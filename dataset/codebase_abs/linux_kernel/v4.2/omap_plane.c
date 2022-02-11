static inline struct V_1 *
F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static int F_3 ( struct V_5 * V_6 ,
struct V_7 * V_8 ,
const struct V_2 * V_9 )
{
return F_4 ( V_8 ) ;
}
static void F_5 ( struct V_5 * V_6 ,
struct V_7 * V_8 ,
const struct V_2 * V_10 )
{
F_6 ( V_8 ) ;
}
static void F_7 ( struct V_5 * V_6 ,
struct V_2 * V_10 )
{
struct V_11 * V_11 = F_8 ( V_6 ) ;
struct V_2 * V_3 = V_6 -> V_3 ;
struct V_1 * V_12 = F_1 ( V_3 ) ;
struct V_13 V_14 ;
struct V_15 V_16 ;
int V_17 ;
F_9 ( L_1 , V_11 -> V_18 , V_3 -> V_19 , V_3 -> V_8 ) ;
memset ( & V_14 , 0 , sizeof( V_14 ) ) ;
V_14 . V_20 = V_21 ;
V_14 . V_22 = V_23 ;
V_14 . V_24 = 0xff ;
V_14 . V_25 = 0 ;
V_14 . V_26 = V_12 -> V_26 ;
memset ( & V_16 , 0 , sizeof( V_16 ) ) ;
V_16 . V_22 = V_3 -> V_22 ;
V_16 . V_27 = V_3 -> V_27 ;
V_16 . V_28 = V_3 -> V_28 ;
V_16 . V_29 = V_3 -> V_29 ;
V_16 . V_30 = V_3 -> V_30 ;
V_16 . V_31 = V_3 -> V_31 >> 16 ;
V_16 . V_32 = V_3 -> V_32 >> 16 ;
switch ( V_3 -> V_22 & 0xf ) {
case F_10 ( V_33 ) :
case F_10 ( V_34 ) :
V_16 . V_35 = V_3 -> V_36 >> 16 ;
V_16 . V_36 = V_3 -> V_35 >> 16 ;
break;
default:
V_16 . V_35 = V_3 -> V_35 >> 16 ;
V_16 . V_36 = V_3 -> V_36 >> 16 ;
break;
}
F_11 ( V_3 -> V_8 , & V_16 , & V_14 ) ;
F_9 ( L_2 , V_14 . V_37 , V_14 . V_38 ,
V_14 . V_39 , V_14 . V_40 ,
V_14 . V_41 ) ;
F_9 ( L_3 , V_14 . V_42 , V_14 . V_43 ,
& V_14 . V_44 , & V_14 . V_45 ) ;
F_12 ( V_11 -> V_46 ,
F_13 ( V_3 -> V_19 ) ) ;
V_17 = F_14 ( V_11 -> V_46 , & V_14 , false ,
F_15 ( V_3 -> V_19 ) , false ) ;
if ( F_16 ( V_17 ) ) {
F_17 ( V_11 -> V_46 , false ) ;
return;
}
F_17 ( V_11 -> V_46 , true ) ;
}
static void F_18 ( struct V_5 * V_6 ,
struct V_2 * V_10 )
{
struct V_1 * V_12 = F_1 ( V_6 -> V_3 ) ;
struct V_11 * V_11 = F_8 ( V_6 ) ;
V_6 -> V_3 -> V_22 = F_10 ( V_47 ) ;
V_12 -> V_26 = V_6 -> type == V_48
? 0 : V_11 -> V_46 ;
F_17 ( V_11 -> V_46 , false ) ;
}
static int F_19 ( struct V_5 * V_6 ,
struct V_2 * V_3 )
{
struct V_49 * V_50 ;
if ( ! V_3 -> V_19 )
return 0 ;
V_50 = F_20 ( V_3 -> V_3 , V_3 -> V_19 ) ;
if ( F_21 ( V_50 ) )
return F_22 ( V_50 ) ;
if ( V_3 -> V_27 < 0 || V_3 -> V_28 < 0 )
return - V_51 ;
if ( V_3 -> V_27 + V_3 -> V_29 > V_50 -> V_52 . V_53 )
return - V_51 ;
if ( V_3 -> V_28 + V_3 -> V_30 > V_50 -> V_52 . V_54 )
return - V_51 ;
return 0 ;
}
static void F_23 ( struct V_5 * V_6 )
{
struct V_11 * V_11 = F_8 ( V_6 ) ;
struct V_1 * V_12 ;
if ( V_6 -> V_3 && V_6 -> V_3 -> V_8 )
F_24 ( V_6 -> V_3 -> V_8 ) ;
F_25 ( V_6 -> V_3 ) ;
V_6 -> V_3 = NULL ;
V_12 = F_26 ( sizeof( * V_12 ) , V_55 ) ;
if ( V_12 == NULL )
return;
V_12 -> V_26 = V_6 -> type == V_48
? 0 : V_11 -> V_46 ;
V_12 -> V_4 . V_22 = F_10 ( V_47 ) ;
V_6 -> V_3 = & V_12 -> V_4 ;
V_6 -> V_3 -> V_6 = V_6 ;
}
static void F_27 ( struct V_5 * V_6 )
{
struct V_11 * V_11 = F_8 ( V_6 ) ;
F_9 ( L_4 , V_11 -> V_18 ) ;
F_28 ( V_6 -> V_56 , & V_11 -> V_57 ) ;
F_29 ( V_6 ) ;
F_25 ( V_11 ) ;
}
void F_30 ( struct V_5 * V_6 ,
struct V_58 * V_59 )
{
struct V_60 * V_56 = V_6 -> V_56 ;
struct V_61 * V_62 = V_56 -> V_63 ;
if ( V_62 -> V_64 ) {
struct V_65 * V_66 = V_56 -> V_67 . V_68 ;
F_31 ( V_59 , V_66 , 0 ) ;
}
F_31 ( V_59 , V_62 -> V_69 , 0 ) ;
}
static struct V_2 *
F_32 ( struct V_5 * V_6 )
{
struct V_1 * V_3 ;
struct V_1 * V_70 ;
if ( F_16 ( ! V_6 -> V_3 ) )
return NULL ;
V_3 = F_1 ( V_6 -> V_3 ) ;
V_70 = F_33 ( V_3 , sizeof( * V_3 ) , V_55 ) ;
if ( V_70 == NULL )
return NULL ;
F_34 ( V_6 , & V_70 -> V_4 ) ;
return & V_70 -> V_4 ;
}
static void F_35 ( struct V_5 * V_6 ,
struct V_2 * V_3 )
{
F_36 ( V_6 , V_3 ) ;
F_25 ( F_1 ( V_3 ) ) ;
}
static int F_37 ( struct V_5 * V_6 ,
struct V_2 * V_3 ,
struct V_65 * V_71 ,
T_1 V_72 )
{
struct V_61 * V_62 = V_6 -> V_56 -> V_63 ;
struct V_1 * V_12 = F_1 ( V_3 ) ;
if ( V_71 == V_62 -> V_69 )
V_12 -> V_26 = V_72 ;
else
return - V_51 ;
return 0 ;
}
static int F_38 ( struct V_5 * V_6 ,
const struct V_2 * V_3 ,
struct V_65 * V_71 ,
T_1 * V_72 )
{
struct V_61 * V_62 = V_6 -> V_56 -> V_63 ;
const struct V_1 * V_12 =
F_2 ( V_3 , const struct V_1 , V_4 ) ;
if ( V_71 == V_62 -> V_69 )
* V_72 = V_12 -> V_26 ;
else
return - V_51 ;
return 0 ;
}
static void F_39 ( struct V_73 * V_74 , T_2 V_75 )
{
struct V_11 * V_11 =
F_2 ( V_74 , struct V_11 , V_57 ) ;
F_40 ( L_5 , V_11 -> V_18 ,
V_75 ) ;
}
struct V_5 * F_41 ( struct V_60 * V_56 ,
int V_46 , enum V_76 type )
{
struct V_61 * V_62 = V_56 -> V_63 ;
struct V_5 * V_6 ;
struct V_11 * V_11 ;
int V_17 ;
F_9 ( L_6 , V_77 [ V_46 ] , type ) ;
V_11 = F_26 ( sizeof( * V_11 ) , V_55 ) ;
if ( ! V_11 )
return F_42 ( - V_78 ) ;
V_11 -> V_79 = F_43 (
V_11 -> V_80 , F_44 ( V_11 -> V_80 ) ,
F_45 ( V_46 ) ) ;
V_11 -> V_46 = V_46 ;
V_11 -> V_18 = V_77 [ V_46 ] ;
V_6 = & V_11 -> V_4 ;
V_11 -> V_57 . V_81 = V_82 [ V_46 ] ;
V_11 -> V_57 . V_74 = F_39 ;
F_46 ( V_56 , & V_11 -> V_57 ) ;
V_17 = F_47 ( V_56 , V_6 , ( 1 << V_62 -> V_83 ) - 1 ,
& V_84 , V_11 -> V_80 ,
V_11 -> V_79 , type ) ;
if ( V_17 < 0 )
goto error;
F_48 ( V_6 , & V_85 ) ;
F_30 ( V_6 , & V_6 -> V_4 ) ;
return V_6 ;
error:
F_28 ( V_6 -> V_56 , & V_11 -> V_57 ) ;
F_25 ( V_11 ) ;
return NULL ;
}
