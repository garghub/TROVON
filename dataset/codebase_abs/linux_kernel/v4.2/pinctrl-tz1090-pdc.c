static inline T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 ) ;
}
static inline void F_3 ( struct V_1 * V_2 , T_1 V_5 , T_1 V_3 )
{
F_4 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static int F_5 ( struct V_6 * V_7 )
{
return F_6 ( V_8 ) ;
}
static const char * F_7 ( struct V_6 * V_9 ,
unsigned int V_10 )
{
return V_8 [ V_10 ] . V_11 ;
}
static int F_8 ( struct V_6 * V_7 ,
unsigned int V_10 ,
const unsigned int * * V_12 ,
unsigned int * V_13 )
{
* V_12 = V_8 [ V_10 ] . V_12 ;
* V_13 = V_8 [ V_10 ] . V_14 ;
return 0 ;
}
static void F_9 ( struct V_6 * V_7 ,
struct V_15 * V_16 ,
unsigned int V_17 )
{
F_10 ( V_16 , L_1 , F_11 ( V_7 -> V_18 ) ) ;
}
static int F_12 ( struct V_19 * V_18 , struct V_20 * * V_21 ,
unsigned int * V_22 , unsigned int * V_23 ,
unsigned int V_24 )
{
unsigned int V_25 = * V_22 ;
unsigned int V_26 = * V_23 + V_24 ;
struct V_20 * V_27 ;
if ( V_25 >= V_26 )
return 0 ;
V_27 = F_13 ( * V_21 , sizeof( * V_27 ) * V_26 , V_28 ) ;
if ( ! V_27 ) {
F_14 ( V_18 , L_2 ) ;
return - V_29 ;
}
memset ( V_27 + V_25 , 0 , ( V_26 - V_25 ) * sizeof( * V_27 ) ) ;
* V_21 = V_27 ;
* V_22 = V_26 ;
return 0 ;
}
static int F_15 ( struct V_20 * * V_21 , unsigned int * V_22 ,
unsigned int * V_23 , const char * V_10 ,
const char * V_30 )
{
if ( F_16 ( * V_23 == * V_22 ) )
return - V_31 ;
( * V_21 ) [ * V_23 ] . type = V_32 ;
( * V_21 ) [ * V_23 ] . V_33 . V_34 . V_10 = V_10 ;
( * V_21 ) [ * V_23 ] . V_33 . V_34 . V_30 = V_30 ;
( * V_23 ) ++ ;
return 0 ;
}
static int F_17 ( const char * V_35 )
{
unsigned int V_10 ;
for ( V_10 = 0 ; V_10 < F_6 ( V_8 ) ; ++ V_10 )
if ( ! strcmp ( V_8 [ V_10 ] . V_11 , V_35 ) )
return V_10 ;
return - V_36 ;
}
static int F_18 ( struct V_19 * V_18 ,
struct V_20 * * V_21 ,
unsigned int * V_22 , unsigned int * V_23 ,
const char * V_10 , unsigned long * V_37 ,
unsigned int V_38 )
{
unsigned long * V_39 ;
enum V_40 type ;
if ( F_16 ( * V_23 == * V_22 ) )
return - V_31 ;
V_39 = F_19 ( V_37 , V_38 * sizeof( * V_39 ) ,
V_28 ) ;
if ( ! V_39 ) {
F_14 ( V_18 , L_3 ) ;
return - V_29 ;
}
if ( F_17 ( V_10 ) >= 0 )
type = V_41 ;
else
type = V_42 ;
( * V_21 ) [ * V_23 ] . type = type ;
( * V_21 ) [ * V_23 ] . V_33 . V_37 . V_43 = V_10 ;
( * V_21 ) [ * V_23 ] . V_33 . V_37 . V_37 = V_39 ;
( * V_21 ) [ * V_23 ] . V_33 . V_37 . V_38 = V_38 ;
( * V_23 ) ++ ;
return 0 ;
}
static void F_20 ( struct V_6 * V_7 ,
struct V_20 * V_21 ,
unsigned int V_23 )
{
int V_44 ;
for ( V_44 = 0 ; V_44 < V_23 ; V_44 ++ )
if ( V_21 [ V_44 ] . type == V_41 )
F_21 ( V_21 [ V_44 ] . V_33 . V_37 . V_37 ) ;
F_21 ( V_21 ) ;
}
static int F_22 ( struct V_19 * V_18 ,
struct V_45 * V_46 ,
struct V_20 * * V_21 ,
unsigned int * V_22 ,
unsigned int * V_23 )
{
int V_47 ;
const char * V_30 ;
unsigned long * V_37 = NULL ;
unsigned int V_38 = 0 ;
unsigned int V_24 ;
struct V_48 * V_49 ;
const char * V_10 ;
V_47 = F_23 ( V_46 , L_4 , & V_30 ) ;
if ( V_47 < 0 ) {
if ( V_47 != - V_36 )
F_14 ( V_18 ,
L_5 ) ;
V_30 = NULL ;
}
V_47 = F_24 ( V_46 , NULL , & V_37 , & V_38 ) ;
if ( V_47 )
return V_47 ;
V_24 = 0 ;
if ( V_30 != NULL )
V_24 ++ ;
if ( V_38 )
V_24 ++ ;
V_47 = F_25 ( V_46 , L_6 ) ;
if ( V_47 < 0 ) {
F_14 ( V_18 , L_7 ) ;
goto exit;
}
V_24 *= V_47 ;
V_47 = F_12 ( V_18 , V_21 , V_22 , V_23 , V_24 ) ;
if ( V_47 < 0 )
goto exit;
F_26 (np, L_6 , prop, group) {
if ( V_30 ) {
V_47 = F_15 ( V_21 , V_22 , V_23 ,
V_10 , V_30 ) ;
if ( V_47 < 0 )
goto exit;
}
if ( V_38 ) {
V_47 = F_18 ( V_18 , V_21 , V_22 ,
V_23 , V_10 , V_37 ,
V_38 ) ;
if ( V_47 < 0 )
goto exit;
}
}
V_47 = 0 ;
exit:
F_21 ( V_37 ) ;
return V_47 ;
}
static int F_27 ( struct V_6 * V_7 ,
struct V_45 * V_50 ,
struct V_20 * * V_21 ,
unsigned int * V_23 )
{
unsigned int V_22 ;
struct V_45 * V_46 ;
int V_47 ;
V_22 = 0 ;
* V_21 = NULL ;
* V_23 = 0 ;
F_28 (np_config, np) {
V_47 = F_22 ( V_7 -> V_18 , V_46 ,
V_21 , & V_22 ,
V_23 ) ;
if ( V_47 < 0 ) {
F_20 ( V_7 , * V_21 ,
* V_23 ) ;
return V_47 ;
}
}
return 0 ;
}
static int F_29 ( struct V_6 * V_7 )
{
return F_6 ( V_51 ) ;
}
static const char * F_30 ( struct V_6 * V_7 ,
unsigned int V_30 )
{
return V_51 [ V_30 ] . V_11 ;
}
static int F_31 ( struct V_6 * V_7 ,
unsigned int V_30 ,
const char * const * * V_52 ,
unsigned int * const V_53 )
{
* V_52 = V_51 [ V_30 ] . V_52 ;
* V_53 = V_51 [ V_30 ] . V_54 ;
return 0 ;
}
static void F_32 ( struct V_1 * V_2 ,
const struct V_55 * V_56 )
{
T_1 V_3 , V_57 ;
unsigned int V_58 = V_56 -> V_12 [ 0 ] ;
unsigned long V_59 ;
V_57 = ( ( V_2 -> V_60 & ~ V_2 -> V_61 ) >> V_58 ) & 1 ;
F_33 ( V_59 ) ;
V_3 = F_1 ( V_2 , V_56 -> V_3 ) ;
V_3 &= ~ F_34 ( V_56 -> V_62 ) ;
V_3 |= V_57 << V_56 -> V_62 ;
F_3 ( V_2 , V_3 , V_56 -> V_3 ) ;
F_35 ( V_59 ) ;
}
static int F_36 ( struct V_6 * V_7 ,
unsigned int V_30 ,
unsigned int V_10 )
{
struct V_1 * V_2 = F_37 ( V_7 ) ;
const struct V_55 * V_56 = & V_8 [ V_10 ] ;
F_38 ( V_7 -> V_18 , L_8 ,
V_63 ,
V_30 , V_51 [ V_30 ] . V_11 ,
V_10 , V_8 [ V_10 ] . V_11 ) ;
if ( V_56 -> V_64 )
return - V_36 ;
if ( V_30 != V_56 -> V_65 )
return - V_36 ;
F_39 ( & V_2 -> V_66 ) ;
V_2 -> V_60 |= F_34 ( V_56 -> V_12 [ 0 ] ) ;
F_32 ( V_2 , V_56 ) ;
F_40 ( & V_2 -> V_66 ) ;
return 0 ;
}
static const struct V_55 * F_41 (
struct V_1 * V_2 ,
unsigned int V_67 )
{
const struct V_55 * V_56 ;
unsigned int V_10 ;
V_56 = V_8 ;
for ( V_10 = 0 ; V_10 < F_6 ( V_8 ) ; ++ V_10 , ++ V_56 ) {
if ( V_56 -> V_64 )
continue;
if ( V_56 -> V_12 [ 0 ] == V_67 )
return V_56 ;
}
return NULL ;
}
static int F_42 (
struct V_6 * V_7 ,
struct V_68 * V_69 ,
unsigned int V_67 )
{
struct V_1 * V_2 = F_37 ( V_7 ) ;
const struct V_55 * V_56 = F_41 ( V_2 , V_67 ) ;
if ( V_56 ) {
F_39 ( & V_2 -> V_66 ) ;
V_2 -> V_61 |= F_34 ( V_67 ) ;
F_32 ( V_2 , V_56 ) ;
F_40 ( & V_2 -> V_66 ) ;
}
return 0 ;
}
static void F_43 (
struct V_6 * V_7 ,
struct V_68 * V_69 ,
unsigned int V_67 )
{
struct V_1 * V_2 = F_37 ( V_7 ) ;
const struct V_55 * V_56 = F_41 ( V_2 , V_67 ) ;
if ( V_56 ) {
F_39 ( & V_2 -> V_66 ) ;
V_2 -> V_61 &= ~ F_34 ( V_67 ) ;
F_32 ( V_2 , V_56 ) ;
F_40 ( & V_2 -> V_66 ) ;
}
}
static int F_44 ( struct V_6 * V_7 ,
unsigned int V_67 ,
enum V_70 V_71 ,
bool V_72 ,
T_1 * V_3 , T_1 * V_73 , T_1 * V_74 , T_1 * V_75 ,
T_1 * V_5 )
{
switch ( V_71 ) {
case V_76 :
case V_77 :
* V_5 = V_78 ;
break;
case V_79 :
* V_5 = V_80 ;
break;
case V_81 :
* V_5 = V_82 ;
break;
case V_83 :
* V_5 = V_84 ;
break;
default:
return - V_85 ;
} ;
* V_3 = V_86 ;
* V_75 = V_87 + V_67 * 2 ;
* V_73 = 2 ;
* V_74 = ( F_34 ( * V_73 ) - 1 ) << * V_75 ;
return 0 ;
}
static int F_45 ( struct V_6 * V_7 ,
unsigned int V_67 , unsigned long * V_88 )
{
struct V_1 * V_2 = F_37 ( V_7 ) ;
enum V_70 V_71 = F_46 ( * V_88 ) ;
int V_47 ;
T_1 V_3 , V_73 , V_74 , V_75 , V_5 , V_89 , V_90 ;
V_47 = F_44 ( V_7 , V_67 , V_71 , true ,
& V_3 , & V_73 , & V_74 , & V_75 , & V_5 ) ;
if ( V_47 < 0 )
return V_47 ;
V_89 = F_1 ( V_2 , V_3 ) ;
V_90 = ( ( V_89 & V_74 ) >> V_75 ) == V_5 ;
if ( ! V_90 )
return - V_36 ;
* V_88 = F_47 ( V_71 , V_90 ) ;
return 0 ;
}
static int F_48 ( struct V_6 * V_7 ,
unsigned int V_67 , unsigned long * V_37 ,
unsigned V_38 )
{
struct V_1 * V_2 = F_37 ( V_7 ) ;
enum V_70 V_71 ;
unsigned int V_90 ;
int V_47 ;
T_1 V_3 , V_73 , V_74 , V_75 , V_5 , V_89 ;
unsigned long V_59 ;
int V_44 ;
for ( V_44 = 0 ; V_44 < V_38 ; V_44 ++ ) {
V_71 = F_46 ( V_37 [ V_44 ] ) ;
V_90 = F_49 ( V_37 [ V_44 ] ) ;
F_38 ( V_7 -> V_18 , L_9 ,
V_63 , V_91 [ V_67 ] . V_11 , V_37 [ V_44 ] ) ;
V_47 = F_44 ( V_7 , V_67 , V_71 , true ,
& V_3 , & V_73 , & V_74 , & V_75 , & V_5 ) ;
if ( V_47 < 0 )
return V_47 ;
if ( V_90 > 1 ) {
F_38 ( V_7 -> V_18 , L_10 ,
V_63 , V_90 ) ;
return - V_36 ;
}
F_33 ( V_59 ) ;
V_89 = F_1 ( V_2 , V_3 ) ;
V_89 &= ~ V_74 ;
if ( V_90 )
V_89 |= V_5 << V_75 ;
F_3 ( V_2 , V_89 , V_3 ) ;
F_35 ( V_59 ) ;
}
return 0 ;
}
static int F_50 ( struct V_6 * V_7 ,
const struct V_55 * V_92 ,
enum V_70 V_71 ,
bool V_72 , T_1 * V_3 , T_1 * V_73 ,
T_1 * V_74 , T_1 * V_75 , const int * * V_21 )
{
if ( ! V_92 -> V_64 ) {
if ( V_72 )
F_38 ( V_7 -> V_18 ,
L_11 ,
V_63 , V_92 -> V_11 ) ;
return - V_85 ;
}
* V_3 = V_86 ;
switch ( V_71 ) {
case V_93 :
* V_75 = V_94 ;
* V_73 = 1 ;
* V_21 = V_95 ;
break;
case V_96 :
* V_75 = V_97 ;
* V_73 = 2 ;
* V_21 = V_98 ;
break;
case V_99 :
* V_75 = V_100 ;
* V_73 = 1 ;
* V_21 = V_95 ;
break;
default:
return - V_85 ;
} ;
* V_74 = ( F_34 ( * V_73 ) - 1 ) << * V_75 ;
return 0 ;
}
static int F_51 ( struct V_6 * V_7 ,
unsigned int V_10 ,
unsigned long * V_88 )
{
struct V_1 * V_2 = F_37 ( V_7 ) ;
const struct V_55 * V_92 = & V_8 [ V_10 ] ;
enum V_70 V_71 = F_46 ( * V_88 ) ;
int V_47 , V_90 ;
T_1 V_3 , V_73 , V_74 , V_75 , V_5 ;
const int * V_21 ;
V_47 = F_50 ( V_7 , V_92 , V_71 , true ,
& V_3 , & V_73 , & V_74 , & V_75 , & V_21 ) ;
if ( V_47 < 0 )
return V_47 ;
V_5 = F_1 ( V_2 , V_3 ) ;
V_90 = V_21 [ ( V_5 & V_74 ) >> V_75 ] ;
if ( V_90 < 0 )
return V_90 ;
* V_88 = F_47 ( V_71 , V_90 ) ;
return 0 ;
}
static int F_52 ( struct V_6 * V_7 ,
unsigned int V_10 ,
unsigned long * V_37 ,
unsigned V_38 )
{
struct V_1 * V_2 = F_37 ( V_7 ) ;
const struct V_55 * V_92 = & V_8 [ V_10 ] ;
enum V_70 V_71 ;
const unsigned int * V_101 ;
unsigned int V_44 ;
int V_47 , V_90 ;
T_1 V_3 , V_73 , V_74 , V_75 , V_5 ;
unsigned long V_59 ;
const int * V_21 ;
int V_102 ;
for ( V_102 = 0 ; V_102 < V_38 ; V_102 ++ ) {
V_71 = F_46 ( V_37 [ V_102 ] ) ;
F_38 ( V_7 -> V_18 , L_12 ,
V_63 , V_92 -> V_11 , V_37 [ V_102 ] ) ;
V_47 = F_50 ( V_7 , V_92 , V_71 , true ,
& V_3 , & V_73 , & V_74 , & V_75 ,
& V_21 ) ;
if ( V_47 < 0 ) {
for ( V_44 = 0 , V_101 = V_92 -> V_12 ; V_44 < V_92 -> V_14 ; ++ V_44 , ++ V_101 ) {
V_47 = F_48 ( V_7 , * V_101 ,
V_37 , V_38 ) ;
if ( V_47 )
return V_47 ;
}
return 0 ;
}
V_90 = F_49 ( V_37 [ V_102 ] ) ;
for ( V_44 = 0 ; V_44 < F_34 ( V_73 ) ; ++ V_44 ) {
if ( V_21 [ V_44 ] == V_90 || ( V_21 [ V_44 ] == - V_36 && ! V_90 ) ) {
F_33 ( V_59 ) ;
V_5 = F_1 ( V_2 , V_3 ) ;
V_5 &= ~ V_74 ;
V_5 |= V_44 << V_75 ;
F_3 ( V_2 , V_5 , V_3 ) ;
F_35 ( V_59 ) ;
goto V_103;
}
}
F_38 ( V_7 -> V_18 , L_13 ,
V_63 , V_90 ) ;
return 0 ;
V_103:
;
}
return 0 ;
}
static int F_53 ( struct V_104 * V_105 )
{
struct V_1 * V_2 ;
struct V_106 * V_107 ;
V_2 = F_54 ( & V_105 -> V_18 , sizeof( * V_2 ) , V_28 ) ;
if ( ! V_2 ) {
F_14 ( & V_105 -> V_18 , L_14 ) ;
return - V_29 ;
}
V_2 -> V_18 = & V_105 -> V_18 ;
F_55 ( & V_2 -> V_66 ) ;
V_108 . V_11 = F_11 ( & V_105 -> V_18 ) ;
V_108 . V_12 = V_91 ;
V_108 . V_14 = F_6 ( V_91 ) ;
V_107 = F_56 ( V_105 , V_109 , 0 ) ;
V_2 -> V_4 = F_57 ( & V_105 -> V_18 , V_107 ) ;
if ( F_58 ( V_2 -> V_4 ) )
return F_59 ( V_2 -> V_4 ) ;
V_2 -> V_9 = F_60 ( & V_108 , & V_105 -> V_18 , V_2 ) ;
if ( F_58 ( V_2 -> V_9 ) ) {
F_14 ( & V_105 -> V_18 , L_15 ) ;
return F_59 ( V_2 -> V_9 ) ;
}
F_61 ( V_105 , V_2 ) ;
F_62 ( & V_105 -> V_18 , L_16 ) ;
return 0 ;
}
static int F_63 ( struct V_104 * V_105 )
{
struct V_1 * V_2 = F_64 ( V_105 ) ;
F_65 ( V_2 -> V_9 ) ;
return 0 ;
}
static int T_2 F_66 ( void )
{
return F_67 ( & V_110 ) ;
}
static void T_3 F_68 ( void )
{
F_69 ( & V_110 ) ;
}
