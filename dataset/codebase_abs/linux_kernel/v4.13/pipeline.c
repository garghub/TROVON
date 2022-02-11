void F_1 ( void )
{
F_2 () ;
}
enum V_1 F_3 (
struct V_2 * V_3 ,
enum V_4 V_5 ,
unsigned int V_6 ,
unsigned int V_7 )
{
assert ( V_3 != NULL ) ;
F_4 ( L_1 ,
V_3 , V_5 , V_6 , V_7 ) ;
if ( V_3 == NULL ) {
F_5 ( V_8 ) ;
return V_8 ;
}
F_6 ( V_3 , V_5 , V_6 , V_7 ) ;
F_5 ( V_9 ) ;
return V_9 ;
}
void F_7 ( unsigned int V_6 , bool V_10 )
{
assert ( V_6 < V_11 ) ;
F_4 ( L_2 , V_6 , V_10 ) ;
if ( V_6 >= V_11 ) {
F_8 ( L_3 ) ;
F_9 ( L_4 ) ;
return;
}
if ( V_10 )
F_10 ( V_6 ) ;
else
F_11 ( V_6 ) ;
F_9 ( L_4 ) ;
}
void F_12 ( struct V_2 * V_3 )
{
assert ( V_3 != NULL ) ;
F_4 ( L_5 , V_3 ) ;
if ( V_3 == NULL ) {
F_8 ( L_6 ) ;
F_9 ( L_4 ) ;
return;
}
F_13 ( L_7 , V_3 -> V_6 ) ;
F_14 ( V_3 ) ;
F_9 ( L_4 ) ;
}
void F_15 ( enum V_4 V_5 ,
struct V_2 * V_3 )
{
T_1 V_6 = 0 ;
unsigned int V_12 ;
assert ( V_3 != NULL ) ;
F_16 ( V_13 ,
L_8 ,
V_5 , V_3 ) ;
V_3 -> V_5 = V_5 ;
F_17 (pipeline, pipe_id, pipe_num,
false, false, false, true, SH_CSS_BDS_FACTOR_1_00,
SH_CSS_PIPE_CONFIG_OVRD_NO_OVRD,
#ifndef F_18
IA_CSS_INPUT_MODE_MEMORY, NULL, NULL
#else
IA_CSS_INPUT_MODE_MEMORY, NULL, NULL,
#endif
#if ! F_19 ( V_14 )
#ifndef F_18
, (mipi_port_ID_t) 0
#else
(mipi_port_ID_t) 0 ,
#endif
#endif
#ifndef F_18
) ;
#else
NULL , NULL ) ;
void F_20 ( void )
{
unsigned int V_15 ;
F_16 ( V_13 ,
L_9 ) ;
for ( V_15 = 0 ; V_15 < V_11 ; V_15 ++ ) {
F_16 ( V_13 ,
L_10 , V_15 , V_16 [ V_15 ] ) ;
}
}
enum V_1 F_21 ( struct V_2 * V_3 )
{
enum V_1 V_17 = V_9 ;
unsigned int V_12 ;
assert ( V_3 != NULL ) ;
if ( V_3 == NULL )
return V_8 ;
F_16 ( V_13 ,
L_11 ,
V_3 ) ;
V_3 -> V_18 = true ;
F_22 ( V_3 -> V_6 , & V_12 ) ;
if ( ! F_23 () )
{
F_16 ( V_13 ,
L_12 ) ;
return V_19 ;
}
F_24 ( V_20 ,
( T_1 ) V_12 ,
0 ,
0 ) ;
F_25 ( V_3 -> V_6 ) ;
F_16 ( V_13 ,
L_13 ,
V_17 ) ;
return V_17 ;
}
void F_14 ( struct V_2 * V_3 )
{
struct V_21 * V_22 ;
assert ( V_3 != NULL ) ;
F_4 ( L_5 , V_3 ) ;
if ( V_3 == NULL ) {
F_8 ( L_6 ) ;
F_9 ( L_4 ) ;
return;
}
V_22 = V_3 -> V_23 ;
while ( V_22 ) {
struct V_21 * V_24 = V_22 -> V_24 ;
F_26 ( V_22 ) ;
V_22 = V_24 ;
}
F_6 ( V_3 , V_3 -> V_5 , V_3 -> V_6 , V_3 -> V_7 ) ;
F_9 ( L_4 ) ;
}
enum V_1 F_27 (
struct V_2 * V_3 ,
struct V_25 * V_26 ,
struct V_21 * * V_27 )
{
struct V_21 * V_28 , * V_29 = NULL ;
enum V_1 V_17 ;
assert ( V_3 != NULL ) ;
assert ( V_26 != NULL ) ;
V_28 = V_3 -> V_23 ;
F_16 ( V_13 ,
L_14 ) ;
if ( ! V_26 -> V_30 && ! V_26 -> V_31
&& ( V_26 -> V_32 == V_33 ) ) {
F_16 ( V_13 ,
L_15
L_16 ) ;
return V_34 ;
}
while ( V_28 && V_28 -> V_24 )
V_28 = V_28 -> V_24 ;
if ( ( V_26 -> V_32 == V_33 )
&& ( ! V_26 -> V_35 )
&& ( ! V_26 -> V_31 )
&& ( ! V_26 -> V_30 -> V_36 ) ) {
if ( V_28 && V_28 -> args . V_37 [ 0 ] )
V_26 -> V_35 = V_28 -> args . V_37 [ 0 ] ;
if ( ! V_26 -> V_35 )
return V_34 ;
}
V_17 = F_28 ( V_26 , & V_29 ) ;
if ( V_17 != V_9 ) {
F_16 ( V_13 ,
L_15
L_17 ) ;
return V_17 ;
}
if ( V_28 )
V_28 -> V_24 = V_29 ;
else
V_3 -> V_23 = V_29 ;
if ( V_27 )
* V_27 = V_29 ;
F_16 ( V_13 ,
L_18 ) ;
return V_9 ;
}
void F_29 ( struct V_2 * V_3 ,
bool V_38 )
{
unsigned V_15 = 0 ;
struct V_21 * V_27 ;
assert ( V_3 != NULL ) ;
for ( V_27 = V_3 -> V_23 ; V_27 ; V_27 = V_27 -> V_24 ) {
V_27 -> V_39 = V_15 ;
V_15 ++ ;
}
V_3 -> V_40 = V_15 ;
F_30 ( V_3 ) ;
F_31 ( V_3 , V_38 ) ;
}
enum V_1 F_32 ( struct V_2 * V_3 ,
int V_41 ,
struct V_21 * * V_27 )
{
struct V_21 * V_22 ;
assert ( V_3 != NULL ) ;
assert ( V_27 != NULL ) ;
F_16 ( V_13 ,
L_19 ) ;
for ( V_22 = V_3 -> V_23 ; V_22 ; V_22 = V_22 -> V_24 ) {
if ( V_22 -> V_41 == V_41 ) {
* V_27 = V_22 ;
return V_9 ;
}
}
return V_34 ;
}
enum V_1 F_33 ( struct V_2 * V_3 ,
T_2 V_42 ,
struct V_21 * * V_27 )
{
struct V_21 * V_22 ;
assert ( V_3 != NULL ) ;
assert ( V_27 != NULL ) ;
F_16 ( V_13 , L_20 , V_43 ) ;
for ( V_22 = V_3 -> V_23 ; V_22 ; V_22 = V_22 -> V_24 ) {
if ( ( V_22 -> V_31 ) && ( V_22 -> V_31 -> V_44 == V_42 ) ) {
* V_27 = V_22 ;
return V_9 ;
}
}
return V_34 ;
}
enum V_1 F_34 ( struct V_2 * V_3 ,
T_2 V_39 ,
T_2 * V_42 )
{
struct V_21 * V_22 ;
F_16 ( V_13 , L_20 , V_43 ) ;
if ( ( V_3 == NULL ) || ( V_42 == NULL ) )
return V_8 ;
for ( V_22 = V_3 -> V_23 ; V_22 ; V_22 = V_22 -> V_24 ) {
if( ( V_22 -> V_39 == V_39 ) && ( V_22 -> V_31 ) ) {
* V_42 = V_22 -> V_31 -> V_44 ;
return V_9 ;
}
}
return V_34 ;
}
enum V_1 F_35 (
struct V_2 * V_3 ,
int V_41 ,
struct V_21 * * V_27 )
{
struct V_21 * V_22 ;
assert ( V_3 != NULL ) ;
assert ( V_27 != NULL ) ;
F_16 ( V_13 ,
L_21 ) ;
* V_27 = NULL ;
for ( V_22 = V_3 -> V_23 ; V_22 ; V_22 = V_22 -> V_24 ) {
if ( V_22 -> V_31 && V_22 -> V_41 == V_41 &&
V_22 -> V_31 -> V_45 . V_46 . V_47 . V_48 . V_49 )
* V_27 = V_22 ;
}
if ( * V_27 )
return V_9 ;
return F_32 ( V_3 , V_41 , V_27 ) ;
}
bool F_36 ( struct V_2 * V_3 )
{
static struct V_50 V_51 ;
unsigned int V_12 ;
const struct V_52 * V_53 ;
unsigned int V_54 ;
V_53 = & V_55 ;
V_54 = V_53 -> V_45 . V_47 . V_56 ;
F_22 ( V_3 -> V_6 , & V_12 ) ;
F_37 ( V_57 ,
( unsigned int ) F_38 ( V_51 ) ,
& V_51 , sizeof( struct V_50 ) ) ;
return V_51 . V_58 [ V_12 ] . V_40 == 0 ;
}
struct V_59 * F_39 ( void )
{
return ( & V_50 . V_60 ) ;
}
bool F_40 ( unsigned int V_61 )
{
bool V_62 = false ;
F_4 ( L_22 , V_61 ) ;
if ( ( V_61 >= V_11 ) || ( V_61 >= V_63 ) ) {
F_8 ( L_23 ) ;
F_9 ( L_24 , false ) ;
return false ;
}
V_62 = ( bool ) ( V_16 [ V_61 ] != ( unsigned ) V_64 ) ;
F_9 ( L_24 , V_62 ) ;
return V_62 ;
}
static void F_26 ( struct V_21 * V_27 )
{
unsigned int V_15 ;
for ( V_15 = 0 ; V_15 < V_65 ; V_15 ++ ) {
if ( V_27 -> V_66 [ V_15 ] ) {
F_41 ( V_27 -> args . V_37 [ V_15 ] ) ;
V_27 -> args . V_37 [ V_15 ] = NULL ;
}
}
if ( V_27 -> V_67 ) {
F_41 ( V_27 -> args . V_68 ) ;
V_27 -> args . V_68 = NULL ;
}
F_42 ( V_27 ) ;
}
static void F_2 ( void )
{
unsigned int V_15 ;
for ( V_15 = 1 ; V_15 < V_69 ; V_15 ++ )
V_70 [ V_15 ] = V_71 ;
for ( V_15 = 0 ; V_15 < V_11 ; V_15 ++ )
V_16 [ V_15 ] = V_64 ;
}
static void F_10 ( unsigned int V_6 )
{
unsigned int V_15 ;
bool V_72 = false ;
assert ( V_16 [ V_6 ]
== ( unsigned ) V_64 ) ;
for ( V_15 = 0 ; V_15 < V_69 ; V_15 ++ ) {
if ( V_70 [ V_15 ] ==
V_71 ) {
V_70 [ V_15 ] =
V_73 ;
V_16 [ V_6 ] = V_15 ;
V_72 = true ;
break;
}
}
assert ( V_72 != false ) ;
}
static void F_11 ( unsigned int V_6 )
{
unsigned int V_12 ;
assert ( V_16 [ V_6 ]
!= ( unsigned ) V_64 ) ;
V_12 = V_16 [ V_6 ] ;
V_16 [ V_6 ] = V_64 ;
V_70 [ V_12 ] = V_71 ;
}
static enum V_1 F_28 (
struct V_25 * V_26 ,
struct V_21 * * V_29 )
{
enum V_1 V_17 = V_9 ;
struct V_21 * V_27 = NULL ;
struct V_74 * V_30 ;
struct V_75 * V_76 ;
struct V_75 * V_37 [ V_65 ] ;
const struct V_52 * V_31 ;
unsigned int V_15 ;
if ( ! ( V_26 -> V_35 ) && ! ( V_26 -> V_31 )
&& ( V_26 -> V_30 ) && ! ( V_26 -> V_30 -> V_36 ) ) {
V_17 = V_34 ;
goto V_77;
}
V_30 = V_26 -> V_30 ;
V_31 = V_26 -> V_31 ;
V_76 = V_26 -> V_76 ;
for ( V_15 = 0 ; V_15 < V_65 ; V_15 ++ ) {
V_37 [ V_15 ] = V_26 -> V_37 [ V_15 ] ;
}
V_27 = F_43 ( sizeof( * V_27 ) ) ;
if ( V_27 == NULL ) {
V_17 = V_78 ;
goto V_77;
}
memset ( V_27 , 0 , sizeof( * V_27 ) ) ;
if ( V_31 ) {
V_27 -> V_30 = NULL ;
V_27 -> V_79 =
(struct V_80 * ) & V_31 -> V_45 . V_46 ;
} else {
V_27 -> V_30 = V_30 ;
if ( V_30 )
V_27 -> V_79 =
(struct V_80 * ) V_30 -> V_45 ;
else
V_27 -> V_79 = NULL ;
}
V_27 -> V_31 = V_31 ;
V_27 -> V_32 = V_26 -> V_32 ;
V_27 -> V_81 = V_26 -> V_81 ;
V_27 -> V_41 = V_26 -> V_41 ;
for ( V_15 = 0 ; V_15 < V_65 ; V_15 ++ )
V_27 -> V_66 [ V_15 ] = false ;
V_27 -> V_67 = false ;
V_27 -> V_24 = NULL ;
F_44 ( & V_27 -> args ) ;
for ( V_15 = 0 ; V_15 < V_65 ; V_15 ++ ) {
if ( ! ( V_37 [ V_15 ] ) && ( V_30 )
&& ( V_30 -> V_82 [ V_15 ] . V_83 . V_84 ) ) {
V_17 = F_45 ( & V_37 [ V_15 ] ,
& V_30 -> V_82 [ V_15 ] ) ;
if ( V_17 != V_9 )
goto V_77;
V_27 -> V_66 [ V_15 ] = true ;
}
}
if ( ! V_76 ) {
if ( ( V_30 && V_30 -> V_85 . V_83 . V_84 ) ||
( V_31 && V_31 -> V_45 . V_46 . V_47 . V_48 . V_86 )
) {
V_17 = F_45 ( & V_76 ,
& V_30 -> V_85 ) ;
if ( V_17 != V_9 )
goto V_77;
V_27 -> V_67 = true ;
}
} else if ( V_76 && V_30 && V_30 -> V_85 . V_83 . V_84
&& ! V_31 ) {
if ( V_76 -> V_87 != V_88 )
V_27 -> V_67 = true ;
}
V_27 -> args . V_35 = V_26 -> V_35 ;
for ( V_15 = 0 ; V_15 < V_65 ; V_15 ++ )
V_27 -> args . V_37 [ V_15 ] = V_37 [ V_15 ] ;
V_27 -> args . V_68 = V_76 ;
* V_29 = V_27 ;
return V_17 ;
V_77:
if ( V_27 != NULL )
F_26 ( V_27 ) ;
return V_17 ;
}
static void F_6 (
struct V_2 * V_3 ,
enum V_4 V_5 ,
unsigned int V_6 ,
unsigned int V_7 )
{
struct V_75 V_89 = V_90 ;
unsigned int V_15 ;
V_3 -> V_5 = V_5 ;
V_3 -> V_23 = NULL ;
V_3 -> V_18 = false ;
V_3 -> V_91 = NULL ;
V_3 -> V_35 = V_89 ;
for ( V_15 = 0 ; V_15 < V_92 ; V_15 ++ ) {
V_3 -> V_37 [ V_15 ] = V_89 ;
V_3 -> V_76 [ V_15 ] = V_89 ;
}
V_3 -> V_93 = - 1 ;
V_3 -> V_94 = true ;
V_3 -> V_6 = ( T_1 ) V_6 ;
V_3 -> V_7 = V_7 ;
}
static void F_30 ( struct V_2 * V_3 )
{
struct V_21 * V_27 = NULL ;
enum V_1 V_17 = V_9 ;
assert ( V_3 != NULL ) ;
if ( V_3 -> V_5 == V_95 ) {
V_17 = F_32 ( V_3 , V_96 , & V_27 ) ;
if ( V_17 == V_9 )
V_27 -> V_97 = true ;
} else if ( V_3 -> V_5 == V_98 ) {
V_17 = F_32 ( V_3 , V_99 , & V_27 ) ;
if ( V_17 == V_9 )
V_27 -> V_97 = true ;
} else if ( V_3 -> V_5 == V_100 ) {
V_17 = F_32 ( V_3 , V_101 , & V_27 ) ;
if ( V_17 == V_9 )
V_27 -> V_97 = true ;
} else if ( V_3 -> V_5 == V_102 ) {
V_17 = F_32 ( V_3 , V_99 , & V_27 ) ;
if ( V_17 == V_9 )
V_27 -> V_97 = true ;
}
}
static void
F_31 ( struct V_2 * V_103 , bool V_38 )
{
F_16 ( V_104 ,
L_25 ,
V_103 -> V_5 , V_38 ) ;
switch ( V_103 -> V_5 ) {
case V_95 :
case V_100 :
F_46 ( V_103 -> V_105 ,
( T_1 ) V_106 ,
( T_1 ) ( V_38 ? V_107 : V_108 ) , 1 ) ;
F_46 ( V_103 -> V_105 ,
( T_1 ) V_109 ,
( T_1 ) V_108 , 1 ) ;
break;
case V_110 :
F_46 ( V_103 -> V_105 ,
( T_1 ) V_106 ,
( T_1 ) V_108 , 1 ) ;
if ( V_38 ) {
F_46 ( V_103 -> V_105 ,
( T_1 ) V_109 ,
( T_1 ) V_107 , 1 ) ;
F_46 ( V_103 -> V_105 ,
( T_1 ) V_109 ,
( T_1 ) V_111 , 1 ) ;
} else {
F_46 ( V_103 -> V_105 ,
( T_1 ) V_109 ,
( T_1 ) V_108 , 1 ) ;
}
break;
case V_98 :
F_46 ( V_103 -> V_105 ,
( T_1 ) V_106 ,
( T_1 ) ( V_38 ? V_111 : V_108 ) ,
1 ) ;
F_46 ( V_103 -> V_105 ,
( T_1 ) V_109 ,
( T_1 ) V_108 , 1 ) ;
break;
case V_102 :
F_46 ( V_103 -> V_105 ,
( T_1 ) V_106 ,
( T_1 ) ( V_108 ) , 1 ) ;
F_46 ( V_103 -> V_105 ,
( T_1 ) V_109 ,
( T_1 ) V_108 , 1 ) ;
break;
case V_112 :
F_46 ( V_103 -> V_105 ,
( T_1 ) V_106 ,
( T_1 ) V_108 , 1 ) ;
F_46 ( V_103 -> V_105 ,
( T_1 ) V_109 ,
( T_1 ) V_108 , 1 ) ;
break;
default:
break;
}
F_16 ( V_104 ,
L_26 ,
V_103 -> V_105 ) ;
}
