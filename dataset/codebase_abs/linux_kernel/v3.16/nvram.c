static T_1 F_1 ( char * V_1 , T_2 V_2 , T_3 * V_3 )
{
unsigned int V_4 ;
unsigned long V_5 ;
int V_6 ;
unsigned long V_7 ;
char * V_8 = V_1 ;
if ( V_9 == 0 || V_10 == V_11 )
return - V_12 ;
if ( * V_3 >= V_9 )
return 0 ;
V_4 = * V_3 ;
if ( V_4 + V_2 > V_9 )
V_2 = V_9 - V_4 ;
F_2 ( & V_13 , V_7 ) ;
for (; V_2 != 0 ; V_2 -= V_5 ) {
V_5 = V_2 ;
if ( V_5 > V_14 )
V_5 = V_14 ;
if ( ( F_3 ( V_10 , 3 , 2 , & V_6 , V_4 , F_4 ( V_15 ) ,
V_5 ) != 0 ) || V_5 != V_6 ) {
F_5 ( & V_13 , V_7 ) ;
return - V_16 ;
}
memcpy ( V_8 , V_15 , V_5 ) ;
V_8 += V_5 ;
V_4 += V_5 ;
}
F_5 ( & V_13 , V_7 ) ;
* V_3 = V_4 ;
return V_8 - V_1 ;
}
static T_1 F_6 ( char * V_1 , T_2 V_2 , T_3 * V_3 )
{
unsigned int V_4 ;
unsigned long V_5 ;
int V_6 ;
unsigned long V_7 ;
const char * V_8 = V_1 ;
if ( V_9 == 0 || V_17 == V_11 )
return - V_12 ;
if ( * V_3 >= V_9 )
return 0 ;
V_4 = * V_3 ;
if ( V_4 + V_2 > V_9 )
V_2 = V_9 - V_4 ;
F_2 ( & V_13 , V_7 ) ;
for (; V_2 != 0 ; V_2 -= V_5 ) {
V_5 = V_2 ;
if ( V_5 > V_14 )
V_5 = V_14 ;
memcpy ( V_15 , V_8 , V_5 ) ;
if ( ( F_3 ( V_17 , 3 , 2 , & V_6 , V_4 , F_4 ( V_15 ) ,
V_5 ) != 0 ) || V_5 != V_6 ) {
F_5 ( & V_13 , V_7 ) ;
return - V_16 ;
}
V_8 += V_5 ;
V_4 += V_5 ;
}
F_5 ( & V_13 , V_7 ) ;
* V_3 = V_4 ;
return V_8 - V_1 ;
}
static T_1 F_7 ( void )
{
return V_9 ? V_9 : - V_12 ;
}
int F_8 ( struct V_18 * V_19 , char * V_20 ,
int V_21 , unsigned int V_22 , unsigned int V_23 )
{
int V_24 ;
T_3 V_25 ;
struct V_26 V_27 ;
if ( V_19 -> V_3 == - 1 ) {
return - V_28 ;
}
if ( V_21 > V_19 -> V_29 ) {
V_21 = V_19 -> V_29 ;
}
V_27 . V_30 = F_9 ( V_22 ) ;
V_27 . V_31 = F_9 ( V_23 ) ;
V_25 = V_19 -> V_3 ;
V_24 = V_32 . V_33 ( ( char * ) & V_27 , sizeof( struct V_26 ) , & V_25 ) ;
if ( V_24 <= 0 ) {
F_10 ( L_1 , V_34 , V_24 ) ;
return V_24 ;
}
V_24 = V_32 . V_33 ( V_20 , V_21 , & V_25 ) ;
if ( V_24 <= 0 ) {
F_10 ( L_1 , V_34 , V_24 ) ;
return V_24 ;
}
return 0 ;
}
int F_11 ( char * V_20 , int V_21 ,
unsigned int V_22 , unsigned int V_23 )
{
int V_24 = F_8 ( & V_35 , V_20 , V_21 ,
V_22 , V_23 ) ;
if ( ! V_24 ) {
V_36 = F_12 () ;
#ifdef F_13
V_37 = F_12 () ;
#endif
}
return V_24 ;
}
int F_14 ( struct V_18 * V_19 , char * V_20 ,
int V_21 , unsigned int * V_22 ,
unsigned int * V_23 )
{
int V_24 ;
T_3 V_25 ;
struct V_26 V_27 ;
if ( V_19 -> V_3 == - 1 )
return - 1 ;
if ( V_21 > V_19 -> V_29 )
V_21 = V_19 -> V_29 ;
V_25 = V_19 -> V_3 ;
if ( V_19 -> V_38 ) {
V_24 = V_32 . V_39 ( ( char * ) & V_27 ,
sizeof( struct V_26 ) ,
& V_25 ) ;
if ( V_24 <= 0 ) {
F_10 ( L_2 , V_34 , V_24 ) ;
return V_24 ;
}
}
V_24 = V_32 . V_39 ( V_20 , V_21 , & V_25 ) ;
if ( V_24 <= 0 ) {
F_10 ( L_2 , V_34 , V_24 ) ;
return V_24 ;
}
if ( V_19 -> V_38 ) {
* V_23 = F_15 ( V_27 . V_31 ) ;
* V_22 = F_15 ( V_27 . V_30 ) ;
}
return 0 ;
}
int F_16 ( char * V_20 , int V_21 ,
unsigned int * V_22 , unsigned int * V_23 )
{
return F_14 ( & V_35 , V_20 , V_21 ,
V_22 , V_23 ) ;
}
int F_17 ( void )
{
T_3 V_25 ;
int V_40 = V_41 ;
int V_24 ;
if ( V_35 . V_3 == - 1 )
return - 1 ;
V_25 = V_35 . V_3 ;
V_24 = V_32 . V_33 ( ( char * ) & V_40 , sizeof( int ) , & V_25 ) ;
if ( V_24 <= 0 ) {
F_18 ( V_42 L_3 , V_24 ) ;
return V_24 ;
}
V_36 = 0 ;
return 0 ;
}
static int T_4 F_19 ( struct V_18
* V_19 )
{
T_3 V_8 ;
int V_29 ;
V_8 = F_20 ( V_19 -> V_43 , V_44 , & V_29 ) ;
if ( V_8 && V_29 < V_19 -> V_45 ) {
F_21 ( L_4
L_5 , V_19 -> V_43 ) ;
F_22 ( V_19 -> V_43 , V_44 , NULL ) ;
V_8 = 0 ;
}
if ( ! V_8 ) {
V_8 = F_23 ( V_19 -> V_43 , V_44 ,
V_19 -> V_46 , V_19 -> V_45 ) ;
if ( V_8 == - V_47 ) {
F_21 ( L_6
L_7 ,
V_19 -> V_43 ) ;
F_22 ( NULL , V_44 ,
V_48 ) ;
V_8 = F_23 ( V_19 -> V_43 , V_44 ,
V_19 -> V_46 , V_19 -> V_45 ) ;
}
}
if ( V_8 <= 0 ) {
F_10 ( L_8
L_9 , V_19 -> V_43 , ( int ) V_8 ) ;
return - 1 ;
}
V_19 -> V_3 = V_8 ;
V_19 -> V_29 = F_24 ( V_8 ) - sizeof( struct V_26 ) ;
return 0 ;
}
static int F_25 ( void )
{
return ( V_49 . V_3 == V_35 . V_3
&& V_36
&& F_12 () - V_36 <=
V_50 ) ;
}
static int F_26 ( const void * V_51 , void * V_52 , T_2 V_53 ,
T_2 V_54 )
{
int V_55 , V_56 ;
V_56 = - V_16 ;
V_55 = F_27 ( & V_57 , V_58 , V_59 , V_60 ,
V_61 , V_62 ) ;
if ( V_55 != V_63 )
goto error;
V_57 . V_64 = V_51 ;
V_57 . V_65 = V_53 ;
V_57 . V_66 = 0 ;
V_57 . V_67 = V_52 ;
V_57 . V_68 = V_54 ;
V_57 . V_69 = 0 ;
V_55 = F_28 ( & V_57 , V_70 ) ;
if ( V_55 != V_71 )
goto error;
V_55 = F_29 ( & V_57 ) ;
if ( V_55 != V_63 )
goto error;
if ( V_57 . V_69 >= V_57 . V_66 )
goto error;
V_56 = V_57 . V_69 ;
error:
return V_56 ;
}
static int F_30 ( T_2 V_72 )
{
struct V_73 * V_74 = (struct V_73 * ) V_75 ;
int V_76 = F_26 ( V_77 , V_78 , V_72 ,
V_79 ) ;
if ( V_76 < 0 ) {
F_10 ( L_10 , V_76 ) ;
F_10 ( L_11 ) ;
return - 1 ;
}
V_74 -> V_80 = F_31 ( V_81 ) ;
V_74 -> V_82 = F_31 ( V_76 ) ;
V_74 -> V_83 = F_32 ( F_12 () ) ;
return 0 ;
}
static int F_33 ( struct V_84 * V_85 )
{
V_86 = - 1 ;
return 0 ;
}
static int F_34 ( enum V_87 type ,
enum V_88 V_89 ,
T_5 * V_90 , unsigned int V_19 , int V_2 ,
bool V_91 , T_2 V_29 ,
struct V_84 * V_85 )
{
int V_24 ;
unsigned int V_22 = V_92 ;
struct V_73 * V_74 = (struct V_73 * ) V_75 ;
if ( V_19 > 1 || type != V_93 ||
F_25 () )
return - 1 ;
V_74 -> V_80 = F_31 ( V_81 ) ;
V_74 -> V_82 = F_31 ( V_29 ) ;
V_74 -> V_83 = F_32 ( F_12 () ) ;
if ( V_91 )
V_22 = V_94 ;
V_24 = F_8 ( & V_49 , V_75 ,
( int ) ( sizeof( * V_74 ) + V_29 ) , V_22 , V_2 ) ;
if ( V_24 != 0 )
return V_24 ;
* V_90 = V_19 ;
return 0 ;
}
static T_1 F_35 ( T_5 * V_90 , enum V_87 * type ,
int * V_2 , struct V_95 * time , char * * V_1 ,
bool * V_91 , struct V_84 * V_85 )
{
struct V_73 * V_74 ;
unsigned int V_22 , V_96 , V_29 = 0 ;
struct V_18 * V_19 = NULL ;
char * V_20 = NULL ;
int V_97 = 0 ;
T_3 V_8 ;
V_86 ++ ;
switch ( V_98 [ V_86 ] ) {
case V_93 :
V_19 = & V_49 ;
* type = V_93 ;
break;
case V_99 :
V_19 = & V_35 ;
* type = V_99 ;
time -> V_100 = V_37 ;
time -> V_101 = 0 ;
break;
case V_102 :
V_97 = V_103 ;
V_19 = & V_104 ;
* type = V_102 ;
* V_90 = V_102 ;
time -> V_100 = 0 ;
time -> V_101 = 0 ;
break;
case V_105 :
V_97 = V_106 ;
V_19 = & V_107 ;
* type = V_105 ;
* V_90 = V_105 ;
time -> V_100 = 0 ;
time -> V_101 = 0 ;
break;
default:
return 0 ;
}
if ( ! V_19 -> V_38 ) {
V_8 = F_20 ( V_19 -> V_43 , V_97 , & V_29 ) ;
if ( V_8 <= 0 ) {
F_10 ( L_12
L_13 , V_19 -> V_43 , ( int ) V_8 ) ;
return 0 ;
}
V_19 -> V_3 = V_8 ;
V_19 -> V_29 = V_29 ;
}
V_20 = F_36 ( V_19 -> V_29 , V_108 ) ;
if ( ! V_20 )
return - V_109 ;
if ( F_14 ( V_19 , V_20 , V_19 -> V_29 , & V_22 , & V_96 ) ) {
F_37 ( V_20 ) ;
return 0 ;
}
* V_2 = 0 ;
if ( V_19 -> V_38 )
* V_90 = V_96 ;
if ( V_98 [ V_86 ] == V_93 ) {
T_2 V_21 , V_110 ;
V_74 = (struct V_73 * ) V_20 ;
if ( F_38 ( V_74 -> V_80 ) < V_81 ) {
V_110 = sizeof( V_111 ) ;
V_21 = F_38 ( V_74 -> V_80 ) ;
time -> V_100 = 0 ;
time -> V_101 = 0 ;
} else {
V_110 = sizeof( * V_74 ) ;
V_21 = F_38 ( V_74 -> V_82 ) ;
time -> V_100 = F_39 ( V_74 -> V_83 ) ;
time -> V_101 = 0 ;
}
* V_1 = F_36 ( V_21 , V_108 ) ;
if ( * V_1 == NULL )
return - V_109 ;
memcpy ( * V_1 , V_20 + V_110 , V_21 ) ;
F_37 ( V_20 ) ;
if ( V_22 == V_94 )
* V_91 = true ;
else
* V_91 = false ;
return V_21 ;
}
* V_1 = V_20 ;
return V_19 -> V_29 ;
}
static int F_40 ( void )
{
int V_24 = 0 ;
V_112 . V_1 = V_78 ;
V_112 . V_113 = V_79 ;
V_24 = F_41 ( & V_112 ) ;
if ( V_24 != 0 )
F_10 ( L_14
L_15 , V_24 ) ;
return V_24 ;
}
static int F_40 ( void )
{
return - 1 ;
}
static void T_4 F_42 ( int V_114 )
{
int V_24 ;
V_24 = F_19 ( & V_49 ) ;
if ( V_24 != 0 ) {
if ( ! V_114 )
return;
F_43 ( L_16
L_17 ,
V_35 . V_43 ) ;
memcpy ( & V_49 , & V_35 ,
sizeof( V_35 ) ) ;
}
V_75 = F_36 ( V_49 . V_29 , V_108 ) ;
if ( ! V_75 ) {
F_10 ( L_18 ,
V_49 . V_43 ) ;
return;
}
V_78 = V_75 + sizeof( struct V_73 ) ;
V_79 = V_49 . V_29 - sizeof( struct V_73 ) ;
V_24 = F_40 () ;
if ( ! V_24 )
return;
V_115 = ( V_79 * 100 ) / 45 ;
V_77 = F_36 ( V_115 , V_108 ) ;
if ( V_77 ) {
V_57 . V_116 = F_36 ( F_44 (
V_60 , V_61 ) , V_108 ) ;
if ( ! V_57 . V_116 ) {
F_10 ( L_19
L_20 ,
V_49 . V_43 ) ;
F_37 ( V_77 ) ;
V_77 = NULL ;
}
} else {
F_10 ( L_21
L_22 , V_49 . V_43 ) ;
V_57 . V_116 = NULL ;
}
V_24 = F_45 ( & V_117 ) ;
if ( V_24 != 0 ) {
F_10 ( L_23 , V_24 ) ;
F_37 ( V_75 ) ;
F_37 ( V_77 ) ;
F_37 ( V_57 . V_116 ) ;
}
}
static int T_4 F_46 ( void )
{
int V_24 ;
F_47 () ;
V_24 = F_19 ( & V_35 ) ;
F_42 ( V_24 == 0 ) ;
return 0 ;
}
int T_4 F_48 ( void )
{
struct V_118 * V_119 ;
const T_6 * V_120 ;
unsigned int V_121 ;
V_119 = F_49 ( NULL , L_24 ) ;
if ( V_119 == NULL )
return - V_12 ;
V_120 = F_50 ( V_119 , L_25 , & V_121 ) ;
if ( V_120 == NULL || V_121 != sizeof( unsigned int ) ) {
F_51 ( V_119 ) ;
return - V_16 ;
}
V_9 = F_52 ( V_120 ) ;
V_10 = F_53 ( L_26 ) ;
V_17 = F_53 ( L_27 ) ;
F_18 ( V_122 L_28 , V_9 ) ;
F_51 ( V_119 ) ;
V_32 . V_39 = F_1 ;
V_32 . V_33 = F_6 ;
V_32 . V_9 = F_7 ;
return 0 ;
}
static void F_54 ( struct V_123 * V_124 ,
enum V_88 V_89 )
{
struct V_73 * V_74 = (struct V_73 * ) V_75 ;
static unsigned int V_125 = 0 ;
static bool V_126 = false ;
static F_55 ( V_127 ) ;
unsigned long V_7 ;
T_2 V_72 ;
unsigned int V_22 = V_94 ;
int V_24 = - 1 ;
switch ( V_89 ) {
case V_128 :
case V_129 :
case V_130 :
return;
case V_131 :
break;
case V_132 :
V_126 = true ;
break;
case V_133 :
if ( V_126 )
return;
break;
default:
F_10 ( L_29 ,
V_34 , ( int ) V_89 ) ;
return;
}
if ( F_25 () )
return;
if ( ! F_56 ( & V_127 , V_7 ) )
return;
if ( V_77 ) {
F_57 ( V_124 , false ,
V_77 , V_115 , & V_72 ) ;
V_24 = F_30 ( V_72 ) ;
}
if ( V_24 != 0 ) {
F_58 ( V_124 ) ;
F_57 ( V_124 , false ,
V_78 , V_79 , & V_72 ) ;
V_22 = V_92 ;
V_74 -> V_80 = F_31 ( V_81 ) ;
V_74 -> V_82 = F_31 ( V_72 ) ;
V_74 -> V_83 = F_32 ( F_12 () ) ;
}
( void ) F_8 ( & V_49 , V_75 ,
( int ) ( sizeof( * V_74 ) + V_72 ) , V_22 ,
++ V_125 ) ;
F_5 ( & V_127 , V_7 ) ;
}
