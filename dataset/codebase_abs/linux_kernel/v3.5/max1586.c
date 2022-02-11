static int F_1 ( struct V_1 * V_2 ,
unsigned V_3 )
{
unsigned V_4 = V_2 -> V_5 - V_2 -> V_6 ;
return V_2 -> V_6 + ( V_3 * V_4 / V_7 ) ;
}
static int F_2 ( struct V_8 * V_9 , int V_6 , int V_5 ,
unsigned * V_3 )
{
struct V_1 * V_2 = F_3 ( V_9 ) ;
struct V_10 * V_11 = V_2 -> V_11 ;
unsigned V_4 = V_2 -> V_5 - V_2 -> V_6 ;
T_1 V_12 ;
if ( V_6 > V_2 -> V_5 || V_5 < V_2 -> V_6 )
return - V_13 ;
if ( V_6 < V_2 -> V_6 )
V_6 = V_2 -> V_6 ;
* V_3 = F_4 ( ( V_6 - V_2 -> V_6 ) *
V_7 , V_4 ) ;
if ( F_1 ( V_2 , * V_3 ) > V_5 )
return - V_13 ;
F_5 ( & V_11 -> V_14 , L_1 ,
F_1 ( V_2 , * V_3 ) / 1000 ) ;
V_12 = V_15 | ( T_1 ) * V_3 ;
return F_6 ( V_11 , V_12 ) ;
}
static int F_7 ( struct V_8 * V_9 , unsigned V_3 )
{
struct V_1 * V_2 = F_3 ( V_9 ) ;
if ( V_3 > V_7 )
return - V_13 ;
return F_1 ( V_2 , V_3 ) ;
}
static int F_8 ( unsigned V_3 )
{
static int V_16 [] = { 1 , 1800000 , 2500000 , 3000000 } ;
return V_16 [ V_3 ] ;
}
static int F_9 ( struct V_8 * V_9 , int V_6 , int V_5 ,
unsigned int * V_3 )
{
struct V_10 * V_11 = F_3 ( V_9 ) ;
T_1 V_17 ;
if ( V_6 < V_18 || V_6 > V_19 )
return - V_13 ;
if ( V_5 < V_18 || V_5 > V_19 )
return - V_13 ;
if ( V_6 < 1800000 )
* V_3 = 0 ;
else if ( V_6 < 2500000 )
* V_3 = 1 ;
else if ( V_6 < 3000000 )
* V_3 = 2 ;
else if ( V_6 >= 3000000 )
* V_3 = 3 ;
if ( F_8 ( * V_3 ) > V_5 )
return - V_13 ;
F_5 ( & V_11 -> V_14 , L_2 ,
F_8 ( * V_3 ) / 1000 ) ;
V_17 = V_20 | ( T_1 ) * V_3 ;
return F_6 ( V_11 , V_17 ) ;
}
static int F_10 ( struct V_8 * V_9 , unsigned V_3 )
{
if ( V_3 > V_21 )
return - V_13 ;
return F_8 ( V_3 ) ;
}
static int T_2 F_11 ( struct V_10 * V_11 ,
const struct V_22 * V_23 )
{
struct V_8 * * V_9 ;
struct V_24 * V_25 = V_11 -> V_14 . V_26 ;
struct V_27 V_28 = { } ;
struct V_1 * V_2 ;
int V_29 , V_30 , V_31 = - V_32 ;
V_2 = F_12 ( & V_11 -> V_14 , sizeof( struct V_1 ) +
sizeof( struct V_8 * ) * ( V_33 + 1 ) ,
V_34 ) ;
if ( ! V_2 )
return - V_32 ;
V_2 -> V_11 = V_11 ;
if ( ! V_25 -> V_35 )
return - V_13 ;
V_2 -> V_6 = V_36 / 1000 * V_25 -> V_35 / 1000 ;
V_2 -> V_5 = V_37 / 1000 * V_25 -> V_35 / 1000 ;
V_9 = V_2 -> V_9 ;
for ( V_29 = 0 ; V_29 < V_25 -> V_38 && V_29 <= V_33 ; V_29 ++ ) {
V_30 = V_25 -> V_39 [ V_29 ] . V_30 ;
if ( ! V_25 -> V_39 [ V_29 ] . V_26 )
continue;
if ( V_30 < V_40 || V_30 > V_33 ) {
F_13 ( & V_11 -> V_14 , L_3 , V_30 ) ;
goto V_41;
}
V_28 . V_14 = & V_11 -> V_14 ;
V_28 . V_42 = V_25 -> V_39 [ V_29 ] . V_26 ;
V_28 . V_43 = V_2 ;
V_9 [ V_29 ] = F_14 ( & V_44 [ V_30 ] , & V_28 ) ;
if ( F_15 ( V_9 [ V_29 ] ) ) {
V_31 = F_16 ( V_9 [ V_29 ] ) ;
F_13 ( & V_11 -> V_14 , L_4 ,
V_44 [ V_30 ] . V_45 ) ;
goto V_41;
}
}
F_17 ( V_11 , V_2 ) ;
F_18 ( & V_11 -> V_14 , L_5 ) ;
return 0 ;
V_41:
while ( -- V_29 >= 0 )
F_19 ( V_9 [ V_29 ] ) ;
return V_31 ;
}
static int T_3 F_20 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = F_21 ( V_11 ) ;
int V_29 ;
for ( V_29 = 0 ; V_29 <= V_33 ; V_29 ++ )
if ( V_2 -> V_9 [ V_29 ] )
F_19 ( V_2 -> V_9 [ V_29 ] ) ;
return 0 ;
}
static int T_4 F_22 ( void )
{
return F_23 ( & V_46 ) ;
}
static void T_5 F_24 ( void )
{
F_25 ( & V_46 ) ;
}
