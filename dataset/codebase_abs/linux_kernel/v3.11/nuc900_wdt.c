static inline void F_1 ( void )
{
unsigned int V_1 ;
F_2 ( & V_2 -> V_3 ) ;
V_1 = F_3 ( V_2 -> V_4 + V_5 ) ;
V_1 |= ( V_6 | V_7 ) ;
F_4 ( V_1 , V_2 -> V_4 + V_5 ) ;
F_5 ( & V_2 -> V_3 ) ;
}
static inline void F_6 ( void )
{
unsigned int V_1 ;
F_2 ( & V_2 -> V_3 ) ;
V_1 = F_3 ( V_2 -> V_4 + V_5 ) ;
V_1 |= ( V_8 | V_9 | V_6 | V_10 | V_7 ) ;
V_1 &= ~ V_11 ;
V_1 |= ( V_12 << 0x04 ) ;
F_4 ( V_1 , V_2 -> V_4 + V_5 ) ;
F_5 ( & V_2 -> V_3 ) ;
V_2 -> V_13 = V_14 + V_15 * V_16 ;
F_7 ( & V_2 -> V_17 , V_14 + V_18 ) ;
}
static inline void F_8 ( void )
{
unsigned int V_1 ;
F_9 ( & V_2 -> V_17 ) ;
F_2 ( & V_2 -> V_3 ) ;
V_1 = F_3 ( V_2 -> V_4 + V_5 ) ;
V_1 &= ~ V_9 ;
F_4 ( V_1 , V_2 -> V_4 + V_5 ) ;
F_5 ( & V_2 -> V_3 ) ;
}
static inline void F_10 ( void )
{
V_2 -> V_13 = V_14 + V_15 * V_16 ;
}
static int F_11 ( struct V_19 * V_19 , struct V_20 * V_20 )
{
if ( F_12 ( 0 , & V_21 ) )
return - V_22 ;
F_6 () ;
return F_13 ( V_19 , V_20 ) ;
}
static int F_14 ( struct V_19 * V_19 , struct V_20 * V_20 )
{
if ( V_2 -> V_23 == 42 )
F_8 () ;
else {
F_15 ( & V_2 -> V_24 -> V_25 ,
L_1 ) ;
F_10 () ;
}
V_2 -> V_23 = 0 ;
F_16 ( 0 , & V_21 ) ;
return 0 ;
}
static long F_17 ( struct V_20 * V_20 ,
unsigned int V_26 , unsigned long V_27 )
{
void T_1 * V_28 = ( void T_1 * ) V_27 ;
int T_1 * V_29 = V_28 ;
int V_30 ;
switch ( V_26 ) {
case V_31 :
return F_18 ( V_28 , & V_32 ,
sizeof( V_32 ) ) ? - V_33 : 0 ;
case V_34 :
case V_35 :
return F_19 ( 0 , V_29 ) ;
case V_36 :
F_10 () ;
return 0 ;
case V_37 :
if ( F_20 ( V_30 , V_29 ) )
return - V_33 ;
V_15 = V_30 ;
F_10 () ;
return F_19 ( V_30 , V_29 ) ;
case V_38 :
return F_19 ( V_15 , V_29 ) ;
default:
return - V_39 ;
}
}
static T_2 F_21 ( struct V_20 * V_20 , const char T_1 * V_40 ,
T_3 V_41 , T_4 * V_42 )
{
if ( ! V_41 )
return 0 ;
if ( ! V_43 ) {
T_3 V_44 ;
V_2 -> V_23 = 0 ;
for ( V_44 = 0 ; V_44 < V_41 ; V_44 ++ ) {
char V_45 ;
if ( F_20 ( V_45 , V_40 + V_44 ) )
return - V_33 ;
if ( V_45 == 'V' ) {
V_2 -> V_23 = 42 ;
break;
}
}
}
F_10 () ;
return V_41 ;
}
static void F_22 ( unsigned long V_40 )
{
if ( F_23 ( V_14 , V_2 -> V_13 ) ) {
F_1 () ;
F_7 ( & V_2 -> V_17 , V_14 + V_18 ) ;
} else
F_24 ( & V_2 -> V_24 -> V_25 , L_2 ) ;
}
static int F_25 ( struct V_46 * V_24 )
{
struct V_47 * V_48 ;
int V_49 = 0 ;
V_2 = F_26 ( & V_24 -> V_25 , sizeof( * V_2 ) ,
V_50 ) ;
if ( ! V_2 )
return - V_51 ;
V_2 -> V_24 = V_24 ;
F_27 ( & V_2 -> V_3 ) ;
V_48 = F_28 ( V_24 , V_52 , 0 ) ;
if ( V_48 == NULL ) {
F_29 ( & V_24 -> V_25 , L_3 ) ;
return - V_53 ;
}
V_2 -> V_4 = F_30 ( & V_24 -> V_25 , V_48 ) ;
if ( F_31 ( V_2 -> V_4 ) )
return F_32 ( V_2 -> V_4 ) ;
V_2 -> V_54 = F_33 ( & V_24 -> V_25 , NULL ) ;
if ( F_31 ( V_2 -> V_54 ) ) {
F_29 ( & V_24 -> V_25 , L_4 ) ;
return F_32 ( V_2 -> V_54 ) ;
}
F_34 ( V_2 -> V_54 ) ;
F_35 ( & V_2 -> V_17 , F_22 , 0 ) ;
V_49 = F_36 ( & V_55 ) ;
if ( V_49 ) {
F_29 ( & V_24 -> V_25 , L_5 ,
V_56 , V_49 ) ;
goto V_57;
}
return 0 ;
V_57:
F_37 ( V_2 -> V_54 ) ;
return V_49 ;
}
static int F_38 ( struct V_46 * V_24 )
{
F_39 ( & V_55 ) ;
F_37 ( V_2 -> V_54 ) ;
return 0 ;
}
