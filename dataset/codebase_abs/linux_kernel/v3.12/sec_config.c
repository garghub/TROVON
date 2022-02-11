const char * F_1 ( enum V_1 V_2 )
{
switch ( V_2 ) {
case V_3 :
return L_1 ;
case V_4 :
return L_2 ;
case V_5 :
return L_3 ;
case V_6 :
return L_4 ;
case V_7 :
return L_5 ;
case V_8 :
return L_6 ;
default:
return L_7 ;
}
}
enum V_1 F_2 ( struct V_9 * V_10 )
{
const char * type = V_10 -> V_11 -> V_12 ;
if ( ! strcmp ( type , V_13 ) )
return V_4 ;
if ( ! strcmp ( type , V_14 ) )
return V_5 ;
if ( ! strcmp ( type , V_15 ) )
return V_7 ;
F_3 ( L_8 , V_10 , type ) ;
return V_8 ;
}
int F_4 ( const char * V_16 , struct V_17 * V_18 )
{
char V_19 [ 32 ] ;
char * V_20 , * V_21 ;
memset ( V_18 , 0 , sizeof( * V_18 ) ) ;
if ( V_16 == NULL || V_16 [ 0 ] == '\0' ) {
V_18 -> V_22 = V_23 ;
return 0 ;
}
strncpy ( V_19 , V_16 , sizeof( V_19 ) ) ;
V_19 [ sizeof( V_19 ) - 1 ] = '\0' ;
V_20 = strchr ( V_19 , '-' ) ;
if ( V_20 )
* V_20 ++ = '\0' ;
V_18 -> V_22 = F_5 ( V_19 ) ;
if ( V_18 -> V_22 == V_23 )
goto V_24;
if ( V_18 -> V_22 == V_25 ) {
V_18 -> V_26 . V_27 . V_28 = V_29 ;
if ( V_20 ) {
V_21 = strchr ( V_20 , ':' ) ;
if ( V_21 == NULL )
goto V_24;
* V_21 ++ = '\0' ;
if ( strcmp ( V_20 , L_9 ) )
goto V_24;
V_18 -> V_26 . V_27 . V_28 = F_6 ( V_21 ) ;
if ( V_18 -> V_26 . V_27 . V_28 >= V_30 )
goto V_24;
}
if ( V_18 -> V_26 . V_27 . V_28 == V_31 )
F_7 ( & V_18 -> V_22 , V_32 ) ;
else
F_7 ( & V_18 -> V_22 , V_33 ) ;
} else {
if ( V_20 )
goto V_24;
}
V_18 -> V_34 = 0 ;
return 0 ;
V_24:
F_3 ( L_10 , V_16 ) ;
return - V_35 ;
}
static void F_8 ( struct V_17 * V_36 )
{
memset ( V_36 , 0 , sizeof( * V_36 ) ) ;
V_36 -> V_22 = V_37 ;
V_36 -> V_34 = 0 ;
}
static void F_9 ( struct V_38 * V_39 )
{
V_39 -> V_40 = F_10 ( V_41 ) ;
V_39 -> V_42 = V_8 ;
V_39 -> V_43 = V_8 ;
V_39 -> V_44 = 0 ;
F_8 ( & V_39 -> V_45 ) ;
}
int F_11 ( char * V_46 , struct V_38 * V_39 )
{
char * V_47 , * V_48 ;
int V_49 ;
F_9 ( V_39 ) ;
V_47 = strchr ( V_46 , '=' ) ;
if ( V_47 == NULL ) {
F_3 ( L_11 ) ;
return - V_35 ;
}
* V_47 ++ = '\0' ;
V_48 = strchr ( V_46 , '.' ) ;
if ( V_48 )
* V_48 ++ = '\0' ;
if ( strcmp ( V_46 , L_12 ) ) {
V_39 -> V_40 = F_12 ( V_46 ) ;
if ( V_39 -> V_40 == F_10 ( V_41 ) ) {
F_3 ( L_13 , V_46 ) ;
return - V_35 ;
}
}
if ( V_48 ) {
if ( ! strcmp ( V_48 , L_14 ) ) {
V_39 -> V_42 = V_4 ;
V_39 -> V_43 = V_5 ;
} else if ( ! strcmp ( V_48 , L_15 ) ) {
V_39 -> V_42 = V_4 ;
V_39 -> V_43 = V_4 ;
} else if ( ! strcmp ( V_48 , L_16 ) ) {
V_39 -> V_42 = V_3 ;
V_39 -> V_43 = V_5 ;
} else if ( ! strcmp ( V_48 , L_17 ) ) {
V_39 -> V_42 = V_3 ;
V_39 -> V_43 = V_4 ;
} else {
F_3 ( L_18 , V_48 ) ;
return - V_35 ;
}
}
V_49 = F_4 ( V_47 , & V_39 -> V_45 ) ;
if ( V_49 )
return - V_35 ;
return 0 ;
}
void F_13 ( struct V_50 * V_51 )
{
F_14 ( V_51 -> V_52 ||
( V_51 -> V_53 == 0 && V_51 -> V_54 == NULL ) ) ;
if ( V_51 -> V_52 ) {
F_15 ( V_51 -> V_54 ,
V_51 -> V_52 * sizeof( * V_51 -> V_54 ) ) ;
F_16 ( V_51 ) ;
}
}
int F_17 ( struct V_50 * V_51 )
{
struct V_38 * V_55 ;
int V_56 ;
F_18 () ;
if ( V_51 -> V_53 < V_51 -> V_52 )
return 0 ;
V_56 = V_51 -> V_52 + 8 ;
F_19 ( V_55 , V_56 * sizeof( * V_51 -> V_54 ) ) ;
if ( V_55 == NULL )
return - V_57 ;
if ( V_51 -> V_53 ) {
F_14 ( V_51 -> V_52 && V_51 -> V_54 ) ;
memcpy ( V_55 , V_51 -> V_54 ,
V_51 -> V_53 * sizeof( * V_51 -> V_54 ) ) ;
F_15 ( V_51 -> V_54 ,
V_51 -> V_52 * sizeof( * V_51 -> V_54 ) ) ;
}
V_51 -> V_54 = V_55 ;
V_51 -> V_52 = V_56 ;
return 0 ;
}
static inline int F_20 ( struct V_38 * V_39 )
{
return ( V_39 -> V_42 != V_8 ||
V_39 -> V_43 != V_8 ) ;
}
static inline int F_21 ( struct V_38 * V_39 )
{
return ( V_39 -> V_40 != F_10 ( V_41 ) ) ;
}
static inline int F_22 ( struct V_38 * V_58 ,
struct V_38 * V_59 )
{
return ( V_58 -> V_42 == V_59 -> V_42 && V_58 -> V_43 == V_59 -> V_43 ) ;
}
static inline int F_23 ( struct V_38 * V_58 ,
struct V_38 * V_59 )
{
return ( V_58 -> V_40 == V_59 -> V_40 ) ;
}
int F_24 ( struct V_50 * V_51 ,
struct V_38 * V_39 )
{
struct V_38 * V_60 = V_51 -> V_54 ;
int V_61 , V_62 ;
int V_49 , V_63 , V_64 = 0 ;
F_18 () ;
V_62 = F_21 ( V_39 ) ;
V_61 = F_20 ( V_39 ) ;
for ( V_63 = 0 ; V_63 < V_51 -> V_53 ; V_63 ++ ) {
V_60 = & V_51 -> V_54 [ V_63 ] ;
if ( ! F_23 ( V_60 , V_39 ) ) {
if ( V_62 ) {
if ( F_21 ( V_60 ) )
continue;
else
break;
} else {
continue;
}
}
if ( ! F_22 ( V_60 , V_39 ) ) {
if ( V_61 ) {
if ( F_20 ( V_60 ) )
continue;
else
break;
} else {
continue;
}
}
V_64 = 1 ;
break;
}
if ( V_64 ) {
F_14 ( V_63 >= 0 && V_63 < V_51 -> V_53 ) ;
if ( V_39 -> V_45 . V_22 == V_23 ) {
if ( V_63 < V_51 -> V_53 - 1 )
memmove ( & V_51 -> V_54 [ V_63 ] ,
& V_51 -> V_54 [ V_63 + 1 ] ,
( V_51 -> V_53 - V_63 - 1 ) *
sizeof( * V_39 ) ) ;
V_51 -> V_53 -- ;
} else {
memcpy ( & V_51 -> V_54 [ V_63 ] , V_39 , sizeof( * V_39 ) ) ;
}
} else {
F_14 ( V_63 >= 0 && V_63 <= V_51 -> V_53 ) ;
if ( V_39 -> V_45 . V_22 != V_23 ) {
V_49 = F_17 ( V_51 ) ;
if ( V_49 )
return V_49 ;
if ( V_63 < V_51 -> V_53 )
memmove ( & V_51 -> V_54 [ V_63 + 1 ] ,
& V_51 -> V_54 [ V_63 ] ,
( V_51 -> V_53 - V_63 ) * sizeof( * V_39 ) ) ;
memcpy ( & V_51 -> V_54 [ V_63 ] , V_39 , sizeof( * V_39 ) ) ;
V_51 -> V_53 ++ ;
} else {
F_25 ( V_65 , L_19 ) ;
}
}
return 0 ;
}
int F_26 ( struct V_50 * V_51 ,
enum V_1 V_66 ,
enum V_1 V_67 ,
T_1 V_68 ,
struct V_17 * V_36 )
{
struct V_38 * V_69 ;
int V_63 ;
for ( V_63 = 0 ; V_63 < V_51 -> V_53 ; V_63 ++ ) {
V_69 = & V_51 -> V_54 [ V_63 ] ;
if ( F_10 ( V_68 ) != F_10 ( V_41 ) &&
V_69 -> V_40 != F_10 ( V_41 ) &&
F_10 ( V_68 ) != V_69 -> V_40 )
continue;
if ( V_66 != V_8 && V_69 -> V_42 != V_8 &&
V_66 != V_69 -> V_42 )
continue;
if ( V_67 != V_8 && V_69 -> V_43 != V_8 &&
V_67 != V_69 -> V_43 )
continue;
* V_36 = V_69 -> V_45 ;
return 1 ;
}
return 0 ;
}
void F_27 ( struct V_50 * V_51 )
{
struct V_38 * V_69 ;
int V_63 ;
for ( V_63 = 0 ; V_63 < V_51 -> V_53 ; V_63 ++ ) {
V_69 = & V_51 -> V_54 [ V_63 ] ;
F_25 ( V_70 , L_20 , V_63 ,
V_69 -> V_42 , V_69 -> V_43 , V_69 -> V_40 , V_69 -> V_45 . V_22 ) ;
}
}
static int F_28 ( struct V_50 * V_71 ,
struct V_50 * V_72 ,
enum V_1 V_66 ,
enum V_1 V_67 ,
struct V_50 * V_51 )
{
struct V_50 * V_73 [ 2 ] = { V_71 , V_72 } ;
struct V_38 * V_39 ;
int V_74 , V_63 , V_49 ;
F_18 () ;
for ( V_74 = 0 ; V_74 < 2 ; V_74 ++ ) {
if ( V_73 [ V_74 ] == NULL )
continue;
for ( V_63 = 0 ; V_63 < V_73 [ V_74 ] -> V_53 ; V_63 ++ ) {
V_39 = & V_73 [ V_74 ] -> V_54 [ V_63 ] ;
if ( V_66 != V_8 &&
V_39 -> V_42 != V_8 &&
V_39 -> V_42 != V_66 )
continue;
if ( V_67 != V_8 &&
V_39 -> V_43 != V_8 &&
V_39 -> V_43 != V_67 )
continue;
V_49 = F_24 ( V_51 , V_39 ) ;
if ( V_49 ) {
F_3 ( L_21 , V_49 ) ;
return V_49 ;
}
}
}
return 0 ;
}
static inline int F_29 ( char V_75 )
{
return ( ( V_75 >= '0' && V_75 <= '9' ) ||
( V_75 >= 'a' && V_75 <= 'f' ) ) ;
}
static void F_30 ( const char * V_72 , char * V_76 , int V_77 )
{
const char * V_78 ;
int V_79 ;
V_78 = strrchr ( V_72 , '-' ) ;
if ( V_78 ) {
if ( ( strncmp ( V_78 , L_22 , 4 ) != 0 &&
strncmp ( V_78 , L_23 , 4 ) != 0 ) ||
! F_29 ( V_78 [ 4 ] ) || ! F_29 ( V_78 [ 5 ] ) ||
! F_29 ( V_78 [ 6 ] ) || ! F_29 ( V_78 [ 7 ] ) )
V_78 = NULL ;
}
if ( V_78 == NULL )
V_79 = strlen ( V_72 ) ;
else
V_79 = V_78 - V_72 ;
V_79 = F_31 ( V_79 , V_77 - 1 ) ;
memcpy ( V_76 , V_72 , V_79 ) ;
V_76 [ V_79 ] = '\0' ;
}
static void F_32 ( struct V_80 * V_81 )
{
struct V_82 * V_83 , * V_84 ;
F_13 ( & V_81 -> V_85 ) ;
F_33 (conf_tgt, conf_tgt_next,
&conf->sc_tgts, sct_list) {
F_13 ( & V_83 -> V_86 ) ;
F_34 ( & V_83 -> V_87 ) ;
F_35 ( V_83 ) ;
}
F_14 ( F_36 ( & V_81 -> V_88 ) ) ;
V_81 -> V_89 = 0 ;
V_81 -> V_90 = 0 ;
}
static void F_37 ( struct V_80 * V_81 )
{
F_25 ( V_70 , L_24 , V_81 -> V_91 ) ;
F_32 ( V_81 ) ;
F_34 ( & V_81 -> V_92 ) ;
F_35 ( V_81 ) ;
}
static
struct V_82 * F_38 ( struct V_80 * V_81 ,
const char * V_93 ,
int V_94 )
{
struct V_82 * V_83 ;
F_39 (conf_tgt, &conf->sc_tgts, sct_list) {
if ( strcmp ( V_83 -> V_95 , V_93 ) == 0 )
return V_83 ;
}
if ( ! V_94 )
return NULL ;
F_40 ( V_83 ) ;
if ( V_83 ) {
F_41 ( V_83 -> V_95 , V_93 , sizeof( V_83 -> V_95 ) ) ;
F_16 ( & V_83 -> V_86 ) ;
F_42 ( & V_83 -> V_87 , & V_81 -> V_88 ) ;
}
return V_83 ;
}
static
struct V_80 * F_43 ( const char * V_76 ,
int V_94 )
{
struct V_80 * V_81 ;
F_39 (conf, &sptlrpc_confs, sc_list) {
if ( strcmp ( V_81 -> V_91 , V_76 ) == 0 )
return V_81 ;
}
if ( ! V_94 )
return NULL ;
F_40 ( V_81 ) ;
if ( V_81 == NULL )
return NULL ;
strcpy ( V_81 -> V_91 , V_76 ) ;
F_16 ( & V_81 -> V_85 ) ;
F_44 ( & V_81 -> V_88 ) ;
F_42 ( & V_81 -> V_92 , & V_96 ) ;
F_25 ( V_70 , L_25 , V_81 -> V_91 ) ;
return V_81 ;
}
static int F_45 ( struct V_80 * V_81 ,
const char * V_97 ,
struct V_38 * V_39 )
{
struct V_82 * V_83 ;
struct V_50 * V_98 ;
if ( strcmp ( V_81 -> V_91 , V_97 ) == 0 ) {
V_98 = & V_81 -> V_85 ;
} else {
V_83 = F_38 ( V_81 , V_97 , 1 ) ;
if ( V_83 ) {
V_98 = & V_83 -> V_86 ;
} else {
F_3 ( L_26 ) ;
return - V_57 ;
}
}
return F_24 ( V_98 , V_39 ) ;
}
static int F_46 ( struct V_99 * V_100 ,
struct V_80 * V_81 )
{
char * V_97 , * V_46 ;
char V_76 [ V_101 ] ;
struct V_38 V_39 ;
int V_49 ;
V_97 = F_47 ( V_100 , 1 ) ;
if ( V_97 == NULL ) {
F_3 ( L_27 ) ;
return - V_35 ;
}
V_46 = F_47 ( V_100 , 2 ) ;
if ( V_46 == NULL ) {
F_3 ( L_28 ) ;
return - V_35 ;
}
F_25 ( V_70 , L_29 , V_97 , V_46 ) ;
if ( strncmp ( V_46 , V_102 , sizeof( V_102 ) - 1 ) != 0 ) {
F_3 ( L_30 , V_46 ) ;
return - V_35 ;
}
V_46 += sizeof( V_102 ) - 1 ;
V_49 = F_11 ( V_46 , & V_39 ) ;
if ( V_49 )
return - V_35 ;
if ( V_81 == NULL ) {
F_30 ( V_97 , V_76 , sizeof( V_76 ) ) ;
F_48 ( & V_103 ) ;
V_81 = F_43 ( V_76 , 0 ) ;
if ( V_81 == NULL ) {
F_3 ( L_31 ) ;
V_49 = - V_57 ;
} else {
V_49 = F_45 ( V_81 , V_97 , & V_39 ) ;
}
F_49 ( & V_103 ) ;
} else {
F_14 ( F_50 ( & V_103 ) ) ;
V_49 = F_45 ( V_81 , V_97 , & V_39 ) ;
}
if ( V_49 == 0 )
V_81 -> V_104 ++ ;
return V_49 ;
}
int F_51 ( struct V_99 * V_100 )
{
return F_46 ( V_100 , NULL ) ;
}
static int F_52 ( const char * V_105 , char * V_19 , int V_77 )
{
char * V_78 ;
int V_79 ;
V_78 = strrchr ( V_105 , '-' ) ;
if ( V_78 == NULL || strcmp ( V_78 , L_32 ) ) {
F_3 ( L_33 , V_105 ) ;
return - V_35 ;
}
V_79 = F_31 ( ( int ) ( V_78 - V_105 ) , V_77 - 1 ) ;
memcpy ( V_19 , V_105 , V_79 ) ;
V_19 [ V_79 ] = '\0' ;
return 0 ;
}
void F_53 ( const char * V_105 )
{
struct V_80 * V_81 ;
char V_76 [ 16 ] ;
if ( F_52 ( V_105 , V_76 , sizeof( V_76 ) ) )
return;
F_48 ( & V_103 ) ;
V_81 = F_43 ( V_76 , 0 ) ;
if ( V_81 && V_81 -> V_90 ) {
F_14 ( V_81 -> V_89 == 0 ) ;
F_32 ( V_81 ) ;
}
V_81 -> V_104 = 0 ;
F_49 ( & V_103 ) ;
}
void F_54 ( const char * V_105 )
{
struct V_80 * V_81 ;
char V_76 [ 16 ] ;
if ( F_52 ( V_105 , V_76 , sizeof( V_76 ) ) )
return;
F_48 ( & V_103 ) ;
V_81 = F_43 ( V_76 , 0 ) ;
if ( V_81 ) {
if ( V_81 -> V_89 == 0 )
V_81 -> V_104 ++ ;
V_81 -> V_89 = 1 ;
}
F_49 ( & V_103 ) ;
}
void F_55 ( const char * V_105 )
{
char V_76 [ 16 ] ;
if ( F_52 ( V_105 , V_76 , sizeof( V_76 ) ) )
return;
F_48 ( & V_103 ) ;
F_43 ( V_76 , 1 ) ;
F_49 ( & V_103 ) ;
}
void F_56 ( const char * V_105 )
{
struct V_80 * V_81 ;
char V_76 [ 16 ] ;
if ( F_52 ( V_105 , V_76 , sizeof( V_76 ) ) )
return;
F_48 ( & V_103 ) ;
V_81 = F_43 ( V_76 , 0 ) ;
if ( V_81 )
F_37 ( V_81 ) ;
F_49 ( & V_103 ) ;
}
static void inline F_57 ( struct V_17 * V_36 ,
enum V_1 V_66 ,
enum V_1 V_67 ,
unsigned int V_106 )
{
if ( V_36 -> V_22 == V_37 )
return;
if ( V_66 == V_4 ) {
V_36 -> V_34 |= V_107 ;
} else if ( V_66 == V_3 && V_67 == V_5 ) {
V_36 -> V_34 |= V_107 | V_108 ;
} else if ( V_66 == V_3 && V_67 == V_4 ) {
if ( V_106 && V_36 -> V_22 != V_37 )
V_36 -> V_34 |= V_109 ;
}
}
void F_58 ( enum V_1 V_66 ,
enum V_1 V_67 ,
struct V_110 * V_97 ,
T_1 V_68 ,
struct V_17 * V_36 )
{
struct V_80 * V_81 ;
struct V_82 * V_83 ;
char V_93 [ V_101 ] ;
int V_79 , V_49 = 0 ;
F_30 ( V_97 -> V_111 , V_93 , sizeof( V_93 ) ) ;
F_48 ( & V_103 ) ;
V_81 = F_43 ( V_93 , 0 ) ;
if ( V_81 == NULL )
goto V_112;
V_79 = strlen ( V_97 -> V_111 ) ;
F_14 ( V_79 > 5 ) ;
memcpy ( V_93 , V_97 -> V_111 , V_79 - 5 ) ;
V_93 [ V_79 - 5 ] = '\0' ;
V_83 = F_38 ( V_81 , V_93 , 0 ) ;
if ( V_83 ) {
V_49 = F_26 ( & V_83 -> V_86 ,
V_66 , V_67 , V_68 , V_36 ) ;
if ( V_49 )
goto V_112;
}
V_49 = F_26 ( & V_81 -> V_85 , V_66 , V_67 , V_68 , V_36 ) ;
V_112:
F_49 ( & V_103 ) ;
if ( V_49 == 0 )
F_8 ( V_36 ) ;
F_57 ( V_36 , V_66 , V_67 , 1 ) ;
}
void F_59 ( struct V_50 * V_51 ,
enum V_1 V_66 ,
T_1 V_68 ,
struct V_17 * V_36 )
{
if ( F_26 ( V_51 , V_66 , V_8 , V_68 , V_36 ) == 0 )
F_8 ( V_36 ) ;
}
void F_60 ( struct V_9 * V_10 )
{
struct V_113 * V_114 ;
F_14 ( strcmp ( V_10 -> V_11 -> V_12 , V_115 ) == 0 ||
strcmp ( V_10 -> V_11 -> V_12 , V_116 ) == 0 ) ;
F_25 ( V_70 , L_34 , V_10 -> V_117 . V_118 . V_119 . V_111 ) ;
F_61 ( & V_10 -> V_117 . V_118 . V_120 ) ;
V_114 = V_10 -> V_117 . V_118 . V_121 ;
if ( V_114 ) {
F_62 ( & V_114 -> V_122 ) ;
if ( V_114 -> V_123 )
V_114 -> V_124 = F_63 () +
V_125 ;
F_64 ( & V_114 -> V_122 ) ;
}
F_65 ( & V_10 -> V_117 . V_118 . V_120 ) ;
}
static void F_66 ( struct V_38 * V_69 , char * V_19 , int V_77 )
{
char V_126 [ 8 ] ;
char * V_127 ;
char * V_78 = V_19 ;
if ( V_69 -> V_40 == F_10 ( V_41 ) )
V_127 = L_12 ;
else
V_127 = F_67 ( V_69 -> V_40 ) ;
if ( V_69 -> V_42 == V_8 && V_69 -> V_43 == V_8 )
V_126 [ 0 ] = '\0' ;
else
snprintf ( V_126 , sizeof( V_126 ) , L_35 ,
F_1 ( V_69 -> V_42 ) ,
F_1 ( V_69 -> V_43 ) ) ;
V_78 += snprintf ( V_19 , V_77 , L_36 , V_127 , V_126 ) ;
F_68 ( & V_69 -> V_45 , V_78 , V_77 - ( V_78 - V_19 ) ) ;
V_19 [ V_77 - 1 ] = '\0' ;
}
static int F_69 ( struct V_128 * V_129 ,
char * V_97 ,
struct V_50 * V_51 )
{
struct V_130 V_131 ;
struct V_99 * V_100 ;
struct V_132 V_133 ;
int V_77 ;
char V_46 [ 48 ] ;
int V_74 , V_49 ;
for ( V_74 = 0 ; V_74 < V_51 -> V_53 ; V_74 ++ ) {
F_66 ( & V_51 -> V_54 [ V_74 ] , V_46 , sizeof( V_46 ) ) ;
F_70 ( & V_131 , NULL ) ;
F_71 ( & V_131 , 1 , V_97 ) ;
F_71 ( & V_131 , 2 , V_46 ) ;
V_100 = F_72 ( V_134 , & V_131 ) ;
F_14 ( V_100 ) ;
V_77 = F_73 ( V_100 -> V_135 ,
V_100 -> V_136 ) ;
V_133 . V_137 = F_74 ( V_77 ) ;
V_133 . V_138 = V_139 ;
V_49 = F_75 ( NULL , V_129 , & V_133 , NULL , 0 , ( void * ) V_100 , - 1 ) ;
if ( V_49 )
F_3 ( L_37 , V_49 ) ;
F_76 ( V_100 ) ;
}
return 0 ;
}
static int F_77 ( struct V_128 * V_129 ,
struct V_80 * V_81 )
{
struct V_82 * V_83 ;
F_69 ( V_129 , V_81 -> V_91 , & V_81 -> V_85 ) ;
F_39 (conf_tgt, &conf->sc_tgts, sct_list) {
F_69 ( V_129 , V_83 -> V_95 ,
& V_83 -> V_86 ) ;
}
return 0 ;
}
static
int F_78 ( struct V_9 * V_10 ,
struct V_80 * V_81 )
{
struct V_128 * V_129 = NULL ;
struct V_140 * V_141 ;
struct V_142 V_143 ;
struct V_144 * V_144 ;
int V_49 ;
V_141 = F_79 ( V_10 , V_145 ) ;
if ( V_141 == NULL )
return - V_35 ;
F_80 ( & V_143 , & V_10 -> V_146 , NULL ) ;
V_144 = F_81 ( V_147 , F_82 ( V_148 -> V_149 ) ,
strlen ( V_147 ) ) ;
if ( F_83 ( V_144 ) ) {
V_49 = F_84 ( V_144 ) ;
F_3 ( L_38 ,
V_147 , V_49 ) ;
GOTO ( V_150 , V_49 ) ;
}
V_49 = F_85 ( NULL , V_141 , NULL , V_151 ) ;
if ( V_49 < 0 && V_49 != - V_152 ) {
F_3 ( L_39 ,
V_10 -> V_153 , V_49 ) ;
GOTO ( V_154 , V_49 ) ;
}
V_49 = F_86 ( NULL , V_141 , & V_129 , NULL , V_151 ) ;
if ( V_49 )
GOTO ( V_154 , V_49 ) ;
V_49 = F_87 ( NULL , V_129 , V_155 , NULL ) ;
if ( V_49 )
GOTO ( V_156 , V_49 ) ;
V_49 = F_77 ( V_129 , V_81 ) ;
V_156:
F_88 ( NULL , V_129 ) ;
if ( V_49 == 0 )
V_49 = F_89 ( V_144 , V_10 -> V_146 . V_157 ,
V_151 , V_158 ) ;
V_154:
F_90 ( V_144 ) ;
V_150:
F_91 ( & V_143 , & V_10 -> V_146 , NULL ) ;
F_92 ( V_141 ) ;
F_25 ( V_70 , L_40 ,
V_10 -> V_153 , V_49 ) ;
return V_49 ;
}
static int F_93 ( const struct V_159 * V_160 ,
struct V_128 * V_129 ,
struct V_132 * V_133 , void * V_161 )
{
struct V_80 * V_81 = (struct V_80 * ) V_161 ;
struct V_99 * V_100 = (struct V_99 * ) ( V_133 + 1 ) ;
int V_162 , V_49 ;
if ( V_133 -> V_138 != V_139 ) {
F_3 ( L_41 , V_133 -> V_138 ) ;
return - V_35 ;
}
V_162 = V_133 -> V_137 - sizeof( struct V_132 ) -
sizeof( struct V_163 ) ;
V_49 = F_94 ( V_100 , V_162 ) ;
if ( V_49 ) {
F_3 ( L_42 ) ;
return V_49 ;
}
if ( V_100 -> V_164 != V_134 ) {
F_3 ( L_43 , V_100 -> V_164 ) ;
return - V_35 ;
}
return F_46 ( V_100 , V_81 ) ;
}
static
int F_95 ( struct V_9 * V_10 ,
struct V_80 * V_81 )
{
struct V_128 * V_129 = NULL ;
struct V_140 * V_141 ;
struct V_142 V_143 ;
int V_49 ;
F_14 ( V_81 -> V_89 == 0 && V_81 -> V_90 == 0 ) ;
V_141 = F_79 ( V_10 , V_145 ) ;
if ( V_141 == NULL ) {
F_3 ( L_44 ) ;
return - V_35 ;
}
F_80 ( & V_143 , & V_10 -> V_146 , NULL ) ;
V_49 = F_96 ( NULL , V_141 , & V_129 , NULL , V_158 , V_165 ) ;
if ( V_49 < 0 ) {
if ( V_49 == - V_152 )
V_49 = 0 ;
GOTO ( V_166 , V_49 ) ;
}
V_49 = F_87 ( NULL , V_129 , V_155 , NULL ) ;
if ( V_49 )
GOTO ( V_156 , V_49 ) ;
if ( F_97 ( V_129 ) <= 1 ) {
F_25 ( V_70 , L_45 ) ;
GOTO ( V_156 , V_49 = 0 ) ;
}
V_49 = F_98 ( NULL , V_129 , F_93 , ( void * ) V_81 , NULL ) ;
if ( V_49 == 0 ) {
V_81 -> V_90 = 1 ;
} else {
F_32 ( V_81 ) ;
}
V_156:
F_88 ( NULL , V_129 ) ;
V_166:
F_91 ( & V_143 , & V_10 -> V_146 , NULL ) ;
F_92 ( V_141 ) ;
F_25 ( V_70 , L_46 ,
V_10 -> V_153 , V_49 ) ;
return V_49 ;
}
int F_99 ( struct V_9 * V_10 ,
struct V_50 * V_51 ,
int V_167 )
{
struct V_80 * V_81 ;
struct V_82 * V_83 ;
enum V_1 V_168 ;
char V_76 [ V_101 ] ;
int V_49 = 0 ;
if ( strcmp ( V_10 -> V_11 -> V_12 , V_13 ) == 0 ) {
V_168 = V_4 ;
} else if ( strcmp ( V_10 -> V_11 -> V_12 , V_14 ) == 0 ) {
V_168 = V_5 ;
} else {
F_3 ( L_47 , V_10 -> V_11 -> V_12 ) ;
return - V_35 ;
}
F_25 ( V_70 , L_48 , V_10 -> V_110 . V_111 ) ;
F_30 ( V_10 -> V_110 . V_111 , V_76 , sizeof( V_76 ) ) ;
F_48 ( & V_103 ) ;
V_81 = F_43 ( V_76 , 0 ) ;
if ( V_81 == NULL ) {
F_3 ( L_49 ) ;
GOTO ( V_112 , V_49 ) ;
}
if ( V_81 -> V_89 == 0 ) {
if ( V_81 -> V_90 )
F_32 ( V_81 ) ;
F_95 ( V_10 , V_81 ) ;
} else {
F_14 ( V_81 -> V_90 == 0 ) ;
if ( V_167 || V_81 -> V_104 )
F_78 ( V_10 , V_81 ) ;
else
F_25 ( V_70 , L_50 ) ;
}
V_83 = F_38 ( V_81 , V_10 -> V_153 , 0 ) ;
V_49 = F_28 ( & V_81 -> V_85 ,
V_83 ? & V_83 -> V_86 : NULL ,
V_8 , V_168 , V_51 ) ;
V_112:
F_49 ( & V_103 ) ;
return V_49 ;
}
int F_100 ( void )
{
F_101 ( & V_103 ) ;
return 0 ;
}
void F_102 ( void )
{
struct V_80 * V_81 , * V_169 ;
F_48 ( & V_103 ) ;
F_33 (conf, conf_next, &sptlrpc_confs, sc_list) {
F_37 ( V_81 ) ;
}
F_14 ( F_36 ( & V_96 ) ) ;
F_49 ( & V_103 ) ;
}
