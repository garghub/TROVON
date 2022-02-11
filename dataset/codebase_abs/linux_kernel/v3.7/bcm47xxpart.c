static void F_1 ( struct V_1 * V_2 , char * V_3 ,
T_1 V_4 , T_2 V_5 )
{
V_2 -> V_3 = V_3 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_5 = V_5 ;
}
static int F_2 ( struct V_6 * V_7 ,
struct V_1 * * V_8 ,
struct V_9 * V_10 )
{
struct V_1 * V_11 ;
T_3 V_12 , V_13 = 0 ;
T_2 * V_14 ;
T_4 V_15 ;
T_2 V_4 ;
T_2 V_16 = 0x10000 ;
struct V_17 * V_18 ;
V_11 = F_3 ( sizeof( struct V_1 ) * V_19 ,
V_20 ) ;
V_14 = F_3 ( V_21 , V_20 ) ;
for ( V_4 = 0 ; V_4 <= V_7 -> V_22 - V_16 ;
V_4 += V_16 ) {
if ( V_4 >= 0x2000000 )
break;
if ( V_13 > V_19 ) {
F_4 ( L_1 ) ;
break;
}
if ( F_5 ( V_7 , V_4 , V_21 ,
& V_15 , ( T_3 * ) V_14 ) < 0 ) {
F_6 ( L_2 ,
V_4 ) ;
continue;
}
if ( V_14 [ 0x400 / 4 ] == V_23 ) {
F_1 ( & V_11 [ V_13 ++ ] , L_3 ,
V_4 , V_24 ) ;
continue;
}
if ( V_14 [ 0x000 / 4 ] == V_23 ) {
F_1 ( & V_11 [ V_13 ++ ] , L_4 ,
V_4 , 0 ) ;
continue;
}
if ( V_14 [ 0x100 / 4 ] == V_25 ) {
F_1 ( & V_11 [ V_13 ++ ] , L_5 ,
V_4 , V_24 ) ;
continue;
}
if ( V_14 [ 0x000 / 4 ] == V_26 &&
( V_14 [ 0x004 / 4 ] & 0xFFFF ) == V_27 ) {
F_1 ( & V_11 [ V_13 ++ ] , L_6 , V_4 ,
V_24 ) ;
continue;
}
if ( V_14 [ 0x010 / 4 ] == V_28 &&
V_14 [ 0x014 / 4 ] == V_29 ) {
F_1 ( & V_11 [ V_13 ++ ] , L_7 , V_4 ,
V_24 ) ;
continue;
}
if ( V_14 [ 0x000 / 4 ] == V_30 ) {
V_18 = (struct V_17 * ) V_14 ;
V_12 = 0 ;
if ( V_18 -> V_4 [ 2 ] ) {
F_1 ( & V_11 [ V_13 ++ ] ,
L_8 ,
V_4 + V_18 -> V_4 [ V_12 ] ,
0 ) ;
V_12 ++ ;
}
F_1 ( & V_11 [ V_13 ++ ] , L_9 ,
V_4 + V_18 -> V_4 [ V_12 ] , 0 ) ;
V_12 ++ ;
F_1 ( & V_11 [ V_13 ++ ] , L_10 ,
V_4 + V_18 -> V_4 [ V_12 ] , 0 ) ;
V_12 ++ ;
V_4 = F_7 ( V_4 + V_18 -> V_31 , V_16 ) ;
continue;
}
}
F_8 ( V_14 ) ;
for ( V_12 = 0 ; V_12 < V_13 - 1 ; V_12 ++ )
V_11 [ V_12 ] . V_22 = V_11 [ V_12 + 1 ] . V_4 - V_11 [ V_12 ] . V_4 ;
if ( V_13 > 0 )
V_11 [ V_13 - 1 ] . V_22 =
V_7 -> V_22 - V_11 [ V_13 - 1 ] . V_4 ;
* V_8 = V_11 ;
return V_13 ;
}
static int T_5 F_9 ( void )
{
return F_10 ( & V_32 ) ;
}
static void T_6 F_11 ( void )
{
F_12 ( & V_32 ) ;
}
