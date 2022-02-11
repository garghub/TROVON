int F_1 ( int V_1 )
{
int V_2 = - V_3 ;
V_4 = ( unsigned long long ) V_1 ;
F_2 ( & V_4 , 0 ) ;
F_3 ( V_5 , & V_4 ,
0 ) ;
if ( V_4 != 0 )
V_6 = true ;
F_4 ( L_1 ,
V_7 ,
V_5 ,
( unsigned long long ) V_4 ) ;
V_8 = F_5 ( L_2 , NULL ) ;
if ( ! V_8 ) {
F_4 ( L_3 , V_7 ) ;
goto V_9;
}
V_10 = F_6 ( V_11 ,
0444 ,
V_8 ,
V_12 ,
& V_13 ) ;
if ( ! V_10 ) {
F_4 ( L_4 , V_7 ) ;
goto V_9;
}
V_14 = 0 ;
V_2 = F_7 () ;
V_9:
return V_2 ;
}
static int F_7 ( void )
{
int V_2 = - V_3 ;
struct V_15 * V_16 ;
char * V_17 = NULL ;
F_8 ( V_18 , L_5 , V_7 ) ;
V_17 = F_9 ( V_19 , V_20 ) ;
if ( ! V_17 )
goto V_9;
if ( strlen ( V_5 ) + 1 < V_19 ) {
strcpy ( V_17 , V_5 ) ;
strcat ( V_17 , L_6 ) ;
} else {
strcpy ( V_17 , L_7 ) ;
F_4 ( L_8 , V_7 ) ;
}
V_16 = F_6 ( V_21 ,
0444 ,
V_8 ,
V_17 ,
& V_22 ) ;
if ( ! V_16 ) {
F_4 ( L_9 ,
V_7 ,
V_21 ) ;
goto V_9;
}
V_2 = 0 ;
V_9:
F_8 ( V_18 , L_10 , V_7 , V_2 ) ;
return V_2 ;
}
void F_10 ( void )
{
F_11 ( V_8 ) ;
}
static int F_12 ( struct V_23 * V_23 , struct V_24 * V_24 )
{
int V_2 = - V_25 ;
int V_16 ;
F_8 ( V_18 ,
L_11 ) ;
if ( V_14 )
goto V_9;
V_16 = F_13 ( V_24 , & V_26 ) ;
if ( V_16 )
goto V_9;
( (struct V_27 * ) ( V_24 -> V_28 ) ) -> V_29 = V_23 -> V_30 ;
V_2 = 0 ;
V_9:
F_8 ( V_18 ,
L_12 ,
V_2 ) ;
return V_2 ;
}
static void * F_14 ( struct V_27 * V_31 , T_1 * V_32 )
{
void * V_33 = NULL ;
F_8 ( V_18 , L_13 ) ;
F_15 ( & V_34 ) ;
if ( * V_32 == 0 )
V_33 = V_31 -> V_29 ;
return V_33 ;
}
static void * F_16 ( struct V_27 * V_31 , void * V_35 , T_1 * V_32 )
{
F_8 ( V_18 , L_14 ) ;
return NULL ;
}
static void F_17 ( struct V_27 * V_31 , void * V_36 )
{
F_8 ( V_18 , L_15 ) ;
F_18 ( & V_34 ) ;
}
static int F_19 ( struct V_27 * V_31 , void * V_35 )
{
F_8 ( V_18 , L_16 ) ;
F_20 ( V_31 , V_35 ) ;
return 0 ;
}
int F_21 ( void )
{
int V_2 = - V_3 ;
char * V_37 = NULL ;
F_8 ( V_18 , L_5 , V_7 ) ;
V_37 = F_9 ( V_19 , V_20 ) ;
if ( ! V_37 )
goto V_9;
if ( strlen ( V_38 ) + 1 < V_19 ) {
strcpy ( V_37 , V_38 ) ;
strcat ( V_37 , L_6 ) ;
} else {
strcpy ( V_37 , L_7 ) ;
F_4 ( L_17 , V_7 ) ;
}
V_39 = F_6 ( V_40 ,
0444 ,
V_8 ,
V_37 ,
& V_22 ) ;
if ( ! V_39 ) {
F_4 ( L_18 ,
V_7 ,
V_40 ) ;
goto V_9;
}
V_2 = 0 ;
V_9:
F_8 ( V_18 , L_10 , V_7 , V_2 ) ;
return V_2 ;
}
static int F_22 ( struct V_23 * V_23 , struct V_24 * V_24 )
{
int V_2 = - V_25 ;
F_8 ( V_18 ,
L_19 ,
V_7 ,
V_14 ) ;
if ( V_14 )
goto V_9;
V_2 = 0 ;
F_15 ( & V_41 ) ;
V_24 -> V_28 = V_23 -> V_30 ;
F_18 ( & V_41 ) ;
V_9:
F_8 ( V_18 ,
L_20 ,
V_2 ) ;
return V_2 ;
}
static T_2 F_23 ( struct V_24 * V_24 ,
char T_3 * V_42 ,
T_4 V_43 ,
T_1 * V_44 )
{
char * V_45 ;
int V_46 ;
T_2 V_47 = - V_3 ;
F_8 ( V_18 , L_21 ) ;
V_45 = F_24 ( V_19 , V_20 ) ;
if ( ! V_45 )
goto V_9;
F_15 ( & V_41 ) ;
V_46 = sprintf ( V_45 , L_22 , ( char * ) V_24 -> V_28 ) ;
F_18 ( & V_41 ) ;
V_47 = F_25 ( V_42 , V_43 , V_44 , V_45 , V_46 ) ;
F_26 ( V_45 ) ;
V_9:
F_8 ( V_18 ,
L_23 ,
V_47 ) ;
return V_47 ;
}
static T_2 F_27 ( struct V_24 * V_24 ,
const char T_3 * V_42 ,
T_4 V_43 ,
T_1 * V_44 )
{
char * V_45 ;
int V_2 = - V_48 ;
T_4 V_49 = 0 ;
char * V_50 ;
struct V_51 * V_52 = NULL ;
struct V_53 V_54 = { NULL , 0 , 0 } ;
F_8 ( V_18 ,
L_24 ,
V_24 ) ;
if ( V_43 > V_19 + 1 ) {
V_49 = V_43 ;
V_43 = V_19 + 1 ;
}
V_45 = F_9 ( V_19 , V_20 ) ;
if ( ! V_45 )
goto V_9;
if ( F_28 ( V_45 , V_42 , V_43 - 1 ) ) {
F_8 ( V_18 ,
L_25 ,
V_7 ) ;
goto V_9;
}
if ( ! strcmp ( V_24 -> V_55 . V_15 -> V_56 . V_57 ,
V_21 ) ) {
F_3 ( V_45 , & V_4 , 0 ) ;
F_2 ( & V_4 , 0 ) ;
V_50 = V_5 ;
F_8 ( V_18 ,
L_26 ,
V_5 ) ;
} else {
if ( F_29 () ) {
F_4 ( L_27 ,
V_7 ,
F_29 () ) ;
goto V_9;
}
F_3 ( V_45 , & V_54 , 1 ) ;
F_2 ( & V_54 , 1 ) ;
V_50 = V_38 ;
V_52 = F_30 ( V_58 ) ;
if ( ! V_52 ) {
F_4 ( L_28 , V_7 ) ;
goto V_9;
}
V_52 -> V_59 . V_60 . V_61 . V_62 =
V_63 ;
V_52 -> V_59 . V_60 . V_61 . type = V_64 ;
memset ( V_52 -> V_59 . V_60 . V_61 . V_65 ,
0 ,
V_19 ) ;
sprintf ( V_52 -> V_59 . V_60 . V_61 . V_65 ,
L_29 ,
V_54 . V_66 ,
V_54 . V_67 ) ;
V_2 = F_31 ( V_52 ,
L_30 ,
V_68 ) ;
if ( V_2 )
F_8 ( V_18 ,
L_31 ,
V_7 ,
V_2 ) ;
F_32 ( V_52 ) ;
}
F_15 ( & V_41 ) ;
memset ( V_24 -> V_69 -> V_30 , 0 , V_19 ) ;
sprintf ( ( char * ) V_24 -> V_69 -> V_30 , L_32 , V_50 ) ;
F_18 ( & V_41 ) ;
* V_44 += V_43 ;
if ( V_49 )
V_2 = V_49 ;
else
V_2 = V_43 ;
V_9:
F_8 ( V_18 ,
L_33 ,
V_2 ) ;
F_26 ( V_45 ) ;
return V_2 ;
}
static int F_33 ( char * V_70 )
{
int V_71 ;
int V_2 = - V_72 ;
char * V_73 = NULL ;
char * V_74 = NULL ;
int V_75 = 0 ;
F_8 ( V_76 , L_5 , V_7 ) ;
for ( V_71 = 0 ; V_71 < strlen ( V_70 ) ; V_71 ++ )
if ( V_70 [ V_71 ] == '\n' )
V_77 ++ ;
if ( ! V_77 ) {
F_4 ( L_34 ) ;
goto V_9;
}
V_78 =
F_9 ( V_77 * sizeof( struct V_53 ) ,
V_20 ) ;
if ( ! V_78 ) {
F_4 ( L_35 ) ;
V_2 = - V_3 ;
goto V_9;
}
V_73 = V_70 ;
for ( V_71 = 0 ; V_71 < V_77 ; V_71 ++ ) {
V_74 = strchr ( V_73 , '\n' ) ;
* V_74 = '\0' ;
V_75 = strcspn ( V_73 , L_36 ) ;
V_78 [ V_71 ] . V_79 = F_9 ( V_75 + 1 , V_20 ) ;
if ( ! V_78 [ V_71 ] . V_79 ) {
V_2 = - V_3 ;
goto V_9;
}
sscanf ( V_73 ,
L_37 ,
V_78 [ V_71 ] . V_79 ,
( unsigned long long * ) & ( V_78 [ V_71 ] . V_66 ) ,
( unsigned long long * ) & ( V_78 [ V_71 ] . V_67 ) ) ;
if ( ! strcmp ( V_78 [ V_71 ] . V_79 , V_80 ) )
V_81 = V_71 ;
if ( ! strcmp ( V_78 [ V_71 ] . V_79 , V_82 ) )
V_83 = V_71 ;
V_73 = V_74 + 1 ;
}
V_2 = V_77 ;
F_8 ( V_76 , L_10 , V_7 , V_2 ) ;
V_9:
return V_2 ;
}
int F_34 ( int V_84 )
{
char * V_85 = L_38 ;
char * V_86 = L_39 ;
T_4 V_87 = V_88 ;
T_4 V_89 ;
T_4 V_71 ;
char * V_90 ;
int V_2 = - V_72 ;
F_8 ( V_76 , L_5 , V_7 ) ;
if ( V_84 )
V_85 = V_91 ;
V_90 = F_9 ( V_88 , V_20 ) ;
if ( ! V_90 ) {
V_2 = - V_3 ;
goto V_9;
}
F_35 ( V_90 , V_85 , V_87 ) ;
if ( ! V_84 ) {
V_77 =
F_33 ( V_92 ) ;
if ( V_77 <= 0 )
goto V_9;
for ( V_71 = 0 ; V_71 < V_77 ; V_71 ++ ) {
F_35 ( V_90 , L_40 , V_87 ) ;
F_35 ( V_90 , V_78 [ V_71 ] . V_79 , V_87 ) ;
F_35 ( V_90 , L_6 , V_87 ) ;
}
}
F_35 ( V_90 , L_6 , V_87 ) ;
F_35 ( V_90 , V_86 , V_87 ) ;
for ( V_71 = 0 ; V_71 < V_93 ; V_71 ++ ) {
F_35 ( V_90 , L_40 , V_87 ) ;
F_35 ( V_90 , V_94 [ V_71 ] . V_79 , V_87 ) ;
V_89 = F_35 ( V_90 , L_6 , V_87 ) ;
}
if ( V_89 >= V_87 ) {
F_26 ( V_90 ) ;
goto V_9;
}
if ( V_84 ) {
V_12 = V_90 ;
} else {
F_15 ( & V_34 ) ;
memset ( V_12 , 0 , V_88 ) ;
F_35 ( V_12 , V_90 , V_87 ) ;
F_18 ( & V_34 ) ;
}
V_2 = 0 ;
V_9: return V_2 ;
}
static void F_2 ( void * V_95 , int type )
{
int V_71 ;
int V_96 = 0 ;
char * V_50 ;
int V_97 = 0 ;
F_8 ( V_76 , L_5 , V_7 ) ;
if ( type ) {
V_50 = V_38 ;
V_97 = V_77 ;
} else {
V_50 = V_5 ;
V_97 = V_93 ;
}
memset ( V_50 , 0 , V_19 ) ;
if ( F_36 ( V_95 , type ) )
goto V_9;
for ( V_71 = 0 ; V_71 < V_97 ; V_71 ++ )
if ( type )
F_37 ( V_95 , V_71 ) ;
else
F_38 ( V_95 , V_71 ) ;
V_96 = strlen ( V_50 ) ;
if ( ( V_96 ) && ( type ) )
V_38 [ V_96 - 1 ] = '\0' ;
else if ( V_96 )
V_5 [ V_96 - 1 ] = '\0' ;
else if ( type )
strcpy ( V_38 , L_41 ) ;
else
strcpy ( V_5 , L_41 ) ;
V_9:
F_8 ( V_76 , L_42 , V_7 , V_50 ) ;
return;
}
static void F_38 ( void * V_98 , int V_99 )
{
T_5 * V_95 = ( T_5 * ) V_98 ;
if ( F_39 ( ( char * ) V_94 [ V_99 ] . V_79 ) )
goto V_9;
if ( * V_95 & V_94 [ V_99 ] . V_100 ) {
if ( ( strlen ( V_5 ) +
strlen ( V_94 [ V_99 ] . V_79 ) )
< V_19 - 1 ) {
strcat ( V_5 ,
V_94 [ V_99 ] . V_79 ) ;
strcat ( V_5 , L_43 ) ;
} else {
F_40 ( L_44 , V_7 ) ;
strcpy ( V_5 , V_82 ) ;
goto V_9;
}
}
V_9:
return;
}
static void F_37 ( void * V_54 , int V_99 )
{
struct V_53 * V_95 = (struct V_53 * ) V_54 ;
if ( F_39 ( V_78 [ V_99 ] . V_79 ) )
goto V_9;
if ( ( V_95 -> V_66 & V_78 [ V_99 ] . V_66 ) ||
( V_95 -> V_67 & V_78 [ V_99 ] . V_67 ) ) {
if ( ( strlen ( V_38 ) +
strlen ( V_78 [ V_99 ] . V_79 ) + 1 )
< V_19 - 2 ) {
strcat ( V_38 ,
V_78 [ V_99 ] . V_79 ) ;
strcat ( V_38 , L_43 ) ;
} else {
F_40 ( L_44 , V_7 ) ;
strcpy ( V_38 , V_82 ) ;
goto V_9;
}
}
V_9:
return;
}
static int F_39 ( char * V_79 )
{
int V_2 = 0 ;
if ( ( ! strcmp ( V_79 , V_82 ) ) || ( ! strcmp ( V_79 , V_80 ) ) )
V_2 = 1 ;
return V_2 ;
}
static int F_36 ( void * V_95 , int type )
{
T_5 * V_98 ;
struct V_53 * V_54 ;
int V_101 = V_93 - 1 ;
int V_2 = 0 ;
if ( type ) {
V_54 = (struct V_53 * ) V_95 ;
if ( ( V_54 -> V_66 == V_78 [ V_83 ] . V_66 ) &&
( V_54 -> V_67 == V_78 [ V_83 ] . V_67 ) ) {
strcpy ( V_38 , V_82 ) ;
V_2 = 1 ;
goto V_9;
}
if ( ( V_54 -> V_66 == V_78 [ V_81 ] . V_66 ) &&
( V_54 -> V_67 == V_78 [ V_81 ] . V_67 ) ) {
strcpy ( V_38 , V_80 ) ;
V_2 = 1 ;
goto V_9;
}
} else {
V_98 = ( T_5 * ) V_95 ;
if ( * V_98 >= V_94 [ V_101 ] . V_100 ) {
strcpy ( V_5 , V_82 ) ;
V_2 = 1 ;
goto V_9;
}
}
V_9:
return V_2 ;
}
static void F_3 ( char * V_50 , void * V_95 , int type )
{
char * V_102 ;
int V_71 ;
char * V_103 = F_41 ( V_50 , V_20 ) ;
char * V_104 ;
int V_97 = 0 ;
struct V_53 * V_54 = NULL ;
T_5 * V_98 = NULL ;
F_8 ( V_76 , L_5 , V_7 ) ;
if ( type ) {
V_54 = (struct V_53 * ) V_95 ;
V_97 = V_77 ;
} else {
V_98 = ( T_5 * ) V_95 ;
* V_98 = 0 ;
V_97 = V_93 ;
}
V_104 = V_103 ;
while ( ( V_102 = F_42 ( & V_103 , L_43 ) ) )
if ( strlen ( V_102 ) ) {
for ( V_71 = 0 ; V_71 < V_97 ; V_71 ++ )
if ( type )
F_43 ( V_71 ,
V_102 ,
& V_54 ) ;
else
F_44 ( V_71 ,
V_102 ,
& V_98 ) ;
}
F_26 ( V_104 ) ;
}
static void F_43 ( int V_71 , char * V_102 ,
struct V_53 * * V_105 )
{
if ( ! strcmp ( V_78 [ V_71 ] . V_79 , V_102 ) ) {
( * * V_105 ) . V_66 = ( * * V_105 ) . V_66 | V_78 [ V_71 ] . V_66 ;
( * * V_105 ) . V_67 = ( * * V_105 ) . V_67 | V_78 [ V_71 ] . V_67 ;
}
}
static void F_44 ( int V_71 , char * V_102 , T_5 * * V_105 )
{
if ( ! strcmp ( V_94 [ V_71 ] . V_79 , V_102 ) )
* * V_105 = ( * * V_105 ) |
V_94 [ V_71 ] . V_100 ;
}
int F_45 ( void T_3 * V_106 )
{
struct V_107 V_108 = { 0 } ;
int V_16 ;
V_16 = F_28 ( & V_108 ,
( void T_3 * ) V_106 ,
sizeof( struct V_107 ) ) ;
if ( V_16 != 0 )
return - V_109 ;
V_53 . V_66 = V_108 . V_110 ;
V_53 . V_67 = V_108 . V_111 ;
F_4 ( L_45
L_46 ,
V_7 ,
( unsigned long long ) V_53 . V_66 ,
( unsigned long long ) V_53 . V_67 ) ;
return V_16 ;
}
int F_46 ( void T_3 * V_106 )
{
int V_16 ;
V_16 = F_28 ( & V_92 ,
( void T_3 * ) V_106 ,
V_19 ) ;
if ( V_16 != 0 ) {
F_4 ( L_47 ,
V_7 ) ;
return - V_109 ;
}
V_92 [ V_19 - 1 ] =
'\0' ;
F_4 ( L_48 ,
V_7 ) ;
if ( ! V_112 ) {
if ( F_34 ( 0 ) ) {
F_40 ( L_49 ,
V_7 ) ;
return - V_109 ;
}
}
F_2 ( & V_53 , 1 ) ;
F_47 ( V_39 ) ;
F_21 () ;
V_112 ++ ;
return V_16 ;
}
int F_48 ( void T_3 * V_106 )
{
struct V_113 V_114 = { 0 } ;
int V_16 ;
V_16 = F_28 ( & V_114 ,
( void T_3 * ) V_106 ,
sizeof( V_114 ) ) ;
if ( V_16 != 0 )
return - V_109 ;
if ( V_114 . V_115 == V_116 ) {
if ( ( V_114 . V_117 == 0 )
&& ( V_6 ) ) {
return 0 ;
}
F_2 ( & V_114 . V_117 ,
V_114 . V_115 ) ;
V_4 = V_114 . V_117 ;
F_4 ( L_50
L_51 ,
V_7 ,
V_5 ,
( unsigned long long ) V_4 ) ;
} else if ( V_114 . V_115 == V_118 ) {
F_2 ( & V_114 . V_117 ,
V_114 . V_115 ) ;
F_4 ( L_52
L_51 ,
V_7 ,
V_38 ,
F_49 ( V_114 . V_117 ) ) ;
} else {
F_50 ( L_53 ) ;
return - V_72 ;
}
return V_16 ;
}
