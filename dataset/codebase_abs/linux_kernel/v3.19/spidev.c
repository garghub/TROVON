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
. V_18 = V_3 -> V_18 ,
} ;
struct V_4 V_19 ;
F_10 ( & V_19 ) ;
F_11 ( & V_15 , & V_19 ) ;
return F_3 ( V_3 , & V_19 ) ;
}
static inline T_1
F_12 ( struct V_2 * V_3 , T_2 V_13 )
{
struct V_14 V_15 = {
. V_20 = V_3 -> V_21 ,
. V_13 = V_13 ,
. V_18 = V_3 -> V_18 ,
} ;
struct V_4 V_19 ;
F_10 ( & V_19 ) ;
F_11 ( & V_15 , & V_19 ) ;
return F_3 ( V_3 , & V_19 ) ;
}
static T_1
F_13 ( struct V_22 * V_23 , char T_3 * V_24 , T_2 V_25 , T_4 * V_26 )
{
struct V_2 * V_3 ;
T_1 V_7 = 0 ;
if ( V_25 > V_27 )
return - V_28 ;
V_3 = V_23 -> V_29 ;
F_14 ( & V_3 -> V_30 ) ;
V_7 = F_12 ( V_3 , V_25 ) ;
if ( V_7 > 0 ) {
unsigned long V_31 ;
V_31 = F_15 ( V_24 , V_3 -> V_21 , V_7 ) ;
if ( V_31 == V_7 )
V_7 = - V_32 ;
else
V_7 = V_7 - V_31 ;
}
F_16 ( & V_3 -> V_30 ) ;
return V_7 ;
}
static T_1
F_17 ( struct V_22 * V_23 , const char T_3 * V_24 ,
T_2 V_25 , T_4 * V_26 )
{
struct V_2 * V_3 ;
T_1 V_7 = 0 ;
unsigned long V_31 ;
if ( V_25 > V_27 )
return - V_28 ;
V_3 = V_23 -> V_29 ;
F_14 ( & V_3 -> V_30 ) ;
V_31 = F_18 ( V_3 -> V_17 , V_24 , V_25 ) ;
if ( V_31 == 0 )
V_7 = F_9 ( V_3 , V_25 ) ;
else
V_7 = - V_32 ;
F_16 ( & V_3 -> V_30 ) ;
return V_7 ;
}
static int F_19 ( struct V_2 * V_3 ,
struct V_33 * V_34 , unsigned V_35 )
{
struct V_4 V_36 ;
struct V_14 * V_37 ;
struct V_14 * V_38 ;
struct V_33 * V_39 ;
unsigned V_40 , V_41 ;
T_5 * V_16 , * V_20 ;
int V_7 = - V_32 ;
F_10 ( & V_36 ) ;
V_37 = F_20 ( V_35 , sizeof( * V_38 ) , V_42 ) ;
if ( V_37 == NULL )
return - V_43 ;
V_16 = V_3 -> V_17 ;
V_20 = V_3 -> V_21 ;
V_41 = 0 ;
for ( V_40 = V_35 , V_38 = V_37 , V_39 = V_34 ;
V_40 ;
V_40 -- , V_38 ++ , V_39 ++ ) {
V_38 -> V_13 = V_39 -> V_13 ;
V_41 += V_38 -> V_13 ;
if ( V_41 > V_27 ) {
V_7 = - V_28 ;
goto V_6;
}
if ( V_39 -> V_20 ) {
V_38 -> V_20 = V_20 ;
if ( ! F_21 ( V_44 , ( T_5 T_3 * )
( V_45 ) V_39 -> V_20 ,
V_39 -> V_13 ) )
goto V_6;
}
if ( V_39 -> V_16 ) {
V_38 -> V_16 = V_16 ;
if ( F_18 ( V_16 , ( const T_5 T_3 * )
( V_45 ) V_39 -> V_16 ,
V_39 -> V_13 ) )
goto V_6;
}
V_16 += V_38 -> V_13 ;
V_20 += V_38 -> V_13 ;
V_38 -> V_46 = ! ! V_39 -> V_46 ;
V_38 -> V_47 = V_39 -> V_47 ;
V_38 -> V_48 = V_39 -> V_48 ;
V_38 -> V_49 = V_39 -> V_49 ;
V_38 -> V_50 = V_39 -> V_50 ;
V_38 -> V_18 = V_39 -> V_18 ;
if ( ! V_38 -> V_18 )
V_38 -> V_18 = V_3 -> V_18 ;
#ifdef F_22
F_23 ( & V_3 -> V_10 -> V_51 ,
L_1 ,
V_39 -> V_13 ,
V_39 -> V_20 ? L_2 : L_3 ,
V_39 -> V_16 ? L_4 : L_3 ,
V_39 -> V_46 ? L_5 : L_3 ,
V_39 -> V_49 ? : V_3 -> V_10 -> V_49 ,
V_39 -> V_50 ,
V_39 -> V_18 ? : V_3 -> V_10 -> V_52 ) ;
#endif
F_11 ( V_38 , & V_36 ) ;
}
V_7 = F_3 ( V_3 , & V_36 ) ;
if ( V_7 < 0 )
goto V_6;
V_20 = V_3 -> V_21 ;
for ( V_40 = V_35 , V_39 = V_34 ; V_40 ; V_40 -- , V_39 ++ ) {
if ( V_39 -> V_20 ) {
if ( F_24 ( ( T_5 T_3 * )
( V_45 ) V_39 -> V_20 , V_20 ,
V_39 -> V_13 ) ) {
V_7 = - V_32 ;
goto V_6;
}
}
V_20 += V_39 -> V_13 ;
}
V_7 = V_41 ;
V_6:
F_25 ( V_37 ) ;
return V_7 ;
}
static long
F_26 ( struct V_22 * V_23 , unsigned int V_53 , unsigned long V_1 )
{
int V_54 = 0 ;
int V_55 = 0 ;
struct V_2 * V_3 ;
struct V_56 * V_10 ;
T_6 V_57 ;
unsigned V_58 ;
struct V_33 * V_59 ;
if ( F_27 ( V_53 ) != V_60 )
return - V_61 ;
if ( F_28 ( V_53 ) & V_62 )
V_54 = ! F_21 ( V_44 ,
( void T_3 * ) V_1 , F_29 ( V_53 ) ) ;
if ( V_54 == 0 && F_28 ( V_53 ) & V_63 )
V_54 = ! F_21 ( V_64 ,
( void T_3 * ) V_1 , F_29 ( V_53 ) ) ;
if ( V_54 )
return - V_32 ;
V_3 = V_23 -> V_29 ;
F_5 ( & V_3 -> V_9 ) ;
V_10 = F_30 ( V_3 -> V_10 ) ;
F_7 ( & V_3 -> V_9 ) ;
if ( V_10 == NULL )
return - V_11 ;
F_14 ( & V_3 -> V_30 ) ;
switch ( V_53 ) {
case V_65 :
V_55 = F_31 ( V_10 -> V_66 & V_67 ,
( V_68 T_3 * ) V_1 ) ;
break;
case V_69 :
V_55 = F_31 ( V_10 -> V_66 & V_67 ,
( V_70 T_3 * ) V_1 ) ;
break;
case V_71 :
V_55 = F_31 ( ( V_10 -> V_66 & V_72 ) ? 1 : 0 ,
( V_68 T_3 * ) V_1 ) ;
break;
case V_73 :
V_55 = F_31 ( V_10 -> V_49 , ( V_68 T_3 * ) V_1 ) ;
break;
case V_74 :
V_55 = F_31 ( V_3 -> V_18 , ( V_70 T_3 * ) V_1 ) ;
break;
case V_75 :
case V_76 :
if ( V_53 == V_75 )
V_55 = F_32 ( V_57 , ( T_5 T_3 * ) V_1 ) ;
else
V_55 = F_32 ( V_57 , ( T_6 T_3 * ) V_1 ) ;
if ( V_55 == 0 ) {
T_6 V_77 = V_10 -> V_66 ;
if ( V_57 & ~ V_67 ) {
V_55 = - V_78 ;
break;
}
V_57 |= V_10 -> V_66 & ~ V_67 ;
V_10 -> V_66 = ( V_79 ) V_57 ;
V_55 = F_33 ( V_10 ) ;
if ( V_55 < 0 )
V_10 -> V_66 = V_77 ;
else
F_23 ( & V_10 -> V_51 , L_6 , V_57 ) ;
}
break;
case V_80 :
V_55 = F_32 ( V_57 , ( V_68 T_3 * ) V_1 ) ;
if ( V_55 == 0 ) {
T_6 V_77 = V_10 -> V_66 ;
if ( V_57 )
V_10 -> V_66 |= V_72 ;
else
V_10 -> V_66 &= ~ V_72 ;
V_55 = F_33 ( V_10 ) ;
if ( V_55 < 0 )
V_10 -> V_66 = V_77 ;
else
F_23 ( & V_10 -> V_51 , L_7 ,
V_57 ? 'l' : 'm' ) ;
}
break;
case V_81 :
V_55 = F_32 ( V_57 , ( V_68 T_3 * ) V_1 ) ;
if ( V_55 == 0 ) {
T_5 V_77 = V_10 -> V_49 ;
V_10 -> V_49 = V_57 ;
V_55 = F_33 ( V_10 ) ;
if ( V_55 < 0 )
V_10 -> V_49 = V_77 ;
else
F_23 ( & V_10 -> V_51 , L_8 , V_57 ) ;
}
break;
case V_82 :
V_55 = F_32 ( V_57 , ( V_70 T_3 * ) V_1 ) ;
if ( V_55 == 0 ) {
T_6 V_77 = V_10 -> V_52 ;
V_10 -> V_52 = V_57 ;
V_55 = F_33 ( V_10 ) ;
if ( V_55 >= 0 )
V_3 -> V_18 = V_57 ;
else
F_23 ( & V_10 -> V_51 , L_9 , V_57 ) ;
V_10 -> V_52 = V_77 ;
}
break;
default:
if ( F_34 ( V_53 ) != F_34 ( F_35 ( 0 ) )
|| F_28 ( V_53 ) != V_63 ) {
V_55 = - V_61 ;
break;
}
V_57 = F_29 ( V_53 ) ;
if ( ( V_57 % sizeof( struct V_33 ) ) != 0 ) {
V_55 = - V_78 ;
break;
}
V_58 = V_57 / sizeof( struct V_33 ) ;
if ( V_58 == 0 )
break;
V_59 = F_36 ( V_57 , V_42 ) ;
if ( ! V_59 ) {
V_55 = - V_43 ;
break;
}
if ( F_37 ( V_59 , ( void T_3 * ) V_1 , V_57 ) ) {
F_25 ( V_59 ) ;
V_55 = - V_32 ;
break;
}
V_55 = F_19 ( V_3 , V_59 , V_58 ) ;
F_25 ( V_59 ) ;
break;
}
F_16 ( & V_3 -> V_30 ) ;
F_38 ( V_10 ) ;
return V_55 ;
}
static long
F_39 ( struct V_22 * V_23 , unsigned int V_53 , unsigned long V_1 )
{
return F_26 ( V_23 , V_53 , ( unsigned long ) F_40 ( V_1 ) ) ;
}
static int F_41 ( struct V_83 * V_83 , struct V_22 * V_23 )
{
struct V_2 * V_3 ;
int V_7 = - V_84 ;
F_14 ( & V_85 ) ;
F_42 (spidev, &device_list, device_entry) {
if ( V_3 -> V_86 == V_83 -> V_87 ) {
V_7 = 0 ;
break;
}
}
if ( V_7 ) {
F_43 ( L_10 , F_44 ( V_83 ) ) ;
goto V_88;
}
if ( ! V_3 -> V_17 ) {
V_3 -> V_17 = F_36 ( V_27 , V_42 ) ;
if ( ! V_3 -> V_17 ) {
F_23 ( & V_3 -> V_10 -> V_51 , L_11 ) ;
V_7 = - V_43 ;
goto V_88;
}
}
if ( ! V_3 -> V_21 ) {
V_3 -> V_21 = F_36 ( V_27 , V_42 ) ;
if ( ! V_3 -> V_21 ) {
F_23 ( & V_3 -> V_10 -> V_51 , L_11 ) ;
V_7 = - V_43 ;
goto V_89;
}
}
V_3 -> V_90 ++ ;
V_23 -> V_29 = V_3 ;
F_45 ( V_83 , V_23 ) ;
F_16 ( & V_85 ) ;
return 0 ;
V_89:
F_25 ( V_3 -> V_17 ) ;
V_3 -> V_17 = NULL ;
V_88:
F_16 ( & V_85 ) ;
return V_7 ;
}
static int F_46 ( struct V_83 * V_83 , struct V_22 * V_23 )
{
struct V_2 * V_3 ;
int V_7 = 0 ;
F_14 ( & V_85 ) ;
V_3 = V_23 -> V_29 ;
V_23 -> V_29 = NULL ;
V_3 -> V_90 -- ;
if ( ! V_3 -> V_90 ) {
int V_91 ;
F_25 ( V_3 -> V_17 ) ;
V_3 -> V_17 = NULL ;
F_25 ( V_3 -> V_21 ) ;
V_3 -> V_21 = NULL ;
V_3 -> V_18 = V_3 -> V_10 -> V_52 ;
F_5 ( & V_3 -> V_9 ) ;
V_91 = ( V_3 -> V_10 == NULL ) ;
F_7 ( & V_3 -> V_9 ) ;
if ( V_91 )
F_25 ( V_3 ) ;
}
F_16 ( & V_85 ) ;
return V_7 ;
}
static int F_47 ( struct V_56 * V_10 )
{
struct V_2 * V_3 ;
int V_7 ;
unsigned long V_92 ;
V_3 = F_48 ( sizeof( * V_3 ) , V_42 ) ;
if ( ! V_3 )
return - V_43 ;
V_3 -> V_10 = V_10 ;
F_49 ( & V_3 -> V_9 ) ;
F_50 ( & V_3 -> V_30 ) ;
F_51 ( & V_3 -> V_93 ) ;
F_14 ( & V_85 ) ;
V_92 = F_52 ( V_94 , V_95 ) ;
if ( V_92 < V_95 ) {
struct V_96 * V_51 ;
V_3 -> V_86 = F_53 ( V_97 , V_92 ) ;
V_51 = F_54 ( V_98 , & V_10 -> V_51 , V_3 -> V_86 ,
V_3 , L_12 ,
V_10 -> V_99 -> V_100 , V_10 -> V_101 ) ;
V_7 = F_55 ( V_51 ) ;
} else {
F_23 ( & V_10 -> V_51 , L_13 ) ;
V_7 = - V_102 ;
}
if ( V_7 == 0 ) {
F_56 ( V_92 , V_94 ) ;
F_57 ( & V_3 -> V_93 , & V_103 ) ;
}
F_16 ( & V_85 ) ;
V_3 -> V_18 = V_10 -> V_52 ;
if ( V_7 == 0 )
F_58 ( V_10 , V_3 ) ;
else
F_25 ( V_3 ) ;
return V_7 ;
}
static int F_59 ( struct V_56 * V_10 )
{
struct V_2 * V_3 = F_60 ( V_10 ) ;
F_5 ( & V_3 -> V_9 ) ;
V_3 -> V_10 = NULL ;
F_7 ( & V_3 -> V_9 ) ;
F_14 ( & V_85 ) ;
F_61 ( & V_3 -> V_93 ) ;
F_62 ( V_98 , V_3 -> V_86 ) ;
F_63 ( F_64 ( V_3 -> V_86 ) , V_94 ) ;
if ( V_3 -> V_90 == 0 )
F_25 ( V_3 ) ;
F_16 ( & V_85 ) ;
return 0 ;
}
static int T_7 F_65 ( void )
{
int V_7 ;
F_66 ( V_95 > 256 ) ;
V_7 = F_67 ( V_97 , L_14 , & V_104 ) ;
if ( V_7 < 0 )
return V_7 ;
V_98 = F_68 ( V_105 , L_15 ) ;
if ( F_69 ( V_98 ) ) {
F_70 ( V_97 , V_106 . V_107 . V_108 ) ;
return F_71 ( V_98 ) ;
}
V_7 = F_72 ( & V_106 ) ;
if ( V_7 < 0 ) {
F_73 ( V_98 ) ;
F_70 ( V_97 , V_106 . V_107 . V_108 ) ;
}
return V_7 ;
}
static void T_8 F_74 ( void )
{
F_75 ( & V_106 ) ;
F_73 ( V_98 ) ;
F_70 ( V_97 , V_106 . V_107 . V_108 ) ;
}
