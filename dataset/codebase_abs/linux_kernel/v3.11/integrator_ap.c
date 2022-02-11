static void T_1 F_1 ( void )
{
F_2 ( V_1 , F_3 ( V_1 ) ) ;
F_4 () ;
}
static int F_5 ( void )
{
V_2 = F_6 ( V_3 + V_4 ) ;
return 0 ;
}
static void F_7 ( void )
{
F_8 ( - 1 , V_5 + V_6 ) ;
F_8 ( - 1 , V_3 + V_6 ) ;
F_8 ( - 1 , V_3 + V_7 ) ;
F_8 ( V_2 , V_3 + V_8 ) ;
}
static int T_1 F_9 ( void )
{
F_10 ( & V_9 ) ;
return 0 ;
}
static int F_11 ( struct V_10 * V_11 )
{
T_2 V_12 ;
F_8 ( V_13 | V_14 ,
V_15 + V_16 ) ;
V_12 = F_6 ( V_17 ) | V_18 ;
F_8 ( V_12 , V_17 ) ;
if ( ! ( F_6 ( V_17 ) & V_18 ) ) {
F_8 ( 0xa05f , V_19 ) ;
F_8 ( V_12 , V_17 ) ;
F_8 ( 0 , V_19 ) ;
}
return 0 ;
}
static void F_12 ( struct V_10 * V_11 )
{
T_2 V_12 ;
F_8 ( V_13 | V_14 ,
V_15 + V_16 ) ;
V_12 = F_6 ( V_17 ) & ~ V_18 ;
F_8 ( V_12 , V_17 ) ;
if ( F_6 ( V_17 ) & V_18 ) {
F_8 ( 0xa05f , V_19 ) ;
F_8 ( V_12 , V_17 ) ;
F_8 ( 0 , V_19 ) ;
}
}
static void F_13 ( struct V_10 * V_20 , int V_21 )
{
if ( V_21 )
F_8 ( V_13 ,
V_15 + V_22 ) ;
else
F_8 ( V_13 ,
V_15 + V_16 ) ;
}
static void F_14 ( struct V_23 * V_11 ,
void T_3 * V_24 , unsigned int V_25 )
{
unsigned int V_26 = 0 , V_27 = 0 , V_28 , V_29 ;
T_2 V_30 = V_11 -> V_31 . V_32 ;
if ( V_30 == V_33 ) {
V_28 = 1 << 4 ;
V_29 = 1 << 5 ;
} else {
V_28 = 1 << 6 ;
V_29 = 1 << 7 ;
}
if ( V_25 & V_34 )
V_27 |= V_28 ;
else
V_26 |= V_28 ;
if ( V_25 & V_35 )
V_27 |= V_29 ;
else
V_26 |= V_29 ;
F_15 ( V_26 , V_15 + V_22 ) ;
F_15 ( V_27 , V_15 + V_16 ) ;
}
static T_2 T_4 F_16 ( void )
{
return - F_6 ( ( void T_3 * ) V_36 + V_37 ) ;
}
static void F_17 ( unsigned long V_38 ,
void T_3 * V_24 )
{
T_2 V_39 = V_40 | V_41 ;
unsigned long V_42 = V_38 ;
if ( V_42 >= 1500000 ) {
V_42 /= 16 ;
V_39 |= V_43 ;
}
F_8 ( 0xffff , V_24 + V_44 ) ;
F_8 ( V_39 , V_24 + V_45 ) ;
F_18 ( V_24 + V_37 , L_1 ,
V_42 , 200 , 16 , V_46 ) ;
F_19 ( F_16 , 16 , V_42 ) ;
}
static T_5 F_20 ( int V_47 , void * V_48 )
{
struct V_49 * V_50 = V_48 ;
F_8 ( 1 , V_51 + V_52 ) ;
V_50 -> V_53 ( V_50 ) ;
return V_54 ;
}
static void F_21 ( enum V_55 V_56 , struct V_49 * V_50 )
{
T_2 V_39 = F_6 ( V_51 + V_45 ) & ~ V_40 ;
F_8 ( V_39 , V_51 + V_45 ) ;
switch ( V_56 ) {
case V_57 :
F_8 ( V_58 , V_51 + V_44 ) ;
V_39 |= V_41 | V_40 ;
F_8 ( V_39 , V_51 + V_45 ) ;
break;
case V_59 :
V_39 &= ~ V_41 ;
F_8 ( V_39 , V_51 + V_45 ) ;
break;
case V_60 :
case V_61 :
case V_62 :
default:
break;
}
}
static int F_22 ( unsigned long V_63 , struct V_49 * V_50 )
{
unsigned long V_39 = F_6 ( V_51 + V_45 ) ;
F_8 ( V_39 & ~ V_40 , V_51 + V_45 ) ;
F_8 ( V_63 , V_51 + V_44 ) ;
F_8 ( V_39 | V_40 , V_51 + V_45 ) ;
return 0 ;
}
static void F_23 ( unsigned long V_38 ,
void T_3 * V_24 , int V_47 )
{
unsigned long V_42 = V_38 ;
unsigned int V_39 = 0 ;
V_51 = V_24 ;
if ( V_42 > 0x100000 * V_64 ) {
V_42 /= 256 ;
V_39 |= V_65 ;
} else if ( V_42 > 0x10000 * V_64 ) {
V_42 /= 16 ;
V_39 |= V_43 ;
}
V_58 = V_42 / V_64 ;
F_8 ( V_39 , V_51 + V_45 ) ;
F_24 ( V_47 , & V_66 ) ;
F_25 ( & V_67 ,
V_42 ,
1 ,
0xffffU ) ;
}
void T_1 F_26 ( void )
{
}
static void T_1 F_27 ( void )
{
struct V_68 * V_69 ;
const char * V_70 ;
void T_3 * V_24 ;
int V_71 ;
int V_47 ;
struct V_72 * V_72 ;
unsigned long V_42 ;
V_72 = F_28 ( L_2 , NULL ) ;
F_29 ( F_30 ( V_72 ) ) ;
F_31 ( V_72 ) ;
V_42 = F_32 ( V_72 ) ;
V_71 = F_33 ( V_73 ,
L_3 , & V_70 ) ;
if ( F_34 ( V_71 ) )
return;
V_69 = F_35 ( V_70 ) ;
V_24 = F_36 ( V_69 , 0 ) ;
if ( F_34 ( ! V_24 ) )
return;
F_8 ( 0 , V_24 + V_45 ) ;
F_17 ( V_42 , V_24 ) ;
V_71 = F_33 ( V_73 ,
L_4 , & V_70 ) ;
if ( F_34 ( V_71 ) )
return;
V_69 = F_35 ( V_70 ) ;
V_24 = F_36 ( V_69 , 0 ) ;
if ( F_34 ( ! V_24 ) )
return;
V_47 = F_37 ( V_69 , 0 ) ;
F_8 ( 0 , V_24 + V_45 ) ;
F_23 ( V_42 , V_24 , V_47 ) ;
}
static void T_1 F_38 ( void )
{
F_8 ( 0xffffffffU , V_5 + V_6 ) ;
F_39 ( V_74 ) ;
F_40 ( false ) ;
}
static void T_1 F_41 ( void )
{
unsigned long V_75 ;
struct V_68 * V_76 ;
struct V_68 * V_77 ;
struct V_78 * V_79 ;
struct V_80 * V_81 ;
struct V_82 * V_83 ;
T_2 V_84 ;
int V_71 ;
int V_85 ;
V_76 = F_35 ( L_5 ) ;
if ( ! V_76 )
return;
V_77 = F_35 ( L_6 ) ;
if ( ! V_77 )
return;
V_15 = F_36 ( V_77 , 0 ) ;
if ( ! V_15 )
return;
V_84 = F_6 ( V_15 ) ;
V_83 = F_42 ( sizeof( * V_83 ) , V_86 ) ;
if ( ! V_83 )
return;
V_71 = F_33 ( V_76 , L_7 ,
& V_83 -> V_87 ) ;
if ( V_71 )
return;
V_71 = F_33 ( V_76 , L_8 , & V_83 -> V_88 ) ;
if ( V_71 )
return;
V_83 -> V_89 = L_9 ;
V_83 -> V_90 = F_43 ( V_86 , L_10 ,
'A' + ( V_84 & 0x0f ) ) ;
V_81 = F_44 ( V_83 ) ;
if ( F_30 ( V_81 ) ) {
F_45 ( V_83 -> V_90 ) ;
F_45 ( V_83 ) ;
return;
}
V_79 = F_46 ( V_81 ) ;
F_47 ( V_79 , V_84 ) ;
F_48 ( V_76 , V_91 ,
V_92 , V_79 ) ;
V_75 = F_6 ( V_15 + V_93 ) ;
for ( V_85 = 0 ; V_85 < 4 ; V_85 ++ ) {
struct V_94 * V_95 ;
if ( ( V_75 & ( 16 << V_85 ) ) == 0 )
continue;
V_95 = F_42 ( sizeof( struct V_94 ) , V_86 ) ;
if ( ! V_95 )
continue;
V_95 -> V_96 . V_32 = 0xc0000000 + 0x10000000 * V_85 ;
V_95 -> V_96 . V_97 = V_95 -> V_96 . V_32 + 0x0fffffff ;
V_95 -> V_96 . V_98 = V_99 ;
V_95 -> V_47 = V_100 + V_85 ;
V_95 -> V_101 = V_85 ;
F_49 ( V_95 ) ;
}
}
static void T_1 F_50 ( void )
{
F_2 ( V_102 , F_3 ( V_102 ) ) ;
F_1 () ;
}
static void T_1 F_51 ( void )
{
struct V_72 * V_72 ;
unsigned long V_42 ;
V_72 = F_28 ( L_2 , NULL ) ;
F_29 ( F_30 ( V_72 ) ) ;
F_31 ( V_72 ) ;
V_42 = F_32 ( V_72 ) ;
F_8 ( 0 , V_103 + V_45 ) ;
F_8 ( 0 , V_104 + V_45 ) ;
F_8 ( 0 , V_36 + V_45 ) ;
F_17 ( V_42 , ( void T_3 * ) V_36 ) ;
F_23 ( V_42 , ( void T_3 * ) V_104 ,
V_105 ) ;
}
static void T_1 F_52 ( void )
{
F_8 ( - 1 , V_5 + V_6 ) ;
F_8 ( - 1 , V_3 + V_6 ) ;
F_8 ( - 1 , V_3 + V_7 ) ;
F_53 ( V_3 , L_11 , V_106 ,
- 1 , V_107 , NULL ) ;
F_40 ( false ) ;
}
static void T_1 F_54 ( void )
{
unsigned long V_75 ;
int V_85 ;
F_55 ( & V_108 ) ;
F_55 ( & V_109 ) ;
V_15 = F_56 ( V_110 ) ;
V_75 = F_6 ( V_15 + V_93 ) ;
for ( V_85 = 0 ; V_85 < 4 ; V_85 ++ ) {
struct V_94 * V_95 ;
if ( ( V_75 & ( 16 << V_85 ) ) == 0 )
continue;
V_95 = F_42 ( sizeof( struct V_94 ) , V_86 ) ;
if ( ! V_95 )
continue;
V_95 -> V_96 . V_32 = 0xc0000000 + 0x10000000 * V_85 ;
V_95 -> V_96 . V_97 = V_95 -> V_96 . V_32 + 0x0fffffff ;
V_95 -> V_96 . V_98 = V_99 ;
V_95 -> V_47 = V_100 + V_85 ;
V_95 -> V_101 = V_85 ;
F_49 ( V_95 ) ;
}
F_57 ( false ) ;
}
