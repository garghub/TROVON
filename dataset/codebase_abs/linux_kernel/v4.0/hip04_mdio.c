static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_5 ;
for ( V_5 = 0 ; F_2 ( V_4 -> V_6 + V_7 ) & V_8 ; V_5 ++ ) {
if ( V_5 == V_9 )
return - V_10 ;
F_3 ( 20 ) ;
}
return 0 ;
}
static int F_4 ( struct V_1 * V_2 , int V_11 , int V_12 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
T_1 V_13 ;
int V_14 ;
V_14 = F_1 ( V_2 ) ;
if ( V_14 < 0 )
goto V_15;
V_13 = V_12 | ( V_11 << 5 ) | V_16 ;
F_5 ( V_13 , V_4 -> V_6 + V_7 ) ;
V_14 = F_1 ( V_2 ) ;
if ( V_14 < 0 )
goto V_15;
V_13 = F_2 ( V_4 -> V_6 + V_17 ) ;
if ( V_13 & V_18 ) {
F_6 ( V_2 -> V_19 , L_1 ) ;
V_14 = - V_20 ;
goto V_15;
}
V_13 = F_2 ( V_4 -> V_6 + V_21 ) ;
V_14 = V_13 & 0xFFFF ;
V_15:
return V_14 ;
}
static int F_7 ( struct V_1 * V_2 , int V_11 ,
int V_12 , T_2 V_22 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
T_1 V_13 ;
int V_14 ;
V_14 = F_1 ( V_2 ) ;
if ( V_14 < 0 )
goto V_15;
F_5 ( V_22 , V_4 -> V_6 + V_23 ) ;
V_13 = V_12 | ( V_11 << 5 ) | V_24 ;
F_5 ( V_13 , V_4 -> V_6 + V_7 ) ;
V_15:
return V_14 ;
}
static int F_8 ( struct V_1 * V_2 )
{
int V_25 , V_5 ;
for ( V_5 = 0 ; V_5 < V_26 ; V_5 ++ ) {
F_7 ( V_2 , V_5 , 22 , 0 ) ;
V_25 = F_4 ( V_2 , V_5 , V_27 ) ;
if ( V_25 < 0 )
continue;
V_25 |= V_28 ;
if ( F_7 ( V_2 , V_5 , V_27 , V_25 ) < 0 )
continue;
}
F_9 ( 500 ) ;
return 0 ;
}
static int F_10 ( struct V_29 * V_30 )
{
struct V_31 * V_32 ;
struct V_1 * V_2 ;
struct V_3 * V_4 ;
int V_14 ;
V_2 = F_11 ( sizeof( struct V_3 ) ) ;
if ( ! V_2 ) {
F_6 ( & V_30 -> V_33 , L_2 ) ;
return - V_34 ;
}
V_2 -> V_35 = L_3 ;
V_2 -> V_36 = F_4 ;
V_2 -> V_37 = F_7 ;
V_2 -> V_38 = F_8 ;
snprintf ( V_2 -> V_39 , V_40 , L_4 , F_12 ( & V_30 -> V_33 ) ) ;
V_2 -> V_19 = & V_30 -> V_33 ;
V_4 = V_2 -> V_4 ;
V_32 = F_13 ( V_30 , V_41 , 0 ) ;
V_4 -> V_6 = F_14 ( & V_30 -> V_33 , V_32 ) ;
if ( F_15 ( V_4 -> V_6 ) ) {
V_14 = F_16 ( V_4 -> V_6 ) ;
goto V_42;
}
V_14 = F_17 ( V_2 , V_30 -> V_33 . V_43 ) ;
if ( V_14 < 0 ) {
F_6 ( & V_30 -> V_33 , L_5 , V_14 ) ;
goto V_42;
}
F_18 ( V_30 , V_2 ) ;
return 0 ;
V_42:
F_19 ( V_2 ) ;
return V_14 ;
}
static int F_20 ( struct V_29 * V_30 )
{
struct V_1 * V_2 = F_21 ( V_30 ) ;
F_22 ( V_2 ) ;
F_19 ( V_2 ) ;
return 0 ;
}
