static int F_1 ( T_1 V_1 , T_1 V_2 )
{
int V_3 ;
V_3 = F_2 ( V_4 , V_1 , V_5 ) ;
if ( V_3 )
goto V_6;
V_3 = F_2 ( V_4 , V_2 , V_7 ) ;
V_6:
return V_3 ;
}
static int F_3 ( T_1 V_1 , T_2 V_8 ,
T_1 V_9 , T_1 V_10 )
{
int V_3 ;
V_1 *= 4 ;
V_3 = F_1 ( V_1 ++ , V_8 >> 8 ) ;
if ( V_3 )
goto V_6;
V_3 = F_1 ( V_1 ++ , V_8 & 0xff ) ;
if ( V_3 )
goto V_6;
V_3 = F_1 ( V_1 ++ , V_9 ) ;
if ( V_3 )
goto V_6;
V_3 = F_1 ( V_1 ++ , V_10 ) ;
V_6:
return V_3 ;
}
static int F_4 ( T_1 V_1 , struct V_11 * V_12 ,
int V_13 )
{
int V_3 = - V_14 ;
for (; V_13 ; V_13 -- , V_1 ++ , V_12 ++ ) {
if ( V_13 == 1 ) {
V_3 = F_3 ( V_1 ,
V_12 -> V_8 ,
V_12 -> V_9 ,
V_15 ) ;
if ( V_3 )
break;
} else {
V_3 = F_3 ( V_1 ,
V_12 -> V_8 ,
V_12 -> V_9 ,
V_1 + 1 ) ;
if ( V_3 )
break;
}
}
return V_3 ;
}
static int F_5 ( T_1 V_1 )
{
int V_3 ;
T_1 V_16 ;
V_3 = F_2 ( V_4 , V_1 , V_17 ) ;
if ( V_3 )
goto V_6;
V_3 = F_6 ( V_4 , & V_16 , V_18 ) ;
if ( V_3 )
goto V_6;
V_16 |= V_19 ;
V_3 = F_2 ( V_4 , V_16 , V_18 ) ;
V_6:
if ( V_3 )
F_7 ( L_1 ) ;
return V_3 ;
}
static int F_8 ( T_1 V_1 )
{
int V_3 = 0 ;
T_1 V_16 ;
V_3 = F_2 ( V_4 , V_1 , V_20 ) ;
if ( V_3 )
goto V_6;
V_3 = F_6 ( V_4 , & V_16 , V_21 ) ;
if ( V_3 )
goto V_6;
V_16 |= V_19 ;
V_3 = F_2 ( V_4 , V_16 , V_21 ) ;
if ( V_3 )
goto V_6;
V_3 = F_6 ( V_4 , & V_16 , V_22 ) ;
if ( V_3 )
goto V_6;
V_16 |= V_19 ;
V_3 = F_2 ( V_4 , V_16 , V_22 ) ;
if ( V_3 )
goto V_6;
if ( F_9 () || F_10 () ) {
V_3 = F_6 ( V_4 , & V_16 ,
V_23 ) ;
if ( V_3 )
goto V_6;
V_16 &= ~ ( 1 << 1 ) ;
V_3 = F_2 ( V_4 , V_16 ,
V_23 ) ;
if ( V_3 )
goto V_6;
}
V_6:
if ( V_3 )
F_7 ( L_2 \
L_3 ) ;
return V_3 ;
}
static int F_11 ( T_1 V_1 )
{
int V_3 ;
V_3 = F_2 ( V_4 , V_1 , V_24 ) ;
if ( V_3 )
F_7 ( L_4 ) ;
return V_3 ;
}
static int F_12 ( T_1 V_1 )
{
int V_3 ;
T_1 V_25 ;
V_3 = F_2 ( V_4 , V_1 , V_26 ) ;
if ( V_3 )
goto V_6;
V_3 = F_6 ( V_4 , & V_25 , V_21 ) ;
if ( V_3 )
goto V_6;
V_25 |= V_27 ;
V_3 = F_2 ( V_4 , V_25 , V_21 ) ;
if ( V_3 )
goto V_6;
V_3 = F_6 ( V_4 , & V_25 , V_22 ) ;
if ( V_3 )
goto V_6;
V_25 |= V_27 ;
V_3 = F_2 ( V_4 , V_25 , V_22 ) ;
if ( V_3 )
goto V_6;
V_3 = F_6 ( V_4 , & V_25 , V_18 ) ;
if ( V_3 )
goto V_6;
V_25 |= V_27 ;
V_3 = F_2 ( V_4 , V_25 , V_18 ) ;
V_6:
if ( V_3 )
F_7 ( L_5 ) ;
return V_3 ;
}
static int F_13 ( struct V_28 * V_29 )
{
int V_30 ;
int V_3 ;
T_1 type ;
T_1 V_31 ;
T_1 V_32 ;
if ( V_29 -> V_33 > V_34 ) {
F_7 ( L_6 ,
V_29 -> V_33 ) ;
return - V_14 ;
}
V_30 = V_35 [ V_29 -> V_33 ] ;
V_3 = F_6 ( V_36 , & V_31 ,
V_30 + V_37 ) ;
if ( V_3 ) {
F_7 ( L_7 ,
V_29 -> V_33 ) ;
return V_3 ;
}
if ( V_29 -> V_38 != V_39 ) {
V_31 &= ~ V_40 ;
V_31 |= V_29 -> V_38 << V_41 ;
V_3 = F_2 ( V_36 ,
V_31 , V_30 + V_37 ) ;
if ( V_3 < 0 ) {
F_7 ( L_8 ) ;
return V_3 ;
}
}
V_3 = F_6 ( V_36 , & type ,
V_30 + V_42 ) ;
if ( V_3 < 0 ) {
F_7 ( L_9 ,
V_29 -> V_33 ) ;
return V_3 ;
}
if ( V_29 -> type != V_39 ) {
type &= ~ V_43 ;
type |= V_29 -> type << V_44 ;
}
if ( V_29 -> V_45 != V_39 ) {
type &= ~ V_46 ;
type |= V_29 -> V_45 << V_47 ;
}
V_3 = F_2 ( V_36 ,
type , V_30 + V_42 ) ;
if ( V_3 < 0 ) {
F_7 ( L_10 ) ;
return V_3 ;
}
V_3 = F_6 ( V_36 , & V_32 ,
V_30 + V_48 ) ;
if ( V_3 < 0 ) {
F_7 ( L_11 ,
V_29 -> V_33 ) ;
return V_3 ;
}
if ( V_29 -> V_49 != V_39 ) {
V_32 &= ~ V_50 ;
V_32 |= V_29 -> V_49 << V_51 ;
}
if ( V_29 -> V_52 != V_39 ) {
V_32 &= ~ V_53 ;
V_32 |= V_29 -> V_52 << V_54 ;
}
V_3 = F_2 ( V_36 ,
V_32 ,
V_30 + V_48 ) ;
if ( V_3 < 0 ) {
F_7 ( L_12 ) ;
return V_3 ;
}
return 0 ;
}
static int F_14 ( struct V_55 * V_56 ,
T_1 V_1 )
{
int V_3 ;
static int V_57 ;
if ( ( V_1 + V_56 -> V_58 ) > V_15 ) {
F_7 ( L_13 ) ;
return - V_14 ;
}
V_3 = F_4 ( V_1 , V_56 -> V_12 , V_56 -> V_58 ) ;
if ( V_3 )
goto V_6;
if ( V_56 -> V_59 & V_60 ) {
V_3 = F_12 ( V_1 ) ;
if ( V_3 )
goto V_6;
}
if ( V_56 -> V_59 & V_61 ) {
V_3 = F_8 ( V_1 ) ;
if ( V_3 )
goto V_6;
V_57 = 1 ;
}
if ( V_56 -> V_59 & V_62 ) {
V_3 = F_5 ( V_1 ) ;
if ( V_3 )
goto V_6;
}
if ( V_56 -> V_59 & V_63 ) {
if ( ! V_57 )
F_15 ( L_14\
L_15\
L_16 ) ;
V_3 = F_11 ( V_1 ) ;
}
V_6:
return V_3 ;
}
int F_16 ( T_1 V_59 )
{
int V_3 = 0 ;
V_3 = F_2 ( V_4 , V_64 ,
V_65 ) ;
if ( V_3 ) {
F_7 ( L_17 ) ;
return V_3 ;
}
V_3 = F_2 ( V_4 , V_66 ,
V_65 ) ;
if ( V_3 ) {
F_7 ( L_17 ) ;
return V_3 ;
}
if ( V_59 & V_60 ) {
V_3 = F_2 ( V_4 , V_15 ,
V_26 ) ;
if ( V_3 )
return V_3 ;
}
if ( V_59 & V_61 ) {
V_3 = F_2 ( V_4 , V_15 ,
V_20 ) ;
if ( V_3 )
return V_3 ;
}
if ( V_59 & V_62 ) {
V_3 = F_2 ( V_4 , V_15 ,
V_17 ) ;
if ( V_3 )
return V_3 ;
}
if ( V_59 & V_63 ) {
V_3 = F_2 ( V_4 , V_15 ,
V_24 ) ;
if ( V_3 )
return V_3 ;
}
V_3 = F_2 ( V_4 , 0 ,
V_65 ) ;
if ( V_3 )
F_7 ( L_18 ) ;
return V_3 ;
}
static int F_17 ( struct V_67 * V_68 )
{
int V_3 ;
int V_69 ;
T_1 V_1 = V_70 ;
for ( V_69 = 0 ; V_69 < V_68 -> V_71 ; V_69 ++ ) {
V_3 = F_14 ( V_68 -> V_72 [ V_69 ] , V_1 ) ;
if ( V_3 )
return V_3 ;
V_1 += V_68 -> V_72 [ V_69 ] -> V_58 ;
}
return 0 ;
}
static int F_18 ( struct V_67 * V_68 )
{
struct V_28 * V_73 = V_68 -> V_74 ;
int V_3 ;
if ( V_73 ) {
while ( V_73 -> V_33 ) {
V_3 = F_13 ( V_73 ) ;
if ( V_3 )
return V_3 ;
V_73 ++ ;
}
}
return 0 ;
}
void F_19 ( void )
{
int V_3 ;
V_3 = F_2 ( V_4 , V_75 ,
V_76 ) ;
if ( V_3 )
F_7 ( L_19 ) ;
}
static bool F_20 ( struct V_67 * V_68 ,
struct V_77 * V_78 )
{
if ( V_68 && V_68 -> V_79 )
return true ;
if ( F_21 ( V_78 , L_20 ) )
return true ;
return false ;
}
static int F_22 ( struct V_80 * V_81 )
{
struct V_67 * V_68 = F_23 ( & V_81 -> V_82 ) ;
struct V_77 * V_78 = V_81 -> V_82 . V_83 ;
int V_3 = 0 ;
int V_84 = 0 ;
T_1 V_85 ;
if ( ! V_68 && ! V_78 ) {
F_24 ( & V_81 -> V_82 , L_21 ) ;
return - V_14 ;
}
V_3 = F_2 ( V_4 , V_64 ,
V_65 ) ;
V_3 |= F_2 ( V_4 ,
V_66 ,
V_65 ) ;
if ( V_3 ) {
F_7 ( L_22 ) ;
return V_3 ;
}
if ( V_68 ) {
V_3 = F_17 ( V_68 ) ;
if ( V_3 ) {
F_7 ( L_23 ) ;
goto V_86;
}
V_3 = F_18 ( V_68 ) ;
if ( V_3 ) {
F_7 ( L_24 ) ;
goto V_86;
}
}
if ( F_20 ( V_68 , V_78 ) && ! V_87 ) {
V_3 = F_6 ( V_4 , & V_85 ,
V_88 ) ;
if ( V_3 ) {
F_15 ( L_25 ) ;
} else if ( ! ( V_85 & V_89 ) ) {
V_85 |= V_89 ;
V_3 = F_2 ( V_4 , V_85 ,
V_88 ) ;
if ( V_3 ) {
F_7 ( L_26 ) ;
goto V_86;
}
}
V_87 = F_19 ;
}
V_86:
V_84 = F_2 ( V_4 , 0 ,
V_65 ) ;
if ( V_84 ) {
F_7 ( L_18 ) ;
return V_84 ;
}
return V_3 ;
}
static int F_25 ( struct V_80 * V_81 )
{
return 0 ;
}
