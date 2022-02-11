static long F_1 ( struct V_1 * V_2 , char T_1 * V_3 , long V_4 ,
T_2 * V_5 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
F_2 ( V_9 ) ;
union V_10 V_11 ;
F_3 ( & V_7 -> V_12 ) ;
while ( ! V_7 -> V_13 && V_7 -> V_14 == 0 ) {
F_4 ( & V_7 -> V_15 , & V_9 , V_16 ) ;
F_5 ( & V_7 -> V_12 ) ;
F_6 () ;
F_7 ( & V_7 -> V_15 , & V_9 ) ;
if ( F_8 ( V_17 ) )
return - V_18 ;
F_3 ( & V_7 -> V_12 ) ;
}
memset ( & V_11 , 0 , sizeof( V_11 ) ) ;
if ( V_7 -> V_13 ) {
V_11 . V_19 . type = V_20 ;
V_11 . V_19 . V_21 = ( V_7 -> V_22 > 0 ) ;
V_7 -> V_13 = false ;
V_4 = F_9 ( long , V_4 , sizeof( V_11 . V_19 ) ) ;
} else {
V_11 . V_23 . type = V_24 ;
V_11 . V_23 . V_25 = V_7 -> V_14 ;
V_7 -> V_14 = 0 ;
V_4 = F_9 ( long , V_4 , sizeof( V_11 . V_23 ) ) ;
}
F_5 ( & V_7 -> V_12 ) ;
if ( F_10 ( V_3 , & V_11 , V_4 ) )
return - V_26 ;
return V_4 ;
}
static unsigned int F_11 ( struct V_1 * V_2 , struct V_27 * V_27 ,
T_3 * V_9 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
unsigned int V_28 ;
F_12 ( V_27 , & V_7 -> V_15 , V_9 ) ;
F_3 ( & V_7 -> V_12 ) ;
if ( V_7 -> V_13 || V_7 -> V_14 )
V_28 = V_29 | V_30 ;
else
V_28 = 0 ;
F_5 ( & V_7 -> V_12 ) ;
return V_28 | V_31 ;
}
static int F_13 ( struct V_6 * V_7 , void T_1 * V_32 )
{
struct V_33 * V_34 = F_14 ( V_7 -> V_35 ) ;
struct V_36 V_37 ;
memset ( & V_37 , 0 , sizeof( V_37 ) ) ;
V_37 . type = V_38 ;
V_37 . V_39 = V_34 -> V_39 -> V_40 ;
* ( V_41 * ) & V_37 . V_42 [ 0 ] = F_15 ( V_34 -> V_43 [ 3 ] ) ;
* ( V_41 * ) & V_37 . V_42 [ 4 ] = F_15 ( V_34 -> V_43 [ 4 ] ) ;
F_16 ( V_37 . V_44 , F_17 ( & V_34 -> V_45 ) ,
sizeof( V_37 . V_44 ) ) ;
if ( F_10 ( V_32 , & V_37 , sizeof( V_37 ) ) )
return - V_26 ;
return 0 ;
}
static int F_18 ( struct V_6 * V_7 )
{
int V_46 ;
F_3 ( & V_7 -> V_12 ) ;
if ( V_7 -> V_22 == 0 ) {
V_7 -> V_22 = - 1 ;
V_46 = 0 ;
} else {
V_46 = - V_47 ;
}
F_5 ( & V_7 -> V_12 ) ;
return V_46 ;
}
static int F_19 ( struct V_6 * V_7 )
{
int V_46 ;
F_3 ( & V_7 -> V_12 ) ;
if ( V_7 -> V_22 == - 1 ) {
V_7 -> V_22 = 0 ;
V_46 = 0 ;
} else {
V_46 = - V_48 ;
}
F_5 ( & V_7 -> V_12 ) ;
return V_46 ;
}
static int F_20 ( struct V_1 * V_2 , struct V_27 * V_27 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
F_3 ( & V_7 -> V_12 ) ;
if ( V_7 -> V_22 == - 1 )
V_7 -> V_22 = 0 ;
F_5 ( & V_7 -> V_12 ) ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 , struct V_27 * V_27 ,
unsigned int V_49 , unsigned long V_32 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
switch ( V_49 ) {
case V_50 :
return F_13 ( V_7 , ( void T_1 * ) V_32 ) ;
case V_51 :
return F_18 ( V_7 ) ;
case V_52 :
return F_19 ( V_7 ) ;
default:
return - V_53 ;
}
}
static int F_22 ( struct V_1 * V_2 , struct V_27 * V_27 ,
unsigned int V_49 , unsigned long V_32 )
{
return F_21 ( V_2 , V_27 , V_49 ,
( unsigned long ) F_23 ( V_32 ) ) ;
}
int F_24 ( struct V_6 * V_7 )
{
static const struct V_54 V_55 = {
. V_56 = F_1 ,
. V_57 = F_20 ,
. V_58 = F_11 ,
. V_59 = F_21 ,
. V_60 = F_22 ,
} ;
struct V_1 * V_2 ;
int V_46 ;
V_46 = F_25 ( V_7 -> V_39 , V_7 -> V_39 -> V_61 , 0 , & V_2 ) ;
if ( V_46 < 0 )
return V_46 ;
strcpy ( V_2 -> V_62 , L_1 ) ;
V_2 -> V_63 = V_64 ;
V_2 -> V_55 = V_55 ;
V_2 -> V_8 = V_7 ;
V_2 -> V_65 = true ;
return 0 ;
}
