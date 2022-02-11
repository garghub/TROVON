static void F_1 ( unsigned long V_1 )
{
if ( V_2 > 2 )
F_2 ( L_1 , V_3 ) ;
if ( V_4 . V_5 )
V_3 -- ;
F_3 ( & V_6 ) ;
F_4 ( 1 , V_7 + V_8 ) ;
if ( V_4 . V_9 && V_3 )
F_5 ( & V_4 . V_10 , V_11 + V_12 ) ;
else {
F_6 ( & V_4 . V_13 ) ;
}
F_7 ( & V_6 ) ;
}
static void F_8 ( void )
{
V_3 = V_4 . V_14 ;
if ( V_2 )
F_2 ( L_2 , ( int ) V_3 ) ;
}
static void F_9 ( void )
{
unsigned long V_15 ;
F_10 ( & V_6 , V_15 ) ;
if ( ! V_4 . V_9 ) {
V_4 . V_9 = 1 ;
F_4 ( 0 , V_7 + V_16 ) ;
F_4 ( 0 , V_7 + V_17 ) ;
F_4 ( 1 , V_7 + V_18 ) ;
F_4 ( 0 , V_7 + V_19 ) ;
F_4 ( 0 , V_7 + V_20 ) ;
F_5 ( & V_4 . V_10 , V_11 + V_12 ) ;
}
V_4 . V_5 ++ ;
F_11 ( & V_6 , V_15 ) ;
}
static int F_12 ( void )
{
unsigned long V_15 ;
F_10 ( & V_6 , V_15 ) ;
if ( V_4 . V_5 )
V_4 . V_5 = 0 ;
V_3 = V_4 . V_14 ;
F_11 ( & V_6 , V_15 ) ;
if ( V_2 )
F_13 ( L_3 ) ;
return - V_21 ;
}
static int F_14 ( struct V_22 * V_22 , struct V_23 * V_23 )
{
if ( F_15 ( 0 , & V_4 . V_24 ) )
return - V_25 ;
return F_16 ( V_22 , V_23 ) ;
}
static int F_17 ( struct V_22 * V_22 , struct V_23 * V_23 )
{
F_18 ( 0 , & V_4 . V_24 ) ;
return 0 ;
}
static long F_19 ( struct V_23 * V_23 , unsigned int V_26 ,
unsigned long V_27 )
{
void T_1 * V_28 = ( void T_1 * ) V_27 ;
int T_1 * V_29 = V_28 ;
unsigned int V_30 ;
static const struct V_31 V_32 = {
. V_33 = V_34 ,
. V_35 = L_4 ,
} ;
switch ( V_26 ) {
case V_36 :
if ( F_20 ( V_28 , & V_32 , sizeof( V_32 ) ) )
return - V_37 ;
break;
case V_38 :
V_30 = F_21 ( V_7 + V_39 ) ;
V_30 = ( V_30 >> 2 ) & 1 ;
return F_22 ( V_30 , V_29 ) ;
case V_40 :
return F_22 ( 0 , V_29 ) ;
case V_41 :
if ( F_23 ( V_30 , V_29 ) )
return - V_37 ;
if ( V_30 & V_42 )
F_9 () ;
if ( V_30 & V_43 )
F_12 () ;
break;
case V_44 :
F_8 () ;
break;
default:
return - V_45 ;
}
return 0 ;
}
static T_2 F_24 ( struct V_23 * V_23 , const char T_1 * V_46 ,
T_3 V_47 , T_4 * V_48 )
{
if ( ! V_47 )
return - V_21 ;
F_8 () ;
return V_47 ;
}
static int T_5 F_25 ( void )
{
unsigned int V_49 ;
int V_50 ;
if ( V_2 )
F_2 ( L_5 , V_7 , V_2 ) ;
F_26 ( & V_4 . V_13 ) ;
V_4 . V_9 = 0 ;
F_27 ( & V_4 . V_10 , F_1 , 0 ) ;
V_4 . V_14 = V_3 ;
if ( ! F_28 ( V_7 , V_51 , V_52 ) ) {
F_29 ( L_6 ) ;
V_50 = - V_25 ;
goto V_53;
}
V_49 = F_21 ( V_7 + V_39 ) ;
V_49 = ( V_49 >> 2 ) & 1 ;
if ( ! V_49 )
F_30 ( L_7 ) ;
V_50 = F_31 ( & V_54 ) ;
if ( V_50 < 0 ) {
F_29 ( L_8 ) ;
goto V_55;
}
F_30 ( L_9 ) ;
return 0 ;
V_55:
F_32 ( V_7 , V_51 ) ;
V_53:
return V_50 ;
}
static int T_5 F_33 ( void )
{
return F_25 () ;
}
static void T_6 F_34 ( void )
{
if ( V_4 . V_9 ) {
V_4 . V_9 = 0 ;
F_35 ( & V_4 . V_13 ) ;
}
F_36 ( & V_54 ) ;
F_32 ( V_7 , V_51 ) ;
}
static void T_6 F_37 ( void )
{
F_34 () ;
}
