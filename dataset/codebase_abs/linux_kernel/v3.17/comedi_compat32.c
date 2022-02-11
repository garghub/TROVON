static int F_1 ( struct V_1 * V_1 , unsigned int V_2 ,
unsigned long V_3 )
{
if ( V_1 -> V_4 -> V_5 )
return V_1 -> V_4 -> V_5 ( V_1 , V_2 , V_3 ) ;
return - V_6 ;
}
static int F_2 ( struct V_1 * V_1 , unsigned long V_3 )
{
struct V_7 T_1 * V_8 ;
struct V_9 T_1 * V_10 ;
int V_11 ;
union {
unsigned int V_12 ;
T_2 V_13 ;
} V_14 ;
V_10 = F_3 ( V_3 ) ;
V_8 = F_4 ( sizeof( * V_8 ) ) ;
if ( ! F_5 ( V_15 , V_10 , sizeof( * V_10 ) ) ||
! F_5 ( V_16 , V_8 , sizeof( * V_8 ) ) )
return - V_17 ;
V_11 = 0 ;
V_11 |= F_6 ( V_14 . V_12 , & V_10 -> V_18 ) ;
V_11 |= F_7 ( V_14 . V_12 , & V_8 -> V_18 ) ;
V_11 |= F_6 ( V_14 . V_13 , & V_10 -> V_19 ) ;
V_11 |= F_7 ( F_3 ( V_14 . V_13 ) , & V_8 -> V_19 ) ;
V_11 |= F_6 ( V_14 . V_13 , & V_10 -> V_20 ) ;
V_11 |= F_7 ( F_3 ( V_14 . V_13 ) , & V_8 -> V_20 ) ;
V_11 |= F_6 ( V_14 . V_13 , & V_10 -> V_21 ) ;
V_11 |= F_7 ( F_3 ( V_14 . V_13 ) , & V_8 -> V_21 ) ;
if ( V_11 )
return - V_17 ;
return F_1 ( V_1 , V_22 , ( unsigned long ) V_8 ) ;
}
static int F_8 ( struct V_1 * V_1 , unsigned long V_3 )
{
struct V_23 T_1 * V_24 ;
struct V_25 T_1 * V_26 ;
int V_11 ;
union {
unsigned int V_12 ;
T_2 V_13 ;
} V_14 ;
V_26 = F_3 ( V_3 ) ;
V_24 = F_4 ( sizeof( * V_24 ) ) ;
if ( ! F_5 ( V_15 , V_26 , sizeof( * V_26 ) ) ||
! F_5 ( V_16 , V_24 , sizeof( * V_24 ) ) )
return - V_17 ;
V_11 = 0 ;
V_11 |= F_6 ( V_14 . V_12 , & V_26 -> V_27 ) ;
V_11 |= F_7 ( V_14 . V_12 , & V_24 -> V_27 ) ;
V_11 |= F_6 ( V_14 . V_13 , & V_26 -> V_28 ) ;
V_11 |= F_7 ( F_3 ( V_14 . V_13 ) , & V_24 -> V_28 ) ;
if ( V_11 )
return - V_17 ;
return F_1 ( V_1 , V_29 ,
( unsigned long ) V_24 ) ;
}
static int F_9 ( struct V_30 T_1 * V_2 ,
struct V_31 T_1 * V_32 )
{
int V_11 ;
union {
unsigned int V_12 ;
T_2 V_13 ;
} V_14 ;
if ( ! F_5 ( V_15 , V_32 , sizeof( * V_32 ) ) ||
! F_5 ( V_16 , V_2 , sizeof( * V_2 ) ) )
return - V_17 ;
V_11 = 0 ;
V_11 |= F_6 ( V_14 . V_12 , & V_32 -> V_18 ) ;
V_11 |= F_7 ( V_14 . V_12 , & V_2 -> V_18 ) ;
V_11 |= F_6 ( V_14 . V_12 , & V_32 -> V_33 ) ;
V_11 |= F_7 ( V_14 . V_12 , & V_2 -> V_33 ) ;
V_11 |= F_6 ( V_14 . V_12 , & V_32 -> V_34 ) ;
V_11 |= F_7 ( V_14 . V_12 , & V_2 -> V_34 ) ;
V_11 |= F_6 ( V_14 . V_12 , & V_32 -> V_35 ) ;
V_11 |= F_7 ( V_14 . V_12 , & V_2 -> V_35 ) ;
V_11 |= F_6 ( V_14 . V_12 , & V_32 -> V_36 ) ;
V_11 |= F_7 ( V_14 . V_12 , & V_2 -> V_36 ) ;
V_11 |= F_6 ( V_14 . V_12 , & V_32 -> V_37 ) ;
V_11 |= F_7 ( V_14 . V_12 , & V_2 -> V_37 ) ;
V_11 |= F_6 ( V_14 . V_12 , & V_32 -> V_38 ) ;
V_11 |= F_7 ( V_14 . V_12 , & V_2 -> V_38 ) ;
V_11 |= F_6 ( V_14 . V_12 , & V_32 -> V_39 ) ;
V_11 |= F_7 ( V_14 . V_12 , & V_2 -> V_39 ) ;
V_11 |= F_6 ( V_14 . V_12 , & V_32 -> V_40 ) ;
V_11 |= F_7 ( V_14 . V_12 , & V_2 -> V_40 ) ;
V_11 |= F_6 ( V_14 . V_12 , & V_32 -> V_41 ) ;
V_11 |= F_7 ( V_14 . V_12 , & V_2 -> V_41 ) ;
V_11 |= F_6 ( V_14 . V_12 , & V_32 -> V_42 ) ;
V_11 |= F_7 ( V_14 . V_12 , & V_2 -> V_42 ) ;
V_11 |= F_6 ( V_14 . V_12 , & V_32 -> V_43 ) ;
V_11 |= F_7 ( V_14 . V_12 , & V_2 -> V_43 ) ;
V_11 |= F_6 ( V_14 . V_13 , & V_32 -> V_44 ) ;
V_11 |= F_7 ( F_3 ( V_14 . V_13 ) , & V_2 -> V_44 ) ;
V_11 |= F_6 ( V_14 . V_12 , & V_32 -> V_45 ) ;
V_11 |= F_7 ( V_14 . V_12 , & V_2 -> V_45 ) ;
V_11 |= F_6 ( V_14 . V_13 , & V_32 -> V_46 ) ;
V_11 |= F_7 ( F_3 ( V_14 . V_13 ) , & V_2 -> V_46 ) ;
V_11 |= F_6 ( V_14 . V_12 , & V_32 -> V_47 ) ;
V_11 |= F_7 ( V_14 . V_12 , & V_2 -> V_47 ) ;
return V_11 ? - V_17 : 0 ;
}
static int F_10 ( struct V_31 T_1 * V_32 ,
struct V_30 T_1 * V_2 )
{
int V_11 ;
unsigned int V_14 ;
if ( ! F_5 ( V_15 , V_2 , sizeof( * V_2 ) ) ||
! F_5 ( V_16 , V_32 , sizeof( * V_32 ) ) )
return - V_17 ;
V_11 = 0 ;
V_11 |= F_6 ( V_14 , & V_2 -> V_18 ) ;
V_11 |= F_7 ( V_14 , & V_32 -> V_18 ) ;
V_11 |= F_6 ( V_14 , & V_2 -> V_33 ) ;
V_11 |= F_7 ( V_14 , & V_32 -> V_33 ) ;
V_11 |= F_6 ( V_14 , & V_2 -> V_34 ) ;
V_11 |= F_7 ( V_14 , & V_32 -> V_34 ) ;
V_11 |= F_6 ( V_14 , & V_2 -> V_35 ) ;
V_11 |= F_7 ( V_14 , & V_32 -> V_35 ) ;
V_11 |= F_6 ( V_14 , & V_2 -> V_36 ) ;
V_11 |= F_7 ( V_14 , & V_32 -> V_36 ) ;
V_11 |= F_6 ( V_14 , & V_2 -> V_37 ) ;
V_11 |= F_7 ( V_14 , & V_32 -> V_37 ) ;
V_11 |= F_6 ( V_14 , & V_2 -> V_38 ) ;
V_11 |= F_7 ( V_14 , & V_32 -> V_38 ) ;
V_11 |= F_6 ( V_14 , & V_2 -> V_39 ) ;
V_11 |= F_7 ( V_14 , & V_32 -> V_39 ) ;
V_11 |= F_6 ( V_14 , & V_2 -> V_40 ) ;
V_11 |= F_7 ( V_14 , & V_32 -> V_40 ) ;
V_11 |= F_6 ( V_14 , & V_2 -> V_41 ) ;
V_11 |= F_7 ( V_14 , & V_32 -> V_41 ) ;
V_11 |= F_6 ( V_14 , & V_2 -> V_42 ) ;
V_11 |= F_7 ( V_14 , & V_32 -> V_42 ) ;
V_11 |= F_6 ( V_14 , & V_2 -> V_43 ) ;
V_11 |= F_7 ( V_14 , & V_32 -> V_43 ) ;
V_11 |= F_6 ( V_14 , & V_2 -> V_45 ) ;
V_11 |= F_7 ( V_14 , & V_32 -> V_45 ) ;
V_11 |= F_6 ( V_14 , & V_2 -> V_47 ) ;
V_11 |= F_7 ( V_14 , & V_32 -> V_47 ) ;
return V_11 ? - V_17 : 0 ;
}
static int F_11 ( struct V_1 * V_1 , unsigned long V_3 )
{
struct V_30 T_1 * V_2 ;
struct V_31 T_1 * V_32 ;
int V_48 ;
V_32 = F_3 ( V_3 ) ;
V_2 = F_4 ( sizeof( * V_2 ) ) ;
V_48 = F_9 ( V_2 , V_32 ) ;
if ( V_48 )
return V_48 ;
return F_1 ( V_1 , V_49 , ( unsigned long ) V_2 ) ;
}
static int F_12 ( struct V_1 * V_1 , unsigned long V_3 )
{
struct V_30 T_1 * V_2 ;
struct V_31 T_1 * V_32 ;
int V_48 , V_11 ;
V_32 = F_3 ( V_3 ) ;
V_2 = F_4 ( sizeof( * V_2 ) ) ;
V_48 = F_9 ( V_2 , V_32 ) ;
if ( V_48 )
return V_48 ;
V_48 = F_1 ( V_1 , V_50 , ( unsigned long ) V_2 ) ;
if ( V_48 < 0 )
return V_48 ;
V_11 = F_10 ( V_32 , V_2 ) ;
if ( V_11 )
V_48 = V_11 ;
return V_48 ;
}
static int F_13 ( struct V_51 T_1 * V_52 ,
struct V_53 T_1 * V_54 )
{
int V_11 ;
union {
unsigned int V_12 ;
T_2 V_13 ;
} V_14 ;
V_11 = 0 ;
if ( ! F_5 ( V_15 , V_54 , sizeof( * V_54 ) ) ||
! F_5 ( V_16 , V_52 , sizeof( * V_52 ) ) )
return - V_17 ;
V_11 |= F_6 ( V_14 . V_12 , & V_54 -> V_52 ) ;
V_11 |= F_7 ( V_14 . V_12 , & V_52 -> V_52 ) ;
V_11 |= F_6 ( V_14 . V_12 , & V_54 -> V_55 ) ;
V_11 |= F_7 ( V_14 . V_12 , & V_52 -> V_55 ) ;
V_11 |= F_6 ( V_14 . V_13 , & V_54 -> V_46 ) ;
V_11 |= F_7 ( F_3 ( V_14 . V_13 ) , & V_52 -> V_46 ) ;
V_11 |= F_6 ( V_14 . V_12 , & V_54 -> V_18 ) ;
V_11 |= F_7 ( V_14 . V_12 , & V_52 -> V_18 ) ;
V_11 |= F_6 ( V_14 . V_12 , & V_54 -> V_56 ) ;
V_11 |= F_7 ( V_14 . V_12 , & V_52 -> V_56 ) ;
return V_11 ? - V_17 : 0 ;
}
static int F_14 ( struct V_1 * V_1 , unsigned long V_3 )
{
struct V_57 {
struct V_58 V_59 ;
struct V_51 V_52 [ 1 ] ;
} T_1 * V_60 ;
struct V_61 T_1 * V_62 ;
struct V_53 T_1 * V_54 ;
T_2 V_13 ;
unsigned int V_63 , V_55 ;
int V_11 , V_48 ;
V_62 = F_3 ( V_3 ) ;
if ( ! F_5 ( V_15 , V_62 , sizeof( * V_62 ) ) )
return - V_17 ;
V_11 = 0 ;
V_11 |= F_6 ( V_63 , & V_62 -> V_63 ) ;
V_11 |= F_6 ( V_13 , & V_62 -> V_64 ) ;
V_54 = F_3 ( V_13 ) ;
if ( V_11 )
return - V_17 ;
V_60 = F_4 ( F_15 ( struct V_57 ,
V_52 [ V_63 ] ) ) ;
if ( ! F_5 ( V_16 , & V_60 -> V_59 , sizeof( V_60 -> V_59 ) ) )
return - V_17 ;
V_11 |= F_7 ( V_63 , & V_60 -> V_59 . V_63 ) ;
V_11 |= F_7 ( & V_60 -> V_52 [ 0 ] , & V_60 -> V_59 . V_64 ) ;
if ( V_11 )
return - V_17 ;
for ( V_55 = 0 ; V_55 < V_63 ; V_55 ++ ) {
V_48 = F_13 ( & V_60 -> V_52 [ V_55 ] , & V_54 [ V_55 ] ) ;
if ( V_48 )
return V_48 ;
}
return F_1 ( V_1 , V_65 ,
( unsigned long ) & V_60 -> V_59 ) ;
}
static int F_16 ( struct V_1 * V_1 , unsigned long V_3 )
{
struct V_51 T_1 * V_52 ;
struct V_53 T_1 * V_54 ;
int V_48 ;
V_54 = F_3 ( V_3 ) ;
V_52 = F_4 ( sizeof( * V_52 ) ) ;
V_48 = F_13 ( V_52 , V_54 ) ;
if ( V_48 )
return V_48 ;
return F_1 ( V_1 , V_66 , ( unsigned long ) V_52 ) ;
}
static inline int F_17 ( struct V_1 * V_1 , unsigned int V_2 ,
unsigned long V_3 )
{
int V_48 ;
switch ( V_2 ) {
case V_67 :
case V_68 :
case V_69 :
case V_70 :
case V_71 :
V_3 = ( unsigned long ) F_3 ( V_3 ) ;
V_48 = F_1 ( V_1 , V_2 , V_3 ) ;
break;
case V_72 :
case V_73 :
case V_74 :
case V_75 :
V_48 = F_1 ( V_1 , V_2 , V_3 ) ;
break;
case V_76 :
V_48 = F_2 ( V_1 , V_3 ) ;
break;
case V_77 :
V_48 = F_8 ( V_1 , V_3 ) ;
break;
case V_78 :
V_48 = F_11 ( V_1 , V_3 ) ;
break;
case V_79 :
V_48 = F_12 ( V_1 , V_3 ) ;
break;
case V_80 :
V_48 = F_14 ( V_1 , V_3 ) ;
break;
case V_81 :
V_48 = F_16 ( V_1 , V_3 ) ;
break;
default:
V_48 = - V_82 ;
break;
}
return V_48 ;
}
long F_18 ( struct V_1 * V_1 , unsigned int V_2 , unsigned long V_3 )
{
return F_17 ( V_1 , V_2 , V_3 ) ;
}
