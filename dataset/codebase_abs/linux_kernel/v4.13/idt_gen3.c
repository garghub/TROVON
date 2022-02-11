static int
F_1 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 ,
T_1 V_5 , T_1 V_6 , T_2 V_7 )
{
T_3 V_8 ;
T_3 V_9 = V_7 ;
int V_10 = 0 ;
F_2 ( L_1 ,
V_11 , V_5 , V_6 , V_9 ) ;
if ( V_6 > 0xFF )
return - V_12 ;
if ( V_7 == V_13 )
V_9 = V_14 ;
if ( V_5 == V_15 ) {
V_10 = F_3 ( V_2 , V_3 , V_4 ,
F_4 ( 0 , V_6 ) ,
V_9 ) ;
return V_10 ;
}
V_10 = F_5 ( V_2 , V_3 , V_4 ,
V_16 , & V_8 ) ;
if ( V_10 )
return V_10 ;
if ( V_5 >= F_6 ( V_8 ) )
return - V_12 ;
V_10 = F_3 ( V_2 , V_3 , V_4 ,
F_7 ( V_5 , 0 , V_6 ) ,
V_9 ) ;
return V_10 ;
}
static int
F_8 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 ,
T_1 V_5 , T_1 V_6 , T_2 * V_7 )
{
T_3 V_8 ;
int V_10 ;
if ( V_6 > 0xFF )
return - V_12 ;
V_10 = F_5 ( V_2 , V_3 , V_4 ,
V_16 , & V_8 ) ;
if ( V_10 )
return V_10 ;
if ( V_5 == V_15 )
V_5 = F_9 ( V_8 ) ;
else if ( V_5 >= F_6 ( V_8 ) )
return - V_12 ;
V_10 = F_5 ( V_2 , V_3 , V_4 ,
F_7 ( V_5 , 0 , V_6 ) ,
& V_8 ) ;
if ( V_10 )
return V_10 ;
if ( V_8 == V_14 )
* V_7 = V_13 ;
else
* V_7 = ( T_2 ) V_8 ;
return 0 ;
}
static int
F_10 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 ,
T_1 V_5 )
{
T_3 V_17 ;
T_3 V_8 ;
int V_10 ;
if ( V_5 == V_15 ) {
for ( V_17 = 0 ; V_17 <= 0xff ; V_17 ++ ) {
V_10 = F_3 ( V_2 , V_3 , V_4 ,
F_4 ( 0 , V_17 ) ,
V_14 ) ;
if ( V_10 )
break;
}
return V_10 ;
}
V_10 = F_5 ( V_2 , V_3 , V_4 ,
V_16 , & V_8 ) ;
if ( V_10 )
return V_10 ;
if ( V_5 >= F_6 ( V_8 ) )
return - V_12 ;
for ( V_17 = 0 ; V_17 <= 0xff ; V_17 ++ ) {
V_10 = F_3 ( V_2 , V_3 , V_4 ,
F_7 ( V_5 , 0 , V_17 ) ,
V_14 ) ;
if ( V_10 )
break;
}
return V_10 ;
}
static int
F_11 ( struct V_18 * V_19 )
{
int V_17 , V_20 ;
T_3 V_8 ;
F_2 ( L_2 , V_11 , V_19 -> V_3 , V_19 -> V_4 ) ;
F_12 ( V_19 , V_21 , 0 ) ;
F_12 ( V_19 , V_19 -> V_22 + V_23 ,
V_24 ) ;
V_20 = F_6 ( V_19 -> V_25 ) ;
for ( V_17 = 0 ; V_17 < V_20 ; V_17 ++ ) {
F_13 ( V_19 ,
F_14 ( V_19 , V_17 ) ,
& V_8 ) ;
if ( V_8 & V_26 )
continue;
F_12 ( V_19 ,
V_19 -> V_22 + F_15 ( V_17 ) , 0 ) ;
F_12 ( V_19 ,
V_19 -> V_22 + F_16 ( V_17 ) ,
V_27 | V_28 ) ;
F_12 ( V_19 , F_17 ( V_17 ) ,
V_29 | V_30 ) ;
}
V_20 = F_9 ( V_19 -> V_25 ) ;
F_12 ( V_19 , V_31 , 1 << V_20 ) ;
F_12 ( V_19 , V_19 -> V_22 + V_23 , 0 ) ;
F_12 ( V_19 ,
V_19 -> V_32 + V_33 , 0x8e << 8 ) ;
return 0 ;
}
static int
F_18 ( struct V_18 * V_19 , T_2 V_34 )
{
T_3 V_35 ;
T_3 V_8 ;
F_13 ( V_19 ,
F_14 ( V_19 , V_34 ) ,
& V_35 ) ;
if ( V_35 & V_36 )
return 0 ;
if ( V_35 & ( V_37 |
V_38 ) ) {
F_13 ( V_19 , F_19 ( V_34 ) , & V_8 ) ;
F_12 ( V_19 , F_19 ( V_34 ) ,
V_8 | V_39 ) ;
F_20 ( 10 ) ;
F_12 ( V_19 , F_19 ( V_34 ) , V_8 ) ;
F_21 ( 500 ) ;
}
return 0 ;
}
static int F_22 ( struct V_18 * V_19 , const struct V_40 * V_41 )
{
F_2 ( L_3 , V_11 , F_23 ( V_19 ) ) ;
F_24 ( & V_19 -> V_42 -> V_43 ) ;
if ( V_19 -> V_42 -> V_44 ) {
F_25 ( & V_19 -> V_42 -> V_43 ) ;
return - V_12 ;
}
V_19 -> V_42 -> V_44 = & V_45 ;
if ( V_19 -> V_46 ) {
F_12 ( V_19 , 0x5000 + V_47 , 0 ) ;
}
F_25 ( & V_19 -> V_42 -> V_43 ) ;
return 0 ;
}
static void F_26 ( struct V_18 * V_19 )
{
F_2 ( L_3 , V_11 , F_23 ( V_19 ) ) ;
F_24 ( & V_19 -> V_42 -> V_43 ) ;
if ( V_19 -> V_42 -> V_44 == & V_45 )
V_19 -> V_42 -> V_44 = NULL ;
F_25 ( & V_19 -> V_42 -> V_43 ) ;
}
static void F_27 ( struct V_18 * V_19 )
{
int V_17 ;
T_3 V_8 ;
T_1 V_3 ;
if ( ! V_19 -> V_46 )
return;
F_2 ( L_4 , V_11 , F_23 ( V_19 ) ) ;
F_13 ( V_19 , V_31 , & V_8 ) ;
V_17 = F_9 ( V_19 -> V_25 ) ;
if ( ! ( ( 1 << V_17 ) & V_8 ) )
return;
F_13 ( V_19 , V_19 -> V_22 + V_48 , & V_8 ) ;
if ( V_8 & V_49 )
V_3 = V_8 >> 16 ;
else
V_3 = ( ( V_8 & V_50 ) >> 16 ) ;
if ( V_19 -> V_51 -> V_52 -> V_53 == V_3 ) {
F_12 ( V_19 ,
V_19 -> V_22 + V_23 , 0 ) ;
F_2 ( L_5 ,
V_11 , F_23 ( V_19 ) ) ;
}
}
static int T_4 F_28 ( void )
{
return F_29 ( & V_54 ) ;
}
static void T_5 F_30 ( void )
{
F_2 ( L_6 , V_11 ) ;
F_31 ( & V_54 ) ;
F_2 ( L_7 , V_11 ) ;
}
