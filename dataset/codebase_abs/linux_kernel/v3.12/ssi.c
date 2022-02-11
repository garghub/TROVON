static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 ;
T_1 V_9 ;
T_1 V_10 ;
int V_11 ;
V_4 -> V_12 = 0 ;
F_3 (ssi, priv, i) {
V_9 = F_4 ( V_8 ) ;
if ( ! ( V_9 & V_13 ) ) {
V_4 -> V_12 |= ( 1 << V_11 ) ;
F_5 ( V_6 , L_1 , V_11 ) ;
} else {
F_5 ( V_6 , L_2 , V_11 ) ;
}
}
#define F_6 ( T_2 , T_3 , T_4 , T_5 ) \
do { \
ssi->parent = ssiu->ssi + p; \
if (flags & RSND_SSI_CLK_FROM_ADG) \
val = adg; \
else \
val = ext; \
if (flags & RSND_SSI_SYNC) \
val |= sync; \
} while (0)
V_4 -> V_14 = 0 ;
F_3 (ssi, priv, i) {
V_9 = F_4 ( V_8 ) ;
if ( ! ( V_9 & V_15 ) )
continue;
V_10 = 0 ;
switch ( V_11 ) {
case 1 :
F_6 ( 0 , ( 1 << 4 ) , ( 0x2 << 0 ) , ( 0x1 << 0 ) ) ;
break;
case 2 :
F_6 ( 0 , ( 1 << 4 ) , ( 0x2 << 2 ) , ( 0x1 << 2 ) ) ;
break;
case 4 :
F_6 ( 3 , ( 1 << 20 ) , ( 0x2 << 16 ) , ( 0x1 << 16 ) ) ;
break;
case 8 :
F_6 ( 7 , 0 , 0 , 0 ) ;
break;
}
V_4 -> V_14 |= V_10 ;
}
}
static void F_7 ( struct V_7 * V_8 )
{
struct V_3 * V_4 = F_8 ( V_8 ) ;
F_9 ( & V_8 -> V_16 , V_17 , V_4 -> V_12 ) ;
F_9 ( & V_8 -> V_16 , V_18 , V_4 -> V_14 ) ;
}
static void F_10 ( struct V_19 * V_16 ,
T_1 V_20 )
{
struct V_1 * V_2 = F_11 ( V_16 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_21 ;
int V_11 ;
for ( V_11 = 0 ; V_11 < 1024 ; V_11 ++ ) {
V_21 = F_12 ( V_16 , V_22 ) ;
if ( V_21 & V_20 )
return;
F_13 ( 50 ) ;
}
F_14 ( V_6 , L_3 ) ;
}
static int F_15 ( struct V_7 * V_8 ,
unsigned int V_23 )
{
struct V_1 * V_2 = F_11 ( & V_8 -> V_16 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_11 , V_24 , V_25 ;
int V_26 [] = {
1 , 6 ,
} ;
int V_27 [] = {
1 , 2 , 4 , 8 , 16 , 6 , 12 ,
} ;
unsigned int V_28 ;
for ( V_11 = 0 ; V_11 < F_16 ( V_26 ) ; V_11 ++ ) {
for ( V_24 = 0 ; V_24 < F_16 ( V_27 ) ; V_24 ++ ) {
V_28 = V_23 / V_26 [ V_11 ]
* 32 * 2 * V_27 [ V_24 ] ;
V_25 = F_17 ( & V_8 -> V_16 , V_28 ) ;
if ( 0 == V_25 ) {
V_8 -> V_23 = V_23 ;
V_8 -> V_29 = V_30 | V_31 |
V_32 | V_33 | F_18 ( V_24 ) ;
F_5 ( V_6 , L_4 ,
F_19 ( & V_8 -> V_16 ) , V_23 ) ;
return 0 ;
}
}
}
F_20 ( V_6 , L_5 ) ;
return - V_34 ;
}
static void F_21 ( struct V_7 * V_8 )
{
V_8 -> V_23 = 0 ;
V_8 -> V_29 = 0 ;
F_22 ( & V_8 -> V_16 ) ;
}
static void F_23 ( struct V_7 * V_8 ,
struct V_35 * V_36 ,
struct V_37 * V_38 )
{
struct V_1 * V_2 = F_11 ( & V_8 -> V_16 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_39 ;
if ( 0 == V_8 -> V_40 ) {
F_24 ( V_8 -> V_41 ) ;
if ( F_25 ( V_36 ) ) {
struct V_42 * V_43 ;
V_43 = F_26 ( V_38 ) ;
if ( F_27 ( V_8 ) )
F_23 ( V_8 -> V_44 , V_36 , V_38 ) ;
else
F_15 ( V_8 , V_43 -> V_23 ) ;
}
}
V_39 = V_8 -> V_45 |
V_8 -> V_29 |
V_8 -> V_46 |
V_47 ;
F_9 ( & V_8 -> V_16 , V_48 , V_39 ) ;
V_8 -> V_40 ++ ;
F_5 ( V_6 , L_6 , F_19 ( & V_8 -> V_16 ) ) ;
}
static void F_28 ( struct V_7 * V_8 ,
struct V_35 * V_36 )
{
struct V_1 * V_2 = F_11 ( & V_8 -> V_16 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_39 ;
if ( 0 == V_8 -> V_40 )
return;
V_8 -> V_40 -- ;
if ( 0 == V_8 -> V_40 ) {
V_39 = V_8 -> V_45 |
V_8 -> V_29 ;
F_9 ( & V_8 -> V_16 , V_48 , V_39 | V_47 ) ;
F_10 ( & V_8 -> V_16 , V_49 ) ;
F_9 ( & V_8 -> V_16 , V_48 , V_39 ) ;
F_10 ( & V_8 -> V_16 , V_50 ) ;
if ( F_25 ( V_36 ) ) {
if ( F_27 ( V_8 ) )
F_28 ( V_8 -> V_44 , V_36 ) ;
else
F_21 ( V_8 ) ;
}
F_29 ( V_8 -> V_41 ) ;
}
F_5 ( V_6 , L_7 , F_19 ( & V_8 -> V_16 ) ) ;
}
static int F_30 ( struct V_19 * V_16 ,
struct V_35 * V_36 ,
struct V_37 * V_38 )
{
struct V_7 * V_8 = F_31 ( V_16 ) ;
struct V_1 * V_2 = F_11 ( V_16 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_42 * V_43 = F_26 ( V_38 ) ;
T_1 V_39 ;
V_39 = V_30 ;
V_39 |= V_31 ;
switch ( V_43 -> V_51 ) {
case 16 :
V_39 |= V_52 ;
break;
case 32 :
V_39 |= V_53 ;
break;
default:
return - V_34 ;
}
if ( V_36 -> V_54 )
V_39 |= V_55 ;
if ( V_36 -> V_56 )
V_39 |= V_57 ;
if ( V_36 -> V_58 )
V_39 |= V_59 ;
if ( V_36 -> V_60 )
V_39 |= V_61 ;
if ( F_32 ( V_36 , V_38 ) )
V_39 |= V_62 ;
V_8 -> V_36 = V_36 ;
V_8 -> V_38 = V_38 ;
V_8 -> V_45 = V_39 ;
V_8 -> V_63 = - 1 ;
F_7 ( V_8 ) ;
F_5 ( V_6 , L_8 , F_33 ( V_16 ) , F_19 ( V_16 ) ) ;
return 0 ;
}
static int F_34 ( struct V_19 * V_16 ,
struct V_35 * V_36 ,
struct V_37 * V_38 )
{
struct V_7 * V_8 = F_31 ( V_16 ) ;
struct V_1 * V_2 = F_11 ( V_16 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_5 ( V_6 , L_9 , F_33 ( V_16 ) , F_19 ( V_16 ) ) ;
if ( V_8 -> V_63 > 0 )
F_14 ( V_6 , L_10 , V_8 -> V_63 ) ;
V_8 -> V_36 = NULL ;
V_8 -> V_38 = NULL ;
V_8 -> V_45 = 0 ;
V_8 -> V_63 = 0 ;
return 0 ;
}
static void F_35 ( struct V_7 * V_8 , T_1 V_21 )
{
if ( V_21 & ( V_64 | V_65 ) ) {
V_8 -> V_63 ++ ;
F_9 ( & V_8 -> V_16 , V_22 , 0 ) ;
}
}
static T_6 F_36 ( int V_66 , void * V_67 )
{
struct V_7 * V_8 = V_67 ;
struct V_37 * V_38 = V_8 -> V_38 ;
T_1 V_21 = F_12 ( & V_8 -> V_16 , V_22 ) ;
T_6 V_25 = V_68 ;
if ( V_38 && ( V_21 & V_49 ) ) {
struct V_35 * V_36 = V_8 -> V_36 ;
struct V_42 * V_43 = F_26 ( V_38 ) ;
T_1 * V_69 = ( T_1 * ) ( V_43 -> V_70 +
F_37 ( V_38 , 0 ) ) ;
F_35 ( V_8 , V_21 ) ;
if ( F_32 ( V_36 , V_38 ) )
F_9 ( & V_8 -> V_16 , V_71 , * V_69 ) ;
else
* V_69 = F_12 ( & V_8 -> V_16 , V_72 ) ;
F_38 ( V_38 , sizeof( * V_69 ) ) ;
V_25 = V_73 ;
}
return V_25 ;
}
static int F_39 ( struct V_19 * V_16 ,
struct V_35 * V_36 ,
struct V_37 * V_38 )
{
struct V_1 * V_2 = F_11 ( V_16 ) ;
struct V_7 * V_8 = F_31 ( V_16 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_8 -> V_46 = V_74 | V_75 | V_76 ;
F_23 ( V_8 , V_36 , V_38 ) ;
F_5 ( V_6 , L_11 , F_33 ( V_16 ) , F_19 ( V_16 ) ) ;
return 0 ;
}
static int F_40 ( struct V_19 * V_16 ,
struct V_35 * V_36 ,
struct V_37 * V_38 )
{
struct V_1 * V_2 = F_11 ( V_16 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_31 ( V_16 ) ;
F_5 ( V_6 , L_12 , F_33 ( V_16 ) , F_19 ( V_16 ) ) ;
V_8 -> V_46 = 0 ;
F_28 ( V_8 , V_36 ) ;
return 0 ;
}
static int F_41 ( struct V_77 * V_78 , T_7 * V_69 , int * V_79 )
{
struct V_7 * V_8 = F_42 ( V_78 ) ;
struct V_37 * V_38 = V_8 -> V_38 ;
struct V_42 * V_43 = F_26 ( V_38 ) ;
* V_79 = V_38 -> V_80 ;
* V_69 = V_43 -> V_81 +
F_37 ( V_38 , V_8 -> V_82 + * V_79 ) ;
V_8 -> V_82 = * V_79 ;
return 0 ;
}
static int F_43 ( struct V_77 * V_78 )
{
struct V_7 * V_8 = F_42 ( V_78 ) ;
struct V_37 * V_38 = V_8 -> V_38 ;
T_1 V_21 = F_12 ( & V_8 -> V_16 , V_22 ) ;
F_35 ( V_8 , V_21 ) ;
F_38 ( V_8 -> V_38 , V_38 -> V_80 ) ;
return 0 ;
}
static int F_44 ( struct V_19 * V_16 ,
struct V_35 * V_36 ,
struct V_37 * V_38 )
{
struct V_7 * V_8 = F_31 ( V_16 ) ;
struct V_77 * V_78 = F_45 ( & V_8 -> V_16 ) ;
V_8 -> V_46 = V_83 ;
V_8 -> V_82 = 0 ;
F_46 ( V_78 ) ;
F_23 ( V_8 , V_8 -> V_36 , V_38 ) ;
if ( F_25 ( V_36 ) )
F_9 ( & V_8 -> V_16 , V_84 , V_85 ) ;
return 0 ;
}
static int F_47 ( struct V_19 * V_16 ,
struct V_35 * V_36 ,
struct V_37 * V_38 )
{
struct V_7 * V_8 = F_31 ( V_16 ) ;
struct V_77 * V_78 = F_45 ( & V_8 -> V_16 ) ;
V_8 -> V_46 = 0 ;
F_28 ( V_8 , V_36 ) ;
F_48 ( V_78 ) ;
return 0 ;
}
static int F_49 ( struct V_19 * V_16 ,
struct V_35 * V_36 ,
struct V_37 * V_38 )
{
struct V_1 * V_2 = F_11 ( V_16 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_5 ( V_6 , L_13 , V_86 ) ;
return 0 ;
}
struct V_19 * F_50 ( struct V_1 * V_2 ,
int V_87 , int V_88 )
{
struct V_7 * V_8 ;
int V_11 , V_89 ;
V_88 = ! ! V_88 ;
F_3 (ssi, priv, i) {
if ( F_51 ( V_8 ) != V_87 )
continue;
V_89 = ! ! ( F_4 ( V_8 ) & V_90 ) ;
if ( V_88 == V_89 )
return & V_8 -> V_16 ;
}
return NULL ;
}
struct V_19 * F_52 ( struct V_1 * V_2 , int V_91 )
{
F_53 ( V_91 < 0 || V_91 >= F_54 ( V_2 ) ) ;
return & ( ( (struct V_3 * ) ( V_2 -> V_4 ) ) -> V_8 + V_91 ) -> V_16 ;
}
int F_55 ( struct V_92 * V_93 ,
struct V_94 * V_95 ,
struct V_1 * V_2 )
{
struct V_96 * V_97 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_98 * V_99 ;
struct V_41 * V_41 ;
struct V_3 * V_4 ;
struct V_7 * V_8 ;
char V_100 [ V_101 ] ;
int V_11 , V_102 , V_25 ;
V_102 = V_95 -> V_103 ;
V_4 = F_56 ( V_6 , sizeof( * V_4 ) + ( sizeof( * V_8 ) * V_102 ) ,
V_104 ) ;
if ( ! V_4 ) {
F_20 ( V_6 , L_14 ) ;
return - V_105 ;
}
V_2 -> V_4 = V_4 ;
V_4 -> V_8 = (struct V_7 * ) ( V_4 + 1 ) ;
V_4 -> V_106 = V_102 ;
F_3 (ssi, priv, i) {
V_97 = & V_95 -> V_107 [ V_11 ] ;
snprintf ( V_100 , V_101 , L_15 , V_11 ) ;
V_41 = F_57 ( V_6 , V_100 ) ;
if ( F_58 ( V_41 ) )
return F_59 ( V_41 ) ;
V_8 -> V_95 = V_97 ;
V_8 -> V_41 = V_41 ;
V_99 = & V_108 ;
if ( V_97 -> V_109 > 0 ) {
V_25 = F_60 (
V_2 , F_45 ( & V_8 -> V_16 ) ,
( F_4 ( V_8 ) & V_90 ) ,
V_97 -> V_109 ,
F_41 ,
F_43 ) ;
if ( V_25 < 0 )
F_61 ( V_6 , L_16 ) ;
else
V_99 = & V_110 ;
F_5 ( V_6 , L_17 , V_11 ) ;
}
if ( ! F_62 ( V_8 ) &&
F_63 ( V_8 ) ) {
V_25 = F_64 ( V_6 , V_97 -> V_111 ,
& F_36 ,
V_112 ,
F_65 ( V_6 ) , V_8 ) ;
if ( V_25 ) {
F_20 ( V_6 , L_18 ) ;
return V_25 ;
}
V_99 = & V_113 ;
F_5 ( V_6 , L_19 , V_11 ) ;
}
F_66 ( V_2 , & V_8 -> V_16 , V_99 , V_11 ) ;
}
F_1 ( V_2 , V_4 ) ;
F_5 ( V_6 , L_20 ) ;
return 0 ;
}
void F_67 ( struct V_92 * V_93 ,
struct V_1 * V_2 )
{
struct V_7 * V_8 ;
int V_11 ;
F_3 (ssi, priv, i) {
F_68 ( V_8 -> V_41 ) ;
if ( F_62 ( V_8 ) )
F_69 ( V_2 , F_45 ( & V_8 -> V_16 ) ) ;
}
}
