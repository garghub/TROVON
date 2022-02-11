static long F_1 ( int V_1 , enum V_2 V_3 )
{
T_1 V_4 ;
T_2 V_5 ;
long V_6 ;
V_4 = ( ( T_1 ) V_1 ) >> 11 ;
V_5 = ( ( T_1 ) ( ( V_1 & 0x7ff ) << 5 ) ) >> 5 ;
V_6 = V_5 * 1000L ;
if ( V_3 == V_7 )
V_6 = V_6 * 1000L ;
if ( V_4 >= 0 )
V_6 <<= V_4 ;
else
V_6 >>= - V_4 ;
return V_6 ;
}
static T_3 F_2 ( long V_6 , enum V_2 V_3 )
{
T_1 V_4 = 0 , V_5 ;
bool V_8 = false ;
if ( V_6 == 0 )
return 0 ;
if ( V_6 < 0 ) {
V_8 = true ;
V_6 = - V_6 ;
}
if ( V_3 == V_7 )
V_6 = F_3 ( V_6 , 1000L ) ;
while ( V_6 >= V_9 && V_4 < 15 ) {
V_4 ++ ;
V_6 >>= 1 ;
}
while ( V_6 < V_10 && V_4 > - 15 ) {
V_4 -- ;
V_6 <<= 1 ;
}
V_5 = F_3 ( V_6 , 1000 ) ;
if ( V_5 > 0x3ff )
V_5 = 0x3ff ;
if ( V_8 )
V_5 = - V_5 ;
return ( V_5 & 0x7ff ) | ( ( V_4 << 11 ) & 0xf800 ) ;
}
static T_3 F_4 ( T_1 V_1 , int V_11 ,
enum V_2 V_3 )
{
long V_6 ;
V_6 = F_1 ( V_1 , V_3 ) ;
if ( V_11 < 0 )
V_6 >>= - V_11 ;
else
V_6 <<= V_11 ;
return F_2 ( V_6 , V_3 ) ;
}
static int F_5 ( struct V_12 * V_13 , int V_14 , int V_15 )
{
int V_16 ;
switch ( V_15 ) {
case V_17 :
case V_18 :
V_16 = F_6 ( V_13 , V_14 , V_15 ) ;
if ( V_16 < 0 )
break;
V_16 = F_4 ( V_16 , 1 , V_19 ) ;
break;
case V_20 :
case V_21 :
case V_22 :
V_16 = F_6 ( V_13 , V_14 , V_15 ) ;
V_16 = F_4 ( V_16 , - 4 , V_23 ) ;
break;
case V_24 :
V_16 = F_6 ( V_13 , V_14 , V_15 ) ;
if ( V_16 < 0 )
break;
V_16 = F_4 ( V_16 , - 1 , V_25 ) ;
break;
case V_26 :
V_16 = F_6 ( V_13 , V_14 , V_26 ) ;
if ( V_16 < 0 )
break;
V_16 = F_4 ( V_16 , - 5 , V_23 ) ;
break;
case V_27 :
V_16 = F_6 ( V_13 , V_14 , V_27 ) ;
if ( V_16 < 0 )
break;
if ( V_14 == 0 )
V_16 = F_4 ( V_16 , - 4 , V_25 ) ;
else
V_16 = F_4 ( V_16 , - 5 , V_25 ) ;
break;
case V_28 :
V_16 = F_6 ( V_13 , V_14 , V_28 ) ;
if ( V_16 < 0 )
break;
V_16 = F_4 ( V_16 , - 1 , V_7 ) ;
break;
case V_29 :
V_16 = F_6 ( V_13 , V_14 , V_29 ) ;
if ( V_16 < 0 )
break;
V_16 = F_4 ( V_16 , - 1 , V_7 ) ;
break;
case V_30 :
V_16 = F_6 ( V_13 , V_14 , V_30 ) ;
if ( V_16 < 0 )
break;
if ( V_14 == 0 )
V_16 = F_4 ( V_16 , - 1 , V_19 ) ;
else
V_16 = F_4 ( V_16 , - 2 , V_19 ) ;
break;
case V_31 :
V_16 = F_6 ( V_13 , V_14 , V_32 ) ;
if ( V_16 < 0 )
break;
V_16 = F_4 ( V_16 , - 5 , V_23 ) ;
break;
case V_33 :
V_16 = F_6 ( V_13 , V_14 , V_34 ) ;
break;
case V_35 :
V_16 = F_6 ( V_13 , V_14 , V_36 ) ;
if ( V_16 < 0 )
break;
if ( V_14 == 0 )
V_16 = F_4 ( V_16 , - 1 , V_25 ) ;
else
V_16 = F_4 ( V_16 , - 2 , V_25 ) ;
break;
case V_37 :
V_16 = F_6 ( V_13 , V_14 , V_38 ) ;
break;
case V_39 :
V_16 = F_6 ( V_13 , V_14 ,
V_40 ) ;
if ( V_16 < 0 )
break;
V_16 = F_4 ( V_16 , - 5 , V_23 ) ;
break;
case V_41 :
V_16 = F_6 ( V_13 , V_14 ,
V_42 ) ;
break;
case V_43 :
V_16 = F_6 ( V_13 , V_14 ,
V_44 ) ;
if ( V_16 < 0 )
break;
if ( V_14 == 0 )
V_16 = F_4 ( V_16 , - 1 , V_25 ) ;
else
V_16 = F_4 ( V_16 , - 2 , V_25 ) ;
break;
case V_45 :
V_16 = F_6 ( V_13 , V_14 ,
V_46 ) ;
break;
default:
V_16 = - V_47 ;
break;
}
return V_16 ;
}
static int F_7 ( struct V_12 * V_13 , int V_14 , int V_15 ,
T_3 V_48 )
{
int V_16 ;
T_3 V_6 ;
switch ( V_15 ) {
case V_17 :
case V_18 :
V_6 = F_4 ( V_48 , - 1 , V_19 ) ;
V_16 = F_8 ( V_13 , V_14 , V_15 , V_6 ) ;
break;
case V_20 :
case V_21 :
case V_22 :
V_6 = F_4 ( V_48 , 4 , V_23 ) ;
V_16 = F_8 ( V_13 , V_14 , V_15 , V_6 ) ;
break;
case V_24 :
V_6 = F_4 ( V_48 , 1 , V_25 ) ;
V_16 = F_8 ( V_13 , V_14 , V_15 , V_6 ) ;
break;
default:
V_16 = - V_47 ;
break;
}
return V_16 ;
}
static int F_9 ( struct V_12 * V_13 ,
const struct V_49 * V_50 )
{
struct V_51 * V_52 ;
T_4 V_53 [ V_54 ] ;
int V_16 ;
if ( ! F_10 ( V_13 -> V_55 ,
V_56
| V_57
| V_58 ) )
return - V_59 ;
V_16 = F_11 ( V_13 , V_60 , V_53 ) ;
if ( V_16 < 0 ) {
F_12 ( & V_13 -> V_61 , L_1 ) ;
return V_16 ;
}
if ( V_16 != 2 || strncmp ( V_53 , L_2 , strlen ( L_2 ) ) ) {
F_12 ( & V_13 -> V_61 , L_3 ) ;
return - V_59 ;
}
V_16 = F_11 ( V_13 , V_62 , V_53 ) ;
if ( V_16 < 0 ) {
F_12 ( & V_13 -> V_61 , L_4 ) ;
return V_16 ;
}
if ( V_16 != 2 || ! ( V_53 [ 0 ] == 0x6c && V_53 [ 1 ] == 0x00 ) ) {
F_12 ( & V_13 -> V_61 , L_5 ) ;
return - V_59 ;
}
V_52 = F_13 ( & V_13 -> V_61 , sizeof( struct V_51 ) ,
V_63 ) ;
if ( ! V_52 )
return - V_64 ;
V_52 -> V_65 = F_7 ;
V_52 -> V_66 = F_5 ;
V_52 -> V_67 = 2 ;
V_52 -> V_68 [ V_23 ] = V_69 ;
V_52 -> V_68 [ V_70 ] = V_69 ;
V_52 -> V_68 [ V_25 ] = V_69 ;
V_52 -> V_68 [ V_19 ] = V_69 ;
V_52 -> V_68 [ V_7 ] = V_69 ;
V_52 -> V_68 [ V_71 ] = V_69 ;
V_52 -> V_72 [ 0 ] = V_73
| V_74 | V_75
| V_76 | V_77
| V_78 | V_79
| V_80 | V_81
| V_82 | V_83 ;
V_52 -> V_72 [ 1 ] = V_52 -> V_72 [ 0 ] ;
return F_14 ( V_13 , V_50 , V_52 ) ;
}
