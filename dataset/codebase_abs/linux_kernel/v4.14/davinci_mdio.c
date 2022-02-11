static void F_1 ( struct V_1 * V_2 )
{
T_1 V_3 , div , V_4 , V_5 ;
V_3 = F_2 ( V_2 -> V_6 ) ;
div = ( V_3 / V_2 -> V_7 . V_8 ) - 1 ;
if ( div > V_9 )
div = V_9 ;
V_2 -> V_10 = div ;
V_4 = V_3 / ( 1000 * ( div + 1 ) ) ;
V_5 = ( 88 * 1000 ) / V_4 ;
V_2 -> V_5 = F_3 ( V_5 * 4 ) ;
if ( ! V_2 -> V_5 )
V_2 -> V_5 = 1 ;
}
static void F_4 ( struct V_1 * V_2 )
{
F_5 ( V_2 -> V_10 | V_11 , & V_2 -> V_12 -> V_13 ) ;
}
static int F_6 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
T_1 V_17 , V_18 ;
int V_19 ;
V_19 = F_7 ( V_2 -> V_20 ) ;
if ( V_19 < 0 ) {
F_8 ( V_2 -> V_20 ) ;
return V_19 ;
}
F_9 ( V_21 * V_2 -> V_5 ) ;
V_18 = F_10 ( & V_2 -> V_12 -> V_22 ) ;
F_11 ( V_2 -> V_20 ,
L_1 ,
( V_18 >> 8 ) & 0xff , V_18 & 0xff ,
V_2 -> V_7 . V_8 ) ;
if ( V_2 -> V_23 )
goto V_24;
V_17 = F_10 ( & V_2 -> V_12 -> V_25 ) ;
if ( V_17 ) {
F_11 ( V_2 -> V_20 , L_2 , ~ V_17 ) ;
V_17 = ~ V_17 ;
} else {
F_12 ( V_2 -> V_20 , L_3 ) ;
V_17 = 0 ;
}
V_2 -> V_15 -> V_17 = V_17 ;
V_24:
F_13 ( V_2 -> V_20 ) ;
F_14 ( V_2 -> V_20 ) ;
return 0 ;
}
static inline int F_15 ( struct V_1 * V_2 )
{
struct V_26 T_2 * V_12 = V_2 -> V_12 ;
unsigned long V_27 = V_28 + F_16 ( V_29 ) ;
T_1 V_30 ;
while ( F_17 ( V_27 , V_28 ) ) {
V_30 = F_10 ( & V_12 -> V_31 [ 0 ] . V_32 ) ;
if ( ( V_30 & V_33 ) == 0 )
return 0 ;
V_30 = F_10 ( & V_12 -> V_13 ) ;
if ( ( V_30 & V_34 ) == 0 ) {
F_18 ( 100 , 200 ) ;
continue;
}
F_12 ( V_2 -> V_20 , L_4 ) ;
F_4 ( V_2 ) ;
return - V_35 ;
}
V_30 = F_10 ( & V_12 -> V_31 [ 0 ] . V_32 ) ;
if ( ( V_30 & V_33 ) == 0 )
return 0 ;
F_19 ( V_2 -> V_20 , L_5 ) ;
return - V_36 ;
}
static inline int F_20 ( struct V_1 * V_2 )
{
struct V_26 T_2 * V_12 = V_2 -> V_12 ;
unsigned long V_27 = V_28 + F_16 ( V_29 ) ;
while ( F_17 ( V_27 , V_28 ) ) {
if ( F_10 ( & V_12 -> V_13 ) & V_34 )
return 0 ;
}
F_19 ( V_2 -> V_20 , L_6 ) ;
return - V_36 ;
}
static int F_21 ( struct V_14 * V_15 , int V_37 , int V_38 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
T_1 V_30 ;
int V_19 ;
if ( V_38 & ~ V_39 || V_37 & ~ V_40 )
return - V_41 ;
V_19 = F_7 ( V_2 -> V_20 ) ;
if ( V_19 < 0 ) {
F_8 ( V_2 -> V_20 ) ;
return V_19 ;
}
V_30 = ( V_33 | V_42 | ( V_38 << 21 ) |
( V_37 << 16 ) ) ;
while ( 1 ) {
V_19 = F_15 ( V_2 ) ;
if ( V_19 == - V_35 )
continue;
if ( V_19 < 0 )
break;
F_5 ( V_30 , & V_2 -> V_12 -> V_31 [ 0 ] . V_32 ) ;
V_19 = F_15 ( V_2 ) ;
if ( V_19 == - V_35 )
continue;
if ( V_19 < 0 )
break;
V_30 = F_10 ( & V_2 -> V_12 -> V_31 [ 0 ] . V_32 ) ;
V_19 = ( V_30 & V_43 ) ? ( V_30 & V_44 ) : - V_45 ;
break;
}
F_13 ( V_2 -> V_20 ) ;
F_14 ( V_2 -> V_20 ) ;
return V_19 ;
}
static int F_22 ( struct V_14 * V_15 , int V_37 ,
int V_38 , T_3 V_46 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
T_1 V_30 ;
int V_19 ;
if ( V_38 & ~ V_39 || V_37 & ~ V_40 )
return - V_41 ;
V_19 = F_7 ( V_2 -> V_20 ) ;
if ( V_19 < 0 ) {
F_8 ( V_2 -> V_20 ) ;
return V_19 ;
}
V_30 = ( V_33 | V_47 | ( V_38 << 21 ) |
( V_37 << 16 ) | ( V_46 & V_44 ) ) ;
while ( 1 ) {
V_19 = F_15 ( V_2 ) ;
if ( V_19 == - V_35 )
continue;
if ( V_19 < 0 )
break;
F_5 ( V_30 , & V_2 -> V_12 -> V_31 [ 0 ] . V_32 ) ;
V_19 = F_15 ( V_2 ) ;
if ( V_19 == - V_35 )
continue;
break;
}
F_13 ( V_2 -> V_20 ) ;
F_14 ( V_2 -> V_20 ) ;
return V_19 ;
}
static int F_23 ( struct V_48 * V_2 ,
struct V_49 * V_50 )
{
struct V_51 * V_52 = V_50 -> V_20 . V_53 ;
T_1 V_54 ;
if ( ! V_52 )
return - V_41 ;
if ( F_24 ( V_52 , L_7 , & V_54 ) ) {
F_19 ( & V_50 -> V_20 , L_8 ) ;
return - V_41 ;
}
V_2 -> V_8 = V_54 ;
return 0 ;
}
static int F_25 ( struct V_49 * V_50 )
{
struct V_48 * V_7 = F_26 ( & V_50 -> V_20 ) ;
struct V_55 * V_20 = & V_50 -> V_20 ;
struct V_1 * V_2 ;
struct V_56 * V_57 ;
struct V_58 * V_59 ;
int V_19 , V_60 ;
int V_61 = - 1 ;
V_2 = F_27 ( V_20 , sizeof( * V_2 ) , V_62 ) ;
if ( ! V_2 )
return - V_63 ;
V_2 -> V_15 = F_28 ( V_20 ) ;
if ( ! V_2 -> V_15 ) {
F_19 ( V_20 , L_9 ) ;
return - V_63 ;
}
if ( V_20 -> V_53 ) {
const struct V_64 * V_65 ;
V_19 = F_23 ( & V_2 -> V_7 , V_50 ) ;
if ( V_19 )
return V_19 ;
snprintf ( V_2 -> V_15 -> V_66 , V_67 , L_10 , V_50 -> V_68 ) ;
V_65 = F_29 ( V_69 , & V_50 -> V_20 ) ;
if ( V_65 ) {
const struct V_70 * V_71 ;
V_71 = V_65 -> V_2 ;
if ( V_71 )
V_61 =
V_71 -> V_61 ;
}
} else {
V_2 -> V_7 = V_7 ? ( * V_7 ) : V_72 ;
snprintf ( V_2 -> V_15 -> V_66 , V_67 , L_11 ,
V_50 -> V_68 , V_50 -> V_66 ) ;
}
V_2 -> V_15 -> V_68 = F_30 ( V_20 ) ;
V_2 -> V_15 -> V_73 = F_21 ,
V_2 -> V_15 -> V_74 = F_22 ,
V_2 -> V_15 -> V_75 = F_6 ,
V_2 -> V_15 -> V_76 = V_20 ;
V_2 -> V_15 -> V_16 = V_2 ;
V_2 -> V_6 = F_31 ( V_20 , L_12 ) ;
if ( F_32 ( V_2 -> V_6 ) ) {
F_19 ( V_20 , L_13 ) ;
return F_33 ( V_2 -> V_6 ) ;
}
F_34 ( V_20 , V_2 ) ;
V_2 -> V_20 = V_20 ;
V_57 = F_35 ( V_50 , V_77 , 0 ) ;
V_2 -> V_12 = F_36 ( V_20 , V_57 ) ;
if ( F_32 ( V_2 -> V_12 ) )
return F_33 ( V_2 -> V_12 ) ;
F_1 ( V_2 ) ;
F_37 ( & V_50 -> V_20 , V_61 ) ;
F_38 ( & V_50 -> V_20 ) ;
F_39 ( & V_50 -> V_20 ) ;
if ( V_20 -> V_53 && F_40 ( V_20 -> V_53 ) ) {
V_2 -> V_23 = true ;
V_19 = F_41 ( V_2 -> V_15 , V_20 -> V_53 ) ;
} else {
V_19 = F_42 ( V_2 -> V_15 ) ;
}
if ( V_19 )
goto V_78;
for ( V_60 = 0 ; V_60 < V_21 ; V_60 ++ ) {
V_59 = F_43 ( V_2 -> V_15 , V_60 ) ;
if ( V_59 ) {
F_11 ( V_20 , L_14 ,
V_59 -> V_79 . V_60 , F_44 ( V_59 ) ,
V_59 -> V_80 ? V_59 -> V_80 -> V_68 : L_15 ) ;
}
}
return 0 ;
V_78:
F_45 ( & V_50 -> V_20 ) ;
F_46 ( & V_50 -> V_20 ) ;
return V_19 ;
}
static int F_47 ( struct V_49 * V_50 )
{
struct V_1 * V_2 = F_48 ( V_50 ) ;
if ( V_2 -> V_15 )
F_49 ( V_2 -> V_15 ) ;
F_45 ( & V_50 -> V_20 ) ;
F_46 ( & V_50 -> V_20 ) ;
return 0 ;
}
static int F_50 ( struct V_55 * V_20 )
{
struct V_1 * V_2 = F_51 ( V_20 ) ;
T_1 V_81 ;
V_81 = F_10 ( & V_2 -> V_12 -> V_13 ) ;
V_81 &= ~ V_11 ;
F_5 ( V_81 , & V_2 -> V_12 -> V_13 ) ;
F_20 ( V_2 ) ;
return 0 ;
}
static int F_52 ( struct V_55 * V_20 )
{
struct V_1 * V_2 = F_51 ( V_20 ) ;
F_4 ( V_2 ) ;
return 0 ;
}
static int F_53 ( struct V_55 * V_20 )
{
struct V_1 * V_2 = F_51 ( V_20 ) ;
int V_19 = 0 ;
V_2 -> V_82 = ! F_54 ( V_20 ) ;
if ( V_2 -> V_82 )
V_19 = F_55 ( V_20 ) ;
if ( V_19 < 0 )
return V_19 ;
F_56 ( V_20 ) ;
return 0 ;
}
static int F_57 ( struct V_55 * V_20 )
{
struct V_1 * V_2 = F_51 ( V_20 ) ;
F_58 ( V_20 ) ;
if ( V_2 -> V_82 )
F_59 ( V_20 ) ;
return 0 ;
}
static int T_4 F_60 ( void )
{
return F_61 ( & V_83 ) ;
}
static void T_5 F_62 ( void )
{
F_63 ( & V_83 ) ;
}
