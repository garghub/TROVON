static int F_1 ( int V_1 )
{
switch ( V_1 ) {
case V_2 :
case V_3 :
case V_4 :
return 0 ;
default:
return 1 ;
}
}
static long F_2 ( struct V_5 * V_6 ,
struct V_5 * * V_7 ,
unsigned long V_8 , unsigned long V_9 , int V_1 )
{
struct V_10 * V_11 = V_6 -> V_12 ;
int error = 0 ;
T_1 V_13 ;
unsigned long V_14 = V_6 -> V_15 ;
switch ( V_1 ) {
case V_16 :
V_14 = V_14 & ~ V_17 & ~ V_18 ;
break;
case V_19 :
V_14 = ( V_14 & ~ V_17 ) | V_18 ;
break;
case V_20 :
V_14 = ( V_14 & ~ V_18 ) | V_17 ;
break;
case V_21 :
V_14 |= V_22 ;
break;
case V_23 :
if ( V_6 -> V_15 & V_24 ) {
error = - V_25 ;
goto V_26;
}
V_14 &= ~ V_22 ;
break;
case V_27 :
V_14 |= V_28 ;
break;
case V_29 :
if ( V_14 & V_30 ) {
error = - V_25 ;
goto V_26;
}
V_14 &= ~ V_28 ;
break;
case V_31 :
case V_32 :
error = F_3 ( V_6 , V_8 , V_9 , V_1 , & V_14 ) ;
if ( error )
goto V_26;
break;
case V_33 :
case V_34 :
error = F_4 ( V_6 , & V_14 , V_1 ) ;
if ( error )
goto V_26;
break;
}
if ( V_14 == V_6 -> V_15 ) {
* V_7 = V_6 ;
goto V_26;
}
V_13 = V_6 -> V_35 + ( ( V_8 - V_6 -> V_36 ) >> V_37 ) ;
* V_7 = F_5 ( V_11 , * V_7 , V_8 , V_9 , V_14 , V_6 -> V_38 ,
V_6 -> V_39 , V_13 , F_6 ( V_6 ) ,
V_6 -> V_40 ) ;
if ( * V_7 ) {
V_6 = * V_7 ;
goto V_41;
}
* V_7 = V_6 ;
if ( V_8 != V_6 -> V_36 ) {
error = F_7 ( V_11 , V_6 , V_8 , 1 ) ;
if ( error )
goto V_26;
}
if ( V_9 != V_6 -> V_42 ) {
error = F_7 ( V_11 , V_6 , V_9 , 0 ) ;
if ( error )
goto V_26;
}
V_41:
V_6 -> V_15 = V_14 ;
V_26:
if ( error == - V_43 )
error = - V_44 ;
return error ;
}
static int F_8 ( T_2 * V_45 , unsigned long V_8 ,
unsigned long V_9 , struct V_46 * V_47 )
{
T_3 * V_48 ;
struct V_5 * V_6 = V_47 -> V_49 ;
unsigned long V_50 ;
if ( F_9 ( V_45 ) )
return 0 ;
for ( V_50 = V_8 ; V_50 != V_9 ; V_50 += V_51 ) {
T_3 V_52 ;
T_4 V_53 ;
struct V_54 * V_54 ;
T_5 * V_55 ;
V_48 = F_10 ( V_6 -> V_12 , V_45 , V_8 , & V_55 ) ;
V_52 = * ( V_48 + ( ( V_50 - V_8 ) / V_51 ) ) ;
F_11 ( V_48 , V_55 ) ;
if ( F_12 ( V_52 ) || F_13 ( V_52 ) )
continue;
V_53 = F_14 ( V_52 ) ;
if ( F_15 ( F_16 ( V_53 ) ) )
continue;
V_54 = F_17 ( V_53 , V_56 ,
V_6 , V_50 ) ;
if ( V_54 )
F_18 ( V_54 ) ;
}
return 0 ;
}
static void F_19 ( struct V_5 * V_6 ,
unsigned long V_8 , unsigned long V_9 )
{
struct V_46 V_47 = {
. V_11 = V_6 -> V_12 ,
. V_57 = F_8 ,
. V_49 = V_6 ,
} ;
F_20 ( V_8 , V_9 , & V_47 ) ;
F_21 () ;
}
static void F_22 ( struct V_5 * V_6 ,
unsigned long V_8 , unsigned long V_9 ,
struct V_58 * V_59 )
{
T_1 V_50 ;
struct V_54 * V_54 ;
T_4 V_60 ;
for (; V_8 < V_9 ; V_8 += V_51 ) {
V_50 = ( ( V_8 - V_6 -> V_36 ) >> V_37 ) + V_6 -> V_35 ;
V_54 = F_23 ( V_59 , V_50 ) ;
if ( ! F_24 ( V_54 ) ) {
if ( V_54 )
F_18 ( V_54 ) ;
continue;
}
V_60 = F_25 ( V_54 ) ;
V_54 = F_17 ( V_60 , V_56 ,
NULL , 0 ) ;
if ( V_54 )
F_18 ( V_54 ) ;
}
F_21 () ;
}
static long F_26 ( struct V_5 * V_6 ,
struct V_5 * * V_7 ,
unsigned long V_8 , unsigned long V_9 )
{
struct V_61 * V_61 = V_6 -> V_39 ;
#ifdef F_27
if ( ! V_61 ) {
* V_7 = V_6 ;
F_19 ( V_6 , V_8 , V_9 ) ;
return 0 ;
}
if ( F_28 ( V_61 -> V_62 ) ) {
* V_7 = V_6 ;
F_22 ( V_6 , V_8 , V_9 ,
V_61 -> V_62 ) ;
return 0 ;
}
#else
if ( ! V_61 )
return - V_63 ;
#endif
if ( F_29 ( F_30 ( V_61 ) ) ) {
return 0 ;
}
* V_7 = V_6 ;
V_8 = ( ( V_8 - V_6 -> V_36 ) >> V_37 ) + V_6 -> V_35 ;
if ( V_9 > V_6 -> V_42 )
V_9 = V_6 -> V_42 ;
V_9 = ( ( V_9 - V_6 -> V_36 ) >> V_37 ) + V_6 -> V_35 ;
F_31 ( V_61 -> V_62 , V_61 , V_8 , V_9 - V_8 ) ;
return 0 ;
}
static long F_32 ( struct V_5 * V_6 ,
struct V_5 * * V_7 ,
unsigned long V_8 , unsigned long V_9 )
{
* V_7 = V_6 ;
if ( V_6 -> V_15 & ( V_64 | V_65 | V_66 ) )
return - V_25 ;
F_33 ( V_6 , V_8 , V_9 - V_8 , NULL ) ;
return 0 ;
}
static long F_34 ( struct V_5 * V_6 ,
struct V_5 * * V_7 ,
unsigned long V_8 , unsigned long V_9 )
{
T_6 V_67 ;
int error ;
struct V_61 * V_68 ;
* V_7 = NULL ;
if ( V_6 -> V_15 & V_64 )
return - V_25 ;
V_68 = V_6 -> V_39 ;
if ( ! V_68 || ! V_68 -> V_62 || ! V_68 -> V_62 -> V_69 ) {
return - V_25 ;
}
if ( ( V_6 -> V_15 & ( V_70 | V_71 ) ) != ( V_70 | V_71 ) )
return - V_72 ;
V_67 = ( T_6 ) ( V_8 - V_6 -> V_36 )
+ ( ( T_6 ) V_6 -> V_35 << V_37 ) ;
F_35 ( V_68 ) ;
F_36 ( & V_73 -> V_11 -> V_74 ) ;
error = F_37 ( V_68 ,
V_75 | V_76 ,
V_67 , V_9 - V_8 ) ;
F_38 ( V_68 ) ;
F_39 ( & V_73 -> V_11 -> V_74 ) ;
return error ;
}
static int F_40 ( int V_77 , unsigned long V_8 , unsigned long V_9 )
{
struct V_54 * V_78 ;
if ( ! F_41 ( V_79 ) )
return - V_80 ;
for (; V_8 < V_9 ; V_8 += V_51 <<
F_42 ( F_43 ( V_78 ) ) ) {
int V_81 ;
V_81 = F_44 ( V_8 , 1 , 0 , & V_78 ) ;
if ( V_81 != 1 )
return V_81 ;
if ( F_45 ( V_78 ) ) {
F_46 ( V_78 ) ;
continue;
}
if ( V_77 == V_82 ) {
F_47 ( L_1 ,
F_48 ( V_78 ) , V_8 ) ;
V_81 = F_49 ( V_78 , V_83 ) ;
if ( V_81 )
return V_81 ;
continue;
}
F_47 ( L_2 ,
F_48 ( V_78 ) , V_8 ) ;
F_50 ( F_48 ( V_78 ) , 0 , V_83 ) ;
}
return 0 ;
}
static long
F_51 ( struct V_5 * V_6 , struct V_5 * * V_7 ,
unsigned long V_8 , unsigned long V_9 , int V_1 )
{
switch ( V_1 ) {
case V_2 :
return F_34 ( V_6 , V_7 , V_8 , V_9 ) ;
case V_3 :
return F_26 ( V_6 , V_7 , V_8 , V_9 ) ;
case V_4 :
return F_32 ( V_6 , V_7 , V_8 , V_9 ) ;
default:
return F_2 ( V_6 , V_7 , V_8 , V_9 , V_1 ) ;
}
}
static bool
F_52 ( int V_1 )
{
switch ( V_1 ) {
case V_23 :
case V_21 :
case V_16 :
case V_19 :
case V_20 :
case V_2 :
case V_3 :
case V_4 :
#ifdef F_53
case V_31 :
case V_32 :
#endif
#ifdef F_54
case V_33 :
case V_34 :
#endif
case V_27 :
case V_29 :
return true ;
default:
return false ;
}
}
