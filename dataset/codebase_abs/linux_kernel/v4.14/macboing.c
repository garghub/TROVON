static void F_1 ( void )
{
int V_1 ;
switch ( V_2 -> V_3 )
{
case V_4 :
V_5 = ( void * ) 0x50010000 ;
break;
case V_6 :
case V_7 :
V_8 = V_9 ;
V_10 = 22150 ;
break;
case V_11 :
case V_12 :
V_8 = V_13 ;
break;
case V_14 :
case V_15 :
case V_16 :
case V_17 :
case V_18 :
V_8 = NULL ;
break;
default:
V_8 = NULL ;
break;
}
for ( V_1 = 0 ; V_1 < 0x400 ; V_1 ++ )
{
V_19 [ V_1 ] = V_1 / 4 ;
V_19 [ V_1 + 0x400 ] = 0xFF - V_1 / 4 ;
}
V_20 = 1 ;
}
void F_2 ( unsigned int V_21 , unsigned int V_22 )
{
T_1 V_23 = ( V_21 << 5 ) / 468 ;
unsigned long V_24 ;
int V_1 ;
if ( V_8 == NULL )
{
return;
}
if ( ! V_20 )
F_1 () ;
if ( V_8 )
{
V_8 ( V_21 , V_22 , 128 ) ;
return;
}
if ( V_21 < 20 || V_21 > 20000 || V_22 == 0 )
{
F_3 ( 0 ) ;
return;
}
F_4 ( V_24 ) ;
F_5 ( & V_25 ) ;
for ( V_1 = 0 ; V_1 < 0x800 ; V_1 ++ )
V_5 [ V_1 ] = 0 ;
for ( V_1 = 0 ; V_1 < 0x800 ; V_1 ++ )
V_5 [ V_1 ] = V_19 [ V_1 ] ;
for ( V_1 = 0 ; V_1 < 8 ; V_1 ++ )
* ( T_1 * ) ( ( T_1 ) V_5 + V_26 + 0x814 + 8 * V_1 ) = V_23 ;
V_5 [ 0x807 ] = 0 ;
V_5 [ V_27 ] = 128 ;
V_5 [ 0x805 ] = 0 ;
V_5 [ 0x80F ] = 0 ;
V_5 [ V_28 ] = V_29 ;
V_5 [ V_30 ] = V_31 ;
V_25 . V_32 = V_33 + V_22 ;
F_6 ( & V_25 ) ;
F_7 ( V_24 ) ;
}
static void F_3 ( unsigned long V_34 )
{
V_5 [ V_30 ] = 0 ;
}
static void V_9 ( unsigned int V_21 , unsigned int V_22 , unsigned int V_35 )
{
unsigned long V_24 ;
if ( V_36 > 0 )
{
V_36 += V_22 ;
return;
}
V_36 = V_22 ;
V_37 = 0 ;
V_38 = ( V_21 * sizeof( V_19 ) ) / V_10 ;
F_4 ( V_24 ) ;
V_5 [ 0x806 ] = V_35 ;
if ( V_5 [ 0x801 ] != 1 )
{
V_5 [ 0x807 ] = 0 ;
V_5 [ 0x802 ] = 0 ;
V_5 [ 0x801 ] = 1 ;
V_5 [ 0x803 ] |= 0x80 ;
V_5 [ 0x803 ] &= 0x7F ;
}
V_25 . V_39 = V_40 ;
V_25 . V_32 = V_33 + 1 ;
F_6 ( & V_25 ) ;
F_7 ( V_24 ) ;
}
static void V_40 ( unsigned long V_34 )
{
int V_1 , V_41 = V_10 / V_42 ;
unsigned long V_24 ;
F_4 ( V_24 ) ;
F_5 ( & V_25 ) ;
if ( V_36 -- > 0 )
{
for ( V_1 = 0 ; V_1 < V_41 ; V_1 ++ )
{
V_37 += V_38 ;
V_5 [ 0 ] = V_19 [ V_37 & ( sizeof( V_19 ) - 1 ) ] ;
}
V_25 . V_32 = V_33 + 1 ;
F_6 ( & V_25 ) ;
}
else
V_5 [ 0x801 ] = 0 ;
F_7 ( V_24 ) ;
}
static void V_13 ( unsigned int V_21 , unsigned int V_22 , unsigned int V_35 )
{
}
