static bool F_1 ( T_1 V_1 )
{
T_2 * V_2 ;
F_2 (md) {
T_1 V_3 ;
T_1 V_4 ;
if ( V_2 -> type != V_5 )
continue;
V_3 = V_2 -> V_6 << V_7 ;
V_4 = V_2 -> V_8 + V_3 ;
if ( V_1 >= V_2 -> V_8 && V_1 < V_4 )
return true ;
}
return false ;
}
void T_3 F_3 ( struct V_9 * V_10 )
{
void * V_11 ;
struct V_12 V_12 ;
struct V_13 * V_14 = & V_15 ;
if ( V_16 )
return;
if ( ! F_4 ( V_17 ) )
return;
if ( V_10 -> V_18 < sizeof( V_15 ) ) {
F_5 ( L_1 ,
V_10 -> V_18 , sizeof( V_15 ) ) ;
return;
}
* V_14 = * (struct V_13 * ) V_10 ;
if ( V_14 -> V_19 != 1 ) {
F_5 ( L_2 ,
V_14 -> V_19 ) ;
goto V_20;
}
if ( V_14 -> V_21 & 0xfe ) {
F_5 ( L_3 ,
V_14 -> V_21 ) ;
goto V_20;
}
if ( V_14 -> V_22 != 0 ) {
F_5 ( L_4 ,
V_14 -> V_22 ) ;
goto V_20;
}
if ( ! V_14 -> V_23 ) {
F_5 ( L_5 ) ;
goto V_20;
}
if ( ! F_1 ( V_14 -> V_23 ) ) {
F_5 ( L_6 ) ;
goto V_20;
}
V_11 = F_6 ( V_14 -> V_23 , sizeof( V_12 ) ) ;
if ( ! V_11 ) {
F_5 ( L_7 ) ;
goto V_20;
}
memcpy ( & V_12 , V_11 , sizeof( V_12 ) ) ;
F_7 ( V_11 , sizeof( V_12 ) ) ;
if ( V_12 . V_24 != 0x4d42 ) {
F_5 ( L_8 ,
V_12 . V_24 ) ;
goto V_20;
}
V_25 = V_12 . V_3 ;
F_8 ( V_14 -> V_23 , V_25 ) ;
return;
V_20:
memset ( V_14 , 0 , sizeof( V_15 ) ) ;
}
