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
F_10 ( V_2 -> V_14 ) ;
while ( F_2 ( V_3 + V_4 ) & 0x04 )
F_3 () ;
F_4 ( V_13 , V_3 + V_15 ) ;
while ( F_2 ( V_3 + V_4 ) & 0x04 )
F_3 () ;
F_11 ( V_2 -> V_14 ) ;
}
static int F_12 ( struct V_16 * V_16 , struct V_17 * V_17 )
{
struct V_1 * V_2 = F_13 ( V_1 ) ;
void T_1 * V_3 = V_2 -> V_3 ;
if ( F_14 ( 1 , ( unsigned long * ) & ( V_2 -> V_18 ) ) )
return - V_19 ;
F_10 ( V_2 -> V_14 ) ;
while ( F_2 ( V_3 + V_4 ) & 0x01 )
F_3 () ;
F_4 ( ( 1 << 5 ) | ( V_20 << 2 ) , V_3 + V_21 ) ;
while ( F_2 ( V_3 + V_4 ) & 0x01 )
F_3 () ;
V_17 -> V_22 = ( void * ) V_2 ;
F_8 ( V_2 ) ;
F_1 ( V_2 ) ;
F_5 ( V_2 ) ;
F_11 ( V_2 -> V_14 ) ;
return F_15 ( V_16 , V_17 ) ;
}
static int F_16 ( struct V_16 * V_16 , struct V_17 * V_17 )
{
struct V_1 * V_2 = V_17 -> V_22 ;
#ifndef F_17
F_10 ( V_2 -> V_14 ) ;
F_6 ( V_2 ) ;
F_11 ( V_2 -> V_14 ) ;
#else
F_18 ( V_23 L_1 ) ;
#endif
V_2 -> V_18 = 0 ;
return 0 ;
}
static T_3 F_19 ( struct V_17 * V_17 , const char T_4 * V_24 ,
T_5 V_25 , T_6 * V_26 )
{
struct V_1 * V_2 = V_17 -> V_22 ;
if ( V_25 ) {
F_10 ( V_2 -> V_14 ) ;
F_20 ( & V_27 ) ;
F_1 ( V_2 ) ;
F_21 ( & V_27 ) ;
F_11 ( V_2 -> V_14 ) ;
}
return V_25 ;
}
static long F_22 ( struct V_17 * V_17 , unsigned int V_28 ,
unsigned long V_29 )
{
struct V_1 * V_2 ;
int V_30 ;
static const struct V_31 V_32 = {
. V_33 = L_2 ,
. V_34 = V_35 ,
. V_36 = 0 ,
} ;
V_2 = V_17 -> V_22 ;
switch ( V_28 ) {
case V_37 :
return F_23 ( (struct V_31 T_4 * ) V_29 , & V_32 ,
sizeof( V_32 ) ) ;
case V_38 :
return F_24 ( 0 , ( int T_4 * ) V_29 ) ;
case V_39 :
if ( F_25 () )
return F_24 ( F_26 ( V_40 ) ,
( int T_4 * ) V_29 ) ;
if ( F_27 () )
return F_24 ( F_28 () ,
( int T_4 * ) V_29 ) ;
return F_24 ( 0 , ( int T_4 * ) V_29 ) ;
case V_41 :
F_10 ( V_2 -> V_14 ) ;
F_20 ( & V_27 ) ;
F_1 ( V_2 ) ;
F_21 ( & V_27 ) ;
F_11 ( V_2 -> V_14 ) ;
return 0 ;
case V_42 :
if ( F_29 ( V_30 , ( int T_4 * ) V_29 ) )
return - V_43 ;
F_7 ( V_30 ) ;
F_10 ( V_2 -> V_14 ) ;
F_20 ( & V_27 ) ;
F_6 ( V_2 ) ;
F_8 ( V_2 ) ;
F_5 ( V_2 ) ;
F_1 ( V_2 ) ;
F_21 ( & V_27 ) ;
F_11 ( V_2 -> V_14 ) ;
case V_44 :
return F_24 ( V_12 , ( int T_4 * ) V_29 ) ;
default:
return - V_45 ;
}
}
static int T_7 F_30 ( struct V_46 * V_47 )
{
struct V_48 * V_49 , * V_50 ;
struct V_1 * V_2 ;
int V_51 ;
V_49 = F_31 ( V_47 , V_52 , 0 ) ;
if ( ! V_49 ) {
V_51 = - V_53 ;
goto V_54;
}
if ( V_1 ) {
V_51 = - V_19 ;
goto V_55;
}
V_50 = F_32 ( V_49 -> V_56 , F_33 ( V_49 ) , V_47 -> V_57 ) ;
if ( ! V_50 ) {
V_51 = - V_19 ;
goto V_55;
}
V_2 = F_34 ( sizeof( struct V_1 ) , V_58 ) ;
if ( ! V_2 ) {
V_51 = - V_59 ;
goto V_60;
}
V_2 -> V_18 = 0 ;
V_2 -> V_50 = V_50 ;
V_2 -> V_14 = & V_47 -> V_14 ;
V_2 -> V_3 = F_35 ( V_49 -> V_56 , F_33 ( V_49 ) ) ;
if ( ! V_2 -> V_3 ) {
V_51 = - V_59 ;
goto V_61;
}
F_36 ( V_47 , V_2 ) ;
F_37 ( V_2 -> V_14 ) ;
F_10 ( V_2 -> V_14 ) ;
F_6 ( V_2 ) ;
F_7 ( V_12 ) ;
V_2 -> V_62 . V_63 = & V_47 -> V_14 ;
V_2 -> V_62 . V_64 = V_65 ;
V_2 -> V_62 . V_57 = L_3 ;
V_2 -> V_62 . V_66 = & V_67 ;
V_51 = F_38 ( & ( V_2 -> V_62 ) ) ;
if ( V_51 )
goto V_68;
F_39 ( L_4 ,
F_2 ( V_2 -> V_3 + V_69 ) & 0xFF ,
V_12 ) ;
F_11 ( V_2 -> V_14 ) ;
V_1 = V_47 ;
return 0 ;
V_68:
F_40 ( V_2 -> V_14 ) ;
F_36 ( V_47 , NULL ) ;
F_41 ( V_2 -> V_3 ) ;
V_61:
V_2 -> V_3 = NULL ;
F_42 ( V_2 ) ;
V_60:
F_43 ( V_49 -> V_56 , F_33 ( V_49 ) ) ;
V_55:
V_54:
return V_51 ;
}
static void F_44 ( struct V_46 * V_47 )
{
struct V_1 * V_2 = F_13 ( V_47 ) ;
if ( V_2 -> V_18 ) {
F_10 ( V_2 -> V_14 ) ;
F_6 ( V_2 ) ;
F_11 ( V_2 -> V_14 ) ;
}
}
static int T_8 F_45 ( struct V_46 * V_47 )
{
struct V_1 * V_2 = F_13 ( V_47 ) ;
struct V_48 * V_49 = F_31 ( V_47 , V_52 , 0 ) ;
F_40 ( V_2 -> V_14 ) ;
if ( ! V_49 )
return - V_53 ;
F_46 ( & ( V_2 -> V_62 ) ) ;
F_43 ( V_49 -> V_56 , F_33 ( V_49 ) ) ;
F_36 ( V_47 , NULL ) ;
F_41 ( V_2 -> V_3 ) ;
F_42 ( V_2 ) ;
V_1 = NULL ;
return 0 ;
}
static int F_47 ( struct V_46 * V_47 , T_9 V_70 )
{
struct V_1 * V_2 = F_13 ( V_47 ) ;
if ( V_2 -> V_18 ) {
F_10 ( V_2 -> V_14 ) ;
F_6 ( V_2 ) ;
F_11 ( V_2 -> V_14 ) ;
}
return 0 ;
}
static int F_48 ( struct V_46 * V_47 )
{
struct V_1 * V_2 = F_13 ( V_47 ) ;
if ( V_2 -> V_18 ) {
F_10 ( V_2 -> V_14 ) ;
F_5 ( V_2 ) ;
F_1 ( V_2 ) ;
F_11 ( V_2 -> V_14 ) ;
}
return 0 ;
}
