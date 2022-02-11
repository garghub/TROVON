static void F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
F_3 ( V_8 , L_1 , V_2 -> V_9 + V_4 , V_3 ) ;
F_4 ( V_3 , V_2 -> V_9 + V_4 ) ;
}
static T_1 F_5 ( struct V_1 * V_2 , T_1 V_4 )
{
return F_6 ( V_2 -> V_9 + V_4 ) ;
}
static void F_7 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = F_8 ( V_11 ) ;
int V_12 ;
F_1 ( V_2 , 0 , V_13 ) ;
for ( V_12 = 0 ; V_12 < 1024 ; V_12 ++ ) {
if ( 0 == F_5 ( V_2 , V_13 ) )
return;
F_9 ( 1 ) ;
}
}
static void F_10 ( struct V_10 * V_11 ,
struct V_14 * V_15 )
{
struct V_1 * V_2 = F_8 ( V_11 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_16 * V_17 = V_2 -> V_18 ;
struct V_7 * V_8 = V_6 -> V_8 ;
T_1 V_19 = V_17 -> V_19 | V_20 ;
F_3 ( V_8 , L_2 ,
& V_17 -> V_21 , & V_17 -> V_22 , V_17 -> V_19 ) ;
F_1 ( V_2 , V_17 -> V_21 , V_23 ) ;
F_1 ( V_2 , V_17 -> V_22 , V_24 ) ;
F_1 ( V_2 , V_19 , V_13 ) ;
}
static struct V_16 *
F_11 ( struct V_1 * V_2 , int V_25 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_26 * V_27 = V_6 -> V_27 ;
struct V_16 * V_17 ;
int V_12 ;
if ( V_25 >= V_28 )
return NULL ;
for ( V_12 = 0 , V_17 = V_27 -> V_29 ; V_12 < V_27 -> V_30 ; V_12 ++ , V_17 ++ )
if ( V_17 -> V_25 == V_25 )
return V_17 ;
return NULL ;
}
static int F_12 ( struct V_10 * V_11 , int V_25 ,
T_2 V_31 , bool V_32 )
{
struct V_1 * V_2 = F_8 ( V_11 ) ;
struct V_16 * V_17 =
F_11 ( V_2 , V_25 ) ;
if ( ! V_17 )
return - V_33 ;
if ( V_32 )
return 0 ;
V_2 -> V_18 = V_17 ;
return 0 ;
}
static int F_13 ( struct V_10 * V_11 ,
struct V_14 * V_15 ,
T_2 V_21 , T_2 V_22 , T_3 * V_34 )
{
struct V_1 * V_2 = F_8 ( V_11 ) ;
struct V_16 * V_17 = V_2 -> V_18 ;
if ( ! V_17 )
return - V_33 ;
if ( * V_34 > ( T_3 ) V_35 )
* V_34 = ( T_3 ) V_35 ;
return 0 ;
}
static void F_14 ( struct V_10 * V_11 ,
int V_25 )
{
}
static T_2 F_15 ( struct V_10 * V_11 )
{
return 0 ;
}
static bool F_16 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = F_8 ( V_11 ) ;
T_1 V_19 = F_5 ( V_2 , V_13 ) ;
return V_19 & ~ V_20 ;
}
static bool F_17 ( struct V_10 * V_11 ,
struct V_14 * V_36 )
{
return true ;
}
static struct V_14 * F_18 ( void * V_37 , int V_12 )
{
return & ( (struct V_14 * ) V_37 ) [ V_12 ] ;
}
static int F_19 ( struct V_38 * V_39 ,
struct V_5 * V_6 , int V_40 )
{
struct V_41 * V_42 = & V_6 -> V_41 ;
struct V_1 * V_2 ;
struct V_10 * V_11 ;
struct V_7 * V_8 = V_6 -> V_8 ;
V_2 = F_20 ( V_8 , sizeof( * V_2 ) , V_43 ) ;
if ( ! V_2 )
return - V_44 ;
V_11 = & V_2 -> V_10 ;
V_11 -> V_45 = V_35 ;
F_21 ( V_42 , V_11 , V_40 ) ;
V_2 -> V_9 = V_6 -> V_46 + 0x20 + ( 0x10 * V_40 ) ;
F_3 ( V_8 , L_3 , V_40 , V_2 -> V_9 , V_6 -> V_46 ) ;
return 0 ;
}
static void F_22 ( struct V_5 * V_6 )
{
struct V_47 * V_48 = & V_6 -> V_41 . V_48 ;
struct V_10 * V_11 ;
int V_12 ;
F_23 (schan, &audev->shdma_dev, i) {
F_24 ( ! V_11 ) ;
F_25 ( V_11 ) ;
}
V_48 -> V_49 = 0 ;
}
static int F_26 ( struct V_38 * V_39 )
{
struct V_26 * V_27 = V_39 -> V_8 . V_50 ;
struct V_5 * V_6 ;
struct V_41 * V_42 ;
struct V_47 * V_48 ;
struct V_51 * V_52 ;
int V_53 , V_12 ;
if ( ! V_27 )
return - V_33 ;
V_52 = F_27 ( V_39 , V_54 , 0 ) ;
V_6 = F_20 ( & V_39 -> V_8 , sizeof( * V_6 ) , V_43 ) ;
if ( ! V_6 )
return - V_44 ;
V_6 -> V_8 = & V_39 -> V_8 ;
V_6 -> V_27 = V_27 ;
V_6 -> V_46 = F_28 ( & V_39 -> V_8 , V_52 ) ;
if ( F_29 ( V_6 -> V_46 ) )
return F_30 ( V_6 -> V_46 ) ;
V_42 = & V_6 -> V_41 ;
V_42 -> V_55 = & V_56 ;
V_42 -> V_57 = sizeof( struct V_14 ) ;
V_48 = & V_42 -> V_48 ;
V_48 -> V_58 = V_59 ;
F_31 ( V_60 , V_48 -> V_61 ) ;
V_53 = F_32 ( & V_39 -> V_8 , V_42 , V_62 ) ;
if ( V_53 < 0 )
return V_53 ;
F_33 ( V_39 , V_6 ) ;
for ( V_12 = 0 ; V_12 < V_62 ; V_12 ++ ) {
V_53 = F_19 ( V_39 , V_6 , V_12 ) ;
if ( V_53 )
goto V_63;
}
V_53 = F_34 ( V_48 ) ;
if ( V_53 < 0 )
goto V_63;
return V_53 ;
V_63:
F_22 ( V_6 ) ;
F_35 ( V_42 ) ;
return V_53 ;
}
static int F_36 ( struct V_38 * V_39 )
{
struct V_5 * V_6 = F_37 ( V_39 ) ;
struct V_47 * V_48 = & V_6 -> V_41 . V_48 ;
F_38 ( V_48 ) ;
F_22 ( V_6 ) ;
F_35 ( & V_6 -> V_41 ) ;
return 0 ;
}
