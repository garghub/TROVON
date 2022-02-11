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
static int F_6 ( struct V_1 * V_2 , T_1 V_16 , T_1 * V_17 , int V_5 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_9 * V_10 = V_7 -> V_10 ;
V_7 -> V_18 [ 0 ] = V_16 ;
if ( V_17 )
memcpy ( & V_7 -> V_18 [ 1 ] , V_17 , V_5 ) ;
return F_7 ( V_10 , V_7 -> V_18 , V_5 + 1 ) ;
}
static void F_8 ( struct V_1 * V_2 , T_2 V_19 , T_3 V_5 ,
T_3 * V_20 , const T_4 * V_17 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_9 * V_10 = V_7 -> V_10 ;
struct V_21 V_22 [ 2 ] = {} ;
struct V_23 V_24 ;
int V_25 = F_5 ( V_2 ) ;
F_9 ( & V_24 ) ;
if ( V_2 -> V_26 == V_27 && V_2 -> V_28 )
V_25 = 1 ;
V_7 -> V_18 [ 0 ] = V_2 -> V_26 ;
F_4 ( V_2 , V_19 , V_7 -> V_18 ) ;
V_22 [ 0 ] . V_29 = V_7 -> V_18 ;
V_22 [ 0 ] . V_5 = V_25 ;
F_10 ( & V_22 [ 0 ] , & V_24 ) ;
V_22 [ 1 ] . V_29 = V_17 ;
V_22 [ 1 ] . V_5 = V_5 ;
F_10 ( & V_22 [ 1 ] , & V_24 ) ;
F_11 ( V_10 , & V_24 ) ;
* V_20 += V_24 . V_30 - V_25 ;
}
static inline unsigned int F_12 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_31 ) {
case V_32 :
return 2 ;
case V_33 :
return 4 ;
default:
return 0 ;
}
}
static int F_13 ( struct V_1 * V_2 , T_2 V_34 , T_3 V_5 ,
T_3 * V_20 , T_4 * V_17 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_9 * V_10 = V_7 -> V_10 ;
struct V_21 V_22 [ 2 ] ;
struct V_23 V_24 ;
unsigned int V_35 = V_2 -> V_36 ;
V_35 /= 8 ;
F_9 ( & V_24 ) ;
memset ( V_22 , 0 , ( sizeof V_22 ) ) ;
V_7 -> V_18 [ 0 ] = V_2 -> V_37 ;
F_4 ( V_2 , V_34 , V_7 -> V_18 ) ;
V_22 [ 0 ] . V_29 = V_7 -> V_18 ;
V_22 [ 0 ] . V_5 = F_5 ( V_2 ) + V_35 ;
F_10 ( & V_22 [ 0 ] , & V_24 ) ;
V_22 [ 1 ] . V_38 = V_17 ;
V_22 [ 1 ] . V_39 = F_12 ( V_2 ) ;
V_22 [ 1 ] . V_5 = V_5 ;
F_10 ( & V_22 [ 1 ] , & V_24 ) ;
F_11 ( V_10 , & V_24 ) ;
* V_20 = V_24 . V_30 - F_5 ( V_2 ) - V_35 ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 , T_2 V_40 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
F_15 ( V_2 -> V_12 , L_2 ,
V_7 -> V_1 . V_41 . V_42 / 1024 , ( V_43 ) V_40 ) ;
V_7 -> V_18 [ 0 ] = V_2 -> V_44 ;
F_4 ( V_2 , V_40 , V_7 -> V_18 ) ;
F_7 ( V_7 -> V_10 , V_7 -> V_18 , F_5 ( V_2 ) ) ;
return 0 ;
}
static int F_16 ( struct V_9 * V_10 )
{
struct V_45 V_46 ;
struct V_47 * V_48 ;
struct V_6 * V_7 ;
struct V_1 * V_2 ;
enum V_49 V_50 = V_51 ;
char * V_52 = NULL ;
int V_11 ;
V_48 = F_17 ( & V_10 -> V_12 ) ;
V_7 = F_18 ( & V_10 -> V_12 , sizeof( * V_7 ) , V_53 ) ;
if ( ! V_7 )
return - V_54 ;
V_2 = & V_7 -> V_1 ;
V_2 -> V_55 = F_13 ;
V_2 -> V_56 = F_8 ;
V_2 -> V_57 = F_14 ;
V_2 -> V_58 = F_6 ;
V_2 -> V_59 = F_1 ;
V_2 -> V_12 = & V_10 -> V_12 ;
V_2 -> V_60 = V_10 -> V_12 . V_61 ;
V_2 -> V_8 = V_7 ;
F_19 ( V_10 , V_7 ) ;
V_7 -> V_10 = V_10 ;
if ( V_10 -> V_50 & V_62 )
V_50 = V_33 ;
else if ( V_10 -> V_50 & V_63 )
V_50 = V_32 ;
if ( V_48 && V_48 -> V_64 )
V_2 -> V_41 . V_64 = V_48 -> V_64 ;
if ( V_48 && V_48 -> type )
V_52 = V_48 -> type ;
else
V_52 = V_10 -> V_65 ;
V_11 = F_20 ( V_2 , V_52 , V_50 ) ;
if ( V_11 )
return V_11 ;
V_46 . V_61 = V_10 -> V_12 . V_61 ;
return F_21 ( & V_2 -> V_41 , NULL , & V_46 ,
V_48 ? V_48 -> V_66 : NULL ,
V_48 ? V_48 -> V_67 : 0 ) ;
}
static int F_22 ( struct V_9 * V_10 )
{
struct V_6 * V_7 = F_23 ( V_10 ) ;
return F_24 ( & V_7 -> V_1 . V_41 ) ;
}
