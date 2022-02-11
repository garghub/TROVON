static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
int V_5 ;
if ( F_2 ( V_4 -> V_6 ) )
F_3 ( V_4 -> V_6 , 0 ) ;
V_5 = F_4 ( V_4 ) ;
if ( V_5 > 0 )
F_5 ( & V_4 -> V_7 ,
0 , V_4 ) ;
return V_8 ;
}
static int F_6 ( struct V_3 * V_4 , T_2 V_9 )
{
struct {
struct V_10 V_11 ;
struct V_12 V_13 ;
} V_14 V_15 ;
memset ( & V_15 , 0 , sizeof( V_15 ) ) ;
V_15 . V_13 . V_9 = V_9 ;
V_15 . V_11 . V_16 = V_17 ;
V_15 . V_11 . V_18 = 0 ;
V_15 . V_11 . V_19 = sizeof( V_15 . V_13 ) ;
return F_7 ( V_4 , & V_15 . V_11 ) ;
}
int F_8 ( struct V_3 * V_4 )
{
struct V_20 * V_6 = V_4 -> V_6 ;
int V_21 = 0 ;
F_9 ( & V_4 -> V_7 ) ;
V_4 -> V_22 = sizeof( struct V_23 ) ;
V_4 -> V_24 = sizeof( struct V_25 ) ;
V_4 -> V_26 = 0 ;
V_4 -> V_27 = F_10 ( V_6 , V_4 -> V_28 , V_29 ) ;
if ( ! V_4 -> V_27 )
return - V_30 ;
V_4 -> V_31 = F_10 ( V_6 , V_4 -> V_32 , V_29 ) ;
if ( ! V_4 -> V_31 )
return - V_30 ;
F_11 ( & V_4 -> V_33 ) ;
F_12 ( V_4 ) ;
if ( V_4 -> V_1 ) {
V_21 = F_13 ( V_4 -> V_1 , NULL , F_1 ,
V_34 | V_35 ,
L_1 , V_4 ) ;
if ( V_21 ) {
F_14 ( V_6 , L_2 ,
V_4 -> V_1 , V_21 ) ;
return V_21 ;
}
}
V_21 = F_15 ( V_4 -> V_6 , V_36 , & V_37 , 1 ,
NULL , V_4 -> V_1 , NULL ) ;
if ( V_21 ) {
F_14 ( V_6 ,
L_3 ,
V_21 ) ;
goto V_38;
}
if ( V_4 -> V_26 ) {
V_21 = F_15 ( V_4 -> V_6 , V_36 ,
& V_39 , 1 , NULL , V_4 -> V_1 , NULL ) ;
if ( V_21 ) {
F_14 ( V_6 ,
L_4 ,
V_21 ) ;
goto V_38;
}
}
if ( F_16 ( V_40 ) && V_6 -> V_41 ) {
V_21 = F_17 ( V_6 -> V_41 , NULL , NULL , V_6 ) ;
if ( V_21 ) {
F_18 ( V_6 ) ;
F_14 ( V_6 , L_5 ) ;
goto V_38;
}
}
V_21 = F_6 ( V_4 , 0 ) ;
if ( V_21 < 0 )
F_19 ( V_4 -> V_6 , L_6 ,
V_21 ) ;
F_20 ( V_6 , L_7 ) ;
return 0 ;
V_38:
if ( V_4 -> V_1 )
F_21 ( V_4 -> V_1 , V_4 ) ;
return V_21 ;
}
int F_22 ( struct V_3 * V_4 )
{
F_18 ( V_4 -> V_6 ) ;
return 0 ;
}
int F_23 ( struct V_3 * V_4 )
{
struct V_20 * V_6 = V_4 -> V_6 ;
int V_5 ;
T_2 V_9 ;
V_9 = ( ! F_16 ( V_42 ) || F_24 () ) ?
V_43 :
V_44 ;
V_5 = F_6 ( V_4 , V_9 ) ;
if ( V_5 < 0 )
F_19 ( V_4 -> V_6 , L_8 ,
V_5 ) ;
if ( F_2 ( V_6 ) )
V_4 -> V_45 = ! F_25 ( V_4 -> V_1 ) ;
F_26 ( V_4 -> V_1 ) ;
V_4 -> V_46 = V_4 -> V_45 ;
V_4 -> V_47 = true ;
return 0 ;
}
static void F_27 ( struct V_3 * V_4 )
{
while ( F_4 ( V_4 ) > 0 )
F_5 ( & V_4 -> V_7 ,
1 , V_4 ) ;
}
int F_28 ( struct V_3 * V_4 )
{
int V_5 ;
T_2 V_9 ;
V_4 -> V_47 = false ;
F_29 ( V_4 -> V_1 ) ;
V_9 = ( ! F_16 ( V_42 ) || F_24 () ) ?
V_43 :
V_44 ;
V_5 = F_6 ( V_4 , V_9 ) ;
if ( V_5 < 0 )
F_19 ( V_4 -> V_6 , L_9 ,
V_5 ) ;
if ( V_4 -> V_45 ) {
F_30 ( V_4 -> V_1 ) ;
V_4 -> V_45 = 0 ;
} else {
F_27 ( V_4 ) ;
}
return 0 ;
}
