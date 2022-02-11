static int F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
static int V_5 ;
struct V_6 * V_7 ;
struct V_8 * V_9 ;
int V_10 ;
if ( V_5 >= V_11 )
return - V_12 ;
if ( ! V_13 [ V_5 ] ) {
V_5 ++ ;
return - V_14 ;
}
V_10 = F_2 ( & V_2 -> V_5 , V_15 [ V_5 ] , V_16 [ V_5 ] , V_17 ,
0 , & V_7 ) ;
if ( V_10 < 0 )
return V_10 ;
if ( ( V_10 = F_3 ( V_7 , V_2 ,
V_18 [ V_5 ] , V_19 [ V_5 ] ,
& V_9 ) ) < 0 ) {
F_4 ( V_7 ) ;
return V_10 ;
}
V_7 -> V_20 = V_9 ;
V_9 -> V_21 = V_22 [ V_5 ] ;
if ( ( V_10 = F_5 ( V_9 , 0 , NULL ) ) < 0 ) {
F_4 ( V_7 ) ;
return V_10 ;
}
#ifdef F_6
if ( ( V_10 = F_7 ( V_9 , 1 , NULL ) ) < 0 ) {
F_4 ( V_7 ) ;
return V_10 ;
}
if ( ( V_10 = F_8 ( V_9 , 2 , NULL ) ) < 0 ) {
F_4 ( V_7 ) ;
return V_10 ;
}
#endif
if ( ( V_10 = F_9 ( V_9 , 2 ) ) < 0 ) {
F_4 ( V_7 ) ;
return V_10 ;
}
#ifdef F_6
if ( V_9 -> V_23 == 2 ) {
if ( ( V_10 = F_10 ( V_9 , 3 , NULL ) ) < 0 ) {
F_4 ( V_7 ) ;
return V_10 ;
}
}
#endif
if ( ( V_10 = F_11 ( V_9 , 0 , NULL ) ) < 0 ) {
F_4 ( V_7 ) ;
return V_10 ;
}
if ( ( V_10 = F_12 ( V_9 ) ) < 0 ) {
F_4 ( V_7 ) ;
return V_10 ;
}
F_13 ( V_9 ) ;
strcpy ( V_7 -> V_24 , L_1 ) ;
strcpy ( V_7 -> V_25 , L_2 ) ;
sprintf ( V_7 -> V_26 , L_3 ,
V_7 -> V_25 ,
V_9 -> V_27 ,
V_9 -> V_28 ,
V_9 -> V_29 ) ;
if ( ( V_10 = F_14 ( V_7 ) ) < 0 ) {
F_4 ( V_7 ) ;
return V_10 ;
}
F_15 ( V_2 , V_7 ) ;
V_5 ++ ;
return 0 ;
}
static void F_16 ( struct V_1 * V_2 )
{
F_4 ( F_17 ( V_2 ) ) ;
}
