bool F_1 ( struct V_1 * V_2 )
{
bool V_3 ;
F_2 ( & V_2 -> V_4 ) ;
V_3 = V_2 -> V_3 ;
F_3 ( & V_2 -> V_4 ) ;
return V_3 ;
}
int F_4 ( struct V_1 * V_2 , bool V_3 )
{
int V_5 ;
F_2 ( & V_2 -> V_4 ) ;
V_2 -> V_3 = V_3 ;
F_3 ( & V_2 -> V_4 ) ;
if ( ! V_3 )
return 0 ;
if ( ! V_2 -> V_6 . V_7 )
return 0 ;
V_5 = F_5 ( V_2 -> V_6 . V_7 ) ;
if ( V_5 < 0 ) {
F_2 ( & V_2 -> V_4 ) ;
V_2 -> V_3 = false ;
F_3 ( & V_2 -> V_4 ) ;
}
return V_5 ;
}
struct V_8 *
F_6 ( struct V_1 * V_2 ,
struct V_9 * V_10 ,
unsigned int V_11 , T_1 V_12 )
{
switch ( V_12 ) {
case V_13 :
return F_7 ( V_10 , V_11 ) ;
case V_14 :
return & V_2 -> V_15 [ V_11 ] ;
default:
return NULL ;
}
}
void F_8 ( struct V_16 * V_6 ,
struct V_9 * V_10 )
{
struct V_17 V_18 ;
unsigned int V_11 ;
for ( V_11 = 0 ; V_11 < V_6 -> V_2 . V_19 - 1 ; ++ V_11 ) {
memset ( & V_18 , 0 , sizeof( V_18 ) ) ;
V_18 . V_11 = V_11 ;
V_18 . V_12 = V_10 ? V_13
: V_14 ;
F_9 ( V_6 , V_11 , V_20 , V_10 , & V_18 ) ;
}
}
static int F_10 ( struct V_16 * V_6 ,
struct V_9 * V_10 )
{
F_8 ( V_6 , V_10 ) ;
return 0 ;
}
static int F_11 ( struct V_21 * V_2 ,
const struct V_22 * V_23 ,
const struct V_22 * V_24 , T_1 V_25 )
{
struct V_1 * V_26 ;
if ( ! ( V_23 -> V_25 & V_27 ) )
return 0 ;
V_26 = F_12 ( V_23 -> V_2 , struct V_1 , V_6 . V_2 ) ;
if ( ! V_26 -> V_28 )
return 0 ;
if ( V_25 & V_29 ) {
if ( V_26 -> V_30 )
return - V_31 ;
V_26 -> V_30 = V_24 -> V_2 ;
V_26 -> V_32 = V_24 -> V_33 ;
} else {
V_26 -> V_30 = NULL ;
V_26 -> V_32 = 0 ;
}
return 0 ;
}
int F_13 ( struct V_34 * V_35 , struct V_1 * V_2 ,
unsigned int V_19 )
{
unsigned int V_36 ;
for ( V_36 = 0 ; V_36 < F_14 ( V_37 ) ; ++ V_36 ) {
if ( V_37 [ V_36 ] . type == V_2 -> type &&
V_37 [ V_36 ] . V_33 == V_2 -> V_33 ) {
V_2 -> V_28 = & V_37 [ V_36 ] ;
break;
}
}
if ( V_36 == F_14 ( V_37 ) )
return - V_38 ;
F_15 ( & V_2 -> V_4 ) ;
V_2 -> V_35 = V_35 ;
V_2 -> V_39 = V_19 - 1 ;
V_2 -> V_15 = F_16 ( V_35 -> V_40 ,
V_19 * sizeof( * V_2 -> V_15 ) ,
V_41 ) ;
if ( V_2 -> V_15 == NULL )
return - V_42 ;
V_2 -> V_43 = F_16 ( V_35 -> V_40 , V_19 * sizeof( * V_2 -> V_43 ) ,
V_41 ) ;
if ( V_2 -> V_43 == NULL )
return - V_42 ;
for ( V_36 = 0 ; V_36 < V_19 - 1 ; ++ V_36 )
V_2 -> V_43 [ V_36 ] . V_25 = V_44 ;
V_2 -> V_43 [ V_19 - 1 ] . V_25 = V_27 ;
return F_17 ( & V_2 -> V_6 . V_2 , V_19 ,
V_2 -> V_43 , 0 ) ;
}
void F_18 ( struct V_1 * V_2 )
{
if ( V_2 -> V_45 )
F_19 ( V_2 -> V_45 ) ;
if ( V_2 -> V_6 . V_7 )
F_20 ( V_2 -> V_6 . V_7 ) ;
F_21 ( & V_2 -> V_6 . V_2 ) ;
F_22 ( & V_2 -> V_4 ) ;
}
