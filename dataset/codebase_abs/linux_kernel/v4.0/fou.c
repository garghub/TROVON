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
T_1 V_21 = V_15 + F_12 ( T_1 , V_20 + sizeof( V_22 ) , V_19 ) ;
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
T_1 V_7 , V_23 , V_15 ;
struct V_13 * V_13 ;
void * V_14 ;
V_22 V_24 = 0 ;
if ( ! V_1 )
return 1 ;
V_7 = sizeof( struct V_11 ) + sizeof( struct V_13 ) ;
if ( ! F_13 ( V_6 , V_7 ) )
goto V_25;
V_13 = (struct V_13 * ) & F_8 ( V_6 ) [ 1 ] ;
V_23 = V_13 -> V_26 << 2 ;
V_7 += V_23 ;
if ( ! F_13 ( V_6 , V_7 ) )
goto V_25;
V_13 = (struct V_13 * ) & F_8 ( V_6 ) [ 1 ] ;
V_15 = sizeof( struct V_13 ) + V_23 ;
if ( V_13 -> V_27 != 0 || F_18 ( V_13 , V_23 ) )
goto V_25;
V_15 = sizeof( struct V_13 ) + V_23 ;
F_3 ( V_6 ) -> V_10 = F_4 ( F_5 ( F_3 ( V_6 ) -> V_10 ) - V_7 ) ;
F_7 ( V_6 , F_8 ( V_6 ) , V_7 ) ;
V_14 = & V_13 [ 1 ] ;
if ( V_13 -> V_28 & V_29 ) {
T_4 V_28 = * ( T_4 * ) ( V_14 + V_24 ) ;
V_24 += V_30 ;
if ( V_28 & V_31 ) {
V_13 = F_11 ( V_6 , V_13 , V_14 + V_24 ,
V_15 , V_13 -> V_32 ,
! ! ( V_1 -> V_28 &
V_33 ) ) ;
if ( ! V_13 )
goto V_25;
V_14 = & V_13 [ 1 ] ;
V_24 += V_34 ;
}
}
if ( F_19 ( V_13 -> V_35 ) )
return F_15 ( V_6 , V_13 ) ;
F_6 ( V_6 , sizeof( struct V_11 ) + V_15 ) ;
F_9 ( V_6 ) ;
return - V_13 -> V_32 ;
V_25:
F_16 ( V_6 ) ;
return 0 ;
}
static struct V_5 * * F_20 ( struct V_5 * * V_36 ,
struct V_5 * V_6 ,
struct V_37 * V_38 )
{
const struct V_39 * V_40 ;
struct V_5 * * V_41 = NULL ;
T_2 V_42 = F_21 ( V_6 ) -> V_42 ;
const struct V_39 * * V_43 ;
F_22 () ;
V_43 = F_21 ( V_6 ) -> V_44 ? V_45 : V_46 ;
V_40 = F_23 ( V_43 [ V_42 ] ) ;
if ( ! V_40 || ! V_40 -> V_47 . V_48 )
goto V_49;
V_41 = V_40 -> V_47 . V_48 ( V_36 , V_6 ) ;
V_49:
F_24 () ;
return V_41 ;
}
static int F_25 ( struct V_5 * V_6 , int V_50 ,
struct V_37 * V_38 )
{
const struct V_39 * V_40 ;
T_2 V_42 = F_21 ( V_6 ) -> V_42 ;
int V_51 = - V_52 ;
const struct V_39 * * V_43 ;
F_26 ( V_6 , V_50 ) ;
F_22 () ;
V_43 = F_21 ( V_6 ) -> V_44 ? V_45 : V_46 ;
V_40 = F_23 ( V_43 [ V_42 ] ) ;
if ( F_27 ( ! V_40 || ! V_40 -> V_47 . V_53 ) )
goto V_49;
V_51 = V_40 -> V_47 . V_53 ( V_6 , V_50 ) ;
V_49:
F_24 () ;
return V_51 ;
}
static struct V_13 * F_28 ( struct V_5 * V_6 , unsigned int V_54 ,
struct V_13 * V_13 , void * V_14 ,
T_1 V_15 , T_2 V_16 ,
struct V_55 * V_56 , bool V_17 )
{
T_3 * V_18 = V_14 ;
T_1 V_19 = F_5 ( V_18 [ 0 ] ) ;
T_1 V_20 = F_5 ( V_18 [ 1 ] ) ;
T_1 V_21 = V_15 + F_12 ( T_1 , V_20 + sizeof( V_22 ) , V_19 ) ;
if ( V_6 -> V_57 )
return NULL ;
if ( ! F_21 ( V_6 ) -> V_58 )
return NULL ;
if ( F_29 ( V_6 , V_54 + V_21 ) ) {
V_13 = F_30 ( V_6 , V_54 + V_21 , V_54 ) ;
if ( ! V_13 )
return NULL ;
}
F_31 ( V_6 , ( void * ) V_13 + V_15 ,
V_19 , V_20 , V_56 , V_17 ) ;
V_6 -> V_57 = 1 ;
return V_13 ;
}
static struct V_5 * * F_32 ( struct V_5 * * V_36 ,
struct V_5 * V_6 ,
struct V_37 * V_38 )
{
const struct V_39 * * V_43 ;
const struct V_39 * V_40 ;
struct V_5 * * V_41 = NULL ;
struct V_5 * V_59 ;
struct V_13 * V_13 ;
T_1 V_7 , V_23 , V_15 , V_54 ;
void * V_14 ;
V_22 V_24 = 0 ;
int V_60 = 1 ;
struct V_1 * V_1 = F_33 ( V_38 , struct V_1 , V_61 ) ;
struct V_55 V_56 ;
F_34 ( & V_56 ) ;
V_54 = F_35 ( V_6 ) ;
V_7 = V_54 + sizeof( * V_13 ) ;
V_13 = F_36 ( V_6 , V_54 ) ;
if ( F_29 ( V_6 , V_7 ) ) {
V_13 = F_30 ( V_6 , V_7 , V_54 ) ;
if ( F_19 ( ! V_13 ) )
goto V_62;
}
V_23 = V_13 -> V_26 << 2 ;
V_7 += V_23 ;
if ( F_29 ( V_6 , V_7 ) ) {
V_13 = F_30 ( V_6 , V_7 , V_54 ) ;
if ( F_19 ( ! V_13 ) )
goto V_62;
}
if ( F_19 ( V_13 -> V_35 ) || V_13 -> V_27 != 0 ||
F_18 ( V_13 , V_23 ) )
goto V_62;
V_15 = sizeof( * V_13 ) + V_23 ;
F_37 ( V_6 , V_13 , V_15 ) ;
V_14 = & V_13 [ 1 ] ;
if ( V_13 -> V_28 & V_29 ) {
T_4 V_28 = * ( T_4 * ) ( V_14 + V_24 ) ;
V_24 += V_30 ;
if ( V_28 & V_31 ) {
V_13 = F_28 ( V_6 , V_54 , V_13 ,
V_14 + V_24 , V_15 ,
V_13 -> V_32 , & V_56 ,
! ! ( V_1 -> V_28 &
V_33 ) ) ;
if ( ! V_13 )
goto V_62;
V_14 = & V_13 [ 1 ] ;
V_24 += V_34 ;
}
}
F_38 ( V_6 , V_15 ) ;
V_60 = 0 ;
for ( V_59 = * V_36 ; V_59 ; V_59 = V_59 -> V_63 ) {
const struct V_13 * V_64 ;
if ( ! F_21 ( V_59 ) -> V_65 )
continue;
V_64 = (struct V_13 * ) ( V_59 -> V_14 + V_54 ) ;
if ( V_13 -> V_66 != V_64 -> V_66 ) {
F_21 ( V_59 ) -> V_65 = 0 ;
continue;
}
if ( V_13 -> V_26 && memcmp ( & V_13 [ 1 ] , & V_64 [ 1 ] ,
V_13 -> V_26 << 2 ) ) {
F_21 ( V_59 ) -> V_65 = 0 ;
continue;
}
}
F_22 () ;
V_43 = F_21 ( V_6 ) -> V_44 ? V_45 : V_46 ;
V_40 = F_23 ( V_43 [ V_13 -> V_32 ] ) ;
if ( F_27 ( ! V_40 || ! V_40 -> V_47 . V_48 ) )
goto V_49;
V_41 = V_40 -> V_47 . V_48 ( V_36 , V_6 ) ;
V_49:
F_24 () ;
V_62:
F_21 ( V_6 ) -> V_60 |= V_60 ;
F_39 ( V_6 , & V_56 ) ;
return V_41 ;
}
static int F_40 ( struct V_5 * V_6 , int V_50 ,
struct V_37 * V_38 )
{
const struct V_39 * * V_43 ;
struct V_13 * V_13 = (struct V_13 * ) ( V_6 -> V_14 + V_50 ) ;
const struct V_39 * V_40 ;
unsigned int V_67 ;
T_2 V_42 ;
int V_51 = - V_68 ;
V_42 = V_13 -> V_32 ;
V_67 = sizeof( * V_13 ) + ( V_13 -> V_26 << 2 ) ;
F_22 () ;
V_43 = F_21 ( V_6 ) -> V_44 ? V_45 : V_46 ;
V_40 = F_23 ( V_43 [ V_42 ] ) ;
if ( F_27 ( ! V_40 || ! V_40 -> V_47 . V_53 ) )
goto V_49;
V_51 = V_40 -> V_47 . V_53 ( V_6 , V_50 + V_67 ) ;
V_49:
F_24 () ;
return V_51 ;
}
static int F_41 ( struct V_1 * V_1 )
{
struct V_1 * V_69 ;
F_42 ( & V_70 ) ;
F_43 (fout, &fou_list, list) {
if ( V_1 -> V_71 == V_69 -> V_71 ) {
F_44 ( & V_70 ) ;
return - V_72 ;
}
}
F_45 ( & V_1 -> V_73 , & V_74 ) ;
F_44 ( & V_70 ) ;
return 0 ;
}
static void F_46 ( struct V_1 * V_1 )
{
struct V_75 * V_2 = V_1 -> V_2 ;
struct V_2 * V_3 = V_2 -> V_3 ;
F_47 ( & V_1 -> V_61 ) ;
F_48 ( & V_1 -> V_73 ) ;
V_3 -> V_4 = NULL ;
F_49 ( V_2 ) ;
F_50 ( V_1 ) ;
}
static int F_51 ( struct V_2 * V_3 , struct V_1 * V_1 , struct V_76 * V_77 )
{
F_52 ( V_3 ) -> V_78 = F_10 ;
V_1 -> V_12 = V_77 -> V_12 ;
V_1 -> V_61 . V_47 . V_48 = F_20 ;
V_1 -> V_61 . V_47 . V_53 = F_25 ;
V_1 -> V_61 . V_71 = V_77 -> V_79 . V_80 ;
V_1 -> V_61 . V_16 = V_77 -> V_12 ;
return 0 ;
}
static int F_53 ( struct V_2 * V_3 , struct V_1 * V_1 , struct V_76 * V_77 )
{
F_52 ( V_3 ) -> V_78 = F_17 ;
V_1 -> V_61 . V_47 . V_48 = F_32 ;
V_1 -> V_61 . V_47 . V_53 = F_40 ;
V_1 -> V_61 . V_71 = V_77 -> V_79 . V_80 ;
return 0 ;
}
static int F_54 ( struct V_81 * V_81 , struct V_76 * V_77 ,
struct V_75 * * V_82 )
{
struct V_1 * V_1 = NULL ;
int V_51 ;
struct V_75 * V_2 = NULL ;
struct V_2 * V_3 ;
V_51 = F_55 ( V_81 , & V_77 -> V_79 , & V_2 ) ;
if ( V_51 < 0 )
goto error;
V_1 = F_56 ( sizeof( * V_1 ) , V_83 ) ;
if ( ! V_1 ) {
V_51 = - V_84 ;
goto error;
}
V_3 = V_2 -> V_3 ;
V_1 -> V_28 = V_77 -> V_28 ;
V_1 -> V_71 = V_77 -> V_79 . V_80 ;
switch ( V_77 -> type ) {
case V_85 :
V_51 = F_51 ( V_3 , V_1 , V_77 ) ;
if ( V_51 )
goto error;
break;
case V_86 :
V_51 = F_53 ( V_3 , V_1 , V_77 ) ;
if ( V_51 )
goto error;
break;
default:
V_51 = - V_87 ;
goto error;
}
F_52 ( V_3 ) -> V_88 = 1 ;
F_57 () ;
V_3 -> V_4 = V_1 ;
V_1 -> V_2 = V_2 ;
F_58 ( V_3 ) ;
V_3 -> V_89 = V_90 ;
if ( V_77 -> V_79 . V_91 == V_92 ) {
V_51 = F_59 ( & V_1 -> V_61 ) ;
if ( V_51 )
goto error;
}
V_51 = F_41 ( V_1 ) ;
if ( V_51 )
goto error;
if ( V_82 )
* V_82 = V_2 ;
return 0 ;
error:
F_50 ( V_1 ) ;
if ( V_2 )
F_49 ( V_2 ) ;
return V_51 ;
}
static int F_60 ( struct V_81 * V_81 , struct V_76 * V_77 )
{
struct V_1 * V_1 ;
V_22 V_71 = V_77 -> V_79 . V_80 ;
int V_51 = - V_87 ;
F_42 ( & V_70 ) ;
F_43 (fou, &fou_list, list) {
if ( V_1 -> V_71 == V_71 ) {
F_47 ( & V_1 -> V_61 ) ;
F_46 ( V_1 ) ;
V_51 = 0 ;
break;
}
}
F_44 ( & V_70 ) ;
return V_51 ;
}
static int F_61 ( struct V_93 * V_94 ,
struct V_76 * V_77 )
{
memset ( V_77 , 0 , sizeof( * V_77 ) ) ;
V_77 -> V_79 . V_91 = V_92 ;
if ( V_94 -> V_95 [ V_96 ] ) {
T_2 V_91 = F_62 ( V_94 -> V_95 [ V_96 ] ) ;
if ( V_91 != V_92 && V_91 != V_97 )
return - V_87 ;
V_77 -> V_79 . V_91 = V_91 ;
}
if ( V_94 -> V_95 [ V_98 ] ) {
V_22 V_71 = F_63 ( V_94 -> V_95 [ V_98 ] ) ;
V_77 -> V_79 . V_80 = V_71 ;
}
if ( V_94 -> V_95 [ V_99 ] )
V_77 -> V_12 = F_62 ( V_94 -> V_95 [ V_99 ] ) ;
if ( V_94 -> V_95 [ V_100 ] )
V_77 -> type = F_62 ( V_94 -> V_95 [ V_100 ] ) ;
if ( V_94 -> V_95 [ V_101 ] )
V_77 -> V_28 |= V_33 ;
return 0 ;
}
static int F_64 ( struct V_5 * V_6 , struct V_93 * V_94 )
{
struct V_76 V_77 ;
int V_51 ;
V_51 = F_61 ( V_94 , & V_77 ) ;
if ( V_51 )
return V_51 ;
return F_54 ( & V_102 , & V_77 , NULL ) ;
}
static int F_65 ( struct V_5 * V_6 , struct V_93 * V_94 )
{
struct V_76 V_77 ;
F_61 ( V_94 , & V_77 ) ;
return F_60 ( & V_102 , & V_77 ) ;
}
T_1 F_66 ( struct V_103 * V_104 )
{
return sizeof( struct V_11 ) ;
}
T_1 F_67 ( struct V_103 * V_104 )
{
T_1 V_7 ;
bool V_105 = false ;
V_7 = sizeof( struct V_11 ) + sizeof( struct V_13 ) ;
if ( V_104 -> V_28 & V_106 ) {
V_7 += V_34 ;
V_105 = true ;
}
V_7 += V_105 ? V_30 : 0 ;
return V_7 ;
}
static void F_68 ( struct V_5 * V_6 , struct V_103 * V_104 ,
struct V_107 * V_108 , T_2 * V_12 , T_3 V_109 )
{
struct V_11 * V_110 ;
F_69 ( V_6 , sizeof( struct V_11 ) ) ;
F_9 ( V_6 ) ;
V_110 = F_8 ( V_6 ) ;
V_110 -> V_111 = V_104 -> V_112 ;
V_110 -> V_113 = V_109 ;
V_110 -> V_7 = F_4 ( V_6 -> V_7 ) ;
V_110 -> V_114 = 0 ;
F_70 ( ! ( V_104 -> V_28 & V_115 ) , V_6 ,
V_108 -> V_116 , V_108 -> V_117 , V_6 -> V_7 ) ;
* V_12 = V_118 ;
}
int F_71 ( struct V_5 * V_6 , struct V_103 * V_104 ,
T_2 * V_12 , struct V_107 * V_108 )
{
bool V_119 = ! ! ( V_104 -> V_28 & V_115 ) ;
int type = V_119 ? V_120 : V_121 ;
T_3 V_109 ;
V_6 = F_72 ( V_6 , V_119 , type ) ;
if ( F_73 ( V_6 ) )
return F_74 ( V_6 ) ;
V_109 = V_104 -> V_109 ? : F_75 ( F_76 ( V_6 -> V_122 ) ,
V_6 , 0 , 0 , false ) ;
F_68 ( V_6 , V_104 , V_108 , V_12 , V_109 ) ;
return 0 ;
}
int F_77 ( struct V_5 * V_6 , struct V_103 * V_104 ,
T_2 * V_12 , struct V_107 * V_108 )
{
bool V_119 = ! ! ( V_104 -> V_28 & V_115 ) ;
int type = V_119 ? V_120 : V_121 ;
struct V_13 * V_13 ;
T_1 V_15 , V_23 = 0 ;
T_3 V_109 ;
void * V_14 ;
bool V_105 = false ;
if ( ( V_104 -> V_28 & V_106 ) &&
V_6 -> V_123 == V_124 ) {
V_119 = false ;
V_23 += V_34 ;
type |= V_125 ;
V_105 = true ;
}
V_23 += V_105 ? V_30 : 0 ;
V_6 = F_72 ( V_6 , V_119 , type ) ;
if ( F_73 ( V_6 ) )
return F_74 ( V_6 ) ;
V_109 = V_104 -> V_109 ? : F_75 ( F_76 ( V_6 -> V_122 ) ,
V_6 , 0 , 0 , false ) ;
V_15 = sizeof( struct V_13 ) + V_23 ;
F_69 ( V_6 , V_15 ) ;
V_13 = (struct V_13 * ) V_6 -> V_14 ;
V_13 -> V_35 = 0 ;
V_13 -> V_27 = 0 ;
V_13 -> V_26 = V_23 >> 2 ;
V_13 -> V_28 = 0 ;
V_13 -> V_32 = * V_12 ;
V_14 = & V_13 [ 1 ] ;
if ( V_105 ) {
T_4 * V_28 = V_14 ;
V_13 -> V_28 |= V_29 ;
* V_28 = 0 ;
V_14 += V_30 ;
if ( type & V_125 ) {
V_22 V_126 = F_78 ( V_6 ) ;
T_3 * V_18 = V_14 ;
if ( V_126 < V_15 )
return - V_87 ;
V_126 -= V_15 ;
V_18 [ 0 ] = F_4 ( V_126 ) ;
V_18 [ 1 ] = F_4 ( V_126 + V_6 -> V_127 ) ;
if ( ! F_79 ( V_6 ) ) {
V_6 -> V_123 = V_128 ;
V_6 -> V_129 = 0 ;
}
* V_28 |= V_31 ;
V_14 += V_34 ;
}
}
F_68 ( V_6 , V_104 , V_108 , V_12 , V_109 ) ;
return 0 ;
}
static int F_80 ( void )
{
int V_130 ;
V_130 = F_81 ( & V_131 , V_132 ) ;
if ( V_130 < 0 ) {
F_82 ( L_1 ) ;
return V_130 ;
}
V_130 = F_81 ( & V_133 , V_134 ) ;
if ( V_130 < 0 ) {
F_82 ( L_2 ) ;
F_83 ( & V_131 , V_132 ) ;
return V_130 ;
}
return 0 ;
}
static void F_84 ( void )
{
F_83 ( & V_131 , V_132 ) ;
F_83 ( & V_133 , V_134 ) ;
}
static int F_80 ( void )
{
return 0 ;
}
static void F_84 ( void )
{
}
static int T_5 F_85 ( void )
{
int V_130 ;
V_130 = F_86 ( & V_135 ,
V_136 ) ;
if ( V_130 < 0 )
goto exit;
V_130 = F_80 () ;
if ( V_130 < 0 )
F_87 ( & V_135 ) ;
exit:
return V_130 ;
}
static void T_6 F_88 ( void )
{
struct V_1 * V_1 , * V_63 ;
F_84 () ;
F_87 ( & V_135 ) ;
F_42 ( & V_70 ) ;
F_89 (fou, next, &fou_list, list)
F_46 ( V_1 ) ;
F_44 ( & V_70 ) ;
}
