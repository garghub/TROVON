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
struct V_3 * F_35 ( struct V_1 * V_2 , T_3 V_53 )
{
struct V_6 * V_7 = F_2 ( & V_2 -> V_8 ) ;
struct V_3 * V_24 ;
F_13 (entry, &data->function_list, node) {
if ( V_24 -> V_30 . V_54 == V_53 )
return V_24 ;
}
return NULL ;
}
static int F_36 ( struct V_3 * V_4 )
{
struct V_18 * V_19 ;
int V_20 = 0 ;
if ( ! V_4 || ! V_4 -> V_8 . V_21 )
return 0 ;
V_19 = F_9 ( V_4 -> V_8 . V_21 ) ;
if ( V_19 -> V_55 ) {
V_20 = V_19 -> V_55 ( V_4 ) ;
if ( V_20 < 0 )
F_10 ( & V_4 -> V_8 , L_7 ,
V_20 ) ;
}
return V_20 ;
}
static int F_37 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( & V_2 -> V_8 ) ;
struct V_3 * V_24 ;
int V_20 ;
F_13 (entry, &data->function_list, node) {
V_20 = F_36 ( V_24 ) ;
if ( V_20 < 0 )
return V_20 ;
}
return 0 ;
}
static int F_38 ( struct V_3 * V_4 )
{
struct V_18 * V_19 ;
int V_20 = 0 ;
if ( ! V_4 || ! V_4 -> V_8 . V_21 )
return 0 ;
V_19 = F_9 ( V_4 -> V_8 . V_21 ) ;
if ( V_19 -> V_56 ) {
V_20 = V_19 -> V_56 ( V_4 ) ;
if ( V_20 < 0 )
F_10 ( & V_4 -> V_8 , L_8 ,
V_20 ) ;
}
return V_20 ;
}
static int F_39 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( & V_2 -> V_8 ) ;
struct V_3 * V_24 ;
int V_20 ;
F_13 (entry, &data->function_list, node) {
V_20 = F_38 ( V_24 ) ;
if ( V_20 < 0 )
return V_20 ;
}
return 0 ;
}
int F_40 ( struct V_1 * V_2 )
{
int V_20 = 0 ;
V_20 = F_14 ( V_2 ) ;
if ( V_20 < 0 )
return V_20 ;
return F_18 ( V_2 ) ;
}
static int F_41 ( struct V_1 * V_2 ,
struct V_57 * V_34 )
{
V_34 -> V_58 = V_59 ;
V_34 -> V_60 . V_61 = V_62 ;
V_34 -> V_60 . V_63 = V_64 ;
return 0 ;
}
static void F_42 ( struct V_1 * V_2 ,
struct V_57 * V_34 )
{
struct V_6 * V_7 = F_2 ( & V_2 -> V_8 ) ;
const char * V_65 = F_43 ( V_7 -> V_15 ) ;
char * V_58 ;
V_58 = F_44 ( & V_2 -> V_8 , V_66 ,
L_9 , V_65 ) ;
if ( ! V_58 )
return;
V_34 -> V_58 = V_58 ;
}
static int F_45 ( struct V_1 * V_2 ,
unsigned long * V_67 )
{
int error = 0 ;
struct V_6 * V_7 = F_2 ( & V_2 -> V_8 ) ;
struct V_28 * V_8 = & V_2 -> V_8 ;
F_20 ( & V_7 -> V_33 ) ;
F_46 ( V_7 -> V_14 ,
V_7 -> V_13 , V_67 , V_7 -> V_27 ) ;
error = F_47 ( V_2 ,
V_7 -> V_15 -> V_30 . V_68 + 1 ,
V_7 -> V_14 , V_7 -> V_32 ) ;
if ( error < 0 ) {
F_10 ( V_8 , L_10 ,
V_69 ) ;
goto V_70;
}
F_48 ( V_7 -> V_13 , V_7 -> V_14 ,
V_7 -> V_32 ) ;
V_70:
F_21 ( & V_7 -> V_33 ) ;
return error ;
}
static int F_49 ( struct V_1 * V_2 ,
unsigned long * V_67 )
{
int error = 0 ;
struct V_6 * V_7 = F_2 ( & V_2 -> V_8 ) ;
struct V_28 * V_8 = & V_2 -> V_8 ;
F_20 ( & V_7 -> V_33 ) ;
F_50 ( V_7 -> V_14 ,
V_7 -> V_13 , V_67 , V_7 -> V_27 ) ;
error = F_47 ( V_2 ,
V_7 -> V_15 -> V_30 . V_68 + 1 ,
V_7 -> V_14 , V_7 -> V_32 ) ;
if ( error < 0 ) {
F_10 ( V_8 , L_10 ,
V_69 ) ;
goto V_70;
}
F_48 ( V_7 -> V_13 , V_7 -> V_14 ,
V_7 -> V_32 ) ;
V_70:
F_21 ( & V_7 -> V_33 ) ;
return error ;
}
static int F_51 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( & V_2 -> V_8 ) ;
int error ;
if ( ! V_7 || ! V_7 -> V_15 ) {
F_52 ( & V_2 -> V_8 ,
L_11 ) ;
return 0 ;
}
error = F_19 ( V_2 ,
V_7 -> V_15 -> V_30 . V_68 + 1 ,
V_7 -> V_13 , V_7 -> V_32 ) ;
if ( error < 0 ) {
F_10 ( & V_2 -> V_8 , L_12 ,
V_69 ) ;
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
static int F_53 ( struct V_1 * V_2 ,
struct V_71 * V_24 , T_4 V_72 )
{
T_3 V_73 [ V_74 ] ;
int error ;
error = F_19 ( V_2 , V_72 , V_73 , V_74 ) ;
if ( error ) {
F_10 ( & V_2 -> V_8 , L_13 ,
V_72 , error ) ;
return error ;
}
V_24 -> V_75 = V_72 & V_76 ;
V_24 -> V_77 = V_73 [ 0 ] ;
V_24 -> V_78 = V_73 [ 1 ] ;
V_24 -> V_68 = V_73 [ 2 ] ;
V_24 -> V_31 = V_73 [ 3 ] ;
V_24 -> V_79 = V_73 [ 4 ] & V_80 ;
V_24 -> V_81 = ( V_73 [ 4 ] & V_82 ) >> 5 ;
V_24 -> V_54 = V_73 [ 5 ] ;
return 0 ;
}
static void F_54 ( const struct V_71 * V_83 ,
struct V_84 * V_30 )
{
V_30 -> V_77 = V_83 -> V_77 + V_83 -> V_75 ;
V_30 -> V_78 = V_83 -> V_78 + V_83 -> V_75 ;
V_30 -> V_68 = V_83 -> V_68 + V_83 -> V_75 ;
V_30 -> V_31 = V_83 -> V_31 + V_83 -> V_75 ;
V_30 -> V_54 = V_83 -> V_54 ;
V_30 -> V_79 = V_83 -> V_79 ;
V_30 -> V_81 = V_83 -> V_81 ;
}
static int F_55 ( struct V_1 * V_2 ,
int V_85 ,
int * V_86 ,
void * V_87 ,
int (* F_56)( struct V_1 * V_2 ,
void * V_87 ,
const struct V_71 * V_24 ) )
{
struct V_6 * V_7 = F_2 ( & V_2 -> V_8 ) ;
struct V_71 V_71 ;
T_4 V_75 = V_88 * V_85 ;
T_4 V_89 = V_75 + V_90 ;
T_4 V_91 = V_75 + V_92 ;
T_4 V_93 ;
int error ;
int V_20 ;
for ( V_93 = V_89 ; V_93 >= V_91 ; V_93 -= V_74 ) {
error = F_53 ( V_2 , & V_71 , V_93 ) ;
if ( error )
return error ;
if ( F_57 ( V_71 . V_54 ) )
break;
V_20 = F_56 ( V_2 , V_87 , & V_71 ) ;
if ( V_20 != V_94 )
return V_20 ;
}
if ( V_93 == V_89 )
++ * V_86 ;
else
* V_86 = 0 ;
return ( V_7 -> V_95 || * V_86 >= 2 ) ?
V_96 : V_94 ;
}
int F_58 ( struct V_1 * V_2 , void * V_87 ,
int (* F_56)( struct V_1 * V_2 ,
void * V_87 , const struct V_71 * V_24 ) )
{
int V_85 ;
int V_86 = 0 ;
int V_20 = V_96 ;
for ( V_85 = 0 ; V_85 <= V_97 ; V_85 ++ ) {
V_20 = F_55 ( V_2 , V_85 , & V_86 ,
V_87 , F_56 ) ;
if ( V_20 != V_94 )
break;
}
return V_20 < 0 ? V_20 : 0 ;
}
int F_59 ( struct V_1 * V_98 , T_4 V_93 ,
struct V_99 * V_100 )
{
int V_44 ;
T_3 V_101 ;
T_3 V_73 [ 35 ] ;
int V_102 = 1 ;
T_3 * V_103 ;
int V_104 ;
int V_105 = 0 ;
int V_106 = 0 ;
int V_107 ;
int V_108 ;
V_44 = F_60 ( V_98 , V_93 , & V_101 ) ;
if ( V_44 )
return V_44 ;
++ V_93 ;
if ( V_101 < 0 || V_101 > 35 )
return - V_109 ;
memset ( V_73 , 0 , sizeof( V_73 ) ) ;
V_44 = F_19 ( V_98 , V_93 , V_73 , V_101 ) ;
if ( V_44 )
return V_44 ;
++ V_93 ;
if ( V_73 [ 0 ] == 0 ) {
V_102 = 3 ;
V_100 -> V_110 = V_73 [ 1 ] | ( V_73 [ 2 ] << 8 ) ;
} else {
V_100 -> V_110 = V_73 [ 0 ] ;
}
for ( V_107 = V_102 ; V_107 < V_101 ; V_107 ++ ) {
for ( V_108 = 0 ; V_108 < 8 ; V_108 ++ ) {
if ( V_73 [ V_107 ] & ( 0x1 << V_108 ) )
F_61 ( V_100 -> V_111 , V_106 , 1 ) ;
++ V_106 ;
}
}
V_100 -> V_112 = F_62 ( V_100 -> V_111 ,
V_113 ) ;
V_100 -> V_114 = F_63 ( & V_98 -> V_8 , V_100 -> V_112 *
sizeof( struct V_115 ) ,
V_66 ) ;
if ( ! V_100 -> V_114 )
return - V_116 ;
V_103 = F_64 ( V_100 -> V_110 , V_66 ) ;
if ( ! V_103 )
return - V_116 ;
V_44 = F_19 ( V_98 , V_93 , V_103 , V_100 -> V_110 ) ;
if ( V_44 )
goto V_117;
V_104 = F_65 ( V_100 -> V_111 , V_113 ) ;
for ( V_107 = 0 ; V_107 < V_100 -> V_112 ; V_107 ++ ) {
struct V_115 * V_118 = & V_100 -> V_114 [ V_107 ] ;
int V_119 = V_103 [ V_105 ] ;
++ V_105 ;
if ( V_119 == 0 ) {
V_119 = V_103 [ V_105 ] |
( V_103 [ V_105 + 1 ] << 8 ) ;
V_105 += 2 ;
}
if ( V_119 == 0 ) {
V_119 = V_103 [ V_105 ] |
( V_103 [ V_105 + 1 ] << 8 ) |
( V_103 [ V_105 + 2 ] << 16 ) |
( V_103 [ V_105 + 3 ] << 24 ) ;
V_105 += 4 ;
}
V_118 -> V_104 = V_104 ;
V_118 -> V_119 = V_119 ;
V_106 = 0 ;
do {
for ( V_108 = 0 ; V_108 < 7 ; V_108 ++ ) {
if ( V_103 [ V_105 ] & ( 0x1 << V_108 ) )
F_61 ( V_118 -> V_120 ,
V_106 , 1 ) ;
++ V_106 ;
}
} while ( V_103 [ V_105 ++ ] & 0x80 );
V_118 -> V_121 = F_62 ( V_118 -> V_120 ,
V_122 ) ;
F_3 ( V_9 , & V_98 -> V_8 ,
L_14 , V_69 ,
V_118 -> V_104 , V_118 -> V_119 , V_118 -> V_121 ) ;
V_104 = F_66 ( V_100 -> V_111 ,
V_113 , V_104 + 1 ) ;
}
V_117:
F_28 ( V_103 ) ;
return V_44 ;
}
const struct V_115 * F_67 (
struct V_99 * V_100 , T_4 V_104 )
{
const struct V_115 * V_118 ;
int V_107 ;
for ( V_107 = 0 ; V_107 < V_100 -> V_112 ; V_107 ++ ) {
V_118 = & V_100 -> V_114 [ V_107 ] ;
if ( V_118 -> V_104 == V_104 )
return V_118 ;
}
return NULL ;
}
T_1 F_68 ( struct V_99 * V_100 )
{
const struct V_115 * V_118 ;
int V_107 ;
T_1 V_35 = 0 ;
for ( V_107 = 0 ; V_107 < V_100 -> V_112 ; V_107 ++ ) {
V_118 = & V_100 -> V_114 [ V_107 ] ;
V_35 += V_118 -> V_119 ;
}
return V_35 ;
}
int F_69 (
struct V_99 * V_100 , T_4 V_104 )
{
const struct V_115 * V_118 ;
int V_105 = 0 ;
int V_107 ;
for ( V_107 = 0 ; V_107 < V_100 -> V_112 ; V_107 ++ ) {
V_118 = & V_100 -> V_114 [ V_107 ] ;
if ( V_118 -> V_104 == V_104 )
return V_105 ;
++ V_105 ;
}
return - 1 ;
}
bool F_70 ( const struct V_115 * V_118 ,
T_3 V_123 )
{
return F_66 ( V_118 -> V_120 , V_113 ,
V_123 ) == V_123 ;
}
static int F_71 ( struct V_1 * V_2 ,
const struct V_71 * V_83 )
{
struct V_6 * V_7 = F_2 ( & V_2 -> V_8 ) ;
int V_44 ;
T_3 V_124 ;
if ( V_83 -> V_54 == 0x34 && V_83 -> V_81 > 1 ) {
V_44 = F_60 ( V_2 , V_83 -> V_31 , & V_124 ) ;
if ( V_44 ) {
F_10 ( & V_2 -> V_8 ,
L_15 , V_44 ) ;
return V_44 ;
}
if ( V_124 & F_72 ( 7 ) )
V_7 -> V_95 = true ;
} else if ( V_83 -> V_54 == 0x01 ) {
V_44 = F_60 ( V_2 , V_83 -> V_31 , & V_124 ) ;
if ( V_44 ) {
F_10 ( & V_2 -> V_8 ,
L_16 , V_44 ) ;
return V_44 ;
}
if ( V_124 & F_72 ( 6 ) )
V_7 -> V_95 = true ;
}
return 0 ;
}
static int F_73 ( struct V_1 * V_2 ,
void * V_87 , const struct V_71 * V_83 )
{
int * V_27 = V_87 ;
int V_44 ;
* V_27 += V_83 -> V_79 ;
V_44 = F_71 ( V_2 , V_83 ) ;
if ( V_44 < 0 )
return V_44 ;
return V_94 ;
}
int F_74 ( struct V_1 * V_2 , void * V_87 ,
const struct V_71 * V_83 )
{
int error ;
if ( V_83 -> V_54 == 0x01 ) {
T_4 V_125 = V_83 -> V_75 + V_83 -> V_78 ;
T_3 V_126 = V_127 ;
const struct V_47 * V_48 =
F_31 ( V_2 ) ;
if ( V_2 -> V_52 -> V_128 -> V_22 ) {
error = V_2 -> V_52 -> V_128 -> V_22 ( V_2 -> V_52 ,
V_125 ) ;
if ( error )
return error ;
return V_96 ;
}
F_3 ( V_9 , & V_2 -> V_8 , L_17 ) ;
error = F_47 ( V_2 , V_125 , & V_126 , 1 ) ;
if ( error ) {
F_10 ( & V_2 -> V_8 ,
L_18 , error ) ;
return error ;
}
F_75 ( V_48 -> V_129 ? : V_130 ) ;
return V_96 ;
}
return V_83 -> V_75 == 0 ? V_94 : - V_131 ;
}
static int F_76 ( struct V_1 * V_2 ,
void * V_87 , const struct V_71 * V_83 )
{
struct V_28 * V_8 = & V_2 -> V_8 ;
struct V_6 * V_7 = F_2 ( V_8 ) ;
int * V_132 = V_87 ;
struct V_3 * V_4 ;
int V_107 ;
int error ;
F_3 ( V_9 , V_8 , L_19 ,
V_83 -> V_54 ) ;
V_4 = F_64 ( sizeof( struct V_3 ) +
F_77 ( V_7 -> V_27 ) * sizeof( unsigned long ) ,
V_66 ) ;
if ( ! V_4 ) {
F_10 ( V_8 , L_20 ,
V_83 -> V_54 ) ;
return - V_116 ;
}
F_78 ( & V_4 -> V_17 ) ;
F_54 ( V_83 , & V_4 -> V_30 ) ;
V_4 -> V_2 = V_2 ;
V_4 -> V_133 = V_83 -> V_79 ;
V_4 -> V_134 = * V_132 ;
* V_132 += V_4 -> V_133 ;
for ( V_107 = 0 ; V_107 < V_4 -> V_133 ; V_107 ++ )
F_79 ( V_4 -> V_134 + V_107 , V_4 -> V_26 ) ;
error = F_80 ( V_4 ) ;
if ( error )
goto V_135;
if ( V_83 -> V_54 == 0x01 )
V_7 -> V_15 = V_4 ;
else if ( V_83 -> V_54 == 0x34 )
V_7 -> V_16 = V_4 ;
F_81 ( & V_4 -> V_17 , & V_7 -> V_136 ) ;
return V_94 ;
V_135:
F_82 ( & V_4 -> V_8 ) ;
return error ;
}
void F_83 ( struct V_1 * V_2 , bool V_137 )
{
struct V_47 * V_48 = F_31 ( V_2 ) ;
struct V_6 * V_7 = F_2 ( & V_2 -> V_8 ) ;
int V_42 = V_48 -> V_42 ;
int V_49 ;
int V_20 ;
F_20 ( & V_7 -> V_138 ) ;
if ( V_7 -> V_39 )
goto V_139;
F_84 ( V_42 ) ;
V_7 -> V_39 = true ;
if ( V_137 && F_85 ( V_2 -> V_52 -> V_8 ) ) {
V_20 = F_86 ( V_42 ) ;
if ( V_20 )
F_52 ( & V_2 -> V_8 ,
L_21 ,
V_20 ) ;
}
V_49 = F_32 ( V_48 -> V_42 ) ;
if ( V_49 & V_140 )
F_18 ( V_2 ) ;
V_139:
F_21 ( & V_7 -> V_138 ) ;
}
void F_87 ( struct V_1 * V_2 , bool V_141 )
{
struct V_47 * V_48 = F_31 ( V_2 ) ;
struct V_6 * V_7 = F_2 ( & V_2 -> V_8 ) ;
struct V_37 V_29 = { 0 } ;
int V_42 = V_48 -> V_42 ;
int V_20 , V_45 ;
F_20 ( & V_7 -> V_138 ) ;
if ( ! V_7 -> V_39 )
goto V_139;
V_7 -> V_39 = false ;
F_88 ( V_42 ) ;
if ( V_141 && F_85 ( V_2 -> V_52 -> V_8 ) ) {
V_20 = F_89 ( V_42 ) ;
if ( V_20 )
F_52 ( & V_2 -> V_8 ,
L_22 ,
V_20 ) ;
}
while ( ! F_29 ( & V_7 -> V_41 ) ) {
V_45 = F_27 ( & V_7 -> V_41 , & V_29 ) ;
if ( V_45 )
F_28 ( V_29 . V_7 ) ;
}
V_139:
F_21 ( & V_7 -> V_138 ) ;
}
int F_90 ( struct V_1 * V_2 , bool V_141 )
{
int V_20 ;
V_20 = F_37 ( V_2 ) ;
if ( V_20 )
F_52 ( & V_2 -> V_8 , L_23 ,
V_20 ) ;
F_87 ( V_2 , V_141 ) ;
return V_20 ;
}
int F_91 ( struct V_1 * V_2 , bool V_137 )
{
int V_20 ;
F_83 ( V_2 , V_137 ) ;
V_20 = F_39 ( V_2 ) ;
if ( V_20 )
F_52 ( & V_2 -> V_8 , L_23 ,
V_20 ) ;
return V_20 ;
}
static int F_92 ( struct V_28 * V_8 )
{
struct V_1 * V_2 = F_93 ( V_8 ) ;
F_87 ( V_2 , false ) ;
F_94 ( V_2 ) ;
F_1 ( V_2 ) ;
return 0 ;
}
static int F_95 ( struct V_28 * V_8 ,
struct V_47 * V_48 )
{
int V_20 ;
V_20 = F_96 ( V_8 , & V_48 -> V_129 ,
L_24 , 1 ) ;
if ( V_20 )
return V_20 ;
return 0 ;
}
static inline int F_95 ( struct V_28 * V_8 ,
struct V_47 * V_48 )
{
return - V_131 ;
}
int F_97 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
struct V_28 * V_8 = & V_2 -> V_8 ;
int V_27 ;
T_1 V_35 ;
int V_20 ;
F_3 ( V_9 , V_8 , L_25 , V_69 ) ;
V_27 = 0 ;
V_7 -> V_95 = false ;
V_20 = F_58 ( V_2 , & V_27 , F_73 ) ;
if ( V_20 < 0 ) {
F_10 ( V_8 , L_26 , V_20 ) ;
return V_20 ;
}
if ( V_7 -> V_95 )
F_52 ( V_8 , L_27 ) ;
V_7 -> V_27 = V_27 ;
V_7 -> V_32 = ( V_7 -> V_27 + 7 ) / 8 ;
V_35 = F_77 ( V_7 -> V_27 ) * sizeof( unsigned long ) ;
V_7 -> V_10 = F_63 ( V_8 , V_35 * 4 , V_66 ) ;
if ( ! V_7 -> V_10 ) {
F_10 ( V_8 , L_28 ) ;
return - V_116 ;
}
V_7 -> V_11 = V_7 -> V_10 + V_35 * 0 ;
V_7 -> V_12 = V_7 -> V_10 + V_35 * 1 ;
V_7 -> V_13 = V_7 -> V_10 + V_35 * 2 ;
V_7 -> V_14 = V_7 -> V_10 + V_35 * 3 ;
return V_20 ;
}
int F_98 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
struct V_28 * V_8 = & V_2 -> V_8 ;
int V_27 ;
int V_20 ;
V_27 = 0 ;
F_3 ( V_9 , V_8 , L_29 , V_69 ) ;
V_20 = F_58 ( V_2 , & V_27 , F_76 ) ;
if ( V_20 < 0 ) {
F_10 ( V_8 , L_30 ,
V_20 ) ;
goto V_142;
}
if ( ! V_7 -> V_15 ) {
F_10 ( V_8 , L_31 ) ;
V_20 = - V_143 ;
goto V_142;
}
V_20 = F_19 ( V_2 ,
V_7 -> V_15 -> V_30 . V_68 + 1 ,
V_7 -> V_13 , V_7 -> V_32 ) ;
if ( V_20 < 0 ) {
F_10 ( V_8 , L_12 ,
V_69 ) ;
goto V_142;
}
return 0 ;
V_142:
F_1 ( V_2 ) ;
return V_20 ;
}
static int F_99 ( struct V_28 * V_8 )
{
struct V_144 * V_144 ;
struct V_6 * V_7 ;
struct V_47 * V_48 ;
struct V_1 * V_2 ;
int V_20 ;
F_3 ( V_9 , V_8 , L_32 ,
V_69 ) ;
if ( ! F_100 ( V_8 ) ) {
F_3 ( V_9 , V_8 , L_33 ) ;
return - V_131 ;
}
V_2 = F_93 ( V_8 ) ;
V_144 = F_101 ( V_8 -> V_21 ) ;
V_2 -> V_21 = V_144 ;
V_48 = F_31 ( V_2 ) ;
if ( V_2 -> V_52 -> V_8 -> V_145 ) {
V_20 = F_95 ( V_2 -> V_52 -> V_8 , V_48 ) ;
if ( V_20 )
return V_20 ;
}
V_7 = F_63 ( V_8 , sizeof( struct V_6 ) , V_66 ) ;
if ( ! V_7 )
return - V_116 ;
F_78 ( & V_7 -> V_136 ) ;
V_7 -> V_2 = V_2 ;
F_102 ( & V_2 -> V_8 , V_7 ) ;
V_20 = F_58 ( V_2 , NULL , F_74 ) ;
if ( V_20 < 0 )
F_52 ( V_8 , L_34 ) ;
V_20 = F_60 ( V_2 , V_146 , & V_7 -> V_147 ) ;
if ( V_20 < 0 ) {
F_52 ( V_8 , L_35 ,
V_146 , V_20 ) ;
}
F_103 ( & V_7 -> V_33 ) ;
F_103 ( & V_7 -> V_138 ) ;
V_20 = F_97 ( V_7 ) ;
if ( V_20 )
goto V_148;
if ( V_2 -> V_52 -> V_34 ) {
V_7 -> V_34 = V_2 -> V_52 -> V_34 ;
} else {
V_7 -> V_34 = F_104 ( V_8 ) ;
if ( ! V_7 -> V_34 ) {
F_10 ( V_8 , L_36 ,
V_69 ) ;
V_20 = - V_116 ;
goto V_148;
}
F_41 ( V_2 , V_7 -> V_34 ) ;
V_7 -> V_34 -> V_149 = F_44 ( V_8 , V_66 ,
L_37 , F_34 ( V_8 ) ) ;
}
V_20 = F_98 ( V_7 ) ;
if ( V_20 )
goto V_148;
V_20 = F_105 ( V_2 ) ;
if ( V_20 )
goto V_148;
if ( V_7 -> V_34 ) {
F_42 ( V_2 , V_7 -> V_34 ) ;
if ( ! V_2 -> V_52 -> V_34 ) {
if ( F_106 ( V_7 -> V_34 ) ) {
F_10 ( V_8 , L_38 ,
V_69 ) ;
goto V_142;
}
}
}
V_20 = F_30 ( V_2 ) ;
if ( V_20 < 0 )
goto V_142;
if ( V_7 -> V_15 -> V_8 . V_21 )
return F_40 ( V_2 ) ;
return 0 ;
V_142:
F_1 ( V_2 ) ;
V_148:
return V_20 < 0 ? V_20 : 0 ;
}
bool F_107 ( struct V_150 * V_151 )
{
return V_151 == & V_152 . V_21 ;
}
int T_5 F_108 ( void )
{
int error ;
error = F_109 ( & V_152 . V_21 ) ;
if ( error ) {
F_110 ( L_39 , V_69 ,
error ) ;
return error ;
}
return 0 ;
}
void T_6 F_111 ( void )
{
F_112 ( & V_152 . V_21 ) ;
}
