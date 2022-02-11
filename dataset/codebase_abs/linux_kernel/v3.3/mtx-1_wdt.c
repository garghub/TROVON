static void F_1 ( unsigned long V_1 )
{
F_2 ( & V_2 . V_3 ) ;
if ( V_2 . V_4 )
V_5 -- ;
V_2 . V_6 = ! V_2 . V_6 ;
F_3 ( V_2 . V_7 , V_2 . V_6 ) ;
if ( V_2 . V_8 && V_5 )
F_4 ( & V_2 . V_9 , V_10 + V_11 ) ;
else
F_5 ( & V_2 . V_12 ) ;
F_6 ( & V_2 . V_3 ) ;
}
static void F_7 ( void )
{
V_5 = V_2 . V_13 ;
}
static void F_8 ( void )
{
unsigned long V_14 ;
F_9 ( & V_2 . V_3 , V_14 ) ;
if ( ! V_2 . V_8 ) {
V_2 . V_8 = 1 ;
V_2 . V_6 = 1 ;
F_3 ( V_2 . V_7 , 1 ) ;
F_4 ( & V_2 . V_9 , V_10 + V_11 ) ;
}
V_2 . V_4 ++ ;
F_10 ( & V_2 . V_3 , V_14 ) ;
}
static int F_11 ( void )
{
unsigned long V_14 ;
F_9 ( & V_2 . V_3 , V_14 ) ;
if ( V_2 . V_8 ) {
V_2 . V_8 = 0 ;
V_2 . V_6 = 0 ;
F_3 ( V_2 . V_7 , 0 ) ;
}
V_5 = V_2 . V_13 ;
F_10 ( & V_2 . V_3 , V_14 ) ;
return 0 ;
}
static int F_12 ( struct V_15 * V_15 , struct V_16 * V_16 )
{
if ( F_13 ( 0 , & V_2 . V_17 ) )
return - V_18 ;
return F_14 ( V_15 , V_16 ) ;
}
static int F_15 ( struct V_15 * V_15 , struct V_16 * V_16 )
{
F_16 ( 0 , & V_2 . V_17 ) ;
return 0 ;
}
static long F_17 ( struct V_16 * V_16 , unsigned int V_19 ,
unsigned long V_20 )
{
void T_1 * V_21 = ( void T_1 * ) V_20 ;
int T_1 * V_22 = ( int T_1 * ) V_21 ;
unsigned int V_23 ;
static const struct V_24 V_25 = {
. V_26 = V_27 ,
. V_28 = L_1 ,
} ;
switch ( V_19 ) {
case V_29 :
if ( F_18 ( V_21 , & V_25 , sizeof( V_25 ) ) )
return - V_30 ;
break;
case V_31 :
case V_32 :
F_19 ( 0 , V_22 ) ;
break;
case V_33 :
if ( F_20 ( V_23 , V_22 ) )
return - V_30 ;
if ( V_23 & V_34 )
F_8 () ;
else if ( V_23 & V_35 )
F_11 () ;
else
return - V_36 ;
return 0 ;
case V_37 :
F_7 () ;
break;
default:
return - V_38 ;
}
return 0 ;
}
static T_2 F_21 ( struct V_16 * V_16 , const char * V_39 ,
T_3 V_40 , T_4 * V_41 )
{
if ( ! V_40 )
return - V_42 ;
F_7 () ;
return V_40 ;
}
static int T_5 F_22 ( struct V_43 * V_44 )
{
int V_45 ;
V_2 . V_7 = V_44 -> V_46 [ 0 ] . V_47 ;
V_45 = F_23 ( V_2 . V_7 ,
V_48 , L_2 ) ;
if ( V_45 < 0 ) {
F_24 ( & V_44 -> V_49 , L_3 ) ;
return V_45 ;
}
F_25 ( & V_2 . V_3 ) ;
F_26 ( & V_2 . V_12 ) ;
V_2 . V_8 = 0 ;
F_16 ( 0 , & V_2 . V_17 ) ;
F_27 ( & V_2 . V_9 , F_1 , 0L ) ;
V_2 . V_13 = V_5 ;
V_45 = F_28 ( & V_50 ) ;
if ( V_45 < 0 ) {
F_24 ( & V_44 -> V_49 , L_4 ) ;
return V_45 ;
}
F_8 () ;
F_29 ( & V_44 -> V_49 , L_5 ) ;
return 0 ;
}
static int T_6 F_30 ( struct V_43 * V_44 )
{
if ( V_2 . V_8 ) {
V_2 . V_8 = 0 ;
F_31 ( & V_2 . V_12 ) ;
}
F_32 ( V_2 . V_7 ) ;
F_33 ( & V_50 ) ;
return 0 ;
}
