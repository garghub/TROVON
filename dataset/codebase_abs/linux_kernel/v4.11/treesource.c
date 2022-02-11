struct V_1 * F_1 ( const char * V_2 )
{
V_3 = NULL ;
V_4 = false ;
F_2 ( V_2 ) ;
V_5 = V_6 -> V_7 ;
V_8 . V_9 = V_6 ;
if ( F_3 () != 0 )
F_4 ( L_1 ) ;
if ( V_4 )
F_4 ( L_2 ) ;
return V_3 ;
}
static void F_5 ( T_1 * V_7 , int V_10 )
{
int V_11 ;
for ( V_11 = 0 ; V_11 < V_10 ; V_11 ++ )
fputc ( '\t' , V_7 ) ;
}
static bool F_6 ( char V_12 )
{
return ( isprint ( ( unsigned char ) V_12 )
|| ( V_12 == '\0' )
|| strchr ( L_3 , V_12 ) ) ;
}
static void F_7 ( T_1 * V_7 , struct V_13 V_14 )
{
const char * V_15 = V_14 . V_14 ;
int V_11 ;
struct V_16 * V_17 = V_14 . V_18 ;
assert ( V_15 [ V_14 . V_19 - 1 ] == '\0' ) ;
while ( V_17 && ( V_17 -> V_20 == 0 ) ) {
if ( V_17 -> type == V_21 )
fprintf ( V_7 , L_4 , V_17 -> V_22 ) ;
V_17 = V_17 -> V_23 ;
}
fprintf ( V_7 , L_5 ) ;
for ( V_11 = 0 ; V_11 < ( V_14 . V_19 - 1 ) ; V_11 ++ ) {
char V_12 = V_15 [ V_11 ] ;
switch ( V_12 ) {
case '\a' :
fprintf ( V_7 , L_6 ) ;
break;
case '\b' :
fprintf ( V_7 , L_7 ) ;
break;
case '\t' :
fprintf ( V_7 , L_8 ) ;
break;
case '\n' :
fprintf ( V_7 , L_9 ) ;
break;
case '\v' :
fprintf ( V_7 , L_10 ) ;
break;
case '\f' :
fprintf ( V_7 , L_11 ) ;
break;
case '\r' :
fprintf ( V_7 , L_12 ) ;
break;
case '\\' :
fprintf ( V_7 , L_13 ) ;
break;
case '\"' :
fprintf ( V_7 , L_14 ) ;
break;
case '\0' :
fprintf ( V_7 , L_15 ) ;
while ( V_17 && ( V_17 -> V_20 <= ( V_11 + 1 ) ) ) {
if ( V_17 -> type == V_21 ) {
assert ( V_17 -> V_20 == ( V_11 + 1 ) ) ;
fprintf ( V_7 , L_4 , V_17 -> V_22 ) ;
}
V_17 = V_17 -> V_23 ;
}
fprintf ( V_7 , L_5 ) ;
break;
default:
if ( isprint ( ( unsigned char ) V_12 ) )
fprintf ( V_7 , L_16 , V_12 ) ;
else
fprintf ( V_7 , L_17 , V_12 ) ;
}
}
fprintf ( V_7 , L_5 ) ;
F_8 (m, LABEL) {
assert ( V_17 -> V_20 == V_14 . V_19 ) ;
fprintf ( V_7 , L_18 , V_17 -> V_22 ) ;
}
}
static void F_9 ( T_1 * V_7 , struct V_13 V_14 )
{
void * V_24 = V_14 . V_14 + V_14 . V_19 ;
T_2 * V_25 = ( T_2 * ) V_14 . V_14 ;
struct V_16 * V_17 = V_14 . V_18 ;
fprintf ( V_7 , L_19 ) ;
for (; ; ) {
while ( V_17 && ( V_17 -> V_20 <= ( ( char * ) V_25 - V_14 . V_14 ) ) ) {
if ( V_17 -> type == V_21 ) {
assert ( V_17 -> V_20 == ( ( char * ) V_25 - V_14 . V_14 ) ) ;
fprintf ( V_7 , L_4 , V_17 -> V_22 ) ;
}
V_17 = V_17 -> V_23 ;
}
fprintf ( V_7 , L_20 , F_10 ( * V_25 ++ ) ) ;
if ( ( void * ) V_25 >= V_24 )
break;
fprintf ( V_7 , L_21 ) ;
}
F_8 (m, LABEL) {
assert ( V_17 -> V_20 == V_14 . V_19 ) ;
fprintf ( V_7 , L_18 , V_17 -> V_22 ) ;
}
fprintf ( V_7 , L_22 ) ;
}
static void F_11 ( T_1 * V_7 , struct V_13 V_14 )
{
void * V_24 = V_14 . V_14 + V_14 . V_19 ;
const char * V_26 = V_14 . V_14 ;
struct V_16 * V_17 = V_14 . V_18 ;
fprintf ( V_7 , L_23 ) ;
for (; ; ) {
while ( V_17 && ( V_17 -> V_20 == ( V_26 - V_14 . V_14 ) ) ) {
if ( V_17 -> type == V_21 )
fprintf ( V_7 , L_4 , V_17 -> V_22 ) ;
V_17 = V_17 -> V_23 ;
}
fprintf ( V_7 , L_24 , ( unsigned char ) ( * V_26 ++ ) ) ;
if ( ( const void * ) V_26 >= V_24 )
break;
fprintf ( V_7 , L_21 ) ;
}
F_8 (m, LABEL) {
assert ( V_17 -> V_20 == V_14 . V_19 ) ;
fprintf ( V_7 , L_18 , V_17 -> V_22 ) ;
}
fprintf ( V_7 , L_25 ) ;
}
static void F_12 ( T_1 * V_7 , struct V_27 * V_28 )
{
int V_19 = V_28 -> V_14 . V_19 ;
const char * V_29 = V_28 -> V_14 . V_14 ;
struct V_16 * V_17 = V_28 -> V_14 . V_18 ;
int V_30 = 0 , V_31 = 0 ;
int V_32 = 0 , V_33 = 0 ;
int V_11 ;
if ( V_19 == 0 ) {
fprintf ( V_7 , L_26 ) ;
return;
}
for ( V_11 = 0 ; V_11 < V_19 ; V_11 ++ ) {
if ( ! F_6 ( V_29 [ V_11 ] ) )
V_30 ++ ;
if ( V_29 [ V_11 ] == '\0' )
V_31 ++ ;
}
F_8 (m, LABEL) {
if ( ( V_17 -> V_20 > 0 ) && ( V_28 -> V_14 . V_14 [ V_17 -> V_20 - 1 ] != '\0' ) )
V_32 ++ ;
if ( ( V_17 -> V_20 % sizeof( T_2 ) ) != 0 )
V_33 ++ ;
}
fprintf ( V_7 , L_27 ) ;
if ( ( V_29 [ V_19 - 1 ] == '\0' ) && ( V_30 == 0 ) && ( V_31 < ( V_19 - V_31 ) )
&& ( V_32 == 0 ) ) {
F_7 ( V_7 , V_28 -> V_14 ) ;
} else if ( ( ( V_19 % sizeof( T_2 ) ) == 0 ) && ( V_33 == 0 ) ) {
F_9 ( V_7 , V_28 -> V_14 ) ;
} else {
F_11 ( V_7 , V_28 -> V_14 ) ;
}
fprintf ( V_7 , L_26 ) ;
}
static void F_13 ( T_1 * V_7 , struct V_34 * V_35 , int V_10 )
{
struct V_27 * V_28 ;
struct V_34 * V_36 ;
struct V_37 * V_38 ;
F_5 ( V_7 , V_10 ) ;
F_14 (tree->labels, l)
fprintf ( V_7 , L_4 , V_38 -> V_37 ) ;
if ( V_35 -> V_39 && ( * V_35 -> V_39 ) )
fprintf ( V_7 , L_28 , V_35 -> V_39 ) ;
else
fprintf ( V_7 , L_29 ) ;
F_15 (tree, prop) {
F_5 ( V_7 , V_10 + 1 ) ;
F_14 (prop->labels, l)
fprintf ( V_7 , L_4 , V_38 -> V_37 ) ;
fprintf ( V_7 , L_30 , V_28 -> V_39 ) ;
F_12 ( V_7 , V_28 ) ;
}
F_16 (tree, child) {
fprintf ( V_7 , L_31 ) ;
F_13 ( V_7 , V_36 , V_10 + 1 ) ;
}
F_5 ( V_7 , V_10 ) ;
fprintf ( V_7 , L_32 ) ;
}
void F_17 ( T_1 * V_7 , struct V_1 * V_40 )
{
struct V_41 * V_42 ;
fprintf ( V_7 , L_33 ) ;
for ( V_42 = V_40 -> V_43 ; V_42 ; V_42 = V_42 -> V_23 ) {
struct V_37 * V_38 ;
F_14 (re->labels, l)
fprintf ( V_7 , L_4 , V_38 -> V_37 ) ;
fprintf ( V_7 , L_34 ,
( unsigned long long ) V_42 -> V_42 . V_44 ,
( unsigned long long ) V_42 -> V_42 . V_45 ) ;
}
F_13 ( V_7 , V_40 -> V_46 , 0 ) ;
}
