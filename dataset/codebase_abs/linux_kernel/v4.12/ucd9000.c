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
if ( V_9 > 0 )
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
if ( V_9 > 0 )
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
enum V_23 V_24 ;
int V_25 , V_11 ;
if ( ! F_6 ( V_2 -> V_26 ,
V_27 |
V_28 ) )
return - V_29 ;
V_11 = F_7 ( V_2 , V_30 ,
V_18 ) ;
if ( V_11 < 0 ) {
F_8 ( & V_2 -> V_31 , L_1 ) ;
return V_11 ;
}
V_18 [ V_11 ] = '\0' ;
F_9 ( & V_2 -> V_31 , L_2 , V_18 ) ;
for ( V_22 = V_32 ; V_22 -> V_33 [ 0 ] ; V_22 ++ ) {
if ( ! strncasecmp ( V_22 -> V_33 , V_18 , strlen ( V_22 -> V_33 ) ) )
break;
}
if ( ! V_22 -> V_33 [ 0 ] ) {
F_8 ( & V_2 -> V_31 , L_3 ) ;
return - V_29 ;
}
if ( V_2 -> V_31 . V_34 )
V_24 = (enum V_23 ) F_10 ( & V_2 -> V_31 ) ;
else
V_24 = V_17 -> V_35 ;
if ( V_24 != V_36 && V_24 != V_22 -> V_35 )
F_11 ( & V_2 -> V_31 ,
L_4 ,
V_17 -> V_33 , V_22 -> V_33 ) ;
V_6 = F_12 ( & V_2 -> V_31 , sizeof( struct V_5 ) ,
V_37 ) ;
if ( ! V_6 )
return - V_38 ;
V_21 = & V_6 -> V_21 ;
V_11 = F_13 ( V_2 , V_39 ) ;
if ( V_11 < 0 ) {
F_8 ( & V_2 -> V_31 ,
L_5 ) ;
return V_11 ;
}
V_21 -> V_40 = V_11 ;
if ( ! V_21 -> V_40 ) {
F_8 ( & V_2 -> V_31 , L_6 ) ;
return - V_29 ;
}
V_21 -> V_41 [ 0 ] = V_42 ;
V_11 = F_7 ( V_2 , V_43 ,
V_18 ) ;
if ( V_11 <= 0 ) {
F_8 ( & V_2 -> V_31 , L_7 ) ;
return - V_29 ;
}
for ( V_25 = 0 ; V_25 < V_11 ; V_25 ++ ) {
int V_9 = F_14 ( V_18 [ V_25 ] ) ;
if ( V_9 >= V_21 -> V_40 )
continue;
switch ( F_15 ( V_18 [ V_25 ] ) ) {
case V_44 :
case V_45 :
V_21 -> V_41 [ V_9 ] |= V_46
| V_47 ;
break;
case V_48 :
V_21 -> V_41 [ V_9 ] |= V_49
| V_50 ;
break;
case V_51 :
V_21 -> V_41 [ V_9 ] |= V_52
| V_53 ;
break;
default:
break;
}
}
if ( V_22 -> V_35 == V_54 ) {
for ( V_25 = 0 ; V_25 < V_55 ; V_25 ++ ) {
F_16 ( V_2 ,
V_56 , V_25 ) ;
V_11 = F_7 ( V_2 ,
V_57 ,
V_6 -> V_7 [ V_25 ] ) ;
if ( V_11 < 0 )
return V_11 ;
}
F_16 ( V_2 , V_56 , 0 ) ;
V_21 -> V_58 = F_4 ;
V_21 -> V_41 [ 0 ] |= V_59 | V_60
| V_61 | V_62 ;
}
return F_17 ( V_2 , V_22 , V_21 ) ;
}
