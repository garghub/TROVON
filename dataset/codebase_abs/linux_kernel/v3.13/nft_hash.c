static unsigned int F_1 ( const struct V_1 * V_2 ,
unsigned int V_3 , unsigned int V_4 )
{
unsigned int V_5 ;
V_5 = F_2 ( V_2 -> V_2 , V_4 , V_6 ) ;
return ( ( V_7 ) V_5 * V_3 ) >> 32 ;
}
static bool F_3 ( const struct V_8 * V_9 ,
const struct V_1 * V_10 ,
struct V_1 * V_2 )
{
const struct V_11 * V_12 = F_4 ( V_9 ) ;
const struct V_13 * V_14 ;
unsigned int V_5 ;
V_5 = F_1 ( V_10 , V_12 -> V_3 , V_9 -> V_15 ) ;
F_5 (he, &priv->hash[h], hnode) {
if ( F_6 ( & V_14 -> V_10 , V_10 , V_9 -> V_15 ) )
continue;
if ( V_9 -> V_16 & V_17 )
F_7 ( V_2 , V_14 -> V_2 ) ;
return true ;
}
return false ;
}
static void F_8 ( const struct V_8 * V_9 ,
struct V_13 * V_14 )
{
F_9 ( & V_14 -> V_10 , V_18 ) ;
if ( V_9 -> V_16 & V_17 )
F_9 ( V_14 -> V_2 , V_9 -> V_19 ) ;
F_10 ( V_14 ) ;
}
static int F_11 ( const struct V_8 * V_9 ,
const struct V_20 * V_21 )
{
struct V_11 * V_12 = F_4 ( V_9 ) ;
struct V_13 * V_14 ;
unsigned int V_22 , V_5 ;
if ( V_21 -> V_16 != 0 )
return - V_23 ;
V_22 = sizeof( * V_14 ) ;
if ( V_9 -> V_16 & V_17 )
V_22 += sizeof( V_14 -> V_2 [ 0 ] ) ;
V_14 = F_12 ( V_22 , V_24 ) ;
if ( V_14 == NULL )
return - V_25 ;
F_7 ( & V_14 -> V_10 , & V_21 -> V_10 ) ;
if ( V_9 -> V_16 & V_17 )
F_7 ( V_14 -> V_2 , & V_21 -> V_2 ) ;
V_5 = F_1 ( & V_14 -> V_10 , V_12 -> V_3 , V_9 -> V_15 ) ;
F_13 ( & V_14 -> V_26 , & V_12 -> V_27 [ V_5 ] ) ;
return 0 ;
}
static void F_14 ( const struct V_8 * V_9 ,
const struct V_20 * V_21 )
{
struct V_13 * V_14 = V_21 -> V_28 ;
F_15 ( & V_14 -> V_26 ) ;
F_10 ( V_14 ) ;
}
static int F_16 ( const struct V_8 * V_9 , struct V_20 * V_21 )
{
const struct V_11 * V_12 = F_4 ( V_9 ) ;
struct V_13 * V_14 ;
unsigned int V_5 ;
V_5 = F_1 ( & V_21 -> V_10 , V_12 -> V_3 , V_9 -> V_15 ) ;
F_5 (he, &priv->hash[h], hnode) {
if ( F_6 ( & V_14 -> V_10 , & V_21 -> V_10 , V_9 -> V_15 ) )
continue;
V_21 -> V_28 = V_14 ;
V_21 -> V_16 = 0 ;
if ( V_9 -> V_16 & V_17 )
F_7 ( & V_21 -> V_2 , V_14 -> V_2 ) ;
return 0 ;
}
return - V_29 ;
}
static void F_17 ( const struct V_30 * V_31 , const struct V_8 * V_9 ,
struct V_32 * V_33 )
{
const struct V_11 * V_12 = F_4 ( V_9 ) ;
const struct V_13 * V_14 ;
struct V_20 V_21 ;
unsigned int V_34 ;
for ( V_34 = 0 ; V_34 < V_12 -> V_3 ; V_34 ++ ) {
F_5 (he, &priv->hash[i], hnode) {
if ( V_33 -> V_35 < V_33 -> V_36 )
goto V_37;
memcpy ( & V_21 . V_10 , & V_14 -> V_10 , sizeof( V_21 . V_10 ) ) ;
if ( V_9 -> V_16 & V_17 )
memcpy ( & V_21 . V_2 , V_14 -> V_2 , sizeof( V_21 . V_2 ) ) ;
V_21 . V_16 = 0 ;
V_33 -> V_38 = V_33 -> V_39 ( V_31 , V_9 , V_33 , & V_21 ) ;
if ( V_33 -> V_38 < 0 )
return;
V_37:
V_33 -> V_35 ++ ;
}
}
}
static unsigned int F_18 ( const struct V_40 * const V_41 [] )
{
return sizeof( struct V_11 ) ;
}
static int F_19 ( const struct V_8 * V_9 ,
const struct V_40 * const V_42 [] )
{
struct V_11 * V_12 = F_4 ( V_9 ) ;
unsigned int V_43 , V_34 ;
if ( F_20 ( ! V_44 ) ) {
F_21 ( & V_6 , 4 ) ;
V_44 = true ;
}
V_43 = 100 ;
V_43 = V_43 * 4 / 3 ;
V_12 -> V_27 = F_22 ( V_43 , sizeof( struct V_45 ) , V_24 ) ;
if ( V_12 -> V_27 == NULL )
return - V_25 ;
V_12 -> V_3 = V_43 ;
for ( V_34 = 0 ; V_34 < V_43 ; V_34 ++ )
F_23 ( & V_12 -> V_27 [ V_34 ] ) ;
return 0 ;
}
static void F_24 ( const struct V_8 * V_9 )
{
const struct V_11 * V_12 = F_4 ( V_9 ) ;
const struct V_46 * V_47 ;
struct V_13 * V_21 ;
unsigned int V_34 ;
for ( V_34 = 0 ; V_34 < V_12 -> V_3 ; V_34 ++ ) {
F_25 (elem, next, &priv->hash[i], hnode) {
F_26 ( & V_21 -> V_26 ) ;
F_8 ( V_9 , V_21 ) ;
}
}
F_10 ( V_12 -> V_27 ) ;
}
static int T_1 F_27 ( void )
{
return F_28 ( & V_48 ) ;
}
static void T_2 F_29 ( void )
{
F_30 ( & V_48 ) ;
}
