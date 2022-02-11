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
int F_30 ( void * V_51 , void * V_52 , T_2 V_53 , T_2 V_54 )
{
int V_55 , V_56 ;
V_56 = - V_16 ;
V_55 = F_31 ( & V_57 ) ;
if ( V_55 != V_63 )
goto error;
V_57 . V_64 = V_51 ;
V_57 . V_65 = V_53 ;
V_57 . V_66 = 0 ;
V_57 . V_67 = V_52 ;
V_57 . V_68 = V_54 ;
V_57 . V_69 = 0 ;
V_55 = F_32 ( & V_57 , V_70 ) ;
if ( V_55 != V_71 )
goto error;
V_55 = F_33 ( & V_57 ) ;
if ( V_55 != V_63 )
goto error;
V_56 = V_57 . V_69 ;
error:
return V_56 ;
}
static int F_34 ( struct V_85 * V_86 )
{
V_87 = - 1 ;
return 0 ;
}
static int F_35 ( enum V_88 type ,
enum V_89 V_90 ,
T_5 * V_91 , unsigned int V_19 , int V_2 ,
T_2 V_92 , T_2 V_29 ,
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
if ( V_77 ) {
V_24 = F_29 ( V_29 ) ;
if ( V_24 != 0 ) {
T_2 V_95 = V_29 - V_79 + V_92 ;
if ( V_29 > V_79 ) {
memcpy ( V_78 , V_77 , V_92 ) ;
memcpy ( V_78 + V_92 , V_77 + V_95 ,
V_79 - V_92 ) ;
V_74 -> V_82 = ( V_83 ) V_79 ;
} else
memcpy ( V_78 , V_77 , V_29 ) ;
} else
V_22 = V_96 ;
}
V_24 = F_8 ( & V_49 , V_75 ,
( int ) ( sizeof( * V_74 ) + V_74 -> V_82 ) , V_22 ,
V_2 ) ;
if ( V_24 != 0 )
return V_24 ;
* V_91 = V_19 ;
return 0 ;
}
static T_1 F_36 ( T_5 * V_91 , enum V_88 * type ,
int * V_2 , struct V_97 * time , char * * V_1 ,
struct V_85 * V_86 )
{
struct V_73 * V_74 ;
unsigned int V_22 , V_98 , V_29 = 0 ;
struct V_18 * V_19 = NULL ;
char * V_20 = NULL , * V_99 = NULL ;
int V_100 = 0 ;
T_3 V_8 ;
V_87 ++ ;
switch ( V_101 [ V_87 ] ) {
case V_94 :
V_19 = & V_49 ;
* type = V_94 ;
break;
case V_102 :
V_19 = & V_35 ;
* type = V_102 ;
time -> V_103 = V_37 ;
time -> V_104 = 0 ;
break;
case V_105 :
V_100 = V_106 ;
V_19 = & V_107 ;
* type = V_105 ;
* V_91 = V_105 ;
time -> V_103 = 0 ;
time -> V_104 = 0 ;
break;
case V_108 :
V_100 = V_109 ;
V_19 = & V_110 ;
* type = V_108 ;
* V_91 = V_108 ;
time -> V_103 = 0 ;
time -> V_104 = 0 ;
break;
default:
return 0 ;
}
if ( ! V_19 -> V_38 ) {
V_8 = F_19 ( V_19 -> V_43 , V_100 , & V_29 ) ;
if ( V_8 <= 0 ) {
F_9 ( L_12
L_13 , V_19 -> V_43 , ( int ) V_8 ) ;
return 0 ;
}
V_19 -> V_3 = V_8 ;
V_19 -> V_29 = V_29 ;
}
V_20 = F_37 ( V_19 -> V_29 , V_111 ) ;
if ( ! V_20 )
return - V_112 ;
if ( F_13 ( V_19 , V_20 , V_19 -> V_29 , & V_22 , & V_98 ) ) {
F_38 ( V_20 ) ;
return 0 ;
}
* V_2 = 0 ;
if ( V_19 -> V_38 )
* V_91 = V_98 ;
if ( V_101 [ V_87 ] == V_94 ) {
int V_21 , V_113 ;
T_2 V_114 ;
V_74 = (struct V_73 * ) V_20 ;
if ( V_74 -> V_80 < V_81 ) {
V_114 = sizeof( V_83 ) ;
V_21 = V_74 -> V_80 ;
time -> V_103 = 0 ;
time -> V_104 = 0 ;
} else {
V_114 = sizeof( * V_74 ) ;
V_21 = V_74 -> V_82 ;
time -> V_103 = V_74 -> V_84 ;
time -> V_104 = 0 ;
}
* V_1 = F_37 ( V_21 , V_111 ) ;
if ( * V_1 == NULL )
return - V_112 ;
memcpy ( * V_1 , V_20 + V_114 , V_21 ) ;
F_38 ( V_20 ) ;
if ( V_22 == V_96 ) {
V_99 = F_37 ( V_115 , V_111 ) ;
if ( ! V_99 )
return - V_112 ;
V_113 = F_30 ( * V_1 , V_99 ,
V_21 , V_115 ) ;
if ( V_113 < 0 ) {
F_9 ( L_14
L_15 , V_113 ) ;
F_38 ( V_99 ) ;
} else {
* V_1 = V_99 ;
V_21 = V_113 ;
}
}
return V_21 ;
}
* V_1 = V_20 ;
return V_19 -> V_29 ;
}
static int F_39 ( void )
{
int V_24 = 0 ;
if ( V_77 ) {
V_116 . V_1 = V_77 ;
V_116 . V_117 = V_115 ;
} else {
V_116 . V_1 = V_78 ;
V_116 . V_117 = V_79 ;
}
V_24 = F_40 ( & V_116 ) ;
if ( V_24 != 0 )
F_9 ( L_16
L_17 , V_24 ) ;
return V_24 ;
}
static int F_39 ( void )
{
return - 1 ;
}
static void T_4 F_41 ( int V_118 )
{
int V_24 ;
T_2 V_29 ;
V_24 = F_17 ( & V_49 ) ;
if ( V_24 != 0 ) {
if ( ! V_118 )
return;
F_42 ( L_18
L_19 ,
V_35 . V_43 ) ;
memcpy ( & V_49 , & V_35 ,
sizeof( V_35 ) ) ;
}
V_75 = F_37 ( V_49 . V_29 , V_111 ) ;
if ( ! V_75 ) {
F_9 ( L_20 ,
V_49 . V_43 ) ;
return;
}
V_78 = V_75 + sizeof( struct V_73 ) ;
V_79 = V_49 . V_29 - sizeof( struct V_73 ) ;
V_115 = ( V_79 * 100 ) / 45 ;
V_77 = F_37 ( V_115 , V_111 ) ;
if ( V_77 ) {
V_29 = F_43 ( F_44 ( V_60 , V_61 ) ,
F_45 () ) ;
V_57 . V_119 = F_37 ( V_29 , V_111 ) ;
if ( ! V_57 . V_119 ) {
F_9 ( L_21
L_22 ,
V_49 . V_43 ) ;
F_38 ( V_77 ) ;
V_77 = NULL ;
}
} else {
F_9 ( L_23
L_24 , V_49 . V_43 ) ;
V_57 . V_119 = NULL ;
}
V_24 = F_39 () ;
if ( ! V_24 )
return;
V_24 = F_46 ( & V_120 ) ;
if ( V_24 != 0 ) {
F_9 ( L_25 , V_24 ) ;
F_38 ( V_75 ) ;
F_38 ( V_77 ) ;
F_38 ( V_57 . V_119 ) ;
}
}
static int T_4 F_47 ( void )
{
int V_24 ;
V_24 = F_17 ( & V_35 ) ;
F_41 ( V_24 == 0 ) ;
return 0 ;
}
int T_4 F_48 ( void )
{
struct V_121 * V_122 ;
const unsigned int * V_123 ;
unsigned int V_124 ;
V_122 = F_49 ( NULL , L_26 ) ;
if ( V_122 == NULL )
return - V_12 ;
V_123 = F_50 ( V_122 , L_27 , & V_124 ) ;
if ( V_123 == NULL || V_124 != sizeof( unsigned int ) ) {
F_51 ( V_122 ) ;
return - V_16 ;
}
V_9 = * V_123 ;
V_10 = F_52 ( L_28 ) ;
V_17 = F_52 ( L_29 ) ;
F_16 ( V_125 L_30 , V_9 ) ;
F_51 ( V_122 ) ;
V_32 . V_39 = F_1 ;
V_32 . V_33 = F_6 ;
V_32 . V_9 = F_7 ;
return 0 ;
}
static void F_53 ( struct V_126 * V_127 ,
enum V_89 V_90 )
{
struct V_73 * V_74 = (struct V_73 * ) V_75 ;
static unsigned int V_128 = 0 ;
static bool V_129 = false ;
static F_54 ( V_130 ) ;
unsigned long V_7 ;
T_2 V_72 ;
unsigned int V_22 = V_96 ;
int V_24 = - 1 ;
switch ( V_90 ) {
case V_131 :
case V_132 :
case V_133 :
return;
case V_134 :
break;
case V_135 :
V_129 = true ;
break;
case V_136 :
if ( V_129 )
return;
break;
default:
F_9 ( L_31 ,
V_34 , ( int ) V_90 ) ;
return;
}
if ( F_24 () )
return;
if ( ! F_55 ( & V_130 , V_7 ) )
return;
if ( V_77 ) {
F_56 ( V_127 , false ,
V_77 , V_115 , & V_72 ) ;
V_24 = F_29 ( V_72 ) ;
}
if ( V_24 != 0 ) {
F_57 ( V_127 ) ;
F_56 ( V_127 , false ,
V_78 , V_79 , & V_72 ) ;
V_22 = V_93 ;
V_74 -> V_80 = V_81 ;
V_74 -> V_82 = ( V_83 ) V_72 ;
V_74 -> V_84 = F_11 () ;
}
( void ) F_8 ( & V_49 , V_75 ,
( int ) ( sizeof( * V_74 ) + V_74 -> V_82 ) , V_22 ,
++ V_128 ) ;
F_5 ( & V_130 , V_7 ) ;
}
