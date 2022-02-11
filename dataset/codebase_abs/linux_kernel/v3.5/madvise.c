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
V_14 &= ~ V_28 ;
break;
case V_30 :
case V_31 :
error = F_3 ( V_6 , V_8 , V_9 , V_1 , & V_14 ) ;
if ( error )
goto V_26;
break;
case V_32 :
case V_33 :
error = F_4 ( V_6 , & V_14 , V_1 ) ;
if ( error )
goto V_26;
break;
}
if ( V_14 == V_6 -> V_15 ) {
* V_7 = V_6 ;
goto V_26;
}
V_13 = V_6 -> V_34 + ( ( V_8 - V_6 -> V_35 ) >> V_36 ) ;
* V_7 = F_5 ( V_11 , * V_7 , V_8 , V_9 , V_14 , V_6 -> V_37 ,
V_6 -> V_38 , V_13 , F_6 ( V_6 ) ) ;
if ( * V_7 ) {
V_6 = * V_7 ;
goto V_39;
}
* V_7 = V_6 ;
if ( V_8 != V_6 -> V_35 ) {
error = F_7 ( V_11 , V_6 , V_8 , 1 ) ;
if ( error )
goto V_26;
}
if ( V_9 != V_6 -> V_40 ) {
error = F_7 ( V_11 , V_6 , V_9 , 0 ) ;
if ( error )
goto V_26;
}
V_39:
V_6 -> V_15 = V_14 ;
V_26:
if ( error == - V_41 )
error = - V_42 ;
return error ;
}
static long F_8 ( struct V_5 * V_6 ,
struct V_5 * * V_7 ,
unsigned long V_8 , unsigned long V_9 )
{
struct V_43 * V_43 = V_6 -> V_38 ;
if ( ! V_43 )
return - V_44 ;
if ( V_43 -> V_45 -> V_46 -> V_47 ) {
return 0 ;
}
* V_7 = V_6 ;
V_8 = ( ( V_8 - V_6 -> V_35 ) >> V_36 ) + V_6 -> V_34 ;
if ( V_9 > V_6 -> V_40 )
V_9 = V_6 -> V_40 ;
V_9 = ( ( V_9 - V_6 -> V_35 ) >> V_36 ) + V_6 -> V_34 ;
F_9 ( V_43 -> V_45 , V_43 , V_8 , V_9 - V_8 ) ;
return 0 ;
}
static long F_10 ( struct V_5 * V_6 ,
struct V_5 * * V_7 ,
unsigned long V_8 , unsigned long V_9 )
{
* V_7 = V_6 ;
if ( V_6 -> V_15 & ( V_48 | V_49 | V_50 ) )
return - V_25 ;
if ( F_11 ( V_6 -> V_15 & V_51 ) ) {
struct V_52 V_53 = {
. V_54 = V_6 ,
. V_55 = V_56 ,
} ;
F_12 ( V_6 , V_8 , V_9 - V_8 , & V_53 ) ;
} else
F_12 ( V_6 , V_8 , V_9 - V_8 , NULL ) ;
return 0 ;
}
static long F_13 ( struct V_5 * V_6 ,
struct V_5 * * V_7 ,
unsigned long V_8 , unsigned long V_9 )
{
T_2 V_57 ;
int error ;
struct V_43 * V_58 ;
* V_7 = NULL ;
if ( V_6 -> V_15 & ( V_48 | V_51 | V_49 ) )
return - V_25 ;
V_58 = V_6 -> V_38 ;
if ( ! V_58 || ! V_58 -> V_45 || ! V_58 -> V_45 -> V_59 ) {
return - V_25 ;
}
if ( ( V_6 -> V_15 & ( V_60 | V_61 ) ) != ( V_60 | V_61 ) )
return - V_62 ;
V_57 = ( T_2 ) ( V_8 - V_6 -> V_35 )
+ ( ( T_2 ) V_6 -> V_34 << V_36 ) ;
F_14 ( V_58 ) ;
F_15 ( & V_63 -> V_11 -> V_64 ) ;
error = F_16 ( V_58 ,
V_65 | V_66 ,
V_57 , V_9 - V_8 ) ;
F_17 ( V_58 ) ;
F_18 ( & V_63 -> V_11 -> V_64 ) ;
return error ;
}
static int F_19 ( int V_67 , unsigned long V_8 , unsigned long V_9 )
{
int V_68 = 0 ;
if ( ! F_20 ( V_69 ) )
return - V_70 ;
for (; V_8 < V_9 ; V_8 += V_71 ) {
struct V_72 * V_73 ;
int V_68 = F_21 ( V_8 , 1 , 0 , & V_73 ) ;
if ( V_68 != 1 )
return V_68 ;
if ( V_67 == V_74 ) {
F_22 ( V_75 L_1 ,
F_23 ( V_73 ) , V_8 ) ;
V_68 = F_24 ( V_73 , V_76 ) ;
if ( V_68 )
break;
continue;
}
F_22 ( V_75 L_2 ,
F_23 ( V_73 ) , V_8 ) ;
F_25 ( F_23 ( V_73 ) , 0 , V_76 ) ;
}
return V_68 ;
}
static long
F_26 ( struct V_5 * V_6 , struct V_5 * * V_7 ,
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
F_27 ( int V_1 )
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
#ifdef F_28
case V_30 :
case V_31 :
#endif
#ifdef F_29
case V_32 :
case V_33 :
#endif
case V_27 :
case V_29 :
return 1 ;
default:
return 0 ;
}
}
