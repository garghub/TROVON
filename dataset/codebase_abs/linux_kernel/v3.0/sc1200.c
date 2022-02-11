static unsigned short F_1 ( void )
{
unsigned char V_1 , V_2 ;
unsigned int V_3 ;
V_1 = F_2 ( 0x903c ) ;
V_2 = F_2 ( 0x903d ) ;
if ( V_1 == 0x04 && V_2 < V_4 ) {
V_3 = V_5 ;
} else {
V_3 = F_3 ( 0x901e ) ;
V_3 >>= 8 ;
V_3 &= 0x03 ;
if ( V_3 == V_6 )
V_3 = V_5 ;
}
return V_3 ;
}
static void F_4 ( T_1 * V_7 , T_2 V_8 )
{
T_3 * V_9 = V_7 -> V_9 ;
struct V_10 * V_11 = F_5 ( V_9 -> V_12 ) ;
unsigned int V_13 = V_9 -> V_14 ? 0x50 : 0x40 , V_15 = 0 ;
F_6 ( V_11 , V_13 + 4 , & V_15 ) ;
V_15 = ( V_15 >> 31 ) & 1 ;
if ( V_15 )
V_15 += F_1 () ;
F_7 ( V_11 , V_13 + ( ( V_7 -> V_16 & 1 ) << 3 ) ,
V_17 [ V_15 ] [ V_8 ] ) ;
}
static T_2 F_8 ( T_1 * V_7 )
{
T_3 * V_9 = V_7 -> V_9 ;
T_1 * V_18 = F_9 ( V_7 ) ;
T_4 * V_19 ;
T_2 V_20 = V_9 -> V_21 ;
if ( V_18 == NULL )
goto V_22;
V_19 = V_18 -> V_23 ;
if ( F_10 ( V_19 ) && F_11 ( V_18 ) == 0 ) {
if ( ( V_19 [ V_24 ] & 4 ) &&
( V_19 [ V_25 ] & 7 ) )
goto V_22;
if ( V_19 [ V_26 ] & 7 )
V_20 = 0 ;
}
V_22:
return V_20 ;
}
static void F_12 ( T_3 * V_9 , T_1 * V_7 )
{
struct V_10 * V_12 = F_5 ( V_9 -> V_12 ) ;
unsigned int V_27 , V_28 ;
unsigned short V_3 ;
unsigned int V_13 = V_9 -> V_14 ? 0x50 : 0x40 ;
const T_2 V_29 = V_7 -> V_30 ;
static const T_5 V_31 [ 3 ] [ 3 ] = {
{ 0x00921250 , 0x00911140 , 0x00911030 } ,
{ 0x00932470 , 0x00922260 , 0x00922140 } ,
{ 0x009436a1 , 0x00933481 , 0x00923261 } ,
} ;
static const T_5 V_32 [ 3 ] [ 3 ] = {
{ 0x00077771 , 0x00012121 , 0x00002020 } ,
{ 0x000bbbb2 , 0x00024241 , 0x00013131 } ,
{ 0x000ffff3 , 0x00035352 , 0x00015151 } ,
} ;
V_3 = F_1 () ;
if ( V_29 >= V_33 )
V_28 = V_31 [ V_3 ] [ V_29 - V_33 ] ;
else
V_28 = V_32 [ V_3 ] [ V_29 - V_34 ] ;
if ( ( V_7 -> V_16 & 1 ) == 0 ) {
F_6 ( V_12 , V_13 + 4 , & V_27 ) ;
V_28 |= V_27 & 0x80000000 ;
F_7 ( V_12 , V_13 + 4 , V_28 ) ;
} else
F_7 ( V_12 , V_13 + 12 , V_28 ) ;
}
static int F_13 ( T_1 * V_7 )
{
T_3 * V_9 = V_7 -> V_9 ;
unsigned long V_35 = V_9 -> V_35 ;
T_2 V_36 ;
V_36 = F_2 ( V_35 + 2 ) ;
if ( ! ( V_36 & 4 ) )
F_14 ( L_1 ,
V_36 , ( ( V_36 & 7 ) != 4 ) , ( ( V_36 & 2 ) == 2 ) ) ;
F_15 ( V_36 | 0x1b , V_35 + 2 ) ;
F_15 ( F_2 ( V_35 ) & ~ 1 , V_35 ) ;
return ( V_36 & 7 ) != 4 ;
}
static void F_16 ( T_3 * V_9 , T_1 * V_7 )
{
int V_29 = - 1 ;
const T_2 V_8 = V_7 -> V_37 - V_38 ;
switch ( V_8 ) {
case 200 : V_29 = V_33 ; break;
case 201 : V_29 = V_39 ; break;
case 202 : V_29 = V_40 ; break;
case 100 : V_29 = V_34 ; break;
case 101 : V_29 = V_41 ; break;
case 102 : V_29 = V_42 ; break;
}
if ( V_29 != - 1 ) {
F_14 ( L_2 , V_7 -> V_43 ) ;
F_17 ( V_7 ) ;
if ( F_18 ( V_7 , V_29 ) == 0 &&
( V_7 -> V_44 & V_45 ) )
V_9 -> V_46 -> V_47 ( V_7 , 1 ) ;
return;
}
F_4 ( V_7 , V_8 ) ;
}
static int F_19 ( struct V_10 * V_12 , T_6 V_48 )
{
F_14 ( L_3 , V_48 . V_49 ) ;
if ( V_48 . V_49 == V_50 ) {
struct V_51 * V_52 = F_20 ( V_12 ) ;
struct V_53 * V_54 = V_52 -> V_55 ;
unsigned int V_56 ;
for ( V_56 = 0 ; V_56 < 8 ; V_56 ++ )
F_6 ( V_12 , 0x40 + V_56 * 4 , & V_54 -> V_57 [ V_56 ] ) ;
}
F_21 ( V_12 ) ;
F_22 ( V_12 , F_23 ( V_12 , V_48 ) ) ;
return 0 ;
}
static int F_24 ( struct V_10 * V_12 )
{
struct V_51 * V_52 = F_20 ( V_12 ) ;
struct V_53 * V_54 = V_52 -> V_55 ;
unsigned int V_56 ;
int V_58 ;
V_58 = F_25 ( V_12 ) ;
if ( V_58 )
return V_58 ;
for ( V_56 = 0 ; V_56 < 8 ; V_56 ++ )
F_7 ( V_12 , 0x40 + V_56 * 4 , V_54 -> V_57 [ V_56 ] ) ;
return 0 ;
}
static int T_7 F_26 ( struct V_10 * V_12 , const struct V_59 * V_23 )
{
struct V_53 * V_54 = NULL ;
int V_60 ;
#ifdef F_27
V_54 = F_28 ( sizeof( * V_54 ) , V_61 ) ;
if ( V_54 == NULL )
return - V_62 ;
#endif
V_60 = F_29 ( V_12 , & V_63 , V_54 ) ;
if ( V_60 )
F_30 ( V_54 ) ;
return V_60 ;
}
static int T_8 F_31 ( void )
{
return F_32 ( & V_64 ) ;
}
static void T_9 F_33 ( void )
{
F_34 ( & V_64 ) ;
}
