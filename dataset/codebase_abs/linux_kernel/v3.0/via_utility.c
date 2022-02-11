void F_1 ( T_1 * V_1 )
{
* V_1 = V_2 ;
if ( V_3 -> V_4 -> V_5 . V_6 == V_7 )
* V_1 |= V_8 ;
if ( V_3 -> V_4 -> V_9 . V_10 == V_11 )
* V_1 |= V_12 ;
}
void F_2 ( T_1 * V_13 )
{
bool V_14 = false ;
* V_13 = V_2 ;
if ( F_3 () )
* V_13 |= V_8 ;
F_4 ( & V_14 ) ;
if ( V_14 )
* V_13 |= V_12 ;
}
bool F_5 ( T_1 V_15 , T_1 V_16 )
{
unsigned int V_1 = 0 ;
switch ( V_17 ) {
case V_18 :
if ( ( V_15 < 640 ) && ( V_16 < 480 ) )
V_1 = true ;
break;
case V_19 :
if ( ( V_15 < 800 ) && ( V_16 < 600 ) )
V_1 = true ;
break;
case V_20 :
if ( ( V_15 < 1024 ) && ( V_16 < 768 ) )
V_1 = true ;
break;
case V_21 :
if ( ( V_15 < 1280 ) && ( V_16 < 768 ) )
V_1 = true ;
break;
case V_22 :
if ( ( V_15 < 1280 ) && ( V_16 < 1024 ) )
V_1 = true ;
break;
case V_23 :
if ( ( V_15 < 1400 ) && ( V_16 < 1050 ) )
V_1 = true ;
break;
case V_24 :
if ( ( V_15 < 1600 ) && ( V_16 < 1200 ) )
V_1 = true ;
break;
case V_25 :
if ( ( V_15 < 1366 ) && ( V_16 < 768 ) )
V_1 = true ;
break;
case V_26 :
if ( ( V_15 < 1024 ) && ( V_16 < 600 ) )
V_1 = true ;
break;
case V_27 :
if ( ( V_15 < 1280 ) && ( V_16 < 800 ) )
V_1 = true ;
break;
case V_28 :
if ( ( V_15 < 800 ) && ( V_16 < 480 ) )
V_1 = true ;
break;
case V_29 :
if ( ( V_15 < 1360 ) && ( V_16 < 768 ) )
V_1 = true ;
break;
case V_30 :
if ( ( V_15 < 480 ) && ( V_16 < 640 ) )
V_1 = true ;
break;
default:
V_1 = false ;
break;
}
return V_1 ;
}
void F_6 ( int V_31 , unsigned int * V_32 )
{
int V_33 , V_34 ;
int V_35 = 0 ;
int V_36 = V_37 ;
for ( V_33 = 0 ; V_33 < sizeof( V_37 ) * 8 ; V_33 ++ ) {
if ( V_36 & 1 )
V_35 ++ ;
V_36 >>= 1 ;
}
if ( V_31 == 8 )
return ;
switch ( V_3 -> V_4 -> V_38 ) {
case V_39 :
case V_40 :
F_7 ( V_41 , V_42 , 0x80 , V_43 ) ;
break;
case V_44 :
case V_45 :
case V_46 :
case V_47 :
case V_48 :
case V_49 :
case V_50 :
F_7 ( V_51 , V_52 , 0x80 , V_43 ) ;
break;
}
V_34 = ( unsigned int ) F_8 ( V_42 , V_53 ) ;
F_7 ( V_53 , V_42 , 0x0 , V_54 ) ;
F_9 ( 0 , V_55 ) ;
for ( V_33 = 0 ; V_33 < 256 ; V_33 ++ ) {
F_9 ( V_32 [ V_33 ] >> 16 , V_56 ) ;
F_9 ( V_32 [ V_33 ] >> 8 & 0xFF , V_56 ) ;
F_9 ( V_32 [ V_33 ] & 0xFF , V_56 ) ;
}
if ( ( V_35 > 1 ) &&
! ( ( V_3 -> V_4 -> V_38 ==
V_39 ) &&
( V_3 -> V_4 -> V_57 < 15 ) ) ) {
F_7 ( V_53 , V_42 , 0x01 , V_54 ) ;
F_7 ( V_58 , V_52 , 0x02 , V_59 ) ;
F_9 ( 0 , V_55 ) ;
for ( V_33 = 0 ; V_33 < 256 ; V_33 ++ ) {
F_9 ( V_32 [ V_33 ] >> 16 , V_56 ) ;
F_9 ( V_32 [ V_33 ] >> 8 & 0xFF , V_56 ) ;
F_9 ( V_32 [ V_33 ] & 0xFF , V_56 ) ;
}
}
F_10 ( V_53 , V_42 , V_34 ) ;
}
void F_11 ( unsigned int * V_32 )
{
unsigned char V_60 , V_61 , V_62 ;
unsigned char V_34 = 0 ;
int V_33 ;
switch ( V_3 -> V_4 -> V_38 ) {
case V_39 :
case V_40 :
F_7 ( V_41 , V_42 , 0x80 , V_43 ) ;
break;
case V_44 :
case V_45 :
case V_46 :
case V_47 :
case V_48 :
case V_49 :
case V_50 :
F_7 ( V_51 , V_52 , 0x80 , V_43 ) ;
break;
}
V_34 = F_8 ( V_42 , V_53 ) ;
F_7 ( V_53 , V_42 , 0x0 , V_54 ) ;
F_9 ( 0 , V_63 ) ;
for ( V_33 = 0 ; V_33 < 256 ; V_33 ++ ) {
V_60 = F_12 ( V_56 ) ;
V_61 = F_12 ( V_56 ) ;
V_62 = F_12 ( V_56 ) ;
V_32 [ V_33 ] =
( ( ( ( T_1 ) V_60 ) << 16 ) |
( ( ( V_64 ) V_61 ) << 8 ) ) | V_62 ;
}
F_10 ( V_53 , V_42 , V_34 ) ;
}
void F_13 ( int V_31 , unsigned int * V_1 )
{
if ( V_31 == 8 )
* V_1 = V_65 ;
else
* V_1 = V_2 | V_8 | V_12 ;
}
