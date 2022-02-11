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
static inline int F_12 ( T_1 V_22 )
{
int V_23 = ( V_24 V_25 ) V_22 ^ ( ( V_24 V_25 ) V_22 >> 16 ) ;
return ( V_23 ^ ( V_23 >> 8 ) ) & 0xff ;
}
static inline int F_13 ( struct V_26 V_22 )
{
return ( F_12 ( V_22 . V_27 [ 0 ] ) ^
F_12 ( V_22 . V_27 [ 1 ] ) ^
F_12 ( V_22 . V_27 [ 2 ] ) ^
F_12 ( V_22 . V_27 [ 3 ] ) ) ;
}
static int F_14 ( struct V_14 * V_28 , struct V_14 * V_29 )
{
struct V_16 * V_30 = F_2 ( V_28 , struct V_16 , V_5 ) ;
struct V_16 * V_8 = F_2 ( V_29 , struct V_16 , V_5 ) ;
return strcmp ( V_30 -> V_31 , V_8 -> V_31 ) == 0 &&
F_15 ( & V_30 -> V_32 , & V_8 -> V_32 ) ;
}
static void F_16 ( struct V_14 * V_29 , struct V_14 * V_33 )
{
struct V_16 * V_8 = F_2 ( V_29 , struct V_16 , V_5 ) ;
struct V_16 * V_15 = F_2 ( V_33 , struct V_16 , V_5 ) ;
strcpy ( V_8 -> V_31 , V_15 -> V_31 ) ;
V_8 -> V_32 = V_15 -> V_32 ;
}
static void F_17 ( struct V_14 * V_29 , struct V_14 * V_33 )
{
struct V_16 * V_8 = F_2 ( V_29 , struct V_16 , V_5 ) ;
struct V_16 * V_15 = F_2 ( V_33 , struct V_16 , V_5 ) ;
F_18 ( & V_15 -> V_21 -> V_5 . V_12 ) ;
V_8 -> V_21 = V_15 -> V_21 ;
}
static struct V_14 * F_19 ( void )
{
struct V_16 * V_34 = F_7 ( sizeof( * V_34 ) , V_11 ) ;
if ( V_34 )
return & V_34 -> V_5 ;
else
return NULL ;
}
static void F_20 ( struct V_35 * V_36 ,
struct V_14 * V_5 ,
char * * V_37 , int * V_38 )
{
char V_39 [ 40 ] ;
struct V_16 * V_17 = F_2 ( V_5 , struct V_16 , V_5 ) ;
if ( F_21 ( & ( V_17 -> V_32 ) ) ) {
snprintf ( V_39 , 20 , L_1 , & V_17 -> V_32 . V_27 [ 3 ] ) ;
} else {
snprintf ( V_39 , 40 , L_2 , & V_17 -> V_32 ) ;
}
F_22 ( V_37 , V_38 , V_17 -> V_31 ) ;
F_22 ( V_37 , V_38 , V_39 ) ;
( * V_37 ) [ - 1 ] = '\n' ;
}
static int F_23 ( struct V_35 * V_36 , struct V_14 * V_5 )
{
return F_24 ( V_36 , V_5 , F_20 ) ;
}
static int F_25 ( struct V_35 * V_36 ,
char * V_40 , int V_41 )
{
char * V_42 = V_40 ;
int V_43 ;
char V_44 [ 8 ] ;
union {
struct V_45 V_46 ;
struct V_47 V_48 ;
struct V_49 V_50 ;
} V_51 ;
struct V_49 V_52 ;
int V_53 ;
struct V_16 * V_54 ;
struct V_1 * V_2 ;
T_2 V_55 ;
if ( V_40 [ V_41 - 1 ] != '\n' )
return - V_56 ;
V_40 [ V_41 - 1 ] = 0 ;
V_43 = F_26 ( & V_40 , V_44 , sizeof( V_44 ) ) ;
if ( V_43 <= 0 ) return - V_56 ;
V_43 = F_26 ( & V_40 , V_42 , V_41 ) ;
if ( V_43 <= 0 ) return - V_56 ;
if ( F_27 ( V_36 -> V_57 , V_42 , V_43 , & V_51 . V_46 , sizeof( V_51 ) ) == 0 )
return - V_56 ;
switch ( V_51 . V_46 . V_58 ) {
case V_59 :
V_52 . V_60 = V_61 ;
F_28 ( V_51 . V_48 . V_62 . V_63 ,
& V_52 . V_64 ) ;
break;
#if F_29 ( V_65 )
case V_61 :
memcpy ( & V_52 , & V_51 . V_50 , sizeof( V_52 ) ) ;
break;
#endif
default:
return - V_56 ;
}
V_55 = F_30 ( & V_40 ) ;
if ( V_55 == 0 )
return - V_56 ;
V_43 = F_26 ( & V_40 , V_42 , V_41 ) ;
if ( V_43 < 0 ) return - V_56 ;
if ( V_43 ) {
V_2 = F_4 ( V_42 ) ;
if ( V_2 == NULL )
return - V_66 ;
} else
V_2 = NULL ;
V_54 = F_31 ( V_36 , V_44 , & V_52 . V_64 ) ;
if ( V_54 ) {
V_53 = F_32 ( V_36 , V_54 ,
F_2 ( V_2 , struct V_3 , V_5 ) ,
V_55 ) ;
} else
V_53 = - V_67 ;
if ( V_2 )
F_6 ( V_2 ) ;
F_33 () ;
return V_53 ;
}
static int F_34 ( struct V_68 * V_69 ,
struct V_35 * V_36 ,
struct V_14 * V_5 )
{
struct V_16 * V_17 ;
struct V_26 V_70 ;
char * V_2 = L_3 ;
if ( V_5 == NULL ) {
F_35 ( V_69 , L_4 ) ;
return 0 ;
}
V_17 = F_2 ( V_5 , struct V_16 , V_5 ) ;
V_70 = V_17 -> V_32 ;
if ( F_11 ( V_18 , & V_5 -> V_19 ) &&
! F_11 ( V_20 , & V_5 -> V_19 ) )
V_2 = V_17 -> V_21 -> V_5 . V_6 ;
if ( F_21 ( & V_70 ) ) {
F_36 ( V_69 , L_5 ,
V_17 -> V_31 , & V_70 . V_27 [ 3 ] , V_2 ) ;
} else {
F_36 ( V_69 , L_6 , V_17 -> V_31 , & V_70 , V_2 ) ;
}
return 0 ;
}
static struct V_16 * F_31 ( struct V_35 * V_36 , char * V_44 ,
struct V_26 * V_70 )
{
struct V_16 V_22 ;
struct V_14 * V_71 ;
strcpy ( V_22 . V_31 , V_44 ) ;
V_22 . V_32 = * V_70 ;
V_71 = F_37 ( V_36 , & V_22 . V_5 ,
F_38 ( V_44 , V_72 ) ^
F_13 ( * V_70 ) ) ;
if ( V_71 )
return F_2 ( V_71 , struct V_16 , V_5 ) ;
else
return NULL ;
}
static inline struct V_16 * F_39 ( struct V_57 * V_57 , char * V_44 ,
struct V_26 * V_70 )
{
struct V_73 * V_74 ;
V_74 = F_40 ( V_57 , V_75 ) ;
return F_31 ( V_74 -> V_76 , V_44 , V_70 ) ;
}
static int F_32 ( struct V_35 * V_36 , struct V_16 * V_77 ,
struct V_3 * V_78 , T_2 V_55 )
{
struct V_16 V_22 ;
struct V_14 * V_71 ;
V_22 . V_21 = V_78 ;
V_22 . V_5 . V_19 = 0 ;
if ( ! V_78 )
F_41 ( V_20 , & V_22 . V_5 . V_19 ) ;
V_22 . V_5 . V_79 = V_55 ;
V_71 = F_42 ( V_36 , & V_22 . V_5 , & V_77 -> V_5 ,
F_38 ( V_77 -> V_31 , V_72 ) ^
F_13 ( V_77 -> V_32 ) ) ;
if ( ! V_71 )
return - V_67 ;
F_43 ( V_71 , V_36 ) ;
return 0 ;
}
static inline int F_44 ( struct V_57 * V_57 , struct V_16 * V_77 ,
struct V_3 * V_78 , T_2 V_55 )
{
struct V_73 * V_74 ;
V_74 = F_40 ( V_57 , V_75 ) ;
return F_32 ( V_74 -> V_76 , V_77 , V_78 , V_55 ) ;
}
void F_45 ( struct V_57 * V_57 )
{
struct V_73 * V_74 ;
V_74 = F_40 ( V_57 , V_75 ) ;
F_46 ( V_74 -> V_76 ) ;
}
static inline struct V_16 *
F_47 ( struct V_80 * V_81 )
{
struct V_16 * V_77 = NULL ;
struct V_73 * V_74 ;
if ( F_11 ( V_82 , & V_81 -> V_83 ) ) {
F_48 ( & V_81 -> V_84 ) ;
V_77 = V_81 -> V_85 ;
if ( V_77 != NULL ) {
if ( ! F_49 ( & V_77 -> V_5 ) ) {
V_74 = F_40 ( V_81 -> V_86 , V_75 ) ;
V_81 -> V_85 = NULL ;
F_50 ( & V_81 -> V_84 ) ;
F_43 ( & V_77 -> V_5 , V_74 -> V_76 ) ;
return NULL ;
}
F_51 ( & V_77 -> V_5 ) ;
}
F_50 ( & V_81 -> V_84 ) ;
}
return V_77 ;
}
static inline void
F_52 ( struct V_80 * V_81 , struct V_16 * V_77 )
{
if ( F_11 ( V_82 , & V_81 -> V_83 ) ) {
F_48 ( & V_81 -> V_84 ) ;
if ( V_81 -> V_85 == NULL ) {
V_81 -> V_85 = V_77 ;
V_77 = NULL ;
}
F_50 ( & V_81 -> V_84 ) ;
}
if ( V_77 ) {
struct V_73 * V_74 ;
V_74 = F_40 ( V_81 -> V_86 , V_75 ) ;
F_43 ( & V_77 -> V_5 , V_74 -> V_76 ) ;
}
}
void
F_53 ( struct V_80 * V_87 )
{
struct V_16 * V_77 ;
V_77 = V_87 -> V_85 ;
if ( V_77 != NULL ) {
struct V_73 * V_74 ;
V_74 = F_40 ( V_87 -> V_86 , V_75 ) ;
F_43 ( & V_77 -> V_5 , V_74 -> V_76 ) ;
}
}
static void F_54 ( struct V_13 * V_13 )
{
struct V_14 * V_15 = F_2 ( V_13 , struct V_14 , V_12 ) ;
struct V_88 * V_89 = F_2 ( V_15 , struct V_88 , V_5 ) ;
if ( F_11 ( V_18 , & V_15 -> V_19 ) &&
! F_11 ( V_20 , & V_15 -> V_19 ) )
F_55 ( V_89 -> V_90 ) ;
F_3 ( V_89 ) ;
}
static int F_56 ( struct V_14 * V_28 , struct V_14 * V_29 )
{
struct V_88 * V_30 = F_2 ( V_28 , struct V_88 , V_5 ) ;
struct V_88 * V_8 = F_2 ( V_29 , struct V_88 , V_5 ) ;
return V_30 -> V_91 == V_8 -> V_91 ;
}
static void F_57 ( struct V_14 * V_29 , struct V_14 * V_33 )
{
struct V_88 * V_8 = F_2 ( V_29 , struct V_88 , V_5 ) ;
struct V_88 * V_15 = F_2 ( V_33 , struct V_88 , V_5 ) ;
V_8 -> V_91 = V_15 -> V_91 ;
}
static void F_58 ( struct V_14 * V_29 , struct V_14 * V_33 )
{
struct V_88 * V_8 = F_2 ( V_29 , struct V_88 , V_5 ) ;
struct V_88 * V_15 = F_2 ( V_33 , struct V_88 , V_5 ) ;
F_59 ( V_15 -> V_90 ) ;
V_8 -> V_90 = V_15 -> V_90 ;
}
static struct V_14 * F_60 ( void )
{
struct V_88 * V_92 = F_7 ( sizeof( * V_92 ) , V_11 ) ;
if ( V_92 )
return & V_92 -> V_5 ;
else
return NULL ;
}
static void F_61 ( struct V_35 * V_36 ,
struct V_14 * V_5 ,
char * * V_37 , int * V_38 )
{
char V_93 [ 20 ] ;
struct V_88 * V_89 = F_2 ( V_5 , struct V_88 , V_5 ) ;
snprintf ( V_93 , 20 , L_7 , V_89 -> V_91 ) ;
F_22 ( V_37 , V_38 , V_93 ) ;
( * V_37 ) [ - 1 ] = '\n' ;
}
static int F_62 ( struct V_35 * V_36 , struct V_14 * V_5 )
{
return F_24 ( V_36 , V_5 , F_61 ) ;
}
static int F_63 ( struct V_35 * V_36 ,
char * V_40 , int V_41 )
{
int V_91 ;
int V_94 ;
int V_7 ;
int V_34 ;
int V_53 ;
T_2 V_55 ;
struct V_88 V_89 , * V_95 ;
if ( V_40 [ V_41 - 1 ] != '\n' )
return - V_56 ;
V_40 [ V_41 - 1 ] = 0 ;
V_7 = F_64 ( & V_40 , & V_91 ) ;
if ( V_7 )
return - V_56 ;
V_89 . V_91 = V_91 ;
V_55 = F_30 ( & V_40 ) ;
if ( V_55 == 0 )
return - V_56 ;
V_7 = F_64 ( & V_40 , & V_94 ) ;
if ( V_7 || V_94 < 0 || V_94 > 8192 )
return - V_56 ;
V_89 . V_90 = F_65 ( V_94 ) ;
if ( ! V_89 . V_90 )
return - V_67 ;
for ( V_34 = 0 ; V_34 < V_94 ; V_34 ++ ) {
int V_96 ;
T_3 V_97 ;
V_7 = F_64 ( & V_40 , & V_96 ) ;
V_53 = - V_56 ;
if ( V_7 )
goto V_98;
V_97 = F_66 ( & V_99 , V_96 ) ;
if ( ! F_67 ( V_97 ) )
goto V_98;
F_68 ( V_89 . V_90 , V_34 ) = V_97 ;
}
V_95 = F_69 ( V_36 , V_91 ) ;
if ( V_95 ) {
struct V_14 * V_71 ;
V_89 . V_5 . V_19 = 0 ;
V_89 . V_5 . V_79 = V_55 ;
V_71 = F_42 ( V_36 ,
& V_89 . V_5 , & V_95 -> V_5 ,
F_70 ( V_91 , V_100 ) ) ;
if ( ! V_71 )
V_53 = - V_67 ;
else {
V_53 = 0 ;
F_43 ( V_71 , V_36 ) ;
}
} else
V_53 = - V_67 ;
V_98:
if ( V_89 . V_90 )
F_55 ( V_89 . V_90 ) ;
return V_53 ;
}
static int F_71 ( struct V_68 * V_69 ,
struct V_35 * V_36 ,
struct V_14 * V_5 )
{
struct V_101 * V_102 = F_72 () ;
struct V_88 * V_89 ;
int V_34 ;
int V_103 ;
if ( V_5 == NULL ) {
F_35 ( V_69 , L_8 ) ;
return 0 ;
}
V_89 = F_2 ( V_5 , struct V_88 , V_5 ) ;
if ( F_11 ( V_18 , & V_5 -> V_19 ) &&
! F_11 ( V_20 , & V_5 -> V_19 ) )
V_103 = V_89 -> V_90 -> V_104 ;
else
V_103 = 0 ;
F_36 ( V_69 , L_9 , V_89 -> V_91 , V_103 ) ;
for ( V_34 = 0 ; V_34 < V_103 ; V_34 ++ )
F_36 ( V_69 , L_10 , F_73 ( V_102 , F_68 ( V_89 -> V_90 , V_34 ) ) ) ;
F_36 ( V_69 , L_11 ) ;
return 0 ;
}
int F_74 ( struct V_57 * V_57 )
{
struct V_73 * V_74 = F_40 ( V_57 , V_75 ) ;
struct V_35 * V_36 ;
int V_53 ;
V_36 = F_75 ( & V_105 , V_57 ) ;
if ( F_76 ( V_36 ) )
return F_77 ( V_36 ) ;
V_53 = F_78 ( V_36 , V_57 ) ;
if ( V_53 ) {
F_79 ( V_36 , V_57 ) ;
return V_53 ;
}
V_74 -> V_106 = V_36 ;
return 0 ;
}
void F_80 ( struct V_57 * V_57 )
{
struct V_73 * V_74 = F_40 ( V_57 , V_75 ) ;
struct V_35 * V_36 = V_74 -> V_106 ;
V_74 -> V_106 = NULL ;
F_46 ( V_36 ) ;
F_81 ( V_36 , V_57 ) ;
F_79 ( V_36 , V_57 ) ;
}
static struct V_88 * F_69 ( struct V_35 * V_36 , T_4 V_91 )
{
struct V_88 V_89 ;
struct V_14 * V_71 ;
V_89 . V_91 = V_91 ;
V_71 = F_37 ( V_36 , & V_89 . V_5 , F_70 ( V_91 , V_100 ) ) ;
if ( V_71 )
return F_2 ( V_71 , struct V_88 , V_5 ) ;
else
return NULL ;
}
static struct V_107 * F_82 ( T_4 V_91 , struct V_108 * V_109 )
{
struct V_88 * V_89 ;
struct V_107 * V_90 ;
int V_110 ;
struct V_73 * V_74 = F_40 ( V_109 -> V_111 -> V_86 ,
V_75 ) ;
V_89 = F_69 ( V_74 -> V_106 , V_91 ) ;
if ( ! V_89 )
return F_83 ( - V_112 ) ;
V_110 = F_84 ( V_74 -> V_106 , & V_89 -> V_5 , & V_109 -> V_113 ) ;
switch ( V_110 ) {
case - V_66 :
return F_83 ( - V_66 ) ;
case - V_114 :
return F_83 ( - V_115 ) ;
case 0 :
V_90 = F_59 ( V_89 -> V_90 ) ;
F_43 ( & V_89 -> V_5 , V_74 -> V_106 ) ;
return V_90 ;
default:
return F_83 ( - V_112 ) ;
}
}
int
F_85 ( struct V_108 * V_109 )
{
struct V_47 * sin ;
struct V_49 * V_52 , V_116 ;
struct V_16 * V_77 ;
struct V_107 * V_90 ;
struct V_117 * V_118 = & V_109 -> V_119 ;
struct V_80 * V_81 = V_109 -> V_111 ;
struct V_57 * V_57 = V_81 -> V_86 ;
struct V_73 * V_74 = F_40 ( V_57 , V_75 ) ;
switch ( V_109 -> V_120 . V_121 ) {
case V_59 :
sin = F_86 ( V_109 ) ;
V_52 = & V_116 ;
F_28 ( sin -> V_62 . V_63 , & V_52 -> V_64 ) ;
break;
case V_61 :
V_52 = F_87 ( V_109 ) ;
break;
default:
F_88 () ;
}
V_109 -> V_122 = NULL ;
if ( V_109 -> V_123 == 0 )
return V_124 ;
V_77 = F_47 ( V_81 ) ;
if ( V_77 == NULL )
V_77 = F_31 ( V_74 -> V_76 , V_109 -> V_125 -> V_126 -> V_127 ,
& V_52 -> V_64 ) ;
if ( V_77 == NULL )
return V_128 ;
switch ( F_84 ( V_74 -> V_76 , & V_77 -> V_5 , & V_109 -> V_113 ) ) {
default:
F_88 () ;
case - V_114 :
return V_129 ;
case - V_112 :
return V_130 ;
case - V_66 :
return V_128 ;
case 0 :
V_109 -> V_122 = & V_77 -> V_21 -> V_5 ;
F_18 ( & V_109 -> V_122 -> V_12 ) ;
F_52 ( V_81 , V_77 ) ;
break;
}
V_90 = F_82 ( V_118 -> V_131 , V_109 ) ;
switch ( F_77 ( V_90 ) ) {
case - V_112 :
return V_130 ;
case - V_115 :
return V_129 ;
case - V_66 :
break;
default:
F_55 ( V_118 -> V_132 ) ;
V_118 -> V_132 = V_90 ;
}
return V_124 ;
}
static int
F_89 ( struct V_108 * V_109 , T_1 * V_133 )
{
struct V_134 * V_135 = & V_109 -> V_136 . V_137 [ 0 ] ;
struct V_134 * V_138 = & V_109 -> V_139 . V_137 [ 0 ] ;
struct V_117 * V_118 = & V_109 -> V_119 ;
V_118 -> V_132 = NULL ;
V_118 -> V_140 = NULL ;
V_109 -> V_122 = NULL ;
if ( V_135 -> V_141 < 3 * 4 )
return V_142 ;
if ( F_90 ( V_135 ) != 0 ) {
F_91 ( L_12 ) ;
* V_133 = V_143 ;
return V_128 ;
}
if ( F_90 ( V_135 ) != F_92 ( V_144 ) || F_90 ( V_135 ) != 0 ) {
F_91 ( L_13 ) ;
* V_133 = V_145 ;
return V_128 ;
}
V_118 -> V_131 = ( T_4 ) - 1 ;
V_118 -> V_146 = ( V_147 ) - 1 ;
V_118 -> V_132 = F_65 ( 0 ) ;
if ( V_118 -> V_132 == NULL )
return V_129 ;
F_93 ( V_138 , V_144 ) ;
F_93 ( V_138 , 0 ) ;
V_109 -> V_119 . V_148 = V_144 ;
return V_124 ;
}
static int
F_94 ( struct V_108 * V_109 )
{
if ( V_109 -> V_122 )
F_6 ( V_109 -> V_122 ) ;
V_109 -> V_122 = NULL ;
if ( V_109 -> V_119 . V_132 )
F_55 ( V_109 -> V_119 . V_132 ) ;
V_109 -> V_119 . V_132 = NULL ;
return 0 ;
}
static int
F_95 ( struct V_108 * V_109 , T_1 * V_133 )
{
struct V_134 * V_135 = & V_109 -> V_136 . V_137 [ 0 ] ;
struct V_134 * V_138 = & V_109 -> V_139 . V_137 [ 0 ] ;
struct V_117 * V_118 = & V_109 -> V_119 ;
V_25 V_149 , V_34 ;
int V_43 = V_135 -> V_141 ;
V_118 -> V_132 = NULL ;
V_118 -> V_140 = NULL ;
V_109 -> V_122 = NULL ;
if ( ( V_43 -= 3 * 4 ) < 0 )
return V_142 ;
F_90 ( V_135 ) ;
F_90 ( V_135 ) ;
V_149 = F_96 ( F_97 ( V_135 ) ) ;
if ( V_149 > 64 || ( V_43 -= ( V_149 + 3 ) * 4 ) < 0 )
goto V_150;
V_135 -> V_151 = ( void * ) ( ( T_1 * ) V_135 -> V_151 + V_149 ) ;
V_135 -> V_141 -= V_149 * 4 ;
V_118 -> V_131 = F_97 ( V_135 ) ;
V_118 -> V_146 = F_97 ( V_135 ) ;
V_149 = F_97 ( V_135 ) ;
if ( V_149 > 16 || ( V_43 -= ( V_149 + 2 ) * 4 ) < 0 )
goto V_150;
V_118 -> V_132 = F_65 ( V_149 ) ;
if ( V_118 -> V_132 == NULL )
return V_129 ;
for ( V_34 = 0 ; V_34 < V_149 ; V_34 ++ ) {
T_3 V_97 = F_66 ( & V_99 , F_97 ( V_135 ) ) ;
if ( ! F_67 ( V_97 ) )
goto V_150;
F_68 ( V_118 -> V_132 , V_34 ) = V_97 ;
}
if ( F_90 ( V_135 ) != F_92 ( V_144 ) || F_90 ( V_135 ) != 0 ) {
* V_133 = V_145 ;
return V_128 ;
}
F_93 ( V_138 , V_144 ) ;
F_93 ( V_138 , 0 ) ;
V_109 -> V_119 . V_148 = V_152 ;
return V_124 ;
V_150:
* V_133 = V_143 ;
return V_128 ;
}
static int
F_98 ( struct V_108 * V_109 )
{
if ( V_109 -> V_122 )
F_6 ( V_109 -> V_122 ) ;
V_109 -> V_122 = NULL ;
if ( V_109 -> V_119 . V_132 )
F_55 ( V_109 -> V_119 . V_132 ) ;
V_109 -> V_119 . V_132 = NULL ;
return 0 ;
}
int F_99 ( struct V_57 * V_57 )
{
struct V_73 * V_74 = F_40 ( V_57 , V_75 ) ;
struct V_35 * V_36 ;
int V_53 ;
V_36 = F_75 ( & V_153 , V_57 ) ;
if ( F_76 ( V_36 ) )
return F_77 ( V_36 ) ;
V_53 = F_78 ( V_36 , V_57 ) ;
if ( V_53 ) {
F_79 ( V_36 , V_57 ) ;
return V_53 ;
}
V_74 -> V_76 = V_36 ;
return 0 ;
}
void F_100 ( struct V_57 * V_57 )
{
struct V_73 * V_74 = F_40 ( V_57 , V_75 ) ;
struct V_35 * V_36 = V_74 -> V_76 ;
V_74 -> V_76 = NULL ;
F_46 ( V_36 ) ;
F_81 ( V_36 , V_57 ) ;
F_79 ( V_36 , V_57 ) ;
}
