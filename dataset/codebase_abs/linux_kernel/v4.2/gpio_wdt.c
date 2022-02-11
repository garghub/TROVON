static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 , ! V_2 -> V_4 ) ;
if ( V_2 -> V_5 == V_6 )
F_3 ( V_2 -> V_3 ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
V_2 -> V_7 = V_2 -> V_4 ;
F_5 ( V_2 -> V_3 , V_2 -> V_7 ) ;
V_2 -> V_8 = V_9 ;
F_6 ( & V_2 -> V_10 , V_2 -> V_8 + V_2 -> V_11 ) ;
}
static int F_7 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_8 ( V_13 ) ;
F_4 ( V_2 ) ;
V_2 -> V_14 = true ;
return 0 ;
}
static int F_9 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_8 ( V_13 ) ;
V_2 -> V_14 = false ;
if ( ! V_2 -> V_15 ) {
F_6 ( & V_2 -> V_10 , 0 ) ;
F_1 ( V_2 ) ;
}
return 0 ;
}
static int F_10 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_8 ( V_13 ) ;
V_2 -> V_8 = V_9 ;
return 0 ;
}
static int F_11 ( struct V_12 * V_13 , unsigned int V_16 )
{
V_13 -> V_17 = V_16 ;
return F_10 ( V_13 ) ;
}
static void F_12 ( unsigned long V_18 )
{
struct V_12 * V_13 = (struct V_12 * ) V_18 ;
struct V_1 * V_2 = F_8 ( V_13 ) ;
if ( V_2 -> V_14 && F_13 ( V_9 , V_2 -> V_8 +
F_14 ( V_13 -> V_17 * 1000 ) ) ) {
F_15 ( V_13 -> V_19 , L_1 ) ;
return;
}
F_6 ( & V_2 -> V_10 , V_9 + V_2 -> V_11 ) ;
switch ( V_2 -> V_5 ) {
case V_6 :
V_2 -> V_7 = ! V_2 -> V_7 ;
F_2 ( V_2 -> V_3 , V_2 -> V_7 ) ;
break;
case V_20 :
F_2 ( V_2 -> V_3 , ! V_2 -> V_4 ) ;
F_16 ( 1 ) ;
F_2 ( V_2 -> V_3 , V_2 -> V_4 ) ;
break;
}
}
static int F_17 ( struct V_21 * V_22 , unsigned long V_23 ,
void * V_24 )
{
struct V_1 * V_2 = F_18 ( V_22 , struct V_1 ,
V_25 ) ;
F_6 ( & V_2 -> V_10 , 0 ) ;
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
unsigned int V_11 ;
unsigned long V_33 = 0 ;
const char * V_34 ;
int V_35 ;
V_2 = F_20 ( & V_30 -> V_19 , sizeof( * V_2 ) , V_36 ) ;
if ( ! V_2 )
return - V_37 ;
V_2 -> V_3 = F_21 ( V_30 -> V_19 . V_38 , 0 , & V_32 ) ;
if ( ! F_22 ( V_2 -> V_3 ) )
return V_2 -> V_3 ;
V_2 -> V_4 = V_32 & V_39 ;
V_35 = F_23 ( V_30 -> V_19 . V_38 , L_2 , & V_34 ) ;
if ( V_35 )
return V_35 ;
if ( ! strncmp ( V_34 , L_3 , 6 ) ) {
V_2 -> V_5 = V_6 ;
V_33 = V_40 ;
} else if ( ! strncmp ( V_34 , L_4 , 5 ) ) {
V_2 -> V_5 = V_20 ;
V_33 = V_2 -> V_4 ? V_41 : V_42 ;
} else {
return - V_43 ;
}
V_35 = F_24 ( & V_30 -> V_19 , V_2 -> V_3 , V_33 ,
F_25 ( & V_30 -> V_19 ) ) ;
if ( V_35 )
return V_35 ;
V_35 = F_26 ( V_30 -> V_19 . V_38 ,
L_5 , & V_11 ) ;
if ( V_35 )
return V_35 ;
if ( V_11 < 2 || V_11 > 65535 )
return - V_43 ;
V_2 -> V_11 = F_14 ( V_11 / 2 ) ;
V_2 -> V_15 = F_27 ( V_30 -> V_19 . V_38 ,
L_6 ) ;
F_28 ( & V_2 -> V_13 , V_2 ) ;
V_2 -> V_13 . V_44 = & V_45 ;
V_2 -> V_13 . V_46 = & V_47 ;
V_2 -> V_13 . V_48 = V_49 ;
V_2 -> V_13 . V_50 = V_51 ;
if ( F_29 ( & V_2 -> V_13 , 0 , & V_30 -> V_19 ) < 0 )
V_2 -> V_13 . V_17 = V_52 ;
F_30 ( & V_2 -> V_10 , F_12 , ( unsigned long ) & V_2 -> V_13 ) ;
V_35 = F_31 ( & V_2 -> V_13 ) ;
if ( V_35 )
return V_35 ;
V_2 -> V_25 . V_53 = F_17 ;
V_35 = F_32 ( & V_2 -> V_25 ) ;
if ( V_35 )
goto V_54;
if ( V_2 -> V_15 )
F_4 ( V_2 ) ;
return 0 ;
V_54:
F_33 ( & V_2 -> V_13 ) ;
return V_35 ;
}
static int F_34 ( struct V_29 * V_30 )
{
struct V_1 * V_2 = F_35 ( V_30 ) ;
F_36 ( & V_2 -> V_10 ) ;
F_37 ( & V_2 -> V_25 ) ;
F_33 ( & V_2 -> V_13 ) ;
return 0 ;
}
static int T_1 F_38 ( void )
{
return F_39 ( & V_55 ) ;
}
