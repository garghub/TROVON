static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 * V_4 , int V_5 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_9 * V_10 = V_7 -> V_10 ;
int V_11 ;
V_11 = F_2 ( V_10 , & V_3 , 1 , V_4 , V_5 ) ;
if ( V_11 < 0 )
F_3 ( & V_10 -> V_12 , L_1 , V_11 , V_3 ) ;
return V_11 ;
}
static void F_4 ( struct V_1 * V_2 , unsigned int V_13 , T_1 * V_14 )
{
V_14 [ 1 ] = V_13 >> ( V_2 -> V_15 * 8 - 8 ) ;
V_14 [ 2 ] = V_13 >> ( V_2 -> V_15 * 8 - 16 ) ;
V_14 [ 3 ] = V_13 >> ( V_2 -> V_15 * 8 - 24 ) ;
V_14 [ 4 ] = V_13 >> ( V_2 -> V_15 * 8 - 32 ) ;
}
static int F_5 ( struct V_1 * V_2 )
{
return 1 + V_2 -> V_15 ;
}
static int F_6 ( struct V_1 * V_2 , T_1 V_16 , T_1 * V_17 , int V_5 ,
int V_18 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_9 * V_10 = V_7 -> V_10 ;
V_7 -> V_19 [ 0 ] = V_16 ;
if ( V_17 )
memcpy ( & V_7 -> V_19 [ 1 ] , V_17 , V_5 ) ;
return F_7 ( V_10 , V_7 -> V_19 , V_5 + 1 ) ;
}
static void F_8 ( struct V_1 * V_2 , T_2 V_20 , T_3 V_5 ,
T_3 * V_21 , const T_4 * V_17 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_9 * V_10 = V_7 -> V_10 ;
struct V_22 V_23 [ 2 ] = {} ;
struct V_24 V_25 ;
int V_26 = F_5 ( V_2 ) ;
F_9 ( & V_25 ) ;
if ( V_2 -> V_27 == V_28 && V_2 -> V_29 )
V_26 = 1 ;
V_7 -> V_19 [ 0 ] = V_2 -> V_27 ;
F_4 ( V_2 , V_20 , V_7 -> V_19 ) ;
V_23 [ 0 ] . V_30 = V_7 -> V_19 ;
V_23 [ 0 ] . V_5 = V_26 ;
F_10 ( & V_23 [ 0 ] , & V_25 ) ;
V_23 [ 1 ] . V_30 = V_17 ;
V_23 [ 1 ] . V_5 = V_5 ;
F_10 ( & V_23 [ 1 ] , & V_25 ) ;
F_11 ( V_10 , & V_25 ) ;
* V_21 += V_25 . V_31 - V_26 ;
}
static inline unsigned int F_12 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_32 ) {
case V_33 :
return 2 ;
case V_34 :
return 4 ;
default:
return 0 ;
}
}
static int F_13 ( struct V_1 * V_2 , T_2 V_35 , T_3 V_5 ,
T_3 * V_21 , T_4 * V_17 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_9 * V_10 = V_7 -> V_10 ;
struct V_22 V_23 [ 2 ] ;
struct V_24 V_25 ;
int V_36 = V_2 -> V_37 ;
int V_11 ;
V_11 = V_2 -> V_38 ( V_2 ) ;
if ( V_11 )
return V_11 ;
F_9 ( & V_25 ) ;
memset ( V_23 , 0 , ( sizeof V_23 ) ) ;
V_7 -> V_19 [ 0 ] = V_2 -> V_39 ;
F_4 ( V_2 , V_35 , V_7 -> V_19 ) ;
V_23 [ 0 ] . V_30 = V_7 -> V_19 ;
V_23 [ 0 ] . V_5 = F_5 ( V_2 ) + V_36 ;
F_10 ( & V_23 [ 0 ] , & V_25 ) ;
V_23 [ 1 ] . V_40 = V_17 ;
V_23 [ 1 ] . V_41 = F_12 ( V_2 ) ;
V_23 [ 1 ] . V_5 = V_5 ;
F_10 ( & V_23 [ 1 ] , & V_25 ) ;
F_11 ( V_10 , & V_25 ) ;
* V_21 = V_25 . V_31 - F_5 ( V_2 ) - V_36 ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 , T_2 V_42 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
int V_11 ;
F_15 ( V_2 -> V_12 , L_2 ,
V_7 -> V_43 . V_44 / 1024 , ( V_45 ) V_42 ) ;
V_11 = V_2 -> V_38 ( V_2 ) ;
if ( V_11 )
return V_11 ;
V_11 = V_2 -> V_46 ( V_2 , V_47 , NULL , 0 , 0 ) ;
if ( V_11 )
return V_11 ;
V_7 -> V_19 [ 0 ] = V_2 -> V_48 ;
F_4 ( V_2 , V_42 , V_7 -> V_19 ) ;
F_7 ( V_7 -> V_10 , V_7 -> V_19 , F_5 ( V_2 ) ) ;
return 0 ;
}
static int F_16 ( struct V_9 * V_10 )
{
struct V_49 V_50 ;
struct V_51 * V_52 ;
struct V_6 * V_7 ;
struct V_1 * V_2 ;
enum V_53 V_54 = V_55 ;
int V_11 ;
V_7 = F_17 ( & V_10 -> V_12 , sizeof( * V_7 ) , V_56 ) ;
if ( ! V_7 )
return - V_57 ;
V_2 = & V_7 -> V_1 ;
V_2 -> V_58 = F_13 ;
V_2 -> V_59 = F_8 ;
V_2 -> V_60 = F_14 ;
V_2 -> V_46 = F_6 ;
V_2 -> V_61 = F_1 ;
V_2 -> V_12 = & V_10 -> V_12 ;
V_2 -> V_43 = & V_7 -> V_43 ;
V_2 -> V_8 = V_7 ;
F_18 ( V_10 , V_7 ) ;
V_7 -> V_43 . V_8 = V_2 ;
V_7 -> V_10 = V_10 ;
if ( V_10 -> V_54 & V_62 )
V_54 = V_34 ;
else if ( V_10 -> V_54 & V_63 )
V_54 = V_33 ;
V_11 = F_19 ( V_2 , F_20 ( V_10 ) , V_54 ) ;
if ( V_11 )
return V_11 ;
V_52 = F_21 ( & V_10 -> V_12 ) ;
V_50 . V_64 = V_10 -> V_12 . V_64 ;
return F_22 ( & V_7 -> V_43 , NULL , & V_50 ,
V_52 ? V_52 -> V_65 : NULL ,
V_52 ? V_52 -> V_66 : 0 ) ;
}
static int F_23 ( struct V_9 * V_10 )
{
struct V_6 * V_7 = F_24 ( V_10 ) ;
return F_25 ( & V_7 -> V_43 ) ;
}
