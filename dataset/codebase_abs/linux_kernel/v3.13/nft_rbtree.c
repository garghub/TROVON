static bool F_1 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 ,
struct V_3 * V_5 )
{
const struct V_6 * V_7 = F_2 ( V_2 ) ;
const struct V_8 * V_9 , * V_10 = NULL ;
const struct V_11 * V_12 = V_7 -> V_13 . V_11 ;
int V_14 ;
while ( V_12 != NULL ) {
V_9 = F_3 ( V_12 , struct V_8 , V_15 ) ;
V_14 = F_4 ( & V_9 -> V_4 , V_4 , V_2 -> V_16 ) ;
if ( V_14 < 0 ) {
V_12 = V_12 -> V_17 ;
V_10 = V_9 ;
} else if ( V_14 > 0 )
V_12 = V_12 -> V_18 ;
else {
V_19:
if ( V_9 -> V_20 & V_21 )
goto V_22;
if ( V_2 -> V_20 & V_23 )
F_5 ( V_5 , V_9 -> V_5 ) ;
return true ;
}
}
if ( V_2 -> V_20 & V_24 && V_10 != NULL ) {
V_9 = V_10 ;
goto V_19;
}
V_22:
return false ;
}
static void F_6 ( const struct V_1 * V_2 ,
struct V_8 * V_9 )
{
F_7 ( & V_9 -> V_4 , V_25 ) ;
if ( V_2 -> V_20 & V_23 )
F_7 ( V_9 -> V_5 , V_2 -> V_26 ) ;
F_8 ( V_9 ) ;
}
static int F_9 ( const struct V_1 * V_2 ,
struct V_8 * V_27 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 ;
struct V_11 * V_12 , * * V_28 ;
int V_14 ;
V_12 = NULL ;
V_28 = & V_7 -> V_13 . V_11 ;
while ( * V_28 != NULL ) {
V_12 = * V_28 ;
V_9 = F_3 ( V_12 , struct V_8 , V_15 ) ;
V_14 = F_4 ( & V_9 -> V_4 , & V_27 -> V_4 , V_2 -> V_16 ) ;
if ( V_14 < 0 )
V_28 = & V_12 -> V_17 ;
else if ( V_14 > 0 )
V_28 = & V_12 -> V_18 ;
else
return - V_29 ;
}
F_10 ( & V_27 -> V_15 , V_12 , V_28 ) ;
F_11 ( & V_27 -> V_15 , & V_7 -> V_13 ) ;
return 0 ;
}
static int F_12 ( const struct V_1 * V_2 ,
const struct V_30 * V_31 )
{
struct V_8 * V_9 ;
unsigned int V_32 ;
int V_33 ;
V_32 = sizeof( * V_9 ) ;
if ( V_2 -> V_20 & V_23 )
V_32 += sizeof( V_9 -> V_5 [ 0 ] ) ;
V_9 = F_13 ( V_32 , V_34 ) ;
if ( V_9 == NULL )
return - V_35 ;
V_9 -> V_20 = V_31 -> V_20 ;
F_5 ( & V_9 -> V_4 , & V_31 -> V_4 ) ;
if ( V_2 -> V_20 & V_23 )
F_5 ( V_9 -> V_5 , & V_31 -> V_5 ) ;
V_33 = F_9 ( V_2 , V_9 ) ;
if ( V_33 < 0 )
F_8 ( V_9 ) ;
return V_33 ;
}
static void F_14 ( const struct V_1 * V_2 ,
const struct V_30 * V_31 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_31 -> V_36 ;
F_15 ( & V_9 -> V_15 , & V_7 -> V_13 ) ;
F_8 ( V_9 ) ;
}
static int F_16 ( const struct V_1 * V_2 , struct V_30 * V_31 )
{
const struct V_6 * V_7 = F_2 ( V_2 ) ;
const struct V_11 * V_12 = V_7 -> V_13 . V_11 ;
struct V_8 * V_9 ;
int V_14 ;
while ( V_12 != NULL ) {
V_9 = F_3 ( V_12 , struct V_8 , V_15 ) ;
V_14 = F_4 ( & V_9 -> V_4 , & V_31 -> V_4 , V_2 -> V_16 ) ;
if ( V_14 < 0 )
V_12 = V_12 -> V_17 ;
else if ( V_14 > 0 )
V_12 = V_12 -> V_18 ;
else {
V_31 -> V_36 = V_9 ;
if ( V_2 -> V_20 & V_23 )
F_5 ( & V_31 -> V_5 , V_9 -> V_5 ) ;
V_31 -> V_20 = V_9 -> V_20 ;
return 0 ;
}
}
return - V_37 ;
}
static void F_17 ( const struct V_38 * V_39 ,
const struct V_1 * V_2 ,
struct V_40 * V_41 )
{
const struct V_6 * V_7 = F_2 ( V_2 ) ;
const struct V_8 * V_9 ;
struct V_30 V_31 ;
struct V_11 * V_15 ;
for ( V_15 = F_18 ( & V_7 -> V_13 ) ; V_15 != NULL ; V_15 = F_19 ( V_15 ) ) {
if ( V_41 -> V_42 < V_41 -> V_43 )
goto V_44;
V_9 = F_3 ( V_15 , struct V_8 , V_15 ) ;
F_5 ( & V_31 . V_4 , & V_9 -> V_4 ) ;
if ( V_2 -> V_20 & V_23 )
F_5 ( & V_31 . V_5 , V_9 -> V_5 ) ;
V_31 . V_20 = V_9 -> V_20 ;
V_41 -> V_33 = V_41 -> V_45 ( V_39 , V_2 , V_41 , & V_31 ) ;
if ( V_41 -> V_33 < 0 )
return;
V_44:
V_41 -> V_42 ++ ;
}
}
static unsigned int F_20 ( const struct V_46 * const V_47 [] )
{
return sizeof( struct V_6 ) ;
}
static int F_21 ( const struct V_1 * V_2 ,
const struct V_46 * const V_47 [] )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
V_7 -> V_13 = V_48 ;
return 0 ;
}
static void F_22 ( const struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 ;
struct V_11 * V_15 ;
while ( ( V_15 = V_7 -> V_13 . V_11 ) != NULL ) {
F_15 ( V_15 , & V_7 -> V_13 ) ;
V_9 = F_3 ( V_15 , struct V_8 , V_15 ) ;
F_6 ( V_2 , V_9 ) ;
}
}
static int T_1 F_23 ( void )
{
return F_24 ( & V_49 ) ;
}
static void T_2 F_25 ( void )
{
F_26 ( & V_49 ) ;
}
