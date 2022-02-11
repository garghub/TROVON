static int F_1 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
const struct V_7 * V_8 = F_3 ( V_6 ) ;
int V_9 = 0 ;
if ( V_3 )
return - V_10 ;
switch ( V_4 ) {
case V_11 :
if ( V_8 -> V_12 ) {
V_9 = - V_10 ;
break;
}
V_9 = F_4 ( V_2 , 0 , V_13 ) ;
break;
case V_14 :
if ( ! V_8 -> V_12 ) {
V_9 = - V_10 ;
break;
}
V_9 = F_4 ( V_2 , 0 , V_13 ) ;
break;
case V_15 :
V_9 = F_4 ( V_2 , 0 , V_16 ) ;
break;
case V_17 :
V_9 = F_4 ( V_2 , 0 , V_18 ) ;
break;
case V_19 :
V_9 = F_4 ( V_2 , 0 , V_20 ) ;
break;
case V_21 :
if ( V_8 -> V_22 != V_23 ) {
V_9 = - V_10 ;
break;
}
V_9 = F_4 ( V_2 , 0 , V_24 ) ;
break;
case V_25 :
case V_26 :
case V_27 :
break;
case V_28 :
if ( V_8 -> V_22 != V_23 )
V_9 = - V_10 ;
break;
default:
V_9 = - V_29 ;
break;
}
return V_9 ;
}
static int F_5 ( struct V_1 * V_2 , int V_3 , int V_4 ,
T_1 V_30 )
{
int V_9 ;
if ( V_3 )
return - V_10 ;
switch ( V_4 ) {
case V_11 :
case V_14 :
V_9 = F_6 ( V_2 , 0 , V_13 ,
V_30 ) ;
break;
case V_25 :
V_9 = F_6 ( V_2 , 0 , V_16 , 0 ) ;
break;
case V_26 :
V_9 = F_6 ( V_2 , 0 , V_18 , 0 ) ;
break;
case V_27 :
V_9 = F_6 ( V_2 , 0 , V_20 , 0 ) ;
break;
case V_28 :
V_9 = F_6 ( V_2 , 0 , V_24 , 0 ) ;
break;
default:
V_9 = - V_29 ;
break;
}
return V_9 ;
}
static int F_7 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
const struct V_7 * V_8 = F_3 ( V_6 ) ;
int V_31 , V_9 ;
if ( V_3 > 0 )
return - V_10 ;
switch ( V_4 ) {
case V_32 :
V_9 = F_8 ( V_2 , V_3 , V_32 ) ;
if ( V_9 < 0 )
break;
V_31 = F_8 ( V_2 , V_3 ,
V_33 ) ;
if ( V_31 < 0 ) {
V_9 = V_31 ;
break;
}
if ( V_31 & V_34 ) {
V_9 |= V_8 -> V_12 ?
V_35 : V_36 ;
}
break;
default:
V_9 = - V_29 ;
break;
}
return V_9 ;
}
static int F_9 ( struct V_1 * V_2 ,
const struct V_37 * V_22 )
{
int V_38 , V_39 ;
int V_9 ;
struct V_5 * V_6 ;
struct V_7 * V_8 ;
if ( ! F_10 ( V_2 -> V_40 ,
V_41 ) )
return - V_42 ;
V_8 = F_11 ( sizeof( struct V_7 ) , V_43 ) ;
if ( ! V_8 )
return - V_44 ;
V_38 = F_12 ( V_2 , V_45 ) ;
if ( V_38 < 0 ) {
V_9 = V_38 ;
goto V_46;
}
V_39 = F_12 ( V_2 , V_47 ) ;
if ( V_39 < 0 ) {
V_9 = V_39 ;
goto V_46;
}
V_8 -> V_22 = V_22 -> V_48 ;
V_6 = & V_8 -> V_6 ;
V_6 -> V_49 = 1 ;
V_6 -> V_50 [ V_51 ] = V_52 ;
V_6 -> V_50 [ V_53 ] = V_52 ;
V_6 -> V_50 [ V_54 ] = V_52 ;
V_6 -> V_55 [ V_54 ] = 807 ;
V_6 -> V_56 [ V_54 ] = 20475 ;
V_6 -> V_57 [ V_54 ] = - 1 ;
V_6 -> V_58 [ 0 ] = V_59 | V_60 ;
V_6 -> V_61 = F_1 ;
V_6 -> V_62 = F_7 ;
V_6 -> V_63 = F_5 ;
if ( V_38 & V_64 ) {
V_6 -> V_55 [ V_51 ] = 19199 ;
V_6 -> V_56 [ V_51 ] = 0 ;
V_6 -> V_57 [ V_51 ] = - 2 ;
V_6 -> V_55 [ V_53 ] = 19199 ;
V_6 -> V_56 [ V_53 ] = 0 ;
V_6 -> V_57 [ V_53 ] = - 2 ;
} else {
V_6 -> V_55 [ V_51 ] = 6720 ;
V_6 -> V_56 [ V_51 ] = 0 ;
V_6 -> V_57 [ V_51 ] = - 1 ;
V_6 -> V_55 [ V_53 ] = 6720 ;
V_6 -> V_56 [ V_53 ] = 0 ;
V_6 -> V_57 [ V_53 ] = - 1 ;
}
if ( V_39 & V_65 )
V_8 -> V_12 = true ;
switch ( V_22 -> V_48 ) {
case V_66 :
if ( V_38 & V_67 )
V_6 -> V_58 [ 0 ] |=
V_68 | V_69 ;
else
V_6 -> V_58 [ 0 ] |=
V_70 | V_71 ;
break;
case V_23 :
V_6 -> V_50 [ V_72 ] = V_52 ;
V_6 -> V_58 [ 0 ] |= V_70 | V_73
| V_71 ;
if ( V_38 & V_67 )
V_6 -> V_58 [ 0 ] |=
V_68 | V_69 ;
if ( V_38 & V_64 ) {
V_6 -> V_55 [ V_72 ] = 6043 ;
V_6 -> V_56 [ V_72 ] = 0 ;
V_6 -> V_57 [ V_72 ] = - 2 ;
} else {
V_6 -> V_55 [ V_72 ] = 2115 ;
V_6 -> V_56 [ V_72 ] = 0 ;
V_6 -> V_57 [ V_72 ] = - 1 ;
}
break;
}
V_9 = F_13 ( V_2 , V_22 , V_6 ) ;
if ( V_9 )
goto V_46;
return 0 ;
V_46:
F_14 ( V_8 ) ;
return V_9 ;
}
static int F_15 ( struct V_1 * V_2 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
const struct V_7 * V_8 = F_3 ( V_6 ) ;
F_16 ( V_2 ) ;
F_14 ( V_8 ) ;
return 0 ;
}
static int T_2 F_17 ( void )
{
return F_18 ( & V_74 ) ;
}
static void T_3 F_19 ( void )
{
F_20 ( & V_74 ) ;
}
