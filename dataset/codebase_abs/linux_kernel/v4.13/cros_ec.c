static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
bool V_5 = true ;
int V_6 ;
V_6 = F_2 ( V_4 , & V_5 ) ;
if ( V_5 && F_3 ( V_4 -> V_7 ) )
F_4 ( V_4 -> V_7 , 0 ) ;
if ( V_6 > 0 )
F_5 ( & V_4 -> V_8 ,
0 , V_4 ) ;
return V_9 ;
}
static int F_6 ( struct V_3 * V_4 , T_2 V_10 )
{
struct {
struct V_11 V_12 ;
struct V_13 V_14 ;
} V_15 V_16 ;
memset ( & V_16 , 0 , sizeof( V_16 ) ) ;
V_16 . V_14 . V_10 = V_10 ;
V_16 . V_12 . V_17 = V_18 ;
V_16 . V_12 . V_19 = 0 ;
V_16 . V_12 . V_20 = sizeof( V_16 . V_14 ) ;
return F_7 ( V_4 , & V_16 . V_12 ) ;
}
int F_8 ( struct V_3 * V_4 )
{
struct V_21 * V_7 = V_4 -> V_7 ;
int V_22 = 0 ;
F_9 ( & V_4 -> V_8 ) ;
V_4 -> V_23 = sizeof( struct V_24 ) ;
V_4 -> V_25 = sizeof( struct V_26 ) ;
V_4 -> V_27 = 0 ;
V_4 -> V_28 = F_10 ( V_7 , V_4 -> V_29 , V_30 ) ;
if ( ! V_4 -> V_28 )
return - V_31 ;
V_4 -> V_32 = F_10 ( V_7 , V_4 -> V_33 , V_30 ) ;
if ( ! V_4 -> V_32 )
return - V_31 ;
F_11 ( & V_4 -> V_34 ) ;
F_12 ( V_4 ) ;
if ( V_4 -> V_1 ) {
V_22 = F_13 ( V_4 -> V_1 , NULL , F_1 ,
V_35 | V_36 ,
L_1 , V_4 ) ;
if ( V_22 ) {
F_14 ( V_7 , L_2 ,
V_4 -> V_1 , V_22 ) ;
return V_22 ;
}
}
V_22 = F_15 ( V_4 -> V_7 , V_37 , & V_38 , 1 ,
NULL , V_4 -> V_1 , NULL ) ;
if ( V_22 ) {
F_14 ( V_7 ,
L_3 ,
V_22 ) ;
goto V_39;
}
if ( V_4 -> V_27 ) {
V_22 = F_15 ( V_4 -> V_7 , V_37 ,
& V_40 , 1 , NULL , V_4 -> V_1 , NULL ) ;
if ( V_22 ) {
F_14 ( V_7 ,
L_4 ,
V_22 ) ;
goto V_39;
}
}
if ( F_16 ( V_41 ) && V_7 -> V_42 ) {
V_22 = F_17 ( V_7 ) ;
if ( V_22 ) {
F_18 ( V_7 ) ;
F_14 ( V_7 , L_5 ) ;
goto V_39;
}
}
V_22 = F_6 ( V_4 , 0 ) ;
if ( V_22 < 0 )
F_19 ( V_4 -> V_7 , L_6 ,
V_22 ) ;
F_20 ( V_7 , L_7 ) ;
F_21 ( V_7 ) ;
return 0 ;
V_39:
if ( V_4 -> V_1 )
F_22 ( V_4 -> V_1 , V_4 ) ;
return V_22 ;
}
int F_23 ( struct V_3 * V_4 )
{
F_18 ( V_4 -> V_7 ) ;
F_24 () ;
if ( V_4 -> V_1 )
F_22 ( V_4 -> V_1 , V_4 ) ;
return 0 ;
}
int F_25 ( struct V_3 * V_4 )
{
struct V_21 * V_7 = V_4 -> V_7 ;
int V_6 ;
T_2 V_10 ;
if ( ! F_16 ( V_43 ) || F_26 () ) {
V_10 = V_44 ;
} else {
V_10 = V_45 ;
F_27 () ;
}
V_6 = F_6 ( V_4 , V_10 ) ;
if ( V_6 < 0 )
F_19 ( V_4 -> V_7 , L_8 ,
V_6 ) ;
if ( F_3 ( V_7 ) )
V_4 -> V_46 = ! F_28 ( V_4 -> V_1 ) ;
F_29 ( V_4 -> V_1 ) ;
V_4 -> V_47 = V_4 -> V_46 ;
V_4 -> V_48 = true ;
return 0 ;
}
static void F_30 ( struct V_3 * V_4 )
{
while ( F_2 ( V_4 , NULL ) > 0 )
F_5 ( & V_4 -> V_8 ,
1 , V_4 ) ;
}
int F_31 ( struct V_3 * V_4 )
{
int V_6 ;
T_2 V_10 ;
V_4 -> V_48 = false ;
F_32 ( V_4 -> V_1 ) ;
V_10 = ( ! F_16 ( V_43 ) || F_26 () ) ?
V_49 :
V_50 ;
V_6 = F_6 ( V_4 , V_10 ) ;
if ( V_6 < 0 )
F_19 ( V_4 -> V_7 , L_9 ,
V_6 ) ;
if ( V_4 -> V_46 ) {
F_33 ( V_4 -> V_1 ) ;
V_4 -> V_46 = 0 ;
} else {
F_30 ( V_4 ) ;
}
return 0 ;
}
