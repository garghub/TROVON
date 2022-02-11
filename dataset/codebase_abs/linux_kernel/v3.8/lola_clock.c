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
F_9 (KERN_ERR SFX L_1 , nid) ;
return V_13 ;
}
if ( ( V_5 & 0xfff00000 ) != 0x01f00000 ) {
F_10 ( L_2 ) ;
return 0 ;
}
V_4 -> clock . V_17 = V_17 ;
V_4 -> clock . V_25 = V_5 & 0xff ;
F_10 ( L_3 , V_17 ,
V_4 -> clock . V_25 ) ;
if ( V_4 -> clock . V_25 > V_26 ) {
F_9 (KERN_ERR SFX L_4 ,
chip->clock.items) ;
return - V_15 ;
}
V_20 = V_4 -> clock . V_25 ;
V_21 = ( V_20 + 3 ) / 4 ;
V_22 = 0 ;
V_23 = 0 ;
for ( V_18 = 0 ; V_18 < V_21 ; V_18 ++ ) {
unsigned int V_27 ;
unsigned short V_25 [ 4 ] ;
V_13 = F_11 ( V_4 , V_17 , V_28 ,
V_22 , 0 , & V_5 , & V_27 ) ;
if ( V_13 < 0 ) {
F_9 (KERN_ERR SFX L_5 ) ;
return - V_15 ;
}
V_25 [ 0 ] = V_5 & 0xfff ;
V_25 [ 1 ] = ( V_5 >> 16 ) & 0xfff ;
V_25 [ 2 ] = V_27 & 0xfff ;
V_25 [ 3 ] = ( V_27 >> 16 ) & 0xfff ;
for ( V_19 = 0 ; V_19 < 4 ; V_19 ++ ) {
unsigned char type = V_25 [ V_19 ] >> 8 ;
unsigned int V_2 = V_25 [ V_19 ] & 0xff ;
int V_29 = V_30 ;
bool V_31 = true ;
if ( type == V_32 ) {
V_2 = F_1 ( V_2 ) ;
if ( V_2 < V_4 -> V_33 )
V_31 = false ;
else if ( V_2 == 48000 ) {
V_4 -> clock . V_34 = V_23 ;
V_4 -> clock . V_14 = 48000 ;
V_4 -> clock . V_35 = true ;
}
} else if ( type == V_36 ) {
V_2 = F_1 ( V_2 ) ;
if ( V_2 < V_4 -> V_33 )
V_31 = false ;
if ( V_25 [ V_19 ] & 0x80 )
V_29 = V_37 ;
else
V_29 = V_38 ;
}
if ( V_31 ) {
struct V_39 * V_40 ;
V_40 = & V_4 -> clock . V_41 [ V_23 ] ;
V_40 -> type = type ;
V_40 -> V_29 = V_29 ;
V_40 -> V_2 = V_2 ;
V_4 -> clock . V_42 [ V_23 ] = V_22 ;
V_23 ++ ;
} else {
V_4 -> clock . V_25 -- ;
}
if ( ++ V_22 >= V_20 )
break;
}
}
return 0 ;
}
int F_12 ( struct V_3 * V_4 )
{
unsigned int V_43 ;
int V_13 ;
V_13 = F_11 ( V_4 , V_4 -> clock . V_17 ,
V_44 ,
V_45 | V_46 ,
0 , & V_43 , NULL ) ;
if ( V_13 < 0 )
return V_13 ;
if ( V_43 ) {
F_9 (KERN_WARNING SFX L_6 ,
res) ;
return - V_15 ;
}
return 0 ;
}
int F_13 ( struct V_3 * V_4 , unsigned int V_22 )
{
unsigned int V_43 ;
int V_13 ;
V_13 = F_11 ( V_4 , V_4 -> clock . V_17 ,
V_47 ,
V_4 -> clock . V_42 [ V_22 ] ,
0 , & V_43 , NULL ) ;
if ( V_13 < 0 )
return V_13 ;
if ( V_43 ) {
F_9 (KERN_WARNING SFX L_7 , res) ;
return - V_15 ;
}
return 0 ;
}
bool F_14 ( struct V_3 * V_4 , unsigned int V_5 )
{
unsigned int V_48 ;
if ( ! V_5 )
return false ;
V_48 = ( V_5 >> V_49 ) & V_50 ;
if ( V_48 != V_46 )
return false ;
if ( V_4 -> clock . V_41 [ V_4 -> clock . V_34 ] . type !=
V_32 ) {
V_4 -> clock . V_14 = F_1 ( V_5 & 0x7f ) ;
V_4 -> clock . V_35 = ( V_5 & 0x100 ) != 0 ;
}
return true ;
}
int F_15 ( struct V_3 * V_4 , int V_22 )
{
int V_2 = 0 ;
bool V_51 = false ;
if ( V_22 == V_4 -> clock . V_34 ) {
V_2 = V_4 -> clock . V_14 ;
V_51 = V_4 -> clock . V_35 ;
} else if ( V_4 -> clock . V_41 [ V_22 ] . type ==
V_32 ) {
V_2 = V_4 -> clock . V_41 [ V_22 ] . V_2 ;
V_51 = true ;
}
if ( ! V_2 || ! V_51 )
return - V_15 ;
if ( ! F_2 ( V_4 , V_4 -> V_6 , V_2 ) )
return - V_15 ;
if ( V_22 != V_4 -> clock . V_34 ) {
int V_13 = F_13 ( V_4 , V_22 ) ;
if ( V_13 < 0 )
return V_13 ;
V_4 -> clock . V_34 = V_22 ;
V_4 -> clock . V_14 = V_2 ;
V_4 -> clock . V_35 = true ;
}
return 0 ;
}
int F_16 ( struct V_3 * V_4 , int V_52 )
{
int V_18 ;
if ( V_4 -> clock . V_14 == V_52 && V_4 -> clock . V_35 )
return 0 ;
for ( V_18 = 0 ; V_18 < V_4 -> clock . V_25 ; V_18 ++ ) {
if ( V_4 -> clock . V_41 [ V_18 ] . type == V_32 &&
V_4 -> clock . V_41 [ V_18 ] . V_2 == V_52 )
break;
}
if ( V_18 >= V_4 -> clock . V_25 )
return - V_15 ;
return F_15 ( V_4 , V_18 ) ;
}
