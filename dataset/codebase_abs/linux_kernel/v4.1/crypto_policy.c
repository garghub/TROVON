static int F_1 ( struct V_1 * V_1 )
{
int V_2 = F_2 ( V_1 , V_3 ,
V_4 , NULL , 0 ) ;
return ( V_2 > 0 ) ;
}
static int F_3 (
struct V_1 * V_1 , const struct V_5 * V_6 )
{
struct V_7 V_8 ;
int V_2 = F_2 ( V_1 , V_3 ,
V_4 , & V_8 ,
sizeof( V_8 ) ) ;
if ( V_2 != sizeof( V_8 ) )
return 0 ;
return ( memcmp ( V_8 . V_9 , V_6 -> V_9 ,
V_10 ) == 0 &&
( V_8 . V_11 ==
V_6 -> V_11 ) &&
( V_8 . V_12 ==
V_6 -> V_12 ) &&
( V_8 . V_13 ==
V_6 -> V_13 ) ) ;
}
static int F_4 (
struct V_1 * V_1 , const struct V_5 * V_6 )
{
struct V_7 V_8 ;
int V_2 = 0 ;
V_8 . V_14 = V_15 ;
memcpy ( V_8 . V_9 , V_6 -> V_9 ,
V_10 ) ;
if ( ! F_5 ( V_6 -> V_12 ) ) {
F_6 ( V_16
L_1 , V_17 ,
V_6 -> V_12 ) ;
return - V_18 ;
}
if ( ! F_7 ( V_6 -> V_13 ) ) {
F_6 ( V_16
L_2 , V_17 ,
V_6 -> V_13 ) ;
return - V_18 ;
}
if ( V_6 -> V_11 & ~ V_19 )
return - V_18 ;
V_8 . V_12 = V_6 -> V_12 ;
V_8 . V_13 = V_6 -> V_13 ;
V_8 . V_11 = V_6 -> V_11 ;
F_8 ( sizeof( V_8 . V_20 ) != V_21 ) ;
F_9 ( V_8 . V_20 , V_21 ) ;
V_2 = F_10 ( V_1 , V_3 ,
V_4 , & V_8 ,
sizeof( V_8 ) , 0 ) ;
if ( ! V_2 )
F_11 ( V_1 , V_22 ) ;
return V_2 ;
}
int F_12 ( const struct V_5 * V_6 ,
struct V_1 * V_1 )
{
if ( V_6 -> V_23 != 0 )
return - V_18 ;
if ( ! F_1 ( V_1 ) ) {
if ( ! F_13 ( V_1 ) )
return - V_24 ;
return F_4 ( V_1 ,
V_6 ) ;
}
if ( F_3 ( V_1 , V_6 ) )
return 0 ;
F_6 ( V_16 L_3 ,
V_17 ) ;
return - V_18 ;
}
int F_14 ( struct V_1 * V_1 , struct V_5 * V_6 )
{
struct V_7 V_8 ;
int V_2 = F_2 ( V_1 , V_3 ,
V_4 ,
& V_8 , sizeof( V_8 ) ) ;
if ( V_2 != sizeof( V_8 ) )
return - V_25 ;
if ( V_8 . V_14 != V_15 )
return - V_18 ;
V_6 -> V_23 = 0 ;
V_6 -> V_12 = V_8 . V_12 ;
V_6 -> V_13 = V_8 . V_13 ;
V_6 -> V_11 = V_8 . V_11 ;
memcpy ( & V_6 -> V_9 , V_8 . V_9 ,
V_10 ) ;
return 0 ;
}
int F_15 ( struct V_1 * V_26 ,
struct V_1 * V_27 )
{
struct V_7 V_28 , V_29 ;
int V_2 ;
if ( ( V_26 == NULL ) || ( V_27 == NULL ) ) {
F_16 ( L_4 , V_26 , V_27 ) ;
F_17 ( 1 ) ;
}
if ( ! F_18 ( V_26 ) )
return 1 ;
V_2 = F_2 ( V_26 , V_3 ,
V_4 ,
& V_28 , sizeof( V_28 ) ) ;
if ( V_2 != sizeof( V_28 ) )
return 0 ;
if ( ! F_18 ( V_27 ) )
return 0 ;
V_2 = F_2 ( V_27 , V_3 ,
V_4 ,
& V_29 , sizeof( V_29 ) ) ;
if ( V_2 != sizeof( V_29 ) )
return 0 ;
return ( memcmp ( V_28 . V_9 ,
V_29 . V_9 ,
V_10 ) == 0 &&
( V_28 . V_12 ==
V_29 . V_12 ) &&
( V_28 . V_13 ==
V_29 . V_13 ) ) ;
}
int F_19 ( struct V_1 * V_26 , struct V_1 * V_27 )
{
struct V_7 V_8 ;
int V_2 = F_2 ( V_26 , V_3 ,
V_4 ,
& V_8 , sizeof( V_8 ) ) ;
if ( V_2 != sizeof( V_8 ) ) {
if ( F_20 ( F_21 ( V_26 -> V_30 ) ) ) {
V_8 . V_14 = V_15 ;
V_8 . V_12 =
V_31 ;
V_8 . V_13 =
V_32 ;
V_8 . V_11 = 0 ;
memset ( V_8 . V_9 , 0x42 ,
V_10 ) ;
V_2 = 0 ;
} else {
goto V_33;
}
}
F_9 ( V_8 . V_20 , V_21 ) ;
V_2 = F_10 ( V_27 , V_3 ,
V_4 , & V_8 ,
sizeof( V_8 ) , 0 ) ;
V_33:
if ( ! V_2 )
F_11 ( V_27 , V_22 ) ;
return V_2 ;
}
