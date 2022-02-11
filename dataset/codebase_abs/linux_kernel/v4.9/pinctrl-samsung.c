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
if ( ! V_20 ) {
F_7 ( V_12 , L_1 ) ;
return - V_22 ;
}
memset ( V_20 + V_18 , 0 , ( V_19 - V_18 ) * sizeof( * V_20 ) ) ;
* V_14 = V_20 ;
* V_15 = V_19 ;
return 0 ;
}
static int F_8 ( struct V_13 * * V_14 , unsigned * V_15 ,
unsigned * V_16 , const char * V_6 ,
const char * V_23 )
{
if ( F_9 ( * V_16 == * V_15 ) )
return - V_24 ;
( * V_14 ) [ * V_16 ] . type = V_25 ;
( * V_14 ) [ * V_16 ] . V_26 . V_27 . V_6 = V_6 ;
( * V_14 ) [ * V_16 ] . V_26 . V_27 . V_23 = V_23 ;
( * V_16 ) ++ ;
return 0 ;
}
static int F_10 ( struct V_11 * V_12 , struct V_13 * * V_14 ,
unsigned * V_15 , unsigned * V_16 ,
const char * V_6 , unsigned long * V_28 ,
unsigned V_29 )
{
unsigned long * V_30 ;
if ( F_9 ( * V_16 == * V_15 ) )
return - V_24 ;
V_30 = F_11 ( V_28 , V_29 * sizeof( * V_30 ) ,
V_21 ) ;
if ( ! V_30 ) {
F_7 ( V_12 , L_2 ) ;
return - V_22 ;
}
( * V_14 ) [ * V_16 ] . type = V_31 ;
( * V_14 ) [ * V_16 ] . V_26 . V_28 . V_32 = V_6 ;
( * V_14 ) [ * V_16 ] . V_26 . V_28 . V_28 = V_30 ;
( * V_14 ) [ * V_16 ] . V_26 . V_28 . V_29 = V_29 ;
( * V_16 ) ++ ;
return 0 ;
}
static int F_12 ( struct V_11 * V_12 , unsigned long * * V_28 ,
unsigned * V_29 , unsigned long V_33 )
{
unsigned V_18 = * V_29 ;
unsigned V_19 = V_18 + 1 ;
unsigned long * V_34 ;
V_34 = F_6 ( * V_28 , sizeof( * V_34 ) * V_19 ,
V_21 ) ;
if ( ! V_34 ) {
F_7 ( V_12 , L_3 ) ;
return - V_22 ;
}
V_34 [ V_18 ] = V_33 ;
* V_28 = V_34 ;
* V_29 = V_19 ;
return 0 ;
}
static void F_13 ( struct V_1 * V_2 ,
struct V_13 * V_14 ,
unsigned V_16 )
{
int V_35 ;
for ( V_35 = 0 ; V_35 < V_16 ; V_35 ++ )
if ( V_14 [ V_35 ] . type == V_31 )
F_14 ( V_14 [ V_35 ] . V_26 . V_28 . V_28 ) ;
F_14 ( V_14 ) ;
}
static int F_15 ( struct V_3 * V_36 ,
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
V_39 = F_16 ( V_38 , L_4 , & V_40 ) ;
if ( ! V_39 )
V_43 = true ;
for ( V_35 = 0 ; V_35 < F_17 ( V_44 ) ; V_35 ++ ) {
V_39 = F_16 ( V_38 , V_44 [ V_35 ] . V_41 , & V_40 ) ;
if ( ! V_39 ) {
V_33 = F_18 ( V_44 [ V_35 ] . V_45 , V_40 ) ;
V_39 = F_12 ( V_12 , & V_28 , & V_29 , V_33 ) ;
if ( V_39 < 0 )
goto exit;
} else if ( V_39 != - V_46 ) {
F_7 ( V_12 , L_5 ,
V_44 [ V_35 ] . V_41 ) ;
}
}
V_17 = 0 ;
if ( V_43 )
V_17 ++ ;
if ( V_29 )
V_17 ++ ;
V_39 = F_19 ( V_38 , L_6 ) ;
if ( V_39 < 0 ) {
F_7 ( V_12 , L_7 ) ;
goto exit;
}
V_17 *= V_39 ;
V_39 = F_5 ( V_12 , V_14 , V_15 , V_16 , V_17 ) ;
if ( V_39 < 0 )
goto exit;
F_20 (np, L_6 , prop, group) {
if ( V_43 ) {
V_39 = F_8 ( V_14 , V_15 ,
V_16 , V_6 , V_38 -> V_47 ) ;
if ( V_39 < 0 )
goto exit;
}
if ( V_29 ) {
V_39 = F_10 ( V_12 , V_14 , V_15 ,
V_16 , V_6 , V_28 ,
V_29 ) ;
if ( V_39 < 0 )
goto exit;
}
}
V_39 = 0 ;
exit:
F_14 ( V_28 ) ;
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
return F_15 ( V_36 , V_2 -> V_12 ,
V_48 , V_14 ,
& V_15 ,
V_16 ) ;
F_23 (np_config, np) {
V_39 = F_15 ( V_36 , V_2 -> V_12 , V_38 , V_14 ,
& V_15 , V_16 ) ;
if ( V_39 < 0 ) {
F_13 ( V_2 , * V_14 , * V_16 ) ;
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
* V_55 = V_36 -> V_63 + V_59 -> V_64 ;
* V_56 = V_54 - V_59 -> V_61 ;
if ( V_58 )
* V_58 = V_59 ;
}
static void F_28 ( struct V_1 * V_2 , unsigned V_50 ,
unsigned V_6 , bool V_65 )
{
struct V_3 * V_36 ;
const struct V_66 * type ;
struct V_57 * V_58 ;
void T_2 * V_55 ;
T_1 V_67 , V_68 , V_26 , V_69 ;
unsigned long V_70 ;
const struct V_71 * V_72 ;
const struct V_73 * V_74 ;
V_36 = F_2 ( V_2 ) ;
V_72 = & V_36 -> V_51 [ V_50 ] ;
V_74 = & V_36 -> V_7 [ V_6 ] ;
F_27 ( V_36 , V_74 -> V_9 [ 0 ] - V_36 -> V_61 ,
& V_55 , & V_69 , & V_58 ) ;
type = V_58 -> type ;
V_67 = ( 1 << type -> V_75 [ V_76 ] ) - 1 ;
V_68 = V_69 * type -> V_75 [ V_76 ] ;
if ( V_68 >= 32 ) {
V_68 -= 32 ;
V_55 += 4 ;
}
F_29 ( & V_58 -> V_77 , V_70 ) ;
V_26 = F_30 ( V_55 + type -> V_78 [ V_76 ] ) ;
V_26 &= ~ ( V_67 << V_68 ) ;
if ( V_65 )
V_26 |= V_72 -> V_40 << V_68 ;
F_31 ( V_26 , V_55 + type -> V_78 [ V_76 ] ) ;
F_32 ( & V_58 -> V_77 , V_70 ) ;
}
static int F_33 ( struct V_1 * V_2 ,
unsigned V_50 ,
unsigned V_6 )
{
F_28 ( V_2 , V_50 , V_6 , true ) ;
return 0 ;
}
static int F_34 ( struct V_1 * V_2 , unsigned int V_54 ,
unsigned long * V_33 , bool V_79 )
{
struct V_3 * V_36 ;
const struct V_66 * type ;
struct V_57 * V_58 ;
void T_2 * V_80 ;
enum V_81 V_82 = F_35 ( * V_33 ) ;
T_1 V_26 , V_83 , V_69 , V_67 , V_68 ;
T_1 V_84 , V_85 ;
unsigned long V_70 ;
V_36 = F_2 ( V_2 ) ;
F_27 ( V_36 , V_54 - V_36 -> V_61 , & V_80 ,
& V_69 , & V_58 ) ;
type = V_58 -> type ;
if ( V_82 >= V_86 || ! type -> V_75 [ V_82 ] )
return - V_46 ;
V_83 = type -> V_75 [ V_82 ] ;
V_85 = type -> V_78 [ V_82 ] ;
F_29 ( & V_58 -> V_77 , V_70 ) ;
V_67 = ( 1 << V_83 ) - 1 ;
V_68 = V_69 * V_83 ;
V_26 = F_30 ( V_80 + V_85 ) ;
if ( V_79 ) {
V_84 = F_36 ( * V_33 ) ;
V_26 &= ~ ( V_67 << V_68 ) ;
V_26 |= ( V_84 << V_68 ) ;
F_31 ( V_26 , V_80 + V_85 ) ;
} else {
V_26 >>= V_68 ;
V_26 &= V_67 ;
* V_33 = F_18 ( V_82 , V_26 ) ;
}
F_32 ( & V_58 -> V_77 , V_70 ) ;
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
unsigned int V_87 ;
V_36 = F_2 ( V_2 ) ;
V_9 = V_36 -> V_7 [ V_6 ] . V_9 ;
for ( V_87 = 0 ; V_87 < V_36 -> V_7 [ V_6 ] . V_10 ; V_87 ++ )
F_37 ( V_2 , V_9 [ V_87 ] , V_28 , V_29 ) ;
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
static void F_41 ( struct V_88 * V_89 ,
unsigned V_56 , int V_90 )
{
struct V_57 * V_58 = F_42 ( V_89 ) ;
const struct V_66 * type = V_58 -> type ;
void T_2 * V_55 ;
T_1 V_26 ;
V_55 = V_58 -> V_36 -> V_63 + V_58 -> V_64 ;
V_26 = F_30 ( V_55 + type -> V_78 [ V_91 ] ) ;
V_26 &= ~ ( 1 << V_56 ) ;
if ( V_90 )
V_26 |= 1 << V_56 ;
F_31 ( V_26 , V_55 + type -> V_78 [ V_91 ] ) ;
}
static void F_43 ( struct V_88 * V_89 , unsigned V_56 , int V_90 )
{
struct V_57 * V_58 = F_42 ( V_89 ) ;
unsigned long V_70 ;
F_29 ( & V_58 -> V_77 , V_70 ) ;
F_41 ( V_89 , V_56 , V_90 ) ;
F_32 ( & V_58 -> V_77 , V_70 ) ;
}
static int F_44 ( struct V_88 * V_89 , unsigned V_56 )
{
void T_2 * V_55 ;
T_1 V_26 ;
struct V_57 * V_58 = F_42 ( V_89 ) ;
const struct V_66 * type = V_58 -> type ;
V_55 = V_58 -> V_36 -> V_63 + V_58 -> V_64 ;
V_26 = F_30 ( V_55 + type -> V_78 [ V_91 ] ) ;
V_26 >>= V_56 ;
V_26 &= 1 ;
return V_26 ;
}
static int F_45 ( struct V_88 * V_89 ,
unsigned V_56 , bool V_92 )
{
const struct V_66 * type ;
struct V_57 * V_58 ;
struct V_3 * V_36 ;
void T_2 * V_55 ;
T_1 V_26 , V_67 , V_68 ;
V_58 = F_42 ( V_89 ) ;
type = V_58 -> type ;
V_36 = V_58 -> V_36 ;
V_55 = V_36 -> V_63 + V_58 -> V_64 +
type -> V_78 [ V_76 ] ;
V_67 = ( 1 << type -> V_75 [ V_76 ] ) - 1 ;
V_68 = V_56 * type -> V_75 [ V_76 ] ;
if ( V_68 >= 32 ) {
V_68 -= 32 ;
V_55 += 4 ;
}
V_26 = F_30 ( V_55 ) ;
V_26 &= ~ ( V_67 << V_68 ) ;
if ( ! V_92 )
V_26 |= V_93 << V_68 ;
F_31 ( V_26 , V_55 ) ;
return 0 ;
}
static int F_46 ( struct V_88 * V_89 , unsigned V_56 )
{
struct V_57 * V_58 = F_42 ( V_89 ) ;
unsigned long V_70 ;
int V_39 ;
F_29 ( & V_58 -> V_77 , V_70 ) ;
V_39 = F_45 ( V_89 , V_56 , true ) ;
F_32 ( & V_58 -> V_77 , V_70 ) ;
return V_39 ;
}
static int F_47 ( struct V_88 * V_89 , unsigned V_56 ,
int V_90 )
{
struct V_57 * V_58 = F_42 ( V_89 ) ;
unsigned long V_70 ;
int V_39 ;
F_29 ( & V_58 -> V_77 , V_70 ) ;
F_41 ( V_89 , V_56 , V_90 ) ;
V_39 = F_45 ( V_89 , V_56 , false ) ;
F_32 ( & V_58 -> V_77 , V_70 ) ;
return V_39 ;
}
static int F_48 ( struct V_88 * V_89 , unsigned V_56 )
{
struct V_57 * V_58 = F_42 ( V_89 ) ;
unsigned int V_94 ;
if ( ! V_58 -> V_95 )
return - V_96 ;
V_94 = F_49 ( V_58 -> V_95 , V_56 ) ;
return ( V_94 ) ? : - V_96 ;
}
static struct V_73 * F_50 (
struct V_11 * V_12 ,
struct V_3 * V_36 ,
unsigned int * V_87 )
{
struct V_97 * V_98 = & V_36 -> V_99 ;
struct V_73 * V_52 , * V_74 ;
const struct V_100 * V_101 ;
int V_35 ;
V_52 = F_51 ( V_12 , V_98 -> V_102 * sizeof( * V_52 ) ,
V_21 ) ;
if ( ! V_52 )
return F_52 ( - V_46 ) ;
V_74 = V_52 ;
V_101 = V_98 -> V_9 ;
for ( V_35 = 0 ; V_35 < V_98 -> V_102 ; ++ V_35 , ++ V_101 , ++ V_74 ) {
V_74 -> V_8 = V_101 -> V_8 ;
V_74 -> V_9 = & V_101 -> V_103 ;
V_74 -> V_10 = 1 ;
}
* V_87 = V_98 -> V_102 ;
return V_52 ;
}
static int F_53 ( struct V_11 * V_12 ,
struct V_3 * V_36 ,
struct V_37 * V_104 ,
struct V_71 * V_72 )
{
int V_102 ;
int V_39 ;
int V_35 ;
if ( F_16 ( V_104 , L_4 , & V_72 -> V_40 ) )
return 0 ;
V_102 = F_19 ( V_104 , L_6 ) ;
if ( V_102 < 1 ) {
F_7 ( V_12 , L_8 , V_104 -> V_8 ) ;
return - V_46 ;
}
V_72 -> V_8 = V_104 -> V_47 ;
V_72 -> V_52 = F_51 ( V_12 , V_102 * sizeof( char * ) , V_21 ) ;
if ( ! V_72 -> V_52 )
return - V_22 ;
for ( V_35 = 0 ; V_35 < V_102 ; ++ V_35 ) {
const char * V_105 ;
V_39 = F_54 ( V_104 , L_6 ,
V_35 , & V_105 ) ;
if ( V_39 ) {
F_7 ( V_12 ,
L_9 ,
V_35 , V_104 -> V_8 ) ;
return V_39 ;
}
V_72 -> V_52 [ V_35 ] = V_105 ;
}
V_72 -> V_53 = V_102 ;
return 1 ;
}
static struct V_71 * F_55 (
struct V_11 * V_12 ,
struct V_3 * V_36 ,
unsigned int * V_87 )
{
struct V_71 * V_106 , * V_72 ;
struct V_37 * V_107 = V_12 -> V_108 ;
struct V_37 * V_109 ;
unsigned int V_110 = 0 ;
int V_39 ;
F_23 (dev_np, cfg_np) {
struct V_37 * V_104 ;
if ( ! F_22 ( V_109 ) ) {
if ( ! F_56 ( V_109 ,
L_4 , NULL ) )
continue;
++ V_110 ;
continue;
}
F_23 (cfg_np, func_np) {
if ( ! F_56 ( V_104 ,
L_4 , NULL ) )
continue;
++ V_110 ;
}
}
V_106 = F_51 ( V_12 , V_110 * sizeof( * V_106 ) ,
V_21 ) ;
if ( ! V_106 ) {
F_7 ( V_12 , L_10 ) ;
return F_52 ( - V_46 ) ;
}
V_72 = V_106 ;
V_110 = 0 ;
F_23 (dev_np, cfg_np) {
struct V_37 * V_104 ;
if ( ! F_22 ( V_109 ) ) {
V_39 = F_53 ( V_12 , V_36 ,
V_109 , V_72 ) ;
if ( V_39 < 0 )
return F_52 ( V_39 ) ;
if ( V_39 > 0 ) {
++ V_72 ;
++ V_110 ;
}
continue;
}
F_23 (cfg_np, func_np) {
V_39 = F_53 ( V_12 , V_36 ,
V_104 , V_72 ) ;
if ( V_39 < 0 )
return F_52 ( V_39 ) ;
if ( V_39 > 0 ) {
++ V_72 ;
++ V_110 ;
}
}
}
* V_87 = V_110 ;
return V_106 ;
}
static int F_57 ( struct V_111 * V_112 ,
struct V_3 * V_36 )
{
struct V_11 * V_12 = & V_112 -> V_12 ;
struct V_73 * V_52 ;
struct V_71 * V_106 ;
unsigned int V_113 = 0 , V_110 = 0 ;
V_52 = F_50 ( V_12 , V_36 , & V_113 ) ;
if ( F_58 ( V_52 ) ) {
F_7 ( V_12 , L_11 ) ;
return F_59 ( V_52 ) ;
}
V_106 = F_55 ( V_12 , V_36 , & V_110 ) ;
if ( F_58 ( V_106 ) ) {
F_7 ( V_12 , L_12 ) ;
return F_59 ( V_106 ) ;
}
V_36 -> V_7 = V_52 ;
V_36 -> V_5 = V_113 ;
V_36 -> V_51 = V_106 ;
V_36 -> V_49 = V_110 ;
return 0 ;
}
static int F_60 ( struct V_111 * V_112 ,
struct V_3 * V_36 )
{
struct V_97 * V_98 = & V_36 -> V_99 ;
struct V_100 * V_114 , * V_101 ;
struct V_57 * V_115 ;
char * V_116 ;
int V_54 , V_58 , V_39 ;
V_98 -> V_8 = L_13 ;
V_98 -> V_117 = V_118 ;
V_98 -> V_119 = & V_120 ;
V_98 -> V_121 = & V_122 ;
V_98 -> V_123 = & V_124 ;
V_114 = F_51 ( & V_112 -> V_12 , sizeof( * V_114 ) *
V_36 -> V_62 , V_21 ) ;
if ( ! V_114 ) {
F_7 ( & V_112 -> V_12 , L_14 ) ;
return - V_22 ;
}
V_98 -> V_9 = V_114 ;
V_98 -> V_102 = V_36 -> V_62 ;
for ( V_54 = 0 , V_101 = V_114 ; V_54 < V_98 -> V_102 ; V_54 ++ , V_101 ++ )
V_101 -> V_103 = V_54 + V_36 -> V_61 ;
V_116 = F_51 ( & V_112 -> V_12 , sizeof( char ) * V_125 *
V_36 -> V_62 , V_21 ) ;
if ( ! V_116 ) {
F_7 ( & V_112 -> V_12 , L_15 ) ;
return - V_22 ;
}
for ( V_58 = 0 ; V_58 < V_36 -> V_126 ; V_58 ++ ) {
V_115 = & V_36 -> V_60 [ V_58 ] ;
for ( V_54 = 0 ; V_54 < V_115 -> V_62 ; V_54 ++ ) {
sprintf ( V_116 , L_16 , V_115 -> V_8 , V_54 ) ;
V_101 = V_114 + V_115 -> V_61 + V_54 ;
V_101 -> V_8 = V_116 ;
V_116 += V_125 ;
}
}
V_39 = F_57 ( V_112 , V_36 ) ;
if ( V_39 )
return V_39 ;
V_36 -> V_127 = F_61 ( & V_112 -> V_12 , V_98 ,
V_36 ) ;
if ( F_58 ( V_36 -> V_127 ) ) {
F_7 ( & V_112 -> V_12 , L_17 ) ;
return F_59 ( V_36 -> V_127 ) ;
}
for ( V_58 = 0 ; V_58 < V_36 -> V_126 ; ++ V_58 ) {
V_115 = & V_36 -> V_60 [ V_58 ] ;
V_115 -> V_128 . V_8 = V_115 -> V_8 ;
V_115 -> V_128 . V_129 = V_58 ;
V_115 -> V_128 . V_61 = V_36 -> V_61
+ V_115 -> V_61 ;
V_115 -> V_128 . V_130 = V_115 -> V_88 . V_130 ;
V_115 -> V_128 . V_102 = V_115 -> V_88 . V_131 ;
V_115 -> V_128 . V_89 = & V_115 -> V_88 ;
F_62 ( V_36 -> V_127 , & V_115 -> V_128 ) ;
}
return 0 ;
}
static int F_63 ( struct V_111 * V_112 ,
struct V_3 * V_36 )
{
struct V_57 * V_58 = V_36 -> V_60 ;
struct V_88 * V_89 ;
int V_39 ;
int V_35 ;
for ( V_35 = 0 ; V_35 < V_36 -> V_126 ; ++ V_35 , ++ V_58 ) {
V_58 -> V_88 = V_132 ;
V_89 = & V_58 -> V_88 ;
V_89 -> V_130 = V_36 -> V_61 + V_58 -> V_61 ;
V_89 -> V_131 = V_58 -> V_62 ;
V_89 -> V_133 = & V_112 -> V_12 ;
V_89 -> V_108 = V_58 -> V_108 ;
V_89 -> V_134 = V_58 -> V_8 ;
V_39 = F_64 ( V_89 , V_58 ) ;
if ( V_39 ) {
F_7 ( & V_112 -> V_12 , L_18 ,
V_89 -> V_134 , V_39 ) ;
goto V_135;
}
}
return 0 ;
V_135:
for ( -- V_35 , -- V_58 ; V_35 >= 0 ; -- V_35 , -- V_58 )
F_65 ( & V_58 -> V_88 ) ;
return V_39 ;
}
static int F_66 ( struct V_111 * V_112 ,
struct V_3 * V_36 )
{
struct V_57 * V_58 = V_36 -> V_60 ;
int V_35 ;
for ( V_35 = 0 ; V_35 < V_36 -> V_126 ; ++ V_35 , ++ V_58 )
F_65 ( & V_58 -> V_88 ) ;
return 0 ;
}
static const struct V_136 *
F_67 ( struct V_3 * V_137 ,
struct V_111 * V_112 )
{
int V_129 ;
const struct V_138 * V_139 ;
struct V_37 * V_140 = V_112 -> V_12 . V_108 ;
struct V_37 * V_38 ;
const struct V_141 * V_142 ;
const struct V_136 * V_143 ;
struct V_57 * V_58 ;
int V_35 ;
V_129 = F_68 ( V_140 , L_19 ) ;
if ( V_129 < 0 ) {
F_7 ( & V_112 -> V_12 , L_20 ) ;
return F_52 ( - V_144 ) ;
}
V_139 = F_69 ( V_145 , V_140 ) ;
V_143 = (struct V_136 * ) V_139 -> V_26 + V_129 ;
V_137 -> V_146 = V_143 -> V_146 ;
V_137 -> V_147 = V_143 -> V_147 ;
V_137 -> V_126 = V_143 -> V_126 ;
V_137 -> V_60 = F_70 ( & V_112 -> V_12 , V_137 -> V_126 ,
sizeof( * V_137 -> V_60 ) , V_21 ) ;
if ( ! V_137 -> V_60 )
return F_52 ( - V_22 ) ;
V_58 = V_137 -> V_60 ;
V_142 = V_143 -> V_60 ;
for ( V_35 = 0 ; V_35 < V_143 -> V_126 ; ++ V_35 , ++ V_142 , ++ V_58 ) {
V_58 -> type = V_142 -> type ;
V_58 -> V_64 = V_142 -> V_64 ;
V_58 -> V_62 = V_142 -> V_62 ;
V_58 -> V_148 = V_142 -> V_148 ;
V_58 -> V_149 = V_142 -> V_149 ;
V_58 -> V_150 = V_142 -> V_150 ;
V_58 -> V_151 = V_142 -> V_151 ;
V_58 -> V_8 = V_142 -> V_8 ;
F_71 ( & V_58 -> V_77 ) ;
V_58 -> V_36 = V_137 ;
V_58 -> V_61 = V_137 -> V_62 ;
V_137 -> V_62 += V_58 -> V_62 ;
}
F_23 (node, np) {
if ( ! F_56 ( V_38 , L_21 , NULL ) )
continue;
V_58 = V_137 -> V_60 ;
for ( V_35 = 0 ; V_35 < V_137 -> V_126 ; ++ V_35 , ++ V_58 ) {
if ( ! strcmp ( V_58 -> V_8 , V_38 -> V_8 ) ) {
V_58 -> V_108 = V_38 ;
break;
}
}
}
V_137 -> V_61 = V_61 ;
V_61 += V_137 -> V_62 ;
return V_143 ;
}
static int F_72 ( struct V_111 * V_112 )
{
struct V_3 * V_36 ;
const struct V_136 * V_143 ;
struct V_11 * V_12 = & V_112 -> V_12 ;
struct V_152 * V_153 ;
int V_39 ;
V_36 = F_51 ( V_12 , sizeof( * V_36 ) , V_21 ) ;
if ( ! V_36 )
return - V_22 ;
V_143 = F_67 ( V_36 , V_112 ) ;
if ( F_58 ( V_143 ) ) {
F_7 ( & V_112 -> V_12 , L_22 ) ;
return F_59 ( V_143 ) ;
}
V_36 -> V_12 = V_12 ;
V_153 = F_73 ( V_112 , V_154 , 0 ) ;
V_36 -> V_63 = F_74 ( & V_112 -> V_12 , V_153 ) ;
if ( F_58 ( V_36 -> V_63 ) )
return F_59 ( V_36 -> V_63 ) ;
V_153 = F_73 ( V_112 , V_155 , 0 ) ;
if ( V_153 )
V_36 -> V_156 = V_153 -> V_157 ;
V_39 = F_63 ( V_112 , V_36 ) ;
if ( V_39 )
return V_39 ;
V_39 = F_60 ( V_112 , V_36 ) ;
if ( V_39 ) {
F_66 ( V_112 , V_36 ) ;
return V_39 ;
}
if ( V_143 -> V_158 )
V_143 -> V_158 ( V_36 ) ;
if ( V_143 -> V_159 )
V_143 -> V_159 ( V_36 ) ;
F_75 ( V_112 , V_36 ) ;
F_76 ( & V_36 -> V_140 , & V_160 ) ;
return 0 ;
}
static void F_77 (
struct V_3 * V_36 )
{
void T_2 * V_63 = V_36 -> V_63 ;
int V_35 ;
for ( V_35 = 0 ; V_35 < V_36 -> V_126 ; V_35 ++ ) {
struct V_57 * V_58 = & V_36 -> V_60 [ V_35 ] ;
void T_2 * V_55 = V_63 + V_58 -> V_64 ;
const T_3 * V_161 = V_58 -> type -> V_78 ;
const T_3 * V_162 = V_58 -> type -> V_75 ;
enum V_81 type ;
if ( ! V_162 [ V_163 ] )
continue;
for ( type = 0 ; type < V_86 ; type ++ )
if ( V_162 [ type ] )
V_58 -> V_164 [ type ] = F_30 ( V_55 + V_161 [ type ] ) ;
if ( V_162 [ V_76 ] * V_58 -> V_62 > 32 ) {
V_58 -> V_164 [ V_86 ] =
F_30 ( V_55 + V_161 [ V_76 ] + 4 ) ;
F_78 ( L_23 ,
V_58 -> V_8 , V_55 ,
V_58 -> V_164 [ V_76 ] ,
V_58 -> V_164 [ V_86 ] ) ;
} else {
F_78 ( L_24 , V_58 -> V_8 ,
V_55 , V_58 -> V_164 [ V_76 ] ) ;
}
}
if ( V_36 -> V_146 )
V_36 -> V_146 ( V_36 ) ;
}
static void F_79 ( struct V_3 * V_36 )
{
void T_2 * V_63 = V_36 -> V_63 ;
int V_35 ;
if ( V_36 -> V_147 )
V_36 -> V_147 ( V_36 ) ;
for ( V_35 = 0 ; V_35 < V_36 -> V_126 ; V_35 ++ ) {
struct V_57 * V_58 = & V_36 -> V_60 [ V_35 ] ;
void T_2 * V_55 = V_63 + V_58 -> V_64 ;
const T_3 * V_161 = V_58 -> type -> V_78 ;
const T_3 * V_162 = V_58 -> type -> V_75 ;
enum V_81 type ;
if ( ! V_162 [ V_163 ] )
continue;
if ( V_162 [ V_76 ] * V_58 -> V_62 > 32 ) {
F_78 ( L_25 ,
V_58 -> V_8 , V_55 ,
F_30 ( V_55 + V_161 [ V_76 ] ) ,
F_30 ( V_55 + V_161 [ V_76 ] + 4 ) ,
V_58 -> V_164 [ V_76 ] ,
V_58 -> V_164 [ V_86 ] ) ;
F_31 ( V_58 -> V_164 [ V_86 ] ,
V_55 + V_161 [ V_76 ] + 4 ) ;
} else {
F_78 ( L_26 , V_58 -> V_8 ,
V_55 , F_30 ( V_55 + V_161 [ V_76 ] ) ,
V_58 -> V_164 [ V_76 ] ) ;
}
for ( type = 0 ; type < V_86 ; type ++ )
if ( V_162 [ type ] )
F_31 ( V_58 -> V_164 [ type ] , V_55 + V_161 [ type ] ) ;
}
}
static int F_80 ( void )
{
struct V_3 * V_36 ;
F_81 (drvdata, &drvdata_list, node) {
F_77 ( V_36 ) ;
}
return 0 ;
}
static void F_82 ( void )
{
struct V_3 * V_36 ;
F_83 (drvdata, &drvdata_list, node) {
F_79 ( V_36 ) ;
}
}
static int T_4 F_84 ( void )
{
F_85 ( & V_165 ) ;
return F_86 ( & V_166 ) ;
}
static void T_5 F_87 ( void )
{
F_88 ( & V_166 ) ;
}
