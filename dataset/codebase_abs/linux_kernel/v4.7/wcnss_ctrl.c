static int F_1 ( struct V_1 * V_2 ,
const void * V_3 ,
T_1 V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
const struct V_7 * V_8 ;
const struct V_9 * V_10 ;
const struct V_11 * V_12 = V_3 ;
switch ( V_12 -> type ) {
case V_13 :
if ( V_4 != sizeof( * V_10 ) ) {
F_3 ( V_6 -> V_14 ,
L_1 ) ;
break;
}
V_10 = V_3 ;
F_4 ( V_6 -> V_14 , L_2 ,
V_10 -> V_15 , V_10 -> V_16 ,
V_10 -> V_10 , V_10 -> V_17 ) ;
F_5 ( & V_6 -> V_18 ) ;
break;
case V_19 :
if ( V_4 != sizeof( * V_8 ) ) {
F_3 ( V_6 -> V_14 ,
L_3 ) ;
break;
}
V_8 = V_3 ;
V_6 -> V_20 = V_8 -> V_21 ;
F_6 ( & V_6 -> V_22 ) ;
break;
default:
F_4 ( V_6 -> V_14 , L_4 , V_12 -> type ) ;
break;
}
return 0 ;
}
static int F_7 ( struct V_5 * V_6 )
{
struct V_11 V_23 ;
V_23 . type = V_24 ;
V_23 . V_25 = sizeof( V_23 ) ;
return F_8 ( V_6 -> V_2 , & V_23 , sizeof( V_23 ) ) ;
}
static void F_9 ( struct V_26 * V_27 )
{
struct V_5 * V_6 = F_10 ( V_27 , struct V_5 , V_18 ) ;
struct V_28 * V_29 ;
const struct V_30 * V_31 ;
const void * V_3 ;
T_2 V_32 ;
int V_33 ;
V_29 = F_11 ( sizeof( * V_29 ) + V_34 , V_35 ) ;
if ( ! V_29 )
return;
V_33 = F_12 ( & V_31 , V_36 , V_6 -> V_14 ) ;
if ( V_33 ) {
F_3 ( V_6 -> V_14 , L_5 ,
V_36 , V_33 ) ;
goto V_37;
}
V_3 = V_31 -> V_3 ;
V_32 = V_31 -> V_38 ;
V_29 -> V_12 . type = V_39 ;
V_29 -> V_12 . V_25 = sizeof( * V_29 ) + V_34 ;
V_29 -> V_40 = 0 ;
V_29 -> V_41 = V_34 ;
V_29 -> V_42 = 0 ;
do {
if ( V_32 <= V_34 ) {
V_29 -> V_40 = 1 ;
V_29 -> V_41 = V_32 ;
V_29 -> V_12 . V_25 = sizeof( * V_29 ) + V_32 ;
}
memcpy ( V_29 -> V_43 , V_3 , V_29 -> V_41 ) ;
V_33 = F_8 ( V_6 -> V_2 , V_29 , V_29 -> V_12 . V_25 ) ;
if ( V_33 ) {
F_3 ( V_6 -> V_14 , L_6 ) ;
goto V_44;
}
V_29 -> V_42 ++ ;
V_3 += V_29 -> V_12 . V_25 ;
V_32 -= V_34 ;
} while ( V_32 > 0 );
V_33 = F_13 ( & V_6 -> V_22 , V_45 ) ;
if ( ! V_33 )
F_3 ( V_6 -> V_14 , L_7 ) ;
else if ( V_6 -> V_20 != 1 )
F_3 ( V_6 -> V_14 , L_8 ,
V_6 -> V_20 ) ;
V_44:
F_14 ( V_31 ) ;
V_37:
F_15 ( V_29 ) ;
}
static int F_16 ( struct V_46 * V_47 )
{
struct V_5 * V_6 ;
V_6 = F_17 ( & V_47 -> V_14 , sizeof( * V_6 ) , V_35 ) ;
if ( ! V_6 )
return - V_48 ;
V_6 -> V_14 = & V_47 -> V_14 ;
V_6 -> V_2 = V_47 -> V_2 ;
F_18 ( & V_6 -> V_22 ) ;
F_19 ( & V_6 -> V_18 , F_9 ) ;
F_20 ( V_47 -> V_2 , V_6 ) ;
return F_7 ( V_6 ) ;
}
