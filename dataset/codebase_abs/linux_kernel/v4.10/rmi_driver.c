void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 , * V_5 ;
struct V_6 * V_7 = F_2 ( & V_2 -> V_8 ) ;
F_3 ( V_9 , & V_2 -> V_8 , L_1 ) ;
F_4 ( & V_2 -> V_8 , V_7 -> V_10 ) ;
V_7 -> V_10 = NULL ;
V_7 -> V_11 = NULL ;
V_7 -> V_12 = NULL ;
V_7 -> V_13 = NULL ;
V_7 -> V_14 = NULL ;
V_7 -> V_15 = NULL ;
V_7 -> V_16 = NULL ;
F_5 (fn, tmp,
&data->function_list, node) {
F_6 ( & V_4 -> V_17 ) ;
F_7 ( V_4 ) ;
}
}
static int F_8 ( struct V_3 * V_4 )
{
struct V_18 * V_19 ;
int V_20 = 0 ;
if ( ! V_4 || ! V_4 -> V_8 . V_21 )
return 0 ;
V_19 = F_9 ( V_4 -> V_8 . V_21 ) ;
if ( V_19 -> V_22 ) {
V_20 = V_19 -> V_22 ( V_4 ) ;
if ( V_20 < 0 )
F_10 ( & V_4 -> V_8 , L_2 ,
V_20 ) ;
}
return V_20 ;
}
static int F_11 ( struct V_3 * V_4 )
{
struct V_18 * V_19 ;
int V_20 = 0 ;
if ( ! V_4 || ! V_4 -> V_8 . V_21 )
return 0 ;
V_19 = F_9 ( V_4 -> V_8 . V_21 ) ;
if ( V_19 -> V_23 ) {
V_20 = V_19 -> V_23 ( V_4 ) ;
if ( V_20 < 0 )
F_10 ( & V_4 -> V_8 , L_3 ,
V_20 ) ;
}
return V_20 ;
}
static int F_12 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( & V_2 -> V_8 ) ;
struct V_3 * V_24 ;
int V_20 ;
F_13 (entry, &data->function_list, node) {
V_20 = F_8 ( V_24 ) ;
if ( V_20 < 0 )
return V_20 ;
}
return 0 ;
}
static int F_14 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( & V_2 -> V_8 ) ;
struct V_3 * V_24 ;
int V_20 ;
F_13 (entry, &data->function_list, node) {
V_20 = F_11 ( V_24 ) ;
if ( V_20 < 0 )
return V_20 ;
}
return 0 ;
}
static void F_15 ( struct V_6 * V_7 ,
struct V_3 * V_4 )
{
struct V_18 * V_19 ;
if ( ! V_4 || ! V_4 -> V_8 . V_21 )
return;
V_19 = F_9 ( V_4 -> V_8 . V_21 ) ;
if ( V_19 -> V_25 ) {
F_16 ( V_7 -> V_12 , V_7 -> V_11 , V_4 -> V_26 ,
V_7 -> V_27 ) ;
if ( ! F_17 ( V_7 -> V_12 , V_7 -> V_27 ) )
V_19 -> V_25 ( V_4 , V_7 -> V_12 ) ;
}
}
static int F_18 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( & V_2 -> V_8 ) ;
struct V_28 * V_8 = & V_2 -> V_8 ;
struct V_3 * V_24 ;
int error ;
if ( ! V_7 )
return 0 ;
if ( ! V_7 -> V_29 . V_7 ) {
error = F_19 ( V_2 ,
V_7 -> V_15 -> V_30 . V_31 + 1 ,
V_7 -> V_11 , V_7 -> V_32 ) ;
if ( error < 0 ) {
F_10 ( V_8 , L_4 , error ) ;
return error ;
}
}
F_20 ( & V_7 -> V_33 ) ;
F_16 ( V_7 -> V_11 , V_7 -> V_11 , V_7 -> V_13 ,
V_7 -> V_27 ) ;
F_21 ( & V_7 -> V_33 ) ;
F_13 (entry, &data->function_list, node)
F_15 ( V_7 , V_24 ) ;
if ( V_7 -> V_34 )
F_22 ( V_7 -> V_34 ) ;
return 0 ;
}
void F_23 ( struct V_1 * V_2 , unsigned long V_11 ,
void * V_7 , T_1 V_35 )
{
struct V_6 * V_36 = F_2 ( & V_2 -> V_8 ) ;
struct V_37 V_29 ;
void * V_38 ;
if ( ! V_36 -> V_39 )
return;
V_38 = F_24 ( V_7 , V_35 , V_40 ) ;
if ( ! V_38 )
return;
V_29 . V_11 = V_11 ;
V_29 . V_35 = V_35 ;
V_29 . V_7 = V_38 ;
F_25 ( & V_36 -> V_41 , V_29 ) ;
}
static T_2 F_26 ( int V_42 , void * V_43 )
{
struct V_1 * V_2 = V_43 ;
struct V_6 * V_36 = F_2 ( & V_2 -> V_8 ) ;
struct V_37 V_29 = { 0 } ;
int V_44 , V_45 ;
V_45 = F_27 ( & V_36 -> V_41 , & V_29 ) ;
if ( V_45 ) {
* ( V_36 -> V_11 ) = V_29 . V_11 ;
V_36 -> V_29 = V_29 ;
}
V_44 = F_18 ( V_2 ) ;
if ( V_44 )
F_3 ( V_9 , & V_2 -> V_8 ,
L_5 , V_44 ) ;
if ( V_45 )
F_28 ( V_29 . V_7 ) ;
if ( ! F_29 ( & V_36 -> V_41 ) )
return F_26 ( V_42 , V_43 ) ;
return V_46 ;
}
static int F_30 ( struct V_1 * V_2 )
{
struct V_47 * V_48 = F_31 ( V_2 ) ;
struct V_6 * V_7 = F_2 ( & V_2 -> V_8 ) ;
int V_49 = F_32 ( V_48 -> V_42 ) ;
int V_44 ;
if ( ! V_49 )
V_49 = V_50 ;
V_44 = F_33 ( & V_2 -> V_8 , V_48 -> V_42 , NULL ,
F_26 , V_49 | V_51 ,
F_34 ( V_2 -> V_52 -> V_8 ) ,
V_2 ) ;
if ( V_44 < 0 ) {
F_10 ( & V_2 -> V_8 , L_6 ,
V_48 -> V_42 ) ;
return V_44 ;
}
V_7 -> V_39 = true ;
return 0 ;
}
static int F_35 ( struct V_3 * V_4 )
{
struct V_18 * V_19 ;
int V_20 = 0 ;
if ( ! V_4 || ! V_4 -> V_8 . V_21 )
return 0 ;
V_19 = F_9 ( V_4 -> V_8 . V_21 ) ;
if ( V_19 -> V_53 ) {
V_20 = V_19 -> V_53 ( V_4 ) ;
if ( V_20 < 0 )
F_10 ( & V_4 -> V_8 , L_7 ,
V_20 ) ;
}
return V_20 ;
}
static int F_36 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( & V_2 -> V_8 ) ;
struct V_3 * V_24 ;
int V_20 ;
F_13 (entry, &data->function_list, node) {
V_20 = F_35 ( V_24 ) ;
if ( V_20 < 0 )
return V_20 ;
}
return 0 ;
}
static int F_37 ( struct V_3 * V_4 )
{
struct V_18 * V_19 ;
int V_20 = 0 ;
if ( ! V_4 || ! V_4 -> V_8 . V_21 )
return 0 ;
V_19 = F_9 ( V_4 -> V_8 . V_21 ) ;
if ( V_19 -> V_54 ) {
V_20 = V_19 -> V_54 ( V_4 ) ;
if ( V_20 < 0 )
F_10 ( & V_4 -> V_8 , L_8 ,
V_20 ) ;
}
return V_20 ;
}
static int F_38 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( & V_2 -> V_8 ) ;
struct V_3 * V_24 ;
int V_20 ;
F_13 (entry, &data->function_list, node) {
V_20 = F_37 ( V_24 ) ;
if ( V_20 < 0 )
return V_20 ;
}
return 0 ;
}
int F_39 ( struct V_1 * V_2 )
{
int V_20 = 0 ;
V_20 = F_14 ( V_2 ) ;
if ( V_20 < 0 )
return V_20 ;
return F_18 ( V_2 ) ;
}
static int F_40 ( struct V_1 * V_2 ,
struct V_55 * V_34 )
{
V_34 -> V_56 = V_57 ;
V_34 -> V_58 . V_59 = V_60 ;
V_34 -> V_58 . V_61 = V_62 ;
return 0 ;
}
static void F_41 ( struct V_1 * V_2 ,
struct V_55 * V_34 )
{
struct V_6 * V_7 = F_2 ( & V_2 -> V_8 ) ;
char * V_63 = F_42 ( V_7 -> V_15 ) ;
char * V_56 ;
V_56 = F_43 ( & V_2 -> V_8 , V_64 ,
L_9 , V_63 ) ;
if ( ! V_56 )
return;
V_34 -> V_56 = V_56 ;
}
static int F_44 ( struct V_1 * V_2 ,
unsigned long * V_65 )
{
int error = 0 ;
struct V_6 * V_7 = F_2 ( & V_2 -> V_8 ) ;
struct V_28 * V_8 = & V_2 -> V_8 ;
F_20 ( & V_7 -> V_33 ) ;
F_45 ( V_7 -> V_14 ,
V_7 -> V_13 , V_65 , V_7 -> V_27 ) ;
error = F_46 ( V_2 ,
V_7 -> V_15 -> V_30 . V_66 + 1 ,
V_7 -> V_14 , V_7 -> V_32 ) ;
if ( error < 0 ) {
F_10 ( V_8 , L_10 ,
V_67 ) ;
goto V_68;
}
F_47 ( V_7 -> V_13 , V_7 -> V_14 ,
V_7 -> V_32 ) ;
V_68:
F_21 ( & V_7 -> V_33 ) ;
return error ;
}
static int F_48 ( struct V_1 * V_2 ,
unsigned long * V_65 )
{
int error = 0 ;
struct V_6 * V_7 = F_2 ( & V_2 -> V_8 ) ;
struct V_28 * V_8 = & V_2 -> V_8 ;
F_20 ( & V_7 -> V_33 ) ;
F_49 ( V_7 -> V_14 ,
V_7 -> V_13 , V_65 , V_7 -> V_27 ) ;
error = F_46 ( V_2 ,
V_7 -> V_15 -> V_30 . V_66 + 1 ,
V_7 -> V_14 , V_7 -> V_32 ) ;
if ( error < 0 ) {
F_10 ( V_8 , L_10 ,
V_67 ) ;
goto V_68;
}
F_47 ( V_7 -> V_13 , V_7 -> V_14 ,
V_7 -> V_32 ) ;
V_68:
F_21 ( & V_7 -> V_33 ) ;
return error ;
}
static int F_50 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( & V_2 -> V_8 ) ;
int error ;
if ( ! V_7 || ! V_7 -> V_15 ) {
F_51 ( & V_2 -> V_8 ,
L_11 ) ;
return 0 ;
}
error = F_19 ( V_2 ,
V_7 -> V_15 -> V_30 . V_66 + 1 ,
V_7 -> V_13 , V_7 -> V_32 ) ;
if ( error < 0 ) {
F_10 ( & V_2 -> V_8 , L_12 ,
V_67 ) ;
return error ;
}
error = F_12 ( V_2 ) ;
if ( error < 0 )
return error ;
error = F_14 ( V_2 ) ;
if ( error < 0 )
return error ;
return 0 ;
}
static int F_52 ( struct V_1 * V_2 ,
struct V_69 * V_24 , T_3 V_70 )
{
T_4 V_71 [ V_72 ] ;
int error ;
error = F_19 ( V_2 , V_70 , V_71 , V_72 ) ;
if ( error ) {
F_10 ( & V_2 -> V_8 , L_13 ,
V_70 , error ) ;
return error ;
}
V_24 -> V_73 = V_70 & V_74 ;
V_24 -> V_75 = V_71 [ 0 ] ;
V_24 -> V_76 = V_71 [ 1 ] ;
V_24 -> V_66 = V_71 [ 2 ] ;
V_24 -> V_31 = V_71 [ 3 ] ;
V_24 -> V_77 = V_71 [ 4 ] & V_78 ;
V_24 -> V_79 = ( V_71 [ 4 ] & V_80 ) >> 5 ;
V_24 -> V_81 = V_71 [ 5 ] ;
return 0 ;
}
static void F_53 ( const struct V_69 * V_82 ,
struct V_83 * V_30 )
{
V_30 -> V_75 = V_82 -> V_75 + V_82 -> V_73 ;
V_30 -> V_76 = V_82 -> V_76 + V_82 -> V_73 ;
V_30 -> V_66 = V_82 -> V_66 + V_82 -> V_73 ;
V_30 -> V_31 = V_82 -> V_31 + V_82 -> V_73 ;
V_30 -> V_81 = V_82 -> V_81 ;
V_30 -> V_77 = V_82 -> V_77 ;
V_30 -> V_79 = V_82 -> V_79 ;
}
static int F_54 ( struct V_1 * V_2 ,
int V_84 ,
int * V_85 ,
void * V_86 ,
int (* F_55)( struct V_1 * V_2 ,
void * V_86 ,
const struct V_69 * V_24 ) )
{
struct V_6 * V_7 = F_2 ( & V_2 -> V_8 ) ;
struct V_69 V_69 ;
T_3 V_73 = V_87 * V_84 ;
T_3 V_88 = V_73 + V_89 ;
T_3 V_90 = V_73 + V_91 ;
T_3 V_92 ;
int error ;
int V_20 ;
for ( V_92 = V_88 ; V_92 >= V_90 ; V_92 -= V_72 ) {
error = F_52 ( V_2 , & V_69 , V_92 ) ;
if ( error )
return error ;
if ( F_56 ( V_69 . V_81 ) )
break;
V_20 = F_55 ( V_2 , V_86 , & V_69 ) ;
if ( V_20 != V_93 )
return V_20 ;
}
if ( V_92 == V_88 )
++ * V_85 ;
else
* V_85 = 0 ;
return ( V_7 -> V_94 || * V_85 >= 2 ) ?
V_95 : V_93 ;
}
int F_57 ( struct V_1 * V_2 , void * V_86 ,
int (* F_55)( struct V_1 * V_2 ,
void * V_86 , const struct V_69 * V_24 ) )
{
int V_84 ;
int V_85 = 0 ;
int V_20 = V_95 ;
for ( V_84 = 0 ; V_84 <= V_96 ; V_84 ++ ) {
V_20 = F_54 ( V_2 , V_84 , & V_85 ,
V_86 , F_55 ) ;
if ( V_20 != V_93 )
break;
}
return V_20 < 0 ? V_20 : 0 ;
}
int F_58 ( struct V_1 * V_97 , T_3 V_92 ,
struct V_98 * V_99 )
{
int V_44 ;
T_4 V_100 ;
T_4 V_71 [ 35 ] ;
int V_101 = 1 ;
T_4 * V_102 ;
int V_103 ;
int V_104 = 0 ;
int V_105 = 0 ;
int V_106 ;
int V_107 ;
V_44 = F_59 ( V_97 , V_92 , & V_100 ) ;
if ( V_44 )
return V_44 ;
++ V_92 ;
if ( V_100 < 0 || V_100 > 35 )
return - V_108 ;
memset ( V_71 , 0 , sizeof( V_71 ) ) ;
V_44 = F_19 ( V_97 , V_92 , V_71 , V_100 ) ;
if ( V_44 )
return V_44 ;
++ V_92 ;
if ( V_71 [ 0 ] == 0 ) {
V_101 = 3 ;
V_99 -> V_109 = V_71 [ 1 ] | ( V_71 [ 2 ] << 8 ) ;
} else {
V_99 -> V_109 = V_71 [ 0 ] ;
}
for ( V_106 = V_101 ; V_106 < V_100 ; V_106 ++ ) {
for ( V_107 = 0 ; V_107 < 8 ; V_107 ++ ) {
if ( V_71 [ V_106 ] & ( 0x1 << V_107 ) )
F_60 ( V_99 -> V_110 , V_105 , 1 ) ;
++ V_105 ;
}
}
V_99 -> V_111 = F_61 ( V_99 -> V_110 ,
V_112 ) ;
V_99 -> V_113 = F_62 ( & V_97 -> V_8 , V_99 -> V_111 *
sizeof( struct V_114 ) ,
V_64 ) ;
if ( ! V_99 -> V_113 )
return - V_115 ;
V_102 = F_63 ( V_99 -> V_109 , V_64 ) ;
if ( ! V_102 )
return - V_115 ;
V_44 = F_19 ( V_97 , V_92 , V_102 , V_99 -> V_109 ) ;
if ( V_44 )
goto V_116;
V_103 = F_64 ( V_99 -> V_110 , V_112 ) ;
for ( V_106 = 0 ; V_106 < V_99 -> V_111 ; V_106 ++ ) {
struct V_114 * V_117 = & V_99 -> V_113 [ V_106 ] ;
int V_118 = V_102 [ V_104 ] ;
++ V_104 ;
if ( V_118 == 0 ) {
V_118 = V_102 [ V_104 ] |
( V_102 [ V_104 + 1 ] << 8 ) ;
V_104 += 2 ;
}
if ( V_118 == 0 ) {
V_118 = V_102 [ V_104 ] |
( V_102 [ V_104 + 1 ] << 8 ) |
( V_102 [ V_104 + 2 ] << 16 ) |
( V_102 [ V_104 + 3 ] << 24 ) ;
V_104 += 4 ;
}
V_117 -> V_103 = V_103 ;
V_117 -> V_118 = V_118 ;
V_105 = 0 ;
do {
for ( V_107 = 0 ; V_107 < 7 ; V_107 ++ ) {
if ( V_102 [ V_104 ] & ( 0x1 << V_107 ) )
F_60 ( V_117 -> V_119 ,
V_105 , 1 ) ;
++ V_105 ;
}
} while ( V_102 [ V_104 ++ ] & 0x80 );
V_117 -> V_120 = F_61 ( V_117 -> V_119 ,
V_121 ) ;
F_3 ( V_9 , & V_97 -> V_8 ,
L_14 , V_67 ,
V_117 -> V_103 , V_117 -> V_118 , V_117 -> V_120 ) ;
V_103 = F_65 ( V_99 -> V_110 ,
V_112 , V_103 + 1 ) ;
}
V_116:
F_28 ( V_102 ) ;
return V_44 ;
}
const struct V_114 * F_66 (
struct V_98 * V_99 , T_3 V_103 )
{
const struct V_114 * V_117 ;
int V_106 ;
for ( V_106 = 0 ; V_106 < V_99 -> V_111 ; V_106 ++ ) {
V_117 = & V_99 -> V_113 [ V_106 ] ;
if ( V_117 -> V_103 == V_103 )
return V_117 ;
}
return NULL ;
}
T_1 F_67 ( struct V_98 * V_99 )
{
const struct V_114 * V_117 ;
int V_106 ;
T_1 V_35 = 0 ;
for ( V_106 = 0 ; V_106 < V_99 -> V_111 ; V_106 ++ ) {
V_117 = & V_99 -> V_113 [ V_106 ] ;
V_35 += V_117 -> V_118 ;
}
return V_35 ;
}
int F_68 (
struct V_98 * V_99 , T_3 V_103 )
{
const struct V_114 * V_117 ;
int V_104 = 0 ;
int V_106 ;
for ( V_106 = 0 ; V_106 < V_99 -> V_111 ; V_106 ++ ) {
V_117 = & V_99 -> V_113 [ V_106 ] ;
if ( V_117 -> V_103 == V_103 )
return V_104 ;
++ V_104 ;
}
return - 1 ;
}
bool F_69 ( const struct V_114 * V_117 ,
T_4 V_122 )
{
return F_65 ( V_117 -> V_119 , V_112 ,
V_122 ) == V_122 ;
}
static int F_70 ( struct V_1 * V_2 ,
const struct V_69 * V_82 )
{
struct V_6 * V_7 = F_2 ( & V_2 -> V_8 ) ;
int V_44 ;
T_4 V_123 ;
if ( V_82 -> V_81 == 0x34 && V_82 -> V_79 > 1 ) {
V_44 = F_59 ( V_2 , V_82 -> V_31 , & V_123 ) ;
if ( V_44 ) {
F_10 ( & V_2 -> V_8 ,
L_15 , V_44 ) ;
return V_44 ;
}
if ( V_123 & F_71 ( 7 ) )
V_7 -> V_94 = true ;
} else if ( V_82 -> V_81 == 0x01 ) {
V_44 = F_59 ( V_2 , V_82 -> V_31 , & V_123 ) ;
if ( V_44 ) {
F_10 ( & V_2 -> V_8 ,
L_16 , V_44 ) ;
return V_44 ;
}
if ( V_123 & F_71 ( 6 ) )
V_7 -> V_94 = true ;
}
return 0 ;
}
static int F_72 ( struct V_1 * V_2 ,
void * V_86 , const struct V_69 * V_82 )
{
int * V_27 = V_86 ;
int V_44 ;
* V_27 += V_82 -> V_77 ;
V_44 = F_70 ( V_2 , V_82 ) ;
if ( V_44 < 0 )
return V_44 ;
return V_93 ;
}
int F_73 ( struct V_1 * V_2 , void * V_86 ,
const struct V_69 * V_82 )
{
int error ;
if ( V_82 -> V_81 == 0x01 ) {
T_3 V_124 = V_82 -> V_73 + V_82 -> V_76 ;
T_4 V_125 = V_126 ;
const struct V_47 * V_48 =
F_31 ( V_2 ) ;
if ( V_2 -> V_52 -> V_127 -> V_22 ) {
error = V_2 -> V_52 -> V_127 -> V_22 ( V_2 -> V_52 ,
V_124 ) ;
if ( error )
return error ;
return V_95 ;
}
F_3 ( V_9 , & V_2 -> V_8 , L_17 ) ;
error = F_46 ( V_2 , V_124 , & V_125 , 1 ) ;
if ( error ) {
F_10 ( & V_2 -> V_8 ,
L_18 , error ) ;
return error ;
}
F_74 ( V_48 -> V_128 ? : V_129 ) ;
return V_95 ;
}
return V_82 -> V_73 == 0 ? V_93 : - V_130 ;
}
static int F_75 ( struct V_1 * V_2 ,
void * V_86 , const struct V_69 * V_82 )
{
struct V_28 * V_8 = & V_2 -> V_8 ;
struct V_6 * V_7 = F_2 ( & V_2 -> V_8 ) ;
int * V_131 = V_86 ;
struct V_3 * V_4 ;
int V_106 ;
int error ;
F_3 ( V_9 , V_8 , L_19 ,
V_82 -> V_81 ) ;
V_4 = F_63 ( sizeof( struct V_3 ) +
F_76 ( V_7 -> V_27 ) * sizeof( unsigned long ) ,
V_64 ) ;
if ( ! V_4 ) {
F_10 ( V_8 , L_20 ,
V_82 -> V_81 ) ;
return - V_115 ;
}
F_77 ( & V_4 -> V_17 ) ;
F_53 ( V_82 , & V_4 -> V_30 ) ;
V_4 -> V_2 = V_2 ;
V_4 -> V_132 = V_82 -> V_77 ;
V_4 -> V_133 = * V_131 ;
* V_131 += V_4 -> V_132 ;
for ( V_106 = 0 ; V_106 < V_4 -> V_132 ; V_106 ++ )
F_78 ( V_4 -> V_133 + V_106 , V_4 -> V_26 ) ;
error = F_79 ( V_4 ) ;
if ( error )
goto V_134;
if ( V_82 -> V_81 == 0x01 )
V_7 -> V_15 = V_4 ;
else if ( V_82 -> V_81 == 0x34 )
V_7 -> V_16 = V_4 ;
F_80 ( & V_4 -> V_17 , & V_7 -> V_135 ) ;
return V_93 ;
V_134:
F_81 ( & V_4 -> V_8 ) ;
return error ;
}
void F_82 ( struct V_1 * V_2 , bool V_136 )
{
struct V_47 * V_48 = F_31 ( V_2 ) ;
struct V_6 * V_7 = F_2 ( & V_2 -> V_8 ) ;
int V_42 = V_48 -> V_42 ;
int V_49 ;
int V_20 ;
F_20 ( & V_7 -> V_137 ) ;
if ( V_7 -> V_39 )
goto V_138;
F_83 ( V_42 ) ;
V_7 -> V_39 = true ;
if ( V_136 && F_84 ( V_2 -> V_52 -> V_8 ) ) {
V_20 = F_85 ( V_42 ) ;
if ( V_20 )
F_51 ( & V_2 -> V_8 ,
L_21 ,
V_20 ) ;
}
V_49 = F_32 ( V_48 -> V_42 ) ;
if ( V_49 & V_139 )
F_18 ( V_2 ) ;
V_138:
F_21 ( & V_7 -> V_137 ) ;
}
void F_86 ( struct V_1 * V_2 , bool V_140 )
{
struct V_47 * V_48 = F_31 ( V_2 ) ;
struct V_6 * V_7 = F_2 ( & V_2 -> V_8 ) ;
struct V_37 V_29 = { 0 } ;
int V_42 = V_48 -> V_42 ;
int V_20 , V_45 ;
F_20 ( & V_7 -> V_137 ) ;
if ( ! V_7 -> V_39 )
goto V_138;
V_7 -> V_39 = false ;
F_87 ( V_42 ) ;
if ( V_140 && F_84 ( V_2 -> V_52 -> V_8 ) ) {
V_20 = F_88 ( V_42 ) ;
if ( V_20 )
F_51 ( & V_2 -> V_8 ,
L_22 ,
V_20 ) ;
}
while ( ! F_29 ( & V_7 -> V_41 ) ) {
V_45 = F_27 ( & V_7 -> V_41 , & V_29 ) ;
if ( V_45 )
F_28 ( V_29 . V_7 ) ;
}
V_138:
F_21 ( & V_7 -> V_137 ) ;
}
int F_89 ( struct V_1 * V_2 , bool V_140 )
{
int V_20 ;
V_20 = F_36 ( V_2 ) ;
if ( V_20 )
F_51 ( & V_2 -> V_8 , L_23 ,
V_20 ) ;
F_86 ( V_2 , V_140 ) ;
return V_20 ;
}
int F_90 ( struct V_1 * V_2 , bool V_136 )
{
int V_20 ;
F_82 ( V_2 , V_136 ) ;
V_20 = F_38 ( V_2 ) ;
if ( V_20 )
F_51 ( & V_2 -> V_8 , L_23 ,
V_20 ) ;
return V_20 ;
}
static int F_91 ( struct V_28 * V_8 )
{
struct V_1 * V_2 = F_92 ( V_8 ) ;
F_86 ( V_2 , false ) ;
F_93 ( V_2 ) ;
F_1 ( V_2 ) ;
return 0 ;
}
static int F_94 ( struct V_28 * V_8 ,
struct V_47 * V_48 )
{
int V_20 ;
V_20 = F_95 ( V_8 , & V_48 -> V_128 ,
L_24 , 1 ) ;
if ( V_20 )
return V_20 ;
return 0 ;
}
static inline int F_94 ( struct V_28 * V_8 ,
struct V_47 * V_48 )
{
return - V_130 ;
}
int F_96 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
struct V_28 * V_8 = & V_2 -> V_8 ;
int V_27 ;
T_1 V_35 ;
int V_20 ;
F_3 ( V_9 , V_8 , L_25 , V_67 ) ;
V_27 = 0 ;
V_7 -> V_94 = false ;
V_20 = F_57 ( V_2 , & V_27 , F_72 ) ;
if ( V_20 < 0 ) {
F_10 ( V_8 , L_26 , V_20 ) ;
return V_20 ;
}
if ( V_7 -> V_94 )
F_51 ( & V_2 -> V_8 , L_27 ) ;
V_7 -> V_27 = V_27 ;
V_7 -> V_32 = ( V_7 -> V_27 + 7 ) / 8 ;
V_35 = F_76 ( V_7 -> V_27 ) * sizeof( unsigned long ) ;
V_7 -> V_10 = F_62 ( V_8 , V_35 * 4 , V_64 ) ;
if ( ! V_7 -> V_10 ) {
F_10 ( V_8 , L_28 ) ;
return V_20 ;
}
V_7 -> V_11 = V_7 -> V_10 + V_35 * 0 ;
V_7 -> V_12 = V_7 -> V_10 + V_35 * 1 ;
V_7 -> V_13 = V_7 -> V_10 + V_35 * 2 ;
V_7 -> V_14 = V_7 -> V_10 + V_35 * 3 ;
return V_20 ;
}
int F_97 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
struct V_28 * V_8 = & V_2 -> V_8 ;
int V_27 ;
int V_20 ;
V_27 = 0 ;
F_3 ( V_9 , V_8 , L_29 , V_67 ) ;
V_20 = F_57 ( V_2 , & V_27 , F_75 ) ;
if ( V_20 < 0 ) {
F_10 ( V_8 , L_30 ,
V_20 ) ;
goto V_141;
}
if ( ! V_7 -> V_15 ) {
F_10 ( V_8 , L_31 ) ;
V_20 = - V_142 ;
goto V_141;
}
V_20 = F_19 ( V_2 ,
V_7 -> V_15 -> V_30 . V_66 + 1 ,
V_7 -> V_13 , V_7 -> V_32 ) ;
if ( V_20 < 0 ) {
F_10 ( V_8 , L_12 ,
V_67 ) ;
goto V_141;
}
return 0 ;
V_141:
F_1 ( V_2 ) ;
return V_20 ;
}
static int F_98 ( struct V_28 * V_8 )
{
struct V_143 * V_143 ;
struct V_6 * V_7 ;
struct V_47 * V_48 ;
struct V_1 * V_2 ;
int V_20 ;
F_3 ( V_9 , V_8 , L_32 ,
V_67 ) ;
if ( ! F_99 ( V_8 ) ) {
F_3 ( V_9 , V_8 , L_33 ) ;
return - V_130 ;
}
V_2 = F_92 ( V_8 ) ;
V_143 = F_100 ( V_8 -> V_21 ) ;
V_2 -> V_21 = V_143 ;
V_48 = F_31 ( V_2 ) ;
if ( V_2 -> V_52 -> V_8 -> V_144 ) {
V_20 = F_94 ( V_2 -> V_52 -> V_8 , V_48 ) ;
if ( V_20 )
return V_20 ;
}
V_7 = F_62 ( V_8 , sizeof( struct V_6 ) , V_64 ) ;
if ( ! V_7 )
return - V_115 ;
F_77 ( & V_7 -> V_135 ) ;
V_7 -> V_2 = V_2 ;
F_101 ( & V_2 -> V_8 , V_7 ) ;
V_20 = F_57 ( V_2 , NULL , F_73 ) ;
if ( V_20 < 0 )
F_51 ( V_8 , L_34 ) ;
V_20 = F_59 ( V_2 , V_145 , & V_7 -> V_146 ) ;
if ( V_20 < 0 ) {
F_51 ( V_8 , L_35 ,
V_145 , V_20 ) ;
}
F_102 ( & V_7 -> V_33 ) ;
F_102 ( & V_7 -> V_137 ) ;
V_20 = F_96 ( V_7 ) ;
if ( V_20 )
goto V_147;
if ( V_2 -> V_52 -> V_34 ) {
V_7 -> V_34 = V_2 -> V_52 -> V_34 ;
} else {
V_7 -> V_34 = F_103 ( V_8 ) ;
if ( ! V_7 -> V_34 ) {
F_10 ( V_8 , L_36 ,
V_67 ) ;
V_20 = - V_115 ;
goto V_147;
}
F_40 ( V_2 , V_7 -> V_34 ) ;
V_7 -> V_34 -> V_148 = F_43 ( V_8 , V_64 ,
L_37 , F_34 ( V_8 ) ) ;
}
V_20 = F_97 ( V_7 ) ;
if ( V_20 )
goto V_147;
V_20 = F_104 ( V_2 ) ;
if ( V_20 )
goto V_147;
if ( V_7 -> V_34 ) {
F_41 ( V_2 , V_7 -> V_34 ) ;
if ( ! V_2 -> V_52 -> V_34 ) {
if ( F_105 ( V_7 -> V_34 ) ) {
F_10 ( V_8 , L_38 ,
V_67 ) ;
goto V_141;
}
}
}
V_20 = F_30 ( V_2 ) ;
if ( V_20 < 0 )
goto V_141;
if ( V_7 -> V_15 -> V_8 . V_21 )
return F_39 ( V_2 ) ;
return 0 ;
V_141:
F_1 ( V_2 ) ;
V_147:
return V_20 < 0 ? V_20 : 0 ;
}
bool F_106 ( struct V_149 * V_150 )
{
return V_150 == & V_151 . V_21 ;
}
int T_5 F_107 ( void )
{
int error ;
error = F_108 ( & V_151 . V_21 ) ;
if ( error ) {
F_109 ( L_39 , V_67 ,
error ) ;
return error ;
}
return 0 ;
}
void T_6 F_110 ( void )
{
F_111 ( & V_151 . V_21 ) ;
}
