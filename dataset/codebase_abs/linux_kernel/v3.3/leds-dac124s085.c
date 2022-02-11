static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 , struct V_3 ,
V_2 ) ;
T_1 V_5 ;
F_3 ( & V_4 -> V_6 ) ;
V_5 = F_4 ( ( ( V_4 -> V_7 ) << 14 ) | V_8 |
( V_4 -> V_9 & 0xfff ) ) ;
F_5 ( V_4 -> V_10 , ( const V_11 * ) & V_5 , sizeof( V_5 ) ) ;
F_6 ( & V_4 -> V_6 ) ;
}
static void F_7 ( struct V_12 * V_13 ,
enum V_14 V_9 )
{
struct V_3 * V_4 = F_2 ( V_13 , struct V_3 ,
V_13 ) ;
F_8 ( & V_4 -> V_15 ) ;
V_4 -> V_9 = V_9 ;
F_9 ( & V_4 -> V_2 ) ;
F_10 ( & V_4 -> V_15 ) ;
}
static int F_11 ( struct V_16 * V_10 )
{
struct V_17 * V_18 ;
struct V_3 * V_4 ;
int V_19 , V_20 ;
V_18 = F_12 ( sizeof( * V_18 ) , V_21 ) ;
if ( ! V_18 )
return - V_22 ;
V_10 -> V_23 = 16 ;
for ( V_19 = 0 ; V_19 < F_13 ( V_18 -> V_24 ) ; V_19 ++ ) {
V_4 = V_18 -> V_24 + V_19 ;
V_4 -> V_7 = V_19 ;
V_4 -> V_9 = V_25 ;
V_4 -> V_10 = V_10 ;
snprintf ( V_4 -> V_26 , sizeof( V_4 -> V_26 ) , L_1 , V_19 ) ;
F_14 ( & V_4 -> V_15 ) ;
F_15 ( & V_4 -> V_2 , F_1 ) ;
F_16 ( & V_4 -> V_6 ) ;
V_4 -> V_13 . V_26 = V_4 -> V_26 ;
V_4 -> V_13 . V_9 = V_25 ;
V_4 -> V_13 . V_27 = 0xfff ;
V_4 -> V_13 . V_28 = F_7 ;
V_20 = F_17 ( & V_10 -> V_29 , & V_4 -> V_13 ) ;
if ( V_20 < 0 )
goto V_30;
}
F_18 ( V_10 , V_18 ) ;
return 0 ;
V_30:
while ( V_19 -- )
F_19 ( & V_18 -> V_24 [ V_19 ] . V_13 ) ;
F_18 ( V_10 , NULL ) ;
F_20 ( V_18 ) ;
return V_20 ;
}
static int F_21 ( struct V_16 * V_10 )
{
struct V_17 * V_18 = F_22 ( V_10 ) ;
int V_19 ;
for ( V_19 = 0 ; V_19 < F_13 ( V_18 -> V_24 ) ; V_19 ++ ) {
F_19 ( & V_18 -> V_24 [ V_19 ] . V_13 ) ;
F_23 ( & V_18 -> V_24 [ V_19 ] . V_2 ) ;
}
F_18 ( V_10 , NULL ) ;
F_20 ( V_18 ) ;
return 0 ;
}
