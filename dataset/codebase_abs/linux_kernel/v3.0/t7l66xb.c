static int F_1 ( struct V_1 * V_2 )
{
struct V_1 * V_3 = F_2 ( V_2 -> V_3 . V_4 ) ;
struct V_5 * V_5 = F_3 ( V_3 ) ;
unsigned long V_6 ;
T_1 V_7 ;
F_4 ( V_5 -> V_8 ) ;
F_5 ( & V_5 -> V_9 , V_6 ) ;
V_7 = F_6 ( V_5 -> V_10 + V_11 ) ;
V_7 |= V_12 ;
F_7 ( V_7 , V_5 -> V_10 + V_11 ) ;
F_8 ( & V_5 -> V_9 , V_6 ) ;
F_9 ( V_5 -> V_10 + 0x200 , 0 ,
V_13 [ 0 ] . V_14 & 0xfffe ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 )
{
struct V_1 * V_3 = F_2 ( V_2 -> V_3 . V_4 ) ;
struct V_5 * V_5 = F_3 ( V_3 ) ;
unsigned long V_6 ;
T_1 V_7 ;
F_5 ( & V_5 -> V_9 , V_6 ) ;
V_7 = F_6 ( V_5 -> V_10 + V_11 ) ;
V_7 &= ~ V_12 ;
F_7 ( V_7 , V_5 -> V_10 + V_11 ) ;
F_8 ( & V_5 -> V_9 , V_6 ) ;
F_11 ( V_5 -> V_8 ) ;
return 0 ;
}
static void F_12 ( struct V_1 * V_2 , int V_15 )
{
struct V_1 * V_3 = F_2 ( V_2 -> V_3 . V_4 ) ;
struct V_5 * V_5 = F_3 ( V_3 ) ;
F_13 ( V_5 -> V_10 + 0x200 , 0 , V_15 ) ;
}
static void F_14 ( struct V_1 * V_2 , int V_15 )
{
struct V_1 * V_3 = F_2 ( V_2 -> V_3 . V_4 ) ;
struct V_5 * V_5 = F_3 ( V_3 ) ;
F_15 ( V_5 -> V_10 + 0x200 , 0 , V_15 ) ;
}
static void F_16 ( unsigned int V_16 , struct V_17 * V_18 )
{
struct V_5 * V_5 = F_17 ( V_16 ) ;
unsigned int V_19 ;
unsigned int V_20 , V_21 ;
V_21 = V_5 -> V_21 ;
while ( ( V_19 = F_6 ( V_5 -> V_10 + V_22 ) &
~ F_6 ( V_5 -> V_10 + V_23 ) ) )
for ( V_20 = 0 ; V_20 < V_24 ; V_20 ++ )
if ( V_19 & ( 1 << V_20 ) )
F_18 ( V_21 + V_20 ) ;
}
static void F_19 ( struct V_25 * V_26 )
{
struct V_5 * V_5 = F_20 ( V_26 ) ;
unsigned long V_6 ;
T_1 V_27 ;
F_5 ( & V_5 -> V_9 , V_6 ) ;
V_27 = F_6 ( V_5 -> V_10 + V_23 ) ;
V_27 |= 1 << ( V_26 -> V_16 - V_5 -> V_21 ) ;
F_7 ( V_27 , V_5 -> V_10 + V_23 ) ;
F_8 ( & V_5 -> V_9 , V_6 ) ;
}
static void F_21 ( struct V_25 * V_26 )
{
struct V_5 * V_5 = F_20 ( V_26 ) ;
unsigned long V_6 ;
T_1 V_27 ;
F_5 ( & V_5 -> V_9 , V_6 ) ;
V_27 = F_6 ( V_5 -> V_10 + V_23 ) ;
V_27 &= ~ ( 1 << ( V_26 -> V_16 - V_5 -> V_21 ) ) ;
F_7 ( V_27 , V_5 -> V_10 + V_23 ) ;
F_8 ( & V_5 -> V_9 , V_6 ) ;
}
static void F_22 ( struct V_1 * V_3 )
{
struct V_5 * V_5 = F_3 ( V_3 ) ;
unsigned int V_16 , V_21 ;
V_21 = V_5 -> V_21 ;
for ( V_16 = V_21 ; V_16 < V_21 + V_24 ; V_16 ++ ) {
F_23 ( V_16 , & V_28 , V_29 ) ;
F_24 ( V_16 , V_5 ) ;
#ifdef F_25
F_26 ( V_16 , V_30 | V_31 ) ;
#endif
}
F_27 ( V_5 -> V_16 , V_32 ) ;
F_28 ( V_5 -> V_16 , V_5 ) ;
F_29 ( V_5 -> V_16 , F_16 ) ;
}
static void F_30 ( struct V_1 * V_3 )
{
struct V_5 * V_5 = F_3 ( V_3 ) ;
unsigned int V_16 , V_21 ;
V_21 = V_5 -> V_21 ;
F_29 ( V_5 -> V_16 , NULL ) ;
F_28 ( V_5 -> V_16 , NULL ) ;
for ( V_16 = V_21 ; V_16 < V_21 + V_24 ; V_16 ++ ) {
#ifdef F_25
F_26 ( V_16 , 0 ) ;
#endif
F_31 ( V_16 , NULL ) ;
F_24 ( V_16 , NULL ) ;
}
}
static int F_32 ( struct V_1 * V_3 , T_2 V_15 )
{
struct V_5 * V_5 = F_3 ( V_3 ) ;
struct V_33 * V_34 = V_3 -> V_3 . V_35 ;
if ( V_34 && V_34 -> V_36 )
V_34 -> V_36 ( V_3 ) ;
F_11 ( V_5 -> V_37 ) ;
return 0 ;
}
static int F_33 ( struct V_1 * V_3 )
{
struct V_5 * V_5 = F_3 ( V_3 ) ;
struct V_33 * V_34 = V_3 -> V_3 . V_35 ;
F_4 ( V_5 -> V_37 ) ;
if ( V_34 && V_34 -> V_38 )
V_34 -> V_38 ( V_3 ) ;
F_9 ( V_5 -> V_10 + 0x200 , 0 ,
V_13 [ 0 ] . V_14 & 0xfffe ) ;
return 0 ;
}
static int F_34 ( struct V_1 * V_3 )
{
struct V_33 * V_34 = V_3 -> V_3 . V_35 ;
struct V_5 * V_5 ;
struct V_39 * V_40 , * V_41 ;
int V_42 ;
if ( V_34 == NULL )
return - V_43 ;
V_40 = F_35 ( V_3 , V_44 , 0 ) ;
if ( ! V_40 )
return - V_43 ;
V_5 = F_36 ( sizeof *V_5 , V_45 ) ;
if ( ! V_5 )
return - V_46 ;
F_37 ( & V_5 -> V_9 ) ;
F_38 ( V_3 , V_5 ) ;
V_42 = F_39 ( V_3 , 0 ) ;
if ( V_42 >= 0 )
V_5 -> V_16 = V_42 ;
else
goto V_47;
V_5 -> V_21 = V_34 -> V_21 ;
V_5 -> V_8 = F_40 ( & V_3 -> V_3 , L_1 ) ;
if ( F_41 ( V_5 -> V_8 ) ) {
V_42 = F_42 ( V_5 -> V_8 ) ;
goto V_48;
}
V_5 -> V_37 = F_40 ( & V_3 -> V_3 , L_2 ) ;
if ( F_41 ( V_5 -> V_37 ) ) {
V_42 = F_42 ( V_5 -> V_37 ) ;
goto V_49;
}
V_41 = & V_5 -> V_41 ;
V_41 -> V_50 = L_3 ;
V_41 -> V_14 = V_40 -> V_14 ;
V_41 -> V_51 = V_40 -> V_14 + 0xff ;
V_41 -> V_6 = V_44 ;
V_42 = F_43 ( V_40 , V_41 ) ;
if ( V_42 )
goto V_52;
V_5 -> V_10 = F_44 ( V_41 -> V_14 , F_45 ( V_41 ) ) ;
if ( ! V_5 -> V_10 ) {
V_42 = - V_46 ;
goto V_53;
}
F_4 ( V_5 -> V_37 ) ;
if ( V_34 && V_34 -> V_54 )
V_34 -> V_54 ( V_3 ) ;
F_7 ( 0xbf , V_5 -> V_10 + V_23 ) ;
F_46 ( V_55 L_4 ,
V_3 -> V_50 , F_6 ( V_5 -> V_10 + V_56 ) ,
( unsigned long ) V_40 -> V_14 , V_5 -> V_16 ) ;
F_22 ( V_3 ) ;
V_57 [ V_58 ] . V_35 = V_34 -> V_59 ;
V_57 [ V_58 ] . V_60 = sizeof( * V_34 -> V_59 ) ;
V_42 = F_47 ( & V_3 -> V_3 , V_3 -> V_61 ,
V_57 , F_48 ( V_57 ) ,
V_40 , V_5 -> V_21 ) ;
if ( ! V_42 )
return 0 ;
F_30 ( V_3 ) ;
F_49 ( V_5 -> V_10 ) ;
V_53:
F_50 ( & V_5 -> V_41 ) ;
V_52:
F_51 ( V_5 -> V_37 ) ;
V_49:
F_51 ( V_5 -> V_8 ) ;
V_48:
V_47:
F_52 ( V_5 ) ;
return V_42 ;
}
static int F_53 ( struct V_1 * V_3 )
{
struct V_33 * V_34 = V_3 -> V_3 . V_35 ;
struct V_5 * V_5 = F_3 ( V_3 ) ;
int V_42 ;
V_42 = V_34 -> V_62 ( V_3 ) ;
F_11 ( V_5 -> V_37 ) ;
F_51 ( V_5 -> V_37 ) ;
F_11 ( V_5 -> V_8 ) ;
F_51 ( V_5 -> V_8 ) ;
F_30 ( V_3 ) ;
F_49 ( V_5 -> V_10 ) ;
F_50 ( & V_5 -> V_41 ) ;
F_54 ( & V_3 -> V_3 ) ;
F_38 ( V_3 , NULL ) ;
F_52 ( V_5 ) ;
return V_42 ;
}
static int T_3 F_55 ( void )
{
int V_63 = 0 ;
V_63 = F_56 ( & V_64 ) ;
return V_63 ;
}
static void T_4 F_57 ( void )
{
F_58 ( & V_64 ) ;
}
