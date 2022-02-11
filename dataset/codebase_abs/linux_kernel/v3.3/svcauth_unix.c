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
if ( F_27 ( V_42 , V_43 , & V_51 . V_46 , sizeof( V_51 ) ) == 0 )
return - V_56 ;
switch ( V_51 . V_46 . V_57 ) {
case V_58 :
V_52 . V_59 = V_60 ;
F_28 ( V_51 . V_48 . V_61 . V_62 ,
& V_52 . V_63 ) ;
break;
#if F_29 ( V_64 )
case V_60 :
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
return - V_65 ;
} else
V_2 = NULL ;
V_54 = F_31 ( V_36 , V_44 , & V_52 . V_63 ) ;
if ( V_54 ) {
V_53 = F_32 ( V_36 , V_54 ,
F_2 ( V_2 , struct V_3 , V_5 ) ,
V_55 ) ;
} else
V_53 = - V_66 ;
if ( V_2 )
F_6 ( V_2 ) ;
F_33 () ;
return V_53 ;
}
static int F_34 ( struct V_67 * V_68 ,
struct V_35 * V_36 ,
struct V_14 * V_5 )
{
struct V_16 * V_17 ;
struct V_26 V_69 ;
char * V_2 = L_3 ;
if ( V_5 == NULL ) {
F_35 ( V_68 , L_4 ) ;
return 0 ;
}
V_17 = F_2 ( V_5 , struct V_16 , V_5 ) ;
V_69 = V_17 -> V_32 ;
if ( F_11 ( V_18 , & V_5 -> V_19 ) &&
! F_11 ( V_20 , & V_5 -> V_19 ) )
V_2 = V_17 -> V_21 -> V_5 . V_6 ;
if ( F_21 ( & V_69 ) ) {
F_36 ( V_68 , L_5 ,
V_17 -> V_31 , & V_69 . V_27 [ 3 ] , V_2 ) ;
} else {
F_36 ( V_68 , L_6 , V_17 -> V_31 , & V_69 , V_2 ) ;
}
return 0 ;
}
static struct V_16 * F_31 ( struct V_35 * V_36 , char * V_44 ,
struct V_26 * V_69 )
{
struct V_16 V_22 ;
struct V_14 * V_70 ;
strcpy ( V_22 . V_31 , V_44 ) ;
V_22 . V_32 = * V_69 ;
V_70 = F_37 ( V_36 , & V_22 . V_5 ,
F_38 ( V_44 , V_71 ) ^
F_13 ( * V_69 ) ) ;
if ( V_70 )
return F_2 ( V_70 , struct V_16 , V_5 ) ;
else
return NULL ;
}
static inline struct V_16 * F_39 ( struct V_72 * V_72 , char * V_44 ,
struct V_26 * V_69 )
{
struct V_73 * V_74 ;
V_74 = F_40 ( V_72 , V_75 ) ;
return F_31 ( V_74 -> V_76 , V_44 , V_69 ) ;
}
static int F_32 ( struct V_35 * V_36 , struct V_16 * V_77 ,
struct V_3 * V_78 , T_2 V_55 )
{
struct V_16 V_22 ;
struct V_14 * V_70 ;
V_22 . V_21 = V_78 ;
V_22 . V_5 . V_19 = 0 ;
if ( ! V_78 )
F_41 ( V_20 , & V_22 . V_5 . V_19 ) ;
V_22 . V_5 . V_79 = V_55 ;
V_70 = F_42 ( V_36 , & V_22 . V_5 , & V_77 -> V_5 ,
F_38 ( V_77 -> V_31 , V_71 ) ^
F_13 ( V_77 -> V_32 ) ) ;
if ( ! V_70 )
return - V_66 ;
F_43 ( V_70 , V_36 ) ;
return 0 ;
}
static inline int F_44 ( struct V_72 * V_72 , struct V_16 * V_77 ,
struct V_3 * V_78 , T_2 V_55 )
{
struct V_73 * V_74 ;
V_74 = F_40 ( V_72 , V_75 ) ;
return F_32 ( V_74 -> V_76 , V_77 , V_78 , V_55 ) ;
}
void F_45 ( void )
{
struct V_72 * V_72 ;
F_46 (net) {
struct V_73 * V_74 ;
V_74 = F_40 ( V_72 , V_75 ) ;
F_47 ( V_74 -> V_76 ) ;
}
}
static inline struct V_16 *
F_48 ( struct V_80 * V_81 )
{
struct V_16 * V_77 = NULL ;
struct V_73 * V_74 ;
if ( F_11 ( V_82 , & V_81 -> V_83 ) ) {
F_49 ( & V_81 -> V_84 ) ;
V_77 = V_81 -> V_85 ;
if ( V_77 != NULL ) {
if ( ! F_50 ( & V_77 -> V_5 ) ) {
V_74 = F_40 ( V_81 -> V_86 , V_75 ) ;
V_81 -> V_85 = NULL ;
F_51 ( & V_81 -> V_84 ) ;
F_43 ( & V_77 -> V_5 , V_74 -> V_76 ) ;
return NULL ;
}
F_52 ( & V_77 -> V_5 ) ;
}
F_51 ( & V_81 -> V_84 ) ;
}
return V_77 ;
}
static inline void
F_53 ( struct V_80 * V_81 , struct V_16 * V_77 )
{
if ( F_11 ( V_82 , & V_81 -> V_83 ) ) {
F_49 ( & V_81 -> V_84 ) ;
if ( V_81 -> V_85 == NULL ) {
V_81 -> V_85 = V_77 ;
V_77 = NULL ;
}
F_51 ( & V_81 -> V_84 ) ;
}
if ( V_77 ) {
struct V_73 * V_74 ;
V_74 = F_40 ( V_81 -> V_86 , V_75 ) ;
F_43 ( & V_77 -> V_5 , V_74 -> V_76 ) ;
}
}
void
F_54 ( struct V_80 * V_87 )
{
struct V_16 * V_77 ;
V_77 = V_87 -> V_85 ;
if ( V_77 != NULL ) {
struct V_73 * V_74 ;
V_74 = F_40 ( V_87 -> V_86 , V_75 ) ;
F_43 ( & V_77 -> V_5 , V_74 -> V_76 ) ;
}
}
static void F_55 ( struct V_13 * V_13 )
{
struct V_14 * V_15 = F_2 ( V_13 , struct V_14 , V_12 ) ;
struct V_88 * V_89 = F_2 ( V_15 , struct V_88 , V_5 ) ;
if ( F_11 ( V_18 , & V_15 -> V_19 ) &&
! F_11 ( V_20 , & V_15 -> V_19 ) )
F_56 ( V_89 -> V_90 ) ;
F_3 ( V_89 ) ;
}
static int F_57 ( struct V_14 * V_28 , struct V_14 * V_29 )
{
struct V_88 * V_30 = F_2 ( V_28 , struct V_88 , V_5 ) ;
struct V_88 * V_8 = F_2 ( V_29 , struct V_88 , V_5 ) ;
return V_30 -> V_91 == V_8 -> V_91 ;
}
static void F_58 ( struct V_14 * V_29 , struct V_14 * V_33 )
{
struct V_88 * V_8 = F_2 ( V_29 , struct V_88 , V_5 ) ;
struct V_88 * V_15 = F_2 ( V_33 , struct V_88 , V_5 ) ;
V_8 -> V_91 = V_15 -> V_91 ;
}
static void F_59 ( struct V_14 * V_29 , struct V_14 * V_33 )
{
struct V_88 * V_8 = F_2 ( V_29 , struct V_88 , V_5 ) ;
struct V_88 * V_15 = F_2 ( V_33 , struct V_88 , V_5 ) ;
F_60 ( V_15 -> V_90 ) ;
V_8 -> V_90 = V_15 -> V_90 ;
}
static struct V_14 * F_61 ( void )
{
struct V_88 * V_92 = F_7 ( sizeof( * V_92 ) , V_11 ) ;
if ( V_92 )
return & V_92 -> V_5 ;
else
return NULL ;
}
static void F_62 ( struct V_35 * V_36 ,
struct V_14 * V_5 ,
char * * V_37 , int * V_38 )
{
char V_93 [ 20 ] ;
struct V_88 * V_89 = F_2 ( V_5 , struct V_88 , V_5 ) ;
snprintf ( V_93 , 20 , L_7 , V_89 -> V_91 ) ;
F_22 ( V_37 , V_38 , V_93 ) ;
( * V_37 ) [ - 1 ] = '\n' ;
}
static int F_63 ( struct V_35 * V_36 , struct V_14 * V_5 )
{
return F_24 ( V_36 , V_5 , F_62 ) ;
}
static int F_64 ( struct V_35 * V_36 ,
char * V_40 , int V_41 )
{
int V_91 ;
int V_94 ;
int V_7 ;
int V_34 ;
int V_53 ;
T_2 V_55 ;
struct V_88 V_89 , * V_95 ;
if ( V_41 <= 0 || V_40 [ V_41 - 1 ] != '\n' )
return - V_56 ;
V_40 [ V_41 - 1 ] = 0 ;
V_7 = F_65 ( & V_40 , & V_91 ) ;
if ( V_7 )
return - V_56 ;
V_89 . V_91 = V_91 ;
V_55 = F_30 ( & V_40 ) ;
if ( V_55 == 0 )
return - V_56 ;
V_7 = F_65 ( & V_40 , & V_94 ) ;
if ( V_7 || V_94 < 0 || V_94 > 8192 )
return - V_56 ;
V_89 . V_90 = F_66 ( V_94 ) ;
if ( ! V_89 . V_90 )
return - V_66 ;
for ( V_34 = 0 ; V_34 < V_94 ; V_34 ++ ) {
int V_96 ;
V_7 = F_65 ( & V_40 , & V_96 ) ;
V_53 = - V_56 ;
if ( V_7 )
goto V_97;
F_67 ( V_89 . V_90 , V_34 ) = V_96 ;
}
V_95 = F_68 ( V_91 ) ;
if ( V_95 ) {
struct V_14 * V_70 ;
V_89 . V_5 . V_19 = 0 ;
V_89 . V_5 . V_79 = V_55 ;
V_70 = F_42 ( & V_98 ,
& V_89 . V_5 , & V_95 -> V_5 ,
F_69 ( V_91 , V_99 ) ) ;
if ( ! V_70 )
V_53 = - V_66 ;
else {
V_53 = 0 ;
F_43 ( V_70 , & V_98 ) ;
}
} else
V_53 = - V_66 ;
V_97:
if ( V_89 . V_90 )
F_56 ( V_89 . V_90 ) ;
return V_53 ;
}
static int F_70 ( struct V_67 * V_68 ,
struct V_35 * V_36 ,
struct V_14 * V_5 )
{
struct V_88 * V_89 ;
int V_34 ;
int V_100 ;
if ( V_5 == NULL ) {
F_35 ( V_68 , L_8 ) ;
return 0 ;
}
V_89 = F_2 ( V_5 , struct V_88 , V_5 ) ;
if ( F_11 ( V_18 , & V_5 -> V_19 ) &&
! F_11 ( V_20 , & V_5 -> V_19 ) )
V_100 = V_89 -> V_90 -> V_101 ;
else
V_100 = 0 ;
F_36 ( V_68 , L_9 , V_89 -> V_91 , V_100 ) ;
for ( V_34 = 0 ; V_34 < V_100 ; V_34 ++ )
F_36 ( V_68 , L_10 , F_67 ( V_89 -> V_90 , V_34 ) ) ;
F_36 ( V_68 , L_11 ) ;
return 0 ;
}
static struct V_88 * F_68 ( T_3 V_91 )
{
struct V_88 V_89 ;
struct V_14 * V_70 ;
V_89 . V_91 = V_91 ;
V_70 = F_37 ( & V_98 , & V_89 . V_5 ,
F_69 ( V_91 , V_99 ) ) ;
if ( V_70 )
return F_2 ( V_70 , struct V_88 , V_5 ) ;
else
return NULL ;
}
static struct V_102 * F_71 ( T_3 V_91 , struct V_103 * V_104 )
{
struct V_88 * V_89 ;
struct V_102 * V_90 ;
int V_105 ;
V_89 = F_68 ( V_91 ) ;
if ( ! V_89 )
return F_72 ( - V_106 ) ;
V_105 = F_73 ( & V_98 , & V_89 -> V_5 , & V_104 -> V_107 ) ;
switch ( V_105 ) {
case - V_65 :
return F_72 ( - V_65 ) ;
case - V_108 :
return F_72 ( - V_109 ) ;
case 0 :
V_90 = F_60 ( V_89 -> V_90 ) ;
F_43 ( & V_89 -> V_5 , & V_98 ) ;
return V_90 ;
default:
return F_72 ( - V_106 ) ;
}
}
int
F_74 ( struct V_103 * V_104 )
{
struct V_47 * sin ;
struct V_49 * V_52 , V_110 ;
struct V_16 * V_77 ;
struct V_102 * V_90 ;
struct V_111 * V_112 = & V_104 -> V_113 ;
struct V_80 * V_81 = V_104 -> V_114 ;
struct V_72 * V_72 = V_81 -> V_86 ;
struct V_73 * V_74 = F_40 ( V_72 , V_75 ) ;
switch ( V_104 -> V_115 . V_116 ) {
case V_58 :
sin = F_75 ( V_104 ) ;
V_52 = & V_110 ;
F_28 ( sin -> V_61 . V_62 , & V_52 -> V_63 ) ;
break;
case V_60 :
V_52 = F_76 ( V_104 ) ;
break;
default:
F_77 () ;
}
V_104 -> V_117 = NULL ;
if ( V_104 -> V_118 == 0 )
return V_119 ;
V_77 = F_48 ( V_81 ) ;
if ( V_77 == NULL )
V_77 = F_31 ( V_74 -> V_76 , V_104 -> V_120 -> V_121 -> V_122 ,
& V_52 -> V_63 ) ;
if ( V_77 == NULL )
return V_123 ;
switch ( F_73 ( V_74 -> V_76 , & V_77 -> V_5 , & V_104 -> V_107 ) ) {
default:
F_77 () ;
case - V_108 :
return V_124 ;
case - V_106 :
return V_125 ;
case - V_65 :
return V_123 ;
case 0 :
V_104 -> V_117 = & V_77 -> V_21 -> V_5 ;
F_18 ( & V_104 -> V_117 -> V_12 ) ;
F_53 ( V_81 , V_77 ) ;
break;
}
V_90 = F_71 ( V_112 -> V_126 , V_104 ) ;
switch ( F_78 ( V_90 ) ) {
case - V_106 :
return V_125 ;
case - V_109 :
return V_124 ;
case - V_65 :
break;
default:
F_56 ( V_112 -> V_127 ) ;
V_112 -> V_127 = V_90 ;
}
return V_119 ;
}
static int
F_79 ( struct V_103 * V_104 , T_1 * V_128 )
{
struct V_129 * V_130 = & V_104 -> V_131 . V_132 [ 0 ] ;
struct V_129 * V_133 = & V_104 -> V_134 . V_132 [ 0 ] ;
struct V_111 * V_112 = & V_104 -> V_113 ;
V_112 -> V_127 = NULL ;
V_104 -> V_117 = NULL ;
if ( V_130 -> V_135 < 3 * 4 )
return V_136 ;
if ( F_80 ( V_130 ) != 0 ) {
F_81 ( L_12 ) ;
* V_128 = V_137 ;
return V_123 ;
}
if ( F_80 ( V_130 ) != F_82 ( V_138 ) || F_80 ( V_130 ) != 0 ) {
F_81 ( L_13 ) ;
* V_128 = V_139 ;
return V_123 ;
}
V_112 -> V_126 = ( T_3 ) - 1 ;
V_112 -> V_140 = ( V_141 ) - 1 ;
V_112 -> V_127 = F_66 ( 0 ) ;
if ( V_112 -> V_127 == NULL )
return V_124 ;
F_83 ( V_133 , V_138 ) ;
F_83 ( V_133 , 0 ) ;
V_104 -> V_142 = V_138 ;
return V_119 ;
}
static int
F_84 ( struct V_103 * V_104 )
{
if ( V_104 -> V_117 )
F_6 ( V_104 -> V_117 ) ;
V_104 -> V_117 = NULL ;
if ( V_104 -> V_113 . V_127 )
F_56 ( V_104 -> V_113 . V_127 ) ;
V_104 -> V_113 . V_127 = NULL ;
return 0 ;
}
static int
F_85 ( struct V_103 * V_104 , T_1 * V_128 )
{
struct V_129 * V_130 = & V_104 -> V_131 . V_132 [ 0 ] ;
struct V_129 * V_133 = & V_104 -> V_134 . V_132 [ 0 ] ;
struct V_111 * V_112 = & V_104 -> V_113 ;
V_25 V_143 , V_34 ;
int V_43 = V_130 -> V_135 ;
V_112 -> V_127 = NULL ;
V_104 -> V_117 = NULL ;
if ( ( V_43 -= 3 * 4 ) < 0 )
return V_136 ;
F_80 ( V_130 ) ;
F_80 ( V_130 ) ;
V_143 = F_86 ( F_87 ( V_130 ) ) ;
if ( V_143 > 64 || ( V_43 -= ( V_143 + 3 ) * 4 ) < 0 )
goto V_144;
V_130 -> V_145 = ( void * ) ( ( T_1 * ) V_130 -> V_145 + V_143 ) ;
V_130 -> V_135 -= V_143 * 4 ;
V_112 -> V_126 = F_87 ( V_130 ) ;
V_112 -> V_140 = F_87 ( V_130 ) ;
V_143 = F_87 ( V_130 ) ;
if ( V_143 > 16 || ( V_43 -= ( V_143 + 2 ) * 4 ) < 0 )
goto V_144;
V_112 -> V_127 = F_66 ( V_143 ) ;
if ( V_112 -> V_127 == NULL )
return V_124 ;
for ( V_34 = 0 ; V_34 < V_143 ; V_34 ++ )
F_67 ( V_112 -> V_127 , V_34 ) = F_87 ( V_130 ) ;
if ( F_80 ( V_130 ) != F_82 ( V_138 ) || F_80 ( V_130 ) != 0 ) {
* V_128 = V_139 ;
return V_123 ;
}
F_83 ( V_133 , V_138 ) ;
F_83 ( V_133 , 0 ) ;
V_104 -> V_142 = V_146 ;
return V_119 ;
V_144:
* V_128 = V_137 ;
return V_123 ;
}
static int
F_88 ( struct V_103 * V_104 )
{
if ( V_104 -> V_117 )
F_6 ( V_104 -> V_117 ) ;
V_104 -> V_117 = NULL ;
if ( V_104 -> V_113 . V_127 )
F_56 ( V_104 -> V_113 . V_127 ) ;
V_104 -> V_113 . V_127 = NULL ;
return 0 ;
}
int F_89 ( struct V_72 * V_72 )
{
int V_53 = - V_66 ;
struct V_35 * V_36 ;
struct V_14 * * V_147 ;
struct V_73 * V_74 = F_40 ( V_72 , V_75 ) ;
V_36 = F_90 ( sizeof( struct V_35 ) , V_11 ) ;
if ( V_36 == NULL )
goto V_148;
V_147 = F_90 ( V_149 * sizeof( struct V_14 * ) , V_11 ) ;
if ( V_147 == NULL )
goto V_150;
V_36 -> V_151 = V_152 ,
V_36 -> V_153 = V_149 ,
V_36 -> V_154 = V_147 ,
V_36 -> V_6 = L_14 ,
V_36 -> F_43 = F_10 ,
V_36 -> V_155 = F_23 ,
V_36 -> V_156 = F_25 ,
V_36 -> V_157 = F_34 ,
V_36 -> V_158 = F_14 ,
V_36 -> V_159 = F_16 ,
V_36 -> F_17 = F_17 ,
V_36 -> V_160 = F_19 ,
V_53 = F_91 ( V_36 , V_72 ) ;
if ( V_53 )
goto V_161;
V_74 -> V_76 = V_36 ;
return 0 ;
V_161:
F_3 ( V_147 ) ;
V_150:
F_3 ( V_36 ) ;
V_148:
return V_53 ;
}
void F_92 ( struct V_72 * V_72 )
{
struct V_73 * V_74 ;
V_74 = F_40 ( V_72 , V_75 ) ;
F_47 ( V_74 -> V_76 ) ;
F_93 ( V_74 -> V_76 , V_72 ) ;
F_3 ( V_74 -> V_76 -> V_154 ) ;
F_3 ( V_74 -> V_76 ) ;
}
