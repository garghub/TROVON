static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 , ! V_2 -> V_4 ) ;
if ( V_2 -> V_5 == V_6 )
F_3 ( V_2 -> V_3 ) ;
}
static void F_4 ( unsigned long V_7 )
{
struct V_8 * V_9 = (struct V_8 * ) V_7 ;
struct V_1 * V_2 = F_5 ( V_9 ) ;
if ( V_2 -> V_10 && F_6 ( V_11 , V_2 -> V_12 +
F_7 ( V_9 -> V_13 * 1000 ) ) ) {
F_8 ( V_9 -> V_14 , L_1 ) ;
return;
}
F_9 ( & V_2 -> V_15 , V_11 + V_2 -> V_16 ) ;
switch ( V_2 -> V_5 ) {
case V_6 :
V_2 -> V_17 = ! V_2 -> V_17 ;
F_2 ( V_2 -> V_3 , V_2 -> V_17 ) ;
break;
case V_18 :
F_2 ( V_2 -> V_3 , ! V_2 -> V_4 ) ;
F_10 ( 1 ) ;
F_2 ( V_2 -> V_3 , V_2 -> V_4 ) ;
break;
}
}
static void F_11 ( struct V_1 * V_2 )
{
V_2 -> V_17 = V_2 -> V_4 ;
F_12 ( V_2 -> V_3 , V_2 -> V_17 ) ;
V_2 -> V_12 = V_11 ;
F_4 ( ( unsigned long ) & V_2 -> V_9 ) ;
}
static int F_13 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_5 ( V_9 ) ;
F_11 ( V_2 ) ;
V_2 -> V_10 = true ;
return 0 ;
}
static int F_14 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_5 ( V_9 ) ;
V_2 -> V_10 = false ;
if ( ! V_2 -> V_19 ) {
F_9 ( & V_2 -> V_15 , 0 ) ;
F_1 ( V_2 ) ;
}
return 0 ;
}
static int F_15 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_5 ( V_9 ) ;
V_2 -> V_12 = V_11 ;
return 0 ;
}
static int F_16 ( struct V_8 * V_9 , unsigned int V_20 )
{
V_9 -> V_13 = V_20 ;
return F_15 ( V_9 ) ;
}
static int F_17 ( struct V_21 * V_22 , unsigned long V_23 ,
void * V_24 )
{
struct V_1 * V_2 = F_18 ( V_22 , struct V_1 ,
V_25 ) ;
F_9 ( & V_2 -> V_15 , 0 ) ;
switch ( V_23 ) {
case V_26 :
case V_27 :
F_1 ( V_2 ) ;
break;
default:
break;
}
return V_28 ;
}
static int F_19 ( struct V_29 * V_30 )
{
struct V_1 * V_2 ;
enum V_31 V_32 ;
unsigned int V_16 ;
unsigned long V_33 = 0 ;
const char * V_34 ;
int V_35 ;
V_2 = F_20 ( & V_30 -> V_14 , sizeof( * V_2 ) , V_36 ) ;
if ( ! V_2 )
return - V_37 ;
V_2 -> V_3 = F_21 ( V_30 -> V_14 . V_38 , 0 , & V_32 ) ;
if ( ! F_22 ( V_2 -> V_3 ) )
return V_2 -> V_3 ;
V_2 -> V_4 = V_32 & V_39 ;
V_35 = F_23 ( V_30 -> V_14 . V_38 , L_2 , & V_34 ) ;
if ( V_35 )
return V_35 ;
if ( ! strcmp ( V_34 , L_3 ) ) {
V_2 -> V_5 = V_6 ;
V_33 = V_40 ;
} else if ( ! strcmp ( V_34 , L_4 ) ) {
V_2 -> V_5 = V_18 ;
V_33 = V_2 -> V_4 ? V_41 : V_42 ;
} else {
return - V_43 ;
}
V_35 = F_24 ( & V_30 -> V_14 , V_2 -> V_3 , V_33 ,
F_25 ( & V_30 -> V_14 ) ) ;
if ( V_35 )
return V_35 ;
V_35 = F_26 ( V_30 -> V_14 . V_38 ,
L_5 , & V_16 ) ;
if ( V_35 )
return V_35 ;
if ( V_16 < 2 || V_16 > 65535 )
return - V_43 ;
V_2 -> V_16 = F_7 ( V_16 / 2 ) ;
V_2 -> V_19 = F_27 ( V_30 -> V_14 . V_38 ,
L_6 ) ;
F_28 ( & V_2 -> V_9 , V_2 ) ;
V_2 -> V_9 . V_44 = & V_45 ;
V_2 -> V_9 . V_46 = & V_47 ;
V_2 -> V_9 . V_48 = V_49 ;
V_2 -> V_9 . V_50 = V_51 ;
V_2 -> V_9 . V_52 = & V_30 -> V_14 ;
if ( F_29 ( & V_2 -> V_9 , 0 , & V_30 -> V_14 ) < 0 )
V_2 -> V_9 . V_13 = V_53 ;
F_30 ( & V_2 -> V_15 , F_4 , ( unsigned long ) & V_2 -> V_9 ) ;
V_35 = F_31 ( & V_2 -> V_9 ) ;
if ( V_35 )
return V_35 ;
V_2 -> V_25 . V_54 = F_17 ;
V_35 = F_32 ( & V_2 -> V_25 ) ;
if ( V_35 )
goto V_55;
if ( V_2 -> V_19 )
F_11 ( V_2 ) ;
return 0 ;
V_55:
F_33 ( & V_2 -> V_9 ) ;
return V_35 ;
}
static int F_34 ( struct V_29 * V_30 )
{
struct V_1 * V_2 = F_35 ( V_30 ) ;
F_36 ( & V_2 -> V_15 ) ;
F_37 ( & V_2 -> V_25 ) ;
F_33 ( & V_2 -> V_9 ) ;
return 0 ;
}
static int T_1 F_38 ( void )
{
return F_39 ( & V_56 ) ;
}
