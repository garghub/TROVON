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
if ( V_17 )
memset ( V_17 , 0 , V_16 ) ;
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
V_7 -> V_35 = 1 ;
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
static void F_17 ( struct V_36 * V_32 )
{
struct V_36 * V_37 , * V_38 ;
F_18 (tmp, next, devices) {
struct V_39 * V_40 =
F_19 ( V_37 , struct V_39 , V_41 ) ;
F_20 ( L_1 ,
V_40 -> V_42 . V_43 ) ;
F_16 ( V_40 ) ;
}
}
void F_21 ( struct V_6 * V_7 )
{
unsigned int V_44 ;
if ( ! V_7 )
return;
while ( F_22 ( & V_7 -> V_34 ) )
F_23 ( 1 ) ;
F_24 () ;
if ( V_7 -> V_11 >= 2 )
F_10 ( V_7 -> V_9 [ V_7 -> V_11 - 2 ] ) ;
for ( V_44 = 0 ; V_44 < V_7 -> V_23 ; V_44 ++ ) {
struct V_21 * V_45 = V_7 -> V_26 + V_44 ;
if ( V_45 -> type -> V_46 )
V_45 -> type -> V_46 ( V_45 ) ;
F_25 ( V_45 -> type ) ;
}
F_10 ( V_7 -> V_25 ) ;
if ( V_7 -> V_32 . V_38 != & V_7 -> V_32 )
F_17 ( & V_7 -> V_32 ) ;
F_26 ( V_7 -> V_47 ) ;
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
static struct V_39 * F_33 ( struct V_36 * V_8 , T_3 V_48 )
{
struct V_39 * V_40 ;
F_34 (dd, l, list)
if ( V_40 -> V_42 . V_49 -> V_50 == V_48 )
return V_40 ;
return NULL ;
}
static int F_35 ( struct V_39 * V_51 , T_3 V_48 ,
struct V_29 * V_30 )
{
static char * V_52 = L_2 ;
struct V_53 * V_49 ;
int V_54 ;
F_36 ( V_51 -> V_42 . V_49 ) ;
V_49 = F_37 ( V_48 , V_51 -> V_42 . V_28 | V_55 , V_52 ) ;
if ( F_38 ( V_49 ) )
return F_39 ( V_49 ) ;
V_54 = F_40 ( V_49 , F_41 ( V_30 ) ) ;
if ( V_54 ) {
F_42 ( V_49 , V_51 -> V_42 . V_28 | V_55 ) ;
return V_54 ;
}
V_51 -> V_42 . V_49 = V_49 ;
return 0 ;
}
static void F_43 ( struct V_39 * V_51 , struct V_29 * V_30 )
{
if ( ! V_51 -> V_42 . V_49 )
return;
F_44 ( V_51 -> V_42 . V_49 , F_41 ( V_30 ) ) ;
F_42 ( V_51 -> V_42 . V_49 , V_51 -> V_42 . V_28 | V_55 ) ;
V_51 -> V_42 . V_49 = NULL ;
}
static int F_45 ( struct V_21 * V_56 , struct V_42 * V_48 ,
T_1 V_57 , T_1 V_58 , void * V_59 )
{
struct V_60 * V_61 ;
struct V_62 * V_63 = V_59 ;
struct V_53 * V_49 = V_48 -> V_49 ;
T_1 V_64 =
F_46 ( V_49 -> V_65 ) >> V_66 ;
unsigned short V_67 =
V_63 -> V_68 >> V_66 ;
char V_69 [ V_70 ] ;
V_61 = F_47 ( V_49 ) ;
if ( ! V_61 || ! V_61 -> V_71 ) {
F_20 ( L_3
L_4 ,
F_48 ( V_56 -> V_72 -> V_30 ) , F_49 ( V_49 , V_69 ) ,
( unsigned long long ) V_57 ,
( unsigned long long ) V_58 ,
( unsigned long long ) V_64 ) ;
return 1 ;
}
if ( ! V_64 )
return 0 ;
if ( ( V_57 >= V_64 ) || ( V_57 + V_58 > V_64 ) ) {
F_20 ( L_5
L_4 ,
F_48 ( V_56 -> V_72 -> V_30 ) , F_49 ( V_49 , V_69 ) ,
( unsigned long long ) V_57 ,
( unsigned long long ) V_58 ,
( unsigned long long ) V_64 ) ;
return 1 ;
}
if ( V_67 <= 1 )
return 0 ;
if ( V_57 & ( V_67 - 1 ) ) {
F_20 ( L_6
L_7 ,
F_48 ( V_56 -> V_72 -> V_30 ) ,
( unsigned long long ) V_57 ,
V_63 -> V_68 , F_49 ( V_49 , V_69 ) ) ;
return 1 ;
}
if ( V_58 & ( V_67 - 1 ) ) {
F_20 ( L_8
L_7 ,
F_48 ( V_56 -> V_72 -> V_30 ) ,
( unsigned long long ) V_58 ,
V_63 -> V_68 , F_49 ( V_49 , V_69 ) ) ;
return 1 ;
}
return 0 ;
}
static int F_50 ( struct V_39 * V_40 , T_2 V_73 ,
struct V_29 * V_30 )
{
int V_54 ;
struct V_39 V_74 , V_75 ;
V_74 = V_75 = * V_40 ;
V_74 . V_42 . V_28 |= V_73 ;
V_74 . V_42 . V_49 = NULL ;
V_54 = F_35 ( & V_74 , V_40 -> V_42 . V_49 -> V_50 , V_30 ) ;
if ( V_54 )
return V_54 ;
V_40 -> V_42 . V_28 |= V_73 ;
F_43 ( & V_75 , V_30 ) ;
return 0 ;
}
static int F_51 ( struct V_6 * V_7 , struct V_21 * V_56 ,
const char * V_76 , T_2 V_28 , struct V_42 * * V_3 )
{
int V_54 ;
T_3 V_77 ( V_48 ) ;
struct V_39 * V_40 ;
unsigned int V_78 , V_79 ;
F_36 ( ! V_7 ) ;
if ( sscanf ( V_76 , L_9 , & V_78 , & V_79 ) == 2 ) {
V_48 = F_52 ( V_78 , V_79 ) ;
if ( F_53 ( V_48 ) != V_78 || F_54 ( V_48 ) != V_79 )
return - V_80 ;
} else {
struct V_53 * V_49 = F_55 ( V_76 ) ;
if ( F_38 ( V_49 ) )
return F_39 ( V_49 ) ;
V_48 = V_49 -> V_50 ;
F_56 ( V_49 ) ;
}
V_40 = F_33 ( & V_7 -> V_32 , V_48 ) ;
if ( ! V_40 ) {
V_40 = F_57 ( sizeof( * V_40 ) , V_31 ) ;
if ( ! V_40 )
return - V_24 ;
V_40 -> V_42 . V_28 = V_28 ;
V_40 -> V_42 . V_49 = NULL ;
if ( ( V_54 = F_35 ( V_40 , V_48 , V_7 -> V_30 ) ) ) {
F_16 ( V_40 ) ;
return V_54 ;
}
F_58 ( V_40 -> V_42 . V_43 , V_48 ) ;
F_14 ( & V_40 -> V_81 , 0 ) ;
F_59 ( & V_40 -> V_41 , & V_7 -> V_32 ) ;
} else if ( V_40 -> V_42 . V_28 != ( V_28 | V_40 -> V_42 . V_28 ) ) {
V_54 = F_50 ( V_40 , V_28 , V_7 -> V_30 ) ;
if ( V_54 )
return V_54 ;
}
F_28 ( & V_40 -> V_81 ) ;
* V_3 = & V_40 -> V_42 ;
return 0 ;
}
int F_60 ( struct V_21 * V_56 , struct V_42 * V_48 ,
T_1 V_57 , T_1 V_58 , void * V_59 )
{
struct V_62 * V_63 = V_59 ;
struct V_53 * V_49 = V_48 -> V_49 ;
struct V_60 * V_61 = F_47 ( V_49 ) ;
char V_69 [ V_70 ] ;
if ( F_61 ( ! V_61 ) ) {
F_20 ( L_10 ,
F_48 ( V_56 -> V_72 -> V_30 ) , F_49 ( V_49 , V_69 ) ) ;
return 0 ;
}
if ( F_62 ( V_63 , V_49 , V_57 ) < 0 )
F_20 ( L_11
L_12
L_13 ,
F_48 ( V_56 -> V_72 -> V_30 ) , F_49 ( V_49 , V_69 ) ,
V_61 -> V_63 . V_82 ,
V_61 -> V_63 . V_68 ,
V_61 -> V_63 . V_83 ,
( unsigned long long ) V_57 << V_66 ) ;
if ( V_61 -> V_84 && ! V_56 -> type -> V_85 )
F_63 ( V_63 ,
( unsigned int ) ( V_86 >> 9 ) ) ;
return 0 ;
}
int F_64 ( struct V_21 * V_56 , const char * V_76 , T_2 V_28 ,
struct V_42 * * V_3 )
{
return F_51 ( V_56 -> V_72 , V_56 , V_76 , V_28 , V_3 ) ;
}
void F_65 ( struct V_21 * V_56 , struct V_42 * V_51 )
{
struct V_39 * V_40 = F_66 ( V_51 , struct V_39 ,
V_42 ) ;
if ( F_67 ( & V_40 -> V_81 ) ) {
F_43 ( V_40 , V_56 -> V_72 -> V_30 ) ;
F_68 ( & V_40 -> V_41 ) ;
F_16 ( V_40 ) ;
}
}
static int F_69 ( struct V_6 * V_72 , struct V_21 * V_56 )
{
struct V_21 * V_87 ;
if ( ! V_72 -> V_23 )
return ! V_56 -> V_88 ;
V_87 = & V_72 -> V_26 [ V_72 -> V_23 - 1 ] ;
return ( V_56 -> V_88 == ( V_87 -> V_88 + V_87 -> V_58 ) ) ;
}
static char * * F_70 ( unsigned * V_89 , char * * V_90 )
{
char * * V_91 ;
unsigned V_92 ;
V_92 = * V_89 ? * V_89 * 2 : 64 ;
V_91 = F_57 ( V_92 * sizeof( * V_91 ) , V_31 ) ;
if ( V_91 ) {
memcpy ( V_91 , V_90 , * V_89 * sizeof( * V_91 ) ) ;
* V_89 = V_92 ;
}
F_16 ( V_90 ) ;
return V_91 ;
}
int F_71 ( int * V_93 , char * * * V_94 , char * V_95 )
{
char * V_57 , * V_96 = V_95 , * V_97 , * * V_91 = NULL ;
unsigned V_89 = 0 ;
* V_93 = 0 ;
if ( ! V_95 ) {
* V_94 = NULL ;
return 0 ;
}
V_91 = F_70 ( & V_89 , V_91 ) ;
if ( ! V_91 )
return - V_24 ;
while ( 1 ) {
V_57 = F_72 ( V_96 ) ;
if ( ! * V_57 )
break;
V_96 = V_97 = V_57 ;
while ( * V_96 ) {
if ( * V_96 == '\\' && * ( V_96 + 1 ) ) {
* V_97 ++ = * ( V_96 + 1 ) ;
V_96 += 2 ;
continue;
}
if ( isspace ( * V_96 ) )
break;
* V_97 ++ = * V_96 ++ ;
}
if ( ( * V_93 + 1 ) > V_89 ) {
V_91 = F_70 ( & V_89 , V_91 ) ;
if ( ! V_91 )
return - V_24 ;
}
if ( * V_96 )
V_96 ++ ;
* V_97 = '\0' ;
V_91 [ * V_93 ] = V_57 ;
( * V_93 ) ++ ;
}
* V_94 = V_91 ;
return 0 ;
}
static int F_73 ( struct V_6 * V_72 ,
struct V_62 * V_63 )
{
unsigned short V_98 =
V_63 -> V_68 >> V_66 ;
unsigned short V_99 = 0 ;
unsigned short V_100 = 0 ;
struct V_21 * V_77 ( V_56 ) ;
struct V_62 V_101 ;
unsigned V_44 = 0 ;
while ( V_44 < F_74 ( V_72 ) ) {
V_56 = F_75 ( V_72 , V_44 ++ ) ;
F_76 ( & V_101 ) ;
if ( V_56 -> type -> V_102 )
V_56 -> type -> V_102 ( V_56 , F_60 ,
& V_101 ) ;
if ( V_100 < V_56 -> V_58 &&
V_100 & ( ( V_101 . V_68 >>
V_66 ) - 1 ) )
break;
V_99 =
( unsigned short ) ( ( V_99 + V_56 -> V_58 ) &
( V_98 - 1 ) ) ;
V_100 = V_99 ?
V_98 - V_99 : 0 ;
}
if ( V_100 ) {
F_20 ( L_14
L_15 ,
F_48 ( V_72 -> V_30 ) , V_44 ,
( unsigned long long ) V_56 -> V_88 ,
( unsigned long long ) V_56 -> V_58 ,
V_63 -> V_68 ) ;
return - V_103 ;
}
return 0 ;
}
int F_77 ( struct V_6 * V_7 , const char * type ,
T_1 V_57 , T_1 V_58 , char * V_104 )
{
int V_54 = - V_103 , V_93 ;
char * * V_91 ;
struct V_21 * V_45 ;
if ( ( V_54 = F_32 ( V_7 ) ) )
return V_54 ;
V_45 = V_7 -> V_26 + V_7 -> V_23 ;
memset ( V_45 , 0 , sizeof( * V_45 ) ) ;
if ( ! V_58 ) {
F_78 ( L_16 , F_48 ( V_7 -> V_30 ) ) ;
return - V_103 ;
}
V_45 -> type = F_79 ( type ) ;
if ( ! V_45 -> type ) {
F_78 ( L_17 , F_48 ( V_7 -> V_30 ) ,
type ) ;
return - V_103 ;
}
V_45 -> V_72 = V_7 ;
V_45 -> V_88 = V_57 ;
V_45 -> V_58 = V_58 ;
V_45 -> error = L_18 ;
if ( ! F_69 ( V_7 , V_45 ) ) {
V_45 -> error = L_19 ;
V_54 = - V_103 ;
goto V_105;
}
V_54 = F_71 ( & V_93 , & V_91 , V_104 ) ;
if ( V_54 ) {
V_45 -> error = L_20 ;
goto V_105;
}
V_54 = V_45 -> type -> V_106 ( V_45 , V_93 , V_91 ) ;
F_16 ( V_91 ) ;
if ( V_54 )
goto V_105;
V_7 -> V_25 [ V_7 -> V_23 ++ ] = V_45 -> V_88 + V_45 -> V_58 - 1 ;
if ( ! V_45 -> V_107 )
V_7 -> V_35 = 0 ;
return 0 ;
V_105:
F_78 ( L_21 , F_48 ( V_7 -> V_30 ) , type , V_45 -> error ) ;
F_25 ( V_45 -> type ) ;
return V_54 ;
}
static int F_80 ( struct V_6 * V_7 )
{
unsigned V_44 ;
unsigned V_108 = 0 , V_109 = 0 ;
struct V_21 * V_45 ;
struct V_39 * V_40 ;
struct V_36 * V_32 ;
for ( V_44 = 0 ; V_44 < V_7 -> V_23 ; V_44 ++ ) {
V_45 = V_7 -> V_26 + V_44 ;
if ( F_81 ( V_45 ) )
V_109 = 1 ;
else
V_108 = 1 ;
if ( V_108 && V_109 ) {
F_20 ( L_22
L_23 ) ;
return - V_103 ;
}
}
if ( V_108 ) {
V_7 -> type = V_110 ;
return 0 ;
}
F_36 ( ! V_109 ) ;
V_32 = F_82 ( V_7 ) ;
F_34 (dd, devices, list) {
if ( ! F_83 ( F_47 ( V_40 -> V_42 . V_49 ) ) ) {
F_20 ( L_24
L_25 ) ;
return - V_103 ;
}
}
if ( V_7 -> V_23 > 1 ) {
F_20 ( L_26 ) ;
return - V_103 ;
}
V_7 -> type = V_111 ;
return 0 ;
}
unsigned F_84 ( struct V_6 * V_7 )
{
return V_7 -> type ;
}
bool F_85 ( struct V_6 * V_7 )
{
return F_84 ( V_7 ) == V_111 ;
}
int F_86 ( struct V_6 * V_7 )
{
unsigned type = F_84 ( V_7 ) ;
if ( F_61 ( type == V_112 ) ) {
F_20 ( L_27 ) ;
return - V_103 ;
}
V_7 -> V_47 = F_87 ( type , V_7 -> V_113 ) ;
if ( ! V_7 -> V_47 )
return - V_24 ;
return 0 ;
}
void F_88 ( struct V_6 * V_7 )
{
F_26 ( V_7 -> V_47 ) ;
V_7 -> V_47 = NULL ;
}
struct V_114 * F_89 ( struct V_6 * V_7 )
{
return V_7 -> V_47 ;
}
static int F_90 ( struct V_6 * V_7 )
{
int V_44 ;
unsigned int V_115 = 0 ;
T_1 * V_116 ;
for ( V_44 = V_7 -> V_11 - 2 ; V_44 >= 0 ; V_44 -- ) {
V_7 -> V_12 [ V_44 ] = F_2 ( V_7 -> V_12 [ V_44 + 1 ] , V_5 ) ;
V_115 += V_7 -> V_12 [ V_44 ] ;
}
V_116 = ( T_1 * ) F_7 ( V_115 , ( unsigned long ) V_117 ) ;
if ( ! V_116 )
return - V_24 ;
for ( V_44 = V_7 -> V_11 - 2 ; V_44 >= 0 ; V_44 -- ) {
V_7 -> V_9 [ V_44 ] = V_116 ;
V_116 += ( V_10 * V_7 -> V_12 [ V_44 ] ) ;
F_6 ( V_44 , V_7 ) ;
}
return 0 ;
}
static int F_91 ( struct V_6 * V_7 )
{
int V_54 = 0 ;
unsigned int V_118 ;
V_118 = F_2 ( V_7 -> V_23 , V_10 ) ;
V_7 -> V_11 = 1 + F_1 ( V_118 , V_5 ) ;
V_7 -> V_12 [ V_7 -> V_11 - 1 ] = V_118 ;
V_7 -> V_9 [ V_7 -> V_11 - 1 ] = V_7 -> V_25 ;
if ( V_7 -> V_11 >= 2 )
V_54 = F_90 ( V_7 ) ;
return V_54 ;
}
static struct V_119 * F_92 ( struct V_6 * V_7 ,
bool V_120 )
{
struct V_36 * V_32 = F_82 ( V_7 ) ;
struct V_39 * V_40 = NULL ;
struct V_119 * V_121 = NULL , * V_122 = NULL ;
F_34 (dd, devices, list) {
V_122 = V_40 -> V_42 . V_49 -> V_123 ;
if ( ! F_93 ( V_122 ) )
goto V_124;
if ( ! V_120 && ! F_94 ( V_122 ) )
continue;
else if ( V_121 &&
F_95 ( V_121 , V_122 ) < 0 )
goto V_124;
V_121 = V_122 ;
}
return V_122 ;
V_124:
if ( V_121 )
F_20 ( L_28 ,
F_48 ( V_7 -> V_30 ) ,
V_121 -> V_125 ,
V_122 -> V_125 ) ;
return NULL ;
}
static int F_96 ( struct V_6 * V_7 , struct V_29 * V_30 )
{
struct V_119 * V_122 = NULL ;
V_122 = F_92 ( V_7 , false ) ;
if ( ! V_122 )
return 0 ;
if ( ! F_94 ( F_41 ( V_30 ) ) ) {
V_7 -> V_113 = 1 ;
return F_97 ( F_41 ( V_30 ) , NULL ) ;
}
if ( F_94 ( V_122 ) &&
F_95 ( F_41 ( V_30 ) , V_122 ) < 0 ) {
F_20 ( L_29
L_30 ,
F_48 ( V_7 -> V_30 ) ,
V_122 -> V_125 ) ;
return 1 ;
}
V_7 -> V_113 = 1 ;
return 0 ;
}
int F_98 ( struct V_6 * V_7 )
{
int V_54 ;
V_54 = F_80 ( V_7 ) ;
if ( V_54 ) {
F_78 ( L_31 ) ;
return V_54 ;
}
V_54 = F_91 ( V_7 ) ;
if ( V_54 ) {
F_78 ( L_32 ) ;
return V_54 ;
}
V_54 = F_96 ( V_7 , V_7 -> V_30 ) ;
if ( V_54 ) {
F_78 ( L_33 ) ;
return V_54 ;
}
V_54 = F_86 ( V_7 ) ;
if ( V_54 )
F_78 ( L_34 ) ;
return V_54 ;
}
void F_99 ( struct V_6 * V_7 ,
void (* F_100)( void * ) , void * V_126 )
{
F_101 ( & V_127 ) ;
V_7 -> V_128 = F_100 ;
V_7 -> V_129 = V_126 ;
F_102 ( & V_127 ) ;
}
void F_103 ( struct V_6 * V_7 )
{
F_36 ( F_104 () ) ;
F_101 ( & V_127 ) ;
if ( V_7 -> V_128 )
V_7 -> V_128 ( V_7 -> V_129 ) ;
F_102 ( & V_127 ) ;
}
T_1 F_105 ( struct V_6 * V_7 )
{
return V_7 -> V_23 ? ( V_7 -> V_25 [ V_7 -> V_23 - 1 ] + 1 ) : 0 ;
}
struct V_21 * F_75 ( struct V_6 * V_7 , unsigned int V_9 )
{
if ( V_9 >= V_7 -> V_23 )
return NULL ;
return V_7 -> V_26 + V_9 ;
}
struct V_21 * F_106 ( struct V_6 * V_7 , T_1 V_130 )
{
unsigned int V_8 , V_1 = 0 , V_4 = 0 ;
T_1 * V_13 ;
for ( V_8 = 0 ; V_8 < V_7 -> V_11 ; V_8 ++ ) {
V_1 = F_3 ( V_1 , V_4 ) ;
V_13 = F_4 ( V_7 , V_8 , V_1 ) ;
for ( V_4 = 0 ; V_4 < V_10 ; V_4 ++ )
if ( V_13 [ V_4 ] >= V_130 )
break;
}
return & V_7 -> V_26 [ ( V_10 * V_1 ) + V_4 ] ;
}
int F_107 ( struct V_6 * V_72 ,
struct V_62 * V_63 )
{
struct V_21 * V_77 ( V_56 ) ;
struct V_62 V_101 ;
unsigned V_44 = 0 ;
F_76 ( V_63 ) ;
while ( V_44 < F_74 ( V_72 ) ) {
F_76 ( & V_101 ) ;
V_56 = F_75 ( V_72 , V_44 ++ ) ;
if ( ! V_56 -> type -> V_102 )
goto V_131;
V_56 -> type -> V_102 ( V_56 , F_60 ,
& V_101 ) ;
if ( V_56 -> type -> V_132 )
V_56 -> type -> V_132 ( V_56 , & V_101 ) ;
if ( V_56 -> type -> V_102 ( V_56 , F_45 ,
& V_101 ) )
return - V_103 ;
V_131:
if ( F_108 ( V_63 , & V_101 , 0 ) < 0 )
F_20 ( L_35
L_36
L_37 ,
F_48 ( V_72 -> V_30 ) ,
( unsigned long long ) V_56 -> V_88 ,
( unsigned long long ) V_56 -> V_58 ) ;
}
return F_73 ( V_72 , V_63 ) ;
}
static void F_109 ( struct V_6 * V_7 )
{
struct V_119 * V_122 = NULL ;
if ( ! F_93 ( F_41 ( V_7 -> V_30 ) ) )
return;
V_122 = F_92 ( V_7 , true ) ;
if ( ! V_122 &&
F_94 ( F_41 ( V_7 -> V_30 ) ) ) {
F_20 ( L_38 ,
F_48 ( V_7 -> V_30 ) ) ;
return;
}
F_97 ( F_41 ( V_7 -> V_30 ) ,
F_93 ( V_122 ) ) ;
}
void F_110 ( struct V_6 * V_7 , struct V_60 * V_61 ,
struct V_62 * V_63 )
{
V_61 -> V_63 = * V_63 ;
if ( ! F_111 ( V_7 ) )
F_112 ( V_133 , V_61 ) ;
else
F_113 ( V_133 , V_61 ) ;
F_109 ( V_7 ) ;
F_24 () ;
if ( F_85 ( V_7 ) )
F_113 ( V_134 , V_61 ) ;
}
unsigned int F_74 ( struct V_6 * V_7 )
{
return V_7 -> V_23 ;
}
struct V_36 * F_82 ( struct V_6 * V_7 )
{
return & V_7 -> V_32 ;
}
T_2 F_114 ( struct V_6 * V_7 )
{
return V_7 -> V_28 ;
}
static void F_115 ( struct V_6 * V_7 , unsigned V_135 )
{
int V_44 = V_7 -> V_23 ;
struct V_21 * V_56 = V_7 -> V_26 ;
while ( V_44 -- ) {
if ( V_135 ) {
if ( V_56 -> type -> V_135 )
V_56 -> type -> V_135 ( V_56 ) ;
} else if ( V_56 -> type -> V_136 )
V_56 -> type -> V_136 ( V_56 ) ;
V_56 ++ ;
}
}
void F_116 ( struct V_6 * V_7 )
{
if ( ! V_7 )
return;
F_115 ( V_7 , 0 ) ;
}
void F_117 ( struct V_6 * V_7 )
{
if ( ! V_7 )
return;
F_115 ( V_7 , 1 ) ;
}
int F_118 ( struct V_6 * V_7 )
{
int V_44 , V_54 = 0 ;
for ( V_44 = 0 ; V_44 < V_7 -> V_23 ; V_44 ++ ) {
struct V_21 * V_56 = V_7 -> V_26 + V_44 ;
if ( ! V_56 -> type -> V_137 )
continue;
V_54 = V_56 -> type -> V_137 ( V_56 ) ;
if ( V_54 )
return V_54 ;
}
for ( V_44 = 0 ; V_44 < V_7 -> V_23 ; V_44 ++ ) {
struct V_21 * V_56 = V_7 -> V_26 + V_44 ;
if ( V_56 -> type -> V_138 )
V_56 -> type -> V_138 ( V_56 ) ;
}
return 0 ;
}
void F_119 ( struct V_6 * V_7 , struct V_139 * V_140 )
{
F_59 ( & V_140 -> V_41 , & V_7 -> V_33 ) ;
}
int F_120 ( struct V_6 * V_7 , int V_141 )
{
struct V_39 * V_40 ;
struct V_36 * V_32 = F_82 ( V_7 ) ;
struct V_139 * V_140 ;
int V_54 = 0 ;
F_34 (dd, devices, list) {
struct V_60 * V_61 = F_47 ( V_40 -> V_42 . V_49 ) ;
char V_69 [ V_70 ] ;
if ( F_121 ( V_61 ) )
V_54 |= F_122 ( & V_61 -> V_142 , V_141 ) ;
else
F_123 ( L_39 ,
F_48 ( V_7 -> V_30 ) ,
F_49 ( V_40 -> V_42 . V_49 , V_69 ) ) ;
}
F_34 (cb, &t->target_callbacks, list)
if ( V_140 -> V_143 )
V_54 |= V_140 -> V_143 ( V_140 , V_141 ) ;
return V_54 ;
}
int F_124 ( struct V_6 * V_7 )
{
unsigned V_44 ;
struct V_21 * V_56 ;
for ( V_44 = 0 ; V_44 < V_7 -> V_23 ; V_44 ++ ) {
V_56 = V_7 -> V_26 + V_44 ;
if ( V_56 -> type -> V_144 && V_56 -> type -> V_144 ( V_56 ) )
return 1 ;
}
return 0 ;
}
struct V_29 * F_125 ( struct V_6 * V_7 )
{
return V_7 -> V_30 ;
}
static int F_126 ( struct V_21 * V_56 , struct V_42 * V_48 ,
T_1 V_57 , T_1 V_58 , void * V_59 )
{
struct V_60 * V_61 = F_47 ( V_48 -> V_49 ) ;
return V_61 && F_127 ( V_61 ) ;
}
bool F_111 ( struct V_6 * V_7 )
{
struct V_21 * V_56 ;
unsigned V_44 = 0 ;
if ( ! V_7 -> V_35 )
return 0 ;
while ( V_44 < F_74 ( V_7 ) ) {
V_56 = F_75 ( V_7 , V_44 ++ ) ;
if ( V_56 -> V_35 )
return 1 ;
if ( V_56 -> type -> V_102 &&
V_56 -> type -> V_102 ( V_56 , F_126 , NULL ) )
return 1 ;
}
return 0 ;
}
