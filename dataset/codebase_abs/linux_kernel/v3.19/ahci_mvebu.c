static void F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < 4 ; V_5 ++ ) {
F_2 ( 0 , V_2 -> V_6 + F_3 ( V_5 ) ) ;
F_2 ( 0 , V_2 -> V_6 + F_4 ( V_5 ) ) ;
F_2 ( 0 , V_2 -> V_6 + F_5 ( V_5 ) ) ;
}
for ( V_5 = 0 ; V_5 < V_4 -> V_7 ; V_5 ++ ) {
const struct V_8 * V_9 = V_4 -> V_9 + V_5 ;
F_2 ( ( V_9 -> V_10 << 8 ) |
( V_4 -> V_11 << 4 ) | 1 ,
V_2 -> V_6 + F_3 ( V_5 ) ) ;
F_2 ( V_9 -> V_12 , V_2 -> V_6 + F_4 ( V_5 ) ) ;
F_2 ( ( ( V_9 -> V_13 - 1 ) & 0xffff0000 ) ,
V_2 -> V_6 + F_5 ( V_5 ) ) ;
}
}
static void F_6 ( struct V_1 * V_2 )
{
F_2 ( 0x4 , V_2 -> V_6 + V_14 ) ;
F_2 ( 0x80 , V_2 -> V_6 + V_15 ) ;
}
static int F_7 ( struct V_16 * V_17 )
{
struct V_1 * V_2 ;
const struct V_3 * V_4 ;
int V_18 ;
V_2 = F_8 ( V_17 ) ;
if ( F_9 ( V_2 ) )
return F_10 ( V_2 ) ;
V_18 = F_11 ( V_2 ) ;
if ( V_18 )
return V_18 ;
V_4 = F_12 () ;
if ( ! V_4 )
return - V_19 ;
F_1 ( V_2 , V_4 ) ;
F_6 ( V_2 ) ;
V_18 = F_13 ( V_17 , V_2 , & V_20 ) ;
if ( V_18 )
goto V_21;
return 0 ;
V_21:
F_14 ( V_2 ) ;
return V_18 ;
}
