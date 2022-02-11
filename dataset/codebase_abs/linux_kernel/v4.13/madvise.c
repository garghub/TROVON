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
if ( error ) {
if ( error == - V_34 )
error = - V_35 ;
goto V_27;
}
break;
case V_36 :
case V_37 :
error = F_4 ( V_7 , & V_15 , V_1 ) ;
if ( error ) {
if ( error == - V_34 )
error = - V_35 ;
goto V_27;
}
break;
}
if ( V_15 == V_7 -> V_16 ) {
* V_8 = V_7 ;
goto V_27;
}
V_14 = V_7 -> V_38 + ( ( V_9 - V_7 -> V_39 ) >> V_40 ) ;
* V_8 = F_5 ( V_12 , * V_8 , V_9 , V_10 , V_15 , V_7 -> V_41 ,
V_7 -> V_42 , V_14 , F_6 ( V_7 ) ,
V_7 -> V_43 ) ;
if ( * V_8 ) {
V_7 = * V_8 ;
goto V_44;
}
* V_8 = V_7 ;
if ( V_9 != V_7 -> V_39 ) {
if ( F_7 ( V_12 -> V_45 >= V_46 ) ) {
error = - V_34 ;
goto V_27;
}
error = F_8 ( V_12 , V_7 , V_9 , 1 ) ;
if ( error ) {
if ( error == - V_34 )
error = - V_35 ;
goto V_27;
}
}
if ( V_10 != V_7 -> V_47 ) {
if ( F_7 ( V_12 -> V_45 >= V_46 ) ) {
error = - V_34 ;
goto V_27;
}
error = F_8 ( V_12 , V_7 , V_10 , 0 ) ;
if ( error ) {
if ( error == - V_34 )
error = - V_35 ;
goto V_27;
}
}
V_44:
V_7 -> V_16 = V_15 ;
V_27:
return error ;
}
static int F_9 ( T_2 * V_48 , unsigned long V_9 ,
unsigned long V_10 , struct V_49 * V_50 )
{
T_3 * V_51 ;
struct V_6 * V_7 = V_50 -> V_52 ;
unsigned long V_53 ;
if ( F_10 ( V_48 ) )
return 0 ;
for ( V_53 = V_9 ; V_53 != V_10 ; V_53 += V_54 ) {
T_3 V_55 ;
T_4 V_56 ;
struct V_57 * V_57 ;
T_5 * V_58 ;
V_51 = F_11 ( V_7 -> V_13 , V_48 , V_9 , & V_58 ) ;
V_55 = * ( V_51 + ( ( V_53 - V_9 ) / V_54 ) ) ;
F_12 ( V_51 , V_58 ) ;
if ( F_13 ( V_55 ) || F_14 ( V_55 ) )
continue;
V_56 = F_15 ( V_55 ) ;
if ( F_7 ( F_16 ( V_56 ) ) )
continue;
V_57 = F_17 ( V_56 , V_59 ,
V_7 , V_53 , false ) ;
if ( V_57 )
F_18 ( V_57 ) ;
}
return 0 ;
}
static void F_19 ( struct V_6 * V_7 ,
unsigned long V_9 , unsigned long V_10 )
{
struct V_49 V_50 = {
. V_12 = V_7 -> V_13 ,
. V_60 = F_9 ,
. V_52 = V_7 ,
} ;
F_20 ( V_9 , V_10 , & V_50 ) ;
F_21 () ;
}
static void F_22 ( struct V_6 * V_7 ,
unsigned long V_9 , unsigned long V_10 ,
struct V_61 * V_62 )
{
T_1 V_53 ;
struct V_57 * V_57 ;
T_4 V_63 ;
for (; V_9 < V_10 ; V_9 += V_54 ) {
V_53 = ( ( V_9 - V_7 -> V_39 ) >> V_40 ) + V_7 -> V_38 ;
V_57 = F_23 ( V_62 , V_53 ) ;
if ( ! F_24 ( V_57 ) ) {
if ( V_57 )
F_18 ( V_57 ) ;
continue;
}
V_63 = F_25 ( V_57 ) ;
V_57 = F_17 ( V_63 , V_59 ,
NULL , 0 , false ) ;
if ( V_57 )
F_18 ( V_57 ) ;
}
F_21 () ;
}
static long F_26 ( struct V_6 * V_7 ,
struct V_6 * * V_8 ,
unsigned long V_9 , unsigned long V_10 )
{
struct V_64 * V_64 = V_7 -> V_42 ;
#ifdef F_27
if ( ! V_64 ) {
* V_8 = V_7 ;
F_19 ( V_7 , V_9 , V_10 ) ;
return 0 ;
}
if ( F_28 ( V_64 -> V_65 ) ) {
* V_8 = V_7 ;
F_22 ( V_7 , V_9 , V_10 ,
V_64 -> V_65 ) ;
return 0 ;
}
#else
if ( ! V_64 )
return - V_66 ;
#endif
if ( F_29 ( F_30 ( V_64 ) ) ) {
return 0 ;
}
* V_8 = V_7 ;
V_9 = ( ( V_9 - V_7 -> V_39 ) >> V_40 ) + V_7 -> V_38 ;
if ( V_10 > V_7 -> V_47 )
V_10 = V_7 -> V_47 ;
V_10 = ( ( V_10 - V_7 -> V_39 ) >> V_40 ) + V_7 -> V_38 ;
F_31 ( V_64 -> V_65 , V_64 , V_9 , V_10 - V_9 ) ;
return 0 ;
}
static int F_32 ( T_2 * V_48 , unsigned long V_67 ,
unsigned long V_10 , struct V_49 * V_50 )
{
struct V_68 * V_69 = V_50 -> V_52 ;
struct V_11 * V_12 = V_69 -> V_12 ;
struct V_6 * V_7 = V_50 -> V_7 ;
T_5 * V_58 ;
T_3 * V_51 , * V_55 , V_70 ;
struct V_57 * V_57 ;
int V_71 = 0 ;
unsigned long V_72 ;
V_72 = F_33 ( V_67 , V_10 ) ;
if ( F_34 ( * V_48 ) )
if ( F_35 ( V_69 , V_7 , V_48 , V_67 , V_72 ) )
goto V_72;
if ( F_36 ( V_48 ) )
return 0 ;
F_37 ( V_69 , V_54 ) ;
V_51 = V_55 = F_11 ( V_12 , V_48 , V_67 , & V_58 ) ;
F_38 ( V_12 ) ;
F_39 () ;
for (; V_67 != V_10 ; V_55 ++ , V_67 += V_54 ) {
V_70 = * V_55 ;
if ( F_14 ( V_70 ) )
continue;
if ( ! F_13 ( V_70 ) ) {
T_4 V_56 ;
V_56 = F_15 ( V_70 ) ;
if ( F_16 ( V_56 ) )
continue;
V_71 -- ;
F_40 ( V_56 ) ;
F_41 ( V_12 , V_67 , V_55 , V_69 -> V_73 ) ;
continue;
}
V_57 = F_42 ( V_7 , V_67 , V_70 ) ;
if ( ! V_57 )
continue;
if ( F_43 ( V_57 ) ) {
if ( F_44 ( V_57 ) != 1 )
goto V_27;
F_45 ( V_57 ) ;
if ( ! F_46 ( V_57 ) ) {
F_18 ( V_57 ) ;
goto V_27;
}
F_12 ( V_51 , V_58 ) ;
if ( F_47 ( V_57 ) ) {
F_48 ( V_57 ) ;
F_18 ( V_57 ) ;
F_11 ( V_12 , V_48 , V_67 , & V_58 ) ;
goto V_27;
}
F_48 ( V_57 ) ;
F_18 ( V_57 ) ;
V_55 = F_11 ( V_12 , V_48 , V_67 , & V_58 ) ;
V_55 -- ;
V_67 -= V_54 ;
continue;
}
F_49 ( F_43 ( V_57 ) , V_57 ) ;
if ( F_50 ( V_57 ) || F_51 ( V_57 ) ) {
if ( ! F_46 ( V_57 ) )
continue;
if ( F_44 ( V_57 ) != 1 ) {
F_48 ( V_57 ) ;
continue;
}
if ( F_50 ( V_57 ) && ! F_52 ( V_57 ) ) {
F_48 ( V_57 ) ;
continue;
}
F_53 ( V_57 ) ;
F_48 ( V_57 ) ;
}
if ( F_54 ( V_70 ) || F_55 ( V_70 ) ) {
V_70 = F_56 ( V_12 , V_67 , V_55 ,
V_69 -> V_73 ) ;
V_70 = F_57 ( V_70 ) ;
V_70 = F_58 ( V_70 ) ;
F_59 ( V_12 , V_67 , V_55 , V_70 ) ;
F_60 ( V_69 , V_55 , V_67 ) ;
}
F_61 ( V_57 ) ;
}
V_27:
if ( V_71 ) {
if ( V_74 -> V_12 == V_12 )
F_62 ( V_12 ) ;
F_63 ( V_12 , V_75 , V_71 ) ;
}
F_64 () ;
F_12 ( V_51 , V_58 ) ;
F_65 () ;
V_72:
return 0 ;
}
static void F_66 ( struct V_68 * V_69 ,
struct V_6 * V_7 ,
unsigned long V_67 , unsigned long V_10 )
{
struct V_49 V_76 = {
. V_60 = F_32 ,
. V_12 = V_7 -> V_13 ,
. V_52 = V_69 ,
} ;
F_67 ( V_69 , V_7 ) ;
F_20 ( V_67 , V_10 , & V_76 ) ;
F_68 ( V_69 , V_7 ) ;
}
static int F_69 ( struct V_6 * V_7 ,
unsigned long V_77 , unsigned long V_78 )
{
unsigned long V_9 , V_10 ;
struct V_11 * V_12 = V_7 -> V_13 ;
struct V_68 V_69 ;
if ( ! F_70 ( V_7 ) )
return - V_26 ;
V_9 = F_71 ( V_7 -> V_39 , V_77 ) ;
if ( V_9 >= V_7 -> V_47 )
return - V_26 ;
V_10 = F_72 ( V_7 -> V_47 , V_78 ) ;
if ( V_10 <= V_7 -> V_39 )
return - V_26 ;
F_21 () ;
F_73 ( & V_69 , V_12 , V_9 , V_10 ) ;
F_74 ( V_12 ) ;
F_75 ( V_12 , V_9 , V_10 ) ;
F_66 ( & V_69 , V_7 , V_9 , V_10 ) ;
F_76 ( V_12 , V_9 , V_10 ) ;
F_77 ( & V_69 , V_9 , V_10 ) ;
return 0 ;
}
static long F_78 ( struct V_6 * V_7 ,
unsigned long V_9 , unsigned long V_10 )
{
F_79 ( V_7 , V_9 , V_10 - V_9 ) ;
return 0 ;
}
static long F_80 ( struct V_6 * V_7 ,
struct V_6 * * V_8 ,
unsigned long V_9 , unsigned long V_10 ,
int V_1 )
{
* V_8 = V_7 ;
if ( ! F_81 ( V_7 ) )
return - V_26 ;
if ( ! F_82 ( V_7 , V_9 , V_10 ) ) {
* V_8 = NULL ;
F_83 ( & V_74 -> V_12 -> V_79 ) ;
V_7 = F_84 ( V_74 -> V_12 , V_9 ) ;
if ( ! V_7 )
return - V_34 ;
if ( V_9 < V_7 -> V_39 ) {
return - V_34 ;
}
if ( ! F_81 ( V_7 ) )
return - V_26 ;
if ( V_10 > V_7 -> V_47 ) {
V_10 = V_7 -> V_47 ;
}
F_85 ( V_9 >= V_10 ) ;
}
if ( V_1 == V_4 )
return F_78 ( V_7 , V_9 , V_10 ) ;
else if ( V_1 == V_5 )
return F_69 ( V_7 , V_9 , V_10 ) ;
else
return - V_26 ;
}
static long F_86 ( struct V_6 * V_7 ,
struct V_6 * * V_8 ,
unsigned long V_9 , unsigned long V_10 )
{
T_6 V_80 ;
int error ;
struct V_64 * V_81 ;
* V_8 = NULL ;
if ( V_7 -> V_16 & V_82 )
return - V_26 ;
V_81 = V_7 -> V_42 ;
if ( ! V_81 || ! V_81 -> V_65 || ! V_81 -> V_65 -> V_83 ) {
return - V_26 ;
}
if ( ( V_7 -> V_16 & ( V_84 | V_85 ) ) != ( V_84 | V_85 ) )
return - V_86 ;
V_80 = ( T_6 ) ( V_9 - V_7 -> V_39 )
+ ( ( T_6 ) V_7 -> V_38 << V_40 ) ;
F_87 ( V_81 ) ;
if ( F_82 ( V_7 , V_9 , V_10 ) ) {
F_88 ( & V_74 -> V_12 -> V_79 ) ;
}
error = F_89 ( V_81 ,
V_87 | V_88 ,
V_80 , V_10 - V_9 ) ;
F_90 ( V_81 ) ;
F_83 ( & V_74 -> V_12 -> V_79 ) ;
return error ;
}
static int F_91 ( int V_1 ,
unsigned long V_9 , unsigned long V_10 )
{
struct V_57 * V_57 ;
struct V_89 * V_89 ;
if ( ! F_92 ( V_90 ) )
return - V_91 ;
for (; V_9 < V_10 ; V_9 += V_54 <<
F_93 ( F_94 ( V_57 ) ) ) {
int V_92 ;
V_92 = F_95 ( V_9 , 1 , 0 , & V_57 ) ;
if ( V_92 != 1 )
return V_92 ;
if ( F_96 ( V_57 ) ) {
F_18 ( V_57 ) ;
continue;
}
if ( V_1 == V_93 ) {
F_97 ( L_1 ,
F_98 ( V_57 ) , V_9 ) ;
V_92 = F_99 ( V_57 , V_94 ) ;
if ( V_92 )
return V_92 ;
continue;
}
F_97 ( L_2 ,
F_98 ( V_57 ) , V_9 ) ;
V_92 = F_100 ( F_98 ( V_57 ) , 0 , V_94 ) ;
if ( V_92 )
return V_92 ;
}
F_101 (zone)
F_102 ( V_89 ) ;
return 0 ;
}
static long
F_103 ( struct V_6 * V_7 , struct V_6 * * V_8 ,
unsigned long V_9 , unsigned long V_10 , int V_1 )
{
switch ( V_1 ) {
case V_2 :
return F_86 ( V_7 , V_8 , V_9 , V_10 ) ;
case V_3 :
return F_26 ( V_7 , V_8 , V_9 , V_10 ) ;
case V_5 :
case V_4 :
return F_80 ( V_7 , V_8 , V_9 , V_10 , V_1 ) ;
default:
return F_2 ( V_7 , V_8 , V_9 , V_10 , V_1 ) ;
}
}
static bool
F_104 ( int V_1 )
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
#ifdef F_105
case V_32 :
case V_33 :
#endif
#ifdef F_106
case V_36 :
case V_37 :
#endif
case V_28 :
case V_30 :
#ifdef F_107
case V_93 :
case V_95 :
#endif
return true ;
default:
return false ;
}
}
