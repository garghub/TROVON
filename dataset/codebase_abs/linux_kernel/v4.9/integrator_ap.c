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
if ( V_17 == V_20 ) {
V_15 = 1 << 4 ;
V_16 = 1 << 5 ;
} else {
V_15 = 1 << 6 ;
V_16 = 1 << 7 ;
}
if ( V_12 & V_21 )
V_14 |= V_15 ;
else
V_13 |= V_15 ;
if ( V_12 & V_22 )
V_14 |= V_16 ;
else
V_13 |= V_16 ;
F_13 ( V_13 , V_23 + V_24 ) ;
F_13 ( V_14 , V_23 + V_25 ) ;
}
void T_1 F_14 ( void )
{
}
static void T_1 F_15 ( void )
{
F_16 () ;
F_17 () ;
}
static void T_1 F_18 ( void )
{
unsigned long V_26 ;
struct V_27 * V_28 ;
struct V_27 * V_29 ;
int V_30 ;
V_28 = F_19 ( NULL , V_31 ) ;
if ( ! V_28 )
return;
V_29 = F_19 ( NULL , V_32 ) ;
if ( ! V_29 )
return;
V_23 = F_20 ( V_28 , 0 ) ;
if ( ! V_23 )
return;
V_33 = F_20 ( V_29 , 0 ) ;
if ( ! V_33 )
return;
F_21 ( NULL , V_34 , NULL ) ;
V_26 = F_6 ( V_23 + V_35 ) ;
for ( V_30 = 0 ; V_30 < 4 ; V_30 ++ ) {
struct V_36 * V_37 ;
if ( ( V_26 & ( 16 << V_30 ) ) == 0 )
continue;
V_37 = F_22 ( sizeof( struct V_36 ) , V_38 ) ;
if ( ! V_37 )
continue;
V_37 -> V_39 . V_19 = 0xc0000000 + 0x10000000 * V_30 ;
V_37 -> V_39 . V_40 = V_37 -> V_39 . V_19 + 0x0fffffff ;
V_37 -> V_39 . V_41 = V_42 ;
V_37 -> V_43 = F_23 ( V_28 , V_30 ) ;
V_37 -> V_44 = V_30 ;
F_24 ( V_37 ) ;
}
}
