static void F_1 ( struct V_1 * V_2 ,
unsigned int V_3 , T_1 * V_4 )
{
int V_5 ;
for ( V_5 = V_2 -> V_6 -> V_7 ; V_5 > 0 ; V_5 -- , V_3 >>= 8 )
V_4 [ V_5 ] = V_3 ;
}
static int F_2 ( struct V_1 * V_2 )
{
return 1 + V_2 -> V_6 -> V_7 ;
}
static int F_3 ( struct V_8 * V_9 , T_2 V_10 , T_3 V_11 ,
T_3 * V_12 , const unsigned char * V_13 )
{
struct V_1 * V_2 = F_4 ( V_9 ) ;
struct V_14 V_15 [ 2 ] = {} ;
struct V_16 V_17 ;
unsigned char V_18 [ V_19 ] ;
F_5 ( & V_17 ) ;
V_18 [ 0 ] = V_20 ;
F_1 ( V_2 , V_10 , V_18 ) ;
V_15 [ 0 ] . V_21 = V_18 ;
V_15 [ 0 ] . V_11 = F_2 ( V_2 ) ;
F_6 ( & V_15 [ 0 ] , & V_17 ) ;
V_15 [ 1 ] . V_21 = V_13 ;
V_15 [ 1 ] . V_11 = V_11 ;
F_6 ( & V_15 [ 1 ] , & V_17 ) ;
F_7 ( & V_2 -> V_22 ) ;
F_8 ( V_2 -> V_23 , & V_17 ) ;
if ( V_12 && V_17 . V_24 > sizeof( V_18 ) )
* V_12 += V_17 . V_24 - sizeof( V_18 ) ;
F_9 ( & V_2 -> V_22 ) ;
return 0 ;
}
static int F_10 ( struct V_8 * V_9 , T_2 V_25 , T_3 V_11 ,
T_3 * V_12 , unsigned char * V_13 )
{
struct V_1 * V_2 = F_4 ( V_9 ) ;
struct V_14 V_15 [ 2 ] = {} ;
struct V_16 V_17 ;
unsigned char V_18 [ V_19 ] ;
F_5 ( & V_17 ) ;
memset ( & V_15 , 0 , sizeof( V_15 ) ) ;
V_18 [ 0 ] = V_26 ;
F_1 ( V_2 , V_25 , V_18 ) ;
V_15 [ 0 ] . V_21 = V_18 ;
V_15 [ 0 ] . V_11 = F_2 ( V_2 ) ;
F_6 ( & V_15 [ 0 ] , & V_17 ) ;
V_15 [ 1 ] . V_27 = V_13 ;
V_15 [ 1 ] . V_11 = V_11 ;
F_6 ( & V_15 [ 1 ] , & V_17 ) ;
F_7 ( & V_2 -> V_22 ) ;
F_8 ( V_2 -> V_23 , & V_17 ) ;
if ( V_12 && V_17 . V_24 > sizeof( V_18 ) )
* V_12 += V_17 . V_24 - sizeof( V_18 ) ;
F_9 ( & V_2 -> V_22 ) ;
return 0 ;
}
static int F_11 ( struct V_28 * V_23 )
{
struct V_14 V_15 = {} ;
struct V_16 V_17 ;
unsigned char V_18 [ 2 ] ;
F_5 ( & V_17 ) ;
V_18 [ 0 ] = V_29 ;
V_18 [ 1 ] = V_30 ;
V_15 . V_21 = V_18 ;
V_15 . V_11 = sizeof( V_18 ) ;
F_6 ( & V_15 , & V_17 ) ;
return F_8 ( V_23 , & V_17 ) ;
}
static int F_12 ( struct V_28 * V_23 )
{
struct V_1 * V_2 ;
struct V_31 * V_32 ;
int V_33 ;
V_2 = F_13 ( & V_23 -> V_34 , sizeof( * V_2 ) , V_35 ) ;
if ( ! V_2 )
return - V_36 ;
V_2 -> V_23 = V_23 ;
F_14 ( & V_2 -> V_22 ) ;
F_15 ( V_23 , V_2 ) ;
V_33 = F_11 ( V_23 ) ;
if ( V_33 )
return V_33 ;
V_32 = F_16 ( & V_23 -> V_34 ) ;
V_2 -> V_6 = F_17 ( & V_23 -> V_34 ) ;
if ( ! V_2 -> V_6 )
V_2 -> V_6 = & V_37 ;
F_18 ( & V_2 -> V_9 , V_23 -> V_34 . V_38 ) ;
V_2 -> V_9 . V_34 . V_39 = & V_23 -> V_34 ;
V_2 -> V_9 . type = V_40 ;
V_2 -> V_9 . V_41 = V_42 ;
V_2 -> V_9 . V_43 = 1 ;
V_2 -> V_9 . V_44 = V_2 -> V_6 -> V_44 ;
V_2 -> V_9 . V_45 = F_10 ;
V_2 -> V_9 . V_46 = F_3 ;
V_33 = F_19 ( & V_2 -> V_9 , V_32 ? V_32 -> V_47 : NULL ,
V_32 ? V_32 -> V_48 : 0 ) ;
if ( V_33 )
return V_33 ;
return 0 ;
}
static int F_20 ( struct V_28 * V_23 )
{
struct V_1 * V_2 = F_21 ( V_23 ) ;
return F_22 ( & V_2 -> V_9 ) ;
}
