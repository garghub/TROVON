static long F_1 ( struct V_1 * V_1 ,
struct V_2 T_1 * V_3 ,
int T_1 * V_4 )
{
long V_5 ;
struct V_2 V_6 ;
int V_7 , V_8 ;
struct V_2 * V_9 = NULL ;
if ( ! V_1 -> V_10 -> V_11 -> V_12 ||
! V_1 -> V_10 -> V_11 -> V_12 -> V_13 )
return - V_14 ;
if ( F_2 ( & V_6 , V_3 , sizeof( struct V_2 ) ) )
return - V_15 ;
if ( V_6 . V_8 > V_16 )
return - V_17 ;
V_9 = F_3 ( sizeof( struct V_2 ) + V_6 . V_8 ,
V_18 ) ;
if ( ! V_9 )
return - V_19 ;
V_7 = V_6 . V_8 >> 2 ;
V_5 = F_4 ( V_1 -> V_10 ,
(struct V_20 * ) V_9 -> V_6 ,
& V_7 , 0 ) ;
V_9 -> V_21 = V_5 ;
V_8 = V_7 * sizeof( V_22 ) ;
V_9 -> V_8 = V_8 ;
if ( ( V_9 -> V_8 > V_6 . V_8 ) ||
( V_5 == 255 ) || ( V_5 == - V_23 ) ) {
V_8 = 0 ;
V_5 = - V_24 ;
} else
V_5 = 0 ;
if ( F_5 ( V_4 , & F_6 ( V_1 -> V_25 ) -> V_4 ,
sizeof( * V_4 ) ) ||
F_5 ( V_3 , V_9 ,
sizeof( struct V_2 ) + V_8 ) )
V_5 = - V_15 ;
F_7 ( V_9 ) ;
return V_5 ;
}
static struct V_26 * F_8 ( int V_27 )
{
struct V_1 V_1 ;
if ( V_27 == V_28 ) {
struct V_29 * V_30 = V_31 -> V_30 ;
F_9 ( & V_30 -> V_32 ) ;
V_1 = V_30 -> V_33 ;
F_10 ( V_1 . V_25 ) ;
F_11 ( & V_30 -> V_32 ) ;
} else {
int V_34 ;
struct V_35 * V_35 = F_12 ( V_27 , & V_34 ) ;
if ( ! V_35 )
return F_13 ( - V_36 ) ;
V_1 = V_35 -> V_37 ;
F_10 ( V_1 . V_25 ) ;
F_14 ( V_35 , V_34 ) ;
}
return V_1 . V_25 ;
}
static int F_15 ( void * V_38 , struct V_10 * V_10 )
{
return 1 ;
}
static int F_16 ( int V_39 , struct V_2 * V_9 ,
struct V_1 * V_1 )
{
int V_5 = 0 ;
int V_7 ;
V_1 -> V_25 = F_8 ( V_39 ) ;
if ( F_17 ( V_1 -> V_25 ) ) {
V_5 = F_18 ( V_1 -> V_25 ) ;
goto V_40;
}
V_7 = V_9 -> V_8 >> 2 ;
V_1 -> V_10 = F_19 ( V_1 -> V_25 ,
(struct V_20 * ) V_9 -> V_6 ,
V_7 , V_9 -> V_21 ,
F_15 , NULL ) ;
if ( F_17 ( V_1 -> V_10 ) ) {
V_5 = F_18 ( V_1 -> V_10 ) ;
goto V_41;
}
return 0 ;
V_41:
F_20 ( V_1 -> V_25 ) ;
V_40:
return V_5 ;
}
static int F_21 ( int V_39 , struct V_2 T_1 * V_3 ,
struct V_1 * V_1 )
{
int V_5 = 0 ;
struct V_2 V_6 ;
struct V_2 * V_9 = NULL ;
if ( ! F_22 ( V_42 ) ) {
V_5 = - V_43 ;
goto V_40;
}
if ( F_2 ( & V_6 , V_3 , sizeof( struct V_2 ) ) ) {
V_5 = - V_15 ;
goto V_40;
}
if ( ( V_6 . V_8 > V_16 ) ||
( V_6 . V_8 == 0 ) ) {
V_5 = - V_17 ;
goto V_40;
}
V_9 = F_3 ( sizeof( struct V_2 ) + V_6 . V_8 ,
V_18 ) ;
if ( ! V_9 ) {
V_5 = - V_19 ;
goto V_40;
}
if ( F_2 ( V_9 , V_3 ,
sizeof( struct V_2 ) +
V_6 . V_8 ) ) {
V_5 = - V_15 ;
goto V_44;
}
V_5 = F_16 ( V_39 , V_9 , V_1 ) ;
V_44:
F_7 ( V_9 ) ;
V_40:
return V_5 ;
}
long F_23 ( int V_39 ,
struct V_2 T_1 * V_3 , int V_45 )
{
long V_5 = 0 ;
struct V_1 V_1 ;
struct V_35 * V_35 ;
int V_27 ;
V_5 = F_21 ( V_39 , V_3 , & V_1 ) ;
if ( V_5 )
return V_5 ;
V_27 = F_24 ( V_45 ) ;
if ( V_27 < 0 ) {
F_25 ( & V_1 ) ;
return V_27 ;
}
V_35 = F_26 ( V_1 . V_10 , V_1 . V_25 , L_1 , V_45 ) ;
if ( F_17 ( V_35 ) ) {
F_27 ( V_27 ) ;
V_5 = F_18 ( V_35 ) ;
} else {
V_5 = V_27 ;
F_28 ( V_35 ) ;
F_29 ( V_27 , V_35 ) ;
}
F_25 ( & V_1 ) ;
return V_5 ;
}
