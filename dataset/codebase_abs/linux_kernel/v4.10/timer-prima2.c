static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
F_2 ( ! ( F_3 ( V_5 + V_6 ) &
F_4 ( 0 ) ) ) ;
F_5 ( F_4 ( 0 ) , V_5 + V_6 ) ;
V_4 -> V_7 ( V_4 ) ;
return V_8 ;
}
static T_2 T_3 F_6 ( struct V_9 * V_10 )
{
T_2 V_11 ;
F_5 ( V_12 ,
V_5 + V_13 ) ;
V_11 = F_3 ( V_5 + V_14 ) ;
V_11 = ( V_11 << 32 ) |
F_3 ( V_5 + V_15 ) ;
return V_11 ;
}
static int F_7 ( unsigned long V_16 ,
struct V_3 * V_4 )
{
unsigned long V_17 , V_18 ;
F_5 ( V_12 ,
V_5 + V_13 ) ;
V_17 = F_3 ( V_5 + V_15 ) ;
V_18 = V_17 + V_16 ;
F_5 ( V_18 , V_5 + V_19 ) ;
F_5 ( V_12 ,
V_5 + V_13 ) ;
V_17 = F_3 ( V_5 + V_15 ) ;
return V_18 - V_17 > V_16 ? - V_20 : 0 ;
}
static int F_8 ( struct V_3 * V_21 )
{
T_4 V_22 = F_3 ( V_5 + V_23 ) ;
F_5 ( V_22 & ~ F_4 ( 0 ) ,
V_5 + V_23 ) ;
return 0 ;
}
static int F_9 ( struct V_3 * V_21 )
{
T_4 V_22 = F_3 ( V_5 + V_23 ) ;
F_5 ( V_22 | F_4 ( 0 ) , V_5 + V_23 ) ;
return 0 ;
}
static void F_10 ( struct V_9 * V_10 )
{
int V_24 ;
F_5 ( V_12 ,
V_5 + V_13 ) ;
for ( V_24 = 0 ; V_24 < V_25 ; V_24 ++ )
V_26 [ V_24 ] =
F_3 ( V_5 +
V_27 [ V_24 ] ) ;
}
static void F_11 ( struct V_9 * V_10 )
{
int V_24 ;
for ( V_24 = 0 ; V_24 < V_25 - 2 ; V_24 ++ )
F_5 ( V_26 [ V_24 ] ,
V_5 + V_27 [ V_24 ] ) ;
F_5 ( V_26 [ V_25 - 2 ] ,
V_5 + V_28 ) ;
F_5 ( V_26 [ V_25 - 1 ] ,
V_5 + V_29 ) ;
}
static T_2 T_3 F_12 ( void )
{
return F_6 ( NULL ) ;
}
static void T_5 F_13 ( void )
{
V_30 . V_31 = F_14 ( 0 ) ;
F_15 ( & V_30 , V_32 ,
2 , - 2 ) ;
}
static int T_5 F_16 ( struct V_33 * V_34 )
{
unsigned long V_35 ;
struct V_36 * V_36 ;
int V_37 ;
V_36 = F_17 ( V_34 , 0 ) ;
if ( F_18 ( V_36 ) ) {
F_19 ( L_1 ) ;
return F_20 ( V_36 ) ;
}
V_37 = F_21 ( V_36 ) ;
if ( V_37 ) {
F_19 ( L_2 ) ;
return V_37 ;
}
V_35 = F_22 ( V_36 ) ;
if ( V_35 < V_32 || V_35 % V_32 ) {
F_19 ( L_3 ) ;
return - V_38 ;
}
V_5 = F_23 ( V_34 , 0 ) ;
if ( ! V_5 ) {
F_19 ( L_4 ) ;
return - V_39 ;
}
V_40 . V_1 = F_24 ( V_34 , 0 ) ;
F_5 ( V_35 / V_32 / 2 - 1 ,
V_5 + V_41 ) ;
F_5 ( 0 , V_5 + V_28 ) ;
F_5 ( 0 , V_5 + V_29 ) ;
F_5 ( F_4 ( 0 ) , V_5 + V_6 ) ;
V_37 = F_25 ( & V_42 , V_32 ) ;
if ( V_37 ) {
F_19 ( L_5 ) ;
return V_37 ;
}
F_26 ( F_12 , 64 , V_32 ) ;
V_37 = F_27 ( V_40 . V_1 , & V_40 ) ;
if ( V_37 ) {
F_19 ( L_6 ) ;
return V_37 ;
}
F_13 () ;
return 0 ;
}
