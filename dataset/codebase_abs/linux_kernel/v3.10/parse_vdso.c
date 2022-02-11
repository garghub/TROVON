static unsigned long F_1 ( const unsigned char * V_1 )
{
unsigned long V_2 = 0 , V_3 ;
while ( * V_1 )
{
V_2 = ( V_2 << 4 ) + * V_1 ++ ;
if ( V_3 = V_2 & 0xf0000000 )
V_2 ^= V_3 >> 24 ;
V_2 &= ~ V_3 ;
}
return V_2 ;
}
void F_2 ( T_1 V_4 )
{
T_2 V_5 ;
bool V_6 = false ;
V_7 . V_8 = false ;
V_7 . V_9 = V_4 ;
T_3 * V_10 = ( T_3 * ) V_4 ;
T_4 * V_11 = ( T_4 * ) ( V_7 . V_9 + V_10 -> V_12 ) ;
T_5 * V_13 = 0 ;
for ( V_5 = 0 ; V_5 < V_10 -> V_14 ; V_5 ++ )
{
if ( V_11 [ V_5 ] . V_15 == V_16 && ! V_6 ) {
V_6 = true ;
V_7 . V_17 = V_4
+ ( T_1 ) V_11 [ V_5 ] . V_18
- ( T_1 ) V_11 [ V_5 ] . V_19 ;
} else if ( V_11 [ V_5 ] . V_15 == V_20 ) {
V_13 = ( T_5 * ) ( V_4 + V_11 [ V_5 ] . V_18 ) ;
}
}
if ( ! V_6 || ! V_13 )
return;
T_6 * V_21 = 0 ;
V_7 . V_22 = 0 ;
V_7 . V_23 = 0 ;
V_7 . V_24 = 0 ;
V_7 . V_25 = 0 ;
for ( V_5 = 0 ; V_13 [ V_5 ] . V_26 != V_27 ; V_5 ++ ) {
switch ( V_13 [ V_5 ] . V_26 ) {
case V_28 :
V_7 . V_22 = ( const char * )
( ( T_1 ) V_13 [ V_5 ] . V_29 . V_30
+ V_7 . V_17 ) ;
break;
case V_31 :
V_7 . V_23 = ( V_32 * )
( ( T_1 ) V_13 [ V_5 ] . V_29 . V_30
+ V_7 . V_17 ) ;
break;
case V_33 :
V_21 = ( T_6 * )
( ( T_1 ) V_13 [ V_5 ] . V_29 . V_30
+ V_7 . V_17 ) ;
break;
case V_34 :
V_7 . V_24 = ( V_35 * )
( ( T_1 ) V_13 [ V_5 ] . V_29 . V_30
+ V_7 . V_17 ) ;
break;
case V_36 :
V_7 . V_25 = ( V_37 * )
( ( T_1 ) V_13 [ V_5 ] . V_29 . V_30
+ V_7 . V_17 ) ;
break;
}
}
if ( ! V_7 . V_22 || ! V_7 . V_23 || ! V_21 )
return;
if ( ! V_7 . V_25 )
V_7 . V_24 = 0 ;
V_7 . V_38 = V_21 [ 0 ] ;
V_7 . V_39 = V_21 [ 1 ] ;
V_7 . V_40 = & V_21 [ 2 ] ;
V_7 . V_41 = & V_21 [ V_7 . V_38 + 2 ] ;
V_7 . V_8 = true ;
}
static bool F_3 ( V_35 V_42 ,
const char * V_1 , T_6 V_21 )
{
V_42 &= 0x7fff ;
V_37 * V_43 = V_7 . V_25 ;
while( true ) {
if ( ( V_43 -> V_44 & V_45 ) == 0
&& ( V_43 -> V_46 & 0x7fff ) == V_42 )
break;
if ( V_43 -> V_47 == 0 )
return false ;
V_43 = ( V_37 * ) ( ( char * ) V_43 + V_43 -> V_47 ) ;
}
T_7 * V_48 = ( T_7 * ) ( ( char * ) V_43 + V_43 -> V_49 ) ;
return V_43 -> V_50 == V_21
&& ! strcmp ( V_1 , V_7 . V_22 + V_48 -> V_51 ) ;
}
void * F_4 ( const char * V_52 , const char * V_1 )
{
unsigned long V_53 ;
if ( ! V_7 . V_8 )
return 0 ;
V_53 = F_1 ( V_52 ) ;
T_6 V_41 = V_7 . V_40 [ F_1 ( V_1 ) % V_7 . V_38 ] ;
for (; V_41 != V_54 ; V_41 = V_7 . V_41 [ V_41 ] ) {
V_32 * V_55 = & V_7 . V_23 [ V_41 ] ;
if ( F_5 ( V_55 -> V_56 ) != V_57 )
continue;
if ( F_6 ( V_55 -> V_56 ) != V_58 &&
F_6 ( V_55 -> V_56 ) != V_59 )
continue;
if ( V_55 -> V_60 == V_61 )
continue;
if ( strcmp ( V_1 , V_7 . V_22 + V_55 -> V_62 ) )
continue;
if ( V_7 . V_24
&& ! F_3 ( V_7 . V_24 [ V_41 ] ,
V_52 , V_53 ) )
continue;
return ( void * ) ( V_7 . V_17 + V_55 -> V_63 ) ;
}
return 0 ;
}
void F_7 ( void * V_64 )
{
T_8 * V_65 = V_64 ;
for ( int V_5 = 0 ; V_65 [ V_5 ] . V_66 != V_67 ; V_5 ++ )
{
if ( V_65 [ V_5 ] . V_66 == V_68 ) {
F_2 ( V_65 [ V_5 ] . V_69 . V_70 ) ;
return;
}
}
V_7 . V_8 = false ;
}
