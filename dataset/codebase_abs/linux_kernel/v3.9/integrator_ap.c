static void T_1 F_1 ( void )
{
F_2 ( V_1 , F_3 ( V_1 ) ) ;
V_2 = ( unsigned long ) V_3 ;
F_4 ( F_5 ( V_4 ) ) ;
}
static int F_6 ( void )
{
V_5 = F_7 ( V_6 + V_7 ) ;
return 0 ;
}
static void F_8 ( void )
{
F_9 ( - 1 , V_8 + V_9 ) ;
F_9 ( - 1 , V_6 + V_9 ) ;
F_9 ( - 1 , V_6 + V_10 ) ;
F_9 ( V_5 , V_6 + V_11 ) ;
}
static int T_1 F_10 ( void )
{
F_11 ( & V_12 ) ;
return 0 ;
}
static int F_12 ( struct V_13 * V_14 )
{
T_2 V_15 ;
F_9 ( V_16 | V_17 ,
V_18 + V_19 ) ;
V_15 = F_7 ( V_20 ) | V_21 ;
F_9 ( V_15 , V_20 ) ;
if ( ! ( F_7 ( V_20 ) & V_21 ) ) {
F_9 ( 0xa05f , V_22 ) ;
F_9 ( V_15 , V_20 ) ;
F_9 ( 0 , V_22 ) ;
}
return 0 ;
}
static void F_13 ( struct V_13 * V_14 )
{
T_2 V_15 ;
F_9 ( V_16 | V_17 ,
V_18 + V_19 ) ;
V_15 = F_7 ( V_20 ) & ~ V_21 ;
F_9 ( V_15 , V_20 ) ;
if ( F_7 ( V_20 ) & V_21 ) {
F_9 ( 0xa05f , V_22 ) ;
F_9 ( V_15 , V_20 ) ;
F_9 ( 0 , V_22 ) ;
}
}
static void F_14 ( struct V_13 * V_23 , int V_24 )
{
if ( V_24 )
F_9 ( V_16 ,
V_18 + V_25 ) ;
else
F_9 ( V_16 ,
V_18 + V_19 ) ;
}
static void F_15 ( struct V_26 * V_14 ,
void T_3 * V_27 , unsigned int V_28 )
{
unsigned int V_29 = 0 , V_30 = 0 , V_31 , V_32 ;
T_2 V_33 = V_14 -> V_34 . V_35 ;
if ( V_33 == V_36 ) {
V_31 = 1 << 4 ;
V_32 = 1 << 5 ;
} else {
V_31 = 1 << 6 ;
V_32 = 1 << 7 ;
}
if ( V_28 & V_37 )
V_30 |= V_31 ;
else
V_29 |= V_31 ;
if ( V_28 & V_38 )
V_30 |= V_32 ;
else
V_29 |= V_32 ;
F_16 ( V_29 , V_18 + V_25 ) ;
F_16 ( V_30 , V_18 + V_19 ) ;
}
static T_2 T_4 F_17 ( void )
{
return - F_7 ( ( void T_3 * ) V_39 + V_40 ) ;
}
static void F_18 ( unsigned long V_41 ,
void T_3 * V_27 )
{
T_2 V_42 = V_43 | V_44 ;
unsigned long V_45 = V_41 ;
if ( V_45 >= 1500000 ) {
V_45 /= 16 ;
V_42 |= V_46 ;
}
F_9 ( 0xffff , V_27 + V_47 ) ;
F_9 ( V_42 , V_27 + V_48 ) ;
F_19 ( V_27 + V_40 , L_1 ,
V_45 , 200 , 16 , V_49 ) ;
F_20 ( F_17 , 16 , V_45 ) ;
}
static T_5 F_21 ( int V_50 , void * V_51 )
{
struct V_52 * V_53 = V_51 ;
F_9 ( 1 , V_54 + V_55 ) ;
V_53 -> V_56 ( V_53 ) ;
return V_57 ;
}
static void F_22 ( enum V_58 V_59 , struct V_52 * V_53 )
{
T_2 V_42 = F_7 ( V_54 + V_48 ) & ~ V_43 ;
F_9 ( V_42 , V_54 + V_48 ) ;
switch ( V_59 ) {
case V_60 :
F_9 ( V_61 , V_54 + V_47 ) ;
V_42 |= V_44 | V_43 ;
F_9 ( V_42 , V_54 + V_48 ) ;
break;
case V_62 :
V_42 &= ~ V_44 ;
F_9 ( V_42 , V_54 + V_48 ) ;
break;
case V_63 :
case V_64 :
case V_65 :
default:
break;
}
}
static int F_23 ( unsigned long V_66 , struct V_52 * V_53 )
{
unsigned long V_42 = F_7 ( V_54 + V_48 ) ;
F_9 ( V_42 & ~ V_43 , V_54 + V_48 ) ;
F_9 ( V_66 , V_54 + V_47 ) ;
F_9 ( V_42 | V_43 , V_54 + V_48 ) ;
return 0 ;
}
static void F_24 ( unsigned long V_41 ,
void T_3 * V_27 , int V_50 )
{
unsigned long V_45 = V_41 ;
unsigned int V_42 = 0 ;
V_54 = V_27 ;
if ( V_45 > 0x100000 * V_67 ) {
V_45 /= 256 ;
V_42 |= V_68 ;
} else if ( V_45 > 0x10000 * V_67 ) {
V_45 /= 16 ;
V_42 |= V_46 ;
}
V_61 = V_45 / V_67 ;
F_9 ( V_42 , V_54 + V_48 ) ;
F_25 ( V_50 , & V_69 ) ;
F_26 ( & V_70 ,
V_45 ,
1 ,
0xffffU ) ;
}
void T_1 F_27 ( void )
{
}
static void T_1 F_28 ( void )
{
struct V_71 * V_72 ;
const char * V_73 ;
void T_3 * V_27 ;
int V_74 ;
int V_50 ;
struct V_75 * V_75 ;
unsigned long V_45 ;
V_75 = F_29 ( L_2 , NULL ) ;
F_30 ( F_31 ( V_75 ) ) ;
F_32 ( V_75 ) ;
V_45 = F_33 ( V_75 ) ;
V_74 = F_34 ( V_76 ,
L_3 , & V_73 ) ;
if ( F_35 ( V_74 ) )
return;
V_72 = F_36 ( V_73 ) ;
V_27 = F_37 ( V_72 , 0 ) ;
if ( F_35 ( ! V_27 ) )
return;
F_9 ( 0 , V_27 + V_48 ) ;
F_18 ( V_45 , V_27 ) ;
V_74 = F_34 ( V_76 ,
L_4 , & V_73 ) ;
if ( F_35 ( V_74 ) )
return;
V_72 = F_36 ( V_73 ) ;
V_27 = F_37 ( V_72 , 0 ) ;
if ( F_35 ( ! V_27 ) )
return;
V_50 = F_38 ( V_72 , 0 ) ;
F_9 ( 0 , V_27 + V_48 ) ;
F_24 ( V_45 , V_27 , V_50 ) ;
}
static void T_1 F_39 ( void )
{
F_9 ( 0xffffffffU , V_8 + V_9 ) ;
F_40 ( V_77 ) ;
F_41 ( false ) ;
}
static void T_1 F_42 ( void )
{
unsigned long V_78 ;
struct V_71 * V_79 ;
struct V_71 * V_80 ;
struct V_81 * V_82 ;
struct V_83 * V_84 ;
struct V_85 * V_86 ;
T_2 V_87 ;
int V_74 ;
int V_88 ;
V_79 = F_36 ( L_5 ) ;
if ( ! V_79 )
return;
V_80 = F_36 ( L_6 ) ;
if ( ! V_80 )
return;
V_18 = F_37 ( V_80 , 0 ) ;
if ( ! V_18 )
return;
V_87 = F_7 ( V_18 ) ;
V_86 = F_43 ( sizeof( * V_86 ) , V_89 ) ;
if ( ! V_86 )
return;
V_74 = F_34 ( V_79 , L_7 ,
& V_86 -> V_90 ) ;
if ( V_74 )
return;
V_74 = F_34 ( V_79 , L_8 , & V_86 -> V_91 ) ;
if ( V_74 )
return;
V_86 -> V_92 = L_9 ;
V_86 -> V_93 = F_44 ( V_89 , L_10 ,
'A' + ( V_87 & 0x0f ) ) ;
V_84 = F_45 ( V_86 ) ;
if ( F_46 ( V_84 ) ) {
F_47 ( V_86 -> V_93 ) ;
F_47 ( V_86 ) ;
return;
}
V_82 = F_48 ( V_84 ) ;
if ( ! F_46 ( V_82 ) )
F_49 ( V_82 , V_87 ) ;
F_50 ( V_79 , V_94 ,
V_95 , V_82 ) ;
V_78 = F_7 ( V_18 + V_96 ) ;
for ( V_88 = 0 ; V_88 < 4 ; V_88 ++ ) {
struct V_97 * V_98 ;
if ( ( V_78 & ( 16 << V_88 ) ) == 0 )
continue;
V_98 = F_43 ( sizeof( struct V_97 ) , V_89 ) ;
if ( ! V_98 )
continue;
V_98 -> V_99 . V_35 = 0xc0000000 + 0x10000000 * V_88 ;
V_98 -> V_99 . V_100 = V_98 -> V_99 . V_35 + 0x0fffffff ;
V_98 -> V_99 . V_101 = V_102 ;
V_98 -> V_50 = V_103 + V_88 ;
V_98 -> V_104 = V_88 ;
F_51 ( V_98 ) ;
}
}
static void T_1 F_52 ( void )
{
F_2 ( V_105 , F_3 ( V_105 ) ) ;
F_1 () ;
}
static void T_1 F_53 ( void )
{
struct V_75 * V_75 ;
unsigned long V_45 ;
V_75 = F_29 ( L_2 , NULL ) ;
F_30 ( F_31 ( V_75 ) ) ;
F_32 ( V_75 ) ;
V_45 = F_33 ( V_75 ) ;
F_9 ( 0 , V_106 + V_48 ) ;
F_9 ( 0 , V_107 + V_48 ) ;
F_9 ( 0 , V_39 + V_48 ) ;
F_18 ( V_45 , ( void T_3 * ) V_39 ) ;
F_24 ( V_45 , ( void T_3 * ) V_107 ,
V_108 ) ;
}
static void T_1 F_54 ( void )
{
F_9 ( - 1 , V_8 + V_9 ) ;
F_9 ( - 1 , V_6 + V_9 ) ;
F_9 ( - 1 , V_6 + V_10 ) ;
F_55 ( V_6 , L_11 , V_109 ,
- 1 , V_110 , NULL ) ;
F_41 ( false ) ;
}
static void T_1 F_56 ( void )
{
unsigned long V_78 ;
int V_88 ;
F_57 ( & V_111 ) ;
V_18 = F_58 ( V_112 ) ;
V_78 = F_7 ( V_18 + V_96 ) ;
for ( V_88 = 0 ; V_88 < 4 ; V_88 ++ ) {
struct V_97 * V_98 ;
if ( ( V_78 & ( 16 << V_88 ) ) == 0 )
continue;
V_98 = F_43 ( sizeof( struct V_97 ) , V_89 ) ;
if ( ! V_98 )
continue;
V_98 -> V_99 . V_35 = 0xc0000000 + 0x10000000 * V_88 ;
V_98 -> V_99 . V_100 = V_98 -> V_99 . V_35 + 0x0fffffff ;
V_98 -> V_99 . V_101 = V_102 ;
V_98 -> V_50 = V_103 + V_88 ;
V_98 -> V_104 = V_88 ;
F_51 ( V_98 ) ;
}
F_59 ( false ) ;
}
