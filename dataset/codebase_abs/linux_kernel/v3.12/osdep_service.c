inline int F_1 ( int V_1 )
{
if ( V_1 >= 0 )
return V_2 ;
return V_3 ;
}
T_1 F_2 ( T_2 * V_4 )
{
int V_5 = 0 , V_6 = 0 ;
int V_7 ;
for ( V_7 = 0 ; V_7 <= strlen ( V_4 ) ; V_7 ++ ) {
if ( V_4 [ V_7 ] >= '0' && V_4 [ V_7 ] <= '9' )
V_5 = V_5 * 10 + V_4 [ V_7 ] - '0' ;
else if ( V_4 [ 0 ] == '-' && V_7 == 0 )
V_6 = 1 ;
else
break;
}
if ( V_6 == 1 )
V_5 = V_5 * - 1 ;
return V_5 ;
}
inline T_2 * F_3 ( T_1 V_8 )
{
T_2 * V_9 ;
V_9 = F_4 ( V_8 ) ;
return V_9 ;
}
inline T_2 * F_5 ( T_1 V_8 )
{
T_2 * V_9 ;
V_9 = F_3 ( V_8 ) ;
if ( V_9 != NULL )
memset ( V_9 , 0 , V_8 ) ;
return V_9 ;
}
inline void F_6 ( T_2 * V_9 , T_1 V_8 )
{
F_7 ( V_9 ) ;
}
T_2 * F_8 ( T_1 V_8 )
{
T_2 * V_9 = NULL ;
V_9 = F_9 ( V_8 , F_10 () ? V_10 : V_11 ) ;
return V_9 ;
}
T_2 * F_11 ( T_1 V_8 )
{
T_2 * V_9 = F_8 ( V_8 ) ;
if ( V_9 != NULL )
memset ( V_9 , 0 , V_8 ) ;
return V_9 ;
}
void * F_12 ( int V_12 , int V_13 , int V_14 )
{
int V_15 ;
void * * V_16 = ( void * * ) F_13 ( V_12 * sizeof( void * ) + V_12 * V_13 * V_14 ) ;
if ( V_16 == NULL ) {
F_14 ( L_1 , V_17 ) ;
return NULL ;
}
for ( V_15 = 0 ; V_15 < V_12 ; V_15 ++ )
V_16 [ V_15 ] = ( ( char * ) ( V_16 + V_12 ) ) + V_15 * V_13 * V_14 ;
return V_16 ;
}
void F_15 ( void * V_9 , int V_12 , int V_13 , int V_14 )
{
F_16 ( V_9 ) ;
}
int F_17 ( void * V_18 , void * V_19 , T_1 V_8 )
{
if ( ! ( memcmp ( V_18 , V_19 , V_8 ) ) )
return true ;
else
return false ;
}
void F_18 ( void * V_9 , int V_20 , T_1 V_8 )
{
memset ( V_9 , V_20 , V_8 ) ;
}
void F_19 ( struct V_21 * V_22 )
{
F_20 ( V_22 ) ;
}
T_1 F_21 ( struct V_21 * V_23 )
{
if ( F_22 ( V_23 ) )
return true ;
else
return false ;
}
void F_23 ( struct V_21 * V_24 , struct V_21 * V_23 )
{
F_24 ( V_24 , V_23 ) ;
}
void F_25 ( struct V_21 * V_24 , struct V_21 * V_23 )
{
F_26 ( V_24 , V_23 ) ;
}
void F_27 ( struct V_25 * V_26 , int V_27 )
{
F_28 ( V_26 , V_27 ) ;
}
void F_29 ( struct V_25 * V_26 )
{
}
void F_30 ( struct V_25 * V_26 )
{
F_31 ( V_26 ) ;
}
T_1 F_32 ( struct V_25 * V_26 )
{
if ( F_33 ( V_26 ) )
return V_3 ;
else
return V_2 ;
}
void F_34 ( struct V_28 * V_29 )
{
F_35 ( V_29 ) ;
}
void F_36 ( struct V_28 * V_29 )
{
F_37 ( V_29 ) ;
}
void F_38 ( T_3 * V_30 )
{
F_39 ( V_30 ) ;
}
void F_40 ( T_3 * V_30 )
{
}
void F_41 ( struct V_31 * V_32 )
{
F_19 ( & ( V_32 -> V_33 ) ) ;
F_38 ( & ( V_32 -> V_34 ) ) ;
}
T_1 F_42 ( struct V_31 * V_32 )
{
return F_21 ( & ( V_32 -> V_33 ) ) ;
}
T_1 F_43 ( struct V_21 * V_35 , struct V_21 * V_24 )
{
if ( V_35 == V_24 )
return true ;
else
return false ;
}
T_1 F_44 ( void )
{
return V_36 ;
}
inline T_1 F_45 ( T_1 V_37 )
{
return V_37 * 1000 / V_38 ;
}
inline T_1 F_46 ( T_1 V_39 )
{
return V_39 * V_38 / 1000 ;
}
inline T_4 F_47 ( T_1 V_40 )
{
return F_45 ( V_36 - V_40 ) ;
}
inline T_4 F_48 ( T_1 V_40 , T_1 V_41 )
{
return F_45 ( V_41 - V_40 ) ;
}
void F_49 ( int V_39 )
{
T_1 V_42 ;
V_42 = ( V_39 * V_38 ) / 1000 ;
if ( V_42 == 0 )
V_42 = 1 ;
F_50 ( V_43 ) ;
if ( F_51 ( V_42 ) != 0 )
return;
}
void F_52 ( int V_39 )
{
F_53 ( ( unsigned int ) V_39 ) ;
}
void F_54 ( int V_44 )
{
if ( 1 < ( V_44 / 1000 ) )
F_53 ( 1 ) ;
else
F_53 ( ( V_44 / 1000 ) + 1 ) ;
}
void F_55 ( int V_39 )
{
F_56 ( ( unsigned long ) V_39 ) ;
}
void F_57 ( int V_44 )
{
F_58 ( ( unsigned long ) V_44 ) ;
}
void F_59 ( void )
{
F_60 () ;
}
inline void F_61 ( void )
{
}
inline void F_62 ( void )
{
}
inline void F_63 ( void )
{
}
inline void F_64 ( void )
{
}
inline void F_65 ( T_5 * V_45 , int V_7 )
{
F_66 ( V_45 , V_7 ) ;
}
inline int F_67 ( T_5 * V_45 )
{
return F_68 ( V_45 ) ;
}
inline void F_69 ( T_5 * V_45 , int V_7 )
{
F_70 ( V_7 , V_45 ) ;
}
inline void F_71 ( T_5 * V_45 , int V_7 )
{
F_72 ( V_7 , V_45 ) ;
}
inline void F_73 ( T_5 * V_45 )
{
F_74 ( V_45 ) ;
}
inline void F_75 ( T_5 * V_45 )
{
F_76 ( V_45 ) ;
}
inline int F_77 ( T_5 * V_45 , int V_7 )
{
return F_78 ( V_7 , V_45 ) ;
}
inline int F_79 ( T_5 * V_45 , int V_7 )
{
return F_80 ( V_7 , V_45 ) ;
}
inline int F_81 ( T_5 * V_45 )
{
return F_82 ( V_45 ) ;
}
inline int F_83 ( T_5 * V_45 )
{
return F_84 ( V_45 ) ;
}
static int F_85 ( struct V_46 * * V_47 , char * V_48 , int V_6 , int V_49 )
{
struct V_46 * V_50 ;
V_50 = F_86 ( V_48 , V_6 , V_49 ) ;
if ( F_87 ( V_50 ) ) {
* V_47 = NULL ;
return F_88 ( V_50 ) ;
} else {
* V_47 = V_50 ;
return 0 ;
}
}
static int F_89 ( struct V_46 * V_50 )
{
F_90 ( V_50 , NULL ) ;
return 0 ;
}
static int F_91 ( struct V_46 * V_50 , char T_6 * V_51 , int V_52 )
{
int V_53 = 0 , V_54 = 0 ;
if ( ! V_50 -> V_55 || ! V_50 -> V_55 -> V_56 )
return - V_57 ;
while ( V_54 < V_52 ) {
V_53 = V_50 -> V_55 -> V_56 ( V_50 , V_51 + V_54 , V_52 - V_54 , & V_50 -> V_58 ) ;
if ( V_53 > 0 )
V_54 += V_53 ;
else if ( 0 != V_53 )
return V_53 ;
else
break;
}
return V_54 ;
}
static int F_92 ( struct V_46 * V_50 , char T_6 * V_51 , int V_52 )
{
int V_59 = 0 , V_54 = 0 ;
if ( ! V_50 -> V_55 || ! V_50 -> V_55 -> V_60 )
return - V_57 ;
while ( V_54 < V_52 ) {
V_59 = V_50 -> V_55 -> V_60 ( V_50 , V_51 + V_54 , V_52 - V_54 , & V_50 -> V_58 ) ;
if ( V_59 > 0 )
V_54 += V_59 ;
else if ( 0 != V_59 )
return V_59 ;
else
break;
}
return V_54 ;
}
static int F_93 ( char * V_48 )
{
struct V_46 * V_50 ;
int V_61 = 0 ;
T_7 V_62 ;
char T_6 V_51 ;
V_50 = F_86 ( V_48 , V_63 , 0 ) ;
if ( F_87 ( V_50 ) ) {
V_61 = F_88 ( V_50 ) ;
} else {
V_62 = F_94 () ; F_95 ( F_96 () ) ;
if ( 1 != F_91 ( V_50 , & V_51 , 1 ) )
V_61 = F_88 ( V_50 ) ;
F_95 ( V_62 ) ;
F_90 ( V_50 , NULL ) ;
}
return V_61 ;
}
static int F_97 ( char * V_48 , T_2 T_6 * V_51 , T_1 V_8 )
{
int V_61 = - 1 ;
T_7 V_62 ;
struct V_46 * V_50 ;
if ( V_48 && V_51 ) {
V_61 = F_85 ( & V_50 , V_48 , V_63 , 0 ) ;
if ( 0 == V_61 ) {
F_98 ( L_2 , V_17 ,
V_48 , V_50 ) ;
V_62 = F_94 () ; F_95 ( F_96 () ) ;
V_61 = F_91 ( V_50 , V_51 , V_8 ) ;
F_95 ( V_62 ) ;
F_89 ( V_50 ) ;
F_98 ( L_3 , V_17 , V_61 ) ;
} else {
F_98 ( L_4 , V_17 ,
V_48 , V_61 ) ;
}
} else {
F_98 ( L_5 , V_17 ) ;
V_61 = - V_64 ;
}
return V_61 ;
}
static int F_99 ( char * V_48 , T_2 T_6 * V_51 , T_1 V_8 )
{
int V_61 = 0 ;
T_7 V_62 ;
struct V_46 * V_50 ;
if ( V_48 && V_51 ) {
V_61 = F_85 ( & V_50 , V_48 , V_65 | V_66 , 0666 ) ;
if ( 0 == V_61 ) {
F_98 ( L_2 , V_17 , V_48 , V_50 ) ;
V_62 = F_94 () ; F_95 ( F_96 () ) ;
V_61 = F_92 ( V_50 , V_51 , V_8 ) ;
F_95 ( V_62 ) ;
F_89 ( V_50 ) ;
F_98 ( L_6 , V_17 , V_61 ) ;
} else {
F_98 ( L_4 , V_17 , V_48 , V_61 ) ;
}
} else {
F_98 ( L_5 , V_17 ) ;
V_61 = - V_64 ;
}
return V_61 ;
}
int F_100 ( char * V_48 )
{
if ( F_93 ( V_48 ) == 0 )
return true ;
else
return false ;
}
int F_101 ( char * V_48 , T_2 T_6 * V_51 , T_1 V_8 )
{
int V_61 = F_97 ( V_48 , V_51 , V_8 ) ;
return V_61 >= 0 ? V_61 : 0 ;
}
int F_102 ( char * V_48 , T_2 T_6 * V_51 , T_1 V_8 )
{
int V_61 = F_99 ( V_48 , V_51 , V_8 ) ;
return V_61 >= 0 ? V_61 : 0 ;
}
struct V_67 * F_103 ( int V_68 ,
void * V_69 )
{
struct V_67 * V_70 ;
struct V_71 * V_72 ;
V_70 = F_104 ( sizeof( struct V_71 ) , 4 ) ;
if ( ! V_70 )
goto RETURN;
V_72 = F_105 ( V_70 ) ;
V_72 -> V_73 = V_69 ;
V_72 -> V_68 = V_68 ;
RETURN:
return V_70 ;
}
struct V_67 * F_106 ( int V_68 )
{
struct V_67 * V_70 ;
struct V_71 * V_72 ;
V_70 = F_104 ( sizeof( struct V_71 ) , 4 ) ;
if ( ! V_70 )
goto RETURN;
V_72 = F_105 ( V_70 ) ;
V_72 -> V_73 = F_107 ( V_68 ) ;
if ( ! V_72 -> V_73 ) {
F_108 ( V_70 ) ;
V_70 = NULL ;
goto RETURN;
}
V_72 -> V_68 = V_68 ;
RETURN:
return V_70 ;
}
void F_109 ( struct V_67 * V_74 )
{
struct V_71 * V_72 ;
if ( ! V_74 )
goto RETURN;
V_72 = F_105 ( V_74 ) ;
if ( ! V_72 -> V_73 )
goto RETURN;
F_110 ( V_72 -> V_73 , V_72 -> V_68 ) ;
F_108 ( V_74 ) ;
RETURN:
return;
}
int F_111 ( struct V_75 * V_76 , const char * V_77 )
{
struct V_67 * V_70 ;
struct V_67 * V_78 = V_76 -> V_70 ;
struct V_79 * V_80 ;
int V_61 ;
if ( ! V_76 )
goto error;
V_80 = & V_76 -> V_81 ;
if ( V_80 -> V_82 ) {
F_108 ( V_80 -> V_82 ) ;
V_80 -> V_82 = NULL ;
}
if ( ! F_112 () )
F_113 ( V_78 ) ;
else
F_114 ( V_78 ) ;
F_115 ( V_78 ) ;
V_80 -> V_82 = V_78 ;
V_70 = F_116 ( V_76 ) ;
if ( ! V_70 ) {
V_61 = - 1 ;
goto error;
}
F_117 ( V_70 , F_118 ( F_119 ( V_76 ) ) ) ;
F_120 ( V_70 , V_77 ) ;
memcpy ( V_70 -> V_83 , V_76 -> V_84 . V_85 , V_86 ) ;
if ( ! F_112 () )
V_61 = F_121 ( V_70 ) ;
else
V_61 = F_122 ( V_70 ) ;
if ( V_61 != 0 ) {
F_123 ( V_87 , V_88 ,
( L_7 ) ) ;
goto error;
}
F_124 ( V_70 ) ;
return 0 ;
error:
return - 1 ;
}
T_8 F_125 ( T_8 V_89 , T_8 V_90 )
{
return F_126 ( V_89 , V_90 ) ;
}
T_8 F_127 ( T_8 V_89 , T_8 V_90 )
{
F_126 ( V_89 , V_90 ) ;
return V_89 ;
}
void F_128 ( T_2 * * V_51 , T_1 * V_91 )
{
* V_91 = 0 ;
F_16 ( * V_51 ) ;
* V_51 = NULL ;
}
void F_129 ( T_2 * * V_51 , T_1 * V_91 , T_2 * V_19 , T_1 V_92 )
{
T_1 V_93 = 0 , V_94 = 0 ;
T_2 * V_95 = NULL ;
T_2 * V_96 = NULL ;
if ( ! V_51 || ! V_91 )
return;
if ( ! V_19 || ! V_92 )
goto V_97;
V_96 = F_130 ( V_92 ) ;
if ( V_96 ) {
V_94 = V_92 ;
memcpy ( V_96 , V_19 , V_94 ) ;
}
V_97:
V_95 = * V_51 ;
V_93 = * V_91 ;
* V_91 = 0 ;
* V_51 = V_96 ;
* V_91 = V_94 ;
F_16 ( V_95 ) ;
}
inline bool F_131 ( struct V_98 * V_99 )
{
return ( V_99 -> V_60 == V_99 -> V_56 - 1 ) ? true : false ;
}
inline bool F_132 ( struct V_98 * V_99 )
{
return ( V_99 -> V_60 == V_99 -> V_56 ) ? true : false ;
}
bool F_133 ( struct V_98 * V_99 , void * V_51 )
{
if ( F_131 ( V_99 ) )
return V_3 ;
if ( 0 )
F_98 ( L_8 , V_17 , V_99 -> V_60 ) ;
V_99 -> V_100 [ V_99 -> V_60 ] = V_51 ;
V_99 -> V_60 = ( V_99 -> V_60 + 1 ) % V_99 -> V_14 ;
return V_2 ;
}
void * F_134 ( struct V_98 * V_99 )
{
void * V_51 ;
if ( F_132 ( V_99 ) )
return NULL ;
if ( 0 )
F_98 ( L_8 , V_17 , V_99 -> V_56 ) ;
V_51 = V_99 -> V_100 [ V_99 -> V_56 ] ;
V_99 -> V_56 = ( V_99 -> V_56 + 1 ) % V_99 -> V_14 ;
return V_51 ;
}
struct V_98 * F_135 ( T_1 V_14 )
{
struct V_98 * V_99 ;
V_99 = (struct V_98 * ) F_130 ( sizeof( * V_99 ) +
sizeof( void * ) * V_14 ) ;
if ( V_99 ) {
V_99 -> V_60 = 0 ;
V_99 -> V_56 = 0 ;
V_99 -> V_14 = V_14 ;
}
return V_99 ;
}
