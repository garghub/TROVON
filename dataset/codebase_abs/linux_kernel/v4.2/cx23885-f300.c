static void F_1 ( struct V_1 * V_2 , T_1 line , T_2 V_3 )
{
F_2 ( V_2 , line , 1 ) ;
if ( V_3 == 1 )
F_3 ( V_2 , line ) ;
else
F_4 ( V_2 , line ) ;
}
static T_2 F_5 ( struct V_1 * V_2 , T_1 line )
{
F_2 ( V_2 , line , 0 ) ;
return F_6 ( V_2 , line ) ;
}
static void F_7 ( struct V_1 * V_2 , T_2 V_4 )
{
T_2 V_5 ;
for ( V_5 = 0 ; V_5 < 8 ; V_5 ++ ) {
F_1 ( V_2 , V_6 , 0 ) ;
F_8 ( 30 ) ;
F_1 ( V_2 , V_7 , ( V_4 & 0x80 ) >> 7 ) ;
F_8 ( 30 ) ;
V_4 <<= 1 ;
F_1 ( V_2 , V_6 , 1 ) ;
F_8 ( 30 ) ;
}
}
static T_2 F_9 ( struct V_1 * V_2 )
{
T_2 V_5 , V_4 = 0 ;
for ( V_5 = 0 ; V_5 < 8 ; V_5 ++ ) {
F_1 ( V_2 , V_6 , 0 ) ;
F_8 ( 30 ) ;
V_4 <<= 1 ;
F_1 ( V_2 , V_6 , 1 ) ;
F_8 ( 30 ) ;
V_4 |= F_5 ( V_2 , V_7 ) ;
}
return V_4 ;
}
static T_2 F_10 ( struct V_8 * V_9 , T_2 * V_10 )
{
struct V_11 * V_12 = V_9 -> V_13 -> V_14 ;
struct V_1 * V_2 = V_12 -> V_2 ;
T_2 V_5 , V_15 , V_16 = 0 ;
V_15 = V_10 [ 0 ] ;
for ( V_5 = 0 ; V_5 < V_10 [ 0 ] ; V_5 ++ )
V_15 += V_10 [ V_5 + 1 ] ;
V_15 = ( ~ V_15 + 1 ) ;
V_10 [ 1 + V_10 [ 0 ] ] = V_15 ;
F_1 ( V_2 , V_17 , 1 ) ;
F_1 ( V_2 , V_6 , 1 ) ;
F_8 ( 30 ) ;
F_1 ( V_2 , V_7 , 1 ) ;
F_11 ( 1 ) ;
F_1 ( V_2 , V_17 , 0 ) ;
F_11 ( 1 ) ;
F_7 ( V_2 , 0xe0 ) ;
F_11 ( 1 ) ;
V_15 = V_10 [ 0 ] ;
V_15 += 2 ;
for ( V_5 = 0 ; V_5 < V_15 ; V_5 ++ )
F_7 ( V_2 , V_10 [ V_5 ] ) ;
F_1 ( V_2 , V_17 , 1 ) ;
F_1 ( V_2 , V_7 , 1 ) ;
V_15 = 0 ;
for ( V_5 = 0 ; ( ( V_5 < 8 ) & ( V_15 == 0 ) ) ; V_5 ++ ) {
F_11 ( 1 ) ;
if ( F_5 ( V_2 , V_18 ) == 0 )
V_15 = 1 ;
}
if ( V_5 > 7 ) {
F_12 ( V_19 L_1 ,
V_20 ) ;
V_16 = 1 ;
} else {
F_1 ( V_2 , V_17 , 0 ) ;
F_11 ( 1 ) ;
F_7 ( V_2 , 0xe1 ) ;
F_11 ( 1 ) ;
V_15 = F_9 ( V_2 ) ;
if ( V_15 > 14 )
V_15 = 14 ;
for ( V_5 = 0 ; V_5 < ( V_15 + 1 ) ; V_5 ++ )
F_9 ( V_2 ) ;
F_1 ( V_2 , V_17 , 1 ) ;
F_1 ( V_2 , V_7 , 1 ) ;
}
return V_16 ;
}
int F_13 ( struct V_8 * V_9 , enum V_21 V_22 )
{
T_2 V_10 [ 16 ] ;
V_10 [ 0 ] = 0x05 ;
V_10 [ 1 ] = 0x38 ;
V_10 [ 2 ] = 0x01 ;
switch ( V_22 ) {
case V_23 :
V_10 [ 3 ] = 0x01 ;
V_10 [ 4 ] = 0x02 ;
V_10 [ 5 ] = 0x00 ;
break;
case V_24 :
V_10 [ 3 ] = 0x01 ;
V_10 [ 4 ] = 0x02 ;
V_10 [ 5 ] = 0x01 ;
break;
case V_25 :
V_10 [ 3 ] = 0x00 ;
V_10 [ 4 ] = 0x00 ;
V_10 [ 5 ] = 0x00 ;
break;
}
return F_10 ( V_9 , V_10 ) ;
}
