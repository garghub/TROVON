static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_5 * V_6 ,
unsigned int * V_7 )
{
int V_8 ;
unsigned int V_9 , V_10 ;
char V_11 = F_2 ( V_6 -> V_12 ) ;
unsigned long V_13 = V_2 -> V_13 ;
for ( V_8 = 0 ; V_8 < V_6 -> V_8 ; V_8 ++ ) {
F_3 ( V_11 , V_13 + 2 ) ;
F_3 ( 0 , V_13 + 3 ) ;
F_4 ( 30 ) ;
V_9 = F_5 ( V_13 + 2 ) ;
V_10 = F_5 ( V_13 + 3 ) & 0xf ;
V_7 [ V_8 ] = V_9 + ( V_10 << 8 ) ;
}
return V_8 ;
}
static int F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_5 * V_6 ,
unsigned int * V_7 )
{
int V_8 ;
int V_11 = F_2 ( V_6 -> V_12 ) ;
unsigned long V_13 = V_2 -> V_13 ;
for ( V_8 = 0 ; V_8 < V_6 -> V_8 ; V_8 ++ ) {
F_3 ( V_7 [ V_8 ] & 0x0ff , V_13 + 4 + 2 * V_11 ) ;
F_3 ( ( V_7 [ V_8 ] & 0xf00 ) >> 8 , V_13 + 4 + 2 * V_11 ) ;
F_5 ( V_13 + 4 + 2 * V_11 ) ;
V_14 -> V_15 [ V_11 ] = V_7 [ V_8 ] ;
}
return V_8 ;
}
static int F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
int V_8 ;
int V_11 = F_2 ( V_6 -> V_12 ) ;
for ( V_8 = 0 ; V_8 < V_6 -> V_8 ; V_8 ++ )
V_7 [ V_8 ] = V_14 -> V_15 [ V_11 ] ;
return V_8 ;
}
static int F_8 ( struct V_1 * V_2 , struct V_16 * V_17 )
{
unsigned long V_13 ;
int V_18 ;
struct V_3 * V_4 ;
V_13 = V_17 -> V_19 [ 0 ] ;
F_9 ( V_20 L_1 , V_2 -> V_21 , V_13 ) ;
if ( ! F_10 ( V_13 , V_22 , L_2 ) ) {
F_9 ( V_23 L_3 ) ;
return - V_24 ;
}
V_2 -> V_13 = V_13 ;
V_2 -> V_25 = L_2 ;
if ( F_11 ( V_2 , sizeof( struct V_26 ) ) < 0 )
return - V_27 ;
#if V_28
F_9 ( V_29 L_4 ) ;
#endif
V_18 = F_12 ( V_2 , 2 ) ;
if ( V_18 )
return V_18 ;
V_4 = & V_2 -> V_30 [ 0 ] ;
V_4 -> type = V_31 ;
V_4 -> V_32 = V_33 | V_34 ;
V_4 -> V_35 = 16 ;
V_4 -> V_36 = 0x0fff ;
V_4 -> V_37 = & V_38 ;
V_4 -> V_39 = F_1 ;
F_9 ( V_20 L_5 ) ;
V_4 = & V_2 -> V_30 [ 1 ] ;
V_4 -> type = V_40 ;
V_4 -> V_32 = V_41 ;
V_4 -> V_35 = 2 ;
V_4 -> V_36 = 0x0fff ;
V_4 -> V_37 = & V_38 ;
V_4 -> V_42 = F_6 ;
V_4 -> V_39 = F_7 ;
F_9 ( V_20 L_6 ) ;
return 1 ;
}
static void F_13 ( struct V_1 * V_2 )
{
if ( V_2 -> V_13 )
F_14 ( V_2 -> V_13 , V_22 ) ;
}
