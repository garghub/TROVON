static void F_1 ( void * V_1 )
{
F_2 ( V_1 ) ;
}
static T_1
F_3 ( struct V_2 * V_3 , struct V_4 * V_5 )
{
F_4 ( V_6 ) ;
int V_7 ;
V_5 -> F_2 = F_1 ;
V_5 -> V_8 = & V_6 ;
F_5 ( & V_3 -> V_9 ) ;
if ( V_3 -> V_10 == NULL )
V_7 = - V_11 ;
else
V_7 = F_6 ( V_3 -> V_10 , V_5 ) ;
F_7 ( & V_3 -> V_9 ) ;
if ( V_7 == 0 ) {
F_8 ( & V_6 ) ;
V_7 = V_5 -> V_7 ;
if ( V_7 == 0 )
V_7 = V_5 -> V_12 ;
}
return V_7 ;
}
static inline T_1
F_9 ( struct V_2 * V_3 , T_2 V_13 )
{
struct V_14 V_15 = {
. V_16 = V_3 -> V_17 ,
. V_13 = V_13 ,
} ;
struct V_4 V_18 ;
F_10 ( & V_18 ) ;
F_11 ( & V_15 , & V_18 ) ;
return F_3 ( V_3 , & V_18 ) ;
}
static inline T_1
F_12 ( struct V_2 * V_3 , T_2 V_13 )
{
struct V_14 V_15 = {
. V_19 = V_3 -> V_17 ,
. V_13 = V_13 ,
} ;
struct V_4 V_18 ;
F_10 ( & V_18 ) ;
F_11 ( & V_15 , & V_18 ) ;
return F_3 ( V_3 , & V_18 ) ;
}
static T_1
F_13 ( struct V_20 * V_21 , char T_3 * V_22 , T_2 V_23 , T_4 * V_24 )
{
struct V_2 * V_3 ;
T_1 V_7 = 0 ;
if ( V_23 > V_25 )
return - V_26 ;
V_3 = V_21 -> V_27 ;
F_14 ( & V_3 -> V_28 ) ;
V_7 = F_12 ( V_3 , V_23 ) ;
if ( V_7 > 0 ) {
unsigned long V_29 ;
V_29 = F_15 ( V_22 , V_3 -> V_17 , V_7 ) ;
if ( V_29 == V_7 )
V_7 = - V_30 ;
else
V_7 = V_7 - V_29 ;
}
F_16 ( & V_3 -> V_28 ) ;
return V_7 ;
}
static T_1
F_17 ( struct V_20 * V_21 , const char T_3 * V_22 ,
T_2 V_23 , T_4 * V_24 )
{
struct V_2 * V_3 ;
T_1 V_7 = 0 ;
unsigned long V_29 ;
if ( V_23 > V_25 )
return - V_26 ;
V_3 = V_21 -> V_27 ;
F_14 ( & V_3 -> V_28 ) ;
V_29 = F_18 ( V_3 -> V_17 , V_22 , V_23 ) ;
if ( V_29 == 0 )
V_7 = F_9 ( V_3 , V_23 ) ;
else
V_7 = - V_30 ;
F_16 ( & V_3 -> V_28 ) ;
return V_7 ;
}
static int F_19 ( struct V_2 * V_3 ,
struct V_31 * V_32 , unsigned V_33 )
{
struct V_4 V_34 ;
struct V_14 * V_35 ;
struct V_14 * V_36 ;
struct V_31 * V_37 ;
unsigned V_38 , V_39 ;
T_5 * V_22 ;
int V_7 = - V_30 ;
F_10 ( & V_34 ) ;
V_35 = F_20 ( V_33 , sizeof( * V_36 ) , V_40 ) ;
if ( V_35 == NULL )
return - V_41 ;
V_22 = V_3 -> V_17 ;
V_39 = 0 ;
for ( V_38 = V_33 , V_36 = V_35 , V_37 = V_32 ;
V_38 ;
V_38 -- , V_36 ++ , V_37 ++ ) {
V_36 -> V_13 = V_37 -> V_13 ;
V_39 += V_36 -> V_13 ;
if ( V_39 > V_25 ) {
V_7 = - V_26 ;
goto V_6;
}
if ( V_37 -> V_19 ) {
V_36 -> V_19 = V_22 ;
if ( ! F_21 ( V_42 , ( T_5 T_3 * )
( V_43 ) V_37 -> V_19 ,
V_37 -> V_13 ) )
goto V_6;
}
if ( V_37 -> V_16 ) {
V_36 -> V_16 = V_22 ;
if ( F_18 ( V_22 , ( const T_5 T_3 * )
( V_43 ) V_37 -> V_16 ,
V_37 -> V_13 ) )
goto V_6;
}
V_22 += V_36 -> V_13 ;
V_36 -> V_44 = ! ! V_37 -> V_44 ;
V_36 -> V_45 = V_37 -> V_45 ;
V_36 -> V_46 = V_37 -> V_46 ;
V_36 -> V_47 = V_37 -> V_47 ;
V_36 -> V_48 = V_37 -> V_48 ;
V_36 -> V_49 = V_37 -> V_49 ;
#ifdef F_22
F_23 ( & V_3 -> V_10 -> V_50 ,
L_1 ,
V_37 -> V_13 ,
V_37 -> V_19 ? L_2 : L_3 ,
V_37 -> V_16 ? L_4 : L_3 ,
V_37 -> V_44 ? L_5 : L_3 ,
V_37 -> V_47 ? : V_3 -> V_10 -> V_47 ,
V_37 -> V_48 ,
V_37 -> V_49 ? : V_3 -> V_10 -> V_51 ) ;
#endif
F_11 ( V_36 , & V_34 ) ;
}
V_7 = F_3 ( V_3 , & V_34 ) ;
if ( V_7 < 0 )
goto V_6;
V_22 = V_3 -> V_17 ;
for ( V_38 = V_33 , V_37 = V_32 ; V_38 ; V_38 -- , V_37 ++ ) {
if ( V_37 -> V_19 ) {
if ( F_24 ( ( T_5 T_3 * )
( V_43 ) V_37 -> V_19 , V_22 ,
V_37 -> V_13 ) ) {
V_7 = - V_30 ;
goto V_6;
}
}
V_22 += V_37 -> V_13 ;
}
V_7 = V_39 ;
V_6:
F_25 ( V_35 ) ;
return V_7 ;
}
static long
F_26 ( struct V_20 * V_21 , unsigned int V_52 , unsigned long V_1 )
{
int V_53 = 0 ;
int V_54 = 0 ;
struct V_2 * V_3 ;
struct V_55 * V_10 ;
T_6 V_56 ;
unsigned V_57 ;
struct V_31 * V_58 ;
if ( F_27 ( V_52 ) != V_59 )
return - V_60 ;
if ( F_28 ( V_52 ) & V_61 )
V_53 = ! F_21 ( V_42 ,
( void T_3 * ) V_1 , F_29 ( V_52 ) ) ;
if ( V_53 == 0 && F_28 ( V_52 ) & V_62 )
V_53 = ! F_21 ( V_63 ,
( void T_3 * ) V_1 , F_29 ( V_52 ) ) ;
if ( V_53 )
return - V_30 ;
V_3 = V_21 -> V_27 ;
F_5 ( & V_3 -> V_9 ) ;
V_10 = F_30 ( V_3 -> V_10 ) ;
F_7 ( & V_3 -> V_9 ) ;
if ( V_10 == NULL )
return - V_11 ;
F_14 ( & V_3 -> V_28 ) ;
switch ( V_52 ) {
case V_64 :
V_54 = F_31 ( V_10 -> V_65 & V_66 ,
( V_67 T_3 * ) V_1 ) ;
break;
case V_68 :
V_54 = F_31 ( V_10 -> V_65 & V_66 ,
( V_69 T_3 * ) V_1 ) ;
break;
case V_70 :
V_54 = F_31 ( ( V_10 -> V_65 & V_71 ) ? 1 : 0 ,
( V_67 T_3 * ) V_1 ) ;
break;
case V_72 :
V_54 = F_31 ( V_10 -> V_47 , ( V_67 T_3 * ) V_1 ) ;
break;
case V_73 :
V_54 = F_31 ( V_10 -> V_51 , ( V_69 T_3 * ) V_1 ) ;
break;
case V_74 :
case V_75 :
if ( V_52 == V_74 )
V_54 = F_32 ( V_56 , ( T_5 T_3 * ) V_1 ) ;
else
V_54 = F_32 ( V_56 , ( T_6 T_3 * ) V_1 ) ;
if ( V_54 == 0 ) {
T_6 V_76 = V_10 -> V_65 ;
if ( V_56 & ~ V_66 ) {
V_54 = - V_77 ;
break;
}
V_56 |= V_10 -> V_65 & ~ V_66 ;
V_10 -> V_65 = ( V_78 ) V_56 ;
V_54 = F_33 ( V_10 ) ;
if ( V_54 < 0 )
V_10 -> V_65 = V_76 ;
else
F_23 ( & V_10 -> V_50 , L_6 , V_56 ) ;
}
break;
case V_79 :
V_54 = F_32 ( V_56 , ( V_67 T_3 * ) V_1 ) ;
if ( V_54 == 0 ) {
T_6 V_76 = V_10 -> V_65 ;
if ( V_56 )
V_10 -> V_65 |= V_71 ;
else
V_10 -> V_65 &= ~ V_71 ;
V_54 = F_33 ( V_10 ) ;
if ( V_54 < 0 )
V_10 -> V_65 = V_76 ;
else
F_23 ( & V_10 -> V_50 , L_7 ,
V_56 ? 'l' : 'm' ) ;
}
break;
case V_80 :
V_54 = F_32 ( V_56 , ( V_67 T_3 * ) V_1 ) ;
if ( V_54 == 0 ) {
T_5 V_76 = V_10 -> V_47 ;
V_10 -> V_47 = V_56 ;
V_54 = F_33 ( V_10 ) ;
if ( V_54 < 0 )
V_10 -> V_47 = V_76 ;
else
F_23 ( & V_10 -> V_50 , L_8 , V_56 ) ;
}
break;
case V_81 :
V_54 = F_32 ( V_56 , ( V_69 T_3 * ) V_1 ) ;
if ( V_54 == 0 ) {
T_6 V_76 = V_10 -> V_51 ;
V_10 -> V_51 = V_56 ;
V_54 = F_33 ( V_10 ) ;
if ( V_54 < 0 )
V_10 -> V_51 = V_76 ;
else
F_23 ( & V_10 -> V_50 , L_9 , V_56 ) ;
}
break;
default:
if ( F_34 ( V_52 ) != F_34 ( F_35 ( 0 ) )
|| F_28 ( V_52 ) != V_62 ) {
V_54 = - V_60 ;
break;
}
V_56 = F_29 ( V_52 ) ;
if ( ( V_56 % sizeof( struct V_31 ) ) != 0 ) {
V_54 = - V_77 ;
break;
}
V_57 = V_56 / sizeof( struct V_31 ) ;
if ( V_57 == 0 )
break;
V_58 = F_36 ( V_56 , V_40 ) ;
if ( ! V_58 ) {
V_54 = - V_41 ;
break;
}
if ( F_37 ( V_58 , ( void T_3 * ) V_1 , V_56 ) ) {
F_25 ( V_58 ) ;
V_54 = - V_30 ;
break;
}
V_54 = F_19 ( V_3 , V_58 , V_57 ) ;
F_25 ( V_58 ) ;
break;
}
F_16 ( & V_3 -> V_28 ) ;
F_38 ( V_10 ) ;
return V_54 ;
}
static long
F_39 ( struct V_20 * V_21 , unsigned int V_52 , unsigned long V_1 )
{
return F_26 ( V_21 , V_52 , ( unsigned long ) F_40 ( V_1 ) ) ;
}
static int F_41 ( struct V_82 * V_82 , struct V_20 * V_21 )
{
struct V_2 * V_3 ;
int V_7 = - V_83 ;
F_14 ( & V_84 ) ;
F_42 (spidev, &device_list, device_entry) {
if ( V_3 -> V_85 == V_82 -> V_86 ) {
V_7 = 0 ;
break;
}
}
if ( V_7 == 0 ) {
if ( ! V_3 -> V_17 ) {
V_3 -> V_17 = F_36 ( V_25 , V_40 ) ;
if ( ! V_3 -> V_17 ) {
F_23 ( & V_3 -> V_10 -> V_50 , L_10 ) ;
V_7 = - V_41 ;
}
}
if ( V_7 == 0 ) {
V_3 -> V_87 ++ ;
V_21 -> V_27 = V_3 ;
F_43 ( V_82 , V_21 ) ;
}
} else
F_44 ( L_11 , F_45 ( V_82 ) ) ;
F_16 ( & V_84 ) ;
return V_7 ;
}
static int F_46 ( struct V_82 * V_82 , struct V_20 * V_21 )
{
struct V_2 * V_3 ;
int V_7 = 0 ;
F_14 ( & V_84 ) ;
V_3 = V_21 -> V_27 ;
V_21 -> V_27 = NULL ;
V_3 -> V_87 -- ;
if ( ! V_3 -> V_87 ) {
int V_88 ;
F_25 ( V_3 -> V_17 ) ;
V_3 -> V_17 = NULL ;
F_5 ( & V_3 -> V_9 ) ;
V_88 = ( V_3 -> V_10 == NULL ) ;
F_7 ( & V_3 -> V_9 ) ;
if ( V_88 )
F_25 ( V_3 ) ;
}
F_16 ( & V_84 ) ;
return V_7 ;
}
static int F_47 ( struct V_55 * V_10 )
{
struct V_2 * V_3 ;
int V_7 ;
unsigned long V_89 ;
V_3 = F_48 ( sizeof( * V_3 ) , V_40 ) ;
if ( ! V_3 )
return - V_41 ;
V_3 -> V_10 = V_10 ;
F_49 ( & V_3 -> V_9 ) ;
F_50 ( & V_3 -> V_28 ) ;
F_51 ( & V_3 -> V_90 ) ;
F_14 ( & V_84 ) ;
V_89 = F_52 ( V_91 , V_92 ) ;
if ( V_89 < V_92 ) {
struct V_93 * V_50 ;
V_3 -> V_85 = F_53 ( V_94 , V_89 ) ;
V_50 = F_54 ( V_95 , & V_10 -> V_50 , V_3 -> V_85 ,
V_3 , L_12 ,
V_10 -> V_96 -> V_97 , V_10 -> V_98 ) ;
V_7 = F_55 ( V_50 ) ;
} else {
F_23 ( & V_10 -> V_50 , L_13 ) ;
V_7 = - V_99 ;
}
if ( V_7 == 0 ) {
F_56 ( V_89 , V_91 ) ;
F_57 ( & V_3 -> V_90 , & V_100 ) ;
}
F_16 ( & V_84 ) ;
if ( V_7 == 0 )
F_58 ( V_10 , V_3 ) ;
else
F_25 ( V_3 ) ;
return V_7 ;
}
static int F_59 ( struct V_55 * V_10 )
{
struct V_2 * V_3 = F_60 ( V_10 ) ;
F_5 ( & V_3 -> V_9 ) ;
V_3 -> V_10 = NULL ;
F_7 ( & V_3 -> V_9 ) ;
F_14 ( & V_84 ) ;
F_61 ( & V_3 -> V_90 ) ;
F_62 ( V_95 , V_3 -> V_85 ) ;
F_63 ( F_64 ( V_3 -> V_85 ) , V_91 ) ;
if ( V_3 -> V_87 == 0 )
F_25 ( V_3 ) ;
F_16 ( & V_84 ) ;
return 0 ;
}
static int T_7 F_65 ( void )
{
int V_7 ;
F_66 ( V_92 > 256 ) ;
V_7 = F_67 ( V_94 , L_14 , & V_101 ) ;
if ( V_7 < 0 )
return V_7 ;
V_95 = F_68 ( V_102 , L_15 ) ;
if ( F_69 ( V_95 ) ) {
F_70 ( V_94 , V_103 . V_104 . V_105 ) ;
return F_71 ( V_95 ) ;
}
V_7 = F_72 ( & V_103 ) ;
if ( V_7 < 0 ) {
F_73 ( V_95 ) ;
F_70 ( V_94 , V_103 . V_104 . V_105 ) ;
}
return V_7 ;
}
static void T_8 F_74 ( void )
{
F_75 ( & V_103 ) ;
F_73 ( V_95 ) ;
F_70 ( V_94 , V_103 . V_104 . V_105 ) ;
}
