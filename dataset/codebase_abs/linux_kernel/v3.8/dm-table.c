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
int V_1 = V_7 -> V_23 ;
V_20 = ( T_1 * ) F_7 ( V_19 + 1 , sizeof( struct V_21 ) +
sizeof( T_1 ) ) ;
if ( ! V_20 )
return - V_24 ;
V_22 = (struct V_21 * ) ( V_20 + V_19 ) ;
if ( V_1 ) {
memcpy ( V_20 , V_7 -> V_25 , sizeof( * V_20 ) * V_1 ) ;
memcpy ( V_22 , V_7 -> V_26 , sizeof( * V_22 ) * V_1 ) ;
}
memset ( V_20 + V_1 , - 1 , sizeof( * V_20 ) * ( V_19 - V_1 ) ) ;
F_10 ( V_7 -> V_25 ) ;
V_7 -> V_27 = V_19 ;
V_7 -> V_25 = V_20 ;
V_7 -> V_26 = V_22 ;
return 0 ;
}
int F_11 ( struct V_6 * * V_3 , T_2 V_28 ,
unsigned V_23 , struct V_29 * V_30 )
{
struct V_6 * V_7 = F_12 ( sizeof( * V_7 ) , V_31 ) ;
if ( ! V_7 )
return - V_24 ;
F_13 ( & V_7 -> V_32 ) ;
F_13 ( & V_7 -> V_33 ) ;
F_14 ( & V_7 -> V_34 , 0 ) ;
if ( ! V_23 )
V_23 = V_10 ;
V_23 = F_15 ( V_23 , V_10 ) ;
if ( F_9 ( V_7 , V_23 ) ) {
F_16 ( V_7 ) ;
V_7 = NULL ;
return - V_24 ;
}
V_7 -> V_28 = V_28 ;
V_7 -> V_30 = V_30 ;
* V_3 = V_7 ;
return 0 ;
}
static void F_17 ( struct V_35 * V_32 )
{
struct V_35 * V_36 , * V_37 ;
F_18 (tmp, next, devices) {
struct V_38 * V_39 =
F_19 ( V_36 , struct V_38 , V_40 ) ;
F_20 ( L_1 ,
V_39 -> V_41 . V_42 ) ;
F_16 ( V_39 ) ;
}
}
void F_21 ( struct V_6 * V_7 )
{
unsigned int V_43 ;
if ( ! V_7 )
return;
while ( F_22 ( & V_7 -> V_34 ) )
F_23 ( 1 ) ;
F_24 () ;
if ( V_7 -> V_11 >= 2 )
F_10 ( V_7 -> V_9 [ V_7 -> V_11 - 2 ] ) ;
for ( V_43 = 0 ; V_43 < V_7 -> V_23 ; V_43 ++ ) {
struct V_21 * V_44 = V_7 -> V_26 + V_43 ;
if ( V_44 -> type -> V_45 )
V_44 -> type -> V_45 ( V_44 ) ;
F_25 ( V_44 -> type ) ;
}
F_10 ( V_7 -> V_25 ) ;
F_17 ( & V_7 -> V_32 ) ;
F_26 ( V_7 -> V_46 ) ;
F_16 ( V_7 ) ;
}
void F_27 ( struct V_6 * V_7 )
{
F_28 ( & V_7 -> V_34 ) ;
}
void F_29 ( struct V_6 * V_7 )
{
if ( ! V_7 )
return;
F_30 () ;
F_31 ( & V_7 -> V_34 ) ;
}
static inline int F_32 ( struct V_6 * V_7 )
{
if ( V_7 -> V_23 >= V_7 -> V_27 )
return F_9 ( V_7 , V_7 -> V_27 * 2 ) ;
return 0 ;
}
static struct V_38 * F_33 ( struct V_35 * V_8 , T_3 V_47 )
{
struct V_38 * V_39 ;
F_34 (dd, l, list)
if ( V_39 -> V_41 . V_48 -> V_49 == V_47 )
return V_39 ;
return NULL ;
}
static int F_35 ( struct V_38 * V_50 , T_3 V_47 ,
struct V_29 * V_30 )
{
static char * V_51 = L_2 ;
struct V_52 * V_48 ;
int V_53 ;
F_36 ( V_50 -> V_41 . V_48 ) ;
V_48 = F_37 ( V_47 , V_50 -> V_41 . V_28 | V_54 , V_51 ) ;
if ( F_38 ( V_48 ) )
return F_39 ( V_48 ) ;
V_53 = F_40 ( V_48 , F_41 ( V_30 ) ) ;
if ( V_53 ) {
F_42 ( V_48 , V_50 -> V_41 . V_28 | V_54 ) ;
return V_53 ;
}
V_50 -> V_41 . V_48 = V_48 ;
return 0 ;
}
static void F_43 ( struct V_38 * V_50 , struct V_29 * V_30 )
{
if ( ! V_50 -> V_41 . V_48 )
return;
F_44 ( V_50 -> V_41 . V_48 , F_41 ( V_30 ) ) ;
F_42 ( V_50 -> V_41 . V_48 , V_50 -> V_41 . V_28 | V_54 ) ;
V_50 -> V_41 . V_48 = NULL ;
}
static int F_45 ( struct V_21 * V_55 , struct V_41 * V_47 ,
T_1 V_56 , T_1 V_57 , void * V_58 )
{
struct V_59 * V_60 ;
struct V_61 * V_62 = V_58 ;
struct V_52 * V_48 = V_47 -> V_48 ;
T_1 V_63 =
F_46 ( V_48 -> V_64 ) >> V_65 ;
unsigned short V_66 =
V_62 -> V_67 >> V_65 ;
char V_68 [ V_69 ] ;
V_60 = F_47 ( V_48 ) ;
if ( ! V_60 || ! V_60 -> V_70 ) {
F_20 ( L_3
L_4 ,
F_48 ( V_55 -> V_71 -> V_30 ) , F_49 ( V_48 , V_68 ) ,
( unsigned long long ) V_56 ,
( unsigned long long ) V_57 ,
( unsigned long long ) V_63 ) ;
return 1 ;
}
if ( ! V_63 )
return 0 ;
if ( ( V_56 >= V_63 ) || ( V_56 + V_57 > V_63 ) ) {
F_20 ( L_5
L_4 ,
F_48 ( V_55 -> V_71 -> V_30 ) , F_49 ( V_48 , V_68 ) ,
( unsigned long long ) V_56 ,
( unsigned long long ) V_57 ,
( unsigned long long ) V_63 ) ;
return 1 ;
}
if ( V_66 <= 1 )
return 0 ;
if ( V_56 & ( V_66 - 1 ) ) {
F_20 ( L_6
L_7 ,
F_48 ( V_55 -> V_71 -> V_30 ) ,
( unsigned long long ) V_56 ,
V_62 -> V_67 , F_49 ( V_48 , V_68 ) ) ;
return 1 ;
}
if ( V_57 & ( V_66 - 1 ) ) {
F_20 ( L_8
L_7 ,
F_48 ( V_55 -> V_71 -> V_30 ) ,
( unsigned long long ) V_57 ,
V_62 -> V_67 , F_49 ( V_48 , V_68 ) ) ;
return 1 ;
}
return 0 ;
}
static int F_50 ( struct V_38 * V_39 , T_2 V_72 ,
struct V_29 * V_30 )
{
int V_53 ;
struct V_38 V_73 , V_74 ;
V_73 = V_74 = * V_39 ;
V_73 . V_41 . V_28 |= V_72 ;
V_73 . V_41 . V_48 = NULL ;
V_53 = F_35 ( & V_73 , V_39 -> V_41 . V_48 -> V_49 , V_30 ) ;
if ( V_53 )
return V_53 ;
V_39 -> V_41 . V_28 |= V_72 ;
F_43 ( & V_74 , V_30 ) ;
return 0 ;
}
int F_51 ( struct V_21 * V_55 , const char * V_75 , T_2 V_28 ,
struct V_41 * * V_3 )
{
int V_53 ;
T_3 V_76 ( V_47 ) ;
struct V_38 * V_39 ;
unsigned int V_77 , V_78 ;
struct V_6 * V_7 = V_55 -> V_71 ;
char V_79 ;
F_36 ( ! V_7 ) ;
if ( sscanf ( V_75 , L_9 , & V_77 , & V_78 , & V_79 ) == 2 ) {
V_47 = F_52 ( V_77 , V_78 ) ;
if ( F_53 ( V_47 ) != V_77 || F_54 ( V_47 ) != V_78 )
return - V_80 ;
} else {
struct V_52 * V_48 = F_55 ( V_75 ) ;
if ( F_38 ( V_48 ) )
return F_39 ( V_48 ) ;
V_47 = V_48 -> V_49 ;
F_56 ( V_48 ) ;
}
V_39 = F_33 ( & V_7 -> V_32 , V_47 ) ;
if ( ! V_39 ) {
V_39 = F_57 ( sizeof( * V_39 ) , V_31 ) ;
if ( ! V_39 )
return - V_24 ;
V_39 -> V_41 . V_28 = V_28 ;
V_39 -> V_41 . V_48 = NULL ;
if ( ( V_53 = F_35 ( V_39 , V_47 , V_7 -> V_30 ) ) ) {
F_16 ( V_39 ) ;
return V_53 ;
}
F_58 ( V_39 -> V_41 . V_42 , V_47 ) ;
F_14 ( & V_39 -> V_81 , 0 ) ;
F_59 ( & V_39 -> V_40 , & V_7 -> V_32 ) ;
} else if ( V_39 -> V_41 . V_28 != ( V_28 | V_39 -> V_41 . V_28 ) ) {
V_53 = F_50 ( V_39 , V_28 , V_7 -> V_30 ) ;
if ( V_53 )
return V_53 ;
}
F_28 ( & V_39 -> V_81 ) ;
* V_3 = & V_39 -> V_41 ;
return 0 ;
}
int F_60 ( struct V_21 * V_55 , struct V_41 * V_47 ,
T_1 V_56 , T_1 V_57 , void * V_58 )
{
struct V_61 * V_62 = V_58 ;
struct V_52 * V_48 = V_47 -> V_48 ;
struct V_59 * V_60 = F_47 ( V_48 ) ;
char V_68 [ V_69 ] ;
if ( F_61 ( ! V_60 ) ) {
F_20 ( L_10 ,
F_48 ( V_55 -> V_71 -> V_30 ) , F_49 ( V_48 , V_68 ) ) ;
return 0 ;
}
if ( F_62 ( V_62 , V_48 , V_56 ) < 0 )
F_20 ( L_11
L_12
L_13 ,
F_48 ( V_55 -> V_71 -> V_30 ) , F_49 ( V_48 , V_68 ) ,
V_60 -> V_62 . V_82 ,
V_60 -> V_62 . V_67 ,
V_60 -> V_62 . V_83 ,
( unsigned long long ) V_56 << V_65 ) ;
if ( F_63 ( V_60 ) && ! V_55 -> type -> V_84 )
F_64 ( V_62 ,
( unsigned int ) ( V_85 >> 9 ) ) ;
return 0 ;
}
void F_65 ( struct V_21 * V_55 , struct V_41 * V_50 )
{
struct V_38 * V_39 = F_66 ( V_50 , struct V_38 ,
V_41 ) ;
if ( F_67 ( & V_39 -> V_81 ) ) {
F_43 ( V_39 , V_55 -> V_71 -> V_30 ) ;
F_68 ( & V_39 -> V_40 ) ;
F_16 ( V_39 ) ;
}
}
static int F_69 ( struct V_6 * V_71 , struct V_21 * V_55 )
{
struct V_21 * V_86 ;
if ( ! V_71 -> V_23 )
return ! V_55 -> V_87 ;
V_86 = & V_71 -> V_26 [ V_71 -> V_23 - 1 ] ;
return ( V_55 -> V_87 == ( V_86 -> V_87 + V_86 -> V_57 ) ) ;
}
static char * * F_70 ( unsigned * V_88 , char * * V_89 )
{
char * * V_90 ;
unsigned V_91 ;
V_91 = * V_88 ? * V_88 * 2 : 64 ;
V_90 = F_57 ( V_91 * sizeof( * V_90 ) , V_31 ) ;
if ( V_90 ) {
memcpy ( V_90 , V_89 , * V_88 * sizeof( * V_90 ) ) ;
* V_88 = V_91 ;
}
F_16 ( V_89 ) ;
return V_90 ;
}
int F_71 ( int * V_92 , char * * * V_93 , char * V_94 )
{
char * V_56 , * V_95 = V_94 , * V_96 , * * V_90 = NULL ;
unsigned V_88 = 0 ;
* V_92 = 0 ;
if ( ! V_94 ) {
* V_93 = NULL ;
return 0 ;
}
V_90 = F_70 ( & V_88 , V_90 ) ;
if ( ! V_90 )
return - V_24 ;
while ( 1 ) {
V_56 = F_72 ( V_95 ) ;
if ( ! * V_56 )
break;
V_95 = V_96 = V_56 ;
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
if ( ( * V_92 + 1 ) > V_88 ) {
V_90 = F_70 ( & V_88 , V_90 ) ;
if ( ! V_90 )
return - V_24 ;
}
if ( * V_95 )
V_95 ++ ;
* V_96 = '\0' ;
V_90 [ * V_92 ] = V_56 ;
( * V_92 ) ++ ;
}
* V_93 = V_90 ;
return 0 ;
}
static int F_73 ( struct V_6 * V_71 ,
struct V_61 * V_62 )
{
unsigned short V_97 =
V_62 -> V_67 >> V_65 ;
unsigned short V_98 = 0 ;
unsigned short V_99 = 0 ;
struct V_21 * V_76 ( V_55 ) ;
struct V_61 V_100 ;
unsigned V_43 = 0 ;
while ( V_43 < F_74 ( V_71 ) ) {
V_55 = F_75 ( V_71 , V_43 ++ ) ;
F_76 ( & V_100 ) ;
if ( V_55 -> type -> V_101 )
V_55 -> type -> V_101 ( V_55 , F_60 ,
& V_100 ) ;
if ( V_99 < V_55 -> V_57 &&
V_99 & ( ( V_100 . V_67 >>
V_65 ) - 1 ) )
break;
V_98 =
( unsigned short ) ( ( V_98 + V_55 -> V_57 ) &
( V_97 - 1 ) ) ;
V_99 = V_98 ?
V_97 - V_98 : 0 ;
}
if ( V_99 ) {
F_20 ( L_14
L_15 ,
F_48 ( V_71 -> V_30 ) , V_43 ,
( unsigned long long ) V_55 -> V_87 ,
( unsigned long long ) V_55 -> V_57 ,
V_62 -> V_67 ) ;
return - V_102 ;
}
return 0 ;
}
int F_77 ( struct V_6 * V_7 , const char * type ,
T_1 V_56 , T_1 V_57 , char * V_103 )
{
int V_53 = - V_102 , V_92 ;
char * * V_90 ;
struct V_21 * V_44 ;
if ( V_7 -> V_104 ) {
F_78 ( L_16 ,
F_48 ( V_7 -> V_30 ) , V_7 -> V_26 -> type -> V_42 ) ;
return - V_102 ;
}
if ( ( V_53 = F_32 ( V_7 ) ) )
return V_53 ;
V_44 = V_7 -> V_26 + V_7 -> V_23 ;
memset ( V_44 , 0 , sizeof( * V_44 ) ) ;
if ( ! V_57 ) {
F_78 ( L_17 , F_48 ( V_7 -> V_30 ) ) ;
return - V_102 ;
}
V_44 -> type = F_79 ( type ) ;
if ( ! V_44 -> type ) {
F_78 ( L_18 , F_48 ( V_7 -> V_30 ) ,
type ) ;
return - V_102 ;
}
if ( F_80 ( V_44 -> type ) ) {
if ( V_7 -> V_23 ) {
F_78 ( L_16 ,
F_48 ( V_7 -> V_30 ) , type ) ;
return - V_102 ;
}
V_7 -> V_104 = 1 ;
}
if ( F_81 ( V_44 -> type ) && ! ( V_7 -> V_28 & V_105 ) ) {
F_78 ( L_19 ,
F_48 ( V_7 -> V_30 ) , type ) ;
return - V_102 ;
}
if ( V_7 -> V_106 ) {
if ( V_7 -> V_106 != V_44 -> type ) {
F_78 ( L_20 ,
F_48 ( V_7 -> V_30 ) , V_7 -> V_106 -> V_42 ) ;
return - V_102 ;
}
} else if ( F_82 ( V_44 -> type ) ) {
if ( V_7 -> V_23 ) {
F_78 ( L_20 ,
F_48 ( V_7 -> V_30 ) , V_44 -> type -> V_42 ) ;
return - V_102 ;
}
V_7 -> V_106 = V_44 -> type ;
}
V_44 -> V_71 = V_7 ;
V_44 -> V_87 = V_56 ;
V_44 -> V_57 = V_57 ;
V_44 -> error = L_21 ;
if ( ! F_69 ( V_7 , V_44 ) ) {
V_44 -> error = L_22 ;
V_53 = - V_102 ;
goto V_107;
}
V_53 = F_71 ( & V_92 , & V_90 , V_103 ) ;
if ( V_53 ) {
V_44 -> error = L_23 ;
goto V_107;
}
V_53 = V_44 -> type -> V_108 ( V_44 , V_92 , V_90 ) ;
F_16 ( V_90 ) ;
if ( V_53 )
goto V_107;
V_7 -> V_25 [ V_7 -> V_23 ++ ] = V_44 -> V_87 + V_44 -> V_57 - 1 ;
if ( ! V_44 -> V_109 && V_44 -> V_110 )
F_20 ( L_24 ,
F_48 ( V_7 -> V_30 ) , type ) ;
return 0 ;
V_107:
F_78 ( L_25 , F_48 ( V_7 -> V_30 ) , type , V_44 -> error ) ;
F_25 ( V_44 -> type ) ;
return V_53 ;
}
static int F_83 ( struct V_111 * V_112 , struct V_113 * V_114 ,
unsigned * V_115 , char * * error , unsigned V_116 )
{
const char * V_117 = F_84 ( V_114 ) ;
char V_79 ;
if ( ! V_117 ||
( sscanf ( V_117 , L_26 , V_115 , & V_79 ) != 1 ) ||
( * V_115 < V_112 -> V_118 ) ||
( * V_115 > V_112 -> V_119 ) ||
( V_116 && V_114 -> V_92 < * V_115 ) ) {
* error = V_112 -> error ;
return - V_102 ;
}
return 0 ;
}
int F_85 ( struct V_111 * V_112 , struct V_113 * V_114 ,
unsigned * V_115 , char * * error )
{
return F_83 ( V_112 , V_114 , V_115 , error , 0 ) ;
}
int F_86 ( struct V_111 * V_112 , struct V_113 * V_114 ,
unsigned * V_115 , char * * error )
{
return F_83 ( V_112 , V_114 , V_115 , error , 1 ) ;
}
const char * F_84 ( struct V_113 * V_120 )
{
char * V_53 ;
if ( V_120 -> V_92 ) {
V_120 -> V_92 -- ;
V_53 = * V_120 -> V_90 ;
V_120 -> V_90 ++ ;
return V_53 ;
}
return NULL ;
}
void F_87 ( struct V_113 * V_120 , unsigned V_121 )
{
F_36 ( V_120 -> V_92 < V_121 ) ;
V_120 -> V_92 -= V_121 ;
V_120 -> V_90 += V_121 ;
}
static int F_88 ( struct V_6 * V_7 )
{
unsigned V_43 ;
unsigned V_122 = 0 , V_123 = 0 ;
struct V_21 * V_44 ;
struct V_38 * V_39 ;
struct V_35 * V_32 ;
for ( V_43 = 0 ; V_43 < V_7 -> V_23 ; V_43 ++ ) {
V_44 = V_7 -> V_26 + V_43 ;
if ( F_89 ( V_44 ) )
V_123 = 1 ;
else
V_122 = 1 ;
if ( V_122 && V_123 ) {
F_20 ( L_27
L_28 ) ;
return - V_102 ;
}
}
if ( V_122 ) {
V_7 -> type = V_124 ;
return 0 ;
}
F_36 ( ! V_123 ) ;
V_32 = F_90 ( V_7 ) ;
F_34 (dd, devices, list) {
if ( ! F_91 ( F_47 ( V_39 -> V_41 . V_48 ) ) ) {
F_20 ( L_29
L_30 ) ;
return - V_102 ;
}
}
if ( V_7 -> V_23 > 1 ) {
F_20 ( L_31 ) ;
return - V_102 ;
}
V_7 -> type = V_125 ;
return 0 ;
}
unsigned F_92 ( struct V_6 * V_7 )
{
return V_7 -> type ;
}
struct V_126 * F_93 ( struct V_6 * V_7 )
{
return V_7 -> V_106 ;
}
bool F_94 ( struct V_6 * V_7 )
{
return F_92 ( V_7 ) == V_125 ;
}
int F_95 ( struct V_6 * V_7 )
{
unsigned type = F_92 ( V_7 ) ;
unsigned V_127 = 0 ;
struct V_21 * V_44 ;
unsigned V_43 ;
if ( F_61 ( type == V_128 ) ) {
F_20 ( L_32 ) ;
return - V_102 ;
}
if ( type == V_124 )
for ( V_43 = 0 ; V_43 < V_7 -> V_23 ; V_43 ++ ) {
V_44 = V_7 -> V_26 + V_43 ;
V_127 = V_119 ( V_127 , V_44 -> V_127 ) ;
}
V_7 -> V_46 = F_96 ( type , V_7 -> V_129 , V_127 ) ;
if ( ! V_7 -> V_46 )
return - V_24 ;
return 0 ;
}
void F_97 ( struct V_6 * V_7 )
{
F_26 ( V_7 -> V_46 ) ;
V_7 -> V_46 = NULL ;
}
struct V_130 * F_98 ( struct V_6 * V_7 )
{
return V_7 -> V_46 ;
}
static int F_99 ( struct V_6 * V_7 )
{
int V_43 ;
unsigned int V_131 = 0 ;
T_1 * V_132 ;
for ( V_43 = V_7 -> V_11 - 2 ; V_43 >= 0 ; V_43 -- ) {
V_7 -> V_12 [ V_43 ] = F_2 ( V_7 -> V_12 [ V_43 + 1 ] , V_5 ) ;
V_131 += V_7 -> V_12 [ V_43 ] ;
}
V_132 = ( T_1 * ) F_7 ( V_131 , ( unsigned long ) V_133 ) ;
if ( ! V_132 )
return - V_24 ;
for ( V_43 = V_7 -> V_11 - 2 ; V_43 >= 0 ; V_43 -- ) {
V_7 -> V_9 [ V_43 ] = V_132 ;
V_132 += ( V_10 * V_7 -> V_12 [ V_43 ] ) ;
F_6 ( V_43 , V_7 ) ;
}
return 0 ;
}
static int F_100 ( struct V_6 * V_7 )
{
int V_53 = 0 ;
unsigned int V_134 ;
V_134 = F_2 ( V_7 -> V_23 , V_10 ) ;
V_7 -> V_11 = 1 + F_1 ( V_134 , V_5 ) ;
V_7 -> V_12 [ V_7 -> V_11 - 1 ] = V_134 ;
V_7 -> V_9 [ V_7 -> V_11 - 1 ] = V_7 -> V_25 ;
if ( V_7 -> V_11 >= 2 )
V_53 = F_99 ( V_7 ) ;
return V_53 ;
}
static struct V_135 * F_101 ( struct V_6 * V_7 ,
bool V_136 )
{
struct V_35 * V_32 = F_90 ( V_7 ) ;
struct V_38 * V_39 = NULL ;
struct V_135 * V_137 = NULL , * V_138 = NULL ;
F_34 (dd, devices, list) {
V_138 = V_39 -> V_41 . V_48 -> V_139 ;
if ( ! F_102 ( V_138 ) )
goto V_140;
if ( ! V_136 && ! F_103 ( V_138 ) )
continue;
else if ( V_137 &&
F_104 ( V_137 , V_138 ) < 0 )
goto V_140;
V_137 = V_138 ;
}
return V_138 ;
V_140:
if ( V_137 )
F_20 ( L_33 ,
F_48 ( V_7 -> V_30 ) ,
V_137 -> V_141 ,
V_138 -> V_141 ) ;
return NULL ;
}
static int F_105 ( struct V_6 * V_7 , struct V_29 * V_30 )
{
struct V_135 * V_138 = NULL ;
V_138 = F_101 ( V_7 , false ) ;
if ( ! V_138 )
return 0 ;
if ( ! F_103 ( F_41 ( V_30 ) ) ) {
V_7 -> V_129 = 1 ;
return F_106 ( F_41 ( V_30 ) , NULL ) ;
}
if ( F_103 ( V_138 ) &&
F_104 ( F_41 ( V_30 ) , V_138 ) < 0 ) {
F_20 ( L_34
L_35 ,
F_48 ( V_7 -> V_30 ) ,
V_138 -> V_141 ) ;
return 1 ;
}
V_7 -> V_129 = 1 ;
return 0 ;
}
int F_107 ( struct V_6 * V_7 )
{
int V_53 ;
V_53 = F_88 ( V_7 ) ;
if ( V_53 ) {
F_78 ( L_36 ) ;
return V_53 ;
}
V_53 = F_100 ( V_7 ) ;
if ( V_53 ) {
F_78 ( L_37 ) ;
return V_53 ;
}
V_53 = F_105 ( V_7 , V_7 -> V_30 ) ;
if ( V_53 ) {
F_78 ( L_38 ) ;
return V_53 ;
}
V_53 = F_95 ( V_7 ) ;
if ( V_53 )
F_78 ( L_39 ) ;
return V_53 ;
}
void F_108 ( struct V_6 * V_7 ,
void (* F_109)( void * ) , void * V_142 )
{
F_110 ( & V_143 ) ;
V_7 -> V_144 = F_109 ;
V_7 -> V_145 = V_142 ;
F_111 ( & V_143 ) ;
}
void F_112 ( struct V_6 * V_7 )
{
F_36 ( F_113 () ) ;
F_110 ( & V_143 ) ;
if ( V_7 -> V_144 )
V_7 -> V_144 ( V_7 -> V_145 ) ;
F_111 ( & V_143 ) ;
}
T_1 F_114 ( struct V_6 * V_7 )
{
return V_7 -> V_23 ? ( V_7 -> V_25 [ V_7 -> V_23 - 1 ] + 1 ) : 0 ;
}
struct V_21 * F_75 ( struct V_6 * V_7 , unsigned int V_9 )
{
if ( V_9 >= V_7 -> V_23 )
return NULL ;
return V_7 -> V_26 + V_9 ;
}
struct V_21 * F_115 ( struct V_6 * V_7 , T_1 V_146 )
{
unsigned int V_8 , V_1 = 0 , V_4 = 0 ;
T_1 * V_13 ;
for ( V_8 = 0 ; V_8 < V_7 -> V_11 ; V_8 ++ ) {
V_1 = F_3 ( V_1 , V_4 ) ;
V_13 = F_4 ( V_7 , V_8 , V_1 ) ;
for ( V_4 = 0 ; V_4 < V_10 ; V_4 ++ )
if ( V_13 [ V_4 ] >= V_146 )
break;
}
return & V_7 -> V_26 [ ( V_10 * V_1 ) + V_4 ] ;
}
static int F_116 ( struct V_21 * V_55 , struct V_41 * V_47 ,
T_1 V_56 , T_1 V_57 , void * V_58 )
{
unsigned * V_147 = V_58 ;
( * V_147 ) ++ ;
return 0 ;
}
bool F_117 ( struct V_6 * V_71 )
{
struct V_21 * V_76 ( V_55 ) ;
unsigned V_43 = 0 , V_147 = 0 ;
while ( V_43 < F_74 ( V_71 ) ) {
V_55 = F_75 ( V_71 , V_43 ++ ) ;
if ( ! V_55 -> type -> V_101 )
return false ;
V_55 -> type -> V_101 ( V_55 , F_116 , & V_147 ) ;
if ( V_147 )
return false ;
}
return true ;
}
int F_118 ( struct V_6 * V_71 ,
struct V_61 * V_62 )
{
struct V_21 * V_76 ( V_55 ) ;
struct V_61 V_100 ;
unsigned V_43 = 0 ;
F_76 ( V_62 ) ;
while ( V_43 < F_74 ( V_71 ) ) {
F_76 ( & V_100 ) ;
V_55 = F_75 ( V_71 , V_43 ++ ) ;
if ( ! V_55 -> type -> V_101 )
goto V_148;
V_55 -> type -> V_101 ( V_55 , F_60 ,
& V_100 ) ;
if ( V_55 -> type -> V_149 )
V_55 -> type -> V_149 ( V_55 , & V_100 ) ;
if ( V_55 -> type -> V_101 ( V_55 , F_45 ,
& V_100 ) )
return - V_102 ;
V_148:
if ( F_119 ( V_62 , & V_100 , 0 ) < 0 )
F_20 ( L_40
L_41
L_42 ,
F_48 ( V_71 -> V_30 ) ,
( unsigned long long ) V_55 -> V_87 ,
( unsigned long long ) V_55 -> V_57 ) ;
}
return F_73 ( V_71 , V_62 ) ;
}
static void F_120 ( struct V_6 * V_7 )
{
struct V_135 * V_138 = NULL ;
if ( ! F_102 ( F_41 ( V_7 -> V_30 ) ) )
return;
V_138 = F_101 ( V_7 , true ) ;
if ( V_138 )
F_106 ( F_41 ( V_7 -> V_30 ) ,
F_102 ( V_138 ) ) ;
else if ( F_103 ( F_41 ( V_7 -> V_30 ) ) )
F_20 ( L_43 ,
F_48 ( V_7 -> V_30 ) ) ;
else
F_20 ( L_44 ,
F_48 ( V_7 -> V_30 ) ) ;
}
static int F_121 ( struct V_21 * V_55 , struct V_41 * V_47 ,
T_1 V_56 , T_1 V_57 , void * V_58 )
{
unsigned V_150 = ( * ( unsigned * ) V_58 ) ;
struct V_59 * V_60 = F_47 ( V_47 -> V_48 ) ;
return V_60 && ( V_60 -> V_151 & V_150 ) ;
}
static bool F_122 ( struct V_6 * V_7 , unsigned V_150 )
{
struct V_21 * V_55 ;
unsigned V_43 = 0 ;
while ( V_43 < F_74 ( V_7 ) ) {
V_55 = F_75 ( V_7 , V_43 ++ ) ;
if ( ! V_55 -> V_152 )
continue;
if ( V_55 -> V_153 )
return 1 ;
if ( V_55 -> type -> V_101 &&
V_55 -> type -> V_101 ( V_55 , F_121 , & V_150 ) )
return 1 ;
}
return 0 ;
}
static bool F_123 ( struct V_6 * V_7 )
{
struct V_21 * V_55 ;
unsigned V_43 = 0 ;
while ( V_43 < F_74 ( V_7 ) ) {
V_55 = F_75 ( V_7 , V_43 ++ ) ;
if ( V_55 -> V_154 )
return 0 ;
}
return 1 ;
}
static int F_124 ( struct V_21 * V_55 , struct V_41 * V_47 ,
T_1 V_56 , T_1 V_57 , void * V_58 )
{
struct V_59 * V_60 = F_47 ( V_47 -> V_48 ) ;
return V_60 && F_125 ( V_60 ) ;
}
static int F_126 ( struct V_21 * V_55 , struct V_41 * V_47 ,
T_1 V_56 , T_1 V_57 , void * V_58 )
{
struct V_59 * V_60 = F_47 ( V_47 -> V_48 ) ;
return V_60 && ! F_127 ( V_60 ) ;
}
static bool F_128 ( struct V_6 * V_7 ,
T_4 V_155 )
{
struct V_21 * V_55 ;
unsigned V_43 = 0 ;
while ( V_43 < F_74 ( V_7 ) ) {
V_55 = F_75 ( V_7 , V_43 ++ ) ;
if ( ! V_55 -> type -> V_101 ||
! V_55 -> type -> V_101 ( V_55 , V_155 , NULL ) )
return 0 ;
}
return 1 ;
}
static int F_129 ( struct V_21 * V_55 , struct V_41 * V_47 ,
T_1 V_56 , T_1 V_57 , void * V_58 )
{
struct V_59 * V_60 = F_47 ( V_47 -> V_48 ) ;
return V_60 && ! V_60 -> V_62 . V_156 ;
}
static bool F_130 ( struct V_6 * V_7 )
{
struct V_21 * V_55 ;
unsigned V_43 = 0 ;
while ( V_43 < F_74 ( V_7 ) ) {
V_55 = F_75 ( V_7 , V_43 ++ ) ;
if ( ! V_55 -> V_157 )
return false ;
if ( ! V_55 -> type -> V_101 ||
! V_55 -> type -> V_101 ( V_55 , F_129 , NULL ) )
return false ;
}
return true ;
}
void F_131 ( struct V_6 * V_7 , struct V_59 * V_60 ,
struct V_61 * V_62 )
{
unsigned V_150 = 0 ;
V_60 -> V_62 = * V_62 ;
if ( ! F_132 ( V_7 ) )
F_133 ( V_158 , V_60 ) ;
else
F_134 ( V_158 , V_60 ) ;
if ( F_122 ( V_7 , V_159 ) ) {
V_150 |= V_159 ;
if ( F_122 ( V_7 , V_160 ) )
V_150 |= V_160 ;
}
F_135 ( V_60 , V_150 ) ;
if ( ! F_123 ( V_7 ) )
V_60 -> V_62 . V_161 = 0 ;
if ( F_128 ( V_7 , F_124 ) )
F_134 ( V_162 , V_60 ) ;
else
F_133 ( V_162 , V_60 ) ;
if ( ! F_130 ( V_7 ) )
V_60 -> V_62 . V_156 = 0 ;
F_120 ( V_7 ) ;
if ( F_127 ( V_60 ) && F_128 ( V_7 , F_126 ) )
F_133 ( V_163 , V_60 ) ;
F_24 () ;
if ( F_94 ( V_7 ) )
F_134 ( V_164 , V_60 ) ;
}
unsigned int F_74 ( struct V_6 * V_7 )
{
return V_7 -> V_23 ;
}
struct V_35 * F_90 ( struct V_6 * V_7 )
{
return & V_7 -> V_32 ;
}
T_2 F_136 ( struct V_6 * V_7 )
{
return V_7 -> V_28 ;
}
static void F_137 ( struct V_6 * V_7 , unsigned V_165 )
{
int V_43 = V_7 -> V_23 ;
struct V_21 * V_55 = V_7 -> V_26 ;
while ( V_43 -- ) {
if ( V_165 ) {
if ( V_55 -> type -> V_165 )
V_55 -> type -> V_165 ( V_55 ) ;
} else if ( V_55 -> type -> V_166 )
V_55 -> type -> V_166 ( V_55 ) ;
V_55 ++ ;
}
}
void F_138 ( struct V_6 * V_7 )
{
if ( ! V_7 )
return;
F_137 ( V_7 , 0 ) ;
}
void F_139 ( struct V_6 * V_7 )
{
if ( ! V_7 )
return;
F_137 ( V_7 , 1 ) ;
}
int F_140 ( struct V_6 * V_7 )
{
int V_43 , V_53 = 0 ;
for ( V_43 = 0 ; V_43 < V_7 -> V_23 ; V_43 ++ ) {
struct V_21 * V_55 = V_7 -> V_26 + V_43 ;
if ( ! V_55 -> type -> V_167 )
continue;
V_53 = V_55 -> type -> V_167 ( V_55 ) ;
if ( V_53 )
return V_53 ;
}
for ( V_43 = 0 ; V_43 < V_7 -> V_23 ; V_43 ++ ) {
struct V_21 * V_55 = V_7 -> V_26 + V_43 ;
if ( V_55 -> type -> V_168 )
V_55 -> type -> V_168 ( V_55 ) ;
}
return 0 ;
}
void F_141 ( struct V_6 * V_7 , struct V_169 * V_170 )
{
F_59 ( & V_170 -> V_40 , & V_7 -> V_33 ) ;
}
int F_142 ( struct V_6 * V_7 , int V_171 )
{
struct V_38 * V_39 ;
struct V_35 * V_32 = F_90 ( V_7 ) ;
struct V_169 * V_170 ;
int V_53 = 0 ;
F_34 (dd, devices, list) {
struct V_59 * V_60 = F_47 ( V_39 -> V_41 . V_48 ) ;
char V_68 [ V_69 ] ;
if ( F_143 ( V_60 ) )
V_53 |= F_144 ( & V_60 -> V_172 , V_171 ) ;
else
F_145 ( L_45 ,
F_48 ( V_7 -> V_30 ) ,
F_49 ( V_39 -> V_41 . V_48 , V_68 ) ) ;
}
F_34 (cb, &t->target_callbacks, list)
if ( V_170 -> V_173 )
V_53 |= V_170 -> V_173 ( V_170 , V_171 ) ;
return V_53 ;
}
int F_146 ( struct V_6 * V_7 )
{
unsigned V_43 ;
struct V_21 * V_55 ;
for ( V_43 = 0 ; V_43 < V_7 -> V_23 ; V_43 ++ ) {
V_55 = V_7 -> V_26 + V_43 ;
if ( V_55 -> type -> V_174 && V_55 -> type -> V_174 ( V_55 ) )
return 1 ;
}
return 0 ;
}
struct V_29 * F_147 ( struct V_6 * V_7 )
{
return V_7 -> V_30 ;
}
static int F_148 ( struct V_21 * V_55 , struct V_41 * V_47 ,
T_1 V_56 , T_1 V_57 , void * V_58 )
{
struct V_59 * V_60 = F_47 ( V_47 -> V_48 ) ;
return V_60 && F_149 ( V_60 ) ;
}
bool F_132 ( struct V_6 * V_7 )
{
struct V_21 * V_55 ;
unsigned V_43 = 0 ;
while ( V_43 < F_74 ( V_7 ) ) {
V_55 = F_75 ( V_7 , V_43 ++ ) ;
if ( ! V_55 -> V_109 )
continue;
if ( V_55 -> V_110 )
return 1 ;
if ( V_55 -> type -> V_101 &&
V_55 -> type -> V_101 ( V_55 , F_148 , NULL ) )
return 1 ;
}
return 0 ;
}
