static int T_1 F_1 ( char * V_1 )
{
if ( ! V_1 )
return 1 ;
if ( strncmp ( V_1 , L_1 , 3 ) == 0 ) {
struct V_2 * V_3 = & V_4 . V_5 ;
T_2 V_6 = ( strlen ( V_1 ) - 3 ) / 2 ;
int V_7 ;
if ( V_6 == 0 || V_6 > sizeof( V_4 . V_8 ) ) {
F_2 ( L_2 ) ;
return 1 ;
}
V_7 = F_3 ( V_1 + 3 , V_3 , V_6 ) ;
if ( V_7 < 0 )
F_2 ( L_3 ) ;
else
V_9 = V_3 ;
} else if ( strcmp ( V_1 , L_4 ) == 0 ) {
V_10 = true ;
}
return 1 ;
}
int F_4 ( struct V_11 * V_12 ,
const struct V_13 * type ,
const union V_14 * V_15 ,
struct V_11 * V_16 )
{
const struct V_17 * V_18 ;
struct V_11 * V_11 ;
int V_7 ;
F_5 ( L_5 , V_19 ) ;
if ( ! V_16 )
return - V_20 ;
if ( type != & V_21 )
return - V_22 ;
V_18 = V_15 -> V_8 [ V_23 ] ;
if ( ! V_18 -> V_24 [ 0 ] && ! V_18 -> V_24 [ 1 ] )
return - V_20 ;
if ( V_9 && ! F_6 ( V_18 -> V_24 [ 1 ] , V_9 ) )
return - V_25 ;
V_11 = F_7 ( V_16 ,
V_18 -> V_24 [ 0 ] , V_18 -> V_24 [ 1 ] ,
false ) ;
if ( F_8 ( V_11 ) )
return - V_20 ;
if ( V_10 && ! F_9 ( V_26 , & V_11 -> V_27 ) )
V_7 = - V_20 ;
else
V_7 = F_10 ( V_11 , V_18 ) ;
F_11 ( V_11 ) ;
return V_7 ;
}
static bool F_12 ( const struct V_28 * V_29 ,
const struct V_2 * V_30 )
{
return ( F_13 ( V_29 -> V_5 [ 0 ] , V_30 ) ||
F_13 ( V_29 -> V_5 [ 1 ] , V_30 ) ) ;
}
static int F_14 ( struct V_11 * V_12 ,
const struct V_13 * type ,
const union V_14 * V_15 ,
struct V_11 * V_31 , bool V_32 )
{
const struct V_17 * V_18 ;
struct V_11 * V_11 = NULL ;
int V_7 ;
F_5 ( L_5 , V_19 ) ;
if ( ! V_12 )
return - V_20 ;
else if ( V_12 -> type != & V_33 )
return - V_22 ;
if ( ! V_31 && ! V_32 )
return - V_20 ;
if ( type != & V_21 )
return - V_22 ;
V_18 = V_15 -> V_8 [ V_23 ] ;
if ( ! V_18 -> V_24 [ 0 ] && ! V_18 -> V_24 [ 1 ] )
return - V_20 ;
if ( V_31 ) {
if ( V_31 -> type == & V_33 ) {
V_11 = F_7 ( V_31 , V_18 -> V_24 [ 0 ] ,
V_18 -> V_24 [ 1 ] , false ) ;
if ( F_8 ( V_11 ) )
V_11 = NULL ;
} else if ( V_31 -> type == & V_21 ) {
const struct V_28 * V_34 ;
V_34 = V_28 ( V_31 ) ;
if ( ! V_18 -> V_24 [ 0 ] || ! V_18 -> V_24 [ 1 ] ) {
const struct V_2 * V_35 ;
V_35 = V_18 -> V_24 [ 0 ] ? : V_18 -> V_24 [ 1 ] ;
if ( F_12 ( V_34 , V_35 ) )
V_11 = F_15 ( V_31 ) ;
} else if ( F_13 ( V_34 -> V_5 [ 1 ] ,
V_18 -> V_24 [ 1 ] ) &&
F_12 ( V_34 ,
V_18 -> V_24 [ 0 ] ) ) {
V_11 = F_15 ( V_31 ) ;
}
} else {
return - V_22 ;
}
}
if ( V_32 && ! V_11 ) {
V_11 = F_7 ( V_12 , V_18 -> V_24 [ 0 ] ,
V_18 -> V_24 [ 1 ] , false ) ;
if ( F_8 ( V_11 ) )
V_11 = NULL ;
}
if ( ! V_11 )
return - V_20 ;
V_7 = F_16 ( V_11 ) ;
if ( V_7 == 0 )
V_7 = F_10 ( V_11 , V_18 ) ;
F_11 ( V_11 ) ;
return V_7 ;
}
int F_17 ( struct V_11 * V_12 ,
const struct V_13 * type ,
const union V_14 * V_15 ,
struct V_11 * V_31 )
{
return F_14 ( V_12 , type , V_15 , V_31 ,
false ) ;
}
int F_18 ( struct V_11 * V_12 ,
const struct V_13 * type ,
const union V_14 * V_15 ,
struct V_11 * V_31 )
{
return F_14 ( V_12 , type , V_15 , V_31 ,
true ) ;
}
