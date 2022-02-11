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
return - 1 ;
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
struct V_1 * V_2 = F_8 ( V_12 ) ;
struct V_6 * V_7 = F_9 ( V_2 ) ;
struct V_6 * V_17 = V_7 ;
F_10 ( & V_7 -> V_18 ) ;
if ( F_11 ( V_19 , V_7 -> V_20 + V_21 ) || ! V_7 -> V_22 ) {
int V_23 , V_5 ;
V_5 = F_1 ( V_2 , V_24 ) ;
if ( F_12 ( V_5 < 0 ) ) {
V_17 = F_13 ( V_5 ) ;
goto abort;
}
V_7 -> V_25 = V_5 ;
for ( V_23 = 0 ; V_23 < V_26 ; V_23 ++ ) {
V_5 = F_3 ( V_7 , V_23 ) ;
if ( F_12 ( V_5 < 0 ) ) {
V_17 = F_13 ( V_5 ) ;
goto abort;
}
V_7 -> V_8 [ V_23 ] = V_5 ;
}
V_7 -> V_20 = V_19 ;
V_7 -> V_22 = 1 ;
}
abort:
F_14 ( & V_7 -> V_18 ) ;
return V_17 ;
}
static int F_15 ( T_1 V_27 , int V_28 )
{
int V_5 = 0 ;
switch ( V_28 ) {
case V_29 :
V_5 = F_16 ( V_27 & V_15 ) ;
break;
case V_30 :
case V_31 :
case V_32 :
case V_33 :
case V_34 :
case V_35 :
case V_36 :
V_5 = F_17 ( V_27 & V_15 ) ;
break;
case V_37 :
case V_38 :
V_5 = F_18 ( V_27 & V_15 ) ;
break;
case V_39 :
V_5 = F_19 ( V_27 & V_15 ) ;
break;
default:
F_20 ( 1 ) ;
break;
}
return V_5 ;
}
static int F_21 ( struct V_16 * V_12 , int V_28 )
{
struct V_1 * V_2 = F_8 ( V_12 ) ;
struct V_6 * V_7 = F_9 ( V_2 ) ;
return V_7 -> V_40 [ V_28 ] ;
}
static int F_22 ( struct V_16 * V_12 , int V_28 )
{
struct V_1 * V_2 = F_8 ( V_12 ) ;
struct V_6 * V_7 = F_9 ( V_2 ) ;
return V_7 -> V_41 [ V_28 ] ;
}
static int F_23 ( struct V_16 * V_12 , int V_28 )
{
struct V_1 * V_2 = F_8 ( V_12 ) ;
struct V_6 * V_7 = F_9 ( V_2 ) ;
return V_7 -> V_42 [ V_28 ] ;
}
static int F_24 ( struct V_16 * V_12 , int V_28 )
{
struct V_1 * V_2 = F_8 ( V_12 ) ;
struct V_6 * V_7 = F_9 ( V_2 ) ;
return V_7 -> V_43 [ V_28 ] ;
}
static T_2 F_25 ( struct V_16 * V_12 ,
struct V_44 * V_45 , char * V_46 )
{
struct V_47 * V_48 = F_26 ( V_45 ) ;
struct V_6 * V_7 = F_7 ( V_12 ) ;
int V_5 = 0 ;
if ( F_27 ( V_7 ) )
return F_28 ( V_7 ) ;
if ( V_7 -> V_25 & ( 1 << V_48 -> V_28 ) )
V_5 = 1 ;
return snprintf ( V_46 , V_49 , L_4 , V_5 ) ;
}
static T_2 F_29 ( struct V_16 * V_12 ,
struct V_44 * V_45 , char * V_46 )
{
struct V_47 * V_48 = F_26 ( V_45 ) ;
struct V_6 * V_7 = F_7 ( V_12 ) ;
int V_8 = V_48 -> V_28 ;
int V_5 ;
if ( F_27 ( V_7 ) )
return F_28 ( V_7 ) ;
V_5 = F_15 ( V_7 -> V_8 [ V_8 ] , V_8 ) ;
return snprintf ( V_46 , V_49 , L_4 , V_5 ) ;
}
static int F_30 ( struct V_1 * V_2 ,
const struct V_50 * V_51 )
{
struct V_52 * V_53 = V_2 -> V_53 ;
struct V_6 * V_7 ;
int V_23 , V_17 ;
if ( ! F_31 ( V_53 , V_54
| V_55 ) )
return - V_56 ;
if ( F_2 ( V_2 , V_57 ) < 0 )
return - V_56 ;
V_7 = F_32 ( & V_2 -> V_12 , sizeof( * V_7 ) , V_58 ) ;
if ( ! V_7 )
return - V_59 ;
F_33 ( V_2 , V_7 ) ;
F_34 ( & V_7 -> V_18 ) ;
V_7 -> type = V_51 -> V_60 ;
V_7 -> V_9 = F_35 ( V_53 , ( V_2 -> V_61 & ~ V_62 )
| V_63 ) ;
if ( ! V_7 -> V_9 )
return - V_59 ;
switch ( V_7 -> type ) {
case V_64 :
case V_65 :
V_7 -> V_14 = V_66 ;
break;
case V_67 :
case V_68 :
case V_69 :
V_7 -> V_14 = V_70 ;
break;
}
V_17 = - V_56 ;
if ( F_2 ( V_7 -> V_9 , V_71 ) < 0 )
goto V_72;
for ( V_23 = 0 ; V_23 < V_26 ; V_23 ++ ) {
int V_5 ;
V_5 = F_1 ( V_2 , V_73 + V_23 * 8 ) ;
if ( F_12 ( V_5 < 0 ) )
goto V_72;
V_7 -> V_42 [ V_23 ] = V_7 -> V_40 [ V_23 ]
= F_15 ( V_5 , V_23 ) ;
V_5 = F_1 ( V_2 , V_73 + V_23 * 8 + 2 ) ;
if ( F_12 ( V_5 < 0 ) )
goto V_72;
if ( F_36 ( V_5 ) )
V_7 -> V_42 [ V_23 ] = F_15 ( V_5 , V_23 ) ;
else
V_7 -> V_40 [ V_23 ] = F_15 ( V_5 , V_23 ) ;
V_5 = F_1 ( V_2 , V_73 + V_23 * 8 + 4 ) ;
if ( F_12 ( V_5 < 0 ) )
goto V_72;
V_7 -> V_43 [ V_23 ] = V_7 -> V_41 [ V_23 ]
= F_15 ( V_5 , V_23 ) ;
V_5 = F_1 ( V_2 , V_73 + V_23 * 8 + 6 ) ;
if ( F_12 ( V_5 < 0 ) )
goto V_72;
if ( F_36 ( V_5 ) )
V_7 -> V_43 [ V_23 ] = F_15 ( V_5 , V_23 ) ;
else
V_7 -> V_41 [ V_23 ] = F_15 ( V_5 , V_23 ) ;
}
V_17 = F_37 ( & V_2 -> V_12 . V_74 , & V_75 ) ;
if ( V_17 )
goto V_72;
V_7 -> V_76 = F_38 ( & V_2 -> V_12 ) ;
if ( F_27 ( V_7 -> V_76 ) ) {
V_17 = F_28 ( V_7 -> V_76 ) ;
goto V_77;
}
return 0 ;
V_77:
F_39 ( & V_2 -> V_12 . V_74 , & V_75 ) ;
V_72:
F_40 ( V_7 -> V_9 ) ;
return V_17 ;
}
static int F_41 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_9 ( V_2 ) ;
F_40 ( V_7 -> V_9 ) ;
F_42 ( V_7 -> V_76 ) ;
F_39 ( & V_2 -> V_12 . V_74 , & V_75 ) ;
return 0 ;
}
