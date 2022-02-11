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
. V_19 = V_3 -> V_20 ,
. V_13 = V_13 ,
} ;
struct V_4 V_18 ;
F_10 ( & V_18 ) ;
F_11 ( & V_15 , & V_18 ) ;
return F_3 ( V_3 , & V_18 ) ;
}
static T_1
F_13 ( struct V_21 * V_22 , char T_3 * V_23 , T_2 V_24 , T_4 * V_25 )
{
struct V_2 * V_3 ;
T_1 V_7 = 0 ;
if ( V_24 > V_26 )
return - V_27 ;
V_3 = V_22 -> V_28 ;
F_14 ( & V_3 -> V_29 ) ;
V_7 = F_12 ( V_3 , V_24 ) ;
if ( V_7 > 0 ) {
unsigned long V_30 ;
V_30 = F_15 ( V_23 , V_3 -> V_20 , V_7 ) ;
if ( V_30 == V_7 )
V_7 = - V_31 ;
else
V_7 = V_7 - V_30 ;
}
F_16 ( & V_3 -> V_29 ) ;
return V_7 ;
}
static T_1
F_17 ( struct V_21 * V_22 , const char T_3 * V_23 ,
T_2 V_24 , T_4 * V_25 )
{
struct V_2 * V_3 ;
T_1 V_7 = 0 ;
unsigned long V_30 ;
if ( V_24 > V_26 )
return - V_27 ;
V_3 = V_22 -> V_28 ;
F_14 ( & V_3 -> V_29 ) ;
V_30 = F_18 ( V_3 -> V_17 , V_23 , V_24 ) ;
if ( V_30 == 0 )
V_7 = F_9 ( V_3 , V_24 ) ;
else
V_7 = - V_31 ;
F_16 ( & V_3 -> V_29 ) ;
return V_7 ;
}
static int F_19 ( struct V_2 * V_3 ,
struct V_32 * V_33 , unsigned V_34 )
{
struct V_4 V_35 ;
struct V_14 * V_36 ;
struct V_14 * V_37 ;
struct V_32 * V_38 ;
unsigned V_39 , V_40 ;
T_5 * V_16 , * V_19 ;
int V_7 = - V_31 ;
F_10 ( & V_35 ) ;
V_36 = F_20 ( V_34 , sizeof( * V_37 ) , V_41 ) ;
if ( V_36 == NULL )
return - V_42 ;
V_16 = V_3 -> V_17 ;
V_19 = V_3 -> V_20 ;
V_40 = 0 ;
for ( V_39 = V_34 , V_37 = V_36 , V_38 = V_33 ;
V_39 ;
V_39 -- , V_37 ++ , V_38 ++ ) {
V_37 -> V_13 = V_38 -> V_13 ;
V_40 += V_37 -> V_13 ;
if ( V_40 > V_26 ) {
V_7 = - V_27 ;
goto V_6;
}
if ( V_38 -> V_19 ) {
V_37 -> V_19 = V_19 ;
if ( ! F_21 ( V_43 , ( T_5 T_3 * )
( V_44 ) V_38 -> V_19 ,
V_38 -> V_13 ) )
goto V_6;
}
if ( V_38 -> V_16 ) {
V_37 -> V_16 = V_16 ;
if ( F_18 ( V_16 , ( const T_5 T_3 * )
( V_44 ) V_38 -> V_16 ,
V_38 -> V_13 ) )
goto V_6;
}
V_16 += V_37 -> V_13 ;
V_19 += V_37 -> V_13 ;
V_37 -> V_45 = ! ! V_38 -> V_45 ;
V_37 -> V_46 = V_38 -> V_46 ;
V_37 -> V_47 = V_38 -> V_47 ;
V_37 -> V_48 = V_38 -> V_48 ;
V_37 -> V_49 = V_38 -> V_49 ;
V_37 -> V_50 = V_38 -> V_50 ;
#ifdef F_22
F_23 ( & V_3 -> V_10 -> V_51 ,
L_1 ,
V_38 -> V_13 ,
V_38 -> V_19 ? L_2 : L_3 ,
V_38 -> V_16 ? L_4 : L_3 ,
V_38 -> V_45 ? L_5 : L_3 ,
V_38 -> V_48 ? : V_3 -> V_10 -> V_48 ,
V_38 -> V_49 ,
V_38 -> V_50 ? : V_3 -> V_10 -> V_52 ) ;
#endif
F_11 ( V_37 , & V_35 ) ;
}
V_7 = F_3 ( V_3 , & V_35 ) ;
if ( V_7 < 0 )
goto V_6;
V_19 = V_3 -> V_20 ;
for ( V_39 = V_34 , V_38 = V_33 ; V_39 ; V_39 -- , V_38 ++ ) {
if ( V_38 -> V_19 ) {
if ( F_24 ( ( T_5 T_3 * )
( V_44 ) V_38 -> V_19 , V_19 ,
V_38 -> V_13 ) ) {
V_7 = - V_31 ;
goto V_6;
}
}
V_19 += V_38 -> V_13 ;
}
V_7 = V_40 ;
V_6:
F_25 ( V_36 ) ;
return V_7 ;
}
static long
F_26 ( struct V_21 * V_22 , unsigned int V_53 , unsigned long V_1 )
{
int V_54 = 0 ;
int V_55 = 0 ;
struct V_2 * V_3 ;
struct V_56 * V_10 ;
T_6 V_57 ;
unsigned V_58 ;
struct V_32 * V_59 ;
if ( F_27 ( V_53 ) != V_60 )
return - V_61 ;
if ( F_28 ( V_53 ) & V_62 )
V_54 = ! F_21 ( V_43 ,
( void T_3 * ) V_1 , F_29 ( V_53 ) ) ;
if ( V_54 == 0 && F_28 ( V_53 ) & V_63 )
V_54 = ! F_21 ( V_64 ,
( void T_3 * ) V_1 , F_29 ( V_53 ) ) ;
if ( V_54 )
return - V_31 ;
V_3 = V_22 -> V_28 ;
F_5 ( & V_3 -> V_9 ) ;
V_10 = F_30 ( V_3 -> V_10 ) ;
F_7 ( & V_3 -> V_9 ) ;
if ( V_10 == NULL )
return - V_11 ;
F_14 ( & V_3 -> V_29 ) ;
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
V_55 = F_31 ( V_10 -> V_48 , ( V_68 T_3 * ) V_1 ) ;
break;
case V_74 :
V_55 = F_31 ( V_10 -> V_52 , ( V_70 T_3 * ) V_1 ) ;
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
T_5 V_77 = V_10 -> V_48 ;
V_10 -> V_48 = V_57 ;
V_55 = F_33 ( V_10 ) ;
if ( V_55 < 0 )
V_10 -> V_48 = V_77 ;
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
if ( V_55 < 0 )
V_10 -> V_52 = V_77 ;
else
F_23 ( & V_10 -> V_51 , L_9 , V_57 ) ;
}
break;
default:
if ( F_34 ( V_53 ) != F_34 ( F_35 ( 0 ) )
|| F_28 ( V_53 ) != V_63 ) {
V_55 = - V_61 ;
break;
}
V_57 = F_29 ( V_53 ) ;
if ( ( V_57 % sizeof( struct V_32 ) ) != 0 ) {
V_55 = - V_78 ;
break;
}
V_58 = V_57 / sizeof( struct V_32 ) ;
if ( V_58 == 0 )
break;
V_59 = F_36 ( V_57 , V_41 ) ;
if ( ! V_59 ) {
V_55 = - V_42 ;
break;
}
if ( F_37 ( V_59 , ( void T_3 * ) V_1 , V_57 ) ) {
F_25 ( V_59 ) ;
V_55 = - V_31 ;
break;
}
V_55 = F_19 ( V_3 , V_59 , V_58 ) ;
F_25 ( V_59 ) ;
break;
}
F_16 ( & V_3 -> V_29 ) ;
F_38 ( V_10 ) ;
return V_55 ;
}
static long
F_39 ( struct V_21 * V_22 , unsigned int V_53 , unsigned long V_1 )
{
return F_26 ( V_22 , V_53 , ( unsigned long ) F_40 ( V_1 ) ) ;
}
static int F_41 ( struct V_83 * V_83 , struct V_21 * V_22 )
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
V_3 -> V_17 = F_36 ( V_26 , V_41 ) ;
if ( ! V_3 -> V_17 ) {
F_23 ( & V_3 -> V_10 -> V_51 , L_11 ) ;
V_7 = - V_42 ;
goto V_88;
}
}
if ( ! V_3 -> V_20 ) {
V_3 -> V_20 = F_36 ( V_26 , V_41 ) ;
if ( ! V_3 -> V_20 ) {
F_23 ( & V_3 -> V_10 -> V_51 , L_11 ) ;
V_7 = - V_42 ;
goto V_89;
}
}
V_3 -> V_90 ++ ;
V_22 -> V_28 = V_3 ;
F_45 ( V_83 , V_22 ) ;
F_16 ( & V_85 ) ;
return 0 ;
V_89:
F_25 ( V_3 -> V_17 ) ;
V_3 -> V_17 = NULL ;
V_88:
F_16 ( & V_85 ) ;
return V_7 ;
}
static int F_46 ( struct V_83 * V_83 , struct V_21 * V_22 )
{
struct V_2 * V_3 ;
int V_7 = 0 ;
F_14 ( & V_85 ) ;
V_3 = V_22 -> V_28 ;
V_22 -> V_28 = NULL ;
V_3 -> V_90 -- ;
if ( ! V_3 -> V_90 ) {
int V_91 ;
F_25 ( V_3 -> V_17 ) ;
V_3 -> V_17 = NULL ;
F_25 ( V_3 -> V_20 ) ;
V_3 -> V_20 = NULL ;
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
V_3 = F_48 ( sizeof( * V_3 ) , V_41 ) ;
if ( ! V_3 )
return - V_42 ;
V_3 -> V_10 = V_10 ;
F_49 ( & V_3 -> V_9 ) ;
F_50 ( & V_3 -> V_29 ) ;
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
