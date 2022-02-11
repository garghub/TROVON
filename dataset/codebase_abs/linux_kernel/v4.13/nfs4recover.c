static int
F_1 ( const struct V_1 * * V_2 )
{
struct V_1 * V_3 ;
V_3 = F_2 () ;
if ( ! V_3 )
return - V_4 ;
V_3 -> V_5 = V_6 ;
V_3 -> V_7 = V_8 ;
* V_2 = F_3 ( V_3 ) ;
F_4 ( V_3 ) ;
return 0 ;
}
static void
F_5 ( const struct V_1 * V_9 )
{
F_6 ( V_9 ) ;
}
static void
F_7 ( char * V_10 , char * V_11 )
{
int V_12 ;
for ( V_12 = 0 ; V_12 < 16 ; V_12 ++ ) {
unsigned char V_13 = V_11 [ V_12 ] ;
* V_10 ++ = '0' + ( ( V_13 & 0xf0 ) >> 4 ) + ( V_13 >= 0xa0 ) * ( 'a' - '9' - 1 ) ;
* V_10 ++ = '0' + ( V_13 & 0x0f ) + ( ( V_13 & 0x0f ) >= 0x0a ) * ( 'a' - '9' - 1 ) ;
}
* V_10 = '\0' ;
}
static int
F_8 ( char * V_14 , const struct V_15 * V_16 )
{
struct V_15 V_17 ;
struct V_18 * V_19 ;
int V_20 ;
F_9 ( L_1 ,
V_16 -> V_21 , V_16 -> V_22 ) ;
V_19 = F_10 ( L_2 , 0 , 0 ) ;
if ( F_11 ( V_19 ) ) {
V_20 = F_12 ( V_19 ) ;
goto V_23;
}
V_17 . V_21 = F_13 ( V_19 ) ;
V_17 . V_22 = F_14 ( V_17 . V_21 , V_24 ) ;
if ( V_17 . V_22 == NULL ) {
V_20 = - V_4 ;
goto V_10;
}
{
F_15 ( V_25 , V_19 ) ;
V_25 -> V_19 = V_19 ;
V_25 -> V_26 = V_27 ;
V_20 = F_16 ( V_25 , V_16 -> V_22 , V_16 -> V_21 ,
V_17 . V_22 ) ;
F_17 ( V_25 ) ;
}
if ( V_20 )
goto V_10;
F_7 ( V_14 , V_17 . V_22 ) ;
V_20 = 0 ;
V_10:
F_18 ( V_17 . V_22 ) ;
F_19 ( V_19 ) ;
V_23:
return V_20 ;
}
static void
F_20 ( struct V_28 * V_29 , int error )
{
F_21 ( V_30 L_3
L_4 , error ) ;
if ( error == - V_31 ) {
F_21 ( V_30 L_5
L_6 ) ;
F_22 ( V_29 -> V_32 ) ;
}
}
static void
F_23 ( struct V_28 * V_29 )
{
const struct V_1 * V_33 ;
char V_14 [ V_34 ] ;
struct V_35 * V_36 , * V_35 ;
struct V_37 * V_38 ;
int V_20 ;
struct V_39 * V_40 = F_24 ( V_29 -> V_32 , V_41 ) ;
if ( F_25 ( V_42 , & V_29 -> V_43 ) )
return;
if ( ! V_40 -> V_44 )
return;
V_20 = F_8 ( V_14 , & V_29 -> V_45 ) ;
if ( V_20 )
return F_20 ( V_29 , V_20 ) ;
V_20 = F_1 ( & V_33 ) ;
if ( V_20 < 0 )
return;
V_20 = F_26 ( V_40 -> V_44 ) ;
if ( V_20 )
goto V_46;
V_36 = V_40 -> V_44 -> V_47 . V_35 ;
F_27 ( F_28 ( V_36 ) ) ;
V_35 = F_29 ( V_14 , V_36 , V_34 - 1 ) ;
if ( F_11 ( V_35 ) ) {
V_20 = F_12 ( V_35 ) ;
goto V_48;
}
if ( F_30 ( V_35 ) )
goto V_49;
V_20 = F_31 ( F_28 ( V_36 ) , V_35 , V_50 ) ;
V_49:
F_32 ( V_35 ) ;
V_48:
F_33 ( F_28 ( V_36 ) ) ;
if ( V_20 == 0 ) {
if ( V_40 -> V_51 ) {
V_38 = F_34 ( V_14 , V_40 ) ;
if ( V_38 )
V_38 -> V_52 = V_29 ;
}
F_35 ( V_40 -> V_44 , 0 ) ;
} else {
F_21 ( V_30 L_7
L_8
L_9 , V_20 ,
V_53 ) ;
}
F_36 ( V_40 -> V_44 ) ;
V_46:
F_5 ( V_33 ) ;
}
static int
F_37 ( struct V_54 * V_55 , const char * V_56 , int V_57 ,
T_1 V_58 , T_2 V_59 , unsigned int V_60 )
{
struct V_61 * V_62 =
F_38 ( V_55 , struct V_61 , V_62 ) ;
struct V_63 * V_64 ;
if ( V_57 != V_34 - 1 )
return 0 ;
V_64 = F_14 ( sizeof( struct V_63 ) , V_24 ) ;
if ( V_64 == NULL )
return - V_4 ;
memcpy ( V_64 -> V_56 , V_56 , V_34 - 1 ) ;
V_64 -> V_56 [ V_34 - 1 ] = '\0' ;
F_39 ( & V_64 -> V_65 , & V_62 -> V_66 ) ;
return 0 ;
}
static int
F_40 ( T_3 * V_67 , struct V_39 * V_40 )
{
const struct V_1 * V_33 ;
struct V_35 * V_36 = V_40 -> V_44 -> V_47 . V_35 ;
struct V_61 V_62 = {
. V_62 . V_68 = F_37 ,
. V_66 = F_41 (ctx.names)
} ;
struct V_63 * V_64 , * V_69 ;
int V_20 ;
V_20 = F_1 ( & V_33 ) ;
if ( V_20 < 0 )
return V_20 ;
V_20 = F_42 ( V_40 -> V_44 , 0 , V_70 ) ;
if ( V_20 < 0 ) {
F_5 ( V_33 ) ;
return V_20 ;
}
V_20 = F_43 ( V_40 -> V_44 , & V_62 . V_62 ) ;
F_44 ( F_28 ( V_36 ) , V_71 ) ;
F_45 (entry, tmp, &ctx.names, list) {
if ( ! V_20 ) {
struct V_35 * V_35 ;
V_35 = F_29 ( V_64 -> V_56 , V_36 , V_34 - 1 ) ;
if ( F_11 ( V_35 ) ) {
V_20 = F_12 ( V_35 ) ;
break;
}
V_20 = V_67 ( V_36 , V_35 , V_40 ) ;
F_32 ( V_35 ) ;
}
F_46 ( & V_64 -> V_65 ) ;
F_18 ( V_64 ) ;
}
F_33 ( F_28 ( V_36 ) ) ;
F_5 ( V_33 ) ;
F_45 (entry, tmp, &ctx.names, list) {
F_9 ( L_10 , V_72 , V_64 -> V_56 ) ;
F_46 ( & V_64 -> V_65 ) ;
F_18 ( V_64 ) ;
}
return V_20 ;
}
static int
F_47 ( char * V_56 , int V_57 , struct V_39 * V_40 )
{
struct V_35 * V_36 , * V_35 ;
int V_20 ;
F_9 ( L_11 , V_57 , V_56 ) ;
V_36 = V_40 -> V_44 -> V_47 . V_35 ;
F_44 ( F_28 ( V_36 ) , V_71 ) ;
V_35 = F_29 ( V_56 , V_36 , V_57 ) ;
if ( F_11 ( V_35 ) ) {
V_20 = F_12 ( V_35 ) ;
goto V_48;
}
V_20 = - V_31 ;
if ( F_48 ( V_35 ) )
goto V_10;
V_20 = F_49 ( F_28 ( V_36 ) , V_35 ) ;
V_10:
F_32 ( V_35 ) ;
V_48:
F_33 ( F_28 ( V_36 ) ) ;
return V_20 ;
}
static void
F_50 ( struct V_28 * V_29 )
{
const struct V_1 * V_33 ;
struct V_37 * V_38 ;
char V_14 [ V_34 ] ;
int V_20 ;
struct V_39 * V_40 = F_24 ( V_29 -> V_32 , V_41 ) ;
if ( ! V_40 -> V_44 || ! F_51 ( V_42 , & V_29 -> V_43 ) )
return;
V_20 = F_8 ( V_14 , & V_29 -> V_45 ) ;
if ( V_20 )
return F_20 ( V_29 , V_20 ) ;
V_20 = F_26 ( V_40 -> V_44 ) ;
if ( V_20 )
goto V_10;
F_52 ( V_42 , & V_29 -> V_43 ) ;
V_20 = F_1 ( & V_33 ) ;
if ( V_20 < 0 )
goto V_73;
V_20 = F_47 ( V_14 , V_34 - 1 , V_40 ) ;
F_5 ( V_33 ) ;
if ( V_20 == 0 ) {
F_35 ( V_40 -> V_44 , 0 ) ;
if ( V_40 -> V_51 ) {
V_38 = F_53 ( V_14 , V_40 ) ;
if ( V_38 )
F_54 ( V_38 , V_40 ) ;
}
}
V_73:
F_36 ( V_40 -> V_44 ) ;
V_10:
if ( V_20 )
F_21 ( L_12
L_13 , V_34 , V_14 ) ;
}
static int
F_55 ( struct V_35 * V_74 , struct V_35 * V_75 , struct V_39 * V_40 )
{
int V_20 ;
if ( F_56 ( V_75 -> V_76 . V_56 , V_40 ) )
return 0 ;
V_20 = F_49 ( F_28 ( V_74 ) , V_75 ) ;
if ( V_20 )
F_21 ( L_14 ,
V_75 ) ;
return 0 ;
}
static void
F_57 ( struct V_39 * V_40 )
{
int V_20 ;
V_40 -> V_51 = false ;
if ( ! V_40 -> V_44 )
return;
V_20 = F_26 ( V_40 -> V_44 ) ;
if ( V_20 )
goto V_10;
V_20 = F_40 ( F_55 , V_40 ) ;
if ( V_20 == 0 )
F_35 ( V_40 -> V_44 , 0 ) ;
F_36 ( V_40 -> V_44 ) ;
V_10:
F_58 ( V_40 ) ;
if ( V_20 )
F_21 ( L_15
L_16 , V_40 -> V_44 ) ;
}
static int
F_59 ( struct V_35 * V_74 , struct V_35 * V_75 , struct V_39 * V_40 )
{
if ( V_75 -> V_76 . V_21 != V_34 - 1 ) {
F_21 ( L_17 ,
V_75 ) ;
return 0 ;
}
F_34 ( V_75 -> V_76 . V_56 , V_40 ) ;
return 0 ;
}
static int
F_60 ( struct V_32 * V_32 ) {
int V_20 ;
struct V_39 * V_40 = F_24 ( V_32 , V_41 ) ;
if ( ! V_40 -> V_44 )
return 0 ;
V_20 = F_40 ( F_59 , V_40 ) ;
if ( V_20 )
F_21 ( L_18
L_16 , V_40 -> V_44 ) ;
return V_20 ;
}
static int
F_61 ( struct V_32 * V_32 )
{
struct V_39 * V_40 = F_24 ( V_32 , V_41 ) ;
const struct V_1 * V_33 ;
int V_20 ;
F_21 ( L_19 ,
V_53 ) ;
F_62 ( V_40 -> V_44 ) ;
V_20 = F_1 ( & V_33 ) ;
if ( V_20 < 0 ) {
F_21 ( L_20
L_21 ,
V_20 ) ;
return V_20 ;
}
V_40 -> V_44 = F_63 ( V_53 , V_77 | V_78 , 0 ) ;
if ( F_11 ( V_40 -> V_44 ) ) {
F_21 ( L_22 ,
V_53 ) ;
V_20 = F_12 ( V_40 -> V_44 ) ;
V_40 -> V_44 = NULL ;
}
F_5 ( V_33 ) ;
if ( ! V_20 )
V_40 -> V_51 = true ;
return V_20 ;
}
static void
F_64 ( struct V_32 * V_32 )
{
struct V_39 * V_40 = F_24 ( V_32 , V_41 ) ;
if ( ! V_40 -> V_44 )
return;
F_65 ( V_40 -> V_44 ) ;
V_40 -> V_44 = NULL ;
}
static int
F_66 ( struct V_32 * V_32 )
{
struct V_39 * V_40 = F_24 ( V_32 , V_41 ) ;
int V_12 ;
V_40 -> V_79 = F_14 ( sizeof( struct V_80 ) *
V_81 , V_24 ) ;
if ( ! V_40 -> V_79 )
return - V_4 ;
for ( V_12 = 0 ; V_12 < V_81 ; V_12 ++ )
F_67 ( & V_40 -> V_79 [ V_12 ] ) ;
V_40 -> V_82 = 0 ;
return 0 ;
}
static void
F_68 ( struct V_32 * V_32 )
{
struct V_39 * V_40 = F_24 ( V_32 , V_41 ) ;
F_18 ( V_40 -> V_79 ) ;
}
static int
F_69 ( struct V_32 * V_32 )
{
int V_20 ;
V_20 = F_61 ( V_32 ) ;
if ( V_20 )
return V_20 ;
V_20 = F_60 ( V_32 ) ;
if ( V_20 )
F_64 ( V_32 ) ;
return V_20 ;
}
static int
F_70 ( struct V_32 * V_32 )
{
int V_20 ;
if ( V_32 != & V_83 ) {
F_71 ( L_23 ) ;
return - V_84 ;
}
V_20 = F_66 ( V_32 ) ;
if ( V_20 )
return V_20 ;
V_20 = F_69 ( V_32 ) ;
if ( V_20 )
goto V_85;
return 0 ;
V_85:
F_68 ( V_32 ) ;
return V_20 ;
}
static void
F_72 ( struct V_32 * V_32 )
{
struct V_39 * V_40 = F_24 ( V_32 , V_41 ) ;
F_58 ( V_40 ) ;
F_64 ( V_32 ) ;
F_68 ( V_32 ) ;
}
int
F_73 ( char * V_86 )
{
int V_20 ;
struct V_87 V_87 ;
V_20 = F_74 ( V_86 , V_88 , & V_87 ) ;
if ( V_20 )
return V_20 ;
V_20 = - V_89 ;
if ( F_75 ( V_87 . V_35 ) ) {
strcpy ( V_53 , V_86 ) ;
V_20 = 0 ;
}
F_76 ( & V_87 ) ;
return V_20 ;
}
char *
F_77 ( void )
{
return V_53 ;
}
static int
F_78 ( struct V_28 * V_29 )
{
int V_20 ;
char V_14 [ V_34 ] ;
struct V_37 * V_38 ;
struct V_39 * V_40 = F_24 ( V_29 -> V_32 , V_41 ) ;
if ( F_51 ( V_42 , & V_29 -> V_43 ) )
return 0 ;
V_20 = F_8 ( V_14 , & V_29 -> V_45 ) ;
if ( V_20 ) {
F_20 ( V_29 , V_20 ) ;
return V_20 ;
}
V_38 = F_53 ( V_14 , V_40 ) ;
if ( V_38 ) {
F_79 ( V_42 , & V_29 -> V_43 ) ;
V_38 -> V_52 = V_29 ;
return 0 ;
}
return - V_31 ;
}
static int
F_80 ( struct V_90 * V_91 , struct V_92 * V_93 )
{
int V_94 ;
struct V_95 V_96 ;
memset ( & V_96 , 0 , sizeof( V_96 ) ) ;
V_96 . V_22 = V_93 ;
V_96 . V_21 = sizeof( * V_93 ) ;
F_81 ( V_97 ) ;
V_94 = F_82 ( V_91 , & V_96 ) ;
if ( V_94 < 0 ) {
F_81 ( V_98 ) ;
goto V_10;
}
F_83 () ;
if ( V_96 . V_99 < 0 )
V_94 = V_96 . V_99 ;
V_10:
return V_94 ;
}
static int
F_84 ( struct V_90 * V_91 , struct V_92 * V_93 )
{
int V_94 ;
do {
V_94 = F_80 ( V_91 , V_93 ) ;
} while ( V_94 == - V_100 );
return V_94 ;
}
static T_4
F_85 ( struct V_101 * V_102 , const char T_5 * V_103 , T_6 V_104 )
{
struct V_105 * V_69 , * V_106 ;
struct V_92 T_5 * V_93 = (struct V_92 T_5 * ) V_103 ;
T_7 V_107 ;
struct V_39 * V_40 = F_24 ( F_86 ( V_102 ) -> V_108 -> V_109 ,
V_41 ) ;
struct V_110 * V_111 = V_40 -> V_110 ;
if ( V_104 != sizeof( * V_93 ) ) {
F_9 ( L_24 , V_72 , V_104 ,
sizeof( * V_93 ) ) ;
return - V_84 ;
}
if ( F_87 ( & V_107 , & V_93 -> V_112 , sizeof( V_107 ) ) != 0 ) {
F_9 ( L_25 , V_72 ) ;
return - V_113 ;
}
V_106 = NULL ;
F_88 ( & V_111 -> V_114 ) ;
F_89 (tmp, &cn->cn_list, cu_list) {
if ( F_90 ( & V_69 -> V_115 . V_112 ) == V_107 ) {
V_106 = V_69 ;
F_91 ( & V_106 -> V_116 ) ;
break;
}
}
F_92 ( & V_111 -> V_114 ) ;
if ( ! V_106 ) {
F_9 ( L_26 , V_72 , V_107 ) ;
return - V_84 ;
}
if ( F_87 ( & V_106 -> V_115 , V_103 , V_104 ) != 0 )
return - V_113 ;
F_93 ( V_106 -> V_117 ) ;
return V_104 ;
}
static void
F_94 ( struct V_95 * V_96 )
{
struct V_92 * V_93 = V_96 -> V_22 ;
struct V_105 * V_106 = F_38 ( V_93 , struct V_105 ,
V_115 ) ;
if ( V_96 -> V_99 >= 0 )
return;
F_93 ( V_106 -> V_117 ) ;
}
static struct V_35 *
F_95 ( struct V_118 * V_119 , struct V_90 * V_91 )
{
struct V_35 * V_36 , * V_35 ;
V_36 = F_96 ( V_119 , V_120 ) ;
if ( V_36 == NULL )
return F_97 ( - V_31 ) ;
V_35 = F_98 ( V_36 , V_121 , NULL , V_91 ) ;
F_32 ( V_36 ) ;
return V_35 ;
}
static void
F_99 ( struct V_90 * V_91 )
{
if ( V_91 -> V_35 )
F_100 ( V_91 -> V_35 ) ;
}
static struct V_35 *
F_101 ( struct V_32 * V_32 , struct V_90 * V_91 )
{
struct V_118 * V_119 ;
struct V_35 * V_35 ;
V_119 = F_102 ( V_32 ) ;
if ( ! V_119 )
return NULL ;
V_35 = F_95 ( V_119 , V_91 ) ;
F_103 ( V_32 ) ;
return V_35 ;
}
static void
F_104 ( struct V_32 * V_32 , struct V_90 * V_91 )
{
struct V_118 * V_119 ;
V_119 = F_102 ( V_32 ) ;
if ( V_119 ) {
F_99 ( V_91 ) ;
F_103 ( V_32 ) ;
}
}
static int
F_105 ( struct V_32 * V_32 )
{
int V_94 ;
struct V_35 * V_35 ;
struct V_39 * V_40 = F_24 ( V_32 , V_41 ) ;
struct V_110 * V_111 ;
if ( V_40 -> V_110 )
return 0 ;
V_111 = F_106 ( sizeof( * V_111 ) , V_24 ) ;
if ( ! V_111 ) {
V_94 = - V_4 ;
goto V_85;
}
V_111 -> V_122 = F_107 ( & V_123 , V_124 ) ;
if ( F_11 ( V_111 -> V_122 ) ) {
V_94 = F_12 ( V_111 -> V_122 ) ;
goto V_85;
}
F_108 ( & V_111 -> V_114 ) ;
F_67 ( & V_111 -> V_125 ) ;
V_35 = F_101 ( V_32 , V_111 -> V_122 ) ;
if ( F_11 ( V_35 ) ) {
V_94 = F_12 ( V_35 ) ;
goto V_126;
}
V_111 -> V_122 -> V_35 = V_35 ;
V_40 -> V_110 = V_111 ;
return 0 ;
V_126:
F_109 ( V_111 -> V_122 ) ;
V_85:
F_18 ( V_111 ) ;
F_21 ( V_30 L_27 ,
V_94 ) ;
return V_94 ;
}
static void
F_110 ( struct V_32 * V_32 )
{
struct V_39 * V_40 = F_24 ( V_32 , V_41 ) ;
struct V_110 * V_111 = V_40 -> V_110 ;
F_104 ( V_32 , V_111 -> V_122 ) ;
F_109 ( V_111 -> V_122 ) ;
F_18 ( V_40 -> V_110 ) ;
V_40 -> V_110 = NULL ;
}
static struct V_105 *
F_111 ( struct V_110 * V_111 )
{
struct V_105 * V_3 , * V_69 ;
V_3 = F_106 ( sizeof( * V_3 ) , V_24 ) ;
if ( ! V_3 )
return V_3 ;
V_127:
F_88 ( & V_111 -> V_114 ) ;
F_89 (tmp, &cn->cn_list, cu_list) {
if ( V_69 -> V_115 . V_112 == V_111 -> V_128 ) {
V_111 -> V_128 ++ ;
F_92 ( & V_111 -> V_114 ) ;
goto V_127;
}
}
V_3 -> V_117 = V_129 ;
V_3 -> V_115 . V_130 = V_131 ;
F_112 ( V_111 -> V_128 ++ , & V_3 -> V_115 . V_112 ) ;
V_3 -> V_132 = V_111 ;
F_39 ( & V_3 -> V_116 , & V_111 -> V_125 ) ;
F_92 ( & V_111 -> V_114 ) ;
F_9 ( L_28 , V_72 , V_3 -> V_115 . V_112 ) ;
return V_3 ;
}
static void
F_113 ( struct V_105 * V_133 )
{
struct V_110 * V_111 = V_133 -> V_132 ;
F_88 ( & V_111 -> V_114 ) ;
F_46 ( & V_133 -> V_116 ) ;
F_92 ( & V_111 -> V_114 ) ;
F_18 ( V_133 ) ;
}
static void
F_114 ( struct V_28 * V_29 )
{
int V_94 ;
struct V_105 * V_106 ;
struct V_39 * V_40 = F_24 ( V_29 -> V_32 , V_41 ) ;
struct V_110 * V_111 = V_40 -> V_110 ;
if ( F_51 ( V_42 , & V_29 -> V_43 ) )
return;
V_106 = F_111 ( V_111 ) ;
if ( ! V_106 ) {
V_94 = - V_4 ;
goto V_134;
}
V_106 -> V_115 . V_135 = V_136 ;
V_106 -> V_115 . V_137 . V_138 . V_139 = V_29 -> V_45 . V_21 ;
memcpy ( V_106 -> V_115 . V_137 . V_138 . V_140 , V_29 -> V_45 . V_22 ,
V_29 -> V_45 . V_21 ) ;
V_94 = F_84 ( V_111 -> V_122 , & V_106 -> V_115 ) ;
if ( ! V_94 ) {
V_94 = V_106 -> V_115 . V_141 ;
F_79 ( V_42 , & V_29 -> V_43 ) ;
}
F_113 ( V_106 ) ;
V_134:
if ( V_94 )
F_21 ( V_30 L_29
L_30 , V_94 ) ;
}
static void
F_115 ( struct V_28 * V_29 )
{
int V_94 ;
struct V_105 * V_106 ;
struct V_39 * V_40 = F_24 ( V_29 -> V_32 , V_41 ) ;
struct V_110 * V_111 = V_40 -> V_110 ;
if ( ! F_51 ( V_42 , & V_29 -> V_43 ) )
return;
V_106 = F_111 ( V_111 ) ;
if ( ! V_106 ) {
V_94 = - V_4 ;
goto V_134;
}
V_106 -> V_115 . V_135 = V_142 ;
V_106 -> V_115 . V_137 . V_138 . V_139 = V_29 -> V_45 . V_21 ;
memcpy ( V_106 -> V_115 . V_137 . V_138 . V_140 , V_29 -> V_45 . V_22 ,
V_29 -> V_45 . V_21 ) ;
V_94 = F_84 ( V_111 -> V_122 , & V_106 -> V_115 ) ;
if ( ! V_94 ) {
V_94 = V_106 -> V_115 . V_141 ;
F_52 ( V_42 , & V_29 -> V_43 ) ;
}
F_113 ( V_106 ) ;
V_134:
if ( V_94 )
F_21 ( V_30 L_31
L_32 , V_94 ) ;
}
static int
F_116 ( struct V_28 * V_29 )
{
int V_94 ;
struct V_105 * V_106 ;
struct V_39 * V_40 = F_24 ( V_29 -> V_32 , V_41 ) ;
struct V_110 * V_111 = V_40 -> V_110 ;
if ( F_51 ( V_42 , & V_29 -> V_43 ) )
return 0 ;
V_106 = F_111 ( V_111 ) ;
if ( ! V_106 ) {
F_21 ( V_30 L_33
L_34 , - V_4 ) ;
return - V_4 ;
}
V_106 -> V_115 . V_135 = V_143 ;
V_106 -> V_115 . V_137 . V_138 . V_139 = V_29 -> V_45 . V_21 ;
memcpy ( V_106 -> V_115 . V_137 . V_138 . V_140 , V_29 -> V_45 . V_22 ,
V_29 -> V_45 . V_21 ) ;
V_94 = F_84 ( V_111 -> V_122 , & V_106 -> V_115 ) ;
if ( ! V_94 ) {
V_94 = V_106 -> V_115 . V_141 ;
F_79 ( V_42 , & V_29 -> V_43 ) ;
}
F_113 ( V_106 ) ;
return V_94 ;
}
static void
F_117 ( struct V_39 * V_40 )
{
int V_94 ;
struct V_105 * V_106 ;
struct V_110 * V_111 = V_40 -> V_110 ;
V_106 = F_111 ( V_111 ) ;
if ( ! V_106 ) {
V_94 = - V_4 ;
goto V_134;
}
V_106 -> V_115 . V_135 = V_144 ;
V_106 -> V_115 . V_137 . V_145 = ( V_146 ) V_40 -> V_147 ;
V_94 = F_84 ( V_111 -> V_122 , & V_106 -> V_115 ) ;
if ( ! V_94 )
V_94 = V_106 -> V_115 . V_141 ;
F_113 ( V_106 ) ;
V_134:
if ( V_94 )
F_21 ( V_30 L_35 , V_94 ) ;
}
static char *
F_118 ( void )
{
int V_148 ;
T_6 V_21 ;
char * V_149 ;
if ( V_150 )
return NULL ;
V_21 = strlen ( V_151 ) +
strlen ( F_77 () ) + 1 ;
V_149 = F_14 ( V_21 , V_24 ) ;
if ( ! V_149 )
return V_149 ;
V_148 = snprintf ( V_149 , V_21 , V_151 L_36 ,
F_77 () ) ;
if ( V_148 >= V_21 ) {
F_18 ( V_149 ) ;
return NULL ;
}
return V_149 ;
}
static char *
F_119 ( const struct V_15 * V_56 )
{
int V_148 ;
T_6 V_21 ;
char * V_149 ;
if ( V_150 )
return NULL ;
V_21 = strlen ( V_152 ) +
strlen ( F_77 () ) + 1 + V_34 ;
V_149 = F_14 ( V_21 , V_24 ) ;
if ( ! V_149 )
return V_149 ;
V_148 = snprintf ( V_149 , V_21 , V_152 L_37 ,
F_77 () ) ;
if ( V_148 > ( V_21 - V_34 ) ) {
F_18 ( V_149 ) ;
return NULL ;
}
V_148 = F_8 ( V_149 + V_148 , V_56 ) ;
if ( V_148 ) {
F_18 ( V_149 ) ;
return NULL ;
}
return V_149 ;
}
static char *
F_120 ( struct V_28 * V_29 )
{
int V_148 ;
T_6 V_21 ;
char * V_149 ;
V_21 = strlen ( V_153 ) + 1 + 1 ;
V_149 = F_14 ( V_21 , V_24 ) ;
if ( ! V_149 )
return V_149 ;
V_148 = snprintf ( V_149 , V_21 , V_153 L_38 ,
V_29 -> V_154 ? 'Y' : 'N' ) ;
if ( V_148 >= V_21 ) {
F_18 ( V_149 ) ;
return NULL ;
}
return V_149 ;
}
static char *
F_121 ( T_8 V_155 )
{
int V_148 ;
T_6 V_21 ;
char * V_149 ;
V_21 = strlen ( V_156 ) + 22 + 1 ;
V_149 = F_14 ( V_21 , V_24 ) ;
if ( ! V_149 )
return V_149 ;
V_148 = snprintf ( V_149 , V_21 , V_156 L_39 ,
V_155 ) ;
if ( V_148 >= V_21 ) {
F_18 ( V_149 ) ;
return NULL ;
}
return V_149 ;
}
static int
F_122 ( char * V_157 , char * V_158 , char * V_159 , char * V_160 )
{
char * V_161 [ 3 ] ;
char * V_162 [ 4 ] ;
int V_94 ;
if ( F_123 ( ! V_163 [ 0 ] ) ) {
F_9 ( L_40 , V_72 ) ;
return - V_164 ;
}
F_9 ( L_41 , V_72 , V_157 ) ;
F_9 ( L_42 , V_72 , V_158 ? V_158 : L_43 ) ;
F_9 ( L_44 , V_72 , V_159 ? V_159 : L_43 ) ;
F_9 ( L_45 , V_72 , V_160 ? V_160 : L_43 ) ;
V_161 [ 0 ] = V_159 ;
V_161 [ 1 ] = V_160 ;
V_161 [ 2 ] = NULL ;
V_162 [ 0 ] = ( char * ) V_163 ;
V_162 [ 1 ] = V_157 ;
V_162 [ 2 ] = V_158 ;
V_162 [ 3 ] = NULL ;
V_94 = F_124 ( V_162 [ 0 ] , V_162 , V_161 , V_165 ) ;
if ( V_94 == - V_31 || V_94 == - V_164 ) {
F_9 ( L_46
L_47 ,
V_163 , V_94 ) ;
V_163 [ 0 ] = '\0' ;
}
F_9 ( L_48 , V_72 , V_163 , V_94 ) ;
return V_94 ;
}
static char *
F_125 ( const unsigned char * V_103 , int V_166 )
{
int V_12 ;
char * V_167 , * V_168 ;
V_167 = F_14 ( ( V_166 * 2 ) + 1 , V_24 ) ;
if ( ! V_167 )
return V_167 ;
V_168 = V_167 ;
for ( V_12 = 0 ; V_12 < V_166 ; V_12 ++ ) {
sprintf ( V_168 , L_49 , * V_103 ++ ) ;
V_168 += 2 ;
}
return V_167 ;
}
static int
F_126 ( struct V_32 * V_32 )
{
int V_94 ;
struct V_39 * V_40 = F_24 ( V_32 , V_41 ) ;
char * V_155 = F_121 ( V_40 -> V_147 ) ;
if ( V_32 != & V_83 ) {
F_71 ( L_50 ) ;
F_18 ( V_155 ) ;
return - V_84 ;
}
V_94 = F_122 ( L_51 , NULL , V_155 , NULL ) ;
F_18 ( V_155 ) ;
return V_94 ;
}
static void
F_127 ( struct V_28 * V_29 )
{
F_128 ( & V_29 -> V_43 , V_169 ,
V_97 ) ;
}
static void
F_129 ( struct V_28 * V_29 )
{
F_130 () ;
F_52 ( V_169 , & V_29 -> V_43 ) ;
F_131 () ;
F_132 ( & V_29 -> V_43 , V_169 ) ;
}
static void
F_133 ( struct V_28 * V_29 )
{
char * V_170 , * V_171 , * V_155 ;
struct V_39 * V_40 = F_24 ( V_29 -> V_32 , V_41 ) ;
if ( V_29 -> V_154 == 0 &&
F_51 ( V_42 , & V_29 -> V_43 ) )
return;
V_170 = F_125 ( V_29 -> V_45 . V_22 , V_29 -> V_45 . V_21 ) ;
if ( ! V_170 ) {
F_9 ( L_52 , V_72 ) ;
return;
}
V_171 = F_120 ( V_29 ) ;
V_155 = F_121 ( V_40 -> V_147 ) ;
F_127 ( V_29 ) ;
if ( ! F_122 ( L_53 , V_170 , V_171 , V_155 ) )
F_79 ( V_42 , & V_29 -> V_43 ) ;
F_129 ( V_29 ) ;
F_18 ( V_171 ) ;
F_18 ( V_155 ) ;
F_18 ( V_170 ) ;
}
static void
F_134 ( struct V_28 * V_29 )
{
char * V_170 ;
if ( ! F_51 ( V_42 , & V_29 -> V_43 ) )
return;
V_170 = F_125 ( V_29 -> V_45 . V_22 , V_29 -> V_45 . V_21 ) ;
if ( ! V_170 ) {
F_9 ( L_52 , V_72 ) ;
return;
}
F_127 ( V_29 ) ;
if ( F_51 ( V_42 , & V_29 -> V_43 ) &&
F_122 ( L_54 , V_170 , NULL , NULL ) == 0 )
F_52 ( V_42 , & V_29 -> V_43 ) ;
F_129 ( V_29 ) ;
F_18 ( V_170 ) ;
}
static int
F_135 ( struct V_28 * V_29 )
{
int V_94 ;
char * V_170 , * V_171 , * V_172 ;
if ( F_51 ( V_42 , & V_29 -> V_43 ) )
return 0 ;
V_170 = F_125 ( V_29 -> V_45 . V_22 , V_29 -> V_45 . V_21 ) ;
if ( ! V_170 ) {
F_9 ( L_52 , V_72 ) ;
return - V_4 ;
}
V_171 = F_120 ( V_29 ) ;
V_172 = F_119 ( & V_29 -> V_45 ) ;
F_127 ( V_29 ) ;
if ( F_51 ( V_42 , & V_29 -> V_43 ) ) {
V_94 = 0 ;
} else {
V_94 = F_122 ( L_55 , V_170 , V_171 , V_172 ) ;
if ( V_94 == 0 )
F_79 ( V_42 , & V_29 -> V_43 ) ;
}
F_129 ( V_29 ) ;
F_18 ( V_171 ) ;
F_18 ( V_172 ) ;
F_18 ( V_170 ) ;
return V_94 ;
}
static void
F_136 ( struct V_39 * V_40 )
{
char * V_172 ;
char V_173 [ 22 ] ;
sprintf ( V_173 , L_39 , V_40 -> V_147 ) ;
V_172 = F_118 () ;
F_122 ( L_56 , V_173 , V_172 , NULL ) ;
F_18 ( V_172 ) ;
}
int
F_137 ( struct V_32 * V_32 )
{
int V_20 ;
struct V_87 V_87 ;
struct V_39 * V_40 = F_24 ( V_32 , V_41 ) ;
if ( V_40 -> V_174 )
goto V_175;
V_40 -> V_174 = & V_176 ;
V_20 = V_40 -> V_174 -> V_177 ( V_32 ) ;
if ( ! V_20 )
return V_20 ;
V_40 -> V_174 = & V_178 ;
V_20 = F_74 ( F_77 () , V_88 , & V_87 ) ;
if ( ! V_20 ) {
V_20 = F_75 ( V_87 . V_35 ) ;
F_76 ( & V_87 ) ;
if ( V_20 )
goto V_175;
}
V_40 -> V_174 = & V_179 ;
F_21 ( V_180 L_57
L_58
L_59 ) ;
V_175:
V_20 = V_40 -> V_174 -> V_177 ( V_32 ) ;
if ( V_20 ) {
F_21 ( V_180 L_60
L_61 , V_20 ) ;
V_40 -> V_174 = NULL ;
}
return V_20 ;
}
void
F_22 ( struct V_32 * V_32 )
{
struct V_39 * V_40 = F_24 ( V_32 , V_41 ) ;
if ( V_40 -> V_174 ) {
if ( V_40 -> V_174 -> exit )
V_40 -> V_174 -> exit ( V_32 ) ;
V_40 -> V_174 = NULL ;
}
}
void
F_138 ( struct V_28 * V_29 )
{
struct V_39 * V_40 = F_24 ( V_29 -> V_32 , V_41 ) ;
if ( V_40 -> V_174 )
V_40 -> V_174 -> V_181 ( V_29 ) ;
}
void
F_139 ( struct V_28 * V_29 )
{
struct V_39 * V_40 = F_24 ( V_29 -> V_32 , V_41 ) ;
if ( V_40 -> V_174 )
V_40 -> V_174 -> remove ( V_29 ) ;
}
int
F_140 ( struct V_28 * V_29 )
{
struct V_39 * V_40 = F_24 ( V_29 -> V_32 , V_41 ) ;
if ( V_40 -> V_174 )
return V_40 -> V_174 -> V_182 ( V_29 ) ;
return - V_183 ;
}
void
F_141 ( struct V_39 * V_40 )
{
if ( V_40 -> V_174 )
V_40 -> V_174 -> V_184 ( V_40 ) ;
}
static int
F_142 ( struct V_185 * V_186 , unsigned long V_187 , void * V_188 )
{
struct V_118 * V_119 = V_188 ;
struct V_32 * V_32 = V_119 -> V_109 ;
struct V_39 * V_40 = F_24 ( V_32 , V_41 ) ;
struct V_110 * V_111 = V_40 -> V_110 ;
struct V_35 * V_35 ;
int V_94 = 0 ;
if ( ! F_143 ( V_189 ) )
return 0 ;
if ( ! V_111 ) {
F_144 ( V_189 ) ;
return 0 ;
}
switch ( V_187 ) {
case V_190 :
V_35 = F_95 ( V_119 , V_111 -> V_122 ) ;
if ( F_11 ( V_35 ) ) {
V_94 = F_12 ( V_35 ) ;
break;
}
V_111 -> V_122 -> V_35 = V_35 ;
break;
case V_191 :
if ( V_111 -> V_122 -> V_35 )
F_99 ( V_111 -> V_122 ) ;
break;
default:
V_94 = - V_192 ;
break;
}
F_144 ( V_189 ) ;
return V_94 ;
}
int
F_145 ( void )
{
return F_146 ( & V_193 ) ;
}
void
F_147 ( void )
{
F_148 ( & V_193 ) ;
}
