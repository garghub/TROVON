static void T_1 F_1 ( void )
{
unsigned int V_1 ;
F_2 () ;
V_1 = V_2 -> V_3 [ V_4 ] & 0xff ;
V_2 -> V_3 [ V_4 ] = V_1 | V_5 ;
V_2 -> V_3 [ V_6 ] = 0 ;
V_2 -> V_3 [ V_7 ] = 0 ;
while ( 1 ) {
V_8 -> V_9 = ~ V_10 ;
V_1 = V_2 -> V_3 [ V_11 ] ;
}
}
static void T_1 F_3 ( char * V_12 )
{
if ( V_13 & V_14 )
F_1 () ;
V_15 -> V_16 |= V_17 ;
while ( 1 ) ;
}
static void T_1 F_4 ( void )
{
if ( V_13 & V_14 )
F_1 () ;
F_5 () ;
}
static void F_6 ( unsigned long V_18 )
{
F_1 () ;
}
static void F_7 ( unsigned long V_18 )
{
V_19 ^= ( V_20 | V_21 ) ;
V_8 -> V_22 = V_19 ;
F_8 ( & V_23 , V_24 + V_18 ) ;
}
static void F_9 ( unsigned long V_18 )
{
F_10 ( & V_25 ) ;
if ( V_26 -> V_27 & V_28 ) {
V_25 . V_29 = V_24 + ( V_30 / 20 ) ;
F_11 ( & V_25 ) ;
V_8 -> V_9 = V_10 | V_31 |
V_32 | V_33 |
V_34 | V_35 ;
return;
}
if ( V_13 & V_36 )
V_15 -> V_16 |= V_17 ;
F_12 ( V_37 ) ;
}
static inline void F_13 ( void )
{
if ( V_13 & V_36 )
return;
if ( ( V_13 & V_14 ) ||
F_14 ( V_38 , 1 ) ) {
F_1 () ;
}
V_13 |= V_14 ;
V_23 . V_18 = V_39 ;
F_7 ( V_39 ) ;
F_15 ( & V_40 ) ;
V_40 . V_41 = F_6 ;
V_40 . V_29 = V_24 + V_42 * V_30 ;
F_11 ( & V_40 ) ;
}
static T_2 F_16 ( int V_43 , void * V_44 )
{
unsigned int V_45 ;
V_45 = V_8 -> V_9 ;
V_8 -> V_9 = V_10 | V_31 ;
if ( V_26 -> V_27 & V_28 ) {
F_17 ( V_37 ) ;
F_15 ( & V_25 ) ;
V_25 . V_41 = F_9 ;
V_25 . V_29 = V_24 + 5 ;
F_11 ( & V_25 ) ;
}
if ( ! ( V_45 & V_31 ) )
F_13 () ;
return V_46 ;
}
static int F_18 ( struct V_47 * V_48 , unsigned long V_49 ,
void * V_50 )
{
if ( V_13 & V_36 )
return V_51 ;
V_13 |= V_36 ;
V_23 . V_18 = V_52 ;
F_7 ( V_52 ) ;
return V_51 ;
}
static int T_3 F_19 ( void )
{
int V_53 ;
V_54 = F_3 ;
V_55 = F_4 ;
V_56 = F_1 ;
V_53 = F_20 ( V_37 , F_16 , 0 , L_1 , NULL ) ;
if ( V_53 ) {
F_21 ( V_57 L_2 ) ;
return V_53 ;
}
F_15 ( & V_23 ) ;
V_23 . V_41 = F_7 ;
F_22 ( & V_58 , & V_59 ) ;
return 0 ;
}
