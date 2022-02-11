static T_1 F_1 ( T_2 * V_1 , T_3 V_2 , T_4 V_3 , T_5 * V_4 )
{
T_6 * V_5 = V_1 -> V_6 ;
T_1 V_7 = V_8 ;
T_3 V_9 ;
T_1 V_10 = V_8 ;
V_9 = 0 ;
while ( V_9 ++ < V_11 )
{
if ( V_2 == 0 )
{
#if F_2 ( V_12 ) && F_2 ( V_13 )
F_3 ( L_1 , V_3 ) ;
#endif
V_10 = F_4 ( V_5 , V_3 , V_4 ) ;
}
else
{
#ifdef F_5
F_6 ( V_1 -> V_14 ,
L_2 ) ;
return V_15 ;
#else
#if F_2 ( V_12 ) && F_2 ( V_13 )
F_3 ( L_3 , V_3 ) ;
#endif
V_10 = F_7 ( V_5 , V_3 , V_4 ) ;
#endif
}
#if F_2 ( V_12 ) && F_2 ( V_13 )
if ( V_10 != V_8 )
{
F_3 ( L_4 , V_10 ) ;
}
else
{
F_3 ( L_5 , * V_4 ) ;
}
#endif
if ( V_10 == V_16 )
{
return V_17 ;
}
if ( ! F_8 ( V_10 ) )
{
#ifdef F_9
V_1 -> V_18 . V_19 ++ ;
#endif
break;
}
F_10 ( V_1 -> V_14 , V_20 , L_6 , V_2 , V_3 ) ;
}
if ( ( V_10 == V_8 ) && ( V_9 > 1 ) )
{
F_11 ( V_1 -> V_14 , L_7 , V_9 ) ;
}
if ( V_10 != V_8 )
{
F_6 ( V_1 -> V_14 , L_8 ,
V_3 , V_9 - 1 ) ;
V_7 = V_15 ;
}
return V_7 ;
}
static T_1 F_12 ( T_2 * V_1 , T_3 V_2 , T_4 V_3 , T_5 V_21 )
{
T_6 * V_5 = V_1 -> V_6 ;
T_1 V_7 = V_8 ;
T_3 V_9 ;
T_1 V_10 = V_8 ;
V_9 = 0 ;
while ( V_9 ++ < V_11 )
{
if ( V_2 == 0 )
{
#if F_2 ( V_12 ) && F_2 ( V_13 )
F_3 ( L_9 , V_3 , V_21 ) ;
#endif
V_10 = F_13 ( V_5 , V_3 , V_21 ) ;
}
else
{
#ifdef F_5
F_6 ( V_1 -> V_14 ,
L_10 ) ;
return V_15 ;
#else
#if F_2 ( V_12 ) && F_2 ( V_13 )
F_3 ( L_11 , V_3 , V_21 ) ;
#endif
V_10 = F_14 ( V_5 , V_3 , V_21 ) ;
#endif
}
#if F_2 ( V_12 ) && F_2 ( V_13 )
if ( V_10 != V_8 )
{
F_3 ( L_12 , V_10 ) ;
}
F_15 ( L_13 ) ;
#endif
if ( V_10 == V_16 )
{
return V_17 ;
}
if ( ! F_8 ( V_10 ) )
{
#ifdef F_9
V_1 -> V_18 . V_19 ++ ;
#endif
break;
}
F_10 ( V_1 -> V_14 , V_20 , L_14 ,
V_21 , V_2 , V_3 ) ;
}
if ( ( V_10 == V_8 ) && ( V_9 > 1 ) )
{
F_11 ( V_1 -> V_14 , L_15 , V_9 ) ;
}
if ( V_10 != V_8 )
{
F_6 ( V_1 -> V_14 , L_16 ,
V_3 , V_9 - 1 ) ;
V_7 = V_15 ;
}
return V_7 ;
}
static T_1 F_16 ( T_2 * V_1 , T_3 V_2 ,
T_4 V_3 , T_7 * V_4 )
{
T_6 * V_5 = V_1 -> V_6 ;
T_1 V_7 = V_8 ;
T_3 V_9 ;
T_1 V_10 = V_8 ;
V_9 = 0 ;
while ( V_9 ++ < V_11 )
{
#if F_2 ( V_12 ) && F_2 ( V_13 )
F_3 ( L_3 , V_3 ) ;
#endif
V_10 = F_17 ( V_5 , V_3 , V_4 ) ;
#if F_2 ( V_12 ) && F_2 ( V_13 )
if ( V_10 != V_8 )
{
F_3 ( L_4 , V_10 ) ;
}
else
{
F_3 ( L_5 , * V_4 ) ;
}
#endif
if ( V_10 == V_16 )
{
return V_17 ;
}
if ( ! F_8 ( V_10 ) )
{
#ifdef F_9
V_1 -> V_18 . V_19 ++ ;
#endif
break;
}
F_10 ( V_1 -> V_14 , V_20 , L_6 , V_2 , V_3 ) ;
}
if ( ( V_10 == V_8 ) && ( V_9 > 1 ) )
{
F_11 ( V_1 -> V_14 , L_7 , V_9 ) ;
}
if ( V_10 != V_8 )
{
F_6 ( V_1 -> V_14 , L_8 ,
V_3 , V_9 - 1 ) ;
V_7 = V_15 ;
}
return V_7 ;
}
static T_1 F_18 ( T_2 * V_1 , T_3 V_2 ,
T_4 V_3 , T_7 V_21 )
{
T_6 * V_5 = V_1 -> V_6 ;
T_1 V_7 = V_8 ;
T_3 V_9 ;
T_1 V_10 = V_8 ;
V_9 = 0 ;
while ( V_9 ++ < V_11 )
{
#if F_2 ( V_12 ) && F_2 ( V_13 )
F_3 ( L_11 , V_3 , V_21 ) ;
#endif
V_10 = F_19 ( V_5 , V_3 , V_21 ) ;
#if F_2 ( V_12 ) && F_2 ( V_13 )
if ( V_10 != V_8 )
{
F_3 ( L_12 , V_10 ) ;
}
F_15 ( L_13 ) ;
#endif
if ( V_10 == V_16 )
{
return V_17 ;
}
if ( ! F_8 ( V_10 ) )
{
#ifdef F_9
V_1 -> V_18 . V_19 ++ ;
#endif
break;
}
F_10 ( V_1 -> V_14 , V_20 , L_14 ,
V_21 , V_2 , V_3 ) ;
}
if ( ( V_10 == V_8 ) && ( V_9 > 1 ) )
{
F_11 ( V_1 -> V_14 , L_15 , V_9 ) ;
}
if ( V_10 != V_8 )
{
F_6 ( V_1 -> V_14 , L_16 ,
V_3 , V_9 - 1 ) ;
V_7 = V_15 ;
}
return V_7 ;
}
T_1 F_20 ( T_2 * V_1 , T_4 V_3 , T_5 * V_4 )
{
#if F_2 ( V_12 ) && F_2 ( F_9 )
V_1 -> V_18 . V_22 ++ ;
#endif
return F_1 ( V_1 , 0 , V_3 , V_4 ) ;
}
T_1 F_21 ( T_2 * V_1 , T_4 V_3 , T_5 V_21 )
{
#if F_2 ( V_12 ) && F_2 ( F_9 )
V_1 -> V_18 . V_23 ++ ;
#endif
return F_12 ( V_1 , 0 , V_3 , V_21 ) ;
}
T_1 F_22 ( T_2 * V_1 , T_4 V_3 , T_5 * V_4 )
{
#ifdef F_5
T_7 V_24 ;
T_1 V_7 ;
V_7 = F_16 ( V_1 , V_1 -> V_25 , V_3 , & V_24 ) ;
* V_4 = ( T_5 ) ( V_24 & 0xFF ) ;
return V_7 ;
#else
return F_1 ( V_1 , V_1 -> V_25 , V_3 , V_4 ) ;
#endif
}
T_1 F_23 ( T_2 * V_1 , T_4 V_3 , T_5 V_21 )
{
if ( V_3 & 1 )
{
F_11 ( V_1 -> V_14 ,
L_17 ,
V_3 ) ;
}
#ifdef F_5
return F_18 ( V_1 , V_1 -> V_25 , V_3 , ( T_7 ) V_21 ) ;
#else
return F_12 ( V_1 , V_1 -> V_25 , V_3 , V_21 ) ;
#endif
}
T_1 F_24 ( T_2 * V_1 , T_4 V_3 , T_7 * V_4 )
{
return F_16 ( V_1 , V_1 -> V_25 , V_3 , V_4 ) ;
}
T_1 F_25 ( T_2 * V_1 , T_4 V_3 , T_7 V_21 )
{
return F_18 ( V_1 , V_1 -> V_25 , V_3 , V_21 ) ;
}
T_1 F_26 ( T_2 * V_1 , T_4 V_3 , T_4 * V_4 )
{
T_1 V_7 ;
T_7 V_26 , V_27 ;
V_7 = F_16 ( V_1 , V_1 -> V_25 , V_3 , & V_26 ) ;
if ( V_7 != V_8 )
{
return V_7 ;
}
V_7 = F_16 ( V_1 , V_1 -> V_25 , V_3 + 2 , & V_27 ) ;
if ( V_7 != V_8 )
{
return V_7 ;
}
* V_4 = ( ( T_4 ) V_27 << 16 ) | ( T_4 ) V_26 ;
return V_8 ;
}
static T_1 F_27 ( T_2 * V_1 , T_4 V_3 , void * V_4 , T_7 V_28 , T_8 V_29 , T_4 * V_30 )
{
T_1 V_7 ;
T_4 V_31 ;
T_5 * V_32 ;
T_7 V_24 ;
* V_30 = 0 ;
V_32 = ( T_5 * ) V_4 ;
for ( V_31 = 0 ; V_31 < V_28 ; V_31 += 2 )
{
V_7 = F_16 ( V_1 , V_1 -> V_25 , V_3 , & V_24 ) ;
if ( V_7 != V_8 )
{
return V_7 ;
}
* V_32 ++ = ( ( T_5 ) V_24 & 0xFF ) ;
if ( ( V_29 >= 0 ) && ( ( ( T_8 ) V_24 & 0xFF ) == V_29 ) )
{
break;
}
if ( V_31 + 1 == V_28 )
{
break;
}
* V_32 ++ = ( ( T_5 ) ( V_24 >> 8 ) & 0xFF ) ;
if ( ( V_29 >= 0 ) && ( ( ( T_8 ) ( V_24 >> 8 ) & 0xFF ) == V_29 ) )
{
break;
}
V_3 += 2 ;
}
* V_30 = ( V_33 ) ( V_32 - ( T_5 * ) V_4 ) ;
return V_8 ;
}
T_1 F_28 ( T_2 * V_1 , T_4 V_3 , void * V_4 , T_7 V_28 )
{
T_4 V_30 ;
return F_27 ( V_1 , V_3 , V_4 , V_28 , - 1 , & V_30 ) ;
}
T_1 F_29 ( T_2 * V_1 , T_4 V_3 , void * V_4 , T_7 V_28 )
{
T_1 V_7 ;
T_5 * V_32 ;
T_3 V_34 ;
V_32 = ( T_5 * ) V_4 ;
V_34 = ( T_3 ) V_28 ;
while ( V_34 > 0 )
{
V_7 = F_18 ( V_1 , V_1 -> V_25 , V_3 , * V_32 ) ;
if ( V_7 != V_8 )
{
return V_7 ;
}
V_32 += 2 ;
V_3 += 2 ;
V_34 -= 2 ;
}
return V_8 ;
}
static T_1 F_30 ( T_2 * V_1 , T_4 V_35 , T_4 * V_36 )
{
T_7 V_37 , V_3 ;
T_4 V_28 ;
T_1 V_7 ;
* V_36 = 0 ;
if ( ! F_31 ( V_1 -> V_38 ,
V_39 ,
V_40 ,
V_35 / 2 ,
& V_37 , & V_3 , & V_28 ) )
{
F_6 ( V_1 -> V_14 , L_18 , V_35 ) ;
return V_41 ;
}
if ( V_37 != V_1 -> V_42 )
{
F_10 ( V_1 -> V_14 , V_43 , L_19 , V_37 , V_3 ) ;
V_7 = F_25 ( V_1 , F_32 ( V_1 -> V_38 ) * 2 , V_37 ) ;
if ( V_7 != V_8 )
{
F_6 ( V_1 -> V_14 , L_20 ) ;
return V_7 ;
}
V_1 -> V_42 = V_37 ;
}
* V_36 = ( ( V_33 ) V_3 * 2 ) + ( V_35 & 1 ) ;
return V_8 ;
}
static T_1 F_33 ( T_2 * V_1 , T_4 V_44 ,
enum V_45 V_46 , T_4 * V_36 )
{
T_7 V_37 , V_3 ;
T_4 V_28 ;
T_1 V_7 ;
* V_36 = 0 ;
if ( ! F_31 ( V_1 -> V_38 ,
V_47 ,
V_46 ,
V_44 / 2 ,
& V_37 , & V_3 , & V_28 ) )
{
F_6 ( V_1 -> V_14 , L_21 , V_44 , V_46 ) ;
return V_41 ;
}
if ( V_37 != V_1 -> V_48 )
{
F_10 ( V_1 -> V_14 , V_43 , L_22 , V_37 , V_3 ) ;
V_7 = F_25 ( V_1 , F_34 ( V_1 -> V_38 ) * 2 , V_37 ) ;
if ( V_7 != V_8 )
{
F_6 ( V_1 -> V_14 , L_23 ) ;
return V_7 ;
}
V_1 -> V_48 = V_37 ;
}
* V_36 = ( ( V_33 ) V_3 * 2 ) + ( V_44 & 1 ) ;
return V_8 ;
}
static T_1 F_35 ( T_2 * V_1 , T_4 V_49 , T_4 * V_36 )
{
V_33 V_50 ;
T_4 V_3 ;
T_1 V_7 = V_8 ;
if ( ! V_36 )
{
return V_41 ;
}
* V_36 = 0 ;
V_50 = F_36 ( V_49 ) ;
V_3 = F_37 ( V_49 ) ;
switch ( V_50 )
{
case V_51 :
V_7 = F_30 ( V_1 , V_3 , V_36 ) ;
if ( V_7 != V_8 )
{
return V_7 ;
}
break;
case V_52 :
if ( ! F_38 ( V_1 -> V_38 ) )
{
F_6 ( V_1 -> V_14 , L_24 ,
V_49 , V_1 -> V_38 ) ;
return V_41 ;
}
V_7 = F_33 ( V_1 , V_3 , V_53 , V_36 ) ;
break;
case V_54 :
if ( ! F_39 ( V_1 -> V_38 ) )
{
F_6 ( V_1 -> V_14 , L_25 ,
V_49 , V_1 -> V_38 ) ;
return V_41 ;
}
V_7 = F_33 ( V_1 , V_3 , V_55 , V_36 ) ;
break;
case V_56 :
* V_36 = V_3 ;
break;
case V_57 :
V_7 = F_40 ( V_1 , V_58 ) ;
if ( V_7 != V_8 )
{
return V_7 ;
}
* V_36 = F_41 ( V_1 -> V_38 ) * 2 + V_3 ;
break;
case V_59 :
V_7 = F_40 ( V_1 , V_60 ) ;
if ( V_7 != V_8 )
{
return V_7 ;
}
* V_36 = F_41 ( V_1 -> V_38 ) * 2 + V_3 ;
break;
case V_61 :
if ( ! F_42 ( V_1 -> V_38 ) )
{
F_6 ( V_1 -> V_14 , L_24 ,
V_49 , V_1 -> V_38 ) ;
return V_41 ;
}
V_7 = F_40 ( V_1 , V_62 ) ;
if ( V_7 != V_8 )
{
return V_7 ;
}
* V_36 = F_41 ( V_1 -> V_38 ) * 2 + V_3 ;
break;
case V_63 :
V_7 = F_40 ( V_1 , V_58 ) ;
if ( V_7 != V_8 )
{
return V_7 ;
}
V_7 = F_33 ( V_1 , V_3 , V_64 , V_36 ) ;
break;
case V_65 :
V_7 = F_40 ( V_1 , V_60 ) ;
if ( V_7 != V_8 )
{
return V_7 ;
}
V_7 = F_33 ( V_1 , V_3 , V_64 , V_36 ) ;
break;
case V_66 :
if ( ! F_42 ( V_1 -> V_38 ) )
{
F_6 ( V_1 -> V_14 , L_24 ,
V_49 , V_1 -> V_38 ) ;
return V_41 ;
}
V_7 = F_40 ( V_1 , V_62 ) ;
if ( V_7 != V_8 )
{
return V_7 ;
}
V_7 = F_33 ( V_1 , V_3 , V_64 , V_36 ) ;
break;
case V_67 :
if ( ! F_43 ( V_1 -> V_38 ) )
{
F_6 ( V_1 -> V_14 , L_24 ,
V_49 , V_1 -> V_38 ) ;
return V_41 ;
}
V_7 = F_40 ( V_1 , V_58 ) ;
if ( V_7 != V_8 )
{
return V_7 ;
}
V_7 = F_33 ( V_1 , V_3 , V_68 , V_36 ) ;
break;
case V_69 :
if ( ! F_43 ( V_1 -> V_38 ) )
{
F_6 ( V_1 -> V_14 , L_24 ,
V_49 , V_1 -> V_38 ) ;
return V_41 ;
}
V_7 = F_40 ( V_1 , V_60 ) ;
if ( V_7 != V_8 )
{
return V_7 ;
}
V_7 = F_33 ( V_1 , V_3 , V_68 , V_36 ) ;
break;
case V_70 :
if ( ! F_43 ( V_1 -> V_38 ) || ! F_42 ( V_1 -> V_38 ) )
{
F_6 ( V_1 -> V_14 , L_24 ,
V_49 , V_1 -> V_38 ) ;
return V_41 ;
}
V_7 = F_40 ( V_1 , V_62 ) ;
if ( V_7 != V_8 )
{
return V_7 ;
}
V_7 = F_33 ( V_1 , V_3 , V_68 , V_36 ) ;
break;
default:
F_6 ( V_1 -> V_14 , L_26 ,
V_50 , V_49 , V_1 -> V_38 ) ;
return V_41 ;
}
return V_7 ;
}
T_1 F_40 ( T_2 * V_1 , enum V_71 V_72 )
{
T_1 V_7 ;
switch ( V_72 )
{
case V_60 :
case V_58 :
case V_73 :
break;
default:
return V_41 ;
}
if ( V_1 -> V_74 != ( T_4 ) V_72 )
{
V_7 = F_25 ( V_1 ,
F_44 ( V_1 -> V_38 ) * 2 ,
( T_5 ) V_72 ) ;
if ( V_7 == V_17 )
{
return V_7 ;
}
if ( V_7 != V_8 )
{
F_6 ( V_1 -> V_14 , L_27 ) ;
return V_7 ;
}
V_1 -> V_74 = ( T_4 ) V_72 ;
}
return V_8 ;
}
T_1 F_45 ( T_2 * V_1 , T_4 V_75 , T_5 * V_4 )
{
T_4 V_76 ;
T_1 V_7 ;
#ifdef F_5
T_7 V_24 ;
#endif
V_7 = F_35 ( V_1 , V_75 , & V_76 ) ;
if ( V_7 != V_8 )
{
return V_7 ;
}
#if F_2 ( V_12 ) && F_2 ( F_9 )
V_1 -> V_18 . V_77 ++ ;
#endif
#ifdef F_5
V_7 = F_16 ( V_1 , V_1 -> V_25 , V_76 , & V_24 ) ;
* V_4 = ( T_5 ) ( V_24 & 0xFF ) ;
return V_7 ;
#else
return F_1 ( V_1 , V_1 -> V_25 , V_76 , V_4 ) ;
#endif
}
T_1 F_46 ( T_2 * V_1 , T_4 V_75 , T_5 V_21 )
{
T_4 V_76 ;
T_1 V_7 ;
#ifdef F_5
T_7 V_24 ;
#endif
V_7 = F_35 ( V_1 , V_75 , & V_76 ) ;
if ( V_7 != V_8 )
{
return V_7 ;
}
if ( V_76 & 1 )
{
F_11 ( V_1 -> V_14 ,
L_17 ,
V_76 ) ;
}
#if F_2 ( V_12 ) && F_2 ( F_9 )
V_1 -> V_18 . V_78 ++ ;
#endif
#ifdef F_5
V_24 = V_21 ;
return F_18 ( V_1 , V_1 -> V_25 , V_76 , V_24 ) ;
#else
return F_12 ( V_1 , V_1 -> V_25 , V_76 , V_21 ) ;
#endif
}
T_1 F_47 ( T_2 * V_1 , T_4 V_75 , T_7 * V_4 )
{
T_4 V_76 ;
T_1 V_7 ;
V_7 = F_35 ( V_1 , V_75 , & V_76 ) ;
if ( V_7 != V_8 )
{
return V_7 ;
}
#if F_2 ( V_12 ) && F_2 ( F_9 )
V_1 -> V_18 . V_79 ++ ;
#endif
return F_24 ( V_1 , V_76 , V_4 ) ;
}
T_1 F_48 ( T_2 * V_1 , T_4 V_75 , T_7 V_21 )
{
T_4 V_76 ;
T_1 V_7 ;
V_7 = F_35 ( V_1 , V_75 , & V_76 ) ;
if ( V_7 != V_8 )
{
return V_7 ;
}
#if F_2 ( V_12 ) && F_2 ( F_9 )
V_1 -> V_18 . V_80 ++ ;
#endif
return F_25 ( V_1 , V_76 , V_21 ) ;
}
T_1 F_49 ( T_2 * V_1 , T_4 V_75 , T_4 * V_4 )
{
T_4 V_76 ;
T_1 V_7 ;
V_7 = F_35 ( V_1 , V_75 , & V_76 ) ;
if ( V_7 != V_8 )
{
return V_7 ;
}
#if F_2 ( V_12 ) && F_2 ( F_9 )
V_1 -> V_18 . V_81 ++ ;
#endif
return F_26 ( V_1 , V_76 , V_4 ) ;
}
T_1 F_50 ( T_2 * V_1 , T_4 V_75 , void * V_4 , T_7 V_28 , T_8 V_82 )
{
T_4 V_76 ;
T_1 V_7 ;
T_4 V_30 ;
V_7 = F_35 ( V_1 , V_75 , & V_76 ) ;
if ( V_7 != V_8 )
{
return V_7 ;
}
V_7 = F_27 ( V_1 , V_76 , V_4 , V_28 , V_82 , & V_30 ) ;
return V_7 ;
}
T_1 F_51 ( T_2 * V_1 , T_4 V_75 , void * V_4 , T_7 V_28 )
{
return F_50 ( V_1 , V_75 , V_4 , V_28 , - 1 ) ;
}
T_1 F_52 ( T_2 * V_1 , T_4 V_75 , void * V_4 , T_7 V_28 )
{
return F_50 ( V_1 , V_75 , V_4 , V_28 , 0 ) ;
}
V_33 F_53 ( T_2 * V_1 , T_4 V_3 )
{
T_5 V_83 ;
#define F_54 10
V_33 V_31 ;
for ( V_31 = 0 ; V_31 < F_54 ; V_31 ++ )
{
T_1 V_7 ;
V_7 = F_45 ( V_1 , V_3 , & V_83 ) ;
if ( V_7 != V_8 )
{
return - 1 ;
}
if ( ! ( V_83 & 0x80 ) )
{
return ( V_33 ) ( V_83 & 0xff ) ;
}
}
return - 1 ;
}
T_1 F_55 ( T_2 * V_1 , T_4 V_75 , void * V_4 , T_7 V_28 )
{
T_4 V_76 ;
T_1 V_7 ;
V_7 = F_35 ( V_1 , V_75 , & V_76 ) ;
if ( V_7 != V_8 )
{
return V_7 ;
}
return F_29 ( V_1 , V_76 , V_4 , V_28 ) ;
}
static T_1 F_56 ( T_2 * V_1 , T_3 V_2 ,
T_4 V_3 , T_5 * V_4 ,
T_7 V_84 , T_3 V_85 )
{
T_1 V_10 ;
if ( V_85 == V_86 )
{
#if F_2 ( V_12 ) && F_2 ( V_13 )
F_3 ( L_28 , V_3 , V_84 ) ;
#endif
#if F_2 ( V_12 ) && F_2 ( F_9 )
F_3 ( L_29 ) ;
#endif
V_10 = F_57 ( V_1 -> V_6 , V_3 , V_4 , V_84 ) ;
#if F_2 ( V_12 ) && F_2 ( F_9 )
F_3 ( L_30 ) ;
#endif
}
else
{
#if F_2 ( V_12 ) && F_2 ( V_13 )
F_3 ( L_31 , V_3 , V_84 ) ;
F_58 ( V_4 , V_84 > V_87 ? V_87 : V_84 ) ;
#endif
#if F_2 ( V_12 ) && F_2 ( F_9 )
F_3 ( L_32 ) ;
#endif
V_10 = F_59 ( V_1 -> V_6 , V_3 , V_4 , V_84 ) ;
#if F_2 ( V_12 ) && F_2 ( F_9 )
F_3 ( L_33 ) ;
#endif
}
#ifdef F_9
V_1 -> V_18 . V_88 ++ ;
#endif
#if F_2 ( V_12 ) && F_2 ( V_13 )
if ( V_10 != V_8 )
{
F_3 ( L_34 , V_10 ) ;
}
else if ( V_85 == V_86 )
{
F_58 ( V_4 , V_84 > V_87 ? V_87 : V_84 ) ;
}
F_15 ( L_13 ) ;
#endif
return V_10 ;
}
T_1 F_60 ( T_2 * V_1 , T_4 V_89 , void * V_4 ,
T_4 V_28 , T_3 V_90 )
{
#define F_61 3
#define F_62 15
#define F_63 5
#define F_64 1
T_1 V_10 ;
T_1 V_7 = V_8 ;
T_3 V_9 = F_61 ;
T_3 V_91 ;
T_5 V_92 ;
T_3 V_93 ;
#ifdef F_65
T_5 * V_94 = ( ( T_5 * ) & V_4 ) + V_1 -> V_95 ;
#endif
#ifdef F_66
static T_3 V_96 ;
#endif
V_93 = 0 ;
#ifdef F_65
if ( * V_94 & 1 )
{
F_67 ( V_1 -> V_14 , L_35 ,
V_4 , ( V_90 == V_86 ) ? L_36 : L_37 ) ;
if ( V_90 == V_97 )
{
F_68 ( V_4 , ( T_7 ) V_28 ) ;
}
else
{
V_93 = 1 ;
}
}
#endif
if ( ! V_4 )
{
F_6 ( V_1 -> V_14 , L_38 , V_28 ) ;
return V_41 ;
}
if ( ( V_28 & 1 ) || ( V_28 > 0xffff ) )
{
F_6 ( V_1 -> V_14 , L_39 , V_28 ) ;
return V_41 ;
}
while ( 1 )
{
V_10 = F_56 ( V_1 , V_1 -> V_25 , V_89 ,
( T_5 * ) V_4 , ( T_7 ) V_28 ,
V_90 ) ;
if ( V_10 == V_16 )
{
return V_17 ;
}
#ifdef F_66
if ( ++ V_96 > 100 )
{
V_96 = 90 ;
F_11 ( V_1 -> V_14 , L_40 ) ;
if ( V_10 == V_8 )
{
V_10 = V_15 ;
}
}
#endif
if ( V_10 == V_8 )
{
if ( V_93 )
{
F_68 ( V_4 , ( T_7 ) V_28 ) ;
}
break;
}
if ( V_1 -> V_98 <= V_99 )
{
( void ) F_69 ( V_1 , V_100 ) ;
}
if ( ! F_8 ( V_10 ) )
{
F_6 ( V_1 -> V_14 , L_41 ) ;
break;
}
if ( -- V_9 == 0 )
{
break;
}
F_10 ( V_1 -> V_14 , V_101 ,
L_42 ,
( T_3 ) V_89 & 0xff , V_28 ) ;
V_7 = F_46 ( V_1 , V_1 -> V_102 + 8 ,
( T_5 ) ( V_89 & 0xff ) ) ;
if ( V_7 == V_17 )
{
return V_7 ;
}
if ( V_7 != V_8 )
{
F_6 ( V_1 -> V_14 , L_43 ) ;
return V_7 ;
}
V_7 = F_70 ( V_1 ) ;
if ( V_7 != V_8 )
{
return V_7 ;
}
V_91 = F_62 ;
while ( 1 )
{
V_7 = F_45 ( V_1 , V_1 -> V_102 + 8 , & V_92 ) ;
if ( V_7 == V_17 )
{
return V_7 ;
}
if ( V_7 != V_8 )
{
F_6 ( V_1 -> V_14 , L_44 ) ;
return V_15 ;
}
if ( V_92 == 0 )
{
break;
}
if ( -- V_91 == 0 )
{
F_6 ( V_1 -> V_14 , L_45 ) ;
return V_15 ;
}
if ( V_91 < F_62 - F_63 )
{
F_71 ( F_64 ) ;
}
}
}
if ( V_10 != V_8 )
{
F_6 ( V_1 -> V_14 , L_46 ,
( V_90 == V_86 ) ? L_47 : L_48 ,
F_61 - V_9 ) ;
return V_15 ;
}
if ( V_90 == V_86 )
{
V_1 -> V_103 += V_28 ;
}
else
{
V_1 -> V_104 += V_28 ;
}
return V_8 ;
}
T_1 F_72 ( T_2 * V_1 , T_4 V_89 , void * V_4 ,
T_4 V_28 , T_3 V_90 )
{
T_1 V_10 ;
V_10 = F_56 ( V_1 , V_1 -> V_25 , V_89 ,
( T_5 * ) V_4 , ( T_7 ) V_28 , V_90 ) ;
if ( V_10 != V_8 )
{
F_6 ( V_1 -> V_14 , L_49 ,
( V_90 == V_86 ) ? L_47 : L_48 ) ;
return V_10 ;
}
return V_8 ;
}
