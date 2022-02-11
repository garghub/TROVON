static int F_1 ( struct V_1 * V_2 , int V_3 , unsigned char V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned char V_7 [ 2 ] ;
V_7 [ 0 ] = V_3 & 0x7f ;
V_7 [ 1 ] = V_4 ;
return F_3 ( V_6 , V_7 , F_4 ( V_7 ) ) ;
}
static int F_5 ( struct V_1 * V_2 , unsigned char * V_8 , int V_9 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_10 [ 1 ] , V_11 [ 1 ] ;
int V_12 , V_13 ;
V_13 = 0 ;
for ( V_12 = 0 ; V_13 == 0 && V_12 < V_9 ; V_12 ++ ) {
V_10 [ 0 ] = 0x80 | V_8 [ V_12 ] ;
V_13 = F_6 ( V_6 , V_10 , 1 , V_11 , 1 ) ;
V_8 [ V_12 ] = V_11 [ 0 ] ;
}
return V_13 ;
}
static int F_7 ( struct V_1 * V_2 , struct V_14 * V_15 )
{
int V_13 ;
unsigned char V_7 [] = { V_16 , V_17 , V_18 ,
V_19 , V_20 , V_21 } ;
V_13 = F_5 ( V_2 , V_7 , F_4 ( V_7 ) ) ;
if ( V_13 )
return V_13 ;
memset ( V_15 , 0 , sizeof( * V_15 ) ) ;
V_15 -> V_22 = F_8 ( V_7 [ 0 ] ) ;
V_15 -> V_23 = F_8 ( V_7 [ 1 ] ) ;
V_15 -> V_24 = F_8 ( V_7 [ 2 ] ) ;
V_15 -> V_25 = F_8 ( V_7 [ 3 ] ) ;
V_15 -> V_26 = F_8 ( V_7 [ 4 ] ) - 1 ;
V_15 -> V_27 = F_8 ( V_7 [ 5 ] ) + 100 ;
return F_9 ( V_15 ) ;
}
static int F_10 ( struct V_1 * V_2 , struct V_14 * V_15 )
{
int V_13 , V_28 ;
V_28 = V_15 -> V_27 + 1900 ;
if ( V_28 >= 2100 || V_28 < 2000 )
return - V_29 ;
V_13 = F_1 ( V_2 , V_18 , F_11 ( V_15 -> V_24 ) ) ;
V_13 = V_13 ? V_13 : F_1 ( V_2 , V_17 , F_11 ( V_15 -> V_23 ) ) ;
V_13 = V_13 ? V_13 : F_1 ( V_2 , V_16 , F_11 ( V_15 -> V_22 ) ) ;
V_13 = V_13 ? V_13 : F_1 ( V_2 , V_19 , F_11 ( V_15 -> V_25 ) ) ;
V_13 = V_13 ? V_13 : F_1 ( V_2 , V_20 , F_11 ( V_15 -> V_26 + 1 ) ) ;
V_13 = V_13 ? V_13 : F_1 ( V_2 , V_21 , F_11 ( V_15 -> V_27 - 100 ) ) ;
V_13 = V_13 ? V_13 : F_1 ( V_2 , V_30 , 1 << V_15 -> V_31 ) ;
return V_13 ;
}
static int T_2 F_12 ( struct V_5 * V_6 )
{
struct V_32 * V_33 ;
unsigned char V_34 ;
int V_35 ;
V_34 = V_36 ;
V_35 = F_5 ( & V_6 -> V_2 , & V_34 , 1 ) ;
if ( V_35 || V_34 != 0x20 ) {
F_13 ( & V_6 -> V_2 , L_1 ) ;
return - V_37 ;
}
V_33 = F_14 ( L_2 ,
& V_6 -> V_2 , & V_38 , V_39 ) ;
if ( F_15 ( V_33 ) )
return F_16 ( V_33 ) ;
F_17 ( & V_6 -> V_2 , V_33 ) ;
return 0 ;
}
static int T_3 F_18 ( struct V_5 * V_6 )
{
struct V_32 * V_33 = F_19 ( & V_6 -> V_2 ) ;
F_20 ( V_33 ) ;
return 0 ;
}
static T_4 int F_21 ( void )
{
return F_22 ( & V_40 ) ;
}
static T_5 void F_23 ( void )
{
F_24 ( & V_40 ) ;
}
