void
F_1 (
T_1 * V_1 ,
T_2 * V_2 )
{
ASSERT ( V_2 -> V_3 != V_1 ) ;
ASSERT ( F_2 ( V_2 ) ) ;
ASSERT ( V_2 -> V_4 . V_5 == V_2 ) ;
F_3 ( V_1 , & V_2 -> V_4 . V_6 ) ;
V_2 -> V_3 = V_1 ;
}
void
F_4 (
T_1 * V_1 ,
T_2 * V_2 )
{
ASSERT ( V_2 -> V_3 == V_1 ) ;
ASSERT ( F_2 ( V_2 ) ) ;
V_1 -> V_7 |= V_8 ;
V_2 -> V_4 . V_6 . V_9 -> V_10 |= V_11 ;
}
void
F_5 (
T_1 * V_12 ,
T_1 * V_13 )
{
T_3 * V_14 , * V_15 ;
int V_16 , V_17 ;
T_3 * V_18 , * V_19 ;
if ( ! V_12 -> V_20 )
return;
F_6 ( V_13 ) ;
V_18 = V_12 -> V_20 -> V_21 ;
V_19 = V_13 -> V_20 -> V_21 ;
if( V_12 -> V_7 & V_22 )
V_13 -> V_7 |= V_22 ;
for ( V_17 = 0 ; V_17 < 2 ; V_17 ++ ) {
for ( V_16 = 0 ; V_16 < V_23 ; V_16 ++ ) {
if ( V_18 [ V_16 ] . V_24 == NULL )
break;
V_14 = & V_18 [ V_16 ] ;
V_15 = & V_19 [ V_16 ] ;
V_15 -> V_24 = V_14 -> V_24 ;
V_15 -> V_25 = V_15 -> V_26 = 0 ;
V_15 -> V_27 = 0 ;
V_15 -> V_28 = V_14 -> V_28 - V_14 -> V_29 ;
V_14 -> V_28 = V_14 -> V_29 ;
V_15 -> V_30 = V_14 -> V_30 -
V_14 -> V_31 ;
V_14 -> V_30 = V_14 -> V_31 ;
V_15 -> V_32 = V_14 -> V_32 - V_14 -> V_33 ;
V_14 -> V_32 = V_14 -> V_33 ;
}
V_18 = V_12 -> V_20 -> V_34 ;
V_19 = V_13 -> V_20 -> V_34 ;
}
}
void
F_7 (
T_1 * V_1 ,
T_4 * V_35 ,
T_5 V_36 ,
long V_37 )
{
T_6 * V_38 = V_1 -> V_39 ;
if ( ! F_8 ( V_38 ) ||
! F_9 ( V_38 ) ||
V_35 -> V_40 == V_38 -> V_41 . V_42 ||
V_35 -> V_40 == V_38 -> V_41 . V_43 )
return;
if ( V_1 -> V_20 == NULL )
F_6 ( V_1 ) ;
if ( F_10 ( V_38 ) && V_35 -> V_44 )
( void ) F_11 ( V_1 , V_35 -> V_44 , V_36 , V_37 ) ;
if ( F_12 ( V_38 ) && V_35 -> V_45 )
( void ) F_11 ( V_1 , V_35 -> V_45 , V_36 , V_37 ) ;
}
STATIC T_3 *
F_13 (
T_1 * V_1 ,
T_2 * V_2 )
{
int V_16 ;
T_3 * V_46 ;
V_46 = F_14 ( V_2 ) ?
V_1 -> V_20 -> V_21 : V_1 -> V_20 -> V_34 ;
for ( V_16 = 0 ; V_16 < V_23 ; V_16 ++ ) {
if ( V_46 [ V_16 ] . V_24 == NULL ||
V_46 [ V_16 ] . V_24 == V_2 )
return & V_46 [ V_16 ] ;
}
return NULL ;
}
void
F_11 (
T_1 * V_1 ,
T_2 * V_2 ,
T_5 V_36 ,
long V_37 )
{
T_3 * V_47 ;
ASSERT ( V_1 ) ;
ASSERT ( F_8 ( V_1 -> V_39 ) ) ;
V_47 = NULL ;
if ( V_1 -> V_20 == NULL )
F_6 ( V_1 ) ;
V_47 = F_13 ( V_1 , V_2 ) ;
ASSERT ( V_47 ) ;
if ( V_47 -> V_24 == NULL )
V_47 -> V_24 = V_2 ;
switch ( V_36 ) {
case V_48 :
V_47 -> V_28 += ( V_49 ) V_37 ;
break;
case V_50 :
V_47 -> V_32 += ( V_49 ) V_37 ;
break;
case V_51 :
if ( V_47 -> V_28 && V_37 > 0 ) {
V_47 -> V_29 += ( V_49 ) V_37 ;
ASSERT ( V_47 -> V_28 >= V_47 -> V_29 ) ;
}
V_47 -> V_25 += V_37 ;
break;
case V_52 :
V_47 -> V_53 += V_37 ;
break;
case V_54 :
if ( V_47 -> V_32 && V_37 > 0 ) {
V_47 -> V_33 += ( V_49 ) V_37 ;
ASSERT ( V_47 -> V_32 >= V_47 -> V_33 ) ;
}
V_47 -> V_26 += V_37 ;
break;
case V_55 :
V_47 -> V_30 += ( V_49 ) V_37 ;
break;
case V_56 :
if ( V_47 -> V_30 && V_37 > 0 ) {
V_47 -> V_31 += ( V_49 ) V_37 ;
ASSERT ( V_47 -> V_30 >= V_47 -> V_31 ) ;
}
V_47 -> V_27 += V_37 ;
break;
case V_57 :
V_47 -> V_58 += V_37 ;
break;
default:
ASSERT ( 0 ) ;
}
V_1 -> V_7 |= V_22 ;
}
STATIC void
F_15 (
T_1 * V_1 ,
T_3 * V_59 )
{
ASSERT ( V_59 [ 0 ] . V_24 != NULL ) ;
if ( V_59 [ 1 ] . V_24 == NULL ) {
F_16 ( V_59 [ 0 ] . V_24 ) ;
F_1 ( V_1 , V_59 [ 0 ] . V_24 ) ;
} else {
ASSERT ( V_23 == 2 ) ;
F_17 ( V_59 [ 0 ] . V_24 , V_59 [ 1 ] . V_24 ) ;
F_1 ( V_1 , V_59 [ 0 ] . V_24 ) ;
F_1 ( V_1 , V_59 [ 1 ] . V_24 ) ;
}
}
void
F_18 (
T_1 * V_1 )
{
int V_16 , V_17 ;
T_2 * V_2 ;
T_3 * V_47 , * V_46 ;
T_7 * V_60 ;
long V_61 ;
long V_62 ;
if ( ! ( V_1 -> V_7 & V_22 ) )
return;
ASSERT ( V_1 -> V_20 ) ;
V_46 = V_1 -> V_20 -> V_21 ;
for ( V_17 = 0 ; V_17 < 2 ; V_17 ++ ) {
if ( V_46 [ 0 ] . V_24 == NULL ) {
V_46 = V_1 -> V_20 -> V_34 ;
continue;
}
F_15 ( V_1 , V_46 ) ;
for ( V_16 = 0 ; V_16 < V_23 ; V_16 ++ ) {
V_47 = & V_46 [ V_16 ] ;
if ( ( V_2 = V_47 -> V_24 ) == NULL )
break;
ASSERT ( F_2 ( V_2 ) ) ;
ASSERT ( V_2 -> V_3 == V_1 ) ;
V_60 = & V_2 -> V_63 ;
V_61 = V_47 -> V_25 +
V_47 -> V_53 ;
V_62 = V_47 -> V_27 +
V_47 -> V_58 ;
#ifdef F_19
if ( V_61 < 0 )
ASSERT ( F_20 ( V_60 -> V_64 ) >=
- V_61 ) ;
if ( V_62 < 0 )
ASSERT ( F_20 ( V_60 -> V_65 ) >=
- V_62 ) ;
if ( V_47 -> V_26 < 0 )
ASSERT ( F_20 ( V_60 -> V_66 ) >=
- V_47 -> V_26 ) ;
#endif
if ( V_61 )
F_21 ( & V_60 -> V_64 , ( V_67 ) V_61 ) ;
if ( V_47 -> V_26 )
F_21 ( & V_60 -> V_66 , ( V_67 ) V_47 -> V_26 ) ;
if ( V_62 )
F_21 ( & V_60 -> V_65 , ( V_67 ) V_62 ) ;
if ( V_60 -> V_68 ) {
F_22 ( V_1 -> V_39 , V_60 ) ;
F_23 ( V_1 -> V_39 , V_60 ) ;
}
V_2 -> V_69 |= V_70 ;
F_4 ( V_1 , V_2 ) ;
if ( V_47 -> V_28 != 0 ) {
if ( V_47 -> V_28 != V_47 -> V_29 ) {
if ( V_47 -> V_28 >
V_47 -> V_29 )
V_2 -> V_71 -= ( V_67 )
( V_47 -> V_28 -
V_47 -> V_29 ) ;
else
V_2 -> V_71 -= ( V_67 )
( V_47 -> V_29 -
V_47 -> V_28 ) ;
}
} else {
if ( V_47 -> V_25 ) {
V_2 -> V_71 +=
( V_67 ) V_47 -> V_25 ;
}
}
if ( V_47 -> V_30 != 0 ) {
if ( V_47 -> V_30 != V_47 -> V_31 ) {
if ( V_47 -> V_30 >
V_47 -> V_31 )
V_2 -> V_72 -= ( V_67 )
( V_47 -> V_30 -
V_47 -> V_31 ) ;
else
V_2 -> V_72 -= ( V_67 )
( V_47 -> V_31 -
V_47 -> V_30 ) ;
}
} else {
if ( V_47 -> V_27 )
V_2 -> V_72 +=
( V_67 ) V_47 -> V_27 ;
}
if ( V_47 -> V_32 != 0 ) {
ASSERT ( V_47 -> V_32 >=
V_47 -> V_33 ) ;
if ( V_47 -> V_32 > V_47 -> V_33 )
V_2 -> V_73 -= ( V_67 )
( V_47 -> V_32 -
V_47 -> V_33 ) ;
} else {
if ( V_47 -> V_26 )
V_2 -> V_73 +=
( V_67 ) V_47 -> V_26 ;
}
ASSERT ( V_2 -> V_71 >=
F_20 ( V_2 -> V_63 . V_64 ) ) ;
ASSERT ( V_2 -> V_73 >=
F_20 ( V_2 -> V_63 . V_66 ) ) ;
ASSERT ( V_2 -> V_72 >=
F_20 ( V_2 -> V_63 . V_65 ) ) ;
}
V_46 = V_1 -> V_20 -> V_34 ;
}
}
void
F_24 (
T_1 * V_1 )
{
int V_16 , V_17 ;
T_2 * V_2 ;
T_3 * V_47 , * V_46 ;
T_8 V_74 ;
if ( ! V_1 -> V_20 || ! ( V_1 -> V_7 & V_22 ) )
return;
V_46 = V_1 -> V_20 -> V_21 ;
for ( V_17 = 0 ; V_17 < 2 ; V_17 ++ ) {
for ( V_16 = 0 ; V_16 < V_23 ; V_16 ++ ) {
V_47 = & V_46 [ V_16 ] ;
if ( ( V_2 = V_47 -> V_24 ) == NULL )
break;
V_74 = V_75 ;
if ( V_47 -> V_28 ) {
F_16 ( V_2 ) ;
V_74 = V_76 ;
V_2 -> V_71 -=
( V_67 ) V_47 -> V_28 ;
}
if ( V_47 -> V_32 ) {
if ( ! V_74 ) {
F_16 ( V_2 ) ;
V_74 = V_76 ;
}
V_2 -> V_73 -=
( V_67 ) V_47 -> V_32 ;
}
if ( V_47 -> V_30 ) {
if ( ! V_74 ) {
F_16 ( V_2 ) ;
V_74 = V_76 ;
}
V_2 -> V_72 -=
( V_67 ) V_47 -> V_30 ;
}
if ( V_74 )
F_25 ( V_2 ) ;
}
V_46 = V_1 -> V_20 -> V_34 ;
}
}
STATIC void
F_26 (
struct V_77 * V_38 ,
struct V_78 * V_2 ,
int type )
{
if ( V_2 -> V_69 & V_79 )
return;
F_27 ( F_28 ( & V_80 ,
( V_2 -> V_69 & V_81 ) ?
V_82 : V_83 ,
F_29 ( V_2 -> V_63 . V_68 ) ) ,
V_38 -> V_84 -> V_85 , type ) ;
}
STATIC int
F_30 (
T_1 * V_1 ,
T_6 * V_38 ,
T_2 * V_2 ,
long V_86 ,
long V_87 ,
T_5 V_88 )
{
V_67 V_89 ;
V_67 V_90 ;
T_9 V_91 ;
T_10 V_92 ;
T_10 V_93 ;
V_67 V_94 ;
V_67 * V_95 ;
T_11 * V_59 = V_38 -> V_96 ;
F_16 ( V_2 ) ;
if ( V_88 & V_48 ) {
V_89 = F_20 ( V_2 -> V_63 . V_97 ) ;
if ( ! V_89 )
V_89 = V_59 -> V_98 ;
V_90 = F_20 ( V_2 -> V_63 . V_99 ) ;
if ( ! V_90 )
V_90 = V_59 -> V_100 ;
V_91 = F_29 ( V_2 -> V_63 . V_101 ) ;
V_92 = F_31 ( V_2 -> V_63 . V_102 ) ;
V_93 = V_2 -> V_103 -> V_96 -> V_104 ;
V_95 = & V_2 -> V_71 ;
} else {
ASSERT ( V_88 & V_55 ) ;
V_89 = F_20 ( V_2 -> V_63 . V_105 ) ;
if ( ! V_89 )
V_89 = V_59 -> V_106 ;
V_90 = F_20 ( V_2 -> V_63 . V_107 ) ;
if ( ! V_90 )
V_90 = V_59 -> V_108 ;
V_91 = F_29 ( V_2 -> V_63 . V_109 ) ;
V_92 = F_31 ( V_2 -> V_63 . V_110 ) ;
V_93 = V_2 -> V_103 -> V_96 -> V_111 ;
V_95 = & V_2 -> V_72 ;
}
if ( ( V_88 & V_112 ) == 0 &&
V_2 -> V_63 . V_68 &&
( ( F_32 ( V_2 -> V_103 ) && F_14 ( V_2 ) ) ||
( F_33 ( V_2 -> V_103 ) &&
( F_34 ( V_2 ) || F_35 ( V_2 ) ) ) ) ) {
if ( V_86 > 0 ) {
V_94 = * V_95 + V_86 ;
if ( V_89 && V_94 > V_89 ) {
F_26 ( V_38 , V_2 , V_113 ) ;
goto V_114;
}
if ( V_90 && V_94 > V_90 ) {
if ( ( V_91 != 0 && F_36 () > V_91 ) ||
( V_92 != 0 && V_92 >= V_93 ) ) {
F_26 ( V_38 , V_2 ,
V_115 ) ;
goto V_114;
}
F_26 ( V_38 , V_2 , V_116 ) ;
}
}
if ( V_87 > 0 ) {
V_94 = F_20 ( V_2 -> V_63 . V_66 ) + V_87 ;
V_91 = F_29 ( V_2 -> V_63 . V_117 ) ;
V_92 = F_31 ( V_2 -> V_63 . V_118 ) ;
V_93 = V_2 -> V_103 -> V_96 -> V_119 ;
V_89 = F_20 ( V_2 -> V_63 . V_120 ) ;
if ( ! V_89 )
V_89 = V_59 -> V_121 ;
V_90 = F_20 ( V_2 -> V_63 . V_122 ) ;
if ( ! V_90 )
V_90 = V_59 -> V_123 ;
if ( V_89 && V_94 > V_89 ) {
F_26 ( V_38 , V_2 , V_124 ) ;
goto V_114;
}
if ( V_90 && V_94 > V_90 ) {
if ( ( V_91 != 0 && F_36 () > V_91 ) ||
( V_92 != 0 && V_92 >= V_93 ) ) {
F_26 ( V_38 , V_2 ,
V_125 ) ;
goto V_114;
}
F_26 ( V_38 , V_2 , V_126 ) ;
}
}
}
( * V_95 ) += ( V_67 ) V_86 ;
if ( V_87 != 0 )
V_2 -> V_73 += ( V_67 ) V_87 ;
if ( V_1 ) {
ASSERT ( V_1 -> V_20 ) ;
ASSERT ( V_88 & V_127 ) ;
if ( V_86 != 0 )
F_11 ( V_1 , V_2 ,
V_88 & V_127 ,
V_86 ) ;
if ( V_87 != 0 )
F_11 ( V_1 , V_2 ,
V_50 ,
V_87 ) ;
}
ASSERT ( V_2 -> V_71 >= F_20 ( V_2 -> V_63 . V_64 ) ) ;
ASSERT ( V_2 -> V_72 >= F_20 ( V_2 -> V_63 . V_65 ) ) ;
ASSERT ( V_2 -> V_73 >= F_20 ( V_2 -> V_63 . V_66 ) ) ;
F_25 ( V_2 ) ;
return 0 ;
V_114:
F_25 ( V_2 ) ;
if ( V_88 & V_128 )
return V_129 ;
return V_130 ;
}
int
F_37 (
T_1 * V_1 ,
T_6 * V_38 ,
T_2 * V_131 ,
T_2 * V_132 ,
long V_86 ,
long V_87 ,
T_5 V_88 )
{
int V_133 = 0 , error ;
if ( ! F_8 ( V_38 ) || ! F_9 ( V_38 ) )
return 0 ;
if ( V_1 && V_1 -> V_20 == NULL )
F_6 ( V_1 ) ;
ASSERT ( V_88 & V_127 ) ;
if ( V_131 ) {
error = F_30 ( V_1 , V_38 , V_131 , V_86 , V_87 ,
( V_88 & ~ V_128 ) ) ;
if ( error )
return error ;
V_133 = 1 ;
}
if ( V_132 ) {
error = F_30 ( V_1 , V_38 , V_132 , V_86 , V_87 , V_88 ) ;
if ( error ) {
if ( V_133 ) {
V_88 |= V_112 ;
F_30 ( V_1 , V_38 , V_131 ,
- V_86 , - V_87 , V_88 ) ;
}
return error ;
}
}
return 0 ;
}
int
F_38 (
struct V_134 * V_1 ,
struct V_135 * V_35 ,
long V_86 ,
long V_87 ,
T_5 V_88 )
{
struct V_77 * V_38 = V_35 -> V_136 ;
if ( ! F_8 ( V_38 ) || ! F_9 ( V_38 ) )
return 0 ;
if ( F_39 ( V_38 ) )
V_88 |= V_128 ;
ASSERT ( V_35 -> V_40 != V_38 -> V_41 . V_42 ) ;
ASSERT ( V_35 -> V_40 != V_38 -> V_41 . V_43 ) ;
ASSERT ( F_40 ( V_35 , V_137 ) ) ;
ASSERT ( ( V_88 & ~ ( V_112 | V_128 ) ) ==
V_55 ||
( V_88 & ~ ( V_112 | V_128 ) ) ==
V_48 ) ;
return F_37 ( V_1 , V_38 ,
V_35 -> V_44 , V_35 -> V_45 ,
V_86 , V_87 , V_88 ) ;
}
T_12 *
F_41 (
T_1 * V_1 ,
T_12 * V_138 ,
T_5 V_88 )
{
T_12 * V_59 ;
ASSERT ( V_1 != NULL ) ;
V_59 = F_42 ( V_1 -> V_39 , V_138 , V_88 ) ;
ASSERT ( V_59 != NULL ) ;
F_3 ( V_1 , & V_59 -> V_139 ) ;
return V_59 ;
}
void
F_43 (
T_1 * V_1 ,
T_12 * V_140 )
{
V_1 -> V_7 |= V_8 ;
V_140 -> V_139 . V_9 -> V_10 |= V_11 ;
}
STATIC void
F_6 (
T_1 * V_1 )
{
V_1 -> V_20 = F_44 ( V_141 , V_142 ) ;
}
void
F_45 (
T_1 * V_1 )
{
if ( ! V_1 -> V_20 )
return;
F_46 ( V_141 , V_1 -> V_20 ) ;
V_1 -> V_20 = NULL ;
}
