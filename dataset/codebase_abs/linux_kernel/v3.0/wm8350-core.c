static int F_1 ( struct V_1 * V_1 , T_1 V_2 , int V_3 ,
T_2 * V_4 )
{
int V_5 , V_6 ;
int V_7 = V_3 * 2 ;
F_2 ( V_1 -> V_8 , L_1 ) ;
V_6 = V_1 -> V_9 ( V_1 , V_2 , V_7 , ( char * ) V_4 ) ;
for ( V_5 = V_2 ; V_5 < V_2 + V_3 ; V_5 ++ ) {
V_4 [ V_5 - V_2 ] = F_3 ( V_4 [ V_5 - V_2 ] ) ;
V_4 [ V_5 - V_2 ] &= V_10 [ V_5 ] . V_11 ;
}
F_4 ( V_3 , V_4 ) ;
return V_6 ;
}
static int F_5 ( struct V_1 * V_1 , T_1 V_2 , int V_3 , T_2 * V_4 )
{
int V_5 ;
int V_12 = V_2 + V_3 ;
int V_6 = 0 ;
int V_7 = V_3 * 2 ;
if ( V_1 -> V_9 == NULL )
return - V_13 ;
if ( ( V_2 + V_3 - 1 ) > V_14 ) {
F_6 ( V_1 -> V_8 , L_2 ,
V_2 + V_3 - 1 ) ;
return - V_15 ;
}
F_2 ( V_1 -> V_8 ,
L_3 , V_16 , V_2 , V_2 , V_3 ) ;
#if V_17
for ( V_5 = V_2 ; V_5 < V_12 ; V_5 ++ ) {
if ( ! V_10 [ V_5 ] . V_11 )
F_7 ( V_1 -> V_8 ,
L_4 , V_5 ) ;
}
#endif
for ( V_5 = V_2 ; V_5 < V_12 ; V_5 ++ )
if ( V_10 [ V_5 ] . V_18 )
return F_1 ( V_1 , V_2 , V_3 , V_4 ) ;
F_2 ( V_1 -> V_8 , L_5 ) ;
memcpy ( V_4 , & V_1 -> V_19 [ V_2 ] , V_7 ) ;
F_4 ( V_3 , V_4 ) ;
return V_6 ;
}
static inline int F_8 ( struct V_1 * V_1 , T_1 V_2 )
{
if ( V_2 == V_20 ||
V_1 -> V_19 [ V_20 ] == V_21 )
return 0 ;
if ( ( V_2 >= V_22 &&
V_2 <= V_23 ) ||
( V_2 >= V_24 &&
V_2 <= V_25 ) )
return 1 ;
return 0 ;
}
static int F_9 ( struct V_1 * V_1 , T_1 V_2 , int V_3 , T_2 * V_26 )
{
int V_5 ;
int V_12 = V_2 + V_3 ;
int V_7 = V_3 * 2 ;
if ( V_1 -> V_27 == NULL )
return - V_13 ;
if ( ( V_2 + V_3 - 1 ) > V_14 ) {
F_6 ( V_1 -> V_8 , L_2 ,
V_2 + V_3 - 1 ) ;
return - V_15 ;
}
for ( V_5 = V_2 ; V_5 < V_12 ; V_5 ++ ) {
if ( ! V_10 [ V_5 ] . V_28 ) {
F_6 ( V_1 -> V_8 ,
L_6 , V_5 ) ;
return - V_15 ;
}
if ( F_8 ( V_1 , V_5 ) ) {
F_6 ( V_1 -> V_8 ,
L_7 , V_5 ) ;
return - V_15 ;
}
V_26 [ V_5 - V_2 ] &= V_10 [ V_5 ] . V_28 ;
V_1 -> V_19 [ V_5 ] =
( V_1 -> V_19 [ V_5 ] & ~ V_10 [ V_5 ] . V_28 )
| V_26 [ V_5 - V_2 ] ;
V_26 [ V_5 - V_2 ] = F_10 ( V_26 [ V_5 - V_2 ] ) ;
}
return V_1 -> V_27 ( V_1 , V_2 , V_7 , ( char * ) V_26 ) ;
}
int F_11 ( struct V_1 * V_1 , T_2 V_2 , T_2 V_29 )
{
T_2 V_30 ;
int V_31 ;
F_12 ( & V_32 ) ;
V_31 = F_5 ( V_1 , V_2 , 1 , & V_30 ) ;
if ( V_31 ) {
F_6 ( V_1 -> V_8 , L_8 , V_2 ) ;
goto V_33;
}
V_30 &= ~ V_29 ;
V_31 = F_9 ( V_1 , V_2 , 1 , & V_30 ) ;
if ( V_31 )
F_6 ( V_1 -> V_8 , L_9 , V_2 ) ;
V_33:
F_13 ( & V_32 ) ;
return V_31 ;
}
int F_14 ( struct V_1 * V_1 , T_2 V_2 , T_2 V_29 )
{
T_2 V_30 ;
int V_31 ;
F_12 ( & V_32 ) ;
V_31 = F_5 ( V_1 , V_2 , 1 , & V_30 ) ;
if ( V_31 ) {
F_6 ( V_1 -> V_8 , L_8 , V_2 ) ;
goto V_33;
}
V_30 |= V_29 ;
V_31 = F_9 ( V_1 , V_2 , 1 , & V_30 ) ;
if ( V_31 )
F_6 ( V_1 -> V_8 , L_9 , V_2 ) ;
V_33:
F_13 ( & V_32 ) ;
return V_31 ;
}
T_2 F_15 ( struct V_1 * V_1 , int V_2 )
{
T_2 V_30 ;
int V_31 ;
F_12 ( & V_32 ) ;
V_31 = F_5 ( V_1 , V_2 , 1 , & V_30 ) ;
if ( V_31 )
F_6 ( V_1 -> V_8 , L_8 , V_2 ) ;
F_13 ( & V_32 ) ;
return V_30 ;
}
int F_16 ( struct V_1 * V_1 , int V_2 , T_2 V_34 )
{
int V_6 ;
T_2 V_30 = V_34 ;
F_12 ( & V_32 ) ;
V_6 = F_9 ( V_1 , V_2 , 1 , & V_30 ) ;
if ( V_6 )
F_6 ( V_1 -> V_8 , L_9 , V_2 ) ;
F_13 ( & V_32 ) ;
return V_6 ;
}
int F_17 ( struct V_1 * V_1 , int V_35 , int V_36 ,
T_2 * V_4 )
{
int V_31 = 0 ;
F_12 ( & V_32 ) ;
V_31 = F_5 ( V_1 , V_35 , V_36 , V_4 ) ;
if ( V_31 )
F_6 ( V_1 -> V_8 , L_10 ,
V_35 ) ;
F_13 ( & V_32 ) ;
return V_31 ;
}
int F_18 ( struct V_1 * V_1 , int V_35 , int V_36 ,
T_2 * V_26 )
{
int V_6 = 0 ;
F_12 ( & V_32 ) ;
V_6 = F_9 ( V_1 , V_35 , V_36 , V_26 ) ;
if ( V_6 )
F_6 ( V_1 -> V_8 , L_11 ,
V_35 ) ;
F_13 ( & V_32 ) ;
return V_6 ;
}
int F_19 ( struct V_1 * V_1 )
{
T_2 V_37 = V_38 ;
int V_6 ;
F_20 ( V_16 ) ;
F_12 ( & V_32 ) ;
V_6 = F_9 ( V_1 , V_20 , 1 , & V_37 ) ;
if ( V_6 )
F_6 ( V_1 -> V_8 , L_12 ) ;
F_13 ( & V_32 ) ;
return V_6 ;
}
int F_21 ( struct V_1 * V_1 )
{
T_2 V_37 = V_21 ;
int V_6 ;
F_20 ( V_16 ) ;
F_12 ( & V_32 ) ;
V_6 = F_9 ( V_1 , V_20 , 1 , & V_37 ) ;
if ( V_6 )
F_6 ( V_1 -> V_8 , L_13 ) ;
F_13 ( & V_32 ) ;
return V_6 ;
}
int F_22 ( struct V_1 * V_1 , int V_39 , int V_40 , int V_41 )
{
T_2 V_2 , V_42 = 0 ;
if ( V_39 < V_43 || V_39 > V_44 )
return - V_15 ;
if ( V_39 >= V_45 && V_39 <= V_44
&& ( V_40 != 0 || V_41 != 0 ) )
return - V_15 ;
F_12 ( & V_1 -> V_46 ) ;
V_2 = F_15 ( V_1 , V_47 ) ;
F_16 ( V_1 , V_47 , V_2 | V_48 ) ;
if ( V_40 || V_41 ) {
V_2 = V_40 << 13 ;
V_2 |= V_41 << 12 ;
F_16 ( V_1 , V_49 + V_39 , V_2 ) ;
}
V_2 = F_15 ( V_1 , V_50 ) ;
V_2 |= 1 << V_39 | V_51 ;
F_16 ( V_1 , V_50 , V_2 ) ;
F_23 ( & V_1 -> V_52 ) ;
F_24 ( & V_1 -> V_52 , F_25 ( 5 ) ) ;
V_2 = F_15 ( V_1 , V_50 ) ;
if ( V_2 & V_51 )
F_6 ( V_1 -> V_8 , L_14 , V_39 ) ;
else
V_42 = F_15 ( V_1 ,
V_49 + V_39 ) ;
V_2 = F_15 ( V_1 , V_47 ) ;
F_16 ( V_1 , V_47 ,
V_2 & ~ V_48 ) ;
F_13 ( & V_1 -> V_46 ) ;
return V_42 & V_53 ;
}
static T_3 F_26 ( int V_54 , void * V_55 )
{
struct V_1 * V_1 = V_55 ;
F_27 ( & V_1 -> V_52 ) ;
return V_56 ;
}
static int F_28 ( struct V_1 * V_1 , int type , int V_57 )
{
int V_5 , V_6 = 0 ;
T_2 V_58 ;
const T_2 * V_59 ;
switch ( type ) {
case 0 :
switch ( V_57 ) {
#ifdef F_29
case 0 :
V_59 = V_60 ;
break;
#endif
#ifdef F_30
case 1 :
V_59 = V_61 ;
break;
#endif
#ifdef F_31
case 2 :
V_59 = V_62 ;
break;
#endif
#ifdef F_32
case 3 :
V_59 = V_63 ;
break;
#endif
default:
F_6 ( V_1 -> V_8 ,
L_15 ,
V_57 ) ;
return - V_15 ;
}
break;
case 1 :
switch ( V_57 ) {
#ifdef F_33
case 0 :
V_59 = V_64 ;
break;
#endif
#ifdef F_34
case 1 :
V_59 = V_65 ;
break;
#endif
#ifdef F_35
case 2 :
V_59 = V_66 ;
break;
#endif
#ifdef F_36
case 3 :
V_59 = V_67 ;
break;
#endif
default:
F_6 ( V_1 -> V_8 ,
L_16 ,
V_57 ) ;
return - V_15 ;
}
break;
case 2 :
switch ( V_57 ) {
#ifdef F_37
case 0 :
V_59 = V_68 ;
break;
#endif
#ifdef F_38
case 1 :
V_59 = V_69 ;
break;
#endif
#ifdef F_39
case 2 :
V_59 = V_70 ;
break;
#endif
#ifdef F_40
case 3 :
V_59 = V_71 ;
break;
#endif
default:
F_6 ( V_1 -> V_8 ,
L_17 ,
V_57 ) ;
return - V_15 ;
}
break;
default:
F_6 ( V_1 -> V_8 ,
L_18 ,
V_57 ) ;
return - V_15 ;
}
V_1 -> V_19 =
F_41 ( sizeof( T_2 ) * ( V_14 + 1 ) , V_72 ) ;
if ( V_1 -> V_19 == NULL )
return - V_73 ;
V_6 = V_1 -> V_9 ( V_1 , 0 ,
sizeof( T_2 ) * ( V_14 + 1 ) ,
V_1 -> V_19 ) ;
if ( V_6 < 0 ) {
F_6 ( V_1 -> V_8 ,
L_19 ) ;
goto V_33;
}
for ( V_5 = 0 ; V_5 < V_14 ; V_5 ++ ) {
if ( V_10 [ V_5 ] . V_11 &&
( V_5 < V_74 || V_5 > V_75 ) ) {
V_58 = F_3 ( V_1 -> V_19 [ V_5 ] ) ;
V_58 &= V_10 [ V_5 ] . V_11 ;
V_1 -> V_19 [ V_5 ] = V_58 ;
} else
V_1 -> V_19 [ V_5 ] = V_59 [ V_5 ] ;
}
V_33:
F_42 ( V_1 -> V_19 ) ;
return V_6 ;
}
static void F_43 ( struct V_1 * V_1 ,
const char * V_76 ,
struct V_77 * * V_78 )
{
int V_6 ;
* V_78 = F_44 ( V_76 , - 1 ) ;
if ( * V_78 == NULL ) {
F_6 ( V_1 -> V_8 , L_20 , V_76 ) ;
return;
}
( * V_78 ) -> V_8 . V_79 = V_1 -> V_8 ;
F_45 ( * V_78 , V_1 ) ;
V_6 = F_46 ( * V_78 ) ;
if ( V_6 != 0 ) {
F_6 ( V_1 -> V_8 , L_21 , V_76 , V_6 ) ;
F_47 ( * V_78 ) ;
* V_78 = NULL ;
}
}
int F_48 ( struct V_1 * V_1 , int V_54 ,
struct V_80 * V_81 )
{
int V_6 ;
T_2 V_82 , V_83 , V_84 ;
T_2 V_85 , V_57 , V_86 ;
V_6 = V_1 -> V_9 ( V_1 , V_87 , sizeof( V_82 ) , & V_82 ) ;
if ( V_6 != 0 ) {
F_6 ( V_1 -> V_8 , L_22 , V_6 ) ;
goto V_31;
}
V_6 = V_1 -> V_9 ( V_1 , V_88 , sizeof( V_83 ) , & V_83 ) ;
if ( V_6 != 0 ) {
F_6 ( V_1 -> V_8 , L_22 , V_6 ) ;
goto V_31;
}
V_6 = V_1 -> V_9 ( V_1 , V_89 , sizeof( V_84 ) ,
& V_84 ) ;
if ( V_6 != 0 ) {
F_6 ( V_1 -> V_8 , L_23 , V_6 ) ;
goto V_31;
}
V_82 = F_3 ( V_82 ) ;
V_83 = F_3 ( V_83 ) ;
V_84 = F_3 ( V_84 ) ;
if ( V_82 != 0x6143 ) {
F_6 ( V_1 -> V_8 ,
L_24 , V_82 ) ;
V_6 = - V_13 ;
goto V_31;
}
V_57 = V_83 & V_90 >> 10 ;
V_85 = V_83 & V_91 ;
V_86 = ( V_83 & V_92 ) >> 12 ;
F_49 ( V_1 -> V_8 ,
L_25 ,
V_57 , V_85 , V_84 , V_86 ) ;
if ( V_85 != 0 ) {
F_6 ( V_1 -> V_8 , L_26 ) ;
V_6 = - V_13 ;
goto V_31;
}
switch ( V_84 ) {
case 0 :
V_1 -> V_93 . V_94 = V_95 ;
V_1 -> V_93 . V_96 = V_97 ;
switch ( V_86 ) {
case V_98 :
F_49 ( V_1 -> V_8 , L_27 ) ;
break;
case V_99 :
F_49 ( V_1 -> V_8 , L_28 ) ;
break;
case V_100 :
F_49 ( V_1 -> V_8 , L_29 ) ;
V_1 -> V_101 . V_102 = 1 ;
break;
case V_103 :
F_49 ( V_1 -> V_8 , L_30 ) ;
V_1 -> V_101 . V_102 = 1 ;
break;
default:
F_6 ( V_1 -> V_8 , L_31 ) ;
V_6 = - V_13 ;
goto V_31;
}
break;
case 1 :
V_1 -> V_93 . V_94 = V_104 ;
V_1 -> V_93 . V_96 = V_105 ;
switch ( V_86 ) {
case 0 :
F_49 ( V_1 -> V_8 , L_32 ) ;
V_1 -> V_101 . V_102 = 1 ;
break;
case 1 :
F_49 ( V_1 -> V_8 , L_33 ) ;
V_1 -> V_101 . V_102 = 1 ;
break;
default:
F_6 ( V_1 -> V_8 , L_34 ) ;
V_6 = - V_13 ;
goto V_31;
}
break;
case 2 :
V_1 -> V_93 . V_94 = V_95 ;
V_1 -> V_93 . V_96 = V_97 ;
switch ( V_86 ) {
case 0 :
F_49 ( V_1 -> V_8 , L_35 ) ;
V_1 -> V_101 . V_102 = 1 ;
break;
default:
F_6 ( V_1 -> V_8 , L_36 ) ;
V_6 = - V_13 ;
goto V_31;
}
break;
default:
F_6 ( V_1 -> V_8 , L_37 ) ;
V_6 = - V_13 ;
goto V_31;
}
V_6 = F_28 ( V_1 , V_84 , V_57 ) ;
if ( V_6 < 0 ) {
F_6 ( V_1 -> V_8 , L_38 ) ;
return V_6 ;
}
F_50 ( & V_1 -> V_46 ) ;
F_51 ( & V_1 -> V_52 ) ;
V_6 = F_52 ( V_1 , V_54 , V_81 ) ;
if ( V_6 < 0 )
goto V_106;
if ( V_1 -> V_107 ) {
V_6 = F_53 ( V_1 -> V_107 +
V_108 ,
NULL , F_26 , 0 ,
L_39 , V_1 ) ;
if ( V_6 < 0 )
F_7 ( V_1 -> V_8 ,
L_40 , V_6 ) ;
}
if ( V_81 && V_81 -> V_109 ) {
V_6 = V_81 -> V_109 ( V_1 ) ;
if ( V_6 != 0 ) {
F_6 ( V_1 -> V_8 , L_41 ,
V_6 ) ;
goto V_110;
}
}
F_16 ( V_1 , V_111 , 0x0 ) ;
F_43 ( V_1 , L_42 ,
& ( V_1 -> V_112 . V_78 ) ) ;
F_43 ( V_1 , L_43 ,
& ( V_1 -> V_113 . V_78 ) ) ;
F_43 ( V_1 , L_44 ,
& ( V_1 -> V_114 . V_78 ) ) ;
F_43 ( V_1 , L_45 ,
& ( V_1 -> V_101 . V_78 ) ) ;
F_43 ( V_1 , L_46 , & ( V_1 -> V_115 . V_78 ) ) ;
F_43 ( V_1 , L_47 , & ( V_1 -> V_116 . V_78 ) ) ;
return 0 ;
V_110:
F_54 ( V_1 ) ;
V_106:
F_42 ( V_1 -> V_19 ) ;
V_31:
return V_6 ;
}
void F_55 ( struct V_1 * V_1 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < F_56 ( V_1 -> V_93 . V_117 ) ; V_5 ++ )
F_57 ( V_1 -> V_93 . V_117 [ V_5 ] . V_78 ) ;
for ( V_5 = 0 ; V_5 < F_56 ( V_1 -> V_93 . V_78 ) ; V_5 ++ )
F_57 ( V_1 -> V_93 . V_78 [ V_5 ] ) ;
F_57 ( V_1 -> V_116 . V_78 ) ;
F_57 ( V_1 -> V_115 . V_78 ) ;
F_57 ( V_1 -> V_101 . V_78 ) ;
F_57 ( V_1 -> V_114 . V_78 ) ;
F_57 ( V_1 -> V_113 . V_78 ) ;
F_57 ( V_1 -> V_112 . V_78 ) ;
if ( V_1 -> V_107 )
F_58 ( V_1 -> V_107 + V_108 , V_1 ) ;
F_54 ( V_1 ) ;
F_42 ( V_1 -> V_19 ) ;
}
