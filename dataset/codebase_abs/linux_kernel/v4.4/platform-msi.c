static T_1 F_1 ( struct V_1 * V_2 )
{
T_2 V_3 ;
V_3 = V_2 -> V_4 . V_5 -> V_3 ;
return ( V_3 << ( 32 - V_6 ) ) | V_2 -> V_4 . V_7 ;
}
static void F_2 ( T_3 * V_8 , struct V_1 * V_2 )
{
V_8 -> V_2 = V_2 ;
V_8 -> V_9 = F_1 ( V_2 ) ;
}
static int F_3 ( struct V_10 * V_11 ,
struct V_12 * V_13 ,
unsigned int V_14 , T_1 V_9 ,
T_3 * V_8 )
{
return F_4 ( V_11 , V_14 , V_9 ,
V_13 -> V_15 , V_13 -> V_16 ) ;
}
static void F_5 ( struct V_12 * V_13 )
{
struct V_17 * V_18 = V_13 -> V_18 ;
F_6 ( ! V_18 ) ;
if ( V_18 -> V_19 == NULL )
V_18 -> V_19 = F_3 ;
if ( V_18 -> V_20 == NULL )
V_18 -> V_20 = F_2 ;
}
static void F_7 ( struct V_21 * V_22 , struct V_23 * V_24 )
{
struct V_1 * V_2 = F_8 ( V_22 ) ;
struct V_25 * V_26 ;
V_26 = V_2 -> V_4 . V_5 ;
V_26 -> V_27 ( V_2 , V_24 ) ;
}
static void F_9 ( struct V_12 * V_13 )
{
struct V_28 * V_15 = V_13 -> V_15 ;
F_6 ( ! V_15 ) ;
if ( ! V_15 -> V_29 )
V_15 -> V_29 = V_30 ;
if ( ! V_15 -> V_31 )
V_15 -> V_31 = V_32 ;
if ( ! V_15 -> V_33 )
V_15 -> V_33 = V_34 ;
if ( ! V_15 -> V_35 )
V_15 -> V_35 = V_36 ;
if ( ! V_15 -> V_37 )
V_15 -> V_37 = F_7 ;
}
static void F_10 ( struct V_38 * V_39 )
{
struct V_1 * V_2 , * V_40 ;
F_11 (desc, tmp, dev_to_msi_list(dev), list) {
F_12 ( & V_2 -> V_41 ) ;
F_13 ( V_2 ) ;
}
}
static int F_14 ( struct V_38 * V_39 , int V_42 ,
struct V_25 * V_22 )
{
int V_43 ;
for ( V_43 = 0 ; V_43 < V_42 ; V_43 ++ ) {
struct V_1 * V_2 ;
V_2 = F_15 ( V_39 ) ;
if ( ! V_2 )
break;
V_2 -> V_4 . V_5 = V_22 ;
V_2 -> V_4 . V_7 = V_43 ;
V_2 -> V_44 = 1 ;
F_16 ( & V_2 -> V_41 , F_17 ( V_39 ) ) ;
}
if ( V_43 != V_42 ) {
F_10 ( V_39 ) ;
return - V_45 ;
}
return 0 ;
}
struct V_10 * F_18 ( struct V_46 * V_47 ,
struct V_12 * V_13 ,
struct V_10 * V_48 )
{
struct V_10 * V_11 ;
if ( V_13 -> V_49 & V_50 )
F_5 ( V_13 ) ;
if ( V_13 -> V_49 & V_51 )
F_9 ( V_13 ) ;
V_11 = F_19 ( V_47 , V_13 , V_48 ) ;
if ( V_11 )
V_11 -> V_52 = V_53 ;
return V_11 ;
}
int F_20 ( struct V_38 * V_39 , unsigned int V_42 ,
T_4 V_54 )
{
struct V_25 * V_26 ;
int V_55 ;
if ( ! V_39 -> V_56 || ! V_54 || ! V_42 ||
V_42 > ( 1 << ( 32 - V_6 ) ) )
return - V_57 ;
if ( V_39 -> V_56 -> V_52 != V_53 ) {
F_21 ( V_39 , L_1 ) ;
return - V_57 ;
}
if ( ! F_22 ( F_17 ( V_39 ) ) )
return - V_58 ;
V_26 = F_23 ( sizeof( * V_26 ) , V_59 ) ;
if ( ! V_26 )
return - V_45 ;
V_26 -> V_3 = F_24 ( & V_60 ,
0 , 1 << V_6 , V_59 ) ;
if ( V_26 -> V_3 < 0 ) {
V_55 = V_26 -> V_3 ;
goto V_61;
}
V_26 -> V_27 = V_54 ;
V_55 = F_14 ( V_39 , V_42 , V_26 ) ;
if ( V_55 )
goto V_62;
V_55 = F_25 ( V_39 -> V_56 , V_39 , V_42 ) ;
if ( V_55 )
goto V_63;
return 0 ;
V_63:
F_10 ( V_39 ) ;
V_62:
F_26 ( & V_60 , V_26 -> V_3 ) ;
V_61:
F_27 ( V_26 ) ;
return V_55 ;
}
void F_28 ( struct V_38 * V_39 )
{
struct V_1 * V_2 ;
V_2 = F_29 ( V_39 ) ;
if ( V_2 ) {
struct V_25 * V_22 ;
V_22 = V_2 -> V_4 . V_5 ;
F_26 ( & V_60 , V_22 -> V_3 ) ;
F_27 ( V_22 ) ;
}
F_30 ( V_39 -> V_56 , V_39 ) ;
F_10 ( V_39 ) ;
}
