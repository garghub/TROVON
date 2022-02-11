static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 , * V_5 ;
struct V_6 * V_7 = F_2 ( & V_2 -> V_8 ) ;
V_7 -> V_9 = NULL ;
F_3 (fn, tmp,
&data->function_list, node) {
F_4 ( & V_4 -> V_10 ) ;
F_5 ( V_4 ) ;
}
}
static int F_6 ( struct V_3 * V_4 )
{
struct V_11 * V_12 ;
int V_13 = 0 ;
if ( ! V_4 || ! V_4 -> V_8 . V_14 )
return 0 ;
V_12 = F_7 ( V_4 -> V_8 . V_14 ) ;
if ( V_12 -> V_15 ) {
V_13 = V_12 -> V_15 ( V_4 ) ;
if ( V_13 < 0 )
F_8 ( & V_4 -> V_8 , L_1 ,
V_13 ) ;
}
return V_13 ;
}
static int F_9 ( struct V_3 * V_4 )
{
struct V_11 * V_12 ;
int V_13 = 0 ;
if ( ! V_4 || ! V_4 -> V_8 . V_14 )
return 0 ;
V_12 = F_7 ( V_4 -> V_8 . V_14 ) ;
if ( V_12 -> V_16 ) {
V_13 = V_12 -> V_16 ( V_4 ) ;
if ( V_13 < 0 )
F_8 ( & V_4 -> V_8 , L_2 ,
V_13 ) ;
}
return V_13 ;
}
static int F_10 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( & V_2 -> V_8 ) ;
struct V_3 * V_17 ;
int V_13 ;
F_11 (entry, &data->function_list, node) {
V_13 = F_6 ( V_17 ) ;
if ( V_13 < 0 )
return V_13 ;
}
return 0 ;
}
static int F_12 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( & V_2 -> V_8 ) ;
struct V_3 * V_17 ;
int V_13 ;
F_11 (entry, &data->function_list, node) {
V_13 = F_9 ( V_17 ) ;
if ( V_13 < 0 )
return V_13 ;
}
return 0 ;
}
static void F_13 ( struct V_6 * V_7 ,
struct V_3 * V_4 )
{
struct V_11 * V_12 ;
if ( ! V_4 || ! V_4 -> V_8 . V_14 )
return;
V_12 = F_7 ( V_4 -> V_8 . V_14 ) ;
if ( V_12 -> V_18 ) {
F_14 ( V_7 -> V_19 , V_7 -> V_20 , V_4 -> V_21 ,
V_7 -> V_22 ) ;
if ( ! F_15 ( V_7 -> V_19 , V_7 -> V_22 ) )
V_12 -> V_18 ( V_4 , V_7 -> V_19 ) ;
}
}
int F_16 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( & V_2 -> V_8 ) ;
struct V_23 * V_8 = & V_2 -> V_8 ;
struct V_3 * V_17 ;
int error ;
if ( ! V_7 )
return 0 ;
if ( ! V_2 -> V_24 -> V_25 ) {
error = F_17 ( V_2 ,
V_7 -> V_9 -> V_26 . V_27 + 1 ,
V_7 -> V_20 , V_7 -> V_28 ) ;
if ( error < 0 ) {
F_8 ( V_8 , L_3 , error ) ;
return error ;
}
}
F_18 ( & V_7 -> V_29 ) ;
F_14 ( V_7 -> V_20 , V_7 -> V_20 , V_7 -> V_30 ,
V_7 -> V_22 ) ;
F_19 ( & V_7 -> V_29 ) ;
F_11 (entry, &data->function_list, node)
F_13 ( V_7 , V_17 ) ;
if ( V_7 -> V_31 )
F_20 ( V_7 -> V_31 ) ;
return 0 ;
}
static int F_21 ( struct V_3 * V_4 )
{
struct V_11 * V_12 ;
int V_13 = 0 ;
if ( ! V_4 || ! V_4 -> V_8 . V_14 )
return 0 ;
V_12 = F_7 ( V_4 -> V_8 . V_14 ) ;
if ( V_12 -> V_32 ) {
V_13 = V_12 -> V_32 ( V_4 ) ;
if ( V_13 < 0 )
F_8 ( & V_4 -> V_8 , L_4 ,
V_13 ) ;
}
return V_13 ;
}
static int F_22 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( & V_2 -> V_8 ) ;
struct V_3 * V_17 ;
int V_13 ;
F_11 (entry, &data->function_list, node) {
V_13 = F_21 ( V_17 ) ;
if ( V_13 < 0 )
return V_13 ;
}
return 0 ;
}
static int F_23 ( struct V_3 * V_4 )
{
struct V_11 * V_12 ;
int V_13 = 0 ;
if ( ! V_4 || ! V_4 -> V_8 . V_14 )
return 0 ;
V_12 = F_7 ( V_4 -> V_8 . V_14 ) ;
if ( V_12 -> V_33 ) {
V_13 = V_12 -> V_33 ( V_4 ) ;
if ( V_13 < 0 )
F_8 ( & V_4 -> V_8 , L_5 ,
V_13 ) ;
}
return V_13 ;
}
static int F_24 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( & V_2 -> V_8 ) ;
struct V_3 * V_17 ;
int V_13 ;
F_11 (entry, &data->function_list, node) {
V_13 = F_23 ( V_17 ) ;
if ( V_13 < 0 )
return V_13 ;
}
return 0 ;
}
static int F_25 ( struct V_1 * V_2 )
{
int V_13 = 0 ;
V_13 = F_12 ( V_2 ) ;
if ( V_13 < 0 )
return V_13 ;
return F_16 ( V_2 ) ;
}
static int F_26 ( struct V_1 * V_2 ,
struct V_34 * V_31 )
{
V_31 -> V_35 = V_36 ;
V_31 -> V_37 . V_38 = V_39 ;
V_31 -> V_37 . V_40 = V_41 ;
return 0 ;
}
static void F_27 ( struct V_1 * V_2 ,
struct V_34 * V_31 )
{
struct V_6 * V_7 = F_2 ( & V_2 -> V_8 ) ;
char * V_42 = F_28 ( V_7 -> V_9 ) ;
char * V_35 ;
V_35 = F_29 ( & V_2 -> V_8 , V_43 ,
L_6 , V_42 ) ;
if ( ! V_35 )
return;
V_31 -> V_35 = V_35 ;
}
static int F_30 ( struct V_1 * V_2 ,
unsigned long * V_44 )
{
int error = 0 ;
struct V_6 * V_7 = F_2 ( & V_2 -> V_8 ) ;
struct V_23 * V_8 = & V_2 -> V_8 ;
F_18 ( & V_7 -> V_29 ) ;
F_31 ( V_7 -> V_45 ,
V_7 -> V_30 , V_44 , V_7 -> V_22 ) ;
error = F_32 ( V_2 ,
V_7 -> V_9 -> V_26 . V_46 + 1 ,
V_7 -> V_45 , V_7 -> V_28 ) ;
if ( error < 0 ) {
F_8 ( V_8 , L_7 ,
V_47 ) ;
goto V_48;
}
F_33 ( V_7 -> V_30 , V_7 -> V_45 ,
V_7 -> V_28 ) ;
V_48:
F_19 ( & V_7 -> V_29 ) ;
return error ;
}
static int F_34 ( struct V_1 * V_2 ,
unsigned long * V_44 )
{
int error = 0 ;
struct V_6 * V_7 = F_2 ( & V_2 -> V_8 ) ;
struct V_23 * V_8 = & V_2 -> V_8 ;
F_18 ( & V_7 -> V_29 ) ;
F_35 ( V_7 -> V_45 ,
V_7 -> V_30 , V_44 , V_7 -> V_22 ) ;
error = F_32 ( V_2 ,
V_7 -> V_9 -> V_26 . V_46 + 1 ,
V_7 -> V_45 , V_7 -> V_28 ) ;
if ( error < 0 ) {
F_8 ( V_8 , L_7 ,
V_47 ) ;
goto V_48;
}
F_33 ( V_7 -> V_30 , V_7 -> V_45 ,
V_7 -> V_28 ) ;
V_48:
F_19 ( & V_7 -> V_29 ) ;
return error ;
}
static int F_36 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( & V_2 -> V_8 ) ;
int error ;
if ( ! V_7 || ! V_7 -> V_9 ) {
F_37 ( & V_2 -> V_8 ,
L_8 ) ;
return 0 ;
}
error = F_17 ( V_2 ,
V_7 -> V_9 -> V_26 . V_46 + 1 ,
V_7 -> V_30 , V_7 -> V_28 ) ;
if ( error < 0 ) {
F_8 ( & V_2 -> V_8 , L_9 ,
V_47 ) ;
return error ;
}
error = F_10 ( V_2 ) ;
if ( error < 0 )
return error ;
error = F_12 ( V_2 ) ;
if ( error < 0 )
return error ;
return 0 ;
}
int F_38 ( struct V_1 * V_2 , struct V_49 * V_17 ,
T_1 V_50 )
{
T_2 V_51 [ V_52 ] ;
int error ;
error = F_17 ( V_2 , V_50 , V_51 , V_52 ) ;
if ( error ) {
F_8 ( & V_2 -> V_8 , L_10 ,
V_50 , error ) ;
return error ;
}
V_17 -> V_53 = V_50 & V_54 ;
V_17 -> V_55 = V_51 [ 0 ] ;
V_17 -> V_56 = V_51 [ 1 ] ;
V_17 -> V_46 = V_51 [ 2 ] ;
V_17 -> V_27 = V_51 [ 3 ] ;
V_17 -> V_57 = V_51 [ 4 ] & V_58 ;
V_17 -> V_59 = ( V_51 [ 4 ] & V_60 ) >> 5 ;
V_17 -> V_61 = V_51 [ 5 ] ;
return 0 ;
}
static void F_39 ( const struct V_49 * V_62 ,
struct V_63 * V_26 )
{
V_26 -> V_55 = V_62 -> V_55 + V_62 -> V_53 ;
V_26 -> V_56 = V_62 -> V_56 + V_62 -> V_53 ;
V_26 -> V_46 = V_62 -> V_46 + V_62 -> V_53 ;
V_26 -> V_27 = V_62 -> V_27 + V_62 -> V_53 ;
V_26 -> V_61 = V_62 -> V_61 ;
V_26 -> V_57 = V_62 -> V_57 ;
V_26 -> V_59 = V_62 -> V_59 ;
}
static int F_40 ( struct V_1 * V_2 ,
int V_64 ,
void * V_65 ,
int (* F_41)( struct V_1 * V_2 ,
void * V_65 ,
const struct V_49 * V_17 ) )
{
struct V_6 * V_7 = F_2 ( & V_2 -> V_8 ) ;
struct V_49 V_49 ;
T_1 V_53 = V_66 * V_64 ;
T_1 V_67 = V_53 + V_68 ;
T_1 V_69 = V_53 + V_70 ;
T_1 V_71 ;
int error ;
int V_13 ;
for ( V_71 = V_67 ; V_71 >= V_69 ; V_71 -= V_52 ) {
error = F_38 ( V_2 , & V_49 , V_71 ) ;
if ( error )
return error ;
if ( F_42 ( V_49 . V_61 ) )
break;
V_13 = F_41 ( V_2 , V_65 , & V_49 ) ;
if ( V_13 != V_72 )
return V_13 ;
}
return ( V_7 -> V_73 || V_71 == V_67 ) ?
V_74 : V_72 ;
}
static int F_43 ( struct V_1 * V_2 , void * V_65 ,
int (* F_41)( struct V_1 * V_2 ,
void * V_65 ,
const struct V_49 * V_17 ) )
{
int V_64 ;
int V_13 = V_74 ;
for ( V_64 = 0 ; V_64 <= V_75 ; V_64 ++ ) {
V_13 = F_40 ( V_2 , V_64 , V_65 , F_41 ) ;
if ( V_13 != V_72 )
break;
}
return V_13 < 0 ? V_13 : 0 ;
}
int F_44 ( struct V_1 * V_76 , T_1 V_71 ,
struct V_77 * V_78 )
{
int V_79 ;
T_2 V_80 ;
T_2 V_51 [ 35 ] ;
int V_81 = 1 ;
T_2 * V_82 ;
int V_83 ;
int V_84 = 0 ;
int V_85 = 0 ;
int V_86 ;
int V_87 ;
V_79 = F_45 ( V_76 , V_71 , & V_80 ) ;
if ( V_79 )
return V_79 ;
++ V_71 ;
if ( V_80 < 0 || V_80 > 35 )
return - V_88 ;
memset ( V_51 , 0 , sizeof( V_51 ) ) ;
V_79 = F_17 ( V_76 , V_71 , V_51 , V_80 ) ;
if ( V_79 )
return V_79 ;
++ V_71 ;
if ( V_51 [ 0 ] == 0 ) {
V_81 = 3 ;
V_78 -> V_89 = V_51 [ 1 ] | ( V_51 [ 2 ] << 8 ) ;
} else {
V_78 -> V_89 = V_51 [ 0 ] ;
}
for ( V_86 = V_81 ; V_86 < V_80 ; V_86 ++ ) {
for ( V_87 = 0 ; V_87 < 8 ; V_87 ++ ) {
if ( V_51 [ V_86 ] & ( 0x1 << V_87 ) )
F_46 ( V_78 -> V_90 , V_85 , 1 ) ;
++ V_85 ;
}
}
V_78 -> V_91 = F_47 ( V_78 -> V_90 ,
V_92 ) ;
V_78 -> V_93 = F_48 ( & V_76 -> V_8 , V_78 -> V_91 *
sizeof( struct V_94 ) ,
V_43 ) ;
if ( ! V_78 -> V_93 )
return - V_95 ;
V_82 = F_49 ( V_78 -> V_89 , V_43 ) ;
if ( ! V_82 )
return - V_95 ;
V_79 = F_17 ( V_76 , V_71 , V_82 , V_78 -> V_89 ) ;
if ( V_79 )
goto V_96;
V_83 = F_50 ( V_78 -> V_90 , V_92 ) ;
for ( V_86 = 0 ; V_86 < V_78 -> V_91 ; V_86 ++ ) {
struct V_94 * V_97 = & V_78 -> V_93 [ V_86 ] ;
int V_98 = V_82 [ V_84 ] ;
++ V_84 ;
if ( V_98 == 0 ) {
V_98 = V_82 [ V_84 ] |
( V_82 [ V_84 + 1 ] << 8 ) ;
V_84 += 2 ;
}
if ( V_98 == 0 ) {
V_98 = V_82 [ V_84 ] |
( V_82 [ V_84 + 1 ] << 8 ) |
( V_82 [ V_84 + 2 ] << 16 ) |
( V_82 [ V_84 + 3 ] << 24 ) ;
V_84 += 4 ;
}
V_97 -> V_83 = V_83 ;
V_97 -> V_98 = V_98 ;
V_85 = 0 ;
do {
for ( V_87 = 0 ; V_87 < 7 ; V_87 ++ ) {
if ( V_82 [ V_84 ] & ( 0x1 << V_87 ) )
F_46 ( V_97 -> V_99 ,
V_85 , 1 ) ;
++ V_85 ;
}
} while ( V_82 [ V_84 ++ ] & 0x80 );
V_97 -> V_100 = F_47 ( V_97 -> V_99 ,
V_101 ) ;
F_51 ( V_102 , & V_76 -> V_8 ,
L_11 , V_47 ,
V_97 -> V_83 , V_97 -> V_98 , V_97 -> V_100 ) ;
V_83 = F_52 ( V_78 -> V_90 ,
V_92 , V_83 + 1 ) ;
}
V_96:
F_53 ( V_82 ) ;
return V_79 ;
}
const struct V_94 * F_54 (
struct V_77 * V_78 , T_1 V_83 )
{
const struct V_94 * V_97 ;
int V_86 ;
for ( V_86 = 0 ; V_86 < V_78 -> V_91 ; V_86 ++ ) {
V_97 = & V_78 -> V_93 [ V_86 ] ;
if ( V_97 -> V_83 == V_83 )
return V_97 ;
}
return NULL ;
}
T_3 F_55 ( struct V_77 * V_78 )
{
const struct V_94 * V_97 ;
int V_86 ;
T_3 V_103 = 0 ;
for ( V_86 = 0 ; V_86 < V_78 -> V_91 ; V_86 ++ ) {
V_97 = & V_78 -> V_93 [ V_86 ] ;
V_103 += V_97 -> V_98 ;
}
return V_103 ;
}
int F_56 (
struct V_77 * V_78 , T_1 V_83 )
{
const struct V_94 * V_97 ;
int V_84 = 0 ;
int V_86 ;
for ( V_86 = 0 ; V_86 < V_78 -> V_91 ; V_86 ++ ) {
V_97 = & V_78 -> V_93 [ V_86 ] ;
if ( V_97 -> V_83 == V_83 )
return V_84 ;
++ V_84 ;
}
return - 1 ;
}
bool F_57 ( const struct V_94 * V_97 ,
T_2 V_104 )
{
return F_52 ( V_97 -> V_99 , V_92 ,
V_104 ) == V_104 ;
}
static int F_58 ( struct V_1 * V_2 ,
const struct V_49 * V_62 )
{
int error ;
T_2 V_105 ;
error = F_45 ( V_2 , V_62 -> V_27 + V_62 -> V_53 ,
& V_105 ) ;
if ( error ) {
F_8 ( & V_2 -> V_8 ,
L_12 , error ) ;
return error ;
}
return F_59 ( V_105 ) ;
}
static int F_60 ( struct V_1 * V_2 ,
void * V_65 , const struct V_49 * V_62 )
{
struct V_6 * V_7 = F_2 ( & V_2 -> V_8 ) ;
int * V_22 = V_65 ;
* V_22 += V_62 -> V_57 ;
if ( V_62 -> V_61 == 0x01 ) {
V_7 -> V_73 =
F_58 ( V_2 , V_62 ) ;
if ( V_7 -> V_73 )
F_37 ( & V_2 -> V_8 ,
L_13 ) ;
}
return V_72 ;
}
static int F_61 ( struct V_1 * V_2 ,
void * V_65 , const struct V_49 * V_62 )
{
int error ;
if ( V_62 -> V_61 == 0x01 ) {
T_1 V_106 = V_62 -> V_53 + V_62 -> V_56 ;
T_2 V_107 = V_108 ;
const struct V_109 * V_110 =
F_62 ( V_2 ) ;
if ( V_2 -> V_24 -> V_111 -> V_15 ) {
error = V_2 -> V_24 -> V_111 -> V_15 ( V_2 -> V_24 ,
V_106 ) ;
if ( error )
return error ;
return V_74 ;
}
error = F_32 ( V_2 , V_106 , & V_107 , 1 ) ;
if ( error ) {
F_8 ( & V_2 -> V_8 ,
L_14 , error ) ;
return error ;
}
F_63 ( V_110 -> V_112 ? : V_113 ) ;
return V_74 ;
}
return V_62 -> V_53 == 0 ? V_72 : - V_114 ;
}
static int F_64 ( struct V_1 * V_2 ,
void * V_65 , const struct V_49 * V_62 )
{
struct V_23 * V_8 = & V_2 -> V_8 ;
struct V_6 * V_7 = F_2 ( & V_2 -> V_8 ) ;
int * V_115 = V_65 ;
struct V_3 * V_4 ;
int V_86 ;
int error ;
F_51 ( V_102 , V_8 , L_15 ,
V_62 -> V_61 ) ;
V_4 = F_49 ( sizeof( struct V_3 ) +
F_65 ( V_7 -> V_22 ) * sizeof( unsigned long ) ,
V_43 ) ;
if ( ! V_4 ) {
F_8 ( V_8 , L_16 ,
V_62 -> V_61 ) ;
return - V_95 ;
}
F_66 ( & V_4 -> V_10 ) ;
F_39 ( V_62 , & V_4 -> V_26 ) ;
V_4 -> V_2 = V_2 ;
V_4 -> V_116 = V_62 -> V_57 ;
V_4 -> V_117 = * V_115 ;
* V_115 += V_4 -> V_116 ;
for ( V_86 = 0 ; V_86 < V_4 -> V_116 ; V_86 ++ )
F_67 ( V_4 -> V_117 + V_86 , V_4 -> V_21 ) ;
error = F_68 ( V_4 ) ;
if ( error )
goto V_118;
if ( V_62 -> V_61 == 0x01 )
V_7 -> V_9 = V_4 ;
F_69 ( & V_4 -> V_10 , & V_7 -> V_119 ) ;
return V_72 ;
V_118:
F_70 ( & V_4 -> V_8 ) ;
return error ;
}
int F_71 ( struct V_1 * V_2 )
{
int V_13 = 0 ;
V_13 = F_22 ( V_2 ) ;
if ( V_13 )
F_37 ( & V_2 -> V_8 , L_17 ,
V_13 ) ;
return V_13 ;
}
int F_72 ( struct V_1 * V_2 )
{
int V_13 ;
V_13 = F_24 ( V_2 ) ;
if ( V_13 )
F_37 ( & V_2 -> V_8 , L_17 ,
V_13 ) ;
return V_13 ;
}
static int F_73 ( struct V_23 * V_8 )
{
struct V_1 * V_2 = F_74 ( V_8 ) ;
F_1 ( V_2 ) ;
return 0 ;
}
static int F_75 ( struct V_23 * V_8 ,
struct V_109 * V_110 )
{
int V_13 ;
V_13 = F_76 ( V_8 , & V_110 -> V_112 ,
L_18 , 1 ) ;
if ( V_13 )
return V_13 ;
return 0 ;
}
static inline int F_75 ( struct V_23 * V_8 ,
struct V_109 * V_110 )
{
return - V_114 ;
}
static int F_77 ( struct V_23 * V_8 )
{
struct V_120 * V_120 ;
struct V_6 * V_7 ;
struct V_109 * V_110 ;
struct V_1 * V_2 ;
T_3 V_103 ;
void * V_121 ;
int V_22 ;
int V_13 ;
F_51 ( V_102 , V_8 , L_19 ,
V_47 ) ;
if ( ! F_78 ( V_8 ) ) {
F_51 ( V_102 , V_8 , L_20 ) ;
return - V_114 ;
}
V_2 = F_74 ( V_8 ) ;
V_120 = F_79 ( V_8 -> V_14 ) ;
V_2 -> V_14 = V_120 ;
V_110 = F_62 ( V_2 ) ;
if ( V_2 -> V_24 -> V_8 -> V_122 ) {
V_13 = F_75 ( V_2 -> V_24 -> V_8 , V_110 ) ;
if ( V_13 )
return V_13 ;
}
V_7 = F_48 ( V_8 , sizeof( struct V_6 ) , V_43 ) ;
if ( ! V_7 )
return - V_95 ;
F_66 ( & V_7 -> V_119 ) ;
V_7 -> V_2 = V_2 ;
F_80 ( & V_2 -> V_8 , V_7 ) ;
V_13 = F_43 ( V_2 , NULL , F_61 ) ;
if ( V_13 < 0 )
F_37 ( V_8 , L_21 ) ;
V_13 = F_45 ( V_2 , V_123 , & V_7 -> V_124 ) ;
if ( V_13 < 0 ) {
F_37 ( V_8 , L_22 ,
V_123 , V_13 ) ;
}
F_51 ( V_102 , V_8 , L_23 ) ;
V_22 = 0 ;
V_13 = F_43 ( V_2 , & V_22 , F_60 ) ;
if ( V_13 < 0 ) {
F_8 ( V_8 , L_24 , V_13 ) ;
goto V_125;
}
V_7 -> V_22 = V_22 ;
V_7 -> V_28 = ( V_7 -> V_22 + 7 ) / 8 ;
F_81 ( & V_7 -> V_29 ) ;
V_103 = F_65 ( V_7 -> V_22 ) * sizeof( unsigned long ) ;
V_121 = F_48 ( V_8 , V_103 * 4 , V_43 ) ;
if ( ! V_121 ) {
F_8 ( V_8 , L_25 ) ;
goto V_125;
}
V_7 -> V_20 = V_121 + V_103 * 0 ;
V_7 -> V_19 = V_121 + V_103 * 1 ;
V_7 -> V_30 = V_121 + V_103 * 2 ;
V_7 -> V_45 = V_121 + V_103 * 3 ;
if ( V_2 -> V_24 -> V_31 ) {
V_7 -> V_31 = V_2 -> V_24 -> V_31 ;
} else {
V_7 -> V_31 = F_82 ( V_8 ) ;
if ( ! V_7 -> V_31 ) {
F_8 ( V_8 , L_26 ,
V_47 ) ;
V_13 = - V_95 ;
goto V_126;
}
F_26 ( V_2 , V_7 -> V_31 ) ;
V_7 -> V_31 -> V_127 = F_29 ( V_8 , V_43 ,
L_27 , F_83 ( V_8 ) ) ;
}
V_22 = 0 ;
F_51 ( V_102 , V_8 , L_28 ) ;
V_13 = F_43 ( V_2 , & V_22 , F_64 ) ;
if ( V_13 < 0 ) {
F_8 ( V_8 , L_29 ,
V_13 ) ;
goto V_126;
}
if ( ! V_7 -> V_9 ) {
F_8 ( V_8 , L_30 ) ;
V_13 = - V_128 ;
goto V_126;
}
V_13 = F_17 ( V_2 ,
V_7 -> V_9 -> V_26 . V_46 + 1 ,
V_7 -> V_30 , V_7 -> V_28 ) ;
if ( V_13 < 0 ) {
F_8 ( V_8 , L_9 ,
V_47 ) ;
goto V_126;
}
if ( V_7 -> V_31 ) {
F_27 ( V_2 , V_7 -> V_31 ) ;
if ( ! V_2 -> V_24 -> V_31 ) {
if ( F_84 ( V_7 -> V_31 ) ) {
F_8 ( V_8 , L_31 ,
V_47 ) ;
goto V_126;
}
}
}
if ( V_7 -> V_9 -> V_8 . V_14 )
return F_25 ( V_2 ) ;
return 0 ;
V_126:
F_1 ( V_2 ) ;
V_125:
return V_13 < 0 ? V_13 : 0 ;
}
bool F_85 ( struct V_129 * V_130 )
{
return V_130 == & V_131 . V_14 ;
}
int T_4 F_86 ( void )
{
int error ;
error = F_87 ( & V_131 . V_14 ) ;
if ( error ) {
F_88 ( L_32 , V_47 ,
error ) ;
return error ;
}
return 0 ;
}
void T_5 F_89 ( void )
{
F_90 ( & V_131 . V_14 ) ;
}
