static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_2 ( V_2 , & V_2 -> V_5 ) ;
return 0 ;
}
static int F_3 ( struct V_1 * V_2 )
{
F_2 ( V_2 , NULL ) ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_9 * V_10 = (struct V_9 * )
F_5 ( V_7 -> V_11 , V_2 ) ;
int V_12 ;
V_12 = F_6 ( V_2 , & V_13 ) ;
if ( V_12 )
return V_12 ;
return F_7 ( V_2 , V_10 -> V_14 ,
V_10 ) ;
}
static int F_8 ( struct V_1 * V_2 ,
struct V_15 * V_16 )
{
struct V_17 * V_18 = V_2 -> V_18 ;
return F_9 ( V_2 -> V_19 -> V_20 -> V_21 , V_16 ,
V_18 -> V_22 , V_18 -> V_23 ,
V_18 -> V_24 ) ;
}
static int
F_10 ( struct V_25 * V_19 , int V_26 ,
T_1 V_27 )
{
struct V_1 * V_2 = V_19 -> V_28 [ V_26 ] . V_2 ;
struct V_29 * V_30 = & V_2 -> V_5 ;
V_30 -> V_21 . type = V_31 ;
V_30 -> V_21 . V_21 = V_19 -> V_20 -> V_21 ;
V_30 -> V_8 = NULL ;
V_30 -> V_32 = F_11 ( V_19 -> V_20 -> V_21 , V_27 ,
& V_30 -> V_33 , V_34 ) ;
if ( ! V_30 -> V_32 )
return - V_35 ;
F_12 ( V_30 -> V_21 . V_21 ,
L_1 ,
( void * ) V_30 -> V_32 , ( void * ) V_30 -> V_33 , V_27 ) ;
V_30 -> V_36 = V_27 ;
return 0 ;
}
static void F_13 ( struct V_25 * V_19 )
{
struct V_1 * V_2 ;
struct V_29 * V_30 ;
int V_26 ;
for ( V_26 = 0 ; V_26 < 2 ; V_26 ++ ) {
V_2 = V_19 -> V_28 [ V_26 ] . V_2 ;
if ( ! V_2 )
continue;
V_30 = & V_2 -> V_5 ;
if ( ! V_30 || ! V_30 -> V_32 )
continue;
F_14 ( V_19 -> V_20 -> V_21 , V_30 -> V_36 ,
V_30 -> V_32 , V_30 -> V_33 ) ;
V_30 -> V_32 = NULL ;
}
}
static int F_15 ( struct V_6 * V_7 )
{
struct V_37 * V_20 = V_7 -> V_20 -> V_37 ;
int V_12 ;
if ( ! V_20 -> V_21 -> V_38 )
V_20 -> V_21 -> V_38 = & V_39 ;
if ( ! V_20 -> V_21 -> V_40 )
V_20 -> V_21 -> V_40 = F_16 ( 32 ) ;
if ( V_7 -> V_11 -> V_41 -> V_42 . V_43 ) {
V_12 = F_10 ( V_7 -> V_19 ,
V_44 ,
V_13 . V_45 ) ;
if ( V_12 )
return V_12 ;
}
if ( V_7 -> V_11 -> V_41 -> V_46 . V_43 ) {
V_12 = F_10 ( V_7 -> V_19 ,
V_47 ,
V_13 . V_45 ) ;
if ( V_12 )
return V_12 ;
}
return 0 ;
}
static int F_17 ( struct V_48 * V_49 )
{
return F_18 ( & V_49 -> V_21 , & V_50 ) ;
}
static int F_19 ( struct V_48 * V_49 )
{
F_20 ( & V_49 -> V_21 ) ;
return 0 ;
}
