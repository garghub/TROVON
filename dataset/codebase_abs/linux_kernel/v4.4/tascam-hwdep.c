static long F_1 ( struct V_1 * V_2 , char T_1 * V_3 ,
long V_4 )
{
union V_5 V_6 ;
memset ( & V_6 , 0 , sizeof( V_6 ) ) ;
V_6 . V_7 . type = V_8 ;
V_6 . V_7 . V_9 = ( V_2 -> V_10 > 0 ) ;
V_2 -> V_11 = false ;
V_4 = F_2 ( long , V_4 , sizeof( V_6 . V_7 ) ) ;
if ( F_3 ( V_3 , & V_6 , V_4 ) )
return - V_12 ;
return V_4 ;
}
static long F_4 ( struct V_13 * V_14 , char T_1 * V_3 , long V_4 ,
T_2 * V_15 )
{
struct V_1 * V_2 = V_14 -> V_16 ;
F_5 ( V_17 ) ;
union V_5 V_6 ;
F_6 ( & V_2 -> V_18 ) ;
while ( ! V_2 -> V_11 ) {
F_7 ( & V_2 -> V_19 , & V_17 , V_20 ) ;
F_8 ( & V_2 -> V_18 ) ;
F_9 () ;
F_10 ( & V_2 -> V_19 , & V_17 ) ;
if ( F_11 ( V_21 ) )
return - V_22 ;
F_6 ( & V_2 -> V_18 ) ;
}
memset ( & V_6 , 0 , sizeof( V_6 ) ) ;
V_4 = F_1 ( V_2 , V_3 , V_4 ) ;
F_8 ( & V_2 -> V_18 ) ;
return V_4 ;
}
static unsigned int F_12 ( struct V_13 * V_14 , struct V_23 * V_23 ,
T_3 * V_17 )
{
struct V_1 * V_2 = V_14 -> V_16 ;
unsigned int V_24 ;
F_13 ( V_23 , & V_2 -> V_19 , V_17 ) ;
F_6 ( & V_2 -> V_18 ) ;
if ( V_2 -> V_11 )
V_24 = V_25 | V_26 ;
else
V_24 = 0 ;
F_8 ( & V_2 -> V_18 ) ;
return V_24 ;
}
static int F_14 ( struct V_1 * V_2 , void T_1 * V_27 )
{
struct V_28 * V_29 = F_15 ( V_2 -> V_30 ) ;
struct V_31 V_32 ;
memset ( & V_32 , 0 , sizeof( V_32 ) ) ;
V_32 . type = V_33 ;
V_32 . V_34 = V_29 -> V_34 -> V_35 ;
* ( V_36 * ) & V_32 . V_37 [ 0 ] = F_16 ( V_29 -> V_38 [ 3 ] ) ;
* ( V_36 * ) & V_32 . V_37 [ 4 ] = F_16 ( V_29 -> V_38 [ 4 ] ) ;
F_17 ( V_32 . V_39 , F_18 ( & V_29 -> V_40 ) ,
sizeof( V_32 . V_39 ) ) ;
if ( F_3 ( V_27 , & V_32 , sizeof( V_32 ) ) )
return - V_12 ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 )
{
int V_41 ;
F_6 ( & V_2 -> V_18 ) ;
if ( V_2 -> V_10 == 0 ) {
V_2 -> V_10 = - 1 ;
V_41 = 0 ;
} else {
V_41 = - V_42 ;
}
F_8 ( & V_2 -> V_18 ) ;
return V_41 ;
}
static int F_20 ( struct V_1 * V_2 )
{
int V_41 ;
F_6 ( & V_2 -> V_18 ) ;
if ( V_2 -> V_10 == - 1 ) {
V_2 -> V_10 = 0 ;
V_41 = 0 ;
} else {
V_41 = - V_43 ;
}
F_8 ( & V_2 -> V_18 ) ;
return V_41 ;
}
static int F_21 ( struct V_13 * V_14 , struct V_23 * V_23 )
{
struct V_1 * V_2 = V_14 -> V_16 ;
F_6 ( & V_2 -> V_18 ) ;
if ( V_2 -> V_10 == - 1 )
V_2 -> V_10 = 0 ;
F_8 ( & V_2 -> V_18 ) ;
return 0 ;
}
static int F_22 ( struct V_13 * V_14 , struct V_23 * V_23 ,
unsigned int V_44 , unsigned long V_27 )
{
struct V_1 * V_2 = V_14 -> V_16 ;
switch ( V_44 ) {
case V_45 :
return F_14 ( V_2 , ( void T_1 * ) V_27 ) ;
case V_46 :
return F_19 ( V_2 ) ;
case V_47 :
return F_20 ( V_2 ) ;
default:
return - V_48 ;
}
}
static int F_23 ( struct V_13 * V_14 , struct V_23 * V_23 ,
unsigned int V_44 , unsigned long V_27 )
{
return F_22 ( V_14 , V_23 , V_44 ,
( unsigned long ) F_24 ( V_27 ) ) ;
}
int F_25 ( struct V_1 * V_2 )
{
struct V_13 * V_14 ;
int V_41 ;
V_41 = F_26 ( V_2 -> V_34 , L_1 , 0 , & V_14 ) ;
if ( V_41 < 0 )
return V_41 ;
strcpy ( V_14 -> V_49 , L_1 ) ;
V_14 -> V_50 = V_51 ;
V_14 -> V_52 = V_53 ;
V_14 -> V_16 = V_2 ;
V_14 -> V_54 = true ;
return V_41 ;
}
