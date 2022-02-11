void F_1 ( void )
{
unsigned long V_1 ;
unsigned V_2 = 2 ;
T_1 V_3 = 0 ;
T_1 V_4 = 0 ;
T_1 V_5 = 0 ;
if ( F_2 () == V_6 ) {
union V_7 V_8 ;
V_8 . T_1 = F_3 ( V_9 ) ;
V_4 = V_8 . V_10 . V_11 ;
V_5 = V_8 . V_10 . V_12 ;
V_3 = ( 0x8000000000000000ull / V_5 ) * 2 ;
}
asm("" : "+r" (loops));
F_4 ( V_1 ) ;
while ( V_2 -- ) {
T_1 V_13 = F_3 ( V_14 ) ;
if ( V_4 != 0 ) {
V_13 *= V_4 ;
if ( V_3 != 0 ) {
asm("dmultu\t%[cnt],%[f]\n\t"
"mfhi\t%[cnt]"
: [cnt] "+r" (ipd_clk_count),
[f] "=r" (f)
: : "hi", "lo");
}
}
F_5 ( V_13 ) ;
}
F_6 ( V_1 ) ;
}
static T_2 F_7 ( struct V_15 * V_16 )
{
return F_8 () ;
}
unsigned long long T_3 F_9 ( void )
{
T_1 V_17 , V_18 , V_19 ;
unsigned long long V_20 ;
T_1 V_21 = V_22 . V_21 ;
T_1 V_23 = V_22 . V_23 ;
T_1 V_24 = F_8 () ;
asm (
"dmultu\t%[cnt],%[mult]\n\t"
"nor\t%[t1],$0,%[shift]\n\t"
"mfhi\t%[t2]\n\t"
"mflo\t%[t3]\n\t"
"dsll\t%[t2],%[t2],1\n\t"
"dsrlv\t%[rv],%[t3],%[shift]\n\t"
"dsllv\t%[t1],%[t2],%[t1]\n\t"
"or\t%[rv],%[t1],%[rv]\n\t"
: [rv] "=&r" (rv), [t1] "=&r" (t1), [t2] "=&r" (t2), [t3] "=&r" (t3)
: [cnt] "r" (cnt), [mult] "r" (mult), [shift] "r" (shift)
: "hi", "lo");
return V_20 ;
}
void T_4 F_10 ( void )
{
V_22 . V_25 = 300 ;
F_11 ( & V_22 , F_12 () ) ;
}
void T_4 F_13 ( void )
{
V_26 = F_12 () / 1000000 ;
V_27 = ( V_26 * 0x10000ull ) / 1000ull ;
V_28 = F_12 () / V_29 ;
}
void F_14 ( unsigned long V_30 )
{
T_1 V_31 , V_32 , V_33 ;
V_31 = F_8 () ;
V_33 = V_30 * V_26 ;
V_32 = V_31 + V_33 ;
while ( V_32 > V_31 )
V_31 = F_8 () ;
}
void F_15 ( unsigned long V_34 )
{
T_1 V_31 , V_32 , V_33 ;
V_31 = F_8 () ;
V_33 = ( ( V_34 * V_27 ) >> 16 ) ;
V_32 = V_31 + V_33 ;
while ( V_32 > V_31 )
V_31 = F_8 () ;
}
void F_16 ( unsigned long V_2 )
{
T_1 V_31 , V_32 ;
V_31 = F_8 () ;
V_32 = V_31 + V_2 ;
while ( V_32 > V_31 )
V_31 = F_8 () ;
}
