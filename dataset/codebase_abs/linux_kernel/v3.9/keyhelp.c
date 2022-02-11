static void F_1 ( void )
{
T_1 * V_1 , V_2 [ V_3 ] , V_4 , V_5 ;
T_2 * V_6 = V_7 , V_8 ;
int V_9 , V_10 = 1 ;
V_11 = ( int ) ( V_12 [ - 1 ] ) ;
memset ( V_2 , 0 , sizeof( V_2 ) ) ;
memset ( V_13 , 0 , sizeof( V_13 ) ) ;
V_1 = V_12 + V_11 + 1 ;
while ( * V_1 ++ ) {
for ( V_9 = 0 ; V_9 < V_11 ; V_9 ++ , V_1 ++ ) {
if ( ! * V_1 )
continue;
if ( ( V_12 [ V_9 ] & 16 ) != 0 && * V_1 == V_14 )
continue;
V_2 [ * V_1 ] ++ ;
}
}
for ( V_9 = 0 ; V_9 < V_3 ; V_9 ++ ) {
if ( V_2 [ V_9 ] == 0 )
continue;
V_13 [ V_9 ] = V_10 ;
V_10 += ( V_2 [ V_9 ] + 1 ) ;
if ( V_10 >= V_15 )
break;
}
V_1 = V_12 + V_11 + 1 ;
while ( ( V_4 = * V_1 ++ ) ) {
for ( V_9 = 0 ; V_9 < V_11 ; V_9 ++ ) {
V_5 = * V_1 ++ ;
if ( ! V_5 )
continue;
if ( ( V_12 [ V_9 ] & 16 ) != 0 && V_5 == V_14 )
continue;
V_8 = ( V_12 [ V_9 ] << 8 ) + V_4 ;
V_2 [ V_5 ] -- ;
V_10 = V_13 [ V_5 ] ;
if ( ! V_10 )
continue;
V_6 = V_7 + V_10 + V_2 [ V_5 ] ;
* V_6 = V_8 ;
}
}
}
static void F_2 ( int V_8 )
{
int V_9 , V_16 = V_8 >> 8 ;
V_8 &= 0xff ;
for ( V_9 = 0 ; V_9 < 6 ; V_9 ++ ) {
if ( V_16 & V_17 [ V_9 ] )
F_3 ( L_1 , F_4 ( V_18 + V_9 ) ) ;
}
if ( ( V_8 > 0 ) && ( V_8 <= V_19 ) )
F_3 ( L_2 ,
F_4 ( V_20 + ( V_8 - 1 ) ) ) ;
}
static int F_5 ( void )
{
char V_21 = V_22 ;
int V_9 ;
int V_23 = V_24 - V_25 + 1 ;
V_12 = V_26 [ 0 ] + V_27 + 2 ;
for ( V_9 = 0 ; V_9 < V_23 ; V_9 ++ ) {
char * V_28 = F_4 ( V_25 + V_9 ) ;
if ( V_21 == * V_28 )
continue;
V_21 = * V_28 ;
V_29 [ ( V_21 & 31 ) - 1 ] = V_9 ;
}
return 0 ;
}
int F_6 ( struct V_30 * V_31 , T_1 type , T_1 V_4 , T_2 V_8 )
{
int V_9 , V_32 ;
char * V_33 ;
T_1 V_34 , * V_1 ;
T_2 * V_35 , V_36 ;
if ( V_29 [ 0 ] == - 1 )
F_5 () ;
if ( type == V_37 ) {
if ( V_4 == V_22 ) {
V_38 = NULL ;
F_3 ( L_3 , F_4 ( V_39 ) ) ;
return 1 ;
}
V_4 |= 32 ;
if ( V_4 < 'a' || V_4 > 'z' )
return - 1 ;
if ( V_29 [ V_4 - 'a' ] == - 1 ) {
F_3 ( F_4 ( V_40 ) , V_4 ) ;
F_3 ( L_4 ) ;
return 1 ;
}
V_41 = V_29 [ V_4 - 'a' ] ;
} else if ( type == V_42 ) {
if ( V_4 == 0
&& ( V_25 + V_41 + 1 ) <=
V_24 )
V_41 ++ ;
else if ( V_4 == 3 && V_41 > 0 )
V_41 -- ;
else
return - 1 ;
} else if ( type == V_43
&& V_4 == V_44
&& ! V_38 ) {
V_38 = F_6 ;
F_3 ( L_3 , F_4 ( V_45 ) ) ;
F_1 () ;
return 1 ;
} else {
V_33 = NULL ;
if ( ( type != V_43 ) && ( V_8 > 0 ) && ( V_8 <= V_19 ) ) {
F_3 ( L_3 ,
F_4 ( V_20 + V_8 - 1 ) ) ;
return 1 ;
}
for ( V_9 = 0 ; V_46 [ V_9 ] != 0 && ! V_33 ; V_9 ++ ) {
if ( V_4 == V_46 [ V_9 ] )
V_33 = F_4 ( V_25 + V_9 ) ;
}
if ( ! V_33 )
return - 1 ;
V_1 = V_26 [ V_8 ] + 1 ;
for ( V_9 = 0 ; V_9 < V_11 ; V_9 ++ ) {
if ( V_4 == V_1 [ V_9 ] )
break;
}
V_8 += ( V_12 [ V_9 ] << 8 ) ;
F_2 ( V_8 ) ;
F_3 ( F_4 ( V_47 ) , V_33 ) ;
F_3 ( L_4 ) ;
return 1 ;
}
V_33 = F_4 ( V_25 + V_41 ) ;
V_34 = V_46 [ V_41 ] ;
F_3 ( L_5 , V_33 ) ;
if ( V_13 [ V_34 ] == 0 ) {
F_3 ( L_2 , F_4 ( V_48 ) ) ;
return 1 ;
}
V_35 = V_7 + V_13 [ V_34 ] ;
for ( V_32 = 0 ; V_35 [ V_32 ] ; V_32 ++ ) {
V_36 = V_35 [ V_32 ] ;
if ( V_32 > 0 )
F_3 ( L_6 , F_4 ( V_49 ) ) ;
F_2 ( V_36 ) ;
}
return 1 ;
}
