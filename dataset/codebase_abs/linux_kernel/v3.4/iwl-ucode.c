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
( T_1 * ) F_3 ( V_3 -> V_12 , V_13 ) ;
F_4 ( & V_10 . V_14 , V_15 ) ;
V_10 . V_16 = F_5 ( V_11 [ 0 ] ) ;
V_10 . V_17 = F_5 ( V_11 [ 1 ] ) ;
return F_6 ( V_3 , ( void * ) & V_10 , sizeof( V_10 ) ) ;
}
static int F_7 ( struct V_2 * V_3 )
{
struct V_18 V_10 ;
T_1 * V_19 =
( T_1 * ) F_3 ( V_3 -> V_12 ,
V_20 ) ;
memset ( & V_10 , 0 , sizeof( V_10 ) ) ;
F_4 ( & V_10 . V_14 , V_21 ) ;
memcpy ( & V_10 . V_22 , V_19 , sizeof( * V_19 ) ) ;
if ( ! ( V_10 . V_22 ) )
V_10 . V_22 = V_23 ;
F_8 ( V_3 , L_1 ,
F_5 ( V_10 . V_22 ) ) ;
return F_6 ( V_3 , ( void * ) & V_10 , sizeof( V_10 ) ) ;
}
static int F_9 ( struct V_2 * V_3 )
{
struct V_24 V_10 ;
T_1 * V_25 = ( T_1 * ) F_3 ( V_3 -> V_12 ,
V_26 ) ;
T_1 * V_27 =
( T_1 * ) F_3 ( V_3 -> V_12 ,
V_20 ) ;
struct V_28 * V_14 ;
memset ( & V_10 , 0 , sizeof( V_10 ) ) ;
F_4 ( & V_10 . V_14 , V_21 ) ;
V_14 = (struct V_28 * ) F_3 ( V_3 -> V_12 ,
V_29 ) ;
memcpy ( & V_10 . V_30 , V_25 ,
sizeof( * V_25 ) ) ;
memcpy ( & V_10 . V_31 , V_27 ,
sizeof( * V_27 ) ) ;
if ( ! ( V_10 . V_31 ) ) {
F_8 ( V_3 , L_2 ) ;
V_10 . V_31 = V_23 ;
V_10 . V_30 = V_23 ;
}
memcpy ( & V_10 . V_32 , & V_14 -> V_33 ,
sizeof( V_14 -> V_33 ) ) ;
F_8 ( V_3 , L_3 ,
F_5 ( V_10 . V_30 ) ) ;
F_8 ( V_3 , L_4 ,
F_5 ( V_10 . V_31 ) ) ;
F_8 ( V_3 , L_5 ,
F_5 ( V_10 . V_32 ) ) ;
return F_6 ( V_3 , ( void * ) & V_10 , sizeof( V_10 ) ) ;
}
static int F_10 ( struct V_2 * V_3 )
{
struct V_34 V_35 ;
struct V_36 V_10 = {
. V_37 = V_38 ,
. V_39 = { sizeof( struct V_34 ) , } ,
. V_40 = { & V_35 , } ,
} ;
memset ( & V_35 , 0 , sizeof( V_35 ) ) ;
V_35 . V_41 . V_42 . V_43 = V_44 ;
V_35 . V_41 . V_42 . V_45 = V_44 ;
V_35 . V_41 . V_42 . V_46 = V_44 ;
V_35 . V_41 . V_47 =
V_48 ;
return F_11 ( V_3 , & V_10 ) ;
}
int F_12 ( struct V_2 * V_3 ,
struct V_49 * V_50 ,
struct V_51 * V_10 )
{
struct V_52 * V_53 = F_13 ( V_50 ) ;
struct V_54 * V_14 = (struct V_54 * ) V_53 -> V_40 ;
int V_39 = F_14 ( V_53 -> V_55 ) & V_56 ;
V_39 -= 4 ;
if ( F_6 ( V_3 , V_14 , V_39 ) )
F_15 ( V_3 , L_6 ,
V_14 -> V_57 ) ;
return 0 ;
}
int F_16 ( struct V_2 * V_3 )
{
int V_58 ;
if ( F_17 ( V_3 ) -> V_59 &&
F_17 ( V_3 ) -> V_59 -> V_60 ) {
V_58 = F_18 ( V_3 , V_61 ,
V_62 ) ;
if ( V_58 )
return V_58 ;
}
V_58 = F_10 ( V_3 ) ;
if ( V_58 )
return V_58 ;
if ( F_17 ( V_3 ) -> V_63 ) {
if ( F_17 ( V_3 ) -> V_64 )
return F_9 ( V_3 ) ;
else
return F_7 ( V_3 ) ;
}
return 0 ;
}
static int F_19 ( struct V_2 * V_3 )
{
struct V_65 V_66 ;
if ( F_17 ( V_3 ) -> V_67 -> V_68 ) {
V_66 . V_47 = V_69 ;
V_66 . V_47 |= V_70 ;
memcpy ( V_66 . V_71 , V_72 ,
sizeof( struct V_73 ) *
V_74 ) ;
V_66 . V_47 |= V_75 ;
V_66 . V_47 |= V_76 ;
} else {
memset ( & V_66 , 0 , sizeof( V_66 ) ) ;
}
return F_20 ( V_3 ,
V_77 , V_78 ,
sizeof( V_66 ) , & V_66 ) ;
}
void F_21 ( struct V_2 * V_3 )
{
struct V_79 V_80 ;
memcpy ( V_80 . V_81 , V_82 ,
sizeof( V_82 ) ) ;
if ( F_20 ( V_3 ,
V_83 , V_78 ,
sizeof( V_80 ) , & V_80 ) )
F_15 ( V_3 , L_7 ) ;
}
int F_18 ( struct V_2 * V_3 , T_2 V_84 , T_2 type )
{
struct V_85 V_86 ;
int V_58 ;
V_86 . V_84 = V_84 ;
V_86 . type = type ;
V_58 = F_20 ( V_3 ,
V_87 , V_78 ,
sizeof( V_86 ) , & V_86 ) ;
if ( V_58 )
F_15 ( V_3 , L_8 ) ;
return V_58 ;
}
static int F_22 ( struct V_2 * V_3 )
{
int V_58 ;
F_23 ( F_24 ( V_3 ) ) ;
V_3 -> V_88 = false ;
V_3 -> V_89 = 0 ;
V_58 = F_19 ( V_3 ) ;
if ( V_58 )
return V_58 ;
if ( ! F_17 ( V_3 ) -> V_90 ) {
V_58 = F_2 ( V_3 ) ;
if ( V_58 )
return V_58 ;
}
return F_25 ( V_3 ) ;
}
static int F_26 ( struct V_2 * V_3 ,
const struct V_91 * V_91 )
{
T_3 * V_92 = ( T_3 * ) V_91 -> V_93 ;
T_4 V_39 = V_91 -> V_39 ;
T_4 V_94 ;
T_4 V_95 ;
F_27 ( V_3 , L_9 , V_39 ) ;
for ( V_95 = 0 ; V_95 < V_39 ; V_95 += 100 , V_92 += 100 / sizeof( T_4 ) ) {
F_28 ( F_24 ( V_3 ) , V_96 ,
V_95 + V_91 -> V_97 ) ;
V_94 = F_29 ( F_24 ( V_3 ) , V_98 ) ;
if ( V_94 != F_14 ( * V_92 ) )
return - V_99 ;
}
return 0 ;
}
static void F_30 ( struct V_2 * V_3 ,
const struct V_91 * V_91 )
{
T_3 * V_92 = ( T_3 * ) V_91 -> V_93 ;
T_4 V_39 = V_91 -> V_39 ;
T_4 V_94 ;
T_4 V_100 ;
int V_101 = 0 ;
F_27 ( V_3 , L_9 , V_39 ) ;
F_28 ( F_24 ( V_3 ) , V_96 ,
V_91 -> V_97 ) ;
for ( V_100 = 0 ;
V_100 < V_39 && V_101 < 20 ;
V_100 += sizeof( T_4 ) , V_92 ++ ) {
V_94 = F_29 ( F_24 ( V_3 ) , V_98 ) ;
if ( V_94 != F_14 ( * V_92 ) ) {
F_15 ( V_3 , L_10
L_11 ,
V_100 , V_94 , F_14 ( * V_92 ) ) ;
V_101 ++ ;
}
}
}
static int F_31 ( struct V_2 * V_3 ,
enum V_4 V_5 )
{
const struct V_1 * V_8 = F_1 ( V_3 , V_5 ) ;
if ( ! V_8 ) {
F_15 ( V_3 , L_12 , V_5 ) ;
return - V_102 ;
}
if ( ! F_26 ( V_3 , & V_8 -> V_103 [ V_104 ] ) ) {
F_27 ( V_3 , L_13 ) ;
return 0 ;
}
F_15 ( V_3 , L_14 ) ;
F_30 ( V_3 , & V_8 -> V_103 [ V_104 ] ) ;
return - V_99 ;
}
static void F_32 ( struct V_105 * V_106 ,
struct V_52 * V_53 ,
void * V_40 )
{
struct V_2 * V_3 =
F_33 ( V_106 , struct V_2 , V_106 ) ;
struct V_107 * V_108 = V_40 ;
struct V_109 * V_110 ;
V_110 = ( void * ) V_53 -> V_40 ;
F_27 ( V_3 , L_15
L_16 ,
V_110 -> V_111 , V_110 -> V_112 ,
V_110 -> V_113 ) ;
V_3 -> V_12 -> V_114 . V_115 =
F_14 ( V_110 -> V_116 ) ;
V_3 -> V_12 -> V_114 . V_117 =
F_14 ( V_110 -> V_118 ) ;
V_108 -> V_119 = V_110 -> V_113 ;
V_108 -> V_120 = V_110 -> V_111 == V_121 ;
}
int F_34 ( struct V_2 * V_3 ,
enum V_4 V_5 )
{
struct V_122 V_123 ;
struct V_107 V_108 ;
const struct V_1 * V_7 ;
int V_58 ;
enum V_4 V_124 ;
V_124 = V_3 -> V_12 -> V_5 ;
V_3 -> V_12 -> V_5 = V_5 ;
V_7 = F_1 ( V_3 , V_5 ) ;
V_3 -> V_125 = false ;
if ( ! V_7 )
return - V_102 ;
F_35 ( & V_3 -> V_106 , & V_123 , V_126 ,
F_32 , & V_108 ) ;
V_58 = F_36 ( F_24 ( V_3 ) , V_7 ) ;
if ( V_58 ) {
V_3 -> V_12 -> V_5 = V_124 ;
F_37 ( & V_3 -> V_106 , & V_123 ) ;
return V_58 ;
}
V_58 = F_38 ( & V_3 -> V_106 , & V_123 ,
V_127 ) ;
if ( V_58 ) {
V_3 -> V_12 -> V_5 = V_124 ;
return V_58 ;
}
if ( ! V_108 . V_120 ) {
F_15 ( V_3 , L_17 ) ;
V_3 -> V_12 -> V_5 = V_124 ;
return - V_99 ;
}
if ( V_5 != V_128 ) {
V_58 = F_31 ( V_3 , V_5 ) ;
if ( V_58 ) {
V_3 -> V_12 -> V_5 = V_124 ;
return V_58 ;
}
F_39 ( 5 ) ;
}
V_58 = F_22 ( V_3 ) ;
if ( V_58 ) {
F_40 ( V_3 ,
L_18 , V_58 ) ;
V_3 -> V_12 -> V_5 = V_124 ;
return V_58 ;
}
V_3 -> V_125 = true ;
return 0 ;
}
int F_41 ( struct V_2 * V_3 )
{
struct V_122 V_129 ;
int V_58 ;
F_42 ( & V_3 -> V_130 ) ;
if ( ! V_3 -> V_7 -> V_8 [ V_131 ] . V_103 [ 0 ] . V_39 )
return 0 ;
if ( V_3 -> V_132 )
return 0 ;
F_35 ( & V_3 -> V_106 , & V_129 ,
V_133 ,
NULL , NULL ) ;
V_58 = F_34 ( V_3 , V_131 ) ;
if ( V_58 )
goto error;
V_58 = F_16 ( V_3 ) ;
if ( V_58 )
goto error;
V_58 = F_38 ( & V_3 -> V_106 , & V_129 ,
V_134 ) ;
if ( ! V_58 )
V_3 -> V_132 = true ;
goto V_135;
error:
F_37 ( & V_3 -> V_106 , & V_129 ) ;
V_135:
F_43 ( F_24 ( V_3 ) ) ;
V_3 -> V_125 = false ;
return V_58 ;
}
