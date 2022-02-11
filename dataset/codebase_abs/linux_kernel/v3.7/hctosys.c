static int T_1 F_1 ( void )
{
int V_1 = - V_2 ;
struct V_3 V_4 ;
struct V_5 V_6 = {
. V_7 = V_8 >> 1 ,
} ;
struct V_9 * V_10 = F_2 ( V_11 ) ;
if ( V_10 == NULL ) {
F_3 ( L_1 ,
__FILE__ , V_11 ) ;
goto V_12;
}
V_1 = F_4 ( V_10 , & V_4 ) ;
if ( V_1 ) {
F_5 ( V_10 -> V_13 . V_14 ,
L_2 ) ;
goto V_15;
}
V_1 = F_6 ( & V_4 ) ;
if ( V_1 ) {
F_5 ( V_10 -> V_13 . V_14 ,
L_3 ) ;
goto V_16;
}
F_7 ( & V_4 , & V_6 . V_17 ) ;
V_1 = F_8 ( & V_6 ) ;
F_9 ( V_10 -> V_13 . V_14 ,
L_4
L_5 ,
V_4 . V_18 + 1900 , V_4 . V_19 + 1 , V_4 . V_20 ,
V_4 . V_21 , V_4 . V_22 , V_4 . V_23 ,
( unsigned int ) V_6 . V_17 ) ;
V_16:
V_15:
F_10 ( V_10 ) ;
V_12:
V_24 = V_1 ;
return V_1 ;
}
