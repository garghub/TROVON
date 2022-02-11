static inline void F_1 ( int V_1 )
{
F_2 ( V_1 , V_2 ) ;
}
static inline void F_3 ( int V_3 )
{
F_2 ( V_3 , V_4 ) ;
}
static void F_4 ( struct V_5 * V_6 , int V_7 )
{
if ( V_6 -> V_8 -> V_9 )
V_6 -> V_8 -> V_9 ( V_6 -> V_10 , V_7 ) ;
switch ( V_7 ) {
case V_11 :
case V_12 :
case V_13 :
case V_14 :
F_1 ( 0 ) ;
F_3 ( 0 ) ;
break;
case V_15 :
F_1 ( V_6 -> V_16 ) ;
F_3 ( 1 ) ;
break;
}
}
static int F_5 ( struct V_17 * V_10 )
{
struct V_18 * V_19 = F_6 ( V_10 ) ;
struct V_5 * V_6 = F_7 ( V_19 ) ;
F_4 ( V_6 , V_14 ) ;
return 0 ;
}
static int F_8 ( struct V_17 * V_10 )
{
struct V_18 * V_19 = F_6 ( V_10 ) ;
struct V_5 * V_6 = F_7 ( V_19 ) ;
F_4 ( V_6 , V_6 -> V_20 ) ;
return 0 ;
}
static int F_9 ( struct V_18 * V_10 , int V_21 )
{
struct V_5 * V_6 = F_7 ( V_10 ) ;
F_4 ( V_6 , V_21 ) ;
V_6 -> V_20 = V_21 ;
return 0 ;
}
static int F_10 ( struct V_18 * V_10 )
{
struct V_5 * V_6 = F_7 ( V_10 ) ;
if ( V_6 -> V_16 != V_10 -> V_22 . V_23 ) {
if ( V_6 -> V_20 == V_15 )
F_1 ( V_10 -> V_22 . V_23 ) ;
V_6 -> V_16 = V_10 -> V_22 . V_23 ;
}
if ( V_10 -> V_22 . V_24 != V_6 -> V_20 )
F_9 ( V_10 , V_10 -> V_22 . V_24 ) ;
return 0 ;
}
static int F_11 ( struct V_18 * V_10 )
{
struct V_5 * V_6 = F_7 ( V_10 ) ;
return V_6 -> V_16 ;
}
static int F_12 ( struct V_25 * V_26 )
{
struct V_27 V_22 ;
struct V_18 * V_10 ;
struct V_5 * V_6 ;
struct V_28 * V_8 = F_13 ( & V_26 -> V_10 ) ;
if ( ! V_8 )
return - V_29 ;
V_6 = F_14 ( & V_26 -> V_10 , sizeof( struct V_5 ) ,
V_30 ) ;
if ( F_15 ( ! V_6 ) )
return - V_31 ;
memset ( & V_22 , 0 , sizeof( struct V_27 ) ) ;
V_22 . type = V_32 ;
V_22 . V_33 = V_34 ;
V_10 = F_16 ( L_1 , & V_26 -> V_10 , V_6 , & V_35 ,
& V_22 ) ;
if ( F_17 ( V_10 ) )
return F_18 ( V_10 ) ;
V_6 -> V_20 = V_14 ;
V_6 -> V_16 = 0 ;
V_6 -> V_8 = V_8 ;
V_6 -> V_10 = & V_26 -> V_10 ;
F_19 ( V_26 , V_10 ) ;
F_20 ( V_36 ) ;
V_10 -> V_22 . V_24 = V_15 ;
V_10 -> V_22 . V_23 = V_8 -> V_37 ;
F_10 ( V_10 ) ;
F_21 ( & V_26 -> V_10 , L_2 ) ;
return 0 ;
}
static int F_22 ( struct V_25 * V_26 )
{
struct V_18 * V_10 = F_23 ( V_26 ) ;
F_24 ( V_10 ) ;
return 0 ;
}
