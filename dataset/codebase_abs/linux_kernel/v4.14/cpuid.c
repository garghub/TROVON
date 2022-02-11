int F_1 ( struct V_1 * V_2 )
{
T_1 * V_3 ;
char V_4 [ 64 ] ;
unsigned int V_5 , V_6 ;
unsigned int V_7 = 0xffffff ;
unsigned int V_8 , V_9 ;
int V_10 = - V_11 ;
V_2 -> V_12 = V_13 ;
V_2 -> V_14 = V_7 ;
V_2 -> V_15 = V_7 ;
V_2 -> V_16 = V_7 ;
V_2 -> V_17 = 0 ;
V_3 = fopen ( L_1 , L_2 ) ;
if ( ! V_3 )
return - V_18 ;
while ( ! feof ( V_3 ) ) {
if ( ! fgets ( V_4 , 64 , V_3 ) )
continue;
V_4 [ 63 - 1 ] = '\0' ;
if ( ! strncmp ( V_4 , L_3 , 12 ) )
sscanf ( V_4 , L_4 , & V_5 ) ;
if ( V_5 != ( unsigned int ) V_19 )
continue;
if ( ! strncmp ( V_4 , L_5 , 9 ) ) {
for ( V_6 = 1 ; V_6 < V_20 ; V_6 ++ ) {
if ( strstr ( V_4 , V_21 [ V_6 ] ) )
V_2 -> V_12 = V_6 ;
}
} else if ( ! strncmp ( V_4 , L_6 , 13 ) ) {
sscanf ( V_4 , L_7 ,
& V_2 -> V_14 ) ;
} else if ( ! strncmp ( V_4 , L_8 , 9 ) ) {
sscanf ( V_4 , L_9 ,
& V_2 -> V_15 ) ;
} else if ( ! strncmp ( V_4 , L_10 , 10 ) ) {
sscanf ( V_4 , L_11 ,
& V_2 -> V_16 ) ;
if ( V_2 -> V_12 == V_13 ||
V_2 -> V_14 == V_7 ||
V_2 -> V_15 == V_7 ||
V_2 -> V_16 == V_7 ) {
V_10 = - V_11 ;
goto V_22;
}
V_10 = 0 ;
goto V_22;
}
}
V_10 = - V_23 ;
V_22:
fclose ( V_3 ) ;
if ( V_2 -> V_12 != V_24 &&
V_2 -> V_12 != V_25 )
return V_10 ;
V_8 = F_2 ( 0 ) ;
V_9 = F_2 ( 0x80000000 ) ;
if ( V_9 >= 0x80000007 &&
( F_3 ( 0x80000007 ) & ( 1 << 8 ) ) )
V_2 -> V_17 |= V_26 ;
if ( V_8 >= 6 && ( F_4 ( 6 ) & 0x1 ) )
V_2 -> V_17 |= V_27 ;
if ( V_2 -> V_12 == V_24 ) {
if ( V_9 >= 0x80000007 &&
( F_3 ( 0x80000007 ) & ( 1 << 9 ) ) )
V_2 -> V_17 |= V_28 ;
}
if ( V_2 -> V_12 == V_25 ) {
if ( V_8 >= 6 &&
( F_2 ( 6 ) & ( 1 << 1 ) ) )
V_2 -> V_17 |= V_29 ;
}
if ( V_2 -> V_12 == V_25 ) {
if ( V_8 >= 6 && ( F_4 ( 6 ) & ( 1 << 3 ) ) )
V_2 -> V_17 |= V_30 ;
if ( V_2 -> V_14 == 6 ) {
switch ( V_2 -> V_15 ) {
case 0x1A :
case 0x1E :
case 0x1F :
case 0x25 :
case 0x2C :
V_2 -> V_17 |= V_31 ;
break;
case 0x2A :
case 0x2D :
case 0x3A :
case 0x3E :
V_2 -> V_17 |= V_31 ;
V_2 -> V_17 |= V_32 ;
break;
case 0x2E :
case 0x2F :
default:
break;
}
}
}
return V_10 ;
}
