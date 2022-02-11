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
T_4 * V_35 , T_5 V_36 )
{
void * V_37 ;
if ( ! V_33 || * V_33 -> V_38 >= 0xffffffffUL )
V_36 &= ~ V_39 ;
V_37 = ( void * ) F_9 ( V_36 , F_10 ( V_34 ) ) ;
if ( V_37 ) {
memset ( V_37 , 0 , V_34 ) ;
* V_35 = F_11 ( V_37 ) ;
}
return V_37 ;
}
static void F_12 ( struct V_32 * V_33 , T_3 V_34 ,
void * V_40 , T_4 V_41 )
{
F_13 ( ( unsigned long ) V_40 , F_10 ( V_34 ) ) ;
}
static T_4 F_14 ( struct V_32 * V_33 , struct V_42 * V_42 ,
unsigned long V_43 , T_3 V_34 ,
enum V_44 V_45 ,
struct V_46 * V_47 )
{
return F_15 ( V_42 ) + V_43 ;
}
static int F_16 ( struct V_32 * V_33 , struct V_48 * V_49 , int V_50 ,
enum V_44 V_45 , struct V_46 * V_47 )
{
int V_51 ;
struct V_48 * V_52 ;
F_17 (sgl, sg, nents, i) {
void * V_53 ;
F_18 ( ! F_19 ( V_52 ) ) ;
V_53 = F_20 ( V_52 ) ;
F_21 ( V_52 ) = ( T_4 ) F_11 ( V_53 ) ;
F_22 ( V_52 ) = V_52 -> V_54 ;
}
return V_50 ;
}
static int F_23 ( struct V_32 * V_33 , T_4 V_41 )
{
return 0 ;
}
static int F_24 ( struct V_32 * V_33 , T_6 V_55 )
{
return V_55 < 0x00ffffffUL ? 0 : 1 ;
}
static int F_25 ( struct V_32 * V_33 , T_6 V_55 )
{
if ( ! V_33 -> V_38 || ! F_26 ( V_33 , V_55 ) )
return - V_56 ;
* V_33 -> V_38 = V_55 ;
return 0 ;
}
void T_7 * F_27 ( struct V_57 * V_33 , int V_58 , unsigned long V_59 )
{
return NULL ;
}
void F_28 ( struct V_57 * V_33 , void T_7 * V_60 )
{
}
