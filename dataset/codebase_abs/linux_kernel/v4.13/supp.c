void F_1 ( struct V_1 * V_2 )
{
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
F_2 ( & V_2 -> V_3 ) ;
F_2 ( & V_2 -> V_4 ) ;
F_2 ( & V_2 -> V_5 ) ;
F_3 ( & V_2 -> V_6 ) ;
F_3 ( & V_2 -> V_7 ) ;
}
void F_4 ( struct V_1 * V_2 )
{
F_5 ( & V_2 -> V_3 ) ;
F_5 ( & V_2 -> V_4 ) ;
F_5 ( & V_2 -> V_5 ) ;
}
T_1 F_6 ( struct V_8 * V_9 , T_1 V_10 , T_2 V_11 ,
struct V_12 * V_13 )
{
bool V_14 ;
struct V_15 * V_15 = F_7 ( V_9 -> V_16 ) ;
struct V_1 * V_2 = & V_15 -> V_2 ;
T_1 V_17 ;
while ( F_8 ( & V_2 -> V_4 ) ) {
F_9 ( & V_2 -> V_3 ) ;
V_14 = ! V_2 -> V_9 ;
F_10 ( & V_2 -> V_3 ) ;
if ( V_14 )
return V_18 ;
}
V_2 -> V_10 = V_10 ;
V_2 -> V_11 = V_11 ;
V_2 -> V_13 = V_13 ;
V_2 -> V_19 = true ;
F_11 ( & V_2 -> V_6 ) ;
while ( F_12 ( & V_2 -> V_7 ) ) {
F_9 ( & V_2 -> V_3 ) ;
V_14 = ! V_2 -> V_9 ;
if ( V_14 ) {
V_2 -> V_17 = V_18 ;
F_3 ( & V_2 -> V_6 ) ;
}
F_10 ( & V_2 -> V_3 ) ;
if ( V_14 )
break;
}
V_17 = V_2 -> V_17 ;
V_2 -> V_13 = NULL ;
V_2 -> V_19 = false ;
F_10 ( & V_2 -> V_4 ) ;
return V_17 ;
}
int F_13 ( struct V_8 * V_9 , T_1 * V_10 , T_1 * V_11 ,
struct V_12 * V_13 )
{
struct V_20 * V_16 = V_9 -> V_16 ;
struct V_15 * V_15 = F_7 ( V_16 ) ;
struct V_1 * V_2 = & V_15 -> V_2 ;
int V_21 ;
F_9 ( & V_2 -> V_5 ) ;
if ( V_2 -> V_22 ) {
if ( V_2 -> V_19 ) {
V_2 -> V_17 = V_18 ;
V_2 -> V_22 = false ;
F_11 ( & V_2 -> V_7 ) ;
}
}
if ( F_12 ( & V_2 -> V_6 ) ) {
V_21 = - V_23 ;
goto V_24;
}
if ( * V_11 < V_2 -> V_11 ) {
V_2 -> V_17 = V_18 ;
V_21 = - V_25 ;
F_11 ( & V_2 -> V_7 ) ;
goto V_24;
}
* V_10 = V_2 -> V_10 ;
* V_11 = V_2 -> V_11 ;
memcpy ( V_13 , V_2 -> V_13 ,
sizeof( struct V_12 ) * V_2 -> V_11 ) ;
V_2 -> V_22 = true ;
V_21 = 0 ;
V_24:
F_10 ( & V_2 -> V_5 ) ;
return V_21 ;
}
int F_14 ( struct V_8 * V_9 , T_1 V_17 , T_1 V_11 ,
struct V_12 * V_13 )
{
struct V_20 * V_16 = V_9 -> V_16 ;
struct V_15 * V_15 = F_7 ( V_16 ) ;
struct V_1 * V_2 = & V_15 -> V_2 ;
T_2 V_26 ;
int V_21 = 0 ;
F_9 ( & V_2 -> V_5 ) ;
if ( ! V_2 -> V_22 ) {
V_21 = - V_27 ;
goto V_24;
}
if ( V_11 != V_2 -> V_11 ) {
V_21 = - V_25 ;
goto V_24;
}
for ( V_26 = 0 ; V_26 < V_11 ; V_26 ++ ) {
struct V_12 * V_28 = V_2 -> V_13 + V_26 ;
switch ( V_28 -> V_29 ) {
case V_30 :
case V_31 :
V_28 -> V_32 . V_33 . V_34 = V_13 [ V_26 ] . V_32 . V_33 . V_34 ;
V_28 -> V_32 . V_33 . V_35 = V_13 [ V_26 ] . V_32 . V_33 . V_35 ;
V_28 -> V_32 . V_33 . V_36 = V_13 [ V_26 ] . V_32 . V_33 . V_36 ;
break;
case V_37 :
case V_38 :
V_28 -> V_32 . V_39 . V_40 = V_13 [ V_26 ] . V_32 . V_39 . V_40 ;
break;
default:
break;
}
}
V_2 -> V_17 = V_17 ;
V_2 -> V_22 = false ;
F_11 ( & V_2 -> V_7 ) ;
V_24:
F_10 ( & V_2 -> V_5 ) ;
return V_21 ;
}
