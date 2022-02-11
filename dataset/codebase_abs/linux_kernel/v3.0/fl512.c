static int T_1 F_1 ( void )
{
return F_2 ( & V_1 ) ;
}
static void T_2 F_3 ( void )
{
F_4 ( & V_1 ) ;
}
static int F_5 ( struct V_2 * V_3 ,
struct V_4 * V_5 , struct V_6 * V_7 ,
unsigned int * V_8 )
{
int V_9 ;
unsigned int V_10 , V_11 ;
char V_12 = F_6 ( V_7 -> V_13 ) ;
unsigned long V_14 = V_3 -> V_14 ;
for ( V_9 = 0 ; V_9 < V_7 -> V_9 ; V_9 ++ ) {
F_7 ( V_12 , V_14 + 2 ) ;
F_7 ( 0 , V_14 + 3 ) ;
F_8 ( 30 ) ;
V_10 = F_9 ( V_14 + 2 ) ;
V_11 = F_9 ( V_14 + 3 ) & 0xf ;
V_8 [ V_9 ] = V_10 + ( V_11 << 8 ) ;
}
return V_9 ;
}
static int F_10 ( struct V_2 * V_3 ,
struct V_4 * V_5 , struct V_6 * V_7 ,
unsigned int * V_8 )
{
int V_9 ;
int V_12 = F_6 ( V_7 -> V_13 ) ;
unsigned long V_14 = V_3 -> V_14 ;
for ( V_9 = 0 ; V_9 < V_7 -> V_9 ; V_9 ++ ) {
F_7 ( V_8 [ V_9 ] & 0x0ff , V_14 + 4 + 2 * V_12 ) ;
F_7 ( ( V_8 [ V_9 ] & 0xf00 ) >> 8 , V_14 + 4 + 2 * V_12 ) ;
F_9 ( V_14 + 4 + 2 * V_12 ) ;
V_15 -> V_16 [ V_12 ] = V_8 [ V_9 ] ;
}
return V_9 ;
}
static int F_11 ( struct V_2 * V_3 ,
struct V_4 * V_5 ,
struct V_6 * V_7 , unsigned int * V_8 )
{
int V_9 ;
int V_12 = F_6 ( V_7 -> V_13 ) ;
for ( V_9 = 0 ; V_9 < V_7 -> V_9 ; V_9 ++ )
V_8 [ V_9 ] = V_15 -> V_16 [ V_12 ] ;
return V_9 ;
}
static int F_12 ( struct V_2 * V_3 , struct V_17 * V_18 )
{
unsigned long V_14 ;
struct V_4 * V_5 ;
V_14 = V_18 -> V_19 [ 0 ] ;
F_13 ( V_20 L_1 , V_3 -> V_21 , V_14 ) ;
if ( ! F_14 ( V_14 , V_22 , L_2 ) ) {
F_13 ( V_23 L_3 ) ;
return - V_24 ;
}
V_3 -> V_14 = V_14 ;
V_3 -> V_25 = L_2 ;
if ( F_15 ( V_3 , sizeof( struct V_26 ) ) < 0 )
return - V_27 ;
#if V_28
F_13 ( V_29 L_4 ) ;
#endif
if ( F_16 ( V_3 , 2 ) < 0 )
return - V_27 ;
V_5 = V_3 -> V_30 + 0 ;
V_5 -> type = V_31 ;
V_5 -> V_32 = V_33 | V_34 ;
V_5 -> V_35 = 16 ;
V_5 -> V_36 = 0x0fff ;
V_5 -> V_37 = & V_38 ;
V_5 -> V_39 = F_5 ;
F_13 ( V_20 L_5 ) ;
V_5 = V_3 -> V_30 + 1 ;
V_5 -> type = V_40 ;
V_5 -> V_32 = V_41 ;
V_5 -> V_35 = 2 ;
V_5 -> V_36 = 0x0fff ;
V_5 -> V_37 = & V_38 ;
V_5 -> V_42 = F_10 ;
V_5 -> V_39 = F_11 ;
F_13 ( V_20 L_6 ) ;
return 1 ;
}
static int F_17 ( struct V_2 * V_3 )
{
if ( V_3 -> V_14 )
F_18 ( V_3 -> V_14 , V_22 ) ;
F_13 ( V_20 L_7 , V_3 -> V_21 ) ;
return 0 ;
}
