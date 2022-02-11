void F_1 ( int V_1 )
{
int V_2 ;
union V_3 V_4 ;
if ( F_2 ( V_5 ) || F_2 ( V_6 ) )
V_2 = 0xf ;
else
V_2 = 0x7 ;
V_4 . V_7 = F_3 ( F_4 ( V_1 ) ) ;
V_4 . V_8 . V_9 = V_2 ;
V_4 . V_8 . V_10 = V_2 ;
V_4 . V_8 . V_11 = V_2 ;
F_5 ( F_4 ( V_1 ) , V_4 . V_7 ) ;
}
void F_6 ( int V_12 )
{
union V_13 V_14 ;
union V_15 V_16 ;
int V_17 ;
int V_18 ;
V_14 . V_7 = F_3 ( F_7 ( V_12 ) ) ;
if ( F_2 ( V_19 ) || F_2 ( V_20 ) ) {
if ( V_14 . V_8 . V_21 ) {
switch ( V_14 . V_22 . V_14 ) {
case 1 :
V_17 = 1 ;
break;
case 2 :
case 3 :
V_17 = 4 ;
break;
default:
V_17 = 0 ;
break;
}
} else
V_17 = 0 ;
} else {
if ( V_14 . V_8 . V_21 ) {
if ( F_2 ( V_5 )
|| F_2 ( V_6 ) ) {
if ( V_14 . V_8 . type )
V_17 = 1 ;
else
V_17 = 4 ;
} else {
if ( V_14 . V_8 . type )
V_17 = 2 ;
else
V_17 = 3 ;
}
} else
V_17 = 0 ;
}
V_16 . V_7 = 0 ;
if ( V_17 ) {
if ( F_2 ( V_5 )
|| F_2 ( V_6 ) )
V_16 . V_8 . V_23 = 1 ;
V_16 . V_8 . V_24 = 1 ;
}
V_16 . V_8 . V_25 = ( 1 << V_17 ) - 1 ;
F_5 ( F_8 ( V_12 ) , V_16 . V_7 ) ;
for ( V_18 = 0 ; V_18 < V_17 ; V_18 ++ )
F_9 ( V_18 , V_12 ) ;
}
