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
static int F_15 ( struct V_22 * V_23 , int V_26 , bool V_35 )
{
struct V_1 * V_2 = F_9 ( V_23 ) ;
const struct V_27 * V_13 = F_13 ( V_2 , V_26 ) ;
if ( ! V_13 )
return - V_36 ;
return 0 ;
}
static inline void F_16 ( struct V_1 * V_2 )
{
T_1 V_19 = F_3 ( V_2 , V_20 ) ;
F_1 ( V_2 , 0 , V_7 + V_2 -> V_8 ) ;
F_1 ( V_2 , V_19 & ~ V_2 -> V_21 , V_20 ) ;
F_1 ( V_2 , V_2 -> V_21 , V_37 ) ;
}
static int F_17 ( struct V_22 * V_23 ,
struct V_11 * V_12 ,
T_2 V_38 , T_2 V_39 , T_3 * V_40 )
{
struct V_1 * V_2 = F_9 ( V_23 ) ;
struct V_24 * V_25 = F_10 ( V_12 ) ;
F_18 ( V_2 -> V_22 . V_41 , L_1 ,
V_42 , V_38 , V_39 , * V_40 ) ;
if ( * V_40 > V_23 -> V_43 )
* V_40 = V_23 -> V_43 ;
if ( V_39 )
V_25 -> V_10 . V_15 = V_39 ;
else if ( V_38 )
V_25 -> V_10 . V_15 = V_38 ;
V_25 -> V_10 . V_17 = * V_40 ;
return 0 ;
}
static void F_19 ( struct V_22 * V_23 )
{
struct V_1 * V_2 = F_9 ( V_23 ) ;
F_16 ( V_2 ) ;
}
static bool F_20 ( struct V_22 * V_23 , int V_44 )
{
struct V_1 * V_2 = F_9 ( V_23 ) ;
T_1 V_45 = F_3 ( V_2 , V_46 ) ;
if ( ! ( V_45 & V_2 -> V_21 ) )
return false ;
F_16 ( V_2 ) ;
return true ;
}
static T_3 F_21 ( struct V_22 * V_23 ,
struct V_11 * V_12 )
{
struct V_1 * V_2 = F_9 ( V_23 ) ;
struct V_24 * V_25 = F_10 ( V_12 ) ;
T_1 V_47 = F_3 ( V_2 , V_48 + V_2 -> V_8 ) ;
return V_25 -> V_10 . V_17 - V_47 ;
}
static bool F_22 ( struct V_22 * V_23 ,
struct V_11 * V_12 )
{
struct V_1 * V_2 = F_9 ( V_23 ) ;
struct V_24 * V_25 = F_10 ( V_12 ) ;
T_1 V_49 = F_3 ( V_2 , V_50 + V_2 -> V_8 ) ;
return V_25 -> V_10 . V_15 + V_25 -> V_10 . V_17 == V_49 ;
}
static int F_23 ( struct V_28 * V_51 , int V_52 , int V_44 ,
unsigned long V_53 )
{
struct V_54 * V_29 = & V_51 -> V_54 ;
struct V_55 * V_56 = F_24 ( V_29 -> V_57 . V_41 ) ;
struct V_1 * V_2 ;
struct V_22 * V_23 ;
int V_58 ;
V_2 = F_25 ( & V_56 -> V_41 , sizeof( struct V_1 ) , V_59 ) ;
if ( ! V_2 ) {
F_26 ( V_29 -> V_57 . V_41 ,
L_2 ) ;
return - V_60 ;
}
V_23 = & V_2 -> V_22 ;
V_23 -> V_43 = 64 * 1024 * 1024 - 1 ;
F_27 ( V_29 , V_23 , V_52 ) ;
V_2 -> V_5 = V_51 -> V_61 ;
V_2 -> V_8 = V_51 -> V_31 -> V_62 -> V_8 ;
if ( V_51 -> V_31 -> V_62 -> V_63 & V_64 )
V_2 -> V_13 |= V_65 ;
if ( V_51 -> V_31 -> V_62 -> V_63 & V_66 )
V_2 -> V_13 |= V_67 ;
V_2 -> V_13 |= ( V_51 -> V_31 -> V_62 -> V_68 << 4 ) & V_69 ;
if ( V_51 -> V_31 -> V_62 -> V_21 & V_70 )
V_2 -> V_21 |= V_71 ;
if ( V_51 -> V_31 -> V_62 -> V_21 & V_72 )
V_2 -> V_21 |= V_73 ;
if ( V_56 -> V_52 >= 0 )
snprintf ( V_2 -> V_74 , sizeof( V_2 -> V_74 ) , L_3 ,
V_56 -> V_52 , V_52 ) ;
else
snprintf ( V_2 -> V_74 , sizeof( V_2 -> V_74 ) , L_4 , V_52 ) ;
V_58 = F_28 ( V_23 , V_44 , V_53 , V_2 -> V_74 ) ;
if ( V_58 ) {
F_26 ( V_29 -> V_57 . V_41 ,
L_5 , V_52 , V_58 ) ;
goto V_75;
}
return 0 ;
V_75:
F_29 ( V_23 ) ;
return V_58 ;
}
static void F_30 ( struct V_28 * V_51 )
{
struct V_76 * V_57 = & V_51 -> V_54 . V_57 ;
struct V_22 * V_23 ;
int V_32 ;
F_31 (schan, &su_dev->shdma_dev, i) {
struct V_1 * V_2 = F_9 ( V_23 ) ;
F_32 ( ! V_23 ) ;
F_33 ( & V_2 -> V_22 ) ;
F_29 ( V_23 ) ;
}
V_57 -> V_77 = 0 ;
}
static T_2 F_34 ( struct V_22 * V_23 )
{
return 0 ;
}
static struct V_11 * F_35 ( void * V_78 , int V_32 )
{
return & ( (struct V_24 * ) V_78 ) [ V_32 ] . V_11 ;
}
static int F_36 ( struct V_55 * V_56 )
{
struct V_30 * V_31 = V_56 -> V_41 . V_79 ;
int V_58 , V_32 ;
struct V_28 * V_51 ;
struct V_76 * V_57 ;
struct V_80 * V_81 , * V_82 ;
if ( ! V_31 )
return - V_36 ;
V_81 = F_37 ( V_56 , V_83 , 0 ) ;
V_82 = F_37 ( V_56 , V_84 , 0 ) ;
if ( ! V_81 || ! V_82 )
return - V_36 ;
V_58 = - V_60 ;
V_51 = F_25 ( & V_56 -> V_41 , sizeof( struct V_28 ) ,
V_59 ) ;
if ( ! V_51 ) {
F_26 ( & V_56 -> V_41 , L_6 ) ;
return V_58 ;
}
V_57 = & V_51 -> V_54 . V_57 ;
V_51 -> V_61 = F_38 ( & V_56 -> V_41 , V_81 ) ;
if ( ! V_51 -> V_61 )
return V_58 ;
F_39 ( V_85 , V_57 -> V_86 ) ;
V_51 -> V_54 . V_87 = & V_88 ;
V_51 -> V_54 . V_89 = sizeof( struct V_24 ) ;
V_58 = F_40 ( & V_56 -> V_41 , & V_51 -> V_54 , V_31 -> V_90 ) ;
if ( V_58 < 0 )
return V_58 ;
V_51 -> V_31 = V_56 -> V_41 . V_79 ;
F_41 ( V_56 , V_51 ) ;
for ( V_32 = 0 ; V_32 < V_31 -> V_90 ; V_32 ++ ) {
V_58 = F_23 ( V_51 , V_32 , V_82 -> V_91 , V_92 ) ;
if ( V_58 )
goto V_93;
}
V_58 = F_42 ( & V_51 -> V_54 . V_57 ) ;
if ( V_58 < 0 )
goto V_93;
return V_58 ;
V_93:
F_30 ( V_51 ) ;
F_41 ( V_56 , NULL ) ;
F_43 ( & V_51 -> V_54 ) ;
return V_58 ;
}
static int F_44 ( struct V_55 * V_56 )
{
struct V_28 * V_51 = F_45 ( V_56 ) ;
struct V_76 * V_57 = & V_51 -> V_54 . V_57 ;
F_46 ( V_57 ) ;
F_30 ( V_51 ) ;
F_43 ( & V_51 -> V_54 ) ;
F_41 ( V_56 , NULL ) ;
return 0 ;
}
