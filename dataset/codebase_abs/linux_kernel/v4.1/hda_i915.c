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
struct V_17 * V_10 = V_2 -> V_9 . V_10 ;
if ( V_10 -> V_18 != 0x0a0c && V_10 -> V_18 != 0x0c0c
&& V_10 -> V_18 != 0x0d0c && V_10 -> V_18 != 0x160c )
return;
if ( ! V_5 -> V_7 )
return;
V_14 = V_5 -> V_7 -> V_19 ( V_5 -> V_11 ) ;
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
F_4 ( & V_2 -> V_9 , V_20 , V_15 ) ;
F_4 ( & V_2 -> V_9 , V_21 , V_16 ) ;
}
static int F_5 ( struct V_18 * V_11 )
{
struct V_22 * V_23 = F_6 ( V_11 ) ;
struct V_24 * V_9 = V_23 -> V_25 ;
struct V_1 * V_2 = F_7 ( V_9 , struct V_1 , V_9 ) ;
struct V_4 * V_5 = & V_2 -> V_6 ;
int V_26 ;
V_26 = F_8 ( V_11 , V_5 ) ;
if ( V_26 < 0 )
return V_26 ;
if ( F_9 ( ! ( V_5 -> V_11 && V_5 -> V_7 && V_5 -> V_7 -> V_12 &&
V_5 -> V_7 -> V_13 && V_5 -> V_7 -> V_19 ) ) ) {
V_26 = - V_27 ;
goto V_28;
}
if ( ! F_10 ( V_5 -> V_7 -> V_29 ) ) {
V_26 = - V_8 ;
goto V_28;
}
return 0 ;
V_28:
F_11 ( V_11 , V_5 ) ;
return V_26 ;
}
static void F_12 ( struct V_18 * V_11 )
{
struct V_22 * V_23 = F_6 ( V_11 ) ;
struct V_24 * V_9 = V_23 -> V_25 ;
struct V_1 * V_2 = F_7 ( V_9 , struct V_1 , V_9 ) ;
struct V_4 * V_5 = & V_2 -> V_6 ;
F_13 ( V_5 -> V_7 -> V_29 ) ;
F_11 ( V_11 , V_5 ) ;
F_9 ( V_5 -> V_7 || V_5 -> V_11 ) ;
}
static int F_14 ( struct V_18 * V_11 , void * V_30 )
{
return ! strcmp ( V_11 -> V_31 -> V_32 , L_4 ) ;
}
int F_15 ( struct V_1 * V_2 )
{
struct V_33 * V_34 = NULL ;
struct V_18 * V_11 = & V_2 -> V_9 . V_10 -> V_11 ;
struct V_4 * V_5 = & V_2 -> V_6 ;
int V_26 ;
F_16 ( V_11 , & V_34 , F_14 , V_2 ) ;
V_26 = F_17 ( V_11 , & V_35 ,
V_34 ) ;
if ( V_26 < 0 )
goto V_36;
F_18 ( L_4 ) ;
if ( ! V_5 -> V_7 ) {
V_26 = - V_8 ;
goto V_37;
}
F_2 ( V_11 , L_5 ) ;
return 0 ;
V_37:
F_19 ( V_11 , & V_35 ) ;
V_36:
F_20 ( V_11 , L_6 , V_26 ) ;
return V_26 ;
}
int F_21 ( struct V_1 * V_2 )
{
struct V_18 * V_11 = & V_2 -> V_9 . V_10 -> V_11 ;
F_19 ( V_11 , & V_35 ) ;
return 0 ;
}
