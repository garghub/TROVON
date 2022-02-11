static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return V_3 -> V_4 ;
}
static int F_2 ( struct V_5 * V_6 , T_1 V_7 )
{
struct V_8 * V_9 = F_3 ( V_6 ) ;
V_9 -> V_10 = F_4 ( F_5 ( V_9 -> V_10 ) - V_7 ) ;
F_6 ( V_6 , V_7 ) ;
F_7 ( V_6 , F_8 ( V_6 ) , V_7 ) ;
F_9 ( V_6 ) ;
return F_10 ( V_6 ) ;
}
static int F_11 ( struct V_2 * V_3 , struct V_5 * V_6 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
if ( ! V_1 )
return 1 ;
if ( F_2 ( V_6 , sizeof( struct V_11 ) ) )
goto V_12;
return - V_1 -> V_13 ;
V_12:
F_12 ( V_6 ) ;
return 0 ;
}
static struct V_14 * F_13 ( struct V_5 * V_6 , struct V_14 * V_14 ,
void * V_15 , T_1 V_16 , T_2 V_17 ,
bool V_18 )
{
T_3 * V_19 = V_15 ;
T_1 V_20 = F_5 ( V_19 [ 0 ] ) ;
T_1 V_21 = F_5 ( V_19 [ 1 ] ) ;
T_1 V_22 = sizeof( struct V_11 ) + V_16 +
F_14 ( T_1 , V_21 + sizeof( V_23 ) , V_20 ) ;
if ( V_6 -> V_24 )
return V_14 ;
if ( ! F_15 ( V_6 , V_22 ) )
return NULL ;
V_14 = (struct V_14 * ) & F_8 ( V_6 ) [ 1 ] ;
F_16 ( V_6 , ( void * ) V_14 + V_16 ,
V_20 , V_21 , V_18 ) ;
return V_14 ;
}
static int F_17 ( struct V_5 * V_6 , struct V_14 * V_14 )
{
F_12 ( V_6 ) ;
return 0 ;
}
static int F_18 ( struct V_2 * V_3 , struct V_5 * V_6 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
T_1 V_7 , V_25 , V_16 ;
struct V_14 * V_14 ;
void * V_15 ;
V_23 V_26 = 0 ;
if ( ! V_1 )
return 1 ;
V_7 = sizeof( struct V_11 ) + sizeof( struct V_14 ) ;
if ( ! F_15 ( V_6 , V_7 ) )
goto V_12;
V_14 = (struct V_14 * ) & F_8 ( V_6 ) [ 1 ] ;
V_25 = V_14 -> V_27 << 2 ;
V_7 += V_25 ;
if ( ! F_15 ( V_6 , V_7 ) )
goto V_12;
V_14 = (struct V_14 * ) & F_8 ( V_6 ) [ 1 ] ;
V_16 = sizeof( struct V_14 ) + V_25 ;
if ( V_14 -> V_28 != 0 || F_19 ( V_14 , V_25 ) )
goto V_12;
V_16 = sizeof( struct V_14 ) + V_25 ;
F_3 ( V_6 ) -> V_10 = F_4 ( F_5 ( F_3 ( V_6 ) -> V_10 ) - V_7 ) ;
F_7 ( V_6 , F_8 ( V_6 ) , V_7 ) ;
V_15 = & V_14 [ 1 ] ;
if ( V_14 -> V_29 & V_30 ) {
T_4 V_29 = * ( T_4 * ) ( V_15 + V_26 ) ;
V_26 += V_31 ;
if ( V_29 & V_32 ) {
V_14 = F_13 ( V_6 , V_14 , V_15 + V_26 ,
V_16 , V_14 -> V_33 ,
! ! ( V_1 -> V_29 &
V_34 ) ) ;
if ( ! V_14 )
goto V_12;
V_15 = & V_14 [ 1 ] ;
V_26 += V_35 ;
}
}
if ( F_20 ( V_14 -> V_36 ) )
return F_17 ( V_6 , V_14 ) ;
F_6 ( V_6 , sizeof( struct V_11 ) + V_16 ) ;
F_9 ( V_6 ) ;
if ( F_10 ( V_6 ) )
goto V_12;
return - V_14 -> V_33 ;
V_12:
F_12 ( V_6 ) ;
return 0 ;
}
static struct V_5 * * F_21 ( struct V_5 * * V_37 ,
struct V_5 * V_6 ,
struct V_38 * V_39 )
{
const struct V_40 * V_41 ;
struct V_5 * * V_42 = NULL ;
T_2 V_43 = F_22 ( V_6 ) -> V_43 ;
const struct V_40 * * V_44 ;
F_22 ( V_6 ) -> V_45 = 0 ;
F_22 ( V_6 ) -> V_46 = 1 ;
F_23 () ;
V_44 = F_22 ( V_6 ) -> V_47 ? V_48 : V_49 ;
V_41 = F_24 ( V_44 [ V_43 ] ) ;
if ( ! V_41 || ! V_41 -> V_50 . V_51 )
goto V_52;
V_42 = V_41 -> V_50 . V_51 ( V_37 , V_6 ) ;
V_52:
F_25 () ;
return V_42 ;
}
static int F_26 ( struct V_5 * V_6 , int V_53 ,
struct V_38 * V_39 )
{
const struct V_40 * V_41 ;
T_2 V_43 = F_22 ( V_6 ) -> V_43 ;
int V_54 = - V_55 ;
const struct V_40 * * V_44 ;
F_23 () ;
V_44 = F_22 ( V_6 ) -> V_47 ? V_48 : V_49 ;
V_41 = F_24 ( V_44 [ V_43 ] ) ;
if ( F_27 ( ! V_41 || ! V_41 -> V_50 . V_56 ) )
goto V_52;
V_54 = V_41 -> V_50 . V_56 ( V_6 , V_53 ) ;
F_28 ( V_6 , V_53 ) ;
V_52:
F_25 () ;
return V_54 ;
}
static struct V_14 * F_29 ( struct V_5 * V_6 , unsigned int V_57 ,
struct V_14 * V_14 , void * V_15 ,
T_1 V_16 , struct V_58 * V_59 ,
bool V_18 )
{
T_3 * V_19 = V_15 ;
T_1 V_20 = F_5 ( V_19 [ 0 ] ) ;
T_1 V_21 = F_5 ( V_19 [ 1 ] ) ;
if ( V_6 -> V_24 )
return V_14 ;
if ( ! F_22 ( V_6 ) -> V_60 )
return NULL ;
V_14 = F_30 ( V_6 , ( void * ) V_14 , V_57 , V_16 ,
V_20 , V_21 , V_59 , V_18 ) ;
V_6 -> V_24 = 1 ;
return V_14 ;
}
static struct V_5 * * F_31 ( struct V_5 * * V_37 ,
struct V_5 * V_6 ,
struct V_38 * V_39 )
{
const struct V_40 * * V_44 ;
const struct V_40 * V_41 ;
struct V_5 * * V_42 = NULL ;
struct V_5 * V_61 ;
struct V_14 * V_14 ;
T_1 V_7 , V_25 , V_16 , V_57 ;
void * V_15 ;
V_23 V_26 = 0 ;
int V_62 = 1 ;
struct V_1 * V_1 = F_32 ( V_39 , struct V_1 , V_63 ) ;
struct V_58 V_59 ;
F_33 ( & V_59 ) ;
V_57 = F_34 ( V_6 ) ;
V_7 = V_57 + sizeof( * V_14 ) ;
V_14 = F_35 ( V_6 , V_57 ) ;
if ( F_36 ( V_6 , V_7 ) ) {
V_14 = F_37 ( V_6 , V_7 , V_57 ) ;
if ( F_20 ( ! V_14 ) )
goto V_64;
}
V_25 = V_14 -> V_27 << 2 ;
V_7 += V_25 ;
if ( F_36 ( V_6 , V_7 ) ) {
V_14 = F_37 ( V_6 , V_7 , V_57 ) ;
if ( F_20 ( ! V_14 ) )
goto V_64;
}
if ( F_20 ( V_14 -> V_36 ) || V_14 -> V_28 != 0 ||
F_19 ( V_14 , V_25 ) )
goto V_64;
V_16 = sizeof( * V_14 ) + V_25 ;
F_38 ( V_6 , V_14 , V_16 ) ;
V_15 = & V_14 [ 1 ] ;
if ( V_14 -> V_29 & V_30 ) {
T_4 V_29 = * ( T_4 * ) ( V_15 + V_26 ) ;
V_26 += V_31 ;
if ( V_29 & V_32 ) {
V_14 = F_29 ( V_6 , V_57 , V_14 ,
V_15 + V_26 , V_16 , & V_59 ,
! ! ( V_1 -> V_29 &
V_34 ) ) ;
if ( ! V_14 )
goto V_64;
V_15 = & V_14 [ 1 ] ;
V_26 += V_35 ;
}
}
F_39 ( V_6 , V_16 ) ;
for ( V_61 = * V_37 ; V_61 ; V_61 = V_61 -> V_65 ) {
const struct V_14 * V_66 ;
if ( ! F_22 ( V_61 ) -> V_67 )
continue;
V_66 = (struct V_14 * ) ( V_61 -> V_15 + V_57 ) ;
if ( V_14 -> V_68 != V_66 -> V_68 ) {
F_22 ( V_61 ) -> V_67 = 0 ;
continue;
}
if ( V_14 -> V_27 && memcmp ( & V_14 [ 1 ] , & V_66 [ 1 ] ,
V_14 -> V_27 << 2 ) ) {
F_22 ( V_61 ) -> V_67 = 0 ;
continue;
}
}
F_22 ( V_6 ) -> V_45 = 0 ;
F_22 ( V_6 ) -> V_46 = 1 ;
F_23 () ;
V_44 = F_22 ( V_6 ) -> V_47 ? V_48 : V_49 ;
V_41 = F_24 ( V_44 [ V_14 -> V_33 ] ) ;
if ( F_40 ( ! V_41 || ! V_41 -> V_50 . V_51 ) )
goto V_52;
V_42 = V_41 -> V_50 . V_51 ( V_37 , V_6 ) ;
V_62 = 0 ;
V_52:
F_25 () ;
V_64:
F_22 ( V_6 ) -> V_62 |= V_62 ;
F_41 ( V_6 , & V_59 ) ;
return V_42 ;
}
static int F_42 ( struct V_5 * V_6 , int V_53 ,
struct V_38 * V_39 )
{
const struct V_40 * * V_44 ;
struct V_14 * V_14 = (struct V_14 * ) ( V_6 -> V_15 + V_53 ) ;
const struct V_40 * V_41 ;
unsigned int V_69 ;
T_2 V_43 ;
int V_54 = - V_70 ;
V_43 = V_14 -> V_33 ;
V_69 = sizeof( * V_14 ) + ( V_14 -> V_27 << 2 ) ;
F_23 () ;
V_44 = F_22 ( V_6 ) -> V_47 ? V_48 : V_49 ;
V_41 = F_24 ( V_44 [ V_43 ] ) ;
if ( F_27 ( ! V_41 || ! V_41 -> V_50 . V_56 ) )
goto V_52;
V_54 = V_41 -> V_50 . V_56 ( V_6 , V_53 + V_69 ) ;
F_28 ( V_6 , V_53 + V_69 ) ;
V_52:
F_25 () ;
return V_54 ;
}
static int F_43 ( struct V_71 * V_71 , struct V_1 * V_1 )
{
struct V_72 * V_73 = F_44 ( V_71 , V_74 ) ;
struct V_1 * V_75 ;
F_45 ( & V_73 -> V_76 ) ;
F_46 (fout, &fn->fou_list, list) {
if ( V_1 -> V_77 == V_75 -> V_77 ) {
F_47 ( & V_73 -> V_76 ) ;
return - V_78 ;
}
}
F_48 ( & V_1 -> V_79 , & V_73 -> V_80 ) ;
F_47 ( & V_73 -> V_76 ) ;
return 0 ;
}
static void F_49 ( struct V_1 * V_1 )
{
struct V_81 * V_2 = V_1 -> V_2 ;
struct V_2 * V_3 = V_2 -> V_3 ;
if ( V_3 -> V_82 == V_83 )
F_50 ( & V_1 -> V_63 ) ;
F_51 ( & V_1 -> V_79 ) ;
F_52 ( V_2 ) ;
F_53 ( V_1 , V_84 ) ;
}
static int F_54 ( struct V_2 * V_3 , struct V_1 * V_1 , struct V_85 * V_86 )
{
F_55 ( V_3 ) -> V_87 = F_11 ;
V_1 -> V_13 = V_86 -> V_13 ;
V_1 -> V_63 . V_50 . V_51 = F_21 ;
V_1 -> V_63 . V_50 . V_56 = F_26 ;
V_1 -> V_63 . V_77 = V_86 -> V_88 . V_89 ;
V_1 -> V_63 . V_17 = V_86 -> V_13 ;
return 0 ;
}
static int F_56 ( struct V_2 * V_3 , struct V_1 * V_1 , struct V_85 * V_86 )
{
F_55 ( V_3 ) -> V_87 = F_18 ;
V_1 -> V_63 . V_50 . V_51 = F_31 ;
V_1 -> V_63 . V_50 . V_56 = F_42 ;
V_1 -> V_63 . V_77 = V_86 -> V_88 . V_89 ;
return 0 ;
}
static int F_57 ( struct V_71 * V_71 , struct V_85 * V_86 ,
struct V_81 * * V_90 )
{
struct V_81 * V_2 = NULL ;
struct V_1 * V_1 = NULL ;
struct V_2 * V_3 ;
int V_54 ;
V_54 = F_58 ( V_71 , & V_86 -> V_88 , & V_2 ) ;
if ( V_54 < 0 )
goto error;
V_1 = F_59 ( sizeof( * V_1 ) , V_91 ) ;
if ( ! V_1 ) {
V_54 = - V_92 ;
goto error;
}
V_3 = V_2 -> V_3 ;
V_1 -> V_29 = V_86 -> V_29 ;
V_1 -> V_77 = V_86 -> V_88 . V_89 ;
switch ( V_86 -> type ) {
case V_93 :
V_54 = F_54 ( V_3 , V_1 , V_86 ) ;
if ( V_54 )
goto error;
break;
case V_94 :
V_54 = F_56 ( V_3 , V_1 , V_86 ) ;
if ( V_54 )
goto error;
break;
default:
V_54 = - V_95 ;
goto error;
}
V_1 -> type = V_86 -> type ;
F_55 ( V_3 ) -> V_96 = 1 ;
F_60 () ;
V_3 -> V_4 = V_1 ;
V_1 -> V_2 = V_2 ;
F_61 ( V_3 ) ;
V_3 -> V_97 = V_98 ;
if ( V_86 -> V_88 . V_99 == V_83 ) {
V_54 = F_62 ( V_71 , & V_1 -> V_63 ) ;
if ( V_54 )
goto error;
}
V_54 = F_43 ( V_71 , V_1 ) ;
if ( V_54 )
goto error;
if ( V_90 )
* V_90 = V_2 ;
return 0 ;
error:
F_63 ( V_1 ) ;
if ( V_2 )
F_52 ( V_2 ) ;
return V_54 ;
}
static int F_64 ( struct V_71 * V_71 , struct V_85 * V_86 )
{
struct V_72 * V_73 = F_44 ( V_71 , V_74 ) ;
T_3 V_77 = V_86 -> V_88 . V_89 ;
int V_54 = - V_95 ;
struct V_1 * V_1 ;
F_45 ( & V_73 -> V_76 ) ;
F_46 (fou, &fn->fou_list, list) {
if ( V_1 -> V_77 == V_77 ) {
F_49 ( V_1 ) ;
V_54 = 0 ;
break;
}
}
F_47 ( & V_73 -> V_76 ) ;
return V_54 ;
}
static int F_65 ( struct V_100 * V_101 ,
struct V_85 * V_86 )
{
memset ( V_86 , 0 , sizeof( * V_86 ) ) ;
V_86 -> V_88 . V_99 = V_83 ;
if ( V_101 -> V_102 [ V_103 ] ) {
T_2 V_99 = F_66 ( V_101 -> V_102 [ V_103 ] ) ;
if ( V_99 != V_83 )
return - V_95 ;
V_86 -> V_88 . V_99 = V_99 ;
}
if ( V_101 -> V_102 [ V_104 ] ) {
T_3 V_77 = F_67 ( V_101 -> V_102 [ V_104 ] ) ;
V_86 -> V_88 . V_89 = V_77 ;
}
if ( V_101 -> V_102 [ V_105 ] )
V_86 -> V_13 = F_66 ( V_101 -> V_102 [ V_105 ] ) ;
if ( V_101 -> V_102 [ V_106 ] )
V_86 -> type = F_66 ( V_101 -> V_102 [ V_106 ] ) ;
if ( V_101 -> V_102 [ V_107 ] )
V_86 -> V_29 |= V_34 ;
return 0 ;
}
static int F_68 ( struct V_5 * V_6 , struct V_100 * V_101 )
{
struct V_71 * V_71 = F_69 ( V_101 ) ;
struct V_85 V_86 ;
int V_54 ;
V_54 = F_65 ( V_101 , & V_86 ) ;
if ( V_54 )
return V_54 ;
return F_57 ( V_71 , & V_86 , NULL ) ;
}
static int F_70 ( struct V_5 * V_6 , struct V_100 * V_101 )
{
struct V_71 * V_71 = F_69 ( V_101 ) ;
struct V_85 V_86 ;
int V_54 ;
V_54 = F_65 ( V_101 , & V_86 ) ;
if ( V_54 )
return V_54 ;
return F_64 ( V_71 , & V_86 ) ;
}
static int F_71 ( struct V_1 * V_1 , struct V_5 * V_108 )
{
if ( F_72 ( V_108 , V_103 , V_1 -> V_2 -> V_3 -> V_82 ) ||
F_73 ( V_108 , V_104 , V_1 -> V_77 ) ||
F_72 ( V_108 , V_105 , V_1 -> V_13 ) ||
F_72 ( V_108 , V_106 , V_1 -> type ) )
return - 1 ;
if ( V_1 -> V_29 & V_34 )
if ( F_74 ( V_108 , V_107 ) )
return - 1 ;
return 0 ;
}
static int F_75 ( struct V_1 * V_1 , T_5 V_109 , T_5 V_110 ,
T_5 V_29 , struct V_5 * V_6 , T_2 V_111 )
{
void * V_112 ;
V_112 = F_76 ( V_6 , V_109 , V_110 , & V_113 , V_29 , V_111 ) ;
if ( ! V_112 )
return - V_92 ;
if ( F_71 ( V_1 , V_6 ) < 0 )
goto V_114;
F_77 ( V_6 , V_112 ) ;
return 0 ;
V_114:
F_78 ( V_6 , V_112 ) ;
return - V_115 ;
}
static int F_79 ( struct V_5 * V_6 , struct V_100 * V_101 )
{
struct V_71 * V_71 = F_69 ( V_101 ) ;
struct V_72 * V_73 = F_44 ( V_71 , V_74 ) ;
struct V_5 * V_108 ;
struct V_85 V_86 ;
struct V_1 * V_75 ;
T_3 V_77 ;
int V_116 ;
V_116 = F_65 ( V_101 , & V_86 ) ;
if ( V_116 )
return V_116 ;
V_77 = V_86 . V_88 . V_89 ;
if ( V_77 == 0 )
return - V_95 ;
V_108 = F_80 ( V_117 , V_91 ) ;
if ( ! V_108 )
return - V_92 ;
V_116 = - V_118 ;
F_45 ( & V_73 -> V_76 ) ;
F_46 (fout, &fn->fou_list, list) {
if ( V_77 == V_75 -> V_77 ) {
V_116 = F_75 ( V_75 , V_101 -> V_119 ,
V_101 -> V_120 , 0 , V_108 ,
V_101 -> V_121 -> V_111 ) ;
break;
}
}
F_47 ( & V_73 -> V_76 ) ;
if ( V_116 < 0 )
goto V_122;
return F_81 ( V_108 , V_101 ) ;
V_122:
F_82 ( V_108 ) ;
return V_116 ;
}
static int F_83 ( struct V_5 * V_6 , struct V_123 * V_124 )
{
struct V_71 * V_71 = F_84 ( V_6 -> V_3 ) ;
struct V_72 * V_73 = F_44 ( V_71 , V_74 ) ;
struct V_1 * V_75 ;
int V_125 = 0 , V_116 ;
F_45 ( & V_73 -> V_76 ) ;
F_46 (fout, &fn->fou_list, list) {
if ( V_125 ++ < V_124 -> args [ 0 ] )
continue;
V_116 = F_75 ( V_75 , F_85 ( V_124 -> V_6 ) . V_109 ,
V_124 -> V_126 -> V_127 , V_128 ,
V_6 , V_129 ) ;
if ( V_116 )
break;
}
F_47 ( & V_73 -> V_76 ) ;
V_124 -> args [ 0 ] = V_125 ;
return V_6 -> V_7 ;
}
T_1 F_86 ( struct V_130 * V_131 )
{
return sizeof( struct V_11 ) ;
}
T_1 F_87 ( struct V_130 * V_131 )
{
T_1 V_7 ;
bool V_132 = false ;
V_7 = sizeof( struct V_11 ) + sizeof( struct V_14 ) ;
if ( V_131 -> V_29 & V_133 ) {
V_7 += V_35 ;
V_132 = true ;
}
V_7 += V_132 ? V_31 : 0 ;
return V_7 ;
}
static void F_88 ( struct V_5 * V_6 , struct V_130 * V_131 ,
struct V_134 * V_135 , T_2 * V_13 , T_3 V_136 )
{
struct V_11 * V_137 ;
F_89 ( V_6 , sizeof( struct V_11 ) ) ;
F_9 ( V_6 ) ;
V_137 = F_8 ( V_6 ) ;
V_137 -> V_138 = V_131 -> V_139 ;
V_137 -> V_140 = V_136 ;
V_137 -> V_7 = F_4 ( V_6 -> V_7 ) ;
F_90 ( ! ( V_131 -> V_29 & V_141 ) , V_6 ,
V_135 -> V_142 , V_135 -> V_143 , V_6 -> V_7 ) ;
* V_13 = V_144 ;
}
int F_91 ( struct V_5 * V_6 , struct V_130 * V_131 ,
T_2 * V_13 , struct V_134 * V_135 )
{
int type = V_131 -> V_29 & V_141 ? V_145 :
V_146 ;
T_3 V_136 ;
V_6 = F_92 ( V_6 , type ) ;
if ( F_93 ( V_6 ) )
return F_94 ( V_6 ) ;
V_136 = V_131 -> V_136 ? : F_95 ( F_96 ( V_6 -> V_147 ) ,
V_6 , 0 , 0 , false ) ;
F_88 ( V_6 , V_131 , V_135 , V_13 , V_136 ) ;
return 0 ;
}
int F_97 ( struct V_5 * V_6 , struct V_130 * V_131 ,
T_2 * V_13 , struct V_134 * V_135 )
{
int type = V_131 -> V_29 & V_141 ? V_145 :
V_146 ;
struct V_14 * V_14 ;
T_1 V_16 , V_25 = 0 ;
T_3 V_136 ;
void * V_15 ;
bool V_132 = false ;
if ( ( V_131 -> V_29 & V_133 ) &&
V_6 -> V_148 == V_149 ) {
V_25 += V_35 ;
type |= V_150 ;
V_132 = true ;
}
V_25 += V_132 ? V_31 : 0 ;
V_6 = F_92 ( V_6 , type ) ;
if ( F_93 ( V_6 ) )
return F_94 ( V_6 ) ;
V_136 = V_131 -> V_136 ? : F_95 ( F_96 ( V_6 -> V_147 ) ,
V_6 , 0 , 0 , false ) ;
V_16 = sizeof( struct V_14 ) + V_25 ;
F_89 ( V_6 , V_16 ) ;
V_14 = (struct V_14 * ) V_6 -> V_15 ;
V_14 -> V_36 = 0 ;
V_14 -> V_28 = 0 ;
V_14 -> V_27 = V_25 >> 2 ;
V_14 -> V_29 = 0 ;
V_14 -> V_33 = * V_13 ;
V_15 = & V_14 [ 1 ] ;
if ( V_132 ) {
T_4 * V_29 = V_15 ;
V_14 -> V_29 |= V_30 ;
* V_29 = 0 ;
V_15 += V_31 ;
if ( type & V_150 ) {
V_23 V_151 = F_98 ( V_6 ) ;
T_3 * V_19 = V_15 ;
if ( V_151 < V_16 )
return - V_95 ;
V_151 -= V_16 ;
V_19 [ 0 ] = F_4 ( V_151 ) ;
V_19 [ 1 ] = F_4 ( V_151 + V_6 -> V_152 ) ;
if ( ! F_99 ( V_6 ) ) {
V_6 -> V_148 = V_153 ;
V_6 -> V_154 = 0 ;
}
* V_29 |= V_32 ;
V_15 += V_35 ;
}
}
F_88 ( V_6 , V_131 , V_135 , V_13 , V_136 ) ;
return 0 ;
}
static int F_100 ( void )
{
int V_116 ;
V_116 = F_101 ( & V_155 , V_156 ) ;
if ( V_116 < 0 ) {
F_102 ( L_1 ) ;
return V_116 ;
}
V_116 = F_101 ( & V_157 , V_158 ) ;
if ( V_116 < 0 ) {
F_102 ( L_2 ) ;
F_103 ( & V_155 , V_156 ) ;
return V_116 ;
}
return 0 ;
}
static void F_104 ( void )
{
F_103 ( & V_155 , V_156 ) ;
F_103 ( & V_157 , V_158 ) ;
}
static int F_100 ( void )
{
return 0 ;
}
static void F_104 ( void )
{
}
static T_6 int F_105 ( struct V_71 * V_71 )
{
struct V_72 * V_73 = F_44 ( V_71 , V_74 ) ;
F_106 ( & V_73 -> V_80 ) ;
F_107 ( & V_73 -> V_76 ) ;
return 0 ;
}
static T_7 void F_108 ( struct V_71 * V_71 )
{
struct V_72 * V_73 = F_44 ( V_71 , V_74 ) ;
struct V_1 * V_1 , * V_65 ;
F_45 ( & V_73 -> V_76 ) ;
F_109 (fou, next, &fn->fou_list, list)
F_49 ( V_1 ) ;
F_47 ( & V_73 -> V_76 ) ;
}
static int T_8 F_110 ( void )
{
int V_116 ;
V_116 = F_111 ( & V_159 ) ;
if ( V_116 )
goto exit;
V_116 = F_112 ( & V_113 ,
V_160 ) ;
if ( V_116 < 0 )
goto V_161;
V_116 = F_100 () ;
if ( V_116 == 0 )
return 0 ;
F_113 ( & V_113 ) ;
V_161:
F_114 ( & V_159 ) ;
exit:
return V_116 ;
}
static void T_9 F_115 ( void )
{
F_104 () ;
F_113 ( & V_113 ) ;
F_114 ( & V_159 ) ;
}
