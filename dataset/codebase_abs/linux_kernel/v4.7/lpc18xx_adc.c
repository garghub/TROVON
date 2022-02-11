static int F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
int V_4 ;
T_1 V_5 ;
V_5 = V_2 -> V_6 | F_2 ( V_3 ) | V_7 ;
F_3 ( V_5 , V_2 -> V_8 + V_9 ) ;
V_4 = F_4 ( V_2 -> V_8 + V_10 , V_5 ,
V_5 & V_11 , 3 , 9 ) ;
if ( V_4 ) {
F_5 ( V_2 -> V_12 , L_1 ) ;
return V_4 ;
}
return ( V_5 >> V_13 ) & V_14 ;
}
static int F_6 ( struct V_15 * V_16 ,
struct V_17 const * V_18 ,
int * V_19 , int * V_20 , long V_21 )
{
struct V_1 * V_2 = F_7 ( V_16 ) ;
switch ( V_21 ) {
case V_22 :
F_8 ( & V_2 -> V_23 ) ;
* V_19 = F_1 ( V_2 , V_18 -> V_24 ) ;
F_9 ( & V_2 -> V_23 ) ;
if ( * V_19 < 0 )
return * V_19 ;
return V_25 ;
case V_26 :
* V_19 = F_10 ( V_2 -> V_27 ) / 1000 ;
* V_20 = 10 ;
return V_28 ;
}
return - V_29 ;
}
static int F_11 ( struct V_30 * V_31 )
{
struct V_15 * V_16 ;
struct V_1 * V_2 ;
struct V_32 * V_33 ;
unsigned int V_34 ;
unsigned long V_35 ;
int V_4 ;
V_16 = F_12 ( & V_31 -> V_12 , sizeof( * V_2 ) ) ;
if ( ! V_16 )
return - V_36 ;
F_13 ( V_31 , V_16 ) ;
V_2 = F_7 ( V_16 ) ;
V_2 -> V_12 = & V_31 -> V_12 ;
F_14 ( & V_2 -> V_23 ) ;
V_33 = F_15 ( V_31 , V_37 , 0 ) ;
V_2 -> V_8 = F_16 ( & V_31 -> V_12 , V_33 ) ;
if ( F_17 ( V_2 -> V_8 ) )
return F_18 ( V_2 -> V_8 ) ;
V_2 -> V_38 = F_19 ( & V_31 -> V_12 , NULL ) ;
if ( F_17 ( V_2 -> V_38 ) ) {
F_20 ( & V_31 -> V_12 , L_2 ) ;
return F_18 ( V_2 -> V_38 ) ;
}
V_35 = F_21 ( V_2 -> V_38 ) ;
V_34 = F_22 ( V_35 , V_39 ) ;
V_2 -> V_27 = F_23 ( & V_31 -> V_12 , L_3 ) ;
if ( F_17 ( V_2 -> V_27 ) ) {
F_20 ( & V_31 -> V_12 , L_4 ) ;
return F_18 ( V_2 -> V_27 ) ;
}
V_16 -> V_40 = F_24 ( & V_31 -> V_12 ) ;
V_16 -> V_12 . V_41 = & V_31 -> V_12 ;
V_16 -> V_42 = & V_43 ;
V_16 -> V_44 = V_45 ;
V_16 -> V_46 = V_47 ;
V_16 -> V_48 = F_25 ( V_47 ) ;
V_4 = F_26 ( V_2 -> V_27 ) ;
if ( V_4 ) {
F_20 ( & V_31 -> V_12 , L_5 ) ;
return V_4 ;
}
V_4 = F_27 ( V_2 -> V_38 ) ;
if ( V_4 ) {
F_20 ( & V_31 -> V_12 , L_6 ) ;
goto V_49;
}
V_2 -> V_6 = ( V_34 << V_50 ) |
V_51 ;
F_3 ( V_2 -> V_6 , V_2 -> V_8 + V_9 ) ;
V_4 = F_28 ( V_16 ) ;
if ( V_4 ) {
F_20 ( & V_31 -> V_12 , L_7 ) ;
goto V_52;
}
return 0 ;
V_52:
F_3 ( 0 , V_2 -> V_8 + V_9 ) ;
F_29 ( V_2 -> V_38 ) ;
V_49:
F_30 ( V_2 -> V_27 ) ;
return V_4 ;
}
static int F_31 ( struct V_30 * V_31 )
{
struct V_15 * V_16 = F_32 ( V_31 ) ;
struct V_1 * V_2 = F_7 ( V_16 ) ;
F_33 ( V_16 ) ;
F_3 ( 0 , V_2 -> V_8 + V_9 ) ;
F_29 ( V_2 -> V_38 ) ;
F_30 ( V_2 -> V_27 ) ;
return 0 ;
}
