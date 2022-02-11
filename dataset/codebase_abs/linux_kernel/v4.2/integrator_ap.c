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
static int F_12 ( struct V_9 * V_10 )
{
T_2 V_11 ;
F_9 ( V_12 | V_13 ,
V_14 + V_15 ) ;
V_11 = F_6 ( V_16 + V_17 ) |
V_18 ;
F_9 ( V_11 , V_16 + V_17 ) ;
if ( ! ( F_6 ( V_16 + V_17 )
& V_18 ) ) {
F_9 ( 0xa05f , V_16 + V_19 ) ;
F_9 ( V_11 , V_16 + V_17 ) ;
F_9 ( 0 , V_16 + V_19 ) ;
}
return 0 ;
}
static void F_13 ( struct V_9 * V_10 )
{
T_2 V_11 ;
F_9 ( V_12 | V_13 ,
V_14 + V_15 ) ;
V_11 = F_6 ( V_16 + V_17 ) &
~ V_18 ;
F_9 ( V_11 , V_16 + V_17 ) ;
if ( F_6 ( V_16 + V_17 ) &
V_18 ) {
F_9 ( 0xa05f , V_16 + V_19 ) ;
F_9 ( V_11 , V_16 + V_17 ) ;
F_9 ( 0 , V_16 + V_19 ) ;
}
}
static void F_14 ( struct V_9 * V_20 , int V_21 )
{
if ( V_21 )
F_9 ( V_12 ,
V_14 + V_22 ) ;
else
F_9 ( V_12 ,
V_14 + V_15 ) ;
}
static void F_15 ( struct V_23 * V_10 ,
void T_3 * V_24 , unsigned int V_25 )
{
unsigned int V_26 = 0 , V_27 = 0 , V_28 , V_29 ;
T_2 V_30 = V_10 -> V_31 . V_32 ;
if ( V_30 == V_33 ) {
V_28 = 1 << 4 ;
V_29 = 1 << 5 ;
} else {
V_28 = 1 << 6 ;
V_29 = 1 << 7 ;
}
if ( V_25 & V_34 )
V_27 |= V_28 ;
else
V_26 |= V_28 ;
if ( V_25 & V_35 )
V_27 |= V_29 ;
else
V_26 |= V_29 ;
F_16 ( V_26 , V_14 + V_22 ) ;
F_16 ( V_27 , V_14 + V_15 ) ;
}
void T_1 F_17 ( void )
{
}
static void T_1 F_18 ( void )
{
F_19 () ;
F_20 () ;
}
static void T_1 F_21 ( void )
{
unsigned long V_36 ;
struct V_37 * V_38 ;
struct V_37 * V_39 ;
int V_40 ;
V_38 = F_22 ( NULL , V_41 ) ;
if ( ! V_38 )
return;
V_39 = F_22 ( NULL , V_42 ) ;
if ( ! V_39 )
return;
V_14 = F_23 ( V_38 , 0 ) ;
if ( ! V_14 )
return;
V_16 = F_23 ( V_39 , 0 ) ;
if ( ! V_16 )
return;
F_24 ( NULL , V_43 ,
V_44 , NULL ) ;
V_36 = F_6 ( V_14 + V_45 ) ;
for ( V_40 = 0 ; V_40 < 4 ; V_40 ++ ) {
struct V_46 * V_47 ;
if ( ( V_36 & ( 16 << V_40 ) ) == 0 )
continue;
V_47 = F_25 ( sizeof( struct V_46 ) , V_48 ) ;
if ( ! V_47 )
continue;
V_47 -> V_49 . V_32 = 0xc0000000 + 0x10000000 * V_40 ;
V_47 -> V_49 . V_50 = V_47 -> V_49 . V_32 + 0x0fffffff ;
V_47 -> V_49 . V_51 = V_52 ;
V_47 -> V_53 = F_26 ( V_38 , V_40 ) ;
V_47 -> V_54 = V_40 ;
F_27 ( V_47 ) ;
}
}
