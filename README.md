# PROBLEM  
Optimise specific matrix multiplicaton:  
Multiply two matrices: `A` (size: `n x 3`) and `B` (size: `3 x m`). `n` is a power of 2.

```text
    ┌         ┐  
    | █  █  █ |      
A = | █  █  █ |  ⟶  n
    | ....... |   
    | █  █  █ |      
    └         ┘  
         ⤷ 3

    ┌           ┐
    | █ █ ... █ |
B = | █ █ ... █ |  ⟶  3
    | █ █ ... █ |
    └           ┘
          ⤷ m

            ┌           ┐
            | █ █ ... █ |
            | █ █ ... █ |
C = A * B = | ......... | ⟶  n
            | ......... |
            | █ █ ... █ |
            └           ┘
                  ⤷ m
```
## Make
`make` - makes the executable and the assembler file  

## Compilation
`g++ -march=native main.cpp -O3 -o matmul` - only compiles with `-O3` optimisations  

## ASM
`g++ -march=native main.cpp -O3 -S` - produce assembler output  

## List your CPU details
`cat /proc/cpuinfo` - Read CPU info or  
`cpuinfo` - Gets CPU info with pure Python  

### Examples:
```text
processor	: 0
vendor_id	: GenuineIntel
cpu family	: 6
model		: 158
model name	: Intel(R) Core(TM) i7-9750H CPU @ 2.60GHz
stepping	: 13
microcode	: 0x104
cpu MHz		: 4262.449
cache size	: 12288 KB
physical id	: 0
siblings	: 12
core id		: 0
cpu cores	: 6
apicid		: 0
initial apicid	: 0
fpu		: yes
fpu_exception	: yes
cpuid level	: 22
wp		: yes
flags		: fpu vme de pse tsc msr pae mce cx8 apic sep mtrr pge mca cmov pat pse36 clflush dts acpi mmx fxsr sse sse2 ss ht tm pbe syscall nx pdpe1gb rdtscp lm constant_tsc art arch_perfmon pebs bts rep_good nopl xtopology nonstop_tsc cpuid aperfmperf pni pclmulqdq dtes64 monitor ds_cpl vmx est tm2 ssse3 sdbg fma cx16 xtpr pdcm pcid sse4_1 sse4_2 x2apic movbe popcnt tsc_deadline_timer aes xsave avx f16c rdrand lahf_lm abm 3dnowprefetch cpuid_fault epb ssbd ibrs ibpb stibp ibrs_enhanced tpr_shadow flexpriority ept vpid ept_ad fsgsbase tsc_adjust bmi1 avx2 smep bmi2 erms invpcid mpx rdseed adx smap clflushopt intel_pt xsaveopt xsavec xgetbv1 xsaves dtherm ida arat pln pts hwp hwp_notify hwp_act_window hwp_epp vnmi md_clear flush_l1d arch_capabilities
vmx flags	: vnmi preemption_timer invvpid ept_x_only ept_ad ept_1gb flexpriority tsc_offset vtpr mtf vapic ept vpid unrestricted_guest ple pml ept_violation_ve ept_mode_based_exec
bugs		: spectre_v1 spectre_v2 spec_store_bypass swapgs itlb_multihit srbds mmio_stale_data retbleed eibrs_pbrsb gds bhi its vmscape
bogomips	: 5199.98
clflush size	: 64
cache_alignment	: 64
address sizes	: 39 bits physical, 48 bits virtual
power management:

```

```json
{
  "python_version": "3.13.5.final.0 (64 bit)",
  "cpuinfo_version": [
    9,
    0,
    0
  ],
  "cpuinfo_version_string": "9.0.0",
  "arch": "X86_64",
  "bits": 64,
  "count": 12,
  "arch_string_raw": "x86_64",
  "vendor_id_raw": "GenuineIntel",
  "brand_raw": "Intel(R) Core(TM) i7-9750H CPU @ 2.60GHz",
  "hz_advertised_friendly": "2.6000 GHz",
  "hz_actual_friendly": "4.0666 GHz",
  "hz_advertised": [
    2600000000,
    0
  ],
  "hz_actual": [
    4066590000,
    0
  ],
  "stepping": 13,
  "model": 158,
  "family": 6,
  "flags": [
    "3dnowprefetch",
    "abm",
    "acpi",
    "adx",
    "aes",
    "aperfmperf",
    "apic",
    "arat",
    "arch_capabilities",
    "arch_perfmon",
    "art",
    "avx",
    "avx2",
    "bmi1",
    "bmi2",
    "bts",
    "clflush",
    "clflushopt",
    "cmov",
    "constant_tsc",
    "cpuid",
    "cpuid_fault",
    "cx16",
    "cx8",
    "de",
    "ds_cpl",
    "dtes64",
    "dtherm",
    "dts",
    "epb",
    "ept",
    "ept_ad",
    "erms",
    "est",
    "f16c",
    "flexpriority",
    "flush_l1d",
    "fma",
    "fpu",
    "fsgsbase",
    "fxsr",
    "ht",
    "hwp",
    "hwp_act_window",
    "hwp_epp",
    "hwp_notify",
    "ibpb",
    "ibrs",
    "ibrs_enhanced",
    "ida",
    "intel_pt",
    "invpcid",
    "lahf_lm",
    "lm",
    "mca",
    "mce",
    "md_clear",
    "mmx",
    "monitor",
    "movbe",
    "mpx",
    "msr",
    "mtrr",
    "nonstop_tsc",
    "nopl",
    "nx",
    "osxsave",
    "pae",
    "pat",
    "pbe",
    "pcid",
    "pclmulqdq",
    "pdcm",
    "pdpe1gb",
    "pebs",
    "pge",
    "pln",
    "pni",
    "popcnt",
    "pse",
    "pse36",
    "pts",
    "rdrand",
    "rdrnd",
    "rdseed",
    "rdtscp",
    "rep_good",
    "sdbg",
    "sep",
    "sgx",
    "sgx_lc",
    "smap",
    "smep",
    "ss",
    "ssbd",
    "sse",
    "sse2",
    "sse4_1",
    "sse4_2",
    "ssse3",
    "stibp",
    "syscall",
    "tm",
    "tm2",
    "tpr_shadow",
    "tsc",
    "tsc_adjust",
    "tsc_deadline_timer",
    "tscdeadline",
    "vme",
    "vmx",
    "vnmi",
    "vpid",
    "x2apic",
    "xgetbv1",
    "xsave",
    "xsavec",
    "xsaveopt",
    "xsaves",
    "xtopology",
    "xtpr"
  ],
  "l3_cache_size": 12582912,
  "l2_cache_size": "1.5 MiB",
  "l1_data_cache_size": 196608,
  "l1_instruction_cache_size": 196608,
  "l2_cache_line_size": 256,
  "l2_cache_associativity": 6
}
```