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
F_8 ( V_9 -> V_14 ,
L_1 ) ;
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
static int F_17 ( struct V_21 * V_22 )
{
struct V_1 * V_2 ;
enum V_23 V_24 ;
unsigned int V_16 ;
unsigned long V_25 = 0 ;
const char * V_26 ;
int V_27 ;
V_2 = F_18 ( & V_22 -> V_28 , sizeof( * V_2 ) , V_29 ) ;
if ( ! V_2 )
return - V_30 ;
F_19 ( V_22 , V_2 ) ;
V_2 -> V_3 = F_20 ( V_22 -> V_28 . V_31 , 0 , & V_24 ) ;
if ( ! F_21 ( V_2 -> V_3 ) )
return V_2 -> V_3 ;
V_2 -> V_4 = V_24 & V_32 ;
V_27 = F_22 ( V_22 -> V_28 . V_31 , L_2 , & V_26 ) ;
if ( V_27 )
return V_27 ;
if ( ! strcmp ( V_26 , L_3 ) ) {
V_2 -> V_5 = V_6 ;
V_25 = V_33 ;
} else if ( ! strcmp ( V_26 , L_4 ) ) {
V_2 -> V_5 = V_18 ;
V_25 = V_2 -> V_4 ? V_34 : V_35 ;
} else {
return - V_36 ;
}
V_27 = F_23 ( & V_22 -> V_28 , V_2 -> V_3 , V_25 ,
F_24 ( & V_22 -> V_28 ) ) ;
if ( V_27 )
return V_27 ;
V_27 = F_25 ( V_22 -> V_28 . V_31 ,
L_5 , & V_16 ) ;
if ( V_27 )
return V_27 ;
if ( V_16 < 2 || V_16 > 65535 )
return - V_36 ;
V_2 -> V_16 = F_7 ( V_16 / 2 ) ;
V_2 -> V_19 = F_26 ( V_22 -> V_28 . V_31 ,
L_6 ) ;
F_27 ( & V_2 -> V_9 , V_2 ) ;
V_2 -> V_9 . V_37 = & V_38 ;
V_2 -> V_9 . V_39 = & V_40 ;
V_2 -> V_9 . V_41 = V_42 ;
V_2 -> V_9 . V_43 = V_44 ;
V_2 -> V_9 . V_14 = & V_22 -> V_28 ;
if ( F_28 ( & V_2 -> V_9 , 0 , & V_22 -> V_28 ) < 0 )
V_2 -> V_9 . V_13 = V_45 ;
F_29 ( & V_2 -> V_15 , F_4 , ( unsigned long ) & V_2 -> V_9 ) ;
F_30 ( & V_2 -> V_9 ) ;
V_27 = F_31 ( & V_2 -> V_9 ) ;
if ( V_27 )
return V_27 ;
if ( V_2 -> V_19 )
F_11 ( V_2 ) ;
return 0 ;
}
static int F_32 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_33 ( V_22 ) ;
F_34 ( & V_2 -> V_15 ) ;
F_35 ( & V_2 -> V_9 ) ;
return 0 ;
}
static int T_1 F_36 ( void )
{
return F_37 ( & V_46 ) ;
}
