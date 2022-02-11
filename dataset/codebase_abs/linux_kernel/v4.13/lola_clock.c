unsigned int F_1 ( unsigned int V_1 )
{
unsigned int V_2 ;
switch ( V_1 & 0x3 ) {
case 0 : V_2 = 48000 ; break;
case 1 : V_2 = 44100 ; break;
case 2 : V_2 = 32000 ; break;
default: return 0 ;
}
switch ( V_1 & 0x1c ) {
case ( 0 << 2 ) : break;
case ( 4 << 2 ) : break;
case ( 1 << 2 ) : V_2 *= 2 ; break;
case ( 2 << 2 ) : V_2 *= 4 ; break;
case ( 5 << 2 ) : V_2 /= 2 ; break;
case ( 6 << 2 ) : V_2 /= 4 ; break;
default: return 0 ;
}
switch ( V_1 & 0x60 ) {
case ( 0 << 5 ) : break;
case ( 1 << 5 ) : V_2 = ( V_2 * 999 ) / 1000 ; break;
case ( 2 << 5 ) : V_2 = ( V_2 * 1001 ) / 1000 ; break;
default: return 0 ;
}
return V_2 ;
}
static bool F_2 ( struct V_3 * V_4 ,
unsigned int V_5 ,
unsigned int V_2 )
{
if ( ! V_4 -> V_6 )
return true ;
if ( V_5 < V_7 || V_5 > V_8 ||
( V_5 % V_9 ) != 0 )
return false ;
if ( V_5 == V_7 ) {
if ( V_2 > V_10 )
return false ;
} else if ( V_5 < V_8 ) {
if ( V_2 > V_11 )
return false ;
}
return true ;
}
int F_3 ( struct V_3 * V_4 , unsigned int V_5 , bool V_12 )
{
int V_13 ;
if ( ! V_12 ) {
if ( V_5 == V_4 -> V_6 )
return 0 ;
#if 0
if (chip->audio_in_alloc_mask || chip->audio_out_alloc_mask)
return -EBUSY;
#endif
if ( ! F_2 ( V_4 , V_5 ,
V_4 -> clock . V_14 ) )
return - V_15 ;
}
V_4 -> V_6 = V_5 ;
V_5 /= V_9 ;
V_13 = F_4 ( V_4 , 1 , V_16 ,
V_5 , 0 ) ;
if ( V_13 < 0 )
return V_13 ;
F_5 ( 400 * V_5 , 20000 ) ;
return F_6 ( V_4 ) ;
}
int F_7 ( struct V_3 * V_4 , int V_17 )
{
unsigned int V_5 ;
int V_18 , V_19 , V_20 , V_21 , V_22 , V_23 ;
int V_13 ;
V_13 = F_8 ( V_4 , V_17 , V_24 , & V_5 ) ;
if ( V_13 < 0 ) {
F_9 ( V_4 -> V_25 -> V_26 , L_1 , V_17 ) ;
return V_13 ;
}
if ( ( V_5 & 0xfff00000 ) != 0x01f00000 ) {
F_10 ( V_4 -> V_25 -> V_26 , L_2 ) ;
return 0 ;
}
V_4 -> clock . V_17 = V_17 ;
V_4 -> clock . V_27 = V_5 & 0xff ;
F_10 ( V_4 -> V_25 -> V_26 , L_3 , V_17 ,
V_4 -> clock . V_27 ) ;
if ( V_4 -> clock . V_27 > V_28 ) {
F_9 ( V_4 -> V_25 -> V_26 , L_4 ,
V_4 -> clock . V_27 ) ;
return - V_15 ;
}
V_20 = V_4 -> clock . V_27 ;
V_21 = ( V_20 + 3 ) / 4 ;
V_22 = 0 ;
V_23 = 0 ;
for ( V_18 = 0 ; V_18 < V_21 ; V_18 ++ ) {
unsigned int V_29 ;
unsigned short V_27 [ 4 ] ;
V_13 = F_11 ( V_4 , V_17 , V_30 ,
V_22 , 0 , & V_5 , & V_29 ) ;
if ( V_13 < 0 ) {
F_9 ( V_4 -> V_25 -> V_26 , L_5 ) ;
return - V_15 ;
}
V_27 [ 0 ] = V_5 & 0xfff ;
V_27 [ 1 ] = ( V_5 >> 16 ) & 0xfff ;
V_27 [ 2 ] = V_29 & 0xfff ;
V_27 [ 3 ] = ( V_29 >> 16 ) & 0xfff ;
for ( V_19 = 0 ; V_19 < 4 ; V_19 ++ ) {
unsigned char type = V_27 [ V_19 ] >> 8 ;
unsigned int V_2 = V_27 [ V_19 ] & 0xff ;
int V_31 = V_32 ;
bool V_33 = true ;
if ( type == V_34 ) {
V_2 = F_1 ( V_2 ) ;
if ( V_2 < V_4 -> V_35 )
V_33 = false ;
else if ( V_2 == 48000 ) {
V_4 -> clock . V_36 = V_23 ;
V_4 -> clock . V_14 = 48000 ;
V_4 -> clock . V_37 = true ;
}
} else if ( type == V_38 ) {
V_2 = F_1 ( V_2 ) ;
if ( V_2 < V_4 -> V_35 )
V_33 = false ;
if ( V_27 [ V_19 ] & 0x80 )
V_31 = V_39 ;
else
V_31 = V_40 ;
}
if ( V_33 ) {
struct V_41 * V_42 ;
V_42 = & V_4 -> clock . V_43 [ V_23 ] ;
V_42 -> type = type ;
V_42 -> V_31 = V_31 ;
V_42 -> V_2 = V_2 ;
V_4 -> clock . V_44 [ V_23 ] = V_22 ;
V_23 ++ ;
} else {
V_4 -> clock . V_27 -- ;
}
if ( ++ V_22 >= V_20 )
break;
}
}
return 0 ;
}
int F_12 ( struct V_3 * V_4 )
{
unsigned int V_45 ;
int V_13 ;
V_13 = F_11 ( V_4 , V_4 -> clock . V_17 ,
V_46 ,
V_47 | V_48 ,
0 , & V_45 , NULL ) ;
if ( V_13 < 0 )
return V_13 ;
if ( V_45 ) {
F_13 ( V_4 -> V_25 -> V_26 , L_6 ,
V_45 ) ;
return - V_15 ;
}
return 0 ;
}
int F_14 ( struct V_3 * V_4 , unsigned int V_22 )
{
unsigned int V_45 ;
int V_13 ;
V_13 = F_11 ( V_4 , V_4 -> clock . V_17 ,
V_49 ,
V_4 -> clock . V_44 [ V_22 ] ,
0 , & V_45 , NULL ) ;
if ( V_13 < 0 )
return V_13 ;
if ( V_45 ) {
F_13 ( V_4 -> V_25 -> V_26 , L_7 , V_45 ) ;
return - V_15 ;
}
return 0 ;
}
bool F_15 ( struct V_3 * V_4 , unsigned int V_5 )
{
unsigned int V_50 ;
if ( ! V_5 )
return false ;
V_50 = ( V_5 >> V_51 ) & V_52 ;
if ( V_50 != V_48 )
return false ;
if ( V_4 -> clock . V_43 [ V_4 -> clock . V_36 ] . type !=
V_34 ) {
V_4 -> clock . V_14 = F_1 ( V_5 & 0x7f ) ;
V_4 -> clock . V_37 = ( V_5 & 0x100 ) != 0 ;
}
return true ;
}
int F_16 ( struct V_3 * V_4 , int V_22 )
{
int V_2 = 0 ;
bool V_53 = false ;
if ( V_22 == V_4 -> clock . V_36 ) {
V_2 = V_4 -> clock . V_14 ;
V_53 = V_4 -> clock . V_37 ;
} else if ( V_4 -> clock . V_43 [ V_22 ] . type ==
V_34 ) {
V_2 = V_4 -> clock . V_43 [ V_22 ] . V_2 ;
V_53 = true ;
}
if ( ! V_2 || ! V_53 )
return - V_15 ;
if ( ! F_2 ( V_4 , V_4 -> V_6 , V_2 ) )
return - V_15 ;
if ( V_22 != V_4 -> clock . V_36 ) {
int V_13 = F_14 ( V_4 , V_22 ) ;
if ( V_13 < 0 )
return V_13 ;
V_4 -> clock . V_36 = V_22 ;
V_4 -> clock . V_14 = V_2 ;
V_4 -> clock . V_37 = true ;
}
return 0 ;
}
int F_17 ( struct V_3 * V_4 , int V_54 )
{
int V_18 ;
if ( V_4 -> clock . V_14 == V_54 && V_4 -> clock . V_37 )
return 0 ;
for ( V_18 = 0 ; V_18 < V_4 -> clock . V_27 ; V_18 ++ ) {
if ( V_4 -> clock . V_43 [ V_18 ] . type == V_34 &&
V_4 -> clock . V_43 [ V_18 ] . V_2 == V_54 )
break;
}
if ( V_18 >= V_4 -> clock . V_27 )
return - V_15 ;
return F_16 ( V_4 , V_18 ) ;
}
