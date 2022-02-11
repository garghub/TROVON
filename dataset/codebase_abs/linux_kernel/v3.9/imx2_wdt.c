static inline void F_1 ( void )
{
T_1 V_1 = F_2 ( V_2 . V_3 + V_4 ) ;
V_1 &= ~ V_5 ;
V_1 &= ~ V_6 ;
V_1 &= ~ V_7 ;
V_1 |= F_3 ( V_2 . V_8 ) ;
F_4 ( V_1 , V_2 . V_3 + V_4 ) ;
V_1 |= V_7 ;
F_4 ( V_1 , V_2 . V_3 + V_4 ) ;
}
static inline void F_5 ( void )
{
F_4 ( V_9 , V_2 . V_3 + V_10 ) ;
F_4 ( V_11 , V_2 . V_3 + V_10 ) ;
}
static void F_6 ( unsigned long V_12 )
{
F_5 () ;
F_7 ( & V_2 . V_13 , V_14 + V_2 . V_8 * V_15 / 2 ) ;
}
static void F_8 ( void )
{
if ( ! F_9 ( V_16 , & V_2 . V_17 ) ) {
F_10 ( V_2 . V_18 ) ;
F_1 () ;
} else
F_11 ( & V_2 . V_13 ) ;
F_5 () ;
}
static void F_12 ( void )
{
F_6 ( 0 ) ;
}
static void F_13 ( int V_19 )
{
T_1 V_1 = F_2 ( V_2 . V_3 + V_4 ) ;
V_1 &= ~ V_5 ;
V_1 |= F_3 ( V_19 ) ;
F_4 ( V_1 , V_2 . V_3 + V_4 ) ;
}
static int F_14 ( struct V_20 * V_20 , struct V_21 * V_21 )
{
if ( F_9 ( V_22 , & V_2 . V_17 ) )
return - V_23 ;
F_8 () ;
return F_15 ( V_20 , V_21 ) ;
}
static int F_16 ( struct V_20 * V_20 , struct V_21 * V_21 )
{
if ( F_17 ( V_24 , & V_2 . V_17 ) && ! V_25 )
F_12 () ;
else {
F_18 ( V_26 . V_27 ,
L_1 ) ;
F_5 () ;
}
F_19 ( V_24 , & V_2 . V_17 ) ;
F_19 ( V_22 , & V_2 . V_17 ) ;
return 0 ;
}
static long F_20 ( struct V_21 * V_21 , unsigned int V_28 ,
unsigned long V_12 )
{
void T_2 * V_29 = ( void T_2 * ) V_12 ;
int T_2 * V_30 = V_29 ;
int V_31 ;
T_1 V_1 ;
switch ( V_28 ) {
case V_32 :
return F_21 ( V_29 , & V_33 ,
sizeof( struct V_34 ) ) ? - V_35 : 0 ;
case V_36 :
return F_22 ( 0 , V_30 ) ;
case V_37 :
V_1 = F_2 ( V_2 . V_3 + V_38 ) ;
V_31 = V_1 & V_39 ? V_40 : 0 ;
return F_22 ( V_31 , V_30 ) ;
case V_41 :
F_5 () ;
return 0 ;
case V_42 :
if ( F_23 ( V_31 , V_30 ) )
return - V_35 ;
if ( ( V_31 < 1 ) || ( V_31 > V_43 ) )
return - V_44 ;
F_13 ( V_31 ) ;
V_2 . V_8 = V_31 ;
F_5 () ;
case V_45 :
return F_22 ( V_2 . V_8 , V_30 ) ;
default:
return - V_46 ;
}
}
static T_3 F_24 ( struct V_21 * V_21 , const char T_2 * V_47 ,
T_4 V_48 , T_5 * V_49 )
{
T_4 V_50 ;
char V_51 ;
if ( V_48 == 0 )
return 0 ;
F_19 ( V_24 , & V_2 . V_17 ) ;
for ( V_50 = 0 ; V_50 != V_48 ; V_50 ++ ) {
if ( F_23 ( V_51 , V_47 + V_50 ) )
return - V_35 ;
if ( V_51 == 'V' )
F_25 ( V_24 , & V_2 . V_17 ) ;
}
F_5 () ;
return V_48 ;
}
static int T_6 F_26 ( struct V_52 * V_53 )
{
int V_54 ;
struct V_55 * V_56 ;
V_56 = F_27 ( V_53 , V_57 , 0 ) ;
if ( ! V_56 ) {
F_28 ( & V_53 -> V_58 , L_2 ) ;
return - V_59 ;
}
V_2 . V_3 = F_29 ( & V_53 -> V_58 , V_56 ) ;
if ( F_30 ( V_2 . V_3 ) )
return F_31 ( V_2 . V_3 ) ;
V_2 . V_18 = F_32 ( & V_53 -> V_58 , NULL ) ;
if ( F_30 ( V_2 . V_18 ) ) {
F_28 ( & V_53 -> V_58 , L_3 ) ;
return F_31 ( V_2 . V_18 ) ;
}
V_2 . V_8 = F_33 ( unsigned , V_8 , 1 , V_43 ) ;
if ( V_2 . V_8 != V_8 )
F_34 ( & V_53 -> V_58 , L_4
L_5 , V_8 , V_2 . V_8 ) ;
F_35 ( & V_2 . V_13 , F_6 , 0 ) ;
V_26 . V_27 = & V_53 -> V_58 ;
V_54 = F_36 ( & V_26 ) ;
if ( V_54 )
goto V_60;
F_37 ( & V_53 -> V_58 ,
L_6 ,
V_2 . V_8 , V_25 ) ;
return 0 ;
V_60:
V_26 . V_27 = NULL ;
F_38 ( V_2 . V_18 ) ;
return V_54 ;
}
static int T_7 F_39 ( struct V_52 * V_53 )
{
F_40 ( & V_26 ) ;
if ( F_17 ( V_16 , & V_2 . V_17 ) ) {
F_11 ( & V_2 . V_13 ) ;
F_18 ( V_26 . V_27 ,
L_7 ) ;
} else
F_38 ( V_2 . V_18 ) ;
V_26 . V_27 = NULL ;
return 0 ;
}
static void F_41 ( struct V_52 * V_53 )
{
if ( F_17 ( V_16 , & V_2 . V_17 ) ) {
F_11 ( & V_2 . V_13 ) ;
F_13 ( V_43 ) ;
F_5 () ;
F_18 ( V_26 . V_27 ,
L_8 ) ;
}
}
