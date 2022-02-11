static T_1 F_1 ( struct V_1 * V_2 ,
void * V_3 )
{
return F_2 ( V_3 ) ;
}
static void F_3 ( struct V_1 * V_2 ,
void * V_3 , T_1 V_4 )
{
F_4 ( V_4 , V_3 ) ;
}
static T_1 F_5 ( struct V_1 * V_2 ,
void * V_3 )
{
return F_2 ( V_3 + ( long ) V_3 - ( long ) V_2 -> V_5 ) ;
}
static void F_6 ( struct V_1 * V_2 ,
void * V_3 , T_1 V_4 )
{
F_4 ( V_4 , V_3 + ( long ) V_3 - ( long ) V_2 -> V_5 ) ;
}
static int T_2 F_7 ( struct V_6 * V_7 )
{
int V_8 ;
void T_3 * V_9 ;
struct V_10 * V_11 ;
struct V_1 * V_2 ;
struct V_12 * V_13 ;
int V_14 ;
#ifdef F_8
struct V_15 * V_15 ;
V_15 = F_9 ( & V_7 -> V_11 , NULL ) ;
if ( F_10 ( V_15 ) ) {
F_11 ( & V_7 -> V_11 , L_1 ) ;
V_8 = - V_16 ;
goto exit;
}
#endif
V_13 = F_12 ( V_7 , V_17 , 0 ) ;
V_14 = F_13 ( V_7 , 0 ) ;
if ( ! V_13 || V_14 <= 0 ) {
V_8 = - V_16 ;
goto V_18;
}
if ( ! F_14 ( V_13 -> V_19 , F_15 ( V_13 ) ,
V_20 ) ) {
F_11 ( & V_7 -> V_11 , L_2 ) ;
V_8 = - V_16 ;
goto V_18;
}
V_9 = F_16 ( V_13 -> V_19 , F_15 ( V_13 ) ) ;
if ( ! V_9 ) {
F_11 ( & V_7 -> V_11 , L_3 ) ;
V_8 = - V_21 ;
goto V_22;
}
V_11 = F_17 () ;
if ( ! V_11 ) {
V_8 = - V_21 ;
goto V_23;
}
V_2 = F_18 ( V_11 ) ;
V_11 -> V_14 = V_14 ;
V_2 -> V_5 = V_9 ;
#ifdef F_8
V_2 -> V_24 . clock . V_25 = F_19 ( V_15 ) ;
V_2 -> V_2 = V_15 ;
#endif
switch ( V_13 -> V_26 & V_27 ) {
case V_28 :
V_2 -> V_29 = F_5 ;
V_2 -> V_30 = F_6 ;
break;
case V_31 :
default:
V_2 -> V_29 = F_1 ;
V_2 -> V_30 = F_3 ;
break;
}
F_20 ( V_7 , V_11 ) ;
F_21 ( V_11 , & V_7 -> V_11 ) ;
V_8 = F_22 ( V_11 ) ;
if ( V_8 ) {
F_11 ( & V_7 -> V_11 , L_4 ,
V_20 , V_8 ) ;
goto V_32;
}
F_23 ( & V_7 -> V_11 , L_5 ,
V_20 , V_2 -> V_5 , V_11 -> V_14 ) ;
return 0 ;
V_32:
F_20 ( V_7 , NULL ) ;
F_24 ( V_11 ) ;
V_23:
F_25 ( V_9 ) ;
V_22:
F_26 ( V_13 -> V_19 , F_15 ( V_13 ) ) ;
V_18:
#ifdef F_8
F_27 ( V_15 ) ;
exit:
#endif
F_11 ( & V_7 -> V_11 , L_6 ) ;
return V_8 ;
}
static int T_4 F_28 ( struct V_6 * V_7 )
{
struct V_10 * V_11 = F_29 ( V_7 ) ;
struct V_1 * V_2 = F_18 ( V_11 ) ;
struct V_12 * V_13 ;
F_30 ( V_11 ) ;
F_20 ( V_7 , NULL ) ;
F_24 ( V_11 ) ;
F_25 ( V_2 -> V_5 ) ;
V_13 = F_12 ( V_7 , V_17 , 0 ) ;
F_26 ( V_13 -> V_19 , F_15 ( V_13 ) ) ;
#ifdef F_8
F_27 ( V_2 -> V_2 ) ;
#endif
return 0 ;
}
