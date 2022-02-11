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
unsigned V_40 , V_41 , V_42 , V_43 ;
T_5 * V_16 , * V_20 ;
int V_7 = - V_32 ;
F_10 ( & V_36 ) ;
V_37 = F_20 ( V_35 , sizeof( * V_38 ) , V_44 ) ;
if ( V_37 == NULL )
return - V_45 ;
V_16 = V_3 -> V_17 ;
V_20 = V_3 -> V_21 ;
V_41 = 0 ;
V_42 = 0 ;
V_43 = 0 ;
for ( V_40 = V_35 , V_38 = V_37 , V_39 = V_34 ;
V_40 ;
V_40 -- , V_38 ++ , V_39 ++ ) {
V_38 -> V_13 = V_39 -> V_13 ;
V_41 += V_38 -> V_13 ;
if ( V_41 > V_46 || V_38 -> V_13 > V_46 ) {
V_7 = - V_28 ;
goto V_6;
}
if ( V_39 -> V_20 ) {
V_43 += V_38 -> V_13 ;
if ( V_43 > V_27 ) {
V_7 = - V_28 ;
goto V_6;
}
V_38 -> V_20 = V_20 ;
if ( ! F_21 ( V_47 , ( T_5 T_3 * )
( V_48 ) V_39 -> V_20 ,
V_39 -> V_13 ) )
goto V_6;
V_20 += V_38 -> V_13 ;
}
if ( V_39 -> V_16 ) {
V_42 += V_38 -> V_13 ;
if ( V_42 > V_27 ) {
V_7 = - V_28 ;
goto V_6;
}
V_38 -> V_16 = V_16 ;
if ( F_18 ( V_16 , ( const T_5 T_3 * )
( V_48 ) V_39 -> V_16 ,
V_39 -> V_13 ) )
goto V_6;
V_16 += V_38 -> V_13 ;
}
V_38 -> V_49 = ! ! V_39 -> V_49 ;
V_38 -> V_50 = V_39 -> V_50 ;
V_38 -> V_51 = V_39 -> V_51 ;
V_38 -> V_52 = V_39 -> V_52 ;
V_38 -> V_53 = V_39 -> V_53 ;
V_38 -> V_18 = V_39 -> V_18 ;
if ( ! V_38 -> V_18 )
V_38 -> V_18 = V_3 -> V_18 ;
#ifdef F_22
F_23 ( & V_3 -> V_10 -> V_54 ,
L_1 ,
V_39 -> V_13 ,
V_39 -> V_20 ? L_2 : L_3 ,
V_39 -> V_16 ? L_4 : L_3 ,
V_39 -> V_49 ? L_5 : L_3 ,
V_39 -> V_52 ? : V_3 -> V_10 -> V_52 ,
V_39 -> V_53 ,
V_39 -> V_18 ? : V_3 -> V_10 -> V_55 ) ;
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
( V_48 ) V_39 -> V_20 , V_20 ,
V_39 -> V_13 ) ) {
V_7 = - V_32 ;
goto V_6;
}
V_20 += V_39 -> V_13 ;
}
}
V_7 = V_41 ;
V_6:
F_25 ( V_37 ) ;
return V_7 ;
}
static struct V_33 *
F_26 ( unsigned int V_56 , struct V_33 T_3 * V_57 ,
unsigned * V_58 )
{
struct V_33 * V_59 ;
T_6 V_60 ;
if ( F_27 ( V_56 ) != V_61
|| F_28 ( V_56 ) != F_28 ( F_29 ( 0 ) )
|| F_30 ( V_56 ) != V_62 )
return F_31 ( - V_63 ) ;
V_60 = F_32 ( V_56 ) ;
if ( ( V_60 % sizeof( struct V_33 ) ) != 0 )
return F_31 ( - V_64 ) ;
* V_58 = V_60 / sizeof( struct V_33 ) ;
if ( * V_58 == 0 )
return NULL ;
V_59 = F_33 ( V_60 , V_44 ) ;
if ( ! V_59 )
return F_31 ( - V_45 ) ;
if ( F_34 ( V_59 , V_57 , V_60 ) ) {
F_25 ( V_59 ) ;
return F_31 ( - V_32 ) ;
}
return V_59 ;
}
static long
F_35 ( struct V_22 * V_23 , unsigned int V_56 , unsigned long V_1 )
{
int V_65 = 0 ;
int V_66 = 0 ;
struct V_2 * V_3 ;
struct V_67 * V_10 ;
T_6 V_60 ;
unsigned V_58 ;
struct V_33 * V_59 ;
if ( F_27 ( V_56 ) != V_61 )
return - V_63 ;
if ( F_30 ( V_56 ) & V_68 )
V_65 = ! F_21 ( V_47 ,
( void T_3 * ) V_1 , F_32 ( V_56 ) ) ;
if ( V_65 == 0 && F_30 ( V_56 ) & V_62 )
V_65 = ! F_21 ( V_69 ,
( void T_3 * ) V_1 , F_32 ( V_56 ) ) ;
if ( V_65 )
return - V_32 ;
V_3 = V_23 -> V_29 ;
F_5 ( & V_3 -> V_9 ) ;
V_10 = F_36 ( V_3 -> V_10 ) ;
F_7 ( & V_3 -> V_9 ) ;
if ( V_10 == NULL )
return - V_11 ;
F_14 ( & V_3 -> V_30 ) ;
switch ( V_56 ) {
case V_70 :
V_66 = F_37 ( V_10 -> V_71 & V_72 ,
( V_73 T_3 * ) V_1 ) ;
break;
case V_74 :
V_66 = F_37 ( V_10 -> V_71 & V_72 ,
( V_75 T_3 * ) V_1 ) ;
break;
case V_76 :
V_66 = F_37 ( ( V_10 -> V_71 & V_77 ) ? 1 : 0 ,
( V_73 T_3 * ) V_1 ) ;
break;
case V_78 :
V_66 = F_37 ( V_10 -> V_52 , ( V_73 T_3 * ) V_1 ) ;
break;
case V_79 :
V_66 = F_37 ( V_3 -> V_18 , ( V_75 T_3 * ) V_1 ) ;
break;
case V_80 :
case V_81 :
if ( V_56 == V_80 )
V_66 = F_38 ( V_60 , ( T_5 T_3 * ) V_1 ) ;
else
V_66 = F_38 ( V_60 , ( T_6 T_3 * ) V_1 ) ;
if ( V_66 == 0 ) {
T_6 V_82 = V_10 -> V_71 ;
if ( V_60 & ~ V_72 ) {
V_66 = - V_64 ;
break;
}
V_60 |= V_10 -> V_71 & ~ V_72 ;
V_10 -> V_71 = ( V_83 ) V_60 ;
V_66 = F_39 ( V_10 ) ;
if ( V_66 < 0 )
V_10 -> V_71 = V_82 ;
else
F_23 ( & V_10 -> V_54 , L_6 , V_60 ) ;
}
break;
case V_84 :
V_66 = F_38 ( V_60 , ( V_73 T_3 * ) V_1 ) ;
if ( V_66 == 0 ) {
T_6 V_82 = V_10 -> V_71 ;
if ( V_60 )
V_10 -> V_71 |= V_77 ;
else
V_10 -> V_71 &= ~ V_77 ;
V_66 = F_39 ( V_10 ) ;
if ( V_66 < 0 )
V_10 -> V_71 = V_82 ;
else
F_23 ( & V_10 -> V_54 , L_7 ,
V_60 ? 'l' : 'm' ) ;
}
break;
case V_85 :
V_66 = F_38 ( V_60 , ( V_73 T_3 * ) V_1 ) ;
if ( V_66 == 0 ) {
T_5 V_82 = V_10 -> V_52 ;
V_10 -> V_52 = V_60 ;
V_66 = F_39 ( V_10 ) ;
if ( V_66 < 0 )
V_10 -> V_52 = V_82 ;
else
F_23 ( & V_10 -> V_54 , L_8 , V_60 ) ;
}
break;
case V_86 :
V_66 = F_38 ( V_60 , ( V_75 T_3 * ) V_1 ) ;
if ( V_66 == 0 ) {
T_6 V_82 = V_10 -> V_55 ;
V_10 -> V_55 = V_60 ;
V_66 = F_39 ( V_10 ) ;
if ( V_66 >= 0 )
V_3 -> V_18 = V_60 ;
else
F_23 ( & V_10 -> V_54 , L_9 , V_60 ) ;
V_10 -> V_55 = V_82 ;
}
break;
default:
V_59 = F_26 ( V_56 ,
(struct V_33 T_3 * ) V_1 , & V_58 ) ;
if ( F_40 ( V_59 ) ) {
V_66 = F_41 ( V_59 ) ;
break;
}
if ( ! V_59 )
break;
V_66 = F_19 ( V_3 , V_59 , V_58 ) ;
F_25 ( V_59 ) ;
break;
}
F_16 ( & V_3 -> V_30 ) ;
F_42 ( V_10 ) ;
return V_66 ;
}
static long
F_43 ( struct V_22 * V_23 , unsigned int V_56 ,
unsigned long V_1 )
{
struct V_33 T_3 * V_57 ;
int V_66 = 0 ;
struct V_2 * V_3 ;
struct V_67 * V_10 ;
unsigned V_58 , V_40 ;
struct V_33 * V_59 ;
V_57 = (struct V_33 T_3 * ) F_44 ( V_1 ) ;
if ( ! F_21 ( V_69 , V_57 , F_32 ( V_56 ) ) )
return - V_32 ;
V_3 = V_23 -> V_29 ;
F_5 ( & V_3 -> V_9 ) ;
V_10 = F_36 ( V_3 -> V_10 ) ;
F_7 ( & V_3 -> V_9 ) ;
if ( V_10 == NULL )
return - V_11 ;
F_14 ( & V_3 -> V_30 ) ;
V_59 = F_26 ( V_56 , V_57 , & V_58 ) ;
if ( F_40 ( V_59 ) ) {
V_66 = F_41 ( V_59 ) ;
goto V_6;
}
if ( ! V_59 )
goto V_6;
for ( V_40 = 0 ; V_40 < V_58 ; V_40 ++ ) {
V_59 [ V_40 ] . V_20 = ( V_48 ) F_44 ( V_59 [ V_40 ] . V_20 ) ;
V_59 [ V_40 ] . V_16 = ( V_48 ) F_44 ( V_59 [ V_40 ] . V_16 ) ;
}
V_66 = F_19 ( V_3 , V_59 , V_58 ) ;
F_25 ( V_59 ) ;
V_6:
F_16 ( & V_3 -> V_30 ) ;
F_42 ( V_10 ) ;
return V_66 ;
}
static long
F_45 ( struct V_22 * V_23 , unsigned int V_56 , unsigned long V_1 )
{
if ( F_27 ( V_56 ) == V_61
&& F_28 ( V_56 ) == F_28 ( F_29 ( 0 ) )
&& F_30 ( V_56 ) == V_62 )
return F_43 ( V_23 , V_56 , V_1 ) ;
return F_35 ( V_23 , V_56 , ( unsigned long ) F_44 ( V_1 ) ) ;
}
static int F_46 ( struct V_87 * V_87 , struct V_22 * V_23 )
{
struct V_2 * V_3 ;
int V_7 = - V_88 ;
F_14 ( & V_89 ) ;
F_47 (spidev, &device_list, device_entry) {
if ( V_3 -> V_90 == V_87 -> V_91 ) {
V_7 = 0 ;
break;
}
}
if ( V_7 ) {
F_48 ( L_10 , F_49 ( V_87 ) ) ;
goto V_92;
}
if ( ! V_3 -> V_17 ) {
V_3 -> V_17 = F_33 ( V_27 , V_44 ) ;
if ( ! V_3 -> V_17 ) {
F_23 ( & V_3 -> V_10 -> V_54 , L_11 ) ;
V_7 = - V_45 ;
goto V_92;
}
}
if ( ! V_3 -> V_21 ) {
V_3 -> V_21 = F_33 ( V_27 , V_44 ) ;
if ( ! V_3 -> V_21 ) {
F_23 ( & V_3 -> V_10 -> V_54 , L_11 ) ;
V_7 = - V_45 ;
goto V_93;
}
}
V_3 -> V_94 ++ ;
V_23 -> V_29 = V_3 ;
F_50 ( V_87 , V_23 ) ;
F_16 ( & V_89 ) ;
return 0 ;
V_93:
F_25 ( V_3 -> V_17 ) ;
V_3 -> V_17 = NULL ;
V_92:
F_16 ( & V_89 ) ;
return V_7 ;
}
static int F_51 ( struct V_87 * V_87 , struct V_22 * V_23 )
{
struct V_2 * V_3 ;
int V_7 = 0 ;
F_14 ( & V_89 ) ;
V_3 = V_23 -> V_29 ;
V_23 -> V_29 = NULL ;
V_3 -> V_94 -- ;
if ( ! V_3 -> V_94 ) {
int V_95 ;
F_25 ( V_3 -> V_17 ) ;
V_3 -> V_17 = NULL ;
F_25 ( V_3 -> V_21 ) ;
V_3 -> V_21 = NULL ;
V_3 -> V_18 = V_3 -> V_10 -> V_55 ;
F_5 ( & V_3 -> V_9 ) ;
V_95 = ( V_3 -> V_10 == NULL ) ;
F_7 ( & V_3 -> V_9 ) ;
if ( V_95 )
F_25 ( V_3 ) ;
}
F_16 ( & V_89 ) ;
return V_7 ;
}
static int F_52 ( struct V_67 * V_10 )
{
struct V_2 * V_3 ;
int V_7 ;
unsigned long V_96 ;
if ( V_10 -> V_54 . V_97 && ! F_53 ( V_98 , & V_10 -> V_54 ) ) {
F_54 ( & V_10 -> V_54 , L_12 ) ;
F_55 ( V_10 -> V_54 . V_97 &&
! F_53 ( V_98 , & V_10 -> V_54 ) ) ;
}
V_3 = F_56 ( sizeof( * V_3 ) , V_44 ) ;
if ( ! V_3 )
return - V_45 ;
V_3 -> V_10 = V_10 ;
F_57 ( & V_3 -> V_9 ) ;
F_58 ( & V_3 -> V_30 ) ;
F_59 ( & V_3 -> V_99 ) ;
F_14 ( & V_89 ) ;
V_96 = F_60 ( V_100 , V_101 ) ;
if ( V_96 < V_101 ) {
struct V_102 * V_54 ;
V_3 -> V_90 = F_61 ( V_103 , V_96 ) ;
V_54 = F_62 ( V_104 , & V_10 -> V_54 , V_3 -> V_90 ,
V_3 , L_13 ,
V_10 -> V_105 -> V_106 , V_10 -> V_107 ) ;
V_7 = F_63 ( V_54 ) ;
} else {
F_23 ( & V_10 -> V_54 , L_14 ) ;
V_7 = - V_108 ;
}
if ( V_7 == 0 ) {
F_64 ( V_96 , V_100 ) ;
F_65 ( & V_3 -> V_99 , & V_109 ) ;
}
F_16 ( & V_89 ) ;
V_3 -> V_18 = V_10 -> V_55 ;
if ( V_7 == 0 )
F_66 ( V_10 , V_3 ) ;
else
F_25 ( V_3 ) ;
return V_7 ;
}
static int F_67 ( struct V_67 * V_10 )
{
struct V_2 * V_3 = F_68 ( V_10 ) ;
F_5 ( & V_3 -> V_9 ) ;
V_3 -> V_10 = NULL ;
F_7 ( & V_3 -> V_9 ) ;
F_14 ( & V_89 ) ;
F_69 ( & V_3 -> V_99 ) ;
F_70 ( V_104 , V_3 -> V_90 ) ;
F_71 ( F_72 ( V_3 -> V_90 ) , V_100 ) ;
if ( V_3 -> V_94 == 0 )
F_25 ( V_3 ) ;
F_16 ( & V_89 ) ;
return 0 ;
}
static int T_7 F_73 ( void )
{
int V_7 ;
F_74 ( V_101 > 256 ) ;
V_7 = F_75 ( V_103 , L_15 , & V_110 ) ;
if ( V_7 < 0 )
return V_7 ;
V_104 = F_76 ( V_111 , L_16 ) ;
if ( F_40 ( V_104 ) ) {
F_77 ( V_103 , V_112 . V_113 . V_114 ) ;
return F_41 ( V_104 ) ;
}
V_7 = F_78 ( & V_112 ) ;
if ( V_7 < 0 ) {
F_79 ( V_104 ) ;
F_77 ( V_103 , V_112 . V_113 . V_114 ) ;
}
return V_7 ;
}
static void T_8 F_80 ( void )
{
F_81 ( & V_112 ) ;
F_79 ( V_104 ) ;
F_77 ( V_103 , V_112 . V_113 . V_114 ) ;
}
