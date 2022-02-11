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
V_27 . V_30 = V_22 ;
V_27 . V_31 = V_23 ;
V_25 = V_19 -> V_3 ;
V_24 = V_32 . V_33 ( ( char * ) & V_27 , sizeof( struct V_26 ) , & V_25 ) ;
if ( V_24 <= 0 ) {
F_9 ( L_1 , V_34 , V_24 ) ;
return V_24 ;
}
V_24 = V_32 . V_33 ( V_20 , V_21 , & V_25 ) ;
if ( V_24 <= 0 ) {
F_9 ( L_1 , V_34 , V_24 ) ;
return V_24 ;
}
return 0 ;
}
int F_10 ( char * V_20 , int V_21 ,
unsigned int V_22 , unsigned int V_23 )
{
int V_24 = F_8 ( & V_35 , V_20 , V_21 ,
V_22 , V_23 ) ;
if ( ! V_24 ) {
V_36 = F_11 () ;
#ifdef F_12
V_37 = F_11 () ;
#endif
}
return V_24 ;
}
int F_13 ( struct V_18 * V_19 , char * V_20 ,
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
F_9 ( L_2 , V_34 ,
V_24 ) ;
return V_24 ;
}
}
V_24 = V_32 . V_39 ( V_20 , V_21 , & V_25 ) ;
if ( V_24 <= 0 ) {
F_9 ( L_2 , V_34 , V_24 ) ;
return V_24 ;
}
if ( V_19 -> V_38 ) {
* V_23 = V_27 . V_31 ;
* V_22 = V_27 . V_30 ;
}
return 0 ;
}
int F_14 ( char * V_20 , int V_21 ,
unsigned int * V_22 , unsigned int * V_23 )
{
return F_13 ( & V_35 , V_20 , V_21 ,
V_22 , V_23 ) ;
}
int F_15 ( void )
{
T_3 V_25 ;
int V_40 = V_41 ;
int V_24 ;
if ( V_35 . V_3 == - 1 )
return - 1 ;
V_25 = V_35 . V_3 ;
V_24 = V_32 . V_33 ( ( char * ) & V_40 , sizeof( int ) , & V_25 ) ;
if ( V_24 <= 0 ) {
F_16 ( V_42 L_3 , V_24 ) ;
return V_24 ;
}
V_36 = 0 ;
return 0 ;
}
static int T_4 F_17 ( struct V_18
* V_19 )
{
T_3 V_8 ;
int V_29 ;
F_18 () ;
V_8 = F_19 ( V_19 -> V_43 , V_44 , & V_29 ) ;
if ( V_8 && V_29 < V_19 -> V_45 ) {
F_20 ( L_4
L_5 , V_19 -> V_43 ) ;
F_21 ( V_19 -> V_43 , V_44 , NULL ) ;
V_8 = 0 ;
}
if ( ! V_8 ) {
V_8 = F_22 ( V_19 -> V_43 , V_44 ,
V_19 -> V_46 , V_19 -> V_45 ) ;
if ( V_8 == - V_47 ) {
F_20 ( L_6
L_7 ,
V_19 -> V_43 ) ;
F_21 ( NULL , V_44 ,
V_48 ) ;
V_8 = F_22 ( V_19 -> V_43 , V_44 ,
V_19 -> V_46 , V_19 -> V_45 ) ;
}
}
if ( V_8 <= 0 ) {
F_9 ( L_8
L_9 , V_19 -> V_43 , ( int ) V_8 ) ;
return - 1 ;
}
V_19 -> V_3 = V_8 ;
V_19 -> V_29 = F_23 ( V_8 ) - sizeof( struct V_26 ) ;
return 0 ;
}
static int F_24 ( void )
{
return ( V_49 . V_3 == V_35 . V_3
&& V_36
&& F_11 () - V_36 <=
V_50 ) ;
}
static int F_25 ( const void * V_51 , void * V_52 , T_2 V_53 ,
T_2 V_54 )
{
int V_55 , V_56 ;
V_56 = - V_16 ;
V_55 = F_26 ( & V_57 , V_58 , V_59 , V_60 ,
V_61 , V_62 ) ;
if ( V_55 != V_63 )
goto error;
V_57 . V_64 = V_51 ;
V_57 . V_65 = V_53 ;
V_57 . V_66 = 0 ;
V_57 . V_67 = V_52 ;
V_57 . V_68 = V_54 ;
V_57 . V_69 = 0 ;
V_55 = F_27 ( & V_57 , V_70 ) ;
if ( V_55 != V_71 )
goto error;
V_55 = F_28 ( & V_57 ) ;
if ( V_55 != V_63 )
goto error;
if ( V_57 . V_69 >= V_57 . V_66 )
goto error;
V_56 = V_57 . V_69 ;
error:
return V_56 ;
}
static int F_29 ( T_2 V_72 )
{
struct V_73 * V_74 = (struct V_73 * ) V_75 ;
int V_76 = F_25 ( V_77 , V_78 , V_72 ,
V_79 ) ;
if ( V_76 < 0 ) {
F_9 ( L_10 , V_76 ) ;
F_9 ( L_11 ) ;
return - 1 ;
}
V_74 -> V_80 = V_81 ;
V_74 -> V_82 = ( V_83 ) V_76 ;
V_74 -> V_84 = F_11 () ;
return 0 ;
}
static int F_30 ( struct V_85 * V_86 )
{
V_87 = - 1 ;
return 0 ;
}
static int F_31 ( enum V_88 type ,
enum V_89 V_90 ,
T_5 * V_91 , unsigned int V_19 , int V_2 ,
bool V_92 , T_2 V_29 ,
struct V_85 * V_86 )
{
int V_24 ;
unsigned int V_22 = V_93 ;
struct V_73 * V_74 = (struct V_73 * ) V_75 ;
if ( V_19 > 1 || type != V_94 ||
F_24 () )
return - 1 ;
V_74 -> V_80 = V_81 ;
V_74 -> V_82 = ( V_83 ) V_29 ;
V_74 -> V_84 = F_11 () ;
if ( V_92 )
V_22 = V_95 ;
V_24 = F_8 ( & V_49 , V_75 ,
( int ) ( sizeof( * V_74 ) + V_29 ) , V_22 , V_2 ) ;
if ( V_24 != 0 )
return V_24 ;
* V_91 = V_19 ;
return 0 ;
}
static T_1 F_32 ( T_5 * V_91 , enum V_88 * type ,
int * V_2 , struct V_96 * time , char * * V_1 ,
bool * V_92 , struct V_85 * V_86 )
{
struct V_73 * V_74 ;
unsigned int V_22 , V_97 , V_29 = 0 ;
struct V_18 * V_19 = NULL ;
char * V_20 = NULL ;
int V_98 = 0 ;
T_3 V_8 ;
V_87 ++ ;
switch ( V_99 [ V_87 ] ) {
case V_94 :
V_19 = & V_49 ;
* type = V_94 ;
break;
case V_100 :
V_19 = & V_35 ;
* type = V_100 ;
time -> V_101 = V_37 ;
time -> V_102 = 0 ;
break;
case V_103 :
V_98 = V_104 ;
V_19 = & V_105 ;
* type = V_103 ;
* V_91 = V_103 ;
time -> V_101 = 0 ;
time -> V_102 = 0 ;
break;
case V_106 :
V_98 = V_107 ;
V_19 = & V_108 ;
* type = V_106 ;
* V_91 = V_106 ;
time -> V_101 = 0 ;
time -> V_102 = 0 ;
break;
default:
return 0 ;
}
if ( ! V_19 -> V_38 ) {
V_8 = F_19 ( V_19 -> V_43 , V_98 , & V_29 ) ;
if ( V_8 <= 0 ) {
F_9 ( L_12
L_13 , V_19 -> V_43 , ( int ) V_8 ) ;
return 0 ;
}
V_19 -> V_3 = V_8 ;
V_19 -> V_29 = V_29 ;
}
V_20 = F_33 ( V_19 -> V_29 , V_109 ) ;
if ( ! V_20 )
return - V_110 ;
if ( F_13 ( V_19 , V_20 , V_19 -> V_29 , & V_22 , & V_97 ) ) {
F_34 ( V_20 ) ;
return 0 ;
}
* V_2 = 0 ;
if ( V_19 -> V_38 )
* V_91 = V_97 ;
if ( V_99 [ V_87 ] == V_94 ) {
T_2 V_21 , V_111 ;
V_74 = (struct V_73 * ) V_20 ;
if ( V_74 -> V_80 < V_81 ) {
V_111 = sizeof( V_83 ) ;
V_21 = V_74 -> V_80 ;
time -> V_101 = 0 ;
time -> V_102 = 0 ;
} else {
V_111 = sizeof( * V_74 ) ;
V_21 = V_74 -> V_82 ;
time -> V_101 = V_74 -> V_84 ;
time -> V_102 = 0 ;
}
* V_1 = F_33 ( V_21 , V_109 ) ;
if ( * V_1 == NULL )
return - V_110 ;
memcpy ( * V_1 , V_20 + V_111 , V_21 ) ;
F_34 ( V_20 ) ;
if ( V_22 == V_95 )
* V_92 = true ;
else
* V_92 = false ;
return V_21 ;
}
* V_1 = V_20 ;
return V_19 -> V_29 ;
}
static int F_35 ( void )
{
int V_24 = 0 ;
V_112 . V_1 = V_78 ;
V_112 . V_113 = V_79 ;
V_24 = F_36 ( & V_112 ) ;
if ( V_24 != 0 )
F_9 ( L_14
L_15 , V_24 ) ;
return V_24 ;
}
static int F_35 ( void )
{
return - 1 ;
}
static void T_4 F_37 ( int V_114 )
{
int V_24 ;
V_24 = F_17 ( & V_49 ) ;
if ( V_24 != 0 ) {
if ( ! V_114 )
return;
F_38 ( L_16
L_17 ,
V_35 . V_43 ) ;
memcpy ( & V_49 , & V_35 ,
sizeof( V_35 ) ) ;
}
V_75 = F_33 ( V_49 . V_29 , V_109 ) ;
if ( ! V_75 ) {
F_9 ( L_18 ,
V_49 . V_43 ) ;
return;
}
V_78 = V_75 + sizeof( struct V_73 ) ;
V_79 = V_49 . V_29 - sizeof( struct V_73 ) ;
V_24 = F_35 () ;
if ( ! V_24 )
return;
V_115 = ( V_79 * 100 ) / 45 ;
V_77 = F_33 ( V_115 , V_109 ) ;
if ( V_77 ) {
V_57 . V_116 = F_33 ( F_39 (
V_60 , V_61 ) , V_109 ) ;
if ( ! V_57 . V_116 ) {
F_9 ( L_19
L_20 ,
V_49 . V_43 ) ;
F_34 ( V_77 ) ;
V_77 = NULL ;
}
} else {
F_9 ( L_21
L_22 , V_49 . V_43 ) ;
V_57 . V_116 = NULL ;
}
V_24 = F_40 ( & V_117 ) ;
if ( V_24 != 0 ) {
F_9 ( L_23 , V_24 ) ;
F_34 ( V_75 ) ;
F_34 ( V_77 ) ;
F_34 ( V_57 . V_116 ) ;
}
}
static int T_4 F_41 ( void )
{
int V_24 ;
V_24 = F_17 ( & V_35 ) ;
F_37 ( V_24 == 0 ) ;
return 0 ;
}
int T_4 F_42 ( void )
{
struct V_118 * V_119 ;
const unsigned int * V_120 ;
unsigned int V_121 ;
V_119 = F_43 ( NULL , L_24 ) ;
if ( V_119 == NULL )
return - V_12 ;
V_120 = F_44 ( V_119 , L_25 , & V_121 ) ;
if ( V_120 == NULL || V_121 != sizeof( unsigned int ) ) {
F_45 ( V_119 ) ;
return - V_16 ;
}
V_9 = * V_120 ;
V_10 = F_46 ( L_26 ) ;
V_17 = F_46 ( L_27 ) ;
F_16 ( V_122 L_28 , V_9 ) ;
F_45 ( V_119 ) ;
V_32 . V_39 = F_1 ;
V_32 . V_33 = F_6 ;
V_32 . V_9 = F_7 ;
return 0 ;
}
static void F_47 ( struct V_123 * V_124 ,
enum V_89 V_90 )
{
struct V_73 * V_74 = (struct V_73 * ) V_75 ;
static unsigned int V_125 = 0 ;
static bool V_126 = false ;
static F_48 ( V_127 ) ;
unsigned long V_7 ;
T_2 V_72 ;
unsigned int V_22 = V_95 ;
int V_24 = - 1 ;
switch ( V_90 ) {
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
F_9 ( L_29 ,
V_34 , ( int ) V_90 ) ;
return;
}
if ( F_24 () )
return;
if ( ! F_49 ( & V_127 , V_7 ) )
return;
if ( V_77 ) {
F_50 ( V_124 , false ,
V_77 , V_115 , & V_72 ) ;
V_24 = F_29 ( V_72 ) ;
}
if ( V_24 != 0 ) {
F_51 ( V_124 ) ;
F_50 ( V_124 , false ,
V_78 , V_79 , & V_72 ) ;
V_22 = V_93 ;
V_74 -> V_80 = V_81 ;
V_74 -> V_82 = ( V_83 ) V_72 ;
V_74 -> V_84 = F_11 () ;
}
( void ) F_8 ( & V_49 , V_75 ,
( int ) ( sizeof( * V_74 ) + V_74 -> V_82 ) , V_22 ,
++ V_125 ) ;
F_5 ( & V_127 , V_7 ) ;
}
