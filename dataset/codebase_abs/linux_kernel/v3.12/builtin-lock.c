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
if ( ! V_5 ) {
F_9 ( L_2 ) ;
return NULL ;
}
V_5 -> V_2 = V_2 ;
F_10 ( & V_5 -> V_13 ) ;
F_3 ( V_5 ) ;
return V_5 ;
}
static struct V_1 * F_11 ( T_1 V_2 )
{
struct V_1 * V_5 ;
V_5 = F_8 ( sizeof( struct V_1 ) ) ;
if ( ! V_5 ) {
F_9 ( L_2 ) ;
return NULL ;
}
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
static int F_13 ( void )
{
int V_22 ;
for ( V_22 = 0 ; V_23 [ V_22 ] . V_24 ; V_22 ++ ) {
if ( ! strcmp ( V_23 [ V_22 ] . V_24 , V_25 ) ) {
V_26 = V_23 [ V_22 ] . V_27 ;
return 0 ;
}
}
F_9 ( L_3 , V_25 ) ;
return - 1 ;
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
return NULL ;
}
static struct V_35 * F_22 ( struct V_1 * V_36 , void * V_29 )
{
struct V_35 * V_37 ;
F_20 (seq, &ts->seq_list, list) {
if ( V_37 -> V_29 == V_29 )
return V_37 ;
}
V_37 = F_8 ( sizeof( struct V_35 ) ) ;
if ( ! V_37 ) {
F_9 ( L_2 ) ;
return NULL ;
}
V_37 -> V_38 = V_39 ;
V_37 -> V_29 = V_29 ;
F_21 ( & V_37 -> V_40 , & V_36 -> V_13 ) ;
return V_37 ;
}
static int F_23 ( struct V_41 * V_42 ,
struct V_43 * V_44 )
{
void * V_29 ;
struct V_15 * V_45 ;
struct V_1 * V_36 ;
struct V_35 * V_37 ;
const char * V_24 = F_24 ( V_42 , V_44 , L_4 ) ;
T_2 V_46 = F_25 ( V_42 , V_44 , L_5 ) ;
int V_47 = F_25 ( V_42 , V_44 , L_6 ) ;
memcpy ( & V_29 , & V_46 , sizeof( void * ) ) ;
V_45 = F_18 ( V_29 , V_24 ) ;
if ( ! V_45 )
return - 1 ;
if ( V_45 -> V_48 )
return 0 ;
V_36 = V_14 ( V_44 -> V_2 ) ;
if ( ! V_36 )
return - 1 ;
V_37 = F_22 ( V_36 , V_29 ) ;
if ( ! V_37 )
return - 1 ;
switch ( V_37 -> V_38 ) {
case V_39 :
case V_49 :
if ( ! V_47 ) {
V_37 -> V_38 = V_50 ;
} else {
if ( V_47 & V_51 )
V_45 -> V_52 ++ ;
if ( V_47 & V_53 )
V_45 -> V_54 ++ ;
V_37 -> V_38 = V_55 ;
V_37 -> V_56 = 1 ;
V_45 -> V_57 ++ ;
}
break;
case V_55 :
if ( V_47 & V_53 ) {
V_37 -> V_56 ++ ;
V_45 -> V_57 ++ ;
goto V_58;
} else {
goto V_59;
}
break;
case V_60 :
case V_50 :
case V_61 :
V_59:
V_45 -> V_48 = 1 ;
V_62 [ V_63 ] ++ ;
F_26 ( & V_37 -> V_40 ) ;
free ( V_37 ) ;
goto V_58;
break;
default:
F_4 ( L_7 ) ;
break;
}
V_45 -> V_64 ++ ;
V_37 -> V_65 = V_44 -> time ;
V_58:
return 0 ;
}
static int F_27 ( struct V_41 * V_42 ,
struct V_43 * V_44 )
{
void * V_29 ;
struct V_15 * V_45 ;
struct V_1 * V_36 ;
struct V_35 * V_37 ;
T_2 V_66 ;
const char * V_24 = F_24 ( V_42 , V_44 , L_4 ) ;
T_2 V_46 = F_25 ( V_42 , V_44 , L_5 ) ;
memcpy ( & V_29 , & V_46 , sizeof( void * ) ) ;
V_45 = F_18 ( V_29 , V_24 ) ;
if ( ! V_45 )
return - 1 ;
if ( V_45 -> V_48 )
return 0 ;
V_36 = V_14 ( V_44 -> V_2 ) ;
if ( ! V_36 )
return - 1 ;
V_37 = F_22 ( V_36 , V_29 ) ;
if ( ! V_37 )
return - 1 ;
switch ( V_37 -> V_38 ) {
case V_39 :
return 0 ;
case V_50 :
break;
case V_61 :
V_66 = V_44 -> time - V_37 -> V_65 ;
V_45 -> V_67 += V_66 ;
if ( V_66 < V_45 -> V_19 )
V_45 -> V_19 = V_66 ;
if ( V_45 -> V_68 < V_66 )
V_45 -> V_68 = V_66 ;
break;
case V_49 :
case V_60 :
case V_55 :
V_45 -> V_48 = 1 ;
V_62 [ V_69 ] ++ ;
F_26 ( & V_37 -> V_40 ) ;
free ( V_37 ) ;
goto V_58;
break;
default:
F_4 ( L_7 ) ;
break;
}
V_37 -> V_38 = V_60 ;
V_45 -> V_57 ++ ;
V_37 -> V_65 = V_44 -> time ;
V_58:
return 0 ;
}
static int F_28 ( struct V_41 * V_42 ,
struct V_43 * V_44 )
{
void * V_29 ;
struct V_15 * V_45 ;
struct V_1 * V_36 ;
struct V_35 * V_37 ;
const char * V_24 = F_24 ( V_42 , V_44 , L_4 ) ;
T_2 V_46 = F_25 ( V_42 , V_44 , L_5 ) ;
memcpy ( & V_29 , & V_46 , sizeof( void * ) ) ;
V_45 = F_18 ( V_29 , V_24 ) ;
if ( ! V_45 )
return - 1 ;
if ( V_45 -> V_48 )
return 0 ;
V_36 = V_14 ( V_44 -> V_2 ) ;
if ( ! V_36 )
return - 1 ;
V_37 = F_22 ( V_36 , V_29 ) ;
if ( ! V_37 )
return - 1 ;
switch ( V_37 -> V_38 ) {
case V_39 :
return 0 ;
case V_50 :
break;
case V_49 :
case V_60 :
case V_55 :
case V_61 :
V_45 -> V_48 = 1 ;
V_62 [ V_70 ] ++ ;
F_26 ( & V_37 -> V_40 ) ;
free ( V_37 ) ;
goto V_58;
break;
default:
F_4 ( L_7 ) ;
break;
}
V_37 -> V_38 = V_61 ;
V_45 -> V_71 ++ ;
V_37 -> V_65 = V_44 -> time ;
V_58:
return 0 ;
}
static int F_29 ( struct V_41 * V_42 ,
struct V_43 * V_44 )
{
void * V_29 ;
struct V_15 * V_45 ;
struct V_1 * V_36 ;
struct V_35 * V_37 ;
const char * V_24 = F_24 ( V_42 , V_44 , L_4 ) ;
T_2 V_46 = F_25 ( V_42 , V_44 , L_5 ) ;
memcpy ( & V_29 , & V_46 , sizeof( void * ) ) ;
V_45 = F_18 ( V_29 , V_24 ) ;
if ( ! V_45 )
return - 1 ;
if ( V_45 -> V_48 )
return 0 ;
V_36 = V_14 ( V_44 -> V_2 ) ;
if ( ! V_36 )
return - 1 ;
V_37 = F_22 ( V_36 , V_29 ) ;
if ( ! V_37 )
return - 1 ;
switch ( V_37 -> V_38 ) {
case V_39 :
goto V_58;
break;
case V_60 :
break;
case V_55 :
V_37 -> V_56 -- ;
F_4 ( V_37 -> V_56 < 0 ) ;
if ( ! V_37 -> V_56 ) {
V_45 -> V_72 ++ ;
goto V_58;
}
break;
case V_50 :
case V_61 :
case V_49 :
V_45 -> V_48 = 1 ;
V_62 [ V_73 ] ++ ;
goto V_74;
break;
default:
F_4 ( L_7 ) ;
break;
}
V_45 -> V_72 ++ ;
V_74:
F_26 ( & V_37 -> V_40 ) ;
free ( V_37 ) ;
V_58:
return 0 ;
}
static int F_30 ( struct V_41 * V_42 ,
struct V_43 * V_44 )
{
if ( V_75 -> V_76 )
return V_75 -> V_76 ( V_42 , V_44 ) ;
return 0 ;
}
static int F_31 ( struct V_41 * V_42 ,
struct V_43 * V_44 )
{
if ( V_75 -> V_77 )
return V_75 -> V_77 ( V_42 , V_44 ) ;
return 0 ;
}
static int F_32 ( struct V_41 * V_42 ,
struct V_43 * V_44 )
{
if ( V_75 -> V_78 )
return V_75 -> V_78 ( V_42 , V_44 ) ;
return 0 ;
}
static int F_33 ( struct V_41 * V_42 ,
struct V_43 * V_44 )
{
if ( V_75 -> V_79 )
return V_75 -> V_79 ( V_42 , V_44 ) ;
return 0 ;
}
static void F_34 ( int V_80 , int V_81 )
{
int V_22 ;
const char * V_24 [ 4 ] =
{ L_8 , L_9 , L_10 , L_11 } ;
F_35 ( L_12 ) ;
F_35 ( L_13 , V_80 , V_81 ) ;
F_35 ( L_14 , ( double ) V_80 / ( double ) V_81 * 100 ) ;
F_35 ( L_15 ) ;
for ( V_22 = 0 ; V_22 < V_82 ; V_22 ++ )
F_35 ( L_16 , V_24 [ V_22 ] , V_62 [ V_22 ] ) ;
}
static void F_36 ( void )
{
struct V_15 * V_5 ;
char V_83 [ 20 ] ;
int V_80 , V_81 ;
F_35 ( L_17 , L_18 ) ;
F_35 ( L_19 , L_9 ) ;
F_35 ( L_19 , L_10 ) ;
F_35 ( L_20 , L_21 ) ;
F_35 ( L_20 , L_22 ) ;
F_35 ( L_20 , L_23 ) ;
F_35 ( L_24 ) ;
V_80 = V_81 = 0 ;
while ( ( V_5 = F_16 () ) ) {
V_81 ++ ;
if ( V_5 -> V_48 ) {
V_80 ++ ;
continue;
}
F_37 ( V_83 , 20 ) ;
if ( strlen ( V_5 -> V_24 ) < 16 ) {
F_35 ( L_17 , V_5 -> V_24 ) ;
} else {
strncpy ( V_83 , V_5 -> V_24 , 16 ) ;
V_83 [ 16 ] = '.' ;
V_83 [ 17 ] = '.' ;
V_83 [ 18 ] = '.' ;
V_83 [ 19 ] = '\0' ;
F_35 ( L_17 , V_83 ) ;
}
F_35 ( L_25 , V_5 -> V_57 ) ;
F_35 ( L_25 , V_5 -> V_71 ) ;
F_35 ( L_26 V_84 L_27 , V_5 -> V_67 ) ;
F_35 ( L_26 V_84 L_27 , V_5 -> V_68 ) ;
F_35 ( L_26 V_84 L_27 , V_5 -> V_19 == V_21 ?
0 : V_5 -> V_19 ) ;
F_35 ( L_28 ) ;
}
F_34 ( V_80 , V_81 ) ;
}
static void F_38 ( void )
{
struct V_1 * V_5 ;
struct V_3 * V_4 ;
struct V_85 * V_86 ;
F_35 ( L_29 , L_30 ) ;
V_4 = F_39 ( & V_6 ) ;
while ( V_4 ) {
V_5 = F_2 ( V_4 , struct V_1 , V_7 ) ;
V_86 = F_40 ( V_87 , V_5 -> V_2 ) ;
F_35 ( L_31 , V_5 -> V_2 , V_86 -> V_88 ) ;
V_4 = F_41 ( V_4 ) ;
} ;
}
static void F_42 ( void )
{
unsigned int V_22 ;
struct V_15 * V_5 ;
F_35 ( L_32 ) ;
for ( V_22 = 0 ; V_22 < V_89 ; V_22 ++ ) {
F_20 (st, &lockhash_table[i], hash_entry) {
F_35 ( L_33 , V_5 -> V_29 , V_5 -> V_24 ) ;
}
}
}
static int F_43 ( void )
{
int V_90 = 0 ;
if ( V_91 )
F_38 () ;
else if ( V_92 )
F_42 () ;
else {
V_90 = - 1 ;
F_9 ( L_34 ) ;
}
return V_90 ;
}
static int F_44 ( struct V_93 * T_3 V_94 ,
union V_95 * V_96 ,
struct V_43 * V_44 ,
struct V_41 * V_42 ,
struct V_97 * V_97 )
{
struct V_85 * V_85 = F_45 ( V_97 , V_44 -> V_98 ,
V_44 -> V_2 ) ;
if ( V_85 == NULL ) {
F_46 ( L_35 ,
V_96 -> V_99 . type ) ;
return - 1 ;
}
if ( V_42 -> V_100 . V_101 != NULL ) {
T_4 V_102 = V_42 -> V_100 . V_101 ;
return V_102 ( V_42 , V_44 ) ;
}
return 0 ;
}
static int F_47 ( void )
{
struct V_93 V_103 = {
. V_44 = F_44 ,
. V_88 = V_104 ,
. V_105 = true ,
} ;
V_87 = F_48 ( V_106 , V_107 , 0 , false , & V_103 ) ;
if ( ! V_87 ) {
F_9 ( L_36 ) ;
return - 1 ;
}
if ( F_49 ( V_87 , V_108 ) ) {
F_9 ( L_37 ) ;
return - 1 ;
}
return F_50 ( V_87 , & V_103 ) ;
}
static void F_51 ( void )
{
unsigned int V_22 ;
struct V_15 * V_5 ;
for ( V_22 = 0 ; V_22 < V_89 ; V_22 ++ ) {
F_20 (st, &lockhash_table[i], hash_entry) {
F_14 ( V_5 , V_26 ) ;
}
}
}
static int F_52 ( void )
{
F_53 () ;
if ( ( F_13 () != 0 ) ||
( F_47 () != 0 ) )
return - 1 ;
F_51 () ;
F_36 () ;
return 0 ;
}
static int F_54 ( int V_109 , const char * * V_110 )
{
const char * V_111 [] = {
L_38 , L_39 , L_40 , L_41 , L_42 , L_43 ,
} ;
unsigned int V_112 , V_22 , V_113 ;
const char * * V_114 ;
for ( V_22 = 0 ; V_22 < F_55 ( V_108 ) ; V_22 ++ ) {
if ( ! F_56 ( V_108 [ V_22 ] . V_24 ) ) {
F_9 ( L_44
L_45 ,
V_108 [ V_22 ] . V_24 ) ;
return 1 ;
}
}
V_112 = F_55 ( V_111 ) + V_109 - 1 ;
V_112 += 2 * F_55 ( V_108 ) ;
V_114 = calloc ( V_112 + 1 , sizeof( char * ) ) ;
if ( V_114 == NULL )
return - V_115 ;
for ( V_22 = 0 ; V_22 < F_55 ( V_111 ) ; V_22 ++ )
V_114 [ V_22 ] = F_57 ( V_111 [ V_22 ] ) ;
for ( V_113 = 0 ; V_113 < F_55 ( V_108 ) ; V_113 ++ ) {
V_114 [ V_22 ++ ] = L_46 ;
V_114 [ V_22 ++ ] = F_57 ( V_108 [ V_113 ] . V_24 ) ;
}
for ( V_113 = 1 ; V_113 < ( unsigned int ) V_109 ; V_113 ++ , V_22 ++ )
V_114 [ V_22 ] = V_110 [ V_113 ] ;
F_4 ( V_22 != V_112 ) ;
return F_58 ( V_22 , V_114 , NULL ) ;
}
int F_59 ( int V_109 , const char * * V_110 , const char * T_5 V_94 )
{
const struct V_116 V_117 [] = {
F_60 ( 't' , L_47 , & V_91 ,
L_48 ) ,
F_60 ( 'm' , L_49 , & V_92 ,
L_50 ) ,
F_61 ()
} ;
const struct V_116 V_118 [] = {
F_62 ( 'i' , L_51 , & V_106 , L_52 , L_53 ) ,
F_63 ( 'v' , L_54 , & V_119 , L_55 ) ,
F_60 ( 'D' , L_56 , & V_120 , L_57 ) ,
F_61 ()
} ;
const struct V_116 V_121 [] = {
F_62 ( 'k' , L_58 , & V_25 , L_9 ,
L_59 ) ,
F_61 ()
} ;
const char * const V_122 [] = {
L_60 ,
NULL
} ;
const char * const V_123 [] = {
L_61 ,
NULL
} ;
const char * const V_124 [] = {
L_62 ,
NULL
} ;
unsigned int V_22 ;
int V_90 = 0 ;
F_64 () ;
for ( V_22 = 0 ; V_22 < V_89 ; V_22 ++ )
F_10 ( V_125 + V_22 ) ;
V_109 = F_65 ( V_109 , V_110 , V_118 , V_123 ,
V_126 ) ;
if ( ! V_109 )
F_66 ( V_123 , V_118 ) ;
if ( ! strncmp ( V_110 [ 0 ] , L_63 , 3 ) ) {
return F_54 ( V_109 , V_110 ) ;
} else if ( ! strncmp ( V_110 [ 0 ] , L_64 , 6 ) ) {
V_75 = & V_127 ;
if ( V_109 ) {
V_109 = F_65 ( V_109 , V_110 ,
V_121 , V_124 , 0 ) ;
if ( V_109 )
F_66 ( V_124 , V_121 ) ;
}
F_52 () ;
} else if ( ! strcmp ( V_110 [ 0 ] , L_65 ) ) {
return F_67 ( V_109 , V_110 , T_5 ) ;
} else if ( ! strcmp ( V_110 [ 0 ] , L_66 ) ) {
if ( V_109 ) {
V_109 = F_65 ( V_109 , V_110 ,
V_117 , V_122 , 0 ) ;
if ( V_109 )
F_66 ( V_122 , V_117 ) ;
}
V_75 = & V_127 ;
F_53 () ;
if ( F_47 () != 0 )
V_90 = - 1 ;
else
V_90 = F_43 () ;
} else {
F_66 ( V_123 , V_118 ) ;
}
return V_90 ;
}
