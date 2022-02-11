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
struct V_10 * V_11 = V_6 -> V_12 -> V_13 ;
struct V_14 * V_14 = F_8 ( V_6 ) ;
struct V_2 * V_3 = V_6 -> V_3 ;
struct V_1 * V_15 = F_1 ( V_3 ) ;
struct V_16 V_17 ;
struct V_18 V_19 ;
int V_20 ;
F_9 ( L_1 , V_14 -> V_21 , V_3 -> V_22 , V_3 -> V_8 ) ;
memset ( & V_17 , 0 , sizeof( V_17 ) ) ;
V_17 . V_23 = V_24 ;
V_17 . V_25 = V_26 ;
V_17 . V_27 = 0xff ;
V_17 . V_28 = 0 ;
V_17 . V_29 = V_15 -> V_29 ;
memset ( & V_19 , 0 , sizeof( V_19 ) ) ;
V_19 . V_25 = V_3 -> V_25 ;
V_19 . V_30 = V_3 -> V_30 ;
V_19 . V_31 = V_3 -> V_31 ;
V_19 . V_32 = V_3 -> V_32 ;
V_19 . V_33 = V_3 -> V_33 ;
V_19 . V_34 = V_3 -> V_34 >> 16 ;
V_19 . V_35 = V_3 -> V_35 >> 16 ;
if ( F_10 ( V_3 -> V_25 ) ) {
V_19 . V_36 = V_3 -> V_37 >> 16 ;
V_19 . V_37 = V_3 -> V_36 >> 16 ;
} else {
V_19 . V_36 = V_3 -> V_36 >> 16 ;
V_19 . V_37 = V_3 -> V_37 >> 16 ;
}
F_11 ( V_3 -> V_8 , & V_19 , & V_17 ) ;
F_9 ( L_2 , V_17 . V_38 , V_17 . V_39 ,
V_17 . V_40 , V_17 . V_41 ,
V_17 . V_42 ) ;
F_9 ( L_3 , V_17 . V_43 , V_17 . V_44 ,
& V_17 . V_45 , & V_17 . V_46 ) ;
V_11 -> V_47 -> V_48 ( V_14 -> V_49 ,
F_12 ( V_3 -> V_22 ) ) ;
V_20 = V_11 -> V_47 -> V_50 ( V_14 -> V_49 , & V_17 ,
F_13 ( V_3 -> V_22 ) , false ) ;
if ( V_20 ) {
F_14 ( V_6 -> V_12 -> V_12 , L_4 ,
V_14 -> V_21 ) ;
V_11 -> V_47 -> V_51 ( V_14 -> V_49 , false ) ;
return;
}
V_11 -> V_47 -> V_51 ( V_14 -> V_49 , true ) ;
}
static void F_15 ( struct V_5 * V_6 ,
struct V_2 * V_9 )
{
struct V_10 * V_11 = V_6 -> V_12 -> V_13 ;
struct V_1 * V_15 = F_1 ( V_6 -> V_3 ) ;
struct V_14 * V_14 = F_8 ( V_6 ) ;
V_6 -> V_3 -> V_25 = V_52 ;
V_15 -> V_29 = V_6 -> type == V_53
? 0 : V_14 -> V_49 ;
V_11 -> V_47 -> V_51 ( V_14 -> V_49 , false ) ;
}
static int F_16 ( struct V_5 * V_6 ,
struct V_2 * V_3 )
{
struct V_54 * V_55 ;
if ( ! V_3 -> V_8 )
return 0 ;
if ( F_17 ( ! V_3 -> V_22 ) )
return 0 ;
V_55 = F_18 ( V_3 -> V_3 , V_3 -> V_22 ) ;
if ( F_17 ( ! V_55 ) )
return 0 ;
if ( ! V_55 -> V_56 )
return 0 ;
if ( V_3 -> V_30 < 0 || V_3 -> V_31 < 0 )
return - V_57 ;
if ( V_3 -> V_30 + V_3 -> V_32 > V_55 -> V_58 . V_59 )
return - V_57 ;
if ( V_3 -> V_31 + V_3 -> V_33 > V_55 -> V_58 . V_60 )
return - V_57 ;
if ( V_3 -> V_25 != V_52 &&
! F_19 ( V_3 -> V_8 ) )
return - V_57 ;
return 0 ;
}
static void F_20 ( struct V_5 * V_6 )
{
struct V_14 * V_14 = F_8 ( V_6 ) ;
F_9 ( L_5 , V_14 -> V_21 ) ;
F_21 ( V_6 ) ;
F_22 ( V_14 ) ;
}
void F_23 ( struct V_5 * V_6 ,
struct V_61 * V_62 )
{
struct V_63 * V_12 = V_6 -> V_12 ;
struct V_10 * V_11 = V_12 -> V_13 ;
if ( V_11 -> V_64 ) {
if ( ! V_6 -> V_65 )
F_24 ( V_6 ,
V_52 ,
V_52 | V_66 |
V_67 | V_68 |
V_69 | V_70 ) ;
if ( V_6 -> V_65 && V_62 != & V_6 -> V_4 )
F_25 ( V_62 , V_6 -> V_65 ,
V_52 ) ;
}
F_25 ( V_62 , V_11 -> V_71 , 0 ) ;
}
static struct V_2 *
F_26 ( struct V_5 * V_6 )
{
struct V_1 * V_3 ;
struct V_1 * V_72 ;
if ( F_17 ( ! V_6 -> V_3 ) )
return NULL ;
V_3 = F_1 ( V_6 -> V_3 ) ;
V_72 = F_27 ( V_3 , sizeof( * V_3 ) , V_73 ) ;
if ( V_72 == NULL )
return NULL ;
F_28 ( V_6 , & V_72 -> V_4 ) ;
return & V_72 -> V_4 ;
}
static void F_29 ( struct V_5 * V_6 ,
struct V_2 * V_3 )
{
F_30 ( V_3 ) ;
F_22 ( F_1 ( V_3 ) ) ;
}
static void F_31 ( struct V_5 * V_6 )
{
struct V_14 * V_14 = F_8 ( V_6 ) ;
struct V_1 * V_15 ;
if ( V_6 -> V_3 ) {
F_29 ( V_6 , V_6 -> V_3 ) ;
V_6 -> V_3 = NULL ;
}
V_15 = F_32 ( sizeof( * V_15 ) , V_73 ) ;
if ( V_15 == NULL )
return;
V_15 -> V_29 = V_6 -> type == V_53
? 0 : V_14 -> V_49 ;
V_15 -> V_4 . V_25 = V_52 ;
V_6 -> V_3 = & V_15 -> V_4 ;
V_6 -> V_3 -> V_6 = V_6 ;
}
static int F_33 ( struct V_5 * V_6 ,
struct V_2 * V_3 ,
struct V_74 * V_75 ,
T_1 V_76 )
{
struct V_10 * V_11 = V_6 -> V_12 -> V_13 ;
struct V_1 * V_15 = F_1 ( V_3 ) ;
if ( V_75 == V_11 -> V_71 )
V_15 -> V_29 = V_76 ;
else
return - V_57 ;
return 0 ;
}
static int F_34 ( struct V_5 * V_6 ,
const struct V_2 * V_3 ,
struct V_74 * V_75 ,
T_1 * V_76 )
{
struct V_10 * V_11 = V_6 -> V_12 -> V_13 ;
const struct V_1 * V_15 =
F_2 ( V_3 , const struct V_1 , V_4 ) ;
if ( V_75 == V_11 -> V_71 )
* V_76 = V_15 -> V_29 ;
else
return - V_57 ;
return 0 ;
}
struct V_5 * F_35 ( struct V_63 * V_12 ,
int V_77 , enum V_78 type ,
T_2 V_79 )
{
struct V_10 * V_11 = V_12 -> V_13 ;
struct V_5 * V_6 ;
struct V_14 * V_14 ;
enum V_80 V_49 ;
int V_20 ;
if ( F_17 ( V_77 >= F_36 ( V_81 ) ) )
return F_37 ( - V_57 ) ;
V_49 = V_81 [ V_77 ] ;
F_9 ( L_6 , V_82 [ V_49 ] , type ) ;
V_14 = F_32 ( sizeof( * V_14 ) , V_73 ) ;
if ( ! V_14 )
return F_37 ( - V_83 ) ;
V_14 -> V_84 = F_38 (
V_14 -> V_85 , F_36 ( V_14 -> V_85 ) ,
V_11 -> V_47 -> V_86 ( V_49 ) ) ;
V_14 -> V_49 = V_49 ;
V_14 -> V_21 = V_82 [ V_49 ] ;
V_6 = & V_14 -> V_4 ;
V_20 = F_39 ( V_12 , V_6 , V_79 ,
& V_87 , V_14 -> V_85 ,
V_14 -> V_84 , type , NULL ) ;
if ( V_20 < 0 )
goto error;
F_40 ( V_6 , & V_88 ) ;
F_23 ( V_6 , & V_6 -> V_4 ) ;
return V_6 ;
error:
F_14 ( V_12 -> V_12 , L_7 ,
V_89 , V_82 [ V_49 ] ) ;
F_22 ( V_14 ) ;
return NULL ;
}
