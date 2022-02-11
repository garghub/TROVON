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
static int F_4 ( struct V_1 * V_1 , void * V_2 ,
struct V_14 * V_15 )
{
struct V_5 * V_6 = F_2 ( V_1 ) ;
V_15 -> V_16 . V_17 = V_6 -> V_18 ;
return 0 ;
}
static int F_5 ( struct V_1 * V_1 , void * V_2 ,
struct V_19 * V_15 )
{
struct V_5 * V_6 = F_2 ( V_1 ) ;
if ( V_15 -> V_20 > 0 )
return - V_21 ;
V_15 -> V_22 = V_6 -> V_18 . V_22 ;
return 0 ;
}
static void F_6 ( struct V_5 * V_6 ,
enum V_23 V_24 )
{
struct V_25 * V_26 , * V_27 ;
F_7 ( & V_6 -> V_28 ) ;
F_8 (vbuf, node, &vcap->buf_list, list) {
F_9 ( & V_26 -> V_29 ) ;
F_10 ( & V_26 -> V_30 . V_31 , V_24 ) ;
}
F_11 ( & V_6 -> V_28 ) ;
}
static int F_12 ( struct V_5 * V_6 , int V_32 )
{
struct V_33 * V_34 ;
struct V_35 * V_36 ;
int V_37 ;
V_36 = F_13 ( & V_6 -> V_11 . V_38 . V_39 [ 0 ] ) ;
if ( V_36 -> V_38 -> V_40 == V_41 )
return 0 ;
V_34 = F_14 ( V_36 -> V_38 ) ;
V_37 = F_15 ( V_34 , V_42 , V_43 , V_32 ) ;
if ( V_37 && V_37 != - V_44 )
return V_37 ;
return 0 ;
}
static int F_16 ( struct V_45 * V_46 , unsigned int V_47 )
{
struct V_5 * V_6 = F_17 ( V_46 ) ;
struct V_48 * V_38 = & V_6 -> V_11 . V_38 ;
int V_37 ;
V_6 -> V_49 = 0 ;
V_37 = F_18 ( V_38 , & V_6 -> V_50 ) ;
if ( V_37 ) {
F_6 ( V_6 , V_51 ) ;
return V_37 ;
}
V_37 = F_12 ( V_6 , 1 ) ;
if ( V_37 ) {
F_19 ( V_38 ) ;
F_6 ( V_6 , V_51 ) ;
return V_37 ;
}
return 0 ;
}
static void F_20 ( struct V_45 * V_46 )
{
struct V_5 * V_6 = F_17 ( V_46 ) ;
F_12 ( V_6 , 0 ) ;
F_19 ( & V_6 -> V_11 . V_38 ) ;
F_6 ( V_6 , V_52 ) ;
}
static void F_21 ( struct V_53 * V_31 )
{
struct V_5 * V_6 = F_17 ( V_31 -> V_45 ) ;
struct V_25 * V_54 = F_22 ( V_31 ,
struct V_25 ,
V_30 . V_31 ) ;
F_7 ( & V_6 -> V_28 ) ;
F_23 ( & V_54 -> V_29 , & V_6 -> V_55 ) ;
F_11 ( & V_6 -> V_28 ) ;
}
static int F_24 ( struct V_45 * V_46 , unsigned int * V_56 ,
unsigned int * V_57 , unsigned int V_58 [] ,
struct V_59 * V_60 [] )
{
struct V_5 * V_6 = F_17 ( V_46 ) ;
if ( * V_57 )
return V_58 [ 0 ] < V_6 -> V_18 . V_61 ? - V_21 : 0 ;
* V_57 = 1 ;
V_58 [ 0 ] = V_6 -> V_18 . V_61 ;
return 0 ;
}
static int F_25 ( struct V_53 * V_62 )
{
struct V_5 * V_6 = F_17 ( V_62 -> V_45 ) ;
unsigned long V_63 = V_6 -> V_18 . V_61 ;
if ( F_26 ( V_62 , 0 ) < V_63 ) {
F_27 ( V_6 -> V_11 . V_12 -> V_64 ,
L_2 ,
V_6 -> V_11 . V_13 , F_26 ( V_62 , 0 ) , V_63 ) ;
return - V_21 ;
}
return 0 ;
}
static int F_28 ( struct V_35 * V_36 ,
struct V_65 * V_16 )
{
struct V_33 * V_34 = F_14 ( V_36 -> V_38 ) ;
V_16 -> V_66 = V_67 ;
V_16 -> V_36 = V_36 -> V_20 ;
return F_15 ( V_34 , V_36 , V_68 , NULL , V_16 ) ;
}
static int F_29 ( struct V_69 * V_70 )
{
struct V_65 V_71 ;
const struct V_72 * V_73 ;
struct V_5 * V_6 = F_22 ( V_70 -> V_74 -> V_38 ,
struct V_5 ,
V_11 . V_38 ) ;
struct V_75 * V_76 = & V_6 -> V_18 ;
int V_37 ;
if ( V_70 -> V_77 -> V_38 -> V_40 == V_41 )
return 0 ;
V_37 = F_28 ( V_70 -> V_77 ,
& V_71 ) ;
if ( V_37 )
return V_37 ;
F_30 ( V_6 -> V_11 . V_12 -> V_64 ,
L_3 ,
V_6 -> V_11 . V_13 ,
V_71 . V_18 . V_78 , V_71 . V_18 . V_79 ,
V_71 . V_18 . V_80 ,
V_76 -> V_78 , V_76 -> V_79 ,
V_76 -> V_22 ) ;
V_73 = F_31 ( V_76 -> V_22 ) ;
if ( V_71 . V_18 . V_78 != V_76 -> V_78
|| V_71 . V_18 . V_79 != V_76 -> V_79
|| V_73 -> V_80 != V_71 . V_18 . V_80 )
return - V_81 ;
if ( V_71 . V_18 . V_82 != V_76 -> V_82 &&
V_76 -> V_82 != V_83 )
return - V_81 ;
return 0 ;
}
static void F_32 ( struct V_84 * V_85 )
{
struct V_5 * V_6 = F_22 ( V_85 , struct V_5 ,
V_85 ) ;
F_33 ( & V_6 -> V_86 ) ;
F_34 ( V_85 -> V_87 ) ;
F_35 ( & V_6 -> V_11 ) ;
F_36 ( V_6 -> V_85 . V_39 ) ;
F_37 ( V_6 ) ;
}
static void F_38 ( struct V_84 * V_85 ,
struct V_35 * V_74 , const void * V_88 )
{
struct V_5 * V_6 = F_22 ( V_85 , struct V_5 ,
V_85 ) ;
struct V_25 * V_89 ;
void * V_26 ;
F_7 ( & V_6 -> V_28 ) ;
V_89 = F_39 ( & V_6 -> V_55 ,
F_40 ( * V_89 ) , V_29 ) ;
if ( ! V_89 ) {
F_11 ( & V_6 -> V_28 ) ;
return;
}
F_9 ( & V_89 -> V_29 ) ;
F_11 ( & V_6 -> V_28 ) ;
V_89 -> V_30 . V_31 . V_90 = F_41 () ;
V_89 -> V_30 . V_49 = V_6 -> V_49 ++ ;
V_89 -> V_30 . V_82 = V_6 -> V_18 . V_82 ;
V_26 = F_42 ( & V_89 -> V_30 . V_31 , 0 ) ;
memcpy ( V_26 , V_88 , V_6 -> V_18 . V_61 ) ;
F_43 ( & V_89 -> V_30 . V_31 , 0 ,
V_6 -> V_18 . V_61 ) ;
F_10 ( & V_89 -> V_30 . V_31 , V_91 ) ;
}
struct V_84 * F_44 ( struct V_92 * V_12 ,
const char * const V_13 ,
T_1 V_93 ,
const unsigned long * V_94 )
{
const struct V_72 * V_73 ;
struct V_5 * V_6 ;
struct V_95 * V_11 ;
struct V_45 * V_96 ;
int V_37 ;
if ( ! V_13 || V_93 != 1 || ! V_94 ||
! ( V_94 [ 0 ] & V_97 ) )
return F_45 ( - V_21 ) ;
V_6 = F_46 ( sizeof( * V_6 ) , V_98 ) ;
if ( ! V_6 )
return F_45 ( - V_99 ) ;
V_6 -> V_85 . V_39 = F_47 ( V_93 , V_94 ) ;
if ( F_48 ( V_6 -> V_85 . V_39 ) ) {
V_37 = F_49 ( V_6 -> V_85 . V_39 ) ;
goto V_100;
}
V_6 -> V_11 . V_38 . V_13 = V_13 ;
V_6 -> V_11 . V_38 . V_101 = V_102 ;
V_37 = F_50 ( & V_6 -> V_11 . V_38 ,
V_93 , V_6 -> V_85 . V_39 ) ;
if ( V_37 )
goto V_103;
F_51 ( & V_6 -> V_104 ) ;
V_96 = & V_6 -> V_86 ;
V_96 -> type = V_105 ;
V_96 -> V_106 = V_107 | V_108 ;
V_96 -> V_109 = V_6 ;
V_96 -> V_110 = sizeof( struct V_25 ) ;
V_96 -> V_111 = & V_112 ;
V_96 -> V_113 = & V_114 ;
V_96 -> V_115 = V_116 ;
V_96 -> V_117 = 2 ;
V_96 -> V_104 = & V_6 -> V_104 ;
V_37 = F_52 ( V_96 ) ;
if ( V_37 ) {
F_27 ( V_6 -> V_11 . V_12 -> V_64 ,
L_4 ,
V_6 -> V_11 . V_13 , V_37 ) ;
goto V_118;
}
F_53 ( & V_6 -> V_55 ) ;
F_54 ( & V_6 -> V_28 ) ;
V_6 -> V_18 . V_78 = 640 ;
V_6 -> V_18 . V_79 = 480 ;
V_6 -> V_18 . V_22 = V_119 ;
V_6 -> V_18 . V_82 = V_83 ;
V_6 -> V_18 . V_120 = V_121 ;
V_73 = F_31 ( V_6 -> V_18 . V_22 ) ;
V_6 -> V_18 . V_122 = V_6 -> V_18 . V_78 * V_73 -> V_123 ;
V_6 -> V_18 . V_61 = V_6 -> V_18 . V_122 *
V_6 -> V_18 . V_79 ;
V_6 -> V_85 . V_124 = F_32 ;
V_6 -> V_85 . V_87 = & V_6 -> V_11 . V_38 ;
V_6 -> V_85 . V_125 = F_38 ;
V_11 = & V_6 -> V_11 ;
V_11 -> V_126 = V_127 | V_128 ;
V_11 -> V_38 . V_111 = & V_129 ;
V_11 -> V_130 = V_131 ;
V_11 -> V_132 = & V_133 ;
V_11 -> V_134 = & V_135 ;
V_11 -> V_104 = & V_6 -> V_104 ;
V_11 -> V_86 = V_96 ;
V_11 -> V_12 = V_12 ;
V_11 -> V_136 = V_137 ;
F_3 ( V_11 -> V_13 , V_13 , sizeof( V_11 -> V_13 ) ) ;
F_55 ( V_11 , & V_6 -> V_85 ) ;
V_37 = F_56 ( V_11 , V_138 , - 1 ) ;
if ( V_37 ) {
F_27 ( V_6 -> V_11 . V_12 -> V_64 ,
L_5 ,
V_6 -> V_11 . V_13 , V_37 ) ;
goto V_139;
}
return & V_6 -> V_85 ;
V_139:
F_33 ( V_96 ) ;
V_118:
F_34 ( & V_6 -> V_11 . V_38 ) ;
V_103:
F_36 ( V_6 -> V_85 . V_39 ) ;
V_100:
F_37 ( V_6 ) ;
return F_45 ( V_37 ) ;
}
