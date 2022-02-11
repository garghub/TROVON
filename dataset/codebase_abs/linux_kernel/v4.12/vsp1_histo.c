static inline struct V_1 *
F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
struct V_1 *
F_3 ( struct V_5 * V_6 )
{
struct V_1 * V_4 = NULL ;
unsigned long V_7 ;
F_4 ( & V_6 -> V_8 , V_7 ) ;
if ( F_5 ( & V_6 -> V_9 ) )
goto V_10;
V_4 = F_6 ( & V_6 -> V_9 , struct V_1 ,
V_11 ) ;
F_7 ( & V_4 -> V_11 ) ;
V_6 -> V_12 = true ;
V_10:
F_8 ( & V_6 -> V_8 , V_7 ) ;
return V_4 ;
}
void F_9 ( struct V_5 * V_6 ,
struct V_1 * V_4 ,
T_1 V_13 )
{
struct V_14 * V_15 = V_6 -> V_15 ;
unsigned long V_7 ;
V_4 -> V_4 . V_16 = V_15 -> V_16 ;
V_4 -> V_4 . V_17 . V_18 = F_10 () ;
F_11 ( & V_4 -> V_4 . V_17 , 0 , V_13 ) ;
F_12 ( & V_4 -> V_4 . V_17 , V_19 ) ;
F_4 ( & V_6 -> V_8 , V_7 ) ;
V_6 -> V_12 = false ;
F_13 ( & V_6 -> V_20 ) ;
F_8 ( & V_6 -> V_8 , V_7 ) ;
}
static int F_14 ( struct V_21 * V_22 , unsigned int * V_23 ,
unsigned int * V_24 , unsigned int V_25 [] ,
struct V_26 * V_27 [] )
{
struct V_5 * V_6 = F_15 ( V_22 ) ;
if ( * V_24 ) {
if ( * V_24 != 1 )
return - V_28 ;
if ( V_25 [ 0 ] < V_6 -> V_29 )
return - V_28 ;
return 0 ;
}
* V_24 = 1 ;
V_25 [ 0 ] = V_6 -> V_29 ;
return 0 ;
}
static int F_16 ( struct V_30 * V_31 )
{
struct V_2 * V_3 = F_17 ( V_31 ) ;
struct V_5 * V_6 = F_15 ( V_31 -> V_21 ) ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
if ( V_31 -> V_32 != 1 )
return - V_28 ;
if ( F_18 ( V_31 , 0 ) < V_6 -> V_29 )
return - V_28 ;
V_4 -> V_33 = F_19 ( V_31 , 0 ) ;
return 0 ;
}
static void F_20 ( struct V_30 * V_31 )
{
struct V_2 * V_3 = F_17 ( V_31 ) ;
struct V_5 * V_6 = F_15 ( V_31 -> V_21 ) ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
unsigned long V_7 ;
F_4 ( & V_6 -> V_8 , V_7 ) ;
F_21 ( & V_4 -> V_11 , & V_6 -> V_9 ) ;
F_8 ( & V_6 -> V_8 , V_7 ) ;
}
static int F_22 ( struct V_21 * V_22 , unsigned int V_34 )
{
return 0 ;
}
static void F_23 ( struct V_21 * V_22 )
{
struct V_5 * V_6 = F_15 ( V_22 ) ;
struct V_1 * V_35 ;
unsigned long V_7 ;
F_4 ( & V_6 -> V_8 , V_7 ) ;
F_24 (buffer, &histo->irqqueue, queue)
F_12 ( & V_35 -> V_4 . V_17 , V_36 ) ;
F_25 ( & V_6 -> V_9 ) ;
F_26 ( V_6 -> V_20 , ! V_6 -> V_12 , V_6 -> V_8 ) ;
F_8 ( & V_6 -> V_8 , V_7 ) ;
}
static int F_27 ( struct V_37 * V_38 ,
struct V_39 * V_40 ,
struct V_41 * V_42 )
{
struct V_5 * V_6 = F_28 ( V_38 ) ;
if ( V_42 -> V_43 == V_44 ) {
V_42 -> V_42 = V_45 ;
return 0 ;
}
return F_29 ( V_38 , V_40 , V_42 , V_6 -> V_46 ,
V_6 -> V_47 ) ;
}
static int F_30 ( struct V_37 * V_38 ,
struct V_39 * V_40 ,
struct V_48 * V_49 )
{
if ( V_49 -> V_43 != V_50 )
return - V_28 ;
return F_31 ( V_38 , V_40 , V_49 , V_51 ,
V_51 , V_52 ,
V_52 ) ;
}
static int F_32 ( struct V_37 * V_38 ,
struct V_39 * V_40 ,
struct V_53 * V_54 )
{
struct V_5 * V_6 = F_28 ( V_38 ) ;
struct V_39 * V_55 ;
struct V_56 * V_57 ;
struct V_58 * V_59 ;
int V_60 = 0 ;
if ( V_54 -> V_43 != V_50 )
return - V_28 ;
F_33 ( & V_6 -> V_61 . V_62 ) ;
V_55 = F_34 ( & V_6 -> V_61 , V_40 , V_54 -> V_63 ) ;
if ( ! V_55 ) {
V_60 = - V_28 ;
goto V_10;
}
switch ( V_54 -> V_64 ) {
case V_65 :
case V_66 :
V_59 = F_35 ( & V_6 -> V_61 , V_55 ,
V_50 ,
V_67 ) ;
V_54 -> V_68 . V_69 = 0 ;
V_54 -> V_68 . V_70 = 0 ;
V_54 -> V_68 . V_71 = V_59 -> V_71 ;
V_54 -> V_68 . V_72 = V_59 -> V_72 ;
break;
case V_73 :
case V_74 :
V_57 = F_36 ( & V_6 -> V_61 , V_55 ,
V_50 ) ;
V_54 -> V_68 . V_69 = 0 ;
V_54 -> V_68 . V_70 = 0 ;
V_54 -> V_68 . V_71 = V_57 -> V_71 ;
V_54 -> V_68 . V_72 = V_57 -> V_72 ;
break;
case V_75 :
case V_67 :
V_54 -> V_68 = * F_35 ( & V_6 -> V_61 , V_55 ,
V_54 -> V_43 , V_54 -> V_64 ) ;
break;
default:
V_60 = - V_28 ;
break;
}
V_10:
F_37 ( & V_6 -> V_61 . V_62 ) ;
return V_60 ;
}
static int F_38 ( struct V_37 * V_38 ,
struct V_39 * V_55 ,
struct V_53 * V_54 )
{
struct V_5 * V_6 = F_28 ( V_38 ) ;
struct V_56 * V_57 ;
struct V_58 * V_76 ;
V_57 = F_36 ( & V_6 -> V_61 , V_55 ,
V_50 ) ;
V_54 -> V_68 . V_69 = F_39 (unsigned int, sel->r.left, 0 , format->width - 1 ) ;
V_54 -> V_68 . V_70 = F_39 (unsigned int, sel->r.top, 0 , format->height - 1 ) ;
V_54 -> V_68 . V_71 = F_39 (unsigned int, sel->r.width, HISTO_MIN_SIZE,
format->width - sel->r.left) ;
V_54 -> V_68 . V_72 = F_39 (unsigned int, sel->r.height, HISTO_MIN_SIZE,
format->height - sel->r.top) ;
V_76 = F_35 ( & V_6 -> V_61 , V_55 ,
V_54 -> V_43 , V_67 ) ;
* V_76 = V_54 -> V_68 ;
V_76 = F_35 ( & V_6 -> V_61 , V_55 ,
V_54 -> V_43 ,
V_75 ) ;
* V_76 = V_54 -> V_68 ;
return 0 ;
}
static int F_40 ( struct V_37 * V_38 ,
struct V_39 * V_55 ,
struct V_53 * V_54 )
{
struct V_5 * V_6 = F_28 ( V_38 ) ;
struct V_58 * V_77 ;
struct V_58 * V_59 ;
unsigned int V_78 ;
V_54 -> V_68 . V_69 = 0 ;
V_54 -> V_68 . V_70 = 0 ;
V_59 = F_35 ( & V_6 -> V_61 , V_55 , V_54 -> V_43 ,
V_67 ) ;
V_54 -> V_68 . V_71 = F_41 ( V_54 -> V_68 . V_71 , V_59 -> V_71 / 4 , V_59 -> V_71 ) ;
V_78 = 1 << ( V_59 -> V_71 * 2 / V_54 -> V_68 . V_71 / 3 ) ;
V_54 -> V_68 . V_71 = V_59 -> V_71 / V_78 ;
V_54 -> V_68 . V_72 = F_41 ( V_54 -> V_68 . V_72 , V_59 -> V_72 / 4 , V_59 -> V_72 ) ;
V_78 = 1 << ( V_59 -> V_72 * 2 / V_54 -> V_68 . V_72 / 3 ) ;
V_54 -> V_68 . V_72 = V_59 -> V_72 / V_78 ;
V_77 = F_35 ( & V_6 -> V_61 , V_55 ,
V_54 -> V_43 ,
V_75 ) ;
* V_77 = V_54 -> V_68 ;
return 0 ;
}
static int F_42 ( struct V_37 * V_38 ,
struct V_39 * V_40 ,
struct V_53 * V_54 )
{
struct V_5 * V_6 = F_28 ( V_38 ) ;
struct V_39 * V_55 ;
int V_60 ;
if ( V_54 -> V_43 != V_50 )
return - V_28 ;
F_33 ( & V_6 -> V_61 . V_62 ) ;
V_55 = F_34 ( & V_6 -> V_61 , V_40 , V_54 -> V_63 ) ;
if ( ! V_55 ) {
V_60 = - V_28 ;
goto V_10;
}
if ( V_54 -> V_64 == V_67 )
V_60 = F_38 ( V_38 , V_55 , V_54 ) ;
else if ( V_54 -> V_64 == V_75 )
V_60 = F_40 ( V_38 , V_55 , V_54 ) ;
else
V_60 = - V_28 ;
V_10:
F_37 ( & V_6 -> V_61 . V_62 ) ;
return V_60 ;
}
static int F_43 ( struct V_37 * V_38 ,
struct V_39 * V_40 ,
struct V_79 * V_80 )
{
if ( V_80 -> V_43 == V_44 ) {
V_80 -> V_57 . V_42 = V_45 ;
V_80 -> V_57 . V_71 = 0 ;
V_80 -> V_57 . V_72 = 0 ;
V_80 -> V_57 . V_81 = V_82 ;
V_80 -> V_57 . V_83 = V_84 ;
return 0 ;
}
return F_44 ( V_38 , V_40 , V_80 ) ;
}
static int F_45 ( struct V_37 * V_38 ,
struct V_39 * V_40 ,
struct V_79 * V_80 )
{
struct V_5 * V_6 = F_28 ( V_38 ) ;
struct V_39 * V_55 ;
struct V_56 * V_57 ;
struct V_58 * V_76 ;
unsigned int V_85 ;
int V_60 = 0 ;
if ( V_80 -> V_43 != V_50 )
return F_43 ( V_38 , V_40 , V_80 ) ;
F_33 ( & V_6 -> V_61 . V_62 ) ;
V_55 = F_34 ( & V_6 -> V_61 , V_40 , V_80 -> V_63 ) ;
if ( ! V_55 ) {
V_60 = - V_28 ;
goto V_10;
}
for ( V_85 = 0 ; V_85 < V_6 -> V_47 ; ++ V_85 ) {
if ( V_80 -> V_57 . V_42 == V_6 -> V_46 [ V_85 ] )
break;
}
if ( V_85 == V_6 -> V_47 )
V_80 -> V_57 . V_42 = V_6 -> V_46 [ 0 ] ;
V_57 = F_36 ( & V_6 -> V_61 , V_55 , V_80 -> V_43 ) ;
V_57 -> V_42 = V_80 -> V_57 . V_42 ;
V_57 -> V_71 = F_39 (unsigned int, fmt->format.width,
HISTO_MIN_SIZE, HISTO_MAX_SIZE) ;
V_57 -> V_72 = F_39 (unsigned int, fmt->format.height,
HISTO_MIN_SIZE, HISTO_MAX_SIZE) ;
V_57 -> V_81 = V_82 ;
V_57 -> V_83 = V_86 ;
V_80 -> V_57 = * V_57 ;
V_76 = F_35 ( & V_6 -> V_61 , V_55 ,
V_80 -> V_43 , V_67 ) ;
V_76 -> V_69 = 0 ;
V_76 -> V_70 = 0 ;
V_76 -> V_71 = V_57 -> V_71 ;
V_76 -> V_72 = V_57 -> V_72 ;
V_76 = F_35 ( & V_6 -> V_61 , V_55 ,
V_80 -> V_43 ,
V_75 ) ;
V_76 -> V_69 = 0 ;
V_76 -> V_70 = 0 ;
V_76 -> V_71 = V_57 -> V_71 ;
V_76 -> V_72 = V_57 -> V_72 ;
V_10:
F_37 ( & V_6 -> V_61 . V_62 ) ;
return V_60 ;
}
static int F_46 ( struct V_87 * V_87 , void * V_88 ,
struct V_89 * V_90 )
{
struct V_91 * V_92 = V_87 -> V_93 ;
struct V_5 * V_6 = F_47 ( V_92 -> V_94 ) ;
V_90 -> V_95 = V_96 | V_97
| V_98
| V_99
| V_100 ;
V_90 -> V_101 = V_100
| V_97 ;
F_48 ( V_90 -> V_102 , L_1 , sizeof( V_90 -> V_102 ) ) ;
F_48 ( V_90 -> V_103 , V_6 -> V_104 . V_105 , sizeof( V_90 -> V_103 ) ) ;
snprintf ( V_90 -> V_106 , sizeof( V_90 -> V_106 ) , L_2 ,
F_49 ( V_6 -> V_61 . V_107 -> V_108 ) ) ;
return 0 ;
}
static int F_50 ( struct V_87 * V_87 , void * V_88 ,
struct V_109 * V_110 )
{
struct V_91 * V_92 = V_87 -> V_93 ;
struct V_5 * V_6 = F_47 ( V_92 -> V_94 ) ;
if ( V_110 -> V_111 > 0 || V_110 -> type != V_6 -> V_11 . type )
return - V_28 ;
V_110 -> V_112 = V_6 -> V_113 ;
return 0 ;
}
static int F_51 ( struct V_87 * V_87 , void * V_88 ,
struct V_114 * V_57 )
{
struct V_91 * V_92 = V_87 -> V_93 ;
struct V_5 * V_6 = F_47 ( V_92 -> V_94 ) ;
struct V_115 * V_116 = & V_57 -> V_80 . V_116 ;
if ( V_57 -> type != V_6 -> V_11 . type )
return - V_28 ;
memset ( V_116 , 0 , sizeof( * V_116 ) ) ;
V_116 -> V_117 = V_6 -> V_113 ;
V_116 -> V_118 = V_6 -> V_29 ;
return 0 ;
}
static void F_52 ( struct V_5 * V_6 )
{
if ( F_53 ( & V_6 -> V_104 ) )
F_54 ( & V_6 -> V_104 ) ;
F_55 ( & V_6 -> V_104 . V_61 ) ;
}
void F_56 ( struct V_119 * V_61 )
{
struct V_5 * V_6 = F_28 ( & V_61 -> V_38 ) ;
F_52 ( V_6 ) ;
}
int F_57 ( struct V_120 * V_107 , struct V_5 * V_6 ,
enum V_121 type , const char * V_105 ,
const struct V_122 * V_123 ,
const unsigned int * V_46 , unsigned int V_47 ,
T_1 V_29 , T_2 V_113 )
{
int V_60 ;
V_6 -> V_46 = V_46 ;
V_6 -> V_47 = V_47 ;
V_6 -> V_29 = V_29 ;
V_6 -> V_113 = V_113 ;
V_6 -> V_43 . V_7 = V_124 ;
V_6 -> V_104 . V_125 = V_126 ;
F_58 ( & V_6 -> V_62 ) ;
F_59 ( & V_6 -> V_8 ) ;
F_25 ( & V_6 -> V_9 ) ;
F_60 ( & V_6 -> V_20 ) ;
V_6 -> V_61 . V_123 = V_123 ;
V_6 -> V_61 . type = type ;
V_60 = F_61 ( V_107 , & V_6 -> V_61 , V_105 , 2 , & V_127 ,
V_128 ) ;
if ( V_60 < 0 )
return V_60 ;
V_60 = F_62 ( & V_6 -> V_104 . V_61 , 1 , & V_6 -> V_43 ) ;
if ( V_60 < 0 )
return V_60 ;
V_6 -> V_104 . V_129 = & V_107 -> V_129 ;
V_6 -> V_104 . V_130 = & V_131 ;
snprintf ( V_6 -> V_104 . V_105 , sizeof( V_6 -> V_104 . V_105 ) ,
L_3 , V_6 -> V_61 . V_38 . V_105 ) ;
V_6 -> V_104 . V_132 = V_133 ;
V_6 -> V_104 . V_134 = V_135 ;
V_6 -> V_104 . V_136 = & V_137 ;
F_63 ( & V_6 -> V_104 , V_6 ) ;
V_6 -> V_11 . type = V_138 ;
V_6 -> V_11 . V_139 = V_140 | V_141 | V_142 ;
V_6 -> V_11 . V_62 = & V_6 -> V_62 ;
V_6 -> V_11 . V_143 = V_6 ;
V_6 -> V_11 . V_144 = sizeof( struct V_1 ) ;
V_6 -> V_11 . V_123 = & V_145 ;
V_6 -> V_11 . V_146 = & V_147 ;
V_6 -> V_11 . V_148 = V_149 ;
V_6 -> V_11 . V_108 = V_107 -> V_108 ;
V_60 = F_64 ( & V_6 -> V_11 ) ;
if ( V_60 < 0 ) {
F_65 ( V_107 -> V_108 , L_4 ) ;
goto error;
}
V_6 -> V_104 . V_11 = & V_6 -> V_11 ;
V_60 = F_66 ( & V_6 -> V_104 , V_133 , - 1 ) ;
if ( V_60 < 0 ) {
F_65 ( V_107 -> V_108 , L_5 ) ;
goto error;
}
return 0 ;
error:
F_52 ( V_6 ) ;
return V_60 ;
}
