static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return V_4 -> V_5 ;
}
static const char * F_3 ( struct V_1 * V_2 ,
unsigned V_6 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return V_4 -> V_7 [ V_6 ] . V_8 ;
}
static int F_4 ( struct V_1 * V_2 ,
unsigned V_6 ,
const unsigned * * V_9 ,
unsigned * V_10 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
* V_9 = V_4 -> V_7 [ V_6 ] . V_9 ;
* V_10 = V_4 -> V_7 [ V_6 ] . V_10 ;
return 0 ;
}
static int F_5 ( struct V_11 * V_12 , struct V_13 * * V_14 ,
unsigned * V_15 , unsigned * V_16 ,
unsigned V_17 )
{
unsigned V_18 = * V_15 ;
unsigned V_19 = * V_16 + V_17 ;
struct V_13 * V_20 ;
if ( V_18 >= V_19 )
return 0 ;
V_20 = F_6 ( * V_14 , sizeof( * V_20 ) * V_19 , V_21 ) ;
if ( ! V_20 )
return - V_22 ;
memset ( V_20 + V_18 , 0 , ( V_19 - V_18 ) * sizeof( * V_20 ) ) ;
* V_14 = V_20 ;
* V_15 = V_19 ;
return 0 ;
}
static int F_7 ( struct V_13 * * V_14 , unsigned * V_15 ,
unsigned * V_16 , const char * V_6 ,
const char * V_23 )
{
if ( F_8 ( * V_16 == * V_15 ) )
return - V_24 ;
( * V_14 ) [ * V_16 ] . type = V_25 ;
( * V_14 ) [ * V_16 ] . V_26 . V_27 . V_6 = V_6 ;
( * V_14 ) [ * V_16 ] . V_26 . V_27 . V_23 = V_23 ;
( * V_16 ) ++ ;
return 0 ;
}
static int F_9 ( struct V_11 * V_12 , struct V_13 * * V_14 ,
unsigned * V_15 , unsigned * V_16 ,
const char * V_6 , unsigned long * V_28 ,
unsigned V_29 )
{
unsigned long * V_30 ;
if ( F_8 ( * V_16 == * V_15 ) )
return - V_24 ;
V_30 = F_10 ( V_28 , V_29 * sizeof( * V_30 ) ,
V_21 ) ;
if ( ! V_30 )
return - V_22 ;
( * V_14 ) [ * V_16 ] . type = V_31 ;
( * V_14 ) [ * V_16 ] . V_26 . V_28 . V_32 = V_6 ;
( * V_14 ) [ * V_16 ] . V_26 . V_28 . V_28 = V_30 ;
( * V_14 ) [ * V_16 ] . V_26 . V_28 . V_29 = V_29 ;
( * V_16 ) ++ ;
return 0 ;
}
static int F_11 ( struct V_11 * V_12 , unsigned long * * V_28 ,
unsigned * V_29 , unsigned long V_33 )
{
unsigned V_18 = * V_29 ;
unsigned V_19 = V_18 + 1 ;
unsigned long * V_34 ;
V_34 = F_6 ( * V_28 , sizeof( * V_34 ) * V_19 ,
V_21 ) ;
if ( ! V_34 )
return - V_22 ;
V_34 [ V_18 ] = V_33 ;
* V_28 = V_34 ;
* V_29 = V_19 ;
return 0 ;
}
static void F_12 ( struct V_1 * V_2 ,
struct V_13 * V_14 ,
unsigned V_16 )
{
int V_35 ;
for ( V_35 = 0 ; V_35 < V_16 ; V_35 ++ )
if ( V_14 [ V_35 ] . type == V_31 )
F_13 ( V_14 [ V_35 ] . V_26 . V_28 . V_28 ) ;
F_13 ( V_14 ) ;
}
static int F_14 ( struct V_3 * V_36 ,
struct V_11 * V_12 ,
struct V_37 * V_38 ,
struct V_13 * * V_14 ,
unsigned * V_15 ,
unsigned * V_16 )
{
int V_39 , V_35 ;
T_1 V_40 ;
unsigned long V_33 ;
unsigned long * V_28 = NULL ;
unsigned V_29 = 0 ;
unsigned V_17 ;
struct V_41 * V_42 ;
const char * V_6 ;
bool V_43 = false ;
V_39 = F_15 ( V_38 , L_1 , & V_40 ) ;
if ( ! V_39 )
V_43 = true ;
for ( V_35 = 0 ; V_35 < F_16 ( V_44 ) ; V_35 ++ ) {
V_39 = F_15 ( V_38 , V_44 [ V_35 ] . V_41 , & V_40 ) ;
if ( ! V_39 ) {
V_33 = F_17 ( V_44 [ V_35 ] . V_45 , V_40 ) ;
V_39 = F_11 ( V_12 , & V_28 , & V_29 , V_33 ) ;
if ( V_39 < 0 )
goto exit;
} else if ( V_39 != - V_46 ) {
F_18 ( V_12 , L_2 ,
V_44 [ V_35 ] . V_41 ) ;
}
}
V_17 = 0 ;
if ( V_43 )
V_17 ++ ;
if ( V_29 )
V_17 ++ ;
V_39 = F_19 ( V_38 , L_3 ) ;
if ( V_39 < 0 ) {
F_18 ( V_12 , L_4 ) ;
goto exit;
}
V_17 *= V_39 ;
V_39 = F_5 ( V_12 , V_14 , V_15 , V_16 , V_17 ) ;
if ( V_39 < 0 )
goto exit;
F_20 (np, L_3 , prop, group) {
if ( V_43 ) {
V_39 = F_7 ( V_14 , V_15 ,
V_16 , V_6 , V_38 -> V_47 ) ;
if ( V_39 < 0 )
goto exit;
}
if ( V_29 ) {
V_39 = F_9 ( V_12 , V_14 , V_15 ,
V_16 , V_6 , V_28 ,
V_29 ) ;
if ( V_39 < 0 )
goto exit;
}
}
V_39 = 0 ;
exit:
F_13 ( V_28 ) ;
return V_39 ;
}
static int F_21 ( struct V_1 * V_2 ,
struct V_37 * V_48 ,
struct V_13 * * V_14 ,
unsigned * V_16 )
{
struct V_3 * V_36 ;
unsigned V_15 ;
struct V_37 * V_38 ;
int V_39 ;
V_36 = F_2 ( V_2 ) ;
V_15 = 0 ;
* V_14 = NULL ;
* V_16 = 0 ;
if ( ! F_22 ( V_48 ) )
return F_14 ( V_36 , V_2 -> V_12 ,
V_48 , V_14 ,
& V_15 ,
V_16 ) ;
F_23 (np_config, np) {
V_39 = F_14 ( V_36 , V_2 -> V_12 , V_38 , V_14 ,
& V_15 , V_16 ) ;
if ( V_39 < 0 ) {
F_12 ( V_2 , * V_14 , * V_16 ) ;
return V_39 ;
}
}
return 0 ;
}
static int F_24 ( struct V_1 * V_2 )
{
struct V_3 * V_36 ;
V_36 = F_2 ( V_2 ) ;
return V_36 -> V_49 ;
}
static const char * F_25 ( struct V_1 * V_2 ,
unsigned V_50 )
{
struct V_3 * V_36 ;
V_36 = F_2 ( V_2 ) ;
return V_36 -> V_51 [ V_50 ] . V_8 ;
}
static int F_26 ( struct V_1 * V_2 ,
unsigned V_50 , const char * const * * V_52 ,
unsigned * const V_53 )
{
struct V_3 * V_36 ;
V_36 = F_2 ( V_2 ) ;
* V_52 = V_36 -> V_51 [ V_50 ] . V_52 ;
* V_53 = V_36 -> V_51 [ V_50 ] . V_53 ;
return 0 ;
}
static void F_27 ( struct V_3 * V_36 ,
unsigned V_54 , void T_2 * * V_55 , T_1 * V_56 ,
struct V_57 * * V_58 )
{
struct V_57 * V_59 ;
V_59 = V_36 -> V_60 ;
while ( ( V_54 >= V_59 -> V_61 ) &&
( ( V_59 -> V_61 + V_59 -> V_62 - 1 ) < V_54 ) )
V_59 ++ ;
* V_55 = V_59 -> V_63 + V_59 -> V_64 ;
* V_56 = V_54 - V_59 -> V_61 ;
if ( V_58 )
* V_58 = V_59 ;
}
static void F_28 ( struct V_1 * V_2 , unsigned V_50 ,
unsigned V_6 )
{
struct V_3 * V_36 ;
const struct V_65 * type ;
struct V_57 * V_58 ;
void T_2 * V_55 ;
T_1 V_66 , V_67 , V_26 , V_68 ;
unsigned long V_69 ;
const struct V_70 * V_71 ;
const struct V_72 * V_73 ;
V_36 = F_2 ( V_2 ) ;
V_71 = & V_36 -> V_51 [ V_50 ] ;
V_73 = & V_36 -> V_7 [ V_6 ] ;
F_27 ( V_36 , V_73 -> V_9 [ 0 ] - V_36 -> V_61 ,
& V_55 , & V_68 , & V_58 ) ;
type = V_58 -> type ;
V_66 = ( 1 << type -> V_74 [ V_75 ] ) - 1 ;
V_67 = V_68 * type -> V_74 [ V_75 ] ;
if ( V_67 >= 32 ) {
V_67 -= 32 ;
V_55 += 4 ;
}
F_29 ( & V_58 -> V_76 , V_69 ) ;
V_26 = F_30 ( V_55 + type -> V_77 [ V_75 ] ) ;
V_26 &= ~ ( V_66 << V_67 ) ;
V_26 |= V_71 -> V_40 << V_67 ;
F_31 ( V_26 , V_55 + type -> V_77 [ V_75 ] ) ;
F_32 ( & V_58 -> V_76 , V_69 ) ;
}
static int F_33 ( struct V_1 * V_2 ,
unsigned V_50 ,
unsigned V_6 )
{
F_28 ( V_2 , V_50 , V_6 ) ;
return 0 ;
}
static int F_34 ( struct V_1 * V_2 , unsigned int V_54 ,
unsigned long * V_33 , bool V_78 )
{
struct V_3 * V_36 ;
const struct V_65 * type ;
struct V_57 * V_58 ;
void T_2 * V_79 ;
enum V_80 V_81 = F_35 ( * V_33 ) ;
T_1 V_26 , V_82 , V_68 , V_66 , V_67 ;
T_1 V_83 , V_84 ;
unsigned long V_69 ;
V_36 = F_2 ( V_2 ) ;
F_27 ( V_36 , V_54 - V_36 -> V_61 , & V_79 ,
& V_68 , & V_58 ) ;
type = V_58 -> type ;
if ( V_81 >= V_85 || ! type -> V_74 [ V_81 ] )
return - V_46 ;
V_82 = type -> V_74 [ V_81 ] ;
V_84 = type -> V_77 [ V_81 ] ;
F_29 ( & V_58 -> V_76 , V_69 ) ;
V_66 = ( 1 << V_82 ) - 1 ;
V_67 = V_68 * V_82 ;
V_26 = F_30 ( V_79 + V_84 ) ;
if ( V_78 ) {
V_83 = F_36 ( * V_33 ) ;
V_26 &= ~ ( V_66 << V_67 ) ;
V_26 |= ( V_83 << V_67 ) ;
F_31 ( V_26 , V_79 + V_84 ) ;
} else {
V_26 >>= V_67 ;
V_26 &= V_66 ;
* V_33 = F_17 ( V_81 , V_26 ) ;
}
F_32 ( & V_58 -> V_76 , V_69 ) ;
return 0 ;
}
static int F_37 ( struct V_1 * V_2 , unsigned int V_54 ,
unsigned long * V_28 , unsigned V_29 )
{
int V_35 , V_39 ;
for ( V_35 = 0 ; V_35 < V_29 ; V_35 ++ ) {
V_39 = F_34 ( V_2 , V_54 , & V_28 [ V_35 ] , true ) ;
if ( V_39 < 0 )
return V_39 ;
}
return 0 ;
}
static int F_38 ( struct V_1 * V_2 , unsigned int V_54 ,
unsigned long * V_33 )
{
return F_34 ( V_2 , V_54 , V_33 , false ) ;
}
static int F_39 ( struct V_1 * V_2 ,
unsigned V_6 , unsigned long * V_28 ,
unsigned V_29 )
{
struct V_3 * V_36 ;
const unsigned int * V_9 ;
unsigned int V_86 ;
V_36 = F_2 ( V_2 ) ;
V_9 = V_36 -> V_7 [ V_6 ] . V_9 ;
for ( V_86 = 0 ; V_86 < V_36 -> V_7 [ V_6 ] . V_10 ; V_86 ++ )
F_37 ( V_2 , V_9 [ V_86 ] , V_28 , V_29 ) ;
return 0 ;
}
static int F_40 ( struct V_1 * V_2 ,
unsigned int V_6 , unsigned long * V_33 )
{
struct V_3 * V_36 ;
const unsigned int * V_9 ;
V_36 = F_2 ( V_2 ) ;
V_9 = V_36 -> V_7 [ V_6 ] . V_9 ;
F_38 ( V_2 , V_9 [ 0 ] , V_33 ) ;
return 0 ;
}
static void F_41 ( struct V_87 * V_88 ,
unsigned V_56 , int V_89 )
{
struct V_57 * V_58 = F_42 ( V_88 ) ;
const struct V_65 * type = V_58 -> type ;
void T_2 * V_55 ;
T_1 V_26 ;
V_55 = V_58 -> V_63 + V_58 -> V_64 ;
V_26 = F_30 ( V_55 + type -> V_77 [ V_90 ] ) ;
V_26 &= ~ ( 1 << V_56 ) ;
if ( V_89 )
V_26 |= 1 << V_56 ;
F_31 ( V_26 , V_55 + type -> V_77 [ V_90 ] ) ;
}
static void F_43 ( struct V_87 * V_88 , unsigned V_56 , int V_89 )
{
struct V_57 * V_58 = F_42 ( V_88 ) ;
unsigned long V_69 ;
F_29 ( & V_58 -> V_76 , V_69 ) ;
F_41 ( V_88 , V_56 , V_89 ) ;
F_32 ( & V_58 -> V_76 , V_69 ) ;
}
static int F_44 ( struct V_87 * V_88 , unsigned V_56 )
{
void T_2 * V_55 ;
T_1 V_26 ;
struct V_57 * V_58 = F_42 ( V_88 ) ;
const struct V_65 * type = V_58 -> type ;
V_55 = V_58 -> V_63 + V_58 -> V_64 ;
V_26 = F_30 ( V_55 + type -> V_77 [ V_90 ] ) ;
V_26 >>= V_56 ;
V_26 &= 1 ;
return V_26 ;
}
static int F_45 ( struct V_87 * V_88 ,
unsigned V_56 , bool V_91 )
{
const struct V_65 * type ;
struct V_57 * V_58 ;
void T_2 * V_55 ;
T_1 V_26 , V_66 , V_67 ;
V_58 = F_42 ( V_88 ) ;
type = V_58 -> type ;
V_55 = V_58 -> V_63 + V_58 -> V_64
+ type -> V_77 [ V_75 ] ;
V_66 = ( 1 << type -> V_74 [ V_75 ] ) - 1 ;
V_67 = V_56 * type -> V_74 [ V_75 ] ;
if ( V_67 >= 32 ) {
V_67 -= 32 ;
V_55 += 4 ;
}
V_26 = F_30 ( V_55 ) ;
V_26 &= ~ ( V_66 << V_67 ) ;
if ( ! V_91 )
V_26 |= V_92 << V_67 ;
F_31 ( V_26 , V_55 ) ;
return 0 ;
}
static int F_46 ( struct V_87 * V_88 , unsigned V_56 )
{
struct V_57 * V_58 = F_42 ( V_88 ) ;
unsigned long V_69 ;
int V_39 ;
F_29 ( & V_58 -> V_76 , V_69 ) ;
V_39 = F_45 ( V_88 , V_56 , true ) ;
F_32 ( & V_58 -> V_76 , V_69 ) ;
return V_39 ;
}
static int F_47 ( struct V_87 * V_88 , unsigned V_56 ,
int V_89 )
{
struct V_57 * V_58 = F_42 ( V_88 ) ;
unsigned long V_69 ;
int V_39 ;
F_29 ( & V_58 -> V_76 , V_69 ) ;
F_41 ( V_88 , V_56 , V_89 ) ;
V_39 = F_45 ( V_88 , V_56 , false ) ;
F_32 ( & V_58 -> V_76 , V_69 ) ;
return V_39 ;
}
static int F_48 ( struct V_87 * V_88 , unsigned V_56 )
{
struct V_57 * V_58 = F_42 ( V_88 ) ;
unsigned int V_93 ;
if ( ! V_58 -> V_94 )
return - V_95 ;
V_93 = F_49 ( V_58 -> V_94 , V_56 ) ;
return ( V_93 ) ? : - V_95 ;
}
static struct V_72 * F_50 (
struct V_11 * V_12 ,
struct V_3 * V_36 ,
unsigned int * V_86 )
{
struct V_96 * V_97 = & V_36 -> V_98 ;
struct V_72 * V_52 , * V_73 ;
const struct V_99 * V_100 ;
int V_35 ;
V_52 = F_51 ( V_12 , V_97 -> V_101 * sizeof( * V_52 ) ,
V_21 ) ;
if ( ! V_52 )
return F_52 ( - V_46 ) ;
V_73 = V_52 ;
V_100 = V_97 -> V_9 ;
for ( V_35 = 0 ; V_35 < V_97 -> V_101 ; ++ V_35 , ++ V_100 , ++ V_73 ) {
V_73 -> V_8 = V_100 -> V_8 ;
V_73 -> V_9 = & V_100 -> V_102 ;
V_73 -> V_10 = 1 ;
}
* V_86 = V_97 -> V_101 ;
return V_52 ;
}
static int F_53 ( struct V_11 * V_12 ,
struct V_3 * V_36 ,
struct V_37 * V_103 ,
struct V_70 * V_71 )
{
int V_101 ;
int V_39 ;
int V_35 ;
if ( F_15 ( V_103 , L_1 , & V_71 -> V_40 ) )
return 0 ;
V_101 = F_19 ( V_103 , L_3 ) ;
if ( V_101 < 1 ) {
F_18 ( V_12 , L_5 , V_103 ) ;
return - V_46 ;
}
V_71 -> V_8 = V_103 -> V_47 ;
V_71 -> V_52 = F_51 ( V_12 , V_101 * sizeof( char * ) , V_21 ) ;
if ( ! V_71 -> V_52 )
return - V_22 ;
for ( V_35 = 0 ; V_35 < V_101 ; ++ V_35 ) {
const char * V_104 ;
V_39 = F_54 ( V_103 , L_3 ,
V_35 , & V_104 ) ;
if ( V_39 ) {
F_18 ( V_12 ,
L_6 ,
V_35 , V_103 ) ;
return V_39 ;
}
V_71 -> V_52 [ V_35 ] = V_104 ;
}
V_71 -> V_53 = V_101 ;
return 1 ;
}
static struct V_70 * F_55 (
struct V_11 * V_12 ,
struct V_3 * V_36 ,
unsigned int * V_86 )
{
struct V_70 * V_105 , * V_71 ;
struct V_37 * V_106 = V_12 -> V_107 ;
struct V_37 * V_108 ;
unsigned int V_109 = 0 ;
int V_39 ;
F_23 (dev_np, cfg_np) {
struct V_37 * V_103 ;
if ( ! F_22 ( V_108 ) ) {
if ( ! F_56 ( V_108 ,
L_1 , NULL ) )
continue;
++ V_109 ;
continue;
}
F_23 (cfg_np, func_np) {
if ( ! F_56 ( V_103 ,
L_1 , NULL ) )
continue;
++ V_109 ;
}
}
V_105 = F_51 ( V_12 , V_109 * sizeof( * V_105 ) ,
V_21 ) ;
if ( ! V_105 )
return F_52 ( - V_22 ) ;
V_71 = V_105 ;
V_109 = 0 ;
F_23 (dev_np, cfg_np) {
struct V_37 * V_103 ;
if ( ! F_22 ( V_108 ) ) {
V_39 = F_53 ( V_12 , V_36 ,
V_108 , V_71 ) ;
if ( V_39 < 0 )
return F_52 ( V_39 ) ;
if ( V_39 > 0 ) {
++ V_71 ;
++ V_109 ;
}
continue;
}
F_23 (cfg_np, func_np) {
V_39 = F_53 ( V_12 , V_36 ,
V_103 , V_71 ) ;
if ( V_39 < 0 )
return F_52 ( V_39 ) ;
if ( V_39 > 0 ) {
++ V_71 ;
++ V_109 ;
}
}
}
* V_86 = V_109 ;
return V_105 ;
}
static int F_57 ( struct V_110 * V_111 ,
struct V_3 * V_36 )
{
struct V_11 * V_12 = & V_111 -> V_12 ;
struct V_72 * V_52 ;
struct V_70 * V_105 ;
unsigned int V_112 = 0 , V_109 = 0 ;
V_52 = F_50 ( V_12 , V_36 , & V_112 ) ;
if ( F_58 ( V_52 ) ) {
F_18 ( V_12 , L_7 ) ;
return F_59 ( V_52 ) ;
}
V_105 = F_55 ( V_12 , V_36 , & V_109 ) ;
if ( F_58 ( V_105 ) ) {
F_18 ( V_12 , L_8 ) ;
return F_59 ( V_105 ) ;
}
V_36 -> V_7 = V_52 ;
V_36 -> V_5 = V_112 ;
V_36 -> V_51 = V_105 ;
V_36 -> V_49 = V_109 ;
return 0 ;
}
static int F_60 ( struct V_110 * V_111 ,
struct V_3 * V_36 )
{
struct V_96 * V_97 = & V_36 -> V_98 ;
struct V_99 * V_113 , * V_100 ;
struct V_57 * V_114 ;
char * V_115 ;
int V_54 , V_58 , V_39 ;
V_97 -> V_8 = L_9 ;
V_97 -> V_116 = V_117 ;
V_97 -> V_118 = & V_119 ;
V_97 -> V_120 = & V_121 ;
V_97 -> V_122 = & V_123 ;
V_113 = F_51 ( & V_111 -> V_12 , sizeof( * V_113 ) *
V_36 -> V_62 , V_21 ) ;
if ( ! V_113 )
return - V_22 ;
V_97 -> V_9 = V_113 ;
V_97 -> V_101 = V_36 -> V_62 ;
for ( V_54 = 0 , V_100 = V_113 ; V_54 < V_97 -> V_101 ; V_54 ++ , V_100 ++ )
V_100 -> V_102 = V_54 + V_36 -> V_61 ;
V_115 = F_51 ( & V_111 -> V_12 , sizeof( char ) * V_124 *
V_36 -> V_62 , V_21 ) ;
if ( ! V_115 )
return - V_22 ;
for ( V_58 = 0 ; V_58 < V_36 -> V_125 ; V_58 ++ ) {
V_114 = & V_36 -> V_60 [ V_58 ] ;
for ( V_54 = 0 ; V_54 < V_114 -> V_62 ; V_54 ++ ) {
sprintf ( V_115 , L_10 , V_114 -> V_8 , V_54 ) ;
V_100 = V_113 + V_114 -> V_61 + V_54 ;
V_100 -> V_8 = V_115 ;
V_115 += V_124 ;
}
}
V_39 = F_57 ( V_111 , V_36 ) ;
if ( V_39 )
return V_39 ;
V_36 -> V_126 = F_61 ( & V_111 -> V_12 , V_97 ,
V_36 ) ;
if ( F_58 ( V_36 -> V_126 ) ) {
F_18 ( & V_111 -> V_12 , L_11 ) ;
return F_59 ( V_36 -> V_126 ) ;
}
for ( V_58 = 0 ; V_58 < V_36 -> V_125 ; ++ V_58 ) {
V_114 = & V_36 -> V_60 [ V_58 ] ;
V_114 -> V_127 . V_8 = V_114 -> V_8 ;
V_114 -> V_127 . V_128 = V_58 ;
V_114 -> V_127 . V_61 = V_36 -> V_61
+ V_114 -> V_61 ;
V_114 -> V_127 . V_129 = V_114 -> V_127 . V_61 ;
V_114 -> V_127 . V_101 = V_114 -> V_87 . V_130 ;
V_114 -> V_127 . V_88 = & V_114 -> V_87 ;
F_62 ( V_36 -> V_126 , & V_114 -> V_127 ) ;
}
return 0 ;
}
static int F_63 ( struct V_110 * V_111 ,
struct V_3 * V_36 )
{
struct V_57 * V_58 = V_36 -> V_60 ;
int V_35 ;
for ( V_35 = 0 ; V_35 < V_36 -> V_125 ; ++ V_35 , ++ V_58 )
F_64 ( V_36 -> V_126 , & V_58 -> V_127 ) ;
return 0 ;
}
static int F_65 ( struct V_110 * V_111 ,
struct V_3 * V_36 )
{
struct V_57 * V_58 = V_36 -> V_60 ;
struct V_87 * V_88 ;
int V_39 ;
int V_35 ;
for ( V_35 = 0 ; V_35 < V_36 -> V_125 ; ++ V_35 , ++ V_58 ) {
V_58 -> V_87 = V_131 ;
V_88 = & V_58 -> V_87 ;
V_88 -> V_129 = V_58 -> V_127 . V_129 ;
V_88 -> V_130 = V_58 -> V_62 ;
V_88 -> V_132 = & V_111 -> V_12 ;
V_88 -> V_107 = V_58 -> V_107 ;
V_88 -> V_133 = V_58 -> V_8 ;
V_39 = F_66 ( & V_111 -> V_12 , V_88 , V_58 ) ;
if ( V_39 ) {
F_18 ( & V_111 -> V_12 , L_12 ,
V_88 -> V_133 , V_39 ) ;
return V_39 ;
}
}
return 0 ;
}
static const struct V_134 *
F_67 ( struct V_3 * V_135 ,
struct V_110 * V_111 )
{
int V_128 ;
struct V_37 * V_136 = V_111 -> V_12 . V_107 ;
struct V_37 * V_38 ;
const struct V_137 * V_138 ;
const struct V_134 * V_139 ;
struct V_57 * V_58 ;
struct V_140 * V_141 ;
void T_2 * V_142 [ V_143 ] ;
unsigned int V_35 ;
V_128 = F_68 ( V_136 , L_13 ) ;
if ( V_128 < 0 ) {
F_18 ( & V_111 -> V_12 , L_14 ) ;
return F_52 ( - V_144 ) ;
}
V_139 = F_69 ( & V_111 -> V_12 ) ;
V_139 += V_128 ;
V_135 -> V_145 = V_139 -> V_145 ;
V_135 -> V_146 = V_139 -> V_146 ;
V_135 -> V_125 = V_139 -> V_125 ;
V_135 -> V_60 = F_70 ( & V_111 -> V_12 , V_135 -> V_125 ,
sizeof( * V_135 -> V_60 ) , V_21 ) ;
if ( ! V_135 -> V_60 )
return F_52 ( - V_22 ) ;
if ( V_139 -> V_147 + 1 > V_143 )
return F_52 ( - V_46 ) ;
for ( V_35 = 0 ; V_35 < V_139 -> V_147 + 1 ; V_35 ++ ) {
V_141 = F_71 ( V_111 , V_148 , V_35 ) ;
if ( ! V_141 ) {
F_18 ( & V_111 -> V_12 , L_15 , V_35 ) ;
return F_52 ( - V_46 ) ;
}
V_142 [ V_35 ] = F_72 ( & V_111 -> V_12 , V_141 -> V_149 ,
F_73 ( V_141 ) ) ;
if ( ! V_142 [ V_35 ] ) {
F_18 ( & V_111 -> V_12 , L_16 , V_141 ) ;
return F_52 ( - V_150 ) ;
}
}
V_58 = V_135 -> V_60 ;
V_138 = V_139 -> V_60 ;
for ( V_35 = 0 ; V_35 < V_139 -> V_125 ; ++ V_35 , ++ V_138 , ++ V_58 ) {
V_58 -> type = V_138 -> type ;
V_58 -> V_64 = V_138 -> V_64 ;
V_58 -> V_62 = V_138 -> V_62 ;
V_58 -> V_151 = V_138 -> V_151 ;
V_58 -> V_152 = V_138 -> V_152 ;
V_58 -> V_153 = V_138 -> V_153 ;
V_58 -> V_154 = V_138 -> V_154 ;
V_58 -> V_8 = V_138 -> V_8 ;
F_74 ( & V_58 -> V_76 ) ;
V_58 -> V_36 = V_135 ;
V_58 -> V_61 = V_135 -> V_62 ;
V_135 -> V_62 += V_58 -> V_62 ;
V_58 -> V_155 = V_142 [ 0 ] ;
V_58 -> V_63 = V_142 [ V_138 -> V_156 ] ;
}
V_135 -> V_142 = V_142 [ 0 ] ;
F_23 (node, np) {
if ( ! F_56 ( V_38 , L_17 , NULL ) )
continue;
V_58 = V_135 -> V_60 ;
for ( V_35 = 0 ; V_35 < V_135 -> V_125 ; ++ V_35 , ++ V_58 ) {
if ( ! strcmp ( V_58 -> V_8 , V_38 -> V_8 ) ) {
V_58 -> V_107 = V_38 ;
break;
}
}
}
V_135 -> V_61 = V_61 ;
V_61 += V_135 -> V_62 ;
return V_139 ;
}
static int F_75 ( struct V_110 * V_111 )
{
struct V_3 * V_36 ;
const struct V_134 * V_139 ;
struct V_11 * V_12 = & V_111 -> V_12 ;
struct V_140 * V_141 ;
int V_39 ;
V_36 = F_51 ( V_12 , sizeof( * V_36 ) , V_21 ) ;
if ( ! V_36 )
return - V_22 ;
V_139 = F_67 ( V_36 , V_111 ) ;
if ( F_58 ( V_139 ) ) {
F_18 ( & V_111 -> V_12 , L_18 ) ;
return F_59 ( V_139 ) ;
}
V_36 -> V_12 = V_12 ;
V_141 = F_71 ( V_111 , V_157 , 0 ) ;
if ( V_141 )
V_36 -> V_158 = V_141 -> V_149 ;
if ( V_139 -> V_159 ) {
V_36 -> V_160 = V_139 -> V_159 -> V_161 ( V_36 ,
V_139 -> V_159 ) ;
if ( F_58 ( V_36 -> V_160 ) )
return F_59 ( V_36 -> V_160 ) ;
}
V_39 = F_60 ( V_111 , V_36 ) ;
if ( V_39 )
return V_39 ;
V_39 = F_65 ( V_111 , V_36 ) ;
if ( V_39 ) {
F_63 ( V_111 , V_36 ) ;
return V_39 ;
}
if ( V_139 -> V_162 )
V_139 -> V_162 ( V_36 ) ;
if ( V_139 -> V_163 )
V_139 -> V_163 ( V_36 ) ;
F_76 ( V_111 , V_36 ) ;
return 0 ;
}
static int T_3 F_77 ( struct V_11 * V_12 )
{
struct V_3 * V_36 = F_78 ( V_12 ) ;
int V_35 ;
for ( V_35 = 0 ; V_35 < V_36 -> V_125 ; V_35 ++ ) {
struct V_57 * V_58 = & V_36 -> V_60 [ V_35 ] ;
void T_2 * V_55 = V_58 -> V_63 + V_58 -> V_64 ;
const T_4 * V_164 = V_58 -> type -> V_77 ;
const T_4 * V_165 = V_58 -> type -> V_74 ;
enum V_80 type ;
if ( ! V_165 [ V_166 ] )
continue;
for ( type = 0 ; type < V_85 ; type ++ )
if ( V_165 [ type ] )
V_58 -> V_167 [ type ] = F_30 ( V_55 + V_164 [ type ] ) ;
if ( V_165 [ V_75 ] * V_58 -> V_62 > 32 ) {
V_58 -> V_167 [ V_85 ] =
F_30 ( V_55 + V_164 [ V_75 ] + 4 ) ;
F_79 ( L_19 ,
V_58 -> V_8 , V_55 ,
V_58 -> V_167 [ V_75 ] ,
V_58 -> V_167 [ V_85 ] ) ;
} else {
F_79 ( L_20 , V_58 -> V_8 ,
V_55 , V_58 -> V_167 [ V_75 ] ) ;
}
}
if ( V_36 -> V_145 )
V_36 -> V_145 ( V_36 ) ;
if ( V_36 -> V_160 && V_36 -> V_160 -> V_168 )
V_36 -> V_160 -> V_168 ( V_36 ) ;
return 0 ;
}
static int T_3 F_80 ( struct V_11 * V_12 )
{
struct V_3 * V_36 = F_78 ( V_12 ) ;
int V_35 ;
if ( V_36 -> V_146 )
V_36 -> V_146 ( V_36 ) ;
for ( V_35 = 0 ; V_35 < V_36 -> V_125 ; V_35 ++ ) {
struct V_57 * V_58 = & V_36 -> V_60 [ V_35 ] ;
void T_2 * V_55 = V_58 -> V_63 + V_58 -> V_64 ;
const T_4 * V_164 = V_58 -> type -> V_77 ;
const T_4 * V_165 = V_58 -> type -> V_74 ;
enum V_80 type ;
if ( ! V_165 [ V_166 ] )
continue;
if ( V_165 [ V_75 ] * V_58 -> V_62 > 32 ) {
F_79 ( L_21 ,
V_58 -> V_8 , V_55 ,
F_30 ( V_55 + V_164 [ V_75 ] ) ,
F_30 ( V_55 + V_164 [ V_75 ] + 4 ) ,
V_58 -> V_167 [ V_75 ] ,
V_58 -> V_167 [ V_85 ] ) ;
F_31 ( V_58 -> V_167 [ V_85 ] ,
V_55 + V_164 [ V_75 ] + 4 ) ;
} else {
F_79 ( L_22 , V_58 -> V_8 ,
V_55 , F_30 ( V_55 + V_164 [ V_75 ] ) ,
V_58 -> V_167 [ V_75 ] ) ;
}
for ( type = 0 ; type < V_85 ; type ++ )
if ( V_165 [ type ] )
F_31 ( V_58 -> V_167 [ type ] , V_55 + V_164 [ type ] ) ;
}
if ( V_36 -> V_160 && V_36 -> V_160 -> V_169 )
V_36 -> V_160 -> V_169 ( V_36 ) ;
return 0 ;
}
static int T_5 F_81 ( void )
{
return F_82 ( & V_170 ) ;
}
