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
& V_66 , V_39 ) ;
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
if ( ! V_15 )
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
V_15 = F_14 ( V_46 , V_24 , V_74 , V_47 ,
NULL , NULL , NULL ) ;
if ( ! V_15 )
++ V_51 ;
if ( * V_49 == ':' )
break;
}
if ( V_51 > 0 ) {
V_15 = F_14 ( V_46 , 0 , V_79 ,
V_47 , NULL , NULL , NULL ) ;
if ( ! V_15 )
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
V_86 | V_87 ;
#if F_36 ( 3 , 0 , 53 , 0 ) > V_88
V_39 -> V_81 |= V_89 ;
#endif
if ( F_27 ( V_11 -> V_52 ) &&
V_11 -> V_52 -> V_68 & V_71 )
V_39 -> V_81 &= ~ V_85 ;
V_39 -> V_90 = V_88 ;
V_15 = F_37 ( NULL , & exp , V_40 , & V_40 -> V_42 , V_39 , NULL ) ;
if ( V_15 ) {
F_18 ( L_17 , V_15 ) ;
goto V_73;
}
V_40 -> V_62 . V_63 . V_91 = exp ;
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
int V_50 , V_15 = 0 , V_92 = 0 ;
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
V_15 = - V_93 ;
goto V_73;
}
V_40 -> V_94 = 1 ;
if ( V_40 -> V_62 . V_63 . V_91 ) {
V_15 = F_42 ( V_40 -> V_62 . V_63 . V_91 ) ;
if ( V_15 )
F_15 ( V_34 , L_19 , V_15 ) ;
}
V_92 = strlen ( V_40 -> V_18 ) + 6 ;
V_47 = F_4 ( V_92 , V_16 ) ;
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
V_15 = F_14 ( V_55 , 0 , V_95 ,
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
V_11 -> V_52 -> V_96 = 0 ;
V_11 -> V_52 -> V_97 = 0 ;
V_11 -> V_52 -> V_98 = 0 ;
F_45 ( V_2 ) = V_11 ;
F_35 ( & V_11 -> V_99 , 1 ) ;
V_11 -> V_100 = V_101 ;
return V_11 ;
}
static int F_46 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = F_2 ( V_2 ) ;
F_15 ( V_34 , L_22 , V_11 ) ;
F_3 ( F_40 ( & V_11 -> V_99 ) == 0 ) ;
if ( V_11 -> V_52 ) {
F_11 ( V_11 -> V_52 -> V_53 ) ;
F_11 ( V_11 -> V_52 -> V_102 ) ;
F_11 ( V_11 -> V_52 -> V_57 ) ;
F_11 ( V_11 -> V_52 -> V_103 ) ;
if ( V_11 -> V_52 -> V_96 )
F_11 ( V_11 -> V_52 -> V_104 ) ;
F_11 ( V_11 -> V_52 -> V_105 ) ;
F_11 ( V_11 -> V_52 -> V_106 ) ;
F_11 ( V_11 -> V_52 -> V_107 ) ;
F_11 ( V_11 -> V_52 ) ;
}
F_3 ( ! V_11 -> V_108 ) ;
F_11 ( V_11 ) ;
F_45 ( V_2 ) = NULL ;
return 0 ;
}
static int F_47 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = F_2 ( V_2 ) ;
F_15 ( V_34 , L_23 , V_2 , F_40 ( & V_11 -> V_99 ) ) ;
if ( F_41 ( & V_11 -> V_99 ) ) {
F_46 ( V_2 ) ;
return 1 ;
}
return 0 ;
}
static int F_48 ( const char * V_109 , char * V_110 ,
const char * * V_111 )
{
const char * V_112 ;
V_112 = V_109 + F_49 ( V_109 , 8 ) ;
for (; V_112 > V_109 && * V_112 != '-' && * V_112 != ':' ; V_112 -- )
;
if ( V_112 == V_109 )
return - V_20 ;
if ( V_110 ) {
strncpy ( V_110 , V_109 , V_112 - V_109 ) ;
V_110 [ V_112 - V_109 ] = '\0' ;
}
if ( V_111 )
* V_111 = V_112 ;
return 0 ;
}
static int F_50 ( const char * V_109 , T_3 * V_113 ,
const char * * V_111 )
{
unsigned long V_114 ;
int V_15 ;
const char * V_112 ;
V_15 = F_48 ( V_109 , NULL , & V_112 ) ;
if ( V_15 != 0 )
return V_15 ;
V_112 ++ ;
if ( strncmp ( V_112 , L_24 , 3 ) == 0 )
V_15 = V_115 ;
else if ( strncmp ( V_112 , L_25 , 3 ) == 0 )
V_15 = V_116 ;
else
return - V_20 ;
V_112 += 3 ;
if ( strncmp ( V_112 , L_26 , 3 ) == 0 ) {
if ( V_111 )
* V_111 = V_112 + 3 ;
return V_15 | V_117 ;
}
V_114 = F_51 ( V_112 , ( char * * ) V_111 , 16 ) ;
if ( V_113 )
* V_113 = V_114 ;
if ( V_111 && strncmp ( V_118 , * V_111 + 1 ,
sizeof( V_118 ) - 1 ) == 0 )
* V_111 += sizeof( V_118 ) ;
return V_15 ;
}
int F_52 ( struct V_1 * V_2 )
{
int V_15 ;
F_15 ( V_34 , L_27 , V_2 ) ;
V_15 = F_39 ( V_2 ) ;
if ( V_15 && ( V_15 != - V_21 ) ) {
if ( V_15 != - V_93 ) {
F_18 ( L_28 , V_15 ) ;
return V_15 ;
}
F_15 ( V_34 , L_29 ) ;
}
F_47 ( V_2 ) ;
return V_15 ;
}
static void F_53 ( struct V_119 * V_120 )
{
int V_50 ;
F_54 ( V_34 , L_30 ) ;
if ( F_27 ( V_120 ) )
F_54 ( V_34 , L_31 , V_120 -> V_102 ) ;
F_54 ( V_34 , L_32 , V_120 -> V_53 ) ;
F_54 ( V_34 , L_33 , V_120 -> V_68 ) ;
if ( V_120 -> V_103 )
F_54 ( V_34 , L_34 , V_120 -> V_103 ) ;
if ( V_120 -> V_97 )
F_54 ( V_34 , L_35 ,
V_120 -> V_97 ) ;
if ( V_120 -> V_98 )
F_54 ( V_34 , L_36 ,
V_120 -> V_98 ) ;
for ( V_50 = 0 ; V_50 < V_120 -> V_96 ; V_50 ++ ) {
F_54 ( V_34 , L_37 , V_50 ,
V_120 -> V_104 [ V_50 ] ) ;
}
}
int F_55 ( struct V_1 * V_2 , char * V_109 )
{
struct V_10 * V_11 = F_2 ( V_2 ) ;
struct V_119 * V_120 = V_11 -> V_52 ;
T_3 V_114 ;
int V_50 , V_15 ;
V_15 = F_50 ( V_109 , & V_114 , NULL ) ;
if ( V_15 != V_116 )
return 0 ;
F_15 ( V_34 , L_38 , V_109 ,
V_114 , V_120 -> V_96 , V_120 -> V_53 ) ;
for ( V_50 = 0 ; V_50 < V_120 -> V_96 ; V_50 ++ ) {
if ( V_114 == V_120 -> V_104 [ V_50 ] ) {
F_56 ( L_39 , V_109 ) ;
return 1 ;
}
}
return 0 ;
}
static int F_57 ( struct V_119 * V_120 , const char * V_49 )
{
const char * V_26 = V_49 , * V_27 ;
T_3 V_114 = 0 , * V_121 ;
int V_15 = 0 , V_122 ;
V_122 = strlen ( V_49 ) / 8 + 1 ;
V_121 = F_58 ( V_122 , sizeof( V_114 ) , V_16 ) ;
if ( ! V_121 )
return - V_17 ;
while ( * V_26 && * V_26 != ' ' && * V_26 != ',' ) {
V_26 ++ ;
V_15 = F_50 ( V_26 , & V_114 , & V_27 ) ;
if ( V_15 < 0 ) {
F_18 ( L_40 ,
V_26 , V_15 ) ;
break;
}
if ( V_15 == V_116 )
V_121 [ V_120 -> V_96 ++ ] = V_114 ;
else
F_15 ( V_34 , L_41 ,
( V_123 ) ( V_27 - V_26 ) , V_26 , V_15 ) ;
V_26 = V_27 ;
if ( V_120 -> V_96 >= V_122 )
break;
}
if ( V_15 >= 0 )
V_15 = 0 ;
if ( V_120 -> V_96 ) {
V_120 -> V_104 = F_58 ( V_120 -> V_96 ,
sizeof( V_114 ) , V_16 ) ;
if ( V_120 -> V_104 ) {
memcpy ( V_120 -> V_104 , V_121 ,
sizeof( V_114 ) * V_120 -> V_96 ) ;
} else {
V_15 = - V_17 ;
V_120 -> V_96 = 0 ;
}
}
F_11 ( V_121 ) ;
return V_15 ;
}
static int F_59 ( struct V_119 * V_120 , char * V_49 )
{
char * V_124 ;
int V_125 ;
F_11 ( V_120 -> V_57 ) ;
V_120 -> V_57 = NULL ;
V_124 = strchr ( V_49 , ',' ) ;
if ( ! V_124 )
V_125 = strlen ( V_49 ) ;
else
V_125 = V_124 - V_49 ;
V_120 -> V_57 = F_4 ( V_125 + 1 , V_16 ) ;
if ( ! V_120 -> V_57 )
return - V_17 ;
memcpy ( V_120 -> V_57 , V_49 , V_125 ) ;
V_120 -> V_57 [ V_125 ] = '\0' ;
return 0 ;
}
static int F_60 ( char * * V_126 , char * V_49 )
{
char * V_124 ;
int V_125 ;
if ( ! V_126 || ! V_49 )
return - V_20 ;
F_11 ( * V_126 ) ;
* V_126 = NULL ;
V_124 = strchr ( V_49 , ',' ) ;
if ( ! V_124 )
V_125 = strlen ( V_49 ) ;
else
V_125 = V_124 - V_49 ;
* V_126 = F_4 ( V_125 + 1 , V_16 ) ;
if ( ! * V_126 )
return - V_17 ;
memcpy ( * V_126 , V_49 , V_125 ) ;
( * V_126 ) [ V_125 ] = '\0' ;
return 0 ;
}
static int F_61 ( struct V_119 * V_120 , char * * V_49 )
{
T_1 V_24 ;
char * V_124 = * V_49 ;
char * V_127 ;
int V_125 ;
int V_128 = 0 ;
while ( F_34 ( V_124 , & V_24 , & V_124 ) == 0 )
;
V_125 = V_124 - * V_49 ;
if ( V_125 == 0 ) {
F_12 ( 0x159 , L_42 , * V_49 ) ;
return - V_20 ;
}
if ( V_120 -> V_105 )
V_128 = strlen ( V_120 -> V_105 ) + 1 ;
V_127 = F_4 ( V_128 + V_125 + 1 , V_16 ) ;
if ( ! V_127 )
return - V_17 ;
if ( V_120 -> V_105 ) {
memcpy ( V_127 , V_120 -> V_105 , V_128 ) ;
V_127 [ V_128 - 1 ] = ':' ;
F_11 ( V_120 -> V_105 ) ;
}
memcpy ( V_127 + V_128 , * V_49 , V_125 ) ;
V_127 [ V_128 + V_125 ] = '\0' ;
V_120 -> V_105 = V_127 ;
* V_49 = V_124 ;
return 0 ;
}
static int F_62 ( char * V_129 , struct V_119 * V_120 )
{
char * V_26 , * V_27 , * V_28 , * V_130 = NULL ;
struct V_119 * V_131 = (struct V_119 * ) V_129 ;
int V_15 = 0 ;
F_3 ( V_120 ) ;
if ( ! V_129 ) {
F_12 ( 0x162 , L_43 ) ;
return - V_20 ;
}
if ( ( V_131 -> V_132 & 0xffffff00 ) == ( V_133 & 0xffffff00 ) ) {
F_12 ( 0x163 , L_44 ,
V_134 ) ;
return - V_20 ;
}
V_120 -> V_132 = V_133 ;
V_120 -> V_107 = F_4 ( V_135 , V_16 ) ;
if ( ! V_120 -> V_107 )
return - V_17 ;
V_120 -> V_107 [ 0 ] = '\0' ;
V_26 = V_129 ;
while ( * V_26 ) {
int V_136 = 0 ;
int V_137 = V_138 ;
while ( * V_26 == ' ' || * V_26 == ',' )
V_26 ++ ;
V_28 = V_26 ;
if ( strncmp ( V_26 , L_45 , 11 ) == 0 ) {
V_120 -> V_68 |= V_139 ;
V_136 ++ ;
} else if ( strncmp ( V_26 , L_46 , 19 ) == 0 ) {
V_120 -> V_97 = F_63 ( int ,
F_51 ( V_26 + 19 , NULL , 10 ) , V_137 ) ;
V_136 ++ ;
} else if ( strncmp ( V_26 , L_47 , 19 ) == 0 ) {
V_120 -> V_98 = F_63 ( int ,
F_51 ( V_26 + 19 , NULL , 10 ) , V_137 ) ;
V_136 ++ ;
} else if ( strncmp ( V_26 , L_48 , 4 ) == 0 ) {
V_120 -> V_68 |= V_71 ;
V_136 ++ ;
} else if ( strncmp ( V_26 , L_49 , 5 ) == 0 ) {
V_120 -> V_68 |= V_140 ;
V_136 ++ ;
} else if ( strncmp ( V_26 , L_50 , 5 ) == 0 ) {
V_120 -> V_68 |= V_141 ;
V_136 ++ ;
} else if ( strncmp ( V_26 , L_51 , 7 ) == 0 ) {
V_120 -> V_68 |= V_142 ;
V_136 ++ ;
} else if ( strncmp ( V_26 , V_78 ,
sizeof( V_78 ) - 1 ) == 0 ) {
V_27 = V_26 + sizeof( V_78 ) - 1 ;
V_15 = F_61 ( V_120 , & V_27 ) ;
if ( V_15 )
goto V_143;
V_136 ++ ;
} else if ( strncmp ( V_26 , L_52 , 9 ) == 0 ) {
V_120 -> V_68 |= V_144 ;
V_136 ++ ;
} else if ( strncmp ( V_26 , L_53 , 6 ) == 0 ) {
V_120 -> V_68 |= V_145 ;
V_136 ++ ;
} else if ( strncmp ( V_26 , L_54 , 6 ) == 0 ) {
V_120 -> V_68 |= V_146 ;
V_136 ++ ;
} else if ( strncmp ( V_26 , L_55 , 10 ) == 0 ) {
V_120 -> V_68 |= V_147 ;
V_136 ++ ;
} else if ( strncmp ( V_26 , L_56 , 7 ) == 0 ) {
V_15 = F_59 ( V_120 , V_26 + 7 ) ;
if ( V_15 )
goto V_143;
V_28 = V_27 ;
V_136 ++ ;
} else if ( strncmp ( V_26 , L_57 , 8 ) == 0 ) {
V_15 = F_57 ( V_120 , V_26 + 7 ) ;
if ( V_15 )
goto V_143;
V_136 ++ ;
} else if ( strncmp ( V_26 , L_58 , 3 ) == 0 ) {
V_120 -> V_68 |= V_148 ;
V_136 ++ ;
} else if ( strncmp ( V_26 , L_59 , 7 ) == 0 ) {
V_15 = F_60 ( & V_120 -> V_102 , V_26 + 7 ) ;
if ( V_15 )
goto V_143;
V_136 ++ ;
} else if ( strncmp ( V_26 , L_60 , 6 ) == 0 ) {
T_4 V_125 , V_149 ;
char * V_124 = strchr ( V_26 + 6 , ',' ) ;
if ( ! V_124 ) {
V_125 = strlen ( V_26 ) ;
} else {
T_1 V_24 ;
char * V_150 = V_124 + 1 ;
int V_151 = 1 ;
while ( ! F_34 ( V_150 , & V_24 ,
& V_150 ) ) {
V_151 = 0 ;
}
V_125 = V_150 - V_26 - V_151 ;
}
V_125 -= 6 ;
V_149 = strlen ( V_120 -> V_107 ) ;
if ( V_149 + V_125 + 1 >= V_135 )
return - V_152 ;
strncat ( V_120 -> V_107 , V_26 + 6 , V_125 ) ;
V_120 -> V_107 [ V_149 + V_125 ] = '\0' ;
F_64 ( V_120 -> V_107 , L_61 , V_135 ) ;
V_28 = V_26 + 6 + V_125 ;
V_136 ++ ;
} else if ( strncmp ( V_26 , L_62 , 4 ) == 0 ) {
V_15 = F_60 ( & V_120 -> V_106 , V_26 + 4 ) ;
if ( V_15 )
goto V_143;
V_136 ++ ;
}
else if ( strncmp ( V_26 , L_63 , 7 ) == 0 ) {
V_130 = V_26 + 7 ;
* V_26 = '\0' ;
break;
}
V_27 = strchr ( V_26 , ',' ) ;
if ( ! V_27 ) {
if ( V_136 )
* V_26 = '\0' ;
break;
}
V_27 ++ ;
if ( V_136 )
memmove ( V_26 , V_27 , strlen ( V_27 ) + 1 ) ;
else
V_26 = V_27 ;
}
if ( ! V_130 ) {
F_12 ( 0x164 , L_64 ) ;
goto V_143;
}
V_26 = strstr ( V_130 , L_65 ) ;
if ( V_26 ) {
++ V_26 ;
V_120 -> V_68 |= V_153 ;
while ( * ++ V_26 == '/' )
;
V_120 -> V_102 = F_23 ( V_16 , L_66 , V_26 ) ;
if ( ! V_120 -> V_102 )
return - V_17 ;
}
V_120 -> V_53 = F_4 ( strlen ( V_130 ) + 1 , V_16 ) ;
if ( ! V_120 -> V_53 )
return - V_17 ;
strcpy ( V_120 -> V_53 , V_130 ) ;
V_26 = V_129 + strlen ( V_129 ) - 1 ;
while ( V_26 >= V_129 && ( * V_26 == ',' || * V_26 == ' ' ) )
* V_26 -- = 0 ;
if ( * V_129 != 0 ) {
V_120 -> V_103 = F_4 ( strlen ( V_129 ) + 1 , V_16 ) ;
if ( ! V_120 -> V_103 )
return - V_17 ;
strcpy ( V_120 -> V_103 , V_129 ) ;
}
F_53 ( V_120 ) ;
V_120 -> V_132 = V_133 ;
return V_15 ;
V_143:
F_18 ( L_67 , V_129 ) ;
return - V_20 ;
}
static int F_65 ( struct V_1 * V_2 , void * V_39 , int V_154 )
{
struct V_119 * V_120 ;
struct V_155 * V_156 = V_39 ;
struct V_10 * V_11 ;
int V_15 ;
F_15 ( V_34 | V_157 , L_68 , V_2 ) ;
V_11 = F_44 ( V_2 ) ;
if ( ! V_11 )
return - V_17 ;
V_120 = V_11 -> V_52 ;
F_66 () ;
F_67 () ;
if ( F_62 ( ( V_156 -> V_158 ) , V_120 ) ) {
F_47 ( V_2 ) ;
V_15 = - V_20 ;
goto V_73;
}
if ( F_27 ( V_120 ) ) {
F_15 ( V_34 , L_69 , V_120 -> V_102 ) ;
if ( ! V_159 )
F_68 ( L_70 ) ;
if ( ! V_159 ) {
F_12 ( 0x165 , L_71 ) ;
F_47 ( V_2 ) ;
V_15 = - V_160 ;
} else {
V_15 = F_19 ( V_2 ) ;
if ( V_15 ) {
F_52 ( V_2 ) ;
goto V_73;
}
V_15 = (* V_159)( V_2 , V_156 -> V_161 ) ;
}
} else {
F_18 ( L_72 ) ;
V_15 = - V_20 ;
}
goto V_73;
V_73:
if ( V_15 ) {
F_18 ( L_73 ,
F_2 ( V_2 ) ? V_120 -> V_53 : L_10 , V_15 ) ;
} else {
F_15 ( V_162 , L_74 ,
V_120 -> V_53 ) ;
}
F_69 () ;
return V_15 ;
}
void F_70 ( int (* F_71)( struct V_1 * V_2 ,
struct V_163 * V_164 ) )
{
V_159 = F_71 ;
}
void F_72 ( void (* F_71)( struct V_1 * V_2 ) )
{
V_165 = F_71 ;
}
static struct V_166 * F_73 ( struct V_167 * V_168 , int V_67 ,
const char * V_130 , void * V_39 )
{
struct V_155 V_156 = {
. V_158 = V_39 ,
. V_161 = NULL
} ;
return F_74 ( V_168 , V_67 , & V_156 , F_65 ) ;
}
static void F_75 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = F_2 ( V_2 ) ;
if ( V_165 && V_11 )
(* V_165)( V_2 ) ;
F_76 ( V_2 ) ;
}
int F_77 ( void )
{
return F_78 ( & V_169 ) ;
}
int F_79 ( void )
{
return F_80 ( & V_169 ) ;
}
