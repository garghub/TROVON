static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_2 ) ;
}
static int F_3 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = F_4 ( V_5 ) ;
return V_7 -> V_8 ;
}
static const char * F_5 ( struct V_4 * V_5 ,
unsigned V_9 )
{
struct V_6 * V_7 = F_4 ( V_5 ) ;
return V_7 -> V_10 [ V_9 ] . V_11 ;
}
static int F_6 ( struct V_4 * V_5 ,
unsigned V_9 ,
const unsigned * * V_12 ,
unsigned * V_13 )
{
struct V_6 * V_7 = F_4 ( V_5 ) ;
* V_12 = V_7 -> V_10 [ V_9 ] . V_12 ;
* V_13 = V_7 -> V_10 [ V_9 ] . V_13 ;
return 0 ;
}
static int F_7 ( struct V_14 * V_15 , struct V_16 * * V_17 ,
unsigned * V_18 , unsigned * V_19 ,
unsigned V_20 )
{
unsigned V_21 = * V_18 ;
unsigned V_22 = * V_19 + V_20 ;
struct V_16 * V_23 ;
if ( V_21 >= V_22 )
return 0 ;
V_23 = F_8 ( * V_17 , sizeof( * V_23 ) * V_22 , V_24 ) ;
if ( ! V_23 ) {
F_9 ( V_15 , L_1 ) ;
return - V_25 ;
}
memset ( V_23 + V_21 , 0 , ( V_22 - V_21 ) * sizeof( * V_23 ) ) ;
* V_17 = V_23 ;
* V_18 = V_22 ;
return 0 ;
}
static int F_10 ( struct V_16 * * V_17 , unsigned * V_18 ,
unsigned * V_19 , const char * V_9 ,
const char * V_26 )
{
if ( F_11 ( * V_19 == * V_18 ) )
return - V_27 ;
( * V_17 ) [ * V_19 ] . type = V_28 ;
( * V_17 ) [ * V_19 ] . V_29 . V_30 . V_9 = V_9 ;
( * V_17 ) [ * V_19 ] . V_29 . V_30 . V_26 = V_26 ;
( * V_19 ) ++ ;
return 0 ;
}
static int F_12 ( struct V_14 * V_15 , struct V_16 * * V_17 ,
unsigned * V_18 , unsigned * V_19 ,
const char * V_9 , unsigned long * V_31 ,
unsigned V_32 )
{
unsigned long * V_33 ;
if ( F_11 ( * V_19 == * V_18 ) )
return - V_27 ;
V_33 = F_13 ( V_31 , V_32 * sizeof( * V_33 ) ,
V_24 ) ;
if ( ! V_33 ) {
F_9 ( V_15 , L_2 ) ;
return - V_25 ;
}
( * V_17 ) [ * V_19 ] . type = V_34 ;
( * V_17 ) [ * V_19 ] . V_29 . V_31 . V_35 = V_9 ;
( * V_17 ) [ * V_19 ] . V_29 . V_31 . V_31 = V_33 ;
( * V_17 ) [ * V_19 ] . V_29 . V_31 . V_32 = V_32 ;
( * V_19 ) ++ ;
return 0 ;
}
static int F_14 ( struct V_14 * V_15 , unsigned long * * V_31 ,
unsigned * V_32 , unsigned long V_36 )
{
unsigned V_21 = * V_32 ;
unsigned V_22 = V_21 + 1 ;
unsigned long * V_37 ;
V_37 = F_8 ( * V_31 , sizeof( * V_37 ) * V_22 ,
V_24 ) ;
if ( ! V_37 ) {
F_9 ( V_15 , L_3 ) ;
return - V_25 ;
}
V_37 [ V_21 ] = V_36 ;
* V_31 = V_37 ;
* V_32 = V_22 ;
return 0 ;
}
static void F_15 ( struct V_4 * V_5 ,
struct V_16 * V_17 ,
unsigned V_19 )
{
int V_38 ;
for ( V_38 = 0 ; V_38 < V_19 ; V_38 ++ )
if ( V_17 [ V_38 ] . type == V_34 )
F_16 ( V_17 [ V_38 ] . V_29 . V_31 . V_31 ) ;
F_16 ( V_17 ) ;
}
static int F_17 ( struct V_6 * V_39 ,
struct V_14 * V_15 ,
struct V_40 * V_41 ,
struct V_16 * * V_17 ,
unsigned * V_18 ,
unsigned * V_19 )
{
int V_42 , V_38 ;
T_1 V_43 ;
unsigned long V_36 ;
unsigned long * V_31 = NULL ;
unsigned V_32 = 0 ;
unsigned V_20 ;
struct V_44 * V_45 ;
const char * V_9 ;
bool V_46 = false ;
V_42 = F_18 ( V_41 , L_4 , & V_43 ) ;
if ( ! V_42 )
V_46 = true ;
for ( V_38 = 0 ; V_38 < F_19 ( V_47 ) ; V_38 ++ ) {
V_42 = F_18 ( V_41 , V_47 [ V_38 ] . V_44 , & V_43 ) ;
if ( ! V_42 ) {
V_36 = F_20 ( V_47 [ V_38 ] . V_48 , V_43 ) ;
V_42 = F_14 ( V_15 , & V_31 , & V_32 , V_36 ) ;
if ( V_42 < 0 )
goto exit;
} else if ( V_42 != - V_49 ) {
F_9 ( V_15 , L_5 ,
V_47 [ V_38 ] . V_44 ) ;
}
}
V_20 = 0 ;
if ( V_46 )
V_20 ++ ;
if ( V_32 )
V_20 ++ ;
V_42 = F_21 ( V_41 , L_6 ) ;
if ( V_42 < 0 ) {
F_9 ( V_15 , L_7 ) ;
goto exit;
}
V_20 *= V_42 ;
V_42 = F_7 ( V_15 , V_17 , V_18 , V_19 , V_20 ) ;
if ( V_42 < 0 )
goto exit;
F_22 (np, L_6 , prop, group) {
if ( V_46 ) {
V_42 = F_10 ( V_17 , V_18 ,
V_19 , V_9 , V_41 -> V_50 ) ;
if ( V_42 < 0 )
goto exit;
}
if ( V_32 ) {
V_42 = F_12 ( V_15 , V_17 , V_18 ,
V_19 , V_9 , V_31 ,
V_32 ) ;
if ( V_42 < 0 )
goto exit;
}
}
V_42 = 0 ;
exit:
F_16 ( V_31 ) ;
return V_42 ;
}
static int F_23 ( struct V_4 * V_5 ,
struct V_40 * V_51 ,
struct V_16 * * V_17 ,
unsigned * V_19 )
{
struct V_6 * V_39 ;
unsigned V_18 ;
struct V_40 * V_41 ;
int V_42 ;
V_39 = F_4 ( V_5 ) ;
V_18 = 0 ;
* V_17 = NULL ;
* V_19 = 0 ;
if ( ! F_24 ( V_51 ) )
return F_17 ( V_39 , V_5 -> V_15 ,
V_51 , V_17 ,
& V_18 ,
V_19 ) ;
F_25 (np_config, np) {
V_42 = F_17 ( V_39 , V_5 -> V_15 , V_41 , V_17 ,
& V_18 , V_19 ) ;
if ( V_42 < 0 ) {
F_15 ( V_5 , * V_17 , * V_19 ) ;
return V_42 ;
}
}
return 0 ;
}
static int F_26 ( struct V_4 * V_5 )
{
struct V_6 * V_39 ;
V_39 = F_4 ( V_5 ) ;
return V_39 -> V_52 ;
}
static const char * F_27 ( struct V_4 * V_5 ,
unsigned V_53 )
{
struct V_6 * V_39 ;
V_39 = F_4 ( V_5 ) ;
return V_39 -> V_54 [ V_53 ] . V_11 ;
}
static int F_28 ( struct V_4 * V_5 ,
unsigned V_53 , const char * const * * V_55 ,
unsigned * const V_56 )
{
struct V_6 * V_39 ;
V_39 = F_4 ( V_5 ) ;
* V_55 = V_39 -> V_54 [ V_53 ] . V_55 ;
* V_56 = V_39 -> V_54 [ V_53 ] . V_56 ;
return 0 ;
}
static void F_29 ( struct V_6 * V_39 ,
unsigned V_57 , void T_2 * * V_58 , T_1 * V_59 ,
struct V_1 * * V_60 )
{
struct V_1 * V_61 ;
V_61 = V_39 -> V_62 ;
while ( ( V_57 >= V_61 -> V_63 ) &&
( ( V_61 -> V_63 + V_61 -> V_64 - 1 ) < V_57 ) )
V_61 ++ ;
* V_58 = V_39 -> V_65 + V_61 -> V_66 ;
* V_59 = V_57 - V_61 -> V_63 ;
if ( V_60 )
* V_60 = V_61 ;
}
static void F_30 ( struct V_4 * V_5 , unsigned V_53 ,
unsigned V_9 , bool V_67 )
{
struct V_6 * V_39 ;
const struct V_68 * type ;
struct V_1 * V_60 ;
void T_2 * V_58 ;
T_1 V_69 , V_70 , V_29 , V_71 ;
unsigned long V_72 ;
const struct V_73 * V_74 ;
const struct V_75 * V_76 ;
V_39 = F_4 ( V_5 ) ;
V_74 = & V_39 -> V_54 [ V_53 ] ;
V_76 = & V_39 -> V_10 [ V_9 ] ;
F_29 ( V_39 , V_76 -> V_12 [ 0 ] - V_39 -> V_63 ,
& V_58 , & V_71 , & V_60 ) ;
type = V_60 -> type ;
V_69 = ( 1 << type -> V_77 [ V_78 ] ) - 1 ;
V_70 = V_71 * type -> V_77 [ V_78 ] ;
if ( V_70 >= 32 ) {
V_70 -= 32 ;
V_58 += 4 ;
}
F_31 ( & V_60 -> V_79 , V_72 ) ;
V_29 = F_32 ( V_58 + type -> V_80 [ V_78 ] ) ;
V_29 &= ~ ( V_69 << V_70 ) ;
if ( V_67 )
V_29 |= V_74 -> V_43 << V_70 ;
F_33 ( V_29 , V_58 + type -> V_80 [ V_78 ] ) ;
F_34 ( & V_60 -> V_79 , V_72 ) ;
}
static int F_35 ( struct V_4 * V_5 ,
unsigned V_53 ,
unsigned V_9 )
{
F_30 ( V_5 , V_53 , V_9 , true ) ;
return 0 ;
}
static int F_36 ( struct V_4 * V_5 , unsigned int V_57 ,
unsigned long * V_36 , bool V_81 )
{
struct V_6 * V_39 ;
const struct V_68 * type ;
struct V_1 * V_60 ;
void T_2 * V_82 ;
enum V_83 V_84 = F_37 ( * V_36 ) ;
T_1 V_29 , V_85 , V_71 , V_69 , V_70 ;
T_1 V_86 , V_87 ;
unsigned long V_72 ;
V_39 = F_4 ( V_5 ) ;
F_29 ( V_39 , V_57 - V_39 -> V_63 , & V_82 ,
& V_71 , & V_60 ) ;
type = V_60 -> type ;
if ( V_84 >= V_88 || ! type -> V_77 [ V_84 ] )
return - V_49 ;
V_85 = type -> V_77 [ V_84 ] ;
V_87 = type -> V_80 [ V_84 ] ;
F_31 ( & V_60 -> V_79 , V_72 ) ;
V_69 = ( 1 << V_85 ) - 1 ;
V_70 = V_71 * V_85 ;
V_29 = F_32 ( V_82 + V_87 ) ;
if ( V_81 ) {
V_86 = F_38 ( * V_36 ) ;
V_29 &= ~ ( V_69 << V_70 ) ;
V_29 |= ( V_86 << V_70 ) ;
F_33 ( V_29 , V_82 + V_87 ) ;
} else {
V_29 >>= V_70 ;
V_29 &= V_69 ;
* V_36 = F_20 ( V_84 , V_29 ) ;
}
F_34 ( & V_60 -> V_79 , V_72 ) ;
return 0 ;
}
static int F_39 ( struct V_4 * V_5 , unsigned int V_57 ,
unsigned long * V_31 , unsigned V_32 )
{
int V_38 , V_42 ;
for ( V_38 = 0 ; V_38 < V_32 ; V_38 ++ ) {
V_42 = F_36 ( V_5 , V_57 , & V_31 [ V_38 ] , true ) ;
if ( V_42 < 0 )
return V_42 ;
}
return 0 ;
}
static int F_40 ( struct V_4 * V_5 , unsigned int V_57 ,
unsigned long * V_36 )
{
return F_36 ( V_5 , V_57 , V_36 , false ) ;
}
static int F_41 ( struct V_4 * V_5 ,
unsigned V_9 , unsigned long * V_31 ,
unsigned V_32 )
{
struct V_6 * V_39 ;
const unsigned int * V_12 ;
unsigned int V_89 ;
V_39 = F_4 ( V_5 ) ;
V_12 = V_39 -> V_10 [ V_9 ] . V_12 ;
for ( V_89 = 0 ; V_89 < V_39 -> V_10 [ V_9 ] . V_13 ; V_89 ++ )
F_39 ( V_5 , V_12 [ V_89 ] , V_31 , V_32 ) ;
return 0 ;
}
static int F_42 ( struct V_4 * V_5 ,
unsigned int V_9 , unsigned long * V_36 )
{
struct V_6 * V_39 ;
const unsigned int * V_12 ;
V_39 = F_4 ( V_5 ) ;
V_12 = V_39 -> V_10 [ V_9 ] . V_12 ;
F_40 ( V_5 , V_12 [ 0 ] , V_36 ) ;
return 0 ;
}
static void F_43 ( struct V_2 * V_3 , unsigned V_59 , int V_90 )
{
struct V_1 * V_60 = F_1 ( V_3 ) ;
const struct V_68 * type = V_60 -> type ;
unsigned long V_72 ;
void T_2 * V_58 ;
T_1 V_29 ;
V_58 = V_60 -> V_39 -> V_65 + V_60 -> V_66 ;
F_31 ( & V_60 -> V_79 , V_72 ) ;
V_29 = F_32 ( V_58 + type -> V_80 [ V_91 ] ) ;
V_29 &= ~ ( 1 << V_59 ) ;
if ( V_90 )
V_29 |= 1 << V_59 ;
F_33 ( V_29 , V_58 + type -> V_80 [ V_91 ] ) ;
F_34 ( & V_60 -> V_79 , V_72 ) ;
}
static int F_44 ( struct V_2 * V_3 , unsigned V_59 )
{
void T_2 * V_58 ;
T_1 V_29 ;
struct V_1 * V_60 = F_1 ( V_3 ) ;
const struct V_68 * type = V_60 -> type ;
V_58 = V_60 -> V_39 -> V_65 + V_60 -> V_66 ;
V_29 = F_32 ( V_58 + type -> V_80 [ V_91 ] ) ;
V_29 >>= V_59 ;
V_29 &= 1 ;
return V_29 ;
}
static int F_45 ( struct V_2 * V_3 ,
unsigned V_59 , bool V_92 )
{
const struct V_68 * type ;
struct V_1 * V_60 ;
struct V_6 * V_39 ;
void T_2 * V_58 ;
T_1 V_29 , V_69 , V_70 ;
unsigned long V_72 ;
V_60 = F_1 ( V_3 ) ;
type = V_60 -> type ;
V_39 = V_60 -> V_39 ;
V_58 = V_39 -> V_65 + V_60 -> V_66 +
type -> V_80 [ V_78 ] ;
V_69 = ( 1 << type -> V_77 [ V_78 ] ) - 1 ;
V_70 = V_59 * type -> V_77 [ V_78 ] ;
if ( V_70 >= 32 ) {
V_70 -= 32 ;
V_58 += 4 ;
}
F_31 ( & V_60 -> V_79 , V_72 ) ;
V_29 = F_32 ( V_58 ) ;
V_29 &= ~ ( V_69 << V_70 ) ;
if ( ! V_92 )
V_29 |= V_93 << V_70 ;
F_33 ( V_29 , V_58 ) ;
F_34 ( & V_60 -> V_79 , V_72 ) ;
return 0 ;
}
static int F_46 ( struct V_2 * V_3 , unsigned V_59 )
{
return F_45 ( V_3 , V_59 , true ) ;
}
static int F_47 ( struct V_2 * V_3 , unsigned V_59 ,
int V_90 )
{
F_43 ( V_3 , V_59 , V_90 ) ;
return F_45 ( V_3 , V_59 , false ) ;
}
static int F_48 ( struct V_2 * V_3 , unsigned V_59 )
{
struct V_1 * V_60 = F_1 ( V_3 ) ;
unsigned int V_94 ;
if ( ! V_60 -> V_95 )
return - V_96 ;
V_94 = F_49 ( V_60 -> V_95 , V_59 ) ;
return ( V_94 ) ? : - V_96 ;
}
static struct V_75 * F_50 (
struct V_14 * V_15 ,
struct V_6 * V_39 ,
unsigned int * V_89 )
{
struct V_97 * V_98 = & V_39 -> V_99 ;
struct V_75 * V_55 , * V_76 ;
const struct V_100 * V_101 ;
int V_38 ;
V_55 = F_51 ( V_15 , V_98 -> V_102 * sizeof( * V_55 ) ,
V_24 ) ;
if ( ! V_55 )
return F_52 ( - V_49 ) ;
V_76 = V_55 ;
V_101 = V_98 -> V_12 ;
for ( V_38 = 0 ; V_38 < V_98 -> V_102 ; ++ V_38 , ++ V_101 , ++ V_76 ) {
V_76 -> V_11 = V_101 -> V_11 ;
V_76 -> V_12 = & V_101 -> V_103 ;
V_76 -> V_13 = 1 ;
}
* V_89 = V_98 -> V_102 ;
return V_55 ;
}
static int F_53 ( struct V_14 * V_15 ,
struct V_6 * V_39 ,
struct V_40 * V_104 ,
struct V_73 * V_74 )
{
int V_102 ;
int V_42 ;
int V_38 ;
if ( F_18 ( V_104 , L_4 , & V_74 -> V_43 ) )
return 0 ;
V_102 = F_21 ( V_104 , L_6 ) ;
if ( V_102 < 1 ) {
F_9 ( V_15 , L_8 , V_104 -> V_11 ) ;
return - V_49 ;
}
V_74 -> V_11 = V_104 -> V_50 ;
V_74 -> V_55 = F_51 ( V_15 , V_102 * sizeof( char * ) , V_24 ) ;
if ( ! V_74 -> V_55 )
return - V_25 ;
for ( V_38 = 0 ; V_38 < V_102 ; ++ V_38 ) {
const char * V_105 ;
V_42 = F_54 ( V_104 , L_6 ,
V_38 , & V_105 ) ;
if ( V_42 ) {
F_9 ( V_15 ,
L_9 ,
V_38 , V_104 -> V_11 ) ;
return V_42 ;
}
V_74 -> V_55 [ V_38 ] = V_105 ;
}
V_74 -> V_56 = V_102 ;
return 1 ;
}
static struct V_73 * F_55 (
struct V_14 * V_15 ,
struct V_6 * V_39 ,
unsigned int * V_89 )
{
struct V_73 * V_106 , * V_74 ;
struct V_40 * V_107 = V_15 -> V_108 ;
struct V_40 * V_109 ;
unsigned int V_110 = 0 ;
int V_42 ;
F_25 (dev_np, cfg_np) {
struct V_40 * V_104 ;
if ( ! F_24 ( V_109 ) ) {
if ( ! F_56 ( V_109 ,
L_4 , NULL ) )
continue;
++ V_110 ;
continue;
}
F_25 (cfg_np, func_np) {
if ( ! F_56 ( V_104 ,
L_4 , NULL ) )
continue;
++ V_110 ;
}
}
V_106 = F_51 ( V_15 , V_110 * sizeof( * V_106 ) ,
V_24 ) ;
if ( ! V_106 ) {
F_9 ( V_15 , L_10 ) ;
return F_52 ( - V_49 ) ;
}
V_74 = V_106 ;
V_110 = 0 ;
F_25 (dev_np, cfg_np) {
struct V_40 * V_104 ;
if ( ! F_24 ( V_109 ) ) {
V_42 = F_53 ( V_15 , V_39 ,
V_109 , V_74 ) ;
if ( V_42 < 0 )
return F_52 ( V_42 ) ;
if ( V_42 > 0 ) {
++ V_74 ;
++ V_110 ;
}
continue;
}
F_25 (cfg_np, func_np) {
V_42 = F_53 ( V_15 , V_39 ,
V_104 , V_74 ) ;
if ( V_42 < 0 )
return F_52 ( V_42 ) ;
if ( V_42 > 0 ) {
++ V_74 ;
++ V_110 ;
}
}
}
* V_89 = V_110 ;
return V_106 ;
}
static int F_57 ( struct V_111 * V_112 ,
struct V_6 * V_39 )
{
struct V_14 * V_15 = & V_112 -> V_15 ;
struct V_75 * V_55 ;
struct V_73 * V_106 ;
unsigned int V_113 = 0 , V_110 = 0 ;
V_55 = F_50 ( V_15 , V_39 , & V_113 ) ;
if ( F_58 ( V_55 ) ) {
F_9 ( V_15 , L_11 ) ;
return F_59 ( V_55 ) ;
}
V_106 = F_55 ( V_15 , V_39 , & V_110 ) ;
if ( F_58 ( V_106 ) ) {
F_9 ( V_15 , L_12 ) ;
return F_59 ( V_55 ) ;
}
V_39 -> V_10 = V_55 ;
V_39 -> V_8 = V_113 ;
V_39 -> V_54 = V_106 ;
V_39 -> V_52 = V_110 ;
return 0 ;
}
static int F_60 ( struct V_111 * V_112 ,
struct V_6 * V_39 )
{
struct V_97 * V_98 = & V_39 -> V_99 ;
struct V_100 * V_114 , * V_101 ;
struct V_1 * V_115 ;
char * V_116 ;
int V_57 , V_60 , V_42 ;
V_98 -> V_11 = L_13 ;
V_98 -> V_117 = V_118 ;
V_98 -> V_119 = & V_120 ;
V_98 -> V_121 = & V_122 ;
V_98 -> V_123 = & V_124 ;
V_114 = F_51 ( & V_112 -> V_15 , sizeof( * V_114 ) *
V_39 -> V_64 , V_24 ) ;
if ( ! V_114 ) {
F_9 ( & V_112 -> V_15 , L_14 ) ;
return - V_25 ;
}
V_98 -> V_12 = V_114 ;
V_98 -> V_102 = V_39 -> V_64 ;
for ( V_57 = 0 , V_101 = V_114 ; V_57 < V_98 -> V_102 ; V_57 ++ , V_101 ++ )
V_101 -> V_103 = V_57 + V_39 -> V_63 ;
V_116 = F_51 ( & V_112 -> V_15 , sizeof( char ) * V_125 *
V_39 -> V_64 , V_24 ) ;
if ( ! V_116 ) {
F_9 ( & V_112 -> V_15 , L_15 ) ;
return - V_25 ;
}
for ( V_60 = 0 ; V_60 < V_39 -> V_126 ; V_60 ++ ) {
V_115 = & V_39 -> V_62 [ V_60 ] ;
for ( V_57 = 0 ; V_57 < V_115 -> V_64 ; V_57 ++ ) {
sprintf ( V_116 , L_16 , V_115 -> V_11 , V_57 ) ;
V_101 = V_114 + V_115 -> V_63 + V_57 ;
V_101 -> V_11 = V_116 ;
V_116 += V_125 ;
}
}
V_42 = F_57 ( V_112 , V_39 ) ;
if ( V_42 )
return V_42 ;
V_39 -> V_127 = F_61 ( V_98 , & V_112 -> V_15 , V_39 ) ;
if ( ! V_39 -> V_127 ) {
F_9 ( & V_112 -> V_15 , L_17 ) ;
return - V_49 ;
}
for ( V_60 = 0 ; V_60 < V_39 -> V_126 ; ++ V_60 ) {
V_115 = & V_39 -> V_62 [ V_60 ] ;
V_115 -> V_128 . V_11 = V_115 -> V_11 ;
V_115 -> V_128 . V_129 = V_60 ;
V_115 -> V_128 . V_63 = V_39 -> V_63
+ V_115 -> V_63 ;
V_115 -> V_128 . V_130 = V_115 -> V_2 . V_130 ;
V_115 -> V_128 . V_102 = V_115 -> V_2 . V_131 ;
V_115 -> V_128 . V_3 = & V_115 -> V_2 ;
F_62 ( V_39 -> V_127 , & V_115 -> V_128 ) ;
}
return 0 ;
}
static int F_63 ( struct V_2 * V_132 , unsigned V_59 )
{
return F_64 ( V_132 -> V_130 + V_59 ) ;
}
static void F_65 ( struct V_2 * V_132 , unsigned V_59 )
{
F_66 ( V_132 -> V_130 + V_59 ) ;
}
static int F_67 ( struct V_111 * V_112 ,
struct V_6 * V_39 )
{
struct V_1 * V_60 = V_39 -> V_62 ;
struct V_2 * V_3 ;
int V_42 ;
int V_38 ;
for ( V_38 = 0 ; V_38 < V_39 -> V_126 ; ++ V_38 , ++ V_60 ) {
V_60 -> V_2 = V_133 ;
V_3 = & V_60 -> V_2 ;
V_3 -> V_130 = V_39 -> V_63 + V_60 -> V_63 ;
V_3 -> V_131 = V_60 -> V_64 ;
V_3 -> V_15 = & V_112 -> V_15 ;
V_3 -> V_108 = V_60 -> V_108 ;
V_3 -> V_134 = V_60 -> V_11 ;
V_42 = F_68 ( V_3 ) ;
if ( V_42 ) {
F_9 ( & V_112 -> V_15 , L_18 ,
V_3 -> V_134 , V_42 ) ;
goto V_135;
}
}
return 0 ;
V_135:
for ( -- V_38 , -- V_60 ; V_38 >= 0 ; -- V_38 , -- V_60 )
F_69 ( & V_60 -> V_2 ) ;
return V_42 ;
}
static int F_70 ( struct V_111 * V_112 ,
struct V_6 * V_39 )
{
struct V_1 * V_60 = V_39 -> V_62 ;
int V_38 ;
for ( V_38 = 0 ; V_38 < V_39 -> V_126 ; ++ V_38 , ++ V_60 )
F_69 ( & V_60 -> V_2 ) ;
return 0 ;
}
static const struct V_136 *
F_71 ( struct V_6 * V_137 ,
struct V_111 * V_112 )
{
int V_129 ;
const struct V_138 * V_139 ;
struct V_40 * V_140 = V_112 -> V_15 . V_108 ;
struct V_40 * V_41 ;
const struct V_141 * V_142 ;
const struct V_136 * V_143 ;
struct V_1 * V_60 ;
int V_38 ;
V_129 = F_72 ( V_140 , L_19 ) ;
if ( V_129 < 0 ) {
F_9 ( & V_112 -> V_15 , L_20 ) ;
return F_52 ( - V_144 ) ;
}
V_139 = F_73 ( V_145 , V_140 ) ;
V_143 = (struct V_136 * ) V_139 -> V_29 + V_129 ;
V_137 -> V_146 = V_143 -> V_146 ;
V_137 -> V_147 = V_143 -> V_147 ;
V_137 -> V_126 = V_143 -> V_126 ;
V_137 -> V_62 = F_74 ( & V_112 -> V_15 , V_137 -> V_126 ,
sizeof( * V_137 -> V_62 ) , V_24 ) ;
if ( ! V_137 -> V_62 )
return F_52 ( - V_25 ) ;
V_60 = V_137 -> V_62 ;
V_142 = V_143 -> V_62 ;
for ( V_38 = 0 ; V_38 < V_143 -> V_126 ; ++ V_38 , ++ V_142 , ++ V_60 ) {
V_60 -> type = V_142 -> type ;
V_60 -> V_66 = V_142 -> V_66 ;
V_60 -> V_64 = V_142 -> V_64 ;
V_60 -> V_148 = V_142 -> V_148 ;
V_60 -> V_149 = V_142 -> V_149 ;
V_60 -> V_150 = V_142 -> V_150 ;
V_60 -> V_151 = V_142 -> V_151 ;
V_60 -> V_11 = V_142 -> V_11 ;
F_75 ( & V_60 -> V_79 ) ;
V_60 -> V_39 = V_137 ;
V_60 -> V_63 = V_137 -> V_64 ;
V_137 -> V_64 += V_60 -> V_64 ;
}
F_25 (node, np) {
if ( ! F_56 ( V_41 , L_21 , NULL ) )
continue;
V_60 = V_137 -> V_62 ;
for ( V_38 = 0 ; V_38 < V_137 -> V_126 ; ++ V_38 , ++ V_60 ) {
if ( ! strcmp ( V_60 -> V_11 , V_41 -> V_11 ) ) {
V_60 -> V_108 = V_41 ;
break;
}
}
}
V_137 -> V_63 = V_63 ;
V_63 += V_137 -> V_64 ;
return V_143 ;
}
static int F_76 ( struct V_111 * V_112 )
{
struct V_6 * V_39 ;
const struct V_136 * V_143 ;
struct V_14 * V_15 = & V_112 -> V_15 ;
struct V_152 * V_153 ;
int V_42 ;
if ( ! V_15 -> V_108 ) {
F_9 ( V_15 , L_22 ) ;
return - V_154 ;
}
V_39 = F_51 ( V_15 , sizeof( * V_39 ) , V_24 ) ;
if ( ! V_39 ) {
F_9 ( V_15 , L_23
L_24 ) ;
return - V_25 ;
}
V_143 = F_71 ( V_39 , V_112 ) ;
if ( F_58 ( V_143 ) ) {
F_9 ( & V_112 -> V_15 , L_25 ) ;
return F_59 ( V_143 ) ;
}
V_39 -> V_15 = V_15 ;
V_153 = F_77 ( V_112 , V_155 , 0 ) ;
V_39 -> V_65 = F_78 ( & V_112 -> V_15 , V_153 ) ;
if ( F_58 ( V_39 -> V_65 ) )
return F_59 ( V_39 -> V_65 ) ;
V_153 = F_77 ( V_112 , V_156 , 0 ) ;
if ( V_153 )
V_39 -> V_157 = V_153 -> V_158 ;
V_42 = F_67 ( V_112 , V_39 ) ;
if ( V_42 )
return V_42 ;
V_42 = F_60 ( V_112 , V_39 ) ;
if ( V_42 ) {
F_70 ( V_112 , V_39 ) ;
return V_42 ;
}
if ( V_143 -> V_159 )
V_143 -> V_159 ( V_39 ) ;
if ( V_143 -> V_160 )
V_143 -> V_160 ( V_39 ) ;
F_79 ( V_112 , V_39 ) ;
F_80 ( & V_39 -> V_140 , & V_161 ) ;
return 0 ;
}
static void F_81 (
struct V_6 * V_39 )
{
void T_2 * V_65 = V_39 -> V_65 ;
int V_38 ;
for ( V_38 = 0 ; V_38 < V_39 -> V_126 ; V_38 ++ ) {
struct V_1 * V_60 = & V_39 -> V_62 [ V_38 ] ;
void T_2 * V_58 = V_65 + V_60 -> V_66 ;
const T_3 * V_162 = V_60 -> type -> V_80 ;
const T_3 * V_163 = V_60 -> type -> V_77 ;
enum V_83 type ;
if ( ! V_163 [ V_164 ] )
continue;
for ( type = 0 ; type < V_88 ; type ++ )
if ( V_163 [ type ] )
V_60 -> V_165 [ type ] = F_32 ( V_58 + V_162 [ type ] ) ;
if ( V_163 [ V_78 ] * V_60 -> V_64 > 32 ) {
V_60 -> V_165 [ V_88 ] =
F_32 ( V_58 + V_162 [ V_78 ] + 4 ) ;
F_82 ( L_26 ,
V_60 -> V_11 , V_58 ,
V_60 -> V_165 [ V_78 ] ,
V_60 -> V_165 [ V_88 ] ) ;
} else {
F_82 ( L_27 , V_60 -> V_11 ,
V_58 , V_60 -> V_165 [ V_78 ] ) ;
}
}
if ( V_39 -> V_146 )
V_39 -> V_146 ( V_39 ) ;
}
static void F_83 ( struct V_6 * V_39 )
{
void T_2 * V_65 = V_39 -> V_65 ;
int V_38 ;
if ( V_39 -> V_147 )
V_39 -> V_147 ( V_39 ) ;
for ( V_38 = 0 ; V_38 < V_39 -> V_126 ; V_38 ++ ) {
struct V_1 * V_60 = & V_39 -> V_62 [ V_38 ] ;
void T_2 * V_58 = V_65 + V_60 -> V_66 ;
const T_3 * V_162 = V_60 -> type -> V_80 ;
const T_3 * V_163 = V_60 -> type -> V_77 ;
enum V_83 type ;
if ( ! V_163 [ V_164 ] )
continue;
if ( V_163 [ V_78 ] * V_60 -> V_64 > 32 ) {
F_82 ( L_28 ,
V_60 -> V_11 , V_58 ,
F_32 ( V_58 + V_162 [ V_78 ] ) ,
F_32 ( V_58 + V_162 [ V_78 ] + 4 ) ,
V_60 -> V_165 [ V_78 ] ,
V_60 -> V_165 [ V_88 ] ) ;
F_33 ( V_60 -> V_165 [ V_88 ] ,
V_58 + V_162 [ V_78 ] + 4 ) ;
} else {
F_82 ( L_29 , V_60 -> V_11 ,
V_58 , F_32 ( V_58 + V_162 [ V_78 ] ) ,
V_60 -> V_165 [ V_78 ] ) ;
}
for ( type = 0 ; type < V_88 ; type ++ )
if ( V_163 [ type ] )
F_33 ( V_60 -> V_165 [ type ] , V_58 + V_162 [ type ] ) ;
}
}
static int F_84 ( void )
{
struct V_6 * V_39 ;
F_85 (drvdata, &drvdata_list, node) {
F_81 ( V_39 ) ;
}
return 0 ;
}
static void F_86 ( void )
{
struct V_6 * V_39 ;
F_87 (drvdata, &drvdata_list, node) {
F_83 ( V_39 ) ;
}
}
static int T_4 F_88 ( void )
{
F_89 ( & V_166 ) ;
return F_90 ( & V_167 ) ;
}
static void T_5 F_91 ( void )
{
F_92 ( & V_167 ) ;
}
