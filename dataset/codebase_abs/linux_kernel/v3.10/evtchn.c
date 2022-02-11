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
else {
struct V_46 V_47 ;
V_47 . V_2 = V_2 ;
if ( F_32 ( V_48 , & V_47 ) != 0 )
F_33 () ;
F_2 ( V_2 , NULL ) ;
}
return V_23 ;
}
static void F_34 ( struct V_1 * V_4 , int V_2 )
{
int V_6 = F_25 ( V_2 ) ;
F_29 ( V_6 < 0 ) ;
F_35 ( V_6 , ( void * ) ( unsigned long ) V_2 ) ;
F_2 ( V_2 , NULL ) ;
}
static long F_36 ( struct V_19 * V_19 ,
unsigned int V_49 , unsigned long V_50 )
{
int V_23 ;
struct V_1 * V_4 = V_19 -> V_28 ;
void T_3 * V_51 = ( void T_3 * ) V_50 ;
F_15 ( & V_4 -> V_52 ) ;
switch ( V_49 ) {
case V_53 : {
struct V_54 V_55 ;
struct V_56 V_57 ;
V_23 = - V_37 ;
if ( F_22 ( & V_55 , V_51 , sizeof( V_55 ) ) )
break;
V_57 . V_58 = V_55 . V_58 ;
V_57 . V_59 = 0 ;
V_23 = F_32 ( V_60 ,
& V_57 ) ;
if ( V_23 != 0 )
break;
V_23 = F_28 ( V_4 , V_57 . V_2 ) ;
if ( V_23 == 0 )
V_23 = V_57 . V_2 ;
break;
}
case V_61 : {
struct V_62 V_55 ;
struct V_63 V_64 ;
V_23 = - V_37 ;
if ( F_22 ( & V_55 , V_51 , sizeof( V_55 ) ) )
break;
V_64 . V_65 = V_55 . V_66 ;
V_64 . V_67 = V_55 . V_67 ;
V_23 = F_32 ( V_68 ,
& V_64 ) ;
if ( V_23 != 0 )
break;
V_23 = F_28 ( V_4 , V_64 . V_69 ) ;
if ( V_23 == 0 )
V_23 = V_64 . V_69 ;
break;
}
case V_70 : {
struct V_71 V_55 ;
struct V_72 V_73 ;
V_23 = - V_37 ;
if ( F_22 ( & V_55 , V_51 , sizeof( V_55 ) ) )
break;
V_73 . V_74 = V_75 ;
V_73 . V_65 = V_55 . V_66 ;
V_23 = F_32 ( V_76 ,
& V_73 ) ;
if ( V_23 != 0 )
break;
V_23 = F_28 ( V_4 , V_73 . V_2 ) ;
if ( V_23 == 0 )
V_23 = V_73 . V_2 ;
break;
}
case V_77 : {
struct V_78 V_79 ;
V_23 = - V_37 ;
if ( F_22 ( & V_79 , V_51 , sizeof( V_79 ) ) )
break;
V_23 = - V_80 ;
if ( V_79 . V_2 >= V_43 )
break;
F_23 ( & V_8 ) ;
V_23 = - V_81 ;
if ( F_1 ( V_79 . V_2 ) != V_4 ) {
F_26 ( & V_8 ) ;
break;
}
F_37 ( F_25 ( V_79 . V_2 ) ) ;
F_26 ( & V_8 ) ;
F_34 ( V_4 , V_79 . V_2 ) ;
V_23 = 0 ;
break;
}
case V_82 : {
struct V_83 V_84 ;
V_23 = - V_37 ;
if ( F_22 ( & V_84 , V_51 , sizeof( V_84 ) ) )
break;
if ( V_84 . V_2 >= V_43 ) {
V_23 = - V_80 ;
} else if ( F_1 ( V_84 . V_2 ) != V_4 ) {
V_23 = - V_81 ;
} else {
F_38 ( V_84 . V_2 ) ;
V_23 = 0 ;
}
break;
}
case V_85 : {
F_15 ( & V_4 -> V_31 ) ;
F_23 ( & V_8 ) ;
V_4 -> V_10 = V_4 -> V_9 = V_4 -> V_17 = 0 ;
F_26 ( & V_8 ) ;
F_16 ( & V_4 -> V_31 ) ;
V_23 = 0 ;
break;
}
default:
V_23 = - V_86 ;
break;
}
F_16 ( & V_4 -> V_52 ) ;
return V_23 ;
}
static unsigned int F_39 ( struct V_19 * V_19 , T_6 * V_87 )
{
unsigned int V_88 = V_89 | V_90 ;
struct V_1 * V_4 = V_19 -> V_28 ;
F_40 ( V_19 , & V_4 -> V_13 , V_87 ) ;
if ( V_4 -> V_10 != V_4 -> V_9 )
V_88 |= V_91 | V_92 ;
if ( V_4 -> V_17 )
V_88 = V_93 ;
return V_88 ;
}
static int F_41 ( int V_94 , struct V_19 * V_95 , int V_96 )
{
struct V_1 * V_4 = V_95 -> V_28 ;
return F_42 ( V_94 , V_95 , V_96 , & V_4 -> V_14 ) ;
}
static int F_43 ( struct V_97 * V_97 , struct V_19 * V_95 )
{
struct V_1 * V_4 ;
V_4 = F_44 ( sizeof( * V_4 ) , V_40 ) ;
if ( V_4 == NULL )
return - V_41 ;
V_4 -> V_45 = F_45 ( V_40 , L_2 , V_98 -> V_99 ) ;
if ( V_4 -> V_45 == NULL ) {
F_46 ( V_4 ) ;
return - V_41 ;
}
F_47 ( & V_4 -> V_13 ) ;
V_4 -> V_12 = ( V_29 * ) F_21 ( V_40 ) ;
if ( V_4 -> V_12 == NULL ) {
F_46 ( V_4 -> V_45 ) ;
F_46 ( V_4 ) ;
return - V_41 ;
}
F_48 ( & V_4 -> V_52 ) ;
F_48 ( & V_4 -> V_31 ) ;
V_95 -> V_28 = V_4 ;
return F_49 ( V_97 , V_95 ) ;
}
static int F_50 ( struct V_97 * V_97 , struct V_19 * V_95 )
{
int V_38 ;
struct V_1 * V_4 = V_95 -> V_28 ;
F_23 ( & V_8 ) ;
F_27 ( ( unsigned long ) V_4 -> V_12 ) ;
for ( V_38 = 0 ; V_38 < V_43 ; V_38 ++ ) {
if ( F_1 ( V_38 ) != V_4 )
continue;
F_37 ( F_25 ( V_38 ) ) ;
}
F_26 ( & V_8 ) ;
for ( V_38 = 0 ; V_38 < V_43 ; V_38 ++ ) {
if ( F_1 ( V_38 ) != V_4 )
continue;
F_34 ( F_1 ( V_38 ) , V_38 ) ;
}
F_46 ( V_4 -> V_45 ) ;
F_46 ( V_4 ) ;
return 0 ;
}
static int T_7 F_51 ( void )
{
int V_100 ;
if ( ! F_52 () )
return - V_101 ;
V_3 = F_53 ( V_43 , sizeof( * V_3 ) , V_40 ) ;
if ( V_3 == NULL )
return - V_41 ;
F_54 ( & V_8 ) ;
V_100 = F_55 ( & V_102 ) ;
if ( V_100 != 0 ) {
F_56 ( V_103 L_3 ) ;
return V_100 ;
}
F_56 ( V_104 L_4 ) ;
return 0 ;
}
static void T_8 F_57 ( void )
{
F_46 ( V_3 ) ;
V_3 = NULL ;
F_58 ( & V_102 ) ;
}
