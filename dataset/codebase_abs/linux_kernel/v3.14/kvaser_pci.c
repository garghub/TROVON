static T_1 F_1 ( const struct V_1 * V_2 , int V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 ) ;
}
static void F_3 ( const struct V_1 * V_2 ,
int V_3 , T_1 V_5 )
{
F_4 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static void F_5 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
struct V_8 * V_9 = V_2 -> V_2 ;
T_2 V_10 ;
V_10 = F_7 ( V_9 -> V_11 + V_12 ) ;
V_10 &= ~ V_13 ;
F_8 ( V_10 , V_9 -> V_11 + V_12 ) ;
}
static void F_9 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
struct V_8 * V_9 = V_2 -> V_2 ;
T_2 V_14 ;
V_14 = F_7 ( V_9 -> V_11 + V_12 ) ;
V_14 |= V_13 ;
F_8 ( V_14 , V_9 -> V_11 + V_12 ) ;
}
static int F_10 ( void T_3 * V_15 )
{
T_1 V_16 ;
int V_17 ;
for ( V_17 = 0 ; V_17 < V_18 ; V_17 ++ ) {
F_4 ( V_19 , V_15 +
( V_17 * V_20 ) + V_21 ) ;
V_16 = F_2 ( V_15 +
( V_17 * V_20 ) + V_21 ) ;
if ( ! ( V_16 & V_19 ) )
break;
}
return V_17 ;
}
static void F_11 ( struct V_6 * V_7 )
{
struct V_1 * V_2 ;
struct V_8 * V_9 ;
int V_17 ;
if ( ! V_7 )
return;
V_2 = F_6 ( V_7 ) ;
V_9 = V_2 -> V_2 ;
if ( ! V_9 )
return;
F_12 ( & V_9 -> V_22 -> V_7 , L_1 ,
V_7 -> V_23 ) ;
F_5 ( V_7 ) ;
for ( V_17 = 0 ; V_17 < V_9 -> V_24 - 1 ; V_17 ++ ) {
if ( V_9 -> V_25 [ V_17 ] ) {
F_12 ( & V_9 -> V_22 -> V_7 , L_1 ,
V_9 -> V_25 [ V_17 ] -> V_23 ) ;
F_13 ( V_9 -> V_25 [ V_17 ] ) ;
F_14 ( V_9 -> V_25 [ V_17 ] ) ;
}
}
F_13 ( V_7 ) ;
F_15 ( V_9 -> V_22 , V_2 -> V_4 ) ;
F_15 ( V_9 -> V_22 , V_9 -> V_11 ) ;
F_15 ( V_9 -> V_22 , V_9 -> V_26 ) ;
F_14 ( V_7 ) ;
}
static int F_16 ( struct V_22 * V_27 , int V_28 ,
struct V_6 * * V_29 ,
void T_3 * V_11 ,
void T_3 * V_26 ,
void T_3 * V_15 )
{
struct V_6 * V_7 ;
struct V_1 * V_2 ;
struct V_8 * V_9 ;
int V_30 , V_31 ;
V_7 = F_17 ( sizeof( struct V_8 ) ) ;
if ( V_7 == NULL )
return - V_32 ;
V_2 = F_6 ( V_7 ) ;
V_9 = V_2 -> V_2 ;
V_9 -> V_22 = V_27 ;
V_9 -> V_28 = V_28 ;
V_9 -> V_11 = V_11 ;
V_9 -> V_26 = V_26 ;
if ( V_28 == 0 ) {
V_9 -> V_33 =
F_2 ( V_9 -> V_26 + V_34 ) >> 4 ;
V_31 = 2 ;
F_8 ( 0x80808080UL , V_9 -> V_11 + V_35 ) ;
F_9 ( V_7 ) ;
} else {
struct V_1 * V_36 = F_6 ( * V_29 ) ;
struct V_8 * V_37 = V_36 -> V_2 ;
V_37 -> V_25 [ V_28 - 1 ] = V_7 ;
V_37 -> V_24 = V_28 + 1 ;
V_9 -> V_33 = V_37 -> V_33 ;
}
V_2 -> V_4 = V_15 + V_28 * V_20 ;
V_2 -> V_38 = F_1 ;
V_2 -> V_39 = F_3 ;
V_2 -> V_40 . clock . V_41 = V_42 ;
V_2 -> V_43 = V_44 ;
V_2 -> V_45 = V_46 ;
V_2 -> V_47 = V_48 ;
V_7 -> V_49 = V_27 -> V_49 ;
V_31 = 4 ;
F_12 ( & V_27 -> V_7 , L_2 ,
V_2 -> V_4 , V_9 -> V_11 , V_7 -> V_49 ) ;
F_18 ( V_7 , & V_27 -> V_7 ) ;
V_30 = F_19 ( V_7 ) ;
if ( V_30 ) {
F_20 ( & V_27 -> V_7 , L_3 ,
V_30 ) ;
goto V_50;
}
if ( V_28 == 0 )
* V_29 = V_7 ;
return 0 ;
V_50:
F_11 ( V_7 ) ;
return V_30 ;
}
static int F_21 ( struct V_22 * V_27 ,
const struct V_51 * V_52 )
{
int V_30 ;
struct V_6 * V_29 = NULL ;
struct V_1 * V_2 ;
struct V_8 * V_9 ;
int V_24 ;
void T_3 * V_15 = NULL ;
void T_3 * V_11 = NULL ;
void T_3 * V_26 = NULL ;
int V_17 ;
F_12 ( & V_27 -> V_7 , L_4 ,
V_27 -> V_53 , V_27 -> V_54 ) ;
V_30 = F_22 ( V_27 ) ;
if ( V_30 )
goto V_50;
V_30 = F_23 ( V_27 , V_55 ) ;
if ( V_30 )
goto V_56;
V_11 = F_24 ( V_27 , 0 , V_57 ) ;
if ( V_11 == NULL ) {
V_30 = - V_58 ;
goto V_59;
}
V_26 = F_24 ( V_27 , 2 , V_60 ) ;
if ( V_26 == NULL ) {
V_30 = - V_32 ;
goto V_61;
}
V_15 = F_24 ( V_27 , 1 , V_62 ) ;
if ( V_15 == NULL ) {
V_30 = - V_32 ;
goto V_61;
}
V_24 = F_10 ( V_15 ) ;
if ( V_24 == 0 ) {
V_30 = - V_32 ;
goto V_61;
}
for ( V_17 = 0 ; V_17 < V_24 ; V_17 ++ ) {
V_30 = F_16 ( V_27 , V_17 , & V_29 ,
V_11 , V_26 ,
V_15 ) ;
if ( V_30 )
goto V_63;
}
V_2 = F_6 ( V_29 ) ;
V_9 = V_2 -> V_2 ;
F_12 ( & V_27 -> V_7 , L_5 ,
V_9 -> V_33 , V_9 -> V_24 ) ;
F_25 ( V_27 , V_29 ) ;
return 0 ;
V_63:
F_11 ( V_29 ) ;
V_61:
if ( V_11 != NULL )
F_15 ( V_27 , V_11 ) ;
if ( V_26 != NULL )
F_15 ( V_27 , V_26 ) ;
if ( V_15 != NULL )
F_15 ( V_27 , V_15 ) ;
V_59:
F_26 ( V_27 ) ;
V_56:
F_27 ( V_27 ) ;
V_50:
return V_30 ;
}
static void F_28 ( struct V_22 * V_27 )
{
struct V_6 * V_7 = F_29 ( V_27 ) ;
F_11 ( V_7 ) ;
F_26 ( V_27 ) ;
F_27 ( V_27 ) ;
}
