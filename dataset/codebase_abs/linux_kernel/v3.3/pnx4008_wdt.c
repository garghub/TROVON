static void F_1 ( void )
{
F_2 ( & V_1 ) ;
F_3 ( V_2 , F_4 ( V_3 ) ) ;
while ( F_5 ( F_6 ( V_3 ) ) )
F_7 () ;
F_3 ( V_4 | V_5 | V_6 ,
F_8 ( V_3 ) ) ;
F_3 ( V_7 , F_9 ( V_3 ) ) ;
F_3 ( V_8 , F_10 ( V_3 ) ) ;
F_3 ( 0xFFFF , F_11 ( V_3 ) ) ;
F_3 ( V_9 * V_10 , F_12 ( V_3 ) ) ;
F_3 ( V_11 | V_12 , F_4 ( V_3 ) ) ;
F_13 ( & V_1 ) ;
}
static void F_14 ( void )
{
F_2 ( & V_1 ) ;
F_3 ( 0 , F_4 ( V_3 ) ) ;
F_13 ( & V_1 ) ;
}
static int F_15 ( struct V_13 * V_13 , struct V_14 * V_14 )
{
int V_15 ;
if ( F_16 ( V_16 , & V_17 ) )
return - V_18 ;
F_17 ( V_19 , & V_17 ) ;
V_15 = F_18 ( V_20 ) ;
if ( V_15 ) {
F_17 ( V_16 , & V_17 ) ;
return V_15 ;
}
F_1 () ;
return F_19 ( V_13 , V_14 ) ;
}
static T_1 F_20 ( struct V_14 * V_14 , const char * V_21 ,
T_2 V_22 , T_3 * V_23 )
{
if ( V_22 ) {
if ( ! V_24 ) {
T_2 V_25 ;
F_17 ( V_19 , & V_17 ) ;
for ( V_25 = 0 ; V_25 != V_22 ; V_25 ++ ) {
char V_26 ;
if ( F_21 ( V_26 , V_21 + V_25 ) )
return - V_27 ;
if ( V_26 == 'V' )
F_22 ( V_19 , & V_17 ) ;
}
}
F_1 () ;
}
return V_22 ;
}
static long F_23 ( struct V_14 * V_14 , unsigned int V_28 ,
unsigned long V_29 )
{
int V_15 = - V_30 ;
int time ;
switch ( V_28 ) {
case V_31 :
V_15 = F_24 ( (struct V_32 * ) V_29 , & V_33 ,
sizeof( V_33 ) ) ? - V_27 : 0 ;
break;
case V_34 :
V_15 = F_25 ( 0 , ( int * ) V_29 ) ;
break;
case V_35 :
V_15 = F_25 ( V_36 , ( int * ) V_29 ) ;
break;
case V_37 :
F_1 () ;
V_15 = 0 ;
break;
case V_38 :
V_15 = F_21 ( time , ( int * ) V_29 ) ;
if ( V_15 )
break;
if ( time <= 0 || time > V_39 ) {
V_15 = - V_40 ;
break;
}
V_9 = time ;
F_1 () ;
case V_41 :
V_15 = F_25 ( V_9 , ( int * ) V_29 ) ;
break;
}
return V_15 ;
}
static int F_26 ( struct V_13 * V_13 , struct V_14 * V_14 )
{
if ( ! F_27 ( V_19 , & V_17 ) )
F_28 ( V_42 L_1 ) ;
F_14 () ;
F_29 ( V_20 ) ;
F_17 ( V_16 , & V_17 ) ;
F_17 ( V_19 , & V_17 ) ;
return 0 ;
}
static int T_4 F_30 ( struct V_43 * V_44 )
{
int V_15 = 0 , V_45 ;
if ( V_9 < 1 || V_9 > V_39 )
V_9 = V_46 ;
F_28 (KERN_INFO MODULE_NAME
L_2 , heartbeat) ;
V_47 = F_31 ( V_44 , V_48 , 0 ) ;
if ( V_47 == NULL ) {
F_28 (KERN_INFO MODULE_NAME
L_3 ) ;
return - V_49 ;
}
V_45 = F_32 ( V_47 ) ;
if ( ! F_33 ( V_47 -> V_50 , V_45 , V_44 -> V_51 ) ) {
F_28 (KERN_INFO MODULE_NAME L_4 ) ;
return - V_49 ;
}
V_3 = ( void V_52 * ) F_34 ( V_47 -> V_50 ) ;
V_20 = F_35 ( & V_44 -> V_53 , NULL ) ;
if ( F_36 ( V_20 ) ) {
V_15 = F_37 ( V_20 ) ;
F_38 ( V_47 -> V_50 , V_45 ) ;
V_47 = NULL ;
goto V_54;
}
V_15 = F_18 ( V_20 ) ;
if ( V_15 ) {
F_38 ( V_47 -> V_50 , V_45 ) ;
V_47 = NULL ;
F_39 ( V_20 ) ;
goto V_54;
}
V_15 = F_40 ( & V_55 ) ;
if ( V_15 < 0 ) {
F_28 (KERN_ERR MODULE_NAME L_5 ) ;
F_38 ( V_47 -> V_50 , V_45 ) ;
V_47 = NULL ;
F_29 ( V_20 ) ;
F_39 ( V_20 ) ;
} else {
V_36 = ( F_5 ( F_41 ( V_3 ) ) & V_56 ) ?
V_57 : 0 ;
F_14 () ;
F_29 ( V_20 ) ;
F_22 ( V_58 , & V_17 ) ;
}
V_54:
return V_15 ;
}
static int T_5 F_42 ( struct V_43 * V_44 )
{
F_43 ( & V_55 ) ;
F_29 ( V_20 ) ;
F_39 ( V_20 ) ;
if ( V_47 ) {
F_38 ( V_47 -> V_50 , F_32 ( V_47 ) ) ;
V_47 = NULL ;
}
return 0 ;
}
