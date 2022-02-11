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
for ( V_42 = 0 ; V_42 < V_7 -> V_28 ; V_42 ++ ) {
struct V_21 * V_43 = V_7 -> V_26 + V_42 ;
if ( V_43 -> type -> V_44 )
V_43 -> type -> V_44 ( V_43 ) ;
F_21 ( V_43 -> type ) ;
}
F_10 ( V_7 -> V_24 ) ;
F_16 ( & V_7 -> V_32 ) ;
F_22 ( V_7 -> V_45 ) ;
F_15 ( V_7 ) ;
}
static struct V_37 * F_23 ( struct V_34 * V_8 , T_3 V_46 )
{
struct V_37 * V_38 ;
F_24 (dd, l, list)
if ( V_38 -> V_40 . V_47 -> V_48 == V_46 )
return V_38 ;
return NULL ;
}
static int F_25 ( struct V_37 * V_49 , T_3 V_46 ,
struct V_29 * V_30 )
{
static char * V_50 = L_2 ;
struct V_51 * V_47 ;
int V_52 ;
F_26 ( V_49 -> V_40 . V_47 ) ;
V_47 = F_27 ( V_46 , V_49 -> V_40 . V_27 | V_53 , V_50 ) ;
if ( F_28 ( V_47 ) )
return F_29 ( V_47 ) ;
V_52 = F_30 ( V_47 , F_31 ( V_30 ) ) ;
if ( V_52 ) {
F_32 ( V_47 , V_49 -> V_40 . V_27 | V_53 ) ;
return V_52 ;
}
V_49 -> V_40 . V_47 = V_47 ;
return 0 ;
}
static void F_33 ( struct V_37 * V_49 , struct V_29 * V_30 )
{
if ( ! V_49 -> V_40 . V_47 )
return;
F_34 ( V_49 -> V_40 . V_47 , F_31 ( V_30 ) ) ;
F_32 ( V_49 -> V_40 . V_47 , V_49 -> V_40 . V_27 | V_53 ) ;
V_49 -> V_40 . V_47 = NULL ;
}
static int F_35 ( struct V_21 * V_54 , struct V_40 * V_46 ,
T_1 V_55 , T_1 V_56 , void * V_57 )
{
struct V_58 * V_59 ;
struct V_60 * V_61 = V_57 ;
struct V_51 * V_47 = V_46 -> V_47 ;
T_1 V_62 =
F_36 ( V_47 -> V_63 ) >> V_64 ;
unsigned short V_65 =
V_61 -> V_66 >> V_64 ;
char V_67 [ V_68 ] ;
V_59 = F_37 ( V_47 ) ;
if ( ! V_59 || ! V_59 -> V_69 ) {
F_19 ( L_3
L_4 ,
F_38 ( V_54 -> V_70 -> V_30 ) , F_39 ( V_47 , V_67 ) ,
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
F_38 ( V_54 -> V_70 -> V_30 ) , F_39 ( V_47 , V_67 ) ,
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
F_38 ( V_54 -> V_70 -> V_30 ) ,
( unsigned long long ) V_55 ,
V_61 -> V_66 , F_39 ( V_47 , V_67 ) ) ;
return 1 ;
}
if ( V_56 & ( V_65 - 1 ) ) {
F_19 ( L_8
L_7 ,
F_38 ( V_54 -> V_70 -> V_30 ) ,
( unsigned long long ) V_56 ,
V_61 -> V_66 , F_39 ( V_47 , V_67 ) ) ;
return 1 ;
}
return 0 ;
}
static int F_40 ( struct V_37 * V_38 , T_2 V_71 ,
struct V_29 * V_30 )
{
int V_52 ;
struct V_37 V_72 , V_73 ;
V_72 = V_73 = * V_38 ;
V_72 . V_40 . V_27 |= V_71 ;
V_72 . V_40 . V_47 = NULL ;
V_52 = F_25 ( & V_72 , V_38 -> V_40 . V_47 -> V_48 , V_30 ) ;
if ( V_52 )
return V_52 ;
V_38 -> V_40 . V_27 |= V_71 ;
F_33 ( & V_73 , V_30 ) ;
return 0 ;
}
int F_41 ( struct V_21 * V_54 , const char * V_74 , T_2 V_27 ,
struct V_40 * * V_3 )
{
int V_52 ;
T_3 V_75 ( V_46 ) ;
struct V_37 * V_38 ;
unsigned int V_76 , V_77 ;
struct V_6 * V_7 = V_54 -> V_70 ;
char V_78 ;
F_26 ( ! V_7 ) ;
if ( sscanf ( V_74 , L_9 , & V_76 , & V_77 , & V_78 ) == 2 ) {
V_46 = F_42 ( V_76 , V_77 ) ;
if ( F_43 ( V_46 ) != V_76 || F_44 ( V_46 ) != V_77 )
return - V_79 ;
} else {
struct V_51 * V_47 = F_45 ( V_74 ) ;
if ( F_28 ( V_47 ) )
return F_29 ( V_47 ) ;
V_46 = V_47 -> V_48 ;
F_46 ( V_47 ) ;
}
V_38 = F_23 ( & V_7 -> V_32 , V_46 ) ;
if ( ! V_38 ) {
V_38 = F_47 ( sizeof( * V_38 ) , V_31 ) ;
if ( ! V_38 )
return - V_23 ;
V_38 -> V_40 . V_27 = V_27 ;
V_38 -> V_40 . V_47 = NULL ;
if ( ( V_52 = F_25 ( V_38 , V_46 , V_7 -> V_30 ) ) ) {
F_15 ( V_38 ) ;
return V_52 ;
}
F_48 ( V_38 -> V_40 . V_41 , V_46 ) ;
F_49 ( & V_38 -> V_80 , 0 ) ;
F_50 ( & V_38 -> V_39 , & V_7 -> V_32 ) ;
} else if ( V_38 -> V_40 . V_27 != ( V_27 | V_38 -> V_40 . V_27 ) ) {
V_52 = F_40 ( V_38 , V_27 , V_7 -> V_30 ) ;
if ( V_52 )
return V_52 ;
}
F_51 ( & V_38 -> V_80 ) ;
* V_3 = & V_38 -> V_40 ;
return 0 ;
}
static int F_52 ( struct V_21 * V_54 , struct V_40 * V_46 ,
T_1 V_55 , T_1 V_56 , void * V_57 )
{
struct V_60 * V_61 = V_57 ;
struct V_51 * V_47 = V_46 -> V_47 ;
struct V_58 * V_59 = F_37 ( V_47 ) ;
char V_67 [ V_68 ] ;
if ( F_53 ( ! V_59 ) ) {
F_19 ( L_10 ,
F_38 ( V_54 -> V_70 -> V_30 ) , F_39 ( V_47 , V_67 ) ) ;
return 0 ;
}
if ( F_54 ( V_61 , V_47 , V_55 ) < 0 )
F_19 ( L_11
L_12
L_13 ,
F_38 ( V_54 -> V_70 -> V_30 ) , F_39 ( V_47 , V_67 ) ,
V_59 -> V_61 . V_81 ,
V_59 -> V_61 . V_66 ,
V_59 -> V_61 . V_82 ,
( unsigned long long ) V_55 << V_64 ) ;
if ( F_55 ( V_59 ) && ! V_54 -> type -> V_83 )
F_56 ( V_61 ,
( unsigned int ) ( V_84 >> 9 ) ) ;
return 0 ;
}
void F_57 ( struct V_21 * V_54 , struct V_40 * V_49 )
{
struct V_37 * V_38 = F_58 ( V_49 , struct V_37 ,
V_40 ) ;
if ( F_59 ( & V_38 -> V_80 ) ) {
F_33 ( V_38 , V_54 -> V_70 -> V_30 ) ;
F_60 ( & V_38 -> V_39 ) ;
F_15 ( V_38 ) ;
}
}
static int F_61 ( struct V_6 * V_70 , struct V_21 * V_54 )
{
struct V_21 * V_85 ;
if ( ! V_70 -> V_28 )
return ! V_54 -> V_86 ;
V_85 = & V_70 -> V_26 [ V_70 -> V_28 - 1 ] ;
return ( V_54 -> V_86 == ( V_85 -> V_86 + V_85 -> V_56 ) ) ;
}
static char * * F_62 ( unsigned * V_87 , char * * V_88 )
{
char * * V_89 ;
unsigned V_90 ;
T_4 V_91 ;
if ( * V_87 ) {
V_90 = * V_87 * 2 ;
V_91 = V_31 ;
} else {
V_90 = 8 ;
V_91 = V_92 ;
}
V_89 = F_47 ( V_90 * sizeof( * V_89 ) , V_91 ) ;
if ( V_89 ) {
memcpy ( V_89 , V_88 , * V_87 * sizeof( * V_89 ) ) ;
* V_87 = V_90 ;
}
F_15 ( V_88 ) ;
return V_89 ;
}
int F_63 ( int * V_93 , char * * * V_94 , char * V_95 )
{
char * V_55 , * V_96 = V_95 , * V_97 , * * V_89 = NULL ;
unsigned V_87 = 0 ;
* V_93 = 0 ;
if ( ! V_95 ) {
* V_94 = NULL ;
return 0 ;
}
V_89 = F_62 ( & V_87 , V_89 ) ;
if ( ! V_89 )
return - V_23 ;
while ( 1 ) {
V_55 = F_64 ( V_96 ) ;
if ( ! * V_55 )
break;
V_96 = V_97 = V_55 ;
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
if ( ( * V_93 + 1 ) > V_87 ) {
V_89 = F_62 ( & V_87 , V_89 ) ;
if ( ! V_89 )
return - V_23 ;
}
if ( * V_96 )
V_96 ++ ;
* V_97 = '\0' ;
V_89 [ * V_93 ] = V_55 ;
( * V_93 ) ++ ;
}
* V_94 = V_89 ;
return 0 ;
}
static int F_65 ( struct V_6 * V_70 ,
struct V_60 * V_61 )
{
unsigned short V_98 =
V_61 -> V_66 >> V_64 ;
unsigned short V_99 = 0 ;
unsigned short V_100 = 0 ;
struct V_21 * V_75 ( V_54 ) ;
struct V_60 V_101 ;
unsigned V_42 = 0 ;
while ( V_42 < F_66 ( V_70 ) ) {
V_54 = F_67 ( V_70 , V_42 ++ ) ;
F_68 ( & V_101 ) ;
if ( V_54 -> type -> V_102 )
V_54 -> type -> V_102 ( V_54 , F_52 ,
& V_101 ) ;
if ( V_100 < V_54 -> V_56 &&
V_100 & ( ( V_101 . V_66 >>
V_64 ) - 1 ) )
break;
V_99 =
( unsigned short ) ( ( V_99 + V_54 -> V_56 ) &
( V_98 - 1 ) ) ;
V_100 = V_99 ?
V_98 - V_99 : 0 ;
}
if ( V_100 ) {
F_19 ( L_14
L_15 ,
F_38 ( V_70 -> V_30 ) , V_42 ,
( unsigned long long ) V_54 -> V_86 ,
( unsigned long long ) V_54 -> V_56 ,
V_61 -> V_66 ) ;
return - V_103 ;
}
return 0 ;
}
int F_69 ( struct V_6 * V_7 , const char * type ,
T_1 V_55 , T_1 V_56 , char * V_104 )
{
int V_52 = - V_103 , V_93 ;
char * * V_89 ;
struct V_21 * V_43 ;
if ( V_7 -> V_105 ) {
F_70 ( L_16 ,
F_38 ( V_7 -> V_30 ) , V_7 -> V_26 -> type -> V_41 ) ;
return - V_103 ;
}
F_26 ( V_7 -> V_28 >= V_7 -> V_25 ) ;
V_43 = V_7 -> V_26 + V_7 -> V_28 ;
memset ( V_43 , 0 , sizeof( * V_43 ) ) ;
if ( ! V_56 ) {
F_70 ( L_17 , F_38 ( V_7 -> V_30 ) ) ;
return - V_103 ;
}
V_43 -> type = F_71 ( type ) ;
if ( ! V_43 -> type ) {
F_70 ( L_18 , F_38 ( V_7 -> V_30 ) ,
type ) ;
return - V_103 ;
}
if ( F_72 ( V_43 -> type ) ) {
if ( V_7 -> V_28 ) {
F_70 ( L_16 ,
F_38 ( V_7 -> V_30 ) , type ) ;
return - V_103 ;
}
V_7 -> V_105 = 1 ;
}
if ( F_73 ( V_43 -> type ) && ! ( V_7 -> V_27 & V_106 ) ) {
F_70 ( L_19 ,
F_38 ( V_7 -> V_30 ) , type ) ;
return - V_103 ;
}
if ( V_7 -> V_107 ) {
if ( V_7 -> V_107 != V_43 -> type ) {
F_70 ( L_20 ,
F_38 ( V_7 -> V_30 ) , V_7 -> V_107 -> V_41 ) ;
return - V_103 ;
}
} else if ( F_74 ( V_43 -> type ) ) {
if ( V_7 -> V_28 ) {
F_70 ( L_20 ,
F_38 ( V_7 -> V_30 ) , V_43 -> type -> V_41 ) ;
return - V_103 ;
}
V_7 -> V_107 = V_43 -> type ;
}
V_43 -> V_70 = V_7 ;
V_43 -> V_86 = V_55 ;
V_43 -> V_56 = V_56 ;
V_43 -> error = L_21 ;
if ( ! F_61 ( V_7 , V_43 ) ) {
V_43 -> error = L_22 ;
V_52 = - V_103 ;
goto V_108;
}
V_52 = F_63 ( & V_93 , & V_89 , V_104 ) ;
if ( V_52 ) {
V_43 -> error = L_23 ;
goto V_108;
}
V_52 = V_43 -> type -> V_109 ( V_43 , V_93 , V_89 ) ;
F_15 ( V_89 ) ;
if ( V_52 )
goto V_108;
V_7 -> V_24 [ V_7 -> V_28 ++ ] = V_43 -> V_86 + V_43 -> V_56 - 1 ;
if ( ! V_43 -> V_110 && V_43 -> V_111 )
F_19 ( L_24 ,
F_38 ( V_7 -> V_30 ) , type ) ;
return 0 ;
V_108:
F_70 ( L_25 , F_38 ( V_7 -> V_30 ) , type , V_43 -> error ) ;
F_21 ( V_43 -> type ) ;
return V_52 ;
}
static int F_75 ( struct V_112 * V_113 , struct V_114 * V_115 ,
unsigned * V_116 , char * * error , unsigned V_117 )
{
const char * V_118 = F_76 ( V_115 ) ;
char V_78 ;
if ( ! V_118 ||
( sscanf ( V_118 , L_26 , V_116 , & V_78 ) != 1 ) ||
( * V_116 < V_113 -> V_119 ) ||
( * V_116 > V_113 -> V_120 ) ||
( V_117 && V_115 -> V_93 < * V_116 ) ) {
* error = V_113 -> error ;
return - V_103 ;
}
return 0 ;
}
int F_77 ( struct V_112 * V_113 , struct V_114 * V_115 ,
unsigned * V_116 , char * * error )
{
return F_75 ( V_113 , V_115 , V_116 , error , 0 ) ;
}
int F_78 ( struct V_112 * V_113 , struct V_114 * V_115 ,
unsigned * V_116 , char * * error )
{
return F_75 ( V_113 , V_115 , V_116 , error , 1 ) ;
}
const char * F_76 ( struct V_114 * V_121 )
{
char * V_52 ;
if ( V_121 -> V_93 ) {
V_121 -> V_93 -- ;
V_52 = * V_121 -> V_89 ;
V_121 -> V_89 ++ ;
return V_52 ;
}
return NULL ;
}
void F_79 ( struct V_114 * V_121 , unsigned V_122 )
{
F_26 ( V_121 -> V_93 < V_122 ) ;
V_121 -> V_93 -= V_122 ;
V_121 -> V_89 += V_122 ;
}
static int F_80 ( struct V_6 * V_7 )
{
unsigned V_42 ;
unsigned V_123 = 0 , V_124 = 0 , V_125 = 0 ;
struct V_21 * V_43 ;
struct V_37 * V_38 ;
struct V_34 * V_32 ;
unsigned V_126 ;
for ( V_42 = 0 ; V_42 < V_7 -> V_28 ; V_42 ++ ) {
V_43 = V_7 -> V_26 + V_42 ;
if ( F_81 ( V_43 ) )
V_125 = 1 ;
else if ( F_82 ( V_43 ) )
V_124 = 1 ;
else
V_123 = 1 ;
if ( V_123 && V_124 ) {
F_19 ( L_27
L_28 ) ;
return - V_103 ;
}
}
if ( V_125 && ! V_123 && ! V_124 ) {
V_126 = F_83 ( V_7 -> V_30 ) ;
if ( V_126 == V_127 )
V_124 = 1 ;
else
V_123 = 1 ;
}
if ( V_123 ) {
V_7 -> type = V_128 ;
return 0 ;
}
F_26 ( ! V_124 ) ;
V_32 = F_84 ( V_7 ) ;
F_24 (dd, devices, list) {
if ( ! F_85 ( F_37 ( V_38 -> V_40 . V_47 ) ) ) {
F_19 ( L_29
L_30 ) ;
return - V_103 ;
}
}
if ( V_7 -> V_28 > 1 ) {
F_19 ( L_31 ) ;
return - V_103 ;
}
V_7 -> type = V_127 ;
return 0 ;
}
unsigned F_86 ( struct V_6 * V_7 )
{
return V_7 -> type ;
}
struct V_129 * F_87 ( struct V_6 * V_7 )
{
return V_7 -> V_107 ;
}
bool F_88 ( struct V_6 * V_7 )
{
return F_86 ( V_7 ) == V_127 ;
}
static int F_89 ( struct V_6 * V_7 )
{
unsigned type = F_86 ( V_7 ) ;
unsigned V_130 = 0 ;
struct V_21 * V_43 ;
unsigned V_42 ;
if ( F_53 ( type == V_131 ) ) {
F_19 ( L_32 ) ;
return - V_103 ;
}
if ( type == V_128 )
for ( V_42 = 0 ; V_42 < V_7 -> V_28 ; V_42 ++ ) {
V_43 = V_7 -> V_26 + V_42 ;
V_130 = V_120 ( V_130 , V_43 -> V_130 ) ;
}
V_7 -> V_45 = F_90 ( type , V_7 -> V_132 , V_130 ) ;
if ( ! V_7 -> V_45 )
return - V_23 ;
return 0 ;
}
void F_91 ( struct V_6 * V_7 )
{
F_22 ( V_7 -> V_45 ) ;
V_7 -> V_45 = NULL ;
}
struct V_133 * F_92 ( struct V_6 * V_7 )
{
return V_7 -> V_45 ;
}
static int F_93 ( struct V_6 * V_7 )
{
int V_42 ;
unsigned int V_134 = 0 ;
T_1 * V_135 ;
for ( V_42 = V_7 -> V_11 - 2 ; V_42 >= 0 ; V_42 -- ) {
V_7 -> V_12 [ V_42 ] = F_2 ( V_7 -> V_12 [ V_42 + 1 ] , V_5 ) ;
V_134 += V_7 -> V_12 [ V_42 ] ;
}
V_135 = ( T_1 * ) F_7 ( V_134 , ( unsigned long ) V_136 ) ;
if ( ! V_135 )
return - V_23 ;
for ( V_42 = V_7 -> V_11 - 2 ; V_42 >= 0 ; V_42 -- ) {
V_7 -> V_9 [ V_42 ] = V_135 ;
V_135 += ( V_10 * V_7 -> V_12 [ V_42 ] ) ;
F_6 ( V_42 , V_7 ) ;
}
return 0 ;
}
static int F_94 ( struct V_6 * V_7 )
{
int V_52 = 0 ;
unsigned int V_137 ;
V_137 = F_2 ( V_7 -> V_28 , V_10 ) ;
V_7 -> V_11 = 1 + F_1 ( V_137 , V_5 ) ;
V_7 -> V_12 [ V_7 -> V_11 - 1 ] = V_137 ;
V_7 -> V_9 [ V_7 -> V_11 - 1 ] = V_7 -> V_24 ;
if ( V_7 -> V_11 >= 2 )
V_52 = F_93 ( V_7 ) ;
return V_52 ;
}
static struct V_138 * F_95 ( struct V_6 * V_7 ,
bool V_139 )
{
struct V_34 * V_32 = F_84 ( V_7 ) ;
struct V_37 * V_38 = NULL ;
struct V_138 * V_140 = NULL , * V_141 = NULL ;
F_24 (dd, devices, list) {
V_141 = V_38 -> V_40 . V_47 -> V_142 ;
if ( ! F_96 ( V_141 ) )
goto V_143;
if ( ! V_139 && ! F_97 ( V_141 ) )
continue;
else if ( V_140 &&
F_98 ( V_140 , V_141 ) < 0 )
goto V_143;
V_140 = V_141 ;
}
return V_141 ;
V_143:
if ( V_140 )
F_19 ( L_33 ,
F_38 ( V_7 -> V_30 ) ,
V_140 -> V_144 ,
V_141 -> V_144 ) ;
return NULL ;
}
static int F_99 ( struct V_6 * V_7 , struct V_29 * V_30 )
{
struct V_138 * V_141 = NULL ;
V_141 = F_95 ( V_7 , false ) ;
if ( ! V_141 )
return 0 ;
if ( ! F_97 ( F_31 ( V_30 ) ) ) {
V_7 -> V_132 = 1 ;
return F_100 ( F_31 ( V_30 ) , NULL ) ;
}
if ( F_97 ( V_141 ) &&
F_98 ( F_31 ( V_30 ) , V_141 ) < 0 ) {
F_19 ( L_34
L_35 ,
F_38 ( V_7 -> V_30 ) ,
V_141 -> V_144 ) ;
return 1 ;
}
V_7 -> V_132 = 1 ;
return 0 ;
}
int F_101 ( struct V_6 * V_7 )
{
int V_52 ;
V_52 = F_80 ( V_7 ) ;
if ( V_52 ) {
F_70 ( L_36 ) ;
return V_52 ;
}
V_52 = F_94 ( V_7 ) ;
if ( V_52 ) {
F_70 ( L_37 ) ;
return V_52 ;
}
V_52 = F_99 ( V_7 , V_7 -> V_30 ) ;
if ( V_52 ) {
F_70 ( L_38 ) ;
return V_52 ;
}
V_52 = F_89 ( V_7 ) ;
if ( V_52 )
F_70 ( L_39 ) ;
return V_52 ;
}
void F_102 ( struct V_6 * V_7 ,
void (* F_103)( void * ) , void * V_145 )
{
F_104 ( & V_146 ) ;
V_7 -> V_147 = F_103 ;
V_7 -> V_148 = V_145 ;
F_105 ( & V_146 ) ;
}
void F_106 ( struct V_6 * V_7 )
{
F_26 ( F_107 () ) ;
F_104 ( & V_146 ) ;
if ( V_7 -> V_147 )
V_7 -> V_147 ( V_7 -> V_148 ) ;
F_105 ( & V_146 ) ;
}
T_1 F_108 ( struct V_6 * V_7 )
{
return V_7 -> V_28 ? ( V_7 -> V_24 [ V_7 -> V_28 - 1 ] + 1 ) : 0 ;
}
struct V_21 * F_67 ( struct V_6 * V_7 , unsigned int V_9 )
{
if ( V_9 >= V_7 -> V_28 )
return NULL ;
return V_7 -> V_26 + V_9 ;
}
struct V_21 * F_109 ( struct V_6 * V_7 , T_1 V_149 )
{
unsigned int V_8 , V_1 = 0 , V_4 = 0 ;
T_1 * V_13 ;
for ( V_8 = 0 ; V_8 < V_7 -> V_11 ; V_8 ++ ) {
V_1 = F_3 ( V_1 , V_4 ) ;
V_13 = F_4 ( V_7 , V_8 , V_1 ) ;
for ( V_4 = 0 ; V_4 < V_10 ; V_4 ++ )
if ( V_13 [ V_4 ] >= V_149 )
break;
}
return & V_7 -> V_26 [ ( V_10 * V_1 ) + V_4 ] ;
}
static int F_110 ( struct V_21 * V_54 , struct V_40 * V_46 ,
T_1 V_55 , T_1 V_56 , void * V_57 )
{
unsigned * V_150 = V_57 ;
( * V_150 ) ++ ;
return 0 ;
}
bool F_111 ( struct V_6 * V_70 )
{
struct V_21 * V_75 ( V_54 ) ;
unsigned V_42 = 0 , V_150 = 0 ;
while ( V_42 < F_66 ( V_70 ) ) {
V_54 = F_67 ( V_70 , V_42 ++ ) ;
if ( ! V_54 -> type -> V_102 )
return false ;
V_54 -> type -> V_102 ( V_54 , F_110 , & V_150 ) ;
if ( V_150 )
return false ;
}
return true ;
}
int F_112 ( struct V_6 * V_70 ,
struct V_60 * V_61 )
{
struct V_21 * V_75 ( V_54 ) ;
struct V_60 V_101 ;
unsigned V_42 = 0 ;
F_68 ( V_61 ) ;
while ( V_42 < F_66 ( V_70 ) ) {
F_68 ( & V_101 ) ;
V_54 = F_67 ( V_70 , V_42 ++ ) ;
if ( ! V_54 -> type -> V_102 )
goto V_151;
V_54 -> type -> V_102 ( V_54 , F_52 ,
& V_101 ) ;
if ( V_54 -> type -> V_152 )
V_54 -> type -> V_152 ( V_54 , & V_101 ) ;
if ( V_54 -> type -> V_102 ( V_54 , F_35 ,
& V_101 ) )
return - V_103 ;
V_151:
if ( F_113 ( V_61 , & V_101 , 0 ) < 0 )
F_19 ( L_40
L_41
L_42 ,
F_38 ( V_70 -> V_30 ) ,
( unsigned long long ) V_54 -> V_86 ,
( unsigned long long ) V_54 -> V_56 ) ;
}
return F_65 ( V_70 , V_61 ) ;
}
static void F_114 ( struct V_6 * V_7 )
{
struct V_138 * V_141 = NULL ;
if ( ! F_96 ( F_31 ( V_7 -> V_30 ) ) )
return;
V_141 = F_95 ( V_7 , true ) ;
if ( V_141 )
F_100 ( F_31 ( V_7 -> V_30 ) ,
F_96 ( V_141 ) ) ;
else if ( F_97 ( F_31 ( V_7 -> V_30 ) ) )
F_19 ( L_43 ,
F_38 ( V_7 -> V_30 ) ) ;
else
F_19 ( L_44 ,
F_38 ( V_7 -> V_30 ) ) ;
}
static int F_115 ( struct V_21 * V_54 , struct V_40 * V_46 ,
T_1 V_55 , T_1 V_56 , void * V_57 )
{
unsigned V_153 = ( * ( unsigned * ) V_57 ) ;
struct V_58 * V_59 = F_37 ( V_46 -> V_47 ) ;
return V_59 && ( V_59 -> V_154 & V_153 ) ;
}
static bool F_116 ( struct V_6 * V_7 , unsigned V_153 )
{
struct V_21 * V_54 ;
unsigned V_42 = 0 ;
while ( V_42 < F_66 ( V_7 ) ) {
V_54 = F_67 ( V_7 , V_42 ++ ) ;
if ( ! V_54 -> V_155 )
continue;
if ( V_54 -> V_156 )
return 1 ;
if ( V_54 -> type -> V_102 &&
V_54 -> type -> V_102 ( V_54 , F_115 , & V_153 ) )
return 1 ;
}
return 0 ;
}
static bool F_117 ( struct V_6 * V_7 )
{
struct V_21 * V_54 ;
unsigned V_42 = 0 ;
while ( V_42 < F_66 ( V_7 ) ) {
V_54 = F_67 ( V_7 , V_42 ++ ) ;
if ( V_54 -> V_157 )
return 0 ;
}
return 1 ;
}
static int F_118 ( struct V_21 * V_54 , struct V_40 * V_46 ,
T_1 V_55 , T_1 V_56 , void * V_57 )
{
struct V_58 * V_59 = F_37 ( V_46 -> V_47 ) ;
return V_59 && F_119 ( V_59 ) ;
}
static int F_120 ( struct V_21 * V_54 , struct V_40 * V_46 ,
T_1 V_55 , T_1 V_56 , void * V_57 )
{
struct V_58 * V_59 = F_37 ( V_46 -> V_47 ) ;
return V_59 && ! F_121 ( V_59 ) ;
}
static int F_122 ( struct V_21 * V_54 , struct V_40 * V_46 ,
T_1 V_55 , T_1 V_56 , void * V_57 )
{
struct V_58 * V_59 = F_37 ( V_46 -> V_47 ) ;
return V_59 && ! F_123 ( V_158 , & V_59 -> V_159 ) ;
}
static bool F_124 ( struct V_6 * V_7 ,
T_5 V_160 )
{
struct V_21 * V_54 ;
unsigned V_42 = 0 ;
while ( V_42 < F_66 ( V_7 ) ) {
V_54 = F_67 ( V_7 , V_42 ++ ) ;
if ( ! V_54 -> type -> V_102 ||
! V_54 -> type -> V_102 ( V_54 , V_160 , NULL ) )
return 0 ;
}
return 1 ;
}
static int F_125 ( struct V_21 * V_54 , struct V_40 * V_46 ,
T_1 V_55 , T_1 V_56 , void * V_57 )
{
struct V_58 * V_59 = F_37 ( V_46 -> V_47 ) ;
return V_59 && ! V_59 -> V_61 . V_161 ;
}
static bool F_126 ( struct V_6 * V_7 )
{
struct V_21 * V_54 ;
unsigned V_42 = 0 ;
while ( V_42 < F_66 ( V_7 ) ) {
V_54 = F_67 ( V_7 , V_42 ++ ) ;
if ( ! V_54 -> V_162 )
return false ;
if ( ! V_54 -> type -> V_102 ||
V_54 -> type -> V_102 ( V_54 , F_125 , NULL ) )
return false ;
}
return true ;
}
static int F_127 ( struct V_21 * V_54 , struct V_40 * V_46 ,
T_1 V_55 , T_1 V_56 , void * V_57 )
{
struct V_58 * V_59 = F_37 ( V_46 -> V_47 ) ;
return V_59 && F_128 ( V_59 ) ;
}
static bool F_129 ( struct V_6 * V_7 )
{
struct V_21 * V_54 ;
unsigned V_42 = 0 ;
while ( V_42 < F_66 ( V_7 ) ) {
V_54 = F_67 ( V_7 , V_42 ++ ) ;
if ( ! V_54 -> V_110 )
continue;
if ( V_54 -> V_111 )
return 1 ;
if ( V_54 -> type -> V_102 &&
V_54 -> type -> V_102 ( V_54 , F_127 , NULL ) )
return 1 ;
}
return 0 ;
}
void F_130 ( struct V_6 * V_7 , struct V_58 * V_59 ,
struct V_60 * V_61 )
{
unsigned V_153 = 0 ;
V_59 -> V_61 = * V_61 ;
if ( ! F_129 ( V_7 ) )
F_131 ( V_163 , V_59 ) ;
else
F_132 ( V_163 , V_59 ) ;
if ( F_116 ( V_7 , V_164 ) ) {
V_153 |= V_164 ;
if ( F_116 ( V_7 , V_165 ) )
V_153 |= V_165 ;
}
F_133 ( V_59 , V_153 ) ;
if ( ! F_117 ( V_7 ) )
V_59 -> V_61 . V_166 = 0 ;
if ( F_124 ( V_7 , F_118 ) )
F_132 ( V_167 , V_59 ) ;
else
F_131 ( V_167 , V_59 ) ;
if ( ! F_126 ( V_7 ) )
V_59 -> V_61 . V_161 = 0 ;
if ( F_124 ( V_7 , F_122 ) )
F_131 ( V_158 , V_59 ) ;
else
F_132 ( V_158 , V_59 ) ;
F_114 ( V_7 ) ;
if ( F_121 ( V_59 ) && F_124 ( V_7 , F_120 ) )
F_131 ( V_168 , V_59 ) ;
F_134 () ;
if ( F_88 ( V_7 ) )
F_132 ( V_169 , V_59 ) ;
}
unsigned int F_66 ( struct V_6 * V_7 )
{
return V_7 -> V_28 ;
}
struct V_34 * F_84 ( struct V_6 * V_7 )
{
return & V_7 -> V_32 ;
}
T_2 F_135 ( struct V_6 * V_7 )
{
return V_7 -> V_27 ;
}
static void F_136 ( struct V_6 * V_7 , unsigned V_170 )
{
int V_42 = V_7 -> V_28 ;
struct V_21 * V_54 = V_7 -> V_26 ;
while ( V_42 -- ) {
if ( V_170 ) {
if ( V_54 -> type -> V_170 )
V_54 -> type -> V_170 ( V_54 ) ;
} else if ( V_54 -> type -> V_171 )
V_54 -> type -> V_171 ( V_54 ) ;
V_54 ++ ;
}
}
void F_137 ( struct V_6 * V_7 )
{
if ( ! V_7 )
return;
F_136 ( V_7 , 0 ) ;
}
void F_138 ( struct V_6 * V_7 )
{
if ( ! V_7 )
return;
F_136 ( V_7 , 1 ) ;
}
int F_139 ( struct V_6 * V_7 )
{
int V_42 , V_52 = 0 ;
for ( V_42 = 0 ; V_42 < V_7 -> V_28 ; V_42 ++ ) {
struct V_21 * V_54 = V_7 -> V_26 + V_42 ;
if ( ! V_54 -> type -> V_172 )
continue;
V_52 = V_54 -> type -> V_172 ( V_54 ) ;
if ( V_52 ) {
F_70 ( L_45 ,
F_38 ( V_7 -> V_30 ) , V_54 -> type -> V_41 , V_52 ) ;
return V_52 ;
}
}
for ( V_42 = 0 ; V_42 < V_7 -> V_28 ; V_42 ++ ) {
struct V_21 * V_54 = V_7 -> V_26 + V_42 ;
if ( V_54 -> type -> V_173 )
V_54 -> type -> V_173 ( V_54 ) ;
}
return 0 ;
}
void F_140 ( struct V_6 * V_7 , struct V_174 * V_175 )
{
F_50 ( & V_175 -> V_39 , & V_7 -> V_33 ) ;
}
int F_141 ( struct V_6 * V_7 , int V_176 )
{
struct V_37 * V_38 ;
struct V_34 * V_32 = F_84 ( V_7 ) ;
struct V_174 * V_175 ;
int V_52 = 0 ;
F_24 (dd, devices, list) {
struct V_58 * V_59 = F_37 ( V_38 -> V_40 . V_47 ) ;
char V_67 [ V_68 ] ;
if ( F_142 ( V_59 ) )
V_52 |= F_143 ( & V_59 -> V_177 , V_176 ) ;
else
F_144 ( L_46 ,
F_38 ( V_7 -> V_30 ) ,
F_39 ( V_38 -> V_40 . V_47 , V_67 ) ) ;
}
F_24 (cb, &t->target_callbacks, list)
if ( V_175 -> V_178 )
V_52 |= V_175 -> V_178 ( V_175 , V_176 ) ;
return V_52 ;
}
int F_145 ( struct V_6 * V_7 )
{
unsigned V_42 ;
struct V_21 * V_54 ;
for ( V_42 = 0 ; V_42 < V_7 -> V_28 ; V_42 ++ ) {
V_54 = V_7 -> V_26 + V_42 ;
if ( V_54 -> type -> V_179 && V_54 -> type -> V_179 ( V_54 ) )
return 1 ;
}
return 0 ;
}
struct V_29 * F_146 ( struct V_6 * V_7 )
{
return V_7 -> V_30 ;
}
void F_147 ( struct V_6 * V_7 )
{
struct V_29 * V_30 ;
struct V_58 * V_180 ;
unsigned long V_181 ;
if ( ! F_88 ( V_7 ) )
return;
V_30 = F_146 ( V_7 ) ;
V_180 = F_148 ( V_30 ) ;
if ( V_180 ) {
F_149 ( V_180 -> V_182 , V_181 ) ;
F_150 ( V_180 ) ;
F_151 ( V_180 -> V_182 , V_181 ) ;
}
}
