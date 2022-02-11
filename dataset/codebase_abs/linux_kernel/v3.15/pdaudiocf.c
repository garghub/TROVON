static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 ) ;
}
static int F_3 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_5 ;
F_1 ( V_2 ) ;
V_6 [ V_4 -> V_7 ] = NULL ;
V_4 -> V_8 = NULL ;
F_4 ( V_4 ) ;
return 0 ;
}
static int F_5 ( struct V_9 * V_10 )
{
struct V_3 * V_11 = V_10 -> V_12 ;
return F_3 ( V_11 ) ;
}
static int F_6 ( struct V_1 * V_2 )
{
int V_13 , V_14 ;
struct V_3 * V_4 ;
struct V_15 * V_8 ;
static struct V_16 V_17 = {
. V_18 = F_5 ,
} ;
F_7 ( V_19 L_1 ) ;
for ( V_13 = 0 ; V_13 < V_20 ; V_13 ++ ) {
if ( ! V_6 [ V_13 ] )
break;
}
if ( V_13 >= V_20 ) {
F_8 ( V_21 L_2 ) ;
return - V_22 ;
}
if ( ! V_23 [ V_13 ] )
return - V_24 ;
V_14 = F_9 ( & V_2 -> V_25 , V_7 [ V_13 ] , V_26 [ V_13 ] , V_27 ,
0 , & V_8 ) ;
if ( V_14 < 0 ) {
F_8 ( V_21 L_3 ) ;
return V_14 ;
}
V_4 = F_10 ( V_8 ) ;
if ( ! V_4 ) {
F_11 ( V_8 ) ;
return - V_28 ;
}
V_14 = F_12 ( V_8 , V_29 , V_4 , & V_17 ) ;
if ( V_14 < 0 ) {
F_4 ( V_4 ) ;
F_11 ( V_8 ) ;
return V_14 ;
}
V_4 -> V_7 = V_13 ;
V_6 [ V_13 ] = V_8 ;
V_4 -> V_5 = V_2 ;
V_2 -> V_30 = V_4 ;
V_2 -> V_31 [ 0 ] -> V_32 |= V_33 ;
V_2 -> V_31 [ 0 ] -> V_34 = 16 ;
V_2 -> V_35 = V_36 | V_37 ;
V_2 -> V_38 = 1 ;
V_2 -> V_39 = V_40 ;
return F_13 ( V_2 ) ;
}
static int F_14 ( struct V_3 * V_4 , int V_41 , int V_42 )
{
int V_14 ;
struct V_15 * V_8 = V_4 -> V_8 ;
F_7 ( V_19 L_4 , V_41 , V_42 ) ;
V_4 -> V_41 = V_41 ;
V_4 -> V_42 = V_42 ;
V_4 -> V_43 |= V_44 ;
V_14 = F_15 ( V_4 ) ;
if ( V_14 < 0 )
return V_14 ;
strcpy ( V_8 -> V_45 , L_5 ) ;
sprintf ( V_8 -> V_46 , L_6 , V_8 -> V_45 ) ;
sprintf ( V_8 -> V_47 , L_7 ,
V_8 -> V_46 , V_41 , V_42 ) ;
V_14 = F_16 ( V_4 ) ;
if ( V_14 < 0 )
return V_14 ;
if ( ( V_14 = F_17 ( V_8 ) ) < 0 )
return V_14 ;
return 0 ;
}
static void F_18 ( struct V_1 * V_2 )
{
struct V_3 * V_11 = V_2 -> V_30 ;
F_7 ( V_19 L_8 ) ;
if ( V_11 -> V_43 & V_44 )
F_19 ( V_11 ) ;
V_11 -> V_43 |= V_48 ;
F_20 ( V_11 -> V_8 ) ;
F_21 ( V_11 -> V_8 ) ;
}
static int F_13 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_30 ;
int V_49 ;
F_7 ( V_19 L_9 ) ;
V_2 -> V_38 = 0x5 ;
V_2 -> V_35 |= V_36 | V_37 ;
V_49 = F_22 ( V_2 ) ;
if ( V_49 )
goto V_50;
V_49 = F_23 ( V_2 , V_51 ) ;
if ( V_49 )
goto V_50;
V_49 = F_24 ( V_2 ) ;
if ( V_49 )
goto V_50;
if ( F_14 ( V_4 , V_2 -> V_31 [ 0 ] -> V_52 ,
V_2 -> V_42 ) < 0 )
goto V_50;
return 0 ;
V_50:
F_2 ( V_2 ) ;
return - V_24 ;
}
static int F_25 ( struct V_1 * V_2 )
{
struct V_3 * V_11 = V_2 -> V_30 ;
F_7 ( V_19 L_10 ) ;
if ( V_11 ) {
F_7 ( V_19 L_11 ) ;
F_26 ( V_11 ) ;
}
return 0 ;
}
static int F_27 ( struct V_1 * V_2 )
{
struct V_3 * V_11 = V_2 -> V_30 ;
F_7 ( V_19 L_12 ) ;
if ( F_28 ( V_2 ) ) {
if ( V_11 ) {
F_7 ( V_19 L_13 ) ;
F_29 ( V_11 ) ;
}
}
F_7 ( V_19 L_14 ) ;
return 0 ;
}
