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
static inline int F_28 ( char V_71 )
{
return ( ( V_71 >= '0' && V_71 <= '9' ) ||
( V_71 >= 'a' && V_71 <= 'f' ) ) ;
}
static void F_29 ( const char * V_72 , char * V_73 , int V_74 )
{
const char * V_75 ;
int V_76 ;
V_75 = strrchr ( V_72 , '-' ) ;
if ( V_75 ) {
if ( ( strncmp ( V_75 , L_21 , 4 ) != 0 &&
strncmp ( V_75 , L_22 , 4 ) != 0 ) ||
! F_28 ( V_75 [ 4 ] ) || ! F_28 ( V_75 [ 5 ] ) ||
! F_28 ( V_75 [ 6 ] ) || ! F_28 ( V_75 [ 7 ] ) )
V_75 = NULL ;
}
if ( V_75 == NULL )
V_76 = strlen ( V_72 ) ;
else
V_76 = V_75 - V_72 ;
V_76 = F_30 ( V_76 , V_74 - 1 ) ;
memcpy ( V_73 , V_72 , V_76 ) ;
V_73 [ V_76 ] = '\0' ;
}
static void F_31 ( struct V_77 * V_78 )
{
struct V_79 * V_80 , * V_81 ;
F_13 ( & V_78 -> V_82 ) ;
F_32 (conf_tgt, conf_tgt_next,
&conf->sc_tgts, sct_list) {
F_13 ( & V_80 -> V_83 ) ;
F_33 ( & V_80 -> V_84 ) ;
F_34 ( V_80 ) ;
}
F_14 ( F_35 ( & V_78 -> V_85 ) ) ;
V_78 -> V_86 = 0 ;
V_78 -> V_87 = 0 ;
}
static void F_36 ( struct V_77 * V_78 )
{
F_25 ( V_70 , L_23 , V_78 -> V_88 ) ;
F_31 ( V_78 ) ;
F_33 ( & V_78 -> V_89 ) ;
F_34 ( V_78 ) ;
}
static
struct V_79 * F_37 ( struct V_77 * V_78 ,
const char * V_90 ,
int V_91 )
{
struct V_79 * V_80 ;
F_38 (conf_tgt, &conf->sc_tgts, sct_list) {
if ( strcmp ( V_80 -> V_92 , V_90 ) == 0 )
return V_80 ;
}
if ( ! V_91 )
return NULL ;
F_39 ( V_80 ) ;
if ( V_80 ) {
F_40 ( V_80 -> V_92 , V_90 , sizeof( V_80 -> V_92 ) ) ;
F_16 ( & V_80 -> V_83 ) ;
F_41 ( & V_80 -> V_84 , & V_78 -> V_85 ) ;
}
return V_80 ;
}
static
struct V_77 * F_42 ( const char * V_73 ,
int V_91 )
{
struct V_77 * V_78 ;
F_38 (conf, &sptlrpc_confs, sc_list) {
if ( strcmp ( V_78 -> V_88 , V_73 ) == 0 )
return V_78 ;
}
if ( ! V_91 )
return NULL ;
F_39 ( V_78 ) ;
if ( V_78 == NULL )
return NULL ;
strcpy ( V_78 -> V_88 , V_73 ) ;
F_16 ( & V_78 -> V_82 ) ;
F_43 ( & V_78 -> V_85 ) ;
F_41 ( & V_78 -> V_89 , & V_93 ) ;
F_25 ( V_70 , L_24 , V_78 -> V_88 ) ;
return V_78 ;
}
static int F_44 ( struct V_77 * V_78 ,
const char * V_94 ,
struct V_38 * V_39 )
{
struct V_79 * V_80 ;
struct V_50 * V_95 ;
if ( strcmp ( V_78 -> V_88 , V_94 ) == 0 ) {
V_95 = & V_78 -> V_82 ;
} else {
V_80 = F_37 ( V_78 , V_94 , 1 ) ;
if ( V_80 ) {
V_95 = & V_80 -> V_83 ;
} else {
F_3 ( L_25 ) ;
return - V_57 ;
}
}
return F_24 ( V_95 , V_39 ) ;
}
static int F_45 ( struct V_96 * V_97 ,
struct V_77 * V_78 )
{
char * V_94 , * V_46 ;
char V_73 [ V_98 ] ;
struct V_38 V_39 ;
int V_49 ;
V_94 = F_46 ( V_97 , 1 ) ;
if ( V_94 == NULL ) {
F_3 ( L_26 ) ;
return - V_35 ;
}
V_46 = F_46 ( V_97 , 2 ) ;
if ( V_46 == NULL ) {
F_3 ( L_27 ) ;
return - V_35 ;
}
F_25 ( V_70 , L_28 , V_94 , V_46 ) ;
if ( strncmp ( V_46 , V_99 , sizeof( V_99 ) - 1 ) != 0 ) {
F_3 ( L_29 , V_46 ) ;
return - V_35 ;
}
V_46 += sizeof( V_99 ) - 1 ;
V_49 = F_11 ( V_46 , & V_39 ) ;
if ( V_49 )
return - V_35 ;
if ( V_78 == NULL ) {
F_29 ( V_94 , V_73 , sizeof( V_73 ) ) ;
F_47 ( & V_100 ) ;
V_78 = F_42 ( V_73 , 0 ) ;
if ( V_78 == NULL ) {
F_3 ( L_30 ) ;
V_49 = - V_57 ;
} else {
V_49 = F_44 ( V_78 , V_94 , & V_39 ) ;
}
F_48 ( & V_100 ) ;
} else {
F_14 ( F_49 ( & V_100 ) ) ;
V_49 = F_44 ( V_78 , V_94 , & V_39 ) ;
}
if ( V_49 == 0 )
V_78 -> V_101 ++ ;
return V_49 ;
}
int F_50 ( struct V_96 * V_97 )
{
return F_45 ( V_97 , NULL ) ;
}
static int F_51 ( const char * V_102 , char * V_19 , int V_74 )
{
char * V_75 ;
int V_76 ;
V_75 = strrchr ( V_102 , '-' ) ;
if ( V_75 == NULL || strcmp ( V_75 , L_31 ) ) {
F_3 ( L_32 , V_102 ) ;
return - V_35 ;
}
V_76 = F_30 ( ( int ) ( V_75 - V_102 ) , V_74 - 1 ) ;
memcpy ( V_19 , V_102 , V_76 ) ;
V_19 [ V_76 ] = '\0' ;
return 0 ;
}
void F_52 ( const char * V_102 )
{
struct V_77 * V_78 ;
char V_73 [ 16 ] ;
if ( F_51 ( V_102 , V_73 , sizeof( V_73 ) ) )
return;
F_47 ( & V_100 ) ;
V_78 = F_42 ( V_73 , 0 ) ;
if ( V_78 ) {
if ( V_78 -> V_87 ) {
F_14 ( V_78 -> V_86 == 0 ) ;
F_31 ( V_78 ) ;
}
V_78 -> V_101 = 0 ;
}
F_48 ( & V_100 ) ;
}
void F_53 ( const char * V_102 )
{
struct V_77 * V_78 ;
char V_73 [ 16 ] ;
if ( F_51 ( V_102 , V_73 , sizeof( V_73 ) ) )
return;
F_47 ( & V_100 ) ;
V_78 = F_42 ( V_73 , 0 ) ;
if ( V_78 ) {
if ( V_78 -> V_86 == 0 )
V_78 -> V_101 ++ ;
V_78 -> V_86 = 1 ;
}
F_48 ( & V_100 ) ;
}
void F_54 ( const char * V_102 )
{
char V_73 [ 16 ] ;
if ( F_51 ( V_102 , V_73 , sizeof( V_73 ) ) )
return;
F_47 ( & V_100 ) ;
F_42 ( V_73 , 1 ) ;
F_48 ( & V_100 ) ;
}
void F_55 ( const char * V_102 )
{
struct V_77 * V_78 ;
char V_73 [ 16 ] ;
if ( F_51 ( V_102 , V_73 , sizeof( V_73 ) ) )
return;
F_47 ( & V_100 ) ;
V_78 = F_42 ( V_73 , 0 ) ;
if ( V_78 )
F_36 ( V_78 ) ;
F_48 ( & V_100 ) ;
}
static inline void F_56 ( struct V_17 * V_36 ,
enum V_1 V_66 ,
enum V_1 V_67 ,
unsigned int V_103 )
{
if ( V_36 -> V_22 == V_37 )
return;
if ( V_66 == V_4 ) {
V_36 -> V_34 |= V_104 ;
} else if ( V_66 == V_3 && V_67 == V_5 ) {
V_36 -> V_34 |= V_104 | V_105 ;
} else if ( V_66 == V_3 && V_67 == V_4 ) {
if ( V_103 && V_36 -> V_22 != V_37 )
V_36 -> V_34 |= V_106 ;
}
}
void F_57 ( enum V_1 V_66 ,
enum V_1 V_67 ,
struct V_107 * V_94 ,
T_1 V_68 ,
struct V_17 * V_36 )
{
struct V_77 * V_78 ;
struct V_79 * V_80 ;
char V_90 [ V_98 ] ;
int V_76 , V_49 = 0 ;
F_29 ( V_94 -> V_108 , V_90 , sizeof( V_90 ) ) ;
F_47 ( & V_100 ) ;
V_78 = F_42 ( V_90 , 0 ) ;
if ( V_78 == NULL )
goto V_109;
V_76 = strlen ( V_94 -> V_108 ) ;
F_14 ( V_76 > 5 ) ;
memcpy ( V_90 , V_94 -> V_108 , V_76 - 5 ) ;
V_90 [ V_76 - 5 ] = '\0' ;
V_80 = F_37 ( V_78 , V_90 , 0 ) ;
if ( V_80 ) {
V_49 = F_26 ( & V_80 -> V_83 ,
V_66 , V_67 , V_68 , V_36 ) ;
if ( V_49 )
goto V_109;
}
V_49 = F_26 ( & V_78 -> V_82 , V_66 , V_67 , V_68 , V_36 ) ;
V_109:
F_48 ( & V_100 ) ;
if ( V_49 == 0 )
F_8 ( V_36 ) ;
F_56 ( V_36 , V_66 , V_67 , 1 ) ;
}
void F_58 ( struct V_50 * V_51 ,
enum V_1 V_66 ,
T_1 V_68 ,
struct V_17 * V_36 )
{
if ( F_26 ( V_51 , V_66 , V_8 , V_68 , V_36 ) == 0 )
F_8 ( V_36 ) ;
}
void F_59 ( struct V_9 * V_10 )
{
struct V_110 * V_111 ;
F_14 ( strcmp ( V_10 -> V_11 -> V_12 , V_112 ) == 0 ||
strcmp ( V_10 -> V_11 -> V_12 , V_113 ) == 0 ) ;
F_25 ( V_70 , L_33 , V_10 -> V_114 . V_115 . V_116 . V_108 ) ;
F_60 ( & V_10 -> V_114 . V_115 . V_117 ) ;
V_111 = V_10 -> V_114 . V_115 . V_118 ;
if ( V_111 ) {
F_61 ( & V_111 -> V_119 ) ;
if ( V_111 -> V_120 )
V_111 -> V_121 = F_62 () +
V_122 ;
F_63 ( & V_111 -> V_119 ) ;
}
F_64 ( & V_10 -> V_114 . V_115 . V_117 ) ;
}
int F_65 ( void )
{
F_66 ( & V_100 ) ;
return 0 ;
}
void F_67 ( void )
{
struct V_77 * V_78 , * V_123 ;
F_47 ( & V_100 ) ;
F_32 (conf, conf_next, &sptlrpc_confs, sc_list) {
F_36 ( V_78 ) ;
}
F_14 ( F_35 ( & V_93 ) ) ;
F_48 ( & V_100 ) ;
}
