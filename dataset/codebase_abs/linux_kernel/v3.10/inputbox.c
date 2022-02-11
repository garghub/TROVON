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
int V_14 = 0 , V_15 = 0 , V_16 = - 1 ;
int V_17 , V_18 , V_19 ;
char * V_20 = V_21 ;
T_1 * V_1 ;
if ( ! V_9 )
V_20 [ 0 ] = '\0' ;
else
strcpy ( V_20 , V_9 ) ;
V_22:
if ( F_7 ( V_23 ) <= ( V_2 - 2 ) )
return - V_24 ;
if ( F_8 ( V_23 ) <= ( V_3 - 2 ) )
return - V_24 ;
V_5 = ( V_25 - V_3 ) / 2 ;
V_6 = ( V_26 - V_2 ) / 2 ;
F_9 ( V_23 , V_6 , V_5 , V_2 , V_3 ) ;
V_1 = F_10 ( V_2 , V_3 , V_6 , V_5 ) ;
F_11 ( V_1 , TRUE ) ;
F_12 ( V_1 , 0 , 0 , V_2 , V_3 ,
V_27 . V_1 . V_28 , V_27 . V_29 . V_28 ) ;
F_13 ( V_1 , V_27 . V_29 . V_28 ) ;
F_14 ( V_1 , V_2 - 3 , 0 , V_30 ) ;
for ( V_10 = 0 ; V_10 < V_3 - 2 ; V_10 ++ )
F_15 ( V_1 , V_31 ) ;
F_13 ( V_1 , V_27 . V_1 . V_28 ) ;
F_15 ( V_1 , V_32 ) ;
F_16 ( V_1 , V_7 , V_3 ) ;
F_13 ( V_1 , V_27 . V_1 . V_28 ) ;
F_17 ( V_1 , V_8 , V_3 - 2 , 1 , 3 ) ;
V_13 = V_3 - 6 ;
F_18 ( V_1 , V_6 , V_5 ) ;
V_11 = V_6 + 2 ;
V_12 = ( V_3 - V_13 ) / 2 ;
F_12 ( V_1 , V_6 + 1 , V_12 - 1 , 3 , V_13 + 2 ,
V_27 . V_1 . V_28 , V_27 . V_29 . V_28 ) ;
F_1 ( V_1 , V_2 , V_3 , 0 ) ;
F_4 ( V_1 , V_11 , V_12 ) ;
F_13 ( V_1 , V_27 . V_33 . V_28 ) ;
V_18 = strlen ( V_20 ) ;
V_19 = V_18 ;
if ( V_18 >= V_13 ) {
V_17 = V_18 - V_13 + 1 ;
V_14 = V_13 - 1 ;
for ( V_10 = 0 ; V_10 < V_13 - 1 ; V_10 ++ )
F_15 ( V_1 , V_20 [ V_17 + V_10 ] ) ;
} else {
V_17 = 0 ;
V_14 = V_18 ;
F_19 ( V_1 , V_20 ) ;
}
F_4 ( V_1 , V_11 , V_12 + V_14 ) ;
F_5 ( V_1 ) ;
while ( V_15 != V_34 ) {
V_15 = F_20 ( V_1 ) ;
if ( V_16 == - 1 ) {
switch ( V_15 ) {
case V_35 :
case V_36 :
case V_37 :
break;
case V_38 :
case 127 :
if ( V_19 ) {
F_13 ( V_1 , V_27 . V_33 . V_28 ) ;
if ( V_14 == 0 ) {
V_17 -- ;
} else
V_14 -- ;
if ( V_19 < V_18 ) {
for ( V_10 = V_19 - 1 ; V_10 < V_18 ; V_10 ++ ) {
V_20 [ V_10 ] = V_20 [ V_10 + 1 ] ;
}
}
V_19 -- ;
V_18 -- ;
V_20 [ V_18 ] = '\0' ;
F_4 ( V_1 , V_11 , V_12 ) ;
for ( V_10 = 0 ; V_10 < V_13 ; V_10 ++ ) {
if ( ! V_20 [ V_17 + V_10 ] ) {
F_15 ( V_1 , ' ' ) ;
break;
}
F_15 ( V_1 , V_20 [ V_17 + V_10 ] ) ;
}
F_4 ( V_1 , V_11 , V_14 + V_12 ) ;
F_5 ( V_1 ) ;
}
continue;
case V_39 :
if ( V_19 > 0 ) {
if ( V_14 > 0 ) {
F_4 ( V_1 , V_11 , -- V_14 + V_12 ) ;
} else if ( V_14 == 0 ) {
V_17 -- ;
F_4 ( V_1 , V_11 , V_12 ) ;
for ( V_10 = 0 ; V_10 < V_13 ; V_10 ++ ) {
if ( ! V_20 [ V_17 + V_10 ] ) {
F_15 ( V_1 , ' ' ) ;
break;
}
F_15 ( V_1 , V_20 [ V_17 + V_10 ] ) ;
}
F_4 ( V_1 , V_11 , V_12 ) ;
}
V_19 -- ;
}
continue;
case V_40 :
if ( V_19 < V_18 ) {
if ( V_14 < V_13 - 1 ) {
F_4 ( V_1 , V_11 , ++ V_14 + V_12 ) ;
} else if ( V_14 == V_13 - 1 ) {
V_17 ++ ;
F_4 ( V_1 , V_11 , V_12 ) ;
for ( V_10 = 0 ; V_10 < V_13 ; V_10 ++ ) {
if ( ! V_20 [ V_17 + V_10 ] ) {
F_15 ( V_1 , ' ' ) ;
break;
}
F_15 ( V_1 , V_20 [ V_17 + V_10 ] ) ;
}
F_4 ( V_1 , V_11 , V_14 + V_12 ) ;
}
V_19 ++ ;
}
continue;
default:
if ( V_15 < 0x100 && isprint ( V_15 ) ) {
if ( V_18 < V_41 ) {
F_13 ( V_1 , V_27 . V_33 . V_28 ) ;
if ( V_19 < V_18 ) {
for ( V_10 = V_18 ; V_10 > V_19 ; V_10 -- )
V_20 [ V_10 ] = V_20 [ V_10 - 1 ] ;
V_20 [ V_19 ] = V_15 ;
} else {
V_20 [ V_18 ] = V_15 ;
}
V_19 ++ ;
V_18 ++ ;
V_20 [ V_18 ] = '\0' ;
if ( V_14 == V_13 - 1 ) {
V_17 ++ ;
} else {
V_14 ++ ;
}
F_4 ( V_1 , V_11 , V_12 ) ;
for ( V_10 = 0 ; V_10 < V_13 ; V_10 ++ ) {
if ( ! V_20 [ V_17 + V_10 ] ) {
F_15 ( V_1 , ' ' ) ;
break;
}
F_15 ( V_1 , V_20 [ V_17 + V_10 ] ) ;
}
F_4 ( V_1 , V_11 , V_14 + V_12 ) ;
F_5 ( V_1 ) ;
} else
F_21 () ;
continue;
}
}
}
switch ( V_15 ) {
case 'O' :
case 'o' :
F_22 ( V_1 ) ;
return 0 ;
case 'H' :
case 'h' :
F_22 ( V_1 ) ;
return 1 ;
case V_36 :
case V_39 :
switch ( V_16 ) {
case - 1 :
V_16 = 1 ;
F_1 ( V_1 , V_2 , V_3 , 1 ) ;
break;
case 0 :
V_16 = - 1 ;
F_1 ( V_1 , V_2 , V_3 , 0 ) ;
F_4 ( V_1 , V_11 , V_12 + V_14 ) ;
F_5 ( V_1 ) ;
break;
case 1 :
V_16 = 0 ;
F_1 ( V_1 , V_2 , V_3 , 0 ) ;
break;
}
break;
case V_35 :
case V_37 :
case V_40 :
switch ( V_16 ) {
case - 1 :
V_16 = 0 ;
F_1 ( V_1 , V_2 , V_3 , 0 ) ;
break;
case 0 :
V_16 = 1 ;
F_1 ( V_1 , V_2 , V_3 , 1 ) ;
break;
case 1 :
V_16 = - 1 ;
F_1 ( V_1 , V_2 , V_3 , 0 ) ;
F_4 ( V_1 , V_11 , V_12 + V_14 ) ;
F_5 ( V_1 ) ;
break;
}
break;
case ' ' :
case '\n' :
F_22 ( V_1 ) ;
return ( V_16 == - 1 ? 0 : V_16 ) ;
case 'X' :
case 'x' :
V_15 = V_34 ;
break;
case V_34 :
V_15 = F_23 ( V_1 ) ;
break;
case V_42 :
F_22 ( V_1 ) ;
F_24 () ;
goto V_22;
}
}
F_22 ( V_1 ) ;
return V_34 ;
}
