static T_1 F_1 ( const struct V_1 * V_2 , int V_3 )
{
return F_2 ( V_2 -> V_4 + ( V_3 << 2 ) ) ;
}
static void F_3 ( const struct V_1 * V_2 ,
int V_3 , T_1 V_5 )
{
F_4 ( V_5 , V_2 -> V_4 + ( V_3 << 2 ) ) ;
}
static void F_5 ( const struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_2 ;
T_2 V_8 ;
V_8 = F_6 ( V_7 -> V_9 + V_10 ) ;
if ( V_8 & V_7 -> V_11 )
F_7 ( V_7 -> V_11 , V_7 -> V_9 + V_10 ) ;
}
static int T_3 F_8 ( struct V_12 * V_13 ,
const struct V_14 * V_15 )
{
struct V_1 * V_2 ;
struct V_6 * V_7 ;
struct V_16 * V_17 ;
void T_4 * V_9 , * V_4 ;
T_2 V_18 , V_8 ;
int V_19 , V_20 , V_21 ;
V_20 = F_9 ( V_13 ) ;
if ( V_20 )
return V_20 ;
V_20 = F_10 ( V_13 , V_22 ) ;
if ( V_20 )
goto V_23;
V_20 = F_11 ( V_13 , 0x2e , & V_18 ) ;
if ( V_20 )
goto V_24;
F_12 ( & V_13 -> V_17 , L_1 ,
V_13 -> V_25 , V_13 -> V_26 , V_18 ) ;
V_20 = F_13 ( V_13 , 0x44 , 0 ) ;
if ( V_20 )
goto V_24;
if ( V_18 >= 12 )
V_21 = 4 ;
else if ( V_18 >= 10 )
V_21 = 3 ;
else if ( V_18 >= 4 )
V_21 = 2 ;
else
V_21 = 1 ;
V_9 = F_14 ( V_13 , 0 , V_27 ) ;
if ( ! V_9 ) {
F_15 ( & V_13 -> V_17 , L_2 ) ;
goto V_24;
}
V_4 = F_14 ( V_13 , 1 , V_28 * V_21 ) ;
if ( ! V_4 ) {
F_15 ( & V_13 -> V_17 , L_3 ) ;
goto V_29;
}
F_7 ( 0x0005 , V_9 + V_30 + 2 ) ;
F_4 ( 0x00 , V_9 + V_30 ) ;
F_4 ( 0x05 , V_9 + V_31 + 3 ) ;
F_16 ( 5 ) ;
F_4 ( 0x04 , V_9 + V_31 + 3 ) ;
V_8 = F_6 ( V_9 + V_10 + 2 ) ;
for ( V_19 = 0 ; V_19 < V_21 ; V_19 ++ ) {
V_17 = F_17 ( sizeof( struct V_6 ) ) ;
if ( ! V_17 ) {
V_20 = - V_32 ;
goto V_33;
}
V_2 = F_18 ( V_17 ) ;
V_7 = V_2 -> V_2 ;
V_7 -> V_9 = V_9 ;
V_2 -> V_4 = V_4 + V_19 * V_28 ;
V_2 -> V_34 = F_1 ;
V_2 -> V_35 = F_3 ;
V_2 -> V_36 = F_5 ;
V_2 -> V_37 . clock . V_38 = V_39 ;
V_2 -> V_40 = V_41 ;
V_2 -> V_42 = V_43 ;
if ( V_21 == 1 || V_19 > 0 )
V_2 -> V_42 |= V_44 ;
V_2 -> V_45 = V_46 ;
V_17 -> V_47 = V_13 -> V_47 ;
V_7 -> V_11 = V_48 [ V_19 ] ;
V_8 |= V_7 -> V_11 ;
F_19 ( V_17 , & V_13 -> V_17 ) ;
V_20 = F_20 ( V_17 ) ;
if ( V_20 ) {
F_15 ( & V_13 -> V_17 , L_4 ) ;
F_21 ( V_17 ) ;
goto V_33;
}
V_7 -> V_49 = F_22 ( V_13 ) ;
F_23 ( V_13 , V_17 ) ;
F_24 ( & V_13 -> V_17 ,
L_5 ,
V_17 -> V_50 , V_2 -> V_4 , V_7 -> V_9 , V_17 -> V_47 ) ;
}
F_7 ( V_8 , V_9 + V_10 + 2 ) ;
return 0 ;
V_33:
F_7 ( 0x0 , V_9 + V_10 + 2 ) ;
for ( V_17 = F_22 ( V_13 ) ; V_17 ; V_17 = V_7 -> V_49 ) {
F_25 ( V_17 ) ;
F_21 ( V_17 ) ;
V_2 = F_18 ( V_17 ) ;
V_7 = V_2 -> V_2 ;
}
F_26 ( V_13 , V_4 ) ;
V_29:
F_26 ( V_13 , V_9 ) ;
V_24:
F_27 ( V_13 ) ;
V_23:
F_28 ( V_13 ) ;
return V_20 ;
}
static void T_5 F_29 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = F_22 ( V_13 ) ;
struct V_1 * V_2 = F_18 ( V_17 ) ;
struct V_6 * V_7 = V_2 -> V_2 ;
void T_4 * V_9 = V_7 -> V_9 ;
void T_4 * V_4 = V_2 -> V_4 ;
F_7 ( 0x0 , V_9 + V_10 + 2 ) ;
while ( 1 ) {
F_24 ( & V_13 -> V_17 , L_6 , V_17 -> V_50 ) ;
F_25 ( V_17 ) ;
F_21 ( V_17 ) ;
V_17 = V_7 -> V_49 ;
if ( ! V_17 )
break;
V_2 = F_18 ( V_17 ) ;
V_7 = V_2 -> V_2 ;
}
F_26 ( V_13 , V_4 ) ;
F_26 ( V_13 , V_9 ) ;
F_27 ( V_13 ) ;
F_28 ( V_13 ) ;
F_23 ( V_13 , NULL ) ;
}
static int T_6 F_30 ( void )
{
return F_31 ( & V_51 ) ;
}
static void T_7 F_32 ( void )
{
F_33 ( & V_51 ) ;
}
