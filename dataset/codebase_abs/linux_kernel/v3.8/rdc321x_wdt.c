static void F_1 ( unsigned long V_1 )
{
unsigned long V_2 ;
T_1 V_3 ;
if ( V_4 . V_5 )
V_6 -- ;
F_2 ( & V_4 . V_7 , V_2 ) ;
F_3 ( V_4 . V_8 ,
V_4 . V_9 , & V_3 ) ;
V_3 |= V_10 ;
F_4 ( V_4 . V_8 ,
V_4 . V_9 , V_3 ) ;
F_5 ( & V_4 . V_7 , V_2 ) ;
if ( V_4 . V_11 && V_6 )
F_6 ( & V_4 . V_12 ,
V_13 + V_14 ) ;
else {
F_7 ( & V_4 . V_15 ) ;
}
}
static void F_8 ( void )
{
V_6 = V_4 . V_16 ;
}
static void F_9 ( void )
{
unsigned long V_2 ;
if ( ! V_4 . V_11 ) {
V_4 . V_11 = 1 ;
F_2 ( & V_4 . V_7 , V_2 ) ;
F_4 ( V_4 . V_8 ,
V_4 . V_9 , V_17 ) ;
F_4 ( V_4 . V_8 ,
V_4 . V_9 ,
V_10 | V_18 ) ;
F_5 ( & V_4 . V_7 , V_2 ) ;
F_6 ( & V_4 . V_12 ,
V_13 + V_14 ) ;
}
V_4 . V_5 ++ ;
}
static int F_10 ( void )
{
if ( V_4 . V_5 )
V_4 . V_5 = 0 ;
V_6 = V_4 . V_16 ;
return - V_19 ;
}
static int F_11 ( struct V_20 * V_20 , struct V_21 * V_21 )
{
if ( F_12 ( 0 , & V_4 . V_22 ) )
return - V_23 ;
return F_13 ( V_20 , V_21 ) ;
}
static int F_14 ( struct V_20 * V_20 , struct V_21 * V_21 )
{
F_15 ( 0 , & V_4 . V_22 ) ;
return 0 ;
}
static long F_16 ( struct V_21 * V_21 , unsigned int V_24 ,
unsigned long V_25 )
{
void T_2 * V_26 = ( void T_2 * ) V_25 ;
T_1 V_27 ;
static const struct V_28 V_29 = {
. V_30 = V_31 ,
. V_32 = L_1 ,
} ;
unsigned long V_2 ;
switch ( V_24 ) {
case V_33 :
F_8 () ;
break;
case V_34 :
F_2 ( & V_4 . V_7 , V_2 ) ;
F_3 ( V_4 . V_8 ,
V_4 . V_9 , & V_27 ) ;
F_5 ( & V_4 . V_7 , V_2 ) ;
if ( F_17 ( V_26 , & V_27 , sizeof( T_1 ) ) )
return - V_35 ;
break;
case V_36 :
if ( F_17 ( V_26 , & V_29 , sizeof( V_29 ) ) )
return - V_35 ;
break;
case V_37 :
if ( F_18 ( & V_27 , V_26 , sizeof( int ) ) )
return - V_35 ;
switch ( V_27 ) {
case V_38 :
F_9 () ;
break;
case V_39 :
return F_10 () ;
default:
return - V_40 ;
}
break;
default:
return - V_41 ;
}
return 0 ;
}
static T_3 F_19 ( struct V_21 * V_21 , const char T_2 * V_42 ,
T_4 V_43 , T_5 * V_44 )
{
if ( ! V_43 )
return - V_19 ;
F_8 () ;
return V_43 ;
}
static int F_20 ( struct V_45 * V_46 )
{
int V_47 ;
struct V_48 * V_49 ;
struct V_50 * V_51 ;
V_51 = V_46 -> V_52 . V_53 ;
if ( ! V_51 ) {
F_21 ( & V_46 -> V_52 , L_2 ) ;
return - V_54 ;
}
V_49 = F_22 ( V_46 , V_55 , L_3 ) ;
if ( ! V_49 ) {
F_21 ( & V_46 -> V_52 , L_4 ) ;
return - V_54 ;
}
V_4 . V_8 = V_51 -> V_8 ;
V_4 . V_9 = V_49 -> V_56 ;
V_47 = F_23 ( & V_57 ) ;
if ( V_47 < 0 ) {
F_21 ( & V_46 -> V_52 , L_5 ) ;
return V_47 ;
}
F_24 ( & V_4 . V_7 ) ;
F_4 ( V_4 . V_8 ,
V_4 . V_9 , V_58 ) ;
F_25 ( & V_4 . V_15 ) ;
V_4 . V_11 = 0 ;
F_15 ( 0 , & V_4 . V_22 ) ;
F_26 ( & V_4 . V_12 , F_1 , 0 ) ;
V_4 . V_16 = V_6 ;
F_27 ( & V_46 -> V_52 , L_6 ) ;
return 0 ;
}
static int F_28 ( struct V_45 * V_46 )
{
if ( V_4 . V_11 ) {
V_4 . V_11 = 0 ;
F_29 ( & V_4 . V_15 ) ;
}
F_30 ( & V_57 ) ;
return 0 ;
}
