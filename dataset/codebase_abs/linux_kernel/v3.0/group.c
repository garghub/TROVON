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
int F_4 ( char * V_9 , const bool V_10 , const T_1 type )
{
struct V_11 * V_12 ;
struct V_13 * V_14 ;
char * V_15 [ 2 ] ;
int error = - V_16 ;
if ( ! F_5 ( V_9 , V_15 , sizeof( V_15 ) ) || ! V_15 [ 1 ] [ 0 ] )
return - V_16 ;
V_12 = F_6 ( V_15 [ 0 ] , type ) ;
if ( ! V_12 )
return - V_17 ;
V_14 = & V_12 -> V_18 ;
if ( type == V_19 ) {
struct V_4 V_20 = { } ;
V_20 . V_6 = F_7 ( V_15 [ 1 ] ) ;
if ( ! V_20 . V_6 ) {
error = - V_17 ;
goto V_21;
}
error = F_8 ( & V_20 . V_5 , sizeof( V_20 ) , V_10 ,
V_14 , F_1 ) ;
F_9 ( V_20 . V_6 ) ;
} else if ( type == V_22 ) {
struct V_7 V_20 = { } ;
if ( V_15 [ 1 ] [ 0 ] == '@'
|| ! F_10 ( V_15 [ 1 ] , & V_20 . V_8 )
|| V_20 . V_8 . V_23 [ 0 ] > V_20 . V_8 . V_23 [ 1 ] )
goto V_21;
error = F_8 ( & V_20 . V_5 , sizeof( V_20 ) , V_10 ,
V_14 , F_3 ) ;
}
V_21:
F_11 ( V_12 ) ;
return error ;
}
const struct V_24 *
F_12 ( const struct V_24 * V_25 ,
const struct V_11 * V_12 )
{
struct V_4 * V_14 ;
F_13 (member, &group->member_list, head.list) {
if ( V_14 -> V_5 . V_26 )
continue;
if ( ! F_14 ( V_25 , V_14 -> V_6 ) )
continue;
return V_14 -> V_6 ;
}
return NULL ;
}
bool F_15 ( const unsigned long V_27 ,
const unsigned long V_28 ,
const struct V_11 * V_12 )
{
struct V_7 * V_14 ;
bool V_29 = false ;
F_13 (member, &group->member_list, head.list) {
if ( V_14 -> V_5 . V_26 )
continue;
if ( V_27 > V_14 -> V_8 . V_23 [ 1 ] ||
V_28 < V_14 -> V_8 . V_23 [ 0 ] )
continue;
V_29 = true ;
break;
}
return V_29 ;
}
