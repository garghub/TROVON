static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static int F_3 ( struct V_5 * V_6 ,
struct V_1 * V_7 )
{
unsigned long V_8 ;
T_1 V_9 ;
int V_10 ;
if ( ! V_7 -> V_11 ) {
F_4 ( & V_6 -> V_12 , L_1 ) ;
return - V_13 ;
}
V_8 = F_5 ( V_7 -> V_11 ) ;
for ( V_10 = 0 ; V_10 < F_6 ( V_14 ) ; V_10 ++ ) {
if ( ( V_8 / V_14 [ V_10 ] ) <= V_15 )
break;
}
if ( V_10 >= F_6 ( V_14 ) ) {
F_4 ( & V_6 -> V_12 , L_2 ) ;
return - V_16 ;
}
V_7 -> V_4 . V_8 = V_8 / V_14 [ V_10 ] ;
V_9 = F_7 ( V_7 -> V_4 . V_17 + V_18 ) ;
V_9 &= ~ V_19 ;
V_9 |= V_10 << V_20 ;
F_8 ( V_9 , V_7 -> V_4 . V_17 + V_18 ) ;
F_9 ( & V_6 -> V_12 , L_3 ,
V_7 -> V_4 . V_8 / 1000 ) ;
return 0 ;
}
static int F_10 ( struct V_5 * V_6 ,
struct V_1 * V_7 )
{
T_1 V_21 , V_22 , V_9 ;
unsigned long V_8 ;
int V_10 , div ;
if ( ! V_7 -> V_23 ) {
F_4 ( & V_6 -> V_12 , L_4 ) ;
return - V_13 ;
}
if ( V_7 -> V_11 ) {
V_8 = F_5 ( V_7 -> V_11 ) ;
for ( V_10 = 0 ; V_10 < F_6 ( V_24 ) ; V_10 ++ ) {
V_21 = V_24 [ V_10 ] . V_21 ;
V_22 = V_24 [ V_10 ] . V_22 ;
div = V_24 [ V_10 ] . div ;
if ( V_21 )
continue;
if ( ( V_8 / div ) <= V_25 )
goto V_26;
}
}
V_8 = F_5 ( V_7 -> V_23 ) ;
for ( V_10 = 0 ; V_10 < F_6 ( V_24 ) ; V_10 ++ ) {
V_21 = V_24 [ V_10 ] . V_21 ;
V_22 = V_24 [ V_10 ] . V_22 ;
div = V_24 [ V_10 ] . div ;
if ( ! V_21 )
continue;
if ( ( V_8 / div ) <= V_25 )
goto V_26;
}
F_4 ( & V_6 -> V_12 , L_2 ) ;
return - V_16 ;
V_26:
V_7 -> V_4 . V_8 = V_8 / div ;
V_9 = F_7 ( V_7 -> V_4 . V_17 + V_27 ) ;
V_9 &= ~ ( V_28 | V_29 ) ;
V_9 |= V_21 << V_30 ;
V_9 |= V_22 << V_31 ;
F_8 ( V_9 , V_7 -> V_4 . V_17 + V_27 ) ;
F_9 ( & V_6 -> V_12 , L_5 ,
V_21 ? L_6 : L_7 , div , V_7 -> V_4 . V_8 / 1000 ) ;
return 0 ;
}
static void F_11 ( struct V_32 * V_33 )
{
struct V_1 * V_7 = F_12 ( V_33 ) ;
struct V_34 * V_35 = F_13 ( V_33 ) ;
T_1 V_36 ;
F_14 ( V_35 , V_33 ) ;
V_36 = F_7 ( V_7 -> V_4 . V_17 + V_7 -> V_37 -> V_38 -> V_39 ) ;
if ( V_36 & V_7 -> V_37 -> V_38 -> V_40 )
F_15 ( F_16 ( V_7 -> V_41 , 0 ) ) ;
if ( V_36 & V_7 -> V_37 -> V_38 -> V_42 )
F_15 ( F_16 ( V_7 -> V_41 , 1 ) ) ;
if ( V_36 & V_7 -> V_37 -> V_38 -> V_43 )
F_15 ( F_16 ( V_7 -> V_41 , 2 ) ) ;
F_17 ( V_35 , V_33 ) ;
}
static int F_18 ( struct V_44 * V_45 , unsigned int V_46 ,
T_2 V_47 )
{
F_19 ( V_46 , V_45 -> V_48 ) ;
F_20 ( V_46 , & V_49 , V_50 ) ;
return 0 ;
}
static void F_21 ( struct V_44 * V_45 , unsigned int V_46 )
{
F_20 ( V_46 , NULL , NULL ) ;
F_19 ( V_46 , NULL ) ;
}
static int F_22 ( struct V_5 * V_6 ,
struct V_1 * V_7 )
{
struct V_51 * V_52 = V_6 -> V_12 . V_53 ;
V_7 -> V_46 = F_23 ( V_6 , 0 ) ;
if ( V_7 -> V_46 < 0 ) {
F_4 ( & V_6 -> V_12 , L_8 ) ;
return V_7 -> V_46 ;
}
V_7 -> V_41 = F_24 ( V_52 , V_54 , 0 ,
& V_55 ,
V_7 ) ;
if ( ! V_7 -> V_41 ) {
F_4 ( & V_6 -> V_12 , L_9 ) ;
return - V_56 ;
}
F_25 ( V_7 -> V_46 , F_11 ) ;
F_26 ( V_7 -> V_46 , V_7 ) ;
return 0 ;
}
static void F_27 ( struct V_5 * V_6 ,
struct V_1 * V_7 )
{
int V_47 ;
for ( V_47 = 0 ; V_47 < V_54 ; V_47 ++ )
F_28 ( F_16 ( V_7 -> V_41 , V_47 ) ) ;
F_29 ( V_7 -> V_41 ) ;
F_25 ( V_7 -> V_46 , NULL ) ;
}
static int F_30 ( struct V_5 * V_6 )
{
struct V_1 * V_7 ;
struct V_57 * V_12 = & V_6 -> V_12 ;
struct V_51 * V_52 = V_6 -> V_12 . V_53 ;
struct V_58 * V_59 ;
int V_60 ;
if ( ! V_6 -> V_12 . V_53 )
return - V_61 ;
V_7 = F_31 ( & V_6 -> V_12 , sizeof( * V_7 ) , V_62 ) ;
if ( ! V_7 )
return - V_56 ;
V_7 -> V_37 = ( const struct V_63 * )
F_32 ( V_12 -> V_64 -> V_65 , V_12 ) -> V_66 ;
V_59 = F_33 ( V_6 , V_67 , 0 ) ;
V_7 -> V_4 . V_17 = F_34 ( & V_6 -> V_12 , V_59 ) ;
if ( F_35 ( V_7 -> V_4 . V_17 ) )
return F_36 ( V_7 -> V_4 . V_17 ) ;
V_7 -> V_4 . V_68 = V_59 -> V_69 ;
V_7 -> V_70 = F_37 ( & V_6 -> V_12 , L_10 ) ;
if ( F_35 ( V_7 -> V_70 ) ) {
V_60 = F_36 ( V_7 -> V_70 ) ;
F_4 ( & V_6 -> V_12 , L_11 , V_60 ) ;
return V_60 ;
}
V_60 = F_38 ( V_7 -> V_70 ) ;
if ( V_60 < 0 ) {
F_4 ( & V_6 -> V_12 , L_12 ) ;
return V_60 ;
}
V_60 = F_39 ( V_7 -> V_70 ) ;
if ( V_60 < 0 ) {
F_4 ( & V_6 -> V_12 , L_13 , V_60 ) ;
goto V_71;
}
V_7 -> V_4 . V_72 = V_60 / 1000 ;
F_9 ( & V_6 -> V_12 , L_14 , V_7 -> V_4 . V_72 ) ;
V_7 -> V_11 = F_40 ( & V_6 -> V_12 , L_7 ) ;
if ( F_35 ( V_7 -> V_11 ) ) {
V_60 = F_36 ( V_7 -> V_11 ) ;
if ( V_60 == - V_13 ) {
V_7 -> V_11 = NULL ;
} else {
F_4 ( & V_6 -> V_12 , L_15 ) ;
goto V_71;
}
}
if ( V_7 -> V_11 ) {
V_60 = F_41 ( V_7 -> V_11 ) ;
if ( V_60 < 0 ) {
F_4 ( & V_6 -> V_12 , L_16 ) ;
goto V_71;
}
}
V_7 -> V_23 = F_40 ( & V_6 -> V_12 , L_6 ) ;
if ( F_35 ( V_7 -> V_23 ) ) {
V_60 = F_36 ( V_7 -> V_23 ) ;
if ( V_60 == - V_13 ) {
V_7 -> V_23 = NULL ;
} else {
F_4 ( & V_6 -> V_12 , L_17 ) ;
goto V_73;
}
}
if ( V_7 -> V_23 ) {
V_60 = F_41 ( V_7 -> V_23 ) ;
if ( V_60 < 0 ) {
F_4 ( & V_6 -> V_12 , L_16 ) ;
goto V_73;
}
}
V_60 = V_7 -> V_37 -> V_74 ( V_6 , V_7 ) ;
if ( V_60 < 0 )
goto V_75;
V_60 = F_22 ( V_6 , V_7 ) ;
if ( V_60 < 0 )
goto V_75;
F_42 ( V_6 , & V_7 -> V_4 ) ;
V_60 = F_43 ( V_52 , NULL , NULL , & V_6 -> V_12 ) ;
if ( V_60 < 0 ) {
F_4 ( & V_6 -> V_12 , L_18 ) ;
goto V_76;
}
return 0 ;
V_76:
F_27 ( V_6 , V_7 ) ;
V_75:
if ( V_7 -> V_23 )
F_44 ( V_7 -> V_23 ) ;
V_73:
if ( V_7 -> V_11 )
F_44 ( V_7 -> V_11 ) ;
V_71:
F_45 ( V_7 -> V_70 ) ;
return V_60 ;
}
static int F_46 ( struct V_5 * V_6 )
{
struct V_2 * V_4 = F_47 ( V_6 ) ;
struct V_1 * V_7 = F_1 ( V_4 ) ;
F_48 ( & V_6 -> V_12 ) ;
F_27 ( V_6 , V_7 ) ;
if ( V_7 -> V_23 )
F_44 ( V_7 -> V_23 ) ;
if ( V_7 -> V_11 )
F_44 ( V_7 -> V_11 ) ;
F_45 ( V_7 -> V_70 ) ;
return 0 ;
}
