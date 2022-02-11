static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
V_3 = F_2 ( V_2 -> V_4 , V_5 , 0 , L_1 , V_2 ) ;
if ( V_3 ) {
F_3 ( V_6 L_2 ,
V_2 -> V_7 , V_2 -> V_4 ) ;
return V_3 ;
}
V_3 = F_4 ( V_2 ) ;
if ( V_3 )
F_5 ( V_2 -> V_4 , V_2 ) ;
return V_3 ;
}
static int F_6 ( struct V_1 * V_2 )
{
int V_8 ;
V_8 = F_7 ( V_2 ) ;
F_5 ( V_2 -> V_4 , V_2 ) ;
return V_8 ;
}
static int F_8 ( struct V_1 * V_2 )
{
static unsigned V_9 ;
unsigned int V_10 ;
unsigned int V_11 ;
struct V_12 * V_13 = F_9 ( V_2 ) ;
int V_8 = - V_14 ;
int V_15 ;
if ( ! F_10 ( V_2 -> V_16 , V_17 , V_18 ) )
return - V_19 ;
V_10 = F_11 ( V_20 ) ;
if ( V_21 > 1 )
F_3 ( L_3 , V_10 ) ;
V_15 = 0 ;
while ( V_22 [ V_15 ] != 0xffff &&
V_22 [ V_15 ] != V_10 )
V_15 ++ ;
if ( V_22 [ V_15 ] == 0xffff ) {
F_3 ( L_4 ,
V_10 ) ;
goto V_23;
}
if ( V_21 && V_9 ++ == 0 )
F_3 ( V_24 ) ;
F_3 ( V_25 L_5 ,
F_12 ( V_13 -> V_26 ) , V_2 -> V_16 ) ;
F_13 ( V_27 , V_28 ) ;
F_13 ( V_29 , 0 ) ;
for ( V_15 = 0 ; V_15 < 3 ; V_15 ++ ) {
V_11 = F_11 ( V_30 - V_15 ) ;
V_2 -> V_31 [ V_15 * 2 ] = V_11 ;
V_2 -> V_31 [ V_15 * 2 + 1 ] = V_11 >> 8 ;
}
V_8 = - V_32 ;
V_13 -> V_33 = V_34 ;
V_13 -> V_35 = F_14 ( V_13 -> V_26 ,
V_36 *
F_15 ( V_13 -> V_33 ) ,
& V_13 -> V_37 ,
V_38 ) ;
if ( V_13 -> V_35 == NULL )
goto V_23;
V_13 -> V_39 = V_13 -> V_35 ;
V_13 -> V_40 = V_13 -> V_39 + ( V_41
* F_15 ( V_13 -> V_33 ) ) ;
V_13 -> V_42 = V_13 -> V_40 + ( V_43 * V_44
* F_15 ( V_13 -> V_33 ) ) ;
V_13 -> V_45 = V_13 -> V_42 + ( V_46 * V_47
* F_15 ( V_13 -> V_33 ) ) ;
V_13 -> V_48 = V_13 -> V_37 ;
V_13 -> V_49 = V_13 -> V_48 + ( V_41
* F_15 ( V_13 -> V_33 ) ) ;
V_13 -> V_50 = V_13 -> V_49 + ( V_43 * V_44
* F_15 ( V_13 -> V_33 ) ) ;
V_13 -> V_51 = V_13 -> V_50 + ( V_46 * V_47
* F_15 ( V_13 -> V_33 ) ) ;
V_2 -> V_52 = & V_53 ;
V_2 -> V_54 = V_55 ;
F_13 ( V_56 , 0xffff ) ;
F_13 ( V_57 , 0xffff ) ;
F_13 ( V_58 , 0xffff ) ;
return 0 ;
V_23:
F_16 ( V_2 -> V_16 , V_17 ) ;
return V_8 ;
}
static int F_17 ( struct V_59 * V_60 )
{
struct V_1 * V_2 ;
struct V_12 * V_13 ;
struct V_61 * V_62 ;
int V_8 = 0 ;
V_62 = F_18 ( V_60 , V_63 , 0 ) ;
if ( ! V_62 )
return - V_14 ;
V_2 = F_19 ( sizeof( struct V_12 ) ) ;
if ( ! V_2 )
return - V_32 ;
V_13 = F_9 ( V_2 ) ;
V_13 -> V_26 = & V_60 -> V_2 ;
F_20 ( V_2 , & V_60 -> V_2 ) ;
F_21 ( V_60 , V_2 ) ;
F_22 ( V_2 ) ;
V_2 -> V_16 = V_62 -> V_64 ;
V_2 -> V_4 = F_23 ( V_60 , 0 ) ;
V_8 = F_8 ( V_2 ) ;
if ( V_8 )
goto V_23;
V_8 = F_24 ( V_2 ) ;
if ( V_8 )
goto V_65;
F_3 ( L_6 , V_2 -> V_7 , V_2 -> V_31 , V_2 -> V_4 ) ;
return 0 ;
V_65:
F_16 ( V_2 -> V_16 , V_17 ) ;
V_23:
F_25 ( V_2 ) ;
return V_8 ;
}
static int F_26 ( struct V_59 * V_60 )
{
struct V_1 * V_2 = F_27 ( V_60 ) ;
struct V_12 * V_13 = F_9 ( V_2 ) ;
F_28 ( V_2 ) ;
F_29 ( V_13 -> V_26 , V_36 * F_15 ( V_13 -> V_33 ) ,
V_13 -> V_35 , V_13 -> V_37 ) ;
F_16 ( V_2 -> V_16 , V_17 ) ;
F_25 ( V_2 ) ;
return 0 ;
}
