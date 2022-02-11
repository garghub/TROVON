struct V_1 *
F_1 ( struct V_2 * V_3 ,
struct V_4 * V_5 ,
unsigned int V_6 , T_1 V_7 )
{
switch ( V_7 ) {
case V_8 :
return F_2 ( V_5 , V_6 ) ;
case V_9 :
return & V_3 -> V_10 [ V_6 ] ;
default:
return NULL ;
}
}
void F_3 ( struct V_11 * V_12 ,
struct V_4 * V_5 )
{
struct V_13 V_14 ;
unsigned int V_6 ;
for ( V_6 = 0 ; V_6 < V_12 -> V_3 . V_15 - 1 ; ++ V_6 ) {
memset ( & V_14 , 0 , sizeof( V_14 ) ) ;
V_14 . V_6 = V_6 ;
V_14 . V_7 = V_5 ? V_8
: V_9 ;
F_4 ( V_12 , V_6 , V_16 , V_5 , & V_14 ) ;
}
}
static int F_5 ( struct V_11 * V_12 ,
struct V_4 * V_5 )
{
F_3 ( V_12 , V_5 ) ;
return 0 ;
}
static int F_6 ( struct V_17 * V_3 ,
const struct V_18 * V_19 ,
const struct V_18 * V_20 , T_1 V_21 )
{
struct V_2 * V_22 ;
if ( ! ( V_19 -> V_21 & V_23 ) )
return 0 ;
V_22 = F_7 ( V_19 -> V_3 , struct V_2 , V_12 . V_3 ) ;
if ( ! V_22 -> V_24 )
return 0 ;
if ( V_21 & V_25 ) {
if ( V_22 -> V_26 )
return - V_27 ;
V_22 -> V_26 = V_20 -> V_3 ;
V_22 -> V_28 = V_20 -> V_29 ;
} else {
V_22 -> V_26 = NULL ;
V_22 -> V_28 = 0 ;
}
return 0 ;
}
int F_8 ( struct V_30 * V_31 , struct V_2 * V_3 ,
unsigned int V_15 )
{
unsigned int V_32 ;
for ( V_32 = 0 ; V_32 < F_9 ( V_33 ) ; ++ V_32 ) {
if ( V_33 [ V_32 ] . type == V_3 -> type &&
V_33 [ V_32 ] . V_29 == V_3 -> V_29 ) {
V_3 -> V_24 = & V_33 [ V_32 ] ;
break;
}
}
if ( V_32 == F_9 ( V_33 ) )
return - V_34 ;
V_3 -> V_31 = V_31 ;
V_3 -> V_35 = V_15 - 1 ;
V_3 -> V_10 = F_10 ( V_31 -> V_36 ,
V_15 * sizeof( * V_3 -> V_10 ) ,
V_37 ) ;
if ( V_3 -> V_10 == NULL )
return - V_38 ;
V_3 -> V_39 = F_10 ( V_31 -> V_36 , V_15 * sizeof( * V_3 -> V_39 ) ,
V_37 ) ;
if ( V_3 -> V_39 == NULL )
return - V_38 ;
for ( V_32 = 0 ; V_32 < V_15 - 1 ; ++ V_32 )
V_3 -> V_39 [ V_32 ] . V_21 = V_40 ;
V_3 -> V_39 [ V_15 - 1 ] . V_21 = V_23 ;
return F_11 ( & V_3 -> V_12 . V_3 , V_15 ,
V_3 -> V_39 , 0 ) ;
}
void F_12 ( struct V_2 * V_3 )
{
if ( V_3 -> V_12 . V_41 )
F_13 ( V_3 -> V_12 . V_41 ) ;
F_14 ( & V_3 -> V_12 . V_3 ) ;
}
