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
V_61 = V_39 -> V_62 -> V_63 ;
while ( ( V_57 >= V_61 -> V_64 ) &&
( ( V_61 -> V_64 + V_61 -> V_65 - 1 ) < V_57 ) )
V_61 ++ ;
* V_58 = V_39 -> V_66 + V_61 -> V_67 ;
* V_59 = V_57 - V_61 -> V_64 ;
if ( V_60 )
* V_60 = V_61 ;
}
static void F_30 ( struct V_4 * V_5 , unsigned V_53 ,
unsigned V_9 , bool V_68 )
{
struct V_6 * V_39 ;
struct V_69 * type ;
struct V_1 * V_60 ;
void T_2 * V_58 ;
T_1 V_70 , V_71 , V_29 , V_72 ;
unsigned long V_73 ;
const struct V_74 * V_75 ;
const struct V_76 * V_77 ;
V_39 = F_4 ( V_5 ) ;
V_75 = & V_39 -> V_54 [ V_53 ] ;
V_77 = & V_39 -> V_10 [ V_9 ] ;
F_29 ( V_39 , V_77 -> V_12 [ 0 ] - V_39 -> V_62 -> V_78 ,
& V_58 , & V_72 , & V_60 ) ;
type = V_60 -> type ;
V_70 = ( 1 << type -> V_79 [ V_80 ] ) - 1 ;
V_71 = V_72 * type -> V_79 [ V_80 ] ;
if ( V_71 >= 32 ) {
V_71 -= 32 ;
V_58 += 4 ;
}
F_31 ( & V_60 -> V_81 , V_73 ) ;
V_29 = F_32 ( V_58 + type -> V_82 [ V_80 ] ) ;
V_29 &= ~ ( V_70 << V_71 ) ;
if ( V_68 )
V_29 |= V_75 -> V_43 << V_71 ;
F_33 ( V_29 , V_58 + type -> V_82 [ V_80 ] ) ;
F_34 ( & V_60 -> V_81 , V_73 ) ;
}
static int F_35 ( struct V_4 * V_5 , unsigned V_53 ,
unsigned V_9 )
{
F_30 ( V_5 , V_53 , V_9 , true ) ;
return 0 ;
}
static int F_36 ( struct V_4 * V_5 , unsigned int V_57 ,
unsigned long * V_36 , bool V_83 )
{
struct V_6 * V_39 ;
struct V_69 * type ;
struct V_1 * V_60 ;
void T_2 * V_84 ;
enum V_85 V_86 = F_37 ( * V_36 ) ;
T_1 V_29 , V_87 , V_72 , V_70 , V_71 ;
T_1 V_88 , V_89 ;
unsigned long V_73 ;
V_39 = F_4 ( V_5 ) ;
F_29 ( V_39 , V_57 - V_39 -> V_62 -> V_78 , & V_84 ,
& V_72 , & V_60 ) ;
type = V_60 -> type ;
if ( V_86 >= V_90 || ! type -> V_79 [ V_86 ] )
return - V_49 ;
V_87 = type -> V_79 [ V_86 ] ;
V_89 = type -> V_82 [ V_86 ] ;
F_31 ( & V_60 -> V_81 , V_73 ) ;
V_70 = ( 1 << V_87 ) - 1 ;
V_71 = V_72 * V_87 ;
V_29 = F_32 ( V_84 + V_89 ) ;
if ( V_83 ) {
V_88 = F_38 ( * V_36 ) ;
V_29 &= ~ ( V_70 << V_71 ) ;
V_29 |= ( V_88 << V_71 ) ;
F_33 ( V_29 , V_84 + V_89 ) ;
} else {
V_29 >>= V_71 ;
V_29 &= V_70 ;
* V_36 = F_20 ( V_86 , V_29 ) ;
}
F_34 ( & V_60 -> V_81 , V_73 ) ;
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
unsigned int V_91 ;
V_39 = F_4 ( V_5 ) ;
V_12 = V_39 -> V_10 [ V_9 ] . V_12 ;
for ( V_91 = 0 ; V_91 < V_39 -> V_10 [ V_9 ] . V_13 ; V_91 ++ )
F_39 ( V_5 , V_12 [ V_91 ] , V_31 , V_32 ) ;
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
static void F_43 ( struct V_2 * V_3 , unsigned V_59 , int V_92 )
{
struct V_1 * V_60 = F_1 ( V_3 ) ;
struct V_69 * type = V_60 -> type ;
unsigned long V_73 ;
void T_2 * V_58 ;
T_1 V_29 ;
V_58 = V_60 -> V_39 -> V_66 + V_60 -> V_67 ;
F_31 ( & V_60 -> V_81 , V_73 ) ;
V_29 = F_32 ( V_58 + type -> V_82 [ V_93 ] ) ;
V_29 &= ~ ( 1 << V_59 ) ;
if ( V_92 )
V_29 |= 1 << V_59 ;
F_33 ( V_29 , V_58 + type -> V_82 [ V_93 ] ) ;
F_34 ( & V_60 -> V_81 , V_73 ) ;
}
static int F_44 ( struct V_2 * V_3 , unsigned V_59 )
{
void T_2 * V_58 ;
T_1 V_29 ;
struct V_1 * V_60 = F_1 ( V_3 ) ;
struct V_69 * type = V_60 -> type ;
V_58 = V_60 -> V_39 -> V_66 + V_60 -> V_67 ;
V_29 = F_32 ( V_58 + type -> V_82 [ V_93 ] ) ;
V_29 >>= V_59 ;
V_29 &= 1 ;
return V_29 ;
}
static int F_45 ( struct V_2 * V_3 ,
unsigned V_59 , bool V_94 )
{
struct V_69 * type ;
struct V_1 * V_60 ;
struct V_6 * V_39 ;
void T_2 * V_58 ;
T_1 V_29 , V_70 , V_71 ;
unsigned long V_73 ;
V_60 = F_1 ( V_3 ) ;
type = V_60 -> type ;
V_39 = V_60 -> V_39 ;
V_58 = V_39 -> V_66 + V_60 -> V_67 +
type -> V_82 [ V_80 ] ;
V_70 = ( 1 << type -> V_79 [ V_80 ] ) - 1 ;
V_71 = V_59 * type -> V_79 [ V_80 ] ;
if ( V_71 >= 32 ) {
V_71 -= 32 ;
V_58 += 4 ;
}
F_31 ( & V_60 -> V_81 , V_73 ) ;
V_29 = F_32 ( V_58 ) ;
V_29 &= ~ ( V_70 << V_71 ) ;
if ( ! V_94 )
V_29 |= V_95 << V_71 ;
F_33 ( V_29 , V_58 ) ;
F_34 ( & V_60 -> V_81 , V_73 ) ;
return 0 ;
}
static int F_46 ( struct V_2 * V_3 , unsigned V_59 )
{
return F_45 ( V_3 , V_59 , true ) ;
}
static int F_47 ( struct V_2 * V_3 , unsigned V_59 ,
int V_92 )
{
F_43 ( V_3 , V_59 , V_92 ) ;
return F_45 ( V_3 , V_59 , false ) ;
}
static int F_48 ( struct V_2 * V_3 , unsigned V_59 )
{
struct V_1 * V_60 = F_1 ( V_3 ) ;
unsigned int V_96 ;
if ( ! V_60 -> V_97 )
return - V_98 ;
V_96 = F_49 ( V_60 -> V_97 , V_59 ) ;
return ( V_96 ) ? : - V_98 ;
}
static struct V_76 * F_50 (
struct V_14 * V_15 ,
struct V_6 * V_39 ,
unsigned int * V_91 )
{
struct V_99 * V_100 = & V_39 -> V_101 ;
struct V_76 * V_55 , * V_77 ;
const struct V_102 * V_103 ;
int V_38 ;
V_55 = F_51 ( V_15 , V_100 -> V_104 * sizeof( * V_55 ) ,
V_24 ) ;
if ( ! V_55 )
return F_52 ( - V_49 ) ;
V_77 = V_55 ;
V_103 = V_100 -> V_12 ;
for ( V_38 = 0 ; V_38 < V_100 -> V_104 ; ++ V_38 , ++ V_103 , ++ V_77 ) {
V_77 -> V_11 = V_103 -> V_11 ;
V_77 -> V_12 = & V_103 -> V_105 ;
V_77 -> V_13 = 1 ;
}
* V_91 = V_100 -> V_104 ;
return V_55 ;
}
static int F_53 ( struct V_14 * V_15 ,
struct V_6 * V_39 ,
struct V_40 * V_106 ,
struct V_74 * V_75 )
{
int V_104 ;
int V_42 ;
int V_38 ;
if ( F_18 ( V_106 , L_4 , & V_75 -> V_43 ) )
return 0 ;
V_104 = F_21 ( V_106 , L_6 ) ;
if ( V_104 < 1 ) {
F_9 ( V_15 , L_8 , V_106 -> V_11 ) ;
return - V_49 ;
}
V_75 -> V_11 = V_106 -> V_50 ;
V_75 -> V_55 = F_51 ( V_15 , V_104 * sizeof( char * ) , V_24 ) ;
if ( ! V_75 -> V_55 )
return - V_25 ;
for ( V_38 = 0 ; V_38 < V_104 ; ++ V_38 ) {
const char * V_107 ;
V_42 = F_54 ( V_106 , L_6 ,
V_38 , & V_107 ) ;
if ( V_42 ) {
F_9 ( V_15 ,
L_9 ,
V_38 , V_106 -> V_11 ) ;
return V_42 ;
}
V_75 -> V_55 [ V_38 ] = V_107 ;
}
V_75 -> V_56 = V_104 ;
return 1 ;
}
static struct V_74 * F_55 (
struct V_14 * V_15 ,
struct V_6 * V_39 ,
unsigned int * V_91 )
{
struct V_74 * V_108 , * V_75 ;
struct V_40 * V_109 = V_15 -> V_110 ;
struct V_40 * V_111 ;
unsigned int V_112 = 0 ;
int V_42 ;
F_25 (dev_np, cfg_np) {
struct V_40 * V_106 ;
if ( ! F_24 ( V_111 ) ) {
if ( ! F_56 ( V_111 ,
L_4 , NULL ) )
continue;
++ V_112 ;
continue;
}
F_25 (cfg_np, func_np) {
if ( ! F_56 ( V_106 ,
L_4 , NULL ) )
continue;
++ V_112 ;
}
}
V_108 = F_51 ( V_15 , V_112 * sizeof( * V_108 ) ,
V_24 ) ;
if ( ! V_108 ) {
F_9 ( V_15 , L_10 ) ;
return F_52 ( - V_49 ) ;
}
V_75 = V_108 ;
V_112 = 0 ;
F_25 (dev_np, cfg_np) {
struct V_40 * V_106 ;
if ( ! F_24 ( V_111 ) ) {
V_42 = F_53 ( V_15 , V_39 ,
V_111 , V_75 ) ;
if ( V_42 < 0 )
return F_52 ( V_42 ) ;
if ( V_42 > 0 ) {
++ V_75 ;
++ V_112 ;
}
continue;
}
F_25 (cfg_np, func_np) {
V_42 = F_53 ( V_15 , V_39 ,
V_106 , V_75 ) ;
if ( V_42 < 0 )
return F_52 ( V_42 ) ;
if ( V_42 > 0 ) {
++ V_75 ;
++ V_112 ;
}
}
}
* V_91 = V_112 ;
return V_108 ;
}
static int F_57 ( struct V_113 * V_114 ,
struct V_6 * V_39 )
{
struct V_14 * V_15 = & V_114 -> V_15 ;
struct V_76 * V_55 ;
struct V_74 * V_108 ;
unsigned int V_115 = 0 , V_112 = 0 ;
V_55 = F_50 ( V_15 , V_39 , & V_115 ) ;
if ( F_58 ( V_55 ) ) {
F_9 ( V_15 , L_11 ) ;
return F_59 ( V_55 ) ;
}
V_108 = F_55 ( V_15 , V_39 , & V_112 ) ;
if ( F_58 ( V_108 ) ) {
F_9 ( V_15 , L_12 ) ;
return F_59 ( V_55 ) ;
}
V_39 -> V_10 = V_55 ;
V_39 -> V_8 = V_115 ;
V_39 -> V_54 = V_108 ;
V_39 -> V_52 = V_112 ;
return 0 ;
}
static int F_60 ( struct V_113 * V_114 ,
struct V_6 * V_39 )
{
struct V_99 * V_100 = & V_39 -> V_101 ;
struct V_102 * V_116 , * V_103 ;
struct V_1 * V_117 ;
char * V_118 ;
int V_57 , V_60 , V_42 ;
V_100 -> V_11 = L_13 ;
V_100 -> V_119 = V_120 ;
V_100 -> V_121 = & V_122 ;
V_100 -> V_123 = & V_124 ;
V_100 -> V_125 = & V_126 ;
V_116 = F_51 ( & V_114 -> V_15 , sizeof( * V_116 ) *
V_39 -> V_62 -> V_65 , V_24 ) ;
if ( ! V_116 ) {
F_9 ( & V_114 -> V_15 , L_14 ) ;
return - V_25 ;
}
V_100 -> V_12 = V_116 ;
V_100 -> V_104 = V_39 -> V_62 -> V_65 ;
for ( V_57 = 0 , V_103 = V_116 ; V_57 < V_100 -> V_104 ; V_57 ++ , V_103 ++ )
V_103 -> V_105 = V_57 + V_39 -> V_62 -> V_78 ;
V_118 = F_51 ( & V_114 -> V_15 , sizeof( char ) * V_127 *
V_39 -> V_62 -> V_65 , V_24 ) ;
if ( ! V_118 ) {
F_9 ( & V_114 -> V_15 , L_15 ) ;
return - V_25 ;
}
for ( V_60 = 0 ; V_60 < V_39 -> V_62 -> V_128 ; V_60 ++ ) {
V_117 = & V_39 -> V_62 -> V_63 [ V_60 ] ;
for ( V_57 = 0 ; V_57 < V_117 -> V_65 ; V_57 ++ ) {
sprintf ( V_118 , L_16 , V_117 -> V_11 , V_57 ) ;
V_103 = V_116 + V_117 -> V_64 + V_57 ;
V_103 -> V_11 = V_118 ;
V_118 += V_127 ;
}
}
V_42 = F_57 ( V_114 , V_39 ) ;
if ( V_42 )
return V_42 ;
V_39 -> V_129 = F_61 ( V_100 , & V_114 -> V_15 , V_39 ) ;
if ( ! V_39 -> V_129 ) {
F_9 ( & V_114 -> V_15 , L_17 ) ;
return - V_49 ;
}
for ( V_60 = 0 ; V_60 < V_39 -> V_62 -> V_128 ; ++ V_60 ) {
V_117 = & V_39 -> V_62 -> V_63 [ V_60 ] ;
V_117 -> V_130 . V_11 = V_117 -> V_11 ;
V_117 -> V_130 . V_131 = V_60 ;
V_117 -> V_130 . V_64 = V_39 -> V_62 -> V_78
+ V_117 -> V_64 ;
V_117 -> V_130 . V_78 = V_117 -> V_2 . V_78 ;
V_117 -> V_130 . V_104 = V_117 -> V_2 . V_132 ;
V_117 -> V_130 . V_3 = & V_117 -> V_2 ;
F_62 ( V_39 -> V_129 , & V_117 -> V_130 ) ;
}
return 0 ;
}
static int F_63 ( struct V_2 * V_133 , unsigned V_59 )
{
return F_64 ( V_133 -> V_78 + V_59 ) ;
}
static void F_65 ( struct V_2 * V_133 , unsigned V_59 )
{
F_66 ( V_133 -> V_78 + V_59 ) ;
}
static int F_67 ( struct V_113 * V_114 ,
struct V_6 * V_39 )
{
struct V_134 * V_62 = V_39 -> V_62 ;
struct V_1 * V_60 = V_62 -> V_63 ;
struct V_2 * V_3 ;
int V_42 ;
int V_38 ;
for ( V_38 = 0 ; V_38 < V_62 -> V_128 ; ++ V_38 , ++ V_60 ) {
V_60 -> V_2 = V_135 ;
V_3 = & V_60 -> V_2 ;
V_3 -> V_78 = V_62 -> V_78 + V_60 -> V_64 ;
V_3 -> V_132 = V_60 -> V_65 ;
V_3 -> V_15 = & V_114 -> V_15 ;
V_3 -> V_110 = V_60 -> V_110 ;
V_3 -> V_136 = V_60 -> V_11 ;
V_42 = F_68 ( V_3 ) ;
if ( V_42 ) {
F_9 ( & V_114 -> V_15 , L_18 ,
V_3 -> V_136 , V_42 ) ;
goto V_137;
}
}
return 0 ;
V_137:
for ( -- V_38 , -- V_60 ; V_38 >= 0 ; -- V_38 , -- V_60 )
if ( F_69 ( & V_60 -> V_2 ) )
F_9 ( & V_114 -> V_15 , L_19 ,
V_60 -> V_2 . V_136 ) ;
return V_42 ;
}
static int F_70 ( struct V_113 * V_114 ,
struct V_6 * V_39 )
{
struct V_134 * V_62 = V_39 -> V_62 ;
struct V_1 * V_60 = V_62 -> V_63 ;
int V_42 = 0 ;
int V_38 ;
for ( V_38 = 0 ; ! V_42 && V_38 < V_62 -> V_128 ; ++ V_38 , ++ V_60 )
V_42 = F_69 ( & V_60 -> V_2 ) ;
if ( V_42 )
F_9 ( & V_114 -> V_15 , L_20 ) ;
return V_42 ;
}
static struct V_134 * F_71 (
struct V_6 * V_138 ,
struct V_113 * V_114 )
{
int V_131 ;
const struct V_139 * V_140 ;
struct V_40 * V_141 = V_114 -> V_15 . V_110 ;
struct V_40 * V_41 ;
struct V_134 * V_62 ;
struct V_1 * V_60 ;
int V_38 ;
V_131 = F_72 ( V_141 , L_21 ) ;
if ( V_131 < 0 ) {
F_9 ( & V_114 -> V_15 , L_22 ) ;
return NULL ;
}
V_140 = F_73 ( V_142 , V_141 ) ;
V_62 = (struct V_134 * ) V_140 -> V_29 + V_131 ;
V_60 = V_62 -> V_63 ;
for ( V_38 = 0 ; V_38 < V_62 -> V_128 ; ++ V_38 , ++ V_60 ) {
F_74 ( & V_60 -> V_81 ) ;
V_60 -> V_39 = V_138 ;
V_60 -> V_64 = V_62 -> V_65 ;
V_62 -> V_65 += V_60 -> V_65 ;
}
F_25 (node, np) {
if ( ! F_56 ( V_41 , L_23 , NULL ) )
continue;
V_60 = V_62 -> V_63 ;
for ( V_38 = 0 ; V_38 < V_62 -> V_128 ; ++ V_38 , ++ V_60 ) {
if ( ! strcmp ( V_60 -> V_11 , V_41 -> V_11 ) ) {
V_60 -> V_110 = V_41 ;
break;
}
}
}
V_62 -> V_78 = V_64 ;
V_64 += V_62 -> V_65 ;
return V_62 ;
}
static int F_75 ( struct V_113 * V_114 )
{
struct V_6 * V_39 ;
struct V_14 * V_15 = & V_114 -> V_15 ;
struct V_134 * V_62 ;
struct V_143 * V_144 ;
int V_42 ;
if ( ! V_15 -> V_110 ) {
F_9 ( V_15 , L_24 ) ;
return - V_145 ;
}
V_39 = F_51 ( V_15 , sizeof( * V_39 ) , V_24 ) ;
if ( ! V_39 ) {
F_9 ( V_15 , L_25
L_26 ) ;
return - V_25 ;
}
V_62 = F_71 ( V_39 , V_114 ) ;
if ( ! V_62 ) {
F_9 ( & V_114 -> V_15 , L_27 ) ;
return - V_49 ;
}
V_39 -> V_62 = V_62 ;
V_39 -> V_15 = V_15 ;
V_144 = F_76 ( V_114 , V_146 , 0 ) ;
V_39 -> V_66 = F_77 ( & V_114 -> V_15 , V_144 ) ;
if ( F_58 ( V_39 -> V_66 ) )
return F_59 ( V_39 -> V_66 ) ;
V_144 = F_76 ( V_114 , V_147 , 0 ) ;
if ( V_144 )
V_39 -> V_148 = V_144 -> V_149 ;
V_42 = F_67 ( V_114 , V_39 ) ;
if ( V_42 )
return V_42 ;
V_42 = F_60 ( V_114 , V_39 ) ;
if ( V_42 ) {
F_70 ( V_114 , V_39 ) ;
return V_42 ;
}
if ( V_62 -> V_150 )
V_62 -> V_150 ( V_39 ) ;
if ( V_62 -> V_151 )
V_62 -> V_151 ( V_39 ) ;
F_78 ( V_114 , V_39 ) ;
F_79 ( & V_39 -> V_141 , & V_152 ) ;
return 0 ;
}
static void F_80 (
struct V_6 * V_39 )
{
struct V_134 * V_62 = V_39 -> V_62 ;
void T_2 * V_66 = V_39 -> V_66 ;
int V_38 ;
for ( V_38 = 0 ; V_38 < V_62 -> V_128 ; V_38 ++ ) {
struct V_1 * V_60 = & V_62 -> V_63 [ V_38 ] ;
void T_2 * V_58 = V_66 + V_60 -> V_67 ;
T_3 * V_153 = V_60 -> type -> V_82 ;
T_3 * V_154 = V_60 -> type -> V_79 ;
enum V_85 type ;
if ( ! V_154 [ V_155 ] )
continue;
for ( type = 0 ; type < V_90 ; type ++ )
if ( V_154 [ type ] )
V_60 -> V_156 [ type ] = F_32 ( V_58 + V_153 [ type ] ) ;
if ( V_154 [ V_80 ] * V_60 -> V_65 > 32 ) {
V_60 -> V_156 [ V_90 ] =
F_32 ( V_58 + V_153 [ V_80 ] + 4 ) ;
F_81 ( L_28 ,
V_60 -> V_11 , V_58 ,
V_60 -> V_156 [ V_80 ] ,
V_60 -> V_156 [ V_90 ] ) ;
} else {
F_81 ( L_29 , V_60 -> V_11 ,
V_58 , V_60 -> V_156 [ V_80 ] ) ;
}
}
if ( V_62 -> V_157 )
V_62 -> V_157 ( V_39 ) ;
}
static void F_82 ( struct V_6 * V_39 )
{
struct V_134 * V_62 = V_39 -> V_62 ;
void T_2 * V_66 = V_39 -> V_66 ;
int V_38 ;
if ( V_62 -> V_158 )
V_62 -> V_158 ( V_39 ) ;
for ( V_38 = 0 ; V_38 < V_62 -> V_128 ; V_38 ++ ) {
struct V_1 * V_60 = & V_62 -> V_63 [ V_38 ] ;
void T_2 * V_58 = V_66 + V_60 -> V_67 ;
T_3 * V_153 = V_60 -> type -> V_82 ;
T_3 * V_154 = V_60 -> type -> V_79 ;
enum V_85 type ;
if ( ! V_154 [ V_155 ] )
continue;
if ( V_154 [ V_80 ] * V_60 -> V_65 > 32 ) {
F_81 ( L_30 ,
V_60 -> V_11 , V_58 ,
F_32 ( V_58 + V_153 [ V_80 ] ) ,
F_32 ( V_58 + V_153 [ V_80 ] + 4 ) ,
V_60 -> V_156 [ V_80 ] ,
V_60 -> V_156 [ V_90 ] ) ;
F_33 ( V_60 -> V_156 [ V_90 ] ,
V_58 + V_153 [ V_80 ] + 4 ) ;
} else {
F_81 ( L_31 , V_60 -> V_11 ,
V_58 , F_32 ( V_58 + V_153 [ V_80 ] ) ,
V_60 -> V_156 [ V_80 ] ) ;
}
for ( type = 0 ; type < V_90 ; type ++ )
if ( V_154 [ type ] )
F_33 ( V_60 -> V_156 [ type ] , V_58 + V_153 [ type ] ) ;
}
}
static int F_83 ( void )
{
struct V_6 * V_39 ;
F_84 (drvdata, &drvdata_list, node) {
F_80 ( V_39 ) ;
}
return 0 ;
}
static void F_85 ( void )
{
struct V_6 * V_39 ;
F_86 (drvdata, &drvdata_list, node) {
F_82 ( V_39 ) ;
}
}
static int T_4 F_87 ( void )
{
F_88 ( & V_159 ) ;
return F_89 ( & V_160 ) ;
}
static void T_5 F_90 ( void )
{
F_91 ( & V_160 ) ;
}
