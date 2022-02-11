static void F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 ;
bool V_4 ;
V_3 = F_2 ( 1 ) ;
if ( ! V_3 )
return;
V_3 -> V_5 [ 0 ] . V_6 = F_3 ( V_1 , 0 ) ;
V_3 -> V_5 [ 0 ] . V_7 = F_4 ( V_1 , 0 ) ;
V_4 = V_1 -> V_8 [ V_9 ] . V_10
& V_11 ;
F_5 ( V_3 , L_1 , V_4 ) ;
F_6 ( V_3 ) ;
}
int F_7 ( struct V_12 * V_13 , struct V_14 * V_15 )
{
struct V_16 * V_17 ;
int V_18 ;
V_17 = F_8 ( V_13 , & V_15 -> V_17 ) ;
if ( F_9 ( V_17 ) )
return F_10 ( V_17 ) ;
V_15 -> V_19 = V_17 ;
if ( strcmp ( V_15 -> V_17 . V_20 -> V_21 -> V_22 , L_2 ) == 0 ) {
struct V_1 * V_23 = F_11 ( V_15 -> V_17 . V_20 ) ;
const char * V_24 = F_12 ( & V_23 -> V_17 ) ;
bool V_25 = ( V_23 -> V_26 >> 8 ) == V_27 ;
char V_28 [ 20 ] ;
F_13 ( L_3 ,
V_25 ? L_4 : L_5 ,
V_24 ) ;
V_17 -> V_23 = V_23 ;
if ( V_25 )
F_1 ( V_23 ) ;
snprintf ( V_28 , sizeof( V_28 ) , L_6 , V_24 ) ;
V_18 = F_14 ( V_17 , V_28 ) ;
if ( V_18 )
goto V_29;
}
V_18 = F_15 ( V_17 , 0 ) ;
if ( V_18 )
goto V_29;
return 0 ;
V_29:
F_16 ( V_17 ) ;
return V_18 ;
}
