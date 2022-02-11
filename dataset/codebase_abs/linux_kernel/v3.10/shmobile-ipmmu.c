static void F_1 ( struct V_1 * V_2 , unsigned long V_3 ,
unsigned long V_4 )
{
F_2 ( V_4 , V_2 -> V_5 + V_3 ) ;
}
void F_3 ( struct V_1 * V_2 )
{
if ( ! V_2 )
return;
F_4 ( & V_2 -> V_6 ) ;
if ( V_2 -> V_7 )
F_1 ( V_2 , V_8 , V_9 | V_10 ) ;
else
F_1 ( V_2 , V_8 , V_9 ) ;
F_5 ( & V_2 -> V_6 ) ;
}
void F_6 ( struct V_1 * V_2 , unsigned long V_11 , int V_12 ,
int V_13 )
{
if ( ! V_2 )
return;
F_4 ( & V_2 -> V_6 ) ;
switch ( V_12 ) {
default:
V_2 -> V_7 = 0 ;
break;
case 0x2000 :
F_1 ( V_2 , V_14 , 1 ) ;
V_2 -> V_7 = 1 ;
break;
case 0x1000 :
F_1 ( V_2 , V_14 , 2 ) ;
V_2 -> V_7 = 1 ;
break;
case 0x800 :
F_1 ( V_2 , V_14 , 3 ) ;
V_2 -> V_7 = 1 ;
break;
case 0x400 :
F_1 ( V_2 , V_14 , 4 ) ;
V_2 -> V_7 = 1 ;
break;
case 0x200 :
F_1 ( V_2 , V_14 , 5 ) ;
V_2 -> V_7 = 1 ;
break;
case 0x100 :
F_1 ( V_2 , V_14 , 6 ) ;
V_2 -> V_7 = 1 ;
break;
case 0x80 :
F_1 ( V_2 , V_14 , 7 ) ;
V_2 -> V_7 = 1 ;
break;
}
F_1 ( V_2 , V_15 , V_11 ) ;
F_1 ( V_2 , V_16 , V_13 ) ;
F_5 ( & V_2 -> V_6 ) ;
}
static int F_7 ( struct V_17 * V_18 )
{
struct V_1 * V_2 ;
struct V_19 * V_20 ;
struct V_21 * V_22 = V_18 -> V_23 . V_24 ;
V_20 = F_8 ( V_18 , V_25 , 0 ) ;
if ( ! V_20 ) {
F_9 ( & V_18 -> V_23 , L_1 ) ;
return - V_26 ;
}
V_2 = F_10 ( & V_18 -> V_23 , sizeof( * V_2 ) , V_27 ) ;
if ( ! V_2 ) {
F_9 ( & V_18 -> V_23 , L_2 ) ;
return - V_28 ;
}
F_11 ( & V_2 -> V_6 ) ;
V_2 -> V_23 = & V_18 -> V_23 ;
V_2 -> V_5 = F_12 ( & V_18 -> V_23 , V_20 -> V_29 ,
F_13 ( V_20 ) ) ;
if ( ! V_2 -> V_5 ) {
F_9 ( & V_18 -> V_23 , L_3 ) ;
return - V_28 ;
}
V_2 -> V_30 = V_22 -> V_30 ;
V_2 -> V_31 = V_22 -> V_31 ;
F_14 ( V_18 , V_2 ) ;
F_1 ( V_2 , V_8 , 0x0 ) ;
F_1 ( V_2 , V_32 , 0x0 ) ;
F_15 ( V_2 ) ;
return 0 ;
}
static int T_1 F_16 ( void )
{
return F_17 ( & V_33 ) ;
}
