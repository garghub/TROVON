static void F_1 ( struct V_1 * V_2 ,
T_1 V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = F_3 ( V_5 ) ;
T_1 V_8 ;
int V_9 ;
for ( V_9 = 0 ; V_9 < 1024 ; V_9 ++ ) {
V_8 = F_4 ( V_2 , V_10 ) ;
if ( V_8 & V_3 )
return;
F_5 ( 50 ) ;
}
F_6 ( V_7 , L_1 ) ;
}
static int F_7 ( struct V_11 * V_12 ,
struct V_13 * V_14 )
{
struct V_4 * V_5 = F_2 ( & V_12 -> V_2 ) ;
struct V_15 * V_16 = F_8 ( V_14 ) ;
struct V_6 * V_7 = F_3 ( V_5 ) ;
int V_9 , V_17 , V_18 ;
int V_19 [] = {
1 , 6 ,
} ;
int V_20 [] = {
1 , 2 , 4 , 8 , 16 , 6 , 12 ,
} ;
unsigned int V_21 ;
unsigned int V_22 = F_9 ( V_5 , V_14 , V_16 ) ;
for ( V_9 = 0 ; V_9 < F_10 ( V_19 ) ; V_9 ++ ) {
for ( V_17 = 0 ; V_17 < F_10 ( V_20 ) ; V_17 ++ ) {
V_21 = V_22 / V_19 [ V_9 ]
* 32 * 2 * V_20 [ V_17 ] ;
V_18 = F_11 ( & V_12 -> V_2 , V_21 ) ;
if ( 0 == V_18 ) {
V_12 -> V_22 = V_22 ;
V_12 -> V_23 = V_24 | V_25 |
V_26 | V_27 | F_12 ( V_17 ) ;
F_13 ( V_7 , L_2 ,
F_14 ( & V_12 -> V_2 ) , V_22 ) ;
return 0 ;
}
}
}
F_15 ( V_7 , L_3 ) ;
return - V_28 ;
}
static void F_16 ( struct V_11 * V_12 )
{
V_12 -> V_22 = 0 ;
V_12 -> V_23 = 0 ;
F_17 ( & V_12 -> V_2 ) ;
}
static void F_18 ( struct V_11 * V_12 ,
struct V_29 * V_30 ,
struct V_13 * V_14 )
{
struct V_4 * V_5 = F_2 ( & V_12 -> V_2 ) ;
struct V_6 * V_7 = F_3 ( V_5 ) ;
T_1 V_31 ;
if ( 0 == V_12 -> V_32 ) {
F_19 ( V_12 -> V_33 ) ;
if ( F_20 ( V_30 ) ) {
if ( F_21 ( V_12 ) )
F_18 ( V_12 -> V_34 , V_30 , V_14 ) ;
else
F_7 ( V_12 , V_14 ) ;
}
}
V_31 = V_12 -> V_35 |
V_12 -> V_23 |
V_12 -> V_36 |
V_37 ;
F_22 ( & V_12 -> V_2 , V_38 , V_31 ) ;
V_12 -> V_32 ++ ;
F_13 ( V_7 , L_4 , F_14 ( & V_12 -> V_2 ) ) ;
}
static void F_23 ( struct V_11 * V_12 ,
struct V_29 * V_30 )
{
struct V_4 * V_5 = F_2 ( & V_12 -> V_2 ) ;
struct V_6 * V_7 = F_3 ( V_5 ) ;
T_1 V_31 ;
if ( 0 == V_12 -> V_32 )
return;
V_12 -> V_32 -- ;
if ( 0 == V_12 -> V_32 ) {
V_31 = V_12 -> V_35 |
V_12 -> V_23 ;
F_22 ( & V_12 -> V_2 , V_38 , V_31 | V_37 ) ;
F_1 ( & V_12 -> V_2 , V_39 ) ;
F_22 ( & V_12 -> V_2 , V_38 , V_31 ) ;
F_1 ( & V_12 -> V_2 , V_40 ) ;
if ( F_20 ( V_30 ) ) {
if ( F_21 ( V_12 ) )
F_23 ( V_12 -> V_34 , V_30 ) ;
else
F_16 ( V_12 ) ;
}
F_24 ( V_12 -> V_33 ) ;
}
F_13 ( V_7 , L_5 , F_14 ( & V_12 -> V_2 ) ) ;
}
static int F_25 ( struct V_1 * V_2 ,
struct V_29 * V_30 ,
struct V_13 * V_14 )
{
struct V_11 * V_12 = F_26 ( V_2 ) ;
struct V_15 * V_16 = F_8 ( V_14 ) ;
T_1 V_31 ;
V_31 = V_24 ;
V_31 |= V_25 ;
switch ( V_16 -> V_41 ) {
case 16 :
V_31 |= V_42 ;
break;
case 32 :
V_31 |= V_43 ;
break;
default:
return - V_28 ;
}
if ( V_30 -> V_44 )
V_31 |= V_45 ;
if ( V_30 -> V_46 )
V_31 |= V_47 ;
if ( V_30 -> V_48 )
V_31 |= V_49 ;
if ( V_30 -> V_50 )
V_31 |= V_51 ;
if ( F_27 ( V_30 , V_14 ) )
V_31 |= V_52 ;
V_12 -> V_30 = V_30 ;
V_12 -> V_35 = V_31 ;
V_12 -> V_53 = - 1 ;
F_28 ( V_2 , V_30 , V_14 ) ;
return 0 ;
}
static int F_29 ( struct V_1 * V_2 ,
struct V_29 * V_30 ,
struct V_13 * V_14 )
{
struct V_11 * V_12 = F_26 ( V_2 ) ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = F_3 ( V_5 ) ;
if ( V_12 -> V_53 > 0 )
F_6 ( V_7 , L_6 , V_12 -> V_53 ) ;
V_12 -> V_30 = NULL ;
V_12 -> V_35 = 0 ;
V_12 -> V_53 = 0 ;
return 0 ;
}
static void F_30 ( struct V_11 * V_12 , T_1 V_8 )
{
if ( V_8 & ( V_54 | V_55 ) ) {
V_12 -> V_53 ++ ;
F_22 ( & V_12 -> V_2 , V_10 , 0 ) ;
}
}
static T_2 F_31 ( int V_56 , void * V_57 )
{
struct V_11 * V_12 = V_57 ;
struct V_1 * V_2 = & V_12 -> V_2 ;
struct V_13 * V_14 = F_32 ( V_2 ) ;
T_1 V_8 = F_4 ( V_2 , V_10 ) ;
T_2 V_18 = V_58 ;
if ( V_14 && ( V_8 & V_39 ) ) {
struct V_29 * V_30 = V_12 -> V_30 ;
struct V_15 * V_16 = F_8 ( V_14 ) ;
T_1 * V_59 = ( T_1 * ) ( V_16 -> V_60 +
F_33 ( V_14 , 0 ) ) ;
F_30 ( V_12 , V_8 ) ;
if ( F_27 ( V_30 , V_14 ) )
F_22 ( V_2 , V_61 , * V_59 ) ;
else
* V_59 = F_4 ( V_2 , V_62 ) ;
F_34 ( V_14 , sizeof( * V_59 ) ) ;
V_18 = V_63 ;
}
return V_18 ;
}
static int F_35 ( struct V_1 * V_2 ,
struct V_29 * V_30 ,
struct V_13 * V_14 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = F_3 ( V_5 ) ;
struct V_11 * V_12 = F_26 ( V_2 ) ;
int V_56 = V_12 -> V_64 -> V_65 ;
int V_18 ;
V_18 = F_36 ( V_7 , V_56 ,
F_31 ,
V_66 ,
F_37 ( V_7 ) , V_12 ) ;
if ( V_18 )
F_15 ( V_7 , L_7 ) ;
return V_18 ;
}
static int F_38 ( struct V_1 * V_2 ,
struct V_29 * V_30 ,
struct V_13 * V_14 )
{
struct V_11 * V_12 = F_26 ( V_2 ) ;
V_12 -> V_36 = V_67 | V_68 | V_69 ;
F_39 ( V_2 , V_30 , V_14 ) ;
F_18 ( V_12 , V_30 , V_14 ) ;
return 0 ;
}
static int F_40 ( struct V_1 * V_2 ,
struct V_29 * V_30 ,
struct V_13 * V_14 )
{
struct V_11 * V_12 = F_26 ( V_2 ) ;
V_12 -> V_36 = 0 ;
F_23 ( V_12 , V_30 ) ;
return 0 ;
}
static int F_41 ( struct V_1 * V_2 ,
struct V_29 * V_30 ,
struct V_13 * V_14 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_11 * V_12 = F_26 ( V_2 ) ;
struct V_70 * V_64 = F_42 ( V_5 ) ;
struct V_6 * V_7 = F_3 ( V_5 ) ;
int V_71 = V_12 -> V_64 -> V_71 ;
int V_72 ;
int V_18 ;
if ( V_64 -> V_73 )
V_72 = F_43 ( V_5 , V_12 ) ;
else
V_72 = F_44 ( & V_12 -> V_2 ) ;
V_18 = F_45 (
V_5 , F_46 ( V_2 ) ,
V_72 ,
V_71 ) ;
if ( V_18 < 0 )
F_15 ( V_7 , L_8 ) ;
return V_18 ;
}
static int F_47 ( struct V_1 * V_2 ,
struct V_29 * V_30 ,
struct V_13 * V_14 )
{
F_48 ( F_2 ( V_2 ) , F_46 ( V_2 ) ) ;
return 0 ;
}
static int F_49 ( struct V_1 * V_2 ,
struct V_29 * V_30 ,
struct V_13 * V_14 )
{
struct V_11 * V_12 = F_26 ( V_2 ) ;
struct V_74 * V_75 = F_46 ( & V_12 -> V_2 ) ;
V_12 -> V_36 = V_76 ;
F_50 ( V_75 ) ;
F_18 ( V_12 , V_12 -> V_30 , V_14 ) ;
if ( F_20 ( V_30 ) )
F_22 ( & V_12 -> V_2 , V_77 , V_78 ) ;
return 0 ;
}
static int F_51 ( struct V_1 * V_2 ,
struct V_29 * V_30 ,
struct V_13 * V_14 )
{
struct V_11 * V_12 = F_26 ( V_2 ) ;
struct V_74 * V_75 = F_46 ( & V_12 -> V_2 ) ;
V_12 -> V_36 = 0 ;
F_30 ( V_12 , F_4 ( V_2 , V_10 ) ) ;
F_23 ( V_12 , V_30 ) ;
F_52 ( V_75 ) ;
return 0 ;
}
struct V_1 * F_53 ( struct V_4 * V_5 ,
int V_79 , int V_72 )
{
struct V_80 * V_73 = NULL ;
struct V_81 * V_82 = NULL ;
struct V_83 * V_84 = NULL ;
struct V_11 * V_12 ;
int V_9 , V_85 ;
if ( V_5 -> V_30 )
V_73 = V_5 -> V_30 [ V_79 ] . V_64 ;
if ( V_73 )
V_82 = ( V_72 ) ? & V_73 -> V_86 : & V_73 -> V_87 ;
if ( V_82 )
V_84 = V_82 -> V_12 ;
V_72 = ! ! V_72 ;
F_54 (ssi, priv, i) {
if ( V_84 == V_12 -> V_64 )
return & V_12 -> V_2 ;
if ( F_55 ( V_12 ) != V_79 )
continue;
V_85 = F_44 ( & V_12 -> V_2 ) ;
if ( V_72 == V_85 )
return & V_12 -> V_2 ;
}
return NULL ;
}
struct V_1 * F_56 ( struct V_4 * V_5 , int V_88 )
{
if ( F_57 ( V_88 < 0 || V_88 >= F_58 ( V_5 ) ) )
V_88 = 0 ;
return & ( (struct V_11 * ) ( V_5 -> V_12 ) + V_88 ) -> V_2 ;
}
int F_59 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = F_26 ( V_2 ) ;
return ! ! ( F_60 ( V_12 ) & V_89 ) ;
}
int F_44 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = F_26 ( V_2 ) ;
return ! ! ( F_60 ( V_12 ) & V_90 ) ;
}
static void F_61 ( struct V_4 * V_5 , struct V_11 * V_12 )
{
if ( ! F_59 ( & V_12 -> V_2 ) )
return;
switch ( F_14 ( & V_12 -> V_2 ) ) {
case 1 :
case 2 :
V_12 -> V_34 = F_26 ( F_56 ( V_5 , 0 ) ) ;
break;
case 4 :
V_12 -> V_34 = F_26 ( F_56 ( V_5 , 3 ) ) ;
break;
case 8 :
V_12 -> V_34 = F_26 ( F_56 ( V_5 , 7 ) ) ;
break;
}
}
static void F_62 ( struct V_91 * V_92 ,
const struct V_93 * V_94 ,
struct V_4 * V_5 )
{
struct V_95 * V_96 ;
struct V_95 * V_97 ;
struct V_83 * V_98 ;
struct V_70 * V_64 = F_42 ( V_5 ) ;
struct V_6 * V_7 = & V_92 -> V_7 ;
int V_99 , V_9 ;
if ( ! V_94 )
return;
V_96 = F_63 ( V_7 -> V_100 , L_9 ) ;
if ( ! V_96 )
return;
V_99 = F_64 ( V_96 ) ;
if ( ! V_99 )
return;
V_98 = F_65 ( V_7 ,
sizeof( struct V_83 ) * V_99 ,
V_101 ) ;
if ( ! V_98 ) {
F_15 ( V_7 , L_10 ) ;
return;
}
V_64 -> V_98 = V_98 ;
V_64 -> V_102 = V_99 ;
V_9 = - 1 ;
F_66 (node, np) {
V_9 ++ ;
V_98 = V_64 -> V_98 + V_9 ;
if ( F_67 ( V_97 , L_11 , NULL ) )
V_98 -> V_103 |= V_89 ;
V_98 -> V_65 = F_68 ( V_97 , 0 ) ;
}
}
int F_69 ( struct V_91 * V_92 ,
const struct V_93 * V_94 ,
struct V_4 * V_5 )
{
struct V_70 * V_64 = F_42 ( V_5 ) ;
struct V_83 * V_104 ;
struct V_6 * V_7 = F_3 ( V_5 ) ;
struct V_105 * V_106 ;
struct V_33 * V_33 ;
struct V_11 * V_12 ;
char V_107 [ V_108 ] ;
int V_9 , V_99 ;
F_62 ( V_92 , V_94 , V_5 ) ;
V_99 = V_64 -> V_102 ;
V_12 = F_65 ( V_7 , sizeof( * V_12 ) * V_99 , V_101 ) ;
if ( ! V_12 ) {
F_15 ( V_7 , L_12 ) ;
return - V_109 ;
}
V_5 -> V_12 = V_12 ;
V_5 -> V_110 = V_99 ;
F_54 (ssi, priv, i) {
V_104 = & V_64 -> V_98 [ V_9 ] ;
snprintf ( V_107 , V_108 , L_13 , V_9 ) ;
V_33 = F_70 ( V_7 , V_107 ) ;
if ( F_71 ( V_33 ) )
return F_72 ( V_33 ) ;
V_12 -> V_64 = V_104 ;
V_12 -> V_33 = V_33 ;
V_106 = & V_111 ;
if ( V_104 -> V_71 > 0 )
V_106 = & V_112 ;
else if ( F_73 ( V_12 ) )
V_106 = & V_113 ;
F_74 ( V_5 , & V_12 -> V_2 , V_106 , V_114 , V_9 ) ;
F_61 ( V_5 , V_12 ) ;
}
return 0 ;
}
