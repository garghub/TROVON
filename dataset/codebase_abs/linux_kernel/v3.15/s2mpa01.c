static int F_1 ( int V_1 )
{
unsigned char V_2 = 0 ;
V_1 /= 6250 ;
while ( true ) {
V_1 = V_1 >> 1 ;
if ( V_1 == 0 )
break;
V_2 ++ ;
}
if ( V_2 > 3 )
V_2 = 3 ;
return V_2 ;
}
static int F_2 ( struct V_3 * V_4 ,
unsigned int V_5 ,
unsigned int V_6 )
{
struct V_7 * V_8 = F_3 ( V_4 ) ;
unsigned int V_1 = 0 ;
int V_9 , V_10 ;
switch ( V_4 -> V_11 -> V_12 ) {
case V_13 :
case V_14 :
V_1 = V_8 -> V_15 ;
break;
case V_16 :
V_1 = V_8 -> V_17 ;
break;
case V_18 :
V_1 = V_8 -> V_19 ;
break;
case V_20 :
case V_21 :
V_1 = V_8 -> V_22 ;
break;
case V_23 :
V_1 = V_8 -> V_24 ;
break;
case V_25 :
case V_26 :
case V_27 :
V_1 = V_8 -> V_28 ;
break;
}
if ( V_1 == 0 )
V_1 = V_4 -> V_11 -> V_1 ;
V_9 = V_4 -> V_11 -> V_29 + ( V_4 -> V_11 -> V_30 * V_5 ) ;
V_10 = V_4 -> V_11 -> V_29 + ( V_4 -> V_11 -> V_30 * V_6 ) ;
return F_4 ( abs ( V_10 - V_9 ) , V_1 ) ;
}
static int F_5 ( struct V_3 * V_4 , int V_1 )
{
struct V_7 * V_8 = F_3 ( V_4 ) ;
unsigned int V_31 , V_32 , V_33 = V_34 ;
unsigned int V_35 = 1 , V_36 = 0 ;
int V_37 ;
switch ( V_4 -> V_11 -> V_12 ) {
case V_20 :
V_36 = V_38 ;
if ( ! V_1 ) {
V_35 = 0 ;
break;
}
if ( V_1 > V_8 -> V_22 )
V_8 -> V_22 = V_1 ;
else
V_1 = V_8 -> V_22 ;
V_32 = V_39 ;
V_33 = V_40 ;
break;
case V_13 :
V_36 = V_41 ;
if ( ! V_1 ) {
V_35 = 0 ;
break;
}
if ( V_1 > V_8 -> V_15 )
V_8 -> V_15 = V_1 ;
else
V_1 = V_8 -> V_15 ;
V_32 = V_42 ;
V_33 = V_40 ;
break;
case V_16 :
V_36 = V_43 ;
if ( ! V_1 ) {
V_35 = 0 ;
break;
}
V_8 -> V_17 = V_1 ;
V_32 = V_44 ;
V_33 = V_40 ;
break;
case V_14 :
V_36 = V_45 ;
if ( ! V_1 ) {
V_35 = 0 ;
break;
}
if ( V_1 > V_8 -> V_15 )
V_8 -> V_15 = V_1 ;
else
V_1 = V_8 -> V_15 ;
V_32 = V_42 ;
V_33 = V_40 ;
break;
case V_18 :
V_8 -> V_19 = V_1 ;
V_32 = V_46 ;
break;
case V_21 :
if ( V_1 > V_8 -> V_22 )
V_8 -> V_22 = V_1 ;
else
V_1 = V_8 -> V_22 ;
V_32 = V_39 ;
break;
case V_23 :
V_8 -> V_24 = V_1 ;
V_32 = V_47 ;
break;
case V_25 :
case V_26 :
case V_27 :
if ( V_1 > V_8 -> V_28 )
V_8 -> V_28 = V_1 ;
else
V_1 = V_8 -> V_28 ;
V_32 = V_48 ;
break;
default:
return 0 ;
}
if ( ! V_35 )
goto V_49;
V_37 = F_6 ( V_4 -> V_50 , V_40 ,
1 << V_36 , 1 << V_36 ) ;
if ( V_37 ) {
F_7 ( & V_4 -> V_51 , L_1 ) ;
return V_37 ;
}
V_31 = F_1 ( V_1 ) ;
return F_6 ( V_4 -> V_50 , V_33 , 0x3 << V_32 ,
V_31 << V_32 ) ;
V_49:
return F_6 ( V_4 -> V_50 , V_40 ,
1 << V_36 , 0 ) ;
}
static int F_8 ( struct V_52 * V_53 )
{
struct V_54 * V_55 = F_9 ( V_53 -> V_51 . V_56 ) ;
struct V_57 * V_58 = F_10 ( V_55 -> V_51 ) ;
struct V_59 V_60 [ V_61 ] ;
struct V_62 * V_63 = NULL ;
struct V_64 V_65 = { } ;
struct V_7 * V_8 ;
int V_66 ;
V_8 = F_11 ( & V_53 -> V_51 , sizeof( * V_8 ) , V_67 ) ;
if ( ! V_8 )
return - V_68 ;
for ( V_66 = 0 ; V_66 < V_69 ; V_66 ++ )
V_60 [ V_66 ] . V_70 = V_71 [ V_66 ] . V_70 ;
if ( V_55 -> V_51 -> V_72 ) {
V_63 = F_12 ( V_55 -> V_51 -> V_72 ,
L_2 ) ;
if ( ! V_63 ) {
F_7 ( & V_53 -> V_51 ,
L_3 ) ;
return - V_73 ;
}
V_59 ( & V_53 -> V_51 , V_63 , V_60 ,
V_61 ) ;
F_13 ( V_63 ) ;
}
F_14 ( V_53 , V_8 ) ;
V_65 . V_51 = & V_53 -> V_51 ;
V_65 . V_50 = V_55 -> V_74 ;
V_65 . V_75 = V_8 ;
for ( V_66 = 0 ; V_66 < V_61 ; V_66 ++ ) {
struct V_3 * V_4 ;
if ( V_58 )
V_65 . V_76 = V_58 -> V_71 [ V_66 ] . V_77 ;
else
V_65 . V_76 = V_60 [ V_66 ] . V_76 ;
if ( V_63 )
V_65 . V_72 = V_60 [ V_66 ] . V_72 ;
V_4 = F_15 ( & V_53 -> V_51 ,
& V_71 [ V_66 ] , & V_65 ) ;
if ( F_16 ( V_4 ) ) {
F_7 ( & V_53 -> V_51 , L_4 ,
V_66 ) ;
return F_17 ( V_4 ) ;
}
}
return 0 ;
}
