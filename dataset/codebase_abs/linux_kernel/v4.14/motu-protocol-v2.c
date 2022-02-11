static int F_1 ( struct V_1 * V_2 , unsigned int * V_3 )
{
T_1 V_4 ;
unsigned int V_5 ;
int V_6 ;
V_6 = F_2 ( V_2 , V_7 , & V_4 ,
sizeof( V_4 ) ) ;
if ( V_6 < 0 )
return V_6 ;
V_5 = ( F_3 ( V_4 ) & V_8 ) >> V_9 ;
if ( V_5 >= F_4 ( V_10 ) )
return - V_11 ;
* V_3 = V_10 [ V_5 ] ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 , unsigned int V_3 )
{
T_1 V_4 ;
T_2 V_12 ;
int V_13 ;
int V_6 ;
for ( V_13 = 0 ; V_13 < F_4 ( V_10 ) ; ++ V_13 ) {
if ( V_10 [ V_13 ] == V_3 )
break;
}
if ( V_13 == F_4 ( V_10 ) )
return - V_14 ;
V_6 = F_2 ( V_2 , V_7 , & V_4 ,
sizeof( V_4 ) ) ;
if ( V_6 < 0 )
return V_6 ;
V_12 = F_3 ( V_4 ) ;
V_12 &= ~ V_8 ;
V_12 |= V_13 << V_9 ;
V_4 = F_6 ( V_12 ) ;
return F_7 ( V_2 , V_7 , & V_4 ,
sizeof( V_4 ) ) ;
}
static int F_8 ( struct V_1 * V_2 ,
enum V_15 * V_16 )
{
T_1 V_4 ;
unsigned int V_5 ;
int V_6 ;
V_6 = F_2 ( V_2 , V_7 , & V_4 ,
sizeof( V_4 ) ) ;
if ( V_6 < 0 )
return V_6 ;
V_5 = F_3 ( V_4 ) & V_17 ;
if ( V_5 > 5 )
return - V_11 ;
V_6 = F_2 ( V_2 , V_18 , & V_4 ,
sizeof( V_4 ) ) ;
if ( V_6 < 0 )
return V_6 ;
switch ( V_5 ) {
case 0 :
* V_16 = V_19 ;
break;
case 1 :
if ( F_3 ( V_4 ) & 0x00000200 )
* V_16 = V_20 ;
else
* V_16 = V_21 ;
break;
case 2 :
* V_16 = V_22 ;
break;
case 4 :
* V_16 = V_23 ;
break;
case 5 :
* V_16 = V_24 ;
break;
default:
return - V_11 ;
}
return 0 ;
}
static int F_9 ( struct V_1 * V_2 , bool V_25 )
{
return 0 ;
}
static void F_10 ( struct V_26 * V_27 ,
enum V_28 V_29 ,
enum V_30 V_31 ,
unsigned char V_32 )
{
unsigned char V_33 [ 3 ] = { 0 , 0 , 0 } ;
V_27 -> V_34 = 2 ;
V_33 [ 0 ] = V_32 ;
V_33 [ 1 ] = V_32 ;
if ( V_31 & V_35 )
V_33 [ 2 ] = V_32 ;
if ( V_29 == V_36 ) {
if ( V_31 & V_37 ) {
V_33 [ 0 ] += 2 ;
V_33 [ 1 ] += 2 ;
}
if ( V_31 & V_38 ) {
V_33 [ 0 ] += 2 ;
V_33 [ 1 ] += 2 ;
}
} else {
V_33 [ 0 ] += 4 ;
V_33 [ 1 ] += 4 ;
}
V_33 [ 0 ] += 2 ;
V_33 [ 1 ] += 2 ;
V_27 -> V_39 [ 0 ] = F_11 ( 2 + V_33 [ 0 ] , 4 ) - 2 ;
V_27 -> V_39 [ 1 ] = F_11 ( 2 + V_33 [ 1 ] , 4 ) - 2 ;
if ( V_31 & V_35 )
V_27 -> V_39 [ 2 ] =
F_11 ( 2 + V_33 [ 2 ] , 4 ) - 2 ;
}
static void F_12 ( struct V_26 * V_27 ,
enum V_30 V_31 ,
T_2 V_12 , T_2 V_40 , T_2 V_41 )
{
unsigned char V_33 [ 3 ] = { 0 , 0 } ;
V_12 = ( V_12 & V_40 ) >> V_41 ;
if ( ( V_31 & V_42 ) &&
V_12 == V_43 ) {
V_33 [ 0 ] += 8 ;
V_33 [ 1 ] += 4 ;
}
V_27 -> V_44 [ 0 ] = V_33 [ 0 ] ;
V_27 -> V_44 [ 1 ] = V_33 [ 1 ] ;
}
static int F_13 ( struct V_1 * V_2 )
{
T_1 V_4 ;
T_2 V_12 ;
int V_6 ;
V_6 = F_2 ( V_2 , V_18 , & V_4 ,
sizeof( V_4 ) ) ;
if ( V_6 < 0 )
return V_6 ;
V_12 = F_3 ( V_4 ) ;
F_10 ( & V_2 -> V_45 , V_36 ,
V_2 -> V_46 -> V_31 , V_2 -> V_46 -> V_47 ) ;
F_12 ( & V_2 -> V_45 , V_2 -> V_46 -> V_31 ,
V_12 , V_48 , V_49 ) ;
F_10 ( & V_2 -> V_50 , V_51 ,
V_2 -> V_46 -> V_31 , V_2 -> V_46 -> V_52 ) ;
F_12 ( & V_2 -> V_50 , V_2 -> V_46 -> V_31 ,
V_12 , V_53 , V_54 ) ;
V_2 -> V_45 . V_55 = 10 ;
V_2 -> V_50 . V_55 = 10 ;
return 0 ;
}
