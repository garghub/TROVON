int F_1 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_4 )
{
T_2 V_5 ;
if ( V_3 & 3 )
return - V_6 ;
if ( ( V_3 + 3 ) > V_4 )
return - V_6 ;
V_5 = V_3 ;
V_5 |= V_7 ;
F_2 ( V_8 , V_5 ) ;
return 0 ;
}
int F_3 ( struct V_1 * V_2 ,
T_1 V_9 , const T_3 * V_10 ,
T_1 V_11 , T_1 V_4 )
{
T_2 V_12 , V_13 , V_14 ;
T_1 V_5 ;
int V_15 ;
if ( V_9 & 3 )
return - V_6 ;
if ( ( V_9 + V_11 ) > V_4 )
return - V_6 ;
V_5 = V_9 ;
while ( V_11 >= 4 ) {
V_12 = ( V_10 [ 0 ] << 24 ) | ( V_10 [ 1 ] << 16 ) | ( V_10 [ 2 ] << 8 ) | V_10 [ 3 ] ;
V_15 = F_1 ( V_2 , V_5 , V_4 ) ;
if ( V_15 )
return V_15 ;
F_2 ( V_16 , V_12 ) ;
V_10 += 4 ;
V_11 -= 4 ;
V_5 += 4 ;
}
if ( V_11 > 0 ) {
V_12 = 0 ;
V_15 = F_1 ( V_2 , V_5 , V_4 ) ;
if ( V_15 )
return V_15 ;
V_13 = F_4 ( V_16 ) ;
V_14 = 8 * ( 4 - V_11 ) ;
while ( V_11 > 0 ) {
V_12 = ( V_12 << 8 ) + * V_10 ++ ;
V_11 -- ;
}
V_12 <<= V_14 ;
V_12 |= ( V_13 & ~ ( ( ~ 0UL ) << V_14 ) ) ;
V_15 = F_1 ( V_2 , V_5 , V_4 ) ;
if ( V_15 )
return V_15 ;
F_2 ( V_16 , V_12 ) ;
}
return 0 ;
}
static int F_5 ( struct V_1 * V_2 ,
T_2 V_17 , const T_3 * V_10 ,
T_2 V_11 )
{
T_2 V_18 , V_19 ;
if ( V_11 % 4 )
return - V_6 ;
if ( V_17 < V_20 ) {
V_18 = V_20 - V_17 ;
if ( V_18 > V_11 )
return 0 ;
V_11 -= V_18 ;
V_10 += V_18 ;
V_17 = V_20 ;
}
for ( V_19 = 0 ; V_19 < V_11 ; V_19 += 4 ) {
V_18 = ( V_10 [ V_19 ] << 24 ) | ( V_10 [ V_19 + 1 ] << 16 ) | ( V_10 [ V_19 + 2 ] << 8 ) | V_10 [ V_19 + 3 ] ;
F_2 ( V_21 + V_19 , V_18 ) ;
}
return 0 ;
}
void F_6 ( struct V_1 * V_2 )
{
F_7 ( V_22 , V_23 , ~ V_23 ) ;
}
void F_8 ( struct V_1 * V_2 )
{
F_7 ( V_22 , 0 , ~ V_23 ) ;
}
void F_9 ( struct V_1 * V_2 )
{
F_7 ( V_22 , 0 , ~ V_24 ) ;
}
void F_10 ( struct V_1 * V_2 )
{
F_7 ( V_22 , V_24 , ~ V_24 ) ;
}
bool F_11 ( struct V_1 * V_2 )
{
T_2 V_18 ;
V_18 = F_4 ( V_22 ) ;
if ( ( V_18 & V_23 ) && ( V_18 & V_24 ) )
return true ;
else
return false ;
}
T_4 F_12 ( struct V_1 * V_2 , T_5 V_25 )
{
T_2 V_18 ;
int V_19 ;
T_4 V_26 ;
if ( ! F_11 ( V_2 ) )
return V_27 ;
F_7 ( V_28 , F_13 ( V_25 ) , ~ V_29 ) ;
for ( V_19 = 0 ; V_19 < V_2 -> V_30 ; V_19 ++ ) {
V_18 = F_4 ( V_28 ) & V_31 ;
V_18 >>= V_32 ;
if ( V_18 != 0 )
break;
F_14 ( 1 ) ;
}
V_18 = F_4 ( V_28 ) & V_31 ;
V_18 >>= V_32 ;
V_26 = ( T_4 ) V_18 ;
return V_26 ;
}
T_4 F_15 ( struct V_1 * V_2 )
{
int V_19 ;
T_4 V_26 = V_33 ;
if ( ! F_11 ( V_2 ) )
return V_26 ;
for ( V_19 = 0 ; V_19 < V_2 -> V_30 ; V_19 ++ ) {
if ( F_4 ( V_22 ) & V_34 )
break;
F_14 ( 1 ) ;
}
return V_26 ;
}
static void F_16 ( struct V_1 * V_2 , T_1 V_4 )
{
T_1 V_19 ;
for ( V_19 = 0 ; V_19 < V_4 ; V_19 += 4 ) {
F_1 ( V_2 , V_19 , V_4 ) ;
F_2 ( V_16 , 0 ) ;
}
}
int F_17 ( struct V_1 * V_2 ,
T_1 V_4 )
{
int V_15 ;
const T_3 * V_35 ;
T_1 V_36 ;
T_1 V_37 ;
const T_3 * V_38 ;
T_1 V_39 ;
T_1 V_40 ;
if ( ! V_2 -> V_41 )
return - V_6 ;
F_16 ( V_2 , V_4 ) ;
switch ( V_2 -> V_42 ) {
case V_43 :
V_39 = V_44 ;
V_40 = V_45 ;
V_35 = ( const T_3 * ) & V_46 ;
V_36 = V_47 ;
V_37 = V_48 ;
break;
case V_49 :
V_39 = V_50 ;
V_40 = V_51 ;
V_35 = ( const T_3 * ) & V_52 ;
V_36 = V_53 ;
V_37 = V_54 ;
break;
case V_55 :
V_39 = V_56 ;
V_40 = V_57 ;
V_35 = ( const T_3 * ) & V_58 ;
V_36 = V_59 ;
V_37 = V_60 ;
break;
case V_61 :
V_39 = V_62 ;
V_40 = V_63 ;
V_35 = ( const T_3 * ) & V_64 ;
V_36 = V_65 ;
V_37 = V_66 ;
break;
case V_67 :
V_39 = V_68 ;
V_40 = V_69 ;
V_35 = ( const T_3 * ) & V_70 ;
V_36 = V_71 ;
V_37 = V_72 ;
break;
case V_73 :
V_39 = V_74 ;
V_40 = V_75 ;
V_35 = ( const T_3 * ) & V_76 ;
V_36 = V_77 ;
V_37 = V_78 ;
break;
case V_79 :
V_39 = V_80 ;
V_40 = V_81 ;
V_35 = ( const T_3 * ) & V_82 ;
V_36 = V_83 ;
V_37 = V_84 ;
break;
case V_85 :
case V_86 :
V_39 = V_87 ;
V_40 = V_88 ;
V_35 = ( const T_3 * ) & V_89 ;
V_36 = V_90 ;
V_37 = V_91 ;
break;
case V_92 :
V_39 = V_93 ;
V_40 = V_94 ;
V_35 = ( const T_3 * ) & V_95 ;
V_36 = V_96 ;
V_37 = V_97 ;
break;
case V_98 :
V_39 = V_99 ;
V_40 = V_100 ;
V_35 = ( const T_3 * ) & V_101 ;
V_36 = V_102 ;
V_37 = V_103 ;
break;
case V_104 :
V_39 = V_105 ;
V_40 = V_106 ;
V_35 = ( const T_3 * ) & V_107 ;
V_36 = V_108 ;
V_37 = V_109 ;
break;
case V_110 :
V_39 = V_111 ;
V_40 = V_112 ;
V_35 = ( const T_3 * ) & V_113 ;
V_36 = V_114 ;
V_37 = V_115 ;
break;
default:
F_18 ( L_1 ) ;
F_19 () ;
}
V_38 = ( const T_3 * ) V_2 -> V_41 -> V_12 ;
V_15 = F_3 ( V_2 , V_39 ,
V_38 , V_40 , V_4 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_5 ( V_2 , V_36 ,
V_35 , V_37 ) ;
if ( V_15 )
return V_15 ;
return 0 ;
}
int F_20 ( struct V_1 * V_2 ,
T_1 V_3 , T_2 * V_116 , T_1 V_4 )
{
int V_15 ;
V_15 = F_1 ( V_2 , V_3 , V_4 ) ;
if ( V_15 )
return V_15 ;
* V_116 = F_4 ( V_16 ) ;
return 0 ;
}
int F_21 ( struct V_1 * V_2 ,
T_1 V_3 , T_2 V_116 , T_1 V_4 )
{
int V_15 ;
V_15 = F_1 ( V_2 , V_3 , V_4 ) ;
if ( V_15 )
return V_15 ;
F_2 ( V_16 , V_116 ) ;
return 0 ;
}
