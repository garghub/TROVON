static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = V_2 -> V_4 ;
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_7 * V_8 = F_2 ( V_6 ) ;
struct V_9 V_9 [ V_10 ] ;
unsigned int V_11 = sizeof( V_3 -> V_12 [ 0 ] . V_13 ) - 1 ;
int V_14 , V_15 ;
for ( V_14 = 0 ; V_14 < F_3 ( V_9 ) ; V_14 ++ )
V_9 [ V_14 ] . V_16 = V_14 ;
V_15 = F_4 ( V_8 , V_9 , 1 , V_14 ) ;
if ( V_15 < 0 )
return V_15 ;
V_3 -> V_17 = V_15 ;
for ( V_14 = 0 ; V_14 < V_3 -> V_17 ; V_14 ++ ) {
snprintf ( V_3 -> V_12 [ V_14 ] . V_13 , V_11 , L_1 , V_14 ) ;
V_3 -> V_12 [ V_14 ] . V_18 = V_9 [ V_14 ] . V_18 ;
V_15 = F_5 ( V_3 -> V_12 [ V_14 ] . V_18 , V_19 ,
0 , V_3 -> V_12 [ V_14 ] . V_13 , V_6 ) ;
if ( V_15 ) {
F_6 ( V_6 , L_2 ,
V_15 ) ;
goto V_20;
}
}
return 0 ;
V_20:
while ( V_14 -- )
F_7 ( V_3 -> V_12 [ V_14 ] . V_18 , V_6 ) ;
F_8 ( V_8 ) ;
V_3 -> V_17 = 0 ;
return V_15 ;
}
static int F_9 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_7 * V_8 = F_2 ( V_6 ) ;
int V_15 ;
V_15 = F_10 ( V_8 ) ;
if ( V_15 )
return V_15 ;
V_2 -> V_21 = V_8 -> V_21 ;
V_15 = F_5 ( V_2 -> V_21 , V_19 , 0 , L_3 , V_6 ) ;
if ( V_15 ) {
F_6 ( V_6 , L_4 , V_15 ) ;
goto V_22;
}
return 0 ;
V_22:
F_11 ( V_8 ) ;
return V_15 ;
}
static int F_12 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
int V_15 ;
V_15 = F_1 ( V_2 ) ;
if ( ! V_15 )
return 0 ;
F_6 ( V_6 , L_5 , V_15 ) ;
V_15 = F_9 ( V_2 ) ;
if ( ! V_15 )
return 0 ;
F_6 ( V_6 , L_6 , V_15 ) ;
return V_15 ;
}
static void F_13 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = V_2 -> V_4 ;
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_7 * V_8 = F_2 ( V_6 ) ;
if ( V_3 -> V_17 ) {
while ( V_3 -> V_17 -- )
F_7 ( V_3 -> V_12 [ V_3 -> V_17 ] . V_18 ,
V_6 ) ;
F_8 ( V_8 ) ;
} else {
F_7 ( V_2 -> V_21 , V_6 ) ;
F_11 ( V_8 ) ;
}
}
static int F_14 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_7 * V_8 = F_2 ( V_6 ) ;
T_1 V_23 ;
unsigned long V_24 ;
V_24 = F_15 ( V_8 , V_25 ) ;
V_23 = F_16 ( V_8 , V_25 ) ;
if ( ( V_24 & V_26 ) && ( V_23 >= ( V_27 + 0x800 ) ) )
return V_25 ;
return - V_28 ;
}
static int F_17 ( struct V_7 * V_8 , const struct V_29 * V_30 )
{
struct V_1 * V_2 ;
struct V_3 * V_3 ;
struct V_5 * V_6 = & V_8 -> V_6 ;
unsigned int V_31 ;
int V_15 ;
V_15 = - V_32 ;
V_2 = F_18 ( V_6 ) ;
if ( ! V_2 )
goto V_33;
V_3 = F_19 ( V_6 , sizeof( * V_3 ) , V_34 ) ;
if ( ! V_3 )
goto V_33;
V_2 -> V_4 = V_3 ;
V_2 -> V_35 = F_12 ;
V_2 -> F_7 = F_13 ;
V_15 = F_20 ( V_8 , L_3 ) ;
if ( V_15 ) {
F_21 ( V_6 , L_7 , V_15 ) ;
goto V_33;
}
V_15 = F_22 ( V_8 ) ;
if ( V_15 ) {
F_21 ( V_6 , L_8 , V_15 ) ;
goto V_36;
}
F_23 ( V_8 ) ;
V_15 = F_14 ( V_2 ) ;
if ( V_15 < 0 )
goto V_37;
V_31 = V_15 ;
V_15 = - V_28 ;
V_2 -> V_38 = F_24 ( V_8 , V_31 , 0 ) ;
if ( ! V_2 -> V_38 ) {
F_21 ( V_6 , L_9 ) ;
goto V_37;
}
V_2 -> V_39 = V_2 -> V_38 + V_27 ;
V_15 = F_25 ( V_6 , F_26 ( 48 ) ) ;
if ( V_15 ) {
V_15 = F_25 ( V_6 , F_26 ( 32 ) ) ;
if ( V_15 ) {
F_21 ( V_6 , L_10 ,
V_15 ) ;
goto V_40;
}
}
F_27 ( V_6 , V_2 ) ;
V_15 = F_28 ( V_2 ) ;
if ( V_15 )
goto V_40;
F_6 ( V_6 , L_11 ) ;
return 0 ;
V_40:
F_29 ( V_8 , V_2 -> V_38 ) ;
V_37:
F_30 ( V_8 ) ;
V_36:
F_31 ( V_8 ) ;
V_33:
F_6 ( V_6 , L_12 ) ;
return V_15 ;
}
static void F_32 ( struct V_7 * V_8 )
{
struct V_5 * V_6 = & V_8 -> V_6 ;
struct V_1 * V_2 = F_33 ( V_6 ) ;
if ( ! V_2 )
return;
F_34 ( V_2 ) ;
F_29 ( V_8 , V_2 -> V_38 ) ;
F_30 ( V_8 ) ;
F_31 ( V_8 ) ;
F_6 ( V_6 , L_13 ) ;
}
static int F_35 ( struct V_7 * V_8 , T_2 V_41 )
{
struct V_5 * V_6 = & V_8 -> V_6 ;
struct V_1 * V_2 = F_33 ( V_6 ) ;
unsigned long V_42 ;
unsigned int V_43 ;
F_36 ( & V_2 -> V_44 , V_42 ) ;
V_2 -> V_45 = 1 ;
for ( V_43 = 0 ; V_43 < V_2 -> V_46 ; V_43 ++ )
F_37 ( V_2 -> V_47 [ V_43 ] . V_48 ) ;
F_38 ( & V_2 -> V_44 , V_42 ) ;
while ( ! F_39 ( V_2 ) )
F_40 ( V_2 -> V_49 ,
F_39 ( V_2 ) ) ;
return 0 ;
}
static int F_41 ( struct V_7 * V_8 )
{
struct V_5 * V_6 = & V_8 -> V_6 ;
struct V_1 * V_2 = F_33 ( V_6 ) ;
unsigned long V_42 ;
unsigned int V_43 ;
F_36 ( & V_2 -> V_44 , V_42 ) ;
V_2 -> V_45 = 0 ;
for ( V_43 = 0 ; V_43 < V_2 -> V_46 ; V_43 ++ ) {
V_2 -> V_47 [ V_43 ] . V_50 = 0 ;
F_37 ( V_2 -> V_47 [ V_43 ] . V_48 ) ;
}
F_38 ( & V_2 -> V_44 , V_42 ) ;
return 0 ;
}
int F_42 ( void )
{
return F_43 ( & V_51 ) ;
}
void F_44 ( void )
{
F_45 ( & V_51 ) ;
}
