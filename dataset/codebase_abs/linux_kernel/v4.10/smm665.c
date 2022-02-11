static int F_1 ( struct V_1 * V_2 , int V_3 )
{
int V_4 , V_5 ;
V_4 = F_2 ( V_2 , V_3 ) ;
if ( V_4 < 0 )
return V_4 ;
V_5 = V_4 << 8 ;
V_4 = F_2 ( V_2 , V_3 + 1 ) ;
if ( V_4 < 0 )
return V_4 ;
V_5 |= V_4 ;
return V_5 ;
}
static int F_3 ( struct V_6 * V_7 , int V_8 )
{
struct V_1 * V_2 = V_7 -> V_9 ;
int V_4 ;
int V_10 ;
V_4 = F_2 ( V_2 , V_8 << 3 ) ;
if ( V_4 != - V_11 ) {
F_4 ( & V_2 -> V_12 ,
L_1 , V_4 ) ;
return ( V_4 < 0 ) ? V_4 : - V_13 ;
}
F_5 ( V_7 -> V_14 ) ;
V_4 = F_6 ( V_2 , 0 ) ;
if ( V_4 < 0 ) {
F_4 ( & V_2 -> V_12 , L_2 , V_4 ) ;
return V_4 ;
}
V_10 = ( V_4 >> 11 ) & 0x0f ;
if ( V_10 != V_8 ) {
F_4 ( & V_2 -> V_12 , L_3 ,
V_8 , V_10 ) ;
return - V_13 ;
}
return V_4 & V_15 ;
}
static struct V_6 * F_7 ( struct V_16 * V_12 )
{
struct V_6 * V_7 = F_8 ( V_12 ) ;
struct V_1 * V_2 = V_7 -> V_2 ;
struct V_6 * V_17 = V_7 ;
F_9 ( & V_7 -> V_18 ) ;
if ( F_10 ( V_19 , V_7 -> V_20 + V_21 ) || ! V_7 -> V_22 ) {
int V_23 , V_5 ;
V_5 = F_1 ( V_2 , V_24 ) ;
if ( F_11 ( V_5 < 0 ) ) {
V_17 = F_12 ( V_5 ) ;
goto abort;
}
V_7 -> V_25 = V_5 ;
for ( V_23 = 0 ; V_23 < V_26 ; V_23 ++ ) {
V_5 = F_3 ( V_7 , V_23 ) ;
if ( F_11 ( V_5 < 0 ) ) {
V_17 = F_12 ( V_5 ) ;
goto abort;
}
V_7 -> V_8 [ V_23 ] = V_5 ;
}
V_7 -> V_20 = V_19 ;
V_7 -> V_22 = 1 ;
}
abort:
F_13 ( & V_7 -> V_18 ) ;
return V_17 ;
}
static int F_14 ( T_1 V_27 , int V_28 )
{
int V_5 = 0 ;
switch ( V_28 ) {
case V_29 :
V_5 = F_15 ( V_27 & V_15 ) ;
break;
case V_30 :
case V_31 :
case V_32 :
case V_33 :
case V_34 :
case V_35 :
case V_36 :
V_5 = F_16 ( V_27 & V_15 ) ;
break;
case V_37 :
case V_38 :
V_5 = F_17 ( V_27 & V_15 ) ;
break;
case V_39 :
V_5 = F_18 ( V_27 & V_15 ) ;
break;
default:
F_19 ( 1 ) ;
break;
}
return V_5 ;
}
static int F_20 ( struct V_16 * V_12 , int V_28 )
{
struct V_6 * V_7 = F_8 ( V_12 ) ;
return V_7 -> V_40 [ V_28 ] ;
}
static int F_21 ( struct V_16 * V_12 , int V_28 )
{
struct V_6 * V_7 = F_8 ( V_12 ) ;
return V_7 -> V_41 [ V_28 ] ;
}
static int F_22 ( struct V_16 * V_12 , int V_28 )
{
struct V_6 * V_7 = F_8 ( V_12 ) ;
return V_7 -> V_42 [ V_28 ] ;
}
static int F_23 ( struct V_16 * V_12 , int V_28 )
{
struct V_6 * V_7 = F_8 ( V_12 ) ;
return V_7 -> V_43 [ V_28 ] ;
}
static T_2 F_24 ( struct V_16 * V_12 ,
struct V_44 * V_45 , char * V_46 )
{
struct V_47 * V_48 = F_25 ( V_45 ) ;
struct V_6 * V_7 = F_7 ( V_12 ) ;
int V_5 = 0 ;
if ( F_26 ( V_7 ) )
return F_27 ( V_7 ) ;
if ( V_7 -> V_25 & ( 1 << V_48 -> V_28 ) )
V_5 = 1 ;
return snprintf ( V_46 , V_49 , L_4 , V_5 ) ;
}
static T_2 F_28 ( struct V_16 * V_12 ,
struct V_44 * V_45 , char * V_46 )
{
struct V_47 * V_48 = F_25 ( V_45 ) ;
struct V_6 * V_7 = F_7 ( V_12 ) ;
int V_8 = V_48 -> V_28 ;
int V_5 ;
if ( F_26 ( V_7 ) )
return F_27 ( V_7 ) ;
V_5 = F_14 ( V_7 -> V_8 [ V_8 ] , V_8 ) ;
return snprintf ( V_46 , V_49 , L_4 , V_5 ) ;
}
static int F_29 ( struct V_1 * V_2 ,
const struct V_50 * V_51 )
{
struct V_52 * V_53 = V_2 -> V_53 ;
struct V_6 * V_7 ;
struct V_16 * V_54 ;
int V_23 , V_17 ;
if ( ! F_30 ( V_53 , V_55
| V_56 ) )
return - V_57 ;
if ( F_2 ( V_2 , V_58 ) < 0 )
return - V_57 ;
V_7 = F_31 ( & V_2 -> V_12 , sizeof( * V_7 ) , V_59 ) ;
if ( ! V_7 )
return - V_60 ;
F_32 ( V_2 , V_7 ) ;
F_33 ( & V_7 -> V_18 ) ;
V_7 -> V_2 = V_2 ;
V_7 -> type = V_51 -> V_61 ;
V_7 -> V_9 = F_34 ( V_53 , ( V_2 -> V_62 & ~ V_63 )
| V_64 ) ;
if ( ! V_7 -> V_9 )
return - V_60 ;
switch ( V_7 -> type ) {
case V_65 :
case V_66 :
V_7 -> V_14 = V_67 ;
break;
case V_68 :
case V_69 :
case V_70 :
V_7 -> V_14 = V_71 ;
break;
}
V_17 = - V_57 ;
if ( F_2 ( V_7 -> V_9 , V_72 ) < 0 )
goto V_73;
for ( V_23 = 0 ; V_23 < V_26 ; V_23 ++ ) {
int V_5 ;
V_5 = F_1 ( V_2 , V_74 + V_23 * 8 ) ;
if ( F_11 ( V_5 < 0 ) )
goto V_73;
V_7 -> V_42 [ V_23 ] = V_7 -> V_40 [ V_23 ]
= F_14 ( V_5 , V_23 ) ;
V_5 = F_1 ( V_2 , V_74 + V_23 * 8 + 2 ) ;
if ( F_11 ( V_5 < 0 ) )
goto V_73;
if ( F_35 ( V_5 ) )
V_7 -> V_42 [ V_23 ] = F_14 ( V_5 , V_23 ) ;
else
V_7 -> V_40 [ V_23 ] = F_14 ( V_5 , V_23 ) ;
V_5 = F_1 ( V_2 , V_74 + V_23 * 8 + 4 ) ;
if ( F_11 ( V_5 < 0 ) )
goto V_73;
V_7 -> V_43 [ V_23 ] = V_7 -> V_41 [ V_23 ]
= F_14 ( V_5 , V_23 ) ;
V_5 = F_1 ( V_2 , V_74 + V_23 * 8 + 6 ) ;
if ( F_11 ( V_5 < 0 ) )
goto V_73;
if ( F_35 ( V_5 ) )
V_7 -> V_43 [ V_23 ] = F_14 ( V_5 , V_23 ) ;
else
V_7 -> V_41 [ V_23 ] = F_14 ( V_5 , V_23 ) ;
}
V_54 = F_36 ( & V_2 -> V_12 ,
V_2 -> V_75 , V_7 ,
V_76 ) ;
if ( F_26 ( V_54 ) ) {
V_17 = F_27 ( V_54 ) ;
goto V_73;
}
return 0 ;
V_73:
F_37 ( V_7 -> V_9 ) ;
return V_17 ;
}
static int F_38 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_39 ( V_2 ) ;
F_37 ( V_7 -> V_9 ) ;
return 0 ;
}
