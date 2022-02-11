void F_1 ( int V_1 )
{
struct V_2 * V_3 ;
V_3 = F_2 ( V_1 ) ;
V_3 -> V_4 = F_3 ( V_1 ) ;
V_3 -> V_5 = F_4 ( V_1 ) ;
V_3 -> V_6 = F_5 () & ( ~ ( ( 1 << 12 ) - 1 ) ) ;
F_6 ( & V_3 -> V_7 ) ;
}
int F_7 ( int V_8 )
{
T_1 V_9 ;
int V_10 , V_11 ;
V_10 = 0 ;
switch ( V_8 ) {
case V_12 :
V_10 = F_8 ( 0 ) ;
break;
case V_13 :
V_10 = F_9 ( 0 ) ;
break;
case V_14 :
V_10 = F_10 ( 0 ) ;
break;
case V_15 :
case V_16 :
case V_17 :
case V_18 :
if ( F_11 () )
V_10 = F_12 ( 0 ) ;
else
V_10 = F_13 ( 0 ) ;
break;
default:
if ( F_11 () ) {
switch ( V_8 ) {
case V_19 :
V_10 = F_14 ( 0 ) ;
break;
case V_20 :
V_10 = F_15 ( 0 ) ;
break;
case V_21 :
V_10 = F_16 ( 0 ) ;
break;
}
} else {
switch ( V_8 ) {
case V_22 :
V_10 = F_17 ( 0 ) ;
break;
case V_23 :
V_10 = F_18 ( 0 ) ;
break;
case V_24 :
V_10 = F_19 ( 0 ) ;
break;
case V_25 :
V_10 = F_20 ( 0 ) ;
break;
case V_26 :
V_10 = F_21 ( 0 ) ;
break;
case V_27 :
V_10 = F_22 ( 0 ) ;
break;
}
}
}
if ( V_10 != 0 ) {
V_9 = F_23 ( V_10 ) ;
V_11 = F_24 ( V_9 , V_28 ) & 0xffff ;
switch ( V_8 ) {
case V_16 :
V_11 = V_11 + 1 ; break;
case V_17 :
V_11 = V_11 + 2 ; break;
case V_18 :
V_11 = V_11 + 3 ; break;
}
} else if ( V_8 >= V_29 && V_8 <= V_30 ) {
V_11 = F_25 ( V_8 - V_29 ) ;
} else {
V_11 = - 1 ;
}
return V_11 ;
}
unsigned int F_26 ( int V_1 , int V_31 )
{
unsigned int V_32 , V_33 , V_34 , V_35 ;
unsigned int V_36 , V_37 , V_38 ;
T_1 V_39 , V_4 ;
V_4 = F_2 ( V_1 ) -> V_4 ;
V_36 = F_27 ( V_4 , V_40 ) ;
if ( F_11 () ) {
V_39 = 1000000ULL * ( 400 * 3 + 100 * ( V_36 >> 26 ) ) ;
V_38 = 3 ;
} else {
V_37 = F_27 ( V_4 , V_41 ) ;
V_32 = ( ( V_36 >> 10 ) & 0x7f ) + 1 ;
V_33 = ( ( V_36 >> 8 ) & 0x3 ) + 1 ;
V_35 = ( ( V_36 >> 30 ) & 0x3 ) + 1 ;
V_34 = ( ( V_37 >> ( V_31 * 4 ) ) & 0xf ) + 1 ;
V_39 = 800000000ULL * V_32 ;
V_38 = 3 * V_33 * V_35 * V_34 ;
}
F_28 ( V_39 , V_38 ) ;
return ( unsigned int ) V_39 ;
}
static unsigned int F_29 ( int V_1 )
{
T_2 V_42 , V_43 , V_44 , V_45 ;
T_2 V_46 , V_47 , V_48 , V_49 , V_50 , V_51 ;
T_3 V_52 , V_4 , V_53 , V_54 ;
V_4 = F_2 ( V_1 ) -> V_4 ;
V_54 =
( F_27 ( V_4 , V_40 ) >> 18 ) & 0x3 ;
switch ( V_54 ) {
case 0 :
V_52 = 200000000ULL ;
V_50 = 3 ;
break;
case 1 :
V_52 = 100000000ULL ;
V_50 = 1 ;
break;
case 2 :
V_52 = 125000000ULL ;
V_50 = 1 ;
break;
case 3 :
V_52 = 400000000ULL ;
V_50 = 3 ;
break;
}
V_49 = ( F_27 ( V_4 , V_55 ) >> 22 ) & 0x3 ;
switch ( V_49 ) {
case 0 :
V_42 = F_27 ( V_4 , V_56 ) ;
V_43 = F_27 ( V_4 , V_57 ) ;
break;
case 1 :
V_42 = F_27 ( V_4 , F_30 ( 0 ) ) ;
V_43 = F_27 ( V_4 , F_31 ( 0 ) ) ;
break;
case 2 :
V_42 = F_27 ( V_4 , F_30 ( 1 ) ) ;
V_43 = F_27 ( V_4 , F_31 ( 1 ) ) ;
break;
case 3 :
V_42 = F_27 ( V_4 , F_30 ( 2 ) ) ;
V_43 = F_27 ( V_4 , F_31 ( 2 ) ) ;
break;
}
V_44 = ( V_42 >> 5 ) & 0x7 ;
V_45 = ( V_42 >> 24 ) & 0x7 ;
V_46 = V_43 & 0xff ;
V_47 = ( V_43 >> 8 ) & 0xfff ;
switch ( V_45 ) {
case 1 :
V_45 = 2 ;
break;
case 3 :
V_45 = 4 ;
break;
case 7 :
V_45 = 8 ;
break;
case 6 :
V_45 = 16 ;
break;
case 0 :
default:
V_45 = 1 ;
break;
}
V_47 = V_47 / ( 1 << 13 ) ;
V_53 = ( ( V_52 >> 1 ) * ( 6 + V_46 ) ) + V_47 ;
V_48 = ( 1 << V_44 ) * V_45 * 3 ;
if ( V_48 > 0 )
F_28 ( V_53 , V_48 ) ;
V_51 = ( F_27 ( V_4 , V_58 ) >> 22 ) & 0x3 ;
F_28 ( V_53 , 1 << V_51 ) ;
return V_53 ;
}
unsigned int F_32 ( int V_1 )
{
if ( F_11 () )
return F_29 ( V_1 ) ;
else
return 133333333 ;
}
unsigned int F_33 ( void )
{
return F_26 ( 0 , 0 ) ;
}
int F_34 ( int V_59 , T_1 * V_60 )
{
T_1 V_61 , V_62 , V_63 ;
T_4 V_64 ;
int V_65 , V_1 , V_66 ;
V_61 = F_35 ( 0 ) ;
V_66 = 0 ;
for ( V_65 = 0 ; V_65 < 8 ; V_65 ++ ) {
V_64 = F_36 ( V_61 ,
F_37 ( V_65 ) ) ;
V_1 = ( V_64 >> 1 ) & 0x3 ;
if ( V_59 >= 0 && V_59 != V_1 )
continue;
V_64 = F_36 ( V_61 , F_38 ( V_65 ) ) ;
V_64 = ( V_64 >> 12 ) & 0xfffff ;
V_62 = ( T_1 ) V_64 << 20 ;
V_64 = F_36 ( V_61 , F_39 ( V_65 ) ) ;
V_64 = ( V_64 >> 12 ) & 0xfffff ;
if ( V_64 == 0 )
continue;
V_63 = ( ( T_1 ) V_64 + 1 ) << 20 ;
V_60 [ V_66 ] = V_62 ;
V_60 [ V_66 + 1 ] = V_63 ;
V_66 += 2 ;
}
return V_66 ;
}
