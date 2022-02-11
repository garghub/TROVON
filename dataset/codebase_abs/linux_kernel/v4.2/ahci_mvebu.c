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
F_2 ( V_9 -> V_12 >> 16 , V_2 -> V_6 + F_4 ( V_5 ) ) ;
F_2 ( ( ( V_9 -> V_13 - 1 ) & 0xffff0000 ) ,
V_2 -> V_6 + F_5 ( V_5 ) ) ;
}
}
static void F_6 ( struct V_1 * V_2 )
{
F_2 ( 0x4 , V_2 -> V_6 + V_14 ) ;
F_2 ( 0x80 , V_2 -> V_6 + V_15 ) ;
}
static int F_7 ( struct V_16 * V_17 , T_1 V_18 )
{
return F_8 ( & V_17 -> V_19 ) ;
}
static int F_9 ( struct V_16 * V_17 )
{
struct V_20 * V_21 = F_10 ( V_17 ) ;
struct V_1 * V_2 = V_21 -> V_22 ;
const struct V_3 * V_4 ;
V_4 = F_11 () ;
if ( V_4 )
F_1 ( V_2 , V_4 ) ;
F_6 ( V_2 ) ;
return F_12 ( & V_17 -> V_19 ) ;
}
static int F_13 ( struct V_16 * V_17 )
{
struct V_1 * V_2 ;
const struct V_3 * V_4 ;
int V_23 ;
V_2 = F_14 ( V_17 ) ;
if ( F_15 ( V_2 ) )
return F_16 ( V_2 ) ;
V_23 = F_17 ( V_2 ) ;
if ( V_23 )
return V_23 ;
V_4 = F_11 () ;
if ( ! V_4 )
return - V_24 ;
F_1 ( V_2 , V_4 ) ;
F_6 ( V_2 ) ;
V_23 = F_18 ( V_17 , V_2 , & V_25 ,
& V_26 ) ;
if ( V_23 )
goto V_27;
return 0 ;
V_27:
F_19 ( V_2 ) ;
return V_23 ;
}
