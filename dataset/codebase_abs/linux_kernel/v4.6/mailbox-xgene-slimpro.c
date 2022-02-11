static void F_1 ( struct V_1 * V_2 , T_1 * V_3 )
{
F_2 ( V_3 [ 1 ] , V_2 -> V_4 + V_5 ) ;
F_2 ( V_3 [ 2 ] , V_2 -> V_4 + V_6 ) ;
F_2 ( V_3 [ 0 ] , V_2 -> V_4 + V_7 ) ;
}
static void F_3 ( struct V_1 * V_2 )
{
V_2 -> V_8 [ 1 ] = F_4 ( V_2 -> V_4 + V_9 ) ;
V_2 -> V_8 [ 2 ] = F_4 ( V_2 -> V_4 + V_10 ) ;
V_2 -> V_8 [ 0 ] = F_4 ( V_2 -> V_4 + V_11 ) ;
}
static int F_5 ( struct V_1 * V_2 )
{
T_1 V_12 = F_4 ( V_2 -> V_4 + V_13 ) ;
if ( V_12 & V_14 ) {
F_2 ( V_14 , V_2 -> V_4 + V_13 ) ;
return 1 ;
}
return 0 ;
}
static int F_6 ( struct V_1 * V_2 )
{
T_1 V_12 = F_4 ( V_2 -> V_4 + V_13 ) ;
if ( V_12 & V_15 ) {
F_3 ( V_2 ) ;
F_2 ( V_15 , V_2 -> V_4 + V_13 ) ;
return 1 ;
}
return 0 ;
}
static T_2 F_7 ( int V_16 , void * V_17 )
{
struct V_1 * V_2 = V_17 ;
if ( F_5 ( V_2 ) )
F_8 ( V_2 -> V_18 , 0 ) ;
if ( F_6 ( V_2 ) )
F_9 ( V_2 -> V_18 , V_2 -> V_8 ) ;
return V_19 ;
}
static int F_10 ( struct V_20 * V_18 , void * V_3 )
{
struct V_1 * V_2 = V_18 -> V_21 ;
F_1 ( V_2 , V_3 ) ;
return 0 ;
}
static int F_11 ( struct V_20 * V_18 )
{
struct V_1 * V_2 = V_18 -> V_21 ;
int V_22 ;
T_1 V_12 ;
V_22 = F_12 ( V_2 -> V_23 , V_2 -> V_16 , F_7 , 0 ,
V_24 , V_2 ) ;
if ( F_13 ( V_22 ) ) {
F_14 ( V_2 -> V_23 , L_1 ,
V_2 -> V_16 ) ;
return V_22 ;
}
F_2 ( V_14 | V_15 ,
V_2 -> V_4 + V_13 ) ;
V_12 = F_4 ( V_2 -> V_4 + V_25 ) ;
V_12 &= ~ ( V_14 | V_15 ) ;
F_2 ( V_12 , V_2 -> V_4 + V_25 ) ;
return 0 ;
}
static void F_15 ( struct V_20 * V_18 )
{
struct V_1 * V_2 = V_18 -> V_21 ;
T_1 V_12 ;
V_12 = F_4 ( V_2 -> V_4 + V_25 ) ;
V_12 |= ( V_14 | V_15 ) ;
F_2 ( V_12 , V_2 -> V_4 + V_25 ) ;
F_16 ( V_2 -> V_23 , V_2 -> V_16 , V_2 ) ;
}
static int F_17 ( struct V_26 * V_27 )
{
struct V_28 * V_29 ;
struct V_30 * V_31 ;
void T_3 * V_32 ;
int V_22 ;
int V_33 ;
V_29 = F_18 ( & V_27 -> V_23 , sizeof( struct V_28 ) , V_34 ) ;
if ( ! V_29 )
return - V_35 ;
F_19 ( V_27 , V_29 ) ;
V_31 = F_20 ( V_27 , V_36 , 0 ) ;
V_32 = F_21 ( & V_27 -> V_23 , V_31 -> V_37 , F_22 ( V_31 ) ) ;
if ( ! V_32 )
return - V_35 ;
for ( V_33 = 0 ; V_33 < V_38 ; V_33 ++ ) {
V_29 -> V_39 [ V_33 ] . V_16 = F_23 ( V_27 , V_33 ) ;
if ( V_29 -> V_39 [ V_33 ] . V_16 < 0 ) {
if ( V_33 == 0 ) {
F_14 ( & V_27 -> V_23 , L_2 ) ;
return - V_40 ;
}
F_24 ( & V_27 -> V_23 , L_3 , V_33 ) ;
break;
}
V_29 -> V_39 [ V_33 ] . V_23 = & V_27 -> V_23 ;
V_29 -> V_39 [ V_33 ] . V_4 = V_32 + V_33 * V_41 ;
V_29 -> V_39 [ V_33 ] . V_18 = & V_29 -> V_42 [ V_33 ] ;
V_29 -> V_42 [ V_33 ] . V_21 = & V_29 -> V_39 [ V_33 ] ;
}
V_29 -> V_43 . V_23 = & V_27 -> V_23 ;
V_29 -> V_43 . V_42 = V_29 -> V_42 ;
V_29 -> V_43 . V_44 = true ;
V_29 -> V_43 . V_45 = & V_46 ;
V_29 -> V_43 . V_47 = V_33 ;
V_22 = F_25 ( & V_29 -> V_43 ) ;
if ( V_22 ) {
F_14 ( & V_27 -> V_23 ,
L_4 , V_22 ) ;
return V_22 ;
}
F_24 ( & V_27 -> V_23 , L_5 ) ;
return 0 ;
}
static int F_26 ( struct V_26 * V_27 )
{
struct V_28 * V_48 = F_27 ( V_27 ) ;
F_28 ( & V_48 -> V_43 ) ;
return 0 ;
}
static int T_4 F_29 ( void )
{
return F_30 ( & V_49 ) ;
}
static void T_5 F_31 ( void )
{
F_32 ( & V_49 ) ;
}
