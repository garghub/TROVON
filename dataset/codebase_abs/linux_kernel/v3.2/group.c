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
static bool F_4 ( const struct V_1 * V_2 ,
const struct V_1 * V_3 )
{
const struct V_9 * V_10 = F_2 ( V_2 , F_5 ( * V_10 ) ,
V_5 ) ;
const struct V_9 * V_11 = F_2 ( V_3 , F_5 ( * V_11 ) ,
V_5 ) ;
return F_6 ( & V_10 -> V_12 , & V_11 -> V_12 ) ;
}
int F_7 ( struct V_13 * V_14 , const T_1 type )
{
struct V_15 * V_16 = F_8 ( V_14 , type ) ;
int error = - V_17 ;
if ( ! V_16 )
return - V_18 ;
V_14 -> V_19 = & V_16 -> V_20 ;
if ( type == V_21 ) {
struct V_4 V_22 = { } ;
V_22 . V_6 = F_9 ( F_10 ( V_14 ) ) ;
if ( ! V_22 . V_6 ) {
error = - V_18 ;
goto V_23;
}
error = F_11 ( & V_22 . V_5 , sizeof( V_22 ) , V_14 ,
F_1 ) ;
F_12 ( V_22 . V_6 ) ;
} else if ( type == V_24 ) {
struct V_7 V_22 = { } ;
if ( V_14 -> V_25 [ 0 ] == '@' ||
! F_13 ( V_14 , & V_22 . V_8 ) )
goto V_23;
error = F_11 ( & V_22 . V_5 , sizeof( V_22 ) , V_14 ,
F_3 ) ;
} else {
struct V_9 V_22 = { } ;
if ( V_14 -> V_25 [ 0 ] == '@' ||
! F_14 ( V_14 , & V_22 . V_12 ) )
goto V_23;
error = F_11 ( & V_22 . V_5 , sizeof( V_22 ) , V_14 ,
F_4 ) ;
}
V_23:
F_15 ( V_16 ) ;
return error ;
}
const struct V_26 *
F_16 ( const struct V_26 * V_27 ,
const struct V_15 * V_16 )
{
struct V_4 * V_28 ;
F_17 (member, &group->member_list, head.list) {
if ( V_28 -> V_5 . V_29 )
continue;
if ( ! F_18 ( V_27 , V_28 -> V_6 ) )
continue;
return V_28 -> V_6 ;
}
return NULL ;
}
bool F_19 ( const unsigned long V_30 ,
const unsigned long V_31 ,
const struct V_15 * V_16 )
{
struct V_7 * V_28 ;
bool V_32 = false ;
F_17 (member, &group->member_list, head.list) {
if ( V_28 -> V_5 . V_29 )
continue;
if ( V_30 > V_28 -> V_8 . V_33 [ 1 ] ||
V_31 < V_28 -> V_8 . V_33 [ 0 ] )
continue;
V_32 = true ;
break;
}
return V_32 ;
}
bool F_20 ( const bool V_34 , const T_2 * V_12 ,
const struct V_15 * V_16 )
{
struct V_9 * V_28 ;
bool V_32 = false ;
const T_1 V_35 = V_34 ? 16 : 4 ;
F_17 (member, &group->member_list, head.list) {
if ( V_28 -> V_5 . V_29 )
continue;
if ( V_28 -> V_12 . V_34 != V_34 )
continue;
if ( memcmp ( & V_28 -> V_12 . V_36 [ 0 ] , V_12 , V_35 ) > 0 ||
memcmp ( V_12 , & V_28 -> V_12 . V_36 [ 1 ] , V_35 ) > 0 )
continue;
V_32 = true ;
break;
}
return V_32 ;
}
