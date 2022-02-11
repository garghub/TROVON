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
T_1 * V_14 ;
int V_2 , V_15 ;
V_2 = F_5 ( V_1 ) ;
if ( V_2 )
return V_2 ;
V_8 . V_16 = V_17 ;
memcpy ( V_8 . V_9 , V_6 -> V_9 ,
V_10 ) ;
if ( ! F_6 ( V_6 -> V_12 ) ) {
F_7 ( V_18
L_1 , V_19 ,
V_6 -> V_12 ) ;
return - V_20 ;
}
if ( ! F_8 ( V_6 -> V_13 ) ) {
F_7 ( V_18
L_2 , V_19 ,
V_6 -> V_13 ) ;
return - V_20 ;
}
if ( V_6 -> V_11 & ~ V_21 )
return - V_20 ;
V_8 . V_12 = V_6 -> V_12 ;
V_8 . V_13 = V_6 -> V_13 ;
V_8 . V_11 = V_6 -> V_11 ;
F_9 ( sizeof( V_8 . V_22 ) != V_23 ) ;
F_10 ( V_8 . V_22 , V_23 ) ;
V_14 = F_11 ( V_1 , V_24 ,
F_12 ( V_1 ) ) ;
if ( F_13 ( V_14 ) )
return F_14 ( V_14 ) ;
V_2 = F_15 ( V_1 , V_3 ,
V_4 , & V_8 ,
sizeof( V_8 ) , 0 ) ;
if ( ! V_2 ) {
F_16 ( V_1 , V_25 ) ;
V_2 = F_17 ( V_14 , V_1 ) ;
if ( V_2 )
F_18 ( V_1 , L_3 ) ;
}
V_15 = F_19 ( V_14 ) ;
if ( ! V_2 )
V_2 = V_15 ;
return V_2 ;
}
int F_20 ( const struct V_5 * V_6 ,
struct V_1 * V_1 )
{
if ( V_6 -> V_26 != 0 )
return - V_20 ;
if ( ! F_1 ( V_1 ) ) {
if ( ! F_21 ( V_1 -> V_27 ) )
return - V_20 ;
if ( ! F_22 ( V_1 ) )
return - V_28 ;
return F_4 ( V_1 ,
V_6 ) ;
}
if ( F_3 ( V_1 , V_6 ) )
return 0 ;
F_7 ( V_18 L_4 ,
V_19 ) ;
return - V_20 ;
}
int F_23 ( struct V_1 * V_1 , struct V_5 * V_6 )
{
struct V_7 V_8 ;
int V_2 = F_2 ( V_1 , V_3 ,
V_4 ,
& V_8 , sizeof( V_8 ) ) ;
if ( V_2 != sizeof( V_8 ) )
return - V_29 ;
if ( V_8 . V_16 != V_17 )
return - V_20 ;
V_6 -> V_26 = 0 ;
V_6 -> V_12 = V_8 . V_12 ;
V_6 -> V_13 = V_8 . V_13 ;
V_6 -> V_11 = V_8 . V_11 ;
memcpy ( & V_6 -> V_9 , V_8 . V_9 ,
V_10 ) ;
return 0 ;
}
int F_24 ( struct V_1 * V_30 ,
struct V_1 * V_31 )
{
struct V_32 * V_33 , * V_34 ;
int V_2 ;
if ( ( V_30 == NULL ) || ( V_31 == NULL ) ) {
F_25 ( L_5 , V_30 , V_31 ) ;
F_26 ( 1 ) ;
return 0 ;
}
if ( ! F_27 ( V_30 ) )
return 1 ;
if ( ! F_27 ( V_31 ) )
return 0 ;
V_2 = F_28 ( V_30 ) ;
if ( V_2 )
return 0 ;
V_2 = F_28 ( V_31 ) ;
if ( V_2 )
return 0 ;
V_33 = F_29 ( V_30 ) -> V_35 ;
V_34 = F_29 ( V_31 ) -> V_35 ;
if ( ! V_33 && ! V_34 )
return 1 ;
if ( ! V_33 || ! V_34 )
return 0 ;
return ( memcmp ( V_33 -> V_36 ,
V_34 -> V_36 ,
V_10 ) == 0 &&
( V_33 -> V_37 == V_34 -> V_37 ) &&
( V_33 -> V_38 == V_34 -> V_38 ) &&
( V_33 -> V_39 == V_34 -> V_39 ) ) ;
}
int F_30 ( struct V_1 * V_30 , struct V_1 * V_31 )
{
struct V_7 V_8 ;
struct V_32 * V_40 ;
int V_2 ;
V_2 = F_28 ( V_30 ) ;
if ( V_2 < 0 )
return V_2 ;
V_40 = F_29 ( V_30 ) -> V_35 ;
if ( V_40 == NULL )
return - V_41 ;
V_8 . V_16 = V_17 ;
if ( F_31 ( F_32 ( V_30 -> V_42 ) ) ) {
V_8 . V_12 = V_43 ;
V_8 . V_13 =
V_44 ;
V_8 . V_11 = 0 ;
memset ( V_8 . V_9 , 0x42 ,
V_10 ) ;
V_2 = 0 ;
} else {
V_8 . V_12 = V_40 -> V_37 ;
V_8 . V_13 = V_40 -> V_38 ;
V_8 . V_11 = V_40 -> V_39 ;
memcpy ( V_8 . V_9 , V_40 -> V_36 ,
V_10 ) ;
}
F_10 ( V_8 . V_22 , V_23 ) ;
V_2 = F_15 ( V_31 , V_3 ,
V_4 , & V_8 ,
sizeof( V_8 ) , 0 ) ;
if ( ! V_2 ) {
F_16 ( V_31 , V_25 ) ;
F_33 ( V_31 , V_45 ) ;
V_2 = F_28 ( V_31 ) ;
}
return V_2 ;
}
