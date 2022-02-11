struct V_1 * T_1
F_1 ( void )
{
struct V_1 * V_2 ;
V_2 = F_2 ( sizeof( * V_2 ) ) ;
* V_3 = V_2 ;
V_3 = & V_2 -> V_4 ;
return V_2 ;
}
struct V_5 * T_1
F_3 ( void )
{
struct V_5 * V_6 ;
V_6 = F_2 ( sizeof( * V_6 ) ) ;
return V_6 ;
}
T_2 long
F_4 ( long V_7 , unsigned long V_8 , unsigned long V_9 )
{
struct V_1 * V_2 ;
if ( V_7 & V_10 ) {
for ( V_2 = V_11 ; V_2 ; V_2 = V_2 -> V_4 )
if ( V_2 -> V_12 == V_8 )
break;
if ( ! V_2 )
return - V_13 ;
} else {
if ( V_8 == 0 && V_9 == 0 )
V_2 = V_14 ;
else
return - V_13 ;
}
switch ( V_7 & ~ V_10 ) {
case V_15 :
return V_2 -> V_12 ;
case V_16 :
return V_2 -> V_17 ;
case V_18 :
return V_2 -> V_19 ;
case V_20 :
return V_2 -> V_21 ;
case V_22 :
return V_2 -> V_23 ;
case V_24 :
return V_2 -> V_8 -> V_25 ;
}
return - V_26 ;
}
T_2 long
F_5 ( unsigned long V_8 , unsigned long V_9 ,
unsigned long V_27 , unsigned long V_28 , void * V_29 )
{
if ( ! F_6 ( V_30 ) )
return - V_31 ;
else
return - V_13 ;
}
T_2 long
F_7 ( unsigned long V_8 , unsigned long V_9 ,
unsigned long V_27 , unsigned long V_28 , void * V_29 )
{
if ( ! F_6 ( V_30 ) )
return - V_31 ;
else
return - V_13 ;
}
static void * F_8 ( struct V_32 * V_33 , T_3 V_34 ,
T_4 * V_35 , T_5 V_36 ,
struct V_37 * V_38 )
{
void * V_39 ;
if ( ! V_33 || * V_33 -> V_40 >= 0xffffffffUL )
V_36 &= ~ V_41 ;
V_39 = ( void * ) F_9 ( V_36 , F_10 ( V_34 ) ) ;
if ( V_39 ) {
memset ( V_39 , 0 , V_34 ) ;
* V_35 = F_11 ( V_39 ) ;
}
return V_39 ;
}
static int F_12 ( struct V_32 * V_33 , T_6 V_42 )
{
return V_42 < 0x00ffffffUL ? 0 : 1 ;
}
