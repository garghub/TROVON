static int F_1 ( void * V_1 )
{
T_1 * V_2 = ( T_1 * ) V_1 ;
return ( int ) ( V_2 -> V_3 ) ;
}
static int F_2 ( void * V_1 )
{
T_1 * V_2 = ( T_1 * ) V_1 ;
return ( int ) V_2 -> V_4 * 2 ;
}
static T_2 F_3 ( void * V_1 , T_3 * V_5 , T_4 V_6 )
{
T_1 * V_2 ;
V_2 = ( T_1 * ) V_1 ;
return F_4 ( & V_5 -> V_7 [ V_6 ] ) ;
}
static T_2 F_5 ( void * V_1 , T_3 * V_5 , T_4 V_8 )
{
T_1 * V_2 = ( T_1 * ) V_1 ;
T_4 V_9 , V_10 , V_11 ;
T_5 V_12 , V_13 ;
V_10 = V_8 / V_2 -> V_14 ;
V_11 = V_8 % V_2 -> V_14 ;
V_12 = V_15 |
( ( V_16 << V_17 ) & V_18 ) |
( ( V_10 << V_19 ) & V_20 ) |
( ( V_11 << V_21 ) & V_22 ) ;
F_6 ( & V_5 -> V_23 , V_12 ) ;
for ( V_9 = 0 ;
( ( V_13 = F_4 ( & V_5 -> V_23 ) ) & V_15 )
&& ( V_9 < V_24 ) ; V_9 ++ )
;
if ( V_9 >= V_24 ) {
return 0xffff ;
}
if ( V_13 & V_25 ) {
return 0xffff ;
}
V_13 = ( V_13 & V_26 ) >> V_27 ;
return ( int ) V_13 ;
}
static int F_7 ( T_6 * V_28 , int V_29 )
{
int V_30 = 0 ;
switch ( V_28 -> V_31 ) {
case V_32 :
case V_33 :
V_30 = V_29 * 2 - V_34 - V_35 ;
break;
case V_36 :
V_30 = V_29 * 2 - V_34 - V_35 ;
break;
default:
break;
}
return V_30 ;
}
static void F_8 ( T_1 * V_2 , T_3 * V_5 )
{
T_4 V_9 ;
T_5 V_12 , V_13 ;
if ( V_2 -> V_28 -> V_37 == 21 || V_2 -> V_28 -> V_37 == 24
|| V_2 -> V_28 -> V_37 == 27 ) {
V_2 -> V_38 = V_39 ;
} else if ( V_2 -> V_28 -> V_37 == 36 ) {
if ( V_2 -> V_4 >= 128 )
V_2 -> V_38 = V_40 ;
else
V_2 -> V_38 = V_41 ;
} else if ( V_2 -> V_28 -> V_37 == 23 || V_2 -> V_28 -> V_37 >= 25 ) {
V_2 -> V_38 = V_40 ;
}
V_12 =
V_15 | ( ( V_42 << V_17 ) & V_18 ) ;
F_6 ( & V_5 -> V_23 , V_12 ) ;
for ( V_9 = 0 ;
( ( V_13 = F_4 ( & V_5 -> V_23 ) ) & V_15 )
&& ( V_9 < V_24 ) ; V_9 ++ )
;
if ( V_9 >= V_24 ) {
return;
}
V_2 -> V_3 = F_4 ( & V_5 -> V_43 ) ;
if ( ( V_2 -> V_28 -> V_31 == V_32 )
|| ( V_2 -> V_28 -> V_31 == V_33 ) ) {
T_5 V_44 ;
V_44 =
( F_3 ( V_2 , V_5 , V_2 -> V_38 + V_45 ) &
V_46 )
>> V_47 ;
V_2 -> V_3 |= ( V_44 << V_48 ) ;
}
V_2 -> V_49 = V_2 -> V_38 + V_50 ;
V_2 -> V_51 = V_2 -> V_4 ;
if ( V_2 -> V_3 & V_52 ) {
V_2 -> V_51 =
F_3 ( V_2 , V_5 , V_2 -> V_38 + V_53 ) / 16 ;
V_2 -> V_54 = V_2 -> V_51 ;
} else
V_2 -> V_54 = V_2 -> V_49 ;
V_2 -> V_55 = F_7 ( V_2 -> V_28 , V_2 -> V_4 ) / 2 ;
if ( V_2 -> V_3 & V_56 ) {
V_2 -> V_55 =
F_3 ( V_2 , V_5 , V_2 -> V_38 + V_57 ) / 16 ;
V_2 -> V_58 = V_2 -> V_55 ;
} else
V_2 -> V_58 = V_2 -> V_54 ;
V_2 -> V_59 = V_2 -> V_4 ;
}
static void * F_9 ( T_6 * V_28 )
{
T_4 V_60 ;
T_3 * V_5 ;
T_1 * V_2 ;
if ( ! F_10 ( V_28 -> V_37 ) )
return NULL ;
if ( F_11 ( V_28 ) )
return NULL ;
if ( ! F_12 ( V_28 ) )
return NULL ;
V_2 = & V_61 ;
switch ( ( V_28 -> V_62 & V_63 ) >> V_64 ) {
case 0 :
return NULL ;
case 1 :
V_2 -> V_65 = 32 ;
V_2 -> V_14 = 64 ;
V_2 -> V_4 = 128 ;
break;
case 2 :
V_2 -> V_65 = 64 ;
V_2 -> V_14 = 64 ;
V_2 -> V_4 = 256 ;
break;
case 5 :
V_2 -> V_65 = 96 ;
V_2 -> V_14 = 64 ;
V_2 -> V_4 = 384 ;
break;
case 7 :
V_2 -> V_65 = 16 ;
V_2 -> V_14 = 64 ;
V_2 -> V_4 = 64 ;
break;
default:
return NULL ;
}
V_60 = F_13 ( V_28 ) ;
V_5 = F_14 ( V_28 , V_66 ) ;
F_8 ( V_2 , V_5 ) ;
F_14 ( V_28 , V_60 ) ;
return ( void * ) V_2 ;
}
static int F_15 ( void * V_1 , int V_67 , T_2 * V_68 , T_4 * V_69 )
{
T_1 * V_2 = ( T_1 * ) V_1 ;
T_4 V_60 ;
T_3 * V_5 ;
T_4 V_70 , V_71 , V_72 ;
switch ( V_67 ) {
case V_73 :
V_72 = ( T_4 ) V_2 -> V_51 - V_2 -> V_49 ;
if ( ! ( V_2 -> V_3 & V_52 ) ) {
* V_69 = V_72 ;
return - V_74 ;
}
if ( * V_69 < V_72 ) {
* V_69 = V_72 ;
return - V_75 ;
}
V_70 = V_2 -> V_49 ;
break;
case V_76 :
V_72 = ( ( T_4 ) V_2 -> V_55 - V_2 -> V_54 ) ;
if ( ! ( V_2 -> V_3 & V_56 ) ) {
* V_69 = V_72 ;
return - V_74 ;
}
if ( * V_69 < V_72 ) {
* V_69 = V_72 ;
return - V_75 ;
}
V_70 = V_2 -> V_54 ;
break;
case V_77 :
V_72 = V_78 ;
if ( ! ( V_2 -> V_3 & V_79 ) ) {
* V_69 = V_72 ;
return - V_74 ;
}
if ( * V_69 < V_72 ) {
* V_69 = V_72 ;
return - V_75 ;
}
V_70 = V_2 -> V_38 + V_80 ;
break;
case V_81 :
V_72 = ( T_4 ) V_2 -> V_59 - V_2 -> V_58 ;
if ( ! ( V_2 -> V_3 & V_82 ) ) {
* V_69 = V_72 ;
return - V_74 ;
}
if ( * V_69 < V_72 ) {
* V_69 = V_72 ;
return - V_75 ;
}
V_70 = V_2 -> V_58 ;
break;
case V_83 :
V_72 = ( ( T_4 ) V_2 -> V_59 - V_2 -> V_49 ) ;
if ( ! ( V_2 -> V_3 & ( V_52 | V_56 ) ) ) {
* V_69 = V_72 ;
return - V_74 ;
}
if ( * V_69 < V_72 ) {
* V_69 = V_72 ;
return - V_75 ;
}
V_70 = V_2 -> V_49 ;
break;
default:
return - V_84 ;
}
V_60 = F_13 ( V_2 -> V_28 ) ;
V_5 = F_14 ( V_2 -> V_28 , V_66 ) ;
for ( V_71 = 0 ; V_71 < V_72 ; V_71 ++ )
V_68 [ V_71 ] = F_3 ( V_1 , V_5 , V_70 + V_71 ) ;
F_14 ( V_2 -> V_28 , V_60 ) ;
* V_69 = V_72 ;
return 0 ;
}
static int F_16 ( void * V_1 , char * V_68 , T_4 * V_85 )
{
return - V_86 ;
}
static int F_17 ( void * V_1 )
{
T_1 * V_2 = ( T_1 * ) V_1 ;
return ( int ) ( V_2 -> V_87 | V_2 -> V_88 ) ;
}
static int F_18 ( void * V_1 )
{
T_1 * V_2 = ( T_1 * ) V_1 ;
return ( int ) ( V_2 -> V_89 ) ;
}
static T_2 F_19 ( void * V_1 , T_3 * V_5 , T_4 V_6 )
{
volatile T_2 * V_90 ;
V_90 = ( volatile T_2 * ) ( ( volatile char * ) V_5 + V_91 ) ;
return F_4 ( & V_90 [ V_6 ] ) ;
}
static T_2 F_20 ( void * V_1 , T_3 * V_5 , int V_92 )
{
T_1 * V_2 = ( T_1 * ) V_1 ;
volatile T_2 * V_90 ;
V_90 = ( volatile T_2 * ) ( ( volatile char * ) V_5 + V_91 ) ;
return F_4 ( & V_90 [ ( V_2 -> V_89 / 2 ) + V_92 ] ) ;
}
static T_2 F_21 ( void * V_1 , T_3 * V_5 , T_4 V_60 )
{
T_4 V_9 , V_10 , V_11 ;
T_5 V_12 , V_13 ;
V_10 = V_60 / 65 ;
V_11 = V_60 % 65 ;
V_12 = V_15 | V_93 |
( ( V_10 << V_19 ) & V_20 ) | ( V_11 & V_22 ) ;
F_6 ( & V_5 -> V_23 , V_12 ) ;
V_13 = F_4 ( & V_5 -> V_23 ) ;
for ( V_9 = 0 ;
( ( V_13 & V_15 ) == V_15 ) && ( V_9 < V_24 ) ;
V_9 ++ )
V_13 = F_4 ( & V_5 -> V_23 ) ;
if ( V_9 >= V_24 ) {
return 0xffff ;
}
if ( V_13 & V_25 ) {
return 0xffff ;
}
V_13 = ( V_13 & V_26 ) >> V_27 ;
return ( T_2 ) V_13 ;
}
static void * F_22 ( T_6 * V_28 )
{
T_4 V_60 ;
T_3 * V_5 ;
T_1 * V_2 ;
T_5 V_94 = 0 , V_95 , V_96 = 0 ;
void * V_30 = NULL ;
V_2 = & V_61 ;
V_60 = F_13 ( V_28 ) ;
V_5 = F_14 ( V_28 , V_66 ) ;
if ( V_5 != NULL ) {
V_94 = F_4 ( & V_5 -> V_97 ) ;
if ( ( V_94 & V_63 ) == 0 ) {
goto V_98;
}
if ( ! ( ( V_2 -> V_37 == 12 ) || ( V_2 -> V_37 == 17 )
|| ( V_2 -> V_37 == 22 ) ) )
return NULL ;
V_2 -> V_89 =
1 << ( ( ( V_94 & V_63 ) >> V_64 )
+ V_99 ) ;
if ( V_2 -> V_37 >= 18 )
V_2 -> V_89 -= ( ( V_100 - V_101 ) * 2 ) ;
V_2 -> V_87 = ( int ) ( F_4 ( & V_5 -> V_43 ) & V_102 ) ;
V_2 -> V_103 = - 1 ;
if ( F_20 ( V_2 , V_5 , V_104 ) == V_105 ) {
V_2 -> V_88 |= V_106 ;
V_2 -> V_103 = F_20 ( V_2 , V_5 , V_101 ) ;
}
if ( F_20 ( V_2 , V_5 , V_107 ) == V_105 )
V_2 -> V_88 |= V_108 ;
if ( F_20 ( V_2 , V_5 , V_109 ) == V_105 )
V_2 -> V_88 |= V_110 ;
if ( V_2 -> V_37 == 22 )
V_96 = 12 ;
if ( V_96 ) {
V_95 = F_4 ( & V_5 -> V_95 ) ;
V_95 =
( V_95 & ~ V_111 ) | ( V_96 << V_112 ) ;
F_6 ( & V_5 -> V_95 , V_95 ) ;
}
F_23 ( 10 ) ;
V_30 = ( void * ) V_2 ;
}
V_98:
F_14 ( V_28 , V_60 ) ;
return V_30 ;
}
static int F_24 ( void * V_1 , int V_67 , T_2 * V_68 , T_4 * V_69 )
{
T_1 * V_2 = ( T_1 * ) V_1 ;
T_5 V_60 , V_13 ;
T_3 * V_5 ;
int V_71 ;
if ( V_67 != V_106 ) {
return - V_86 ;
}
V_13 = V_2 -> V_87 | V_2 -> V_88 ;
if ( ( V_13 & V_67 ) == 0 )
return - V_74 ;
* V_69 =
( ( int ) * V_69 < V_2 -> V_103 / 2 ) ? * V_69 : ( T_4 ) V_2 -> V_103 / 2 ;
V_60 = F_13 ( V_2 -> V_28 ) ;
V_5 = F_14 ( V_2 -> V_28 , V_66 ) ;
for ( V_71 = 0 ; V_71 < ( int ) * V_69 ; V_71 ++ )
V_68 [ V_71 ] = F_19 ( V_1 , V_5 , V_71 ) ;
F_14 ( V_2 -> V_28 , V_60 ) ;
return 0 ;
}
static int F_25 ( void * V_1 , char * V_68 , T_4 * V_85 )
{
int V_113 = 0 ;
T_1 * V_2 = ( T_1 * ) V_1 ;
T_5 V_70 , V_114 , V_115 = 0 , V_13 ;
int V_71 , V_116 , V_117 , V_118 = 0 ;
T_5 V_60 ;
T_3 * V_5 ;
T_4 V_119 ;
T_2 * V_120 = NULL ;
V_60 = F_13 ( V_2 -> V_28 ) ;
V_5 = F_14 ( V_2 -> V_28 , V_66 ) ;
V_13 = F_17 ( V_1 ) ;
if ( ! ( V_13 & ( V_106 | V_108 ) ) ) {
V_113 = - 1 ;
goto V_98;
}
V_115 = F_18 ( V_1 ) ;
V_120 = F_26 ( V_115 , V_121 ) ;
if ( V_120 == NULL ) {
V_113 = - 2 ;
goto V_98;
}
for ( V_71 = 0 ; V_71 < ( int ) ( V_115 / 2 ) ; V_71 ++ )
V_120 [ V_71 ] = F_19 ( V_1 , V_5 , V_71 ) ;
if ( ( V_13 & V_106 ) == 0 ) {
for ( V_71 = 0 ; V_71 < ( int ) ( V_115 / 2 ) ; V_71 ++ )
if ( V_120 [ V_71 ] == V_122 )
break;
if ( V_71 < ( int ) ( V_115 / 2 ) ) {
V_70 = V_71 ;
V_114 = ( V_71 * 2 ) + V_120 [ V_71 + 1 ] ;
} else {
V_113 = - 3 ;
goto V_98;
}
} else {
V_114 = V_120 [ ( V_115 / 2 ) + V_101 ] ;
if ( V_120 [ 0 ] == V_122 ) {
V_70 = 0 ;
} else
V_70 = V_114 ;
}
V_116 = 0 ;
V_117 = 0 ;
V_71 = V_70 / 2 ;
V_119 = 0 ;
while ( ( V_71 < ( int ) ( V_115 / 2 ) ) && ( V_120 [ V_71 ] == V_122 ) ) {
int V_123 , V_124 = V_120 [ V_71 + 1 ] ;
if ( ( ( V_71 * 2 ) + V_124 ) >= ( int ) V_115 ) {
V_124 = 6 ;
}
if ( F_27 ( V_125 , ( V_126 * ) & V_120 [ V_71 ] , V_124 ) ==
V_127 ) {
V_117 ++ ;
V_123 = V_124 - 6 ;
V_118 += V_123 ;
if ( V_119 + V_123 >= * V_85 ) {
goto V_98;
}
memcpy ( & V_68 [ V_119 ] , & V_120 [ V_71 + 2 ] , V_123 ) ;
V_119 += V_123 ;
while ( V_119 > 1 &&
V_68 [ V_119 - 1 ] == 0 && V_68 [ V_119 - 2 ] == 0 )
V_119 -- ;
V_71 += V_124 / 2 ;
} else {
if ( V_120 [ V_71 + ( V_124 / 2 ) ] == V_122 ) {
V_71 += V_124 / 2 ;
} else {
while ( ++ V_71 < ( int ) ( V_115 / 2 ) )
if ( V_120 [ V_71 ] == V_122 )
break;
}
}
V_116 ++ ;
}
* V_85 = V_119 ;
V_98:
F_28 ( V_120 ) ;
F_14 ( V_2 -> V_28 , V_60 ) ;
return V_113 ;
}
int F_29 ( void * V_1 )
{
T_1 * V_2 = ( T_1 * ) V_1 ;
return V_2 -> V_128 -> V_3 ( V_1 ) ;
}
int F_30 ( void * V_1 )
{
T_1 * V_2 = ( T_1 * ) V_1 ;
return V_2 -> V_128 -> V_89 ( V_1 ) ;
}
T_2 F_31 ( void * V_1 , T_4 V_119 )
{
T_1 * V_2 = ( T_1 * ) V_1 ;
T_4 V_60 = F_13 ( V_2 -> V_28 ) ;
T_3 * V_5 = F_14 ( V_2 -> V_28 , V_66 ) ;
T_2 V_129 = ( T_2 ) V_2 -> V_128 -> V_130 ( V_1 , V_5 , V_119 ) ;
F_14 ( V_2 -> V_28 , V_60 ) ;
return V_129 ;
}
void * F_32 ( T_6 * V_28 )
{
T_1 * V_2 ;
void * V_30 = NULL ;
V_2 = & V_61 ;
memset ( V_2 , 0 , sizeof( T_1 ) ) ;
V_2 -> V_37 = V_28 -> V_37 ;
#ifdef F_33
if ( F_10 ( V_2 -> V_37 ) )
V_2 -> V_128 = & V_131 ;
#endif
#ifdef F_34
if ( F_35 ( V_2 -> V_37 ) )
V_2 -> V_128 = & V_132 ;
#endif
if ( V_2 -> V_128 == NULL ) {
return NULL ;
}
V_2 -> V_28 = V_28 ;
V_30 = ( V_2 -> V_128 -> V_133 ) ( V_28 ) ;
return V_30 ;
}
int
F_36 ( T_6 * V_28 , int V_67 , T_2 * V_68 ,
T_4 * V_69 ) {
bool V_134 = false ;
void * V_1 ;
int V_135 = 0 ;
V_134 = F_12 ( V_28 ) ;
if ( ! V_134 )
F_37 ( V_28 , true ) ;
if ( ! F_12 ( V_28 ) || F_11 ( V_28 ) ) {
V_135 = - V_136 ;
goto V_98;
}
V_1 = F_32 ( V_28 ) ;
if ( V_1 == NULL ) {
V_135 = - V_137 ;
goto V_98;
}
V_135 = ( ( ( T_1 * ) V_1 ) -> V_128 -> V_138 ) ( V_1 , V_67 , V_68 , V_69 ) ;
V_98:
if ( ! V_134 )
F_37 ( V_28 , false ) ;
return V_135 ;
}
int F_38 ( void * V_1 , char * V_68 , T_4 * V_85 )
{
T_1 * V_2 = ( T_1 * ) V_1 ;
return V_2 -> V_128 -> V_139 ( V_1 , V_68 , V_85 ) ;
}
