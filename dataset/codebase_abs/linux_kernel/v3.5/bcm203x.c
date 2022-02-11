static void F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = V_1 -> V_4 ;
struct V_5 * V_6 = V_1 -> V_7 ;
int V_8 ;
F_2 ( L_1 , V_6 , V_1 ) ;
if ( V_1 -> V_9 ) {
F_3 ( L_2 , V_1 -> V_9 ) ;
V_3 -> V_10 = V_11 ;
return;
}
switch ( V_3 -> V_10 ) {
case V_12 :
memcpy ( V_3 -> V_13 , L_3 , 1 ) ;
F_4 ( V_1 , V_6 , F_5 ( V_6 , V_14 ) ,
V_3 -> V_13 , 1 , F_1 , V_3 ) ;
V_3 -> V_10 = V_15 ;
F_6 ( & V_3 -> V_16 ) ;
break;
case V_15 :
F_7 ( V_1 , V_6 , F_8 ( V_6 , V_17 ) ,
V_3 -> V_13 , 32 , F_1 , V_3 , 1 ) ;
V_3 -> V_10 = V_18 ;
if ( F_9 ( V_3 -> V_1 , V_19 ) < 0 )
F_3 ( L_4 ) ;
break;
case V_18 :
if ( V_3 -> V_13 [ 0 ] != '#' ) {
F_3 ( L_5 ) ;
V_3 -> V_10 = V_11 ;
break;
}
V_3 -> V_10 = V_20 ;
case V_20 :
if ( V_3 -> V_21 == V_3 -> V_22 ) {
F_7 ( V_1 , V_6 , F_8 ( V_6 , V_17 ) ,
V_3 -> V_13 , 32 , F_1 , V_3 , 1 ) ;
V_3 -> V_10 = V_23 ;
} else {
V_8 = F_10 ( V_24 , V_3 -> V_22 - V_3 -> V_21 , 4096 ) ;
F_4 ( V_1 , V_6 , F_5 ( V_6 , V_14 ) ,
V_3 -> V_25 + V_3 -> V_21 , V_8 , F_1 , V_3 ) ;
V_3 -> V_21 += V_8 ;
}
if ( F_9 ( V_3 -> V_1 , V_19 ) < 0 )
F_3 ( L_4 ) ;
break;
case V_23 :
if ( V_3 -> V_13 [ 0 ] != '.' ) {
F_3 ( L_6 ) ;
V_3 -> V_10 = V_11 ;
break;
}
V_3 -> V_10 = V_26 ;
break;
}
}
static void F_11 ( struct V_27 * V_16 )
{
struct V_2 * V_3 =
F_12 ( V_16 , struct V_2 , V_16 ) ;
if ( F_13 ( & V_3 -> V_28 ) )
return;
if ( F_9 ( V_3 -> V_1 , V_29 ) < 0 )
F_3 ( L_4 ) ;
}
static int F_14 ( struct V_30 * V_31 , const struct V_32 * V_33 )
{
const struct V_34 * V_34 ;
struct V_5 * V_6 = F_15 ( V_31 ) ;
struct V_2 * V_3 ;
int V_35 ;
F_2 ( L_7 , V_31 , V_33 ) ;
if ( V_31 -> V_36 -> V_37 . V_38 != 0 )
return - V_39 ;
V_3 = F_16 ( sizeof( * V_3 ) , V_29 ) ;
if ( ! V_3 ) {
F_3 ( L_8 ) ;
return - V_40 ;
}
V_3 -> V_6 = V_6 ;
V_3 -> V_10 = V_12 ;
V_3 -> V_1 = F_17 ( 0 , V_29 ) ;
if ( ! V_3 -> V_1 ) {
F_3 ( L_9 ) ;
F_18 ( V_3 ) ;
return - V_40 ;
}
if ( F_19 ( & V_34 , L_10 , & V_6 -> V_7 ) < 0 ) {
F_3 ( L_11 ) ;
F_20 ( V_3 -> V_1 ) ;
F_18 ( V_3 ) ;
return - V_41 ;
}
F_2 ( L_12 , V_34 -> V_3 , V_34 -> V_35 ) ;
V_35 = F_21 ( V_24 , V_34 -> V_35 , 4096 ) ;
V_3 -> V_13 = F_22 ( V_35 , V_29 ) ;
if ( ! V_3 -> V_13 ) {
F_3 ( L_13 ) ;
F_23 ( V_34 ) ;
F_20 ( V_3 -> V_1 ) ;
F_18 ( V_3 ) ;
return - V_40 ;
}
memcpy ( V_3 -> V_13 , V_34 -> V_3 , V_34 -> V_35 ) ;
F_4 ( V_3 -> V_1 , V_6 , F_5 ( V_6 , V_14 ) ,
V_3 -> V_13 , V_34 -> V_35 , F_1 , V_3 ) ;
F_23 ( V_34 ) ;
if ( F_19 ( & V_34 , L_14 , & V_6 -> V_7 ) < 0 ) {
F_3 ( L_15 ) ;
F_20 ( V_3 -> V_1 ) ;
F_18 ( V_3 -> V_13 ) ;
F_18 ( V_3 ) ;
return - V_41 ;
}
F_2 ( L_16 , V_34 -> V_3 , V_34 -> V_35 ) ;
V_3 -> V_25 = F_24 ( V_34 -> V_3 , V_34 -> V_35 , V_29 ) ;
if ( ! V_3 -> V_25 ) {
F_3 ( L_17 ) ;
F_23 ( V_34 ) ;
F_20 ( V_3 -> V_1 ) ;
F_18 ( V_3 -> V_13 ) ;
F_18 ( V_3 ) ;
return - V_40 ;
}
V_3 -> V_22 = V_34 -> V_35 ;
V_3 -> V_21 = 0 ;
F_23 ( V_34 ) ;
F_25 ( & V_3 -> V_16 , F_11 ) ;
F_26 ( V_31 , V_3 ) ;
F_6 ( & V_3 -> V_16 ) ;
return 0 ;
}
static void F_27 ( struct V_30 * V_31 )
{
struct V_2 * V_3 = F_28 ( V_31 ) ;
F_2 ( L_18 , V_31 ) ;
F_29 ( & V_3 -> V_28 ) ;
F_30 ( & V_3 -> V_16 ) ;
F_31 ( V_3 -> V_1 ) ;
F_26 ( V_31 , NULL ) ;
F_20 ( V_3 -> V_1 ) ;
F_18 ( V_3 -> V_25 ) ;
F_18 ( V_3 -> V_13 ) ;
F_18 ( V_3 ) ;
}
