static int F_1 ( struct V_1 * V_2 ,
unsigned long * V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_7 * V_8 = V_5 -> V_9 ;
unsigned long long V_10 ;
T_1 V_11 ;
V_11 = F_2 ( V_8 -> V_12 , L_1 , NULL , & V_10 ) ;
if ( F_3 ( V_11 ) )
return - V_13 ;
* V_3 = F_4 ( V_10 , V_14 ) ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 ,
int V_15 , unsigned long * V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_7 * V_8 = V_5 -> V_9 ;
unsigned long long V_16 ;
T_1 V_11 ;
V_11 = F_2 ( V_8 -> V_12 , L_2 , NULL , & V_16 ) ;
if ( F_3 ( V_11 ) )
return - V_13 ;
* V_3 = V_16 * 100 ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 ,
int V_15 , unsigned long * V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_17 * V_18 = V_5 -> V_5 ;
if ( V_5 -> type != V_19 || ! V_18 )
return - V_20 ;
if ( V_15 == V_18 -> V_21 )
* V_3 = V_18 -> V_22 ;
else if ( V_15 == V_18 -> V_23 )
* V_3 = V_18 -> V_24 ;
else {
* V_3 = V_18 -> V_25 [ V_15 ] ;
}
return 0 ;
}
static int F_7 ( struct V_1 * V_26 ,
int V_15 , enum V_27 * type )
{
struct V_4 * V_5 = V_26 -> V_6 ;
struct V_17 * V_18 = V_5 -> V_5 ;
if ( V_15 == V_18 -> V_21 )
* type = V_28 ;
else
* type = V_29 ;
return 0 ;
}
int F_8 ( struct V_1 * V_2 , int V_15 ,
unsigned long V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_7 * V_8 = V_5 -> V_9 ;
struct V_17 * V_18 = V_5 -> V_5 ;
T_1 V_11 ;
char V_30 [ 10 ] ;
int V_31 = 0 ;
snprintf ( V_30 , sizeof( V_30 ) , L_3 , V_15 ) ;
if ( F_9 ( V_8 -> V_12 , V_30 ) ) {
V_11 = F_10 ( V_8 -> V_12 , V_30 ,
F_11 ( V_3 ,
V_14 ) ) ;
if ( F_3 ( V_11 ) )
V_31 = - V_13 ;
else
V_18 -> V_25 [ V_15 ] = V_3 ;
} else {
V_31 = - V_13 ;
F_12 ( & V_8 -> V_32 , L_4 ) ;
}
return V_31 ;
}
static void F_13 ( T_2 V_12 ,
T_3 V_33 , void * V_34 )
{
struct V_4 * V_5 = V_34 ;
struct V_17 * V_18 ;
if ( ! V_5 )
return;
V_18 = V_5 -> V_5 ;
if ( V_5 -> type != V_19 || ! V_18 )
return;
switch ( V_33 ) {
case V_35 :
break;
case V_36 :
F_14 ( V_18 -> V_2 ) ;
break;
default:
F_12 ( & V_5 -> V_37 -> V_32 , L_5 , V_33 ) ;
break;
}
}
static int F_15 ( struct V_7 * V_8 , unsigned long * V_3 )
{
unsigned long long V_38 ;
T_1 V_11 ;
V_11 = F_2 ( V_8 -> V_12 , L_6 , NULL , & V_38 ) ;
if ( F_3 ( V_11 ) )
return - V_13 ;
* V_3 = F_4 ( V_38 , V_14 ) ;
return 0 ;
}
static int F_16 ( struct V_7 * V_8 , unsigned long * V_3 )
{
unsigned long long V_39 ;
T_1 V_11 ;
V_11 = F_2 ( V_8 -> V_12 , L_7 , NULL , & V_39 ) ;
if ( F_3 ( V_11 ) )
return - V_13 ;
* V_3 = F_4 ( V_39 , V_14 ) ;
return 0 ;
}
static int F_17 ( struct V_4 * V_5 )
{
int V_40 = 0 ;
T_1 V_11 ;
struct V_17 * V_18 ;
unsigned long long V_41 ;
int V_42 = 0 ;
V_18 = F_18 ( & V_5 -> V_37 -> V_32 , sizeof( * V_18 ) , V_43 ) ;
if ( ! V_18 )
return - V_44 ;
V_5 -> V_5 = V_18 ;
V_11 = F_2 ( V_5 -> V_9 -> V_12 , L_8 , NULL ,
& V_41 ) ;
if ( F_3 ( V_11 ) )
V_41 = 0 ;
if ( V_41 ) {
V_18 -> V_25 = F_18 ( & V_5 -> V_37 -> V_32 ,
sizeof( * V_18 -> V_25 ) * V_41 ,
V_43 ) ;
if ( ! V_18 -> V_25 ) {
V_40 = - V_44 ;
goto V_45;
}
V_42 = F_19 ( V_41 ) - 1 ;
}
V_18 -> V_23 = - 1 ;
if ( ! F_16 ( V_5 -> V_9 , & V_18 -> V_24 ) )
V_18 -> V_23 = V_41 ++ ;
V_18 -> V_21 = - 1 ;
if ( ! F_15 ( V_5 -> V_9 , & V_18 -> V_22 ) )
V_18 -> V_21 = V_41 ++ ;
V_18 -> V_2 = F_20 ( F_21 ( V_5 -> V_9 ) ,
V_41 , V_42 , V_5 , & V_46 ,
& V_47 , 0 , 0 ) ;
if ( F_22 ( V_18 -> V_2 ) ) {
V_40 = F_23 ( V_18 -> V_2 ) ;
V_18 -> V_2 = NULL ;
goto V_45;
}
V_40 = F_24 ( V_5 -> V_9 -> V_12 ,
V_48 , F_13 ,
( void * ) V_5 ) ;
if ( V_40 )
goto V_45;
return 0 ;
V_45:
if ( V_18 -> V_2 )
F_25 ( V_18 -> V_2 ) ;
return V_40 ;
}
static int F_26 ( struct V_4 * V_5 )
{
struct V_17 * V_18 = V_5 -> V_5 ;
F_25 ( V_18 -> V_2 ) ;
return 0 ;
}
static int F_27 ( struct V_49 * V_50 ,
unsigned long * V_51 )
{
struct V_4 * V_5 = V_50 -> V_6 ;
struct V_52 * V_18 = V_5 -> V_5 ;
* V_51 = V_18 -> V_53 ;
return 0 ;
}
static int F_28 ( struct V_49 * V_50 ,
unsigned long * V_51 )
{
struct V_4 * V_5 = V_50 -> V_6 ;
unsigned long long V_54 ;
T_1 V_11 ;
V_11 = F_2 ( V_5 -> V_9 -> V_12 , L_9 , NULL , & V_54 ) ;
if ( F_29 ( V_11 ) ) {
* V_51 = V_54 ;
return 0 ;
} else
return - V_20 ;
}
static int
F_30 ( struct V_49 * V_50 , unsigned long V_51 )
{
struct V_4 * V_5 = V_50 -> V_6 ;
T_1 V_11 ;
V_11 = F_10 ( V_5 -> V_9 -> V_12 , L_10 , V_51 ) ;
if ( F_29 ( V_11 ) )
return 0 ;
else
return - V_20 ;
}
static int F_31 ( struct V_4 * V_5 )
{
int V_40 = 0 ;
T_1 V_11 ;
struct V_52 * V_18 ;
struct V_55 V_56 = { V_57 , NULL } ;
union V_58 * V_59 ;
V_18 = F_18 ( & V_5 -> V_37 -> V_32 , sizeof( * V_18 ) , V_43 ) ;
if ( ! V_18 )
return - V_44 ;
V_11 = F_32 ( V_5 -> V_9 -> V_12 , L_11 , NULL , & V_56 ) ;
if ( F_3 ( V_11 ) )
return - V_60 ;
V_59 = V_56 . V_61 ;
if ( ! V_59 || ( V_59 -> type != V_62 ) ) {
F_33 ( V_63 L_12 ) ;
return - V_64 ;
}
V_18 -> V_53 = V_59 -> V_65 . V_66 - 1 ;
V_18 -> V_50 =
F_34 ( F_21 ( V_5 -> V_9 ) ,
V_5 , & V_67 ) ;
if ( F_22 ( V_18 -> V_50 ) )
V_40 = F_23 ( V_18 -> V_50 ) ;
V_5 -> V_5 = V_18 ;
return V_40 ;
}
static int F_35 ( struct V_4 * V_5 )
{
struct V_52 * V_18 = V_5 -> V_5 ;
F_36 ( V_18 -> V_50 ) ;
return 0 ;
}
static int F_37 ( struct V_68 * V_37 )
{
struct V_4 * V_5 ;
int V_40 = 0 ;
T_1 V_11 ;
V_5 = F_18 ( & V_37 -> V_32 , sizeof( struct V_4 ) ,
V_43 ) ;
if ( ! V_5 )
return - V_44 ;
V_5 -> V_37 = V_37 ;
V_5 -> V_9 = F_38 ( & ( V_37 -> V_32 ) ) ;
if ( ! V_5 -> V_9 ) {
V_40 = - V_20 ;
goto V_69;
}
V_11 = F_2 ( V_5 -> V_9 -> V_12 , L_13 ,
NULL , & V_5 -> type ) ;
if ( F_3 ( V_11 ) ) {
V_40 = - V_20 ;
goto V_69;
}
F_39 ( V_37 , V_5 ) ;
switch ( V_5 -> type ) {
case V_19 :
V_40 = F_17 ( V_5 ) ;
break;
case V_70 :
case V_71 :
V_40 = F_31 ( V_5 ) ;
break;
default:
V_40 = - V_20 ;
}
if ( V_40 )
goto V_69;
return V_40 ;
V_69:
return V_40 ;
}
static int F_40 ( struct V_68 * V_37 )
{
struct V_4 * V_5 = F_41 ( V_37 ) ;
switch ( V_5 -> type ) {
case V_19 :
F_26 ( V_5 ) ;
break;
case V_70 :
case V_71 :
F_35 ( V_5 ) ;
break;
default:
break;
}
return 0 ;
}
