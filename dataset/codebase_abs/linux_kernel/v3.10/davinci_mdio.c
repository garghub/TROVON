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
V_16 = F_7 ( & V_2 -> V_11 -> V_21 ) ;
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
struct V_22 T_2 * V_11 = V_2 -> V_11 ;
unsigned long V_23 = V_24 + F_11 ( V_25 ) ;
T_1 V_26 ;
while ( F_12 ( V_23 , V_24 ) ) {
V_26 = F_7 ( & V_11 -> V_27 [ 0 ] . V_28 ) ;
if ( ( V_26 & V_29 ) == 0 )
return 0 ;
V_26 = F_7 ( & V_11 -> V_12 ) ;
if ( ( V_26 & V_30 ) == 0 )
continue;
F_9 ( V_2 -> V_20 , L_4 ) ;
F_1 ( V_2 ) ;
return - V_31 ;
}
V_26 = F_7 ( & V_11 -> V_27 [ 0 ] . V_28 ) ;
if ( ( V_26 & V_29 ) == 0 )
return 0 ;
F_13 ( V_2 -> V_20 , L_5 ) ;
return - V_32 ;
}
static inline int F_14 ( struct V_1 * V_2 )
{
struct V_22 T_2 * V_11 = V_2 -> V_11 ;
unsigned long V_23 = V_24 + F_11 ( V_25 ) ;
while ( F_12 ( V_23 , V_24 ) ) {
if ( F_7 ( & V_11 -> V_12 ) & V_30 )
return 0 ;
}
F_13 ( V_2 -> V_20 , L_6 ) ;
return - V_32 ;
}
static int F_15 ( struct V_13 * V_14 , int V_33 , int V_34 )
{
struct V_1 * V_2 = V_14 -> V_15 ;
T_1 V_26 ;
int V_35 ;
if ( V_34 & ~ V_36 || V_33 & ~ V_37 )
return - V_38 ;
F_16 ( & V_2 -> V_39 ) ;
if ( V_2 -> V_40 ) {
F_17 ( & V_2 -> V_39 ) ;
return - V_41 ;
}
V_26 = ( V_29 | V_42 | ( V_34 << 21 ) |
( V_33 << 16 ) ) ;
while ( 1 ) {
V_35 = F_10 ( V_2 ) ;
if ( V_35 == - V_31 )
continue;
if ( V_35 < 0 )
break;
F_3 ( V_26 , & V_2 -> V_11 -> V_27 [ 0 ] . V_28 ) ;
V_35 = F_10 ( V_2 ) ;
if ( V_35 == - V_31 )
continue;
if ( V_35 < 0 )
break;
V_26 = F_7 ( & V_2 -> V_11 -> V_27 [ 0 ] . V_28 ) ;
V_35 = ( V_26 & V_43 ) ? ( V_26 & V_44 ) : - V_45 ;
break;
}
F_17 ( & V_2 -> V_39 ) ;
return V_35 ;
}
static int F_18 ( struct V_13 * V_14 , int V_33 ,
int V_34 , T_3 V_46 )
{
struct V_1 * V_2 = V_14 -> V_15 ;
T_1 V_26 ;
int V_35 ;
if ( V_34 & ~ V_36 || V_33 & ~ V_37 )
return - V_38 ;
F_16 ( & V_2 -> V_39 ) ;
if ( V_2 -> V_40 ) {
F_17 ( & V_2 -> V_39 ) ;
return - V_41 ;
}
V_26 = ( V_29 | V_47 | ( V_34 << 21 ) |
( V_33 << 16 ) | ( V_46 & V_44 ) ) ;
while ( 1 ) {
V_35 = F_10 ( V_2 ) ;
if ( V_35 == - V_31 )
continue;
if ( V_35 < 0 )
break;
F_3 ( V_26 , & V_2 -> V_11 -> V_27 [ 0 ] . V_28 ) ;
V_35 = F_10 ( V_2 ) ;
if ( V_35 == - V_31 )
continue;
break;
}
F_17 ( & V_2 -> V_39 ) ;
return 0 ;
}
static int F_19 ( struct V_48 * V_2 ,
struct V_49 * V_50 )
{
struct V_51 * V_52 = V_50 -> V_20 . V_53 ;
T_1 V_54 ;
if ( ! V_52 )
return - V_38 ;
if ( F_20 ( V_52 , L_7 , & V_54 ) ) {
F_21 ( L_8 ) ;
return - V_38 ;
}
V_2 -> V_8 = V_54 ;
return 0 ;
}
static int F_22 ( struct V_49 * V_50 )
{
struct V_48 * V_7 = V_50 -> V_20 . V_55 ;
struct V_56 * V_20 = & V_50 -> V_20 ;
struct V_1 * V_2 ;
struct V_57 * V_58 ;
struct V_59 * V_60 ;
int V_35 , V_61 ;
V_2 = F_23 ( sizeof( * V_2 ) , V_62 ) ;
if ( ! V_2 )
return - V_63 ;
V_2 -> V_14 = F_24 () ;
if ( ! V_2 -> V_14 ) {
F_13 ( V_20 , L_9 ) ;
V_35 = - V_63 ;
goto V_64;
}
if ( V_20 -> V_53 ) {
if ( F_19 ( & V_2 -> V_7 , V_50 ) )
V_2 -> V_7 = V_65 ;
snprintf ( V_2 -> V_14 -> V_66 , V_67 , L_10 , V_50 -> V_68 ) ;
} else {
V_2 -> V_7 = V_7 ? ( * V_7 ) : V_65 ;
snprintf ( V_2 -> V_14 -> V_66 , V_67 , L_11 ,
V_50 -> V_68 , V_50 -> V_66 ) ;
}
V_2 -> V_14 -> V_68 = F_25 ( V_20 ) ;
V_2 -> V_14 -> V_69 = F_15 ,
V_2 -> V_14 -> V_70 = F_18 ,
V_2 -> V_14 -> V_71 = F_5 ,
V_2 -> V_14 -> V_72 = V_20 ;
V_2 -> V_14 -> V_15 = V_2 ;
F_26 ( & V_50 -> V_20 ) ;
F_27 ( & V_50 -> V_20 ) ;
V_2 -> V_6 = F_28 ( & V_50 -> V_20 , L_12 ) ;
if ( F_29 ( V_2 -> V_6 ) ) {
F_13 ( V_20 , L_13 ) ;
V_35 = F_30 ( V_2 -> V_6 ) ;
V_2 -> V_6 = NULL ;
goto V_64;
}
F_31 ( V_20 , V_2 ) ;
V_2 -> V_20 = V_20 ;
F_32 ( & V_2 -> V_39 ) ;
V_58 = F_33 ( V_50 , V_73 , 0 ) ;
if ( ! V_58 ) {
F_13 ( V_20 , L_14 ) ;
V_35 = - V_74 ;
goto V_64;
}
V_58 = F_34 ( V_20 , V_58 -> V_75 , F_35 ( V_58 ) ,
F_25 ( V_20 ) ) ;
if ( ! V_58 ) {
F_13 ( V_20 , L_15 ) ;
V_35 = - V_76 ;
goto V_64;
}
V_2 -> V_11 = F_36 ( V_20 , V_58 -> V_75 , F_35 ( V_58 ) ) ;
if ( ! V_2 -> V_11 ) {
F_13 ( V_20 , L_16 ) ;
V_35 = - V_63 ;
goto V_64;
}
V_35 = F_37 ( V_2 -> V_14 ) ;
if ( V_35 )
goto V_64;
for ( V_61 = 0 ; V_61 < V_18 ; V_61 ++ ) {
V_60 = V_2 -> V_14 -> V_77 [ V_61 ] ;
if ( V_60 ) {
F_8 ( V_20 , L_17 ,
V_60 -> V_61 , F_25 ( & V_60 -> V_20 ) ,
V_60 -> V_78 ? V_60 -> V_78 -> V_68 : L_18 ) ;
}
}
return 0 ;
V_64:
if ( V_2 -> V_14 )
F_38 ( V_2 -> V_14 ) ;
if ( V_2 -> V_6 )
F_39 ( V_2 -> V_6 ) ;
F_40 ( & V_50 -> V_20 ) ;
F_41 ( & V_50 -> V_20 ) ;
F_42 ( V_2 ) ;
return V_35 ;
}
static int F_43 ( struct V_49 * V_50 )
{
struct V_56 * V_20 = & V_50 -> V_20 ;
struct V_1 * V_2 = F_44 ( V_20 ) ;
if ( V_2 -> V_14 ) {
F_45 ( V_2 -> V_14 ) ;
F_38 ( V_2 -> V_14 ) ;
}
if ( V_2 -> V_6 )
F_39 ( V_2 -> V_6 ) ;
F_40 ( & V_50 -> V_20 ) ;
F_41 ( & V_50 -> V_20 ) ;
F_31 ( V_20 , NULL ) ;
F_42 ( V_2 ) ;
return 0 ;
}
static int F_46 ( struct V_56 * V_20 )
{
struct V_1 * V_2 = F_44 ( V_20 ) ;
T_1 V_79 ;
F_16 ( & V_2 -> V_39 ) ;
V_79 = F_7 ( & V_2 -> V_11 -> V_12 ) ;
V_79 &= ~ V_10 ;
F_3 ( V_79 , & V_2 -> V_11 -> V_12 ) ;
F_14 ( V_2 ) ;
V_2 -> V_40 = true ;
F_17 ( & V_2 -> V_39 ) ;
F_40 ( V_2 -> V_20 ) ;
return 0 ;
}
static int F_47 ( struct V_56 * V_20 )
{
struct V_1 * V_2 = F_44 ( V_20 ) ;
F_27 ( V_2 -> V_20 ) ;
F_16 ( & V_2 -> V_39 ) ;
F_1 ( V_2 ) ;
V_2 -> V_40 = false ;
F_17 ( & V_2 -> V_39 ) ;
return 0 ;
}
static int T_4 F_48 ( void )
{
return F_49 ( & V_80 ) ;
}
static void T_5 F_50 ( void )
{
F_51 ( & V_80 ) ;
}
