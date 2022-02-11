static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_8 * V_10 = V_6 -> V_10 ;
int V_11 ;
V_11 = F_2 ( V_9 , 0 ,
25000000 , V_12 ) ;
if ( V_11 ) {
F_3 ( L_1 , V_13 ) ;
return V_11 ;
}
V_11 = F_2 ( V_10 , V_14 , 0 ,
V_15 ) ;
if ( V_11 ) {
F_3 ( L_2 ) ;
return V_11 ;
}
return 0 ;
}
static int F_4 ( struct V_16 * V_17 ,
struct V_18 * V_19 )
{
struct V_20 * V_21 =
(struct V_20 * ) V_17 -> V_22 ;
int V_23 = V_19 -> V_23 . integer . V_23 [ 0 ] ;
unsigned int V_24 = V_21 -> V_24 ;
int V_25 = V_21 -> V_25 ;
if ( V_23 > V_25 )
return - V_26 ;
switch ( V_24 ) {
case V_27 :
F_5 ( V_28 , V_23 & 1 ) ;
F_5 ( V_29 , V_23 >> 1 ) ;
V_30 = V_23 ;
break;
case V_31 :
F_5 ( V_32 , V_23 & 1 ) ;
F_5 ( V_33 , V_23 >> 1 ) ;
V_34 = V_23 ;
break;
}
return 0 ;
}
static int F_6 ( struct V_16 * V_17 ,
struct V_18 * V_19 )
{
struct V_20 * V_21 =
(struct V_20 * ) V_17 -> V_22 ;
unsigned int V_24 = V_21 -> V_24 ;
switch ( V_24 ) {
case V_27 :
V_19 -> V_23 . integer . V_23 [ 0 ] = V_30 ;
break;
case V_31 :
V_19 -> V_23 . integer . V_23 [ 0 ] = V_34 ;
break;
}
return 0 ;
}
static int F_7 ( struct V_35 * V_36 )
{
struct V_37 * V_38 = V_36 -> V_39 . V_40 ;
int V_11 ;
if ( ! V_38 ) {
F_8 ( & V_36 -> V_39 , L_3 ) ;
return - V_26 ;
}
V_28 = V_38 -> V_41 ;
V_29 = V_38 -> V_42 ;
V_32 = V_38 -> V_43 ;
V_33 = V_38 -> V_44 ;
V_45 . V_39 = & V_36 -> V_39 ;
V_11 = F_9 ( & V_45 ) ;
if ( V_11 ) {
F_8 ( & V_36 -> V_39 , L_4 ,
V_11 ) ;
return V_11 ;
}
F_10 ( V_46 ,
V_47 |
V_48 |
V_49 |
F_11 ( V_50 ) |
F_12 ( V_50 )
) ;
F_10 ( V_50 ,
V_47 |
F_12 ( V_46 )
) ;
return V_11 ;
}
static int F_13 ( struct V_35 * V_36 )
{
F_14 ( & V_45 ) ;
return 0 ;
}
