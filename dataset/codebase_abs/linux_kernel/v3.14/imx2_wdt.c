static inline void F_1 ( void )
{
T_1 V_1 = F_2 ( V_2 . V_3 + V_4 ) ;
V_1 |= V_5 ;
V_1 &= ~ V_6 ;
V_1 &= ~ V_7 ;
V_1 &= ~ V_8 ;
V_1 |= F_3 ( V_2 . V_9 ) ;
F_4 ( V_1 , V_2 . V_3 + V_4 ) ;
V_1 |= V_8 ;
F_4 ( V_1 , V_2 . V_3 + V_4 ) ;
}
static inline void F_5 ( void )
{
F_4 ( V_10 , V_2 . V_3 + V_11 ) ;
F_4 ( V_12 , V_2 . V_3 + V_11 ) ;
}
static void F_6 ( unsigned long V_13 )
{
F_5 () ;
F_7 ( & V_2 . V_14 , V_15 + V_2 . V_9 * V_16 / 2 ) ;
}
static void F_8 ( void )
{
if ( ! F_9 ( V_17 , & V_2 . V_18 ) ) {
F_10 ( V_2 . V_19 ) ;
F_1 () ;
} else
F_11 ( & V_2 . V_14 ) ;
F_5 () ;
}
static void F_12 ( void )
{
F_6 ( 0 ) ;
}
static void F_13 ( int V_20 )
{
T_1 V_1 = F_2 ( V_2 . V_3 + V_4 ) ;
V_1 &= ~ V_6 ;
V_1 |= F_3 ( V_20 ) ;
F_4 ( V_1 , V_2 . V_3 + V_4 ) ;
}
static int F_14 ( struct V_21 * V_21 , struct V_22 * V_22 )
{
if ( F_9 ( V_23 , & V_2 . V_18 ) )
return - V_24 ;
F_8 () ;
return F_15 ( V_21 , V_22 ) ;
}
static int F_16 ( struct V_21 * V_21 , struct V_22 * V_22 )
{
if ( F_17 ( V_25 , & V_2 . V_18 ) && ! V_26 )
F_12 () ;
else {
F_18 ( V_27 . V_28 ,
L_1 ) ;
F_5 () ;
}
F_19 ( V_25 , & V_2 . V_18 ) ;
F_19 ( V_23 , & V_2 . V_18 ) ;
return 0 ;
}
static long F_20 ( struct V_22 * V_22 , unsigned int V_29 ,
unsigned long V_13 )
{
void T_2 * V_30 = ( void T_2 * ) V_13 ;
int T_2 * V_31 = V_30 ;
int V_32 ;
T_1 V_1 ;
switch ( V_29 ) {
case V_33 :
return F_21 ( V_30 , & V_34 ,
sizeof( struct V_35 ) ) ? - V_36 : 0 ;
case V_37 :
return F_22 ( 0 , V_31 ) ;
case V_38 :
V_1 = F_2 ( V_2 . V_3 + V_39 ) ;
V_32 = V_1 & V_40 ? V_41 : 0 ;
return F_22 ( V_32 , V_31 ) ;
case V_42 :
F_5 () ;
return 0 ;
case V_43 :
if ( F_23 ( V_32 , V_31 ) )
return - V_36 ;
if ( ( V_32 < 1 ) || ( V_32 > V_44 ) )
return - V_45 ;
F_13 ( V_32 ) ;
V_2 . V_9 = V_32 ;
F_5 () ;
case V_46 :
return F_22 ( V_2 . V_9 , V_31 ) ;
default:
return - V_47 ;
}
}
static T_3 F_24 ( struct V_22 * V_22 , const char T_2 * V_48 ,
T_4 V_49 , T_5 * V_50 )
{
T_4 V_51 ;
char V_52 ;
if ( V_49 == 0 )
return 0 ;
F_19 ( V_25 , & V_2 . V_18 ) ;
for ( V_51 = 0 ; V_51 != V_49 ; V_51 ++ ) {
if ( F_23 ( V_52 , V_48 + V_51 ) )
return - V_36 ;
if ( V_52 == 'V' )
F_25 ( V_25 , & V_2 . V_18 ) ;
}
F_5 () ;
return V_49 ;
}
static int T_6 F_26 ( struct V_53 * V_54 )
{
int V_55 ;
struct V_56 * V_57 ;
V_57 = F_27 ( V_54 , V_58 , 0 ) ;
V_2 . V_3 = F_28 ( & V_54 -> V_59 , V_57 ) ;
if ( F_29 ( V_2 . V_3 ) )
return F_30 ( V_2 . V_3 ) ;
V_2 . V_19 = F_31 ( & V_54 -> V_59 , NULL ) ;
if ( F_29 ( V_2 . V_19 ) ) {
F_32 ( & V_54 -> V_59 , L_2 ) ;
return F_30 ( V_2 . V_19 ) ;
}
V_2 . V_9 = F_33 ( unsigned , V_9 , 1 , V_44 ) ;
if ( V_2 . V_9 != V_9 )
F_34 ( & V_54 -> V_59 , L_3
L_4 , V_9 , V_2 . V_9 ) ;
F_35 ( & V_2 . V_14 , F_6 , 0 ) ;
V_27 . V_28 = & V_54 -> V_59 ;
V_55 = F_36 ( & V_27 ) ;
if ( V_55 )
goto V_60;
F_37 ( & V_54 -> V_59 ,
L_5 ,
V_2 . V_9 , V_26 ) ;
return 0 ;
V_60:
V_27 . V_28 = NULL ;
return V_55 ;
}
static int T_7 F_38 ( struct V_53 * V_54 )
{
F_39 ( & V_27 ) ;
if ( F_17 ( V_17 , & V_2 . V_18 ) ) {
F_11 ( & V_2 . V_14 ) ;
F_18 ( V_27 . V_28 ,
L_6 ) ;
}
V_27 . V_28 = NULL ;
return 0 ;
}
static void F_40 ( struct V_53 * V_54 )
{
if ( F_17 ( V_17 , & V_2 . V_18 ) ) {
F_11 ( & V_2 . V_14 ) ;
F_13 ( V_44 ) ;
F_5 () ;
F_18 ( V_27 . V_28 ,
L_7 ) ;
}
}
