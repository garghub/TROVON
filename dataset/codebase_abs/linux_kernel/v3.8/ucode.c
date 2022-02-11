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
T_1 * V_11 = V_3 -> V_12 -> V_11 ;
F_3 ( & V_10 . V_13 , V_14 ) ;
V_10 . V_15 = F_4 ( V_11 [ 0 ] ) ;
V_10 . V_16 = F_4 ( V_11 [ 1 ] ) ;
return F_5 ( V_3 , ( void * ) & V_10 , sizeof( V_10 ) ) ;
}
static int F_6 ( struct V_2 * V_3 )
{
struct V_17 V_10 ;
memset ( & V_10 , 0 , sizeof( V_10 ) ) ;
F_3 ( & V_10 . V_13 , V_18 ) ;
V_10 . V_19 = V_3 -> V_12 -> V_20 ;
if ( ! ( V_10 . V_19 ) )
V_10 . V_19 = V_21 ;
F_7 ( V_3 , L_1 ,
F_4 ( V_10 . V_19 ) ) ;
return F_5 ( V_3 , ( void * ) & V_10 , sizeof( V_10 ) ) ;
}
static int F_8 ( struct V_2 * V_3 )
{
struct V_22 V_10 ;
memset ( & V_10 , 0 , sizeof( V_10 ) ) ;
F_3 ( & V_10 . V_13 , V_18 ) ;
V_10 . V_23 = V_3 -> V_12 -> V_24 ;
V_10 . V_25 = V_3 -> V_12 -> V_20 ;
if ( ! V_10 . V_25 ) {
F_7 ( V_3 , L_2 ) ;
V_10 . V_25 = V_21 ;
V_10 . V_23 = V_21 ;
}
V_10 . V_26 = V_3 -> V_12 -> V_27 ;
F_7 ( V_3 , L_3 ,
F_4 ( V_10 . V_23 ) ) ;
F_7 ( V_3 , L_4 ,
F_4 ( V_10 . V_25 ) ) ;
F_7 ( V_3 , L_5 ,
F_4 ( V_10 . V_26 ) ) ;
return F_5 ( V_3 , ( void * ) & V_10 , sizeof( V_10 ) ) ;
}
static int F_9 ( struct V_2 * V_3 )
{
struct V_28 V_29 ;
struct V_30 V_10 = {
. V_31 = V_32 ,
. V_33 = { sizeof( struct V_28 ) , } ,
. V_34 = { & V_29 , } ,
} ;
memset ( & V_29 , 0 , sizeof( V_29 ) ) ;
V_29 . V_35 . V_36 . V_37 = V_38 ;
V_29 . V_35 . V_36 . V_39 = V_38 ;
V_29 . V_35 . V_36 . V_40 = V_38 ;
V_29 . V_35 . V_41 =
V_42 ;
return F_10 ( V_3 , & V_10 ) ;
}
int F_11 ( struct V_2 * V_3 )
{
int V_43 ;
if ( V_3 -> V_44 -> V_45 &&
V_3 -> V_44 -> V_45 -> V_46 ) {
V_43 = F_12 ( V_3 , V_47 ,
V_48 ) ;
if ( V_43 )
return V_43 ;
}
V_43 = F_9 ( V_3 ) ;
if ( V_43 )
return V_43 ;
if ( V_3 -> V_44 -> V_49 ) {
if ( V_3 -> V_44 -> V_50 )
return F_8 ( V_3 ) ;
else
return F_6 ( V_3 ) ;
}
return 0 ;
}
static int F_13 ( struct V_2 * V_3 )
{
struct V_51 V_52 ;
memset ( & V_52 , 0 , sizeof( V_52 ) ) ;
return F_14 ( V_3 ,
V_53 , V_54 ,
sizeof( V_52 ) , & V_52 ) ;
}
void F_15 ( struct V_2 * V_3 )
{
struct V_55 V_56 ;
memcpy ( V_56 . V_57 , V_58 ,
sizeof( V_58 ) ) ;
if ( F_14 ( V_3 ,
V_59 , V_54 ,
sizeof( V_56 ) , & V_56 ) )
F_16 ( V_3 , L_6 ) ;
}
int F_12 ( struct V_2 * V_3 , T_2 V_60 , T_2 type )
{
struct V_61 V_62 ;
int V_43 ;
V_62 . V_60 = V_60 ;
V_62 . type = type ;
V_43 = F_14 ( V_3 ,
V_63 , V_54 ,
sizeof( V_62 ) , & V_62 ) ;
if ( V_43 )
F_16 ( V_3 , L_7 ) ;
return V_43 ;
}
static int F_17 ( struct V_2 * V_3 )
{
const T_2 * V_64 ;
T_2 V_65 ;
int V_43 ;
int V_66 ;
F_18 ( V_3 -> V_67 , 0 ) ;
if ( V_3 -> V_7 -> V_68 . V_41 & V_69 &&
V_3 -> V_12 -> V_70 ) {
V_65 = F_19 ( V_71 ) ;
V_64 = V_71 ;
} else {
V_65 = F_19 ( V_72 ) ;
V_64 = V_72 ;
}
for ( V_66 = 0 ; V_66 < V_65 ; V_66 ++ )
if ( V_64 [ V_66 ] != V_73 )
F_20 ( V_3 -> V_67 , V_66 ,
V_64 [ V_66 ] ) ;
V_3 -> V_74 = false ;
V_3 -> V_75 = 0 ;
V_43 = F_13 ( V_3 ) ;
if ( V_43 )
return V_43 ;
if ( ! V_3 -> V_44 -> V_76 ) {
V_43 = F_2 ( V_3 ) ;
if ( V_43 )
return V_43 ;
}
return F_21 ( V_3 ) ;
}
static int F_22 ( struct V_2 * V_3 ,
const struct V_77 * V_77 )
{
T_3 * V_78 = ( T_3 * ) V_77 -> V_34 ;
T_4 V_33 = V_77 -> V_33 ;
T_4 V_79 ;
T_4 V_66 ;
F_23 ( V_3 , L_8 , V_33 ) ;
for ( V_66 = 0 ; V_66 < V_33 ; V_66 += 100 , V_78 += 100 / sizeof( T_4 ) ) {
F_24 ( V_3 -> V_67 , V_80 ,
V_66 + V_77 -> V_81 ) ;
V_79 = F_25 ( V_3 -> V_67 , V_82 ) ;
if ( V_79 != F_26 ( * V_78 ) )
return - V_83 ;
}
return 0 ;
}
static void F_27 ( struct V_2 * V_3 ,
const struct V_77 * V_77 )
{
T_3 * V_78 = ( T_3 * ) V_77 -> V_34 ;
T_4 V_33 = V_77 -> V_33 ;
T_4 V_79 ;
T_4 V_84 ;
int V_85 = 0 ;
F_23 ( V_3 , L_8 , V_33 ) ;
F_24 ( V_3 -> V_67 , V_80 ,
V_77 -> V_81 ) ;
for ( V_84 = 0 ;
V_84 < V_33 && V_85 < 20 ;
V_84 += sizeof( T_4 ) , V_78 ++ ) {
V_79 = F_25 ( V_3 -> V_67 , V_82 ) ;
if ( V_79 != F_26 ( * V_78 ) ) {
F_16 ( V_3 , L_9
L_10 ,
V_84 , V_79 , F_26 ( * V_78 ) ) ;
V_85 ++ ;
}
}
}
static int F_28 ( struct V_2 * V_3 ,
enum V_4 V_5 )
{
const struct V_1 * V_8 = F_1 ( V_3 , V_5 ) ;
if ( ! V_8 ) {
F_16 ( V_3 , L_11 , V_5 ) ;
return - V_86 ;
}
if ( ! F_22 ( V_3 , & V_8 -> V_87 [ V_88 ] ) ) {
F_23 ( V_3 , L_12 ) ;
return 0 ;
}
F_16 ( V_3 , L_13 ) ;
F_27 ( V_3 , & V_8 -> V_87 [ V_88 ] ) ;
return - V_83 ;
}
static bool F_29 ( struct V_89 * V_90 ,
struct V_91 * V_92 , void * V_34 )
{
struct V_2 * V_3 =
F_30 ( V_90 , struct V_2 , V_90 ) ;
struct V_93 * V_94 = V_34 ;
struct V_95 * V_96 ;
V_96 = ( void * ) V_92 -> V_34 ;
F_23 ( V_3 , L_14
L_15 ,
V_96 -> V_97 , V_96 -> V_98 ,
V_96 -> V_99 ) ;
V_3 -> V_100 . V_101 =
F_26 ( V_96 -> V_102 ) ;
V_3 -> V_100 . V_103 =
F_26 ( V_96 -> V_104 ) ;
V_94 -> V_105 = V_96 -> V_99 ;
V_94 -> V_106 = V_96 -> V_97 == V_107 ;
return true ;
}
int F_31 ( struct V_2 * V_3 ,
enum V_4 V_5 )
{
struct V_108 V_109 ;
struct V_93 V_94 ;
const struct V_1 * V_7 ;
int V_43 ;
enum V_4 V_110 ;
static const T_2 V_111 [] = { V_112 } ;
V_110 = V_3 -> V_113 ;
V_3 -> V_113 = V_5 ;
V_7 = F_1 ( V_3 , V_5 ) ;
V_3 -> V_114 = false ;
if ( ! V_7 )
return - V_86 ;
F_32 ( & V_3 -> V_90 , & V_109 ,
V_111 , F_19 ( V_111 ) ,
F_29 , & V_94 ) ;
V_43 = F_33 ( V_3 -> V_67 , V_7 ) ;
if ( V_43 ) {
V_3 -> V_113 = V_110 ;
F_34 ( & V_3 -> V_90 , & V_109 ) ;
return V_43 ;
}
V_43 = F_35 ( & V_3 -> V_90 , & V_109 ,
V_115 ) ;
if ( V_43 ) {
V_3 -> V_113 = V_110 ;
return V_43 ;
}
if ( ! V_94 . V_106 ) {
F_16 ( V_3 , L_16 ) ;
V_3 -> V_113 = V_110 ;
return - V_83 ;
}
if ( V_5 != V_116 ) {
V_43 = F_28 ( V_3 , V_5 ) ;
if ( V_43 ) {
V_3 -> V_113 = V_110 ;
return V_43 ;
}
F_36 ( 5 ) ;
}
V_43 = F_17 ( V_3 ) ;
if ( V_43 ) {
F_37 ( V_3 ,
L_17 , V_43 ) ;
V_3 -> V_113 = V_110 ;
return V_43 ;
}
V_3 -> V_114 = true ;
return 0 ;
}
static bool F_38 ( struct V_89 * V_90 ,
struct V_91 * V_92 , void * V_34 )
{
struct V_2 * V_3 = V_34 ;
struct V_117 * V_13 ;
int V_33 ;
if ( V_92 -> V_13 . V_10 != V_118 ) {
F_39 ( V_92 -> V_13 . V_10 != V_119 ) ;
return true ;
}
V_13 = (struct V_117 * ) V_92 -> V_34 ;
V_33 = F_26 ( V_92 -> V_120 ) & V_121 ;
V_33 -= sizeof( T_3 ) ;
if ( F_5 ( V_3 , V_13 , V_33 ) )
F_16 ( V_3 , L_18 ,
V_13 -> V_122 ) ;
return false ;
}
int F_40 ( struct V_2 * V_3 )
{
struct V_108 V_123 ;
static const T_2 V_124 [] = {
V_118 ,
V_119
} ;
int V_43 ;
F_41 ( & V_3 -> V_125 ) ;
if ( ! V_3 -> V_7 -> V_8 [ V_126 ] . V_87 [ 0 ] . V_33 )
return 0 ;
if ( V_3 -> V_127 )
return 0 ;
F_32 ( & V_3 -> V_90 , & V_123 ,
V_124 , F_19 ( V_124 ) ,
F_38 , V_3 ) ;
V_43 = F_31 ( V_3 , V_126 ) ;
if ( V_43 )
goto error;
V_43 = F_11 ( V_3 ) ;
if ( V_43 )
goto error;
V_43 = F_35 ( & V_3 -> V_90 , & V_123 ,
V_128 ) ;
if ( ! V_43 )
V_3 -> V_127 = true ;
goto V_129;
error:
F_34 ( & V_3 -> V_90 , & V_123 ) ;
V_129:
F_42 ( V_3 -> V_67 ) ;
V_3 -> V_114 = false ;
return V_43 ;
}
