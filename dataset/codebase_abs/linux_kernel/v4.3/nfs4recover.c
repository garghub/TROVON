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
struct V_68 * V_69 , * V_74 ;
int V_22 ;
V_22 = F_1 ( & V_37 ) ;
if ( V_22 < 0 )
return V_22 ;
V_22 = F_41 ( V_44 -> V_48 , 0 , V_75 ) ;
if ( V_22 < 0 ) {
F_5 ( V_37 ) ;
return V_22 ;
}
V_22 = F_42 ( V_44 -> V_48 , & V_67 . V_67 ) ;
F_43 ( & F_27 ( V_40 ) -> V_52 , V_76 ) ;
F_44 (entry, tmp, &ctx.names, list) {
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
F_45 ( & V_69 -> V_70 ) ;
F_17 ( V_69 ) ;
}
F_32 ( & F_27 ( V_40 ) -> V_52 ) ;
F_5 ( V_37 ) ;
F_44 (entry, tmp, &ctx.names, list) {
F_9 ( L_10 , V_77 , V_69 -> V_61 ) ;
F_45 ( & V_69 -> V_70 ) ;
F_17 ( V_69 ) ;
}
return V_22 ;
}
static int
F_46 ( char * V_61 , int V_62 , struct V_43 * V_44 )
{
struct V_39 * V_40 , * V_39 ;
int V_22 ;
F_9 ( L_11 , V_62 , V_61 ) ;
V_40 = V_44 -> V_48 -> V_51 . V_39 ;
F_43 ( & F_27 ( V_40 ) -> V_52 , V_76 ) ;
V_39 = F_28 ( V_61 , V_40 , V_62 ) ;
if ( F_11 ( V_39 ) ) {
V_22 = F_12 ( V_39 ) ;
goto V_53;
}
V_22 = - V_35 ;
if ( F_47 ( V_39 ) )
goto V_10;
V_22 = F_48 ( F_27 ( V_40 ) , V_39 ) ;
V_10:
F_31 ( V_39 ) ;
V_53:
F_32 ( & F_27 ( V_40 ) -> V_52 ) ;
return V_22 ;
}
static void
F_49 ( struct V_32 * V_33 )
{
const struct V_1 * V_37 ;
struct V_41 * V_42 ;
char V_14 [ V_38 ] ;
int V_22 ;
struct V_43 * V_44 = F_23 ( V_33 -> V_36 , V_45 ) ;
if ( ! V_44 -> V_48 || ! F_50 ( V_46 , & V_33 -> V_47 ) )
return;
V_22 = F_8 ( V_14 , & V_33 -> V_49 ) ;
if ( V_22 )
return F_19 ( V_33 , V_22 ) ;
V_22 = F_25 ( V_44 -> V_48 ) ;
if ( V_22 )
goto V_10;
F_51 ( V_46 , & V_33 -> V_47 ) ;
V_22 = F_1 ( & V_37 ) ;
if ( V_22 < 0 )
goto V_78;
V_22 = F_46 ( V_14 , V_38 - 1 , V_44 ) ;
F_5 ( V_37 ) ;
if ( V_22 == 0 ) {
F_34 ( V_44 -> V_48 , 0 ) ;
if ( V_44 -> V_56 ) {
V_42 = F_52 ( V_14 , V_44 ) ;
if ( V_42 )
F_53 ( V_42 , V_44 ) ;
}
}
V_78:
F_35 ( V_44 -> V_48 ) ;
V_10:
if ( V_22 )
F_20 ( L_12
L_13 , V_38 , V_14 ) ;
}
static int
F_54 ( struct V_39 * V_79 , struct V_39 * V_80 , struct V_43 * V_44 )
{
int V_22 ;
if ( F_55 ( V_80 -> V_81 . V_61 , V_44 ) )
return 0 ;
V_22 = F_48 ( F_27 ( V_79 ) , V_80 ) ;
if ( V_22 )
F_20 ( L_14 ,
V_80 ) ;
return 0 ;
}
static void
F_56 ( struct V_43 * V_44 )
{
int V_22 ;
V_44 -> V_56 = false ;
if ( ! V_44 -> V_48 )
return;
V_22 = F_25 ( V_44 -> V_48 ) ;
if ( V_22 )
goto V_10;
V_22 = F_39 ( F_54 , V_44 ) ;
if ( V_22 == 0 )
F_34 ( V_44 -> V_48 , 0 ) ;
F_35 ( V_44 -> V_48 ) ;
V_10:
F_57 ( V_44 ) ;
if ( V_22 )
F_20 ( L_15
L_16 , V_44 -> V_48 ) ;
}
static int
F_58 ( struct V_39 * V_79 , struct V_39 * V_80 , struct V_43 * V_44 )
{
if ( V_80 -> V_81 . V_23 != V_38 - 1 ) {
F_20 ( L_17 ,
V_80 ) ;
return 0 ;
}
F_33 ( V_80 -> V_81 . V_61 , V_44 ) ;
return 0 ;
}
static int
F_59 ( struct V_36 * V_36 ) {
int V_22 ;
struct V_43 * V_44 = F_23 ( V_36 , V_45 ) ;
if ( ! V_44 -> V_48 )
return 0 ;
V_22 = F_39 ( F_58 , V_44 ) ;
if ( V_22 )
F_20 ( L_18
L_16 , V_44 -> V_48 ) ;
return V_22 ;
}
static int
F_60 ( struct V_36 * V_36 )
{
struct V_43 * V_44 = F_23 ( V_36 , V_45 ) ;
const struct V_1 * V_37 ;
int V_22 ;
F_20 ( L_19 ,
V_58 ) ;
F_61 ( V_44 -> V_48 ) ;
V_22 = F_1 ( & V_37 ) ;
if ( V_22 < 0 ) {
F_20 ( L_20
L_21 ,
V_22 ) ;
return V_22 ;
}
V_44 -> V_48 = F_62 ( V_58 , V_82 | V_83 , 0 ) ;
if ( F_11 ( V_44 -> V_48 ) ) {
F_20 ( L_22 ,
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
F_63 ( struct V_36 * V_36 )
{
struct V_43 * V_44 = F_23 ( V_36 , V_45 ) ;
if ( ! V_44 -> V_48 )
return;
F_64 ( V_44 -> V_48 ) ;
V_44 -> V_48 = NULL ;
}
static int
F_65 ( struct V_36 * V_36 )
{
struct V_43 * V_44 = F_23 ( V_36 , V_45 ) ;
int V_12 ;
V_44 -> V_84 = F_14 ( sizeof( struct V_85 ) *
V_86 , V_30 ) ;
if ( ! V_44 -> V_84 )
return - V_4 ;
for ( V_12 = 0 ; V_12 < V_86 ; V_12 ++ )
F_66 ( & V_44 -> V_84 [ V_12 ] ) ;
V_44 -> V_87 = 0 ;
return 0 ;
}
static void
F_67 ( struct V_36 * V_36 )
{
struct V_43 * V_44 = F_23 ( V_36 , V_45 ) ;
F_17 ( V_44 -> V_84 ) ;
}
static int
F_68 ( struct V_36 * V_36 )
{
int V_22 ;
V_22 = F_60 ( V_36 ) ;
if ( V_22 )
return V_22 ;
V_22 = F_59 ( V_36 ) ;
if ( V_22 )
F_63 ( V_36 ) ;
return V_22 ;
}
static int
F_69 ( struct V_36 * V_36 )
{
int V_22 ;
if ( V_36 != & V_88 ) {
F_70 ( L_23 ) ;
return - V_89 ;
}
V_22 = F_65 ( V_36 ) ;
if ( V_22 )
return V_22 ;
V_22 = F_68 ( V_36 ) ;
if ( V_22 )
goto V_90;
return 0 ;
V_90:
F_67 ( V_36 ) ;
return V_22 ;
}
static void
F_71 ( struct V_36 * V_36 )
{
struct V_43 * V_44 = F_23 ( V_36 , V_45 ) ;
F_57 ( V_44 ) ;
F_63 ( V_36 ) ;
F_67 ( V_36 ) ;
}
int
F_72 ( char * V_91 )
{
int V_22 ;
struct V_92 V_92 ;
V_22 = F_73 ( V_91 , V_93 , & V_92 ) ;
if ( V_22 )
return V_22 ;
V_22 = - V_94 ;
if ( F_74 ( V_92 . V_39 ) ) {
strcpy ( V_58 , V_91 ) ;
V_22 = 0 ;
}
F_75 ( & V_92 ) ;
return V_22 ;
}
char *
F_76 ( void )
{
return V_58 ;
}
static int
F_77 ( struct V_32 * V_33 )
{
int V_22 ;
char V_14 [ V_38 ] ;
struct V_41 * V_42 ;
struct V_43 * V_44 = F_23 ( V_33 -> V_36 , V_45 ) ;
if ( F_50 ( V_46 , & V_33 -> V_47 ) )
return 0 ;
V_22 = F_8 ( V_14 , & V_33 -> V_49 ) ;
if ( V_22 ) {
F_19 ( V_33 , V_22 ) ;
return V_22 ;
}
V_42 = F_52 ( V_14 , V_44 ) ;
if ( V_42 ) {
F_78 ( V_46 , & V_33 -> V_47 ) ;
V_42 -> V_57 = V_33 ;
return 0 ;
}
return - V_35 ;
}
static int
F_79 ( struct V_95 * V_96 , struct V_97 * V_98 )
{
int V_99 ;
struct V_100 V_101 ;
memset ( & V_101 , 0 , sizeof( V_101 ) ) ;
V_101 . V_24 = V_98 ;
V_101 . V_23 = sizeof( * V_98 ) ;
F_80 ( V_102 ) ;
V_99 = F_81 ( V_96 , & V_101 ) ;
if ( V_99 < 0 ) {
F_80 ( V_103 ) ;
goto V_10;
}
F_82 () ;
if ( V_101 . V_104 < 0 )
V_99 = V_101 . V_104 ;
V_10:
return V_99 ;
}
static int
F_83 ( struct V_95 * V_96 , struct V_97 * V_98 )
{
int V_99 ;
do {
V_99 = F_79 ( V_96 , V_98 ) ;
} while ( V_99 == - V_105 );
return V_99 ;
}
static T_4
F_84 ( struct V_106 * V_107 , const char T_5 * V_108 , T_6 V_109 )
{
struct V_110 * V_74 , * V_111 ;
struct V_97 T_5 * V_98 = (struct V_97 T_5 * ) V_108 ;
T_7 V_112 ;
struct V_43 * V_44 = F_23 ( F_85 ( V_107 ) -> V_113 -> V_114 ,
V_45 ) ;
struct V_115 * V_116 = V_44 -> V_115 ;
if ( V_109 != sizeof( * V_98 ) ) {
F_9 ( L_24 , V_77 , V_109 ,
sizeof( * V_98 ) ) ;
return - V_89 ;
}
if ( F_86 ( & V_112 , & V_98 -> V_117 , sizeof( V_112 ) ) != 0 ) {
F_9 ( L_25 , V_77 ) ;
return - V_118 ;
}
V_111 = NULL ;
F_87 ( & V_116 -> V_119 ) ;
F_88 (tmp, &cn->cn_list, cu_list) {
if ( F_89 ( & V_74 -> V_120 . V_117 ) == V_112 ) {
V_111 = V_74 ;
F_90 ( & V_111 -> V_121 ) ;
break;
}
}
F_91 ( & V_116 -> V_119 ) ;
if ( ! V_111 ) {
F_9 ( L_26 , V_77 , V_112 ) ;
return - V_89 ;
}
if ( F_86 ( & V_111 -> V_120 , V_108 , V_109 ) != 0 )
return - V_118 ;
F_92 ( V_111 -> V_122 ) ;
return V_109 ;
}
static void
F_93 ( struct V_100 * V_101 )
{
struct V_97 * V_98 = V_101 -> V_24 ;
struct V_110 * V_111 = F_37 ( V_98 , struct V_110 ,
V_120 ) ;
if ( V_101 -> V_104 >= 0 )
return;
F_92 ( V_111 -> V_122 ) ;
}
static struct V_39 *
F_94 ( struct V_123 * V_124 , struct V_95 * V_96 )
{
struct V_39 * V_40 , * V_39 ;
V_40 = F_95 ( V_124 , V_125 ) ;
if ( V_40 == NULL )
return F_96 ( - V_35 ) ;
V_39 = F_97 ( V_40 , V_126 , NULL , V_96 ) ;
F_31 ( V_40 ) ;
return V_39 ;
}
static void
F_98 ( struct V_95 * V_96 )
{
if ( V_96 -> V_39 )
F_99 ( V_96 -> V_39 ) ;
}
static struct V_39 *
F_100 ( struct V_36 * V_36 , struct V_95 * V_96 )
{
struct V_123 * V_124 ;
struct V_39 * V_39 ;
V_124 = F_101 ( V_36 ) ;
if ( ! V_124 )
return NULL ;
V_39 = F_94 ( V_124 , V_96 ) ;
F_102 ( V_36 ) ;
return V_39 ;
}
static void
F_103 ( struct V_36 * V_36 , struct V_95 * V_96 )
{
struct V_123 * V_124 ;
V_124 = F_101 ( V_36 ) ;
if ( V_124 ) {
F_98 ( V_96 ) ;
F_102 ( V_36 ) ;
}
}
static int
F_104 ( struct V_36 * V_36 )
{
int V_99 ;
struct V_39 * V_39 ;
struct V_43 * V_44 = F_23 ( V_36 , V_45 ) ;
struct V_115 * V_116 ;
if ( V_44 -> V_115 )
return 0 ;
V_116 = F_105 ( sizeof( * V_116 ) , V_30 ) ;
if ( ! V_116 ) {
V_99 = - V_4 ;
goto V_90;
}
V_116 -> V_127 = F_106 ( & V_128 , V_129 ) ;
if ( F_11 ( V_116 -> V_127 ) ) {
V_99 = F_12 ( V_116 -> V_127 ) ;
goto V_90;
}
F_107 ( & V_116 -> V_119 ) ;
F_66 ( & V_116 -> V_130 ) ;
V_39 = F_100 ( V_36 , V_116 -> V_127 ) ;
if ( F_11 ( V_39 ) ) {
V_99 = F_12 ( V_39 ) ;
goto V_131;
}
V_116 -> V_127 -> V_39 = V_39 ;
V_44 -> V_115 = V_116 ;
return 0 ;
V_131:
F_108 ( V_116 -> V_127 ) ;
V_90:
F_17 ( V_116 ) ;
F_20 ( V_34 L_27 ,
V_99 ) ;
return V_99 ;
}
static void
F_109 ( struct V_36 * V_36 )
{
struct V_43 * V_44 = F_23 ( V_36 , V_45 ) ;
struct V_115 * V_116 = V_44 -> V_115 ;
F_103 ( V_36 , V_116 -> V_127 ) ;
F_108 ( V_116 -> V_127 ) ;
F_17 ( V_44 -> V_115 ) ;
V_44 -> V_115 = NULL ;
}
static struct V_110 *
F_110 ( struct V_115 * V_116 )
{
struct V_110 * V_3 , * V_74 ;
V_3 = F_105 ( sizeof( * V_3 ) , V_30 ) ;
if ( ! V_3 )
return V_3 ;
V_132:
F_87 ( & V_116 -> V_119 ) ;
F_88 (tmp, &cn->cn_list, cu_list) {
if ( V_74 -> V_120 . V_117 == V_116 -> V_133 ) {
V_116 -> V_133 ++ ;
F_91 ( & V_116 -> V_119 ) ;
goto V_132;
}
}
V_3 -> V_122 = V_134 ;
V_3 -> V_120 . V_135 = V_136 ;
F_111 ( V_116 -> V_133 ++ , & V_3 -> V_120 . V_117 ) ;
V_3 -> V_137 = V_116 ;
F_38 ( & V_3 -> V_121 , & V_116 -> V_130 ) ;
F_91 ( & V_116 -> V_119 ) ;
F_9 ( L_28 , V_77 , V_3 -> V_120 . V_117 ) ;
return V_3 ;
}
static void
F_112 ( struct V_110 * V_138 )
{
struct V_115 * V_116 = V_138 -> V_137 ;
F_87 ( & V_116 -> V_119 ) ;
F_45 ( & V_138 -> V_121 ) ;
F_91 ( & V_116 -> V_119 ) ;
F_17 ( V_138 ) ;
}
static void
F_113 ( struct V_32 * V_33 )
{
int V_99 ;
struct V_110 * V_111 ;
struct V_43 * V_44 = F_23 ( V_33 -> V_36 , V_45 ) ;
struct V_115 * V_116 = V_44 -> V_115 ;
if ( F_50 ( V_46 , & V_33 -> V_47 ) )
return;
V_111 = F_110 ( V_116 ) ;
if ( ! V_111 ) {
V_99 = - V_4 ;
goto V_139;
}
V_111 -> V_120 . V_140 = V_141 ;
V_111 -> V_120 . V_142 . V_143 . V_144 = V_33 -> V_49 . V_23 ;
memcpy ( V_111 -> V_120 . V_142 . V_143 . V_145 , V_33 -> V_49 . V_24 ,
V_33 -> V_49 . V_23 ) ;
V_99 = F_83 ( V_116 -> V_127 , & V_111 -> V_120 ) ;
if ( ! V_99 ) {
V_99 = V_111 -> V_120 . V_146 ;
F_78 ( V_46 , & V_33 -> V_47 ) ;
}
F_112 ( V_111 ) ;
V_139:
if ( V_99 )
F_20 ( V_34 L_29
L_30 , V_99 ) ;
}
static void
F_114 ( struct V_32 * V_33 )
{
int V_99 ;
struct V_110 * V_111 ;
struct V_43 * V_44 = F_23 ( V_33 -> V_36 , V_45 ) ;
struct V_115 * V_116 = V_44 -> V_115 ;
if ( ! F_50 ( V_46 , & V_33 -> V_47 ) )
return;
V_111 = F_110 ( V_116 ) ;
if ( ! V_111 ) {
V_99 = - V_4 ;
goto V_139;
}
V_111 -> V_120 . V_140 = V_147 ;
V_111 -> V_120 . V_142 . V_143 . V_144 = V_33 -> V_49 . V_23 ;
memcpy ( V_111 -> V_120 . V_142 . V_143 . V_145 , V_33 -> V_49 . V_24 ,
V_33 -> V_49 . V_23 ) ;
V_99 = F_83 ( V_116 -> V_127 , & V_111 -> V_120 ) ;
if ( ! V_99 ) {
V_99 = V_111 -> V_120 . V_146 ;
F_51 ( V_46 , & V_33 -> V_47 ) ;
}
F_112 ( V_111 ) ;
V_139:
if ( V_99 )
F_20 ( V_34 L_31
L_32 , V_99 ) ;
}
static int
F_115 ( struct V_32 * V_33 )
{
int V_99 ;
struct V_110 * V_111 ;
struct V_43 * V_44 = F_23 ( V_33 -> V_36 , V_45 ) ;
struct V_115 * V_116 = V_44 -> V_115 ;
if ( F_50 ( V_46 , & V_33 -> V_47 ) )
return 0 ;
V_111 = F_110 ( V_116 ) ;
if ( ! V_111 ) {
F_20 ( V_34 L_33
L_34 , - V_4 ) ;
return - V_4 ;
}
V_111 -> V_120 . V_140 = V_148 ;
V_111 -> V_120 . V_142 . V_143 . V_144 = V_33 -> V_49 . V_23 ;
memcpy ( V_111 -> V_120 . V_142 . V_143 . V_145 , V_33 -> V_49 . V_24 ,
V_33 -> V_49 . V_23 ) ;
V_99 = F_83 ( V_116 -> V_127 , & V_111 -> V_120 ) ;
if ( ! V_99 ) {
V_99 = V_111 -> V_120 . V_146 ;
F_78 ( V_46 , & V_33 -> V_47 ) ;
}
F_112 ( V_111 ) ;
return V_99 ;
}
static void
F_116 ( struct V_43 * V_44 )
{
int V_99 ;
struct V_110 * V_111 ;
struct V_115 * V_116 = V_44 -> V_115 ;
V_111 = F_110 ( V_116 ) ;
if ( ! V_111 ) {
V_99 = - V_4 ;
goto V_139;
}
V_111 -> V_120 . V_140 = V_149 ;
V_111 -> V_120 . V_142 . V_150 = ( V_151 ) V_44 -> V_152 ;
V_99 = F_83 ( V_116 -> V_127 , & V_111 -> V_120 ) ;
if ( ! V_99 )
V_99 = V_111 -> V_120 . V_146 ;
F_112 ( V_111 ) ;
V_139:
if ( V_99 )
F_20 ( V_34 L_35 , V_99 ) ;
}
static char *
F_117 ( void )
{
int V_153 ;
T_6 V_23 ;
char * V_154 ;
if ( V_155 )
return NULL ;
V_23 = strlen ( V_156 ) +
strlen ( F_76 () ) + 1 ;
V_154 = F_14 ( V_23 , V_30 ) ;
if ( ! V_154 )
return V_154 ;
V_153 = snprintf ( V_154 , V_23 , V_156 L_36 ,
F_76 () ) ;
if ( V_153 >= V_23 ) {
F_17 ( V_154 ) ;
return NULL ;
}
return V_154 ;
}
static char *
F_118 ( const struct V_15 * V_61 )
{
int V_153 ;
T_6 V_23 ;
char * V_154 ;
if ( V_155 )
return NULL ;
V_23 = strlen ( V_157 ) +
strlen ( F_76 () ) + 1 + V_38 ;
V_154 = F_14 ( V_23 , V_30 ) ;
if ( ! V_154 )
return V_154 ;
V_153 = snprintf ( V_154 , V_23 , V_157 L_37 ,
F_76 () ) ;
if ( V_153 > ( V_23 - V_38 ) ) {
F_17 ( V_154 ) ;
return NULL ;
}
V_153 = F_8 ( V_154 + V_153 , V_61 ) ;
if ( V_153 ) {
F_17 ( V_154 ) ;
return NULL ;
}
return V_154 ;
}
static char *
F_119 ( struct V_32 * V_33 )
{
int V_153 ;
T_6 V_23 ;
char * V_154 ;
V_23 = strlen ( V_158 ) + 1 + 1 ;
V_154 = F_14 ( V_23 , V_30 ) ;
if ( ! V_154 )
return V_154 ;
V_153 = snprintf ( V_154 , V_23 , V_158 L_38 ,
V_33 -> V_159 ? 'Y' : 'N' ) ;
if ( V_153 >= V_23 ) {
F_17 ( V_154 ) ;
return NULL ;
}
return V_154 ;
}
static char *
F_120 ( T_8 V_160 )
{
int V_153 ;
T_6 V_23 ;
char * V_154 ;
V_23 = strlen ( V_161 ) + 22 + 1 ;
V_154 = F_14 ( V_23 , V_30 ) ;
if ( ! V_154 )
return V_154 ;
V_153 = snprintf ( V_154 , V_23 , V_161 L_39 ,
V_160 ) ;
if ( V_153 >= V_23 ) {
F_17 ( V_154 ) ;
return NULL ;
}
return V_154 ;
}
static int
F_121 ( char * V_162 , char * V_163 , char * V_164 , char * V_165 )
{
char * V_166 [ 3 ] ;
char * V_167 [ 4 ] ;
int V_99 ;
if ( F_122 ( ! V_168 [ 0 ] ) ) {
F_9 ( L_40 , V_77 ) ;
return - V_169 ;
}
F_9 ( L_41 , V_77 , V_162 ) ;
F_9 ( L_42 , V_77 , V_163 ? V_163 : L_43 ) ;
F_9 ( L_44 , V_77 , V_164 ? V_164 : L_43 ) ;
F_9 ( L_45 , V_77 , V_165 ? V_165 : L_43 ) ;
V_166 [ 0 ] = V_164 ;
V_166 [ 1 ] = V_165 ;
V_166 [ 2 ] = NULL ;
V_167 [ 0 ] = ( char * ) V_168 ;
V_167 [ 1 ] = V_162 ;
V_167 [ 2 ] = V_163 ;
V_167 [ 3 ] = NULL ;
V_99 = F_123 ( V_167 [ 0 ] , V_167 , V_166 , V_170 ) ;
if ( V_99 == - V_35 || V_99 == - V_169 ) {
F_9 ( L_46
L_47 ,
V_168 , V_99 ) ;
V_168 [ 0 ] = '\0' ;
}
F_9 ( L_48 , V_77 , V_168 , V_99 ) ;
return V_99 ;
}
static char *
F_124 ( const unsigned char * V_108 , int V_171 )
{
int V_12 ;
char * V_172 , * V_173 ;
V_172 = F_14 ( ( V_171 * 2 ) + 1 , V_30 ) ;
if ( ! V_172 )
return V_172 ;
V_173 = V_172 ;
for ( V_12 = 0 ; V_12 < V_171 ; V_12 ++ ) {
sprintf ( V_173 , L_49 , * V_108 ++ ) ;
V_173 += 2 ;
}
return V_172 ;
}
static int
F_125 ( struct V_36 * V_36 )
{
int V_99 ;
struct V_43 * V_44 = F_23 ( V_36 , V_45 ) ;
char * V_160 = F_120 ( V_44 -> V_152 ) ;
if ( V_36 != & V_88 ) {
F_70 ( L_50 ) ;
return - V_89 ;
}
V_99 = F_121 ( L_51 , NULL , V_160 , NULL ) ;
F_17 ( V_160 ) ;
return V_99 ;
}
static void
F_126 ( struct V_32 * V_33 )
{
F_127 ( & V_33 -> V_47 , V_174 ,
V_102 ) ;
}
static void
F_128 ( struct V_32 * V_33 )
{
F_129 () ;
F_51 ( V_174 , & V_33 -> V_47 ) ;
F_130 () ;
F_131 ( & V_33 -> V_47 , V_174 ) ;
}
static void
F_132 ( struct V_32 * V_33 )
{
char * V_175 , * V_176 , * V_160 ;
struct V_43 * V_44 = F_23 ( V_33 -> V_36 , V_45 ) ;
if ( V_33 -> V_159 == 0 &&
F_50 ( V_46 , & V_33 -> V_47 ) )
return;
V_175 = F_124 ( V_33 -> V_49 . V_24 , V_33 -> V_49 . V_23 ) ;
if ( ! V_175 ) {
F_9 ( L_52 , V_77 ) ;
return;
}
V_176 = F_119 ( V_33 ) ;
V_160 = F_120 ( V_44 -> V_152 ) ;
F_126 ( V_33 ) ;
if ( ! F_121 ( L_53 , V_175 , V_176 , V_160 ) )
F_78 ( V_46 , & V_33 -> V_47 ) ;
F_128 ( V_33 ) ;
F_17 ( V_176 ) ;
F_17 ( V_160 ) ;
F_17 ( V_175 ) ;
}
static void
F_133 ( struct V_32 * V_33 )
{
char * V_175 ;
if ( ! F_50 ( V_46 , & V_33 -> V_47 ) )
return;
V_175 = F_124 ( V_33 -> V_49 . V_24 , V_33 -> V_49 . V_23 ) ;
if ( ! V_175 ) {
F_9 ( L_52 , V_77 ) ;
return;
}
F_126 ( V_33 ) ;
if ( F_50 ( V_46 , & V_33 -> V_47 ) &&
F_121 ( L_54 , V_175 , NULL , NULL ) == 0 )
F_51 ( V_46 , & V_33 -> V_47 ) ;
F_128 ( V_33 ) ;
F_17 ( V_175 ) ;
}
static int
F_134 ( struct V_32 * V_33 )
{
int V_99 ;
char * V_175 , * V_176 , * V_177 ;
if ( F_50 ( V_46 , & V_33 -> V_47 ) )
return 0 ;
V_175 = F_124 ( V_33 -> V_49 . V_24 , V_33 -> V_49 . V_23 ) ;
if ( ! V_175 ) {
F_9 ( L_52 , V_77 ) ;
return - V_4 ;
}
V_176 = F_119 ( V_33 ) ;
V_177 = F_118 ( & V_33 -> V_49 ) ;
F_126 ( V_33 ) ;
if ( F_50 ( V_46 , & V_33 -> V_47 ) ) {
V_99 = 0 ;
} else {
V_99 = F_121 ( L_55 , V_175 , V_176 , V_177 ) ;
if ( V_99 == 0 )
F_78 ( V_46 , & V_33 -> V_47 ) ;
}
F_128 ( V_33 ) ;
F_17 ( V_176 ) ;
F_17 ( V_177 ) ;
F_17 ( V_175 ) ;
return V_99 ;
}
static void
F_135 ( struct V_43 * V_44 )
{
char * V_177 ;
char V_178 [ 22 ] ;
sprintf ( V_178 , L_39 , V_44 -> V_152 ) ;
V_177 = F_117 () ;
F_121 ( L_56 , V_178 , V_177 , NULL ) ;
F_17 ( V_177 ) ;
}
int
F_136 ( struct V_36 * V_36 )
{
int V_22 ;
struct V_92 V_92 ;
struct V_43 * V_44 = F_23 ( V_36 , V_45 ) ;
if ( V_44 -> V_179 )
goto V_180;
V_44 -> V_179 = & V_181 ;
V_22 = V_44 -> V_179 -> V_182 ( V_36 ) ;
if ( ! V_22 )
return V_22 ;
V_44 -> V_179 = & V_183 ;
V_22 = F_73 ( F_76 () , V_93 , & V_92 ) ;
if ( ! V_22 ) {
V_22 = F_74 ( V_92 . V_39 ) ;
F_75 ( & V_92 ) ;
if ( V_22 )
goto V_180;
}
V_44 -> V_179 = & V_184 ;
F_20 ( V_185 L_57
L_58
L_59 ) ;
V_180:
V_22 = V_44 -> V_179 -> V_182 ( V_36 ) ;
if ( V_22 ) {
F_20 ( V_185 L_60
L_61 , V_22 ) ;
V_44 -> V_179 = NULL ;
}
return V_22 ;
}
void
F_21 ( struct V_36 * V_36 )
{
struct V_43 * V_44 = F_23 ( V_36 , V_45 ) ;
if ( V_44 -> V_179 ) {
if ( V_44 -> V_179 -> exit )
V_44 -> V_179 -> exit ( V_36 ) ;
V_44 -> V_179 = NULL ;
}
}
void
F_137 ( struct V_32 * V_33 )
{
struct V_43 * V_44 = F_23 ( V_33 -> V_36 , V_45 ) ;
if ( V_44 -> V_179 )
V_44 -> V_179 -> V_186 ( V_33 ) ;
}
void
F_138 ( struct V_32 * V_33 )
{
struct V_43 * V_44 = F_23 ( V_33 -> V_36 , V_45 ) ;
if ( V_44 -> V_179 )
V_44 -> V_179 -> remove ( V_33 ) ;
}
int
F_139 ( struct V_32 * V_33 )
{
struct V_43 * V_44 = F_23 ( V_33 -> V_36 , V_45 ) ;
if ( V_44 -> V_179 )
return V_44 -> V_179 -> V_187 ( V_33 ) ;
return - V_188 ;
}
void
F_140 ( struct V_43 * V_44 )
{
if ( V_44 -> V_179 )
V_44 -> V_179 -> V_189 ( V_44 ) ;
}
static int
F_141 ( struct V_190 * V_191 , unsigned long V_192 , void * V_193 )
{
struct V_123 * V_124 = V_193 ;
struct V_36 * V_36 = V_124 -> V_114 ;
struct V_43 * V_44 = F_23 ( V_36 , V_45 ) ;
struct V_115 * V_116 = V_44 -> V_115 ;
struct V_39 * V_39 ;
int V_99 = 0 ;
if ( ! F_142 ( V_194 ) )
return 0 ;
if ( ! V_116 ) {
F_143 ( V_194 ) ;
return 0 ;
}
switch ( V_192 ) {
case V_195 :
V_39 = F_94 ( V_124 , V_116 -> V_127 ) ;
if ( F_11 ( V_39 ) ) {
V_99 = F_12 ( V_39 ) ;
break;
}
V_116 -> V_127 -> V_39 = V_39 ;
break;
case V_196 :
if ( V_116 -> V_127 -> V_39 )
F_98 ( V_116 -> V_127 ) ;
break;
default:
V_99 = - V_197 ;
break;
}
F_143 ( V_194 ) ;
return V_99 ;
}
int
F_144 ( void )
{
return F_145 ( & V_198 ) ;
}
void
F_146 ( void )
{
F_147 ( & V_198 ) ;
}
