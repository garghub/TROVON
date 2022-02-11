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
* V_3 = V_13 * 100 ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 ,
int V_12 , unsigned long * V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_14 * V_15 = F_7 ( V_5 ) ;
if ( V_12 == V_15 -> V_16 )
* V_3 = V_15 -> V_17 ;
else if ( V_12 == V_15 -> V_18 )
* V_3 = V_15 -> V_19 ;
else {
* V_3 = V_15 -> V_20 [ V_12 ] ;
}
return 0 ;
}
static int F_8 ( struct V_1 * V_21 ,
int V_12 , enum V_22 * type )
{
struct V_4 * V_5 = V_21 -> V_6 ;
struct V_14 * V_15 = F_7 ( V_5 ) ;
if ( V_12 == V_15 -> V_16 )
* type = V_23 ;
else
* type = V_24 ;
return 0 ;
}
int F_9 ( struct V_1 * V_2 , int V_12 ,
unsigned long V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
T_1 V_8 ;
char V_25 [ 10 ] ;
int V_26 = 0 ;
struct V_14 * V_15 = F_7 ( V_5 ) ;
snprintf ( V_25 , sizeof( V_25 ) , L_3 , V_12 ) ;
if ( F_10 ( V_5 -> V_9 , V_25 ) ) {
V_8 = F_11 ( V_5 -> V_9 , V_25 ,
F_12 ( V_3 ,
V_11 ) ) ;
if ( F_3 ( V_8 ) )
V_26 = - V_10 ;
else
V_15 -> V_20 [ V_12 ] = V_3 ;
} else {
V_26 = - V_10 ;
F_13 ( & V_5 -> V_27 , L_4 ) ;
}
return V_26 ;
}
static void F_14 ( struct V_4 * V_5 , T_2 V_28 )
{
struct V_14 * V_15 ;
if ( ! V_5 )
return;
V_15 = F_7 ( V_5 ) ;
if ( ! V_15 )
return;
switch ( V_28 ) {
case V_29 :
break;
case V_30 :
F_15 ( V_15 -> V_2 ) ;
break;
default:
F_13 ( & V_5 -> V_27 , L_5 , V_28 ) ;
break;
}
}
static int F_16 ( struct V_4 * V_5 , unsigned long * V_3 )
{
unsigned long long V_31 ;
T_1 V_8 ;
V_8 = F_2 ( V_5 -> V_9 , L_6 , NULL , & V_31 ) ;
if ( F_3 ( V_8 ) )
return - V_10 ;
* V_3 = F_4 ( V_31 , V_11 ) ;
return 0 ;
}
static int F_17 ( struct V_4 * V_5 , unsigned long * V_3 )
{
unsigned long long V_32 ;
T_1 V_8 ;
V_8 = F_2 ( V_5 -> V_9 , L_7 , NULL , & V_32 ) ;
if ( F_3 ( V_8 ) )
return - V_10 ;
* V_3 = F_4 ( V_32 , V_11 ) ;
return 0 ;
}
static int F_18 ( struct V_4 * V_5 )
{
int V_33 = 0 ;
unsigned long long V_34 ;
T_1 V_8 ;
struct V_14 * V_15 ;
unsigned long long V_35 ;
int V_36 = 0 ;
if ( ! V_5 )
return - V_37 ;
V_8 = F_2 ( V_5 -> V_9 , L_8 , NULL , & V_34 ) ;
if ( F_3 ( V_8 ) )
return - V_37 ;
if ( V_34 != V_38 )
return - V_37 ;
V_15 = F_19 ( & V_5 -> V_27 , sizeof( * V_15 ) , V_39 ) ;
if ( ! V_15 )
return - V_40 ;
V_5 -> V_41 = V_15 ;
V_8 = F_2 ( V_5 -> V_9 , L_9 , NULL ,
& V_35 ) ;
if ( F_3 ( V_8 ) )
V_35 = 0 ;
if ( V_35 ) {
V_15 -> V_20 = F_19 ( & V_5 -> V_27 ,
sizeof( * V_15 -> V_20 ) * V_35 ,
V_39 ) ;
if ( ! V_15 -> V_20 )
return - V_40 ;
V_36 = F_20 ( V_35 ) - 1 ;
}
V_15 -> V_18 = - 1 ;
if ( ! F_17 ( V_5 , & V_15 -> V_19 ) )
V_15 -> V_18 = V_35 ++ ;
V_15 -> V_16 = - 1 ;
if ( ! F_16 ( V_5 , & V_15 -> V_17 ) )
V_15 -> V_16 = V_35 ++ ;
V_15 -> V_2 = F_21 ( F_22 ( V_5 ) ,
V_35 , V_36 , V_5 , & V_42 ,
NULL , 0 , 0 ) ;
if ( F_23 ( V_15 -> V_2 ) ) {
V_33 = F_24 ( V_15 -> V_2 ) ;
return V_33 ;
}
strcpy ( F_25 ( V_5 ) , L_10 ) ;
strcpy ( F_26 ( V_5 ) , V_43 ) ;
return 0 ;
}
static int F_27 ( struct V_4 * V_5 )
{
struct V_14 * V_15 ;
V_15 = F_7 ( V_5 ) ;
F_28 ( V_15 -> V_2 ) ;
return 0 ;
}
