static void F_1 ( unsigned long V_1 )
{
if ( V_2 > 2 )
F_2 (KERN_DEBUG PFX L_1 , ticks) ;
if ( V_3 . V_4 )
V_5 -- ;
F_3 ( & V_6 ) ;
F_4 ( 1 , V_7 + V_8 ) ;
if ( V_3 . V_9 && V_5 )
F_5 ( & V_3 . V_10 , V_11 + V_12 ) ;
else {
F_6 ( & V_3 . V_13 ) ;
}
F_7 ( & V_6 ) ;
}
static void F_8 ( void )
{
V_5 = V_3 . V_14 ;
if ( V_2 )
F_2 (KERN_DEBUG PFX L_2 , (int) ticks) ;
}
static void F_9 ( void )
{
unsigned long V_15 ;
F_10 ( & V_6 , V_15 ) ;
if ( ! V_3 . V_9 ) {
V_3 . V_9 = 1 ;
F_4 ( 0 , V_7 + V_16 ) ;
F_4 ( 0 , V_7 + V_17 ) ;
F_4 ( 1 , V_7 + V_18 ) ;
F_4 ( 0 , V_7 + V_19 ) ;
F_4 ( 0 , V_7 + V_20 ) ;
F_5 ( & V_3 . V_10 , V_11 + V_12 ) ;
}
V_3 . V_4 ++ ;
F_11 ( & V_6 , V_15 ) ;
}
static int F_12 ( void )
{
unsigned long V_15 ;
F_10 ( & V_6 , V_15 ) ;
if ( V_3 . V_4 )
V_3 . V_4 = 0 ;
V_5 = V_3 . V_14 ;
F_11 ( & V_6 , V_15 ) ;
if ( V_2 )
F_2 (KERN_CRIT PFX L_3 ) ;
return - V_21 ;
}
static int F_13 ( struct V_22 * V_22 , struct V_23 * V_23 )
{
if ( F_14 ( 0 , & V_3 . V_24 ) )
return - V_25 ;
return F_15 ( V_22 , V_23 ) ;
}
static int F_16 ( struct V_22 * V_22 , struct V_23 * V_23 )
{
F_17 ( 0 , & V_3 . V_24 ) ;
return 0 ;
}
static long F_18 ( struct V_23 * V_23 , unsigned int V_26 ,
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
if ( F_19 ( V_28 , & V_32 , sizeof( V_32 ) ) )
return - V_37 ;
break;
case V_38 :
V_30 = F_20 ( V_7 + V_39 ) ;
V_30 = ( V_30 >> 2 ) & 1 ;
return F_21 ( V_30 , V_29 ) ;
case V_40 :
return F_21 ( 0 , V_29 ) ;
case V_41 :
if ( F_22 ( V_30 , V_29 ) )
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
static T_2 F_23 ( struct V_23 * V_23 , const char T_1 * V_46 ,
T_3 V_47 , T_4 * V_48 )
{
if ( ! V_47 )
return - V_21 ;
F_8 () ;
return V_47 ;
}
static int T_5 F_24 ( void )
{
unsigned int V_49 ;
int V_50 ;
if ( V_2 )
F_2 (KERN_DEBUG PFX
L_5 , port, verbose) ;
F_25 ( & V_3 . V_13 ) ;
F_26 ( & V_6 ) ;
V_3 . V_9 = 0 ;
F_27 ( & V_3 . V_10 , F_1 , 0 ) ;
V_3 . V_14 = V_5 ;
if ( ! F_28 ( V_7 , V_51 , V_52 ) ) {
F_2 (KERN_ERR PFX L_6 ) ;
V_50 = - V_25 ;
goto V_53;
}
V_49 = F_20 ( V_7 + V_39 ) ;
V_49 = ( V_49 >> 2 ) & 1 ;
if ( ! V_49 )
F_2 (KERN_INFO PFX L_7 ) ;
V_50 = F_29 ( & V_54 ) ;
if ( V_50 < 0 ) {
F_2 (KERN_ERR PFX L_8 ) ;
goto V_55;
}
F_2 (KERN_INFO PFX L_9 ) ;
return 0 ;
V_55:
F_30 ( V_7 , V_51 ) ;
V_53:
return V_50 ;
}
static int T_5 F_31 ( void )
{
return F_24 () ;
}
static void T_6 F_32 ( void )
{
if ( V_3 . V_9 ) {
V_3 . V_9 = 0 ;
F_33 ( & V_3 . V_13 ) ;
}
F_34 ( & V_54 ) ;
F_30 ( V_7 , V_51 ) ;
}
static void T_6 F_35 ( void )
{
F_32 () ;
}
