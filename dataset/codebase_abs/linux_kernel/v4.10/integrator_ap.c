static void T_1 F_1 ( void )
{
F_2 ( V_1 , F_3 ( V_1 ) ) ;
F_4 () ;
}
static int F_5 ( void )
{
V_2 = F_6 ( V_3 + V_4 ) ;
return 0 ;
}
static void F_7 ( void )
{
F_8 () ;
F_9 ( - 1 , V_3 + V_5 ) ;
F_9 ( - 1 , V_3 + V_6 ) ;
F_9 ( V_2 , V_3 + V_7 ) ;
}
static int T_1 F_10 ( void )
{
F_11 ( & V_8 ) ;
return 0 ;
}
static void F_12 ( struct V_9 * V_10 ,
void T_2 * V_11 , unsigned int V_12 )
{
unsigned int V_13 = 0 , V_14 = 0 , V_15 , V_16 ;
T_3 V_17 = V_10 -> V_18 . V_19 ;
int V_20 ;
if ( V_17 == V_21 ) {
V_15 = 1 << 4 ;
V_16 = 1 << 5 ;
} else {
V_15 = 1 << 6 ;
V_16 = 1 << 7 ;
}
if ( V_12 & V_22 )
V_14 |= V_15 ;
else
V_13 |= V_15 ;
if ( V_12 & V_23 )
V_14 |= V_16 ;
else
V_13 |= V_16 ;
V_20 = F_13 ( V_24 ,
V_25 ,
V_13 ) ;
if ( V_20 )
F_14 ( L_1 ) ;
V_20 = F_13 ( V_24 ,
V_26 ,
V_14 ) ;
if ( V_20 )
F_14 ( L_2 ) ;
}
void T_1 F_15 ( void )
{
}
static void T_1 F_16 ( void )
{
F_17 () ;
F_18 () ;
}
static void T_1 F_19 ( void )
{
T_3 V_27 ;
struct V_28 * V_29 ;
int V_20 ;
int V_30 ;
F_20 ( NULL , V_31 , NULL ) ;
V_29 = F_21 ( NULL , V_32 ) ;
if ( ! V_29 )
return;
V_24 = F_22 ( V_29 ) ;
if ( F_23 ( V_24 ) ) {
F_24 ( L_3 ) ;
return;
}
V_20 = F_25 ( V_24 ,
V_33 ,
& V_27 ) ;
if ( V_20 ) {
F_24 ( L_4 ) ;
return;
}
for ( V_30 = 0 ; V_30 < 4 ; V_30 ++ ) {
struct V_34 * V_35 ;
if ( ( V_27 & ( 16 << V_30 ) ) == 0 )
continue;
V_35 = F_26 ( sizeof( struct V_34 ) , V_36 ) ;
if ( ! V_35 )
continue;
V_35 -> V_37 . V_19 = 0xc0000000 + 0x10000000 * V_30 ;
V_35 -> V_37 . V_38 = V_35 -> V_37 . V_19 + 0x0fffffff ;
V_35 -> V_37 . V_39 = V_40 ;
V_35 -> V_41 = F_27 ( V_29 , V_30 ) ;
V_35 -> V_42 = V_30 ;
F_28 ( V_35 ) ;
}
}
