struct V_1 * F_1 ( const void * V_2 ,
T_1 V_3 ,
const void * V_4 ,
T_1 V_5 )
{
struct V_1 * V_6 ;
V_6 = F_2 ( sizeof( struct V_1 ) + V_3 + V_5 ,
V_7 ) ;
if ( ! V_6 )
return F_3 ( - V_8 ) ;
V_6 -> V_9 = V_3 + V_5 ;
memcpy ( V_6 -> V_10 , V_2 , V_3 ) ;
memcpy ( V_6 -> V_10 + V_3 , V_4 , V_5 ) ;
return V_6 ;
}
bool F_4 ( const struct V_1 * V_11 ,
const struct V_1 * V_12 )
{
if ( ! V_11 || ! V_12 )
return false ;
if ( V_11 -> V_9 != V_12 -> V_9 )
return false ;
return memcmp ( V_11 -> V_10 , V_12 -> V_10 , V_11 -> V_9 ) == 0 ;
}
bool F_5 ( const struct V_1 * V_11 ,
const struct V_1 * V_12 )
{
if ( ! V_11 || ! V_12 )
return false ;
if ( V_11 -> V_9 < V_12 -> V_9 )
return false ;
return memcmp ( V_11 -> V_10 + ( V_11 -> V_9 - V_12 -> V_9 ) ,
V_12 -> V_10 , V_12 -> V_9 ) == 0 ;
}
static bool F_6 (
const struct V_13 * V_14 ,
const struct V_1 * V_15 ,
bool (* F_7)( const struct V_1 * V_11 ,
const struct V_1 * V_12 ) )
{
int V_16 ;
if ( ! V_14 || ! V_15 )
return false ;
for ( V_16 = 0 ; V_16 < F_8 ( V_14 -> V_17 ) ; V_16 ++ )
if ( F_7 ( V_14 -> V_17 [ V_16 ] , V_15 ) )
return true ;
return false ;
}
inline int F_9 ( const char * V_17 ,
struct V_1 * V_15 ,
T_1 V_18 )
{
V_15 -> V_9 = V_18 ;
return F_10 ( V_15 -> V_10 , V_17 , V_18 ) ;
}
struct V_1 * F_11 ( const char * V_17 )
{
struct V_1 * V_15 ;
T_1 V_19 ;
int V_20 ;
if ( ! * V_17 )
return F_3 ( - V_21 ) ;
V_19 = strlen ( V_17 ) ;
if ( V_19 & 1 )
return F_3 ( - V_21 ) ;
V_15 = F_2 ( sizeof( struct V_1 ) + V_19 / 2 ,
V_7 ) ;
if ( ! V_15 )
return F_3 ( - V_8 ) ;
V_20 = F_9 ( V_17 , V_15 , V_19 / 2 ) ;
if ( V_20 < 0 ) {
F_12 ( V_15 ) ;
return F_3 ( - V_21 ) ;
}
return V_15 ;
}
static bool F_13 ( const struct V_22 * V_22 ,
const struct V_23 * V_24 )
{
const struct V_13 * V_14 = V_13 ( V_22 ) ;
const struct V_1 * V_15 = V_24 -> V_25 ;
return F_6 ( V_14 , V_15 ,
F_4 ) ;
}
static bool F_14 ( const struct V_22 * V_22 ,
const struct V_23 * V_24 )
{
const struct V_13 * V_14 = V_13 ( V_22 ) ;
const struct V_1 * V_15 = V_24 -> V_25 ;
return F_6 ( V_14 , V_15 ,
F_5 ) ;
}
static int F_15 ( struct V_23 * V_24 )
{
struct V_1 * V_15 ;
const char * V_26 = V_24 -> V_27 ;
const char * V_17 ;
bool (* F_16)( const struct V_22 * , const struct V_23 * ) =
F_13 ;
if ( ! V_26 || ! * V_26 )
return - V_21 ;
if ( V_26 [ 0 ] == 'i' &&
V_26 [ 1 ] == 'd' &&
V_26 [ 2 ] == ':' ) {
V_17 = V_26 + 3 ;
F_16 = F_14 ;
} else if ( V_26 [ 0 ] == 'e' &&
V_26 [ 1 ] == 'x' &&
V_26 [ 2 ] == ':' ) {
V_17 = V_26 + 3 ;
} else {
goto V_28;
}
V_15 = F_11 ( V_17 ) ;
if ( F_17 ( V_15 ) )
return F_18 ( V_15 ) ;
V_24 -> V_25 = V_15 ;
V_24 -> F_16 = F_16 ;
V_24 -> V_29 = V_30 ;
return 0 ;
V_28:
return 0 ;
}
static void F_19 ( struct V_23 * V_24 )
{
F_12 ( V_24 -> V_25 ) ;
}
static void F_20 ( const struct V_22 * V_22 , struct V_31 * V_32 )
{
const struct V_33 * V_34 = V_33 ( V_22 ) ;
const struct V_13 * V_14 = V_13 ( V_22 ) ;
const struct V_1 * V_6 ;
const unsigned char * V_35 ;
int V_36 ;
F_21 ( V_32 , V_22 -> V_37 ) ;
if ( V_34 ) {
F_21 ( V_32 , L_1 ) ;
V_34 -> V_38 ( V_22 , V_32 ) ;
if ( V_14 && V_14 -> V_17 [ 1 ] ) {
V_6 = V_14 -> V_17 [ 1 ] ;
F_22 ( V_32 , ' ' ) ;
V_36 = V_6 -> V_9 ;
V_35 = V_6 -> V_10 ;
if ( V_36 > 4 ) {
V_35 += V_36 - 4 ;
V_36 = 4 ;
}
F_23 ( V_32 , L_2 , V_36 , V_35 ) ;
}
F_21 ( V_32 , L_3 ) ;
F_22 ( V_32 , ']' ) ;
}
}
static int F_24 ( struct V_39 * V_40 )
{
struct V_41 * V_42 ;
int V_20 ;
F_25 ( L_4 , V_43 ) ;
if ( V_40 -> V_44 == 0 )
return - V_21 ;
F_26 ( & V_45 ) ;
V_20 = - V_46 ;
F_27 (parser, &asymmetric_key_parsers, link) {
F_28 ( L_5 , V_42 -> V_47 ) ;
V_20 = V_42 -> V_48 ( V_40 ) ;
if ( V_20 != - V_46 ) {
F_28 ( L_6 ,
V_20 ) ;
break;
}
}
F_29 ( & V_45 ) ;
F_25 ( L_7 , V_43 , V_20 ) ;
return V_20 ;
}
static void F_30 ( struct V_39 * V_40 )
{
struct V_33 * V_34 = V_40 -> V_49 [ 0 ] ;
struct V_13 * V_14 = V_40 -> V_49 [ 1 ] ;
int V_16 ;
F_25 ( L_4 , V_43 ) ;
if ( V_34 ) {
V_34 -> V_50 ( V_40 -> V_51 [ 0 ] ) ;
F_31 ( V_34 -> V_52 ) ;
}
if ( V_14 ) {
for ( V_16 = 0 ; V_16 < F_8 ( V_14 -> V_17 ) ; V_16 ++ )
F_12 ( V_14 -> V_17 [ V_16 ] ) ;
F_12 ( V_14 ) ;
}
F_12 ( V_40 -> V_37 ) ;
}
static void F_32 ( struct V_22 * V_22 )
{
struct V_33 * V_34 = V_33 ( V_22 ) ;
struct V_13 * V_14 = V_22 -> V_49 . V_35 [ 1 ] ;
if ( V_34 ) {
V_34 -> V_50 ( V_22 -> V_51 . V_10 ) ;
F_31 ( V_34 -> V_52 ) ;
V_22 -> V_49 . V_35 [ 0 ] = NULL ;
}
if ( V_14 ) {
F_12 ( V_14 -> V_17 [ 0 ] ) ;
F_12 ( V_14 -> V_17 [ 1 ] ) ;
F_12 ( V_14 ) ;
V_22 -> V_49 . V_35 [ 1 ] = NULL ;
}
}
int F_33 ( struct V_41 * V_42 )
{
struct V_41 * V_53 ;
int V_20 ;
F_34 ( & V_45 ) ;
F_27 (cursor, &asymmetric_key_parsers, link) {
if ( strcmp ( V_53 -> V_47 , V_42 -> V_47 ) == 0 ) {
F_35 ( L_8 ,
V_42 -> V_47 ) ;
V_20 = - V_54 ;
goto V_55;
}
}
F_36 ( & V_42 -> V_56 , & V_57 ) ;
F_37 ( L_9 , V_42 -> V_47 ) ;
V_20 = 0 ;
V_55:
F_38 ( & V_45 ) ;
return V_20 ;
}
void F_39 ( struct V_41 * V_42 )
{
F_34 ( & V_45 ) ;
F_40 ( & V_42 -> V_56 ) ;
F_38 ( & V_45 ) ;
F_37 ( L_10 , V_42 -> V_47 ) ;
}
static int T_2 F_41 ( void )
{
return F_42 ( & V_58 ) ;
}
static void T_3 F_43 ( void )
{
F_44 ( & V_58 ) ;
}
