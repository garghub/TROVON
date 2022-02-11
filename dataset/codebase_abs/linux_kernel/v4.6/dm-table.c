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
T_3 F_33 ( const char * V_71 )
{
T_3 V_72 ( V_46 ) ;
struct V_57 * V_47 ;
V_47 = F_34 ( V_71 ) ;
if ( F_35 ( V_47 ) )
V_46 = F_36 ( V_71 ) ;
else {
V_46 = V_47 -> V_48 ;
F_37 ( V_47 ) ;
}
return V_46 ;
}
int F_38 ( struct V_21 * V_49 , const char * V_71 , T_2 V_27 ,
struct V_40 * * V_3 )
{
int V_68 ;
T_3 V_46 ;
struct V_37 * V_38 ;
struct V_6 * V_7 = V_49 -> V_66 ;
F_39 ( ! V_7 ) ;
V_46 = F_33 ( V_71 ) ;
if ( ! V_46 )
return - V_73 ;
V_38 = F_25 ( & V_7 -> V_32 , V_46 ) ;
if ( ! V_38 ) {
V_38 = F_40 ( sizeof( * V_38 ) , V_31 ) ;
if ( ! V_38 )
return - V_23 ;
if ( ( V_68 = F_32 ( V_7 -> V_30 , V_46 , V_27 , & V_38 -> V_40 ) ) ) {
F_15 ( V_38 ) ;
return V_68 ;
}
F_41 ( & V_38 -> V_74 , 0 ) ;
F_42 ( & V_38 -> V_39 , & V_7 -> V_32 ) ;
} else if ( V_38 -> V_40 -> V_27 != ( V_27 | V_38 -> V_40 -> V_27 ) ) {
V_68 = F_31 ( V_38 , V_27 , V_7 -> V_30 ) ;
if ( V_68 )
return V_68 ;
}
F_43 ( & V_38 -> V_74 ) ;
* V_3 = V_38 -> V_40 ;
return 0 ;
}
static int F_44 ( struct V_21 * V_49 , struct V_40 * V_46 ,
T_1 V_50 , T_1 V_51 , void * V_52 )
{
struct V_55 * V_56 = V_52 ;
struct V_57 * V_47 = V_46 -> V_47 ;
struct V_53 * V_54 = F_29 ( V_47 ) ;
char V_63 [ V_64 ] ;
if ( F_45 ( ! V_54 ) ) {
F_19 ( L_8 ,
F_20 ( V_49 -> V_66 -> V_30 ) , F_30 ( V_47 , V_63 ) ) ;
return 0 ;
}
if ( F_46 ( V_56 , V_47 , V_50 ) < 0 )
F_19 ( L_9
L_10
L_11 ,
F_20 ( V_49 -> V_66 -> V_30 ) , F_30 ( V_47 , V_63 ) ,
V_54 -> V_56 . V_75 ,
V_54 -> V_56 . V_62 ,
V_54 -> V_56 . V_76 ,
( unsigned long long ) V_50 << V_60 ) ;
return 0 ;
}
void F_47 ( struct V_21 * V_49 , struct V_40 * V_77 )
{
int V_78 = 0 ;
struct V_34 * V_32 = & V_49 -> V_66 -> V_32 ;
struct V_37 * V_38 ;
F_26 (dd, devices, list) {
if ( V_38 -> V_40 == V_77 ) {
V_78 = 1 ;
break;
}
}
if ( ! V_78 ) {
F_19 ( L_12 ,
F_20 ( V_49 -> V_66 -> V_30 ) , V_77 -> V_41 ) ;
return;
}
if ( F_48 ( & V_38 -> V_74 ) ) {
F_21 ( V_49 -> V_66 -> V_30 , V_77 ) ;
F_49 ( & V_38 -> V_39 ) ;
F_15 ( V_38 ) ;
}
}
static int F_50 ( struct V_6 * V_66 , struct V_21 * V_49 )
{
struct V_21 * V_79 ;
if ( ! V_66 -> V_28 )
return ! V_49 -> V_80 ;
V_79 = & V_66 -> V_26 [ V_66 -> V_28 - 1 ] ;
return ( V_49 -> V_80 == ( V_79 -> V_80 + V_79 -> V_51 ) ) ;
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
char * V_50 , * V_90 = V_89 , * V_91 , * * V_83 = NULL ;
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
V_50 = F_53 ( V_90 ) ;
if ( ! * V_50 )
break;
V_90 = V_91 = V_50 ;
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
V_83 [ * V_87 ] = V_50 ;
( * V_87 ) ++ ;
}
* V_88 = V_83 ;
return 0 ;
}
static int F_54 ( struct V_6 * V_66 ,
struct V_55 * V_56 )
{
unsigned short V_92 =
V_56 -> V_62 >> V_60 ;
unsigned short V_93 = 0 ;
unsigned short V_94 = 0 ;
struct V_21 * V_72 ( V_49 ) ;
struct V_55 V_95 ;
unsigned V_42 = 0 ;
while ( V_42 < F_55 ( V_66 ) ) {
V_49 = F_56 ( V_66 , V_42 ++ ) ;
F_57 ( & V_95 ) ;
if ( V_49 -> type -> V_96 )
V_49 -> type -> V_96 ( V_49 , F_44 ,
& V_95 ) ;
if ( V_94 < V_49 -> V_51 &&
V_94 & ( ( V_95 . V_62 >>
V_60 ) - 1 ) )
break;
V_93 =
( unsigned short ) ( ( V_93 + V_49 -> V_51 ) &
( V_92 - 1 ) ) ;
V_94 = V_93 ?
V_92 - V_93 : 0 ;
}
if ( V_94 ) {
F_19 ( L_13
L_14 ,
F_20 ( V_66 -> V_30 ) , V_42 ,
( unsigned long long ) V_49 -> V_80 ,
( unsigned long long ) V_49 -> V_51 ,
V_56 -> V_62 ) ;
return - V_97 ;
}
return 0 ;
}
int F_58 ( struct V_6 * V_7 , const char * type ,
T_1 V_50 , T_1 V_51 , char * V_98 )
{
int V_68 = - V_97 , V_87 ;
char * * V_83 ;
struct V_21 * V_43 ;
if ( V_7 -> V_99 ) {
F_59 ( L_15 ,
F_20 ( V_7 -> V_30 ) , V_7 -> V_26 -> type -> V_41 ) ;
return - V_97 ;
}
F_39 ( V_7 -> V_28 >= V_7 -> V_25 ) ;
V_43 = V_7 -> V_26 + V_7 -> V_28 ;
memset ( V_43 , 0 , sizeof( * V_43 ) ) ;
if ( ! V_51 ) {
F_59 ( L_16 , F_20 ( V_7 -> V_30 ) ) ;
return - V_97 ;
}
V_43 -> type = F_60 ( type ) ;
if ( ! V_43 -> type ) {
F_59 ( L_17 , F_20 ( V_7 -> V_30 ) ,
type ) ;
return - V_97 ;
}
if ( F_61 ( V_43 -> type ) ) {
if ( V_7 -> V_28 ) {
F_59 ( L_15 ,
F_20 ( V_7 -> V_30 ) , type ) ;
return - V_97 ;
}
V_7 -> V_99 = 1 ;
}
if ( F_62 ( V_43 -> type ) && ! ( V_7 -> V_27 & V_100 ) ) {
F_59 ( L_18 ,
F_20 ( V_7 -> V_30 ) , type ) ;
return - V_97 ;
}
if ( V_7 -> V_101 ) {
if ( V_7 -> V_101 != V_43 -> type ) {
F_59 ( L_19 ,
F_20 ( V_7 -> V_30 ) , V_7 -> V_101 -> V_41 ) ;
return - V_97 ;
}
} else if ( F_63 ( V_43 -> type ) ) {
if ( V_7 -> V_28 ) {
F_59 ( L_19 ,
F_20 ( V_7 -> V_30 ) , V_43 -> type -> V_41 ) ;
return - V_97 ;
}
V_7 -> V_101 = V_43 -> type ;
}
V_43 -> V_66 = V_7 ;
V_43 -> V_80 = V_50 ;
V_43 -> V_51 = V_51 ;
V_43 -> error = L_20 ;
if ( ! F_50 ( V_7 , V_43 ) ) {
V_43 -> error = L_21 ;
V_68 = - V_97 ;
goto V_102;
}
V_68 = F_52 ( & V_87 , & V_83 , V_98 ) ;
if ( V_68 ) {
V_43 -> error = L_22 ;
goto V_102;
}
V_68 = V_43 -> type -> V_103 ( V_43 , V_87 , V_83 ) ;
F_15 ( V_83 ) ;
if ( V_68 )
goto V_102;
V_7 -> V_24 [ V_7 -> V_28 ++ ] = V_43 -> V_80 + V_43 -> V_51 - 1 ;
if ( ! V_43 -> V_104 && V_43 -> V_105 )
F_19 ( L_23 ,
F_20 ( V_7 -> V_30 ) , type ) ;
return 0 ;
V_102:
F_59 ( L_24 , F_20 ( V_7 -> V_30 ) , type , V_43 -> error ) ;
F_23 ( V_43 -> type ) ;
return V_68 ;
}
static int F_64 ( struct V_106 * V_107 , struct V_108 * V_109 ,
unsigned * V_110 , char * * error , unsigned V_111 )
{
const char * V_112 = F_65 ( V_109 ) ;
char V_113 ;
if ( ! V_112 ||
( sscanf ( V_112 , L_25 , V_110 , & V_113 ) != 1 ) ||
( * V_110 < V_107 -> V_114 ) ||
( * V_110 > V_107 -> V_115 ) ||
( V_111 && V_109 -> V_87 < * V_110 ) ) {
* error = V_107 -> error ;
return - V_97 ;
}
return 0 ;
}
int F_66 ( struct V_106 * V_107 , struct V_108 * V_109 ,
unsigned * V_110 , char * * error )
{
return F_64 ( V_107 , V_109 , V_110 , error , 0 ) ;
}
int F_67 ( struct V_106 * V_107 , struct V_108 * V_109 ,
unsigned * V_110 , char * * error )
{
return F_64 ( V_107 , V_109 , V_110 , error , 1 ) ;
}
const char * F_65 ( struct V_108 * V_116 )
{
char * V_68 ;
if ( V_116 -> V_87 ) {
V_116 -> V_87 -- ;
V_68 = * V_116 -> V_83 ;
V_116 -> V_83 ++ ;
return V_68 ;
}
return NULL ;
}
void F_68 ( struct V_108 * V_116 , unsigned V_117 )
{
F_39 ( V_116 -> V_87 < V_117 ) ;
V_116 -> V_87 -= V_117 ;
V_116 -> V_83 += V_117 ;
}
static bool F_69 ( unsigned V_118 )
{
return ( V_118 == V_119 ||
V_118 == V_120 ) ;
}
static int F_70 ( struct V_6 * V_7 )
{
unsigned V_42 ;
unsigned V_121 = 0 , V_122 = 0 , V_123 = 0 ;
bool V_124 = false ;
struct V_21 * V_43 ;
struct V_37 * V_38 ;
struct V_34 * V_32 ;
unsigned V_125 = F_71 ( V_7 -> V_30 ) ;
for ( V_42 = 0 ; V_42 < V_7 -> V_28 ; V_42 ++ ) {
V_43 = V_7 -> V_26 + V_42 ;
if ( F_72 ( V_43 ) )
V_123 = 1 ;
else if ( F_73 ( V_43 ) )
V_122 = 1 ;
else
V_121 = 1 ;
if ( V_121 && V_122 ) {
F_19 ( L_26
L_27 ) ;
return - V_97 ;
}
}
if ( V_123 && ! V_121 && ! V_122 ) {
if ( F_69 ( V_125 ) )
V_122 = 1 ;
else
V_121 = 1 ;
}
if ( V_121 ) {
V_7 -> type = V_126 ;
return 0 ;
}
F_39 ( ! V_122 ) ;
if ( V_7 -> V_28 > 1 ) {
F_19 ( L_28 ) ;
return - V_97 ;
}
V_32 = F_74 ( V_7 ) ;
F_26 (dd, devices, list) {
struct V_53 * V_54 = F_29 ( V_38 -> V_40 -> V_47 ) ;
if ( ! F_75 ( V_54 ) ) {
F_59 ( L_29
L_30 ) ;
return - V_97 ;
}
if ( V_54 -> V_127 )
V_124 = true ;
}
if ( V_124 ) {
F_26 (dd, devices, list)
if ( ! F_29 ( V_38 -> V_40 -> V_47 ) -> V_127 ) {
F_59 ( L_31
L_32 ) ;
return - V_97 ;
}
V_7 -> type = V_120 ;
} else if ( F_76 ( V_32 ) && F_69 ( V_125 ) ) {
V_7 -> type = V_125 ;
} else
V_7 -> type = V_119 ;
return 0 ;
}
unsigned F_77 ( struct V_6 * V_7 )
{
return V_7 -> type ;
}
struct V_128 * F_78 ( struct V_6 * V_7 )
{
return V_7 -> V_101 ;
}
struct V_21 * F_79 ( struct V_6 * V_7 )
{
if ( V_7 -> V_28 > 1 ||
! F_63 ( V_7 -> V_26 [ 0 ] . type ) )
return NULL ;
return V_7 -> V_26 ;
}
struct V_21 * F_80 ( struct V_6 * V_7 )
{
struct V_21 * V_72 ( V_49 ) ;
unsigned V_42 = 0 ;
while ( V_42 < F_55 ( V_7 ) ) {
V_49 = F_56 ( V_7 , V_42 ++ ) ;
if ( F_81 ( V_49 -> type ) )
return V_49 ;
}
return NULL ;
}
bool F_82 ( struct V_6 * V_7 )
{
return F_69 ( F_77 ( V_7 ) ) ;
}
bool F_83 ( struct V_6 * V_7 )
{
return F_77 ( V_7 ) == V_120 ;
}
static int F_84 ( struct V_6 * V_7 , struct V_29 * V_30 )
{
unsigned type = F_77 ( V_7 ) ;
unsigned V_129 = 0 ;
struct V_21 * V_43 ;
unsigned V_42 ;
if ( F_45 ( type == V_130 ) ) {
F_19 ( L_33 ) ;
return - V_97 ;
}
if ( type == V_126 )
for ( V_42 = 0 ; V_42 < V_7 -> V_28 ; V_42 ++ ) {
V_43 = V_7 -> V_26 + V_42 ;
V_129 = V_115 ( V_129 , V_43 -> V_129 ) ;
}
V_7 -> V_45 = F_85 ( V_30 , type , V_7 -> V_131 , V_129 ) ;
if ( ! V_7 -> V_45 )
return - V_23 ;
return 0 ;
}
void F_86 ( struct V_6 * V_7 )
{
F_24 ( V_7 -> V_45 ) ;
V_7 -> V_45 = NULL ;
}
struct V_132 * F_87 ( struct V_6 * V_7 )
{
return V_7 -> V_45 ;
}
static int F_88 ( struct V_6 * V_7 )
{
int V_42 ;
unsigned int V_133 = 0 ;
T_1 * V_134 ;
for ( V_42 = V_7 -> V_11 - 2 ; V_42 >= 0 ; V_42 -- ) {
V_7 -> V_12 [ V_42 ] = F_2 ( V_7 -> V_12 [ V_42 + 1 ] , V_5 ) ;
V_133 += V_7 -> V_12 [ V_42 ] ;
}
V_134 = ( T_1 * ) F_7 ( V_133 , ( unsigned long ) V_135 ) ;
if ( ! V_134 )
return - V_23 ;
for ( V_42 = V_7 -> V_11 - 2 ; V_42 >= 0 ; V_42 -- ) {
V_7 -> V_9 [ V_42 ] = V_134 ;
V_134 += ( V_10 * V_7 -> V_12 [ V_42 ] ) ;
F_6 ( V_42 , V_7 ) ;
}
return 0 ;
}
static int F_89 ( struct V_6 * V_7 )
{
int V_68 = 0 ;
unsigned int V_136 ;
V_136 = F_2 ( V_7 -> V_28 , V_10 ) ;
V_7 -> V_11 = 1 + F_1 ( V_136 , V_5 ) ;
V_7 -> V_12 [ V_7 -> V_11 - 1 ] = V_136 ;
V_7 -> V_9 [ V_7 -> V_11 - 1 ] = V_7 -> V_24 ;
if ( V_7 -> V_11 >= 2 )
V_68 = F_88 ( V_7 ) ;
return V_68 ;
}
static bool F_90 ( struct V_137 * V_138 )
{
return ! ! F_91 ( V_138 ) ;
}
static struct V_137 * F_92 ( struct V_6 * V_7 )
{
struct V_34 * V_32 = F_74 ( V_7 ) ;
struct V_37 * V_38 = NULL ;
struct V_137 * V_139 = NULL , * V_140 = NULL ;
F_26 (dd, devices, list) {
V_140 = V_38 -> V_40 -> V_47 -> V_141 ;
if ( ! F_90 ( V_140 ) )
goto V_142;
else if ( V_139 &&
F_93 ( V_139 , V_140 ) < 0 )
goto V_142;
V_139 = V_140 ;
}
return V_140 ;
V_142:
if ( V_139 )
F_19 ( L_34 ,
F_20 ( V_7 -> V_30 ) ,
V_139 -> V_143 ,
V_140 -> V_143 ) ;
return NULL ;
}
static int F_94 ( struct V_6 * V_7 )
{
struct V_29 * V_30 = V_7 -> V_30 ;
struct V_137 * V_140 = NULL ;
V_140 = F_92 ( V_7 ) ;
if ( ! V_140 )
return 0 ;
if ( ! F_90 ( F_95 ( V_30 ) ) ) {
V_7 -> V_131 = 1 ;
F_96 ( F_95 ( V_30 ) ,
F_91 ( V_140 ) ) ;
return 0 ;
}
if ( F_93 ( F_95 ( V_30 ) , V_140 ) < 0 ) {
F_19 ( L_35
L_36 ,
F_20 ( V_7 -> V_30 ) ,
V_140 -> V_143 ) ;
return 1 ;
}
V_7 -> V_131 = 1 ;
return 0 ;
}
int F_97 ( struct V_6 * V_7 )
{
int V_68 ;
V_68 = F_70 ( V_7 ) ;
if ( V_68 ) {
F_59 ( L_37 ) ;
return V_68 ;
}
V_68 = F_89 ( V_7 ) ;
if ( V_68 ) {
F_59 ( L_38 ) ;
return V_68 ;
}
V_68 = F_94 ( V_7 ) ;
if ( V_68 ) {
F_59 ( L_39 ) ;
return V_68 ;
}
V_68 = F_84 ( V_7 , V_7 -> V_30 ) ;
if ( V_68 )
F_59 ( L_40 ) ;
return V_68 ;
}
void F_98 ( struct V_6 * V_7 ,
void (* F_99)( void * ) , void * V_144 )
{
F_100 ( & V_145 ) ;
V_7 -> V_146 = F_99 ;
V_7 -> V_147 = V_144 ;
F_101 ( & V_145 ) ;
}
void F_102 ( struct V_6 * V_7 )
{
F_39 ( F_103 () ) ;
F_100 ( & V_145 ) ;
if ( V_7 -> V_146 )
V_7 -> V_146 ( V_7 -> V_147 ) ;
F_101 ( & V_145 ) ;
}
T_1 F_104 ( struct V_6 * V_7 )
{
return V_7 -> V_28 ? ( V_7 -> V_24 [ V_7 -> V_28 - 1 ] + 1 ) : 0 ;
}
struct V_21 * F_56 ( struct V_6 * V_7 , unsigned int V_9 )
{
if ( V_9 >= V_7 -> V_28 )
return NULL ;
return V_7 -> V_26 + V_9 ;
}
struct V_21 * F_105 ( struct V_6 * V_7 , T_1 V_148 )
{
unsigned int V_8 , V_1 = 0 , V_4 = 0 ;
T_1 * V_13 ;
for ( V_8 = 0 ; V_8 < V_7 -> V_11 ; V_8 ++ ) {
V_1 = F_3 ( V_1 , V_4 ) ;
V_13 = F_4 ( V_7 , V_8 , V_1 ) ;
for ( V_4 = 0 ; V_4 < V_10 ; V_4 ++ )
if ( V_13 [ V_4 ] >= V_148 )
break;
}
return & V_7 -> V_26 [ ( V_10 * V_1 ) + V_4 ] ;
}
static int F_106 ( struct V_21 * V_49 , struct V_40 * V_46 ,
T_1 V_50 , T_1 V_51 , void * V_52 )
{
unsigned * V_149 = V_52 ;
( * V_149 ) ++ ;
return 0 ;
}
bool F_107 ( struct V_6 * V_66 )
{
struct V_21 * V_72 ( V_49 ) ;
unsigned V_42 = 0 , V_149 = 0 ;
while ( V_42 < F_55 ( V_66 ) ) {
V_49 = F_56 ( V_66 , V_42 ++ ) ;
if ( ! V_49 -> type -> V_96 )
return false ;
V_49 -> type -> V_96 ( V_49 , F_106 , & V_149 ) ;
if ( V_149 )
return false ;
}
return true ;
}
int F_108 ( struct V_6 * V_66 ,
struct V_55 * V_56 )
{
struct V_21 * V_72 ( V_49 ) ;
struct V_55 V_95 ;
unsigned V_42 = 0 ;
F_57 ( V_56 ) ;
while ( V_42 < F_55 ( V_66 ) ) {
F_57 ( & V_95 ) ;
V_49 = F_56 ( V_66 , V_42 ++ ) ;
if ( ! V_49 -> type -> V_96 )
goto V_150;
V_49 -> type -> V_96 ( V_49 , F_44 ,
& V_95 ) ;
if ( V_49 -> type -> V_151 )
V_49 -> type -> V_151 ( V_49 , & V_95 ) ;
if ( V_49 -> type -> V_96 ( V_49 , F_27 ,
& V_95 ) )
return - V_97 ;
V_150:
if ( F_109 ( V_56 , & V_95 , 0 ) < 0 )
F_19 ( L_41
L_42
L_43 ,
F_20 ( V_66 -> V_30 ) ,
( unsigned long long ) V_49 -> V_80 ,
( unsigned long long ) V_49 -> V_51 ) ;
}
return F_54 ( V_66 , V_56 ) ;
}
static void F_110 ( struct V_6 * V_7 )
{
struct V_137 * V_140 = NULL ;
if ( V_7 -> V_131 ) {
V_140 = F_92 ( V_7 ) ;
if ( V_140 &&
F_93 ( F_95 ( V_7 -> V_30 ) , V_140 ) >= 0 )
return;
}
if ( F_90 ( F_95 ( V_7 -> V_30 ) ) ) {
F_19 ( L_44 ,
F_20 ( V_7 -> V_30 ) ) ;
F_111 ( F_95 ( V_7 -> V_30 ) ) ;
}
}
static int F_112 ( struct V_21 * V_49 , struct V_40 * V_46 ,
T_1 V_50 , T_1 V_51 , void * V_52 )
{
unsigned V_152 = ( * ( unsigned * ) V_52 ) ;
struct V_53 * V_54 = F_29 ( V_46 -> V_47 ) ;
return V_54 && ( V_54 -> V_153 & V_152 ) ;
}
static bool F_113 ( struct V_6 * V_7 , unsigned V_152 )
{
struct V_21 * V_49 ;
unsigned V_42 = 0 ;
while ( V_42 < F_55 ( V_7 ) ) {
V_49 = F_56 ( V_7 , V_42 ++ ) ;
if ( ! V_49 -> V_154 )
continue;
if ( V_49 -> V_155 )
return true ;
if ( V_49 -> type -> V_96 &&
V_49 -> type -> V_96 ( V_49 , F_112 , & V_152 ) )
return true ;
}
return false ;
}
static bool F_114 ( struct V_6 * V_7 )
{
struct V_21 * V_49 ;
unsigned V_42 = 0 ;
while ( V_42 < F_55 ( V_7 ) ) {
V_49 = F_56 ( V_7 , V_42 ++ ) ;
if ( V_49 -> V_156 )
return false ;
}
return true ;
}
static int F_115 ( struct V_21 * V_49 , struct V_40 * V_46 ,
T_1 V_50 , T_1 V_51 , void * V_52 )
{
struct V_53 * V_54 = F_29 ( V_46 -> V_47 ) ;
return V_54 && F_116 ( V_54 ) ;
}
static int F_117 ( struct V_21 * V_49 , struct V_40 * V_46 ,
T_1 V_50 , T_1 V_51 , void * V_52 )
{
struct V_53 * V_54 = F_29 ( V_46 -> V_47 ) ;
return V_54 && ! F_118 ( V_54 ) ;
}
static int F_119 ( struct V_21 * V_49 , struct V_40 * V_46 ,
T_1 V_50 , T_1 V_51 , void * V_52 )
{
struct V_53 * V_54 = F_29 ( V_46 -> V_47 ) ;
return V_54 && ! F_120 ( V_157 , & V_54 -> V_158 ) ;
}
static bool F_121 ( struct V_6 * V_7 ,
T_5 V_159 )
{
struct V_21 * V_49 ;
unsigned V_42 = 0 ;
while ( V_42 < F_55 ( V_7 ) ) {
V_49 = F_56 ( V_7 , V_42 ++ ) ;
if ( ! V_49 -> type -> V_96 ||
! V_49 -> type -> V_96 ( V_49 , V_159 , NULL ) )
return false ;
}
return true ;
}
static int F_122 ( struct V_21 * V_49 , struct V_40 * V_46 ,
T_1 V_50 , T_1 V_51 , void * V_52 )
{
struct V_53 * V_54 = F_29 ( V_46 -> V_47 ) ;
return V_54 && ! V_54 -> V_56 . V_160 ;
}
static bool F_123 ( struct V_6 * V_7 )
{
struct V_21 * V_49 ;
unsigned V_42 = 0 ;
while ( V_42 < F_55 ( V_7 ) ) {
V_49 = F_56 ( V_7 , V_42 ++ ) ;
if ( ! V_49 -> V_161 )
return false ;
if ( ! V_49 -> type -> V_96 ||
V_49 -> type -> V_96 ( V_49 , F_122 , NULL ) )
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
while ( V_42 < F_55 ( V_7 ) ) {
V_49 = F_56 ( V_7 , V_42 ++ ) ;
if ( ! V_49 -> V_104 )
continue;
if ( V_49 -> V_105 )
return true ;
if ( V_49 -> type -> V_96 &&
V_49 -> type -> V_96 ( V_49 , F_124 , NULL ) )
return true ;
}
return false ;
}
void F_127 ( struct V_6 * V_7 , struct V_53 * V_54 ,
struct V_55 * V_56 )
{
unsigned V_152 = 0 ;
V_54 -> V_56 = * V_56 ;
if ( ! F_126 ( V_7 ) )
F_128 ( V_162 , V_54 ) ;
else
F_129 ( V_162 , V_54 ) ;
if ( F_113 ( V_7 , V_163 ) ) {
V_152 |= V_163 ;
if ( F_113 ( V_7 , V_164 ) )
V_152 |= V_164 ;
}
F_130 ( V_54 , V_152 ) ;
if ( ! F_114 ( V_7 ) )
V_54 -> V_56 . V_165 = 0 ;
if ( F_121 ( V_7 , F_115 ) )
F_129 ( V_166 , V_54 ) ;
else
F_128 ( V_166 , V_54 ) ;
if ( ! F_123 ( V_7 ) )
V_54 -> V_56 . V_160 = 0 ;
if ( F_121 ( V_7 , F_119 ) )
F_128 ( V_157 , V_54 ) ;
else
F_129 ( V_157 , V_54 ) ;
F_110 ( V_7 ) ;
if ( F_118 ( V_54 ) && F_121 ( V_7 , F_117 ) )
F_128 ( V_167 , V_54 ) ;
F_131 () ;
if ( F_82 ( V_7 ) )
F_129 ( V_168 , V_54 ) ;
}
unsigned int F_55 ( struct V_6 * V_7 )
{
return V_7 -> V_28 ;
}
struct V_34 * F_74 ( struct V_6 * V_7 )
{
return & V_7 -> V_32 ;
}
T_2 F_132 ( struct V_6 * V_7 )
{
return V_7 -> V_27 ;
}
static void F_133 ( struct V_6 * V_7 , enum V_169 V_27 )
{
int V_42 = V_7 -> V_28 ;
struct V_21 * V_49 = V_7 -> V_26 ;
while ( V_42 -- ) {
switch ( V_27 ) {
case V_170 :
if ( V_49 -> type -> V_171 )
V_49 -> type -> V_171 ( V_49 ) ;
break;
case V_172 :
if ( V_49 -> type -> V_173 )
V_49 -> type -> V_173 ( V_49 ) ;
break;
case V_174 :
if ( V_49 -> type -> V_175 )
V_49 -> type -> V_175 ( V_49 ) ;
break;
}
V_49 ++ ;
}
}
void F_134 ( struct V_6 * V_7 )
{
if ( ! V_7 )
return;
F_133 ( V_7 , V_170 ) ;
}
void F_135 ( struct V_6 * V_7 )
{
if ( ! V_7 )
return;
F_133 ( V_7 , V_172 ) ;
}
void F_136 ( struct V_6 * V_7 )
{
if ( ! V_7 )
return;
F_133 ( V_7 , V_174 ) ;
}
int F_137 ( struct V_6 * V_7 )
{
int V_42 , V_68 = 0 ;
for ( V_42 = 0 ; V_42 < V_7 -> V_28 ; V_42 ++ ) {
struct V_21 * V_49 = V_7 -> V_26 + V_42 ;
if ( ! V_49 -> type -> V_176 )
continue;
V_68 = V_49 -> type -> V_176 ( V_49 ) ;
if ( V_68 ) {
F_59 ( L_45 ,
F_20 ( V_7 -> V_30 ) , V_49 -> type -> V_41 , V_68 ) ;
return V_68 ;
}
}
for ( V_42 = 0 ; V_42 < V_7 -> V_28 ; V_42 ++ ) {
struct V_21 * V_49 = V_7 -> V_26 + V_42 ;
if ( V_49 -> type -> V_177 )
V_49 -> type -> V_177 ( V_49 ) ;
}
return 0 ;
}
void F_138 ( struct V_6 * V_7 , struct V_178 * V_179 )
{
F_42 ( & V_179 -> V_39 , & V_7 -> V_33 ) ;
}
int F_139 ( struct V_6 * V_7 , int V_180 )
{
struct V_37 * V_38 ;
struct V_34 * V_32 = F_74 ( V_7 ) ;
struct V_178 * V_179 ;
int V_68 = 0 ;
F_26 (dd, devices, list) {
struct V_53 * V_54 = F_29 ( V_38 -> V_40 -> V_47 ) ;
char V_63 [ V_64 ] ;
if ( F_140 ( V_54 ) )
V_68 |= F_141 ( & V_54 -> V_181 , V_180 ) ;
else
F_142 ( L_46 ,
F_20 ( V_7 -> V_30 ) ,
F_30 ( V_38 -> V_40 -> V_47 , V_63 ) ) ;
}
F_26 (cb, &t->target_callbacks, list)
if ( V_179 -> V_182 )
V_68 |= V_179 -> V_182 ( V_179 , V_180 ) ;
return V_68 ;
}
struct V_29 * F_143 ( struct V_6 * V_7 )
{
return V_7 -> V_30 ;
}
void F_144 ( struct V_6 * V_7 )
{
struct V_29 * V_30 ;
struct V_53 * V_183 ;
unsigned long V_184 ;
if ( ! F_82 ( V_7 ) )
return;
V_30 = F_143 ( V_7 ) ;
V_183 = F_145 ( V_30 ) ;
if ( V_183 ) {
if ( V_183 -> V_127 )
F_146 ( V_183 , true ) ;
else {
F_147 ( V_183 -> V_185 , V_184 ) ;
F_148 ( V_183 ) ;
F_149 ( V_183 -> V_185 , V_184 ) ;
}
}
}
