static void F_1 ( struct V_1 * V_2 , const char * V_3 ,
T_1 V_4 , T_2 V_5 )
{
V_2 -> V_3 = V_3 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_5 = V_5 ;
}
static int F_2 ( void )
{
char V_6 [ 4 ] ;
int V_7 ;
if ( F_3 ( L_1 , V_6 , sizeof( V_6 ) ) > 0 ) {
if ( ! F_4 ( V_6 , 0 , & V_7 ) )
return V_7 ;
}
return 0 ;
}
static int F_5 ( struct V_8 * V_9 ,
const struct V_1 * * V_10 ,
struct V_11 * V_12 )
{
struct V_1 * V_13 ;
T_3 V_14 , V_15 = 0 ;
T_2 * V_6 ;
T_4 V_16 ;
T_2 V_4 ;
T_2 V_17 = V_9 -> V_18 ;
int V_19 [ 2 ] ;
int V_20 = 0 ;
int V_21 [] = { 0x8000 , 0xF000 , 0x10000 , } ;
int V_22 ;
if ( V_17 < 0x1000 )
V_17 = 0x1000 ;
V_13 = F_6 ( sizeof( struct V_1 ) * V_23 ,
V_24 ) ;
if ( ! V_13 )
return - V_25 ;
V_6 = F_6 ( V_26 , V_24 ) ;
if ( ! V_6 ) {
F_7 ( V_13 ) ;
return - V_25 ;
}
for ( V_4 = 0 ; V_4 <= V_9 -> V_27 - V_17 ;
V_4 += V_17 ) {
if ( F_8 ( V_28 ) && V_4 >= 0x2000000 )
break;
if ( V_15 >= V_23 ) {
F_9 ( L_2 ) ;
break;
}
V_22 = F_10 ( V_9 , V_4 , V_26 ,
& V_16 , ( T_3 * ) V_6 ) ;
if ( V_22 && ! F_11 ( V_22 ) ) {
F_12 ( L_3 ,
V_4 , V_22 ) ;
continue;
}
if ( ( V_6 [ 0x4e0 / 4 ] == V_29 && V_6 [ 0x4e4 / 4 ] == V_29 ) ||
( V_6 [ 0x400 / 4 ] == V_30 ) ) {
F_1 ( & V_13 [ V_15 ++ ] , L_4 ,
V_4 , V_31 ) ;
continue;
}
if ( V_6 [ 0x100 / 4 ] == V_32 ) {
F_1 ( & V_13 [ V_15 ++ ] , L_5 ,
V_4 , V_31 ) ;
continue;
}
if ( V_6 [ 0x000 / 4 ] == V_33 ) {
F_1 ( & V_13 [ V_15 ++ ] , L_6 ,
V_4 , V_31 ) ;
continue;
}
if ( V_6 [ 0x000 / 4 ] == V_34 &&
( V_6 [ 0x004 / 4 ] & 0xFFFF ) == V_35 ) {
F_1 ( & V_13 [ V_15 ++ ] , L_7 , V_4 ,
V_31 ) ;
continue;
}
if ( V_6 [ 0x010 / 4 ] == V_36 &&
V_6 [ 0x014 / 4 ] == V_37 ) {
F_1 ( & V_13 [ V_15 ++ ] , L_8 , V_4 ,
V_31 ) ;
continue;
}
if ( V_6 [ 0x000 / 4 ] == V_38 ) {
struct V_39 * V_40 ;
if ( V_20 >= F_13 ( V_19 ) )
F_9 ( L_9 ,
V_4 ) ;
else
V_19 [ V_20 ++ ] = V_15 ;
F_1 ( & V_13 [ V_15 ++ ] , L_10 ,
V_4 , 0 ) ;
V_40 = (struct V_39 * ) V_6 ;
V_4 = F_14 ( V_4 + V_40 -> V_41 , V_17 ) ;
V_4 -= V_17 ;
continue;
}
if ( F_15 ( V_6 [ 0x000 / 4 ] ) == V_42 ||
V_6 [ 0x000 / 4 ] == V_43 ) {
F_1 ( & V_13 [ V_15 ++ ] , L_11 ,
V_4 , 0 ) ;
continue;
}
if ( V_4 != V_9 -> V_27 - V_17 &&
V_6 [ 0x000 / 4 ] == V_30 ) {
F_1 ( & V_13 [ V_15 ++ ] , L_12 ,
V_4 , 0 ) ;
continue;
}
V_22 = F_10 ( V_9 , V_4 + 0x8000 , 0x4 , & V_16 ,
( T_3 * ) V_6 ) ;
if ( V_22 && ! F_11 ( V_22 ) ) {
F_12 ( L_3 ,
V_4 , V_22 ) ;
continue;
}
if ( V_6 [ 0x000 / 4 ] == V_44 ) {
F_1 ( & V_13 [ V_15 ++ ] , L_5 ,
V_4 , V_31 ) ;
continue;
}
}
for ( V_14 = 0 ; V_14 < F_13 ( V_21 ) ; V_14 ++ ) {
if ( V_15 >= V_23 ) {
F_9 ( L_2 ) ;
break;
}
V_4 = V_9 -> V_27 - V_21 [ V_14 ] ;
V_22 = F_10 ( V_9 , V_4 , 0x4 , & V_16 ,
( T_3 * ) V_6 ) ;
if ( V_22 && ! F_11 ( V_22 ) ) {
F_12 ( L_13 ,
V_4 , V_22 ) ;
continue;
}
if ( V_6 [ 0 ] == V_30 ) {
F_1 ( & V_13 [ V_15 ++ ] , L_12 ,
V_9 -> V_27 - V_17 , 0 ) ;
break;
}
}
F_7 ( V_6 ) ;
for ( V_14 = 0 ; V_14 < V_15 ; V_14 ++ ) {
T_1 V_45 = ( V_14 < V_15 - 1 ) ?
V_13 [ V_14 + 1 ] . V_4 : V_9 -> V_27 ;
V_13 [ V_14 ] . V_27 = V_45 - V_13 [ V_14 ] . V_4 ;
}
for ( V_14 = 0 ; V_14 < V_20 ; V_14 ++ ) {
struct V_1 * V_40 = & V_13 [ V_19 [ V_14 ] ] ;
if ( V_14 == F_2 () )
V_40 -> V_46 = V_47 ;
else
V_40 -> V_3 = L_14 ;
}
* V_10 = V_13 ;
return V_15 ;
}
