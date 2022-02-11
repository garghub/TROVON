static void F_1 ( unsigned int V_1 , unsigned long V_2 )
{
unsigned long V_3 ;
T_1 V_4 ;
T_1 V_5 ;
F_2 ( V_1 , V_6 + V_2 ) ;
if ( F_3 ( V_2 >= F_4 ( 0 ) ) ) {
V_3 = ( V_2 & V_7 ) + V_8 ;
switch ( V_2 & ~ V_7 ) {
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
static void F_7 ( void )
{
T_1 V_22 ;
V_22 = F_5 ( V_6 + V_12 ) ;
V_22 |= V_23 ;
F_1 ( V_22 , V_12 ) ;
}
static T_2 F_8 ( void )
{
unsigned int V_24 , V_25 ;
T_1 V_26 = F_5 ( V_6 + V_19 ) ;
do {
V_25 = V_26 ;
V_24 = F_5 ( V_6 + V_17 ) ;
V_26 = F_5 ( V_6 + V_19 ) ;
} while ( V_25 != V_26 );
return ( ( V_27 ) V_25 << 32 ) | V_24 ;
}
static T_1 T_3 F_9 ( void )
{
return F_5 ( V_6 + V_17 ) ;
}
static V_27 F_10 ( struct V_28 * V_29 )
{
return F_9 () ;
}
static void F_11 ( struct V_28 * V_29 )
{
F_7 () ;
}
static T_2 T_3 F_12 ( void )
{
return F_9 () ;
}
static T_4 F_13 ( void )
{
F_14 ( sizeof( T_4 ) != sizeof( T_1 ) ,
L_2 ) ;
return F_9 () ;
}
static int T_5 F_15 ( void )
{
F_7 () ;
#if F_16 ( V_30 )
V_31 . V_32 = & F_13 ;
V_31 . V_33 = V_34 ;
F_17 ( & V_31 ) ;
#endif
if ( F_18 ( & V_35 , V_34 ) )
F_6 ( L_3 , V_35 . V_36 ) ;
F_19 ( F_12 , 32 , V_34 ) ;
return 0 ;
}
static void F_20 ( void )
{
unsigned int V_37 ;
V_37 = F_5 ( V_6 + V_12 ) ;
V_37 &= ~ ( V_38 | V_39 ) ;
F_1 ( V_37 , V_12 ) ;
F_1 ( 0 , V_40 ) ;
}
static void F_21 ( bool V_41 , unsigned long V_42 )
{
unsigned int V_37 ;
V_27 V_43 ;
V_37 = F_5 ( V_6 + V_12 ) ;
if ( V_41 ) {
V_37 |= V_39 ;
F_1 ( V_42 , V_16 ) ;
}
V_43 = F_8 () + V_42 ;
F_1 ( ( T_1 ) V_43 , V_14 ) ;
F_1 ( ( T_1 ) ( V_43 >> 32 ) , V_15 ) ;
F_1 ( 0x1 , V_40 ) ;
V_37 |= V_38 ;
F_1 ( V_37 , V_12 ) ;
}
static int F_22 ( unsigned long V_42 ,
struct V_44 * V_45 )
{
F_21 ( false , V_42 ) ;
return 0 ;
}
static int F_23 ( struct V_44 * V_45 )
{
F_20 () ;
return 0 ;
}
static int F_24 ( struct V_44 * V_45 )
{
unsigned long V_46 ;
V_46 = ( ( ( unsigned long long ) V_47 / V_21 * V_45 -> V_48 )
>> V_45 -> V_49 ) ;
F_20 () ;
F_21 ( true , V_46 ) ;
return 0 ;
}
static T_6 F_25 ( int V_50 , void * V_51 )
{
struct V_44 * V_45 = V_51 ;
F_1 ( 0x1 , V_52 ) ;
V_45 -> V_53 ( V_45 ) ;
return V_54 ;
}
static int F_26 ( void )
{
V_55 . V_56 = F_27 ( 0 ) ;
F_28 ( & V_55 , V_34 ,
0xf , 0xffffffff ) ;
F_29 ( V_57 [ V_58 ] , & V_59 ) ;
return 0 ;
}
static void F_30 ( struct V_60 * V_61 )
{
unsigned long V_62 ;
unsigned long V_4 = V_63 | V_64 ;
unsigned long V_2 = V_61 -> V_65 + V_9 ;
V_62 = F_5 ( V_6 + V_2 ) ;
if ( V_62 & V_4 ) {
V_62 &= ~ V_4 ;
F_1 ( V_62 , V_2 ) ;
}
}
static void F_31 ( unsigned long V_42 ,
struct V_60 * V_61 )
{
unsigned long V_62 ;
F_30 ( V_61 ) ;
V_62 = ( 1 << 31 ) | V_42 ;
F_1 ( V_62 , V_61 -> V_65 + V_10 ) ;
F_1 ( 0x1 , V_61 -> V_65 + V_66 ) ;
V_62 = F_5 ( V_6 + V_61 -> V_65 + V_9 ) ;
V_62 |= V_63 | V_64 |
V_67 ;
F_1 ( V_62 , V_61 -> V_65 + V_9 ) ;
}
static int F_32 ( unsigned long V_42 ,
struct V_44 * V_45 )
{
struct V_60 * V_61 ;
V_61 = F_33 ( V_45 , struct V_60 , V_45 ) ;
F_31 ( V_42 , V_61 ) ;
return 0 ;
}
static int F_34 ( struct V_44 * V_45 )
{
struct V_60 * V_61 ;
V_61 = F_33 ( V_45 , struct V_60 , V_45 ) ;
F_30 ( V_61 ) ;
return 0 ;
}
static int F_35 ( struct V_44 * V_45 )
{
struct V_60 * V_61 ;
unsigned long V_46 ;
V_61 = F_33 ( V_45 , struct V_60 , V_45 ) ;
V_46 = ( ( ( unsigned long long ) V_47 / V_21 * V_45 -> V_48 )
>> V_45 -> V_49 ) ;
F_30 ( V_61 ) ;
F_31 ( V_46 , V_61 ) ;
return 0 ;
}
static void F_36 ( struct V_60 * V_61 )
{
if ( ! F_37 ( & V_61 -> V_45 ) )
F_30 ( V_61 ) ;
if ( F_5 ( V_6 + V_61 -> V_65 + V_68 ) & 1 )
F_1 ( 0x1 , V_61 -> V_65 + V_68 ) ;
}
static T_6 F_38 ( int V_50 , void * V_51 )
{
struct V_60 * V_61 = V_51 ;
struct V_44 * V_45 = & V_61 -> V_45 ;
F_36 ( V_61 ) ;
V_45 -> V_53 ( V_45 ) ;
return V_54 ;
}
static int F_39 ( unsigned int V_69 )
{
struct V_60 * V_61 =
F_40 ( & V_70 , V_69 ) ;
struct V_44 * V_45 = & V_61 -> V_45 ;
V_61 -> V_65 = F_4 ( V_69 ) ;
snprintf ( V_61 -> V_36 , sizeof( V_61 -> V_36 ) , L_4 , V_69 ) ;
V_45 -> V_36 = V_61 -> V_36 ;
V_45 -> V_56 = F_27 ( V_69 ) ;
V_45 -> V_71 = F_32 ;
V_45 -> F_35 = F_35 ;
V_45 -> F_34 = F_34 ;
V_45 -> V_72 = F_34 ;
V_45 -> V_73 = F_34 ;
V_45 -> V_74 = F_34 ;
V_45 -> V_75 = V_76 | V_77 ;
V_45 -> V_78 = 450 ;
F_1 ( V_79 , V_61 -> V_65 + V_11 ) ;
if ( V_80 == V_81 ) {
if ( V_45 -> V_50 == - 1 )
return - V_82 ;
F_41 ( V_45 -> V_50 , F_27 ( V_69 ) ) ;
F_42 ( V_45 -> V_50 ) ;
} else {
F_43 ( V_57 [ V_83 ] , 0 ) ;
}
F_28 ( V_45 , V_34 / ( V_79 + 1 ) ,
0xf , 0x7fffffff ) ;
return 0 ;
}
static int F_44 ( unsigned int V_69 )
{
struct V_60 * V_61 =
F_40 ( & V_70 , V_69 ) ;
struct V_44 * V_45 = & V_61 -> V_45 ;
V_45 -> F_34 ( V_45 ) ;
if ( V_80 == V_81 ) {
if ( V_45 -> V_50 != - 1 )
F_45 ( V_45 -> V_50 ) ;
} else {
F_46 ( V_57 [ V_83 ] ) ;
}
return 0 ;
}
static int T_5 F_47 ( struct V_84 * V_85 , void T_7 * V_65 )
{
int V_86 , V_69 ;
struct V_87 * V_88 , * V_89 ;
V_89 = V_85 ? F_48 ( V_85 , L_5 ) :
F_49 ( NULL , L_5 ) ;
if ( F_50 ( V_89 ) )
F_6 ( L_6 , V_90 ) ;
V_34 = F_51 ( V_89 ) ;
V_88 = V_85 ? F_48 ( V_85 , L_7 ) : F_49 ( NULL , L_7 ) ;
if ( F_50 ( V_88 ) )
F_6 ( L_8 , V_90 ) ;
F_52 ( V_88 ) ;
V_6 = V_65 ;
if ( ! V_6 )
F_6 ( L_9 , V_90 ) ;
if ( V_80 == V_91 ) {
V_86 = F_53 ( V_57 [ V_83 ] ,
F_38 , L_10 ,
& V_70 ) ;
F_54 ( V_86 , L_11 ,
V_57 [ V_83 ] , V_86 ) ;
} else {
F_55 (cpu) {
int V_92 = V_57 [ V_83 + V_69 ] ;
struct V_60 * V_93 =
F_40 ( & V_70 , V_69 ) ;
V_93 -> V_45 . V_50 = - 1 ;
F_56 ( V_92 , V_94 ) ;
if ( F_57 ( V_92 ,
F_38 ,
V_95 | V_96 ,
V_93 -> V_36 , V_93 ) ) {
F_58 ( L_12 ,
V_69 ) ;
continue;
}
V_93 -> V_45 . V_50 = V_92 ;
}
}
V_86 = F_59 ( V_97 ,
L_13 ,
F_39 ,
F_44 ) ;
if ( V_86 )
goto V_98;
return 0 ;
V_98:
F_60 ( V_57 [ V_83 ] , & V_70 ) ;
return V_86 ;
}
static int T_5 F_61 ( struct V_84 * V_85 , unsigned int V_99 )
{
T_1 V_100 , V_5 ;
int V_101 ;
V_80 = V_99 ;
V_57 [ V_58 ] = F_62 ( V_85 , V_58 ) ;
#ifdef F_63
V_100 = F_64 ( V_85 ) ;
#else
V_100 = 0 ;
#endif
for ( V_5 = V_83 ; V_5 < V_100 ; V_5 ++ )
V_57 [ V_5 ] = F_62 ( V_85 , V_5 ) ;
V_101 = F_47 ( V_85 , F_65 ( V_85 , 0 ) ) ;
if ( V_101 )
return V_101 ;
V_101 = F_15 () ;
if ( V_101 )
return V_101 ;
return F_26 () ;
}
static int T_5 F_66 ( struct V_84 * V_85 )
{
return F_61 ( V_85 , V_81 ) ;
}
static int T_5 F_67 ( struct V_84 * V_85 )
{
return F_61 ( V_85 , V_91 ) ;
}
