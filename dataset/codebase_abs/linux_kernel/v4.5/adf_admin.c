static int F_1 ( struct V_1 * V_2 , T_1 V_3 ,
void * V_4 , void * V_5 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
int V_8 = V_3 * V_9 * 2 ;
void T_2 * V_10 = V_7 -> V_11 ;
int V_12 = V_3 * V_13 ;
int V_14 , V_15 ;
F_2 ( & V_7 -> V_16 ) ;
if ( F_3 ( V_10 , V_12 ) == 1 ) {
F_4 ( & V_7 -> V_16 ) ;
return - V_17 ;
}
memcpy ( V_7 -> V_18 + V_8 , V_4 , V_9 ) ;
F_5 ( V_10 , V_12 , 1 ) ;
V_15 = 0 ;
for ( V_14 = 0 ; V_14 < 50 ; V_14 ++ ) {
F_6 ( 20 ) ;
if ( F_3 ( V_10 , V_12 ) == 0 ) {
V_15 = 1 ;
break;
}
}
if ( V_15 )
memcpy ( V_5 , V_7 -> V_18 + V_8 +
V_9 , V_9 ) ;
else
F_7 ( & F_8 ( V_2 ) ,
L_1 ) ;
F_4 ( & V_7 -> V_16 ) ;
return V_15 ? 0 : - V_19 ;
}
static int F_9 ( struct V_1 * V_2 , int V_20 )
{
struct V_21 * V_22 = V_2 -> V_22 ;
struct V_23 V_24 ;
struct V_25 V_26 ;
int V_27 ;
memset ( & V_24 , 0 , sizeof( struct V_23 ) ) ;
V_24 . V_28 = V_20 ;
if ( V_20 == V_29 ) {
V_24 . V_30 = 1024 ;
V_24 . V_31 = V_2 -> V_7 -> V_32 ;
}
for ( V_27 = 0 ; V_27 < V_22 -> V_33 ( V_22 ) ; V_27 ++ ) {
memset ( & V_26 , 0 , sizeof( struct V_25 ) ) ;
if ( F_1 ( V_2 , V_27 , & V_24 , & V_26 ) ||
V_26 . V_34 . V_35 )
return - V_19 ;
}
return 0 ;
}
int F_10 ( struct V_1 * V_2 )
{
int V_36 = F_9 ( V_2 , V_37 ) ;
if ( V_36 )
return V_36 ;
return F_9 ( V_2 , V_29 ) ;
}
int F_11 ( struct V_1 * V_2 )
{
struct V_6 * V_7 ;
struct V_21 * V_38 = V_2 -> V_22 ;
struct V_39 * V_40 =
& F_12 ( V_2 ) [ V_38 -> V_41 ( V_38 ) ] ;
void T_2 * V_42 = V_40 -> V_18 ;
void T_2 * V_10 = ( void T_2 * ) ( ( V_43 ) V_42 +
V_44 ) ;
T_3 V_45 ;
V_7 = F_13 ( sizeof( * V_2 -> V_7 ) , V_46 ,
F_14 ( & F_8 ( V_2 ) ) ) ;
if ( ! V_7 )
return - V_47 ;
V_7 -> V_18 = F_15 ( & F_8 ( V_2 ) , V_48 ,
& V_7 -> V_49 , V_46 ) ;
if ( ! V_7 -> V_18 ) {
F_7 ( & F_8 ( V_2 ) , L_2 ) ;
F_16 ( V_7 ) ;
return - V_47 ;
}
V_7 -> V_32 = F_17 ( & F_8 ( V_2 ) ,
( void * ) V_50 , 1024 ,
V_51 ) ;
if ( F_18 ( F_19 ( & F_8 ( V_2 ) ,
V_7 -> V_32 ) ) ) {
F_20 ( & F_8 ( V_2 ) , V_48 ,
V_7 -> V_18 , V_7 -> V_49 ) ;
F_16 ( V_7 ) ;
return - V_47 ;
}
V_45 = ( T_3 ) V_7 -> V_49 ;
F_5 ( V_42 , V_52 , V_45 >> 32 ) ;
F_5 ( V_42 , V_53 , V_45 ) ;
F_21 ( & V_7 -> V_16 ) ;
V_7 -> V_11 = V_10 ;
V_2 -> V_7 = V_7 ;
return 0 ;
}
void F_22 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
if ( ! V_7 )
return;
if ( V_7 -> V_18 )
F_20 ( & F_8 ( V_2 ) , V_48 ,
V_7 -> V_18 , V_7 -> V_49 ) ;
F_23 ( & F_8 ( V_2 ) , V_7 -> V_32 , 1024 ,
V_51 ) ;
F_24 ( & V_7 -> V_16 ) ;
F_16 ( V_7 ) ;
V_2 -> V_7 = NULL ;
}
