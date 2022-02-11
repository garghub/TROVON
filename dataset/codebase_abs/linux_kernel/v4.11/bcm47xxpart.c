static void F_1 ( struct V_1 * V_2 , const char * V_3 ,
T_1 V_4 , T_2 V_5 )
{
V_2 -> V_3 = V_3 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_5 = V_5 ;
}
static const char * F_2 ( struct V_6 * V_7 ,
T_3 V_4 )
{
T_2 V_8 ;
T_3 V_9 ;
int V_10 ;
V_10 = F_3 ( V_7 , V_4 , sizeof( V_8 ) , & V_9 ,
( V_11 * ) & V_8 ) ;
if ( V_10 && ! F_4 ( V_10 ) ) {
F_5 ( L_1 ,
V_4 , V_10 ) ;
goto V_12;
}
if ( V_8 == V_13 )
return L_2 ;
V_12:
return L_3 ;
}
static int F_6 ( struct V_6 * V_7 ,
struct V_1 * V_14 ,
struct V_1 * V_15 ,
T_3 V_16 )
{
struct V_17 V_18 ;
T_3 V_9 ;
int V_19 = 0 ;
int V_20 , V_10 ;
if ( V_16 < 3 ) {
F_7 ( L_4 ) ;
return - V_21 ;
}
V_10 = F_3 ( V_7 , V_14 -> V_4 , sizeof( V_18 ) , & V_9 ,
( V_11 * ) & V_18 ) ;
if ( V_10 && ! F_4 ( V_10 ) ) {
F_5 ( L_5 , V_10 ) ;
return V_10 ;
}
V_20 = 0 ;
if ( V_18 . V_4 [ 2 ] ) {
F_1 ( & V_15 [ V_19 ++ ] , L_6 ,
V_14 -> V_4 + V_18 . V_4 [ V_20 ] , 0 ) ;
V_20 ++ ;
}
if ( V_18 . V_4 [ V_20 ] ) {
F_1 ( & V_15 [ V_19 ++ ] , L_7 ,
V_14 -> V_4 + V_18 . V_4 [ V_20 ] , 0 ) ;
V_20 ++ ;
}
if ( V_18 . V_4 [ V_20 ] ) {
T_3 V_4 = V_14 -> V_4 + V_18 . V_4 [ V_20 ] ;
const char * V_3 = F_2 ( V_7 ,
V_4 ) ;
F_1 ( & V_15 [ V_19 ++ ] , V_3 , V_4 , 0 ) ;
V_20 ++ ;
}
for ( V_20 = 0 ; V_20 < V_19 ; V_20 ++ ) {
T_1 V_22 = ( V_20 < V_19 - 1 ) ?
V_15 [ V_20 + 1 ] . V_4 :
V_14 -> V_4 + V_14 -> V_23 ;
V_15 [ V_20 ] . V_23 = V_22 - V_15 [ V_20 ] . V_4 ;
}
return V_19 ;
}
static int F_8 ( void )
{
char V_8 [ 4 ] ;
int V_24 ;
if ( F_9 ( L_8 , V_8 , sizeof( V_8 ) ) > 0 ) {
if ( ! F_10 ( V_8 , 0 , & V_24 ) )
return V_24 ;
}
return 0 ;
}
static int F_11 ( struct V_6 * V_7 ,
const struct V_1 * * V_25 ,
struct V_26 * V_27 )
{
struct V_1 * V_15 ;
V_11 V_20 , V_19 = 0 ;
T_2 * V_8 ;
T_3 V_9 ;
T_2 V_4 ;
T_2 V_28 = V_7 -> V_29 ;
int V_30 [ 2 ] ;
int V_31 = 0 ;
int V_32 [] = { 0x8000 , 0xF000 , 0x10000 , } ;
int V_10 ;
if ( V_28 < 0x1000 )
V_28 = 0x1000 ;
V_15 = F_12 ( sizeof( struct V_1 ) * V_33 ,
V_34 ) ;
if ( ! V_15 )
return - V_21 ;
V_8 = F_12 ( V_35 , V_34 ) ;
if ( ! V_8 ) {
F_13 ( V_15 ) ;
return - V_21 ;
}
for ( V_4 = 0 ; V_4 <= V_7 -> V_23 - V_28 ;
V_4 += V_28 ) {
if ( F_14 ( V_36 ) && V_4 >= 0x2000000 )
break;
if ( V_19 >= V_33 ) {
F_7 ( L_9 ) ;
break;
}
V_10 = F_3 ( V_7 , V_4 , V_35 ,
& V_9 , ( V_11 * ) V_8 ) ;
if ( V_10 && ! F_4 ( V_10 ) ) {
F_5 ( L_1 ,
V_4 , V_10 ) ;
continue;
}
if ( ( V_8 [ 0x4e0 / 4 ] == V_37 && V_8 [ 0x4e4 / 4 ] == V_37 ) ||
( V_8 [ 0x400 / 4 ] == V_38 ) ) {
F_1 ( & V_15 [ V_19 ++ ] , L_10 ,
V_4 , V_39 ) ;
continue;
}
if ( V_8 [ 0x100 / 4 ] == V_40 ) {
F_1 ( & V_15 [ V_19 ++ ] , L_11 ,
V_4 , V_39 ) ;
continue;
}
if ( V_8 [ 0x000 / 4 ] == V_41 ) {
F_1 ( & V_15 [ V_19 ++ ] , L_12 ,
V_4 , V_39 ) ;
continue;
}
if ( V_8 [ 0x000 / 4 ] == V_42 &&
( V_8 [ 0x004 / 4 ] & 0xFFFF ) == V_43 ) {
F_1 ( & V_15 [ V_19 ++ ] , L_13 , V_4 ,
V_39 ) ;
continue;
}
if ( V_8 [ 0x010 / 4 ] == V_44 &&
V_8 [ 0x014 / 4 ] == V_45 ) {
F_1 ( & V_15 [ V_19 ++ ] , L_14 , V_4 ,
V_39 ) ;
continue;
}
if ( V_8 [ 0x000 / 4 ] == V_46 ) {
struct V_17 * V_14 ;
if ( V_31 >= F_15 ( V_30 ) )
F_7 ( L_15 ,
V_4 ) ;
else
V_30 [ V_31 ++ ] = V_19 ;
F_1 ( & V_15 [ V_19 ++ ] , L_16 ,
V_4 , 0 ) ;
V_14 = (struct V_17 * ) V_8 ;
V_4 = F_16 ( V_4 + V_14 -> V_47 , V_28 ) ;
V_4 -= V_28 ;
continue;
}
if ( F_17 ( V_8 [ 0x000 / 4 ] ) == V_48 ||
V_8 [ 0x000 / 4 ] == V_49 ) {
F_1 ( & V_15 [ V_19 ++ ] , L_3 ,
V_4 , 0 ) ;
continue;
}
if ( V_4 != V_7 -> V_23 - V_28 &&
V_8 [ 0x000 / 4 ] == V_38 ) {
F_1 ( & V_15 [ V_19 ++ ] , L_17 ,
V_4 , 0 ) ;
continue;
}
V_10 = F_3 ( V_7 , V_4 + 0x8000 , 0x4 , & V_9 ,
( V_11 * ) V_8 ) ;
if ( V_10 && ! F_4 ( V_10 ) ) {
F_5 ( L_1 ,
V_4 , V_10 ) ;
continue;
}
if ( V_8 [ 0x000 / 4 ] == V_50 ) {
F_1 ( & V_15 [ V_19 ++ ] , L_11 ,
V_4 , V_39 ) ;
continue;
}
}
for ( V_20 = 0 ; V_20 < F_15 ( V_32 ) ; V_20 ++ ) {
if ( V_19 >= V_33 ) {
F_7 ( L_9 ) ;
break;
}
V_4 = V_7 -> V_23 - V_32 [ V_20 ] ;
V_10 = F_3 ( V_7 , V_4 , 0x4 , & V_9 ,
( V_11 * ) V_8 ) ;
if ( V_10 && ! F_4 ( V_10 ) ) {
F_5 ( L_18 ,
V_4 , V_10 ) ;
continue;
}
if ( V_8 [ 0 ] == V_38 ) {
F_1 ( & V_15 [ V_19 ++ ] , L_17 ,
V_7 -> V_23 - V_28 , 0 ) ;
break;
}
}
F_13 ( V_8 ) ;
for ( V_20 = 0 ; V_20 < V_19 ; V_20 ++ ) {
T_1 V_22 = ( V_20 < V_19 - 1 ) ?
V_15 [ V_20 + 1 ] . V_4 : V_7 -> V_23 ;
V_15 [ V_20 ] . V_23 = V_22 - V_15 [ V_20 ] . V_4 ;
}
for ( V_20 = 0 ; V_20 < V_31 ; V_20 ++ ) {
struct V_1 * V_14 = & V_15 [ V_30 [ V_20 ] ] ;
if ( V_20 == F_8 () ) {
int V_51 ;
V_51 = F_6 ( V_7 , V_14 ,
V_15 + V_19 ,
V_33 - V_19 ) ;
if ( V_51 > 0 )
V_19 += V_51 ;
} else {
V_14 -> V_3 = L_19 ;
}
}
* V_25 = V_15 ;
return V_19 ;
}
