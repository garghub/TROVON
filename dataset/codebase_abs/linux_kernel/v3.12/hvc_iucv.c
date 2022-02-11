struct V_1 * F_1 ( T_1 V_2 )
{
if ( ( V_2 < V_3 ) || ( V_2 - V_3 > V_4 ) )
return NULL ;
return V_5 [ V_2 - V_3 ] ;
}
static struct V_6 * F_2 ( T_2 V_7 , T_3 V_8 )
{
struct V_6 * V_9 ;
V_9 = F_3 ( V_10 , V_8 ) ;
if ( ! V_9 )
return NULL ;
memset ( V_9 , 0 , sizeof( * V_9 ) ) ;
if ( V_7 > 0 ) {
V_9 -> V_11 . V_12 = F_4 ( V_7 ) ;
V_9 -> V_13 = F_5 ( V_9 -> V_11 . V_12 , V_8 | V_14 ) ;
if ( ! V_9 -> V_13 ) {
F_6 ( V_9 , V_10 ) ;
return NULL ;
}
V_9 -> V_13 -> V_15 = V_16 ;
V_9 -> V_13 -> type = V_17 ;
V_9 -> V_13 -> V_18 = ( V_19 ) V_7 ;
}
return V_9 ;
}
static void F_7 ( struct V_6 * V_9 )
{
F_8 ( V_9 -> V_13 ) ;
F_6 ( V_9 , V_10 ) ;
}
static void F_9 ( struct V_20 * V_21 )
{
struct V_6 * V_22 , * V_23 ;
F_10 (ent, next, list, list) {
F_11 ( & V_22 -> V_21 ) ;
F_7 ( V_22 ) ;
}
}
static int F_12 ( struct V_1 * V_24 ,
char * V_25 , int V_26 , int * V_27 )
{
struct V_6 * V_28 ;
int V_29 ;
int V_30 ;
if ( V_24 -> V_31 == V_32 )
return 0 ;
if ( V_24 -> V_31 == V_33 )
return - V_34 ;
if ( F_13 ( & V_24 -> V_35 ) )
return 0 ;
V_28 = F_14 ( & V_24 -> V_35 , struct V_6 , V_21 ) ;
V_29 = 0 ;
if ( ! V_28 -> V_13 ) {
V_28 -> V_13 = F_5 ( V_28 -> V_11 . V_12 , V_36 | V_14 ) ;
if ( ! V_28 -> V_13 )
return - V_37 ;
V_30 = F_15 ( V_24 -> V_38 , & V_28 -> V_11 , 0 ,
V_28 -> V_13 , V_28 -> V_11 . V_12 , NULL ) ;
switch ( V_30 ) {
case 0 :
break;
case 2 :
case 9 :
break;
default:
V_29 = - V_39 ;
}
if ( V_30 || ( V_28 -> V_13 -> V_15 != V_16 ) ||
( V_28 -> V_11 . V_12 != F_4 ( V_28 -> V_13 -> V_18 ) ) )
goto V_40;
}
switch ( V_28 -> V_13 -> type ) {
case V_17 :
V_29 = F_16 ( int , V_28 -> V_13 -> V_18 - V_28 -> V_41 , V_26 ) ;
memcpy ( V_25 , V_28 -> V_13 -> V_42 + V_28 -> V_41 , V_29 ) ;
if ( V_29 < ( V_28 -> V_13 -> V_18 - V_28 -> V_41 ) ) {
V_28 -> V_41 += V_29 ;
* V_27 = 1 ;
goto V_43;
}
break;
case V_44 :
if ( V_28 -> V_13 -> V_18 != sizeof( struct V_45 ) )
break;
F_17 ( V_24 -> V_46 , * ( (struct V_45 * ) V_28 -> V_13 -> V_42 ) ) ;
break;
case V_47 :
case V_48 :
case V_49 :
break;
}
V_40:
F_11 ( & V_28 -> V_21 ) ;
F_7 ( V_28 ) ;
* V_27 = ! F_13 ( & V_24 -> V_35 ) ;
V_43:
return V_29 ;
}
static int F_18 ( T_1 V_50 , char * V_25 , int V_26 )
{
struct V_1 * V_24 = F_1 ( V_50 ) ;
int V_29 ;
int V_27 ;
if ( V_26 <= 0 )
return 0 ;
if ( ! V_24 )
return - V_51 ;
F_19 ( & V_24 -> V_52 ) ;
V_27 = 0 ;
V_29 = F_12 ( V_24 , V_25 , V_26 , & V_27 ) ;
F_20 ( & V_24 -> V_52 ) ;
if ( V_27 )
F_21 () ;
return V_29 ;
}
static int F_22 ( struct V_1 * V_24 , const char * V_25 ,
int V_26 )
{
T_2 V_53 ;
if ( V_24 -> V_31 == V_32 )
return V_26 ;
if ( V_24 -> V_31 == V_33 )
return - V_34 ;
V_53 = F_16 ( T_2 , V_26 , V_54 - V_24 -> V_55 ) ;
if ( ! V_53 )
return 0 ;
memcpy ( V_24 -> V_56 + V_24 -> V_55 , V_25 , V_53 ) ;
V_24 -> V_55 += V_53 ;
if ( V_24 -> V_31 == V_57 )
F_23 ( & V_24 -> V_58 , V_59 ) ;
return V_53 ;
}
static int F_24 ( struct V_1 * V_24 )
{
struct V_6 * V_60 ;
int V_30 , V_53 ;
if ( V_24 -> V_31 == V_33 )
return - V_34 ;
if ( V_24 -> V_31 == V_32 )
return - V_39 ;
if ( ! V_24 -> V_55 )
return 0 ;
V_60 = F_2 ( V_24 -> V_55 , V_36 ) ;
if ( ! V_60 )
return - V_37 ;
memcpy ( V_60 -> V_13 -> V_42 , V_24 -> V_56 , V_24 -> V_55 ) ;
V_60 -> V_13 -> V_18 = ( V_19 ) V_24 -> V_55 ;
V_60 -> V_11 . V_12 = F_4 ( V_60 -> V_13 -> V_18 ) ;
F_25 ( & V_60 -> V_21 , & V_24 -> V_61 ) ;
V_30 = F_26 ( V_24 -> V_38 , & V_60 -> V_11 , 0 , 0 ,
( void * ) V_60 -> V_13 , V_60 -> V_11 . V_12 ) ;
if ( V_30 ) {
F_11 ( & V_60 -> V_21 ) ;
F_7 ( V_60 ) ;
}
V_53 = V_24 -> V_55 ;
V_24 -> V_55 = 0 ;
return V_53 ;
}
static void F_27 ( struct V_62 * V_63 )
{
struct V_1 * V_24 ;
V_24 = F_28 ( V_63 , struct V_1 , V_58 . V_63 ) ;
if ( ! V_24 )
return;
F_29 ( & V_24 -> V_52 ) ;
F_24 ( V_24 ) ;
F_30 ( & V_24 -> V_52 ) ;
}
static int F_31 ( T_1 V_50 , const char * V_25 , int V_26 )
{
struct V_1 * V_24 = F_1 ( V_50 ) ;
int V_64 ;
if ( V_26 <= 0 )
return 0 ;
if ( ! V_24 )
return - V_51 ;
F_19 ( & V_24 -> V_52 ) ;
V_64 = F_22 ( V_24 , V_25 , V_26 ) ;
F_20 ( & V_24 -> V_52 ) ;
return V_64 ;
}
static int F_32 ( struct V_65 * V_66 , int V_67 )
{
struct V_1 * V_24 ;
V_24 = F_1 ( V_67 ) ;
if ( ! V_24 )
return 0 ;
F_29 ( & V_24 -> V_52 ) ;
V_24 -> V_68 = V_69 ;
F_30 ( & V_24 -> V_52 ) ;
return 0 ;
}
static void F_33 ( struct V_1 * V_24 )
{
F_9 ( & V_24 -> V_61 ) ;
F_9 ( & V_24 -> V_35 ) ;
V_24 -> V_68 = V_70 ;
V_24 -> V_31 = V_32 ;
V_24 -> V_55 = 0 ;
}
static inline int F_34 ( struct V_1 * V_24 )
{
int V_30 ;
F_29 ( & V_24 -> V_52 ) ;
V_30 = F_13 ( & V_24 -> V_61 ) ;
F_30 ( & V_24 -> V_52 ) ;
return V_30 ;
}
static void F_35 ( struct V_1 * V_24 )
{
int V_71 ;
F_36 ( & V_24 -> V_58 ) ;
F_29 ( & V_24 -> V_52 ) ;
F_24 ( V_24 ) ;
V_71 = ! F_13 ( & V_24 -> V_61 ) ;
F_30 ( & V_24 -> V_52 ) ;
if ( V_71 )
F_37 ( V_24 -> V_72 ,
F_34 ( V_24 ) , V_73 / 10 ) ;
}
static void F_38 ( struct V_1 * V_24 )
{
struct V_74 * V_38 ;
V_38 = NULL ;
F_19 ( & V_24 -> V_52 ) ;
if ( V_24 -> V_31 == V_57 ) {
V_38 = V_24 -> V_38 ;
V_24 -> V_38 = NULL ;
V_24 -> V_31 = V_33 ;
if ( V_24 -> V_68 == V_70 )
F_33 ( V_24 ) ;
else
if ( V_24 -> V_75 ) {
F_33 ( V_24 ) ;
V_24 -> V_68 = V_69 ;
} else
F_21 () ;
}
F_20 ( & V_24 -> V_52 ) ;
if ( V_38 ) {
F_39 ( V_38 , NULL ) ;
F_40 ( V_38 ) ;
}
}
static void F_41 ( struct V_65 * V_66 , int V_67 )
{
struct V_1 * V_24 ;
V_24 = F_1 ( V_67 ) ;
if ( ! V_24 )
return;
F_35 ( V_24 ) ;
F_29 ( & V_24 -> V_52 ) ;
V_24 -> V_68 = V_70 ;
if ( V_24 -> V_31 == V_33 )
F_33 ( V_24 ) ;
F_30 ( & V_24 -> V_52 ) ;
}
static void F_42 ( struct V_65 * V_66 , int raise )
{
struct V_1 * V_24 ;
struct V_74 * V_38 ;
if ( raise )
return;
V_24 = F_1 ( V_66 -> V_50 ) ;
if ( ! V_24 )
return;
F_35 ( V_24 ) ;
F_29 ( & V_24 -> V_52 ) ;
V_38 = V_24 -> V_38 ;
V_24 -> V_38 = NULL ;
V_24 -> V_31 = V_32 ;
F_30 ( & V_24 -> V_52 ) ;
if ( V_38 ) {
F_39 ( V_38 , NULL ) ;
F_40 ( V_38 ) ;
}
}
static void F_43 ( struct V_65 * V_66 , int V_67 )
{
struct V_1 * V_24 ;
V_24 = F_1 ( V_67 ) ;
if ( ! V_24 )
return;
F_35 ( V_24 ) ;
F_29 ( & V_24 -> V_52 ) ;
F_9 ( & V_24 -> V_61 ) ;
F_9 ( & V_24 -> V_35 ) ;
V_24 -> V_68 = V_70 ;
V_24 -> V_55 = 0 ;
F_30 ( & V_24 -> V_52 ) ;
}
static int F_44 ( T_4 V_76 [ 8 ] )
{
T_2 V_77 ;
if ( ! V_78 )
return 0 ;
for ( V_77 = 0 ; V_77 < V_78 ; V_77 ++ )
if ( 0 == memcmp ( V_76 , V_79 + ( 8 * V_77 ) , 8 ) )
return 0 ;
return 1 ;
}
static int F_45 ( struct V_74 * V_38 ,
T_4 V_76 [ 8 ] , T_4 V_80 [ 16 ] )
{
struct V_1 * V_24 ;
T_4 V_81 [ 16 ] ;
T_4 V_82 [ 9 ] ;
int V_77 , V_30 ;
V_24 = NULL ;
for ( V_77 = 0 ; V_77 < V_4 ; V_77 ++ )
if ( V_5 [ V_77 ] &&
( 0 == memcmp ( V_5 [ V_77 ] -> V_83 , V_80 , 8 ) ) ) {
V_24 = V_5 [ V_77 ] ;
break;
}
if ( ! V_24 )
return - V_51 ;
F_46 ( & V_84 ) ;
V_30 = F_44 ( V_76 ) ;
F_47 ( & V_84 ) ;
if ( V_30 ) {
F_39 ( V_38 , V_80 ) ;
F_40 ( V_38 ) ;
memcpy ( V_82 , V_76 , 8 ) ;
V_82 [ 8 ] = 0 ;
F_48 ( L_1
L_2 , V_82 ) ;
return 0 ;
}
F_19 ( & V_24 -> V_52 ) ;
if ( V_24 -> V_31 != V_32 ) {
F_39 ( V_38 , V_80 ) ;
F_40 ( V_38 ) ;
goto V_85;
}
memcpy ( V_81 , V_80 + 8 , 8 ) ;
memcpy ( V_81 + 8 , V_80 , 8 ) ;
V_38 -> V_86 = 0xffff ;
V_38 -> V_8 &= ~ V_87 ;
V_30 = F_49 ( V_38 , & V_88 , V_81 , V_24 ) ;
if ( V_30 ) {
F_39 ( V_38 , V_80 ) ;
F_40 ( V_38 ) ;
goto V_85;
}
V_24 -> V_38 = V_38 ;
V_24 -> V_31 = V_57 ;
F_23 ( & V_24 -> V_58 , 5 ) ;
V_85:
F_20 ( & V_24 -> V_52 ) ;
return 0 ;
}
static void F_50 ( struct V_74 * V_38 , T_4 V_80 [ 16 ] )
{
struct V_1 * V_24 = V_38 -> V_89 ;
F_38 ( V_24 ) ;
}
static void F_51 ( struct V_74 * V_38 ,
struct V_90 * V_11 )
{
struct V_1 * V_24 = V_38 -> V_89 ;
struct V_6 * V_28 ;
if ( V_11 -> V_12 > F_4 ( V_91 ) ) {
F_52 ( V_38 , V_11 ) ;
return;
}
F_19 ( & V_24 -> V_52 ) ;
if ( V_24 -> V_68 == V_70 ) {
F_52 ( V_38 , V_11 ) ;
goto V_92;
}
V_28 = F_2 ( 0 , V_36 ) ;
if ( ! V_28 ) {
F_52 ( V_38 , V_11 ) ;
goto V_92;
}
V_28 -> V_11 = * V_11 ;
F_25 ( & V_28 -> V_21 , & V_24 -> V_35 ) ;
F_21 () ;
V_92:
F_20 ( & V_24 -> V_52 ) ;
}
static void F_53 ( struct V_74 * V_38 ,
struct V_90 * V_11 )
{
struct V_1 * V_24 = V_38 -> V_89 ;
struct V_6 * V_22 , * V_23 ;
F_54 ( V_93 ) ;
F_19 ( & V_24 -> V_52 ) ;
F_10 (ent, next, &priv->tty_outqueue, list)
if ( V_22 -> V_11 . V_67 == V_11 -> V_67 ) {
F_55 ( & V_22 -> V_21 , & V_93 ) ;
break;
}
F_56 ( & V_24 -> V_72 ) ;
F_20 ( & V_24 -> V_52 ) ;
F_9 ( & V_93 ) ;
}
static int F_57 ( struct V_94 * V_95 )
{
struct V_1 * V_24 = F_58 ( V_95 ) ;
F_59 () ;
F_38 ( V_24 ) ;
F_60 () ;
return 0 ;
}
static int F_61 ( struct V_94 * V_95 )
{
F_21 () ;
return 0 ;
}
static int T_5 F_62 ( int V_67 , unsigned int V_75 )
{
struct V_1 * V_24 ;
char V_96 [ 9 ] ;
int V_30 ;
V_24 = F_63 ( sizeof( struct V_1 ) , V_97 ) ;
if ( ! V_24 )
return - V_37 ;
F_64 ( & V_24 -> V_52 ) ;
F_65 ( & V_24 -> V_61 ) ;
F_65 ( & V_24 -> V_35 ) ;
F_66 ( & V_24 -> V_58 , F_27 ) ;
F_67 ( & V_24 -> V_72 ) ;
V_24 -> V_56 = ( void * ) F_68 ( V_97 ) ;
if ( ! V_24 -> V_56 ) {
F_8 ( V_24 ) ;
return - V_37 ;
}
V_24 -> V_75 = V_75 ;
V_24 -> V_46 = F_69 ( V_3 + V_67 ,
V_3 + V_67 , & V_98 , 256 ) ;
if ( F_70 ( V_24 -> V_46 ) ) {
V_30 = F_71 ( V_24 -> V_46 ) ;
goto V_99;
}
V_24 -> V_46 -> V_100 = 1 ;
snprintf ( V_96 , 9 , L_3 , V_67 ) ;
memcpy ( V_24 -> V_83 , V_96 , 8 ) ;
F_72 ( V_24 -> V_83 , 8 ) ;
V_24 -> V_95 = F_63 ( sizeof( * V_24 -> V_95 ) , V_97 ) ;
if ( ! V_24 -> V_95 ) {
V_30 = - V_37 ;
goto V_101;
}
F_73 ( V_24 -> V_95 , L_4 , V_67 ) ;
F_74 ( V_24 -> V_95 , V_24 ) ;
V_24 -> V_95 -> V_102 = & V_103 ;
V_24 -> V_95 -> V_104 = V_105 ;
V_24 -> V_95 -> V_106 = & V_107 ;
V_24 -> V_95 -> V_108 = ( void ( * ) ( struct V_94 * ) ) F_8 ;
V_30 = F_75 ( V_24 -> V_95 ) ;
if ( V_30 ) {
F_76 ( V_24 -> V_95 ) ;
goto V_101;
}
V_5 [ V_67 ] = V_24 ;
return 0 ;
V_101:
F_77 ( V_24 -> V_46 ) ;
V_99:
F_78 ( ( unsigned long ) V_24 -> V_56 ) ;
F_8 ( V_24 ) ;
return V_30 ;
}
static void T_5 F_79 ( struct V_1 * V_24 )
{
F_77 ( V_24 -> V_46 ) ;
F_80 ( V_24 -> V_95 ) ;
F_78 ( ( unsigned long ) V_24 -> V_56 ) ;
F_8 ( V_24 ) ;
}
static const char * F_81 ( const char * V_109 , char * V_110 )
{
const char * V_111 , * V_112 ;
T_2 V_53 ;
V_111 = strchr ( V_109 , ',' ) ;
if ( V_111 ) {
V_53 = V_111 - V_109 ;
V_112 = V_111 + 1 ;
} else {
V_53 = strlen ( V_109 ) ;
V_112 = V_109 + V_53 ;
}
if ( V_53 == 0 )
return F_82 ( - V_113 ) ;
if ( V_109 [ V_53 - 1 ] == '\n' )
V_53 -- ;
if ( V_53 > 8 )
return F_82 ( - V_113 ) ;
memset ( V_110 , ' ' , 8 ) ;
while ( V_53 -- )
V_110 [ V_53 ] = toupper ( V_109 [ V_53 ] ) ;
return V_112 ;
}
static int F_83 ( const char * V_114 )
{
const char * V_112 ;
int V_115 ;
T_2 V_7 , V_26 ;
void * V_116 , * V_117 ;
V_26 = strlen ( V_114 ) ;
if ( V_26 == 0 || ( V_26 == 1 && V_114 [ 0 ] == '\n' ) ) {
V_7 = 0 ;
V_116 = NULL ;
goto V_118;
}
V_7 = 1 ;
V_112 = V_114 ;
while ( ( V_112 = strchr ( V_112 , ',' ) ) != NULL ) {
V_112 ++ ;
V_7 ++ ;
}
if ( V_7 > V_119 )
return - V_120 ;
V_116 = F_63 ( V_7 * 8 , V_97 ) ;
if ( ! V_116 )
return - V_37 ;
V_26 = V_7 ;
V_112 = V_114 ;
while ( * V_112 && V_26 ) {
V_112 = F_81 ( V_112 ,
V_116 + ( ( V_7 - V_26 ) * 8 ) ) ;
if ( F_70 ( V_112 ) ) {
V_115 = F_71 ( V_112 ) ;
F_8 ( V_116 ) ;
goto V_121;
}
V_26 -- ;
}
V_118:
F_84 ( & V_84 ) ;
V_117 = V_79 ;
V_78 = V_7 ;
V_79 = V_116 ;
F_85 ( & V_84 ) ;
F_8 ( V_117 ) ;
V_115 = 0 ;
V_121:
return V_115 ;
}
static int F_86 ( const char * V_114 , const struct V_122 * V_123 )
{
int V_30 ;
if ( ! V_124 || ! V_4 )
return - V_51 ;
if ( ! V_114 )
return - V_113 ;
V_30 = 0 ;
if ( F_87 () )
V_30 = F_83 ( V_114 ) ;
else
V_125 = V_114 ;
return V_30 ;
}
static int F_88 ( char * V_126 , const struct V_122 * V_123 )
{
int V_30 ;
T_2 V_127 , V_53 ;
void * V_128 , * V_129 ;
if ( ! V_124 || ! V_4 )
return - V_51 ;
V_30 = 0 ;
F_89 ( & V_84 ) ;
for ( V_127 = 0 ; V_127 < V_78 ; V_127 ++ ) {
V_128 = V_79 + ( 8 * V_127 ) ;
V_129 = memchr ( V_128 , ' ' , 8 ) ;
V_53 = ( V_129 ) ? V_129 - V_128 : 8 ;
memcpy ( V_126 + V_30 , V_128 , V_53 ) ;
V_30 += V_53 ;
V_126 [ V_30 ++ ] = ',' ;
}
F_90 ( & V_84 ) ;
if ( V_30 )
V_126 [ -- V_30 ] = '\0' ;
return V_30 ;
}
static int T_5 F_91 ( void )
{
int V_30 ;
unsigned int V_77 ;
if ( ! V_4 )
return - V_51 ;
if ( ! V_124 ) {
F_92 ( L_5
L_6 ) ;
V_30 = - V_51 ;
goto V_130;
}
if ( V_4 > V_131 ) {
F_93 ( L_7
L_8 , V_4 ) ;
V_30 = - V_113 ;
goto V_130;
}
V_30 = F_94 ( & V_107 ) ;
if ( V_30 )
goto V_130;
if ( V_125 ) {
V_30 = F_83 ( V_125 ) ;
switch ( V_30 ) {
case 0 :
break;
case - V_37 :
F_93 ( L_9
L_10 , 3 ) ;
goto V_130;
case - V_113 :
F_93 ( L_11
L_12 ) ;
goto V_130;
case - V_120 :
F_93 ( L_13
L_14 ) ;
goto V_130;
default:
goto V_130;
}
}
V_132 = F_95 ( V_133 ,
sizeof( struct V_6 ) ,
0 , 0 , NULL ) ;
if ( ! V_132 ) {
F_93 ( L_15 , 1 ) ;
V_30 = - V_37 ;
goto V_130;
}
V_10 = F_96 ( V_134 ,
V_132 ) ;
if ( ! V_10 ) {
F_93 ( L_15 , 2 ) ;
F_97 ( V_132 ) ;
V_30 = - V_37 ;
goto V_130;
}
V_30 = F_98 ( V_3 , V_135 , & V_98 ) ;
if ( V_30 ) {
F_93 ( L_16
L_17 ) ;
goto V_136;
}
for ( V_77 = 0 ; V_77 < V_4 ; V_77 ++ ) {
V_30 = F_62 ( V_77 , ( V_77 == V_135 ) ? 1 : 0 ) ;
if ( V_30 ) {
F_93 ( L_18
L_19 , V_30 ) ;
goto V_99;
}
}
V_30 = F_99 ( & V_88 , 0 ) ;
if ( V_30 ) {
F_93 ( L_20 ,
V_30 ) ;
goto V_99;
}
return 0 ;
V_99:
for ( V_77 = 0 ; V_77 < V_4 ; V_77 ++ )
if ( V_5 [ V_77 ] )
F_79 ( V_5 [ V_77 ] ) ;
V_136:
F_100 ( V_10 ) ;
F_97 ( V_132 ) ;
V_130:
if ( V_79 )
F_8 ( V_79 ) ;
V_4 = 0 ;
return V_30 ;
}
static int T_5 F_101 ( char * V_114 )
{
return F_102 ( V_114 , 10 , & V_4 ) ;
}
