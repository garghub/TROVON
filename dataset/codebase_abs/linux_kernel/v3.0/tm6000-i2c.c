static int F_1 ( struct V_1 * V_2 , unsigned char V_3 ,
T_1 V_4 , char * V_5 , int V_6 )
{
int V_7 ;
unsigned int V_8 ;
unsigned int V_9 = 16 ;
if ( V_2 -> V_10 == V_11 )
V_9 = 64 ;
if ( ! V_5 )
return - 1 ;
if ( V_6 < 1 || V_6 > V_9 ) {
F_2 ( V_12 L_1 ,
V_6 , V_9 ) ;
return - 1 ;
}
V_7 = F_3 ( V_2 , V_13 | V_14 |
V_15 , V_16 ,
V_3 | V_4 << 8 , 0 , V_5 , V_6 ) ;
if ( V_7 < 0 ) {
return V_7 ;
}
V_8 = ( ( V_6 * 200 ) + 200 + 1000 ) / 1000 ;
F_4 ( V_8 ) ;
return V_7 ;
}
static int F_5 ( struct V_1 * V_2 , unsigned char V_3 ,
T_1 V_4 , char * V_5 , int V_6 )
{
int V_7 ;
T_2 V_17 [ 2 ] ;
unsigned int V_9 = 16 ;
if ( V_2 -> V_10 == V_11 )
V_9 = 64 ;
if ( ! V_5 )
return - 1 ;
if ( V_6 < 1 || V_6 > V_9 ) {
F_2 ( V_12 L_1 ,
V_6 , V_9 ) ;
return - 1 ;
}
if ( ( V_2 -> V_18 . V_19 ) && ( V_2 -> V_20 << 1 == V_3 ) && ( V_4 % 2 == 0 ) ) {
V_4 -= 1 ;
V_6 += 1 ;
V_7 = F_3 ( V_2 , V_21 | V_14 | V_15 ,
V_16 , V_3 | V_4 << 8 , 0 , V_17 , V_6 ) ;
* V_5 = V_17 [ 1 ] ;
} else {
V_7 = F_3 ( V_2 , V_21 | V_14 | V_15 ,
V_16 , V_3 | V_4 << 8 , 0 , V_5 , V_6 ) ;
}
return V_7 ;
}
static int F_6 ( struct V_1 * V_2 , unsigned char V_3 ,
T_3 V_4 , char * V_5 , int V_6 )
{
int V_7 ;
unsigned char V_22 ;
if ( ! V_5 || V_6 != 2 )
return - 1 ;
if ( V_2 -> V_10 == V_11 ) {
V_22 = V_4 & 0xFF ;
V_7 = F_3 ( V_2 , V_13 | V_14 |
V_15 , V_16 ,
V_3 | ( V_4 & 0xFF00 ) , 0 , & V_22 , 1 ) ;
if ( V_7 < 0 ) {
return V_7 ;
}
F_4 ( 1400 / 1000 ) ;
V_7 = F_3 ( V_2 , V_21 | V_14 |
V_15 , V_23 ,
V_4 , 0 , V_5 , V_6 ) ;
} else {
V_7 = F_3 ( V_2 , V_21 | V_14 |
V_15 , V_24 ,
V_3 , V_4 , V_5 , V_6 ) ;
}
return V_7 ;
}
static int F_7 ( struct V_25 * V_26 ,
struct V_27 V_28 [] , int V_29 )
{
struct V_1 * V_2 = V_26 -> V_30 ;
int V_3 , V_7 , V_31 , V_32 ;
if ( V_29 <= 0 )
return 0 ;
for ( V_31 = 0 ; V_31 < V_29 ; V_31 ++ ) {
V_3 = ( V_28 [ V_31 ] . V_3 << 1 ) & 0xff ;
F_8 ( 2 , L_2 ,
( V_28 [ V_31 ] . V_33 & V_34 ) ? L_3 : L_4 ,
V_31 == V_29 - 1 ? L_5 : L_6 , V_3 , V_28 [ V_31 ] . V_6 ) ;
if ( V_28 [ V_31 ] . V_33 & V_34 ) {
F_8 ( 2 , L_7
L_8 ) ;
V_7 = - V_35 ;
goto V_36;
} else if ( V_31 + 1 < V_29 && V_28 [ V_31 ] . V_6 <= 2 &&
( V_28 [ V_31 + 1 ] . V_33 & V_34 ) &&
V_28 [ V_31 ] . V_3 == V_28 [ V_31 + 1 ] . V_3 ) {
if ( V_37 >= 2 )
for ( V_32 = 0 ; V_32 < V_28 [ V_31 ] . V_6 ; V_32 ++ )
F_2 ( L_9 , V_28 [ V_31 ] . V_5 [ V_32 ] ) ;
F_8 ( 2 , L_10 ,
V_31 == V_29 - 2 ? L_5 : L_6 ,
V_28 [ V_31 + 1 ] . V_6 ) ;
if ( V_28 [ V_31 ] . V_6 == 2 ) {
V_7 = F_6 ( V_2 , V_3 ,
V_28 [ V_31 ] . V_5 [ 0 ] << 8 | V_28 [ V_31 ] . V_5 [ 1 ] ,
V_28 [ V_31 + 1 ] . V_5 , V_28 [ V_31 + 1 ] . V_6 ) ;
} else {
V_7 = F_5 ( V_2 , V_3 , V_28 [ V_31 ] . V_5 [ 0 ] ,
V_28 [ V_31 + 1 ] . V_5 , V_28 [ V_31 + 1 ] . V_6 ) ;
}
V_31 ++ ;
if ( V_3 == V_2 -> V_38 << 1 ) {
F_9 ( V_2 , V_39 , 0 , 0 ) ;
F_9 ( V_2 , V_40 , 0 , 0 ) ;
}
if ( V_37 >= 2 )
for ( V_32 = 0 ; V_32 < V_28 [ V_31 ] . V_6 ; V_32 ++ )
F_2 ( L_9 , V_28 [ V_31 ] . V_5 [ V_32 ] ) ;
} else {
if ( V_37 >= 2 )
for ( V_32 = 0 ; V_32 < V_28 [ V_31 ] . V_6 ; V_32 ++ )
F_2 ( L_9 , V_28 [ V_31 ] . V_5 [ V_32 ] ) ;
V_7 = F_1 ( V_2 , V_3 , V_28 [ V_31 ] . V_5 [ 0 ] ,
V_28 [ V_31 ] . V_5 + 1 , V_28 [ V_31 ] . V_6 - 1 ) ;
if ( V_3 == V_2 -> V_38 << 1 ) {
F_9 ( V_2 , V_39 , 0 , 0 ) ;
F_9 ( V_2 , V_40 , 0 , 0 ) ;
}
}
if ( V_37 >= 2 )
F_2 ( L_11 ) ;
if ( V_7 < 0 )
goto V_36;
}
return V_29 ;
V_36:
F_8 ( 2 , L_12 , V_7 ) ;
return V_7 ;
}
static int F_10 ( struct V_1 * V_2 )
{
int V_31 , V_7 ;
unsigned char * V_41 = V_2 -> V_42 ;
unsigned char V_43 [ 17 ] ;
V_2 -> V_44 . V_3 = 0xa0 >> 1 ;
V_2 -> V_45 = 0 ;
V_43 [ 16 ] = '\0' ;
for ( V_31 = 0 ; V_31 < sizeof( V_2 -> V_42 ) ; ) {
* V_41 = V_31 ;
V_7 = F_5 ( V_2 , 0xa0 , V_31 , V_41 , 1 ) ;
if ( V_7 < 1 ) {
if ( V_41 == V_2 -> V_42 )
goto V_46;
else {
F_2 ( V_47
L_13 ,
V_2 -> V_48 , V_7 ) ;
}
return - V_49 ;
}
V_2 -> V_45 ++ ;
V_41 ++ ;
if ( 0 == ( V_31 % 16 ) )
F_2 ( V_50 L_14 , V_2 -> V_48 , V_31 ) ;
F_2 ( L_9 , V_2 -> V_42 [ V_31 ] ) ;
if ( ( V_2 -> V_42 [ V_31 ] >= ' ' ) && ( V_2 -> V_42 [ V_31 ] <= 'z' ) )
V_43 [ V_31 % 16 ] = V_2 -> V_42 [ V_31 ] ;
else
V_43 [ V_31 % 16 ] = '.' ;
V_31 ++ ;
if ( 0 == ( V_31 % 16 ) ) {
V_43 [ 16 ] = '\0' ;
F_2 ( L_15 , V_43 ) ;
}
}
if ( 0 != ( V_31 % 16 ) ) {
V_43 [ V_31 % 16 ] = '\0' ;
for ( V_31 %= 16 ; V_31 < 16 ; V_31 ++ )
F_2 ( L_16 ) ;
F_2 ( L_15 , V_43 ) ;
}
return 0 ;
V_46:
F_2 ( V_50 L_17 ,
V_2 -> V_48 , V_7 ) ;
return - V_49 ;
}
static T_4 F_11 ( struct V_25 * V_51 )
{
return V_52 ;
}
int F_12 ( struct V_1 * V_2 )
{
int V_7 ;
V_2 -> V_26 . V_53 = V_54 ;
V_2 -> V_26 . V_55 = & V_56 ;
V_2 -> V_26 . V_2 . V_57 = & V_2 -> V_58 -> V_2 ;
F_13 ( V_2 -> V_26 . V_48 , V_2 -> V_48 , sizeof( V_2 -> V_26 . V_48 ) ) ;
V_2 -> V_26 . V_30 = V_2 ;
F_14 ( & V_2 -> V_26 , & V_2 -> V_59 ) ;
V_7 = F_15 ( & V_2 -> V_26 ) ;
if ( V_7 )
return V_7 ;
V_2 -> V_44 . V_60 = & V_2 -> V_26 ;
F_13 ( V_2 -> V_44 . V_48 , L_18 , V_61 ) ;
F_10 ( V_2 ) ;
return 0 ;
}
int F_16 ( struct V_1 * V_2 )
{
F_17 ( & V_2 -> V_26 ) ;
return 0 ;
}
