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
struct V_16 * V_17 , * V_18 = NULL ;
void T_4 * V_9 , * V_4 ;
T_2 V_19 , V_8 ;
int V_20 , V_21 , V_22 ;
V_21 = F_9 ( V_13 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_10 ( V_13 , V_23 ) ;
if ( V_21 )
goto V_24;
V_21 = F_11 ( V_13 , 0x2e , & V_19 ) ;
if ( V_21 )
goto V_25;
F_12 ( & V_13 -> V_17 , L_1 ,
V_13 -> V_26 , V_13 -> V_27 , V_19 ) ;
V_21 = F_13 ( V_13 , 0x44 , 0 ) ;
if ( V_21 )
goto V_25;
if ( V_19 >= 12 )
V_22 = 4 ;
else if ( V_19 >= 10 )
V_22 = 3 ;
else if ( V_19 >= 4 )
V_22 = 2 ;
else
V_22 = 1 ;
V_9 = F_14 ( V_13 , 0 , V_28 ) ;
if ( ! V_9 ) {
F_15 ( & V_13 -> V_17 , L_2 ) ;
goto V_25;
}
V_4 = F_14 ( V_13 , 1 , V_29 * V_22 ) ;
if ( ! V_4 ) {
F_15 ( & V_13 -> V_17 , L_3 ) ;
goto V_30;
}
F_7 ( 0x0005 , V_9 + V_31 + 2 ) ;
F_4 ( 0x00 , V_9 + V_31 ) ;
F_4 ( 0x05 , V_9 + V_32 + 3 ) ;
F_16 ( 5 ) ;
F_4 ( 0x04 , V_9 + V_32 + 3 ) ;
V_8 = F_6 ( V_9 + V_10 + 2 ) ;
for ( V_20 = 0 ; V_20 < V_22 ; V_20 ++ ) {
V_17 = F_17 ( sizeof( struct V_6 ) ) ;
if ( ! V_17 ) {
V_21 = - V_33 ;
goto V_34;
}
V_2 = F_18 ( V_17 ) ;
V_7 = V_2 -> V_2 ;
V_7 -> V_9 = V_9 ;
V_2 -> V_4 = V_4 + V_20 * V_29 ;
V_2 -> V_35 = F_1 ;
V_2 -> V_36 = F_3 ;
V_2 -> V_37 = F_5 ;
V_2 -> V_38 . clock . V_39 = V_40 ;
V_2 -> V_41 = V_42 ;
V_2 -> V_43 = V_44 ;
if ( V_22 == 1 || V_20 > 0 )
V_2 -> V_43 |= V_45 ;
V_2 -> V_46 = V_47 ;
V_17 -> V_48 = V_13 -> V_48 ;
V_7 -> V_11 = V_49 [ V_20 ] ;
V_8 |= V_7 -> V_11 ;
F_19 ( V_17 , & V_13 -> V_17 ) ;
V_21 = F_20 ( V_17 ) ;
if ( V_21 ) {
F_15 ( & V_13 -> V_17 , L_4 ) ;
F_21 ( V_17 ) ;
goto V_34;
}
if ( V_20 == 0 )
V_18 = V_17 ;
else
V_7 -> V_50 = V_17 ;
F_22 ( & V_13 -> V_17 ,
L_5 ,
V_17 -> V_51 , V_2 -> V_4 , V_7 -> V_9 , V_17 -> V_48 ) ;
}
F_23 ( V_13 , V_18 ) ;
F_7 ( V_8 , V_9 + V_10 + 2 ) ;
return 0 ;
V_34:
F_7 ( 0x0 , V_9 + V_10 + 2 ) ;
for ( V_17 = V_18 ; V_17 ; V_17 = V_7 -> V_50 ) {
F_24 ( V_17 ) ;
F_21 ( V_17 ) ;
V_2 = F_18 ( V_17 ) ;
V_7 = V_2 -> V_2 ;
V_17 = V_7 -> V_50 ;
}
F_25 ( V_13 , V_4 ) ;
V_30:
F_25 ( V_13 , V_9 ) ;
V_25:
F_26 ( V_13 ) ;
V_24:
F_27 ( V_13 ) ;
return V_21 ;
}
static void T_5 F_28 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = F_29 ( V_13 ) ;
struct V_1 * V_2 = F_18 ( V_17 ) ;
struct V_6 * V_7 = V_2 -> V_2 ;
void T_4 * V_9 = V_7 -> V_9 ;
void T_4 * V_4 = V_2 -> V_4 ;
F_7 ( 0x0 , V_9 + V_10 + 2 ) ;
while ( 1 ) {
F_22 ( & V_13 -> V_17 , L_6 , V_17 -> V_51 ) ;
F_24 ( V_17 ) ;
F_21 ( V_17 ) ;
V_17 = V_7 -> V_50 ;
if ( ! V_17 )
break;
V_2 = F_18 ( V_17 ) ;
V_7 = V_2 -> V_2 ;
}
F_25 ( V_13 , V_4 ) ;
F_25 ( V_13 , V_9 ) ;
F_26 ( V_13 ) ;
F_27 ( V_13 ) ;
F_23 ( V_13 , NULL ) ;
}
static int T_6 F_30 ( void )
{
return F_31 ( & V_52 ) ;
}
static void T_7 F_32 ( void )
{
F_33 ( & V_52 ) ;
}
