static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
F_2 ( F_3 ( V_5 ) | V_6 , V_5 ) ;
F_4 ( V_4 , 1 , V_7 | V_8 ) ;
return V_9 ;
}
static T_1 F_5 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
F_2 ( F_3 ( V_5 ) | V_10 , V_5 ) ;
F_4 ( V_4 , 1 , V_11 | V_8 ) ;
return V_9 ;
}
static void F_6 ( struct V_12 * V_13 , int V_14 )
{
unsigned int V_15 ;
F_7 ( V_13 , L_1 , V_16 , V_14 ) ;
V_15 = F_3 ( V_5 ) & ~ V_17 ;
if ( V_14 )
V_15 |= V_17 ;
F_2 ( V_15 , V_5 ) ;
}
static int F_8 ( struct V_12 * V_13 , int V_18 )
{
unsigned int V_15 ;
F_7 ( V_13 , L_2 , V_16 , V_18 ) ;
F_9 ( & V_19 ) ;
V_15 = F_3 ( V_5 ) & ~ V_20 ;
if ( V_18 )
V_15 |= V_20 ;
F_2 ( V_15 , V_5 ) ;
F_10 ( & V_19 ) ;
return 0 ;
}
static int F_11 ( struct V_12 * V_13 , struct V_21 * V_22 )
{
F_12 ( F_3 ( V_23 ) , V_22 ) ;
F_7 ( V_13 , L_3 ,
V_22 -> V_24 , V_22 -> V_25 , V_22 -> V_26 ,
V_22 -> V_27 , V_22 -> V_28 , V_22 -> V_29 ) ;
return 0 ;
}
static int F_13 ( struct V_12 * V_13 , struct V_21 * V_30 )
{
unsigned long V_31 = 0 ;
F_7 ( V_13 , L_4 ,
V_30 -> V_24 , V_30 -> V_25 , V_30 -> V_26 ,
V_30 -> V_27 , V_30 -> V_28 , V_30 -> V_29 ) ;
F_14 ( V_30 , & V_31 ) ;
F_2 ( V_31 , V_23 ) ;
return 0 ;
}
static int F_15 ( struct V_12 * V_13 , struct V_32 * V_33 )
{
struct V_21 * V_34 = & V_33 -> time ;
F_12 ( F_3 ( V_35 ) , V_34 ) ;
V_33 -> V_18 = F_3 ( V_5 ) & V_17 ;
F_7 ( V_13 , L_5 ,
V_33 -> V_18 ,
V_34 -> V_24 , V_34 -> V_25 , V_34 -> V_26 ,
V_34 -> V_27 , V_34 -> V_28 , V_34 -> V_29 ) ;
return 0 ;
}
static int F_16 ( struct V_12 * V_13 , struct V_32 * V_33 )
{
struct V_21 * V_30 = & V_33 -> time ;
unsigned long V_36 = 0 ;
F_7 ( V_13 , L_6 ,
V_33 -> V_18 ,
V_30 -> V_26 & 0xff , V_30 -> V_25 & 0xff , V_30 -> V_24 & 0xff ,
V_30 -> V_27 & 0xff , V_30 -> V_28 & 0xff , V_30 -> V_29 ) ;
F_14 ( V_30 , & V_36 ) ;
F_2 ( V_36 , V_35 ) ;
F_6 ( V_13 , V_33 -> V_18 ) ;
if ( V_33 -> V_18 )
F_17 ( V_37 ) ;
else
F_18 ( V_37 ) ;
return 0 ;
}
static int F_19 ( struct V_12 * V_13 , struct V_38 * V_39 )
{
F_20 ( V_39 , L_7 ,
( F_3 ( V_5 ) & V_20 ) ? L_8 : L_9 ) ;
return 0 ;
}
static int F_21 ( struct V_12 * V_13 )
{
struct V_40 * V_41 = F_22 ( V_13 ) ;
struct V_3 * V_42 = F_23 ( V_41 ) ;
int V_43 ;
V_43 = F_24 ( V_37 , F_1 ,
0 , L_10 , V_42 ) ;
if ( V_43 ) {
F_25 ( V_13 , L_11 , V_37 , V_43 ) ;
return V_43 ;
}
V_43 = F_24 ( V_44 , F_5 ,
0 , L_12 , V_42 ) ;
if ( V_43 ) {
F_25 ( V_13 , L_11 , V_44 , V_43 ) ;
goto V_45;
}
return V_43 ;
V_45:
F_26 ( V_37 , V_42 ) ;
return V_43 ;
}
static void F_27 ( struct V_12 * V_13 )
{
struct V_40 * V_41 = F_22 ( V_13 ) ;
struct V_3 * V_42 = F_23 ( V_41 ) ;
F_8 ( V_13 , 0 ) ;
F_26 ( V_37 , V_42 ) ;
F_26 ( V_44 , V_42 ) ;
}
static void F_28 ( struct V_12 * V_13 , int V_46 )
{
if ( ! V_46 ) {
F_2 ( F_3 ( V_5 ) & ~ V_20 , V_5 ) ;
} else {
if ( ( F_3 ( V_5 ) & V_20 ) == 0 ) {
F_29 ( V_13 , L_13 ) ;
F_2 ( F_3 ( V_5 ) | V_20 , V_5 ) ;
}
}
}
static int F_30 ( struct V_40 * V_13 )
{
struct V_3 * V_47 = F_23 ( V_13 ) ;
F_31 ( V_47 ) ;
F_8 ( & V_13 -> V_13 , 0 ) ;
F_6 ( & V_13 -> V_13 , 0 ) ;
F_32 ( V_48 ) ;
F_33 ( V_48 ) ;
return 0 ;
}
static int F_34 ( struct V_40 * V_41 )
{
struct V_3 * V_47 ;
struct V_49 * V_50 ;
int V_43 ;
F_7 ( & V_41 -> V_13 , L_14 , V_16 , V_41 ) ;
V_44 = F_35 ( V_41 , 1 ) ;
if ( V_44 < 0 ) {
F_25 ( & V_41 -> V_13 , L_15 ) ;
return - V_51 ;
}
V_37 = F_35 ( V_41 , 0 ) ;
if ( V_37 < 0 ) {
F_25 ( & V_41 -> V_13 , L_16 ) ;
return - V_51 ;
}
F_7 ( & V_41 -> V_13 , L_17 ,
V_44 , V_37 ) ;
V_50 = F_36 ( V_41 , V_52 , 0 ) ;
if ( V_50 == NULL ) {
F_25 ( & V_41 -> V_13 , L_18 ) ;
return - V_51 ;
}
V_48 = F_37 ( V_50 -> V_53 , F_38 ( V_50 ) ,
V_41 -> V_54 ) ;
if ( V_48 == NULL ) {
F_25 ( & V_41 -> V_13 , L_19 ) ;
V_43 = - V_51 ;
goto V_55;
}
F_28 ( & V_41 -> V_13 , 1 ) ;
V_47 = F_39 ( L_20 , & V_41 -> V_13 , & V_56 ,
V_57 ) ;
if ( F_40 ( V_47 ) ) {
F_25 ( & V_41 -> V_13 , L_21 ) ;
V_43 = F_41 ( V_47 ) ;
goto V_58;
}
if ( ! F_42 ( & V_41 -> V_13 ) )
F_43 ( & V_41 -> V_13 , 1 ) ;
F_44 ( V_41 , V_47 ) ;
return 0 ;
V_58:
F_28 ( & V_41 -> V_13 , 0 ) ;
F_32 ( V_48 ) ;
V_55:
return V_43 ;
}
static int F_45 ( struct V_12 * V_13 )
{
V_59 = F_3 ( V_35 ) ;
F_28 ( V_13 , 0 ) ;
return 0 ;
}
static int F_46 ( struct V_12 * V_13 )
{
F_28 ( V_13 , 1 ) ;
F_2 ( V_59 , V_35 ) ;
return 0 ;
}
