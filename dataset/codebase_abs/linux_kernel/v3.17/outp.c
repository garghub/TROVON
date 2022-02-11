int
F_1 ( struct V_1 * V_2 , bool V_3 )
{
struct V_4 * V_5 = ( void * ) V_2 ;
F_2 ( V_5 -> V_6 ) -> F_3 ( F_4 ( V_5 -> V_6 ) , V_3 ) ;
return F_5 ( & V_5 -> V_7 , V_3 ) ;
}
int
F_6 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = ( void * ) V_2 ;
int V_8 = F_7 ( & V_5 -> V_7 ) ;
if ( V_8 == 0 )
F_2 ( V_5 -> V_6 ) -> F_8 ( F_4 ( V_5 -> V_6 ) ) ;
return 0 ;
}
void
F_9 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = ( void * ) V_2 ;
F_10 ( & V_5 -> V_9 ) ;
F_11 ( NULL , ( void * ) & V_5 -> V_6 ) ;
F_12 ( & V_5 -> V_7 ) ;
}
int
F_13 ( struct V_1 * V_10 ,
struct V_1 * V_11 ,
struct V_12 * V_13 ,
struct V_14 * V_15 , int V_16 ,
int V_17 , void * * V_18 )
{
struct V_19 * V_20 = V_19 ( V_11 ) ;
struct V_21 * V_22 = V_21 ( V_10 ) ;
struct V_23 * V_24 = ( void * ) V_11 ;
struct V_25 V_26 ;
struct V_4 * V_5 ;
T_1 V_27 , V_28 ;
T_2 V_29 ;
int V_8 ;
V_8 = F_14 ( V_10 , V_11 , V_13 , 0 , V_17 , V_18 ) ;
V_5 = * V_18 ;
if ( V_8 )
return V_8 ;
V_5 -> V_30 = * V_15 ;
V_5 -> V_16 = V_16 ;
V_5 -> V_31 = F_15 ( V_5 -> V_30 . V_31 ) - 1 ;
F_16 ( L_1 ,
V_15 -> type , V_15 -> V_32 , V_15 -> V_31 , V_15 -> type >= 2 ?
V_15 -> V_33 . V_34 : 0 , V_15 -> V_35 , V_15 -> V_36 ,
V_15 -> V_37 , V_15 -> V_38 ) ;
V_5 -> V_39 = V_22 -> V_40 ( V_22 , V_5 -> V_30 . V_36 ) ;
V_5 -> V_41 = V_5 -> V_39 ;
V_29 = F_17 ( V_20 , V_5 -> V_30 . V_35 , & V_27 , & V_28 , & V_26 ) ;
if ( ! V_29 ) {
F_16 ( L_2 ) ;
memset ( & V_26 , 0x00 , sizeof( V_26 ) ) ;
V_26 . type = V_42 ;
}
V_8 = F_18 ( V_10 , V_11 , V_43 ,
& V_26 , V_5 -> V_30 . V_35 ,
(struct V_1 * * ) & V_5 -> V_6 ) ;
if ( V_8 < 0 ) {
F_19 ( L_3 , V_8 ) ;
return V_8 ;
}
F_20 ( & V_5 -> V_9 , & V_24 -> V_5 ) ;
return 0 ;
}
int
F_21 ( struct V_1 * V_10 ,
struct V_1 * V_11 ,
struct V_12 * V_13 , void * V_15 , T_2 V_16 ,
struct V_1 * * V_18 )
{
struct V_4 * V_5 ;
int V_8 ;
V_8 = F_22 ( V_10 , V_11 , V_13 , V_15 , V_16 , & V_5 ) ;
* V_18 = F_4 ( V_5 ) ;
if ( V_8 )
return V_8 ;
return 0 ;
}
