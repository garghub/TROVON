static int F_1 ( struct V_1 * V_2 )
{
int V_3 , V_4 , V_5 = 0 ;
for ( V_4 = V_6 ; V_4 >= V_7 ; V_4 -- ) {
if ( ( V_2 -> V_8 [ V_4 ] != V_2 -> V_9 [ V_4 ] ) ||
( ( V_4 == V_7 ) && V_5 ) ) {
switch ( V_4 ) {
case V_10 :
case V_11 :
V_5 = 1 ;
break;
}
V_2 -> V_12 = F_2 ( V_2 -> V_9 [ V_4 ] | V_4 ) ;
V_3 = F_3 ( V_2 -> V_13 , & V_2 -> V_12 , 4 ) ;
if ( V_3 < 0 )
return V_3 ;
V_2 -> V_8 [ V_4 ] = V_2 -> V_9 [ V_4 ] ;
F_4 ( & V_2 -> V_13 -> V_14 , L_1 ,
V_4 , ( V_15 ) V_2 -> V_9 [ V_4 ] | V_4 ) ;
}
}
return 0 ;
}
static int F_5 ( struct V_16 * V_17 ,
unsigned V_18 , unsigned V_19 ,
unsigned * V_20 )
{
struct V_1 * V_2 = F_6 ( V_17 ) ;
int V_3 ;
if ( V_18 > V_6 )
return - V_21 ;
F_7 ( & V_17 -> V_22 ) ;
if ( V_20 == NULL ) {
V_2 -> V_9 [ V_18 ] = V_19 & ~ ( F_8 ( 0 ) | F_8 ( 1 ) | F_8 ( 2 ) ) ;
V_3 = F_1 ( V_2 ) ;
} else {
* V_20 = V_2 -> V_8 [ V_18 ] ;
V_3 = 0 ;
}
F_9 ( & V_17 -> V_22 ) ;
return V_3 ;
}
static int F_10 ( struct V_1 * V_2 , unsigned short V_23 )
{
struct V_24 * V_25 = V_2 -> V_25 ;
do {
V_23 ++ ;
V_2 -> V_26 = ( V_2 -> V_27 * ( V_25 -> V_28 ? 2 : 1 ) ) /
( V_23 * ( V_25 -> V_29 ? 2 : 1 ) ) ;
} while ( V_2 -> V_26 > V_30 );
return V_23 ;
}
static int F_11 ( struct V_1 * V_2 , unsigned long long V_31 )
{
struct V_24 * V_25 = V_2 -> V_25 ;
T_1 V_32 ;
V_15 V_33 , V_34 , V_35 ;
T_2 V_36 , V_23 = 0 ;
T_3 V_37 ;
if ( V_31 > V_38 || V_31 < V_2 -> V_39 )
return - V_21 ;
if ( V_31 > V_40 ) {
V_34 = V_41 ;
V_36 = 75 ;
} else {
V_34 = 0 ;
V_36 = 23 ;
}
V_2 -> V_42 = 0 ;
while ( V_31 < V_43 ) {
V_31 <<= 1 ;
V_2 -> V_42 ++ ;
}
if ( V_25 -> V_44 )
V_23 = V_25 -> V_44 - 1 ;
V_35 = V_2 -> V_35 ;
do {
do {
do {
V_23 = F_10 ( V_2 , V_23 ) ;
V_2 -> V_45 = V_2 -> V_26 / V_35 ;
if ( V_23 > V_46 ) {
V_35 ++ ;
V_23 = 0 ;
}
} while ( ( V_2 -> V_45 > V_47 ) && V_23 );
} while ( V_23 == 0 );
V_32 = V_31 * ( T_1 ) V_2 -> V_45 + ( V_2 -> V_26 >> 1 ) ;
F_12 ( V_32 , V_2 -> V_26 ) ;
V_2 -> V_48 = F_12 ( V_32 , V_2 -> V_45 ) ;
V_2 -> V_49 = V_32 ;
} while ( V_36 > V_2 -> V_49 );
V_37 = F_13 ( V_2 -> V_26 , V_50 ) ;
if ( V_2 -> V_48 && V_2 -> V_45 ) {
V_33 = F_14 ( V_2 -> V_45 , V_2 -> V_48 ) ;
V_2 -> V_45 /= V_33 ;
V_2 -> V_48 /= V_33 ;
} else {
V_2 -> V_48 = 0 ;
V_2 -> V_45 = 1 ;
}
F_4 ( & V_2 -> V_13 -> V_14 , L_2
L_3
L_4 ,
V_31 , V_2 -> V_26 , V_23 , V_2 -> V_49 , V_2 -> V_48 , V_2 -> V_45 ,
1 << V_2 -> V_42 , V_34 ? L_5 : L_6 ,
V_37 ) ;
V_2 -> V_9 [ V_7 ] = F_15 ( V_2 -> V_49 ) |
F_16 ( V_2 -> V_48 ) ;
V_2 -> V_9 [ V_10 ] = F_17 ( 1 ) |
F_18 ( V_2 -> V_45 ) |
V_34 ;
V_2 -> V_9 [ V_51 ] =
F_19 ( V_23 ) |
V_52 |
( V_25 -> V_28 ? V_53 : 0 ) |
( V_25 -> V_29 ? V_54 : 0 ) |
( V_25 -> V_55 & ( V_56 |
V_57 | V_58 |
F_20 ( 5000 ) |
F_21 ( 0x7 ) | F_22 ( 0x9 ) ) ) ;
V_2 -> V_9 [ V_59 ] = V_25 -> V_60 &
( F_23 ( 0xFFF ) |
F_24 ( 0x3 ) |
V_61 |
V_62 |
V_63 |
V_64 ) ;
V_2 -> V_9 [ V_11 ] =
V_65 |
F_25 ( V_2 -> V_42 ) |
F_26 ( V_37 ) |
V_66 |
( V_25 -> V_67 &
( F_27 ( 0x3 ) |
F_28 ( 0x3 ) |
V_68 |
V_69 |
V_70 ) ) ;
V_2 -> V_9 [ V_6 ] = V_71 ;
return F_1 ( V_2 ) ;
}
static T_4 F_29 ( struct V_16 * V_17 ,
T_5 V_72 ,
const struct V_73 * V_74 ,
const char * V_75 , T_6 V_76 )
{
struct V_1 * V_2 = F_6 ( V_17 ) ;
unsigned long long V_77 ;
int V_3 ;
V_3 = F_30 ( V_75 , 10 , & V_77 ) ;
if ( V_3 )
return V_3 ;
F_7 ( & V_17 -> V_22 ) ;
switch ( ( V_15 ) V_72 ) {
case V_78 :
V_3 = F_11 ( V_2 , V_77 ) ;
break;
case V_79 :
if ( V_77 > V_80 )
V_3 = - V_21 ;
else
V_2 -> V_27 = V_77 ;
break;
case V_81 :
if ( V_77 == 0 )
V_3 = - V_21 ;
else
V_2 -> V_35 = V_77 ;
break;
case V_82 :
if ( V_77 )
V_2 -> V_9 [ V_51 ] |= V_83 ;
else
V_2 -> V_9 [ V_51 ] &= ~ V_83 ;
F_1 ( V_2 ) ;
break;
default:
V_3 = - V_21 ;
}
F_9 ( & V_17 -> V_22 ) ;
return V_3 ? V_3 : V_76 ;
}
static T_4 F_31 ( struct V_16 * V_17 ,
T_5 V_72 ,
const struct V_73 * V_74 ,
char * V_75 )
{
struct V_1 * V_2 = F_6 ( V_17 ) ;
unsigned long long V_12 ;
int V_3 = 0 ;
F_7 ( & V_17 -> V_22 ) ;
switch ( ( V_15 ) V_72 ) {
case V_78 :
V_12 = ( T_1 ) ( ( V_2 -> V_49 * V_2 -> V_45 ) + V_2 -> V_48 ) *
( T_1 ) V_2 -> V_26 ;
F_12 ( V_12 , V_2 -> V_45 * ( 1 << V_2 -> V_42 ) ) ;
if ( F_32 ( V_2 -> V_25 -> V_84 ) )
if ( ! F_33 ( V_2 -> V_25 -> V_84 ) ) {
F_4 ( & V_2 -> V_13 -> V_14 , L_7 ) ;
V_3 = - V_85 ;
}
break;
case V_79 :
V_12 = V_2 -> V_27 ;
break;
case V_81 :
V_12 = V_2 -> V_35 ;
break;
case V_82 :
V_12 = ! ! ( V_2 -> V_9 [ V_51 ] & V_83 ) ;
break;
default:
V_3 = - V_21 ;
}
F_9 ( & V_17 -> V_22 ) ;
return V_3 < 0 ? V_3 : sprintf ( V_75 , L_8 , V_12 ) ;
}
static int F_34 ( struct V_86 * V_13 )
{
struct V_24 * V_25 = V_13 -> V_14 . V_87 ;
struct V_16 * V_17 ;
struct V_1 * V_2 ;
int V_3 ;
if ( ! V_25 ) {
F_35 ( & V_13 -> V_14 , L_9 ) ;
V_25 = & V_88 ;
}
V_17 = F_36 ( sizeof( * V_2 ) ) ;
if ( V_17 == NULL )
return - V_89 ;
V_2 = F_6 ( V_17 ) ;
V_2 -> V_18 = F_37 ( & V_13 -> V_14 , L_10 ) ;
if ( ! F_38 ( V_2 -> V_18 ) ) {
V_3 = F_39 ( V_2 -> V_18 ) ;
if ( V_3 )
goto V_90;
}
F_40 ( V_13 , V_17 ) ;
V_2 -> V_13 = V_13 ;
V_2 -> V_25 = V_25 ;
V_17 -> V_14 . V_91 = & V_13 -> V_14 ;
V_17 -> V_92 = ( V_25 -> V_92 [ 0 ] != 0 ) ? V_25 -> V_92 :
F_41 ( V_13 ) -> V_92 ;
V_17 -> V_93 = & V_94 ;
V_17 -> V_95 = V_96 ;
V_17 -> V_97 = & V_98 ;
V_17 -> V_99 = 1 ;
V_2 -> V_35 = V_25 -> V_100 ;
V_2 -> V_27 = V_25 -> V_27 ;
V_2 -> V_39 = F_41 ( V_13 ) -> V_101 == 4351 ?
V_102 : V_103 ;
memset ( V_2 -> V_8 , 0xFF , sizeof( V_2 -> V_8 ) ) ;
if ( F_32 ( V_25 -> V_84 ) ) {
V_3 = F_42 ( V_25 -> V_84 , V_17 -> V_92 ) ;
if ( V_3 ) {
F_43 ( & V_13 -> V_14 , L_11 ,
V_25 -> V_84 ) ;
goto V_104;
}
F_44 ( V_25 -> V_84 ) ;
}
if ( V_25 -> V_105 ) {
V_3 = F_11 ( V_2 , V_25 -> V_105 ) ;
if ( V_3 )
goto V_106;
}
V_3 = F_45 ( V_17 ) ;
if ( V_3 )
goto V_106;
return 0 ;
V_106:
if ( F_32 ( V_25 -> V_84 ) )
F_46 ( V_25 -> V_84 ) ;
V_104:
if ( ! F_38 ( V_2 -> V_18 ) )
F_47 ( V_2 -> V_18 ) ;
V_90:
if ( ! F_38 ( V_2 -> V_18 ) )
F_48 ( V_2 -> V_18 ) ;
F_49 ( V_17 ) ;
return V_3 ;
}
static int F_50 ( struct V_86 * V_13 )
{
struct V_16 * V_17 = F_51 ( V_13 ) ;
struct V_1 * V_2 = F_6 ( V_17 ) ;
struct V_107 * V_18 = V_2 -> V_18 ;
V_2 -> V_9 [ V_51 ] |= V_83 ;
F_1 ( V_2 ) ;
F_52 ( V_17 ) ;
if ( ! F_38 ( V_18 ) ) {
F_47 ( V_18 ) ;
F_48 ( V_18 ) ;
}
if ( F_32 ( V_2 -> V_25 -> V_84 ) )
F_46 ( V_2 -> V_25 -> V_84 ) ;
F_49 ( V_17 ) ;
return 0 ;
}
