static void F_1 ( unsigned int V_1 )
{
T_1 V_2 , V_3 ;
V_3 = F_2 ( V_4 -> V_5 ) ;
V_2 = F_3 ( V_3 , 2 ) * V_1 - 1 ;
V_2 = ( V_2 > V_6 ) ? V_6 : V_2 ;
V_2 = ( V_2 < V_7 ) ? V_7 : V_2 ;
F_4 ( & V_4 -> V_8 ) ;
V_4 -> V_9 = V_2 ;
V_4 -> V_1 = F_3 ( ( V_2 + 1 ) * 2 + ( V_3 / 2 ) , V_3 ) ;
F_5 ( & V_4 -> V_8 ) ;
}
static T_2 F_6 ( void )
{
T_1 V_2 , V_3 ;
V_3 = F_2 ( V_4 -> V_5 ) ;
F_4 ( & V_4 -> V_8 ) ;
V_2 = F_7 ( V_4 -> V_10 + V_11 ) ;
if ( ! ( F_7 ( V_4 -> V_10 + V_12 ) & V_13 ) )
V_2 += V_4 -> V_9 + 1 ;
F_5 ( & V_4 -> V_8 ) ;
return F_3 ( V_2 , V_3 ) ;
}
static void F_8 ( void )
{
F_4 ( & V_4 -> V_8 ) ;
F_9 ( V_14 , V_4 -> V_10 + V_15 ) ;
F_9 ( V_4 -> V_9 , V_4 -> V_10 + V_16 ) ;
F_9 ( V_13 , V_4 -> V_10 + V_17 ) ;
F_9 ( V_18 | V_19 , V_4 -> V_10 + V_20 ) ;
F_9 ( V_21 , V_4 -> V_10 + V_15 ) ;
F_7 ( V_4 -> V_10 + V_15 ) ;
F_5 ( & V_4 -> V_8 ) ;
}
static void F_10 ( void )
{
F_4 ( & V_4 -> V_8 ) ;
F_9 ( V_14 , V_4 -> V_10 + V_15 ) ;
F_9 ( 0 , V_4 -> V_10 + V_20 ) ;
F_9 ( V_21 , V_4 -> V_10 + V_15 ) ;
F_7 ( V_4 -> V_10 + V_15 ) ;
F_5 ( & V_4 -> V_8 ) ;
}
static T_3 F_11 ( struct V_22 * V_22 , const char * V_23 ,
T_4 V_24 , T_5 * V_25 )
{
if ( V_24 ) {
if ( ! V_26 ) {
T_4 V_27 ;
F_12 ( V_28 , & V_4 -> V_29 ) ;
for ( V_27 = 0 ; V_27 != V_24 ; V_27 ++ ) {
char V_30 ;
if ( F_13 ( V_30 , V_23 + V_27 ) )
return - V_31 ;
if ( V_30 == 'V' ) {
F_14 ( V_28 ,
& V_4 -> V_29 ) ;
break;
}
}
}
F_8 () ;
}
return V_24 ;
}
static long F_15 ( struct V_22 * V_22 , unsigned int V_32 ,
unsigned long V_33 )
{
int V_34 = - V_35 ;
unsigned int V_1 ;
switch ( V_32 ) {
case V_36 :
V_34 = F_16 ( (struct V_37 * ) V_33 , & V_38 ,
sizeof( V_38 ) ) ? - V_31 : 0 ;
break;
case V_39 :
V_34 = F_17 ( 0 , ( int * ) V_33 ) ;
break;
case V_40 :
F_8 () ;
V_34 = 0 ;
break;
case V_41 :
V_34 = F_13 ( V_1 , ( unsigned int * ) V_33 ) ;
if ( V_34 )
break;
F_1 ( V_1 ) ;
F_8 () ;
case V_42 :
V_34 = F_17 ( V_4 -> V_1 , ( unsigned int * ) V_33 ) ;
break;
case V_43 :
V_34 = F_17 ( F_6 () , ( unsigned int * ) V_33 ) ;
break;
}
return V_34 ;
}
static int F_18 ( struct V_44 * V_44 , struct V_22 * V_22 )
{
int V_34 = 0 ;
if ( F_19 ( V_45 , & V_4 -> V_29 ) )
return - V_46 ;
V_34 = F_20 ( V_4 -> V_5 ) ;
if ( V_34 ) {
F_21 ( & V_4 -> V_47 -> V_48 , L_1 ) ;
goto V_49;
}
F_8 () ;
F_12 ( V_28 , & V_4 -> V_29 ) ;
return F_22 ( V_44 , V_22 ) ;
V_49:
F_12 ( V_45 , & V_4 -> V_29 ) ;
return V_34 ;
}
static int F_23 ( struct V_44 * V_44 , struct V_22 * V_22 )
{
if ( ! F_24 ( V_28 , & V_4 -> V_29 ) ) {
F_12 ( V_45 , & V_4 -> V_29 ) ;
F_25 ( & V_4 -> V_47 -> V_48 , L_2 ) ;
return 0 ;
}
F_10 () ;
F_26 ( V_4 -> V_5 ) ;
F_12 ( V_45 , & V_4 -> V_29 ) ;
return 0 ;
}
static int T_6
F_27 ( struct V_50 * V_47 , const struct V_51 * V_52 )
{
int V_34 = 0 ;
if ( ! F_28 ( V_47 -> V_53 . V_54 , F_29 ( & V_47 -> V_53 ) ,
L_3 ) ) {
F_25 ( & V_47 -> V_48 , L_4 ) ;
V_34 = - V_55 ;
goto V_49;
}
V_4 = F_30 ( sizeof( * V_4 ) , V_56 ) ;
if ( ! V_4 ) {
F_25 ( & V_47 -> V_48 , L_5 ) ;
V_34 = - V_57 ;
goto V_58;
}
V_4 -> V_5 = F_31 ( & V_47 -> V_48 , NULL ) ;
if ( F_32 ( V_4 -> V_5 ) ) {
F_25 ( & V_47 -> V_48 , L_6 ) ;
V_34 = F_33 ( V_4 -> V_5 ) ;
goto V_59;
}
V_4 -> V_10 = F_34 ( V_47 -> V_53 . V_54 , F_29 ( & V_47 -> V_53 ) ) ;
if ( ! V_4 -> V_10 ) {
V_34 = - V_57 ;
F_25 ( & V_47 -> V_48 , L_7 ) ;
goto V_60;
}
V_4 -> V_47 = V_47 ;
F_35 ( & V_4 -> V_8 ) ;
F_1 ( V_61 ) ;
V_34 = F_36 ( & V_62 ) ;
if ( V_34 < 0 ) {
F_25 ( & V_47 -> V_48 , L_8 ) ;
goto V_63;
}
F_37 ( & V_47 -> V_48 , L_9 ) ;
return 0 ;
V_63:
F_38 ( V_4 -> V_10 ) ;
V_60:
F_39 ( V_4 -> V_5 ) ;
V_59:
F_40 ( V_4 ) ;
V_4 = NULL ;
V_58:
F_41 ( V_47 -> V_53 . V_54 , F_29 ( & V_47 -> V_53 ) ) ;
V_49:
F_21 ( & V_47 -> V_48 , L_10 ) ;
return V_34 ;
}
static int T_7 F_42 ( struct V_50 * V_47 )
{
F_43 ( & V_62 ) ;
F_38 ( V_4 -> V_10 ) ;
F_39 ( V_4 -> V_5 ) ;
F_40 ( V_4 ) ;
F_41 ( V_47 -> V_53 . V_54 , F_29 ( & V_47 -> V_53 ) ) ;
return 0 ;
}
static int T_8 F_44 ( void )
{
return F_45 ( & V_64 ) ;
}
static void T_9 F_46 ( void )
{
F_47 ( & V_64 ) ;
}
