int F_1 ( const char T_1 * V_1 ,
struct V_2 * V_3 )
{
if ( V_4 && ! V_5 ) {
struct V_6 V_7 ;
if ( F_2 ( & V_7 , V_1 ,
sizeof( struct V_6 ) ) )
return - V_8 ;
V_3 -> time . V_9 = V_7 . time . V_9 ;
V_3 -> time . V_10 = V_7 . time . V_10 ;
V_3 -> type = V_7 . type ;
V_3 -> V_11 = V_7 . V_11 ;
V_3 -> V_12 = V_7 . V_12 ;
} else {
if ( F_2 ( V_3 , V_1 , sizeof( struct V_2 ) ) )
return - V_8 ;
}
return 0 ;
}
int F_3 ( char T_1 * V_1 ,
const struct V_2 * V_3 )
{
if ( V_4 && ! V_5 ) {
struct V_6 V_7 ;
V_7 . time . V_9 = V_3 -> time . V_9 ;
V_7 . time . V_10 = V_3 -> time . V_10 ;
V_7 . type = V_3 -> type ;
V_7 . V_11 = V_3 -> V_11 ;
V_7 . V_12 = V_3 -> V_12 ;
if ( F_4 ( V_1 , & V_7 ,
sizeof( struct V_6 ) ) )
return - V_8 ;
} else {
if ( F_4 ( V_1 , V_3 , sizeof( struct V_2 ) ) )
return - V_8 ;
}
return 0 ;
}
int F_5 ( const char T_1 * V_1 , T_2 V_13 ,
struct V_14 * V_15 )
{
if ( V_4 ) {
struct V_16 * V_17 ;
if ( V_13 != sizeof( struct V_16 ) )
return - V_18 ;
V_17 = (struct V_16 * ) V_15 ;
if ( F_2 ( V_17 , V_1 ,
sizeof( struct V_16 ) ) )
return - V_8 ;
if ( V_17 -> type == V_19 &&
V_17 -> V_20 . V_21 . V_22 == V_23 )
V_15 -> V_20 . V_21 . V_24 =
F_6 ( V_17 -> V_20 . V_21 . V_24 ) ;
} else {
if ( V_13 != sizeof( struct V_14 ) )
return - V_18 ;
if ( F_2 ( V_15 , V_1 , sizeof( struct V_14 ) ) )
return - V_8 ;
}
return 0 ;
}
int F_1 ( const char T_1 * V_1 ,
struct V_2 * V_3 )
{
if ( F_2 ( V_3 , V_1 , sizeof( struct V_2 ) ) )
return - V_8 ;
return 0 ;
}
int F_3 ( char T_1 * V_1 ,
const struct V_2 * V_3 )
{
if ( F_4 ( V_1 , V_3 , sizeof( struct V_2 ) ) )
return - V_8 ;
return 0 ;
}
int F_5 ( const char T_1 * V_1 , T_2 V_13 ,
struct V_14 * V_15 )
{
if ( V_13 != sizeof( struct V_14 ) )
return - V_18 ;
if ( F_2 ( V_15 , V_1 , sizeof( struct V_14 ) ) )
return - V_8 ;
return 0 ;
}
