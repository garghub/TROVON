static void F_1 ( void )
{
F_2 ( & V_1 ) ;
F_3 ( V_2 * V_3 , V_4 ) ;
F_4 ( & V_1 ) ;
}
static void F_5 ( void )
{
T_1 V_5 ;
F_2 ( & V_1 ) ;
F_3 ( V_2 * V_3 , V_4 ) ;
V_5 = F_6 ( V_6 ) ;
V_5 &= ~ V_7 ;
F_3 ( V_5 , V_6 ) ;
V_5 = F_6 ( V_8 ) ;
V_5 |= V_9 ;
F_3 ( V_5 , V_8 ) ;
V_5 = F_6 ( V_10 ) ;
V_5 |= V_11 ;
F_3 ( V_5 , V_10 ) ;
F_4 ( & V_1 ) ;
}
static void F_7 ( void )
{
T_1 V_5 ;
F_2 ( & V_1 ) ;
V_5 = F_6 ( V_10 ) ;
V_5 &= ~ V_11 ;
F_3 ( V_5 , V_10 ) ;
V_5 = F_6 ( V_8 ) ;
V_5 &= ~ V_9 ;
F_3 ( V_5 , V_8 ) ;
F_4 ( & V_1 ) ;
}
static int F_8 ( int * V_12 )
{
F_2 ( & V_1 ) ;
* V_12 = F_6 ( V_4 ) / V_2 ;
F_4 ( & V_1 ) ;
return 0 ;
}
static int F_9 ( struct V_13 * V_13 , struct V_14 * V_14 )
{
if ( F_10 ( V_15 , & V_16 ) )
return - V_17 ;
F_11 ( V_18 , & V_16 ) ;
F_5 () ;
return F_12 ( V_13 , V_14 ) ;
}
static T_2 F_13 ( struct V_14 * V_14 , const char * V_19 ,
T_3 V_20 , T_4 * V_21 )
{
if ( V_20 ) {
if ( ! V_22 ) {
T_3 V_23 ;
F_11 ( V_18 , & V_16 ) ;
for ( V_23 = 0 ; V_23 != V_20 ; V_23 ++ ) {
char V_24 ;
if ( F_14 ( V_24 , V_19 + V_23 ) )
return - V_25 ;
if ( V_24 == 'V' )
F_15 ( V_18 , & V_16 ) ;
}
}
F_1 () ;
}
return V_20 ;
}
static int F_16 ( int V_26 )
{
if ( ( V_26 <= 0 ) || ( V_26 > V_27 ) )
return - V_28 ;
V_3 = V_26 ;
return 0 ;
}
static long F_17 ( struct V_14 * V_14 , unsigned int V_29 ,
unsigned long V_30 )
{
int V_31 = - V_32 ;
int time ;
switch ( V_29 ) {
case V_33 :
V_31 = F_18 ( (struct V_34 * ) V_30 , & V_35 ,
sizeof( V_35 ) ) ? - V_25 : 0 ;
break;
case V_36 :
case V_37 :
V_31 = F_19 ( 0 , ( int * ) V_30 ) ;
break;
case V_38 :
F_1 () ;
V_31 = 0 ;
break;
case V_39 :
V_31 = F_14 ( time , ( int * ) V_30 ) ;
if ( V_31 )
break;
if ( F_16 ( time ) ) {
V_31 = - V_28 ;
break;
}
F_1 () ;
case V_40 :
V_31 = F_19 ( V_3 , ( int * ) V_30 ) ;
break;
case V_41 :
if ( F_8 ( & time ) ) {
V_31 = - V_28 ;
break;
}
V_31 = F_19 ( time , ( int * ) V_30 ) ;
break;
}
return V_31 ;
}
static int F_20 ( struct V_13 * V_13 , struct V_14 * V_14 )
{
if ( F_21 ( V_18 , & V_16 ) )
F_7 () ;
else
F_22 ( V_42 L_1
L_2 ) ;
F_11 ( V_15 , & V_16 ) ;
F_11 ( V_18 , & V_16 ) ;
return 0 ;
}
static int T_5 F_23 ( struct V_43 * V_44 )
{
struct V_45 * V_46 = V_44 -> V_47 . V_48 ;
int V_31 ;
if ( V_46 ) {
V_2 = V_46 -> V_49 ;
} else {
F_22 ( V_50 L_3 ) ;
return - V_51 ;
}
if ( V_52 . V_53 )
return - V_17 ;
V_52 . V_53 = & V_44 -> V_47 ;
V_27 = V_54 / V_2 ;
if ( F_16 ( V_3 ) )
V_3 = V_27 ;
V_31 = F_24 ( & V_52 ) ;
if ( V_31 )
return V_31 ;
F_22 ( V_55 L_4 ,
V_3 , V_22 ? L_5 : L_6 ) ;
return 0 ;
}
static int T_6 F_25 ( struct V_43 * V_44 )
{
int V_31 ;
if ( F_21 ( V_15 , & V_16 ) ) {
F_7 () ;
F_11 ( V_15 , & V_16 ) ;
}
V_31 = F_26 ( & V_52 ) ;
if ( ! V_31 )
V_52 . V_53 = NULL ;
return V_31 ;
}
static void F_27 ( struct V_43 * V_44 )
{
if ( F_21 ( V_15 , & V_16 ) )
F_7 () ;
}
