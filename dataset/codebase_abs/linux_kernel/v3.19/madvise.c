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
V_6 -> V_39 , V_13 , F_6 ( V_6 ) ) ;
if ( * V_7 ) {
V_6 = * V_7 ;
goto V_40;
}
* V_7 = V_6 ;
if ( V_8 != V_6 -> V_36 ) {
error = F_7 ( V_11 , V_6 , V_8 , 1 ) ;
if ( error )
goto V_26;
}
if ( V_9 != V_6 -> V_41 ) {
error = F_7 ( V_11 , V_6 , V_9 , 0 ) ;
if ( error )
goto V_26;
}
V_40:
V_6 -> V_15 = V_14 ;
V_26:
if ( error == - V_42 )
error = - V_43 ;
return error ;
}
static int F_8 ( T_2 * V_44 , unsigned long V_8 ,
unsigned long V_9 , struct V_45 * V_46 )
{
T_3 * V_47 ;
struct V_5 * V_6 = V_46 -> V_48 ;
unsigned long V_49 ;
if ( F_9 ( V_44 ) )
return 0 ;
for ( V_49 = V_8 ; V_49 != V_9 ; V_49 += V_50 ) {
T_3 V_51 ;
T_4 V_52 ;
struct V_53 * V_53 ;
T_5 * V_54 ;
V_47 = F_10 ( V_6 -> V_12 , V_44 , V_8 , & V_54 ) ;
V_51 = * ( V_47 + ( ( V_49 - V_8 ) / V_50 ) ) ;
F_11 ( V_47 , V_54 ) ;
if ( F_12 ( V_51 ) || F_13 ( V_51 ) || F_14 ( V_51 ) )
continue;
V_52 = F_15 ( V_51 ) ;
if ( F_16 ( F_17 ( V_52 ) ) )
continue;
V_53 = F_18 ( V_52 , V_55 ,
V_6 , V_49 ) ;
if ( V_53 )
F_19 ( V_53 ) ;
}
return 0 ;
}
static void F_20 ( struct V_5 * V_6 ,
unsigned long V_8 , unsigned long V_9 )
{
struct V_45 V_46 = {
. V_11 = V_6 -> V_12 ,
. V_56 = F_8 ,
. V_48 = V_6 ,
} ;
F_21 ( V_8 , V_9 , & V_46 ) ;
F_22 () ;
}
static void F_23 ( struct V_5 * V_6 ,
unsigned long V_8 , unsigned long V_9 ,
struct V_57 * V_58 )
{
T_1 V_49 ;
struct V_53 * V_53 ;
T_4 V_59 ;
for (; V_8 < V_9 ; V_8 += V_50 ) {
V_49 = ( ( V_8 - V_6 -> V_36 ) >> V_37 ) + V_6 -> V_35 ;
V_53 = F_24 ( V_58 , V_49 ) ;
if ( ! F_25 ( V_53 ) ) {
if ( V_53 )
F_19 ( V_53 ) ;
continue;
}
V_59 = F_26 ( V_53 ) ;
V_53 = F_18 ( V_59 , V_55 ,
NULL , 0 ) ;
if ( V_53 )
F_19 ( V_53 ) ;
}
F_22 () ;
}
static long F_27 ( struct V_5 * V_6 ,
struct V_5 * * V_7 ,
unsigned long V_8 , unsigned long V_9 )
{
struct V_60 * V_60 = V_6 -> V_39 ;
#ifdef F_28
if ( ! V_60 || F_29 ( V_60 -> V_61 ) ) {
* V_7 = V_6 ;
if ( ! V_60 )
F_20 ( V_6 , V_8 , V_9 ) ;
else
F_23 ( V_6 , V_8 , V_9 ,
V_60 -> V_61 ) ;
return 0 ;
}
#endif
if ( ! V_60 )
return - V_62 ;
if ( V_60 -> V_61 -> V_63 -> V_64 ) {
return 0 ;
}
* V_7 = V_6 ;
V_8 = ( ( V_8 - V_6 -> V_36 ) >> V_37 ) + V_6 -> V_35 ;
if ( V_9 > V_6 -> V_41 )
V_9 = V_6 -> V_41 ;
V_9 = ( ( V_9 - V_6 -> V_36 ) >> V_37 ) + V_6 -> V_35 ;
F_30 ( V_60 -> V_61 , V_60 , V_8 , V_9 - V_8 ) ;
return 0 ;
}
static long F_31 ( struct V_5 * V_6 ,
struct V_5 * * V_7 ,
unsigned long V_8 , unsigned long V_9 )
{
* V_7 = V_6 ;
if ( V_6 -> V_15 & ( V_65 | V_66 | V_67 ) )
return - V_25 ;
if ( F_16 ( V_6 -> V_15 & V_68 ) ) {
struct V_69 V_70 = {
. V_71 = V_6 ,
. V_72 = V_73 ,
} ;
F_32 ( V_6 , V_8 , V_9 - V_8 , & V_70 ) ;
} else
F_32 ( V_6 , V_8 , V_9 - V_8 , NULL ) ;
return 0 ;
}
static long F_33 ( struct V_5 * V_6 ,
struct V_5 * * V_7 ,
unsigned long V_8 , unsigned long V_9 )
{
T_6 V_74 ;
int error ;
struct V_60 * V_75 ;
* V_7 = NULL ;
if ( V_6 -> V_15 & ( V_65 | V_68 | V_66 ) )
return - V_25 ;
V_75 = V_6 -> V_39 ;
if ( ! V_75 || ! V_75 -> V_61 || ! V_75 -> V_61 -> V_76 ) {
return - V_25 ;
}
if ( ( V_6 -> V_15 & ( V_77 | V_78 ) ) != ( V_77 | V_78 ) )
return - V_79 ;
V_74 = ( T_6 ) ( V_8 - V_6 -> V_36 )
+ ( ( T_6 ) V_6 -> V_35 << V_37 ) ;
F_34 ( V_75 ) ;
F_35 ( & V_80 -> V_11 -> V_81 ) ;
error = F_36 ( V_75 ,
V_82 | V_83 ,
V_74 , V_9 - V_8 ) ;
F_37 ( V_75 ) ;
F_38 ( & V_80 -> V_11 -> V_81 ) ;
return error ;
}
static int F_39 ( int V_84 , unsigned long V_8 , unsigned long V_9 )
{
struct V_53 * V_85 ;
if ( ! F_40 ( V_86 ) )
return - V_87 ;
for (; V_8 < V_9 ; V_8 += V_50 <<
F_41 ( F_42 ( V_85 ) ) ) {
int V_88 ;
V_88 = F_43 ( V_8 , 1 , 0 , & V_85 ) ;
if ( V_88 != 1 )
return V_88 ;
if ( F_44 ( V_85 ) ) {
F_45 ( V_85 ) ;
continue;
}
if ( V_84 == V_89 ) {
F_46 ( L_1 ,
F_47 ( V_85 ) , V_8 ) ;
V_88 = F_48 ( V_85 , V_90 ) ;
if ( V_88 )
return V_88 ;
continue;
}
F_46 ( L_2 ,
F_47 ( V_85 ) , V_8 ) ;
F_49 ( F_47 ( V_85 ) , 0 , V_90 ) ;
}
return 0 ;
}
static long
F_50 ( struct V_5 * V_6 , struct V_5 * * V_7 ,
unsigned long V_8 , unsigned long V_9 , int V_1 )
{
switch ( V_1 ) {
case V_2 :
return F_33 ( V_6 , V_7 , V_8 , V_9 ) ;
case V_3 :
return F_27 ( V_6 , V_7 , V_8 , V_9 ) ;
case V_4 :
return F_31 ( V_6 , V_7 , V_8 , V_9 ) ;
default:
return F_2 ( V_6 , V_7 , V_8 , V_9 , V_1 ) ;
}
}
static int
F_51 ( int V_1 )
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
#ifdef F_52
case V_31 :
case V_32 :
#endif
#ifdef F_53
case V_33 :
case V_34 :
#endif
case V_27 :
case V_29 :
return 1 ;
default:
return 0 ;
}
}
