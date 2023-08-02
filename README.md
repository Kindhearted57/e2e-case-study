# e2e-case-study

# Dependencies

[C parser document](https://trustworthy.systems/software/TS/c-parser/)

[Raw isabelle](https://isabelle.in.tum.de/website-Isabelle2011-1/dist/Isabelle2011-1.tar.gz)

[C parser](https://trustworthy.systems/software/TS/c-parser/) - Chose the newest version here. (Java also required here)

In order to put the parser up, the version of Isabelle and MLton matters, which can be found [here](./c-parser-1.17/src/c-parser/INSTALL)

Possible errors when building [MLton](http://www.mlton.org/SelfCompiling#:~:text=To%20build%20MLton%2C%20run%20make,calls%20mlton%20to%20compile%20itself.)

[seL4 on Docker](https://docs.sel4.systems/projects/dockerfiles/)

When trying to build docker with M1 system, might run into an [error](https://github.com/docker/compose/issues/8449), this can be fixed by editing docker engine configuration and disable `buildkit`

[Tutorial setup](https://docs.sel4.systems/Tutorials/hello-world.html)

```
$ mkdir tutorial
$ cd tutorial
$ repo init -u https://github.com/seL4/sel4-tutorials-manifest.git
```

Setting the proof up:

1) Follow the [instructions](https://github.com/seL4/l4v/blob/master/docs/setup.md) to setup isabelle
2) Run proof following the [description](https://github.com/seL4/l4v/blob/master/README.md#running-the-proofs)
