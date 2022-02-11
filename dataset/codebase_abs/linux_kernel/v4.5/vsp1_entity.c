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
if ( ! V_2 -> V_7 . V_8 )
return 0 ;
V_6 = F_5 ( V_2 -> V_7 . V_8 ) ;
if ( V_6 < 0 ) {
F_2 ( & V_2 -> V_5 , V_3 ) ;
V_2 -> V_4 = false ;
F_3 ( & V_2 -> V_5 , V_3 ) ;
}
return V_6 ;
}
struct V_9 *
F_6 ( struct V_1 * V_2 ,
struct V_10 * V_11 ,
unsigned int V_12 , T_1 V_13 )
{
switch ( V_13 ) {
case V_14 :
return F_7 ( & V_2 -> V_7 , V_11 , V_12 ) ;
case V_15 :
return & V_2 -> V_16 [ V_12 ] ;
default:
return NULL ;
}
}
void F_8 ( struct V_17 * V_7 ,
struct V_10 * V_11 )
{
struct V_18 V_19 ;
unsigned int V_12 ;
for ( V_12 = 0 ; V_12 < V_7 -> V_2 . V_20 - 1 ; ++ V_12 ) {
memset ( & V_19 , 0 , sizeof( V_19 ) ) ;
V_19 . V_12 = V_12 ;
V_19 . V_13 = V_11 ? V_14
: V_15 ;
F_9 ( V_7 , V_12 , V_21 , V_11 , & V_19 ) ;
}
}
static int F_10 ( struct V_17 * V_7 ,
struct V_22 * V_23 )
{
F_8 ( V_7 , V_23 -> V_12 ) ;
return 0 ;
}
static int F_11 ( struct V_24 * V_2 ,
const struct V_25 * V_26 ,
const struct V_25 * V_27 , T_1 V_3 )
{
struct V_1 * V_28 ;
if ( ! ( V_26 -> V_3 & V_29 ) )
return 0 ;
V_28 = F_12 ( V_26 -> V_2 , struct V_1 , V_7 . V_2 ) ;
if ( ! V_28 -> V_30 )
return 0 ;
if ( V_3 & V_31 ) {
if ( V_28 -> V_32 )
return - V_33 ;
V_28 -> V_32 = V_27 -> V_2 ;
V_28 -> V_34 = V_27 -> V_35 ;
} else {
V_28 -> V_32 = NULL ;
V_28 -> V_34 = 0 ;
}
return 0 ;
}
int F_13 ( struct V_36 * V_37 , struct V_1 * V_2 ,
unsigned int V_20 )
{
unsigned int V_38 ;
for ( V_38 = 0 ; V_38 < F_14 ( V_39 ) ; ++ V_38 ) {
if ( V_39 [ V_38 ] . type == V_2 -> type &&
V_39 [ V_38 ] . V_35 == V_2 -> V_35 ) {
V_2 -> V_30 = & V_39 [ V_38 ] ;
break;
}
}
if ( V_38 == F_14 ( V_39 ) )
return - V_40 ;
F_15 ( & V_2 -> V_5 ) ;
V_2 -> V_37 = V_37 ;
V_2 -> V_41 = V_20 - 1 ;
V_2 -> V_16 = F_16 ( V_37 -> V_42 ,
V_20 * sizeof( * V_2 -> V_16 ) ,
V_43 ) ;
if ( V_2 -> V_16 == NULL )
return - V_44 ;
V_2 -> V_45 = F_16 ( V_37 -> V_42 , V_20 * sizeof( * V_2 -> V_45 ) ,
V_43 ) ;
if ( V_2 -> V_45 == NULL )
return - V_44 ;
for ( V_38 = 0 ; V_38 < V_20 - 1 ; ++ V_38 )
V_2 -> V_45 [ V_38 ] . V_3 = V_46 ;
V_2 -> V_45 [ V_20 - 1 ] . V_3 = V_29 ;
return F_17 ( & V_2 -> V_7 . V_2 , V_20 ,
V_2 -> V_45 ) ;
}
void F_18 ( struct V_1 * V_2 )
{
if ( V_2 -> V_47 )
F_19 ( V_2 -> V_47 ) ;
if ( V_2 -> V_7 . V_8 )
F_20 ( V_2 -> V_7 . V_8 ) ;
F_21 ( & V_2 -> V_7 . V_2 ) ;
}
