static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 , V_2 -> V_4 ) ;
F_3 ( V_2 ) ;
}
static int F_4 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_7 ;
F_1 ( V_2 ) ;
V_8 [ V_6 -> V_9 ] = NULL ;
V_6 -> V_10 = NULL ;
F_5 ( V_6 ) ;
return 0 ;
}
static int F_6 ( struct V_11 * V_12 )
{
struct V_5 * V_13 = V_12 -> V_14 ;
return F_4 ( V_13 ) ;
}
static int F_7 ( struct V_1 * V_2 )
{
int V_15 , V_16 ;
struct V_5 * V_6 ;
struct V_17 * V_10 ;
static struct V_18 V_19 = {
. V_20 = F_6 ,
} ;
F_8 ( V_21 L_1 ) ;
for ( V_15 = 0 ; V_15 < V_22 ; V_15 ++ ) {
if ( ! V_8 [ V_15 ] )
break;
}
if ( V_15 >= V_22 ) {
F_9 ( V_23 L_2 ) ;
return - V_24 ;
}
if ( ! V_25 [ V_15 ] )
return - V_26 ;
V_16 = F_10 ( & V_2 -> V_27 , V_9 [ V_15 ] , V_28 [ V_15 ] , V_29 ,
0 , & V_10 ) ;
if ( V_16 < 0 ) {
F_9 ( V_23 L_3 ) ;
return V_16 ;
}
V_6 = F_11 ( V_10 ) ;
if ( ! V_6 ) {
F_12 ( V_10 ) ;
return - V_30 ;
}
V_16 = F_13 ( V_10 , V_31 , V_6 , & V_19 ) ;
if ( V_16 < 0 ) {
F_5 ( V_6 ) ;
F_12 ( V_10 ) ;
return V_16 ;
}
V_6 -> V_9 = V_15 ;
V_8 [ V_15 ] = V_10 ;
V_6 -> V_7 = V_2 ;
V_2 -> V_4 = V_6 ;
V_2 -> V_32 [ 0 ] -> V_33 |= V_34 ;
V_2 -> V_32 [ 0 ] -> V_35 = 16 ;
V_2 -> V_36 = V_37 | V_38 ;
V_2 -> V_39 = 1 ;
V_2 -> V_40 = V_41 ;
return F_14 ( V_2 ) ;
}
static int F_15 ( struct V_5 * V_6 , int V_42 , int V_3 )
{
int V_16 ;
struct V_17 * V_10 = V_6 -> V_10 ;
F_8 ( V_21 L_4 , V_42 , V_3 ) ;
V_6 -> V_42 = V_42 ;
V_6 -> V_3 = V_3 ;
V_6 -> V_43 |= V_44 ;
V_16 = F_16 ( V_6 ) ;
if ( V_16 < 0 )
return V_16 ;
strcpy ( V_10 -> V_45 , L_5 ) ;
sprintf ( V_10 -> V_46 , L_6 , V_10 -> V_45 ) ;
sprintf ( V_10 -> V_47 , L_7 ,
V_10 -> V_46 , V_42 , V_3 ) ;
V_16 = F_17 ( V_6 ) ;
if ( V_16 < 0 )
return V_16 ;
if ( ( V_16 = F_18 ( V_10 ) ) < 0 )
return V_16 ;
return 0 ;
}
static void F_19 ( struct V_1 * V_2 )
{
struct V_5 * V_13 = V_2 -> V_4 ;
F_8 ( V_21 L_8 ) ;
if ( V_13 -> V_43 & V_44 )
F_20 ( V_13 ) ;
V_13 -> V_43 |= V_48 ;
F_21 ( V_13 -> V_10 ) ;
F_22 ( V_13 -> V_10 ) ;
}
static int F_14 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_4 ;
int V_49 ;
F_8 ( V_21 L_9 ) ;
V_2 -> V_39 = 0x5 ;
V_2 -> V_36 |= V_37 | V_38 ;
V_49 = F_23 ( V_2 ) ;
if ( V_49 )
goto V_50;
V_49 = F_24 ( V_2 -> V_3 , V_51 ,
V_52 ,
V_53 , V_2 -> V_54 , V_2 -> V_4 ) ;
if ( V_49 )
goto V_50;
V_49 = F_25 ( V_2 ) ;
if ( V_49 )
goto V_55;
if ( F_15 ( V_6 , V_2 -> V_32 [ 0 ] -> V_56 ,
V_2 -> V_3 ) < 0 )
goto V_55;
return 0 ;
V_55:
F_2 ( V_2 -> V_3 , V_2 -> V_4 ) ;
V_50:
F_3 ( V_2 ) ;
return - V_26 ;
}
static int F_26 ( struct V_1 * V_2 )
{
struct V_5 * V_13 = V_2 -> V_4 ;
F_8 ( V_21 L_10 ) ;
if ( V_13 ) {
F_8 ( V_21 L_11 ) ;
F_27 ( V_13 ) ;
}
return 0 ;
}
static int F_28 ( struct V_1 * V_2 )
{
struct V_5 * V_13 = V_2 -> V_4 ;
F_8 ( V_21 L_12 ) ;
if ( F_29 ( V_2 ) ) {
if ( V_13 ) {
F_8 ( V_21 L_13 ) ;
F_30 ( V_13 ) ;
}
}
F_8 ( V_21 L_14 ) ;
return 0 ;
}
