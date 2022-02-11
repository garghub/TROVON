T_1 void F_1 ( char * * V_1 )
{
long V_2 = 0 ;
T_2 * V_3 ;
while ( * V_1 ++ != NULL ) ;
for ( V_3 = ( T_2 * ) V_1 ; V_3 -> V_4 != V_5 ; V_3 ++ ) {
switch ( V_3 -> V_4 ) {
case V_6 :
V_7 = V_3 -> V_8 . V_9 ;
if ( V_7 < ( unsigned long ) V_1 )
V_7 = 0 ;
break;
case V_10 :
V_11 = V_3 -> V_8 . V_9 ;
if ( V_11 < ( unsigned long ) V_1 )
V_11 = 0 ;
break;
case V_12 :
V_13 = V_3 -> V_8 . V_9 ;
break;
case V_14 :
V_15 =
( char * ) ( long ) V_3 -> V_8 . V_9 ;
break;
case V_16 :
V_2 = V_3 -> V_8 . V_9 ;
break;
}
}
if ( ! V_7 || ! V_11 ||
! V_13 || ! V_15 ||
! V_2 || ( V_11 % V_2 ) ) {
V_7 = 0 ;
V_11 = 0 ;
V_13 = 0 ;
V_15 = L_1 ;
}
else {
V_17 = V_11 + V_2 ;
}
}
