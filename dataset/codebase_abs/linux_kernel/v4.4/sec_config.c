enum V_1 F_1 ( struct V_2 * V_3 )
{
const char * type = V_3 -> V_4 -> V_5 ;
if ( ! strcmp ( type , V_6 ) )
return V_7 ;
if ( ! strcmp ( type , V_8 ) )
return V_9 ;
if ( ! strcmp ( type , V_10 ) )
return V_11 ;
F_2 ( L_1 , V_3 , type ) ;
return V_12 ;
}
int F_3 ( const char * V_13 , struct V_14 * V_15 )
{
char V_16 [ 32 ] ;
char * V_17 , * V_18 ;
memset ( V_15 , 0 , sizeof( * V_15 ) ) ;
if ( V_13 == NULL || V_13 [ 0 ] == '\0' ) {
V_15 -> V_19 = V_20 ;
return 0 ;
}
strncpy ( V_16 , V_13 , sizeof( V_16 ) ) ;
V_16 [ sizeof( V_16 ) - 1 ] = '\0' ;
V_17 = strchr ( V_16 , '-' ) ;
if ( V_17 )
* V_17 ++ = '\0' ;
V_15 -> V_19 = F_4 ( V_16 ) ;
if ( V_15 -> V_19 == V_20 )
goto V_21;
if ( V_15 -> V_19 == V_22 ) {
V_15 -> V_23 . V_24 . V_25 = V_26 ;
if ( V_17 ) {
V_18 = strchr ( V_17 , ':' ) ;
if ( V_18 == NULL )
goto V_21;
* V_18 ++ = '\0' ;
if ( strcmp ( V_17 , L_2 ) )
goto V_21;
V_15 -> V_23 . V_24 . V_25 = F_5 ( V_18 ) ;
if ( V_15 -> V_23 . V_24 . V_25 >= V_27 )
goto V_21;
}
if ( V_15 -> V_23 . V_24 . V_25 == V_28 )
F_6 ( & V_15 -> V_19 , V_29 ) ;
else
F_6 ( & V_15 -> V_19 , V_30 ) ;
} else {
if ( V_17 )
goto V_21;
}
V_15 -> V_31 = 0 ;
return 0 ;
V_21:
F_2 ( L_3 , V_13 ) ;
return - V_32 ;
}
static void F_7 ( struct V_14 * V_33 )
{
memset ( V_33 , 0 , sizeof( * V_33 ) ) ;
V_33 -> V_19 = V_34 ;
V_33 -> V_31 = 0 ;
}
static void F_8 ( struct V_35 * V_36 )
{
V_36 -> V_37 = F_9 ( V_38 ) ;
V_36 -> V_39 = V_12 ;
V_36 -> V_40 = V_12 ;
V_36 -> V_41 = 0 ;
F_7 ( & V_36 -> V_42 ) ;
}
static int F_10 ( char * V_43 , struct V_35 * V_36 )
{
char * V_44 , * V_45 ;
int V_46 ;
F_8 ( V_36 ) ;
V_44 = strchr ( V_43 , '=' ) ;
if ( V_44 == NULL ) {
F_2 ( L_4 ) ;
return - V_32 ;
}
* V_44 ++ = '\0' ;
V_45 = strchr ( V_43 , '.' ) ;
if ( V_45 )
* V_45 ++ = '\0' ;
if ( strcmp ( V_43 , L_5 ) ) {
V_36 -> V_37 = F_11 ( V_43 ) ;
if ( V_36 -> V_37 == F_9 ( V_38 ) ) {
F_2 ( L_6 , V_43 ) ;
return - V_32 ;
}
}
if ( V_45 ) {
if ( ! strcmp ( V_45 , L_7 ) ) {
V_36 -> V_39 = V_7 ;
V_36 -> V_40 = V_9 ;
} else if ( ! strcmp ( V_45 , L_8 ) ) {
V_36 -> V_39 = V_7 ;
V_36 -> V_40 = V_7 ;
} else if ( ! strcmp ( V_45 , L_9 ) ) {
V_36 -> V_39 = V_47 ;
V_36 -> V_40 = V_9 ;
} else if ( ! strcmp ( V_45 , L_10 ) ) {
V_36 -> V_39 = V_47 ;
V_36 -> V_40 = V_7 ;
} else {
F_2 ( L_11 , V_45 ) ;
return - V_32 ;
}
}
V_46 = F_3 ( V_44 , & V_36 -> V_42 ) ;
if ( V_46 )
return - V_32 ;
return 0 ;
}
static void F_12 ( struct V_48 * V_49 )
{
F_13 ( V_49 -> V_50 ||
( V_49 -> V_51 == 0 && V_49 -> V_52 == NULL ) ) ;
if ( V_49 -> V_50 ) {
F_14 ( V_49 -> V_52 ) ;
F_15 ( V_49 ) ;
}
}
static int F_16 ( struct V_48 * V_49 )
{
struct V_35 * V_53 ;
int V_54 ;
F_17 () ;
if ( V_49 -> V_51 < V_49 -> V_50 )
return 0 ;
V_54 = V_49 -> V_50 + 8 ;
V_53 = F_18 ( V_54 , sizeof( * V_49 -> V_52 ) , V_55 ) ;
if ( V_53 == NULL )
return - V_56 ;
if ( V_49 -> V_51 ) {
F_13 ( V_49 -> V_50 && V_49 -> V_52 ) ;
memcpy ( V_53 , V_49 -> V_52 ,
V_49 -> V_51 * sizeof( * V_49 -> V_52 ) ) ;
F_14 ( V_49 -> V_52 ) ;
}
V_49 -> V_52 = V_53 ;
V_49 -> V_50 = V_54 ;
return 0 ;
}
static inline int F_19 ( struct V_35 * V_36 )
{
return ( V_36 -> V_39 != V_12 ||
V_36 -> V_40 != V_12 ) ;
}
static inline int F_20 ( struct V_35 * V_36 )
{
return ( V_36 -> V_37 != F_9 ( V_38 ) ) ;
}
static inline int F_21 ( struct V_35 * V_57 ,
struct V_35 * V_58 )
{
return ( V_57 -> V_39 == V_58 -> V_39 && V_57 -> V_40 == V_58 -> V_40 ) ;
}
static inline int F_22 ( struct V_35 * V_57 ,
struct V_35 * V_58 )
{
return ( V_57 -> V_37 == V_58 -> V_37 ) ;
}
static int F_23 ( struct V_48 * V_49 ,
struct V_35 * V_36 )
{
struct V_35 * V_59 = V_49 -> V_52 ;
int V_60 , V_61 ;
int V_46 , V_62 , V_63 = 0 ;
F_17 () ;
V_61 = F_20 ( V_36 ) ;
V_60 = F_19 ( V_36 ) ;
for ( V_62 = 0 ; V_62 < V_49 -> V_51 ; V_62 ++ ) {
V_59 = & V_49 -> V_52 [ V_62 ] ;
if ( ! F_22 ( V_59 , V_36 ) ) {
if ( V_61 ) {
if ( F_20 ( V_59 ) )
continue;
else
break;
} else {
continue;
}
}
if ( ! F_21 ( V_59 , V_36 ) ) {
if ( V_60 ) {
if ( F_19 ( V_59 ) )
continue;
else
break;
} else {
continue;
}
}
V_63 = 1 ;
break;
}
if ( V_63 ) {
F_13 ( V_62 >= 0 && V_62 < V_49 -> V_51 ) ;
if ( V_36 -> V_42 . V_19 == V_20 ) {
if ( V_62 < V_49 -> V_51 - 1 )
memmove ( & V_49 -> V_52 [ V_62 ] ,
& V_49 -> V_52 [ V_62 + 1 ] ,
( V_49 -> V_51 - V_62 - 1 ) *
sizeof( * V_36 ) ) ;
V_49 -> V_51 -- ;
} else {
memcpy ( & V_49 -> V_52 [ V_62 ] , V_36 , sizeof( * V_36 ) ) ;
}
} else {
F_13 ( V_62 >= 0 && V_62 <= V_49 -> V_51 ) ;
if ( V_36 -> V_42 . V_19 != V_20 ) {
V_46 = F_16 ( V_49 ) ;
if ( V_46 )
return V_46 ;
if ( V_62 < V_49 -> V_51 )
memmove ( & V_49 -> V_52 [ V_62 + 1 ] ,
& V_49 -> V_52 [ V_62 ] ,
( V_49 -> V_51 - V_62 ) * sizeof( * V_36 ) ) ;
memcpy ( & V_49 -> V_52 [ V_62 ] , V_36 , sizeof( * V_36 ) ) ;
V_49 -> V_51 ++ ;
} else {
F_24 ( V_64 , L_12 ) ;
}
}
return 0 ;
}
static int F_25 ( struct V_48 * V_49 ,
enum V_1 V_65 ,
enum V_1 V_66 ,
T_1 V_67 ,
struct V_14 * V_33 )
{
struct V_35 * V_68 ;
int V_62 ;
for ( V_62 = 0 ; V_62 < V_49 -> V_51 ; V_62 ++ ) {
V_68 = & V_49 -> V_52 [ V_62 ] ;
if ( F_9 ( V_67 ) != F_9 ( V_38 ) &&
V_68 -> V_37 != F_9 ( V_38 ) &&
F_9 ( V_67 ) != V_68 -> V_37 )
continue;
if ( V_65 != V_12 && V_68 -> V_39 != V_12 &&
V_65 != V_68 -> V_39 )
continue;
if ( V_66 != V_12 && V_68 -> V_40 != V_12 &&
V_66 != V_68 -> V_40 )
continue;
* V_33 = V_68 -> V_42 ;
return 1 ;
}
return 0 ;
}
static inline int F_26 ( char V_69 )
{
return ( ( V_69 >= '0' && V_69 <= '9' ) ||
( V_69 >= 'a' && V_69 <= 'f' ) ) ;
}
static void F_27 ( const char * V_70 , char * V_71 , int V_72 )
{
const char * V_73 ;
int V_74 ;
V_73 = strrchr ( V_70 , '-' ) ;
if ( V_73 ) {
if ( ( strncmp ( V_73 , L_13 , 4 ) != 0 &&
strncmp ( V_73 , L_14 , 4 ) != 0 ) ||
! F_26 ( V_73 [ 4 ] ) || ! F_26 ( V_73 [ 5 ] ) ||
! F_26 ( V_73 [ 6 ] ) || ! F_26 ( V_73 [ 7 ] ) )
V_73 = NULL ;
}
if ( V_73 == NULL )
V_74 = strlen ( V_70 ) ;
else
V_74 = V_73 - V_70 ;
V_74 = F_28 ( V_74 , V_72 - 1 ) ;
memcpy ( V_71 , V_70 , V_74 ) ;
V_71 [ V_74 ] = '\0' ;
}
static void F_29 ( struct V_75 * V_76 )
{
struct V_77 * V_78 , * V_79 ;
F_12 ( & V_76 -> V_80 ) ;
F_30 (conf_tgt, conf_tgt_next,
&conf->sc_tgts, sct_list) {
F_12 ( & V_78 -> V_81 ) ;
F_31 ( & V_78 -> V_82 ) ;
F_14 ( V_78 ) ;
}
F_13 ( F_32 ( & V_76 -> V_83 ) ) ;
V_76 -> V_84 = 0 ;
V_76 -> V_85 = 0 ;
}
static void F_33 ( struct V_75 * V_76 )
{
F_24 ( V_86 , L_15 , V_76 -> V_87 ) ;
F_29 ( V_76 ) ;
F_31 ( & V_76 -> V_88 ) ;
F_14 ( V_76 ) ;
}
static
struct V_77 * F_34 ( struct V_75 * V_76 ,
const char * V_89 ,
int V_90 )
{
struct V_77 * V_78 ;
F_35 (conf_tgt, &conf->sc_tgts, sct_list) {
if ( strcmp ( V_78 -> V_91 , V_89 ) == 0 )
return V_78 ;
}
if ( ! V_90 )
return NULL ;
V_78 = F_36 ( sizeof( * V_78 ) , V_55 ) ;
if ( V_78 ) {
F_37 ( V_78 -> V_91 , V_89 , sizeof( V_78 -> V_91 ) ) ;
F_15 ( & V_78 -> V_81 ) ;
F_38 ( & V_78 -> V_82 , & V_76 -> V_83 ) ;
}
return V_78 ;
}
static
struct V_75 * F_39 ( const char * V_71 ,
int V_90 )
{
struct V_75 * V_76 ;
F_35 (conf, &sptlrpc_confs, sc_list) {
if ( strcmp ( V_76 -> V_87 , V_71 ) == 0 )
return V_76 ;
}
if ( ! V_90 )
return NULL ;
V_76 = F_36 ( sizeof( * V_76 ) , V_55 ) ;
if ( ! V_76 )
return NULL ;
strcpy ( V_76 -> V_87 , V_71 ) ;
F_15 ( & V_76 -> V_80 ) ;
F_40 ( & V_76 -> V_83 ) ;
F_38 ( & V_76 -> V_88 , & V_92 ) ;
F_24 ( V_86 , L_16 , V_76 -> V_87 ) ;
return V_76 ;
}
static int F_41 ( struct V_75 * V_76 ,
const char * V_93 ,
struct V_35 * V_36 )
{
struct V_77 * V_78 ;
struct V_48 * V_94 ;
if ( strcmp ( V_76 -> V_87 , V_93 ) == 0 ) {
V_94 = & V_76 -> V_80 ;
} else {
V_78 = F_34 ( V_76 , V_93 , 1 ) ;
if ( V_78 ) {
V_94 = & V_78 -> V_81 ;
} else {
F_2 ( L_17 ) ;
return - V_56 ;
}
}
return F_23 ( V_94 , V_36 ) ;
}
static int F_42 ( struct V_95 * V_96 ,
struct V_75 * V_76 )
{
char * V_93 , * V_43 ;
char V_71 [ V_97 ] ;
struct V_35 V_36 ;
int V_46 ;
V_93 = F_43 ( V_96 , 1 ) ;
if ( V_93 == NULL ) {
F_2 ( L_18 ) ;
return - V_32 ;
}
V_43 = F_43 ( V_96 , 2 ) ;
if ( V_43 == NULL ) {
F_2 ( L_19 ) ;
return - V_32 ;
}
F_24 ( V_86 , L_20 , V_93 , V_43 ) ;
if ( strncmp ( V_43 , V_98 , sizeof( V_98 ) - 1 ) != 0 ) {
F_2 ( L_21 , V_43 ) ;
return - V_32 ;
}
V_43 += sizeof( V_98 ) - 1 ;
V_46 = F_10 ( V_43 , & V_36 ) ;
if ( V_46 )
return - V_32 ;
if ( V_76 == NULL ) {
F_27 ( V_93 , V_71 , sizeof( V_71 ) ) ;
F_44 ( & V_99 ) ;
V_76 = F_39 ( V_71 , 0 ) ;
if ( V_76 == NULL ) {
F_2 ( L_22 ) ;
V_46 = - V_56 ;
} else {
V_46 = F_41 ( V_76 , V_93 , & V_36 ) ;
}
F_45 ( & V_99 ) ;
} else {
F_13 ( F_46 ( & V_99 ) ) ;
V_46 = F_41 ( V_76 , V_93 , & V_36 ) ;
}
if ( V_46 == 0 )
V_76 -> V_100 ++ ;
return V_46 ;
}
int F_47 ( struct V_95 * V_96 )
{
return F_42 ( V_96 , NULL ) ;
}
static int F_48 ( const char * V_101 , char * V_16 , int V_72 )
{
char * V_73 ;
int V_74 ;
V_73 = strrchr ( V_101 , '-' ) ;
if ( V_73 == NULL || strcmp ( V_73 , L_23 ) ) {
F_2 ( L_24 , V_101 ) ;
return - V_32 ;
}
V_74 = F_28 ( ( int ) ( V_73 - V_101 ) , V_72 - 1 ) ;
memcpy ( V_16 , V_101 , V_74 ) ;
V_16 [ V_74 ] = '\0' ;
return 0 ;
}
void F_49 ( const char * V_101 )
{
struct V_75 * V_76 ;
char V_71 [ 16 ] ;
if ( F_48 ( V_101 , V_71 , sizeof( V_71 ) ) )
return;
F_44 ( & V_99 ) ;
V_76 = F_39 ( V_71 , 0 ) ;
if ( V_76 ) {
if ( V_76 -> V_85 ) {
F_13 ( V_76 -> V_84 == 0 ) ;
F_29 ( V_76 ) ;
}
V_76 -> V_100 = 0 ;
}
F_45 ( & V_99 ) ;
}
void F_50 ( const char * V_101 )
{
struct V_75 * V_76 ;
char V_71 [ 16 ] ;
if ( F_48 ( V_101 , V_71 , sizeof( V_71 ) ) )
return;
F_44 ( & V_99 ) ;
V_76 = F_39 ( V_71 , 0 ) ;
if ( V_76 ) {
if ( V_76 -> V_84 == 0 )
V_76 -> V_100 ++ ;
V_76 -> V_84 = 1 ;
}
F_45 ( & V_99 ) ;
}
void F_51 ( const char * V_101 )
{
char V_71 [ 16 ] ;
if ( F_48 ( V_101 , V_71 , sizeof( V_71 ) ) )
return;
F_44 ( & V_99 ) ;
F_39 ( V_71 , 1 ) ;
F_45 ( & V_99 ) ;
}
void F_52 ( const char * V_101 )
{
struct V_75 * V_76 ;
char V_71 [ 16 ] ;
if ( F_48 ( V_101 , V_71 , sizeof( V_71 ) ) )
return;
F_44 ( & V_99 ) ;
V_76 = F_39 ( V_71 , 0 ) ;
if ( V_76 )
F_33 ( V_76 ) ;
F_45 ( & V_99 ) ;
}
static inline void F_53 ( struct V_14 * V_33 ,
enum V_1 V_65 ,
enum V_1 V_66 ,
unsigned int V_102 )
{
if ( V_33 -> V_19 == V_34 )
return;
if ( V_65 == V_7 ) {
V_33 -> V_31 |= V_103 ;
} else if ( V_65 == V_47 && V_66 == V_9 ) {
V_33 -> V_31 |= V_103 | V_104 ;
} else if ( V_65 == V_47 && V_66 == V_7 ) {
if ( V_102 && V_33 -> V_19 != V_34 )
V_33 -> V_31 |= V_105 ;
}
}
void F_54 ( enum V_1 V_65 ,
enum V_1 V_66 ,
struct V_106 * V_93 ,
T_1 V_67 ,
struct V_14 * V_33 )
{
struct V_75 * V_76 ;
struct V_77 * V_78 ;
char V_89 [ V_97 ] ;
int V_74 , V_46 = 0 ;
F_27 ( V_93 -> V_107 , V_89 , sizeof( V_89 ) ) ;
F_44 ( & V_99 ) ;
V_76 = F_39 ( V_89 , 0 ) ;
if ( V_76 == NULL )
goto V_108;
V_74 = strlen ( V_93 -> V_107 ) ;
F_13 ( V_74 > 5 ) ;
memcpy ( V_89 , V_93 -> V_107 , V_74 - 5 ) ;
V_89 [ V_74 - 5 ] = '\0' ;
V_78 = F_34 ( V_76 , V_89 , 0 ) ;
if ( V_78 ) {
V_46 = F_25 ( & V_78 -> V_81 ,
V_65 , V_66 , V_67 , V_33 ) ;
if ( V_46 )
goto V_108;
}
V_46 = F_25 ( & V_76 -> V_80 , V_65 , V_66 , V_67 , V_33 ) ;
V_108:
F_45 ( & V_99 ) ;
if ( V_46 == 0 )
F_7 ( V_33 ) ;
F_53 ( V_33 , V_65 , V_66 , 1 ) ;
}
void F_55 ( struct V_2 * V_3 )
{
struct V_109 * V_110 ;
F_13 ( strcmp ( V_3 -> V_4 -> V_5 , V_111 ) == 0 ||
strcmp ( V_3 -> V_4 -> V_5 , V_112 ) == 0 ) ;
F_24 ( V_86 , L_25 , V_3 -> V_113 . V_114 . V_115 . V_107 ) ;
F_56 ( & V_3 -> V_113 . V_114 . V_116 ) ;
V_110 = V_3 -> V_113 . V_114 . V_117 ;
if ( V_110 ) {
F_57 ( & V_110 -> V_118 ) ;
if ( V_110 -> V_119 )
V_110 -> V_120 = F_58 () +
V_121 ;
F_59 ( & V_110 -> V_118 ) ;
}
F_60 ( & V_3 -> V_113 . V_114 . V_116 ) ;
}
int F_61 ( void )
{
F_62 ( & V_99 ) ;
return 0 ;
}
void F_63 ( void )
{
struct V_75 * V_76 , * V_122 ;
F_44 ( & V_99 ) ;
F_30 (conf, conf_next, &sptlrpc_confs, sc_list) {
F_33 ( V_76 ) ;
}
F_13 ( F_32 ( & V_92 ) ) ;
F_45 ( & V_99 ) ;
}
