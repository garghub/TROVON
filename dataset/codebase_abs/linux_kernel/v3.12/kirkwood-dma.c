static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_6 ;
return F_2 ( V_5 -> V_7 ) ;
}
static T_1 F_3 ( int V_8 , void * V_9 )
{
struct V_1 * V_10 = V_9 ;
unsigned long V_11 , V_12 , V_13 ;
V_11 = F_4 ( V_10 -> V_14 + V_15 ) ;
V_12 = F_4 ( V_10 -> V_14 + V_16 ) & V_11 ;
V_13 = F_4 ( V_10 -> V_14 + V_17 ) ;
if ( F_5 ( V_13 ) ) {
F_6 ( V_18 L_1 ,
V_19 , V_13 ) ;
F_7 ( V_13 , V_10 -> V_14 + V_17 ) ;
}
if ( V_12 & ~ ( V_20 | \
V_21 ) ) {
F_6 ( V_18 L_2 ,
V_19 , V_12 ) ;
return V_22 ;
}
F_7 ( V_12 , V_10 -> V_14 + V_16 ) ;
if ( V_12 & V_20 )
F_8 ( V_10 -> V_23 ) ;
if ( V_12 & V_21 )
F_8 ( V_10 -> V_24 ) ;
return V_25 ;
}
static void
F_9 ( void T_2 * V_26 , int V_27 ,
unsigned long V_28 ,
const struct V_29 * V_30 )
{
int V_31 ;
F_7 ( 0 , V_26 + F_10 ( V_27 ) ) ;
F_7 ( 0 , V_26 + F_11 ( V_27 ) ) ;
for ( V_31 = 0 ; V_31 < V_30 -> V_32 ; V_31 ++ ) {
const struct V_33 * V_34 = V_30 -> V_34 + V_31 ;
if ( ( V_34 -> V_26 & 0xffff0000 ) < ( V_28 & 0xffff0000 ) ) {
F_7 ( V_34 -> V_26 & 0xffff0000 ,
V_26 + F_11 ( V_27 ) ) ;
F_7 ( ( ( V_34 -> V_35 - 1 ) & 0xffff0000 ) |
( V_34 -> V_36 << 8 ) |
( V_30 -> V_37 << 4 ) | 1 ,
V_26 + F_10 ( V_27 ) ) ;
}
}
}
static int F_12 ( struct V_2 * V_38 )
{
int V_39 ;
struct V_40 * V_41 = V_38 -> V_41 ;
struct V_1 * V_10 = F_1 ( V_38 ) ;
const struct V_29 * V_30 ;
unsigned long V_42 ;
F_13 ( V_38 , & V_43 ) ;
V_39 = F_14 ( V_41 ,
V_44 ,
V_10 -> V_45 * 2 ,
V_46 - 1 ) ;
if ( V_39 < 0 )
return V_39 ;
V_39 = F_15 ( V_41 , 0 ,
V_44 ,
V_10 -> V_45 ) ;
if ( V_39 < 0 )
return V_39 ;
V_39 = F_15 ( V_38 -> V_41 , 0 ,
V_47 ,
V_10 -> V_45 ) ;
if ( V_39 < 0 )
return V_39 ;
if ( ! V_10 -> V_23 && ! V_10 -> V_24 ) {
V_39 = F_16 ( V_10 -> V_8 , F_3 , V_48 ,
L_3 , V_10 ) ;
if ( V_39 )
return - V_49 ;
F_7 ( ( unsigned long ) - 1 , V_10 -> V_14 + V_50 ) ;
}
V_30 = F_17 () ;
V_42 = V_38 -> V_51 . V_42 ;
if ( V_38 -> V_52 == V_53 ) {
V_10 -> V_23 = V_38 ;
F_9 ( V_10 -> V_14 ,
V_54 , V_42 , V_30 ) ;
} else {
V_10 -> V_24 = V_38 ;
F_9 ( V_10 -> V_14 ,
V_55 , V_42 , V_30 ) ;
}
return 0 ;
}
static int F_18 ( struct V_2 * V_38 )
{
struct V_1 * V_10 = F_1 ( V_38 ) ;
if ( ! V_10 )
return 0 ;
if ( V_38 -> V_52 == V_53 )
V_10 -> V_23 = NULL ;
else
V_10 -> V_24 = NULL ;
if ( ! V_10 -> V_23 && ! V_10 -> V_24 ) {
F_7 ( 0 , V_10 -> V_14 + V_50 ) ;
F_19 ( V_10 -> V_8 , V_10 ) ;
}
return 0 ;
}
static int F_20 ( struct V_2 * V_38 ,
struct V_56 * V_57 )
{
struct V_40 * V_41 = V_38 -> V_41 ;
F_21 ( V_38 , & V_38 -> V_51 ) ;
V_41 -> V_58 = F_22 ( V_57 ) ;
return 0 ;
}
static int F_23 ( struct V_2 * V_38 )
{
F_21 ( V_38 , NULL ) ;
return 0 ;
}
static int F_24 ( struct V_2 * V_38 )
{
struct V_40 * V_41 = V_38 -> V_41 ;
struct V_1 * V_10 = F_1 ( V_38 ) ;
unsigned long V_35 , V_59 ;
V_35 = F_25 ( V_41 , V_41 -> V_60 ) ;
V_35 = ( V_35 >> 2 ) - 1 ;
V_59 = F_26 ( V_38 ) ;
if ( V_38 -> V_52 == V_53 ) {
F_7 ( V_59 , V_10 -> V_14 + V_61 ) ;
F_7 ( V_41 -> V_62 , V_10 -> V_14 + V_63 ) ;
F_7 ( V_35 , V_10 -> V_14 + V_64 ) ;
} else {
F_7 ( V_59 , V_10 -> V_14 + V_65 ) ;
F_7 ( V_41 -> V_62 , V_10 -> V_14 + V_66 ) ;
F_7 ( V_35 , V_10 -> V_14 + V_67 ) ;
}
return 0 ;
}
static T_3 F_27 ( struct V_2
* V_38 )
{
struct V_1 * V_10 = F_1 ( V_38 ) ;
T_3 V_59 ;
if ( V_38 -> V_52 == V_53 )
V_59 = F_28 ( V_38 -> V_41 ,
F_4 ( V_10 -> V_14 + V_68 ) ) ;
else
V_59 = F_28 ( V_38 -> V_41 ,
F_4 ( V_10 -> V_14 + V_69 ) ) ;
return V_59 ;
}
static int F_29 ( struct V_70 * V_71 ,
int V_52 )
{
struct V_2 * V_38 = V_71 -> V_72 [ V_52 ] . V_38 ;
struct V_73 * V_74 = & V_38 -> V_51 ;
T_4 V_35 = V_43 . V_75 ;
V_74 -> V_76 . type = V_77 ;
V_74 -> V_76 . V_76 = V_71 -> V_78 -> V_76 ;
V_74 -> V_79 = F_30 ( V_71 -> V_78 -> V_76 , V_35 ,
& V_74 -> V_42 , V_80 ) ;
if ( ! V_74 -> V_79 )
return - V_81 ;
V_74 -> V_82 = V_35 ;
V_74 -> V_6 = NULL ;
return 0 ;
}
static int F_31 ( struct V_4 * V_83 )
{
struct V_84 * V_78 = V_83 -> V_78 -> V_84 ;
struct V_70 * V_71 = V_83 -> V_71 ;
int V_85 ;
if ( ! V_78 -> V_76 -> V_86 )
V_78 -> V_76 -> V_86 = & V_87 ;
if ( ! V_78 -> V_76 -> V_88 )
V_78 -> V_76 -> V_88 = F_32 ( 32 ) ;
if ( V_71 -> V_72 [ V_53 ] . V_38 ) {
V_85 = F_29 ( V_71 ,
V_53 ) ;
if ( V_85 )
return V_85 ;
}
if ( V_71 -> V_72 [ V_89 ] . V_38 ) {
V_85 = F_29 ( V_71 ,
V_89 ) ;
if ( V_85 )
return V_85 ;
}
return 0 ;
}
static void F_33 ( struct V_70 * V_71 )
{
struct V_2 * V_38 ;
struct V_73 * V_74 ;
int V_52 ;
for ( V_52 = 0 ; V_52 < 2 ; V_52 ++ ) {
V_38 = V_71 -> V_72 [ V_52 ] . V_38 ;
if ( ! V_38 )
continue;
V_74 = & V_38 -> V_51 ;
if ( ! V_74 -> V_79 )
continue;
F_34 ( V_71 -> V_78 -> V_76 , V_74 -> V_82 ,
V_74 -> V_79 , V_74 -> V_42 ) ;
V_74 -> V_79 = NULL ;
}
}
