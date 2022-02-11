static bool F_1 ( int V_1 )
{
return F_2 ( V_2 ) ;
}
static bool F_3 ( int V_1 )
{
if ( V_3 . V_4 != V_5 ||
V_3 . V_6 != 6 )
return false ;
switch ( V_3 . V_7 ) {
case 30 :
case 26 :
case 46 :
case 37 :
case 44 :
case 47 :
case 42 :
case 45 :
case 58 :
case 62 :
case 60 :
case 63 :
case 69 :
case 70 :
case 61 :
case 86 :
case 71 :
case 79 :
case 55 :
case 77 :
case 76 :
if ( V_1 == V_8 )
return true ;
break;
case 78 :
case 94 :
if ( V_1 == V_8 || V_1 == V_9 )
return true ;
break;
}
return false ;
}
static int F_4 ( struct V_10 * V_11 )
{
T_1 V_12 = V_11 -> V_13 . V_14 ;
if ( V_11 -> V_13 . type != V_11 -> V_15 -> type )
return - V_16 ;
if ( V_12 >= V_17 )
return - V_18 ;
if ( V_11 -> V_13 . V_19 ||
V_11 -> V_13 . V_20 ||
V_11 -> V_13 . V_21 ||
V_11 -> V_13 . V_22 ||
V_11 -> V_13 . V_23 ||
V_11 -> V_13 . V_24 ||
V_11 -> V_13 . V_25 )
return - V_18 ;
if ( ! V_26 [ V_12 ] . V_13 )
return - V_18 ;
V_11 -> V_27 . V_1 = - 1 ;
V_11 -> V_27 . V_28 = V_26 [ V_12 ] . V_26 ;
V_11 -> V_27 . V_14 = V_12 ;
return 0 ;
}
static inline T_1 F_5 ( struct V_10 * V_11 )
{
T_1 V_29 ;
if ( V_11 -> V_27 . V_28 )
F_6 ( V_11 -> V_27 . V_28 , V_29 ) ;
else
F_7 ( V_29 ) ;
return V_29 ;
}
static void F_8 ( struct V_10 * V_11 )
{
T_1 V_30 , V_29 ;
T_2 V_31 ;
V_32:
V_30 = F_9 ( & V_11 -> V_27 . V_33 ) ;
V_29 = F_5 ( V_11 ) ;
if ( F_10 ( & V_11 -> V_27 . V_33 , V_30 , V_29 ) != V_30 )
goto V_32;
V_31 = V_29 - V_30 ;
if ( F_11 ( V_11 -> V_27 . V_28 == V_34 ) ) {
V_31 <<= 32 ;
V_31 >>= 32 ;
}
F_12 ( V_29 - V_30 , & V_11 -> V_35 ) ;
}
static void F_13 ( struct V_10 * V_11 , int V_36 )
{
T_1 V_29 ;
V_29 = F_5 ( V_11 ) ;
F_14 ( & V_11 -> V_27 . V_33 , V_29 ) ;
}
static void F_15 ( struct V_10 * V_11 , int V_36 )
{
F_8 ( V_11 ) ;
}
static void F_16 ( struct V_10 * V_11 , int V_36 )
{
F_15 ( V_11 , V_37 ) ;
}
static int F_17 ( struct V_10 * V_11 , int V_36 )
{
if ( V_36 & V_38 )
F_13 ( V_11 , V_36 ) ;
return 0 ;
}
static int T_3 F_18 ( void )
{
int V_39 , V_40 = 0 ;
if ( ! F_2 ( V_41 ) ) {
F_19 ( L_1 ) ;
return 0 ;
}
for ( V_39 = V_42 + 1 ; V_39 < V_17 ; V_39 ++ ) {
T_1 V_43 ;
if ( ! V_26 [ V_39 ] . F_20 ( V_39 ) || F_21 ( V_26 [ V_39 ] . V_26 , & V_43 ) )
V_26 [ V_39 ] . V_13 = NULL ;
}
for ( V_39 = 0 ; V_39 < V_17 ; V_39 ++ ) {
if ( V_26 [ V_39 ] . V_13 )
V_44 [ V_40 ++ ] = & V_26 [ V_39 ] . V_13 -> V_13 . V_13 ;
}
V_44 [ V_40 ] = NULL ;
F_22 ( & V_45 , L_2 , - 1 ) ;
return 0 ;
}
