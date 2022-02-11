static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_5 ;
static const T_1 V_6 [ 3 ] = { 0x00 , 0x1f , 0xdf } ;
int V_7 ;
V_7 = 1 ;
for ( V_5 = 0 ; V_5 < 6 ; V_5 ++ ) {
if ( V_2 -> V_8 [ V_5 ] != 0x00 ) {
V_7 = 0 ;
break;
}
}
if ( V_7 ) {
F_2 ( V_2 -> V_9 , L_1 ) ;
memcpy ( V_2 -> V_8 , V_6 , 3 ) ;
F_3 ( V_2 -> V_8 + 3 , 3 ) ;
}
for ( V_5 = 0 ; V_5 < 6 ; V_5 ++ )
V_4 -> V_10 [ 9 - V_5 ] = V_2 -> V_8 [ V_5 ] ;
return 0 ;
}
void F_4 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_3 * V_11 ;
int V_12 ;
unsigned long V_13 ;
if ( V_4 -> V_10 [ 5 ] != 0x00 ) {
F_5 ( V_2 -> V_9 , L_2 ,
V_4 -> V_10 [ 5 ] ) ;
V_2 -> V_14 = - V_15 ;
}
F_6 ( V_4 ) ;
V_11 = F_7 ( V_2 -> V_16 ) ;
if ( V_11 == NULL || V_2 -> V_14 ) {
F_8 ( & V_2 -> V_17 ) ;
return;
}
if ( V_11 -> V_10 [ 1 ] == 0x01 && V_11 -> V_10 [ 2 ] == 0xfc &&
V_11 -> V_18 >= 10 ) {
F_9 ( L_3 ) ;
V_12 = F_1 ( V_2 , V_11 ) ;
if ( V_12 < 0 ) {
F_6 ( V_11 ) ;
V_2 -> V_14 = V_12 ;
F_8 ( & V_2 -> V_17 ) ;
return;
}
}
F_10 ( & V_2 -> V_19 , V_11 ) ;
F_11 ( & V_2 -> V_20 , V_13 ) ;
F_12 ( V_2 , V_21 , F_13 ( V_2 , V_21 ) |
V_22 ) ;
F_14 ( & V_2 -> V_20 , V_13 ) ;
}
int F_15 ( struct V_1 * V_2 ,
struct V_23 * V_24 )
{
struct V_3 * V_4 ;
unsigned long V_13 , time ;
V_2 -> V_14 = 0 ;
F_9 ( L_4 ) ;
time = V_25 ;
V_2 -> V_16 = V_24 ;
V_4 = F_7 ( V_24 ) ;
if ( ! V_4 )
return - V_26 ;
F_9 ( L_5 ) ;
F_16 ( V_2 , 0 ) ;
F_17 ( & V_2 -> V_17 ) ;
F_10 ( & V_2 -> V_19 , V_4 ) ;
F_11 ( & V_2 -> V_20 , V_13 ) ;
F_12 ( V_2 , V_21 , F_13 ( V_2 , V_21 ) |
V_22 ) ;
F_14 ( & V_2 -> V_20 , V_13 ) ;
if ( ! F_18 ( & V_2 -> V_17 ,
F_19 ( 2000 ) ) ) {
F_5 ( V_2 -> V_9 , L_6 ) ;
return - V_27 ;
}
if ( V_2 -> V_14 ) {
F_5 ( V_2 -> V_9 , L_7 ) ;
return - V_15 ;
}
F_9 ( L_8 ,
F_20 ( V_25 - time ) ) ;
F_21 ( V_2 , 0 , V_28 ) ;
F_22 ( V_2 , 0 ) ;
F_23 ( V_2 , V_29 ) ;
F_21 ( V_2 , 1 , V_28 ) ;
return 0 ;
}
