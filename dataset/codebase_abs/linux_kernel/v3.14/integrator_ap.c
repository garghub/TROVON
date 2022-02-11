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
V_11 = F_6 ( V_16 + V_17 ) |
V_18 ;
F_9 ( V_11 , V_16 + V_17 ) ;
if ( ! ( F_6 ( V_16 + V_17 )
& V_18 ) ) {
F_9 ( 0xa05f , V_16 + V_19 ) ;
F_9 ( V_11 , V_16 + V_17 ) ;
F_9 ( 0 , V_16 + V_19 ) ;
}
return 0 ;
}
static void F_13 ( struct V_9 * V_10 )
{
T_2 V_11 ;
F_9 ( V_12 | V_13 ,
V_14 + V_15 ) ;
V_11 = F_6 ( V_16 + V_17 ) &
~ V_18 ;
F_9 ( V_11 , V_16 + V_17 ) ;
if ( F_6 ( V_16 + V_17 ) &
V_18 ) {
F_9 ( 0xa05f , V_16 + V_19 ) ;
F_9 ( V_11 , V_16 + V_17 ) ;
F_9 ( 0 , V_16 + V_19 ) ;
}
}
static void F_14 ( struct V_9 * V_20 , int V_21 )
{
if ( V_21 )
F_9 ( V_12 ,
V_14 + V_22 ) ;
else
F_9 ( V_12 ,
V_14 + V_15 ) ;
}
static void F_15 ( struct V_23 * V_10 ,
void T_3 * V_24 , unsigned int V_25 )
{
unsigned int V_26 = 0 , V_27 = 0 , V_28 , V_29 ;
T_2 V_30 = V_10 -> V_31 . V_32 ;
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
F_16 ( V_26 , V_14 + V_22 ) ;
F_16 ( V_27 , V_14 + V_15 ) ;
}
static T_4 T_5 F_17 ( void )
{
return - F_6 ( ( void T_3 * ) V_36 + V_37 ) ;
}
static void F_18 ( unsigned long V_38 ,
void T_3 * V_24 )
{
T_2 V_39 = V_40 | V_41 ;
unsigned long V_42 = V_38 ;
if ( V_42 >= 1500000 ) {
V_42 /= 16 ;
V_39 |= V_43 ;
}
F_9 ( 0xffff , V_24 + V_44 ) ;
F_9 ( V_39 , V_24 + V_45 ) ;
F_19 ( V_24 + V_37 , L_1 ,
V_42 , 200 , 16 , V_46 ) ;
F_20 ( F_17 , 16 , V_42 ) ;
}
static T_6 F_21 ( int V_47 , void * V_48 )
{
struct V_49 * V_50 = V_48 ;
F_9 ( 1 , V_51 + V_52 ) ;
V_50 -> V_53 ( V_50 ) ;
return V_54 ;
}
static void F_22 ( enum V_55 V_56 , struct V_49 * V_50 )
{
T_2 V_39 = F_6 ( V_51 + V_45 ) & ~ V_40 ;
F_9 ( V_39 , V_51 + V_45 ) ;
switch ( V_56 ) {
case V_57 :
F_9 ( V_58 , V_51 + V_44 ) ;
V_39 |= V_41 | V_40 ;
F_9 ( V_39 , V_51 + V_45 ) ;
break;
case V_59 :
V_39 &= ~ V_41 ;
F_9 ( V_39 , V_51 + V_45 ) ;
break;
case V_60 :
case V_61 :
case V_62 :
default:
break;
}
}
static int F_23 ( unsigned long V_63 , struct V_49 * V_50 )
{
unsigned long V_39 = F_6 ( V_51 + V_45 ) ;
F_9 ( V_39 & ~ V_40 , V_51 + V_45 ) ;
F_9 ( V_63 , V_51 + V_44 ) ;
F_9 ( V_39 | V_40 , V_51 + V_45 ) ;
return 0 ;
}
static void F_24 ( unsigned long V_38 ,
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
F_9 ( V_39 , V_51 + V_45 ) ;
F_25 ( V_47 , & V_66 ) ;
F_26 ( & V_67 ,
V_42 ,
1 ,
0xffffU ) ;
}
void T_1 F_27 ( void )
{
}
static void T_1 F_28 ( void )
{
struct V_68 * V_69 ;
const char * V_70 ;
void T_3 * V_24 ;
int V_71 ;
int V_47 ;
struct V_72 * V_72 ;
unsigned long V_42 ;
V_72 = F_29 ( L_2 , NULL ) ;
F_30 ( F_31 ( V_72 ) ) ;
F_32 ( V_72 ) ;
V_42 = F_33 ( V_72 ) ;
V_71 = F_34 ( V_73 ,
L_3 , & V_70 ) ;
if ( F_35 ( V_71 ) )
return;
V_69 = F_36 ( V_70 ) ;
V_24 = F_37 ( V_69 , 0 ) ;
if ( F_35 ( ! V_24 ) )
return;
F_9 ( 0 , V_24 + V_45 ) ;
F_18 ( V_42 , V_24 ) ;
V_71 = F_34 ( V_73 ,
L_4 , & V_70 ) ;
if ( F_35 ( V_71 ) )
return;
V_69 = F_36 ( V_70 ) ;
V_24 = F_37 ( V_69 , 0 ) ;
if ( F_35 ( ! V_24 ) )
return;
V_47 = F_38 ( V_69 , 0 ) ;
F_9 ( 0 , V_24 + V_45 ) ;
F_24 ( V_42 , V_24 , V_47 ) ;
}
static void T_1 F_39 ( void )
{
F_40 () ;
F_41 ( V_74 ) ;
F_42 ( false ) ;
}
static void T_1 F_43 ( void )
{
unsigned long V_75 ;
struct V_68 * V_76 ;
struct V_68 * V_77 ;
struct V_68 * V_78 ;
struct V_79 * V_80 ;
struct V_81 * V_82 ;
struct V_83 * V_84 ;
T_2 V_85 ;
int V_71 ;
int V_86 ;
V_76 = F_36 ( L_5 ) ;
if ( ! V_76 )
return;
V_77 = F_44 ( V_76 , V_87 ) ;
if ( ! V_77 )
return;
V_78 = F_44 ( V_76 , V_88 ) ;
if ( ! V_78 )
return;
V_14 = F_37 ( V_77 , 0 ) ;
if ( ! V_14 )
return;
V_16 = F_37 ( V_78 , 0 ) ;
if ( ! V_16 )
return;
V_85 = F_6 ( V_14 ) ;
V_84 = F_45 ( sizeof( * V_84 ) , V_89 ) ;
if ( ! V_84 )
return;
V_71 = F_34 ( V_76 , L_6 ,
& V_84 -> V_90 ) ;
if ( V_71 )
return;
V_71 = F_34 ( V_76 , L_7 , & V_84 -> V_91 ) ;
if ( V_71 )
return;
V_84 -> V_92 = L_8 ;
V_84 -> V_93 = F_46 ( V_89 , L_9 ,
'A' + ( V_85 & 0x0f ) ) ;
V_82 = F_47 ( V_84 ) ;
if ( F_31 ( V_82 ) ) {
F_48 ( V_84 -> V_93 ) ;
F_48 ( V_84 ) ;
return;
}
V_80 = F_49 ( V_82 ) ;
F_50 ( V_80 , V_85 ) ;
F_51 ( V_76 , V_94 ,
V_95 , V_80 ) ;
V_75 = F_6 ( V_14 + V_96 ) ;
for ( V_86 = 0 ; V_86 < 4 ; V_86 ++ ) {
struct V_97 * V_98 ;
if ( ( V_75 & ( 16 << V_86 ) ) == 0 )
continue;
V_98 = F_45 ( sizeof( struct V_97 ) , V_89 ) ;
if ( ! V_98 )
continue;
V_98 -> V_99 . V_32 = 0xc0000000 + 0x10000000 * V_86 ;
V_98 -> V_99 . V_100 = V_98 -> V_99 . V_32 + 0x0fffffff ;
V_98 -> V_99 . V_101 = V_102 ;
V_98 -> V_47 = F_38 ( V_77 , V_86 ) ;
V_98 -> V_103 = V_86 ;
F_52 ( V_98 ) ;
}
}
