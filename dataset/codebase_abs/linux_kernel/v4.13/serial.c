static inline void F_1 ( struct V_1 * V_2 , int V_3 ,
int V_4 )
{
V_3 <<= V_2 -> V_5 ;
F_2 ( ! V_2 -> V_6 , L_1 , V_3 ) ;
F_3 ( V_4 , V_2 -> V_6 + V_3 ) ;
}
static void T_1 F_4 ( struct V_1 * V_2 )
{
unsigned int V_7 = 0 ;
F_1 ( V_2 , V_8 , 0 ) ;
F_1 ( V_2 , V_9 , V_7 ) ;
F_5 ( 10 ) ;
V_7 |= ( 0x3 << 13 ) ;
V_7 |= 0x1 ;
F_1 ( V_2 , V_9 , V_7 ) ;
if ( F_6 () )
F_1 ( V_2 , V_10 ,
V_11 ) ;
}
int T_1 F_7 ( struct V_12 * V_13 )
{
int V_14 , V_15 = 0 ;
struct V_16 * V_17 ;
struct V_1 * V_2 ;
struct V_18 * V_18 ;
for ( V_14 = 0 ; V_13 [ V_14 ] . V_17 . V_19 != NULL ; V_14 ++ ) {
V_17 = & V_13 [ V_14 ] . V_17 ;
V_2 = V_17 -> V_19 ;
V_15 = F_8 ( & V_13 [ V_14 ] ) ;
if ( V_15 )
continue;
V_18 = F_9 ( V_17 , NULL ) ;
if ( F_10 ( V_18 ) ) {
F_11 ( L_2 ,
V_20 , __LINE__ , V_14 ) ;
continue;
}
F_12 ( V_18 ) ;
V_2 -> V_21 = F_13 ( V_18 ) ;
if ( ! V_2 -> V_6 && V_2 -> V_22 ) {
V_2 -> V_6 = F_14 ( V_2 -> V_22 , V_23 ) ;
if ( V_2 -> V_6 )
V_2 -> V_24 &= ~ V_25 ;
else
F_11 ( L_3 ) ;
}
if ( V_2 -> V_6 && V_2 -> type != V_26 )
F_4 ( V_2 ) ;
}
return V_15 ;
}
