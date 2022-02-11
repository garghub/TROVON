static int F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
unsigned int V_4 = V_2 -> V_5 -> V_6 ,
V_7 = V_4 << 4 ;
T_1 V_8 ;
switch ( V_3 ) {
case V_9 :
V_8 = V_4 | V_7 ;
break;
case V_10 :
V_8 = V_7 ;
break;
case V_11 :
V_8 = 0 ;
break;
default:
return - V_12 ;
}
return F_2 ( V_2 -> V_13 , V_14 ,
V_7 | V_4 , V_8 ) ;
}
static unsigned int F_3 ( struct V_1 * V_2 )
{
unsigned int V_4 = V_2 -> V_5 -> V_6 ,
V_7 = V_4 << 4 , V_15 = V_4 | V_7 ;
unsigned int V_8 ;
int V_16 = F_4 ( V_2 -> V_13 , V_14 , & V_8 ) ;
if ( V_16 < 0 )
return V_16 ;
if ( ( V_8 & V_15 ) == V_15 )
return V_9 ;
if ( ( V_8 & V_15 ) == V_7 )
return V_10 ;
if ( ! ( V_8 & V_15 ) )
return V_11 ;
return - V_12 ;
}
static int F_5 ( struct V_17 * V_18 ,
struct V_19 * * V_20 , const int V_21 )
{
struct V_22 * V_23 = F_6 ( V_18 ) ;
struct V_19 * V_24 =
F_7 ( V_18 -> V_25 -> V_20 , L_1 ) ;
struct V_26 * V_27 ;
int V_16 , V_28 ;
if ( ! V_24 ) {
F_8 ( V_18 , L_2 ) ;
return - V_29 ;
}
V_16 = V_26 ( V_18 -> V_25 , V_24 ,
V_30 , V_21 ) ;
F_9 ( V_24 ) ;
if ( V_16 < 0 ) {
F_8 ( V_18 , L_3 , V_16 ) ;
return V_16 ;
}
for ( V_28 = 0 , V_27 = V_30 ; V_28 < V_21 ; V_28 ++ , V_27 ++ )
if ( V_27 -> V_20 ) {
V_23 -> V_31 [ V_28 ] = V_27 -> V_31 ;
V_20 [ V_28 ] = V_27 -> V_20 ;
}
return 0 ;
}
static int F_10 ( struct V_32 * V_33 )
{
struct V_22 * V_23 = F_6 ( & V_33 -> V_18 ) ;
struct V_34 * V_34 = F_11 ( V_33 -> V_18 . V_25 ) ;
struct V_35 * V_36 ;
struct V_37 V_38 = { . V_18 = & V_33 -> V_18 ,} ;
struct V_39 * V_40 = NULL ;
struct V_39 * V_41 ;
struct V_19 * V_20 [ V_42 ] = {} ;
struct V_1 * V_2 ;
struct V_43 * V_44 ;
int V_16 ;
int V_45 ;
if ( ! V_23 ) {
F_8 ( & V_33 -> V_18 , L_4 ) ;
return - V_29 ;
}
if ( V_33 -> V_18 . V_25 -> V_20 ) {
V_16 = F_5 ( & V_33 -> V_18 , V_20 , V_42 ) ;
if ( V_16 < 0 ) {
F_8 ( & V_33 -> V_18 , L_5 , V_16 ) ;
return V_16 ;
}
}
V_41 = F_12 ( & V_33 -> V_18 , V_42 *
sizeof( struct V_39 ) , V_46 ) ;
if ( ! V_41 ) {
F_8 ( & V_33 -> V_18 , L_6 ) ;
return - V_47 ;
}
for ( V_45 = 0 , V_44 = V_48 ; V_45 < V_42 ; ++ V_45 , V_44 ++ ) {
V_36 = V_23 -> V_31 [ V_45 ] ;
if ( ! V_36 )
continue;
V_40 = & V_41 [ V_45 ] ;
V_40 -> V_49 = V_44 ;
V_38 . V_31 = V_36 ;
V_38 . V_50 = V_40 ;
V_38 . V_13 = V_34 -> V_13 ;
V_38 . V_20 = V_20 [ V_45 ] ;
V_2 = F_13 ( & V_44 -> V_5 , & V_38 ) ;
if ( F_14 ( V_2 ) ) {
F_8 ( & V_33 -> V_18 , L_7 ,
V_44 -> V_5 . V_51 ) ;
V_16 = F_15 ( V_2 ) ;
goto V_52;
}
V_40 -> V_2 = V_2 ;
}
F_16 ( V_33 , V_41 ) ;
return 0 ;
V_52:
while ( -- V_45 >= 0 )
F_17 ( V_41 [ V_45 ] . V_2 ) ;
return V_16 ;
}
static int F_18 ( struct V_32 * V_33 )
{
struct V_39 * V_41 = F_19 ( V_33 ) ;
int V_45 ;
for ( V_45 = 0 ; V_45 < V_42 ; ++ V_45 )
F_17 ( V_41 [ V_45 ] . V_2 ) ;
return 0 ;
}
static int T_2 F_20 ( void )
{
return F_21 ( & V_53 ) ;
}
static void T_3 F_22 ( void )
{
F_23 ( & V_53 ) ;
}
