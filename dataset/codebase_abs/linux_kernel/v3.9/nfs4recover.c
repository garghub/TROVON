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
F_19 ( int error )
{
F_20 ( V_32 L_3
L_4 , error ) ;
if ( error == - V_33 ) {
F_20 ( V_32 L_5
L_6 ) ;
F_21 ( NULL ) ;
}
}
static void
F_22 ( struct V_34 * V_35 )
{
const struct V_1 * V_36 ;
char V_14 [ V_37 ] ;
struct V_38 * V_39 , * V_38 ;
struct V_40 * V_41 ;
int V_22 ;
struct V_42 * V_43 = F_23 ( V_35 -> V_44 , V_45 ) ;
F_9 ( L_7 , V_14 ) ;
if ( F_24 ( V_46 , & V_35 -> V_47 ) )
return;
if ( ! V_43 -> V_48 )
return;
V_22 = F_8 ( V_14 , & V_35 -> V_49 ) ;
if ( V_22 )
return F_19 ( V_22 ) ;
V_22 = F_1 ( & V_36 ) ;
if ( V_22 < 0 )
return;
V_22 = F_25 ( V_43 -> V_48 ) ;
if ( V_22 )
return;
V_39 = V_43 -> V_48 -> V_50 . V_38 ;
F_26 ( & V_39 -> V_51 -> V_52 ) ;
V_38 = F_27 ( V_14 , V_39 , V_37 - 1 ) ;
if ( F_11 ( V_38 ) ) {
V_22 = F_12 ( V_38 ) ;
goto V_53;
}
if ( V_38 -> V_51 )
goto V_54;
V_22 = F_28 ( V_39 -> V_51 , V_38 , V_55 ) ;
V_54:
F_29 ( V_38 ) ;
V_53:
F_30 ( & V_39 -> V_51 -> V_52 ) ;
if ( V_22 == 0 ) {
if ( V_43 -> V_56 ) {
V_41 = F_31 ( V_14 , V_43 ) ;
if ( V_41 )
V_41 -> V_57 = V_35 ;
}
F_32 ( V_43 -> V_48 , 0 ) ;
} else {
F_20 ( V_32 L_8
L_9
L_10 , V_22 ,
V_58 ) ;
}
F_33 ( V_43 -> V_48 ) ;
F_5 ( V_36 ) ;
}
static int
F_34 ( void * V_59 , const char * V_60 , int V_61 ,
T_1 V_62 , T_2 V_63 , unsigned int V_64 )
{
struct V_65 * V_66 = V_59 ;
struct V_67 * V_68 ;
if ( V_61 != V_37 - 1 )
return 0 ;
V_68 = F_14 ( sizeof( struct V_67 ) , V_30 ) ;
if ( V_68 == NULL )
return - V_4 ;
memcpy ( V_68 -> V_60 , V_60 , V_37 - 1 ) ;
V_68 -> V_60 [ V_37 - 1 ] = '\0' ;
F_35 ( & V_68 -> V_69 , V_66 ) ;
return 0 ;
}
static int
F_36 ( T_3 * V_70 , struct V_42 * V_43 )
{
const struct V_1 * V_36 ;
struct V_38 * V_39 = V_43 -> V_48 -> V_50 . V_38 ;
F_37 ( V_66 ) ;
int V_22 ;
V_22 = F_1 ( & V_36 ) ;
if ( V_22 < 0 )
return V_22 ;
V_22 = F_38 ( V_43 -> V_48 , 0 , V_71 ) ;
if ( V_22 < 0 ) {
F_5 ( V_36 ) ;
return V_22 ;
}
V_22 = F_39 ( V_43 -> V_48 , F_34 , & V_66 ) ;
F_40 ( & V_39 -> V_51 -> V_52 , V_72 ) ;
while ( ! F_41 ( & V_66 ) ) {
struct V_67 * V_68 ;
V_68 = F_42 ( V_66 . V_73 , struct V_67 , V_69 ) ;
if ( ! V_22 ) {
struct V_38 * V_38 ;
V_38 = F_27 ( V_68 -> V_60 , V_39 , V_37 - 1 ) ;
if ( F_11 ( V_38 ) ) {
V_22 = F_12 ( V_38 ) ;
break;
}
V_22 = V_70 ( V_39 , V_38 , V_43 ) ;
F_29 ( V_38 ) ;
}
F_43 ( & V_68 -> V_69 ) ;
F_17 ( V_68 ) ;
}
F_30 ( & V_39 -> V_51 -> V_52 ) ;
F_5 ( V_36 ) ;
return V_22 ;
}
static int
F_44 ( char * V_60 , int V_61 , struct V_42 * V_43 )
{
struct V_38 * V_39 , * V_38 ;
int V_22 ;
F_9 ( L_11 , V_61 , V_60 ) ;
V_39 = V_43 -> V_48 -> V_50 . V_38 ;
F_40 ( & V_39 -> V_51 -> V_52 , V_72 ) ;
V_38 = F_27 ( V_60 , V_39 , V_61 ) ;
if ( F_11 ( V_38 ) ) {
V_22 = F_12 ( V_38 ) ;
goto V_53;
}
V_22 = - V_33 ;
if ( ! V_38 -> V_51 )
goto V_10;
V_22 = F_45 ( V_39 -> V_51 , V_38 ) ;
V_10:
F_29 ( V_38 ) ;
V_53:
F_30 ( & V_39 -> V_51 -> V_52 ) ;
return V_22 ;
}
static void
F_46 ( struct V_34 * V_35 )
{
const struct V_1 * V_36 ;
struct V_40 * V_41 ;
char V_14 [ V_37 ] ;
int V_22 ;
struct V_42 * V_43 = F_23 ( V_35 -> V_44 , V_45 ) ;
if ( ! V_43 -> V_48 || ! F_47 ( V_46 , & V_35 -> V_47 ) )
return;
V_22 = F_8 ( V_14 , & V_35 -> V_49 ) ;
if ( V_22 )
return F_19 ( V_22 ) ;
V_22 = F_25 ( V_43 -> V_48 ) ;
if ( V_22 )
goto V_10;
F_48 ( V_46 , & V_35 -> V_47 ) ;
V_22 = F_1 ( & V_36 ) ;
if ( V_22 < 0 )
goto V_74;
V_22 = F_44 ( V_14 , V_37 - 1 , V_43 ) ;
F_5 ( V_36 ) ;
if ( V_22 == 0 ) {
F_32 ( V_43 -> V_48 , 0 ) ;
if ( V_43 -> V_56 ) {
V_41 = F_49 ( V_14 , V_43 ) ;
if ( V_41 )
F_50 ( V_41 , V_43 ) ;
}
}
V_74:
F_33 ( V_43 -> V_48 ) ;
V_10:
if ( V_22 )
F_20 ( L_12
L_13 , V_37 , V_14 ) ;
}
static int
F_51 ( struct V_38 * V_75 , struct V_38 * V_76 , struct V_42 * V_43 )
{
int V_22 ;
if ( F_52 ( V_76 -> V_77 . V_60 , V_43 ) )
return 0 ;
V_22 = F_45 ( V_75 -> V_51 , V_76 ) ;
if ( V_22 )
F_20 ( L_14 ,
V_76 -> V_77 . V_60 ) ;
return 0 ;
}
static void
F_53 ( struct V_42 * V_43 , T_4 V_78 )
{
int V_22 ;
V_43 -> V_56 = false ;
if ( ! V_43 -> V_48 )
return;
V_22 = F_25 ( V_43 -> V_48 ) ;
if ( V_22 )
goto V_10;
V_22 = F_36 ( F_51 , V_43 ) ;
if ( V_22 == 0 )
F_32 ( V_43 -> V_48 , 0 ) ;
F_33 ( V_43 -> V_48 ) ;
V_10:
F_54 ( V_43 ) ;
if ( V_22 )
F_20 ( L_15
L_16 , V_43 -> V_48 -> V_50 . V_38 -> V_77 . V_60 ) ;
}
static int
F_55 ( struct V_38 * V_75 , struct V_38 * V_76 , struct V_42 * V_43 )
{
if ( V_76 -> V_77 . V_23 != V_37 - 1 ) {
F_20 ( L_17 ,
V_76 -> V_77 . V_60 ) ;
return 0 ;
}
F_31 ( V_76 -> V_77 . V_60 , V_43 ) ;
return 0 ;
}
static int
F_56 ( struct V_44 * V_44 ) {
int V_22 ;
struct V_42 * V_43 = F_23 ( V_44 , V_45 ) ;
if ( ! V_43 -> V_48 )
return 0 ;
V_22 = F_36 ( F_55 , V_43 ) ;
if ( V_22 )
F_20 ( L_18
L_16 , V_43 -> V_48 -> V_50 . V_38 -> V_77 . V_60 ) ;
return V_22 ;
}
static int
F_57 ( struct V_44 * V_44 )
{
struct V_42 * V_43 = F_23 ( V_44 , V_45 ) ;
const struct V_1 * V_36 ;
int V_22 ;
F_20 ( L_19 ,
V_58 ) ;
F_58 ( V_43 -> V_48 ) ;
V_22 = F_1 ( & V_36 ) ;
if ( V_22 < 0 ) {
F_20 ( L_20
L_21 ,
V_22 ) ;
return V_22 ;
}
V_43 -> V_48 = F_59 ( V_58 , V_79 | V_80 , 0 ) ;
if ( F_11 ( V_43 -> V_48 ) ) {
F_20 ( L_22 ,
V_58 ) ;
V_22 = F_12 ( V_43 -> V_48 ) ;
V_43 -> V_48 = NULL ;
}
F_5 ( V_36 ) ;
if ( ! V_22 )
V_43 -> V_56 = true ;
return V_22 ;
}
static int
F_60 ( struct V_44 * V_44 )
{
struct V_42 * V_43 = F_23 ( V_44 , V_45 ) ;
int V_12 ;
V_43 -> V_81 = F_14 ( sizeof( struct V_65 ) *
V_82 , V_30 ) ;
if ( ! V_43 -> V_81 )
return - V_4 ;
for ( V_12 = 0 ; V_12 < V_82 ; V_12 ++ )
F_61 ( & V_43 -> V_81 [ V_12 ] ) ;
V_43 -> V_83 = 0 ;
return 0 ;
}
static void
F_62 ( struct V_44 * V_44 )
{
struct V_42 * V_43 = F_23 ( V_44 , V_45 ) ;
F_17 ( V_43 -> V_81 ) ;
}
static int
F_63 ( struct V_44 * V_44 )
{
int V_22 ;
V_22 = F_57 ( V_44 ) ;
if ( ! V_22 )
V_22 = F_56 ( V_44 ) ;
if ( V_22 )
F_20 ( V_32 L_23 ) ;
return V_22 ;
}
static int
F_64 ( struct V_44 * V_44 )
{
int V_22 ;
if ( V_44 != & V_84 ) {
F_65 ( 1 , V_32 L_24
L_25 ) ;
return - V_85 ;
}
V_22 = F_60 ( V_44 ) ;
if ( V_22 )
return V_22 ;
V_22 = F_63 ( V_44 ) ;
if ( V_22 )
goto V_86;
return 0 ;
V_86:
F_62 ( V_44 ) ;
return V_22 ;
}
static void
F_66 ( struct V_42 * V_43 )
{
if ( ! V_43 -> V_48 )
return;
F_67 ( V_43 -> V_48 ) ;
V_43 -> V_48 = NULL ;
}
static void
F_68 ( struct V_44 * V_44 )
{
struct V_42 * V_43 = F_23 ( V_44 , V_45 ) ;
F_54 ( V_43 ) ;
F_66 ( V_43 ) ;
F_62 ( V_44 ) ;
}
int
F_69 ( char * V_87 )
{
int V_22 ;
struct V_88 V_88 ;
V_22 = F_70 ( V_87 , V_89 , & V_88 ) ;
if ( V_22 )
return V_22 ;
V_22 = - V_90 ;
if ( F_71 ( V_88 . V_38 -> V_51 -> V_91 ) ) {
strcpy ( V_58 , V_87 ) ;
V_22 = 0 ;
}
F_72 ( & V_88 ) ;
return V_22 ;
}
char *
F_73 ( void )
{
return V_58 ;
}
static int
F_74 ( struct V_34 * V_35 )
{
int V_22 ;
char V_14 [ V_37 ] ;
struct V_40 * V_41 ;
struct V_42 * V_43 = F_23 ( V_35 -> V_44 , V_45 ) ;
if ( F_47 ( V_46 , & V_35 -> V_47 ) )
return 0 ;
V_22 = F_8 ( V_14 , & V_35 -> V_49 ) ;
if ( V_22 ) {
F_19 ( V_22 ) ;
return V_22 ;
}
V_41 = F_49 ( V_14 , V_43 ) ;
if ( V_41 ) {
F_75 ( V_46 , & V_35 -> V_47 ) ;
V_41 -> V_57 = V_35 ;
return 0 ;
}
return - V_33 ;
}
static int
F_76 ( struct V_92 * V_93 , struct V_94 * V_95 )
{
int V_96 ;
struct V_97 V_98 ;
memset ( & V_98 , 0 , sizeof( V_98 ) ) ;
V_98 . V_24 = V_95 ;
V_98 . V_23 = sizeof( * V_95 ) ;
F_77 ( V_99 ) ;
V_96 = F_78 ( V_93 , & V_98 ) ;
if ( V_96 < 0 ) {
F_77 ( V_100 ) ;
goto V_10;
}
F_79 () ;
F_77 ( V_100 ) ;
if ( V_98 . V_101 < 0 )
V_96 = V_98 . V_101 ;
V_10:
return V_96 ;
}
static int
F_80 ( struct V_92 * V_93 , struct V_94 * V_95 )
{
int V_96 ;
do {
V_96 = F_76 ( V_93 , V_95 ) ;
} while ( V_96 == - V_102 );
return V_96 ;
}
static T_5
F_81 ( struct V_103 * V_104 , const char T_6 * V_105 , T_7 V_106 )
{
struct V_107 * V_108 , * V_109 ;
struct V_94 T_6 * V_95 = (struct V_94 T_6 * ) V_105 ;
T_8 V_110 ;
struct V_42 * V_43 = F_23 ( V_104 -> V_111 -> V_112 -> V_113 ,
V_45 ) ;
struct V_114 * V_115 = V_43 -> V_114 ;
if ( V_106 != sizeof( * V_95 ) ) {
F_9 ( L_26 , V_116 , V_106 ,
sizeof( * V_95 ) ) ;
return - V_85 ;
}
if ( F_82 ( & V_110 , & V_95 -> V_117 , sizeof( V_110 ) ) != 0 ) {
F_9 ( L_27 , V_116 ) ;
return - V_118 ;
}
V_109 = NULL ;
F_83 ( & V_115 -> V_119 ) ;
F_84 (tmp, &cn->cn_list, cu_list) {
if ( F_85 ( & V_108 -> V_120 . V_117 ) == V_110 ) {
V_109 = V_108 ;
F_86 ( & V_109 -> V_121 ) ;
break;
}
}
F_87 ( & V_115 -> V_119 ) ;
if ( ! V_109 ) {
F_9 ( L_28 , V_116 , V_110 ) ;
return - V_85 ;
}
if ( F_82 ( & V_109 -> V_120 , V_105 , V_106 ) != 0 )
return - V_118 ;
F_88 ( V_109 -> V_122 ) ;
return V_106 ;
}
static void
F_89 ( struct V_97 * V_98 )
{
struct V_94 * V_95 = V_98 -> V_24 ;
struct V_107 * V_109 = F_90 ( V_95 , struct V_107 ,
V_120 ) ;
if ( V_98 -> V_101 >= 0 )
return;
F_88 ( V_109 -> V_122 ) ;
}
static struct V_38 *
F_91 ( struct V_123 * V_124 , struct V_92 * V_93 )
{
struct V_38 * V_39 , * V_38 ;
V_39 = F_92 ( V_124 , V_125 ) ;
if ( V_39 == NULL )
return F_93 ( - V_33 ) ;
V_38 = F_94 ( V_39 , V_126 , NULL , V_93 ) ;
F_29 ( V_39 ) ;
return V_38 ;
}
static void
F_95 ( struct V_92 * V_93 )
{
if ( V_93 -> V_38 )
F_96 ( V_93 -> V_38 ) ;
}
static struct V_38 *
F_97 ( struct V_44 * V_44 , struct V_92 * V_93 )
{
struct V_123 * V_124 ;
struct V_38 * V_38 ;
V_124 = F_98 ( V_44 ) ;
if ( ! V_124 )
return NULL ;
V_38 = F_91 ( V_124 , V_93 ) ;
F_99 ( V_44 ) ;
return V_38 ;
}
static void
F_100 ( struct V_44 * V_44 , struct V_92 * V_93 )
{
struct V_123 * V_124 ;
V_124 = F_98 ( V_44 ) ;
if ( V_124 ) {
F_95 ( V_93 ) ;
F_99 ( V_44 ) ;
}
}
static int
F_101 ( struct V_44 * V_44 )
{
int V_96 ;
struct V_38 * V_38 ;
struct V_42 * V_43 = F_23 ( V_44 , V_45 ) ;
struct V_114 * V_115 ;
if ( V_43 -> V_114 )
return 0 ;
V_115 = F_102 ( sizeof( * V_115 ) , V_30 ) ;
if ( ! V_115 ) {
V_96 = - V_4 ;
goto V_86;
}
V_115 -> V_127 = F_103 ( & V_128 , V_129 ) ;
if ( F_11 ( V_115 -> V_127 ) ) {
V_96 = F_12 ( V_115 -> V_127 ) ;
goto V_86;
}
F_104 ( & V_115 -> V_119 ) ;
F_61 ( & V_115 -> V_130 ) ;
V_38 = F_97 ( V_44 , V_115 -> V_127 ) ;
if ( F_11 ( V_38 ) ) {
V_96 = F_12 ( V_38 ) ;
goto V_131;
}
V_115 -> V_127 -> V_38 = V_38 ;
V_43 -> V_114 = V_115 ;
return 0 ;
V_131:
F_105 ( V_115 -> V_127 ) ;
V_86:
F_17 ( V_115 ) ;
F_20 ( V_32 L_29 ,
V_96 ) ;
return V_96 ;
}
static void
F_106 ( struct V_44 * V_44 )
{
struct V_42 * V_43 = F_23 ( V_44 , V_45 ) ;
struct V_114 * V_115 = V_43 -> V_114 ;
F_100 ( V_44 , V_115 -> V_127 ) ;
F_105 ( V_115 -> V_127 ) ;
F_17 ( V_43 -> V_114 ) ;
V_43 -> V_114 = NULL ;
}
static struct V_107 *
F_107 ( struct V_114 * V_115 )
{
struct V_107 * V_3 , * V_108 ;
V_3 = F_102 ( sizeof( * V_3 ) , V_30 ) ;
if ( ! V_3 )
return V_3 ;
V_132:
F_83 ( & V_115 -> V_119 ) ;
F_84 (tmp, &cn->cn_list, cu_list) {
if ( V_108 -> V_120 . V_117 == V_115 -> V_133 ) {
V_115 -> V_133 ++ ;
F_87 ( & V_115 -> V_119 ) ;
goto V_132;
}
}
V_3 -> V_122 = V_134 ;
V_3 -> V_120 . V_135 = V_136 ;
F_108 ( V_115 -> V_133 ++ , & V_3 -> V_120 . V_117 ) ;
V_3 -> V_137 = V_115 ;
F_35 ( & V_3 -> V_121 , & V_115 -> V_130 ) ;
F_87 ( & V_115 -> V_119 ) ;
F_9 ( L_30 , V_116 , V_3 -> V_120 . V_117 ) ;
return V_3 ;
}
static void
F_109 ( struct V_107 * V_138 )
{
struct V_114 * V_115 = V_138 -> V_137 ;
F_83 ( & V_115 -> V_119 ) ;
F_43 ( & V_138 -> V_121 ) ;
F_87 ( & V_115 -> V_119 ) ;
F_17 ( V_138 ) ;
}
static void
F_110 ( struct V_34 * V_35 )
{
int V_96 ;
struct V_107 * V_109 ;
struct V_42 * V_43 = F_23 ( V_35 -> V_44 , V_45 ) ;
struct V_114 * V_115 = V_43 -> V_114 ;
if ( F_47 ( V_46 , & V_35 -> V_47 ) )
return;
V_109 = F_107 ( V_115 ) ;
if ( ! V_109 ) {
V_96 = - V_4 ;
goto V_139;
}
V_109 -> V_120 . V_140 = V_141 ;
V_109 -> V_120 . V_142 . V_143 . V_144 = V_35 -> V_49 . V_23 ;
memcpy ( V_109 -> V_120 . V_142 . V_143 . V_145 , V_35 -> V_49 . V_24 ,
V_35 -> V_49 . V_23 ) ;
V_96 = F_80 ( V_115 -> V_127 , & V_109 -> V_120 ) ;
if ( ! V_96 ) {
V_96 = V_109 -> V_120 . V_146 ;
F_75 ( V_46 , & V_35 -> V_47 ) ;
}
F_109 ( V_109 ) ;
V_139:
if ( V_96 )
F_20 ( V_32 L_31
L_32 , V_96 ) ;
}
static void
F_111 ( struct V_34 * V_35 )
{
int V_96 ;
struct V_107 * V_109 ;
struct V_42 * V_43 = F_23 ( V_35 -> V_44 , V_45 ) ;
struct V_114 * V_115 = V_43 -> V_114 ;
if ( ! F_47 ( V_46 , & V_35 -> V_47 ) )
return;
V_109 = F_107 ( V_115 ) ;
if ( ! V_109 ) {
V_96 = - V_4 ;
goto V_139;
}
V_109 -> V_120 . V_140 = V_147 ;
V_109 -> V_120 . V_142 . V_143 . V_144 = V_35 -> V_49 . V_23 ;
memcpy ( V_109 -> V_120 . V_142 . V_143 . V_145 , V_35 -> V_49 . V_24 ,
V_35 -> V_49 . V_23 ) ;
V_96 = F_80 ( V_115 -> V_127 , & V_109 -> V_120 ) ;
if ( ! V_96 ) {
V_96 = V_109 -> V_120 . V_146 ;
F_48 ( V_46 , & V_35 -> V_47 ) ;
}
F_109 ( V_109 ) ;
V_139:
if ( V_96 )
F_20 ( V_32 L_33
L_34 , V_96 ) ;
}
static int
F_112 ( struct V_34 * V_35 )
{
int V_96 ;
struct V_107 * V_109 ;
struct V_42 * V_43 = F_23 ( V_35 -> V_44 , V_45 ) ;
struct V_114 * V_115 = V_43 -> V_114 ;
if ( F_47 ( V_46 , & V_35 -> V_47 ) )
return 0 ;
V_109 = F_107 ( V_115 ) ;
if ( ! V_109 ) {
F_20 ( V_32 L_35
L_36 , - V_4 ) ;
return - V_4 ;
}
V_109 -> V_120 . V_140 = V_148 ;
V_109 -> V_120 . V_142 . V_143 . V_144 = V_35 -> V_49 . V_23 ;
memcpy ( V_109 -> V_120 . V_142 . V_143 . V_145 , V_35 -> V_49 . V_24 ,
V_35 -> V_49 . V_23 ) ;
V_96 = F_80 ( V_115 -> V_127 , & V_109 -> V_120 ) ;
if ( ! V_96 ) {
V_96 = V_109 -> V_120 . V_146 ;
F_75 ( V_46 , & V_35 -> V_47 ) ;
}
F_109 ( V_109 ) ;
return V_96 ;
}
static void
F_113 ( struct V_42 * V_43 , T_4 V_78 )
{
int V_96 ;
struct V_107 * V_109 ;
struct V_114 * V_115 = V_43 -> V_114 ;
V_109 = F_107 ( V_115 ) ;
if ( ! V_109 ) {
V_96 = - V_4 ;
goto V_139;
}
V_109 -> V_120 . V_140 = V_149 ;
V_109 -> V_120 . V_142 . V_150 = ( V_151 ) V_78 ;
V_96 = F_80 ( V_115 -> V_127 , & V_109 -> V_120 ) ;
if ( ! V_96 )
V_96 = V_109 -> V_120 . V_146 ;
F_109 ( V_109 ) ;
V_139:
if ( V_96 )
F_20 ( V_32 L_37 , V_96 ) ;
}
static char *
F_114 ( void )
{
int V_152 ;
T_7 V_23 ;
char * V_153 ;
if ( V_154 )
return NULL ;
V_23 = strlen ( V_155 ) +
strlen ( F_73 () ) + 1 ;
V_153 = F_14 ( V_23 , V_30 ) ;
if ( ! V_153 )
return V_153 ;
V_152 = snprintf ( V_153 , V_23 , V_155 L_38 ,
F_73 () ) ;
if ( V_152 >= V_23 ) {
F_17 ( V_153 ) ;
return NULL ;
}
return V_153 ;
}
static char *
F_115 ( const struct V_15 * V_60 )
{
int V_152 ;
T_7 V_23 ;
char * V_153 ;
if ( V_154 )
return NULL ;
V_23 = strlen ( V_156 ) +
strlen ( F_73 () ) + 1 + V_37 ;
V_153 = F_14 ( V_23 , V_30 ) ;
if ( ! V_153 )
return V_153 ;
V_152 = snprintf ( V_153 , V_23 , V_156 L_39 ,
F_73 () ) ;
if ( V_152 > ( V_23 - V_37 ) ) {
F_17 ( V_153 ) ;
return NULL ;
}
V_152 = F_8 ( V_153 + V_152 , V_60 ) ;
if ( V_152 ) {
F_17 ( V_153 ) ;
return NULL ;
}
return V_153 ;
}
static int
F_116 ( char * V_157 , char * V_59 , char * V_158 )
{
char * V_159 [ 2 ] ;
char * V_160 [ 4 ] ;
int V_96 ;
if ( F_117 ( ! V_161 [ 0 ] ) ) {
F_9 ( L_40 , V_116 ) ;
return - V_162 ;
}
F_9 ( L_41 , V_116 , V_157 ) ;
F_9 ( L_42 , V_116 , V_59 ? V_59 : L_43 ) ;
F_9 ( L_44 , V_116 , V_158 ? V_158 : L_43 ) ;
V_159 [ 0 ] = V_158 ;
V_159 [ 1 ] = NULL ;
V_160 [ 0 ] = ( char * ) V_161 ;
V_160 [ 1 ] = V_157 ;
V_160 [ 2 ] = V_59 ;
V_160 [ 3 ] = NULL ;
V_96 = F_118 ( V_160 [ 0 ] , V_160 , V_159 , V_163 ) ;
if ( V_96 == - V_33 || V_96 == - V_162 ) {
F_9 ( L_45
L_46 ,
V_161 , V_96 ) ;
V_161 [ 0 ] = '\0' ;
}
F_9 ( L_47 , V_116 , V_161 , V_96 ) ;
return V_96 ;
}
static char *
F_119 ( const unsigned char * V_105 , int V_164 )
{
int V_12 ;
char * V_165 , * V_166 ;
V_165 = F_14 ( ( V_164 * 2 ) + 1 , V_30 ) ;
if ( ! V_165 )
return V_165 ;
V_166 = V_165 ;
for ( V_12 = 0 ; V_12 < V_164 ; V_12 ++ ) {
sprintf ( V_166 , L_48 , * V_105 ++ ) ;
V_166 += 2 ;
}
return V_165 ;
}
static void
F_120 ( struct V_34 * V_35 )
{
char * V_167 ;
V_167 = F_119 ( V_35 -> V_49 . V_24 , V_35 -> V_49 . V_23 ) ;
if ( ! V_167 ) {
F_9 ( L_49 , V_116 ) ;
return;
}
F_116 ( L_50 , V_167 , NULL ) ;
F_17 ( V_167 ) ;
}
static void
F_121 ( struct V_34 * V_35 )
{
char * V_167 ;
V_167 = F_119 ( V_35 -> V_49 . V_24 , V_35 -> V_49 . V_23 ) ;
if ( ! V_167 ) {
F_9 ( L_49 , V_116 ) ;
return;
}
F_116 ( L_51 , V_167 , NULL ) ;
F_17 ( V_167 ) ;
}
static int
F_122 ( struct V_34 * V_35 )
{
int V_96 ;
char * V_167 , * V_158 ;
V_167 = F_119 ( V_35 -> V_49 . V_24 , V_35 -> V_49 . V_23 ) ;
if ( ! V_167 ) {
F_9 ( L_49 , V_116 ) ;
return - V_4 ;
}
V_158 = F_115 ( & V_35 -> V_49 ) ;
V_96 = F_116 ( L_52 , V_167 , V_158 ) ;
F_17 ( V_158 ) ;
F_17 ( V_167 ) ;
return V_96 ;
}
int
F_123 ( struct V_44 * V_44 )
{
int V_22 ;
struct V_88 V_88 ;
struct V_42 * V_43 = F_23 ( V_44 , V_45 ) ;
if ( V_43 -> V_168 )
goto V_169;
V_43 -> V_168 = & V_170 ;
V_22 = V_43 -> V_168 -> V_171 ( V_44 ) ;
if ( ! V_22 )
return V_22 ;
V_43 -> V_168 = & V_172 ;
V_22 = F_70 ( F_73 () , V_89 , & V_88 ) ;
if ( ! V_22 ) {
V_22 = F_71 ( V_88 . V_38 -> V_51 -> V_91 ) ;
F_72 ( & V_88 ) ;
if ( V_22 )
goto V_169;
}
V_43 -> V_168 = & V_173 ;
F_20 ( V_174 L_53
L_54
L_55 ) ;
V_169:
V_22 = V_43 -> V_168 -> V_171 ( V_44 ) ;
if ( V_22 ) {
F_20 ( V_174 L_56
L_57 , V_22 ) ;
V_43 -> V_168 = NULL ;
}
return V_22 ;
}
void
F_21 ( struct V_44 * V_44 )
{
struct V_42 * V_43 = F_23 ( V_44 , V_45 ) ;
if ( V_43 -> V_168 ) {
if ( V_43 -> V_168 -> exit )
V_43 -> V_168 -> exit ( V_44 ) ;
V_43 -> V_168 = NULL ;
}
}
void
F_124 ( struct V_34 * V_35 )
{
struct V_42 * V_43 = F_23 ( V_35 -> V_44 , V_45 ) ;
if ( V_43 -> V_168 )
V_43 -> V_168 -> V_175 ( V_35 ) ;
}
void
F_125 ( struct V_34 * V_35 )
{
struct V_42 * V_43 = F_23 ( V_35 -> V_44 , V_45 ) ;
if ( V_43 -> V_168 )
V_43 -> V_168 -> remove ( V_35 ) ;
}
int
F_126 ( struct V_34 * V_35 )
{
struct V_42 * V_43 = F_23 ( V_35 -> V_44 , V_45 ) ;
if ( V_43 -> V_168 )
return V_43 -> V_168 -> V_176 ( V_35 ) ;
return - V_177 ;
}
void
F_127 ( struct V_42 * V_43 , T_4 V_78 )
{
if ( V_43 -> V_168 )
V_43 -> V_168 -> V_178 ( V_43 , V_78 ) ;
}
static int
F_128 ( struct V_179 * V_180 , unsigned long V_181 , void * V_182 )
{
struct V_123 * V_124 = V_182 ;
struct V_44 * V_44 = V_124 -> V_113 ;
struct V_42 * V_43 = F_23 ( V_44 , V_45 ) ;
struct V_114 * V_115 = V_43 -> V_114 ;
struct V_38 * V_38 ;
int V_96 = 0 ;
if ( ! F_129 ( V_183 ) )
return 0 ;
if ( ! V_115 ) {
F_130 ( V_183 ) ;
return 0 ;
}
switch ( V_181 ) {
case V_184 :
V_38 = F_91 ( V_124 , V_115 -> V_127 ) ;
if ( F_11 ( V_38 ) ) {
V_96 = F_12 ( V_38 ) ;
break;
}
V_115 -> V_127 -> V_38 = V_38 ;
break;
case V_185 :
if ( V_115 -> V_127 -> V_38 )
F_95 ( V_115 -> V_127 ) ;
break;
default:
V_96 = - V_186 ;
break;
}
F_130 ( V_183 ) ;
return V_96 ;
}
int
F_131 ( void )
{
return F_132 ( & V_187 ) ;
}
void
F_133 ( void )
{
F_134 ( & V_187 ) ;
}
