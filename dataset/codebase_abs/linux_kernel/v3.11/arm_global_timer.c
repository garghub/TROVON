static T_1 F_1 ( void )
{
T_1 V_1 ;
T_2 V_2 ;
T_2 V_3 , V_4 ;
V_3 = F_2 ( V_5 + V_6 ) ;
do {
V_4 = V_3 ;
V_2 = F_2 ( V_5 + V_7 ) ;
V_3 = F_2 ( V_5 + V_6 ) ;
} while ( V_3 != V_4 );
V_1 = V_3 ;
V_1 <<= 32 ;
V_1 |= V_2 ;
return V_1 ;
}
static void F_3 ( unsigned long V_8 , int V_9 )
{
T_1 V_1 = F_1 () ;
unsigned long V_10 ;
V_1 += V_8 ;
V_10 = V_11 ;
F_4 ( V_10 , V_5 + V_12 ) ;
F_4 ( F_5 ( V_1 ) , V_5 + V_13 ) ;
F_4 ( F_6 ( V_1 ) , V_5 + V_14 ) ;
if ( V_9 ) {
F_4 ( V_8 , V_5 + V_15 ) ;
V_10 |= V_16 ;
}
V_10 |= V_17 | V_18 ;
F_4 ( V_10 , V_5 + V_12 ) ;
}
static void F_7 ( enum V_19 V_20 ,
struct V_21 * V_22 )
{
unsigned long V_10 ;
switch ( V_20 ) {
case V_23 :
F_3 ( F_8 ( V_24 , V_25 ) , 1 ) ;
break;
case V_26 :
case V_27 :
case V_28 :
V_10 = F_9 ( V_5 + V_12 ) ;
V_10 &= ~ ( V_17 |
V_18 | V_16 ) ;
F_4 ( V_10 , V_5 + V_12 ) ;
break;
default:
break;
}
}
static int F_10 ( unsigned long V_29 ,
struct V_21 * V_30 )
{
F_3 ( V_29 , 0 ) ;
return 0 ;
}
static T_3 F_11 ( int V_31 , void * V_32 )
{
struct V_21 * V_29 = V_32 ;
if ( ! ( F_2 ( V_5 + V_33 ) &
V_34 ) )
return V_35 ;
if ( V_29 -> V_20 == V_26 )
F_3 ( V_36 , 0 ) ;
F_12 ( V_34 , V_5 + V_33 ) ;
V_29 -> V_37 ( V_29 ) ;
return V_38 ;
}
static int F_13 ( struct V_21 * V_22 )
{
int V_39 = F_14 () ;
V_22 -> V_40 = L_1 ;
V_22 -> V_41 = V_42 | V_43 ;
V_22 -> V_44 = F_7 ;
V_22 -> V_45 = F_10 ;
V_22 -> V_46 = F_15 ( V_39 ) ;
V_22 -> V_47 = 300 ;
V_22 -> V_31 = V_48 ;
F_16 ( V_22 , V_24 ,
1 , 0xffffffff ) ;
F_17 ( V_22 -> V_31 , V_49 ) ;
return 0 ;
}
static void F_18 ( struct V_21 * V_22 )
{
F_7 ( V_27 , V_22 ) ;
F_19 ( V_22 -> V_31 ) ;
}
static T_4 F_20 ( struct V_50 * V_51 )
{
return F_1 () ;
}
static T_2 T_5 F_21 ( void )
{
return F_1 () ;
}
static void T_6 F_22 ( void )
{
F_4 ( 0 , V_5 + V_12 ) ;
F_4 ( 0 , V_5 + V_7 ) ;
F_4 ( 0 , V_5 + V_6 ) ;
F_4 ( V_11 , V_5 + V_12 ) ;
#ifdef F_23
F_24 ( F_21 , 32 , V_24 ) ;
#endif
F_25 ( & V_52 , V_24 ) ;
}
static int F_26 ( struct V_53 * V_54 , unsigned long V_55 ,
void * V_56 )
{
switch ( V_55 & ~ V_57 ) {
case V_58 :
F_13 ( F_27 ( V_59 ) ) ;
break;
case V_60 :
F_18 ( F_27 ( V_59 ) ) ;
break;
}
return V_61 ;
}
static void T_6 F_28 ( struct V_62 * V_63 )
{
struct V_22 * V_64 ;
int V_65 = 0 ;
if ( ( F_29 () & 0xf0000f ) < 0x200000 ) {
F_30 ( L_2 ) ;
return;
}
V_48 = F_31 ( V_63 , 0 ) ;
if ( ! V_48 ) {
F_30 ( L_3 ) ;
return;
}
V_5 = F_32 ( V_63 , 0 ) ;
if ( ! V_5 ) {
F_30 ( L_4 ) ;
return;
}
V_64 = F_33 ( V_63 , 0 ) ;
if ( ! F_34 ( V_64 ) ) {
V_65 = F_35 ( V_64 ) ;
if ( V_65 )
goto V_66;
} else {
F_30 ( L_5 ) ;
V_65 = - V_67 ;
goto V_66;
}
V_24 = F_36 ( V_64 ) ;
V_59 = F_37 ( struct V_21 ) ;
if ( ! V_59 ) {
F_30 ( L_6 ) ;
V_65 = - V_68 ;
goto V_69;
}
V_65 = F_38 ( V_48 , F_11 ,
L_7 , V_59 ) ;
if ( V_65 ) {
F_30 ( L_8 ,
V_48 , V_65 ) ;
goto V_70;
}
V_65 = F_39 ( & V_71 ) ;
if ( V_65 ) {
F_30 ( L_9 ) ;
goto V_72;
}
F_22 () ;
F_13 ( F_27 ( V_59 ) ) ;
return;
V_72:
F_40 ( V_48 , V_59 ) ;
V_70:
F_41 ( V_59 ) ;
V_69:
F_42 ( V_64 ) ;
V_66:
F_43 ( V_5 ) ;
F_44 ( V_65 , L_10 , V_65 ) ;
}
