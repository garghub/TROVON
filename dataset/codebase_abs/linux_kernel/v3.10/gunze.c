static void F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = V_1 -> V_3 ;
if ( V_1 -> V_4 != V_5 || V_1 -> V_6 [ 5 ] != ',' ||
( V_1 -> V_6 [ 0 ] != 'T' && V_1 -> V_6 [ 0 ] != 'R' ) ) {
F_2 ( V_7 L_1 , V_5 , V_1 -> V_6 ) ;
return;
}
F_3 ( V_3 , V_8 , F_4 ( V_1 -> V_6 + 1 , NULL , 10 ) ) ;
F_3 ( V_3 , V_9 , 1024 - F_4 ( V_1 -> V_6 + 6 , NULL , 10 ) ) ;
F_5 ( V_3 , V_10 , V_1 -> V_6 [ 0 ] == 'T' ) ;
F_6 ( V_3 ) ;
}
static T_1 F_7 ( struct V_11 * V_11 ,
unsigned char V_6 , unsigned int V_12 )
{
struct V_1 * V_1 = F_8 ( V_11 ) ;
if ( V_6 == '\r' ) {
F_1 ( V_1 ) ;
V_1 -> V_4 = 0 ;
} else {
if ( V_1 -> V_4 < V_5 )
V_1 -> V_6 [ V_1 -> V_4 ++ ] = V_6 ;
}
return V_13 ;
}
static void F_9 ( struct V_11 * V_11 )
{
struct V_1 * V_1 = F_8 ( V_11 ) ;
F_10 ( V_1 -> V_3 ) ;
F_11 ( V_1 -> V_3 ) ;
F_12 ( V_11 ) ;
F_13 ( V_11 , NULL ) ;
F_14 ( V_1 -> V_3 ) ;
F_15 ( V_1 ) ;
}
static int F_16 ( struct V_11 * V_11 , struct V_14 * V_15 )
{
struct V_1 * V_1 ;
struct V_2 * V_2 ;
int V_16 ;
V_1 = F_17 ( sizeof( struct V_1 ) , V_17 ) ;
V_2 = F_18 () ;
if ( ! V_1 || ! V_2 ) {
V_16 = - V_18 ;
goto V_19;
}
V_1 -> V_11 = V_11 ;
V_1 -> V_3 = V_2 ;
snprintf ( V_1 -> V_20 , sizeof( V_11 -> V_20 ) , L_2 , V_11 -> V_20 ) ;
V_2 -> V_21 = L_3 ;
V_2 -> V_20 = V_1 -> V_20 ;
V_2 -> V_22 . V_23 = V_24 ;
V_2 -> V_22 . V_25 = V_26 ;
V_2 -> V_22 . V_27 = 0x0051 ;
V_2 -> V_22 . V_28 = 0x0100 ;
V_2 -> V_3 . V_29 = & V_11 -> V_3 ;
V_2 -> V_30 [ 0 ] = F_19 ( V_31 ) | F_19 ( V_32 ) ;
V_2 -> V_33 [ F_20 ( V_10 ) ] = F_19 ( V_10 ) ;
F_21 ( V_2 , V_8 , 24 , 1000 , 0 , 0 ) ;
F_21 ( V_2 , V_9 , 24 , 1000 , 0 , 0 ) ;
F_13 ( V_11 , V_1 ) ;
V_16 = F_22 ( V_11 , V_15 ) ;
if ( V_16 )
goto V_34;
V_16 = F_23 ( V_1 -> V_3 ) ;
if ( V_16 )
goto V_35;
return 0 ;
V_35: F_12 ( V_11 ) ;
V_34: F_13 ( V_11 , NULL ) ;
V_19: F_24 ( V_2 ) ;
F_15 ( V_1 ) ;
return V_16 ;
}
