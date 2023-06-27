(*
 * Copyright 2020, Data61, CSIRO (ABN 41 687 119 230)
 *
 * SPDX-License-Identifier: BSD-2-Clause
 *)

theory jiraver443a
  imports "CParser.CTranslation"
begin

external_file "jiraver443a.c"
install_C_file "jiraver443a.c"

context jiraver443a
begin

term "symbol_table"
thm get_body_def

end (* context *)

end
