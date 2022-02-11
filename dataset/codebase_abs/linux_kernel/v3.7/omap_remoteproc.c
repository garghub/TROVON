static int F_1 ( struct V_1 * V_2 ,
unsigned long V_3 , void * V_4 )
{
T_1 V_5 = ( T_1 ) V_4 ;
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 , V_8 ) ;
struct V_9 * V_10 = V_7 -> V_11 -> V_10 . V_12 ;
const char * V_13 = V_7 -> V_11 -> V_13 ;
F_3 ( V_10 , L_1 , V_5 ) ;
switch ( V_5 ) {
case V_14 :
F_4 ( V_10 , L_2 , V_13 ) ;
break;
case V_15 :
F_5 ( V_10 , L_3 , V_13 ) ;
break;
default:
if ( F_6 ( V_7 -> V_11 , V_5 ) == V_16 )
F_3 ( V_10 , L_4 , V_5 ) ;
}
return V_17 ;
}
static void F_7 ( struct V_11 * V_11 , int V_18 )
{
struct V_6 * V_7 = V_11 -> V_19 ;
struct V_9 * V_10 = V_11 -> V_10 . V_12 ;
int V_20 ;
V_20 = F_8 ( V_7 -> V_21 , V_18 ) ;
if ( V_20 )
F_4 ( V_10 , L_5 , V_20 ) ;
}
static int F_9 ( struct V_11 * V_11 )
{
struct V_6 * V_7 = V_11 -> V_19 ;
struct V_9 * V_10 = V_11 -> V_10 . V_12 ;
struct V_22 * V_23 = F_10 ( V_10 ) ;
struct V_24 * V_25 = V_23 -> V_10 . V_26 ;
int V_20 ;
if ( V_25 -> V_27 )
V_25 -> V_27 ( V_11 -> V_28 ) ;
V_7 -> V_8 . V_29 = F_1 ;
V_7 -> V_21 = F_11 ( V_25 -> V_30 , & V_7 -> V_8 ) ;
if ( F_12 ( V_7 -> V_21 ) ) {
V_20 = F_13 ( V_7 -> V_21 ) ;
F_4 ( V_10 , L_6 , V_20 ) ;
return V_20 ;
}
V_20 = F_8 ( V_7 -> V_21 , V_31 ) ;
if ( V_20 ) {
F_4 ( V_10 , L_6 , V_20 ) ;
goto V_32;
}
V_20 = V_25 -> V_33 ( V_23 ) ;
if ( V_20 ) {
F_4 ( V_10 , L_7 , V_20 ) ;
goto V_32;
}
return 0 ;
V_32:
F_14 ( V_7 -> V_21 , & V_7 -> V_8 ) ;
return V_20 ;
}
static int F_15 ( struct V_11 * V_11 )
{
struct V_9 * V_10 = V_11 -> V_10 . V_12 ;
struct V_22 * V_23 = F_10 ( V_10 ) ;
struct V_24 * V_25 = V_23 -> V_10 . V_26 ;
struct V_6 * V_7 = V_11 -> V_19 ;
int V_20 ;
V_20 = V_25 -> V_34 ( V_23 ) ;
if ( V_20 )
return V_20 ;
F_14 ( V_7 -> V_21 , & V_7 -> V_8 ) ;
return 0 ;
}
static int T_2 F_16 ( struct V_22 * V_23 )
{
struct V_24 * V_25 = V_23 -> V_10 . V_26 ;
struct V_6 * V_7 ;
struct V_11 * V_11 ;
int V_20 ;
V_20 = F_17 ( & V_23 -> V_10 , F_18 ( 32 ) ) ;
if ( V_20 ) {
F_4 ( & V_23 -> V_10 , L_8 , V_20 ) ;
return V_20 ;
}
V_11 = F_19 ( & V_23 -> V_10 , V_25 -> V_13 , & V_35 ,
V_25 -> V_36 , sizeof( * V_7 ) ) ;
if ( ! V_11 )
return - V_37 ;
V_7 = V_11 -> V_19 ;
V_7 -> V_11 = V_11 ;
F_20 ( V_23 , V_11 ) ;
V_20 = F_21 ( V_11 ) ;
if ( V_20 )
goto V_38;
return 0 ;
V_38:
F_22 ( V_11 ) ;
return V_20 ;
}
static int T_3 F_23 ( struct V_22 * V_23 )
{
struct V_11 * V_11 = F_24 ( V_23 ) ;
F_25 ( V_11 ) ;
F_22 ( V_11 ) ;
return 0 ;
}
