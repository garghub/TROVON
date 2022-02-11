static void F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 . V_7 ;
if ( V_5 && V_5 -> V_8 )
V_5 -> V_8 ( V_2 , V_3 ) ;
}
static int F_2 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 . V_7 ;
if ( V_5 && V_5 -> V_9 )
return V_5 -> V_9 ( V_2 ) ;
else
return - V_10 ;
}
static int T_1 F_3 ( struct V_1 * V_2 )
{
struct V_11 * V_12 ;
struct V_13 * V_14 ;
struct V_4 * V_5 = V_2 -> V_6 . V_7 ;
struct V_15 * V_16 ;
char V_17 [ 8 ] ;
int V_18 , V_19 , V_20 ;
V_12 = F_4 ( sizeof( struct V_11 ) , V_21 ) ;
if ( V_12 == NULL ) {
F_5 ( & V_2 -> V_6 , L_1 ) ;
return - V_22 ;
}
V_14 = & V_12 -> V_14 ;
V_5 -> V_23 = V_14 ;
snprintf ( V_17 , sizeof( V_17 ) , L_2 , V_2 -> V_24 ) ;
V_12 -> V_25 = F_6 ( & V_2 -> V_6 , V_17 ) ;
if ( F_7 ( V_12 -> V_25 ) ) {
F_5 ( & V_2 -> V_6 , L_3 , V_17 ) ;
V_20 = F_8 ( V_12 -> V_25 ) ;
goto V_26;
}
F_9 ( V_12 -> V_25 ) ;
V_14 -> V_27 = F_10 ( V_12 -> V_25 ) ;
V_14 -> V_8 = F_1 ;
V_14 -> V_9 = F_2 ;
V_14 -> V_28 = V_29 ;
if ( V_5 ) {
V_14 -> V_30 = V_5 -> V_31 ;
V_14 -> V_32 = V_5 -> V_33 ;
V_14 -> V_28 |= V_5 -> V_34 ;
if ( V_5 -> V_35 > 0 && V_5 -> V_36 > 0 ) {
V_12 -> V_37 . V_38 = V_5 -> V_35 ;
V_12 -> V_39 . V_38 = V_5 -> V_36 ;
V_12 -> V_40 . V_41 = & V_12 -> V_37 ;
V_12 -> V_40 . V_42 = & V_12 -> V_39 ;
V_12 -> V_40 . V_43 = 1 ;
V_14 -> V_44 = & V_12 -> V_40 ;
}
}
V_14 -> V_30 |= V_45 ;
V_14 -> V_30 |= V_46 ;
V_20 = F_11 ( & V_16 , V_2 , V_14 ) ;
if ( V_20 < 0 )
goto V_47;
for ( V_18 = 0 ; V_18 < 3 ; V_18 ++ ) {
V_19 = F_12 ( V_2 , V_18 ) ;
if ( V_19 < 0 ) {
if ( V_18 ) {
continue;
} else {
V_20 = V_19 ;
goto V_48;
}
}
V_20 = F_13 ( V_19 , V_49 , 0 ,
F_14 ( & V_2 -> V_6 ) , V_16 ) ;
if ( V_20 ) {
while ( V_18 -- ) {
V_19 = F_12 ( V_2 , V_18 ) ;
if ( V_19 >= 0 )
F_15 ( V_19 , V_16 ) ;
}
goto V_48;
}
}
F_16 ( & V_2 -> V_6 , L_4 ,
F_17 ( V_16 -> V_50 ) , ( unsigned long )
( F_18 ( V_2 , V_51 , 0 ) -> V_52 ) ,
V_14 -> V_27 / 1000000 ) ;
return V_20 ;
V_48:
F_19 ( V_16 ) ;
V_47:
F_20 ( V_12 -> V_25 ) ;
F_21 ( V_12 -> V_25 ) ;
V_26:
F_22 ( V_12 ) ;
return V_20 ;
}
static int F_23 ( struct V_1 * V_2 )
{
struct V_53 * V_50 = F_24 ( V_2 ) ;
struct V_15 * V_16 = F_25 ( V_50 ) ;
struct V_11 * V_12 = F_26 ( V_16 -> V_23 , struct V_11 , V_14 ) ;
struct V_4 * V_5 = V_2 -> V_6 . V_7 ;
int V_18 , V_19 ;
V_5 -> V_23 = NULL ;
F_19 ( V_16 ) ;
for ( V_18 = 0 ; V_18 < 3 ; V_18 ++ ) {
V_19 = F_12 ( V_2 , V_18 ) ;
if ( V_19 >= 0 )
F_15 ( V_19 , V_16 ) ;
}
F_20 ( V_12 -> V_25 ) ;
F_21 ( V_12 -> V_25 ) ;
F_22 ( V_12 ) ;
return 0 ;
}
static int T_2 F_27 ( void )
{
return F_28 ( & V_54 ) ;
}
static void T_3 F_29 ( void )
{
F_30 ( & V_54 ) ;
}
