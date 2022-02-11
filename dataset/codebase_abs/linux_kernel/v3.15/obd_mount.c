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
F_4 ( V_9 ) ;
if ( V_9 == NULL )
return - V_16 ;
F_5 ( V_9 , V_13 -> V_17 ) ;
F_6 ( V_9 , 1 , V_3 ) ;
F_7 ( V_9 , 2 , V_5 , sizeof( * V_5 ) ) ;
F_7 ( V_9 , 3 , & V_2 , sizeof( V_2 ) ) ;
V_7 = F_8 ( V_18 , V_9 ) ;
V_15 = F_9 ( V_13 , sizeof( * V_7 ) , V_7 ) ;
F_10 ( V_7 ) ;
F_11 ( V_9 ) ;
if ( V_15 == - V_19 )
F_12 ( 0x15b , L_1
L_2
L_3
L_4 ,
V_13 -> V_17 , V_3 , V_15 ) ;
if ( V_15 )
F_12 ( 0x15c , L_5
L_6
L_7
L_8
L_9
L_10 , V_13 -> V_17 , V_3 ,
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
return - V_20 ;
F_5 ( & V_9 , V_13 -> V_17 ) ;
F_6 ( & V_9 , 1 , V_3 ) ;
if ( V_5 )
F_7 ( & V_9 , 2 , V_5 , sizeof( * V_5 ) ) ;
V_7 = F_8 ( V_21 , & V_9 ) ;
V_15 = F_9 ( V_13 , sizeof( * V_7 ) , V_7 ) ;
F_10 ( V_7 ) ;
return V_15 ;
}
int F_14 ( char * V_22 , T_1 V_23 , int V_24 ,
char * V_25 , char * V_26 , char * V_27 , char * V_28 )
{
struct V_8 V_9 ;
struct V_6 * V_7 = NULL ;
int V_15 ;
F_15 ( V_29 , L_11 , V_22 ,
V_24 , V_25 , V_26 , V_27 , V_28 ) ;
F_5 ( & V_9 , V_22 ) ;
if ( V_25 )
F_6 ( & V_9 , 1 , V_25 ) ;
if ( V_26 )
F_6 ( & V_9 , 2 , V_26 ) ;
if ( V_27 )
F_6 ( & V_9 , 3 , V_27 ) ;
if ( V_28 )
F_6 ( & V_9 , 4 , V_28 ) ;
V_7 = F_8 ( V_24 , & V_9 ) ;
V_7 -> V_30 = V_23 ;
V_15 = F_16 ( V_7 ) ;
F_10 ( V_7 ) ;
return ( V_15 ) ;
}
int F_17 ( char * V_31 , char * type , char * V_32 ,
char * V_25 , char * V_26 , char * V_27 , char * V_28 )
{
int V_15 ;
F_15 ( V_33 , L_12 , V_31 , type ) ;
V_15 = F_14 ( V_31 , 0 , V_34 , type , V_32 , 0 , 0 ) ;
if ( V_15 ) {
F_18 ( L_13 , V_31 , V_15 ) ;
return V_15 ;
}
V_15 = F_14 ( V_31 , 0 , V_35 , V_25 , V_26 , V_27 , V_28 ) ;
if ( V_15 ) {
F_18 ( L_14 , V_31 , V_15 ) ;
F_14 ( V_31 , 0 , V_36 , 0 , 0 , 0 , 0 ) ;
}
return V_15 ;
}
int F_19 ( struct V_1 * V_2 )
{
struct V_37 * V_38 = NULL ;
struct V_10 * V_11 = F_2 ( V_2 ) ;
struct V_12 * V_39 ;
struct V_40 * exp ;
struct V_41 * V_32 ;
T_2 V_42 ;
T_1 V_23 ;
char * V_43 = NULL , * V_44 = NULL , * V_45 = NULL ;
char * V_46 ;
int V_47 ;
int V_15 = 0 , V_48 = 0 , V_49 , V_50 ;
F_3 ( V_11 -> V_51 ) ;
if ( F_20 ( V_11 ) ) {
V_46 = V_11 -> V_51 -> V_52 ;
if ( V_11 -> V_51 -> V_52 &&
( F_21 ( V_11 -> V_51 -> V_52 , & V_23 , & V_46 ) == 0 ) ) {
V_48 ++ ;
} else if ( F_22 ( V_11 ) ) {
T_3 V_53 ;
while ( ( V_15 = F_23 ( V_48 ++ , & V_53 ) ) != - V_20 ) {
if ( F_24 ( F_25 ( V_53 . V_23 ) ) == V_54 )
continue;
V_23 = V_53 . V_23 ;
V_48 ++ ;
break;
}
}
} else {
V_46 = V_11 -> V_51 -> V_55 ;
if ( F_21 ( V_46 , & V_23 , & V_46 ) == 0 )
V_48 ++ ;
}
if ( V_48 == 0 ) {
F_18 ( L_15 ) ;
return - V_19 ;
}
F_26 ( & V_56 ) ;
V_50 = strlen ( V_57 ) + strlen ( F_27 ( V_23 ) ) + 1 ;
F_28 ( V_43 , V_50 ) ;
F_28 ( V_44 , V_50 + 2 ) ;
if ( ! V_43 || ! V_44 )
GOTO ( V_58 , V_15 = - V_16 ) ;
sprintf ( V_43 , L_16 , V_57 , F_27 ( V_23 ) ) ;
V_45 = V_11 -> V_51 -> V_59 ? V_11 -> V_51 -> V_59 : L_17 ;
F_4 ( V_38 ) ;
if ( V_38 == NULL )
GOTO ( V_58 , V_15 = - V_16 ) ;
V_39 = F_29 ( V_43 ) ;
if ( V_39 && ! V_39 -> V_60 ) {
V_15 = F_30 ( NULL , V_39 -> V_61 ,
strlen ( V_62 ) , V_62 ,
strlen ( V_45 ) , V_45 , NULL ) ;
if ( V_15 )
GOTO ( V_58 , V_15 ) ;
F_31 ( & V_39 -> V_63 . V_64 . V_65 ) ;
if ( F_32 ( V_11 -> V_51 ) ) {
int V_66 ;
int V_67 = sizeof( * V_38 ) ;
T_4 * V_68 = & V_11 -> V_51 -> V_69 ;
V_15 = F_33 ( NULL , V_39 -> V_61 ,
strlen ( V_70 ) , V_70 ,
& V_67 , V_38 , NULL ) ;
F_3 ( V_15 == 0 ) ;
V_66 = F_34 ( V_38 , V_71 ) ;
if ( V_66 ^ ! ( * V_68 & V_72 ) ) {
F_35 (
L_18
L_19
L_20
L_21 ,
V_66 ? L_22 : L_23 ) ;
if ( V_66 )
* V_68 &= ~ V_72 ;
else
* V_68 |= V_72 ;
}
}
V_47 = 0 ;
if ( F_22 ( V_11 ) ) {
F_15 ( V_33 , L_24 ) ;
V_47 = 1 ;
}
V_47 ++ ;
F_15 ( V_33 , L_25 , V_43 , V_47 ) ;
V_15 = F_30 ( NULL , V_39 -> V_61 ,
sizeof( V_73 ) ,
V_73 ,
sizeof( V_47 ) , & V_47 , NULL ) ;
GOTO ( V_74 , V_15 = 0 ) ;
}
F_15 ( V_33 , L_26 , V_43 ) ;
V_48 = 0 ;
sprintf ( V_44 , L_27 , V_43 , V_48 ) ;
if ( F_20 ( V_11 ) ) {
V_46 = V_11 -> V_51 -> V_52 ;
if ( F_22 ( V_11 ) ) {
T_3 V_53 ;
while ( ( V_15 = F_23 ( V_48 ++ , & V_53 ) ) != - V_20 ) {
V_15 = F_14 ( V_43 , V_53 . V_23 ,
V_75 , V_44 , 0 , 0 , 0 ) ;
}
} else {
if ( V_11 -> V_51 -> V_52 ) {
V_46 = V_11 -> V_51 -> V_52 ;
} else if ( F_36 ( V_46 , V_76 ,
& V_46 ) != 0 ) {
F_18 ( L_28 ) ;
GOTO ( V_58 , V_15 = - V_19 ) ;
}
while ( F_21 ( V_46 , & V_23 , & V_46 ) == 0 ) {
V_15 = F_14 ( V_43 , V_23 ,
V_75 , V_44 , 0 , 0 , 0 ) ;
V_48 ++ ;
}
}
} else {
V_46 = V_11 -> V_51 -> V_55 ;
while ( F_21 ( V_46 , & V_23 , & V_46 ) == 0 ) {
V_15 = F_14 ( V_43 , V_23 ,
V_75 , V_44 , 0 , 0 , 0 ) ;
V_48 ++ ;
if ( * V_46 == ':' )
break;
}
}
if ( V_48 == 0 ) {
F_18 ( L_15 ) ;
GOTO ( V_58 , V_15 = - V_19 ) ;
}
V_11 -> V_51 -> V_77 = 1 ;
F_4 ( V_32 ) ;
F_37 ( V_42 ) ;
F_38 ( V_42 , V_32 ) ;
V_15 = F_17 ( V_43 , V_78 ,
( char * ) V_32 -> V_32 , V_79 ,
V_44 , 0 , 0 ) ;
F_11 ( V_32 ) ;
if ( V_15 )
GOTO ( V_58 , V_15 ) ;
V_48 = 1 ;
while ( V_46 && ( ( * V_46 == ':' ||
F_36 ( V_46 , V_76 , & V_46 ) == 0 ) ) ) {
sprintf ( V_44 , L_27 , V_43 , V_48 ) ;
V_49 = 0 ;
while ( F_39 ( V_46 , & V_23 , & V_46 ) == 0 ) {
V_49 ++ ;
V_15 = F_14 ( V_43 , V_23 ,
V_75 , V_44 , 0 , 0 , 0 ) ;
if ( * V_46 == ':' )
break;
}
if ( V_49 > 0 ) {
V_15 = F_14 ( V_43 , 0 , V_80 ,
V_44 , 0 , 0 , 0 ) ;
V_48 ++ ;
} else {
break;
}
}
V_11 -> V_51 -> V_77 = V_48 ;
V_39 = F_29 ( V_43 ) ;
if ( ! V_39 ) {
F_18 ( L_29 , V_43 ) ;
GOTO ( V_58 , V_15 = - V_81 ) ;
}
V_15 = F_30 ( NULL , V_39 -> V_61 ,
strlen ( V_62 ) , V_62 ,
strlen ( V_45 ) , V_45 , NULL ) ;
if ( V_15 )
GOTO ( V_58 , V_15 ) ;
F_40 ( & V_39 -> V_63 . V_64 . V_65 , 1 ) ;
V_47 = 1 ;
V_15 = F_30 ( NULL , V_39 -> V_61 ,
sizeof( V_73 ) ,
V_73 ,
sizeof( V_47 ) , & V_47 , NULL ) ;
if ( V_15 )
F_41 ( L_30 , V_73 , V_15 ) ;
V_38 -> V_82 = V_83 | V_84 |
V_85 | V_86 |
V_87 ;
#if V_88 < F_42 ( 3 , 2 , 50 , 0 )
V_38 -> V_82 |= V_89 ;
#else
#warning "LU-1644: Remove old OBD_CONNECT_MNE_SWAB fixup and imp_need_mne_swab"
#endif
if ( F_32 ( V_11 -> V_51 ) &&
V_11 -> V_51 -> V_69 & V_72 )
V_38 -> V_82 &= ~ V_86 ;
V_38 -> V_90 = V_88 ;
V_15 = F_43 ( NULL , & exp , V_39 , & ( V_39 -> V_41 ) , V_38 , NULL ) ;
if ( V_15 ) {
F_18 ( L_31 , V_15 ) ;
GOTO ( V_74 , V_15 ) ;
}
V_39 -> V_63 . V_64 . V_91 = exp ;
V_74:
V_11 -> V_14 = V_39 ;
V_58:
F_44 ( & V_56 ) ;
if ( V_38 )
F_11 ( V_38 ) ;
if ( V_43 )
F_45 ( V_43 , V_50 ) ;
if ( V_44 )
F_45 ( V_44 , V_50 + 2 ) ;
return V_15 ;
}
static int F_46 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = F_2 ( V_2 ) ;
struct V_12 * V_39 ;
char * V_44 = 0 , * V_46 = 0 ;
int V_48 , V_15 = 0 , V_50 = 0 ;
if ( ! V_11 )
return - V_20 ;
V_39 = V_11 -> V_14 ;
if ( ! V_39 )
return - V_20 ;
V_11 -> V_14 = NULL ;
F_26 ( & V_56 ) ;
F_3 ( F_47 ( & V_39 -> V_63 . V_64 . V_65 ) > 0 ) ;
if ( ! F_48 ( & V_39 -> V_63 . V_64 . V_65 ) ) {
F_15 ( V_33 , L_32 ,
F_47 ( & V_39 -> V_63 . V_64 . V_65 ) ) ;
GOTO ( V_74 , V_15 = - V_92 ) ;
}
V_39 -> V_93 = 1 ;
if ( V_39 -> V_63 . V_64 . V_91 ) {
V_15 = F_49 ( V_39 -> V_63 . V_64 . V_91 ) ;
if ( V_15 )
F_15 ( V_33 , L_33 , V_15 ) ;
}
V_50 = strlen ( V_39 -> V_17 ) + 6 ;
F_28 ( V_44 , V_50 ) ;
if ( V_44 ) {
strcpy ( V_44 , V_39 -> V_17 ) ;
V_46 = V_44 + strlen ( V_44 ) ;
}
V_15 = F_50 ( V_39 ) ;
if ( V_15 )
GOTO ( V_74 , V_15 ) ;
if ( ! V_44 )
GOTO ( V_74 , V_15 = - V_16 ) ;
for ( V_48 = 0 ; V_48 < V_11 -> V_51 -> V_77 ; V_48 ++ ) {
sprintf ( V_46 , L_34 , V_48 ) ;
V_15 = F_14 ( V_57 , 0 , V_94 ,
V_44 , 0 , 0 , 0 ) ;
if ( V_15 )
F_18 ( L_35 ,
V_44 , V_15 ) ;
}
V_74:
if ( V_44 )
F_45 ( V_44 , V_50 ) ;
F_44 ( & V_56 ) ;
return V_15 ;
}
struct V_10 * F_51 ( struct V_1 * V_2 )
{
struct V_10 * V_11 ;
F_4 ( V_11 ) ;
if ( ! V_11 )
return NULL ;
F_4 ( V_11 -> V_51 ) ;
if ( ! V_11 -> V_51 ) {
F_11 ( V_11 ) ;
return NULL ;
}
V_11 -> V_51 -> V_95 = 0 ;
V_11 -> V_51 -> V_96 = 0 ;
V_11 -> V_51 -> V_97 = 0 ;
F_52 ( V_2 ) = V_11 ;
F_40 ( & V_11 -> V_98 , 1 ) ;
V_11 -> V_99 = V_100 ;
return V_11 ;
}
static int F_53 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = F_2 ( V_2 ) ;
F_3 ( V_11 != NULL ) ;
F_15 ( V_33 , L_36 , V_11 ) ;
F_3 ( F_47 ( & V_11 -> V_98 ) == 0 ) ;
if ( V_11 -> V_51 != NULL ) {
if ( V_11 -> V_51 -> V_55 != NULL )
F_45 ( V_11 -> V_51 -> V_55 ,
strlen ( V_11 -> V_51 -> V_55 ) + 1 ) ;
if ( V_11 -> V_51 -> V_101 != NULL )
F_45 ( V_11 -> V_51 -> V_101 ,
strlen ( V_11 -> V_51 -> V_101 ) + 1 ) ;
if ( V_11 -> V_51 -> V_59 != NULL )
F_45 ( V_11 -> V_51 -> V_59 ,
strlen ( V_11 -> V_51 -> V_59 ) + 1 ) ;
if ( V_11 -> V_51 -> V_102 != NULL )
F_45 ( V_11 -> V_51 -> V_102 ,
strlen ( V_11 -> V_51 -> V_102 ) + 1 ) ;
if ( V_11 -> V_51 -> V_95 )
F_45 ( V_11 -> V_51 -> V_103 ,
sizeof( V_11 -> V_51 -> V_103 [ 0 ] ) *
V_11 -> V_51 -> V_95 ) ;
if ( V_11 -> V_51 -> V_52 != NULL )
F_45 ( V_11 -> V_51 -> V_52 ,
strlen ( V_11 -> V_51 -> V_52 ) + 1 ) ;
if ( V_11 -> V_51 -> V_104 != NULL )
F_45 ( V_11 -> V_51 -> V_104 ,
strlen ( V_11 -> V_51 -> V_104 ) + 1 ) ;
if ( V_11 -> V_51 -> V_105 != NULL )
F_45 ( V_11 -> V_51 -> V_105 , 4096 ) ;
F_45 ( V_11 -> V_51 , sizeof( * V_11 -> V_51 ) ) ;
}
F_3 ( V_11 -> V_106 == NULL ) ;
F_45 ( V_11 , sizeof( * V_11 ) ) ;
F_52 ( V_2 ) = NULL ;
return 0 ;
}
int F_54 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = F_2 ( V_2 ) ;
F_3 ( V_11 != NULL ) ;
F_15 ( V_33 , L_37 , V_2 , F_47 ( & V_11 -> V_98 ) ) ;
if ( F_48 ( & V_11 -> V_98 ) ) {
if ( F_20 ( V_11 ) && V_11 -> V_107 ) {
F_55 ( & V_11 -> V_108 -> V_109 ) ;
V_11 -> V_107 -> V_110 -> V_111 . V_112 = NULL ;
V_11 -> V_108 = NULL ;
F_49 ( V_11 -> V_107 ) ;
F_56 () ;
}
F_53 ( V_2 ) ;
return 1 ;
}
return 0 ;
}
int F_57 ( const char * V_113 , char * V_114 , const char * * V_115 )
{
const char * V_116 ;
V_116 = V_113 + F_58 ( V_113 , 8 ) ;
for (; V_116 > V_113 && * V_116 != '-' && * V_116 != ':' ; V_116 -- )
;
if ( V_116 == V_113 )
return - V_19 ;
if ( V_114 != NULL ) {
strncpy ( V_114 , V_113 , V_116 - V_113 ) ;
V_114 [ V_116 - V_113 ] = '\0' ;
}
if ( V_115 != NULL )
* V_115 = V_116 ;
return 0 ;
}
int F_59 ( const char * V_117 , char * V_113 , const char * * V_115 ,
T_5 V_118 )
{
int V_15 ;
const char * V_116 ;
V_15 = F_57 ( V_117 , NULL , & V_116 ) ;
if ( V_15 != 0 )
return V_15 ;
if ( V_115 != NULL )
* V_115 = V_116 ;
if ( F_60 ( V_113 , V_116 + 1 , V_118 ) >= V_118 )
return - V_119 ;
return 0 ;
}
int F_61 ( const char * V_113 , T_4 * V_120 , const char * * V_115 )
{
unsigned long V_121 ;
int V_15 ;
const char * V_116 ;
V_15 = F_57 ( V_113 , NULL , & V_116 ) ;
if ( V_15 != 0 )
return V_15 ;
V_116 ++ ;
if ( strncmp ( V_116 , L_38 , 3 ) == 0 )
V_15 = V_122 ;
else if ( strncmp ( V_116 , L_39 , 3 ) == 0 )
V_15 = V_123 ;
else
return - V_19 ;
V_116 += 3 ;
if ( strncmp ( V_116 , L_40 , 3 ) == 0 ) {
if ( V_115 != NULL )
* V_115 = V_116 + 3 ;
return V_15 | V_124 ;
}
V_121 = F_62 ( V_116 , ( char * * ) V_115 , 16 ) ;
if ( V_120 != NULL )
* V_120 = V_121 ;
if ( V_115 != NULL && strncmp ( V_125 , * V_115 + 1 ,
sizeof( V_125 ) - 1 ) == 0 )
* V_115 += sizeof( V_125 ) ;
return V_15 ;
}
int F_63 ( struct V_1 * V_2 )
{
int V_15 ;
F_15 ( V_33 , L_41 , V_2 ) ;
V_15 = F_46 ( V_2 ) ;
if ( V_15 && ( V_15 != - V_20 ) ) {
if ( V_15 != - V_92 ) {
F_18 ( L_42 , V_15 ) ;
return V_15 ;
}
F_15 ( V_33 , L_43 ) ;
}
F_54 ( V_2 ) ;
F_64 () ;
return V_15 ;
}
static void F_65 ( struct V_126 * V_127 )
{
int V_48 ;
F_66 ( V_33 , L_44 ) ;
if ( F_32 ( V_127 ) )
F_66 ( V_33 , L_45 , V_127 -> V_101 ) ;
F_66 ( V_33 , L_46 , V_127 -> V_55 ) ;
F_66 ( V_33 , L_47 , V_127 -> V_69 ) ;
if ( V_127 -> V_102 )
F_66 ( V_33 , L_48 , V_127 -> V_102 ) ;
if ( V_127 -> V_96 )
F_66 ( V_33 , L_49 ,
V_127 -> V_96 ) ;
if ( V_127 -> V_97 )
F_66 ( V_33 , L_50 ,
V_127 -> V_97 ) ;
for ( V_48 = 0 ; V_48 < V_127 -> V_95 ; V_48 ++ ) {
F_66 ( V_33 , L_51 , V_48 ,
V_127 -> V_103 [ V_48 ] ) ;
}
}
int F_67 ( struct V_1 * V_2 , char * V_113 )
{
struct V_10 * V_11 = F_2 ( V_2 ) ;
struct V_126 * V_127 = V_11 -> V_51 ;
T_4 V_121 ;
int V_48 , V_15 ;
V_15 = F_61 ( V_113 , & V_121 , NULL ) ;
if ( V_15 != V_123 )
return 0 ;
F_15 ( V_33 , L_52 , V_113 ,
V_121 , V_127 -> V_95 , V_127 -> V_55 ) ;
for( V_48 = 0 ; V_48 < V_127 -> V_95 ; V_48 ++ ) {
if ( V_121 == V_127 -> V_103 [ V_48 ] ) {
F_41 ( L_53 , V_113 ) ;
return 1 ;
}
}
return 0 ;
}
static int F_68 ( struct V_126 * V_127 , const char * V_46 )
{
const char * V_25 = V_46 , * V_26 ;
T_4 V_121 , * V_128 ;
int V_15 = 0 , V_129 ;
V_129 = strlen ( V_46 ) / 8 + 1 ;
F_28 ( V_128 , sizeof( V_121 ) * V_129 ) ;
if ( ! V_128 )
return - V_16 ;
while ( * V_25 && * V_25 != ' ' && * V_25 != ',' ) {
V_25 ++ ;
V_15 = F_61 ( V_25 , & V_121 , & V_26 ) ;
if ( V_15 < 0 ) {
F_18 ( L_54 ,
V_25 , V_15 ) ;
break;
}
if ( V_15 == V_123 )
V_128 [ V_127 -> V_95 ++ ] = V_121 ;
else
F_15 ( V_33 , L_55 ,
( V_130 ) ( V_26 - V_25 ) , V_25 , V_15 ) ;
V_25 = V_26 ;
if ( V_127 -> V_95 >= V_129 )
break;
}
if ( V_15 >= 0 )
V_15 = 0 ;
if ( V_127 -> V_95 ) {
F_28 ( V_127 -> V_103 , sizeof( V_121 ) *
V_127 -> V_95 ) ;
if ( V_127 -> V_103 ) {
memcpy ( V_127 -> V_103 , V_128 ,
sizeof( V_121 ) * V_127 -> V_95 ) ;
} else {
V_15 = - V_16 ;
V_127 -> V_95 = 0 ;
}
}
F_45 ( V_128 , sizeof( V_121 ) * V_129 ) ;
return V_15 ;
}
static int F_69 ( struct V_126 * V_127 , char * V_46 )
{
char * V_131 ;
int V_132 ;
if ( V_127 -> V_59 != NULL ) {
F_45 ( V_127 -> V_59 , strlen ( V_127 -> V_59 ) + 1 ) ;
V_127 -> V_59 = NULL ;
}
V_131 = strchr ( V_46 , ',' ) ;
if ( V_131 == NULL )
V_132 = strlen ( V_46 ) ;
else
V_132 = V_131 - V_46 ;
F_28 ( V_127 -> V_59 , V_132 + 1 ) ;
if ( V_127 -> V_59 == NULL )
return - V_16 ;
memcpy ( V_127 -> V_59 , V_46 , V_132 ) ;
V_127 -> V_59 [ V_132 ] = '\0' ;
return 0 ;
}
static int F_70 ( char * * V_133 , char * V_46 )
{
char * V_131 ;
int V_132 ;
if ( ( V_133 == NULL ) || ( V_46 == NULL ) )
return - V_19 ;
if ( * V_133 != NULL ) {
F_45 ( * V_133 , strlen ( * V_133 ) + 1 ) ;
* V_133 = NULL ;
}
V_131 = strchr ( V_46 , ',' ) ;
if ( V_131 == NULL )
V_132 = strlen ( V_46 ) ;
else
V_132 = V_131 - V_46 ;
F_28 ( * V_133 , V_132 + 1 ) ;
if ( * V_133 == NULL )
return - V_16 ;
memcpy ( * V_133 , V_46 , V_132 ) ;
( * V_133 ) [ V_132 ] = '\0' ;
return 0 ;
}
static int F_71 ( struct V_126 * V_127 , char * * V_46 )
{
T_1 V_23 ;
char * V_131 = * V_46 ;
char * V_134 ;
int V_132 ;
int V_135 = 0 ;
while ( F_39 ( V_131 , & V_23 , & V_131 ) == 0 ) {}
V_132 = V_131 - * V_46 ;
if ( V_132 == 0 ) {
F_12 ( 0x159 , L_56 , * V_46 ) ;
return - V_19 ;
}
if ( V_127 -> V_52 != NULL )
V_135 = strlen ( V_127 -> V_52 ) + 1 ;
F_28 ( V_134 , V_135 + V_132 + 1 ) ;
if ( V_134 == NULL )
return - V_16 ;
if ( V_127 -> V_52 != NULL ) {
memcpy ( V_134 , V_127 -> V_52 , V_135 ) ;
V_134 [ V_135 - 1 ] = ':' ;
F_45 ( V_127 -> V_52 , V_135 ) ;
}
memcpy ( V_134 + V_135 , * V_46 , V_132 ) ;
V_134 [ V_135 + V_132 ] = '\0' ;
V_127 -> V_52 = V_134 ;
* V_46 = V_131 ;
return 0 ;
}
static int F_72 ( char * V_136 , struct V_126 * V_127 )
{
char * V_25 , * V_26 , * V_137 = NULL ;
struct V_126 * V_138 = (struct V_126 * ) V_136 ;
int V_15 = 0 ;
F_3 ( V_127 ) ;
if ( ! V_136 ) {
F_12 ( 0x162 , L_57
L_58 ) ;
return - V_19 ;
}
if ( ( V_138 -> V_139 & 0xffffff00 ) == ( V_140 & 0xffffff00 ) ) {
F_12 ( 0x163 , L_59
L_60
L_61 , V_141 ) ;
return - V_19 ;
}
V_127 -> V_139 = V_140 ;
F_28 ( V_127 -> V_105 , 4096 ) ;
if ( V_127 -> V_105 == NULL )
return - V_16 ;
V_127 -> V_105 [ 0 ] = '\0' ;
V_25 = V_136 ;
while ( * V_25 ) {
int V_142 = 0 ;
int V_143 = V_144 ;
while ( * V_25 == ' ' || * V_25 == ',' )
V_25 ++ ;
if ( strncmp ( V_25 , L_62 , 11 ) == 0 ) {
V_127 -> V_69 |= V_145 ;
V_142 ++ ;
} else if ( strncmp ( V_25 , L_63 , 19 ) == 0 ) {
V_127 -> V_96 = F_73 ( int ,
F_62 ( V_25 + 19 , NULL , 10 ) , V_143 ) ;
V_142 ++ ;
} else if ( strncmp ( V_25 , L_64 , 19 ) == 0 ) {
V_127 -> V_97 = F_73 ( int ,
F_62 ( V_25 + 19 , NULL , 10 ) , V_143 ) ;
V_142 ++ ;
} else if ( strncmp ( V_25 , L_65 , 4 ) == 0 ) {
V_127 -> V_69 |= V_72 ;
V_142 ++ ;
} else if ( strncmp ( V_25 , L_66 , 5 ) == 0 ) {
V_127 -> V_69 |= V_146 ;
V_142 ++ ;
} else if ( strncmp ( V_25 , L_67 , 5 ) == 0 ) {
V_127 -> V_69 |= V_147 ;
V_142 ++ ;
} else if ( strncmp ( V_25 , L_68 , 7 ) == 0 ) {
V_127 -> V_69 |= V_148 ;
V_142 ++ ;
} else if ( strncmp ( V_25 , V_76 ,
sizeof( V_76 ) - 1 ) == 0 ) {
V_26 = V_25 + sizeof( V_76 ) - 1 ;
V_15 = F_71 ( V_127 , & V_26 ) ;
if ( V_15 )
goto V_149;
V_142 ++ ;
} else if ( strncmp ( V_25 , L_69 , 9 ) == 0 ) {
V_127 -> V_69 |= V_150 ;
V_142 ++ ;
} else if ( strncmp ( V_25 , L_70 , 6 ) == 0 ) {
V_127 -> V_69 |= V_151 ;
V_142 ++ ;
} else if ( strncmp ( V_25 , L_71 , 6 ) == 0 ) {
V_127 -> V_69 |= V_152 ;
V_142 ++ ;
} else if ( strncmp ( V_25 , L_72 , 10 ) == 0 ) {
V_127 -> V_69 |= V_153 ;
V_142 ++ ;
} else if ( strncmp ( V_25 , L_73 , 7 ) == 0 ) {
V_15 = F_69 ( V_127 , V_25 + 7 ) ;
if ( V_15 )
goto V_149;
V_142 ++ ;
} else if ( strncmp ( V_25 , L_74 , 8 ) == 0 ) {
V_15 = F_68 ( V_127 , V_25 + 7 ) ;
if ( V_15 )
goto V_149;
V_142 ++ ;
} else if ( strncmp ( V_25 , L_75 , 3 ) == 0 ) {
V_127 -> V_69 |= V_154 ;
V_142 ++ ;
} else if ( strncmp ( V_25 , L_76 , 7 ) == 0 ) {
V_15 = F_70 ( & V_127 -> V_101 , V_25 + 7 ) ;
if ( V_15 )
goto V_149;
V_142 ++ ;
} else if ( strncmp ( V_25 , L_77 , 6 ) == 0 ) {
int V_132 ;
char * V_131 = strchr ( V_25 + 6 , ',' ) ;
if ( V_131 == NULL )
V_132 = strlen ( V_25 ) ;
else
V_132 = V_131 - V_25 ;
V_132 -= 6 ;
strncat ( V_127 -> V_105 , V_25 + 6 , V_132 ) ;
strcat ( V_127 -> V_105 , L_78 ) ;
V_142 ++ ;
} else if ( strncmp ( V_25 , L_79 , 4 ) == 0 ) {
V_15 = F_70 ( & V_127 -> V_104 , V_25 + 4 ) ;
if ( V_15 )
goto V_149;
V_142 ++ ;
}
else if ( strncmp ( V_25 , L_80 , 7 ) == 0 ) {
V_137 = V_25 + 7 ;
* V_25 = '\0' ;
break;
}
V_26 = strchr ( V_25 , ',' ) ;
if ( V_26 == NULL ) {
if ( V_142 )
* V_25 = '\0' ;
break;
}
V_26 ++ ;
if ( V_142 )
memmove ( V_25 , V_26 , strlen ( V_26 ) + 1 ) ;
else
V_25 = V_26 ;
}
if ( ! V_137 ) {
F_12 ( 0x164 , L_81
L_82 ) ;
goto V_149;
}
V_25 = strstr ( V_137 , L_83 ) ;
if ( V_25 ) {
++ V_25 ;
V_127 -> V_69 |= V_155 ;
while ( * ++ V_25 == '/' ) ;
F_28 ( V_127 -> V_101 , strlen ( V_25 ) + 8 ) ;
if ( ! V_127 -> V_101 )
return - V_16 ;
sprintf ( V_127 -> V_101 , L_84 , V_25 ) ;
}
F_28 ( V_127 -> V_55 , strlen ( V_137 ) + 1 ) ;
if ( ! V_127 -> V_55 )
return - V_16 ;
strcpy ( V_127 -> V_55 , V_137 ) ;
V_25 = V_136 + strlen ( V_136 ) - 1 ;
while ( V_25 >= V_136 && ( * V_25 == ',' || * V_25 == ' ' ) )
* V_25 -- = 0 ;
if ( * V_136 != 0 ) {
F_28 ( V_127 -> V_102 , strlen ( V_136 ) + 1 ) ;
if ( ! V_127 -> V_102 )
return - V_16 ;
strcpy ( V_127 -> V_102 , V_136 ) ;
}
F_65 ( V_127 ) ;
V_127 -> V_139 = V_140 ;
return V_15 ;
V_149:
F_18 ( L_85 , V_136 ) ;
return - V_19 ;
}
int F_74 ( struct V_1 * V_2 , void * V_38 , int V_156 )
{
struct V_126 * V_127 ;
struct V_157 * V_158 = V_38 ;
struct V_10 * V_11 ;
int V_15 ;
F_15 ( V_33 | V_159 , L_86 , V_2 ) ;
V_11 = F_51 ( V_2 ) ;
if ( ! V_11 )
return - V_16 ;
V_127 = V_11 -> V_51 ;
F_75 () ;
F_56 () ;
if ( F_72 ( ( char * ) ( V_158 -> V_160 ) , V_127 ) ) {
F_54 ( V_2 ) ;
GOTO ( V_74 , V_15 = - V_19 ) ;
}
if ( F_32 ( V_127 ) ) {
F_15 ( V_33 , L_87 , V_127 -> V_101 ) ;
if ( ! V_161 ) {
F_12 ( 0x165 , L_88
L_89
L_90 ) ;
F_54 ( V_2 ) ;
V_15 = - V_162 ;
} else {
V_15 = F_19 ( V_2 ) ;
if ( V_15 ) {
F_54 ( V_2 ) ;
GOTO ( V_74 , V_15 ) ;
}
V_15 = (* V_161)( V_2 , V_158 -> V_163 ) ;
}
} else {
F_18 ( L_91
L_92 ) ;
V_15 = - V_19 ;
}
GOTO ( V_74 , V_15 ) ;
V_74:
if ( V_15 ) {
F_18 ( L_93 ,
F_2 ( V_2 ) ? V_127 -> V_55 : L_17 , V_15 ) ;
} else {
F_15 ( V_164 , L_94 ,
V_127 -> V_55 ) ;
}
F_76 () ;
return V_15 ;
}
void F_77 ( int (* F_78)( struct V_1 * V_2 ,
struct V_165 * V_166 ) )
{
V_161 = F_78 ;
}
void F_79 ( void (* F_78)( struct V_1 * V_2 ) )
{
V_167 = F_78 ;
}
struct V_168 * F_80 ( struct V_169 * V_170 , int V_68 ,
const char * V_137 , void * V_38 )
{
struct V_157 V_158 = { V_38 , NULL } ;
return F_81 ( V_170 , V_68 , & V_158 , F_74 ) ;
}
void F_82 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = F_2 ( V_2 ) ;
if ( V_167 && V_11 && ! F_20 ( V_11 ) )
(* V_167)( V_2 ) ;
F_83 ( V_2 ) ;
}
int F_84 ( void )
{
return F_85 ( & V_171 ) ;
}
int F_86 ( void )
{
return F_87 ( & V_171 ) ;
}
