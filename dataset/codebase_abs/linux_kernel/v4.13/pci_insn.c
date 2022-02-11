static inline void F_1 ( T_1 V_1 , T_1 V_2 , T_2 V_3 , T_2 V_4 )
{
struct {
T_2 V_3 ;
T_2 V_4 ;
T_1 V_1 ;
T_1 V_2 ;
} V_5 V_6 = { V_3 , V_4 , V_1 , V_2 } ;
F_2 ( & V_6 , sizeof( V_6 ) ) ;
}
static inline T_1 F_3 ( T_2 V_3 , struct V_7 * V_8 , T_1 * V_2 )
{
T_1 V_1 ;
asm volatile (
" .insn rxy,0xe300000000d0,%[req],%[fib]\n"
" ipm %[cc]\n"
" srl %[cc],28\n"
: [cc] "=d" (cc), [req] "+d" (req), [fib] "+Q" (*fib)
: : "cc");
* V_2 = V_3 >> 24 & 0xff ;
return V_1 ;
}
T_1 F_4 ( T_2 V_3 , struct V_7 * V_8 , T_1 * V_2 )
{
T_1 V_1 ;
do {
V_1 = F_3 ( V_3 , V_8 , V_2 ) ;
if ( V_1 == 2 )
F_5 ( V_9 ) ;
} while ( V_1 == 2 );
if ( V_1 )
F_1 ( V_1 , * V_2 , V_3 , 0 ) ;
return V_1 ;
}
static inline T_1 F_6 ( T_2 V_10 , T_2 V_11 , T_2 V_12 , T_1 * V_2 )
{
register T_2 T_3 V_13 ( L_1 ) = V_11 ;
register T_2 T_4 V_13 ( L_2 ) = V_12 ;
T_1 V_1 ;
asm volatile (
" .insn rre,0xb9d30000,%[fn],%[addr]\n"
" ipm %[cc]\n"
" srl %[cc],28\n"
: [cc] "=d" (cc), [fn] "+d" (fn)
: [addr] "d" (__addr), "d" (__range)
: "cc");
* V_2 = V_10 >> 24 & 0xff ;
return V_1 ;
}
int F_7 ( T_2 V_10 , T_2 V_11 , T_2 V_12 )
{
T_1 V_1 , V_2 ;
do {
V_1 = F_6 ( V_10 , V_11 , V_12 , & V_2 ) ;
if ( V_1 == 2 )
F_8 ( V_9 ) ;
} while ( V_1 == 2 );
if ( V_1 )
F_1 ( V_1 , V_2 , V_11 , V_12 ) ;
return ( V_1 ) ? - V_14 : 0 ;
}
void F_9 ( T_5 V_15 , char * V_16 , T_1 V_17 )
{
asm volatile (
" .insn rsy,0xeb00000000d1,%[ctl],%[isc],%[u]\n"
: : [ctl] "d" (ctl), [isc] "d" (isc << 27), [u] "Q" (*unused));
}
static inline int F_10 ( T_2 * V_6 , T_2 V_3 , T_2 V_4 , T_1 * V_2 )
{
register T_2 T_6 V_13 ( L_1 ) = V_3 ;
register T_2 T_7 V_13 ( L_2 ) = V_4 ;
int V_1 = - V_18 ;
T_2 V_19 ;
asm volatile (
" .insn rre,0xb9d20000,%[data],%[req]\n"
"0: ipm %[cc]\n"
" srl %[cc],28\n"
"1:\n"
EX_TABLE(0b, 1b)
: [cc] "+d" (cc), [data] "=d" (__data), [req] "+d" (__req)
: "d" (__offset)
: "cc");
* V_2 = T_6 >> 24 & 0xff ;
* V_6 = V_19 ;
return V_1 ;
}
static inline int F_11 ( T_2 * V_6 , T_2 V_3 , T_2 V_4 , T_1 * V_2 )
{
T_2 V_19 ;
int V_1 ;
V_1 = F_10 ( & V_19 , V_3 , V_4 , V_2 ) ;
if ( ! V_1 )
* V_6 = V_19 ;
return V_1 ;
}
int F_12 ( T_2 * V_6 , T_2 V_3 , T_2 V_4 )
{
T_1 V_2 ;
int V_1 ;
do {
V_1 = F_11 ( V_6 , V_3 , V_4 , & V_2 ) ;
if ( V_1 == 2 )
F_8 ( V_9 ) ;
} while ( V_1 == 2 );
if ( V_1 )
F_1 ( V_1 , V_2 , V_3 , V_4 ) ;
return ( V_1 > 0 ) ? - V_14 : V_1 ;
}
static inline int F_13 ( T_2 V_6 , T_2 V_3 , T_2 V_4 , T_1 * V_2 )
{
register T_2 T_6 V_13 ( L_1 ) = V_3 ;
register T_2 T_7 V_13 ( L_2 ) = V_4 ;
int V_1 = - V_18 ;
asm volatile (
" .insn rre,0xb9d00000,%[data],%[req]\n"
"0: ipm %[cc]\n"
" srl %[cc],28\n"
"1:\n"
EX_TABLE(0b, 1b)
: [cc] "+d" (cc), [req] "+d" (__req)
: "d" (__offset), [data] "d" (data)
: "cc");
* V_2 = T_6 >> 24 & 0xff ;
return V_1 ;
}
int F_14 ( T_2 V_6 , T_2 V_3 , T_2 V_4 )
{
T_1 V_2 ;
int V_1 ;
do {
V_1 = F_13 ( V_6 , V_3 , V_4 , & V_2 ) ;
if ( V_1 == 2 )
F_8 ( V_9 ) ;
} while ( V_1 == 2 );
if ( V_1 )
F_1 ( V_1 , V_2 , V_3 , V_4 ) ;
return ( V_1 > 0 ) ? - V_14 : V_1 ;
}
static inline int F_15 ( const T_2 * V_6 , T_2 V_3 , T_2 V_4 , T_1 * V_2 )
{
int V_1 = - V_18 ;
asm volatile (
" .insn rsy,0xeb00000000d0,%[req],%[offset],%[data]\n"
"0: ipm %[cc]\n"
" srl %[cc],28\n"
"1:\n"
EX_TABLE(0b, 1b)
: [cc] "+d" (cc), [req] "+d" (req)
: [offset] "d" (offset), [data] "Q" (*data)
: "cc");
* V_2 = V_3 >> 24 & 0xff ;
return V_1 ;
}
int F_16 ( const T_2 * V_6 , T_2 V_3 , T_2 V_4 )
{
T_1 V_2 ;
int V_1 ;
do {
V_1 = F_15 ( V_6 , V_3 , V_4 , & V_2 ) ;
if ( V_1 == 2 )
F_8 ( V_9 ) ;
} while ( V_1 == 2 );
if ( V_1 )
F_1 ( V_1 , V_2 , V_3 , V_4 ) ;
return ( V_1 > 0 ) ? - V_14 : V_1 ;
}
