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
V_8 V_19 ;
unsigned long V_20 ;
unsigned V_21 = 2 ;
V_19 = F_6 ( V_22 ) ?
V_23 : V_24 ;
asm("" : "+r" (loops));
F_7 ( V_20 ) ;
while ( V_21 -- ) {
V_8 V_25 = F_4 ( V_19 ) ;
if ( V_10 != 0 ) {
V_25 *= V_10 ;
if ( V_15 != 0 ) {
asm("dmultu\t%[cnt],%[f]\n\t"
"mfhi\t%[cnt]"
: [cnt] "+r" (clk_count)
: [f] "r" (f)
: "hi", "lo");
}
}
F_8 ( V_25 ) ;
}
F_9 ( V_20 ) ;
}
static V_8 F_10 ( struct V_26 * V_27 )
{
return F_11 () ;
}
unsigned long long T_2 F_12 ( void )
{
V_8 V_28 , V_29 , V_30 ;
unsigned long long V_31 ;
V_8 V_32 = V_33 . V_32 ;
V_8 V_34 = V_33 . V_34 ;
V_8 V_35 = F_11 () ;
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
return V_31 ;
}
void T_1 F_13 ( void )
{
V_33 . V_36 = 300 ;
F_14 ( & V_33 , F_2 () ) ;
}
void F_15 ( unsigned long V_37 )
{
V_8 V_38 , V_39 , V_40 ;
V_38 = F_11 () ;
V_40 = V_37 * V_1 ;
V_39 = V_38 + V_40 ;
while ( V_39 > V_38 )
V_38 = F_11 () ;
}
void F_16 ( unsigned long V_41 )
{
V_8 V_38 , V_39 , V_40 ;
V_38 = F_11 () ;
V_40 = ( ( V_41 * V_2 ) >> 16 ) ;
V_39 = V_38 + V_40 ;
while ( V_39 > V_38 )
V_38 = F_11 () ;
}
void F_17 ( unsigned long V_21 )
{
V_8 V_38 , V_39 ;
V_38 = F_11 () ;
V_39 = V_38 + V_21 ;
while ( V_39 > V_38 )
V_38 = F_11 () ;
}
void F_18 ( unsigned long V_42 )
{
V_8 V_38 , V_39 ;
V_38 = F_11 () ;
if ( V_10 != 0 ) {
V_39 = V_42 * V_10 ;
if ( V_15 != 0 ) {
asm("dmultu\t%[cnt],%[f]\n\t"
"mfhi\t%[cnt]"
: [cnt] "+r" (end)
: [f] "r" (f)
: "hi", "lo");
}
V_39 = V_38 + V_39 ;
} else {
V_39 = V_38 + V_42 ;
}
while ( V_39 > V_38 )
V_38 = F_11 () ;
}
