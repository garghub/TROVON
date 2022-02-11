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
F_8 () ;
F_9 ( - 1 , V_3 + V_5 ) ;
F_9 ( - 1 , V_3 + V_6 ) ;
F_9 ( V_2 , V_3 + V_7 ) ;
}
static int T_1 F_10 ( void )
{
F_11 ( & V_8 ) ;
return 0 ;
}
static int F_12 ( struct V_9 * V_10 )
{
T_2 V_11 ;
F_9 ( V_12 | V_13 ,
V_14 + V_15 ) ;
V_11 = F_6 ( V_16 ) | V_17 ;
F_9 ( V_11 , V_16 ) ;
if ( ! ( F_6 ( V_16 ) & V_17 ) ) {
F_9 ( 0xa05f , V_18 ) ;
F_9 ( V_11 , V_16 ) ;
F_9 ( 0 , V_18 ) ;
}
return 0 ;
}
static void F_13 ( struct V_9 * V_10 )
{
T_2 V_11 ;
F_9 ( V_12 | V_13 ,
V_14 + V_15 ) ;
V_11 = F_6 ( V_16 ) & ~ V_17 ;
F_9 ( V_11 , V_16 ) ;
if ( F_6 ( V_16 ) & V_17 ) {
F_9 ( 0xa05f , V_18 ) ;
F_9 ( V_11 , V_16 ) ;
F_9 ( 0 , V_18 ) ;
}
}
static void F_14 ( struct V_9 * V_19 , int V_20 )
{
if ( V_20 )
F_9 ( V_12 ,
V_14 + V_21 ) ;
else
F_9 ( V_12 ,
V_14 + V_15 ) ;
}
static void F_15 ( struct V_22 * V_10 ,
void T_3 * V_23 , unsigned int V_24 )
{
unsigned int V_25 = 0 , V_26 = 0 , V_27 , V_28 ;
T_2 V_29 = V_10 -> V_30 . V_31 ;
if ( V_29 == V_32 ) {
V_27 = 1 << 4 ;
V_28 = 1 << 5 ;
} else {
V_27 = 1 << 6 ;
V_28 = 1 << 7 ;
}
if ( V_24 & V_33 )
V_26 |= V_27 ;
else
V_25 |= V_27 ;
if ( V_24 & V_34 )
V_26 |= V_28 ;
else
V_25 |= V_28 ;
F_16 ( V_25 , V_14 + V_21 ) ;
F_16 ( V_26 , V_14 + V_15 ) ;
}
static T_2 T_4 F_17 ( void )
{
return - F_6 ( ( void T_3 * ) V_35 + V_36 ) ;
}
static void F_18 ( unsigned long V_37 ,
void T_3 * V_23 )
{
T_2 V_38 = V_39 | V_40 ;
unsigned long V_41 = V_37 ;
if ( V_41 >= 1500000 ) {
V_41 /= 16 ;
V_38 |= V_42 ;
}
F_9 ( 0xffff , V_23 + V_43 ) ;
F_9 ( V_38 , V_23 + V_44 ) ;
F_19 ( V_23 + V_36 , L_1 ,
V_41 , 200 , 16 , V_45 ) ;
F_20 ( F_17 , 16 , V_41 ) ;
}
static T_5 F_21 ( int V_46 , void * V_47 )
{
struct V_48 * V_49 = V_47 ;
F_9 ( 1 , V_50 + V_51 ) ;
V_49 -> V_52 ( V_49 ) ;
return V_53 ;
}
static void F_22 ( enum V_54 V_55 , struct V_48 * V_49 )
{
T_2 V_38 = F_6 ( V_50 + V_44 ) & ~ V_39 ;
F_9 ( V_38 , V_50 + V_44 ) ;
switch ( V_55 ) {
case V_56 :
F_9 ( V_57 , V_50 + V_43 ) ;
V_38 |= V_40 | V_39 ;
F_9 ( V_38 , V_50 + V_44 ) ;
break;
case V_58 :
V_38 &= ~ V_40 ;
F_9 ( V_38 , V_50 + V_44 ) ;
break;
case V_59 :
case V_60 :
case V_61 :
default:
break;
}
}
static int F_23 ( unsigned long V_62 , struct V_48 * V_49 )
{
unsigned long V_38 = F_6 ( V_50 + V_44 ) ;
F_9 ( V_38 & ~ V_39 , V_50 + V_44 ) ;
F_9 ( V_62 , V_50 + V_43 ) ;
F_9 ( V_38 | V_39 , V_50 + V_44 ) ;
return 0 ;
}
static void F_24 ( unsigned long V_37 ,
void T_3 * V_23 , int V_46 )
{
unsigned long V_41 = V_37 ;
unsigned int V_38 = 0 ;
V_50 = V_23 ;
if ( V_41 > 0x100000 * V_63 ) {
V_41 /= 256 ;
V_38 |= V_64 ;
} else if ( V_41 > 0x10000 * V_63 ) {
V_41 /= 16 ;
V_38 |= V_42 ;
}
V_57 = V_41 / V_63 ;
F_9 ( V_38 , V_50 + V_44 ) ;
F_25 ( V_46 , & V_65 ) ;
F_26 ( & V_66 ,
V_41 ,
1 ,
0xffffU ) ;
}
void T_1 F_27 ( void )
{
}
static void T_1 F_28 ( void )
{
struct V_67 * V_68 ;
const char * V_69 ;
void T_3 * V_23 ;
int V_70 ;
int V_46 ;
struct V_71 * V_71 ;
unsigned long V_41 ;
V_71 = F_29 ( L_2 , NULL ) ;
F_30 ( F_31 ( V_71 ) ) ;
F_32 ( V_71 ) ;
V_41 = F_33 ( V_71 ) ;
V_70 = F_34 ( V_72 ,
L_3 , & V_69 ) ;
if ( F_35 ( V_70 ) )
return;
V_68 = F_36 ( V_69 ) ;
V_23 = F_37 ( V_68 , 0 ) ;
if ( F_35 ( ! V_23 ) )
return;
F_9 ( 0 , V_23 + V_44 ) ;
F_18 ( V_41 , V_23 ) ;
V_70 = F_34 ( V_72 ,
L_4 , & V_69 ) ;
if ( F_35 ( V_70 ) )
return;
V_68 = F_36 ( V_69 ) ;
V_23 = F_37 ( V_68 , 0 ) ;
if ( F_35 ( ! V_23 ) )
return;
V_46 = F_38 ( V_68 , 0 ) ;
F_9 ( 0 , V_23 + V_44 ) ;
F_24 ( V_41 , V_23 , V_46 ) ;
}
static void T_1 F_39 ( void )
{
F_40 () ;
F_41 ( V_73 ) ;
F_42 ( false ) ;
}
static void T_1 F_43 ( void )
{
unsigned long V_74 ;
struct V_67 * V_75 ;
struct V_67 * V_76 ;
struct V_77 * V_78 ;
struct V_79 * V_80 ;
struct V_81 * V_82 ;
T_2 V_83 ;
int V_70 ;
int V_84 ;
V_75 = F_36 ( L_5 ) ;
if ( ! V_75 )
return;
V_76 = F_44 ( V_75 , V_85 ) ;
if ( ! V_76 )
return;
V_14 = F_37 ( V_76 , 0 ) ;
if ( ! V_14 )
return;
V_83 = F_6 ( V_14 ) ;
V_82 = F_45 ( sizeof( * V_82 ) , V_86 ) ;
if ( ! V_82 )
return;
V_70 = F_34 ( V_75 , L_6 ,
& V_82 -> V_87 ) ;
if ( V_70 )
return;
V_70 = F_34 ( V_75 , L_7 , & V_82 -> V_88 ) ;
if ( V_70 )
return;
V_82 -> V_89 = L_8 ;
V_82 -> V_90 = F_46 ( V_86 , L_9 ,
'A' + ( V_83 & 0x0f ) ) ;
V_80 = F_47 ( V_82 ) ;
if ( F_31 ( V_80 ) ) {
F_48 ( V_82 -> V_90 ) ;
F_48 ( V_82 ) ;
return;
}
V_78 = F_49 ( V_80 ) ;
F_50 ( V_78 , V_83 ) ;
F_51 ( V_75 , V_91 ,
V_92 , V_78 ) ;
V_74 = F_6 ( V_14 + V_93 ) ;
for ( V_84 = 0 ; V_84 < 4 ; V_84 ++ ) {
struct V_94 * V_95 ;
if ( ( V_74 & ( 16 << V_84 ) ) == 0 )
continue;
V_95 = F_45 ( sizeof( struct V_94 ) , V_86 ) ;
if ( ! V_95 )
continue;
V_95 -> V_96 . V_31 = 0xc0000000 + 0x10000000 * V_84 ;
V_95 -> V_96 . V_97 = V_95 -> V_96 . V_31 + 0x0fffffff ;
V_95 -> V_96 . V_98 = V_99 ;
V_95 -> V_46 = F_38 ( V_76 , V_84 ) ;
V_95 -> V_100 = V_84 ;
F_52 ( V_95 ) ;
}
}
