T_1 F_1 ( T_2 clock
) {
volatile T_3 * V_1 = ( T_3 * ) 0x0 ;
volatile T_3 * V_2 = ( T_3 * ) 0x0 ;
volatile T_3 * V_3 = ( T_3 * ) 0x0 ;
T_3 V_4 = 0 ;
T_3 V_5 = 0 ;
T_3 V_6 = 0 ;
T_3 V_7 = 0 ;
if ( ( V_8 -> V_9 & V_10 ) != V_11 ) {
T_4 V_12 = 0 ;
V_4 = V_13 *
F_2 ( V_14 , V_15 ) *
( ( V_8 -> V_9 & V_16 ) >>
V_17 ) ;
V_12 = ( T_4 ) V_13 *
( T_4 ) V_18 *
F_2 ( V_14 , ( V_15 * ( T_4 ) V_19 ) ) ;
V_4 += ( T_3 ) V_12 ;
} else {
V_4 = V_13 *
F_2 ( V_14 , V_15 ) *
( ( V_8 -> V_9 & V_16 ) >>
V_17 ) ;
}
V_5 =
V_13 *
F_2 ( V_14 , V_15 ) *
( ( V_8 -> V_20 & V_16 ) >>
V_17 ) ;
switch ( clock ) {
case V_21 :
V_1 = & V_8 -> V_22 ;
V_7 = V_4 ;
break;
case V_23 :
V_1 = & V_8 -> V_24 ;
V_7 = V_4 ;
break;
case V_25 :
V_1 = & V_8 -> V_26 ;
V_7 = V_4 ;
break;
case V_27 :
V_1 = & V_8 -> V_28 ;
V_7 = V_4 ;
break;
case V_29 :
V_1 = & V_8 -> V_30 ;
V_7 = V_4 ;
break;
case V_31 :
V_1 = & V_8 -> V_32 ;
V_7 = V_4 ;
break;
case V_33 :
V_1 = & V_8 -> V_34 ;
V_7 = V_4 ;
break;
case V_35 :
V_1 = & V_8 -> V_36 ;
V_7 = V_4 ;
break;
case V_37 :
V_1 = & V_8 -> V_38 ;
V_7 = V_4 ;
break;
case V_39 :
V_1 = & V_8 -> V_40 ;
V_7 = V_4 ;
break;
case V_41 :
V_1 = & V_8 -> V_42 ;
V_7 = V_5 ;
break;
case V_43 :
V_1 = & V_8 -> V_44 ;
V_7 = V_5 ;
break;
case V_45 :
V_1 = & V_8 -> V_46 ;
V_7 = V_5 ;
break;
case V_47 :
V_2 = & V_8 -> V_48 ;
V_3 = & V_8 -> V_24 ;
V_7 = V_4 ;
V_6 = V_49 ;
break;
case V_50 :
V_2 = & V_8 -> V_51 ;
break;
case V_52 :
V_2 = & V_8 -> V_53 ;
break;
case V_54 :
V_2 = & V_8 -> V_55 ;
break;
case V_56 :
V_2 = & V_8 -> V_57 ;
V_3 = & V_8 -> V_48 ;
V_6 = V_58 ;
break;
case V_59 :
V_2 = & V_8 -> V_60 ;
V_3 = & V_8 -> V_46 ;
V_7 = V_5 ;
V_6 = V_49 ;
break;
case V_61 :
V_2 = & V_8 -> V_62 ;
break;
case V_63 :
V_2 = & V_8 -> V_64 ;
break;
case V_65 :
V_2 = & V_8 -> V_66 ;
break;
}
if ( V_1 ) {
if ( * V_1 & V_67 ) {
return V_13 ;
} else if ( clock == V_21 ) {
return F_2 ( V_7 , ( ( ( V_8 -> V_68 & 0xFF000000 ) >> 24 ) ? ( ( V_8 -> V_68 & 0xFF000000 ) >> 24 ) : 256 ) ) ;
} else {
if ( ( V_1 == & V_8 -> V_44 ) && ( F_3 () != V_69 ) ) {
V_7 >>= 1 ;
}
return F_2 ( V_7 , ( ( * V_1 & V_70 ) ? ( * V_1 & V_70 ) : 256 ) ) ;
}
} else if ( V_2 ) {
T_3 div ;
T_3 V_71 = 0 ;
if ( * V_2 & V_72 ) {
return V_13 ;
} else if ( V_3 ) {
switch ( V_6 ) {
case V_49 :
if ( * V_3 & V_67 ) {
V_71 = V_13 ;
} else {
div = * V_3 & V_70 ;
V_71 = div ? F_2 ( V_7 , div ) : 0 ;
}
break;
case V_58 :
if ( V_3 == ( T_3 * ) & V_8 -> V_48 ) {
V_71 = F_1 ( V_47 ) ;
} else {
if ( * V_3 & V_72 ) {
V_71 = V_13 ;
} else {
div = * V_3 & V_73 ;
V_71 = F_2 ( V_13 , ( div ? div : 256 ) ) ;
}
}
break;
}
} else {
V_71 = V_13 ;
}
div = * V_2 & V_73 ;
return F_2 ( V_71 , ( div ? div : 256 ) ) ;
}
return 0 ;
}
T_1 F_4 ( T_2 clock ,
T_3 V_71
) {
volatile T_3 * V_1 = ( T_3 * ) 0x0 ;
volatile T_3 * V_2 = ( T_3 * ) 0x0 ;
volatile T_3 * V_3 = ( T_3 * ) 0x0 ;
T_3 V_4 = 0 ;
T_3 V_74 = 0 ;
T_3 V_5 = 0 ;
T_3 V_6 = 0 ;
T_3 V_7 = 0 ;
T_3 V_75 = 0 ;
if ( ( V_8 -> V_9 & V_10 ) != V_11 ) {
T_4 V_12 = 0 ;
V_4 = V_13 *
F_2 ( V_14 , V_15 ) *
( ( V_8 -> V_9 & V_16 ) >>
V_17 ) ;
V_12 = ( T_4 ) V_13 *
( T_4 ) V_18 *
F_2 ( V_14 , ( V_15 * ( T_4 ) V_19 ) ) ;
V_4 += ( T_3 ) V_12 ;
V_74 = V_13 *
F_2 ( V_14 , V_15 ) *
( ( ( V_8 -> V_9 & V_16 ) >>
V_17 ) + 1 ) ;
} else {
V_4 = V_74 = V_13 *
F_2 ( V_14 , V_15 ) *
( ( V_8 -> V_9 & V_16 ) >>
V_17 ) ;
}
V_5 = V_13 * F_2 ( V_14 , V_15 ) *
( ( V_8 -> V_20 & V_16 ) >>
V_17 ) ;
switch ( clock ) {
case V_21 :
{
V_76 ;
V_8 -> V_22 = ( V_8 -> V_22 & ~ V_77 ) | ( ( ( ( V_71 / 2 ) / F_1 ( V_47 ) ) - 1 )
<< V_78 ) ;
V_79 ;
}
V_1 = & V_8 -> V_22 ;
V_7 = V_4 ;
V_75 = V_74 ;
break;
case V_23 :
V_1 = & V_8 -> V_24 ;
V_7 = V_4 ;
V_75 = V_74 ;
break;
case V_25 :
V_1 = & V_8 -> V_26 ;
V_7 = V_4 ;
V_75 = V_74 ;
break;
case V_27 :
{
V_76 ;
V_8 -> V_28 = ( V_8 -> V_28 & ~ V_77 ) | ( ( F_2 ( V_71 , F_1 ( V_47 ) ) - 1 )
<< V_78 ) ;
V_79 ;
}
V_1 = & V_8 -> V_28 ;
V_7 = V_4 ;
V_75 = V_74 ;
break;
case V_29 :
V_1 = & V_8 -> V_30 ;
V_7 = V_4 ;
V_75 = V_74 ;
break;
case V_31 :
V_1 = & V_8 -> V_32 ;
V_7 = V_4 ;
V_75 = V_74 ;
break;
case V_33 :
V_1 = & V_8 -> V_34 ;
V_7 = V_4 ;
V_75 = V_74 ;
break;
case V_35 :
V_1 = & V_8 -> V_36 ;
V_7 = V_4 ;
V_75 = V_74 ;
break;
case V_37 :
V_1 = & V_8 -> V_38 ;
V_7 = V_4 ;
V_75 = V_74 ;
break;
case V_39 :
V_1 = & V_8 -> V_40 ;
V_7 = V_4 ;
V_75 = V_74 ;
break;
case V_41 :
V_1 = & V_8 -> V_42 ;
V_7 = V_5 ;
V_75 = V_5 ;
break;
case V_43 :
V_1 = & V_8 -> V_44 ;
V_7 = V_5 ;
V_75 = V_5 ;
break;
case V_45 :
V_1 = & V_8 -> V_46 ;
V_7 = V_5 ;
V_75 = V_5 ;
break;
case V_47 :
V_2 = & V_8 -> V_48 ;
V_3 = & V_8 -> V_24 ;
V_7 = V_4 ;
V_75 = V_74 ;
V_6 = V_49 ;
break;
case V_50 :
V_2 = & V_8 -> V_51 ;
break;
case V_52 :
V_2 = & V_8 -> V_53 ;
break;
case V_54 :
V_2 = & V_8 -> V_55 ;
break;
case V_56 :
V_2 = & V_8 -> V_57 ;
V_3 = & V_8 -> V_48 ;
V_6 = V_58 ;
break;
case V_59 :
V_2 = & V_8 -> V_60 ;
V_3 = & V_8 -> V_46 ;
V_7 = V_5 ;
V_75 = V_5 ;
V_6 = V_49 ;
break;
case V_61 :
V_2 = & V_8 -> V_62 ;
break;
case V_63 :
V_2 = & V_8 -> V_64 ;
break;
case V_65 :
V_2 = & V_8 -> V_66 ;
break;
}
if ( V_1 ) {
F_5 ( V_1 , ~ V_80 ) ;
F_6 ( V_1 , V_67 ) ;
if ( V_1 == & V_8 -> V_22 ) {
F_7 ( & V_8 -> V_68 , ( V_8 -> V_68 & 0x00FFFFFF ) | ( ( F_8 ( V_75 , V_71 ) ) << 24 ) ) ;
V_71 = F_2 ( V_7 , ( ( ( V_8 -> V_68 & 0xFF000000 ) >> 24 ) ? ( ( V_8 -> V_68 & 0xFF000000 ) >> 24 ) : 256 ) ) ;
} else {
if ( ( V_1 == & V_8 -> V_44 ) && ( F_3 () != V_69 ) ) {
V_75 >>= 1 ;
V_7 >>= 1 ;
}
F_5 ( V_1 , ~ ( V_70 ) ) ;
F_6 ( V_1 , F_8 ( V_75 , V_71 ) ) ;
V_71 = F_2 ( V_7 , ( ( * ( V_1 ) & V_70 ) ? ( * ( V_1 ) & V_70 ) : 256 ) ) ;
}
F_9 ( 1 ) ;
F_5 ( V_1 , ~ V_67 ) ;
return V_71 ;
} else if ( V_2 ) {
T_3 V_81 = 0 ;
F_5 ( V_2 ,
~ V_72 ) ;
if ( V_3 ) {
switch ( V_6 ) {
case V_49 :
V_81 = F_2 ( F_2 ( V_75 , ( * V_3 & V_70 ) ) , V_71 ) ;
break;
case V_58 :
{
T_3 V_82 = 0 ;
if ( V_3 == ( T_3 * ) & V_8 -> V_48 ) {
V_82 = F_1 ( V_47 ) ;
} else {
T_3 div = * V_3 & V_73 ;
V_82 = F_2 ( V_13 , ( ( div ) ? div : 256 ) ) ;
}
V_81 = F_2 ( V_82 , V_71 ) ;
}
break;
}
} else {
V_81 = F_2 ( V_13 , V_71 ) ;
}
if ( V_81 ) {
V_76 ;
* V_2 = ( * V_2 & ( ~ V_73 ) ) | ( ( ( V_81 > 256 ) ? V_83 : V_81 ) & V_73 ) ;
V_79 ;
return V_71 ;
}
}
return 0 ;
}
static int F_10 ( void )
{
T_3 V_84 ;
T_3 V_85 ;
T_3 V_86 ;
int V_87 = 0 ;
int V_88 = 0 ;
int V_89 = 0 ;
for ( V_87 = 0 ; ( V_87 < V_90 ) && ( V_88 < V_91 ) ; V_87 ++ ) {
V_84 = ( V_8 -> V_28 & V_92 ) >> V_93 ;
V_85 = 0 ;
V_86 = 0 ;
V_85 = V_8 -> V_28 ;
do {
V_86 = V_85 & V_94 ;
F_7 ( & V_8 -> V_28 , ( V_8 -> V_28 & ( ~ V_92 ) ) | ( V_84 << V_93 ) ) ;
F_9 ( 1 ) ;
V_8 -> V_28 ^= V_95 ;
V_85 = V_8 -> V_28 ;
if ( ( V_85 & V_94 ) == 0x0 ) {
V_84 = ( 0x3F & ( V_84 - 1 ) ) ;
} else {
V_84 = ( 0x3F & ( V_84 + 1 ) ) ;
}
V_88 ++ ;
} while ( ( ( V_86 == ( V_85 & V_94 ) ) ||
( ( V_85 & V_94 ) != 0x0 ) ) &&
( V_88 < V_91 )
);
if ( V_88 >= V_91 ) {
return - 1 ;
}
for ( V_89 = 0 ; ( V_89 < 5 ) && ( ( V_85 & V_94 ) == 0 ) ; V_89 ++ ) {
V_84 = ( 0x3F & ( V_84 + 1 ) ) ;
F_7 ( & V_8 -> V_28 , ( V_8 -> V_28 & ( ~ V_92 ) ) | ( V_84 << V_93 ) ) ;
F_9 ( 1 ) ;
V_8 -> V_28 ^= V_95 ;
V_85 = V_8 -> V_28 ;
V_88 ++ ;
}
if ( V_88 >= V_91 ) {
return - 1 ;
}
if ( V_89 != 5 ) {
continue;
}
for ( V_89 = 0 ; ( V_89 < 3 ) && ( ( V_85 & V_94 ) == 0 ) ; V_89 ++ ) {
V_84 = ( 0x3F & ( V_84 - 1 ) ) ;
F_7 ( & V_8 -> V_28 , ( V_8 -> V_28 & ( ~ V_92 ) ) | ( V_84 << V_93 ) ) ;
F_9 ( 1 ) ;
V_8 -> V_28 ^= V_95 ;
V_85 = V_8 -> V_28 ;
V_88 ++ ;
}
if ( V_88 >= V_91 ) {
return - 1 ;
}
if ( V_89 != 3 ) {
continue;
}
for ( V_89 = 0 ; ( V_89 < 5 ) ; V_89 ++ ) {
V_84 = ( 0x3F & ( V_84 - 1 ) ) ;
F_7 ( & V_8 -> V_28 , ( V_8 -> V_28 & ( ~ V_92 ) ) | ( V_84 << V_93 ) ) ;
F_9 ( 1 ) ;
V_8 -> V_28 ^= V_95 ;
V_85 = V_8 -> V_28 ;
V_88 ++ ;
}
if ( V_88 >= V_91 ) {
return - 1 ;
}
if ( ( V_85 & V_94 ) == 0 ) {
continue;
}
do {
V_86 = V_85 ;
F_7 ( & V_8 -> V_28 , ( V_8 -> V_28 & ( ~ V_92 ) ) | ( V_84 << V_93 ) ) ;
F_9 ( 1 ) ;
V_8 -> V_28 ^=
V_95 ;
V_85 = V_8 -> V_28 ;
if ( ( V_85 & V_94 ) == 0x0 ) {
V_84 = ( 0x3F & ( V_84 - 1 ) ) ;
} else {
V_84 = ( 0x3F & ( V_84 + 1 ) ) ;
}
V_88 ++ ;
} while ( ( ( V_86 == ( V_85 & V_94 ) ) || ( ( V_85 & V_94 ) != 0x0 ) ) && ( V_88 < V_91 ) );
if ( V_88 >= V_91 ) {
return - 1 ;
} else {
break;
}
}
V_84 = ( ( ( V_8 -> V_28 >> V_93 ) - 1 ) & 0x3F ) ;
{
V_76 ;
V_8 -> V_28 = ( V_8 -> V_28 & ~ V_92 ) | ( V_84 << V_93 ) ;
V_8 -> V_28 ^= V_95 ;
V_79 ;
}
return ( int ) V_88 ;
}
int F_11 ( void )
{
if ( F_3 () == V_69 ) {
return F_10 () ;
} else {
T_3 V_84 = F_12 () ;
T_3 V_85 = 0 ;
int V_88 = 0 ;
V_8 -> V_96 &= ~ V_97 ;
F_13 () ;
F_14 () ;
while ( V_88 < V_91 ) {
V_85 = F_15 () ;
if ( V_85 > 0xF ) {
V_84 ++ ;
} else if ( V_85 < 0xF ) {
V_84 -- ;
} else {
V_8 -> V_96 |= V_97 ;
return V_88 ;
}
F_7 ( & V_8 -> V_28 , ( V_8 -> V_28 & ( ~ V_92 ) ) | ( V_84 << V_93 ) ) ;
F_9 ( 1 ) ;
V_8 -> V_28 ^= V_95 ;
V_88 ++ ;
}
}
V_8 -> V_96 &= ~ V_97 ;
return - 1 ;
}
static int F_2 ( int V_98 , int V_99 )
{
int V_100 ;
int V_101 = 1 ;
while ( ( V_99 & 0x40000000 ) == 0 ) {
V_99 = V_99 << 1 ;
V_101 = V_101 << 1 ;
}
V_100 = 0 ;
do {
if ( ( V_98 - V_99 ) >= 0 ) {
V_98 = V_98 - V_99 ;
V_100 = V_100 + V_101 ;
}
V_99 = V_99 >> 1 ;
V_101 = V_101 >> 1 ;
} while ( V_101 != 0 );
return V_100 ;
}
