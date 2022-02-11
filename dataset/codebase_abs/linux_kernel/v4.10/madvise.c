static int F_1 ( int V_1 )
{
switch ( V_1 ) {
case V_2 :
case V_3 :
case V_4 :
case V_5 :
return 0 ;
default:
return 1 ;
}
}
static long F_2 ( struct V_6 * V_7 ,
struct V_6 * * V_8 ,
unsigned long V_9 , unsigned long V_10 , int V_1 )
{
struct V_11 * V_12 = V_7 -> V_13 ;
int error = 0 ;
T_1 V_14 ;
unsigned long V_15 = V_7 -> V_16 ;
switch ( V_1 ) {
case V_17 :
V_15 = V_15 & ~ V_18 & ~ V_19 ;
break;
case V_20 :
V_15 = ( V_15 & ~ V_18 ) | V_19 ;
break;
case V_21 :
V_15 = ( V_15 & ~ V_19 ) | V_18 ;
break;
case V_22 :
V_15 |= V_23 ;
break;
case V_24 :
if ( V_7 -> V_16 & V_25 ) {
error = - V_26 ;
goto V_27;
}
V_15 &= ~ V_23 ;
break;
case V_28 :
V_15 |= V_29 ;
break;
case V_30 :
if ( V_15 & V_31 ) {
error = - V_26 ;
goto V_27;
}
V_15 &= ~ V_29 ;
break;
case V_32 :
case V_33 :
error = F_3 ( V_7 , V_9 , V_10 , V_1 , & V_15 ) ;
if ( error )
goto V_27;
break;
case V_34 :
case V_35 :
error = F_4 ( V_7 , & V_15 , V_1 ) ;
if ( error )
goto V_27;
break;
}
if ( V_15 == V_7 -> V_16 ) {
* V_8 = V_7 ;
goto V_27;
}
V_14 = V_7 -> V_36 + ( ( V_9 - V_7 -> V_37 ) >> V_38 ) ;
* V_8 = F_5 ( V_12 , * V_8 , V_9 , V_10 , V_15 , V_7 -> V_39 ,
V_7 -> V_40 , V_14 , F_6 ( V_7 ) ,
V_7 -> V_41 ) ;
if ( * V_8 ) {
V_7 = * V_8 ;
goto V_42;
}
* V_8 = V_7 ;
if ( V_9 != V_7 -> V_37 ) {
error = F_7 ( V_12 , V_7 , V_9 , 1 ) ;
if ( error )
goto V_27;
}
if ( V_10 != V_7 -> V_43 ) {
error = F_7 ( V_12 , V_7 , V_10 , 0 ) ;
if ( error )
goto V_27;
}
V_42:
V_7 -> V_16 = V_15 ;
V_27:
if ( error == - V_44 )
error = - V_45 ;
return error ;
}
static int F_8 ( T_2 * V_46 , unsigned long V_9 ,
unsigned long V_10 , struct V_47 * V_48 )
{
T_3 * V_49 ;
struct V_6 * V_7 = V_48 -> V_50 ;
unsigned long V_51 ;
if ( F_9 ( V_46 ) )
return 0 ;
for ( V_51 = V_9 ; V_51 != V_10 ; V_51 += V_52 ) {
T_3 V_53 ;
T_4 V_54 ;
struct V_55 * V_55 ;
T_5 * V_56 ;
V_49 = F_10 ( V_7 -> V_13 , V_46 , V_9 , & V_56 ) ;
V_53 = * ( V_49 + ( ( V_51 - V_9 ) / V_52 ) ) ;
F_11 ( V_49 , V_56 ) ;
if ( F_12 ( V_53 ) || F_13 ( V_53 ) )
continue;
V_54 = F_14 ( V_53 ) ;
if ( F_15 ( F_16 ( V_54 ) ) )
continue;
V_55 = F_17 ( V_54 , V_57 ,
V_7 , V_51 ) ;
if ( V_55 )
F_18 ( V_55 ) ;
}
return 0 ;
}
static void F_19 ( struct V_6 * V_7 ,
unsigned long V_9 , unsigned long V_10 )
{
struct V_47 V_48 = {
. V_12 = V_7 -> V_13 ,
. V_58 = F_8 ,
. V_50 = V_7 ,
} ;
F_20 ( V_9 , V_10 , & V_48 ) ;
F_21 () ;
}
static void F_22 ( struct V_6 * V_7 ,
unsigned long V_9 , unsigned long V_10 ,
struct V_59 * V_60 )
{
T_1 V_51 ;
struct V_55 * V_55 ;
T_4 V_61 ;
for (; V_9 < V_10 ; V_9 += V_52 ) {
V_51 = ( ( V_9 - V_7 -> V_37 ) >> V_38 ) + V_7 -> V_36 ;
V_55 = F_23 ( V_60 , V_51 ) ;
if ( ! F_24 ( V_55 ) ) {
if ( V_55 )
F_18 ( V_55 ) ;
continue;
}
V_61 = F_25 ( V_55 ) ;
V_55 = F_17 ( V_61 , V_57 ,
NULL , 0 ) ;
if ( V_55 )
F_18 ( V_55 ) ;
}
F_21 () ;
}
static long F_26 ( struct V_6 * V_7 ,
struct V_6 * * V_8 ,
unsigned long V_9 , unsigned long V_10 )
{
struct V_62 * V_62 = V_7 -> V_40 ;
#ifdef F_27
if ( ! V_62 ) {
* V_8 = V_7 ;
F_19 ( V_7 , V_9 , V_10 ) ;
return 0 ;
}
if ( F_28 ( V_62 -> V_63 ) ) {
* V_8 = V_7 ;
F_22 ( V_7 , V_9 , V_10 ,
V_62 -> V_63 ) ;
return 0 ;
}
#else
if ( ! V_62 )
return - V_64 ;
#endif
if ( F_29 ( F_30 ( V_62 ) ) ) {
return 0 ;
}
* V_8 = V_7 ;
V_9 = ( ( V_9 - V_7 -> V_37 ) >> V_38 ) + V_7 -> V_36 ;
if ( V_10 > V_7 -> V_43 )
V_10 = V_7 -> V_43 ;
V_10 = ( ( V_10 - V_7 -> V_37 ) >> V_38 ) + V_7 -> V_36 ;
F_31 ( V_62 -> V_63 , V_62 , V_9 , V_10 - V_9 ) ;
return 0 ;
}
static int F_32 ( T_2 * V_46 , unsigned long V_65 ,
unsigned long V_10 , struct V_47 * V_48 )
{
struct V_66 * V_67 = V_48 -> V_50 ;
struct V_11 * V_12 = V_67 -> V_12 ;
struct V_6 * V_7 = V_48 -> V_7 ;
T_5 * V_56 ;
T_3 * V_49 , * V_53 , V_68 ;
struct V_55 * V_55 ;
int V_69 = 0 ;
unsigned long V_70 ;
V_70 = F_33 ( V_65 , V_10 ) ;
if ( F_34 ( * V_46 ) )
if ( F_35 ( V_67 , V_7 , V_46 , V_65 , V_70 ) )
goto V_70;
if ( F_36 ( V_46 ) )
return 0 ;
F_37 ( V_67 , V_52 ) ;
V_49 = V_53 = F_10 ( V_12 , V_46 , V_65 , & V_56 ) ;
F_38 () ;
for (; V_65 != V_10 ; V_53 ++ , V_65 += V_52 ) {
V_68 = * V_53 ;
if ( F_13 ( V_68 ) )
continue;
if ( ! F_12 ( V_68 ) ) {
T_4 V_54 ;
V_54 = F_14 ( V_68 ) ;
if ( F_16 ( V_54 ) )
continue;
V_69 -- ;
F_39 ( V_54 ) ;
F_40 ( V_12 , V_65 , V_53 , V_67 -> V_71 ) ;
continue;
}
V_55 = F_41 ( V_7 , V_65 , V_68 ) ;
if ( ! V_55 )
continue;
if ( F_42 ( V_55 ) ) {
if ( F_43 ( V_55 ) != 1 )
goto V_27;
F_44 ( V_55 ) ;
if ( ! F_45 ( V_55 ) ) {
F_18 ( V_55 ) ;
goto V_27;
}
F_11 ( V_49 , V_56 ) ;
if ( F_46 ( V_55 ) ) {
F_47 ( V_55 ) ;
F_18 ( V_55 ) ;
F_10 ( V_12 , V_46 , V_65 , & V_56 ) ;
goto V_27;
}
F_18 ( V_55 ) ;
F_47 ( V_55 ) ;
V_53 = F_10 ( V_12 , V_46 , V_65 , & V_56 ) ;
V_53 -- ;
V_65 -= V_52 ;
continue;
}
F_48 ( F_42 ( V_55 ) , V_55 ) ;
if ( F_49 ( V_55 ) || F_50 ( V_55 ) ) {
if ( ! F_45 ( V_55 ) )
continue;
if ( F_43 ( V_55 ) != 1 ) {
F_47 ( V_55 ) ;
continue;
}
if ( F_49 ( V_55 ) && ! F_51 ( V_55 ) ) {
F_47 ( V_55 ) ;
continue;
}
F_52 ( V_55 ) ;
F_47 ( V_55 ) ;
}
if ( F_53 ( V_68 ) || F_54 ( V_68 ) ) {
V_68 = F_55 ( V_12 , V_65 , V_53 ,
V_67 -> V_71 ) ;
V_68 = F_56 ( V_68 ) ;
V_68 = F_57 ( V_68 ) ;
F_58 ( V_12 , V_65 , V_53 , V_68 ) ;
if ( F_59 ( V_55 ) )
F_60 ( V_55 ) ;
F_61 ( V_67 , V_53 , V_65 ) ;
}
}
V_27:
if ( V_69 ) {
if ( V_72 -> V_12 == V_12 )
F_62 ( V_12 ) ;
F_63 ( V_12 , V_73 , V_69 ) ;
}
F_64 () ;
F_11 ( V_49 , V_56 ) ;
F_65 () ;
V_70:
return 0 ;
}
static void F_66 ( struct V_66 * V_67 ,
struct V_6 * V_7 ,
unsigned long V_65 , unsigned long V_10 )
{
struct V_47 V_74 = {
. V_58 = F_32 ,
. V_12 = V_7 -> V_13 ,
. V_50 = V_67 ,
} ;
F_67 ( V_67 , V_7 ) ;
F_20 ( V_65 , V_10 , & V_74 ) ;
F_68 ( V_67 , V_7 ) ;
}
static int F_69 ( struct V_6 * V_7 ,
unsigned long V_75 , unsigned long V_76 )
{
unsigned long V_9 , V_10 ;
struct V_11 * V_12 = V_7 -> V_13 ;
struct V_66 V_67 ;
if ( V_7 -> V_16 & ( V_77 | V_78 | V_79 ) )
return - V_26 ;
if ( ! F_70 ( V_7 ) )
return - V_26 ;
V_9 = F_71 ( V_7 -> V_37 , V_75 ) ;
if ( V_9 >= V_7 -> V_43 )
return - V_26 ;
V_10 = F_72 ( V_7 -> V_43 , V_76 ) ;
if ( V_10 <= V_7 -> V_37 )
return - V_26 ;
F_21 () ;
F_73 ( & V_67 , V_12 , V_9 , V_10 ) ;
F_74 ( V_12 ) ;
F_75 ( V_12 , V_9 , V_10 ) ;
F_66 ( & V_67 , V_7 , V_9 , V_10 ) ;
F_76 ( V_12 , V_9 , V_10 ) ;
F_77 ( & V_67 , V_9 , V_10 ) ;
return 0 ;
}
static long F_78 ( struct V_6 * V_7 ,
struct V_6 * * V_8 ,
unsigned long V_9 , unsigned long V_10 )
{
* V_8 = V_7 ;
return F_69 ( V_7 , V_9 , V_10 ) ;
}
static long F_79 ( struct V_6 * V_7 ,
struct V_6 * * V_8 ,
unsigned long V_9 , unsigned long V_10 )
{
* V_8 = V_7 ;
if ( V_7 -> V_16 & ( V_77 | V_78 | V_79 ) )
return - V_26 ;
F_80 ( V_7 , V_9 , V_10 - V_9 , NULL ) ;
return 0 ;
}
static long F_81 ( struct V_6 * V_7 ,
struct V_6 * * V_8 ,
unsigned long V_9 , unsigned long V_10 )
{
T_6 V_80 ;
int error ;
struct V_62 * V_81 ;
* V_8 = NULL ;
if ( V_7 -> V_16 & V_77 )
return - V_26 ;
V_81 = V_7 -> V_40 ;
if ( ! V_81 || ! V_81 -> V_63 || ! V_81 -> V_63 -> V_82 ) {
return - V_26 ;
}
if ( ( V_7 -> V_16 & ( V_83 | V_84 ) ) != ( V_83 | V_84 ) )
return - V_85 ;
V_80 = ( T_6 ) ( V_9 - V_7 -> V_37 )
+ ( ( T_6 ) V_7 -> V_36 << V_38 ) ;
F_82 ( V_81 ) ;
F_83 ( & V_72 -> V_12 -> V_86 ) ;
error = F_84 ( V_81 ,
V_87 | V_88 ,
V_80 , V_10 - V_9 ) ;
F_85 ( V_81 ) ;
F_86 ( & V_72 -> V_12 -> V_86 ) ;
return error ;
}
static int F_87 ( int V_89 , unsigned long V_9 , unsigned long V_10 )
{
struct V_55 * V_90 ;
if ( ! F_88 ( V_91 ) )
return - V_92 ;
for (; V_9 < V_10 ; V_9 += V_52 <<
F_89 ( F_90 ( V_90 ) ) ) {
int V_93 ;
V_93 = F_91 ( V_9 , 1 , 0 , & V_90 ) ;
if ( V_93 != 1 )
return V_93 ;
if ( F_92 ( V_90 ) ) {
F_18 ( V_90 ) ;
continue;
}
if ( V_89 == V_94 ) {
F_93 ( L_1 ,
F_94 ( V_90 ) , V_9 ) ;
V_93 = F_95 ( V_90 , V_95 ) ;
if ( V_93 )
return V_93 ;
continue;
}
F_93 ( L_2 ,
F_94 ( V_90 ) , V_9 ) ;
V_93 = F_96 ( F_94 ( V_90 ) , 0 , V_95 ) ;
if ( V_93 )
return V_93 ;
}
return 0 ;
}
static long
F_97 ( struct V_6 * V_7 , struct V_6 * * V_8 ,
unsigned long V_9 , unsigned long V_10 , int V_1 )
{
switch ( V_1 ) {
case V_2 :
return F_81 ( V_7 , V_8 , V_9 , V_10 ) ;
case V_3 :
return F_26 ( V_7 , V_8 , V_9 , V_10 ) ;
case V_5 :
if ( F_98 () > 0 )
return F_78 ( V_7 , V_8 , V_9 , V_10 ) ;
case V_4 :
return F_79 ( V_7 , V_8 , V_9 , V_10 ) ;
default:
return F_2 ( V_7 , V_8 , V_9 , V_10 , V_1 ) ;
}
}
static bool
F_99 ( int V_1 )
{
switch ( V_1 ) {
case V_24 :
case V_22 :
case V_17 :
case V_20 :
case V_21 :
case V_2 :
case V_3 :
case V_4 :
case V_5 :
#ifdef F_100
case V_32 :
case V_33 :
#endif
#ifdef F_101
case V_34 :
case V_35 :
#endif
case V_28 :
case V_30 :
return true ;
default:
return false ;
}
}
