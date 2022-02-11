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
V_8 = F_4 ( V_7 -> V_11 ) ;
for ( V_10 = 0 ; V_10 < F_5 ( V_12 ) ; V_10 ++ ) {
if ( ( V_8 / V_12 [ V_10 ] ) <= V_13 )
break;
}
if ( V_10 >= F_5 ( V_12 ) )
return - V_14 ;
V_9 = F_6 ( V_7 -> V_4 . V_15 + V_16 ) ;
V_9 &= ~ V_17 ;
V_9 |= V_10 << V_18 ;
F_7 ( V_9 , V_7 -> V_4 . V_15 + V_16 ) ;
F_8 ( & V_6 -> V_19 , L_1 ,
V_8 / ( V_12 [ V_10 ] * 1000 ) ) ;
return 0 ;
}
static void F_9 ( struct V_20 * V_21 )
{
struct V_1 * V_7 = F_10 ( V_21 ) ;
struct V_22 * V_23 = F_11 ( V_21 ) ;
T_1 V_24 ;
F_12 ( V_23 , V_21 ) ;
V_24 = F_6 ( V_7 -> V_4 . V_15 + V_25 ) ;
if ( V_24 & V_26 )
F_13 ( F_14 ( V_7 -> V_27 , 0 ) ) ;
if ( V_24 & V_28 )
F_13 ( F_14 ( V_7 -> V_27 , 1 ) ) ;
if ( V_24 & V_29 )
F_13 ( F_14 ( V_7 -> V_27 , 2 ) ) ;
F_15 ( V_23 , V_21 ) ;
}
static int F_16 ( struct V_30 * V_31 , unsigned int V_32 ,
T_2 V_33 )
{
F_17 ( V_32 , V_31 -> V_34 ) ;
F_18 ( V_32 , & V_35 , V_36 ) ;
return 0 ;
}
static void F_19 ( struct V_30 * V_31 , unsigned int V_32 )
{
F_18 ( V_32 , NULL , NULL ) ;
F_17 ( V_32 , NULL ) ;
}
static int F_20 ( struct V_5 * V_6 ,
struct V_1 * V_7 )
{
struct V_37 * V_38 = V_6 -> V_19 . V_39 ;
V_7 -> V_32 = F_21 ( V_6 , 0 ) ;
if ( V_7 -> V_32 < 0 ) {
F_22 ( & V_6 -> V_19 , L_2 ) ;
return V_7 -> V_32 ;
}
V_7 -> V_27 = F_23 ( V_38 , V_40 , 0 ,
& V_41 ,
V_7 ) ;
if ( ! V_7 -> V_27 ) {
F_22 ( & V_6 -> V_19 , L_3 ) ;
return - V_42 ;
}
F_24 ( V_7 -> V_32 , F_9 ) ;
F_25 ( V_7 -> V_32 , V_7 ) ;
return 0 ;
}
static void F_26 ( struct V_5 * V_6 ,
struct V_1 * V_7 )
{
int V_33 ;
for ( V_33 = 0 ; V_33 < V_40 ; V_33 ++ )
F_27 ( F_14 ( V_7 -> V_27 , V_33 ) ) ;
F_28 ( V_7 -> V_27 ) ;
F_24 ( V_7 -> V_32 , NULL ) ;
}
static int F_29 ( struct V_5 * V_6 )
{
struct V_1 * V_7 ;
struct V_37 * V_38 = V_6 -> V_19 . V_39 ;
struct V_43 * V_44 ;
int V_45 ;
if ( ! V_6 -> V_19 . V_39 )
return - V_46 ;
V_7 = F_30 ( & V_6 -> V_19 , sizeof( * V_7 ) , V_47 ) ;
if ( ! V_7 )
return - V_42 ;
V_44 = F_31 ( V_6 , V_48 , 0 ) ;
V_7 -> V_4 . V_15 = F_32 ( & V_6 -> V_19 , V_44 ) ;
if ( F_33 ( V_7 -> V_4 . V_15 ) )
return F_34 ( V_7 -> V_4 . V_15 ) ;
V_7 -> V_4 . V_49 = V_44 -> V_50 ;
V_7 -> V_51 = F_35 ( & V_6 -> V_19 , L_4 ) ;
if ( F_33 ( V_7 -> V_51 ) ) {
V_45 = F_34 ( V_7 -> V_51 ) ;
F_22 ( & V_6 -> V_19 , L_5 , V_45 ) ;
return V_45 ;
}
V_45 = F_36 ( V_7 -> V_51 ) ;
if ( V_45 < 0 ) {
F_22 ( & V_6 -> V_19 , L_6 ) ;
return V_45 ;
}
V_45 = F_37 ( V_7 -> V_51 ) ;
if ( V_45 < 0 ) {
F_22 ( & V_6 -> V_19 , L_7 , V_45 ) ;
goto V_52;
}
V_7 -> V_4 . V_53 = V_45 / 1000 ;
F_8 ( & V_6 -> V_19 , L_8 , V_7 -> V_4 . V_53 ) ;
V_7 -> V_11 = F_38 ( & V_6 -> V_19 , L_9 ) ;
if ( F_33 ( V_7 -> V_11 ) ) {
V_45 = F_34 ( V_7 -> V_11 ) ;
F_22 ( & V_6 -> V_19 , L_10 ) ;
goto V_52;
}
V_45 = F_39 ( V_7 -> V_11 ) ;
if ( V_45 < 0 ) {
F_22 ( & V_6 -> V_19 , L_11 ) ;
goto V_52;
}
V_45 = F_3 ( V_6 , V_7 ) ;
if ( V_45 < 0 ) {
F_22 ( & V_6 -> V_19 , L_12 ) ;
goto V_54;
}
V_45 = F_20 ( V_6 , V_7 ) ;
if ( V_45 < 0 )
goto V_54;
F_40 ( V_6 , & V_7 -> V_4 ) ;
V_45 = F_41 ( V_38 , NULL , NULL , & V_6 -> V_19 ) ;
if ( V_45 < 0 ) {
F_22 ( & V_6 -> V_19 , L_13 ) ;
goto V_55;
}
return 0 ;
V_55:
F_26 ( V_6 , V_7 ) ;
V_54:
F_42 ( V_7 -> V_11 ) ;
V_52:
F_43 ( V_7 -> V_51 ) ;
return V_45 ;
}
static int F_44 ( struct V_5 * V_6 )
{
struct V_2 * V_4 = F_45 ( V_6 ) ;
struct V_1 * V_7 = F_1 ( V_4 ) ;
F_46 ( & V_6 -> V_19 ) ;
F_26 ( V_6 , V_7 ) ;
F_42 ( V_7 -> V_11 ) ;
F_43 ( V_7 -> V_51 ) ;
return 0 ;
}
