static int T_1 F_1 ( T_2 V_1 , T_2 V_2 )
{
int V_3 ;
V_3 = F_2 ( V_4 , V_1 ,
V_5 ) ;
if ( V_3 )
goto V_6;
V_3 = F_2 ( V_4 , V_2 ,
V_7 ) ;
V_6:
return V_3 ;
}
static int T_1 F_3 ( T_2 V_1 , T_3 V_8 ,
T_2 V_9 , T_2 V_10 )
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
static int T_1 F_4 ( T_2 V_1 , struct V_11 * V_12 ,
int V_13 )
{
int V_3 ;
for (; V_13 ; V_13 -- , V_1 ++ , V_12 ++ ) {
if ( V_13 == 1 ) {
V_3 = F_3 ( V_1 ,
V_12 -> V_8 ,
V_12 -> V_9 ,
V_14 ) ;
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
static int T_1 F_5 ( T_2 V_1 )
{
int V_3 ;
T_2 V_15 ;
V_3 = F_2 ( V_4 , V_1 ,
V_16 ) ;
if ( V_3 )
goto V_6;
V_3 = F_6 ( V_4 , & V_15 ,
V_17 ) ;
if ( V_3 )
goto V_6;
V_15 |= V_18 ;
V_3 = F_2 ( V_4 , V_15 ,
V_17 ) ;
V_6:
if ( V_3 )
F_7 ( L_1 ) ;
return V_3 ;
}
static int T_1 F_8 ( T_2 V_1 )
{
int V_3 = 0 ;
T_2 V_15 ;
V_3 = F_2 ( V_4 , V_1 ,
V_19 ) ;
if ( V_3 )
goto V_6;
V_3 = F_6 ( V_4 , & V_15 ,
V_20 ) ;
if ( V_3 )
goto V_6;
V_15 |= V_18 ;
V_3 = F_2 ( V_4 , V_15 ,
V_20 ) ;
if ( V_3 )
goto V_6;
V_3 = F_6 ( V_4 , & V_15 ,
V_21 ) ;
if ( V_3 )
goto V_6;
V_15 |= V_18 ;
V_3 = F_2 ( V_4 , V_15 ,
V_21 ) ;
if ( V_3 )
goto V_6;
if ( F_9 () || F_10 () ) {
V_3 = F_6 ( V_4 , & V_15 ,
V_22 ) ;
if ( V_3 )
goto V_6;
V_15 &= ~ ( 1 << 1 ) ;
V_3 = F_2 ( V_4 , V_15 ,
V_22 ) ;
if ( V_3 )
goto V_6;
}
V_6:
if ( V_3 )
F_7 ( L_2 \
L_3 ) ;
return V_3 ;
}
static int T_1 F_11 ( T_2 V_1 )
{
int V_3 ;
V_3 = F_2 ( V_4 , V_1 ,
V_23 ) ;
if ( V_3 )
F_7 ( L_4 ) ;
return V_3 ;
}
static int T_1 F_12 ( T_2 V_1 )
{
int V_3 ;
T_2 V_24 ;
V_3 = F_2 ( V_4 , V_1 ,
V_25 ) ;
if ( V_3 )
goto V_6;
V_3 = F_6 ( V_4 , & V_24 ,
V_20 ) ;
if ( V_3 )
goto V_6;
V_24 |= V_26 ;
V_3 = F_2 ( V_4 , V_24 ,
V_20 ) ;
if ( V_3 )
goto V_6;
V_3 = F_6 ( V_4 , & V_24 ,
V_21 ) ;
if ( V_3 )
goto V_6;
V_24 |= V_26 ;
V_3 = F_2 ( V_4 , V_24 ,
V_21 ) ;
if ( V_3 )
goto V_6;
V_3 = F_6 ( V_4 , & V_24 ,
V_17 ) ;
if ( V_3 )
goto V_6;
V_24 |= V_26 ;
V_3 = F_2 ( V_4 , V_24 ,
V_17 ) ;
V_6:
if ( V_3 )
F_7 ( L_5 ) ;
return V_3 ;
}
static int T_1 F_13 ( struct V_27 * V_28 )
{
int V_29 ;
int V_3 ;
T_2 type ;
T_2 V_30 ;
T_2 V_31 ;
if ( V_28 -> V_32 > V_33 ) {
F_7 ( L_6 ,
V_28 -> V_32 ) ;
return - V_34 ;
}
V_29 = V_35 [ V_28 -> V_32 ] ;
V_3 = F_6 ( V_36 , & V_30 ,
V_29 + V_37 ) ;
if ( V_3 ) {
F_7 ( L_7 ,
V_28 -> V_32 ) ;
return V_3 ;
}
if ( V_28 -> V_38 != V_39 ) {
V_30 &= ~ V_40 ;
V_30 |= V_28 -> V_38 << V_41 ;
V_3 = F_2 ( V_36 ,
V_30 , V_29 + V_37 ) ;
if ( V_3 < 0 ) {
F_7 ( L_8 ) ;
return V_3 ;
}
}
V_3 = F_6 ( V_36 , & type ,
V_29 + V_42 ) ;
if ( V_3 < 0 ) {
F_7 ( L_9 ,
V_28 -> V_32 ) ;
return V_3 ;
}
if ( V_28 -> type != V_39 ) {
type &= ~ V_43 ;
type |= V_28 -> type << V_44 ;
}
if ( V_28 -> V_45 != V_39 ) {
type &= ~ V_46 ;
type |= V_28 -> V_45 << V_47 ;
}
V_3 = F_2 ( V_36 ,
type , V_29 + V_42 ) ;
if ( V_3 < 0 ) {
F_7 ( L_10 ) ;
return V_3 ;
}
V_3 = F_6 ( V_36 , & V_31 ,
V_29 + V_48 ) ;
if ( V_3 < 0 ) {
F_7 ( L_11 ,
V_28 -> V_32 ) ;
return V_3 ;
}
if ( V_28 -> V_49 != V_39 ) {
V_31 &= ~ V_50 ;
V_31 |= V_28 -> V_49 << V_51 ;
}
if ( V_28 -> V_52 != V_39 ) {
V_31 &= ~ V_53 ;
V_31 |= V_28 -> V_52 << V_54 ;
}
V_3 = F_2 ( V_36 ,
V_31 ,
V_29 + V_48 ) ;
if ( V_3 < 0 ) {
F_7 ( L_12 ) ;
return V_3 ;
}
return 0 ;
}
static int T_1 F_14 ( struct V_55 * V_56 ,
T_2 V_1 )
{
int V_3 ;
static int V_57 ;
if ( ( V_1 + V_56 -> V_58 ) > V_14 ) {
F_7 ( L_13 ) ;
return - V_34 ;
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
int F_16 ( T_2 V_59 )
{
int V_3 = 0 ;
V_3 = F_2 ( V_4 ,
V_64 ,
V_65 ) ;
if ( V_3 ) {
F_7 ( L_17 ) ;
return V_3 ;
}
V_3 = F_2 ( V_4 ,
V_66 ,
V_65 ) ;
if ( V_3 ) {
F_7 ( L_17 ) ;
return V_3 ;
}
if ( V_59 & V_60 ) {
V_3 = F_2 ( V_4 , V_14 ,
V_25 ) ;
if ( V_3 )
return V_3 ;
}
if ( V_59 & V_61 ) {
V_3 = F_2 ( V_4 , V_14 ,
V_19 ) ;
if ( V_3 )
return V_3 ;
}
if ( V_59 & V_62 ) {
V_3 = F_2 ( V_4 , V_14 ,
V_16 ) ;
if ( V_3 )
return V_3 ;
}
if ( V_59 & V_63 ) {
V_3 = F_2 ( V_4 , V_14 ,
V_23 ) ;
if ( V_3 )
return V_3 ;
}
V_3 = F_2 ( V_4 , 0 ,
V_65 ) ;
if ( V_3 )
F_7 ( L_18 ) ;
return V_3 ;
}
void F_17 ( void )
{
int V_3 ;
V_3 = F_2 ( V_4 , V_67 ,
V_68 ) ;
if ( V_3 )
F_7 ( L_19 ) ;
}
void T_1 F_18 ( struct V_69 * V_70 )
{
int V_3 = 0 ;
int V_71 ;
struct V_27 * V_72 ;
T_2 V_73 , V_1 = V_74 ;
V_3 = F_2 ( V_4 ,
V_64 ,
V_65 ) ;
if ( V_3 )
goto V_75;
V_3 = F_2 ( V_4 ,
V_66 ,
V_65 ) ;
if ( V_3 )
goto V_75;
for ( V_71 = 0 ; V_71 < V_70 -> V_76 ; V_71 ++ ) {
V_3 = F_14 ( V_70 -> V_77 [ V_71 ] , V_1 ) ;
if ( V_3 )
goto V_78;
V_1 += V_70 -> V_77 [ V_71 ] -> V_58 ;
}
V_72 = V_70 -> V_79 ;
if ( V_72 ) {
while ( V_72 -> V_32 ) {
V_3 = F_13 ( V_72 ) ;
if ( V_3 )
goto V_32;
V_72 ++ ;
}
}
if ( V_70 -> V_80 && ! V_81 ) {
V_3 = F_6 ( V_4 , & V_73 ,
V_82 ) ;
if ( V_3 ) {
F_15 ( L_20 ) ;
} else if ( ! ( V_73 & V_83 ) ) {
V_73 |= V_83 ;
V_3 = F_2 ( V_4 , V_73 ,
V_82 ) ;
if ( V_3 ) {
F_7 ( L_21 ) ;
goto V_84;
}
}
V_81 = F_17 ;
}
V_84:
V_3 = F_2 ( V_4 , 0 ,
V_65 ) ;
if ( V_3 )
F_7 ( L_18 ) ;
return;
V_75:
if ( V_3 )
F_7 ( L_22 ) ;
return;
V_78:
if ( V_3 )
F_7 ( L_23 ) ;
return;
V_32:
if ( V_3 )
F_7 ( L_24 ) ;
return;
}
