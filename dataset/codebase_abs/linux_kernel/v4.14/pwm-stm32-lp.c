static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static int F_3 ( struct V_2 * V_3 , struct V_4 * V_5 ,
struct V_6 * V_7 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
unsigned long long V_9 , div , V_10 ;
struct V_6 V_11 ;
T_1 V_12 , V_13 , V_14 , V_15 = 0 ;
bool V_16 ;
int V_17 ;
F_4 ( V_5 , & V_11 ) ;
V_16 = ! V_11 . V_18 ;
if ( ! V_7 -> V_18 ) {
if ( V_11 . V_18 ) {
V_17 = F_5 ( V_8 -> V_19 , V_20 , 0 ) ;
if ( V_17 )
return V_17 ;
F_6 ( V_8 -> V_21 ) ;
}
return 0 ;
}
div = ( unsigned long long ) F_7 ( V_8 -> V_21 ) * V_7 -> V_22 ;
F_8 ( div , V_23 ) ;
V_9 = div ;
while ( div > V_24 ) {
V_15 ++ ;
if ( ( 1 << V_15 ) > V_25 ) {
F_9 ( V_8 -> V_3 . V_26 , L_1 ) ;
return - V_27 ;
}
div = V_9 >> V_15 ;
}
V_9 = div ;
V_10 = V_9 * V_7 -> V_28 ;
F_8 ( V_10 , V_7 -> V_22 ) ;
if ( ! V_11 . V_18 ) {
V_17 = F_10 ( V_8 -> V_21 ) ;
if ( V_17 )
return V_17 ;
}
V_17 = F_11 ( V_8 -> V_19 , V_29 , & V_14 ) ;
if ( V_17 )
goto V_30;
if ( ( F_12 ( V_31 , V_14 ) != V_15 ) ||
( F_12 ( V_32 , V_14 ) != V_7 -> V_33 ) ) {
V_12 = F_13 ( V_31 , V_15 ) ;
V_12 |= F_13 ( V_32 , V_7 -> V_33 ) ;
V_13 = V_31 | V_32 ;
V_16 = true ;
V_17 = F_5 ( V_8 -> V_19 , V_20 , 0 ) ;
if ( V_17 )
goto V_30;
V_17 = F_14 ( V_8 -> V_19 , V_29 , V_13 ,
V_12 ) ;
if ( V_17 )
goto V_30;
}
if ( V_16 ) {
V_17 = F_5 ( V_8 -> V_19 , V_20 ,
V_34 ) ;
if ( V_17 )
goto V_30;
}
V_17 = F_5 ( V_8 -> V_19 , V_35 , V_9 - 1 ) ;
if ( V_17 )
goto V_30;
V_17 = F_5 ( V_8 -> V_19 , V_36 , V_9 - ( 1 + V_10 ) ) ;
if ( V_17 )
goto V_30;
V_17 = F_15 ( V_8 -> V_19 , V_37 , V_12 ,
( V_12 & V_38 ) ,
100 , 1000 ) ;
if ( V_17 ) {
F_9 ( V_8 -> V_3 . V_26 , L_2 ) ;
goto V_30;
}
V_17 = F_5 ( V_8 -> V_19 , V_39 ,
V_40 ) ;
if ( V_17 )
goto V_30;
if ( V_16 ) {
V_17 = F_14 ( V_8 -> V_19 , V_20 ,
V_41 ,
V_41 ) ;
if ( V_17 ) {
F_5 ( V_8 -> V_19 , V_20 , 0 ) ;
goto V_30;
}
}
return 0 ;
V_30:
if ( ! V_11 . V_18 )
F_6 ( V_8 -> V_21 ) ;
return V_17 ;
}
static void F_16 ( struct V_2 * V_3 ,
struct V_4 * V_5 ,
struct V_6 * V_7 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
unsigned long V_42 = F_7 ( V_8 -> V_21 ) ;
T_1 V_12 , V_15 , V_9 ;
T_2 V_43 ;
F_11 ( V_8 -> V_19 , V_20 , & V_12 ) ;
V_7 -> V_18 = ! ! F_12 ( V_34 , V_12 ) ;
if ( V_7 -> V_18 )
F_10 ( V_8 -> V_21 ) ;
F_11 ( V_8 -> V_19 , V_29 , & V_12 ) ;
V_15 = F_12 ( V_31 , V_12 ) ;
V_7 -> V_33 = F_12 ( V_32 , V_12 ) ;
F_11 ( V_8 -> V_19 , V_35 , & V_9 ) ;
V_43 = V_9 + 1 ;
V_43 = ( V_43 << V_15 ) * V_23 ;
V_7 -> V_22 = F_17 ( V_43 , V_42 ) ;
F_11 ( V_8 -> V_19 , V_36 , & V_12 ) ;
V_43 = V_9 - V_12 ;
V_43 = ( V_43 << V_15 ) * V_23 ;
V_7 -> V_28 = F_17 ( V_43 , V_42 ) ;
}
static int F_18 ( struct V_44 * V_45 )
{
struct V_46 * V_47 = F_19 ( V_45 -> V_26 . V_48 ) ;
struct V_1 * V_8 ;
int V_17 ;
V_8 = F_20 ( & V_45 -> V_26 , sizeof( * V_8 ) , V_49 ) ;
if ( ! V_8 )
return - V_50 ;
V_8 -> V_19 = V_47 -> V_19 ;
V_8 -> V_21 = V_47 -> V_21 ;
V_8 -> V_3 . V_51 = - 1 ;
V_8 -> V_3 . V_26 = & V_45 -> V_26 ;
V_8 -> V_3 . V_52 = & V_53 ;
V_8 -> V_3 . V_54 = 1 ;
V_17 = F_21 ( & V_8 -> V_3 ) ;
if ( V_17 < 0 )
return V_17 ;
F_22 ( V_45 , V_8 ) ;
return 0 ;
}
static int F_23 ( struct V_44 * V_45 )
{
struct V_1 * V_8 = F_24 ( V_45 ) ;
unsigned int V_55 ;
for ( V_55 = 0 ; V_55 < V_8 -> V_3 . V_54 ; V_55 ++ )
if ( F_25 ( & V_8 -> V_3 . V_56 [ V_55 ] ) )
F_26 ( & V_8 -> V_3 . V_56 [ V_55 ] ) ;
return F_27 ( & V_8 -> V_3 ) ;
}
