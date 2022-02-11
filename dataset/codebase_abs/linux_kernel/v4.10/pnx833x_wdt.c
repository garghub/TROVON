static void F_1 ( void )
{
F_2 ( V_1 + V_2 ) |= 0x1 ;
F_2 ( V_3 +
V_4 ) = V_5 ;
F_2 ( V_3 +
V_6 ) |= 0x1 ;
F_3 ( L_1 ) ;
}
static void F_4 ( void )
{
F_2 ( V_1 + V_3 ) &= 0xFFFFFFFE ;
F_2 ( V_3 +
V_6 ) &= 0xFFFFFFFE ;
F_3 ( L_2 ) ;
}
static void F_5 ( void )
{
F_2 ( V_3 +
V_4 ) = V_5 ;
}
static int F_6 ( struct V_7 * V_7 , struct V_8 * V_8 )
{
if ( F_7 ( 0 , & V_9 ) )
return - V_10 ;
if ( V_11 )
F_8 ( V_12 ) ;
if ( ! V_13 )
F_1 () ;
F_5 () ;
F_3 ( L_1 ) ;
return F_9 ( V_7 , V_8 ) ;
}
static int F_10 ( struct V_7 * V_7 , struct V_8 * V_8 )
{
if ( ! V_11 )
F_4 () ;
F_11 ( 0 , & V_9 ) ;
return 0 ;
}
static T_1 F_12 ( struct V_8 * V_8 , const char * V_14 , T_2 V_15 , T_3 * V_16 )
{
if ( V_15 )
F_5 () ;
return V_15 ;
}
static long F_13 ( struct V_8 * V_8 , unsigned int V_17 ,
unsigned long V_18 )
{
int V_19 , V_20 = 0 ;
T_4 V_21 , V_22 = 0 ;
static const struct V_23 V_24 = {
. V_19 = V_25 | V_26 ,
. V_27 = 0 ,
. V_28 = L_3 ,
} ;
switch ( V_17 ) {
default:
return - V_29 ;
case V_30 :
if ( F_14 ( (struct V_23 * ) V_18 ,
& V_24 , sizeof( V_24 ) ) )
return - V_31 ;
return 0 ;
case V_32 :
case V_33 :
return F_15 ( 0 , ( int * ) V_18 ) ;
case V_34 :
if ( F_16 ( V_19 , ( int * ) V_18 ) )
return - V_31 ;
if ( V_19 & V_35 )
F_4 () ;
if ( V_19 & V_36 )
F_1 () ;
return 0 ;
case V_37 :
F_5 () ;
return 0 ;
case V_38 :
{
if ( F_16 ( V_20 , ( int * ) V_18 ) )
return - V_31 ;
V_5 = V_20 ;
F_2 ( V_3 +
V_4 ) = V_20 ;
return F_15 ( V_20 , ( int * ) V_18 ) ;
}
case V_39 :
V_21 = F_2 ( V_3 +
V_4 ) ;
return F_15 ( V_21 , ( int * ) V_18 ) ;
case V_40 :
V_22 = F_2 ( V_3 +
V_41 ) ;
return F_15 ( V_22 , ( int * ) V_18 ) ;
}
}
static int F_17 ( struct V_42 * V_43 ,
unsigned long V_44 , void * V_45 )
{
if ( V_44 == V_46 || V_44 == V_47 )
F_4 () ;
return V_48 ;
}
static int T_5 F_18 ( void )
{
int V_49 , V_50 ;
V_50 = F_2 ( V_1 ) ;
if ( V_50 & 0x80000000 ) {
F_3 ( L_4 ) ;
}
V_49 = F_19 ( & V_51 ) ;
if ( V_49 ) {
F_20 ( L_5 , V_49 ) ;
return V_49 ;
}
V_49 = F_21 ( & V_52 ) ;
if ( V_49 ) {
F_20 ( L_6 ,
V_53 , V_49 ) ;
F_22 ( & V_51 ) ;
return V_49 ;
}
F_3 ( L_7 ) ;
if ( V_13 )
F_1 () ;
return 0 ;
}
static void T_6 F_23 ( void )
{
F_24 ( & V_52 ) ;
F_22 ( & V_51 ) ;
}
