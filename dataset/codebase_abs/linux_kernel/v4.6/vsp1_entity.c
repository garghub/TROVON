bool F_1 ( struct V_1 * V_2 )
{
unsigned long V_3 ;
bool V_4 ;
F_2 ( & V_2 -> V_5 , V_3 ) ;
V_4 = V_2 -> V_4 ;
F_3 ( & V_2 -> V_5 , V_3 ) ;
return V_4 ;
}
int F_4 ( struct V_1 * V_2 , bool V_4 )
{
unsigned long V_3 ;
int V_6 ;
F_2 ( & V_2 -> V_5 , V_3 ) ;
V_2 -> V_4 = V_4 ;
F_3 ( & V_2 -> V_5 , V_3 ) ;
if ( ! V_4 )
return 0 ;
if ( ! V_2 -> V_7 -> V_8 -> V_9 || ! V_2 -> V_10 . V_11 )
return 0 ;
V_6 = F_5 ( V_2 -> V_10 . V_11 ) ;
if ( V_6 < 0 ) {
F_2 ( & V_2 -> V_5 , V_3 ) ;
V_2 -> V_4 = false ;
F_3 ( & V_2 -> V_5 , V_3 ) ;
}
return V_6 ;
}
void F_6 ( struct V_1 * V_12 )
{
struct V_1 * V_13 ;
if ( V_12 -> V_14 -> V_15 == 0 )
return;
V_13 = F_7 ( V_12 -> V_13 , struct V_1 , V_10 . V_2 ) ;
F_8 ( V_12 , V_12 -> V_14 -> V_15 ,
V_13 -> V_14 -> V_16 [ V_12 -> V_17 ] ) ;
}
struct V_18 *
F_9 ( struct V_1 * V_2 ,
struct V_19 * V_20 ,
unsigned int V_21 , T_1 V_22 )
{
switch ( V_22 ) {
case V_23 :
return F_10 ( & V_2 -> V_10 , V_20 , V_21 ) ;
case V_24 :
return & V_2 -> V_25 [ V_21 ] ;
default:
return NULL ;
}
}
void F_11 ( struct V_26 * V_10 ,
struct V_19 * V_20 )
{
struct V_27 V_28 ;
unsigned int V_21 ;
for ( V_21 = 0 ; V_21 < V_10 -> V_2 . V_29 - 1 ; ++ V_21 ) {
memset ( & V_28 , 0 , sizeof( V_28 ) ) ;
V_28 . V_21 = V_21 ;
V_28 . V_22 = V_20 ? V_23
: V_24 ;
F_12 ( V_10 , V_21 , V_30 , V_20 , & V_28 ) ;
}
}
static int F_13 ( struct V_26 * V_10 ,
struct V_31 * V_32 )
{
F_11 ( V_10 , V_32 -> V_21 ) ;
return 0 ;
}
int F_14 ( struct V_33 * V_2 ,
const struct V_34 * V_35 ,
const struct V_34 * V_36 , T_1 V_3 )
{
struct V_1 * V_12 ;
if ( ! ( V_35 -> V_3 & V_37 ) )
return 0 ;
V_12 = F_7 ( V_35 -> V_2 , struct V_1 , V_10 . V_2 ) ;
if ( ! V_12 -> V_14 )
return 0 ;
if ( V_3 & V_38 ) {
if ( V_12 -> V_13 )
return - V_39 ;
V_12 -> V_13 = V_36 -> V_2 ;
V_12 -> V_17 = V_36 -> V_40 ;
} else {
V_12 -> V_13 = NULL ;
V_12 -> V_17 = 0 ;
}
return 0 ;
}
int F_15 ( struct V_41 * V_7 , struct V_1 * V_2 ,
unsigned int V_29 )
{
unsigned int V_42 ;
for ( V_42 = 0 ; V_42 < F_16 ( V_43 ) ; ++ V_42 ) {
if ( V_43 [ V_42 ] . type == V_2 -> type &&
V_43 [ V_42 ] . V_40 == V_2 -> V_40 ) {
V_2 -> V_14 = & V_43 [ V_42 ] ;
break;
}
}
if ( V_42 == F_16 ( V_43 ) )
return - V_44 ;
F_17 ( & V_2 -> V_5 ) ;
V_2 -> V_7 = V_7 ;
V_2 -> V_45 = V_29 - 1 ;
V_2 -> V_25 = F_18 ( V_7 -> V_46 ,
V_29 * sizeof( * V_2 -> V_25 ) ,
V_47 ) ;
if ( V_2 -> V_25 == NULL )
return - V_48 ;
V_2 -> V_49 = F_18 ( V_7 -> V_46 , V_29 * sizeof( * V_2 -> V_49 ) ,
V_47 ) ;
if ( V_2 -> V_49 == NULL )
return - V_48 ;
for ( V_42 = 0 ; V_42 < V_29 - 1 ; ++ V_42 )
V_2 -> V_49 [ V_42 ] . V_3 = V_50 ;
V_2 -> V_49 [ V_29 - 1 ] . V_3 = V_37 ;
return F_19 ( & V_2 -> V_10 . V_2 , V_29 ,
V_2 -> V_49 ) ;
}
void F_20 ( struct V_1 * V_2 )
{
if ( V_2 -> V_10 . V_11 )
F_21 ( V_2 -> V_10 . V_11 ) ;
F_22 ( & V_2 -> V_10 . V_2 ) ;
}
