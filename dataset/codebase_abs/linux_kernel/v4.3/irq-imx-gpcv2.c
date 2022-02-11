T_1 F_1 ( T_1 * * V_1 )
{
if ( ! V_2 )
return 0 ;
if ( V_1 )
* V_1 = V_2 -> V_3 ;
return V_4 ;
}
static int F_2 ( void )
{
struct V_5 * V_6 ;
void T_2 * V_7 ;
int V_8 ;
V_6 = V_2 ;
if ( ! V_6 )
return 0 ;
for ( V_8 = 0 ; V_8 < V_4 ; V_8 ++ ) {
V_7 = V_6 -> V_9 + V_6 -> V_10 + V_8 * 4 ;
V_6 -> V_11 [ V_8 ] = F_3 ( V_7 ) ;
F_4 ( V_6 -> V_3 [ V_8 ] , V_7 ) ;
}
return 0 ;
}
static void F_5 ( void )
{
struct V_5 * V_6 ;
void T_2 * V_7 ;
int V_8 ;
V_6 = V_2 ;
if ( ! V_6 )
return;
for ( V_8 = 0 ; V_8 < V_4 ; V_8 ++ ) {
V_7 = V_6 -> V_9 + V_6 -> V_10 + V_8 * 4 ;
F_4 ( V_6 -> V_11 [ V_8 ] , V_7 ) ;
}
}
static int F_6 ( struct V_12 * V_13 , unsigned int V_14 )
{
struct V_5 * V_6 = V_13 -> V_15 ;
unsigned int V_16 = V_13 -> V_17 / 32 ;
unsigned long V_18 ;
void T_2 * V_7 ;
T_1 V_19 , V_20 ;
F_7 ( & V_6 -> V_21 , V_18 ) ;
V_7 = V_6 -> V_9 + V_6 -> V_10 + V_16 * 4 ;
V_19 = 1 << V_13 -> V_17 % 32 ;
V_20 = V_6 -> V_3 [ V_16 ] ;
V_6 -> V_3 [ V_16 ] = V_14 ? ( V_20 & ~ V_19 ) : ( V_20 | V_19 ) ;
F_8 ( & V_6 -> V_21 , V_18 ) ;
return 0 ;
}
static void F_9 ( struct V_12 * V_13 )
{
struct V_5 * V_6 = V_13 -> V_15 ;
void T_2 * V_7 ;
T_1 V_20 ;
F_10 ( & V_6 -> V_21 ) ;
V_7 = V_6 -> V_9 + V_6 -> V_10 + V_13 -> V_17 / 32 * 4 ;
V_20 = F_3 ( V_7 ) ;
V_20 &= ~ ( 1 << V_13 -> V_17 % 32 ) ;
F_4 ( V_20 , V_7 ) ;
F_11 ( & V_6 -> V_21 ) ;
F_12 ( V_13 ) ;
}
static void F_13 ( struct V_12 * V_13 )
{
struct V_5 * V_6 = V_13 -> V_15 ;
void T_2 * V_7 ;
T_1 V_20 ;
F_10 ( & V_6 -> V_21 ) ;
V_7 = V_6 -> V_9 + V_6 -> V_10 + V_13 -> V_17 / 32 * 4 ;
V_20 = F_3 ( V_7 ) ;
V_20 |= 1 << ( V_13 -> V_17 % 32 ) ;
F_4 ( V_20 , V_7 ) ;
F_11 ( & V_6 -> V_21 ) ;
F_14 ( V_13 ) ;
}
static int F_15 ( struct V_22 * V_23 ,
struct V_24 * V_25 ,
const T_1 * V_26 ,
unsigned int V_27 ,
unsigned long * V_28 ,
unsigned int * V_29 )
{
if ( V_23 -> V_30 != V_25 )
return - V_31 ;
if ( V_27 != 3 )
return - V_31 ;
if ( V_26 [ 0 ] != 0 )
return - V_31 ;
* V_28 = V_26 [ 1 ] ;
* V_29 = V_26 [ 2 ] ;
return 0 ;
}
static int F_16 ( struct V_22 * V_23 ,
unsigned int V_32 , unsigned int V_33 ,
void * V_34 )
{
struct V_35 * args = V_34 ;
struct V_35 V_36 ;
T_3 V_17 ;
int V_8 ;
if ( args -> V_37 != 3 )
return - V_31 ;
if ( args -> args [ 0 ] != 0 )
return - V_31 ;
V_17 = args -> args [ 1 ] ;
if ( V_17 >= V_38 )
return - V_31 ;
for ( V_8 = 0 ; V_8 < V_33 ; V_8 ++ ) {
F_17 ( V_23 , V_32 + V_8 , V_17 + V_8 ,
& V_39 , V_23 -> V_40 ) ;
}
V_36 = * args ;
V_36 . V_41 = V_23 -> V_42 -> V_30 ;
return F_18 ( V_23 , V_32 , V_33 , & V_36 ) ;
}
static int T_4 F_19 ( struct V_24 * V_43 ,
struct V_24 * V_42 )
{
struct V_22 * V_44 , * V_23 ;
struct V_5 * V_6 ;
int V_8 ;
if ( ! V_42 ) {
F_20 ( L_1 , V_43 -> V_45 ) ;
return - V_46 ;
}
V_44 = F_21 ( V_42 ) ;
if ( ! V_44 ) {
F_20 ( L_2 , V_43 -> V_45 ) ;
return - V_47 ;
}
V_6 = F_22 ( sizeof( struct V_5 ) , V_48 ) ;
if ( ! V_6 ) {
F_20 ( L_3 ) ;
return - V_49 ;
}
V_6 -> V_9 = F_23 ( V_43 , 0 ) ;
if ( ! V_6 -> V_9 ) {
F_20 ( L_4 ) ;
F_24 ( V_6 ) ;
return - V_49 ;
}
V_23 = F_25 ( V_44 , 0 , V_38 ,
V_43 , & V_50 , V_6 ) ;
if ( ! V_23 ) {
F_26 ( V_6 -> V_9 ) ;
F_24 ( V_6 ) ;
return - V_49 ;
}
F_27 ( V_23 ) ;
for ( V_8 = 0 ; V_8 < V_4 ; V_8 ++ ) {
F_4 ( ~ 0 , V_6 -> V_9 + V_51 + V_8 * 4 ) ;
F_4 ( ~ 0 , V_6 -> V_9 + V_52 + V_8 * 4 ) ;
V_6 -> V_3 [ V_8 ] = ~ 0 ;
}
V_6 -> V_10 = V_51 ;
F_4 ( ~ 0x1 , V_6 -> V_9 + V_6 -> V_10 ) ;
V_2 = V_6 ;
F_28 ( & V_53 ) ;
return 0 ;
}
