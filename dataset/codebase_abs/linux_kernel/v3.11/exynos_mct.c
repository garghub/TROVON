static void F_1 ( unsigned int V_1 , unsigned long V_2 )
{
unsigned long V_3 ;
T_1 V_4 ;
T_1 V_5 ;
F_2 ( V_1 , V_6 + V_2 ) ;
if ( F_3 ( V_2 >= F_4 ( 0 ) ) ) {
V_3 = ( V_2 & ~ V_7 ) + V_8 ;
switch ( V_2 & V_7 ) {
case V_9 :
V_4 = 1 << 3 ;
break;
case V_10 :
V_4 = 1 << 1 ;
break;
case V_11 :
V_4 = 1 << 0 ;
break;
default:
return;
}
} else {
switch ( V_2 ) {
case V_12 :
V_3 = V_13 ;
V_4 = 1 << 16 ;
break;
case V_14 :
V_3 = V_13 ;
V_4 = 1 << 0 ;
break;
case V_15 :
V_3 = V_13 ;
V_4 = 1 << 1 ;
break;
case V_16 :
V_3 = V_13 ;
V_4 = 1 << 2 ;
break;
case V_17 :
V_3 = V_18 ;
V_4 = 1 << 0 ;
break;
case V_19 :
V_3 = V_18 ;
V_4 = 1 << 1 ;
break;
default:
return;
}
}
for ( V_5 = 0 ; V_5 < V_20 / 1000 * V_21 ; V_5 ++ )
if ( F_5 ( V_6 + V_3 ) & V_4 ) {
F_2 ( V_4 , V_6 + V_3 ) ;
return;
}
F_6 ( L_1 , V_1 , V_2 ) ;
}
static void F_7 ( T_1 V_22 , T_1 V_23 )
{
T_1 V_24 ;
F_1 ( V_23 , V_17 ) ;
F_1 ( V_22 , V_19 ) ;
V_24 = F_5 ( V_6 + V_12 ) ;
V_24 |= V_25 ;
F_1 ( V_24 , V_12 ) ;
}
static T_2 F_8 ( struct V_26 * V_27 )
{
unsigned int V_23 , V_22 ;
T_1 V_28 = F_5 ( V_6 + V_19 ) ;
do {
V_22 = V_28 ;
V_23 = F_5 ( V_6 + V_17 ) ;
V_28 = F_5 ( V_6 + V_19 ) ;
} while ( V_22 != V_28 );
return ( ( T_2 ) V_22 << 32 ) | V_23 ;
}
static void F_9 ( struct V_26 * V_27 )
{
F_7 ( 0 , 0 ) ;
}
static void T_3 F_10 ( void )
{
F_7 ( 0 , 0 ) ;
if ( F_11 ( & V_29 , V_30 ) )
F_6 ( L_2 , V_29 . V_31 ) ;
}
static void F_12 ( void )
{
unsigned int V_32 ;
V_32 = F_5 ( V_6 + V_12 ) ;
V_32 &= ~ ( V_33 | V_34 ) ;
F_1 ( V_32 , V_12 ) ;
F_1 ( 0 , V_35 ) ;
}
static void F_13 ( enum V_36 V_37 ,
unsigned long V_38 )
{
unsigned int V_32 ;
T_2 V_39 ;
V_32 = F_5 ( V_6 + V_12 ) ;
if ( V_37 == V_40 ) {
V_32 |= V_34 ;
F_1 ( V_38 , V_16 ) ;
}
V_39 = F_8 ( & V_29 ) + V_38 ;
F_1 ( ( T_1 ) V_39 , V_14 ) ;
F_1 ( ( T_1 ) ( V_39 >> 32 ) , V_15 ) ;
F_1 ( 0x1 , V_35 ) ;
V_32 |= V_33 ;
F_1 ( V_32 , V_12 ) ;
}
static int F_14 ( unsigned long V_38 ,
struct V_41 * V_42 )
{
F_13 ( V_42 -> V_37 , V_38 ) ;
return 0 ;
}
static void F_15 ( enum V_36 V_37 ,
struct V_41 * V_42 )
{
unsigned long V_43 ;
F_12 () ;
switch ( V_37 ) {
case V_40 :
V_43 =
( ( ( unsigned long long ) V_44 / V_21 * V_42 -> V_45 ) >> V_42 -> V_46 ) ;
F_13 ( V_37 , V_43 ) ;
break;
case V_47 :
case V_48 :
case V_49 :
case V_50 :
break;
}
}
static T_4 F_16 ( int V_51 , void * V_52 )
{
struct V_41 * V_42 = V_52 ;
F_1 ( 0x1 , V_53 ) ;
V_42 -> V_54 ( V_42 ) ;
return V_55 ;
}
static void F_17 ( void )
{
V_56 . V_57 = F_18 ( 0 ) ;
F_19 ( & V_56 , V_30 ,
0xf , 0xffffffff ) ;
F_20 ( V_58 [ V_59 ] , & V_60 ) ;
}
static void F_21 ( struct V_61 * V_62 )
{
unsigned long V_63 ;
unsigned long V_4 = V_64 | V_65 ;
unsigned long V_2 = V_62 -> V_66 + V_9 ;
V_63 = F_5 ( V_6 + V_2 ) ;
if ( V_63 & V_4 ) {
V_63 &= ~ V_4 ;
F_1 ( V_63 , V_2 ) ;
}
}
static void F_22 ( unsigned long V_38 ,
struct V_61 * V_62 )
{
unsigned long V_63 ;
F_21 ( V_62 ) ;
V_63 = ( 1 << 31 ) | V_38 ;
F_1 ( V_63 , V_62 -> V_66 + V_10 ) ;
F_1 ( 0x1 , V_62 -> V_66 + V_67 ) ;
V_63 = F_5 ( V_6 + V_62 -> V_66 + V_9 ) ;
V_63 |= V_64 | V_65 |
V_68 ;
F_1 ( V_63 , V_62 -> V_66 + V_9 ) ;
}
static int F_23 ( unsigned long V_38 ,
struct V_41 * V_42 )
{
struct V_61 * V_62 = F_24 ( & V_69 ) ;
F_22 ( V_38 , V_62 ) ;
return 0 ;
}
static inline void F_25 ( enum V_36 V_37 ,
struct V_41 * V_42 )
{
struct V_61 * V_62 = F_24 ( & V_69 ) ;
unsigned long V_43 ;
F_21 ( V_62 ) ;
switch ( V_37 ) {
case V_40 :
V_43 =
( ( ( unsigned long long ) V_44 / V_21 * V_42 -> V_45 ) >> V_42 -> V_46 ) ;
F_22 ( V_43 , V_62 ) ;
break;
case V_47 :
case V_48 :
case V_49 :
case V_50 :
break;
}
}
static int F_26 ( struct V_61 * V_62 )
{
struct V_41 * V_42 = V_62 -> V_42 ;
if ( V_42 -> V_37 != V_40 )
F_21 ( V_62 ) ;
if ( F_5 ( V_6 + V_62 -> V_66 + V_70 ) & 1 ) {
F_1 ( 0x1 , V_62 -> V_66 + V_70 ) ;
return 1 ;
} else {
return 0 ;
}
}
static T_4 F_27 ( int V_51 , void * V_52 )
{
struct V_61 * V_62 = V_52 ;
struct V_41 * V_42 = V_62 -> V_42 ;
F_26 ( V_62 ) ;
V_42 -> V_54 ( V_42 ) ;
return V_55 ;
}
static int F_28 ( struct V_41 * V_42 )
{
struct V_61 * V_62 ;
unsigned int V_71 = F_29 () ;
V_62 = F_24 ( & V_69 ) ;
V_62 -> V_42 = V_42 ;
V_62 -> V_66 = F_4 ( V_71 ) ;
sprintf ( V_62 -> V_31 , L_3 , V_71 ) ;
V_42 -> V_31 = V_62 -> V_31 ;
V_42 -> V_57 = F_18 ( V_71 ) ;
V_42 -> V_72 = F_23 ;
V_42 -> V_73 = F_25 ;
V_42 -> V_74 = V_75 | V_76 ;
V_42 -> V_77 = 450 ;
F_19 ( V_42 , V_30 / ( V_78 + 1 ) ,
0xf , 0x7fffffff ) ;
F_1 ( V_78 , V_62 -> V_66 + V_11 ) ;
if ( V_79 == V_80 ) {
V_42 -> V_51 = V_58 [ V_81 + V_71 ] ;
if ( F_30 ( V_42 -> V_51 , F_27 ,
V_82 | V_83 ,
V_42 -> V_31 , V_62 ) ) {
F_31 ( L_4 ,
V_42 -> V_51 ) ;
return - V_84 ;
}
F_32 ( V_42 -> V_51 , F_18 ( V_71 ) ) ;
} else {
F_33 ( V_58 [ V_81 ] , 0 ) ;
}
return 0 ;
}
static void F_34 ( struct V_41 * V_42 )
{
V_42 -> V_73 ( V_48 , V_42 ) ;
if ( V_79 == V_80 )
F_35 ( V_42 -> V_51 , F_24 ( & V_69 ) ) ;
else
F_36 ( V_58 [ V_81 ] ) ;
}
static void T_3 F_37 ( struct V_85 * V_86 , void T_5 * V_66 )
{
struct V_87 * V_88 , * V_89 ;
V_89 = V_86 ? F_38 ( V_86 , L_5 ) :
F_39 ( NULL , L_5 ) ;
if ( F_40 ( V_89 ) )
F_6 ( L_6 , V_90 ) ;
V_30 = F_41 ( V_89 ) ;
V_88 = V_86 ? F_38 ( V_86 , L_7 ) : F_39 ( NULL , L_7 ) ;
if ( F_40 ( V_88 ) )
F_6 ( L_8 , V_90 ) ;
F_42 ( V_88 ) ;
V_6 = V_66 ;
if ( ! V_6 )
F_6 ( L_9 , V_90 ) ;
#ifdef F_43
if ( V_79 == V_91 ) {
int V_92 ;
V_92 = F_44 ( V_58 [ V_81 ] ,
F_27 , L_10 ,
& V_69 ) ;
F_45 ( V_92 , L_11 ,
V_58 [ V_81 ] , V_92 ) ;
}
F_46 ( & V_93 ) ;
#endif
}
void T_3 F_47 ( void T_5 * V_66 , int V_94 , int V_95 , int V_96 )
{
V_58 [ V_59 ] = V_94 ;
V_58 [ V_81 ] = V_95 ;
V_58 [ V_97 ] = V_96 ;
V_79 = V_80 ;
F_37 ( NULL , V_66 ) ;
F_10 () ;
F_17 () ;
}
static void T_3 F_48 ( struct V_85 * V_86 , unsigned int V_98 )
{
T_1 V_99 , V_5 ;
V_79 = V_98 ;
V_58 [ V_59 ] = F_49 ( V_86 , V_59 ) ;
#ifdef F_50
V_99 = F_51 ( V_86 ) ;
#else
V_99 = 0 ;
#endif
for ( V_5 = V_81 ; V_5 < V_99 ; V_5 ++ )
V_58 [ V_5 ] = F_49 ( V_86 , V_5 ) ;
F_37 ( V_86 , F_52 ( V_86 , 0 ) ) ;
F_10 () ;
F_17 () ;
}
static void T_3 F_53 ( struct V_85 * V_86 )
{
return F_48 ( V_86 , V_80 ) ;
}
static void T_3 F_54 ( struct V_85 * V_86 )
{
return F_48 ( V_86 , V_91 ) ;
}
