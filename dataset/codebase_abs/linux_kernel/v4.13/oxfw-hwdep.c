static long F_1 ( struct V_1 * V_2 , char T_1 * V_3 , long V_4 ,
T_2 * V_5 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
F_2 ( V_9 ) ;
union V_10 V_11 ;
F_3 ( & V_7 -> V_12 ) ;
while ( ! V_7 -> V_13 ) {
F_4 ( & V_7 -> V_14 , & V_9 , V_15 ) ;
F_5 ( & V_7 -> V_12 ) ;
F_6 () ;
F_7 ( & V_7 -> V_14 , & V_9 ) ;
if ( F_8 ( V_16 ) )
return - V_17 ;
F_3 ( & V_7 -> V_12 ) ;
}
memset ( & V_11 , 0 , sizeof( V_11 ) ) ;
if ( V_7 -> V_13 ) {
V_11 . V_18 . type = V_19 ;
V_11 . V_18 . V_20 = ( V_7 -> V_21 > 0 ) ;
V_7 -> V_13 = false ;
V_4 = F_9 ( long , V_4 , sizeof( V_11 . V_18 ) ) ;
}
F_5 ( & V_7 -> V_12 ) ;
if ( F_10 ( V_3 , & V_11 , V_4 ) )
return - V_22 ;
return V_4 ;
}
static unsigned int F_11 ( struct V_1 * V_2 , struct V_23 * V_23 ,
T_3 * V_9 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
unsigned int V_24 ;
F_12 ( V_23 , & V_7 -> V_14 , V_9 ) ;
F_3 ( & V_7 -> V_12 ) ;
if ( V_7 -> V_13 )
V_24 = V_25 | V_26 ;
else
V_24 = 0 ;
F_5 ( & V_7 -> V_12 ) ;
return V_24 ;
}
static int F_13 ( struct V_6 * V_7 , void T_1 * V_27 )
{
struct V_28 * V_29 = F_14 ( V_7 -> V_30 ) ;
struct V_31 V_32 ;
memset ( & V_32 , 0 , sizeof( V_32 ) ) ;
V_32 . type = V_33 ;
V_32 . V_34 = V_29 -> V_34 -> V_35 ;
* ( V_36 * ) & V_32 . V_37 [ 0 ] = F_15 ( V_29 -> V_38 [ 3 ] ) ;
* ( V_36 * ) & V_32 . V_37 [ 4 ] = F_15 ( V_29 -> V_38 [ 4 ] ) ;
F_16 ( V_32 . V_39 , F_17 ( & V_29 -> V_40 ) ,
sizeof( V_32 . V_39 ) ) ;
if ( F_10 ( V_27 , & V_32 , sizeof( V_32 ) ) )
return - V_22 ;
return 0 ;
}
static int F_18 ( struct V_6 * V_7 )
{
int V_41 ;
F_3 ( & V_7 -> V_12 ) ;
if ( V_7 -> V_21 == 0 ) {
V_7 -> V_21 = - 1 ;
V_41 = 0 ;
} else {
V_41 = - V_42 ;
}
F_5 ( & V_7 -> V_12 ) ;
return V_41 ;
}
static int F_19 ( struct V_6 * V_7 )
{
int V_41 ;
F_3 ( & V_7 -> V_12 ) ;
if ( V_7 -> V_21 == - 1 ) {
V_7 -> V_21 = 0 ;
V_41 = 0 ;
} else {
V_41 = - V_43 ;
}
F_5 ( & V_7 -> V_12 ) ;
return V_41 ;
}
static int F_20 ( struct V_1 * V_2 , struct V_23 * V_23 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
F_3 ( & V_7 -> V_12 ) ;
if ( V_7 -> V_21 == - 1 )
V_7 -> V_21 = 0 ;
F_5 ( & V_7 -> V_12 ) ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 , struct V_23 * V_23 ,
unsigned int V_44 , unsigned long V_27 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
switch ( V_44 ) {
case V_45 :
return F_13 ( V_7 , ( void T_1 * ) V_27 ) ;
case V_46 :
return F_18 ( V_7 ) ;
case V_47 :
return F_19 ( V_7 ) ;
default:
return - V_48 ;
}
}
static int F_22 ( struct V_1 * V_2 , struct V_23 * V_23 ,
unsigned int V_44 , unsigned long V_27 )
{
return F_21 ( V_2 , V_23 , V_44 ,
( unsigned long ) F_23 ( V_27 ) ) ;
}
int F_24 ( struct V_6 * V_7 )
{
static const struct V_49 V_50 = {
. V_51 = F_1 ,
. V_52 = F_20 ,
. V_53 = F_11 ,
. V_54 = F_21 ,
. V_55 = F_22 ,
} ;
struct V_1 * V_2 ;
int V_41 ;
V_41 = F_25 ( V_7 -> V_34 , V_7 -> V_34 -> V_56 , 0 , & V_2 ) ;
if ( V_41 < 0 )
goto V_57;
strcpy ( V_2 -> V_58 , V_7 -> V_34 -> V_56 ) ;
V_2 -> V_59 = V_60 ;
V_2 -> V_61 = V_50 ;
V_2 -> V_8 = V_7 ;
V_2 -> V_62 = true ;
V_57:
return V_41 ;
}
