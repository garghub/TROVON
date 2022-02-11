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
void F_45 ( void )
{
struct V_57 * V_57 ;
F_46 (net) {
struct V_73 * V_74 ;
V_74 = F_40 ( V_57 , V_75 ) ;
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
if ( V_40 [ V_41 - 1 ] != '\n' )
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
return - V_67 ;
for ( V_34 = 0 ; V_34 < V_94 ; V_34 ++ ) {
int V_96 ;
V_7 = F_65 ( & V_40 , & V_96 ) ;
V_53 = - V_56 ;
if ( V_7 )
goto V_97;
F_67 ( V_89 . V_90 , V_34 ) = V_96 ;
}
V_95 = F_68 ( V_36 , V_91 ) ;
if ( V_95 ) {
struct V_14 * V_71 ;
V_89 . V_5 . V_19 = 0 ;
V_89 . V_5 . V_79 = V_55 ;
V_71 = F_42 ( V_36 ,
& V_89 . V_5 , & V_95 -> V_5 ,
F_69 ( V_91 , V_98 ) ) ;
if ( ! V_71 )
V_53 = - V_67 ;
else {
V_53 = 0 ;
F_43 ( V_71 , V_36 ) ;
}
} else
V_53 = - V_67 ;
V_97:
if ( V_89 . V_90 )
F_56 ( V_89 . V_90 ) ;
return V_53 ;
}
static int F_70 ( struct V_68 * V_69 ,
struct V_35 * V_36 ,
struct V_14 * V_5 )
{
struct V_88 * V_89 ;
int V_34 ;
int V_99 ;
if ( V_5 == NULL ) {
F_35 ( V_69 , L_8 ) ;
return 0 ;
}
V_89 = F_2 ( V_5 , struct V_88 , V_5 ) ;
if ( F_11 ( V_18 , & V_5 -> V_19 ) &&
! F_11 ( V_20 , & V_5 -> V_19 ) )
V_99 = V_89 -> V_90 -> V_100 ;
else
V_99 = 0 ;
F_36 ( V_69 , L_9 , V_89 -> V_91 , V_99 ) ;
for ( V_34 = 0 ; V_34 < V_99 ; V_34 ++ )
F_36 ( V_69 , L_10 , F_67 ( V_89 -> V_90 , V_34 ) ) ;
F_36 ( V_69 , L_11 ) ;
return 0 ;
}
int F_71 ( struct V_57 * V_57 )
{
struct V_73 * V_74 = F_40 ( V_57 , V_75 ) ;
struct V_35 * V_36 ;
int V_53 ;
V_36 = F_72 ( & V_101 , V_57 ) ;
if ( F_73 ( V_36 ) )
return F_74 ( V_36 ) ;
V_53 = F_75 ( V_36 , V_57 ) ;
if ( V_53 ) {
F_76 ( V_36 , V_57 ) ;
return V_53 ;
}
V_74 -> V_102 = V_36 ;
return 0 ;
}
void F_77 ( struct V_57 * V_57 )
{
struct V_73 * V_74 = F_40 ( V_57 , V_75 ) ;
struct V_35 * V_36 = V_74 -> V_102 ;
V_74 -> V_102 = NULL ;
F_47 ( V_36 ) ;
F_78 ( V_36 , V_57 ) ;
F_76 ( V_36 , V_57 ) ;
}
static struct V_88 * F_68 ( struct V_35 * V_36 , T_3 V_91 )
{
struct V_88 V_89 ;
struct V_14 * V_71 ;
V_89 . V_91 = V_91 ;
V_71 = F_37 ( V_36 , & V_89 . V_5 , F_69 ( V_91 , V_98 ) ) ;
if ( V_71 )
return F_2 ( V_71 , struct V_88 , V_5 ) ;
else
return NULL ;
}
static struct V_103 * F_79 ( T_3 V_91 , struct V_104 * V_105 )
{
struct V_88 * V_89 ;
struct V_103 * V_90 ;
int V_106 ;
struct V_73 * V_74 = F_40 ( V_105 -> V_107 -> V_86 ,
V_75 ) ;
V_89 = F_68 ( V_74 -> V_102 , V_91 ) ;
if ( ! V_89 )
return F_80 ( - V_108 ) ;
V_106 = F_81 ( V_74 -> V_102 , & V_89 -> V_5 , & V_105 -> V_109 ) ;
switch ( V_106 ) {
case - V_66 :
return F_80 ( - V_66 ) ;
case - V_110 :
return F_80 ( - V_111 ) ;
case 0 :
V_90 = F_60 ( V_89 -> V_90 ) ;
F_43 ( & V_89 -> V_5 , V_74 -> V_102 ) ;
return V_90 ;
default:
return F_80 ( - V_108 ) ;
}
}
int
F_82 ( struct V_104 * V_105 )
{
struct V_47 * sin ;
struct V_49 * V_52 , V_112 ;
struct V_16 * V_77 ;
struct V_103 * V_90 ;
struct V_113 * V_114 = & V_105 -> V_115 ;
struct V_80 * V_81 = V_105 -> V_107 ;
struct V_57 * V_57 = V_81 -> V_86 ;
struct V_73 * V_74 = F_40 ( V_57 , V_75 ) ;
switch ( V_105 -> V_116 . V_117 ) {
case V_59 :
sin = F_83 ( V_105 ) ;
V_52 = & V_112 ;
F_28 ( sin -> V_62 . V_63 , & V_52 -> V_64 ) ;
break;
case V_61 :
V_52 = F_84 ( V_105 ) ;
break;
default:
F_85 () ;
}
V_105 -> V_118 = NULL ;
if ( V_105 -> V_119 == 0 )
return V_120 ;
V_77 = F_48 ( V_81 ) ;
if ( V_77 == NULL )
V_77 = F_31 ( V_74 -> V_76 , V_105 -> V_121 -> V_122 -> V_123 ,
& V_52 -> V_64 ) ;
if ( V_77 == NULL )
return V_124 ;
switch ( F_81 ( V_74 -> V_76 , & V_77 -> V_5 , & V_105 -> V_109 ) ) {
default:
F_85 () ;
case - V_110 :
return V_125 ;
case - V_108 :
return V_126 ;
case - V_66 :
return V_124 ;
case 0 :
V_105 -> V_118 = & V_77 -> V_21 -> V_5 ;
F_18 ( & V_105 -> V_118 -> V_12 ) ;
F_53 ( V_81 , V_77 ) ;
break;
}
V_90 = F_79 ( V_114 -> V_127 , V_105 ) ;
switch ( F_74 ( V_90 ) ) {
case - V_108 :
return V_126 ;
case - V_111 :
return V_125 ;
case - V_66 :
break;
default:
F_56 ( V_114 -> V_128 ) ;
V_114 -> V_128 = V_90 ;
}
return V_120 ;
}
static int
F_86 ( struct V_104 * V_105 , T_1 * V_129 )
{
struct V_130 * V_131 = & V_105 -> V_132 . V_133 [ 0 ] ;
struct V_130 * V_134 = & V_105 -> V_135 . V_133 [ 0 ] ;
struct V_113 * V_114 = & V_105 -> V_115 ;
V_114 -> V_128 = NULL ;
V_105 -> V_118 = NULL ;
if ( V_131 -> V_136 < 3 * 4 )
return V_137 ;
if ( F_87 ( V_131 ) != 0 ) {
F_88 ( L_12 ) ;
* V_129 = V_138 ;
return V_124 ;
}
if ( F_87 ( V_131 ) != F_89 ( V_139 ) || F_87 ( V_131 ) != 0 ) {
F_88 ( L_13 ) ;
* V_129 = V_140 ;
return V_124 ;
}
V_114 -> V_127 = ( T_3 ) - 1 ;
V_114 -> V_141 = ( V_142 ) - 1 ;
V_114 -> V_128 = F_66 ( 0 ) ;
if ( V_114 -> V_128 == NULL )
return V_125 ;
F_90 ( V_134 , V_139 ) ;
F_90 ( V_134 , 0 ) ;
V_105 -> V_143 = V_139 ;
return V_120 ;
}
static int
F_91 ( struct V_104 * V_105 )
{
if ( V_105 -> V_118 )
F_6 ( V_105 -> V_118 ) ;
V_105 -> V_118 = NULL ;
if ( V_105 -> V_115 . V_128 )
F_56 ( V_105 -> V_115 . V_128 ) ;
V_105 -> V_115 . V_128 = NULL ;
return 0 ;
}
static int
F_92 ( struct V_104 * V_105 , T_1 * V_129 )
{
struct V_130 * V_131 = & V_105 -> V_132 . V_133 [ 0 ] ;
struct V_130 * V_134 = & V_105 -> V_135 . V_133 [ 0 ] ;
struct V_113 * V_114 = & V_105 -> V_115 ;
V_25 V_144 , V_34 ;
int V_43 = V_131 -> V_136 ;
V_114 -> V_128 = NULL ;
V_105 -> V_118 = NULL ;
if ( ( V_43 -= 3 * 4 ) < 0 )
return V_137 ;
F_87 ( V_131 ) ;
F_87 ( V_131 ) ;
V_144 = F_93 ( F_94 ( V_131 ) ) ;
if ( V_144 > 64 || ( V_43 -= ( V_144 + 3 ) * 4 ) < 0 )
goto V_145;
V_131 -> V_146 = ( void * ) ( ( T_1 * ) V_131 -> V_146 + V_144 ) ;
V_131 -> V_136 -= V_144 * 4 ;
V_114 -> V_127 = F_94 ( V_131 ) ;
V_114 -> V_141 = F_94 ( V_131 ) ;
V_144 = F_94 ( V_131 ) ;
if ( V_144 > 16 || ( V_43 -= ( V_144 + 2 ) * 4 ) < 0 )
goto V_145;
V_114 -> V_128 = F_66 ( V_144 ) ;
if ( V_114 -> V_128 == NULL )
return V_125 ;
for ( V_34 = 0 ; V_34 < V_144 ; V_34 ++ )
F_67 ( V_114 -> V_128 , V_34 ) = F_94 ( V_131 ) ;
if ( F_87 ( V_131 ) != F_89 ( V_139 ) || F_87 ( V_131 ) != 0 ) {
* V_129 = V_140 ;
return V_124 ;
}
F_90 ( V_134 , V_139 ) ;
F_90 ( V_134 , 0 ) ;
V_105 -> V_143 = V_147 ;
return V_120 ;
V_145:
* V_129 = V_138 ;
return V_124 ;
}
static int
F_95 ( struct V_104 * V_105 )
{
if ( V_105 -> V_118 )
F_6 ( V_105 -> V_118 ) ;
V_105 -> V_118 = NULL ;
if ( V_105 -> V_115 . V_128 )
F_56 ( V_105 -> V_115 . V_128 ) ;
V_105 -> V_115 . V_128 = NULL ;
return 0 ;
}
int F_96 ( struct V_57 * V_57 )
{
struct V_73 * V_74 = F_40 ( V_57 , V_75 ) ;
struct V_35 * V_36 ;
int V_53 ;
V_36 = F_72 ( & V_148 , V_57 ) ;
if ( F_73 ( V_36 ) )
return F_74 ( V_36 ) ;
V_53 = F_75 ( V_36 , V_57 ) ;
if ( V_53 ) {
F_76 ( V_36 , V_57 ) ;
return V_53 ;
}
V_74 -> V_76 = V_36 ;
return 0 ;
}
void F_97 ( struct V_57 * V_57 )
{
struct V_73 * V_74 = F_40 ( V_57 , V_75 ) ;
struct V_35 * V_36 = V_74 -> V_76 ;
V_74 -> V_76 = NULL ;
F_47 ( V_36 ) ;
F_78 ( V_36 , V_57 ) ;
F_76 ( V_36 , V_57 ) ;
}
