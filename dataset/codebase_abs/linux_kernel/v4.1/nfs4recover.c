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
struct V_18 V_19 ;
struct V_20 V_21 ;
int V_22 ;
F_9 ( L_1 ,
V_16 -> V_23 , V_16 -> V_24 ) ;
V_19 . V_25 = V_26 ;
V_19 . V_27 = F_10 ( L_2 , 0 , V_28 ) ;
if ( F_11 ( V_19 . V_27 ) ) {
V_22 = F_12 ( V_19 . V_27 ) ;
goto V_29;
}
V_17 . V_23 = F_13 ( V_19 . V_27 ) ;
V_17 . V_24 = F_14 ( V_17 . V_23 , V_30 ) ;
if ( V_17 . V_24 == NULL ) {
V_22 = - V_4 ;
goto V_10;
}
F_15 ( & V_21 , V_16 -> V_24 , V_16 -> V_23 ) ;
V_22 = F_16 ( & V_19 , & V_21 , V_21 . V_31 , V_17 . V_24 ) ;
if ( V_22 )
goto V_10;
F_7 ( V_14 , V_17 . V_24 ) ;
V_22 = 0 ;
V_10:
F_17 ( V_17 . V_24 ) ;
F_18 ( V_19 . V_27 ) ;
V_29:
return V_22 ;
}
static void
F_19 ( struct V_32 * V_33 , int error )
{
F_20 ( V_34 L_3
L_4 , error ) ;
if ( error == - V_35 ) {
F_20 ( V_34 L_5
L_6 ) ;
F_21 ( V_33 -> V_36 ) ;
}
}
static void
F_22 ( struct V_32 * V_33 )
{
const struct V_1 * V_37 ;
char V_14 [ V_38 ] ;
struct V_39 * V_40 , * V_39 ;
struct V_41 * V_42 ;
int V_22 ;
struct V_43 * V_44 = F_23 ( V_33 -> V_36 , V_45 ) ;
if ( F_24 ( V_46 , & V_33 -> V_47 ) )
return;
if ( ! V_44 -> V_48 )
return;
V_22 = F_8 ( V_14 , & V_33 -> V_49 ) ;
if ( V_22 )
return F_19 ( V_33 , V_22 ) ;
V_22 = F_1 ( & V_37 ) ;
if ( V_22 < 0 )
return;
V_22 = F_25 ( V_44 -> V_48 ) ;
if ( V_22 )
goto V_50;
V_40 = V_44 -> V_48 -> V_51 . V_39 ;
F_26 ( & F_27 ( V_40 ) -> V_52 ) ;
V_39 = F_28 ( V_14 , V_40 , V_38 - 1 ) ;
if ( F_11 ( V_39 ) ) {
V_22 = F_12 ( V_39 ) ;
goto V_53;
}
if ( F_29 ( V_39 ) )
goto V_54;
V_22 = F_30 ( F_27 ( V_40 ) , V_39 , V_55 ) ;
V_54:
F_31 ( V_39 ) ;
V_53:
F_32 ( & F_27 ( V_40 ) -> V_52 ) ;
if ( V_22 == 0 ) {
if ( V_44 -> V_56 ) {
V_42 = F_33 ( V_14 , V_44 ) ;
if ( V_42 )
V_42 -> V_57 = V_33 ;
}
F_34 ( V_44 -> V_48 , 0 ) ;
} else {
F_20 ( V_34 L_7
L_8
L_9 , V_22 ,
V_58 ) ;
}
F_35 ( V_44 -> V_48 ) ;
V_50:
F_5 ( V_37 ) ;
}
static int
F_36 ( struct V_59 * V_60 , const char * V_61 , int V_62 ,
T_1 V_63 , T_2 V_64 , unsigned int V_65 )
{
struct V_66 * V_67 =
F_37 ( V_60 , struct V_66 , V_67 ) ;
struct V_68 * V_69 ;
if ( V_62 != V_38 - 1 )
return 0 ;
V_69 = F_14 ( sizeof( struct V_68 ) , V_30 ) ;
if ( V_69 == NULL )
return - V_4 ;
memcpy ( V_69 -> V_61 , V_61 , V_38 - 1 ) ;
V_69 -> V_61 [ V_38 - 1 ] = '\0' ;
F_38 ( & V_69 -> V_70 , & V_67 -> V_71 ) ;
return 0 ;
}
static int
F_39 ( T_3 * V_72 , struct V_43 * V_44 )
{
const struct V_1 * V_37 ;
struct V_39 * V_40 = V_44 -> V_48 -> V_51 . V_39 ;
struct V_66 V_67 = {
. V_67 . V_73 = F_36 ,
. V_71 = F_40 (ctx.names)
} ;
int V_22 ;
V_22 = F_1 ( & V_37 ) ;
if ( V_22 < 0 )
return V_22 ;
V_22 = F_41 ( V_44 -> V_48 , 0 , V_74 ) ;
if ( V_22 < 0 ) {
F_5 ( V_37 ) ;
return V_22 ;
}
V_22 = F_42 ( V_44 -> V_48 , & V_67 . V_67 ) ;
F_43 ( & F_27 ( V_40 ) -> V_52 , V_75 ) ;
while ( ! F_44 ( & V_67 . V_71 ) ) {
struct V_68 * V_69 ;
V_69 = F_45 ( V_67 . V_71 . V_76 , struct V_68 , V_70 ) ;
if ( ! V_22 ) {
struct V_39 * V_39 ;
V_39 = F_28 ( V_69 -> V_61 , V_40 , V_38 - 1 ) ;
if ( F_11 ( V_39 ) ) {
V_22 = F_12 ( V_39 ) ;
break;
}
V_22 = V_72 ( V_40 , V_39 , V_44 ) ;
F_31 ( V_39 ) ;
}
F_46 ( & V_69 -> V_70 ) ;
F_17 ( V_69 ) ;
}
F_32 ( & F_27 ( V_40 ) -> V_52 ) ;
F_5 ( V_37 ) ;
return V_22 ;
}
static int
F_47 ( char * V_61 , int V_62 , struct V_43 * V_44 )
{
struct V_39 * V_40 , * V_39 ;
int V_22 ;
F_9 ( L_10 , V_62 , V_61 ) ;
V_40 = V_44 -> V_48 -> V_51 . V_39 ;
F_43 ( & F_27 ( V_40 ) -> V_52 , V_75 ) ;
V_39 = F_28 ( V_61 , V_40 , V_62 ) ;
if ( F_11 ( V_39 ) ) {
V_22 = F_12 ( V_39 ) ;
goto V_53;
}
V_22 = - V_35 ;
if ( F_48 ( V_39 ) )
goto V_10;
V_22 = F_49 ( F_27 ( V_40 ) , V_39 ) ;
V_10:
F_31 ( V_39 ) ;
V_53:
F_32 ( & F_27 ( V_40 ) -> V_52 ) ;
return V_22 ;
}
static void
F_50 ( struct V_32 * V_33 )
{
const struct V_1 * V_37 ;
struct V_41 * V_42 ;
char V_14 [ V_38 ] ;
int V_22 ;
struct V_43 * V_44 = F_23 ( V_33 -> V_36 , V_45 ) ;
if ( ! V_44 -> V_48 || ! F_51 ( V_46 , & V_33 -> V_47 ) )
return;
V_22 = F_8 ( V_14 , & V_33 -> V_49 ) ;
if ( V_22 )
return F_19 ( V_33 , V_22 ) ;
V_22 = F_25 ( V_44 -> V_48 ) ;
if ( V_22 )
goto V_10;
F_52 ( V_46 , & V_33 -> V_47 ) ;
V_22 = F_1 ( & V_37 ) ;
if ( V_22 < 0 )
goto V_77;
V_22 = F_47 ( V_14 , V_38 - 1 , V_44 ) ;
F_5 ( V_37 ) ;
if ( V_22 == 0 ) {
F_34 ( V_44 -> V_48 , 0 ) ;
if ( V_44 -> V_56 ) {
V_42 = F_53 ( V_14 , V_44 ) ;
if ( V_42 )
F_54 ( V_42 , V_44 ) ;
}
}
V_77:
F_35 ( V_44 -> V_48 ) ;
V_10:
if ( V_22 )
F_20 ( L_11
L_12 , V_38 , V_14 ) ;
}
static int
F_55 ( struct V_39 * V_78 , struct V_39 * V_79 , struct V_43 * V_44 )
{
int V_22 ;
if ( F_56 ( V_79 -> V_80 . V_61 , V_44 ) )
return 0 ;
V_22 = F_49 ( F_27 ( V_78 ) , V_79 ) ;
if ( V_22 )
F_20 ( L_13 ,
V_79 ) ;
return 0 ;
}
static void
F_57 ( struct V_43 * V_44 )
{
int V_22 ;
V_44 -> V_56 = false ;
if ( ! V_44 -> V_48 )
return;
V_22 = F_25 ( V_44 -> V_48 ) ;
if ( V_22 )
goto V_10;
V_22 = F_39 ( F_55 , V_44 ) ;
if ( V_22 == 0 )
F_34 ( V_44 -> V_48 , 0 ) ;
F_35 ( V_44 -> V_48 ) ;
V_10:
F_58 ( V_44 ) ;
if ( V_22 )
F_20 ( L_14
L_15 , V_44 -> V_48 ) ;
}
static int
F_59 ( struct V_39 * V_78 , struct V_39 * V_79 , struct V_43 * V_44 )
{
if ( V_79 -> V_80 . V_23 != V_38 - 1 ) {
F_20 ( L_16 ,
V_79 ) ;
return 0 ;
}
F_33 ( V_79 -> V_80 . V_61 , V_44 ) ;
return 0 ;
}
static int
F_60 ( struct V_36 * V_36 ) {
int V_22 ;
struct V_43 * V_44 = F_23 ( V_36 , V_45 ) ;
if ( ! V_44 -> V_48 )
return 0 ;
V_22 = F_39 ( F_59 , V_44 ) ;
if ( V_22 )
F_20 ( L_17
L_15 , V_44 -> V_48 ) ;
return V_22 ;
}
static int
F_61 ( struct V_36 * V_36 )
{
struct V_43 * V_44 = F_23 ( V_36 , V_45 ) ;
const struct V_1 * V_37 ;
int V_22 ;
F_20 ( L_18 ,
V_58 ) ;
F_62 ( V_44 -> V_48 ) ;
V_22 = F_1 ( & V_37 ) ;
if ( V_22 < 0 ) {
F_20 ( L_19
L_20 ,
V_22 ) ;
return V_22 ;
}
V_44 -> V_48 = F_63 ( V_58 , V_81 | V_82 , 0 ) ;
if ( F_11 ( V_44 -> V_48 ) ) {
F_20 ( L_21 ,
V_58 ) ;
V_22 = F_12 ( V_44 -> V_48 ) ;
V_44 -> V_48 = NULL ;
}
F_5 ( V_37 ) ;
if ( ! V_22 )
V_44 -> V_56 = true ;
return V_22 ;
}
static void
F_64 ( struct V_36 * V_36 )
{
struct V_43 * V_44 = F_23 ( V_36 , V_45 ) ;
if ( ! V_44 -> V_48 )
return;
F_65 ( V_44 -> V_48 ) ;
V_44 -> V_48 = NULL ;
}
static int
F_66 ( struct V_36 * V_36 )
{
struct V_43 * V_44 = F_23 ( V_36 , V_45 ) ;
int V_12 ;
V_44 -> V_83 = F_14 ( sizeof( struct V_84 ) *
V_85 , V_30 ) ;
if ( ! V_44 -> V_83 )
return - V_4 ;
for ( V_12 = 0 ; V_12 < V_85 ; V_12 ++ )
F_67 ( & V_44 -> V_83 [ V_12 ] ) ;
V_44 -> V_86 = 0 ;
return 0 ;
}
static void
F_68 ( struct V_36 * V_36 )
{
struct V_43 * V_44 = F_23 ( V_36 , V_45 ) ;
F_17 ( V_44 -> V_83 ) ;
}
static int
F_69 ( struct V_36 * V_36 )
{
int V_22 ;
V_22 = F_61 ( V_36 ) ;
if ( V_22 )
return V_22 ;
V_22 = F_60 ( V_36 ) ;
if ( V_22 )
F_64 ( V_36 ) ;
return V_22 ;
}
static int
F_70 ( struct V_36 * V_36 )
{
int V_22 ;
if ( V_36 != & V_87 ) {
F_71 ( 1 , V_34 L_22
L_23 ) ;
return - V_88 ;
}
V_22 = F_66 ( V_36 ) ;
if ( V_22 )
return V_22 ;
V_22 = F_69 ( V_36 ) ;
if ( V_22 )
goto V_89;
return 0 ;
V_89:
F_68 ( V_36 ) ;
return V_22 ;
}
static void
F_72 ( struct V_36 * V_36 )
{
struct V_43 * V_44 = F_23 ( V_36 , V_45 ) ;
F_58 ( V_44 ) ;
F_64 ( V_36 ) ;
F_68 ( V_36 ) ;
}
int
F_73 ( char * V_90 )
{
int V_22 ;
struct V_91 V_91 ;
V_22 = F_74 ( V_90 , V_92 , & V_91 ) ;
if ( V_22 )
return V_22 ;
V_22 = - V_93 ;
if ( F_75 ( V_91 . V_39 ) ) {
strcpy ( V_58 , V_90 ) ;
V_22 = 0 ;
}
F_76 ( & V_91 ) ;
return V_22 ;
}
char *
F_77 ( void )
{
return V_58 ;
}
static int
F_78 ( struct V_32 * V_33 )
{
int V_22 ;
char V_14 [ V_38 ] ;
struct V_41 * V_42 ;
struct V_43 * V_44 = F_23 ( V_33 -> V_36 , V_45 ) ;
if ( F_51 ( V_46 , & V_33 -> V_47 ) )
return 0 ;
V_22 = F_8 ( V_14 , & V_33 -> V_49 ) ;
if ( V_22 ) {
F_19 ( V_33 , V_22 ) ;
return V_22 ;
}
V_42 = F_53 ( V_14 , V_44 ) ;
if ( V_42 ) {
F_79 ( V_46 , & V_33 -> V_47 ) ;
V_42 -> V_57 = V_33 ;
return 0 ;
}
return - V_35 ;
}
static int
F_80 ( struct V_94 * V_95 , struct V_96 * V_97 )
{
int V_98 ;
struct V_99 V_100 ;
memset ( & V_100 , 0 , sizeof( V_100 ) ) ;
V_100 . V_24 = V_97 ;
V_100 . V_23 = sizeof( * V_97 ) ;
F_81 ( V_101 ) ;
V_98 = F_82 ( V_95 , & V_100 ) ;
if ( V_98 < 0 ) {
F_81 ( V_102 ) ;
goto V_10;
}
F_83 () ;
if ( V_100 . V_103 < 0 )
V_98 = V_100 . V_103 ;
V_10:
return V_98 ;
}
static int
F_84 ( struct V_94 * V_95 , struct V_96 * V_97 )
{
int V_98 ;
do {
V_98 = F_80 ( V_95 , V_97 ) ;
} while ( V_98 == - V_104 );
return V_98 ;
}
static T_4
F_85 ( struct V_105 * V_106 , const char T_5 * V_107 , T_6 V_108 )
{
struct V_109 * V_110 , * V_111 ;
struct V_96 T_5 * V_97 = (struct V_96 T_5 * ) V_107 ;
T_7 V_112 ;
struct V_43 * V_44 = F_23 ( F_86 ( V_106 ) -> V_113 -> V_114 ,
V_45 ) ;
struct V_115 * V_116 = V_44 -> V_115 ;
if ( V_108 != sizeof( * V_97 ) ) {
F_9 ( L_24 , V_117 , V_108 ,
sizeof( * V_97 ) ) ;
return - V_88 ;
}
if ( F_87 ( & V_112 , & V_97 -> V_118 , sizeof( V_112 ) ) != 0 ) {
F_9 ( L_25 , V_117 ) ;
return - V_119 ;
}
V_111 = NULL ;
F_88 ( & V_116 -> V_120 ) ;
F_89 (tmp, &cn->cn_list, cu_list) {
if ( F_90 ( & V_110 -> V_121 . V_118 ) == V_112 ) {
V_111 = V_110 ;
F_91 ( & V_111 -> V_122 ) ;
break;
}
}
F_92 ( & V_116 -> V_120 ) ;
if ( ! V_111 ) {
F_9 ( L_26 , V_117 , V_112 ) ;
return - V_88 ;
}
if ( F_87 ( & V_111 -> V_121 , V_107 , V_108 ) != 0 )
return - V_119 ;
F_93 ( V_111 -> V_123 ) ;
return V_108 ;
}
static void
F_94 ( struct V_99 * V_100 )
{
struct V_96 * V_97 = V_100 -> V_24 ;
struct V_109 * V_111 = F_37 ( V_97 , struct V_109 ,
V_121 ) ;
if ( V_100 -> V_103 >= 0 )
return;
F_93 ( V_111 -> V_123 ) ;
}
static struct V_39 *
F_95 ( struct V_124 * V_125 , struct V_94 * V_95 )
{
struct V_39 * V_40 , * V_39 ;
V_40 = F_96 ( V_125 , V_126 ) ;
if ( V_40 == NULL )
return F_97 ( - V_35 ) ;
V_39 = F_98 ( V_40 , V_127 , NULL , V_95 ) ;
F_31 ( V_40 ) ;
return V_39 ;
}
static void
F_99 ( struct V_94 * V_95 )
{
if ( V_95 -> V_39 )
F_100 ( V_95 -> V_39 ) ;
}
static struct V_39 *
F_101 ( struct V_36 * V_36 , struct V_94 * V_95 )
{
struct V_124 * V_125 ;
struct V_39 * V_39 ;
V_125 = F_102 ( V_36 ) ;
if ( ! V_125 )
return NULL ;
V_39 = F_95 ( V_125 , V_95 ) ;
F_103 ( V_36 ) ;
return V_39 ;
}
static void
F_104 ( struct V_36 * V_36 , struct V_94 * V_95 )
{
struct V_124 * V_125 ;
V_125 = F_102 ( V_36 ) ;
if ( V_125 ) {
F_99 ( V_95 ) ;
F_103 ( V_36 ) ;
}
}
static int
F_105 ( struct V_36 * V_36 )
{
int V_98 ;
struct V_39 * V_39 ;
struct V_43 * V_44 = F_23 ( V_36 , V_45 ) ;
struct V_115 * V_116 ;
if ( V_44 -> V_115 )
return 0 ;
V_116 = F_106 ( sizeof( * V_116 ) , V_30 ) ;
if ( ! V_116 ) {
V_98 = - V_4 ;
goto V_89;
}
V_116 -> V_128 = F_107 ( & V_129 , V_130 ) ;
if ( F_11 ( V_116 -> V_128 ) ) {
V_98 = F_12 ( V_116 -> V_128 ) ;
goto V_89;
}
F_108 ( & V_116 -> V_120 ) ;
F_67 ( & V_116 -> V_131 ) ;
V_39 = F_101 ( V_36 , V_116 -> V_128 ) ;
if ( F_11 ( V_39 ) ) {
V_98 = F_12 ( V_39 ) ;
goto V_132;
}
V_116 -> V_128 -> V_39 = V_39 ;
V_44 -> V_115 = V_116 ;
return 0 ;
V_132:
F_109 ( V_116 -> V_128 ) ;
V_89:
F_17 ( V_116 ) ;
F_20 ( V_34 L_27 ,
V_98 ) ;
return V_98 ;
}
static void
F_110 ( struct V_36 * V_36 )
{
struct V_43 * V_44 = F_23 ( V_36 , V_45 ) ;
struct V_115 * V_116 = V_44 -> V_115 ;
F_104 ( V_36 , V_116 -> V_128 ) ;
F_109 ( V_116 -> V_128 ) ;
F_17 ( V_44 -> V_115 ) ;
V_44 -> V_115 = NULL ;
}
static struct V_109 *
F_111 ( struct V_115 * V_116 )
{
struct V_109 * V_3 , * V_110 ;
V_3 = F_106 ( sizeof( * V_3 ) , V_30 ) ;
if ( ! V_3 )
return V_3 ;
V_133:
F_88 ( & V_116 -> V_120 ) ;
F_89 (tmp, &cn->cn_list, cu_list) {
if ( V_110 -> V_121 . V_118 == V_116 -> V_134 ) {
V_116 -> V_134 ++ ;
F_92 ( & V_116 -> V_120 ) ;
goto V_133;
}
}
V_3 -> V_123 = V_135 ;
V_3 -> V_121 . V_136 = V_137 ;
F_112 ( V_116 -> V_134 ++ , & V_3 -> V_121 . V_118 ) ;
V_3 -> V_138 = V_116 ;
F_38 ( & V_3 -> V_122 , & V_116 -> V_131 ) ;
F_92 ( & V_116 -> V_120 ) ;
F_9 ( L_28 , V_117 , V_3 -> V_121 . V_118 ) ;
return V_3 ;
}
static void
F_113 ( struct V_109 * V_139 )
{
struct V_115 * V_116 = V_139 -> V_138 ;
F_88 ( & V_116 -> V_120 ) ;
F_46 ( & V_139 -> V_122 ) ;
F_92 ( & V_116 -> V_120 ) ;
F_17 ( V_139 ) ;
}
static void
F_114 ( struct V_32 * V_33 )
{
int V_98 ;
struct V_109 * V_111 ;
struct V_43 * V_44 = F_23 ( V_33 -> V_36 , V_45 ) ;
struct V_115 * V_116 = V_44 -> V_115 ;
if ( F_51 ( V_46 , & V_33 -> V_47 ) )
return;
V_111 = F_111 ( V_116 ) ;
if ( ! V_111 ) {
V_98 = - V_4 ;
goto V_140;
}
V_111 -> V_121 . V_141 = V_142 ;
V_111 -> V_121 . V_143 . V_144 . V_145 = V_33 -> V_49 . V_23 ;
memcpy ( V_111 -> V_121 . V_143 . V_144 . V_146 , V_33 -> V_49 . V_24 ,
V_33 -> V_49 . V_23 ) ;
V_98 = F_84 ( V_116 -> V_128 , & V_111 -> V_121 ) ;
if ( ! V_98 ) {
V_98 = V_111 -> V_121 . V_147 ;
F_79 ( V_46 , & V_33 -> V_47 ) ;
}
F_113 ( V_111 ) ;
V_140:
if ( V_98 )
F_20 ( V_34 L_29
L_30 , V_98 ) ;
}
static void
F_115 ( struct V_32 * V_33 )
{
int V_98 ;
struct V_109 * V_111 ;
struct V_43 * V_44 = F_23 ( V_33 -> V_36 , V_45 ) ;
struct V_115 * V_116 = V_44 -> V_115 ;
if ( ! F_51 ( V_46 , & V_33 -> V_47 ) )
return;
V_111 = F_111 ( V_116 ) ;
if ( ! V_111 ) {
V_98 = - V_4 ;
goto V_140;
}
V_111 -> V_121 . V_141 = V_148 ;
V_111 -> V_121 . V_143 . V_144 . V_145 = V_33 -> V_49 . V_23 ;
memcpy ( V_111 -> V_121 . V_143 . V_144 . V_146 , V_33 -> V_49 . V_24 ,
V_33 -> V_49 . V_23 ) ;
V_98 = F_84 ( V_116 -> V_128 , & V_111 -> V_121 ) ;
if ( ! V_98 ) {
V_98 = V_111 -> V_121 . V_147 ;
F_52 ( V_46 , & V_33 -> V_47 ) ;
}
F_113 ( V_111 ) ;
V_140:
if ( V_98 )
F_20 ( V_34 L_31
L_32 , V_98 ) ;
}
static int
F_116 ( struct V_32 * V_33 )
{
int V_98 ;
struct V_109 * V_111 ;
struct V_43 * V_44 = F_23 ( V_33 -> V_36 , V_45 ) ;
struct V_115 * V_116 = V_44 -> V_115 ;
if ( F_51 ( V_46 , & V_33 -> V_47 ) )
return 0 ;
V_111 = F_111 ( V_116 ) ;
if ( ! V_111 ) {
F_20 ( V_34 L_33
L_34 , - V_4 ) ;
return - V_4 ;
}
V_111 -> V_121 . V_141 = V_149 ;
V_111 -> V_121 . V_143 . V_144 . V_145 = V_33 -> V_49 . V_23 ;
memcpy ( V_111 -> V_121 . V_143 . V_144 . V_146 , V_33 -> V_49 . V_24 ,
V_33 -> V_49 . V_23 ) ;
V_98 = F_84 ( V_116 -> V_128 , & V_111 -> V_121 ) ;
if ( ! V_98 ) {
V_98 = V_111 -> V_121 . V_147 ;
F_79 ( V_46 , & V_33 -> V_47 ) ;
}
F_113 ( V_111 ) ;
return V_98 ;
}
static void
F_117 ( struct V_43 * V_44 )
{
int V_98 ;
struct V_109 * V_111 ;
struct V_115 * V_116 = V_44 -> V_115 ;
V_111 = F_111 ( V_116 ) ;
if ( ! V_111 ) {
V_98 = - V_4 ;
goto V_140;
}
V_111 -> V_121 . V_141 = V_150 ;
V_111 -> V_121 . V_143 . V_151 = ( V_152 ) V_44 -> V_153 ;
V_98 = F_84 ( V_116 -> V_128 , & V_111 -> V_121 ) ;
if ( ! V_98 )
V_98 = V_111 -> V_121 . V_147 ;
F_113 ( V_111 ) ;
V_140:
if ( V_98 )
F_20 ( V_34 L_35 , V_98 ) ;
}
static char *
F_118 ( void )
{
int V_154 ;
T_6 V_23 ;
char * V_155 ;
if ( V_156 )
return NULL ;
V_23 = strlen ( V_157 ) +
strlen ( F_77 () ) + 1 ;
V_155 = F_14 ( V_23 , V_30 ) ;
if ( ! V_155 )
return V_155 ;
V_154 = snprintf ( V_155 , V_23 , V_157 L_36 ,
F_77 () ) ;
if ( V_154 >= V_23 ) {
F_17 ( V_155 ) ;
return NULL ;
}
return V_155 ;
}
static char *
F_119 ( const struct V_15 * V_61 )
{
int V_154 ;
T_6 V_23 ;
char * V_155 ;
if ( V_156 )
return NULL ;
V_23 = strlen ( V_158 ) +
strlen ( F_77 () ) + 1 + V_38 ;
V_155 = F_14 ( V_23 , V_30 ) ;
if ( ! V_155 )
return V_155 ;
V_154 = snprintf ( V_155 , V_23 , V_158 L_37 ,
F_77 () ) ;
if ( V_154 > ( V_23 - V_38 ) ) {
F_17 ( V_155 ) ;
return NULL ;
}
V_154 = F_8 ( V_155 + V_154 , V_61 ) ;
if ( V_154 ) {
F_17 ( V_155 ) ;
return NULL ;
}
return V_155 ;
}
static char *
F_120 ( struct V_32 * V_33 )
{
int V_154 ;
T_6 V_23 ;
char * V_155 ;
V_23 = strlen ( V_159 ) + 1 + 1 ;
V_155 = F_14 ( V_23 , V_30 ) ;
if ( ! V_155 )
return V_155 ;
V_154 = snprintf ( V_155 , V_23 , V_159 L_38 ,
V_33 -> V_160 ? 'Y' : 'N' ) ;
if ( V_154 >= V_23 ) {
F_17 ( V_155 ) ;
return NULL ;
}
return V_155 ;
}
static char *
F_121 ( T_8 V_161 )
{
int V_154 ;
T_6 V_23 ;
char * V_155 ;
V_23 = strlen ( V_162 ) + 22 + 1 ;
V_155 = F_14 ( V_23 , V_30 ) ;
if ( ! V_155 )
return V_155 ;
V_154 = snprintf ( V_155 , V_23 , V_162 L_39 ,
V_161 ) ;
if ( V_154 >= V_23 ) {
F_17 ( V_155 ) ;
return NULL ;
}
return V_155 ;
}
static int
F_122 ( char * V_163 , char * V_164 , char * V_165 , char * V_166 )
{
char * V_167 [ 3 ] ;
char * V_168 [ 4 ] ;
int V_98 ;
if ( F_123 ( ! V_169 [ 0 ] ) ) {
F_9 ( L_40 , V_117 ) ;
return - V_170 ;
}
F_9 ( L_41 , V_117 , V_163 ) ;
F_9 ( L_42 , V_117 , V_164 ? V_164 : L_43 ) ;
F_9 ( L_44 , V_117 , V_165 ? V_165 : L_43 ) ;
F_9 ( L_45 , V_117 , V_166 ? V_166 : L_43 ) ;
V_167 [ 0 ] = V_165 ;
V_167 [ 1 ] = V_166 ;
V_167 [ 2 ] = NULL ;
V_168 [ 0 ] = ( char * ) V_169 ;
V_168 [ 1 ] = V_163 ;
V_168 [ 2 ] = V_164 ;
V_168 [ 3 ] = NULL ;
V_98 = F_124 ( V_168 [ 0 ] , V_168 , V_167 , V_171 ) ;
if ( V_98 == - V_35 || V_98 == - V_170 ) {
F_9 ( L_46
L_47 ,
V_169 , V_98 ) ;
V_169 [ 0 ] = '\0' ;
}
F_9 ( L_48 , V_117 , V_169 , V_98 ) ;
return V_98 ;
}
static char *
F_125 ( const unsigned char * V_107 , int V_172 )
{
int V_12 ;
char * V_173 , * V_174 ;
V_173 = F_14 ( ( V_172 * 2 ) + 1 , V_30 ) ;
if ( ! V_173 )
return V_173 ;
V_174 = V_173 ;
for ( V_12 = 0 ; V_12 < V_172 ; V_12 ++ ) {
sprintf ( V_174 , L_49 , * V_107 ++ ) ;
V_174 += 2 ;
}
return V_173 ;
}
static int
F_126 ( struct V_36 * V_36 )
{
int V_98 ;
struct V_43 * V_44 = F_23 ( V_36 , V_45 ) ;
char * V_161 = F_121 ( V_44 -> V_153 ) ;
if ( V_36 != & V_87 ) {
F_71 ( 1 , V_34 L_50
L_23 ) ;
return - V_88 ;
}
V_98 = F_122 ( L_51 , NULL , V_161 , NULL ) ;
F_17 ( V_161 ) ;
return V_98 ;
}
static void
F_127 ( struct V_32 * V_33 )
{
F_128 ( & V_33 -> V_47 , V_175 ,
V_101 ) ;
}
static void
F_129 ( struct V_32 * V_33 )
{
F_130 () ;
F_52 ( V_175 , & V_33 -> V_47 ) ;
F_131 () ;
F_132 ( & V_33 -> V_47 , V_175 ) ;
}
static void
F_133 ( struct V_32 * V_33 )
{
char * V_176 , * V_177 , * V_161 ;
struct V_43 * V_44 = F_23 ( V_33 -> V_36 , V_45 ) ;
if ( V_33 -> V_160 == 0 &&
F_51 ( V_46 , & V_33 -> V_47 ) )
return;
V_176 = F_125 ( V_33 -> V_49 . V_24 , V_33 -> V_49 . V_23 ) ;
if ( ! V_176 ) {
F_9 ( L_52 , V_117 ) ;
return;
}
V_177 = F_120 ( V_33 ) ;
V_161 = F_121 ( V_44 -> V_153 ) ;
F_127 ( V_33 ) ;
if ( ! F_122 ( L_53 , V_176 , V_177 , V_161 ) )
F_79 ( V_46 , & V_33 -> V_47 ) ;
F_129 ( V_33 ) ;
F_17 ( V_177 ) ;
F_17 ( V_161 ) ;
F_17 ( V_176 ) ;
}
static void
F_134 ( struct V_32 * V_33 )
{
char * V_176 ;
if ( ! F_51 ( V_46 , & V_33 -> V_47 ) )
return;
V_176 = F_125 ( V_33 -> V_49 . V_24 , V_33 -> V_49 . V_23 ) ;
if ( ! V_176 ) {
F_9 ( L_52 , V_117 ) ;
return;
}
F_127 ( V_33 ) ;
if ( F_51 ( V_46 , & V_33 -> V_47 ) &&
F_122 ( L_54 , V_176 , NULL , NULL ) == 0 )
F_52 ( V_46 , & V_33 -> V_47 ) ;
F_129 ( V_33 ) ;
F_17 ( V_176 ) ;
}
static int
F_135 ( struct V_32 * V_33 )
{
int V_98 ;
char * V_176 , * V_177 , * V_178 ;
if ( F_51 ( V_46 , & V_33 -> V_47 ) )
return 0 ;
V_176 = F_125 ( V_33 -> V_49 . V_24 , V_33 -> V_49 . V_23 ) ;
if ( ! V_176 ) {
F_9 ( L_52 , V_117 ) ;
return - V_4 ;
}
V_177 = F_120 ( V_33 ) ;
V_178 = F_119 ( & V_33 -> V_49 ) ;
F_127 ( V_33 ) ;
if ( F_51 ( V_46 , & V_33 -> V_47 ) ) {
V_98 = 0 ;
} else {
V_98 = F_122 ( L_55 , V_176 , V_177 , V_178 ) ;
if ( V_98 == 0 )
F_79 ( V_46 , & V_33 -> V_47 ) ;
}
F_129 ( V_33 ) ;
F_17 ( V_177 ) ;
F_17 ( V_178 ) ;
F_17 ( V_176 ) ;
return V_98 ;
}
static void
F_136 ( struct V_43 * V_44 )
{
char * V_178 ;
char V_179 [ 22 ] ;
sprintf ( V_179 , L_39 , V_44 -> V_153 ) ;
V_178 = F_118 () ;
F_122 ( L_56 , V_179 , V_178 , NULL ) ;
F_17 ( V_178 ) ;
}
int
F_137 ( struct V_36 * V_36 )
{
int V_22 ;
struct V_91 V_91 ;
struct V_43 * V_44 = F_23 ( V_36 , V_45 ) ;
if ( V_44 -> V_180 )
goto V_181;
V_44 -> V_180 = & V_182 ;
V_22 = V_44 -> V_180 -> V_183 ( V_36 ) ;
if ( ! V_22 )
return V_22 ;
V_44 -> V_180 = & V_184 ;
V_22 = F_74 ( F_77 () , V_92 , & V_91 ) ;
if ( ! V_22 ) {
V_22 = F_75 ( V_91 . V_39 ) ;
F_76 ( & V_91 ) ;
if ( V_22 )
goto V_181;
}
V_44 -> V_180 = & V_185 ;
F_20 ( V_186 L_57
L_58
L_59 ) ;
V_181:
V_22 = V_44 -> V_180 -> V_183 ( V_36 ) ;
if ( V_22 ) {
F_20 ( V_186 L_60
L_61 , V_22 ) ;
V_44 -> V_180 = NULL ;
}
return V_22 ;
}
void
F_21 ( struct V_36 * V_36 )
{
struct V_43 * V_44 = F_23 ( V_36 , V_45 ) ;
if ( V_44 -> V_180 ) {
if ( V_44 -> V_180 -> exit )
V_44 -> V_180 -> exit ( V_36 ) ;
V_44 -> V_180 = NULL ;
}
}
void
F_138 ( struct V_32 * V_33 )
{
struct V_43 * V_44 = F_23 ( V_33 -> V_36 , V_45 ) ;
if ( V_44 -> V_180 )
V_44 -> V_180 -> V_187 ( V_33 ) ;
}
void
F_139 ( struct V_32 * V_33 )
{
struct V_43 * V_44 = F_23 ( V_33 -> V_36 , V_45 ) ;
if ( V_44 -> V_180 )
V_44 -> V_180 -> remove ( V_33 ) ;
}
int
F_140 ( struct V_32 * V_33 )
{
struct V_43 * V_44 = F_23 ( V_33 -> V_36 , V_45 ) ;
if ( V_44 -> V_180 )
return V_44 -> V_180 -> V_188 ( V_33 ) ;
return - V_189 ;
}
void
F_141 ( struct V_43 * V_44 )
{
if ( V_44 -> V_180 )
V_44 -> V_180 -> V_190 ( V_44 ) ;
}
static int
F_142 ( struct V_191 * V_192 , unsigned long V_193 , void * V_194 )
{
struct V_124 * V_125 = V_194 ;
struct V_36 * V_36 = V_125 -> V_114 ;
struct V_43 * V_44 = F_23 ( V_36 , V_45 ) ;
struct V_115 * V_116 = V_44 -> V_115 ;
struct V_39 * V_39 ;
int V_98 = 0 ;
if ( ! F_143 ( V_195 ) )
return 0 ;
if ( ! V_116 ) {
F_144 ( V_195 ) ;
return 0 ;
}
switch ( V_193 ) {
case V_196 :
V_39 = F_95 ( V_125 , V_116 -> V_128 ) ;
if ( F_11 ( V_39 ) ) {
V_98 = F_12 ( V_39 ) ;
break;
}
V_116 -> V_128 -> V_39 = V_39 ;
break;
case V_197 :
if ( V_116 -> V_128 -> V_39 )
F_99 ( V_116 -> V_128 ) ;
break;
default:
V_98 = - V_198 ;
break;
}
F_144 ( V_195 ) ;
return V_98 ;
}
int
F_145 ( void )
{
return F_146 ( & V_199 ) ;
}
void
F_147 ( void )
{
F_148 ( & V_199 ) ;
}
