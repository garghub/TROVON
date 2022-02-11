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
struct V_1 * F_9 ( const char * V_17 )
{
struct V_1 * V_15 ;
T_1 V_18 ;
int V_19 ;
if ( ! * V_17 )
return F_3 ( - V_20 ) ;
V_18 = strlen ( V_17 ) ;
if ( V_18 & 1 )
return F_3 ( - V_20 ) ;
V_15 = F_2 ( sizeof( struct V_1 ) + V_18 / 2 ,
V_7 ) ;
if ( ! V_15 )
return F_3 ( - V_8 ) ;
V_15 -> V_9 = V_18 / 2 ;
V_19 = F_10 ( V_15 -> V_10 , V_17 , V_18 / 2 ) ;
if ( V_19 < 0 ) {
F_11 ( V_15 ) ;
return F_3 ( - V_20 ) ;
}
return V_15 ;
}
static bool F_12 ( const struct V_21 * V_21 ,
const struct V_22 * V_23 )
{
const struct V_13 * V_14 = V_13 ( V_21 ) ;
const struct V_1 * V_15 = V_23 -> V_24 ;
return F_6 ( V_14 , V_15 ,
F_4 ) ;
}
static bool F_13 ( const struct V_21 * V_21 ,
const struct V_22 * V_23 )
{
const struct V_13 * V_14 = V_13 ( V_21 ) ;
const struct V_1 * V_15 = V_23 -> V_24 ;
return F_6 ( V_14 , V_15 ,
F_5 ) ;
}
static int F_14 ( struct V_22 * V_23 )
{
struct V_1 * V_15 ;
const char * V_25 = V_23 -> V_26 ;
const char * V_17 ;
bool (* F_15)( const struct V_21 * , const struct V_22 * ) =
F_12 ;
if ( ! V_25 || ! * V_25 )
return - V_20 ;
if ( V_25 [ 0 ] == 'i' &&
V_25 [ 1 ] == 'd' &&
V_25 [ 2 ] == ':' ) {
V_17 = V_25 + 3 ;
F_15 = F_13 ;
} else if ( V_25 [ 0 ] == 'e' &&
V_25 [ 1 ] == 'x' &&
V_25 [ 2 ] == ':' ) {
V_17 = V_25 + 3 ;
} else {
goto V_27;
}
V_15 = F_9 ( V_17 ) ;
if ( F_16 ( V_15 ) )
return F_17 ( V_15 ) ;
V_23 -> V_24 = V_15 ;
V_23 -> F_15 = F_15 ;
V_23 -> V_28 = V_29 ;
return 0 ;
V_27:
return 0 ;
}
static void F_18 ( struct V_22 * V_23 )
{
F_11 ( V_23 -> V_24 ) ;
}
static void F_19 ( const struct V_21 * V_21 , struct V_30 * V_31 )
{
const struct V_32 * V_33 = V_32 ( V_21 ) ;
const struct V_13 * V_14 = V_13 ( V_21 ) ;
const struct V_1 * V_6 ;
const unsigned char * V_34 ;
int V_35 ;
F_20 ( V_31 , V_21 -> V_36 ) ;
if ( V_33 ) {
F_20 ( V_31 , L_1 ) ;
V_33 -> V_37 ( V_21 , V_31 ) ;
if ( V_14 && V_14 -> V_17 [ 1 ] ) {
V_6 = V_14 -> V_17 [ 1 ] ;
F_21 ( V_31 , ' ' ) ;
V_35 = V_6 -> V_9 ;
V_34 = V_6 -> V_10 ;
if ( V_35 > 4 ) {
V_34 += V_35 - 4 ;
V_35 = 4 ;
}
F_22 ( V_31 , L_2 , V_35 , V_34 ) ;
}
F_20 ( V_31 , L_3 ) ;
F_21 ( V_31 , ']' ) ;
}
}
static int F_23 ( struct V_38 * V_39 )
{
struct V_40 * V_41 ;
int V_19 ;
F_24 ( L_4 , V_42 ) ;
if ( V_39 -> V_43 == 0 )
return - V_20 ;
F_25 ( & V_44 ) ;
V_19 = - V_45 ;
F_26 (parser, &asymmetric_key_parsers, link) {
F_27 ( L_5 , V_41 -> V_46 ) ;
V_19 = V_41 -> V_47 ( V_39 ) ;
if ( V_19 != - V_45 ) {
F_27 ( L_6 ,
V_19 ) ;
break;
}
}
F_28 ( & V_44 ) ;
F_24 ( L_7 , V_42 , V_19 ) ;
return V_19 ;
}
static void F_29 ( struct V_38 * V_39 )
{
struct V_32 * V_33 = V_39 -> V_48 [ 0 ] ;
struct V_13 * V_14 = V_39 -> V_48 [ 1 ] ;
int V_16 ;
F_24 ( L_4 , V_42 ) ;
if ( V_33 ) {
V_33 -> V_49 ( V_39 -> V_50 [ 0 ] ) ;
F_30 ( V_33 -> V_51 ) ;
}
if ( V_14 ) {
for ( V_16 = 0 ; V_16 < F_8 ( V_14 -> V_17 ) ; V_16 ++ )
F_11 ( V_14 -> V_17 [ V_16 ] ) ;
F_11 ( V_14 ) ;
}
F_11 ( V_39 -> V_36 ) ;
}
static void F_31 ( struct V_21 * V_21 )
{
struct V_32 * V_33 = V_32 ( V_21 ) ;
struct V_13 * V_14 = V_21 -> V_48 . V_34 [ 1 ] ;
if ( V_33 ) {
V_33 -> V_49 ( V_21 -> V_50 . V_10 ) ;
F_30 ( V_33 -> V_51 ) ;
V_21 -> V_48 . V_34 [ 0 ] = NULL ;
}
if ( V_14 ) {
F_11 ( V_14 -> V_17 [ 0 ] ) ;
F_11 ( V_14 -> V_17 [ 1 ] ) ;
F_11 ( V_14 ) ;
V_21 -> V_48 . V_34 [ 1 ] = NULL ;
}
}
int F_32 ( struct V_40 * V_41 )
{
struct V_40 * V_52 ;
int V_19 ;
F_33 ( & V_44 ) ;
F_26 (cursor, &asymmetric_key_parsers, link) {
if ( strcmp ( V_52 -> V_46 , V_41 -> V_46 ) == 0 ) {
F_34 ( L_8 ,
V_41 -> V_46 ) ;
V_19 = - V_53 ;
goto V_54;
}
}
F_35 ( & V_41 -> V_55 , & V_56 ) ;
F_36 ( L_9 , V_41 -> V_46 ) ;
V_19 = 0 ;
V_54:
F_37 ( & V_44 ) ;
return V_19 ;
}
void F_38 ( struct V_40 * V_41 )
{
F_33 ( & V_44 ) ;
F_39 ( & V_41 -> V_55 ) ;
F_37 ( & V_44 ) ;
F_36 ( L_10 , V_41 -> V_46 ) ;
}
static int T_2 F_40 ( void )
{
return F_41 ( & V_57 ) ;
}
static void T_3 F_42 ( void )
{
F_43 ( & V_57 ) ;
}
