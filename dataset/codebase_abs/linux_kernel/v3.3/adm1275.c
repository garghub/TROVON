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
T_2 V_38 [ V_39 + 1 ] ;
int V_40 , V_41 ;
int V_9 ;
struct V_5 * V_6 ;
struct V_7 * V_8 ;
const struct V_37 * V_42 ;
if ( ! F_10 ( V_2 -> V_43 ,
V_44
| V_45 ) )
return - V_46 ;
V_9 = F_11 ( V_2 , V_47 , V_38 ) ;
if ( V_9 < 0 ) {
F_12 ( & V_2 -> V_48 , L_1 ) ;
return V_9 ;
}
if ( V_9 != 3 || strncmp ( V_38 , L_2 , 3 ) ) {
F_12 ( & V_2 -> V_48 , L_3 ) ;
return - V_46 ;
}
V_9 = F_11 ( V_2 , V_49 , V_38 ) ;
if ( V_9 < 0 ) {
F_12 ( & V_2 -> V_48 , L_4 ) ;
return V_9 ;
}
for ( V_42 = V_50 ; V_42 -> V_51 [ 0 ] ; V_42 ++ ) {
if ( ! strncasecmp ( V_42 -> V_51 , V_38 , strlen ( V_42 -> V_51 ) ) )
break;
}
if ( ! V_42 -> V_51 [ 0 ] ) {
F_12 ( & V_2 -> V_48 , L_5 ) ;
return - V_46 ;
}
if ( V_22 -> V_52 != V_42 -> V_52 )
F_13 ( & V_2 -> V_48 ,
L_6 ,
V_22 -> V_51 , V_42 -> V_51 ) ;
V_40 = F_14 ( V_2 , V_53 ) ;
if ( V_40 < 0 )
return V_40 ;
V_41 = F_14 ( V_2 , V_54 ) ;
if ( V_41 < 0 )
return V_41 ;
V_8 = F_15 ( sizeof( struct V_7 ) , V_55 ) ;
if ( ! V_8 )
return - V_56 ;
V_8 -> V_22 = V_42 -> V_52 ;
V_6 = & V_8 -> V_6 ;
V_6 -> V_57 = 1 ;
V_6 -> V_58 [ V_59 ] = V_60 ;
V_6 -> V_58 [ V_61 ] = V_60 ;
V_6 -> V_58 [ V_62 ] = V_60 ;
V_6 -> V_63 [ V_62 ] = 807 ;
V_6 -> V_64 [ V_62 ] = 20475 ;
V_6 -> V_65 [ V_62 ] = - 1 ;
V_6 -> V_66 [ 0 ] = V_67 | V_68 ;
V_6 -> V_69 = F_1 ;
V_6 -> V_70 = F_7 ;
V_6 -> V_71 = F_5 ;
if ( V_40 & V_72 ) {
V_6 -> V_63 [ V_59 ] = 19199 ;
V_6 -> V_64 [ V_59 ] = 0 ;
V_6 -> V_65 [ V_59 ] = - 2 ;
V_6 -> V_63 [ V_61 ] = 19199 ;
V_6 -> V_64 [ V_61 ] = 0 ;
V_6 -> V_65 [ V_61 ] = - 2 ;
} else {
V_6 -> V_63 [ V_59 ] = 6720 ;
V_6 -> V_64 [ V_59 ] = 0 ;
V_6 -> V_65 [ V_59 ] = - 1 ;
V_6 -> V_63 [ V_61 ] = 6720 ;
V_6 -> V_64 [ V_61 ] = 0 ;
V_6 -> V_65 [ V_61 ] = - 1 ;
}
if ( V_41 & V_73 )
V_8 -> V_12 = true ;
switch ( V_8 -> V_22 ) {
case V_74 :
if ( V_40 & V_75 )
V_6 -> V_66 [ 0 ] |=
V_76 | V_77 ;
else
V_6 -> V_66 [ 0 ] |=
V_78 | V_79 ;
break;
case V_23 :
V_6 -> V_58 [ V_80 ] = V_60 ;
V_6 -> V_66 [ 0 ] |= V_78 | V_81
| V_79 ;
if ( V_40 & V_75 )
V_6 -> V_66 [ 0 ] |=
V_76 | V_77 ;
if ( V_40 & V_72 ) {
V_6 -> V_63 [ V_80 ] = 6043 ;
V_6 -> V_64 [ V_80 ] = 0 ;
V_6 -> V_65 [ V_80 ] = - 2 ;
} else {
V_6 -> V_63 [ V_80 ] = 2115 ;
V_6 -> V_64 [ V_80 ] = 0 ;
V_6 -> V_65 [ V_80 ] = - 1 ;
}
break;
}
V_9 = F_16 ( V_2 , V_22 , V_6 ) ;
if ( V_9 )
goto V_82;
return 0 ;
V_82:
F_17 ( V_8 ) ;
return V_9 ;
}
static int F_18 ( struct V_1 * V_2 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
const struct V_7 * V_8 = F_3 ( V_6 ) ;
F_19 ( V_2 ) ;
F_17 ( V_8 ) ;
return 0 ;
}
static int T_3 F_20 ( void )
{
return F_21 ( & V_83 ) ;
}
static void T_4 F_22 ( void )
{
F_23 ( & V_83 ) ;
}
