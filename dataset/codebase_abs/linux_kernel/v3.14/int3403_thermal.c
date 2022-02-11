static int F_1 ( struct V_1 * V_2 ,
unsigned long * V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned long long V_7 ;
T_1 V_8 ;
V_8 = F_2 ( V_5 -> V_9 , L_1 , NULL , & V_7 ) ;
if ( F_3 ( V_8 ) )
return - V_10 ;
* V_3 = F_4 ( V_7 , V_11 ) ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 ,
int V_12 , unsigned long * V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned long long V_13 ;
T_1 V_8 ;
V_8 = F_2 ( V_5 -> V_9 , L_2 , NULL , & V_13 ) ;
if ( F_3 ( V_8 ) )
return - V_10 ;
* V_3 = F_4 ( V_13 , V_11 ) ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 ,
int V_12 , unsigned long * V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_14 * V_15 = F_7 ( V_5 ) ;
* V_3 = V_15 -> V_16 [ V_12 ] ;
return 0 ;
}
static int F_8 ( struct V_1 * V_17 ,
int V_12 , enum V_18 * type )
{
* type = V_19 ;
return 0 ;
}
int F_9 ( struct V_1 * V_2 , int V_12 ,
unsigned long V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
T_1 V_8 ;
char V_20 [ 10 ] ;
int V_21 = 0 ;
struct V_14 * V_15 = F_7 ( V_5 ) ;
snprintf ( V_20 , sizeof( V_20 ) , L_3 , V_12 ) ;
if ( F_10 ( V_5 -> V_9 , V_20 ) ) {
V_8 = F_11 ( V_5 -> V_9 , V_20 ,
F_12 ( V_3 ,
V_11 ) ) ;
if ( F_3 ( V_8 ) )
V_21 = - V_10 ;
else
V_15 -> V_16 [ V_12 ] = V_3 ;
} else {
V_21 = - V_10 ;
F_13 ( & V_5 -> V_22 , L_4 ) ;
}
return V_21 ;
}
static void F_14 ( struct V_4 * V_5 , T_2 V_23 )
{
struct V_14 * V_15 ;
if ( ! V_5 )
return;
V_15 = F_7 ( V_5 ) ;
if ( ! V_15 )
return;
switch ( V_23 ) {
case V_24 :
break;
case V_25 :
F_15 ( V_15 -> V_2 ) ;
break;
default:
F_13 ( & V_5 -> V_22 , L_5 , V_23 ) ;
break;
}
}
static int F_16 ( struct V_4 * V_5 )
{
int V_26 = 0 ;
unsigned long long V_27 ;
T_1 V_8 ;
struct V_14 * V_15 ;
unsigned long long V_28 ;
int V_29 = 0 ;
if ( ! V_5 )
return - V_30 ;
V_8 = F_2 ( V_5 -> V_9 , L_6 , NULL , & V_27 ) ;
if ( F_3 ( V_8 ) )
return - V_30 ;
if ( V_27 != V_31 )
return - V_30 ;
V_15 = F_17 ( & V_5 -> V_22 , sizeof( * V_15 ) , V_32 ) ;
if ( ! V_15 )
return - V_33 ;
V_5 -> V_34 = V_15 ;
V_8 = F_2 ( V_5 -> V_9 , L_7 , NULL ,
& V_28 ) ;
if ( F_3 ( V_8 ) )
V_28 = 0 ;
if ( V_28 ) {
V_15 -> V_16 = F_17 ( & V_5 -> V_22 ,
sizeof( * V_15 -> V_16 ) * V_28 ,
V_32 ) ;
if ( ! V_15 -> V_16 )
return - V_33 ;
V_29 = F_18 ( V_28 ) - 1 ;
}
V_15 -> V_2 = F_19 ( F_20 ( V_5 ) ,
V_28 , V_29 , V_5 , & V_35 ,
NULL , 0 , 0 ) ;
if ( F_21 ( V_15 -> V_2 ) ) {
V_26 = F_22 ( V_15 -> V_2 ) ;
return V_26 ;
}
strcpy ( F_23 ( V_5 ) , L_8 ) ;
strcpy ( F_24 ( V_5 ) , V_36 ) ;
return 0 ;
}
static int F_25 ( struct V_4 * V_5 )
{
struct V_14 * V_15 ;
V_15 = F_7 ( V_5 ) ;
F_26 ( V_15 -> V_2 ) ;
return 0 ;
}
