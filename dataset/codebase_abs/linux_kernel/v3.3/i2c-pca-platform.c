static int F_1 ( void * V_1 , int V_2 )
{
struct V_3 * V_4 = V_1 ;
return F_2 ( V_4 -> V_5 + V_2 ) ;
}
static int F_3 ( void * V_1 , int V_2 )
{
struct V_3 * V_4 = V_1 ;
return F_2 ( V_4 -> V_5 + V_2 * 2 ) ;
}
static int F_4 ( void * V_1 , int V_2 )
{
struct V_3 * V_4 = V_1 ;
return F_2 ( V_4 -> V_5 + V_2 * 4 ) ;
}
static void F_5 ( void * V_1 , int V_2 , int V_6 )
{
struct V_3 * V_4 = V_1 ;
F_6 ( V_6 , V_4 -> V_5 + V_2 ) ;
}
static void F_7 ( void * V_1 , int V_2 , int V_6 )
{
struct V_3 * V_4 = V_1 ;
F_6 ( V_6 , V_4 -> V_5 + V_2 * 2 ) ;
}
static void F_8 ( void * V_1 , int V_2 , int V_6 )
{
struct V_3 * V_4 = V_1 ;
F_6 ( V_6 , V_4 -> V_5 + V_2 * 4 ) ;
}
static int F_9 ( void * V_1 )
{
struct V_3 * V_4 = V_1 ;
unsigned long V_7 ;
long V_8 ;
if ( V_4 -> V_9 ) {
V_8 = F_10 ( V_4 -> V_10 ,
V_4 -> V_11 . V_12 ( V_4 , V_13 )
& V_14 , V_4 -> V_15 . V_7 ) ;
} else {
V_7 = V_16 + V_4 -> V_15 . V_7 ;
do {
V_8 = F_11 ( V_16 , V_7 ) ;
if ( V_4 -> V_11 . V_12 ( V_4 , V_13 )
& V_14 )
break;
F_12 ( 100 ) ;
} while ( V_8 );
}
return V_8 > 0 ;
}
static void F_13 ( void * V_1 )
{
struct V_3 * V_4 = V_1 ;
F_14 ( V_17 L_1 ,
V_4 -> V_15 . V_18 ) ;
}
static void F_15 ( void * V_1 )
{
struct V_3 * V_4 = V_1 ;
F_16 ( V_4 -> V_19 , 0 ) ;
F_17 ( 100 ) ;
F_16 ( V_4 -> V_19 , 1 ) ;
}
static T_1 F_18 ( int V_20 , void * V_21 )
{
struct V_3 * V_4 = V_21 ;
if ( ( V_4 -> V_11 . V_12 ( V_4 , V_13 ) & V_14 ) == 0 )
return V_22 ;
F_19 ( & V_4 -> V_10 ) ;
return V_23 ;
}
static int T_2 F_20 ( struct V_24 * V_25 )
{
struct V_3 * V_4 ;
struct V_26 * V_27 ;
struct V_28 * V_29 =
V_25 -> V_30 . V_29 ;
int V_8 = 0 ;
int V_9 ;
V_27 = F_21 ( V_25 , V_31 , 0 ) ;
V_9 = F_22 ( V_25 , 0 ) ;
if ( V_27 == NULL ) {
V_8 = - V_32 ;
goto V_33;
}
if ( ! F_23 ( V_27 -> V_34 , F_24 ( V_27 ) , V_27 -> V_18 ) ) {
V_8 = - V_35 ;
goto V_33;
}
V_4 = F_25 ( sizeof( struct V_3 ) , V_36 ) ;
if ( ! V_4 ) {
V_8 = - V_35 ;
goto V_37;
}
F_26 ( & V_4 -> V_10 ) ;
V_4 -> V_5 = F_27 ( V_27 -> V_34 , F_24 ( V_27 ) ) ;
if ( ! V_4 -> V_5 ) {
V_8 = - V_35 ;
goto V_38;
}
V_4 -> V_39 = V_27 -> V_34 ;
V_4 -> V_40 = F_24 ( V_27 ) ;
V_4 -> V_9 = V_9 ;
V_4 -> V_15 . V_41 = V_25 -> V_42 >= 0 ? V_25 -> V_42 : 0 ;
V_4 -> V_15 . V_43 = V_44 ;
snprintf ( V_4 -> V_15 . V_18 , sizeof( V_4 -> V_15 . V_18 ) ,
L_2 ,
( unsigned long ) V_27 -> V_34 ) ;
V_4 -> V_15 . V_11 = & V_4 -> V_11 ;
V_4 -> V_15 . V_30 . V_45 = & V_25 -> V_30 ;
if ( V_29 ) {
V_4 -> V_15 . V_7 = V_29 -> V_7 ;
V_4 -> V_11 . V_46 = V_29 -> V_47 ;
V_4 -> V_19 = V_29 -> V_19 ;
} else {
V_4 -> V_15 . V_7 = V_48 ;
V_4 -> V_11 . V_46 = 59000 ;
V_4 -> V_19 = - 1 ;
}
V_4 -> V_11 . V_49 = V_4 ;
V_4 -> V_11 . V_50 = F_9 ;
V_4 -> V_11 . V_51 = F_13 ;
switch ( V_27 -> V_52 & V_53 ) {
case V_54 :
V_4 -> V_11 . V_55 = F_8 ;
V_4 -> V_11 . V_12 = F_4 ;
break;
case V_56 :
V_4 -> V_11 . V_55 = F_7 ;
V_4 -> V_11 . V_12 = F_3 ;
break;
case V_57 :
default:
V_4 -> V_11 . V_55 = F_5 ;
V_4 -> V_11 . V_12 = F_1 ;
break;
}
if ( V_4 -> V_19 > - 1 ) {
V_8 = F_28 ( V_4 -> V_19 , V_4 -> V_15 . V_18 ) ;
if ( V_8 == 0 ) {
F_29 ( V_4 -> V_19 , 1 ) ;
V_4 -> V_11 . V_51 = F_15 ;
} else {
F_14 ( V_17 L_3 ,
V_4 -> V_15 . V_18 ) ;
V_4 -> V_19 = V_8 ;
}
}
if ( V_9 ) {
V_8 = F_30 ( V_9 , F_18 ,
V_58 , V_25 -> V_18 , V_4 ) ;
if ( V_8 )
goto V_59;
}
if ( F_31 ( & V_4 -> V_15 ) < 0 ) {
V_8 = - V_32 ;
goto V_60;
}
F_32 ( V_25 , V_4 ) ;
F_14 ( V_61 L_4 , V_4 -> V_15 . V_18 ) ;
return 0 ;
V_60:
if ( V_9 )
F_33 ( V_9 , V_4 ) ;
V_59:
if ( V_4 -> V_19 > - 1 )
F_34 ( V_4 -> V_19 ) ;
F_35 ( V_4 -> V_5 ) ;
V_38:
F_36 ( V_4 ) ;
V_37:
F_37 ( V_27 -> V_34 , F_24 ( V_27 ) ) ;
V_33:
F_14 ( V_62 L_5 , V_8 ) ;
return V_8 ;
}
static int T_3 F_38 ( struct V_24 * V_25 )
{
struct V_3 * V_4 = F_39 ( V_25 ) ;
F_32 ( V_25 , NULL ) ;
F_40 ( & V_4 -> V_15 ) ;
if ( V_4 -> V_9 )
F_33 ( V_4 -> V_9 , V_4 ) ;
if ( V_4 -> V_19 > - 1 )
F_34 ( V_4 -> V_19 ) ;
F_35 ( V_4 -> V_5 ) ;
F_37 ( V_4 -> V_39 , V_4 -> V_40 ) ;
F_36 ( V_4 ) ;
return 0 ;
}
