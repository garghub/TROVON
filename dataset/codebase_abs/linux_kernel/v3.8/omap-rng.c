static inline T_1 F_1 ( struct V_1 * V_2 , int V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 ) ;
}
static inline void F_3 ( struct V_1 * V_2 ,
int V_3 , T_1 V_5 )
{
F_4 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static int F_5 ( struct V_6 * V_7 , int V_8 )
{
struct V_1 * V_2 ;
int V_9 , V_10 ;
V_2 = (struct V_1 * ) V_7 -> V_2 ;
for ( V_10 = 0 ; V_10 < 20 ; V_10 ++ ) {
V_9 = F_1 ( V_2 , V_11 ) ? 0 : 1 ;
if ( V_9 || ! V_8 )
break;
F_6 ( 10 ) ;
}
return V_9 ;
}
static int F_7 ( struct V_6 * V_7 , T_1 * V_9 )
{
struct V_1 * V_2 ;
V_2 = (struct V_1 * ) V_7 -> V_2 ;
* V_9 = F_1 ( V_2 , V_12 ) ;
return sizeof( T_1 ) ;
}
static int F_8 ( struct V_13 * V_14 )
{
struct V_1 * V_2 ;
int V_15 ;
V_2 = F_9 ( sizeof( struct V_1 ) , V_16 ) ;
if ( ! V_2 ) {
F_10 ( & V_14 -> V_17 , L_1 ) ;
return - V_18 ;
} ;
V_19 . V_2 = ( unsigned long ) V_2 ;
F_11 ( & V_14 -> V_17 , V_2 ) ;
V_2 -> V_20 = F_12 ( V_14 , V_21 , 0 ) ;
if ( ! V_2 -> V_20 ) {
V_15 = - V_22 ;
goto V_23;
}
V_2 -> V_4 = F_13 ( & V_14 -> V_17 , V_2 -> V_20 ) ;
if ( ! V_2 -> V_4 ) {
V_15 = - V_18 ;
goto V_23;
}
F_11 ( & V_14 -> V_17 , V_2 ) ;
F_14 ( & V_14 -> V_17 ) ;
F_15 ( & V_14 -> V_17 ) ;
V_15 = F_16 ( & V_19 ) ;
if ( V_15 )
goto V_24;
F_17 ( & V_14 -> V_17 , L_2 ,
F_1 ( V_2 , V_25 ) ) ;
F_3 ( V_2 , V_26 , 0x1 ) ;
return 0 ;
V_24:
V_2 -> V_4 = NULL ;
F_18 ( & V_14 -> V_17 ) ;
V_23:
F_19 ( V_2 ) ;
return V_15 ;
}
static int T_2 F_20 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = F_21 ( & V_14 -> V_17 ) ;
F_22 ( & V_19 ) ;
F_3 ( V_2 , V_26 , 0x0 ) ;
F_23 ( & V_14 -> V_17 ) ;
F_18 ( & V_14 -> V_17 ) ;
F_24 ( V_2 -> V_20 -> V_27 , F_25 ( V_2 -> V_20 ) ) ;
F_19 ( V_2 ) ;
return 0 ;
}
static int F_26 ( struct V_28 * V_17 )
{
struct V_1 * V_2 = F_21 ( V_17 ) ;
F_3 ( V_2 , V_26 , 0x0 ) ;
F_23 ( V_17 ) ;
return 0 ;
}
static int F_27 ( struct V_28 * V_17 )
{
struct V_1 * V_2 = F_21 ( V_17 ) ;
F_15 ( V_17 ) ;
F_3 ( V_2 , V_26 , 0x1 ) ;
return 0 ;
}
static int T_3 F_28 ( void )
{
return F_29 ( & V_29 ) ;
}
static void T_2 F_30 ( void )
{
F_31 ( & V_29 ) ;
}
