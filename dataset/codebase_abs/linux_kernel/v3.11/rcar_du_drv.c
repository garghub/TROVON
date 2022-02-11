int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
if ( V_2 -> V_4 )
goto V_5;
V_3 = F_2 ( V_2 -> clock ) ;
if ( V_3 < 0 )
return V_3 ;
F_3 ( V_2 , V_6 , V_7 | V_8 ) ;
F_3 ( V_2 , V_9 , V_10 | V_11 ) ;
F_3 ( V_2 , V_12 , V_13 | V_14 ) ;
F_3 ( V_2 , V_15 , V_16 ) ;
F_3 ( V_2 , V_17 , V_18 | V_19 ) ;
F_3 ( V_2 , V_20 , V_21 | V_22 ) ;
V_5:
V_2 -> V_4 ++ ;
return 0 ;
}
void F_4 ( struct V_1 * V_2 )
{
if ( -- V_2 -> V_4 )
return;
F_5 ( V_2 -> clock ) ;
}
static int F_6 ( struct V_23 * V_24 )
{
F_7 ( V_24 ) ;
F_8 ( V_24 ) ;
F_9 ( V_24 ) ;
F_10 ( V_24 ) ;
V_24 -> V_25 = NULL ;
return 0 ;
}
static int F_11 ( struct V_23 * V_24 , unsigned long V_26 )
{
struct V_27 * V_28 = V_24 -> V_29 ;
struct V_30 * V_31 = V_28 -> V_24 . V_32 ;
struct V_1 * V_2 ;
struct V_33 * V_34 ;
struct V_33 * V_35 ;
int V_3 ;
if ( V_31 == NULL ) {
F_12 ( V_24 -> V_24 , L_1 ) ;
return - V_36 ;
}
V_2 = F_13 ( & V_28 -> V_24 , sizeof( * V_2 ) , V_37 ) ;
if ( V_2 == NULL ) {
F_12 ( V_24 -> V_24 , L_2 ) ;
return - V_38 ;
}
V_2 -> V_24 = & V_28 -> V_24 ;
V_2 -> V_31 = V_31 ;
V_2 -> V_39 = V_24 ;
V_24 -> V_25 = V_2 ;
V_35 = F_14 ( V_28 , V_40 , 0 ) ;
if ( V_35 == NULL ) {
F_12 ( & V_28 -> V_24 , L_3 ) ;
return - V_41 ;
}
V_34 = F_15 ( & V_28 -> V_24 , V_35 -> V_42 ,
F_16 ( V_35 ) , V_28 -> V_43 ) ;
if ( V_34 == NULL ) {
F_12 ( & V_28 -> V_24 , L_4 ) ;
return - V_44 ;
}
V_2 -> V_45 = F_17 ( & V_28 -> V_24 , V_34 -> V_42 ,
F_16 ( V_34 ) ) ;
if ( V_2 -> V_45 == NULL ) {
F_12 ( & V_28 -> V_24 , L_5 ) ;
return - V_38 ;
}
V_2 -> clock = F_18 ( & V_28 -> V_24 , NULL ) ;
if ( F_19 ( V_2 -> clock ) ) {
F_12 ( & V_28 -> V_24 , L_6 ) ;
return - V_46 ;
}
V_3 = F_20 ( V_2 ) ;
if ( V_3 < 0 ) {
F_12 ( & V_28 -> V_24 , L_7 ) ;
goto V_5;
}
V_3 = F_21 ( V_24 , ( 1 << V_2 -> V_47 ) - 1 ) ;
if ( V_3 < 0 ) {
F_12 ( & V_28 -> V_24 , L_8 ) ;
goto V_5;
}
V_3 = F_22 ( V_24 ) ;
if ( V_3 < 0 ) {
F_12 ( & V_28 -> V_24 , L_9 ) ;
goto V_5;
}
F_23 ( V_28 , V_2 ) ;
V_5:
if ( V_3 )
F_6 ( V_24 ) ;
return V_3 ;
}
static void F_24 ( struct V_23 * V_24 , struct V_48 * V_49 )
{
struct V_1 * V_2 = V_24 -> V_25 ;
unsigned int V_50 ;
for ( V_50 = 0 ; V_50 < F_25 ( V_2 -> V_51 ) ; ++ V_50 )
F_26 ( & V_2 -> V_51 [ V_50 ] , V_49 ) ;
}
static T_1 F_27 ( int V_52 , void * V_53 )
{
struct V_23 * V_24 = V_53 ;
struct V_1 * V_2 = V_24 -> V_25 ;
unsigned int V_50 ;
for ( V_50 = 0 ; V_50 < F_25 ( V_2 -> V_51 ) ; ++ V_50 )
F_28 ( & V_2 -> V_51 [ V_50 ] ) ;
return V_54 ;
}
static int F_29 ( struct V_23 * V_24 , int V_55 )
{
struct V_1 * V_2 = V_24 -> V_25 ;
F_30 ( & V_2 -> V_51 [ V_55 ] , true ) ;
return 0 ;
}
static void F_31 ( struct V_23 * V_24 , int V_55 )
{
struct V_1 * V_2 = V_24 -> V_25 ;
F_30 ( & V_2 -> V_51 [ V_55 ] , false ) ;
}
static int F_32 ( struct V_56 * V_24 )
{
struct V_1 * V_2 = F_33 ( V_24 ) ;
F_34 ( V_2 -> V_39 ) ;
return 0 ;
}
static int F_35 ( struct V_56 * V_24 )
{
struct V_1 * V_2 = F_33 ( V_24 ) ;
F_36 ( V_2 -> V_39 ) ;
return 0 ;
}
static int F_37 ( struct V_27 * V_28 )
{
return F_38 ( & V_57 , V_28 ) ;
}
static int F_39 ( struct V_27 * V_28 )
{
F_40 ( & V_57 , V_28 ) ;
return 0 ;
}
