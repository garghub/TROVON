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
case V_28 :
error = F_3 ( V_6 , V_8 , V_9 , V_1 , & V_14 ) ;
if ( error )
goto V_26;
break;
case V_29 :
case V_30 :
error = F_4 ( V_6 , & V_14 , V_1 ) ;
if ( error )
goto V_26;
break;
}
if ( V_14 == V_6 -> V_15 ) {
* V_7 = V_6 ;
goto V_26;
}
V_13 = V_6 -> V_31 + ( ( V_8 - V_6 -> V_32 ) >> V_33 ) ;
* V_7 = F_5 ( V_11 , * V_7 , V_8 , V_9 , V_14 , V_6 -> V_34 ,
V_6 -> V_35 , V_13 , F_6 ( V_6 ) ) ;
if ( * V_7 ) {
V_6 = * V_7 ;
goto V_36;
}
* V_7 = V_6 ;
if ( V_8 != V_6 -> V_32 ) {
error = F_7 ( V_11 , V_6 , V_8 , 1 ) ;
if ( error )
goto V_26;
}
if ( V_9 != V_6 -> V_37 ) {
error = F_7 ( V_11 , V_6 , V_9 , 0 ) ;
if ( error )
goto V_26;
}
V_36:
V_6 -> V_15 = V_14 ;
V_26:
if ( error == - V_38 )
error = - V_39 ;
return error ;
}
static long F_8 ( struct V_5 * V_6 ,
struct V_5 * * V_7 ,
unsigned long V_8 , unsigned long V_9 )
{
struct V_40 * V_40 = V_6 -> V_35 ;
if ( ! V_40 )
return - V_41 ;
if ( V_40 -> V_42 -> V_43 -> V_44 ) {
return 0 ;
}
* V_7 = V_6 ;
V_8 = ( ( V_8 - V_6 -> V_32 ) >> V_33 ) + V_6 -> V_31 ;
if ( V_9 > V_6 -> V_37 )
V_9 = V_6 -> V_37 ;
V_9 = ( ( V_9 - V_6 -> V_32 ) >> V_33 ) + V_6 -> V_31 ;
F_9 ( V_40 -> V_42 , V_40 , V_8 , V_9 - V_8 ) ;
return 0 ;
}
static long F_10 ( struct V_5 * V_6 ,
struct V_5 * * V_7 ,
unsigned long V_8 , unsigned long V_9 )
{
* V_7 = V_6 ;
if ( V_6 -> V_15 & ( V_45 | V_46 | V_47 ) )
return - V_25 ;
if ( F_11 ( V_6 -> V_15 & V_48 ) ) {
struct V_49 V_50 = {
. V_51 = V_6 ,
. V_52 = V_53 ,
} ;
F_12 ( V_6 , V_8 , V_9 - V_8 , & V_50 ) ;
} else
F_12 ( V_6 , V_8 , V_9 - V_8 , NULL ) ;
return 0 ;
}
static long F_13 ( struct V_5 * V_6 ,
struct V_5 * * V_7 ,
unsigned long V_8 , unsigned long V_9 )
{
struct V_54 * V_55 ;
T_2 V_56 , V_57 ;
int error ;
* V_7 = NULL ;
if ( V_6 -> V_15 & ( V_45 | V_48 | V_46 ) )
return - V_25 ;
if ( ! V_6 -> V_35 || ! V_6 -> V_35 -> V_42
|| ! V_6 -> V_35 -> V_42 -> V_58 ) {
return - V_25 ;
}
if ( ( V_6 -> V_15 & ( V_59 | V_60 ) ) != ( V_59 | V_60 ) )
return - V_61 ;
V_55 = V_6 -> V_35 -> V_42 ;
V_56 = ( T_2 ) ( V_8 - V_6 -> V_32 )
+ ( ( T_2 ) V_6 -> V_31 << V_33 ) ;
V_57 = ( T_2 ) ( V_9 - V_6 -> V_32 - 1 )
+ ( ( T_2 ) V_6 -> V_31 << V_33 ) ;
F_14 ( & V_62 -> V_11 -> V_63 ) ;
error = F_15 ( V_55 -> V_58 , V_56 , V_57 ) ;
F_16 ( & V_62 -> V_11 -> V_63 ) ;
return error ;
}
static int F_17 ( int V_64 , unsigned long V_8 , unsigned long V_9 )
{
int V_65 = 0 ;
if ( ! F_18 ( V_66 ) )
return - V_67 ;
for (; V_8 < V_9 ; V_8 += V_68 ) {
struct V_69 * V_70 ;
int V_65 = F_19 ( V_8 , 1 , 0 , & V_70 ) ;
if ( V_65 != 1 )
return V_65 ;
if ( V_64 == V_71 ) {
F_20 ( V_72 L_1 ,
F_21 ( V_70 ) , V_8 ) ;
V_65 = F_22 ( V_70 , V_73 ) ;
if ( V_65 )
break;
continue;
}
F_20 ( V_72 L_2 ,
F_21 ( V_70 ) , V_8 ) ;
F_23 ( F_21 ( V_70 ) , 0 , V_73 ) ;
}
return V_65 ;
}
static long
F_24 ( struct V_5 * V_6 , struct V_5 * * V_7 ,
unsigned long V_8 , unsigned long V_9 , int V_1 )
{
switch ( V_1 ) {
case V_2 :
return F_13 ( V_6 , V_7 , V_8 , V_9 ) ;
case V_3 :
return F_8 ( V_6 , V_7 , V_8 , V_9 ) ;
case V_4 :
return F_10 ( V_6 , V_7 , V_8 , V_9 ) ;
default:
return F_2 ( V_6 , V_7 , V_8 , V_9 , V_1 ) ;
}
}
static int
F_25 ( int V_1 )
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
#ifdef F_26
case V_27 :
case V_28 :
#endif
#ifdef F_27
case V_29 :
case V_30 :
#endif
return 1 ;
default:
return 0 ;
}
}
