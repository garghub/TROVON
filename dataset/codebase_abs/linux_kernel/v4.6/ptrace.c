void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 , V_3 ) ;
F_2 ( V_2 , V_4 ) ;
F_3 ( V_2 ) -> V_5 = 0 ;
F_3 ( V_2 ) -> V_6 = 0 ;
F_3 ( V_2 ) -> V_7 = 0 ;
F_3 ( V_2 ) -> V_8 = 0 ;
}
void F_4 ( struct V_1 * V_2 )
{
F_1 ( V_2 ) ;
}
void F_5 ( struct V_1 * V_2 )
{
F_2 ( V_2 , V_4 ) ;
F_6 ( V_2 , V_3 ) ;
if ( F_3 ( V_2 ) -> V_9 ) {
struct V_10 V_11 ;
F_7 ( V_2 ) -> V_12 [ 0 ] = F_7 ( V_2 ) -> V_12 [ 1 ] ;
F_7 ( V_2 ) -> V_13 [ 0 ] = F_7 ( V_2 ) -> V_13 [ 1 ] ;
F_7 ( V_2 ) -> V_12 [ 1 ] = F_7 ( V_2 ) -> V_12 [ 0 ] + 4 ;
F_3 ( V_2 ) -> V_9 = 0 ;
F_3 ( V_2 ) -> V_14 = 0 ;
F_3 ( V_2 ) -> V_15 = 0 ;
F_3 ( V_2 ) -> V_16 = 0 ;
F_3 ( V_2 ) -> V_17 = 0 ;
F_1 ( V_2 ) ;
V_11 . V_18 = V_19 ;
V_11 . V_20 = ( void V_21 * ) ( F_7 ( V_2 ) -> V_12 [ 0 ] & ~ 3 ) ;
V_11 . V_22 = V_23 ;
V_11 . V_24 = 0 ;
F_8 ( V_23 , & V_11 , V_2 ) ;
return;
}
F_3 ( V_2 ) -> V_5 = 1 ;
F_3 ( V_2 ) -> V_6 = 0 ;
F_3 ( V_2 ) -> V_7 = 0 ;
F_3 ( V_2 ) -> V_8 = 0 ;
}
void F_9 ( struct V_1 * V_2 )
{
F_2 ( V_2 , V_3 ) ;
F_6 ( V_2 , V_4 ) ;
F_3 ( V_2 ) -> V_5 = 0 ;
F_3 ( V_2 ) -> V_6 = 1 ;
F_3 ( V_2 ) -> V_7 = 0 ;
F_3 ( V_2 ) -> V_8 = 0 ;
}
long F_10 ( struct V_1 * V_25 , long V_26 ,
unsigned long V_27 , unsigned long V_28 )
{
unsigned long V_29 ;
long V_30 = - V_31 ;
switch ( V_26 ) {
case V_32 :
if ( ( V_27 & (sizeof( unsigned long ) - 1 ) ) ||
V_27 >= sizeof( struct V_33 ) )
break;
V_29 = * ( unsigned long * ) ( ( char * ) F_7 ( V_25 ) + V_27 ) ;
V_30 = F_11 ( V_29 , ( unsigned long V_21 * ) V_28 ) ;
break;
case V_34 :
if ( V_27 == V_35 ) {
V_28 &= V_36 ;
F_7 ( V_25 ) -> V_37 [ 0 ] &= ~ V_36 ;
F_7 ( V_25 ) -> V_37 [ 0 ] |= V_28 ;
V_30 = 0 ;
break;
}
if ( ( V_27 & (sizeof( unsigned long ) - 1 ) ) ||
V_27 >= sizeof( struct V_33 ) )
break;
if ( ( V_27 >= V_38 && V_27 <= V_39 ) ||
V_27 == V_40 || V_27 == V_41 ||
( V_27 >= V_42 && V_27 <= V_43 + 4 ) ||
V_27 == V_44 ) {
* ( unsigned long * ) ( ( char * ) F_7 ( V_25 ) + V_27 ) = V_28 ;
V_30 = 0 ;
}
break;
default:
V_30 = F_12 ( V_25 , V_26 , V_27 , V_28 ) ;
break;
}
return V_30 ;
}
static T_1 F_13 ( T_1 V_45 )
{
if ( V_45 < 0 )
return sizeof( struct V_33 ) ;
else if ( V_45 <= 32 * 4 )
return V_45 * 2 + 4 ;
else if ( V_45 <= 32 * 4 + 32 * 8 )
return V_45 + 32 * 4 ;
else if ( V_45 < sizeof( struct V_33 ) / 2 + 32 * 4 )
return V_45 * 2 + 4 - 32 * 8 ;
else
return sizeof( struct V_33 ) ;
}
long F_14 ( struct V_1 * V_25 , T_2 V_26 ,
T_1 V_27 , T_1 V_28 )
{
T_3 V_29 ;
long V_30 = - V_31 ;
switch ( V_26 ) {
case V_32 :
if ( V_27 & ( sizeof( T_3 ) - 1 ) )
break;
V_27 = F_13 ( V_27 ) ;
if ( V_27 >= sizeof( struct V_33 ) )
break;
V_29 = * ( T_3 * ) ( ( char * ) F_7 ( V_25 ) + V_27 ) ;
V_30 = F_11 ( V_29 , ( T_3 * ) ( unsigned long ) V_28 ) ;
break;
case V_34 :
if ( V_27 == V_35 ) {
V_30 = F_10 ( V_25 , V_26 , V_27 , V_28 ) ;
} else {
if ( V_27 & ( sizeof( T_3 ) - 1 ) )
break;
V_27 = F_13 ( V_27 ) ;
if ( V_27 >= sizeof( struct V_33 ) )
break;
if ( V_27 >= V_42 && V_27 <= V_43 + 4 ) {
* ( V_46 * ) ( ( char * ) F_7 ( V_25 ) + V_27 ) = V_28 ;
V_30 = 0 ;
}
else if ( ( V_27 >= V_38 + 4 && V_27 <= V_39 + 4 ) ||
V_27 == V_40 + 4 || V_27 == V_41 + 4 ||
V_27 == V_44 + 4 ) {
* ( V_47 * ) ( ( char * ) F_7 ( V_25 ) + V_27 - 4 ) = 0 ;
* ( V_47 * ) ( ( char * ) F_7 ( V_25 ) + V_27 ) = V_28 ;
V_30 = 0 ;
}
}
break;
default:
V_30 = F_15 ( V_25 , V_26 , V_27 , V_28 ) ;
break;
}
return V_30 ;
}
long F_16 ( struct V_33 * V_48 )
{
if ( F_17 () == - 1 )
return - 1 ;
if ( F_18 ( V_49 ) &&
F_19 ( V_48 ) ) {
V_48 -> V_37 [ 20 ] = - 1UL ;
goto V_50;
}
#ifdef F_20
if ( ! F_21 () )
F_22 ( V_48 -> V_37 [ 20 ] , V_48 -> V_37 [ 26 ] , V_48 -> V_37 [ 25 ] ,
V_48 -> V_37 [ 24 ] , V_48 -> V_37 [ 23 ] ) ;
else
#endif
F_22 ( V_48 -> V_37 [ 20 ] & 0xffffffff ,
V_48 -> V_37 [ 26 ] & 0xffffffff ,
V_48 -> V_37 [ 25 ] & 0xffffffff ,
V_48 -> V_37 [ 24 ] & 0xffffffff ,
V_48 -> V_37 [ 23 ] & 0xffffffff ) ;
V_50:
return ( int ) ( ( V_51 ) V_48 -> V_37 [ 20 ] ) ;
}
void F_23 ( struct V_33 * V_48 )
{
int V_52 = F_18 ( V_3 ) ||
F_18 ( V_4 ) ;
F_24 ( V_48 ) ;
if ( V_52 || F_18 ( V_49 ) )
F_25 ( V_48 , V_52 ) ;
}
