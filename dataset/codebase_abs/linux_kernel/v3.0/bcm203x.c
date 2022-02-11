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
if ( F_9 ( V_3 -> V_1 , V_19 ) < 0 )
F_3 ( L_4 ) ;
}
static int F_13 ( struct V_28 * V_29 , const struct V_30 * V_31 )
{
const struct V_32 * V_32 ;
struct V_5 * V_6 = F_14 ( V_29 ) ;
struct V_2 * V_3 ;
int V_33 ;
F_2 ( L_7 , V_29 , V_31 ) ;
if ( V_29 -> V_34 -> V_35 . V_36 != 0 )
return - V_37 ;
V_3 = F_15 ( sizeof( * V_3 ) , V_38 ) ;
if ( ! V_3 ) {
F_3 ( L_8 ) ;
return - V_39 ;
}
V_3 -> V_6 = V_6 ;
V_3 -> V_10 = V_12 ;
V_3 -> V_1 = F_16 ( 0 , V_38 ) ;
if ( ! V_3 -> V_1 ) {
F_3 ( L_9 ) ;
F_17 ( V_3 ) ;
return - V_39 ;
}
if ( F_18 ( & V_32 , L_10 , & V_6 -> V_7 ) < 0 ) {
F_3 ( L_11 ) ;
F_19 ( V_3 -> V_1 ) ;
F_17 ( V_3 ) ;
return - V_40 ;
}
F_2 ( L_12 , V_32 -> V_3 , V_32 -> V_33 ) ;
V_33 = F_20 ( V_24 , V_32 -> V_33 , 4096 ) ;
V_3 -> V_13 = F_21 ( V_33 , V_38 ) ;
if ( ! V_3 -> V_13 ) {
F_3 ( L_13 ) ;
F_22 ( V_32 ) ;
F_19 ( V_3 -> V_1 ) ;
F_17 ( V_3 ) ;
return - V_39 ;
}
memcpy ( V_3 -> V_13 , V_32 -> V_3 , V_32 -> V_33 ) ;
F_4 ( V_3 -> V_1 , V_6 , F_5 ( V_6 , V_14 ) ,
V_3 -> V_13 , V_32 -> V_33 , F_1 , V_3 ) ;
F_22 ( V_32 ) ;
if ( F_18 ( & V_32 , L_14 , & V_6 -> V_7 ) < 0 ) {
F_3 ( L_15 ) ;
F_19 ( V_3 -> V_1 ) ;
F_17 ( V_3 -> V_13 ) ;
F_17 ( V_3 ) ;
return - V_40 ;
}
F_2 ( L_16 , V_32 -> V_3 , V_32 -> V_33 ) ;
V_3 -> V_25 = F_23 ( V_32 -> V_3 , V_32 -> V_33 , V_38 ) ;
if ( ! V_3 -> V_25 ) {
F_3 ( L_17 ) ;
F_22 ( V_32 ) ;
F_19 ( V_3 -> V_1 ) ;
F_17 ( V_3 -> V_13 ) ;
F_17 ( V_3 ) ;
return - V_39 ;
}
V_3 -> V_22 = V_32 -> V_33 ;
V_3 -> V_21 = 0 ;
F_22 ( V_32 ) ;
F_24 ( & V_3 -> V_16 , F_11 ) ;
F_25 ( V_29 , V_3 ) ;
F_6 ( & V_3 -> V_16 ) ;
return 0 ;
}
static void F_26 ( struct V_28 * V_29 )
{
struct V_2 * V_3 = F_27 ( V_29 ) ;
F_2 ( L_18 , V_29 ) ;
F_28 ( V_3 -> V_1 ) ;
F_25 ( V_29 , NULL ) ;
F_19 ( V_3 -> V_1 ) ;
F_17 ( V_3 -> V_25 ) ;
F_17 ( V_3 -> V_13 ) ;
F_17 ( V_3 ) ;
}
static int T_1 F_29 ( void )
{
int V_41 ;
F_30 ( L_19 , V_42 ) ;
V_41 = F_31 ( & V_43 ) ;
if ( V_41 < 0 )
F_3 ( L_20 ) ;
return V_41 ;
}
static void T_2 F_32 ( void )
{
F_33 ( & V_43 ) ;
}
