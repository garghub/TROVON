static int F_1 ( struct V_1 * V_1 , T_1 V_2 , int V_3 , T_2 * V_4 )
{
int V_5 , V_6 = 0 ;
F_2 ( V_2 + V_3 > F_3 ( V_1 -> V_7 ) ) ;
for ( V_5 = V_2 ; V_5 < V_2 + V_3 ; V_5 ++ )
if ( V_8 [ V_5 ] . V_9 ) {
V_6 = F_4 ( V_1 -> V_10 , V_2 , V_4 ,
V_3 ) ;
return V_6 ;
}
memcpy ( V_4 , & V_1 -> V_7 [ V_2 ] , V_3 * sizeof( T_2 ) ) ;
return 0 ;
}
static int F_5 ( struct V_1 * V_1 , T_1 V_2 , int V_3 ,
T_2 * V_11 )
{
int V_6 , V_5 ;
F_2 ( V_2 + V_3 > F_3 ( V_1 -> V_7 ) ) ;
for ( V_5 = 0 ; V_5 < V_3 ; V_5 ++ ) {
F_2 ( ! V_8 [ V_2 + V_5 ] . V_12 ) ;
V_1 -> V_7 [ V_2 + V_5 ] = V_11 [ V_5 ] ;
V_6 = F_6 ( V_1 -> V_10 , V_2 , V_11 [ V_5 ] ) ;
if ( V_6 != 0 )
return V_6 ;
}
return 0 ;
}
T_2 F_7 ( struct V_1 * V_1 , T_1 V_2 )
{
T_2 V_13 ;
F_8 ( & V_1 -> V_14 ) ;
F_1 ( V_1 , V_2 , 1 , & V_13 ) ;
F_9 ( & V_1 -> V_14 ) ;
return V_13 ;
}
int F_10 ( struct V_1 * V_1 , T_1 V_2 , int V_15 , T_2 * V_16 )
{
int V_6 ;
F_8 ( & V_1 -> V_14 ) ;
V_6 = F_1 ( V_1 , V_2 , V_15 , V_16 ) ;
F_9 ( & V_1 -> V_14 ) ;
return V_6 ;
}
int F_11 ( struct V_1 * V_1 , T_1 V_2 , T_2 V_17 , T_2 V_13 )
{
T_2 V_18 ;
int V_6 ;
F_8 ( & V_1 -> V_14 ) ;
V_6 = F_1 ( V_1 , V_2 , 1 , & V_18 ) ;
V_18 = ( V_18 & ~ V_17 ) | V_13 ;
if ( V_6 == 0 )
V_6 = F_5 ( V_1 , V_2 , 1 , & V_18 ) ;
F_9 ( & V_1 -> V_14 ) ;
return V_6 ;
}
void F_12 ( struct V_1 * V_1 )
{
int V_5 ;
F_8 ( & V_1 -> V_14 ) ;
for ( V_5 = 0 ; V_5 < F_3 ( V_1 -> V_7 ) ; V_5 ++ )
if ( V_8 [ V_5 ] . V_19 )
V_1 -> V_7 [ V_5 ] = V_8 [ V_5 ] . V_20 ;
F_9 ( & V_1 -> V_14 ) ;
}
static int F_13 ( struct V_1 * V_1 )
{
struct V_21 V_22 = {
. V_23 = L_1 ,
. V_24 = V_1 ,
. V_25 = sizeof( * V_1 ) ,
} ;
return F_14 ( V_1 -> V_26 , - 1 , & V_22 , 1 , NULL , 0 ) ;
}
static int F_15 ( struct V_1 * V_1 ,
struct V_27 * V_28 )
{
T_2 V_2 ;
int V_6 , V_5 ;
F_16 ( & V_1 -> V_14 ) ;
F_17 ( V_1 -> V_26 , V_1 ) ;
V_6 = F_18 ( V_1 -> V_10 , V_29 , & V_5 ) ;
if ( V_6 != 0 ) {
F_19 ( V_1 -> V_26 , L_2 ) ;
return - V_30 ;
}
if ( V_5 != V_8 [ V_29 ] . V_20 ) {
F_19 ( V_1 -> V_26 , L_3 ,
V_2 ) ;
return - V_31 ;
}
V_6 = F_20 ( V_1 -> V_10 , 0 , V_1 -> V_7 ,
F_3 ( V_1 -> V_7 ) ) ;
if ( V_6 != 0 ) {
F_19 ( V_1 -> V_26 , L_4 ) ;
return - V_30 ;
}
for ( V_5 = 0 ; V_5 < F_3 ( V_1 -> V_7 ) ; V_5 ++ )
V_1 -> V_7 [ V_5 ] = F_21 ( V_1 -> V_7 [ V_5 ] ) ;
if ( ! ( V_1 -> V_7 [ V_32 ] & V_33 ) )
for ( V_5 = 0 ; V_5 < F_3 ( V_1 -> V_7 ) ; V_5 ++ )
if ( V_8 [ V_5 ] . V_19 )
V_1 -> V_7 [ V_5 ] = V_8 [ V_5 ] . V_20 ;
V_6 = F_1 ( V_1 , V_34 , 1 , & V_2 ) ;
if ( V_6 != 0 ) {
F_19 ( V_1 -> V_26 , L_5 , V_6 ) ;
return V_6 ;
}
V_2 = ( V_2 & V_35 ) >> V_36 ;
F_22 ( V_1 -> V_26 , L_6 , V_2 ) ;
V_6 = F_13 ( V_1 ) ;
if ( V_6 != 0 ) {
F_19 ( V_1 -> V_26 , L_7 ) ;
goto V_37;
}
if ( V_28 && V_28 -> V_38 ) {
V_6 = V_28 -> V_38 ( V_1 -> V_26 ) ;
if ( V_6 != 0 ) {
F_19 ( V_1 -> V_26 , L_8 ,
V_6 ) ;
goto V_37;
}
} else
F_23 ( V_1 -> V_26 , L_9 ) ;
return 0 ;
V_37:
F_24 ( V_1 -> V_26 ) ;
return V_6 ;
}
static void F_25 ( struct V_1 * V_1 )
{
F_24 ( V_1 -> V_26 ) ;
}
static int F_26 ( struct V_39 * V_40 ,
const struct V_41 * V_42 )
{
struct V_1 * V_1 ;
int V_6 ;
V_1 = F_27 ( & V_40 -> V_26 , sizeof( struct V_1 ) , V_43 ) ;
if ( V_1 == NULL ) {
V_6 = - V_44 ;
goto V_45;
}
V_1 -> V_10 = F_28 ( V_40 , & V_46 ) ;
if ( F_29 ( V_1 -> V_10 ) ) {
V_6 = F_30 ( V_1 -> V_10 ) ;
goto V_45;
}
V_1 -> V_26 = & V_40 -> V_26 ;
F_31 ( V_40 , V_1 ) ;
V_6 = F_15 ( V_1 , V_40 -> V_26 . V_24 ) ;
if ( V_6 != 0 )
goto V_47;
return 0 ;
V_47:
F_32 ( V_1 -> V_10 ) ;
V_45:
return V_6 ;
}
static int F_33 ( struct V_39 * V_40 )
{
struct V_1 * V_1 = F_34 ( V_40 ) ;
F_25 ( V_1 ) ;
F_32 ( V_1 -> V_10 ) ;
return 0 ;
}
static int T_3 F_35 ( void )
{
int V_6 = - V_31 ;
#if F_36 ( V_48 ) || F_36 ( V_49 )
V_6 = F_37 ( & V_50 ) ;
if ( V_6 != 0 )
F_38 ( L_10 , V_6 ) ;
#endif
return V_6 ;
}
static void T_4 F_39 ( void )
{
#if F_36 ( V_48 ) || F_36 ( V_49 )
F_40 ( & V_50 ) ;
#endif
}
