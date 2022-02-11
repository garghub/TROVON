static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static void F_3 ( void * V_4 , int V_5 , unsigned int V_6 )
{
F_4 ( V_6 & 0xFFFF , V_4 + V_5 ) ;
}
static void F_5 ( void * V_4 , int V_5 ,
unsigned short V_7 , unsigned short V_6 )
{
unsigned short V_8 ;
V_8 = F_6 ( V_4 + V_5 ) ;
V_8 &= ~ V_7 ;
V_8 |= V_6 & V_7 ;
F_4 ( V_8 , V_4 + V_5 ) ;
}
static int F_7 ( unsigned long V_9 ,
unsigned short * V_10 , unsigned short * V_11 )
{
unsigned int V_12 , V_13 ;
for ( V_12 = 0 ; V_12 <= V_14 ; V_12 ++ ) {
for ( V_13 = 0 ; V_13 <= V_15 ; V_13 ++ ) {
* V_10 = ( 1 << V_12 ) *
( V_13 ? ( V_13 * 2 ) : 1 ) ;
if ( * V_10 > V_9 ) {
* V_11 = ( V_12 << V_16 ) |
( V_13 << V_17 ) ;
return 0 ;
}
}
}
return 1 ;
}
static void F_8 ( struct V_1 * V_18 , int V_19 ,
unsigned long V_20 )
{
int V_21 , V_22 ;
unsigned short V_23 , V_24 ;
if ( V_19 == 1 ) {
V_22 = V_25 ;
V_21 = V_26 ;
V_23 = V_27 ;
V_24 = V_28 ;
} else {
V_21 = V_29 ;
V_22 = V_30 ;
V_23 = V_31 ;
V_24 = V_32 ;
}
V_23 |= V_33 | V_34 ;
V_24 |= V_35 | V_36 ;
F_5 ( V_18 -> V_37 , V_22 , V_24 , V_23 ) ;
F_3 ( V_18 -> V_37 , V_21 , V_20 ) ;
}
static int F_9 ( struct V_2 * V_3 , struct V_38 * V_39 ,
int V_40 , int V_41 )
{
struct V_1 * V_18 = F_1 ( V_3 ) ;
unsigned long long V_42 ;
unsigned long V_43 , V_20 ;
unsigned short V_44 , V_45 ;
int V_46 ;
if ( V_41 < 0 || V_40 < 0 || V_41 > V_47 )
return - V_48 ;
V_42 = V_18 -> V_49 ;
V_42 = V_42 * V_41 ;
F_10 ( V_42 , V_47 ) ;
V_43 = ( unsigned long ) V_42 ;
if ( V_43 < 1 ) {
V_43 = 1 ;
V_20 = 1 ;
} else {
V_42 = V_18 -> V_49 ;
V_42 = V_42 * V_40 ;
F_10 ( V_42 , V_47 ) ;
V_20 = ( unsigned long ) V_42 ;
}
for ( V_46 = 0 ; V_46 < V_50 ; V_46 ++ ) {
if ( V_18 -> V_43 [ V_46 ] &&
( V_18 -> V_43 [ V_46 ] != V_43 ) ) {
if ( V_46 == V_39 -> V_51 )
continue;
F_11 ( V_3 -> V_52 , L_1 ,
V_46 ) ;
return - V_53 ;
}
}
V_18 -> V_43 [ V_39 -> V_51 ] = V_43 ;
if ( F_7 ( V_43 / V_54 , & V_44 ,
& V_45 ) ) {
F_11 ( V_3 -> V_52 , L_2 ) ;
return - V_53 ;
}
F_12 ( V_3 -> V_52 ) ;
F_5 ( V_18 -> V_37 , V_55 , V_56 , V_45 ) ;
V_43 = V_43 / V_44 ;
V_20 = V_20 / V_44 ;
F_5 ( V_18 -> V_37 , V_55 , V_57 , V_58 ) ;
F_3 ( V_18 -> V_37 , V_59 , V_43 ) ;
F_5 ( V_18 -> V_37 , V_55 , V_60 ,
V_61 ) ;
F_8 ( V_18 , V_39 -> V_51 , V_20 ) ;
F_13 ( V_3 -> V_52 ) ;
return 0 ;
}
static int F_14 ( struct V_2 * V_3 , struct V_38 * V_39 )
{
struct V_1 * V_18 = F_1 ( V_3 ) ;
unsigned short V_62 , V_63 ;
F_12 ( V_3 -> V_52 ) ;
if ( V_39 -> V_51 ) {
V_62 = V_64 ;
V_63 = V_65 ;
} else {
V_62 = V_66 ;
V_63 = V_67 ;
}
F_5 ( V_18 -> V_37 , V_68 , V_69 ,
V_70 ) ;
F_5 ( V_18 -> V_37 , V_71 , V_63 , V_62 ) ;
F_5 ( V_18 -> V_37 , V_55 , V_72 , V_73 ) ;
return 0 ;
}
static void F_15 ( struct V_2 * V_3 , struct V_38 * V_39 )
{
struct V_1 * V_18 = F_1 ( V_3 ) ;
unsigned short V_62 , V_63 ;
if ( V_39 -> V_51 ) {
V_62 = V_74 ;
V_63 = V_65 ;
} else {
V_62 = V_75 ;
V_63 = V_67 ;
}
F_5 ( V_18 -> V_37 , V_68 , V_69 ,
V_76 ) ;
F_5 ( V_18 -> V_37 , V_71 , V_63 , V_62 ) ;
F_5 ( V_18 -> V_37 , V_55 , V_72 , V_77 ) ;
F_13 ( V_3 -> V_52 ) ;
}
static void F_16 ( struct V_2 * V_3 , struct V_38 * V_39 )
{
struct V_1 * V_18 = F_1 ( V_3 ) ;
if ( F_17 ( V_78 , & V_39 -> V_79 ) ) {
F_18 ( V_3 -> V_52 , L_3 ) ;
F_13 ( V_3 -> V_52 ) ;
}
V_18 -> V_43 [ V_39 -> V_51 ] = 0 ;
}
static int T_1 F_19 ( struct V_80 * V_81 )
{
int V_82 ;
struct V_83 * V_84 ;
struct V_85 * V_85 ;
struct V_1 * V_18 ;
V_18 = F_20 ( & V_81 -> V_52 , sizeof( * V_18 ) , V_86 ) ;
if ( ! V_18 ) {
F_11 ( & V_81 -> V_52 , L_4 ) ;
return - V_87 ;
}
V_85 = F_21 ( & V_81 -> V_52 , L_5 ) ;
if ( F_22 ( V_85 ) ) {
F_11 ( & V_81 -> V_52 , L_6 ) ;
return F_23 ( V_85 ) ;
}
V_18 -> V_49 = F_24 ( V_85 ) ;
if ( ! V_18 -> V_49 ) {
F_11 ( & V_81 -> V_52 , L_7 ) ;
return - V_53 ;
}
V_18 -> V_3 . V_52 = & V_81 -> V_52 ;
V_18 -> V_3 . V_88 = & V_89 ;
V_18 -> V_3 . V_4 = - 1 ;
V_18 -> V_3 . V_90 = V_50 ;
V_84 = F_25 ( V_81 , V_91 , 0 ) ;
if ( ! V_84 ) {
F_11 ( & V_81 -> V_52 , L_8 ) ;
return - V_92 ;
}
V_18 -> V_37 = F_26 ( & V_81 -> V_52 , V_84 ) ;
if ( ! V_18 -> V_37 )
return - V_93 ;
V_82 = F_27 ( & V_18 -> V_3 ) ;
if ( V_82 < 0 ) {
F_11 ( & V_81 -> V_52 , L_9 , V_82 ) ;
return V_82 ;
}
F_28 ( & V_81 -> V_52 ) ;
F_29 ( V_81 , V_18 ) ;
return 0 ;
}
static int T_2 F_30 ( struct V_80 * V_81 )
{
struct V_1 * V_18 = F_31 ( V_81 ) ;
F_13 ( & V_81 -> V_52 ) ;
F_32 ( & V_81 -> V_52 ) ;
return F_33 ( & V_18 -> V_3 ) ;
}
