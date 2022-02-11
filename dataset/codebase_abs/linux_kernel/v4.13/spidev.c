static T_1
F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_5 ;
struct V_6 * V_7 ;
F_2 ( & V_2 -> V_8 ) ;
V_7 = V_2 -> V_7 ;
F_3 ( & V_2 -> V_8 ) ;
if ( V_7 == NULL )
V_5 = - V_9 ;
else
V_5 = F_4 ( V_7 , V_4 ) ;
if ( V_5 == 0 )
V_5 = V_4 -> V_10 ;
return V_5 ;
}
static inline T_1
F_5 ( struct V_1 * V_2 , T_2 V_11 )
{
struct V_12 V_13 = {
. V_14 = V_2 -> V_15 ,
. V_11 = V_11 ,
. V_16 = V_2 -> V_16 ,
} ;
struct V_3 V_17 ;
F_6 ( & V_17 ) ;
F_7 ( & V_13 , & V_17 ) ;
return F_1 ( V_2 , & V_17 ) ;
}
static inline T_1
F_8 ( struct V_1 * V_2 , T_2 V_11 )
{
struct V_12 V_13 = {
. V_18 = V_2 -> V_19 ,
. V_11 = V_11 ,
. V_16 = V_2 -> V_16 ,
} ;
struct V_3 V_17 ;
F_6 ( & V_17 ) ;
F_7 ( & V_13 , & V_17 ) ;
return F_1 ( V_2 , & V_17 ) ;
}
static T_1
F_9 ( struct V_20 * V_21 , char T_3 * V_22 , T_2 V_23 , T_4 * V_24 )
{
struct V_1 * V_2 ;
T_1 V_5 = 0 ;
if ( V_23 > V_25 )
return - V_26 ;
V_2 = V_21 -> V_27 ;
F_10 ( & V_2 -> V_28 ) ;
V_5 = F_8 ( V_2 , V_23 ) ;
if ( V_5 > 0 ) {
unsigned long V_29 ;
V_29 = F_11 ( V_22 , V_2 -> V_19 , V_5 ) ;
if ( V_29 == V_5 )
V_5 = - V_30 ;
else
V_5 = V_5 - V_29 ;
}
F_12 ( & V_2 -> V_28 ) ;
return V_5 ;
}
static T_1
F_13 ( struct V_20 * V_21 , const char T_3 * V_22 ,
T_2 V_23 , T_4 * V_24 )
{
struct V_1 * V_2 ;
T_1 V_5 = 0 ;
unsigned long V_29 ;
if ( V_23 > V_25 )
return - V_26 ;
V_2 = V_21 -> V_27 ;
F_10 ( & V_2 -> V_28 ) ;
V_29 = F_14 ( V_2 -> V_15 , V_22 , V_23 ) ;
if ( V_29 == 0 )
V_5 = F_5 ( V_2 , V_23 ) ;
else
V_5 = - V_30 ;
F_12 ( & V_2 -> V_28 ) ;
return V_5 ;
}
static int F_15 ( struct V_1 * V_2 ,
struct V_31 * V_32 , unsigned V_33 )
{
struct V_3 V_34 ;
struct V_12 * V_35 ;
struct V_12 * V_36 ;
struct V_31 * V_37 ;
unsigned V_38 , V_39 , V_40 , V_41 ;
T_5 * V_14 , * V_18 ;
int V_5 = - V_30 ;
F_6 ( & V_34 ) ;
V_35 = F_16 ( V_33 , sizeof( * V_36 ) , V_42 ) ;
if ( V_35 == NULL )
return - V_43 ;
V_14 = V_2 -> V_15 ;
V_18 = V_2 -> V_19 ;
V_39 = 0 ;
V_40 = 0 ;
V_41 = 0 ;
for ( V_38 = V_33 , V_36 = V_35 , V_37 = V_32 ;
V_38 ;
V_38 -- , V_36 ++ , V_37 ++ ) {
V_36 -> V_11 = V_37 -> V_11 ;
V_39 += V_36 -> V_11 ;
if ( V_39 > V_44 || V_36 -> V_11 > V_44 ) {
V_5 = - V_26 ;
goto V_45;
}
if ( V_37 -> V_18 ) {
V_41 += V_36 -> V_11 ;
if ( V_41 > V_25 ) {
V_5 = - V_26 ;
goto V_45;
}
V_36 -> V_18 = V_18 ;
V_18 += V_36 -> V_11 ;
}
if ( V_37 -> V_14 ) {
V_40 += V_36 -> V_11 ;
if ( V_40 > V_25 ) {
V_5 = - V_26 ;
goto V_45;
}
V_36 -> V_14 = V_14 ;
if ( F_14 ( V_14 , ( const T_5 T_3 * )
( V_46 ) V_37 -> V_14 ,
V_37 -> V_11 ) )
goto V_45;
V_14 += V_36 -> V_11 ;
}
V_36 -> V_47 = ! ! V_37 -> V_47 ;
V_36 -> V_48 = V_37 -> V_48 ;
V_36 -> V_49 = V_37 -> V_49 ;
V_36 -> V_50 = V_37 -> V_50 ;
V_36 -> V_51 = V_37 -> V_51 ;
V_36 -> V_16 = V_37 -> V_16 ;
if ( ! V_36 -> V_16 )
V_36 -> V_16 = V_2 -> V_16 ;
#ifdef F_17
F_18 ( & V_2 -> V_7 -> V_52 ,
L_1 ,
V_37 -> V_11 ,
V_37 -> V_18 ? L_2 : L_3 ,
V_37 -> V_14 ? L_4 : L_3 ,
V_37 -> V_47 ? L_5 : L_3 ,
V_37 -> V_50 ? : V_2 -> V_7 -> V_50 ,
V_37 -> V_51 ,
V_37 -> V_16 ? : V_2 -> V_7 -> V_53 ) ;
#endif
F_7 ( V_36 , & V_34 ) ;
}
V_5 = F_1 ( V_2 , & V_34 ) ;
if ( V_5 < 0 )
goto V_45;
V_18 = V_2 -> V_19 ;
for ( V_38 = V_33 , V_37 = V_32 ; V_38 ; V_38 -- , V_37 ++ ) {
if ( V_37 -> V_18 ) {
if ( F_11 ( ( T_5 T_3 * )
( V_46 ) V_37 -> V_18 , V_18 ,
V_37 -> V_11 ) ) {
V_5 = - V_30 ;
goto V_45;
}
V_18 += V_37 -> V_11 ;
}
}
V_5 = V_39 ;
V_45:
F_19 ( V_35 ) ;
return V_5 ;
}
static struct V_31 *
F_20 ( unsigned int V_54 , struct V_31 T_3 * V_55 ,
unsigned * V_56 )
{
T_6 V_57 ;
if ( F_21 ( V_54 ) != V_58
|| F_22 ( V_54 ) != F_22 ( F_23 ( 0 ) )
|| F_24 ( V_54 ) != V_59 )
return F_25 ( - V_60 ) ;
V_57 = F_26 ( V_54 ) ;
if ( ( V_57 % sizeof( struct V_31 ) ) != 0 )
return F_25 ( - V_61 ) ;
* V_56 = V_57 / sizeof( struct V_31 ) ;
if ( * V_56 == 0 )
return NULL ;
return F_27 ( V_55 , V_57 ) ;
}
static long
F_28 ( struct V_20 * V_21 , unsigned int V_54 , unsigned long V_62 )
{
int V_63 = 0 ;
struct V_1 * V_2 ;
struct V_6 * V_7 ;
T_6 V_57 ;
unsigned V_56 ;
struct V_31 * V_64 ;
if ( F_21 ( V_54 ) != V_58 )
return - V_60 ;
V_2 = V_21 -> V_27 ;
F_2 ( & V_2 -> V_8 ) ;
V_7 = F_29 ( V_2 -> V_7 ) ;
F_3 ( & V_2 -> V_8 ) ;
if ( V_7 == NULL )
return - V_9 ;
F_10 ( & V_2 -> V_28 ) ;
switch ( V_54 ) {
case V_65 :
V_63 = F_30 ( V_7 -> V_66 & V_67 ,
( V_68 T_3 * ) V_62 ) ;
break;
case V_69 :
V_63 = F_30 ( V_7 -> V_66 & V_67 ,
( V_70 T_3 * ) V_62 ) ;
break;
case V_71 :
V_63 = F_30 ( ( V_7 -> V_66 & V_72 ) ? 1 : 0 ,
( V_68 T_3 * ) V_62 ) ;
break;
case V_73 :
V_63 = F_30 ( V_7 -> V_50 , ( V_68 T_3 * ) V_62 ) ;
break;
case V_74 :
V_63 = F_30 ( V_2 -> V_16 , ( V_70 T_3 * ) V_62 ) ;
break;
case V_75 :
case V_76 :
if ( V_54 == V_75 )
V_63 = F_31 ( V_57 , ( T_5 T_3 * ) V_62 ) ;
else
V_63 = F_31 ( V_57 , ( T_6 T_3 * ) V_62 ) ;
if ( V_63 == 0 ) {
T_6 V_77 = V_7 -> V_66 ;
if ( V_57 & ~ V_67 ) {
V_63 = - V_61 ;
break;
}
V_57 |= V_7 -> V_66 & ~ V_67 ;
V_7 -> V_66 = ( V_78 ) V_57 ;
V_63 = F_32 ( V_7 ) ;
if ( V_63 < 0 )
V_7 -> V_66 = V_77 ;
else
F_18 ( & V_7 -> V_52 , L_6 , V_57 ) ;
}
break;
case V_79 :
V_63 = F_31 ( V_57 , ( V_68 T_3 * ) V_62 ) ;
if ( V_63 == 0 ) {
T_6 V_77 = V_7 -> V_66 ;
if ( V_57 )
V_7 -> V_66 |= V_72 ;
else
V_7 -> V_66 &= ~ V_72 ;
V_63 = F_32 ( V_7 ) ;
if ( V_63 < 0 )
V_7 -> V_66 = V_77 ;
else
F_18 ( & V_7 -> V_52 , L_7 ,
V_57 ? 'l' : 'm' ) ;
}
break;
case V_80 :
V_63 = F_31 ( V_57 , ( V_68 T_3 * ) V_62 ) ;
if ( V_63 == 0 ) {
T_5 V_77 = V_7 -> V_50 ;
V_7 -> V_50 = V_57 ;
V_63 = F_32 ( V_7 ) ;
if ( V_63 < 0 )
V_7 -> V_50 = V_77 ;
else
F_18 ( & V_7 -> V_52 , L_8 , V_57 ) ;
}
break;
case V_81 :
V_63 = F_31 ( V_57 , ( V_70 T_3 * ) V_62 ) ;
if ( V_63 == 0 ) {
T_6 V_77 = V_7 -> V_53 ;
V_7 -> V_53 = V_57 ;
V_63 = F_32 ( V_7 ) ;
if ( V_63 >= 0 )
V_2 -> V_16 = V_57 ;
else
F_18 ( & V_7 -> V_52 , L_9 , V_57 ) ;
V_7 -> V_53 = V_77 ;
}
break;
default:
V_64 = F_20 ( V_54 ,
(struct V_31 T_3 * ) V_62 , & V_56 ) ;
if ( F_33 ( V_64 ) ) {
V_63 = F_34 ( V_64 ) ;
break;
}
if ( ! V_64 )
break;
V_63 = F_15 ( V_2 , V_64 , V_56 ) ;
F_19 ( V_64 ) ;
break;
}
F_12 ( & V_2 -> V_28 ) ;
F_35 ( V_7 ) ;
return V_63 ;
}
static long
F_36 ( struct V_20 * V_21 , unsigned int V_54 ,
unsigned long V_62 )
{
struct V_31 T_3 * V_55 ;
int V_63 = 0 ;
struct V_1 * V_2 ;
struct V_6 * V_7 ;
unsigned V_56 , V_38 ;
struct V_31 * V_64 ;
V_55 = (struct V_31 T_3 * ) F_37 ( V_62 ) ;
V_2 = V_21 -> V_27 ;
F_2 ( & V_2 -> V_8 ) ;
V_7 = F_29 ( V_2 -> V_7 ) ;
F_3 ( & V_2 -> V_8 ) ;
if ( V_7 == NULL )
return - V_9 ;
F_10 ( & V_2 -> V_28 ) ;
V_64 = F_20 ( V_54 , V_55 , & V_56 ) ;
if ( F_33 ( V_64 ) ) {
V_63 = F_34 ( V_64 ) ;
goto V_45;
}
if ( ! V_64 )
goto V_45;
for ( V_38 = 0 ; V_38 < V_56 ; V_38 ++ ) {
V_64 [ V_38 ] . V_18 = ( V_46 ) F_37 ( V_64 [ V_38 ] . V_18 ) ;
V_64 [ V_38 ] . V_14 = ( V_46 ) F_37 ( V_64 [ V_38 ] . V_14 ) ;
}
V_63 = F_15 ( V_2 , V_64 , V_56 ) ;
F_19 ( V_64 ) ;
V_45:
F_12 ( & V_2 -> V_28 ) ;
F_35 ( V_7 ) ;
return V_63 ;
}
static long
F_38 ( struct V_20 * V_21 , unsigned int V_54 , unsigned long V_62 )
{
if ( F_21 ( V_54 ) == V_58
&& F_22 ( V_54 ) == F_22 ( F_23 ( 0 ) )
&& F_24 ( V_54 ) == V_59 )
return F_36 ( V_21 , V_54 , V_62 ) ;
return F_28 ( V_21 , V_54 , ( unsigned long ) F_37 ( V_62 ) ) ;
}
static int F_39 ( struct V_82 * V_82 , struct V_20 * V_21 )
{
struct V_1 * V_2 ;
int V_5 = - V_83 ;
F_10 ( & V_84 ) ;
F_40 (spidev, &device_list, device_entry) {
if ( V_2 -> V_85 == V_82 -> V_86 ) {
V_5 = 0 ;
break;
}
}
if ( V_5 ) {
F_41 ( L_10 , F_42 ( V_82 ) ) ;
goto V_87;
}
if ( ! V_2 -> V_15 ) {
V_2 -> V_15 = F_43 ( V_25 , V_42 ) ;
if ( ! V_2 -> V_15 ) {
F_18 ( & V_2 -> V_7 -> V_52 , L_11 ) ;
V_5 = - V_43 ;
goto V_87;
}
}
if ( ! V_2 -> V_19 ) {
V_2 -> V_19 = F_43 ( V_25 , V_42 ) ;
if ( ! V_2 -> V_19 ) {
F_18 ( & V_2 -> V_7 -> V_52 , L_11 ) ;
V_5 = - V_43 ;
goto V_88;
}
}
V_2 -> V_89 ++ ;
V_21 -> V_27 = V_2 ;
F_44 ( V_82 , V_21 ) ;
F_12 ( & V_84 ) ;
return 0 ;
V_88:
F_19 ( V_2 -> V_15 ) ;
V_2 -> V_15 = NULL ;
V_87:
F_12 ( & V_84 ) ;
return V_5 ;
}
static int F_45 ( struct V_82 * V_82 , struct V_20 * V_21 )
{
struct V_1 * V_2 ;
F_10 ( & V_84 ) ;
V_2 = V_21 -> V_27 ;
V_21 -> V_27 = NULL ;
V_2 -> V_89 -- ;
if ( ! V_2 -> V_89 ) {
int V_90 ;
F_19 ( V_2 -> V_15 ) ;
V_2 -> V_15 = NULL ;
F_19 ( V_2 -> V_19 ) ;
V_2 -> V_19 = NULL ;
F_2 ( & V_2 -> V_8 ) ;
if ( V_2 -> V_7 )
V_2 -> V_16 = V_2 -> V_7 -> V_53 ;
V_90 = ( V_2 -> V_7 == NULL ) ;
F_3 ( & V_2 -> V_8 ) ;
if ( V_90 )
F_19 ( V_2 ) ;
}
F_12 ( & V_84 ) ;
return 0 ;
}
static void F_46 ( struct V_6 * V_7 )
{
const struct V_91 * V_92 ;
if ( ! F_47 ( & V_7 -> V_52 ) )
return;
V_92 = F_48 ( V_93 , & V_7 -> V_52 ) ;
if ( F_49 ( ! V_92 ) )
return;
if ( V_92 -> V_94 == V_95 )
F_50 ( & V_7 -> V_52 , L_12 ) ;
}
static inline void F_46 ( struct V_6 * V_7 ) {}
static int F_51 ( struct V_6 * V_7 )
{
struct V_1 * V_2 ;
int V_5 ;
unsigned long V_96 ;
if ( V_7 -> V_52 . V_97 && ! F_52 ( V_98 , & V_7 -> V_52 ) ) {
F_53 ( & V_7 -> V_52 , L_13 ) ;
F_49 ( V_7 -> V_52 . V_97 &&
! F_52 ( V_98 , & V_7 -> V_52 ) ) ;
}
F_46 ( V_7 ) ;
V_2 = F_54 ( sizeof( * V_2 ) , V_42 ) ;
if ( ! V_2 )
return - V_43 ;
V_2 -> V_7 = V_7 ;
F_55 ( & V_2 -> V_8 ) ;
F_56 ( & V_2 -> V_28 ) ;
F_57 ( & V_2 -> V_99 ) ;
F_10 ( & V_84 ) ;
V_96 = F_58 ( V_100 , V_101 ) ;
if ( V_96 < V_101 ) {
struct V_102 * V_52 ;
V_2 -> V_85 = F_59 ( V_103 , V_96 ) ;
V_52 = F_60 ( V_104 , & V_7 -> V_52 , V_2 -> V_85 ,
V_2 , L_14 ,
V_7 -> V_105 -> V_106 , V_7 -> V_107 ) ;
V_5 = F_61 ( V_52 ) ;
} else {
F_18 ( & V_7 -> V_52 , L_15 ) ;
V_5 = - V_108 ;
}
if ( V_5 == 0 ) {
F_62 ( V_96 , V_100 ) ;
F_63 ( & V_2 -> V_99 , & V_109 ) ;
}
F_12 ( & V_84 ) ;
V_2 -> V_16 = V_7 -> V_53 ;
if ( V_5 == 0 )
F_64 ( V_7 , V_2 ) ;
else
F_19 ( V_2 ) ;
return V_5 ;
}
static int F_65 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_66 ( V_7 ) ;
F_2 ( & V_2 -> V_8 ) ;
V_2 -> V_7 = NULL ;
F_3 ( & V_2 -> V_8 ) ;
F_10 ( & V_84 ) ;
F_67 ( & V_2 -> V_99 ) ;
F_68 ( V_104 , V_2 -> V_85 ) ;
F_69 ( F_70 ( V_2 -> V_85 ) , V_100 ) ;
if ( V_2 -> V_89 == 0 )
F_19 ( V_2 ) ;
F_12 ( & V_84 ) ;
return 0 ;
}
static int T_7 F_71 ( void )
{
int V_5 ;
F_72 ( V_101 > 256 ) ;
V_5 = F_73 ( V_103 , L_16 , & V_110 ) ;
if ( V_5 < 0 )
return V_5 ;
V_104 = F_74 ( V_111 , L_17 ) ;
if ( F_33 ( V_104 ) ) {
F_75 ( V_103 , V_112 . V_113 . V_114 ) ;
return F_34 ( V_104 ) ;
}
V_5 = F_76 ( & V_112 ) ;
if ( V_5 < 0 ) {
F_77 ( V_104 ) ;
F_75 ( V_103 , V_112 . V_113 . V_114 ) ;
}
return V_5 ;
}
static void T_8 F_78 ( void )
{
F_79 ( & V_112 ) ;
F_77 ( V_104 ) ;
F_75 ( V_103 , V_112 . V_113 . V_114 ) ;
}
