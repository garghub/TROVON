static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 , ! V_2 -> V_4 ) ;
if ( V_2 -> V_5 == V_6 )
F_3 ( V_2 -> V_3 ) ;
}
static int F_4 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = F_5 ( V_8 ) ;
switch ( V_2 -> V_5 ) {
case V_6 :
V_2 -> V_9 = ! V_2 -> V_9 ;
F_2 ( V_2 -> V_3 , V_2 -> V_9 ) ;
break;
case V_10 :
F_2 ( V_2 -> V_3 , ! V_2 -> V_4 ) ;
F_6 ( 1 ) ;
F_2 ( V_2 -> V_3 , V_2 -> V_4 ) ;
break;
}
return 0 ;
}
static int F_7 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = F_5 ( V_8 ) ;
V_2 -> V_9 = V_2 -> V_4 ;
F_8 ( V_2 -> V_3 , V_2 -> V_9 ) ;
F_9 ( V_11 , & V_8 -> V_12 ) ;
return F_4 ( V_8 ) ;
}
static int F_10 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = F_5 ( V_8 ) ;
if ( ! V_2 -> V_13 ) {
F_1 ( V_2 ) ;
F_11 ( V_11 , & V_8 -> V_12 ) ;
}
return 0 ;
}
static int F_12 ( struct V_14 * V_15 )
{
struct V_1 * V_2 ;
enum V_16 V_17 ;
unsigned int V_18 ;
unsigned long V_19 = 0 ;
const char * V_20 ;
int V_21 ;
V_2 = F_13 ( & V_15 -> V_22 , sizeof( * V_2 ) , V_23 ) ;
if ( ! V_2 )
return - V_24 ;
F_14 ( V_15 , V_2 ) ;
V_2 -> V_3 = F_15 ( V_15 -> V_22 . V_25 , 0 , & V_17 ) ;
if ( ! F_16 ( V_2 -> V_3 ) )
return V_2 -> V_3 ;
V_2 -> V_4 = V_17 & V_26 ;
V_21 = F_17 ( V_15 -> V_22 . V_25 , L_1 , & V_20 ) ;
if ( V_21 )
return V_21 ;
if ( ! strcmp ( V_20 , L_2 ) ) {
V_2 -> V_5 = V_6 ;
V_19 = V_27 ;
} else if ( ! strcmp ( V_20 , L_3 ) ) {
V_2 -> V_5 = V_10 ;
V_19 = V_2 -> V_4 ? V_28 : V_29 ;
} else {
return - V_30 ;
}
V_21 = F_18 ( & V_15 -> V_22 , V_2 -> V_3 , V_19 ,
F_19 ( & V_15 -> V_22 ) ) ;
if ( V_21 )
return V_21 ;
V_21 = F_20 ( V_15 -> V_22 . V_25 ,
L_4 , & V_18 ) ;
if ( V_21 )
return V_21 ;
if ( V_18 < 2 || V_18 > 65535 )
return - V_30 ;
V_2 -> V_13 = F_21 ( V_15 -> V_22 . V_25 ,
L_5 ) ;
F_22 ( & V_2 -> V_8 , V_2 ) ;
V_2 -> V_8 . V_31 = & V_32 ;
V_2 -> V_8 . V_33 = & V_34 ;
V_2 -> V_8 . V_35 = V_36 ;
V_2 -> V_8 . V_37 = V_18 ;
V_2 -> V_8 . V_38 = & V_15 -> V_22 ;
if ( F_23 ( & V_2 -> V_8 , 0 , & V_15 -> V_22 ) < 0 )
V_2 -> V_8 . V_39 = V_40 ;
F_24 ( & V_2 -> V_8 ) ;
if ( V_2 -> V_13 )
F_7 ( & V_2 -> V_8 ) ;
V_21 = F_25 ( & V_2 -> V_8 ) ;
return V_21 ;
}
static int F_26 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = F_27 ( V_15 ) ;
F_28 ( & V_2 -> V_8 ) ;
return 0 ;
}
static int T_1 F_29 ( void )
{
return F_30 ( & V_41 ) ;
}
