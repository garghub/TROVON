void F_1 ( int (* F_2)( void ) )
{
V_1 = F_2 ;
}
static void F_3 ( struct V_2 * V_3 )
{
unsigned int V_4 , V_5 = V_3 -> V_5 - V_6 ;
unsigned long V_7 ;
V_4 = 1 << V_5 ;
F_4 ( & V_8 , V_7 ) ;
V_9 |= V_4 ;
if ( V_5 & 8 )
F_5 ( V_10 , V_11 ) ;
else
F_5 ( V_12 , V_13 ) ;
F_6 ( & V_8 , V_7 ) ;
}
static void F_7 ( struct V_2 * V_3 )
{
unsigned int V_4 , V_5 = V_3 -> V_5 - V_6 ;
unsigned long V_7 ;
V_4 = ~ ( 1 << V_5 ) ;
F_4 ( & V_8 , V_7 ) ;
V_9 &= V_4 ;
if ( V_5 & 8 )
F_5 ( V_10 , V_11 ) ;
else
F_5 ( V_12 , V_13 ) ;
F_6 ( & V_8 , V_7 ) ;
}
void F_8 ( unsigned int V_5 )
{
F_9 ( V_5 ) ;
F_10 ( V_5 , & V_14 , V_15 ) ;
F_11 ( V_5 ) ;
}
static inline int F_12 ( unsigned int V_5 )
{
int V_16 ;
int V_17 = 1 << V_5 ;
if ( V_5 < 8 ) {
F_5 ( 0x0B , V_18 ) ;
V_16 = F_13 ( V_18 ) & V_17 ;
F_5 ( 0x0A , V_18 ) ;
return V_16 ;
}
F_5 ( 0x0B , V_19 ) ;
V_16 = F_13 ( V_19 ) & ( V_17 >> 8 ) ;
F_5 ( 0x0A , V_19 ) ;
return V_16 ;
}
static void F_14 ( struct V_2 * V_3 )
{
unsigned int V_17 , V_5 = V_3 -> V_5 - V_6 ;
unsigned long V_7 ;
V_17 = 1 << V_5 ;
F_4 ( & V_8 , V_7 ) ;
if ( V_9 & V_17 )
goto V_20;
V_9 |= V_17 ;
V_21:
if ( V_5 & 8 ) {
F_13 ( V_11 ) ;
F_5 ( V_10 , V_11 ) ;
F_5 ( 0x60 + ( V_5 & 7 ) , V_19 ) ;
F_5 ( 0x60 + V_22 , V_18 ) ;
} else {
F_13 ( V_13 ) ;
F_5 ( V_12 , V_13 ) ;
F_5 ( 0x60 + V_5 , V_18 ) ;
}
F_6 ( & V_8 , V_7 ) ;
return;
V_20:
if ( F_12 ( V_5 ) )
goto V_21;
{
static int V_23 ;
if ( ! ( V_23 & V_17 ) ) {
F_15 ( V_24 L_1 , V_5 ) ;
V_23 |= V_17 ;
}
F_16 ( & V_25 ) ;
goto V_21;
}
}
static void F_17 ( void )
{
if ( V_26 >= 0 )
F_18 ( V_26 ) ;
}
static void F_19 ( void )
{
if ( V_26 >= 0 ) {
F_5 ( 0xff , V_13 ) ;
F_5 ( 0xff , V_11 ) ;
}
}
static int T_1 F_20 ( void )
{
F_21 ( & V_27 ) ;
return 0 ;
}
static void F_18 ( int V_28 )
{
unsigned long V_7 ;
V_26 = V_28 ;
F_4 ( & V_8 , V_7 ) ;
F_5 ( 0xff , V_13 ) ;
F_5 ( 0xff , V_11 ) ;
F_22 ( 0x11 , V_18 ) ;
F_22 ( V_6 + 0 , V_13 ) ;
F_22 ( 1U << V_22 , V_13 ) ;
if ( V_28 )
F_22 ( V_29 | V_30 , V_13 ) ;
else
F_22 ( V_29 , V_13 ) ;
F_22 ( 0x11 , V_19 ) ;
F_22 ( V_6 + 8 , V_11 ) ;
F_22 ( V_22 , V_11 ) ;
F_22 ( V_31 , V_11 ) ;
if ( V_28 )
V_14 . V_32 = F_3 ;
else
V_14 . V_32 = F_14 ;
F_23 ( 100 ) ;
F_5 ( V_12 , V_13 ) ;
F_5 ( V_10 , V_11 ) ;
F_6 ( & V_8 , V_7 ) ;
}
static int F_24 ( struct V_33 * V_3 , unsigned int V_34 ,
T_2 V_35 )
{
F_10 ( V_34 , & V_14 , V_15 ) ;
F_25 ( V_34 ) ;
return 0 ;
}
struct V_33 * T_1 F_26 ( struct V_36 * V_37 )
{
struct V_33 * V_38 ;
F_27 ( & V_39 , & V_40 ) ;
F_27 ( & V_39 , & V_41 ) ;
F_18 ( 0 ) ;
V_38 = F_28 ( V_37 , 16 , V_6 , 0 ,
& V_42 , NULL ) ;
if ( ! V_38 )
F_29 ( L_2 ) ;
F_30 ( V_6 + V_22 , & V_43 ) ;
return V_38 ;
}
void T_1 F_31 ( void )
{
F_26 ( NULL ) ;
}
static void F_32 ( struct V_44 * V_45 )
{
struct V_33 * V_38 = F_33 ( V_45 ) ;
int V_46 = V_1 () ;
unsigned int V_5 ;
if ( V_46 < 0 )
return;
V_5 = F_34 ( V_38 , V_46 ) ;
F_35 ( V_5 ) ;
}
int T_1 F_36 ( struct V_36 * V_37 , struct V_36 * V_47 )
{
struct V_33 * V_38 ;
unsigned int V_48 ;
V_38 = F_26 ( V_37 ) ;
V_48 = F_37 ( V_37 , 0 ) ;
if ( ! V_48 ) {
F_38 ( L_3 ) ;
F_39 ( V_38 ) ;
return - V_49 ;
}
F_40 ( V_48 , F_32 ,
V_38 ) ;
return 0 ;
}
