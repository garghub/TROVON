static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
if ( V_4 -> V_5 == V_6 ) {
F_2 ( V_2 , V_7 , 0 ) ;
F_2 ( V_2 , V_8 , V_9 ) ;
F_2 ( V_2 , V_10 , V_11 |
V_12 |
V_13 |
V_14 ) ;
}
return 0 ;
}
static int F_3 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
unsigned long V_15 = F_4 ( V_2 -> V_16 ) ;
V_2 -> V_17 = V_15 / ( V_4 -> V_18 + 1 ) ;
return 0 ;
}
static int F_5 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = F_6 ( V_20 ) ;
return F_7 ( V_2 ) ;
}
static int F_8 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = F_6 ( V_20 ) ;
F_1 ( V_2 ) ;
return F_9 ( V_2 ) ;
}
static int F_10 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = F_6 ( V_20 ) ;
T_1 V_21 ;
V_21 = F_11 ( V_2 , V_22 ) ;
if ( V_21 & V_23 )
F_2 ( V_2 , V_22 , V_21 ) ;
return 0 ;
}
static void F_12 ( struct V_1 * V_2 , T_1 * V_24 )
{
if ( F_13 ( F_11 ( V_2 , V_22 ) ) )
* V_24 |= V_25 ;
}
static void F_14 ( struct V_1 * V_2 , struct V_26 * V_27 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
unsigned int V_28 = V_27 -> clock ;
unsigned long V_29 ;
T_2 div = V_4 -> V_18 + 1 ;
if ( V_27 -> V_30 == V_31 ) {
F_2 ( V_2 , V_22 , V_4 -> V_32 ) ;
if ( V_27 -> V_33 == V_34 )
V_28 <<= 1 ;
} else {
F_2 ( V_2 , V_22 , V_4 -> V_35 ) ;
}
if ( ! V_28 )
return;
if ( V_28 < V_36 )
V_28 = V_36 ;
if ( V_28 != V_4 -> V_37 ) {
int V_38 = F_15 ( V_2 -> V_16 , V_28 * div ) ;
if ( V_38 )
F_16 ( V_2 -> V_20 ,
L_1 ,
V_28 * div , V_38 ) ;
V_29 = F_4 ( V_2 -> V_16 ) ;
V_2 -> V_17 = V_29 / div ;
V_4 -> V_37 = V_28 ;
V_2 -> V_39 = 0 ;
}
}
static int F_17 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_40 * V_41 = V_2 -> V_20 -> V_42 ;
T_1 V_30 [ 2 ] ;
T_1 div = 0 ;
int V_43 ;
int V_38 ;
V_4 = F_18 ( V_2 -> V_20 , sizeof( * V_4 ) , V_44 ) ;
if ( ! V_4 ) {
F_19 ( V_2 -> V_20 , L_2 ) ;
return - V_45 ;
}
for ( V_43 = 0 ; V_43 < F_20 ( V_46 ) ; V_43 ++ ) {
if ( F_21 ( V_41 , V_46 [ V_43 ] . V_47 ) )
V_4 -> V_5 = V_46 [ V_43 ] . V_5 ;
}
if ( V_4 -> V_5 == V_48 )
V_4 -> V_18 = V_49 - 1 ;
else if ( V_4 -> V_5 == V_50 )
V_4 -> V_18 = V_51 - 1 ;
else {
F_22 ( V_41 , L_3 , & div ) ;
V_4 -> V_18 = div ;
}
V_38 = F_23 ( V_41 ,
L_4 , V_30 , 2 ) ;
if ( V_38 )
return V_38 ;
V_4 -> V_35 = F_24 ( V_30 [ 0 ] , V_30 [ 1 ] , div ) ;
V_38 = F_23 ( V_41 ,
L_5 , V_30 , 2 ) ;
if ( V_38 )
return V_38 ;
V_4 -> V_32 = F_24 ( V_30 [ 0 ] , V_30 [ 1 ] , div ) ;
V_2 -> V_4 = V_4 ;
return 0 ;
}
static inline T_2 F_25 ( struct V_1 * V_2 )
{
return F_26 ( F_11 ( V_2 , V_22 ) ) ;
}
static inline void F_27 ( struct V_1 * V_2 , T_2 V_52 )
{
T_1 V_21 ;
V_21 = F_11 ( V_2 , V_22 ) ;
V_21 = ( V_21 & ~ 0x7 ) | F_26 ( V_52 ) ;
F_2 ( V_2 , V_22 , V_21 ) ;
}
static inline T_2 F_28 ( struct V_1 * V_2 )
{
T_1 V_21 ;
T_2 V_52 ;
V_21 = F_11 ( V_2 , V_22 ) ;
V_52 = ( V_21 + 1 ) & 0x7 ;
V_21 = ( V_21 & ~ 0x7 ) | V_52 ;
F_2 ( V_2 , V_22 , V_21 ) ;
return V_52 ;
}
static T_3 F_29 ( T_2 V_53 )
{
const T_2 V_54 = 8 ;
T_2 V_55 ;
T_3 V_56 , V_57 = - 1 ;
for ( V_56 = 0 ; V_56 < V_54 ; V_56 ++ ) {
V_55 = F_30 ( V_53 , V_56 ) ;
if ( ( V_55 & 0xc7 ) == 0xc7 ) {
V_57 = V_56 ;
goto V_58;
}
}
for ( V_56 = 0 ; V_56 < V_54 ; V_56 ++ ) {
V_55 = F_30 ( V_53 , V_56 ) ;
if ( ( V_55 & 0x83 ) == 0x83 ) {
V_57 = V_56 ;
goto V_58;
}
}
V_58:
return V_57 ;
}
static int F_31 ( struct V_59 * V_60 , T_1 V_61 ,
struct V_62 * V_63 )
{
struct V_1 * V_2 = V_60 -> V_2 ;
struct V_64 * V_65 = V_60 -> V_65 ;
const T_2 * V_66 = V_63 -> V_66 ;
T_2 * V_67 ;
unsigned int V_68 = V_63 -> V_68 ;
T_2 V_69 , V_70 , V_53 = 0 ;
T_3 V_71 = - 1 ;
int V_38 = 0 ;
V_67 = F_32 ( V_68 , V_44 ) ;
if ( ! V_67 )
return - V_45 ;
V_69 = F_25 ( V_2 ) ;
do {
struct V_72 V_73 = { NULL } ;
struct V_74 V_75 = { 0 } ;
struct V_74 V_76 = { 0 } ;
struct V_77 V_78 = { 0 } ;
struct V_79 V_80 ;
V_75 . V_61 = V_61 ;
V_75 . V_81 = 0 ;
V_75 . V_82 = V_83 | V_84 ;
V_76 . V_61 = V_85 ;
V_76 . V_81 = 0 ;
V_76 . V_82 = V_86 | V_87 ;
V_78 . V_68 = V_68 ;
V_78 . V_88 = 1 ;
V_78 . V_82 = V_89 ;
V_78 . V_80 = & V_80 ;
V_78 . V_90 = 1 ;
F_33 ( & V_80 , V_67 , V_68 ) ;
V_73 . V_75 = & V_75 ;
V_73 . V_76 = & V_76 ;
V_73 . V_78 = & V_78 ;
V_2 -> V_73 = & V_73 ;
F_2 ( V_2 , V_91 , ~ 0 ) ;
V_70 = F_28 ( V_2 ) ;
F_34 ( V_65 , & V_73 ) ;
if ( ! V_75 . error && ! V_78 . error ) {
if ( ! memcmp ( V_66 , V_67 , V_68 ) )
V_53 |= ( 1 << V_70 ) ;
} else {
F_35 ( V_2 -> V_20 ,
L_6 ,
V_75 . error , V_78 . error ) ;
}
} while ( V_69 != V_70 );
V_71 = F_29 ( V_53 ) ;
if ( V_71 >= 0 )
F_27 ( V_2 , V_71 ) ;
else
V_38 = - V_92 ;
F_36 ( V_67 ) ;
return V_38 ;
}
static int F_37 ( struct V_93 * V_94 )
{
const struct V_95 * V_96 ;
const struct V_97 * V_98 ;
V_98 = F_38 ( V_99 , V_94 -> V_20 . V_42 ) ;
V_96 = V_98 -> V_78 ;
return F_39 ( V_94 , V_96 ) ;
}
