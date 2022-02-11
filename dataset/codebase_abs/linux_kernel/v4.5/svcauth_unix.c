static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 , struct V_3 , V_5 ) ;
F_3 ( V_2 -> V_6 ) ;
F_3 ( V_4 ) ;
}
struct V_1 * F_4 ( char * V_6 )
{
struct V_1 * V_7 ;
struct V_3 * V_8 = NULL ;
V_7 = F_5 ( V_6 , NULL ) ;
while( 1 ) {
if ( V_7 ) {
if ( V_8 && V_7 != & V_8 -> V_5 )
F_1 ( & V_8 -> V_5 ) ;
if ( V_7 -> V_9 != & V_10 ) {
F_6 ( V_7 ) ;
return NULL ;
}
return V_7 ;
}
V_8 = F_7 ( sizeof( * V_8 ) , V_11 ) ;
if ( V_8 == NULL )
return NULL ;
F_8 ( & V_8 -> V_5 . V_12 ) ;
V_8 -> V_5 . V_6 = F_9 ( V_6 , V_11 ) ;
if ( V_8 -> V_5 . V_6 == NULL ) {
F_3 ( V_8 ) ;
return NULL ;
}
V_8 -> V_5 . V_9 = & V_10 ;
V_7 = F_5 ( V_6 , & V_8 -> V_5 ) ;
}
}
static void F_10 ( struct V_13 * V_13 )
{
struct V_14 * V_15 = F_2 ( V_13 , struct V_14 , V_12 ) ;
struct V_16 * V_17 = F_2 ( V_15 , struct V_16 , V_5 ) ;
if ( F_11 ( V_18 , & V_15 -> V_19 ) &&
! F_11 ( V_20 , & V_15 -> V_19 ) )
F_6 ( & V_17 -> V_21 -> V_5 ) ;
F_3 ( V_17 ) ;
}
static inline int F_12 ( const struct V_22 * V_23 )
{
return F_13 ( F_14 ( V_23 ) , V_24 ) ;
}
static int F_15 ( struct V_14 * V_25 , struct V_14 * V_26 )
{
struct V_16 * V_27 = F_2 ( V_25 , struct V_16 , V_5 ) ;
struct V_16 * V_8 = F_2 ( V_26 , struct V_16 , V_5 ) ;
return strcmp ( V_27 -> V_28 , V_8 -> V_28 ) == 0 &&
F_16 ( & V_27 -> V_29 , & V_8 -> V_29 ) ;
}
static void F_17 ( struct V_14 * V_26 , struct V_14 * V_30 )
{
struct V_16 * V_8 = F_2 ( V_26 , struct V_16 , V_5 ) ;
struct V_16 * V_15 = F_2 ( V_30 , struct V_16 , V_5 ) ;
strcpy ( V_8 -> V_28 , V_15 -> V_28 ) ;
V_8 -> V_29 = V_15 -> V_29 ;
}
static void F_18 ( struct V_14 * V_26 , struct V_14 * V_30 )
{
struct V_16 * V_8 = F_2 ( V_26 , struct V_16 , V_5 ) ;
struct V_16 * V_15 = F_2 ( V_30 , struct V_16 , V_5 ) ;
F_19 ( & V_15 -> V_21 -> V_5 . V_12 ) ;
V_8 -> V_21 = V_15 -> V_21 ;
}
static struct V_14 * F_20 ( void )
{
struct V_16 * V_31 = F_7 ( sizeof( * V_31 ) , V_11 ) ;
if ( V_31 )
return & V_31 -> V_5 ;
else
return NULL ;
}
static void F_21 ( struct V_32 * V_33 ,
struct V_14 * V_5 ,
char * * V_34 , int * V_35 )
{
char V_36 [ 40 ] ;
struct V_16 * V_17 = F_2 ( V_5 , struct V_16 , V_5 ) ;
if ( F_22 ( & ( V_17 -> V_29 ) ) ) {
snprintf ( V_36 , 20 , L_1 , & V_17 -> V_29 . V_37 [ 3 ] ) ;
} else {
snprintf ( V_36 , 40 , L_2 , & V_17 -> V_29 ) ;
}
F_23 ( V_34 , V_35 , V_17 -> V_28 ) ;
F_23 ( V_34 , V_35 , V_36 ) ;
( * V_34 ) [ - 1 ] = '\n' ;
}
static int F_24 ( struct V_32 * V_33 ,
char * V_38 , int V_39 )
{
char * V_40 = V_38 ;
int V_41 ;
char V_42 [ 8 ] ;
union {
struct V_43 V_44 ;
struct V_45 V_46 ;
struct V_47 V_48 ;
} V_49 ;
struct V_47 V_50 ;
int V_51 ;
struct V_16 * V_52 ;
struct V_1 * V_2 ;
T_1 V_53 ;
if ( V_38 [ V_39 - 1 ] != '\n' )
return - V_54 ;
V_38 [ V_39 - 1 ] = 0 ;
V_41 = F_25 ( & V_38 , V_42 , sizeof( V_42 ) ) ;
if ( V_41 <= 0 ) return - V_54 ;
V_41 = F_25 ( & V_38 , V_40 , V_39 ) ;
if ( V_41 <= 0 ) return - V_54 ;
if ( F_26 ( V_33 -> V_55 , V_40 , V_41 , & V_49 . V_44 , sizeof( V_49 ) ) == 0 )
return - V_54 ;
switch ( V_49 . V_44 . V_56 ) {
case V_57 :
V_50 . V_58 = V_59 ;
F_27 ( V_49 . V_46 . V_60 . V_61 ,
& V_50 . V_62 ) ;
break;
#if F_28 ( V_63 )
case V_59 :
memcpy ( & V_50 , & V_49 . V_48 , sizeof( V_50 ) ) ;
break;
#endif
default:
return - V_54 ;
}
V_53 = F_29 ( & V_38 ) ;
if ( V_53 == 0 )
return - V_54 ;
V_41 = F_25 ( & V_38 , V_40 , V_39 ) ;
if ( V_41 < 0 ) return - V_54 ;
if ( V_41 ) {
V_2 = F_4 ( V_40 ) ;
if ( V_2 == NULL )
return - V_64 ;
} else
V_2 = NULL ;
V_52 = F_30 ( V_33 , V_42 , & V_50 . V_62 ) ;
if ( V_52 ) {
V_51 = F_31 ( V_33 , V_52 ,
F_2 ( V_2 , struct V_3 , V_5 ) ,
V_53 ) ;
} else
V_51 = - V_65 ;
if ( V_2 )
F_6 ( V_2 ) ;
F_32 () ;
return V_51 ;
}
static int F_33 ( struct V_66 * V_67 ,
struct V_32 * V_33 ,
struct V_14 * V_5 )
{
struct V_16 * V_17 ;
struct V_22 V_68 ;
char * V_2 = L_3 ;
if ( V_5 == NULL ) {
F_34 ( V_67 , L_4 ) ;
return 0 ;
}
V_17 = F_2 ( V_5 , struct V_16 , V_5 ) ;
V_68 = V_17 -> V_29 ;
if ( F_11 ( V_18 , & V_5 -> V_19 ) &&
! F_11 ( V_20 , & V_5 -> V_19 ) )
V_2 = V_17 -> V_21 -> V_5 . V_6 ;
if ( F_22 ( & V_68 ) ) {
F_35 ( V_67 , L_5 ,
V_17 -> V_28 , & V_68 . V_37 [ 3 ] , V_2 ) ;
} else {
F_35 ( V_67 , L_6 , V_17 -> V_28 , & V_68 , V_2 ) ;
}
return 0 ;
}
static struct V_16 * F_30 ( struct V_32 * V_33 , char * V_42 ,
struct V_22 * V_68 )
{
struct V_16 V_23 ;
struct V_14 * V_69 ;
strcpy ( V_23 . V_28 , V_42 ) ;
V_23 . V_29 = * V_68 ;
V_69 = F_36 ( V_33 , & V_23 . V_5 ,
F_37 ( V_42 , V_24 ) ^
F_12 ( V_68 ) ) ;
if ( V_69 )
return F_2 ( V_69 , struct V_16 , V_5 ) ;
else
return NULL ;
}
static inline struct V_16 * F_38 ( struct V_55 * V_55 , char * V_42 ,
struct V_22 * V_68 )
{
struct V_70 * V_71 ;
V_71 = F_39 ( V_55 , V_72 ) ;
return F_30 ( V_71 -> V_73 , V_42 , V_68 ) ;
}
static int F_31 ( struct V_32 * V_33 , struct V_16 * V_74 ,
struct V_3 * V_75 , T_1 V_53 )
{
struct V_16 V_23 ;
struct V_14 * V_69 ;
V_23 . V_21 = V_75 ;
V_23 . V_5 . V_19 = 0 ;
if ( ! V_75 )
F_40 ( V_20 , & V_23 . V_5 . V_19 ) ;
V_23 . V_5 . V_76 = V_53 ;
V_69 = F_41 ( V_33 , & V_23 . V_5 , & V_74 -> V_5 ,
F_37 ( V_74 -> V_28 , V_24 ) ^
F_12 ( & V_74 -> V_29 ) ) ;
if ( ! V_69 )
return - V_65 ;
F_42 ( V_69 , V_33 ) ;
return 0 ;
}
static inline int F_43 ( struct V_55 * V_55 , struct V_16 * V_74 ,
struct V_3 * V_75 , T_1 V_53 )
{
struct V_70 * V_71 ;
V_71 = F_39 ( V_55 , V_72 ) ;
return F_31 ( V_71 -> V_73 , V_74 , V_75 , V_53 ) ;
}
void F_44 ( struct V_55 * V_55 )
{
struct V_70 * V_71 ;
V_71 = F_39 ( V_55 , V_72 ) ;
F_45 ( V_71 -> V_73 ) ;
}
static inline struct V_16 *
F_46 ( struct V_77 * V_78 )
{
struct V_16 * V_74 = NULL ;
struct V_70 * V_71 ;
if ( F_11 ( V_79 , & V_78 -> V_80 ) ) {
F_47 ( & V_78 -> V_81 ) ;
V_74 = V_78 -> V_82 ;
if ( V_74 != NULL ) {
V_71 = F_39 ( V_78 -> V_83 , V_72 ) ;
if ( F_48 ( V_71 -> V_73 , & V_74 -> V_5 ) ) {
V_78 -> V_82 = NULL ;
F_49 ( & V_78 -> V_81 ) ;
F_42 ( & V_74 -> V_5 , V_71 -> V_73 ) ;
return NULL ;
}
F_50 ( & V_74 -> V_5 ) ;
}
F_49 ( & V_78 -> V_81 ) ;
}
return V_74 ;
}
static inline void
F_51 ( struct V_77 * V_78 , struct V_16 * V_74 )
{
if ( F_11 ( V_79 , & V_78 -> V_80 ) ) {
F_47 ( & V_78 -> V_81 ) ;
if ( V_78 -> V_82 == NULL ) {
V_78 -> V_82 = V_74 ;
V_74 = NULL ;
}
F_49 ( & V_78 -> V_81 ) ;
}
if ( V_74 ) {
struct V_70 * V_71 ;
V_71 = F_39 ( V_78 -> V_83 , V_72 ) ;
F_42 ( & V_74 -> V_5 , V_71 -> V_73 ) ;
}
}
void
F_52 ( struct V_77 * V_84 )
{
struct V_16 * V_74 ;
V_74 = V_84 -> V_82 ;
if ( V_74 != NULL ) {
struct V_70 * V_71 ;
V_71 = F_39 ( V_84 -> V_83 , V_72 ) ;
F_42 ( & V_74 -> V_5 , V_71 -> V_73 ) ;
}
}
static int F_53 ( T_2 V_85 )
{
return F_54 ( F_55 ( & V_86 , V_85 ) , V_87 ) ;
}
static void F_56 ( struct V_13 * V_13 )
{
struct V_14 * V_15 = F_2 ( V_13 , struct V_14 , V_12 ) ;
struct V_88 * V_89 = F_2 ( V_15 , struct V_88 , V_5 ) ;
if ( F_11 ( V_18 , & V_15 -> V_19 ) &&
! F_11 ( V_20 , & V_15 -> V_19 ) )
F_57 ( V_89 -> V_90 ) ;
F_3 ( V_89 ) ;
}
static int F_58 ( struct V_14 * V_25 , struct V_14 * V_26 )
{
struct V_88 * V_27 = F_2 ( V_25 , struct V_88 , V_5 ) ;
struct V_88 * V_8 = F_2 ( V_26 , struct V_88 , V_5 ) ;
return F_59 ( V_27 -> V_85 , V_8 -> V_85 ) ;
}
static void F_60 ( struct V_14 * V_26 , struct V_14 * V_30 )
{
struct V_88 * V_8 = F_2 ( V_26 , struct V_88 , V_5 ) ;
struct V_88 * V_15 = F_2 ( V_30 , struct V_88 , V_5 ) ;
V_8 -> V_85 = V_15 -> V_85 ;
}
static void F_61 ( struct V_14 * V_26 , struct V_14 * V_30 )
{
struct V_88 * V_8 = F_2 ( V_26 , struct V_88 , V_5 ) ;
struct V_88 * V_15 = F_2 ( V_30 , struct V_88 , V_5 ) ;
F_62 ( V_15 -> V_90 ) ;
V_8 -> V_90 = V_15 -> V_90 ;
}
static struct V_14 * F_63 ( void )
{
struct V_88 * V_91 = F_7 ( sizeof( * V_91 ) , V_11 ) ;
if ( V_91 )
return & V_91 -> V_5 ;
else
return NULL ;
}
static void F_64 ( struct V_32 * V_33 ,
struct V_14 * V_5 ,
char * * V_34 , int * V_35 )
{
char V_92 [ 20 ] ;
struct V_88 * V_89 = F_2 ( V_5 , struct V_88 , V_5 ) ;
snprintf ( V_92 , 20 , L_7 , F_55 ( & V_86 , V_89 -> V_85 ) ) ;
F_23 ( V_34 , V_35 , V_92 ) ;
( * V_34 ) [ - 1 ] = '\n' ;
}
static int F_65 ( struct V_32 * V_33 ,
char * V_38 , int V_39 )
{
int V_93 ;
T_2 V_85 ;
int V_94 ;
int V_7 ;
int V_31 ;
int V_51 ;
T_1 V_53 ;
struct V_88 V_89 , * V_95 ;
if ( V_38 [ V_39 - 1 ] != '\n' )
return - V_54 ;
V_38 [ V_39 - 1 ] = 0 ;
V_7 = F_66 ( & V_38 , & V_93 ) ;
if ( V_7 )
return - V_54 ;
V_85 = F_67 ( & V_86 , V_93 ) ;
V_89 . V_85 = V_85 ;
V_53 = F_29 ( & V_38 ) ;
if ( V_53 == 0 )
return - V_54 ;
V_7 = F_66 ( & V_38 , & V_94 ) ;
if ( V_7 || V_94 < 0 || V_94 > 8192 )
return - V_54 ;
V_89 . V_90 = F_68 ( V_94 ) ;
if ( ! V_89 . V_90 )
return - V_65 ;
for ( V_31 = 0 ; V_31 < V_94 ; V_31 ++ ) {
int V_96 ;
T_3 V_97 ;
V_7 = F_66 ( & V_38 , & V_96 ) ;
V_51 = - V_54 ;
if ( V_7 )
goto V_98;
V_97 = F_69 ( & V_86 , V_96 ) ;
if ( ! F_70 ( V_97 ) )
goto V_98;
F_71 ( V_89 . V_90 , V_31 ) = V_97 ;
}
V_95 = F_72 ( V_33 , V_85 ) ;
if ( V_95 ) {
struct V_14 * V_69 ;
V_89 . V_5 . V_19 = 0 ;
V_89 . V_5 . V_76 = V_53 ;
V_69 = F_41 ( V_33 ,
& V_89 . V_5 , & V_95 -> V_5 ,
F_53 ( V_85 ) ) ;
if ( ! V_69 )
V_51 = - V_65 ;
else {
V_51 = 0 ;
F_42 ( V_69 , V_33 ) ;
}
} else
V_51 = - V_65 ;
V_98:
if ( V_89 . V_90 )
F_57 ( V_89 . V_90 ) ;
return V_51 ;
}
static int F_73 ( struct V_66 * V_67 ,
struct V_32 * V_33 ,
struct V_14 * V_5 )
{
struct V_99 * V_100 = & V_86 ;
struct V_88 * V_89 ;
int V_31 ;
int V_101 ;
if ( V_5 == NULL ) {
F_34 ( V_67 , L_8 ) ;
return 0 ;
}
V_89 = F_2 ( V_5 , struct V_88 , V_5 ) ;
if ( F_11 ( V_18 , & V_5 -> V_19 ) &&
! F_11 ( V_20 , & V_5 -> V_19 ) )
V_101 = V_89 -> V_90 -> V_102 ;
else
V_101 = 0 ;
F_35 ( V_67 , L_9 , F_74 ( V_100 , V_89 -> V_85 ) , V_101 ) ;
for ( V_31 = 0 ; V_31 < V_101 ; V_31 ++ )
F_35 ( V_67 , L_10 , F_75 ( V_100 , F_71 ( V_89 -> V_90 , V_31 ) ) ) ;
F_35 ( V_67 , L_11 ) ;
return 0 ;
}
int F_76 ( struct V_55 * V_55 )
{
struct V_70 * V_71 = F_39 ( V_55 , V_72 ) ;
struct V_32 * V_33 ;
int V_51 ;
V_33 = F_77 ( & V_103 , V_55 ) ;
if ( F_78 ( V_33 ) )
return F_79 ( V_33 ) ;
V_51 = F_80 ( V_33 , V_55 ) ;
if ( V_51 ) {
F_81 ( V_33 , V_55 ) ;
return V_51 ;
}
V_71 -> V_104 = V_33 ;
return 0 ;
}
void F_82 ( struct V_55 * V_55 )
{
struct V_70 * V_71 = F_39 ( V_55 , V_72 ) ;
struct V_32 * V_33 = V_71 -> V_104 ;
V_71 -> V_104 = NULL ;
F_45 ( V_33 ) ;
F_83 ( V_33 , V_55 ) ;
F_81 ( V_33 , V_55 ) ;
}
static struct V_88 * F_72 ( struct V_32 * V_33 , T_2 V_85 )
{
struct V_88 V_89 ;
struct V_14 * V_69 ;
V_89 . V_85 = V_85 ;
V_69 = F_36 ( V_33 , & V_89 . V_5 , F_53 ( V_85 ) ) ;
if ( V_69 )
return F_2 ( V_69 , struct V_88 , V_5 ) ;
else
return NULL ;
}
static struct V_105 * F_84 ( T_2 V_85 , struct V_106 * V_107 )
{
struct V_88 * V_89 ;
struct V_105 * V_90 ;
int V_108 ;
struct V_70 * V_71 = F_39 ( V_107 -> V_109 -> V_83 ,
V_72 ) ;
V_89 = F_72 ( V_71 -> V_104 , V_85 ) ;
if ( ! V_89 )
return F_85 ( - V_110 ) ;
V_108 = F_86 ( V_71 -> V_104 , & V_89 -> V_5 , & V_107 -> V_111 ) ;
switch ( V_108 ) {
case - V_64 :
return F_85 ( - V_64 ) ;
case - V_112 :
return F_85 ( - V_113 ) ;
case 0 :
V_90 = F_62 ( V_89 -> V_90 ) ;
F_42 ( & V_89 -> V_5 , V_71 -> V_104 ) ;
return V_90 ;
default:
return F_85 ( - V_110 ) ;
}
}
int
F_87 ( struct V_106 * V_107 )
{
struct V_45 * sin ;
struct V_47 * V_50 , V_114 ;
struct V_16 * V_74 ;
struct V_105 * V_90 ;
struct V_115 * V_116 = & V_107 -> V_117 ;
struct V_77 * V_78 = V_107 -> V_109 ;
struct V_55 * V_55 = V_78 -> V_83 ;
struct V_70 * V_71 = F_39 ( V_55 , V_72 ) ;
switch ( V_107 -> V_118 . V_119 ) {
case V_57 :
sin = F_88 ( V_107 ) ;
V_50 = & V_114 ;
F_27 ( sin -> V_60 . V_61 , & V_50 -> V_62 ) ;
break;
case V_59 :
V_50 = F_89 ( V_107 ) ;
break;
default:
F_90 () ;
}
V_107 -> V_120 = NULL ;
if ( V_107 -> V_121 == 0 )
return V_122 ;
V_74 = F_46 ( V_78 ) ;
if ( V_74 == NULL )
V_74 = F_30 ( V_71 -> V_73 , V_107 -> V_123 -> V_124 -> V_125 ,
& V_50 -> V_62 ) ;
if ( V_74 == NULL )
return V_126 ;
switch ( F_86 ( V_71 -> V_73 , & V_74 -> V_5 , & V_107 -> V_111 ) ) {
default:
F_90 () ;
case - V_112 :
return V_127 ;
case - V_110 :
return V_128 ;
case - V_64 :
return V_126 ;
case 0 :
V_107 -> V_120 = & V_74 -> V_21 -> V_5 ;
F_19 ( & V_107 -> V_120 -> V_12 ) ;
F_51 ( V_78 , V_74 ) ;
break;
}
V_90 = F_84 ( V_116 -> V_129 , V_107 ) ;
switch ( F_79 ( V_90 ) ) {
case - V_110 :
return V_128 ;
case - V_113 :
return V_127 ;
case - V_64 :
break;
default:
F_57 ( V_116 -> V_130 ) ;
V_116 -> V_130 = V_90 ;
}
return V_122 ;
}
static int
F_91 ( struct V_106 * V_107 , T_4 * V_131 )
{
struct V_132 * V_133 = & V_107 -> V_134 . V_135 [ 0 ] ;
struct V_132 * V_136 = & V_107 -> V_137 . V_135 [ 0 ] ;
struct V_115 * V_116 = & V_107 -> V_117 ;
if ( V_133 -> V_138 < 3 * 4 )
return V_139 ;
if ( F_92 ( V_133 ) != 0 ) {
F_93 ( L_12 ) ;
* V_131 = V_140 ;
return V_126 ;
}
if ( F_92 ( V_133 ) != F_94 ( V_141 ) || F_92 ( V_133 ) != 0 ) {
F_93 ( L_13 ) ;
* V_131 = V_142 ;
return V_126 ;
}
V_116 -> V_129 = V_143 ;
V_116 -> V_144 = V_145 ;
V_116 -> V_130 = F_68 ( 0 ) ;
if ( V_116 -> V_130 == NULL )
return V_127 ;
F_95 ( V_136 , V_141 ) ;
F_95 ( V_136 , 0 ) ;
V_107 -> V_117 . V_146 = V_141 ;
return V_122 ;
}
static int
F_96 ( struct V_106 * V_107 )
{
if ( V_107 -> V_120 )
F_6 ( V_107 -> V_120 ) ;
V_107 -> V_120 = NULL ;
if ( V_107 -> V_117 . V_130 )
F_57 ( V_107 -> V_117 . V_130 ) ;
V_107 -> V_117 . V_130 = NULL ;
return 0 ;
}
static int
F_97 ( struct V_106 * V_107 , T_4 * V_131 )
{
struct V_132 * V_133 = & V_107 -> V_134 . V_135 [ 0 ] ;
struct V_132 * V_136 = & V_107 -> V_137 . V_135 [ 0 ] ;
struct V_115 * V_116 = & V_107 -> V_117 ;
T_5 V_147 , V_31 ;
int V_41 = V_133 -> V_138 ;
if ( ( V_41 -= 3 * 4 ) < 0 )
return V_139 ;
F_92 ( V_133 ) ;
F_92 ( V_133 ) ;
V_147 = F_98 ( F_99 ( V_133 ) ) ;
if ( V_147 > 64 || ( V_41 -= ( V_147 + 3 ) * 4 ) < 0 )
goto V_148;
V_133 -> V_149 = ( void * ) ( ( T_4 * ) V_133 -> V_149 + V_147 ) ;
V_133 -> V_138 -= V_147 * 4 ;
V_116 -> V_129 = F_67 ( & V_86 , F_99 ( V_133 ) ) ;
V_116 -> V_144 = F_69 ( & V_86 , F_99 ( V_133 ) ) ;
V_147 = F_99 ( V_133 ) ;
if ( V_147 > 16 || ( V_41 -= ( V_147 + 2 ) * 4 ) < 0 )
goto V_148;
V_116 -> V_130 = F_68 ( V_147 ) ;
if ( V_116 -> V_130 == NULL )
return V_127 ;
for ( V_31 = 0 ; V_31 < V_147 ; V_31 ++ ) {
T_3 V_97 = F_69 ( & V_86 , F_99 ( V_133 ) ) ;
F_71 ( V_116 -> V_130 , V_31 ) = V_97 ;
}
if ( F_92 ( V_133 ) != F_94 ( V_141 ) || F_92 ( V_133 ) != 0 ) {
* V_131 = V_142 ;
return V_126 ;
}
F_95 ( V_136 , V_141 ) ;
F_95 ( V_136 , 0 ) ;
V_107 -> V_117 . V_146 = V_150 ;
return V_122 ;
V_148:
* V_131 = V_140 ;
return V_126 ;
}
static int
F_100 ( struct V_106 * V_107 )
{
if ( V_107 -> V_120 )
F_6 ( V_107 -> V_120 ) ;
V_107 -> V_120 = NULL ;
if ( V_107 -> V_117 . V_130 )
F_57 ( V_107 -> V_117 . V_130 ) ;
V_107 -> V_117 . V_130 = NULL ;
return 0 ;
}
int F_101 ( struct V_55 * V_55 )
{
struct V_70 * V_71 = F_39 ( V_55 , V_72 ) ;
struct V_32 * V_33 ;
int V_51 ;
V_33 = F_77 ( & V_151 , V_55 ) ;
if ( F_78 ( V_33 ) )
return F_79 ( V_33 ) ;
V_51 = F_80 ( V_33 , V_55 ) ;
if ( V_51 ) {
F_81 ( V_33 , V_55 ) ;
return V_51 ;
}
V_71 -> V_73 = V_33 ;
return 0 ;
}
void F_102 ( struct V_55 * V_55 )
{
struct V_70 * V_71 = F_39 ( V_55 , V_72 ) ;
struct V_32 * V_33 = V_71 -> V_73 ;
V_71 -> V_73 = NULL ;
F_45 ( V_33 ) ;
F_83 ( V_33 , V_55 ) ;
F_81 ( V_33 , V_55 ) ;
}
