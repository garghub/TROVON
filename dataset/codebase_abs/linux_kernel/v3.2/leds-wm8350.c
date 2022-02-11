static void F_1 ( struct V_1 * V_2 )
{
int V_3 ;
if ( V_2 -> V_4 )
return;
V_3 = F_2 ( V_2 -> V_5 ) ;
if ( V_3 != 0 ) {
F_3 ( V_2 -> V_6 . V_7 , L_1 , V_3 ) ;
return;
}
V_3 = F_2 ( V_2 -> V_8 ) ;
if ( V_3 != 0 ) {
F_3 ( V_2 -> V_6 . V_7 , L_2 , V_3 ) ;
F_4 ( V_2 -> V_5 ) ;
return;
}
V_2 -> V_4 = 1 ;
}
static void F_5 ( struct V_1 * V_2 )
{
int V_3 ;
if ( ! V_2 -> V_4 )
return;
V_3 = F_4 ( V_2 -> V_8 ) ;
if ( V_3 != 0 ) {
F_3 ( V_2 -> V_6 . V_7 , L_3 , V_3 ) ;
return;
}
V_3 = F_4 ( V_2 -> V_5 ) ;
if ( V_3 != 0 ) {
F_3 ( V_2 -> V_6 . V_7 , L_4 , V_3 ) ;
F_2 ( V_2 -> V_8 ) ;
return;
}
V_2 -> V_4 = 0 ;
}
static void F_6 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = F_7 ( V_10 , struct V_1 , V_10 ) ;
int V_3 ;
int V_11 ;
unsigned long V_12 ;
F_8 ( & V_2 -> V_13 ) ;
F_9 ( & V_2 -> V_14 , V_12 ) ;
if ( V_2 -> V_15 == V_16 ) {
F_10 ( & V_2 -> V_14 , V_12 ) ;
F_5 ( V_2 ) ;
goto V_17;
}
V_11 = ( V_2 -> V_18 * V_2 -> V_15 ) / V_19 ;
F_10 ( & V_2 -> V_14 , V_12 ) ;
F_11 ( V_11 >= F_12 ( V_20 ) ) ;
V_3 = F_13 ( V_2 -> V_5 , V_20 [ V_11 ] ,
V_20 [ V_11 ] ) ;
if ( V_3 != 0 )
F_3 ( V_2 -> V_6 . V_7 , L_5 ,
V_20 [ V_11 ] , V_3 ) ;
F_1 ( V_2 ) ;
V_17:
F_14 ( & V_2 -> V_13 ) ;
}
static void F_15 ( struct V_21 * V_22 ,
enum V_23 V_15 )
{
struct V_1 * V_2 = F_16 ( V_22 ) ;
unsigned long V_12 ;
F_9 ( & V_2 -> V_14 , V_12 ) ;
V_2 -> V_15 = V_15 ;
F_17 ( & V_2 -> V_10 ) ;
F_10 ( & V_2 -> V_14 , V_12 ) ;
}
static void F_18 ( struct V_24 * V_25 )
{
struct V_1 * V_2 = F_19 ( V_25 ) ;
F_8 ( & V_2 -> V_13 ) ;
V_2 -> V_15 = V_16 ;
F_5 ( V_2 ) ;
F_14 ( & V_2 -> V_13 ) ;
}
static int F_20 ( struct V_24 * V_25 )
{
struct V_26 * V_5 , * V_8 ;
struct V_1 * V_2 ;
struct V_27 * V_28 = V_25 -> V_7 . V_29 ;
int V_3 , V_30 ;
if ( V_28 == NULL ) {
F_3 ( & V_25 -> V_7 , L_6 ) ;
return - V_31 ;
}
if ( V_28 -> V_32 < V_20 [ 0 ] ) {
F_3 ( & V_25 -> V_7 , L_7 ,
V_28 -> V_32 ) ;
return - V_33 ;
}
V_5 = F_21 ( & V_25 -> V_7 , L_8 ) ;
if ( F_22 ( V_5 ) ) {
F_23 ( V_34 L_9 , V_35 ) ;
return F_24 ( V_5 ) ;
}
V_8 = F_21 ( & V_25 -> V_7 , L_10 ) ;
if ( F_22 ( V_8 ) ) {
F_23 ( V_34 L_11 , V_35 ) ;
V_3 = F_24 ( V_8 ) ;
goto V_36;
}
V_2 = F_25 ( sizeof( * V_2 ) , V_37 ) ;
if ( V_2 == NULL ) {
V_3 = - V_38 ;
goto V_39;
}
V_2 -> V_6 . V_40 = F_15 ;
V_2 -> V_6 . V_41 = V_28 -> V_41 ;
V_2 -> V_6 . V_42 = V_28 -> V_42 ;
V_2 -> V_6 . V_12 |= V_43 ;
V_2 -> V_4 = F_26 ( V_5 ) ;
V_2 -> V_5 = V_5 ;
V_2 -> V_8 = V_8 ;
for ( V_30 = 0 ; V_30 < F_12 ( V_20 ) - 1 ; V_30 ++ )
if ( V_20 [ V_30 ] >= V_28 -> V_32 )
break;
V_2 -> V_18 = V_30 ;
if ( V_28 -> V_32 != V_20 [ V_30 ] )
F_27 ( & V_25 -> V_7 ,
L_12
L_13 ,
V_28 -> V_32 ) ;
F_28 ( & V_2 -> V_14 ) ;
F_29 ( & V_2 -> V_13 ) ;
F_30 ( & V_2 -> V_10 , F_6 ) ;
V_2 -> V_15 = V_16 ;
F_31 ( V_25 , V_2 ) ;
V_3 = F_32 ( & V_25 -> V_7 , & V_2 -> V_6 ) ;
if ( V_3 < 0 )
goto V_44;
return 0 ;
V_44:
F_33 ( V_2 ) ;
V_39:
F_34 ( V_8 ) ;
V_36:
F_34 ( V_5 ) ;
return V_3 ;
}
static int F_35 ( struct V_24 * V_25 )
{
struct V_1 * V_2 = F_19 ( V_25 ) ;
F_36 ( & V_2 -> V_6 ) ;
F_37 ( & V_2 -> V_10 ) ;
F_5 ( V_2 ) ;
F_34 ( V_2 -> V_8 ) ;
F_34 ( V_2 -> V_5 ) ;
F_33 ( V_2 ) ;
return 0 ;
}
static int T_1 F_38 ( void )
{
return F_39 ( & V_45 ) ;
}
static void F_40 ( void )
{
F_41 ( & V_45 ) ;
}
