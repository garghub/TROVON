static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return V_3 -> V_4 ;
}
static int F_2 ( struct V_5 * V_6 , struct V_1 * V_1 , T_1 V_7 )
{
if ( V_1 -> V_8 == V_9 )
F_3 ( V_6 ) -> V_10 = F_4 ( F_5 ( F_3 ( V_6 ) -> V_10 ) - V_7 ) ;
else
F_6 ( V_6 ) -> V_11 =
F_4 ( F_5 ( F_6 ( V_6 ) -> V_11 ) - V_7 ) ;
F_7 ( V_6 , V_7 ) ;
F_8 ( V_6 , F_9 ( V_6 ) , V_7 ) ;
F_10 ( V_6 ) ;
return F_11 ( V_6 ) ;
}
static int F_12 ( struct V_2 * V_3 , struct V_5 * V_6 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
if ( ! V_1 )
return 1 ;
if ( F_2 ( V_6 , V_1 , sizeof( struct V_12 ) ) )
goto V_13;
return - V_1 -> V_14 ;
V_13:
F_13 ( V_6 ) ;
return 0 ;
}
static struct V_15 * F_14 ( struct V_5 * V_6 , struct V_15 * V_15 ,
void * V_16 , T_1 V_17 , T_2 V_18 ,
bool V_19 )
{
T_3 * V_20 = V_16 ;
T_1 V_21 = F_5 ( V_20 [ 0 ] ) ;
T_1 V_22 = F_5 ( V_20 [ 1 ] ) ;
T_1 V_23 = sizeof( struct V_12 ) + V_17 +
F_15 ( T_1 , V_22 + sizeof( V_24 ) , V_21 ) ;
if ( V_6 -> V_25 )
return V_15 ;
if ( ! F_16 ( V_6 , V_23 ) )
return NULL ;
V_15 = (struct V_15 * ) & F_9 ( V_6 ) [ 1 ] ;
F_17 ( V_6 , ( void * ) V_15 + V_17 ,
V_21 , V_22 , V_19 ) ;
return V_15 ;
}
static int F_18 ( struct V_5 * V_6 , struct V_15 * V_15 )
{
F_13 ( V_6 ) ;
return 0 ;
}
static int F_19 ( struct V_2 * V_3 , struct V_5 * V_6 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
T_1 V_7 , V_26 , V_17 ;
struct V_15 * V_15 ;
void * V_16 ;
V_24 V_27 = 0 ;
if ( ! V_1 )
return 1 ;
V_7 = sizeof( struct V_12 ) + sizeof( struct V_15 ) ;
if ( ! F_16 ( V_6 , V_7 ) )
goto V_13;
V_15 = (struct V_15 * ) & F_9 ( V_6 ) [ 1 ] ;
V_26 = V_15 -> V_28 << 2 ;
V_7 += V_26 ;
if ( ! F_16 ( V_6 , V_7 ) )
goto V_13;
V_15 = (struct V_15 * ) & F_9 ( V_6 ) [ 1 ] ;
V_17 = sizeof( struct V_15 ) + V_26 ;
if ( V_15 -> V_29 != 0 || F_20 ( V_15 , V_26 ) )
goto V_13;
V_17 = sizeof( struct V_15 ) + V_26 ;
if ( V_1 -> V_8 == V_9 )
F_3 ( V_6 ) -> V_10 = F_4 ( F_5 ( F_3 ( V_6 ) -> V_10 ) - V_7 ) ;
else
F_6 ( V_6 ) -> V_11 =
F_4 ( F_5 ( F_6 ( V_6 ) -> V_11 ) - V_7 ) ;
F_8 ( V_6 , F_9 ( V_6 ) , V_7 ) ;
V_16 = & V_15 [ 1 ] ;
if ( V_15 -> V_30 & V_31 ) {
T_4 V_30 = * ( T_4 * ) ( V_16 + V_27 ) ;
V_27 += V_32 ;
if ( V_30 & V_33 ) {
V_15 = F_14 ( V_6 , V_15 , V_16 + V_27 ,
V_17 , V_15 -> V_34 ,
! ! ( V_1 -> V_30 &
V_35 ) ) ;
if ( ! V_15 )
goto V_13;
V_16 = & V_15 [ 1 ] ;
V_27 += V_36 ;
}
}
if ( F_21 ( V_15 -> V_37 ) )
return F_18 ( V_6 , V_15 ) ;
F_7 ( V_6 , sizeof( struct V_12 ) + V_17 ) ;
F_10 ( V_6 ) ;
if ( F_11 ( V_6 ) )
goto V_13;
return - V_15 -> V_34 ;
V_13:
F_13 ( V_6 ) ;
return 0 ;
}
static struct V_5 * * F_22 ( struct V_2 * V_3 ,
struct V_5 * * V_38 ,
struct V_5 * V_6 )
{
const struct V_39 * V_40 ;
struct V_5 * * V_41 = NULL ;
T_2 V_42 = F_1 ( V_3 ) -> V_14 ;
const struct V_39 * * V_43 ;
F_23 ( V_6 ) -> V_44 = 0 ;
F_23 ( V_6 ) -> V_45 = 1 ;
F_24 () ;
V_43 = F_23 ( V_6 ) -> V_46 ? V_47 : V_48 ;
V_40 = F_25 ( V_43 [ V_42 ] ) ;
if ( ! V_40 || ! V_40 -> V_49 . V_50 )
goto V_51;
V_41 = V_40 -> V_49 . V_50 ( V_38 , V_6 ) ;
V_51:
F_26 () ;
return V_41 ;
}
static int F_27 ( struct V_2 * V_3 , struct V_5 * V_6 ,
int V_52 )
{
const struct V_39 * V_40 ;
T_2 V_42 = F_1 ( V_3 ) -> V_14 ;
int V_53 = - V_54 ;
const struct V_39 * * V_43 ;
F_24 () ;
V_43 = F_23 ( V_6 ) -> V_46 ? V_47 : V_48 ;
V_40 = F_25 ( V_43 [ V_42 ] ) ;
if ( F_28 ( ! V_40 || ! V_40 -> V_49 . V_55 ) )
goto V_51;
V_53 = V_40 -> V_49 . V_55 ( V_6 , V_52 ) ;
F_29 ( V_6 , V_52 ) ;
V_51:
F_26 () ;
return V_53 ;
}
static struct V_15 * F_30 ( struct V_5 * V_6 , unsigned int V_56 ,
struct V_15 * V_15 , void * V_16 ,
T_1 V_17 , struct V_57 * V_58 ,
bool V_19 )
{
T_3 * V_20 = V_16 ;
T_1 V_21 = F_5 ( V_20 [ 0 ] ) ;
T_1 V_22 = F_5 ( V_20 [ 1 ] ) ;
if ( V_6 -> V_25 )
return V_15 ;
if ( ! F_23 ( V_6 ) -> V_59 )
return NULL ;
V_15 = F_31 ( V_6 , ( void * ) V_15 , V_56 , V_17 ,
V_21 , V_22 , V_58 , V_19 ) ;
V_6 -> V_25 = 1 ;
return V_15 ;
}
static struct V_5 * * F_32 ( struct V_2 * V_3 ,
struct V_5 * * V_38 ,
struct V_5 * V_6 )
{
const struct V_39 * * V_43 ;
const struct V_39 * V_40 ;
struct V_5 * * V_41 = NULL ;
struct V_5 * V_60 ;
struct V_15 * V_15 ;
T_1 V_7 , V_26 , V_17 , V_56 ;
void * V_16 ;
V_24 V_27 = 0 ;
int V_61 = 1 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_57 V_58 ;
F_33 ( & V_58 ) ;
V_56 = F_34 ( V_6 ) ;
V_7 = V_56 + sizeof( * V_15 ) ;
V_15 = F_35 ( V_6 , V_56 ) ;
if ( F_36 ( V_6 , V_7 ) ) {
V_15 = F_37 ( V_6 , V_7 , V_56 ) ;
if ( F_21 ( ! V_15 ) )
goto V_62;
}
V_26 = V_15 -> V_28 << 2 ;
V_7 += V_26 ;
if ( F_36 ( V_6 , V_7 ) ) {
V_15 = F_37 ( V_6 , V_7 , V_56 ) ;
if ( F_21 ( ! V_15 ) )
goto V_62;
}
if ( F_21 ( V_15 -> V_37 ) || V_15 -> V_29 != 0 ||
F_20 ( V_15 , V_26 ) )
goto V_62;
V_17 = sizeof( * V_15 ) + V_26 ;
F_38 ( V_6 , V_15 , V_17 ) ;
V_16 = & V_15 [ 1 ] ;
if ( V_15 -> V_30 & V_31 ) {
T_4 V_30 = * ( T_4 * ) ( V_16 + V_27 ) ;
V_27 += V_32 ;
if ( V_30 & V_33 ) {
V_15 = F_30 ( V_6 , V_56 , V_15 ,
V_16 + V_27 , V_17 , & V_58 ,
! ! ( V_1 -> V_30 &
V_35 ) ) ;
if ( ! V_15 )
goto V_62;
V_16 = & V_15 [ 1 ] ;
V_27 += V_36 ;
}
}
F_39 ( V_6 , V_17 ) ;
for ( V_60 = * V_38 ; V_60 ; V_60 = V_60 -> V_63 ) {
const struct V_15 * V_64 ;
if ( ! F_23 ( V_60 ) -> V_65 )
continue;
V_64 = (struct V_15 * ) ( V_60 -> V_16 + V_56 ) ;
if ( V_15 -> V_66 != V_64 -> V_66 ) {
F_23 ( V_60 ) -> V_65 = 0 ;
continue;
}
if ( V_15 -> V_28 && memcmp ( & V_15 [ 1 ] , & V_64 [ 1 ] ,
V_15 -> V_28 << 2 ) ) {
F_23 ( V_60 ) -> V_65 = 0 ;
continue;
}
}
F_23 ( V_6 ) -> V_44 = 0 ;
F_23 ( V_6 ) -> V_45 = 1 ;
F_24 () ;
V_43 = F_23 ( V_6 ) -> V_46 ? V_47 : V_48 ;
V_40 = F_25 ( V_43 [ V_15 -> V_34 ] ) ;
if ( F_40 ( ! V_40 || ! V_40 -> V_49 . V_50 ) )
goto V_51;
V_41 = V_40 -> V_49 . V_50 ( V_38 , V_6 ) ;
V_61 = 0 ;
V_51:
F_26 () ;
V_62:
F_23 ( V_6 ) -> V_61 |= V_61 ;
F_41 ( V_6 , & V_58 ) ;
return V_41 ;
}
static int F_42 ( struct V_2 * V_3 , struct V_5 * V_6 , int V_52 )
{
const struct V_39 * * V_43 ;
struct V_15 * V_15 = (struct V_15 * ) ( V_6 -> V_16 + V_52 ) ;
const struct V_39 * V_40 ;
unsigned int V_67 ;
T_2 V_42 ;
int V_53 = - V_68 ;
V_42 = V_15 -> V_34 ;
V_67 = sizeof( * V_15 ) + ( V_15 -> V_28 << 2 ) ;
F_24 () ;
V_43 = F_23 ( V_6 ) -> V_46 ? V_47 : V_48 ;
V_40 = F_25 ( V_43 [ V_42 ] ) ;
if ( F_28 ( ! V_40 || ! V_40 -> V_49 . V_55 ) )
goto V_51;
V_53 = V_40 -> V_49 . V_55 ( V_6 , V_52 + V_67 ) ;
F_29 ( V_6 , V_52 + V_67 ) ;
V_51:
F_26 () ;
return V_53 ;
}
static int F_43 ( struct V_69 * V_69 , struct V_1 * V_1 )
{
struct V_70 * V_71 = F_44 ( V_69 , V_72 ) ;
struct V_1 * V_73 ;
F_45 ( & V_71 -> V_74 ) ;
F_46 (fout, &fn->fou_list, list) {
if ( V_1 -> V_75 == V_73 -> V_75 &&
V_1 -> V_8 == V_73 -> V_8 ) {
F_47 ( & V_71 -> V_74 ) ;
return - V_76 ;
}
}
F_48 ( & V_1 -> V_77 , & V_71 -> V_78 ) ;
F_47 ( & V_71 -> V_74 ) ;
return 0 ;
}
static void F_49 ( struct V_1 * V_1 )
{
struct V_79 * V_2 = V_1 -> V_2 ;
F_50 ( & V_1 -> V_77 ) ;
F_51 ( V_2 ) ;
F_52 ( V_1 , V_80 ) ;
}
static int F_53 ( struct V_69 * V_69 , struct V_81 * V_82 ,
struct V_79 * * V_83 )
{
struct V_79 * V_2 = NULL ;
struct V_1 * V_1 = NULL ;
struct V_2 * V_3 ;
struct V_84 V_85 ;
int V_53 ;
V_53 = F_54 ( V_69 , & V_82 -> V_86 , & V_2 ) ;
if ( V_53 < 0 )
goto error;
V_1 = F_55 ( sizeof( * V_1 ) , V_87 ) ;
if ( ! V_1 ) {
V_53 = - V_88 ;
goto error;
}
V_3 = V_2 -> V_3 ;
V_1 -> V_75 = V_82 -> V_86 . V_89 ;
V_1 -> V_8 = V_82 -> V_86 . V_8 ;
V_1 -> V_30 = V_82 -> V_30 ;
V_1 -> type = V_82 -> type ;
V_1 -> V_2 = V_2 ;
memset ( & V_85 , 0 , sizeof( V_85 ) ) ;
V_85 . V_90 = 1 ;
V_85 . V_4 = V_1 ;
V_85 . V_91 = NULL ;
switch ( V_82 -> type ) {
case V_92 :
V_85 . V_93 = F_12 ;
V_85 . V_50 = F_22 ;
V_85 . V_55 = F_27 ;
V_1 -> V_14 = V_82 -> V_14 ;
break;
case V_94 :
V_85 . V_93 = F_19 ;
V_85 . V_50 = F_32 ;
V_85 . V_55 = F_42 ;
break;
default:
V_53 = - V_95 ;
goto error;
}
F_56 ( V_69 , V_2 , & V_85 ) ;
V_3 -> V_96 = V_97 ;
V_53 = F_43 ( V_69 , V_1 ) ;
if ( V_53 )
goto error;
if ( V_83 )
* V_83 = V_2 ;
return 0 ;
error:
F_57 ( V_1 ) ;
if ( V_2 )
F_51 ( V_2 ) ;
return V_53 ;
}
static int F_58 ( struct V_69 * V_69 , struct V_81 * V_82 )
{
struct V_70 * V_71 = F_44 ( V_69 , V_72 ) ;
T_3 V_75 = V_82 -> V_86 . V_89 ;
T_2 V_8 = V_82 -> V_86 . V_8 ;
int V_53 = - V_95 ;
struct V_1 * V_1 ;
F_45 ( & V_71 -> V_74 ) ;
F_46 (fou, &fn->fou_list, list) {
if ( V_1 -> V_75 == V_75 && V_1 -> V_8 == V_8 ) {
F_49 ( V_1 ) ;
V_53 = 0 ;
break;
}
}
F_47 ( & V_71 -> V_74 ) ;
return V_53 ;
}
static int F_59 ( struct V_98 * V_99 ,
struct V_81 * V_82 )
{
memset ( V_82 , 0 , sizeof( * V_82 ) ) ;
V_82 -> V_86 . V_8 = V_9 ;
if ( V_99 -> V_100 [ V_101 ] ) {
T_2 V_8 = F_60 ( V_99 -> V_100 [ V_101 ] ) ;
switch ( V_8 ) {
case V_9 :
break;
case V_102 :
V_82 -> V_86 . V_103 = 1 ;
break;
default:
return - V_104 ;
}
V_82 -> V_86 . V_8 = V_8 ;
}
if ( V_99 -> V_100 [ V_105 ] ) {
T_3 V_75 = F_61 ( V_99 -> V_100 [ V_105 ] ) ;
V_82 -> V_86 . V_89 = V_75 ;
}
if ( V_99 -> V_100 [ V_106 ] )
V_82 -> V_14 = F_60 ( V_99 -> V_100 [ V_106 ] ) ;
if ( V_99 -> V_100 [ V_107 ] )
V_82 -> type = F_60 ( V_99 -> V_100 [ V_107 ] ) ;
if ( V_99 -> V_100 [ V_108 ] )
V_82 -> V_30 |= V_35 ;
return 0 ;
}
static int F_62 ( struct V_5 * V_6 , struct V_98 * V_99 )
{
struct V_69 * V_69 = F_63 ( V_99 ) ;
struct V_81 V_82 ;
int V_53 ;
V_53 = F_59 ( V_99 , & V_82 ) ;
if ( V_53 )
return V_53 ;
return F_53 ( V_69 , & V_82 , NULL ) ;
}
static int F_64 ( struct V_5 * V_6 , struct V_98 * V_99 )
{
struct V_69 * V_69 = F_63 ( V_99 ) ;
struct V_81 V_82 ;
int V_53 ;
V_53 = F_59 ( V_99 , & V_82 ) ;
if ( V_53 )
return V_53 ;
return F_58 ( V_69 , & V_82 ) ;
}
static int F_65 ( struct V_1 * V_1 , struct V_5 * V_109 )
{
if ( F_66 ( V_109 , V_101 , V_1 -> V_2 -> V_3 -> V_110 ) ||
F_67 ( V_109 , V_105 , V_1 -> V_75 ) ||
F_66 ( V_109 , V_106 , V_1 -> V_14 ) ||
F_66 ( V_109 , V_107 , V_1 -> type ) )
return - 1 ;
if ( V_1 -> V_30 & V_35 )
if ( F_68 ( V_109 , V_108 ) )
return - 1 ;
return 0 ;
}
static int F_69 ( struct V_1 * V_1 , T_5 V_111 , T_5 V_112 ,
T_5 V_30 , struct V_5 * V_6 , T_2 V_113 )
{
void * V_114 ;
V_114 = F_70 ( V_6 , V_111 , V_112 , & V_115 , V_30 , V_113 ) ;
if ( ! V_114 )
return - V_88 ;
if ( F_65 ( V_1 , V_6 ) < 0 )
goto V_116;
F_71 ( V_6 , V_114 ) ;
return 0 ;
V_116:
F_72 ( V_6 , V_114 ) ;
return - V_117 ;
}
static int F_73 ( struct V_5 * V_6 , struct V_98 * V_99 )
{
struct V_69 * V_69 = F_63 ( V_99 ) ;
struct V_70 * V_71 = F_44 ( V_69 , V_72 ) ;
struct V_5 * V_109 ;
struct V_81 V_82 ;
struct V_1 * V_73 ;
T_3 V_75 ;
T_2 V_8 ;
int V_118 ;
V_118 = F_59 ( V_99 , & V_82 ) ;
if ( V_118 )
return V_118 ;
V_75 = V_82 . V_86 . V_89 ;
if ( V_75 == 0 )
return - V_95 ;
V_8 = V_82 . V_86 . V_8 ;
if ( V_8 != V_9 && V_8 != V_102 )
return - V_95 ;
V_109 = F_74 ( V_119 , V_87 ) ;
if ( ! V_109 )
return - V_88 ;
V_118 = - V_120 ;
F_45 ( & V_71 -> V_74 ) ;
F_46 (fout, &fn->fou_list, list) {
if ( V_75 == V_73 -> V_75 && V_8 == V_73 -> V_8 ) {
V_118 = F_69 ( V_73 , V_99 -> V_121 ,
V_99 -> V_122 , 0 , V_109 ,
V_99 -> V_123 -> V_113 ) ;
break;
}
}
F_47 ( & V_71 -> V_74 ) ;
if ( V_118 < 0 )
goto V_124;
return F_75 ( V_109 , V_99 ) ;
V_124:
F_76 ( V_109 ) ;
return V_118 ;
}
static int F_77 ( struct V_5 * V_6 , struct V_125 * V_126 )
{
struct V_69 * V_69 = F_78 ( V_6 -> V_3 ) ;
struct V_70 * V_71 = F_44 ( V_69 , V_72 ) ;
struct V_1 * V_73 ;
int V_127 = 0 , V_118 ;
F_45 ( & V_71 -> V_74 ) ;
F_46 (fout, &fn->fou_list, list) {
if ( V_127 ++ < V_126 -> args [ 0 ] )
continue;
V_118 = F_69 ( V_73 , F_79 ( V_126 -> V_6 ) . V_111 ,
V_126 -> V_128 -> V_129 , V_130 ,
V_6 , V_131 ) ;
if ( V_118 )
break;
}
F_47 ( & V_71 -> V_74 ) ;
V_126 -> args [ 0 ] = V_127 ;
return V_6 -> V_7 ;
}
T_1 F_80 ( struct V_132 * V_133 )
{
return sizeof( struct V_12 ) ;
}
T_1 F_81 ( struct V_132 * V_133 )
{
T_1 V_7 ;
bool V_134 = false ;
V_7 = sizeof( struct V_12 ) + sizeof( struct V_15 ) ;
if ( V_133 -> V_30 & V_135 ) {
V_7 += V_36 ;
V_134 = true ;
}
V_7 += V_134 ? V_32 : 0 ;
return V_7 ;
}
static void F_82 ( struct V_5 * V_6 , struct V_132 * V_133 ,
struct V_136 * V_137 , T_2 * V_14 , T_3 V_138 )
{
struct V_12 * V_139 ;
F_83 ( V_6 , sizeof( struct V_12 ) ) ;
F_10 ( V_6 ) ;
V_139 = F_9 ( V_6 ) ;
V_139 -> V_140 = V_133 -> V_141 ;
V_139 -> V_142 = V_138 ;
V_139 -> V_7 = F_4 ( V_6 -> V_7 ) ;
F_84 ( ! ( V_133 -> V_30 & V_143 ) , V_6 ,
V_137 -> V_144 , V_137 -> V_145 , V_6 -> V_7 ) ;
* V_14 = V_146 ;
}
int F_85 ( struct V_5 * V_6 , struct V_132 * V_133 ,
T_2 * V_14 , T_3 * V_138 , int type )
{
int V_53 ;
V_53 = F_86 ( V_6 , type ) ;
if ( V_53 )
return V_53 ;
* V_138 = V_133 -> V_138 ? : F_87 ( F_88 ( V_6 -> V_147 ) ,
V_6 , 0 , 0 , false ) ;
return 0 ;
}
int F_89 ( struct V_5 * V_6 , struct V_132 * V_133 ,
T_2 * V_14 , struct V_136 * V_137 )
{
int type = V_133 -> V_30 & V_143 ? V_148 :
V_149 ;
T_3 V_138 ;
int V_53 ;
V_53 = F_85 ( V_6 , V_133 , V_14 , & V_138 , type ) ;
if ( V_53 )
return V_53 ;
F_82 ( V_6 , V_133 , V_137 , V_14 , V_138 ) ;
return 0 ;
}
int F_90 ( struct V_5 * V_6 , struct V_132 * V_133 ,
T_2 * V_14 , T_3 * V_138 , int type )
{
struct V_15 * V_15 ;
T_1 V_17 , V_26 = 0 ;
void * V_16 ;
bool V_134 = false ;
int V_53 ;
if ( ( V_133 -> V_30 & V_135 ) &&
V_6 -> V_150 == V_151 ) {
V_26 += V_36 ;
type |= V_152 ;
V_134 = true ;
}
V_26 += V_134 ? V_32 : 0 ;
V_53 = F_86 ( V_6 , type ) ;
if ( V_53 )
return V_53 ;
* V_138 = V_133 -> V_138 ? : F_87 ( F_88 ( V_6 -> V_147 ) ,
V_6 , 0 , 0 , false ) ;
V_17 = sizeof( struct V_15 ) + V_26 ;
F_83 ( V_6 , V_17 ) ;
V_15 = (struct V_15 * ) V_6 -> V_16 ;
V_15 -> V_37 = 0 ;
V_15 -> V_29 = 0 ;
V_15 -> V_28 = V_26 >> 2 ;
V_15 -> V_30 = 0 ;
V_15 -> V_34 = * V_14 ;
V_16 = & V_15 [ 1 ] ;
if ( V_134 ) {
T_4 * V_30 = V_16 ;
V_15 -> V_30 |= V_31 ;
* V_30 = 0 ;
V_16 += V_32 ;
if ( type & V_152 ) {
V_24 V_153 = F_91 ( V_6 ) ;
T_3 * V_20 = V_16 ;
if ( V_153 < V_17 )
return - V_95 ;
V_153 -= V_17 ;
V_20 [ 0 ] = F_4 ( V_153 ) ;
V_20 [ 1 ] = F_4 ( V_153 + V_6 -> V_154 ) ;
if ( ! F_92 ( V_6 ) ) {
V_6 -> V_150 = V_155 ;
V_6 -> V_156 = 0 ;
}
* V_30 |= V_33 ;
V_16 += V_36 ;
}
}
return 0 ;
}
int F_93 ( struct V_5 * V_6 , struct V_132 * V_133 ,
T_2 * V_14 , struct V_136 * V_137 )
{
int type = V_133 -> V_30 & V_143 ? V_148 :
V_149 ;
T_3 V_138 ;
int V_53 ;
V_53 = F_90 ( V_6 , V_133 , V_14 , & V_138 , type ) ;
if ( V_53 )
return V_53 ;
F_82 ( V_6 , V_133 , V_137 , V_14 , V_138 ) ;
return 0 ;
}
static int F_94 ( void )
{
int V_118 ;
V_118 = F_95 ( & V_157 , V_158 ) ;
if ( V_118 < 0 ) {
F_96 ( L_1 ) ;
return V_118 ;
}
V_118 = F_95 ( & V_159 , V_160 ) ;
if ( V_118 < 0 ) {
F_96 ( L_2 ) ;
F_97 ( & V_157 , V_158 ) ;
return V_118 ;
}
return 0 ;
}
static void F_98 ( void )
{
F_97 ( & V_157 , V_158 ) ;
F_97 ( & V_159 , V_160 ) ;
}
static int F_94 ( void )
{
return 0 ;
}
static void F_98 ( void )
{
}
static T_6 int F_99 ( struct V_69 * V_69 )
{
struct V_70 * V_71 = F_44 ( V_69 , V_72 ) ;
F_100 ( & V_71 -> V_78 ) ;
F_101 ( & V_71 -> V_74 ) ;
return 0 ;
}
static T_7 void F_102 ( struct V_69 * V_69 )
{
struct V_70 * V_71 = F_44 ( V_69 , V_72 ) ;
struct V_1 * V_1 , * V_63 ;
F_45 ( & V_71 -> V_74 ) ;
F_103 (fou, next, &fn->fou_list, list)
F_49 ( V_1 ) ;
F_47 ( & V_71 -> V_74 ) ;
}
static int T_8 F_104 ( void )
{
int V_118 ;
V_118 = F_105 ( & V_161 ) ;
if ( V_118 )
goto exit;
V_118 = F_106 ( & V_115 ,
V_162 ) ;
if ( V_118 < 0 )
goto V_163;
V_118 = F_94 () ;
if ( V_118 == 0 )
return 0 ;
F_107 ( & V_115 ) ;
V_163:
F_108 ( & V_161 ) ;
exit:
return V_118 ;
}
static void T_9 F_109 ( void )
{
F_98 () ;
F_107 ( & V_115 ) ;
F_108 ( & V_161 ) ;
}
