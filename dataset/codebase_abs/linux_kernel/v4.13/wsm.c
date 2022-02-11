static int F_1 ( struct V_1 * V_2 ,
void * V_3 ,
struct V_4 * V_5 )
{
T_1 V_6 = F_2 ( V_5 ) ;
if ( V_6 != V_7 )
return - V_8 ;
return 0 ;
V_9:
F_3 ( 1 ) ;
return - V_8 ;
}
int F_4 ( struct V_1 * V_2 , struct F_4 * V_3 )
{
int V_10 ;
struct V_4 * V_5 = & V_2 -> V_11 ;
F_5 ( V_2 ) ;
F_6 ( V_5 , V_3 -> V_12 ) ;
F_6 ( V_5 , V_3 -> V_13 ) ;
F_6 ( V_5 , V_3 -> V_14 ) ;
F_7 ( V_5 , V_3 -> V_15 + 12 ) ;
F_7 ( V_5 , 1 ) ;
F_8 ( V_5 , V_3 -> V_16 , V_17 ) ;
F_7 ( V_5 , 5 ) ;
F_8 ( V_5 , V_3 -> V_18 , V_3 -> V_15 ) ;
V_10 = F_9 ( V_2 , V_5 , V_3 ,
V_19 , V_20 ) ;
F_10 ( V_2 ) ;
return V_10 ;
V_21:
F_10 ( V_2 ) ;
return - V_22 ;
}
static int F_11 ( struct V_1 * V_2 ,
struct F_4 * V_3 ,
struct V_4 * V_5 )
{
int V_23 ;
int V_6 ;
V_6 = F_2 ( V_5 ) ;
if ( F_3 ( V_6 != V_7 ) )
return - V_8 ;
F_12 ( V_5 , V_3 -> V_16 , V_17 ) ;
V_3 -> V_24 = F_13 ( V_5 ) ;
F_14 ( V_5 , 1 ) ;
V_3 -> V_25 = F_2 ( V_5 ) ;
for ( V_23 = 0 ; V_23 < 2 ; ++ V_23 ) {
V_3 -> V_26 [ V_23 ] . V_27 = F_2 ( V_5 ) ;
V_3 -> V_26 [ V_23 ] . V_28 = F_2 ( V_5 ) ;
V_3 -> V_26 [ V_23 ] . V_29 = F_2 ( V_5 ) ;
}
return 0 ;
V_9:
F_3 ( 1 ) ;
return - V_8 ;
}
int F_15 ( struct V_1 * V_2 , const struct F_15 * V_3 )
{
int V_10 ;
struct V_4 * V_5 = & V_2 -> V_11 ;
T_2 V_30 = V_31 | F_16 ( V_3 -> V_32 ) ;
F_5 ( V_2 ) ;
F_6 ( V_5 , V_3 -> V_33 ? 0 : 1 ) ;
V_10 = F_9 ( V_2 , V_5 , NULL , V_30 , V_34 ) ;
F_10 ( V_2 ) ;
return V_10 ;
V_21:
F_10 ( V_2 ) ;
return - V_22 ;
}
int F_17 ( struct V_1 * V_2 , T_2 V_35 , void * V_36 ,
T_3 V_37 )
{
int V_10 ;
struct V_4 * V_5 = & V_2 -> V_11 ;
struct V_38 V_39 = {
. V_35 = V_35 ,
. V_5 = V_36 ,
. V_37 = V_37 ,
} ;
F_5 ( V_2 ) ;
F_7 ( V_5 , V_35 ) ;
F_7 ( V_5 , 0 ) ;
V_10 = F_9 ( V_2 , V_5 , & V_39 ,
V_40 , V_20 ) ;
F_10 ( V_2 ) ;
return V_10 ;
V_21:
F_10 ( V_2 ) ;
return - V_22 ;
}
static int F_18 ( struct V_1 * V_2 ,
struct V_38 * V_3 ,
struct V_4 * V_5 )
{
T_2 V_41 ;
if ( F_3 ( F_2 ( V_5 ) != V_7 ) )
return - V_8 ;
if ( F_3 ( F_19 ( V_5 ) != V_3 -> V_35 ) )
return - V_8 ;
V_41 = F_19 ( V_5 ) ;
if ( V_41 > V_3 -> V_37 )
V_41 = V_3 -> V_37 ;
F_12 ( V_5 , V_3 -> V_5 , V_41 ) ;
V_3 -> V_37 = V_41 ;
return 0 ;
V_9:
F_3 ( 1 ) ;
return - V_8 ;
}
int F_20 ( struct V_1 * V_2 , T_2 V_35 , void * V_36 ,
T_3 V_37 )
{
int V_10 ;
struct V_4 * V_5 = & V_2 -> V_11 ;
struct V_38 V_39 = {
. V_35 = V_35 ,
. V_5 = V_36 ,
. V_37 = V_37 ,
} ;
F_5 ( V_2 ) ;
F_7 ( V_5 , V_35 ) ;
F_7 ( V_5 , V_37 ) ;
F_8 ( V_5 , V_36 , V_37 ) ;
V_10 = F_9 ( V_2 , V_5 , & V_39 ,
V_42 , V_20 ) ;
F_10 ( V_2 ) ;
return V_10 ;
V_21:
F_10 ( V_2 ) ;
return - V_22 ;
}
static int F_21 ( struct V_1 * V_2 ,
struct V_38 * V_3 ,
struct V_4 * V_5 )
{
int V_10 ;
V_10 = F_1 ( V_2 , V_3 , V_5 ) ;
if ( V_10 )
return V_10 ;
if ( V_3 -> V_35 == V_43 ) {
const char * V_44 = V_3 -> V_5 ;
F_22 ( V_2 , ( V_44 [ 0 ] & 0x0F ) ? true : false ) ;
}
return 0 ;
}
int F_23 ( struct V_1 * V_2 , const struct F_23 * V_3 )
{
int V_23 ;
int V_10 ;
struct V_4 * V_5 = & V_2 -> V_11 ;
if ( V_3 -> V_45 > 48 )
return - V_8 ;
if ( V_3 -> V_46 > 2 )
return - V_8 ;
if ( V_3 -> V_47 > 1 )
return - V_8 ;
F_5 ( V_2 ) ;
F_24 ( V_5 , V_3 -> V_47 ) ;
F_24 ( V_5 , V_3 -> type ) ;
F_24 ( V_5 , V_3 -> V_48 ) ;
F_24 ( V_5 , V_3 -> V_49 ) ;
F_6 ( V_5 , V_3 -> V_50 ) ;
F_24 ( V_5 , V_3 -> V_51 ) ;
F_24 ( V_5 , V_3 -> V_45 ) ;
F_24 ( V_5 , V_3 -> V_46 ) ;
F_24 ( V_5 , V_3 -> V_52 ) ;
for ( V_23 = 0 ; V_23 < V_3 -> V_45 ; ++ V_23 ) {
F_7 ( V_5 , V_3 -> V_53 [ V_23 ] . V_54 ) ;
F_7 ( V_5 , 0 ) ;
F_6 ( V_5 , V_3 -> V_53 [ V_23 ] . V_55 ) ;
F_6 ( V_5 , V_3 -> V_53 [ V_23 ] . V_56 ) ;
F_6 ( V_5 , 0 ) ;
}
for ( V_23 = 0 ; V_23 < V_3 -> V_46 ; ++ V_23 ) {
F_6 ( V_5 , V_3 -> V_57 [ V_23 ] . V_58 ) ;
F_8 ( V_5 , & V_3 -> V_57 [ V_23 ] . V_59 [ 0 ] ,
sizeof( V_3 -> V_57 [ V_23 ] . V_59 ) ) ;
}
V_10 = F_9 ( V_2 , V_5 , NULL ,
V_60 , V_20 ) ;
F_10 ( V_2 ) ;
return V_10 ;
V_21:
F_10 ( V_2 ) ;
return - V_22 ;
}
int F_25 ( struct V_1 * V_2 )
{
int V_10 ;
struct V_4 * V_5 = & V_2 -> V_11 ;
F_5 ( V_2 ) ;
V_10 = F_9 ( V_2 , V_5 , NULL ,
V_61 , V_20 ) ;
F_10 ( V_2 ) ;
return V_10 ;
}
static int F_26 ( struct V_1 * V_2 ,
struct V_4 * V_5 ,
int V_32 )
{
struct F_26 V_62 ;
V_62 . V_63 = F_2 ( V_5 ) ;
V_62 . V_6 = F_2 ( V_5 ) ;
V_62 . V_64 = F_13 ( V_5 ) ;
V_62 . V_65 = F_13 ( V_5 ) ;
V_62 . V_48 = F_19 ( V_5 ) ;
V_62 . V_66 = F_2 ( V_5 ) ;
V_62 . V_67 = F_2 ( V_5 ) ;
F_27 ( V_2 , V_32 , & V_62 ) ;
return 0 ;
V_9:
F_3 ( 1 ) ;
return - V_8 ;
}
static int F_28 ( struct V_1 * V_2 ,
struct V_4 * V_5 , int V_32 )
{
int V_10 ;
int V_68 ;
V_68 = F_2 ( V_5 ) ;
if ( F_3 ( V_68 <= 0 ) )
return - V_8 ;
if ( V_68 > 1 ) {
V_10 = F_29 ( V_2 , V_68 - 1 ) ;
if ( V_10 < 0 )
return V_10 ;
else if ( V_10 > 0 )
F_30 ( V_2 ) ;
}
F_31 ( V_2 , V_68 ) ;
do {
V_10 = F_26 ( V_2 , V_5 , V_32 ) ;
} while ( ! V_10 && -- V_68 );
return V_10 ;
V_9:
F_3 ( 1 ) ;
return - V_8 ;
}
static int F_32 ( struct V_1 * V_2 ,
struct V_69 * V_3 ,
struct V_4 * V_5 )
{
V_3 -> V_6 = F_2 ( V_5 ) ;
if ( F_3 ( V_3 -> V_6 ) != V_7 )
return - V_8 ;
V_3 -> V_27 = F_2 ( V_5 ) ;
V_3 -> V_28 = F_2 ( V_5 ) ;
return 0 ;
V_9:
F_3 ( 1 ) ;
return - V_8 ;
}
int F_33 ( struct V_1 * V_2 , struct F_33 * V_3 )
{
int V_10 ;
struct V_4 * V_5 = & V_2 -> V_11 ;
struct V_69 V_70 ;
F_5 ( V_2 ) ;
F_24 ( V_5 , V_3 -> V_71 ) ;
F_24 ( V_5 , V_3 -> V_47 ) ;
F_7 ( V_5 , V_3 -> V_72 ) ;
F_8 ( V_5 , & V_3 -> V_73 [ 0 ] , sizeof( V_3 -> V_73 ) ) ;
F_7 ( V_5 , V_3 -> V_74 ) ;
F_24 ( V_5 , V_3 -> V_75 ) ;
F_24 ( V_5 , V_3 -> V_76 ) ;
F_24 ( V_5 , V_3 -> V_77 ) ;
F_24 ( V_5 , V_3 -> V_48 ) ;
F_6 ( V_5 , V_3 -> V_78 ) ;
F_8 ( V_5 , & V_3 -> V_59 [ 0 ] , sizeof( V_3 -> V_59 ) ) ;
F_6 ( V_5 , V_3 -> V_79 ) ;
F_6 ( V_5 , V_3 -> V_80 ) ;
V_2 -> V_81 = - 1 ;
V_10 = F_9 ( V_2 , V_5 , & V_70 ,
V_82 , V_20 ) ;
V_2 -> V_83 = V_70 . V_6 ;
F_10 ( V_2 ) ;
return V_10 ;
V_21:
F_10 ( V_2 ) ;
return - V_22 ;
}
int F_34 ( struct V_1 * V_2 ,
const struct F_34 * V_3 )
{
int V_10 ;
struct V_4 * V_5 = & V_2 -> V_11 ;
F_5 ( V_2 ) ;
F_24 ( V_5 , ( V_3 -> V_84 ? 0x1 : 0 ) ) ;
F_24 ( V_5 , V_3 -> V_85 ) ;
F_7 ( V_5 , V_3 -> V_86 ) ;
F_6 ( V_5 , V_3 -> V_87 ) ;
V_10 = F_9 ( V_2 , V_5 , NULL ,
V_88 , V_20 ) ;
F_10 ( V_2 ) ;
return V_10 ;
V_21:
F_10 ( V_2 ) ;
return - V_22 ;
}
int F_35 ( struct V_1 * V_2 , const struct F_35 * V_3 )
{
int V_10 ;
struct V_4 * V_5 = & V_2 -> V_11 ;
F_5 ( V_2 ) ;
F_8 ( V_5 , V_3 , sizeof( * V_3 ) ) ;
V_10 = F_9 ( V_2 , V_5 , NULL ,
V_89 , V_20 ) ;
F_10 ( V_2 ) ;
return V_10 ;
V_21:
F_10 ( V_2 ) ;
return - V_22 ;
}
int F_36 ( struct V_1 * V_2 , const struct F_36 * V_3 )
{
int V_10 ;
struct V_4 * V_5 = & V_2 -> V_11 ;
F_5 ( V_2 ) ;
F_24 ( V_5 , V_3 -> V_90 ) ;
F_24 ( V_5 , 0 ) ;
F_7 ( V_5 , 0 ) ;
V_10 = F_9 ( V_2 , V_5 , NULL ,
V_91 , V_20 ) ;
F_10 ( V_2 ) ;
return V_10 ;
V_21:
F_10 ( V_2 ) ;
return - V_22 ;
}
int F_37 ( struct V_1 * V_2 ,
const struct F_37 * V_3 , T_4 V_92 )
{
int V_10 ;
struct V_4 * V_5 = & V_2 -> V_11 ;
T_4 V_93 [] = { 3 , 2 , 0 , 1 } ;
F_5 ( V_2 ) ;
F_24 ( V_5 , V_93 [ V_92 ] ) ;
F_24 ( V_5 , 0 ) ;
F_24 ( V_5 , V_3 -> V_94 ) ;
F_24 ( V_5 , 0 ) ;
F_6 ( V_5 , V_3 -> V_95 ) ;
F_7 ( V_5 , V_3 -> V_96 ) ;
F_7 ( V_5 , 0 ) ;
V_10 = F_9 ( V_2 , V_5 , NULL , 0x0012 , V_20 ) ;
F_10 ( V_2 ) ;
return V_10 ;
V_21:
F_10 ( V_2 ) ;
return - V_22 ;
}
int F_38 ( struct V_1 * V_2 ,
const struct V_97 * V_3 )
{
int V_10 ;
struct V_4 * V_5 = & V_2 -> V_11 ;
F_5 ( V_2 ) ;
F_7 ( V_5 , V_3 -> V_98 [ 3 ] . V_99 ) ;
F_7 ( V_5 , V_3 -> V_98 [ 2 ] . V_99 ) ;
F_7 ( V_5 , V_3 -> V_98 [ 1 ] . V_99 ) ;
F_7 ( V_5 , V_3 -> V_98 [ 0 ] . V_99 ) ;
F_7 ( V_5 , V_3 -> V_98 [ 3 ] . V_100 ) ;
F_7 ( V_5 , V_3 -> V_98 [ 2 ] . V_100 ) ;
F_7 ( V_5 , V_3 -> V_98 [ 1 ] . V_100 ) ;
F_7 ( V_5 , V_3 -> V_98 [ 0 ] . V_100 ) ;
F_24 ( V_5 , V_3 -> V_98 [ 3 ] . V_101 ) ;
F_24 ( V_5 , V_3 -> V_98 [ 2 ] . V_101 ) ;
F_24 ( V_5 , V_3 -> V_98 [ 1 ] . V_101 ) ;
F_24 ( V_5 , V_3 -> V_98 [ 0 ] . V_101 ) ;
F_7 ( V_5 , V_3 -> V_98 [ 3 ] . V_102 ) ;
F_7 ( V_5 , V_3 -> V_98 [ 2 ] . V_102 ) ;
F_7 ( V_5 , V_3 -> V_98 [ 1 ] . V_102 ) ;
F_7 ( V_5 , V_3 -> V_98 [ 0 ] . V_102 ) ;
F_6 ( V_5 , V_3 -> V_98 [ 3 ] . V_103 ) ;
F_6 ( V_5 , V_3 -> V_98 [ 2 ] . V_103 ) ;
F_6 ( V_5 , V_3 -> V_98 [ 1 ] . V_103 ) ;
F_6 ( V_5 , V_3 -> V_98 [ 0 ] . V_103 ) ;
V_10 = F_9 ( V_2 , V_5 , NULL ,
V_104 , V_20 ) ;
F_10 ( V_2 ) ;
return V_10 ;
V_21:
F_10 ( V_2 ) ;
return - V_22 ;
}
int F_39 ( struct V_1 * V_2 ,
const struct F_39 * V_3 )
{
int V_10 ;
struct V_4 * V_5 = & V_2 -> V_11 ;
F_5 ( V_2 ) ;
F_24 ( V_5 , V_3 -> V_71 ) ;
F_24 ( V_5 , V_3 -> V_105 ) ;
F_7 ( V_5 , V_3 -> V_72 ) ;
V_2 -> V_106 = 1 ;
V_10 = F_9 ( V_2 , V_5 , NULL ,
V_107 , V_20 ) ;
if ( V_10 )
V_2 -> V_106 = 0 ;
F_10 ( V_2 ) ;
return V_10 ;
V_21:
F_10 ( V_2 ) ;
return - V_22 ;
}
int F_40 ( struct V_1 * V_2 , const struct F_40 * V_3 )
{
int V_10 ;
struct V_4 * V_5 = & V_2 -> V_11 ;
V_2 -> V_108 = 1 ;
F_5 ( V_2 ) ;
F_24 ( V_5 , V_3 -> V_71 ) ;
F_24 ( V_5 , V_3 -> V_109 ) ;
F_24 ( V_5 , V_3 -> V_110 ) ;
F_24 ( V_5 , V_3 -> V_111 ) ;
V_10 = F_9 ( V_2 , V_5 , NULL ,
V_112 , V_20 ) ;
F_10 ( V_2 ) ;
return V_10 ;
V_21:
F_10 ( V_2 ) ;
return - V_22 ;
}
int F_41 ( struct V_1 * V_2 , const struct F_41 * V_3 )
{
int V_10 ;
struct V_4 * V_5 = & V_2 -> V_11 ;
F_5 ( V_2 ) ;
F_24 ( V_5 , V_3 -> V_71 ) ;
F_24 ( V_5 , V_3 -> V_47 ) ;
F_7 ( V_5 , V_3 -> V_72 ) ;
F_6 ( V_5 , V_3 -> V_113 ) ;
F_6 ( V_5 , V_3 -> V_79 ) ;
F_24 ( V_5 , V_3 -> V_77 ) ;
F_24 ( V_5 , V_3 -> V_114 ) ;
F_24 ( V_5 , V_3 -> V_52 ) ;
F_24 ( V_5 , V_3 -> V_78 ) ;
F_8 ( V_5 , V_3 -> V_59 , sizeof( V_3 -> V_59 ) ) ;
F_6 ( V_5 , V_3 -> V_80 ) ;
V_2 -> V_81 = - 1 ;
V_10 = F_9 ( V_2 , V_5 , NULL ,
V_115 , V_116 ) ;
F_10 ( V_2 ) ;
return V_10 ;
V_21:
F_10 ( V_2 ) ;
return - V_22 ;
}
int F_42 ( struct V_1 * V_2 ,
const struct F_42 * V_3 )
{
int V_10 ;
struct V_4 * V_5 = & V_2 -> V_11 ;
F_5 ( V_2 ) ;
F_6 ( V_5 , V_3 -> V_117 ? 1 : 0 ) ;
V_10 = F_9 ( V_2 , V_5 , NULL ,
V_118 , V_20 ) ;
F_10 ( V_2 ) ;
return V_10 ;
V_21:
F_10 ( V_2 ) ;
return - V_22 ;
}
int F_43 ( struct V_1 * V_2 )
{
int V_10 ;
struct V_4 * V_5 = & V_2 -> V_11 ;
F_5 ( V_2 ) ;
V_10 = F_9 ( V_2 , V_5 , NULL , 0x0019 , V_20 ) ;
F_10 ( V_2 ) ;
return V_10 ;
}
int F_44 ( struct V_1 * V_2 )
{
int V_10 ;
struct V_4 * V_5 = & V_2 -> V_11 ;
F_5 ( V_2 ) ;
V_10 = F_9 ( V_2 , V_5 , NULL , 0x001A , V_20 ) ;
F_10 ( V_2 ) ;
return V_10 ;
}
int F_45 ( struct V_1 * V_2 , const struct F_45 * V_3 )
{
int V_10 ;
struct V_4 * V_5 = & V_2 -> V_11 ;
T_2 V_30 = 0x001C | F_16 ( V_3 -> V_32 ) ;
F_5 ( V_2 ) ;
F_8 ( V_5 , & V_3 -> V_119 [ 0 ] , sizeof( V_3 -> V_119 ) ) ;
F_7 ( V_5 , 0 ) ;
V_10 = F_9 ( V_2 , V_5 , NULL , V_30 , V_20 ) ;
F_10 ( V_2 ) ;
return V_10 ;
V_21:
F_10 ( V_2 ) ;
return - V_22 ;
}
int F_46 ( struct V_1 * V_2 ,
const struct F_46 * V_3 )
{
int V_10 ;
struct V_4 * V_5 = & V_2 -> V_11 ;
F_5 ( V_2 ) ;
F_7 ( V_5 , V_3 -> V_120 ) ;
F_7 ( V_5 , V_3 -> V_68 ) ;
F_8 ( V_5 , V_3 -> V_121 , V_3 -> V_58 ) ;
V_10 = F_9 ( V_2 , V_5 , NULL , 0x001B , V_20 ) ;
F_10 ( V_2 ) ;
return V_10 ;
V_21:
F_10 ( V_2 ) ;
return - V_22 ;
}
int F_47 ( struct V_1 * V_2 , bool V_122 )
{
V_2 -> V_123 . V_124 = V_122 ;
return F_48 ( V_2 , & V_2 -> V_123 ) ;
}
static int F_49 ( struct V_1 * V_2 ,
struct V_4 * V_5 )
{
V_2 -> V_125 . V_126 = F_19 ( V_5 ) ;
V_2 -> V_125 . V_127 = F_19 ( V_5 ) ;
V_2 -> V_125 . V_128 = F_19 ( V_5 ) ;
V_2 -> V_125 . V_129 = F_19 ( V_5 ) ;
V_2 -> V_125 . V_6 = F_19 ( V_5 ) ;
V_2 -> V_125 . V_130 = F_19 ( V_5 ) ;
V_2 -> V_125 . V_131 = F_19 ( V_5 ) ;
V_2 -> V_125 . V_132 = F_19 ( V_5 ) ;
V_2 -> V_125 . V_133 = F_19 ( V_5 ) ;
V_2 -> V_125 . V_134 = F_19 ( V_5 ) ;
F_12 ( V_5 , V_2 -> V_125 . V_135 , sizeof( V_2 -> V_125 . V_135 ) ) ;
V_2 -> V_125 . V_135 [ sizeof( V_2 -> V_125 . V_135 ) - 1 ] = 0 ;
if ( F_3 ( V_2 -> V_125 . V_6 ) )
return - V_8 ;
if ( F_3 ( V_2 -> V_125 . V_131 > 4 ) )
return - V_8 ;
F_50 ( L_1
L_2
L_3
L_4
L_5 ,
V_2 -> V_125 . V_126 ,
V_2 -> V_125 . V_127 ,
V_2 -> V_125 . V_128 , V_2 -> V_125 . V_129 ,
V_136 [ V_2 -> V_125 . V_131 ] ,
V_2 -> V_125 . V_135 , V_2 -> V_125 . V_134 ,
V_2 -> V_125 . V_133 ,
V_2 -> V_125 . V_132 , V_2 -> V_125 . V_130 ) ;
if ( ! ( V_2 -> V_125 . V_130 & 0x1 ) )
V_2 -> V_137 -> V_138 -> V_139 [ V_140 ] = NULL ;
if ( ! ( V_2 -> V_125 . V_130 & 0x2 ) )
V_2 -> V_137 -> V_138 -> V_139 [ V_141 ] = NULL ;
V_2 -> V_142 = 1 ;
F_51 ( & V_2 -> V_143 ) ;
return 0 ;
V_9:
F_3 ( 1 ) ;
return - V_8 ;
}
static int F_52 ( struct V_1 * V_2 ,
int V_32 ,
struct V_4 * V_5 ,
struct V_144 * * V_145 )
{
struct V_146 V_147 ;
struct V_148 * V_149 ;
T_3 V_150 ;
T_5 V_151 ;
V_147 . V_6 = F_2 ( V_5 ) ;
V_147 . V_72 = F_19 ( V_5 ) ;
V_147 . V_152 = F_13 ( V_5 ) ;
V_147 . V_153 = F_13 ( V_5 ) ;
V_147 . V_48 = F_2 ( V_5 ) ;
V_149 = (struct V_148 * ) ( * V_145 ) -> V_154 ;
if ( ! V_147 . V_153 &&
( F_53 ( V_149 -> V_155 ) ||
F_54 ( V_149 -> V_155 ) ) )
return 0 ;
if ( ! V_2 -> V_156 )
V_147 . V_153 = V_147 . V_153 / 2 - 110 ;
V_151 = * ( T_5 * ) V_5 -> V_154 ;
V_150 = V_5 -> V_154 - V_5 -> V_157 ;
F_55 ( * V_145 , V_150 ) ;
if ( ! V_147 . V_6 && F_56 ( V_151 ) ) {
if ( V_2 -> V_158 == V_159 ) {
F_57 ( L_6 ) ;
F_58 ( V_2 ) ;
if ( F_59 ( V_2 -> V_160 ,
& V_2 -> V_161 ) <= 0 )
F_60 ( V_2 ) ;
}
}
F_61 ( V_2 , & V_147 , V_32 , V_145 ) ;
if ( * V_145 )
F_62 ( * V_145 , V_150 ) ;
return 0 ;
V_9:
return - V_8 ;
}
static int F_63 ( struct V_1 * V_2 , struct V_4 * V_5 )
{
int V_162 ;
struct V_163 * V_164 ;
if ( V_2 -> V_71 == V_165 ) {
return 0 ;
}
V_164 = F_64 ( sizeof( struct V_163 ) , V_166 ) ;
if ( ! V_164 )
return - V_22 ;
V_164 -> V_167 . V_92 = F_2 ( V_5 ) ;
V_164 -> V_167 . V_154 = F_2 ( V_5 ) ;
F_57 ( L_7 ,
V_164 -> V_167 . V_92 , V_164 -> V_167 . V_154 ) ;
F_65 ( & V_2 -> V_168 ) ;
V_162 = F_66 ( & V_2 -> V_169 ) ;
F_67 ( & V_164 -> V_170 , & V_2 -> V_169 ) ;
F_68 ( & V_2 -> V_168 ) ;
if ( V_162 )
F_59 ( V_2 -> V_160 , & V_2 -> V_171 ) ;
return 0 ;
V_9:
F_69 ( V_164 ) ;
return - V_8 ;
}
static int F_70 ( struct V_1 * V_2 ,
struct V_4 * V_5 )
{
F_3 ( F_2 ( V_5 ) ) ;
V_2 -> V_106 = 0 ;
F_51 ( & V_2 -> V_172 ) ;
F_60 ( V_2 ) ;
return 0 ;
V_9:
return - V_8 ;
}
static int F_71 ( struct V_1 * V_2 ,
struct V_4 * V_5 )
{
if ( V_2 -> V_108 ) {
V_2 -> V_108 = 0 ;
F_51 ( & V_2 -> V_173 ) ;
}
return 0 ;
}
static int F_72 ( struct V_1 * V_2 , void * V_3 ,
struct V_4 * V_5 )
{
T_1 V_6 = F_2 ( V_5 ) ;
if ( V_6 != V_7 ) {
F_73 ( V_2 ) ;
return - V_8 ;
}
return 0 ;
V_9:
F_3 ( 1 ) ;
return - V_8 ;
}
static int F_74 ( struct V_1 * V_2 ,
struct V_4 * V_5 )
{
struct V_174 V_3 ;
V_3 . V_6 = F_2 ( V_5 ) ;
V_3 . V_175 = F_13 ( V_5 ) ;
V_3 . V_45 = F_13 ( V_5 ) ;
F_75 ( V_2 , & V_3 ) ;
return 0 ;
V_9:
return - V_8 ;
}
static int F_76 ( struct V_1 * V_2 ,
struct V_4 * V_5 )
{
struct V_176 V_3 ;
V_3 . V_6 = F_2 ( V_5 ) ;
F_57 ( L_8 , V_3 . V_6 ) ;
F_77 ( V_2 , & V_3 ) ;
return 0 ;
V_9:
return - V_8 ;
}
static int F_78 ( struct V_1 * V_2 ,
struct V_4 * V_5 )
{
F_79 ( L_9 ) ;
return 0 ;
}
static int F_80 ( struct V_1 * V_2 ,
struct V_4 * V_5 )
{
T_1 V_177 ;
T_4 V_178 ;
T_4 V_179 ;
T_4 V_180 [ V_17 ] ;
V_177 = F_2 ( V_5 ) ;
V_178 = F_13 ( V_5 ) ;
V_179 = F_13 ( V_5 ) ;
F_12 ( V_5 , V_180 , V_17 ) ;
F_50 ( L_10 ,
V_178 , V_180 ) ;
return 0 ;
V_9:
return - V_8 ;
}
static int F_81 ( struct V_1 * V_2 ,
int V_32 , struct V_4 * V_5 )
{
T_1 V_48 ;
struct V_181 V_3 ;
V_48 = F_2 ( V_5 ) ;
V_3 . V_32 = V_32 ;
V_3 . V_182 = ! ( V_48 & 1 ) ;
V_3 . V_183 = ! ! ( V_48 & 8 ) ;
V_3 . V_184 = ( V_48 >> 1 ) & 3 ;
F_82 ( V_2 , & V_3 ) ;
return 0 ;
V_9:
return - V_8 ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_4 * V_5 ,
void * V_3 , T_2 V_30 , long V_185 )
{
T_3 V_186 = V_5 -> V_154 - V_5 -> V_157 ;
int V_10 ;
if ( V_2 -> V_187 ) {
V_10 = 0 ;
goto V_188;
}
F_65 ( & V_2 -> V_189 . V_190 ) ;
while ( ! V_2 -> V_189 . V_188 ) {
F_68 ( & V_2 -> V_189 . V_190 ) ;
F_65 ( & V_2 -> V_189 . V_190 ) ;
}
V_2 -> V_189 . V_188 = 0 ;
F_68 ( & V_2 -> V_189 . V_190 ) ;
if ( V_30 == V_42 ||
V_30 == V_40 )
F_57 ( L_11 ,
V_30 , F_83 ( ( ( T_5 * ) V_5 -> V_157 ) [ 2 ] ) ,
V_186 ) ;
else
F_57 ( L_12 , V_30 , V_186 ) ;
V_186 += 4 ;
( ( T_5 * ) V_5 -> V_157 ) [ 0 ] = F_84 ( V_186 ) ;
( ( T_5 * ) V_5 -> V_157 ) [ 1 ] = F_84 ( V_30 ) ;
F_65 ( & V_2 -> V_189 . V_190 ) ;
F_85 ( V_2 -> V_189 . V_191 ) ;
V_2 -> V_189 . V_191 = V_5 -> V_157 ;
V_2 -> V_189 . V_192 = V_186 ;
V_2 -> V_189 . V_3 = V_3 ;
V_2 -> V_189 . V_30 = V_30 ;
F_68 ( & V_2 -> V_189 . V_190 ) ;
F_30 ( V_2 ) ;
V_10 = F_86 ( V_2 -> V_193 ,
V_2 -> V_189 . V_188 , V_185 ) ;
if ( ! V_10 && ! V_2 -> V_189 . V_188 ) {
F_65 ( & V_2 -> V_189 . V_190 ) ;
V_2 -> V_189 . V_188 = 1 ;
V_2 -> V_189 . V_191 = NULL ;
F_68 ( & V_2 -> V_189 . V_190 ) ;
if ( V_2 -> V_187 ) {
V_10 = 0 ;
} else {
F_87 ( L_13 , V_2 -> V_189 . V_30 ) ;
F_88 ( L_14 , V_194 ,
V_5 -> V_157 , V_186 ) ;
F_87 ( L_15 , V_2 -> V_195 ) ;
F_89 ( 1 , & V_2 -> V_196 ) ;
F_51 ( & V_2 -> V_197 ) ;
V_10 = - V_198 ;
}
} else {
F_65 ( & V_2 -> V_189 . V_190 ) ;
F_85 ( ! V_2 -> V_189 . V_188 ) ;
V_10 = V_2 -> V_189 . V_10 ;
F_68 ( & V_2 -> V_189 . V_190 ) ;
}
V_188:
F_90 ( V_5 ) ;
return V_10 ;
}
void F_91 ( struct V_1 * V_2 )
{
F_5 ( V_2 ) ;
if ( F_92 ( 1 , & V_2 -> V_199 ) == 1 ) {
if ( F_93 ( V_2 ) )
F_57 ( L_16 ) ;
}
F_10 ( V_2 ) ;
}
void F_58 ( struct V_1 * V_2 )
{
if ( F_92 ( 1 , & V_2 -> V_199 ) == 1 )
F_57 ( L_17 ) ;
}
bool F_93 ( struct V_1 * V_2 )
{
unsigned long V_200 = V_201 ;
bool V_202 = false ;
long V_203 ;
int V_23 ;
F_85 ( ! F_94 ( & V_2 -> V_199 ) ) ;
if ( ! V_2 -> V_195 )
return true ;
if ( V_2 -> V_187 ) {
F_87 ( L_18 ) ;
return false ;
} else {
for ( V_23 = 0 ; V_23 < 4 ; ++ V_23 )
V_202 |= F_95 (
& V_2 -> V_204 [ V_23 ] ,
& V_200 , 0xffffffff ) ;
if ( ! V_202 )
return true ;
V_203 = V_200 + V_205 - V_201 ;
if ( V_203 < 0 || F_86 ( V_2 -> V_206 ,
! V_2 -> V_195 ,
V_203 ) <= 0 ) {
V_2 -> V_187 = 1 ;
F_96 ( V_2 -> V_137 -> V_138 , L_19 , V_2 -> V_195 ) ;
F_51 ( & V_2 -> V_197 ) ;
return false ;
}
return true ;
}
}
void F_60 ( struct V_1 * V_2 )
{
int V_199 ;
V_199 = F_97 ( 1 , & V_2 -> V_199 ) ;
F_85 ( V_199 < 0 ) ;
if ( V_199 == 0 ) {
if ( ! V_2 -> V_187 )
F_30 ( V_2 ) ;
F_57 ( L_20 ) ;
}
}
int F_98 ( struct V_1 * V_2 , T_4 * V_154 , T_3 V_192 )
{
struct V_4 V_5 ;
T_1 V_207 ;
T_1 V_208 [ 18 ] ;
char V_209 [ 48 ] ;
unsigned int V_23 ;
static const char * const V_210 [] = {
L_21 ,
L_22 ,
L_23 ,
L_24 ,
} ;
V_5 . V_157 = V_5 . V_154 = V_154 ;
V_5 . V_211 = & V_5 . V_157 [ V_192 ] ;
V_207 = F_2 ( & V_5 ) ;
for ( V_23 = 0 ; V_23 < F_99 ( V_208 ) ; ++ V_23 )
V_208 [ V_23 ] = F_2 ( & V_5 ) ;
F_12 ( & V_5 , V_209 , sizeof( V_209 ) ) ;
if ( V_207 < 4 )
F_96 ( V_2 -> V_137 -> V_138 ,
L_25 ,
V_210 [ V_207 ] ) ;
else
F_96 ( V_2 -> V_137 -> V_138 ,
L_26 ,
( int ) sizeof( V_209 ) , V_209 , V_208 [ 1 ] ) ;
for ( V_23 = 0 ; V_23 < 12 ; V_23 += 4 )
F_96 ( V_2 -> V_137 -> V_138 ,
L_27 ,
V_23 + 0 , V_208 [ V_23 + 0 ] , V_23 + 1 , V_208 [ V_23 + 1 ] ,
V_23 + 2 , V_208 [ V_23 + 2 ] , V_23 + 3 , V_208 [ V_23 + 3 ] ) ;
F_96 ( V_2 -> V_137 -> V_138 ,
L_28 ,
V_208 [ V_23 + 0 ] , V_208 [ V_23 + 1 ] , V_208 [ V_23 + 2 ] , V_208 [ V_23 + 3 ] ) ;
V_23 += 4 ;
F_96 ( V_2 -> V_137 -> V_138 ,
L_29 ,
V_208 [ V_23 + 0 ] , V_208 [ V_23 + 1 ] ) ;
F_88 ( L_30 , V_194 ,
V_209 , sizeof( V_209 ) ) ;
return 0 ;
V_9:
F_96 ( V_2 -> V_137 -> V_138 , L_31 ) ;
F_88 ( L_32 , V_194 ,
V_154 , V_192 ) ;
return - V_8 ;
}
int F_100 ( struct V_1 * V_2 , T_2 V_92 ,
struct V_212 * V_213 , struct V_144 * * V_145 )
{
int V_10 = 0 ;
struct V_4 V_4 ;
int V_32 = ( V_92 >> 6 ) & 0x0F ;
V_92 &= ~ F_16 ( V_214 ) ;
V_4 . V_157 = ( T_4 * ) & V_213 [ 0 ] ;
V_4 . V_154 = ( T_4 * ) & V_213 [ 1 ] ;
V_4 . V_211 = & V_4 . V_157 [ F_83 ( V_213 -> V_192 ) ] ;
F_57 ( L_33 , V_92 ,
V_4 . V_211 - V_4 . V_157 ) ;
if ( V_92 == V_215 ) {
V_10 = F_26 ( V_2 , & V_4 , V_32 ) ;
} else if ( V_92 == V_216 ) {
V_10 = F_28 ( V_2 , & V_4 , V_32 ) ;
} else if ( V_92 & 0x0400 ) {
void * V_217 ;
T_2 V_189 ;
F_65 ( & V_2 -> V_189 . V_190 ) ;
V_217 = V_2 -> V_189 . V_3 ;
V_189 = V_2 -> V_189 . V_30 &
~ F_16 ( V_214 ) ;
V_2 -> V_189 . V_30 = 0xFFFF ;
F_68 ( & V_2 -> V_189 . V_190 ) ;
if ( F_3 ( ( V_92 & ~ 0x0400 ) != V_189 ) ) {
V_10 = - V_8 ;
goto V_218;
}
switch ( V_92 ) {
case V_219 :
if ( V_217 )
V_10 = F_18 ( V_2 , V_217 ,
& V_4 ) ;
break;
case V_220 :
if ( V_217 )
V_10 = F_21 ( V_2 , V_217 ,
& V_4 ) ;
break;
case V_221 :
if ( V_217 )
V_10 = F_72 ( V_2 , V_217 , & V_4 ) ;
break;
case V_222 :
if ( V_217 )
V_10 = F_11 ( V_2 , V_217 ,
& V_4 ) ;
break;
case V_223 :
if ( V_217 )
V_10 = F_32 ( V_2 , V_217 , & V_4 ) ;
break;
case V_224 :
case V_225 :
case V_226 :
case V_227 :
case V_228 :
case V_229 :
case 0x0412 :
case V_230 :
case V_231 :
case V_232 :
case V_233 :
case 0x0419 :
case 0x041A :
case 0x041B :
case 0x041C :
F_3 ( V_217 != NULL ) ;
V_10 = F_1 ( V_2 , V_217 , & V_4 ) ;
if ( V_10 ) {
F_101 ( V_2 -> V_137 -> V_138 ,
L_34 ,
V_92 & ~ 0x0400 ) ;
if ( V_2 -> V_158 >= V_234 ) {
F_91 ( V_2 ) ;
if ( F_59 ( V_2 -> V_160 , & V_2 -> V_161 ) <= 0 )
F_60 ( V_2 ) ;
}
}
break;
default:
F_101 ( V_2 -> V_137 -> V_138 ,
L_35 ,
V_92 & ~ 0x0400 ) ;
}
F_65 ( & V_2 -> V_189 . V_190 ) ;
V_2 -> V_189 . V_10 = V_10 ;
V_2 -> V_189 . V_188 = 1 ;
F_68 ( & V_2 -> V_189 . V_190 ) ;
V_10 = 0 ;
F_51 ( & V_2 -> V_193 ) ;
} else if ( V_92 & 0x0800 ) {
switch ( V_92 ) {
case V_235 :
V_10 = F_49 ( V_2 , & V_4 ) ;
break;
case V_236 :
V_10 = F_52 ( V_2 , V_32 ,
& V_4 , V_145 ) ;
break;
case 0x0805 :
V_10 = F_63 ( V_2 , & V_4 ) ;
break;
case V_237 :
V_10 = F_74 ( V_2 , & V_4 ) ;
break;
case 0x0808 :
V_10 = F_80 ( V_2 , & V_4 ) ;
break;
case 0x0809 :
V_10 = F_71 ( V_2 , & V_4 ) ;
break;
case 0x080A :
V_10 = F_70 ( V_2 , & V_4 ) ;
break;
case 0x080B :
V_10 = F_78 ( V_2 , & V_4 ) ;
break;
case 0x080C :
V_10 = F_81 ( V_2 ,
V_32 , & V_4 ) ;
break;
case 0x080F :
V_10 = F_76 ( V_2 , & V_4 ) ;
break;
default:
F_79 ( L_36 , V_92 ) ;
}
} else {
F_3 ( 1 ) ;
V_10 = - V_8 ;
}
V_218:
return V_10 ;
}
static bool F_102 ( struct V_1 * V_2 ,
struct V_238 * V_213 ,
const struct V_239 * V_240 ,
const struct V_241 * V_242 ,
struct V_243 * V_184 )
{
bool V_244 = false ;
const struct V_148 * V_245 =
(struct V_148 * ) & ( ( T_4 * ) V_213 ) [ V_242 -> V_246 ] ;
T_5 V_151 = V_245 -> V_155 ;
enum {
V_247 ,
V_248 ,
V_249 ,
V_250 ,
} V_251 = V_250 ;
switch ( V_2 -> V_71 ) {
case V_252 :
if ( V_2 -> V_158 == V_253 )
V_251 = V_250 ;
else if ( V_2 -> V_158 < V_254 )
V_251 = V_248 ;
break;
case V_255 :
if ( ! V_2 -> V_158 ) {
V_251 = V_248 ;
} else if ( ! ( F_103 ( V_242 -> V_256 ) &
( F_103 ( 0 ) | V_2 -> V_257 ) ) ) {
F_101 ( V_2 -> V_137 -> V_138 ,
L_37 ) ;
V_251 = V_248 ;
}
if ( F_104 ( V_213 -> V_63 ) >
V_258 ) {
F_101 ( V_2 -> V_137 -> V_138 ,
L_38 ) ;
V_251 = V_248 ;
}
break;
case V_259 :
if ( V_2 -> V_158 != V_260 )
V_251 = V_248 ;
break;
case V_261 :
V_251 = V_250 ;
break;
case V_262 :
default:
V_251 = V_248 ;
break;
}
if ( V_251 == V_250 ) {
if ( F_105 ( V_151 ) ) {
F_65 ( & V_2 -> V_263 ) ;
if ( V_2 -> V_264 ) {
V_2 -> V_265 = V_213 -> V_63 ;
V_213 -> V_266 = V_267 ;
}
F_68 ( & V_2 -> V_263 ) ;
} else if ( F_106 ( V_151 ) ) {
V_251 = V_247 ;
} else if ( F_56 ( V_151 ) &&
V_2 -> V_71 != V_255 ) {
F_57 ( L_39 ) ;
F_58 ( V_2 ) ;
if ( F_59 ( V_2 -> V_160 ,
& V_2 -> V_161 ) <= 0 )
F_60 ( V_2 ) ;
} else if ( F_107 ( V_151 ) &&
V_240 -> V_268 . V_269 &&
V_240 -> V_268 . V_269 -> V_270 != V_2 -> V_271 &&
( V_240 -> V_268 . V_269 -> V_272 == V_273 ||
V_240 -> V_268 . V_269 -> V_272 == V_274 ) ) {
V_251 = V_249 ;
}
}
switch ( V_251 ) {
case V_247 :
F_57 ( L_40 ) ;
F_58 ( V_2 ) ;
V_2 -> V_275 = V_213 -> V_63 ;
if ( F_108 ( V_2 -> V_160 ,
& V_2 -> V_276 . V_277 , 0 ) <= 0 )
F_60 ( V_2 ) ;
V_244 = true ;
break;
case V_248 :
F_57 ( L_41 , V_151 ) ;
F_85 ( F_109 ( V_184 , V_213 -> V_63 ) ) ;
V_244 = true ;
break;
case V_249 :
F_57 ( L_42 ) ;
F_58 ( V_2 ) ;
V_2 -> V_271 = V_240 -> V_268 . V_269 -> V_270 ;
V_2 -> V_275 = V_213 -> V_63 ;
if ( F_59 ( V_2 -> V_160 , & V_2 -> V_278 ) <= 0 )
F_60 ( V_2 ) ;
V_244 = true ;
break;
case V_250 :
F_57 ( L_43 ) ;
break;
default:
break;
}
return V_244 ;
}
static int F_110 ( struct V_1 * V_2 ,
T_1 V_257 , int * V_279 )
{
static const int V_280 = F_103 ( V_281 ) |
F_103 ( V_282 ) ;
struct V_283 * V_284 ;
unsigned V_285 , V_286 = - 1 ;
int V_287 = - 1 ;
int V_288 ;
int V_23 ;
for ( V_23 = 0 ; V_23 < 4 ; ++ V_23 ) {
V_288 = F_111 ( & V_2 -> V_204 [ V_23 ] ,
V_257 ) ;
if ( ! V_288 )
continue;
* V_279 += V_288 ;
V_284 = & V_2 -> V_284 . V_98 [ V_23 ] ;
V_285 = ( ( V_284 -> V_101 + V_284 -> V_99 ) << 16 ) +
( ( V_284 -> V_100 - V_284 -> V_99 ) *
( F_112 () & 0xFFFF ) ) ;
if ( V_285 < V_286 && ( V_287 < 0 || V_23 != 3 ) ) {
V_286 = V_285 ;
V_287 = V_23 ;
}
}
if ( V_287 >= 0 && V_2 -> V_81 >= 0 &&
V_287 != V_2 -> V_81 &&
! F_111 (
& V_2 -> V_204 [ V_287 ] ,
V_257 & V_280 ) &&
F_111 (
& V_2 -> V_204 [ V_2 -> V_81 ] ,
V_257 ) )
V_287 = V_2 -> V_81 ;
return V_287 ;
}
static int F_113 ( struct V_1 * V_2 ,
struct V_243 * * V_289 ,
T_1 * V_290 ,
bool * V_291 )
{
int V_292 ;
T_1 V_293 ;
int V_279 = 0 ;
if ( V_2 -> V_294 ) {
V_293 = F_103 ( V_281 ) ;
V_292 = F_110 ( V_2 ,
V_293 , & V_279 ) ;
if ( V_292 >= 0 ) {
* V_291 = V_279 > 1 ;
goto V_295;
}
}
V_293 = ~ V_2 -> V_296 ;
V_293 |= F_103 ( V_282 ) ;
if ( V_2 -> V_296 ) {
V_293 |= V_2 -> V_297 ;
V_293 &= ~ F_103 ( V_281 ) ;
} else {
V_293 |= F_103 ( V_281 ) ;
}
V_292 = F_110 ( V_2 ,
V_293 , & V_279 ) ;
if ( V_292 < 0 )
return - V_298 ;
V_295:
* V_289 = & V_2 -> V_204 [ V_292 ] ;
* V_290 = V_293 ;
return 0 ;
}
int F_114 ( struct V_1 * V_2 , T_4 * * V_154 ,
T_3 * V_299 , int * V_300 )
{
struct V_238 * V_213 = NULL ;
struct V_239 * V_240 ;
struct V_243 * V_184 = NULL ;
int V_301 ;
T_1 V_293 = 0 ;
const struct V_241 * V_242 = NULL ;
int V_68 = 0 ;
bool V_291 = false ;
if ( V_2 -> V_189 . V_191 ) {
++ V_68 ;
F_65 ( & V_2 -> V_189 . V_190 ) ;
F_85 ( ! V_2 -> V_189 . V_191 ) ;
* V_154 = V_2 -> V_189 . V_191 ;
* V_299 = V_2 -> V_189 . V_192 ;
* V_300 = 1 ;
F_68 ( & V_2 -> V_189 . V_190 ) ;
} else {
for (; ; ) {
int V_10 ;
if ( F_92 ( 0 , & V_2 -> V_199 ) )
break;
F_115 ( & V_2 -> V_302 ) ;
V_10 = F_113 ( V_2 , & V_184 ,
& V_293 , & V_291 ) ;
V_301 = V_184 - V_2 -> V_204 ;
if ( V_2 -> V_303 &&
( V_10 || ! V_291 ) &&
( V_2 -> V_294 || ! V_2 -> V_296 ) ) {
V_2 -> V_303 = false ;
if ( V_2 -> V_294 ) {
V_2 -> V_294 = false ;
F_59 ( V_2 -> V_160 ,
& V_2 -> V_304 ) ;
}
}
F_116 ( & V_2 -> V_302 ) ;
if ( V_10 )
break;
if ( F_117 ( V_184 ,
V_293 ,
& V_213 , & V_240 , & V_242 ) )
continue;
if ( F_102 ( V_2 , V_213 ,
V_240 , V_242 , V_184 ) )
continue;
V_213 -> V_149 . V_92 &= F_84 (
~ F_16 ( V_214 ) ) ;
V_213 -> V_149 . V_92 |= F_118 (
F_16 ( V_242 -> V_256 ) ) ;
V_2 -> V_297 &= ~ F_103 ( V_242 -> V_256 ) ;
* V_154 = ( T_4 * ) V_213 ;
* V_299 = F_83 ( V_213 -> V_149 . V_192 ) ;
if ( V_2 -> V_284 . V_98 [ V_301 ] . V_102 )
* V_300 = F_119 ( * V_300 ,
( int ) F_111 ( V_184 , V_293 ) + 1 ) ;
else
* V_300 = 1 ;
if ( * V_300 > 1 )
V_2 -> V_81 = V_301 ;
else
V_2 -> V_81 = - 1 ;
if ( V_291 ) {
struct V_148 * V_149 =
(struct V_148 * )
& ( ( T_4 * ) V_213 ) [ V_242 -> V_246 ] ;
V_149 -> V_155 |=
F_118 ( V_305 ) ;
}
F_57 ( L_44 ,
0x0004 , * V_299 , * V_154 ,
V_213 -> V_291 ? 'M' : ' ' ) ;
++ V_68 ;
break;
}
}
return V_68 ;
}
void F_120 ( struct V_1 * V_2 , T_4 * V_154 )
{
if ( V_154 == V_2 -> V_189 . V_191 ) {
F_65 ( & V_2 -> V_189 . V_190 ) ;
V_2 -> V_189 . V_191 = NULL ;
F_68 ( & V_2 -> V_189 . V_190 ) ;
}
}
void F_121 ( struct V_4 * V_5 )
{
F_85 ( V_5 -> V_157 ) ;
V_5 -> V_157 = F_122 ( V_306 , V_166 | V_307 ) ;
V_5 -> V_211 = V_5 -> V_157 ? & V_5 -> V_157 [ V_306 ] : V_5 -> V_157 ;
F_90 ( V_5 ) ;
}
void F_123 ( struct V_4 * V_5 )
{
F_69 ( V_5 -> V_157 ) ;
V_5 -> V_157 = V_5 -> V_154 = V_5 -> V_211 = NULL ;
}
static void F_90 ( struct V_4 * V_5 )
{
if ( V_5 -> V_157 ) {
V_5 -> V_154 = & V_5 -> V_157 [ 4 ] ;
* ( T_1 * ) V_5 -> V_157 = 0 ;
} else {
V_5 -> V_154 = V_5 -> V_157 ;
}
}
static int F_124 ( struct V_4 * V_5 , T_3 V_308 )
{
T_3 V_309 = V_5 -> V_154 - V_5 -> V_157 ;
T_3 V_41 = V_309 + V_308 ;
T_4 * V_310 ;
V_41 = F_125 ( V_41 , V_306 ) ;
V_310 = F_126 ( V_5 -> V_157 , V_41 , V_166 | V_307 ) ;
if ( ! V_310 ) {
F_123 ( V_5 ) ;
return - V_22 ;
}
V_5 -> V_157 = V_310 ;
V_5 -> V_154 = & V_5 -> V_157 [ V_309 ] ;
V_5 -> V_211 = & V_5 -> V_157 [ V_41 ] ;
return 0 ;
}
