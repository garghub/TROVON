static void
F_1 ( void )
{
unsigned long int V_1 = V_2 *
( V_3 / V_4 ) + 0x1000 ;
if ( V_1 > V_5 )
V_1 = V_5 ;
F_2 ( V_6 , V_7 + V_8 ) ;
F_2 ( V_9 | V_10 | V_11 |
V_12 | V_1 , V_7 + V_8 ) ;
}
static void
F_3 ( void )
{
F_2 ( V_6 , V_7 + V_8 ) ;
F_2 ( V_12 , V_7 + V_8 ) ;
}
static T_1
F_4 ( struct V_13 * V_13 , const char T_2 * V_14 ,
T_3 V_15 , T_4 * V_16 )
{
if ( V_15 ) {
if ( ! V_17 ) {
T_3 V_18 ;
V_19 = 0 ;
for ( V_18 = 0 ; V_18 != V_15 ; V_18 ++ ) {
char V_20 ;
if ( F_5 ( V_20 , V_14 + V_18 ) )
return - V_21 ;
if ( V_20 == 'V' )
V_19 = 1 ;
else
V_19 = 0 ;
}
}
F_1 () ;
}
return V_15 ;
}
static long
F_6 ( struct V_13 * V_13 ,
unsigned int V_22 , unsigned long V_23 )
{
int V_24 = - V_25 ;
switch ( V_22 ) {
case V_26 :
V_24 = F_7 ( (struct V_27 T_2 * ) V_23 , & V_28 ,
sizeof( V_28 ) ) ? - V_21 : 0 ;
break;
case V_29 :
V_24 = F_8 ( V_30 , ( int T_2 * ) V_23 ) ;
break;
case V_31 :
V_24 = F_8 ( 0 , ( int T_2 * ) V_23 ) ;
break;
case V_32 :
V_24 = F_5 ( V_2 , ( int T_2 * ) V_23 ) ;
if ( ! V_24 )
F_1 () ;
case V_33 :
V_24 = F_8 ( V_2 , ( int T_2 * ) V_23 ) ;
break;
case V_34 :
F_1 () ;
V_24 = 0 ;
break;
}
return V_24 ;
}
static int
F_9 ( struct V_35 * V_35 , struct V_13 * V_13 )
{
if ( F_10 ( 0 , & V_36 ) )
return - V_37 ;
V_36 = 1 ;
F_1 () ;
return F_11 ( V_35 , V_13 ) ;
}
static int
F_12 ( struct V_35 * V_35 , struct V_13 * V_13 )
{
if ( V_19 )
F_3 () ;
else
F_13 ( L_1 ) ;
V_19 = 0 ;
F_14 ( 0 , & V_36 ) ;
return 0 ;
}
static int
F_15 ( struct V_38 * V_39 )
{
struct V_40 * V_41 = F_16 ( V_39 , V_42 , 0 ) ;
struct V_43 * V_43 ;
if ( ! V_41 ) {
F_17 ( & V_39 -> V_44 , L_2 ) ;
return - V_45 ;
}
V_7 = F_18 ( & V_39 -> V_44 , V_41 ) ;
if ( ! V_7 ) {
F_17 ( & V_39 -> V_44 , L_3 ) ;
return - V_46 ;
}
V_43 = F_19 () ;
if ( F_20 ( V_43 ) ) {
F_17 ( & V_39 -> V_44 , L_4 ) ;
return - V_45 ;
}
V_3 = F_21 ( V_43 ) ;
F_22 ( V_43 ) ;
if ( F_23 () == V_47 )
V_30 = V_48 ;
F_24 ( & V_39 -> V_44 , L_5 ) ;
return F_25 ( & V_49 ) ;
}
static int
F_26 ( struct V_38 * V_39 )
{
F_27 ( & V_49 ) ;
return 0 ;
}
