static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
int V_11 , V_12 ;
T_1 V_13 = 0 ;
unsigned int V_14 , V_15 ;
V_14 = F_2 ( V_6 -> V_16 ) ;
V_15 = V_17 [ F_3 ( ( V_6 -> V_16 ) ) ] ;
F_4 ( & V_9 -> V_18 ) ;
for ( V_11 = 0 ; V_11 < V_6 -> V_11 ; V_11 ++ ) {
F_5 () ;
F_6 ( 0x0000 + V_15 + V_14 , V_2 -> V_19 + 2 ) ;
F_7 ( 10 ) ;
for ( V_12 = 0 ; V_12 < V_20 ; V_12 ++ ) {
V_13 = F_8 ( V_2 -> V_19 ) ;
if ( V_13 & ( 1 << 15 ) )
goto V_21;
}
V_7 [ V_11 ] = 0 ;
F_9 ( V_22 L_1
L_2 ) ;
continue;
V_21:
V_13 &= 0x0FFF ;
V_7 [ V_11 ] = V_13 ;
}
F_10 ( & V_9 -> V_18 ) ;
return V_11 ;
}
static int F_11 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
int V_11 ;
unsigned int V_14 , V_15 ;
V_14 = F_2 ( V_6 -> V_16 ) ;
V_15 = V_17 [ F_3 ( ( V_6 -> V_16 ) ) ] ;
F_4 ( & V_9 -> V_18 ) ;
for ( V_11 = 0 ; V_11 < V_6 -> V_11 ; V_11 ++ ) {
F_5 () ;
F_6 ( V_7 [ V_11 ] , V_2 -> V_19 ) ;
F_7 ( 10 ) ;
}
F_10 ( & V_9 -> V_18 ) ;
return V_11 ;
}
static int F_12 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
T_1 V_13 = 0 ;
F_4 ( & V_9 -> V_18 ) ;
F_5 () ;
V_13 = F_8 ( V_9 -> V_23 ) ;
F_7 ( 10 ) ;
V_7 [ 1 ] = V_13 ;
V_7 [ 0 ] = V_4 -> V_24 ;
F_10 ( & V_9 -> V_18 ) ;
return V_6 -> V_11 ;
}
static int F_13 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
F_4 ( & V_9 -> V_18 ) ;
if ( V_7 [ 0 ] ) {
V_4 -> V_24 &= ~ V_7 [ 0 ] ;
V_4 -> V_24 |= ( V_7 [ 0 ] & V_7 [ 1 ] ) ;
F_5 () ;
F_6 ( V_4 -> V_24 , V_9 -> V_23 ) ;
F_7 ( 10 ) ;
}
V_7 [ 1 ] = V_4 -> V_24 ;
F_10 ( & V_9 -> V_18 ) ;
return V_6 -> V_11 ;
}
static int F_14 ( struct V_1 * V_2 ,
unsigned long V_25 )
{
struct V_26 * V_27 = F_15 ( V_2 ) ;
struct V_8 * V_9 ;
struct V_3 * V_4 ;
int V_28 ;
V_9 = F_16 ( sizeof( * V_9 ) , V_29 ) ;
if ( ! V_9 )
return - V_30 ;
V_2 -> V_10 = V_9 ;
V_28 = F_17 ( V_2 ) ;
if ( V_28 )
return V_28 ;
V_2 -> V_19 = F_18 ( V_27 , 2 ) ;
V_9 -> V_23 = F_18 ( V_27 , 3 ) ;
F_19 ( & V_9 -> V_18 ) ;
V_28 = F_20 ( V_2 , 4 ) ;
if ( V_28 )
return V_28 ;
V_4 = & V_2 -> V_31 [ 0 ] ;
V_4 -> type = V_32 ;
V_4 -> V_33 = V_34 | V_35 | V_36 ;
V_4 -> V_37 = 16 ;
V_4 -> V_38 = 0x0FFF ;
V_4 -> V_39 = & V_40 ;
V_4 -> V_41 = 16 ;
V_4 -> V_42 = F_1 ;
V_4 = & V_2 -> V_31 [ 1 ] ;
V_4 -> type = V_43 ;
V_4 -> V_33 = V_44 ;
V_4 -> V_37 = 16 ;
V_4 -> V_38 = 0x0FFF ;
V_4 -> V_39 = & V_45 ;
V_4 -> V_41 = 16 ;
V_4 -> V_46 = F_11 ;
V_4 = & V_2 -> V_31 [ 2 ] ;
V_4 -> type = V_47 ;
V_4 -> V_33 = V_34 | V_35 ;
V_4 -> V_37 = 16 ;
V_4 -> V_38 = 1 ;
V_4 -> V_39 = & V_48 ;
V_4 -> V_41 = 16 ;
V_4 -> V_49 = F_12 ;
V_4 = & V_2 -> V_31 [ 3 ] ;
V_4 -> type = V_50 ;
V_4 -> V_33 = V_44 | V_35 ;
V_4 -> V_37 = 16 ;
V_4 -> V_38 = 1 ;
V_4 -> V_39 = & V_48 ;
V_4 -> V_41 = 16 ;
V_4 -> V_24 = 0 ;
V_4 -> V_49 = F_13 ;
F_21 ( V_2 -> V_51 , L_3 , V_2 -> V_52 ) ;
return 0 ;
}
static void F_22 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
if ( V_9 )
F_23 ( & V_9 -> V_18 ) ;
F_24 ( V_2 ) ;
}
static int F_25 ( struct V_26 * V_2 ,
const struct V_53 * V_54 )
{
return F_26 ( V_2 , & V_55 ,
V_54 -> V_56 ) ;
}
