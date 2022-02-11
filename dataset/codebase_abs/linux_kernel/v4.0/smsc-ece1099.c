static int F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
struct V_5 * V_5 ;
int V_6 , V_7 , V_8 , V_9 ;
int V_10 = 0 ;
V_5 = F_2 ( & V_2 -> V_11 , sizeof( struct V_5 ) ,
V_12 ) ;
if ( ! V_5 ) {
F_3 ( & V_2 -> V_11 , L_1 ) ;
return - V_13 ;
}
V_5 -> V_14 = F_4 ( V_2 , & V_15 ) ;
if ( F_5 ( V_5 -> V_14 ) ) {
V_10 = F_6 ( V_5 -> V_14 ) ;
goto V_16;
}
F_7 ( V_2 , V_5 ) ;
V_5 -> V_11 = & V_2 -> V_11 ;
#ifdef F_8
F_9 ( V_2 -> V_11 . V_17 , L_2 , & V_5 -> V_18 ) ;
#endif
F_10 ( V_5 -> V_14 , V_19 , & V_6 ) ;
F_10 ( V_5 -> V_14 , V_20 , & V_7 ) ;
F_10 ( V_5 -> V_14 , V_21 , & V_8 ) ;
F_10 ( V_5 -> V_14 , V_22 , & V_9 ) ;
F_11 ( & V_2 -> V_11 , L_3 ,
V_6 , V_7 , ( V_9 << 8 ) | V_8 ) ;
V_10 = F_12 ( V_5 -> V_14 , V_23 , V_5 -> V_18 ) ;
if ( V_10 )
goto V_16;
#ifdef F_8
if ( V_2 -> V_11 . V_17 )
V_10 = F_13 ( V_2 -> V_11 . V_17 ,
NULL , NULL , & V_2 -> V_11 ) ;
#endif
V_16:
return V_10 ;
}
static int F_14 ( struct V_1 * V_2 )
{
struct V_5 * V_5 = F_15 ( V_2 ) ;
F_16 ( V_5 -> V_11 ) ;
return 0 ;
}
