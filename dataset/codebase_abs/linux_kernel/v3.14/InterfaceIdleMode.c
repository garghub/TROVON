int F_1 ( struct V_1 * V_2 ,
unsigned int * V_3 )
{
int V_4 = V_5 ;
unsigned int V_6 = 0 ;
int V_7 ;
if ( F_2 ( * V_3 ) == V_8 ) {
if ( F_2 ( * ( V_3 + 1 ) ) == 0 ) {
V_4 = F_3 ( V_2 , V_9 ,
& V_6 , sizeof( V_6 ) ) ;
if ( V_4 )
return V_4 ;
if ( V_2 -> V_10 ==
V_11 ) {
V_6 = 0x00000000 ;
V_4 = F_3 ( V_2 ,
V_12 ,
& V_6 , sizeof( V_6 ) ) ;
if ( V_4 )
return V_4 ;
}
else if ( V_2 -> V_10 !=
V_13 ) {
V_7 = F_4 ( V_2 , V_14 ,
& V_6 , sizeof( V_6 ) ) ;
if ( V_7 < 0 ) {
V_4 = V_7 ;
return V_4 ;
}
V_7 = F_4 ( V_2 , V_15 ,
& V_6 , sizeof( V_6 ) ) ;
if ( V_7 < 0 ) {
V_4 = V_7 ;
return V_4 ;
}
}
V_2 -> V_16 = false ;
V_2 -> V_17 = false ;
F_5 ( & V_2 -> V_18 ) ;
} else {
if ( TRUE == V_2 -> V_16 )
return V_4 ;
V_6 = 0 ;
if ( V_2 -> V_19 == V_20 ||
V_2 -> V_19 == V_21 ||
V_2 -> V_19 == V_22 ||
V_2 -> V_19 == V_23 ) {
V_7 = F_4 ( V_2 , V_24 ,
& V_6 , sizeof( V_6 ) ) ;
if ( V_7 < 0 ) {
V_4 = V_7 ;
return V_4 ;
}
V_6 |= ( 1 << 17 ) ;
V_4 = F_3 ( V_2 , V_24 ,
& V_6 , sizeof( V_6 ) ) ;
if ( V_4 )
return V_4 ;
}
F_6 ( V_2 ) ;
}
} else if ( F_2 ( * V_3 ) == V_25 ) {
F_7 ( V_2 , V_3 ) ;
}
return V_4 ;
}
static int F_8 ( struct V_1 * V_2 ,
unsigned int V_26 )
{
int V_4 = V_5 ;
unsigned int V_27 ;
unsigned int V_19 ;
unsigned long V_28 = 0 , V_29 = 0 ;
int V_30 = 0 ;
unsigned char V_31 [ 8 ] = { 0xFF , 0xFF , 0xFF , 0xFF , 0xFF ,
0xFF , 0xFF , 0xFF } ;
struct V_32 * V_33 =
V_2 -> V_34 ;
if ( ( TRUE == V_33 -> V_35 ) &&
( TRUE == V_2 -> V_36 ) )
V_4 = F_9 (
V_33 -> V_37 ) ;
if ( ( V_2 -> V_10 ==
V_11 ) ||
( V_2 -> V_10 ==
V_13 ) ) {
V_4 = F_3 ( V_2 , V_9 ,
& V_26 , sizeof( V_26 ) ) ;
if ( V_4 )
return V_4 ;
}
if ( V_2 -> V_10 ==
V_11 ) {
V_27 = 0x80000000 ;
V_4 = F_3 ( V_2 ,
V_12 ,
& V_27 , sizeof( V_27 ) ) ;
if ( V_4 )
return V_4 ;
} else if ( V_2 -> V_10 !=
V_13 ) {
V_4 = F_10 ( V_33 -> V_38 ,
F_11 ( V_33 -> V_38 ,
V_33 -> V_39 . V_40 ) ,
V_31 ,
8 ,
& V_30 ,
5000 ) ;
if ( V_4 )
return V_4 ;
else
F_12 ( V_2 , V_41 ,
V_42 , V_43 ,
L_1 , V_30 ) ;
V_28 = V_44 + F_13 ( 50 ) ;
while ( F_14 ( V_28 , V_44 ) ) {
V_29 ++ ;
F_4 ( V_2 , V_45 , & V_19 , sizeof( V_46 ) ) ;
if ( 0xbece3200 == ( V_19 & ~ ( 0xF0 ) ) )
V_19 = V_19 & ~ ( 0xF0 ) ;
if ( V_19 == V_2 -> V_19 )
break;
}
if ( F_15 ( V_28 , V_44 ) )
F_12 ( V_2 , V_41 ,
V_42 , V_43 ,
L_2 ) ;
else
F_12 ( V_2 , V_41 ,
V_42 , V_43 ,
L_3
L_4 , V_29 ) ;
V_4 = F_3 ( V_2 , V_9 ,
& V_26 , sizeof( V_4 ) ) ;
if ( V_4 )
return V_4 ;
}
return V_4 ;
}
int F_16 ( struct V_1 * V_2 )
{
T_1 V_47 = 0 ;
if ( V_2 -> V_17 ) {
F_12 ( V_2 , V_41 ,
V_42 , V_43 ,
L_5 ) ;
} else {
V_2 -> V_17 = TRUE ;
F_8 ( V_2 , V_2 -> V_48 ) ;
}
return V_47 ;
}
void F_17 ( struct V_1 * V_2 )
{
unsigned int V_49 = 0 ;
INT V_47 = 0 ;
int V_7 ;
if ( V_2 -> V_10 ==
V_11 ) {
V_49 = 0 ;
V_47 = F_3 ( V_2 ,
V_12 ,
& V_49 , sizeof( V_49 ) ) ;
if ( V_47 )
return;
}
else {
V_7 = F_4 ( V_2 ,
V_14 ,
& V_49 , sizeof( V_49 ) ) ;
if ( V_7 < 0 ) {
V_47 = V_7 ;
return;
}
V_7 = F_4 ( V_2 ,
V_15 ,
& V_49 , sizeof( V_49 ) ) ;
if ( V_7 < 0 ) {
V_47 = V_7 ;
return;
}
}
}
