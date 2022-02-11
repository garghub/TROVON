static T_1
F_1 ( struct V_1 * V_2 , T_2 V_3 )
{
return F_2 ( V_2 -> V_4 ,
F_3 ( V_5 [ V_3 ] ) ) ;
}
static int F_4 ( struct V_6 * V_7 , int V_8 )
{
int V_9 = 0 ;
switch ( F_5 ( V_7 ) ) {
case V_10 :
case V_11 :
V_9 = V_8 * 2 - V_12 - V_13 ;
break;
case V_14 :
V_9 = V_8 * 2 - V_12 - V_13 ;
break;
default:
break;
}
return V_9 ;
}
static void F_6 ( struct V_1 * V_2 )
{
T_2 V_15 ;
T_3 V_16 , V_17 ;
int V_18 = F_7 ( V_2 -> V_7 ) ;
if ( V_18 == 21 || V_18 == 24
|| V_18 == 27 ) {
V_2 -> V_19 = V_20 ;
} else if ( V_18 == 36 ) {
if ( V_2 -> V_21 >= 128 )
V_2 -> V_19 = V_22 ;
else
V_2 -> V_19 = V_23 ;
} else if ( V_18 == 23 || V_18 >= 25 ) {
V_2 -> V_19 = V_22 ;
}
V_16 =
V_24 | ( ( V_25 << V_26 ) & V_27 ) ;
F_8 ( V_2 -> V_4 , F_3 ( V_28 ) , V_16 ) ;
V_17 = F_9 ( V_2 -> V_4 , F_3 ( V_28 ) ) ;
for ( V_15 = 0 ; ( V_17 & V_24 ) && ( V_15 < V_29 ) ; V_15 ++ )
V_17 = F_9 ( V_2 -> V_4 , F_3 ( V_28 ) ) ;
if ( V_15 >= V_29 )
return;
V_2 -> V_30 = F_9 ( V_2 -> V_4 , F_3 ( V_31 ) ) ;
if ( ( F_5 ( V_2 -> V_7 ) == V_10 )
|| ( F_5 ( V_2 -> V_7 ) == V_11 ) ) {
T_3 V_32 ;
V_32 = ( F_1 ( V_2 , V_2 -> V_19 + V_33 ) &
V_34 ) >> V_35 ;
V_2 -> V_30 |= ( V_32 << V_36 ) ;
}
V_2 -> V_37 = V_2 -> V_19 + V_38 ;
V_2 -> V_39 = V_2 -> V_21 ;
if ( V_2 -> V_30 & V_40 ) {
V_2 -> V_39 =
F_1 ( V_2 , V_2 -> V_19 + V_41 ) / 16 ;
V_2 -> V_42 = V_2 -> V_39 ;
} else
V_2 -> V_42 = V_2 -> V_37 ;
V_2 -> V_43 = F_4 ( V_2 -> V_7 , V_2 -> V_21 ) / 2 ;
if ( V_2 -> V_30 & V_44 ) {
V_2 -> V_43 =
F_1 ( V_2 , V_2 -> V_19 + V_45 ) / 16 ;
V_2 -> V_46 = V_2 -> V_43 ;
} else
V_2 -> V_46 = V_2 -> V_42 ;
V_2 -> V_47 = V_2 -> V_21 ;
}
static int F_10 ( struct V_6 * V_7 , struct V_1 * V_2 )
{
if ( ! F_11 ( F_7 ( V_7 ) ) )
return - V_48 ;
if ( F_12 ( V_7 ) )
return - V_48 ;
switch ( ( F_13 ( V_7 ) & V_49 ) >> V_50 ) {
case 0 :
return - V_48 ;
case 1 :
V_2 -> V_51 = 32 ;
V_2 -> V_52 = 64 ;
V_2 -> V_21 = 128 ;
break;
case 2 :
V_2 -> V_51 = 64 ;
V_2 -> V_52 = 64 ;
V_2 -> V_21 = 256 ;
break;
case 5 :
V_2 -> V_51 = 96 ;
V_2 -> V_52 = 64 ;
V_2 -> V_21 = 384 ;
break;
case 7 :
V_2 -> V_51 = 16 ;
V_2 -> V_52 = 64 ;
V_2 -> V_21 = 64 ;
break;
default:
return - V_48 ;
}
F_6 ( V_2 ) ;
return 0 ;
}
static int
F_14 ( struct V_1 * V_2 , int V_53 , T_1 * V_54 , T_2 * V_55 )
{
T_2 V_56 , V_57 , V_58 ;
switch ( V_53 ) {
case V_59 :
V_58 = ( T_2 ) V_2 -> V_39 - V_2 -> V_37 ;
if ( ! ( V_2 -> V_30 & V_40 ) ) {
* V_55 = V_58 ;
return - V_60 ;
}
if ( * V_55 < V_58 ) {
* V_55 = V_58 ;
return - V_61 ;
}
V_56 = V_2 -> V_37 ;
break;
case V_62 :
V_58 = ( ( T_2 ) V_2 -> V_43 - V_2 -> V_42 ) ;
if ( ! ( V_2 -> V_30 & V_44 ) ) {
* V_55 = V_58 ;
return - V_60 ;
}
if ( * V_55 < V_58 ) {
* V_55 = V_58 ;
return - V_61 ;
}
V_56 = V_2 -> V_42 ;
break;
case V_63 :
V_58 = V_64 ;
if ( ! ( V_2 -> V_30 & V_65 ) ) {
* V_55 = V_58 ;
return - V_60 ;
}
if ( * V_55 < V_58 ) {
* V_55 = V_58 ;
return - V_61 ;
}
V_56 = V_2 -> V_19 + V_66 ;
break;
case V_67 :
V_58 = ( T_2 ) V_2 -> V_47 - V_2 -> V_46 ;
if ( ! ( V_2 -> V_30 & V_68 ) ) {
* V_55 = V_58 ;
return - V_60 ;
}
if ( * V_55 < V_58 ) {
* V_55 = V_58 ;
return - V_61 ;
}
V_56 = V_2 -> V_46 ;
break;
case V_69 :
V_58 = ( ( T_2 ) V_2 -> V_47 - V_2 -> V_37 ) ;
if ( ! ( V_2 -> V_30 & ( V_40 | V_44 ) ) ) {
* V_55 = V_58 ;
return - V_60 ;
}
if ( * V_55 < V_58 ) {
* V_55 = V_58 ;
return - V_61 ;
}
V_56 = V_2 -> V_37 ;
break;
default:
return - V_70 ;
}
for ( V_57 = 0 ; V_57 < V_58 ; V_57 ++ )
V_54 [ V_57 ] = F_1 ( V_2 , V_56 + V_57 ) ;
* V_55 = V_58 ;
return 0 ;
}
static int F_15 ( struct V_6 * V_7 , struct V_1 * V_2 )
{
int V_9 ;
memset ( V_2 , 0 , sizeof( struct V_1 ) ) ;
V_2 -> V_4 = F_16 ( V_7 , V_71 , 0 ) ;
if ( F_11 ( F_7 ( V_7 ) ) )
V_2 -> V_72 = & V_73 ;
if ( V_2 -> V_72 == NULL )
return - V_48 ;
V_2 -> V_7 = V_7 ;
V_9 = ( V_2 -> V_72 -> V_74 ) ( V_7 , V_2 ) ;
return V_9 ;
}
int
F_17 ( struct V_6 * V_7 , int V_53 , T_1 * V_54 , T_2 * V_55 ) {
struct V_1 V_1 ;
struct V_1 * V_2 = & V_1 ;
int V_75 = 0 ;
if ( F_12 ( V_7 ) ) {
V_75 = - V_76 ;
goto V_77;
}
V_75 = F_15 ( V_7 , V_2 ) ;
if ( V_75 )
goto V_77;
V_75 = ( ( V_2 ) -> V_72 -> V_78 ) ( V_2 , V_53 , V_54 , V_55 ) ;
V_77:
return V_75 ;
}
