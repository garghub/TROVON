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
if ( ! V_10 -> V_24 ) {
free ( V_10 ) ;
goto V_33;
}
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
return - V_48 ;
if ( V_45 -> V_49 )
return 0 ;
V_36 = V_14 ( V_44 -> V_2 ) ;
if ( ! V_36 )
return - V_48 ;
V_37 = F_22 ( V_36 , V_29 ) ;
if ( ! V_37 )
return - V_48 ;
switch ( V_37 -> V_38 ) {
case V_39 :
case V_50 :
if ( ! V_47 ) {
V_37 -> V_38 = V_51 ;
} else {
if ( V_47 & V_52 )
V_45 -> V_53 ++ ;
if ( V_47 & V_54 )
V_45 -> V_55 ++ ;
V_37 -> V_38 = V_56 ;
V_37 -> V_57 = 1 ;
V_45 -> V_58 ++ ;
}
break;
case V_56 :
if ( V_47 & V_54 ) {
V_37 -> V_57 ++ ;
V_45 -> V_58 ++ ;
goto V_59;
} else {
goto V_60;
}
break;
case V_61 :
case V_51 :
case V_62 :
V_60:
V_45 -> V_49 = 1 ;
V_63 [ V_64 ] ++ ;
F_26 ( & V_37 -> V_40 ) ;
free ( V_37 ) ;
goto V_59;
default:
F_4 ( L_7 ) ;
break;
}
V_45 -> V_65 ++ ;
V_37 -> V_66 = V_44 -> time ;
V_59:
return 0 ;
}
static int F_27 ( struct V_41 * V_42 ,
struct V_43 * V_44 )
{
void * V_29 ;
struct V_15 * V_45 ;
struct V_1 * V_36 ;
struct V_35 * V_37 ;
T_2 V_67 ;
const char * V_24 = F_24 ( V_42 , V_44 , L_4 ) ;
T_2 V_46 = F_25 ( V_42 , V_44 , L_5 ) ;
memcpy ( & V_29 , & V_46 , sizeof( void * ) ) ;
V_45 = F_18 ( V_29 , V_24 ) ;
if ( ! V_45 )
return - V_48 ;
if ( V_45 -> V_49 )
return 0 ;
V_36 = V_14 ( V_44 -> V_2 ) ;
if ( ! V_36 )
return - V_48 ;
V_37 = F_22 ( V_36 , V_29 ) ;
if ( ! V_37 )
return - V_48 ;
switch ( V_37 -> V_38 ) {
case V_39 :
return 0 ;
case V_51 :
break;
case V_62 :
V_67 = V_44 -> time - V_37 -> V_66 ;
V_45 -> V_68 += V_67 ;
if ( V_67 < V_45 -> V_19 )
V_45 -> V_19 = V_67 ;
if ( V_45 -> V_69 < V_67 )
V_45 -> V_69 = V_67 ;
break;
case V_50 :
case V_61 :
case V_56 :
V_45 -> V_49 = 1 ;
V_63 [ V_70 ] ++ ;
F_26 ( & V_37 -> V_40 ) ;
free ( V_37 ) ;
goto V_59;
default:
F_4 ( L_7 ) ;
break;
}
V_37 -> V_38 = V_61 ;
V_45 -> V_58 ++ ;
V_45 -> V_71 = V_45 -> V_72 ? V_45 -> V_68 / V_45 -> V_72 : 0 ;
V_37 -> V_66 = V_44 -> time ;
V_59:
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
return - V_48 ;
if ( V_45 -> V_49 )
return 0 ;
V_36 = V_14 ( V_44 -> V_2 ) ;
if ( ! V_36 )
return - V_48 ;
V_37 = F_22 ( V_36 , V_29 ) ;
if ( ! V_37 )
return - V_48 ;
switch ( V_37 -> V_38 ) {
case V_39 :
return 0 ;
case V_51 :
break;
case V_50 :
case V_61 :
case V_56 :
case V_62 :
V_45 -> V_49 = 1 ;
V_63 [ V_73 ] ++ ;
F_26 ( & V_37 -> V_40 ) ;
free ( V_37 ) ;
goto V_59;
default:
F_4 ( L_7 ) ;
break;
}
V_37 -> V_38 = V_62 ;
V_45 -> V_72 ++ ;
V_45 -> V_71 = V_45 -> V_68 / V_45 -> V_72 ;
V_37 -> V_66 = V_44 -> time ;
V_59:
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
return - V_48 ;
if ( V_45 -> V_49 )
return 0 ;
V_36 = V_14 ( V_44 -> V_2 ) ;
if ( ! V_36 )
return - V_48 ;
V_37 = F_22 ( V_36 , V_29 ) ;
if ( ! V_37 )
return - V_48 ;
switch ( V_37 -> V_38 ) {
case V_39 :
goto V_59;
case V_61 :
break;
case V_56 :
V_37 -> V_57 -- ;
F_4 ( V_37 -> V_57 < 0 ) ;
if ( ! V_37 -> V_57 ) {
V_45 -> V_74 ++ ;
goto V_59;
}
break;
case V_51 :
case V_62 :
case V_50 :
V_45 -> V_49 = 1 ;
V_63 [ V_75 ] ++ ;
goto V_76;
default:
F_4 ( L_7 ) ;
break;
}
V_45 -> V_74 ++ ;
V_76:
F_26 ( & V_37 -> V_40 ) ;
free ( V_37 ) ;
V_59:
return 0 ;
}
static int F_30 ( struct V_41 * V_42 ,
struct V_43 * V_44 )
{
if ( V_77 -> V_78 )
return V_77 -> V_78 ( V_42 , V_44 ) ;
return 0 ;
}
static int F_31 ( struct V_41 * V_42 ,
struct V_43 * V_44 )
{
if ( V_77 -> V_79 )
return V_77 -> V_79 ( V_42 , V_44 ) ;
return 0 ;
}
static int F_32 ( struct V_41 * V_42 ,
struct V_43 * V_44 )
{
if ( V_77 -> V_80 )
return V_77 -> V_80 ( V_42 , V_44 ) ;
return 0 ;
}
static int F_33 ( struct V_41 * V_42 ,
struct V_43 * V_44 )
{
if ( V_77 -> V_81 )
return V_77 -> V_81 ( V_42 , V_44 ) ;
return 0 ;
}
static void F_34 ( int V_82 , int V_83 )
{
int V_22 ;
const char * V_24 [ 4 ] =
{ L_8 , L_9 , L_10 , L_11 } ;
F_35 ( L_12 ) ;
F_35 ( L_13 , V_82 , V_83 ) ;
F_35 ( L_14 , ( double ) V_82 / ( double ) V_83 * 100 ) ;
F_35 ( L_15 ) ;
for ( V_22 = 0 ; V_22 < V_84 ; V_22 ++ )
F_35 ( L_16 , V_24 [ V_22 ] , V_63 [ V_22 ] ) ;
}
static void F_36 ( void )
{
struct V_15 * V_5 ;
char V_85 [ 20 ] ;
int V_82 , V_83 ;
F_35 ( L_17 , L_18 ) ;
F_35 ( L_19 , L_9 ) ;
F_35 ( L_19 , L_10 ) ;
F_35 ( L_20 , L_21 ) ;
F_35 ( L_20 , L_22 ) ;
F_35 ( L_20 , L_23 ) ;
F_35 ( L_20 , L_24 ) ;
F_35 ( L_25 ) ;
V_82 = V_83 = 0 ;
while ( ( V_5 = F_16 () ) ) {
V_83 ++ ;
if ( V_5 -> V_49 ) {
V_82 ++ ;
continue;
}
F_37 ( V_85 , 20 ) ;
if ( strlen ( V_5 -> V_24 ) < 16 ) {
F_35 ( L_17 , V_5 -> V_24 ) ;
} else {
strncpy ( V_85 , V_5 -> V_24 , 16 ) ;
V_85 [ 16 ] = '.' ;
V_85 [ 17 ] = '.' ;
V_85 [ 18 ] = '.' ;
V_85 [ 19 ] = '\0' ;
F_35 ( L_17 , V_85 ) ;
}
F_35 ( L_26 , V_5 -> V_58 ) ;
F_35 ( L_26 , V_5 -> V_72 ) ;
F_35 ( L_27 V_86 L_28 , V_5 -> V_71 ) ;
F_35 ( L_27 V_86 L_28 , V_5 -> V_68 ) ;
F_35 ( L_27 V_86 L_28 , V_5 -> V_69 ) ;
F_35 ( L_27 V_86 L_28 , V_5 -> V_19 == V_21 ?
0 : V_5 -> V_19 ) ;
F_35 ( L_29 ) ;
}
F_34 ( V_82 , V_83 ) ;
}
static void F_38 ( void )
{
struct V_1 * V_5 ;
struct V_3 * V_4 ;
struct V_87 * V_88 ;
F_35 ( L_30 , L_31 ) ;
V_4 = F_39 ( & V_6 ) ;
while ( V_4 ) {
V_5 = F_2 ( V_4 , struct V_1 , V_7 ) ;
V_88 = F_40 ( V_89 , V_5 -> V_2 ) ;
F_35 ( L_32 , V_5 -> V_2 , F_41 ( V_88 ) ) ;
V_4 = F_42 ( V_4 ) ;
} ;
}
static void F_43 ( void )
{
unsigned int V_22 ;
struct V_15 * V_5 ;
F_35 ( L_33 ) ;
for ( V_22 = 0 ; V_22 < V_90 ; V_22 ++ ) {
F_20 (st, &lockhash_table[i], hash_entry) {
F_35 ( L_34 , V_5 -> V_29 , V_5 -> V_24 ) ;
}
}
}
static int F_44 ( void )
{
int V_91 = 0 ;
if ( V_92 )
F_38 () ;
else if ( V_93 )
F_43 () ;
else {
V_91 = - 1 ;
F_9 ( L_35 ) ;
}
return V_91 ;
}
static int F_45 ( struct V_94 * T_3 V_95 ,
union V_96 * V_97 ,
struct V_43 * V_44 ,
struct V_41 * V_42 ,
struct V_98 * V_98 )
{
struct V_87 * V_87 = F_46 ( V_98 , V_44 -> V_99 ,
V_44 -> V_2 ) ;
if ( V_87 == NULL ) {
F_47 ( L_36 ,
V_97 -> V_100 . type ) ;
return - 1 ;
}
if ( V_42 -> V_101 != NULL ) {
T_4 V_102 = V_42 -> V_101 ;
return V_102 ( V_42 , V_44 ) ;
}
return 0 ;
}
static void F_48 ( void )
{
unsigned int V_22 ;
struct V_15 * V_5 ;
for ( V_22 = 0 ; V_22 < V_90 ; V_22 ++ ) {
F_20 (st, &lockhash_table[i], hash_entry) {
F_14 ( V_5 , V_26 ) ;
}
}
}
static int F_49 ( bool V_103 )
{
int V_104 = - V_105 ;
struct V_94 V_106 = {
. V_44 = F_45 ,
. V_107 = V_108 ,
. V_109 = true ,
} ;
struct V_110 V_111 = {
. V_112 = V_113 ,
. V_114 = V_115 ,
} ;
V_89 = F_50 ( & V_111 , false , & V_106 ) ;
if ( ! V_89 ) {
F_9 ( L_37 ) ;
return - 1 ;
}
F_51 ( & V_89 -> V_100 . V_116 ) ;
if ( ! F_52 ( V_89 , L_38 ) )
goto V_117;
if ( F_53 ( V_89 , V_118 ) ) {
F_9 ( L_39 ) ;
goto V_117;
}
if ( F_13 () )
goto V_117;
V_104 = F_54 ( V_89 , & V_106 ) ;
if ( V_104 )
goto V_117;
F_55 () ;
if ( V_103 )
V_104 = F_44 () ;
else {
F_48 () ;
F_36 () ;
}
V_117:
F_56 ( V_89 ) ;
return V_104 ;
}
static int F_57 ( int V_119 , const char * * V_120 )
{
const char * V_121 [] = {
L_40 , L_41 , L_42 , L_43 , L_44 , L_45 ,
} ;
unsigned int V_122 , V_22 , V_123 , V_32 ;
const char * * V_124 ;
for ( V_22 = 0 ; V_22 < F_58 ( V_118 ) ; V_22 ++ ) {
if ( ! F_59 ( V_118 [ V_22 ] . V_24 ) ) {
F_9 ( L_46
L_47 ,
V_118 [ V_22 ] . V_24 ) ;
return 1 ;
}
}
V_122 = F_58 ( V_121 ) + V_119 - 1 ;
V_122 += 2 * F_58 ( V_118 ) ;
V_124 = calloc ( V_122 + 1 , sizeof( char * ) ) ;
if ( ! V_124 )
return - V_48 ;
for ( V_22 = 0 ; V_22 < F_58 ( V_121 ) ; V_22 ++ )
V_124 [ V_22 ] = F_60 ( V_121 [ V_22 ] ) ;
for ( V_123 = 0 ; V_123 < F_58 ( V_118 ) ; V_123 ++ ) {
V_124 [ V_22 ++ ] = L_48 ;
V_124 [ V_22 ++ ] = F_60 ( V_118 [ V_123 ] . V_24 ) ;
}
for ( V_123 = 1 ; V_123 < ( unsigned int ) V_119 ; V_123 ++ , V_22 ++ )
V_124 [ V_22 ] = V_120 [ V_123 ] ;
F_4 ( V_22 != V_122 ) ;
V_32 = F_61 ( V_22 , V_124 , NULL ) ;
free ( V_124 ) ;
return V_32 ;
}
int F_62 ( int V_119 , const char * * V_120 , const char * T_5 V_95 )
{
const struct V_125 V_126 [] = {
F_63 ( 't' , L_49 , & V_92 ,
L_50 ) ,
F_63 ( 'm' , L_51 , & V_93 ,
L_52 ) ,
F_64 ()
} ;
const struct V_125 V_127 [] = {
F_65 ( 'i' , L_53 , & V_113 , L_54 , L_55 ) ,
F_66 ( 'v' , L_56 , & V_128 , L_57 ) ,
F_63 ( 'D' , L_58 , & V_129 , L_59 ) ,
F_64 ()
} ;
const struct V_125 V_130 [] = {
F_65 ( 'k' , L_60 , & V_25 , L_9 ,
L_61 ) ,
F_64 ()
} ;
const char * const V_131 [] = {
L_62 ,
NULL
} ;
const char * const V_132 [] = { L_40 , L_63 , L_64 ,
L_65 , NULL } ;
const char * V_133 [] = {
NULL ,
NULL
} ;
const char * const V_134 [] = {
L_66 ,
NULL
} ;
unsigned int V_22 ;
int V_91 = 0 ;
for ( V_22 = 0 ; V_22 < V_90 ; V_22 ++ )
F_10 ( V_135 + V_22 ) ;
V_119 = F_67 ( V_119 , V_120 , V_127 , V_132 ,
V_133 , V_136 ) ;
if ( ! V_119 )
F_68 ( V_133 , V_127 ) ;
if ( ! strncmp ( V_120 [ 0 ] , L_67 , 3 ) ) {
return F_57 ( V_119 , V_120 ) ;
} else if ( ! strncmp ( V_120 [ 0 ] , L_63 , 6 ) ) {
V_77 = & V_137 ;
if ( V_119 ) {
V_119 = F_69 ( V_119 , V_120 ,
V_130 , V_134 , 0 ) ;
if ( V_119 )
F_68 ( V_134 , V_130 ) ;
}
V_91 = F_49 ( false ) ;
} else if ( ! strcmp ( V_120 [ 0 ] , L_64 ) ) {
return F_70 ( V_119 , V_120 , T_5 ) ;
} else if ( ! strcmp ( V_120 [ 0 ] , L_65 ) ) {
if ( V_119 ) {
V_119 = F_69 ( V_119 , V_120 ,
V_126 , V_131 , 0 ) ;
if ( V_119 )
F_68 ( V_131 , V_126 ) ;
}
V_77 = & V_137 ;
V_91 = F_49 ( true ) ;
} else {
F_68 ( V_133 , V_127 ) ;
}
return V_91 ;
}
