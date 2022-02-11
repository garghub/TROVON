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
V_32 -> V_42 = F_13 ;
V_32 -> V_43 = F_18 ( V_33 ) ;
V_32 -> V_44 = 300 ;
V_32 -> V_24 = V_45 ;
F_19 ( V_32 , V_21 ,
1 , 0xffffffff ) ;
F_20 ( V_32 -> V_24 , V_46 ) ;
return 0 ;
}
static void F_21 ( struct V_19 * V_32 )
{
F_8 ( V_32 ) ;
F_22 ( V_32 -> V_24 ) ;
}
static T_5 F_23 ( struct V_47 * V_48 )
{
return F_3 () ;
}
static void F_24 ( struct V_47 * V_48 )
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
static void T_6 F_26 ( void )
{
F_10 ( 0 , V_5 + V_12 ) ;
F_10 ( 0 , V_5 + V_7 ) ;
F_10 ( 0 , V_5 + V_6 ) ;
F_10 ( V_11 , V_5 + V_12 ) ;
#ifdef F_27
F_28 ( F_25 , 64 , V_21 ) ;
#endif
F_29 ( & V_49 , V_21 ) ;
}
static int F_30 ( struct V_50 * V_51 , unsigned long V_52 ,
void * V_53 )
{
switch ( V_52 & ~ V_54 ) {
case V_55 :
F_16 ( F_31 ( V_56 ) ) ;
break;
case V_57 :
F_21 ( F_31 ( V_56 ) ) ;
break;
}
return V_58 ;
}
static void T_6 F_32 ( struct V_59 * V_60 )
{
struct V_32 * V_61 ;
int V_62 = 0 ;
if ( F_33 () == V_63
&& ( F_34 () & 0xf0000f ) < 0x200000 ) {
F_35 ( L_2 ) ;
return;
}
V_45 = F_36 ( V_60 , 0 ) ;
if ( ! V_45 ) {
F_35 ( L_3 ) ;
return;
}
V_5 = F_37 ( V_60 , 0 ) ;
if ( ! V_5 ) {
F_35 ( L_4 ) ;
return;
}
V_61 = F_38 ( V_60 , 0 ) ;
if ( ! F_39 ( V_61 ) ) {
V_62 = F_40 ( V_61 ) ;
if ( V_62 )
goto V_64;
} else {
F_35 ( L_5 ) ;
V_62 = - V_65 ;
goto V_64;
}
V_21 = F_41 ( V_61 ) ;
V_56 = F_42 ( struct V_19 ) ;
if ( ! V_56 ) {
F_35 ( L_6 ) ;
V_62 = - V_66 ;
goto V_67;
}
V_62 = F_43 ( V_45 , F_14 ,
L_7 , V_56 ) ;
if ( V_62 ) {
F_35 ( L_8 ,
V_45 , V_62 ) ;
goto V_68;
}
V_62 = F_44 ( & V_69 ) ;
if ( V_62 ) {
F_35 ( L_9 ) ;
goto V_70;
}
F_26 () ;
F_16 ( F_31 ( V_56 ) ) ;
return;
V_70:
F_45 ( V_45 , V_56 ) ;
V_68:
F_46 ( V_56 ) ;
V_67:
F_47 ( V_61 ) ;
V_64:
F_48 ( V_5 ) ;
F_49 ( V_62 , L_10 , V_62 ) ;
}
