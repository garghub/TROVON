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
return F_2 ( sizeof( struct V_5 ) ) ;
}
T_2 long
F_4 ( long V_6 , unsigned long V_7 , unsigned long V_8 )
{
struct V_1 * V_2 ;
if ( V_6 & V_9 ) {
for ( V_2 = V_10 ; V_2 ; V_2 = V_2 -> V_4 )
if ( V_2 -> V_11 == V_7 )
break;
if ( ! V_2 )
return - V_12 ;
} else {
if ( V_7 == 0 && V_8 == 0 )
V_2 = V_13 ;
else
return - V_12 ;
}
switch ( V_6 & ~ V_9 ) {
case V_14 :
return V_2 -> V_11 ;
case V_15 :
return V_2 -> V_16 ;
case V_17 :
return V_2 -> V_18 ;
case V_19 :
return V_2 -> V_20 ;
case V_21 :
return V_2 -> V_22 ;
case V_23 :
return V_2 -> V_7 -> V_24 ;
}
return - V_25 ;
}
T_2 long
F_5 ( unsigned long V_7 , unsigned long V_8 ,
unsigned long V_26 , unsigned long V_27 , void * V_28 )
{
if ( ! F_6 ( V_29 ) )
return - V_30 ;
else
return - V_12 ;
}
T_2 long
F_7 ( unsigned long V_7 , unsigned long V_8 ,
unsigned long V_26 , unsigned long V_27 , void * V_28 )
{
if ( ! F_6 ( V_29 ) )
return - V_30 ;
else
return - V_12 ;
}
static void * F_8 ( struct V_31 * V_32 , T_3 V_33 ,
T_4 * V_34 , T_5 V_35 ,
unsigned long V_36 )
{
void * V_37 ;
if ( ! V_32 || * V_32 -> V_38 >= 0xffffffffUL )
V_35 &= ~ V_39 ;
V_37 = ( void * ) F_9 ( V_35 , F_10 ( V_33 ) ) ;
if ( V_37 ) {
memset ( V_37 , 0 , V_33 ) ;
* V_34 = F_11 ( V_37 ) ;
}
return V_37 ;
}
static int F_12 ( struct V_31 * V_32 , T_6 V_40 )
{
return V_40 < 0x00ffffffUL ? 0 : 1 ;
}
