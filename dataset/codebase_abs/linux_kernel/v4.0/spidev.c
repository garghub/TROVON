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
static struct V_33 *
F_26 ( unsigned int V_53 , struct V_33 T_3 * V_54 ,
unsigned * V_55 )
{
struct V_33 * V_56 ;
T_6 V_57 ;
if ( F_27 ( V_53 ) != V_58
|| F_28 ( V_53 ) != F_28 ( F_29 ( 0 ) )
|| F_30 ( V_53 ) != V_59 )
return F_31 ( - V_60 ) ;
V_57 = F_32 ( V_53 ) ;
if ( ( V_57 % sizeof( struct V_33 ) ) != 0 )
return F_31 ( - V_61 ) ;
* V_55 = V_57 / sizeof( struct V_33 ) ;
if ( * V_55 == 0 )
return NULL ;
V_56 = F_33 ( V_57 , V_42 ) ;
if ( ! V_56 )
return F_31 ( - V_43 ) ;
if ( F_34 ( V_56 , V_54 , V_57 ) ) {
F_25 ( V_56 ) ;
return F_31 ( - V_32 ) ;
}
return V_56 ;
}
static long
F_35 ( struct V_22 * V_23 , unsigned int V_53 , unsigned long V_1 )
{
int V_62 = 0 ;
int V_63 = 0 ;
struct V_2 * V_3 ;
struct V_64 * V_10 ;
T_6 V_57 ;
unsigned V_55 ;
struct V_33 * V_56 ;
if ( F_27 ( V_53 ) != V_58 )
return - V_60 ;
if ( F_30 ( V_53 ) & V_65 )
V_62 = ! F_21 ( V_44 ,
( void T_3 * ) V_1 , F_32 ( V_53 ) ) ;
if ( V_62 == 0 && F_30 ( V_53 ) & V_59 )
V_62 = ! F_21 ( V_66 ,
( void T_3 * ) V_1 , F_32 ( V_53 ) ) ;
if ( V_62 )
return - V_32 ;
V_3 = V_23 -> V_29 ;
F_5 ( & V_3 -> V_9 ) ;
V_10 = F_36 ( V_3 -> V_10 ) ;
F_7 ( & V_3 -> V_9 ) ;
if ( V_10 == NULL )
return - V_11 ;
F_14 ( & V_3 -> V_30 ) ;
switch ( V_53 ) {
case V_67 :
V_63 = F_37 ( V_10 -> V_68 & V_69 ,
( V_70 T_3 * ) V_1 ) ;
break;
case V_71 :
V_63 = F_37 ( V_10 -> V_68 & V_69 ,
( V_72 T_3 * ) V_1 ) ;
break;
case V_73 :
V_63 = F_37 ( ( V_10 -> V_68 & V_74 ) ? 1 : 0 ,
( V_70 T_3 * ) V_1 ) ;
break;
case V_75 :
V_63 = F_37 ( V_10 -> V_49 , ( V_70 T_3 * ) V_1 ) ;
break;
case V_76 :
V_63 = F_37 ( V_3 -> V_18 , ( V_72 T_3 * ) V_1 ) ;
break;
case V_77 :
case V_78 :
if ( V_53 == V_77 )
V_63 = F_38 ( V_57 , ( T_5 T_3 * ) V_1 ) ;
else
V_63 = F_38 ( V_57 , ( T_6 T_3 * ) V_1 ) ;
if ( V_63 == 0 ) {
T_6 V_79 = V_10 -> V_68 ;
if ( V_57 & ~ V_69 ) {
V_63 = - V_61 ;
break;
}
V_57 |= V_10 -> V_68 & ~ V_69 ;
V_10 -> V_68 = ( V_80 ) V_57 ;
V_63 = F_39 ( V_10 ) ;
if ( V_63 < 0 )
V_10 -> V_68 = V_79 ;
else
F_23 ( & V_10 -> V_51 , L_6 , V_57 ) ;
}
break;
case V_81 :
V_63 = F_38 ( V_57 , ( V_70 T_3 * ) V_1 ) ;
if ( V_63 == 0 ) {
T_6 V_79 = V_10 -> V_68 ;
if ( V_57 )
V_10 -> V_68 |= V_74 ;
else
V_10 -> V_68 &= ~ V_74 ;
V_63 = F_39 ( V_10 ) ;
if ( V_63 < 0 )
V_10 -> V_68 = V_79 ;
else
F_23 ( & V_10 -> V_51 , L_7 ,
V_57 ? 'l' : 'm' ) ;
}
break;
case V_82 :
V_63 = F_38 ( V_57 , ( V_70 T_3 * ) V_1 ) ;
if ( V_63 == 0 ) {
T_5 V_79 = V_10 -> V_49 ;
V_10 -> V_49 = V_57 ;
V_63 = F_39 ( V_10 ) ;
if ( V_63 < 0 )
V_10 -> V_49 = V_79 ;
else
F_23 ( & V_10 -> V_51 , L_8 , V_57 ) ;
}
break;
case V_83 :
V_63 = F_38 ( V_57 , ( V_72 T_3 * ) V_1 ) ;
if ( V_63 == 0 ) {
T_6 V_79 = V_10 -> V_52 ;
V_10 -> V_52 = V_57 ;
V_63 = F_39 ( V_10 ) ;
if ( V_63 >= 0 )
V_3 -> V_18 = V_57 ;
else
F_23 ( & V_10 -> V_51 , L_9 , V_57 ) ;
V_10 -> V_52 = V_79 ;
}
break;
default:
V_56 = F_26 ( V_53 ,
(struct V_33 T_3 * ) V_1 , & V_55 ) ;
if ( F_40 ( V_56 ) ) {
V_63 = F_41 ( V_56 ) ;
break;
}
if ( ! V_56 )
break;
V_63 = F_19 ( V_3 , V_56 , V_55 ) ;
F_25 ( V_56 ) ;
break;
}
F_16 ( & V_3 -> V_30 ) ;
F_42 ( V_10 ) ;
return V_63 ;
}
static long
F_43 ( struct V_22 * V_23 , unsigned int V_53 ,
unsigned long V_1 )
{
struct V_33 T_3 * V_54 ;
int V_63 = 0 ;
struct V_2 * V_3 ;
struct V_64 * V_10 ;
unsigned V_55 , V_40 ;
struct V_33 * V_56 ;
V_54 = (struct V_33 T_3 * ) F_44 ( V_1 ) ;
if ( ! F_21 ( V_66 , V_54 , F_32 ( V_53 ) ) )
return - V_32 ;
V_3 = V_23 -> V_29 ;
F_5 ( & V_3 -> V_9 ) ;
V_10 = F_36 ( V_3 -> V_10 ) ;
F_7 ( & V_3 -> V_9 ) ;
if ( V_10 == NULL )
return - V_11 ;
F_14 ( & V_3 -> V_30 ) ;
V_56 = F_26 ( V_53 , V_54 , & V_55 ) ;
if ( F_40 ( V_56 ) ) {
V_63 = F_41 ( V_56 ) ;
goto V_6;
}
if ( ! V_56 )
goto V_6;
for ( V_40 = 0 ; V_40 < V_55 ; V_40 ++ ) {
V_56 [ V_40 ] . V_20 = ( V_45 ) F_44 ( V_56 [ V_40 ] . V_20 ) ;
V_56 [ V_40 ] . V_16 = ( V_45 ) F_44 ( V_56 [ V_40 ] . V_16 ) ;
}
V_63 = F_19 ( V_3 , V_56 , V_55 ) ;
F_25 ( V_56 ) ;
V_6:
F_16 ( & V_3 -> V_30 ) ;
F_42 ( V_10 ) ;
return V_63 ;
}
static long
F_45 ( struct V_22 * V_23 , unsigned int V_53 , unsigned long V_1 )
{
if ( F_27 ( V_53 ) == V_58
&& F_28 ( V_53 ) == F_28 ( F_29 ( 0 ) )
&& F_30 ( V_53 ) == V_59 )
return F_43 ( V_23 , V_53 , V_1 ) ;
return F_35 ( V_23 , V_53 , ( unsigned long ) F_44 ( V_1 ) ) ;
}
static int F_46 ( struct V_84 * V_84 , struct V_22 * V_23 )
{
struct V_2 * V_3 ;
int V_7 = - V_85 ;
F_14 ( & V_86 ) ;
F_47 (spidev, &device_list, device_entry) {
if ( V_3 -> V_87 == V_84 -> V_88 ) {
V_7 = 0 ;
break;
}
}
if ( V_7 ) {
F_48 ( L_10 , F_49 ( V_84 ) ) ;
goto V_89;
}
if ( ! V_3 -> V_17 ) {
V_3 -> V_17 = F_33 ( V_27 , V_42 ) ;
if ( ! V_3 -> V_17 ) {
F_23 ( & V_3 -> V_10 -> V_51 , L_11 ) ;
V_7 = - V_43 ;
goto V_89;
}
}
if ( ! V_3 -> V_21 ) {
V_3 -> V_21 = F_33 ( V_27 , V_42 ) ;
if ( ! V_3 -> V_21 ) {
F_23 ( & V_3 -> V_10 -> V_51 , L_11 ) ;
V_7 = - V_43 ;
goto V_90;
}
}
V_3 -> V_91 ++ ;
V_23 -> V_29 = V_3 ;
F_50 ( V_84 , V_23 ) ;
F_16 ( & V_86 ) ;
return 0 ;
V_90:
F_25 ( V_3 -> V_17 ) ;
V_3 -> V_17 = NULL ;
V_89:
F_16 ( & V_86 ) ;
return V_7 ;
}
static int F_51 ( struct V_84 * V_84 , struct V_22 * V_23 )
{
struct V_2 * V_3 ;
int V_7 = 0 ;
F_14 ( & V_86 ) ;
V_3 = V_23 -> V_29 ;
V_23 -> V_29 = NULL ;
V_3 -> V_91 -- ;
if ( ! V_3 -> V_91 ) {
int V_92 ;
F_25 ( V_3 -> V_17 ) ;
V_3 -> V_17 = NULL ;
F_25 ( V_3 -> V_21 ) ;
V_3 -> V_21 = NULL ;
V_3 -> V_18 = V_3 -> V_10 -> V_52 ;
F_5 ( & V_3 -> V_9 ) ;
V_92 = ( V_3 -> V_10 == NULL ) ;
F_7 ( & V_3 -> V_9 ) ;
if ( V_92 )
F_25 ( V_3 ) ;
}
F_16 ( & V_86 ) ;
return V_7 ;
}
static int F_52 ( struct V_64 * V_10 )
{
struct V_2 * V_3 ;
int V_7 ;
unsigned long V_93 ;
V_3 = F_53 ( sizeof( * V_3 ) , V_42 ) ;
if ( ! V_3 )
return - V_43 ;
V_3 -> V_10 = V_10 ;
F_54 ( & V_3 -> V_9 ) ;
F_55 ( & V_3 -> V_30 ) ;
F_56 ( & V_3 -> V_94 ) ;
F_14 ( & V_86 ) ;
V_93 = F_57 ( V_95 , V_96 ) ;
if ( V_93 < V_96 ) {
struct V_97 * V_51 ;
V_3 -> V_87 = F_58 ( V_98 , V_93 ) ;
V_51 = F_59 ( V_99 , & V_10 -> V_51 , V_3 -> V_87 ,
V_3 , L_12 ,
V_10 -> V_100 -> V_101 , V_10 -> V_102 ) ;
V_7 = F_60 ( V_51 ) ;
} else {
F_23 ( & V_10 -> V_51 , L_13 ) ;
V_7 = - V_103 ;
}
if ( V_7 == 0 ) {
F_61 ( V_93 , V_95 ) ;
F_62 ( & V_3 -> V_94 , & V_104 ) ;
}
F_16 ( & V_86 ) ;
V_3 -> V_18 = V_10 -> V_52 ;
if ( V_7 == 0 )
F_63 ( V_10 , V_3 ) ;
else
F_25 ( V_3 ) ;
return V_7 ;
}
static int F_64 ( struct V_64 * V_10 )
{
struct V_2 * V_3 = F_65 ( V_10 ) ;
F_5 ( & V_3 -> V_9 ) ;
V_3 -> V_10 = NULL ;
F_7 ( & V_3 -> V_9 ) ;
F_14 ( & V_86 ) ;
F_66 ( & V_3 -> V_94 ) ;
F_67 ( V_99 , V_3 -> V_87 ) ;
F_68 ( F_69 ( V_3 -> V_87 ) , V_95 ) ;
if ( V_3 -> V_91 == 0 )
F_25 ( V_3 ) ;
F_16 ( & V_86 ) ;
return 0 ;
}
static int T_7 F_70 ( void )
{
int V_7 ;
F_71 ( V_96 > 256 ) ;
V_7 = F_72 ( V_98 , L_14 , & V_105 ) ;
if ( V_7 < 0 )
return V_7 ;
V_99 = F_73 ( V_106 , L_15 ) ;
if ( F_40 ( V_99 ) ) {
F_74 ( V_98 , V_107 . V_108 . V_109 ) ;
return F_41 ( V_99 ) ;
}
V_7 = F_75 ( & V_107 ) ;
if ( V_7 < 0 ) {
F_76 ( V_99 ) ;
F_74 ( V_98 , V_107 . V_108 . V_109 ) ;
}
return V_7 ;
}
static void T_8 F_77 ( void )
{
F_78 ( & V_107 ) ;
F_76 ( V_99 ) ;
F_74 ( V_98 , V_107 . V_108 . V_109 ) ;
}
