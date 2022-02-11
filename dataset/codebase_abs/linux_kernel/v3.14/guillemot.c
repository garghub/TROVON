static int F_1 ( struct V_1 * V_1 , T_1 * V_2 )
{
unsigned long V_3 ;
unsigned char V_4 , V_5 ;
unsigned int V_6 , V_7 ;
int V_8 ;
for ( V_8 = 0 ; V_8 < V_9 ; V_8 ++ )
V_2 [ V_8 ] = 0 ;
V_8 = 0 ;
V_6 = F_2 ( V_1 , V_10 ) ;
V_7 = F_2 ( V_1 , V_11 ) ;
F_3 ( V_3 ) ;
F_4 ( V_1 ) ;
V_5 = F_5 ( V_1 ) ;
while ( V_6 > 0 && V_8 < V_9 * 8 ) {
V_6 -- ;
V_4 = V_5 ; V_5 = F_5 ( V_1 ) ;
if ( V_5 & ~ V_4 & 0x10 ) {
V_2 [ V_8 >> 3 ] |= ( ( V_5 >> 5 ) & 1 ) << ( V_8 & 7 ) ;
V_8 ++ ;
V_6 = V_7 ;
}
}
F_6 ( V_3 ) ;
return V_8 ;
}
static void F_7 ( struct V_1 * V_1 )
{
struct V_12 * V_12 = F_8 ( V_1 ) ;
struct V_13 * V_14 = V_12 -> V_14 ;
T_1 V_2 [ V_9 ] ;
int V_8 ;
V_12 -> V_15 ++ ;
if ( F_1 ( V_12 -> V_1 , V_2 ) != V_9 * 8 ||
V_2 [ 0 ] != 0x55 || V_2 [ 16 ] != 0xaa ) {
V_12 -> V_16 ++ ;
} else {
for ( V_8 = 0 ; V_8 < 6 && V_12 -> type -> abs [ V_8 ] >= 0 ; V_8 ++ )
F_9 ( V_14 , V_12 -> type -> abs [ V_8 ] , V_2 [ V_8 + 5 ] ) ;
if ( V_12 -> type -> V_17 ) {
F_9 ( V_14 , V_18 , V_19 [ V_2 [ 4 ] >> 4 ] . V_20 ) ;
F_9 ( V_14 , V_21 , V_19 [ V_2 [ 4 ] >> 4 ] . V_22 ) ;
}
for ( V_8 = 0 ; V_8 < 16 && V_12 -> type -> V_23 [ V_8 ] >= 0 ; V_8 ++ )
F_10 ( V_14 , V_12 -> type -> V_23 [ V_8 ] , ( V_2 [ 2 + ( V_8 >> 3 ) ] >> ( V_8 & 7 ) ) & 1 ) ;
}
F_11 ( V_14 ) ;
}
static int F_12 ( struct V_13 * V_14 )
{
struct V_12 * V_12 = F_13 ( V_14 ) ;
F_14 ( V_12 -> V_1 ) ;
return 0 ;
}
static void F_15 ( struct V_13 * V_14 )
{
struct V_12 * V_12 = F_13 ( V_14 ) ;
F_16 ( V_12 -> V_1 ) ;
}
static int F_17 ( struct V_1 * V_1 , struct V_24 * V_25 )
{
struct V_12 * V_12 ;
struct V_13 * V_13 ;
T_1 V_2 [ V_9 ] ;
int V_8 , V_6 ;
int V_26 ;
V_12 = F_18 ( sizeof( struct V_12 ) , V_27 ) ;
V_13 = F_19 () ;
if ( ! V_12 || ! V_13 ) {
V_26 = - V_28 ;
goto V_29;
}
V_12 -> V_1 = V_1 ;
V_12 -> V_14 = V_13 ;
F_20 ( V_1 , V_12 ) ;
V_26 = F_21 ( V_1 , V_25 , V_30 ) ;
if ( V_26 )
goto V_29;
V_8 = F_1 ( V_1 , V_2 ) ;
if ( V_8 != V_9 * 8 || V_2 [ 0 ] != 0x55 || V_2 [ 16 ] != 0xaa ) {
V_26 = - V_31 ;
goto V_32;
}
for ( V_8 = 0 ; V_33 [ V_8 ] . V_34 ; V_8 ++ )
if ( V_33 [ V_8 ] . V_35 == V_2 [ 11 ] )
break;
if ( ! V_33 [ V_8 ] . V_34 ) {
F_22 ( V_36 L_1 ,
V_1 -> V_37 , V_2 [ 12 ] , V_2 [ 13 ] , V_2 [ 11 ] , V_2 [ 14 ] , V_2 [ 15 ] ) ;
V_26 = - V_31 ;
goto V_32;
}
F_23 ( V_1 , F_7 ) ;
F_24 ( V_1 , 20 ) ;
snprintf ( V_12 -> V_37 , sizeof( V_12 -> V_37 ) , L_2 , V_1 -> V_37 ) ;
V_12 -> type = V_33 + V_8 ;
V_13 -> V_34 = V_33 [ V_8 ] . V_34 ;
V_13 -> V_37 = V_12 -> V_37 ;
V_13 -> V_35 . V_38 = V_39 ;
V_13 -> V_35 . V_40 = V_41 ;
V_13 -> V_35 . V_42 = V_33 [ V_8 ] . V_35 ;
V_13 -> V_35 . V_43 = ( int ) V_2 [ 14 ] << 8 | V_2 [ 15 ] ;
V_13 -> V_14 . V_44 = & V_1 -> V_14 ;
F_25 ( V_13 , V_12 ) ;
V_13 -> V_45 = F_12 ;
V_13 -> V_46 = F_15 ;
V_13 -> V_47 [ 0 ] = F_26 ( V_48 ) | F_26 ( V_49 ) ;
for ( V_8 = 0 ; ( V_6 = V_12 -> type -> abs [ V_8 ] ) >= 0 ; V_8 ++ )
F_27 ( V_13 , V_6 , 0 , 255 , 0 , 0 ) ;
if ( V_12 -> type -> V_17 ) {
F_27 ( V_13 , V_18 , - 1 , 1 , 0 , 0 ) ;
F_27 ( V_13 , V_21 , - 1 , 1 , 0 , 0 ) ;
}
for ( V_8 = 0 ; ( V_6 = V_12 -> type -> V_23 [ V_8 ] ) >= 0 ; V_8 ++ )
F_28 ( V_6 , V_13 -> V_50 ) ;
V_26 = F_29 ( V_12 -> V_14 ) ;
if ( V_26 )
goto V_32;
return 0 ;
V_32: F_30 ( V_1 ) ;
V_29: F_20 ( V_1 , NULL ) ;
F_31 ( V_13 ) ;
F_32 ( V_12 ) ;
return V_26 ;
}
static void F_33 ( struct V_1 * V_1 )
{
struct V_12 * V_12 = F_8 ( V_1 ) ;
F_22 ( V_51 L_3 , V_12 -> V_15 , V_12 -> V_16 , V_12 -> V_37 ) ;
F_34 ( V_12 -> V_14 ) ;
F_30 ( V_1 ) ;
F_32 ( V_12 ) ;
}
