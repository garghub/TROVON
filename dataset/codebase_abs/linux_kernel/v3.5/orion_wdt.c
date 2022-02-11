static void F_1 ( void )
{
F_2 ( & V_1 ) ;
F_3 ( V_2 * V_3 , V_4 + V_5 ) ;
F_4 ( & V_1 ) ;
}
static void F_5 ( void )
{
T_1 V_6 ;
F_2 ( & V_1 ) ;
F_3 ( V_2 * V_3 , V_4 + V_5 ) ;
V_6 = F_6 ( V_7 ) ;
V_6 &= ~ V_8 ;
F_3 ( V_6 , V_7 ) ;
V_6 = F_6 ( V_4 + V_9 ) ;
V_6 |= V_10 ;
F_3 ( V_6 , V_4 + V_9 ) ;
V_6 = F_6 ( V_11 ) ;
V_6 |= V_12 ;
F_3 ( V_6 , V_11 ) ;
F_4 ( & V_1 ) ;
}
static void F_7 ( void )
{
T_1 V_6 ;
F_2 ( & V_1 ) ;
V_6 = F_6 ( V_11 ) ;
V_6 &= ~ V_12 ;
F_3 ( V_6 , V_11 ) ;
V_6 = F_6 ( V_4 + V_9 ) ;
V_6 &= ~ V_10 ;
F_3 ( V_6 , V_4 + V_9 ) ;
F_4 ( & V_1 ) ;
}
static int F_8 ( int * V_13 )
{
F_2 ( & V_1 ) ;
* V_13 = F_6 ( V_4 + V_5 ) / V_2 ;
F_4 ( & V_1 ) ;
return 0 ;
}
static int F_9 ( struct V_14 * V_14 , struct V_15 * V_15 )
{
if ( F_10 ( V_16 , & V_17 ) )
return - V_18 ;
F_11 ( V_19 , & V_17 ) ;
F_5 () ;
return F_12 ( V_14 , V_15 ) ;
}
static T_2 F_13 ( struct V_15 * V_15 , const char * V_20 ,
T_3 V_21 , T_4 * V_22 )
{
if ( V_21 ) {
if ( ! V_23 ) {
T_3 V_24 ;
F_11 ( V_19 , & V_17 ) ;
for ( V_24 = 0 ; V_24 != V_21 ; V_24 ++ ) {
char V_25 ;
if ( F_14 ( V_25 , V_20 + V_24 ) )
return - V_26 ;
if ( V_25 == 'V' )
F_15 ( V_19 , & V_17 ) ;
}
}
F_1 () ;
}
return V_21 ;
}
static int F_16 ( int V_27 )
{
if ( ( V_27 <= 0 ) || ( V_27 > V_28 ) )
return - V_29 ;
V_3 = V_27 ;
return 0 ;
}
static long F_17 ( struct V_15 * V_15 , unsigned int V_30 ,
unsigned long V_31 )
{
int V_32 = - V_33 ;
int time ;
switch ( V_30 ) {
case V_34 :
V_32 = F_18 ( (struct V_35 * ) V_31 , & V_36 ,
sizeof( V_36 ) ) ? - V_26 : 0 ;
break;
case V_37 :
case V_38 :
V_32 = F_19 ( 0 , ( int * ) V_31 ) ;
break;
case V_39 :
F_1 () ;
V_32 = 0 ;
break;
case V_40 :
V_32 = F_14 ( time , ( int * ) V_31 ) ;
if ( V_32 )
break;
if ( F_16 ( time ) ) {
V_32 = - V_29 ;
break;
}
F_1 () ;
case V_41 :
V_32 = F_19 ( V_3 , ( int * ) V_31 ) ;
break;
case V_42 :
if ( F_8 ( & time ) ) {
V_32 = - V_29 ;
break;
}
V_32 = F_19 ( time , ( int * ) V_31 ) ;
break;
}
return V_32 ;
}
static int F_20 ( struct V_14 * V_14 , struct V_15 * V_15 )
{
if ( F_21 ( V_19 , & V_17 ) )
F_7 () ;
else
F_22 ( L_1 ) ;
F_11 ( V_16 , & V_17 ) ;
F_11 ( V_19 , & V_17 ) ;
return 0 ;
}
static int T_5 F_23 ( struct V_43 * V_44 )
{
struct V_45 * V_46 ;
int V_32 ;
V_47 = F_24 ( & V_44 -> V_48 , NULL ) ;
if ( F_25 ( V_47 ) ) {
F_26 ( V_49 L_2 ) ;
return - V_50 ;
}
F_27 ( V_47 ) ;
V_2 = F_28 ( V_47 ) ;
V_46 = F_29 ( V_44 , V_51 , 0 ) ;
V_4 = F_30 ( V_46 -> V_52 , F_31 ( V_46 ) ) ;
if ( V_53 . V_54 )
return - V_18 ;
V_53 . V_54 = & V_44 -> V_48 ;
V_28 = V_55 / V_2 ;
if ( F_16 ( V_3 ) )
V_3 = V_28 ;
V_32 = F_32 ( & V_53 ) ;
if ( V_32 )
return V_32 ;
F_33 ( L_3 ,
V_3 , V_23 ? L_4 : L_5 ) ;
return 0 ;
}
static int T_6 F_34 ( struct V_43 * V_44 )
{
int V_32 ;
if ( F_21 ( V_16 , & V_17 ) ) {
F_7 () ;
F_11 ( V_16 , & V_17 ) ;
}
V_32 = F_35 ( & V_53 ) ;
if ( ! V_32 )
V_53 . V_54 = NULL ;
F_36 ( V_47 ) ;
F_37 ( V_47 ) ;
return V_32 ;
}
static void F_38 ( struct V_43 * V_44 )
{
if ( F_21 ( V_16 , & V_17 ) )
F_7 () ;
}
