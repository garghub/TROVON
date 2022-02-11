static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_8 * V_10 = V_6 -> V_10 ;
int V_11 ;
T_1 V_12 ;
V_12 = V_13 | V_14 |
V_15 ;
F_2 ( V_9 , V_12 ) ;
F_2 ( V_10 , V_12 ) ;
V_11 = F_3 ( V_9 , 0 ,
25000000 , V_16 ) ;
if ( V_11 ) {
F_4 ( L_1 , V_17 ) ;
return V_11 ;
}
V_11 = F_3 ( V_10 , V_18 , 0 ,
V_19 ) ;
if ( V_11 ) {
F_4 ( L_2 ) ;
return V_11 ;
}
return 0 ;
}
static int F_5 ( struct V_20 * V_21 ,
struct V_22 * V_23 )
{
struct V_24 * V_25 =
(struct V_24 * ) V_21 -> V_26 ;
int V_27 = V_23 -> V_27 . integer . V_27 [ 0 ] ;
unsigned int V_28 = V_25 -> V_28 ;
int V_29 = V_25 -> V_29 ;
if ( V_27 > V_29 )
return - V_30 ;
switch ( V_28 ) {
case V_31 :
F_6 ( V_32 , V_27 & 1 ) ;
F_6 ( V_33 , V_27 >> 1 ) ;
V_34 = V_27 ;
break;
case V_35 :
F_6 ( V_36 , V_27 & 1 ) ;
F_6 ( V_37 , V_27 >> 1 ) ;
V_38 = V_27 ;
break;
}
return 0 ;
}
static int F_7 ( struct V_20 * V_21 ,
struct V_22 * V_23 )
{
struct V_24 * V_25 =
(struct V_24 * ) V_21 -> V_26 ;
unsigned int V_28 = V_25 -> V_28 ;
switch ( V_28 ) {
case V_31 :
V_23 -> V_27 . integer . V_27 [ 0 ] = V_34 ;
break;
case V_35 :
V_23 -> V_27 . integer . V_27 [ 0 ] = V_38 ;
break;
}
return 0 ;
}
static int F_8 ( struct V_39 * V_40 )
{
struct V_41 * V_42 = V_40 -> V_43 . V_44 ;
int V_11 ;
if ( ! V_42 ) {
F_9 ( & V_40 -> V_43 , L_3 ) ;
return - V_30 ;
}
V_32 = V_42 -> V_45 ;
V_33 = V_42 -> V_46 ;
V_36 = V_42 -> V_47 ;
V_37 = V_42 -> V_48 ;
V_49 . V_43 = & V_40 -> V_43 ;
V_11 = F_10 ( & V_49 ) ;
if ( V_11 ) {
F_9 ( & V_40 -> V_43 , L_4 ,
V_11 ) ;
return V_11 ;
}
F_11 ( V_50 ,
V_51 |
V_52 |
V_53 |
F_12 ( V_54 ) |
F_13 ( V_54 )
) ;
F_11 ( V_54 ,
V_51 |
F_13 ( V_50 )
) ;
return V_11 ;
}
static int F_14 ( struct V_39 * V_40 )
{
F_15 ( & V_49 ) ;
return 0 ;
}
