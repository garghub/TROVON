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
struct V_16 * V_17 = F_11 ( V_15 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
T_1 V_18 = V_2 -> V_18 | V_19 ;
F_3 ( V_8 , L_2 ,
& V_17 -> V_20 , & V_17 -> V_21 , V_18 ) ;
F_1 ( V_2 , V_17 -> V_20 , V_22 ) ;
F_1 ( V_2 , V_17 -> V_21 , V_23 ) ;
F_1 ( V_2 , V_18 , V_13 ) ;
}
static int F_12 ( struct V_1 * V_2 , int V_24 ,
T_1 * V_18 , T_2 * V_21 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_25 * V_26 = V_6 -> V_26 ;
struct V_27 * V_28 ;
int V_12 ;
* V_18 = 0 ;
* V_21 = 0 ;
if ( ! V_26 ) {
* V_18 = ( ( T_1 ) V_24 ) << 16 ;
V_2 -> V_10 . V_24 = ( V_24 ) >> 8 ;
return 0 ;
}
if ( V_24 >= V_29 )
return - V_30 ;
for ( V_12 = 0 , V_28 = V_26 -> V_31 ; V_12 < V_26 -> V_32 ; V_12 ++ , V_28 ++ )
if ( V_28 -> V_24 == V_24 ) {
* V_18 = V_28 -> V_18 ;
* V_21 = V_28 -> V_21 ;
return 0 ;
}
return - V_30 ;
}
static int F_13 ( struct V_10 * V_11 , int V_24 ,
T_2 V_33 , bool V_34 )
{
struct V_1 * V_2 = F_8 ( V_11 ) ;
T_1 V_18 ;
T_2 V_21 ;
int V_35 ;
V_35 = F_12 ( V_2 , V_24 , & V_18 , & V_21 ) ;
if ( V_35 < 0 )
return V_35 ;
if ( V_34 )
return 0 ;
V_2 -> V_18 = V_18 ;
V_2 -> V_33 = V_33 ? : V_21 ;
return 0 ;
}
static int F_14 ( struct V_10 * V_11 ,
struct V_14 * V_15 ,
T_2 V_20 , T_2 V_21 , T_3 * V_36 )
{
struct V_16 * V_17 = F_11 ( V_15 ) ;
if ( * V_36 > ( T_3 ) V_37 )
* V_36 = ( T_3 ) V_37 ;
V_17 -> V_20 = V_20 ;
V_17 -> V_21 = V_21 ;
return 0 ;
}
static void F_15 ( struct V_10 * V_11 ,
int V_24 )
{
}
static T_2 F_16 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = F_8 ( V_11 ) ;
return V_2 -> V_33 ;
}
static bool F_17 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = F_8 ( V_11 ) ;
T_1 V_18 = F_5 ( V_2 , V_13 ) ;
return V_18 & ~ V_19 ;
}
static bool F_18 ( struct V_10 * V_11 ,
struct V_14 * V_15 )
{
return true ;
}
static struct V_14 * F_19 ( void * V_38 , int V_12 )
{
return & ( (struct V_16 * ) V_38 ) [ V_12 ] . V_14 ;
}
static int F_20 ( struct V_39 * V_40 ,
struct V_5 * V_6 , int V_41 )
{
struct V_42 * V_43 = & V_6 -> V_42 ;
struct V_1 * V_2 ;
struct V_10 * V_11 ;
struct V_7 * V_8 = V_6 -> V_8 ;
V_2 = F_21 ( V_8 , sizeof( * V_2 ) , V_44 ) ;
if ( ! V_2 )
return - V_45 ;
V_11 = & V_2 -> V_10 ;
V_11 -> V_46 = V_37 ;
F_22 ( V_43 , V_11 , V_41 ) ;
V_2 -> V_9 = V_6 -> V_47 + 0x20 + ( 0x10 * V_41 ) ;
F_3 ( V_8 , L_3 , V_41 , V_2 -> V_9 , V_6 -> V_47 ) ;
return 0 ;
}
static void F_23 ( struct V_5 * V_6 )
{
struct V_10 * V_11 ;
int V_12 ;
F_24 (schan, &audev->shdma_dev, i) {
F_25 ( ! V_11 ) ;
F_26 ( V_11 ) ;
}
}
static struct V_48 * F_27 ( struct V_49 * V_50 ,
struct V_51 * V_52 )
{
T_4 V_53 ;
struct V_48 * V_54 ;
T_1 V_18 = V_50 -> args [ 0 ] ;
if ( V_50 -> V_55 != 1 )
return NULL ;
F_28 ( V_53 ) ;
F_29 ( V_56 , V_53 ) ;
V_54 = F_30 ( V_53 , V_57 , NULL ) ;
if ( V_54 )
F_31 ( V_54 ) -> V_58 = V_18 ;
return V_54 ;
}
static int F_32 ( struct V_39 * V_40 )
{
struct V_25 * V_26 = V_40 -> V_8 . V_59 ;
struct V_60 * V_61 = V_40 -> V_8 . V_62 ;
struct V_5 * V_6 ;
struct V_42 * V_43 ;
struct V_63 * V_64 ;
struct V_65 * V_66 ;
int V_67 , V_12 ;
if ( V_61 )
F_33 ( V_61 , F_27 , V_40 ) ;
else if ( ! V_26 )
return - V_68 ;
V_66 = F_34 ( V_40 , V_69 , 0 ) ;
V_6 = F_21 ( & V_40 -> V_8 , sizeof( * V_6 ) , V_44 ) ;
if ( ! V_6 )
return - V_45 ;
V_6 -> V_8 = & V_40 -> V_8 ;
V_6 -> V_26 = V_26 ;
V_6 -> V_47 = F_35 ( & V_40 -> V_8 , V_66 ) ;
if ( F_36 ( V_6 -> V_47 ) )
return F_37 ( V_6 -> V_47 ) ;
V_43 = & V_6 -> V_42 ;
V_43 -> V_70 = & V_71 ;
V_43 -> V_72 = sizeof( struct V_16 ) ;
V_64 = & V_43 -> V_64 ;
V_64 -> V_73 = V_74 ;
F_29 ( V_56 , V_64 -> V_75 ) ;
V_67 = F_38 ( & V_40 -> V_8 , V_43 , V_76 ) ;
if ( V_67 < 0 )
return V_67 ;
F_39 ( V_40 , V_6 ) ;
for ( V_12 = 0 ; V_12 < V_76 ; V_12 ++ ) {
V_67 = F_20 ( V_40 , V_6 , V_12 ) ;
if ( V_67 )
goto V_77;
}
V_67 = F_40 ( V_64 ) ;
if ( V_67 < 0 )
goto V_77;
return V_67 ;
V_77:
F_23 ( V_6 ) ;
F_41 ( V_43 ) ;
return V_67 ;
}
static int F_42 ( struct V_39 * V_40 )
{
struct V_5 * V_6 = F_43 ( V_40 ) ;
struct V_63 * V_64 = & V_6 -> V_42 . V_64 ;
F_44 ( V_64 ) ;
F_23 ( V_6 ) ;
F_41 ( & V_6 -> V_42 ) ;
return 0 ;
}
