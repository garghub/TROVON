static T_1
F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_5 * V_6 )
{
int V_7 ;
int V_8 ;
char V_9 [ V_10 ] ;
struct V_5 V_11 = { . V_12 = sizeof( V_9 ) ,
. V_13 = V_9 } ;
T_2 V_14 ;
int V_15 ;
T_1 V_16 ;
unsigned char * V_17 = ( unsigned char * ) V_6 -> V_13 ;
int V_18 ;
T_3 * V_19 ;
F_2 ( L_1 ) ;
if ( F_3 ( & V_2 -> V_20 , & V_18 , & V_17 ,
V_6 -> V_12 ) )
return V_21 ;
if ( ( V_17 [ 0 ] != ( ( V_22 >> 8 ) & 0xff ) ) ||
( V_17 [ 1 ] != ( V_22 & 0xff ) ) )
return V_21 ;
V_7 = V_17 [ 2 ] + ( V_17 [ 3 ] << 8 ) ;
if ( V_7 != V_2 -> V_23 -> V_7 )
return V_21 ;
V_8 = V_17 [ 4 ] + ( V_17 [ 5 ] << 8 ) ;
if ( V_8 != V_24 )
return V_21 ;
if ( ( V_17 [ 6 ] != 0xff ) || ( V_17 [ 7 ] != 0xff ) )
return V_21 ;
if ( V_2 -> V_23 -> V_25 )
V_19 = V_2 -> V_26 ;
else
V_19 = NULL ;
if ( F_4 ( V_2 , V_17 , 8 , V_4 , 0 ,
V_19 , V_27 , & V_11 ) )
return V_28 ;
if ( memcmp ( V_11 . V_13 , V_17 + V_29 ,
V_2 -> V_23 -> V_30 ) )
return V_31 ;
V_14 = F_5 () ;
if ( V_14 > V_2 -> V_32 )
return V_33 ;
if ( F_6 ( V_2 , V_17 + V_29 , V_17 + 8 ,
& V_15 , & V_16 ) )
return V_28 ;
if ( ( V_2 -> V_34 && V_15 != 0xff ) ||
( ! V_2 -> V_34 && V_15 != 0 ) )
return V_31 ;
return V_35 ;
}
static T_1
F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_5 * V_6 )
{
char V_9 [ V_10 ] ;
struct V_5 V_36 = { . V_12 = sizeof( V_9 ) ,
. V_13 = V_9 } ;
T_2 V_14 ;
T_3 * V_17 = V_6 -> V_13 ;
T_3 * V_19 ;
T_3 V_37 ;
int V_38 ;
unsigned int V_39 ;
F_2 ( L_2 , V_40 ) ;
if ( F_8 ( * ( ( V_41 * ) V_17 ) ) != V_42 )
return V_21 ;
V_37 = V_17 [ 2 ] ;
if ( ( ! V_2 -> V_34 && ( V_37 & V_43 ) ) ||
( V_2 -> V_34 && ! ( V_37 & V_43 ) ) )
return V_31 ;
if ( V_37 & V_44 ) {
F_2 ( L_3 , V_40 ) ;
return V_28 ;
}
for ( V_38 = 3 ; V_38 < 8 ; V_38 ++ )
if ( V_17 [ V_38 ] != 0xff )
return V_21 ;
if ( V_2 -> V_34 ) {
V_19 = V_2 -> V_45 ;
V_39 = V_46 ;
} else {
V_19 = V_2 -> V_47 ;
V_39 = V_48 ;
}
if ( F_9 ( V_2 , V_17 , V_29 , V_4 , 0 ,
V_19 , V_39 , & V_36 ) )
return V_28 ;
if ( memcmp ( V_36 . V_13 , V_17 + V_29 ,
V_2 -> V_23 -> V_30 ) )
return V_31 ;
V_14 = F_5 () ;
if ( V_14 > V_2 -> V_32 )
return V_33 ;
return V_35 ;
}
T_1
F_10 ( struct V_49 * V_49 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_1 * V_2 = V_49 -> V_50 ;
switch ( V_2 -> V_51 ) {
default:
F_11 () ;
case V_52 :
case V_53 :
case V_54 :
return F_1 ( V_2 , V_4 , V_6 ) ;
case V_55 :
case V_56 :
return F_7 ( V_2 , V_4 , V_6 ) ;
}
}
