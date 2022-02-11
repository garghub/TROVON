static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
int V_4 ;
V_4 = F_2 ( V_2 , V_5 , V_3 ) ;
if ( V_4 < 0 )
return V_4 ;
return F_3 ( V_2 , V_6 ) ;
}
static int F_4 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_7 , T_1 V_8 )
{
T_1 V_9 ;
int V_4 ;
V_4 = F_1 ( V_2 , V_3 ) ;
if ( V_4 < 0 )
return V_4 ;
V_9 = V_4 & 0xffff ;
V_9 &= ~ V_7 ;
V_9 |= V_8 ;
return F_2 ( V_2 , V_6 , V_9 ) ;
}
static inline int F_5 ( struct V_1 * V_2 )
{
return F_4 ( V_2 , V_10 , 0 ,
V_11 ) ;
}
static inline int F_6 ( struct V_1 * V_2 )
{
return F_4 ( V_2 , V_12 , 0 ,
V_13 ) ;
}
static void F_7 ( struct V_1 * V_2 ,
struct V_14 * V_15 )
{
V_15 -> V_16 = F_3 ( V_2 , V_17 ) ;
V_15 -> V_18 = F_3 ( V_2 , V_19 ) ;
V_15 -> V_20 = F_3 ( V_2 , V_21 ) ;
V_15 -> V_22 = F_3 ( V_2 , V_23 ) ;
V_15 -> V_24 = F_3 ( V_2 , V_25 ) ;
V_15 -> V_26 = F_3 ( V_2 , V_27 ) ;
}
static void F_8 ( struct V_1 * V_2 ,
const struct V_14 * V_15 )
{
F_2 ( V_2 , V_17 , V_15 -> V_16 ) ;
F_2 ( V_2 , V_19 , V_15 -> V_18 ) ;
F_2 ( V_2 , V_21 , V_15 -> V_20 ) ;
F_2 ( V_2 , V_23 , V_15 -> V_22 ) ;
F_2 ( V_2 , V_25 , V_15 -> V_24 ) ;
F_2 ( V_2 , V_27 , V_15 -> V_26 ) ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_28 * V_29 )
{
struct V_30 * V_31 = V_2 -> V_32 ;
const T_2 * V_33 ;
int V_4 ;
T_3 V_34 ;
unsigned int V_35 , V_36 [] = {
V_37 ,
V_38 ,
V_39 ,
} ;
if ( ! V_31 )
return - V_40 ;
if ( V_29 -> V_41 & V_42 ) {
V_33 = ( const T_2 * ) V_31 -> V_43 ;
if ( ! F_10 ( V_33 ) )
return - V_44 ;
for ( V_35 = 0 ; V_35 < 3 ; V_35 ++ ) {
F_2 ( V_2 , V_45 ,
V_46 ) ;
F_2 ( V_2 , V_47 ,
V_36 [ V_35 ] ) ;
F_2 ( V_2 , V_45 ,
V_48 ) ;
F_2 ( V_2 , V_47 ,
V_33 [ ( V_35 * 2 ) + 1 ] | ( V_33 [ ( V_35 * 2 ) ] << 8 ) ) ;
}
V_34 = F_3 ( V_2 , V_23 ) ;
V_34 |= V_49 ;
V_4 = F_2 ( V_2 , V_23 , V_34 ) ;
if ( V_4 )
return V_4 ;
V_34 = F_3 ( V_2 , V_50 ) ;
} else {
V_34 = F_3 ( V_2 , V_23 ) ;
V_34 &= ( ~ V_49 ) ;
V_4 = F_2 ( V_2 , V_23 , V_34 ) ;
if ( V_4 )
return V_4 ;
V_34 = F_3 ( V_2 , V_50 ) ;
}
return V_4 ;
}
static void F_11 ( struct V_1 * V_2 ,
struct V_28 * V_29 )
{
T_3 V_34 ;
V_29 -> V_51 = V_42 ;
V_29 -> V_41 = 0 ;
V_34 = F_3 ( V_2 , V_23 ) ;
if ( V_34 & V_49 )
V_29 -> V_41 |= V_42 ;
}
static int F_12 ( struct V_1 * V_2 )
{
int V_34 ;
int V_52 ;
F_13 ( & V_2 -> V_53 ) ;
V_34 = F_3 ( V_2 , V_23 ) ;
V_52 = V_34 & V_49 ;
V_34 = F_3 ( V_2 , V_17 ) ;
if ( V_52 )
V_34 |= V_54 ;
else
V_34 |= V_55 ;
F_2 ( V_2 , V_17 , V_34 ) ;
F_14 ( & V_2 -> V_53 ) ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 )
{
int V_34 ;
F_13 ( & V_2 -> V_53 ) ;
V_34 = F_3 ( V_2 , V_17 ) ;
V_34 &= ~ ( V_55 | V_54 ) ;
F_2 ( V_2 , V_17 , V_34 ) ;
F_14 ( & V_2 -> V_53 ) ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 )
{
struct V_56 * V_57 = & V_2 -> V_58 . V_57 ;
struct V_59 * V_60 ;
struct V_61 * V_62 ;
V_60 = F_17 ( V_57 , sizeof( * V_60 ) , V_63 ) ;
if ( ! V_60 )
return - V_64 ;
if ( V_2 -> V_65 -> V_66 != V_67 )
goto V_68;
V_62 = F_18 ( V_57 , L_1 , V_69 ) ;
if ( F_19 ( V_62 ) )
return F_20 ( V_62 ) ;
V_60 -> V_62 = V_62 ;
V_68:
V_2 -> V_60 = V_60 ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 )
{
int V_4 ;
V_4 = F_22 ( V_2 ) ;
if ( V_4 < 0 )
return V_4 ;
if ( V_2 -> V_70 == V_71 ||
V_2 -> V_70 == V_72 ) {
V_4 = F_5 ( V_2 ) ;
if ( V_4 < 0 )
return V_4 ;
}
if ( V_2 -> V_70 == V_73 ||
V_2 -> V_70 == V_72 ) {
V_4 = F_6 ( V_2 ) ;
if ( V_4 < 0 )
return V_4 ;
}
return 0 ;
}
static int F_23 ( struct V_1 * V_2 )
{
int V_74 ;
V_74 = F_3 ( V_2 , V_50 ) ;
return ( V_74 < 0 ) ? V_74 : 0 ;
}
static int F_24 ( struct V_1 * V_2 )
{
int V_74 ;
int V_34 ;
V_34 = F_3 ( V_2 , V_23 ) ;
if ( V_2 -> V_75 == V_76 ) {
V_34 |= V_77 ;
V_34 |= V_78 ;
V_34 |= V_79 ;
V_34 |= V_80 ;
V_34 |= V_81 ;
V_74 = F_2 ( V_2 , V_23 , V_34 ) ;
}
else
V_74 = F_2 ( V_2 , V_23 , 0 ) ;
return V_74 ;
}
static void F_25 ( struct V_1 * V_2 )
{
struct V_59 * V_60 = V_2 -> V_60 ;
if ( V_2 -> V_82 == V_83 ) {
if ( V_60 -> V_62 && ! V_60 -> V_84 ) {
struct V_14 V_15 ;
F_7 ( V_2 , & V_15 ) ;
F_26 ( V_60 -> V_62 , 1 ) ;
F_27 ( 1 ) ;
F_26 ( V_60 -> V_62 , 0 ) ;
F_27 ( 1 ) ;
F_8 ( V_2 , & V_15 ) ;
F_28 ( V_2 , L_2 ,
V_85 ) ;
V_60 -> V_84 = true ;
}
} else {
V_60 -> V_84 = false ;
}
}
static int F_29 ( struct V_1 * V_2 )
{
int V_86 ;
int V_87 = F_30 ( V_2 ) ;
if ( V_87 != V_88 )
return V_87 ;
V_86 = F_3 ( V_2 , V_89 ) ;
if ( ( V_86 & V_90 ) != V_91 )
return V_87 ;
F_2 ( V_2 , V_89 , V_86 & ~ V_92 ) ;
if ( ! ( F_3 ( V_2 , V_93 ) & V_94 ) ) {
F_31 ( L_3 ) ;
V_87 = 0 ;
}
F_2 ( V_2 , V_89 , V_86 | V_92 ) ;
return V_87 ;
}
