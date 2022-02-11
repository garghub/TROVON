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
F_52 ( V_1 , V_82 ) ;
}
static int F_53 ( struct V_2 * V_3 , struct V_1 * V_1 , struct V_83 * V_84 )
{
F_54 ( V_3 ) -> V_85 = F_10 ;
V_1 -> V_12 = V_84 -> V_12 ;
V_1 -> V_61 . V_48 . V_49 = F_20 ;
V_1 -> V_61 . V_48 . V_54 = F_25 ;
V_1 -> V_61 . V_75 = V_84 -> V_86 . V_87 ;
V_1 -> V_61 . V_16 = V_84 -> V_12 ;
return 0 ;
}
static int F_55 ( struct V_2 * V_3 , struct V_1 * V_1 , struct V_83 * V_84 )
{
F_54 ( V_3 ) -> V_85 = F_17 ;
V_1 -> V_61 . V_48 . V_49 = F_30 ;
V_1 -> V_61 . V_48 . V_54 = F_41 ;
V_1 -> V_61 . V_75 = V_84 -> V_86 . V_87 ;
return 0 ;
}
static int F_56 ( struct V_69 * V_69 , struct V_83 * V_84 ,
struct V_79 * * V_88 )
{
struct V_79 * V_2 = NULL ;
struct V_1 * V_1 = NULL ;
struct V_2 * V_3 ;
int V_52 ;
V_52 = F_57 ( V_69 , & V_84 -> V_86 , & V_2 ) ;
if ( V_52 < 0 )
goto error;
V_1 = F_58 ( sizeof( * V_1 ) , V_89 ) ;
if ( ! V_1 ) {
V_52 = - V_90 ;
goto error;
}
V_3 = V_2 -> V_3 ;
V_1 -> V_29 = V_84 -> V_29 ;
V_1 -> V_75 = V_84 -> V_86 . V_87 ;
switch ( V_84 -> type ) {
case V_91 :
V_52 = F_53 ( V_3 , V_1 , V_84 ) ;
if ( V_52 )
goto error;
break;
case V_92 :
V_52 = F_55 ( V_3 , V_1 , V_84 ) ;
if ( V_52 )
goto error;
break;
default:
V_52 = - V_93 ;
goto error;
}
V_1 -> type = V_84 -> type ;
F_54 ( V_3 ) -> V_94 = 1 ;
F_59 () ;
V_3 -> V_4 = V_1 ;
V_1 -> V_2 = V_2 ;
F_60 ( V_3 ) ;
V_3 -> V_95 = V_96 ;
if ( V_84 -> V_86 . V_97 == V_81 ) {
V_52 = F_61 ( V_69 , & V_1 -> V_61 ) ;
if ( V_52 )
goto error;
}
V_52 = F_42 ( V_69 , V_1 ) ;
if ( V_52 )
goto error;
if ( V_88 )
* V_88 = V_2 ;
return 0 ;
error:
F_62 ( V_1 ) ;
if ( V_2 )
F_51 ( V_2 ) ;
return V_52 ;
}
static int F_63 ( struct V_69 * V_69 , struct V_83 * V_84 )
{
struct V_70 * V_71 = F_43 ( V_69 , V_72 ) ;
T_3 V_75 = V_84 -> V_86 . V_87 ;
int V_52 = - V_93 ;
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
static int F_64 ( struct V_98 * V_99 ,
struct V_83 * V_84 )
{
memset ( V_84 , 0 , sizeof( * V_84 ) ) ;
V_84 -> V_86 . V_97 = V_81 ;
if ( V_99 -> V_100 [ V_101 ] ) {
T_2 V_97 = F_65 ( V_99 -> V_100 [ V_101 ] ) ;
if ( V_97 != V_81 )
return - V_93 ;
V_84 -> V_86 . V_97 = V_97 ;
}
if ( V_99 -> V_100 [ V_102 ] ) {
T_3 V_75 = F_66 ( V_99 -> V_100 [ V_102 ] ) ;
V_84 -> V_86 . V_87 = V_75 ;
}
if ( V_99 -> V_100 [ V_103 ] )
V_84 -> V_12 = F_65 ( V_99 -> V_100 [ V_103 ] ) ;
if ( V_99 -> V_100 [ V_104 ] )
V_84 -> type = F_65 ( V_99 -> V_100 [ V_104 ] ) ;
if ( V_99 -> V_100 [ V_105 ] )
V_84 -> V_29 |= V_34 ;
return 0 ;
}
static int F_67 ( struct V_5 * V_6 , struct V_98 * V_99 )
{
struct V_69 * V_69 = F_68 ( V_99 ) ;
struct V_83 V_84 ;
int V_52 ;
V_52 = F_64 ( V_99 , & V_84 ) ;
if ( V_52 )
return V_52 ;
return F_56 ( V_69 , & V_84 , NULL ) ;
}
static int F_69 ( struct V_5 * V_6 , struct V_98 * V_99 )
{
struct V_69 * V_69 = F_68 ( V_99 ) ;
struct V_83 V_84 ;
int V_52 ;
V_52 = F_64 ( V_99 , & V_84 ) ;
if ( V_52 )
return V_52 ;
return F_63 ( V_69 , & V_84 ) ;
}
static int F_70 ( struct V_1 * V_1 , struct V_5 * V_106 )
{
if ( F_71 ( V_106 , V_101 , V_1 -> V_2 -> V_3 -> V_80 ) ||
F_72 ( V_106 , V_102 , V_1 -> V_75 ) ||
F_71 ( V_106 , V_103 , V_1 -> V_12 ) ||
F_71 ( V_106 , V_104 , V_1 -> type ) )
return - 1 ;
if ( V_1 -> V_29 & V_34 )
if ( F_73 ( V_106 , V_105 ) )
return - 1 ;
return 0 ;
}
static int F_74 ( struct V_1 * V_1 , T_5 V_107 , T_5 V_108 ,
T_5 V_29 , struct V_5 * V_6 , T_2 V_109 )
{
void * V_110 ;
V_110 = F_75 ( V_6 , V_107 , V_108 , & V_111 , V_29 , V_109 ) ;
if ( ! V_110 )
return - V_90 ;
if ( F_70 ( V_1 , V_6 ) < 0 )
goto V_112;
F_76 ( V_6 , V_110 ) ;
return 0 ;
V_112:
F_77 ( V_6 , V_110 ) ;
return - V_113 ;
}
static int F_78 ( struct V_5 * V_6 , struct V_98 * V_99 )
{
struct V_69 * V_69 = F_68 ( V_99 ) ;
struct V_70 * V_71 = F_43 ( V_69 , V_72 ) ;
struct V_5 * V_106 ;
struct V_83 V_84 ;
struct V_1 * V_73 ;
T_3 V_75 ;
int V_114 ;
V_114 = F_64 ( V_99 , & V_84 ) ;
if ( V_114 )
return V_114 ;
V_75 = V_84 . V_86 . V_87 ;
if ( V_75 == 0 )
return - V_93 ;
V_106 = F_79 ( V_115 , V_89 ) ;
if ( ! V_106 )
return - V_90 ;
V_114 = - V_116 ;
F_44 ( & V_71 -> V_74 ) ;
F_45 (fout, &fn->fou_list, list) {
if ( V_75 == V_73 -> V_75 ) {
V_114 = F_74 ( V_73 , V_99 -> V_117 ,
V_99 -> V_118 , 0 , V_106 ,
V_99 -> V_119 -> V_109 ) ;
break;
}
}
F_46 ( & V_71 -> V_74 ) ;
if ( V_114 < 0 )
goto V_120;
return F_80 ( V_106 , V_99 ) ;
V_120:
F_81 ( V_106 ) ;
return V_114 ;
}
static int F_82 ( struct V_5 * V_6 , struct V_121 * V_122 )
{
struct V_69 * V_69 = F_83 ( V_6 -> V_3 ) ;
struct V_70 * V_71 = F_43 ( V_69 , V_72 ) ;
struct V_1 * V_73 ;
int V_123 = 0 , V_114 ;
F_44 ( & V_71 -> V_74 ) ;
F_45 (fout, &fn->fou_list, list) {
if ( V_123 ++ < V_122 -> args [ 0 ] )
continue;
V_114 = F_74 ( V_73 , F_84 ( V_122 -> V_6 ) . V_107 ,
V_122 -> V_124 -> V_125 , V_126 ,
V_6 , V_127 ) ;
if ( V_114 )
break;
}
F_46 ( & V_71 -> V_74 ) ;
V_122 -> args [ 0 ] = V_123 ;
return V_6 -> V_7 ;
}
T_1 F_85 ( struct V_128 * V_129 )
{
return sizeof( struct V_11 ) ;
}
T_1 F_86 ( struct V_128 * V_129 )
{
T_1 V_7 ;
bool V_130 = false ;
V_7 = sizeof( struct V_11 ) + sizeof( struct V_13 ) ;
if ( V_129 -> V_29 & V_131 ) {
V_7 += V_35 ;
V_130 = true ;
}
V_7 += V_130 ? V_31 : 0 ;
return V_7 ;
}
static void F_87 ( struct V_5 * V_6 , struct V_128 * V_129 ,
struct V_132 * V_133 , T_2 * V_12 , T_3 V_134 )
{
struct V_11 * V_135 ;
F_88 ( V_6 , sizeof( struct V_11 ) ) ;
F_9 ( V_6 ) ;
V_135 = F_8 ( V_6 ) ;
V_135 -> V_136 = V_129 -> V_137 ;
V_135 -> V_138 = V_134 ;
V_135 -> V_7 = F_4 ( V_6 -> V_7 ) ;
V_135 -> V_139 = 0 ;
F_89 ( ! ( V_129 -> V_29 & V_140 ) , V_6 ,
V_133 -> V_141 , V_133 -> V_142 , V_6 -> V_7 ) ;
* V_12 = V_143 ;
}
int F_90 ( struct V_5 * V_6 , struct V_128 * V_129 ,
T_2 * V_12 , struct V_132 * V_133 )
{
bool V_144 = ! ! ( V_129 -> V_29 & V_140 ) ;
int type = V_144 ? V_145 : V_146 ;
T_3 V_134 ;
V_6 = F_91 ( V_6 , V_144 , type ) ;
if ( F_92 ( V_6 ) )
return F_93 ( V_6 ) ;
V_134 = V_129 -> V_134 ? : F_94 ( F_95 ( V_6 -> V_147 ) ,
V_6 , 0 , 0 , false ) ;
F_87 ( V_6 , V_129 , V_133 , V_12 , V_134 ) ;
return 0 ;
}
int F_96 ( struct V_5 * V_6 , struct V_128 * V_129 ,
T_2 * V_12 , struct V_132 * V_133 )
{
bool V_144 = ! ! ( V_129 -> V_29 & V_140 ) ;
int type = V_144 ? V_145 : V_146 ;
struct V_13 * V_13 ;
T_1 V_15 , V_24 = 0 ;
T_3 V_134 ;
void * V_14 ;
bool V_130 = false ;
if ( ( V_129 -> V_29 & V_131 ) &&
V_6 -> V_148 == V_149 ) {
V_144 = false ;
V_24 += V_35 ;
type |= V_150 ;
V_130 = true ;
}
V_24 += V_130 ? V_31 : 0 ;
V_6 = F_91 ( V_6 , V_144 , type ) ;
if ( F_92 ( V_6 ) )
return F_93 ( V_6 ) ;
V_134 = V_129 -> V_134 ? : F_94 ( F_95 ( V_6 -> V_147 ) ,
V_6 , 0 , 0 , false ) ;
V_15 = sizeof( struct V_13 ) + V_24 ;
F_88 ( V_6 , V_15 ) ;
V_13 = (struct V_13 * ) V_6 -> V_14 ;
V_13 -> V_36 = 0 ;
V_13 -> V_28 = 0 ;
V_13 -> V_27 = V_24 >> 2 ;
V_13 -> V_29 = 0 ;
V_13 -> V_33 = * V_12 ;
V_14 = & V_13 [ 1 ] ;
if ( V_130 ) {
T_4 * V_29 = V_14 ;
V_13 -> V_29 |= V_30 ;
* V_29 = 0 ;
V_14 += V_31 ;
if ( type & V_150 ) {
V_22 V_151 = F_97 ( V_6 ) ;
T_3 * V_18 = V_14 ;
if ( V_151 < V_15 )
return - V_93 ;
V_151 -= V_15 ;
V_18 [ 0 ] = F_4 ( V_151 ) ;
V_18 [ 1 ] = F_4 ( V_151 + V_6 -> V_152 ) ;
if ( ! F_98 ( V_6 ) ) {
V_6 -> V_148 = V_153 ;
V_6 -> V_154 = 0 ;
}
* V_29 |= V_32 ;
V_14 += V_35 ;
}
}
F_87 ( V_6 , V_129 , V_133 , V_12 , V_134 ) ;
return 0 ;
}
static int F_99 ( void )
{
int V_114 ;
V_114 = F_100 ( & V_155 , V_156 ) ;
if ( V_114 < 0 ) {
F_101 ( L_1 ) ;
return V_114 ;
}
V_114 = F_100 ( & V_157 , V_158 ) ;
if ( V_114 < 0 ) {
F_101 ( L_2 ) ;
F_102 ( & V_155 , V_156 ) ;
return V_114 ;
}
return 0 ;
}
static void F_103 ( void )
{
F_102 ( & V_155 , V_156 ) ;
F_102 ( & V_157 , V_158 ) ;
}
static int F_99 ( void )
{
return 0 ;
}
static void F_103 ( void )
{
}
static T_6 int F_104 ( struct V_69 * V_69 )
{
struct V_70 * V_71 = F_43 ( V_69 , V_72 ) ;
F_105 ( & V_71 -> V_78 ) ;
F_106 ( & V_71 -> V_74 ) ;
return 0 ;
}
static T_7 void F_107 ( struct V_69 * V_69 )
{
struct V_70 * V_71 = F_43 ( V_69 , V_72 ) ;
struct V_1 * V_1 , * V_63 ;
F_44 ( & V_71 -> V_74 ) ;
F_108 (fou, next, &fn->fou_list, list)
F_48 ( V_1 ) ;
F_46 ( & V_71 -> V_74 ) ;
}
static int T_8 F_109 ( void )
{
int V_114 ;
V_114 = F_110 ( & V_159 ) ;
if ( V_114 )
goto exit;
V_114 = F_111 ( & V_111 ,
V_160 ) ;
if ( V_114 < 0 )
goto V_161;
V_114 = F_99 () ;
if ( V_114 == 0 )
return 0 ;
F_112 ( & V_111 ) ;
V_161:
F_113 ( & V_159 ) ;
exit:
return V_114 ;
}
static void T_9 F_114 ( void )
{
F_103 () ;
F_112 ( & V_111 ) ;
F_113 ( & V_159 ) ;
}
