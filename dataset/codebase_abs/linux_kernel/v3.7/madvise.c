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
static long F_8 ( struct V_5 * V_6 ,
struct V_5 * * V_7 ,
unsigned long V_8 , unsigned long V_9 )
{
struct V_44 * V_44 = V_6 -> V_39 ;
if ( ! V_44 )
return - V_45 ;
if ( V_44 -> V_46 -> V_47 -> V_48 ) {
return 0 ;
}
* V_7 = V_6 ;
V_8 = ( ( V_8 - V_6 -> V_36 ) >> V_37 ) + V_6 -> V_35 ;
if ( V_9 > V_6 -> V_41 )
V_9 = V_6 -> V_41 ;
V_9 = ( ( V_9 - V_6 -> V_36 ) >> V_37 ) + V_6 -> V_35 ;
F_9 ( V_44 -> V_46 , V_44 , V_8 , V_9 - V_8 ) ;
return 0 ;
}
static long F_10 ( struct V_5 * V_6 ,
struct V_5 * * V_7 ,
unsigned long V_8 , unsigned long V_9 )
{
* V_7 = V_6 ;
if ( V_6 -> V_15 & ( V_49 | V_50 | V_51 ) )
return - V_25 ;
if ( F_11 ( V_6 -> V_15 & V_52 ) ) {
struct V_53 V_54 = {
. V_55 = V_6 ,
. V_56 = V_57 ,
} ;
F_12 ( V_6 , V_8 , V_9 - V_8 , & V_54 ) ;
} else
F_12 ( V_6 , V_8 , V_9 - V_8 , NULL ) ;
return 0 ;
}
static long F_13 ( struct V_5 * V_6 ,
struct V_5 * * V_7 ,
unsigned long V_8 , unsigned long V_9 )
{
T_2 V_58 ;
int error ;
struct V_44 * V_59 ;
* V_7 = NULL ;
if ( V_6 -> V_15 & ( V_49 | V_52 | V_50 ) )
return - V_25 ;
V_59 = V_6 -> V_39 ;
if ( ! V_59 || ! V_59 -> V_46 || ! V_59 -> V_46 -> V_60 ) {
return - V_25 ;
}
if ( ( V_6 -> V_15 & ( V_61 | V_62 ) ) != ( V_61 | V_62 ) )
return - V_63 ;
V_58 = ( T_2 ) ( V_8 - V_6 -> V_36 )
+ ( ( T_2 ) V_6 -> V_35 << V_37 ) ;
F_14 ( V_59 ) ;
F_15 ( & V_64 -> V_11 -> V_65 ) ;
error = F_16 ( V_59 ,
V_66 | V_67 ,
V_58 , V_9 - V_8 ) ;
F_17 ( V_59 ) ;
F_18 ( & V_64 -> V_11 -> V_65 ) ;
return error ;
}
static int F_19 ( int V_68 , unsigned long V_8 , unsigned long V_9 )
{
int V_69 = 0 ;
if ( ! F_20 ( V_70 ) )
return - V_71 ;
for (; V_8 < V_9 ; V_8 += V_72 ) {
struct V_73 * V_74 ;
int V_69 = F_21 ( V_8 , 1 , 0 , & V_74 ) ;
if ( V_69 != 1 )
return V_69 ;
if ( V_68 == V_75 ) {
F_22 ( V_76 L_1 ,
F_23 ( V_74 ) , V_8 ) ;
V_69 = F_24 ( V_74 , V_77 ) ;
if ( V_69 )
break;
continue;
}
F_22 ( V_76 L_2 ,
F_23 ( V_74 ) , V_8 ) ;
F_25 ( F_23 ( V_74 ) , 0 , V_77 ) ;
}
return V_69 ;
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
case V_31 :
case V_32 :
#endif
#ifdef F_29
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
