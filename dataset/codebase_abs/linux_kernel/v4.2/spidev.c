static T_1
F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_2 ( V_5 ) ;
int V_6 ;
struct V_7 * V_8 ;
F_3 ( & V_2 -> V_9 ) ;
V_8 = V_2 -> V_8 ;
F_4 ( & V_2 -> V_9 ) ;
if ( V_8 == NULL )
V_6 = - V_10 ;
else
V_6 = F_5 ( V_8 , V_4 ) ;
if ( V_6 == 0 )
V_6 = V_4 -> V_11 ;
return V_6 ;
}
static inline T_1
F_6 ( struct V_1 * V_2 , T_2 V_12 )
{
struct V_13 V_14 = {
. V_15 = V_2 -> V_16 ,
. V_12 = V_12 ,
. V_17 = V_2 -> V_17 ,
} ;
struct V_3 V_18 ;
F_7 ( & V_18 ) ;
F_8 ( & V_14 , & V_18 ) ;
return F_1 ( V_2 , & V_18 ) ;
}
static inline T_1
F_9 ( struct V_1 * V_2 , T_2 V_12 )
{
struct V_13 V_14 = {
. V_19 = V_2 -> V_20 ,
. V_12 = V_12 ,
. V_17 = V_2 -> V_17 ,
} ;
struct V_3 V_18 ;
F_7 ( & V_18 ) ;
F_8 ( & V_14 , & V_18 ) ;
return F_1 ( V_2 , & V_18 ) ;
}
static T_1
F_10 ( struct V_21 * V_22 , char T_3 * V_23 , T_2 V_24 , T_4 * V_25 )
{
struct V_1 * V_2 ;
T_1 V_6 = 0 ;
if ( V_24 > V_26 )
return - V_27 ;
V_2 = V_22 -> V_28 ;
F_11 ( & V_2 -> V_29 ) ;
V_6 = F_9 ( V_2 , V_24 ) ;
if ( V_6 > 0 ) {
unsigned long V_30 ;
V_30 = F_12 ( V_23 , V_2 -> V_20 , V_6 ) ;
if ( V_30 == V_6 )
V_6 = - V_31 ;
else
V_6 = V_6 - V_30 ;
}
F_13 ( & V_2 -> V_29 ) ;
return V_6 ;
}
static T_1
F_14 ( struct V_21 * V_22 , const char T_3 * V_23 ,
T_2 V_24 , T_4 * V_25 )
{
struct V_1 * V_2 ;
T_1 V_6 = 0 ;
unsigned long V_30 ;
if ( V_24 > V_26 )
return - V_27 ;
V_2 = V_22 -> V_28 ;
F_11 ( & V_2 -> V_29 ) ;
V_30 = F_15 ( V_2 -> V_16 , V_23 , V_24 ) ;
if ( V_30 == 0 )
V_6 = F_6 ( V_2 , V_24 ) ;
else
V_6 = - V_31 ;
F_13 ( & V_2 -> V_29 ) ;
return V_6 ;
}
static int F_16 ( struct V_1 * V_2 ,
struct V_32 * V_33 , unsigned V_34 )
{
struct V_3 V_35 ;
struct V_13 * V_36 ;
struct V_13 * V_37 ;
struct V_32 * V_38 ;
unsigned V_39 , V_40 , V_41 , V_42 ;
T_5 * V_15 , * V_19 ;
int V_6 = - V_31 ;
F_7 ( & V_35 ) ;
V_36 = F_17 ( V_34 , sizeof( * V_37 ) , V_43 ) ;
if ( V_36 == NULL )
return - V_44 ;
V_15 = V_2 -> V_16 ;
V_19 = V_2 -> V_20 ;
V_40 = 0 ;
V_41 = 0 ;
V_42 = 0 ;
for ( V_39 = V_34 , V_37 = V_36 , V_38 = V_33 ;
V_39 ;
V_39 -- , V_37 ++ , V_38 ++ ) {
V_37 -> V_12 = V_38 -> V_12 ;
V_40 += V_37 -> V_12 ;
if ( V_40 > V_45 || V_37 -> V_12 > V_45 ) {
V_6 = - V_27 ;
goto V_5;
}
if ( V_38 -> V_19 ) {
V_42 += V_37 -> V_12 ;
if ( V_42 > V_26 ) {
V_6 = - V_27 ;
goto V_5;
}
V_37 -> V_19 = V_19 ;
if ( ! F_18 ( V_46 , ( T_5 T_3 * )
( V_47 ) V_38 -> V_19 ,
V_38 -> V_12 ) )
goto V_5;
V_19 += V_37 -> V_12 ;
}
if ( V_38 -> V_15 ) {
V_41 += V_37 -> V_12 ;
if ( V_41 > V_26 ) {
V_6 = - V_27 ;
goto V_5;
}
V_37 -> V_15 = V_15 ;
if ( F_15 ( V_15 , ( const T_5 T_3 * )
( V_47 ) V_38 -> V_15 ,
V_38 -> V_12 ) )
goto V_5;
V_15 += V_37 -> V_12 ;
}
V_37 -> V_48 = ! ! V_38 -> V_48 ;
V_37 -> V_49 = V_38 -> V_49 ;
V_37 -> V_50 = V_38 -> V_50 ;
V_37 -> V_51 = V_38 -> V_51 ;
V_37 -> V_52 = V_38 -> V_52 ;
V_37 -> V_17 = V_38 -> V_17 ;
if ( ! V_37 -> V_17 )
V_37 -> V_17 = V_2 -> V_17 ;
#ifdef F_19
F_20 ( & V_2 -> V_8 -> V_53 ,
L_1 ,
V_38 -> V_12 ,
V_38 -> V_19 ? L_2 : L_3 ,
V_38 -> V_15 ? L_4 : L_3 ,
V_38 -> V_48 ? L_5 : L_3 ,
V_38 -> V_51 ? : V_2 -> V_8 -> V_51 ,
V_38 -> V_52 ,
V_38 -> V_17 ? : V_2 -> V_8 -> V_54 ) ;
#endif
F_8 ( V_37 , & V_35 ) ;
}
V_6 = F_1 ( V_2 , & V_35 ) ;
if ( V_6 < 0 )
goto V_5;
V_19 = V_2 -> V_20 ;
for ( V_39 = V_34 , V_38 = V_33 ; V_39 ; V_39 -- , V_38 ++ ) {
if ( V_38 -> V_19 ) {
if ( F_21 ( ( T_5 T_3 * )
( V_47 ) V_38 -> V_19 , V_19 ,
V_38 -> V_12 ) ) {
V_6 = - V_31 ;
goto V_5;
}
V_19 += V_38 -> V_12 ;
}
}
V_6 = V_40 ;
V_5:
F_22 ( V_36 ) ;
return V_6 ;
}
static struct V_32 *
F_23 ( unsigned int V_55 , struct V_32 T_3 * V_56 ,
unsigned * V_57 )
{
struct V_32 * V_58 ;
T_6 V_59 ;
if ( F_24 ( V_55 ) != V_60
|| F_25 ( V_55 ) != F_25 ( F_26 ( 0 ) )
|| F_27 ( V_55 ) != V_61 )
return F_28 ( - V_62 ) ;
V_59 = F_29 ( V_55 ) ;
if ( ( V_59 % sizeof( struct V_32 ) ) != 0 )
return F_28 ( - V_63 ) ;
* V_57 = V_59 / sizeof( struct V_32 ) ;
if ( * V_57 == 0 )
return NULL ;
V_58 = F_30 ( V_59 , V_43 ) ;
if ( ! V_58 )
return F_28 ( - V_44 ) ;
if ( F_31 ( V_58 , V_56 , V_59 ) ) {
F_22 ( V_58 ) ;
return F_28 ( - V_31 ) ;
}
return V_58 ;
}
static long
F_32 ( struct V_21 * V_22 , unsigned int V_55 , unsigned long V_64 )
{
int V_65 = 0 ;
int V_66 = 0 ;
struct V_1 * V_2 ;
struct V_7 * V_8 ;
T_6 V_59 ;
unsigned V_57 ;
struct V_32 * V_58 ;
if ( F_24 ( V_55 ) != V_60 )
return - V_62 ;
if ( F_27 ( V_55 ) & V_67 )
V_65 = ! F_18 ( V_46 ,
( void T_3 * ) V_64 , F_29 ( V_55 ) ) ;
if ( V_65 == 0 && F_27 ( V_55 ) & V_61 )
V_65 = ! F_18 ( V_68 ,
( void T_3 * ) V_64 , F_29 ( V_55 ) ) ;
if ( V_65 )
return - V_31 ;
V_2 = V_22 -> V_28 ;
F_3 ( & V_2 -> V_9 ) ;
V_8 = F_33 ( V_2 -> V_8 ) ;
F_4 ( & V_2 -> V_9 ) ;
if ( V_8 == NULL )
return - V_10 ;
F_11 ( & V_2 -> V_29 ) ;
switch ( V_55 ) {
case V_69 :
V_66 = F_34 ( V_8 -> V_70 & V_71 ,
( V_72 T_3 * ) V_64 ) ;
break;
case V_73 :
V_66 = F_34 ( V_8 -> V_70 & V_71 ,
( V_74 T_3 * ) V_64 ) ;
break;
case V_75 :
V_66 = F_34 ( ( V_8 -> V_70 & V_76 ) ? 1 : 0 ,
( V_72 T_3 * ) V_64 ) ;
break;
case V_77 :
V_66 = F_34 ( V_8 -> V_51 , ( V_72 T_3 * ) V_64 ) ;
break;
case V_78 :
V_66 = F_34 ( V_2 -> V_17 , ( V_74 T_3 * ) V_64 ) ;
break;
case V_79 :
case V_80 :
if ( V_55 == V_79 )
V_66 = F_35 ( V_59 , ( T_5 T_3 * ) V_64 ) ;
else
V_66 = F_35 ( V_59 , ( T_6 T_3 * ) V_64 ) ;
if ( V_66 == 0 ) {
T_6 V_81 = V_8 -> V_70 ;
if ( V_59 & ~ V_71 ) {
V_66 = - V_63 ;
break;
}
V_59 |= V_8 -> V_70 & ~ V_71 ;
V_8 -> V_70 = ( V_82 ) V_59 ;
V_66 = F_36 ( V_8 ) ;
if ( V_66 < 0 )
V_8 -> V_70 = V_81 ;
else
F_20 ( & V_8 -> V_53 , L_6 , V_59 ) ;
}
break;
case V_83 :
V_66 = F_35 ( V_59 , ( V_72 T_3 * ) V_64 ) ;
if ( V_66 == 0 ) {
T_6 V_81 = V_8 -> V_70 ;
if ( V_59 )
V_8 -> V_70 |= V_76 ;
else
V_8 -> V_70 &= ~ V_76 ;
V_66 = F_36 ( V_8 ) ;
if ( V_66 < 0 )
V_8 -> V_70 = V_81 ;
else
F_20 ( & V_8 -> V_53 , L_7 ,
V_59 ? 'l' : 'm' ) ;
}
break;
case V_84 :
V_66 = F_35 ( V_59 , ( V_72 T_3 * ) V_64 ) ;
if ( V_66 == 0 ) {
T_5 V_81 = V_8 -> V_51 ;
V_8 -> V_51 = V_59 ;
V_66 = F_36 ( V_8 ) ;
if ( V_66 < 0 )
V_8 -> V_51 = V_81 ;
else
F_20 ( & V_8 -> V_53 , L_8 , V_59 ) ;
}
break;
case V_85 :
V_66 = F_35 ( V_59 , ( V_74 T_3 * ) V_64 ) ;
if ( V_66 == 0 ) {
T_6 V_81 = V_8 -> V_54 ;
V_8 -> V_54 = V_59 ;
V_66 = F_36 ( V_8 ) ;
if ( V_66 >= 0 )
V_2 -> V_17 = V_59 ;
else
F_20 ( & V_8 -> V_53 , L_9 , V_59 ) ;
V_8 -> V_54 = V_81 ;
}
break;
default:
V_58 = F_23 ( V_55 ,
(struct V_32 T_3 * ) V_64 , & V_57 ) ;
if ( F_37 ( V_58 ) ) {
V_66 = F_38 ( V_58 ) ;
break;
}
if ( ! V_58 )
break;
V_66 = F_16 ( V_2 , V_58 , V_57 ) ;
F_22 ( V_58 ) ;
break;
}
F_13 ( & V_2 -> V_29 ) ;
F_39 ( V_8 ) ;
return V_66 ;
}
static long
F_40 ( struct V_21 * V_22 , unsigned int V_55 ,
unsigned long V_64 )
{
struct V_32 T_3 * V_56 ;
int V_66 = 0 ;
struct V_1 * V_2 ;
struct V_7 * V_8 ;
unsigned V_57 , V_39 ;
struct V_32 * V_58 ;
V_56 = (struct V_32 T_3 * ) F_41 ( V_64 ) ;
if ( ! F_18 ( V_68 , V_56 , F_29 ( V_55 ) ) )
return - V_31 ;
V_2 = V_22 -> V_28 ;
F_3 ( & V_2 -> V_9 ) ;
V_8 = F_33 ( V_2 -> V_8 ) ;
F_4 ( & V_2 -> V_9 ) ;
if ( V_8 == NULL )
return - V_10 ;
F_11 ( & V_2 -> V_29 ) ;
V_58 = F_23 ( V_55 , V_56 , & V_57 ) ;
if ( F_37 ( V_58 ) ) {
V_66 = F_38 ( V_58 ) ;
goto V_5;
}
if ( ! V_58 )
goto V_5;
for ( V_39 = 0 ; V_39 < V_57 ; V_39 ++ ) {
V_58 [ V_39 ] . V_19 = ( V_47 ) F_41 ( V_58 [ V_39 ] . V_19 ) ;
V_58 [ V_39 ] . V_15 = ( V_47 ) F_41 ( V_58 [ V_39 ] . V_15 ) ;
}
V_66 = F_16 ( V_2 , V_58 , V_57 ) ;
F_22 ( V_58 ) ;
V_5:
F_13 ( & V_2 -> V_29 ) ;
F_39 ( V_8 ) ;
return V_66 ;
}
static long
F_42 ( struct V_21 * V_22 , unsigned int V_55 , unsigned long V_64 )
{
if ( F_24 ( V_55 ) == V_60
&& F_25 ( V_55 ) == F_25 ( F_26 ( 0 ) )
&& F_27 ( V_55 ) == V_61 )
return F_40 ( V_22 , V_55 , V_64 ) ;
return F_32 ( V_22 , V_55 , ( unsigned long ) F_41 ( V_64 ) ) ;
}
static int F_43 ( struct V_86 * V_86 , struct V_21 * V_22 )
{
struct V_1 * V_2 ;
int V_6 = - V_87 ;
F_11 ( & V_88 ) ;
F_44 (spidev, &device_list, device_entry) {
if ( V_2 -> V_89 == V_86 -> V_90 ) {
V_6 = 0 ;
break;
}
}
if ( V_6 ) {
F_45 ( L_10 , F_46 ( V_86 ) ) ;
goto V_91;
}
if ( ! V_2 -> V_16 ) {
V_2 -> V_16 = F_30 ( V_26 , V_43 ) ;
if ( ! V_2 -> V_16 ) {
F_20 ( & V_2 -> V_8 -> V_53 , L_11 ) ;
V_6 = - V_44 ;
goto V_91;
}
}
if ( ! V_2 -> V_20 ) {
V_2 -> V_20 = F_30 ( V_26 , V_43 ) ;
if ( ! V_2 -> V_20 ) {
F_20 ( & V_2 -> V_8 -> V_53 , L_11 ) ;
V_6 = - V_44 ;
goto V_92;
}
}
V_2 -> V_93 ++ ;
V_22 -> V_28 = V_2 ;
F_47 ( V_86 , V_22 ) ;
F_13 ( & V_88 ) ;
return 0 ;
V_92:
F_22 ( V_2 -> V_16 ) ;
V_2 -> V_16 = NULL ;
V_91:
F_13 ( & V_88 ) ;
return V_6 ;
}
static int F_48 ( struct V_86 * V_86 , struct V_21 * V_22 )
{
struct V_1 * V_2 ;
F_11 ( & V_88 ) ;
V_2 = V_22 -> V_28 ;
V_22 -> V_28 = NULL ;
V_2 -> V_93 -- ;
if ( ! V_2 -> V_93 ) {
int V_94 ;
F_22 ( V_2 -> V_16 ) ;
V_2 -> V_16 = NULL ;
F_22 ( V_2 -> V_20 ) ;
V_2 -> V_20 = NULL ;
V_2 -> V_17 = V_2 -> V_8 -> V_54 ;
F_3 ( & V_2 -> V_9 ) ;
V_94 = ( V_2 -> V_8 == NULL ) ;
F_4 ( & V_2 -> V_9 ) ;
if ( V_94 )
F_22 ( V_2 ) ;
}
F_13 ( & V_88 ) ;
return 0 ;
}
static int F_49 ( struct V_7 * V_8 )
{
struct V_1 * V_2 ;
int V_6 ;
unsigned long V_95 ;
if ( V_8 -> V_53 . V_96 && ! F_50 ( V_97 , & V_8 -> V_53 ) ) {
F_51 ( & V_8 -> V_53 , L_12 ) ;
F_52 ( V_8 -> V_53 . V_96 &&
! F_50 ( V_97 , & V_8 -> V_53 ) ) ;
}
V_2 = F_53 ( sizeof( * V_2 ) , V_43 ) ;
if ( ! V_2 )
return - V_44 ;
V_2 -> V_8 = V_8 ;
F_54 ( & V_2 -> V_9 ) ;
F_55 ( & V_2 -> V_29 ) ;
F_56 ( & V_2 -> V_98 ) ;
F_11 ( & V_88 ) ;
V_95 = F_57 ( V_99 , V_100 ) ;
if ( V_95 < V_100 ) {
struct V_101 * V_53 ;
V_2 -> V_89 = F_58 ( V_102 , V_95 ) ;
V_53 = F_59 ( V_103 , & V_8 -> V_53 , V_2 -> V_89 ,
V_2 , L_13 ,
V_8 -> V_104 -> V_105 , V_8 -> V_106 ) ;
V_6 = F_60 ( V_53 ) ;
} else {
F_20 ( & V_8 -> V_53 , L_14 ) ;
V_6 = - V_107 ;
}
if ( V_6 == 0 ) {
F_61 ( V_95 , V_99 ) ;
F_62 ( & V_2 -> V_98 , & V_108 ) ;
}
F_13 ( & V_88 ) ;
V_2 -> V_17 = V_8 -> V_54 ;
if ( V_6 == 0 )
F_63 ( V_8 , V_2 ) ;
else
F_22 ( V_2 ) ;
return V_6 ;
}
static int F_64 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = F_65 ( V_8 ) ;
F_3 ( & V_2 -> V_9 ) ;
V_2 -> V_8 = NULL ;
F_4 ( & V_2 -> V_9 ) ;
F_11 ( & V_88 ) ;
F_66 ( & V_2 -> V_98 ) ;
F_67 ( V_103 , V_2 -> V_89 ) ;
F_68 ( F_69 ( V_2 -> V_89 ) , V_99 ) ;
if ( V_2 -> V_93 == 0 )
F_22 ( V_2 ) ;
F_13 ( & V_88 ) ;
return 0 ;
}
static int T_7 F_70 ( void )
{
int V_6 ;
F_71 ( V_100 > 256 ) ;
V_6 = F_72 ( V_102 , L_15 , & V_109 ) ;
if ( V_6 < 0 )
return V_6 ;
V_103 = F_73 ( V_110 , L_16 ) ;
if ( F_37 ( V_103 ) ) {
F_74 ( V_102 , V_111 . V_112 . V_113 ) ;
return F_38 ( V_103 ) ;
}
V_6 = F_75 ( & V_111 ) ;
if ( V_6 < 0 ) {
F_76 ( V_103 ) ;
F_74 ( V_102 , V_111 . V_112 . V_113 ) ;
}
return V_6 ;
}
static void T_8 F_77 ( void )
{
F_78 ( & V_111 ) ;
F_76 ( V_103 ) ;
F_74 ( V_102 , V_111 . V_112 . V_113 ) ;
}
