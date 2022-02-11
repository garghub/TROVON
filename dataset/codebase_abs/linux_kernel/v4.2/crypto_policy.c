static int F_1 ( struct V_1 * V_1 )
{
int V_2 = F_2 ( V_1 , V_3 ,
V_4 , NULL , 0 , NULL ) ;
return ( V_2 > 0 ) ;
}
static int F_3 (
struct V_1 * V_1 , const struct V_5 * V_6 )
{
struct V_7 V_8 ;
int V_2 = F_2 ( V_1 , V_3 ,
V_4 , & V_8 ,
sizeof( V_8 ) , NULL ) ;
if ( V_2 != sizeof( V_8 ) )
return 0 ;
return ( memcmp ( V_8 . V_9 , V_6 -> V_9 ,
V_10 ) == 0 &&
( V_8 . V_11 == V_6 -> V_11 ) &&
( V_8 . V_12 ==
V_6 -> V_12 ) &&
( V_8 . V_13 ==
V_6 -> V_13 ) ) ;
}
static int F_4 (
struct V_1 * V_1 , const struct V_5 * V_6 )
{
struct V_7 V_8 ;
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
return F_10 ( V_1 , V_3 ,
V_4 , & V_8 ,
sizeof( V_8 ) , NULL , V_22 ) ;
}
int F_11 ( const struct V_5 * V_6 ,
struct V_1 * V_1 )
{
if ( V_6 -> V_23 != 0 )
return - V_18 ;
if ( ! F_12 ( V_1 -> V_24 ) )
return - V_18 ;
if ( ! F_1 ( V_1 ) ) {
if ( ! F_13 ( V_1 ) )
return - V_25 ;
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
int V_2 ;
if ( ! F_15 ( V_1 ) )
return - V_26 ;
V_2 = F_2 ( V_1 , V_3 ,
V_4 ,
& V_8 , sizeof( V_8 ) , NULL ) ;
if ( V_2 != sizeof( V_8 ) )
return - V_26 ;
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
int F_16 ( struct V_1 * V_27 ,
struct V_1 * V_28 )
{
struct V_29 * V_30 , * V_31 ;
int V_2 ;
if ( ( V_27 == NULL ) || ( V_28 == NULL ) ) {
F_17 ( L_4 , V_27 , V_28 ) ;
F_18 ( 1 ) ;
}
if ( ! F_15 ( V_27 ) )
return 1 ;
if ( ! F_15 ( V_28 ) )
return 0 ;
V_2 = F_19 ( V_27 ) ;
if ( V_2 )
return 0 ;
V_2 = F_19 ( V_28 ) ;
if ( V_2 )
return 0 ;
V_30 = F_20 ( V_27 ) -> V_32 ;
V_31 = F_20 ( V_28 ) -> V_32 ;
if ( ! V_30 && ! V_31 )
return 1 ;
if ( ! V_30 || ! V_31 )
return 0 ;
return ( memcmp ( V_30 -> V_33 ,
V_31 -> V_33 ,
V_10 ) == 0 &&
( V_30 -> V_34 == V_31 -> V_34 ) &&
( V_30 -> V_35 == V_31 -> V_35 ) &&
( V_30 -> V_36 == V_31 -> V_36 ) ) ;
}
int F_21 ( struct V_1 * V_27 , struct V_1 * V_28 ,
struct V_37 * V_38 )
{
struct V_7 V_8 ;
struct V_29 * V_39 ;
int V_2 ;
V_2 = F_19 ( V_27 ) ;
if ( V_2 < 0 )
return V_2 ;
V_39 = F_20 ( V_27 ) -> V_32 ;
F_18 ( V_39 == NULL ) ;
V_8 . V_14 = V_15 ;
V_8 . V_12 = V_39 -> V_34 ;
V_8 . V_13 = V_39 -> V_35 ;
V_8 . V_11 = V_39 -> V_36 ;
memcpy ( V_8 . V_9 , V_39 -> V_33 ,
V_10 ) ;
F_9 ( V_8 . V_20 , V_21 ) ;
return F_10 ( V_28 , V_3 ,
V_4 , & V_8 ,
sizeof( V_8 ) , V_38 , V_22 ) ;
}
