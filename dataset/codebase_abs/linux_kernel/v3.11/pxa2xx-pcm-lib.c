int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_7 * V_8 = V_6 -> V_9 ;
T_1 V_10 = F_2 ( V_4 ) ;
T_1 V_11 = F_3 ( V_4 ) ;
T_2 * V_12 ;
T_3 V_13 , V_14 ;
F_4 ( V_2 , & V_2 -> V_15 ) ;
V_6 -> V_16 = V_10 ;
V_12 = V_8 -> V_17 ;
V_14 = V_8 -> V_18 ;
V_13 = V_6 -> V_19 ;
do {
V_14 += sizeof( T_2 ) ;
V_12 -> V_20 = V_14 ;
if ( V_2 -> V_21 == V_22 ) {
V_12 -> V_23 = V_13 ;
V_12 -> V_24 = V_8 -> V_4 -> V_25 ;
} else {
V_12 -> V_23 = V_8 -> V_4 -> V_25 ;
V_12 -> V_24 = V_13 ;
}
if ( V_11 > V_10 )
V_11 = V_10 ;
V_12 -> V_26 = V_8 -> V_4 -> V_26 | V_11 | V_27 ;
V_12 ++ ;
V_13 += V_11 ;
} while ( V_10 -= V_11 );
V_12 [ - 1 ] . V_20 = V_8 -> V_18 ;
return 0 ;
}
int F_5 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_6 -> V_9 ;
if ( V_8 && V_8 -> V_4 && V_8 -> V_4 -> V_28 )
* V_8 -> V_4 -> V_28 = 0 ;
F_4 ( V_2 , NULL ) ;
return 0 ;
}
int F_6 ( struct V_1 * V_2 , int V_29 )
{
struct V_7 * V_30 = V_2 -> V_6 -> V_9 ;
int V_31 = 0 ;
switch ( V_29 ) {
case V_32 :
F_7 ( V_30 -> V_33 ) = V_30 -> V_18 ;
F_8 ( V_30 -> V_33 ) = V_34 ;
break;
case V_35 :
case V_36 :
case V_37 :
F_8 ( V_30 -> V_33 ) &= ~ V_34 ;
break;
case V_38 :
F_8 ( V_30 -> V_33 ) |= V_34 ;
break;
case V_39 :
F_7 ( V_30 -> V_33 ) = V_30 -> V_18 ;
F_8 ( V_30 -> V_33 ) |= V_34 ;
break;
default:
V_31 = - V_40 ;
}
return V_31 ;
}
T_4
F_9 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_7 * V_30 = V_6 -> V_9 ;
T_3 V_41 = ( V_2 -> V_21 == V_22 ) ?
F_10 ( V_30 -> V_33 ) : F_11 ( V_30 -> V_33 ) ;
T_4 V_42 = F_12 ( V_6 , V_41 - V_6 -> V_19 ) ;
if ( V_42 == V_6 -> V_43 )
V_42 = 0 ;
return V_42 ;
}
int F_13 ( struct V_1 * V_2 )
{
struct V_7 * V_30 = V_2 -> V_6 -> V_9 ;
if ( ! V_30 || ! V_30 -> V_4 )
return 0 ;
if ( V_30 -> V_33 == - 1 )
return - V_40 ;
F_8 ( V_30 -> V_33 ) &= ~ V_34 ;
F_8 ( V_30 -> V_33 ) = 0 ;
F_14 ( V_30 -> V_33 ) = 0 ;
* V_30 -> V_4 -> V_28 = V_30 -> V_33 | V_44 ;
return 0 ;
}
void F_15 ( int V_33 , void * V_45 )
{
struct V_1 * V_2 = V_45 ;
struct V_7 * V_8 = V_2 -> V_6 -> V_9 ;
int V_46 ;
V_46 = F_8 ( V_33 ) ;
F_8 ( V_33 ) = V_46 & ~ V_47 ;
if ( V_46 & V_48 ) {
F_16 ( V_2 ) ;
} else {
F_17 ( V_49 L_1 ,
V_8 -> V_4 -> V_50 , V_33 , V_46 ) ;
F_18 ( V_2 ) ;
F_19 ( V_2 , V_51 ) ;
F_20 ( V_2 ) ;
}
}
int F_21 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_7 * V_8 ;
int V_31 ;
V_6 -> V_52 = V_53 ;
V_31 = F_22 ( V_6 , 0 ,
V_54 , 32 ) ;
if ( V_31 )
goto V_55;
V_31 = F_22 ( V_6 , 0 ,
V_56 , 32 ) ;
if ( V_31 )
goto V_55;
V_31 = F_23 ( V_6 ,
V_57 ) ;
if ( V_31 < 0 )
goto V_55;
V_31 = - V_58 ;
V_8 = F_24 ( sizeof( * V_8 ) , V_59 ) ;
if ( ! V_8 )
goto V_55;
V_8 -> V_17 =
F_25 ( V_2 -> V_60 -> V_61 -> V_62 , V_63 ,
& V_8 -> V_18 , V_59 ) ;
if ( ! V_8 -> V_17 )
goto V_64;
V_8 -> V_33 = - 1 ;
V_6 -> V_9 = V_8 ;
return 0 ;
V_64:
F_26 ( V_8 ) ;
V_55:
return V_31 ;
}
int F_27 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_7 * V_8 = V_6 -> V_9 ;
F_28 ( V_2 -> V_60 -> V_61 -> V_62 , V_63 ,
V_8 -> V_17 , V_8 -> V_18 ) ;
F_26 ( V_8 ) ;
return 0 ;
}
int F_29 ( struct V_1 * V_2 ,
struct V_65 * V_66 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
return F_30 ( V_2 -> V_60 -> V_61 -> V_62 , V_66 ,
V_6 -> V_67 ,
V_6 -> V_19 ,
V_6 -> V_16 ) ;
}
int F_31 ( struct V_68 * V_60 , int V_21 )
{
struct V_1 * V_2 = V_60 -> V_69 [ V_21 ] . V_2 ;
struct V_70 * V_71 = & V_2 -> V_15 ;
T_1 V_72 = V_53 . V_73 ;
V_71 -> V_62 . type = V_74 ;
V_71 -> V_62 . V_62 = V_60 -> V_61 -> V_62 ;
V_71 -> V_9 = NULL ;
V_71 -> V_75 = F_25 ( V_60 -> V_61 -> V_62 , V_72 ,
& V_71 -> V_76 , V_59 ) ;
if ( ! V_71 -> V_75 )
return - V_58 ;
V_71 -> V_77 = V_72 ;
return 0 ;
}
void F_32 ( struct V_68 * V_60 )
{
struct V_1 * V_2 ;
struct V_70 * V_71 ;
int V_21 ;
for ( V_21 = 0 ; V_21 < 2 ; V_21 ++ ) {
V_2 = V_60 -> V_69 [ V_21 ] . V_2 ;
if ( ! V_2 )
continue;
V_71 = & V_2 -> V_15 ;
if ( ! V_71 -> V_75 )
continue;
F_28 ( V_60 -> V_61 -> V_62 , V_71 -> V_77 ,
V_71 -> V_75 , V_71 -> V_76 ) ;
V_71 -> V_75 = NULL ;
}
}
