static void F_1 ( struct V_1 * V_2 )
{
T_1 V_3 , div , V_4 , V_5 ;
V_3 = F_2 ( V_2 -> V_6 ) ;
div = ( V_3 / V_2 -> V_7 . V_8 ) - 1 ;
if ( div > V_9 )
div = V_9 ;
F_3 ( div | V_10 , & V_2 -> V_11 -> V_12 ) ;
V_4 = V_3 / ( 1000 * ( div + 1 ) ) ;
V_5 = ( 88 * 1000 ) / V_4 ;
V_2 -> V_5 = F_4 ( V_5 * 4 ) ;
if ( ! V_2 -> V_5 )
V_2 -> V_5 = 1 ;
}
static int F_5 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = V_14 -> V_15 ;
T_1 V_16 , V_17 ;
F_1 ( V_2 ) ;
F_6 ( V_18 * V_2 -> V_5 ) ;
V_17 = F_7 ( & V_2 -> V_11 -> V_19 ) ;
F_8 ( V_2 -> V_20 , L_1 ,
( V_17 >> 8 ) & 0xff , V_17 & 0xff ) ;
if ( V_2 -> V_21 )
return 0 ;
V_16 = F_7 ( & V_2 -> V_11 -> V_22 ) ;
if ( V_16 ) {
F_8 ( V_2 -> V_20 , L_2 , ~ V_16 ) ;
V_16 = ~ V_16 ;
} else {
F_9 ( V_2 -> V_20 , L_3 ) ;
V_16 = 0 ;
}
V_2 -> V_14 -> V_16 = V_16 ;
return 0 ;
}
static inline int F_10 ( struct V_1 * V_2 )
{
struct V_23 T_2 * V_11 = V_2 -> V_11 ;
unsigned long V_24 = V_25 + F_11 ( V_26 ) ;
T_1 V_27 ;
while ( F_12 ( V_24 , V_25 ) ) {
V_27 = F_7 ( & V_11 -> V_28 [ 0 ] . V_29 ) ;
if ( ( V_27 & V_30 ) == 0 )
return 0 ;
V_27 = F_7 ( & V_11 -> V_12 ) ;
if ( ( V_27 & V_31 ) == 0 )
continue;
F_9 ( V_2 -> V_20 , L_4 ) ;
F_1 ( V_2 ) ;
return - V_32 ;
}
V_27 = F_7 ( & V_11 -> V_28 [ 0 ] . V_29 ) ;
if ( ( V_27 & V_30 ) == 0 )
return 0 ;
F_13 ( V_2 -> V_20 , L_5 ) ;
return - V_33 ;
}
static inline int F_14 ( struct V_1 * V_2 )
{
struct V_23 T_2 * V_11 = V_2 -> V_11 ;
unsigned long V_24 = V_25 + F_11 ( V_26 ) ;
while ( F_12 ( V_24 , V_25 ) ) {
if ( F_7 ( & V_11 -> V_12 ) & V_31 )
return 0 ;
}
F_13 ( V_2 -> V_20 , L_6 ) ;
return - V_33 ;
}
static int F_15 ( struct V_13 * V_14 , int V_34 , int V_35 )
{
struct V_1 * V_2 = V_14 -> V_15 ;
T_1 V_27 ;
int V_36 ;
if ( V_35 & ~ V_37 || V_34 & ~ V_38 )
return - V_39 ;
F_16 ( & V_2 -> V_40 ) ;
if ( V_2 -> V_41 ) {
F_17 ( & V_2 -> V_40 ) ;
return - V_42 ;
}
V_27 = ( V_30 | V_43 | ( V_35 << 21 ) |
( V_34 << 16 ) ) ;
while ( 1 ) {
V_36 = F_10 ( V_2 ) ;
if ( V_36 == - V_32 )
continue;
if ( V_36 < 0 )
break;
F_3 ( V_27 , & V_2 -> V_11 -> V_28 [ 0 ] . V_29 ) ;
V_36 = F_10 ( V_2 ) ;
if ( V_36 == - V_32 )
continue;
if ( V_36 < 0 )
break;
V_27 = F_7 ( & V_2 -> V_11 -> V_28 [ 0 ] . V_29 ) ;
V_36 = ( V_27 & V_44 ) ? ( V_27 & V_45 ) : - V_46 ;
break;
}
F_17 ( & V_2 -> V_40 ) ;
return V_36 ;
}
static int F_18 ( struct V_13 * V_14 , int V_34 ,
int V_35 , T_3 V_47 )
{
struct V_1 * V_2 = V_14 -> V_15 ;
T_1 V_27 ;
int V_36 ;
if ( V_35 & ~ V_37 || V_34 & ~ V_38 )
return - V_39 ;
F_16 ( & V_2 -> V_40 ) ;
if ( V_2 -> V_41 ) {
F_17 ( & V_2 -> V_40 ) ;
return - V_42 ;
}
V_27 = ( V_30 | V_48 | ( V_35 << 21 ) |
( V_34 << 16 ) | ( V_47 & V_45 ) ) ;
while ( 1 ) {
V_36 = F_10 ( V_2 ) ;
if ( V_36 == - V_32 )
continue;
if ( V_36 < 0 )
break;
F_3 ( V_27 , & V_2 -> V_11 -> V_28 [ 0 ] . V_29 ) ;
V_36 = F_10 ( V_2 ) ;
if ( V_36 == - V_32 )
continue;
break;
}
F_17 ( & V_2 -> V_40 ) ;
return 0 ;
}
static int F_19 ( struct V_49 * V_2 ,
struct V_50 * V_51 )
{
struct V_52 * V_53 = V_51 -> V_20 . V_54 ;
T_1 V_55 ;
if ( ! V_53 )
return - V_39 ;
if ( F_20 ( V_53 , L_7 , & V_55 ) ) {
F_13 ( & V_51 -> V_20 , L_8 ) ;
return - V_39 ;
}
V_2 -> V_8 = V_55 ;
return 0 ;
}
static int F_21 ( struct V_50 * V_51 )
{
struct V_49 * V_7 = F_22 ( & V_51 -> V_20 ) ;
struct V_56 * V_20 = & V_51 -> V_20 ;
struct V_1 * V_2 ;
struct V_57 * V_58 ;
struct V_59 * V_60 ;
int V_36 , V_61 ;
V_2 = F_23 ( V_20 , sizeof( * V_2 ) , V_62 ) ;
if ( ! V_2 )
return - V_63 ;
V_2 -> V_14 = F_24 ( V_20 ) ;
if ( ! V_2 -> V_14 ) {
F_13 ( V_20 , L_9 ) ;
return - V_63 ;
}
if ( V_20 -> V_54 ) {
if ( F_19 ( & V_2 -> V_7 , V_51 ) )
V_2 -> V_7 = V_64 ;
snprintf ( V_2 -> V_14 -> V_65 , V_66 , L_10 , V_51 -> V_67 ) ;
} else {
V_2 -> V_7 = V_7 ? ( * V_7 ) : V_64 ;
snprintf ( V_2 -> V_14 -> V_65 , V_66 , L_11 ,
V_51 -> V_67 , V_51 -> V_65 ) ;
}
V_2 -> V_14 -> V_67 = F_25 ( V_20 ) ;
V_2 -> V_14 -> V_68 = F_15 ,
V_2 -> V_14 -> V_69 = F_18 ,
V_2 -> V_14 -> V_70 = F_5 ,
V_2 -> V_14 -> V_71 = V_20 ;
V_2 -> V_14 -> V_15 = V_2 ;
F_26 ( & V_51 -> V_20 ) ;
F_27 ( & V_51 -> V_20 ) ;
V_2 -> V_6 = F_28 ( V_20 , L_12 ) ;
if ( F_29 ( V_2 -> V_6 ) ) {
F_13 ( V_20 , L_13 ) ;
V_36 = F_30 ( V_2 -> V_6 ) ;
V_2 -> V_6 = NULL ;
goto V_72;
}
F_31 ( V_20 , V_2 ) ;
V_2 -> V_20 = V_20 ;
F_32 ( & V_2 -> V_40 ) ;
V_58 = F_33 ( V_51 , V_73 , 0 ) ;
V_2 -> V_11 = F_34 ( V_20 , V_58 ) ;
if ( F_29 ( V_2 -> V_11 ) ) {
V_36 = F_30 ( V_2 -> V_11 ) ;
goto V_72;
}
if ( V_20 -> V_54 && F_35 ( V_20 -> V_54 ) ) {
V_2 -> V_21 = true ;
V_36 = F_36 ( V_2 -> V_14 , V_20 -> V_54 ) ;
} else {
V_36 = F_37 ( V_2 -> V_14 ) ;
}
if ( V_36 )
goto V_72;
for ( V_61 = 0 ; V_61 < V_18 ; V_61 ++ ) {
V_60 = F_38 ( V_2 -> V_14 , V_61 ) ;
if ( V_60 ) {
F_8 ( V_20 , L_14 ,
V_60 -> V_74 . V_61 , F_39 ( V_60 ) ,
V_60 -> V_75 ? V_60 -> V_75 -> V_67 : L_15 ) ;
}
}
return 0 ;
V_72:
F_40 ( & V_51 -> V_20 ) ;
F_41 ( & V_51 -> V_20 ) ;
return V_36 ;
}
static int F_42 ( struct V_50 * V_51 )
{
struct V_1 * V_2 = F_43 ( V_51 ) ;
if ( V_2 -> V_14 )
F_44 ( V_2 -> V_14 ) ;
F_40 ( & V_51 -> V_20 ) ;
F_41 ( & V_51 -> V_20 ) ;
return 0 ;
}
static int F_45 ( struct V_56 * V_20 )
{
struct V_1 * V_2 = F_46 ( V_20 ) ;
T_1 V_76 ;
F_16 ( & V_2 -> V_40 ) ;
V_76 = F_7 ( & V_2 -> V_11 -> V_12 ) ;
V_76 &= ~ V_10 ;
F_3 ( V_76 , & V_2 -> V_11 -> V_12 ) ;
F_14 ( V_2 ) ;
V_2 -> V_41 = true ;
F_17 ( & V_2 -> V_40 ) ;
F_40 ( V_2 -> V_20 ) ;
F_47 ( V_20 ) ;
return 0 ;
}
static int F_48 ( struct V_56 * V_20 )
{
struct V_1 * V_2 = F_46 ( V_20 ) ;
F_49 ( V_20 ) ;
F_27 ( V_2 -> V_20 ) ;
F_16 ( & V_2 -> V_40 ) ;
F_1 ( V_2 ) ;
V_2 -> V_41 = false ;
F_17 ( & V_2 -> V_40 ) ;
return 0 ;
}
static int T_4 F_50 ( void )
{
return F_51 ( & V_77 ) ;
}
static void T_5 F_52 ( void )
{
F_53 ( & V_77 ) ;
}
