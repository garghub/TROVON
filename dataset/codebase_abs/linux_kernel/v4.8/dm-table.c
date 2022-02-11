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
T_3 V_73 ( V_47 ) ;
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
return - V_74 ;
V_39 = F_25 ( & V_7 -> V_32 , V_47 ) ;
if ( ! V_39 ) {
V_39 = F_40 ( sizeof( * V_39 ) , V_31 ) ;
if ( ! V_39 )
return - V_23 ;
if ( ( V_69 = F_32 ( V_7 -> V_30 , V_47 , V_27 , & V_39 -> V_41 ) ) ) {
F_15 ( V_39 ) ;
return V_69 ;
}
F_41 ( & V_39 -> V_75 , 0 ) ;
F_42 ( & V_39 -> V_40 , & V_7 -> V_32 ) ;
} else if ( V_39 -> V_41 -> V_27 != ( V_27 | V_39 -> V_41 -> V_27 ) ) {
V_69 = F_31 ( V_39 , V_27 , V_7 -> V_30 ) ;
if ( V_69 )
return V_69 ;
}
F_43 ( & V_39 -> V_75 ) ;
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
V_55 -> V_57 . V_76 ,
V_55 -> V_57 . V_63 ,
V_55 -> V_57 . V_77 ,
( unsigned long long ) V_51 << V_61 ) ;
return 0 ;
}
void F_47 ( struct V_21 * V_50 , struct V_41 * V_78 )
{
int V_79 = 0 ;
struct V_35 * V_32 = & V_50 -> V_67 -> V_32 ;
struct V_38 * V_39 ;
F_26 (dd, devices, list) {
if ( V_39 -> V_41 == V_78 ) {
V_79 = 1 ;
break;
}
}
if ( ! V_79 ) {
F_19 ( L_12 ,
F_20 ( V_50 -> V_67 -> V_30 ) , V_78 -> V_42 ) ;
return;
}
if ( F_48 ( & V_39 -> V_75 ) ) {
F_21 ( V_50 -> V_67 -> V_30 , V_78 ) ;
F_49 ( & V_39 -> V_40 ) ;
F_15 ( V_39 ) ;
}
}
static int F_50 ( struct V_6 * V_67 , struct V_21 * V_50 )
{
struct V_21 * V_80 ;
if ( ! V_67 -> V_28 )
return ! V_50 -> V_81 ;
V_80 = & V_67 -> V_26 [ V_67 -> V_28 - 1 ] ;
return ( V_50 -> V_81 == ( V_80 -> V_81 + V_80 -> V_52 ) ) ;
}
static char * * F_51 ( unsigned * V_82 , char * * V_83 )
{
char * * V_84 ;
unsigned V_85 ;
T_4 V_86 ;
if ( * V_82 ) {
V_85 = * V_82 * 2 ;
V_86 = V_31 ;
} else {
V_85 = 8 ;
V_86 = V_87 ;
}
V_84 = F_40 ( V_85 * sizeof( * V_84 ) , V_86 ) ;
if ( V_84 ) {
memcpy ( V_84 , V_83 , * V_82 * sizeof( * V_84 ) ) ;
* V_82 = V_85 ;
}
F_15 ( V_83 ) ;
return V_84 ;
}
int F_52 ( int * V_88 , char * * * V_89 , char * V_90 )
{
char * V_51 , * V_91 = V_90 , * V_92 , * * V_84 = NULL ;
unsigned V_82 = 0 ;
* V_88 = 0 ;
if ( ! V_90 ) {
* V_89 = NULL ;
return 0 ;
}
V_84 = F_51 ( & V_82 , V_84 ) ;
if ( ! V_84 )
return - V_23 ;
while ( 1 ) {
V_51 = F_53 ( V_91 ) ;
if ( ! * V_51 )
break;
V_91 = V_92 = V_51 ;
while ( * V_91 ) {
if ( * V_91 == '\\' && * ( V_91 + 1 ) ) {
* V_92 ++ = * ( V_91 + 1 ) ;
V_91 += 2 ;
continue;
}
if ( isspace ( * V_91 ) )
break;
* V_92 ++ = * V_91 ++ ;
}
if ( ( * V_88 + 1 ) > V_82 ) {
V_84 = F_51 ( & V_82 , V_84 ) ;
if ( ! V_84 )
return - V_23 ;
}
if ( * V_91 )
V_91 ++ ;
* V_92 = '\0' ;
V_84 [ * V_88 ] = V_51 ;
( * V_88 ) ++ ;
}
* V_89 = V_84 ;
return 0 ;
}
static int F_54 ( struct V_6 * V_67 ,
struct V_56 * V_57 )
{
unsigned short V_93 =
V_57 -> V_63 >> V_61 ;
unsigned short V_94 = 0 ;
unsigned short V_95 = 0 ;
struct V_21 * V_73 ( V_50 ) ;
struct V_56 V_96 ;
unsigned V_43 = 0 ;
while ( V_43 < F_55 ( V_67 ) ) {
V_50 = F_56 ( V_67 , V_43 ++ ) ;
F_57 ( & V_96 ) ;
if ( V_50 -> type -> V_97 )
V_50 -> type -> V_97 ( V_50 , F_44 ,
& V_96 ) ;
if ( V_95 < V_50 -> V_52 &&
V_95 & ( ( V_96 . V_63 >>
V_61 ) - 1 ) )
break;
V_94 =
( unsigned short ) ( ( V_94 + V_50 -> V_52 ) &
( V_93 - 1 ) ) ;
V_95 = V_94 ?
V_93 - V_94 : 0 ;
}
if ( V_95 ) {
F_19 ( L_13
L_14 ,
F_20 ( V_67 -> V_30 ) , V_43 ,
( unsigned long long ) V_50 -> V_81 ,
( unsigned long long ) V_50 -> V_52 ,
V_57 -> V_63 ) ;
return - V_98 ;
}
return 0 ;
}
int F_58 ( struct V_6 * V_7 , const char * type ,
T_1 V_51 , T_1 V_52 , char * V_99 )
{
int V_69 = - V_98 , V_88 ;
char * * V_84 ;
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
F_59 ( L_17 , F_20 ( V_7 -> V_30 ) ,
type ) ;
return - V_98 ;
}
if ( F_61 ( V_44 -> type ) ) {
if ( V_7 -> V_28 ) {
F_59 ( L_15 ,
F_20 ( V_7 -> V_30 ) , type ) ;
return - V_98 ;
}
V_7 -> V_100 = true ;
}
if ( F_62 ( V_44 -> type ) && ! ( V_7 -> V_27 & V_101 ) ) {
F_59 ( L_18 ,
F_20 ( V_7 -> V_30 ) , type ) ;
return - V_98 ;
}
if ( V_7 -> V_102 ) {
if ( V_7 -> V_102 != V_44 -> type ) {
F_59 ( L_19 ,
F_20 ( V_7 -> V_30 ) , V_7 -> V_102 -> V_42 ) ;
return - V_98 ;
}
} else if ( F_63 ( V_44 -> type ) ) {
if ( V_7 -> V_28 ) {
F_59 ( L_19 ,
F_20 ( V_7 -> V_30 ) , V_44 -> type -> V_42 ) ;
return - V_98 ;
}
V_7 -> V_102 = V_44 -> type ;
}
V_44 -> V_67 = V_7 ;
V_44 -> V_81 = V_51 ;
V_44 -> V_52 = V_52 ;
V_44 -> error = L_20 ;
if ( ! F_50 ( V_7 , V_44 ) ) {
V_44 -> error = L_21 ;
V_69 = - V_98 ;
goto V_103;
}
V_69 = F_52 ( & V_88 , & V_84 , V_99 ) ;
if ( V_69 ) {
V_44 -> error = L_22 ;
goto V_103;
}
V_69 = V_44 -> type -> V_104 ( V_44 , V_88 , V_84 ) ;
F_15 ( V_84 ) ;
if ( V_69 )
goto V_103;
V_7 -> V_24 [ V_7 -> V_28 ++ ] = V_44 -> V_81 + V_44 -> V_52 - 1 ;
if ( ! V_44 -> V_105 && V_44 -> V_106 )
F_19 ( L_23 ,
F_20 ( V_7 -> V_30 ) , type ) ;
return 0 ;
V_103:
F_59 ( L_24 , F_20 ( V_7 -> V_30 ) , type , V_44 -> error ) ;
F_23 ( V_44 -> type ) ;
return V_69 ;
}
static int F_64 ( struct V_107 * V_108 , struct V_109 * V_110 ,
unsigned * V_111 , char * * error , unsigned V_112 )
{
const char * V_113 = F_65 ( V_110 ) ;
char V_114 ;
if ( ! V_113 ||
( sscanf ( V_113 , L_25 , V_111 , & V_114 ) != 1 ) ||
( * V_111 < V_108 -> V_115 ) ||
( * V_111 > V_108 -> V_116 ) ||
( V_112 && V_110 -> V_88 < * V_111 ) ) {
* error = V_108 -> error ;
return - V_98 ;
}
return 0 ;
}
int F_66 ( struct V_107 * V_108 , struct V_109 * V_110 ,
unsigned * V_111 , char * * error )
{
return F_64 ( V_108 , V_110 , V_111 , error , 0 ) ;
}
int F_67 ( struct V_107 * V_108 , struct V_109 * V_110 ,
unsigned * V_111 , char * * error )
{
return F_64 ( V_108 , V_110 , V_111 , error , 1 ) ;
}
const char * F_65 ( struct V_109 * V_117 )
{
char * V_69 ;
if ( V_117 -> V_88 ) {
V_117 -> V_88 -- ;
V_69 = * V_117 -> V_84 ;
V_117 -> V_84 ++ ;
return V_69 ;
}
return NULL ;
}
void F_68 ( struct V_109 * V_117 , unsigned V_118 )
{
F_39 ( V_117 -> V_88 < V_118 ) ;
V_117 -> V_88 -= V_118 ;
V_117 -> V_84 += V_118 ;
}
static bool F_69 ( unsigned V_119 )
{
return ( V_119 == V_120 ||
V_119 == V_121 ) ;
}
static bool F_70 ( unsigned V_119 )
{
return ( V_119 == V_122 ||
V_119 == V_123 ) ;
}
void F_71 ( struct V_6 * V_7 , unsigned type )
{
V_7 -> type = type ;
}
static int F_72 ( struct V_21 * V_50 , struct V_41 * V_47 ,
T_1 V_51 , T_1 V_52 , void * V_53 )
{
struct V_54 * V_55 = F_29 ( V_47 -> V_48 ) ;
return V_55 && F_73 ( V_55 ) ;
}
static bool F_74 ( struct V_6 * V_7 )
{
struct V_21 * V_50 ;
unsigned V_43 = 0 ;
while ( V_43 < F_55 ( V_7 ) ) {
V_50 = F_56 ( V_7 , V_43 ++ ) ;
if ( ! V_50 -> type -> V_124 )
return false ;
if ( ! V_50 -> type -> V_97 ||
! V_50 -> type -> V_97 ( V_50 , F_72 , NULL ) )
return false ;
}
return true ;
}
static int F_75 ( struct V_6 * V_7 )
{
unsigned V_43 ;
unsigned V_125 = 0 , V_126 = 0 , V_127 = 0 ;
bool V_128 = false ;
struct V_21 * V_44 ;
struct V_38 * V_39 ;
struct V_35 * V_32 = F_76 ( V_7 ) ;
unsigned V_129 = F_77 ( V_7 -> V_30 ) ;
if ( V_7 -> type != V_34 ) {
if ( V_7 -> type == V_120 )
return 0 ;
F_39 ( V_7 -> type == V_121 ) ;
goto V_130;
}
for ( V_43 = 0 ; V_43 < V_7 -> V_28 ; V_43 ++ ) {
V_44 = V_7 -> V_26 + V_43 ;
if ( F_78 ( V_44 ) )
V_127 = 1 ;
else if ( F_79 ( V_44 ) )
V_126 = 1 ;
else
V_125 = 1 ;
if ( V_125 && V_126 ) {
F_19 ( L_26
L_27 ) ;
return - V_98 ;
}
}
if ( V_127 && ! V_125 && ! V_126 ) {
if ( F_70 ( V_129 ) )
V_126 = 1 ;
else
V_125 = 1 ;
}
if ( V_125 ) {
V_7 -> type = V_120 ;
if ( F_74 ( V_7 ) ||
( F_80 ( V_32 ) && V_129 == V_121 ) )
V_7 -> type = V_121 ;
return 0 ;
}
F_39 ( ! V_126 ) ;
if ( F_80 ( V_32 ) && F_70 ( V_129 ) ) {
V_7 -> type = V_129 ;
return 0 ;
}
V_7 -> type = V_122 ;
V_130:
if ( V_7 -> V_28 > 1 ) {
F_19 ( L_28 ) ;
return - V_98 ;
}
F_26 (dd, devices, list) {
struct V_54 * V_55 = F_29 ( V_39 -> V_41 -> V_48 ) ;
if ( ! F_81 ( V_55 ) ) {
F_59 ( L_29
L_30 ) ;
return - V_98 ;
}
if ( V_55 -> V_131 )
V_128 = true ;
}
if ( V_128 ) {
F_26 (dd, devices, list)
if ( ! F_29 ( V_39 -> V_41 -> V_48 ) -> V_131 ) {
F_59 ( L_31
L_32 ) ;
return - V_98 ;
}
V_7 -> V_132 = true ;
}
return 0 ;
}
unsigned F_82 ( struct V_6 * V_7 )
{
return V_7 -> type ;
}
struct V_133 * F_83 ( struct V_6 * V_7 )
{
return V_7 -> V_102 ;
}
struct V_21 * F_84 ( struct V_6 * V_7 )
{
if ( V_7 -> V_28 > 1 ||
! F_63 ( V_7 -> V_26 [ 0 ] . type ) )
return NULL ;
return V_7 -> V_26 ;
}
struct V_21 * F_85 ( struct V_6 * V_7 )
{
struct V_21 * V_73 ( V_50 ) ;
unsigned V_43 = 0 ;
while ( V_43 < F_55 ( V_7 ) ) {
V_50 = F_56 ( V_7 , V_43 ++ ) ;
if ( F_86 ( V_50 -> type ) )
return V_50 ;
}
return NULL ;
}
bool F_87 ( struct V_6 * V_7 )
{
return F_69 ( F_82 ( V_7 ) ) ;
}
bool F_88 ( struct V_6 * V_7 )
{
return F_70 ( F_82 ( V_7 ) ) ;
}
bool F_89 ( struct V_6 * V_7 )
{
return V_7 -> V_132 ;
}
static int F_90 ( struct V_6 * V_7 , struct V_29 * V_30 )
{
unsigned type = F_82 ( V_7 ) ;
unsigned V_134 = 0 ;
struct V_21 * V_44 ;
unsigned V_43 ;
if ( F_45 ( type == V_34 ) ) {
F_19 ( L_33 ) ;
return - V_98 ;
}
if ( F_69 ( type ) )
for ( V_43 = 0 ; V_43 < V_7 -> V_28 ; V_43 ++ ) {
V_44 = V_7 -> V_26 + V_43 ;
V_134 = V_116 ( V_134 , V_44 -> V_134 ) ;
}
V_7 -> V_46 = F_91 ( V_30 , type , V_7 -> V_135 , V_134 ) ;
if ( ! V_7 -> V_46 )
return - V_23 ;
return 0 ;
}
void F_92 ( struct V_6 * V_7 )
{
F_24 ( V_7 -> V_46 ) ;
V_7 -> V_46 = NULL ;
}
struct V_136 * F_93 ( struct V_6 * V_7 )
{
return V_7 -> V_46 ;
}
static int F_94 ( struct V_6 * V_7 )
{
int V_43 ;
unsigned int V_137 = 0 ;
T_1 * V_138 ;
for ( V_43 = V_7 -> V_11 - 2 ; V_43 >= 0 ; V_43 -- ) {
V_7 -> V_12 [ V_43 ] = F_2 ( V_7 -> V_12 [ V_43 + 1 ] , V_5 ) ;
V_137 += V_7 -> V_12 [ V_43 ] ;
}
V_138 = ( T_1 * ) F_7 ( V_137 , ( unsigned long ) V_139 ) ;
if ( ! V_138 )
return - V_23 ;
for ( V_43 = V_7 -> V_11 - 2 ; V_43 >= 0 ; V_43 -- ) {
V_7 -> V_9 [ V_43 ] = V_138 ;
V_138 += ( V_10 * V_7 -> V_12 [ V_43 ] ) ;
F_6 ( V_43 , V_7 ) ;
}
return 0 ;
}
static int F_95 ( struct V_6 * V_7 )
{
int V_69 = 0 ;
unsigned int V_140 ;
V_140 = F_2 ( V_7 -> V_28 , V_10 ) ;
V_7 -> V_11 = 1 + F_1 ( V_140 , V_5 ) ;
V_7 -> V_12 [ V_7 -> V_11 - 1 ] = V_140 ;
V_7 -> V_9 [ V_7 -> V_11 - 1 ] = V_7 -> V_24 ;
if ( V_7 -> V_11 >= 2 )
V_69 = F_94 ( V_7 ) ;
return V_69 ;
}
static bool F_96 ( struct V_141 * V_142 )
{
return ! ! F_97 ( V_142 ) ;
}
static struct V_141 * F_98 ( struct V_6 * V_7 )
{
struct V_35 * V_32 = F_76 ( V_7 ) ;
struct V_38 * V_39 = NULL ;
struct V_141 * V_143 = NULL , * V_144 = NULL ;
F_26 (dd, devices, list) {
V_144 = V_39 -> V_41 -> V_48 -> V_145 ;
if ( ! F_96 ( V_144 ) )
goto V_146;
else if ( V_143 &&
F_99 ( V_143 , V_144 ) < 0 )
goto V_146;
V_143 = V_144 ;
}
return V_144 ;
V_146:
if ( V_143 )
F_19 ( L_34 ,
F_20 ( V_7 -> V_30 ) ,
V_143 -> V_147 ,
V_144 -> V_147 ) ;
return NULL ;
}
static int F_100 ( struct V_6 * V_7 )
{
struct V_29 * V_30 = V_7 -> V_30 ;
struct V_141 * V_144 = NULL ;
V_144 = F_98 ( V_7 ) ;
if ( ! V_144 )
return 0 ;
if ( ! F_96 ( F_101 ( V_30 ) ) ) {
V_7 -> V_135 = true ;
F_102 ( F_101 ( V_30 ) ,
F_97 ( V_144 ) ) ;
return 0 ;
}
if ( F_99 ( F_101 ( V_30 ) , V_144 ) < 0 ) {
F_19 ( L_35
L_36 ,
F_20 ( V_7 -> V_30 ) ,
V_144 -> V_147 ) ;
return 1 ;
}
V_7 -> V_135 = true ;
return 0 ;
}
int F_103 ( struct V_6 * V_7 )
{
int V_69 ;
V_69 = F_75 ( V_7 ) ;
if ( V_69 ) {
F_59 ( L_37 ) ;
return V_69 ;
}
V_69 = F_95 ( V_7 ) ;
if ( V_69 ) {
F_59 ( L_38 ) ;
return V_69 ;
}
V_69 = F_100 ( V_7 ) ;
if ( V_69 ) {
F_59 ( L_39 ) ;
return V_69 ;
}
V_69 = F_90 ( V_7 , V_7 -> V_30 ) ;
if ( V_69 )
F_59 ( L_40 ) ;
return V_69 ;
}
void F_104 ( struct V_6 * V_7 ,
void (* F_105)( void * ) , void * V_148 )
{
F_106 ( & V_149 ) ;
V_7 -> V_150 = F_105 ;
V_7 -> V_151 = V_148 ;
F_107 ( & V_149 ) ;
}
void F_108 ( struct V_6 * V_7 )
{
F_39 ( F_109 () ) ;
F_106 ( & V_149 ) ;
if ( V_7 -> V_150 )
V_7 -> V_150 ( V_7 -> V_151 ) ;
F_107 ( & V_149 ) ;
}
T_1 F_110 ( struct V_6 * V_7 )
{
return V_7 -> V_28 ? ( V_7 -> V_24 [ V_7 -> V_28 - 1 ] + 1 ) : 0 ;
}
struct V_21 * F_56 ( struct V_6 * V_7 , unsigned int V_9 )
{
if ( V_9 >= V_7 -> V_28 )
return NULL ;
return V_7 -> V_26 + V_9 ;
}
struct V_21 * F_111 ( struct V_6 * V_7 , T_1 V_152 )
{
unsigned int V_8 , V_1 = 0 , V_4 = 0 ;
T_1 * V_13 ;
for ( V_8 = 0 ; V_8 < V_7 -> V_11 ; V_8 ++ ) {
V_1 = F_3 ( V_1 , V_4 ) ;
V_13 = F_4 ( V_7 , V_8 , V_1 ) ;
for ( V_4 = 0 ; V_4 < V_10 ; V_4 ++ )
if ( V_13 [ V_4 ] >= V_152 )
break;
}
return & V_7 -> V_26 [ ( V_10 * V_1 ) + V_4 ] ;
}
static int F_112 ( struct V_21 * V_50 , struct V_41 * V_47 ,
T_1 V_51 , T_1 V_52 , void * V_53 )
{
unsigned * V_153 = V_53 ;
( * V_153 ) ++ ;
return 0 ;
}
bool F_113 ( struct V_6 * V_67 )
{
struct V_21 * V_73 ( V_50 ) ;
unsigned V_43 = 0 , V_153 = 0 ;
while ( V_43 < F_55 ( V_67 ) ) {
V_50 = F_56 ( V_67 , V_43 ++ ) ;
if ( ! V_50 -> type -> V_97 )
return false ;
V_50 -> type -> V_97 ( V_50 , F_112 , & V_153 ) ;
if ( V_153 )
return false ;
}
return true ;
}
int F_114 ( struct V_6 * V_67 ,
struct V_56 * V_57 )
{
struct V_21 * V_73 ( V_50 ) ;
struct V_56 V_96 ;
unsigned V_43 = 0 ;
F_57 ( V_57 ) ;
while ( V_43 < F_55 ( V_67 ) ) {
F_57 ( & V_96 ) ;
V_50 = F_56 ( V_67 , V_43 ++ ) ;
if ( ! V_50 -> type -> V_97 )
goto V_154;
V_50 -> type -> V_97 ( V_50 , F_44 ,
& V_96 ) ;
if ( V_50 -> type -> V_155 )
V_50 -> type -> V_155 ( V_50 , & V_96 ) ;
if ( V_50 -> type -> V_97 ( V_50 , F_27 ,
& V_96 ) )
return - V_98 ;
V_154:
if ( F_115 ( V_57 , & V_96 , 0 ) < 0 )
F_19 ( L_41
L_42
L_43 ,
F_20 ( V_67 -> V_30 ) ,
( unsigned long long ) V_50 -> V_81 ,
( unsigned long long ) V_50 -> V_52 ) ;
}
return F_54 ( V_67 , V_57 ) ;
}
static void F_116 ( struct V_6 * V_7 )
{
struct V_141 * V_144 = NULL ;
if ( V_7 -> V_135 ) {
V_144 = F_98 ( V_7 ) ;
if ( V_144 &&
F_99 ( F_101 ( V_7 -> V_30 ) , V_144 ) >= 0 )
return;
}
if ( F_96 ( F_101 ( V_7 -> V_30 ) ) ) {
F_19 ( L_44 ,
F_20 ( V_7 -> V_30 ) ) ;
F_117 ( F_101 ( V_7 -> V_30 ) ) ;
}
}
static int F_118 ( struct V_21 * V_50 , struct V_41 * V_47 ,
T_1 V_51 , T_1 V_52 , void * V_53 )
{
unsigned long V_156 = ( unsigned long ) V_53 ;
struct V_54 * V_55 = F_29 ( V_47 -> V_48 ) ;
return V_55 && ( V_55 -> V_157 & V_156 ) ;
}
static bool F_119 ( struct V_6 * V_7 , unsigned long V_156 )
{
struct V_21 * V_50 ;
unsigned V_43 = 0 ;
while ( V_43 < F_55 ( V_7 ) ) {
V_50 = F_56 ( V_7 , V_43 ++ ) ;
if ( ! V_50 -> V_158 )
continue;
if ( V_50 -> V_159 )
return true ;
if ( V_50 -> type -> V_97 &&
V_50 -> type -> V_97 ( V_50 , F_118 , ( void * ) V_156 ) )
return true ;
}
return false ;
}
static bool F_120 ( struct V_6 * V_7 )
{
struct V_21 * V_50 ;
unsigned V_43 = 0 ;
while ( V_43 < F_55 ( V_7 ) ) {
V_50 = F_56 ( V_7 , V_43 ++ ) ;
if ( V_50 -> V_160 )
return false ;
}
return true ;
}
static int F_121 ( struct V_21 * V_50 , struct V_41 * V_47 ,
T_1 V_51 , T_1 V_52 , void * V_53 )
{
struct V_54 * V_55 = F_29 ( V_47 -> V_48 ) ;
return V_55 && F_122 ( V_55 ) ;
}
static int F_123 ( struct V_21 * V_50 , struct V_41 * V_47 ,
T_1 V_51 , T_1 V_52 , void * V_53 )
{
struct V_54 * V_55 = F_29 ( V_47 -> V_48 ) ;
return V_55 && ! F_124 ( V_55 ) ;
}
static int F_125 ( struct V_21 * V_50 , struct V_41 * V_47 ,
T_1 V_51 , T_1 V_52 , void * V_53 )
{
struct V_54 * V_55 = F_29 ( V_47 -> V_48 ) ;
return V_55 && ! F_126 ( V_161 , & V_55 -> V_157 ) ;
}
static bool F_127 ( struct V_6 * V_7 ,
T_5 V_162 )
{
struct V_21 * V_50 ;
unsigned V_43 = 0 ;
while ( V_43 < F_55 ( V_7 ) ) {
V_50 = F_56 ( V_7 , V_43 ++ ) ;
if ( ! V_50 -> type -> V_97 ||
! V_50 -> type -> V_97 ( V_50 , V_162 , NULL ) )
return false ;
}
return true ;
}
static int F_128 ( struct V_21 * V_50 , struct V_41 * V_47 ,
T_1 V_51 , T_1 V_52 , void * V_53 )
{
struct V_54 * V_55 = F_29 ( V_47 -> V_48 ) ;
return V_55 && ! V_55 -> V_57 . V_163 ;
}
static bool F_129 ( struct V_6 * V_7 )
{
struct V_21 * V_50 ;
unsigned V_43 = 0 ;
while ( V_43 < F_55 ( V_7 ) ) {
V_50 = F_56 ( V_7 , V_43 ++ ) ;
if ( ! V_50 -> V_164 )
return false ;
if ( ! V_50 -> type -> V_97 ||
V_50 -> type -> V_97 ( V_50 , F_128 , NULL ) )
return false ;
}
return true ;
}
static int F_130 ( struct V_21 * V_50 , struct V_41 * V_47 ,
T_1 V_51 , T_1 V_52 , void * V_53 )
{
struct V_54 * V_55 = F_29 ( V_47 -> V_48 ) ;
return V_55 && F_131 ( V_55 ) ;
}
static bool F_132 ( struct V_6 * V_7 )
{
struct V_21 * V_50 ;
unsigned V_43 = 0 ;
while ( V_43 < F_55 ( V_7 ) ) {
V_50 = F_56 ( V_7 , V_43 ++ ) ;
if ( ! V_50 -> V_105 )
continue;
if ( V_50 -> V_106 )
return true ;
if ( V_50 -> type -> V_97 &&
V_50 -> type -> V_97 ( V_50 , F_130 , NULL ) )
return true ;
}
return false ;
}
void F_133 ( struct V_6 * V_7 , struct V_54 * V_55 ,
struct V_56 * V_57 )
{
bool V_165 = false , V_166 = false ;
V_55 -> V_57 = * V_57 ;
if ( ! F_132 ( V_7 ) )
F_134 ( V_167 , V_55 ) ;
else
F_135 ( V_167 , V_55 ) ;
if ( F_119 ( V_7 , ( 1UL << V_168 ) ) ) {
V_165 = true ;
if ( F_119 ( V_7 , ( 1UL << V_169 ) ) )
V_166 = true ;
}
F_136 ( V_55 , V_165 , V_166 ) ;
if ( ! F_120 ( V_7 ) )
V_55 -> V_57 . V_170 = 0 ;
if ( F_127 ( V_7 , F_121 ) )
F_135 ( V_171 , V_55 ) ;
else
F_134 ( V_171 , V_55 ) ;
if ( ! F_129 ( V_7 ) )
V_55 -> V_57 . V_163 = 0 ;
if ( F_127 ( V_7 , F_125 ) )
F_134 ( V_161 , V_55 ) ;
else
F_135 ( V_161 , V_55 ) ;
F_116 ( V_7 ) ;
if ( F_124 ( V_55 ) && F_127 ( V_7 , F_123 ) )
F_134 ( V_172 , V_55 ) ;
F_137 () ;
if ( F_88 ( V_7 ) )
F_135 ( V_173 , V_55 ) ;
}
unsigned int F_55 ( struct V_6 * V_7 )
{
return V_7 -> V_28 ;
}
struct V_35 * F_76 ( struct V_6 * V_7 )
{
return & V_7 -> V_32 ;
}
T_2 F_138 ( struct V_6 * V_7 )
{
return V_7 -> V_27 ;
}
static void F_139 ( struct V_6 * V_7 , enum V_174 V_27 )
{
int V_43 = V_7 -> V_28 ;
struct V_21 * V_50 = V_7 -> V_26 ;
while ( V_43 -- ) {
switch ( V_27 ) {
case V_175 :
if ( V_50 -> type -> V_176 )
V_50 -> type -> V_176 ( V_50 ) ;
break;
case V_177 :
if ( V_50 -> type -> V_178 )
V_50 -> type -> V_178 ( V_50 ) ;
break;
case V_179 :
if ( V_50 -> type -> V_180 )
V_50 -> type -> V_180 ( V_50 ) ;
break;
}
V_50 ++ ;
}
}
void F_140 ( struct V_6 * V_7 )
{
if ( ! V_7 )
return;
F_139 ( V_7 , V_175 ) ;
}
void F_141 ( struct V_6 * V_7 )
{
if ( ! V_7 )
return;
F_139 ( V_7 , V_177 ) ;
}
void F_142 ( struct V_6 * V_7 )
{
if ( ! V_7 )
return;
F_139 ( V_7 , V_179 ) ;
}
int F_143 ( struct V_6 * V_7 )
{
int V_43 , V_69 = 0 ;
for ( V_43 = 0 ; V_43 < V_7 -> V_28 ; V_43 ++ ) {
struct V_21 * V_50 = V_7 -> V_26 + V_43 ;
if ( ! V_50 -> type -> V_181 )
continue;
V_69 = V_50 -> type -> V_181 ( V_50 ) ;
if ( V_69 ) {
F_59 ( L_45 ,
F_20 ( V_7 -> V_30 ) , V_50 -> type -> V_42 , V_69 ) ;
return V_69 ;
}
}
for ( V_43 = 0 ; V_43 < V_7 -> V_28 ; V_43 ++ ) {
struct V_21 * V_50 = V_7 -> V_26 + V_43 ;
if ( V_50 -> type -> V_182 )
V_50 -> type -> V_182 ( V_50 ) ;
}
return 0 ;
}
void F_144 ( struct V_6 * V_7 , struct V_183 * V_184 )
{
F_42 ( & V_184 -> V_40 , & V_7 -> V_33 ) ;
}
int F_145 ( struct V_6 * V_7 , int V_185 )
{
struct V_38 * V_39 ;
struct V_35 * V_32 = F_76 ( V_7 ) ;
struct V_183 * V_184 ;
int V_69 = 0 ;
F_26 (dd, devices, list) {
struct V_54 * V_55 = F_29 ( V_39 -> V_41 -> V_48 ) ;
char V_64 [ V_65 ] ;
if ( F_146 ( V_55 ) )
V_69 |= F_147 ( & V_55 -> V_186 , V_185 ) ;
else
F_148 ( L_46 ,
F_20 ( V_7 -> V_30 ) ,
F_30 ( V_39 -> V_41 -> V_48 , V_64 ) ) ;
}
F_26 (cb, &t->target_callbacks, list)
if ( V_184 -> V_187 )
V_69 |= V_184 -> V_187 ( V_184 , V_185 ) ;
return V_69 ;
}
struct V_29 * F_149 ( struct V_6 * V_7 )
{
return V_7 -> V_30 ;
}
void F_150 ( struct V_6 * V_7 )
{
struct V_29 * V_30 ;
struct V_54 * V_188 ;
unsigned long V_189 ;
if ( ! F_88 ( V_7 ) )
return;
V_30 = F_149 ( V_7 ) ;
V_188 = F_151 ( V_30 ) ;
if ( V_188 ) {
if ( V_188 -> V_131 )
F_152 ( V_188 , true ) ;
else {
F_153 ( V_188 -> V_190 , V_189 ) ;
F_154 ( V_188 ) ;
F_155 ( V_188 -> V_190 , V_189 ) ;
}
}
}
