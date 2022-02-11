void F_1 ( void * V_1 , int V_2 )
{
struct V_3 * V_4 = V_1 ;
if ( V_2 == 1 )
F_2 ( V_4 , V_5 , 0x10 ) ;
else
F_3 ( V_4 , V_5 , 0x10 ) ;
}
int F_4 ( void * V_1 , int V_6 , int V_7 , int V_8 )
{
struct V_3 * V_4 = V_1 ;
F_5 ( 1 , L_1 , V_9 ) ;
switch ( V_4 -> V_10 ) {
case V_11 :
case V_12 :
case V_13 :
case V_14 :
if ( V_7 == 0 ) {
F_3 ( V_4 , V_15 , 2 ) ;
F_6 ( 10 ) ;
F_2 ( V_4 , V_15 , 2 ) ;
F_6 ( 10 ) ;
return 0 ;
} else {
F_7 ( V_16
L_2 , V_9 ) ;
return - V_17 ;
}
break;
}
return 0 ;
}
static void F_8 ( struct V_3 * V_4 , T_1 * V_18 )
{
struct V_19 V_20 ;
F_9 ( & V_4 -> V_21 , & V_20 , V_18 ) ;
V_4 -> V_22 . V_23 = V_20 . V_23 ;
switch ( V_20 . V_24 ) {
case 72000 :
case 72001 :
case 72101 :
case 72201 :
case 72211 :
case 72221 :
case 72231 :
case 72241 :
case 72251 :
case 72261 :
case 72301 :
case 72500 :
break;
default:
F_7 ( V_25 L_3
L_4 , V_9 , V_20 . V_24 ) ;
break;
}
F_7 ( V_26 L_5 ,
V_9 , V_20 . V_24 ) ;
}
void F_10 ( struct V_3 * V_4 )
{
static T_1 V_27 [ 256 ] ;
struct V_28 V_29 ;
struct V_30 * V_31 ;
unsigned int V_32 = V_33 ;
F_5 ( 1 , L_1 , V_9 ) ;
memcpy ( & V_4 -> V_22 , & V_34 [ V_4 -> V_10 ] , sizeof( V_4 -> V_22 ) ) ;
if ( V_4 -> V_35 == 0 ) {
V_4 -> V_21 . V_36 = 0xa0 >> 1 ;
F_11 ( & V_4 -> V_21 , V_27 , sizeof( V_27 ) ) ;
}
switch ( V_4 -> V_10 ) {
case V_11 :
case V_12 :
case V_13 :
case V_37 :
if ( V_4 -> V_35 == 0 )
F_8 ( V_4 , V_27 + 0xa0 ) ;
break;
}
if ( F_12 ( 0 ) . type != V_38 ) {
V_31 = F_13 ( & V_4 -> V_39 , & V_4 -> V_40 ,
L_6 , 0x8e >> 1 , NULL ) ;
if ( V_31 == NULL )
F_7 ( V_16 L_7 ) ;
}
if ( V_4 -> V_22 . V_23 != V_41 ) {
V_31 = F_13 ( & V_4 -> V_39 , & V_4 -> V_40 ,
L_8 , V_4 -> V_22 . V_42 , NULL ) ;
if ( V_31 == NULL )
F_7 ( V_16 L_9 ) ;
V_29 . V_32 = V_32 ;
V_29 . type = V_4 -> V_22 . V_23 ;
V_29 . V_36 = V_4 -> V_22 . V_42 ;
V_29 . V_43 = F_4 ;
F_14 ( & V_4 -> V_39 , 0 , V_44 , V_45 ,
& V_29 ) ;
}
}
void F_15 ( struct V_3 * V_4 )
{
F_5 ( 1 , L_1 , V_9 ) ;
switch ( V_4 -> V_10 ) {
case V_11 :
case V_12 :
case V_13 :
case V_37 :
F_16 ( V_4 , V_46 , 0x02 ) ;
F_16 ( V_4 , V_47 , 0x80 | 0x20 | 0x10 ) ;
F_16 ( V_4 , V_15 , 0x0 ) ;
F_16 ( V_4 , V_5 , 0x0 ) ;
F_17 ( 100 ) ;
F_16 ( V_4 , V_46 , 0x02 ) ;
F_16 ( V_4 , V_15 , 0x02 ) ;
F_16 ( V_4 , V_47 , 0x80 | 0x20 | 0x10 ) ;
F_16 ( V_4 , V_5 , 0x80 | 0x40 | 0x20 ) ;
F_17 ( 250 ) ;
break;
case V_14 :
F_16 ( V_4 , V_46 , 0x02 ) ;
F_16 ( V_4 , V_47 , 0xa0 ) ;
F_16 ( V_4 , V_15 , 0x0 ) ;
F_16 ( V_4 , V_5 , 0x0 ) ;
F_17 ( 100 ) ;
F_16 ( V_4 , V_46 , 0x02 ) ;
F_16 ( V_4 , V_47 , 0xa0 ) ;
F_16 ( V_4 , V_15 , 0x02 ) ;
F_16 ( V_4 , V_5 , 0xa0 ) ;
F_17 ( 250 ) ;
break;
}
}
