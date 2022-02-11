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
static void F_12 ( struct V_1 * V_2 , int V_24 ,
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
return;
}
if ( V_24 >= V_29 )
return;
for ( V_12 = 0 , V_28 = V_26 -> V_30 ; V_12 < V_26 -> V_31 ; V_12 ++ , V_28 ++ )
if ( V_28 -> V_24 == V_24 ) {
* V_18 = V_28 -> V_18 ;
* V_21 = V_28 -> V_21 ;
break;
}
}
static int F_13 ( struct V_10 * V_11 , int V_24 ,
T_2 V_32 , bool V_33 )
{
struct V_1 * V_2 = F_8 ( V_11 ) ;
T_1 V_18 ;
T_2 V_21 ;
F_12 ( V_2 , V_24 , & V_18 , & V_21 ) ;
if ( V_33 )
return 0 ;
V_2 -> V_18 = V_18 ;
V_2 -> V_32 = V_32 ? : V_21 ;
return 0 ;
}
static int F_14 ( struct V_10 * V_11 ,
struct V_14 * V_15 ,
T_2 V_20 , T_2 V_21 , T_3 * V_34 )
{
struct V_16 * V_17 = F_11 ( V_15 ) ;
if ( * V_34 > ( T_3 ) V_35 )
* V_34 = ( T_3 ) V_35 ;
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
return V_2 -> V_32 ;
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
static struct V_14 * F_19 ( void * V_36 , int V_12 )
{
return & ( (struct V_16 * ) V_36 ) [ V_12 ] . V_14 ;
}
static int F_20 ( struct V_37 * V_38 ,
struct V_5 * V_6 , int V_39 )
{
struct V_40 * V_41 = & V_6 -> V_40 ;
struct V_1 * V_2 ;
struct V_10 * V_11 ;
struct V_7 * V_8 = V_6 -> V_8 ;
V_2 = F_21 ( V_8 , sizeof( * V_2 ) , V_42 ) ;
if ( ! V_2 )
return - V_43 ;
V_11 = & V_2 -> V_10 ;
V_11 -> V_44 = V_35 ;
F_22 ( V_41 , V_11 , V_39 ) ;
V_2 -> V_9 = V_6 -> V_45 + 0x20 + ( 0x10 * V_39 ) ;
F_3 ( V_8 , L_3 , V_39 , V_2 -> V_9 , V_6 -> V_45 ) ;
return 0 ;
}
static void F_23 ( struct V_5 * V_6 )
{
struct V_46 * V_47 = & V_6 -> V_40 . V_47 ;
struct V_10 * V_11 ;
int V_12 ;
F_24 (schan, &audev->shdma_dev, i) {
F_25 ( ! V_11 ) ;
F_26 ( V_11 ) ;
}
V_47 -> V_48 = 0 ;
}
static struct V_49 * F_27 ( struct V_50 * V_51 ,
struct V_52 * V_53 )
{
T_4 V_54 ;
struct V_49 * V_55 ;
T_1 V_18 = V_51 -> args [ 0 ] ;
if ( V_51 -> V_56 != 1 )
return NULL ;
F_28 ( V_54 ) ;
F_29 ( V_57 , V_54 ) ;
V_55 = F_30 ( V_54 , V_58 , NULL ) ;
if ( V_55 )
F_31 ( V_55 ) -> V_59 = V_18 ;
return V_55 ;
}
static int F_32 ( struct V_37 * V_38 )
{
struct V_25 * V_26 = V_38 -> V_8 . V_60 ;
struct V_61 * V_62 = V_38 -> V_8 . V_63 ;
struct V_5 * V_6 ;
struct V_40 * V_41 ;
struct V_46 * V_47 ;
struct V_64 * V_65 ;
int V_66 , V_12 ;
if ( V_62 )
F_33 ( V_62 , F_27 , V_38 ) ;
else if ( ! V_26 )
return - V_67 ;
V_65 = F_34 ( V_38 , V_68 , 0 ) ;
V_6 = F_21 ( & V_38 -> V_8 , sizeof( * V_6 ) , V_42 ) ;
if ( ! V_6 )
return - V_43 ;
V_6 -> V_8 = & V_38 -> V_8 ;
V_6 -> V_26 = V_26 ;
V_6 -> V_45 = F_35 ( & V_38 -> V_8 , V_65 ) ;
if ( F_36 ( V_6 -> V_45 ) )
return F_37 ( V_6 -> V_45 ) ;
V_41 = & V_6 -> V_40 ;
V_41 -> V_69 = & V_70 ;
V_41 -> V_71 = sizeof( struct V_16 ) ;
V_47 = & V_41 -> V_47 ;
V_47 -> V_72 = V_73 ;
F_29 ( V_57 , V_47 -> V_74 ) ;
V_66 = F_38 ( & V_38 -> V_8 , V_41 , V_75 ) ;
if ( V_66 < 0 )
return V_66 ;
F_39 ( V_38 , V_6 ) ;
for ( V_12 = 0 ; V_12 < V_75 ; V_12 ++ ) {
V_66 = F_20 ( V_38 , V_6 , V_12 ) ;
if ( V_66 )
goto V_76;
}
V_66 = F_40 ( V_47 ) ;
if ( V_66 < 0 )
goto V_76;
return V_66 ;
V_76:
F_23 ( V_6 ) ;
F_41 ( V_41 ) ;
return V_66 ;
}
static int F_42 ( struct V_37 * V_38 )
{
struct V_5 * V_6 = F_43 ( V_38 ) ;
struct V_46 * V_47 = & V_6 -> V_40 . V_47 ;
F_44 ( V_47 ) ;
F_23 ( V_6 ) ;
F_41 ( & V_6 -> V_40 ) ;
return 0 ;
}
