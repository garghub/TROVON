static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned long V_7 )
{
unsigned int V_8 ;
V_8 = F_2 ( V_2 -> V_9 ) ;
if ( V_8 & ( 1 << 15 ) )
return 0 ;
return - V_10 ;
}
static int F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_11 )
{
struct V_12 * V_13 = V_2 -> V_14 ;
int V_15 ;
T_1 V_16 = 0 ;
int V_17 = 0 ;
unsigned int V_18 , V_19 ;
V_18 = F_4 ( V_6 -> V_20 ) ;
V_19 = V_21 [ F_5 ( ( V_6 -> V_20 ) ) ] ;
F_6 ( & V_13 -> V_22 ) ;
for ( V_15 = 0 ; V_15 < V_6 -> V_15 ; V_15 ++ ) {
F_7 () ;
F_8 ( 0x0000 + V_19 + V_18 , V_2 -> V_9 + 2 ) ;
F_9 ( 10 ) ;
V_17 = F_10 ( V_2 , V_4 , V_6 , F_1 , 0 ) ;
if ( V_17 )
break;
V_16 = F_2 ( V_2 -> V_9 ) ;
V_16 &= 0x0FFF ;
V_11 [ V_15 ] = V_16 ;
}
F_11 ( & V_13 -> V_22 ) ;
return V_17 ? V_17 : V_15 ;
}
static int F_12 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_11 )
{
struct V_12 * V_13 = V_2 -> V_14 ;
int V_15 ;
unsigned int V_18 , V_19 ;
V_18 = F_4 ( V_6 -> V_20 ) ;
V_19 = V_21 [ F_5 ( ( V_6 -> V_20 ) ) ] ;
F_6 ( & V_13 -> V_22 ) ;
for ( V_15 = 0 ; V_15 < V_6 -> V_15 ; V_15 ++ ) {
F_7 () ;
F_8 ( V_11 [ V_15 ] , V_2 -> V_9 ) ;
F_9 ( 10 ) ;
}
F_11 ( & V_13 -> V_22 ) ;
return V_15 ;
}
static int F_13 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_11 )
{
struct V_12 * V_13 = V_2 -> V_14 ;
T_1 V_16 = 0 ;
F_6 ( & V_13 -> V_22 ) ;
F_7 () ;
V_16 = F_2 ( V_13 -> V_23 ) ;
F_9 ( 10 ) ;
V_11 [ 1 ] = V_16 ;
V_11 [ 0 ] = V_4 -> V_24 ;
F_11 ( & V_13 -> V_22 ) ;
return V_6 -> V_15 ;
}
static int F_14 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_11 )
{
struct V_12 * V_13 = V_2 -> V_14 ;
F_6 ( & V_13 -> V_22 ) ;
if ( F_15 ( V_4 , V_11 ) ) {
F_7 () ;
F_8 ( V_4 -> V_24 , V_13 -> V_23 ) ;
F_9 ( 10 ) ;
}
V_11 [ 1 ] = V_4 -> V_24 ;
F_11 ( & V_13 -> V_22 ) ;
return V_6 -> V_15 ;
}
static int F_16 ( struct V_1 * V_2 ,
unsigned long V_25 )
{
struct V_26 * V_27 = F_17 ( V_2 ) ;
struct V_12 * V_13 ;
struct V_3 * V_4 ;
int V_17 ;
V_13 = F_18 ( V_2 , sizeof( * V_13 ) ) ;
if ( ! V_13 )
return - V_28 ;
V_17 = F_19 ( V_2 ) ;
if ( V_17 )
return V_17 ;
V_2 -> V_9 = F_20 ( V_27 , 2 ) ;
V_13 -> V_23 = F_20 ( V_27 , 3 ) ;
F_21 ( & V_13 -> V_22 ) ;
V_17 = F_22 ( V_2 , 4 ) ;
if ( V_17 )
return V_17 ;
V_4 = & V_2 -> V_29 [ 0 ] ;
V_4 -> type = V_30 ;
V_4 -> V_31 = V_32 | V_33 | V_34 ;
V_4 -> V_35 = 16 ;
V_4 -> V_36 = 0x0FFF ;
V_4 -> V_37 = & V_38 ;
V_4 -> V_39 = 16 ;
V_4 -> V_40 = F_3 ;
V_4 = & V_2 -> V_29 [ 1 ] ;
V_4 -> type = V_41 ;
V_4 -> V_31 = V_42 ;
V_4 -> V_35 = 16 ;
V_4 -> V_36 = 0x0FFF ;
V_4 -> V_37 = & V_43 ;
V_4 -> V_39 = 16 ;
V_4 -> V_44 = F_12 ;
V_4 = & V_2 -> V_29 [ 2 ] ;
V_4 -> type = V_45 ;
V_4 -> V_31 = V_32 ;
V_4 -> V_35 = 16 ;
V_4 -> V_36 = 1 ;
V_4 -> V_37 = & V_46 ;
V_4 -> V_39 = 16 ;
V_4 -> V_47 = F_13 ;
V_4 = & V_2 -> V_29 [ 3 ] ;
V_4 -> type = V_48 ;
V_4 -> V_31 = V_42 ;
V_4 -> V_35 = 16 ;
V_4 -> V_36 = 1 ;
V_4 -> V_37 = & V_46 ;
V_4 -> V_39 = 16 ;
V_4 -> V_24 = 0 ;
V_4 -> V_47 = F_14 ;
return 0 ;
}
static void F_23 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = V_2 -> V_14 ;
F_24 ( V_2 ) ;
if ( V_13 )
F_25 ( & V_13 -> V_22 ) ;
}
static int F_26 ( struct V_26 * V_2 ,
const struct V_49 * V_50 )
{
return F_27 ( V_2 , & V_51 ,
V_50 -> V_52 ) ;
}
