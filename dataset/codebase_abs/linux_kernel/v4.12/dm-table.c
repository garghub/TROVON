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
if ( V_62 <= 1 )
return 0 ;
if ( V_51 & ( V_62 - 1 ) ) {
F_19 ( L_5
L_6 ,
F_20 ( V_50 -> V_67 -> V_30 ) ,
( unsigned long long ) V_51 ,
V_57 -> V_63 , F_30 ( V_48 , V_64 ) ) ;
return 1 ;
}
if ( V_52 & ( V_62 - 1 ) ) {
F_19 ( L_7
L_6 ,
F_20 ( V_50 -> V_67 -> V_30 ) ,
( unsigned long long ) V_52 ,
V_57 -> V_63 , F_30 ( V_48 , V_64 ) ) ;
return 1 ;
}
return 0 ;
}
static int F_31 ( struct V_38 * V_39 , T_2 V_68 ,
struct V_29 * V_30 )
{
int V_69 ;
struct V_41 * V_70 , * V_71 ;
V_70 = V_39 -> V_41 ;
V_69 = F_32 ( V_30 , V_39 -> V_41 -> V_48 -> V_49 ,
V_39 -> V_41 -> V_27 | V_68 , & V_71 ) ;
if ( V_69 )
return V_69 ;
V_39 -> V_41 = V_71 ;
F_21 ( V_30 , V_70 ) ;
return 0 ;
}
T_3 F_33 ( const char * V_72 )
{
T_3 V_47 ;
struct V_58 * V_48 ;
V_48 = F_34 ( V_72 ) ;
if ( F_35 ( V_48 ) )
V_47 = F_36 ( V_72 ) ;
else {
V_47 = V_48 -> V_49 ;
F_37 ( V_48 ) ;
}
return V_47 ;
}
int F_38 ( struct V_21 * V_50 , const char * V_72 , T_2 V_27 ,
struct V_41 * * V_3 )
{
int V_69 ;
T_3 V_47 ;
struct V_38 * V_39 ;
struct V_6 * V_7 = V_50 -> V_67 ;
F_39 ( ! V_7 ) ;
V_47 = F_33 ( V_72 ) ;
if ( ! V_47 )
return - V_73 ;
V_39 = F_25 ( & V_7 -> V_32 , V_47 ) ;
if ( ! V_39 ) {
V_39 = F_40 ( sizeof( * V_39 ) , V_31 ) ;
if ( ! V_39 )
return - V_23 ;
if ( ( V_69 = F_32 ( V_7 -> V_30 , V_47 , V_27 , & V_39 -> V_41 ) ) ) {
F_15 ( V_39 ) ;
return V_69 ;
}
F_41 ( & V_39 -> V_74 , 0 ) ;
F_42 ( & V_39 -> V_40 , & V_7 -> V_32 ) ;
} else if ( V_39 -> V_41 -> V_27 != ( V_27 | V_39 -> V_41 -> V_27 ) ) {
V_69 = F_31 ( V_39 , V_27 , V_7 -> V_30 ) ;
if ( V_69 )
return V_69 ;
}
F_43 ( & V_39 -> V_74 ) ;
* V_3 = V_39 -> V_41 ;
return 0 ;
}
static int F_44 ( struct V_21 * V_50 , struct V_41 * V_47 ,
T_1 V_51 , T_1 V_52 , void * V_53 )
{
struct V_56 * V_57 = V_53 ;
struct V_58 * V_48 = V_47 -> V_48 ;
struct V_54 * V_55 = F_29 ( V_48 ) ;
char V_64 [ V_65 ] ;
if ( F_45 ( ! V_55 ) ) {
F_19 ( L_8 ,
F_20 ( V_50 -> V_67 -> V_30 ) , F_30 ( V_48 , V_64 ) ) ;
return 0 ;
}
if ( F_46 ( V_57 , V_48 , V_51 ) < 0 )
F_19 ( L_9
L_10
L_11 ,
F_20 ( V_50 -> V_67 -> V_30 ) , F_30 ( V_48 , V_64 ) ,
V_55 -> V_57 . V_75 ,
V_55 -> V_57 . V_63 ,
V_55 -> V_57 . V_76 ,
( unsigned long long ) V_51 << V_61 ) ;
return 0 ;
}
void F_47 ( struct V_21 * V_50 , struct V_41 * V_77 )
{
int V_78 = 0 ;
struct V_35 * V_32 = & V_50 -> V_67 -> V_32 ;
struct V_38 * V_39 ;
F_26 (dd, devices, list) {
if ( V_39 -> V_41 == V_77 ) {
V_78 = 1 ;
break;
}
}
if ( ! V_78 ) {
F_19 ( L_12 ,
F_20 ( V_50 -> V_67 -> V_30 ) , V_77 -> V_42 ) ;
return;
}
if ( F_48 ( & V_39 -> V_74 ) ) {
F_21 ( V_50 -> V_67 -> V_30 , V_77 ) ;
F_49 ( & V_39 -> V_40 ) ;
F_15 ( V_39 ) ;
}
}
static int F_50 ( struct V_6 * V_67 , struct V_21 * V_50 )
{
struct V_21 * V_79 ;
if ( ! V_67 -> V_28 )
return ! V_50 -> V_80 ;
V_79 = & V_67 -> V_26 [ V_67 -> V_28 - 1 ] ;
return ( V_50 -> V_80 == ( V_79 -> V_80 + V_79 -> V_52 ) ) ;
}
static char * * F_51 ( unsigned * V_81 , char * * V_82 )
{
char * * V_83 ;
unsigned V_84 ;
T_4 V_85 ;
if ( * V_81 ) {
V_84 = * V_81 * 2 ;
V_85 = V_31 ;
} else {
V_84 = 8 ;
V_85 = V_86 ;
}
V_83 = F_40 ( V_84 * sizeof( * V_83 ) , V_85 ) ;
if ( V_83 ) {
memcpy ( V_83 , V_82 , * V_81 * sizeof( * V_83 ) ) ;
* V_81 = V_84 ;
}
F_15 ( V_82 ) ;
return V_83 ;
}
int F_52 ( int * V_87 , char * * * V_88 , char * V_89 )
{
char * V_51 , * V_90 = V_89 , * V_91 , * * V_83 = NULL ;
unsigned V_81 = 0 ;
* V_87 = 0 ;
if ( ! V_89 ) {
* V_88 = NULL ;
return 0 ;
}
V_83 = F_51 ( & V_81 , V_83 ) ;
if ( ! V_83 )
return - V_23 ;
while ( 1 ) {
V_51 = F_53 ( V_90 ) ;
if ( ! * V_51 )
break;
V_90 = V_91 = V_51 ;
while ( * V_90 ) {
if ( * V_90 == '\\' && * ( V_90 + 1 ) ) {
* V_91 ++ = * ( V_90 + 1 ) ;
V_90 += 2 ;
continue;
}
if ( isspace ( * V_90 ) )
break;
* V_91 ++ = * V_90 ++ ;
}
if ( ( * V_87 + 1 ) > V_81 ) {
V_83 = F_51 ( & V_81 , V_83 ) ;
if ( ! V_83 )
return - V_23 ;
}
if ( * V_90 )
V_90 ++ ;
* V_91 = '\0' ;
V_83 [ * V_87 ] = V_51 ;
( * V_87 ) ++ ;
}
* V_88 = V_83 ;
return 0 ;
}
static int F_54 ( struct V_6 * V_67 ,
struct V_56 * V_57 )
{
unsigned short V_92 =
V_57 -> V_63 >> V_61 ;
unsigned short V_93 = 0 ;
unsigned short V_94 = 0 ;
struct V_21 * V_95 ( V_50 ) ;
struct V_56 V_96 ;
unsigned V_43 ;
for ( V_43 = 0 ; V_43 < F_55 ( V_67 ) ; V_43 ++ ) {
V_50 = F_56 ( V_67 , V_43 ) ;
F_57 ( & V_96 ) ;
if ( V_50 -> type -> V_97 )
V_50 -> type -> V_97 ( V_50 , F_44 ,
& V_96 ) ;
if ( V_94 < V_50 -> V_52 &&
V_94 & ( ( V_96 . V_63 >>
V_61 ) - 1 ) )
break;
V_93 =
( unsigned short ) ( ( V_93 + V_50 -> V_52 ) &
( V_92 - 1 ) ) ;
V_94 = V_93 ?
V_92 - V_93 : 0 ;
}
if ( V_94 ) {
F_19 ( L_13
L_14 ,
F_20 ( V_67 -> V_30 ) , V_43 ,
( unsigned long long ) V_50 -> V_80 ,
( unsigned long long ) V_50 -> V_52 ,
V_57 -> V_63 ) ;
return - V_98 ;
}
return 0 ;
}
int F_58 ( struct V_6 * V_7 , const char * type ,
T_1 V_51 , T_1 V_52 , char * V_99 )
{
int V_69 = - V_98 , V_87 ;
char * * V_83 ;
struct V_21 * V_44 ;
if ( V_7 -> V_100 ) {
F_59 ( L_15 ,
F_20 ( V_7 -> V_30 ) , V_7 -> V_26 -> type -> V_42 ) ;
return - V_98 ;
}
F_39 ( V_7 -> V_28 >= V_7 -> V_25 ) ;
V_44 = V_7 -> V_26 + V_7 -> V_28 ;
memset ( V_44 , 0 , sizeof( * V_44 ) ) ;
if ( ! V_52 ) {
F_59 ( L_16 , F_20 ( V_7 -> V_30 ) ) ;
return - V_98 ;
}
V_44 -> type = F_60 ( type ) ;
if ( ! V_44 -> type ) {
F_59 ( L_17 , F_20 ( V_7 -> V_30 ) , type ) ;
return - V_98 ;
}
if ( F_61 ( V_44 -> type ) ) {
if ( V_7 -> V_28 ) {
V_44 -> error = L_18 ;
goto V_101;
}
V_7 -> V_100 = true ;
}
if ( F_62 ( V_44 -> type ) && ! ( V_7 -> V_27 & V_102 ) ) {
V_44 -> error = L_19 ;
goto V_101;
}
if ( V_7 -> V_103 ) {
if ( V_7 -> V_103 != V_44 -> type ) {
V_44 -> error = L_20 ;
goto V_101;
}
} else if ( F_63 ( V_44 -> type ) ) {
if ( V_7 -> V_28 ) {
V_44 -> error = L_20 ;
goto V_101;
}
V_7 -> V_103 = V_44 -> type ;
}
if ( F_64 ( V_44 -> type ) )
V_7 -> V_104 = 1 ;
V_44 -> V_67 = V_7 ;
V_44 -> V_80 = V_51 ;
V_44 -> V_52 = V_52 ;
V_44 -> error = L_21 ;
if ( ! F_50 ( V_7 , V_44 ) ) {
V_44 -> error = L_22 ;
goto V_101;
}
V_69 = F_52 ( & V_87 , & V_83 , V_99 ) ;
if ( V_69 ) {
V_44 -> error = L_23 ;
goto V_101;
}
V_69 = V_44 -> type -> V_105 ( V_44 , V_87 , V_83 ) ;
F_15 ( V_83 ) ;
if ( V_69 )
goto V_101;
V_7 -> V_24 [ V_7 -> V_28 ++ ] = V_44 -> V_80 + V_44 -> V_52 - 1 ;
if ( ! V_44 -> V_106 && V_44 -> V_107 )
F_19 ( L_24 ,
F_20 ( V_7 -> V_30 ) , type ) ;
return 0 ;
V_101:
F_59 ( L_25 , F_20 ( V_7 -> V_30 ) , type , V_44 -> error ) ;
F_23 ( V_44 -> type ) ;
return V_69 ;
}
static int F_65 ( struct V_108 * V_109 , struct V_110 * V_111 ,
unsigned * V_112 , char * * error , unsigned V_113 )
{
const char * V_114 = F_66 ( V_111 ) ;
char V_115 ;
if ( ! V_114 ||
( sscanf ( V_114 , L_26 , V_112 , & V_115 ) != 1 ) ||
( * V_112 < V_109 -> V_116 ) ||
( * V_112 > V_109 -> V_117 ) ||
( V_113 && V_111 -> V_87 < * V_112 ) ) {
* error = V_109 -> error ;
return - V_98 ;
}
return 0 ;
}
int F_67 ( struct V_108 * V_109 , struct V_110 * V_111 ,
unsigned * V_112 , char * * error )
{
return F_65 ( V_109 , V_111 , V_112 , error , 0 ) ;
}
int F_68 ( struct V_108 * V_109 , struct V_110 * V_111 ,
unsigned * V_112 , char * * error )
{
return F_65 ( V_109 , V_111 , V_112 , error , 1 ) ;
}
const char * F_66 ( struct V_110 * V_118 )
{
char * V_69 ;
if ( V_118 -> V_87 ) {
V_118 -> V_87 -- ;
V_69 = * V_118 -> V_83 ;
V_118 -> V_83 ++ ;
return V_69 ;
}
return NULL ;
}
void F_69 ( struct V_110 * V_118 , unsigned V_119 )
{
F_39 ( V_118 -> V_87 < V_119 ) ;
V_118 -> V_87 -= V_119 ;
V_118 -> V_83 += V_119 ;
}
static bool F_70 ( enum V_120 V_121 )
{
return ( V_121 == V_122 ||
V_121 == V_123 ) ;
}
static bool F_71 ( enum V_120 V_121 )
{
return ( V_121 == V_124 ||
V_121 == V_125 ) ;
}
void F_72 ( struct V_6 * V_7 , enum V_120 type )
{
V_7 -> type = type ;
}
static int F_73 ( struct V_21 * V_50 , struct V_41 * V_47 ,
T_1 V_51 , T_1 V_52 , void * V_53 )
{
struct V_54 * V_55 = F_29 ( V_47 -> V_48 ) ;
return V_55 && F_74 ( V_55 ) ;
}
static bool F_75 ( struct V_6 * V_7 )
{
struct V_21 * V_50 ;
unsigned V_43 ;
for ( V_43 = 0 ; V_43 < F_55 ( V_7 ) ; V_43 ++ ) {
V_50 = F_56 ( V_7 , V_43 ) ;
if ( ! V_50 -> type -> V_126 )
return false ;
if ( ! V_50 -> type -> V_97 ||
! V_50 -> type -> V_97 ( V_50 , F_73 , NULL ) )
return false ;
}
return true ;
}
static int F_76 ( struct V_6 * V_7 )
{
unsigned V_43 ;
unsigned V_127 = 0 , V_128 = 0 , V_129 = 0 ;
unsigned V_130 = 0 , V_131 = 0 ;
struct V_21 * V_44 ;
struct V_38 * V_39 ;
struct V_35 * V_32 = F_77 ( V_7 ) ;
enum V_120 V_132 = F_78 ( V_7 -> V_30 ) ;
if ( V_7 -> type != V_34 ) {
if ( V_7 -> type == V_122 )
return 0 ;
F_39 ( V_7 -> type == V_123 ) ;
goto V_133;
}
for ( V_43 = 0 ; V_43 < V_7 -> V_28 ; V_43 ++ ) {
V_44 = V_7 -> V_26 + V_43 ;
if ( F_79 ( V_44 ) )
V_129 = 1 ;
else if ( F_80 ( V_44 ) )
V_128 = 1 ;
else
V_127 = 1 ;
if ( V_127 && V_128 ) {
F_19 ( L_27
L_28 ) ;
return - V_98 ;
}
}
if ( V_129 && ! V_127 && ! V_128 ) {
if ( F_71 ( V_132 ) )
V_128 = 1 ;
else
V_127 = 1 ;
}
if ( V_127 ) {
V_7 -> type = V_122 ;
if ( F_75 ( V_7 ) ||
( F_81 ( V_32 ) && V_132 == V_123 ) )
V_7 -> type = V_123 ;
return 0 ;
}
F_39 ( ! V_128 ) ;
V_7 -> type = V_124 ;
V_133:
if ( V_7 -> V_28 > 1 ) {
F_19 ( L_29 ) ;
return - V_98 ;
}
if ( F_81 ( V_32 ) ) {
int V_134 ;
struct V_6 * V_135 = F_82 ( V_7 -> V_30 , & V_134 ) ;
if ( V_135 ) {
V_7 -> type = V_135 -> type ;
V_7 -> V_136 = V_135 -> V_136 ;
}
F_83 ( V_7 -> V_30 , V_134 ) ;
return 0 ;
}
F_26 (dd, devices, list) {
struct V_54 * V_55 = F_29 ( V_39 -> V_41 -> V_48 ) ;
if ( ! F_84 ( V_55 ) ) {
F_59 ( L_30
L_31 ) ;
return - V_98 ;
}
if ( V_55 -> V_137 )
V_131 ++ ;
else
V_130 ++ ;
}
if ( V_130 && V_131 ) {
F_59 ( L_32 ) ;
return - V_98 ;
}
V_7 -> V_136 = V_131 > 0 ;
if ( V_7 -> type == V_125 && ! V_7 -> V_136 ) {
F_59 ( L_33 ) ;
return - V_98 ;
}
return 0 ;
}
enum V_120 F_85 ( struct V_6 * V_7 )
{
return V_7 -> type ;
}
struct V_138 * F_86 ( struct V_6 * V_7 )
{
return V_7 -> V_103 ;
}
struct V_21 * F_87 ( struct V_6 * V_7 )
{
if ( V_7 -> V_28 > 1 ||
! F_63 ( V_7 -> V_26 [ 0 ] . type ) )
return NULL ;
return V_7 -> V_26 ;
}
struct V_21 * F_88 ( struct V_6 * V_7 )
{
struct V_21 * V_50 ;
unsigned V_43 ;
for ( V_43 = 0 ; V_43 < F_55 ( V_7 ) ; V_43 ++ ) {
V_50 = F_56 ( V_7 , V_43 ) ;
if ( F_89 ( V_50 -> type ) )
return V_50 ;
}
return NULL ;
}
bool F_90 ( struct V_6 * V_7 )
{
return F_70 ( F_85 ( V_7 ) ) ;
}
bool F_91 ( struct V_6 * V_7 )
{
return F_71 ( F_85 ( V_7 ) ) ;
}
bool F_92 ( struct V_6 * V_7 )
{
return V_7 -> V_136 ;
}
static int F_93 ( struct V_6 * V_7 , struct V_29 * V_30 )
{
enum V_120 type = F_85 ( V_7 ) ;
unsigned V_139 = 0 ;
struct V_21 * V_44 ;
unsigned V_43 ;
if ( F_45 ( type == V_34 ) ) {
F_19 ( L_34 ) ;
return - V_98 ;
}
if ( F_70 ( type ) )
for ( V_43 = 0 ; V_43 < V_7 -> V_28 ; V_43 ++ ) {
V_44 = V_7 -> V_26 + V_43 ;
V_139 = V_117 ( V_139 , V_44 -> V_139 ) ;
}
V_7 -> V_46 = F_94 ( V_30 , type , V_7 -> V_140 , V_139 ) ;
if ( ! V_7 -> V_46 )
return - V_23 ;
return 0 ;
}
void F_95 ( struct V_6 * V_7 )
{
F_24 ( V_7 -> V_46 ) ;
V_7 -> V_46 = NULL ;
}
struct V_141 * F_96 ( struct V_6 * V_7 )
{
return V_7 -> V_46 ;
}
static int F_97 ( struct V_6 * V_7 )
{
int V_43 ;
unsigned int V_142 = 0 ;
T_1 * V_143 ;
for ( V_43 = V_7 -> V_11 - 2 ; V_43 >= 0 ; V_43 -- ) {
V_7 -> V_12 [ V_43 ] = F_2 ( V_7 -> V_12 [ V_43 + 1 ] , V_5 ) ;
V_142 += V_7 -> V_12 [ V_43 ] ;
}
V_143 = ( T_1 * ) F_7 ( V_142 , ( unsigned long ) V_144 ) ;
if ( ! V_143 )
return - V_23 ;
for ( V_43 = V_7 -> V_11 - 2 ; V_43 >= 0 ; V_43 -- ) {
V_7 -> V_9 [ V_43 ] = V_143 ;
V_143 += ( V_10 * V_7 -> V_12 [ V_43 ] ) ;
F_6 ( V_43 , V_7 ) ;
}
return 0 ;
}
static int F_98 ( struct V_6 * V_7 )
{
int V_69 = 0 ;
unsigned int V_145 ;
V_145 = F_2 ( V_7 -> V_28 , V_10 ) ;
V_7 -> V_11 = 1 + F_1 ( V_145 , V_5 ) ;
V_7 -> V_12 [ V_7 -> V_11 - 1 ] = V_145 ;
V_7 -> V_9 [ V_7 -> V_11 - 1 ] = V_7 -> V_24 ;
if ( V_7 -> V_11 >= 2 )
V_69 = F_97 ( V_7 ) ;
return V_69 ;
}
static bool F_99 ( struct V_146 * V_147 )
{
return ! ! F_100 ( V_147 ) ;
}
static struct V_146 * F_101 ( struct V_6 * V_7 )
{
struct V_35 * V_32 = F_77 ( V_7 ) ;
struct V_38 * V_39 = NULL ;
struct V_146 * V_148 = NULL , * V_149 = NULL ;
unsigned V_43 ;
for ( V_43 = 0 ; V_43 < F_55 ( V_7 ) ; V_43 ++ ) {
struct V_21 * V_50 = F_56 ( V_7 , V_43 ) ;
if ( ! F_102 ( V_50 -> type ) )
goto V_150;
}
F_26 (dd, devices, list) {
V_149 = V_39 -> V_41 -> V_48 -> V_151 ;
if ( ! F_99 ( V_149 ) )
goto V_150;
else if ( V_148 &&
F_103 ( V_148 , V_149 ) < 0 )
goto V_150;
V_148 = V_149 ;
}
return V_149 ;
V_150:
if ( V_148 )
F_19 ( L_35 ,
F_20 ( V_7 -> V_30 ) ,
V_148 -> V_152 ,
V_149 -> V_152 ) ;
return NULL ;
}
static int F_104 ( struct V_6 * V_7 )
{
struct V_29 * V_30 = V_7 -> V_30 ;
struct V_146 * V_149 = NULL ;
if ( V_7 -> V_104 )
return 0 ;
V_149 = F_101 ( V_7 ) ;
if ( ! V_149 )
return 0 ;
if ( ! F_99 ( F_105 ( V_30 ) ) ) {
V_7 -> V_140 = true ;
F_106 ( F_105 ( V_30 ) ,
F_100 ( V_149 ) ) ;
return 0 ;
}
if ( F_103 ( F_105 ( V_30 ) , V_149 ) < 0 ) {
F_19 ( L_36
L_37 ,
F_20 ( V_7 -> V_30 ) ,
V_149 -> V_152 ) ;
return 1 ;
}
V_7 -> V_140 = true ;
return 0 ;
}
int F_107 ( struct V_6 * V_7 )
{
int V_69 ;
V_69 = F_76 ( V_7 ) ;
if ( V_69 ) {
F_59 ( L_38 ) ;
return V_69 ;
}
V_69 = F_98 ( V_7 ) ;
if ( V_69 ) {
F_59 ( L_39 ) ;
return V_69 ;
}
V_69 = F_104 ( V_7 ) ;
if ( V_69 ) {
F_59 ( L_40 ) ;
return V_69 ;
}
V_69 = F_93 ( V_7 , V_7 -> V_30 ) ;
if ( V_69 )
F_59 ( L_41 ) ;
return V_69 ;
}
void F_108 ( struct V_6 * V_7 ,
void (* F_109)( void * ) , void * V_153 )
{
F_110 ( & V_154 ) ;
V_7 -> V_155 = F_109 ;
V_7 -> V_156 = V_153 ;
F_111 ( & V_154 ) ;
}
void F_112 ( struct V_6 * V_7 )
{
F_39 ( F_113 () ) ;
F_110 ( & V_154 ) ;
if ( V_7 -> V_155 )
V_7 -> V_155 ( V_7 -> V_156 ) ;
F_111 ( & V_154 ) ;
}
T_1 F_114 ( struct V_6 * V_7 )
{
return V_7 -> V_28 ? ( V_7 -> V_24 [ V_7 -> V_28 - 1 ] + 1 ) : 0 ;
}
struct V_21 * F_56 ( struct V_6 * V_7 , unsigned int V_9 )
{
if ( V_9 >= V_7 -> V_28 )
return NULL ;
return V_7 -> V_26 + V_9 ;
}
struct V_21 * F_115 ( struct V_6 * V_7 , T_1 V_157 )
{
unsigned int V_8 , V_1 = 0 , V_4 = 0 ;
T_1 * V_13 ;
for ( V_8 = 0 ; V_8 < V_7 -> V_11 ; V_8 ++ ) {
V_1 = F_3 ( V_1 , V_4 ) ;
V_13 = F_4 ( V_7 , V_8 , V_1 ) ;
for ( V_4 = 0 ; V_4 < V_10 ; V_4 ++ )
if ( V_13 [ V_4 ] >= V_157 )
break;
}
return & V_7 -> V_26 [ ( V_10 * V_1 ) + V_4 ] ;
}
static int F_116 ( struct V_21 * V_50 , struct V_41 * V_47 ,
T_1 V_51 , T_1 V_52 , void * V_53 )
{
unsigned * V_158 = V_53 ;
( * V_158 ) ++ ;
return 0 ;
}
bool F_117 ( struct V_6 * V_67 )
{
struct V_21 * V_50 ;
unsigned V_43 , V_158 ;
for ( V_43 = 0 ; V_43 < F_55 ( V_67 ) ; V_43 ++ ) {
V_50 = F_56 ( V_67 , V_43 ) ;
if ( ! V_50 -> type -> V_97 )
return false ;
V_158 = 0 ;
V_50 -> type -> V_97 ( V_50 , F_116 , & V_158 ) ;
if ( V_158 )
return false ;
}
return true ;
}
int F_118 ( struct V_6 * V_67 ,
struct V_56 * V_57 )
{
struct V_21 * V_50 ;
struct V_56 V_96 ;
unsigned V_43 ;
F_57 ( V_57 ) ;
for ( V_43 = 0 ; V_43 < F_55 ( V_67 ) ; V_43 ++ ) {
F_57 ( & V_96 ) ;
V_50 = F_56 ( V_67 , V_43 ) ;
if ( ! V_50 -> type -> V_97 )
goto V_159;
V_50 -> type -> V_97 ( V_50 , F_44 ,
& V_96 ) ;
if ( V_50 -> type -> V_160 )
V_50 -> type -> V_160 ( V_50 , & V_96 ) ;
if ( V_50 -> type -> V_97 ( V_50 , F_27 ,
& V_96 ) )
return - V_98 ;
V_159:
if ( F_119 ( V_57 , & V_96 , 0 ) < 0 )
F_19 ( L_42
L_43
L_44 ,
F_20 ( V_67 -> V_30 ) ,
( unsigned long long ) V_50 -> V_80 ,
( unsigned long long ) V_50 -> V_52 ) ;
}
return F_54 ( V_67 , V_57 ) ;
}
static void F_120 ( struct V_6 * V_7 )
{
struct V_146 * V_149 = NULL ;
if ( V_7 -> V_104 )
return;
if ( V_7 -> V_140 ) {
V_149 = F_101 ( V_7 ) ;
if ( V_149 &&
F_103 ( F_105 ( V_7 -> V_30 ) , V_149 ) >= 0 )
return;
}
if ( F_99 ( F_105 ( V_7 -> V_30 ) ) ) {
F_19 ( L_45 ,
F_20 ( V_7 -> V_30 ) ) ;
F_121 ( F_105 ( V_7 -> V_30 ) ) ;
}
}
static int F_122 ( struct V_21 * V_50 , struct V_41 * V_47 ,
T_1 V_51 , T_1 V_52 , void * V_53 )
{
unsigned long V_161 = ( unsigned long ) V_53 ;
struct V_54 * V_55 = F_29 ( V_47 -> V_48 ) ;
return V_55 && ( V_55 -> V_162 & V_161 ) ;
}
static bool F_123 ( struct V_6 * V_7 , unsigned long V_161 )
{
struct V_21 * V_50 ;
unsigned V_43 ;
for ( V_43 = 0 ; V_43 < F_55 ( V_7 ) ; V_43 ++ ) {
V_50 = F_56 ( V_7 , V_43 ) ;
if ( ! V_50 -> V_163 )
continue;
if ( V_50 -> V_164 )
return true ;
if ( V_50 -> type -> V_97 &&
V_50 -> type -> V_97 ( V_50 , F_122 , ( void * ) V_161 ) )
return true ;
}
return false ;
}
static int F_124 ( struct V_21 * V_50 , struct V_41 * V_47 ,
T_1 V_51 , T_1 V_52 , void * V_53 )
{
struct V_54 * V_55 = F_29 ( V_47 -> V_48 ) ;
return V_55 && F_125 ( V_55 ) ;
}
static int F_126 ( struct V_21 * V_50 , struct V_41 * V_47 ,
T_1 V_51 , T_1 V_52 , void * V_53 )
{
struct V_54 * V_55 = F_29 ( V_47 -> V_48 ) ;
return V_55 && ! F_127 ( V_55 ) ;
}
static int F_128 ( struct V_21 * V_50 , struct V_41 * V_47 ,
T_1 V_51 , T_1 V_52 , void * V_53 )
{
struct V_54 * V_55 = F_29 ( V_47 -> V_48 ) ;
return V_55 && ! F_129 ( V_165 , & V_55 -> V_162 ) ;
}
static bool F_130 ( struct V_6 * V_7 ,
T_5 V_166 )
{
struct V_21 * V_50 ;
unsigned V_43 ;
for ( V_43 = 0 ; V_43 < F_55 ( V_7 ) ; V_43 ++ ) {
V_50 = F_56 ( V_7 , V_43 ) ;
if ( ! V_50 -> type -> V_97 ||
! V_50 -> type -> V_97 ( V_50 , V_166 , NULL ) )
return false ;
}
return true ;
}
static int F_131 ( struct V_21 * V_50 , struct V_41 * V_47 ,
T_1 V_51 , T_1 V_52 , void * V_53 )
{
struct V_54 * V_55 = F_29 ( V_47 -> V_48 ) ;
return V_55 && ! V_55 -> V_57 . V_167 ;
}
static bool F_132 ( struct V_6 * V_7 )
{
struct V_21 * V_50 ;
unsigned V_43 ;
for ( V_43 = 0 ; V_43 < F_55 ( V_7 ) ; V_43 ++ ) {
V_50 = F_56 ( V_7 , V_43 ) ;
if ( ! V_50 -> V_168 )
return false ;
if ( ! V_50 -> type -> V_97 ||
V_50 -> type -> V_97 ( V_50 , F_131 , NULL ) )
return false ;
}
return true ;
}
static int F_133 ( struct V_21 * V_50 , struct V_41 * V_47 ,
T_1 V_51 , T_1 V_52 , void * V_53 )
{
struct V_54 * V_55 = F_29 ( V_47 -> V_48 ) ;
return V_55 && ! V_55 -> V_57 . V_169 ;
}
static bool F_134 ( struct V_6 * V_7 )
{
struct V_21 * V_50 ;
unsigned V_43 = 0 ;
while ( V_43 < F_55 ( V_7 ) ) {
V_50 = F_56 ( V_7 , V_43 ++ ) ;
if ( ! V_50 -> V_170 )
return false ;
if ( ! V_50 -> type -> V_97 ||
V_50 -> type -> V_97 ( V_50 , F_133 , NULL ) )
return false ;
}
return true ;
}
static int F_135 ( struct V_21 * V_50 , struct V_41 * V_47 ,
T_1 V_51 , T_1 V_52 , void * V_53 )
{
struct V_54 * V_55 = F_29 ( V_47 -> V_48 ) ;
return V_55 && F_136 ( V_55 ) ;
}
static bool F_137 ( struct V_6 * V_7 )
{
struct V_21 * V_50 ;
unsigned V_43 ;
for ( V_43 = 0 ; V_43 < F_55 ( V_7 ) ; V_43 ++ ) {
V_50 = F_56 ( V_7 , V_43 ) ;
if ( ! V_50 -> V_106 )
continue;
if ( V_50 -> V_107 )
return true ;
if ( V_50 -> type -> V_97 &&
V_50 -> type -> V_97 ( V_50 , F_135 , NULL ) )
return true ;
}
return false ;
}
void F_138 ( struct V_6 * V_7 , struct V_54 * V_55 ,
struct V_56 * V_57 )
{
bool V_171 = false , V_172 = false ;
V_55 -> V_57 = * V_57 ;
if ( ! F_137 ( V_7 ) )
F_139 ( V_173 , V_55 ) ;
else
F_140 ( V_173 , V_55 ) ;
if ( F_123 ( V_7 , ( 1UL << V_174 ) ) ) {
V_171 = true ;
if ( F_123 ( V_7 , ( 1UL << V_175 ) ) )
V_172 = true ;
}
F_141 ( V_55 , V_171 , V_172 ) ;
if ( F_130 ( V_7 , F_124 ) )
F_140 ( V_176 , V_55 ) ;
else
F_139 ( V_176 , V_55 ) ;
if ( ! F_132 ( V_7 ) )
V_55 -> V_57 . V_167 = 0 ;
if ( ! F_134 ( V_7 ) )
V_55 -> V_57 . V_169 = 0 ;
if ( F_130 ( V_7 , F_128 ) )
F_139 ( V_165 , V_55 ) ;
else
F_140 ( V_165 , V_55 ) ;
F_120 ( V_7 ) ;
if ( F_127 ( V_55 ) && F_130 ( V_7 , F_126 ) )
F_139 ( V_177 , V_55 ) ;
F_142 () ;
if ( F_91 ( V_7 ) )
F_140 ( V_178 , V_55 ) ;
}
unsigned int F_55 ( struct V_6 * V_7 )
{
return V_7 -> V_28 ;
}
struct V_35 * F_77 ( struct V_6 * V_7 )
{
return & V_7 -> V_32 ;
}
T_2 F_143 ( struct V_6 * V_7 )
{
return V_7 -> V_27 ;
}
static void F_144 ( struct V_6 * V_7 , enum V_179 V_27 )
{
int V_43 = V_7 -> V_28 ;
struct V_21 * V_50 = V_7 -> V_26 ;
F_145 ( & V_7 -> V_30 -> V_180 ) ;
while ( V_43 -- ) {
switch ( V_27 ) {
case V_181 :
if ( V_50 -> type -> V_182 )
V_50 -> type -> V_182 ( V_50 ) ;
break;
case V_183 :
if ( V_50 -> type -> V_184 )
V_50 -> type -> V_184 ( V_50 ) ;
break;
case V_185 :
if ( V_50 -> type -> V_186 )
V_50 -> type -> V_186 ( V_50 ) ;
break;
}
V_50 ++ ;
}
}
void F_146 ( struct V_6 * V_7 )
{
if ( ! V_7 )
return;
F_144 ( V_7 , V_181 ) ;
}
void F_147 ( struct V_6 * V_7 )
{
if ( ! V_7 )
return;
F_144 ( V_7 , V_183 ) ;
}
void F_148 ( struct V_6 * V_7 )
{
if ( ! V_7 )
return;
F_144 ( V_7 , V_185 ) ;
}
int F_149 ( struct V_6 * V_7 )
{
int V_43 , V_69 = 0 ;
F_145 ( & V_7 -> V_30 -> V_180 ) ;
for ( V_43 = 0 ; V_43 < V_7 -> V_28 ; V_43 ++ ) {
struct V_21 * V_50 = V_7 -> V_26 + V_43 ;
if ( ! V_50 -> type -> V_187 )
continue;
V_69 = V_50 -> type -> V_187 ( V_50 ) ;
if ( V_69 ) {
F_59 ( L_46 ,
F_20 ( V_7 -> V_30 ) , V_50 -> type -> V_42 , V_69 ) ;
return V_69 ;
}
}
for ( V_43 = 0 ; V_43 < V_7 -> V_28 ; V_43 ++ ) {
struct V_21 * V_50 = V_7 -> V_26 + V_43 ;
if ( V_50 -> type -> V_188 )
V_50 -> type -> V_188 ( V_50 ) ;
}
return 0 ;
}
void F_150 ( struct V_6 * V_7 , struct V_189 * V_190 )
{
F_42 ( & V_190 -> V_40 , & V_7 -> V_33 ) ;
}
int F_151 ( struct V_6 * V_7 , int V_191 )
{
struct V_38 * V_39 ;
struct V_35 * V_32 = F_77 ( V_7 ) ;
struct V_189 * V_190 ;
int V_69 = 0 ;
F_26 (dd, devices, list) {
struct V_54 * V_55 = F_29 ( V_39 -> V_41 -> V_48 ) ;
char V_64 [ V_65 ] ;
if ( F_152 ( V_55 ) )
V_69 |= F_153 ( V_55 -> V_192 , V_191 ) ;
else
F_154 ( L_47 ,
F_20 ( V_7 -> V_30 ) ,
F_30 ( V_39 -> V_41 -> V_48 , V_64 ) ) ;
}
F_26 (cb, &t->target_callbacks, list)
if ( V_190 -> V_193 )
V_69 |= V_190 -> V_193 ( V_190 , V_191 ) ;
return V_69 ;
}
struct V_29 * F_155 ( struct V_6 * V_7 )
{
return V_7 -> V_30 ;
}
void F_156 ( struct V_6 * V_7 )
{
struct V_29 * V_30 ;
struct V_54 * V_194 ;
unsigned long V_195 ;
if ( ! F_91 ( V_7 ) )
return;
V_30 = F_155 ( V_7 ) ;
V_194 = F_157 ( V_30 ) ;
if ( V_194 ) {
if ( V_194 -> V_137 )
F_158 ( V_194 , true ) ;
else {
F_159 ( V_194 -> V_196 , V_195 ) ;
F_160 ( V_194 ) ;
F_161 ( V_194 -> V_196 , V_195 ) ;
}
}
}
