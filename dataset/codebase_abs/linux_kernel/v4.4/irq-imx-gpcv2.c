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
static int F_15 ( struct V_22 * V_13 ,
struct V_23 * V_24 ,
unsigned long * V_17 ,
unsigned int * type )
{
if ( F_16 ( V_24 -> V_25 ) ) {
if ( V_24 -> V_26 != 3 )
return - V_27 ;
if ( V_24 -> V_28 [ 0 ] != 0 )
return - V_27 ;
* V_17 = V_24 -> V_28 [ 1 ] ;
* type = V_24 -> V_28 [ 2 ] ;
return 0 ;
}
return - V_27 ;
}
static int F_17 ( struct V_22 * V_29 ,
unsigned int V_30 , unsigned int V_31 ,
void * V_32 )
{
struct V_23 * V_24 = V_32 ;
struct V_23 V_33 ;
T_3 V_17 ;
unsigned int type ;
int V_34 ;
int V_8 ;
V_34 = F_15 ( V_29 , V_24 , & V_17 , & type ) ;
if ( V_34 )
return V_34 ;
if ( V_17 >= V_35 )
return - V_27 ;
for ( V_8 = 0 ; V_8 < V_31 ; V_8 ++ ) {
F_18 ( V_29 , V_30 + V_8 , V_17 + V_8 ,
& V_36 , V_29 -> V_37 ) ;
}
V_33 = * V_24 ;
V_33 . V_25 = V_29 -> V_38 -> V_25 ;
return F_19 ( V_29 , V_30 , V_31 ,
& V_33 ) ;
}
static int T_4 F_20 ( struct V_39 * V_40 ,
struct V_39 * V_38 )
{
struct V_22 * V_41 , * V_29 ;
struct V_5 * V_6 ;
int V_8 ;
if ( ! V_38 ) {
F_21 ( L_1 , V_40 -> V_42 ) ;
return - V_43 ;
}
V_41 = F_22 ( V_38 ) ;
if ( ! V_41 ) {
F_21 ( L_2 , V_40 -> V_42 ) ;
return - V_44 ;
}
V_6 = F_23 ( sizeof( struct V_5 ) , V_45 ) ;
if ( ! V_6 ) {
F_21 ( L_3 ) ;
return - V_46 ;
}
V_6 -> V_9 = F_24 ( V_40 , 0 ) ;
if ( ! V_6 -> V_9 ) {
F_21 ( L_4 ) ;
F_25 ( V_6 ) ;
return - V_46 ;
}
V_29 = F_26 ( V_41 , 0 , V_35 ,
V_40 , & V_47 , V_6 ) ;
if ( ! V_29 ) {
F_27 ( V_6 -> V_9 ) ;
F_25 ( V_6 ) ;
return - V_46 ;
}
F_28 ( V_29 ) ;
for ( V_8 = 0 ; V_8 < V_4 ; V_8 ++ ) {
F_4 ( ~ 0 , V_6 -> V_9 + V_48 + V_8 * 4 ) ;
F_4 ( ~ 0 , V_6 -> V_9 + V_49 + V_8 * 4 ) ;
V_6 -> V_3 [ V_8 ] = ~ 0 ;
}
V_6 -> V_10 = V_48 ;
F_4 ( ~ 0x1 , V_6 -> V_9 + V_6 -> V_10 ) ;
V_2 = V_6 ;
F_29 ( & V_50 ) ;
return 0 ;
}
