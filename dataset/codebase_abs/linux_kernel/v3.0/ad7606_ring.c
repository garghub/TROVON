int F_1 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_6 ;
T_1 * V_7 ;
V_7 = F_2 ( V_5 -> V_8 -> V_9 ( V_5 ) ,
V_10 ) ;
if ( V_7 == NULL ) {
V_6 = - V_11 ;
goto V_12;
}
V_6 = V_5 -> V_8 -> V_13 ( V_5 , ( V_14 * ) V_7 ) ;
if ( V_6 )
goto V_15;
V_6 = V_7 [ V_3 ] ;
V_15:
F_3 ( V_7 ) ;
V_12:
return V_6 ;
}
static int F_4 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = F_5 ( V_2 ) ;
struct V_4 * V_5 = V_2 -> V_5 ;
T_2 V_18 ;
V_18 = V_17 -> V_19 -> V_20 *
V_17 -> V_19 -> V_21 [ 0 ] . V_22 . V_23 / 8 ;
if ( V_5 -> V_24 ) {
V_18 += sizeof( V_25 ) ;
if ( V_18 % sizeof( V_25 ) )
V_18 += sizeof( V_25 ) - ( V_18 % sizeof( V_25 ) ) ;
}
if ( V_5 -> V_8 -> V_26 )
V_5 -> V_8 -> V_26 ( V_5 , V_18 ) ;
V_17 -> V_18 = V_18 ;
return 0 ;
}
static T_3 F_6 ( int V_27 , void * V_28 )
{
struct V_29 * V_30 = V_28 ;
struct V_1 * V_2 = V_30 -> V_31 ;
struct V_16 * V_17 = F_5 ( V_2 ) ;
F_7 ( V_17 -> V_32 -> V_33 , 1 ) ;
return V_34 ;
}
static void F_8 ( struct V_35 * V_36 )
{
struct V_16 * V_17 = F_9 ( V_36 , struct V_16 ,
V_37 ) ;
struct V_1 * V_2 = F_10 ( V_17 ) ;
struct V_4 * V_5 = V_2 -> V_5 ;
V_25 V_38 ;
T_4 * V_39 ;
int V_6 ;
V_39 = F_11 ( V_17 -> V_18 , V_10 ) ;
if ( V_39 == NULL )
return;
if ( V_17 -> V_40 ) {
V_6 = V_17 -> V_41 -> V_42 ( V_17 -> V_43 , 1 , V_39 ) ;
if ( V_6 )
goto V_44;
if ( ! F_12 ( V_17 -> V_32 -> V_45 ) ) {
F_13 ( V_17 ) ;
goto V_44;
}
V_6 = V_17 -> V_41 -> V_42 ( V_17 -> V_43 ,
V_17 -> V_19 -> V_20 - 1 , V_39 + 2 ) ;
if ( V_6 )
goto V_44;
} else {
V_6 = V_17 -> V_41 -> V_42 ( V_17 -> V_43 ,
V_17 -> V_19 -> V_20 , V_39 ) ;
if ( V_6 )
goto V_44;
}
V_38 = F_14 () ;
if ( V_5 -> V_24 )
memcpy ( V_39 + V_17 -> V_18 - sizeof( V_25 ) ,
& V_38 , sizeof( V_38 ) ) ;
V_5 -> V_8 -> V_46 ( V_2 -> V_5 , V_39 , V_38 ) ;
V_44:
F_7 ( V_17 -> V_32 -> V_33 , 0 ) ;
F_15 ( V_2 -> V_47 ) ;
F_3 ( V_39 ) ;
}
int F_16 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = F_5 ( V_2 ) ;
int V_6 ;
V_2 -> V_5 = F_17 ( V_2 ) ;
if ( ! V_2 -> V_5 ) {
V_6 = - V_11 ;
goto V_12;
}
V_2 -> V_5 -> V_8 = & V_48 ;
V_2 -> V_49 = F_18 ( & F_6 ,
& F_6 ,
0 ,
V_2 ,
L_1 ,
V_2 -> V_50 ,
V_2 -> V_51 ) ;
if ( V_2 -> V_49 == NULL ) {
V_6 = - V_11 ;
goto V_52;
}
V_2 -> V_5 -> V_53 = & V_54 ;
V_2 -> V_5 -> V_24 = true ;
F_19 ( & V_17 -> V_37 , & F_8 ) ;
V_2 -> V_55 |= V_56 ;
return 0 ;
V_52:
F_20 ( V_2 -> V_5 ) ;
V_12:
return V_6 ;
}
void F_21 ( struct V_1 * V_2 )
{
if ( V_2 -> V_47 ) {
F_22 ( V_2 -> V_47 ) ;
F_23 ( V_2 -> V_47 ,
V_2 -> V_49 ) ;
}
F_24 ( V_2 -> V_49 ) ;
F_20 ( V_2 -> V_5 ) ;
}
