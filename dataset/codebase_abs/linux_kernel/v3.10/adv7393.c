static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static inline struct V_2 * F_3 ( struct V_4 * V_5 )
{
return & F_2 ( V_5 -> V_6 , struct V_1 , V_7 ) -> V_3 ;
}
static inline int F_4 ( struct V_2 * V_3 , T_1 V_8 , T_1 V_9 )
{
struct V_10 * V_11 = F_5 ( V_3 ) ;
return F_6 ( V_11 , V_8 , V_9 ) ;
}
static int F_7 ( struct V_2 * V_3 , T_2 V_12 )
{
struct V_1 * V_13 = F_1 ( V_3 ) ;
const struct V_14 * V_15 ;
int V_16 ;
T_1 V_8 ;
T_3 V_17 ;
int V_18 = 0 ;
int V_19 ;
V_16 = F_8 ( V_20 ) ;
for ( V_19 = 0 ; V_19 < V_16 ; V_19 ++ ) {
if ( V_20 [ V_19 ] . V_21 & V_12 )
break;
}
if ( V_19 == V_16 ) {
F_9 ( 1 , V_22 , V_3 ,
L_1 ,
( unsigned long long ) V_12 ) ;
return - V_23 ;
}
V_15 = & V_20 [ V_19 ] ;
V_17 = V_13 -> V_24 & ~ V_25 ;
V_17 |= V_15 -> V_26 ;
V_18 = F_4 ( V_3 , V_27 , V_17 ) ;
if ( V_18 < 0 )
goto V_28;
V_13 -> V_24 = V_17 ;
V_17 = V_13 -> V_29 & ~ V_30 ;
V_17 |= V_31 ;
V_18 = F_4 ( V_3 , V_32 , V_17 ) ;
if ( V_18 < 0 )
goto V_28;
V_13 -> V_29 = V_17 ;
V_17 = V_15 -> V_33 ;
for ( V_8 = V_34 ; V_8 <= V_35 ; V_8 ++ ) {
V_18 = F_4 ( V_3 , V_8 , V_17 ) ;
if ( V_18 < 0 )
goto V_28;
V_17 >>= 8 ;
}
V_17 = V_13 -> V_36 ;
if ( V_12 & ( V_37 | V_38 ) )
V_17 |= V_39 ;
else
V_17 &= V_40 ;
V_18 = F_4 ( V_3 , V_41 , V_17 ) ;
if ( V_18 < 0 )
goto V_28;
V_13 -> V_36 = V_17 ;
V_28:
if ( V_18 != 0 )
F_10 ( V_3 , L_2 ) ;
return V_18 ;
}
static int F_11 ( struct V_2 * V_3 , T_3 V_42 )
{
struct V_1 * V_13 = F_1 ( V_3 ) ;
T_1 V_17 ;
int V_18 = 0 ;
if ( V_42 > V_43 ) {
F_9 ( 1 , V_22 , V_3 ,
L_3 ,
V_42 ) ;
return - V_23 ;
}
V_17 = V_13 -> V_44 & 0x03 ;
if ( V_42 == V_45 )
V_17 |= V_46 ;
else if ( V_42 == V_47 )
V_17 |= V_48 ;
else
V_17 |= V_49 ;
V_18 = F_4 ( V_3 , V_50 , V_17 ) ;
if ( V_18 < 0 )
goto V_51;
V_13 -> V_44 = V_17 ;
V_17 = V_13 -> V_52 | V_53 ;
V_18 = F_4 ( V_3 , V_54 , V_17 ) ;
if ( V_18 < 0 )
goto V_51;
V_13 -> V_52 = V_17 ;
V_17 = V_13 -> V_36 ;
if ( V_42 == V_47 )
V_17 &= V_55 ;
else
V_17 |= V_56 ;
V_18 = F_4 ( V_3 , V_41 , V_17 ) ;
if ( V_18 < 0 )
goto V_51;
V_13 -> V_36 = V_17 ;
V_17 = V_13 -> V_57 & V_58 ;
V_18 = F_4 ( V_3 , V_59 , V_17 ) ;
if ( V_18 < 0 )
goto V_51;
V_13 -> V_57 = V_17 ;
V_51:
if ( V_18 != 0 )
F_10 ( V_3 , L_4 ) ;
return V_18 ;
}
static int F_12 ( struct V_2 * V_3 )
{
struct V_1 * V_13 = F_1 ( V_3 ) ;
F_13 ( V_3 , L_5 , ( unsigned long long ) V_13 -> V_12 ) ;
F_13 ( V_3 , L_6 , ( V_13 -> V_60 == 0 ) ? L_7 :
( ( V_13 -> V_60 == 1 ) ? L_8 : L_9 ) ) ;
return 0 ;
}
static int F_14 ( struct V_4 * V_5 )
{
struct V_2 * V_3 = F_3 ( V_5 ) ;
switch ( V_5 -> V_61 ) {
case V_62 :
return F_4 ( V_3 , V_63 ,
V_5 -> V_17 & V_64 ) ;
case V_65 :
return F_4 ( V_3 , V_66 ,
V_5 -> V_17 - V_67 ) ;
case V_68 :
return F_4 ( V_3 , V_69 ,
V_5 -> V_17 ) ;
}
return - V_23 ;
}
static int F_15 ( struct V_2 * V_3 ,
struct V_70 * V_71 )
{
struct V_10 * V_11 = F_5 ( V_3 ) ;
return F_16 ( V_11 , V_71 , V_72 , 0 ) ;
}
static int F_17 ( struct V_2 * V_3 , T_2 V_12 )
{
struct V_1 * V_13 = F_1 ( V_3 ) ;
int V_18 = 0 ;
if ( V_13 -> V_12 == V_12 )
return 0 ;
V_18 = F_7 ( V_3 , V_12 ) ;
if ( ! V_18 )
V_13 -> V_12 = V_12 ;
return V_18 ;
}
static int F_18 ( struct V_2 * V_3 ,
T_3 V_73 , T_3 V_60 , T_3 V_74 )
{
struct V_1 * V_13 = F_1 ( V_3 ) ;
int V_18 = 0 ;
if ( V_13 -> V_60 == V_60 )
return 0 ;
V_18 = F_11 ( V_3 , V_60 ) ;
if ( ! V_18 )
V_13 -> V_60 = V_60 ;
return V_18 ;
}
static int F_19 ( struct V_2 * V_3 )
{
struct V_1 * V_13 = F_1 ( V_3 ) ;
int V_18 = 0 ;
int V_19 ;
for ( V_19 = 0 ; V_19 < F_8 ( V_75 ) ; V_19 += 2 ) {
V_18 = F_4 ( V_3 , V_75 [ V_19 ] ,
V_75 [ V_19 + 1 ] ) ;
if ( V_18 ) {
F_10 ( V_3 , L_10 ) ;
return V_18 ;
}
}
V_18 = F_11 ( V_3 , V_13 -> V_60 ) ;
if ( V_18 < 0 ) {
F_10 ( V_3 , L_11 ) ;
return - V_23 ;
}
V_18 = F_7 ( V_3 , V_13 -> V_12 ) ;
if ( V_18 < 0 ) {
F_10 ( V_3 , L_12 ) ;
return - V_23 ;
}
return V_18 ;
}
static int F_20 ( struct V_10 * V_11 ,
const struct V_76 * V_61 )
{
struct V_1 * V_13 ;
int V_18 ;
if ( ! F_21 ( V_11 -> V_77 , V_78 ) )
return - V_79 ;
F_22 ( V_11 , L_13 ,
V_11 -> V_80 << 1 , V_11 -> V_77 -> V_81 ) ;
V_13 = F_23 ( sizeof( struct V_1 ) , V_82 ) ;
if ( V_13 == NULL )
return - V_83 ;
V_13 -> V_44 = V_84 ;
V_13 -> V_29 = 0x00 ;
V_13 -> V_52 = 0x20 ;
V_13 -> V_57 = V_85 ;
V_13 -> V_24 = V_86 ;
V_13 -> V_36 = V_87 ;
V_13 -> V_60 = V_45 ;
V_13 -> V_12 = V_37 ;
F_24 ( & V_13 -> V_3 , V_11 , & V_88 ) ;
F_25 ( & V_13 -> V_7 , 3 ) ;
F_26 ( & V_13 -> V_7 , & V_89 ,
V_62 , V_90 ,
V_91 , 1 ,
V_92 ) ;
F_26 ( & V_13 -> V_7 , & V_89 ,
V_65 , V_67 ,
V_93 , 1 ,
V_94 ) ;
F_26 ( & V_13 -> V_7 , & V_89 ,
V_68 , V_95 ,
V_96 , 1 ,
V_97 ) ;
V_13 -> V_3 . V_98 = & V_13 -> V_7 ;
if ( V_13 -> V_7 . error ) {
int V_18 = V_13 -> V_7 . error ;
F_27 ( & V_13 -> V_7 ) ;
F_28 ( V_13 ) ;
return V_18 ;
}
F_29 ( & V_13 -> V_7 ) ;
V_18 = F_19 ( & V_13 -> V_3 ) ;
if ( V_18 ) {
F_27 ( & V_13 -> V_7 ) ;
F_28 ( V_13 ) ;
}
return V_18 ;
}
static int F_30 ( struct V_10 * V_11 )
{
struct V_2 * V_3 = F_31 ( V_11 ) ;
struct V_1 * V_13 = F_1 ( V_3 ) ;
F_32 ( V_3 ) ;
F_27 ( & V_13 -> V_7 ) ;
F_28 ( V_13 ) ;
return 0 ;
}
