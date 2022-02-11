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
struct V_35 V_36 = { . V_18 = & V_33 -> V_18 ,} ;
struct V_37 * V_38 = NULL ;
struct V_37 * V_39 ;
struct V_19 * V_20 [ V_40 ] = {} ;
struct V_1 * V_2 ;
struct V_41 * V_42 ;
int V_16 ;
int V_43 ;
if ( ! V_23 ) {
F_8 ( & V_33 -> V_18 , L_4 ) ;
return - V_29 ;
}
if ( V_33 -> V_18 . V_25 -> V_20 ) {
V_16 = F_5 ( & V_33 -> V_18 , V_20 , V_40 ) ;
if ( V_16 < 0 ) {
F_8 ( & V_33 -> V_18 , L_5 , V_16 ) ;
return V_16 ;
}
}
V_39 = F_12 ( & V_33 -> V_18 , V_40 *
sizeof( struct V_37 ) , V_44 ) ;
if ( ! V_39 )
return - V_45 ;
for ( V_43 = 0 , V_42 = V_46 ; V_43 < V_40 ; ++ V_43 , V_42 ++ ) {
V_38 = & V_39 [ V_43 ] ;
V_38 -> V_47 = V_42 ;
V_36 . V_31 = V_23 -> V_31 [ V_43 ] ;
V_36 . V_48 = V_38 ;
V_36 . V_13 = V_34 -> V_13 ;
V_36 . V_20 = V_20 [ V_43 ] ;
V_2 = F_13 ( & V_33 -> V_18 , & V_42 -> V_5 , & V_36 ) ;
if ( F_14 ( V_2 ) ) {
F_8 ( & V_33 -> V_18 , L_6 ,
V_42 -> V_5 . V_49 ) ;
return F_15 ( V_2 ) ;
}
}
F_16 ( V_33 , V_39 ) ;
return 0 ;
}
static int T_2 F_17 ( void )
{
return F_18 ( & V_50 ) ;
}
static void T_3 F_19 ( void )
{
F_20 ( & V_50 ) ;
}
