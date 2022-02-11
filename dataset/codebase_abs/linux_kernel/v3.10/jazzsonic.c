static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
V_3 = F_2 ( V_2 -> V_4 , V_5 , V_6 ,
L_1 , V_2 ) ;
if ( V_3 ) {
F_3 ( V_7 L_2 ,
V_2 -> V_8 , V_2 -> V_4 ) ;
return V_3 ;
}
V_3 = F_4 ( V_2 ) ;
if ( V_3 )
F_5 ( V_2 -> V_4 , V_2 ) ;
return V_3 ;
}
static int F_6 ( struct V_1 * V_2 )
{
int V_9 ;
V_9 = F_7 ( V_2 ) ;
F_5 ( V_2 -> V_4 , V_2 ) ;
return V_9 ;
}
static int F_8 ( struct V_1 * V_2 )
{
static unsigned V_10 ;
unsigned int V_11 ;
unsigned int V_12 ;
struct V_13 * V_14 = F_9 ( V_2 ) ;
int V_9 = - V_15 ;
int V_16 ;
if ( ! F_10 ( V_2 -> V_17 , V_18 , V_19 ) )
return - V_20 ;
V_11 = F_11 ( V_21 ) ;
if ( V_22 > 1 )
F_3 ( L_3 , V_11 ) ;
V_16 = 0 ;
while ( V_23 [ V_16 ] != 0xffff &&
V_23 [ V_16 ] != V_11 )
V_16 ++ ;
if ( V_23 [ V_16 ] == 0xffff ) {
F_3 ( L_4 ,
V_11 ) ;
goto V_24;
}
if ( V_22 && V_10 ++ == 0 )
F_3 ( V_25 ) ;
F_3 ( V_26 L_5 ,
F_12 ( V_14 -> V_27 ) , V_2 -> V_17 ) ;
F_13 ( V_28 , V_29 ) ;
F_13 ( V_30 , 0 ) ;
for ( V_16 = 0 ; V_16 < 3 ; V_16 ++ ) {
V_12 = F_11 ( V_31 - V_16 ) ;
V_2 -> V_32 [ V_16 * 2 ] = V_12 ;
V_2 -> V_32 [ V_16 * 2 + 1 ] = V_12 >> 8 ;
}
V_9 = - V_33 ;
V_14 -> V_34 = V_35 ;
V_14 -> V_36 = F_14 ( V_14 -> V_27 ,
V_37 *
F_15 ( V_14 -> V_34 ) ,
& V_14 -> V_38 ,
V_39 ) ;
if ( V_14 -> V_36 == NULL )
goto V_24;
V_14 -> V_40 = V_14 -> V_36 ;
V_14 -> V_41 = V_14 -> V_40 + ( V_42
* F_15 ( V_14 -> V_34 ) ) ;
V_14 -> V_43 = V_14 -> V_41 + ( V_44 * V_45
* F_15 ( V_14 -> V_34 ) ) ;
V_14 -> V_46 = V_14 -> V_43 + ( V_47 * V_48
* F_15 ( V_14 -> V_34 ) ) ;
V_14 -> V_49 = V_14 -> V_38 ;
V_14 -> V_50 = V_14 -> V_49 + ( V_42
* F_15 ( V_14 -> V_34 ) ) ;
V_14 -> V_51 = V_14 -> V_50 + ( V_44 * V_45
* F_15 ( V_14 -> V_34 ) ) ;
V_14 -> V_52 = V_14 -> V_51 + ( V_47 * V_48
* F_15 ( V_14 -> V_34 ) ) ;
V_2 -> V_53 = & V_54 ;
V_2 -> V_55 = V_56 ;
F_13 ( V_57 , 0xffff ) ;
F_13 ( V_58 , 0xffff ) ;
F_13 ( V_59 , 0xffff ) ;
return 0 ;
V_24:
F_16 ( V_2 -> V_17 , V_18 ) ;
return V_9 ;
}
static int F_17 ( struct V_60 * V_61 )
{
struct V_1 * V_2 ;
struct V_13 * V_14 ;
struct V_62 * V_63 ;
int V_9 = 0 ;
V_63 = F_18 ( V_61 , V_64 , 0 ) ;
if ( ! V_63 )
return - V_15 ;
V_2 = F_19 ( sizeof( struct V_13 ) ) ;
if ( ! V_2 )
return - V_33 ;
V_14 = F_9 ( V_2 ) ;
V_14 -> V_27 = & V_61 -> V_2 ;
F_20 ( V_2 , & V_61 -> V_2 ) ;
F_21 ( V_61 , V_2 ) ;
F_22 ( V_2 ) ;
V_2 -> V_17 = V_63 -> V_65 ;
V_2 -> V_4 = F_23 ( V_61 , 0 ) ;
V_9 = F_8 ( V_2 ) ;
if ( V_9 )
goto V_24;
V_9 = F_24 ( V_2 ) ;
if ( V_9 )
goto V_66;
F_3 ( L_6 , V_2 -> V_8 , V_2 -> V_32 , V_2 -> V_4 ) ;
return 0 ;
V_66:
F_16 ( V_2 -> V_17 , V_18 ) ;
V_24:
F_25 ( V_2 ) ;
return V_9 ;
}
static int F_26 ( struct V_60 * V_61 )
{
struct V_1 * V_2 = F_27 ( V_61 ) ;
struct V_13 * V_14 = F_9 ( V_2 ) ;
F_28 ( V_2 ) ;
F_29 ( V_14 -> V_27 , V_37 * F_15 ( V_14 -> V_34 ) ,
V_14 -> V_36 , V_14 -> V_38 ) ;
F_16 ( V_2 -> V_17 , V_18 ) ;
F_25 ( V_2 ) ;
return 0 ;
}
