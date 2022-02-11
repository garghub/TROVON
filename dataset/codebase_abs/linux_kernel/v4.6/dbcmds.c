struct V_1 * F_1 ( char * V_2 )
{
struct V_1 * V_3 ;
T_1 V_4 ;
if ( ( * V_2 >= 0x30 ) && ( * V_2 <= 0x39 ) ) {
V_4 = strtoul ( V_2 , NULL , 16 ) ;
V_3 = F_2 ( V_4 ) ;
if ( ! F_3 ( V_3 , sizeof( struct V_1 ) ) ) {
F_4 ( L_1 , V_3 ) ;
return ( NULL ) ;
}
if ( F_5 ( V_3 ) != V_5 ) {
F_4
( L_2 ,
V_3 , F_6 ( V_3 ) ) ;
return ( NULL ) ;
}
} else {
V_3 = F_7 ( V_2 ) ;
if ( ! V_3 ) {
F_4
( L_3 ,
V_2 ) ;
V_3 = V_6 ;
}
}
return ( V_3 ) ;
}
T_2 F_8 ( char * V_7 )
{
T_3 V_8 ;
T_4 V_9 ;
F_9 ( F_8 ) ;
if ( ! V_7 ) {
F_4 ( L_4 ,
V_10 ) ;
for ( V_9 = 0 ; V_9 <= V_10 ; V_9 ++ ) {
F_10 ( ( T_3 ) V_9 ) ;
}
F_11 ( V_11 ) ;
}
V_8 = ( T_3 ) strtoul ( V_7 , NULL , 0 ) ;
F_10 ( V_8 ) ;
F_11 ( V_11 ) ;
}
static void F_10 ( T_3 V_8 )
{
T_2 V_12 ;
T_3 V_13 ;
T_3 V_14 ;
if ( V_8 > V_10 ) {
F_4 ( L_5 ,
V_8 , V_10 ) ;
return;
}
F_4 ( L_6 ,
V_8 , V_15 [ V_8 ] ) ;
V_12 =
F_12 ( V_8 , & V_13 , & V_14 ) ;
if ( F_13 ( V_12 ) ) {
F_4 ( L_7 ,
V_15 [ V_8 ] ,
F_14 ( V_12 ) ) ;
return;
}
F_4
( L_8 ,
V_8 , V_13 , V_14 ) ;
F_4 ( L_9 ,
V_8 ) ;
V_12 = F_15 ( V_8 ) ;
if ( F_13 ( V_12 ) ) {
goto V_16;
}
F_4 ( L_10 , V_8 ) ;
V_12 = F_16 ( V_8 ) ;
if ( F_13 ( V_12 ) ) {
goto V_16;
}
F_4 ( L_11 ,
V_8 ) ;
V_12 = F_17 ( V_8 ) ;
if ( F_13 ( V_12 ) ) {
goto V_16;
}
F_4 ( L_12 ,
V_8 ) ;
V_12 = F_18 ( V_8 ) ;
if ( F_13 ( V_12 ) ) {
goto V_16;
}
return;
V_16:
F_19 ( ( V_17 , V_12 , L_13 ,
V_8 ) ) ;
}
void F_20 ( void )
{
T_4 V_9 ;
for ( V_9 = 0 ; V_9 < V_18 ; V_9 ++ ) {
F_4 ( L_14 , F_21 ( V_9 ) ,
V_19 [ V_9 ] . V_20 ==
V_21 ? L_15 : L_16 ) ;
}
}
void F_22 ( char * V_22 )
{
T_4 V_9 ;
struct V_23 * V_24 ;
T_2 V_12 ;
F_4 ( L_17
L_18 ) ;
for ( V_9 = 0 ; V_9 < V_25 . V_26 ; V_9 ++ ) {
V_24 = & V_25 . V_27 [ V_9 ] ;
F_4 ( L_19 , V_9 , V_24 -> V_28 ) ;
if ( ! ( V_24 -> V_29 & V_30 ) ) {
F_4 ( L_20 ) ;
} else {
F_4 ( L_21 ) ;
}
switch ( V_24 -> V_29 & V_31 ) {
case V_32 :
F_4 ( L_22 ) ;
break;
case V_33 :
F_4 ( L_23 ) ;
break;
case V_34 :
F_4 ( L_24 ) ;
break;
default:
F_4 ( L_25 ) ;
break;
}
V_12 = F_23 ( V_24 ) ;
if ( F_13 ( V_12 ) ) {
return;
}
if ( V_24 -> V_35 ) {
F_24 ( V_24 -> V_4 ,
V_24 -> V_35 ) ;
} else {
F_25 ( ( L_26 ,
V_24 -> V_36 . V_37 ) ) ;
}
}
}
void F_26 ( char * V_38 )
{
struct V_1 * V_3 ;
T_2 V_12 ;
V_3 = F_1 ( V_38 ) ;
if ( ! V_3 ) {
return;
}
V_12 = F_27 ( F_28 ( V_39 , V_3 ) ) ;
if ( F_29 ( V_12 ) ) {
F_4 ( L_27 ,
V_38 , V_3 ) ;
} else {
F_4 ( L_28 ,
F_14 ( V_12 ) , V_38 ) ;
}
}
void F_30 ( char * V_40 , T_4 V_41 )
{
struct V_1 * V_3 ;
T_2 V_12 ;
V_3 = F_1 ( V_40 ) ;
if ( ! V_3 ) {
return;
}
if ( F_31 ( V_3 ) ) {
V_12 = F_32 ( V_3 , V_41 ) ;
if ( F_13 ( V_12 ) ) {
F_4 ( L_29 ) ;
}
} else {
F_4 ( L_30
L_31 ,
F_33 ( V_3 ) ,
F_34 ( V_3 -> type ) ) ;
}
}
void F_35 ( char * V_42 , char * V_43 )
{
struct V_44 * V_45 ;
char * V_46 ;
T_2 V_12 ;
if ( ! V_42 ) {
( void ) F_36 ( V_47 ,
V_48 ) ;
V_45 = V_49 ;
while ( V_45 ) {
if ( ! ( V_45 -> V_29 & V_50 ) ) {
F_4 ( L_32 , V_45 -> V_40 ) ;
}
V_45 = V_45 -> V_51 ;
}
F_37 ( V_47 ) ;
return;
}
if ( ! V_43 ) {
F_4 ( L_33 ) ;
return;
}
F_38 ( V_42 ) ;
V_46 = strstr ( L_34 , V_42 ) ;
if ( V_46 ) {
V_12 = F_39 ( V_43 ) ;
if ( F_13 ( V_12 ) ) {
F_4 ( L_35 ,
F_14 ( V_12 ) ,
V_43 ) ;
}
return;
}
V_46 = strstr ( L_36 , V_42 ) ;
if ( V_46 ) {
V_12 = F_40 ( V_43 ) ;
if ( F_13 ( V_12 ) ) {
F_4 ( L_37 ,
F_14 ( V_12 ) ,
V_43 ) ;
}
return;
}
F_4 ( L_38 , V_42 ) ;
return;
}
void F_41 ( char * V_52 )
{
struct V_1 * V_3 ;
T_2 V_12 ;
struct V_53 V_54 ;
V_3 = F_1 ( V_52 ) ;
if ( ! V_3 || ( V_3 == V_6 ) ) {
F_4 ( L_39 , V_52 ) ;
return;
}
if ( V_3 -> type != V_55 ) {
F_4
( L_40 ,
V_52 ) ;
return;
}
V_54 . V_56 = V_57 ;
V_54 . V_35 = V_58 ;
V_12 = F_42 ( V_3 -> V_59 , & V_54 ) ;
F_43 ( V_60 ) ;
V_61 |= V_62 ;
if ( F_13 ( V_12 ) ) {
F_4
( L_41 ,
V_52 , F_14 ( V_12 ) ) ;
goto V_63;
}
F_44 ( F_28 ( struct V_64 ,
V_54 . V_35 ) ) ;
V_63:
F_4 ( L_42 ) ;
F_45 ( ( T_3 * ) V_3 -> V_59 -> V_65 . V_35 ,
V_3 -> V_59 -> V_65 . V_56 ,
V_66 , V_67 ) ;
F_43 ( V_68 ) ;
return;
}
static void
F_46 ( T_3 * V_69 ,
T_5 V_70 ,
T_3 * V_71 ,
T_5 V_72 )
{
T_3 * V_73 ;
T_3 * V_74 ;
T_3 * V_75 ;
T_3 * V_76 ;
T_5 V_77 ;
T_5 V_78 ;
T_5 V_79 = 0 ;
T_3 V_80 ;
T_4 V_81 = 0 ;
T_4 V_9 ;
if ( V_70 != V_72 ) {
F_4 ( L_43
L_44 ,
V_70 , V_72 ) ;
}
V_73 = V_69 ;
V_74 = V_71 ;
V_75 = V_69 + V_70 ;
V_76 = V_71 + V_72 ;
while ( ( V_73 < V_75 ) && ( V_74 < V_76 ) ) {
V_77 = F_47 ( V_73 ) ;
V_78 = F_47 ( V_74 ) ;
V_80 = F_48 ( V_73 ) ;
if ( V_77 != V_78 ) {
F_4
( L_45
L_46 , V_81 ,
V_80 , V_79 , V_77 , V_78 ) ;
}
else if ( memcmp ( V_73 , V_74 , V_77 ) ) {
F_4
( L_47
L_48 , V_81 , V_80 ,
V_79 ) ;
for ( V_9 = 0 ; V_9 < V_77 ; V_9 ++ ) {
if ( V_73 [ V_9 ] != V_74 [ V_9 ] ) {
F_4
( L_49
L_50 , V_9 , V_74 [ V_9 ] ,
V_73 [ V_9 ] ) ;
}
}
}
if ( V_80 == V_82 ) {
return;
}
V_81 ++ ;
V_79 += V_77 ;
V_73 += V_77 ;
V_74 += V_78 ;
}
}
static T_2
F_49 ( struct V_1 * V_3 , char * V_40 )
{
T_2 V_12 ;
struct V_53 V_54 ;
struct V_53 V_83 ;
struct V_53 V_84 ;
union V_85 * V_86 ;
F_4 ( L_51 ) ;
V_84 . V_56 = V_87 ;
V_54 . V_56 = V_87 ;
V_83 . V_56 = V_87 ;
V_12 = F_50 ( V_3 , V_40 , NULL , & V_54 ) ;
if ( F_13 ( V_12 ) ) {
F_4 ( L_52 ,
V_40 , F_14 ( V_12 ) ) ;
return ( V_12 ) ;
}
V_12 = F_51 ( V_3 , & V_83 ) ;
if ( F_13 ( V_12 ) ) {
F_4 ( L_53 ,
F_14 ( V_12 ) ) ;
goto V_88;
}
V_12 = F_52 ( & V_83 , & V_84 ) ;
if ( F_13 ( V_12 ) ) {
F_4 ( L_54 ,
F_14 ( V_12 ) ) ;
goto V_89;
}
V_86 = V_54 . V_35 ;
F_46 ( V_86 -> V_65 . V_35 ,
( T_5 ) V_86 -> V_65 .
V_56 , V_84 . V_35 ,
( T_5 ) V_84 . V_56 ) ;
F_53 ( V_84 . V_35 ) ;
V_89:
F_53 ( V_83 . V_35 ) ;
V_88:
F_53 ( V_54 . V_35 ) ;
return ( V_12 ) ;
}
static T_2
F_54 ( struct V_64 * V_90 , void * V_91 )
{
return ( V_11 ) ;
}
static T_2
F_55 ( V_39 V_92 ,
T_4 V_93 , void * V_91 , void * * V_94 )
{
struct V_1 * V_3 ;
struct V_1 * V_95 = NULL ;
struct V_1 * V_96 = NULL ;
struct V_1 * V_97 = NULL ;
struct V_1 * V_98 = NULL ;
char * V_99 ;
struct V_53 V_54 ;
T_2 V_12 ;
V_3 = F_28 ( struct V_1 , V_92 ) ;
V_99 = F_56 ( V_3 , TRUE ) ;
if ( ! V_99 ) {
return ( V_100 ) ;
}
( void ) F_57 ( V_3 , V_101 ,
F_28 ( V_39 , & V_95 ) ) ;
( void ) F_57 ( V_3 , V_102 ,
F_28 ( V_39 , & V_96 ) ) ;
( void ) F_57 ( V_3 , V_103 ,
F_28 ( V_39 , & V_97 ) ) ;
( void ) F_57 ( V_3 , V_104 ,
F_28 ( V_39 , & V_98 ) ) ;
if ( ! V_95 && ! V_96 && ! V_97 && ! V_98 ) {
goto V_105;
}
F_4 ( L_55 , V_99 ) ;
V_54 . V_35 = V_58 ;
V_54 . V_56 = V_57 ;
if ( V_95 ) {
F_4 ( L_56 ) ;
V_12 =
F_50 ( V_95 , NULL , NULL , & V_54 ) ;
if ( F_13 ( V_12 ) ) {
F_4 ( L_57 ,
F_14 ( V_12 ) ) ;
goto V_106;
}
V_54 . V_35 = V_58 ;
V_54 . V_56 = V_57 ;
V_12 = F_58 ( V_3 , & V_54 ) ;
if ( F_13 ( V_12 ) ) {
F_4 ( L_58 ,
F_14 ( V_12 ) ) ;
goto V_106;
}
F_59 ( F_28 ( T_3 , V_58 ) ) ;
}
V_106:
if ( V_96 ) {
F_4 ( L_59 ) ;
V_54 . V_35 = V_58 ;
V_54 . V_56 = V_57 ;
V_12 =
F_50 ( V_96 , NULL , NULL , & V_54 ) ;
if ( F_13 ( V_12 ) ) {
F_4 ( L_60 ,
F_14 ( V_12 ) ) ;
goto V_107;
}
V_12 = F_60 ( V_3 , V_102 ,
F_54 , NULL ) ;
if ( F_13 ( V_12 ) ) {
F_4 ( L_61 ,
F_14 ( V_12 ) ) ;
goto V_107;
}
V_54 . V_35 = NULL ;
V_54 . V_56 = V_87 ;
V_12 = F_51 ( V_3 , & V_54 ) ;
if ( F_13 ( V_12 ) ) {
F_4 ( L_53 ,
F_14 ( V_12 ) ) ;
goto V_107;
}
V_12 = F_61 ( & V_54 ,
F_54 ,
NULL ) ;
if ( F_13 ( V_12 ) ) {
F_4 ( L_62 ,
F_14 ( V_12 ) ) ;
goto V_108;
}
F_44 ( F_28 ( struct V_64 ,
V_54 .
V_35 ) ) ;
( void ) F_49 ( V_3 , V_102 ) ;
F_4 ( L_63 ) ;
V_12 = F_62 ( V_3 , & V_54 ) ;
if ( F_13 ( V_12 ) ) {
F_4 ( L_64 ,
F_14 ( V_12 ) ) ;
goto V_108;
}
V_108:
F_53 ( V_54 . V_35 ) ;
}
V_107:
if ( V_97 ) {
F_4 ( L_65 ) ;
V_54 . V_35 = V_58 ;
V_54 . V_56 = V_57 ;
V_12 =
F_50 ( V_97 , NULL , NULL , & V_54 ) ;
if ( F_13 ( V_12 ) ) {
F_4 ( L_66 ,
F_14 ( V_12 ) ) ;
goto V_109;
}
V_54 . V_35 = V_58 ;
V_54 . V_56 = V_57 ;
V_12 = F_63 ( V_3 , & V_54 ) ;
if ( F_13 ( V_12 ) ) {
F_4 ( L_67 ,
F_14 ( V_12 ) ) ;
goto V_109;
}
F_44 ( F_28
( struct V_64 ,
V_58 ) ) ;
}
V_109:
if ( V_98 ) {
F_4 ( L_68 ) ;
V_54 . V_35 = V_58 ;
V_54 . V_56 = V_57 ;
V_12 =
F_50 ( V_98 , NULL , NULL , & V_54 ) ;
if ( F_13 ( V_12 ) ) {
F_4 ( L_69 ,
F_14 ( V_12 ) ) ;
goto V_105;
}
V_54 . V_35 = V_58 ;
V_54 . V_56 = V_57 ;
V_12 = F_64 ( V_3 , & V_54 ) ;
if ( F_13 ( V_12 ) ) {
F_4 ( L_70 ,
F_14 ( V_12 ) ) ;
goto V_105;
}
F_44 ( F_28
( struct V_64 ,
V_58 ) ) ;
}
V_105:
F_53 ( V_99 ) ;
return ( V_11 ) ;
}
void F_65 ( char * V_7 )
{
struct V_1 * V_3 ;
F_43 ( V_60 ) ;
V_61 |= V_62 ;
if ( ! V_7 || ( ! strcmp ( V_7 , L_71 ) ) ) {
( void ) F_66 ( V_110 , V_111 ,
V_67 ,
F_55 , NULL , NULL ,
NULL ) ;
} else {
V_3 = F_1 ( V_7 ) ;
if ( V_3 ) {
if ( V_3 -> type != V_110 ) {
F_4
( L_72 ,
V_3 -> V_40 . V_37 ,
F_34 ( V_3 -> type ) ) ;
} else {
( void ) F_55 ( V_3 , 0 , NULL ,
NULL ) ;
}
}
}
F_43 ( V_68 ) ;
}
void F_67 ( char * V_112 , char * V_113 )
{
T_4 V_114 = 0 ;
T_4 V_115 ;
struct V_116 * V_117 ;
V_115 = strtoul ( V_112 , NULL , 0 ) ;
if ( V_113 ) {
V_114 = strtoul ( V_113 , NULL , 0 ) ;
if ( V_114 == 1 ) {
V_114 = 0 ;
}
}
V_117 =
F_68 ( F_2 ( V_114 ) ,
V_115 ) ;
if ( ! V_117 ) {
F_4 ( L_73 ) ;
return;
}
( void ) F_69 ( NULL , V_117 , V_115 ) ;
}
void F_70 ( void )
{
F_71 () ;
}
void F_72 ( char * V_118 , char * V_119 , char * V_120 )
{
T_4 V_121 = 0 ;
T_4 V_122 = 0 ;
T_4 V_29 = 0 ;
F_38 ( V_118 ) ;
F_38 ( V_120 ) ;
if ( V_119 ) {
if ( V_123 ) {
F_53 ( V_123 ) ;
V_123 = NULL ;
}
V_123 =
F_73 ( strlen ( V_119 ) + 1 ) ;
if ( ! V_123 ) {
F_4 ( L_74 ,
V_119 ) ;
return;
}
strcpy ( V_123 , V_119 ) ;
}
if ( ! strcmp ( V_118 , L_75 ) ||
! strcmp ( V_118 , L_76 ) || ! strcmp ( V_118 , L_77 ) ) {
if ( ! strcmp ( V_118 , L_75 ) ) {
V_121 = V_124 ;
V_122 = V_125 ;
} else {
V_121 = V_126 ;
V_122 = V_127 ;
}
V_29 = V_128 ;
if ( ! strcmp ( V_118 , L_77 ) ) {
V_29 |= V_129 ;
}
if ( V_120 && ! strcmp ( V_120 , L_78 ) ) {
V_29 |= V_130 ;
}
}
( void ) F_74 ( V_123 ,
V_121 , V_122 , V_29 ) ;
}
