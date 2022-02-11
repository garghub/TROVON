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
V_7 = F_4 ( F_8 ( V_9 -> V_19 , V_9 -> V_20 ) ,
V_16 ) ;
if ( ! V_7 ) {
V_15 = - V_17 ;
goto V_21;
}
F_9 ( V_7 , V_22 , V_9 ) ;
V_15 = F_10 ( V_13 , sizeof( * V_7 ) , V_7 ) ;
F_11 ( V_7 ) ;
V_21:
F_11 ( V_9 ) ;
if ( V_15 == - V_23 )
F_12 ( 0x15b , L_1 ,
V_13 -> V_18 , V_3 , V_15 ) ;
else if ( V_15 )
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
return - V_24 ;
F_5 ( & V_9 , V_13 -> V_18 ) ;
F_6 ( & V_9 , 1 , V_3 ) ;
if ( V_5 )
F_7 ( & V_9 , 2 , V_5 , sizeof( * V_5 ) ) ;
V_7 = F_4 ( F_8 ( V_9 . V_19 , V_9 . V_20 ) ,
V_16 ) ;
if ( ! V_7 )
return - V_17 ;
F_9 ( V_7 , V_25 , & V_9 ) ;
V_15 = F_10 ( V_13 , sizeof( * V_7 ) , V_7 ) ;
F_11 ( V_7 ) ;
return V_15 ;
}
static int F_14 ( char * V_26 , T_1 V_27 , int V_28 ,
char * V_29 , char * V_30 , char * V_31 , char * V_32 )
{
struct V_8 V_9 ;
struct V_6 * V_7 = NULL ;
int V_15 ;
F_15 ( V_33 , L_3 , V_26 ,
V_28 , V_29 , V_30 , V_31 , V_32 ) ;
F_5 ( & V_9 , V_26 ) ;
if ( V_29 )
F_6 ( & V_9 , 1 , V_29 ) ;
if ( V_30 )
F_6 ( & V_9 , 2 , V_30 ) ;
if ( V_31 )
F_6 ( & V_9 , 3 , V_31 ) ;
if ( V_32 )
F_6 ( & V_9 , 4 , V_32 ) ;
V_7 = F_4 ( F_8 ( V_9 . V_19 , V_9 . V_20 ) ,
V_16 ) ;
if ( ! V_7 )
return - V_17 ;
F_9 ( V_7 , V_28 , & V_9 ) ;
V_7 -> V_34 = V_27 ;
V_15 = F_16 ( V_7 ) ;
F_11 ( V_7 ) ;
return V_15 ;
}
static int F_17 ( char * V_35 , char * type , char * V_36 ,
char * V_29 , char * V_30 , char * V_31 , char * V_32 )
{
int V_15 ;
F_15 ( V_37 , L_4 , V_35 , type ) ;
V_15 = F_14 ( V_35 , 0 , V_38 , type , V_36 , NULL , NULL ) ;
if ( V_15 ) {
F_18 ( L_5 , V_35 , V_15 ) ;
return V_15 ;
}
V_15 = F_14 ( V_35 , 0 , V_39 , V_29 , V_30 , V_31 , V_32 ) ;
if ( V_15 ) {
F_18 ( L_6 , V_35 , V_15 ) ;
F_14 ( V_35 , 0 , V_40 , NULL , NULL , NULL , NULL ) ;
}
return V_15 ;
}
int F_19 ( struct V_1 * V_2 )
{
struct V_41 * V_42 = NULL ;
struct V_10 * V_11 = F_2 ( V_2 ) ;
struct V_12 * V_43 ;
struct V_44 * exp ;
struct V_45 * V_36 ;
T_2 V_46 ;
T_1 V_27 ;
char V_47 [ V_48 ] ;
char * V_49 = NULL , * V_50 = NULL , * V_51 = NULL ;
char * V_52 ;
int V_15 = 0 , V_53 = 0 , V_54 ;
F_3 ( V_11 -> V_55 ) ;
V_52 = V_11 -> V_55 -> V_56 ;
if ( F_20 ( V_52 , & V_27 , & V_52 ) == 0 )
V_53 ++ ;
if ( V_53 == 0 ) {
F_18 ( L_7 ) ;
return - V_23 ;
}
F_21 ( & V_57 ) ;
F_22 ( V_27 , V_47 , sizeof( V_47 ) ) ;
V_49 = F_23 ( V_16 ,
L_8 , V_58 , V_47 ) ;
V_50 = F_23 ( V_16 , L_9 , V_49 , V_53 ) ;
if ( ! V_49 || ! V_50 ) {
V_15 = - V_17 ;
goto V_59;
}
V_51 = V_11 -> V_55 -> V_60 ? V_11 -> V_55 -> V_60 : L_10 ;
V_42 = F_4 ( sizeof( * V_42 ) , V_16 ) ;
if ( ! V_42 ) {
V_15 = - V_17 ;
goto V_59;
}
V_43 = F_24 ( V_49 ) ;
if ( V_43 && ! V_43 -> V_61 ) {
int V_62 ;
V_15 = F_25 ( NULL , V_43 -> V_63 ,
strlen ( V_64 ) , V_64 ,
strlen ( V_51 ) , V_51 , NULL ) ;
if ( V_15 )
goto V_59;
F_26 ( & V_43 -> V_65 . V_66 . V_67 ) ;
if ( F_27 ( V_11 -> V_55 ) ) {
int V_68 ;
int V_69 = sizeof( * V_42 ) ;
T_3 * V_70 = & V_11 -> V_55 -> V_71 ;
V_15 = F_28 ( NULL , V_43 -> V_63 ,
strlen ( V_72 ) , V_72 ,
& V_69 , V_42 ) ;
F_3 ( V_15 == 0 ) ;
V_68 = F_29 ( V_42 , V_73 ) ;
if ( V_68 ^ ! ( * V_70 & V_74 ) ) {
F_30 (
L_11 ,
V_68 ? L_12 : L_13 ) ;
if ( V_68 )
* V_70 &= ~ V_74 ;
else
* V_70 |= V_74 ;
}
}
V_62 = 0 ;
V_62 ++ ;
F_15 ( V_37 , L_14 , V_49 ,
V_62 ) ;
V_15 = F_25 ( NULL , V_43 -> V_63 ,
sizeof( V_75 ) ,
V_75 ,
sizeof( V_62 ) , & V_62 , NULL ) ;
V_15 = 0 ;
goto V_21;
}
F_15 ( V_37 , L_15 , V_49 ) ;
V_53 = 0 ;
V_52 = V_11 -> V_55 -> V_56 ;
while ( F_20 ( V_52 , & V_27 , & V_52 ) == 0 ) {
V_15 = F_14 ( V_49 , V_27 ,
V_76 , V_50 , NULL , NULL , NULL ) ;
if ( ! V_15 )
V_53 ++ ;
if ( * V_52 == ':' )
break;
}
if ( V_53 == 0 ) {
F_18 ( L_7 ) ;
V_15 = - V_23 ;
goto V_59;
}
V_11 -> V_55 -> V_77 = 1 ;
V_36 = F_4 ( sizeof( * V_36 ) , V_16 ) ;
if ( ! V_36 ) {
V_15 = - V_17 ;
goto V_59;
}
F_31 ( V_46 ) ;
F_32 ( V_46 , V_36 ) ;
V_15 = F_17 ( V_49 , V_78 ,
( char * ) V_36 -> V_36 , V_79 ,
V_50 , NULL , NULL ) ;
F_11 ( V_36 ) ;
if ( V_15 )
goto V_59;
V_53 = 1 ;
while ( V_52 && ( ( * V_52 == ':' ||
F_33 ( V_52 , V_80 , & V_52 ) == 0 ) ) ) {
sprintf ( V_50 , L_9 , V_49 , V_53 ) ;
V_54 = 0 ;
while ( F_34 ( V_52 , & V_27 , & V_52 ) == 0 ) {
V_15 = F_14 ( V_49 , V_27 , V_76 , V_50 ,
NULL , NULL , NULL ) ;
if ( ! V_15 )
++ V_54 ;
if ( * V_52 == ':' )
break;
}
if ( V_54 > 0 ) {
V_15 = F_14 ( V_49 , 0 , V_81 ,
V_50 , NULL , NULL , NULL ) ;
if ( ! V_15 )
V_53 ++ ;
} else {
break;
}
}
V_11 -> V_55 -> V_77 = V_53 ;
V_43 = F_24 ( V_49 ) ;
if ( ! V_43 ) {
F_18 ( L_16 , V_49 ) ;
V_15 = - V_82 ;
goto V_59;
}
V_15 = F_25 ( NULL , V_43 -> V_63 ,
strlen ( V_64 ) , V_64 ,
strlen ( V_51 ) , V_51 , NULL ) ;
if ( V_15 )
goto V_59;
F_35 ( & V_43 -> V_65 . V_66 . V_67 , 1 ) ;
V_42 -> V_83 = V_84 | V_85 |
V_86 | V_87 |
V_88 | V_89 ;
#if F_36 ( 3 , 0 , 53 , 0 ) > V_90
V_42 -> V_83 |= V_91 ;
#endif
if ( F_27 ( V_11 -> V_55 ) &&
V_11 -> V_55 -> V_71 & V_74 )
V_42 -> V_83 &= ~ V_87 ;
V_42 -> V_92 = V_90 ;
V_15 = F_37 ( NULL , & exp , V_43 , & V_43 -> V_45 , V_42 , NULL ) ;
if ( V_15 ) {
F_18 ( L_17 , V_15 ) ;
goto V_21;
}
V_43 -> V_65 . V_66 . V_93 = exp ;
V_21:
V_11 -> V_14 = V_43 ;
V_59:
F_38 ( & V_57 ) ;
F_11 ( V_42 ) ;
F_11 ( V_49 ) ;
F_11 ( V_50 ) ;
return V_15 ;
}
static int F_39 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = F_2 ( V_2 ) ;
struct V_12 * V_43 ;
char * V_50 = NULL , * V_52 = NULL ;
int V_53 , V_15 = 0 , V_94 = 0 ;
if ( ! V_11 )
return - V_24 ;
V_43 = V_11 -> V_14 ;
if ( ! V_43 )
return - V_24 ;
V_11 -> V_14 = NULL ;
F_21 ( & V_57 ) ;
F_3 ( F_40 ( & V_43 -> V_65 . V_66 . V_67 ) > 0 ) ;
if ( ! F_41 ( & V_43 -> V_65 . V_66 . V_67 ) ) {
F_15 ( V_37 , L_18 ,
F_40 ( & V_43 -> V_65 . V_66 . V_67 ) ) ;
V_15 = - V_95 ;
goto V_21;
}
V_43 -> V_96 = 1 ;
if ( V_43 -> V_65 . V_66 . V_93 ) {
V_15 = F_42 ( V_43 -> V_65 . V_66 . V_93 ) ;
if ( V_15 )
F_15 ( V_37 , L_19 , V_15 ) ;
}
V_94 = strlen ( V_43 -> V_18 ) + 6 ;
V_50 = F_4 ( V_94 , V_16 ) ;
if ( V_50 ) {
strcpy ( V_50 , V_43 -> V_18 ) ;
V_52 = V_50 + strlen ( V_50 ) ;
}
V_15 = F_43 ( V_43 ) ;
if ( V_15 )
goto V_21;
if ( ! V_50 ) {
V_15 = - V_17 ;
goto V_21;
}
for ( V_53 = 0 ; V_53 < V_11 -> V_55 -> V_77 ; V_53 ++ ) {
sprintf ( V_52 , L_20 , V_53 ) ;
V_15 = F_14 ( V_58 , 0 , V_97 ,
V_50 , NULL , NULL , NULL ) ;
if ( V_15 )
F_18 ( L_21 ,
V_50 , V_15 ) ;
}
V_21:
F_11 ( V_50 ) ;
F_38 ( & V_57 ) ;
return V_15 ;
}
static struct V_10 * F_44 ( struct V_1 * V_2 )
{
struct V_10 * V_11 ;
V_11 = F_4 ( sizeof( * V_11 ) , V_16 ) ;
if ( ! V_11 )
return NULL ;
V_11 -> V_55 = F_4 ( sizeof( * V_11 -> V_55 ) , V_16 ) ;
if ( ! V_11 -> V_55 ) {
F_11 ( V_11 ) ;
return NULL ;
}
V_11 -> V_55 -> V_98 = 0 ;
V_11 -> V_55 -> V_99 = 0 ;
V_11 -> V_55 -> V_100 = 0 ;
F_45 ( V_2 ) = V_11 ;
F_35 ( & V_11 -> V_101 , 1 ) ;
V_11 -> V_102 = V_103 ;
return V_11 ;
}
static int F_46 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = F_2 ( V_2 ) ;
F_15 ( V_37 , L_22 , V_11 ) ;
F_3 ( F_40 ( & V_11 -> V_101 ) == 0 ) ;
if ( V_11 -> V_55 ) {
F_11 ( V_11 -> V_55 -> V_56 ) ;
F_11 ( V_11 -> V_55 -> V_104 ) ;
F_11 ( V_11 -> V_55 -> V_60 ) ;
F_11 ( V_11 -> V_55 -> V_105 ) ;
if ( V_11 -> V_55 -> V_98 )
F_11 ( V_11 -> V_55 -> V_106 ) ;
F_11 ( V_11 -> V_55 -> V_107 ) ;
F_11 ( V_11 -> V_55 -> V_108 ) ;
F_11 ( V_11 -> V_55 -> V_109 ) ;
F_11 ( V_11 -> V_55 ) ;
}
F_3 ( ! V_11 -> V_110 ) ;
F_11 ( V_11 ) ;
F_45 ( V_2 ) = NULL ;
return 0 ;
}
static int F_47 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = F_2 ( V_2 ) ;
F_15 ( V_37 , L_23 , V_2 , F_40 ( & V_11 -> V_101 ) ) ;
if ( F_41 ( & V_11 -> V_101 ) ) {
F_46 ( V_2 ) ;
return 1 ;
}
return 0 ;
}
static int F_48 ( const char * V_111 , char * V_112 ,
const char * * V_113 )
{
const char * V_114 ;
V_114 = V_111 + F_49 ( V_111 , 8 ) ;
for (; V_114 > V_111 && * V_114 != '-' && * V_114 != ':' ; V_114 -- )
;
if ( V_114 == V_111 )
return - V_23 ;
if ( V_112 ) {
strncpy ( V_112 , V_111 , V_114 - V_111 ) ;
V_112 [ V_114 - V_111 ] = '\0' ;
}
if ( V_113 )
* V_113 = V_114 ;
return 0 ;
}
static int F_50 ( const char * V_111 , T_3 * V_115 ,
const char * * V_113 )
{
unsigned long V_116 ;
int V_15 ;
const char * V_114 ;
V_15 = F_48 ( V_111 , NULL , & V_114 ) ;
if ( V_15 != 0 )
return V_15 ;
V_114 ++ ;
if ( strncmp ( V_114 , L_24 , 3 ) == 0 )
V_15 = V_117 ;
else if ( strncmp ( V_114 , L_25 , 3 ) == 0 )
V_15 = V_118 ;
else
return - V_23 ;
V_114 += 3 ;
if ( strncmp ( V_114 , L_26 , 3 ) == 0 ) {
if ( V_113 )
* V_113 = V_114 + 3 ;
return V_15 | V_119 ;
}
V_116 = F_51 ( V_114 , ( char * * ) V_113 , 16 ) ;
if ( V_115 )
* V_115 = V_116 ;
if ( V_113 && strncmp ( V_120 , * V_113 + 1 ,
sizeof( V_120 ) - 1 ) == 0 )
* V_113 += sizeof( V_120 ) ;
return V_15 ;
}
int F_52 ( struct V_1 * V_2 )
{
int V_15 ;
F_15 ( V_37 , L_27 , V_2 ) ;
V_15 = F_39 ( V_2 ) ;
if ( V_15 && ( V_15 != - V_24 ) ) {
if ( V_15 != - V_95 ) {
F_18 ( L_28 , V_15 ) ;
return V_15 ;
}
F_15 ( V_37 , L_29 ) ;
}
F_47 ( V_2 ) ;
return V_15 ;
}
static void F_53 ( struct V_121 * V_122 )
{
int V_53 ;
F_54 ( V_37 , L_30 ) ;
if ( F_27 ( V_122 ) )
F_54 ( V_37 , L_31 , V_122 -> V_104 ) ;
F_54 ( V_37 , L_32 , V_122 -> V_56 ) ;
F_54 ( V_37 , L_33 , V_122 -> V_71 ) ;
if ( V_122 -> V_105 )
F_54 ( V_37 , L_34 , V_122 -> V_105 ) ;
if ( V_122 -> V_99 )
F_54 ( V_37 , L_35 ,
V_122 -> V_99 ) ;
if ( V_122 -> V_100 )
F_54 ( V_37 , L_36 ,
V_122 -> V_100 ) ;
for ( V_53 = 0 ; V_53 < V_122 -> V_98 ; V_53 ++ ) {
F_54 ( V_37 , L_37 , V_53 ,
V_122 -> V_106 [ V_53 ] ) ;
}
}
int F_55 ( struct V_1 * V_2 , char * V_111 )
{
struct V_10 * V_11 = F_2 ( V_2 ) ;
struct V_121 * V_122 = V_11 -> V_55 ;
T_3 V_116 ;
int V_53 , V_15 ;
V_15 = F_50 ( V_111 , & V_116 , NULL ) ;
if ( V_15 != V_118 )
return 0 ;
F_15 ( V_37 , L_38 , V_111 ,
V_116 , V_122 -> V_98 , V_122 -> V_56 ) ;
for ( V_53 = 0 ; V_53 < V_122 -> V_98 ; V_53 ++ ) {
if ( V_116 == V_122 -> V_106 [ V_53 ] ) {
F_56 ( L_39 , V_111 ) ;
return 1 ;
}
}
return 0 ;
}
static int F_57 ( struct V_121 * V_122 , const char * V_52 )
{
const char * V_29 = V_52 , * V_30 ;
T_3 V_116 = 0 , * V_123 ;
int V_15 = 0 , V_124 ;
V_124 = strlen ( V_52 ) / 8 + 1 ;
V_123 = F_58 ( V_124 , sizeof( V_116 ) , V_16 ) ;
if ( ! V_123 )
return - V_17 ;
while ( * V_29 && * V_29 != ' ' && * V_29 != ',' ) {
V_29 ++ ;
V_15 = F_50 ( V_29 , & V_116 , & V_30 ) ;
if ( V_15 < 0 ) {
F_18 ( L_40 ,
V_29 , V_15 ) ;
break;
}
if ( V_15 == V_118 )
V_123 [ V_122 -> V_98 ++ ] = V_116 ;
else
F_15 ( V_37 , L_41 ,
( V_125 ) ( V_30 - V_29 ) , V_29 , V_15 ) ;
V_29 = V_30 ;
if ( V_122 -> V_98 >= V_124 )
break;
}
if ( V_15 >= 0 )
V_15 = 0 ;
if ( V_122 -> V_98 ) {
V_122 -> V_106 = F_58 ( V_122 -> V_98 ,
sizeof( V_116 ) , V_16 ) ;
if ( V_122 -> V_106 ) {
memcpy ( V_122 -> V_106 , V_123 ,
sizeof( V_116 ) * V_122 -> V_98 ) ;
} else {
V_15 = - V_17 ;
V_122 -> V_98 = 0 ;
}
}
F_11 ( V_123 ) ;
return V_15 ;
}
static int F_59 ( struct V_121 * V_122 , char * V_52 )
{
char * V_126 ;
int V_127 ;
F_11 ( V_122 -> V_60 ) ;
V_122 -> V_60 = NULL ;
V_126 = strchr ( V_52 , ',' ) ;
if ( ! V_126 )
V_127 = strlen ( V_52 ) ;
else
V_127 = V_126 - V_52 ;
V_122 -> V_60 = F_4 ( V_127 + 1 , V_16 ) ;
if ( ! V_122 -> V_60 )
return - V_17 ;
memcpy ( V_122 -> V_60 , V_52 , V_127 ) ;
V_122 -> V_60 [ V_127 ] = '\0' ;
return 0 ;
}
static int F_60 ( char * * V_128 , char * V_52 )
{
char * V_126 ;
int V_127 ;
if ( ! V_128 || ! V_52 )
return - V_23 ;
F_11 ( * V_128 ) ;
* V_128 = NULL ;
V_126 = strchr ( V_52 , ',' ) ;
if ( ! V_126 )
V_127 = strlen ( V_52 ) ;
else
V_127 = V_126 - V_52 ;
* V_128 = F_4 ( V_127 + 1 , V_16 ) ;
if ( ! * V_128 )
return - V_17 ;
memcpy ( * V_128 , V_52 , V_127 ) ;
( * V_128 ) [ V_127 ] = '\0' ;
return 0 ;
}
static int F_61 ( struct V_121 * V_122 , char * * V_52 )
{
T_1 V_27 ;
char * V_126 = * V_52 ;
char * V_129 ;
int V_127 ;
int V_130 = 0 ;
while ( F_34 ( V_126 , & V_27 , & V_126 ) == 0 )
;
V_127 = V_126 - * V_52 ;
if ( V_127 == 0 ) {
F_12 ( 0x159 , L_42 , * V_52 ) ;
return - V_23 ;
}
if ( V_122 -> V_107 )
V_130 = strlen ( V_122 -> V_107 ) + 1 ;
V_129 = F_4 ( V_130 + V_127 + 1 , V_16 ) ;
if ( ! V_129 )
return - V_17 ;
if ( V_122 -> V_107 ) {
memcpy ( V_129 , V_122 -> V_107 , V_130 ) ;
V_129 [ V_130 - 1 ] = ':' ;
F_11 ( V_122 -> V_107 ) ;
}
memcpy ( V_129 + V_130 , * V_52 , V_127 ) ;
V_129 [ V_130 + V_127 ] = '\0' ;
V_122 -> V_107 = V_129 ;
* V_52 = V_126 ;
return 0 ;
}
static int F_62 ( char * V_131 , struct V_121 * V_122 )
{
char * V_29 , * V_30 , * V_132 = NULL ;
struct V_121 * V_133 = (struct V_121 * ) V_131 ;
int V_15 = 0 ;
F_3 ( V_122 ) ;
if ( ! V_131 ) {
F_12 ( 0x162 , L_43 ) ;
return - V_23 ;
}
if ( ( V_133 -> V_134 & 0xffffff00 ) == ( V_135 & 0xffffff00 ) ) {
F_12 ( 0x163 , L_44 ,
V_136 ) ;
return - V_23 ;
}
V_122 -> V_134 = V_135 ;
V_122 -> V_109 = F_4 ( V_137 , V_16 ) ;
if ( ! V_122 -> V_109 )
return - V_17 ;
V_122 -> V_109 [ 0 ] = '\0' ;
V_29 = V_131 ;
while ( * V_29 ) {
int V_138 = 0 ;
int V_139 = V_140 ;
char * V_31 ;
while ( * V_29 == ' ' || * V_29 == ',' )
V_29 ++ ;
V_31 = V_29 ;
if ( strncmp ( V_29 , L_45 , 11 ) == 0 ) {
V_122 -> V_71 |= V_141 ;
V_138 ++ ;
} else if ( strncmp ( V_29 , L_46 , 19 ) == 0 ) {
V_122 -> V_99 = F_63 ( int ,
F_51 ( V_29 + 19 , NULL , 10 ) , V_139 ) ;
V_138 ++ ;
} else if ( strncmp ( V_29 , L_47 , 19 ) == 0 ) {
V_122 -> V_100 = F_63 ( int ,
F_51 ( V_29 + 19 , NULL , 10 ) , V_139 ) ;
V_138 ++ ;
} else if ( strncmp ( V_29 , L_48 , 4 ) == 0 ) {
V_122 -> V_71 |= V_74 ;
V_138 ++ ;
} else if ( strncmp ( V_29 , L_49 , 5 ) == 0 ) {
V_122 -> V_71 |= V_142 ;
V_138 ++ ;
} else if ( strncmp ( V_29 , L_50 , 5 ) == 0 ) {
V_122 -> V_71 |= V_143 ;
V_138 ++ ;
} else if ( strncmp ( V_29 , L_51 , 7 ) == 0 ) {
V_122 -> V_71 |= V_144 ;
V_138 ++ ;
} else if ( strncmp ( V_29 , V_80 ,
sizeof( V_80 ) - 1 ) == 0 ) {
V_30 = V_29 + sizeof( V_80 ) - 1 ;
V_15 = F_61 ( V_122 , & V_30 ) ;
if ( V_15 )
goto V_145;
V_138 ++ ;
} else if ( strncmp ( V_29 , L_52 , 9 ) == 0 ) {
V_122 -> V_71 |= V_146 ;
V_138 ++ ;
} else if ( strncmp ( V_29 , L_53 , 6 ) == 0 ) {
V_122 -> V_71 |= V_147 ;
V_138 ++ ;
} else if ( strncmp ( V_29 , L_54 , 6 ) == 0 ) {
V_122 -> V_71 |= V_148 ;
V_138 ++ ;
} else if ( strncmp ( V_29 , L_55 , 10 ) == 0 ) {
V_122 -> V_71 |= V_149 ;
V_138 ++ ;
} else if ( strncmp ( V_29 , L_56 , 7 ) == 0 ) {
V_15 = F_59 ( V_122 , V_29 + 7 ) ;
if ( V_15 )
goto V_145;
V_31 = V_30 ;
V_138 ++ ;
} else if ( strncmp ( V_29 , L_57 , 8 ) == 0 ) {
V_15 = F_57 ( V_122 , V_29 + 7 ) ;
if ( V_15 )
goto V_145;
V_138 ++ ;
} else if ( strncmp ( V_29 , L_58 , 3 ) == 0 ) {
V_122 -> V_71 |= V_150 ;
V_138 ++ ;
} else if ( strncmp ( V_29 , L_59 , 7 ) == 0 ) {
V_15 = F_60 ( & V_122 -> V_104 , V_29 + 7 ) ;
if ( V_15 )
goto V_145;
V_138 ++ ;
} else if ( strncmp ( V_29 , L_60 , 6 ) == 0 ) {
T_4 V_127 , V_151 ;
char * V_126 = strchr ( V_29 + 6 , ',' ) ;
if ( ! V_126 ) {
V_127 = strlen ( V_29 ) ;
} else {
T_1 V_27 ;
char * V_152 = V_126 + 1 ;
int V_153 = 1 ;
while ( ! F_34 ( V_152 , & V_27 ,
& V_152 ) ) {
V_153 = 0 ;
}
V_127 = V_152 - V_29 - V_153 ;
}
V_127 -= 6 ;
V_151 = strlen ( V_122 -> V_109 ) ;
if ( V_151 + V_127 + 1 >= V_137 )
return - V_154 ;
strncat ( V_122 -> V_109 , V_29 + 6 , V_127 ) ;
V_122 -> V_109 [ V_151 + V_127 ] = '\0' ;
F_64 ( V_122 -> V_109 , L_61 , V_137 ) ;
V_31 = V_29 + 6 + V_127 ;
V_138 ++ ;
} else if ( strncmp ( V_29 , L_62 , 4 ) == 0 ) {
V_15 = F_60 ( & V_122 -> V_108 , V_29 + 4 ) ;
if ( V_15 )
goto V_145;
V_138 ++ ;
}
else if ( strncmp ( V_29 , L_63 , 7 ) == 0 ) {
V_132 = V_29 + 7 ;
* V_29 = '\0' ;
break;
}
V_30 = strchr ( V_29 , ',' ) ;
if ( ! V_30 ) {
if ( V_138 )
* V_29 = '\0' ;
break;
}
V_30 ++ ;
if ( V_138 )
memmove ( V_29 , V_30 , strlen ( V_30 ) + 1 ) ;
else
V_29 = V_30 ;
}
if ( ! V_132 ) {
F_12 ( 0x164 , L_64 ) ;
goto V_145;
}
V_29 = strstr ( V_132 , L_65 ) ;
if ( V_29 ) {
++ V_29 ;
V_122 -> V_71 |= V_155 ;
while ( * ++ V_29 == '/' )
;
V_122 -> V_104 = F_23 ( V_16 , L_66 , V_29 ) ;
if ( ! V_122 -> V_104 )
return - V_17 ;
}
V_122 -> V_56 = F_4 ( strlen ( V_132 ) + 1 , V_16 ) ;
if ( ! V_122 -> V_56 )
return - V_17 ;
strcpy ( V_122 -> V_56 , V_132 ) ;
V_29 = V_131 + strlen ( V_131 ) - 1 ;
while ( V_29 >= V_131 && ( * V_29 == ',' || * V_29 == ' ' ) )
* V_29 -- = 0 ;
if ( * V_131 != 0 ) {
V_122 -> V_105 = F_4 ( strlen ( V_131 ) + 1 , V_16 ) ;
if ( ! V_122 -> V_105 )
return - V_17 ;
strcpy ( V_122 -> V_105 , V_131 ) ;
}
F_53 ( V_122 ) ;
V_122 -> V_134 = V_135 ;
return V_15 ;
V_145:
F_18 ( L_67 , V_131 ) ;
return - V_23 ;
}
static int F_65 ( struct V_1 * V_2 , void * V_42 , int V_156 )
{
struct V_121 * V_122 ;
struct V_157 * V_158 = V_42 ;
struct V_10 * V_11 ;
int V_15 ;
F_15 ( V_37 | V_159 , L_68 , V_2 ) ;
V_11 = F_44 ( V_2 ) ;
if ( ! V_11 )
return - V_17 ;
V_122 = V_11 -> V_55 ;
F_66 () ;
F_67 () ;
if ( F_62 ( ( V_158 -> V_160 ) , V_122 ) ) {
F_47 ( V_2 ) ;
V_15 = - V_23 ;
goto V_21;
}
if ( F_27 ( V_122 ) ) {
F_15 ( V_37 , L_69 , V_122 -> V_104 ) ;
if ( ! V_161 )
F_68 ( L_70 ) ;
if ( ! V_161 ) {
F_12 ( 0x165 , L_71 ) ;
F_47 ( V_2 ) ;
V_15 = - V_162 ;
} else {
V_15 = F_19 ( V_2 ) ;
if ( V_15 ) {
F_52 ( V_2 ) ;
goto V_21;
}
V_15 = (* V_161)( V_2 , V_158 -> V_163 ) ;
}
} else {
F_18 ( L_72 ) ;
V_15 = - V_23 ;
}
goto V_21;
V_21:
if ( V_15 ) {
F_18 ( L_73 ,
F_2 ( V_2 ) ? V_122 -> V_56 : L_10 , V_15 ) ;
} else {
F_15 ( V_164 , L_74 ,
V_122 -> V_56 ) ;
}
F_69 () ;
return V_15 ;
}
void F_70 ( int (* F_71)( struct V_1 * V_2 ,
struct V_165 * V_166 ) )
{
V_161 = F_71 ;
}
void F_72 ( void (* F_71)( struct V_1 * V_2 ) )
{
V_167 = F_71 ;
}
static struct V_168 * F_73 ( struct V_169 * V_170 , int V_70 ,
const char * V_132 , void * V_42 )
{
struct V_157 V_158 = {
. V_160 = V_42 ,
. V_163 = NULL
} ;
return F_74 ( V_170 , V_70 , & V_158 , F_65 ) ;
}
static void F_75 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = F_2 ( V_2 ) ;
if ( V_167 && V_11 )
(* V_167)( V_2 ) ;
F_76 ( V_2 ) ;
}
int F_77 ( void )
{
return F_78 ( & V_171 ) ;
}
int F_79 ( void )
{
return F_80 ( & V_171 ) ;
}
