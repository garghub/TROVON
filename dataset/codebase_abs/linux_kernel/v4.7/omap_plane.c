static inline struct V_1 *
F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static int F_3 ( struct V_5 * V_6 ,
const struct V_2 * V_7 )
{
if ( ! V_7 -> V_8 )
return 0 ;
return F_4 ( V_7 -> V_8 ) ;
}
static void F_5 ( struct V_5 * V_6 ,
const struct V_2 * V_9 )
{
if ( V_9 -> V_8 )
F_6 ( V_9 -> V_8 ) ;
}
static void F_7 ( struct V_5 * V_6 ,
struct V_2 * V_9 )
{
struct V_10 * V_10 = F_8 ( V_6 ) ;
struct V_2 * V_3 = V_6 -> V_3 ;
struct V_1 * V_11 = F_1 ( V_3 ) ;
struct V_12 V_13 ;
struct V_14 V_15 ;
int V_16 ;
F_9 ( L_1 , V_10 -> V_17 , V_3 -> V_18 , V_3 -> V_8 ) ;
memset ( & V_13 , 0 , sizeof( V_13 ) ) ;
V_13 . V_19 = V_20 ;
V_13 . V_21 = V_22 ;
V_13 . V_23 = 0xff ;
V_13 . V_24 = 0 ;
V_13 . V_25 = V_11 -> V_25 ;
memset ( & V_15 , 0 , sizeof( V_15 ) ) ;
V_15 . V_21 = V_3 -> V_21 ;
V_15 . V_26 = V_3 -> V_26 ;
V_15 . V_27 = V_3 -> V_27 ;
V_15 . V_28 = V_3 -> V_28 ;
V_15 . V_29 = V_3 -> V_29 ;
V_15 . V_30 = V_3 -> V_30 >> 16 ;
V_15 . V_31 = V_3 -> V_31 >> 16 ;
switch ( V_3 -> V_21 & V_32 ) {
case F_10 ( V_33 ) :
case F_10 ( V_34 ) :
V_15 . V_35 = V_3 -> V_36 >> 16 ;
V_15 . V_36 = V_3 -> V_35 >> 16 ;
break;
default:
V_15 . V_35 = V_3 -> V_35 >> 16 ;
V_15 . V_36 = V_3 -> V_36 >> 16 ;
break;
}
F_11 ( V_3 -> V_8 , & V_15 , & V_13 ) ;
F_9 ( L_2 , V_13 . V_37 , V_13 . V_38 ,
V_13 . V_39 , V_13 . V_40 ,
V_13 . V_41 ) ;
F_9 ( L_3 , V_13 . V_42 , V_13 . V_43 ,
& V_13 . V_44 , & V_13 . V_45 ) ;
F_12 ( V_10 -> V_46 ,
F_13 ( V_3 -> V_18 ) ) ;
V_16 = F_14 ( V_10 -> V_46 , & V_13 , false ,
F_15 ( V_3 -> V_18 ) , false ) ;
if ( F_16 ( V_16 ) ) {
F_17 ( V_10 -> V_46 , false ) ;
return;
}
F_17 ( V_10 -> V_46 , true ) ;
}
static void F_18 ( struct V_5 * V_6 ,
struct V_2 * V_9 )
{
struct V_1 * V_11 = F_1 ( V_6 -> V_3 ) ;
struct V_10 * V_10 = F_8 ( V_6 ) ;
V_6 -> V_3 -> V_21 = F_10 ( V_47 ) ;
V_11 -> V_25 = V_6 -> type == V_48
? 0 : V_10 -> V_46 ;
F_17 ( V_10 -> V_46 , false ) ;
}
static int F_19 ( struct V_5 * V_6 ,
struct V_2 * V_3 )
{
struct V_49 * V_50 ;
if ( ! V_3 -> V_18 )
return 0 ;
V_50 = F_20 ( V_3 -> V_3 , V_3 -> V_18 ) ;
if ( F_21 ( V_50 ) )
return F_22 ( V_50 ) ;
if ( V_3 -> V_26 < 0 || V_3 -> V_27 < 0 )
return - V_51 ;
if ( V_3 -> V_26 + V_3 -> V_28 > V_50 -> V_52 . V_53 )
return - V_51 ;
if ( V_3 -> V_27 + V_3 -> V_29 > V_50 -> V_52 . V_54 )
return - V_51 ;
if ( V_3 -> V_8 ) {
if ( V_3 -> V_21 != F_10 ( V_47 ) &&
! F_23 ( V_3 -> V_8 ) )
return - V_51 ;
}
return 0 ;
}
static void F_24 ( struct V_5 * V_6 )
{
struct V_10 * V_10 = F_8 ( V_6 ) ;
F_9 ( L_4 , V_10 -> V_17 ) ;
F_25 ( V_6 -> V_55 , & V_10 -> V_56 ) ;
F_26 ( V_6 ) ;
F_27 ( V_10 ) ;
}
void F_28 ( struct V_5 * V_6 ,
struct V_57 * V_58 )
{
struct V_59 * V_55 = V_6 -> V_55 ;
struct V_60 * V_61 = V_55 -> V_62 ;
if ( V_61 -> V_63 ) {
struct V_64 * V_65 = V_55 -> V_66 . V_67 ;
F_29 ( V_58 , V_65 , 0 ) ;
}
F_29 ( V_58 , V_61 -> V_68 , 0 ) ;
}
static struct V_2 *
F_30 ( struct V_5 * V_6 )
{
struct V_1 * V_3 ;
struct V_1 * V_69 ;
if ( F_16 ( ! V_6 -> V_3 ) )
return NULL ;
V_3 = F_1 ( V_6 -> V_3 ) ;
V_69 = F_31 ( V_3 , sizeof( * V_3 ) , V_70 ) ;
if ( V_69 == NULL )
return NULL ;
F_32 ( V_6 , & V_69 -> V_4 ) ;
return & V_69 -> V_4 ;
}
static void F_33 ( struct V_5 * V_6 ,
struct V_2 * V_3 )
{
F_34 ( V_3 ) ;
F_27 ( F_1 ( V_3 ) ) ;
}
static void F_35 ( struct V_5 * V_6 )
{
struct V_10 * V_10 = F_8 ( V_6 ) ;
struct V_1 * V_11 ;
if ( V_6 -> V_3 ) {
F_33 ( V_6 , V_6 -> V_3 ) ;
V_6 -> V_3 = NULL ;
}
V_11 = F_36 ( sizeof( * V_11 ) , V_70 ) ;
if ( V_11 == NULL )
return;
V_11 -> V_25 = V_6 -> type == V_48
? 0 : V_10 -> V_46 ;
V_11 -> V_4 . V_21 = F_10 ( V_47 ) ;
V_6 -> V_3 = & V_11 -> V_4 ;
V_6 -> V_3 -> V_6 = V_6 ;
}
static int F_37 ( struct V_5 * V_6 ,
struct V_2 * V_3 ,
struct V_64 * V_71 ,
T_1 V_72 )
{
struct V_60 * V_61 = V_6 -> V_55 -> V_62 ;
struct V_1 * V_11 = F_1 ( V_3 ) ;
if ( V_71 == V_61 -> V_68 )
V_11 -> V_25 = V_72 ;
else
return - V_51 ;
return 0 ;
}
static int F_38 ( struct V_5 * V_6 ,
const struct V_2 * V_3 ,
struct V_64 * V_71 ,
T_1 * V_72 )
{
struct V_60 * V_61 = V_6 -> V_55 -> V_62 ;
const struct V_1 * V_11 =
F_2 ( V_3 , const struct V_1 , V_4 ) ;
if ( V_71 == V_61 -> V_68 )
* V_72 = V_11 -> V_25 ;
else
return - V_51 ;
return 0 ;
}
static void F_39 ( struct V_73 * V_74 , T_2 V_75 )
{
struct V_10 * V_10 =
F_2 ( V_74 , struct V_10 , V_56 ) ;
F_40 ( L_5 , V_10 -> V_17 ,
V_75 ) ;
}
struct V_5 * F_41 ( struct V_59 * V_55 ,
int V_46 , enum V_76 type )
{
struct V_60 * V_61 = V_55 -> V_62 ;
struct V_5 * V_6 ;
struct V_10 * V_10 ;
int V_16 ;
F_9 ( L_6 , V_77 [ V_46 ] , type ) ;
V_10 = F_36 ( sizeof( * V_10 ) , V_70 ) ;
if ( ! V_10 )
return F_42 ( - V_78 ) ;
V_10 -> V_79 = F_43 (
V_10 -> V_80 , F_44 ( V_10 -> V_80 ) ,
F_45 ( V_46 ) ) ;
V_10 -> V_46 = V_46 ;
V_10 -> V_17 = V_77 [ V_46 ] ;
V_6 = & V_10 -> V_4 ;
V_10 -> V_56 . V_81 = V_82 [ V_46 ] ;
V_10 -> V_56 . V_74 = F_39 ;
F_46 ( V_55 , & V_10 -> V_56 ) ;
V_16 = F_47 ( V_55 , V_6 , ( 1 << V_61 -> V_83 ) - 1 ,
& V_84 , V_10 -> V_80 ,
V_10 -> V_79 , type , NULL ) ;
if ( V_16 < 0 )
goto error;
F_48 ( V_6 , & V_85 ) ;
F_28 ( V_6 , & V_6 -> V_4 ) ;
return V_6 ;
error:
F_25 ( V_6 -> V_55 , & V_10 -> V_56 ) ;
F_27 ( V_10 ) ;
return NULL ;
}
