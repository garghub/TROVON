static T_1 T_2 F_1 ( void )
{
T_1 V_1 ;
T_3 V_2 ;
T_3 V_3 , V_4 ;
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
static T_1 F_3 ( void )
{
return F_1 () ;
}
static void F_4 ( unsigned long V_8 , int V_9 )
{
T_1 V_1 = F_3 () ;
unsigned long V_10 ;
V_1 += V_8 ;
V_10 = V_11 ;
F_5 ( V_10 , V_5 + V_12 ) ;
F_5 ( F_6 ( V_1 ) , V_5 + V_13 ) ;
F_5 ( F_7 ( V_1 ) , V_5 + V_14 ) ;
if ( V_9 ) {
F_5 ( V_8 , V_5 + V_15 ) ;
V_10 |= V_16 ;
}
V_10 |= V_17 | V_18 ;
F_5 ( V_10 , V_5 + V_12 ) ;
}
static int F_8 ( struct V_19 * V_20 )
{
unsigned long V_10 ;
V_10 = F_9 ( V_5 + V_12 ) ;
V_10 &= ~ ( V_17 | V_18 |
V_16 ) ;
F_10 ( V_10 , V_5 + V_12 ) ;
return 0 ;
}
static int F_11 ( struct V_19 * V_20 )
{
F_4 ( F_12 ( V_21 , V_22 ) , 1 ) ;
return 0 ;
}
static int F_13 ( unsigned long V_20 ,
struct V_19 * V_23 )
{
F_4 ( V_20 , 0 ) ;
return 0 ;
}
static T_4 F_14 ( int V_24 , void * V_25 )
{
struct V_19 * V_20 = V_25 ;
if ( ! ( F_2 ( V_5 + V_26 ) &
V_27 ) )
return V_28 ;
if ( F_15 ( V_20 ) )
F_4 ( V_29 , 0 ) ;
F_5 ( V_27 , V_5 + V_26 ) ;
V_20 -> V_30 ( V_20 ) ;
return V_31 ;
}
static int F_16 ( struct V_19 * V_32 )
{
int V_33 = F_17 () ;
V_32 -> V_34 = L_1 ;
V_32 -> V_35 = V_36 | V_37 |
V_38 ;
V_32 -> V_39 = F_8 ;
V_32 -> V_40 = F_11 ;
V_32 -> V_41 = F_8 ;
V_32 -> V_42 = F_8 ;
V_32 -> V_43 = F_13 ;
V_32 -> V_44 = F_18 ( V_33 ) ;
V_32 -> V_45 = 300 ;
V_32 -> V_24 = V_46 ;
F_19 ( V_32 , V_21 ,
1 , 0xffffffff ) ;
F_20 ( V_32 -> V_24 , V_47 ) ;
return 0 ;
}
static void F_21 ( struct V_19 * V_32 )
{
F_8 ( V_32 ) ;
F_22 ( V_32 -> V_24 ) ;
}
static T_5 F_23 ( struct V_48 * V_49 )
{
return F_3 () ;
}
static void F_24 ( struct V_48 * V_49 )
{
unsigned long V_10 ;
V_10 = F_9 ( V_5 + V_12 ) ;
if ( ! ( V_10 & V_11 ) )
F_10 ( V_11 , V_5 + V_12 ) ;
}
static T_1 T_2 F_25 ( void )
{
return F_1 () ;
}
static unsigned long F_26 ( void )
{
return F_2 ( V_5 + V_7 ) ;
}
static void T_6 F_27 ( void )
{
V_50 . V_51 = V_21 ;
F_28 ( & V_50 ) ;
}
static void T_6 F_29 ( void )
{
F_10 ( 0 , V_5 + V_12 ) ;
F_10 ( 0 , V_5 + V_7 ) ;
F_10 ( 0 , V_5 + V_6 ) ;
F_10 ( V_11 , V_5 + V_12 ) ;
#ifdef F_30
F_31 ( F_25 , 64 , V_21 ) ;
#endif
F_32 ( & V_52 , V_21 ) ;
}
static int F_33 ( struct V_53 * V_54 , unsigned long V_55 ,
void * V_56 )
{
switch ( V_55 & ~ V_57 ) {
case V_58 :
F_16 ( F_34 ( V_59 ) ) ;
break;
case V_60 :
F_21 ( F_34 ( V_59 ) ) ;
break;
}
return V_61 ;
}
static void T_6 F_35 ( struct V_62 * V_63 )
{
struct V_32 * V_64 ;
int V_65 = 0 ;
if ( F_36 () == V_66
&& ( F_37 () & 0xf0000f ) < 0x200000 ) {
F_38 ( L_2 ) ;
return;
}
V_46 = F_39 ( V_63 , 0 ) ;
if ( ! V_46 ) {
F_38 ( L_3 ) ;
return;
}
V_5 = F_40 ( V_63 , 0 ) ;
if ( ! V_5 ) {
F_38 ( L_4 ) ;
return;
}
V_64 = F_41 ( V_63 , 0 ) ;
if ( ! F_42 ( V_64 ) ) {
V_65 = F_43 ( V_64 ) ;
if ( V_65 )
goto V_67;
} else {
F_38 ( L_5 ) ;
V_65 = - V_68 ;
goto V_67;
}
V_21 = F_44 ( V_64 ) ;
V_59 = F_45 ( struct V_19 ) ;
if ( ! V_59 ) {
F_38 ( L_6 ) ;
V_65 = - V_69 ;
goto V_70;
}
V_65 = F_46 ( V_46 , F_14 ,
L_7 , V_59 ) ;
if ( V_65 ) {
F_38 ( L_8 ,
V_46 , V_65 ) ;
goto V_71;
}
V_65 = F_47 ( & V_72 ) ;
if ( V_65 ) {
F_38 ( L_9 ) ;
goto V_73;
}
F_29 () ;
F_16 ( F_34 ( V_59 ) ) ;
F_27 () ;
return;
V_73:
F_48 ( V_46 , V_59 ) ;
V_71:
F_49 ( V_59 ) ;
V_70:
F_50 ( V_64 ) ;
V_67:
F_51 ( V_5 ) ;
F_52 ( V_65 , L_10 , V_65 ) ;
}
