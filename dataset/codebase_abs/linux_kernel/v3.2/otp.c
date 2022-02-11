static T_1
F_1 ( struct V_1 * V_2 , struct V_3 T_2 * V_4 , T_3 V_5 )
{
return F_2 ( & V_4 -> V_6 [ V_5 ] ) ;
}
static int F_3 ( struct V_7 * V_8 , int V_9 )
{
int V_10 = 0 ;
switch ( V_8 -> V_11 ) {
case V_12 :
case V_13 :
V_10 = V_9 * 2 - V_14 - V_15 ;
break;
case V_16 :
V_10 = V_9 * 2 - V_14 - V_15 ;
break;
default:
break;
}
return V_10 ;
}
static void F_4 ( struct V_1 * V_2 , struct V_3 T_2 * V_4 )
{
T_3 V_17 ;
T_4 V_18 , V_19 ;
if ( V_2 -> V_8 -> V_20 == 21 || V_2 -> V_8 -> V_20 == 24
|| V_2 -> V_8 -> V_20 == 27 ) {
V_2 -> V_21 = V_22 ;
} else if ( V_2 -> V_8 -> V_20 == 36 ) {
if ( V_2 -> V_23 >= 128 )
V_2 -> V_21 = V_24 ;
else
V_2 -> V_21 = V_25 ;
} else if ( V_2 -> V_8 -> V_20 == 23 || V_2 -> V_8 -> V_20 >= 25 ) {
V_2 -> V_21 = V_24 ;
}
V_18 =
V_26 | ( ( V_27 << V_28 ) & V_29 ) ;
F_5 ( & V_4 -> V_30 , V_18 ) ;
for ( V_17 = 0 ;
( ( V_19 = F_2 ( & V_4 -> V_30 ) ) & V_26 )
&& ( V_17 < V_31 ) ; V_17 ++ )
;
if ( V_17 >= V_31 )
return;
V_2 -> V_32 = F_2 ( & V_4 -> V_33 ) ;
if ( ( V_2 -> V_8 -> V_11 == V_12 )
|| ( V_2 -> V_8 -> V_11 == V_13 ) ) {
T_4 V_34 ;
V_34 =
( F_1 ( V_2 , V_4 , V_2 -> V_21 + V_35 ) &
V_36 )
>> V_37 ;
V_2 -> V_32 |= ( V_34 << V_38 ) ;
}
V_2 -> V_39 = V_2 -> V_21 + V_40 ;
V_2 -> V_41 = V_2 -> V_23 ;
if ( V_2 -> V_32 & V_42 ) {
V_2 -> V_41 =
F_1 ( V_2 , V_4 , V_2 -> V_21 + V_43 ) / 16 ;
V_2 -> V_44 = V_2 -> V_41 ;
} else
V_2 -> V_44 = V_2 -> V_39 ;
V_2 -> V_45 = F_3 ( V_2 -> V_8 , V_2 -> V_23 ) / 2 ;
if ( V_2 -> V_32 & V_46 ) {
V_2 -> V_45 =
F_1 ( V_2 , V_4 , V_2 -> V_21 + V_47 ) / 16 ;
V_2 -> V_48 = V_2 -> V_45 ;
} else
V_2 -> V_48 = V_2 -> V_44 ;
V_2 -> V_49 = V_2 -> V_23 ;
}
static int F_6 ( struct V_7 * V_8 , struct V_1 * V_2 )
{
T_3 V_50 ;
struct V_3 T_2 * V_4 ;
if ( ! F_7 ( V_8 -> V_20 ) )
return - V_51 ;
if ( F_8 ( V_8 ) )
return - V_51 ;
switch ( ( V_8 -> V_52 & V_53 ) >> V_54 ) {
case 0 :
return - V_51 ;
case 1 :
V_2 -> V_55 = 32 ;
V_2 -> V_56 = 64 ;
V_2 -> V_23 = 128 ;
break;
case 2 :
V_2 -> V_55 = 64 ;
V_2 -> V_56 = 64 ;
V_2 -> V_23 = 256 ;
break;
case 5 :
V_2 -> V_55 = 96 ;
V_2 -> V_56 = 64 ;
V_2 -> V_23 = 384 ;
break;
case 7 :
V_2 -> V_55 = 16 ;
V_2 -> V_56 = 64 ;
V_2 -> V_23 = 64 ;
break;
default:
return - V_51 ;
}
V_50 = F_9 ( V_8 ) ;
V_4 = F_10 ( V_8 , V_57 ) ;
F_4 ( V_2 , V_4 ) ;
F_10 ( V_8 , V_50 ) ;
return 0 ;
}
static int
F_11 ( struct V_1 * V_2 , int V_58 , T_1 * V_59 , T_3 * V_60 )
{
T_3 V_50 ;
struct V_3 T_2 * V_4 ;
T_3 V_61 , V_62 , V_63 ;
switch ( V_58 ) {
case V_64 :
V_63 = ( T_3 ) V_2 -> V_41 - V_2 -> V_39 ;
if ( ! ( V_2 -> V_32 & V_42 ) ) {
* V_60 = V_63 ;
return - V_65 ;
}
if ( * V_60 < V_63 ) {
* V_60 = V_63 ;
return - V_66 ;
}
V_61 = V_2 -> V_39 ;
break;
case V_67 :
V_63 = ( ( T_3 ) V_2 -> V_45 - V_2 -> V_44 ) ;
if ( ! ( V_2 -> V_32 & V_46 ) ) {
* V_60 = V_63 ;
return - V_65 ;
}
if ( * V_60 < V_63 ) {
* V_60 = V_63 ;
return - V_66 ;
}
V_61 = V_2 -> V_44 ;
break;
case V_68 :
V_63 = V_69 ;
if ( ! ( V_2 -> V_32 & V_70 ) ) {
* V_60 = V_63 ;
return - V_65 ;
}
if ( * V_60 < V_63 ) {
* V_60 = V_63 ;
return - V_66 ;
}
V_61 = V_2 -> V_21 + V_71 ;
break;
case V_72 :
V_63 = ( T_3 ) V_2 -> V_49 - V_2 -> V_48 ;
if ( ! ( V_2 -> V_32 & V_73 ) ) {
* V_60 = V_63 ;
return - V_65 ;
}
if ( * V_60 < V_63 ) {
* V_60 = V_63 ;
return - V_66 ;
}
V_61 = V_2 -> V_48 ;
break;
case V_74 :
V_63 = ( ( T_3 ) V_2 -> V_49 - V_2 -> V_39 ) ;
if ( ! ( V_2 -> V_32 & ( V_42 | V_46 ) ) ) {
* V_60 = V_63 ;
return - V_65 ;
}
if ( * V_60 < V_63 ) {
* V_60 = V_63 ;
return - V_66 ;
}
V_61 = V_2 -> V_39 ;
break;
default:
return - V_75 ;
}
V_50 = F_9 ( V_2 -> V_8 ) ;
V_4 = F_10 ( V_2 -> V_8 , V_57 ) ;
for ( V_62 = 0 ; V_62 < V_63 ; V_62 ++ )
V_59 [ V_62 ] = F_1 ( V_2 , V_4 , V_61 + V_62 ) ;
F_10 ( V_2 -> V_8 , V_50 ) ;
* V_60 = V_63 ;
return 0 ;
}
static int F_12 ( struct V_7 * V_8 , struct V_1 * V_2 )
{
int V_10 ;
memset ( V_2 , 0 , sizeof( struct V_1 ) ) ;
V_2 -> V_20 = V_8 -> V_20 ;
if ( F_7 ( V_2 -> V_20 ) )
V_2 -> V_76 = & V_77 ;
if ( V_2 -> V_76 == NULL )
return - V_51 ;
V_2 -> V_8 = V_8 ;
V_10 = ( V_2 -> V_76 -> V_78 ) ( V_8 , V_2 ) ;
return V_10 ;
}
int
F_13 ( struct V_7 * V_8 , int V_58 , T_1 * V_59 , T_3 * V_60 ) {
struct V_1 V_1 ;
struct V_1 * V_2 = & V_1 ;
int V_79 = 0 ;
if ( F_8 ( V_8 ) ) {
V_79 = - V_80 ;
goto V_81;
}
V_79 = F_12 ( V_8 , V_2 ) ;
if ( V_79 )
goto V_81;
V_79 = ( ( V_2 ) -> V_76 -> V_82 ) ( V_2 , V_58 , V_59 , V_60 ) ;
V_81:
return V_79 ;
}
