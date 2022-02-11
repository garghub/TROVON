static int F_1 ( struct V_1 * V_2 ,
enum V_3 V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 , struct V_5 ,
V_2 ) ;
T_1 V_7 ;
int V_8 ;
F_3 ( & V_6 -> V_9 ) ;
V_7 = F_4 ( ( ( V_6 -> V_10 ) << 14 ) | V_11 |
( V_4 & 0xfff ) ) ;
V_8 = F_5 ( V_6 -> V_12 , ( const V_13 * ) & V_7 , sizeof( V_7 ) ) ;
F_6 ( & V_6 -> V_9 ) ;
return V_8 ;
}
static int F_7 ( struct V_14 * V_12 )
{
struct V_15 * V_16 ;
struct V_5 * V_6 ;
int V_17 , V_8 ;
V_16 = F_8 ( & V_12 -> V_18 , sizeof( * V_16 ) , V_19 ) ;
if ( ! V_16 )
return - V_20 ;
V_12 -> V_21 = 16 ;
for ( V_17 = 0 ; V_17 < F_9 ( V_16 -> V_22 ) ; V_17 ++ ) {
V_6 = V_16 -> V_22 + V_17 ;
V_6 -> V_10 = V_17 ;
V_6 -> V_12 = V_12 ;
snprintf ( V_6 -> V_23 , sizeof( V_6 -> V_23 ) , L_1 , V_17 ) ;
F_10 ( & V_6 -> V_9 ) ;
V_6 -> V_2 . V_23 = V_6 -> V_23 ;
V_6 -> V_2 . V_4 = V_24 ;
V_6 -> V_2 . V_25 = 0xfff ;
V_6 -> V_2 . V_26 = F_1 ;
V_8 = F_11 ( & V_12 -> V_18 , & V_6 -> V_2 ) ;
if ( V_8 < 0 )
goto V_27;
}
F_12 ( V_12 , V_16 ) ;
return 0 ;
V_27:
while ( V_17 -- )
F_13 ( & V_16 -> V_22 [ V_17 ] . V_2 ) ;
return V_8 ;
}
static int F_14 ( struct V_14 * V_12 )
{
struct V_15 * V_16 = F_15 ( V_12 ) ;
int V_17 ;
for ( V_17 = 0 ; V_17 < F_9 ( V_16 -> V_22 ) ; V_17 ++ )
F_13 ( & V_16 -> V_22 [ V_17 ] . V_2 ) ;
return 0 ;
}
