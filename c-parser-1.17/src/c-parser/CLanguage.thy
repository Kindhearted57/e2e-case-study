(*
 * Copyright 2020, Data61, CSIRO (ABN 41 687 119 230)
 *
 * SPDX-License-Identifier: BSD-2-Clause
 *)

theory CLanguage
imports "CProof"
begin

definition
  creturn :: "((c_exntype \<Rightarrow> c_exntype) \<Rightarrow> ('c, 'd) state_scheme \<Rightarrow> ('c, 'd) state_scheme)
      \<Rightarrow> (('a \<Rightarrow> 'a) \<Rightarrow> ('c, 'd) state_scheme \<Rightarrow> ('c, 'd) state_scheme)
      \<Rightarrow> (('c, 'd) state_scheme \<Rightarrow> 'a) \<Rightarrow> (('c, 'd) state_scheme,'p,'f) com"
where
  "creturn rtu xfu v \<equiv> (Basic (\<lambda>s. xfu (\<lambda>_. v s) s);; (Basic (rtu (\<lambda>_. Return));; THROW))"

definition
  creturn_void :: "((c_exntype \<Rightarrow> c_exntype) \<Rightarrow> ('c, 'd) state_scheme
      \<Rightarrow> ('c, 'd) state_scheme) \<Rightarrow> (('c, 'd) state_scheme,'p,'f) com"
where
  "creturn_void rtu \<equiv> (Basic (rtu (\<lambda>_. Return));; THROW)"

definition
  cbreak :: "((c_exntype \<Rightarrow> c_exntype) \<Rightarrow> ('c, 'd) state_scheme
      \<Rightarrow> ('c, 'd) state_scheme) \<Rightarrow> (('c, 'd) state_scheme,'p,'f) com"
where
  "cbreak rtu \<equiv> (Basic (rtu (\<lambda>_. Break));; THROW)"

definition
  ccatchbrk :: "( ('c, 'd) state_scheme \<Rightarrow> c_exntype) \<Rightarrow> (('c, 'd) state_scheme,'p,'f) com"
where
  "ccatchbrk rt \<equiv> Cond {s. rt s = Break} SKIP THROW"

definition
  cchaos :: "('b \<Rightarrow> 'a \<Rightarrow> 'a) \<Rightarrow> ('a,'c,'d) com"
where
  "cchaos upd \<equiv> Spec { (s0,s) . \<exists>v. s = upd v s0 }"

definition
  "guarded_spec_body F R = Guard F (fst ` R) (Spec R)"

end
