static int F_1 ( struct V_1 * V_2 )
{
F_2 ( & V_3 ) ;
F_3 ( V_4 , V_5 + V_6 ) ;
F_4 ( & V_3 ) ;
return 0 ;
}
static void F_5 ( void )
{
unsigned long V_7 ;
V_7 = F_6 ( V_5 + V_8 ) ;
V_7 &= ~ ( V_9 | V_10 ) ;
F_3 ( V_7 , V_5 + V_8 ) ;
}
static int F_7 ( struct V_1 * V_2 )
{
F_2 ( & V_3 ) ;
F_5 () ;
F_4 ( & V_3 ) ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 )
{
unsigned long V_7 ;
F_2 ( & V_3 ) ;
F_5 () ;
V_7 = F_6 ( V_5 + V_8 ) ;
V_7 |= V_9 | V_11 ;
if ( V_12 ) {
V_7 |= V_13 ;
V_7 &= ~ V_10 ;
} else {
V_7 &= ~ V_13 ;
V_7 |= V_10 ;
}
F_9 ( L_1 ,
V_14 , V_4 , V_7 ) ;
F_3 ( V_4 , V_5 + V_15 ) ;
F_3 ( V_4 , V_5 + V_6 ) ;
F_3 ( V_7 , V_5 + V_8 ) ;
F_4 ( & V_3 ) ;
return 0 ;
}
static inline int F_10 ( void )
{
return F_6 ( V_5 + V_8 ) & V_9 ;
}
static int F_11 ( struct V_1 * V_2 , unsigned V_16 )
{
unsigned long V_17 = F_12 ( V_18 ) ;
unsigned int V_19 ;
unsigned int V_20 = 1 ;
unsigned long V_7 ;
if ( V_16 < 1 )
return - V_21 ;
V_17 /= 128 ;
V_19 = V_16 * V_17 ;
F_9 ( L_2 ,
V_14 , V_19 , V_16 , V_17 ) ;
if ( V_19 >= 0x10000 ) {
for ( V_20 = 1 ; V_20 <= 0x100 ; V_20 ++ ) {
if ( ( V_19 / V_20 ) < 0x10000 )
break;
}
if ( ( V_19 / V_20 ) >= 0x10000 ) {
F_13 ( V_22 , L_3 , V_16 ) ;
return - V_21 ;
}
}
F_9 ( L_4 ,
V_14 , V_16 , V_20 , V_19 , V_19 / V_20 ) ;
V_19 /= V_20 ;
V_4 = V_19 ;
V_7 = F_6 ( V_5 + V_8 ) ;
V_7 &= ~ V_23 ;
V_7 |= F_14 ( V_20 - 1 ) ;
F_3 ( V_19 , V_5 + V_15 ) ;
F_3 ( V_7 , V_5 + V_8 ) ;
V_2 -> V_16 = ( V_19 * V_20 ) / V_17 ;
return 0 ;
}
static T_1 F_15 ( int V_24 , void * V_25 )
{
F_16 ( V_22 , L_5 ) ;
F_1 ( & V_26 ) ;
return V_27 ;
}
static int F_17 ( struct V_28 * V_29 ,
unsigned long V_30 , void * V_31 )
{
int V_32 ;
if ( ! F_10 () )
goto V_33;
if ( V_30 == V_34 ) {
F_1 ( & V_26 ) ;
} else if ( V_30 == V_35 ) {
F_7 ( & V_26 ) ;
V_32 = F_11 ( & V_26 , V_26 . V_16 ) ;
if ( V_32 >= 0 )
F_8 ( & V_26 ) ;
else
goto V_36;
}
V_33:
return 0 ;
V_36:
F_13 ( V_22 , L_6 ,
V_26 . V_16 ) ;
return V_32 ;
}
static inline int F_18 ( void )
{
return F_19 ( & V_37 ,
V_38 ) ;
}
static inline void F_20 ( void )
{
F_21 ( & V_37 ,
V_38 ) ;
}
static inline int F_18 ( void )
{
return 0 ;
}
static inline void F_20 ( void )
{
}
static int F_22 ( struct V_39 * V_40 )
{
struct V_41 * V_42 ;
unsigned int V_7 ;
int V_43 = 0 ;
int V_32 ;
F_9 ( L_7 , V_14 , V_40 ) ;
V_42 = & V_40 -> V_42 ;
V_22 = & V_40 -> V_42 ;
V_44 = F_23 ( V_40 , V_45 , 0 ) ;
if ( V_44 == NULL ) {
F_13 ( V_42 , L_8 ) ;
return - V_46 ;
}
V_47 = F_23 ( V_40 , V_48 , 0 ) ;
if ( V_47 == NULL ) {
F_13 ( V_42 , L_9 ) ;
V_32 = - V_46 ;
goto V_36;
}
V_5 = F_24 ( V_42 , V_44 ) ;
if ( F_25 ( V_5 ) ) {
V_32 = F_26 ( V_5 ) ;
goto V_36;
}
F_9 ( L_10 , V_5 ) ;
V_18 = F_27 ( V_42 , L_11 ) ;
if ( F_25 ( V_18 ) ) {
F_13 ( V_42 , L_12 ) ;
V_32 = F_26 ( V_18 ) ;
goto V_36;
}
F_28 ( V_18 ) ;
V_32 = F_18 () ;
if ( V_32 < 0 ) {
F_13 ( V_42 , L_13 ) ;
goto V_49;
}
F_29 ( & V_26 , V_50 , & V_40 -> V_42 ) ;
if ( F_11 ( & V_26 , V_26 . V_16 ) ) {
V_43 = F_11 ( & V_26 ,
V_51 ) ;
if ( V_43 == 0 )
F_16 ( V_42 ,
L_14 ,
V_51 ) ;
else
F_16 ( V_42 , L_15
L_16 ) ;
}
V_32 = F_30 ( V_42 , V_47 -> V_52 , F_15 , 0 ,
V_40 -> V_53 , V_40 ) ;
if ( V_32 != 0 ) {
F_13 ( V_42 , L_17 , V_32 ) ;
goto V_54;
}
F_31 ( & V_26 , V_55 ) ;
V_32 = F_32 ( & V_26 ) ;
if ( V_32 ) {
F_13 ( V_42 , L_18 , V_32 ) ;
goto V_54;
}
if ( V_56 && V_43 == 0 ) {
F_16 ( V_42 , L_19 ) ;
F_8 ( & V_26 ) ;
} else if ( ! V_56 ) {
F_7 ( & V_26 ) ;
}
V_7 = F_6 ( V_5 + V_8 ) ;
F_16 ( V_42 , L_20 ,
( V_7 & V_9 ) ? L_21 : L_22 ,
( V_7 & V_10 ) ? L_23 : L_24 ,
( V_7 & V_13 ) ? L_23 : L_24 ) ;
return 0 ;
V_54:
F_20 () ;
V_49:
F_33 ( V_18 ) ;
V_18 = NULL ;
V_36:
V_47 = NULL ;
V_44 = NULL ;
return V_32 ;
}
static int F_34 ( struct V_39 * V_42 )
{
F_35 ( & V_26 ) ;
F_20 () ;
F_33 ( V_18 ) ;
V_18 = NULL ;
V_47 = NULL ;
V_44 = NULL ;
return 0 ;
}
static void F_36 ( struct V_39 * V_42 )
{
F_7 ( & V_26 ) ;
}
static int F_37 ( struct V_41 * V_42 )
{
V_57 = F_6 ( V_5 + V_8 ) ;
V_58 = F_6 ( V_5 + V_15 ) ;
F_7 ( & V_26 ) ;
return 0 ;
}
static int F_38 ( struct V_41 * V_42 )
{
F_3 ( V_58 , V_5 + V_15 ) ;
F_3 ( V_58 , V_5 + V_6 ) ;
F_3 ( V_57 , V_5 + V_8 ) ;
F_16 ( V_42 , L_25 ,
( V_57 & V_9 ) ? L_23 : L_24 ) ;
return 0 ;
}
