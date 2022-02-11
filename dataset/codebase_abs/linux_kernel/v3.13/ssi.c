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
unsigned int V_26 )
{
struct V_1 * V_2 = F_12 ( & V_6 -> V_14 ) ;
struct V_7 * V_8 = F_2 ( V_2 ) ;
int V_24 , V_27 , V_28 ;
int V_29 [] = {
1 , 6 ,
} ;
int V_30 [] = {
1 , 2 , 4 , 8 , 16 , 6 , 12 ,
} ;
unsigned int V_31 ;
for ( V_24 = 0 ; V_24 < F_17 ( V_29 ) ; V_24 ++ ) {
for ( V_27 = 0 ; V_27 < F_17 ( V_30 ) ; V_27 ++ ) {
V_31 = V_26 / V_29 [ V_24 ]
* 32 * 2 * V_30 [ V_27 ] ;
V_28 = F_18 ( & V_6 -> V_14 , V_31 ) ;
if ( 0 == V_28 ) {
V_6 -> V_26 = V_26 ;
V_6 -> V_32 = V_33 | V_34 |
V_35 | V_36 | F_19 ( V_27 ) ;
F_7 ( V_8 , L_4 ,
F_4 ( & V_6 -> V_14 ) , V_26 ) ;
return 0 ;
}
}
}
F_20 ( V_8 , L_5 ) ;
return - V_37 ;
}
static void F_21 ( struct V_5 * V_6 )
{
V_6 -> V_26 = 0 ;
V_6 -> V_32 = 0 ;
F_22 ( & V_6 -> V_14 ) ;
}
static void F_23 ( struct V_5 * V_6 ,
struct V_3 * V_4 ,
struct V_38 * V_39 )
{
struct V_1 * V_2 = F_12 ( & V_6 -> V_14 ) ;
struct V_7 * V_8 = F_2 ( V_2 ) ;
T_1 V_40 ;
if ( 0 == V_6 -> V_41 ) {
F_24 ( V_6 -> V_42 ) ;
if ( F_25 ( V_4 ) ) {
struct V_43 * V_44 ;
V_44 = F_26 ( V_39 ) ;
if ( F_27 ( V_6 ) )
F_23 ( V_6 -> V_45 , V_4 , V_39 ) ;
else
F_16 ( V_6 , V_44 -> V_26 ) ;
}
}
V_40 = V_6 -> V_46 |
V_6 -> V_32 |
V_6 -> V_47 |
V_48 ;
F_10 ( & V_6 -> V_14 , V_49 , V_40 ) ;
V_6 -> V_41 ++ ;
F_7 ( V_8 , L_6 , F_4 ( & V_6 -> V_14 ) ) ;
}
static void F_28 ( struct V_5 * V_6 ,
struct V_3 * V_4 )
{
struct V_1 * V_2 = F_12 ( & V_6 -> V_14 ) ;
struct V_7 * V_8 = F_2 ( V_2 ) ;
T_1 V_40 ;
if ( 0 == V_6 -> V_41 )
return;
V_6 -> V_41 -- ;
if ( 0 == V_6 -> V_41 ) {
V_40 = V_6 -> V_46 |
V_6 -> V_32 ;
F_10 ( & V_6 -> V_14 , V_49 , V_40 | V_48 ) ;
F_11 ( & V_6 -> V_14 , V_50 ) ;
F_10 ( & V_6 -> V_14 , V_49 , V_40 ) ;
F_11 ( & V_6 -> V_14 , V_51 ) ;
if ( F_25 ( V_4 ) ) {
if ( F_27 ( V_6 ) )
F_28 ( V_6 -> V_45 , V_4 ) ;
else
F_21 ( V_6 ) ;
}
F_29 ( V_6 -> V_42 ) ;
}
F_7 ( V_8 , L_7 , F_4 ( & V_6 -> V_14 ) ) ;
}
static int F_30 ( struct V_9 * V_14 ,
struct V_3 * V_4 ,
struct V_38 * V_39 )
{
struct V_5 * V_6 = F_31 ( V_14 ) ;
struct V_1 * V_2 = F_12 ( V_14 ) ;
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_43 * V_44 = F_26 ( V_39 ) ;
T_1 V_40 ;
V_40 = V_33 ;
V_40 |= V_34 ;
switch ( V_44 -> V_52 ) {
case 16 :
V_40 |= V_53 ;
break;
case 32 :
V_40 |= V_54 ;
break;
default:
return - V_37 ;
}
if ( V_4 -> V_55 )
V_40 |= V_56 ;
if ( V_4 -> V_57 )
V_40 |= V_58 ;
if ( V_4 -> V_59 )
V_40 |= V_60 ;
if ( V_4 -> V_61 )
V_40 |= V_62 ;
if ( F_32 ( V_4 , V_39 ) )
V_40 |= V_63 ;
V_6 -> V_4 = V_4 ;
V_6 -> V_39 = V_39 ;
V_6 -> V_46 = V_40 ;
V_6 -> V_64 = - 1 ;
F_1 ( V_2 , V_4 , V_6 ) ;
F_7 ( V_8 , L_8 , F_33 ( V_14 ) , F_4 ( V_14 ) ) ;
return 0 ;
}
static int F_34 ( struct V_9 * V_14 ,
struct V_3 * V_4 ,
struct V_38 * V_39 )
{
struct V_5 * V_6 = F_31 ( V_14 ) ;
struct V_1 * V_2 = F_12 ( V_14 ) ;
struct V_7 * V_8 = F_2 ( V_2 ) ;
F_7 ( V_8 , L_9 , F_33 ( V_14 ) , F_4 ( V_14 ) ) ;
if ( V_6 -> V_64 > 0 )
F_15 ( V_8 , L_10 , V_6 -> V_64 ) ;
V_6 -> V_4 = NULL ;
V_6 -> V_39 = NULL ;
V_6 -> V_46 = 0 ;
V_6 -> V_64 = 0 ;
return 0 ;
}
static void F_35 ( struct V_5 * V_6 , T_1 V_23 )
{
if ( V_23 & ( V_65 | V_66 ) ) {
V_6 -> V_64 ++ ;
F_10 ( & V_6 -> V_14 , V_25 , 0 ) ;
}
}
static T_6 F_36 ( int V_67 , void * V_68 )
{
struct V_5 * V_6 = V_68 ;
struct V_38 * V_39 = V_6 -> V_39 ;
T_1 V_23 = F_13 ( & V_6 -> V_14 , V_25 ) ;
T_6 V_28 = V_69 ;
if ( V_39 && ( V_23 & V_50 ) ) {
struct V_3 * V_4 = V_6 -> V_4 ;
struct V_43 * V_44 = F_26 ( V_39 ) ;
T_1 * V_70 = ( T_1 * ) ( V_44 -> V_71 +
F_37 ( V_39 , 0 ) ) ;
F_35 ( V_6 , V_23 ) ;
if ( F_32 ( V_4 , V_39 ) )
F_10 ( & V_6 -> V_14 , V_72 , * V_70 ) ;
else
* V_70 = F_13 ( & V_6 -> V_14 , V_73 ) ;
F_38 ( V_39 , sizeof( * V_70 ) ) ;
V_28 = V_74 ;
}
return V_28 ;
}
static int F_39 ( struct V_9 * V_14 ,
struct V_3 * V_4 ,
struct V_38 * V_39 )
{
struct V_1 * V_2 = F_12 ( V_14 ) ;
struct V_5 * V_6 = F_31 ( V_14 ) ;
struct V_7 * V_8 = F_2 ( V_2 ) ;
V_6 -> V_47 = V_75 | V_76 | V_77 ;
F_23 ( V_6 , V_4 , V_39 ) ;
F_7 ( V_8 , L_11 , F_33 ( V_14 ) , F_4 ( V_14 ) ) ;
return 0 ;
}
static int F_40 ( struct V_9 * V_14 ,
struct V_3 * V_4 ,
struct V_38 * V_39 )
{
struct V_1 * V_2 = F_12 ( V_14 ) ;
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_31 ( V_14 ) ;
F_7 ( V_8 , L_12 , F_33 ( V_14 ) , F_4 ( V_14 ) ) ;
V_6 -> V_47 = 0 ;
F_28 ( V_6 , V_4 ) ;
return 0 ;
}
static int F_41 ( struct V_78 * V_79 , T_7 * V_70 , int * V_80 )
{
struct V_5 * V_6 = F_42 ( V_79 ) ;
struct V_38 * V_39 = V_6 -> V_39 ;
struct V_43 * V_44 = F_26 ( V_39 ) ;
* V_80 = V_39 -> V_81 ;
* V_70 = V_44 -> V_82 +
F_37 ( V_39 , V_6 -> V_83 + * V_80 ) ;
V_6 -> V_83 = * V_80 ;
return 0 ;
}
static int F_43 ( struct V_78 * V_79 )
{
struct V_5 * V_6 = F_42 ( V_79 ) ;
struct V_38 * V_39 = V_6 -> V_39 ;
T_1 V_23 = F_13 ( & V_6 -> V_14 , V_25 ) ;
F_35 ( V_6 , V_23 ) ;
F_38 ( V_6 -> V_39 , V_39 -> V_81 ) ;
return 0 ;
}
static int F_44 ( struct V_9 * V_14 ,
struct V_3 * V_4 ,
struct V_38 * V_39 )
{
struct V_5 * V_6 = F_31 ( V_14 ) ;
struct V_78 * V_79 = F_45 ( & V_6 -> V_14 ) ;
V_6 -> V_47 = V_84 ;
V_6 -> V_83 = 0 ;
F_46 ( V_79 ) ;
F_23 ( V_6 , V_6 -> V_4 , V_39 ) ;
if ( F_25 ( V_4 ) )
F_10 ( & V_6 -> V_14 , V_85 , V_86 ) ;
return 0 ;
}
static int F_47 ( struct V_9 * V_14 ,
struct V_3 * V_4 ,
struct V_38 * V_39 )
{
struct V_5 * V_6 = F_31 ( V_14 ) ;
struct V_78 * V_79 = F_45 ( & V_6 -> V_14 ) ;
V_6 -> V_47 = 0 ;
F_28 ( V_6 , V_4 ) ;
F_48 ( V_79 ) ;
return 0 ;
}
static int F_49 ( struct V_9 * V_14 ,
struct V_3 * V_4 ,
struct V_38 * V_39 )
{
struct V_1 * V_2 = F_12 ( V_14 ) ;
struct V_7 * V_8 = F_2 ( V_2 ) ;
F_7 ( V_8 , L_13 , V_87 ) ;
return 0 ;
}
struct V_9 * F_50 ( struct V_1 * V_2 ,
int V_88 , int V_89 )
{
struct V_5 * V_6 ;
int V_24 , V_90 ;
V_89 = ! ! V_89 ;
F_51 (ssi, priv, i) {
if ( F_52 ( V_6 ) != V_88 )
continue;
V_90 = ! ! ( F_9 ( V_6 ) & V_91 ) ;
if ( V_89 == V_90 )
return & V_6 -> V_14 ;
}
return NULL ;
}
struct V_9 * F_53 ( struct V_1 * V_2 , int V_13 )
{
if ( F_54 ( V_13 < 0 || V_13 >= F_55 ( V_2 ) ) )
V_13 = 0 ;
return & ( ( (struct V_11 * ) ( V_2 -> V_12 ) ) -> V_6 + V_13 ) -> V_14 ;
}
int F_56 ( struct V_92 * V_93 ,
struct V_94 * V_95 ,
struct V_1 * V_2 )
{
struct V_96 * V_97 ;
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_98 * V_99 ;
struct V_42 * V_42 ;
struct V_11 * V_12 ;
struct V_5 * V_6 ;
char V_100 [ V_101 ] ;
int V_24 , V_102 , V_28 ;
V_102 = V_95 -> V_103 ;
V_12 = F_57 ( V_8 , sizeof( * V_12 ) + ( sizeof( * V_6 ) * V_102 ) ,
V_104 ) ;
if ( ! V_12 ) {
F_20 ( V_8 , L_14 ) ;
return - V_105 ;
}
V_2 -> V_12 = V_12 ;
V_12 -> V_6 = (struct V_5 * ) ( V_12 + 1 ) ;
V_12 -> V_106 = V_102 ;
F_51 (ssi, priv, i) {
V_97 = & V_95 -> V_107 [ V_24 ] ;
snprintf ( V_100 , V_101 , L_15 , V_24 ) ;
V_42 = F_58 ( V_8 , V_100 ) ;
if ( F_59 ( V_42 ) )
return F_60 ( V_42 ) ;
V_6 -> V_95 = V_97 ;
V_6 -> V_42 = V_42 ;
V_99 = & V_108 ;
if ( V_97 -> V_109 > 0 ) {
V_28 = F_61 (
V_2 , F_45 ( & V_6 -> V_14 ) ,
( F_9 ( V_6 ) & V_91 ) ,
V_97 -> V_109 ,
F_41 ,
F_43 ) ;
if ( V_28 < 0 )
F_62 ( V_8 , L_16 ) ;
else
V_99 = & V_110 ;
F_7 ( V_8 , L_17 , V_24 ) ;
}
if ( ! F_63 ( V_6 ) &&
F_64 ( V_6 ) ) {
V_28 = F_65 ( V_8 , V_97 -> V_111 ,
& F_36 ,
V_112 ,
F_66 ( V_8 ) , V_6 ) ;
if ( V_28 ) {
F_20 ( V_8 , L_18 ) ;
return V_28 ;
}
V_99 = & V_113 ;
F_7 ( V_8 , L_19 , V_24 ) ;
}
F_67 ( V_2 , & V_6 -> V_14 , V_99 , V_24 ) ;
}
F_7 ( V_8 , L_20 ) ;
return 0 ;
}
void F_68 ( struct V_92 * V_93 ,
struct V_1 * V_2 )
{
struct V_5 * V_6 ;
int V_24 ;
F_51 (ssi, priv, i) {
F_69 ( V_6 -> V_42 ) ;
if ( F_63 ( V_6 ) )
F_70 ( V_2 , F_45 ( & V_6 -> V_14 ) ) ;
}
}
