static unsigned int F_1 ( unsigned int V_1 , unsigned int V_2 )
{
int V_3 = 0 ;
while ( V_1 > 1 ) {
V_1 = F_2 ( V_1 , V_2 ) ;
V_3 ++ ;
}
return V_3 ;
}
static inline unsigned int F_3 ( unsigned int V_1 , unsigned int V_4 )
{
return ( V_1 * V_5 ) + V_4 ;
}
static inline T_1 * F_4 ( struct V_6 * V_7 ,
unsigned int V_8 , unsigned int V_1 )
{
return V_7 -> V_9 [ V_8 ] + ( V_1 * V_10 ) ;
}
static T_1 F_5 ( struct V_6 * V_7 , unsigned int V_8 , unsigned int V_1 )
{
for (; V_8 < V_7 -> V_11 - 1 ; V_8 ++ )
V_1 = F_3 ( V_1 , V_5 - 1 ) ;
if ( V_1 >= V_7 -> V_12 [ V_8 ] )
return ( T_1 ) - 1 ;
return F_4 ( V_7 , V_8 , V_1 ) [ V_10 - 1 ] ;
}
static int F_6 ( unsigned int V_8 , struct V_6 * V_7 )
{
unsigned int V_1 , V_4 ;
T_1 * V_13 ;
for ( V_1 = 0U ; V_1 < V_7 -> V_12 [ V_8 ] ; V_1 ++ ) {
V_13 = F_4 ( V_7 , V_8 , V_1 ) ;
for ( V_4 = 0U ; V_4 < V_10 ; V_4 ++ )
V_13 [ V_4 ] = F_5 ( V_7 , V_8 + 1 , F_3 ( V_1 , V_4 ) ) ;
}
return 0 ;
}
void * F_7 ( unsigned long V_14 , unsigned long V_15 )
{
unsigned long V_16 ;
void * V_17 ;
if ( V_14 > ( V_18 / V_15 ) )
return NULL ;
V_16 = V_14 * V_15 ;
V_17 = F_8 ( V_16 ) ;
return V_17 ;
}
static int F_9 ( struct V_6 * V_7 , unsigned int V_19 )
{
T_1 * V_20 ;
struct V_21 * V_22 ;
V_20 = ( T_1 * ) F_7 ( V_19 + 1 , sizeof( struct V_21 ) +
sizeof( T_1 ) ) ;
if ( ! V_20 )
return - V_23 ;
V_22 = (struct V_21 * ) ( V_20 + V_19 ) ;
memset ( V_20 , - 1 , sizeof( * V_20 ) * V_19 ) ;
F_10 ( V_7 -> V_24 ) ;
V_7 -> V_25 = V_19 ;
V_7 -> V_24 = V_20 ;
V_7 -> V_26 = V_22 ;
return 0 ;
}
int F_11 ( struct V_6 * * V_3 , T_2 V_27 ,
unsigned V_28 , struct V_29 * V_30 )
{
struct V_6 * V_7 = F_12 ( sizeof( * V_7 ) , V_31 ) ;
if ( ! V_7 )
return - V_23 ;
F_13 ( & V_7 -> V_32 ) ;
F_13 ( & V_7 -> V_33 ) ;
if ( ! V_28 )
V_28 = V_10 ;
V_28 = F_14 ( V_28 , V_10 ) ;
if ( ! V_28 ) {
F_15 ( V_7 ) ;
return - V_23 ;
}
if ( F_9 ( V_7 , V_28 ) ) {
F_15 ( V_7 ) ;
return - V_23 ;
}
V_7 -> type = V_34 ;
V_7 -> V_27 = V_27 ;
V_7 -> V_30 = V_30 ;
* V_3 = V_7 ;
return 0 ;
}
static void F_16 ( struct V_35 * V_32 , struct V_29 * V_30 )
{
struct V_35 * V_36 , * V_37 ;
F_17 (tmp, next, devices) {
struct V_38 * V_39 =
F_18 ( V_36 , struct V_38 , V_40 ) ;
F_19 ( L_1 ,
F_20 ( V_30 ) , V_39 -> V_41 -> V_42 ) ;
F_21 ( V_30 , V_39 -> V_41 ) ;
F_15 ( V_39 ) ;
}
}
void F_22 ( struct V_6 * V_7 )
{
unsigned int V_43 ;
if ( ! V_7 )
return;
if ( V_7 -> V_11 >= 2 )
F_10 ( V_7 -> V_9 [ V_7 -> V_11 - 2 ] ) ;
for ( V_43 = 0 ; V_43 < V_7 -> V_28 ; V_43 ++ ) {
struct V_21 * V_44 = V_7 -> V_26 + V_43 ;
if ( V_44 -> type -> V_45 )
V_44 -> type -> V_45 ( V_44 ) ;
F_23 ( V_44 -> type ) ;
}
F_10 ( V_7 -> V_24 ) ;
F_16 ( & V_7 -> V_32 , V_7 -> V_30 ) ;
F_24 ( V_7 -> V_46 ) ;
F_15 ( V_7 ) ;
}
static struct V_38 * F_25 ( struct V_35 * V_8 , T_3 V_47 )
{
struct V_38 * V_39 ;
F_26 (dd, l, list)
if ( V_39 -> V_41 -> V_48 -> V_49 == V_47 )
return V_39 ;
return NULL ;
}
static int F_27 ( struct V_21 * V_50 , struct V_41 * V_47 ,
T_1 V_51 , T_1 V_52 , void * V_53 )
{
struct V_54 * V_55 ;
struct V_56 * V_57 = V_53 ;
struct V_58 * V_48 = V_47 -> V_48 ;
T_1 V_59 =
F_28 ( V_48 -> V_60 ) >> V_61 ;
unsigned short V_62 =
V_57 -> V_63 >> V_61 ;
char V_64 [ V_65 ] ;
V_55 = F_29 ( V_48 ) ;
if ( ! V_55 || ! V_55 -> V_66 ) {
F_19 ( L_2
L_3 ,
F_20 ( V_50 -> V_67 -> V_30 ) , F_30 ( V_48 , V_64 ) ,
( unsigned long long ) V_51 ,
( unsigned long long ) V_52 ,
( unsigned long long ) V_59 ) ;
return 1 ;
}
if ( ! V_59 )
return 0 ;
if ( ( V_51 >= V_59 ) || ( V_51 + V_52 > V_59 ) ) {
F_19 ( L_4
L_3 ,
F_20 ( V_50 -> V_67 -> V_30 ) , F_30 ( V_48 , V_64 ) ,
( unsigned long long ) V_51 ,
( unsigned long long ) V_52 ,
( unsigned long long ) V_59 ) ;
return 1 ;
}
if ( F_31 ( V_48 ) != V_68 ) {
unsigned int V_69 = F_32 ( V_48 ) ;
if ( V_51 & ( V_69 - 1 ) ) {
F_19 ( L_5 ,
F_20 ( V_50 -> V_67 -> V_30 ) ,
( unsigned long long ) V_51 ,
V_69 , F_30 ( V_48 , V_64 ) ) ;
return 1 ;
}
if ( V_52 & ( V_69 - 1 ) ) {
F_19 ( L_6 ,
F_20 ( V_50 -> V_67 -> V_30 ) ,
( unsigned long long ) V_52 ,
V_69 , F_30 ( V_48 , V_64 ) ) ;
return 1 ;
}
}
if ( V_62 <= 1 )
return 0 ;
if ( V_51 & ( V_62 - 1 ) ) {
F_19 ( L_7
L_8 ,
F_20 ( V_50 -> V_67 -> V_30 ) ,
( unsigned long long ) V_51 ,
V_57 -> V_63 , F_30 ( V_48 , V_64 ) ) ;
return 1 ;
}
if ( V_52 & ( V_62 - 1 ) ) {
F_19 ( L_9
L_8 ,
F_20 ( V_50 -> V_67 -> V_30 ) ,
( unsigned long long ) V_52 ,
V_57 -> V_63 , F_30 ( V_48 , V_64 ) ) ;
return 1 ;
}
return 0 ;
}
static int F_33 ( struct V_38 * V_39 , T_2 V_70 ,
struct V_29 * V_30 )
{
int V_71 ;
struct V_41 * V_72 , * V_73 ;
V_72 = V_39 -> V_41 ;
V_71 = F_34 ( V_30 , V_39 -> V_41 -> V_48 -> V_49 ,
V_39 -> V_41 -> V_27 | V_70 , & V_73 ) ;
if ( V_71 )
return V_71 ;
V_39 -> V_41 = V_73 ;
F_21 ( V_30 , V_72 ) ;
return 0 ;
}
T_3 F_35 ( const char * V_74 )
{
T_3 V_47 ;
struct V_58 * V_48 ;
V_48 = F_36 ( V_74 ) ;
if ( F_37 ( V_48 ) )
V_47 = F_38 ( V_74 ) ;
else {
V_47 = V_48 -> V_49 ;
F_39 ( V_48 ) ;
}
return V_47 ;
}
int F_40 ( struct V_21 * V_50 , const char * V_74 , T_2 V_27 ,
struct V_41 * * V_3 )
{
int V_71 ;
T_3 V_47 ;
struct V_38 * V_39 ;
struct V_6 * V_7 = V_50 -> V_67 ;
F_41 ( ! V_7 ) ;
V_47 = F_35 ( V_74 ) ;
if ( ! V_47 )
return - V_75 ;
V_39 = F_25 ( & V_7 -> V_32 , V_47 ) ;
if ( ! V_39 ) {
V_39 = F_42 ( sizeof( * V_39 ) , V_31 ) ;
if ( ! V_39 )
return - V_23 ;
if ( ( V_71 = F_34 ( V_7 -> V_30 , V_47 , V_27 , & V_39 -> V_41 ) ) ) {
F_15 ( V_39 ) ;
return V_71 ;
}
F_43 ( & V_39 -> V_76 , 0 ) ;
F_44 ( & V_39 -> V_40 , & V_7 -> V_32 ) ;
} else if ( V_39 -> V_41 -> V_27 != ( V_27 | V_39 -> V_41 -> V_27 ) ) {
V_71 = F_33 ( V_39 , V_27 , V_7 -> V_30 ) ;
if ( V_71 )
return V_71 ;
}
F_45 ( & V_39 -> V_76 ) ;
* V_3 = V_39 -> V_41 ;
return 0 ;
}
static int F_46 ( struct V_21 * V_50 , struct V_41 * V_47 ,
T_1 V_51 , T_1 V_52 , void * V_53 )
{
struct V_56 * V_57 = V_53 ;
struct V_58 * V_48 = V_47 -> V_48 ;
struct V_54 * V_55 = F_29 ( V_48 ) ;
char V_64 [ V_65 ] ;
if ( F_47 ( ! V_55 ) ) {
F_19 ( L_10 ,
F_20 ( V_50 -> V_67 -> V_30 ) , F_30 ( V_48 , V_64 ) ) ;
return 0 ;
}
if ( F_48 ( V_57 , V_48 , V_51 ) < 0 )
F_19 ( L_11
L_12
L_13 ,
F_20 ( V_50 -> V_67 -> V_30 ) , F_30 ( V_48 , V_64 ) ,
V_55 -> V_57 . V_77 ,
V_55 -> V_57 . V_63 ,
V_55 -> V_57 . V_78 ,
( unsigned long long ) V_51 << V_61 ) ;
V_57 -> V_79 = F_49 ( V_55 ) ;
return 0 ;
}
void F_50 ( struct V_21 * V_50 , struct V_41 * V_80 )
{
int V_81 = 0 ;
struct V_35 * V_32 = & V_50 -> V_67 -> V_32 ;
struct V_38 * V_39 ;
F_26 (dd, devices, list) {
if ( V_39 -> V_41 == V_80 ) {
V_81 = 1 ;
break;
}
}
if ( ! V_81 ) {
F_19 ( L_14 ,
F_20 ( V_50 -> V_67 -> V_30 ) , V_80 -> V_42 ) ;
return;
}
if ( F_51 ( & V_39 -> V_76 ) ) {
F_21 ( V_50 -> V_67 -> V_30 , V_80 ) ;
F_52 ( & V_39 -> V_40 ) ;
F_15 ( V_39 ) ;
}
}
static int F_53 ( struct V_6 * V_67 , struct V_21 * V_50 )
{
struct V_21 * V_82 ;
if ( ! V_67 -> V_28 )
return ! V_50 -> V_83 ;
V_82 = & V_67 -> V_26 [ V_67 -> V_28 - 1 ] ;
return ( V_50 -> V_83 == ( V_82 -> V_83 + V_82 -> V_52 ) ) ;
}
static char * * F_54 ( unsigned * V_84 , char * * V_85 )
{
char * * V_86 ;
unsigned V_87 ;
T_4 V_88 ;
if ( * V_84 ) {
V_87 = * V_84 * 2 ;
V_88 = V_31 ;
} else {
V_87 = 8 ;
V_88 = V_89 ;
}
V_86 = F_42 ( V_87 * sizeof( * V_86 ) , V_88 ) ;
if ( V_86 ) {
memcpy ( V_86 , V_85 , * V_84 * sizeof( * V_86 ) ) ;
* V_84 = V_87 ;
}
F_15 ( V_85 ) ;
return V_86 ;
}
int F_55 ( int * V_90 , char * * * V_91 , char * V_92 )
{
char * V_51 , * V_93 = V_92 , * V_94 , * * V_86 = NULL ;
unsigned V_84 = 0 ;
* V_90 = 0 ;
if ( ! V_92 ) {
* V_91 = NULL ;
return 0 ;
}
V_86 = F_54 ( & V_84 , V_86 ) ;
if ( ! V_86 )
return - V_23 ;
while ( 1 ) {
V_51 = F_56 ( V_93 ) ;
if ( ! * V_51 )
break;
V_93 = V_94 = V_51 ;
while ( * V_93 ) {
if ( * V_93 == '\\' && * ( V_93 + 1 ) ) {
* V_94 ++ = * ( V_93 + 1 ) ;
V_93 += 2 ;
continue;
}
if ( isspace ( * V_93 ) )
break;
* V_94 ++ = * V_93 ++ ;
}
if ( ( * V_90 + 1 ) > V_84 ) {
V_86 = F_54 ( & V_84 , V_86 ) ;
if ( ! V_86 )
return - V_23 ;
}
if ( * V_93 )
V_93 ++ ;
* V_94 = '\0' ;
V_86 [ * V_90 ] = V_51 ;
( * V_90 ) ++ ;
}
* V_91 = V_86 ;
return 0 ;
}
static int F_57 ( struct V_6 * V_67 ,
struct V_56 * V_57 )
{
unsigned short V_95 =
V_57 -> V_63 >> V_61 ;
unsigned short V_96 = 0 ;
unsigned short V_97 = 0 ;
struct V_21 * V_98 ( V_50 ) ;
struct V_56 V_99 ;
unsigned V_43 ;
for ( V_43 = 0 ; V_43 < F_58 ( V_67 ) ; V_43 ++ ) {
V_50 = F_59 ( V_67 , V_43 ) ;
F_60 ( & V_99 ) ;
if ( V_50 -> type -> V_100 )
V_50 -> type -> V_100 ( V_50 , F_46 ,
& V_99 ) ;
if ( V_97 < V_50 -> V_52 &&
V_97 & ( ( V_99 . V_63 >>
V_61 ) - 1 ) )
break;
V_96 =
( unsigned short ) ( ( V_96 + V_50 -> V_52 ) &
( V_95 - 1 ) ) ;
V_97 = V_96 ?
V_95 - V_96 : 0 ;
}
if ( V_97 ) {
F_19 ( L_15
L_16 ,
F_20 ( V_67 -> V_30 ) , V_43 ,
( unsigned long long ) V_50 -> V_83 ,
( unsigned long long ) V_50 -> V_52 ,
V_57 -> V_63 ) ;
return - V_101 ;
}
return 0 ;
}
int F_61 ( struct V_6 * V_7 , const char * type ,
T_1 V_51 , T_1 V_52 , char * V_102 )
{
int V_71 = - V_101 , V_90 ;
char * * V_86 ;
struct V_21 * V_44 ;
if ( V_7 -> V_103 ) {
F_62 ( L_17 ,
F_20 ( V_7 -> V_30 ) , V_7 -> V_26 -> type -> V_42 ) ;
return - V_101 ;
}
F_41 ( V_7 -> V_28 >= V_7 -> V_25 ) ;
V_44 = V_7 -> V_26 + V_7 -> V_28 ;
memset ( V_44 , 0 , sizeof( * V_44 ) ) ;
if ( ! V_52 ) {
F_62 ( L_18 , F_20 ( V_7 -> V_30 ) ) ;
return - V_101 ;
}
V_44 -> type = F_63 ( type ) ;
if ( ! V_44 -> type ) {
F_62 ( L_19 , F_20 ( V_7 -> V_30 ) , type ) ;
return - V_101 ;
}
if ( F_64 ( V_44 -> type ) ) {
if ( V_7 -> V_28 ) {
V_44 -> error = L_20 ;
goto V_104;
}
V_7 -> V_103 = true ;
}
if ( F_65 ( V_44 -> type ) && ! ( V_7 -> V_27 & V_105 ) ) {
V_44 -> error = L_21 ;
goto V_104;
}
if ( V_7 -> V_106 ) {
if ( V_7 -> V_106 != V_44 -> type ) {
V_44 -> error = L_22 ;
goto V_104;
}
} else if ( F_66 ( V_44 -> type ) ) {
if ( V_7 -> V_28 ) {
V_44 -> error = L_22 ;
goto V_104;
}
V_7 -> V_106 = V_44 -> type ;
}
if ( F_67 ( V_44 -> type ) )
V_7 -> V_107 = 1 ;
V_44 -> V_67 = V_7 ;
V_44 -> V_83 = V_51 ;
V_44 -> V_52 = V_52 ;
V_44 -> error = L_23 ;
if ( ! F_53 ( V_7 , V_44 ) ) {
V_44 -> error = L_24 ;
goto V_104;
}
V_71 = F_55 ( & V_90 , & V_86 , V_102 ) ;
if ( V_71 ) {
V_44 -> error = L_25 ;
goto V_104;
}
V_71 = V_44 -> type -> V_108 ( V_44 , V_90 , V_86 ) ;
F_15 ( V_86 ) ;
if ( V_71 )
goto V_104;
V_7 -> V_24 [ V_7 -> V_28 ++ ] = V_44 -> V_83 + V_44 -> V_52 - 1 ;
if ( ! V_44 -> V_109 && V_44 -> V_110 )
F_19 ( L_26 ,
F_20 ( V_7 -> V_30 ) , type ) ;
return 0 ;
V_104:
F_62 ( L_27 , F_20 ( V_7 -> V_30 ) , type , V_44 -> error ) ;
F_23 ( V_44 -> type ) ;
return V_71 ;
}
static int F_68 ( const struct V_111 * V_112 ,
struct V_113 * V_114 ,
unsigned * V_115 , char * * error , unsigned V_116 )
{
const char * V_117 = F_69 ( V_114 ) ;
char V_118 ;
if ( ! V_117 ||
( sscanf ( V_117 , L_28 , V_115 , & V_118 ) != 1 ) ||
( * V_115 < V_112 -> V_119 ) ||
( * V_115 > V_112 -> V_120 ) ||
( V_116 && V_114 -> V_90 < * V_115 ) ) {
* error = V_112 -> error ;
return - V_101 ;
}
return 0 ;
}
int F_70 ( const struct V_111 * V_112 , struct V_113 * V_114 ,
unsigned * V_115 , char * * error )
{
return F_68 ( V_112 , V_114 , V_115 , error , 0 ) ;
}
int F_71 ( const struct V_111 * V_112 , struct V_113 * V_114 ,
unsigned * V_115 , char * * error )
{
return F_68 ( V_112 , V_114 , V_115 , error , 1 ) ;
}
const char * F_69 ( struct V_113 * V_121 )
{
char * V_71 ;
if ( V_121 -> V_90 ) {
V_121 -> V_90 -- ;
V_71 = * V_121 -> V_86 ;
V_121 -> V_86 ++ ;
return V_71 ;
}
return NULL ;
}
void F_72 ( struct V_113 * V_121 , unsigned V_122 )
{
F_41 ( V_121 -> V_90 < V_122 ) ;
V_121 -> V_90 -= V_122 ;
V_121 -> V_86 += V_122 ;
}
static bool F_73 ( enum V_123 V_124 )
{
return ( V_124 == V_125 ||
V_124 == V_126 ) ;
}
static bool F_74 ( enum V_123 V_124 )
{
return ( V_124 == V_127 ||
V_124 == V_128 ) ;
}
void F_75 ( struct V_6 * V_7 , enum V_123 type )
{
V_7 -> type = type ;
}
static int F_76 ( struct V_21 * V_50 , struct V_41 * V_47 ,
T_1 V_51 , T_1 V_52 , void * V_53 )
{
struct V_54 * V_55 = F_29 ( V_47 -> V_48 ) ;
return V_55 && F_77 ( V_55 ) ;
}
static bool F_78 ( struct V_6 * V_7 )
{
struct V_21 * V_50 ;
unsigned V_43 ;
for ( V_43 = 0 ; V_43 < F_58 ( V_7 ) ; V_43 ++ ) {
V_50 = F_59 ( V_7 , V_43 ) ;
if ( ! V_50 -> type -> V_129 )
return false ;
if ( ! V_50 -> type -> V_100 ||
! V_50 -> type -> V_100 ( V_50 , F_76 , NULL ) )
return false ;
}
return true ;
}
static int F_79 ( struct V_6 * V_7 )
{
unsigned V_43 ;
unsigned V_130 = 0 , V_131 = 0 , V_132 = 0 ;
unsigned V_133 = 0 , V_134 = 0 ;
struct V_21 * V_44 ;
struct V_38 * V_39 ;
struct V_35 * V_32 = F_80 ( V_7 ) ;
enum V_123 V_135 = F_81 ( V_7 -> V_30 ) ;
if ( V_7 -> type != V_34 ) {
if ( V_7 -> type == V_125 )
return 0 ;
F_41 ( V_7 -> type == V_126 ) ;
goto V_136;
}
for ( V_43 = 0 ; V_43 < V_7 -> V_28 ; V_43 ++ ) {
V_44 = V_7 -> V_26 + V_43 ;
if ( F_82 ( V_44 ) )
V_132 = 1 ;
else if ( F_83 ( V_44 ) )
V_131 = 1 ;
else
V_130 = 1 ;
if ( V_130 && V_131 ) {
F_19 ( L_29
L_30 ) ;
return - V_101 ;
}
}
if ( V_132 && ! V_130 && ! V_131 ) {
if ( F_74 ( V_135 ) )
V_131 = 1 ;
else
V_130 = 1 ;
}
if ( V_130 ) {
V_7 -> type = V_125 ;
if ( F_78 ( V_7 ) ||
( F_84 ( V_32 ) && V_135 == V_126 ) )
V_7 -> type = V_126 ;
return 0 ;
}
F_41 ( ! V_131 ) ;
V_7 -> type = V_127 ;
V_136:
if ( V_7 -> V_28 > 1 ) {
F_19 ( L_31 ) ;
return - V_101 ;
}
if ( F_84 ( V_32 ) ) {
int V_137 ;
struct V_6 * V_138 = F_85 ( V_7 -> V_30 , & V_137 ) ;
if ( V_138 ) {
V_7 -> type = V_138 -> type ;
V_7 -> V_139 = V_138 -> V_139 ;
}
F_86 ( V_7 -> V_30 , V_137 ) ;
return 0 ;
}
F_26 (dd, devices, list) {
struct V_54 * V_55 = F_29 ( V_39 -> V_41 -> V_48 ) ;
if ( ! F_87 ( V_55 ) ) {
F_62 ( L_32
L_33 ) ;
return - V_101 ;
}
if ( V_55 -> V_140 )
V_134 ++ ;
else
V_133 ++ ;
}
if ( V_133 && V_134 ) {
F_62 ( L_34 ) ;
return - V_101 ;
}
V_7 -> V_139 = V_134 > 0 ;
if ( V_7 -> type == V_128 && ! V_7 -> V_139 ) {
F_62 ( L_35 ) ;
return - V_101 ;
}
return 0 ;
}
enum V_123 F_88 ( struct V_6 * V_7 )
{
return V_7 -> type ;
}
struct V_141 * F_89 ( struct V_6 * V_7 )
{
return V_7 -> V_106 ;
}
struct V_21 * F_90 ( struct V_6 * V_7 )
{
if ( V_7 -> V_28 > 1 ||
! F_66 ( V_7 -> V_26 [ 0 ] . type ) )
return NULL ;
return V_7 -> V_26 ;
}
struct V_21 * F_91 ( struct V_6 * V_7 )
{
struct V_21 * V_50 ;
unsigned V_43 ;
for ( V_43 = 0 ; V_43 < F_58 ( V_7 ) ; V_43 ++ ) {
V_50 = F_59 ( V_7 , V_43 ) ;
if ( F_92 ( V_50 -> type ) )
return V_50 ;
}
return NULL ;
}
bool F_93 ( struct V_6 * V_7 )
{
return F_73 ( F_88 ( V_7 ) ) ;
}
bool F_94 ( struct V_6 * V_7 )
{
return F_74 ( F_88 ( V_7 ) ) ;
}
bool F_95 ( struct V_6 * V_7 )
{
return V_7 -> V_139 ;
}
static int F_96 ( struct V_6 * V_7 , struct V_29 * V_30 )
{
enum V_123 type = F_88 ( V_7 ) ;
unsigned V_142 = 0 ;
struct V_21 * V_44 ;
unsigned V_43 ;
if ( F_47 ( type == V_34 ) ) {
F_19 ( L_36 ) ;
return - V_101 ;
}
if ( F_73 ( type ) )
for ( V_43 = 0 ; V_43 < V_7 -> V_28 ; V_43 ++ ) {
V_44 = V_7 -> V_26 + V_43 ;
V_142 = V_120 ( V_142 , V_44 -> V_142 ) ;
}
V_7 -> V_46 = F_97 ( V_30 , type , V_7 -> V_143 , V_142 ) ;
if ( ! V_7 -> V_46 )
return - V_23 ;
return 0 ;
}
void F_98 ( struct V_6 * V_7 )
{
F_24 ( V_7 -> V_46 ) ;
V_7 -> V_46 = NULL ;
}
struct V_144 * F_99 ( struct V_6 * V_7 )
{
return V_7 -> V_46 ;
}
static int F_100 ( struct V_6 * V_7 )
{
int V_43 ;
unsigned int V_145 = 0 ;
T_1 * V_146 ;
for ( V_43 = V_7 -> V_11 - 2 ; V_43 >= 0 ; V_43 -- ) {
V_7 -> V_12 [ V_43 ] = F_2 ( V_7 -> V_12 [ V_43 + 1 ] , V_5 ) ;
V_145 += V_7 -> V_12 [ V_43 ] ;
}
V_146 = ( T_1 * ) F_7 ( V_145 , ( unsigned long ) V_147 ) ;
if ( ! V_146 )
return - V_23 ;
for ( V_43 = V_7 -> V_11 - 2 ; V_43 >= 0 ; V_43 -- ) {
V_7 -> V_9 [ V_43 ] = V_146 ;
V_146 += ( V_10 * V_7 -> V_12 [ V_43 ] ) ;
F_6 ( V_43 , V_7 ) ;
}
return 0 ;
}
static int F_101 ( struct V_6 * V_7 )
{
int V_71 = 0 ;
unsigned int V_148 ;
V_148 = F_2 ( V_7 -> V_28 , V_10 ) ;
V_7 -> V_11 = 1 + F_1 ( V_148 , V_5 ) ;
V_7 -> V_12 [ V_7 -> V_11 - 1 ] = V_148 ;
V_7 -> V_9 [ V_7 -> V_11 - 1 ] = V_7 -> V_24 ;
if ( V_7 -> V_11 >= 2 )
V_71 = F_100 ( V_7 ) ;
return V_71 ;
}
static bool F_102 ( struct V_149 * V_150 )
{
return ! ! F_103 ( V_150 ) ;
}
static struct V_149 * F_104 ( struct V_6 * V_7 )
{
struct V_35 * V_32 = F_80 ( V_7 ) ;
struct V_38 * V_39 = NULL ;
struct V_149 * V_151 = NULL , * V_152 = NULL ;
unsigned V_43 ;
for ( V_43 = 0 ; V_43 < F_58 ( V_7 ) ; V_43 ++ ) {
struct V_21 * V_50 = F_59 ( V_7 , V_43 ) ;
if ( ! F_105 ( V_50 -> type ) )
goto V_153;
}
F_26 (dd, devices, list) {
V_152 = V_39 -> V_41 -> V_48 -> V_154 ;
if ( ! F_102 ( V_152 ) )
goto V_153;
else if ( V_151 &&
F_106 ( V_151 , V_152 ) < 0 )
goto V_153;
V_151 = V_152 ;
}
return V_152 ;
V_153:
if ( V_151 )
F_19 ( L_37 ,
F_20 ( V_7 -> V_30 ) ,
V_151 -> V_155 ,
V_152 -> V_155 ) ;
return NULL ;
}
static int F_107 ( struct V_6 * V_7 )
{
struct V_29 * V_30 = V_7 -> V_30 ;
struct V_149 * V_152 = NULL ;
if ( V_7 -> V_107 )
return 0 ;
V_152 = F_104 ( V_7 ) ;
if ( ! V_152 )
return 0 ;
if ( ! F_102 ( F_108 ( V_30 ) ) ) {
V_7 -> V_143 = true ;
F_109 ( F_108 ( V_30 ) ,
F_103 ( V_152 ) ) ;
return 0 ;
}
if ( F_106 ( F_108 ( V_30 ) , V_152 ) < 0 ) {
F_19 ( L_38
L_39 ,
F_20 ( V_7 -> V_30 ) ,
V_152 -> V_155 ) ;
return 1 ;
}
V_7 -> V_143 = true ;
return 0 ;
}
int F_110 ( struct V_6 * V_7 )
{
int V_71 ;
V_71 = F_79 ( V_7 ) ;
if ( V_71 ) {
F_62 ( L_40 ) ;
return V_71 ;
}
V_71 = F_101 ( V_7 ) ;
if ( V_71 ) {
F_62 ( L_41 ) ;
return V_71 ;
}
V_71 = F_107 ( V_7 ) ;
if ( V_71 ) {
F_62 ( L_42 ) ;
return V_71 ;
}
V_71 = F_96 ( V_7 , V_7 -> V_30 ) ;
if ( V_71 )
F_62 ( L_43 ) ;
return V_71 ;
}
void F_111 ( struct V_6 * V_7 ,
void (* F_112)( void * ) , void * V_156 )
{
F_113 ( & V_157 ) ;
V_7 -> V_158 = F_112 ;
V_7 -> V_159 = V_156 ;
F_114 ( & V_157 ) ;
}
void F_115 ( struct V_6 * V_7 )
{
F_41 ( F_116 () ) ;
F_113 ( & V_157 ) ;
if ( V_7 -> V_158 )
V_7 -> V_158 ( V_7 -> V_159 ) ;
F_114 ( & V_157 ) ;
}
T_1 F_117 ( struct V_6 * V_7 )
{
return V_7 -> V_28 ? ( V_7 -> V_24 [ V_7 -> V_28 - 1 ] + 1 ) : 0 ;
}
struct V_21 * F_59 ( struct V_6 * V_7 , unsigned int V_9 )
{
if ( V_9 >= V_7 -> V_28 )
return NULL ;
return V_7 -> V_26 + V_9 ;
}
struct V_21 * F_118 ( struct V_6 * V_7 , T_1 V_160 )
{
unsigned int V_8 , V_1 = 0 , V_4 = 0 ;
T_1 * V_13 ;
for ( V_8 = 0 ; V_8 < V_7 -> V_11 ; V_8 ++ ) {
V_1 = F_3 ( V_1 , V_4 ) ;
V_13 = F_4 ( V_7 , V_8 , V_1 ) ;
for ( V_4 = 0 ; V_4 < V_10 ; V_4 ++ )
if ( V_13 [ V_4 ] >= V_160 )
break;
}
return & V_7 -> V_26 [ ( V_10 * V_1 ) + V_4 ] ;
}
static int F_119 ( struct V_21 * V_50 , struct V_41 * V_47 ,
T_1 V_51 , T_1 V_52 , void * V_53 )
{
unsigned * V_161 = V_53 ;
( * V_161 ) ++ ;
return 0 ;
}
bool F_120 ( struct V_6 * V_67 )
{
struct V_21 * V_50 ;
unsigned V_43 , V_161 ;
for ( V_43 = 0 ; V_43 < F_58 ( V_67 ) ; V_43 ++ ) {
V_50 = F_59 ( V_67 , V_43 ) ;
if ( ! V_50 -> type -> V_100 )
return false ;
V_161 = 0 ;
V_50 -> type -> V_100 ( V_50 , F_119 , & V_161 ) ;
if ( V_161 )
return false ;
}
return true ;
}
static int F_121 ( struct V_21 * V_50 , struct V_41 * V_47 ,
T_1 V_51 , T_1 V_52 , void * V_53 )
{
struct V_54 * V_55 = F_29 ( V_47 -> V_48 ) ;
enum V_162 * V_163 = V_53 ;
return V_55 && F_49 ( V_55 ) == * V_163 ;
}
static bool F_122 ( struct V_6 * V_7 ,
enum V_162 V_163 )
{
struct V_21 * V_50 ;
unsigned V_43 ;
for ( V_43 = 0 ; V_43 < F_58 ( V_7 ) ; V_43 ++ ) {
V_50 = F_59 ( V_7 , V_43 ) ;
if ( V_163 == V_164 &&
! F_123 ( V_50 -> type ) )
return false ;
if ( ! V_50 -> type -> V_100 ||
! V_50 -> type -> V_100 ( V_50 , F_121 , & V_163 ) )
return false ;
}
return true ;
}
static int F_124 ( struct V_21 * V_50 , struct V_41 * V_47 ,
T_1 V_51 , T_1 V_52 , void * V_53 )
{
struct V_54 * V_55 = F_29 ( V_47 -> V_48 ) ;
unsigned int * V_69 = V_53 ;
return V_55 && F_125 ( V_55 ) == * V_69 ;
}
static bool F_126 ( struct V_6 * V_7 ,
unsigned int V_69 )
{
struct V_21 * V_50 ;
unsigned V_43 ;
for ( V_43 = 0 ; V_43 < F_58 ( V_7 ) ; V_43 ++ ) {
V_50 = F_59 ( V_7 , V_43 ) ;
if ( ! V_50 -> type -> V_100 ||
! V_50 -> type -> V_100 ( V_50 , F_124 , & V_69 ) )
return false ;
}
return true ;
}
static int F_127 ( struct V_6 * V_67 ,
enum V_162 V_163 ,
unsigned int V_69 )
{
if ( V_163 == V_68 )
return 0 ;
if ( ! F_122 ( V_67 , V_163 ) ) {
F_62 ( L_44 ,
F_20 ( V_67 -> V_30 ) ) ;
return - V_101 ;
}
if ( ! V_69 || ! F_128 ( V_69 ) )
return - V_101 ;
if ( ! F_126 ( V_67 , V_69 ) ) {
F_62 ( L_45 ,
F_20 ( V_67 -> V_30 ) ) ;
return - V_101 ;
}
return 0 ;
}
int F_129 ( struct V_6 * V_67 ,
struct V_56 * V_57 )
{
struct V_21 * V_50 ;
struct V_56 V_99 ;
unsigned V_43 ;
enum V_162 V_163 = V_68 ;
unsigned int V_69 = 0 ;
F_60 ( V_57 ) ;
for ( V_43 = 0 ; V_43 < F_58 ( V_67 ) ; V_43 ++ ) {
F_60 ( & V_99 ) ;
V_50 = F_59 ( V_67 , V_43 ) ;
if ( ! V_50 -> type -> V_100 )
goto V_165;
V_50 -> type -> V_100 ( V_50 , F_46 ,
& V_99 ) ;
if ( V_163 == V_68 && V_99 . V_79 != V_68 ) {
V_163 = V_99 . V_79 ;
V_69 = V_99 . V_166 ;
}
if ( V_50 -> type -> V_167 )
V_50 -> type -> V_167 ( V_50 , & V_99 ) ;
if ( V_50 -> type -> V_100 ( V_50 , F_27 ,
& V_99 ) )
return - V_101 ;
V_165:
if ( F_130 ( V_57 , & V_99 , 0 ) < 0 )
F_19 ( L_46
L_47
L_48 ,
F_20 ( V_67 -> V_30 ) ,
( unsigned long long ) V_50 -> V_83 ,
( unsigned long long ) V_50 -> V_52 ) ;
if ( V_57 -> V_79 == V_68 && V_99 . V_79 != V_68 ) {
V_57 -> V_79 = V_99 . V_79 ;
}
}
if ( V_57 -> V_79 != V_68 ) {
V_163 = V_57 -> V_79 ;
V_69 = V_57 -> V_166 ;
}
if ( F_127 ( V_67 , V_163 , V_69 ) )
return - V_101 ;
return F_57 ( V_67 , V_57 ) ;
}
static void F_131 ( struct V_6 * V_7 )
{
struct V_149 * V_152 = NULL ;
if ( V_7 -> V_107 )
return;
if ( V_7 -> V_143 ) {
V_152 = F_104 ( V_7 ) ;
if ( V_152 &&
F_106 ( F_108 ( V_7 -> V_30 ) , V_152 ) >= 0 )
return;
}
if ( F_102 ( F_108 ( V_7 -> V_30 ) ) ) {
F_19 ( L_49 ,
F_20 ( V_7 -> V_30 ) ) ;
F_132 ( F_108 ( V_7 -> V_30 ) ) ;
}
}
static int F_133 ( struct V_21 * V_50 , struct V_41 * V_47 ,
T_1 V_51 , T_1 V_52 , void * V_53 )
{
unsigned long V_168 = ( unsigned long ) V_53 ;
struct V_54 * V_55 = F_29 ( V_47 -> V_48 ) ;
return V_55 && ( V_55 -> V_169 & V_168 ) ;
}
static bool F_134 ( struct V_6 * V_7 , unsigned long V_168 )
{
struct V_21 * V_50 ;
unsigned V_43 ;
for ( V_43 = 0 ; V_43 < F_58 ( V_7 ) ; V_43 ++ ) {
V_50 = F_59 ( V_7 , V_43 ) ;
if ( ! V_50 -> V_170 )
continue;
if ( V_50 -> V_171 )
return true ;
if ( V_50 -> type -> V_100 &&
V_50 -> type -> V_100 ( V_50 , F_133 , ( void * ) V_168 ) )
return true ;
}
return false ;
}
static int F_135 ( struct V_21 * V_50 ,
struct V_41 * V_47 , T_1 V_51 ,
T_1 V_52 , void * V_53 )
{
struct V_172 * V_173 = V_47 -> V_173 ;
if ( ! V_173 )
return false ;
if ( F_136 ( V_173 ) )
return true ;
return false ;
}
static int F_137 ( struct V_6 * V_7 )
{
struct V_21 * V_50 ;
unsigned V_43 ;
for ( V_43 = 0 ; V_43 < F_58 ( V_7 ) ; V_43 ++ ) {
V_50 = F_59 ( V_7 , V_43 ) ;
if ( V_50 -> type -> V_100 &&
V_50 -> type -> V_100 ( V_50 ,
F_135 , NULL ) )
return true ;
}
return false ;
}
static int F_138 ( struct V_21 * V_50 , struct V_41 * V_47 ,
T_1 V_51 , T_1 V_52 , void * V_53 )
{
struct V_54 * V_55 = F_29 ( V_47 -> V_48 ) ;
return V_55 && F_139 ( V_55 ) ;
}
static int F_140 ( struct V_21 * V_50 , struct V_41 * V_47 ,
T_1 V_51 , T_1 V_52 , void * V_53 )
{
struct V_54 * V_55 = F_29 ( V_47 -> V_48 ) ;
return V_55 && ! F_141 ( V_55 ) ;
}
static int F_142 ( struct V_21 * V_50 , struct V_41 * V_47 ,
T_1 V_51 , T_1 V_52 , void * V_53 )
{
struct V_54 * V_55 = F_29 ( V_47 -> V_48 ) ;
return V_55 && ! F_143 ( V_174 , & V_55 -> V_169 ) ;
}
static bool F_144 ( struct V_6 * V_7 ,
T_5 V_175 )
{
struct V_21 * V_50 ;
unsigned V_43 ;
for ( V_43 = 0 ; V_43 < F_58 ( V_7 ) ; V_43 ++ ) {
V_50 = F_59 ( V_7 , V_43 ) ;
if ( ! V_50 -> type -> V_100 ||
! V_50 -> type -> V_100 ( V_50 , V_175 , NULL ) )
return false ;
}
return true ;
}
static int F_145 ( struct V_21 * V_50 , struct V_41 * V_47 ,
T_1 V_51 , T_1 V_52 , void * V_53 )
{
struct V_54 * V_55 = F_29 ( V_47 -> V_48 ) ;
return V_55 && ! V_55 -> V_57 . V_176 ;
}
static bool F_146 ( struct V_6 * V_7 )
{
struct V_21 * V_50 ;
unsigned V_43 ;
for ( V_43 = 0 ; V_43 < F_58 ( V_7 ) ; V_43 ++ ) {
V_50 = F_59 ( V_7 , V_43 ) ;
if ( ! V_50 -> V_177 )
return false ;
if ( ! V_50 -> type -> V_100 ||
V_50 -> type -> V_100 ( V_50 , F_145 , NULL ) )
return false ;
}
return true ;
}
static int F_147 ( struct V_21 * V_50 , struct V_41 * V_47 ,
T_1 V_51 , T_1 V_52 , void * V_53 )
{
struct V_54 * V_55 = F_29 ( V_47 -> V_48 ) ;
return V_55 && ! V_55 -> V_57 . V_178 ;
}
static bool F_148 ( struct V_6 * V_7 )
{
struct V_21 * V_50 ;
unsigned V_43 = 0 ;
while ( V_43 < F_58 ( V_7 ) ) {
V_50 = F_59 ( V_7 , V_43 ++ ) ;
if ( ! V_50 -> V_179 )
return false ;
if ( ! V_50 -> type -> V_100 ||
V_50 -> type -> V_100 ( V_50 , F_147 , NULL ) )
return false ;
}
return true ;
}
static int F_149 ( struct V_21 * V_50 , struct V_41 * V_47 ,
T_1 V_51 , T_1 V_52 , void * V_53 )
{
struct V_54 * V_55 = F_29 ( V_47 -> V_48 ) ;
return V_55 && F_150 ( V_55 ) ;
}
static bool F_151 ( struct V_6 * V_7 )
{
struct V_21 * V_50 ;
unsigned V_43 ;
for ( V_43 = 0 ; V_43 < F_58 ( V_7 ) ; V_43 ++ ) {
V_50 = F_59 ( V_7 , V_43 ) ;
if ( ! V_50 -> V_109 )
continue;
if ( V_50 -> V_110 )
return true ;
if ( V_50 -> type -> V_100 &&
V_50 -> type -> V_100 ( V_50 , F_149 , NULL ) )
return true ;
}
return false ;
}
void F_152 ( struct V_6 * V_7 , struct V_54 * V_55 ,
struct V_56 * V_57 )
{
bool V_180 = false , V_181 = false ;
V_55 -> V_57 = * V_57 ;
if ( ! F_151 ( V_7 ) )
F_153 ( V_182 , V_55 ) ;
else
F_154 ( V_182 , V_55 ) ;
if ( F_134 ( V_7 , ( 1UL << V_183 ) ) ) {
V_180 = true ;
if ( F_134 ( V_7 , ( 1UL << V_184 ) ) )
V_181 = true ;
}
F_155 ( V_55 , V_180 , V_181 ) ;
if ( F_137 ( V_7 ) )
F_156 ( V_7 -> V_30 -> V_173 , true ) ;
if ( F_144 ( V_7 , F_138 ) )
F_154 ( V_185 , V_55 ) ;
else
F_153 ( V_185 , V_55 ) ;
if ( ! F_146 ( V_7 ) )
V_55 -> V_57 . V_176 = 0 ;
if ( ! F_148 ( V_7 ) )
V_55 -> V_57 . V_178 = 0 ;
if ( F_144 ( V_7 , F_142 ) )
F_153 ( V_174 , V_55 ) ;
else
F_154 ( V_174 , V_55 ) ;
F_131 ( V_7 ) ;
if ( F_141 ( V_55 ) && F_144 ( V_7 , F_140 ) )
F_153 ( V_186 , V_55 ) ;
F_157 () ;
if ( F_94 ( V_7 ) )
F_154 ( V_187 , V_55 ) ;
}
unsigned int F_58 ( struct V_6 * V_7 )
{
return V_7 -> V_28 ;
}
struct V_35 * F_80 ( struct V_6 * V_7 )
{
return & V_7 -> V_32 ;
}
T_2 F_158 ( struct V_6 * V_7 )
{
return V_7 -> V_27 ;
}
static void F_159 ( struct V_6 * V_7 , enum V_188 V_27 )
{
int V_43 = V_7 -> V_28 ;
struct V_21 * V_50 = V_7 -> V_26 ;
F_160 ( & V_7 -> V_30 -> V_189 ) ;
while ( V_43 -- ) {
switch ( V_27 ) {
case V_190 :
if ( V_50 -> type -> V_191 )
V_50 -> type -> V_191 ( V_50 ) ;
break;
case V_192 :
if ( V_50 -> type -> V_193 )
V_50 -> type -> V_193 ( V_50 ) ;
break;
case V_194 :
if ( V_50 -> type -> V_195 )
V_50 -> type -> V_195 ( V_50 ) ;
break;
}
V_50 ++ ;
}
}
void F_161 ( struct V_6 * V_7 )
{
if ( ! V_7 )
return;
F_159 ( V_7 , V_190 ) ;
}
void F_162 ( struct V_6 * V_7 )
{
if ( ! V_7 )
return;
F_159 ( V_7 , V_192 ) ;
}
void F_163 ( struct V_6 * V_7 )
{
if ( ! V_7 )
return;
F_159 ( V_7 , V_194 ) ;
}
int F_164 ( struct V_6 * V_7 )
{
int V_43 , V_71 = 0 ;
F_160 ( & V_7 -> V_30 -> V_189 ) ;
for ( V_43 = 0 ; V_43 < V_7 -> V_28 ; V_43 ++ ) {
struct V_21 * V_50 = V_7 -> V_26 + V_43 ;
if ( ! V_50 -> type -> V_196 )
continue;
V_71 = V_50 -> type -> V_196 ( V_50 ) ;
if ( V_71 ) {
F_62 ( L_50 ,
F_20 ( V_7 -> V_30 ) , V_50 -> type -> V_42 , V_71 ) ;
return V_71 ;
}
}
for ( V_43 = 0 ; V_43 < V_7 -> V_28 ; V_43 ++ ) {
struct V_21 * V_50 = V_7 -> V_26 + V_43 ;
if ( V_50 -> type -> V_197 )
V_50 -> type -> V_197 ( V_50 ) ;
}
return 0 ;
}
void F_165 ( struct V_6 * V_7 , struct V_198 * V_199 )
{
F_44 ( & V_199 -> V_40 , & V_7 -> V_33 ) ;
}
int F_166 ( struct V_6 * V_7 , int V_200 )
{
struct V_38 * V_39 ;
struct V_35 * V_32 = F_80 ( V_7 ) ;
struct V_198 * V_199 ;
int V_71 = 0 ;
F_26 (dd, devices, list) {
struct V_54 * V_55 = F_29 ( V_39 -> V_41 -> V_48 ) ;
char V_64 [ V_65 ] ;
if ( F_167 ( V_55 ) )
V_71 |= F_168 ( V_55 -> V_201 , V_200 ) ;
else
F_169 ( L_51 ,
F_20 ( V_7 -> V_30 ) ,
F_30 ( V_39 -> V_41 -> V_48 , V_64 ) ) ;
}
F_26 (cb, &t->target_callbacks, list)
if ( V_199 -> V_202 )
V_71 |= V_199 -> V_202 ( V_199 , V_200 ) ;
return V_71 ;
}
struct V_29 * F_170 ( struct V_6 * V_7 )
{
return V_7 -> V_30 ;
}
void F_171 ( struct V_6 * V_7 )
{
struct V_29 * V_30 ;
struct V_54 * V_203 ;
unsigned long V_204 ;
if ( ! F_94 ( V_7 ) )
return;
V_30 = F_170 ( V_7 ) ;
V_203 = F_172 ( V_30 ) ;
if ( V_203 ) {
if ( V_203 -> V_140 )
F_173 ( V_203 , true ) ;
else {
F_174 ( V_203 -> V_205 , V_204 ) ;
F_175 ( V_203 ) ;
F_176 ( V_203 -> V_205 , V_204 ) ;
}
}
}
