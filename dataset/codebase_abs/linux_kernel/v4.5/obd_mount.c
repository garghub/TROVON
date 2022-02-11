int F_1 ( struct V_1 * V_2 , char * V_3 ,
struct V_4 * V_5 )
{
struct V_6 * V_7 ;
struct V_8 * V_9 ;
struct V_10 * V_11 = F_2 ( V_2 ) ;
struct V_12 * V_13 = V_11 -> V_14 ;
int V_15 ;
F_3 ( V_13 ) ;
F_3 ( V_5 ) ;
V_9 = F_4 ( sizeof( * V_9 ) , V_16 ) ;
if ( ! V_9 )
return - V_17 ;
F_5 ( V_9 , V_13 -> V_18 ) ;
F_6 ( V_9 , 1 , V_3 ) ;
F_7 ( V_9 , 2 , V_5 , sizeof( * V_5 ) ) ;
F_7 ( V_9 , 3 , & V_2 , sizeof( V_2 ) ) ;
V_7 = F_8 ( V_19 , V_9 ) ;
V_15 = F_9 ( V_13 , sizeof( * V_7 ) , V_7 ) ;
F_10 ( V_7 ) ;
F_11 ( V_9 ) ;
if ( V_15 == - V_20 )
F_12 ( 0x15b , L_1 ,
V_13 -> V_18 , V_3 , V_15 ) ;
if ( V_15 )
F_12 ( 0x15c , L_2 ,
V_13 -> V_18 , V_3 ,
V_15 ) ;
return V_15 ;
}
int F_13 ( struct V_1 * V_2 , char * V_3 ,
struct V_4 * V_5 )
{
struct V_6 * V_7 ;
struct V_8 V_9 ;
struct V_10 * V_11 = F_2 ( V_2 ) ;
struct V_12 * V_13 = V_11 -> V_14 ;
int V_15 ;
if ( ! V_13 )
return - V_21 ;
F_5 ( & V_9 , V_13 -> V_18 ) ;
F_6 ( & V_9 , 1 , V_3 ) ;
if ( V_5 )
F_7 ( & V_9 , 2 , V_5 , sizeof( * V_5 ) ) ;
V_7 = F_8 ( V_22 , & V_9 ) ;
V_15 = F_9 ( V_13 , sizeof( * V_7 ) , V_7 ) ;
F_10 ( V_7 ) ;
return V_15 ;
}
static int F_14 ( char * V_23 , T_1 V_24 , int V_25 ,
char * V_26 , char * V_27 , char * V_28 , char * V_29 )
{
struct V_8 V_9 ;
struct V_6 * V_7 = NULL ;
int V_15 ;
F_15 ( V_30 , L_3 , V_23 ,
V_25 , V_26 , V_27 , V_28 , V_29 ) ;
F_5 ( & V_9 , V_23 ) ;
if ( V_26 )
F_6 ( & V_9 , 1 , V_26 ) ;
if ( V_27 )
F_6 ( & V_9 , 2 , V_27 ) ;
if ( V_28 )
F_6 ( & V_9 , 3 , V_28 ) ;
if ( V_29 )
F_6 ( & V_9 , 4 , V_29 ) ;
V_7 = F_8 ( V_25 , & V_9 ) ;
V_7 -> V_31 = V_24 ;
V_15 = F_16 ( V_7 ) ;
F_10 ( V_7 ) ;
return V_15 ;
}
static int F_17 ( char * V_32 , char * type , char * V_33 ,
char * V_26 , char * V_27 , char * V_28 , char * V_29 )
{
int V_15 ;
F_15 ( V_34 , L_4 , V_32 , type ) ;
V_15 = F_14 ( V_32 , 0 , V_35 , type , V_33 , NULL , NULL ) ;
if ( V_15 ) {
F_18 ( L_5 , V_32 , V_15 ) ;
return V_15 ;
}
V_15 = F_14 ( V_32 , 0 , V_36 , V_26 , V_27 , V_28 , V_29 ) ;
if ( V_15 ) {
F_18 ( L_6 , V_32 , V_15 ) ;
F_14 ( V_32 , 0 , V_37 , NULL , NULL , NULL , NULL ) ;
}
return V_15 ;
}
int F_19 ( struct V_1 * V_2 )
{
struct V_38 * V_39 = NULL ;
struct V_10 * V_11 = F_2 ( V_2 ) ;
struct V_12 * V_40 ;
struct V_41 * exp ;
struct V_42 * V_33 ;
T_2 V_43 ;
T_1 V_24 ;
char V_44 [ V_45 ] ;
char * V_46 = NULL , * V_47 = NULL , * V_48 = NULL ;
char * V_49 ;
int V_15 = 0 , V_50 = 0 , V_51 ;
F_3 ( V_11 -> V_52 ) ;
V_49 = V_11 -> V_52 -> V_53 ;
if ( F_20 ( V_49 , & V_24 , & V_49 ) == 0 )
V_50 ++ ;
if ( V_50 == 0 ) {
F_18 ( L_7 ) ;
return - V_20 ;
}
F_21 ( & V_54 ) ;
F_22 ( V_24 , V_44 , sizeof( V_44 ) ) ;
V_46 = F_23 ( V_16 ,
L_8 , V_55 , V_44 ) ;
V_47 = F_23 ( V_16 , L_9 , V_46 , V_50 ) ;
if ( ! V_46 || ! V_47 ) {
V_15 = - V_17 ;
goto V_56;
}
V_48 = V_11 -> V_52 -> V_57 ? V_11 -> V_52 -> V_57 : L_10 ;
V_39 = F_4 ( sizeof( * V_39 ) , V_16 ) ;
if ( ! V_39 ) {
V_15 = - V_17 ;
goto V_56;
}
V_40 = F_24 ( V_46 ) ;
if ( V_40 && ! V_40 -> V_58 ) {
int V_59 ;
V_15 = F_25 ( NULL , V_40 -> V_60 ,
strlen ( V_61 ) , V_61 ,
strlen ( V_48 ) , V_48 , NULL ) ;
if ( V_15 )
goto V_56;
F_26 ( & V_40 -> V_62 . V_63 . V_64 ) ;
if ( F_27 ( V_11 -> V_52 ) ) {
int V_65 ;
int V_66 = sizeof( * V_39 ) ;
T_3 * V_67 = & V_11 -> V_52 -> V_68 ;
V_15 = F_28 ( NULL , V_40 -> V_60 ,
strlen ( V_69 ) , V_69 ,
& V_66 , V_39 , NULL ) ;
F_3 ( V_15 == 0 ) ;
V_65 = F_29 ( V_39 , V_70 ) ;
if ( V_65 ^ ! ( * V_67 & V_71 ) ) {
F_30 (
L_11 ,
V_65 ? L_12 : L_13 ) ;
if ( V_65 )
* V_67 &= ~ V_71 ;
else
* V_67 |= V_71 ;
}
}
V_59 = 0 ;
V_59 ++ ;
F_15 ( V_34 , L_14 , V_46 ,
V_59 ) ;
V_15 = F_25 ( NULL , V_40 -> V_60 ,
sizeof( V_72 ) ,
V_72 ,
sizeof( V_59 ) , & V_59 , NULL ) ;
V_15 = 0 ;
goto V_73;
}
F_15 ( V_34 , L_15 , V_46 ) ;
V_50 = 0 ;
V_49 = V_11 -> V_52 -> V_53 ;
while ( F_20 ( V_49 , & V_24 , & V_49 ) == 0 ) {
V_15 = F_14 ( V_46 , V_24 ,
V_74 , V_47 , NULL , NULL , NULL ) ;
V_50 ++ ;
if ( * V_49 == ':' )
break;
}
if ( V_50 == 0 ) {
F_18 ( L_7 ) ;
V_15 = - V_20 ;
goto V_56;
}
V_11 -> V_52 -> V_75 = 1 ;
V_33 = F_4 ( sizeof( * V_33 ) , V_16 ) ;
if ( ! V_33 ) {
V_15 = - V_17 ;
goto V_56;
}
F_31 ( V_43 ) ;
F_32 ( V_43 , V_33 ) ;
V_15 = F_17 ( V_46 , V_76 ,
( char * ) V_33 -> V_33 , V_77 ,
V_47 , NULL , NULL ) ;
F_11 ( V_33 ) ;
if ( V_15 )
goto V_56;
V_50 = 1 ;
while ( V_49 && ( ( * V_49 == ':' ||
F_33 ( V_49 , V_78 , & V_49 ) == 0 ) ) ) {
sprintf ( V_47 , L_9 , V_46 , V_50 ) ;
V_51 = 0 ;
while ( F_34 ( V_49 , & V_24 , & V_49 ) == 0 ) {
V_51 ++ ;
V_15 = F_14 ( V_46 , V_24 ,
V_74 , V_47 , NULL , NULL , NULL ) ;
if ( * V_49 == ':' )
break;
}
if ( V_51 > 0 ) {
V_15 = F_14 ( V_46 , 0 , V_79 ,
V_47 , NULL , NULL , NULL ) ;
V_50 ++ ;
} else {
break;
}
}
V_11 -> V_52 -> V_75 = V_50 ;
V_40 = F_24 ( V_46 ) ;
if ( ! V_40 ) {
F_18 ( L_16 , V_46 ) ;
V_15 = - V_80 ;
goto V_56;
}
V_15 = F_25 ( NULL , V_40 -> V_60 ,
strlen ( V_61 ) , V_61 ,
strlen ( V_48 ) , V_48 , NULL ) ;
if ( V_15 )
goto V_56;
F_35 ( & V_40 -> V_62 . V_63 . V_64 , 1 ) ;
V_39 -> V_81 = V_82 | V_83 |
V_84 | V_85 |
V_86 ;
#if V_87 < F_36 ( 3 , 2 , 50 , 0 )
V_39 -> V_81 |= V_88 ;
#else
#warning "LU-1644: Remove old OBD_CONNECT_MNE_SWAB fixup and imp_need_mne_swab"
#endif
if ( F_27 ( V_11 -> V_52 ) &&
V_11 -> V_52 -> V_68 & V_71 )
V_39 -> V_81 &= ~ V_85 ;
V_39 -> V_89 = V_87 ;
V_15 = F_37 ( NULL , & exp , V_40 , & ( V_40 -> V_42 ) , V_39 , NULL ) ;
if ( V_15 ) {
F_18 ( L_17 , V_15 ) ;
goto V_73;
}
V_40 -> V_62 . V_63 . V_90 = exp ;
V_73:
V_11 -> V_14 = V_40 ;
V_56:
F_38 ( & V_54 ) ;
F_11 ( V_39 ) ;
F_11 ( V_46 ) ;
F_11 ( V_47 ) ;
return V_15 ;
}
static int F_39 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = F_2 ( V_2 ) ;
struct V_12 * V_40 ;
char * V_47 = NULL , * V_49 = NULL ;
int V_50 , V_15 = 0 , V_91 = 0 ;
if ( ! V_11 )
return - V_21 ;
V_40 = V_11 -> V_14 ;
if ( ! V_40 )
return - V_21 ;
V_11 -> V_14 = NULL ;
F_21 ( & V_54 ) ;
F_3 ( F_40 ( & V_40 -> V_62 . V_63 . V_64 ) > 0 ) ;
if ( ! F_41 ( & V_40 -> V_62 . V_63 . V_64 ) ) {
F_15 ( V_34 , L_18 ,
F_40 ( & V_40 -> V_62 . V_63 . V_64 ) ) ;
V_15 = - V_92 ;
goto V_73;
}
V_40 -> V_93 = 1 ;
if ( V_40 -> V_62 . V_63 . V_90 ) {
V_15 = F_42 ( V_40 -> V_62 . V_63 . V_90 ) ;
if ( V_15 )
F_15 ( V_34 , L_19 , V_15 ) ;
}
V_91 = strlen ( V_40 -> V_18 ) + 6 ;
V_47 = F_4 ( V_91 , V_16 ) ;
if ( V_47 ) {
strcpy ( V_47 , V_40 -> V_18 ) ;
V_49 = V_47 + strlen ( V_47 ) ;
}
V_15 = F_43 ( V_40 ) ;
if ( V_15 )
goto V_73;
if ( ! V_47 ) {
V_15 = - V_17 ;
goto V_73;
}
for ( V_50 = 0 ; V_50 < V_11 -> V_52 -> V_75 ; V_50 ++ ) {
sprintf ( V_49 , L_20 , V_50 ) ;
V_15 = F_14 ( V_55 , 0 , V_94 ,
V_47 , NULL , NULL , NULL ) ;
if ( V_15 )
F_18 ( L_21 ,
V_47 , V_15 ) ;
}
V_73:
F_11 ( V_47 ) ;
F_38 ( & V_54 ) ;
return V_15 ;
}
static struct V_10 * F_44 ( struct V_1 * V_2 )
{
struct V_10 * V_11 ;
V_11 = F_4 ( sizeof( * V_11 ) , V_16 ) ;
if ( ! V_11 )
return NULL ;
V_11 -> V_52 = F_4 ( sizeof( * V_11 -> V_52 ) , V_16 ) ;
if ( ! V_11 -> V_52 ) {
F_11 ( V_11 ) ;
return NULL ;
}
V_11 -> V_52 -> V_95 = 0 ;
V_11 -> V_52 -> V_96 = 0 ;
V_11 -> V_52 -> V_97 = 0 ;
F_45 ( V_2 ) = V_11 ;
F_35 ( & V_11 -> V_98 , 1 ) ;
V_11 -> V_99 = V_100 ;
return V_11 ;
}
static int F_46 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = F_2 ( V_2 ) ;
F_3 ( V_11 != NULL ) ;
F_15 ( V_34 , L_22 , V_11 ) ;
F_3 ( F_40 ( & V_11 -> V_98 ) == 0 ) ;
if ( V_11 -> V_52 != NULL ) {
F_11 ( V_11 -> V_52 -> V_53 ) ;
F_11 ( V_11 -> V_52 -> V_101 ) ;
F_11 ( V_11 -> V_52 -> V_57 ) ;
F_11 ( V_11 -> V_52 -> V_102 ) ;
if ( V_11 -> V_52 -> V_95 )
F_11 ( V_11 -> V_52 -> V_103 ) ;
F_11 ( V_11 -> V_52 -> V_104 ) ;
F_11 ( V_11 -> V_52 -> V_105 ) ;
F_11 ( V_11 -> V_52 -> V_106 ) ;
F_11 ( V_11 -> V_52 ) ;
}
F_3 ( V_11 -> V_107 == NULL ) ;
F_11 ( V_11 ) ;
F_45 ( V_2 ) = NULL ;
return 0 ;
}
static int F_47 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = F_2 ( V_2 ) ;
F_3 ( V_11 != NULL ) ;
F_15 ( V_34 , L_23 , V_2 , F_40 ( & V_11 -> V_98 ) ) ;
if ( F_41 ( & V_11 -> V_98 ) ) {
F_46 ( V_2 ) ;
return 1 ;
}
return 0 ;
}
static int F_48 ( const char * V_108 , char * V_109 ,
const char * * V_110 )
{
const char * V_111 ;
V_111 = V_108 + F_49 ( V_108 , 8 ) ;
for (; V_111 > V_108 && * V_111 != '-' && * V_111 != ':' ; V_111 -- )
;
if ( V_111 == V_108 )
return - V_20 ;
if ( V_109 != NULL ) {
strncpy ( V_109 , V_108 , V_111 - V_108 ) ;
V_109 [ V_111 - V_108 ] = '\0' ;
}
if ( V_110 != NULL )
* V_110 = V_111 ;
return 0 ;
}
static int F_50 ( const char * V_108 , T_3 * V_112 ,
const char * * V_110 )
{
unsigned long V_113 ;
int V_15 ;
const char * V_111 ;
V_15 = F_48 ( V_108 , NULL , & V_111 ) ;
if ( V_15 != 0 )
return V_15 ;
V_111 ++ ;
if ( strncmp ( V_111 , L_24 , 3 ) == 0 )
V_15 = V_114 ;
else if ( strncmp ( V_111 , L_25 , 3 ) == 0 )
V_15 = V_115 ;
else
return - V_20 ;
V_111 += 3 ;
if ( strncmp ( V_111 , L_26 , 3 ) == 0 ) {
if ( V_110 != NULL )
* V_110 = V_111 + 3 ;
return V_15 | V_116 ;
}
V_113 = F_51 ( V_111 , ( char * * ) V_110 , 16 ) ;
if ( V_112 != NULL )
* V_112 = V_113 ;
if ( V_110 != NULL && strncmp ( V_117 , * V_110 + 1 ,
sizeof( V_117 ) - 1 ) == 0 )
* V_110 += sizeof( V_117 ) ;
return V_15 ;
}
int F_52 ( struct V_1 * V_2 )
{
int V_15 ;
F_15 ( V_34 , L_27 , V_2 ) ;
V_15 = F_39 ( V_2 ) ;
if ( V_15 && ( V_15 != - V_21 ) ) {
if ( V_15 != - V_92 ) {
F_18 ( L_28 , V_15 ) ;
return V_15 ;
}
F_15 ( V_34 , L_29 ) ;
}
F_47 ( V_2 ) ;
F_53 () ;
return V_15 ;
}
static void F_54 ( struct V_118 * V_119 )
{
int V_50 ;
F_55 ( V_34 , L_30 ) ;
if ( F_27 ( V_119 ) )
F_55 ( V_34 , L_31 , V_119 -> V_101 ) ;
F_55 ( V_34 , L_32 , V_119 -> V_53 ) ;
F_55 ( V_34 , L_33 , V_119 -> V_68 ) ;
if ( V_119 -> V_102 )
F_55 ( V_34 , L_34 , V_119 -> V_102 ) ;
if ( V_119 -> V_96 )
F_55 ( V_34 , L_35 ,
V_119 -> V_96 ) ;
if ( V_119 -> V_97 )
F_55 ( V_34 , L_36 ,
V_119 -> V_97 ) ;
for ( V_50 = 0 ; V_50 < V_119 -> V_95 ; V_50 ++ ) {
F_55 ( V_34 , L_37 , V_50 ,
V_119 -> V_103 [ V_50 ] ) ;
}
}
int F_56 ( struct V_1 * V_2 , char * V_108 )
{
struct V_10 * V_11 = F_2 ( V_2 ) ;
struct V_118 * V_119 = V_11 -> V_52 ;
T_3 V_113 ;
int V_50 , V_15 ;
V_15 = F_50 ( V_108 , & V_113 , NULL ) ;
if ( V_15 != V_115 )
return 0 ;
F_15 ( V_34 , L_38 , V_108 ,
V_113 , V_119 -> V_95 , V_119 -> V_53 ) ;
for ( V_50 = 0 ; V_50 < V_119 -> V_95 ; V_50 ++ ) {
if ( V_113 == V_119 -> V_103 [ V_50 ] ) {
F_57 ( L_39 , V_108 ) ;
return 1 ;
}
}
return 0 ;
}
static int F_58 ( struct V_118 * V_119 , const char * V_49 )
{
const char * V_26 = V_49 , * V_27 ;
T_3 V_113 , * V_120 ;
int V_15 = 0 , V_121 ;
V_121 = strlen ( V_49 ) / 8 + 1 ;
V_120 = F_59 ( V_121 , sizeof( V_113 ) , V_16 ) ;
if ( ! V_120 )
return - V_17 ;
while ( * V_26 && * V_26 != ' ' && * V_26 != ',' ) {
V_26 ++ ;
V_15 = F_50 ( V_26 , & V_113 , & V_27 ) ;
if ( V_15 < 0 ) {
F_18 ( L_40 ,
V_26 , V_15 ) ;
break;
}
if ( V_15 == V_115 )
V_120 [ V_119 -> V_95 ++ ] = V_113 ;
else
F_15 ( V_34 , L_41 ,
( V_122 ) ( V_27 - V_26 ) , V_26 , V_15 ) ;
V_26 = V_27 ;
if ( V_119 -> V_95 >= V_121 )
break;
}
if ( V_15 >= 0 )
V_15 = 0 ;
if ( V_119 -> V_95 ) {
V_119 -> V_103 = F_59 ( V_119 -> V_95 ,
sizeof( V_113 ) , V_16 ) ;
if ( V_119 -> V_103 ) {
memcpy ( V_119 -> V_103 , V_120 ,
sizeof( V_113 ) * V_119 -> V_95 ) ;
} else {
V_15 = - V_17 ;
V_119 -> V_95 = 0 ;
}
}
F_11 ( V_120 ) ;
return V_15 ;
}
static int F_60 ( struct V_118 * V_119 , char * V_49 )
{
char * V_123 ;
int V_124 ;
F_11 ( V_119 -> V_57 ) ;
V_119 -> V_57 = NULL ;
V_123 = strchr ( V_49 , ',' ) ;
if ( V_123 == NULL )
V_124 = strlen ( V_49 ) ;
else
V_124 = V_123 - V_49 ;
V_119 -> V_57 = F_4 ( V_124 + 1 , V_16 ) ;
if ( ! V_119 -> V_57 )
return - V_17 ;
memcpy ( V_119 -> V_57 , V_49 , V_124 ) ;
V_119 -> V_57 [ V_124 ] = '\0' ;
return 0 ;
}
static int F_61 ( char * * V_125 , char * V_49 )
{
char * V_123 ;
int V_124 ;
if ( ( V_125 == NULL ) || ( V_49 == NULL ) )
return - V_20 ;
F_11 ( * V_125 ) ;
* V_125 = NULL ;
V_123 = strchr ( V_49 , ',' ) ;
if ( V_123 == NULL )
V_124 = strlen ( V_49 ) ;
else
V_124 = V_123 - V_49 ;
* V_125 = F_4 ( V_124 + 1 , V_16 ) ;
if ( ! * V_125 )
return - V_17 ;
memcpy ( * V_125 , V_49 , V_124 ) ;
( * V_125 ) [ V_124 ] = '\0' ;
return 0 ;
}
static int F_62 ( struct V_118 * V_119 , char * * V_49 )
{
T_1 V_24 ;
char * V_123 = * V_49 ;
char * V_126 ;
int V_124 ;
int V_127 = 0 ;
while ( F_34 ( V_123 , & V_24 , & V_123 ) == 0 )
;
V_124 = V_123 - * V_49 ;
if ( V_124 == 0 ) {
F_12 ( 0x159 , L_42 , * V_49 ) ;
return - V_20 ;
}
if ( V_119 -> V_104 != NULL )
V_127 = strlen ( V_119 -> V_104 ) + 1 ;
V_126 = F_4 ( V_127 + V_124 + 1 , V_16 ) ;
if ( ! V_126 )
return - V_17 ;
if ( V_119 -> V_104 != NULL ) {
memcpy ( V_126 , V_119 -> V_104 , V_127 ) ;
V_126 [ V_127 - 1 ] = ':' ;
F_11 ( V_119 -> V_104 ) ;
}
memcpy ( V_126 + V_127 , * V_49 , V_124 ) ;
V_126 [ V_127 + V_124 ] = '\0' ;
V_119 -> V_104 = V_126 ;
* V_49 = V_123 ;
return 0 ;
}
static int F_63 ( char * V_128 , struct V_118 * V_119 )
{
char * V_26 , * V_27 , * V_129 = NULL ;
struct V_118 * V_130 = (struct V_118 * ) V_128 ;
int V_15 = 0 ;
F_3 ( V_119 ) ;
if ( ! V_128 ) {
F_12 ( 0x162 , L_43 ) ;
return - V_20 ;
}
if ( ( V_130 -> V_131 & 0xffffff00 ) == ( V_132 & 0xffffff00 ) ) {
F_12 ( 0x163 , L_44 ,
V_133 ) ;
return - V_20 ;
}
V_119 -> V_131 = V_132 ;
V_119 -> V_106 = F_4 ( V_134 , V_16 ) ;
if ( ! V_119 -> V_106 )
return - V_17 ;
V_119 -> V_106 [ 0 ] = '\0' ;
V_26 = V_128 ;
while ( * V_26 ) {
int V_135 = 0 ;
int V_136 = V_137 ;
while ( * V_26 == ' ' || * V_26 == ',' )
V_26 ++ ;
if ( strncmp ( V_26 , L_45 , 11 ) == 0 ) {
V_119 -> V_68 |= V_138 ;
V_135 ++ ;
} else if ( strncmp ( V_26 , L_46 , 19 ) == 0 ) {
V_119 -> V_96 = F_64 ( int ,
F_51 ( V_26 + 19 , NULL , 10 ) , V_136 ) ;
V_135 ++ ;
} else if ( strncmp ( V_26 , L_47 , 19 ) == 0 ) {
V_119 -> V_97 = F_64 ( int ,
F_51 ( V_26 + 19 , NULL , 10 ) , V_136 ) ;
V_135 ++ ;
} else if ( strncmp ( V_26 , L_48 , 4 ) == 0 ) {
V_119 -> V_68 |= V_71 ;
V_135 ++ ;
} else if ( strncmp ( V_26 , L_49 , 5 ) == 0 ) {
V_119 -> V_68 |= V_139 ;
V_135 ++ ;
} else if ( strncmp ( V_26 , L_50 , 5 ) == 0 ) {
V_119 -> V_68 |= V_140 ;
V_135 ++ ;
} else if ( strncmp ( V_26 , L_51 , 7 ) == 0 ) {
V_119 -> V_68 |= V_141 ;
V_135 ++ ;
} else if ( strncmp ( V_26 , V_78 ,
sizeof( V_78 ) - 1 ) == 0 ) {
V_27 = V_26 + sizeof( V_78 ) - 1 ;
V_15 = F_62 ( V_119 , & V_27 ) ;
if ( V_15 )
goto V_142;
V_135 ++ ;
} else if ( strncmp ( V_26 , L_52 , 9 ) == 0 ) {
V_119 -> V_68 |= V_143 ;
V_135 ++ ;
} else if ( strncmp ( V_26 , L_53 , 6 ) == 0 ) {
V_119 -> V_68 |= V_144 ;
V_135 ++ ;
} else if ( strncmp ( V_26 , L_54 , 6 ) == 0 ) {
V_119 -> V_68 |= V_145 ;
V_135 ++ ;
} else if ( strncmp ( V_26 , L_55 , 10 ) == 0 ) {
V_119 -> V_68 |= V_146 ;
V_135 ++ ;
} else if ( strncmp ( V_26 , L_56 , 7 ) == 0 ) {
V_15 = F_60 ( V_119 , V_26 + 7 ) ;
if ( V_15 )
goto V_142;
V_135 ++ ;
} else if ( strncmp ( V_26 , L_57 , 8 ) == 0 ) {
V_15 = F_58 ( V_119 , V_26 + 7 ) ;
if ( V_15 )
goto V_142;
V_135 ++ ;
} else if ( strncmp ( V_26 , L_58 , 3 ) == 0 ) {
V_119 -> V_68 |= V_147 ;
V_135 ++ ;
} else if ( strncmp ( V_26 , L_59 , 7 ) == 0 ) {
V_15 = F_61 ( & V_119 -> V_101 , V_26 + 7 ) ;
if ( V_15 )
goto V_142;
V_135 ++ ;
} else if ( strncmp ( V_26 , L_60 , 6 ) == 0 ) {
T_4 V_124 , V_148 ;
char * V_123 = strchr ( V_26 + 6 , ',' ) ;
if ( V_123 == NULL )
V_124 = strlen ( V_26 ) ;
else
V_124 = V_123 - V_26 ;
V_124 -= 6 ;
V_148 = strlen ( V_119 -> V_106 ) ;
if ( V_148 + V_124 + 1 >= V_134 )
return - V_149 ;
strncat ( V_119 -> V_106 , V_26 + 6 , V_124 ) ;
V_119 -> V_106 [ V_148 + V_124 ] = '\0' ;
F_65 ( V_119 -> V_106 , L_61 , V_134 ) ;
V_135 ++ ;
} else if ( strncmp ( V_26 , L_62 , 4 ) == 0 ) {
V_15 = F_61 ( & V_119 -> V_105 , V_26 + 4 ) ;
if ( V_15 )
goto V_142;
V_135 ++ ;
}
else if ( strncmp ( V_26 , L_63 , 7 ) == 0 ) {
V_129 = V_26 + 7 ;
* V_26 = '\0' ;
break;
}
V_27 = strchr ( V_26 , ',' ) ;
if ( V_27 == NULL ) {
if ( V_135 )
* V_26 = '\0' ;
break;
}
V_27 ++ ;
if ( V_135 )
memmove ( V_26 , V_27 , strlen ( V_27 ) + 1 ) ;
else
V_26 = V_27 ;
}
if ( ! V_129 ) {
F_12 ( 0x164 , L_64 ) ;
goto V_142;
}
V_26 = strstr ( V_129 , L_65 ) ;
if ( V_26 ) {
++ V_26 ;
V_119 -> V_68 |= V_150 ;
while ( * ++ V_26 == '/' )
;
V_119 -> V_101 = F_23 ( V_16 , L_66 , V_26 ) ;
if ( ! V_119 -> V_101 )
return - V_17 ;
}
V_119 -> V_53 = F_4 ( strlen ( V_129 ) + 1 , V_16 ) ;
if ( ! V_119 -> V_53 )
return - V_17 ;
strcpy ( V_119 -> V_53 , V_129 ) ;
V_26 = V_128 + strlen ( V_128 ) - 1 ;
while ( V_26 >= V_128 && ( * V_26 == ',' || * V_26 == ' ' ) )
* V_26 -- = 0 ;
if ( * V_128 != 0 ) {
V_119 -> V_102 = F_4 ( strlen ( V_128 ) + 1 , V_16 ) ;
if ( ! V_119 -> V_102 )
return - V_17 ;
strcpy ( V_119 -> V_102 , V_128 ) ;
}
F_54 ( V_119 ) ;
V_119 -> V_131 = V_132 ;
return V_15 ;
V_142:
F_18 ( L_67 , V_128 ) ;
return - V_20 ;
}
static int F_66 ( struct V_1 * V_2 , void * V_39 , int V_151 )
{
struct V_118 * V_119 ;
struct V_152 * V_153 = V_39 ;
struct V_10 * V_11 ;
int V_15 ;
F_15 ( V_34 | V_154 , L_68 , V_2 ) ;
V_11 = F_44 ( V_2 ) ;
if ( ! V_11 )
return - V_17 ;
V_119 = V_11 -> V_52 ;
F_67 () ;
F_68 () ;
if ( F_63 ( ( V_153 -> V_155 ) , V_119 ) ) {
F_47 ( V_2 ) ;
V_15 = - V_20 ;
goto V_73;
}
if ( F_27 ( V_119 ) ) {
F_15 ( V_34 , L_69 , V_119 -> V_101 ) ;
if ( V_156 == NULL )
F_69 ( L_70 ) ;
if ( V_156 == NULL ) {
F_12 ( 0x165 , L_71 ) ;
F_47 ( V_2 ) ;
V_15 = - V_157 ;
} else {
V_15 = F_19 ( V_2 ) ;
if ( V_15 ) {
F_47 ( V_2 ) ;
goto V_73;
}
V_15 = (* V_156)( V_2 , V_153 -> V_158 ) ;
}
} else {
F_18 ( L_72 ) ;
V_15 = - V_20 ;
}
goto V_73;
V_73:
if ( V_15 ) {
F_18 ( L_73 ,
F_2 ( V_2 ) ? V_119 -> V_53 : L_10 , V_15 ) ;
} else {
F_15 ( V_159 , L_74 ,
V_119 -> V_53 ) ;
}
F_70 () ;
return V_15 ;
}
void F_71 ( int (* F_72)( struct V_1 * V_2 ,
struct V_160 * V_161 ) )
{
V_156 = F_72 ;
}
void F_73 ( void (* F_72)( struct V_1 * V_2 ) )
{
V_162 = F_72 ;
}
struct V_163 * F_74 ( struct V_164 * V_165 , int V_67 ,
const char * V_129 , void * V_39 )
{
struct V_152 V_153 = {
. V_155 = V_39 ,
. V_158 = NULL
} ;
return F_75 ( V_165 , V_67 , & V_153 , F_66 ) ;
}
static void F_76 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = F_2 ( V_2 ) ;
if ( V_162 && V_11 )
(* V_162)( V_2 ) ;
F_77 ( V_2 ) ;
}
int F_78 ( void )
{
return F_79 ( & V_166 ) ;
}
int F_80 ( void )
{
return F_81 ( & V_166 ) ;
}
