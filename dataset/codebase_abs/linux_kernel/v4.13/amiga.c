static T_1 T_2
F_1 ( T_3 * V_1 , int V_2 )
{
T_2 V_3 = 0 ;
while ( V_2 -- )
V_3 += F_2 ( * V_1 ++ ) ;
return V_3 ;
}
int F_3 ( struct V_4 * V_5 )
{
T_4 V_6 ;
unsigned char * V_7 ;
struct V_8 * V_9 ;
struct V_10 * V_11 ;
int V_12 , V_13 , V_14 , V_15 , V_16 = 0 ;
int V_17 = 1 ;
int V_18 = 1 ;
char V_19 [ V_20 ] ;
for ( V_14 = 0 ; ; V_14 ++ , F_4 ( V_6 ) ) {
if ( V_14 == V_21 )
goto V_22;
V_7 = F_5 ( V_5 , V_14 , & V_6 ) ;
if ( ! V_7 ) {
if ( V_23 )
F_6 ( L_1 ,
F_7 ( V_5 -> V_24 , V_19 ) , V_14 ) ;
V_16 = - 1 ;
goto V_22;
}
if ( * ( T_3 * ) V_7 != F_8 ( V_25 ) )
continue;
V_9 = (struct V_8 * ) V_7 ;
if ( F_1 ( ( T_3 * ) V_7 , F_2 ( V_9 -> V_26 ) & 0x7F ) == 0 )
break;
* ( T_3 * ) ( V_7 + 0xdc ) = 0 ;
if ( F_1 ( ( T_3 * ) V_7 ,
F_2 ( V_9 -> V_26 ) & 0x7F ) == 0 ) {
F_6 ( L_2 ,
V_14 ) ;
break;
}
F_6 ( L_3 ,
F_7 ( V_5 -> V_24 , V_19 ) , V_14 ) ;
}
V_17 = F_2 ( V_9 -> V_27 ) / 512 ;
{
char V_28 [ 7 + 10 + 1 + 1 ] ;
snprintf ( V_28 , sizeof( V_28 ) , L_4 , V_17 * 512 ) ;
F_9 ( V_5 -> V_29 , V_28 , V_30 ) ;
}
V_14 = F_2 ( V_9 -> V_31 ) ;
F_4 ( V_6 ) ;
for ( V_15 = 1 ; V_14 > 0 && V_15 <= 16 ; V_15 ++ , F_4 ( V_6 ) ) {
V_14 *= V_17 ;
V_7 = F_5 ( V_5 , V_14 , & V_6 ) ;
if ( ! V_7 ) {
if ( V_23 )
F_6 ( L_5 ,
F_7 ( V_5 -> V_24 , V_19 ) , V_14 ) ;
V_16 = - 1 ;
goto V_22;
}
V_11 = (struct V_10 * ) V_7 ;
V_14 = F_2 ( V_11 -> V_32 ) ;
if ( V_11 -> V_33 != F_8 ( V_34 ) )
continue;
if ( F_1 ( ( T_3 * ) V_11 , F_2 ( V_11 -> V_35 ) & 0x7F ) != 0 )
continue;
V_13 = ( F_2 ( V_11 -> V_36 [ 10 ] ) + 1 -
F_2 ( V_11 -> V_36 [ 9 ] ) ) *
F_2 ( V_11 -> V_36 [ 3 ] ) *
F_2 ( V_11 -> V_36 [ 5 ] ) *
V_17 ;
if ( ! V_13 )
continue;
V_12 = F_2 ( V_11 -> V_36 [ 9 ] ) *
F_2 ( V_11 -> V_36 [ 3 ] ) *
F_2 ( V_11 -> V_36 [ 5 ] ) *
V_17 ;
F_10 ( V_5 , V_18 ++ , V_12 , V_13 ) ;
{
char V_37 [ 4 ] ;
char V_28 [ 42 ] ;
T_3 * V_38 = ( T_3 * ) V_37 ;
* V_38 = V_11 -> V_36 [ 16 ] ;
if ( V_37 [ 3 ] < ' ' )
snprintf ( V_28 , sizeof( V_28 ) , L_6 ,
V_37 [ 0 ] , V_37 [ 1 ] ,
V_37 [ 2 ] , V_37 [ 3 ] + '@' ) ;
else
snprintf ( V_28 , sizeof( V_28 ) , L_7 ,
V_37 [ 0 ] , V_37 [ 1 ] ,
V_37 [ 2 ] , V_37 [ 3 ] ) ;
F_9 ( V_5 -> V_29 , V_28 , V_30 ) ;
snprintf ( V_28 , sizeof( V_28 ) , L_8 ,
F_2 ( V_11 -> V_36 [ 6 ] ) ,
F_2 ( V_11 -> V_36 [ 4 ] ) ) ;
F_9 ( V_5 -> V_29 , V_28 , V_30 ) ;
}
V_16 = 1 ;
}
F_9 ( V_5 -> V_29 , L_9 , V_30 ) ;
V_22:
return V_16 ;
}
