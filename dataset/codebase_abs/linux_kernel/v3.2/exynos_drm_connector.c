static inline void
F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_2 ( L_1 , __FILE__ ) ;
V_2 -> clock = V_4 -> V_5 / 1000 ;
V_2 -> V_6 = V_4 -> V_7 ;
V_2 -> V_8 = V_4 -> V_9 ;
V_2 -> V_10 = V_2 -> V_8 + V_4 -> V_11 ;
V_2 -> V_12 = V_2 -> V_10 + V_4 -> V_13 ;
V_2 -> V_14 = V_2 -> V_12 + V_4 -> V_15 ;
V_2 -> V_16 = V_4 -> V_17 ;
V_2 -> V_18 = V_2 -> V_16 + V_4 -> V_19 ;
V_2 -> V_20 = V_2 -> V_18 + V_4 -> V_21 ;
V_2 -> V_22 = V_2 -> V_20 + V_4 -> V_23 ;
if ( V_4 -> V_24 & V_25 )
V_2 -> V_26 |= V_27 ;
if ( V_4 -> V_24 & V_28 )
V_2 -> V_26 |= V_29 ;
}
static inline void
F_3 ( struct V_3 * V_4 ,
struct V_1 * V_2 )
{
F_2 ( L_1 , __FILE__ ) ;
memset ( V_4 , 0 , sizeof( * V_4 ) ) ;
V_4 -> V_5 = V_2 -> clock * 1000 ;
V_4 -> V_7 = F_4 ( V_2 ) ;
V_4 -> V_9 = V_2 -> V_8 ;
V_4 -> V_11 = V_2 -> V_10 - V_2 -> V_8 ;
V_4 -> V_13 = V_2 -> V_12 - V_2 -> V_10 ;
V_4 -> V_15 = V_2 -> V_14 - V_2 -> V_12 ;
V_4 -> V_17 = V_2 -> V_16 ;
V_4 -> V_19 = V_2 -> V_18 - V_2 -> V_16 ;
V_4 -> V_21 = V_2 -> V_20 - V_2 -> V_18 ;
V_4 -> V_23 = V_2 -> V_22 - V_2 -> V_20 ;
if ( V_2 -> V_26 & V_27 )
V_4 -> V_24 = V_25 ;
else
V_4 -> V_24 = V_30 ;
if ( V_2 -> V_26 & V_29 )
V_4 -> V_24 |= V_28 ;
}
static int F_5 ( struct V_31 * V_32 )
{
struct V_33 * V_34 =
F_6 ( V_32 ) ;
struct V_35 * V_36 = V_34 -> V_36 ;
struct V_37 * V_38 = V_36 -> V_38 ;
unsigned int V_39 ;
F_2 ( L_1 , __FILE__ ) ;
if ( ! V_38 ) {
F_2 ( L_2 ) ;
return 0 ;
}
if ( V_38 -> V_40 ) {
int V_41 ;
void * V_42 ;
V_42 = F_7 ( V_43 , V_44 ) ;
if ( ! V_42 ) {
F_8 ( L_3 ) ;
return 0 ;
}
V_41 = V_38 -> V_40 ( V_36 -> V_45 , V_32 ,
V_42 , V_43 ) ;
if ( V_41 < 0 ) {
F_8 ( L_4 ) ;
F_9 ( V_42 ) ;
V_42 = NULL ;
return 0 ;
}
F_10 ( V_32 , V_42 ) ;
V_39 = F_11 ( V_32 , V_42 ) ;
F_9 ( V_32 -> V_46 . V_47 ) ;
V_32 -> V_46 . V_47 = V_42 ;
} else {
struct V_1 * V_2 = F_12 ( V_32 -> V_45 ) ;
struct V_3 * V_4 ;
if ( V_38 -> V_48 )
V_4 = V_38 -> V_48 ( V_36 -> V_45 ) ;
else {
F_13 ( V_32 -> V_45 , V_2 ) ;
return 0 ;
}
F_1 ( V_2 , V_4 ) ;
V_2 -> type = V_49 | V_50 ;
F_14 ( V_2 ) ;
F_15 ( V_32 , V_2 ) ;
V_39 = 1 ;
}
return V_39 ;
}
static int F_16 ( struct V_31 * V_32 ,
struct V_1 * V_2 )
{
struct V_33 * V_34 =
F_6 ( V_32 ) ;
struct V_35 * V_36 = V_34 -> V_36 ;
struct V_37 * V_38 = V_36 -> V_38 ;
struct V_3 V_4 ;
int V_41 = V_51 ;
F_2 ( L_1 , __FILE__ ) ;
F_3 ( & V_4 , V_2 ) ;
if ( V_38 && V_38 -> V_52 )
if ( ! V_38 -> V_52 ( V_36 -> V_45 , ( void * ) & V_4 ) )
V_41 = V_53 ;
return V_41 ;
}
struct V_54 * F_17 ( struct V_31 * V_32 )
{
struct V_55 * V_45 = V_32 -> V_45 ;
struct V_33 * V_34 =
F_6 ( V_32 ) ;
struct V_56 * V_57 ;
struct V_54 * V_58 ;
F_2 ( L_1 , __FILE__ ) ;
V_57 = F_18 ( V_45 , V_34 -> V_59 ,
V_60 ) ;
if ( ! V_57 ) {
F_2 ( L_5 ,
V_34 -> V_59 ) ;
return NULL ;
}
V_58 = F_19 ( V_57 ) ;
return V_58 ;
}
static enum V_61
F_20 ( struct V_31 * V_32 , bool V_62 )
{
struct V_33 * V_34 =
F_6 ( V_32 ) ;
struct V_35 * V_36 = V_34 -> V_36 ;
struct V_37 * V_38 =
V_36 -> V_38 ;
enum V_61 V_63 = V_64 ;
F_2 ( L_1 , __FILE__ ) ;
if ( V_38 && V_38 -> V_65 ) {
if ( V_38 -> V_65 ( V_36 -> V_45 ) )
V_63 = V_66 ;
else
V_63 = V_64 ;
}
return V_63 ;
}
static void F_21 ( struct V_31 * V_32 )
{
struct V_33 * V_34 =
F_6 ( V_32 ) ;
F_2 ( L_1 , __FILE__ ) ;
F_22 ( V_32 ) ;
F_23 ( V_32 ) ;
F_9 ( V_34 ) ;
}
struct V_31 * F_24 ( struct V_55 * V_45 ,
struct V_54 * V_58 )
{
struct V_33 * V_34 ;
struct V_35 * V_36 = F_25 ( V_58 ) ;
struct V_31 * V_32 ;
int type ;
int V_67 ;
F_2 ( L_1 , __FILE__ ) ;
V_34 = F_7 ( sizeof( * V_34 ) , V_44 ) ;
if ( ! V_34 ) {
F_8 ( L_6 ) ;
return NULL ;
}
V_32 = & V_34 -> V_31 ;
switch ( V_36 -> V_38 -> type ) {
case V_68 :
type = V_69 ;
V_32 -> V_70 = true ;
V_32 -> V_71 = V_72 ;
break;
default:
type = V_73 ;
break;
}
F_26 ( V_45 , V_32 , & V_74 , type ) ;
F_27 ( V_32 , & V_75 ) ;
V_67 = F_28 ( V_32 ) ;
if ( V_67 )
goto V_76;
V_34 -> V_59 = V_58 -> V_77 . V_78 ;
V_34 -> V_36 = V_36 ;
V_32 -> V_58 = V_58 ;
V_67 = F_29 ( V_32 , V_58 ) ;
if ( V_67 ) {
F_8 ( L_7 ) ;
goto V_79;
}
F_2 ( L_8 ) ;
return V_32 ;
V_79:
F_22 ( V_32 ) ;
V_76:
F_23 ( V_32 ) ;
F_9 ( V_34 ) ;
return NULL ;
}
