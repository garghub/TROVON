static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return V_3 -> V_4 ;
}
static void F_2 ( struct V_5 * V_6 , T_1 V_7 )
{
struct V_8 * V_9 = F_3 ( V_6 ) ;
V_9 -> V_10 = F_4 ( F_5 ( V_9 -> V_10 ) - V_7 ) ;
F_6 ( V_6 , V_7 ) ;
F_7 ( V_6 , F_8 ( V_6 ) , V_7 ) ;
F_9 ( V_6 ) ;
}
static int F_10 ( struct V_2 * V_3 , struct V_5 * V_6 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
if ( ! V_1 )
return 1 ;
F_2 ( V_6 , sizeof( struct V_11 ) ) ;
return - V_1 -> V_12 ;
}
static struct V_13 * F_11 ( struct V_5 * V_6 , struct V_13 * V_13 ,
void * V_14 , T_1 V_15 , T_2 V_16 ,
bool V_17 )
{
T_3 * V_18 = V_14 ;
T_1 V_19 = F_5 ( V_18 [ 0 ] ) ;
T_1 V_20 = F_5 ( V_18 [ 1 ] ) ;
T_1 V_21 = sizeof( struct V_11 ) + V_15 +
F_12 ( T_1 , V_20 + sizeof( V_22 ) , V_19 ) ;
if ( V_6 -> V_23 )
return V_13 ;
if ( ! F_13 ( V_6 , V_21 ) )
return NULL ;
V_13 = (struct V_13 * ) & F_8 ( V_6 ) [ 1 ] ;
F_14 ( V_6 , ( void * ) V_13 + V_15 ,
V_19 , V_20 , V_17 ) ;
return V_13 ;
}
static int F_15 ( struct V_5 * V_6 , struct V_13 * V_13 )
{
F_16 ( V_6 ) ;
return 0 ;
}
static int F_17 ( struct V_2 * V_3 , struct V_5 * V_6 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
T_1 V_7 , V_24 , V_15 ;
struct V_13 * V_13 ;
void * V_14 ;
V_22 V_25 = 0 ;
if ( ! V_1 )
return 1 ;
V_7 = sizeof( struct V_11 ) + sizeof( struct V_13 ) ;
if ( ! F_13 ( V_6 , V_7 ) )
goto V_26;
V_13 = (struct V_13 * ) & F_8 ( V_6 ) [ 1 ] ;
V_24 = V_13 -> V_27 << 2 ;
V_7 += V_24 ;
if ( ! F_13 ( V_6 , V_7 ) )
goto V_26;
V_13 = (struct V_13 * ) & F_8 ( V_6 ) [ 1 ] ;
V_15 = sizeof( struct V_13 ) + V_24 ;
if ( V_13 -> V_28 != 0 || F_18 ( V_13 , V_24 ) )
goto V_26;
V_15 = sizeof( struct V_13 ) + V_24 ;
F_3 ( V_6 ) -> V_10 = F_4 ( F_5 ( F_3 ( V_6 ) -> V_10 ) - V_7 ) ;
F_7 ( V_6 , F_8 ( V_6 ) , V_7 ) ;
V_14 = & V_13 [ 1 ] ;
if ( V_13 -> V_29 & V_30 ) {
T_4 V_29 = * ( T_4 * ) ( V_14 + V_25 ) ;
V_25 += V_31 ;
if ( V_29 & V_32 ) {
V_13 = F_11 ( V_6 , V_13 , V_14 + V_25 ,
V_15 , V_13 -> V_33 ,
! ! ( V_1 -> V_29 &
V_34 ) ) ;
if ( ! V_13 )
goto V_26;
V_14 = & V_13 [ 1 ] ;
V_25 += V_35 ;
}
}
if ( F_19 ( V_13 -> V_36 ) )
return F_15 ( V_6 , V_13 ) ;
F_6 ( V_6 , sizeof( struct V_11 ) + V_15 ) ;
F_9 ( V_6 ) ;
return - V_13 -> V_33 ;
V_26:
F_16 ( V_6 ) ;
return 0 ;
}
static struct V_5 * * F_20 ( struct V_5 * * V_37 ,
struct V_5 * V_6 ,
struct V_38 * V_39 )
{
const struct V_40 * V_41 ;
struct V_5 * * V_42 = NULL ;
T_2 V_43 = F_21 ( V_6 ) -> V_43 ;
const struct V_40 * * V_44 ;
F_22 () ;
V_44 = F_21 ( V_6 ) -> V_45 ? V_46 : V_47 ;
V_41 = F_23 ( V_44 [ V_43 ] ) ;
if ( ! V_41 || ! V_41 -> V_48 . V_49 )
goto V_50;
V_42 = V_41 -> V_48 . V_49 ( V_37 , V_6 ) ;
V_50:
F_24 () ;
return V_42 ;
}
static int F_25 ( struct V_5 * V_6 , int V_51 ,
struct V_38 * V_39 )
{
const struct V_40 * V_41 ;
T_2 V_43 = F_21 ( V_6 ) -> V_43 ;
int V_52 = - V_53 ;
const struct V_40 * * V_44 ;
F_26 ( V_6 , V_51 ) ;
F_22 () ;
V_44 = F_21 ( V_6 ) -> V_45 ? V_46 : V_47 ;
V_41 = F_23 ( V_44 [ V_43 ] ) ;
if ( F_27 ( ! V_41 || ! V_41 -> V_48 . V_54 ) )
goto V_50;
V_52 = V_41 -> V_48 . V_54 ( V_6 , V_51 ) ;
V_50:
F_24 () ;
return V_52 ;
}
static struct V_13 * F_28 ( struct V_5 * V_6 , unsigned int V_55 ,
struct V_13 * V_13 , void * V_14 ,
T_1 V_15 , struct V_56 * V_57 ,
bool V_17 )
{
T_3 * V_18 = V_14 ;
T_1 V_19 = F_5 ( V_18 [ 0 ] ) ;
T_1 V_20 = F_5 ( V_18 [ 1 ] ) ;
if ( V_6 -> V_23 )
return V_13 ;
if ( ! F_21 ( V_6 ) -> V_58 )
return NULL ;
V_13 = F_29 ( V_6 , ( void * ) V_13 , V_55 , V_15 ,
V_19 , V_20 , V_57 , V_17 ) ;
V_6 -> V_23 = 1 ;
return V_13 ;
}
static struct V_5 * * F_30 ( struct V_5 * * V_37 ,
struct V_5 * V_6 ,
struct V_38 * V_39 )
{
const struct V_40 * * V_44 ;
const struct V_40 * V_41 ;
struct V_5 * * V_42 = NULL ;
struct V_5 * V_59 ;
struct V_13 * V_13 ;
T_1 V_7 , V_24 , V_15 , V_55 ;
void * V_14 ;
V_22 V_25 = 0 ;
int V_60 = 1 ;
struct V_1 * V_1 = F_31 ( V_39 , struct V_1 , V_61 ) ;
struct V_56 V_57 ;
F_32 ( & V_57 ) ;
V_55 = F_33 ( V_6 ) ;
V_7 = V_55 + sizeof( * V_13 ) ;
V_13 = F_34 ( V_6 , V_55 ) ;
if ( F_35 ( V_6 , V_7 ) ) {
V_13 = F_36 ( V_6 , V_7 , V_55 ) ;
if ( F_19 ( ! V_13 ) )
goto V_62;
}
V_24 = V_13 -> V_27 << 2 ;
V_7 += V_24 ;
if ( F_35 ( V_6 , V_7 ) ) {
V_13 = F_36 ( V_6 , V_7 , V_55 ) ;
if ( F_19 ( ! V_13 ) )
goto V_62;
}
if ( F_19 ( V_13 -> V_36 ) || V_13 -> V_28 != 0 ||
F_18 ( V_13 , V_24 ) )
goto V_62;
V_15 = sizeof( * V_13 ) + V_24 ;
F_37 ( V_6 , V_13 , V_15 ) ;
V_14 = & V_13 [ 1 ] ;
if ( V_13 -> V_29 & V_30 ) {
T_4 V_29 = * ( T_4 * ) ( V_14 + V_25 ) ;
V_25 += V_31 ;
if ( V_29 & V_32 ) {
V_13 = F_28 ( V_6 , V_55 , V_13 ,
V_14 + V_25 , V_15 , & V_57 ,
! ! ( V_1 -> V_29 &
V_34 ) ) ;
if ( ! V_13 )
goto V_62;
V_14 = & V_13 [ 1 ] ;
V_25 += V_35 ;
}
}
F_38 ( V_6 , V_15 ) ;
V_60 = 0 ;
for ( V_59 = * V_37 ; V_59 ; V_59 = V_59 -> V_63 ) {
const struct V_13 * V_64 ;
if ( ! F_21 ( V_59 ) -> V_65 )
continue;
V_64 = (struct V_13 * ) ( V_59 -> V_14 + V_55 ) ;
if ( V_13 -> V_66 != V_64 -> V_66 ) {
F_21 ( V_59 ) -> V_65 = 0 ;
continue;
}
if ( V_13 -> V_27 && memcmp ( & V_13 [ 1 ] , & V_64 [ 1 ] ,
V_13 -> V_27 << 2 ) ) {
F_21 ( V_59 ) -> V_65 = 0 ;
continue;
}
}
F_22 () ;
V_44 = F_21 ( V_6 ) -> V_45 ? V_46 : V_47 ;
V_41 = F_23 ( V_44 [ V_13 -> V_33 ] ) ;
if ( F_39 ( ! V_41 || ! V_41 -> V_48 . V_49 ) )
goto V_50;
V_42 = V_41 -> V_48 . V_49 ( V_37 , V_6 ) ;
V_50:
F_24 () ;
V_62:
F_21 ( V_6 ) -> V_60 |= V_60 ;
F_40 ( V_6 , & V_57 ) ;
return V_42 ;
}
static int F_41 ( struct V_5 * V_6 , int V_51 ,
struct V_38 * V_39 )
{
const struct V_40 * * V_44 ;
struct V_13 * V_13 = (struct V_13 * ) ( V_6 -> V_14 + V_51 ) ;
const struct V_40 * V_41 ;
unsigned int V_67 ;
T_2 V_43 ;
int V_52 = - V_68 ;
V_43 = V_13 -> V_33 ;
V_67 = sizeof( * V_13 ) + ( V_13 -> V_27 << 2 ) ;
F_22 () ;
V_44 = F_21 ( V_6 ) -> V_45 ? V_46 : V_47 ;
V_41 = F_23 ( V_44 [ V_43 ] ) ;
if ( F_27 ( ! V_41 || ! V_41 -> V_48 . V_54 ) )
goto V_50;
V_52 = V_41 -> V_48 . V_54 ( V_6 , V_51 + V_67 ) ;
V_50:
F_24 () ;
return V_52 ;
}
static int F_42 ( struct V_69 * V_69 , struct V_1 * V_1 )
{
struct V_70 * V_71 = F_43 ( V_69 , V_72 ) ;
struct V_1 * V_73 ;
F_44 ( & V_71 -> V_74 ) ;
F_45 (fout, &fn->fou_list, list) {
if ( V_1 -> V_75 == V_73 -> V_75 ) {
F_46 ( & V_71 -> V_74 ) ;
return - V_76 ;
}
}
F_47 ( & V_1 -> V_77 , & V_71 -> V_78 ) ;
F_46 ( & V_71 -> V_74 ) ;
return 0 ;
}
static void F_48 ( struct V_1 * V_1 )
{
struct V_79 * V_2 = V_1 -> V_2 ;
struct V_2 * V_3 = V_2 -> V_3 ;
if ( V_3 -> V_80 == V_81 )
F_49 ( & V_1 -> V_61 ) ;
F_50 ( & V_1 -> V_77 ) ;
F_51 ( V_2 ) ;
F_52 ( V_1 ) ;
}
static int F_53 ( struct V_2 * V_3 , struct V_1 * V_1 , struct V_82 * V_83 )
{
F_54 ( V_3 ) -> V_84 = F_10 ;
V_1 -> V_12 = V_83 -> V_12 ;
V_1 -> V_61 . V_48 . V_49 = F_20 ;
V_1 -> V_61 . V_48 . V_54 = F_25 ;
V_1 -> V_61 . V_75 = V_83 -> V_85 . V_86 ;
V_1 -> V_61 . V_16 = V_83 -> V_12 ;
return 0 ;
}
static int F_55 ( struct V_2 * V_3 , struct V_1 * V_1 , struct V_82 * V_83 )
{
F_54 ( V_3 ) -> V_84 = F_17 ;
V_1 -> V_61 . V_48 . V_49 = F_30 ;
V_1 -> V_61 . V_48 . V_54 = F_41 ;
V_1 -> V_61 . V_75 = V_83 -> V_85 . V_86 ;
return 0 ;
}
static int F_56 ( struct V_69 * V_69 , struct V_82 * V_83 ,
struct V_79 * * V_87 )
{
struct V_79 * V_2 = NULL ;
struct V_1 * V_1 = NULL ;
struct V_2 * V_3 ;
int V_52 ;
V_52 = F_57 ( V_69 , & V_83 -> V_85 , & V_2 ) ;
if ( V_52 < 0 )
goto error;
V_1 = F_58 ( sizeof( * V_1 ) , V_88 ) ;
if ( ! V_1 ) {
V_52 = - V_89 ;
goto error;
}
V_3 = V_2 -> V_3 ;
V_1 -> V_29 = V_83 -> V_29 ;
V_1 -> V_75 = V_83 -> V_85 . V_86 ;
switch ( V_83 -> type ) {
case V_90 :
V_52 = F_53 ( V_3 , V_1 , V_83 ) ;
if ( V_52 )
goto error;
break;
case V_91 :
V_52 = F_55 ( V_3 , V_1 , V_83 ) ;
if ( V_52 )
goto error;
break;
default:
V_52 = - V_92 ;
goto error;
}
V_1 -> type = V_83 -> type ;
F_54 ( V_3 ) -> V_93 = 1 ;
F_59 () ;
V_3 -> V_4 = V_1 ;
V_1 -> V_2 = V_2 ;
F_60 ( V_3 ) ;
V_3 -> V_94 = V_95 ;
if ( V_83 -> V_85 . V_96 == V_81 ) {
V_52 = F_61 ( & V_1 -> V_61 ) ;
if ( V_52 )
goto error;
}
V_52 = F_42 ( V_69 , V_1 ) ;
if ( V_52 )
goto error;
if ( V_87 )
* V_87 = V_2 ;
return 0 ;
error:
F_52 ( V_1 ) ;
if ( V_2 )
F_51 ( V_2 ) ;
return V_52 ;
}
static int F_62 ( struct V_69 * V_69 , struct V_82 * V_83 )
{
struct V_70 * V_71 = F_43 ( V_69 , V_72 ) ;
T_3 V_75 = V_83 -> V_85 . V_86 ;
int V_52 = - V_92 ;
struct V_1 * V_1 ;
F_44 ( & V_71 -> V_74 ) ;
F_45 (fou, &fn->fou_list, list) {
if ( V_1 -> V_75 == V_75 ) {
F_48 ( V_1 ) ;
V_52 = 0 ;
break;
}
}
F_46 ( & V_71 -> V_74 ) ;
return V_52 ;
}
static int F_63 ( struct V_97 * V_98 ,
struct V_82 * V_83 )
{
memset ( V_83 , 0 , sizeof( * V_83 ) ) ;
V_83 -> V_85 . V_96 = V_81 ;
if ( V_98 -> V_99 [ V_100 ] ) {
T_2 V_96 = F_64 ( V_98 -> V_99 [ V_100 ] ) ;
if ( V_96 != V_81 )
return - V_92 ;
V_83 -> V_85 . V_96 = V_96 ;
}
if ( V_98 -> V_99 [ V_101 ] ) {
T_3 V_75 = F_65 ( V_98 -> V_99 [ V_101 ] ) ;
V_83 -> V_85 . V_86 = V_75 ;
}
if ( V_98 -> V_99 [ V_102 ] )
V_83 -> V_12 = F_64 ( V_98 -> V_99 [ V_102 ] ) ;
if ( V_98 -> V_99 [ V_103 ] )
V_83 -> type = F_64 ( V_98 -> V_99 [ V_103 ] ) ;
if ( V_98 -> V_99 [ V_104 ] )
V_83 -> V_29 |= V_34 ;
return 0 ;
}
static int F_66 ( struct V_5 * V_6 , struct V_97 * V_98 )
{
struct V_69 * V_69 = F_67 ( V_98 ) ;
struct V_82 V_83 ;
int V_52 ;
V_52 = F_63 ( V_98 , & V_83 ) ;
if ( V_52 )
return V_52 ;
return F_56 ( V_69 , & V_83 , NULL ) ;
}
static int F_68 ( struct V_5 * V_6 , struct V_97 * V_98 )
{
struct V_69 * V_69 = F_67 ( V_98 ) ;
struct V_82 V_83 ;
int V_52 ;
V_52 = F_63 ( V_98 , & V_83 ) ;
if ( V_52 )
return V_52 ;
return F_62 ( V_69 , & V_83 ) ;
}
static int F_69 ( struct V_1 * V_1 , struct V_5 * V_105 )
{
if ( F_70 ( V_105 , V_100 , V_1 -> V_2 -> V_3 -> V_80 ) ||
F_71 ( V_105 , V_101 , V_1 -> V_75 ) ||
F_70 ( V_105 , V_102 , V_1 -> V_12 ) ||
F_70 ( V_105 , V_103 , V_1 -> type ) )
return - 1 ;
if ( V_1 -> V_29 & V_34 )
if ( F_72 ( V_105 , V_104 ) )
return - 1 ;
return 0 ;
}
static int F_73 ( struct V_1 * V_1 , T_5 V_106 , T_5 V_107 ,
T_5 V_29 , struct V_5 * V_6 , T_2 V_108 )
{
void * V_109 ;
V_109 = F_74 ( V_6 , V_106 , V_107 , & V_110 , V_29 , V_108 ) ;
if ( ! V_109 )
return - V_89 ;
if ( F_69 ( V_1 , V_6 ) < 0 )
goto V_111;
F_75 ( V_6 , V_109 ) ;
return 0 ;
V_111:
F_76 ( V_6 , V_109 ) ;
return - V_112 ;
}
static int F_77 ( struct V_5 * V_6 , struct V_97 * V_98 )
{
struct V_69 * V_69 = F_67 ( V_98 ) ;
struct V_70 * V_71 = F_43 ( V_69 , V_72 ) ;
struct V_5 * V_105 ;
struct V_82 V_83 ;
struct V_1 * V_73 ;
T_3 V_75 ;
int V_113 ;
V_113 = F_63 ( V_98 , & V_83 ) ;
if ( V_113 )
return V_113 ;
V_75 = V_83 . V_85 . V_86 ;
if ( V_75 == 0 )
return - V_92 ;
V_105 = F_78 ( V_114 , V_88 ) ;
if ( ! V_105 )
return - V_89 ;
V_113 = - V_115 ;
F_44 ( & V_71 -> V_74 ) ;
F_45 (fout, &fn->fou_list, list) {
if ( V_75 == V_73 -> V_75 ) {
V_113 = F_73 ( V_73 , V_98 -> V_116 ,
V_98 -> V_117 , 0 , V_105 ,
V_98 -> V_118 -> V_108 ) ;
break;
}
}
F_46 ( & V_71 -> V_74 ) ;
if ( V_113 < 0 )
goto V_119;
return F_79 ( V_105 , V_98 ) ;
V_119:
F_80 ( V_105 ) ;
return V_113 ;
}
static int F_81 ( struct V_5 * V_6 , struct V_120 * V_121 )
{
struct V_69 * V_69 = F_82 ( V_6 -> V_3 ) ;
struct V_70 * V_71 = F_43 ( V_69 , V_72 ) ;
struct V_1 * V_73 ;
int V_122 = 0 , V_113 ;
F_44 ( & V_71 -> V_74 ) ;
F_45 (fout, &fn->fou_list, list) {
if ( V_122 ++ < V_121 -> args [ 0 ] )
continue;
V_113 = F_73 ( V_73 , F_83 ( V_121 -> V_6 ) . V_106 ,
V_121 -> V_123 -> V_124 , V_125 ,
V_6 , V_126 ) ;
if ( V_113 )
break;
}
F_46 ( & V_71 -> V_74 ) ;
V_121 -> args [ 0 ] = V_122 ;
return V_6 -> V_7 ;
}
T_1 F_84 ( struct V_127 * V_128 )
{
return sizeof( struct V_11 ) ;
}
T_1 F_85 ( struct V_127 * V_128 )
{
T_1 V_7 ;
bool V_129 = false ;
V_7 = sizeof( struct V_11 ) + sizeof( struct V_13 ) ;
if ( V_128 -> V_29 & V_130 ) {
V_7 += V_35 ;
V_129 = true ;
}
V_7 += V_129 ? V_31 : 0 ;
return V_7 ;
}
static void F_86 ( struct V_5 * V_6 , struct V_127 * V_128 ,
struct V_131 * V_132 , T_2 * V_12 , T_3 V_133 )
{
struct V_11 * V_134 ;
F_87 ( V_6 , sizeof( struct V_11 ) ) ;
F_9 ( V_6 ) ;
V_134 = F_8 ( V_6 ) ;
V_134 -> V_135 = V_128 -> V_136 ;
V_134 -> V_137 = V_133 ;
V_134 -> V_7 = F_4 ( V_6 -> V_7 ) ;
V_134 -> V_138 = 0 ;
F_88 ( ! ( V_128 -> V_29 & V_139 ) , V_6 ,
V_132 -> V_140 , V_132 -> V_141 , V_6 -> V_7 ) ;
* V_12 = V_142 ;
}
int F_89 ( struct V_5 * V_6 , struct V_127 * V_128 ,
T_2 * V_12 , struct V_131 * V_132 )
{
bool V_143 = ! ! ( V_128 -> V_29 & V_139 ) ;
int type = V_143 ? V_144 : V_145 ;
T_3 V_133 ;
V_6 = F_90 ( V_6 , V_143 , type ) ;
if ( F_91 ( V_6 ) )
return F_92 ( V_6 ) ;
V_133 = V_128 -> V_133 ? : F_93 ( F_94 ( V_6 -> V_146 ) ,
V_6 , 0 , 0 , false ) ;
F_86 ( V_6 , V_128 , V_132 , V_12 , V_133 ) ;
return 0 ;
}
int F_95 ( struct V_5 * V_6 , struct V_127 * V_128 ,
T_2 * V_12 , struct V_131 * V_132 )
{
bool V_143 = ! ! ( V_128 -> V_29 & V_139 ) ;
int type = V_143 ? V_144 : V_145 ;
struct V_13 * V_13 ;
T_1 V_15 , V_24 = 0 ;
T_3 V_133 ;
void * V_14 ;
bool V_129 = false ;
if ( ( V_128 -> V_29 & V_130 ) &&
V_6 -> V_147 == V_148 ) {
V_143 = false ;
V_24 += V_35 ;
type |= V_149 ;
V_129 = true ;
}
V_24 += V_129 ? V_31 : 0 ;
V_6 = F_90 ( V_6 , V_143 , type ) ;
if ( F_91 ( V_6 ) )
return F_92 ( V_6 ) ;
V_133 = V_128 -> V_133 ? : F_93 ( F_94 ( V_6 -> V_146 ) ,
V_6 , 0 , 0 , false ) ;
V_15 = sizeof( struct V_13 ) + V_24 ;
F_87 ( V_6 , V_15 ) ;
V_13 = (struct V_13 * ) V_6 -> V_14 ;
V_13 -> V_36 = 0 ;
V_13 -> V_28 = 0 ;
V_13 -> V_27 = V_24 >> 2 ;
V_13 -> V_29 = 0 ;
V_13 -> V_33 = * V_12 ;
V_14 = & V_13 [ 1 ] ;
if ( V_129 ) {
T_4 * V_29 = V_14 ;
V_13 -> V_29 |= V_30 ;
* V_29 = 0 ;
V_14 += V_31 ;
if ( type & V_149 ) {
V_22 V_150 = F_96 ( V_6 ) ;
T_3 * V_18 = V_14 ;
if ( V_150 < V_15 )
return - V_92 ;
V_150 -= V_15 ;
V_18 [ 0 ] = F_4 ( V_150 ) ;
V_18 [ 1 ] = F_4 ( V_150 + V_6 -> V_151 ) ;
if ( ! F_97 ( V_6 ) ) {
V_6 -> V_147 = V_152 ;
V_6 -> V_153 = 0 ;
}
* V_29 |= V_32 ;
V_14 += V_35 ;
}
}
F_86 ( V_6 , V_128 , V_132 , V_12 , V_133 ) ;
return 0 ;
}
static int F_98 ( void )
{
int V_113 ;
V_113 = F_99 ( & V_154 , V_155 ) ;
if ( V_113 < 0 ) {
F_100 ( L_1 ) ;
return V_113 ;
}
V_113 = F_99 ( & V_156 , V_157 ) ;
if ( V_113 < 0 ) {
F_100 ( L_2 ) ;
F_101 ( & V_154 , V_155 ) ;
return V_113 ;
}
return 0 ;
}
static void F_102 ( void )
{
F_101 ( & V_154 , V_155 ) ;
F_101 ( & V_156 , V_157 ) ;
}
static int F_98 ( void )
{
return 0 ;
}
static void F_102 ( void )
{
}
static T_6 int F_103 ( struct V_69 * V_69 )
{
struct V_70 * V_71 = F_43 ( V_69 , V_72 ) ;
F_104 ( & V_71 -> V_78 ) ;
F_105 ( & V_71 -> V_74 ) ;
return 0 ;
}
static T_7 void F_106 ( struct V_69 * V_69 )
{
struct V_70 * V_71 = F_43 ( V_69 , V_72 ) ;
struct V_1 * V_1 , * V_63 ;
F_44 ( & V_71 -> V_74 ) ;
F_107 (fou, next, &fn->fou_list, list)
F_48 ( V_1 ) ;
F_46 ( & V_71 -> V_74 ) ;
}
static int T_8 F_108 ( void )
{
int V_113 ;
V_113 = F_109 ( & V_158 ) ;
if ( V_113 )
goto exit;
V_113 = F_110 ( & V_110 ,
V_159 ) ;
if ( V_113 < 0 )
goto V_160;
V_113 = F_98 () ;
if ( V_113 == 0 )
return 0 ;
F_111 ( & V_110 ) ;
V_160:
F_112 ( & V_158 ) ;
exit:
return V_113 ;
}
static void T_9 F_113 ( void )
{
F_102 () ;
F_111 ( & V_110 ) ;
F_112 ( & V_158 ) ;
}
