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
} else if ( F_3 () == V_16 ) {
union V_17 V_7 ;
V_7 . V_8 = F_4 ( V_18 ) ;
V_10 = V_7 . V_11 . V_12 ;
V_13 = V_7 . V_11 . V_14 ;
V_15 = ( 0x8000000000000000ull / V_13 ) * 2 ;
}
}
void F_5 ( void )
{
unsigned long V_19 ;
unsigned V_20 = 2 ;
asm("" : "+r" (loops));
F_6 ( V_19 ) ;
while ( V_20 -- ) {
V_8 V_21 = F_4 ( V_22 ) ;
if ( V_10 != 0 ) {
V_21 *= V_10 ;
if ( V_15 != 0 ) {
asm("dmultu\t%[cnt],%[f]\n\t"
"mfhi\t%[cnt]"
: [cnt] "+r" (ipd_clk_count)
: [f] "r" (f)
: "hi", "lo");
}
}
F_7 ( V_21 ) ;
}
F_8 ( V_19 ) ;
}
static T_2 F_9 ( struct V_23 * V_24 )
{
return F_10 () ;
}
unsigned long long T_3 F_11 ( void )
{
V_8 V_25 , V_26 , V_27 ;
unsigned long long V_28 ;
V_8 V_29 = V_30 . V_29 ;
V_8 V_31 = V_30 . V_31 ;
V_8 V_32 = F_10 () ;
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
return V_28 ;
}
void T_1 F_12 ( void )
{
V_30 . V_33 = 300 ;
F_13 ( & V_30 , F_2 () ) ;
}
void F_14 ( unsigned long V_34 )
{
V_8 V_35 , V_36 , V_37 ;
V_35 = F_10 () ;
V_37 = V_34 * V_1 ;
V_36 = V_35 + V_37 ;
while ( V_36 > V_35 )
V_35 = F_10 () ;
}
void F_15 ( unsigned long V_38 )
{
V_8 V_35 , V_36 , V_37 ;
V_35 = F_10 () ;
V_37 = ( ( V_38 * V_2 ) >> 16 ) ;
V_36 = V_35 + V_37 ;
while ( V_36 > V_35 )
V_35 = F_10 () ;
}
void F_16 ( unsigned long V_20 )
{
V_8 V_35 , V_36 ;
V_35 = F_10 () ;
V_36 = V_35 + V_20 ;
while ( V_36 > V_35 )
V_35 = F_10 () ;
}
void F_17 ( unsigned long V_39 )
{
V_8 V_35 , V_36 ;
V_35 = F_10 () ;
if ( V_10 != 0 ) {
V_36 = V_39 * V_10 ;
if ( V_15 != 0 ) {
asm("dmultu\t%[cnt],%[f]\n\t"
"mfhi\t%[cnt]"
: [cnt] "+r" (end)
: [f] "r" (f)
: "hi", "lo");
}
V_36 = V_35 + V_36 ;
} else {
V_36 = V_35 + V_39 ;
}
while ( V_36 > V_35 )
V_35 = F_10 () ;
}
