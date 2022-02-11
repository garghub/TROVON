static struct V_1 * F_1 ( T_1 V_2 )
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
struct V_1 * V_24 , * V_81 ;
T_4 V_82 [ 9 ] = L_1 ;
int V_77 , V_30 , V_83 ;
T_4 V_84 [ 16 ] ;
T_4 V_85 [ 9 ] ;
F_46 ( V_82 , sizeof( V_82 ) ) ;
V_83 = ! memcmp ( V_82 , V_80 , 8 ) ;
V_24 = NULL ;
for ( V_77 = 0 ; V_77 < V_4 ; V_77 ++ ) {
V_81 = V_5 [ V_77 ] ;
if ( ! V_81 )
continue;
if ( V_83 ) {
F_19 ( & V_81 -> V_52 ) ;
if ( V_81 -> V_31 == V_32 )
V_24 = V_81 ;
F_20 ( & V_81 -> V_52 ) ;
} else if ( ! memcmp ( V_81 -> V_86 , V_80 , 8 ) )
V_24 = V_81 ;
if ( V_24 )
break;
}
if ( ! V_24 )
return - V_51 ;
F_47 ( & V_87 ) ;
V_30 = F_44 ( V_76 ) ;
F_48 ( & V_87 ) ;
if ( V_30 ) {
F_39 ( V_38 , V_80 ) ;
F_40 ( V_38 ) ;
memcpy ( V_85 , V_76 , 8 ) ;
V_85 [ 8 ] = 0 ;
F_49 ( L_2
L_3 , V_85 ) ;
return 0 ;
}
F_19 ( & V_24 -> V_52 ) ;
if ( V_24 -> V_31 != V_32 ) {
F_39 ( V_38 , V_80 ) ;
F_40 ( V_38 ) ;
goto V_88;
}
memcpy ( V_84 , V_80 + 8 , 8 ) ;
memcpy ( V_84 + 8 , V_80 , 8 ) ;
V_38 -> V_89 = 0xffff ;
V_38 -> V_8 &= ~ V_90 ;
V_30 = F_50 ( V_38 , & V_91 , V_84 , V_24 ) ;
if ( V_30 ) {
F_39 ( V_38 , V_80 ) ;
F_40 ( V_38 ) ;
goto V_88;
}
V_24 -> V_38 = V_38 ;
V_24 -> V_31 = V_57 ;
memcpy ( V_24 -> V_92 , V_76 , 8 ) ;
memcpy ( V_24 -> V_92 + 8 , V_80 + 8 , 8 ) ;
F_23 ( & V_24 -> V_58 , 5 ) ;
V_88:
F_20 ( & V_24 -> V_52 ) ;
return 0 ;
}
static void F_51 ( struct V_74 * V_38 , T_4 V_80 [ 16 ] )
{
struct V_1 * V_24 = V_38 -> V_93 ;
F_38 ( V_24 ) ;
}
static void F_52 ( struct V_74 * V_38 ,
struct V_94 * V_11 )
{
struct V_1 * V_24 = V_38 -> V_93 ;
struct V_6 * V_28 ;
if ( V_11 -> V_12 > F_4 ( V_95 ) ) {
F_53 ( V_38 , V_11 ) ;
return;
}
F_19 ( & V_24 -> V_52 ) ;
if ( V_24 -> V_68 == V_70 ) {
F_53 ( V_38 , V_11 ) ;
goto V_96;
}
V_28 = F_2 ( 0 , V_36 ) ;
if ( ! V_28 ) {
F_53 ( V_38 , V_11 ) ;
goto V_96;
}
V_28 -> V_11 = * V_11 ;
F_25 ( & V_28 -> V_21 , & V_24 -> V_35 ) ;
F_21 () ;
V_96:
F_20 ( & V_24 -> V_52 ) ;
}
static void F_54 ( struct V_74 * V_38 ,
struct V_94 * V_11 )
{
struct V_1 * V_24 = V_38 -> V_93 ;
struct V_6 * V_22 , * V_23 ;
F_55 ( V_97 ) ;
F_19 ( & V_24 -> V_52 ) ;
F_10 (ent, next, &priv->tty_outqueue, list)
if ( V_22 -> V_11 . V_67 == V_11 -> V_67 ) {
F_56 ( & V_22 -> V_21 , & V_97 ) ;
break;
}
F_57 ( & V_24 -> V_72 ) ;
F_20 ( & V_24 -> V_52 ) ;
F_9 ( & V_97 ) ;
}
static int F_58 ( struct V_98 * V_99 )
{
struct V_1 * V_24 = F_59 ( V_99 ) ;
F_60 () ;
F_38 ( V_24 ) ;
F_61 () ;
return 0 ;
}
static int F_62 ( struct V_98 * V_99 )
{
F_21 () ;
return 0 ;
}
static T_5 F_63 ( struct V_98 * V_99 ,
struct V_100 * V_101 ,
char * V_25 )
{
struct V_1 * V_24 = F_59 ( V_99 ) ;
T_2 V_53 ;
V_53 = sizeof( V_24 -> V_86 ) ;
memcpy ( V_25 , V_24 -> V_86 , V_53 ) ;
F_64 ( V_25 , V_53 ) ;
V_25 [ V_53 ++ ] = '\n' ;
return V_53 ;
}
static T_5 F_65 ( struct V_98 * V_99 ,
struct V_100 * V_101 ,
char * V_25 )
{
struct V_1 * V_24 = F_59 ( V_99 ) ;
return sprintf ( V_25 , L_4 , V_24 -> V_31 , V_24 -> V_68 ) ;
}
static T_5 F_66 ( struct V_98 * V_99 ,
struct V_100 * V_101 ,
char * V_25 )
{
struct V_1 * V_24 = F_59 ( V_99 ) ;
char V_102 [ 9 ] , V_80 [ 9 ] ;
memset ( V_102 , 0 , sizeof( V_102 ) ) ;
memset ( V_80 , 0 , sizeof( V_80 ) ) ;
F_29 ( & V_24 -> V_52 ) ;
if ( V_24 -> V_31 == V_57 ) {
memcpy ( V_102 , V_24 -> V_92 , 8 ) ;
memcpy ( V_80 , V_24 -> V_92 + 8 , 8 ) ;
}
F_30 ( & V_24 -> V_52 ) ;
F_64 ( V_80 , 8 ) ;
return sprintf ( V_25 , L_5 , V_102 , V_80 ) ;
}
static int T_6 F_67 ( int V_67 , unsigned int V_75 )
{
struct V_1 * V_24 ;
char V_103 [ 9 ] ;
int V_30 ;
V_24 = F_68 ( sizeof( struct V_1 ) , V_104 ) ;
if ( ! V_24 )
return - V_37 ;
F_69 ( & V_24 -> V_52 ) ;
F_70 ( & V_24 -> V_61 ) ;
F_70 ( & V_24 -> V_35 ) ;
F_71 ( & V_24 -> V_58 , F_27 ) ;
F_72 ( & V_24 -> V_72 ) ;
V_24 -> V_56 = ( void * ) F_73 ( V_104 ) ;
if ( ! V_24 -> V_56 ) {
F_8 ( V_24 ) ;
return - V_37 ;
}
V_24 -> V_75 = V_75 ;
V_24 -> V_46 = F_74 ( V_3 + V_67 ,
V_3 + V_67 , & V_105 , 256 ) ;
if ( F_75 ( V_24 -> V_46 ) ) {
V_30 = F_76 ( V_24 -> V_46 ) ;
goto V_106;
}
V_24 -> V_46 -> V_107 = 1 ;
snprintf ( V_103 , 9 , L_6 , V_67 ) ;
memcpy ( V_24 -> V_86 , V_103 , 8 ) ;
F_46 ( V_24 -> V_86 , 8 ) ;
V_24 -> V_99 = F_68 ( sizeof( * V_24 -> V_99 ) , V_104 ) ;
if ( ! V_24 -> V_99 ) {
V_30 = - V_37 ;
goto V_108;
}
F_77 ( V_24 -> V_99 , L_7 , V_67 ) ;
F_78 ( V_24 -> V_99 , V_24 ) ;
V_24 -> V_99 -> V_109 = & V_110 ;
V_24 -> V_99 -> V_111 = V_112 ;
V_24 -> V_99 -> V_113 = & V_114 ;
V_24 -> V_99 -> V_115 = V_116 ;
V_24 -> V_99 -> V_117 = ( void ( * ) ( struct V_98 * ) ) F_8 ;
V_30 = F_79 ( V_24 -> V_99 ) ;
if ( V_30 ) {
F_80 ( V_24 -> V_99 ) ;
goto V_108;
}
V_5 [ V_67 ] = V_24 ;
return 0 ;
V_108:
F_81 ( V_24 -> V_46 ) ;
V_106:
F_82 ( ( unsigned long ) V_24 -> V_56 ) ;
F_8 ( V_24 ) ;
return V_30 ;
}
static void T_6 F_83 ( struct V_1 * V_24 )
{
F_81 ( V_24 -> V_46 ) ;
F_84 ( V_24 -> V_99 ) ;
F_82 ( ( unsigned long ) V_24 -> V_56 ) ;
F_8 ( V_24 ) ;
}
static const char * F_85 ( const char * V_118 , char * V_119 )
{
const char * V_120 , * V_121 ;
T_2 V_53 ;
V_120 = strchr ( V_118 , ',' ) ;
if ( V_120 ) {
V_53 = V_120 - V_118 ;
V_121 = V_120 + 1 ;
} else {
V_53 = strlen ( V_118 ) ;
V_121 = V_118 + V_53 ;
}
if ( V_53 == 0 )
return F_86 ( - V_122 ) ;
if ( V_118 [ V_53 - 1 ] == '\n' )
V_53 -- ;
if ( V_53 > 8 )
return F_86 ( - V_122 ) ;
memset ( V_119 , ' ' , 8 ) ;
while ( V_53 -- )
V_119 [ V_53 ] = toupper ( V_118 [ V_53 ] ) ;
return V_121 ;
}
static int F_87 ( const char * V_123 )
{
const char * V_121 ;
int V_124 ;
T_2 V_7 , V_26 ;
void * V_125 , * V_126 ;
V_26 = strlen ( V_123 ) ;
if ( V_26 == 0 || ( V_26 == 1 && V_123 [ 0 ] == '\n' ) ) {
V_7 = 0 ;
V_125 = NULL ;
goto V_127;
}
V_7 = 1 ;
V_121 = V_123 ;
while ( ( V_121 = strchr ( V_121 , ',' ) ) != NULL ) {
V_121 ++ ;
V_7 ++ ;
}
if ( V_7 > V_128 )
return - V_129 ;
V_125 = F_68 ( V_7 * 8 , V_104 ) ;
if ( ! V_125 )
return - V_37 ;
V_26 = V_7 ;
V_121 = V_123 ;
while ( * V_121 && V_26 ) {
V_121 = F_85 ( V_121 ,
V_125 + ( ( V_7 - V_26 ) * 8 ) ) ;
if ( F_75 ( V_121 ) ) {
V_124 = F_76 ( V_121 ) ;
F_8 ( V_125 ) ;
goto V_130;
}
V_26 -- ;
}
V_127:
F_88 ( & V_87 ) ;
V_126 = V_79 ;
V_78 = V_7 ;
V_79 = V_125 ;
F_89 ( & V_87 ) ;
F_8 ( V_126 ) ;
V_124 = 0 ;
V_130:
return V_124 ;
}
static int F_90 ( const char * V_123 , const struct V_131 * V_132 )
{
int V_30 ;
if ( ! V_133 || ! V_4 )
return - V_51 ;
if ( ! V_123 )
return - V_122 ;
V_30 = 0 ;
if ( F_91 () )
V_30 = F_87 ( V_123 ) ;
else
V_134 = V_123 ;
return V_30 ;
}
static int F_92 ( char * V_135 , const struct V_131 * V_132 )
{
int V_30 ;
T_2 V_136 , V_53 ;
void * V_137 , * V_138 ;
if ( ! V_133 || ! V_4 )
return - V_51 ;
V_30 = 0 ;
F_93 ( & V_87 ) ;
for ( V_136 = 0 ; V_136 < V_78 ; V_136 ++ ) {
V_137 = V_79 + ( 8 * V_136 ) ;
V_138 = memchr ( V_137 , ' ' , 8 ) ;
V_53 = ( V_138 ) ? V_138 - V_137 : 8 ;
memcpy ( V_135 + V_30 , V_137 , V_53 ) ;
V_30 += V_53 ;
V_135 [ V_30 ++ ] = ',' ;
}
F_94 ( & V_87 ) ;
if ( V_30 )
V_135 [ -- V_30 ] = '\0' ;
return V_30 ;
}
static int T_6 F_95 ( void )
{
int V_30 ;
unsigned int V_77 ;
if ( ! V_4 )
return - V_51 ;
if ( ! V_133 ) {
F_96 ( L_8
L_9 ) ;
V_30 = - V_51 ;
goto V_139;
}
if ( V_4 > V_140 ) {
F_97 ( L_10
L_11 , V_4 ) ;
V_30 = - V_122 ;
goto V_139;
}
V_30 = F_98 ( & V_114 ) ;
if ( V_30 )
goto V_139;
if ( V_134 ) {
V_30 = F_87 ( V_134 ) ;
switch ( V_30 ) {
case 0 :
break;
case - V_37 :
F_97 ( L_12
L_13 , 3 ) ;
goto V_139;
case - V_122 :
F_97 ( L_14
L_15 ) ;
goto V_139;
case - V_129 :
F_97 ( L_16
L_17 ) ;
goto V_139;
default:
goto V_139;
}
}
V_141 = F_99 ( V_142 ,
sizeof( struct V_6 ) ,
0 , 0 , NULL ) ;
if ( ! V_141 ) {
F_97 ( L_18 , 1 ) ;
V_30 = - V_37 ;
goto V_139;
}
V_10 = F_100 ( V_143 ,
V_141 ) ;
if ( ! V_10 ) {
F_97 ( L_18 , 2 ) ;
F_101 ( V_141 ) ;
V_30 = - V_37 ;
goto V_139;
}
V_30 = F_102 ( V_3 , V_144 , & V_105 ) ;
if ( V_30 ) {
F_97 ( L_19
L_20 ) ;
goto V_145;
}
for ( V_77 = 0 ; V_77 < V_4 ; V_77 ++ ) {
V_30 = F_67 ( V_77 , ( V_77 == V_144 ) ? 1 : 0 ) ;
if ( V_30 ) {
F_97 ( L_21
L_22 , V_30 ) ;
goto V_106;
}
}
V_30 = F_103 ( & V_91 , 0 ) ;
if ( V_30 ) {
F_97 ( L_23 ,
V_30 ) ;
goto V_106;
}
return 0 ;
V_106:
for ( V_77 = 0 ; V_77 < V_4 ; V_77 ++ )
if ( V_5 [ V_77 ] )
F_83 ( V_5 [ V_77 ] ) ;
V_145:
F_104 ( V_10 ) ;
F_101 ( V_141 ) ;
V_139:
F_8 ( V_79 ) ;
V_4 = 0 ;
return V_30 ;
}
static int T_6 F_105 ( char * V_123 )
{
return F_106 ( V_123 , 10 , & V_4 ) ;
}
