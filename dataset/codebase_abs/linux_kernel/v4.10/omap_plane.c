static inline struct V_1 *
F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static int F_3 ( struct V_5 * V_6 ,
struct V_2 * V_7 )
{
if ( ! V_7 -> V_8 )
return 0 ;
return F_4 ( V_7 -> V_8 ) ;
}
static void F_5 ( struct V_5 * V_6 ,
struct V_2 * V_9 )
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
if ( F_10 ( V_3 -> V_21 ) ) {
V_15 . V_32 = V_3 -> V_33 >> 16 ;
V_15 . V_33 = V_3 -> V_32 >> 16 ;
} else {
V_15 . V_32 = V_3 -> V_32 >> 16 ;
V_15 . V_33 = V_3 -> V_33 >> 16 ;
}
F_11 ( V_3 -> V_8 , & V_15 , & V_13 ) ;
F_9 ( L_2 , V_13 . V_34 , V_13 . V_35 ,
V_13 . V_36 , V_13 . V_37 ,
V_13 . V_38 ) ;
F_9 ( L_3 , V_13 . V_39 , V_13 . V_40 ,
& V_13 . V_41 , & V_13 . V_42 ) ;
F_12 ( V_10 -> V_43 ,
F_13 ( V_3 -> V_18 ) ) ;
V_16 = F_14 ( V_10 -> V_43 , & V_13 , false ,
F_15 ( V_3 -> V_18 ) , false ) ;
if ( V_16 ) {
F_16 ( V_6 -> V_44 -> V_44 , L_4 ,
V_10 -> V_17 ) ;
F_17 ( V_10 -> V_43 , false ) ;
return;
}
F_17 ( V_10 -> V_43 , true ) ;
}
static void F_18 ( struct V_5 * V_6 ,
struct V_2 * V_9 )
{
struct V_1 * V_11 = F_1 ( V_6 -> V_3 ) ;
struct V_10 * V_10 = F_8 ( V_6 ) ;
V_6 -> V_3 -> V_21 = V_45 ;
V_11 -> V_25 = V_6 -> type == V_46
? 0 : V_10 -> V_43 ;
F_17 ( V_10 -> V_43 , false ) ;
}
static int F_19 ( struct V_5 * V_6 ,
struct V_2 * V_3 )
{
struct V_47 * V_48 ;
if ( ! V_3 -> V_8 )
return 0 ;
if ( F_20 ( ! V_3 -> V_18 ) )
return 0 ;
V_48 = F_21 ( V_3 -> V_3 , V_3 -> V_18 ) ;
if ( F_20 ( ! V_48 ) )
return 0 ;
if ( ! V_48 -> V_49 )
return 0 ;
if ( V_3 -> V_26 < 0 || V_3 -> V_27 < 0 )
return - V_50 ;
if ( V_3 -> V_26 + V_3 -> V_28 > V_48 -> V_51 . V_52 )
return - V_50 ;
if ( V_3 -> V_27 + V_3 -> V_29 > V_48 -> V_51 . V_53 )
return - V_50 ;
if ( V_3 -> V_21 != V_45 &&
! F_22 ( V_3 -> V_8 ) )
return - V_50 ;
return 0 ;
}
static void F_23 ( struct V_5 * V_6 )
{
struct V_10 * V_10 = F_8 ( V_6 ) ;
F_9 ( L_5 , V_10 -> V_17 ) ;
F_24 ( V_6 -> V_44 , & V_10 -> V_54 ) ;
F_25 ( V_6 ) ;
F_26 ( V_10 ) ;
}
void F_27 ( struct V_5 * V_6 ,
struct V_55 * V_56 )
{
struct V_57 * V_44 = V_6 -> V_44 ;
struct V_58 * V_59 = V_44 -> V_60 ;
if ( V_59 -> V_61 ) {
if ( ! V_6 -> V_62 )
F_28 ( V_6 ,
V_45 ,
V_45 | V_63 |
V_64 | V_65 |
V_66 | V_67 ) ;
if ( V_6 -> V_62 && V_56 != & V_6 -> V_4 )
F_29 ( V_56 , V_6 -> V_62 ,
V_45 ) ;
}
F_29 ( V_56 , V_59 -> V_68 , 0 ) ;
}
static struct V_2 *
F_30 ( struct V_5 * V_6 )
{
struct V_1 * V_3 ;
struct V_1 * V_69 ;
if ( F_20 ( ! V_6 -> V_3 ) )
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
F_26 ( F_1 ( V_3 ) ) ;
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
V_11 -> V_25 = V_6 -> type == V_46
? 0 : V_10 -> V_43 ;
V_11 -> V_4 . V_21 = V_45 ;
V_6 -> V_3 = & V_11 -> V_4 ;
V_6 -> V_3 -> V_6 = V_6 ;
}
static int F_37 ( struct V_5 * V_6 ,
struct V_2 * V_3 ,
struct V_71 * V_72 ,
T_1 V_73 )
{
struct V_58 * V_59 = V_6 -> V_44 -> V_60 ;
struct V_1 * V_11 = F_1 ( V_3 ) ;
if ( V_72 == V_59 -> V_68 )
V_11 -> V_25 = V_73 ;
else
return - V_50 ;
return 0 ;
}
static int F_38 ( struct V_5 * V_6 ,
const struct V_2 * V_3 ,
struct V_71 * V_72 ,
T_1 * V_73 )
{
struct V_58 * V_59 = V_6 -> V_44 -> V_60 ;
const struct V_1 * V_11 =
F_2 ( V_3 , const struct V_1 , V_4 ) ;
if ( V_72 == V_59 -> V_68 )
* V_73 = V_11 -> V_25 ;
else
return - V_50 ;
return 0 ;
}
static void F_39 ( struct V_74 * V_75 , T_2 V_76 )
{
struct V_10 * V_10 =
F_2 ( V_75 , struct V_10 , V_54 ) ;
F_40 ( L_6 , V_10 -> V_17 ,
V_76 ) ;
}
struct V_5 * F_41 ( struct V_57 * V_44 ,
int V_43 , enum V_77 type ,
T_3 V_78 )
{
struct V_5 * V_6 ;
struct V_10 * V_10 ;
int V_16 ;
F_9 ( L_7 , V_79 [ V_43 ] , type ) ;
V_10 = F_36 ( sizeof( * V_10 ) , V_70 ) ;
if ( ! V_10 )
return F_42 ( - V_80 ) ;
V_10 -> V_81 = F_43 (
V_10 -> V_82 , F_44 ( V_10 -> V_82 ) ,
F_45 ( V_43 ) ) ;
V_10 -> V_43 = V_43 ;
V_10 -> V_17 = V_79 [ V_43 ] ;
V_6 = & V_10 -> V_4 ;
V_10 -> V_54 . V_83 = V_84 [ V_43 ] ;
V_10 -> V_54 . V_75 = F_39 ;
F_46 ( V_44 , & V_10 -> V_54 ) ;
V_16 = F_47 ( V_44 , V_6 , V_78 ,
& V_85 , V_10 -> V_82 ,
V_10 -> V_81 , type , NULL ) ;
if ( V_16 < 0 )
goto error;
F_48 ( V_6 , & V_86 ) ;
F_27 ( V_6 , & V_6 -> V_4 ) ;
return V_6 ;
error:
F_24 ( V_6 -> V_44 , & V_10 -> V_54 ) ;
F_26 ( V_10 ) ;
return NULL ;
}
