static void F_1 ( struct V_1 * V_2 )
{
int V_3 ;
#define F_2 (45)
F_3 ( & V_2 -> V_4 ) ;
V_2 -> V_5 -> V_6 ( V_2 ) ;
V_2 -> V_5 -> V_7 ( V_2 ) ;
for ( V_3 = 0 ; V_3 < F_2 ; V_3 ++ ) {
if ( V_2 -> V_5 -> V_8 ( V_2 ) )
goto V_9;
F_4 ( 1000 ) ;
}
F_5 ( V_2 , V_10 ) ;
V_9:
F_6 ( & V_2 -> V_4 ) ;
}
void F_7 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_13 ;
V_12 -> V_14 = F_8 ( V_15 ) ;
V_12 -> V_16 = V_2 -> V_17 ;
V_12 -> V_18 = - 1 ;
V_12 -> V_19 = - 1 ;
V_12 -> V_20 = 0 ;
V_12 -> V_21 = 0 ;
}
int F_9 ( struct V_1 * V_2 , const char * V_22 )
{
int V_23 ;
F_10 ( & V_2 -> V_24 ) ;
V_25:
if ( V_26 != V_2 -> V_27 ) {
V_23 = - V_28 ;
goto V_29;
}
if ( ! V_2 -> V_5 -> V_8 ( V_2 ) ) {
F_1 ( V_2 ) ;
goto V_25;
}
V_23 = V_2 -> V_5 -> V_30 ( V_2 , V_22 ) ;
if ( V_23 )
goto V_29;
F_11 ( V_2 ) ;
F_12 ( V_2 ) ;
V_2 -> V_31 -> V_32 ( V_2 ) ;
V_2 -> V_5 -> V_33 ( V_2 , V_34 , V_2 -> V_35 ) ;
V_2 -> V_5 -> V_33 ( V_2 , V_36 , V_2 -> V_35 >> 32 ) ;
V_2 -> V_5 -> V_37 ( V_2 ) ;
F_5 ( V_2 , V_38 ) ;
V_29:
F_13 ( & V_2 -> V_24 ) ;
return V_23 ;
}
void F_14 ( struct V_1 * V_2 , bool V_39 )
{
F_10 ( & V_2 -> V_24 ) ;
if ( V_26 != V_2 -> V_27 || V_39 ) {
F_15 ( V_2 ) ;
F_7 ( V_2 ) ;
F_1 ( V_2 ) ;
if ( V_10 == V_2 -> V_27 )
goto V_40;
F_16 ( V_2 , V_41 ) ;
if ( V_42 != V_2 -> V_27 )
F_5 ( V_2 , V_26 ) ;
}
V_40:
F_13 ( & V_2 -> V_24 ) ;
}
void F_17 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_13 ;
T_1 V_43 = V_12 -> V_18 ;
F_10 ( & V_2 -> V_24 ) ;
if ( V_38 == V_2 -> V_27 && V_43 != - 1 ) {
V_12 -> V_21 = 1 ;
V_2 -> V_5 -> V_44 ( V_2 , V_43 ) ;
F_5 ( V_2 , V_45 ) ;
}
F_13 ( & V_2 -> V_24 ) ;
}
void F_18 ( struct V_46 * V_47 )
{
struct V_1 * V_2 = F_19 ( V_47 , struct V_1 ,
V_48 ) ;
struct V_11 * V_12 = V_2 -> V_13 ;
F_10 ( & V_2 -> V_24 ) ;
F_16 ( V_2 , V_12 -> V_20 ) ;
V_12 -> V_20 = 0 ;
if ( V_45 != V_2 -> V_27 &&
V_42 != V_2 -> V_27 )
F_5 ( V_2 , V_45 ) ;
F_13 ( & V_2 -> V_24 ) ;
}
void F_20 ( struct V_46 * V_47 )
{
struct V_1 * V_2 = F_19 ( V_47 , struct V_1 ,
V_49 ) ;
F_14 ( V_2 , false ) ;
}
void F_21 ( struct V_1 * V_2 )
{
if ( V_2 -> V_27 != V_42 ) {
F_22 ( V_2 -> V_50 -> V_51 , L_1 ,
V_2 -> V_27 , V_42 ) ;
return;
}
if ( ! V_2 -> V_5 -> V_8 ( V_2 ) )
F_14 ( V_2 , true ) ;
F_10 ( & V_2 -> V_24 ) ;
F_5 ( V_2 , V_26 ) ;
F_13 ( & V_2 -> V_24 ) ;
}
void F_23 ( struct V_1 * V_2 )
{
int V_23 ;
#define F_24 (60 * HZ)
F_10 ( & V_2 -> V_24 ) ;
switch ( V_2 -> V_27 ) {
case V_26 :
F_5 ( V_2 , V_42 ) ;
F_13 ( & V_2 -> V_24 ) ;
break;
case V_38 :
F_5 ( V_2 , V_52 ) ;
F_13 ( & V_2 -> V_24 ) ;
V_23 = F_25 ( & V_2 -> V_4 ,
F_24 ) ;
if ( ! V_23 ) {
F_10 ( & V_2 -> V_24 ) ;
F_5 ( V_2 , V_42 ) ;
F_13 ( & V_2 -> V_24 ) ;
F_14 ( V_2 , true ) ;
}
break;
case V_45 :
F_5 ( V_2 , V_42 ) ;
F_13 ( & V_2 -> V_24 ) ;
V_23 = F_25 ( & V_2 -> V_4 ,
F_24 ) ;
if ( ! V_23 )
F_14 ( V_2 , true ) ;
break;
default:
F_13 ( & V_2 -> V_24 ) ;
break;
}
}
void F_26 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_13 ;
T_1 V_43 = V_12 -> V_18 ;
F_10 ( & V_2 -> V_24 ) ;
if ( V_52 == V_2 -> V_27 && V_43 != - 1 ) {
V_12 -> V_21 = 1 ;
V_2 -> V_5 -> V_44 ( V_2 , V_43 ) ;
F_5 ( V_2 , V_42 ) ;
}
F_13 ( & V_2 -> V_24 ) ;
}
