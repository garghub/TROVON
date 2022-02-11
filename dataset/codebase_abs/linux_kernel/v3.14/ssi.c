static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_9 * V_10 ;
struct V_11 * V_12 = F_3 ( V_6 ) ;
int V_13 = F_4 ( & V_6 -> V_14 ) ;
T_1 V_15 ;
T_1 V_16 ;
V_10 = F_5 ( V_2 , F_4 ( & V_6 -> V_14 ) ) ;
if ( F_6 ( V_10 ) ) {
V_12 -> V_17 &= ~ ( 1 << V_13 ) ;
F_7 ( V_8 , L_1 , V_13 ) ;
} else {
V_12 -> V_17 |= ( 1 << V_13 ) ;
F_7 ( V_8 , L_2 , V_13 ) ;
}
#define F_8 ( T_2 , T_3 , T_4 , T_5 ) \
do { \
ssi->parent = ssiu->ssi + p; \
if (rsnd_rdai_is_clk_master(rdai)) \
val = adg; \
else \
val = ext; \
if (flags & RSND_SSI_SYNC) \
val |= sync; \
} while (0)
V_15 = F_9 ( V_6 ) ;
if ( V_15 & V_18 ) {
V_16 = 0 ;
switch ( V_13 ) {
case 1 :
F_8 ( 0 , ( 1 << 4 ) , ( 0x2 << 0 ) , ( 0x1 << 0 ) ) ;
break;
case 2 :
F_8 ( 0 , ( 1 << 4 ) , ( 0x2 << 2 ) , ( 0x1 << 2 ) ) ;
break;
case 4 :
F_8 ( 3 , ( 1 << 20 ) , ( 0x2 << 16 ) , ( 0x1 << 16 ) ) ;
break;
case 8 :
F_8 ( 7 , 0 , 0 , 0 ) ;
break;
}
V_12 -> V_19 |= V_16 ;
}
F_10 ( & V_6 -> V_14 , V_20 , V_12 -> V_17 ) ;
F_10 ( & V_6 -> V_14 , V_21 , V_12 -> V_19 ) ;
}
static void F_11 ( struct V_9 * V_14 ,
T_1 V_22 )
{
struct V_1 * V_2 = F_12 ( V_14 ) ;
struct V_7 * V_8 = F_2 ( V_2 ) ;
T_1 V_23 ;
int V_24 ;
for ( V_24 = 0 ; V_24 < 1024 ; V_24 ++ ) {
V_23 = F_13 ( V_14 , V_25 ) ;
if ( V_23 & V_22 )
return;
F_14 ( 50 ) ;
}
F_15 ( V_8 , L_3 ) ;
}
static int F_16 ( struct V_5 * V_6 ,
struct V_26 * V_27 )
{
struct V_1 * V_2 = F_12 ( & V_6 -> V_14 ) ;
struct V_28 * V_29 = F_17 ( V_27 ) ;
struct V_7 * V_8 = F_2 ( V_2 ) ;
int V_24 , V_30 , V_31 ;
int V_32 [] = {
1 , 6 ,
} ;
int V_33 [] = {
1 , 2 , 4 , 8 , 16 , 6 , 12 ,
} ;
unsigned int V_34 ;
unsigned int V_35 = F_18 ( V_2 , & V_6 -> V_14 , V_29 ) ;
for ( V_24 = 0 ; V_24 < F_19 ( V_32 ) ; V_24 ++ ) {
for ( V_30 = 0 ; V_30 < F_19 ( V_33 ) ; V_30 ++ ) {
V_34 = V_35 / V_32 [ V_24 ]
* 32 * 2 * V_33 [ V_30 ] ;
V_31 = F_20 ( & V_6 -> V_14 , V_34 ) ;
if ( 0 == V_31 ) {
V_6 -> V_35 = V_35 ;
V_6 -> V_36 = V_37 | V_38 |
V_39 | V_40 | F_21 ( V_30 ) ;
F_7 ( V_8 , L_4 ,
F_4 ( & V_6 -> V_14 ) , V_35 ) ;
return 0 ;
}
}
}
F_22 ( V_8 , L_5 ) ;
return - V_41 ;
}
static void F_23 ( struct V_5 * V_6 )
{
V_6 -> V_35 = 0 ;
V_6 -> V_36 = 0 ;
F_24 ( & V_6 -> V_14 ) ;
}
static void F_25 ( struct V_5 * V_6 ,
struct V_3 * V_4 ,
struct V_26 * V_27 )
{
struct V_1 * V_2 = F_12 ( & V_6 -> V_14 ) ;
struct V_7 * V_8 = F_2 ( V_2 ) ;
T_1 V_42 ;
if ( 0 == V_6 -> V_43 ) {
F_26 ( V_6 -> V_44 ) ;
if ( F_27 ( V_4 ) ) {
if ( F_28 ( V_6 ) )
F_25 ( V_6 -> V_45 , V_4 , V_27 ) ;
else
F_16 ( V_6 , V_27 ) ;
}
}
V_42 = V_6 -> V_46 |
V_6 -> V_36 |
V_6 -> V_47 |
V_48 ;
F_10 ( & V_6 -> V_14 , V_49 , V_42 ) ;
V_6 -> V_43 ++ ;
F_7 ( V_8 , L_6 , F_4 ( & V_6 -> V_14 ) ) ;
}
static void F_29 ( struct V_5 * V_6 ,
struct V_3 * V_4 )
{
struct V_1 * V_2 = F_12 ( & V_6 -> V_14 ) ;
struct V_7 * V_8 = F_2 ( V_2 ) ;
T_1 V_42 ;
if ( 0 == V_6 -> V_43 )
return;
V_6 -> V_43 -- ;
if ( 0 == V_6 -> V_43 ) {
V_42 = V_6 -> V_46 |
V_6 -> V_36 ;
F_10 ( & V_6 -> V_14 , V_49 , V_42 | V_48 ) ;
F_11 ( & V_6 -> V_14 , V_50 ) ;
F_10 ( & V_6 -> V_14 , V_49 , V_42 ) ;
F_11 ( & V_6 -> V_14 , V_51 ) ;
if ( F_27 ( V_4 ) ) {
if ( F_28 ( V_6 ) )
F_29 ( V_6 -> V_45 , V_4 ) ;
else
F_23 ( V_6 ) ;
}
F_30 ( V_6 -> V_44 ) ;
}
F_7 ( V_8 , L_7 , F_4 ( & V_6 -> V_14 ) ) ;
}
static int F_31 ( struct V_9 * V_14 ,
struct V_3 * V_4 ,
struct V_26 * V_27 )
{
struct V_5 * V_6 = F_32 ( V_14 ) ;
struct V_1 * V_2 = F_12 ( V_14 ) ;
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_28 * V_29 = F_17 ( V_27 ) ;
T_1 V_42 ;
V_42 = V_37 ;
V_42 |= V_38 ;
switch ( V_29 -> V_52 ) {
case 16 :
V_42 |= V_53 ;
break;
case 32 :
V_42 |= V_54 ;
break;
default:
return - V_41 ;
}
if ( V_4 -> V_55 )
V_42 |= V_56 ;
if ( V_4 -> V_57 )
V_42 |= V_58 ;
if ( V_4 -> V_59 )
V_42 |= V_60 ;
if ( V_4 -> V_61 )
V_42 |= V_62 ;
if ( F_33 ( V_4 , V_27 ) )
V_42 |= V_63 ;
V_6 -> V_4 = V_4 ;
V_6 -> V_27 = V_27 ;
V_6 -> V_46 = V_42 ;
V_6 -> V_64 = - 1 ;
F_1 ( V_2 , V_4 , V_6 ) ;
F_7 ( V_8 , L_8 , F_34 ( V_14 ) , F_4 ( V_14 ) ) ;
return 0 ;
}
static int F_35 ( struct V_9 * V_14 ,
struct V_3 * V_4 ,
struct V_26 * V_27 )
{
struct V_5 * V_6 = F_32 ( V_14 ) ;
struct V_1 * V_2 = F_12 ( V_14 ) ;
struct V_7 * V_8 = F_2 ( V_2 ) ;
F_7 ( V_8 , L_9 , F_34 ( V_14 ) , F_4 ( V_14 ) ) ;
if ( V_6 -> V_64 > 0 )
F_15 ( V_8 , L_10 , V_6 -> V_64 ) ;
V_6 -> V_4 = NULL ;
V_6 -> V_27 = NULL ;
V_6 -> V_46 = 0 ;
V_6 -> V_64 = 0 ;
return 0 ;
}
static void F_36 ( struct V_5 * V_6 , T_1 V_23 )
{
if ( V_23 & ( V_65 | V_66 ) ) {
V_6 -> V_64 ++ ;
F_10 ( & V_6 -> V_14 , V_25 , 0 ) ;
}
}
static T_6 F_37 ( int V_67 , void * V_68 )
{
struct V_5 * V_6 = V_68 ;
struct V_26 * V_27 = V_6 -> V_27 ;
T_1 V_23 = F_13 ( & V_6 -> V_14 , V_25 ) ;
T_6 V_31 = V_69 ;
if ( V_27 && ( V_23 & V_50 ) ) {
struct V_3 * V_4 = V_6 -> V_4 ;
struct V_28 * V_29 = F_17 ( V_27 ) ;
T_1 * V_70 = ( T_1 * ) ( V_29 -> V_71 +
F_38 ( V_27 , 0 ) ) ;
F_36 ( V_6 , V_23 ) ;
if ( F_33 ( V_4 , V_27 ) )
F_10 ( & V_6 -> V_14 , V_72 , * V_70 ) ;
else
* V_70 = F_13 ( & V_6 -> V_14 , V_73 ) ;
F_39 ( V_27 , sizeof( * V_70 ) ) ;
V_31 = V_74 ;
}
return V_31 ;
}
static int F_40 ( struct V_9 * V_14 ,
struct V_3 * V_4 ,
struct V_26 * V_27 )
{
struct V_1 * V_2 = F_12 ( V_14 ) ;
struct V_5 * V_6 = F_32 ( V_14 ) ;
struct V_7 * V_8 = F_2 ( V_2 ) ;
V_6 -> V_47 = V_75 | V_76 | V_77 ;
if ( F_41 ( V_2 ) )
F_10 ( & V_6 -> V_14 , V_78 , 0x0f000000 ) ;
F_25 ( V_6 , V_4 , V_27 ) ;
F_7 ( V_8 , L_11 , F_34 ( V_14 ) , F_4 ( V_14 ) ) ;
return 0 ;
}
static int F_42 ( struct V_9 * V_14 ,
struct V_3 * V_4 ,
struct V_26 * V_27 )
{
struct V_1 * V_2 = F_12 ( V_14 ) ;
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_32 ( V_14 ) ;
F_7 ( V_8 , L_12 , F_34 ( V_14 ) , F_4 ( V_14 ) ) ;
V_6 -> V_47 = 0 ;
F_29 ( V_6 , V_4 ) ;
return 0 ;
}
static int F_43 ( struct V_79 * V_80 , T_7 * V_70 , int * V_81 )
{
struct V_5 * V_6 = F_44 ( V_80 ) ;
struct V_26 * V_27 = V_6 -> V_27 ;
struct V_28 * V_29 = F_17 ( V_27 ) ;
* V_81 = V_27 -> V_82 ;
* V_70 = V_29 -> V_83 +
F_38 ( V_27 , V_6 -> V_84 + * V_81 ) ;
V_6 -> V_84 = * V_81 ;
return 0 ;
}
static int F_45 ( struct V_79 * V_80 )
{
struct V_5 * V_6 = F_44 ( V_80 ) ;
struct V_26 * V_27 = V_6 -> V_27 ;
T_1 V_23 = F_13 ( & V_6 -> V_14 , V_25 ) ;
F_36 ( V_6 , V_23 ) ;
F_39 ( V_6 -> V_27 , V_27 -> V_82 ) ;
return 0 ;
}
static int F_46 ( struct V_9 * V_14 ,
struct V_3 * V_4 ,
struct V_26 * V_27 )
{
struct V_5 * V_6 = F_32 ( V_14 ) ;
struct V_79 * V_80 = F_47 ( & V_6 -> V_14 ) ;
V_6 -> V_47 = V_85 ;
V_6 -> V_84 = 0 ;
F_48 ( V_80 ) ;
F_25 ( V_6 , V_6 -> V_4 , V_27 ) ;
if ( F_27 ( V_4 ) )
F_10 ( & V_6 -> V_14 , V_86 , V_87 ) ;
return 0 ;
}
static int F_49 ( struct V_9 * V_14 ,
struct V_3 * V_4 ,
struct V_26 * V_27 )
{
struct V_5 * V_6 = F_32 ( V_14 ) ;
struct V_79 * V_80 = F_47 ( & V_6 -> V_14 ) ;
V_6 -> V_47 = 0 ;
F_29 ( V_6 , V_4 ) ;
F_50 ( V_80 ) ;
return 0 ;
}
static int F_51 ( struct V_9 * V_14 ,
struct V_3 * V_4 ,
struct V_26 * V_27 )
{
struct V_1 * V_2 = F_12 ( V_14 ) ;
struct V_7 * V_8 = F_2 ( V_2 ) ;
F_7 ( V_8 , L_13 , V_88 ) ;
return 0 ;
}
struct V_9 * F_52 ( struct V_1 * V_2 ,
int V_89 , int V_90 )
{
struct V_5 * V_6 ;
int V_24 , V_91 ;
V_90 = ! ! V_90 ;
F_53 (ssi, priv, i) {
if ( F_54 ( V_6 ) != V_89 )
continue;
V_91 = ! ! ( F_9 ( V_6 ) & V_92 ) ;
if ( V_90 == V_91 )
return & V_6 -> V_14 ;
}
return NULL ;
}
struct V_9 * F_55 ( struct V_1 * V_2 , int V_13 )
{
if ( F_56 ( V_13 < 0 || V_13 >= F_57 ( V_2 ) ) )
V_13 = 0 ;
return & ( ( (struct V_11 * ) ( V_2 -> V_12 ) ) -> V_6 + V_13 ) -> V_14 ;
}
int F_58 ( struct V_93 * V_94 ,
struct V_95 * V_96 ,
struct V_1 * V_2 )
{
struct V_97 * V_98 ;
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_99 * V_100 ;
struct V_44 * V_44 ;
struct V_11 * V_12 ;
struct V_5 * V_6 ;
char V_101 [ V_102 ] ;
int V_24 , V_103 , V_31 ;
V_103 = V_96 -> V_104 ;
V_12 = F_59 ( V_8 , sizeof( * V_12 ) + ( sizeof( * V_6 ) * V_103 ) ,
V_105 ) ;
if ( ! V_12 ) {
F_22 ( V_8 , L_14 ) ;
return - V_106 ;
}
V_2 -> V_12 = V_12 ;
V_12 -> V_6 = (struct V_5 * ) ( V_12 + 1 ) ;
V_12 -> V_107 = V_103 ;
F_53 (ssi, priv, i) {
V_98 = & V_96 -> V_108 [ V_24 ] ;
snprintf ( V_101 , V_102 , L_15 , V_24 ) ;
V_44 = F_60 ( V_8 , V_101 ) ;
if ( F_61 ( V_44 ) )
return F_62 ( V_44 ) ;
V_6 -> V_96 = V_98 ;
V_6 -> V_44 = V_44 ;
V_100 = & V_109 ;
if ( V_98 -> V_110 > 0 ) {
V_31 = F_63 (
V_2 , F_47 ( & V_6 -> V_14 ) ,
( F_9 ( V_6 ) & V_92 ) ,
V_98 -> V_110 ,
F_43 ,
F_45 ) ;
if ( V_31 < 0 )
F_64 ( V_8 , L_16 ) ;
else
V_100 = & V_111 ;
F_7 ( V_8 , L_17 , V_24 ) ;
}
if ( ! F_65 ( V_6 ) &&
F_66 ( V_6 ) ) {
V_31 = F_67 ( V_8 , V_98 -> V_112 ,
& F_37 ,
V_113 ,
F_68 ( V_8 ) , V_6 ) ;
if ( V_31 ) {
F_22 ( V_8 , L_18 ) ;
return V_31 ;
}
V_100 = & V_114 ;
F_7 ( V_8 , L_19 , V_24 ) ;
}
F_69 ( V_2 , & V_6 -> V_14 , V_100 , V_24 ) ;
}
F_7 ( V_8 , L_20 ) ;
return 0 ;
}
void F_70 ( struct V_93 * V_94 ,
struct V_1 * V_2 )
{
struct V_5 * V_6 ;
int V_24 ;
F_53 (ssi, priv, i) {
if ( F_65 ( V_6 ) )
F_71 ( V_2 , F_47 ( & V_6 -> V_14 ) ) ;
}
}
