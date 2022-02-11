static inline const struct V_1 *
F_1 ( struct V_2 * V_3 , enum V_4 V_5 )
{
if ( V_5 >= V_6 )
return NULL ;
return & V_3 -> V_7 -> V_8 [ V_5 ] ;
}
static int F_2 ( struct V_2 * V_3 )
{
struct V_9 V_10 ;
T_1 * V_11 =
( T_1 * ) F_3 ( V_3 , V_12 ) ;
F_4 ( & V_10 . V_13 , V_14 ) ;
V_10 . V_15 = F_5 ( V_11 [ 0 ] ) ;
V_10 . V_16 = F_5 ( V_11 [ 1 ] ) ;
return F_6 ( V_3 , ( void * ) & V_10 , sizeof( V_10 ) ) ;
}
static int F_7 ( struct V_2 * V_3 )
{
struct V_17 V_10 ;
T_1 * V_18 =
( T_1 * ) F_3 ( V_3 , V_19 ) ;
memset ( & V_10 , 0 , sizeof( V_10 ) ) ;
F_4 ( & V_10 . V_13 , V_20 ) ;
memcpy ( & V_10 . V_21 , V_18 , sizeof( * V_18 ) ) ;
if ( ! ( V_10 . V_21 ) )
V_10 . V_21 = V_22 ;
F_8 ( V_3 , L_1 ,
F_5 ( V_10 . V_21 ) ) ;
return F_6 ( V_3 , ( void * ) & V_10 , sizeof( V_10 ) ) ;
}
static int F_9 ( struct V_2 * V_3 )
{
struct V_23 V_10 ;
T_1 * V_24 = ( T_1 * ) F_3 ( V_3 ,
V_25 ) ;
T_1 * V_26 =
( T_1 * ) F_3 ( V_3 , V_19 ) ;
struct V_27 * V_13 ;
memset ( & V_10 , 0 , sizeof( V_10 ) ) ;
F_4 ( & V_10 . V_13 , V_20 ) ;
V_13 = (struct V_27 * ) F_3 ( V_3 ,
V_28 ) ;
memcpy ( & V_10 . V_29 , V_24 ,
sizeof( * V_24 ) ) ;
memcpy ( & V_10 . V_30 , V_26 ,
sizeof( * V_26 ) ) ;
if ( ! ( V_10 . V_30 ) ) {
F_8 ( V_3 , L_2 ) ;
V_10 . V_30 = V_22 ;
V_10 . V_29 = V_22 ;
}
memcpy ( & V_10 . V_31 , & V_13 -> V_32 ,
sizeof( V_13 -> V_32 ) ) ;
F_8 ( V_3 , L_3 ,
F_5 ( V_10 . V_29 ) ) ;
F_8 ( V_3 , L_4 ,
F_5 ( V_10 . V_30 ) ) ;
F_8 ( V_3 , L_5 ,
F_5 ( V_10 . V_31 ) ) ;
return F_6 ( V_3 , ( void * ) & V_10 , sizeof( V_10 ) ) ;
}
static int F_10 ( struct V_2 * V_3 )
{
struct V_33 V_34 ;
struct V_35 V_10 = {
. V_36 = V_37 ,
. V_38 = { sizeof( struct V_33 ) , } ,
. V_39 = { & V_34 , } ,
} ;
memset ( & V_34 , 0 , sizeof( V_34 ) ) ;
V_34 . V_40 . V_41 . V_42 = V_43 ;
V_34 . V_40 . V_41 . V_44 = V_43 ;
V_34 . V_40 . V_41 . V_45 = V_43 ;
V_34 . V_40 . V_46 =
V_47 ;
return F_11 ( V_3 , & V_10 ) ;
}
int F_12 ( struct V_2 * V_3 )
{
int V_48 ;
if ( V_3 -> V_49 -> V_50 &&
V_3 -> V_49 -> V_50 -> V_51 ) {
V_48 = F_13 ( V_3 , V_52 ,
V_53 ) ;
if ( V_48 )
return V_48 ;
}
V_48 = F_10 ( V_3 ) ;
if ( V_48 )
return V_48 ;
if ( V_3 -> V_49 -> V_54 ) {
if ( V_3 -> V_49 -> V_55 )
return F_9 ( V_3 ) ;
else
return F_7 ( V_3 ) ;
}
return 0 ;
}
int F_14 ( struct V_2 * V_3 )
{
struct V_56 V_57 ;
memset ( & V_57 , 0 , sizeof( V_57 ) ) ;
return F_15 ( V_3 ,
V_58 , V_59 ,
sizeof( V_57 ) , & V_57 ) ;
}
void F_16 ( struct V_2 * V_3 )
{
struct V_60 V_61 ;
memcpy ( V_61 . V_62 , V_63 ,
sizeof( V_63 ) ) ;
if ( F_15 ( V_3 ,
V_64 , V_59 ,
sizeof( V_61 ) , & V_61 ) )
F_17 ( V_3 , L_6 ) ;
}
int F_13 ( struct V_2 * V_3 , T_2 V_65 , T_2 type )
{
struct V_66 V_67 ;
int V_48 ;
V_67 . V_65 = V_65 ;
V_67 . type = type ;
V_48 = F_15 ( V_3 ,
V_68 , V_59 ,
sizeof( V_67 ) , & V_67 ) ;
if ( V_48 )
F_17 ( V_3 , L_7 ) ;
return V_48 ;
}
static int F_18 ( struct V_2 * V_3 )
{
int V_48 ;
F_19 ( V_3 -> V_69 ) ;
V_3 -> V_70 = false ;
V_3 -> V_71 = 0 ;
V_48 = F_14 ( V_3 ) ;
if ( V_48 )
return V_48 ;
if ( ! V_3 -> V_49 -> V_72 ) {
V_48 = F_2 ( V_3 ) ;
if ( V_48 )
return V_48 ;
}
return F_20 ( V_3 ) ;
}
static int F_21 ( struct V_2 * V_3 ,
const struct V_73 * V_73 )
{
T_3 * V_74 = ( T_3 * ) V_73 -> V_75 ;
T_4 V_38 = V_73 -> V_38 ;
T_4 V_76 ;
T_4 V_77 ;
F_22 ( V_3 , L_8 , V_38 ) ;
for ( V_77 = 0 ; V_77 < V_38 ; V_77 += 100 , V_74 += 100 / sizeof( T_4 ) ) {
F_23 ( V_3 -> V_69 , V_78 ,
V_77 + V_73 -> V_79 ) ;
V_76 = F_24 ( V_3 -> V_69 , V_80 ) ;
if ( V_76 != F_25 ( * V_74 ) )
return - V_81 ;
}
return 0 ;
}
static void F_26 ( struct V_2 * V_3 ,
const struct V_73 * V_73 )
{
T_3 * V_74 = ( T_3 * ) V_73 -> V_75 ;
T_4 V_38 = V_73 -> V_38 ;
T_4 V_76 ;
T_4 V_82 ;
int V_83 = 0 ;
F_22 ( V_3 , L_8 , V_38 ) ;
F_23 ( V_3 -> V_69 , V_78 ,
V_73 -> V_79 ) ;
for ( V_82 = 0 ;
V_82 < V_38 && V_83 < 20 ;
V_82 += sizeof( T_4 ) , V_74 ++ ) {
V_76 = F_24 ( V_3 -> V_69 , V_80 ) ;
if ( V_76 != F_25 ( * V_74 ) ) {
F_17 ( V_3 , L_9
L_10 ,
V_82 , V_76 , F_25 ( * V_74 ) ) ;
V_83 ++ ;
}
}
}
static int F_27 ( struct V_2 * V_3 ,
enum V_4 V_5 )
{
const struct V_1 * V_8 = F_1 ( V_3 , V_5 ) ;
if ( ! V_8 ) {
F_17 ( V_3 , L_11 , V_5 ) ;
return - V_84 ;
}
if ( ! F_21 ( V_3 , & V_8 -> V_85 [ V_86 ] ) ) {
F_22 ( V_3 , L_12 ) ;
return 0 ;
}
F_17 ( V_3 , L_13 ) ;
F_26 ( V_3 , & V_8 -> V_85 [ V_86 ] ) ;
return - V_81 ;
}
static bool F_28 ( struct V_87 * V_88 ,
struct V_89 * V_90 , void * V_39 )
{
struct V_2 * V_3 =
F_29 ( V_88 , struct V_2 , V_88 ) ;
struct V_91 * V_92 = V_39 ;
struct V_93 * V_94 ;
V_94 = ( void * ) V_90 -> V_39 ;
F_22 ( V_3 , L_14
L_15 ,
V_94 -> V_95 , V_94 -> V_96 ,
V_94 -> V_97 ) ;
V_3 -> V_98 . V_99 =
F_25 ( V_94 -> V_100 ) ;
V_3 -> V_98 . V_101 =
F_25 ( V_94 -> V_102 ) ;
V_92 -> V_103 = V_94 -> V_97 ;
V_92 -> V_104 = V_94 -> V_95 == V_105 ;
return true ;
}
int F_30 ( struct V_2 * V_3 ,
enum V_4 V_5 )
{
struct V_106 V_107 ;
struct V_91 V_92 ;
const struct V_1 * V_7 ;
int V_48 ;
enum V_4 V_108 ;
static const T_2 V_109 [] = { V_110 } ;
V_108 = V_3 -> V_111 ;
V_3 -> V_111 = V_5 ;
V_7 = F_1 ( V_3 , V_5 ) ;
V_3 -> V_112 = false ;
if ( ! V_7 )
return - V_84 ;
F_31 ( & V_3 -> V_88 , & V_107 ,
V_109 , F_32 ( V_109 ) ,
F_28 , & V_92 ) ;
V_48 = F_33 ( V_3 -> V_69 , V_7 ) ;
if ( V_48 ) {
V_3 -> V_111 = V_108 ;
F_34 ( & V_3 -> V_88 , & V_107 ) ;
return V_48 ;
}
V_48 = F_35 ( & V_3 -> V_88 , & V_107 ,
V_113 ) ;
if ( V_48 ) {
V_3 -> V_111 = V_108 ;
return V_48 ;
}
if ( ! V_92 . V_104 ) {
F_17 ( V_3 , L_16 ) ;
V_3 -> V_111 = V_108 ;
return - V_81 ;
}
if ( V_5 != V_114 ) {
V_48 = F_27 ( V_3 , V_5 ) ;
if ( V_48 ) {
V_3 -> V_111 = V_108 ;
return V_48 ;
}
F_36 ( 5 ) ;
}
V_48 = F_18 ( V_3 ) ;
if ( V_48 ) {
F_37 ( V_3 ,
L_17 , V_48 ) ;
V_3 -> V_111 = V_108 ;
return V_48 ;
}
V_3 -> V_112 = true ;
return 0 ;
}
static bool F_38 ( struct V_87 * V_88 ,
struct V_89 * V_90 , void * V_39 )
{
struct V_2 * V_3 = V_39 ;
struct V_115 * V_13 ;
int V_38 ;
if ( V_90 -> V_13 . V_10 != V_116 ) {
F_39 ( V_90 -> V_13 . V_10 != V_117 ) ;
return true ;
}
V_13 = (struct V_115 * ) V_90 -> V_39 ;
V_38 = F_25 ( V_90 -> V_118 ) & V_119 ;
V_38 -= sizeof( T_3 ) ;
if ( F_6 ( V_3 , V_13 , V_38 ) )
F_17 ( V_3 , L_18 ,
V_13 -> V_120 ) ;
return false ;
}
int F_40 ( struct V_2 * V_3 )
{
struct V_106 V_121 ;
static const T_2 V_122 [] = {
V_116 ,
V_117
} ;
int V_48 ;
F_41 ( & V_3 -> V_123 ) ;
if ( ! V_3 -> V_7 -> V_8 [ V_124 ] . V_85 [ 0 ] . V_38 )
return 0 ;
if ( V_3 -> V_125 )
return 0 ;
F_31 ( & V_3 -> V_88 , & V_121 ,
V_122 , F_32 ( V_122 ) ,
F_38 , V_3 ) ;
V_48 = F_30 ( V_3 , V_124 ) ;
if ( V_48 )
goto error;
V_48 = F_12 ( V_3 ) ;
if ( V_48 )
goto error;
V_48 = F_35 ( & V_3 -> V_88 , & V_121 ,
V_126 ) ;
if ( ! V_48 )
V_3 -> V_125 = true ;
goto V_127;
error:
F_34 ( & V_3 -> V_88 , & V_121 ) ;
V_127:
F_42 ( V_3 -> V_69 ) ;
V_3 -> V_112 = false ;
return V_48 ;
}
