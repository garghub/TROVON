static int F_1 ( struct V_1 * V_2 , unsigned char V_3 ,
T_1 V_4 , char * V_5 , int V_6 )
{
int V_7 ;
unsigned int V_8 = 16 ;
if ( V_2 -> V_9 == V_10 )
V_8 = 80 ;
if ( ! V_5 )
return - 1 ;
if ( V_6 < 1 || V_6 > V_8 ) {
F_2 ( V_11 L_1 ,
V_6 , V_8 ) ;
return - 1 ;
}
V_7 = F_3 ( V_2 , V_12 | V_13 |
V_14 , V_15 ,
V_3 | V_4 << 8 , 0 , V_5 , V_6 ) ;
if ( V_7 < 0 ) {
return V_7 ;
}
return V_7 ;
}
static int F_4 ( struct V_1 * V_2 , unsigned char V_3 ,
T_1 V_4 , char * V_5 , int V_6 )
{
int V_7 ;
T_2 V_16 [ 2 ] ;
unsigned int V_8 = 16 ;
if ( V_2 -> V_9 == V_10 )
V_8 = 64 ;
if ( ! V_5 )
return - 1 ;
if ( V_6 < 1 || V_6 > V_8 ) {
F_2 ( V_11 L_1 ,
V_6 , V_8 ) ;
return - 1 ;
}
if ( ( V_2 -> V_17 . V_18 ) && ( V_2 -> V_19 << 1 == V_3 ) && ( V_4 % 2 == 0 ) ) {
V_4 -= 1 ;
V_6 += 1 ;
V_7 = F_3 ( V_2 , V_20 | V_13 | V_14 ,
V_15 , V_3 | V_4 << 8 , 0 , V_16 , V_6 ) ;
* V_5 = V_16 [ 1 ] ;
} else {
V_7 = F_3 ( V_2 , V_20 | V_13 | V_14 ,
V_15 , V_3 | V_4 << 8 , 0 , V_5 , V_6 ) ;
}
return V_7 ;
}
static int F_5 ( struct V_1 * V_2 , unsigned char V_3 ,
T_3 V_4 , char * V_5 , int V_6 )
{
int V_7 ;
unsigned char V_21 ;
if ( ! V_5 || V_6 != 2 )
return - 1 ;
if ( V_2 -> V_9 == V_10 ) {
V_21 = V_4 & 0xFF ;
V_7 = F_3 ( V_2 , V_12 | V_13 |
V_14 , V_15 ,
V_3 | ( V_4 & 0xFF00 ) , 0 , & V_21 , 1 ) ;
if ( V_7 < 0 ) {
return V_7 ;
}
V_7 = F_3 ( V_2 , V_20 | V_13 |
V_14 , V_22 ,
V_4 , 0 , V_5 , V_6 ) ;
} else {
V_7 = F_3 ( V_2 , V_20 | V_13 |
V_14 , V_23 ,
V_3 , V_4 , V_5 , V_6 ) ;
}
return V_7 ;
}
static int F_6 ( struct V_24 * V_25 ,
struct V_26 V_27 [] , int V_28 )
{
struct V_1 * V_2 = V_25 -> V_29 ;
int V_3 , V_7 , V_30 , V_31 ;
if ( V_28 <= 0 )
return 0 ;
for ( V_30 = 0 ; V_30 < V_28 ; V_30 ++ ) {
V_3 = ( V_27 [ V_30 ] . V_3 << 1 ) & 0xff ;
F_7 ( 2 , L_2 ,
( V_27 [ V_30 ] . V_32 & V_33 ) ? L_3 : L_4 ,
V_30 == V_28 - 1 ? L_5 : L_6 , V_3 , V_27 [ V_30 ] . V_6 ) ;
if ( V_27 [ V_30 ] . V_32 & V_33 ) {
F_7 ( 2 , L_7
L_8 ) ;
V_7 = - V_34 ;
goto V_35;
} else if ( V_30 + 1 < V_28 && V_27 [ V_30 ] . V_6 <= 2 &&
( V_27 [ V_30 + 1 ] . V_32 & V_33 ) &&
V_27 [ V_30 ] . V_3 == V_27 [ V_30 + 1 ] . V_3 ) {
if ( V_36 >= 2 )
for ( V_31 = 0 ; V_31 < V_27 [ V_30 ] . V_6 ; V_31 ++ )
F_2 ( V_37 L_9 , V_27 [ V_30 ] . V_5 [ V_31 ] ) ;
F_7 ( 2 , L_10 ,
V_30 == V_28 - 2 ? L_5 : L_6 ,
V_27 [ V_30 + 1 ] . V_6 ) ;
if ( V_27 [ V_30 ] . V_6 == 2 ) {
V_7 = F_5 ( V_2 , V_3 ,
V_27 [ V_30 ] . V_5 [ 0 ] << 8 | V_27 [ V_30 ] . V_5 [ 1 ] ,
V_27 [ V_30 + 1 ] . V_5 , V_27 [ V_30 + 1 ] . V_6 ) ;
} else {
V_7 = F_4 ( V_2 , V_3 , V_27 [ V_30 ] . V_5 [ 0 ] ,
V_27 [ V_30 + 1 ] . V_5 , V_27 [ V_30 + 1 ] . V_6 ) ;
}
V_30 ++ ;
if ( V_3 == V_2 -> V_38 << 1 ) {
F_8 ( V_2 , V_39 , 0 , 0 ) ;
F_8 ( V_2 , V_40 , 0 , 0 ) ;
}
if ( V_36 >= 2 )
for ( V_31 = 0 ; V_31 < V_27 [ V_30 ] . V_6 ; V_31 ++ )
F_2 ( V_37 L_9 , V_27 [ V_30 ] . V_5 [ V_31 ] ) ;
} else {
if ( V_36 >= 2 )
for ( V_31 = 0 ; V_31 < V_27 [ V_30 ] . V_6 ; V_31 ++ )
F_2 ( V_37 L_9 , V_27 [ V_30 ] . V_5 [ V_31 ] ) ;
V_7 = F_1 ( V_2 , V_3 , V_27 [ V_30 ] . V_5 [ 0 ] ,
V_27 [ V_30 ] . V_5 + 1 , V_27 [ V_30 ] . V_6 - 1 ) ;
}
if ( V_36 >= 2 )
F_2 ( V_37 L_11 ) ;
if ( V_7 < 0 )
goto V_35;
}
return V_28 ;
V_35:
F_7 ( 2 , L_12 , V_7 ) ;
return V_7 ;
}
static int F_9 ( struct V_1 * V_2 )
{
int V_30 , V_7 ;
unsigned char * V_41 = V_2 -> V_42 ;
unsigned char V_43 [ 17 ] ;
V_2 -> V_44 . V_3 = 0xa0 >> 1 ;
V_2 -> V_45 = 0 ;
V_43 [ 16 ] = '\0' ;
for ( V_30 = 0 ; V_30 < sizeof( V_2 -> V_42 ) ; ) {
* V_41 = V_30 ;
V_7 = F_4 ( V_2 , 0xa0 , V_30 , V_41 , 1 ) ;
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
if ( 0 == ( V_30 % 16 ) )
F_2 ( V_50 L_14 , V_2 -> V_48 , V_30 ) ;
F_2 ( V_37 L_9 , V_2 -> V_42 [ V_30 ] ) ;
if ( ( V_2 -> V_42 [ V_30 ] >= ' ' ) && ( V_2 -> V_42 [ V_30 ] <= 'z' ) )
V_43 [ V_30 % 16 ] = V_2 -> V_42 [ V_30 ] ;
else
V_43 [ V_30 % 16 ] = '.' ;
V_30 ++ ;
if ( 0 == ( V_30 % 16 ) ) {
V_43 [ 16 ] = '\0' ;
F_2 ( V_37 L_15 , V_43 ) ;
}
}
if ( 0 != ( V_30 % 16 ) ) {
V_43 [ V_30 % 16 ] = '\0' ;
for ( V_30 %= 16 ; V_30 < 16 ; V_30 ++ )
F_2 ( V_37 L_16 ) ;
F_2 ( V_37 L_15 , V_43 ) ;
}
return 0 ;
V_46:
F_2 ( V_50 L_17 ,
V_2 -> V_48 , V_7 ) ;
return - V_49 ;
}
static T_4 F_10 ( struct V_24 * V_51 )
{
return V_52 ;
}
int F_11 ( struct V_1 * V_2 )
{
int V_7 ;
V_2 -> V_25 . V_53 = V_54 ;
V_2 -> V_25 . V_55 = & V_56 ;
V_2 -> V_25 . V_2 . V_57 = & V_2 -> V_58 -> V_2 ;
F_12 ( V_2 -> V_25 . V_48 , V_2 -> V_48 , sizeof( V_2 -> V_25 . V_48 ) ) ;
V_2 -> V_25 . V_29 = V_2 ;
F_13 ( & V_2 -> V_25 , & V_2 -> V_59 ) ;
V_7 = F_14 ( & V_2 -> V_25 ) ;
if ( V_7 )
return V_7 ;
V_2 -> V_44 . V_60 = & V_2 -> V_25 ;
F_12 ( V_2 -> V_44 . V_48 , L_18 , V_61 ) ;
F_9 ( V_2 ) ;
return 0 ;
}
int F_15 ( struct V_1 * V_2 )
{
F_16 ( & V_2 -> V_25 ) ;
return 0 ;
}
