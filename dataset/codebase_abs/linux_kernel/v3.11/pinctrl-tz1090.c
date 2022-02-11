static void T_1 F_1 ( void )
{
unsigned int V_1 , V_2 ;
const struct V_3 * V_4 ;
const unsigned int * V_5 ;
for ( V_2 = 0 ; V_2 < V_6 ; ++ V_2 )
V_7 [ V_2 ] = V_8 ;
V_4 = V_9 ;
for ( V_1 = 0 , V_4 = V_9 ;
V_1 < F_2 ( V_9 ) ; ++ V_1 , ++ V_4 )
for ( V_5 = V_4 -> V_10 , V_2 = 0 ; V_2 < V_4 -> V_11 ; ++ V_2 , ++ V_5 )
V_7 [ * V_5 ] = V_1 ;
}
static inline T_2 F_3 ( struct V_12 * V_13 , T_2 V_14 )
{
return F_4 ( V_13 -> V_15 + V_14 ) ;
}
static inline void F_5 ( struct V_12 * V_13 , T_2 V_16 , T_2 V_14 )
{
F_6 ( V_16 , V_13 -> V_15 + V_14 ) ;
}
static int F_7 ( struct V_17 * V_18 )
{
return F_2 ( V_19 ) + V_6 ;
}
static const char * F_8 ( struct V_17 * V_18 ,
unsigned int V_20 )
{
if ( V_20 < F_2 ( V_19 ) ) {
return V_19 [ V_20 ] . V_21 ;
} else {
unsigned int V_5 = V_20 - F_2 ( V_19 ) ;
return V_22 [ V_5 ] . V_21 ;
}
}
static int F_9 ( struct V_17 * V_18 ,
unsigned int V_20 ,
const unsigned int * * V_10 ,
unsigned int * V_23 )
{
if ( V_20 < F_2 ( V_19 ) ) {
* V_10 = V_19 [ V_20 ] . V_10 ;
* V_23 = V_19 [ V_20 ] . V_11 ;
} else {
unsigned int V_5 = V_20 - F_2 ( V_19 ) ;
* V_10 = & V_22 [ V_5 ] . V_24 ;
* V_23 = 1 ;
}
return 0 ;
}
static void F_10 ( struct V_17 * V_18 ,
struct V_25 * V_26 ,
unsigned int V_27 )
{
F_11 ( V_26 , L_1 , F_12 ( V_18 -> V_28 ) ) ;
}
static int F_13 ( struct V_29 * V_28 , struct V_30 * * V_31 ,
unsigned int * V_32 , unsigned int * V_33 ,
unsigned int V_34 )
{
unsigned int V_35 = * V_32 ;
unsigned int V_36 = * V_33 + V_34 ;
struct V_30 * V_37 ;
if ( V_35 >= V_36 )
return 0 ;
V_37 = F_14 ( * V_31 , sizeof( * V_37 ) * V_36 , V_38 ) ;
if ( ! V_37 ) {
F_15 ( V_28 , L_2 ) ;
return - V_39 ;
}
memset ( V_37 + V_35 , 0 , ( V_36 - V_35 ) * sizeof( * V_37 ) ) ;
* V_31 = V_37 ;
* V_32 = V_36 ;
return 0 ;
}
static int F_16 ( struct V_30 * * V_31 , unsigned int * V_32 ,
unsigned int * V_33 , const char * V_20 ,
const char * V_40 )
{
if ( F_17 ( * V_33 == * V_32 ) )
return - V_41 ;
( * V_31 ) [ * V_33 ] . type = V_42 ;
( * V_31 ) [ * V_33 ] . V_43 . V_44 . V_20 = V_20 ;
( * V_31 ) [ * V_33 ] . V_43 . V_44 . V_40 = V_40 ;
( * V_33 ) ++ ;
return 0 ;
}
static int F_18 ( struct V_29 * V_28 ,
struct V_30 * * V_31 ,
unsigned int * V_32 , unsigned int * V_33 ,
const char * V_20 , unsigned long * V_45 ,
unsigned int V_46 )
{
unsigned long * V_47 ;
if ( F_17 ( * V_33 == * V_32 ) )
return - V_41 ;
V_47 = F_19 ( V_45 , V_46 * sizeof( * V_47 ) ,
V_38 ) ;
if ( ! V_47 ) {
F_15 ( V_28 , L_3 ) ;
return - V_39 ;
}
( * V_31 ) [ * V_33 ] . type = V_48 ;
( * V_31 ) [ * V_33 ] . V_43 . V_45 . V_49 = V_20 ;
( * V_31 ) [ * V_33 ] . V_43 . V_45 . V_45 = V_47 ;
( * V_31 ) [ * V_33 ] . V_43 . V_45 . V_46 = V_46 ;
( * V_33 ) ++ ;
return 0 ;
}
static void F_20 ( struct V_17 * V_18 ,
struct V_30 * V_31 ,
unsigned int V_33 )
{
int V_50 ;
for ( V_50 = 0 ; V_50 < V_33 ; V_50 ++ )
if ( V_31 [ V_50 ] . type == V_48 )
F_21 ( V_31 [ V_50 ] . V_43 . V_45 . V_45 ) ;
F_21 ( V_31 ) ;
}
static int F_22 ( struct V_29 * V_28 ,
struct V_51 * V_52 ,
struct V_30 * * V_31 ,
unsigned int * V_32 ,
unsigned int * V_33 )
{
int V_53 ;
const char * V_40 ;
unsigned long * V_45 = NULL ;
unsigned int V_46 = 0 ;
unsigned int V_34 ;
struct V_54 * V_55 ;
const char * V_20 ;
V_53 = F_23 ( V_52 , L_4 , & V_40 ) ;
if ( V_53 < 0 ) {
if ( V_53 != - V_56 )
F_15 ( V_28 , L_5 ) ;
V_40 = NULL ;
}
V_53 = F_24 ( V_52 , & V_45 , & V_46 ) ;
if ( V_53 )
return V_53 ;
V_34 = 0 ;
if ( V_40 != NULL )
V_34 ++ ;
if ( V_46 )
V_34 ++ ;
V_53 = F_25 ( V_52 , L_6 ) ;
if ( V_53 < 0 ) {
F_15 ( V_28 , L_7 ) ;
goto exit;
}
V_34 *= V_53 ;
V_53 = F_13 ( V_28 , V_31 , V_32 , V_33 , V_34 ) ;
if ( V_53 < 0 )
goto exit;
F_26 (np, L_6 , prop, group) {
if ( V_40 ) {
V_53 = F_16 ( V_31 , V_32 , V_33 ,
V_20 , V_40 ) ;
if ( V_53 < 0 )
goto exit;
}
if ( V_46 ) {
V_53 = F_18 ( V_28 , V_31 , V_32 ,
V_33 , V_20 , V_45 ,
V_46 ) ;
if ( V_53 < 0 )
goto exit;
}
}
V_53 = 0 ;
exit:
F_21 ( V_45 ) ;
return V_53 ;
}
static int F_27 ( struct V_17 * V_18 ,
struct V_51 * V_57 ,
struct V_30 * * V_31 ,
unsigned int * V_33 )
{
unsigned int V_32 ;
struct V_51 * V_52 ;
int V_53 ;
V_32 = 0 ;
* V_31 = NULL ;
* V_33 = 0 ;
F_28 (np_config, np) {
V_53 = F_22 ( V_18 -> V_28 , V_52 , V_31 ,
& V_32 ,
V_33 ) ;
if ( V_53 < 0 ) {
F_20 ( V_18 , * V_31 , * V_33 ) ;
return V_53 ;
}
}
return 0 ;
}
static int F_29 ( struct V_17 * V_18 )
{
return F_2 ( V_58 ) ;
}
static const char * F_30 ( struct V_17 * V_18 ,
unsigned int V_40 )
{
return V_58 [ V_40 ] . V_21 ;
}
static int F_31 ( struct V_17 * V_18 ,
unsigned int V_40 ,
const char * const * * V_59 ,
unsigned int * const V_60 )
{
* V_59 = V_58 [ V_40 ] . V_59 ;
* V_60 = V_58 [ V_40 ] . V_61 ;
return 0 ;
}
static void F_32 ( struct V_12 * V_13 ,
unsigned int V_5 )
{
T_2 V_14 , V_62 , V_63 , V_16 ;
unsigned int V_64 , V_65 ;
unsigned long V_66 ;
V_64 = V_5 >> 5 ;
V_65 = V_5 & 0x1f ;
V_63 = ( ( ~ V_13 -> V_67 [ V_64 ] |
V_13 -> V_68 [ V_64 ] ) >> V_65 ) & 1 ;
V_14 = V_69 + 4 * ( V_5 / 30 ) ;
V_62 = V_5 % 30 ;
F_33 ( V_66 ) ;
V_16 = F_3 ( V_13 , V_14 ) ;
V_16 &= ~ F_34 ( V_62 ) ;
V_16 |= V_63 << V_62 ;
F_5 ( V_13 , V_16 , V_14 ) ;
F_35 ( V_66 ) ;
}
static void F_36 ( struct V_12 * V_13 ,
unsigned int V_5 ,
bool V_70 )
{
unsigned int V_71 , V_72 ;
T_2 V_68 ;
if ( V_5 >= V_6 )
return;
V_71 = V_5 >> 5 ;
V_72 = V_5 & 0x1f ;
F_37 ( & V_13 -> V_73 ) ;
V_68 = V_13 -> V_68 [ V_71 ] ;
V_68 &= ~ F_34 ( V_72 ) ;
if ( V_70 )
V_68 |= F_34 ( V_72 ) ;
V_13 -> V_68 [ V_71 ] = V_68 ;
F_32 ( V_13 , V_5 ) ;
F_38 ( & V_13 -> V_73 ) ;
}
static void F_39 ( struct V_12 * V_13 ,
unsigned int V_5 ,
bool V_74 )
{
unsigned int V_71 , V_72 ;
T_2 V_67 ;
if ( V_5 >= V_6 )
return;
V_71 = V_5 >> 5 ;
V_72 = V_5 & 0x1f ;
F_37 ( & V_13 -> V_73 ) ;
V_67 = V_13 -> V_67 [ V_71 ] ;
V_67 &= ~ F_34 ( V_72 ) ;
if ( V_74 )
V_67 |= F_34 ( V_72 ) ;
V_13 -> V_67 [ V_71 ] = V_67 ;
F_32 ( V_13 , V_5 ) ;
F_38 ( & V_13 -> V_73 ) ;
}
static int F_40 ( struct V_12 * V_13 ,
const struct V_75 * V_76 ,
unsigned int V_40 )
{
const int * V_77 ;
unsigned long V_66 ;
int V_44 ;
unsigned int V_78 , V_53 ;
T_2 V_14 , V_79 ;
for ( V_44 = 0 , V_77 = V_76 -> V_80 ;
V_44 < F_2 ( V_76 -> V_80 ) ; ++ V_44 , ++ V_77 ) {
V_78 = * V_77 ;
if ( V_78 == V_40 )
goto V_81;
if ( V_78 < F_2 ( V_82 ) && V_82 [ V_78 ] ) {
V_53 = F_40 ( V_13 ,
V_82 [ V_78 ] ,
V_40 ) ;
if ( ! V_53 )
goto V_81;
}
}
return - V_56 ;
V_81:
if ( V_76 -> V_83 ) {
V_79 = ( F_34 ( V_76 -> V_83 ) - 1 ) << V_76 -> V_84 ;
F_33 ( V_66 ) ;
V_14 = F_3 ( V_13 , V_76 -> V_14 ) ;
V_14 &= ~ V_79 ;
V_14 |= ( V_44 << V_76 -> V_84 ) & V_79 ;
F_5 ( V_13 , V_14 , V_76 -> V_14 ) ;
F_35 ( V_66 ) ;
}
return 0 ;
}
static int F_41 ( struct V_17 * V_18 ,
unsigned int V_40 , unsigned int V_20 )
{
struct V_12 * V_13 = F_42 ( V_18 ) ;
struct V_3 * V_4 ;
int V_53 ;
unsigned int V_85 , V_86 , V_50 , V_11 ;
const unsigned int * V_10 ;
if ( V_20 < F_2 ( V_19 ) ) {
V_4 = & V_19 [ V_20 ] ;
V_11 = V_4 -> V_11 ;
V_10 = V_4 -> V_10 ;
} else {
V_85 = V_20 - F_2 ( V_19 ) ;
V_11 = 1 ;
V_10 = & V_85 ;
}
V_86 = V_7 [ * V_10 ] ;
if ( V_86 >= V_8 ) {
if ( V_40 == V_87 )
goto V_88;
return - V_56 ;
}
V_4 = & V_9 [ V_86 ] ;
if ( V_4 -> V_89 && V_4 -> V_78 != V_40 ) {
F_15 ( V_18 -> V_28 ,
L_8 ,
V_90 , V_58 [ V_40 ] . V_21 ,
V_58 [ V_4 -> V_78 ] . V_21 ) ;
return - V_91 ;
}
F_43 ( V_18 -> V_28 , L_9 ,
V_90 , V_11 , V_4 -> V_21 , V_58 [ V_40 ] . V_21 ) ;
if ( ! V_4 -> V_89 ) {
V_4 -> V_78 = V_40 ;
V_53 = F_40 ( V_13 , & V_4 -> V_44 , V_40 ) ;
if ( V_53 )
return V_53 ;
}
V_4 -> V_89 += V_11 ;
V_88:
for ( V_50 = 0 ; V_50 < V_11 ; ++ V_50 )
F_39 ( V_13 , V_10 [ V_50 ] , true ) ;
return 0 ;
}
static void F_44 ( struct V_17 * V_18 ,
unsigned int V_40 , unsigned int V_20 )
{
struct V_12 * V_13 = F_42 ( V_18 ) ;
struct V_3 * V_4 ;
unsigned int V_85 , V_86 , V_50 , V_11 ;
const unsigned int * V_10 ;
if ( V_20 < F_2 ( V_19 ) ) {
V_4 = & V_19 [ V_20 ] ;
V_11 = V_4 -> V_11 ;
V_10 = V_4 -> V_10 ;
} else {
V_85 = V_20 - F_2 ( V_19 ) ;
V_11 = 1 ;
V_10 = & V_85 ;
}
V_86 = V_7 [ * V_10 ] ;
if ( V_86 >= V_8 ) {
if ( V_40 == V_87 )
goto V_92;
return;
}
V_4 = & V_9 [ V_86 ] ;
F_43 ( V_18 -> V_28 , L_10 ,
V_90 , V_11 , V_4 -> V_21 , V_58 [ V_40 ] . V_21 ) ;
F_17 ( V_4 -> V_89 < V_11 ) ;
V_4 -> V_89 -= V_11 ;
V_92:
for ( V_50 = 0 ; V_50 < V_11 ; ++ V_50 )
F_39 ( V_13 , V_10 [ V_50 ] , false ) ;
}
static int F_45 ( struct V_17 * V_18 ,
struct V_93 * V_94 ,
unsigned int V_5 )
{
struct V_12 * V_13 = F_42 ( V_18 ) ;
F_36 ( V_13 , V_5 , true ) ;
return 0 ;
}
static void F_46 ( struct V_17 * V_18 ,
struct V_93 * V_94 ,
unsigned int V_5 )
{
struct V_12 * V_13 = F_42 ( V_18 ) ;
F_36 ( V_13 , V_5 , false ) ;
}
static int F_47 ( struct V_17 * V_18 ,
unsigned int V_5 ,
enum V_95 V_96 ,
bool V_97 ,
T_2 * V_14 , T_2 * V_83 , T_2 * V_79 , T_2 * V_72 ,
T_2 * V_16 )
{
struct V_98 * V_99 ;
switch ( V_96 ) {
case V_100 :
case V_101 :
* V_16 = V_102 ;
break;
case V_103 :
* V_16 = V_104 ;
break;
case V_105 :
* V_16 = V_106 ;
break;
case V_107 :
* V_16 = V_108 ;
break;
default:
return - V_109 ;
} ;
V_99 = & V_98 [ V_5 ] ;
* V_14 = V_110 + 4 * V_99 -> V_71 ;
* V_72 = V_99 -> V_72 ;
* V_83 = 2 ;
* V_79 = ( F_34 ( * V_83 ) - 1 ) << * V_72 ;
return 0 ;
}
static int F_48 ( struct V_17 * V_18 ,
unsigned int V_5 , unsigned long * V_111 )
{
struct V_12 * V_13 = F_42 ( V_18 ) ;
enum V_95 V_96 = F_49 ( * V_111 ) ;
int V_53 ;
T_2 V_14 , V_83 , V_79 , V_72 , V_16 , V_112 , V_113 ;
V_53 = F_47 ( V_18 , V_5 , V_96 , true ,
& V_14 , & V_83 , & V_79 , & V_72 , & V_16 ) ;
if ( V_53 < 0 )
return V_53 ;
V_112 = F_3 ( V_13 , V_14 ) ;
V_113 = ( ( V_112 & V_79 ) >> V_72 ) == V_16 ;
if ( ! V_113 )
return - V_56 ;
* V_111 = F_50 ( V_96 , V_113 ) ;
return 0 ;
}
static int F_51 ( struct V_17 * V_18 ,
unsigned int V_5 , unsigned long V_111 )
{
struct V_12 * V_13 = F_42 ( V_18 ) ;
enum V_95 V_96 = F_49 ( V_111 ) ;
unsigned int V_113 = F_52 ( V_111 ) ;
int V_53 ;
T_2 V_14 , V_83 , V_79 , V_72 , V_16 , V_112 ;
unsigned long V_66 ;
F_43 ( V_18 -> V_28 , L_11 ,
V_90 , V_22 [ V_5 ] . V_21 , V_111 ) ;
V_53 = F_47 ( V_18 , V_5 , V_96 , true ,
& V_14 , & V_83 , & V_79 , & V_72 , & V_16 ) ;
if ( V_53 < 0 )
return V_53 ;
if ( V_113 > 1 ) {
F_43 ( V_18 -> V_28 , L_12 ,
V_90 , V_113 ) ;
return - V_56 ;
}
F_33 ( V_66 ) ;
V_112 = F_3 ( V_13 , V_14 ) ;
V_112 &= ~ V_79 ;
if ( V_113 )
V_112 |= V_16 << V_72 ;
F_5 ( V_13 , V_112 , V_14 ) ;
F_35 ( V_66 ) ;
return 0 ;
}
static int F_53 ( struct V_17 * V_18 ,
const struct V_3 * V_1 ,
enum V_95 V_96 ,
bool V_97 ,
T_2 * V_14 , T_2 * V_83 , T_2 * V_79 , T_2 * V_72 ,
const int * * V_31 )
{
if ( ! V_1 -> V_114 ) {
if ( V_97 )
F_43 ( V_18 -> V_28 ,
L_13 ,
V_90 , V_1 -> V_21 ) ;
return - V_109 ;
}
switch ( V_96 ) {
case V_115 :
* V_14 = V_116 ;
* V_83 = 1 ;
* V_31 = V_117 ;
break;
case V_118 :
* V_14 = V_119 ;
* V_83 = 2 ;
* V_31 = V_120 ;
break;
default:
return - V_109 ;
} ;
* V_72 = V_1 -> V_121 * * V_83 ;
* V_79 = ( F_34 ( * V_83 ) - 1 ) << * V_72 ;
return 0 ;
}
static int F_54 ( struct V_17 * V_18 ,
unsigned int V_20 ,
unsigned long * V_111 )
{
struct V_12 * V_13 = F_42 ( V_18 ) ;
const struct V_3 * V_1 ;
enum V_95 V_96 = F_49 ( * V_111 ) ;
int V_53 , V_113 ;
unsigned int V_5 ;
T_2 V_14 , V_83 , V_79 , V_72 , V_16 ;
const int * V_31 ;
if ( V_20 >= F_2 ( V_19 ) ) {
V_5 = V_20 - F_2 ( V_19 ) ;
return F_48 ( V_18 , V_5 , V_111 ) ;
}
V_1 = & V_19 [ V_20 ] ;
if ( V_1 -> V_11 == 1 ) {
V_5 = V_1 -> V_10 [ 0 ] ;
V_53 = F_48 ( V_18 , V_5 , V_111 ) ;
if ( V_53 != - V_109 )
return V_53 ;
}
V_53 = F_53 ( V_18 , V_1 , V_96 , true ,
& V_14 , & V_83 , & V_79 , & V_72 , & V_31 ) ;
if ( V_53 < 0 )
return V_53 ;
V_16 = F_3 ( V_13 , V_14 ) ;
V_113 = V_31 [ ( V_16 & V_79 ) >> V_72 ] ;
if ( V_113 < 0 )
return V_113 ;
* V_111 = F_50 ( V_96 , V_113 ) ;
return 0 ;
}
static int F_55 ( struct V_17 * V_18 ,
unsigned int V_20 , unsigned long V_111 )
{
struct V_12 * V_13 = F_42 ( V_18 ) ;
const struct V_3 * V_1 ;
enum V_95 V_96 = F_49 ( V_111 ) ;
unsigned int V_113 , V_5 , V_50 ;
const unsigned int * V_122 ;
int V_53 ;
T_2 V_14 , V_83 , V_79 , V_72 , V_16 ;
unsigned long V_66 ;
const int * V_31 ;
if ( V_20 >= F_2 ( V_19 ) ) {
V_5 = V_20 - F_2 ( V_19 ) ;
return F_51 ( V_18 , V_5 , V_111 ) ;
}
V_1 = & V_19 [ V_20 ] ;
if ( V_1 -> V_11 == 1 ) {
V_5 = V_1 -> V_10 [ 0 ] ;
V_53 = F_51 ( V_18 , V_5 , V_111 ) ;
if ( V_53 != - V_109 )
return V_53 ;
}
F_43 ( V_18 -> V_28 , L_14 ,
V_90 , V_1 -> V_21 , V_111 ) ;
V_53 = F_53 ( V_18 , V_1 , V_96 , true ,
& V_14 , & V_83 , & V_79 , & V_72 , & V_31 ) ;
if ( V_53 < 0 ) {
for ( V_50 = 0 , V_122 = V_1 -> V_10 ; V_50 < V_1 -> V_11 ; ++ V_50 , ++ V_122 ) {
V_53 = F_51 ( V_18 , * V_122 , V_111 ) ;
if ( V_53 )
return V_53 ;
}
return 0 ;
}
V_113 = F_52 ( V_111 ) ;
for ( V_50 = 0 ; V_50 < F_34 ( V_83 ) ; ++ V_50 ) {
if ( V_31 [ V_50 ] == V_113 || ( V_31 [ V_50 ] == - V_56 && ! V_113 ) ) {
F_33 ( V_66 ) ;
V_16 = F_3 ( V_13 , V_14 ) ;
V_16 &= ~ V_79 ;
V_16 |= V_50 << V_72 ;
F_5 ( V_13 , V_16 , V_14 ) ;
F_35 ( V_66 ) ;
return 0 ;
}
}
F_43 ( V_18 -> V_28 , L_15 ,
V_90 , V_113 ) ;
return - V_56 ;
}
static int F_56 ( struct V_123 * V_124 )
{
struct V_12 * V_13 ;
struct V_125 * V_126 ;
V_13 = F_57 ( & V_124 -> V_28 , sizeof( * V_13 ) , V_38 ) ;
if ( ! V_13 ) {
F_15 ( & V_124 -> V_28 , L_16 ) ;
return - V_39 ;
}
V_13 -> V_28 = & V_124 -> V_28 ;
F_58 ( & V_13 -> V_73 ) ;
V_127 . V_21 = F_12 ( & V_124 -> V_28 ) ;
V_127 . V_10 = V_22 ;
V_127 . V_11 = F_2 ( V_22 ) ;
V_126 = F_59 ( V_124 , V_128 , 0 ) ;
if ( ! V_126 ) {
F_15 ( & V_124 -> V_28 , L_17 ) ;
return - V_129 ;
}
if ( ! F_60 ( & V_124 -> V_28 , V_126 -> V_130 ,
F_61 ( V_126 ) ,
F_12 ( & V_124 -> V_28 ) ) ) {
F_15 ( & V_124 -> V_28 ,
L_18 ) ;
return - V_129 ;
}
V_13 -> V_15 = F_62 ( & V_124 -> V_28 , V_126 -> V_130 ,
F_61 ( V_126 ) ) ;
if ( ! V_13 -> V_15 ) {
F_15 ( & V_124 -> V_28 , L_19 ) ;
return - V_129 ;
}
V_13 -> V_131 = F_63 ( & V_127 , & V_124 -> V_28 , V_13 ) ;
if ( ! V_13 -> V_131 ) {
F_15 ( & V_124 -> V_28 , L_20 ) ;
return - V_129 ;
}
F_64 ( V_124 , V_13 ) ;
F_65 ( & V_124 -> V_28 , L_21 ) ;
return 0 ;
}
static int F_66 ( struct V_123 * V_124 )
{
struct V_12 * V_13 = F_67 ( V_124 ) ;
F_68 ( V_13 -> V_131 ) ;
return 0 ;
}
static int T_1 F_69 ( void )
{
F_1 () ;
return F_70 ( & V_132 ) ;
}
static void T_3 F_71 ( void )
{
F_72 ( & V_132 ) ;
}
