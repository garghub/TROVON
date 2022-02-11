static T_1 void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 , struct V_3 , V_2 ) ;
struct V_5 * V_6 = & V_4 -> V_6 ;
V_2 -> V_7 ? F_3 ( V_2 -> V_8 , V_6 ) :
F_4 ( V_2 -> V_8 , V_6 ) ;
}
static T_1 int F_5 ( struct V_9 * V_10 ,
struct V_1 * V_2 )
{
int V_11 ;
struct V_3 * V_4 = F_2 ( V_2 , struct V_3 , V_2 ) ;
struct V_5 * V_6 = & V_4 -> V_6 ;
if ( V_2 -> V_12 ) {
V_2 -> V_8 = V_11 = F_6 ( V_10 , V_2 -> V_12 ) ;
if ( V_11 < 0 ) {
F_7 ( L_1 ,
V_2 -> V_12 , V_10 -> V_13 ) ;
return V_11 ;
}
} else {
V_2 -> V_8 = F_8 ( V_10 , V_2 -> V_14 ) ;
}
if ( ! V_2 -> V_8 ) {
F_7 ( L_2 , V_10 ) ;
return - V_15 ;
}
V_11 = V_2 -> V_7 ?
F_9 ( V_2 -> V_8 , V_2 -> V_16 ,
V_10 -> V_13 , V_6 ) :
F_10 ( V_2 -> V_8 , V_2 -> V_16 ,
V_2 -> V_17 ? V_2 -> V_17 : V_18 ,
V_10 -> V_13 , V_6 ) ;
if ( V_11 ) {
F_7 ( L_3 , V_2 -> V_8 , V_10 ) ;
return V_11 ;
}
V_6 -> V_8 = V_2 -> V_8 ;
return 0 ;
}
static T_1 void F_11 ( struct V_19 * V_20 )
{
V_20 -> V_21 = 0 ;
F_12 ( V_20 -> V_22 ) ;
F_13 ( V_20 -> V_22 ) ;
}
static T_1 int F_14 ( struct V_9 * V_10 ,
struct V_19 * V_20 )
{
int V_11 ;
V_20 -> V_22 = V_20 -> V_12 ? F_15 ( V_10 , V_20 -> V_12 ) :
F_16 ( V_10 , V_20 -> V_14 ) ;
if ( F_17 ( V_20 -> V_22 ) ) {
F_7 ( L_4 , V_10 ) ;
return F_18 ( V_20 -> V_22 ) ;
}
V_11 = F_19 ( V_20 -> V_22 ) ;
if ( V_11 ) {
F_7 ( L_5 , V_10 ) ;
goto V_23;
}
V_20 -> V_21 = F_20 ( V_20 -> V_22 ) ;
if ( ! V_20 -> V_21 ) {
V_11 = - V_15 ;
F_7 ( L_6 , V_10 ) ;
goto V_24;
}
V_20 -> V_25 = F_21 ( V_20 -> V_21 , V_26 ) ;
V_27:
return V_11 ;
V_24:
F_12 ( V_20 -> V_22 ) ;
V_23:
F_13 ( V_20 -> V_22 ) ;
goto V_27;
}
static T_1 void F_22 ( struct V_28 * V_29 )
{
F_23 ( V_29 -> V_30 ) ;
}
static T_1 int F_24 ( struct V_9 * V_10 ,
struct V_28 * V_29 )
{
const char * V_12 = V_29 -> V_12 ? V_29 -> V_12 : V_10 -> V_13 ;
V_29 -> V_30 = F_25 ( V_10 , V_29 -> V_14 , V_12 ) ;
if ( F_17 ( V_29 -> V_30 ) ) {
F_7 ( L_7 , V_12 ) ;
return F_18 ( V_29 -> V_30 ) ;
}
return 0 ;
}
int T_1 F_26 ( struct V_9 * V_10 , struct V_3 * V_4 )
{
int V_11 = - V_15 ;
int V_17 = 0 ;
if ( V_4 -> V_17 & V_31 ) {
V_11 = F_24 ( V_10 , & V_4 -> V_29 ) ;
if ( V_11 )
goto V_32;
V_17 |= V_31 ;
}
if ( V_4 -> V_17 & V_33 ) {
V_11 = F_14 ( V_10 , & V_4 -> V_20 ) ;
if ( V_11 )
goto V_32;
V_17 |= V_33 ;
}
if ( V_4 -> V_17 & V_34 ) {
V_11 = F_5 ( V_10 , & V_4 -> V_2 ) ;
if ( V_11 )
goto V_32;
V_17 |= V_34 ;
}
if ( ! V_4 -> V_6 . V_12 )
V_4 -> V_6 . V_12 = V_10 -> V_12 ;
return V_11 ;
V_32:
if ( V_17 & V_34 )
F_1 ( & V_4 -> V_2 ) ;
if ( V_17 & V_33 )
F_11 ( & V_4 -> V_20 ) ;
if ( V_17 & V_31 )
F_22 ( & V_4 -> V_29 ) ;
return V_11 ;
}
