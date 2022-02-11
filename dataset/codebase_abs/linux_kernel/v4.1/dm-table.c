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
V_7 -> V_27 = V_27 ;
V_7 -> V_30 = V_30 ;
* V_3 = V_7 ;
return 0 ;
}
static void F_16 ( struct V_34 * V_32 , struct V_29 * V_30 )
{
struct V_34 * V_35 , * V_36 ;
F_17 (tmp, next, devices) {
struct V_37 * V_38 =
F_18 ( V_35 , struct V_37 , V_39 ) ;
F_19 ( L_1 ,
F_20 ( V_30 ) , V_38 -> V_40 -> V_41 ) ;
F_21 ( V_30 , V_38 -> V_40 ) ;
F_15 ( V_38 ) ;
}
}
void F_22 ( struct V_6 * V_7 )
{
unsigned int V_42 ;
if ( ! V_7 )
return;
if ( V_7 -> V_11 >= 2 )
F_10 ( V_7 -> V_9 [ V_7 -> V_11 - 2 ] ) ;
for ( V_42 = 0 ; V_42 < V_7 -> V_28 ; V_42 ++ ) {
struct V_21 * V_43 = V_7 -> V_26 + V_42 ;
if ( V_43 -> type -> V_44 )
V_43 -> type -> V_44 ( V_43 ) ;
F_23 ( V_43 -> type ) ;
}
F_10 ( V_7 -> V_24 ) ;
F_16 ( & V_7 -> V_32 , V_7 -> V_30 ) ;
F_24 ( V_7 -> V_45 ) ;
F_15 ( V_7 ) ;
}
static struct V_37 * F_25 ( struct V_34 * V_8 , T_3 V_46 )
{
struct V_37 * V_38 ;
F_26 (dd, l, list)
if ( V_38 -> V_40 -> V_47 -> V_48 == V_46 )
return V_38 ;
return NULL ;
}
static int F_27 ( struct V_21 * V_49 , struct V_40 * V_46 ,
T_1 V_50 , T_1 V_51 , void * V_52 )
{
struct V_53 * V_54 ;
struct V_55 * V_56 = V_52 ;
struct V_57 * V_47 = V_46 -> V_47 ;
T_1 V_58 =
F_28 ( V_47 -> V_59 ) >> V_60 ;
unsigned short V_61 =
V_56 -> V_62 >> V_60 ;
char V_63 [ V_64 ] ;
V_54 = F_29 ( V_47 ) ;
if ( ! V_54 || ! V_54 -> V_65 ) {
F_19 ( L_2
L_3 ,
F_20 ( V_49 -> V_66 -> V_30 ) , F_30 ( V_47 , V_63 ) ,
( unsigned long long ) V_50 ,
( unsigned long long ) V_51 ,
( unsigned long long ) V_58 ) ;
return 1 ;
}
if ( ! V_58 )
return 0 ;
if ( ( V_50 >= V_58 ) || ( V_50 + V_51 > V_58 ) ) {
F_19 ( L_4
L_3 ,
F_20 ( V_49 -> V_66 -> V_30 ) , F_30 ( V_47 , V_63 ) ,
( unsigned long long ) V_50 ,
( unsigned long long ) V_51 ,
( unsigned long long ) V_58 ) ;
return 1 ;
}
if ( V_61 <= 1 )
return 0 ;
if ( V_50 & ( V_61 - 1 ) ) {
F_19 ( L_5
L_6 ,
F_20 ( V_49 -> V_66 -> V_30 ) ,
( unsigned long long ) V_50 ,
V_56 -> V_62 , F_30 ( V_47 , V_63 ) ) ;
return 1 ;
}
if ( V_51 & ( V_61 - 1 ) ) {
F_19 ( L_7
L_6 ,
F_20 ( V_49 -> V_66 -> V_30 ) ,
( unsigned long long ) V_51 ,
V_56 -> V_62 , F_30 ( V_47 , V_63 ) ) ;
return 1 ;
}
return 0 ;
}
static int F_31 ( struct V_37 * V_38 , T_2 V_67 ,
struct V_29 * V_30 )
{
int V_68 ;
struct V_40 * V_69 , * V_70 ;
V_69 = V_38 -> V_40 ;
V_68 = F_32 ( V_30 , V_38 -> V_40 -> V_47 -> V_48 ,
V_38 -> V_40 -> V_27 | V_67 , & V_70 ) ;
if ( V_68 )
return V_68 ;
V_38 -> V_40 = V_70 ;
F_21 ( V_30 , V_69 ) ;
return 0 ;
}
int F_33 ( struct V_21 * V_49 , const char * V_71 , T_2 V_27 ,
struct V_40 * * V_3 )
{
int V_68 ;
T_3 V_72 ( V_46 ) ;
struct V_37 * V_38 ;
struct V_6 * V_7 = V_49 -> V_66 ;
struct V_57 * V_47 ;
F_34 ( ! V_7 ) ;
V_47 = F_35 ( V_71 ) ;
if ( F_36 ( V_47 ) ) {
V_46 = F_37 ( V_71 ) ;
if ( ! V_46 )
return - V_73 ;
} else {
V_46 = V_47 -> V_48 ;
F_38 ( V_47 ) ;
}
V_38 = F_25 ( & V_7 -> V_32 , V_46 ) ;
if ( ! V_38 ) {
V_38 = F_39 ( sizeof( * V_38 ) , V_31 ) ;
if ( ! V_38 )
return - V_23 ;
if ( ( V_68 = F_32 ( V_7 -> V_30 , V_46 , V_27 , & V_38 -> V_40 ) ) ) {
F_15 ( V_38 ) ;
return V_68 ;
}
F_40 ( & V_38 -> V_74 , 0 ) ;
F_41 ( & V_38 -> V_39 , & V_7 -> V_32 ) ;
} else if ( V_38 -> V_40 -> V_27 != ( V_27 | V_38 -> V_40 -> V_27 ) ) {
V_68 = F_31 ( V_38 , V_27 , V_7 -> V_30 ) ;
if ( V_68 )
return V_68 ;
}
F_42 ( & V_38 -> V_74 ) ;
* V_3 = V_38 -> V_40 ;
return 0 ;
}
static int F_43 ( struct V_21 * V_49 , struct V_40 * V_46 ,
T_1 V_50 , T_1 V_51 , void * V_52 )
{
struct V_55 * V_56 = V_52 ;
struct V_57 * V_47 = V_46 -> V_47 ;
struct V_53 * V_54 = F_29 ( V_47 ) ;
char V_63 [ V_64 ] ;
if ( F_44 ( ! V_54 ) ) {
F_19 ( L_8 ,
F_20 ( V_49 -> V_66 -> V_30 ) , F_30 ( V_47 , V_63 ) ) ;
return 0 ;
}
if ( F_45 ( V_56 , V_47 , V_50 ) < 0 )
F_19 ( L_9
L_10
L_11 ,
F_20 ( V_49 -> V_66 -> V_30 ) , F_30 ( V_47 , V_63 ) ,
V_54 -> V_56 . V_75 ,
V_54 -> V_56 . V_62 ,
V_54 -> V_56 . V_76 ,
( unsigned long long ) V_50 << V_60 ) ;
if ( F_46 ( V_54 ) && ! V_49 -> type -> V_77 )
F_47 ( V_56 ,
( unsigned int ) ( V_78 >> 9 ) ) ;
return 0 ;
}
void F_48 ( struct V_21 * V_49 , struct V_40 * V_79 )
{
int V_80 = 0 ;
struct V_34 * V_32 = & V_49 -> V_66 -> V_32 ;
struct V_37 * V_38 ;
F_26 (dd, devices, list) {
if ( V_38 -> V_40 == V_79 ) {
V_80 = 1 ;
break;
}
}
if ( ! V_80 ) {
F_19 ( L_12 ,
F_20 ( V_49 -> V_66 -> V_30 ) , V_79 -> V_41 ) ;
return;
}
if ( F_49 ( & V_38 -> V_74 ) ) {
F_21 ( V_49 -> V_66 -> V_30 , V_79 ) ;
F_50 ( & V_38 -> V_39 ) ;
F_15 ( V_38 ) ;
}
}
static int F_51 ( struct V_6 * V_66 , struct V_21 * V_49 )
{
struct V_21 * V_81 ;
if ( ! V_66 -> V_28 )
return ! V_49 -> V_82 ;
V_81 = & V_66 -> V_26 [ V_66 -> V_28 - 1 ] ;
return ( V_49 -> V_82 == ( V_81 -> V_82 + V_81 -> V_51 ) ) ;
}
static char * * F_52 ( unsigned * V_83 , char * * V_84 )
{
char * * V_85 ;
unsigned V_86 ;
T_4 V_87 ;
if ( * V_83 ) {
V_86 = * V_83 * 2 ;
V_87 = V_31 ;
} else {
V_86 = 8 ;
V_87 = V_88 ;
}
V_85 = F_39 ( V_86 * sizeof( * V_85 ) , V_87 ) ;
if ( V_85 ) {
memcpy ( V_85 , V_84 , * V_83 * sizeof( * V_85 ) ) ;
* V_83 = V_86 ;
}
F_15 ( V_84 ) ;
return V_85 ;
}
int F_53 ( int * V_89 , char * * * V_90 , char * V_91 )
{
char * V_50 , * V_92 = V_91 , * V_93 , * * V_85 = NULL ;
unsigned V_83 = 0 ;
* V_89 = 0 ;
if ( ! V_91 ) {
* V_90 = NULL ;
return 0 ;
}
V_85 = F_52 ( & V_83 , V_85 ) ;
if ( ! V_85 )
return - V_23 ;
while ( 1 ) {
V_50 = F_54 ( V_92 ) ;
if ( ! * V_50 )
break;
V_92 = V_93 = V_50 ;
while ( * V_92 ) {
if ( * V_92 == '\\' && * ( V_92 + 1 ) ) {
* V_93 ++ = * ( V_92 + 1 ) ;
V_92 += 2 ;
continue;
}
if ( isspace ( * V_92 ) )
break;
* V_93 ++ = * V_92 ++ ;
}
if ( ( * V_89 + 1 ) > V_83 ) {
V_85 = F_52 ( & V_83 , V_85 ) ;
if ( ! V_85 )
return - V_23 ;
}
if ( * V_92 )
V_92 ++ ;
* V_93 = '\0' ;
V_85 [ * V_89 ] = V_50 ;
( * V_89 ) ++ ;
}
* V_90 = V_85 ;
return 0 ;
}
static int F_55 ( struct V_6 * V_66 ,
struct V_55 * V_56 )
{
unsigned short V_94 =
V_56 -> V_62 >> V_60 ;
unsigned short V_95 = 0 ;
unsigned short V_96 = 0 ;
struct V_21 * V_72 ( V_49 ) ;
struct V_55 V_97 ;
unsigned V_42 = 0 ;
while ( V_42 < F_56 ( V_66 ) ) {
V_49 = F_57 ( V_66 , V_42 ++ ) ;
F_58 ( & V_97 ) ;
if ( V_49 -> type -> V_98 )
V_49 -> type -> V_98 ( V_49 , F_43 ,
& V_97 ) ;
if ( V_96 < V_49 -> V_51 &&
V_96 & ( ( V_97 . V_62 >>
V_60 ) - 1 ) )
break;
V_95 =
( unsigned short ) ( ( V_95 + V_49 -> V_51 ) &
( V_94 - 1 ) ) ;
V_96 = V_95 ?
V_94 - V_95 : 0 ;
}
if ( V_96 ) {
F_19 ( L_13
L_14 ,
F_20 ( V_66 -> V_30 ) , V_42 ,
( unsigned long long ) V_49 -> V_82 ,
( unsigned long long ) V_49 -> V_51 ,
V_56 -> V_62 ) ;
return - V_99 ;
}
return 0 ;
}
int F_59 ( struct V_6 * V_7 , const char * type ,
T_1 V_50 , T_1 V_51 , char * V_100 )
{
int V_68 = - V_99 , V_89 ;
char * * V_85 ;
struct V_21 * V_43 ;
if ( V_7 -> V_101 ) {
F_60 ( L_15 ,
F_20 ( V_7 -> V_30 ) , V_7 -> V_26 -> type -> V_41 ) ;
return - V_99 ;
}
F_34 ( V_7 -> V_28 >= V_7 -> V_25 ) ;
V_43 = V_7 -> V_26 + V_7 -> V_28 ;
memset ( V_43 , 0 , sizeof( * V_43 ) ) ;
if ( ! V_51 ) {
F_60 ( L_16 , F_20 ( V_7 -> V_30 ) ) ;
return - V_99 ;
}
V_43 -> type = F_61 ( type ) ;
if ( ! V_43 -> type ) {
F_60 ( L_17 , F_20 ( V_7 -> V_30 ) ,
type ) ;
return - V_99 ;
}
if ( F_62 ( V_43 -> type ) ) {
if ( V_7 -> V_28 ) {
F_60 ( L_15 ,
F_20 ( V_7 -> V_30 ) , type ) ;
return - V_99 ;
}
V_7 -> V_101 = 1 ;
}
if ( F_63 ( V_43 -> type ) && ! ( V_7 -> V_27 & V_102 ) ) {
F_60 ( L_18 ,
F_20 ( V_7 -> V_30 ) , type ) ;
return - V_99 ;
}
if ( V_7 -> V_103 ) {
if ( V_7 -> V_103 != V_43 -> type ) {
F_60 ( L_19 ,
F_20 ( V_7 -> V_30 ) , V_7 -> V_103 -> V_41 ) ;
return - V_99 ;
}
} else if ( F_64 ( V_43 -> type ) ) {
if ( V_7 -> V_28 ) {
F_60 ( L_19 ,
F_20 ( V_7 -> V_30 ) , V_43 -> type -> V_41 ) ;
return - V_99 ;
}
V_7 -> V_103 = V_43 -> type ;
}
V_43 -> V_66 = V_7 ;
V_43 -> V_82 = V_50 ;
V_43 -> V_51 = V_51 ;
V_43 -> error = L_20 ;
if ( ! F_51 ( V_7 , V_43 ) ) {
V_43 -> error = L_21 ;
V_68 = - V_99 ;
goto V_104;
}
V_68 = F_53 ( & V_89 , & V_85 , V_100 ) ;
if ( V_68 ) {
V_43 -> error = L_22 ;
goto V_104;
}
V_68 = V_43 -> type -> V_105 ( V_43 , V_89 , V_85 ) ;
F_15 ( V_85 ) ;
if ( V_68 )
goto V_104;
V_7 -> V_24 [ V_7 -> V_28 ++ ] = V_43 -> V_82 + V_43 -> V_51 - 1 ;
if ( ! V_43 -> V_106 && V_43 -> V_107 )
F_19 ( L_23 ,
F_20 ( V_7 -> V_30 ) , type ) ;
return 0 ;
V_104:
F_60 ( L_24 , F_20 ( V_7 -> V_30 ) , type , V_43 -> error ) ;
F_23 ( V_43 -> type ) ;
return V_68 ;
}
static int F_65 ( struct V_108 * V_109 , struct V_110 * V_111 ,
unsigned * V_112 , char * * error , unsigned V_113 )
{
const char * V_114 = F_66 ( V_111 ) ;
char V_115 ;
if ( ! V_114 ||
( sscanf ( V_114 , L_25 , V_112 , & V_115 ) != 1 ) ||
( * V_112 < V_109 -> V_116 ) ||
( * V_112 > V_109 -> V_117 ) ||
( V_113 && V_111 -> V_89 < * V_112 ) ) {
* error = V_109 -> error ;
return - V_99 ;
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
char * V_68 ;
if ( V_118 -> V_89 ) {
V_118 -> V_89 -- ;
V_68 = * V_118 -> V_85 ;
V_118 -> V_85 ++ ;
return V_68 ;
}
return NULL ;
}
void F_69 ( struct V_110 * V_118 , unsigned V_119 )
{
F_34 ( V_118 -> V_89 < V_119 ) ;
V_118 -> V_89 -= V_119 ;
V_118 -> V_85 += V_119 ;
}
static bool F_70 ( unsigned V_120 )
{
return ( V_120 == V_121 ||
V_120 == V_122 ) ;
}
static int F_71 ( struct V_6 * V_7 )
{
unsigned V_42 ;
unsigned V_123 = 0 , V_124 = 0 , V_125 = 0 ;
bool V_126 = false ;
struct V_21 * V_43 ;
struct V_37 * V_38 ;
struct V_34 * V_32 ;
unsigned V_127 = F_72 ( V_7 -> V_30 ) ;
for ( V_42 = 0 ; V_42 < V_7 -> V_28 ; V_42 ++ ) {
V_43 = V_7 -> V_26 + V_42 ;
if ( F_73 ( V_43 ) )
V_125 = 1 ;
else if ( F_74 ( V_43 ) )
V_124 = 1 ;
else
V_123 = 1 ;
if ( V_123 && V_124 ) {
F_19 ( L_26
L_27 ) ;
return - V_99 ;
}
}
if ( V_125 && ! V_123 && ! V_124 ) {
if ( F_70 ( V_127 ) )
V_124 = 1 ;
else
V_123 = 1 ;
}
if ( V_123 ) {
V_7 -> type = V_128 ;
return 0 ;
}
F_34 ( ! V_124 ) ;
if ( V_7 -> V_28 > 1 ) {
F_19 ( L_28 ) ;
return - V_99 ;
}
V_32 = F_75 ( V_7 ) ;
F_26 (dd, devices, list) {
struct V_53 * V_54 = F_29 ( V_38 -> V_40 -> V_47 ) ;
if ( ! F_76 ( V_54 ) ) {
F_60 ( L_29
L_30 ) ;
return - V_99 ;
}
if ( V_54 -> V_129 )
V_126 = true ;
}
if ( V_126 ) {
F_26 (dd, devices, list)
if ( ! F_29 ( V_38 -> V_40 -> V_47 ) -> V_129 ) {
F_60 ( L_31
L_32 ) ;
return - V_99 ;
}
V_7 -> type = V_122 ;
} else if ( F_77 ( V_32 ) && F_70 ( V_127 ) ) {
V_7 -> type = V_127 ;
} else
V_7 -> type = V_121 ;
return 0 ;
}
unsigned F_78 ( struct V_6 * V_7 )
{
return V_7 -> type ;
}
struct V_130 * F_79 ( struct V_6 * V_7 )
{
return V_7 -> V_103 ;
}
bool F_80 ( struct V_6 * V_7 )
{
return F_70 ( F_78 ( V_7 ) ) ;
}
bool F_81 ( struct V_6 * V_7 )
{
return F_78 ( V_7 ) == V_122 ;
}
static int F_82 ( struct V_6 * V_7 , struct V_29 * V_30 )
{
unsigned type = F_78 ( V_7 ) ;
unsigned V_131 = 0 ;
struct V_21 * V_43 ;
unsigned V_42 ;
if ( F_44 ( type == V_132 ) ) {
F_19 ( L_33 ) ;
return - V_99 ;
}
if ( type == V_128 )
for ( V_42 = 0 ; V_42 < V_7 -> V_28 ; V_42 ++ ) {
V_43 = V_7 -> V_26 + V_42 ;
V_131 = V_117 ( V_131 , V_43 -> V_131 ) ;
}
V_7 -> V_45 = F_83 ( V_30 , type , V_7 -> V_133 , V_131 ) ;
if ( ! V_7 -> V_45 )
return - V_23 ;
return 0 ;
}
void F_84 ( struct V_6 * V_7 )
{
F_24 ( V_7 -> V_45 ) ;
V_7 -> V_45 = NULL ;
}
struct V_134 * F_85 ( struct V_6 * V_7 )
{
return V_7 -> V_45 ;
}
static int F_86 ( struct V_6 * V_7 )
{
int V_42 ;
unsigned int V_135 = 0 ;
T_1 * V_136 ;
for ( V_42 = V_7 -> V_11 - 2 ; V_42 >= 0 ; V_42 -- ) {
V_7 -> V_12 [ V_42 ] = F_2 ( V_7 -> V_12 [ V_42 + 1 ] , V_5 ) ;
V_135 += V_7 -> V_12 [ V_42 ] ;
}
V_136 = ( T_1 * ) F_7 ( V_135 , ( unsigned long ) V_137 ) ;
if ( ! V_136 )
return - V_23 ;
for ( V_42 = V_7 -> V_11 - 2 ; V_42 >= 0 ; V_42 -- ) {
V_7 -> V_9 [ V_42 ] = V_136 ;
V_136 += ( V_10 * V_7 -> V_12 [ V_42 ] ) ;
F_6 ( V_42 , V_7 ) ;
}
return 0 ;
}
static int F_87 ( struct V_6 * V_7 )
{
int V_68 = 0 ;
unsigned int V_138 ;
V_138 = F_2 ( V_7 -> V_28 , V_10 ) ;
V_7 -> V_11 = 1 + F_1 ( V_138 , V_5 ) ;
V_7 -> V_12 [ V_7 -> V_11 - 1 ] = V_138 ;
V_7 -> V_9 [ V_7 -> V_11 - 1 ] = V_7 -> V_24 ;
if ( V_7 -> V_11 >= 2 )
V_68 = F_86 ( V_7 ) ;
return V_68 ;
}
static struct V_139 * F_88 ( struct V_6 * V_7 ,
bool V_140 )
{
struct V_34 * V_32 = F_75 ( V_7 ) ;
struct V_37 * V_38 = NULL ;
struct V_139 * V_141 = NULL , * V_142 = NULL ;
F_26 (dd, devices, list) {
V_142 = V_38 -> V_40 -> V_47 -> V_143 ;
if ( ! F_89 ( V_142 ) )
goto V_144;
if ( ! V_140 && ! F_90 ( V_142 ) )
continue;
else if ( V_141 &&
F_91 ( V_141 , V_142 ) < 0 )
goto V_144;
V_141 = V_142 ;
}
return V_142 ;
V_144:
if ( V_141 )
F_19 ( L_34 ,
F_20 ( V_7 -> V_30 ) ,
V_141 -> V_145 ,
V_142 -> V_145 ) ;
return NULL ;
}
static int F_92 ( struct V_6 * V_7 , struct V_29 * V_30 )
{
struct V_139 * V_142 = NULL ;
V_142 = F_88 ( V_7 , false ) ;
if ( ! V_142 )
return 0 ;
if ( ! F_90 ( F_93 ( V_30 ) ) ) {
V_7 -> V_133 = 1 ;
return F_94 ( F_93 ( V_30 ) , NULL ) ;
}
if ( F_90 ( V_142 ) &&
F_91 ( F_93 ( V_30 ) , V_142 ) < 0 ) {
F_19 ( L_35
L_36 ,
F_20 ( V_7 -> V_30 ) ,
V_142 -> V_145 ) ;
return 1 ;
}
V_7 -> V_133 = 1 ;
return 0 ;
}
int F_95 ( struct V_6 * V_7 )
{
int V_68 ;
V_68 = F_71 ( V_7 ) ;
if ( V_68 ) {
F_60 ( L_37 ) ;
return V_68 ;
}
V_68 = F_87 ( V_7 ) ;
if ( V_68 ) {
F_60 ( L_38 ) ;
return V_68 ;
}
V_68 = F_92 ( V_7 , V_7 -> V_30 ) ;
if ( V_68 ) {
F_60 ( L_39 ) ;
return V_68 ;
}
V_68 = F_82 ( V_7 , V_7 -> V_30 ) ;
if ( V_68 )
F_60 ( L_40 ) ;
return V_68 ;
}
void F_96 ( struct V_6 * V_7 ,
void (* F_97)( void * ) , void * V_146 )
{
F_98 ( & V_147 ) ;
V_7 -> V_148 = F_97 ;
V_7 -> V_149 = V_146 ;
F_99 ( & V_147 ) ;
}
void F_100 ( struct V_6 * V_7 )
{
F_34 ( F_101 () ) ;
F_98 ( & V_147 ) ;
if ( V_7 -> V_148 )
V_7 -> V_148 ( V_7 -> V_149 ) ;
F_99 ( & V_147 ) ;
}
T_1 F_102 ( struct V_6 * V_7 )
{
return V_7 -> V_28 ? ( V_7 -> V_24 [ V_7 -> V_28 - 1 ] + 1 ) : 0 ;
}
struct V_21 * F_57 ( struct V_6 * V_7 , unsigned int V_9 )
{
if ( V_9 >= V_7 -> V_28 )
return NULL ;
return V_7 -> V_26 + V_9 ;
}
struct V_21 * F_103 ( struct V_6 * V_7 , T_1 V_150 )
{
unsigned int V_8 , V_1 = 0 , V_4 = 0 ;
T_1 * V_13 ;
for ( V_8 = 0 ; V_8 < V_7 -> V_11 ; V_8 ++ ) {
V_1 = F_3 ( V_1 , V_4 ) ;
V_13 = F_4 ( V_7 , V_8 , V_1 ) ;
for ( V_4 = 0 ; V_4 < V_10 ; V_4 ++ )
if ( V_13 [ V_4 ] >= V_150 )
break;
}
return & V_7 -> V_26 [ ( V_10 * V_1 ) + V_4 ] ;
}
static int F_104 ( struct V_21 * V_49 , struct V_40 * V_46 ,
T_1 V_50 , T_1 V_51 , void * V_52 )
{
unsigned * V_151 = V_52 ;
( * V_151 ) ++ ;
return 0 ;
}
bool F_105 ( struct V_6 * V_66 )
{
struct V_21 * V_72 ( V_49 ) ;
unsigned V_42 = 0 , V_151 = 0 ;
while ( V_42 < F_56 ( V_66 ) ) {
V_49 = F_57 ( V_66 , V_42 ++ ) ;
if ( ! V_49 -> type -> V_98 )
return false ;
V_49 -> type -> V_98 ( V_49 , F_104 , & V_151 ) ;
if ( V_151 )
return false ;
}
return true ;
}
int F_106 ( struct V_6 * V_66 ,
struct V_55 * V_56 )
{
struct V_21 * V_72 ( V_49 ) ;
struct V_55 V_97 ;
unsigned V_42 = 0 ;
F_58 ( V_56 ) ;
while ( V_42 < F_56 ( V_66 ) ) {
F_58 ( & V_97 ) ;
V_49 = F_57 ( V_66 , V_42 ++ ) ;
if ( ! V_49 -> type -> V_98 )
goto V_152;
V_49 -> type -> V_98 ( V_49 , F_43 ,
& V_97 ) ;
if ( V_49 -> type -> V_153 )
V_49 -> type -> V_153 ( V_49 , & V_97 ) ;
if ( V_49 -> type -> V_98 ( V_49 , F_27 ,
& V_97 ) )
return - V_99 ;
V_152:
if ( F_107 ( V_56 , & V_97 , 0 ) < 0 )
F_19 ( L_41
L_42
L_43 ,
F_20 ( V_66 -> V_30 ) ,
( unsigned long long ) V_49 -> V_82 ,
( unsigned long long ) V_49 -> V_51 ) ;
}
return F_55 ( V_66 , V_56 ) ;
}
static void F_108 ( struct V_6 * V_7 )
{
struct V_139 * V_142 = NULL ;
if ( ! F_89 ( F_93 ( V_7 -> V_30 ) ) )
return;
V_142 = F_88 ( V_7 , true ) ;
if ( V_142 )
F_94 ( F_93 ( V_7 -> V_30 ) ,
F_89 ( V_142 ) ) ;
else if ( F_90 ( F_93 ( V_7 -> V_30 ) ) )
F_19 ( L_44 ,
F_20 ( V_7 -> V_30 ) ) ;
else
F_19 ( L_45 ,
F_20 ( V_7 -> V_30 ) ) ;
}
static int F_109 ( struct V_21 * V_49 , struct V_40 * V_46 ,
T_1 V_50 , T_1 V_51 , void * V_52 )
{
unsigned V_154 = ( * ( unsigned * ) V_52 ) ;
struct V_53 * V_54 = F_29 ( V_46 -> V_47 ) ;
return V_54 && ( V_54 -> V_155 & V_154 ) ;
}
static bool F_110 ( struct V_6 * V_7 , unsigned V_154 )
{
struct V_21 * V_49 ;
unsigned V_42 = 0 ;
while ( V_42 < F_56 ( V_7 ) ) {
V_49 = F_57 ( V_7 , V_42 ++ ) ;
if ( ! V_49 -> V_156 )
continue;
if ( V_49 -> V_157 )
return true ;
if ( V_49 -> type -> V_98 &&
V_49 -> type -> V_98 ( V_49 , F_109 , & V_154 ) )
return true ;
}
return false ;
}
static bool F_111 ( struct V_6 * V_7 )
{
struct V_21 * V_49 ;
unsigned V_42 = 0 ;
while ( V_42 < F_56 ( V_7 ) ) {
V_49 = F_57 ( V_7 , V_42 ++ ) ;
if ( V_49 -> V_158 )
return false ;
}
return true ;
}
static int F_112 ( struct V_21 * V_49 , struct V_40 * V_46 ,
T_1 V_50 , T_1 V_51 , void * V_52 )
{
struct V_53 * V_54 = F_29 ( V_46 -> V_47 ) ;
return V_54 && F_113 ( V_54 ) ;
}
static int F_114 ( struct V_21 * V_49 , struct V_40 * V_46 ,
T_1 V_50 , T_1 V_51 , void * V_52 )
{
struct V_53 * V_54 = F_29 ( V_46 -> V_47 ) ;
return V_54 && ! F_115 ( V_54 ) ;
}
static int F_116 ( struct V_21 * V_49 , struct V_40 * V_46 ,
T_1 V_50 , T_1 V_51 , void * V_52 )
{
struct V_53 * V_54 = F_29 ( V_46 -> V_47 ) ;
return V_54 && ! F_117 ( V_159 , & V_54 -> V_160 ) ;
}
static int F_118 ( struct V_21 * V_49 , struct V_40 * V_46 ,
T_1 V_50 , T_1 V_51 , void * V_52 )
{
struct V_53 * V_54 = F_29 ( V_46 -> V_47 ) ;
return V_54 && ! F_117 ( V_161 , & V_54 -> V_160 ) ;
}
static bool F_119 ( struct V_6 * V_7 ,
T_5 V_162 )
{
struct V_21 * V_49 ;
unsigned V_42 = 0 ;
while ( V_42 < F_56 ( V_7 ) ) {
V_49 = F_57 ( V_7 , V_42 ++ ) ;
if ( ! V_49 -> type -> V_98 ||
! V_49 -> type -> V_98 ( V_49 , V_162 , NULL ) )
return false ;
}
return true ;
}
static int F_120 ( struct V_21 * V_49 , struct V_40 * V_46 ,
T_1 V_50 , T_1 V_51 , void * V_52 )
{
struct V_53 * V_54 = F_29 ( V_46 -> V_47 ) ;
return V_54 && ! V_54 -> V_56 . V_163 ;
}
static bool F_121 ( struct V_6 * V_7 )
{
struct V_21 * V_49 ;
unsigned V_42 = 0 ;
while ( V_42 < F_56 ( V_7 ) ) {
V_49 = F_57 ( V_7 , V_42 ++ ) ;
if ( ! V_49 -> V_164 )
return false ;
if ( ! V_49 -> type -> V_98 ||
V_49 -> type -> V_98 ( V_49 , F_120 , NULL ) )
return false ;
}
return true ;
}
static int F_122 ( struct V_21 * V_49 , struct V_40 * V_46 ,
T_1 V_50 , T_1 V_51 , void * V_52 )
{
struct V_53 * V_54 = F_29 ( V_46 -> V_47 ) ;
return V_54 && F_123 ( V_54 ) ;
}
static bool F_124 ( struct V_6 * V_7 )
{
struct V_21 * V_49 ;
unsigned V_42 = 0 ;
while ( V_42 < F_56 ( V_7 ) ) {
V_49 = F_57 ( V_7 , V_42 ++ ) ;
if ( ! V_49 -> V_106 )
continue;
if ( V_49 -> V_107 )
return true ;
if ( V_49 -> type -> V_98 &&
V_49 -> type -> V_98 ( V_49 , F_122 , NULL ) )
return true ;
}
return false ;
}
void F_125 ( struct V_6 * V_7 , struct V_53 * V_54 ,
struct V_55 * V_56 )
{
unsigned V_154 = 0 ;
V_54 -> V_56 = * V_56 ;
if ( ! F_124 ( V_7 ) )
F_126 ( V_165 , V_54 ) ;
else
F_127 ( V_165 , V_54 ) ;
if ( F_110 ( V_7 , V_166 ) ) {
V_154 |= V_166 ;
if ( F_110 ( V_7 , V_167 ) )
V_154 |= V_167 ;
}
F_128 ( V_54 , V_154 ) ;
if ( ! F_111 ( V_7 ) )
V_54 -> V_56 . V_168 = 0 ;
if ( F_119 ( V_7 , F_112 ) )
F_127 ( V_169 , V_54 ) ;
else
F_126 ( V_169 , V_54 ) ;
if ( ! F_121 ( V_7 ) )
V_54 -> V_56 . V_163 = 0 ;
if ( F_119 ( V_7 , F_116 ) )
F_126 ( V_159 , V_54 ) ;
else
F_127 ( V_159 , V_54 ) ;
if ( F_119 ( V_7 , F_118 ) )
F_126 ( V_161 , V_54 ) ;
else
F_127 ( V_161 , V_54 ) ;
F_108 ( V_7 ) ;
if ( F_115 ( V_54 ) && F_119 ( V_7 , F_114 ) )
F_126 ( V_170 , V_54 ) ;
F_129 () ;
if ( F_80 ( V_7 ) )
F_127 ( V_171 , V_54 ) ;
}
unsigned int F_56 ( struct V_6 * V_7 )
{
return V_7 -> V_28 ;
}
struct V_34 * F_75 ( struct V_6 * V_7 )
{
return & V_7 -> V_32 ;
}
T_2 F_130 ( struct V_6 * V_7 )
{
return V_7 -> V_27 ;
}
static void F_131 ( struct V_6 * V_7 , enum V_172 V_27 )
{
int V_42 = V_7 -> V_28 ;
struct V_21 * V_49 = V_7 -> V_26 ;
while ( V_42 -- ) {
switch ( V_27 ) {
case V_173 :
if ( V_49 -> type -> V_174 )
V_49 -> type -> V_174 ( V_49 ) ;
break;
case V_175 :
if ( V_49 -> type -> V_176 )
V_49 -> type -> V_176 ( V_49 ) ;
break;
case V_177 :
if ( V_49 -> type -> V_178 )
V_49 -> type -> V_178 ( V_49 ) ;
break;
}
V_49 ++ ;
}
}
void F_132 ( struct V_6 * V_7 )
{
if ( ! V_7 )
return;
F_131 ( V_7 , V_173 ) ;
}
void F_133 ( struct V_6 * V_7 )
{
if ( ! V_7 )
return;
F_131 ( V_7 , V_175 ) ;
}
void F_134 ( struct V_6 * V_7 )
{
if ( ! V_7 )
return;
F_131 ( V_7 , V_177 ) ;
}
int F_135 ( struct V_6 * V_7 )
{
int V_42 , V_68 = 0 ;
for ( V_42 = 0 ; V_42 < V_7 -> V_28 ; V_42 ++ ) {
struct V_21 * V_49 = V_7 -> V_26 + V_42 ;
if ( ! V_49 -> type -> V_179 )
continue;
V_68 = V_49 -> type -> V_179 ( V_49 ) ;
if ( V_68 ) {
F_60 ( L_46 ,
F_20 ( V_7 -> V_30 ) , V_49 -> type -> V_41 , V_68 ) ;
return V_68 ;
}
}
for ( V_42 = 0 ; V_42 < V_7 -> V_28 ; V_42 ++ ) {
struct V_21 * V_49 = V_7 -> V_26 + V_42 ;
if ( V_49 -> type -> V_180 )
V_49 -> type -> V_180 ( V_49 ) ;
}
return 0 ;
}
void F_136 ( struct V_6 * V_7 , struct V_181 * V_182 )
{
F_41 ( & V_182 -> V_39 , & V_7 -> V_33 ) ;
}
int F_137 ( struct V_6 * V_7 , int V_183 )
{
struct V_37 * V_38 ;
struct V_34 * V_32 = F_75 ( V_7 ) ;
struct V_181 * V_182 ;
int V_68 = 0 ;
F_26 (dd, devices, list) {
struct V_53 * V_54 = F_29 ( V_38 -> V_40 -> V_47 ) ;
char V_63 [ V_64 ] ;
if ( F_138 ( V_54 ) )
V_68 |= F_139 ( & V_54 -> V_184 , V_183 ) ;
else
F_140 ( L_47 ,
F_20 ( V_7 -> V_30 ) ,
F_30 ( V_38 -> V_40 -> V_47 , V_63 ) ) ;
}
F_26 (cb, &t->target_callbacks, list)
if ( V_182 -> V_185 )
V_68 |= V_182 -> V_185 ( V_182 , V_183 ) ;
return V_68 ;
}
struct V_29 * F_141 ( struct V_6 * V_7 )
{
return V_7 -> V_30 ;
}
void F_142 ( struct V_6 * V_7 )
{
struct V_29 * V_30 ;
struct V_53 * V_186 ;
unsigned long V_187 ;
if ( ! F_80 ( V_7 ) )
return;
V_30 = F_141 ( V_7 ) ;
V_186 = F_143 ( V_30 ) ;
if ( V_186 ) {
if ( V_186 -> V_129 )
F_144 ( V_186 , true ) ;
else {
F_145 ( V_186 -> V_188 , V_187 ) ;
F_146 ( V_186 ) ;
F_147 ( V_186 -> V_188 , V_187 ) ;
}
}
}
