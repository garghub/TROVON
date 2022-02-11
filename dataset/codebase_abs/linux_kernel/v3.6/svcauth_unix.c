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
static int F_24 ( struct V_32 * V_33 , struct V_14 * V_5 )
{
return F_25 ( V_33 , V_5 , F_21 ) ;
}
static int F_26 ( struct V_32 * V_33 ,
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
V_41 = F_27 ( & V_38 , V_42 , sizeof( V_42 ) ) ;
if ( V_41 <= 0 ) return - V_54 ;
V_41 = F_27 ( & V_38 , V_40 , V_39 ) ;
if ( V_41 <= 0 ) return - V_54 ;
if ( F_28 ( V_33 -> V_55 , V_40 , V_41 , & V_49 . V_44 , sizeof( V_49 ) ) == 0 )
return - V_54 ;
switch ( V_49 . V_44 . V_56 ) {
case V_57 :
V_50 . V_58 = V_59 ;
F_29 ( V_49 . V_46 . V_60 . V_61 ,
& V_50 . V_62 ) ;
break;
#if F_30 ( V_63 )
case V_59 :
memcpy ( & V_50 , & V_49 . V_48 , sizeof( V_50 ) ) ;
break;
#endif
default:
return - V_54 ;
}
V_53 = F_31 ( & V_38 ) ;
if ( V_53 == 0 )
return - V_54 ;
V_41 = F_27 ( & V_38 , V_40 , V_39 ) ;
if ( V_41 < 0 ) return - V_54 ;
if ( V_41 ) {
V_2 = F_4 ( V_40 ) ;
if ( V_2 == NULL )
return - V_64 ;
} else
V_2 = NULL ;
V_52 = F_32 ( V_33 , V_42 , & V_50 . V_62 ) ;
if ( V_52 ) {
V_51 = F_33 ( V_33 , V_52 ,
F_2 ( V_2 , struct V_3 , V_5 ) ,
V_53 ) ;
} else
V_51 = - V_65 ;
if ( V_2 )
F_6 ( V_2 ) ;
F_34 () ;
return V_51 ;
}
static int F_35 ( struct V_66 * V_67 ,
struct V_32 * V_33 ,
struct V_14 * V_5 )
{
struct V_16 * V_17 ;
struct V_22 V_68 ;
char * V_2 = L_3 ;
if ( V_5 == NULL ) {
F_36 ( V_67 , L_4 ) ;
return 0 ;
}
V_17 = F_2 ( V_5 , struct V_16 , V_5 ) ;
V_68 = V_17 -> V_29 ;
if ( F_11 ( V_18 , & V_5 -> V_19 ) &&
! F_11 ( V_20 , & V_5 -> V_19 ) )
V_2 = V_17 -> V_21 -> V_5 . V_6 ;
if ( F_22 ( & V_68 ) ) {
F_37 ( V_67 , L_5 ,
V_17 -> V_28 , & V_68 . V_37 [ 3 ] , V_2 ) ;
} else {
F_37 ( V_67 , L_6 , V_17 -> V_28 , & V_68 , V_2 ) ;
}
return 0 ;
}
static struct V_16 * F_32 ( struct V_32 * V_33 , char * V_42 ,
struct V_22 * V_68 )
{
struct V_16 V_23 ;
struct V_14 * V_69 ;
strcpy ( V_23 . V_28 , V_42 ) ;
V_23 . V_29 = * V_68 ;
V_69 = F_38 ( V_33 , & V_23 . V_5 ,
F_39 ( V_42 , V_24 ) ^
F_12 ( V_68 ) ) ;
if ( V_69 )
return F_2 ( V_69 , struct V_16 , V_5 ) ;
else
return NULL ;
}
static inline struct V_16 * F_40 ( struct V_55 * V_55 , char * V_42 ,
struct V_22 * V_68 )
{
struct V_70 * V_71 ;
V_71 = F_41 ( V_55 , V_72 ) ;
return F_32 ( V_71 -> V_73 , V_42 , V_68 ) ;
}
static int F_33 ( struct V_32 * V_33 , struct V_16 * V_74 ,
struct V_3 * V_75 , T_1 V_53 )
{
struct V_16 V_23 ;
struct V_14 * V_69 ;
V_23 . V_21 = V_75 ;
V_23 . V_5 . V_19 = 0 ;
if ( ! V_75 )
F_42 ( V_20 , & V_23 . V_5 . V_19 ) ;
V_23 . V_5 . V_76 = V_53 ;
V_69 = F_43 ( V_33 , & V_23 . V_5 , & V_74 -> V_5 ,
F_39 ( V_74 -> V_28 , V_24 ) ^
F_12 ( & V_74 -> V_29 ) ) ;
if ( ! V_69 )
return - V_65 ;
F_44 ( V_69 , V_33 ) ;
return 0 ;
}
static inline int F_45 ( struct V_55 * V_55 , struct V_16 * V_74 ,
struct V_3 * V_75 , T_1 V_53 )
{
struct V_70 * V_71 ;
V_71 = F_41 ( V_55 , V_72 ) ;
return F_33 ( V_71 -> V_73 , V_74 , V_75 , V_53 ) ;
}
void F_46 ( struct V_55 * V_55 )
{
struct V_70 * V_71 ;
V_71 = F_41 ( V_55 , V_72 ) ;
F_47 ( V_71 -> V_73 ) ;
}
static inline struct V_16 *
F_48 ( struct V_77 * V_78 )
{
struct V_16 * V_74 = NULL ;
struct V_70 * V_71 ;
if ( F_11 ( V_79 , & V_78 -> V_80 ) ) {
F_49 ( & V_78 -> V_81 ) ;
V_74 = V_78 -> V_82 ;
if ( V_74 != NULL ) {
if ( ! F_50 ( & V_74 -> V_5 ) ) {
V_71 = F_41 ( V_78 -> V_83 , V_72 ) ;
V_78 -> V_82 = NULL ;
F_51 ( & V_78 -> V_81 ) ;
F_44 ( & V_74 -> V_5 , V_71 -> V_73 ) ;
return NULL ;
}
F_52 ( & V_74 -> V_5 ) ;
}
F_51 ( & V_78 -> V_81 ) ;
}
return V_74 ;
}
static inline void
F_53 ( struct V_77 * V_78 , struct V_16 * V_74 )
{
if ( F_11 ( V_79 , & V_78 -> V_80 ) ) {
F_49 ( & V_78 -> V_81 ) ;
if ( V_78 -> V_82 == NULL ) {
V_78 -> V_82 = V_74 ;
V_74 = NULL ;
}
F_51 ( & V_78 -> V_81 ) ;
}
if ( V_74 ) {
struct V_70 * V_71 ;
V_71 = F_41 ( V_78 -> V_83 , V_72 ) ;
F_44 ( & V_74 -> V_5 , V_71 -> V_73 ) ;
}
}
void
F_54 ( struct V_77 * V_84 )
{
struct V_16 * V_74 ;
V_74 = V_84 -> V_82 ;
if ( V_74 != NULL ) {
struct V_70 * V_71 ;
V_71 = F_41 ( V_84 -> V_83 , V_72 ) ;
F_44 ( & V_74 -> V_5 , V_71 -> V_73 ) ;
}
}
static void F_55 ( struct V_13 * V_13 )
{
struct V_14 * V_15 = F_2 ( V_13 , struct V_14 , V_12 ) ;
struct V_85 * V_86 = F_2 ( V_15 , struct V_85 , V_5 ) ;
if ( F_11 ( V_18 , & V_15 -> V_19 ) &&
! F_11 ( V_20 , & V_15 -> V_19 ) )
F_56 ( V_86 -> V_87 ) ;
F_3 ( V_86 ) ;
}
static int F_57 ( struct V_14 * V_25 , struct V_14 * V_26 )
{
struct V_85 * V_27 = F_2 ( V_25 , struct V_85 , V_5 ) ;
struct V_85 * V_8 = F_2 ( V_26 , struct V_85 , V_5 ) ;
return V_27 -> V_88 == V_8 -> V_88 ;
}
static void F_58 ( struct V_14 * V_26 , struct V_14 * V_30 )
{
struct V_85 * V_8 = F_2 ( V_26 , struct V_85 , V_5 ) ;
struct V_85 * V_15 = F_2 ( V_30 , struct V_85 , V_5 ) ;
V_8 -> V_88 = V_15 -> V_88 ;
}
static void F_59 ( struct V_14 * V_26 , struct V_14 * V_30 )
{
struct V_85 * V_8 = F_2 ( V_26 , struct V_85 , V_5 ) ;
struct V_85 * V_15 = F_2 ( V_30 , struct V_85 , V_5 ) ;
F_60 ( V_15 -> V_87 ) ;
V_8 -> V_87 = V_15 -> V_87 ;
}
static struct V_14 * F_61 ( void )
{
struct V_85 * V_89 = F_7 ( sizeof( * V_89 ) , V_11 ) ;
if ( V_89 )
return & V_89 -> V_5 ;
else
return NULL ;
}
static void F_62 ( struct V_32 * V_33 ,
struct V_14 * V_5 ,
char * * V_34 , int * V_35 )
{
char V_90 [ 20 ] ;
struct V_85 * V_86 = F_2 ( V_5 , struct V_85 , V_5 ) ;
snprintf ( V_90 , 20 , L_7 , V_86 -> V_88 ) ;
F_23 ( V_34 , V_35 , V_90 ) ;
( * V_34 ) [ - 1 ] = '\n' ;
}
static int F_63 ( struct V_32 * V_33 , struct V_14 * V_5 )
{
return F_25 ( V_33 , V_5 , F_62 ) ;
}
static int F_64 ( struct V_32 * V_33 ,
char * V_38 , int V_39 )
{
int V_88 ;
int V_91 ;
int V_7 ;
int V_31 ;
int V_51 ;
T_1 V_53 ;
struct V_85 V_86 , * V_92 ;
if ( V_38 [ V_39 - 1 ] != '\n' )
return - V_54 ;
V_38 [ V_39 - 1 ] = 0 ;
V_7 = F_65 ( & V_38 , & V_88 ) ;
if ( V_7 )
return - V_54 ;
V_86 . V_88 = V_88 ;
V_53 = F_31 ( & V_38 ) ;
if ( V_53 == 0 )
return - V_54 ;
V_7 = F_65 ( & V_38 , & V_91 ) ;
if ( V_7 || V_91 < 0 || V_91 > 8192 )
return - V_54 ;
V_86 . V_87 = F_66 ( V_91 ) ;
if ( ! V_86 . V_87 )
return - V_65 ;
for ( V_31 = 0 ; V_31 < V_91 ; V_31 ++ ) {
int V_93 ;
T_2 V_94 ;
V_7 = F_65 ( & V_38 , & V_93 ) ;
V_51 = - V_54 ;
if ( V_7 )
goto V_95;
V_94 = F_67 ( & V_96 , V_93 ) ;
if ( ! F_68 ( V_94 ) )
goto V_95;
F_69 ( V_86 . V_87 , V_31 ) = V_94 ;
}
V_92 = F_70 ( V_33 , V_88 ) ;
if ( V_92 ) {
struct V_14 * V_69 ;
V_86 . V_5 . V_19 = 0 ;
V_86 . V_5 . V_76 = V_53 ;
V_69 = F_43 ( V_33 ,
& V_86 . V_5 , & V_92 -> V_5 ,
F_71 ( V_88 , V_97 ) ) ;
if ( ! V_69 )
V_51 = - V_65 ;
else {
V_51 = 0 ;
F_44 ( V_69 , V_33 ) ;
}
} else
V_51 = - V_65 ;
V_95:
if ( V_86 . V_87 )
F_56 ( V_86 . V_87 ) ;
return V_51 ;
}
static int F_72 ( struct V_66 * V_67 ,
struct V_32 * V_33 ,
struct V_14 * V_5 )
{
struct V_98 * V_99 = F_73 () ;
struct V_85 * V_86 ;
int V_31 ;
int V_100 ;
if ( V_5 == NULL ) {
F_36 ( V_67 , L_8 ) ;
return 0 ;
}
V_86 = F_2 ( V_5 , struct V_85 , V_5 ) ;
if ( F_11 ( V_18 , & V_5 -> V_19 ) &&
! F_11 ( V_20 , & V_5 -> V_19 ) )
V_100 = V_86 -> V_87 -> V_101 ;
else
V_100 = 0 ;
F_37 ( V_67 , L_9 , V_86 -> V_88 , V_100 ) ;
for ( V_31 = 0 ; V_31 < V_100 ; V_31 ++ )
F_37 ( V_67 , L_10 , F_74 ( V_99 , F_69 ( V_86 -> V_87 , V_31 ) ) ) ;
F_37 ( V_67 , L_11 ) ;
return 0 ;
}
int F_75 ( struct V_55 * V_55 )
{
struct V_70 * V_71 = F_41 ( V_55 , V_72 ) ;
struct V_32 * V_33 ;
int V_51 ;
V_33 = F_76 ( & V_102 , V_55 ) ;
if ( F_77 ( V_33 ) )
return F_78 ( V_33 ) ;
V_51 = F_79 ( V_33 , V_55 ) ;
if ( V_51 ) {
F_80 ( V_33 , V_55 ) ;
return V_51 ;
}
V_71 -> V_103 = V_33 ;
return 0 ;
}
void F_81 ( struct V_55 * V_55 )
{
struct V_70 * V_71 = F_41 ( V_55 , V_72 ) ;
struct V_32 * V_33 = V_71 -> V_103 ;
V_71 -> V_103 = NULL ;
F_47 ( V_33 ) ;
F_82 ( V_33 , V_55 ) ;
F_80 ( V_33 , V_55 ) ;
}
static struct V_85 * F_70 ( struct V_32 * V_33 , T_3 V_88 )
{
struct V_85 V_86 ;
struct V_14 * V_69 ;
V_86 . V_88 = V_88 ;
V_69 = F_38 ( V_33 , & V_86 . V_5 , F_71 ( V_88 , V_97 ) ) ;
if ( V_69 )
return F_2 ( V_69 , struct V_85 , V_5 ) ;
else
return NULL ;
}
static struct V_104 * F_83 ( T_3 V_88 , struct V_105 * V_106 )
{
struct V_85 * V_86 ;
struct V_104 * V_87 ;
int V_107 ;
struct V_70 * V_71 = F_41 ( V_106 -> V_108 -> V_83 ,
V_72 ) ;
V_86 = F_70 ( V_71 -> V_103 , V_88 ) ;
if ( ! V_86 )
return F_84 ( - V_109 ) ;
V_107 = F_85 ( V_71 -> V_103 , & V_86 -> V_5 , & V_106 -> V_110 ) ;
switch ( V_107 ) {
case - V_64 :
return F_84 ( - V_64 ) ;
case - V_111 :
return F_84 ( - V_112 ) ;
case 0 :
V_87 = F_60 ( V_86 -> V_87 ) ;
F_44 ( & V_86 -> V_5 , V_71 -> V_103 ) ;
return V_87 ;
default:
return F_84 ( - V_109 ) ;
}
}
int
F_86 ( struct V_105 * V_106 )
{
struct V_45 * sin ;
struct V_47 * V_50 , V_113 ;
struct V_16 * V_74 ;
struct V_104 * V_87 ;
struct V_114 * V_115 = & V_106 -> V_116 ;
struct V_77 * V_78 = V_106 -> V_108 ;
struct V_55 * V_55 = V_78 -> V_83 ;
struct V_70 * V_71 = F_41 ( V_55 , V_72 ) ;
switch ( V_106 -> V_117 . V_118 ) {
case V_57 :
sin = F_87 ( V_106 ) ;
V_50 = & V_113 ;
F_29 ( sin -> V_60 . V_61 , & V_50 -> V_62 ) ;
break;
case V_59 :
V_50 = F_88 ( V_106 ) ;
break;
default:
F_89 () ;
}
V_106 -> V_119 = NULL ;
if ( V_106 -> V_120 == 0 )
return V_121 ;
V_74 = F_48 ( V_78 ) ;
if ( V_74 == NULL )
V_74 = F_32 ( V_71 -> V_73 , V_106 -> V_122 -> V_123 -> V_124 ,
& V_50 -> V_62 ) ;
if ( V_74 == NULL )
return V_125 ;
switch ( F_85 ( V_71 -> V_73 , & V_74 -> V_5 , & V_106 -> V_110 ) ) {
default:
F_89 () ;
case - V_111 :
return V_126 ;
case - V_109 :
return V_127 ;
case - V_64 :
return V_125 ;
case 0 :
V_106 -> V_119 = & V_74 -> V_21 -> V_5 ;
F_19 ( & V_106 -> V_119 -> V_12 ) ;
F_53 ( V_78 , V_74 ) ;
break;
}
V_87 = F_83 ( V_115 -> V_128 , V_106 ) ;
switch ( F_78 ( V_87 ) ) {
case - V_109 :
return V_127 ;
case - V_112 :
return V_126 ;
case - V_64 :
break;
default:
F_56 ( V_115 -> V_129 ) ;
V_115 -> V_129 = V_87 ;
}
return V_121 ;
}
static int
F_90 ( struct V_105 * V_106 , T_4 * V_130 )
{
struct V_131 * V_132 = & V_106 -> V_133 . V_134 [ 0 ] ;
struct V_131 * V_135 = & V_106 -> V_136 . V_134 [ 0 ] ;
struct V_114 * V_115 = & V_106 -> V_116 ;
V_115 -> V_129 = NULL ;
V_115 -> V_137 = NULL ;
V_106 -> V_119 = NULL ;
if ( V_132 -> V_138 < 3 * 4 )
return V_139 ;
if ( F_91 ( V_132 ) != 0 ) {
F_92 ( L_12 ) ;
* V_130 = V_140 ;
return V_125 ;
}
if ( F_91 ( V_132 ) != F_93 ( V_141 ) || F_91 ( V_132 ) != 0 ) {
F_92 ( L_13 ) ;
* V_130 = V_142 ;
return V_125 ;
}
V_115 -> V_128 = ( T_3 ) - 1 ;
V_115 -> V_143 = ( V_144 ) - 1 ;
V_115 -> V_129 = F_66 ( 0 ) ;
if ( V_115 -> V_129 == NULL )
return V_126 ;
F_94 ( V_135 , V_141 ) ;
F_94 ( V_135 , 0 ) ;
V_106 -> V_116 . V_145 = V_141 ;
return V_121 ;
}
static int
F_95 ( struct V_105 * V_106 )
{
if ( V_106 -> V_119 )
F_6 ( V_106 -> V_119 ) ;
V_106 -> V_119 = NULL ;
if ( V_106 -> V_116 . V_129 )
F_56 ( V_106 -> V_116 . V_129 ) ;
V_106 -> V_116 . V_129 = NULL ;
return 0 ;
}
static int
F_96 ( struct V_105 * V_106 , T_4 * V_130 )
{
struct V_131 * V_132 = & V_106 -> V_133 . V_134 [ 0 ] ;
struct V_131 * V_135 = & V_106 -> V_136 . V_134 [ 0 ] ;
struct V_114 * V_115 = & V_106 -> V_116 ;
T_5 V_146 , V_31 ;
int V_41 = V_132 -> V_138 ;
V_115 -> V_129 = NULL ;
V_115 -> V_137 = NULL ;
V_106 -> V_119 = NULL ;
if ( ( V_41 -= 3 * 4 ) < 0 )
return V_139 ;
F_91 ( V_132 ) ;
F_91 ( V_132 ) ;
V_146 = F_97 ( F_98 ( V_132 ) ) ;
if ( V_146 > 64 || ( V_41 -= ( V_146 + 3 ) * 4 ) < 0 )
goto V_147;
V_132 -> V_148 = ( void * ) ( ( T_4 * ) V_132 -> V_148 + V_146 ) ;
V_132 -> V_138 -= V_146 * 4 ;
V_115 -> V_128 = F_98 ( V_132 ) ;
V_115 -> V_143 = F_98 ( V_132 ) ;
V_146 = F_98 ( V_132 ) ;
if ( V_146 > 16 || ( V_41 -= ( V_146 + 2 ) * 4 ) < 0 )
goto V_147;
V_115 -> V_129 = F_66 ( V_146 ) ;
if ( V_115 -> V_129 == NULL )
return V_126 ;
for ( V_31 = 0 ; V_31 < V_146 ; V_31 ++ ) {
T_2 V_94 = F_67 ( & V_96 , F_98 ( V_132 ) ) ;
if ( ! F_68 ( V_94 ) )
goto V_147;
F_69 ( V_115 -> V_129 , V_31 ) = V_94 ;
}
if ( F_91 ( V_132 ) != F_93 ( V_141 ) || F_91 ( V_132 ) != 0 ) {
* V_130 = V_142 ;
return V_125 ;
}
F_94 ( V_135 , V_141 ) ;
F_94 ( V_135 , 0 ) ;
V_106 -> V_116 . V_145 = V_149 ;
return V_121 ;
V_147:
* V_130 = V_140 ;
return V_125 ;
}
static int
F_99 ( struct V_105 * V_106 )
{
if ( V_106 -> V_119 )
F_6 ( V_106 -> V_119 ) ;
V_106 -> V_119 = NULL ;
if ( V_106 -> V_116 . V_129 )
F_56 ( V_106 -> V_116 . V_129 ) ;
V_106 -> V_116 . V_129 = NULL ;
return 0 ;
}
int F_100 ( struct V_55 * V_55 )
{
struct V_70 * V_71 = F_41 ( V_55 , V_72 ) ;
struct V_32 * V_33 ;
int V_51 ;
V_33 = F_76 ( & V_150 , V_55 ) ;
if ( F_77 ( V_33 ) )
return F_78 ( V_33 ) ;
V_51 = F_79 ( V_33 , V_55 ) ;
if ( V_51 ) {
F_80 ( V_33 , V_55 ) ;
return V_51 ;
}
V_71 -> V_73 = V_33 ;
return 0 ;
}
void F_101 ( struct V_55 * V_55 )
{
struct V_70 * V_71 = F_41 ( V_55 , V_72 ) ;
struct V_32 * V_33 = V_71 -> V_73 ;
V_71 -> V_73 = NULL ;
F_47 ( V_33 ) ;
F_82 ( V_33 , V_55 ) ;
F_80 ( V_33 , V_55 ) ;
}
