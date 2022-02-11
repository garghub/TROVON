static struct V_1 * F_1 ( T_1 V_2 )
{
struct V_3 * V_4 ;
struct V_1 * V_5 ;
V_4 = V_6 . V_3 ;
while ( V_4 ) {
V_5 = F_2 ( V_4 , struct V_1 , V_7 ) ;
if ( V_5 -> V_2 == V_2 )
return V_5 ;
else if ( V_2 < V_5 -> V_2 )
V_4 = V_4 -> V_8 ;
else
V_4 = V_4 -> V_9 ;
}
return NULL ;
}
static void F_3 ( struct V_1 * V_10 )
{
struct V_3 * * V_7 = & V_6 . V_3 ;
struct V_3 * V_11 = NULL ;
struct V_1 * V_12 ;
while ( * V_7 ) {
V_12 = F_2 ( * V_7 , struct V_1 , V_7 ) ;
V_11 = * V_7 ;
if ( V_10 -> V_2 < V_12 -> V_2 )
V_7 = & ( * V_7 ) -> V_8 ;
else if ( V_10 -> V_2 > V_12 -> V_2 )
V_7 = & ( * V_7 ) -> V_9 ;
else
F_4 ( L_1 ) ;
}
F_5 ( & V_10 -> V_7 , V_11 , V_7 ) ;
F_6 ( & V_10 -> V_7 , & V_6 ) ;
}
static struct V_1 * F_7 ( T_1 V_2 )
{
struct V_1 * V_5 ;
V_5 = F_1 ( V_2 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_8 ( sizeof( struct V_1 ) ) ;
if ( ! V_5 )
F_9 ( L_2 ) ;
V_5 -> V_2 = V_2 ;
F_10 ( & V_5 -> V_13 ) ;
F_3 ( V_5 ) ;
return V_5 ;
}
static struct V_1 * F_11 ( T_1 V_2 )
{
struct V_1 * V_5 ;
V_5 = F_8 ( sizeof( struct V_1 ) ) ;
if ( ! V_5 )
F_9 ( L_2 ) ;
V_5 -> V_2 = V_2 ;
F_10 ( & V_5 -> V_13 ) ;
F_5 ( & V_5 -> V_7 , NULL , & V_6 . V_3 ) ;
F_6 ( & V_5 -> V_7 , & V_6 ) ;
V_14 = F_7 ;
return V_5 ;
}
static int F_12 ( struct V_15 * V_16 ,
struct V_15 * V_17 )
{
T_2 V_18 = V_16 -> V_19 ;
T_2 V_20 = V_17 -> V_19 ;
if ( V_18 == V_21 )
V_18 = 0 ;
if ( V_20 == V_21 )
V_20 = 0 ;
return V_18 > V_20 ;
}
static void F_13 ( void )
{
int V_22 ;
for ( V_22 = 0 ; V_23 [ V_22 ] . V_24 ; V_22 ++ ) {
if ( ! strcmp ( V_23 [ V_22 ] . V_24 , V_25 ) ) {
V_26 = V_23 [ V_22 ] . V_27 ;
return;
}
}
F_9 ( L_3 , V_25 ) ;
}
static void F_14 ( struct V_15 * V_5 ,
int (* F_15)( struct V_15 * , struct V_15 * ) )
{
struct V_3 * * V_7 = & V_28 . V_3 ;
struct V_3 * V_11 = NULL ;
struct V_15 * V_12 ;
while ( * V_7 ) {
V_12 = F_2 ( * V_7 , struct V_15 , V_7 ) ;
V_11 = * V_7 ;
if ( F_15 ( V_5 , V_12 ) )
V_7 = & ( * V_7 ) -> V_8 ;
else
V_7 = & ( * V_7 ) -> V_9 ;
}
F_5 ( & V_5 -> V_7 , V_11 , V_7 ) ;
F_6 ( & V_5 -> V_7 , & V_28 ) ;
}
static struct V_15 * F_16 ( void )
{
struct V_3 * V_4 = V_28 . V_3 ;
if ( ! V_4 )
return NULL ;
while ( V_4 -> V_8 )
V_4 = V_4 -> V_8 ;
F_17 ( V_4 , & V_28 ) ;
return F_2 ( V_4 , struct V_15 , V_7 ) ;
}
static struct V_15 * F_18 ( void * V_29 , const char * V_24 )
{
struct V_30 * V_31 = F_19 ( V_29 ) ;
struct V_15 * V_32 , * V_10 ;
F_20 (ret, entry, hash_entry) {
if ( V_32 -> V_29 == V_29 )
return V_32 ;
}
V_10 = F_8 ( sizeof( struct V_15 ) ) ;
if ( ! V_10 )
goto V_33;
V_10 -> V_29 = V_29 ;
V_10 -> V_24 = F_8 ( sizeof( char ) * strlen ( V_24 ) + 1 ) ;
if ( ! V_10 -> V_24 )
goto V_33;
strcpy ( V_10 -> V_24 , V_24 ) ;
V_10 -> V_19 = V_21 ;
F_21 ( & V_10 -> V_34 , V_31 ) ;
return V_10 ;
V_33:
F_9 ( L_2 ) ;
}
static struct V_35 * F_22 ( struct V_1 * V_36 , void * V_29 )
{
struct V_35 * V_37 ;
F_20 (seq, &ts->seq_list, list) {
if ( V_37 -> V_29 == V_29 )
return V_37 ;
}
V_37 = F_8 ( sizeof( struct V_35 ) ) ;
if ( ! V_37 )
F_9 ( L_4 ) ;
V_37 -> V_38 = V_39 ;
V_37 -> V_29 = V_29 ;
F_21 ( & V_37 -> V_40 , & V_36 -> V_13 ) ;
return V_37 ;
}
static void
F_23 ( struct V_41 * V_42 ,
struct V_43 * T_3 V_44 ,
int T_4 V_44 ,
T_2 T_5 V_44 ,
struct V_45 * V_45 V_44 )
{
struct V_15 * V_46 ;
struct V_1 * V_36 ;
struct V_35 * V_37 ;
V_46 = F_18 ( V_42 -> V_29 , V_42 -> V_24 ) ;
if ( V_46 -> V_47 )
return;
V_36 = V_14 ( V_45 -> V_48 ) ;
V_37 = F_22 ( V_36 , V_42 -> V_29 ) ;
switch ( V_37 -> V_38 ) {
case V_39 :
case V_49 :
if ( ! V_42 -> V_50 ) {
V_37 -> V_38 = V_51 ;
} else {
if ( V_42 -> V_50 & V_52 )
V_46 -> V_53 ++ ;
if ( V_42 -> V_50 & V_54 )
V_46 -> V_55 ++ ;
V_37 -> V_38 = V_56 ;
V_37 -> V_57 = 1 ;
V_46 -> V_58 ++ ;
}
break;
case V_56 :
if ( V_42 -> V_50 & V_54 ) {
V_37 -> V_57 ++ ;
V_46 -> V_58 ++ ;
goto V_59;
} else {
goto V_60;
}
break;
case V_61 :
case V_51 :
case V_62 :
V_60:
V_46 -> V_47 = 1 ;
V_63 [ V_64 ] ++ ;
F_24 ( & V_37 -> V_40 ) ;
free ( V_37 ) ;
goto V_59;
break;
default:
F_4 ( L_5 ) ;
break;
}
V_46 -> V_65 ++ ;
V_37 -> V_66 = T_5 ;
V_59:
return;
}
static void
F_25 ( struct V_67 * V_68 ,
struct V_43 * T_3 V_44 ,
int T_4 V_44 ,
T_2 T_5 V_44 ,
struct V_45 * V_45 V_44 )
{
struct V_15 * V_46 ;
struct V_1 * V_36 ;
struct V_35 * V_37 ;
T_2 V_69 ;
V_46 = F_18 ( V_68 -> V_29 , V_68 -> V_24 ) ;
if ( V_46 -> V_47 )
return;
V_36 = V_14 ( V_45 -> V_48 ) ;
V_37 = F_22 ( V_36 , V_68 -> V_29 ) ;
switch ( V_37 -> V_38 ) {
case V_39 :
return;
case V_51 :
break;
case V_62 :
V_69 = T_5 - V_37 -> V_66 ;
V_46 -> V_70 += V_69 ;
if ( V_69 < V_46 -> V_19 )
V_46 -> V_19 = V_69 ;
if ( V_46 -> V_71 < V_69 )
V_46 -> V_71 = V_69 ;
break;
case V_49 :
case V_61 :
case V_56 :
V_46 -> V_47 = 1 ;
V_63 [ V_72 ] ++ ;
F_24 ( & V_37 -> V_40 ) ;
free ( V_37 ) ;
goto V_59;
break;
default:
F_4 ( L_5 ) ;
break;
}
V_37 -> V_38 = V_61 ;
V_46 -> V_58 ++ ;
V_37 -> V_66 = T_5 ;
V_59:
return;
}
static void
F_26 ( struct V_73 * V_74 ,
struct V_43 * T_3 V_44 ,
int T_4 V_44 ,
T_2 T_5 V_44 ,
struct V_45 * V_45 V_44 )
{
struct V_15 * V_46 ;
struct V_1 * V_36 ;
struct V_35 * V_37 ;
V_46 = F_18 ( V_74 -> V_29 , V_74 -> V_24 ) ;
if ( V_46 -> V_47 )
return;
V_36 = V_14 ( V_45 -> V_48 ) ;
V_37 = F_22 ( V_36 , V_74 -> V_29 ) ;
switch ( V_37 -> V_38 ) {
case V_39 :
return;
case V_51 :
break;
case V_49 :
case V_61 :
case V_56 :
case V_62 :
V_46 -> V_47 = 1 ;
V_63 [ V_75 ] ++ ;
F_24 ( & V_37 -> V_40 ) ;
free ( V_37 ) ;
goto V_59;
break;
default:
F_4 ( L_5 ) ;
break;
}
V_37 -> V_38 = V_62 ;
V_46 -> V_76 ++ ;
V_37 -> V_66 = T_5 ;
V_59:
return;
}
static void
F_27 ( struct V_77 * V_78 ,
struct V_43 * T_3 V_44 ,
int T_4 V_44 ,
T_2 T_5 V_44 ,
struct V_45 * V_45 V_44 )
{
struct V_15 * V_46 ;
struct V_1 * V_36 ;
struct V_35 * V_37 ;
V_46 = F_18 ( V_78 -> V_29 , V_78 -> V_24 ) ;
if ( V_46 -> V_47 )
return;
V_36 = V_14 ( V_45 -> V_48 ) ;
V_37 = F_22 ( V_36 , V_78 -> V_29 ) ;
switch ( V_37 -> V_38 ) {
case V_39 :
goto V_59;
break;
case V_61 :
break;
case V_56 :
V_37 -> V_57 -- ;
F_4 ( V_37 -> V_57 < 0 ) ;
if ( ! V_37 -> V_57 ) {
V_46 -> V_79 ++ ;
goto V_59;
}
break;
case V_51 :
case V_62 :
case V_49 :
V_46 -> V_47 = 1 ;
V_63 [ V_80 ] ++ ;
goto V_81;
break;
default:
F_4 ( L_5 ) ;
break;
}
V_46 -> V_79 ++ ;
V_81:
F_24 ( & V_37 -> V_40 ) ;
free ( V_37 ) ;
V_59:
return;
}
static void
F_28 ( void * V_82 ,
struct V_43 * T_6 V_44 ,
int T_4 V_44 ,
T_2 T_5 V_44 ,
struct V_45 * V_45 V_44 )
{
struct V_41 V_42 ;
T_2 V_83 ;
V_83 = F_29 ( T_6 , L_6 , V_82 ) ;
memcpy ( & V_42 . V_29 , & V_83 , sizeof( void * ) ) ;
V_42 . V_24 = ( char * ) F_30 ( T_6 , L_7 , V_82 ) ;
V_42 . V_50 = ( int ) F_29 ( T_6 , L_8 , V_82 ) ;
if ( V_84 -> V_42 )
V_84 -> V_42 ( & V_42 , T_6 , T_4 , T_5 , V_45 ) ;
}
static void
F_31 ( void * V_82 ,
struct V_43 * T_6 V_44 ,
int T_4 V_44 ,
T_2 T_5 V_44 ,
struct V_45 * V_45 V_44 )
{
struct V_67 V_68 ;
T_2 V_83 ;
V_83 = F_29 ( T_6 , L_6 , V_82 ) ;
memcpy ( & V_68 . V_29 , & V_83 , sizeof( void * ) ) ;
V_68 . V_24 = ( char * ) F_30 ( T_6 , L_7 , V_82 ) ;
if ( V_84 -> V_42 )
V_84 -> V_68 ( & V_68 , T_6 , T_4 , T_5 , V_45 ) ;
}
static void
F_32 ( void * V_82 ,
struct V_43 * T_6 V_44 ,
int T_4 V_44 ,
T_2 T_5 V_44 ,
struct V_45 * V_45 V_44 )
{
struct V_73 V_74 ;
T_2 V_83 ;
V_83 = F_29 ( T_6 , L_6 , V_82 ) ;
memcpy ( & V_74 . V_29 , & V_83 , sizeof( void * ) ) ;
V_74 . V_24 = ( char * ) F_30 ( T_6 , L_7 , V_82 ) ;
if ( V_84 -> V_42 )
V_84 -> V_74 ( & V_74 , T_6 , T_4 , T_5 , V_45 ) ;
}
static void
F_33 ( void * V_82 ,
struct V_43 * T_6 V_44 ,
int T_4 V_44 ,
T_2 T_5 V_44 ,
struct V_45 * V_45 V_44 )
{
struct V_77 V_78 ;
T_2 V_83 ;
V_83 = F_29 ( T_6 , L_6 , V_82 ) ;
memcpy ( & V_78 . V_29 , & V_83 , sizeof( void * ) ) ;
V_78 . V_24 = ( char * ) F_30 ( T_6 , L_7 , V_82 ) ;
if ( V_84 -> V_42 )
V_84 -> V_78 ( & V_78 , T_6 , T_4 , T_5 , V_45 ) ;
}
static void
F_34 ( void * V_82 , int T_4 , T_2 T_5 , struct V_45 * V_45 )
{
struct V_43 * T_6 ;
int type ;
type = F_35 ( V_85 -> V_86 , V_82 ) ;
T_6 = F_36 ( V_85 -> V_86 , type ) ;
if ( ! strcmp ( T_6 -> V_24 , L_9 ) )
F_28 ( V_82 , T_6 , T_4 , T_5 , V_45 ) ;
if ( ! strcmp ( T_6 -> V_24 , L_10 ) )
F_31 ( V_82 , T_6 , T_4 , T_5 , V_45 ) ;
if ( ! strcmp ( T_6 -> V_24 , L_11 ) )
F_32 ( V_82 , T_6 , T_4 , T_5 , V_45 ) ;
if ( ! strcmp ( T_6 -> V_24 , L_12 ) )
F_33 ( V_82 , T_6 , T_4 , T_5 , V_45 ) ;
}
static void F_37 ( int V_87 , int V_88 )
{
int V_22 ;
const char * V_24 [ 4 ] =
{ L_13 , L_14 , L_15 , L_16 } ;
F_38 ( L_17 ) ;
F_38 ( L_18 , V_87 , V_88 ) ;
F_38 ( L_19 , ( double ) V_87 / ( double ) V_88 * 100 ) ;
F_38 ( L_20 ) ;
for ( V_22 = 0 ; V_22 < V_89 ; V_22 ++ )
F_38 ( L_21 , V_24 [ V_22 ] , V_63 [ V_22 ] ) ;
}
static void F_39 ( void )
{
struct V_15 * V_5 ;
char V_90 [ 20 ] ;
int V_87 , V_88 ;
F_38 ( L_22 , L_23 ) ;
F_38 ( L_24 , L_14 ) ;
F_38 ( L_24 , L_15 ) ;
F_38 ( L_25 , L_26 ) ;
F_38 ( L_25 , L_27 ) ;
F_38 ( L_25 , L_28 ) ;
F_38 ( L_29 ) ;
V_87 = V_88 = 0 ;
while ( ( V_5 = F_16 () ) ) {
V_88 ++ ;
if ( V_5 -> V_47 ) {
V_87 ++ ;
continue;
}
F_40 ( V_90 , 20 ) ;
if ( strlen ( V_5 -> V_24 ) < 16 ) {
F_38 ( L_22 , V_5 -> V_24 ) ;
} else {
strncpy ( V_90 , V_5 -> V_24 , 16 ) ;
V_90 [ 16 ] = '.' ;
V_90 [ 17 ] = '.' ;
V_90 [ 18 ] = '.' ;
V_90 [ 19 ] = '\0' ;
F_38 ( L_22 , V_90 ) ;
}
F_38 ( L_30 , V_5 -> V_58 ) ;
F_38 ( L_30 , V_5 -> V_76 ) ;
F_38 ( L_31 V_91 L_32 , V_5 -> V_70 ) ;
F_38 ( L_31 V_91 L_32 , V_5 -> V_71 ) ;
F_38 ( L_31 V_91 L_32 , V_5 -> V_19 == V_21 ?
0 : V_5 -> V_19 ) ;
F_38 ( L_33 ) ;
}
F_37 ( V_87 , V_88 ) ;
}
static void F_41 ( void )
{
struct V_1 * V_5 ;
struct V_3 * V_4 ;
struct V_45 * V_92 ;
F_38 ( L_34 , L_35 ) ;
V_4 = F_42 ( & V_6 ) ;
while ( V_4 ) {
V_5 = F_2 ( V_4 , struct V_1 , V_7 ) ;
V_92 = F_43 ( V_85 , V_5 -> V_2 ) ;
F_38 ( L_36 , V_5 -> V_2 , V_92 -> V_93 ) ;
V_4 = F_44 ( V_4 ) ;
} ;
}
static void F_45 ( void )
{
unsigned int V_22 ;
struct V_15 * V_5 ;
F_38 ( L_37 ) ;
for ( V_22 = 0 ; V_22 < V_94 ; V_22 ++ ) {
F_20 (st, &lockhash_table[i], hash_entry) {
F_38 ( L_38 , V_5 -> V_29 , V_5 -> V_24 ) ;
}
}
}
static void F_46 ( void )
{
if ( V_95 )
F_41 () ;
else if ( V_96 )
F_45 () ;
else
F_9 ( L_39 ) ;
}
static int F_47 ( struct V_97 * T_7 V_44 ,
union V_98 * T_6 ,
struct V_99 * V_100 ,
struct V_101 * T_8 V_44 ,
struct V_102 * V_102 )
{
struct V_45 * V_45 = F_48 ( V_102 , V_100 -> V_2 ) ;
if ( V_45 == NULL ) {
F_49 ( L_40 ,
T_6 -> V_103 . type ) ;
return - 1 ;
}
F_34 ( V_100 -> V_104 , V_100 -> T_4 , V_100 -> time , V_45 ) ;
return 0 ;
}
static int F_50 ( void )
{
V_85 = F_51 ( V_105 , V_106 , 0 , false , & V_107 ) ;
if ( ! V_85 )
F_9 ( L_41 ) ;
return F_52 ( V_85 , & V_107 ) ;
}
static void F_53 ( void )
{
unsigned int V_22 ;
struct V_15 * V_5 ;
for ( V_22 = 0 ; V_22 < V_94 ; V_22 ++ ) {
F_20 (st, &lockhash_table[i], hash_entry) {
F_14 ( V_5 , V_26 ) ;
}
}
}
static void F_54 ( void )
{
F_55 () ;
F_13 () ;
F_50 () ;
F_53 () ;
F_39 () ;
}
static int F_56 ( int V_108 , const char * * V_109 )
{
unsigned int V_110 , V_22 , V_111 ;
const char * * V_112 ;
V_110 = F_57 ( V_113 ) + V_108 - 1 ;
V_112 = calloc ( V_110 + 1 , sizeof( char * ) ) ;
if ( V_112 == NULL )
return - V_114 ;
for ( V_22 = 0 ; V_22 < F_57 ( V_113 ) ; V_22 ++ )
V_112 [ V_22 ] = F_58 ( V_113 [ V_22 ] ) ;
for ( V_111 = 1 ; V_111 < ( unsigned int ) V_108 ; V_111 ++ , V_22 ++ )
V_112 [ V_22 ] = V_109 [ V_111 ] ;
F_4 ( V_22 != V_110 ) ;
return F_59 ( V_22 , V_112 , NULL ) ;
}
int F_60 ( int V_108 , const char * * V_109 , const char * T_9 V_44 )
{
unsigned int V_22 ;
F_61 () ;
for ( V_22 = 0 ; V_22 < V_94 ; V_22 ++ )
F_10 ( V_115 + V_22 ) ;
V_108 = F_62 ( V_108 , V_109 , V_116 , V_117 ,
V_118 ) ;
if ( ! V_108 )
F_63 ( V_117 , V_116 ) ;
if ( ! strncmp ( V_109 [ 0 ] , L_42 , 3 ) ) {
return F_56 ( V_108 , V_109 ) ;
} else if ( ! strncmp ( V_109 [ 0 ] , L_43 , 6 ) ) {
V_84 = & V_119 ;
if ( V_108 ) {
V_108 = F_62 ( V_108 , V_109 ,
V_120 , V_121 , 0 ) ;
if ( V_108 )
F_63 ( V_121 , V_120 ) ;
}
F_54 () ;
} else if ( ! strcmp ( V_109 [ 0 ] , L_44 ) ) {
return F_64 ( V_108 , V_109 , T_9 ) ;
} else if ( ! strcmp ( V_109 [ 0 ] , L_45 ) ) {
if ( V_108 ) {
V_108 = F_62 ( V_108 , V_109 ,
V_122 , V_123 , 0 ) ;
if ( V_108 )
F_63 ( V_123 , V_122 ) ;
}
V_84 = & V_119 ;
F_55 () ;
F_50 () ;
F_46 () ;
} else {
F_63 ( V_117 , V_116 ) ;
}
return 0 ;
}
