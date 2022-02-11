static int F_1 ( struct V_1 * V_1 , void * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_1 ) ;
F_3 ( V_4 -> V_7 , V_8 , sizeof( V_4 -> V_7 ) ) ;
F_3 ( V_4 -> V_9 , V_8 , sizeof( V_4 -> V_9 ) ) ;
snprintf ( V_4 -> V_10 , sizeof( V_4 -> V_10 ) ,
L_1 , V_6 -> V_11 . V_12 -> V_13 ) ;
return 0 ;
}
static void F_4 ( struct V_14 * V_15 ,
struct V_16 * V_17 )
{
struct V_5 * V_6 = F_5 ( V_15 , struct V_5 ,
V_15 ) ;
* V_17 = V_6 -> V_18 ;
}
static int F_6 ( struct V_1 * V_1 , void * V_2 ,
struct V_19 * V_20 )
{
struct V_5 * V_6 = F_2 ( V_1 ) ;
V_20 -> V_17 . V_21 = V_6 -> V_18 ;
return 0 ;
}
static int F_7 ( struct V_1 * V_1 , void * V_2 ,
struct V_19 * V_20 )
{
struct V_16 * V_18 = & V_20 -> V_17 . V_21 ;
const struct V_22 * V_23 ;
V_18 -> V_24 = F_8 ( V_25 , V_18 -> V_24 , V_26 ,
V_27 ) & ~ 1 ;
V_18 -> V_28 = F_8 ( V_25 , V_18 -> V_28 , V_29 ,
V_30 ) & ~ 1 ;
V_23 = F_9 ( V_18 -> V_31 ) ;
if ( ! V_23 ) {
V_18 -> V_31 = V_32 . V_31 ;
V_23 = F_9 ( V_18 -> V_31 ) ;
}
V_18 -> V_33 = V_18 -> V_24 * V_23 -> V_34 ;
V_18 -> V_35 = V_18 -> V_33 * V_18 -> V_28 ;
if ( V_18 -> V_36 == V_37 )
V_18 -> V_36 = V_32 . V_36 ;
F_10 ( V_18 ) ;
return 0 ;
}
static int F_11 ( struct V_1 * V_1 , void * V_2 ,
struct V_19 * V_20 )
{
struct V_5 * V_6 = F_2 ( V_1 ) ;
if ( F_12 ( & V_6 -> V_38 ) )
return - V_39 ;
F_7 ( V_1 , V_2 , V_20 ) ;
F_13 ( V_6 -> V_40 , L_2
L_3
L_4 , V_6 -> V_11 . V_13 ,
V_6 -> V_18 . V_24 , V_6 -> V_18 . V_28 ,
V_6 -> V_18 . V_31 , V_6 -> V_18 . V_41 ,
V_6 -> V_18 . V_42 , V_6 -> V_18 . V_43 ,
V_6 -> V_18 . V_44 ,
V_20 -> V_17 . V_21 . V_24 , V_20 -> V_17 . V_21 . V_28 ,
V_20 -> V_17 . V_21 . V_31 , V_20 -> V_17 . V_21 . V_41 ,
V_20 -> V_17 . V_21 . V_42 , V_20 -> V_17 . V_21 . V_43 ,
V_20 -> V_17 . V_21 . V_44 ) ;
V_6 -> V_18 = V_20 -> V_17 . V_21 ;
return 0 ;
}
static int F_14 ( struct V_1 * V_1 , void * V_2 ,
struct V_45 * V_20 )
{
const struct V_22 * V_23 = F_15 ( V_20 -> V_46 ) ;
if ( ! V_23 )
return - V_47 ;
V_20 -> V_31 = V_23 -> V_31 ;
return 0 ;
}
static int F_16 ( struct V_1 * V_1 , void * V_48 ,
struct V_49 * V_50 )
{
const struct V_22 * V_23 ;
if ( V_50 -> V_46 )
return - V_47 ;
V_23 = F_17 ( V_50 -> V_51 ) ;
if ( ! V_23 )
return - V_47 ;
V_50 -> type = V_52 ;
V_50 -> V_53 . V_54 = V_26 ;
V_50 -> V_53 . V_55 = V_27 ;
V_50 -> V_53 . V_56 = V_29 ;
V_50 -> V_53 . V_57 = V_30 ;
V_50 -> V_53 . V_58 = 2 ;
V_50 -> V_53 . V_59 = 2 ;
return 0 ;
}
static void F_18 ( struct V_5 * V_6 ,
enum V_60 V_61 )
{
struct V_62 * V_63 , * V_64 ;
F_19 ( & V_6 -> V_65 ) ;
F_20 (vbuf, node, &vcap->buf_list, list) {
F_21 ( & V_63 -> V_66 ) ;
F_22 ( & V_63 -> V_67 . V_68 , V_61 ) ;
}
F_23 ( & V_6 -> V_65 ) ;
}
static int F_24 ( struct V_69 * V_70 , unsigned int V_71 )
{
struct V_5 * V_6 = F_25 ( V_70 ) ;
struct V_72 * V_73 = & V_6 -> V_11 . V_73 ;
int V_74 ;
V_6 -> V_75 = 0 ;
V_74 = F_26 ( V_73 , & V_6 -> V_76 ) ;
if ( V_74 ) {
F_18 ( V_6 , V_77 ) ;
return V_74 ;
}
V_74 = F_27 ( & V_6 -> V_11 . V_73 , 1 ) ;
if ( V_74 ) {
F_28 ( V_73 ) ;
F_18 ( V_6 , V_77 ) ;
return V_74 ;
}
return 0 ;
}
static void F_29 ( struct V_69 * V_70 )
{
struct V_5 * V_6 = F_25 ( V_70 ) ;
F_27 ( & V_6 -> V_11 . V_73 , 0 ) ;
F_28 ( & V_6 -> V_11 . V_73 ) ;
F_18 ( V_6 , V_78 ) ;
}
static void F_30 ( struct V_79 * V_68 )
{
struct V_5 * V_6 = F_25 ( V_68 -> V_69 ) ;
struct V_62 * V_80 = F_5 ( V_68 ,
struct V_62 ,
V_67 . V_68 ) ;
F_19 ( & V_6 -> V_65 ) ;
F_31 ( & V_80 -> V_66 , & V_6 -> V_81 ) ;
F_23 ( & V_6 -> V_65 ) ;
}
static int F_32 ( struct V_69 * V_70 , unsigned int * V_82 ,
unsigned int * V_83 , unsigned int V_84 [] ,
struct V_85 * V_86 [] )
{
struct V_5 * V_6 = F_25 ( V_70 ) ;
if ( * V_83 )
return V_84 [ 0 ] < V_6 -> V_18 . V_35 ? - V_47 : 0 ;
* V_83 = 1 ;
V_84 [ 0 ] = V_6 -> V_18 . V_35 ;
return 0 ;
}
static int F_33 ( struct V_79 * V_87 )
{
struct V_5 * V_6 = F_25 ( V_87 -> V_69 ) ;
unsigned long V_88 = V_6 -> V_18 . V_35 ;
if ( F_34 ( V_87 , 0 ) < V_88 ) {
F_35 ( V_6 -> V_40 , L_5 ,
V_6 -> V_11 . V_13 , F_34 ( V_87 , 0 ) , V_88 ) ;
return - V_47 ;
}
return 0 ;
}
static void F_36 ( struct V_85 * V_89 , struct V_85 * V_90 ,
void * V_91 )
{
struct V_14 * V_15 = F_37 ( V_89 ) ;
struct V_5 * V_6 = F_5 ( V_15 , struct V_5 ,
V_15 ) ;
F_38 ( & V_6 -> V_38 ) ;
F_39 ( V_15 -> V_92 ) ;
F_40 ( & V_6 -> V_11 ) ;
F_41 ( V_6 -> V_15 . V_93 ) ;
F_42 ( V_6 ) ;
}
static void F_43 ( struct V_14 * V_15 ,
struct V_94 * V_95 , const void * V_96 )
{
struct V_5 * V_6 = F_5 ( V_15 , struct V_5 ,
V_15 ) ;
struct V_62 * V_97 ;
void * V_63 ;
F_19 ( & V_6 -> V_65 ) ;
V_97 = F_44 ( & V_6 -> V_81 ,
F_45 ( * V_97 ) , V_66 ) ;
if ( ! V_97 ) {
F_23 ( & V_6 -> V_65 ) ;
return;
}
F_21 ( & V_97 -> V_66 ) ;
F_23 ( & V_6 -> V_65 ) ;
V_97 -> V_67 . V_68 . V_98 = F_46 () ;
V_97 -> V_67 . V_75 = V_6 -> V_75 ++ ;
V_97 -> V_67 . V_36 = V_6 -> V_18 . V_36 ;
V_63 = F_47 ( & V_97 -> V_67 . V_68 , 0 ) ;
memcpy ( V_63 , V_96 , V_6 -> V_18 . V_35 ) ;
F_48 ( & V_97 -> V_67 . V_68 , 0 ,
V_6 -> V_18 . V_35 ) ;
F_22 ( & V_97 -> V_67 . V_68 , V_99 ) ;
}
static int F_49 ( struct V_85 * V_89 , struct V_85 * V_90 ,
void * V_91 )
{
struct V_100 * V_12 = V_91 ;
struct V_101 * V_102 = V_89 -> V_103 ;
const struct V_22 * V_23 ;
struct V_5 * V_6 ;
struct V_104 * V_11 ;
struct V_69 * V_105 ;
int V_74 ;
V_6 = F_50 ( sizeof( * V_6 ) , V_106 ) ;
if ( ! V_6 )
return - V_107 ;
V_6 -> V_15 . V_93 =
F_51 ( 1 , (const unsigned long[1]) {MEDIA_PAD_FL_SINK}) ;
if ( F_52 ( V_6 -> V_15 . V_93 ) ) {
V_74 = F_53 ( V_6 -> V_15 . V_93 ) ;
goto V_108;
}
V_6 -> V_11 . V_73 . V_13 = V_102 -> V_109 ;
V_6 -> V_11 . V_73 . V_110 = V_111 ;
V_74 = F_54 ( & V_6 -> V_11 . V_73 ,
1 , V_6 -> V_15 . V_93 ) ;
if ( V_74 )
goto V_112;
F_55 ( & V_6 -> V_113 ) ;
V_105 = & V_6 -> V_38 ;
V_105 -> type = V_114 ;
V_105 -> V_115 = V_116 | V_117 ;
V_105 -> V_118 = V_6 ;
V_105 -> V_119 = sizeof( struct V_62 ) ;
V_105 -> V_120 = & V_121 ;
V_105 -> V_122 = & V_123 ;
V_105 -> V_124 = V_125 ;
V_105 -> V_126 = 2 ;
V_105 -> V_113 = & V_6 -> V_113 ;
V_74 = F_56 ( V_105 ) ;
if ( V_74 ) {
F_35 ( V_89 , L_6 ,
V_102 -> V_109 , V_74 ) ;
goto V_127;
}
F_57 ( & V_6 -> V_81 ) ;
F_58 ( & V_6 -> V_65 ) ;
V_6 -> V_18 = V_32 ;
V_23 = F_9 ( V_6 -> V_18 . V_31 ) ;
V_6 -> V_18 . V_33 = V_6 -> V_18 . V_24 * V_23 -> V_34 ;
V_6 -> V_18 . V_35 = V_6 -> V_18 . V_33 *
V_6 -> V_18 . V_28 ;
V_6 -> V_15 . V_92 = & V_6 -> V_11 . V_73 ;
V_6 -> V_15 . V_128 = F_43 ;
V_6 -> V_15 . V_129 = F_4 ;
F_59 ( V_89 , & V_6 -> V_15 ) ;
V_6 -> V_40 = V_89 ;
V_11 = & V_6 -> V_11 ;
V_11 -> V_130 = V_131 | V_132 ;
V_11 -> V_73 . V_120 = & V_133 ;
V_11 -> V_134 = V_135 ;
V_11 -> V_136 = & V_137 ;
V_11 -> V_138 = & V_139 ;
V_11 -> V_113 = & V_6 -> V_113 ;
V_11 -> V_38 = V_105 ;
V_11 -> V_12 = V_12 ;
V_11 -> V_140 = V_141 ;
F_3 ( V_11 -> V_13 , V_102 -> V_109 , sizeof( V_11 -> V_13 ) ) ;
F_60 ( V_11 , & V_6 -> V_15 ) ;
V_74 = F_61 ( V_11 , V_142 , - 1 ) ;
if ( V_74 ) {
F_35 ( V_89 , L_7 ,
V_6 -> V_11 . V_13 , V_74 ) ;
goto V_143;
}
return 0 ;
V_143:
F_38 ( V_105 ) ;
V_127:
F_39 ( & V_6 -> V_11 . V_73 ) ;
V_112:
F_41 ( V_6 -> V_15 . V_93 ) ;
V_108:
F_42 ( V_6 ) ;
return V_74 ;
}
static int F_62 ( struct V_144 * V_145 )
{
return F_63 ( & V_145 -> V_40 , & V_146 ) ;
}
static int F_64 ( struct V_144 * V_145 )
{
F_65 ( & V_145 -> V_40 , & V_146 ) ;
return 0 ;
}
