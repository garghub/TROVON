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
const char * V_77 , * V_78 ;
T_2 V_79 , V_53 ;
if ( ! V_80 )
return 0 ;
for ( V_79 = 0 ; V_79 < V_80 ; V_79 ++ ) {
V_78 = V_81 + ( 8 * V_79 ) ;
V_77 = F_45 ( V_78 , 8 , V_82 ) ;
V_53 = ( V_77 ) ? V_77 - V_78 : 8 ;
if ( 0 == memcmp ( V_76 , V_78 , V_53 ) )
return 0 ;
}
return 1 ;
}
static int F_46 ( struct V_74 * V_38 , T_4 * V_76 ,
T_4 * V_83 )
{
struct V_1 * V_24 , * V_84 ;
T_4 V_77 [ 9 ] = L_1 ;
int V_79 , V_30 , V_85 ;
T_4 V_86 [ 16 ] ;
T_4 V_87 [ 9 ] ;
F_47 ( V_77 , sizeof( V_77 ) ) ;
V_85 = ! memcmp ( V_77 , V_83 , 8 ) ;
V_24 = NULL ;
for ( V_79 = 0 ; V_79 < V_4 ; V_79 ++ ) {
V_84 = V_5 [ V_79 ] ;
if ( ! V_84 )
continue;
if ( V_85 ) {
F_19 ( & V_84 -> V_52 ) ;
if ( V_84 -> V_31 == V_32 )
V_24 = V_84 ;
F_20 ( & V_84 -> V_52 ) ;
} else if ( ! memcmp ( V_84 -> V_88 , V_83 , 8 ) )
V_24 = V_84 ;
if ( V_24 )
break;
}
if ( ! V_24 )
return - V_51 ;
F_48 ( & V_89 ) ;
V_30 = F_44 ( V_76 ) ;
F_49 ( & V_89 ) ;
if ( V_30 ) {
F_39 ( V_38 , V_83 ) ;
F_40 ( V_38 ) ;
memcpy ( V_87 , V_76 , 8 ) ;
V_87 [ 8 ] = 0 ;
F_50 ( L_2
L_3 , V_87 ) ;
return 0 ;
}
F_19 ( & V_24 -> V_52 ) ;
if ( V_24 -> V_31 != V_32 ) {
F_39 ( V_38 , V_83 ) ;
F_40 ( V_38 ) ;
goto V_90;
}
memcpy ( V_86 , V_83 + 8 , 8 ) ;
memcpy ( V_86 + 8 , V_83 , 8 ) ;
V_38 -> V_91 = 0xffff ;
V_38 -> V_8 &= ~ V_92 ;
V_30 = F_51 ( V_38 , & V_93 , V_86 , V_24 ) ;
if ( V_30 ) {
F_39 ( V_38 , V_83 ) ;
F_40 ( V_38 ) ;
goto V_90;
}
V_24 -> V_38 = V_38 ;
V_24 -> V_31 = V_57 ;
memcpy ( V_24 -> V_94 , V_76 , 8 ) ;
memcpy ( V_24 -> V_94 + 8 , V_83 + 8 , 8 ) ;
F_23 ( & V_24 -> V_58 , 5 ) ;
V_90:
F_20 ( & V_24 -> V_52 ) ;
return 0 ;
}
static void F_52 ( struct V_74 * V_38 , T_4 * V_83 )
{
struct V_1 * V_24 = V_38 -> V_95 ;
F_38 ( V_24 ) ;
}
static void F_53 ( struct V_74 * V_38 ,
struct V_96 * V_11 )
{
struct V_1 * V_24 = V_38 -> V_95 ;
struct V_6 * V_28 ;
if ( V_11 -> V_12 > F_4 ( V_97 ) ) {
F_54 ( V_38 , V_11 ) ;
return;
}
F_19 ( & V_24 -> V_52 ) ;
if ( V_24 -> V_68 == V_70 ) {
F_54 ( V_38 , V_11 ) ;
goto V_98;
}
V_28 = F_2 ( 0 , V_36 ) ;
if ( ! V_28 ) {
F_54 ( V_38 , V_11 ) ;
goto V_98;
}
V_28 -> V_11 = * V_11 ;
F_25 ( & V_28 -> V_21 , & V_24 -> V_35 ) ;
F_21 () ;
V_98:
F_20 ( & V_24 -> V_52 ) ;
}
static void F_55 ( struct V_74 * V_38 ,
struct V_96 * V_11 )
{
struct V_1 * V_24 = V_38 -> V_95 ;
struct V_6 * V_22 , * V_23 ;
F_56 ( V_99 ) ;
F_19 ( & V_24 -> V_52 ) ;
F_10 (ent, next, &priv->tty_outqueue, list)
if ( V_22 -> V_11 . V_67 == V_11 -> V_67 ) {
F_57 ( & V_22 -> V_21 , & V_99 ) ;
break;
}
F_58 ( & V_24 -> V_72 ) ;
F_20 ( & V_24 -> V_52 ) ;
F_9 ( & V_99 ) ;
}
static int F_59 ( struct V_100 * V_101 )
{
struct V_1 * V_24 = F_60 ( V_101 ) ;
F_61 () ;
F_38 ( V_24 ) ;
F_62 () ;
return 0 ;
}
static int F_63 ( struct V_100 * V_101 )
{
F_21 () ;
return 0 ;
}
static T_5 F_64 ( struct V_100 * V_101 ,
struct V_102 * V_103 ,
char * V_25 )
{
struct V_1 * V_24 = F_60 ( V_101 ) ;
T_2 V_53 ;
V_53 = sizeof( V_24 -> V_88 ) ;
memcpy ( V_25 , V_24 -> V_88 , V_53 ) ;
F_65 ( V_25 , V_53 ) ;
V_25 [ V_53 ++ ] = '\n' ;
return V_53 ;
}
static T_5 F_66 ( struct V_100 * V_101 ,
struct V_102 * V_103 ,
char * V_25 )
{
struct V_1 * V_24 = F_60 ( V_101 ) ;
return sprintf ( V_25 , L_4 , V_24 -> V_31 , V_24 -> V_68 ) ;
}
static T_5 F_67 ( struct V_100 * V_101 ,
struct V_102 * V_103 ,
char * V_25 )
{
struct V_1 * V_24 = F_60 ( V_101 ) ;
char V_104 [ 9 ] , V_83 [ 9 ] ;
memset ( V_104 , 0 , sizeof( V_104 ) ) ;
memset ( V_83 , 0 , sizeof( V_83 ) ) ;
F_29 ( & V_24 -> V_52 ) ;
if ( V_24 -> V_31 == V_57 ) {
memcpy ( V_104 , V_24 -> V_94 , 8 ) ;
memcpy ( V_83 , V_24 -> V_94 + 8 , 8 ) ;
}
F_30 ( & V_24 -> V_52 ) ;
F_65 ( V_83 , 8 ) ;
return sprintf ( V_25 , L_5 , V_104 , V_83 ) ;
}
static int T_6 F_68 ( int V_67 , unsigned int V_75 )
{
struct V_1 * V_24 ;
char V_105 [ 9 ] ;
int V_30 ;
V_24 = F_69 ( sizeof( struct V_1 ) , V_106 ) ;
if ( ! V_24 )
return - V_37 ;
F_70 ( & V_24 -> V_52 ) ;
F_71 ( & V_24 -> V_61 ) ;
F_71 ( & V_24 -> V_35 ) ;
F_72 ( & V_24 -> V_58 , F_27 ) ;
F_73 ( & V_24 -> V_72 ) ;
V_24 -> V_56 = ( void * ) F_74 ( V_106 ) ;
if ( ! V_24 -> V_56 ) {
F_8 ( V_24 ) ;
return - V_37 ;
}
V_24 -> V_75 = V_75 ;
V_24 -> V_46 = F_75 ( V_3 + V_67 ,
V_3 + V_67 , & V_107 , 256 ) ;
if ( F_76 ( V_24 -> V_46 ) ) {
V_30 = F_77 ( V_24 -> V_46 ) ;
goto V_108;
}
V_24 -> V_46 -> V_109 = 1 ;
snprintf ( V_105 , 9 , L_6 , V_67 ) ;
memcpy ( V_24 -> V_88 , V_105 , 8 ) ;
F_47 ( V_24 -> V_88 , 8 ) ;
V_24 -> V_101 = F_69 ( sizeof( * V_24 -> V_101 ) , V_106 ) ;
if ( ! V_24 -> V_101 ) {
V_30 = - V_37 ;
goto V_110;
}
F_78 ( V_24 -> V_101 , L_7 , V_67 ) ;
F_79 ( V_24 -> V_101 , V_24 ) ;
V_24 -> V_101 -> V_111 = & V_112 ;
V_24 -> V_101 -> V_113 = V_114 ;
V_24 -> V_101 -> V_115 = & V_116 ;
V_24 -> V_101 -> V_117 = V_118 ;
V_24 -> V_101 -> V_119 = ( void ( * ) ( struct V_100 * ) ) F_8 ;
V_30 = F_80 ( V_24 -> V_101 ) ;
if ( V_30 ) {
F_81 ( V_24 -> V_101 ) ;
goto V_110;
}
V_5 [ V_67 ] = V_24 ;
return 0 ;
V_110:
F_82 ( V_24 -> V_46 ) ;
V_108:
F_83 ( ( unsigned long ) V_24 -> V_56 ) ;
F_8 ( V_24 ) ;
return V_30 ;
}
static void T_6 F_84 ( struct V_1 * V_24 )
{
F_82 ( V_24 -> V_46 ) ;
F_85 ( V_24 -> V_101 ) ;
F_83 ( ( unsigned long ) V_24 -> V_56 ) ;
F_8 ( V_24 ) ;
}
static const char * F_86 ( const char * V_120 , char * V_121 )
{
const char * V_122 , * V_123 ;
T_2 V_53 ;
V_122 = strchr ( V_120 , ',' ) ;
if ( V_122 ) {
V_53 = V_122 - V_120 ;
V_123 = V_122 + 1 ;
} else {
V_53 = strlen ( V_120 ) ;
V_123 = V_120 + V_53 ;
}
if ( V_53 == 0 )
return F_87 ( - V_124 ) ;
if ( V_120 [ V_53 - 1 ] == '\n' )
V_53 -- ;
if ( V_53 == 1 && * V_120 == V_82 )
return F_87 ( - V_124 ) ;
if ( V_53 > 8 )
return F_87 ( - V_124 ) ;
memset ( V_121 , ' ' , 8 ) ;
while ( V_53 -- )
V_121 [ V_53 ] = toupper ( V_120 [ V_53 ] ) ;
return V_123 ;
}
static int F_88 ( const char * V_125 )
{
const char * V_123 ;
int V_126 ;
T_2 V_7 , V_26 ;
void * V_127 , * V_128 ;
V_26 = strlen ( V_125 ) ;
if ( V_26 == 0 || ( V_26 == 1 && V_125 [ 0 ] == '\n' ) ) {
V_7 = 0 ;
V_127 = NULL ;
goto V_129;
}
V_7 = 1 ;
V_123 = V_125 ;
while ( ( V_123 = strchr ( V_123 , ',' ) ) != NULL ) {
V_123 ++ ;
V_7 ++ ;
}
if ( V_7 > V_130 )
return - V_131 ;
V_127 = F_69 ( V_7 * 8 , V_106 ) ;
if ( ! V_127 )
return - V_37 ;
V_26 = V_7 ;
V_123 = V_125 ;
while ( * V_123 && V_26 ) {
V_123 = F_86 ( V_123 ,
V_127 + ( ( V_7 - V_26 ) * 8 ) ) ;
if ( F_76 ( V_123 ) ) {
V_126 = F_77 ( V_123 ) ;
F_8 ( V_127 ) ;
goto V_132;
}
V_26 -- ;
}
V_129:
F_89 ( & V_89 ) ;
V_128 = V_81 ;
V_80 = V_7 ;
V_81 = V_127 ;
F_90 ( & V_89 ) ;
F_8 ( V_128 ) ;
V_126 = 0 ;
V_132:
return V_126 ;
}
static int F_91 ( const char * V_125 , const struct V_133 * V_134 )
{
int V_30 ;
if ( ! V_135 || ! V_4 )
return - V_51 ;
if ( ! V_125 )
return - V_124 ;
V_30 = 0 ;
if ( F_92 () )
V_30 = F_88 ( V_125 ) ;
else
V_136 = V_125 ;
return V_30 ;
}
static int F_93 ( char * V_137 , const struct V_133 * V_134 )
{
int V_30 ;
T_2 V_138 , V_53 ;
void * V_139 , * V_140 ;
if ( ! V_135 || ! V_4 )
return - V_51 ;
V_30 = 0 ;
F_94 ( & V_89 ) ;
for ( V_138 = 0 ; V_138 < V_80 ; V_138 ++ ) {
V_139 = V_81 + ( 8 * V_138 ) ;
V_140 = memchr ( V_139 , ' ' , 8 ) ;
V_53 = ( V_140 ) ? V_140 - V_139 : 8 ;
memcpy ( V_137 + V_30 , V_139 , V_53 ) ;
V_30 += V_53 ;
V_137 [ V_30 ++ ] = ',' ;
}
F_95 ( & V_89 ) ;
if ( V_30 )
V_137 [ -- V_30 ] = '\0' ;
return V_30 ;
}
static int T_6 F_96 ( void )
{
int V_30 ;
unsigned int V_79 ;
if ( ! V_4 )
return - V_51 ;
if ( ! V_135 ) {
F_97 ( L_8
L_9 ) ;
V_30 = - V_51 ;
goto V_141;
}
if ( V_4 > V_142 ) {
F_98 ( L_10
L_11 , V_4 ) ;
V_30 = - V_124 ;
goto V_141;
}
V_30 = F_99 ( & V_116 ) ;
if ( V_30 )
goto V_141;
if ( V_136 ) {
V_30 = F_88 ( V_136 ) ;
switch ( V_30 ) {
case 0 :
break;
case - V_37 :
F_98 ( L_12
L_13 , 3 ) ;
goto V_141;
case - V_124 :
F_98 ( L_14
L_15 ) ;
goto V_141;
case - V_131 :
F_98 ( L_16
L_17 ) ;
goto V_141;
default:
goto V_141;
}
}
V_143 = F_100 ( V_144 ,
sizeof( struct V_6 ) ,
0 , 0 , NULL ) ;
if ( ! V_143 ) {
F_98 ( L_18 , 1 ) ;
V_30 = - V_37 ;
goto V_141;
}
V_10 = F_101 ( V_145 ,
V_143 ) ;
if ( ! V_10 ) {
F_98 ( L_18 , 2 ) ;
F_102 ( V_143 ) ;
V_30 = - V_37 ;
goto V_141;
}
V_30 = F_103 ( V_3 , V_146 , & V_107 ) ;
if ( V_30 ) {
F_98 ( L_19
L_20 ) ;
goto V_147;
}
for ( V_79 = 0 ; V_79 < V_4 ; V_79 ++ ) {
V_30 = F_68 ( V_79 , ( V_79 == V_146 ) ? 1 : 0 ) ;
if ( V_30 ) {
F_98 ( L_21
L_22 , V_30 ) ;
goto V_108;
}
}
V_30 = F_104 ( & V_93 , 0 ) ;
if ( V_30 ) {
F_98 ( L_23 ,
V_30 ) ;
goto V_108;
}
return 0 ;
V_108:
for ( V_79 = 0 ; V_79 < V_4 ; V_79 ++ )
if ( V_5 [ V_79 ] )
F_84 ( V_5 [ V_79 ] ) ;
V_147:
F_105 ( V_10 ) ;
F_102 ( V_143 ) ;
V_141:
F_8 ( V_81 ) ;
V_4 = 0 ;
return V_30 ;
}
static int T_6 F_106 ( char * V_125 )
{
return F_107 ( V_125 , 10 , & V_4 ) ;
}
