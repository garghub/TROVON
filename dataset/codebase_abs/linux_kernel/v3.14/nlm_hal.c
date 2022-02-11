void F_1 ( int V_1 )
{
struct V_2 * V_3 ;
V_3 = F_2 ( V_1 ) ;
V_3 -> V_4 = F_3 ( V_1 ) ;
V_3 -> V_5 = F_4 ( V_1 ) ;
V_3 -> V_6 = F_5 () & ( ~ ( ( 1 << 12 ) - 1 ) ) ;
if ( F_6 () )
V_3 -> V_7 = F_7 ( V_1 ) ;
else
V_3 -> V_7 = 0 ;
F_8 ( & V_3 -> V_8 ) ;
}
int F_9 ( int V_9 )
{
T_1 V_10 ;
int V_11 , V_12 ;
if ( F_6 () ) {
switch ( V_9 ) {
case V_13 :
return 114 ;
case V_14 :
return 115 ;
case V_15 :
return 133 ;
case V_16 :
return 134 ;
case F_10 ( 0 ) :
case F_10 ( 1 ) :
case F_10 ( 2 ) :
case F_10 ( 3 ) :
return 191 + V_9 - V_17 ;
}
return - 1 ;
}
V_11 = 0 ;
switch ( V_9 ) {
case V_15 :
V_11 = F_11 ( 0 ) ;
break;
case V_16 :
V_11 = F_12 ( 0 ) ;
break;
case V_18 :
V_11 = F_13 ( 0 ) ;
break;
case V_19 :
case V_20 :
case V_21 :
case V_22 :
if ( F_14 () )
V_11 = F_15 ( 0 ) ;
else
V_11 = F_16 ( 0 ) ;
break;
default:
if ( F_14 () ) {
switch ( V_9 ) {
case V_23 :
V_11 = F_17 ( 0 ) ;
break;
case V_24 :
V_11 = F_18 ( 0 ) ;
break;
case V_25 :
V_11 = F_19 ( 0 ) ;
break;
}
} else {
switch ( V_9 ) {
case V_26 :
V_11 = F_20 ( 0 ) ;
break;
case V_27 :
V_11 = F_21 ( 0 ) ;
break;
case V_28 :
V_11 = F_22 ( 0 ) ;
break;
case V_29 :
V_11 = F_23 ( 0 ) ;
break;
case V_30 :
V_11 = F_24 ( 0 ) ;
break;
case V_31 :
V_11 = F_25 ( 0 ) ;
break;
}
}
}
if ( V_11 != 0 ) {
V_10 = F_26 ( V_11 ) ;
V_12 = F_27 ( V_10 , V_32 ) & 0xffff ;
switch ( V_9 ) {
case V_20 :
V_12 = V_12 + 1 ; break;
case V_21 :
V_12 = V_12 + 2 ; break;
case V_22 :
V_12 = V_12 + 3 ; break;
}
} else if ( V_9 >= F_10 ( 0 ) &&
V_9 <= F_10 ( 3 ) ) {
V_12 = F_28 ( V_9 -
V_17 ) ;
} else if ( V_9 >= F_29 ( 0 ) &&
V_9 <= F_29 ( 3 ) ) {
V_12 = - 2 ;
} else if ( V_9 >= F_30 ( 0 ) &&
V_9 <= F_30 ( 3 ) ) {
V_12 = - 2 ;
} else {
V_12 = - 1 ;
}
return V_12 ;
}
unsigned int F_31 ( int V_1 , int V_33 )
{
unsigned int V_34 , V_35 , V_36 , V_37 ;
unsigned int V_38 , V_39 , V_40 ;
T_1 V_41 , V_4 ;
V_4 = F_2 ( V_1 ) -> V_4 ;
if ( F_6 () )
V_38 = F_32 ( V_4 , V_42 ) ;
else
V_38 = F_32 ( V_4 , V_43 ) ;
if ( F_14 () ) {
V_41 = 1000000ULL * ( 400 * 3 + 100 * ( V_38 >> 26 ) ) ;
V_40 = 3 ;
} else {
V_39 = F_32 ( V_4 , V_44 ) ;
V_34 = ( ( V_38 >> 10 ) & 0x7f ) + 1 ;
V_35 = ( ( V_38 >> 8 ) & 0x3 ) + 1 ;
V_37 = ( ( V_38 >> 30 ) & 0x3 ) + 1 ;
V_36 = ( ( V_39 >> ( V_33 * 4 ) ) & 0xf ) + 1 ;
V_41 = 800000000ULL * V_34 ;
V_40 = 3 * V_35 * V_37 * V_36 ;
}
F_33 ( V_41 , V_40 ) ;
return ( unsigned int ) V_41 ;
}
static unsigned int F_34 ( int V_1 )
{
T_2 V_45 , V_46 , V_47 , V_48 ;
T_2 V_49 , V_50 , V_51 , V_52 , V_53 , V_54 ;
T_3 V_55 , V_4 , V_56 , V_57 ;
V_4 = F_2 ( V_1 ) -> V_4 ;
V_57 =
( F_32 ( V_4 , V_43 ) >> 18 ) & 0x3 ;
switch ( V_57 ) {
case 0 :
V_55 = 200000000ULL ;
V_53 = 3 ;
break;
case 1 :
V_55 = 100000000ULL ;
V_53 = 1 ;
break;
case 2 :
V_55 = 125000000ULL ;
V_53 = 1 ;
break;
case 3 :
V_55 = 400000000ULL ;
V_53 = 3 ;
break;
}
V_52 = ( F_32 ( V_4 , V_58 ) >> 22 ) & 0x3 ;
switch ( V_52 ) {
case 0 :
V_45 = F_32 ( V_4 , V_59 ) ;
V_46 = F_32 ( V_4 , V_60 ) ;
break;
case 1 :
V_45 = F_32 ( V_4 , F_35 ( 0 ) ) ;
V_46 = F_32 ( V_4 , F_36 ( 0 ) ) ;
break;
case 2 :
V_45 = F_32 ( V_4 , F_35 ( 1 ) ) ;
V_46 = F_32 ( V_4 , F_36 ( 1 ) ) ;
break;
case 3 :
V_45 = F_32 ( V_4 , F_35 ( 2 ) ) ;
V_46 = F_32 ( V_4 , F_36 ( 2 ) ) ;
break;
}
V_47 = ( V_45 >> 5 ) & 0x7 ;
V_48 = ( V_45 >> 24 ) & 0x7 ;
V_49 = V_46 & 0xff ;
V_50 = ( V_46 >> 8 ) & 0xfff ;
switch ( V_48 ) {
case 1 :
V_48 = 2 ;
break;
case 3 :
V_48 = 4 ;
break;
case 7 :
V_48 = 8 ;
break;
case 6 :
V_48 = 16 ;
break;
case 0 :
default:
V_48 = 1 ;
break;
}
V_50 = V_50 / ( 1 << 13 ) ;
V_56 = ( ( V_55 >> 1 ) * ( 6 + V_49 ) ) + V_50 ;
V_51 = ( 1 << V_47 ) * V_48 * 3 ;
if ( V_51 > 0 )
F_33 ( V_56 , V_51 ) ;
V_54 = ( F_32 ( V_4 , V_61 ) >> 22 ) & 0x3 ;
F_33 ( V_56 , 1 << V_54 ) ;
return V_56 ;
}
unsigned int F_37 ( int V_1 )
{
if ( F_6 () )
return 250000000 ;
if ( F_14 () )
return F_34 ( V_1 ) ;
else
return 133333333 ;
}
unsigned int F_38 ( void )
{
return F_31 ( 0 , 0 ) ;
}
int F_39 ( int V_62 , T_1 * V_63 )
{
T_1 V_64 , V_65 , V_66 ;
T_4 V_67 ;
unsigned int V_68 , V_69 , V_70 ;
int V_71 , V_1 , V_72 ;
V_64 = F_40 ( 0 ) ;
V_72 = 0 ;
for ( V_71 = 0 ; V_71 < 8 ; V_71 ++ ) {
if ( F_6 () ) {
V_68 = F_41 ( V_71 ) ;
V_69 = F_42 ( V_71 ) ;
V_70 = F_43 ( V_71 ) ;
} else {
V_68 = F_44 ( V_71 ) ;
V_69 = F_45 ( V_71 ) ;
V_70 = F_46 ( V_71 ) ;
}
if ( V_62 >= 0 ) {
V_67 = F_47 ( V_64 , V_70 ) ;
V_1 = ( V_67 >> 1 ) & 0x3 ;
if ( V_62 != V_1 )
continue;
}
V_67 = F_47 ( V_64 , V_68 ) ;
V_67 = ( V_67 >> 12 ) & 0xfffff ;
V_65 = ( T_1 ) V_67 << 20 ;
V_67 = F_47 ( V_64 , V_69 ) ;
V_67 = ( V_67 >> 12 ) & 0xfffff ;
if ( V_67 == 0 )
continue;
V_66 = ( ( T_1 ) V_67 + 1 ) << 20 ;
V_63 [ V_72 ] = V_65 ;
V_63 [ V_72 + 1 ] = V_66 ;
V_72 += 2 ;
}
return V_72 ;
}
