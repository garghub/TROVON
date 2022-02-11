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
unsigned int V_73 , V_74 ;
struct V_6 * V_7 = V_49 -> V_66 ;
char V_75 ;
F_34 ( ! V_7 ) ;
if ( sscanf ( V_71 , L_8 , & V_73 , & V_74 , & V_75 ) == 2 ) {
V_46 = F_35 ( V_73 , V_74 ) ;
if ( F_36 ( V_46 ) != V_73 || F_37 ( V_46 ) != V_74 )
return - V_76 ;
} else {
struct V_57 * V_47 = F_38 ( V_71 ) ;
if ( F_39 ( V_47 ) )
return F_40 ( V_47 ) ;
V_46 = V_47 -> V_48 ;
F_41 ( V_47 ) ;
}
V_38 = F_25 ( & V_7 -> V_32 , V_46 ) ;
if ( ! V_38 ) {
V_38 = F_42 ( sizeof( * V_38 ) , V_31 ) ;
if ( ! V_38 )
return - V_23 ;
if ( ( V_68 = F_32 ( V_7 -> V_30 , V_46 , V_27 , & V_38 -> V_40 ) ) ) {
F_15 ( V_38 ) ;
return V_68 ;
}
F_43 ( & V_38 -> V_77 , 0 ) ;
F_44 ( & V_38 -> V_39 , & V_7 -> V_32 ) ;
} else if ( V_38 -> V_40 -> V_27 != ( V_27 | V_38 -> V_40 -> V_27 ) ) {
V_68 = F_31 ( V_38 , V_27 , V_7 -> V_30 ) ;
if ( V_68 )
return V_68 ;
}
F_45 ( & V_38 -> V_77 ) ;
* V_3 = V_38 -> V_40 ;
return 0 ;
}
static int F_46 ( struct V_21 * V_49 , struct V_40 * V_46 ,
T_1 V_50 , T_1 V_51 , void * V_52 )
{
struct V_55 * V_56 = V_52 ;
struct V_57 * V_47 = V_46 -> V_47 ;
struct V_53 * V_54 = F_29 ( V_47 ) ;
char V_63 [ V_64 ] ;
if ( F_47 ( ! V_54 ) ) {
F_19 ( L_9 ,
F_20 ( V_49 -> V_66 -> V_30 ) , F_30 ( V_47 , V_63 ) ) ;
return 0 ;
}
if ( F_48 ( V_56 , V_47 , V_50 ) < 0 )
F_19 ( L_10
L_11
L_12 ,
F_20 ( V_49 -> V_66 -> V_30 ) , F_30 ( V_47 , V_63 ) ,
V_54 -> V_56 . V_78 ,
V_54 -> V_56 . V_62 ,
V_54 -> V_56 . V_79 ,
( unsigned long long ) V_50 << V_60 ) ;
if ( F_49 ( V_54 ) && ! V_49 -> type -> V_80 )
F_50 ( V_56 ,
( unsigned int ) ( V_81 >> 9 ) ) ;
return 0 ;
}
void F_51 ( struct V_21 * V_49 , struct V_40 * V_82 )
{
int V_83 = 0 ;
struct V_34 * V_32 = & V_49 -> V_66 -> V_32 ;
struct V_37 * V_38 ;
F_26 (dd, devices, list) {
if ( V_38 -> V_40 == V_82 ) {
V_83 = 1 ;
break;
}
}
if ( ! V_83 ) {
F_19 ( L_13 ,
F_20 ( V_49 -> V_66 -> V_30 ) , V_82 -> V_41 ) ;
return;
}
if ( F_52 ( & V_38 -> V_77 ) ) {
F_21 ( V_49 -> V_66 -> V_30 , V_82 ) ;
F_53 ( & V_38 -> V_39 ) ;
F_15 ( V_38 ) ;
}
}
static int F_54 ( struct V_6 * V_66 , struct V_21 * V_49 )
{
struct V_21 * V_84 ;
if ( ! V_66 -> V_28 )
return ! V_49 -> V_85 ;
V_84 = & V_66 -> V_26 [ V_66 -> V_28 - 1 ] ;
return ( V_49 -> V_85 == ( V_84 -> V_85 + V_84 -> V_51 ) ) ;
}
static char * * F_55 ( unsigned * V_86 , char * * V_87 )
{
char * * V_88 ;
unsigned V_89 ;
T_4 V_90 ;
if ( * V_86 ) {
V_89 = * V_86 * 2 ;
V_90 = V_31 ;
} else {
V_89 = 8 ;
V_90 = V_91 ;
}
V_88 = F_42 ( V_89 * sizeof( * V_88 ) , V_90 ) ;
if ( V_88 ) {
memcpy ( V_88 , V_87 , * V_86 * sizeof( * V_88 ) ) ;
* V_86 = V_89 ;
}
F_15 ( V_87 ) ;
return V_88 ;
}
int F_56 ( int * V_92 , char * * * V_93 , char * V_94 )
{
char * V_50 , * V_95 = V_94 , * V_96 , * * V_88 = NULL ;
unsigned V_86 = 0 ;
* V_92 = 0 ;
if ( ! V_94 ) {
* V_93 = NULL ;
return 0 ;
}
V_88 = F_55 ( & V_86 , V_88 ) ;
if ( ! V_88 )
return - V_23 ;
while ( 1 ) {
V_50 = F_57 ( V_95 ) ;
if ( ! * V_50 )
break;
V_95 = V_96 = V_50 ;
while ( * V_95 ) {
if ( * V_95 == '\\' && * ( V_95 + 1 ) ) {
* V_96 ++ = * ( V_95 + 1 ) ;
V_95 += 2 ;
continue;
}
if ( isspace ( * V_95 ) )
break;
* V_96 ++ = * V_95 ++ ;
}
if ( ( * V_92 + 1 ) > V_86 ) {
V_88 = F_55 ( & V_86 , V_88 ) ;
if ( ! V_88 )
return - V_23 ;
}
if ( * V_95 )
V_95 ++ ;
* V_96 = '\0' ;
V_88 [ * V_92 ] = V_50 ;
( * V_92 ) ++ ;
}
* V_93 = V_88 ;
return 0 ;
}
static int F_58 ( struct V_6 * V_66 ,
struct V_55 * V_56 )
{
unsigned short V_97 =
V_56 -> V_62 >> V_60 ;
unsigned short V_98 = 0 ;
unsigned short V_99 = 0 ;
struct V_21 * V_72 ( V_49 ) ;
struct V_55 V_100 ;
unsigned V_42 = 0 ;
while ( V_42 < F_59 ( V_66 ) ) {
V_49 = F_60 ( V_66 , V_42 ++ ) ;
F_61 ( & V_100 ) ;
if ( V_49 -> type -> V_101 )
V_49 -> type -> V_101 ( V_49 , F_46 ,
& V_100 ) ;
if ( V_99 < V_49 -> V_51 &&
V_99 & ( ( V_100 . V_62 >>
V_60 ) - 1 ) )
break;
V_98 =
( unsigned short ) ( ( V_98 + V_49 -> V_51 ) &
( V_97 - 1 ) ) ;
V_99 = V_98 ?
V_97 - V_98 : 0 ;
}
if ( V_99 ) {
F_19 ( L_14
L_15 ,
F_20 ( V_66 -> V_30 ) , V_42 ,
( unsigned long long ) V_49 -> V_85 ,
( unsigned long long ) V_49 -> V_51 ,
V_56 -> V_62 ) ;
return - V_102 ;
}
return 0 ;
}
int F_62 ( struct V_6 * V_7 , const char * type ,
T_1 V_50 , T_1 V_51 , char * V_103 )
{
int V_68 = - V_102 , V_92 ;
char * * V_88 ;
struct V_21 * V_43 ;
if ( V_7 -> V_104 ) {
F_63 ( L_16 ,
F_20 ( V_7 -> V_30 ) , V_7 -> V_26 -> type -> V_41 ) ;
return - V_102 ;
}
F_34 ( V_7 -> V_28 >= V_7 -> V_25 ) ;
V_43 = V_7 -> V_26 + V_7 -> V_28 ;
memset ( V_43 , 0 , sizeof( * V_43 ) ) ;
if ( ! V_51 ) {
F_63 ( L_17 , F_20 ( V_7 -> V_30 ) ) ;
return - V_102 ;
}
V_43 -> type = F_64 ( type ) ;
if ( ! V_43 -> type ) {
F_63 ( L_18 , F_20 ( V_7 -> V_30 ) ,
type ) ;
return - V_102 ;
}
if ( F_65 ( V_43 -> type ) ) {
if ( V_7 -> V_28 ) {
F_63 ( L_16 ,
F_20 ( V_7 -> V_30 ) , type ) ;
return - V_102 ;
}
V_7 -> V_104 = 1 ;
}
if ( F_66 ( V_43 -> type ) && ! ( V_7 -> V_27 & V_105 ) ) {
F_63 ( L_19 ,
F_20 ( V_7 -> V_30 ) , type ) ;
return - V_102 ;
}
if ( V_7 -> V_106 ) {
if ( V_7 -> V_106 != V_43 -> type ) {
F_63 ( L_20 ,
F_20 ( V_7 -> V_30 ) , V_7 -> V_106 -> V_41 ) ;
return - V_102 ;
}
} else if ( F_67 ( V_43 -> type ) ) {
if ( V_7 -> V_28 ) {
F_63 ( L_20 ,
F_20 ( V_7 -> V_30 ) , V_43 -> type -> V_41 ) ;
return - V_102 ;
}
V_7 -> V_106 = V_43 -> type ;
}
V_43 -> V_66 = V_7 ;
V_43 -> V_85 = V_50 ;
V_43 -> V_51 = V_51 ;
V_43 -> error = L_21 ;
if ( ! F_54 ( V_7 , V_43 ) ) {
V_43 -> error = L_22 ;
V_68 = - V_102 ;
goto V_107;
}
V_68 = F_56 ( & V_92 , & V_88 , V_103 ) ;
if ( V_68 ) {
V_43 -> error = L_23 ;
goto V_107;
}
V_68 = V_43 -> type -> V_108 ( V_43 , V_92 , V_88 ) ;
F_15 ( V_88 ) ;
if ( V_68 )
goto V_107;
V_7 -> V_24 [ V_7 -> V_28 ++ ] = V_43 -> V_85 + V_43 -> V_51 - 1 ;
if ( ! V_43 -> V_109 && V_43 -> V_110 )
F_19 ( L_24 ,
F_20 ( V_7 -> V_30 ) , type ) ;
return 0 ;
V_107:
F_63 ( L_25 , F_20 ( V_7 -> V_30 ) , type , V_43 -> error ) ;
F_23 ( V_43 -> type ) ;
return V_68 ;
}
static int F_68 ( struct V_111 * V_112 , struct V_113 * V_114 ,
unsigned * V_115 , char * * error , unsigned V_116 )
{
const char * V_117 = F_69 ( V_114 ) ;
char V_75 ;
if ( ! V_117 ||
( sscanf ( V_117 , L_26 , V_115 , & V_75 ) != 1 ) ||
( * V_115 < V_112 -> V_118 ) ||
( * V_115 > V_112 -> V_119 ) ||
( V_116 && V_114 -> V_92 < * V_115 ) ) {
* error = V_112 -> error ;
return - V_102 ;
}
return 0 ;
}
int F_70 ( struct V_111 * V_112 , struct V_113 * V_114 ,
unsigned * V_115 , char * * error )
{
return F_68 ( V_112 , V_114 , V_115 , error , 0 ) ;
}
int F_71 ( struct V_111 * V_112 , struct V_113 * V_114 ,
unsigned * V_115 , char * * error )
{
return F_68 ( V_112 , V_114 , V_115 , error , 1 ) ;
}
const char * F_69 ( struct V_113 * V_120 )
{
char * V_68 ;
if ( V_120 -> V_92 ) {
V_120 -> V_92 -- ;
V_68 = * V_120 -> V_88 ;
V_120 -> V_88 ++ ;
return V_68 ;
}
return NULL ;
}
void F_72 ( struct V_113 * V_120 , unsigned V_121 )
{
F_34 ( V_120 -> V_92 < V_121 ) ;
V_120 -> V_92 -= V_121 ;
V_120 -> V_88 += V_121 ;
}
static int F_73 ( struct V_6 * V_7 )
{
unsigned V_42 ;
unsigned V_122 = 0 , V_123 = 0 , V_124 = 0 ;
bool V_125 = false ;
struct V_21 * V_43 ;
struct V_37 * V_38 ;
struct V_34 * V_32 ;
unsigned V_126 = F_74 ( V_7 -> V_30 ) ;
for ( V_42 = 0 ; V_42 < V_7 -> V_28 ; V_42 ++ ) {
V_43 = V_7 -> V_26 + V_42 ;
if ( F_75 ( V_43 ) )
V_124 = 1 ;
else if ( F_76 ( V_43 ) )
V_123 = 1 ;
else
V_122 = 1 ;
if ( V_122 && V_123 ) {
F_19 ( L_27
L_28 ) ;
return - V_102 ;
}
}
if ( V_124 && ! V_122 && ! V_123 ) {
if ( V_126 == V_127 ||
V_126 == V_128 )
V_123 = 1 ;
else
V_122 = 1 ;
}
if ( V_122 ) {
V_7 -> type = V_129 ;
return 0 ;
}
F_34 ( ! V_123 ) ;
if ( V_7 -> V_28 > 1 ) {
F_19 ( L_29 ) ;
return - V_102 ;
}
V_32 = F_77 ( V_7 ) ;
F_26 (dd, devices, list) {
struct V_53 * V_54 = F_29 ( V_38 -> V_40 -> V_47 ) ;
if ( ! F_78 ( V_54 ) ) {
F_63 ( L_30
L_31 ) ;
return - V_102 ;
}
if ( V_54 -> V_130 )
V_125 = true ;
}
if ( V_125 ) {
F_26 (dd, devices, list)
if ( ! F_29 ( V_38 -> V_40 -> V_47 ) -> V_130 ) {
F_63 ( L_32
L_33 ) ;
return - V_102 ;
}
V_7 -> type = V_128 ;
} else if ( V_124 && F_79 ( V_32 ) && V_126 != V_131 ) {
V_7 -> type = V_126 ;
} else
V_7 -> type = V_127 ;
return 0 ;
}
unsigned F_80 ( struct V_6 * V_7 )
{
return V_7 -> type ;
}
struct V_132 * F_81 ( struct V_6 * V_7 )
{
return V_7 -> V_106 ;
}
bool F_82 ( struct V_6 * V_7 )
{
unsigned V_133 = F_80 ( V_7 ) ;
return ( V_133 == V_127 ||
V_133 == V_128 ) ;
}
bool F_83 ( struct V_6 * V_7 )
{
return F_80 ( V_7 ) == V_128 ;
}
static int F_84 ( struct V_6 * V_7 )
{
unsigned type = F_80 ( V_7 ) ;
unsigned V_134 = 0 ;
struct V_21 * V_43 ;
unsigned V_42 ;
if ( F_47 ( type == V_131 ) ) {
F_19 ( L_34 ) ;
return - V_102 ;
}
if ( type == V_129 )
for ( V_42 = 0 ; V_42 < V_7 -> V_28 ; V_42 ++ ) {
V_43 = V_7 -> V_26 + V_42 ;
V_134 = V_119 ( V_134 , V_43 -> V_134 ) ;
}
V_7 -> V_45 = F_85 ( type , V_7 -> V_135 , V_134 ) ;
if ( ! V_7 -> V_45 )
return - V_23 ;
return 0 ;
}
void F_86 ( struct V_6 * V_7 )
{
F_24 ( V_7 -> V_45 ) ;
V_7 -> V_45 = NULL ;
}
struct V_136 * F_87 ( struct V_6 * V_7 )
{
return V_7 -> V_45 ;
}
static int F_88 ( struct V_6 * V_7 )
{
int V_42 ;
unsigned int V_137 = 0 ;
T_1 * V_138 ;
for ( V_42 = V_7 -> V_11 - 2 ; V_42 >= 0 ; V_42 -- ) {
V_7 -> V_12 [ V_42 ] = F_2 ( V_7 -> V_12 [ V_42 + 1 ] , V_5 ) ;
V_137 += V_7 -> V_12 [ V_42 ] ;
}
V_138 = ( T_1 * ) F_7 ( V_137 , ( unsigned long ) V_139 ) ;
if ( ! V_138 )
return - V_23 ;
for ( V_42 = V_7 -> V_11 - 2 ; V_42 >= 0 ; V_42 -- ) {
V_7 -> V_9 [ V_42 ] = V_138 ;
V_138 += ( V_10 * V_7 -> V_12 [ V_42 ] ) ;
F_6 ( V_42 , V_7 ) ;
}
return 0 ;
}
static int F_89 ( struct V_6 * V_7 )
{
int V_68 = 0 ;
unsigned int V_140 ;
V_140 = F_2 ( V_7 -> V_28 , V_10 ) ;
V_7 -> V_11 = 1 + F_1 ( V_140 , V_5 ) ;
V_7 -> V_12 [ V_7 -> V_11 - 1 ] = V_140 ;
V_7 -> V_9 [ V_7 -> V_11 - 1 ] = V_7 -> V_24 ;
if ( V_7 -> V_11 >= 2 )
V_68 = F_88 ( V_7 ) ;
return V_68 ;
}
static struct V_141 * F_90 ( struct V_6 * V_7 ,
bool V_142 )
{
struct V_34 * V_32 = F_77 ( V_7 ) ;
struct V_37 * V_38 = NULL ;
struct V_141 * V_143 = NULL , * V_144 = NULL ;
F_26 (dd, devices, list) {
V_144 = V_38 -> V_40 -> V_47 -> V_145 ;
if ( ! F_91 ( V_144 ) )
goto V_146;
if ( ! V_142 && ! F_92 ( V_144 ) )
continue;
else if ( V_143 &&
F_93 ( V_143 , V_144 ) < 0 )
goto V_146;
V_143 = V_144 ;
}
return V_144 ;
V_146:
if ( V_143 )
F_19 ( L_35 ,
F_20 ( V_7 -> V_30 ) ,
V_143 -> V_147 ,
V_144 -> V_147 ) ;
return NULL ;
}
static int F_94 ( struct V_6 * V_7 , struct V_29 * V_30 )
{
struct V_141 * V_144 = NULL ;
V_144 = F_90 ( V_7 , false ) ;
if ( ! V_144 )
return 0 ;
if ( ! F_92 ( F_95 ( V_30 ) ) ) {
V_7 -> V_135 = 1 ;
return F_96 ( F_95 ( V_30 ) , NULL ) ;
}
if ( F_92 ( V_144 ) &&
F_93 ( F_95 ( V_30 ) , V_144 ) < 0 ) {
F_19 ( L_36
L_37 ,
F_20 ( V_7 -> V_30 ) ,
V_144 -> V_147 ) ;
return 1 ;
}
V_7 -> V_135 = 1 ;
return 0 ;
}
int F_97 ( struct V_6 * V_7 )
{
int V_68 ;
V_68 = F_73 ( V_7 ) ;
if ( V_68 ) {
F_63 ( L_38 ) ;
return V_68 ;
}
V_68 = F_89 ( V_7 ) ;
if ( V_68 ) {
F_63 ( L_39 ) ;
return V_68 ;
}
V_68 = F_94 ( V_7 , V_7 -> V_30 ) ;
if ( V_68 ) {
F_63 ( L_40 ) ;
return V_68 ;
}
V_68 = F_84 ( V_7 ) ;
if ( V_68 )
F_63 ( L_41 ) ;
return V_68 ;
}
void F_98 ( struct V_6 * V_7 ,
void (* F_99)( void * ) , void * V_148 )
{
F_100 ( & V_149 ) ;
V_7 -> V_150 = F_99 ;
V_7 -> V_151 = V_148 ;
F_101 ( & V_149 ) ;
}
void F_102 ( struct V_6 * V_7 )
{
F_34 ( F_103 () ) ;
F_100 ( & V_149 ) ;
if ( V_7 -> V_150 )
V_7 -> V_150 ( V_7 -> V_151 ) ;
F_101 ( & V_149 ) ;
}
T_1 F_104 ( struct V_6 * V_7 )
{
return V_7 -> V_28 ? ( V_7 -> V_24 [ V_7 -> V_28 - 1 ] + 1 ) : 0 ;
}
struct V_21 * F_60 ( struct V_6 * V_7 , unsigned int V_9 )
{
if ( V_9 >= V_7 -> V_28 )
return NULL ;
return V_7 -> V_26 + V_9 ;
}
struct V_21 * F_105 ( struct V_6 * V_7 , T_1 V_152 )
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
static int F_106 ( struct V_21 * V_49 , struct V_40 * V_46 ,
T_1 V_50 , T_1 V_51 , void * V_52 )
{
unsigned * V_153 = V_52 ;
( * V_153 ) ++ ;
return 0 ;
}
bool F_107 ( struct V_6 * V_66 )
{
struct V_21 * V_72 ( V_49 ) ;
unsigned V_42 = 0 , V_153 = 0 ;
while ( V_42 < F_59 ( V_66 ) ) {
V_49 = F_60 ( V_66 , V_42 ++ ) ;
if ( ! V_49 -> type -> V_101 )
return false ;
V_49 -> type -> V_101 ( V_49 , F_106 , & V_153 ) ;
if ( V_153 )
return false ;
}
return true ;
}
int F_108 ( struct V_6 * V_66 ,
struct V_55 * V_56 )
{
struct V_21 * V_72 ( V_49 ) ;
struct V_55 V_100 ;
unsigned V_42 = 0 ;
F_61 ( V_56 ) ;
while ( V_42 < F_59 ( V_66 ) ) {
F_61 ( & V_100 ) ;
V_49 = F_60 ( V_66 , V_42 ++ ) ;
if ( ! V_49 -> type -> V_101 )
goto V_154;
V_49 -> type -> V_101 ( V_49 , F_46 ,
& V_100 ) ;
if ( V_49 -> type -> V_155 )
V_49 -> type -> V_155 ( V_49 , & V_100 ) ;
if ( V_49 -> type -> V_101 ( V_49 , F_27 ,
& V_100 ) )
return - V_102 ;
V_154:
if ( F_109 ( V_56 , & V_100 , 0 ) < 0 )
F_19 ( L_42
L_43
L_44 ,
F_20 ( V_66 -> V_30 ) ,
( unsigned long long ) V_49 -> V_85 ,
( unsigned long long ) V_49 -> V_51 ) ;
}
return F_58 ( V_66 , V_56 ) ;
}
static void F_110 ( struct V_6 * V_7 )
{
struct V_141 * V_144 = NULL ;
if ( ! F_91 ( F_95 ( V_7 -> V_30 ) ) )
return;
V_144 = F_90 ( V_7 , true ) ;
if ( V_144 )
F_96 ( F_95 ( V_7 -> V_30 ) ,
F_91 ( V_144 ) ) ;
else if ( F_92 ( F_95 ( V_7 -> V_30 ) ) )
F_19 ( L_45 ,
F_20 ( V_7 -> V_30 ) ) ;
else
F_19 ( L_46 ,
F_20 ( V_7 -> V_30 ) ) ;
}
static int F_111 ( struct V_21 * V_49 , struct V_40 * V_46 ,
T_1 V_50 , T_1 V_51 , void * V_52 )
{
unsigned V_156 = ( * ( unsigned * ) V_52 ) ;
struct V_53 * V_54 = F_29 ( V_46 -> V_47 ) ;
return V_54 && ( V_54 -> V_157 & V_156 ) ;
}
static bool F_112 ( struct V_6 * V_7 , unsigned V_156 )
{
struct V_21 * V_49 ;
unsigned V_42 = 0 ;
while ( V_42 < F_59 ( V_7 ) ) {
V_49 = F_60 ( V_7 , V_42 ++ ) ;
if ( ! V_49 -> V_158 )
continue;
if ( V_49 -> V_159 )
return 1 ;
if ( V_49 -> type -> V_101 &&
V_49 -> type -> V_101 ( V_49 , F_111 , & V_156 ) )
return 1 ;
}
return 0 ;
}
static bool F_113 ( struct V_6 * V_7 )
{
struct V_21 * V_49 ;
unsigned V_42 = 0 ;
while ( V_42 < F_59 ( V_7 ) ) {
V_49 = F_60 ( V_7 , V_42 ++ ) ;
if ( V_49 -> V_160 )
return 0 ;
}
return 1 ;
}
static int F_114 ( struct V_21 * V_49 , struct V_40 * V_46 ,
T_1 V_50 , T_1 V_51 , void * V_52 )
{
struct V_53 * V_54 = F_29 ( V_46 -> V_47 ) ;
return V_54 && F_115 ( V_54 ) ;
}
static int F_116 ( struct V_21 * V_49 , struct V_40 * V_46 ,
T_1 V_50 , T_1 V_51 , void * V_52 )
{
struct V_53 * V_54 = F_29 ( V_46 -> V_47 ) ;
return V_54 && ! F_117 ( V_54 ) ;
}
static int F_118 ( struct V_21 * V_49 , struct V_40 * V_46 ,
T_1 V_50 , T_1 V_51 , void * V_52 )
{
struct V_53 * V_54 = F_29 ( V_46 -> V_47 ) ;
return V_54 && ! F_119 ( V_161 , & V_54 -> V_162 ) ;
}
static int F_120 ( struct V_21 * V_49 , struct V_40 * V_46 ,
T_1 V_50 , T_1 V_51 , void * V_52 )
{
struct V_53 * V_54 = F_29 ( V_46 -> V_47 ) ;
return V_54 && ! F_119 ( V_163 , & V_54 -> V_162 ) ;
}
static bool F_121 ( struct V_6 * V_7 ,
T_5 V_164 )
{
struct V_21 * V_49 ;
unsigned V_42 = 0 ;
while ( V_42 < F_59 ( V_7 ) ) {
V_49 = F_60 ( V_7 , V_42 ++ ) ;
if ( ! V_49 -> type -> V_101 ||
! V_49 -> type -> V_101 ( V_49 , V_164 , NULL ) )
return 0 ;
}
return 1 ;
}
static int F_122 ( struct V_21 * V_49 , struct V_40 * V_46 ,
T_1 V_50 , T_1 V_51 , void * V_52 )
{
struct V_53 * V_54 = F_29 ( V_46 -> V_47 ) ;
return V_54 && ! V_54 -> V_56 . V_165 ;
}
static bool F_123 ( struct V_6 * V_7 )
{
struct V_21 * V_49 ;
unsigned V_42 = 0 ;
while ( V_42 < F_59 ( V_7 ) ) {
V_49 = F_60 ( V_7 , V_42 ++ ) ;
if ( ! V_49 -> V_166 )
return false ;
if ( ! V_49 -> type -> V_101 ||
V_49 -> type -> V_101 ( V_49 , F_122 , NULL ) )
return false ;
}
return true ;
}
static int F_124 ( struct V_21 * V_49 , struct V_40 * V_46 ,
T_1 V_50 , T_1 V_51 , void * V_52 )
{
struct V_53 * V_54 = F_29 ( V_46 -> V_47 ) ;
return V_54 && F_125 ( V_54 ) ;
}
static bool F_126 ( struct V_6 * V_7 )
{
struct V_21 * V_49 ;
unsigned V_42 = 0 ;
while ( V_42 < F_59 ( V_7 ) ) {
V_49 = F_60 ( V_7 , V_42 ++ ) ;
if ( ! V_49 -> V_109 )
continue;
if ( V_49 -> V_110 )
return 1 ;
if ( V_49 -> type -> V_101 &&
V_49 -> type -> V_101 ( V_49 , F_124 , NULL ) )
return 1 ;
}
return 0 ;
}
void F_127 ( struct V_6 * V_7 , struct V_53 * V_54 ,
struct V_55 * V_56 )
{
unsigned V_156 = 0 ;
V_54 -> V_56 = * V_56 ;
if ( ! F_126 ( V_7 ) )
F_128 ( V_167 , V_54 ) ;
else
F_129 ( V_167 , V_54 ) ;
if ( F_112 ( V_7 , V_168 ) ) {
V_156 |= V_168 ;
if ( F_112 ( V_7 , V_169 ) )
V_156 |= V_169 ;
}
F_130 ( V_54 , V_156 ) ;
if ( ! F_113 ( V_7 ) )
V_54 -> V_56 . V_170 = 0 ;
if ( F_121 ( V_7 , F_114 ) )
F_129 ( V_171 , V_54 ) ;
else
F_128 ( V_171 , V_54 ) ;
if ( ! F_123 ( V_7 ) )
V_54 -> V_56 . V_165 = 0 ;
if ( F_121 ( V_7 , F_118 ) )
F_128 ( V_161 , V_54 ) ;
else
F_129 ( V_161 , V_54 ) ;
if ( F_121 ( V_7 , F_120 ) )
F_128 ( V_163 , V_54 ) ;
else
F_129 ( V_163 , V_54 ) ;
F_110 ( V_7 ) ;
if ( F_117 ( V_54 ) && F_121 ( V_7 , F_116 ) )
F_128 ( V_172 , V_54 ) ;
F_131 () ;
if ( F_82 ( V_7 ) )
F_129 ( V_173 , V_54 ) ;
}
unsigned int F_59 ( struct V_6 * V_7 )
{
return V_7 -> V_28 ;
}
struct V_34 * F_77 ( struct V_6 * V_7 )
{
return & V_7 -> V_32 ;
}
T_2 F_132 ( struct V_6 * V_7 )
{
return V_7 -> V_27 ;
}
static void F_133 ( struct V_6 * V_7 , enum V_174 V_27 )
{
int V_42 = V_7 -> V_28 ;
struct V_21 * V_49 = V_7 -> V_26 ;
while ( V_42 -- ) {
switch ( V_27 ) {
case V_175 :
if ( V_49 -> type -> V_176 )
V_49 -> type -> V_176 ( V_49 ) ;
break;
case V_177 :
if ( V_49 -> type -> V_178 )
V_49 -> type -> V_178 ( V_49 ) ;
break;
case V_179 :
if ( V_49 -> type -> V_180 )
V_49 -> type -> V_180 ( V_49 ) ;
break;
}
V_49 ++ ;
}
}
void F_134 ( struct V_6 * V_7 )
{
if ( ! V_7 )
return;
F_133 ( V_7 , V_175 ) ;
}
void F_135 ( struct V_6 * V_7 )
{
if ( ! V_7 )
return;
F_133 ( V_7 , V_177 ) ;
}
void F_136 ( struct V_6 * V_7 )
{
if ( ! V_7 )
return;
F_133 ( V_7 , V_179 ) ;
}
int F_137 ( struct V_6 * V_7 )
{
int V_42 , V_68 = 0 ;
for ( V_42 = 0 ; V_42 < V_7 -> V_28 ; V_42 ++ ) {
struct V_21 * V_49 = V_7 -> V_26 + V_42 ;
if ( ! V_49 -> type -> V_181 )
continue;
V_68 = V_49 -> type -> V_181 ( V_49 ) ;
if ( V_68 ) {
F_63 ( L_47 ,
F_20 ( V_7 -> V_30 ) , V_49 -> type -> V_41 , V_68 ) ;
return V_68 ;
}
}
for ( V_42 = 0 ; V_42 < V_7 -> V_28 ; V_42 ++ ) {
struct V_21 * V_49 = V_7 -> V_26 + V_42 ;
if ( V_49 -> type -> V_182 )
V_49 -> type -> V_182 ( V_49 ) ;
}
return 0 ;
}
void F_138 ( struct V_6 * V_7 , struct V_183 * V_184 )
{
F_44 ( & V_184 -> V_39 , & V_7 -> V_33 ) ;
}
int F_139 ( struct V_6 * V_7 , int V_185 )
{
struct V_37 * V_38 ;
struct V_34 * V_32 = F_77 ( V_7 ) ;
struct V_183 * V_184 ;
int V_68 = 0 ;
F_26 (dd, devices, list) {
struct V_53 * V_54 = F_29 ( V_38 -> V_40 -> V_47 ) ;
char V_63 [ V_64 ] ;
if ( F_140 ( V_54 ) )
V_68 |= F_141 ( & V_54 -> V_186 , V_185 ) ;
else
F_142 ( L_48 ,
F_20 ( V_7 -> V_30 ) ,
F_30 ( V_38 -> V_40 -> V_47 , V_63 ) ) ;
}
F_26 (cb, &t->target_callbacks, list)
if ( V_184 -> V_187 )
V_68 |= V_184 -> V_187 ( V_184 , V_185 ) ;
return V_68 ;
}
int F_143 ( struct V_6 * V_7 )
{
unsigned V_42 ;
struct V_21 * V_49 ;
for ( V_42 = 0 ; V_42 < V_7 -> V_28 ; V_42 ++ ) {
V_49 = V_7 -> V_26 + V_42 ;
if ( V_49 -> type -> V_188 && V_49 -> type -> V_188 ( V_49 ) )
return 1 ;
}
return 0 ;
}
struct V_29 * F_144 ( struct V_6 * V_7 )
{
return V_7 -> V_30 ;
}
void F_145 ( struct V_6 * V_7 )
{
struct V_29 * V_30 ;
struct V_53 * V_189 ;
unsigned long V_190 ;
if ( ! F_82 ( V_7 ) )
return;
V_30 = F_144 ( V_7 ) ;
V_189 = F_146 ( V_30 ) ;
if ( V_189 ) {
F_147 ( V_189 -> V_191 , V_190 ) ;
F_148 ( V_189 ) ;
F_149 ( V_189 -> V_191 , V_190 ) ;
}
}
