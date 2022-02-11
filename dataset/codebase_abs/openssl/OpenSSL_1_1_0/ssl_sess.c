T_1 * F_1 ( const T_2 * V_1 )
{
return ( V_1 -> V_2 ) ;
}
T_1 * F_2 ( T_2 * V_1 )
{
T_1 * V_3 ;
F_3 ( V_1 -> V_4 ) ;
V_3 = V_1 -> V_2 ;
if ( V_3 )
F_4 ( V_3 ) ;
F_5 ( V_1 -> V_4 ) ;
return V_3 ;
}
int F_6 ( T_1 * V_5 , int V_6 , void * V_7 )
{
return ( F_7 ( & V_5 -> V_8 , V_6 , V_7 ) ) ;
}
void * F_8 ( const T_1 * V_5 , int V_6 )
{
return ( F_9 ( & V_5 -> V_8 , V_6 ) ) ;
}
T_1 * F_10 ( void )
{
T_1 * V_9 ;
V_9 = F_11 ( sizeof( * V_9 ) ) ;
if ( V_9 == NULL ) {
F_12 ( V_10 , V_11 ) ;
return NULL ;
}
V_9 -> V_12 = 1 ;
V_9 -> V_13 = 1 ;
V_9 -> V_14 = 60 * 5 + 4 ;
V_9 -> time = ( unsigned long ) time ( NULL ) ;
V_9 -> V_4 = F_13 () ;
if ( V_9 -> V_4 == NULL ) {
F_12 ( V_10 , V_11 ) ;
F_14 ( V_9 ) ;
return NULL ;
}
if ( ! F_15 ( V_15 , V_9 , & V_9 -> V_8 ) ) {
F_16 ( V_9 -> V_4 ) ;
F_14 ( V_9 ) ;
return NULL ;
}
return V_9 ;
}
T_1 * F_17 ( T_1 * V_16 , int V_17 )
{
T_1 * V_18 ;
V_18 = F_18 ( sizeof( * V_16 ) ) ;
if ( V_18 == NULL ) {
goto V_19;
}
memcpy ( V_18 , V_16 , sizeof( * V_18 ) ) ;
#ifndef F_19
V_18 -> V_20 = NULL ;
V_18 -> V_21 = NULL ;
#endif
V_18 -> V_22 = NULL ;
V_18 -> V_23 = NULL ;
#ifndef F_20
V_18 -> V_24 = NULL ;
V_18 -> V_25 = NULL ;
#endif
V_18 -> V_26 = NULL ;
#ifndef F_21
V_18 -> V_27 = NULL ;
#endif
memset ( & V_18 -> V_8 , 0 , sizeof( V_18 -> V_8 ) ) ;
V_18 -> V_28 = NULL ;
V_18 -> V_29 = NULL ;
V_18 -> V_13 = 1 ;
V_18 -> V_4 = F_13 () ;
if ( V_18 -> V_4 == NULL )
goto V_19;
if ( V_16 -> V_30 != NULL )
F_22 ( V_16 -> V_30 ) ;
if ( V_16 -> V_31 != NULL ) {
V_18 -> V_31 = F_23 ( V_16 -> V_31 ) ;
if ( V_18 -> V_31 == NULL )
goto V_19;
}
#ifndef F_19
if ( V_16 -> V_20 ) {
V_18 -> V_20 = F_24 ( V_16 -> V_20 ) ;
if ( V_18 -> V_20 == NULL ) {
goto V_19;
}
}
if ( V_16 -> V_21 ) {
V_18 -> V_21 = F_24 ( V_16 -> V_21 ) ;
if ( V_18 -> V_21 == NULL ) {
goto V_19;
}
}
#endif
if ( V_16 -> V_22 != NULL ) {
V_18 -> V_22 = F_25 ( V_16 -> V_22 ) ;
if ( V_18 -> V_22 == NULL )
goto V_19;
}
if ( ! F_26 ( V_15 ,
& V_18 -> V_8 , & V_16 -> V_8 ) ) {
goto V_19;
}
if ( V_16 -> V_23 ) {
V_18 -> V_23 = F_24 ( V_16 -> V_23 ) ;
if ( V_18 -> V_23 == NULL ) {
goto V_19;
}
}
#ifndef F_20
if ( V_16 -> V_24 ) {
V_18 -> V_24 =
F_27 ( V_16 -> V_24 ,
V_16 -> V_32 ) ;
if ( V_18 -> V_24 == NULL )
goto V_19;
}
if ( V_16 -> V_25 ) {
V_18 -> V_25 =
F_27 ( V_16 -> V_25 ,
V_16 -> V_33 ) ;
if ( V_18 -> V_25 == NULL )
goto V_19;
}
#endif
if ( V_17 != 0 ) {
V_18 -> V_26 =
F_27 ( V_16 -> V_26 , V_16 -> V_34 ) ;
if ( V_18 -> V_26 == NULL )
goto V_19;
} else {
V_18 -> V_35 = 0 ;
V_18 -> V_34 = 0 ;
}
#ifndef F_21
if ( V_16 -> V_27 ) {
V_18 -> V_27 = F_24 ( V_16 -> V_27 ) ;
if ( V_18 -> V_27 == NULL ) {
goto V_19;
}
}
#endif
return V_18 ;
V_19:
F_12 ( V_36 , V_11 ) ;
F_28 ( V_18 ) ;
return NULL ;
}
const unsigned char * F_29 ( const T_1 * V_5 , unsigned int * V_37 )
{
if ( V_37 )
* V_37 = V_5 -> V_38 ;
return V_5 -> V_39 ;
}
const unsigned char * F_30 ( const T_1 * V_5 ,
unsigned int * V_37 )
{
if ( V_37 != NULL )
* V_37 = V_5 -> V_40 ;
return V_5 -> V_41 ;
}
unsigned int F_31 ( const T_1 * V_5 )
{
return V_5 -> V_42 ;
}
static int F_32 ( const T_2 * V_1 , unsigned char * V_43 ,
unsigned int * V_44 )
{
unsigned int V_45 = 0 ;
do
if ( F_33 ( V_43 , * V_44 ) <= 0 )
return 0 ;
while ( F_34 ( V_1 , V_43 , * V_44 ) &&
( ++ V_45 < V_46 ) ) ;
if ( V_45 < V_46 )
return 1 ;
return 0 ;
}
int F_35 ( T_2 * V_5 , int V_2 )
{
unsigned int V_47 ;
T_1 * V_9 = NULL ;
T_3 V_48 = F_32 ;
if ( ( V_9 = F_10 () ) == NULL )
return ( 0 ) ;
if ( V_5 -> V_49 -> V_50 == 0 )
V_9 -> V_14 = F_36 ( V_5 ) ;
else
V_9 -> V_14 = V_5 -> V_49 -> V_50 ;
F_28 ( V_5 -> V_2 ) ;
V_5 -> V_2 = NULL ;
if ( V_2 ) {
if ( V_5 -> V_51 == V_52 ) {
V_9 -> V_53 = V_52 ;
V_9 -> V_38 = V_54 ;
} else if ( V_5 -> V_51 == V_55 ) {
V_9 -> V_53 = V_55 ;
V_9 -> V_38 = V_54 ;
} else if ( V_5 -> V_51 == V_56 ) {
V_9 -> V_53 = V_56 ;
V_9 -> V_38 = V_54 ;
} else if ( V_5 -> V_51 == V_57 ) {
V_9 -> V_53 = V_57 ;
V_9 -> V_38 = V_54 ;
} else if ( V_5 -> V_51 == V_58 ) {
V_9 -> V_53 = V_58 ;
V_9 -> V_38 = V_54 ;
} else if ( V_5 -> V_51 == V_59 ) {
V_9 -> V_53 = V_59 ;
V_9 -> V_38 = V_54 ;
} else if ( V_5 -> V_51 == V_60 ) {
V_9 -> V_53 = V_60 ;
V_9 -> V_38 = V_54 ;
} else {
F_12 ( V_61 , V_62 ) ;
F_28 ( V_9 ) ;
return ( 0 ) ;
}
if ( V_5 -> V_63 ) {
V_9 -> V_38 = 0 ;
goto V_64;
}
F_3 ( V_5 -> V_4 ) ;
F_3 ( V_5 -> V_49 -> V_4 ) ;
if ( V_5 -> V_65 )
V_48 = V_5 -> V_65 ;
else if ( V_5 -> V_49 -> V_65 )
V_48 = V_5 -> V_49 -> V_65 ;
F_5 ( V_5 -> V_49 -> V_4 ) ;
F_5 ( V_5 -> V_4 ) ;
memset ( V_9 -> V_39 , 0 , V_9 -> V_38 ) ;
V_47 = V_9 -> V_38 ;
if ( ! V_48 ( V_5 , V_9 -> V_39 , & V_47 ) ) {
F_12 ( V_61 ,
V_66 ) ;
F_28 ( V_9 ) ;
return ( 0 ) ;
}
if ( V_47 == 0 || V_47 > V_9 -> V_38 ) {
F_12 ( V_61 ,
V_67 ) ;
F_28 ( V_9 ) ;
return ( 0 ) ;
}
V_9 -> V_38 = V_47 ;
if ( F_34 ( V_5 , V_9 -> V_39 ,
V_9 -> V_38 ) ) {
F_12 ( V_61 , V_68 ) ;
F_28 ( V_9 ) ;
return ( 0 ) ;
}
V_64:
if ( V_5 -> V_23 ) {
V_9 -> V_23 = F_24 ( V_5 -> V_23 ) ;
if ( V_9 -> V_23 == NULL ) {
F_12 ( V_61 , V_69 ) ;
F_28 ( V_9 ) ;
return 0 ;
}
}
} else {
V_9 -> V_38 = 0 ;
}
if ( V_5 -> V_40 > sizeof V_9 -> V_41 ) {
F_12 ( V_61 , V_69 ) ;
F_28 ( V_9 ) ;
return 0 ;
}
memcpy ( V_9 -> V_41 , V_5 -> V_41 , V_5 -> V_40 ) ;
V_9 -> V_40 = V_5 -> V_40 ;
V_5 -> V_2 = V_9 ;
V_9 -> V_53 = V_5 -> V_51 ;
V_9 -> V_12 = V_70 ;
if ( V_5 -> V_71 -> V_72 & V_73 )
V_9 -> V_72 |= V_74 ;
return ( 1 ) ;
}
int F_37 ( T_2 * V_5 , const T_4 * V_75 , const T_4 * V_39 )
{
T_1 * V_76 = NULL ;
int V_77 = 0 ;
int V_78 = 1 ;
int V_79 ;
if ( F_38 ( V_39 ) == 0 )
V_78 = 0 ;
V_79 = F_39 ( V_5 , V_75 , V_39 , & V_76 ) ;
switch ( V_79 ) {
case - 1 :
V_77 = 1 ;
goto V_19;
case 0 :
case 1 :
break;
case 2 :
case 3 :
V_78 = 0 ;
break;
default:
abort () ;
}
if ( V_78 &&
V_76 == NULL &&
! ( V_5 -> V_49 -> V_80 &
V_81 ) ) {
T_1 V_82 ;
T_5 V_83 ;
V_82 . V_53 = V_5 -> V_51 ;
memset ( V_82 . V_39 , 0 , sizeof( V_82 . V_39 ) ) ;
if ( ! F_40 ( V_39 , V_82 . V_39 ,
sizeof( V_82 . V_39 ) , & V_83 ) ) {
goto V_19;
}
V_82 . V_38 = V_83 ;
F_3 ( V_5 -> V_49 -> V_4 ) ;
V_76 = F_41 ( V_5 -> V_49 -> V_84 , & V_82 ) ;
if ( V_76 != NULL ) {
F_4 ( V_76 ) ;
}
F_5 ( V_5 -> V_49 -> V_4 ) ;
if ( V_76 == NULL )
V_5 -> V_49 -> V_85 . V_86 ++ ;
}
if ( V_78 &&
V_76 == NULL && V_5 -> V_49 -> V_87 != NULL ) {
int V_88 = 1 ;
V_76 = V_5 -> V_49 -> V_87 ( V_5 , F_42 ( V_39 ) ,
F_38 ( V_39 ) ,
& V_88 ) ;
if ( V_76 != NULL ) {
V_5 -> V_49 -> V_85 . V_89 ++ ;
if ( V_88 )
F_4 ( V_76 ) ;
if ( !
( V_5 -> V_49 -> V_80 &
V_90 ) ) {
if ( F_43 ( V_5 -> V_49 , V_76 ) )
goto V_19;
}
}
}
if ( V_76 == NULL )
goto V_19;
if ( V_76 -> V_40 != V_5 -> V_40
|| memcmp ( V_76 -> V_41 , V_5 -> V_41 , V_76 -> V_40 ) ) {
goto V_19;
}
if ( ( V_5 -> V_91 & V_92 ) && V_5 -> V_40 == 0 ) {
F_12 ( V_93 ,
V_94 ) ;
V_77 = 1 ;
goto V_19;
}
if ( V_76 -> V_95 == NULL ) {
unsigned char V_96 [ 5 ] , * V_97 ;
unsigned long V_98 ;
V_97 = V_96 ;
V_98 = V_76 -> V_99 ;
F_44 ( V_98 , V_97 ) ;
if ( ( V_76 -> V_53 >> 8 ) >= V_100 )
V_76 -> V_95 = F_45 ( V_5 , & ( V_96 [ 2 ] ) ) ;
else
V_76 -> V_95 = F_45 ( V_5 , & ( V_96 [ 1 ] ) ) ;
if ( V_76 -> V_95 == NULL )
goto V_19;
}
if ( V_76 -> V_14 < ( long ) ( time ( NULL ) - V_76 -> time ) ) {
V_5 -> V_49 -> V_85 . V_101 ++ ;
if ( V_78 ) {
F_46 ( V_5 -> V_49 , V_76 ) ;
}
goto V_19;
}
if ( V_76 -> V_72 & V_74 ) {
if ( ! ( V_5 -> V_71 -> V_72 & V_73 ) ) {
F_12 ( V_93 , V_102 ) ;
F_47 ( V_5 , V_103 , V_104 ) ;
V_77 = 1 ;
goto V_19;
}
} else if ( V_5 -> V_71 -> V_72 & V_73 ) {
goto V_19;
}
V_5 -> V_49 -> V_85 . V_105 ++ ;
F_28 ( V_5 -> V_2 ) ;
V_5 -> V_2 = V_76 ;
V_5 -> V_12 = V_5 -> V_2 -> V_12 ;
return 1 ;
V_19:
if ( V_76 != NULL ) {
F_28 ( V_76 ) ;
if ( ! V_78 ) {
V_5 -> V_63 = 1 ;
}
}
if ( V_77 )
return - 1 ;
else
return 0 ;
}
int F_43 ( T_6 * V_106 , T_1 * V_107 )
{
int V_76 = 0 ;
T_1 * V_5 ;
F_4 ( V_107 ) ;
F_48 ( V_106 -> V_4 ) ;
V_5 = F_49 ( V_106 -> V_84 , V_107 ) ;
if ( V_5 != NULL && V_5 != V_107 ) {
F_50 ( V_106 , V_5 ) ;
F_28 ( V_5 ) ;
V_5 = NULL ;
}
if ( V_5 == NULL )
F_51 ( V_106 , V_107 ) ;
if ( V_5 != NULL ) {
F_28 ( V_5 ) ;
V_76 = 0 ;
} else {
V_76 = 1 ;
if ( F_52 ( V_106 ) > 0 ) {
while ( F_53 ( V_106 ) > F_52 ( V_106 ) ) {
if ( ! F_54 ( V_106 , V_106 -> V_108 , 0 ) )
break;
else
V_106 -> V_85 . V_109 ++ ;
}
}
}
F_5 ( V_106 -> V_4 ) ;
return V_76 ;
}
int F_46 ( T_6 * V_106 , T_1 * V_107 )
{
return F_54 ( V_106 , V_107 , 1 ) ;
}
static int F_54 ( T_6 * V_106 , T_1 * V_107 , int V_110 )
{
T_1 * V_79 ;
int V_76 = 0 ;
if ( ( V_107 != NULL ) && ( V_107 -> V_38 != 0 ) ) {
if ( V_110 )
F_48 ( V_106 -> V_4 ) ;
if ( ( V_79 = F_41 ( V_106 -> V_84 , V_107 ) ) == V_107 ) {
V_76 = 1 ;
V_79 = F_55 ( V_106 -> V_84 , V_107 ) ;
F_50 ( V_106 , V_107 ) ;
}
V_107 -> V_111 = 1 ;
if ( V_110 )
F_5 ( V_106 -> V_4 ) ;
if ( V_76 )
F_28 ( V_79 ) ;
if ( V_106 -> V_112 != NULL )
V_106 -> V_112 ( V_106 , V_107 ) ;
} else
V_76 = 0 ;
return ( V_76 ) ;
}
void F_28 ( T_1 * V_9 )
{
int V_113 ;
if ( V_9 == NULL )
return;
F_56 ( & V_9 -> V_13 , - 1 , & V_113 , V_9 -> V_4 ) ;
F_57 ( L_1 , V_9 ) ;
if ( V_113 > 0 )
return;
F_58 ( V_113 < 0 ) ;
F_59 ( V_15 , V_9 , & V_9 -> V_8 ) ;
F_60 ( V_9 -> V_114 , sizeof V_9 -> V_114 ) ;
F_60 ( V_9 -> V_39 , sizeof V_9 -> V_39 ) ;
F_61 ( V_9 -> V_30 ) ;
F_62 ( V_9 -> V_31 , F_61 ) ;
F_63 ( V_9 -> V_22 ) ;
F_14 ( V_9 -> V_23 ) ;
F_14 ( V_9 -> V_26 ) ;
#ifndef F_20
V_9 -> V_32 = 0 ;
F_14 ( V_9 -> V_24 ) ;
V_9 -> V_33 = 0 ;
F_14 ( V_9 -> V_25 ) ;
#endif
#ifndef F_19
F_14 ( V_9 -> V_20 ) ;
F_14 ( V_9 -> V_21 ) ;
#endif
#ifndef F_21
F_14 ( V_9 -> V_27 ) ;
#endif
F_16 ( V_9 -> V_4 ) ;
F_64 ( V_9 , sizeof( * V_9 ) ) ;
}
int F_4 ( T_1 * V_9 )
{
int V_113 ;
if ( F_56 ( & V_9 -> V_13 , 1 , & V_113 , V_9 -> V_4 ) <= 0 )
return 0 ;
F_57 ( L_1 , V_9 ) ;
F_58 ( V_113 < 2 ) ;
return ( ( V_113 > 1 ) ? 1 : 0 ) ;
}
int F_65 ( T_2 * V_5 , T_1 * V_2 )
{
F_66 ( V_5 ) ;
if ( V_5 -> V_106 -> V_115 != V_5 -> V_115 ) {
if ( ! F_67 ( V_5 , V_5 -> V_106 -> V_115 ) )
return 0 ;
}
if ( V_2 != NULL ) {
F_4 ( V_2 ) ;
V_5 -> V_12 = V_2 -> V_12 ;
}
F_28 ( V_5 -> V_2 ) ;
V_5 -> V_2 = V_2 ;
return 1 ;
}
int F_68 ( T_1 * V_5 , const unsigned char * V_116 ,
unsigned int V_117 )
{
if ( V_117 > V_118 ) {
F_12 ( V_119 ,
V_120 ) ;
return 0 ;
}
V_5 -> V_38 = V_117 ;
memcpy ( V_5 -> V_39 , V_116 , V_117 ) ;
return 1 ;
}
long F_69 ( T_1 * V_5 , long V_121 )
{
if ( V_5 == NULL )
return ( 0 ) ;
V_5 -> V_14 = V_121 ;
return ( 1 ) ;
}
long F_70 ( const T_1 * V_5 )
{
if ( V_5 == NULL )
return ( 0 ) ;
return ( V_5 -> V_14 ) ;
}
long F_71 ( const T_1 * V_5 )
{
if ( V_5 == NULL )
return ( 0 ) ;
return ( V_5 -> time ) ;
}
long F_72 ( T_1 * V_5 , long V_121 )
{
if ( V_5 == NULL )
return ( 0 ) ;
V_5 -> time = V_121 ;
return ( V_121 ) ;
}
int F_73 ( const T_1 * V_5 )
{
return V_5 -> V_53 ;
}
const T_7 * F_74 ( const T_1 * V_5 )
{
return V_5 -> V_95 ;
}
const char * F_75 ( const T_1 * V_5 )
{
return V_5 -> V_23 ;
}
int F_76 ( const T_1 * V_5 )
{
return ( V_5 -> V_34 > 0 ) ? 1 : 0 ;
}
unsigned long F_77 ( const T_1 * V_5 )
{
return V_5 -> V_35 ;
}
void F_78 ( const T_1 * V_5 , const unsigned char * * V_122 ,
T_5 * V_37 )
{
* V_37 = V_5 -> V_34 ;
if ( V_122 != NULL )
* V_122 = V_5 -> V_26 ;
}
T_8 * F_79 ( T_1 * V_5 )
{
return V_5 -> V_30 ;
}
int F_80 ( T_1 * V_5 , const unsigned char * V_41 ,
unsigned int V_123 )
{
if ( V_123 > V_124 ) {
F_12 ( V_125 ,
V_126 ) ;
return 0 ;
}
V_5 -> V_40 = V_123 ;
memcpy ( V_5 -> V_41 , V_41 , V_123 ) ;
return 1 ;
}
long F_81 ( T_6 * V_5 , long V_121 )
{
long V_98 ;
if ( V_5 == NULL )
return ( 0 ) ;
V_98 = V_5 -> V_50 ;
V_5 -> V_50 = V_121 ;
return ( V_98 ) ;
}
long F_82 ( const T_6 * V_5 )
{
if ( V_5 == NULL )
return ( 0 ) ;
return ( V_5 -> V_50 ) ;
}
int F_83 ( T_2 * V_5 , T_9 V_48 ,
void * V_7 )
{
if ( V_5 == NULL )
return ( 0 ) ;
V_5 -> V_127 = V_48 ;
V_5 -> V_128 = V_7 ;
return ( 1 ) ;
}
int F_84 ( T_2 * V_5 , void * V_129 , int V_130 )
{
if ( V_5 -> V_51 >= V_55 ) {
F_14 ( V_5 -> V_131 ) ;
V_5 -> V_131 = NULL ;
V_5 -> V_131 =
F_18 ( sizeof( V_132 ) + V_130 ) ;
if ( V_5 -> V_131 == NULL ) {
F_12 ( V_133 , V_11 ) ;
return 0 ;
}
if ( V_129 ) {
V_5 -> V_131 -> V_134 = V_130 ;
V_5 -> V_131 -> V_82 = V_5 -> V_131 + 1 ;
memcpy ( V_5 -> V_131 -> V_82 , V_129 , V_130 ) ;
} else {
V_5 -> V_131 -> V_134 = 0 ;
V_5 -> V_131 -> V_82 = NULL ;
}
return 1 ;
}
return 0 ;
}
static void F_85 ( T_1 * V_5 , T_10 * V_97 )
{
if ( ( V_97 -> time == 0 ) || ( V_97 -> time > ( V_5 -> time + V_5 -> V_14 ) ) ) {
( void ) F_55 ( V_97 -> V_135 , V_5 ) ;
F_50 ( V_97 -> V_106 , V_5 ) ;
V_5 -> V_111 = 1 ;
if ( V_97 -> V_106 -> V_112 != NULL )
V_97 -> V_106 -> V_112 ( V_97 -> V_106 , V_5 ) ;
F_28 ( V_5 ) ;
}
}
void F_86 ( T_6 * V_5 , long V_121 )
{
unsigned long V_113 ;
T_10 V_136 ;
V_136 . V_106 = V_5 ;
V_136 . V_135 = V_5 -> V_84 ;
if ( V_136 . V_135 == NULL )
return;
V_136 . time = V_121 ;
F_48 ( V_5 -> V_4 ) ;
V_113 = F_87 ( V_5 -> V_84 ) ;
F_88 ( V_5 -> V_84 , 0 ) ;
F_89 ( V_136 . V_135 , F_85 , & V_136 ) ;
F_88 ( V_5 -> V_84 , V_113 ) ;
F_5 ( V_5 -> V_4 ) ;
}
int F_66 ( T_2 * V_5 )
{
if ( ( V_5 -> V_2 != NULL ) &&
! ( V_5 -> V_137 & V_138 ) &&
! ( F_90 ( V_5 ) || F_91 ( V_5 ) ) ) {
F_46 ( V_5 -> V_49 , V_5 -> V_2 ) ;
return ( 1 ) ;
} else
return ( 0 ) ;
}
static void F_50 ( T_6 * V_106 , T_1 * V_5 )
{
if ( ( V_5 -> V_29 == NULL ) || ( V_5 -> V_28 == NULL ) )
return;
if ( V_5 -> V_29 == ( T_1 * ) & ( V_106 -> V_108 ) ) {
if ( V_5 -> V_28 == ( T_1 * ) & ( V_106 -> V_139 ) ) {
V_106 -> V_139 = NULL ;
V_106 -> V_108 = NULL ;
} else {
V_106 -> V_108 = V_5 -> V_28 ;
V_5 -> V_28 -> V_29 = ( T_1 * ) & ( V_106 -> V_108 ) ;
}
} else {
if ( V_5 -> V_28 == ( T_1 * ) & ( V_106 -> V_139 ) ) {
V_106 -> V_139 = V_5 -> V_29 ;
V_5 -> V_29 -> V_28 = ( T_1 * ) & ( V_106 -> V_139 ) ;
} else {
V_5 -> V_29 -> V_28 = V_5 -> V_28 ;
V_5 -> V_28 -> V_29 = V_5 -> V_29 ;
}
}
V_5 -> V_28 = V_5 -> V_29 = NULL ;
}
static void F_51 ( T_6 * V_106 , T_1 * V_5 )
{
if ( ( V_5 -> V_29 != NULL ) && ( V_5 -> V_28 != NULL ) )
F_50 ( V_106 , V_5 ) ;
if ( V_106 -> V_139 == NULL ) {
V_106 -> V_139 = V_5 ;
V_106 -> V_108 = V_5 ;
V_5 -> V_28 = ( T_1 * ) & ( V_106 -> V_139 ) ;
V_5 -> V_29 = ( T_1 * ) & ( V_106 -> V_108 ) ;
} else {
V_5 -> V_29 = V_106 -> V_139 ;
V_5 -> V_29 -> V_28 = V_5 ;
V_5 -> V_28 = ( T_1 * ) & ( V_106 -> V_139 ) ;
V_106 -> V_139 = V_5 ;
}
}
void F_92 ( T_6 * V_106 ,
int (* V_48) ( struct V_140 * V_1 , T_1 * V_3 ) )
{
V_106 -> V_141 = V_48 ;
}
void F_93 ( T_6 * V_106 ,
void (* V_48) ( T_6 * V_106 , T_1 * V_3 ) )
{
V_106 -> V_112 = V_48 ;
}
void F_94 ( T_6 * V_106 ,
T_1 * (* V_48) ( struct V_140 * V_1 ,
const unsigned char * V_82 ,
int V_37 , int * V_88 ) )
{
V_106 -> V_87 = V_48 ;
}
void F_95 ( T_6 * V_106 ,
void (* V_48) ( const T_2 * V_1 , int type , int V_142 ) )
{
V_106 -> V_143 = V_48 ;
}
void F_96 ( T_6 * V_106 ,
int (* V_48) ( T_2 * V_1 , T_8 * * V_144 ,
T_11 * * V_145 ) )
{
V_106 -> V_146 = V_48 ;
}
int F_97 ( T_6 * V_106 , T_12 * V_147 )
{
if ( ! F_98 ( V_147 ) ) {
F_12 ( V_148 , V_149 ) ;
return 0 ;
}
if ( ! F_99 ( V_147 ) ) {
F_12 ( V_148 ,
V_150 ) ;
F_100 ( V_147 ) ;
return 0 ;
}
V_106 -> V_151 = V_147 ;
return 1 ;
}
void F_101 ( T_6 * V_106 ,
int (* V_48) ( T_2 * V_1 ,
unsigned char * V_152 ,
unsigned int * V_153 ) )
{
V_106 -> V_154 = V_48 ;
}
void F_102 ( T_6 * V_106 ,
int (* V_48) ( T_2 * V_1 ,
const unsigned char * V_152 ,
unsigned int V_153 ) )
{
V_106 -> V_155 = V_48 ;
}
