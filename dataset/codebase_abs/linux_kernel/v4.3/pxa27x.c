void F_1 ( void )
{
if ( F_2 () && ( V_1 & V_2 ) )
V_1 |= V_2 ;
}
void F_3 ( int V_3 , bool V_4 )
{
if ( V_3 == 113 )
F_4 ( V_4 ? & V_5 [ 0 ] :
& V_5 [ 1 ] , 1 ) ;
if ( V_3 == 95 )
F_4 ( V_4 ? & V_5 [ 2 ] :
& V_5 [ 3 ] , 1 ) ;
}
int T_1 F_5 ( unsigned int V_6 )
{
switch ( V_6 ) {
case V_7 :
case V_8 :
V_9 = V_6 ;
return 0 ;
}
return - V_10 ;
}
void F_6 ( unsigned long * V_11 )
{
V_11 [ V_12 ] = F_7 ( V_13 ) ;
F_8 ( V_14 ) ;
F_8 ( V_15 ) ;
}
void F_9 ( unsigned long * V_11 )
{
F_10 ( V_11 [ V_12 ] , V_13 ) ;
F_11 ( V_14 ) ;
V_1 = V_16 | V_17 ;
F_11 ( V_15 ) ;
}
void F_12 ( T_2 V_18 )
{
extern void V_19 ( void ) ;
#ifndef F_13
T_3 V_20 ;
asm volatile("mra %Q0, %R0, acc0" : "=r" (acc0));
#endif
V_14 &= ~ V_21 ;
V_22 = 0xDF12FE1B ;
V_23 = V_24 | V_25 | V_26 | V_27 ;
switch ( V_18 ) {
case V_28 :
V_19 () ;
break;
case V_29 :
F_14 ( V_9 , V_30 ) ;
#ifndef F_13
asm volatile("mar acc0, %Q0, %R0" : "=r" (acc0));
#endif
break;
}
}
static int F_15 ( T_2 V_18 )
{
return V_18 == V_29 || V_18 == V_28 ;
}
static int F_16 ( void )
{
V_31 = F_17 ( V_32 ) ;
return 0 ;
}
static void F_18 ( void )
{
V_31 = 0 ;
}
static void T_1 F_19 ( void )
{
V_33 = & V_34 ;
}
static inline void F_19 ( void ) {}
static int F_20 ( struct V_35 * V_36 , unsigned int V_37 )
{
int V_38 = F_21 ( V_36 -> V_39 ) ;
T_4 V_40 ;
if ( V_38 >= 0 && V_38 < 128 )
return F_22 ( V_38 , V_37 ) ;
if ( V_36 -> V_39 == V_41 )
return F_23 ( V_37 ) ;
switch ( V_36 -> V_39 ) {
case V_42 :
V_40 = V_43 ;
break;
case V_44 :
V_40 = 1u << 26 ;
break;
default:
return - V_10 ;
}
if ( V_37 )
V_45 |= V_40 ;
else
V_45 &= ~ V_40 ;
return 0 ;
}
void T_1 F_24 ( void )
{
F_25 ( 34 , F_20 ) ;
}
void T_1 F_26 ( void )
{
if ( F_27 ( V_46 ) )
F_28 ( F_20 ) ;
}
void T_1 F_29 ( void )
{
F_30 () ;
F_31 ( F_32 ( V_47 ) ) ;
F_33 ( 1 ) ;
}
void T_1 F_34 ( struct V_48 * V_49 )
{
F_35 () ;
V_14 |= V_50 ;
F_36 () ;
F_37 ( & V_51 , V_49 ) ;
}
static int T_1 F_38 ( void )
{
int V_52 = 0 ;
if ( F_2 () ) {
V_53 = V_23 ;
if ( ( V_52 = F_39 ( V_54 , 32 ) ) )
return V_52 ;
F_19 () ;
F_40 ( & V_55 ) ;
F_40 ( & V_56 ) ;
if ( ! F_41 () ) {
F_37 ( & V_57 ,
& V_58 ) ;
F_42 ( 32 ) ;
V_52 = F_43 ( V_59 ,
F_44 ( V_59 ) ) ;
}
}
return V_52 ;
}
