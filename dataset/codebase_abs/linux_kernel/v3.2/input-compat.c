int F_1 ( const char T_1 * V_1 ,
struct V_2 * V_3 )
{
if ( V_4 ) {
struct V_5 V_6 ;
if ( F_2 ( & V_6 , V_1 ,
sizeof( struct V_5 ) ) )
return - V_7 ;
V_3 -> time . V_8 = V_6 . time . V_8 ;
V_3 -> time . V_9 = V_6 . time . V_9 ;
V_3 -> type = V_6 . type ;
V_3 -> V_10 = V_6 . V_10 ;
V_3 -> V_11 = V_6 . V_11 ;
} else {
if ( F_2 ( V_3 , V_1 , sizeof( struct V_2 ) ) )
return - V_7 ;
}
return 0 ;
}
int F_3 ( char T_1 * V_1 ,
const struct V_2 * V_3 )
{
if ( V_4 ) {
struct V_5 V_6 ;
V_6 . time . V_8 = V_3 -> time . V_8 ;
V_6 . time . V_9 = V_3 -> time . V_9 ;
V_6 . type = V_3 -> type ;
V_6 . V_10 = V_3 -> V_10 ;
V_6 . V_11 = V_3 -> V_11 ;
if ( F_4 ( V_1 , & V_6 ,
sizeof( struct V_5 ) ) )
return - V_7 ;
} else {
if ( F_4 ( V_1 , V_3 , sizeof( struct V_2 ) ) )
return - V_7 ;
}
return 0 ;
}
int F_5 ( const char T_1 * V_1 , T_2 V_12 ,
struct V_13 * V_14 )
{
if ( V_4 ) {
struct V_15 * V_16 ;
if ( V_12 != sizeof( struct V_15 ) )
return - V_17 ;
V_16 = (struct V_15 * ) V_14 ;
if ( F_2 ( V_16 , V_1 ,
sizeof( struct V_15 ) ) )
return - V_7 ;
if ( V_16 -> type == V_18 &&
V_16 -> V_19 . V_20 . V_21 == V_22 )
V_14 -> V_19 . V_20 . V_23 =
F_6 ( V_16 -> V_19 . V_20 . V_23 ) ;
} else {
if ( V_12 != sizeof( struct V_13 ) )
return - V_17 ;
if ( F_2 ( V_14 , V_1 , sizeof( struct V_13 ) ) )
return - V_7 ;
}
return 0 ;
}
int F_1 ( const char T_1 * V_1 ,
struct V_2 * V_3 )
{
if ( F_2 ( V_3 , V_1 , sizeof( struct V_2 ) ) )
return - V_7 ;
return 0 ;
}
int F_3 ( char T_1 * V_1 ,
const struct V_2 * V_3 )
{
if ( F_4 ( V_1 , V_3 , sizeof( struct V_2 ) ) )
return - V_7 ;
return 0 ;
}
int F_5 ( const char T_1 * V_1 , T_2 V_12 ,
struct V_13 * V_14 )
{
if ( V_12 != sizeof( struct V_13 ) )
return - V_17 ;
if ( F_2 ( V_14 , V_1 , sizeof( struct V_13 ) ) )
return - V_7 ;
return 0 ;
}
