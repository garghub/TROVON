static T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
unsigned long V_4 ;
T_1 V_5 ;
struct V_6 * V_7 = V_2 -> V_7 ;
F_2 ( & V_7 -> V_8 , V_4 ) ;
F_3 ( V_2 , V_7 -> V_9 + V_10 ,
V_7 -> V_9 + V_11 ) ;
F_4 ( V_3 , V_7 -> V_9 + V_12 ) ;
V_5 = F_5 ( V_7 -> V_9 + V_13 ) ;
F_6 ( & V_7 -> V_8 , V_4 ) ;
return V_5 ;
}
static void F_7 ( struct V_1 * V_2 , T_1 V_3 )
{
unsigned long V_4 ;
struct V_6 * V_7 = V_2 -> V_7 ;
F_2 ( & V_7 -> V_8 , V_4 ) ;
F_3 ( V_2 , V_7 -> V_9 + V_10 ,
V_7 -> V_9 + V_11 ) ;
F_4 ( V_3 , V_7 -> V_9 + V_12 ) ;
F_6 ( & V_7 -> V_8 , V_4 ) ;
}
static int F_8 ( int V_5 )
{
switch ( V_5 ) {
case V_14 :
return - V_15 ;
case V_16 :
return - V_17 ;
case V_18 :
return - V_19 ;
default:
return - V_20 ;
}
}
static int F_9 ( struct V_6 * V_7 ,
struct V_21 * V_22 )
{
T_1 V_23 , V_24 ;
T_2 V_25 ;
V_23 = F_5 ( V_7 -> V_9 + V_26 ) ;
V_24 = F_5 ( V_7 -> V_9 + V_27 ) ;
V_25 = ( ( T_2 ) V_23 << 32 ) | V_24 ;
if ( V_25 != ( F_10 ( V_22 ) ) )
return 0 ;
return 1 ;
}
static int F_11 ( struct V_28 * V_29 ,
struct V_6 * V_7 )
{
T_3 V_30 ;
struct V_21 * V_22 ;
V_22 = F_12 ( & V_29 -> V_7 , sizeof( struct V_21 ) ,
& V_30 , V_31 ) ;
if ( ! V_22 )
return - V_17 ;
F_4 ( F_13 ( V_30 ) , V_7 -> V_9 + V_26 ) ;
F_4 ( F_14 ( V_30 ) , V_7 -> V_9 + V_27 ) ;
if ( F_9 ( V_7 , V_22 ) ) {
V_7 -> V_22 = V_22 ;
return 0 ;
} else
return - 1 ;
}
static int F_15 ( struct V_6 * V_7 , const int V_3 ,
unsigned long V_32 , unsigned long V_33 ,
struct V_1 * V_2 , int * V_5 )
{
struct V_21 * V_22 = V_7 -> V_22 ;
if ( V_22 == NULL )
return - 1 ;
V_22 -> V_34 = V_35 ;
V_22 -> V_36 = ( unsigned long ) V_2 ;
V_22 -> V_37 = V_33 ;
V_22 -> V_32 = V_32 ;
V_22 -> V_3 = V_3 ;
F_4 ( V_3 , V_7 -> V_9 + V_38 ) ;
if ( V_22 -> V_34 == V_35 )
return - 1 ;
* V_5 = V_22 -> V_34 ;
return 0 ;
}
static T_4 F_16 ( struct V_39 * V_40 , char T_5 * V_41 ,
T_6 V_42 , int V_43 )
{
unsigned long V_44 ;
struct V_1 * V_2 = V_40 -> V_45 ;
struct V_6 * V_7 = V_2 -> V_7 ;
unsigned long V_32 , V_46 ;
int V_47 = 0 , V_48 = - V_20 ;
if ( F_17 ( V_49 , & V_2 -> V_4 ) )
return - V_19 ;
if ( F_18 ( V_42 == 0 ) )
return 0 ;
if ( ! F_19 ( V_43 ? V_50 : V_51 ,
V_41 , V_42 ) )
return - V_52 ;
if ( F_20 ( & V_2 -> V_8 ) )
return - V_53 ;
V_32 = ( unsigned long ) ( void * ) V_41 ;
V_46 = V_32 + V_42 ;
while ( V_32 < V_46 ) {
unsigned long V_54 = ( V_32 & V_55 ) + V_56 ;
unsigned long V_57 = V_54 < V_46 ? V_54
: V_46 ;
unsigned long V_33 = V_57 - V_32 ;
int V_5 , V_58 ;
struct V_59 * V_59 ;
unsigned long V_60 ;
F_21 ( & V_61 -> V_62 -> V_63 ) ;
V_48 = F_22 ( V_32 , 1 , V_43 ? 0 : V_64 ,
& V_59 , NULL ) ;
F_23 ( & V_61 -> V_62 -> V_63 ) ;
if ( V_48 < 0 )
break;
if ( V_7 -> V_65 ) {
V_60 = F_24 ( V_59 ) | ( V_32 & ~ V_55 ) ;
} else {
V_60 = V_32 ;
}
F_2 ( & V_7 -> V_8 , V_44 ) ;
if ( F_15 ( V_7 ,
V_43 ? V_66 : V_67 ,
V_60 , V_33 , V_2 , & V_5 ) ) {
F_3 ( V_2 , V_7 -> V_9 + V_10 ,
V_7 -> V_9 + V_11 ) ;
F_4 ( V_33 , V_7 -> V_9 + V_68 ) ;
F_3 ( ( void * ) V_60 ,
V_7 -> V_9 + V_69 ,
V_7 -> V_9 + V_70 ) ;
F_4 ( V_43 ? V_66 : V_67 ,
V_7 -> V_9 + V_12 ) ;
V_5 = F_5 ( V_7 -> V_9 + V_13 ) ;
}
F_6 ( & V_7 -> V_8 , V_44 ) ;
if ( V_5 > 0 && ! V_43 )
F_25 ( V_59 ) ;
F_26 ( V_59 ) ;
if ( V_5 > 0 ) {
V_47 += V_5 ;
V_32 += V_5 ;
continue;
} else if ( V_5 == 0 ) {
V_48 = 0 ;
break;
} else if ( V_5 < 0 && V_47 > 0 ) {
if ( V_5 != V_14 )
F_27 ( L_1 ,
V_5 , V_43 ? L_2 : L_3 ) ;
V_48 = 0 ;
break;
}
if ( V_5 != V_14 ||
( V_40 -> V_71 & V_72 ) != 0 ) {
V_48 = F_8 ( V_5 ) ;
break;
}
V_58 = V_43 ? V_73 : V_74 ;
F_28 ( V_58 , & V_2 -> V_4 ) ;
F_7 ( V_2 ,
V_43 ? V_75 : V_76 ) ;
F_29 ( & V_2 -> V_8 ) ;
while ( F_17 ( V_58 , & V_2 -> V_4 ) ) {
if ( F_30 (
V_2 -> V_77 ,
! F_17 ( V_58 , & V_2 -> V_4 ) ) )
return - V_53 ;
if ( F_17 ( V_49 , & V_2 -> V_4 ) )
return - V_19 ;
}
if ( F_20 ( & V_2 -> V_8 ) )
return - V_53 ;
}
F_29 ( & V_2 -> V_8 ) ;
if ( V_48 < 0 )
return V_48 ;
else
return V_47 ;
}
static T_4 F_31 ( struct V_39 * V_40 , char T_5 * V_41 ,
T_6 V_42 , T_7 * V_78 )
{
return F_16 ( V_40 , V_41 , V_42 , 0 ) ;
}
static T_4 F_32 ( struct V_39 * V_40 ,
const char T_5 * V_41 , T_6 V_42 ,
T_7 * V_78 )
{
return F_16 ( V_40 , ( char T_5 * ) V_41 ,
V_42 , 1 ) ;
}
static unsigned int F_33 ( struct V_39 * V_40 , T_8 * V_79 )
{
struct V_1 * V_2 = V_40 -> V_45 ;
unsigned int V_80 = 0 ;
int V_5 ;
F_34 ( & V_2 -> V_8 ) ;
F_35 ( V_40 , & V_2 -> V_77 , V_79 ) ;
V_5 = F_1 ( V_2 , V_81 ) ;
F_29 ( & V_2 -> V_8 ) ;
if ( V_5 & V_82 )
V_80 |= V_83 | V_84 ;
if ( V_5 & V_85 )
V_80 |= V_86 | V_87 ;
if ( V_5 & V_88 )
V_80 |= V_89 ;
if ( F_17 ( V_49 , & V_2 -> V_4 ) )
V_80 |= V_90 ;
return V_80 ;
}
static T_9 F_36 ( int V_91 , void * V_92 )
{
struct V_6 * V_7 = V_92 ;
unsigned long V_44 ;
int V_47 = 0 ;
F_2 ( & V_7 -> V_8 , V_44 ) ;
for (; ; ) {
struct V_1 * V_2 ;
unsigned long V_93 ;
unsigned long V_36 = 0 ;
#ifdef F_37
V_36 = ( T_2 ) F_5 ( V_7 -> V_9 + V_11 ) << 32 ;
if ( V_36 == 0 )
break;
#endif
V_36 |= F_5 ( V_7 -> V_9 + V_10 ) ;
if ( V_36 == 0 )
break;
V_93 = F_5 ( V_7 -> V_9 + V_94 ) ;
V_2 = (struct V_1 * ) ( V_95 ) V_36 ;
if ( V_93 & V_96 ) {
F_28 ( V_49 , & V_2 -> V_4 ) ;
V_93 |= V_97 | V_98 ;
}
if ( V_93 & V_97 )
F_38 ( V_74 , & V_2 -> V_4 ) ;
if ( V_93 & V_98 )
F_38 ( V_73 , & V_2 -> V_4 ) ;
F_39 ( & V_2 -> V_77 ) ;
V_47 ++ ;
}
F_6 ( & V_7 -> V_8 , V_44 ) ;
return ( V_47 == 0 ) ? V_99 : V_100 ;
}
static int F_40 ( struct V_101 * V_101 , struct V_39 * V_39 )
{
struct V_1 * V_2 ;
struct V_6 * V_7 = V_102 ;
T_10 V_5 ;
V_2 = F_41 ( sizeof( * V_2 ) , V_31 ) ;
if ( V_2 == NULL )
return - V_17 ;
V_2 -> V_7 = V_7 ;
F_42 ( & V_2 -> V_8 ) ;
F_43 ( & V_2 -> V_77 ) ;
V_5 = F_1 ( V_2 , V_103 ) ;
if ( V_5 < 0 ) {
F_44 ( V_2 ) ;
return V_5 ;
}
V_39 -> V_45 = V_2 ;
return 0 ;
}
static int F_45 ( struct V_101 * V_101 , struct V_39 * V_40 )
{
struct V_1 * V_2 = V_40 -> V_45 ;
F_7 ( V_2 , V_104 ) ;
F_44 ( V_2 ) ;
V_40 -> V_45 = NULL ;
return 0 ;
}
static int F_46 ( struct V_28 * V_29 )
{
int V_105 ;
struct V_106 * V_107 ;
struct V_6 * V_7 = V_102 ;
F_47 ( V_7 -> V_9 != NULL ) ;
F_48 ( & V_7 -> V_8 ) ;
V_107 = F_49 ( V_29 , V_108 , 0 ) ;
if ( V_107 == NULL || F_50 ( V_107 ) < V_56 ) {
F_51 ( & V_29 -> V_7 , L_4 ) ;
return - V_20 ;
}
V_7 -> V_9 = F_52 ( & V_29 -> V_7 , V_107 -> V_109 , V_56 ) ;
if ( V_7 -> V_9 == NULL ) {
F_51 ( & V_29 -> V_7 , L_5 ) ;
return - V_20 ;
}
V_107 = F_49 ( V_29 , V_110 , 0 ) ;
if ( V_107 == NULL ) {
V_105 = - V_20 ;
goto error;
}
V_7 -> V_91 = V_107 -> V_109 ;
V_105 = F_53 ( & V_29 -> V_7 , V_7 -> V_91 , F_36 ,
V_111 , L_6 , V_7 ) ;
if ( V_105 ) {
F_51 ( & V_29 -> V_7 , L_7 ) ;
goto error;
}
V_105 = F_54 ( & V_112 ) ;
if ( V_105 ) {
F_51 ( & V_29 -> V_7 , L_8 ) ;
goto error;
}
F_11 ( V_29 , V_7 ) ;
V_7 -> V_65 = F_5 ( V_7 -> V_9 + V_113 ) ;
return 0 ;
error:
V_7 -> V_9 = NULL ;
return V_105 ;
}
static int F_55 ( struct V_28 * V_29 )
{
struct V_6 * V_7 = V_102 ;
F_56 ( & V_112 ) ;
V_7 -> V_9 = NULL ;
return 0 ;
}
