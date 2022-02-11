static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const T_1 * V_5 , unsigned int V_6 )
{
static const T_1 V_7 [] = {
0x11 , 0x22 , 0x33 , 0x44 ,
0xde , 0xad , 0xbe , 0xef ,
0xde , 0xad , 0xfa , 0xce
} ;
unsigned int V_8 , V_9 ;
T_1 * V_10 ;
int V_11 = 0 ;
if ( V_4 == NULL )
return 0 ;
if ( ( V_6 >= 14 && memcmp ( & V_5 [ 2 ] , V_7 , 12 ) == 0 ) ||
( V_6 >= 15 && memcmp ( & V_5 [ 3 ] , V_7 , 12 ) == 0 ) ) {
F_2 ( V_12 , L_1 ) ;
V_11 = 1 ;
}
if ( V_4 -> V_13 != V_14 ) {
if ( ! V_11 ) {
F_2 ( V_12 , L_2
L_3 ) ;
return 0 ;
}
V_4 -> V_13 = V_14 ;
}
if ( V_11 && V_4 -> V_4 . V_15 != 0 ) {
V_4 -> V_13 = V_16 ;
return - V_17 ;
}
if ( ! V_11 ) {
V_8 = V_4 -> V_4 . V_18 - V_4 -> V_4 . V_15 ;
V_10 = V_2 -> V_10 + V_4 -> V_4 . V_19 . V_20 + V_4 -> V_4 . V_15 ;
V_9 = F_3 ( V_6 , V_8 ) ;
memcpy ( V_10 , V_5 , V_9 ) ;
V_4 -> V_4 . V_15 += V_9 ;
if ( V_6 > V_8 || V_4 -> V_4 . V_15 == V_4 -> V_4 . V_18 ) {
F_2 ( V_12 , L_4
L_5 ) ;
V_4 -> V_13 = V_16 ;
}
}
return 0 ;
}
void F_4 ( struct V_21 * V_21 , struct V_22 * V_23 ,
struct V_3 * V_4 )
{
int V_24 , V_25 ;
for ( V_25 = 0 ; V_25 < V_21 -> V_26 ; ++ V_25 ) {
if ( V_21 -> V_27 [ V_25 ] . V_28 < 0 ) {
F_2 ( V_12 , L_6
L_7 ,
V_21 -> V_27 [ V_25 ] . V_28 ) ;
}
do {
V_24 = F_1 ( & V_23 -> V_2 , V_4 ,
V_21 -> V_29 +
V_21 -> V_27 [ V_25 ] . V_20 ,
V_21 -> V_27 [ V_25 ] . V_30 ) ;
if ( V_4 == NULL )
break;
if ( V_4 -> V_13 == V_16 ||
V_4 -> V_13 == V_31 )
V_4 = F_5 ( & V_23 -> V_2 ,
V_4 ) ;
} while ( V_24 == - V_17 );
}
}
