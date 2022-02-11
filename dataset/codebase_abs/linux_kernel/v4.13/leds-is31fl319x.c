static int F_1 ( struct V_1 * V_2 ,
enum V_3 V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 , struct V_5 ,
V_2 ) ;
struct V_7 * V_8 = V_6 -> V_9 ;
int V_10 = V_6 - V_8 -> V_11 ;
int V_12 ;
int V_13 ;
T_1 V_14 = 0 , V_15 = 0 ;
F_3 ( & V_8 -> V_16 -> V_17 , L_1 , V_18 , V_10 , V_4 ) ;
F_4 ( & V_8 -> V_19 ) ;
V_12 = F_5 ( V_8 -> V_20 , F_6 ( V_10 ) , V_4 ) ;
if ( V_12 < 0 )
goto V_21;
for ( V_13 = 0 ; V_13 < V_8 -> V_22 -> V_23 ; V_13 ++ ) {
unsigned int V_24 ;
bool V_25 ;
V_12 = F_7 ( V_8 -> V_20 , F_6 ( V_13 ) , & V_24 ) ;
F_3 ( & V_8 -> V_16 -> V_17 , L_2 ,
V_18 , V_13 , V_12 , V_24 ) ;
V_25 = V_12 >= 0 && V_24 > V_26 ;
if ( V_13 < 3 )
V_14 |= V_25 << V_13 ;
else if ( V_13 < 6 )
V_14 |= V_25 << ( V_13 + 1 ) ;
else
V_15 |= V_25 << ( V_13 - 6 ) ;
}
if ( V_14 > 0 || V_15 > 0 ) {
F_3 ( & V_8 -> V_16 -> V_17 , L_3 ,
V_14 , V_15 ) ;
F_5 ( V_8 -> V_20 , V_27 , V_14 ) ;
F_5 ( V_8 -> V_20 , V_28 , V_15 ) ;
F_5 ( V_8 -> V_20 , V_29 , 0x00 ) ;
V_12 = F_5 ( V_8 -> V_20 , V_30 , 0x01 ) ;
} else {
F_3 ( & V_8 -> V_16 -> V_17 , L_4 ) ;
V_12 = F_5 ( V_8 -> V_20 , V_30 , 0x00 ) ;
}
V_21:
F_8 ( & V_8 -> V_19 ) ;
return V_12 ;
}
static int F_9 ( const struct V_31 * V_17 ,
const struct V_32 * V_33 ,
struct V_5 * V_6 )
{
struct V_1 * V_2 = & V_6 -> V_2 ;
int V_12 ;
if ( F_10 ( V_33 , L_5 , & V_2 -> V_34 ) )
V_2 -> V_34 = V_33 -> V_34 ;
V_12 = F_10 ( V_33 , L_6 ,
& V_2 -> V_35 ) ;
if ( V_12 < 0 && V_12 != - V_36 )
return V_12 ;
V_6 -> V_37 = V_38 ;
V_12 = F_11 ( V_33 , L_7 ,
& V_6 -> V_37 ) ;
if ( ! V_12 ) {
if ( V_6 -> V_37 < V_39 )
return - V_36 ;
V_6 -> V_37 = F_12 ( V_6 -> V_37 ,
V_40 ) ;
}
return 0 ;
}
static int F_13 ( struct V_31 * V_17 ,
struct V_7 * V_8 )
{
struct V_32 * V_41 = V_17 -> V_42 , * V_33 ;
const struct V_43 * V_44 ;
int V_45 ;
int V_12 ;
if ( ! V_41 )
return - V_46 ;
V_44 = F_14 ( V_47 , V_17 ) ;
if ( ! V_44 ) {
F_15 ( V_17 , L_8 ) ;
return - V_36 ;
}
V_8 -> V_22 = V_44 -> V_48 ;
V_45 = F_16 ( V_41 ) ;
F_3 ( V_17 , L_9 ,
V_44 -> V_49 , V_45 ) ;
if ( ! V_45 || V_45 > V_8 -> V_22 -> V_23 ) {
F_15 ( V_17 , L_10 ,
V_8 -> V_22 -> V_23 ) ;
return - V_46 ;
}
F_17 (np, child) {
struct V_5 * V_6 ;
T_2 V_50 ;
V_12 = F_11 ( V_33 , L_11 , & V_50 ) ;
if ( V_12 ) {
F_15 ( V_17 , L_12 ) ;
goto V_51;
}
if ( V_50 < 1 || V_50 > V_8 -> V_22 -> V_23 ) {
F_15 ( V_17 , L_13 , V_50 ) ;
V_12 = - V_36 ;
goto V_51;
}
V_6 = & V_8 -> V_11 [ V_50 - 1 ] ;
if ( V_6 -> V_52 ) {
F_15 ( V_17 , L_14 , V_50 ) ;
V_12 = - V_36 ;
goto V_51;
}
V_12 = F_9 ( V_17 , V_33 , V_6 ) ;
if ( V_12 ) {
F_15 ( V_17 , L_15 , V_50 ) ;
goto V_51;
}
V_6 -> V_52 = true ;
}
V_8 -> V_53 = 0 ;
V_12 = F_11 ( V_41 , L_16 , & V_8 -> V_53 ) ;
if ( ! V_12 )
V_8 -> V_53 = F_12 ( V_8 -> V_53 ,
V_54 ) ;
return 0 ;
V_51:
F_18 ( V_33 ) ;
return V_12 ;
}
static bool F_19 ( struct V_31 * V_17 , unsigned int V_50 )
{
return false ;
}
static bool F_20 ( struct V_31 * V_17 , unsigned int V_50 )
{
switch ( V_50 ) {
case V_29 :
case V_55 :
case V_56 :
return true ;
default:
return false ;
}
}
static inline int F_21 ( struct V_31 * V_17 , T_2 V_57 )
{
T_2 V_58 = V_57 / V_59 ;
return ( ( V_60 - V_58 ) &
V_61 ) <<
V_62 ;
}
static inline int F_22 ( T_2 V_63 )
{
return V_63 / V_64 ;
}
static int F_23 ( struct V_65 * V_16 ,
const struct V_66 * V_67 )
{
struct V_7 * V_8 ;
struct V_31 * V_17 = & V_16 -> V_17 ;
struct V_68 * V_69 = F_24 ( V_17 -> V_70 ) ;
int V_71 ;
int V_13 = 0 ;
T_2 V_72 = V_40 ;
if ( ! F_25 ( V_69 , V_73 ) )
return - V_74 ;
V_8 = F_26 ( & V_16 -> V_17 , sizeof( * V_8 ) , V_75 ) ;
if ( ! V_8 )
return - V_76 ;
F_27 ( & V_8 -> V_19 ) ;
V_71 = F_13 ( & V_16 -> V_17 , V_8 ) ;
if ( V_71 )
goto V_77;
V_8 -> V_16 = V_16 ;
V_8 -> V_20 = F_28 ( V_16 , & V_78 ) ;
if ( F_29 ( V_8 -> V_20 ) ) {
F_15 ( & V_16 -> V_17 , L_17 ) ;
V_71 = F_30 ( V_8 -> V_20 ) ;
goto V_77;
}
F_31 ( V_16 , V_8 ) ;
V_71 = F_5 ( V_8 -> V_20 , V_56 , 0x00 ) ;
if ( V_71 < 0 ) {
F_15 ( & V_16 -> V_17 , L_18 ,
V_71 ) ;
V_71 = - V_74 ;
goto V_77;
}
for ( V_13 = 0 ; V_13 < V_8 -> V_22 -> V_23 ; V_13 ++ )
if ( V_8 -> V_11 [ V_13 ] . V_52 &&
V_8 -> V_11 [ V_13 ] . V_37 < V_72 )
V_72 = V_8 -> V_11 [ V_13 ] . V_37 ;
F_5 ( V_8 -> V_20 , V_79 ,
F_21 ( V_17 , V_72 ) |
F_22 ( V_8 -> V_53 ) ) ;
for ( V_13 = 0 ; V_13 < V_8 -> V_22 -> V_23 ; V_13 ++ ) {
struct V_5 * V_6 = & V_8 -> V_11 [ V_13 ] ;
if ( ! V_6 -> V_52 )
continue;
V_6 -> V_9 = V_8 ;
V_6 -> V_2 . V_80 = F_1 ;
V_71 = F_32 ( & V_16 -> V_17 , & V_6 -> V_2 ) ;
if ( V_71 < 0 )
goto V_77;
}
return 0 ;
V_77:
F_33 ( & V_8 -> V_19 ) ;
return V_71 ;
}
static int F_34 ( struct V_65 * V_16 )
{
struct V_7 * V_8 = F_35 ( V_16 ) ;
F_33 ( & V_8 -> V_19 ) ;
return 0 ;
}
