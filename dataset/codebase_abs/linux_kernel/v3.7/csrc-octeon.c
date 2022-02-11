void T_1 F_1 ( void )
{
V_1 = F_2 () / 1000000 ;
V_2 = ( V_1 * 0x10000ull ) / 1000ull ;
V_3 = F_2 () / V_4 ;
if ( F_3 () == V_5 ) {
union V_6 V_7 ;
V_7 . V_8 = F_4 ( V_9 ) ;
V_10 = V_7 . V_11 . V_12 ;
V_13 = V_7 . V_11 . V_14 ;
V_15 = ( 0x8000000000000000ull / V_13 ) * 2 ;
}
}
void F_5 ( void )
{
unsigned long V_16 ;
unsigned V_17 = 2 ;
asm("" : "+r" (loops));
F_6 ( V_16 ) ;
while ( V_17 -- ) {
V_8 V_18 = F_4 ( V_19 ) ;
if ( V_10 != 0 ) {
V_18 *= V_10 ;
if ( V_15 != 0 ) {
asm("dmultu\t%[cnt],%[f]\n\t"
"mfhi\t%[cnt]"
: [cnt] "+r" (ipd_clk_count)
: [f] "r" (f)
: "hi", "lo");
}
}
F_7 ( V_18 ) ;
}
F_8 ( V_16 ) ;
}
static T_2 F_9 ( struct V_20 * V_21 )
{
return F_10 () ;
}
unsigned long long T_3 F_11 ( void )
{
V_8 V_22 , V_23 , V_24 ;
unsigned long long V_25 ;
V_8 V_26 = V_27 . V_26 ;
V_8 V_28 = V_27 . V_28 ;
V_8 V_29 = F_10 () ;
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
return V_25 ;
}
void T_1 F_12 ( void )
{
V_27 . V_30 = 300 ;
F_13 ( & V_27 , F_2 () ) ;
}
void F_14 ( unsigned long V_31 )
{
V_8 V_32 , V_33 , V_34 ;
V_32 = F_10 () ;
V_34 = V_31 * V_1 ;
V_33 = V_32 + V_34 ;
while ( V_33 > V_32 )
V_32 = F_10 () ;
}
void F_15 ( unsigned long V_35 )
{
V_8 V_32 , V_33 , V_34 ;
V_32 = F_10 () ;
V_34 = ( ( V_35 * V_2 ) >> 16 ) ;
V_33 = V_32 + V_34 ;
while ( V_33 > V_32 )
V_32 = F_10 () ;
}
void F_16 ( unsigned long V_17 )
{
V_8 V_32 , V_33 ;
V_32 = F_10 () ;
V_33 = V_32 + V_17 ;
while ( V_33 > V_32 )
V_32 = F_10 () ;
}
void F_17 ( unsigned long V_36 )
{
V_8 V_32 , V_33 ;
V_32 = F_10 () ;
if ( V_10 != 0 ) {
V_33 = V_36 * V_10 ;
if ( V_15 != 0 ) {
asm("dmultu\t%[cnt],%[f]\n\t"
"mfhi\t%[cnt]"
: [cnt] "+r" (end)
: [f] "r" (f)
: "hi", "lo");
}
V_33 = V_32 + V_33 ;
} else {
V_33 = V_32 + V_36 ;
}
while ( V_33 > V_32 )
V_32 = F_10 () ;
}
