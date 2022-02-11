int F_1 ( struct V_1 * V_2 , char * V_3 ,
struct V_4 * V_5 )
{
struct V_6 * V_7 ;
struct V_8 * V_9 ;
struct V_10 * V_11 = F_2 ( V_2 ) ;
struct V_12 * V_13 = V_11 -> V_14 ;
int V_15 ;
V_16 ;
F_3 ( V_13 ) ;
F_3 ( V_5 ) ;
F_4 ( V_9 ) ;
if ( V_9 == NULL )
RETURN ( - V_17 ) ;
F_5 ( V_9 , V_13 -> V_18 ) ;
F_6 ( V_9 , 1 , V_3 ) ;
F_7 ( V_9 , 2 , V_5 , sizeof( * V_5 ) ) ;
F_7 ( V_9 , 3 , & V_2 , sizeof( V_2 ) ) ;
V_7 = F_8 ( V_19 , V_9 ) ;
V_15 = F_9 ( V_13 , sizeof( * V_7 ) , V_7 ) ;
F_10 ( V_7 ) ;
F_11 ( V_9 ) ;
if ( V_15 == - V_20 )
F_12 ( 0x15b , L_1
L_2
L_3
L_4 ,
V_13 -> V_18 , V_3 , V_15 ) ;
if ( V_15 )
F_12 ( 0x15c , L_5
L_6
L_7
L_8
L_9
L_10 , V_13 -> V_18 , V_3 ,
V_15 ) ;
RETURN ( V_15 ) ;
}
int F_13 ( struct V_1 * V_2 , char * V_3 ,
struct V_4 * V_5 )
{
struct V_6 * V_7 ;
struct V_8 V_9 ;
struct V_10 * V_11 = F_2 ( V_2 ) ;
struct V_12 * V_13 = V_11 -> V_14 ;
int V_15 ;
V_16 ;
if ( ! V_13 )
RETURN ( - V_21 ) ;
F_5 ( & V_9 , V_13 -> V_18 ) ;
F_6 ( & V_9 , 1 , V_3 ) ;
if ( V_5 )
F_7 ( & V_9 , 2 , V_5 , sizeof( * V_5 ) ) ;
V_7 = F_8 ( V_22 , & V_9 ) ;
V_15 = F_9 ( V_13 , sizeof( * V_7 ) , V_7 ) ;
F_10 ( V_7 ) ;
RETURN ( V_15 ) ;
}
int F_14 ( char * V_23 , T_1 V_24 , int V_25 ,
char * V_26 , char * V_27 , char * V_28 , char * V_29 )
{
struct V_8 V_9 ;
struct V_6 * V_7 = NULL ;
int V_15 ;
F_15 ( V_30 , L_11 , V_23 ,
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
return ( V_15 ) ;
}
int F_17 ( char * V_32 , char * type , char * V_33 ,
char * V_26 , char * V_27 , char * V_28 , char * V_29 )
{
int V_15 ;
F_15 ( V_34 , L_12 , V_32 , type ) ;
V_15 = F_14 ( V_32 , 0 , V_35 , type , V_33 , 0 , 0 ) ;
if ( V_15 ) {
F_18 ( L_13 , V_32 , V_15 ) ;
return V_15 ;
}
V_15 = F_14 ( V_32 , 0 , V_36 , V_26 , V_27 , V_28 , V_29 ) ;
if ( V_15 ) {
F_18 ( L_14 , V_32 , V_15 ) ;
F_14 ( V_32 , 0 , V_37 , 0 , 0 , 0 , 0 ) ;
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
char * V_44 = NULL , * V_45 = NULL , * V_46 = NULL ;
char * V_47 ;
int V_48 ;
int V_15 = 0 , V_49 = 0 , V_50 , V_51 ;
V_16 ;
F_3 ( V_11 -> V_52 ) ;
if ( F_20 ( V_11 ) ) {
V_47 = V_11 -> V_52 -> V_53 ;
if ( V_11 -> V_52 -> V_53 &&
( F_21 ( V_11 -> V_52 -> V_53 , & V_24 , & V_47 ) == 0 ) ) {
V_49 ++ ;
} else if ( F_22 ( V_11 ) ) {
T_3 V_54 ;
while ( ( V_15 = F_23 ( V_49 ++ , & V_54 ) ) != - V_21 ) {
if ( F_24 ( F_25 ( V_54 . V_24 ) ) == V_55 )
continue;
V_24 = V_54 . V_24 ;
V_49 ++ ;
break;
}
}
} else {
V_47 = V_11 -> V_52 -> V_56 ;
if ( F_21 ( V_47 , & V_24 , & V_47 ) == 0 )
V_49 ++ ;
}
if ( V_49 == 0 ) {
F_18 ( L_15 ) ;
RETURN ( - V_20 ) ;
}
F_26 ( & V_57 ) ;
V_51 = strlen ( V_58 ) + strlen ( F_27 ( V_24 ) ) + 1 ;
F_28 ( V_44 , V_51 ) ;
F_28 ( V_45 , V_51 + 2 ) ;
if ( ! V_44 || ! V_45 )
GOTO ( V_59 , V_15 = - V_17 ) ;
sprintf ( V_44 , L_16 , V_58 , F_27 ( V_24 ) ) ;
V_46 = V_11 -> V_52 -> V_60 ? V_11 -> V_52 -> V_60 : L_17 ;
F_4 ( V_39 ) ;
if ( V_39 == NULL )
GOTO ( V_59 , V_15 = - V_17 ) ;
V_40 = F_29 ( V_44 ) ;
if ( V_40 && ! V_40 -> V_61 ) {
V_15 = F_30 ( NULL , V_40 -> V_62 ,
strlen ( V_63 ) , V_63 ,
strlen ( V_46 ) , V_46 , NULL ) ;
if ( V_15 )
GOTO ( V_59 , V_15 ) ;
F_31 ( & V_40 -> V_64 . V_65 . V_66 ) ;
if ( F_32 ( V_11 -> V_52 ) ) {
int V_67 ;
int V_68 = sizeof( * V_39 ) ;
T_4 * V_69 = & V_11 -> V_52 -> V_70 ;
V_15 = F_33 ( NULL , V_40 -> V_62 ,
strlen ( V_71 ) , V_71 ,
& V_68 , V_39 , NULL ) ;
F_3 ( V_15 == 0 ) ;
V_67 = F_34 ( V_39 , V_72 ) ;
if ( V_67 ^ ! ( * V_69 & V_73 ) ) {
F_35 (
L_18
L_19
L_20
L_21 ,
V_67 ? L_22 : L_23 ) ;
if ( V_67 )
* V_69 &= ~ V_73 ;
else
* V_69 |= V_73 ;
}
}
V_48 = 0 ;
if ( F_22 ( V_11 ) ) {
F_15 ( V_34 , L_24 ) ;
V_48 = 1 ;
}
V_48 ++ ;
F_15 ( V_34 , L_25 , V_44 , V_48 ) ;
V_15 = F_30 ( NULL , V_40 -> V_62 ,
sizeof( V_74 ) ,
V_74 ,
sizeof( V_48 ) , & V_48 , NULL ) ;
GOTO ( V_75 , V_15 = 0 ) ;
}
F_15 ( V_34 , L_26 , V_44 ) ;
V_49 = 0 ;
sprintf ( V_45 , L_27 , V_44 , V_49 ) ;
if ( F_20 ( V_11 ) ) {
V_47 = V_11 -> V_52 -> V_53 ;
if ( F_22 ( V_11 ) ) {
T_3 V_54 ;
while ( ( V_15 = F_23 ( V_49 ++ , & V_54 ) ) != - V_21 ) {
V_15 = F_14 ( V_44 , V_54 . V_24 ,
V_76 , V_45 , 0 , 0 , 0 ) ;
}
} else {
if ( V_11 -> V_52 -> V_53 ) {
V_47 = V_11 -> V_52 -> V_53 ;
} else if ( F_36 ( V_47 , V_77 ,
& V_47 ) != 0 ) {
F_18 ( L_28 ) ;
GOTO ( V_59 , V_15 = - V_20 ) ;
}
while ( F_21 ( V_47 , & V_24 , & V_47 ) == 0 ) {
V_15 = F_14 ( V_44 , V_24 ,
V_76 , V_45 , 0 , 0 , 0 ) ;
V_49 ++ ;
}
}
} else {
V_47 = V_11 -> V_52 -> V_56 ;
while ( F_21 ( V_47 , & V_24 , & V_47 ) == 0 ) {
V_15 = F_14 ( V_44 , V_24 ,
V_76 , V_45 , 0 , 0 , 0 ) ;
V_49 ++ ;
if ( * V_47 == ':' )
break;
}
}
if ( V_49 == 0 ) {
F_18 ( L_15 ) ;
GOTO ( V_59 , V_15 = - V_20 ) ;
}
V_11 -> V_52 -> V_78 = 1 ;
F_4 ( V_33 ) ;
F_37 ( V_43 ) ;
F_38 ( V_43 , V_33 ) ;
V_15 = F_17 ( V_44 , V_79 ,
( char * ) V_33 -> V_33 , V_80 ,
V_45 , 0 , 0 ) ;
F_11 ( V_33 ) ;
if ( V_15 )
GOTO ( V_59 , V_15 ) ;
V_49 = 1 ;
while ( V_47 && ( ( * V_47 == ':' ||
F_36 ( V_47 , V_77 , & V_47 ) == 0 ) ) ) {
sprintf ( V_45 , L_27 , V_44 , V_49 ) ;
V_50 = 0 ;
while ( F_39 ( V_47 , & V_24 , & V_47 ) == 0 ) {
V_50 ++ ;
V_15 = F_14 ( V_44 , V_24 ,
V_76 , V_45 , 0 , 0 , 0 ) ;
if ( * V_47 == ':' )
break;
}
if ( V_50 > 0 ) {
V_15 = F_14 ( V_44 , 0 , V_81 ,
V_45 , 0 , 0 , 0 ) ;
V_49 ++ ;
} else {
break;
}
}
V_11 -> V_52 -> V_78 = V_49 ;
V_40 = F_29 ( V_44 ) ;
if ( ! V_40 ) {
F_18 ( L_29 , V_44 ) ;
GOTO ( V_59 , V_15 = - V_82 ) ;
}
V_15 = F_30 ( NULL , V_40 -> V_62 ,
strlen ( V_63 ) , V_63 ,
strlen ( V_46 ) , V_46 , NULL ) ;
if ( V_15 )
GOTO ( V_59 , V_15 ) ;
F_40 ( & V_40 -> V_64 . V_65 . V_66 , 1 ) ;
V_48 = 1 ;
V_15 = F_30 ( NULL , V_40 -> V_62 ,
sizeof( V_74 ) ,
V_74 ,
sizeof( V_48 ) , & V_48 , NULL ) ;
if ( V_15 )
F_41 ( L_30 , V_74 , V_15 ) ;
V_39 -> V_83 = V_84 | V_85 |
V_86 | V_87 |
V_88 ;
#if V_89 < F_42 ( 3 , 2 , 50 , 0 )
V_39 -> V_83 |= V_90 ;
#else
#warning "LU-1644: Remove old OBD_CONNECT_MNE_SWAB fixup and imp_need_mne_swab"
#endif
if ( F_32 ( V_11 -> V_52 ) &&
V_11 -> V_52 -> V_70 & V_73 )
V_39 -> V_83 &= ~ V_87 ;
V_39 -> V_91 = V_89 ;
V_15 = F_43 ( NULL , & exp , V_40 , & ( V_40 -> V_42 ) , V_39 , NULL ) ;
if ( V_15 ) {
F_18 ( L_31 , V_15 ) ;
GOTO ( V_75 , V_15 ) ;
}
V_40 -> V_64 . V_65 . V_92 = exp ;
V_75:
V_11 -> V_14 = V_40 ;
V_59:
F_44 ( & V_57 ) ;
if ( V_39 )
F_11 ( V_39 ) ;
if ( V_44 )
F_45 ( V_44 , V_51 ) ;
if ( V_45 )
F_45 ( V_45 , V_51 + 2 ) ;
RETURN ( V_15 ) ;
}
static int F_46 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = F_2 ( V_2 ) ;
struct V_12 * V_40 ;
char * V_45 = 0 , * V_47 = 0 ;
int V_49 , V_15 = 0 , V_51 = 0 ;
V_16 ;
if ( ! V_11 )
RETURN ( - V_21 ) ;
V_40 = V_11 -> V_14 ;
if ( ! V_40 )
RETURN ( - V_21 ) ;
V_11 -> V_14 = NULL ;
F_26 ( & V_57 ) ;
F_3 ( F_47 ( & V_40 -> V_64 . V_65 . V_66 ) > 0 ) ;
if ( ! F_48 ( & V_40 -> V_64 . V_65 . V_66 ) ) {
F_15 ( V_34 , L_32 ,
F_47 ( & V_40 -> V_64 . V_65 . V_66 ) ) ;
GOTO ( V_75 , V_15 = - V_93 ) ;
}
V_40 -> V_94 = 1 ;
if ( V_40 -> V_64 . V_65 . V_92 ) {
V_15 = F_49 ( V_40 -> V_64 . V_65 . V_92 ) ;
if ( V_15 )
F_15 ( V_34 , L_33 , V_15 ) ;
}
V_51 = strlen ( V_40 -> V_18 ) + 6 ;
F_28 ( V_45 , V_51 ) ;
if ( V_45 ) {
strcpy ( V_45 , V_40 -> V_18 ) ;
V_47 = V_45 + strlen ( V_45 ) ;
}
V_15 = F_50 ( V_40 ) ;
if ( V_15 )
GOTO ( V_75 , V_15 ) ;
if ( ! V_45 )
GOTO ( V_75 , V_15 = - V_17 ) ;
for ( V_49 = 0 ; V_49 < V_11 -> V_52 -> V_78 ; V_49 ++ ) {
sprintf ( V_47 , L_34 , V_49 ) ;
V_15 = F_14 ( V_58 , 0 , V_95 ,
V_45 , 0 , 0 , 0 ) ;
if ( V_15 )
F_18 ( L_35 ,
V_45 , V_15 ) ;
}
V_75:
if ( V_45 )
F_45 ( V_45 , V_51 ) ;
F_44 ( & V_57 ) ;
RETURN ( V_15 ) ;
}
struct V_10 * F_51 ( struct V_1 * V_2 )
{
struct V_10 * V_11 ;
V_16 ;
F_4 ( V_11 ) ;
if ( ! V_11 )
RETURN ( NULL ) ;
F_4 ( V_11 -> V_52 ) ;
if ( ! V_11 -> V_52 ) {
F_11 ( V_11 ) ;
RETURN ( NULL ) ;
}
V_11 -> V_52 -> V_96 = 0 ;
V_11 -> V_52 -> V_97 = 0 ;
V_11 -> V_52 -> V_98 = 0 ;
F_52 ( V_2 ) = V_11 ;
F_40 ( & V_11 -> V_99 , 1 ) ;
V_11 -> V_100 = V_101 ;
RETURN ( V_11 ) ;
}
static int F_53 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = F_2 ( V_2 ) ;
V_16 ;
F_3 ( V_11 != NULL ) ;
F_15 ( V_34 , L_36 , V_11 ) ;
F_3 ( F_47 ( & V_11 -> V_99 ) == 0 ) ;
if ( V_11 -> V_52 != NULL ) {
if ( V_11 -> V_52 -> V_56 != NULL )
F_45 ( V_11 -> V_52 -> V_56 ,
strlen ( V_11 -> V_52 -> V_56 ) + 1 ) ;
if ( V_11 -> V_52 -> V_102 != NULL )
F_45 ( V_11 -> V_52 -> V_102 ,
strlen ( V_11 -> V_52 -> V_102 ) + 1 ) ;
if ( V_11 -> V_52 -> V_60 != NULL )
F_45 ( V_11 -> V_52 -> V_60 ,
strlen ( V_11 -> V_52 -> V_60 ) + 1 ) ;
if ( V_11 -> V_52 -> V_103 != NULL )
F_45 ( V_11 -> V_52 -> V_103 ,
strlen ( V_11 -> V_52 -> V_103 ) + 1 ) ;
if ( V_11 -> V_52 -> V_96 )
F_45 ( V_11 -> V_52 -> V_104 ,
sizeof( V_11 -> V_52 -> V_104 [ 0 ] ) *
V_11 -> V_52 -> V_96 ) ;
if ( V_11 -> V_52 -> V_53 != NULL )
F_45 ( V_11 -> V_52 -> V_53 ,
strlen ( V_11 -> V_52 -> V_53 ) + 1 ) ;
if ( V_11 -> V_52 -> V_105 != NULL )
F_45 ( V_11 -> V_52 -> V_105 ,
strlen ( V_11 -> V_52 -> V_105 ) + 1 ) ;
if ( V_11 -> V_52 -> V_106 != NULL )
F_45 ( V_11 -> V_52 -> V_106 , 4096 ) ;
F_45 ( V_11 -> V_52 , sizeof( * V_11 -> V_52 ) ) ;
}
F_3 ( V_11 -> V_107 == NULL ) ;
F_45 ( V_11 , sizeof( * V_11 ) ) ;
F_52 ( V_2 ) = NULL ;
RETURN ( 0 ) ;
}
int F_54 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = F_2 ( V_2 ) ;
V_16 ;
F_3 ( V_11 != NULL ) ;
F_15 ( V_34 , L_37 , V_2 , F_47 ( & V_11 -> V_99 ) ) ;
if ( F_48 ( & V_11 -> V_99 ) ) {
if ( F_20 ( V_11 ) && V_11 -> V_108 ) {
F_49 ( V_11 -> V_108 ) ;
F_55 () ;
}
F_53 ( V_2 ) ;
RETURN ( 1 ) ;
}
RETURN ( 0 ) ;
}
int F_56 ( const char * V_109 , char * V_110 , const char * * V_111 )
{
const char * V_112 = strrchr ( V_109 , '-' ) ;
if ( ! V_112 ) {
V_112 = strrchr ( V_109 , ':' ) ;
if ( ! V_112 )
return - V_20 ;
}
if ( ! strcmp ( V_113 , V_112 + 1 ) ) {
V_112 -- ;
for (; V_112 > V_109 && * V_112 != '-' && * V_112 != ':' ; V_112 -- )
;
if ( V_112 == V_109 )
return - V_20 ;
}
if ( V_110 != NULL ) {
strncpy ( V_110 , V_109 , V_112 - V_109 ) ;
V_110 [ V_112 - V_109 ] = '\0' ;
}
if ( V_111 != NULL )
* V_111 = V_112 ;
return 0 ;
}
int F_57 ( const char * V_114 , char * V_109 , const char * * V_111 ,
T_5 V_115 )
{
int V_15 ;
const const char * V_112 ;
V_15 = F_56 ( V_114 , NULL , & V_112 ) ;
if ( V_15 != 0 )
return V_15 ;
if ( * V_112 != '-' )
return - 1 ;
if ( F_58 ( V_109 , V_112 + 1 , V_115 ) >= V_115 )
return - V_116 ;
return 0 ;
}
int F_59 ( const char * V_109 , T_4 * V_117 , const char * * V_111 )
{
unsigned long V_118 ;
int V_15 ;
const char * V_112 ;
V_15 = F_56 ( V_109 , NULL , & V_112 ) ;
if ( V_15 != 0 )
return V_15 ;
if ( * V_112 != '-' )
return - V_20 ;
V_112 ++ ;
if ( strncmp ( V_112 , L_38 , 3 ) == 0 )
V_15 = V_119 ;
else if ( strncmp ( V_112 , L_39 , 3 ) == 0 )
V_15 = V_120 ;
else
return - V_20 ;
V_112 += 3 ;
if ( strcmp ( V_112 , L_40 ) == 0 )
return V_15 | V_121 ;
V_118 = F_60 ( V_112 , ( char * * ) V_111 , 16 ) ;
* V_117 = V_118 ;
return V_15 ;
}
int F_61 ( struct V_1 * V_2 )
{
int V_15 ;
V_16 ;
F_15 ( V_34 , L_41 , V_2 ) ;
V_15 = F_46 ( V_2 ) ;
if ( V_15 && ( V_15 != - V_21 ) ) {
if ( V_15 != - V_93 ) {
F_18 ( L_42 , V_15 ) ;
RETURN ( V_15 ) ;
}
F_15 ( V_34 , L_43 ) ;
}
F_54 ( V_2 ) ;
F_62 () ;
RETURN ( V_15 ) ;
}
static void F_63 ( struct V_122 * V_123 )
{
int V_49 ;
F_64 ( V_34 , L_44 ) ;
if ( F_32 ( V_123 ) )
F_64 ( V_34 , L_45 , V_123 -> V_102 ) ;
F_64 ( V_34 , L_46 , V_123 -> V_56 ) ;
F_64 ( V_34 , L_47 , V_123 -> V_70 ) ;
if ( V_123 -> V_103 )
F_64 ( V_34 , L_48 , V_123 -> V_103 ) ;
if ( V_123 -> V_97 )
F_64 ( V_34 , L_49 ,
V_123 -> V_97 ) ;
if ( V_123 -> V_98 )
F_64 ( V_34 , L_50 ,
V_123 -> V_98 ) ;
for ( V_49 = 0 ; V_49 < V_123 -> V_96 ; V_49 ++ ) {
F_64 ( V_34 , L_51 , V_49 ,
V_123 -> V_104 [ V_49 ] ) ;
}
}
int F_65 ( struct V_1 * V_2 , char * V_109 )
{
struct V_10 * V_11 = F_2 ( V_2 ) ;
struct V_122 * V_123 = V_11 -> V_52 ;
T_4 V_118 ;
int V_49 , V_15 ;
V_16 ;
V_15 = F_59 ( V_109 , & V_118 , NULL ) ;
if ( V_15 != V_120 )
RETURN ( 0 ) ;
F_15 ( V_34 , L_52 , V_109 ,
V_118 , V_123 -> V_96 , V_123 -> V_56 ) ;
for( V_49 = 0 ; V_49 < V_123 -> V_96 ; V_49 ++ ) {
if ( V_118 == V_123 -> V_104 [ V_49 ] ) {
F_41 ( L_53 , V_109 ) ;
RETURN ( 1 ) ;
}
}
RETURN ( 0 ) ;
}
static int F_66 ( struct V_122 * V_123 , const char * V_47 )
{
const char * V_26 = V_47 , * V_27 ;
T_4 V_118 , * V_124 ;
int V_15 = 0 , V_125 ;
V_16 ;
V_125 = strlen ( V_47 ) / 8 + 1 ;
F_28 ( V_124 , sizeof( V_118 ) * V_125 ) ;
if ( ! V_124 )
RETURN ( - V_17 ) ;
while ( * V_26 && * V_26 != ' ' && * V_26 != ',' ) {
V_26 ++ ;
V_15 = F_59 ( V_26 , & V_118 , & V_27 ) ;
if ( V_15 < 0 ) {
F_18 ( L_54 , V_26 ) ;
break;
}
if ( V_15 == V_120 )
V_124 [ V_123 -> V_96 ++ ] = V_118 ;
else
F_15 ( V_34 , L_55 , V_26 ) ;
V_26 = V_27 ;
if ( V_123 -> V_96 >= V_125 )
break;
}
if ( V_15 >= 0 )
V_15 = 0 ;
if ( V_123 -> V_96 ) {
F_28 ( V_123 -> V_104 , sizeof( V_118 ) *
V_123 -> V_96 ) ;
if ( V_123 -> V_104 ) {
memcpy ( V_123 -> V_104 , V_124 ,
sizeof( V_118 ) * V_123 -> V_96 ) ;
} else {
V_15 = - V_17 ;
V_123 -> V_96 = 0 ;
}
}
F_45 ( V_124 , sizeof( V_118 ) * V_125 ) ;
RETURN ( V_15 ) ;
}
static int F_67 ( struct V_122 * V_123 , char * V_47 )
{
char * V_126 ;
int V_127 ;
if ( V_123 -> V_60 != NULL ) {
F_45 ( V_123 -> V_60 , strlen ( V_123 -> V_60 ) + 1 ) ;
V_123 -> V_60 = NULL ;
}
V_126 = strchr ( V_47 , ',' ) ;
if ( V_126 == NULL )
V_127 = strlen ( V_47 ) ;
else
V_127 = V_126 - V_47 ;
F_28 ( V_123 -> V_60 , V_127 + 1 ) ;
if ( V_123 -> V_60 == NULL )
return - V_17 ;
memcpy ( V_123 -> V_60 , V_47 , V_127 ) ;
V_123 -> V_60 [ V_127 ] = '\0' ;
return 0 ;
}
static int F_68 ( char * * V_128 , char * V_47 )
{
char * V_126 ;
int V_127 ;
if ( ( V_128 == NULL ) || ( V_47 == NULL ) )
return - V_20 ;
if ( * V_128 != NULL ) {
F_45 ( * V_128 , strlen ( * V_128 ) + 1 ) ;
* V_128 = NULL ;
}
V_126 = strchr ( V_47 , ',' ) ;
if ( V_126 == NULL )
V_127 = strlen ( V_47 ) ;
else
V_127 = V_126 - V_47 ;
F_28 ( * V_128 , V_127 + 1 ) ;
if ( * V_128 == NULL )
return - V_17 ;
memcpy ( * V_128 , V_47 , V_127 ) ;
( * V_128 ) [ V_127 ] = '\0' ;
return 0 ;
}
static int F_69 ( struct V_122 * V_123 , char * * V_47 )
{
T_1 V_24 ;
char * V_126 = * V_47 ;
char * V_129 ;
int V_127 ;
int V_130 = 0 ;
while ( F_39 ( V_126 , & V_24 , & V_126 ) == 0 ) {}
V_127 = V_126 - * V_47 ;
if ( V_127 == 0 ) {
F_12 ( 0x159 , L_56 , * V_47 ) ;
return - V_20 ;
}
if ( V_123 -> V_53 != NULL )
V_130 = strlen ( V_123 -> V_53 ) + 1 ;
F_28 ( V_129 , V_130 + V_127 + 1 ) ;
if ( V_129 == NULL )
return - V_17 ;
if ( V_123 -> V_53 != NULL ) {
memcpy ( V_129 , V_123 -> V_53 , V_130 ) ;
V_129 [ V_130 - 1 ] = ':' ;
F_45 ( V_123 -> V_53 , V_130 ) ;
}
memcpy ( V_129 + V_130 , * V_47 , V_127 ) ;
V_129 [ V_130 + V_127 ] = '\0' ;
V_123 -> V_53 = V_129 ;
* V_47 = V_126 ;
return 0 ;
}
static int F_70 ( char * V_131 , struct V_122 * V_123 )
{
char * V_26 , * V_27 , * V_132 = NULL ;
struct V_122 * V_133 = (struct V_122 * ) V_131 ;
int V_15 = 0 ;
V_16 ;
F_3 ( V_123 ) ;
if ( ! V_131 ) {
F_12 ( 0x162 , L_57
L_58 ) ;
RETURN ( - V_20 ) ;
}
if ( ( V_133 -> V_134 & 0xffffff00 ) == ( V_135 & 0xffffff00 ) ) {
F_12 ( 0x163 , L_59
L_60
L_61 , V_136 ) ;
RETURN ( - V_20 ) ;
}
V_123 -> V_134 = V_135 ;
F_28 ( V_123 -> V_106 , 4096 ) ;
if ( V_123 -> V_106 == NULL )
RETURN ( - V_17 ) ;
V_123 -> V_106 [ 0 ] = '\0' ;
V_26 = V_131 ;
while ( * V_26 ) {
int V_137 = 0 ;
int V_138 = V_139 ;
while ( * V_26 == ' ' || * V_26 == ',' )
V_26 ++ ;
if ( strncmp ( V_26 , L_62 , 11 ) == 0 ) {
V_123 -> V_70 |= V_140 ;
V_137 ++ ;
} else if ( strncmp ( V_26 , L_63 , 19 ) == 0 ) {
V_123 -> V_97 = F_71 ( int ,
F_60 ( V_26 + 19 , NULL , 10 ) , V_138 ) ;
V_137 ++ ;
} else if ( strncmp ( V_26 , L_64 , 19 ) == 0 ) {
V_123 -> V_98 = F_71 ( int ,
F_60 ( V_26 + 19 , NULL , 10 ) , V_138 ) ;
V_137 ++ ;
} else if ( strncmp ( V_26 , L_65 , 4 ) == 0 ) {
V_123 -> V_70 |= V_73 ;
V_137 ++ ;
} else if ( strncmp ( V_26 , L_66 , 5 ) == 0 ) {
V_123 -> V_70 |= V_141 ;
V_137 ++ ;
} else if ( strncmp ( V_26 , L_67 , 5 ) == 0 ) {
V_123 -> V_70 |= V_142 ;
V_137 ++ ;
} else if ( strncmp ( V_26 , L_68 , 7 ) == 0 ) {
V_123 -> V_70 |= V_143 ;
V_137 ++ ;
} else if ( strncmp ( V_26 , V_77 ,
sizeof( V_77 ) - 1 ) == 0 ) {
V_27 = V_26 + sizeof( V_77 ) - 1 ;
V_15 = F_69 ( V_123 , & V_27 ) ;
if ( V_15 )
goto V_144;
V_137 ++ ;
} else if ( strncmp ( V_26 , L_69 , 9 ) == 0 ) {
V_123 -> V_70 |= V_145 ;
V_137 ++ ;
} else if ( strncmp ( V_26 , L_70 , 6 ) == 0 ) {
V_123 -> V_70 |= V_146 ;
V_137 ++ ;
} else if ( strncmp ( V_26 , L_71 , 6 ) == 0 ) {
V_123 -> V_70 |= V_147 ;
V_137 ++ ;
} else if ( strncmp ( V_26 , L_72 , 10 ) == 0 ) {
V_123 -> V_70 |= V_148 ;
V_137 ++ ;
} else if ( strncmp ( V_26 , L_73 , 7 ) == 0 ) {
V_15 = F_67 ( V_123 , V_26 + 7 ) ;
if ( V_15 )
goto V_144;
V_137 ++ ;
} else if ( strncmp ( V_26 , L_74 , 8 ) == 0 ) {
V_15 = F_66 ( V_123 , V_26 + 7 ) ;
if ( V_15 )
goto V_144;
V_137 ++ ;
} else if ( strncmp ( V_26 , L_75 , 3 ) == 0 ) {
V_123 -> V_70 |= V_149 ;
V_137 ++ ;
} else if ( strncmp ( V_26 , L_76 , 7 ) == 0 ) {
V_15 = F_68 ( & V_123 -> V_102 , V_26 + 7 ) ;
if ( V_15 )
goto V_144;
V_137 ++ ;
} else if ( strncmp ( V_26 , L_77 , 6 ) == 0 ) {
int V_127 ;
char * V_126 = strchr ( V_26 + 6 , ',' ) ;
if ( V_126 == NULL )
V_127 = strlen ( V_26 ) ;
else
V_127 = V_126 - V_26 ;
V_127 -= 6 ;
strncat ( V_123 -> V_106 , V_26 + 6 , V_127 ) ;
strcat ( V_123 -> V_106 , L_78 ) ;
V_137 ++ ;
} else if ( strncmp ( V_26 , L_79 , 4 ) == 0 ) {
V_15 = F_68 ( & V_123 -> V_105 , V_26 + 4 ) ;
if ( V_15 )
goto V_144;
V_137 ++ ;
}
else if ( strncmp ( V_26 , L_80 , 7 ) == 0 ) {
V_132 = V_26 + 7 ;
* V_26 = '\0' ;
break;
}
V_27 = strchr ( V_26 , ',' ) ;
if ( V_27 == NULL ) {
if ( V_137 )
* V_26 = '\0' ;
break;
}
V_27 ++ ;
if ( V_137 )
memmove ( V_26 , V_27 , strlen ( V_27 ) + 1 ) ;
else
V_26 = V_27 ;
}
if ( ! V_132 ) {
F_12 ( 0x164 , L_81
L_82 ) ;
goto V_144;
}
V_26 = strstr ( V_132 , L_83 ) ;
if ( V_26 ) {
++ V_26 ;
V_123 -> V_70 |= V_150 ;
while ( * ++ V_26 == '/' ) ;
F_28 ( V_123 -> V_102 , strlen ( V_26 ) + 8 ) ;
if ( ! V_123 -> V_102 )
RETURN ( - V_17 ) ;
sprintf ( V_123 -> V_102 , L_84 , V_26 ) ;
}
F_28 ( V_123 -> V_56 , strlen ( V_132 ) + 1 ) ;
if ( ! V_123 -> V_56 )
RETURN ( - V_17 ) ;
strcpy ( V_123 -> V_56 , V_132 ) ;
V_26 = V_131 + strlen ( V_131 ) - 1 ;
while ( V_26 >= V_131 && ( * V_26 == ',' || * V_26 == ' ' ) )
* V_26 -- = 0 ;
if ( * V_131 != 0 ) {
F_28 ( V_123 -> V_103 , strlen ( V_131 ) + 1 ) ;
if ( ! V_123 -> V_103 )
RETURN ( - V_17 ) ;
strcpy ( V_123 -> V_103 , V_131 ) ;
}
F_63 ( V_123 ) ;
V_123 -> V_134 = V_135 ;
RETURN ( V_15 ) ;
V_144:
F_18 ( L_85 , V_131 ) ;
RETURN ( - V_20 ) ;
}
int F_72 ( struct V_1 * V_2 , void * V_39 , int V_151 )
{
struct V_122 * V_123 ;
struct V_152 * V_153 = V_39 ;
struct V_10 * V_11 ;
int V_15 ;
V_16 ;
F_15 ( V_34 | V_154 , L_86 , V_2 ) ;
V_11 = F_51 ( V_2 ) ;
if ( ! V_11 )
RETURN ( - V_17 ) ;
V_123 = V_11 -> V_52 ;
F_73 () ;
F_55 () ;
if ( F_70 ( ( char * ) ( V_153 -> V_155 ) , V_123 ) ) {
F_54 ( V_2 ) ;
GOTO ( V_75 , V_15 = - V_20 ) ;
}
if ( F_32 ( V_123 ) ) {
F_15 ( V_34 , L_87 , V_123 -> V_102 ) ;
if ( ! V_156 ) {
F_12 ( 0x165 , L_88
L_89
L_90 ) ;
F_54 ( V_2 ) ;
V_15 = - V_157 ;
} else {
V_15 = F_19 ( V_2 ) ;
if ( V_15 ) {
F_54 ( V_2 ) ;
GOTO ( V_75 , V_15 ) ;
}
V_15 = (* V_156)( V_2 , V_153 -> V_158 ) ;
}
} else {
F_18 ( L_91
L_92 ) ;
V_15 = - V_20 ;
}
GOTO ( V_75 , V_15 ) ;
V_75:
if ( V_15 ) {
F_18 ( L_93 ,
F_2 ( V_2 ) ? V_123 -> V_56 : L_17 , V_15 ) ;
} else {
F_15 ( V_159 , L_94 ,
V_123 -> V_56 ) ;
}
F_74 () ;
return V_15 ;
}
void F_75 ( int (* F_76)( struct V_1 * V_2 ,
struct V_160 * V_161 ) )
{
V_156 = F_76 ;
}
void F_77 ( void (* F_76)( struct V_1 * V_2 ) )
{
V_162 = F_76 ;
}
struct V_163 * F_78 ( struct V_164 * V_165 , int V_69 ,
const char * V_132 , void * V_39 )
{
struct V_152 V_153 = { V_39 , NULL } ;
return F_79 ( V_165 , V_69 , & V_153 , F_72 ) ;
}
void F_80 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = F_2 ( V_2 ) ;
if ( V_162 && V_11 && ! F_20 ( V_11 ) )
(* V_162)( V_2 ) ;
F_81 ( V_2 ) ;
}
int F_82 ( void )
{
return F_83 ( & V_166 ) ;
}
int F_84 ( void )
{
return F_85 ( & V_166 ) ;
}
