static void F_1 ( struct V_1 * V_2 )
{
unsigned int V_3 , V_4 = V_2 -> V_4 - V_5 ;
unsigned long V_6 ;
V_3 = 1 << V_4 ;
F_2 ( & V_7 , V_6 ) ;
V_8 |= V_3 ;
if ( V_4 & 8 )
F_3 ( V_9 , V_10 ) ;
else
F_3 ( V_11 , V_12 ) ;
F_4 ( & V_7 , V_6 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
unsigned int V_3 , V_4 = V_2 -> V_4 - V_5 ;
unsigned long V_6 ;
V_3 = ~ ( 1 << V_4 ) ;
F_2 ( & V_7 , V_6 ) ;
V_8 &= V_3 ;
if ( V_4 & 8 )
F_3 ( V_9 , V_10 ) ;
else
F_3 ( V_11 , V_12 ) ;
F_4 ( & V_7 , V_6 ) ;
}
int F_6 ( unsigned int V_4 )
{
unsigned int V_3 ;
unsigned long V_6 ;
int V_13 ;
V_4 -= V_5 ;
V_3 = 1 << V_4 ;
F_2 ( & V_7 , V_6 ) ;
if ( V_4 < 8 )
V_13 = F_7 ( V_14 ) & V_3 ;
else
V_13 = F_7 ( V_15 ) & ( V_3 >> 8 ) ;
F_4 ( & V_7 , V_6 ) ;
return V_13 ;
}
void F_8 ( unsigned int V_4 )
{
F_9 ( V_4 ) ;
F_10 ( V_4 , & V_16 , V_17 ) ;
F_11 ( V_4 ) ;
}
static inline int F_12 ( unsigned int V_4 )
{
int V_18 ;
int V_19 = 1 << V_4 ;
if ( V_4 < 8 ) {
F_3 ( 0x0B , V_14 ) ;
V_18 = F_7 ( V_14 ) & V_19 ;
F_3 ( 0x0A , V_14 ) ;
return V_18 ;
}
F_3 ( 0x0B , V_15 ) ;
V_18 = F_7 ( V_15 ) & ( V_19 >> 8 ) ;
F_3 ( 0x0A , V_15 ) ;
return V_18 ;
}
static void F_13 ( struct V_1 * V_2 )
{
unsigned int V_19 , V_4 = V_2 -> V_4 - V_5 ;
unsigned long V_6 ;
V_19 = 1 << V_4 ;
F_2 ( & V_7 , V_6 ) ;
if ( V_8 & V_19 )
goto V_20;
V_8 |= V_19 ;
V_21:
if ( V_4 & 8 ) {
F_7 ( V_10 ) ;
F_3 ( V_9 , V_10 ) ;
F_3 ( 0x60 + ( V_4 & 7 ) , V_15 ) ;
F_3 ( 0x60 + V_22 , V_14 ) ;
} else {
F_7 ( V_12 ) ;
F_3 ( V_11 , V_12 ) ;
F_3 ( 0x60 + V_4 , V_14 ) ;
}
F_4 ( & V_7 , V_6 ) ;
return;
V_20:
if ( F_12 ( V_4 ) )
goto V_21;
{
static int V_23 ;
if ( ! ( V_23 & V_19 ) ) {
F_14 ( V_24 L_1 , V_4 ) ;
V_23 |= V_19 ;
}
F_15 ( & V_25 ) ;
goto V_21;
}
}
static void F_16 ( void )
{
if ( V_26 >= 0 )
F_17 ( V_26 ) ;
}
static void F_18 ( void )
{
if ( V_26 >= 0 ) {
F_3 ( 0xff , V_12 ) ;
F_3 ( 0xff , V_10 ) ;
}
}
static int T_1 F_19 ( void )
{
F_20 ( & V_27 ) ;
return 0 ;
}
static void F_17 ( int V_28 )
{
unsigned long V_6 ;
V_26 = V_28 ;
F_2 ( & V_7 , V_6 ) ;
F_3 ( 0xff , V_12 ) ;
F_3 ( 0xff , V_10 ) ;
F_21 ( 0x11 , V_14 ) ;
F_21 ( V_5 + 0 , V_12 ) ;
F_21 ( 1U << V_22 , V_12 ) ;
if ( V_28 )
F_21 ( V_29 | V_30 , V_12 ) ;
else
F_21 ( V_29 , V_12 ) ;
F_21 ( 0x11 , V_15 ) ;
F_21 ( V_5 + 8 , V_10 ) ;
F_21 ( V_22 , V_10 ) ;
F_21 ( V_31 , V_10 ) ;
if ( V_28 )
V_16 . V_32 = F_1 ;
else
V_16 . V_32 = F_13 ;
F_22 ( 100 ) ;
F_3 ( V_11 , V_12 ) ;
F_3 ( V_9 , V_10 ) ;
F_4 ( & V_7 , V_6 ) ;
}
static int F_23 ( struct V_33 * V_2 , unsigned int V_34 ,
T_2 V_35 )
{
F_10 ( V_34 , & V_16 , V_17 ) ;
F_24 ( V_34 ) ;
return 0 ;
}
struct V_33 * T_1 F_25 ( struct V_36 * V_37 )
{
struct V_33 * V_38 ;
F_26 ( & V_39 , & V_40 ) ;
F_26 ( & V_39 , & V_41 ) ;
F_17 ( 0 ) ;
V_38 = F_27 ( V_37 , 16 , V_5 , 0 ,
& V_42 , NULL ) ;
if ( ! V_38 )
F_28 ( L_2 ) ;
F_29 ( V_5 + V_22 , & V_43 ) ;
return V_38 ;
}
void T_1 F_30 ( void )
{
F_25 ( NULL ) ;
}
static void F_31 ( struct V_44 * V_45 )
{
struct V_33 * V_38 = F_32 ( V_45 ) ;
int V_46 = F_33 () ;
unsigned int V_4 ;
if ( V_46 < 0 )
return;
V_4 = F_34 ( V_38 , V_46 ) ;
F_35 ( V_4 ) ;
}
int T_1 F_36 ( struct V_36 * V_37 , struct V_36 * V_47 )
{
struct V_33 * V_38 ;
unsigned int V_48 ;
V_48 = F_37 ( V_37 , 0 ) ;
if ( ! V_48 ) {
F_38 ( L_3 ) ;
return - V_49 ;
}
V_38 = F_25 ( V_37 ) ;
F_39 ( V_48 , V_38 ) ;
F_40 ( V_48 , F_31 ) ;
return 0 ;
}
