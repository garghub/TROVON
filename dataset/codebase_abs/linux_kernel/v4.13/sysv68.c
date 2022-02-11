int F_1 ( struct V_1 * V_2 )
{
int V_3 , V_4 ;
int V_5 = 1 ;
T_1 V_6 ;
unsigned char * V_7 ;
struct V_8 * V_9 ;
struct V_10 * V_10 ;
char V_11 [ 64 ] ;
V_7 = F_2 ( V_2 , 0 , & V_6 ) ;
if ( ! V_7 )
return - 1 ;
V_9 = (struct V_8 * ) V_7 ;
if ( memcmp ( V_9 -> V_12 . V_13 , L_1 , sizeof( V_9 -> V_12 . V_13 ) ) ) {
F_3 ( V_6 ) ;
return 0 ;
}
V_4 = F_4 ( V_9 -> V_14 . V_15 ) ;
V_3 = F_5 ( V_9 -> V_14 . V_16 ) ;
F_3 ( V_6 ) ;
V_7 = F_2 ( V_2 , V_3 , & V_6 ) ;
if ( ! V_7 )
return - 1 ;
V_4 -= 1 ;
snprintf ( V_11 , sizeof( V_11 ) , L_2 , V_2 -> V_17 , V_4 ) ;
F_6 ( V_2 -> V_18 , V_11 , V_19 ) ;
V_10 = (struct V_10 * ) V_7 ;
for ( V_3 = 0 ; V_3 < V_4 ; V_3 ++ , V_10 ++ ) {
if ( V_5 == V_2 -> V_20 )
break;
if ( F_5 ( V_10 -> V_21 ) ) {
F_7 ( V_2 , V_5 ,
F_5 ( V_10 -> V_22 ) ,
F_5 ( V_10 -> V_21 ) ) ;
snprintf ( V_11 , sizeof( V_11 ) , L_3 , V_3 ) ;
F_6 ( V_2 -> V_18 , V_11 , V_19 ) ;
}
V_5 ++ ;
}
F_6 ( V_2 -> V_18 , L_4 , V_19 ) ;
F_3 ( V_6 ) ;
return 1 ;
}
