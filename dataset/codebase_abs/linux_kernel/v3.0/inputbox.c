static void F_1 ( T_1 * V_1 , int V_2 , int V_3 , int V_4 )
{
int V_5 = V_3 / 2 - 11 ;
int V_6 = V_2 - 2 ;
F_2 ( V_1 , F_3 ( L_1 ) , V_6 , V_5 , V_4 == 0 ) ;
F_2 ( V_1 , F_3 ( L_2 ) , V_6 , V_5 + 14 , V_4 == 1 ) ;
F_4 ( V_1 , V_6 , V_5 + 1 + 14 * V_4 ) ;
F_5 ( V_1 ) ;
}
int F_6 ( const char * V_7 , const char * V_8 , int V_2 , int V_3 ,
const char * V_9 )
{
int V_10 , V_5 , V_6 , V_11 , V_12 , V_13 ;
int V_14 = 0 , V_15 = 0 , V_16 = 0 , V_17 = - 1 ;
char * V_18 = V_19 ;
T_1 * V_1 ;
if ( ! V_9 )
V_18 [ 0 ] = '\0' ;
else
strcpy ( V_18 , V_9 ) ;
V_20:
if ( F_7 ( V_21 ) <= ( V_2 - 2 ) )
return - V_22 ;
if ( F_8 ( V_21 ) <= ( V_3 - 2 ) )
return - V_22 ;
V_5 = ( V_23 - V_3 ) / 2 ;
V_6 = ( V_24 - V_2 ) / 2 ;
F_9 ( V_21 , V_6 , V_5 , V_2 , V_3 ) ;
V_1 = F_10 ( V_2 , V_3 , V_6 , V_5 ) ;
F_11 ( V_1 , TRUE ) ;
F_12 ( V_1 , 0 , 0 , V_2 , V_3 ,
V_25 . V_1 . V_26 , V_25 . V_27 . V_26 ) ;
F_13 ( V_1 , V_25 . V_27 . V_26 ) ;
F_14 ( V_1 , V_2 - 3 , 0 , V_28 ) ;
for ( V_10 = 0 ; V_10 < V_3 - 2 ; V_10 ++ )
F_15 ( V_1 , V_29 ) ;
F_13 ( V_1 , V_25 . V_1 . V_26 ) ;
F_15 ( V_1 , V_30 ) ;
F_16 ( V_1 , V_7 , V_3 ) ;
F_13 ( V_1 , V_25 . V_1 . V_26 ) ;
F_17 ( V_1 , V_8 , V_3 - 2 , 1 , 3 ) ;
V_13 = V_3 - 6 ;
F_18 ( V_1 , V_6 , V_5 ) ;
V_11 = V_6 + 2 ;
V_12 = ( V_3 - V_13 ) / 2 ;
F_12 ( V_1 , V_6 + 1 , V_12 - 1 , 3 , V_13 + 2 ,
V_25 . V_1 . V_26 , V_25 . V_27 . V_26 ) ;
F_1 ( V_1 , V_2 , V_3 , 0 ) ;
F_4 ( V_1 , V_11 , V_12 ) ;
F_13 ( V_1 , V_25 . V_31 . V_26 ) ;
V_14 = strlen ( V_18 ) ;
if ( V_14 >= V_13 ) {
V_15 = V_14 - V_13 + 1 ;
V_14 = V_13 - 1 ;
for ( V_10 = 0 ; V_10 < V_13 - 1 ; V_10 ++ )
F_15 ( V_1 , V_18 [ V_15 + V_10 ] ) ;
} else {
F_19 ( V_1 , V_18 ) ;
}
F_4 ( V_1 , V_11 , V_12 + V_14 ) ;
F_5 ( V_1 ) ;
while ( V_16 != V_32 ) {
V_16 = F_20 ( V_1 ) ;
if ( V_17 == - 1 ) {
switch ( V_16 ) {
case V_33 :
case V_34 :
case V_35 :
break;
case V_36 :
continue;
case V_37 :
continue;
case V_38 :
case 127 :
if ( V_14 || V_15 ) {
F_13 ( V_1 , V_25 . V_31 . V_26 ) ;
if ( ! V_14 ) {
V_15 = V_15 < V_13 - 1 ? 0 : V_15 - ( V_13 - 1 ) ;
F_4 ( V_1 , V_11 , V_12 ) ;
for ( V_10 = 0 ; V_10 < V_13 ; V_10 ++ )
F_15 ( V_1 ,
V_18 [ V_15 + V_14 + V_10 ] ?
V_18 [ V_15 + V_14 + V_10 ] : ' ' ) ;
V_14 = strlen ( V_18 ) - V_15 ;
} else
V_14 -- ;
V_18 [ V_15 + V_14 ] = '\0' ;
F_14 ( V_1 , V_11 , V_14 + V_12 , ' ' ) ;
F_4 ( V_1 , V_11 , V_14 + V_12 ) ;
F_5 ( V_1 ) ;
}
continue;
default:
if ( V_16 < 0x100 && isprint ( V_16 ) ) {
if ( V_15 + V_14 < V_39 ) {
F_13 ( V_1 , V_25 . V_31 . V_26 ) ;
V_18 [ V_15 + V_14 ] = V_16 ;
V_18 [ V_15 + V_14 + 1 ] = '\0' ;
if ( V_14 == V_13 - 1 ) {
V_15 ++ ;
F_4 ( V_1 , V_11 , V_12 ) ;
for ( V_10 = 0 ; V_10 < V_13 - 1 ; V_10 ++ )
F_15 ( V_1 , V_18 [ V_15 + V_10 ] ) ;
} else {
F_4 ( V_1 , V_11 , V_14 ++ + V_12 ) ;
F_15 ( V_1 , V_16 ) ;
}
F_5 ( V_1 ) ;
} else
F_21 () ;
continue;
}
}
}
switch ( V_16 ) {
case 'O' :
case 'o' :
F_22 ( V_1 ) ;
return 0 ;
case 'H' :
case 'h' :
F_22 ( V_1 ) ;
return 1 ;
case V_34 :
case V_36 :
switch ( V_17 ) {
case - 1 :
V_17 = 1 ;
F_1 ( V_1 , V_2 , V_3 , 1 ) ;
break;
case 0 :
V_17 = - 1 ;
F_1 ( V_1 , V_2 , V_3 , 0 ) ;
F_4 ( V_1 , V_11 , V_12 + V_14 ) ;
F_5 ( V_1 ) ;
break;
case 1 :
V_17 = 0 ;
F_1 ( V_1 , V_2 , V_3 , 0 ) ;
break;
}
break;
case V_33 :
case V_35 :
case V_37 :
switch ( V_17 ) {
case - 1 :
V_17 = 0 ;
F_1 ( V_1 , V_2 , V_3 , 0 ) ;
break;
case 0 :
V_17 = 1 ;
F_1 ( V_1 , V_2 , V_3 , 1 ) ;
break;
case 1 :
V_17 = - 1 ;
F_1 ( V_1 , V_2 , V_3 , 0 ) ;
F_4 ( V_1 , V_11 , V_12 + V_14 ) ;
F_5 ( V_1 ) ;
break;
}
break;
case ' ' :
case '\n' :
F_22 ( V_1 ) ;
return ( V_17 == - 1 ? 0 : V_17 ) ;
case 'X' :
case 'x' :
V_16 = V_32 ;
break;
case V_32 :
V_16 = F_23 ( V_1 ) ;
break;
case V_40 :
F_22 ( V_1 ) ;
F_24 () ;
goto V_20;
}
}
F_22 ( V_1 ) ;
return V_32 ;
}
