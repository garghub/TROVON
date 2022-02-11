static int F_1 ( struct V_1 * V_2 , int V_3 )
{
int V_4 = 0 ;
struct V_5 * V_6
= F_2 ( F_3 ( V_2 ) ) ;
if ( V_6 -> V_7 [ V_3 ] [ 3 ] & 1 )
V_4 |= V_8 ;
V_4 |= ( V_6 -> V_7 [ V_3 ] [ 3 ] & 0x06 ) >> 1 ;
return V_4 ;
}
static int F_4 ( struct V_1 * V_2 , int V_9 , int V_10 )
{
int V_11 = 0 ;
int V_4 ;
switch ( V_10 ) {
case V_12 :
if ( V_9 )
return - V_13 ;
V_11 = F_1 ( V_2 , 0 ) ;
if ( V_11 < 0 )
return V_11 ;
V_4 = V_11 << 4 ;
V_11 = F_1 ( V_2 , 1 ) ;
if ( V_11 < 0 )
return V_11 ;
V_4 |= V_11 ;
V_11 = V_4 ;
break;
case V_14 :
if ( V_9 )
return - V_13 ;
V_11 = F_1 ( V_2 , 2 ) ;
if ( V_11 < 0 )
return V_11 ;
V_4 = V_11 << 4 ;
V_11 = F_1 ( V_2 , 3 ) ;
if ( V_11 < 0 )
return V_11 ;
V_4 |= V_11 ;
V_11 = V_4 ;
break;
default:
V_11 = - V_15 ;
break;
}
return V_11 ;
}
static int F_5 ( struct V_1 * V_2 ,
const struct V_16 * V_17 )
{
T_1 V_18 [ V_19 + 1 ] ;
struct V_5 * V_6 ;
struct V_20 * V_21 ;
const struct V_16 * V_22 ;
int V_23 , V_11 ;
if ( ! F_6 ( V_2 -> V_24 ,
V_25 |
V_26 ) )
return - V_27 ;
V_11 = F_7 ( V_2 , V_28 ,
V_18 ) ;
if ( V_11 < 0 ) {
F_8 ( & V_2 -> V_29 , L_1 ) ;
return V_11 ;
}
V_18 [ V_11 ] = '\0' ;
F_9 ( & V_2 -> V_29 , L_2 , V_18 ) ;
V_22 = NULL ;
for ( V_23 = 0 ; V_23 < F_10 ( V_30 ) ; V_23 ++ ) {
V_22 = & V_30 [ V_23 ] ;
if ( ! strncasecmp ( V_22 -> V_31 , V_18 , strlen ( V_22 -> V_31 ) ) )
break;
}
if ( ! V_22 || ! strlen ( V_22 -> V_31 ) ) {
F_8 ( & V_2 -> V_29 , L_3 ) ;
return - V_27 ;
}
if ( V_17 -> V_32 != V_33 && V_17 -> V_32 != V_22 -> V_32 )
F_11 ( & V_2 -> V_29 ,
L_4 ,
V_17 -> V_31 , V_22 -> V_31 ) ;
V_6 = F_12 ( sizeof( struct V_5 ) , V_34 ) ;
if ( ! V_6 )
return - V_35 ;
V_21 = & V_6 -> V_21 ;
V_11 = F_13 ( V_2 , V_36 ) ;
if ( V_11 < 0 ) {
F_8 ( & V_2 -> V_29 ,
L_5 ) ;
goto V_37;
}
V_21 -> V_38 = V_11 ;
if ( ! V_21 -> V_38 ) {
F_8 ( & V_2 -> V_29 , L_6 ) ;
V_11 = - V_27 ;
goto V_37;
}
V_21 -> V_39 [ 0 ] = V_40 ;
V_11 = F_7 ( V_2 , V_41 ,
V_18 ) ;
if ( V_11 <= 0 ) {
F_8 ( & V_2 -> V_29 , L_7 ) ;
V_11 = - V_27 ;
goto V_37;
}
for ( V_23 = 0 ; V_23 < V_11 ; V_23 ++ ) {
int V_9 = F_14 ( V_18 [ V_23 ] ) ;
if ( V_9 >= V_21 -> V_38 )
continue;
switch ( F_15 ( V_18 [ V_23 ] ) ) {
case V_42 :
case V_43 :
V_21 -> V_39 [ V_9 ] |= V_44
| V_45 ;
break;
case V_46 :
V_21 -> V_39 [ V_9 ] |= V_47
| V_48 ;
break;
case V_49 :
V_21 -> V_39 [ V_9 ] |= V_50
| V_51 ;
break;
default:
break;
}
}
if ( V_22 -> V_32 == V_52 ) {
for ( V_23 = 0 ; V_23 < V_53 ; V_23 ++ ) {
F_16 ( V_2 ,
V_54 , V_23 ) ;
V_11 = F_7 ( V_2 ,
V_55 ,
V_6 -> V_7 [ V_23 ] ) ;
if ( V_11 < 0 )
goto V_37;
}
F_16 ( V_2 , V_54 , 0 ) ;
V_21 -> V_56 = F_4 ;
V_21 -> V_39 [ 0 ] |= V_57 | V_58
| V_59 | V_60 ;
}
V_11 = F_17 ( V_2 , V_22 , V_21 ) ;
if ( V_11 < 0 )
goto V_37;
return 0 ;
V_37:
F_18 ( V_6 ) ;
return V_11 ;
}
static int F_19 ( struct V_1 * V_2 )
{
int V_11 ;
struct V_5 * V_6 ;
V_6 = F_2 ( F_3 ( V_2 ) ) ;
V_11 = F_20 ( V_2 ) ;
F_18 ( V_6 ) ;
return V_11 ;
}
static int T_2 F_21 ( void )
{
return F_22 ( & V_61 ) ;
}
static void T_3 F_23 ( void )
{
F_24 ( & V_61 ) ;
}
