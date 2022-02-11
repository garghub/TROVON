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
F_14 ( & V_4 -> V_15 . V_17 , L_1 ) ;
}
static void F_15 ( void * V_1 )
{
struct V_3 * V_4 = V_1 ;
F_16 ( V_4 -> V_18 , 1 ) ;
F_17 ( 100 ) ;
F_16 ( V_4 -> V_18 , 0 ) ;
}
static T_1 F_18 ( int V_19 , void * V_20 )
{
struct V_3 * V_4 = V_20 ;
if ( ( V_4 -> V_11 . V_12 ( V_4 , V_13 ) & V_14 ) == 0 )
return V_21 ;
F_19 ( & V_4 -> V_10 ) ;
return V_22 ;
}
static int F_20 ( struct V_23 * V_24 )
{
struct V_3 * V_4 ;
struct V_25 * V_26 ;
struct V_27 * V_28 =
F_21 ( & V_24 -> V_17 ) ;
struct V_29 * V_30 = V_24 -> V_17 . V_31 ;
int V_8 = 0 ;
int V_9 ;
V_9 = F_22 ( V_24 , 0 ) ;
if ( V_9 < 0 )
V_9 = 0 ;
V_4 = F_23 ( & V_24 -> V_17 , sizeof( * V_4 ) , V_32 ) ;
if ( ! V_4 )
return - V_33 ;
V_26 = F_24 ( V_24 , V_34 , 0 ) ;
V_4 -> V_5 = F_25 ( & V_24 -> V_17 , V_26 ) ;
if ( F_26 ( V_4 -> V_5 ) )
return F_27 ( V_4 -> V_5 ) ;
F_28 ( & V_4 -> V_10 ) ;
V_4 -> V_35 = V_26 -> V_36 ;
V_4 -> V_37 = F_29 ( V_26 ) ;
V_4 -> V_9 = V_9 ;
V_4 -> V_15 . V_38 = V_24 -> V_39 ;
V_4 -> V_15 . V_40 = V_41 ;
snprintf ( V_4 -> V_15 . V_42 , sizeof( V_4 -> V_15 . V_42 ) ,
L_2 ,
( unsigned long ) V_26 -> V_36 ) ;
V_4 -> V_15 . V_11 = & V_4 -> V_11 ;
V_4 -> V_15 . V_17 . V_43 = & V_24 -> V_17 ;
V_4 -> V_15 . V_17 . V_31 = V_30 ;
if ( V_28 ) {
V_4 -> V_15 . V_7 = V_28 -> V_7 ;
V_4 -> V_11 . V_44 = V_28 -> V_45 ;
if ( F_30 ( V_28 -> V_18 ) ) {
V_8 = F_31 ( & V_24 -> V_17 ,
V_28 -> V_18 ,
V_46 ,
V_4 -> V_15 . V_42 ) ;
if ( V_8 == 0 ) {
V_4 -> V_18 = F_32 ( V_28 -> V_18 ) ;
F_33 ( V_4 -> V_18 , 0 ) ;
} else {
F_14 ( & V_24 -> V_17 , L_3 ) ;
V_4 -> V_18 = NULL ;
}
}
} else if ( V_30 ) {
V_4 -> V_15 . V_7 = V_47 ;
V_4 -> V_18 = F_34 ( & V_24 -> V_17 , L_4 , V_48 ) ;
if ( F_26 ( V_4 -> V_18 ) )
return F_27 ( V_4 -> V_18 ) ;
F_35 ( V_30 , L_5 , 0 ,
& V_4 -> V_11 . V_44 ) ;
} else {
V_4 -> V_15 . V_7 = V_47 ;
V_4 -> V_11 . V_44 = 59000 ;
V_4 -> V_18 = NULL ;
}
V_4 -> V_11 . V_49 = V_4 ;
V_4 -> V_11 . V_50 = F_9 ;
if ( V_4 -> V_18 )
V_4 -> V_11 . V_51 = F_15 ;
else
V_4 -> V_11 . V_51 = F_13 ;
switch ( V_26 -> V_52 & V_53 ) {
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
if ( V_9 ) {
V_8 = F_36 ( & V_24 -> V_17 , V_9 , F_18 ,
V_58 , V_24 -> V_42 , V_4 ) ;
if ( V_8 )
return V_8 ;
}
V_8 = F_37 ( & V_4 -> V_15 ) ;
if ( V_8 )
return V_8 ;
F_38 ( V_24 , V_4 ) ;
F_39 ( & V_24 -> V_17 , L_6 ) ;
return 0 ;
}
static int F_40 ( struct V_23 * V_24 )
{
struct V_3 * V_4 = F_41 ( V_24 ) ;
F_42 ( & V_4 -> V_15 ) ;
return 0 ;
}
