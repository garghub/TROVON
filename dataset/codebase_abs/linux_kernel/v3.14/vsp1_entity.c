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
} else {
V_22 -> V_26 = NULL ;
}
return 0 ;
}
int F_8 ( struct V_28 * V_29 , struct V_2 * V_3 ,
unsigned int V_15 )
{
static const struct {
unsigned int V_30 ;
unsigned int V_31 ;
} V_32 [] = {
{ V_33 , V_34 } ,
{ V_35 , V_36 } ,
{ V_37 , 0 } ,
{ V_38 , V_39 } ,
{ F_9 ( 0 ) , F_10 ( 0 ) } ,
{ F_9 ( 1 ) , F_10 ( 1 ) } ,
{ F_9 ( 2 ) , F_10 ( 2 ) } ,
{ F_9 ( 3 ) , F_10 ( 3 ) } ,
{ F_9 ( 4 ) , F_10 ( 4 ) } ,
{ V_40 , V_41 } ,
{ F_11 ( 0 ) , F_12 ( 0 ) } ,
{ F_11 ( 1 ) , F_12 ( 1 ) } ,
{ F_11 ( 2 ) , F_12 ( 2 ) } ,
{ F_13 ( 0 ) , 0 } ,
{ F_13 ( 1 ) , 0 } ,
{ F_13 ( 2 ) , 0 } ,
{ F_13 ( 3 ) , 0 } ,
} ;
unsigned int V_42 ;
for ( V_42 = 0 ; V_42 < F_14 ( V_32 ) ; ++ V_42 ) {
if ( V_32 [ V_42 ] . V_30 == V_3 -> V_30 ) {
V_3 -> V_24 = V_32 [ V_42 ] . V_31 ;
break;
}
}
if ( V_42 == F_14 ( V_32 ) )
return - V_43 ;
V_3 -> V_29 = V_29 ;
V_3 -> V_44 = V_15 - 1 ;
V_3 -> V_10 = F_15 ( V_29 -> V_45 ,
V_15 * sizeof( * V_3 -> V_10 ) ,
V_46 ) ;
if ( V_3 -> V_10 == NULL )
return - V_47 ;
V_3 -> V_48 = F_15 ( V_29 -> V_45 , V_15 * sizeof( * V_3 -> V_48 ) ,
V_46 ) ;
if ( V_3 -> V_48 == NULL )
return - V_47 ;
for ( V_42 = 0 ; V_42 < V_15 - 1 ; ++ V_42 )
V_3 -> V_48 [ V_42 ] . V_21 = V_49 ;
V_3 -> V_48 [ V_15 - 1 ] . V_21 = V_23 ;
return F_16 ( & V_3 -> V_12 . V_3 , V_15 ,
V_3 -> V_48 , 0 ) ;
}
void F_17 ( struct V_2 * V_3 )
{
if ( V_3 -> V_12 . V_50 )
F_18 ( V_3 -> V_12 . V_50 ) ;
F_19 ( & V_3 -> V_12 . V_3 ) ;
}
