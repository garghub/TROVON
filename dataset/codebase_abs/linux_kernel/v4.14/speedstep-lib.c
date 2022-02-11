static unsigned int F_1 ( enum V_1 V_2 )
{
static const struct {
unsigned int V_3 ;
T_1 V_4 ;
} V_5 [] = {
{ 30 , 0x01 } ,
{ 35 , 0x05 } ,
{ 40 , 0x02 } ,
{ 45 , 0x06 } ,
{ 50 , 0x00 } ,
{ 55 , 0x04 } ,
{ 60 , 0x0b } ,
{ 65 , 0x0f } ,
{ 70 , 0x09 } ,
{ 75 , 0x0d } ,
{ 80 , 0x0a } ,
{ 85 , 0x26 } ,
{ 90 , 0x20 } ,
{ 100 , 0x2b } ,
{ 0 , 0xff }
} ;
static const struct {
unsigned int V_6 ;
T_1 V_4 ;
} V_7 [] = {
{ 66 , 0x0 } ,
{ 100 , 0x2 } ,
{ 133 , 0x1 } ,
{ 0 , 0xff }
} ;
T_2 V_8 , V_9 ;
int V_10 = 0 , V_11 = 0 ;
F_2 ( V_12 , V_8 , V_9 ) ;
F_3 ( L_1 , V_8 , V_9 ) ;
V_9 = V_8 ;
V_9 &= 0x00c0000 ;
V_9 >>= 18 ;
while ( V_9 != V_7 [ V_10 ] . V_4 ) {
if ( V_7 [ V_10 ] . V_4 == 0xff )
return 0 ;
V_10 ++ ;
}
if ( V_2 == V_13 ) {
F_3 ( L_2 ) ;
V_8 &= 0x03c00000 ;
} else
V_8 &= 0x0bc00000 ;
V_8 >>= 22 ;
while ( V_8 != V_5 [ V_11 ] . V_4 ) {
if ( V_5 [ V_11 ] . V_4 == 0xff )
return 0 ;
V_11 ++ ;
}
F_3 ( L_3 ,
( V_5 [ V_11 ] . V_3 * V_7 [ V_10 ] . V_6 * 100 ) ) ;
return V_5 [ V_11 ] . V_3 * V_7 [ V_10 ] . V_6 * 100 ;
}
static unsigned int F_4 ( void )
{
T_2 V_8 , V_9 ;
F_2 ( V_12 , V_8 , V_9 ) ;
F_3 ( L_4 , V_8 , V_9 ) ;
if ( V_8 & 0x00040000 ) {
F_5 (KERN_DEBUG PFX L_5 ,
msr_lo, msr_tmp) ;
return 0 ;
}
V_9 = ( V_8 >> 22 ) & 0x1f ;
F_3 ( L_6 ,
V_9 , ( V_9 * 100 * 1000 ) ) ;
return V_9 * 100 * 1000 ;
}
static unsigned int F_6 ( void )
{
T_2 V_14 = 0 ;
T_2 V_8 , V_9 ;
int V_15 ;
F_2 ( V_16 , V_8 , V_9 ) ;
switch ( V_8 & 0x07 ) {
case 5 :
V_14 = 100000 ;
break;
case 1 :
V_14 = 133333 ;
break;
case 3 :
V_14 = 166667 ;
break;
case 2 :
V_14 = 200000 ;
break;
case 0 :
V_14 = 266667 ;
break;
case 4 :
V_14 = 333333 ;
break;
default:
F_7 ( L_7 ) ;
}
F_2 ( V_12 , V_8 , V_9 ) ;
F_3 ( L_8 ,
V_8 , V_9 ) ;
V_9 = ( V_8 >> 22 ) & 0x1f ;
F_3 ( L_6 ,
V_9 , ( V_9 * V_14 ) ) ;
V_15 = ( V_9 * V_14 ) ;
return V_15 ;
}
static unsigned int F_8 ( void )
{
struct V_17 * V_18 = & V_19 ;
T_2 V_8 , V_20 , V_21 ;
unsigned int V_14 = 0 ;
unsigned int V_15 ;
T_1 V_22 ;
if ( V_18 -> V_23 < 2 )
return V_24 ;
F_2 ( 0x2c , V_8 , V_20 ) ;
F_3 ( L_9 , V_8 , V_20 ) ;
V_22 = ( V_8 >> 16 ) & 0x7 ;
switch ( V_22 ) {
case 0 :
V_14 = 100 * 1000 ;
break;
case 1 :
V_14 = 13333 * 10 ;
break;
case 2 :
V_14 = 200 * 1000 ;
break;
}
if ( ! V_14 )
F_5 (KERN_DEBUG PFX L_10
L_11 ) ;
V_21 = V_8 >> 24 ;
F_3 ( L_12 ,
V_14 , V_21 , ( V_14 * V_21 ) ) ;
V_15 = ( V_14 * V_21 ) ;
return V_15 ;
}
unsigned int F_9 ( enum V_1 V_2 )
{
switch ( V_2 ) {
case V_25 :
return F_6 () ;
case V_26 :
return F_4 () ;
case V_27 :
case V_28 :
return F_8 () ;
case V_29 :
case V_30 :
case V_13 :
return F_1 ( V_2 ) ;
default:
return 0 ;
} ;
return 0 ;
}
unsigned int F_10 ( void )
{
struct V_17 * V_18 = & F_11 ( 0 ) ;
T_2 V_31 , V_8 , V_20 ;
F_3 ( L_13 , V_18 -> V_32 , V_18 -> V_23 ) ;
if ( ( V_18 -> V_33 != V_34 ) ||
( ( V_18 -> V_32 != 6 ) && ( V_18 -> V_32 != 0xF ) ) )
return 0 ;
if ( V_18 -> V_32 == 0xF ) {
if ( V_18 -> V_23 != 2 )
return 0 ;
V_31 = F_12 ( 0x00000001 ) ;
V_31 &= 0x000000FF ;
F_3 ( L_14 , V_31 , V_18 -> V_35 ) ;
switch ( V_18 -> V_35 ) {
case 4 :
if ( ( V_31 == 0x0e ) || ( V_31 == 0x0f ) )
return V_28 ;
break;
case 7 :
if ( V_31 == 0x0e )
return V_28 ;
break;
case 9 :
if ( ( V_31 == 0x0e ) ||
( strstr ( V_18 -> V_36 ,
L_15 ) != NULL ) )
return V_28 ;
break;
default:
break;
}
return 0 ;
}
switch ( V_18 -> V_23 ) {
case 0x0B :
V_31 = F_12 ( 0x00000001 ) ;
F_3 ( L_16 , V_31 ) ;
V_31 &= 0x000000FF ;
if ( V_31 != 0x06 )
return 0 ;
return V_29 ;
case 0x08 :
F_2 ( V_12 , V_8 , V_20 ) ;
F_3 ( L_17 ,
V_8 , V_20 ) ;
V_8 &= 0x00c0000 ;
if ( V_8 != 0x0080000 )
return 0 ;
F_2 ( V_37 , V_8 , V_20 ) ;
F_3 ( L_18 ,
V_8 , V_20 ) ;
if ( ( V_20 & ( 1 << 18 ) ) &&
( V_38 ? 1 : ( V_20 & ( 3 << 24 ) ) ) ) {
if ( V_18 -> V_35 == 0x01 ) {
F_3 ( L_19 ) ;
return V_13 ;
} else
return V_30 ;
}
default:
return 0 ;
}
}
unsigned int F_13 ( enum V_1 V_2 ,
unsigned int * V_39 ,
unsigned int * V_40 ,
unsigned int * V_41 ,
void (* F_14) ( unsigned int V_42 ) )
{
unsigned int V_43 ;
unsigned int V_15 = 0 ;
unsigned long V_44 ;
T_3 V_45 , V_46 ;
if ( ( ! V_2 ) || ( ! V_39 ) || ( ! V_40 ) || ( ! F_14 ) )
return - V_47 ;
F_3 ( L_20 ) ;
V_43 = F_9 ( V_2 ) ;
if ( ! V_43 )
return - V_48 ;
F_3 ( L_21 , V_43 ) ;
F_15 () ;
F_16 ( V_44 ) ;
F_14 ( V_49 ) ;
* V_39 = F_9 ( V_2 ) ;
if ( ! * V_39 ) {
V_15 = - V_48 ;
goto V_50;
}
F_3 ( L_22 , * V_39 ) ;
if ( V_41 )
V_45 = F_17 () ;
F_14 ( V_51 ) ;
if ( V_41 )
V_46 = F_17 () ;
* V_40 = F_9 ( V_2 ) ;
if ( ! * V_40 ) {
V_15 = - V_48 ;
goto V_50;
}
F_3 ( L_23 , * V_40 ) ;
if ( * V_39 == * V_40 ) {
V_15 = - V_52 ;
goto V_50;
}
if ( * V_40 != V_43 )
F_14 ( V_49 ) ;
if ( V_41 ) {
* V_41 = F_18 ( F_19 ( V_46 , V_45 ) ) ;
F_3 ( L_24 , * V_41 ) ;
* V_41 *= 1200 ;
if ( * V_41 > 10000000 ||
* V_41 < 50000 ) {
F_20 ( L_25 ,
* V_41 , 500000 ) ;
* V_41 = 500000 ;
}
}
V_50:
F_21 ( V_44 ) ;
F_22 () ;
return V_15 ;
}
