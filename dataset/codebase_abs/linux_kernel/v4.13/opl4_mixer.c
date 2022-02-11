static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
V_4 -> type = V_5 ;
V_4 -> V_6 = 2 ;
V_4 -> V_7 . integer . V_8 = 0 ;
V_4 -> V_7 . integer . V_9 = 7 ;
return 0 ;
}
static int F_2 ( struct V_1 * V_2 , struct V_10 * V_11 )
{
struct V_12 * V_13 = F_3 ( V_2 ) ;
unsigned long V_14 ;
T_1 V_15 = V_2 -> V_16 ;
T_1 V_7 ;
F_4 ( & V_13 -> V_17 , V_14 ) ;
V_7 = F_5 ( V_13 , V_15 ) ;
F_6 ( & V_13 -> V_17 , V_14 ) ;
V_11 -> V_7 . integer . V_7 [ 0 ] = 7 - ( V_7 & 7 ) ;
V_11 -> V_7 . integer . V_7 [ 1 ] = 7 - ( ( V_7 >> 3 ) & 7 ) ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 , struct V_10 * V_11 )
{
struct V_12 * V_13 = F_3 ( V_2 ) ;
unsigned long V_14 ;
T_1 V_15 = V_2 -> V_16 ;
T_1 V_7 , V_18 ;
V_7 = ( 7 - ( V_11 -> V_7 . integer . V_7 [ 0 ] & 7 ) ) |
( ( 7 - ( V_11 -> V_7 . integer . V_7 [ 1 ] & 7 ) ) << 3 ) ;
F_4 ( & V_13 -> V_17 , V_14 ) ;
V_18 = F_5 ( V_13 , V_15 ) ;
F_8 ( V_13 , V_15 , V_7 ) ;
F_6 ( & V_13 -> V_17 , V_14 ) ;
return V_7 != V_18 ;
}
int F_9 ( struct V_12 * V_13 )
{
struct V_19 * V_20 = V_13 -> V_20 ;
int V_21 , V_22 ;
strcat ( V_20 -> V_23 , L_1 ) ;
for ( V_21 = 0 ; V_21 < 2 ; ++ V_21 ) {
V_22 = F_10 ( V_20 , F_11 ( & V_24 [ V_21 ] , V_13 ) ) ;
if ( V_22 < 0 )
return V_22 ;
}
return 0 ;
}
