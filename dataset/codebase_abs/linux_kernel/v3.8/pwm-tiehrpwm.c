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
static void F_8 ( struct V_1 * V_18 , int V_19 )
{
int V_20 ;
unsigned short V_21 , V_22 ;
if ( V_19 == 1 ) {
V_20 = V_23 ;
V_22 = V_24 ;
if ( V_18 -> V_25 [ V_19 ] == V_26 )
V_21 = V_27 ;
else
V_21 = V_28 ;
} else {
V_20 = V_29 ;
V_22 = V_30 ;
if ( V_18 -> V_25 [ V_19 ] == V_26 )
V_21 = V_31 ;
else
V_21 = V_32 ;
}
V_22 |= V_33 | V_34 ;
F_5 ( V_18 -> V_35 , V_20 , V_22 , V_21 ) ;
}
static int F_9 ( struct V_2 * V_3 , struct V_36 * V_37 ,
int V_38 , int V_39 )
{
struct V_1 * V_18 = F_1 ( V_3 ) ;
unsigned long long V_40 ;
unsigned long V_41 , V_42 ;
unsigned short V_43 , V_44 ;
int V_45 , V_46 ;
if ( V_39 > V_47 )
return - V_48 ;
V_40 = V_18 -> V_49 ;
V_40 = V_40 * V_39 ;
F_10 ( V_40 , V_47 ) ;
V_41 = ( unsigned long ) V_40 ;
if ( V_41 < 1 ) {
V_41 = 1 ;
V_42 = 1 ;
} else {
V_40 = V_18 -> V_49 ;
V_40 = V_40 * V_38 ;
F_10 ( V_40 , V_47 ) ;
V_42 = ( unsigned long ) V_40 ;
}
for ( V_45 = 0 ; V_45 < V_50 ; V_45 ++ ) {
if ( V_18 -> V_41 [ V_45 ] &&
( V_18 -> V_41 [ V_45 ] != V_41 ) ) {
if ( V_45 == V_37 -> V_51 )
continue;
F_11 ( V_3 -> V_52 , L_1 ,
V_45 ) ;
return - V_53 ;
}
}
V_18 -> V_41 [ V_37 -> V_51 ] = V_41 ;
if ( F_7 ( V_41 / V_54 , & V_43 ,
& V_44 ) ) {
F_11 ( V_3 -> V_52 , L_2 ) ;
return - V_53 ;
}
F_12 ( V_3 -> V_52 ) ;
F_5 ( V_18 -> V_35 , V_55 , V_56 , V_44 ) ;
V_41 = V_41 / V_43 ;
V_42 = V_42 / V_43 ;
F_5 ( V_18 -> V_35 , V_55 , V_57 , V_58 ) ;
F_3 ( V_18 -> V_35 , V_59 , V_41 ) ;
F_5 ( V_18 -> V_35 , V_55 , V_60 ,
V_61 ) ;
if ( V_37 -> V_51 == 1 )
V_46 = V_62 ;
else
V_46 = V_63 ;
F_3 ( V_18 -> V_35 , V_46 , V_42 ) ;
F_13 ( V_3 -> V_52 ) ;
return 0 ;
}
static int F_14 ( struct V_2 * V_3 ,
struct V_36 * V_37 , enum V_64 V_25 )
{
struct V_1 * V_18 = F_1 ( V_3 ) ;
V_18 -> V_25 [ V_37 -> V_51 ] = V_25 ;
return 0 ;
}
static int F_15 ( struct V_2 * V_3 , struct V_36 * V_37 )
{
struct V_1 * V_18 = F_1 ( V_3 ) ;
unsigned short V_65 , V_66 ;
F_12 ( V_3 -> V_52 ) ;
if ( V_37 -> V_51 ) {
V_65 = V_67 ;
V_66 = V_68 ;
} else {
V_65 = V_69 ;
V_66 = V_70 ;
}
F_5 ( V_18 -> V_35 , V_71 , V_72 ,
V_73 ) ;
F_5 ( V_18 -> V_35 , V_74 , V_66 , V_65 ) ;
F_8 ( V_18 , V_37 -> V_51 ) ;
F_16 ( V_18 -> V_75 ) ;
F_5 ( V_18 -> V_35 , V_55 , V_76 , V_77 ) ;
return 0 ;
}
static void F_17 ( struct V_2 * V_3 , struct V_36 * V_37 )
{
struct V_1 * V_18 = F_1 ( V_3 ) ;
unsigned short V_65 , V_66 ;
if ( V_37 -> V_51 ) {
V_65 = V_78 ;
V_66 = V_68 ;
} else {
V_65 = V_79 ;
V_66 = V_70 ;
}
F_5 ( V_18 -> V_35 , V_71 , V_72 ,
V_80 ) ;
F_5 ( V_18 -> V_35 , V_74 , V_66 , V_65 ) ;
F_18 ( V_18 -> V_75 ) ;
F_5 ( V_18 -> V_35 , V_55 , V_76 , V_81 ) ;
F_13 ( V_3 -> V_52 ) ;
}
static void F_19 ( struct V_2 * V_3 , struct V_36 * V_37 )
{
struct V_1 * V_18 = F_1 ( V_3 ) ;
if ( F_20 ( V_82 , & V_37 -> V_83 ) ) {
F_21 ( V_3 -> V_52 , L_3 ) ;
F_13 ( V_3 -> V_52 ) ;
}
V_18 -> V_41 [ V_37 -> V_51 ] = 0 ;
}
static int F_22 ( struct V_84 * V_85 )
{
int V_86 ;
struct V_87 * V_88 ;
struct V_89 * V_89 ;
struct V_1 * V_18 ;
T_1 V_90 ;
struct V_91 * V_91 ;
V_91 = F_23 ( & V_85 -> V_52 ) ;
if ( F_24 ( V_91 ) )
F_21 ( & V_85 -> V_52 , L_4 ) ;
V_18 = F_25 ( & V_85 -> V_52 , sizeof( * V_18 ) , V_92 ) ;
if ( ! V_18 ) {
F_11 ( & V_85 -> V_52 , L_5 ) ;
return - V_93 ;
}
V_89 = F_26 ( & V_85 -> V_52 , L_6 ) ;
if ( F_24 ( V_89 ) ) {
F_11 ( & V_85 -> V_52 , L_7 ) ;
return F_27 ( V_89 ) ;
}
V_18 -> V_49 = F_28 ( V_89 ) ;
if ( ! V_18 -> V_49 ) {
F_11 ( & V_85 -> V_52 , L_8 ) ;
return - V_53 ;
}
V_18 -> V_3 . V_52 = & V_85 -> V_52 ;
V_18 -> V_3 . V_94 = & V_95 ;
V_18 -> V_3 . V_96 = V_97 ;
V_18 -> V_3 . V_98 = 3 ;
V_18 -> V_3 . V_4 = - 1 ;
V_18 -> V_3 . V_99 = V_50 ;
V_88 = F_29 ( V_85 , V_100 , 0 ) ;
if ( ! V_88 ) {
F_11 ( & V_85 -> V_52 , L_9 ) ;
return - V_101 ;
}
V_18 -> V_35 = F_30 ( & V_85 -> V_52 , V_88 ) ;
if ( ! V_18 -> V_35 )
return - V_102 ;
V_18 -> V_75 = F_26 ( & V_85 -> V_52 , L_10 ) ;
if ( F_24 ( V_18 -> V_75 ) ) {
F_11 ( & V_85 -> V_52 , L_11 ) ;
return F_27 ( V_18 -> V_75 ) ;
}
V_86 = F_31 ( & V_18 -> V_3 ) ;
if ( V_86 < 0 ) {
F_11 ( & V_85 -> V_52 , L_12 , V_86 ) ;
return V_86 ;
}
F_32 ( & V_85 -> V_52 ) ;
F_12 ( & V_85 -> V_52 ) ;
V_90 = F_33 ( V_85 -> V_52 . V_103 ,
V_104 ) ;
if ( ! ( V_90 & V_105 ) ) {
F_11 ( & V_85 -> V_52 , L_13 ) ;
V_86 = - V_53 ;
goto V_106;
}
F_13 ( & V_85 -> V_52 ) ;
F_34 ( V_85 , V_18 ) ;
return 0 ;
V_106:
F_13 ( & V_85 -> V_52 ) ;
F_35 ( & V_85 -> V_52 ) ;
F_36 ( & V_18 -> V_3 ) ;
return V_86 ;
}
static int F_37 ( struct V_84 * V_85 )
{
struct V_1 * V_18 = F_38 ( V_85 ) ;
F_12 ( & V_85 -> V_52 ) ;
F_33 ( V_85 -> V_52 . V_103 , V_107 ) ;
F_13 ( & V_85 -> V_52 ) ;
F_13 ( & V_85 -> V_52 ) ;
F_35 ( & V_85 -> V_52 ) ;
return F_36 ( & V_18 -> V_3 ) ;
}
