static int F_1 ( struct V_1 * V_2 ,
unsigned long V_3 , void * V_4 )
{
T_1 V_5 = ( T_1 ) V_4 ;
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 , V_8 ) ;
struct V_9 * V_10 = V_7 -> V_11 -> V_10 ;
const char * V_12 = V_7 -> V_11 -> V_12 ;
F_3 ( V_10 , L_1 , V_5 ) ;
switch ( V_5 ) {
case V_13 :
F_4 ( V_10 , L_2 , V_12 ) ;
break;
case V_14 :
F_5 ( V_10 , L_3 , V_12 ) ;
break;
default:
if ( F_6 ( V_7 -> V_11 , V_5 ) == V_15 )
F_3 ( V_10 , L_4 , V_5 ) ;
}
return V_16 ;
}
static void F_7 ( struct V_11 * V_11 , int V_17 )
{
struct V_6 * V_7 = V_11 -> V_18 ;
int V_19 ;
V_19 = F_8 ( V_7 -> V_20 , V_17 ) ;
if ( V_19 )
F_4 ( V_11 -> V_10 , L_5 , V_19 ) ;
}
static int F_9 ( struct V_11 * V_11 )
{
struct V_6 * V_7 = V_11 -> V_18 ;
struct V_21 * V_22 = F_10 ( V_11 -> V_10 ) ;
struct V_23 * V_24 = V_22 -> V_10 . V_25 ;
int V_19 ;
V_7 -> V_8 . V_26 = F_1 ;
V_7 -> V_20 = F_11 ( V_24 -> V_27 , & V_7 -> V_8 ) ;
if ( F_12 ( V_7 -> V_20 ) ) {
V_19 = F_13 ( V_7 -> V_20 ) ;
F_4 ( V_11 -> V_10 , L_6 , V_19 ) ;
return V_19 ;
}
V_19 = F_8 ( V_7 -> V_20 , V_28 ) ;
if ( V_19 ) {
F_4 ( V_11 -> V_10 , L_6 , V_19 ) ;
goto V_29;
}
V_19 = V_24 -> V_30 ( V_22 ) ;
if ( V_19 ) {
F_4 ( V_11 -> V_10 , L_7 , V_19 ) ;
goto V_29;
}
return 0 ;
V_29:
F_14 ( V_7 -> V_20 , & V_7 -> V_8 ) ;
return V_19 ;
}
static int F_15 ( struct V_11 * V_11 )
{
struct V_21 * V_22 = F_10 ( V_11 -> V_10 ) ;
struct V_23 * V_24 = V_22 -> V_10 . V_25 ;
struct V_6 * V_7 = V_11 -> V_18 ;
int V_19 ;
V_19 = V_24 -> V_31 ( V_22 ) ;
if ( V_19 )
return V_19 ;
F_14 ( V_7 -> V_20 , & V_7 -> V_8 ) ;
return 0 ;
}
static int T_2 F_16 ( struct V_21 * V_22 )
{
struct V_23 * V_24 = V_22 -> V_10 . V_25 ;
struct V_6 * V_7 ;
struct V_11 * V_11 ;
int V_19 ;
V_19 = F_17 ( & V_22 -> V_10 , F_18 ( 32 ) ) ;
if ( V_19 ) {
F_4 ( V_22 -> V_10 . V_32 , L_8 , V_19 ) ;
return V_19 ;
}
V_11 = F_19 ( & V_22 -> V_10 , V_24 -> V_12 , & V_33 ,
V_24 -> V_34 , sizeof( * V_7 ) ) ;
if ( ! V_11 )
return - V_35 ;
V_7 = V_11 -> V_18 ;
V_7 -> V_11 = V_11 ;
F_20 ( V_22 , V_11 ) ;
V_19 = F_21 ( V_11 ) ;
if ( V_19 )
goto V_36;
return 0 ;
V_36:
F_22 ( V_11 ) ;
return V_19 ;
}
static int T_3 F_23 ( struct V_21 * V_22 )
{
struct V_11 * V_11 = F_24 ( V_22 ) ;
return F_25 ( V_11 ) ;
}
