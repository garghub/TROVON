static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 ,
struct V_6 * V_7 ,
const char * V_8 )
{
unsigned int V_9 ;
T_1 V_10 ;
F_2 ( & V_2 -> V_11 . V_12 ) ;
V_4 -> V_2 = V_2 ;
V_4 -> V_5 = F_3 ( V_5 ? : L_1 , V_13 ) ;
if ( ! V_4 -> V_5 )
return - V_14 ;
F_4 ( & V_4 -> V_15 , & V_2 -> V_16 . V_17 ) ;
V_10 = F_5 ( F_6 ( V_4 -> V_18 ) ) ;
for ( V_9 = 0 ; V_9 < F_6 ( V_4 -> V_18 ) ; V_9 ++ ) {
struct V_19 * V_20 = & V_4 -> V_18 [ V_9 ] ;
V_20 -> V_21 = V_10 ++ ;
V_20 -> V_22 = V_4 ;
#ifdef F_7
F_8 ( & V_20 -> V_23 . V_24 , V_8 , V_7 ) ;
#else
F_9 ( & V_20 -> V_23 ) ;
#endif
F_10 ( & V_20 -> V_25 , NULL ) ;
F_11 ( & V_20 -> V_26 ) ;
}
return 0 ;
}
int F_12 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 )
{
static struct V_6 V_27 ;
return F_1 ( V_2 , V_4 , V_5 ,
& V_27 , L_2 ) ;
}
int F_13 ( struct V_1 * V_2 )
{
static struct V_6 V_27 ;
return F_1 ( V_2 ,
& V_2 -> V_16 . V_28 ,
L_3 ,
& V_27 , L_4 ) ;
}
void F_14 ( struct V_3 * V_20 )
{
F_2 ( & V_20 -> V_2 -> V_11 . V_12 ) ;
F_15 ( & V_20 -> V_15 ) ;
F_16 ( V_20 -> V_5 ) ;
}
