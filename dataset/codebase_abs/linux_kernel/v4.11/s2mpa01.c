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
switch ( F_4 ( V_4 ) ) {
case V_11 :
case V_12 :
V_1 = V_8 -> V_13 ;
break;
case V_14 :
V_1 = V_8 -> V_15 ;
break;
case V_16 :
V_1 = V_8 -> V_17 ;
break;
case V_18 :
case V_19 :
V_1 = V_8 -> V_20 ;
break;
case V_21 :
V_1 = V_8 -> V_22 ;
break;
case V_23 :
case V_24 :
case V_25 :
V_1 = V_8 -> V_26 ;
break;
}
if ( V_1 == 0 )
V_1 = V_4 -> V_27 -> V_1 ;
V_9 = V_4 -> V_27 -> V_28 + ( V_4 -> V_27 -> V_29 * V_5 ) ;
V_10 = V_4 -> V_27 -> V_28 + ( V_4 -> V_27 -> V_29 * V_6 ) ;
return F_5 ( abs ( V_10 - V_9 ) , V_1 ) ;
}
static int F_6 ( struct V_3 * V_4 , int V_1 )
{
struct V_7 * V_8 = F_3 ( V_4 ) ;
unsigned int V_30 , V_31 , V_32 = V_33 ;
unsigned int V_34 = 1 , V_35 = 0 ;
int V_36 ;
switch ( F_4 ( V_4 ) ) {
case V_18 :
V_35 = V_37 ;
if ( ! V_1 ) {
V_34 = 0 ;
break;
}
if ( V_1 > V_8 -> V_20 )
V_8 -> V_20 = V_1 ;
else
V_1 = V_8 -> V_20 ;
V_31 = V_38 ;
break;
case V_11 :
V_35 = V_39 ;
if ( ! V_1 ) {
V_34 = 0 ;
break;
}
if ( V_1 > V_8 -> V_13 )
V_8 -> V_13 = V_1 ;
else
V_1 = V_8 -> V_13 ;
V_31 = V_40 ;
V_32 = V_41 ;
break;
case V_14 :
V_35 = V_42 ;
if ( ! V_1 ) {
V_34 = 0 ;
break;
}
V_8 -> V_15 = V_1 ;
V_31 = V_43 ;
V_32 = V_41 ;
break;
case V_12 :
V_35 = V_44 ;
if ( ! V_1 ) {
V_34 = 0 ;
break;
}
if ( V_1 > V_8 -> V_13 )
V_8 -> V_13 = V_1 ;
else
V_1 = V_8 -> V_13 ;
V_31 = V_40 ;
V_32 = V_41 ;
break;
case V_16 :
V_8 -> V_17 = V_1 ;
V_31 = V_45 ;
break;
case V_19 :
if ( V_1 > V_8 -> V_20 )
V_8 -> V_20 = V_1 ;
else
V_1 = V_8 -> V_20 ;
V_31 = V_38 ;
break;
case V_21 :
V_8 -> V_22 = V_1 ;
V_31 = V_46 ;
break;
case V_23 :
case V_24 :
case V_25 :
if ( V_1 > V_8 -> V_26 )
V_8 -> V_26 = V_1 ;
else
V_1 = V_8 -> V_26 ;
V_31 = V_47 ;
break;
default:
return 0 ;
}
if ( ! V_34 )
goto V_48;
if ( F_4 ( V_4 ) >= V_18 &&
F_4 ( V_4 ) <= V_12 ) {
V_36 = F_7 ( V_4 -> V_49 , V_41 ,
1 << V_35 , 1 << V_35 ) ;
if ( V_36 ) {
F_8 ( & V_4 -> V_50 , L_1 ) ;
return V_36 ;
}
}
V_30 = F_1 ( V_1 ) ;
return F_7 ( V_4 -> V_49 , V_32 , 0x3 << V_31 ,
V_30 << V_31 ) ;
V_48:
return F_7 ( V_4 -> V_49 , V_41 ,
1 << V_35 , 0 ) ;
}
static int F_9 ( struct V_51 * V_52 )
{
struct V_53 * V_54 = F_10 ( V_52 -> V_50 . V_55 ) ;
struct V_56 * V_57 = F_11 ( V_54 -> V_50 ) ;
struct V_58 * V_59 = NULL ;
struct V_60 V_61 = { } ;
struct V_62 * V_63 ;
struct V_7 * V_8 ;
int V_64 ;
V_8 = F_12 ( & V_52 -> V_50 , sizeof( * V_8 ) , V_65 ) ;
if ( ! V_8 )
return - V_66 ;
V_63 = V_8 -> V_63 ;
for ( V_64 = 0 ; V_64 < V_67 ; V_64 ++ )
V_63 [ V_64 ] . V_68 = V_69 [ V_64 ] . V_68 ;
if ( V_54 -> V_50 -> V_70 ) {
V_59 = F_13 ( V_54 -> V_50 -> V_70 ,
L_2 ) ;
if ( ! V_59 ) {
F_8 ( & V_52 -> V_50 ,
L_3 ) ;
return - V_71 ;
}
V_62 ( & V_52 -> V_50 , V_59 , V_63 ,
V_72 ) ;
F_14 ( V_59 ) ;
}
F_15 ( V_52 , V_8 ) ;
V_61 . V_50 = & V_52 -> V_50 ;
V_61 . V_49 = V_54 -> V_73 ;
V_61 . V_74 = V_8 ;
for ( V_64 = 0 ; V_64 < V_72 ; V_64 ++ ) {
struct V_3 * V_4 ;
if ( V_57 )
V_61 . V_75 = V_57 -> V_69 [ V_64 ] . V_76 ;
else
V_61 . V_75 = V_63 [ V_64 ] . V_75 ;
if ( V_59 )
V_61 . V_70 = V_63 [ V_64 ] . V_70 ;
V_4 = F_16 ( & V_52 -> V_50 ,
& V_69 [ V_64 ] , & V_61 ) ;
if ( F_17 ( V_4 ) ) {
F_8 ( & V_52 -> V_50 , L_4 ,
V_64 ) ;
return F_18 ( V_4 ) ;
}
}
return 0 ;
}
