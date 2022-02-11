static int F_1 ( struct V_1 * V_1 , T_1 V_2 , int V_3 ,
T_2 * V_4 )
{
int V_5 , V_6 ;
int V_7 = V_3 * 2 ;
F_2 ( V_1 -> V_8 , L_1 ) ;
V_6 = F_3 ( V_1 -> V_9 , V_2 , V_4 , V_7 ) ;
for ( V_5 = V_2 ; V_5 < V_2 + V_3 ; V_5 ++ ) {
V_4 [ V_5 - V_2 ] = F_4 ( V_4 [ V_5 - V_2 ] ) ;
V_4 [ V_5 - V_2 ] &= V_10 [ V_5 ] . V_11 ;
}
F_5 ( V_3 , V_4 ) ;
return V_6 ;
}
static int F_6 ( struct V_1 * V_1 , T_1 V_2 , int V_3 , T_2 * V_4 )
{
int V_5 ;
int V_12 = V_2 + V_3 ;
int V_6 = 0 ;
int V_7 = V_3 * 2 ;
if ( ( V_2 + V_3 - 1 ) > V_13 ) {
F_7 ( V_1 -> V_8 , L_2 ,
V_2 + V_3 - 1 ) ;
return - V_14 ;
}
F_2 ( V_1 -> V_8 ,
L_3 , V_15 , V_2 , V_2 , V_3 ) ;
#if V_16
for ( V_5 = V_2 ; V_5 < V_12 ; V_5 ++ ) {
if ( ! V_10 [ V_5 ] . V_11 )
F_8 ( V_1 -> V_8 ,
L_4 , V_5 ) ;
}
#endif
for ( V_5 = V_2 ; V_5 < V_12 ; V_5 ++ )
if ( V_10 [ V_5 ] . V_17 )
return F_1 ( V_1 , V_2 , V_3 , V_4 ) ;
F_2 ( V_1 -> V_8 , L_5 ) ;
memcpy ( V_4 , & V_1 -> V_18 [ V_2 ] , V_7 ) ;
F_5 ( V_3 , V_4 ) ;
return V_6 ;
}
static inline int F_9 ( struct V_1 * V_1 , T_1 V_2 )
{
if ( V_2 == V_19 ||
V_1 -> V_18 [ V_19 ] == V_20 )
return 0 ;
if ( ( V_2 >= V_21 &&
V_2 <= V_22 ) ||
( V_2 >= V_23 &&
V_2 <= V_24 ) )
return 1 ;
return 0 ;
}
static int F_10 ( struct V_1 * V_1 , T_1 V_2 , int V_3 , T_2 * V_25 )
{
int V_5 ;
int V_12 = V_2 + V_3 ;
int V_7 = V_3 * 2 ;
if ( ( V_2 + V_3 - 1 ) > V_13 ) {
F_7 ( V_1 -> V_8 , L_2 ,
V_2 + V_3 - 1 ) ;
return - V_14 ;
}
for ( V_5 = V_2 ; V_5 < V_12 ; V_5 ++ ) {
if ( ! V_10 [ V_5 ] . V_26 ) {
F_7 ( V_1 -> V_8 ,
L_6 , V_5 ) ;
return - V_14 ;
}
if ( F_9 ( V_1 , V_5 ) ) {
F_7 ( V_1 -> V_8 ,
L_7 , V_5 ) ;
return - V_14 ;
}
V_25 [ V_5 - V_2 ] &= V_10 [ V_5 ] . V_26 ;
V_1 -> V_18 [ V_5 ] =
( V_1 -> V_18 [ V_5 ] & ~ V_10 [ V_5 ] . V_26 )
| V_25 [ V_5 - V_2 ] ;
V_25 [ V_5 - V_2 ] = F_11 ( V_25 [ V_5 - V_2 ] ) ;
}
return F_12 ( V_1 -> V_9 , V_2 , V_25 , V_7 ) ;
}
int F_13 ( struct V_1 * V_1 , T_2 V_2 , T_2 V_27 )
{
T_2 V_28 ;
int V_29 ;
F_14 ( & V_30 ) ;
V_29 = F_6 ( V_1 , V_2 , 1 , & V_28 ) ;
if ( V_29 ) {
F_7 ( V_1 -> V_8 , L_8 , V_2 ) ;
goto V_31;
}
V_28 &= ~ V_27 ;
V_29 = F_10 ( V_1 , V_2 , 1 , & V_28 ) ;
if ( V_29 )
F_7 ( V_1 -> V_8 , L_9 , V_2 ) ;
V_31:
F_15 ( & V_30 ) ;
return V_29 ;
}
int F_16 ( struct V_1 * V_1 , T_2 V_2 , T_2 V_27 )
{
T_2 V_28 ;
int V_29 ;
F_14 ( & V_30 ) ;
V_29 = F_6 ( V_1 , V_2 , 1 , & V_28 ) ;
if ( V_29 ) {
F_7 ( V_1 -> V_8 , L_8 , V_2 ) ;
goto V_31;
}
V_28 |= V_27 ;
V_29 = F_10 ( V_1 , V_2 , 1 , & V_28 ) ;
if ( V_29 )
F_7 ( V_1 -> V_8 , L_9 , V_2 ) ;
V_31:
F_15 ( & V_30 ) ;
return V_29 ;
}
T_2 F_17 ( struct V_1 * V_1 , int V_2 )
{
T_2 V_28 ;
int V_29 ;
F_14 ( & V_30 ) ;
V_29 = F_6 ( V_1 , V_2 , 1 , & V_28 ) ;
if ( V_29 )
F_7 ( V_1 -> V_8 , L_8 , V_2 ) ;
F_15 ( & V_30 ) ;
return V_28 ;
}
int F_18 ( struct V_1 * V_1 , int V_2 , T_2 V_32 )
{
int V_6 ;
T_2 V_28 = V_32 ;
F_14 ( & V_30 ) ;
V_6 = F_10 ( V_1 , V_2 , 1 , & V_28 ) ;
if ( V_6 )
F_7 ( V_1 -> V_8 , L_9 , V_2 ) ;
F_15 ( & V_30 ) ;
return V_6 ;
}
int F_19 ( struct V_1 * V_1 , int V_33 , int V_34 ,
T_2 * V_4 )
{
int V_29 = 0 ;
F_14 ( & V_30 ) ;
V_29 = F_6 ( V_1 , V_33 , V_34 , V_4 ) ;
if ( V_29 )
F_7 ( V_1 -> V_8 , L_10 ,
V_33 ) ;
F_15 ( & V_30 ) ;
return V_29 ;
}
int F_20 ( struct V_1 * V_1 , int V_33 , int V_34 ,
T_2 * V_25 )
{
int V_6 = 0 ;
F_14 ( & V_30 ) ;
V_6 = F_10 ( V_1 , V_33 , V_34 , V_25 ) ;
if ( V_6 )
F_7 ( V_1 -> V_8 , L_11 ,
V_33 ) ;
F_15 ( & V_30 ) ;
return V_6 ;
}
int F_21 ( struct V_1 * V_1 )
{
T_2 V_35 = V_36 ;
int V_6 ;
F_22 ( V_15 ) ;
F_14 ( & V_30 ) ;
V_6 = F_10 ( V_1 , V_19 , 1 , & V_35 ) ;
if ( V_6 )
F_7 ( V_1 -> V_8 , L_12 ) ;
F_15 ( & V_30 ) ;
return V_6 ;
}
int F_23 ( struct V_1 * V_1 )
{
T_2 V_35 = V_20 ;
int V_6 ;
F_22 ( V_15 ) ;
F_14 ( & V_30 ) ;
V_6 = F_10 ( V_1 , V_19 , 1 , & V_35 ) ;
if ( V_6 )
F_7 ( V_1 -> V_8 , L_13 ) ;
F_15 ( & V_30 ) ;
return V_6 ;
}
int F_24 ( struct V_1 * V_1 , int V_37 , int V_38 , int V_39 )
{
T_2 V_2 , V_40 = 0 ;
if ( V_37 < V_41 || V_37 > V_42 )
return - V_14 ;
if ( V_37 >= V_43 && V_37 <= V_42
&& ( V_38 != 0 || V_39 != 0 ) )
return - V_14 ;
F_14 ( & V_1 -> V_44 ) ;
V_2 = F_17 ( V_1 , V_45 ) ;
F_18 ( V_1 , V_45 , V_2 | V_46 ) ;
if ( V_38 || V_39 ) {
V_2 = V_38 << 13 ;
V_2 |= V_39 << 12 ;
F_18 ( V_1 , V_47 + V_37 , V_2 ) ;
}
V_2 = F_17 ( V_1 , V_48 ) ;
V_2 |= 1 << V_37 | V_49 ;
F_18 ( V_1 , V_48 , V_2 ) ;
F_25 ( & V_1 -> V_50 ) ;
F_26 ( & V_1 -> V_50 , F_27 ( 5 ) ) ;
V_2 = F_17 ( V_1 , V_48 ) ;
if ( V_2 & V_49 )
F_7 ( V_1 -> V_8 , L_14 , V_37 ) ;
else
V_40 = F_17 ( V_1 ,
V_47 + V_37 ) ;
V_2 = F_17 ( V_1 , V_45 ) ;
F_18 ( V_1 , V_45 ,
V_2 & ~ V_46 ) ;
F_15 ( & V_1 -> V_44 ) ;
return V_40 & V_51 ;
}
static T_3 F_28 ( int V_52 , void * V_53 )
{
struct V_1 * V_1 = V_53 ;
F_29 ( & V_1 -> V_50 ) ;
return V_54 ;
}
static int F_30 ( struct V_1 * V_1 , int type , int V_55 )
{
int V_5 , V_6 = 0 ;
T_2 V_56 ;
const T_2 * V_57 ;
switch ( type ) {
case 0 :
switch ( V_55 ) {
#ifdef F_31
case 0 :
V_57 = V_58 ;
break;
#endif
#ifdef F_32
case 1 :
V_57 = V_59 ;
break;
#endif
#ifdef F_33
case 2 :
V_57 = V_60 ;
break;
#endif
#ifdef F_34
case 3 :
V_57 = V_61 ;
break;
#endif
default:
F_7 ( V_1 -> V_8 ,
L_15 ,
V_55 ) ;
return - V_14 ;
}
break;
case 1 :
switch ( V_55 ) {
#ifdef F_35
case 0 :
V_57 = V_62 ;
break;
#endif
#ifdef F_36
case 1 :
V_57 = V_63 ;
break;
#endif
#ifdef F_37
case 2 :
V_57 = V_64 ;
break;
#endif
#ifdef F_38
case 3 :
V_57 = V_65 ;
break;
#endif
default:
F_7 ( V_1 -> V_8 ,
L_16 ,
V_55 ) ;
return - V_14 ;
}
break;
case 2 :
switch ( V_55 ) {
#ifdef F_39
case 0 :
V_57 = V_66 ;
break;
#endif
#ifdef F_40
case 1 :
V_57 = V_67 ;
break;
#endif
#ifdef F_41
case 2 :
V_57 = V_68 ;
break;
#endif
#ifdef F_42
case 3 :
V_57 = V_69 ;
break;
#endif
default:
F_7 ( V_1 -> V_8 ,
L_17 ,
V_55 ) ;
return - V_14 ;
}
break;
default:
F_7 ( V_1 -> V_8 ,
L_18 ,
V_55 ) ;
return - V_14 ;
}
V_1 -> V_18 =
F_43 ( sizeof( T_2 ) * ( V_13 + 1 ) , V_70 ) ;
if ( V_1 -> V_18 == NULL )
return - V_71 ;
V_6 = F_3 ( V_1 -> V_9 , 0 , V_1 -> V_18 ,
sizeof( T_2 ) * ( V_13 + 1 ) ) ;
if ( V_6 < 0 ) {
F_7 ( V_1 -> V_8 ,
L_19 ) ;
goto V_31;
}
for ( V_5 = 0 ; V_5 < V_13 ; V_5 ++ ) {
if ( V_10 [ V_5 ] . V_11 &&
( V_5 < V_72 || V_5 > V_73 ) ) {
V_56 = F_4 ( V_1 -> V_18 [ V_5 ] ) ;
V_56 &= V_10 [ V_5 ] . V_11 ;
V_1 -> V_18 [ V_5 ] = V_56 ;
} else
V_1 -> V_18 [ V_5 ] = V_57 [ V_5 ] ;
}
V_31:
F_44 ( V_1 -> V_18 ) ;
return V_6 ;
}
static void F_45 ( struct V_1 * V_1 ,
const char * V_74 ,
struct V_75 * * V_76 )
{
int V_6 ;
* V_76 = F_46 ( V_74 , - 1 ) ;
if ( * V_76 == NULL ) {
F_7 ( V_1 -> V_8 , L_20 , V_74 ) ;
return;
}
( * V_76 ) -> V_8 . V_77 = V_1 -> V_8 ;
F_47 ( * V_76 , V_1 ) ;
V_6 = F_48 ( * V_76 ) ;
if ( V_6 != 0 ) {
F_7 ( V_1 -> V_8 , L_21 , V_74 , V_6 ) ;
F_49 ( * V_76 ) ;
* V_76 = NULL ;
}
}
int F_50 ( struct V_1 * V_1 , int V_52 ,
struct V_78 * V_79 )
{
int V_6 ;
unsigned int V_80 , V_81 , V_82 ;
unsigned int V_83 , V_55 , V_84 ;
F_51 ( V_1 -> V_8 , V_1 ) ;
V_6 = F_52 ( V_1 -> V_9 , V_85 , & V_80 ) ;
if ( V_6 != 0 ) {
F_7 ( V_1 -> V_8 , L_22 , V_6 ) ;
goto V_29;
}
V_6 = F_52 ( V_1 -> V_9 , V_86 , & V_81 ) ;
if ( V_6 != 0 ) {
F_7 ( V_1 -> V_8 , L_22 , V_6 ) ;
goto V_29;
}
V_6 = F_52 ( V_1 -> V_9 , V_87 , & V_82 ) ;
if ( V_6 != 0 ) {
F_7 ( V_1 -> V_8 , L_23 , V_6 ) ;
goto V_29;
}
if ( V_80 != 0x6143 ) {
F_7 ( V_1 -> V_8 ,
L_24 , V_80 ) ;
V_6 = - V_88 ;
goto V_29;
}
V_55 = V_81 & V_89 >> 10 ;
V_83 = V_81 & V_90 ;
V_84 = ( V_81 & V_91 ) >> 12 ;
F_53 ( V_1 -> V_8 ,
L_25 ,
V_55 , V_83 , V_82 , V_84 ) ;
if ( V_83 != 0 ) {
F_7 ( V_1 -> V_8 , L_26 ) ;
V_6 = - V_88 ;
goto V_29;
}
switch ( V_82 ) {
case 0 :
V_1 -> V_92 . V_93 = V_94 ;
V_1 -> V_92 . V_95 = V_96 ;
switch ( V_84 ) {
case V_97 :
F_53 ( V_1 -> V_8 , L_27 ) ;
break;
case V_98 :
F_53 ( V_1 -> V_8 , L_28 ) ;
break;
case V_99 :
F_53 ( V_1 -> V_8 , L_29 ) ;
V_1 -> V_100 . V_101 = 1 ;
break;
case V_102 :
F_53 ( V_1 -> V_8 , L_30 ) ;
V_1 -> V_100 . V_101 = 1 ;
break;
default:
F_7 ( V_1 -> V_8 , L_31 ) ;
V_6 = - V_88 ;
goto V_29;
}
break;
case 1 :
V_1 -> V_92 . V_93 = V_103 ;
V_1 -> V_92 . V_95 = V_104 ;
switch ( V_84 ) {
case 0 :
F_53 ( V_1 -> V_8 , L_32 ) ;
V_1 -> V_100 . V_101 = 1 ;
break;
case 1 :
F_53 ( V_1 -> V_8 , L_33 ) ;
V_1 -> V_100 . V_101 = 1 ;
break;
default:
F_7 ( V_1 -> V_8 , L_34 ) ;
V_6 = - V_88 ;
goto V_29;
}
break;
case 2 :
V_1 -> V_92 . V_93 = V_94 ;
V_1 -> V_92 . V_95 = V_96 ;
switch ( V_84 ) {
case 0 :
F_53 ( V_1 -> V_8 , L_35 ) ;
V_1 -> V_100 . V_101 = 1 ;
break;
default:
F_7 ( V_1 -> V_8 , L_36 ) ;
V_6 = - V_88 ;
goto V_29;
}
break;
default:
F_7 ( V_1 -> V_8 , L_37 ) ;
V_6 = - V_88 ;
goto V_29;
}
V_6 = F_30 ( V_1 , V_82 , V_55 ) ;
if ( V_6 < 0 ) {
F_7 ( V_1 -> V_8 , L_38 ) ;
return V_6 ;
}
F_54 ( & V_1 -> V_44 ) ;
F_55 ( & V_1 -> V_50 ) ;
V_6 = F_56 ( V_1 , V_52 , V_79 ) ;
if ( V_6 < 0 )
goto V_105;
if ( V_1 -> V_106 ) {
V_6 = F_57 ( V_1 -> V_106 +
V_107 ,
NULL , F_28 , 0 ,
L_39 , V_1 ) ;
if ( V_6 < 0 )
F_8 ( V_1 -> V_8 ,
L_40 , V_6 ) ;
}
if ( V_79 && V_79 -> V_108 ) {
V_6 = V_79 -> V_108 ( V_1 ) ;
if ( V_6 != 0 ) {
F_7 ( V_1 -> V_8 , L_41 ,
V_6 ) ;
goto V_109;
}
}
F_18 ( V_1 , V_110 , 0x0 ) ;
F_45 ( V_1 , L_42 ,
& ( V_1 -> V_111 . V_76 ) ) ;
F_45 ( V_1 , L_43 ,
& ( V_1 -> V_112 . V_76 ) ) ;
F_45 ( V_1 , L_44 ,
& ( V_1 -> V_113 . V_76 ) ) ;
F_45 ( V_1 , L_45 ,
& ( V_1 -> V_100 . V_76 ) ) ;
F_45 ( V_1 , L_46 , & ( V_1 -> V_114 . V_76 ) ) ;
F_45 ( V_1 , L_47 , & ( V_1 -> V_115 . V_76 ) ) ;
return 0 ;
V_109:
F_58 ( V_1 ) ;
V_105:
F_44 ( V_1 -> V_18 ) ;
V_29:
return V_6 ;
}
void F_59 ( struct V_1 * V_1 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < F_60 ( V_1 -> V_92 . V_116 ) ; V_5 ++ )
F_61 ( V_1 -> V_92 . V_116 [ V_5 ] . V_76 ) ;
for ( V_5 = 0 ; V_5 < F_60 ( V_1 -> V_92 . V_76 ) ; V_5 ++ )
F_61 ( V_1 -> V_92 . V_76 [ V_5 ] ) ;
F_61 ( V_1 -> V_115 . V_76 ) ;
F_61 ( V_1 -> V_114 . V_76 ) ;
F_61 ( V_1 -> V_100 . V_76 ) ;
F_61 ( V_1 -> V_113 . V_76 ) ;
F_61 ( V_1 -> V_112 . V_76 ) ;
F_61 ( V_1 -> V_111 . V_76 ) ;
if ( V_1 -> V_106 )
F_62 ( V_1 -> V_106 + V_107 , V_1 ) ;
F_58 ( V_1 ) ;
F_44 ( V_1 -> V_18 ) ;
}
