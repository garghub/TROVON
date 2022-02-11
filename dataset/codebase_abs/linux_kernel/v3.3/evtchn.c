static inline struct V_1 * F_1 ( unsigned V_2 )
{
return (struct V_1 * ) ( V_3 [ V_2 ] & ~ 1 ) ;
}
static inline void F_2 ( unsigned V_2 , struct V_1 * V_4 )
{
V_3 [ V_2 ] = ( unsigned long ) V_4 ;
}
static inline bool F_3 ( unsigned V_2 )
{
return V_3 [ V_2 ] & 1 ;
}
static inline void F_4 ( unsigned V_2 , bool V_5 )
{
if ( V_5 )
V_3 [ V_2 ] |= 1 ;
else
V_3 [ V_2 ] &= ~ 1 ;
}
static T_1 F_5 ( int V_6 , void * V_7 )
{
unsigned int V_2 = ( unsigned long ) V_7 ;
struct V_1 * V_4 ;
F_6 ( & V_8 ) ;
V_4 = F_1 ( V_2 ) ;
F_7 ( ! F_3 ( V_2 ) ,
L_1 ,
V_2 , V_4 ) ;
F_8 ( V_6 ) ;
F_4 ( V_2 , false ) ;
if ( ( V_4 -> V_9 - V_4 -> V_10 ) < V_11 ) {
V_4 -> V_12 [ F_9 ( V_4 -> V_9 ) ] = V_2 ;
F_10 () ;
if ( V_4 -> V_10 == V_4 -> V_9 ++ ) {
F_11 ( & V_4 -> V_13 ) ;
F_12 ( & V_4 -> V_14 ,
V_15 , V_16 ) ;
}
} else
V_4 -> V_17 = 1 ;
F_13 ( & V_8 ) ;
return V_18 ;
}
static T_2 F_14 ( struct V_19 * V_19 , char T_3 * V_20 ,
T_4 V_21 , T_5 * V_22 )
{
int V_23 ;
unsigned int V_24 , V_25 , V_26 = 0 , V_27 = 0 ;
struct V_1 * V_4 = V_19 -> V_28 ;
V_21 &= ~ ( sizeof( V_29 ) - 1 ) ;
if ( V_21 == 0 )
return 0 ;
if ( V_21 > V_30 )
V_21 = V_30 ;
for (; ; ) {
F_15 ( & V_4 -> V_31 ) ;
V_23 = - V_32 ;
if ( V_4 -> V_17 )
goto V_33;
V_24 = V_4 -> V_10 ;
V_25 = V_4 -> V_9 ;
if ( V_24 != V_25 )
break;
F_16 ( & V_4 -> V_31 ) ;
if ( V_19 -> V_34 & V_35 )
return - V_36 ;
V_23 = F_17 ( V_4 -> V_13 ,
V_4 -> V_10 != V_4 -> V_9 ) ;
if ( V_23 )
return V_23 ;
}
if ( ( ( V_24 ^ V_25 ) & V_11 ) != 0 ) {
V_26 = ( V_11 - F_9 ( V_24 ) ) *
sizeof( V_29 ) ;
V_27 = F_9 ( V_25 ) * sizeof( V_29 ) ;
} else {
V_26 = ( V_25 - V_24 ) * sizeof( V_29 ) ;
V_27 = 0 ;
}
if ( V_26 > V_21 ) {
V_26 = V_21 ;
V_27 = 0 ;
} else if ( ( V_26 + V_27 ) > V_21 ) {
V_27 = V_21 - V_26 ;
}
V_23 = - V_37 ;
F_18 () ;
if ( F_19 ( V_20 , & V_4 -> V_12 [ F_9 ( V_24 ) ] , V_26 ) ||
( ( V_27 != 0 ) &&
F_19 ( & V_20 [ V_26 ] , & V_4 -> V_12 [ 0 ] , V_27 ) ) )
goto V_33;
V_4 -> V_10 += ( V_26 + V_27 ) / sizeof( V_29 ) ;
V_23 = V_26 + V_27 ;
V_33:
F_16 ( & V_4 -> V_31 ) ;
return V_23 ;
}
static T_2 F_20 ( struct V_19 * V_19 , const char T_3 * V_20 ,
T_4 V_21 , T_5 * V_22 )
{
int V_23 , V_38 ;
V_29 * V_39 = ( V_29 * ) F_21 ( V_40 ) ;
struct V_1 * V_4 = V_19 -> V_28 ;
if ( V_39 == NULL )
return - V_41 ;
V_21 &= ~ ( sizeof( V_29 ) - 1 ) ;
V_23 = 0 ;
if ( V_21 == 0 )
goto V_42;
if ( V_21 > V_30 )
V_21 = V_30 ;
V_23 = - V_37 ;
if ( F_22 ( V_39 , V_20 , V_21 ) != 0 )
goto V_42;
F_23 ( & V_8 ) ;
for ( V_38 = 0 ; V_38 < ( V_21 / sizeof( V_29 ) ) ; V_38 ++ ) {
unsigned V_2 = V_39 [ V_38 ] ;
if ( V_2 < V_43 &&
F_1 ( V_2 ) == V_4 &&
! F_3 ( V_2 ) ) {
F_4 ( V_2 , true ) ;
F_24 ( F_25 ( V_2 ) ) ;
}
}
F_26 ( & V_8 ) ;
V_23 = V_21 ;
V_42:
F_27 ( ( unsigned long ) V_39 ) ;
return V_23 ;
}
static int F_28 ( struct V_1 * V_4 , int V_2 )
{
int V_23 = 0 ;
F_29 ( F_1 ( V_2 ) != NULL ) ;
F_2 ( V_2 , V_4 ) ;
F_4 ( V_2 , true ) ;
V_23 = F_30 ( V_2 , F_5 , V_44 ,
V_4 -> V_45 , ( void * ) ( unsigned long ) V_2 ) ;
if ( V_23 >= 0 )
V_23 = F_31 ( V_2 ) ;
return V_23 ;
}
static void F_32 ( struct V_1 * V_4 , int V_2 )
{
int V_6 = F_25 ( V_2 ) ;
F_33 ( V_6 , ( void * ) ( unsigned long ) V_2 ) ;
F_2 ( V_2 , NULL ) ;
}
static long F_34 ( struct V_19 * V_19 ,
unsigned int V_46 , unsigned long V_47 )
{
int V_23 ;
struct V_1 * V_4 = V_19 -> V_28 ;
void T_3 * V_48 = ( void T_3 * ) V_47 ;
F_15 ( & V_4 -> V_49 ) ;
switch ( V_46 ) {
case V_50 : {
struct V_51 V_52 ;
struct V_53 V_54 ;
V_23 = - V_37 ;
if ( F_22 ( & V_52 , V_48 , sizeof( V_52 ) ) )
break;
V_54 . V_55 = V_52 . V_55 ;
V_54 . V_56 = 0 ;
V_23 = F_35 ( V_57 ,
& V_54 ) ;
if ( V_23 != 0 )
break;
V_23 = F_28 ( V_4 , V_54 . V_2 ) ;
if ( V_23 == 0 )
V_23 = V_54 . V_2 ;
break;
}
case V_58 : {
struct V_59 V_52 ;
struct V_60 V_61 ;
V_23 = - V_37 ;
if ( F_22 ( & V_52 , V_48 , sizeof( V_52 ) ) )
break;
V_61 . V_62 = V_52 . V_63 ;
V_61 . V_64 = V_52 . V_64 ;
V_23 = F_35 ( V_65 ,
& V_61 ) ;
if ( V_23 != 0 )
break;
V_23 = F_28 ( V_4 , V_61 . V_66 ) ;
if ( V_23 == 0 )
V_23 = V_61 . V_66 ;
break;
}
case V_67 : {
struct V_68 V_52 ;
struct V_69 V_70 ;
V_23 = - V_37 ;
if ( F_22 ( & V_52 , V_48 , sizeof( V_52 ) ) )
break;
V_70 . V_71 = V_72 ;
V_70 . V_62 = V_52 . V_63 ;
V_23 = F_35 ( V_73 ,
& V_70 ) ;
if ( V_23 != 0 )
break;
V_23 = F_28 ( V_4 , V_70 . V_2 ) ;
if ( V_23 == 0 )
V_23 = V_70 . V_2 ;
break;
}
case V_74 : {
struct V_75 V_76 ;
V_23 = - V_37 ;
if ( F_22 ( & V_76 , V_48 , sizeof( V_76 ) ) )
break;
V_23 = - V_77 ;
if ( V_76 . V_2 >= V_43 )
break;
F_23 ( & V_8 ) ;
V_23 = - V_78 ;
if ( F_1 ( V_76 . V_2 ) != V_4 ) {
F_26 ( & V_8 ) ;
break;
}
F_36 ( F_25 ( V_76 . V_2 ) ) ;
F_26 ( & V_8 ) ;
F_32 ( V_4 , V_76 . V_2 ) ;
V_23 = 0 ;
break;
}
case V_79 : {
struct V_80 V_81 ;
V_23 = - V_37 ;
if ( F_22 ( & V_81 , V_48 , sizeof( V_81 ) ) )
break;
if ( V_81 . V_2 >= V_43 ) {
V_23 = - V_77 ;
} else if ( F_1 ( V_81 . V_2 ) != V_4 ) {
V_23 = - V_78 ;
} else {
F_37 ( V_81 . V_2 ) ;
V_23 = 0 ;
}
break;
}
case V_82 : {
F_15 ( & V_4 -> V_31 ) ;
F_23 ( & V_8 ) ;
V_4 -> V_10 = V_4 -> V_9 = V_4 -> V_17 = 0 ;
F_26 ( & V_8 ) ;
F_16 ( & V_4 -> V_31 ) ;
V_23 = 0 ;
break;
}
default:
V_23 = - V_83 ;
break;
}
F_16 ( & V_4 -> V_49 ) ;
return V_23 ;
}
static unsigned int F_38 ( struct V_19 * V_19 , T_6 * V_84 )
{
unsigned int V_85 = V_86 | V_87 ;
struct V_1 * V_4 = V_19 -> V_28 ;
F_39 ( V_19 , & V_4 -> V_13 , V_84 ) ;
if ( V_4 -> V_10 != V_4 -> V_9 )
V_85 |= V_88 | V_89 ;
if ( V_4 -> V_17 )
V_85 = V_90 ;
return V_85 ;
}
static int F_40 ( int V_91 , struct V_19 * V_92 , int V_93 )
{
struct V_1 * V_4 = V_92 -> V_28 ;
return F_41 ( V_91 , V_92 , V_93 , & V_4 -> V_14 ) ;
}
static int F_42 ( struct V_94 * V_94 , struct V_19 * V_92 )
{
struct V_1 * V_4 ;
V_4 = F_43 ( sizeof( * V_4 ) , V_40 ) ;
if ( V_4 == NULL )
return - V_41 ;
V_4 -> V_45 = F_44 ( V_40 , L_2 , V_95 -> V_96 ) ;
if ( V_4 -> V_45 == NULL ) {
F_45 ( V_4 ) ;
return - V_41 ;
}
F_46 ( & V_4 -> V_13 ) ;
V_4 -> V_12 = ( V_29 * ) F_21 ( V_40 ) ;
if ( V_4 -> V_12 == NULL ) {
F_45 ( V_4 -> V_45 ) ;
F_45 ( V_4 ) ;
return - V_41 ;
}
F_47 ( & V_4 -> V_49 ) ;
F_47 ( & V_4 -> V_31 ) ;
V_92 -> V_28 = V_4 ;
return F_48 ( V_94 , V_92 ) ;
}
static int F_49 ( struct V_94 * V_94 , struct V_19 * V_92 )
{
int V_38 ;
struct V_1 * V_4 = V_92 -> V_28 ;
F_23 ( & V_8 ) ;
F_27 ( ( unsigned long ) V_4 -> V_12 ) ;
for ( V_38 = 0 ; V_38 < V_43 ; V_38 ++ ) {
if ( F_1 ( V_38 ) != V_4 )
continue;
F_36 ( F_25 ( V_38 ) ) ;
}
F_26 ( & V_8 ) ;
for ( V_38 = 0 ; V_38 < V_43 ; V_38 ++ ) {
if ( F_1 ( V_38 ) != V_4 )
continue;
F_32 ( F_1 ( V_38 ) , V_38 ) ;
}
F_45 ( V_4 -> V_45 ) ;
F_45 ( V_4 ) ;
return 0 ;
}
static int T_7 F_50 ( void )
{
int V_97 ;
if ( ! F_51 () )
return - V_98 ;
V_3 = F_52 ( V_43 , sizeof( * V_3 ) , V_40 ) ;
if ( V_3 == NULL )
return - V_41 ;
F_53 ( & V_8 ) ;
V_97 = F_54 ( & V_99 ) ;
if ( V_97 != 0 ) {
F_55 ( V_100 L_3 ) ;
return V_97 ;
}
F_55 ( V_101 L_4 ) ;
return 0 ;
}
static void T_8 F_56 ( void )
{
F_45 ( V_3 ) ;
V_3 = NULL ;
F_57 ( & V_99 ) ;
}
