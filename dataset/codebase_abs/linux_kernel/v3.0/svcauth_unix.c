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
#ifdef F_10
V_8 -> V_13 = 0 ;
#endif
V_7 = F_5 ( V_6 , & V_8 -> V_5 ) ;
}
}
static void F_11 ( struct V_14 * V_14 )
{
struct V_15 * V_16 = F_2 ( V_14 , struct V_15 , V_12 ) ;
struct V_17 * V_18 = F_2 ( V_16 , struct V_17 , V_5 ) ;
if ( F_12 ( V_19 , & V_16 -> V_20 ) &&
! F_12 ( V_21 , & V_16 -> V_20 ) )
F_6 ( & V_18 -> V_22 -> V_5 ) ;
F_3 ( V_18 ) ;
}
static inline int F_13 ( T_1 V_23 )
{
int V_24 = ( V_25 V_26 ) V_23 ^ ( ( V_25 V_26 ) V_23 >> 16 ) ;
return ( V_24 ^ ( V_24 >> 8 ) ) & 0xff ;
}
static inline int F_14 ( struct V_27 V_23 )
{
return ( F_13 ( V_23 . V_28 [ 0 ] ) ^
F_13 ( V_23 . V_28 [ 1 ] ) ^
F_13 ( V_23 . V_28 [ 2 ] ) ^
F_13 ( V_23 . V_28 [ 3 ] ) ) ;
}
static int F_15 ( struct V_15 * V_29 , struct V_15 * V_30 )
{
struct V_17 * V_31 = F_2 ( V_29 , struct V_17 , V_5 ) ;
struct V_17 * V_8 = F_2 ( V_30 , struct V_17 , V_5 ) ;
return strcmp ( V_31 -> V_32 , V_8 -> V_32 ) == 0 &&
F_16 ( & V_31 -> V_33 , & V_8 -> V_33 ) ;
}
static void F_17 ( struct V_15 * V_30 , struct V_15 * V_34 )
{
struct V_17 * V_8 = F_2 ( V_30 , struct V_17 , V_5 ) ;
struct V_17 * V_16 = F_2 ( V_34 , struct V_17 , V_5 ) ;
strcpy ( V_8 -> V_32 , V_16 -> V_32 ) ;
F_18 ( & V_8 -> V_33 , & V_16 -> V_33 ) ;
}
static void F_19 ( struct V_15 * V_30 , struct V_15 * V_34 )
{
struct V_17 * V_8 = F_2 ( V_30 , struct V_17 , V_5 ) ;
struct V_17 * V_16 = F_2 ( V_34 , struct V_17 , V_5 ) ;
F_20 ( & V_16 -> V_22 -> V_5 . V_12 ) ;
V_8 -> V_22 = V_16 -> V_22 ;
#ifdef F_10
V_8 -> V_35 = V_16 -> V_35 ;
#endif
}
static struct V_15 * F_21 ( void )
{
struct V_17 * V_36 = F_7 ( sizeof( * V_36 ) , V_11 ) ;
if ( V_36 )
return & V_36 -> V_5 ;
else
return NULL ;
}
static void F_22 ( struct V_37 * V_38 ,
struct V_15 * V_5 ,
char * * V_39 , int * V_40 )
{
char V_41 [ 40 ] ;
struct V_17 * V_18 = F_2 ( V_5 , struct V_17 , V_5 ) ;
if ( F_23 ( & ( V_18 -> V_33 ) ) ) {
snprintf ( V_41 , 20 , L_1 , & V_18 -> V_33 . V_28 [ 3 ] ) ;
} else {
snprintf ( V_41 , 40 , L_2 , & V_18 -> V_33 ) ;
}
F_24 ( V_39 , V_40 , V_18 -> V_32 ) ;
F_24 ( V_39 , V_40 , V_41 ) ;
( * V_39 ) [ - 1 ] = '\n' ;
}
static int F_25 ( struct V_37 * V_38 , struct V_15 * V_5 )
{
return F_26 ( V_38 , V_5 , F_22 ) ;
}
static int F_27 ( struct V_37 * V_38 ,
char * V_42 , int V_43 )
{
char * V_44 = V_42 ;
int V_45 ;
char V_46 [ 8 ] ;
union {
struct V_47 V_48 ;
struct V_49 V_50 ;
struct V_51 V_52 ;
} V_53 ;
struct V_51 V_54 ;
int V_55 ;
struct V_17 * V_56 ;
struct V_1 * V_2 ;
T_2 V_57 ;
if ( V_42 [ V_43 - 1 ] != '\n' )
return - V_58 ;
V_42 [ V_43 - 1 ] = 0 ;
V_45 = F_28 ( & V_42 , V_46 , sizeof( V_46 ) ) ;
if ( V_45 <= 0 ) return - V_58 ;
V_45 = F_28 ( & V_42 , V_44 , V_43 ) ;
if ( V_45 <= 0 ) return - V_58 ;
if ( F_29 ( V_44 , V_45 , & V_53 . V_48 , sizeof( V_53 ) ) == 0 )
return - V_58 ;
switch ( V_53 . V_48 . V_59 ) {
case V_60 :
V_54 . V_61 = V_62 ;
F_30 ( V_53 . V_50 . V_63 . V_64 ,
& V_54 . V_65 ) ;
break;
#if F_31 ( V_66 ) || F_31 ( V_67 )
case V_62 :
memcpy ( & V_54 , & V_53 . V_52 , sizeof( V_54 ) ) ;
break;
#endif
default:
return - V_58 ;
}
V_57 = F_32 ( & V_42 ) ;
if ( V_57 == 0 )
return - V_58 ;
V_45 = F_28 ( & V_42 , V_44 , V_43 ) ;
if ( V_45 < 0 ) return - V_58 ;
if ( V_45 ) {
V_2 = F_4 ( V_44 ) ;
if ( V_2 == NULL )
return - V_68 ;
} else
V_2 = NULL ;
V_56 = F_33 ( V_38 , V_46 , & V_54 . V_65 ) ;
if ( V_56 ) {
V_55 = F_34 ( V_38 , V_56 ,
F_2 ( V_2 , struct V_3 , V_5 ) ,
V_57 ) ;
} else
V_55 = - V_69 ;
if ( V_2 )
F_6 ( V_2 ) ;
F_35 () ;
return V_55 ;
}
static int F_36 ( struct V_70 * V_71 ,
struct V_37 * V_38 ,
struct V_15 * V_5 )
{
struct V_17 * V_18 ;
struct V_27 V_72 ;
char * V_2 = L_3 ;
if ( V_5 == NULL ) {
F_37 ( V_71 , L_4 ) ;
return 0 ;
}
V_18 = F_2 ( V_5 , struct V_17 , V_5 ) ;
F_18 ( & V_72 , & V_18 -> V_33 ) ;
if ( F_12 ( V_19 , & V_5 -> V_20 ) &&
! F_12 ( V_21 , & V_5 -> V_20 ) )
V_2 = V_18 -> V_22 -> V_5 . V_6 ;
if ( F_23 ( & V_72 ) ) {
F_38 ( V_71 , L_5 ,
V_18 -> V_32 , & V_72 . V_28 [ 3 ] , V_2 ) ;
} else {
F_38 ( V_71 , L_6 , V_18 -> V_32 , & V_72 , V_2 ) ;
}
return 0 ;
}
static struct V_17 * F_33 ( struct V_37 * V_38 , char * V_46 ,
struct V_27 * V_72 )
{
struct V_17 V_23 ;
struct V_15 * V_73 ;
strcpy ( V_23 . V_32 , V_46 ) ;
F_18 ( & V_23 . V_33 , V_72 ) ;
V_73 = F_39 ( V_38 , & V_23 . V_5 ,
F_40 ( V_46 , V_74 ) ^
F_14 ( * V_72 ) ) ;
if ( V_73 )
return F_2 ( V_73 , struct V_17 , V_5 ) ;
else
return NULL ;
}
static inline struct V_17 * F_41 ( struct V_75 * V_75 , char * V_46 ,
struct V_27 * V_72 )
{
struct V_76 * V_77 ;
V_77 = F_42 ( V_75 , V_78 ) ;
return F_33 ( V_77 -> V_79 , V_46 , V_72 ) ;
}
static int F_34 ( struct V_37 * V_38 , struct V_17 * V_80 ,
struct V_3 * V_81 , T_2 V_57 )
{
struct V_17 V_23 ;
struct V_15 * V_73 ;
V_23 . V_22 = V_81 ;
V_23 . V_5 . V_20 = 0 ;
if ( ! V_81 )
F_43 ( V_21 , & V_23 . V_5 . V_20 ) ;
#ifdef F_10
else {
V_23 . V_35 = V_81 -> V_13 ;
if ( V_57 == V_82 )
V_23 . V_35 ++ ;
}
#endif
V_23 . V_5 . V_83 = V_57 ;
V_73 = F_44 ( V_38 , & V_23 . V_5 , & V_80 -> V_5 ,
F_40 ( V_80 -> V_32 , V_74 ) ^
F_14 ( V_80 -> V_33 ) ) ;
if ( ! V_73 )
return - V_69 ;
F_45 ( V_73 , V_38 ) ;
return 0 ;
}
static inline int F_46 ( struct V_75 * V_75 , struct V_17 * V_80 ,
struct V_3 * V_81 , T_2 V_57 )
{
struct V_76 * V_77 ;
V_77 = F_42 ( V_75 , V_78 ) ;
return F_34 ( V_77 -> V_79 , V_80 , V_81 , V_57 ) ;
}
int F_47 ( struct V_75 * V_75 , struct V_27 * V_72 , struct V_1 * V_2 )
{
struct V_3 * V_81 ;
struct V_17 * V_56 ;
if ( V_2 -> V_9 != & V_10 )
return - V_58 ;
V_81 = F_2 ( V_2 , struct V_3 , V_5 ) ;
V_56 = F_41 ( V_75 , L_7 , V_72 ) ;
if ( V_56 )
return F_46 ( V_75 , V_56 , V_81 , V_82 ) ;
else
return - V_69 ;
}
int F_48 ( struct V_1 * V_2 )
{
struct V_3 * V_81 ;
if ( V_2 -> V_9 != & V_10 )
return - V_58 ;
V_81 = F_2 ( V_2 , struct V_3 , V_5 ) ;
V_81 -> V_13 ++ ;
return 0 ;
}
struct V_1 * F_49 ( struct V_75 * V_75 , struct V_27 * V_72 )
{
struct V_17 * V_80 ;
struct V_1 * V_7 ;
struct V_76 * V_77 ;
V_77 = F_42 ( V_75 , V_78 ) ;
V_80 = F_41 ( V_75 , L_7 , V_72 ) ;
if ( ! V_80 )
return NULL ;
if ( F_50 ( V_77 -> V_79 , & V_80 -> V_5 , NULL ) )
return NULL ;
if ( ( V_80 -> V_22 -> V_13 - V_80 -> V_35 ) > 0 ) {
F_51 ( & V_80 -> V_5 , V_77 -> V_79 ) ;
V_7 = NULL ;
} else {
V_7 = & V_80 -> V_22 -> V_5 ;
F_20 ( & V_7 -> V_12 ) ;
}
F_45 ( & V_80 -> V_5 , V_77 -> V_79 ) ;
return V_7 ;
}
void F_52 ( void )
{
struct V_75 * V_75 ;
F_53 (net) {
struct V_76 * V_77 ;
V_77 = F_42 ( V_75 , V_78 ) ;
F_54 ( V_77 -> V_79 ) ;
}
}
static inline struct V_17 *
F_55 ( struct V_84 * V_85 )
{
struct V_17 * V_80 = NULL ;
struct V_76 * V_77 ;
if ( F_12 ( V_86 , & V_85 -> V_87 ) ) {
F_56 ( & V_85 -> V_88 ) ;
V_80 = V_85 -> V_89 ;
if ( V_80 != NULL ) {
if ( ! F_57 ( & V_80 -> V_5 ) ) {
V_77 = F_42 ( V_85 -> V_90 , V_78 ) ;
V_85 -> V_89 = NULL ;
F_58 ( & V_85 -> V_88 ) ;
F_45 ( & V_80 -> V_5 , V_77 -> V_79 ) ;
return NULL ;
}
F_59 ( & V_80 -> V_5 ) ;
}
F_58 ( & V_85 -> V_88 ) ;
}
return V_80 ;
}
static inline void
F_60 ( struct V_84 * V_85 , struct V_17 * V_80 )
{
if ( F_12 ( V_86 , & V_85 -> V_87 ) ) {
F_56 ( & V_85 -> V_88 ) ;
if ( V_85 -> V_89 == NULL ) {
V_85 -> V_89 = V_80 ;
V_80 = NULL ;
}
F_58 ( & V_85 -> V_88 ) ;
}
if ( V_80 ) {
struct V_76 * V_77 ;
V_77 = F_42 ( V_85 -> V_90 , V_78 ) ;
F_45 ( & V_80 -> V_5 , V_77 -> V_79 ) ;
}
}
void
F_61 ( struct V_84 * V_91 )
{
struct V_17 * V_80 ;
V_80 = V_91 -> V_89 ;
if ( V_80 != NULL ) {
struct V_76 * V_77 ;
V_77 = F_42 ( V_91 -> V_90 , V_78 ) ;
F_45 ( & V_80 -> V_5 , V_77 -> V_79 ) ;
}
}
static void F_62 ( struct V_14 * V_14 )
{
struct V_15 * V_16 = F_2 ( V_14 , struct V_15 , V_12 ) ;
struct V_92 * V_93 = F_2 ( V_16 , struct V_92 , V_5 ) ;
if ( F_12 ( V_19 , & V_16 -> V_20 ) &&
! F_12 ( V_21 , & V_16 -> V_20 ) )
F_63 ( V_93 -> V_94 ) ;
F_3 ( V_93 ) ;
}
static int F_64 ( struct V_15 * V_29 , struct V_15 * V_30 )
{
struct V_92 * V_31 = F_2 ( V_29 , struct V_92 , V_5 ) ;
struct V_92 * V_8 = F_2 ( V_30 , struct V_92 , V_5 ) ;
return V_31 -> V_95 == V_8 -> V_95 ;
}
static void F_65 ( struct V_15 * V_30 , struct V_15 * V_34 )
{
struct V_92 * V_8 = F_2 ( V_30 , struct V_92 , V_5 ) ;
struct V_92 * V_16 = F_2 ( V_34 , struct V_92 , V_5 ) ;
V_8 -> V_95 = V_16 -> V_95 ;
}
static void F_66 ( struct V_15 * V_30 , struct V_15 * V_34 )
{
struct V_92 * V_8 = F_2 ( V_30 , struct V_92 , V_5 ) ;
struct V_92 * V_16 = F_2 ( V_34 , struct V_92 , V_5 ) ;
F_67 ( V_16 -> V_94 ) ;
V_8 -> V_94 = V_16 -> V_94 ;
}
static struct V_15 * F_68 ( void )
{
struct V_92 * V_96 = F_7 ( sizeof( * V_96 ) , V_11 ) ;
if ( V_96 )
return & V_96 -> V_5 ;
else
return NULL ;
}
static void F_69 ( struct V_37 * V_38 ,
struct V_15 * V_5 ,
char * * V_39 , int * V_40 )
{
char V_97 [ 20 ] ;
struct V_92 * V_93 = F_2 ( V_5 , struct V_92 , V_5 ) ;
snprintf ( V_97 , 20 , L_8 , V_93 -> V_95 ) ;
F_24 ( V_39 , V_40 , V_97 ) ;
( * V_39 ) [ - 1 ] = '\n' ;
}
static int F_70 ( struct V_37 * V_38 , struct V_15 * V_5 )
{
return F_26 ( V_38 , V_5 , F_69 ) ;
}
static int F_71 ( struct V_37 * V_38 ,
char * V_42 , int V_43 )
{
int V_95 ;
int V_98 ;
int V_7 ;
int V_36 ;
int V_55 ;
T_2 V_57 ;
struct V_92 V_93 , * V_99 ;
if ( V_43 <= 0 || V_42 [ V_43 - 1 ] != '\n' )
return - V_58 ;
V_42 [ V_43 - 1 ] = 0 ;
V_7 = F_72 ( & V_42 , & V_95 ) ;
if ( V_7 )
return - V_58 ;
V_93 . V_95 = V_95 ;
V_57 = F_32 ( & V_42 ) ;
if ( V_57 == 0 )
return - V_58 ;
V_7 = F_72 ( & V_42 , & V_98 ) ;
if ( V_7 || V_98 < 0 || V_98 > 8192 )
return - V_58 ;
V_93 . V_94 = F_73 ( V_98 ) ;
if ( ! V_93 . V_94 )
return - V_69 ;
for ( V_36 = 0 ; V_36 < V_98 ; V_36 ++ ) {
int V_100 ;
V_7 = F_72 ( & V_42 , & V_100 ) ;
V_55 = - V_58 ;
if ( V_7 )
goto V_101;
F_74 ( V_93 . V_94 , V_36 ) = V_100 ;
}
V_99 = F_75 ( V_95 ) ;
if ( V_99 ) {
struct V_15 * V_73 ;
V_93 . V_5 . V_20 = 0 ;
V_93 . V_5 . V_83 = V_57 ;
V_73 = F_44 ( & V_102 ,
& V_93 . V_5 , & V_99 -> V_5 ,
F_76 ( V_95 , V_103 ) ) ;
if ( ! V_73 )
V_55 = - V_69 ;
else {
V_55 = 0 ;
F_45 ( V_73 , & V_102 ) ;
}
} else
V_55 = - V_69 ;
V_101:
if ( V_93 . V_94 )
F_63 ( V_93 . V_94 ) ;
return V_55 ;
}
static int F_77 ( struct V_70 * V_71 ,
struct V_37 * V_38 ,
struct V_15 * V_5 )
{
struct V_92 * V_93 ;
int V_36 ;
int V_104 ;
if ( V_5 == NULL ) {
F_37 ( V_71 , L_9 ) ;
return 0 ;
}
V_93 = F_2 ( V_5 , struct V_92 , V_5 ) ;
if ( F_12 ( V_19 , & V_5 -> V_20 ) &&
! F_12 ( V_21 , & V_5 -> V_20 ) )
V_104 = V_93 -> V_94 -> V_105 ;
else
V_104 = 0 ;
F_38 ( V_71 , L_10 , V_93 -> V_95 , V_104 ) ;
for ( V_36 = 0 ; V_36 < V_104 ; V_36 ++ )
F_38 ( V_71 , L_11 , F_74 ( V_93 -> V_94 , V_36 ) ) ;
F_38 ( V_71 , L_12 ) ;
return 0 ;
}
static struct V_92 * F_75 ( T_3 V_95 )
{
struct V_92 V_93 ;
struct V_15 * V_73 ;
V_93 . V_95 = V_95 ;
V_73 = F_39 ( & V_102 , & V_93 . V_5 ,
F_76 ( V_95 , V_103 ) ) ;
if ( V_73 )
return F_2 ( V_73 , struct V_92 , V_5 ) ;
else
return NULL ;
}
static struct V_106 * F_78 ( T_3 V_95 , struct V_107 * V_108 )
{
struct V_92 * V_93 ;
struct V_106 * V_94 ;
int V_109 ;
V_93 = F_75 ( V_95 ) ;
if ( ! V_93 )
return F_79 ( - V_110 ) ;
V_109 = F_50 ( & V_102 , & V_93 -> V_5 , & V_108 -> V_111 ) ;
switch ( V_109 ) {
case - V_68 :
return F_79 ( - V_68 ) ;
case - V_112 :
return F_79 ( - V_113 ) ;
case 0 :
V_94 = F_67 ( V_93 -> V_94 ) ;
F_45 ( & V_93 -> V_5 , & V_102 ) ;
return V_94 ;
default:
return F_79 ( - V_110 ) ;
}
}
int
F_80 ( struct V_107 * V_108 )
{
struct V_49 * sin ;
struct V_51 * V_54 , V_114 ;
struct V_17 * V_80 ;
struct V_106 * V_94 ;
struct V_115 * V_116 = & V_108 -> V_117 ;
struct V_84 * V_85 = V_108 -> V_118 ;
struct V_75 * V_75 = V_85 -> V_90 ;
struct V_76 * V_77 = F_42 ( V_75 , V_78 ) ;
switch ( V_108 -> V_119 . V_120 ) {
case V_60 :
sin = F_81 ( V_108 ) ;
V_54 = & V_114 ;
F_30 ( sin -> V_63 . V_64 , & V_54 -> V_65 ) ;
break;
case V_62 :
V_54 = F_82 ( V_108 ) ;
break;
default:
F_83 () ;
}
V_108 -> V_121 = NULL ;
if ( V_108 -> V_122 == 0 )
return V_123 ;
V_80 = F_55 ( V_85 ) ;
if ( V_80 == NULL )
V_80 = F_33 ( V_77 -> V_79 , V_108 -> V_124 -> V_125 -> V_126 ,
& V_54 -> V_65 ) ;
if ( V_80 == NULL )
return V_127 ;
switch ( F_50 ( V_77 -> V_79 , & V_80 -> V_5 , & V_108 -> V_111 ) ) {
default:
F_83 () ;
case - V_112 :
return V_128 ;
case - V_110 :
return V_129 ;
case - V_68 :
return V_127 ;
case 0 :
V_108 -> V_121 = & V_80 -> V_22 -> V_5 ;
F_20 ( & V_108 -> V_121 -> V_12 ) ;
F_60 ( V_85 , V_80 ) ;
break;
}
V_94 = F_78 ( V_116 -> V_130 , V_108 ) ;
switch ( F_84 ( V_94 ) ) {
case - V_110 :
return V_129 ;
case - V_113 :
return V_128 ;
case - V_68 :
break;
default:
F_63 ( V_116 -> V_131 ) ;
V_116 -> V_131 = V_94 ;
}
return V_123 ;
}
static int
F_85 ( struct V_107 * V_108 , T_1 * V_132 )
{
struct V_133 * V_134 = & V_108 -> V_135 . V_136 [ 0 ] ;
struct V_133 * V_137 = & V_108 -> V_138 . V_136 [ 0 ] ;
struct V_115 * V_116 = & V_108 -> V_117 ;
V_116 -> V_131 = NULL ;
V_108 -> V_121 = NULL ;
if ( V_134 -> V_139 < 3 * 4 )
return V_140 ;
if ( F_86 ( V_134 ) != 0 ) {
F_87 ( L_13 ) ;
* V_132 = V_141 ;
return V_127 ;
}
if ( F_86 ( V_134 ) != F_88 ( V_142 ) || F_86 ( V_134 ) != 0 ) {
F_87 ( L_14 ) ;
* V_132 = V_143 ;
return V_127 ;
}
V_116 -> V_130 = ( T_3 ) - 1 ;
V_116 -> V_144 = ( V_145 ) - 1 ;
V_116 -> V_131 = F_73 ( 0 ) ;
if ( V_116 -> V_131 == NULL )
return V_128 ;
F_89 ( V_137 , V_142 ) ;
F_89 ( V_137 , 0 ) ;
V_108 -> V_146 = V_142 ;
return V_123 ;
}
static int
F_90 ( struct V_107 * V_108 )
{
if ( V_108 -> V_121 )
F_6 ( V_108 -> V_121 ) ;
V_108 -> V_121 = NULL ;
if ( V_108 -> V_117 . V_131 )
F_63 ( V_108 -> V_117 . V_131 ) ;
V_108 -> V_117 . V_131 = NULL ;
return 0 ;
}
static int
F_91 ( struct V_107 * V_108 , T_1 * V_132 )
{
struct V_133 * V_134 = & V_108 -> V_135 . V_136 [ 0 ] ;
struct V_133 * V_137 = & V_108 -> V_138 . V_136 [ 0 ] ;
struct V_115 * V_116 = & V_108 -> V_117 ;
V_26 V_147 , V_36 ;
int V_45 = V_134 -> V_139 ;
V_116 -> V_131 = NULL ;
V_108 -> V_121 = NULL ;
if ( ( V_45 -= 3 * 4 ) < 0 )
return V_140 ;
F_86 ( V_134 ) ;
F_86 ( V_134 ) ;
V_147 = F_92 ( F_93 ( V_134 ) ) ;
if ( V_147 > 64 || ( V_45 -= ( V_147 + 3 ) * 4 ) < 0 )
goto V_148;
V_134 -> V_149 = ( void * ) ( ( T_1 * ) V_134 -> V_149 + V_147 ) ;
V_134 -> V_139 -= V_147 * 4 ;
V_116 -> V_130 = F_93 ( V_134 ) ;
V_116 -> V_144 = F_93 ( V_134 ) ;
V_147 = F_93 ( V_134 ) ;
if ( V_147 > 16 || ( V_45 -= ( V_147 + 2 ) * 4 ) < 0 )
goto V_148;
V_116 -> V_131 = F_73 ( V_147 ) ;
if ( V_116 -> V_131 == NULL )
return V_128 ;
for ( V_36 = 0 ; V_36 < V_147 ; V_36 ++ )
F_74 ( V_116 -> V_131 , V_36 ) = F_93 ( V_134 ) ;
if ( F_86 ( V_134 ) != F_88 ( V_142 ) || F_86 ( V_134 ) != 0 ) {
* V_132 = V_143 ;
return V_127 ;
}
F_89 ( V_137 , V_142 ) ;
F_89 ( V_137 , 0 ) ;
V_108 -> V_146 = V_150 ;
return V_123 ;
V_148:
* V_132 = V_141 ;
return V_127 ;
}
static int
F_94 ( struct V_107 * V_108 )
{
if ( V_108 -> V_121 )
F_6 ( V_108 -> V_121 ) ;
V_108 -> V_121 = NULL ;
if ( V_108 -> V_117 . V_131 )
F_63 ( V_108 -> V_117 . V_131 ) ;
V_108 -> V_117 . V_131 = NULL ;
return 0 ;
}
int F_95 ( struct V_75 * V_75 )
{
int V_55 = - V_69 ;
struct V_37 * V_38 ;
struct V_15 * * V_151 ;
struct V_76 * V_77 = F_42 ( V_75 , V_78 ) ;
V_38 = F_96 ( sizeof( struct V_37 ) , V_11 ) ;
if ( V_38 == NULL )
goto V_152;
V_151 = F_96 ( V_153 * sizeof( struct V_15 * ) , V_11 ) ;
if ( V_151 == NULL )
goto V_154;
V_38 -> V_155 = V_156 ,
V_38 -> V_157 = V_153 ,
V_38 -> V_158 = V_151 ,
V_38 -> V_6 = L_15 ,
V_38 -> F_45 = F_11 ,
V_38 -> V_159 = F_25 ,
V_38 -> V_160 = F_27 ,
V_38 -> V_161 = F_36 ,
V_38 -> V_162 = F_15 ,
V_38 -> V_163 = F_17 ,
V_38 -> F_19 = F_19 ,
V_38 -> V_164 = F_21 ,
V_55 = F_97 ( V_38 , V_75 ) ;
if ( V_55 )
goto V_165;
V_77 -> V_79 = V_38 ;
return 0 ;
V_165:
F_3 ( V_151 ) ;
V_154:
F_3 ( V_38 ) ;
V_152:
return V_55 ;
}
void F_98 ( struct V_75 * V_75 )
{
struct V_76 * V_77 ;
V_77 = F_42 ( V_75 , V_78 ) ;
F_54 ( V_77 -> V_79 ) ;
F_99 ( V_77 -> V_79 , V_75 ) ;
F_3 ( V_77 -> V_79 -> V_158 ) ;
F_3 ( V_77 -> V_79 ) ;
}
