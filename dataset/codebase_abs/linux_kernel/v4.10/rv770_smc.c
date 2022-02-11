static int F_1 ( struct V_1 * V_2 ,
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
unsigned long V_12 ;
T_2 V_13 , V_14 , V_15 ;
T_1 V_5 ;
int V_16 = 0 ;
if ( V_9 & 3 )
return - V_6 ;
if ( ( V_9 + V_11 ) > V_4 )
return - V_6 ;
V_5 = V_9 ;
F_4 ( & V_2 -> V_17 , V_12 ) ;
while ( V_11 >= 4 ) {
V_13 = ( V_10 [ 0 ] << 24 ) | ( V_10 [ 1 ] << 16 ) | ( V_10 [ 2 ] << 8 ) | V_10 [ 3 ] ;
V_16 = F_1 ( V_2 , V_5 , V_4 ) ;
if ( V_16 )
goto V_18;
F_2 ( V_19 , V_13 ) ;
V_10 += 4 ;
V_11 -= 4 ;
V_5 += 4 ;
}
if ( V_11 > 0 ) {
V_13 = 0 ;
V_16 = F_1 ( V_2 , V_5 , V_4 ) ;
if ( V_16 )
goto V_18;
V_14 = F_5 ( V_19 ) ;
V_15 = 8 * ( 4 - V_11 ) ;
while ( V_11 > 0 ) {
V_13 = ( V_13 << 8 ) + * V_10 ++ ;
V_11 -- ;
}
V_13 <<= V_15 ;
V_13 |= ( V_14 & ~ ( ( ~ 0UL ) << V_15 ) ) ;
V_16 = F_1 ( V_2 , V_5 , V_4 ) ;
if ( V_16 )
goto V_18;
F_2 ( V_19 , V_13 ) ;
}
V_18:
F_6 ( & V_2 -> V_17 , V_12 ) ;
return V_16 ;
}
static int F_7 ( struct V_1 * V_2 ,
T_2 V_20 , const T_3 * V_10 ,
T_2 V_11 )
{
T_2 V_21 , V_22 ;
if ( V_11 % 4 )
return - V_6 ;
if ( V_20 < V_23 ) {
V_21 = V_23 - V_20 ;
if ( V_21 > V_11 )
return 0 ;
V_11 -= V_21 ;
V_10 += V_21 ;
V_20 = V_23 ;
}
for ( V_22 = 0 ; V_22 < V_11 ; V_22 += 4 ) {
V_21 = ( V_10 [ V_22 ] << 24 ) | ( V_10 [ V_22 + 1 ] << 16 ) | ( V_10 [ V_22 + 2 ] << 8 ) | V_10 [ V_22 + 3 ] ;
F_2 ( V_24 + V_22 , V_21 ) ;
}
return 0 ;
}
void F_8 ( struct V_1 * V_2 )
{
F_9 ( V_25 , V_26 , ~ V_26 ) ;
}
void F_10 ( struct V_1 * V_2 )
{
F_9 ( V_25 , 0 , ~ V_26 ) ;
}
void F_11 ( struct V_1 * V_2 )
{
F_9 ( V_25 , 0 , ~ V_27 ) ;
}
void F_12 ( struct V_1 * V_2 )
{
F_9 ( V_25 , V_27 , ~ V_27 ) ;
}
bool F_13 ( struct V_1 * V_2 )
{
T_2 V_21 ;
V_21 = F_5 ( V_25 ) ;
if ( ( V_21 & V_26 ) && ( V_21 & V_27 ) )
return true ;
else
return false ;
}
T_4 F_14 ( struct V_1 * V_2 , T_5 V_28 )
{
T_2 V_21 ;
int V_22 ;
T_4 V_29 ;
if ( ! F_13 ( V_2 ) )
return V_30 ;
F_9 ( V_31 , F_15 ( V_28 ) , ~ V_32 ) ;
for ( V_22 = 0 ; V_22 < V_2 -> V_33 ; V_22 ++ ) {
V_21 = F_5 ( V_31 ) & V_34 ;
V_21 >>= V_35 ;
if ( V_21 != 0 )
break;
F_16 ( 1 ) ;
}
V_21 = F_5 ( V_31 ) & V_34 ;
V_21 >>= V_35 ;
V_29 = ( T_4 ) V_21 ;
return V_29 ;
}
T_4 F_17 ( struct V_1 * V_2 )
{
int V_22 ;
T_4 V_29 = V_36 ;
if ( ! F_13 ( V_2 ) )
return V_29 ;
for ( V_22 = 0 ; V_22 < V_2 -> V_33 ; V_22 ++ ) {
if ( F_5 ( V_25 ) & V_37 )
break;
F_16 ( 1 ) ;
}
return V_29 ;
}
static void F_18 ( struct V_1 * V_2 , T_1 V_4 )
{
unsigned long V_12 ;
T_1 V_22 ;
F_4 ( & V_2 -> V_17 , V_12 ) ;
for ( V_22 = 0 ; V_22 < V_4 ; V_22 += 4 ) {
F_1 ( V_2 , V_22 , V_4 ) ;
F_2 ( V_19 , 0 ) ;
}
F_6 ( & V_2 -> V_17 , V_12 ) ;
}
int F_19 ( struct V_1 * V_2 ,
T_1 V_4 )
{
int V_16 ;
const T_3 * V_38 ;
T_1 V_39 ;
T_1 V_40 ;
const T_3 * V_41 ;
T_1 V_42 ;
T_1 V_43 ;
if ( ! V_2 -> V_44 )
return - V_6 ;
F_18 ( V_2 , V_4 ) ;
switch ( V_2 -> V_45 ) {
case V_46 :
V_42 = V_47 ;
V_43 = V_48 ;
V_38 = ( const T_3 * ) & V_49 ;
V_39 = V_50 ;
V_40 = V_51 ;
break;
case V_52 :
V_42 = V_53 ;
V_43 = V_54 ;
V_38 = ( const T_3 * ) & V_55 ;
V_39 = V_56 ;
V_40 = V_57 ;
break;
case V_58 :
V_42 = V_59 ;
V_43 = V_60 ;
V_38 = ( const T_3 * ) & V_61 ;
V_39 = V_62 ;
V_40 = V_63 ;
break;
case V_64 :
V_42 = V_65 ;
V_43 = V_66 ;
V_38 = ( const T_3 * ) & V_67 ;
V_39 = V_68 ;
V_40 = V_69 ;
break;
case V_70 :
V_42 = V_71 ;
V_43 = V_72 ;
V_38 = ( const T_3 * ) & V_73 ;
V_39 = V_74 ;
V_40 = V_75 ;
break;
case V_76 :
V_42 = V_77 ;
V_43 = V_78 ;
V_38 = ( const T_3 * ) & V_79 ;
V_39 = V_80 ;
V_40 = V_81 ;
break;
case V_82 :
V_42 = V_83 ;
V_43 = V_84 ;
V_38 = ( const T_3 * ) & V_85 ;
V_39 = V_86 ;
V_40 = V_87 ;
break;
case V_88 :
case V_89 :
V_42 = V_90 ;
V_43 = V_91 ;
V_38 = ( const T_3 * ) & V_92 ;
V_39 = V_93 ;
V_40 = V_94 ;
break;
case V_95 :
V_42 = V_96 ;
V_43 = V_97 ;
V_38 = ( const T_3 * ) & V_98 ;
V_39 = V_99 ;
V_40 = V_100 ;
break;
case V_101 :
V_42 = V_102 ;
V_43 = V_103 ;
V_38 = ( const T_3 * ) & V_104 ;
V_39 = V_105 ;
V_40 = V_106 ;
break;
case V_107 :
V_42 = V_108 ;
V_43 = V_109 ;
V_38 = ( const T_3 * ) & V_110 ;
V_39 = V_111 ;
V_40 = V_112 ;
break;
case V_113 :
V_42 = V_114 ;
V_43 = V_115 ;
V_38 = ( const T_3 * ) & V_116 ;
V_39 = V_117 ;
V_40 = V_118 ;
break;
default:
F_20 ( L_1 ) ;
F_21 () ;
}
V_41 = ( const T_3 * ) V_2 -> V_44 -> V_13 ;
V_16 = F_3 ( V_2 , V_42 ,
V_41 , V_43 , V_4 ) ;
if ( V_16 )
return V_16 ;
V_16 = F_7 ( V_2 , V_39 ,
V_38 , V_40 ) ;
if ( V_16 )
return V_16 ;
return 0 ;
}
int F_22 ( struct V_1 * V_2 ,
T_1 V_3 , T_2 * V_119 , T_1 V_4 )
{
unsigned long V_12 ;
int V_16 ;
F_4 ( & V_2 -> V_17 , V_12 ) ;
V_16 = F_1 ( V_2 , V_3 , V_4 ) ;
if ( V_16 == 0 )
* V_119 = F_5 ( V_19 ) ;
F_6 ( & V_2 -> V_17 , V_12 ) ;
return V_16 ;
}
int F_23 ( struct V_1 * V_2 ,
T_1 V_3 , T_2 V_119 , T_1 V_4 )
{
unsigned long V_12 ;
int V_16 ;
F_4 ( & V_2 -> V_17 , V_12 ) ;
V_16 = F_1 ( V_2 , V_3 , V_4 ) ;
if ( V_16 == 0 )
F_2 ( V_19 , V_119 ) ;
F_6 ( & V_2 -> V_17 , V_12 ) ;
return V_16 ;
}
