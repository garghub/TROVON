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
if ( ! V_23 )
V_23 = V_10 ;
V_23 = F_14 ( V_23 , V_10 ) ;
if ( F_9 ( V_7 , V_23 ) ) {
F_15 ( V_7 ) ;
return - V_24 ;
}
V_7 -> V_28 = V_28 ;
V_7 -> V_30 = V_30 ;
* V_3 = V_7 ;
return 0 ;
}
static void F_16 ( struct V_34 * V_32 )
{
struct V_34 * V_35 , * V_36 ;
F_17 (tmp, next, devices) {
struct V_37 * V_38 =
F_18 ( V_35 , struct V_37 , V_39 ) ;
F_19 ( L_1 ,
V_38 -> V_40 . V_41 ) ;
F_15 ( V_38 ) ;
}
}
void F_20 ( struct V_6 * V_7 )
{
unsigned int V_42 ;
if ( ! V_7 )
return;
if ( V_7 -> V_11 >= 2 )
F_10 ( V_7 -> V_9 [ V_7 -> V_11 - 2 ] ) ;
for ( V_42 = 0 ; V_42 < V_7 -> V_23 ; V_42 ++ ) {
struct V_21 * V_43 = V_7 -> V_26 + V_42 ;
if ( V_43 -> type -> V_44 )
V_43 -> type -> V_44 ( V_43 ) ;
F_21 ( V_43 -> type ) ;
}
F_10 ( V_7 -> V_25 ) ;
F_16 ( & V_7 -> V_32 ) ;
F_22 ( V_7 -> V_45 ) ;
F_15 ( V_7 ) ;
}
static inline int F_23 ( struct V_6 * V_7 )
{
if ( V_7 -> V_23 >= V_7 -> V_27 )
return F_9 ( V_7 , V_7 -> V_27 * 2 ) ;
return 0 ;
}
static struct V_37 * F_24 ( struct V_34 * V_8 , T_3 V_46 )
{
struct V_37 * V_38 ;
F_25 (dd, l, list)
if ( V_38 -> V_40 . V_47 -> V_48 == V_46 )
return V_38 ;
return NULL ;
}
static int F_26 ( struct V_37 * V_49 , T_3 V_46 ,
struct V_29 * V_30 )
{
static char * V_50 = L_2 ;
struct V_51 * V_47 ;
int V_52 ;
F_27 ( V_49 -> V_40 . V_47 ) ;
V_47 = F_28 ( V_46 , V_49 -> V_40 . V_28 | V_53 , V_50 ) ;
if ( F_29 ( V_47 ) )
return F_30 ( V_47 ) ;
V_52 = F_31 ( V_47 , F_32 ( V_30 ) ) ;
if ( V_52 ) {
F_33 ( V_47 , V_49 -> V_40 . V_28 | V_53 ) ;
return V_52 ;
}
V_49 -> V_40 . V_47 = V_47 ;
return 0 ;
}
static void F_34 ( struct V_37 * V_49 , struct V_29 * V_30 )
{
if ( ! V_49 -> V_40 . V_47 )
return;
F_35 ( V_49 -> V_40 . V_47 , F_32 ( V_30 ) ) ;
F_33 ( V_49 -> V_40 . V_47 , V_49 -> V_40 . V_28 | V_53 ) ;
V_49 -> V_40 . V_47 = NULL ;
}
static int F_36 ( struct V_21 * V_54 , struct V_40 * V_46 ,
T_1 V_55 , T_1 V_56 , void * V_57 )
{
struct V_58 * V_59 ;
struct V_60 * V_61 = V_57 ;
struct V_51 * V_47 = V_46 -> V_47 ;
T_1 V_62 =
F_37 ( V_47 -> V_63 ) >> V_64 ;
unsigned short V_65 =
V_61 -> V_66 >> V_64 ;
char V_67 [ V_68 ] ;
V_59 = F_38 ( V_47 ) ;
if ( ! V_59 || ! V_59 -> V_69 ) {
F_19 ( L_3
L_4 ,
F_39 ( V_54 -> V_70 -> V_30 ) , F_40 ( V_47 , V_67 ) ,
( unsigned long long ) V_55 ,
( unsigned long long ) V_56 ,
( unsigned long long ) V_62 ) ;
return 1 ;
}
if ( ! V_62 )
return 0 ;
if ( ( V_55 >= V_62 ) || ( V_55 + V_56 > V_62 ) ) {
F_19 ( L_5
L_4 ,
F_39 ( V_54 -> V_70 -> V_30 ) , F_40 ( V_47 , V_67 ) ,
( unsigned long long ) V_55 ,
( unsigned long long ) V_56 ,
( unsigned long long ) V_62 ) ;
return 1 ;
}
if ( V_65 <= 1 )
return 0 ;
if ( V_55 & ( V_65 - 1 ) ) {
F_19 ( L_6
L_7 ,
F_39 ( V_54 -> V_70 -> V_30 ) ,
( unsigned long long ) V_55 ,
V_61 -> V_66 , F_40 ( V_47 , V_67 ) ) ;
return 1 ;
}
if ( V_56 & ( V_65 - 1 ) ) {
F_19 ( L_8
L_7 ,
F_39 ( V_54 -> V_70 -> V_30 ) ,
( unsigned long long ) V_56 ,
V_61 -> V_66 , F_40 ( V_47 , V_67 ) ) ;
return 1 ;
}
return 0 ;
}
static int F_41 ( struct V_37 * V_38 , T_2 V_71 ,
struct V_29 * V_30 )
{
int V_52 ;
struct V_37 V_72 , V_73 ;
V_72 = V_73 = * V_38 ;
V_72 . V_40 . V_28 |= V_71 ;
V_72 . V_40 . V_47 = NULL ;
V_52 = F_26 ( & V_72 , V_38 -> V_40 . V_47 -> V_48 , V_30 ) ;
if ( V_52 )
return V_52 ;
V_38 -> V_40 . V_28 |= V_71 ;
F_34 ( & V_73 , V_30 ) ;
return 0 ;
}
int F_42 ( struct V_21 * V_54 , const char * V_74 , T_2 V_28 ,
struct V_40 * * V_3 )
{
int V_52 ;
T_3 V_75 ( V_46 ) ;
struct V_37 * V_38 ;
unsigned int V_76 , V_77 ;
struct V_6 * V_7 = V_54 -> V_70 ;
char V_78 ;
F_27 ( ! V_7 ) ;
if ( sscanf ( V_74 , L_9 , & V_76 , & V_77 , & V_78 ) == 2 ) {
V_46 = F_43 ( V_76 , V_77 ) ;
if ( F_44 ( V_46 ) != V_76 || F_45 ( V_46 ) != V_77 )
return - V_79 ;
} else {
struct V_51 * V_47 = F_46 ( V_74 ) ;
if ( F_29 ( V_47 ) )
return F_30 ( V_47 ) ;
V_46 = V_47 -> V_48 ;
F_47 ( V_47 ) ;
}
V_38 = F_24 ( & V_7 -> V_32 , V_46 ) ;
if ( ! V_38 ) {
V_38 = F_48 ( sizeof( * V_38 ) , V_31 ) ;
if ( ! V_38 )
return - V_24 ;
V_38 -> V_40 . V_28 = V_28 ;
V_38 -> V_40 . V_47 = NULL ;
if ( ( V_52 = F_26 ( V_38 , V_46 , V_7 -> V_30 ) ) ) {
F_15 ( V_38 ) ;
return V_52 ;
}
F_49 ( V_38 -> V_40 . V_41 , V_46 ) ;
F_50 ( & V_38 -> V_80 , 0 ) ;
F_51 ( & V_38 -> V_39 , & V_7 -> V_32 ) ;
} else if ( V_38 -> V_40 . V_28 != ( V_28 | V_38 -> V_40 . V_28 ) ) {
V_52 = F_41 ( V_38 , V_28 , V_7 -> V_30 ) ;
if ( V_52 )
return V_52 ;
}
F_52 ( & V_38 -> V_80 ) ;
* V_3 = & V_38 -> V_40 ;
return 0 ;
}
int F_53 ( struct V_21 * V_54 , struct V_40 * V_46 ,
T_1 V_55 , T_1 V_56 , void * V_57 )
{
struct V_60 * V_61 = V_57 ;
struct V_51 * V_47 = V_46 -> V_47 ;
struct V_58 * V_59 = F_38 ( V_47 ) ;
char V_67 [ V_68 ] ;
if ( F_54 ( ! V_59 ) ) {
F_19 ( L_10 ,
F_39 ( V_54 -> V_70 -> V_30 ) , F_40 ( V_47 , V_67 ) ) ;
return 0 ;
}
if ( F_55 ( V_61 , V_47 , V_55 ) < 0 )
F_19 ( L_11
L_12
L_13 ,
F_39 ( V_54 -> V_70 -> V_30 ) , F_40 ( V_47 , V_67 ) ,
V_59 -> V_61 . V_81 ,
V_59 -> V_61 . V_66 ,
V_59 -> V_61 . V_82 ,
( unsigned long long ) V_55 << V_64 ) ;
if ( F_56 ( V_59 ) && ! V_54 -> type -> V_83 )
F_57 ( V_61 ,
( unsigned int ) ( V_84 >> 9 ) ) ;
return 0 ;
}
void F_58 ( struct V_21 * V_54 , struct V_40 * V_49 )
{
struct V_37 * V_38 = F_59 ( V_49 , struct V_37 ,
V_40 ) ;
if ( F_60 ( & V_38 -> V_80 ) ) {
F_34 ( V_38 , V_54 -> V_70 -> V_30 ) ;
F_61 ( & V_38 -> V_39 ) ;
F_15 ( V_38 ) ;
}
}
static int F_62 ( struct V_6 * V_70 , struct V_21 * V_54 )
{
struct V_21 * V_85 ;
if ( ! V_70 -> V_23 )
return ! V_54 -> V_86 ;
V_85 = & V_70 -> V_26 [ V_70 -> V_23 - 1 ] ;
return ( V_54 -> V_86 == ( V_85 -> V_86 + V_85 -> V_56 ) ) ;
}
static char * * F_63 ( unsigned * V_87 , char * * V_88 )
{
char * * V_89 ;
unsigned V_90 ;
V_90 = * V_87 ? * V_87 * 2 : 64 ;
V_89 = F_48 ( V_90 * sizeof( * V_89 ) , V_31 ) ;
if ( V_89 ) {
memcpy ( V_89 , V_88 , * V_87 * sizeof( * V_89 ) ) ;
* V_87 = V_90 ;
}
F_15 ( V_88 ) ;
return V_89 ;
}
int F_64 ( int * V_91 , char * * * V_92 , char * V_93 )
{
char * V_55 , * V_94 = V_93 , * V_95 , * * V_89 = NULL ;
unsigned V_87 = 0 ;
* V_91 = 0 ;
if ( ! V_93 ) {
* V_92 = NULL ;
return 0 ;
}
V_89 = F_63 ( & V_87 , V_89 ) ;
if ( ! V_89 )
return - V_24 ;
while ( 1 ) {
V_55 = F_65 ( V_94 ) ;
if ( ! * V_55 )
break;
V_94 = V_95 = V_55 ;
while ( * V_94 ) {
if ( * V_94 == '\\' && * ( V_94 + 1 ) ) {
* V_95 ++ = * ( V_94 + 1 ) ;
V_94 += 2 ;
continue;
}
if ( isspace ( * V_94 ) )
break;
* V_95 ++ = * V_94 ++ ;
}
if ( ( * V_91 + 1 ) > V_87 ) {
V_89 = F_63 ( & V_87 , V_89 ) ;
if ( ! V_89 )
return - V_24 ;
}
if ( * V_94 )
V_94 ++ ;
* V_95 = '\0' ;
V_89 [ * V_91 ] = V_55 ;
( * V_91 ) ++ ;
}
* V_92 = V_89 ;
return 0 ;
}
static int F_66 ( struct V_6 * V_70 ,
struct V_60 * V_61 )
{
unsigned short V_96 =
V_61 -> V_66 >> V_64 ;
unsigned short V_97 = 0 ;
unsigned short V_98 = 0 ;
struct V_21 * V_75 ( V_54 ) ;
struct V_60 V_99 ;
unsigned V_42 = 0 ;
while ( V_42 < F_67 ( V_70 ) ) {
V_54 = F_68 ( V_70 , V_42 ++ ) ;
F_69 ( & V_99 ) ;
if ( V_54 -> type -> V_100 )
V_54 -> type -> V_100 ( V_54 , F_53 ,
& V_99 ) ;
if ( V_98 < V_54 -> V_56 &&
V_98 & ( ( V_99 . V_66 >>
V_64 ) - 1 ) )
break;
V_97 =
( unsigned short ) ( ( V_97 + V_54 -> V_56 ) &
( V_96 - 1 ) ) ;
V_98 = V_97 ?
V_96 - V_97 : 0 ;
}
if ( V_98 ) {
F_19 ( L_14
L_15 ,
F_39 ( V_70 -> V_30 ) , V_42 ,
( unsigned long long ) V_54 -> V_86 ,
( unsigned long long ) V_54 -> V_56 ,
V_61 -> V_66 ) ;
return - V_101 ;
}
return 0 ;
}
int F_70 ( struct V_6 * V_7 , const char * type ,
T_1 V_55 , T_1 V_56 , char * V_102 )
{
int V_52 = - V_101 , V_91 ;
char * * V_89 ;
struct V_21 * V_43 ;
if ( V_7 -> V_103 ) {
F_71 ( L_16 ,
F_39 ( V_7 -> V_30 ) , V_7 -> V_26 -> type -> V_41 ) ;
return - V_101 ;
}
if ( ( V_52 = F_23 ( V_7 ) ) )
return V_52 ;
V_43 = V_7 -> V_26 + V_7 -> V_23 ;
memset ( V_43 , 0 , sizeof( * V_43 ) ) ;
if ( ! V_56 ) {
F_71 ( L_17 , F_39 ( V_7 -> V_30 ) ) ;
return - V_101 ;
}
V_43 -> type = F_72 ( type ) ;
if ( ! V_43 -> type ) {
F_71 ( L_18 , F_39 ( V_7 -> V_30 ) ,
type ) ;
return - V_101 ;
}
if ( F_73 ( V_43 -> type ) ) {
if ( V_7 -> V_23 ) {
F_71 ( L_16 ,
F_39 ( V_7 -> V_30 ) , type ) ;
return - V_101 ;
}
V_7 -> V_103 = 1 ;
}
if ( F_74 ( V_43 -> type ) && ! ( V_7 -> V_28 & V_104 ) ) {
F_71 ( L_19 ,
F_39 ( V_7 -> V_30 ) , type ) ;
return - V_101 ;
}
if ( V_7 -> V_105 ) {
if ( V_7 -> V_105 != V_43 -> type ) {
F_71 ( L_20 ,
F_39 ( V_7 -> V_30 ) , V_7 -> V_105 -> V_41 ) ;
return - V_101 ;
}
} else if ( F_75 ( V_43 -> type ) ) {
if ( V_7 -> V_23 ) {
F_71 ( L_20 ,
F_39 ( V_7 -> V_30 ) , V_43 -> type -> V_41 ) ;
return - V_101 ;
}
V_7 -> V_105 = V_43 -> type ;
}
V_43 -> V_70 = V_7 ;
V_43 -> V_86 = V_55 ;
V_43 -> V_56 = V_56 ;
V_43 -> error = L_21 ;
if ( ! F_62 ( V_7 , V_43 ) ) {
V_43 -> error = L_22 ;
V_52 = - V_101 ;
goto V_106;
}
V_52 = F_64 ( & V_91 , & V_89 , V_102 ) ;
if ( V_52 ) {
V_43 -> error = L_23 ;
goto V_106;
}
V_52 = V_43 -> type -> V_107 ( V_43 , V_91 , V_89 ) ;
F_15 ( V_89 ) ;
if ( V_52 )
goto V_106;
V_7 -> V_25 [ V_7 -> V_23 ++ ] = V_43 -> V_86 + V_43 -> V_56 - 1 ;
if ( ! V_43 -> V_108 && V_43 -> V_109 )
F_19 ( L_24 ,
F_39 ( V_7 -> V_30 ) , type ) ;
return 0 ;
V_106:
F_71 ( L_25 , F_39 ( V_7 -> V_30 ) , type , V_43 -> error ) ;
F_21 ( V_43 -> type ) ;
return V_52 ;
}
static int F_76 ( struct V_110 * V_111 , struct V_112 * V_113 ,
unsigned * V_114 , char * * error , unsigned V_115 )
{
const char * V_116 = F_77 ( V_113 ) ;
char V_78 ;
if ( ! V_116 ||
( sscanf ( V_116 , L_26 , V_114 , & V_78 ) != 1 ) ||
( * V_114 < V_111 -> V_117 ) ||
( * V_114 > V_111 -> V_118 ) ||
( V_115 && V_113 -> V_91 < * V_114 ) ) {
* error = V_111 -> error ;
return - V_101 ;
}
return 0 ;
}
int F_78 ( struct V_110 * V_111 , struct V_112 * V_113 ,
unsigned * V_114 , char * * error )
{
return F_76 ( V_111 , V_113 , V_114 , error , 0 ) ;
}
int F_79 ( struct V_110 * V_111 , struct V_112 * V_113 ,
unsigned * V_114 , char * * error )
{
return F_76 ( V_111 , V_113 , V_114 , error , 1 ) ;
}
const char * F_77 ( struct V_112 * V_119 )
{
char * V_52 ;
if ( V_119 -> V_91 ) {
V_119 -> V_91 -- ;
V_52 = * V_119 -> V_89 ;
V_119 -> V_89 ++ ;
return V_52 ;
}
return NULL ;
}
void F_80 ( struct V_112 * V_119 , unsigned V_120 )
{
F_27 ( V_119 -> V_91 < V_120 ) ;
V_119 -> V_91 -= V_120 ;
V_119 -> V_89 += V_120 ;
}
static int F_81 ( struct V_6 * V_7 )
{
unsigned V_42 ;
unsigned V_121 = 0 , V_122 = 0 ;
struct V_21 * V_43 ;
struct V_37 * V_38 ;
struct V_34 * V_32 ;
for ( V_42 = 0 ; V_42 < V_7 -> V_23 ; V_42 ++ ) {
V_43 = V_7 -> V_26 + V_42 ;
if ( F_82 ( V_43 ) )
V_122 = 1 ;
else
V_121 = 1 ;
if ( V_121 && V_122 ) {
F_19 ( L_27
L_28 ) ;
return - V_101 ;
}
}
if ( V_121 ) {
V_7 -> type = V_123 ;
return 0 ;
}
F_27 ( ! V_122 ) ;
V_32 = F_83 ( V_7 ) ;
F_25 (dd, devices, list) {
if ( ! F_84 ( F_38 ( V_38 -> V_40 . V_47 ) ) ) {
F_19 ( L_29
L_30 ) ;
return - V_101 ;
}
}
if ( V_7 -> V_23 > 1 ) {
F_19 ( L_31 ) ;
return - V_101 ;
}
V_7 -> type = V_124 ;
return 0 ;
}
unsigned F_85 ( struct V_6 * V_7 )
{
return V_7 -> type ;
}
struct V_125 * F_86 ( struct V_6 * V_7 )
{
return V_7 -> V_105 ;
}
bool F_87 ( struct V_6 * V_7 )
{
return F_85 ( V_7 ) == V_124 ;
}
int F_88 ( struct V_6 * V_7 )
{
unsigned type = F_85 ( V_7 ) ;
unsigned V_126 = 0 ;
struct V_21 * V_43 ;
unsigned V_42 ;
if ( F_54 ( type == V_127 ) ) {
F_19 ( L_32 ) ;
return - V_101 ;
}
if ( type == V_123 )
for ( V_42 = 0 ; V_42 < V_7 -> V_23 ; V_42 ++ ) {
V_43 = V_7 -> V_26 + V_42 ;
V_126 = V_118 ( V_126 , V_43 -> V_126 ) ;
}
V_7 -> V_45 = F_89 ( type , V_7 -> V_128 , V_126 ) ;
if ( ! V_7 -> V_45 )
return - V_24 ;
return 0 ;
}
void F_90 ( struct V_6 * V_7 )
{
F_22 ( V_7 -> V_45 ) ;
V_7 -> V_45 = NULL ;
}
struct V_129 * F_91 ( struct V_6 * V_7 )
{
return V_7 -> V_45 ;
}
static int F_92 ( struct V_6 * V_7 )
{
int V_42 ;
unsigned int V_130 = 0 ;
T_1 * V_131 ;
for ( V_42 = V_7 -> V_11 - 2 ; V_42 >= 0 ; V_42 -- ) {
V_7 -> V_12 [ V_42 ] = F_2 ( V_7 -> V_12 [ V_42 + 1 ] , V_5 ) ;
V_130 += V_7 -> V_12 [ V_42 ] ;
}
V_131 = ( T_1 * ) F_7 ( V_130 , ( unsigned long ) V_132 ) ;
if ( ! V_131 )
return - V_24 ;
for ( V_42 = V_7 -> V_11 - 2 ; V_42 >= 0 ; V_42 -- ) {
V_7 -> V_9 [ V_42 ] = V_131 ;
V_131 += ( V_10 * V_7 -> V_12 [ V_42 ] ) ;
F_6 ( V_42 , V_7 ) ;
}
return 0 ;
}
static int F_93 ( struct V_6 * V_7 )
{
int V_52 = 0 ;
unsigned int V_133 ;
V_133 = F_2 ( V_7 -> V_23 , V_10 ) ;
V_7 -> V_11 = 1 + F_1 ( V_133 , V_5 ) ;
V_7 -> V_12 [ V_7 -> V_11 - 1 ] = V_133 ;
V_7 -> V_9 [ V_7 -> V_11 - 1 ] = V_7 -> V_25 ;
if ( V_7 -> V_11 >= 2 )
V_52 = F_92 ( V_7 ) ;
return V_52 ;
}
static struct V_134 * F_94 ( struct V_6 * V_7 ,
bool V_135 )
{
struct V_34 * V_32 = F_83 ( V_7 ) ;
struct V_37 * V_38 = NULL ;
struct V_134 * V_136 = NULL , * V_137 = NULL ;
F_25 (dd, devices, list) {
V_137 = V_38 -> V_40 . V_47 -> V_138 ;
if ( ! F_95 ( V_137 ) )
goto V_139;
if ( ! V_135 && ! F_96 ( V_137 ) )
continue;
else if ( V_136 &&
F_97 ( V_136 , V_137 ) < 0 )
goto V_139;
V_136 = V_137 ;
}
return V_137 ;
V_139:
if ( V_136 )
F_19 ( L_33 ,
F_39 ( V_7 -> V_30 ) ,
V_136 -> V_140 ,
V_137 -> V_140 ) ;
return NULL ;
}
static int F_98 ( struct V_6 * V_7 , struct V_29 * V_30 )
{
struct V_134 * V_137 = NULL ;
V_137 = F_94 ( V_7 , false ) ;
if ( ! V_137 )
return 0 ;
if ( ! F_96 ( F_32 ( V_30 ) ) ) {
V_7 -> V_128 = 1 ;
return F_99 ( F_32 ( V_30 ) , NULL ) ;
}
if ( F_96 ( V_137 ) &&
F_97 ( F_32 ( V_30 ) , V_137 ) < 0 ) {
F_19 ( L_34
L_35 ,
F_39 ( V_7 -> V_30 ) ,
V_137 -> V_140 ) ;
return 1 ;
}
V_7 -> V_128 = 1 ;
return 0 ;
}
int F_100 ( struct V_6 * V_7 )
{
int V_52 ;
V_52 = F_81 ( V_7 ) ;
if ( V_52 ) {
F_71 ( L_36 ) ;
return V_52 ;
}
V_52 = F_93 ( V_7 ) ;
if ( V_52 ) {
F_71 ( L_37 ) ;
return V_52 ;
}
V_52 = F_98 ( V_7 , V_7 -> V_30 ) ;
if ( V_52 ) {
F_71 ( L_38 ) ;
return V_52 ;
}
V_52 = F_88 ( V_7 ) ;
if ( V_52 )
F_71 ( L_39 ) ;
return V_52 ;
}
void F_101 ( struct V_6 * V_7 ,
void (* F_102)( void * ) , void * V_141 )
{
F_103 ( & V_142 ) ;
V_7 -> V_143 = F_102 ;
V_7 -> V_144 = V_141 ;
F_104 ( & V_142 ) ;
}
void F_105 ( struct V_6 * V_7 )
{
F_27 ( F_106 () ) ;
F_103 ( & V_142 ) ;
if ( V_7 -> V_143 )
V_7 -> V_143 ( V_7 -> V_144 ) ;
F_104 ( & V_142 ) ;
}
T_1 F_107 ( struct V_6 * V_7 )
{
return V_7 -> V_23 ? ( V_7 -> V_25 [ V_7 -> V_23 - 1 ] + 1 ) : 0 ;
}
struct V_21 * F_68 ( struct V_6 * V_7 , unsigned int V_9 )
{
if ( V_9 >= V_7 -> V_23 )
return NULL ;
return V_7 -> V_26 + V_9 ;
}
struct V_21 * F_108 ( struct V_6 * V_7 , T_1 V_145 )
{
unsigned int V_8 , V_1 = 0 , V_4 = 0 ;
T_1 * V_13 ;
for ( V_8 = 0 ; V_8 < V_7 -> V_11 ; V_8 ++ ) {
V_1 = F_3 ( V_1 , V_4 ) ;
V_13 = F_4 ( V_7 , V_8 , V_1 ) ;
for ( V_4 = 0 ; V_4 < V_10 ; V_4 ++ )
if ( V_13 [ V_4 ] >= V_145 )
break;
}
return & V_7 -> V_26 [ ( V_10 * V_1 ) + V_4 ] ;
}
static int F_109 ( struct V_21 * V_54 , struct V_40 * V_46 ,
T_1 V_55 , T_1 V_56 , void * V_57 )
{
unsigned * V_146 = V_57 ;
( * V_146 ) ++ ;
return 0 ;
}
bool F_110 ( struct V_6 * V_70 )
{
struct V_21 * V_75 ( V_54 ) ;
unsigned V_42 = 0 , V_146 = 0 ;
while ( V_42 < F_67 ( V_70 ) ) {
V_54 = F_68 ( V_70 , V_42 ++ ) ;
if ( ! V_54 -> type -> V_100 )
return false ;
V_54 -> type -> V_100 ( V_54 , F_109 , & V_146 ) ;
if ( V_146 )
return false ;
}
return true ;
}
int F_111 ( struct V_6 * V_70 ,
struct V_60 * V_61 )
{
struct V_21 * V_75 ( V_54 ) ;
struct V_60 V_99 ;
unsigned V_42 = 0 ;
F_69 ( V_61 ) ;
while ( V_42 < F_67 ( V_70 ) ) {
F_69 ( & V_99 ) ;
V_54 = F_68 ( V_70 , V_42 ++ ) ;
if ( ! V_54 -> type -> V_100 )
goto V_147;
V_54 -> type -> V_100 ( V_54 , F_53 ,
& V_99 ) ;
if ( V_54 -> type -> V_148 )
V_54 -> type -> V_148 ( V_54 , & V_99 ) ;
if ( V_54 -> type -> V_100 ( V_54 , F_36 ,
& V_99 ) )
return - V_101 ;
V_147:
if ( F_112 ( V_61 , & V_99 , 0 ) < 0 )
F_19 ( L_40
L_41
L_42 ,
F_39 ( V_70 -> V_30 ) ,
( unsigned long long ) V_54 -> V_86 ,
( unsigned long long ) V_54 -> V_56 ) ;
}
return F_66 ( V_70 , V_61 ) ;
}
static void F_113 ( struct V_6 * V_7 )
{
struct V_134 * V_137 = NULL ;
if ( ! F_95 ( F_32 ( V_7 -> V_30 ) ) )
return;
V_137 = F_94 ( V_7 , true ) ;
if ( V_137 )
F_99 ( F_32 ( V_7 -> V_30 ) ,
F_95 ( V_137 ) ) ;
else if ( F_96 ( F_32 ( V_7 -> V_30 ) ) )
F_19 ( L_43 ,
F_39 ( V_7 -> V_30 ) ) ;
else
F_19 ( L_44 ,
F_39 ( V_7 -> V_30 ) ) ;
}
static int F_114 ( struct V_21 * V_54 , struct V_40 * V_46 ,
T_1 V_55 , T_1 V_56 , void * V_57 )
{
unsigned V_149 = ( * ( unsigned * ) V_57 ) ;
struct V_58 * V_59 = F_38 ( V_46 -> V_47 ) ;
return V_59 && ( V_59 -> V_150 & V_149 ) ;
}
static bool F_115 ( struct V_6 * V_7 , unsigned V_149 )
{
struct V_21 * V_54 ;
unsigned V_42 = 0 ;
while ( V_42 < F_67 ( V_7 ) ) {
V_54 = F_68 ( V_7 , V_42 ++ ) ;
if ( ! V_54 -> V_151 )
continue;
if ( V_54 -> V_152 )
return 1 ;
if ( V_54 -> type -> V_100 &&
V_54 -> type -> V_100 ( V_54 , F_114 , & V_149 ) )
return 1 ;
}
return 0 ;
}
static bool F_116 ( struct V_6 * V_7 )
{
struct V_21 * V_54 ;
unsigned V_42 = 0 ;
while ( V_42 < F_67 ( V_7 ) ) {
V_54 = F_68 ( V_7 , V_42 ++ ) ;
if ( V_54 -> V_153 )
return 0 ;
}
return 1 ;
}
static int F_117 ( struct V_21 * V_54 , struct V_40 * V_46 ,
T_1 V_55 , T_1 V_56 , void * V_57 )
{
struct V_58 * V_59 = F_38 ( V_46 -> V_47 ) ;
return V_59 && F_118 ( V_59 ) ;
}
static int F_119 ( struct V_21 * V_54 , struct V_40 * V_46 ,
T_1 V_55 , T_1 V_56 , void * V_57 )
{
struct V_58 * V_59 = F_38 ( V_46 -> V_47 ) ;
return V_59 && ! F_120 ( V_59 ) ;
}
static bool F_121 ( struct V_6 * V_7 ,
T_4 V_154 )
{
struct V_21 * V_54 ;
unsigned V_42 = 0 ;
while ( V_42 < F_67 ( V_7 ) ) {
V_54 = F_68 ( V_7 , V_42 ++ ) ;
if ( ! V_54 -> type -> V_100 ||
! V_54 -> type -> V_100 ( V_54 , V_154 , NULL ) )
return 0 ;
}
return 1 ;
}
static int F_122 ( struct V_21 * V_54 , struct V_40 * V_46 ,
T_1 V_55 , T_1 V_56 , void * V_57 )
{
struct V_58 * V_59 = F_38 ( V_46 -> V_47 ) ;
return V_59 && ! V_59 -> V_61 . V_155 ;
}
static bool F_123 ( struct V_6 * V_7 )
{
struct V_21 * V_54 ;
unsigned V_42 = 0 ;
while ( V_42 < F_67 ( V_7 ) ) {
V_54 = F_68 ( V_7 , V_42 ++ ) ;
if ( ! V_54 -> V_156 )
return false ;
if ( ! V_54 -> type -> V_100 ||
V_54 -> type -> V_100 ( V_54 , F_122 , NULL ) )
return false ;
}
return true ;
}
void F_124 ( struct V_6 * V_7 , struct V_58 * V_59 ,
struct V_60 * V_61 )
{
unsigned V_149 = 0 ;
V_59 -> V_61 = * V_61 ;
if ( ! F_125 ( V_7 ) )
F_126 ( V_157 , V_59 ) ;
else
F_127 ( V_157 , V_59 ) ;
if ( F_115 ( V_7 , V_158 ) ) {
V_149 |= V_158 ;
if ( F_115 ( V_7 , V_159 ) )
V_149 |= V_159 ;
}
F_128 ( V_59 , V_149 ) ;
if ( ! F_116 ( V_7 ) )
V_59 -> V_61 . V_160 = 0 ;
if ( F_121 ( V_7 , F_117 ) )
F_127 ( V_161 , V_59 ) ;
else
F_126 ( V_161 , V_59 ) ;
if ( ! F_123 ( V_7 ) )
V_59 -> V_61 . V_155 = 0 ;
F_113 ( V_7 ) ;
if ( F_120 ( V_59 ) && F_121 ( V_7 , F_119 ) )
F_126 ( V_162 , V_59 ) ;
F_129 () ;
if ( F_87 ( V_7 ) )
F_127 ( V_163 , V_59 ) ;
}
unsigned int F_67 ( struct V_6 * V_7 )
{
return V_7 -> V_23 ;
}
struct V_34 * F_83 ( struct V_6 * V_7 )
{
return & V_7 -> V_32 ;
}
T_2 F_130 ( struct V_6 * V_7 )
{
return V_7 -> V_28 ;
}
static void F_131 ( struct V_6 * V_7 , unsigned V_164 )
{
int V_42 = V_7 -> V_23 ;
struct V_21 * V_54 = V_7 -> V_26 ;
while ( V_42 -- ) {
if ( V_164 ) {
if ( V_54 -> type -> V_164 )
V_54 -> type -> V_164 ( V_54 ) ;
} else if ( V_54 -> type -> V_165 )
V_54 -> type -> V_165 ( V_54 ) ;
V_54 ++ ;
}
}
void F_132 ( struct V_6 * V_7 )
{
if ( ! V_7 )
return;
F_131 ( V_7 , 0 ) ;
}
void F_133 ( struct V_6 * V_7 )
{
if ( ! V_7 )
return;
F_131 ( V_7 , 1 ) ;
}
int F_134 ( struct V_6 * V_7 )
{
int V_42 , V_52 = 0 ;
for ( V_42 = 0 ; V_42 < V_7 -> V_23 ; V_42 ++ ) {
struct V_21 * V_54 = V_7 -> V_26 + V_42 ;
if ( ! V_54 -> type -> V_166 )
continue;
V_52 = V_54 -> type -> V_166 ( V_54 ) ;
if ( V_52 )
return V_52 ;
}
for ( V_42 = 0 ; V_42 < V_7 -> V_23 ; V_42 ++ ) {
struct V_21 * V_54 = V_7 -> V_26 + V_42 ;
if ( V_54 -> type -> V_167 )
V_54 -> type -> V_167 ( V_54 ) ;
}
return 0 ;
}
void F_135 ( struct V_6 * V_7 , struct V_168 * V_169 )
{
F_51 ( & V_169 -> V_39 , & V_7 -> V_33 ) ;
}
int F_136 ( struct V_6 * V_7 , int V_170 )
{
struct V_37 * V_38 ;
struct V_34 * V_32 = F_83 ( V_7 ) ;
struct V_168 * V_169 ;
int V_52 = 0 ;
F_25 (dd, devices, list) {
struct V_58 * V_59 = F_38 ( V_38 -> V_40 . V_47 ) ;
char V_67 [ V_68 ] ;
if ( F_137 ( V_59 ) )
V_52 |= F_138 ( & V_59 -> V_171 , V_170 ) ;
else
F_139 ( L_45 ,
F_39 ( V_7 -> V_30 ) ,
F_40 ( V_38 -> V_40 . V_47 , V_67 ) ) ;
}
F_25 (cb, &t->target_callbacks, list)
if ( V_169 -> V_172 )
V_52 |= V_169 -> V_172 ( V_169 , V_170 ) ;
return V_52 ;
}
int F_140 ( struct V_6 * V_7 )
{
unsigned V_42 ;
struct V_21 * V_54 ;
for ( V_42 = 0 ; V_42 < V_7 -> V_23 ; V_42 ++ ) {
V_54 = V_7 -> V_26 + V_42 ;
if ( V_54 -> type -> V_173 && V_54 -> type -> V_173 ( V_54 ) )
return 1 ;
}
return 0 ;
}
struct V_29 * F_141 ( struct V_6 * V_7 )
{
return V_7 -> V_30 ;
}
static int F_142 ( struct V_21 * V_54 , struct V_40 * V_46 ,
T_1 V_55 , T_1 V_56 , void * V_57 )
{
struct V_58 * V_59 = F_38 ( V_46 -> V_47 ) ;
return V_59 && F_143 ( V_59 ) ;
}
bool F_125 ( struct V_6 * V_7 )
{
struct V_21 * V_54 ;
unsigned V_42 = 0 ;
while ( V_42 < F_67 ( V_7 ) ) {
V_54 = F_68 ( V_7 , V_42 ++ ) ;
if ( ! V_54 -> V_108 )
continue;
if ( V_54 -> V_109 )
return 1 ;
if ( V_54 -> type -> V_100 &&
V_54 -> type -> V_100 ( V_54 , F_142 , NULL ) )
return 1 ;
}
return 0 ;
}
