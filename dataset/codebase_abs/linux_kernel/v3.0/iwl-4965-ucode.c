static int
F_1 ( struct V_1 * V_2 , T_1 * V_3 , T_2 V_4 )
{
T_2 V_5 ;
int V_6 = 0 ;
T_2 V_7 = 0 ;
T_2 V_8 ;
F_2 ( V_2 , L_1 , V_4 ) ;
for ( V_8 = 0 ; V_8 < V_4 ; V_8 += 100 , V_3 += 100 / sizeof( T_2 ) ) {
F_3 ( V_2 , V_9 ,
V_8 + V_10 ) ;
V_5 = F_4 ( V_2 , V_11 ) ;
if ( V_5 != F_5 ( * V_3 ) ) {
V_6 = - V_12 ;
V_7 ++ ;
if ( V_7 >= 3 )
break;
}
}
return V_6 ;
}
static int F_6 ( struct V_1 * V_2 , T_1 * V_3 ,
T_2 V_4 )
{
T_2 V_5 ;
T_2 V_13 = V_4 ;
int V_6 = 0 ;
T_2 V_7 ;
F_2 ( V_2 , L_1 , V_4 ) ;
F_3 ( V_2 , V_9 ,
V_10 ) ;
V_7 = 0 ;
for (; V_4 > 0 ; V_4 -= sizeof( T_2 ) , V_3 ++ ) {
V_5 = F_4 ( V_2 , V_11 ) ;
if ( V_5 != F_5 ( * V_3 ) ) {
F_7 ( V_2 , L_2
L_3 ,
V_13 - V_4 , V_5 , F_5 ( * V_3 ) ) ;
V_6 = - V_12 ;
V_7 ++ ;
if ( V_7 >= 20 )
break;
}
}
if ( ! V_7 )
F_2 ( V_2 ,
L_4 ) ;
return V_6 ;
}
int F_8 ( struct V_1 * V_2 )
{
T_1 * V_3 ;
T_2 V_4 ;
int V_6 ;
V_3 = ( T_1 * ) V_2 -> V_14 . V_15 ;
V_4 = V_2 -> V_14 . V_4 ;
V_6 = F_1 ( V_2 , V_3 , V_4 ) ;
if ( ! V_6 ) {
F_2 ( V_2 , L_5 ) ;
return 0 ;
}
V_3 = ( T_1 * ) V_2 -> V_16 . V_15 ;
V_4 = V_2 -> V_16 . V_4 ;
V_6 = F_1 ( V_2 , V_3 , V_4 ) ;
if ( ! V_6 ) {
F_2 ( V_2 , L_6 ) ;
return 0 ;
}
V_3 = ( T_1 * ) V_2 -> V_17 . V_15 ;
V_4 = V_2 -> V_17 . V_4 ;
V_6 = F_1 ( V_2 , V_3 , V_4 ) ;
if ( ! V_6 ) {
F_2 ( V_2 , L_7 ) ;
return 0 ;
}
F_7 ( V_2 , L_8 ) ;
V_3 = ( T_1 * ) V_2 -> V_14 . V_15 ;
V_4 = V_2 -> V_14 . V_4 ;
V_6 = F_6 ( V_2 , V_3 , V_4 ) ;
return V_6 ;
}
