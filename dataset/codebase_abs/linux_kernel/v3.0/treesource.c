struct V_1 * F_1 ( const char * V_2 )
{
V_3 = NULL ;
V_4 = 0 ;
F_2 ( V_2 ) ;
V_5 = V_6 -> V_7 ;
if ( F_3 () != 0 )
F_4 ( L_1 ) ;
if ( V_4 )
F_4 ( L_2 ) ;
return V_3 ;
}
static void F_5 ( T_1 * V_7 , int V_8 )
{
int V_9 ;
for ( V_9 = 0 ; V_9 < V_8 ; V_9 ++ )
fputc ( '\t' , V_7 ) ;
}
static int F_6 ( char V_10 )
{
return ( isprint ( V_10 )
|| ( V_10 == '\0' )
|| strchr ( L_3 , V_10 ) ) ;
}
static void F_7 ( T_1 * V_7 , struct V_11 V_12 )
{
const char * V_13 = V_12 . V_12 ;
int V_9 ;
struct V_14 * V_15 = V_12 . V_16 ;
assert ( V_13 [ V_12 . V_17 - 1 ] == '\0' ) ;
while ( V_15 && ( V_15 -> V_18 == 0 ) ) {
if ( V_15 -> type == V_19 )
fprintf ( V_7 , L_4 , V_15 -> V_20 ) ;
V_15 = V_15 -> V_21 ;
}
fprintf ( V_7 , L_5 ) ;
for ( V_9 = 0 ; V_9 < ( V_12 . V_17 - 1 ) ; V_9 ++ ) {
char V_10 = V_13 [ V_9 ] ;
switch ( V_10 ) {
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
while ( V_15 && ( V_15 -> V_18 < V_9 ) ) {
if ( V_15 -> type == V_19 ) {
assert ( V_15 -> V_18 == ( V_9 + 1 ) ) ;
fprintf ( V_7 , L_4 , V_15 -> V_20 ) ;
}
V_15 = V_15 -> V_21 ;
}
fprintf ( V_7 , L_5 ) ;
break;
default:
if ( isprint ( V_10 ) )
fprintf ( V_7 , L_16 , V_10 ) ;
else
fprintf ( V_7 , L_17 , V_10 ) ;
}
}
fprintf ( V_7 , L_5 ) ;
F_8 (m, LABEL) {
assert ( V_15 -> V_18 == V_12 . V_17 ) ;
fprintf ( V_7 , L_18 , V_15 -> V_20 ) ;
}
}
static void F_9 ( T_1 * V_7 , struct V_11 V_12 )
{
void * V_22 = V_12 . V_12 + V_12 . V_17 ;
T_2 * V_23 = ( T_2 * ) V_12 . V_12 ;
struct V_14 * V_15 = V_12 . V_16 ;
fprintf ( V_7 , L_19 ) ;
for (; ; ) {
while ( V_15 && ( V_15 -> V_18 <= ( ( char * ) V_23 - V_12 . V_12 ) ) ) {
if ( V_15 -> type == V_19 ) {
assert ( V_15 -> V_18 == ( ( char * ) V_23 - V_12 . V_12 ) ) ;
fprintf ( V_7 , L_4 , V_15 -> V_20 ) ;
}
V_15 = V_15 -> V_21 ;
}
fprintf ( V_7 , L_20 , F_10 ( * V_23 ++ ) ) ;
if ( ( void * ) V_23 >= V_22 )
break;
fprintf ( V_7 , L_21 ) ;
}
F_8 (m, LABEL) {
assert ( V_15 -> V_18 == V_12 . V_17 ) ;
fprintf ( V_7 , L_18 , V_15 -> V_20 ) ;
}
fprintf ( V_7 , L_22 ) ;
}
static void F_11 ( T_1 * V_7 , struct V_11 V_12 )
{
void * V_22 = V_12 . V_12 + V_12 . V_17 ;
const char * V_24 = V_12 . V_12 ;
struct V_14 * V_15 = V_12 . V_16 ;
fprintf ( V_7 , L_23 ) ;
for (; ; ) {
while ( V_15 && ( V_15 -> V_18 == ( V_24 - V_12 . V_12 ) ) ) {
if ( V_15 -> type == V_19 )
fprintf ( V_7 , L_4 , V_15 -> V_20 ) ;
V_15 = V_15 -> V_21 ;
}
fprintf ( V_7 , L_24 , * V_24 ++ ) ;
if ( ( const void * ) V_24 >= V_22 )
break;
fprintf ( V_7 , L_21 ) ;
}
F_8 (m, LABEL) {
assert ( V_15 -> V_18 == V_12 . V_17 ) ;
fprintf ( V_7 , L_18 , V_15 -> V_20 ) ;
}
fprintf ( V_7 , L_25 ) ;
}
static void F_12 ( T_1 * V_7 , struct V_25 * V_26 )
{
int V_17 = V_26 -> V_12 . V_17 ;
const char * V_27 = V_26 -> V_12 . V_12 ;
struct V_14 * V_15 = V_26 -> V_12 . V_16 ;
int V_28 = 0 , V_29 = 0 ;
int V_30 = 0 , V_31 = 0 ;
int V_9 ;
if ( V_17 == 0 ) {
fprintf ( V_7 , L_26 ) ;
return;
}
for ( V_9 = 0 ; V_9 < V_17 ; V_9 ++ ) {
if ( ! F_6 ( V_27 [ V_9 ] ) )
V_28 ++ ;
if ( V_27 [ V_9 ] == '\0' )
V_29 ++ ;
}
F_8 (m, LABEL) {
if ( ( V_15 -> V_18 > 0 ) && ( V_26 -> V_12 . V_12 [ V_15 -> V_18 - 1 ] != '\0' ) )
V_30 ++ ;
if ( ( V_15 -> V_18 % sizeof( T_2 ) ) != 0 )
V_31 ++ ;
}
fprintf ( V_7 , L_27 ) ;
if ( ( V_27 [ V_17 - 1 ] == '\0' ) && ( V_28 == 0 ) && ( V_29 < ( V_17 - V_29 ) )
&& ( V_30 == 0 ) ) {
F_7 ( V_7 , V_26 -> V_12 ) ;
} else if ( ( ( V_17 % sizeof( T_2 ) ) == 0 ) && ( V_31 == 0 ) ) {
F_9 ( V_7 , V_26 -> V_12 ) ;
} else {
F_11 ( V_7 , V_26 -> V_12 ) ;
}
fprintf ( V_7 , L_26 ) ;
}
static void F_13 ( T_1 * V_7 , struct V_32 * V_33 , int V_8 )
{
struct V_25 * V_26 ;
struct V_32 * V_34 ;
struct V_35 * V_36 ;
F_5 ( V_7 , V_8 ) ;
F_14 (tree->labels, l)
fprintf ( V_7 , L_4 , V_36 -> V_35 ) ;
if ( V_33 -> V_37 && ( * V_33 -> V_37 ) )
fprintf ( V_7 , L_28 , V_33 -> V_37 ) ;
else
fprintf ( V_7 , L_29 ) ;
F_15 (tree, prop) {
F_5 ( V_7 , V_8 + 1 ) ;
F_14 (prop->labels, l)
fprintf ( V_7 , L_4 , V_36 -> V_35 ) ;
fprintf ( V_7 , L_30 , V_26 -> V_37 ) ;
F_12 ( V_7 , V_26 ) ;
}
F_16 (tree, child) {
fprintf ( V_7 , L_31 ) ;
F_13 ( V_7 , V_34 , V_8 + 1 ) ;
}
F_5 ( V_7 , V_8 ) ;
fprintf ( V_7 , L_32 ) ;
}
void F_17 ( T_1 * V_7 , struct V_1 * V_38 )
{
struct V_39 * V_40 ;
fprintf ( V_7 , L_33 ) ;
for ( V_40 = V_38 -> V_41 ; V_40 ; V_40 = V_40 -> V_21 ) {
struct V_35 * V_36 ;
F_14 (re->labels, l)
fprintf ( V_7 , L_4 , V_36 -> V_35 ) ;
fprintf ( V_7 , L_34 ,
( unsigned long long ) V_40 -> V_40 . V_42 ,
( unsigned long long ) V_40 -> V_40 . V_43 ) ;
}
F_13 ( V_7 , V_38 -> V_44 , 0 ) ;
}
