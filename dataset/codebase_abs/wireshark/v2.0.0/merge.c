T_1
F_1 ( const char * V_1 )
{
int V_2 ;
for ( V_2 = 0 ; V_2 < V_3 ; V_2 ++ ) {
if ( F_2 ( V_1 , V_4 [ V_2 ] ) == 0 ) {
return ( T_1 ) V_2 ;
}
}
return V_3 ;
}
const char *
F_3 ( const int V_5 )
{
if ( V_5 >= 0 && V_5 < V_3 ) {
return V_4 [ V_5 ] ;
}
return V_4 [ ( int ) V_3 ] ;
}
static void
F_4 ( T_2 * V_6 )
{
F_5 ( V_6 != NULL ) ;
F_6 ( V_6 -> V_7 ) ;
V_6 -> V_7 = NULL ;
F_7 ( V_6 -> V_8 , TRUE ) ;
V_6 -> V_8 = NULL ;
}
static void
F_8 ( T_2 * V_6 , const T_3 V_9 , const T_3 V_10 )
{
F_5 ( V_6 != NULL ) ;
F_5 ( V_6 -> V_8 != NULL ) ;
F_5 ( V_9 == V_6 -> V_8 -> V_11 ) ;
F_9 ( V_6 -> V_8 , V_10 ) ;
}
static T_4
F_10 ( int V_12 , const char * const * V_13 ,
T_2 * * V_14 , int * V_15 , T_5 * * V_16 ,
int * V_17 )
{
T_6 V_2 ;
T_6 V_18 ;
T_7 V_19 = V_12 * sizeof( T_2 ) ;
T_2 * V_20 ;
T_8 V_21 ;
V_20 = ( T_2 * ) F_11 ( V_19 ) ;
* V_14 = V_20 ;
for ( V_2 = 0 ; V_2 < V_12 ; V_2 ++ ) {
V_20 [ V_2 ] . V_22 = V_13 [ V_2 ] ;
V_20 [ V_2 ] . V_7 = F_12 ( V_13 [ V_2 ] , V_23 , V_15 , V_16 , FALSE ) ;
V_20 [ V_2 ] . V_24 = 0 ;
V_20 [ V_2 ] . V_25 = V_26 ;
V_20 [ V_2 ] . V_27 = 0 ;
if ( ! V_20 [ V_2 ] . V_7 ) {
for ( V_18 = 0 ; V_18 < V_2 ; V_18 ++ )
F_4 ( & V_20 [ V_18 ] ) ;
* V_17 = V_2 ;
return FALSE ;
}
V_21 = F_13 ( V_20 [ V_2 ] . V_7 , V_15 ) ;
if ( V_21 == - 1 ) {
for ( V_18 = 0 ; V_18 + 1 > V_18 && V_18 <= V_2 ; V_18 ++ )
F_4 ( & V_20 [ V_18 ] ) ;
* V_17 = V_2 ;
return FALSE ;
}
V_20 [ V_2 ] . V_21 = V_21 ;
V_20 [ V_2 ] . V_8 = F_14 ( FALSE , FALSE , sizeof( T_3 ) ) ;
}
return TRUE ;
}
static void
F_15 ( int V_28 , T_2 V_14 [] )
{
int V_2 ;
for ( V_2 = 0 ; V_2 < V_28 ; V_2 ++ ) {
F_4 ( & V_14 [ V_2 ] ) ;
}
}
static int
F_16 ( int V_28 , T_2 V_20 [] )
{
int V_2 ;
int V_29 ;
V_29 = F_17 ( V_20 [ 0 ] . V_7 ) ;
for ( V_2 = 1 ; V_2 < V_28 ; V_2 ++ ) {
int V_30 = F_17 ( V_20 [ V_2 ] . V_7 ) ;
if ( V_29 != V_30 ) {
V_29 = V_31 ;
break;
}
}
return V_29 ;
}
static T_4
F_18 ( T_9 * V_32 , T_9 * V_33 )
{
if ( V_32 -> V_34 > V_33 -> V_34 ) {
return FALSE ;
} else if ( V_32 -> V_34 < V_33 -> V_34 ) {
return TRUE ;
} else if ( V_32 -> V_35 > V_33 -> V_35 ) {
return FALSE ;
}
return TRUE ;
}
static T_2 *
F_19 ( int V_12 , T_2 V_14 [] ,
int * V_15 , T_5 * * V_16 )
{
int V_2 ;
int V_36 = - 1 ;
T_9 V_37 = { sizeof( V_38 ) > sizeof( int ) ? V_39 : V_40 , V_40 } ;
struct V_41 * V_42 ;
for ( V_2 = 0 ; V_2 < V_12 ; V_2 ++ ) {
if ( V_14 [ V_2 ] . V_25 == V_26 ) {
if ( ! F_20 ( V_14 [ V_2 ] . V_7 , V_15 , V_16 , & V_14 [ V_2 ] . V_24 ) ) {
if ( * V_15 != 0 ) {
V_14 [ V_2 ] . V_25 = V_43 ;
return & V_14 [ V_2 ] ;
}
V_14 [ V_2 ] . V_25 = V_44 ;
} else
V_14 [ V_2 ] . V_25 = V_45 ;
}
if ( V_14 [ V_2 ] . V_25 == V_45 ) {
V_42 = F_21 ( V_14 [ V_2 ] . V_7 ) ;
if ( F_18 ( & V_42 -> V_46 , & V_37 ) ) {
V_37 = V_42 -> V_46 ;
V_36 = V_2 ;
}
}
}
if ( V_36 == - 1 ) {
* V_15 = 0 ;
return NULL ;
}
V_14 [ V_36 ] . V_25 = V_26 ;
V_14 [ V_36 ] . V_27 ++ ;
* V_15 = 0 ;
return & V_14 [ V_36 ] ;
}
static T_2 *
F_22 ( int V_12 , T_2 V_14 [] ,
int * V_15 , T_5 * * V_16 )
{
int V_2 ;
for ( V_2 = 0 ; V_2 < V_12 ; V_2 ++ ) {
if ( V_14 [ V_2 ] . V_25 == V_44 )
continue;
if ( F_20 ( V_14 [ V_2 ] . V_7 , V_15 , V_16 , & V_14 [ V_2 ] . V_24 ) )
break;
if ( * V_15 != 0 ) {
V_14 [ V_2 ] . V_25 = V_43 ;
return & V_14 [ V_2 ] ;
}
V_14 [ V_2 ] . V_25 = V_44 ;
}
if ( V_2 == V_12 ) {
* V_15 = 0 ;
return NULL ;
}
* V_15 = 0 ;
return & V_14 [ V_2 ] ;
}
static T_10 *
F_23 ( const T_2 * V_14 , const T_3 V_12 ,
const T_5 * V_47 )
{
T_10 * V_48 = NULL ;
T_11 * V_49 ;
T_11 * V_50 ;
T_3 V_2 ;
V_48 = F_24 ( V_14 [ 0 ] . V_7 ) ;
V_49 = F_25 ( L_1 ) ;
if ( V_48 -> V_51 && strlen ( V_48 -> V_51 ) > 0 ) {
F_26 ( V_49 , L_2 , V_48 -> V_51 ) ;
}
F_27 ( V_48 -> V_51 ) ;
V_48 -> V_51 = NULL ;
F_26 ( V_49 , L_3 ) ;
for ( V_2 = 0 ; V_2 < V_12 ; V_2 ++ ) {
F_26 ( V_49 , L_4 , V_2 + 1 , V_14 [ V_2 ] . V_22 ) ;
}
V_50 = F_25 ( L_1 ) ;
F_28 ( V_50 ) ;
V_48 -> V_52 = - 1 ;
V_48 -> V_51 = F_29 ( V_49 , FALSE ) ;
V_48 -> V_53 = NULL ;
V_48 -> V_54 = F_29 ( V_50 , FALSE ) ;
V_48 -> V_55 = F_30 ( V_47 ) ;
return V_48 ;
}
static T_4
F_31 ( const T_12 * V_56 , const T_12 * V_57 )
{
F_5 ( V_56 && V_57 ) ;
F_32 ( L_5 ) ;
F_32 ( L_6 ,
( V_56 -> V_58 == V_57 -> V_58 ) ? L_7 : L_8 ) ;
F_32 ( L_9 ,
( V_56 -> V_59 == V_57 -> V_59 ) ? L_7 : L_8 ) ;
F_32 ( L_10 ,
( V_56 -> V_60 == V_57 -> V_60 ) ? L_7 : L_8 ) ;
F_32 ( L_11 ,
( V_56 -> V_61 == V_57 -> V_61 ) ? L_7 : L_8 ) ;
F_32 ( L_12 ,
( V_56 -> V_62 == V_57 -> V_62 ) ? L_7 : L_8 ) ;
F_32 ( L_13 ,
( V_56 -> V_63 == V_57 -> V_63 ) ? L_7 : L_8 ) ;
F_32 ( L_14 ,
( V_56 -> V_64 == V_57 -> V_64 ) ? L_7 : L_8 ) ;
F_32 ( L_15 ,
( V_56 -> V_65 == V_57 -> V_65 ) ? L_7 : L_8 ) ;
F_32 ( L_16 ,
( F_2 ( V_56 -> V_51 , V_57 -> V_51 ) == 0 ) ? L_7 : L_8 ) ;
F_32 ( L_17 ,
( F_2 ( V_56 -> V_66 , V_57 -> V_66 ) == 0 ) ? L_7 : L_8 ) ;
F_32 ( L_18 ,
( F_2 ( V_56 -> V_67 , V_57 -> V_67 ) == 0 ) ? L_7 : L_8 ) ;
F_32 ( L_19 ,
( F_2 ( V_56 -> V_68 , V_57 -> V_68 ) == 0 ) ? L_7 : L_8 ) ;
F_32 ( L_20 ) ;
return ( V_56 -> V_58 == V_57 -> V_58 &&
V_56 -> V_59 == V_57 -> V_59 &&
V_56 -> V_60 == V_57 -> V_60 &&
V_56 -> V_61 == V_57 -> V_61 &&
V_56 -> V_62 == V_57 -> V_62 &&
V_56 -> V_63 == V_57 -> V_63 &&
V_56 -> V_64 == V_57 -> V_64 &&
V_56 -> V_65 == V_57 -> V_65 &&
F_2 ( V_56 -> V_51 , V_57 -> V_51 ) == 0 &&
F_2 ( V_56 -> V_66 , V_57 -> V_66 ) == 0 &&
F_2 ( V_56 -> V_67 , V_57 -> V_67 ) == 0 &&
F_2 ( V_56 -> V_68 , V_57 -> V_68 ) == 0 ) ;
}
static T_4
F_33 ( const T_2 * V_14 , const T_3 V_12 )
{
T_13 * V_69 = NULL ;
T_13 * V_70 = NULL ;
T_3 V_71 , V_72 ;
const T_12 * V_73 , * V_74 ;
T_3 V_2 , V_18 ;
F_5 ( V_14 != NULL ) ;
V_69 = F_34 ( V_14 [ 0 ] . V_7 ) ;
F_5 ( V_69 -> V_75 ) ;
V_71 = V_69 -> V_75 -> V_11 ;
for ( V_2 = 1 ; V_2 < V_12 ; V_2 ++ ) {
V_70 = F_34 ( V_14 [ V_2 ] . V_7 ) ;
F_5 ( V_70 -> V_75 ) ;
V_72 = V_70 -> V_75 -> V_11 ;
if ( V_72 != V_71 ) {
F_32 ( L_21 ,
V_71 , V_72 ) ;
F_27 ( V_70 ) ;
F_27 ( V_69 ) ;
return FALSE ;
}
for ( V_18 = 0 ; V_18 < V_72 ; V_18 ++ ) {
V_73 = & F_35 ( V_69 -> V_75 , T_12 , V_18 ) ;
V_74 = & F_35 ( V_70 -> V_75 , T_12 , V_18 ) ;
if ( ! F_31 ( V_73 , V_74 ) ) {
F_32 ( L_22 , V_18 ) ;
F_27 ( V_70 ) ;
F_27 ( V_69 ) ;
return FALSE ;
}
}
F_27 ( V_70 ) ;
}
F_32 ( L_23 ) ;
F_27 ( V_69 ) ;
return TRUE ;
}
static T_4
F_36 ( const T_12 * V_76 ,
const T_13 * V_77 ,
T_3 * V_10 )
{
const T_12 * V_78 ;
T_3 V_2 ;
F_5 ( V_76 != NULL ) ;
F_5 ( V_77 != NULL ) ;
F_5 ( V_77 -> V_75 != NULL ) ;
F_5 ( V_10 != NULL ) ;
for ( V_2 = 0 ; V_2 < V_77 -> V_75 -> V_11 ; V_2 ++ ) {
V_78 = & F_35 ( V_77 -> V_75 , T_12 , V_2 ) ;
if ( F_31 ( V_76 , V_78 ) ) {
* V_10 = V_2 ;
return TRUE ;
}
}
return FALSE ;
}
static T_3
F_37 ( T_13 * V_77 ,
const T_12 * V_76 )
{
T_12 V_79 ;
F_5 ( V_77 != NULL ) ;
F_5 ( V_77 -> V_75 != NULL ) ;
F_5 ( V_76 != NULL ) ;
V_79 . V_58 = V_76 -> V_58 ;
V_79 . V_59 = V_76 -> V_59 ;
V_79 . V_60 = V_76 -> V_60 ;
V_79 . V_61 = V_76 -> V_61 ;
V_79 . V_62 = V_76 -> V_62 ;
V_79 . V_66 = F_30 ( V_76 -> V_66 ) ;
V_79 . V_51 = F_30 ( V_76 -> V_51 ) ; ;
V_79 . V_67 = F_30 ( V_76 -> V_67 ) ;
V_79 . V_63 = V_76 -> V_63 ;
V_79 . V_64 = V_76 -> V_64 ;
V_79 . V_80 = NULL ;
V_79 . V_81 = 0 ;
V_79 . V_82 = NULL ;
V_79 . V_68 = F_30 ( V_76 -> V_68 ) ;
V_79 . V_65 = V_76 -> V_65 ;
V_79 . V_83 = 0 ;
V_79 . V_84 = NULL ;
F_9 ( V_77 -> V_75 , V_79 ) ;
return V_77 -> V_75 -> V_11 - 1 ;
}
static T_13 *
F_38 ( T_2 * V_14 , const T_3 V_12 , const T_1 V_5 )
{
T_13 * V_77 = NULL ;
T_13 * V_85 = NULL ;
const T_12 * V_76 = NULL ;
T_3 V_86 , V_87 ;
T_3 V_2 ;
V_77 = F_39 ( T_13 , 1 ) ;
V_77 -> V_75 = F_14 ( FALSE , FALSE , sizeof( T_12 ) ) ;
if ( V_5 == V_88 && F_33 ( V_14 , V_12 ) ) {
T_3 V_89 ;
F_32 ( L_24 ) ;
V_85 = F_34 ( V_14 [ 0 ] . V_7 ) ;
V_89 = V_85 -> V_75 -> V_11 ;
for ( V_86 = 0 ; V_86 < V_89 ; V_86 ++ ) {
V_76 = & F_35 ( V_85 -> V_75 ,
T_12 , V_86 ) ;
V_87 = F_37 ( V_77 , V_76 ) ;
F_8 ( & V_14 [ 0 ] , V_86 , V_87 ) ;
}
for ( V_2 = 1 ; V_2 < V_12 ; V_2 ++ ) {
for ( V_86 = 0 ; V_86 < V_89 ; V_86 ++ ) {
F_8 ( & V_14 [ V_2 ] , V_86 , V_86 ) ;
}
}
F_27 ( V_85 ) ;
}
else {
for ( V_2 = 0 ; V_2 < V_12 ; V_2 ++ ) {
V_85 = F_34 ( V_14 [ V_2 ] . V_7 ) ;
for ( V_86 = 0 ; V_86 < V_85 -> V_75 -> V_11 ; V_86 ++ ) {
V_76 = & F_35 ( V_85 -> V_75 ,
T_12 , V_86 ) ;
if ( V_5 == V_90 &&
F_36 ( V_76 , V_77 , & V_87 ) )
{
F_32 ( L_25 ) ;
F_8 ( & V_14 [ V_2 ] , V_86 , V_87 ) ;
}
else {
F_32 ( L_26 ) ;
V_87 = F_37 ( V_77 , V_76 ) ;
F_8 ( & V_14 [ V_2 ] , V_86 , V_87 ) ;
}
}
F_27 ( V_85 ) ;
}
}
return V_77 ;
}
static T_4
F_40 ( struct V_41 * V_42 , const T_2 * V_6 )
{
T_3 V_91 = 0 ;
F_5 ( V_42 != NULL ) ;
F_5 ( V_6 != NULL ) ;
F_5 ( V_6 -> V_8 != NULL ) ;
if ( V_42 -> V_92 & V_93 ) {
V_91 = V_42 -> V_94 ;
}
if ( V_91 >= V_6 -> V_8 -> V_11 ) {
F_32 ( L_27 ) ;
return FALSE ;
}
V_42 -> V_94 = F_35 ( V_6 -> V_8 , T_3 , V_91 ) ;
V_42 -> V_92 |= V_93 ;
return TRUE ;
}
static T_5 *
F_41 ( const T_2 * V_14 , const T_3 V_12 ,
const int * V_15 , T_5 * * V_16 )
{
T_11 * V_95 = F_25 ( L_1 ) ;
T_5 * V_96 = NULL ;
T_3 V_2 ;
F_5 ( V_14 != NULL ) ;
F_5 ( V_15 != NULL ) ;
F_5 ( V_16 != NULL ) ;
if ( * V_16 == NULL ) {
* V_16 = F_30 ( L_28 ) ;
}
for ( V_2 = 0 ; V_2 < V_12 ; V_2 ++ ) {
if ( V_14 [ V_2 ] . V_25 == V_43 ) {
V_96 = F_42 ( V_14 [ V_2 ] . V_22 ) ;
switch ( * V_15 ) {
case V_97 :
F_43 ( V_95 ,
L_29
L_30 , V_96 ) ;
break;
case V_98 :
F_43 ( V_95 ,
L_31 ,
V_96 , * V_16 ) ;
break;
case V_99 :
F_43 ( V_95 ,
L_32
L_33 , V_96 , * V_16 ) ;
break;
default:
F_43 ( V_95 ,
L_34
L_35 ,
V_96 , F_44 ( * V_15 ) ) ;
break;
}
F_27 ( V_96 ) ;
break;
}
}
F_27 ( * V_16 ) ;
* V_16 = F_29 ( V_95 , FALSE ) ;
return * V_16 ;
}
static T_5 *
F_45 ( const T_2 * V_6 , const int V_100 ,
const T_5 * V_101 , const int * V_15 , T_5 * * V_16 )
{
T_11 * V_95 = F_25 ( L_1 ) ;
T_5 * V_96 = NULL ;
int V_102 ;
F_5 ( V_15 != NULL ) ;
F_5 ( V_16 != NULL ) ;
if ( * V_16 == NULL ) {
* V_16 = F_30 ( L_28 ) ;
}
V_102 = * V_15 ;
V_96 = F_42 ( V_6 ? V_6 -> V_22 : L_36 ) ;
if ( V_102 < 0 ) {
switch ( V_102 ) {
case V_103 :
F_43 ( V_95 ,
L_37 ,
V_6 ? V_6 -> V_27 : 0 , V_96 ,
F_46 ( V_100 ) ) ;
break;
case V_104 :
F_43 ( V_95 ,
L_38 ,
V_6 ? V_6 -> V_27 : 0 , V_96 ,
F_46 ( V_100 ) ) ;
break;
case V_105 :
F_43 ( V_95 ,
L_39 ,
V_6 ? V_6 -> V_27 : 0 , V_96 ,
F_46 ( V_100 ) ) ;
break;
case V_106 :
F_43 ( V_95 ,
L_40 ,
V_6 ? V_6 -> V_27 : 0 , V_96 ,
F_46 ( V_100 ) , * V_16 ) ;
break;
default:
F_43 ( V_95 ,
L_41 ,
V_101 , F_44 ( V_102 ) ) ;
break;
}
}
else {
F_43 ( V_95 , F_47 ( V_102 ) , V_101 ) ;
}
F_27 ( V_96 ) ;
F_27 ( * V_16 ) ;
* V_16 = F_29 ( V_95 , FALSE ) ;
return * V_16 ;
}
T_14
F_48 ( int V_107 , const T_5 * V_101 , const int V_100 ,
const char * const * V_108 , const T_3 V_12 ,
const T_4 V_109 , const T_1 V_5 ,
T_3 V_110 , const T_5 * V_47 , T_15 * V_111 ,
int * V_15 , T_5 * * V_16 , int * V_17 )
{
T_2 * V_14 = NULL , * V_6 = NULL ;
int V_112 = V_31 ;
T_14 V_113 = V_114 ;
T_16 * V_115 ;
struct V_41 * V_42 , V_116 ;
int V_28 = 0 ;
T_4 V_117 = FALSE ;
T_10 * V_48 = NULL ;
T_13 * V_118 = NULL ;
F_5 ( V_107 > 0 ) ;
F_5 ( V_12 > 0 ) ;
F_5 ( V_108 != NULL ) ;
F_5 ( V_15 != NULL ) ;
F_5 ( V_16 != NULL ) ;
F_5 ( V_17 != NULL ) ;
F_5 ( ( V_111 != NULL ) ? ( V_111 -> V_119 != NULL ) : TRUE ) ;
F_32 ( L_42 ) ;
if ( ! F_10 ( V_12 , V_108 , & V_14 ,
V_15 , V_16 , V_17 ) ) {
F_32 ( L_43 , * V_15 ) ;
return V_120 ;
}
if ( V_111 )
V_111 -> V_119 ( V_121 , 0 , V_14 , V_12 , V_111 -> V_122 ) ;
if ( V_110 == 0 ) {
V_110 = V_123 ;
}
V_112 = F_16 ( V_12 , V_14 ) ;
F_32 ( L_44 , V_112 ) ;
if ( V_111 )
V_111 -> V_119 ( V_124 , V_112 , V_14 , V_12 , V_111 -> V_122 ) ;
if ( V_100 == V_125 ) {
V_48 = F_23 ( V_14 , V_12 , V_47 ) ;
F_32 ( L_45 ) ;
V_118 = F_38 ( V_14 , V_12 , V_5 ) ;
F_32 ( L_46 , V_118 ? V_118 -> V_75 -> V_11 : 0 ) ;
V_115 = F_49 ( V_107 , V_100 , V_112 , V_110 ,
FALSE , V_48 , V_118 ,
NULL , V_15 ) ;
}
else {
V_115 = F_50 ( V_107 , V_100 , V_112 , V_110 , FALSE , V_15 ) ;
}
if ( V_115 == NULL ) {
F_15 ( V_12 , V_14 ) ;
F_27 ( V_14 ) ;
F_51 ( V_48 ) ;
F_52 ( V_118 ) ;
return V_126 ;
}
if ( V_111 )
V_111 -> V_119 ( V_127 , 0 , V_14 , V_12 , V_111 -> V_122 ) ;
for (; ; ) {
* V_15 = 0 ;
if ( V_109 ) {
V_6 = F_22 ( V_12 , V_14 , V_15 ,
V_16 ) ;
}
else {
V_6 = F_19 ( V_12 , V_14 , V_15 ,
V_16 ) ;
}
if ( V_6 == NULL ) {
break;
}
if ( * V_15 != 0 ) {
V_113 = V_128 ;
break;
}
V_28 ++ ;
if ( V_111 )
V_117 = V_111 -> V_119 ( V_129 , V_28 , V_14 , V_12 , V_111 -> V_122 ) ;
if ( V_117 ) {
V_113 = V_130 ;
break;
}
V_42 = F_21 ( V_6 -> V_7 ) ;
if ( V_110 != 0 && V_42 -> V_131 > V_110 ) {
V_116 = * V_42 ;
V_116 . V_131 = V_110 ;
V_42 = & V_116 ;
}
if ( V_100 == V_125 ) {
if ( ! F_40 ( V_42 , V_6 ) ) {
V_113 = V_132 ;
break;
}
}
if ( ! F_53 ( V_115 , V_42 , F_54 ( V_6 -> V_7 ) , V_15 , V_16 ) ) {
V_113 = V_133 ;
break;
}
}
if ( V_111 )
V_111 -> V_119 ( V_134 , V_28 , V_14 , V_12 , V_111 -> V_122 ) ;
F_15 ( V_12 , V_14 ) ;
if ( V_113 == V_114 || V_113 == V_130 ) {
if ( ! F_55 ( V_115 , V_15 ) )
V_113 = V_135 ;
} else {
int V_136 = 0 ;
( void ) F_55 ( V_115 , & V_136 ) ;
}
if ( V_113 != V_114 ) {
T_11 * V_95 = NULL ;
T_5 * V_96 = NULL ;
switch( V_113 ) {
case V_128 :
* V_16 = F_41 ( V_14 , V_12 , V_15 , V_16 ) ;
break;
case V_133 :
case V_135 :
* V_16 = F_45 ( V_6 , V_100 , V_101 , V_15 , V_16 ) ;
break;
case V_132 :
V_96 = F_42 ( V_6 ? V_6 -> V_22 : L_36 ) ;
if ( * V_16 != NULL )
F_27 ( * V_16 ) ;
V_95 = F_25 ( L_1 ) ;
F_43 ( V_95 ,
L_47 ,
V_6 ? V_6 -> V_27 : 0 , V_96 ) ;
F_27 ( V_96 ) ;
* V_16 = F_29 ( V_95 , FALSE ) ;
break;
case V_130 :
default:
break;
}
}
F_27 ( V_14 ) ;
F_51 ( V_48 ) ;
F_52 ( V_118 ) ;
return V_113 ;
}
