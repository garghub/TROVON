static int T_1 F_1 ( void )
{
if ( V_1 == V_2 ) {
F_2 ( & V_3 ) ;
F_2 ( & V_4 ) ;
F_2 ( & V_5 ) ;
F_2 ( & V_6 ) ;
F_3 () ;
}
return 0 ;
}
static void F_4 ( struct V_7 * V_8 )
{
unsigned int V_9 , V_10 = V_8 -> V_10 - V_11 ;
unsigned long V_12 ;
V_9 = 1 << V_10 ;
F_5 ( & V_13 , V_12 ) ;
V_14 |= V_9 ;
if ( V_10 & 8 )
F_6 ( V_15 , V_16 + V_17 ) ;
else
F_6 ( V_18 , V_19 + V_17 ) ;
F_7 ( & V_13 , V_12 ) ;
}
static void F_8 ( struct V_7 * V_8 )
{
unsigned int V_9 , V_10 = V_8 -> V_10 - V_11 ;
unsigned long V_12 ;
V_9 = ~ ( 1 << V_10 ) ;
F_5 ( & V_13 , V_12 ) ;
V_14 &= V_9 ;
if ( V_10 & 8 )
F_6 ( V_15 , V_16 + V_17 ) ;
else
F_6 ( V_18 , V_19 + V_17 ) ;
F_7 ( & V_13 , V_12 ) ;
}
static inline int F_9 ( unsigned int V_10 )
{
int V_20 ;
int V_21 = 1 << V_10 ;
if ( V_10 < 8 ) {
F_6 ( 0x0B , V_19 + V_22 ) ;
V_20 = F_10 ( V_19 + V_22 ) & V_21 ;
F_6 ( 0x0A , V_19 + V_22 ) ;
return V_20 ;
}
F_6 ( 0x0B , V_16 + V_22 ) ;
V_20 = F_10 ( V_16 + V_22 ) & ( V_21 >> 8 ) ;
F_6 ( 0x0A , V_16 + V_22 ) ;
return V_20 ;
}
void F_11 ( struct V_7 * V_8 )
{
unsigned int V_21 , V_10 = V_8 -> V_10 - V_11 ;
unsigned long V_12 ;
V_21 = 1 << V_10 ;
F_5 ( & V_13 , V_12 ) ;
if ( V_14 & V_21 )
goto V_23;
V_14 |= V_21 ;
V_24:
if ( V_10 & 8 ) {
F_10 ( V_16 + V_17 ) ;
F_6 ( V_15 , V_16 + V_17 ) ;
F_6 ( 0x60 + ( V_10 & 7 ) , V_16 + V_22 ) ;
F_6 ( 0x60 + V_25 , V_19 + V_22 ) ;
} else {
F_10 ( V_19 + V_17 ) ;
F_6 ( V_18 , V_19 + V_17 ) ;
F_6 ( 0x60 + V_10 , V_19 + V_22 ) ;
}
F_7 ( & V_13 , V_12 ) ;
return;
V_23:
if ( F_9 ( V_10 ) )
goto V_24;
{
static int V_26 ;
if ( ! ( V_26 & V_21 ) ) {
F_12 ( V_27
L_1 , V_10 ) ;
V_26 |= V_21 ;
}
F_13 ( & V_28 ) ;
goto V_24;
}
}
static inline int F_14 ( void )
{
int V_10 ;
F_15 ( & V_13 ) ;
F_6 ( 0x0C , V_19 + V_22 ) ;
V_10 = F_10 ( V_19 + V_22 ) & 7 ;
if ( V_10 == V_25 ) {
F_6 ( 0x0C , V_16 + V_22 ) ;
V_10 = ( F_10 ( V_16 + V_22 ) & 7 ) + 8 ;
}
if ( F_16 ( V_10 == 7 ) ) {
F_6 ( 0x0B , V_19 + V_29 ) ;
if ( ~ F_10 ( V_19 + V_29 ) & 0x80 )
V_10 = - 1 ;
}
F_17 ( & V_13 ) ;
return F_18 ( V_10 >= 0 ) ? V_10 + V_11 : V_10 ;
}
void F_19 ( void )
{
unsigned long V_12 ;
F_5 ( & V_13 , V_12 ) ;
F_6 ( 0xff , V_19 + V_17 ) ;
F_6 ( 0xff , V_16 + V_17 ) ;
F_6 ( 0x11 , V_19 + V_22 ) ;
F_6 ( 0 , V_19 + V_17 ) ;
F_6 ( 1U << V_25 , V_19 + V_17 ) ;
F_6 ( V_30 , V_19 + V_17 ) ;
F_6 ( 0x11 , V_16 + V_22 ) ;
F_6 ( 8 , V_16 + V_17 ) ;
F_6 ( V_25 , V_16 + V_17 ) ;
F_6 ( V_31 , V_16 + V_17 ) ;
F_20 ( 100 ) ;
F_6 ( V_18 , V_19 + V_17 ) ;
F_6 ( V_15 , V_16 + V_17 ) ;
F_7 ( & V_13 , V_12 ) ;
}
static T_2 F_21 ( int V_32 , void * V_33 )
{
int V_10 ;
V_10 = F_14 () ;
if ( F_16 ( V_10 < 0 ) )
return V_34 ;
F_22 ( V_10 ) ;
return V_35 ;
}
void T_1 F_23 ( void )
{
int V_36 ;
V_19 = F_24 ( 0x16000020 , 4 ) ;
if ( ! V_19 )
return;
V_16 = F_24 ( 0x160000a0 , 4 ) ;
if ( ! V_16 ) {
F_25 ( V_19 ) ;
return;
}
F_26 ( & V_37 , & V_38 ) ;
F_26 ( & V_37 , & V_39 ) ;
F_19 () ;
for ( V_36 = V_11 ; V_36 < V_11 + 16 ; V_36 ++ )
F_27 ( V_36 , & V_40 ,
V_41 ) ;
F_28 ( V_11 + V_25 , & V_42 ) ;
}
static void F_29 ( struct V_7 * V_8 )
{
unsigned int V_9 = 1 << ( V_8 -> V_10 - V_43 ) ;
* ( volatile V_44 * ) V_45 &= ~ V_9 ;
}
void F_30 ( struct V_7 * V_8 )
{
unsigned int V_9 = 1 << ( V_8 -> V_10 - V_43 ) ;
* ( volatile V_44 * ) V_45 |= V_9 ;
}
static void F_31 ( void )
{
T_3 V_46 = F_32 () & F_33 () ;
V_44 V_9 ;
V_44 V_47 ;
int V_10 ;
if ( V_46 & V_48 )
F_22 ( V_49 + 7 ) ;
else if ( V_46 & V_50 ) {
F_34 ( V_51 ) ;
V_9 = * ( volatile V_44 * ) V_45 ^ 0x1f ;
V_47 = * ( volatile V_44 * ) V_52 ^ 0x14 ;
V_10 = F_35 ( V_47 & V_9 & 0x1f ) ;
if ( F_18 ( V_10 > 0 ) )
F_22 ( V_10 + V_43 - 1 ) ;
F_36 ( V_51 ) ;
}
}
void T_1 F_37 ( void )
{
int V_36 ;
* ( volatile V_44 * ) V_45 = 0x1f ;
F_23 () ;
F_38 () ;
for ( V_36 = V_43 ; V_36 <= V_53 ; V_36 ++ )
F_27 ( V_36 , & V_54 , V_41 ) ;
V_55 = F_31 ;
F_39 ( V_56 , V_51 ) ;
F_28 ( V_43 + 0 , & V_57 ) ;
F_28 ( V_43 + 1 , & V_58 ) ;
}
void T_1 F_40 ( void )
{
}
