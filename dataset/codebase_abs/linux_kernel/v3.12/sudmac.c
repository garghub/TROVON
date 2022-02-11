static void F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
F_2 ( V_3 , V_2 -> V_5 + V_4 ) ;
}
static T_1 F_3 ( struct V_1 * V_2 , T_1 V_4 )
{
return F_4 ( V_2 -> V_5 + V_4 ) ;
}
static bool F_5 ( struct V_1 * V_2 )
{
T_1 V_6 = F_3 ( V_2 , V_7 + V_2 -> V_8 ) ;
if ( V_6 )
return true ;
return false ;
}
static void F_6 ( struct V_1 * V_2 , struct V_9 * V_10 ,
struct V_11 * V_12 )
{
F_1 ( V_2 , V_2 -> V_13 , V_14 + V_2 -> V_8 ) ;
F_1 ( V_2 , V_10 -> V_15 , V_16 + V_2 -> V_8 ) ;
F_1 ( V_2 , V_10 -> V_17 , V_18 + V_2 -> V_8 ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
T_1 V_19 = F_3 ( V_2 , V_20 ) ;
F_1 ( V_2 , V_19 | V_2 -> V_21 , V_20 ) ;
F_1 ( V_2 , 1 , V_7 + V_2 -> V_8 ) ;
}
static void F_8 ( struct V_22 * V_23 ,
struct V_11 * V_12 )
{
struct V_1 * V_2 = F_9 ( V_23 ) ;
struct V_24 * V_25 = F_10 ( V_12 ) ;
F_6 ( V_2 , & V_25 -> V_10 , V_12 ) ;
F_7 ( V_2 ) ;
}
static bool F_11 ( struct V_22 * V_23 )
{
struct V_1 * V_2 = F_9 ( V_23 ) ;
return F_5 ( V_2 ) ;
}
static void F_12 ( struct V_22 * V_23 , int V_26 )
{
}
static const struct V_27 * F_13 (
struct V_1 * V_2 , int V_26 )
{
struct V_28 * V_29 = F_14 ( V_2 ) ;
struct V_30 * V_31 = V_29 -> V_31 ;
const struct V_27 * V_13 ;
int V_32 ;
for ( V_32 = 0 , V_13 = V_31 -> V_33 ; V_32 < V_31 -> V_34 ; V_32 ++ , V_13 ++ )
if ( V_13 -> V_26 == V_26 )
return V_13 ;
return NULL ;
}
static int F_15 ( struct V_22 * V_23 , int V_26 ,
T_2 V_35 , bool V_36 )
{
struct V_1 * V_2 = F_9 ( V_23 ) ;
const struct V_27 * V_13 = F_13 ( V_2 , V_26 ) ;
if ( ! V_13 )
return - V_37 ;
return 0 ;
}
static inline void F_16 ( struct V_1 * V_2 )
{
T_1 V_19 = F_3 ( V_2 , V_20 ) ;
F_1 ( V_2 , 0 , V_7 + V_2 -> V_8 ) ;
F_1 ( V_2 , V_19 & ~ V_2 -> V_21 , V_20 ) ;
F_1 ( V_2 , V_2 -> V_21 , V_38 ) ;
}
static int F_17 ( struct V_22 * V_23 ,
struct V_11 * V_12 ,
T_2 V_39 , T_2 V_40 , T_3 * V_41 )
{
struct V_1 * V_2 = F_9 ( V_23 ) ;
struct V_24 * V_25 = F_10 ( V_12 ) ;
F_18 ( V_2 -> V_22 . V_42 , L_1 ,
V_43 , V_39 , V_40 , * V_41 ) ;
if ( * V_41 > V_23 -> V_44 )
* V_41 = V_23 -> V_44 ;
if ( V_40 )
V_25 -> V_10 . V_15 = V_40 ;
else if ( V_39 )
V_25 -> V_10 . V_15 = V_39 ;
V_25 -> V_10 . V_17 = * V_41 ;
return 0 ;
}
static void F_19 ( struct V_22 * V_23 )
{
struct V_1 * V_2 = F_9 ( V_23 ) ;
F_16 ( V_2 ) ;
}
static bool F_20 ( struct V_22 * V_23 , int V_45 )
{
struct V_1 * V_2 = F_9 ( V_23 ) ;
T_1 V_46 = F_3 ( V_2 , V_47 ) ;
if ( ! ( V_46 & V_2 -> V_21 ) )
return false ;
F_16 ( V_2 ) ;
return true ;
}
static T_3 F_21 ( struct V_22 * V_23 ,
struct V_11 * V_12 )
{
struct V_1 * V_2 = F_9 ( V_23 ) ;
struct V_24 * V_25 = F_10 ( V_12 ) ;
T_1 V_48 = F_3 ( V_2 , V_49 + V_2 -> V_8 ) ;
return V_25 -> V_10 . V_17 - V_48 ;
}
static bool F_22 ( struct V_22 * V_23 ,
struct V_11 * V_12 )
{
struct V_1 * V_2 = F_9 ( V_23 ) ;
struct V_24 * V_25 = F_10 ( V_12 ) ;
T_1 V_50 = F_3 ( V_2 , V_51 + V_2 -> V_8 ) ;
return V_25 -> V_10 . V_15 + V_25 -> V_10 . V_17 == V_50 ;
}
static int F_23 ( struct V_28 * V_52 , int V_53 , int V_45 ,
unsigned long V_54 )
{
struct V_55 * V_29 = & V_52 -> V_55 ;
struct V_56 * V_57 = F_24 ( V_29 -> V_58 . V_42 ) ;
struct V_1 * V_2 ;
struct V_22 * V_23 ;
int V_59 ;
V_2 = F_25 ( & V_57 -> V_42 , sizeof( struct V_1 ) , V_60 ) ;
if ( ! V_2 ) {
F_26 ( V_29 -> V_58 . V_42 ,
L_2 ) ;
return - V_61 ;
}
V_23 = & V_2 -> V_22 ;
V_23 -> V_44 = 64 * 1024 * 1024 - 1 ;
F_27 ( V_29 , V_23 , V_53 ) ;
V_2 -> V_5 = V_52 -> V_62 ;
V_2 -> V_8 = V_52 -> V_31 -> V_63 -> V_8 ;
if ( V_52 -> V_31 -> V_63 -> V_64 & V_65 )
V_2 -> V_13 |= V_66 ;
if ( V_52 -> V_31 -> V_63 -> V_64 & V_67 )
V_2 -> V_13 |= V_68 ;
V_2 -> V_13 |= ( V_52 -> V_31 -> V_63 -> V_69 << 4 ) & V_70 ;
if ( V_52 -> V_31 -> V_63 -> V_21 & V_71 )
V_2 -> V_21 |= V_72 ;
if ( V_52 -> V_31 -> V_63 -> V_21 & V_73 )
V_2 -> V_21 |= V_74 ;
if ( V_57 -> V_53 >= 0 )
snprintf ( V_2 -> V_75 , sizeof( V_2 -> V_75 ) , L_3 ,
V_57 -> V_53 , V_53 ) ;
else
snprintf ( V_2 -> V_75 , sizeof( V_2 -> V_75 ) , L_4 , V_53 ) ;
V_59 = F_28 ( V_23 , V_45 , V_54 , V_2 -> V_75 ) ;
if ( V_59 ) {
F_26 ( V_29 -> V_58 . V_42 ,
L_5 , V_53 , V_59 ) ;
goto V_76;
}
return 0 ;
V_76:
F_29 ( V_23 ) ;
return V_59 ;
}
static void F_30 ( struct V_28 * V_52 )
{
struct V_77 * V_58 = & V_52 -> V_55 . V_58 ;
struct V_22 * V_23 ;
int V_32 ;
F_31 (schan, &su_dev->shdma_dev, i) {
F_32 ( ! V_23 ) ;
F_29 ( V_23 ) ;
}
V_58 -> V_78 = 0 ;
}
static T_2 F_33 ( struct V_22 * V_23 )
{
return 0 ;
}
static struct V_11 * F_34 ( void * V_79 , int V_32 )
{
return & ( (struct V_24 * ) V_79 ) [ V_32 ] . V_11 ;
}
static int F_35 ( struct V_56 * V_57 )
{
struct V_30 * V_31 = F_36 ( & V_57 -> V_42 ) ;
int V_59 , V_32 ;
struct V_28 * V_52 ;
struct V_77 * V_58 ;
struct V_80 * V_81 , * V_82 ;
if ( ! V_31 )
return - V_37 ;
V_82 = F_37 ( V_57 , V_83 , 0 ) ;
if ( ! V_82 )
return - V_37 ;
V_59 = - V_61 ;
V_52 = F_25 ( & V_57 -> V_42 , sizeof( struct V_28 ) ,
V_60 ) ;
if ( ! V_52 ) {
F_26 ( & V_57 -> V_42 , L_6 ) ;
return V_59 ;
}
V_58 = & V_52 -> V_55 . V_58 ;
V_81 = F_37 ( V_57 , V_84 , 0 ) ;
V_52 -> V_62 = F_38 ( & V_57 -> V_42 , V_81 ) ;
if ( F_39 ( V_52 -> V_62 ) )
return F_40 ( V_52 -> V_62 ) ;
F_41 ( V_85 , V_58 -> V_86 ) ;
V_52 -> V_55 . V_87 = & V_88 ;
V_52 -> V_55 . V_89 = sizeof( struct V_24 ) ;
V_59 = F_42 ( & V_57 -> V_42 , & V_52 -> V_55 , V_31 -> V_90 ) ;
if ( V_59 < 0 )
return V_59 ;
V_52 -> V_31 = F_36 ( & V_57 -> V_42 ) ;
F_43 ( V_57 , V_52 ) ;
for ( V_32 = 0 ; V_32 < V_31 -> V_90 ; V_32 ++ ) {
V_59 = F_23 ( V_52 , V_32 , V_82 -> V_91 , V_92 ) ;
if ( V_59 )
goto V_93;
}
V_59 = F_44 ( & V_52 -> V_55 . V_58 ) ;
if ( V_59 < 0 )
goto V_93;
return V_59 ;
V_93:
F_30 ( V_52 ) ;
F_45 ( & V_52 -> V_55 ) ;
return V_59 ;
}
static int F_46 ( struct V_56 * V_57 )
{
struct V_28 * V_52 = F_47 ( V_57 ) ;
struct V_77 * V_58 = & V_52 -> V_55 . V_58 ;
F_48 ( V_58 ) ;
F_30 ( V_52 ) ;
F_45 ( & V_52 -> V_55 ) ;
return 0 ;
}
