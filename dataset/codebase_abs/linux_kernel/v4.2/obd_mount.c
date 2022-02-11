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
if ( V_9 == NULL )
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
int F_14 ( char * V_23 , T_1 V_24 , int V_25 ,
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
int F_17 ( char * V_32 , char * type , char * V_33 ,
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
char * V_44 = NULL , * V_45 = NULL , * V_46 = NULL ;
char * V_47 ;
int V_15 = 0 , V_48 = 0 , V_49 , V_50 ;
F_3 ( V_11 -> V_51 ) ;
if ( F_20 ( V_11 ) ) {
V_47 = V_11 -> V_51 -> V_52 ;
if ( V_11 -> V_51 -> V_52 &&
( F_21 ( V_11 -> V_51 -> V_52 , & V_24 , & V_47 ) == 0 ) ) {
V_48 ++ ;
} else if ( F_22 ( V_11 ) ) {
T_3 V_53 ;
while ( ( V_15 = F_23 ( V_48 ++ , & V_53 ) ) != - V_21 ) {
if ( F_24 ( F_25 ( V_53 . V_24 ) ) == V_54 )
continue;
V_24 = V_53 . V_24 ;
V_48 ++ ;
break;
}
}
} else {
V_47 = V_11 -> V_51 -> V_55 ;
if ( F_21 ( V_47 , & V_24 , & V_47 ) == 0 )
V_48 ++ ;
}
if ( V_48 == 0 ) {
F_18 ( L_7 ) ;
return - V_20 ;
}
F_26 ( & V_56 ) ;
V_50 = strlen ( V_57 ) + strlen ( F_27 ( V_24 ) ) + 1 ;
V_44 = F_4 ( V_50 , V_16 ) ;
V_45 = F_4 ( V_50 + 2 , V_16 ) ;
if ( ! V_44 || ! V_45 ) {
V_15 = - V_17 ;
goto V_58;
}
sprintf ( V_44 , L_8 , V_57 , F_27 ( V_24 ) ) ;
V_46 = V_11 -> V_51 -> V_59 ? V_11 -> V_51 -> V_59 : L_9 ;
V_39 = F_4 ( sizeof( * V_39 ) , V_16 ) ;
if ( V_39 == NULL ) {
V_15 = - V_17 ;
goto V_58;
}
V_40 = F_28 ( V_44 ) ;
if ( V_40 && ! V_40 -> V_60 ) {
int V_61 ;
V_15 = F_29 ( NULL , V_40 -> V_62 ,
strlen ( V_63 ) , V_63 ,
strlen ( V_46 ) , V_46 , NULL ) ;
if ( V_15 )
goto V_58;
F_30 ( & V_40 -> V_64 . V_65 . V_66 ) ;
if ( F_31 ( V_11 -> V_51 ) ) {
int V_67 ;
int V_68 = sizeof( * V_39 ) ;
T_4 * V_69 = & V_11 -> V_51 -> V_70 ;
V_15 = F_32 ( NULL , V_40 -> V_62 ,
strlen ( V_71 ) , V_71 ,
& V_68 , V_39 , NULL ) ;
F_3 ( V_15 == 0 ) ;
V_67 = F_33 ( V_39 , V_72 ) ;
if ( V_67 ^ ! ( * V_69 & V_73 ) ) {
F_34 (
L_10 ,
V_67 ? L_11 : L_12 ) ;
if ( V_67 )
* V_69 &= ~ V_73 ;
else
* V_69 |= V_73 ;
}
}
V_61 = 0 ;
if ( F_22 ( V_11 ) ) {
F_15 ( V_34 , L_13 ) ;
V_61 = 1 ;
}
V_61 ++ ;
F_15 ( V_34 , L_14 , V_44 ,
V_61 ) ;
V_15 = F_29 ( NULL , V_40 -> V_62 ,
sizeof( V_74 ) ,
V_74 ,
sizeof( V_61 ) , & V_61 , NULL ) ;
V_15 = 0 ;
goto V_75;
}
F_15 ( V_34 , L_15 , V_44 ) ;
V_48 = 0 ;
sprintf ( V_45 , L_16 , V_44 , V_48 ) ;
if ( F_20 ( V_11 ) ) {
V_47 = V_11 -> V_51 -> V_52 ;
if ( F_22 ( V_11 ) ) {
T_3 V_53 ;
while ( ( V_15 = F_23 ( V_48 ++ , & V_53 ) ) != - V_21 ) {
V_15 = F_14 ( V_44 , V_53 . V_24 ,
V_76 , V_45 ,
NULL , NULL , NULL ) ;
}
} else {
if ( V_11 -> V_51 -> V_52 ) {
V_47 = V_11 -> V_51 -> V_52 ;
} else if ( F_35 ( V_47 , V_77 ,
& V_47 ) != 0 ) {
F_18 ( L_17 ) ;
V_15 = - V_20 ;
goto V_58;
}
while ( F_21 ( V_47 , & V_24 , & V_47 ) == 0 ) {
V_15 = F_14 ( V_44 , V_24 ,
V_76 , V_45 ,
NULL , NULL , NULL ) ;
V_48 ++ ;
}
}
} else {
V_47 = V_11 -> V_51 -> V_55 ;
while ( F_21 ( V_47 , & V_24 , & V_47 ) == 0 ) {
V_15 = F_14 ( V_44 , V_24 ,
V_76 , V_45 , NULL , NULL , NULL ) ;
V_48 ++ ;
if ( * V_47 == ':' )
break;
}
}
if ( V_48 == 0 ) {
F_18 ( L_7 ) ;
V_15 = - V_20 ;
goto V_58;
}
V_11 -> V_51 -> V_78 = 1 ;
V_33 = F_4 ( sizeof( * V_33 ) , V_16 ) ;
if ( ! V_33 ) {
V_15 = - V_17 ;
goto V_58;
}
F_36 ( V_43 ) ;
F_37 ( V_43 , V_33 ) ;
V_15 = F_17 ( V_44 , V_79 ,
( char * ) V_33 -> V_33 , V_80 ,
V_45 , NULL , NULL ) ;
F_11 ( V_33 ) ;
if ( V_15 )
goto V_58;
V_48 = 1 ;
while ( V_47 && ( ( * V_47 == ':' ||
F_35 ( V_47 , V_77 , & V_47 ) == 0 ) ) ) {
sprintf ( V_45 , L_16 , V_44 , V_48 ) ;
V_49 = 0 ;
while ( F_38 ( V_47 , & V_24 , & V_47 ) == 0 ) {
V_49 ++ ;
V_15 = F_14 ( V_44 , V_24 ,
V_76 , V_45 , NULL , NULL , NULL ) ;
if ( * V_47 == ':' )
break;
}
if ( V_49 > 0 ) {
V_15 = F_14 ( V_44 , 0 , V_81 ,
V_45 , NULL , NULL , NULL ) ;
V_48 ++ ;
} else {
break;
}
}
V_11 -> V_51 -> V_78 = V_48 ;
V_40 = F_28 ( V_44 ) ;
if ( ! V_40 ) {
F_18 ( L_18 , V_44 ) ;
V_15 = - V_82 ;
goto V_58;
}
V_15 = F_29 ( NULL , V_40 -> V_62 ,
strlen ( V_63 ) , V_63 ,
strlen ( V_46 ) , V_46 , NULL ) ;
if ( V_15 )
goto V_58;
F_39 ( & V_40 -> V_64 . V_65 . V_66 , 1 ) ;
V_39 -> V_83 = V_84 | V_85 |
V_86 | V_87 |
V_88 ;
#if V_89 < F_40 ( 3 , 2 , 50 , 0 )
V_39 -> V_83 |= V_90 ;
#else
#warning "LU-1644: Remove old OBD_CONNECT_MNE_SWAB fixup and imp_need_mne_swab"
#endif
if ( F_31 ( V_11 -> V_51 ) &&
V_11 -> V_51 -> V_70 & V_73 )
V_39 -> V_83 &= ~ V_87 ;
V_39 -> V_91 = V_89 ;
V_15 = F_41 ( NULL , & exp , V_40 , & ( V_40 -> V_42 ) , V_39 , NULL ) ;
if ( V_15 ) {
F_18 ( L_19 , V_15 ) ;
goto V_75;
}
V_40 -> V_64 . V_65 . V_92 = exp ;
V_75:
V_11 -> V_14 = V_40 ;
V_58:
F_42 ( & V_56 ) ;
F_11 ( V_39 ) ;
F_11 ( V_44 ) ;
F_11 ( V_45 ) ;
return V_15 ;
}
static int F_43 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = F_2 ( V_2 ) ;
struct V_12 * V_40 ;
char * V_45 = NULL , * V_47 = NULL ;
int V_48 , V_15 = 0 , V_50 = 0 ;
if ( ! V_11 )
return - V_21 ;
V_40 = V_11 -> V_14 ;
if ( ! V_40 )
return - V_21 ;
V_11 -> V_14 = NULL ;
F_26 ( & V_56 ) ;
F_3 ( F_44 ( & V_40 -> V_64 . V_65 . V_66 ) > 0 ) ;
if ( ! F_45 ( & V_40 -> V_64 . V_65 . V_66 ) ) {
F_15 ( V_34 , L_20 ,
F_44 ( & V_40 -> V_64 . V_65 . V_66 ) ) ;
V_15 = - V_93 ;
goto V_75;
}
V_40 -> V_94 = 1 ;
if ( V_40 -> V_64 . V_65 . V_92 ) {
V_15 = F_46 ( V_40 -> V_64 . V_65 . V_92 ) ;
if ( V_15 )
F_15 ( V_34 , L_21 , V_15 ) ;
}
V_50 = strlen ( V_40 -> V_18 ) + 6 ;
V_45 = F_4 ( V_50 , V_16 ) ;
if ( V_45 ) {
strcpy ( V_45 , V_40 -> V_18 ) ;
V_47 = V_45 + strlen ( V_45 ) ;
}
V_15 = F_47 ( V_40 ) ;
if ( V_15 )
goto V_75;
if ( ! V_45 ) {
V_15 = - V_17 ;
goto V_75;
}
for ( V_48 = 0 ; V_48 < V_11 -> V_51 -> V_78 ; V_48 ++ ) {
sprintf ( V_47 , L_22 , V_48 ) ;
V_15 = F_14 ( V_57 , 0 , V_95 ,
V_45 , NULL , NULL , NULL ) ;
if ( V_15 )
F_18 ( L_23 ,
V_45 , V_15 ) ;
}
V_75:
F_11 ( V_45 ) ;
F_42 ( & V_56 ) ;
return V_15 ;
}
struct V_10 * F_48 ( struct V_1 * V_2 )
{
struct V_10 * V_11 ;
V_11 = F_4 ( sizeof( * V_11 ) , V_16 ) ;
if ( ! V_11 )
return NULL ;
V_11 -> V_51 = F_4 ( sizeof( * V_11 -> V_51 ) , V_16 ) ;
if ( ! V_11 -> V_51 ) {
F_11 ( V_11 ) ;
return NULL ;
}
V_11 -> V_51 -> V_96 = 0 ;
V_11 -> V_51 -> V_97 = 0 ;
V_11 -> V_51 -> V_98 = 0 ;
F_49 ( V_2 ) = V_11 ;
F_39 ( & V_11 -> V_99 , 1 ) ;
V_11 -> V_100 = V_101 ;
return V_11 ;
}
static int F_50 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = F_2 ( V_2 ) ;
F_3 ( V_11 != NULL ) ;
F_15 ( V_34 , L_24 , V_11 ) ;
F_3 ( F_44 ( & V_11 -> V_99 ) == 0 ) ;
if ( V_11 -> V_51 != NULL ) {
F_11 ( V_11 -> V_51 -> V_55 ) ;
F_11 ( V_11 -> V_51 -> V_102 ) ;
F_11 ( V_11 -> V_51 -> V_59 ) ;
F_11 ( V_11 -> V_51 -> V_103 ) ;
if ( V_11 -> V_51 -> V_96 )
F_11 ( V_11 -> V_51 -> V_104 ) ;
F_11 ( V_11 -> V_51 -> V_52 ) ;
F_11 ( V_11 -> V_51 -> V_105 ) ;
F_11 ( V_11 -> V_51 -> V_106 ) ;
F_11 ( V_11 -> V_51 ) ;
}
F_3 ( V_11 -> V_107 == NULL ) ;
F_11 ( V_11 ) ;
F_49 ( V_2 ) = NULL ;
return 0 ;
}
int F_51 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = F_2 ( V_2 ) ;
F_3 ( V_11 != NULL ) ;
F_15 ( V_34 , L_25 , V_2 , F_44 ( & V_11 -> V_99 ) ) ;
if ( F_45 ( & V_11 -> V_99 ) ) {
if ( F_20 ( V_11 ) && V_11 -> V_108 ) {
F_52 ( & V_11 -> V_109 -> V_110 ) ;
V_11 -> V_108 -> V_111 -> V_112 . V_113 = NULL ;
V_11 -> V_109 = NULL ;
F_46 ( V_11 -> V_108 ) ;
F_53 () ;
}
F_50 ( V_2 ) ;
return 1 ;
}
return 0 ;
}
int F_54 ( const char * V_114 , char * V_115 , const char * * V_116 )
{
const char * V_117 ;
V_117 = V_114 + F_55 ( V_114 , 8 ) ;
for (; V_117 > V_114 && * V_117 != '-' && * V_117 != ':' ; V_117 -- )
;
if ( V_117 == V_114 )
return - V_20 ;
if ( V_115 != NULL ) {
strncpy ( V_115 , V_114 , V_117 - V_114 ) ;
V_115 [ V_117 - V_114 ] = '\0' ;
}
if ( V_116 != NULL )
* V_116 = V_117 ;
return 0 ;
}
int F_56 ( const char * V_118 , char * V_114 , const char * * V_116 ,
T_5 V_119 )
{
int V_15 ;
const char * V_117 ;
V_15 = F_54 ( V_118 , NULL , & V_117 ) ;
if ( V_15 != 0 )
return V_15 ;
if ( V_116 != NULL )
* V_116 = V_117 ;
if ( F_57 ( V_114 , V_117 + 1 , V_119 ) >= V_119 )
return - V_120 ;
return 0 ;
}
int F_58 ( const char * V_114 , T_4 * V_121 , const char * * V_116 )
{
unsigned long V_122 ;
int V_15 ;
const char * V_117 ;
V_15 = F_54 ( V_114 , NULL , & V_117 ) ;
if ( V_15 != 0 )
return V_15 ;
V_117 ++ ;
if ( strncmp ( V_117 , L_26 , 3 ) == 0 )
V_15 = V_123 ;
else if ( strncmp ( V_117 , L_27 , 3 ) == 0 )
V_15 = V_124 ;
else
return - V_20 ;
V_117 += 3 ;
if ( strncmp ( V_117 , L_28 , 3 ) == 0 ) {
if ( V_116 != NULL )
* V_116 = V_117 + 3 ;
return V_15 | V_125 ;
}
V_122 = F_59 ( V_117 , ( char * * ) V_116 , 16 ) ;
if ( V_121 != NULL )
* V_121 = V_122 ;
if ( V_116 != NULL && strncmp ( V_126 , * V_116 + 1 ,
sizeof( V_126 ) - 1 ) == 0 )
* V_116 += sizeof( V_126 ) ;
return V_15 ;
}
int F_60 ( struct V_1 * V_2 )
{
int V_15 ;
F_15 ( V_34 , L_29 , V_2 ) ;
V_15 = F_43 ( V_2 ) ;
if ( V_15 && ( V_15 != - V_21 ) ) {
if ( V_15 != - V_93 ) {
F_18 ( L_30 , V_15 ) ;
return V_15 ;
}
F_15 ( V_34 , L_31 ) ;
}
F_51 ( V_2 ) ;
F_61 () ;
return V_15 ;
}
static void F_62 ( struct V_127 * V_128 )
{
int V_48 ;
F_63 ( V_34 , L_32 ) ;
if ( F_31 ( V_128 ) )
F_63 ( V_34 , L_33 , V_128 -> V_102 ) ;
F_63 ( V_34 , L_34 , V_128 -> V_55 ) ;
F_63 ( V_34 , L_35 , V_128 -> V_70 ) ;
if ( V_128 -> V_103 )
F_63 ( V_34 , L_36 , V_128 -> V_103 ) ;
if ( V_128 -> V_97 )
F_63 ( V_34 , L_37 ,
V_128 -> V_97 ) ;
if ( V_128 -> V_98 )
F_63 ( V_34 , L_38 ,
V_128 -> V_98 ) ;
for ( V_48 = 0 ; V_48 < V_128 -> V_96 ; V_48 ++ ) {
F_63 ( V_34 , L_39 , V_48 ,
V_128 -> V_104 [ V_48 ] ) ;
}
}
int F_64 ( struct V_1 * V_2 , char * V_114 )
{
struct V_10 * V_11 = F_2 ( V_2 ) ;
struct V_127 * V_128 = V_11 -> V_51 ;
T_4 V_122 ;
int V_48 , V_15 ;
V_15 = F_58 ( V_114 , & V_122 , NULL ) ;
if ( V_15 != V_124 )
return 0 ;
F_15 ( V_34 , L_40 , V_114 ,
V_122 , V_128 -> V_96 , V_128 -> V_55 ) ;
for ( V_48 = 0 ; V_48 < V_128 -> V_96 ; V_48 ++ ) {
if ( V_122 == V_128 -> V_104 [ V_48 ] ) {
F_65 ( L_41 , V_114 ) ;
return 1 ;
}
}
return 0 ;
}
static int F_66 ( struct V_127 * V_128 , const char * V_47 )
{
const char * V_26 = V_47 , * V_27 ;
T_4 V_122 , * V_129 ;
int V_15 = 0 , V_130 ;
V_130 = strlen ( V_47 ) / 8 + 1 ;
V_129 = F_67 ( V_130 , sizeof( V_122 ) , V_16 ) ;
if ( ! V_129 )
return - V_17 ;
while ( * V_26 && * V_26 != ' ' && * V_26 != ',' ) {
V_26 ++ ;
V_15 = F_58 ( V_26 , & V_122 , & V_27 ) ;
if ( V_15 < 0 ) {
F_18 ( L_42 ,
V_26 , V_15 ) ;
break;
}
if ( V_15 == V_124 )
V_129 [ V_128 -> V_96 ++ ] = V_122 ;
else
F_15 ( V_34 , L_43 ,
( V_131 ) ( V_27 - V_26 ) , V_26 , V_15 ) ;
V_26 = V_27 ;
if ( V_128 -> V_96 >= V_130 )
break;
}
if ( V_15 >= 0 )
V_15 = 0 ;
if ( V_128 -> V_96 ) {
V_128 -> V_104 = F_67 ( V_128 -> V_96 ,
sizeof( V_122 ) , V_16 ) ;
if ( V_128 -> V_104 ) {
memcpy ( V_128 -> V_104 , V_129 ,
sizeof( V_122 ) * V_128 -> V_96 ) ;
} else {
V_15 = - V_17 ;
V_128 -> V_96 = 0 ;
}
}
F_11 ( V_129 ) ;
return V_15 ;
}
static int F_68 ( struct V_127 * V_128 , char * V_47 )
{
char * V_132 ;
int V_133 ;
F_11 ( V_128 -> V_59 ) ;
V_128 -> V_59 = NULL ;
V_132 = strchr ( V_47 , ',' ) ;
if ( V_132 == NULL )
V_133 = strlen ( V_47 ) ;
else
V_133 = V_132 - V_47 ;
V_128 -> V_59 = F_4 ( V_133 + 1 , V_16 ) ;
if ( V_128 -> V_59 == NULL )
return - V_17 ;
memcpy ( V_128 -> V_59 , V_47 , V_133 ) ;
V_128 -> V_59 [ V_133 ] = '\0' ;
return 0 ;
}
static int F_69 ( char * * V_134 , char * V_47 )
{
char * V_132 ;
int V_133 ;
if ( ( V_134 == NULL ) || ( V_47 == NULL ) )
return - V_20 ;
F_11 ( * V_134 ) ;
* V_134 = NULL ;
V_132 = strchr ( V_47 , ',' ) ;
if ( V_132 == NULL )
V_133 = strlen ( V_47 ) ;
else
V_133 = V_132 - V_47 ;
* V_134 = F_4 ( V_133 + 1 , V_16 ) ;
if ( * V_134 == NULL )
return - V_17 ;
memcpy ( * V_134 , V_47 , V_133 ) ;
( * V_134 ) [ V_133 ] = '\0' ;
return 0 ;
}
static int F_70 ( struct V_127 * V_128 , char * * V_47 )
{
T_1 V_24 ;
char * V_132 = * V_47 ;
char * V_135 ;
int V_133 ;
int V_136 = 0 ;
while ( F_38 ( V_132 , & V_24 , & V_132 ) == 0 ) {}
V_133 = V_132 - * V_47 ;
if ( V_133 == 0 ) {
F_12 ( 0x159 , L_44 , * V_47 ) ;
return - V_20 ;
}
if ( V_128 -> V_52 != NULL )
V_136 = strlen ( V_128 -> V_52 ) + 1 ;
V_135 = F_4 ( V_136 + V_133 + 1 , V_16 ) ;
if ( V_135 == NULL )
return - V_17 ;
if ( V_128 -> V_52 != NULL ) {
memcpy ( V_135 , V_128 -> V_52 , V_136 ) ;
V_135 [ V_136 - 1 ] = ':' ;
F_11 ( V_128 -> V_52 ) ;
}
memcpy ( V_135 + V_136 , * V_47 , V_133 ) ;
V_135 [ V_136 + V_133 ] = '\0' ;
V_128 -> V_52 = V_135 ;
* V_47 = V_132 ;
return 0 ;
}
static int F_71 ( char * V_137 , struct V_127 * V_128 )
{
char * V_26 , * V_27 , * V_138 = NULL ;
struct V_127 * V_139 = (struct V_127 * ) V_137 ;
int V_15 = 0 ;
F_3 ( V_128 ) ;
if ( ! V_137 ) {
F_12 ( 0x162 , L_45 ) ;
return - V_20 ;
}
if ( ( V_139 -> V_140 & 0xffffff00 ) == ( V_141 & 0xffffff00 ) ) {
F_12 ( 0x163 , L_46 ,
V_142 ) ;
return - V_20 ;
}
V_128 -> V_140 = V_141 ;
V_128 -> V_106 = F_4 ( 4096 , V_16 ) ;
if ( V_128 -> V_106 == NULL )
return - V_17 ;
V_128 -> V_106 [ 0 ] = '\0' ;
V_26 = V_137 ;
while ( * V_26 ) {
int V_143 = 0 ;
int V_144 = V_145 ;
while ( * V_26 == ' ' || * V_26 == ',' )
V_26 ++ ;
if ( strncmp ( V_26 , L_47 , 11 ) == 0 ) {
V_128 -> V_70 |= V_146 ;
V_143 ++ ;
} else if ( strncmp ( V_26 , L_48 , 19 ) == 0 ) {
V_128 -> V_97 = F_72 ( int ,
F_59 ( V_26 + 19 , NULL , 10 ) , V_144 ) ;
V_143 ++ ;
} else if ( strncmp ( V_26 , L_49 , 19 ) == 0 ) {
V_128 -> V_98 = F_72 ( int ,
F_59 ( V_26 + 19 , NULL , 10 ) , V_144 ) ;
V_143 ++ ;
} else if ( strncmp ( V_26 , L_50 , 4 ) == 0 ) {
V_128 -> V_70 |= V_73 ;
V_143 ++ ;
} else if ( strncmp ( V_26 , L_51 , 5 ) == 0 ) {
V_128 -> V_70 |= V_147 ;
V_143 ++ ;
} else if ( strncmp ( V_26 , L_52 , 5 ) == 0 ) {
V_128 -> V_70 |= V_148 ;
V_143 ++ ;
} else if ( strncmp ( V_26 , L_53 , 7 ) == 0 ) {
V_128 -> V_70 |= V_149 ;
V_143 ++ ;
} else if ( strncmp ( V_26 , V_77 ,
sizeof( V_77 ) - 1 ) == 0 ) {
V_27 = V_26 + sizeof( V_77 ) - 1 ;
V_15 = F_70 ( V_128 , & V_27 ) ;
if ( V_15 )
goto V_150;
V_143 ++ ;
} else if ( strncmp ( V_26 , L_54 , 9 ) == 0 ) {
V_128 -> V_70 |= V_151 ;
V_143 ++ ;
} else if ( strncmp ( V_26 , L_55 , 6 ) == 0 ) {
V_128 -> V_70 |= V_152 ;
V_143 ++ ;
} else if ( strncmp ( V_26 , L_56 , 6 ) == 0 ) {
V_128 -> V_70 |= V_153 ;
V_143 ++ ;
} else if ( strncmp ( V_26 , L_57 , 10 ) == 0 ) {
V_128 -> V_70 |= V_154 ;
V_143 ++ ;
} else if ( strncmp ( V_26 , L_58 , 7 ) == 0 ) {
V_15 = F_68 ( V_128 , V_26 + 7 ) ;
if ( V_15 )
goto V_150;
V_143 ++ ;
} else if ( strncmp ( V_26 , L_59 , 8 ) == 0 ) {
V_15 = F_66 ( V_128 , V_26 + 7 ) ;
if ( V_15 )
goto V_150;
V_143 ++ ;
} else if ( strncmp ( V_26 , L_60 , 3 ) == 0 ) {
V_128 -> V_70 |= V_155 ;
V_143 ++ ;
} else if ( strncmp ( V_26 , L_61 , 7 ) == 0 ) {
V_15 = F_69 ( & V_128 -> V_102 , V_26 + 7 ) ;
if ( V_15 )
goto V_150;
V_143 ++ ;
} else if ( strncmp ( V_26 , L_62 , 6 ) == 0 ) {
int V_133 ;
char * V_132 = strchr ( V_26 + 6 , ',' ) ;
if ( V_132 == NULL )
V_133 = strlen ( V_26 ) ;
else
V_133 = V_132 - V_26 ;
V_133 -= 6 ;
strncat ( V_128 -> V_106 , V_26 + 6 , V_133 ) ;
strcat ( V_128 -> V_106 , L_63 ) ;
V_143 ++ ;
} else if ( strncmp ( V_26 , L_64 , 4 ) == 0 ) {
V_15 = F_69 ( & V_128 -> V_105 , V_26 + 4 ) ;
if ( V_15 )
goto V_150;
V_143 ++ ;
}
else if ( strncmp ( V_26 , L_65 , 7 ) == 0 ) {
V_138 = V_26 + 7 ;
* V_26 = '\0' ;
break;
}
V_27 = strchr ( V_26 , ',' ) ;
if ( V_27 == NULL ) {
if ( V_143 )
* V_26 = '\0' ;
break;
}
V_27 ++ ;
if ( V_143 )
memmove ( V_26 , V_27 , strlen ( V_27 ) + 1 ) ;
else
V_26 = V_27 ;
}
if ( ! V_138 ) {
F_12 ( 0x164 , L_66 ) ;
goto V_150;
}
V_26 = strstr ( V_138 , L_67 ) ;
if ( V_26 ) {
++ V_26 ;
V_128 -> V_70 |= V_156 ;
while ( * ++ V_26 == '/' ) ;
V_128 -> V_102 = F_4 ( strlen ( V_26 ) + 8 , V_16 ) ;
if ( ! V_128 -> V_102 )
return - V_17 ;
sprintf ( V_128 -> V_102 , L_68 , V_26 ) ;
}
V_128 -> V_55 = F_4 ( strlen ( V_138 ) + 1 , V_16 ) ;
if ( ! V_128 -> V_55 )
return - V_17 ;
strcpy ( V_128 -> V_55 , V_138 ) ;
V_26 = V_137 + strlen ( V_137 ) - 1 ;
while ( V_26 >= V_137 && ( * V_26 == ',' || * V_26 == ' ' ) )
* V_26 -- = 0 ;
if ( * V_137 != 0 ) {
V_128 -> V_103 = F_4 ( strlen ( V_137 ) + 1 , V_16 ) ;
if ( ! V_128 -> V_103 )
return - V_17 ;
strcpy ( V_128 -> V_103 , V_137 ) ;
}
F_62 ( V_128 ) ;
V_128 -> V_140 = V_141 ;
return V_15 ;
V_150:
F_18 ( L_69 , V_137 ) ;
return - V_20 ;
}
int F_73 ( struct V_1 * V_2 , void * V_39 , int V_157 )
{
struct V_127 * V_128 ;
struct V_158 * V_159 = V_39 ;
struct V_10 * V_11 ;
int V_15 ;
F_15 ( V_34 | V_160 , L_70 , V_2 ) ;
V_11 = F_48 ( V_2 ) ;
if ( ! V_11 )
return - V_17 ;
V_128 = V_11 -> V_51 ;
F_74 () ;
F_53 () ;
if ( F_71 ( ( char * ) ( V_159 -> V_161 ) , V_128 ) ) {
F_51 ( V_2 ) ;
V_15 = - V_20 ;
goto V_75;
}
if ( F_31 ( V_128 ) ) {
F_15 ( V_34 , L_71 , V_128 -> V_102 ) ;
if ( V_162 == NULL )
F_75 ( L_72 ) ;
if ( V_162 == NULL ) {
F_12 ( 0x165 , L_73 ) ;
F_51 ( V_2 ) ;
V_15 = - V_163 ;
} else {
V_15 = F_19 ( V_2 ) ;
if ( V_15 ) {
F_51 ( V_2 ) ;
goto V_75;
}
V_15 = (* V_162)( V_2 , V_159 -> V_164 ) ;
}
} else {
F_18 ( L_74 ) ;
V_15 = - V_20 ;
}
goto V_75;
V_75:
if ( V_15 ) {
F_18 ( L_75 ,
F_2 ( V_2 ) ? V_128 -> V_55 : L_9 , V_15 ) ;
} else {
F_15 ( V_165 , L_76 ,
V_128 -> V_55 ) ;
}
F_76 () ;
return V_15 ;
}
void F_77 ( int (* F_78)( struct V_1 * V_2 ,
struct V_166 * V_167 ) )
{
V_162 = F_78 ;
}
void F_79 ( void (* F_78)( struct V_1 * V_2 ) )
{
V_168 = F_78 ;
}
struct V_169 * F_80 ( struct V_170 * V_171 , int V_69 ,
const char * V_138 , void * V_39 )
{
struct V_158 V_159 = {
. V_161 = V_39 ,
. V_164 = NULL
} ;
return F_81 ( V_171 , V_69 , & V_159 , F_73 ) ;
}
static void F_82 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = F_2 ( V_2 ) ;
if ( V_168 && V_11 && ! F_20 ( V_11 ) )
(* V_168)( V_2 ) ;
F_83 ( V_2 ) ;
}
int F_84 ( void )
{
return F_85 ( & V_172 ) ;
}
int F_86 ( void )
{
return F_87 ( & V_172 ) ;
}
