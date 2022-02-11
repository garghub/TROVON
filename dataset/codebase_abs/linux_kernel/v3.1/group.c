static bool F_1 ( const struct V_1 * V_2 ,
const struct V_1 * V_3 )
{
return F_2 ( V_2 , struct V_4 , V_5 ) -> V_6 ==
F_2 ( V_3 , struct V_4 , V_5 ) -> V_6 ;
}
static bool F_3 ( const struct V_1 * V_2 ,
const struct V_1 * V_3 )
{
return ! memcmp ( & F_2 ( V_2 , struct V_7 , V_5 )
-> V_8 ,
& F_2 ( V_3 , struct V_7 , V_5 )
-> V_8 ,
sizeof( F_2 ( V_2 , struct V_7 , V_5 )
-> V_8 ) ) ;
}
int F_4 ( struct V_9 * V_10 , const T_1 type )
{
struct V_11 * V_12 = F_5 ( V_10 , type ) ;
int error = - V_13 ;
if ( ! V_12 )
return - V_14 ;
V_10 -> V_15 = & V_12 -> V_16 ;
if ( type == V_17 ) {
struct V_4 V_18 = { } ;
V_18 . V_6 = F_6 ( F_7 ( V_10 ) ) ;
if ( ! V_18 . V_6 ) {
error = - V_14 ;
goto V_19;
}
error = F_8 ( & V_18 . V_5 , sizeof( V_18 ) , V_10 ,
F_1 ) ;
F_9 ( V_18 . V_6 ) ;
} else if ( type == V_20 ) {
struct V_7 V_18 = { } ;
if ( V_10 -> V_21 [ 0 ] == '@' ||
! F_10 ( V_10 , & V_18 . V_8 ) )
goto V_19;
error = F_8 ( & V_18 . V_5 , sizeof( V_18 ) , V_10 ,
F_3 ) ;
}
V_19:
F_11 ( V_12 ) ;
return error ;
}
const struct V_22 *
F_12 ( const struct V_22 * V_23 ,
const struct V_11 * V_12 )
{
struct V_4 * V_24 ;
F_13 (member, &group->member_list, head.list) {
if ( V_24 -> V_5 . V_25 )
continue;
if ( ! F_14 ( V_23 , V_24 -> V_6 ) )
continue;
return V_24 -> V_6 ;
}
return NULL ;
}
bool F_15 ( const unsigned long V_26 ,
const unsigned long V_27 ,
const struct V_11 * V_12 )
{
struct V_7 * V_24 ;
bool V_28 = false ;
F_13 (member, &group->member_list, head.list) {
if ( V_24 -> V_5 . V_25 )
continue;
if ( V_26 > V_24 -> V_8 . V_29 [ 1 ] ||
V_27 < V_24 -> V_8 . V_29 [ 0 ] )
continue;
V_28 = true ;
break;
}
return V_28 ;
}
