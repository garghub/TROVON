static int F_1 ( void )
{
struct V_1 * V_2 ;
V_3 = F_2 ( L_1 , NULL ) ;
if ( ! V_3 )
return - V_4 ;
V_2 = F_3 ( L_2 , V_5 , V_3 ,
( V_6 * ) & V_7 ) ;
if ( ! V_2 )
goto V_8;
V_2 = F_3 ( L_3 , V_5 , V_3 ,
( V_6 * ) & V_9 ) ;
if ( ! V_2 )
goto V_8;
return 0 ;
V_8:
F_4 ( V_3 ) ;
return - V_4 ;
}
static struct V_10
* F_5 ( unsigned int V_11 )
{
T_1 V_12 = F_6 ( V_11 ) ;
struct V_10 * V_13 ;
F_7 ( & V_14 ) ;
F_8 (phy_ptr, &phy_dev_list, list)
if ( V_13 -> V_12 == V_12 ) {
F_9 ( & V_14 ) ;
return V_13 ;
}
F_9 ( & V_14 ) ;
return NULL ;
}
static int F_10 ( int V_11 , V_6 * V_15 )
{
V_6 V_16 , V_17 ;
V_6 V_18 ;
int V_19 ;
V_19 = F_11 ( V_11 , V_20 , & V_16 , & V_17 ) ;
if ( V_19 )
goto V_21;
else {
V_18 = ( V_16 >> 16 ) & 0xff ;
if ( V_18 )
* V_15 = V_18 * 1000 ;
else {
V_19 = - V_22 ;
goto V_21;
}
}
return 0 ;
V_21:
* V_15 = 0 ;
return V_19 ;
}
static int F_12 ( struct V_23 * V_24 , unsigned long * V_25 )
{
V_6 V_16 , V_17 ;
struct V_10 * V_10 ;
V_10 = V_24 -> V_26 ;
F_13 ( V_10 -> V_27 , V_28 ,
& V_16 , & V_17 ) ;
if ( V_16 & 0x80000000 ) {
* V_25 = V_10 -> V_15 -
( ( V_16 >> 16 ) & 0x7f ) * 1000 ;
F_14 ( L_4 , * V_25 ) ;
return 0 ;
}
return - V_22 ;
}
static int F_15 ( struct V_23 * V_24 ,
int V_29 , unsigned long * V_25 )
{
V_6 V_16 , V_17 ;
struct V_10 * V_10 ;
V_6 V_30 , V_31 ;
unsigned long V_32 ;
int V_33 ;
if ( V_29 >= V_34 )
return - V_22 ;
V_10 = V_24 -> V_26 ;
if ( V_29 ) {
V_30 = V_35 ;
V_31 = V_36 ;
} else {
V_30 = V_37 ;
V_31 = V_38 ;
}
V_33 = F_13 ( V_10 -> V_27 ,
V_39 , & V_16 , & V_17 ) ;
if ( V_33 < 0 )
return - V_22 ;
V_32 = ( V_16 & V_30 ) >> V_31 ;
if ( V_32 )
* V_25 = V_10 -> V_15 - V_32 * 1000 ;
else
* V_25 = 0 ;
F_14 ( L_5 , * V_25 ) ;
return 0 ;
}
int F_16 ( struct V_23 * V_24 , int V_29 ,
unsigned long V_25 )
{
V_6 V_40 , V_41 ;
struct V_10 * V_10 ;
V_6 V_30 , V_31 , V_42 ;
int V_33 ;
V_10 = V_24 -> V_26 ;
if ( V_29 >= V_34 || V_25 >= V_10 -> V_15 )
return - V_22 ;
V_33 = F_13 ( V_10 -> V_27 ,
V_39 ,
& V_40 , & V_41 ) ;
if ( V_33 < 0 )
return - V_22 ;
if ( V_29 ) {
V_30 = V_35 ;
V_31 = V_36 ;
V_42 = V_43 ;
} else {
V_30 = V_37 ;
V_31 = V_38 ;
V_42 = V_44 ;
}
V_40 &= ~ V_30 ;
if ( ! V_25 )
V_40 &= ~ V_42 ;
else {
V_40 |= ( V_10 -> V_15 - V_25 ) / 1000 << V_31 ;
V_40 |= V_42 ;
}
return F_17 ( V_10 -> V_27 ,
V_39 ,
V_40 , V_41 ) ;
}
static int F_18 ( struct V_23 * V_45 ,
int V_29 , enum V_46 * type )
{
* type = V_47 ;
return 0 ;
}
static bool F_19 ( void )
{
return true ;
}
static inline void F_20 ( void )
{
V_6 V_40 , V_41 ;
T_2 V_48 , V_49 ;
F_21 ( V_39 , V_40 , V_41 ) ;
V_48 = ( V_40 & V_37 ) >> V_38 ;
V_49 = ( V_40 & V_35 ) >> V_36 ;
if ( V_48 )
V_40 |= V_44 ;
if ( V_49 )
V_40 |= V_43 ;
F_22 ( V_39 , V_40 , V_41 ) ;
}
static inline void F_23 ( void )
{
V_6 V_40 , V_41 ;
F_21 ( V_39 , V_40 , V_41 ) ;
F_22 ( V_39 ,
V_40 & ( ~ V_44 ) &
( ~ V_43 ) , V_41 ) ;
}
static void F_24 ( struct V_50 * V_51 )
{
T_3 V_52 ;
int V_11 = F_25 () ;
int V_53 = F_6 ( V_11 ) ;
struct V_10 * V_54 = F_5 ( V_11 ) ;
bool V_55 = false ;
if ( ! V_54 )
return;
F_26 ( & V_56 ) ;
++ V_9 ;
if ( F_27 ( V_53 > V_57 ) ) {
F_28 ( & V_56 ) ;
return;
}
V_58 [ V_53 ] = 0 ;
F_28 ( & V_56 ) ;
F_20 () ;
F_29 ( V_28 , V_52 ) ;
if ( V_52 & V_59 ) {
F_30 ( V_28 ,
V_52 & ~ V_59 ) ;
V_55 = true ;
}
if ( V_52 & V_60 ) {
F_30 ( V_28 ,
V_52 & ~ V_60 ) ;
V_55 = true ;
}
if ( V_55 ) {
F_14 ( L_6 ) ;
F_31 ( V_54 -> V_61 ) ;
}
}
static int F_32 ( T_3 V_52 )
{
unsigned long V_62 ;
int V_11 = F_25 () ;
int V_53 = F_6 ( V_11 ) ;
F_33 ( & V_56 , V_62 ) ;
++ V_7 ;
if ( F_27 ( V_53 > V_57 ) || F_27 ( ! V_58 ) ||
V_58 [ V_53 ] ) {
F_23 () ;
F_34 ( & V_56 , V_62 ) ;
return - V_22 ;
}
V_58 [ V_53 ] = 1 ;
F_34 ( & V_56 , V_62 ) ;
F_23 () ;
F_35 ( V_11 ,
& F_36 ( V_63 , V_11 ) ,
F_37 ( V_64 ) ) ;
return 0 ;
}
static int F_38 ( int V_11 )
{
int V_65 ;
int V_66 = F_6 ( V_11 ) ;
F_39 (i)
if ( V_65 != V_11 && F_6 ( V_65 ) == V_66 )
return V_65 ;
return 0 ;
}
static int F_40 ( unsigned int V_11 )
{
int V_19 ;
V_6 V_15 ;
struct V_10 * V_10 ;
char V_67 [ 30 ] ;
int V_68 ;
V_6 V_16 , V_69 , V_70 , V_17 ;
T_2 * V_25 ;
F_41 ( 6 , & V_16 , & V_69 , & V_70 , & V_17 ) ;
V_68 = V_69 & 0x07 ;
if ( ! V_68 )
return - V_71 ;
if ( F_6 ( V_11 ) > V_72 )
return - V_71 ;
V_68 = F_42 ( V_68 , 0 , V_34 ) ;
V_19 = F_10 ( V_11 , & V_15 ) ;
if ( V_19 )
goto V_21;
F_7 ( & V_14 ) ;
V_10 = F_43 ( sizeof( * V_10 ) , V_73 ) ;
if ( ! V_10 ) {
V_19 = - V_74 ;
goto V_75;
}
F_26 ( & V_56 ) ;
if ( F_6 ( V_11 ) > V_57 )
V_57 = F_6 ( V_11 ) ;
V_25 = F_44 ( V_58 ,
( V_57 + 1 ) * sizeof( T_2 ) , V_76 ) ;
if ( ! V_25 ) {
F_28 ( & V_56 ) ;
V_19 = - V_74 ;
goto V_77;
}
V_58 = V_25 ;
V_58 [ F_6 ( V_11 ) ] = 0 ;
F_28 ( & V_56 ) ;
V_10 -> V_12 = F_6 ( V_11 ) ;
V_10 -> V_27 = V_11 ;
V_10 -> V_15 = V_15 ;
V_10 -> V_78 = 1 ;
snprintf ( V_67 , sizeof( V_67 ) , L_7 ,
V_10 -> V_12 ) ;
V_10 -> V_61 = F_45 ( V_67 ,
V_68 ,
( V_68 == V_34 ) ?
0x03 : 0x01 ,
V_10 , & V_79 , NULL , 0 , 0 ) ;
if ( F_46 ( V_10 -> V_61 ) ) {
V_19 = F_47 ( V_10 -> V_61 ) ;
goto V_77;
}
F_13 ( V_11 , V_39 ,
& V_10 -> V_80 ,
& V_10 -> V_81 ) ;
F_48 ( & V_10 -> V_82 , & V_83 ) ;
F_14 ( L_8 ,
V_10 -> V_12 , V_11 ) ;
F_9 ( & V_14 ) ;
return 0 ;
V_77:
F_49 ( V_10 ) ;
V_75:
F_9 ( & V_14 ) ;
V_21:
return V_19 ;
}
static int F_50 ( unsigned int V_11 )
{
struct V_10 * V_84 ;
T_1 V_12 = F_6 ( V_11 ) ;
struct V_10 * V_54 =
F_5 ( V_11 ) ;
if ( ! V_54 )
return - V_71 ;
F_7 ( & V_14 ) ;
if ( V_54 -> V_27 == V_11 ) {
V_54 -> V_27 = F_38 ( V_11 ) ;
F_14 ( L_9 ,
V_54 -> V_27 ) ;
}
-- V_54 -> V_78 ;
F_14 ( L_10 ,
V_12 , V_11 , V_54 -> V_78 ) ;
if ( ! V_54 -> V_78 )
F_51 (phdev, n, &phy_dev_list, list) {
if ( V_54 -> V_12 == V_12 ) {
F_52 ( V_54 -> V_61 ) ;
F_53 ( & V_54 -> V_82 ) ;
F_49 ( V_54 ) ;
break;
}
}
F_9 ( & V_14 ) ;
return 0 ;
}
static int F_54 ( unsigned int V_11 )
{
struct V_85 * V_86 = & F_55 ( V_11 ) ;
struct V_10 * V_54 = F_5 ( V_11 ) ;
if ( ! V_54 ) {
if ( ! F_56 ( V_86 , V_87 ) ||
! F_56 ( V_86 , V_88 ) )
return - V_71 ;
if ( F_40 ( V_11 ) )
return - V_71 ;
} else {
F_7 ( & V_14 ) ;
++ V_54 -> V_78 ;
F_14 ( L_11 ,
V_11 , V_54 -> V_78 ) ;
F_9 ( & V_14 ) ;
}
F_57 ( & F_36 ( V_63 , V_11 ) ,
F_24 ) ;
F_14 ( L_12 , V_11 ) ;
return 0 ;
}
static void F_58 ( unsigned int V_11 )
{
if ( ! F_50 ( V_11 ) )
F_59 (
& F_36 ( V_63 , V_11 ) ) ;
F_14 ( L_13 , V_11 ) ;
}
static int F_60 ( struct V_89 * V_90 ,
unsigned long V_91 , void * V_92 )
{
unsigned int V_11 = ( unsigned long ) V_92 ;
switch ( V_91 ) {
case V_93 :
case V_94 :
F_54 ( V_11 ) ;
break;
case V_95 :
F_58 ( V_11 ) ;
break;
}
return V_96 ;
}
static int T_4 F_61 ( void )
{
int V_65 ;
if ( ! F_62 ( V_97 ) )
return - V_71 ;
F_63 ( & V_56 ) ;
V_98 =
F_32 ;
V_99 =
F_19 ;
F_64 () ;
F_39 (i)
if ( F_54 ( V_65 ) )
goto V_21;
F_65 ( & V_100 ) ;
F_66 () ;
F_1 () ;
return 0 ;
V_21:
F_39 (i)
F_58 ( V_65 ) ;
F_66 () ;
F_49 ( V_58 ) ;
V_98 = NULL ;
V_99 = NULL ;
return - V_71 ;
}
static void T_5 F_67 ( void )
{
struct V_10 * V_54 , * V_84 ;
int V_65 ;
F_64 () ;
F_68 ( & V_100 ) ;
F_7 ( & V_14 ) ;
F_51 (phdev, n, &phy_dev_list, list) {
F_17 ( V_54 -> V_27 ,
V_39 ,
V_54 -> V_80 ,
V_54 -> V_81 ) ;
F_52 ( V_54 -> V_61 ) ;
F_53 ( & V_54 -> V_82 ) ;
F_49 ( V_54 ) ;
}
F_9 ( & V_14 ) ;
V_98 = NULL ;
V_99 = NULL ;
F_39 (i)
F_59 (
& F_36 ( V_63 , V_65 ) ) ;
F_66 () ;
F_49 ( V_58 ) ;
F_4 ( V_3 ) ;
}
