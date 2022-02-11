static void F_1 ( struct V_1 * V_2 )
{
int V_3 , V_4 , V_5 , V_6 ;
F_2 ( & V_2 -> V_7 ) ;
V_6 = V_2 -> V_8 ? V_9 : 0x00 ;
F_3 ( V_6 | V_10 | V_11 , V_2 -> V_12 ) ;
F_4 ( V_13 ) ;
F_3 ( V_6 | V_14 | V_10 | V_11 , V_2 -> V_12 ) ;
F_4 ( V_15 ) ;
for ( V_3 = 0 , V_5 = V_2 -> V_16 ; V_3 < 32 ; V_3 ++ , V_5 >>= 1 ) {
V_4 = ( V_5 & 1 ) ? V_10 : 0 ;
F_3 ( V_6 | V_14 | V_4 , V_2 -> V_12 ) ;
F_4 ( V_13 ) ;
F_3 ( V_6 | V_14 | V_4 | V_11 , V_2 -> V_12 ) ;
F_4 ( V_13 ) ;
}
F_3 ( V_6 | V_10 | V_11 , V_2 -> V_12 ) ;
F_4 ( V_13 ) ;
F_3 ( V_6 | V_14 | V_10 | V_11 , V_2 -> V_12 ) ;
F_4 ( V_15 ) ;
F_5 ( & V_2 -> V_7 ) ;
}
static unsigned long F_6 ( unsigned long V_17 )
{
return ( ( V_17 << V_18 ) + V_19 + V_20 / 2 ) / V_20 ;
}
static void F_7 ( struct V_1 * V_2 , unsigned long V_17 )
{
if ( V_21 && V_22 && V_2 -> V_8 )
return;
V_17 = F_8 ( V_17 , V_23 , V_24 ) ;
V_2 -> V_25 = V_17 ;
V_2 -> V_8 = 0 ;
F_9 ( V_2 , V_26 , 0 ) ;
F_9 ( V_2 , V_27 , 0 ) ;
F_9 ( V_2 , V_28 , 0 ) ;
F_9 ( V_2 , V_29 , 0 ) ;
F_9 ( V_2 , V_30 , 1 ) ;
F_9 ( V_2 , V_31 , 0 ) ;
F_9 ( V_2 , V_32 , V_33 ) ;
F_9 ( V_2 , V_34 , F_6 ( V_17 ) ) ;
F_1 ( V_2 ) ;
}
static void F_10 ( struct V_1 * V_2 )
{
int V_3 ;
V_2 -> V_8 = 1 ;
if ( V_22 ) {
F_9 ( V_2 , V_26 , 0 ) ;
F_9 ( V_2 , V_27 , 0 ) ;
F_9 ( V_2 , V_28 , 0 ) ;
F_9 ( V_2 , V_29 , 0 ) ;
F_9 ( V_2 , V_30 , 0 ) ;
F_9 ( V_2 , V_31 , 0 ) ;
F_9 ( V_2 , V_32 , V_35 ) ;
F_9 ( V_2 , V_34 , 0 ) ;
F_1 ( V_2 ) ;
return;
}
F_2 ( & V_2 -> V_7 ) ;
V_3 = F_11 ( V_2 -> V_12 ) ;
F_3 ( ( V_3 >> 5 ) | V_9 , V_2 -> V_12 ) ;
F_4 ( V_13 ) ;
F_5 ( & V_2 -> V_7 ) ;
}
static void F_12 ( struct V_1 * V_2 )
{
int V_3 ;
V_2 -> V_8 = 0 ;
if ( V_22 ) {
F_7 ( V_2 , V_2 -> V_25 ) ;
return;
}
F_2 ( & V_2 -> V_7 ) ;
V_3 = F_11 ( V_2 -> V_12 ) ;
F_3 ( V_3 >> 5 , V_2 -> V_12 ) ;
F_4 ( V_13 ) ;
F_5 ( & V_2 -> V_7 ) ;
}
static inline int F_13 ( struct V_1 * V_2 )
{
int V_36 ;
F_2 ( & V_2 -> V_7 ) ;
V_36 = F_11 ( V_2 -> V_12 ) & V_37 ? 0 : 1 ;
F_5 ( & V_2 -> V_7 ) ;
return V_36 ;
}
static int F_14 ( struct V_1 * V_2 , int V_38 )
{
int V_3 , V_5 ;
if ( V_2 -> V_39 == V_38 )
return 1 ;
F_2 ( & V_2 -> V_7 ) ;
V_5 = F_11 ( V_38 ) ;
for ( V_3 = 0 ; V_3 < 3 ; ++ V_3 ) {
F_3 ( 1 << V_3 , V_38 ) ;
F_4 ( V_13 ) ;
if ( ( F_11 ( V_38 ) & ( ~ V_37 ) ) != ( 0x17 | ( 1 << ( V_3 + 5 ) ) ) ) {
F_5 ( & V_2 -> V_7 ) ;
return 0 ;
}
}
F_3 ( V_5 >> 5 , V_38 ) ;
F_4 ( V_13 ) ;
F_5 ( & V_2 -> V_7 ) ;
V_2 -> V_39 = V_38 ;
return 1 ;
}
static int F_15 ( struct V_1 * V_2 )
{
struct V_40 * V_41 = & V_2 -> V_41 ;
int V_42 [] = { 0x20c , 0x30c , 0x24c , 0x34c , 0x248 , 0x28c } ;
int V_3 ;
if ( ! V_43 ) {
F_16 ( V_41 , L_1 ) ;
return - 1 ;
}
F_16 ( V_41 , L_2 ) ;
for ( V_3 = 0 ; V_3 < F_17 ( V_42 ) ; ++ V_3 ) {
F_16 ( V_41 , L_3 , V_42 [ V_3 ] ) ;
if ( ! F_18 ( V_42 [ V_3 ] , 1 , L_4 ) ) {
F_19 ( V_41 , L_5 ,
V_42 [ V_3 ] ) ;
continue;
}
if ( F_14 ( V_2 , V_42 [ V_3 ] ) ) {
F_16 ( V_41 , L_6
L_7 , V_42 [ V_3 ] ) ;
F_20 ( V_42 [ V_3 ] , 1 ) ;
V_2 -> V_12 = V_42 [ V_3 ] ;
return V_2 -> V_12 ;
}
F_20 ( V_42 [ V_3 ] , 1 ) ;
}
F_21 ( V_41 , L_8 ) ;
return - 1 ;
}
static int F_22 ( struct V_44 * V_44 , void * V_45 ,
struct V_46 * V_47 )
{
F_23 ( V_47 -> V_48 , L_9 , sizeof( V_47 -> V_48 ) ) ;
F_23 ( V_47 -> V_49 , L_10 , sizeof( V_47 -> V_49 ) ) ;
F_23 ( V_47 -> V_50 , L_11 , sizeof( V_47 -> V_50 ) ) ;
V_47 -> V_51 = V_52 | V_53 ;
return 0 ;
}
static int F_24 ( struct V_44 * V_44 , void * V_45 , struct V_54 * V_47 )
{
struct V_1 * V_2 = F_25 ( V_44 ) ;
if ( V_47 -> V_55 > 0 )
return - V_56 ;
F_23 ( V_47 -> V_57 , L_12 , sizeof( V_47 -> V_57 ) ) ;
V_47 -> type = V_58 ;
V_47 -> V_59 = V_23 ;
V_47 -> V_60 = V_24 ;
V_47 -> V_61 = V_62 | V_63 ;
V_47 -> signal = 0xffff * F_13 ( V_2 ) ;
if ( V_47 -> signal ) {
V_47 -> V_64 = V_65 ;
V_47 -> V_66 = V_67 ;
} else {
V_47 -> V_64 = V_68 ;
V_47 -> V_66 = V_69 ;
}
return 0 ;
}
static int F_26 ( struct V_44 * V_44 , void * V_45 , struct V_54 * V_47 )
{
return ( V_47 -> V_55 != 0 ) ? - V_56 : 0 ;
}
static int F_27 ( struct V_44 * V_44 , void * V_45 ,
struct V_70 * V_71 )
{
struct V_1 * V_2 = F_25 ( V_44 ) ;
if ( V_71 -> V_72 != 0 )
return - V_56 ;
V_71 -> type = V_58 ;
V_71 -> V_73 = V_2 -> V_25 ;
return 0 ;
}
static int F_28 ( struct V_44 * V_44 , void * V_45 ,
struct V_70 * V_71 )
{
struct V_1 * V_2 = F_25 ( V_44 ) ;
if ( V_71 -> V_72 != 0 || V_71 -> type != V_58 )
return - V_56 ;
F_7 ( V_2 , V_71 -> V_73 ) ;
return 0 ;
}
static int F_29 ( struct V_44 * V_44 , void * V_45 ,
struct V_74 * V_75 )
{
switch ( V_75 -> V_76 ) {
case V_77 :
return F_30 ( V_75 , 0 , 1 , 1 , 0 ) ;
default:
return - V_56 ;
}
}
static int F_31 ( struct V_44 * V_44 , void * V_45 ,
struct V_78 * V_79 )
{
struct V_1 * V_2 = F_25 ( V_44 ) ;
switch ( V_79 -> V_76 ) {
case V_77 :
V_79 -> V_80 = V_2 -> V_8 ;
return 0 ;
}
return - V_56 ;
}
static int F_32 ( struct V_44 * V_44 , void * V_45 ,
struct V_78 * V_79 )
{
struct V_1 * V_2 = F_25 ( V_44 ) ;
switch ( V_79 -> V_76 ) {
case V_77 :
if ( V_79 -> V_80 )
F_10 ( V_2 ) ;
else
F_12 ( V_2 ) ;
return 0 ;
}
return - V_56 ;
}
static int F_33 ( struct V_44 * V_81 , void * V_45 , unsigned int * V_3 )
{
* V_3 = 0 ;
return 0 ;
}
static int F_34 ( struct V_44 * V_81 , void * V_45 , unsigned int V_3 )
{
return ( V_3 != 0 ) ? - V_56 : 0 ;
}
static int F_35 ( struct V_44 * V_44 , void * V_45 , struct V_82 * V_83 )
{
V_83 -> V_55 = 0 ;
F_23 ( V_83 -> V_57 , L_13 , sizeof( V_83 -> V_57 ) ) ;
V_83 -> V_61 = V_84 ;
return 0 ;
}
static int F_36 ( struct V_44 * V_44 , void * V_45 , struct V_82 * V_83 )
{
return ( V_83 -> V_55 != 0 ) ? - V_56 : 0 ;
}
static int T_1 F_37 ( void )
{
struct V_1 * V_2 = & V_85 ;
struct V_40 * V_41 = & V_2 -> V_41 ;
int V_86 ;
F_23 ( V_41 -> V_57 , L_14 , sizeof( V_41 -> V_57 ) ) ;
F_16 ( V_41 , L_15 ) ;
F_38 ( & V_2 -> V_7 ) ;
V_2 -> V_39 = - 1 ;
V_2 -> V_12 = V_12 ;
F_15 ( V_2 ) ;
if ( V_2 -> V_12 ) {
if ( ! F_18 ( V_2 -> V_12 , 1 , L_14 ) ) {
F_21 ( V_41 , L_16 , V_2 -> V_12 ) ;
return - V_87 ;
}
if ( ! F_14 ( V_2 , V_2 -> V_12 ) )
F_19 ( V_41 , L_17
L_18
L_19 , V_2 -> V_12 ) ;
else
F_16 ( V_41 , L_20 , V_2 -> V_12 ) ;
} else if ( V_43 ) {
F_21 ( V_41 , L_21
L_22 ) ;
return - V_88 ;
} else {
F_21 ( V_41 , L_23
L_24 ) ;
return - V_56 ;
}
V_86 = F_39 ( NULL , V_41 ) ;
if ( V_86 < 0 ) {
F_21 ( V_41 , L_25 ) ;
F_20 ( V_2 -> V_12 , 1 ) ;
return V_86 ;
}
F_23 ( V_2 -> V_89 . V_57 , V_41 -> V_57 , sizeof( V_2 -> V_89 . V_57 ) ) ;
V_2 -> V_89 . V_41 = V_41 ;
V_2 -> V_89 . V_90 = & V_91 ;
V_2 -> V_89 . V_92 = & V_93 ;
V_2 -> V_89 . V_94 = V_95 ;
F_40 ( & V_2 -> V_89 , V_2 ) ;
V_2 -> V_25 = V_23 ;
V_2 -> V_16 = 0 ;
if ( V_96 )
F_10 ( V_2 ) ;
if ( F_41 ( & V_2 -> V_89 , V_97 , V_98 ) < 0 ) {
F_42 ( V_41 ) ;
F_20 ( V_2 -> V_12 , 1 ) ;
return - V_87 ;
}
return 0 ;
}
static void T_2 F_43 ( void )
{
struct V_1 * V_2 = & V_85 ;
struct V_40 * V_41 = & V_2 -> V_41 ;
if ( V_99 ) {
V_22 = 1 ;
F_10 ( V_2 ) ;
} else {
F_16 ( V_41 , L_26 ) ;
}
F_44 ( & V_2 -> V_89 ) ;
F_42 ( & V_2 -> V_41 ) ;
F_20 ( V_2 -> V_12 , 1 ) ;
}
