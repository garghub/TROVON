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
F_15 ( V_51 -> V_54 ) ;
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
V_55 = F_19 ( V_56 , sizeof( * V_51 -> V_54 ) , V_57 ) ;
if ( V_55 == NULL )
return - V_58 ;
if ( V_51 -> V_53 ) {
F_14 ( V_51 -> V_52 && V_51 -> V_54 ) ;
memcpy ( V_55 , V_51 -> V_54 ,
V_51 -> V_53 * sizeof( * V_51 -> V_54 ) ) ;
F_15 ( V_51 -> V_54 ) ;
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
static inline int F_22 ( struct V_38 * V_59 ,
struct V_38 * V_60 )
{
return ( V_59 -> V_42 == V_60 -> V_42 && V_59 -> V_43 == V_60 -> V_43 ) ;
}
static inline int F_23 ( struct V_38 * V_59 ,
struct V_38 * V_60 )
{
return ( V_59 -> V_40 == V_60 -> V_40 ) ;
}
int F_24 ( struct V_50 * V_51 ,
struct V_38 * V_39 )
{
struct V_38 * V_61 = V_51 -> V_54 ;
int V_62 , V_63 ;
int V_49 , V_64 , V_65 = 0 ;
F_18 () ;
V_63 = F_21 ( V_39 ) ;
V_62 = F_20 ( V_39 ) ;
for ( V_64 = 0 ; V_64 < V_51 -> V_53 ; V_64 ++ ) {
V_61 = & V_51 -> V_54 [ V_64 ] ;
if ( ! F_23 ( V_61 , V_39 ) ) {
if ( V_63 ) {
if ( F_21 ( V_61 ) )
continue;
else
break;
} else {
continue;
}
}
if ( ! F_22 ( V_61 , V_39 ) ) {
if ( V_62 ) {
if ( F_20 ( V_61 ) )
continue;
else
break;
} else {
continue;
}
}
V_65 = 1 ;
break;
}
if ( V_65 ) {
F_14 ( V_64 >= 0 && V_64 < V_51 -> V_53 ) ;
if ( V_39 -> V_45 . V_22 == V_23 ) {
if ( V_64 < V_51 -> V_53 - 1 )
memmove ( & V_51 -> V_54 [ V_64 ] ,
& V_51 -> V_54 [ V_64 + 1 ] ,
( V_51 -> V_53 - V_64 - 1 ) *
sizeof( * V_39 ) ) ;
V_51 -> V_53 -- ;
} else {
memcpy ( & V_51 -> V_54 [ V_64 ] , V_39 , sizeof( * V_39 ) ) ;
}
} else {
F_14 ( V_64 >= 0 && V_64 <= V_51 -> V_53 ) ;
if ( V_39 -> V_45 . V_22 != V_23 ) {
V_49 = F_17 ( V_51 ) ;
if ( V_49 )
return V_49 ;
if ( V_64 < V_51 -> V_53 )
memmove ( & V_51 -> V_54 [ V_64 + 1 ] ,
& V_51 -> V_54 [ V_64 ] ,
( V_51 -> V_53 - V_64 ) * sizeof( * V_39 ) ) ;
memcpy ( & V_51 -> V_54 [ V_64 ] , V_39 , sizeof( * V_39 ) ) ;
V_51 -> V_53 ++ ;
} else {
F_25 ( V_66 , L_19 ) ;
}
}
return 0 ;
}
int F_26 ( struct V_50 * V_51 ,
enum V_1 V_67 ,
enum V_1 V_68 ,
T_1 V_69 ,
struct V_17 * V_36 )
{
struct V_38 * V_70 ;
int V_64 ;
for ( V_64 = 0 ; V_64 < V_51 -> V_53 ; V_64 ++ ) {
V_70 = & V_51 -> V_54 [ V_64 ] ;
if ( F_10 ( V_69 ) != F_10 ( V_41 ) &&
V_70 -> V_40 != F_10 ( V_41 ) &&
F_10 ( V_69 ) != V_70 -> V_40 )
continue;
if ( V_67 != V_8 && V_70 -> V_42 != V_8 &&
V_67 != V_70 -> V_42 )
continue;
if ( V_68 != V_8 && V_70 -> V_43 != V_8 &&
V_68 != V_70 -> V_43 )
continue;
* V_36 = V_70 -> V_45 ;
return 1 ;
}
return 0 ;
}
void F_27 ( struct V_50 * V_51 )
{
struct V_38 * V_70 ;
int V_64 ;
for ( V_64 = 0 ; V_64 < V_51 -> V_53 ; V_64 ++ ) {
V_70 = & V_51 -> V_54 [ V_64 ] ;
F_25 ( V_71 , L_20 , V_64 ,
V_70 -> V_42 , V_70 -> V_43 , V_70 -> V_40 , V_70 -> V_45 . V_22 ) ;
}
}
static inline int F_28 ( char V_72 )
{
return ( ( V_72 >= '0' && V_72 <= '9' ) ||
( V_72 >= 'a' && V_72 <= 'f' ) ) ;
}
static void F_29 ( const char * V_73 , char * V_74 , int V_75 )
{
const char * V_76 ;
int V_77 ;
V_76 = strrchr ( V_73 , '-' ) ;
if ( V_76 ) {
if ( ( strncmp ( V_76 , L_21 , 4 ) != 0 &&
strncmp ( V_76 , L_22 , 4 ) != 0 ) ||
! F_28 ( V_76 [ 4 ] ) || ! F_28 ( V_76 [ 5 ] ) ||
! F_28 ( V_76 [ 6 ] ) || ! F_28 ( V_76 [ 7 ] ) )
V_76 = NULL ;
}
if ( V_76 == NULL )
V_77 = strlen ( V_73 ) ;
else
V_77 = V_76 - V_73 ;
V_77 = F_30 ( V_77 , V_75 - 1 ) ;
memcpy ( V_74 , V_73 , V_77 ) ;
V_74 [ V_77 ] = '\0' ;
}
static void F_31 ( struct V_78 * V_79 )
{
struct V_80 * V_81 , * V_82 ;
F_13 ( & V_79 -> V_83 ) ;
F_32 (conf_tgt, conf_tgt_next,
&conf->sc_tgts, sct_list) {
F_13 ( & V_81 -> V_84 ) ;
F_33 ( & V_81 -> V_85 ) ;
F_15 ( V_81 ) ;
}
F_14 ( F_34 ( & V_79 -> V_86 ) ) ;
V_79 -> V_87 = 0 ;
V_79 -> V_88 = 0 ;
}
static void F_35 ( struct V_78 * V_79 )
{
F_25 ( V_71 , L_23 , V_79 -> V_89 ) ;
F_31 ( V_79 ) ;
F_33 ( & V_79 -> V_90 ) ;
F_15 ( V_79 ) ;
}
static
struct V_80 * F_36 ( struct V_78 * V_79 ,
const char * V_91 ,
int V_92 )
{
struct V_80 * V_81 ;
F_37 (conf_tgt, &conf->sc_tgts, sct_list) {
if ( strcmp ( V_81 -> V_93 , V_91 ) == 0 )
return V_81 ;
}
if ( ! V_92 )
return NULL ;
V_81 = F_38 ( sizeof( * V_81 ) , V_57 ) ;
if ( V_81 ) {
F_39 ( V_81 -> V_93 , V_91 , sizeof( V_81 -> V_93 ) ) ;
F_16 ( & V_81 -> V_84 ) ;
F_40 ( & V_81 -> V_85 , & V_79 -> V_86 ) ;
}
return V_81 ;
}
static
struct V_78 * F_41 ( const char * V_74 ,
int V_92 )
{
struct V_78 * V_79 ;
F_37 (conf, &sptlrpc_confs, sc_list) {
if ( strcmp ( V_79 -> V_89 , V_74 ) == 0 )
return V_79 ;
}
if ( ! V_92 )
return NULL ;
V_79 = F_38 ( sizeof( * V_79 ) , V_57 ) ;
if ( V_79 == NULL )
return NULL ;
strcpy ( V_79 -> V_89 , V_74 ) ;
F_16 ( & V_79 -> V_83 ) ;
F_42 ( & V_79 -> V_86 ) ;
F_40 ( & V_79 -> V_90 , & V_94 ) ;
F_25 ( V_71 , L_24 , V_79 -> V_89 ) ;
return V_79 ;
}
static int F_43 ( struct V_78 * V_79 ,
const char * V_95 ,
struct V_38 * V_39 )
{
struct V_80 * V_81 ;
struct V_50 * V_96 ;
if ( strcmp ( V_79 -> V_89 , V_95 ) == 0 ) {
V_96 = & V_79 -> V_83 ;
} else {
V_81 = F_36 ( V_79 , V_95 , 1 ) ;
if ( V_81 ) {
V_96 = & V_81 -> V_84 ;
} else {
F_3 ( L_25 ) ;
return - V_58 ;
}
}
return F_24 ( V_96 , V_39 ) ;
}
static int F_44 ( struct V_97 * V_98 ,
struct V_78 * V_79 )
{
char * V_95 , * V_46 ;
char V_74 [ V_99 ] ;
struct V_38 V_39 ;
int V_49 ;
V_95 = F_45 ( V_98 , 1 ) ;
if ( V_95 == NULL ) {
F_3 ( L_26 ) ;
return - V_35 ;
}
V_46 = F_45 ( V_98 , 2 ) ;
if ( V_46 == NULL ) {
F_3 ( L_27 ) ;
return - V_35 ;
}
F_25 ( V_71 , L_28 , V_95 , V_46 ) ;
if ( strncmp ( V_46 , V_100 , sizeof( V_100 ) - 1 ) != 0 ) {
F_3 ( L_29 , V_46 ) ;
return - V_35 ;
}
V_46 += sizeof( V_100 ) - 1 ;
V_49 = F_11 ( V_46 , & V_39 ) ;
if ( V_49 )
return - V_35 ;
if ( V_79 == NULL ) {
F_29 ( V_95 , V_74 , sizeof( V_74 ) ) ;
F_46 ( & V_101 ) ;
V_79 = F_41 ( V_74 , 0 ) ;
if ( V_79 == NULL ) {
F_3 ( L_30 ) ;
V_49 = - V_58 ;
} else {
V_49 = F_43 ( V_79 , V_95 , & V_39 ) ;
}
F_47 ( & V_101 ) ;
} else {
F_14 ( F_48 ( & V_101 ) ) ;
V_49 = F_43 ( V_79 , V_95 , & V_39 ) ;
}
if ( V_49 == 0 )
V_79 -> V_102 ++ ;
return V_49 ;
}
int F_49 ( struct V_97 * V_98 )
{
return F_44 ( V_98 , NULL ) ;
}
static int F_50 ( const char * V_103 , char * V_19 , int V_75 )
{
char * V_76 ;
int V_77 ;
V_76 = strrchr ( V_103 , '-' ) ;
if ( V_76 == NULL || strcmp ( V_76 , L_31 ) ) {
F_3 ( L_32 , V_103 ) ;
return - V_35 ;
}
V_77 = F_30 ( ( int ) ( V_76 - V_103 ) , V_75 - 1 ) ;
memcpy ( V_19 , V_103 , V_77 ) ;
V_19 [ V_77 ] = '\0' ;
return 0 ;
}
void F_51 ( const char * V_103 )
{
struct V_78 * V_79 ;
char V_74 [ 16 ] ;
if ( F_50 ( V_103 , V_74 , sizeof( V_74 ) ) )
return;
F_46 ( & V_101 ) ;
V_79 = F_41 ( V_74 , 0 ) ;
if ( V_79 ) {
if ( V_79 -> V_88 ) {
F_14 ( V_79 -> V_87 == 0 ) ;
F_31 ( V_79 ) ;
}
V_79 -> V_102 = 0 ;
}
F_47 ( & V_101 ) ;
}
void F_52 ( const char * V_103 )
{
struct V_78 * V_79 ;
char V_74 [ 16 ] ;
if ( F_50 ( V_103 , V_74 , sizeof( V_74 ) ) )
return;
F_46 ( & V_101 ) ;
V_79 = F_41 ( V_74 , 0 ) ;
if ( V_79 ) {
if ( V_79 -> V_87 == 0 )
V_79 -> V_102 ++ ;
V_79 -> V_87 = 1 ;
}
F_47 ( & V_101 ) ;
}
void F_53 ( const char * V_103 )
{
char V_74 [ 16 ] ;
if ( F_50 ( V_103 , V_74 , sizeof( V_74 ) ) )
return;
F_46 ( & V_101 ) ;
F_41 ( V_74 , 1 ) ;
F_47 ( & V_101 ) ;
}
void F_54 ( const char * V_103 )
{
struct V_78 * V_79 ;
char V_74 [ 16 ] ;
if ( F_50 ( V_103 , V_74 , sizeof( V_74 ) ) )
return;
F_46 ( & V_101 ) ;
V_79 = F_41 ( V_74 , 0 ) ;
if ( V_79 )
F_35 ( V_79 ) ;
F_47 ( & V_101 ) ;
}
static inline void F_55 ( struct V_17 * V_36 ,
enum V_1 V_67 ,
enum V_1 V_68 ,
unsigned int V_104 )
{
if ( V_36 -> V_22 == V_37 )
return;
if ( V_67 == V_4 ) {
V_36 -> V_34 |= V_105 ;
} else if ( V_67 == V_3 && V_68 == V_5 ) {
V_36 -> V_34 |= V_105 | V_106 ;
} else if ( V_67 == V_3 && V_68 == V_4 ) {
if ( V_104 && V_36 -> V_22 != V_37 )
V_36 -> V_34 |= V_107 ;
}
}
void F_56 ( enum V_1 V_67 ,
enum V_1 V_68 ,
struct V_108 * V_95 ,
T_1 V_69 ,
struct V_17 * V_36 )
{
struct V_78 * V_79 ;
struct V_80 * V_81 ;
char V_91 [ V_99 ] ;
int V_77 , V_49 = 0 ;
F_29 ( V_95 -> V_109 , V_91 , sizeof( V_91 ) ) ;
F_46 ( & V_101 ) ;
V_79 = F_41 ( V_91 , 0 ) ;
if ( V_79 == NULL )
goto V_110;
V_77 = strlen ( V_95 -> V_109 ) ;
F_14 ( V_77 > 5 ) ;
memcpy ( V_91 , V_95 -> V_109 , V_77 - 5 ) ;
V_91 [ V_77 - 5 ] = '\0' ;
V_81 = F_36 ( V_79 , V_91 , 0 ) ;
if ( V_81 ) {
V_49 = F_26 ( & V_81 -> V_84 ,
V_67 , V_68 , V_69 , V_36 ) ;
if ( V_49 )
goto V_110;
}
V_49 = F_26 ( & V_79 -> V_83 , V_67 , V_68 , V_69 , V_36 ) ;
V_110:
F_47 ( & V_101 ) ;
if ( V_49 == 0 )
F_8 ( V_36 ) ;
F_55 ( V_36 , V_67 , V_68 , 1 ) ;
}
void F_57 ( struct V_50 * V_51 ,
enum V_1 V_67 ,
T_1 V_69 ,
struct V_17 * V_36 )
{
if ( F_26 ( V_51 , V_67 , V_8 , V_69 , V_36 ) == 0 )
F_8 ( V_36 ) ;
}
void F_58 ( struct V_9 * V_10 )
{
struct V_111 * V_112 ;
F_14 ( strcmp ( V_10 -> V_11 -> V_12 , V_113 ) == 0 ||
strcmp ( V_10 -> V_11 -> V_12 , V_114 ) == 0 ) ;
F_25 ( V_71 , L_33 , V_10 -> V_115 . V_116 . V_117 . V_109 ) ;
F_59 ( & V_10 -> V_115 . V_116 . V_118 ) ;
V_112 = V_10 -> V_115 . V_116 . V_119 ;
if ( V_112 ) {
F_60 ( & V_112 -> V_120 ) ;
if ( V_112 -> V_121 )
V_112 -> V_122 = F_61 () +
V_123 ;
F_62 ( & V_112 -> V_120 ) ;
}
F_63 ( & V_10 -> V_115 . V_116 . V_118 ) ;
}
int F_64 ( void )
{
F_65 ( & V_101 ) ;
return 0 ;
}
void F_66 ( void )
{
struct V_78 * V_79 , * V_124 ;
F_46 ( & V_101 ) ;
F_32 (conf, conf_next, &sptlrpc_confs, sc_list) {
F_35 ( V_79 ) ;
}
F_14 ( F_34 ( & V_94 ) ) ;
F_47 ( & V_101 ) ;
}
