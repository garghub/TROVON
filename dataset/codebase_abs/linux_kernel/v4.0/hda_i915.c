int F_1 ( struct V_1 * V_2 , bool V_3 )
{
struct V_4 * V_5 = & V_2 -> V_6 ;
if ( ! V_5 -> V_7 )
return - V_8 ;
F_2 ( & V_2 -> V_9 . V_10 -> V_11 , L_1 ,
V_3 ? L_2 : L_3 ) ;
if ( V_3 )
V_5 -> V_7 -> V_12 ( V_5 -> V_11 ) ;
else
V_5 -> V_7 -> V_13 ( V_5 -> V_11 ) ;
return 0 ;
}
void F_3 ( struct V_1 * V_2 )
{
int V_14 ;
unsigned int V_15 , V_16 ;
struct V_4 * V_5 = & V_2 -> V_6 ;
if ( ! V_5 -> V_7 )
return;
V_14 = V_5 -> V_7 -> V_17 ( V_5 -> V_11 ) ;
switch ( V_14 ) {
case 337500 :
V_15 = 16 ;
V_16 = 225 ;
break;
case 450000 :
default:
V_15 = 4 ;
V_16 = 75 ;
break;
case 540000 :
V_15 = 4 ;
V_16 = 90 ;
break;
case 675000 :
V_15 = 8 ;
V_16 = 225 ;
break;
}
F_4 ( & V_2 -> V_9 , V_18 , V_15 ) ;
F_4 ( & V_2 -> V_9 , V_19 , V_16 ) ;
}
static int F_5 ( struct V_20 * V_11 )
{
struct V_21 * V_22 = F_6 ( V_11 ) ;
struct V_23 * V_9 = V_22 -> V_24 ;
struct V_1 * V_2 = F_7 ( V_9 , struct V_1 , V_9 ) ;
struct V_4 * V_5 = & V_2 -> V_6 ;
int V_25 ;
V_25 = F_8 ( V_11 , V_5 ) ;
if ( V_25 < 0 )
return V_25 ;
if ( F_9 ( ! ( V_5 -> V_11 && V_5 -> V_7 && V_5 -> V_7 -> V_12 &&
V_5 -> V_7 -> V_13 && V_5 -> V_7 -> V_17 ) ) ) {
V_25 = - V_26 ;
goto V_27;
}
if ( ! F_10 ( V_5 -> V_7 -> V_28 ) ) {
V_25 = - V_8 ;
goto V_27;
}
return 0 ;
V_27:
F_11 ( V_11 , V_5 ) ;
return V_25 ;
}
static void F_12 ( struct V_20 * V_11 )
{
struct V_21 * V_22 = F_6 ( V_11 ) ;
struct V_23 * V_9 = V_22 -> V_24 ;
struct V_1 * V_2 = F_7 ( V_9 , struct V_1 , V_9 ) ;
struct V_4 * V_5 = & V_2 -> V_6 ;
F_13 ( V_5 -> V_7 -> V_28 ) ;
F_11 ( V_11 , V_5 ) ;
F_9 ( V_5 -> V_7 || V_5 -> V_11 ) ;
}
static int F_14 ( struct V_20 * V_11 , void * V_29 )
{
return ! strcmp ( V_11 -> V_30 -> V_31 , L_4 ) ;
}
int F_15 ( struct V_1 * V_2 )
{
struct V_32 * V_33 = NULL ;
struct V_20 * V_11 = & V_2 -> V_9 . V_10 -> V_11 ;
struct V_4 * V_5 = & V_2 -> V_6 ;
int V_25 ;
F_16 ( V_11 , & V_33 , F_14 , V_2 ) ;
V_25 = F_17 ( V_11 , & V_34 ,
V_33 ) ;
if ( V_25 < 0 )
goto V_35;
F_18 ( L_4 ) ;
if ( ! V_5 -> V_7 ) {
V_25 = - V_8 ;
goto V_36;
}
F_2 ( V_11 , L_5 ) ;
return 0 ;
V_36:
F_19 ( V_11 , & V_34 ) ;
V_35:
F_20 ( V_11 , L_6 , V_25 ) ;
return V_25 ;
}
int F_21 ( struct V_1 * V_2 )
{
struct V_20 * V_11 = & V_2 -> V_9 . V_10 -> V_11 ;
F_19 ( V_11 , & V_34 ) ;
return 0 ;
}
