static void F_1 ( void * V_1 , int V_2 )
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
F_7 ( L_2 , V_9 ) ;
return - V_16 ;
}
break;
}
return 0 ;
}
static void F_8 ( struct V_3 * V_4 , T_1 * V_17 )
{
struct V_18 V_19 ;
F_9 ( & V_19 , V_17 ) ;
V_4 -> V_20 . V_21 = V_19 . V_21 ;
switch ( V_19 . V_22 ) {
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
case 72271 :
case 72281 :
case 72301 :
case 72500 :
break;
default:
F_10 ( L_3 ,
V_9 , V_19 . V_22 ) ;
break;
}
F_11 ( L_4 ,
V_9 , V_19 . V_22 ) ;
}
void F_12 ( struct V_3 * V_4 )
{
static T_1 V_23 [ 256 ] ;
F_5 ( 1 , L_1 , V_9 ) ;
if ( V_4 -> V_24 == 0 ) {
V_4 -> V_25 . V_26 = 0xa0 >> 1 ;
F_13 ( & V_4 -> V_25 , V_23 , sizeof( V_23 ) ) ;
}
switch ( V_4 -> V_10 ) {
case V_11 :
case V_12 :
case V_13 :
case V_27 :
if ( V_4 -> V_24 == 0 )
F_8 ( V_4 , V_23 + 0xa0 ) ;
break;
}
F_14 ( V_4 ) ;
}
void F_14 ( struct V_3 * V_4 )
{
#ifdef F_15
struct V_28 V_29 ;
struct V_30 * V_31 ;
unsigned int V_32 = V_33 ;
if ( F_16 ( 0 ) . type != V_34 ) {
V_31 = F_17 ( & V_4 -> V_35 , & V_4 -> V_36 ,
L_5 , 0x8e >> 1 , NULL ) ;
if ( V_31 == NULL )
F_7 ( L_6 ) ;
}
if ( V_4 -> V_20 . V_21 != V_37 && V_4 -> V_20 . V_38 ) {
V_31 = F_17 ( & V_4 -> V_35 , & V_4 -> V_36 ,
L_7 , V_4 -> V_20 . V_39 , NULL ) ;
if ( V_31 == NULL )
F_7 ( L_8 ) ;
V_29 . V_32 = V_32 ;
V_29 . type = V_4 -> V_20 . V_21 ;
V_29 . V_26 = V_4 -> V_20 . V_39 ;
V_29 . V_40 = F_4 ;
F_18 ( & V_4 -> V_35 , 0 , V_41 , V_42 ,
& V_29 ) ;
}
#endif
}
void F_19 ( struct V_3 * V_4 )
{
F_5 ( 1 , L_1 , V_9 ) ;
switch ( V_4 -> V_10 ) {
case V_11 :
case V_12 :
case V_13 :
case V_27 :
F_20 ( V_4 , V_43 , 0x02 ) ;
F_20 ( V_4 , V_44 , 0x80 | 0x20 | 0x10 ) ;
F_20 ( V_4 , V_15 , 0x0 ) ;
F_20 ( V_4 , V_5 , 0x0 ) ;
F_21 ( 50 ) ;
F_20 ( V_4 , V_5 , 0x80 ) ;
F_21 ( 50 ) ;
F_20 ( V_4 , V_15 , 0x02 ) ;
F_20 ( V_4 , V_5 , 0x80 | 0x20 ) ;
F_21 ( 250 ) ;
break;
case V_14 :
F_20 ( V_4 , V_43 , 0x02 ) ;
F_20 ( V_4 , V_44 , 0xa0 ) ;
F_20 ( V_4 , V_15 , 0x0 ) ;
F_20 ( V_4 , V_5 , 0x0 ) ;
F_21 ( 100 ) ;
F_20 ( V_4 , V_43 , 0x02 ) ;
F_20 ( V_4 , V_44 , 0xa0 ) ;
F_20 ( V_4 , V_15 , 0x02 ) ;
F_20 ( V_4 , V_5 , 0xa0 ) ;
F_21 ( 250 ) ;
break;
}
}
