int F_1 ( struct V_1 * V_2 ,
void * V_3 )
{
#ifdef F_2
T_1 * V_4 ;
struct V_5 * V_6 =
V_7 -> V_8 . V_9 ;
V_4 = ( T_1 * ) ( V_3 ) ;
F_3 ( V_10 , L_1 , V_11 ,
( T_1 ) * ( V_4 + 1 ) ) ;
if ( V_6 -> V_12 )
(* V_6 -> V_12 ) ( ( T_1 ) * ( V_4 + 1 ) ) ;
#endif
return 0 ;
}
int F_4 ( struct V_1 * V_2 )
{
int V_13 = 0 ;
#ifdef F_5
T_2 V_14 = V_15 / 10 ;
T_1 V_16 ;
#ifdef F_2
T_1 V_17 ;
struct V_18 * V_19 ;
#endif
struct V_5 * V_6 =
V_7 -> V_8 . V_9 ;
V_16 = (* V_6 -> V_20 )( V_21 , V_22 ) &
V_23 ;
while ( ( V_16 != V_24 ) && -- V_14 ) {
if ( F_6 ( 10 ) ) {
F_7 ( L_2 ) ;
return - V_25 ;
}
V_16 = (* V_6 -> V_20 )( V_21 ,
V_22 ) &
V_23 ;
}
if ( V_14 == 0 ) {
F_7 ( L_3 , V_11 ) ;
V_13 = - V_26 ;
return V_13 ;
} else {
F_8 ( V_2 -> V_27 ) ;
V_13 = F_9 ( V_2 -> V_28 ) ;
F_10 ( false ) ;
if ( ! V_13 ) {
V_2 -> V_29 = V_30 ;
#ifdef F_2
V_13 =
F_11 ( V_2 -> V_31 , & V_19 ) ;
if ( ! V_19 ) {
V_13 = V_32 ;
return V_13 ;
}
F_12 ( V_19 , V_33 , & V_17 ) ;
if ( V_6 -> V_12 )
(* V_6 -> V_12 ) ( V_34 ) ;
V_13 = 0 ;
#endif
}
}
#endif
return V_13 ;
}
int F_13 ( struct V_1 * V_2 , T_1 V_35 ,
void * V_3 )
{
int V_13 = 0 ;
#ifdef F_5
#ifdef F_14
struct V_36 * V_37 ;
#endif
T_2 V_14 = V_15 / 10 ;
T_1 V_16 , V_38 ;
struct V_5 * V_6 =
V_7 -> V_8 . V_9 ;
if ( ( V_35 != V_39 ) && ( V_35 != V_40 ) )
return - V_41 ;
switch ( V_2 -> V_29 ) {
case V_42 :
F_8 ( V_2 -> V_27 ) ;
if ( V_43 == V_24 ) {
F_15 ( V_2 , V_44 ) ;
F_3 ( V_10 , L_4 ,
V_11 ) ;
V_38 = V_24 ;
} else {
F_15 ( V_2 , V_45 ) ;
V_38 = V_46 ;
}
break;
case V_47 :
F_8 ( V_2 -> V_27 ) ;
if ( V_43 == V_24 ) {
F_15 ( V_2 , V_44 ) ;
V_38 = V_24 ;
} else
return 0 ;
break;
case V_48 :
case V_30 :
F_3 ( V_10 , L_5 ,
V_11 ) ;
return 0 ;
case V_49 :
F_3 ( V_10 , L_6 , V_11 ) ;
return 0 ;
default:
F_3 ( V_10 , L_7 , V_11 ) ;
return - V_25 ;
}
V_16 = (* V_6 -> V_20 )( V_21 , V_22 ) &
V_23 ;
while ( ( V_16 != V_38 ) && -- V_14 ) {
if ( F_6 ( 10 ) ) {
F_7 ( L_8 ) ;
return - V_25 ;
}
V_16 = (* V_6 -> V_20 )( V_21 ,
V_22 ) &
V_23 ;
}
if ( ! V_14 ) {
F_7 ( L_9 ,
V_11 , V_16 ) ;
#ifdef F_14
F_16 ( V_2 -> V_31 , & V_37 ) ;
F_17 ( V_37 , V_50 , 0 ) ;
#endif
return - V_26 ;
} else {
if ( V_43 == V_24 )
V_2 -> V_29 = V_48 ;
else
V_2 -> V_29 = V_47 ;
F_10 ( false ) ;
V_13 = F_9 ( V_2 -> V_28 ) ;
if ( V_13 )
return V_13 ;
#ifdef F_2
else if ( V_38 == V_24 ) {
if ( V_6 -> V_12 )
(* V_6 -> V_12 ) ( V_34 ) ;
}
#endif
}
#endif
return V_13 ;
}
int F_18 ( struct V_1 * V_2 , void * V_3 )
{
int V_13 = 0 ;
#ifdef F_5
if ( V_2 -> V_29 == V_42 ||
V_2 -> V_29 == V_49 ) {
return 0 ;
}
F_15 ( V_2 , V_51 ) ;
V_2 -> V_29 = V_42 ;
#endif
return V_13 ;
}
int F_19 ( struct V_1 * V_2 ,
void * V_3 )
{
T_1 V_52 = 0 ;
T_1 V_53 = 0 ;
T_1 V_54 = 0 ;
T_1 V_55 = V_56 ;
T_1 V_57 ;
T_1 V_58 ;
int V_13 = 0 ;
V_58 = V_2 -> V_28 ;
V_52 = ( T_1 ) * ( ( T_1 * ) V_3 ) ;
V_53 = V_52 & V_59 ;
for ( V_57 = 0 ; V_57 < V_56 ; V_57 ++ ) {
if ( V_53 == V_60 [ V_57 ] ) {
V_55 = V_57 ;
break;
}
}
if ( V_55 == V_56 ) {
return - V_25 ;
}
V_54 = ( V_52 >> V_61 ) & V_62 ;
switch ( V_54 ) {
case V_63 :
V_13 = F_20 ( V_64 [ V_55 ] . V_65 ) ;
F_21 ( V_64 [ V_55 ] . V_66 ,
false ) ;
if ( ! V_13 ) {
( V_2 -> V_28 ) &=
( ~ ( ( T_1 ) ( 1 << V_64 [ V_55 ] . V_65 ) ) ) ;
}
break;
case V_67 :
V_13 = F_22 ( V_64 [ V_55 ] . V_65 ) ;
F_21 ( V_64 [ V_55 ] . V_66 , true ) ;
if ( ! V_13 )
( V_2 -> V_28 ) |=
( 1 << V_64 [ V_55 ] . V_65 ) ;
break;
default:
F_3 ( V_10 , L_10 , V_11 ) ;
}
return V_13 ;
}
int F_23 ( struct V_1 * V_2 , void * V_3 )
{
#ifdef F_2
T_1 V_68 ;
T_1 V_69 ;
V_69 = * ( ( T_1 * ) V_3 ) ;
V_68 = * ( ( T_1 * ) V_3 + 1 ) ;
F_3 ( V_10 , L_11 ,
V_11 , V_69 , V_68 ) ;
if ( ( V_2 -> V_29 == V_48 ) ||
( V_2 -> V_29 == V_47 ) ||
( V_2 -> V_29 == V_30 ) ) {
F_3 ( V_10 , L_12 ) ;
return 0 ;
} else if ( V_2 -> V_29 == V_42 ) {
F_3 ( V_10 , L_13 , V_11 ) ;
F_15 ( V_2 , V_70 ) ;
return 0 ;
} else {
return - V_25 ;
}
#endif
return 0 ;
}
int F_24 ( struct V_1 * V_2 ,
void * V_3 )
{
int V_13 = 0 ;
#ifdef F_2
T_1 V_68 ;
T_1 V_69 ;
struct V_18 * V_19 ;
V_13 = F_11 ( V_2 -> V_31 , & V_19 ) ;
if ( ! V_19 )
return - V_71 ;
V_69 = * ( ( T_1 * ) V_3 ) ;
V_68 = * ( ( T_1 * ) V_3 + 1 ) ;
F_3 ( V_10 , L_11 ,
V_11 , V_69 , V_68 ) ;
if ( ( V_2 -> V_29 == V_48 ) ||
( V_2 -> V_29 == V_47 ) ||
( V_2 -> V_29 == V_30 ) ) {
F_12 ( V_19 , V_72 , & V_68 ) ;
F_3 ( V_10 , L_14 ,
V_11 ) ;
} else if ( V_2 -> V_29 == V_42 ) {
F_12 ( V_19 , V_72 , & V_68 ) ;
F_15 ( V_2 , V_73 ) ;
F_3 ( V_10 ,
L_15 ,
V_11 ) ;
} else {
V_13 = - V_25 ;
}
#endif
return V_13 ;
}
void F_21 ( T_1 V_74 , bool V_75 )
{
struct V_76 * V_77 ;
int V_13 = 0 ;
T_1 V_78 ;
T_1 V_79 ;
struct V_80 * V_81 = NULL ;
struct V_1 * V_82 = NULL ;
V_81 = (struct V_80 * ) F_25 () ;
if ( ! V_81 )
return;
V_13 = F_26 ( V_81 , & V_82 ) ;
if ( ! V_82 )
return;
V_77 = V_82 -> V_77 ;
if ( ! V_77 )
return;
switch ( V_74 ) {
case V_83 :
V_78 = F_27 ( V_77 -> V_84 + 0xA8 ) ;
V_79 = F_27 ( V_77 -> V_84 + 0xA4 ) ;
if ( V_75 ) {
V_78 |= V_85 ;
V_79 &= ~ V_85 ;
} else {
V_79 |= V_85 ;
V_78 &= ~ V_85 ;
}
F_28 ( V_78 , V_77 -> V_84 + 0xA8 ) ;
F_28 ( V_79 , V_77 -> V_84 + 0xA4 ) ;
break;
case V_86 :
V_78 = F_27 ( V_77 -> V_84 + 0xA8 ) ;
V_79 = F_27 ( V_77 -> V_84 + 0xA4 ) ;
if ( V_75 ) {
V_78 |= V_87 ;
V_79 &= ~ V_87 ;
} else {
V_79 |= V_87 ;
V_78 &= ~ V_87 ;
}
F_28 ( V_78 , V_77 -> V_84 + 0xA8 ) ;
F_28 ( V_79 , V_77 -> V_84 + 0xA4 ) ;
break;
case V_88 :
V_78 = F_27 ( V_77 -> V_84 + 0xA8 ) ;
V_79 = F_27 ( V_77 -> V_84 + 0xA4 ) ;
if ( V_75 ) {
V_78 |= V_89 ;
V_79 &= ~ V_89 ;
} else {
V_79 |= V_89 ;
V_78 &= ~ V_89 ;
}
F_28 ( V_78 , V_77 -> V_84 + 0xA8 ) ;
F_28 ( V_79 , V_77 -> V_84 + 0xA4 ) ;
break;
case V_90 :
V_78 = F_27 ( V_77 -> V_84 + 0xA8 ) ;
V_79 = F_27 ( V_77 -> V_84 + 0xA4 ) ;
if ( V_75 ) {
V_78 |= V_91 ;
V_79 &= ~ V_91 ;
} else {
V_79 |= V_91 ;
V_78 &= ~ V_91 ;
}
F_28 ( V_78 , V_77 -> V_84 + 0xA8 ) ;
F_28 ( V_79 , V_77 -> V_84 + 0xA4 ) ;
break;
case V_92 :
V_78 = F_27 ( V_77 -> V_93 + 0xA8 ) ;
V_79 = F_27 ( V_77 -> V_93 + 0xA4 ) ;
if ( V_75 ) {
V_78 |= V_94 ;
V_79 &= ~ V_94 ;
} else {
V_79 |= V_94 ;
V_78 &= ~ V_94 ;
}
F_28 ( V_78 , V_77 -> V_93 + 0xA8 ) ;
F_28 ( V_79 , V_77 -> V_93 + 0xA4 ) ;
break;
case V_95 :
V_78 = F_27 ( V_77 -> V_84 + 0xA8 ) ;
V_79 = F_27 ( V_77 -> V_84 + 0xA4 ) ;
if ( V_75 ) {
V_78 |= V_96 ;
V_79 &= ~ V_96 ;
} else {
V_79 |= V_96 ;
V_78 &= ~ V_96 ;
}
F_28 ( V_78 , V_77 -> V_84 + 0xA8 ) ;
F_28 ( V_79 , V_77 -> V_84 + 0xA4 ) ;
break;
case V_97 :
V_78 = F_27 ( V_77 -> V_84 + 0xA8 ) ;
V_79 = F_27 ( V_77 -> V_84 + 0xA4 ) ;
if ( V_75 ) {
V_78 |= V_98 ;
V_79 &= ~ V_98 ;
} else {
V_79 |= V_98 ;
V_78 &= ~ V_98 ;
}
F_28 ( V_78 , V_77 -> V_84 + 0xA8 ) ;
F_28 ( V_79 , V_77 -> V_84 + 0xA4 ) ;
break;
case V_99 :
V_78 = F_27 ( V_77 -> V_84 + 0xA8 ) ;
V_79 = F_27 ( V_77 -> V_84 + 0xA4 ) ;
if ( V_75 ) {
V_78 |= V_100 ;
V_79 &= ~ V_100 ;
} else {
V_79 |= V_100 ;
V_78 &= ~ V_100 ;
}
F_28 ( V_78 , V_77 -> V_84 + 0xA8 ) ;
F_28 ( V_79 , V_77 -> V_84 + 0xA4 ) ;
break;
case V_101 :
V_78 = F_27 ( V_77 -> V_84 + 0xA8 ) ;
V_79 = F_27 ( V_77 -> V_84 + 0xA4 ) ;
if ( V_75 ) {
V_78 |= V_102 ;
V_79 &= ~ V_102 ;
} else {
V_79 |= V_102 ;
V_78 &= ~ V_102 ;
}
F_28 ( V_78 , V_77 -> V_84 + 0xA8 ) ;
F_28 ( V_79 , V_77 -> V_84 + 0xA4 ) ;
break;
}
}
