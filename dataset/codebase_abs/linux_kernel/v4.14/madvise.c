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
if ( V_7 -> V_29 || V_7 -> V_16 & V_30 ) {
error = - V_26 ;
goto V_27;
}
V_15 |= V_31 ;
break;
case V_32 :
V_15 &= ~ V_31 ;
break;
case V_33 :
V_15 |= V_34 ;
break;
case V_35 :
if ( V_15 & V_36 ) {
error = - V_26 ;
goto V_27;
}
V_15 &= ~ V_34 ;
break;
case V_37 :
case V_38 :
error = F_3 ( V_7 , V_9 , V_10 , V_1 , & V_15 ) ;
if ( error ) {
if ( error == - V_39 )
error = - V_40 ;
goto V_27;
}
break;
case V_41 :
case V_42 :
error = F_4 ( V_7 , & V_15 , V_1 ) ;
if ( error ) {
if ( error == - V_39 )
error = - V_40 ;
goto V_27;
}
break;
}
if ( V_15 == V_7 -> V_16 ) {
* V_8 = V_7 ;
goto V_27;
}
V_14 = V_7 -> V_43 + ( ( V_9 - V_7 -> V_44 ) >> V_45 ) ;
* V_8 = F_5 ( V_12 , * V_8 , V_9 , V_10 , V_15 , V_7 -> V_46 ,
V_7 -> V_29 , V_14 , F_6 ( V_7 ) ,
V_7 -> V_47 ) ;
if ( * V_8 ) {
V_7 = * V_8 ;
goto V_48;
}
* V_8 = V_7 ;
if ( V_9 != V_7 -> V_44 ) {
if ( F_7 ( V_12 -> V_49 >= V_50 ) ) {
error = - V_39 ;
goto V_27;
}
error = F_8 ( V_12 , V_7 , V_9 , 1 ) ;
if ( error ) {
if ( error == - V_39 )
error = - V_40 ;
goto V_27;
}
}
if ( V_10 != V_7 -> V_51 ) {
if ( F_7 ( V_12 -> V_49 >= V_50 ) ) {
error = - V_39 ;
goto V_27;
}
error = F_8 ( V_12 , V_7 , V_10 , 0 ) ;
if ( error ) {
if ( error == - V_39 )
error = - V_40 ;
goto V_27;
}
}
V_48:
V_7 -> V_16 = V_15 ;
V_27:
return error ;
}
static int F_9 ( T_2 * V_52 , unsigned long V_9 ,
unsigned long V_10 , struct V_53 * V_54 )
{
T_3 * V_55 ;
struct V_6 * V_7 = V_54 -> V_56 ;
unsigned long V_57 ;
if ( F_10 ( V_52 ) )
return 0 ;
for ( V_57 = V_9 ; V_57 != V_10 ; V_57 += V_58 ) {
T_3 V_59 ;
T_4 V_60 ;
struct V_61 * V_61 ;
T_5 * V_62 ;
V_55 = F_11 ( V_7 -> V_13 , V_52 , V_9 , & V_62 ) ;
V_59 = * ( V_55 + ( ( V_57 - V_9 ) / V_58 ) ) ;
F_12 ( V_55 , V_62 ) ;
if ( F_13 ( V_59 ) || F_14 ( V_59 ) )
continue;
V_60 = F_15 ( V_59 ) ;
if ( F_7 ( F_16 ( V_60 ) ) )
continue;
V_61 = F_17 ( V_60 , V_63 ,
V_7 , V_57 , false ) ;
if ( V_61 )
F_18 ( V_61 ) ;
}
return 0 ;
}
static void F_19 ( struct V_6 * V_7 ,
unsigned long V_9 , unsigned long V_10 )
{
struct V_53 V_54 = {
. V_12 = V_7 -> V_13 ,
. V_64 = F_9 ,
. V_56 = V_7 ,
} ;
F_20 ( V_9 , V_10 , & V_54 ) ;
F_21 () ;
}
static void F_22 ( struct V_6 * V_7 ,
unsigned long V_9 , unsigned long V_10 ,
struct V_65 * V_66 )
{
T_1 V_57 ;
struct V_61 * V_61 ;
T_4 V_67 ;
for (; V_9 < V_10 ; V_9 += V_58 ) {
V_57 = ( ( V_9 - V_7 -> V_44 ) >> V_45 ) + V_7 -> V_43 ;
V_61 = F_23 ( V_66 , V_57 ) ;
if ( ! F_24 ( V_61 ) ) {
if ( V_61 )
F_18 ( V_61 ) ;
continue;
}
V_67 = F_25 ( V_61 ) ;
V_61 = F_17 ( V_67 , V_63 ,
NULL , 0 , false ) ;
if ( V_61 )
F_18 ( V_61 ) ;
}
F_21 () ;
}
static long F_26 ( struct V_6 * V_7 ,
struct V_6 * * V_8 ,
unsigned long V_9 , unsigned long V_10 )
{
struct V_68 * V_68 = V_7 -> V_29 ;
#ifdef F_27
if ( ! V_68 ) {
* V_8 = V_7 ;
F_19 ( V_7 , V_9 , V_10 ) ;
return 0 ;
}
if ( F_28 ( V_68 -> V_69 ) ) {
* V_8 = V_7 ;
F_22 ( V_7 , V_9 , V_10 ,
V_68 -> V_69 ) ;
return 0 ;
}
#else
if ( ! V_68 )
return - V_70 ;
#endif
if ( F_29 ( F_30 ( V_68 ) ) ) {
return 0 ;
}
* V_8 = V_7 ;
V_9 = ( ( V_9 - V_7 -> V_44 ) >> V_45 ) + V_7 -> V_43 ;
if ( V_10 > V_7 -> V_51 )
V_10 = V_7 -> V_51 ;
V_10 = ( ( V_10 - V_7 -> V_44 ) >> V_45 ) + V_7 -> V_43 ;
F_31 ( V_68 -> V_69 , V_68 , V_9 , V_10 - V_9 ) ;
return 0 ;
}
static int F_32 ( T_2 * V_52 , unsigned long V_71 ,
unsigned long V_10 , struct V_53 * V_54 )
{
struct V_72 * V_73 = V_54 -> V_56 ;
struct V_11 * V_12 = V_73 -> V_12 ;
struct V_6 * V_7 = V_54 -> V_7 ;
T_5 * V_62 ;
T_3 * V_55 , * V_59 , V_74 ;
struct V_61 * V_61 ;
int V_75 = 0 ;
unsigned long V_76 ;
V_76 = F_33 ( V_71 , V_10 ) ;
if ( F_34 ( * V_52 ) )
if ( F_35 ( V_73 , V_7 , V_52 , V_71 , V_76 ) )
goto V_76;
if ( F_36 ( V_52 ) )
return 0 ;
F_37 ( V_73 , V_58 ) ;
V_55 = V_59 = F_11 ( V_12 , V_52 , V_71 , & V_62 ) ;
F_38 ( V_12 ) ;
F_39 () ;
for (; V_71 != V_10 ; V_59 ++ , V_71 += V_58 ) {
V_74 = * V_59 ;
if ( F_14 ( V_74 ) )
continue;
if ( ! F_13 ( V_74 ) ) {
T_4 V_60 ;
V_60 = F_15 ( V_74 ) ;
if ( F_16 ( V_60 ) )
continue;
V_75 -- ;
F_40 ( V_60 ) ;
F_41 ( V_12 , V_71 , V_59 , V_73 -> V_77 ) ;
continue;
}
V_61 = F_42 ( V_7 , V_71 , V_74 , true ) ;
if ( ! V_61 )
continue;
if ( F_43 ( V_61 ) ) {
if ( F_44 ( V_61 ) != 1 )
goto V_27;
F_45 ( V_61 ) ;
if ( ! F_46 ( V_61 ) ) {
F_18 ( V_61 ) ;
goto V_27;
}
F_12 ( V_55 , V_62 ) ;
if ( F_47 ( V_61 ) ) {
F_48 ( V_61 ) ;
F_18 ( V_61 ) ;
F_11 ( V_12 , V_52 , V_71 , & V_62 ) ;
goto V_27;
}
F_48 ( V_61 ) ;
F_18 ( V_61 ) ;
V_59 = F_11 ( V_12 , V_52 , V_71 , & V_62 ) ;
V_59 -- ;
V_71 -= V_58 ;
continue;
}
F_49 ( F_43 ( V_61 ) , V_61 ) ;
if ( F_50 ( V_61 ) || F_51 ( V_61 ) ) {
if ( ! F_46 ( V_61 ) )
continue;
if ( F_44 ( V_61 ) != 1 ) {
F_48 ( V_61 ) ;
continue;
}
if ( F_50 ( V_61 ) && ! F_52 ( V_61 ) ) {
F_48 ( V_61 ) ;
continue;
}
F_53 ( V_61 ) ;
F_48 ( V_61 ) ;
}
if ( F_54 ( V_74 ) || F_55 ( V_74 ) ) {
V_74 = F_56 ( V_12 , V_71 , V_59 ,
V_73 -> V_77 ) ;
V_74 = F_57 ( V_74 ) ;
V_74 = F_58 ( V_74 ) ;
F_59 ( V_12 , V_71 , V_59 , V_74 ) ;
F_60 ( V_73 , V_59 , V_71 ) ;
}
F_61 ( V_61 ) ;
}
V_27:
if ( V_75 ) {
if ( V_78 -> V_12 == V_12 )
F_62 ( V_12 ) ;
F_63 ( V_12 , V_79 , V_75 ) ;
}
F_64 () ;
F_12 ( V_55 , V_62 ) ;
F_65 () ;
V_76:
return 0 ;
}
static void F_66 ( struct V_72 * V_73 ,
struct V_6 * V_7 ,
unsigned long V_71 , unsigned long V_10 )
{
struct V_53 V_80 = {
. V_64 = F_32 ,
. V_12 = V_7 -> V_13 ,
. V_56 = V_73 ,
} ;
F_67 ( V_73 , V_7 ) ;
F_20 ( V_71 , V_10 , & V_80 ) ;
F_68 ( V_73 , V_7 ) ;
}
static int F_69 ( struct V_6 * V_7 ,
unsigned long V_81 , unsigned long V_82 )
{
unsigned long V_9 , V_10 ;
struct V_11 * V_12 = V_7 -> V_13 ;
struct V_72 V_73 ;
if ( ! F_70 ( V_7 ) )
return - V_26 ;
V_9 = F_71 ( V_7 -> V_44 , V_81 ) ;
if ( V_9 >= V_7 -> V_51 )
return - V_26 ;
V_10 = F_72 ( V_7 -> V_51 , V_82 ) ;
if ( V_10 <= V_7 -> V_44 )
return - V_26 ;
F_21 () ;
F_73 ( & V_73 , V_12 , V_9 , V_10 ) ;
F_74 ( V_12 ) ;
F_75 ( V_12 , V_9 , V_10 ) ;
F_66 ( & V_73 , V_7 , V_9 , V_10 ) ;
F_76 ( V_12 , V_9 , V_10 ) ;
F_77 ( & V_73 , V_9 , V_10 ) ;
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
F_83 ( & V_78 -> V_12 -> V_83 ) ;
V_7 = F_84 ( V_78 -> V_12 , V_9 ) ;
if ( ! V_7 )
return - V_39 ;
if ( V_9 < V_7 -> V_44 ) {
return - V_39 ;
}
if ( ! F_81 ( V_7 ) )
return - V_26 ;
if ( V_10 > V_7 -> V_51 ) {
V_10 = V_7 -> V_51 ;
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
T_6 V_84 ;
int error ;
struct V_68 * V_85 ;
* V_8 = NULL ;
if ( V_7 -> V_16 & V_86 )
return - V_26 ;
V_85 = V_7 -> V_29 ;
if ( ! V_85 || ! V_85 -> V_69 || ! V_85 -> V_69 -> V_87 ) {
return - V_26 ;
}
if ( ( V_7 -> V_16 & ( V_30 | V_88 ) ) != ( V_30 | V_88 ) )
return - V_89 ;
V_84 = ( T_6 ) ( V_9 - V_7 -> V_44 )
+ ( ( T_6 ) V_7 -> V_43 << V_45 ) ;
F_87 ( V_85 ) ;
if ( F_82 ( V_7 , V_9 , V_10 ) ) {
F_88 ( & V_78 -> V_12 -> V_83 ) ;
}
error = F_89 ( V_85 ,
V_90 | V_91 ,
V_84 , V_10 - V_9 ) ;
F_90 ( V_85 ) ;
F_83 ( & V_78 -> V_12 -> V_83 ) ;
return error ;
}
static int F_91 ( int V_1 ,
unsigned long V_9 , unsigned long V_10 )
{
struct V_61 * V_61 ;
struct V_92 * V_92 ;
unsigned int V_93 ;
if ( ! F_92 ( V_94 ) )
return - V_95 ;
for (; V_9 < V_10 ; V_9 += V_58 << V_93 ) {
int V_96 ;
V_96 = F_93 ( V_9 , 1 , 0 , & V_61 ) ;
if ( V_96 != 1 )
return V_96 ;
V_93 = F_94 ( F_95 ( V_61 ) ) ;
if ( F_96 ( V_61 ) ) {
F_18 ( V_61 ) ;
continue;
}
if ( V_1 == V_97 ) {
F_97 ( L_1 ,
F_98 ( V_61 ) , V_9 ) ;
V_96 = F_99 ( V_61 , V_98 ) ;
if ( V_96 )
return V_96 ;
continue;
}
F_97 ( L_2 ,
F_98 ( V_61 ) , V_9 ) ;
V_96 = F_100 ( F_98 ( V_61 ) , 0 , V_98 ) ;
if ( V_96 )
return V_96 ;
}
F_101 (zone)
F_102 ( V_92 ) ;
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
case V_37 :
case V_38 :
#endif
#ifdef F_106
case V_41 :
case V_42 :
#endif
case V_33 :
case V_35 :
case V_28 :
case V_32 :
#ifdef F_107
case V_97 :
case V_99 :
#endif
return true ;
default:
return false ;
}
}
