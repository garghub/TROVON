static void F_1 ( struct V_1 * V_2 )
{
void T_1 * V_3 = V_2 -> V_3 ;
while ( ( F_2 ( V_3 + V_4 ) ) & 0x08 )
F_3 () ;
V_5 = ~ V_5 ;
F_4 ( V_5 , ( V_3 + V_6 ) ) ;
while ( ( F_2 ( V_3 + V_4 ) ) & 0x08 )
F_3 () ;
}
static void F_5 ( struct V_1 * V_2 )
{
void T_1 * V_3 = V_2 -> V_3 ;
F_4 ( 0xBBBB , V_3 + V_7 ) ;
while ( ( F_2 ( V_3 + V_4 ) ) & 0x10 )
F_3 () ;
F_4 ( 0x4444 , V_3 + V_7 ) ;
while ( ( F_2 ( V_3 + V_4 ) ) & 0x10 )
F_3 () ;
}
static void F_6 ( struct V_1 * V_2 )
{
void T_1 * V_3 = V_2 -> V_3 ;
F_4 ( 0xAAAA , V_3 + V_7 ) ;
while ( F_2 ( V_3 + V_4 ) & 0x10 )
F_3 () ;
F_4 ( 0x5555 , V_3 + V_7 ) ;
while ( F_2 ( V_3 + V_4 ) & 0x10 )
F_3 () ;
}
static void F_7 ( unsigned V_8 )
{
if ( V_8 < V_9 )
V_8 = V_10 ;
if ( V_8 > V_11 )
V_8 = V_11 ;
V_12 = V_8 ;
}
static void F_8 ( struct V_1 * V_2 )
{
T_2 V_13 = F_9 ( V_12 ) ;
void T_1 * V_3 = V_2 -> V_3 ;
while ( F_2 ( V_3 + V_4 ) & 0x04 )
F_3 () ;
F_4 ( V_13 , V_3 + V_14 ) ;
while ( F_2 ( V_3 + V_4 ) & 0x04 )
F_3 () ;
}
static int F_10 ( struct V_15 * V_15 , struct V_16 * V_16 )
{
struct V_1 * V_2 = F_11 ( V_1 ) ;
void T_1 * V_3 = V_2 -> V_3 ;
if ( F_12 ( 1 , ( unsigned long * ) & ( V_2 -> V_17 ) ) )
return - V_18 ;
F_13 ( V_2 -> V_19 ) ;
while ( F_2 ( V_3 + V_4 ) & 0x01 )
F_3 () ;
F_4 ( ( 1 << 5 ) | ( V_20 << 2 ) , V_3 + V_21 ) ;
while ( F_2 ( V_3 + V_4 ) & 0x01 )
F_3 () ;
V_16 -> V_22 = ( void * ) V_2 ;
F_8 ( V_2 ) ;
F_1 ( V_2 ) ;
F_5 ( V_2 ) ;
return F_14 ( V_15 , V_16 ) ;
}
static int F_15 ( struct V_15 * V_15 , struct V_16 * V_16 )
{
struct V_1 * V_2 = V_16 -> V_22 ;
#ifndef F_16
F_6 ( V_2 ) ;
F_17 ( V_2 -> V_19 ) ;
#else
F_18 ( L_1 ) ;
#endif
V_2 -> V_17 = 0 ;
return 0 ;
}
static T_3 F_19 ( struct V_16 * V_16 , const char T_4 * V_23 ,
T_5 V_24 , T_6 * V_25 )
{
struct V_1 * V_2 = V_16 -> V_22 ;
if ( V_24 ) {
F_20 ( & V_26 ) ;
F_1 ( V_2 ) ;
F_21 ( & V_26 ) ;
}
return V_24 ;
}
static long F_22 ( struct V_16 * V_16 , unsigned int V_27 ,
unsigned long V_28 )
{
struct V_1 * V_2 ;
int V_29 ;
static const struct V_30 V_31 = {
. V_32 = L_2 ,
. V_33 = V_34 ,
. V_35 = 0 ,
} ;
V_2 = V_16 -> V_22 ;
switch ( V_27 ) {
case V_36 :
return F_23 ( (struct V_30 T_4 * ) V_28 , & V_31 ,
sizeof( V_31 ) ) ;
case V_37 :
return F_24 ( 0 , ( int T_4 * ) V_28 ) ;
case V_38 :
#ifdef F_25
if ( F_26 () )
return F_24 ( F_27 ( V_39 ) ,
( int T_4 * ) V_28 ) ;
#endif
#ifdef F_28
if ( F_29 () )
return F_24 ( F_30 () ,
( int T_4 * ) V_28 ) ;
#endif
return F_24 ( 0 , ( int T_4 * ) V_28 ) ;
case V_40 :
F_20 ( & V_26 ) ;
F_1 ( V_2 ) ;
F_21 ( & V_26 ) ;
return 0 ;
case V_41 :
if ( F_31 ( V_29 , ( int T_4 * ) V_28 ) )
return - V_42 ;
F_7 ( V_29 ) ;
F_20 ( & V_26 ) ;
F_6 ( V_2 ) ;
F_8 ( V_2 ) ;
F_5 ( V_2 ) ;
F_1 ( V_2 ) ;
F_21 ( & V_26 ) ;
case V_43 :
return F_24 ( V_12 , ( int T_4 * ) V_28 ) ;
default:
return - V_44 ;
}
}
static int T_7 F_32 ( struct V_45 * V_46 )
{
struct V_47 * V_48 , * V_49 ;
struct V_1 * V_2 ;
int V_50 ;
V_48 = F_33 ( V_46 , V_51 , 0 ) ;
if ( ! V_48 ) {
V_50 = - V_52 ;
goto V_53;
}
if ( V_1 ) {
V_50 = - V_18 ;
goto V_54;
}
V_49 = F_34 ( V_48 -> V_55 , F_35 ( V_48 ) , V_46 -> V_56 ) ;
if ( ! V_49 ) {
V_50 = - V_18 ;
goto V_54;
}
V_2 = F_36 ( sizeof( struct V_1 ) , V_57 ) ;
if ( ! V_2 ) {
V_50 = - V_58 ;
goto V_59;
}
V_2 -> V_17 = 0 ;
V_2 -> V_49 = V_49 ;
V_2 -> V_19 = & V_46 -> V_19 ;
V_2 -> V_3 = F_37 ( V_48 -> V_55 , F_35 ( V_48 ) ) ;
if ( ! V_2 -> V_3 ) {
V_50 = - V_58 ;
goto V_60;
}
F_38 ( V_46 , V_2 ) ;
F_39 ( V_2 -> V_19 ) ;
F_13 ( V_2 -> V_19 ) ;
F_6 ( V_2 ) ;
F_7 ( V_12 ) ;
V_2 -> V_61 . V_62 = & V_46 -> V_19 ;
V_2 -> V_61 . V_63 = V_64 ;
V_2 -> V_61 . V_56 = L_3 ;
V_2 -> V_61 . V_65 = & V_66 ;
V_50 = F_40 ( & ( V_2 -> V_61 ) ) ;
if ( V_50 )
goto V_67;
F_41 ( L_4 ,
F_2 ( V_2 -> V_3 + V_68 ) & 0xFF ,
V_12 ) ;
F_17 ( V_2 -> V_19 ) ;
V_1 = V_46 ;
return 0 ;
V_67:
F_42 ( V_2 -> V_19 ) ;
F_38 ( V_46 , NULL ) ;
F_43 ( V_2 -> V_3 ) ;
V_60:
V_2 -> V_3 = NULL ;
F_44 ( V_2 ) ;
V_59:
F_45 ( V_48 -> V_55 , F_35 ( V_48 ) ) ;
V_54:
V_53:
return V_50 ;
}
static void F_46 ( struct V_45 * V_46 )
{
struct V_1 * V_2 = F_11 ( V_46 ) ;
if ( V_2 -> V_17 ) {
F_6 ( V_2 ) ;
F_17 ( V_2 -> V_19 ) ;
}
}
static int T_8 F_47 ( struct V_45 * V_46 )
{
struct V_1 * V_2 = F_11 ( V_46 ) ;
struct V_47 * V_48 = F_33 ( V_46 , V_51 , 0 ) ;
F_42 ( V_2 -> V_19 ) ;
if ( ! V_48 )
return - V_52 ;
F_48 ( & ( V_2 -> V_61 ) ) ;
F_45 ( V_48 -> V_55 , F_35 ( V_48 ) ) ;
F_38 ( V_46 , NULL ) ;
F_43 ( V_2 -> V_3 ) ;
F_44 ( V_2 ) ;
V_1 = NULL ;
return 0 ;
}
static int F_49 ( struct V_45 * V_46 , T_9 V_69 )
{
struct V_1 * V_2 = F_11 ( V_46 ) ;
if ( V_2 -> V_17 ) {
F_6 ( V_2 ) ;
F_17 ( V_2 -> V_19 ) ;
}
return 0 ;
}
static int F_50 ( struct V_45 * V_46 )
{
struct V_1 * V_2 = F_11 ( V_46 ) ;
if ( V_2 -> V_17 ) {
F_13 ( V_2 -> V_19 ) ;
F_5 ( V_2 ) ;
F_1 ( V_2 ) ;
}
return 0 ;
}
