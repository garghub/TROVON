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
F_3 ( V_10 ) * V_11 = ( F_3 ( V_10 ) * ) V_4 ;
if ( V_11 -> V_12 [ V_13 ] !=
( V_14 == 32 ? V_15 : V_16 ) ) {
return;
}
F_3 ( V_17 ) * V_18 = ( F_3 ( V_17 ) * ) ( V_7 . V_9 + V_11 -> V_19 ) ;
F_3 ( V_20 ) * V_21 = 0 ;
for ( V_5 = 0 ; V_5 < V_11 -> V_22 ; V_5 ++ )
{
if ( V_18 [ V_5 ] . V_23 == V_24 && ! V_6 ) {
V_6 = true ;
V_7 . V_25 = V_4
+ ( T_1 ) V_18 [ V_5 ] . V_26
- ( T_1 ) V_18 [ V_5 ] . V_27 ;
} else if ( V_18 [ V_5 ] . V_23 == V_28 ) {
V_21 = ( F_3 ( V_20 ) * ) ( V_4 + V_18 [ V_5 ] . V_26 ) ;
}
}
if ( ! V_6 || ! V_21 )
return;
F_3 ( V_29 ) * V_30 = 0 ;
V_7 . V_31 = 0 ;
V_7 . V_32 = 0 ;
V_7 . V_33 = 0 ;
V_7 . V_34 = 0 ;
for ( V_5 = 0 ; V_21 [ V_5 ] . V_35 != V_36 ; V_5 ++ ) {
switch ( V_21 [ V_5 ] . V_35 ) {
case V_37 :
V_7 . V_31 = ( const char * )
( ( T_1 ) V_21 [ V_5 ] . V_38 . V_39
+ V_7 . V_25 ) ;
break;
case V_40 :
V_7 . V_32 = ( F_3 ( V_41 ) * )
( ( T_1 ) V_21 [ V_5 ] . V_38 . V_39
+ V_7 . V_25 ) ;
break;
case V_42 :
V_30 = ( F_3 ( V_29 ) * )
( ( T_1 ) V_21 [ V_5 ] . V_38 . V_39
+ V_7 . V_25 ) ;
break;
case V_43 :
V_7 . V_33 = ( F_3 ( V_44 ) * )
( ( T_1 ) V_21 [ V_5 ] . V_38 . V_39
+ V_7 . V_25 ) ;
break;
case V_45 :
V_7 . V_34 = ( F_3 ( V_46 ) * )
( ( T_1 ) V_21 [ V_5 ] . V_38 . V_39
+ V_7 . V_25 ) ;
break;
}
}
if ( ! V_7 . V_31 || ! V_7 . V_32 || ! V_30 )
return;
if ( ! V_7 . V_34 )
V_7 . V_33 = 0 ;
V_7 . V_47 = V_30 [ 0 ] ;
V_7 . V_48 = V_30 [ 1 ] ;
V_7 . V_49 = & V_30 [ 2 ] ;
V_7 . V_50 = & V_30 [ V_7 . V_47 + 2 ] ;
V_7 . V_8 = true ;
}
void * F_4 ( const char * V_51 , const char * V_1 )
{
unsigned long V_52 ;
if ( ! V_7 . V_8 )
return 0 ;
V_52 = F_1 ( V_51 ) ;
F_3 (Word) V_50 = V_7 . V_49 [ F_1 ( V_1 ) % V_7 . V_47 ] ;
for (; V_50 != V_53 ; V_50 = V_7 . V_50 [ V_50 ] ) {
F_3 ( V_41 ) * V_54 = & V_7 . V_32 [ V_50 ] ;
if ( F_5 ( V_54 -> V_55 ) != V_56 )
continue;
if ( F_6 ( V_54 -> V_55 ) != V_57 &&
F_6 ( V_54 -> V_55 ) != V_58 )
continue;
if ( V_54 -> V_59 == V_60 )
continue;
if ( strcmp ( V_1 , V_7 . V_31 + V_54 -> V_61 ) )
continue;
if ( V_7 . V_33
&& ! F_7 ( V_7 . V_33 [ V_50 ] ,
V_51 , V_52 ) )
continue;
return ( void * ) ( V_7 . V_25 + V_54 -> V_62 ) ;
}
return 0 ;
}
void F_8 ( void * V_63 )
{
F_3 ( V_64 ) * V_65 = V_63 ;
for ( int V_5 = 0 ; V_65 [ V_5 ] . V_66 != V_67 ; V_5 ++ )
{
if ( V_65 [ V_5 ] . V_66 == V_68 ) {
F_2 ( V_65 [ V_5 ] . V_69 . V_70 ) ;
return;
}
}
V_7 . V_8 = false ;
}
