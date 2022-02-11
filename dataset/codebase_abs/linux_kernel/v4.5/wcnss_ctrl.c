static int F_1 ( struct V_1 * V_2 ,
const void * V_3 ,
T_1 V_4 )
{
struct V_5 * V_6 = F_2 ( & V_2 -> V_7 ) ;
const struct V_8 * V_9 ;
const struct V_10 * V_11 ;
const struct V_12 * V_13 = V_3 ;
switch ( V_13 -> type ) {
case V_14 :
if ( V_4 != sizeof( * V_11 ) ) {
F_3 ( V_6 -> V_7 ,
L_1 ) ;
break;
}
V_11 = V_3 ;
F_4 ( V_6 -> V_7 , L_2 ,
V_11 -> V_15 , V_11 -> V_16 ,
V_11 -> V_11 , V_11 -> V_17 ) ;
F_5 ( & V_6 -> V_18 ) ;
break;
case V_19 :
if ( V_4 != sizeof( * V_9 ) ) {
F_3 ( V_6 -> V_7 ,
L_3 ) ;
break;
}
V_9 = V_3 ;
V_6 -> V_20 = V_9 -> V_21 ;
F_6 ( & V_6 -> V_22 ) ;
break;
default:
F_4 ( V_6 -> V_7 , L_4 , V_13 -> type ) ;
break;
}
return 0 ;
}
static int F_7 ( struct V_5 * V_6 )
{
struct V_12 V_23 ;
V_23 . type = V_24 ;
V_23 . V_25 = sizeof( V_23 ) ;
return F_8 ( V_6 -> V_26 , & V_23 , sizeof( V_23 ) ) ;
}
static void F_9 ( struct V_27 * V_28 )
{
struct V_5 * V_6 = F_10 ( V_28 , struct V_5 , V_18 ) ;
struct V_29 * V_30 ;
const struct V_31 * V_32 ;
const void * V_3 ;
T_2 V_33 ;
int V_34 ;
V_30 = F_11 ( sizeof( * V_30 ) + V_35 , V_36 ) ;
if ( ! V_30 )
return;
V_34 = F_12 ( & V_32 , V_37 , V_6 -> V_7 ) ;
if ( V_34 ) {
F_3 ( V_6 -> V_7 , L_5 ,
V_37 , V_34 ) ;
goto V_38;
}
V_3 = V_32 -> V_3 ;
V_33 = V_32 -> V_39 ;
V_30 -> V_13 . type = V_40 ;
V_30 -> V_13 . V_25 = sizeof( * V_30 ) + V_35 ;
V_30 -> V_41 = 0 ;
V_30 -> V_42 = V_35 ;
V_30 -> V_43 = 0 ;
do {
if ( V_33 <= V_35 ) {
V_30 -> V_41 = 1 ;
V_30 -> V_42 = V_33 ;
V_30 -> V_13 . V_25 = sizeof( * V_30 ) + V_33 ;
}
memcpy ( V_30 -> V_44 , V_3 , V_30 -> V_42 ) ;
V_34 = F_8 ( V_6 -> V_26 , V_30 , V_30 -> V_13 . V_25 ) ;
if ( V_34 ) {
F_3 ( V_6 -> V_7 , L_6 ) ;
goto V_45;
}
V_30 -> V_43 ++ ;
V_3 += V_30 -> V_13 . V_25 ;
V_33 -= V_35 ;
} while ( V_33 > 0 );
V_34 = F_13 ( & V_6 -> V_22 , V_46 ) ;
if ( ! V_34 )
F_3 ( V_6 -> V_7 , L_7 ) ;
else if ( V_6 -> V_20 != 1 )
F_3 ( V_6 -> V_7 , L_8 ,
V_6 -> V_20 ) ;
V_45:
F_14 ( V_32 ) ;
V_38:
F_15 ( V_30 ) ;
}
static int F_16 ( struct V_1 * V_47 )
{
struct V_5 * V_6 ;
V_6 = F_17 ( & V_47 -> V_7 , sizeof( * V_6 ) , V_36 ) ;
if ( ! V_6 )
return - V_48 ;
V_6 -> V_7 = & V_47 -> V_7 ;
V_6 -> V_26 = V_47 -> V_26 ;
F_18 ( & V_6 -> V_22 ) ;
F_19 ( & V_6 -> V_18 , F_9 ) ;
F_20 ( & V_47 -> V_7 , V_6 ) ;
return F_7 ( V_6 ) ;
}
