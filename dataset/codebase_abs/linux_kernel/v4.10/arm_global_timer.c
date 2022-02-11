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
static int F_16 ( unsigned int V_32 )
{
struct V_19 * V_33 = F_17 ( V_34 ) ;
V_33 -> V_35 = L_1 ;
V_33 -> V_36 = V_37 | V_38 |
V_39 ;
V_33 -> V_40 = F_8 ;
V_33 -> V_41 = F_11 ;
V_33 -> V_42 = F_8 ;
V_33 -> V_43 = F_8 ;
V_33 -> V_44 = F_13 ;
V_33 -> V_45 = F_18 ( V_32 ) ;
V_33 -> V_46 = 300 ;
V_33 -> V_24 = V_47 ;
F_19 ( V_33 , V_21 ,
1 , 0xffffffff ) ;
F_20 ( V_33 -> V_24 , V_48 ) ;
return 0 ;
}
static int F_21 ( unsigned int V_32 )
{
struct V_19 * V_33 = F_17 ( V_34 ) ;
F_8 ( V_33 ) ;
F_22 ( V_33 -> V_24 ) ;
return 0 ;
}
static T_1 F_23 ( struct V_49 * V_50 )
{
return F_3 () ;
}
static void F_24 ( struct V_49 * V_50 )
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
static void T_5 F_27 ( void )
{
V_51 . V_52 = V_21 ;
F_28 ( & V_51 ) ;
}
static int T_5 F_29 ( void )
{
F_10 ( 0 , V_5 + V_12 ) ;
F_10 ( 0 , V_5 + V_7 ) ;
F_10 ( 0 , V_5 + V_6 ) ;
F_10 ( V_11 , V_5 + V_12 ) ;
#ifdef F_30
F_31 ( F_25 , 64 , V_21 ) ;
#endif
return F_32 ( & V_53 , V_21 ) ;
}
static int T_5 F_33 ( struct V_54 * V_55 )
{
struct V_33 * V_56 ;
int V_57 = 0 ;
if ( F_34 () == V_58
&& ( F_35 () & 0xf0000f ) < 0x200000 ) {
F_36 ( L_2 ) ;
return - V_59 ;
}
V_47 = F_37 ( V_55 , 0 ) ;
if ( ! V_47 ) {
F_36 ( L_3 ) ;
return - V_60 ;
}
V_5 = F_38 ( V_55 , 0 ) ;
if ( ! V_5 ) {
F_36 ( L_4 ) ;
return - V_61 ;
}
V_56 = F_39 ( V_55 , 0 ) ;
if ( ! F_40 ( V_56 ) ) {
V_57 = F_41 ( V_56 ) ;
if ( V_57 )
goto V_62;
} else {
F_36 ( L_5 ) ;
V_57 = - V_60 ;
goto V_62;
}
V_21 = F_42 ( V_56 ) ;
V_34 = F_43 ( struct V_19 ) ;
if ( ! V_34 ) {
F_36 ( L_6 ) ;
V_57 = - V_63 ;
goto V_64;
}
V_57 = F_44 ( V_47 , F_14 ,
L_7 , V_34 ) ;
if ( V_57 ) {
F_36 ( L_8 ,
V_47 , V_57 ) ;
goto V_65;
}
V_57 = F_29 () ;
if ( V_57 )
goto V_66;
V_57 = F_45 ( V_67 ,
L_9 ,
F_16 , F_21 ) ;
if ( V_57 )
goto V_66;
F_27 () ;
return 0 ;
V_66:
F_46 ( V_47 , V_34 ) ;
V_65:
F_47 ( V_34 ) ;
V_64:
F_48 ( V_56 ) ;
V_62:
F_49 ( V_5 ) ;
F_50 ( V_57 , L_10 , V_57 ) ;
return V_57 ;
}
