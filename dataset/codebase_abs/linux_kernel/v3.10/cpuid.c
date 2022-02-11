int F_1 ( unsigned int V_1 , struct V_2 * V_3 )
{
T_1 * V_4 ;
char V_5 [ 64 ] ;
unsigned int V_6 , V_7 ;
unsigned int V_8 = 0xffffff ;
unsigned int V_9 , V_10 ;
int V_11 = - V_12 ;
V_3 -> V_13 = V_14 ;
V_3 -> V_15 = V_8 ;
V_3 -> V_16 = V_8 ;
V_3 -> V_17 = V_8 ;
V_3 -> V_18 = 0 ;
V_4 = fopen ( L_1 , L_2 ) ;
if ( ! V_4 )
return - V_19 ;
while ( ! feof ( V_4 ) ) {
if ( ! fgets ( V_5 , 64 , V_4 ) )
continue;
V_5 [ 63 - 1 ] = '\0' ;
if ( ! strncmp ( V_5 , L_3 , 12 ) )
sscanf ( V_5 , L_4 , & V_6 ) ;
if ( V_6 != V_1 )
continue;
if ( ! strncmp ( V_5 , L_5 , 9 ) ) {
for ( V_7 = 1 ; V_7 < V_20 ; V_7 ++ ) {
if ( strstr ( V_5 , V_21 [ V_7 ] ) )
V_3 -> V_13 = V_7 ;
}
} else if ( ! strncmp ( V_5 , L_6 , 13 ) ) {
sscanf ( V_5 , L_7 ,
& V_3 -> V_15 ) ;
} else if ( ! strncmp ( V_5 , L_8 , 9 ) ) {
sscanf ( V_5 , L_9 ,
& V_3 -> V_16 ) ;
} else if ( ! strncmp ( V_5 , L_10 , 10 ) ) {
sscanf ( V_5 , L_11 ,
& V_3 -> V_17 ) ;
if ( V_3 -> V_13 == V_14 ||
V_3 -> V_15 == V_8 ||
V_3 -> V_16 == V_8 ||
V_3 -> V_17 == V_8 ) {
V_11 = - V_12 ;
goto V_22;
}
V_11 = 0 ;
goto V_22;
}
}
V_11 = - V_23 ;
V_22:
fclose ( V_4 ) ;
if ( V_3 -> V_13 != V_24 &&
V_3 -> V_13 != V_25 )
return V_11 ;
V_9 = F_2 ( 0 ) ;
V_10 = F_2 ( 0x80000000 ) ;
if ( V_10 >= 0x80000007 &&
( F_3 ( 0x80000007 ) & ( 1 << 8 ) ) )
V_3 -> V_18 |= V_26 ;
if ( V_9 >= 6 && ( F_4 ( 6 ) & 0x1 ) )
V_3 -> V_18 |= V_27 ;
if ( V_3 -> V_13 == V_24 ) {
if ( V_10 >= 0x80000007 &&
( F_3 ( 0x80000007 ) & ( 1 << 9 ) ) )
V_3 -> V_18 |= V_28 ;
}
if ( V_3 -> V_13 == V_25 ) {
if ( V_9 >= 6 &&
( F_2 ( 6 ) & ( 1 << 1 ) ) )
V_3 -> V_18 |= V_29 ;
}
if ( V_3 -> V_13 == V_25 ) {
if ( V_9 >= 6 && ( F_4 ( 6 ) & ( 1 << 3 ) ) )
V_3 -> V_18 |= V_30 ;
if ( V_3 -> V_15 == 6 ) {
switch ( V_3 -> V_16 ) {
case 0x1A :
case 0x1E :
case 0x1F :
case 0x25 :
case 0x2C :
V_3 -> V_18 |= V_31 ;
case 0x2A :
case 0x2D :
case 0x3A :
case 0x3E :
V_3 -> V_18 |= V_31 ;
V_3 -> V_18 |= V_32 ;
break;
case 0x2E :
case 0x2F :
default:
break;
}
}
}
return V_11 ;
}
