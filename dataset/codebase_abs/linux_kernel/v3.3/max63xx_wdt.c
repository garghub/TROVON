static struct V_1 *
F_1 ( struct V_1 * V_2 , int V_3 )
{
while ( V_2 -> V_4 ) {
if ( V_3 <= V_2 -> V_4 ) {
if ( V_5 && V_2 -> V_6 == 0 )
return V_2 ;
if ( ! V_5 )
return V_2 ;
}
V_2 ++ ;
}
return NULL ;
}
static void F_2 ( void )
{
T_1 V_7 ;
F_3 ( & V_8 ) ;
V_7 = F_4 ( V_9 ) ;
F_5 ( V_7 | V_10 , V_9 ) ;
F_5 ( V_7 & ~ V_10 , V_9 ) ;
F_6 ( & V_8 ) ;
}
static void F_7 ( struct V_1 * V_11 )
{
T_1 V_7 ;
if ( F_8 ( V_12 , & V_13 ) )
return;
F_3 ( & V_8 ) ;
V_7 = F_4 ( V_9 ) ;
V_7 &= ~ V_14 ;
V_7 |= V_11 -> V_15 ;
F_5 ( V_7 , V_9 ) ;
F_6 ( & V_8 ) ;
if ( V_11 -> V_6 == 0 )
F_2 () ;
}
static void F_9 ( void )
{
T_1 V_7 ;
F_3 ( & V_8 ) ;
V_7 = F_4 ( V_9 ) ;
V_7 &= ~ V_14 ;
V_7 |= 3 ;
F_5 ( V_7 , V_9 ) ;
F_6 ( & V_8 ) ;
F_10 ( V_12 , & V_13 ) ;
}
static int F_11 ( struct V_16 * V_16 , struct V_17 * V_17 )
{
if ( F_8 ( V_18 , & V_13 ) )
return - V_19 ;
F_7 ( V_20 ) ;
F_10 ( V_21 , & V_13 ) ;
return F_12 ( V_16 , V_17 ) ;
}
static T_2 F_13 ( struct V_17 * V_17 , const char * V_22 ,
T_3 V_23 , T_4 * V_24 )
{
if ( V_23 ) {
if ( ! V_25 ) {
T_3 V_26 ;
F_10 ( V_21 , & V_13 ) ;
for ( V_26 = 0 ; V_26 != V_23 ; V_26 ++ ) {
char V_27 ;
if ( F_14 ( V_27 , V_22 + V_26 ) )
return - V_28 ;
if ( V_27 == 'V' )
F_15 ( V_21 , & V_13 ) ;
}
}
F_2 () ;
}
return V_23 ;
}
static long F_16 ( struct V_17 * V_17 , unsigned int V_29 ,
unsigned long V_30 )
{
int V_31 = - V_32 ;
switch ( V_29 ) {
case V_33 :
V_31 = F_17 ( (struct V_34 * ) V_30 , & V_35 ,
sizeof( V_35 ) ) ? - V_28 : 0 ;
break;
case V_36 :
case V_37 :
V_31 = F_18 ( 0 , ( int * ) V_30 ) ;
break;
case V_38 :
F_2 () ;
V_31 = 0 ;
break;
case V_39 :
V_31 = F_18 ( V_40 , ( int * ) V_30 ) ;
break;
}
return V_31 ;
}
static int F_19 ( struct V_16 * V_16 , struct V_17 * V_17 )
{
if ( F_20 ( V_21 , & V_13 ) )
F_9 () ;
else
F_21 ( & V_41 -> V_42 ,
L_1 ) ;
F_10 ( V_18 , & V_13 ) ;
F_10 ( V_21 , & V_13 ) ;
return 0 ;
}
static int T_5 F_22 ( struct V_43 * V_44 )
{
int V_31 = 0 ;
int V_45 ;
struct V_46 * V_42 = & V_44 -> V_42 ;
struct V_1 * V_2 ;
V_2 = (struct V_1 * ) V_44 -> V_47 -> V_48 ;
if ( V_40 < 1 || V_40 > V_49 )
V_40 = V_50 ;
F_23 ( V_42 , L_2 , V_40 ) ;
V_20 = F_1 ( V_2 , V_40 ) ;
if ( ! V_20 ) {
F_24 ( V_42 , L_3 ) ;
return - V_51 ;
}
F_23 ( V_42 , L_4 ,
V_20 -> V_4 , V_20 -> V_6 ) ;
V_40 = V_20 -> V_4 ;
V_41 = V_44 ;
V_52 = F_25 ( V_44 , V_53 , 0 ) ;
if ( V_52 == NULL ) {
F_24 ( V_42 , L_5 ) ;
return - V_54 ;
}
V_45 = F_26 ( V_52 ) ;
if ( ! F_27 ( V_52 -> V_55 , V_45 , V_44 -> V_56 ) ) {
F_24 ( V_42 , L_6 ) ;
return - V_54 ;
}
V_9 = F_28 ( V_52 -> V_55 , V_45 ) ;
if ( ! V_9 ) {
F_24 ( V_42 , L_7 ) ;
V_31 = - V_57 ;
goto V_58;
}
V_31 = F_29 ( & V_59 ) ;
if ( V_31 < 0 ) {
F_24 ( V_42 , L_8 ) ;
goto V_60;
}
return 0 ;
V_60:
F_30 ( V_9 ) ;
V_58:
F_31 ( V_52 -> V_55 , V_45 ) ;
V_52 = NULL ;
return V_31 ;
}
static int T_6 F_32 ( struct V_43 * V_44 )
{
F_33 ( & V_59 ) ;
if ( V_52 ) {
F_31 ( V_52 -> V_55 , F_26 ( V_52 ) ) ;
V_52 = NULL ;
}
if ( V_9 )
F_30 ( V_9 ) ;
return 0 ;
}
