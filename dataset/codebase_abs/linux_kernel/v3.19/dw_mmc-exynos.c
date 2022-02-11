static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
if ( V_4 -> V_5 == V_6 ||
V_4 -> V_5 == V_7 ) {
F_2 ( V_2 , V_8 , 0 ) ;
F_2 ( V_2 , V_9 , V_10 ) ;
F_2 ( V_2 , V_11 , V_12 |
V_13 |
V_14 |
V_15 ) ;
}
return 0 ;
}
static int F_3 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
unsigned long V_16 = F_4 ( V_2 -> V_17 ) ;
V_2 -> V_18 = V_16 / ( V_4 -> V_19 + 1 ) ;
return 0 ;
}
static int F_5 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = F_6 ( V_21 ) ;
return F_7 ( V_2 ) ;
}
static int F_8 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = F_6 ( V_21 ) ;
F_1 ( V_2 ) ;
return F_9 ( V_2 ) ;
}
static int F_10 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = F_6 ( V_21 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
T_1 V_22 ;
if ( V_4 -> V_5 == V_23 ||
V_4 -> V_5 == V_7 )
V_22 = F_11 ( V_2 , V_24 ) ;
else
V_22 = F_11 ( V_2 , V_25 ) ;
if ( V_22 & V_26 ) {
if ( V_4 -> V_5 == V_23 ||
V_4 -> V_5 == V_7 )
F_2 ( V_2 , V_24 , V_22 ) ;
else
F_2 ( V_2 , V_25 , V_22 ) ;
}
return 0 ;
}
static void F_12 ( struct V_1 * V_2 , T_1 * V_27 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
if ( V_4 -> V_5 == V_23 ||
V_4 -> V_5 == V_7 ) {
if ( F_13 ( F_11 ( V_2 , V_24 ) ) )
* V_27 |= V_28 ;
} else {
if ( F_13 ( F_11 ( V_2 , V_25 ) ) )
* V_27 |= V_28 ;
}
}
static void F_14 ( struct V_1 * V_2 , struct V_29 * V_30 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
unsigned int V_31 = V_30 -> clock ;
unsigned long V_32 ;
T_2 div = V_4 -> V_19 + 1 ;
if ( V_30 -> V_33 == V_34 ) {
if ( V_4 -> V_5 == V_23 ||
V_4 -> V_5 == V_7 )
F_2 ( V_2 , V_24 , V_4 -> V_35 ) ;
else
F_2 ( V_2 , V_25 , V_4 -> V_35 ) ;
if ( V_30 -> V_36 == V_37 )
V_31 <<= 1 ;
} else {
if ( V_4 -> V_5 == V_23 ||
V_4 -> V_5 == V_7 )
F_2 ( V_2 , V_24 , V_4 -> V_38 ) ;
else
F_2 ( V_2 , V_25 , V_4 -> V_38 ) ;
}
if ( ! V_31 )
return;
if ( V_31 < V_39 )
V_31 = V_39 ;
if ( V_31 != V_4 -> V_40 ) {
int V_41 = F_15 ( V_2 -> V_17 , V_31 * div ) ;
if ( V_41 )
F_16 ( V_2 -> V_21 ,
L_1 ,
V_31 * div , V_41 ) ;
V_32 = F_4 ( V_2 -> V_17 ) ;
V_2 -> V_18 = V_32 / div ;
V_4 -> V_40 = V_31 ;
V_2 -> V_42 = 0 ;
}
}
static int F_17 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_43 * V_44 = V_2 -> V_21 -> V_45 ;
T_1 V_33 [ 2 ] ;
T_1 div = 0 ;
int V_46 ;
int V_41 ;
V_4 = F_18 ( V_2 -> V_21 , sizeof( * V_4 ) , V_47 ) ;
if ( ! V_4 ) {
F_19 ( V_2 -> V_21 , L_2 ) ;
return - V_48 ;
}
for ( V_46 = 0 ; V_46 < F_20 ( V_49 ) ; V_46 ++ ) {
if ( F_21 ( V_44 , V_49 [ V_46 ] . V_50 ) )
V_4 -> V_5 = V_49 [ V_46 ] . V_5 ;
}
if ( V_4 -> V_5 == V_51 )
V_4 -> V_19 = V_52 - 1 ;
else if ( V_4 -> V_5 == V_53 )
V_4 -> V_19 = V_54 - 1 ;
else {
F_22 ( V_44 , L_3 , & div ) ;
V_4 -> V_19 = div ;
}
V_41 = F_23 ( V_44 ,
L_4 , V_33 , 2 ) ;
if ( V_41 )
return V_41 ;
V_4 -> V_38 = F_24 ( V_33 [ 0 ] , V_33 [ 1 ] , div ) ;
V_41 = F_23 ( V_44 ,
L_5 , V_33 , 2 ) ;
if ( V_41 )
return V_41 ;
V_4 -> V_35 = F_24 ( V_33 [ 0 ] , V_33 [ 1 ] , div ) ;
V_2 -> V_4 = V_4 ;
return 0 ;
}
static inline T_2 F_25 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
if ( V_4 -> V_5 == V_23 ||
V_4 -> V_5 == V_7 )
return F_26 ( F_11 ( V_2 , V_24 ) ) ;
else
return F_26 ( F_11 ( V_2 , V_25 ) ) ;
}
static inline void F_27 ( struct V_1 * V_2 , T_2 V_55 )
{
T_1 V_22 ;
struct V_3 * V_4 = V_2 -> V_4 ;
if ( V_4 -> V_5 == V_23 ||
V_4 -> V_5 == V_7 )
V_22 = F_11 ( V_2 , V_24 ) ;
else
V_22 = F_11 ( V_2 , V_25 ) ;
V_22 = ( V_22 & ~ 0x7 ) | F_26 ( V_55 ) ;
if ( V_4 -> V_5 == V_23 ||
V_4 -> V_5 == V_7 )
F_2 ( V_2 , V_24 , V_22 ) ;
else
F_2 ( V_2 , V_25 , V_22 ) ;
}
static inline T_2 F_28 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
T_1 V_22 ;
T_2 V_55 ;
if ( V_4 -> V_5 == V_23 ||
V_4 -> V_5 == V_7 )
V_22 = F_11 ( V_2 , V_24 ) ;
else
V_22 = F_11 ( V_2 , V_25 ) ;
V_55 = ( V_22 + 1 ) & 0x7 ;
V_22 = ( V_22 & ~ 0x7 ) | V_55 ;
if ( V_4 -> V_5 == V_23 ||
V_4 -> V_5 == V_7 )
F_2 ( V_2 , V_24 , V_22 ) ;
else
F_2 ( V_2 , V_25 , V_22 ) ;
return V_55 ;
}
static T_3 F_29 ( T_2 V_56 )
{
const T_2 V_57 = 8 ;
T_2 V_58 ;
T_3 V_59 , V_60 = - 1 ;
for ( V_59 = 0 ; V_59 < V_57 ; V_59 ++ ) {
V_58 = F_30 ( V_56 , V_59 ) ;
if ( ( V_58 & 0xc7 ) == 0xc7 ) {
V_60 = V_59 ;
goto V_61;
}
}
for ( V_59 = 0 ; V_59 < V_57 ; V_59 ++ ) {
V_58 = F_30 ( V_56 , V_59 ) ;
if ( ( V_58 & 0x83 ) == 0x83 ) {
V_60 = V_59 ;
goto V_61;
}
}
V_61:
return V_60 ;
}
static int F_31 ( struct V_62 * V_63 , T_1 V_64 ,
struct V_65 * V_66 )
{
struct V_1 * V_2 = V_63 -> V_2 ;
struct V_67 * V_68 = V_63 -> V_68 ;
const T_2 * V_69 = V_66 -> V_69 ;
T_2 * V_70 ;
unsigned int V_71 = V_66 -> V_71 ;
T_2 V_72 , V_73 , V_56 = 0 ;
T_3 V_74 = - 1 ;
int V_41 = 0 ;
V_70 = F_32 ( V_71 , V_47 ) ;
if ( ! V_70 )
return - V_48 ;
V_72 = F_25 ( V_2 ) ;
do {
struct V_75 V_76 = { NULL } ;
struct V_77 V_78 = { 0 } ;
struct V_77 V_79 = { 0 } ;
struct V_80 V_81 = { 0 } ;
struct V_82 V_83 ;
V_78 . V_64 = V_64 ;
V_78 . V_84 = 0 ;
V_78 . V_85 = V_86 | V_87 ;
V_79 . V_64 = V_88 ;
V_79 . V_84 = 0 ;
V_79 . V_85 = V_89 | V_90 ;
V_81 . V_71 = V_71 ;
V_81 . V_91 = 1 ;
V_81 . V_85 = V_92 ;
V_81 . V_83 = & V_83 ;
V_81 . V_93 = 1 ;
F_33 ( & V_83 , V_70 , V_71 ) ;
V_76 . V_78 = & V_78 ;
V_76 . V_79 = & V_79 ;
V_76 . V_81 = & V_81 ;
V_2 -> V_76 = & V_76 ;
F_2 ( V_2 , V_94 , ~ 0 ) ;
V_73 = F_28 ( V_2 ) ;
F_34 ( V_68 , & V_76 ) ;
if ( ! V_78 . error && ! V_81 . error ) {
if ( ! memcmp ( V_69 , V_70 , V_71 ) )
V_56 |= ( 1 << V_73 ) ;
} else {
F_35 ( V_2 -> V_21 ,
L_6 ,
V_78 . error , V_81 . error ) ;
}
} while ( V_72 != V_73 );
V_74 = F_29 ( V_56 ) ;
if ( V_74 >= 0 )
F_27 ( V_2 , V_74 ) ;
else
V_41 = - V_95 ;
F_36 ( V_70 ) ;
return V_41 ;
}
static int F_37 ( struct V_96 * V_97 )
{
const struct V_98 * V_99 ;
const struct V_100 * V_101 ;
V_101 = F_38 ( V_102 , V_97 -> V_21 . V_45 ) ;
V_99 = V_101 -> V_81 ;
return F_39 ( V_97 , V_99 ) ;
}
