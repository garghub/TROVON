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
static void T_5 F_15 ( void )
{
F_7 () ;
V_30 . V_31 = & F_13 ;
V_30 . V_32 = V_33 ;
F_16 ( & V_30 ) ;
if ( F_17 ( & V_34 , V_33 ) )
F_6 ( L_3 , V_34 . V_35 ) ;
F_18 ( F_12 , 32 , V_33 ) ;
}
static void F_19 ( void )
{
unsigned int V_36 ;
V_36 = F_5 ( V_6 + V_12 ) ;
V_36 &= ~ ( V_37 | V_38 ) ;
F_1 ( V_36 , V_12 ) ;
F_1 ( 0 , V_39 ) ;
}
static void F_20 ( bool V_40 , unsigned long V_41 )
{
unsigned int V_36 ;
V_27 V_42 ;
V_36 = F_5 ( V_6 + V_12 ) ;
if ( V_40 ) {
V_36 |= V_38 ;
F_1 ( V_41 , V_16 ) ;
}
V_42 = F_8 () + V_41 ;
F_1 ( ( T_1 ) V_42 , V_14 ) ;
F_1 ( ( T_1 ) ( V_42 >> 32 ) , V_15 ) ;
F_1 ( 0x1 , V_39 ) ;
V_36 |= V_37 ;
F_1 ( V_36 , V_12 ) ;
}
static int F_21 ( unsigned long V_41 ,
struct V_43 * V_44 )
{
F_20 ( false , V_41 ) ;
return 0 ;
}
static int F_22 ( struct V_43 * V_44 )
{
F_19 () ;
return 0 ;
}
static int F_23 ( struct V_43 * V_44 )
{
unsigned long V_45 ;
V_45 = ( ( ( unsigned long long ) V_46 / V_21 * V_44 -> V_47 )
>> V_44 -> V_48 ) ;
F_19 () ;
F_20 ( true , V_45 ) ;
return 0 ;
}
static T_6 F_24 ( int V_49 , void * V_50 )
{
struct V_43 * V_44 = V_50 ;
F_1 ( 0x1 , V_51 ) ;
V_44 -> V_52 ( V_44 ) ;
return V_53 ;
}
static void F_25 ( void )
{
V_54 . V_55 = F_26 ( 0 ) ;
F_27 ( & V_54 , V_33 ,
0xf , 0xffffffff ) ;
F_28 ( V_56 [ V_57 ] , & V_58 ) ;
}
static void F_29 ( struct V_59 * V_60 )
{
unsigned long V_61 ;
unsigned long V_4 = V_62 | V_63 ;
unsigned long V_2 = V_60 -> V_64 + V_9 ;
V_61 = F_5 ( V_6 + V_2 ) ;
if ( V_61 & V_4 ) {
V_61 &= ~ V_4 ;
F_1 ( V_61 , V_2 ) ;
}
}
static void F_30 ( unsigned long V_41 ,
struct V_59 * V_60 )
{
unsigned long V_61 ;
F_29 ( V_60 ) ;
V_61 = ( 1 << 31 ) | V_41 ;
F_1 ( V_61 , V_60 -> V_64 + V_10 ) ;
F_1 ( 0x1 , V_60 -> V_64 + V_65 ) ;
V_61 = F_5 ( V_6 + V_60 -> V_64 + V_9 ) ;
V_61 |= V_62 | V_63 |
V_66 ;
F_1 ( V_61 , V_60 -> V_64 + V_9 ) ;
}
static int F_31 ( unsigned long V_41 ,
struct V_43 * V_44 )
{
struct V_59 * V_60 ;
V_60 = F_32 ( V_44 , struct V_59 , V_44 ) ;
F_30 ( V_41 , V_60 ) ;
return 0 ;
}
static int F_33 ( struct V_43 * V_44 )
{
struct V_59 * V_60 ;
V_60 = F_32 ( V_44 , struct V_59 , V_44 ) ;
F_29 ( V_60 ) ;
return 0 ;
}
static int F_34 ( struct V_43 * V_44 )
{
struct V_59 * V_60 ;
unsigned long V_45 ;
V_60 = F_32 ( V_44 , struct V_59 , V_44 ) ;
V_45 = ( ( ( unsigned long long ) V_46 / V_21 * V_44 -> V_47 )
>> V_44 -> V_48 ) ;
F_29 ( V_60 ) ;
F_30 ( V_45 , V_60 ) ;
return 0 ;
}
static void F_35 ( struct V_59 * V_60 )
{
if ( ! F_36 ( & V_60 -> V_44 ) )
F_29 ( V_60 ) ;
if ( F_5 ( V_6 + V_60 -> V_64 + V_67 ) & 1 )
F_1 ( 0x1 , V_60 -> V_64 + V_67 ) ;
}
static T_6 F_37 ( int V_49 , void * V_50 )
{
struct V_59 * V_60 = V_50 ;
struct V_43 * V_44 = & V_60 -> V_44 ;
F_35 ( V_60 ) ;
V_44 -> V_52 ( V_44 ) ;
return V_53 ;
}
static int F_38 ( struct V_59 * V_60 )
{
struct V_43 * V_44 = & V_60 -> V_44 ;
unsigned int V_68 = F_39 () ;
V_60 -> V_64 = F_4 ( V_68 ) ;
snprintf ( V_60 -> V_35 , sizeof( V_60 -> V_35 ) , L_4 , V_68 ) ;
V_44 -> V_35 = V_60 -> V_35 ;
V_44 -> V_55 = F_26 ( V_68 ) ;
V_44 -> V_69 = F_31 ;
V_44 -> F_34 = F_34 ;
V_44 -> F_33 = F_33 ;
V_44 -> V_70 = F_33 ;
V_44 -> V_71 = F_33 ;
V_44 -> V_72 = V_73 | V_74 ;
V_44 -> V_75 = 450 ;
F_1 ( V_76 , V_60 -> V_64 + V_11 ) ;
if ( V_77 == V_78 ) {
if ( V_44 -> V_49 == - 1 )
return - V_79 ;
F_40 ( V_44 -> V_49 , F_26 ( V_68 ) ) ;
F_41 ( V_44 -> V_49 ) ;
} else {
F_42 ( V_56 [ V_80 ] , 0 ) ;
}
F_27 ( V_44 , V_33 / ( V_76 + 1 ) ,
0xf , 0x7fffffff ) ;
return 0 ;
}
static void F_43 ( struct V_59 * V_60 )
{
struct V_43 * V_44 = & V_60 -> V_44 ;
V_44 -> F_33 ( V_44 ) ;
if ( V_77 == V_78 ) {
if ( V_44 -> V_49 != - 1 )
F_44 ( V_44 -> V_49 ) ;
} else {
F_45 ( V_56 [ V_80 ] ) ;
}
}
static int F_46 ( struct V_81 * V_82 ,
unsigned long V_83 , void * V_84 )
{
struct V_59 * V_60 ;
switch ( V_83 & ~ V_85 ) {
case V_86 :
V_60 = F_47 ( & V_87 ) ;
F_38 ( V_60 ) ;
break;
case V_88 :
V_60 = F_47 ( & V_87 ) ;
F_43 ( V_60 ) ;
break;
}
return V_89 ;
}
static void T_5 F_48 ( struct V_90 * V_91 , void T_7 * V_64 )
{
int V_92 , V_68 ;
struct V_59 * V_60 = F_47 ( & V_87 ) ;
struct V_93 * V_94 , * V_95 ;
V_95 = V_91 ? F_49 ( V_91 , L_5 ) :
F_50 ( NULL , L_5 ) ;
if ( F_51 ( V_95 ) )
F_6 ( L_6 , V_96 ) ;
V_33 = F_52 ( V_95 ) ;
V_94 = V_91 ? F_49 ( V_91 , L_7 ) : F_50 ( NULL , L_7 ) ;
if ( F_51 ( V_94 ) )
F_6 ( L_8 , V_96 ) ;
F_53 ( V_94 ) ;
V_6 = V_64 ;
if ( ! V_6 )
F_6 ( L_9 , V_96 ) ;
if ( V_77 == V_97 ) {
V_92 = F_54 ( V_56 [ V_80 ] ,
F_37 , L_10 ,
& V_87 ) ;
F_55 ( V_92 , L_11 ,
V_56 [ V_80 ] , V_92 ) ;
} else {
F_56 (cpu) {
int V_98 = V_56 [ V_80 + V_68 ] ;
struct V_59 * V_99 =
F_57 ( & V_87 , V_68 ) ;
V_99 -> V_44 . V_49 = - 1 ;
F_58 ( V_98 , V_100 ) ;
if ( F_59 ( V_98 ,
F_37 ,
V_101 | V_102 ,
V_99 -> V_35 , V_99 ) ) {
F_60 ( L_12 ,
V_68 ) ;
continue;
}
V_99 -> V_44 . V_49 = V_98 ;
}
}
V_92 = F_61 ( & V_103 ) ;
if ( V_92 )
goto V_104;
F_38 ( V_60 ) ;
return;
V_104:
F_62 ( V_56 [ V_80 ] , & V_87 ) ;
}
static void T_5 F_63 ( struct V_90 * V_91 , unsigned int V_105 )
{
T_1 V_106 , V_5 ;
V_77 = V_105 ;
V_56 [ V_57 ] = F_64 ( V_91 , V_57 ) ;
#ifdef F_65
V_106 = F_66 ( V_91 ) ;
#else
V_106 = 0 ;
#endif
for ( V_5 = V_80 ; V_5 < V_106 ; V_5 ++ )
V_56 [ V_5 ] = F_64 ( V_91 , V_5 ) ;
F_48 ( V_91 , F_67 ( V_91 , 0 ) ) ;
F_15 () ;
F_25 () ;
}
static void T_5 F_68 ( struct V_90 * V_91 )
{
return F_63 ( V_91 , V_78 ) ;
}
static void T_5 F_69 ( struct V_90 * V_91 )
{
return F_63 ( V_91 , V_97 ) ;
}
