static int F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
T_1 V_4 ;
T_2 T_3 * V_5 ;
T_2 V_6 , V_7 ;
int V_8 ;
T_4 V_9 ;
V_3 = F_2 ( V_2 , 3 ) ;
V_4 = F_3 ( V_2 , 3 ) ;
if ( V_4 < 0xffff ) {
F_4 ( V_10 L_1 ) ;
return - V_11 ;
}
if ( ! F_5 ( V_3 , V_4 , L_2 ) ) {
F_4 ( V_10 L_3 ) ;
return - V_12 ;
}
V_5 = F_6 ( V_3 , V_4 ) ;
if ( ! V_5 ) {
F_4 ( V_10 L_4 ) ;
F_7 ( V_3 , V_4 ) ;
return - V_11 ;
}
F_8 ( V_2 , V_13 , & V_6 ) ;
if ( V_6 ) {
F_8 ( V_2 , V_14 , & V_7 ) ;
if ( V_7 && V_7 < V_6 )
F_9 ( V_2 , V_13 , V_7 ) ;
}
V_8 = 20 ;
V_9 = 0 ;
while ( ( V_9 != 0xFACE ) && V_8 ) {
F_10 ( 0xface , V_5 + V_15 ) ;
F_11 ( 100 ) ;
V_9 = F_12 ( V_5 + V_15 ) & 0x0000ffff ;
V_8 -- ;
}
F_13 ( V_5 ) ;
F_7 ( V_3 , V_4 ) ;
if ( V_9 != 0xFACE ) {
F_14 ( & V_2 -> V_2 , L_5 , V_9 ) ;
return - V_11 ;
}
V_3 = F_2 ( V_2 , 0 ) ;
V_4 = F_3 ( V_2 , 0 ) ;
if ( ! F_5 ( V_3 , V_4 , L_6 ) ) {
F_4 ( V_10 L_7 ) ;
return - V_12 ;
}
V_5 = F_6 ( V_3 , V_4 ) ;
if ( ! V_5 ) {
F_4 ( V_10 L_8 ) ;
F_7 ( V_3 , V_4 ) ;
return - V_11 ;
}
#define F_15 0x68
V_9 = F_12 ( V_5 + F_15 ) ;
V_9 |= 0x900 ;
F_10 ( V_9 , V_5 + F_15 ) ;
F_13 ( V_5 ) ;
F_7 ( V_3 , V_4 ) ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 ,
const struct V_16 * V_17 )
{
unsigned int V_18 = 0 ;
int V_19 ;
if ( ! V_2 -> V_20 )
return - V_21 ;
if ( F_17 ( V_2 ) < 0 )
return - V_21 ;
V_19 = F_1 ( V_2 ) ;
if ( V_19 < 0 )
goto error;
F_18 ( V_2 ) ;
V_2 -> V_2 . V_22 = NULL ;
V_19 = F_19 ( & V_2 -> V_23 [ 3 ] , V_2 -> V_20 , 0 , & V_2 -> V_2 ,
V_18 ) ;
if ( V_19 < 0 )
goto error;
return 0 ;
error:
F_20 ( V_2 ) ;
return V_19 ;
}
static void F_21 ( struct V_1 * V_2 )
{
F_22 ( & V_2 -> V_2 ) ;
F_20 ( V_2 ) ;
}
static void F_23 ( struct V_1 * V_2 )
{
F_4 ( V_10 L_9 ) ;
}
static int F_24 ( struct V_24 * V_25 )
{
unsigned long V_26 ;
unsigned int V_18 = 0 ;
struct V_23 * V_27 ;
struct V_23 * V_28 ;
int V_19 ;
V_27 = F_25 ( V_25 , V_29 , 0 ) ;
V_28 = F_25 ( V_25 , V_30 , 0 ) ;
if ( ! V_28 ) {
F_26 ( L_10 ) ;
return - V_21 ;
}
V_26 = V_28 -> V_31 & V_32 ;
if ( F_27 ( V_33 ) && V_25 -> V_2 . V_34 ) {
struct V_35 * V_36 = V_25 -> V_2 . V_34 ;
T_4 V_37 = 0 ;
if ( F_28 ( V_36 , L_11 ) )
V_18 |= V_38 ;
F_29 ( V_36 , L_12 , & V_37 ) ;
if ( V_37 == 16 )
V_18 |= V_39 ;
if ( F_30 ( V_36 , L_13 ) )
V_18 |= V_40 ;
if ( F_30 ( V_36 , L_14 ) )
V_18 |= V_41 ;
if ( F_30 ( V_36 , L_15 ) )
V_18 |= V_42 ;
if ( F_30 ( V_36 , L_16 ) )
V_18 |= V_43 ;
} else if ( F_31 ( & V_25 -> V_2 ) ) {
struct V_44 * V_45 =
F_31 ( & V_25 -> V_2 ) ;
if ( V_45 -> V_46 )
V_18 |= V_38 ;
if ( V_45 -> V_47 )
V_18 |= V_39 ;
if ( V_45 -> V_48 )
V_18 |= V_40 ;
if ( V_45 -> V_49 )
V_18 |= V_41 ;
if ( V_45 -> V_50 )
V_18 |= V_42 ;
if ( V_45 -> V_51 )
V_18 |= V_43 ;
}
V_19 = F_19 ( V_27 , V_28 -> V_52 , V_26 , & V_25 -> V_2 ,
V_18 ) ;
if ( V_19 < 0 )
return V_19 ;
F_32 ( L_17 ) ;
return 0 ;
}
static int F_33 ( struct V_24 * V_25 )
{
F_22 ( & V_25 -> V_2 ) ;
return 0 ;
}
static int T_5 F_34 ( void )
{
int V_19 , V_53 = - V_21 ;
F_35 () ;
V_19 = F_36 ( & V_54 ) ;
if ( ! V_19 )
V_53 = 0 ;
#ifdef F_37
V_19 = F_38 ( & V_55 ) ;
if ( ! V_19 )
V_53 = 0 ;
#endif
if ( V_53 )
F_39 () ;
return V_53 ;
}
static void T_6 F_40 ( void )
{
F_41 ( & V_54 ) ;
#ifdef F_37
F_42 ( & V_55 ) ;
#endif
F_39 () ;
}
