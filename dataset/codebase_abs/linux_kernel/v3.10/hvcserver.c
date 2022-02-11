static int F_1 ( long V_1 )
{
switch ( V_1 ) {
case V_2 :
return 0 ;
case V_3 :
return - V_4 ;
case V_5 :
return - V_6 ;
case V_7 :
case V_8 :
case V_9 :
case V_10 :
case V_11 :
case V_12 :
case V_13 :
return - V_14 ;
case V_15 :
default:
return - V_16 ;
}
}
int F_2 ( struct V_17 * V_18 )
{
struct V_19 * V_20 ;
struct V_17 * V_21 ;
if ( ! V_18 )
return - V_4 ;
while ( ! F_3 ( V_18 ) ) {
V_21 = V_18 -> V_22 ;
V_20 = F_4 ( V_21 , struct V_19 , V_23 ) ;
F_5 ( V_21 ) ;
F_6 ( V_20 ) ;
}
return 0 ;
}
static int F_7 ( T_1 V_24 ,
unsigned long V_25 ,
unsigned long V_26 , unsigned long * V_27 )
{
long V_28 ;
V_28 = F_8 ( V_29 , V_24 ,
V_25 ,
V_26 , F_9 ( V_27 ) ) ;
return F_1 ( V_28 ) ;
}
int F_10 ( T_1 V_24 , struct V_17 * V_18 ,
unsigned long * V_27 )
{
unsigned long V_25 ;
unsigned long V_26 ;
struct V_19 * V_30 = NULL ;
int V_31 = 1 ;
int V_28 ;
memset ( V_27 , 0x00 , V_32 ) ;
if ( ! V_18 || ! V_27 )
return - V_4 ;
V_25 = V_26 = ~ 0UL ;
F_11 ( V_18 ) ;
do {
V_28 = F_7 ( V_24 , V_25 ,
V_26 , V_27 ) ;
if ( V_28 ) {
if ( ! F_3 ( V_18 ) )
return 0 ;
return V_28 ;
}
V_25 = V_27 [ 0 ] ;
V_26 = V_27 [ 1 ] ;
if ( V_25 == ~ 0UL
&& V_26 == ~ 0UL )
break;
V_30 = F_12 ( sizeof( struct V_19 ) ,
V_33 ) ;
if ( ! V_30 ) {
F_13 ( V_34 L_1
L_2 ) ;
F_2 ( V_18 ) ;
return - V_35 ;
}
V_30 -> V_24
= ( unsigned int ) V_26 ;
V_30 -> V_36
= ( unsigned int ) V_25 ;
F_14 ( & V_30 -> V_37 [ 0 ] ,
( char * ) & V_27 [ 2 ] ,
sizeof( V_30 -> V_37 ) ) ;
F_15 ( & ( V_30 -> V_23 ) , V_18 ) ;
V_30 = NULL ;
} while ( V_31 );
return 0 ;
}
int F_16 ( T_1 V_24 ,
T_1 V_38 , T_1 V_39 )
{
long V_28 ;
V_28 = F_8 ( V_40 , V_24 ,
V_38 , V_39 ) ;
return F_1 ( V_28 ) ;
}
int F_17 ( T_1 V_24 )
{
long V_28 ;
V_28 = F_8 ( V_41 , V_24 ) ;
return F_1 ( V_28 ) ;
}
