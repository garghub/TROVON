static void F_1 ( struct V_1 * V_2 , T_1 V_3 ,
unsigned int V_4 , const T_1 * V_5 )
{
unsigned int V_6 ;
T_1 V_7 ;
F_2 ( V_2 , 0xfb ) ;
F_2 ( V_2 , 0xef ) ;
F_2 ( V_2 , V_3 ) ;
F_2 ( V_2 , V_4 ) ;
for ( V_6 = 0 ; V_6 < V_4 ; ++ V_6 )
F_2 ( V_2 , V_5 [ V_6 ] ) ;
V_7 = 0xfb + 0xef + V_3 + V_4 ;
for ( V_6 = 0 ; V_6 < V_4 ; ++ V_6 )
V_7 += V_5 [ V_6 ] ;
F_2 ( V_2 , V_7 ) ;
}
static void F_3 ( struct V_1 * V_2 ,
struct V_8 * V_9 )
{
T_1 V_10 ;
F_4 ( V_2 ) ;
V_10 = 0 ;
F_1 ( V_2 , 0x61 , 1 , & V_10 ) ;
V_10 = 1 ;
F_1 ( V_2 , 0x74 , 1 , & V_10 ) ;
F_1 ( V_2 , 0x54 , 5 , V_9 -> V_5 ) ;
}
void F_5 ( struct V_1 * V_2 , struct V_8 * V_9 )
{
V_9 -> V_5 [ 1 ] = V_11 ;
V_9 -> V_5 [ 4 ] = 1 ;
F_3 ( V_2 , V_9 ) ;
}
void F_6 ( struct V_1 * V_2 )
{
T_1 V_10 = 0 ;
F_1 ( V_2 , 0x74 , 1 , & V_10 ) ;
}
void F_7 ( struct V_1 * V_2 , struct V_8 * V_9 )
{
F_3 ( V_2 , V_9 ) ;
}
void F_8 ( unsigned int V_12 ,
struct V_13 * V_14 )
{
if ( V_12 == V_15 ) {
V_14 -> V_16 = V_17 |
V_18 |
V_19 |
V_20 ;
V_14 -> V_21 = 44100 ;
}
}
void F_9 ( struct V_1 * V_2 , struct V_8 * V_9 ,
struct V_22 * V_5 )
{
V_9 -> V_5 [ 0 ] = 0 ;
switch ( F_10 ( V_5 ) ) {
case 44100 :
V_9 -> V_5 [ 1 ] = V_23 ;
break;
case 48000 :
V_9 -> V_5 [ 1 ] = V_11 ;
break;
default:
V_9 -> V_5 [ 1 ] = V_24 ;
break;
case 192000 :
V_9 -> V_5 [ 1 ] = V_25 ;
break;
}
V_9 -> V_5 [ 2 ] = F_11 ( V_5 ) / 2 - 1 ;
if ( F_12 ( V_5 ) == V_26 )
V_9 -> V_5 [ 3 ] = 0 ;
else
V_9 -> V_5 [ 3 ] = 0xc0 ;
V_9 -> V_5 [ 4 ] = 1 ;
F_1 ( V_2 , 0x54 , 5 , V_9 -> V_5 ) ;
}
void F_13 ( struct V_1 * V_2 )
{
if ( V_2 -> V_27 >= 2 &&
V_2 -> V_28 [ V_2 -> V_27 - 2 ] == 'O' &&
V_2 -> V_28 [ V_2 -> V_27 - 1 ] == 'K' ) {
F_14 ( V_2 -> V_29 -> V_30 , L_1 ) ;
F_15 ( L_2 , V_31 ,
V_2 -> V_28 , V_2 -> V_27 ) ;
V_2 -> V_27 = 0 ;
}
}
