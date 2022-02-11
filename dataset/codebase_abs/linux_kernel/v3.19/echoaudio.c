static int F_1 ( const struct V_1 * * V_2 ,
struct V_3 * V_4 , const short V_5 )
{
int V_6 ;
char V_7 [ 30 ] ;
#ifdef F_2
if ( V_4 -> V_8 [ V_5 ] ) {
F_3 ( V_4 -> V_9 -> V_10 ,
L_1 ,
V_11 [ V_5 ] . V_12 ) ;
* V_2 = V_4 -> V_8 [ V_5 ] ;
return 0 ;
}
#endif
F_3 ( V_4 -> V_9 -> V_10 ,
L_2 , V_11 [ V_5 ] . V_12 ) ;
snprintf ( V_7 , sizeof( V_7 ) , L_3 , V_11 [ V_5 ] . V_12 ) ;
V_6 = F_4 ( V_2 , V_7 , F_5 ( V_4 ) ) ;
if ( V_6 < 0 )
F_6 ( V_4 -> V_9 -> V_10 ,
L_4 , V_6 ) ;
#ifdef F_2
else
V_4 -> V_8 [ V_5 ] = * V_2 ;
#endif
return V_6 ;
}
static void F_7 ( const struct V_1 * V_2 ,
struct V_3 * V_4 )
{
#ifdef F_2
F_3 ( V_4 -> V_9 -> V_10 , L_5 ) ;
#else
F_8 ( V_2 ) ;
#endif
}
static void F_9 ( struct V_3 * V_4 )
{
#ifdef F_2
int V_13 ;
for ( V_13 = 0 ; V_13 < 8 ; V_13 ++ )
if ( V_4 -> V_8 [ V_13 ] ) {
F_8 ( V_4 -> V_8 [ V_13 ] ) ;
F_3 ( V_4 -> V_9 -> V_10 , L_6 , V_13 ) ;
}
#endif
}
static void F_10 ( struct V_14 * V_15 )
{
struct V_16 * V_17 = V_15 -> V_18 ;
if ( V_17 -> V_19 . V_20 )
F_11 ( & V_17 -> V_19 ) ;
F_12 ( V_17 ) ;
}
static int F_13 ( struct V_21 * V_22 ,
struct V_23 * V_24 )
{
struct V_25 * V_26 = F_14 ( V_22 ,
V_27 ) ;
struct V_28 * V_29 = F_15 ( V_22 , V_30 ) ;
struct V_28 V_31 ;
F_16 ( & V_31 ) ;
#ifndef F_17
if ( V_26 -> V_32 == 2 ) {
V_31 . V_33 [ 0 ] &= ~ V_34 ;
return F_18 ( V_29 , & V_31 ) ;
}
#endif
if ( V_26 -> V_32 > 2 ) {
V_31 . V_33 [ 0 ] &= ~ ( V_35 | V_34 ) ;
return F_18 ( V_29 , & V_31 ) ;
}
return 0 ;
}
static int F_19 ( struct V_21 * V_22 ,
struct V_23 * V_24 )
{
struct V_25 * V_26 = F_14 ( V_22 ,
V_27 ) ;
struct V_28 * V_29 = F_15 ( V_22 , V_30 ) ;
struct V_25 V_36 ;
F_20 ( & V_36 ) ;
if ( V_29 -> V_33 [ 0 ] == V_34 ) {
V_36 . V_32 = 1 ;
#ifdef F_17
V_36 . V_37 = 2 ;
#else
V_36 . V_37 = 1 ;
#endif
V_36 . integer = 1 ;
return F_21 ( V_26 , & V_36 ) ;
}
if ( V_29 -> V_33 [ 0 ] == V_35 ) {
V_36 . V_32 = 1 ;
V_36 . V_37 = 2 ;
V_36 . integer = 1 ;
return F_21 ( V_26 , & V_36 ) ;
}
return 0 ;
}
static int F_22 ( struct V_21 * V_22 ,
struct V_23 * V_24 )
{
struct V_25 * V_26 = F_14 ( V_22 ,
V_27 ) ;
struct V_28 * V_29 = F_15 ( V_22 , V_30 ) ;
struct V_28 V_31 ;
T_1 V_38 ;
F_16 ( & V_31 ) ;
V_38 = V_31 . V_33 [ 0 ] + ( ( T_1 ) V_31 . V_33 [ 1 ] << 32 ) ;
if ( V_26 -> V_32 > 2 ) {
V_38 &= V_39 |
V_40 |
V_41 ;
} else if ( V_26 -> V_37 == 1 )
V_38 &= V_41 | V_34 ;
#ifndef F_17
else if ( V_26 -> V_32 == 2 && V_26 -> V_37 == 2 )
V_38 &= ~ V_34 ;
#endif
else
return 0 ;
V_31 . V_33 [ 0 ] &= ( V_42 ) V_38 ;
V_31 . V_33 [ 1 ] &= ( V_42 ) ( V_38 >> 32 ) ;
return F_18 ( V_29 , & V_31 ) ;
}
static int F_23 ( struct V_21 * V_22 ,
struct V_23 * V_24 )
{
struct V_25 * V_26 = F_14 ( V_22 ,
V_27 ) ;
struct V_28 * V_29 = F_15 ( V_22 , V_30 ) ;
struct V_25 V_36 ;
T_1 V_38 ;
F_20 ( & V_36 ) ;
V_36 . integer = 1 ;
V_38 = V_29 -> V_33 [ 0 ] + ( ( T_1 ) V_29 -> V_33 [ 1 ] << 32 ) ;
if ( V_38 == V_34 ) {
V_36 . V_32 = 1 ;
#ifdef F_17
V_36 . V_37 = 2 ;
#else
V_36 . V_37 = 1 ;
#endif
} else if ( V_38 == V_35 )
V_36 . V_32 = V_36 . V_37 = 2 ;
else if ( ! ( V_38 & ~ ( V_39 |
V_40 ) ) )
V_36 . V_32 = 2 ;
else
return 0 ;
return F_21 ( V_26 , & V_36 ) ;
}
static int F_24 ( struct V_21 * V_22 ,
struct V_23 * V_24 )
{
struct V_25 * V_43 = F_14 ( V_22 ,
V_44 ) ;
struct V_3 * V_4 = V_24 -> V_45 ;
struct V_25 V_46 ;
if ( ! V_4 -> V_47 ) {
F_20 ( & V_46 ) ;
V_46 . V_32 = V_46 . V_37 = V_4 -> V_48 ;
return F_21 ( V_43 , & V_46 ) ;
}
return 0 ;
}
static int F_25 ( struct V_49 * V_50 ,
signed char V_51 )
{
struct V_3 * V_4 ;
struct V_14 * V_15 ;
struct V_16 * V_17 ;
int V_6 , V_13 ;
if ( V_51 <= 0 )
return - V_52 ;
V_4 = F_26 ( V_50 ) ;
V_15 = V_50 -> V_15 ;
V_17 = F_27 ( sizeof( struct V_16 ) , V_53 ) ;
if ( ! V_17 )
return - V_54 ;
V_17 -> V_55 = - 1 ;
memcpy ( & V_17 -> V_56 , & V_57 , sizeof( struct V_58 ) ) ;
F_3 ( V_4 -> V_9 -> V_10 , L_7 , V_51 ) ;
V_17 -> V_59 . V_60 = V_61 ;
V_17 -> V_59 . V_62 = 0 ;
for ( V_13 = 0 ; V_61 [ V_13 ] <= V_51 ; V_13 ++ ) ;
V_17 -> V_59 . V_63 = V_13 ;
if ( V_17 -> V_56 . V_64 > V_51 )
V_17 -> V_56 . V_64 = V_51 ;
if ( V_4 -> V_65 == V_66 ) {
V_17 -> V_56 . V_67 = 48000 ;
V_17 -> V_56 . V_68 &= V_69 ;
}
V_15 -> V_56 = V_17 -> V_56 ;
V_15 -> V_18 = V_17 ;
V_15 -> V_70 = F_10 ;
F_28 ( V_50 ) ;
if ( ( V_6 = F_29 ( V_15 , 0 ,
V_27 ,
& V_17 -> V_59 ) ) < 0 )
return V_6 ;
if ( ( V_6 = F_30 ( V_15 ,
V_71 ) ) < 0 )
return V_6 ;
if ( ( V_6 = F_31 ( V_15 , 0 ,
V_72 ,
32 ) ) < 0 )
return V_6 ;
if ( ( V_6 = F_31 ( V_15 , 0 ,
V_73 ,
32 ) ) < 0 )
return V_6 ;
if ( ( V_6 = F_32 ( V_50 -> V_15 , 0 ,
V_44 ,
F_24 , V_4 ,
V_44 , - 1 ) ) < 0 )
return V_6 ;
if ( ( V_6 = F_33 ( V_74 ,
F_34 ( V_4 -> V_75 ) ,
V_76 , & V_17 -> V_19 ) ) < 0 ) {
F_6 ( V_4 -> V_9 -> V_10 , L_8 ) ;
return V_6 ;
}
return 0 ;
}
static int F_35 ( struct V_49 * V_50 )
{
struct V_3 * V_4 = F_26 ( V_50 ) ;
int V_6 ;
if ( ( V_6 = F_25 ( V_50 , F_36 ( V_4 ) -
V_50 -> V_77 ) ) < 0 )
return V_6 ;
if ( ( V_6 = F_32 ( V_50 -> V_15 , 0 ,
V_27 ,
F_19 , NULL ,
V_30 , - 1 ) ) < 0 )
return V_6 ;
if ( ( V_6 = F_32 ( V_50 -> V_15 , 0 ,
V_30 ,
F_13 , NULL ,
V_27 , - 1 ) ) < 0 )
return V_6 ;
F_37 ( & V_4 -> V_78 ) ;
if ( F_38 ( & V_4 -> V_78 ) > 1 && V_4 -> V_79 )
V_4 -> V_47 = 0 ;
F_3 ( V_4 -> V_9 -> V_10 , L_9 ,
V_4 -> V_47 , F_38 ( & V_4 -> V_78 ) ,
V_4 -> V_48 ) ;
return 0 ;
}
static int F_39 ( struct V_49 * V_50 )
{
struct V_3 * V_4 = F_26 ( V_50 ) ;
int V_51 , V_6 ;
#ifdef F_40
V_51 = F_41 ( V_4 ) ;
#else
V_51 = F_42 ( V_4 ) ;
#endif
if ( ( V_6 = F_25 ( V_50 , V_51 - V_50 -> V_77 ) ) < 0 )
return V_6 ;
if ( ( V_6 = F_32 ( V_50 -> V_15 , 0 ,
V_27 ,
F_23 ,
NULL ,
V_30 , - 1 ) ) < 0 )
return V_6 ;
if ( ( V_6 = F_32 ( V_50 -> V_15 , 0 ,
V_30 ,
F_22 ,
NULL ,
V_27 , - 1 ) ) < 0 )
return V_6 ;
F_37 ( & V_4 -> V_78 ) ;
if ( F_38 ( & V_4 -> V_78 ) > 1 && V_4 -> V_79 )
V_4 -> V_47 = 0 ;
F_3 ( V_4 -> V_9 -> V_10 , L_10 ,
V_4 -> V_47 , F_38 ( & V_4 -> V_78 ) ,
V_4 -> V_48 ) ;
return 0 ;
}
static int F_43 ( struct V_49 * V_50 )
{
struct V_3 * V_4 = F_26 ( V_50 ) ;
int V_6 , V_51 ;
V_51 = F_44 ( V_4 ) - V_50 -> V_77 ;
F_45 ( & V_4 -> V_80 ) ;
if ( V_4 -> V_65 == V_66 )
V_6 = F_25 ( V_50 , V_51 ) ;
else
V_6 = F_25 ( V_50 , V_51 - V_81 ) ;
if ( V_6 < 0 )
goto V_82;
if ( ( V_6 = F_32 ( V_50 -> V_15 , 0 ,
V_27 ,
F_19 , NULL ,
V_30 , - 1 ) ) < 0 )
goto V_82;
if ( ( V_6 = F_32 ( V_50 -> V_15 , 0 ,
V_30 ,
F_13 , NULL ,
V_27 , - 1 ) ) < 0 )
goto V_82;
F_37 ( & V_4 -> V_78 ) ;
if ( F_38 ( & V_4 -> V_78 ) > 1 && V_4 -> V_79 )
V_4 -> V_47 = 0 ;
V_82:
F_46 ( & V_4 -> V_80 ) ;
return V_6 ;
}
static int F_47 ( struct V_49 * V_50 )
{
struct V_3 * V_4 = F_26 ( V_50 ) ;
int V_6 , V_51 ;
V_51 = F_48 ( V_4 ) - V_50 -> V_77 ;
F_45 ( & V_4 -> V_80 ) ;
if ( V_4 -> V_65 == V_66 )
V_6 = F_25 ( V_50 , V_51 ) ;
else
V_6 = F_25 ( V_50 , V_51 - V_81 ) ;
if ( V_6 < 0 )
goto V_83;
if ( ( V_6 = F_32 ( V_50 -> V_15 , 0 ,
V_27 ,
F_23 ,
NULL , V_30 ,
- 1 ) ) < 0 )
goto V_83;
if ( ( V_6 = F_32 ( V_50 -> V_15 , 0 ,
V_30 ,
F_22 ,
NULL , V_27 ,
- 1 ) ) < 0 )
goto V_83;
F_37 ( & V_4 -> V_78 ) ;
if ( F_38 ( & V_4 -> V_78 ) > 1 && V_4 -> V_79 )
V_4 -> V_47 = 0 ;
V_83:
F_46 ( & V_4 -> V_80 ) ;
return V_6 ;
}
static int F_49 ( struct V_49 * V_50 )
{
struct V_3 * V_4 = F_26 ( V_50 ) ;
int V_84 ;
F_50 ( & V_4 -> V_78 ) ;
V_84 = F_38 ( & V_4 -> V_78 ) ;
F_3 ( V_4 -> V_9 -> V_10 , L_11 , V_84 ,
V_4 -> V_47 , V_4 -> V_79 ) ;
if ( V_84 < 2 )
V_4 -> V_47 = 1 ;
if ( V_84 == 0 )
V_4 -> V_79 = 0 ;
F_3 ( V_4 -> V_9 -> V_10 , L_12 , V_84 ,
V_4 -> V_47 , V_4 -> V_79 ) ;
return 0 ;
}
static int F_51 ( struct V_49 * V_50 ,
struct V_21 * V_85 ,
int V_86 , int V_87 )
{
struct V_3 * V_4 ;
int V_6 , V_88 , V_89 , V_90 , V_91 , V_92 ;
struct V_16 * V_17 ;
V_4 = F_26 ( V_50 ) ;
V_17 = (struct V_16 * ) V_50 -> V_15 -> V_18 ;
F_52 ( & V_4 -> V_93 ) ;
if ( V_17 -> V_55 >= 0 ) {
F_3 ( V_4 -> V_9 -> V_10 , L_13 , V_17 -> V_55 ) ;
V_6 = F_53 ( V_4 , V_17 ) ;
F_54 ( V_6 ) ;
V_4 -> V_50 [ V_17 -> V_55 ] = NULL ;
}
V_6 = F_55 ( V_4 , V_17 , V_86 , V_87 ) ;
if ( V_6 < 0 ) {
F_56 ( & V_4 -> V_93 ) ;
F_6 ( V_4 -> V_9 -> V_10 , L_14 ,
V_86 , V_6 ) ;
return V_6 ;
}
F_56 ( & V_4 -> V_93 ) ;
F_3 ( V_4 -> V_9 -> V_10 , L_15 , V_86 ) ;
F_3 ( V_4 -> V_9 -> V_10 ,
L_16 ,
F_57 ( V_85 ) , F_58 ( V_85 ) ,
F_59 ( V_85 ) ) ;
V_6 = F_60 ( V_50 ,
F_57 ( V_85 ) ) ;
if ( V_6 < 0 ) {
F_6 ( V_4 -> V_9 -> V_10 , L_17 , V_6 ) ;
F_52 ( & V_4 -> V_93 ) ;
F_53 ( V_4 , V_17 ) ;
F_56 ( & V_4 -> V_93 ) ;
V_17 -> V_55 = - 1 ;
return V_6 ;
}
F_61 ( V_4 , V_17 ) ;
V_91 = V_76 ;
for ( V_92 = V_90 = V_88 = 0 ; V_92 < F_57 ( V_85 ) ;
V_88 ++ ) {
V_89 = F_59 ( V_85 ) ;
if ( V_92 + V_89 > F_57 ( V_85 ) )
V_89 = F_57 ( V_85 ) - V_92 ;
while ( V_89 ) {
T_2 V_94 ;
V_94 = F_62 ( V_50 , V_92 ) ;
if ( V_89 <= V_91 - V_92 ) {
F_63 ( V_4 , V_17 , V_94 , V_89 ) ;
F_64 ( V_4 , V_17 ) ;
V_92 += V_89 ;
V_89 = 0 ;
} else {
F_63 ( V_4 , V_17 , V_94 ,
V_91 - V_92 ) ;
V_89 -= V_91 - V_92 ;
V_92 = V_91 ;
}
if ( V_92 == V_91 ) {
V_91 += V_76 ;
V_90 ++ ;
}
}
}
F_65 ( V_4 , V_17 ) ;
V_4 -> V_95 [ V_86 ] = 0 ;
V_17 -> V_96 = 0 ;
V_17 -> V_97 = 0 ;
F_66 () ;
V_4 -> V_50 [ V_86 ] = V_50 ;
V_4 -> V_79 = 1 ;
F_52 ( & V_4 -> V_93 ) ;
F_67 ( V_4 , V_85 -> V_98 / V_85 -> V_99 ) ;
F_56 ( & V_4 -> V_93 ) ;
return 0 ;
}
static int F_68 ( struct V_49 * V_50 ,
struct V_21 * V_85 )
{
struct V_3 * V_4 = F_26 ( V_50 ) ;
return F_51 ( V_50 , V_85 , F_69 ( V_4 ) +
V_50 -> V_77 , F_70 ( V_85 ) ) ;
}
static int F_71 ( struct V_49 * V_50 ,
struct V_21 * V_85 )
{
return F_51 ( V_50 , V_85 , V_50 -> V_77 ,
F_70 ( V_85 ) ) ;
}
static int F_72 ( struct V_49 * V_50 ,
struct V_21 * V_85 )
{
struct V_3 * V_4 = F_26 ( V_50 ) ;
return F_51 ( V_50 , V_85 , F_73 ( V_4 ) +
V_50 -> V_77 , F_70 ( V_85 ) ) ;
}
static int F_74 ( struct V_49 * V_50 ,
struct V_21 * V_85 )
{
struct V_3 * V_4 = F_26 ( V_50 ) ;
return F_51 ( V_50 , V_85 , F_75 ( V_4 ) +
V_50 -> V_77 , F_70 ( V_85 ) ) ;
}
static int F_76 ( struct V_49 * V_50 )
{
struct V_3 * V_4 ;
struct V_16 * V_17 ;
V_4 = F_26 ( V_50 ) ;
V_17 = (struct V_16 * ) V_50 -> V_15 -> V_18 ;
F_52 ( & V_4 -> V_93 ) ;
if ( V_17 -> V_55 >= 0 ) {
F_3 ( V_4 -> V_9 -> V_10 , L_18 , V_17 -> V_55 ) ;
F_53 ( V_4 , V_17 ) ;
V_4 -> V_50 [ V_17 -> V_55 ] = NULL ;
V_17 -> V_55 = - 1 ;
}
F_56 ( & V_4 -> V_93 ) ;
F_77 ( V_50 ) ;
return 0 ;
}
static int F_78 ( struct V_49 * V_50 )
{
struct V_3 * V_4 = F_26 ( V_50 ) ;
struct V_14 * V_15 = V_50 -> V_15 ;
struct V_100 V_101 ;
int V_86 = ( (struct V_16 * ) V_15 -> V_18 ) -> V_55 ;
F_3 ( V_4 -> V_9 -> V_10 , L_19 ,
V_15 -> V_43 , V_15 -> V_101 , V_15 -> V_102 ) ;
V_101 . V_87 = V_15 -> V_102 ;
V_101 . V_103 = 0 ;
V_101 . V_104 = 0 ;
switch ( V_15 -> V_101 ) {
case V_105 :
V_101 . V_106 = 8 ;
break;
case V_107 :
V_101 . V_106 = 16 ;
break;
case V_108 :
V_101 . V_106 = 24 ;
break;
case V_109 :
V_101 . V_103 = 1 ;
case V_110 :
V_101 . V_106 = 32 ;
break;
default:
F_6 ( V_4 -> V_9 -> V_10 ,
L_20 ,
V_15 -> V_101 ) ;
return - V_111 ;
}
if ( F_54 ( V_86 >= F_79 ( V_4 ) ) )
return - V_111 ;
if ( F_54 ( ! F_80 ( V_4 , V_86 ) ) )
return - V_111 ;
F_81 ( V_4 , V_86 , & V_101 ) ;
return 0 ;
}
static int F_82 ( struct V_49 * V_50 , int V_112 )
{
struct V_3 * V_4 = F_26 ( V_50 ) ;
struct V_14 * V_15 = V_50 -> V_15 ;
struct V_16 * V_17 = V_15 -> V_18 ;
int V_13 , V_6 ;
V_42 V_113 = 0 ;
struct V_49 * V_114 ;
F_83 (s, substream) {
for ( V_13 = 0 ; V_13 < V_115 ; V_13 ++ ) {
if ( V_114 == V_4 -> V_50 [ V_13 ] ) {
V_113 |= 1 << V_13 ;
F_84 ( V_114 , V_50 ) ;
}
}
}
F_85 ( & V_4 -> V_93 ) ;
switch ( V_112 ) {
case V_116 :
case V_117 :
case V_118 :
for ( V_13 = 0 ; V_13 < V_115 ; V_13 ++ ) {
if ( V_113 & ( 1 << V_13 ) ) {
V_17 = V_4 -> V_50 [ V_13 ] -> V_15 -> V_18 ;
switch ( V_17 -> V_119 ) {
case V_120 :
V_4 -> V_95 [ V_13 ] = 0 ;
V_17 -> V_96 = 0 ;
V_17 -> V_97 = 0 ;
* V_17 -> V_121 = 0 ;
case V_122 :
V_17 -> V_119 = V_123 ;
break;
case V_123 :
break;
}
}
}
V_6 = F_86 ( V_4 , V_113 ,
V_4 -> V_124 ) ;
break;
case V_125 :
case V_126 :
for ( V_13 = 0 ; V_13 < V_115 ; V_13 ++ ) {
if ( V_113 & ( 1 << V_13 ) ) {
V_17 = V_4 -> V_50 [ V_13 ] -> V_15 -> V_18 ;
V_17 -> V_119 = V_120 ;
}
}
V_6 = F_87 ( V_4 , V_113 ) ;
break;
case V_127 :
for ( V_13 = 0 ; V_13 < V_115 ; V_13 ++ ) {
if ( V_113 & ( 1 << V_13 ) ) {
V_17 = V_4 -> V_50 [ V_13 ] -> V_15 -> V_18 ;
V_17 -> V_119 = V_122 ;
}
}
V_6 = F_88 ( V_4 , V_113 ) ;
break;
default:
V_6 = - V_111 ;
}
F_89 ( & V_4 -> V_93 ) ;
return V_6 ;
}
static T_3 F_90 ( struct V_49 * V_50 )
{
struct V_14 * V_15 = V_50 -> V_15 ;
struct V_16 * V_17 = V_15 -> V_18 ;
T_4 V_128 , V_129 , V_130 ;
V_128 = F_91 ( * V_17 -> V_121 ) ;
V_17 -> V_97 += V_128 - V_17 -> V_96 ;
V_17 -> V_96 = V_128 ;
V_129 = V_50 -> V_15 -> V_131 ;
V_130 = F_92 ( V_50 -> V_15 , V_17 -> V_97 ) ;
while ( V_130 >= V_129 ) {
V_17 -> V_97 -= F_93 ( V_50 -> V_15 , V_129 ) ;
V_130 -= V_129 ;
}
return V_130 ;
}
static int F_94 ( struct V_132 * V_133 , struct V_134 * V_10 )
{
struct V_49 * V_135 ;
int V_136 , V_6 ;
for ( V_136 = 0 ; V_136 < 2 ; V_136 ++ )
for ( V_135 = V_133 -> V_137 [ V_136 ] . V_50 ; V_135 ; V_135 = V_135 -> V_138 ) {
V_6 = F_95 ( V_135 , V_139 ,
V_10 ,
V_135 -> V_77 ? 0 : 128 << 10 ,
256 << 10 ) ;
if ( V_6 < 0 )
return V_6 ;
}
return 0 ;
}
static int F_96 ( struct V_3 * V_4 )
{
struct V_132 * V_133 ;
int V_6 ;
#ifdef F_40
if ( ( V_6 = F_97 ( V_4 -> V_9 , L_21 , 0 , F_41 ( V_4 ) ,
F_36 ( V_4 ) , & V_133 ) ) < 0 )
return V_6 ;
V_133 -> V_18 = V_4 ;
V_4 -> V_140 = V_133 ;
strcpy ( V_133 -> V_7 , V_4 -> V_9 -> V_141 ) ;
F_98 ( V_133 , V_142 , & V_143 ) ;
F_98 ( V_133 , V_144 , & V_145 ) ;
if ( ( V_6 = F_94 ( V_133 , F_34 ( V_4 -> V_75 ) ) ) < 0 )
return V_6 ;
#ifdef F_99
if ( ( V_6 = F_97 ( V_4 -> V_9 , L_22 , 1 , 0 ,
F_44 ( V_4 ) , & V_133 ) ) < 0 )
return V_6 ;
V_133 -> V_18 = V_4 ;
V_4 -> V_146 = V_133 ;
strcpy ( V_133 -> V_7 , V_4 -> V_9 -> V_141 ) ;
F_98 ( V_133 , V_144 , & V_147 ) ;
if ( ( V_6 = F_94 ( V_133 , F_34 ( V_4 -> V_75 ) ) ) < 0 )
return V_6 ;
#endif
#else
if ( ( V_6 = F_97 ( V_4 -> V_9 , L_23 , 0 ,
F_42 ( V_4 ) ,
F_36 ( V_4 ) , & V_133 ) ) < 0 )
return V_6 ;
V_133 -> V_18 = V_4 ;
V_4 -> V_140 = V_133 ;
strcpy ( V_133 -> V_7 , V_4 -> V_9 -> V_141 ) ;
F_98 ( V_133 , V_142 , & V_143 ) ;
F_98 ( V_133 , V_144 , & V_145 ) ;
if ( ( V_6 = F_94 ( V_133 , F_34 ( V_4 -> V_75 ) ) ) < 0 )
return V_6 ;
#ifdef F_99
if ( ( V_6 = F_97 ( V_4 -> V_9 , L_22 , 1 ,
F_48 ( V_4 ) ,
F_44 ( V_4 ) , & V_133 ) ) < 0 )
return V_6 ;
V_133 -> V_18 = V_4 ;
V_4 -> V_146 = V_133 ;
strcpy ( V_133 -> V_7 , V_4 -> V_9 -> V_141 ) ;
F_98 ( V_133 , V_142 , & V_148 ) ;
F_98 ( V_133 , V_144 , & V_147 ) ;
if ( ( V_6 = F_94 ( V_133 , F_34 ( V_4 -> V_75 ) ) ) < 0 )
return V_6 ;
#endif
#endif
return 0 ;
}
static int F_100 ( struct V_149 * V_150 ,
struct V_151 * V_152 )
{
struct V_3 * V_4 ;
V_4 = F_101 ( V_150 ) ;
V_152 -> type = V_153 ;
V_152 -> V_63 = F_102 ( V_4 ) ;
V_152 -> V_154 . integer . V_32 = V_155 ;
V_152 -> V_154 . integer . V_37 = V_156 ;
return 0 ;
}
static int F_103 ( struct V_149 * V_150 ,
struct V_157 * V_158 )
{
struct V_3 * V_4 ;
int V_26 ;
V_4 = F_101 ( V_150 ) ;
for ( V_26 = 0 ; V_26 < F_102 ( V_4 ) ; V_26 ++ )
V_158 -> V_154 . integer . V_154 [ V_26 ] = V_4 -> V_159 [ V_26 ] ;
return 0 ;
}
static int F_104 ( struct V_149 * V_150 ,
struct V_157 * V_158 )
{
struct V_3 * V_4 ;
int V_26 , V_160 , V_161 ;
V_160 = 0 ;
V_4 = F_101 ( V_150 ) ;
F_52 ( & V_4 -> V_93 ) ;
for ( V_26 = 0 ; V_26 < F_102 ( V_4 ) ; V_26 ++ ) {
V_161 = V_158 -> V_154 . integer . V_154 [ V_26 ] ;
if ( V_161 < V_155 || V_161 > V_156 )
continue;
if ( V_4 -> V_159 [ V_26 ] != V_161 ) {
F_105 ( V_4 , V_26 , V_161 ) ;
V_160 = 1 ;
}
}
if ( V_160 )
F_106 ( V_4 ) ;
F_56 ( & V_4 -> V_93 ) ;
return V_160 ;
}
static int F_107 ( struct V_149 * V_150 ,
struct V_151 * V_152 )
{
struct V_3 * V_4 ;
V_4 = F_101 ( V_150 ) ;
V_152 -> type = V_153 ;
V_152 -> V_63 = F_36 ( V_4 ) ;
V_152 -> V_154 . integer . V_32 = V_162 ;
V_152 -> V_154 . integer . V_37 = V_163 ;
return 0 ;
}
static int F_108 ( struct V_149 * V_150 ,
struct V_157 * V_158 )
{
struct V_3 * V_4 ;
int V_26 ;
V_4 = F_101 ( V_150 ) ;
for ( V_26 = 0 ; V_26 < F_36 ( V_4 ) ; V_26 ++ )
V_158 -> V_154 . integer . V_154 [ V_26 ] = V_4 -> V_164 [ V_26 ] ;
return 0 ;
}
static int F_109 ( struct V_149 * V_150 ,
struct V_157 * V_158 )
{
struct V_3 * V_4 ;
int V_26 , V_161 , V_160 ;
V_160 = 0 ;
V_4 = F_101 ( V_150 ) ;
F_52 ( & V_4 -> V_93 ) ;
for ( V_26 = 0 ; V_26 < F_36 ( V_4 ) ; V_26 ++ ) {
V_161 = V_158 -> V_154 . integer . V_154 [ V_26 ] ;
if ( V_161 < V_162 || V_161 > V_163 )
continue;
if ( V_4 -> V_164 [ V_26 ] != V_161 ) {
F_110 ( V_4 , V_26 , V_161 ) ;
V_160 = 1 ;
}
}
if ( V_160 )
F_111 ( V_4 ) ;
F_56 ( & V_4 -> V_93 ) ;
return V_160 ;
}
static int F_112 ( struct V_149 * V_150 ,
struct V_151 * V_152 )
{
struct V_3 * V_4 ;
V_4 = F_101 ( V_150 ) ;
V_152 -> type = V_165 ;
V_152 -> V_63 = F_42 ( V_4 ) ;
V_152 -> V_154 . integer . V_32 = 0 ;
V_152 -> V_154 . integer . V_37 = 1 ;
return 0 ;
}
static int F_113 ( struct V_149 * V_150 ,
struct V_157 * V_158 )
{
struct V_3 * V_4 ;
int V_26 ;
V_4 = F_101 ( V_150 ) ;
for ( V_26 = 0 ; V_26 < F_42 ( V_4 ) ; V_26 ++ )
V_158 -> V_154 . integer . V_154 [ V_26 ] = V_4 -> V_166 [ V_26 ] ;
return 0 ;
}
static int F_114 ( struct V_149 * V_150 ,
struct V_157 * V_158 )
{
struct V_3 * V_4 ;
int V_26 , V_160 ;
V_160 = 0 ;
V_4 = F_101 ( V_150 ) ;
F_52 ( & V_4 -> V_93 ) ;
for ( V_26 = 0 ; V_26 < F_42 ( V_4 ) ; V_26 ++ ) {
if ( V_4 -> V_166 [ V_26 ] != V_158 -> V_154 . integer . V_154 [ V_26 ] ) {
F_115 ( V_4 , V_26 ,
V_158 -> V_154 . integer . V_154 [ V_26 ] ) ;
V_160 = 1 ;
}
}
if ( V_160 )
F_106 ( V_4 ) ;
F_56 ( & V_4 -> V_93 ) ;
return V_160 ;
}
static int F_116 ( struct V_149 * V_150 ,
struct V_151 * V_152 )
{
struct V_3 * V_4 ;
V_4 = F_101 ( V_150 ) ;
V_152 -> type = V_165 ;
V_152 -> V_63 = F_36 ( V_4 ) ;
V_152 -> V_154 . integer . V_32 = 0 ;
V_152 -> V_154 . integer . V_37 = 1 ;
return 0 ;
}
static int F_117 ( struct V_149 * V_150 ,
struct V_157 * V_158 )
{
struct V_3 * V_4 ;
int V_26 ;
V_4 = F_101 ( V_150 ) ;
for ( V_26 = 0 ; V_26 < F_36 ( V_4 ) ; V_26 ++ )
V_158 -> V_154 . integer . V_154 [ V_26 ] =
V_4 -> V_166 [ F_118 ( V_4 ) + V_26 ] ;
return 0 ;
}
static int F_119 ( struct V_149 * V_150 ,
struct V_157 * V_158 )
{
struct V_3 * V_4 ;
int V_26 , V_160 ;
V_160 = 0 ;
V_4 = F_101 ( V_150 ) ;
F_52 ( & V_4 -> V_93 ) ;
for ( V_26 = 0 ; V_26 < F_36 ( V_4 ) ; V_26 ++ ) {
if ( V_4 -> V_166 [ F_118 ( V_4 ) + V_26 ] !=
V_158 -> V_154 . integer . V_154 [ V_26 ] ) {
F_115 ( V_4 , F_118 ( V_4 ) + V_26 ,
V_158 -> V_154 . integer . V_154 [ V_26 ] ) ;
V_160 = 1 ;
}
}
if ( V_160 )
F_106 ( V_4 ) ;
F_56 ( & V_4 -> V_93 ) ;
return V_160 ;
}
static int F_120 ( struct V_149 * V_150 ,
struct V_151 * V_152 )
{
struct V_3 * V_4 ;
V_4 = F_101 ( V_150 ) ;
V_152 -> type = V_153 ;
V_152 -> V_63 = 1 ;
V_152 -> V_154 . integer . V_32 = V_155 ;
V_152 -> V_154 . integer . V_37 = V_156 ;
V_152 -> V_167 . V_168 [ 0 ] = F_102 ( V_4 ) ;
V_152 -> V_167 . V_168 [ 1 ] = F_121 ( V_4 ) ;
return 0 ;
}
static int F_122 ( struct V_149 * V_150 ,
struct V_157 * V_158 )
{
struct V_3 * V_4 ;
V_4 = F_101 ( V_150 ) ;
V_158 -> V_154 . integer . V_154 [ 0 ] =
V_4 -> V_169 [ V_158 -> V_170 . V_55 / F_121 ( V_4 ) ]
[ V_158 -> V_170 . V_55 % F_121 ( V_4 ) ] ;
return 0 ;
}
static int F_123 ( struct V_149 * V_150 ,
struct V_157 * V_158 )
{
struct V_3 * V_4 ;
int V_160 , V_161 ;
short V_171 , V_172 ;
V_160 = 0 ;
V_4 = F_101 ( V_150 ) ;
V_171 = V_158 -> V_170 . V_55 / F_121 ( V_4 ) ;
V_172 = V_158 -> V_170 . V_55 % F_121 ( V_4 ) ;
V_161 = V_158 -> V_154 . integer . V_154 [ 0 ] ;
if ( V_161 < V_155 || V_161 > V_156 )
return - V_111 ;
if ( V_4 -> V_169 [ V_171 ] [ V_172 ] != V_161 ) {
F_52 ( & V_4 -> V_93 ) ;
F_124 ( V_4 , V_171 , V_172 , V_161 ) ;
F_106 ( V_4 ) ;
F_56 ( & V_4 -> V_93 ) ;
V_160 = 1 ;
}
return V_160 ;
}
static int F_125 ( struct V_149 * V_150 ,
struct V_151 * V_152 )
{
struct V_3 * V_4 ;
V_4 = F_101 ( V_150 ) ;
V_152 -> type = V_153 ;
V_152 -> V_63 = 1 ;
V_152 -> V_154 . integer . V_32 = V_155 ;
V_152 -> V_154 . integer . V_37 = V_156 ;
V_152 -> V_167 . V_168 [ 0 ] = F_102 ( V_4 ) ;
V_152 -> V_167 . V_168 [ 1 ] = F_41 ( V_4 ) ;
return 0 ;
}
static int F_126 ( struct V_149 * V_150 ,
struct V_157 * V_158 )
{
struct V_3 * V_4 ;
V_4 = F_101 ( V_150 ) ;
V_158 -> V_154 . integer . V_154 [ 0 ] =
V_4 -> V_173 [ V_158 -> V_170 . V_55 / F_41 ( V_4 ) ]
[ V_158 -> V_170 . V_55 % F_41 ( V_4 ) ] ;
return 0 ;
}
static int F_127 ( struct V_149 * V_150 ,
struct V_157 * V_158 )
{
struct V_3 * V_4 ;
int V_161 , V_160 ;
short V_174 , V_171 ;
V_160 = 0 ;
V_4 = F_101 ( V_150 ) ;
V_171 = V_158 -> V_170 . V_55 / F_41 ( V_4 ) ;
V_174 = V_158 -> V_170 . V_55 % F_41 ( V_4 ) ;
V_161 = V_158 -> V_154 . integer . V_154 [ 0 ] ;
if ( V_161 < V_155 || V_161 > V_156 )
return - V_111 ;
if ( V_4 -> V_173 [ V_171 ] [ V_174 ] != V_158 -> V_154 . integer . V_154 [ 0 ] ) {
F_52 ( & V_4 -> V_93 ) ;
F_128 ( V_4 , V_171 , V_174 , V_158 -> V_154 . integer . V_154 [ 0 ] ) ;
F_129 ( V_4 ) ;
F_56 ( & V_4 -> V_93 ) ;
V_160 = 1 ;
}
return V_160 ;
}
static int F_130 ( struct V_149 * V_150 ,
struct V_151 * V_152 )
{
static const char * const V_175 [ 4 ] = {
L_24 , L_25 , L_26 ,
L_27
} ;
struct V_3 * V_4 ;
V_4 = F_101 ( V_150 ) ;
return F_131 ( V_152 , 1 , V_4 -> V_176 , V_175 ) ;
}
static int F_132 ( struct V_149 * V_150 ,
struct V_157 * V_158 )
{
struct V_3 * V_4 ;
int V_13 , V_177 ;
V_4 = F_101 ( V_150 ) ;
V_177 = V_4 -> V_65 ;
for ( V_13 = V_4 -> V_176 - 1 ; V_13 >= 0 ; V_13 -- )
if ( V_177 == V_4 -> V_178 [ V_13 ] ) {
V_158 -> V_154 . V_179 . V_180 [ 0 ] = V_13 ;
break;
}
return 0 ;
}
static int F_133 ( struct V_149 * V_150 ,
struct V_157 * V_158 )
{
struct V_3 * V_4 ;
int V_160 ;
unsigned short V_181 , V_182 ;
V_160 = 0 ;
V_4 = F_101 ( V_150 ) ;
V_181 = V_158 -> V_154 . V_179 . V_180 [ 0 ] ;
if ( V_181 >= V_4 -> V_176 )
return - V_111 ;
V_182 = V_4 -> V_178 [ V_181 ] ;
if ( V_182 != V_4 -> V_65 ) {
F_45 ( & V_4 -> V_80 ) ;
if ( F_38 ( & V_4 -> V_78 ) ) {
V_160 = - V_52 ;
} else {
V_160 = F_134 ( V_4 , V_182 ) ;
if ( V_160 > 0 && V_4 -> V_183 ) {
F_135 ( V_4 -> V_9 ,
V_184 ,
& V_4 -> V_183 -> V_170 ) ;
F_3 ( V_4 -> V_9 -> V_10 ,
L_28 , V_160 ) ;
}
if ( V_160 >= 0 )
V_160 = 1 ;
}
F_46 ( & V_4 -> V_80 ) ;
}
return V_160 ;
}
static int F_136 ( struct V_149 * V_150 ,
struct V_151 * V_152 )
{
static const char * const V_175 [ 2 ] = { L_29 , L_30 } ;
return F_131 ( V_152 , 1 , 2 , V_175 ) ;
}
static int F_137 ( struct V_149 * V_150 ,
struct V_157 * V_158 )
{
struct V_3 * V_4 ;
V_4 = F_101 ( V_150 ) ;
V_158 -> V_154 . V_179 . V_180 [ 0 ] = ! ! V_4 -> V_185 ;
return 0 ;
}
static int F_138 ( struct V_149 * V_150 ,
struct V_157 * V_158 )
{
struct V_3 * V_4 ;
int V_177 ;
V_4 = F_101 ( V_150 ) ;
V_177 = ! ! V_158 -> V_154 . V_179 . V_180 [ 0 ] ;
if ( V_177 != V_4 -> V_185 ) {
F_52 ( & V_4 -> V_93 ) ;
F_139 ( V_4 , V_177 ) ;
F_56 ( & V_4 -> V_93 ) ;
return 1 ;
}
return 0 ;
}
static int F_140 ( struct V_149 * V_150 ,
struct V_151 * V_152 )
{
static const char * const V_175 [ 8 ] = {
L_31 , L_32 , L_33 , L_34 , L_35 , L_36 ,
L_37 , L_38
} ;
struct V_3 * V_4 ;
V_4 = F_101 ( V_150 ) ;
return F_131 ( V_152 , 1 , V_4 -> V_186 , V_175 ) ;
}
static int F_141 ( struct V_149 * V_150 ,
struct V_157 * V_158 )
{
struct V_3 * V_4 ;
int V_13 , clock ;
V_4 = F_101 ( V_150 ) ;
clock = V_4 -> V_187 ;
for ( V_13 = 0 ; V_13 < V_4 -> V_186 ; V_13 ++ )
if ( clock == V_4 -> V_188 [ V_13 ] )
V_158 -> V_154 . V_179 . V_180 [ 0 ] = V_13 ;
return 0 ;
}
static int F_142 ( struct V_149 * V_150 ,
struct V_157 * V_158 )
{
struct V_3 * V_4 ;
int V_160 ;
unsigned int V_189 , V_190 ;
V_160 = 0 ;
V_4 = F_101 ( V_150 ) ;
V_189 = V_158 -> V_154 . V_179 . V_180 [ 0 ] ;
if ( V_189 >= V_4 -> V_191 )
return - V_111 ;
V_190 = V_4 -> V_188 [ V_189 ] ;
if ( V_4 -> V_187 != V_190 ) {
F_45 ( & V_4 -> V_80 ) ;
F_52 ( & V_4 -> V_93 ) ;
if ( ( V_160 = F_143 ( V_4 , V_190 ) ) == 0 )
V_160 = 1 ;
F_56 ( & V_4 -> V_93 ) ;
F_46 ( & V_4 -> V_80 ) ;
}
if ( V_160 < 0 )
F_3 ( V_4 -> V_9 -> V_10 ,
L_39 , V_190 , V_160 ) ;
return V_160 ;
}
static int F_144 ( struct V_149 * V_150 ,
struct V_157 * V_158 )
{
struct V_3 * V_4 = F_101 ( V_150 ) ;
V_158 -> V_154 . integer . V_154 [ 0 ] = V_4 -> V_192 ;
return 0 ;
}
static int F_145 ( struct V_149 * V_150 ,
struct V_157 * V_158 )
{
struct V_3 * V_4 = F_101 ( V_150 ) ;
int V_193 , V_160 = 0 ;
V_193 = ! ! V_158 -> V_154 . integer . V_154 [ 0 ] ;
if ( V_4 -> V_192 != V_193 ) {
F_52 ( & V_4 -> V_93 ) ;
V_160 = F_146 ( V_4 , V_193 ) ;
F_56 ( & V_4 -> V_93 ) ;
if ( V_160 == 0 )
V_160 = 1 ;
}
return V_160 ;
}
static int F_147 ( struct V_149 * V_150 ,
struct V_157 * V_158 )
{
struct V_3 * V_4 = F_101 ( V_150 ) ;
V_158 -> V_154 . integer . V_154 [ 0 ] = V_4 -> V_194 ;
return 0 ;
}
static int F_148 ( struct V_149 * V_150 ,
struct V_157 * V_158 )
{
struct V_3 * V_4 = F_101 ( V_150 ) ;
int V_195 , V_160 = 0 ;
V_195 = ! ! V_158 -> V_154 . integer . V_154 [ 0 ] ;
if ( V_4 -> V_194 != V_195 ) {
F_52 ( & V_4 -> V_93 ) ;
V_160 = F_149 ( V_4 , V_195 ) ;
F_56 ( & V_4 -> V_93 ) ;
if ( V_160 == 0 )
V_160 = 1 ;
}
return V_160 ;
}
static int F_150 ( struct V_149 * V_150 ,
struct V_157 * V_158 )
{
struct V_3 * V_4 ;
V_4 = F_101 ( V_150 ) ;
F_52 ( & V_4 -> V_93 ) ;
F_151 ( V_4 , V_158 -> V_154 . integer . V_154 [ 0 ] ) ;
F_56 ( & V_4 -> V_93 ) ;
return 1 ;
}
static int F_152 ( struct V_149 * V_150 ,
struct V_151 * V_152 )
{
V_152 -> type = V_153 ;
V_152 -> V_63 = 96 ;
V_152 -> V_154 . integer . V_32 = V_155 ;
V_152 -> V_154 . integer . V_37 = 0 ;
#ifdef F_40
V_152 -> V_167 . V_168 [ 0 ] = 3 ;
#else
V_152 -> V_167 . V_168 [ 0 ] = 2 ;
#endif
V_152 -> V_167 . V_168 [ 1 ] = 16 ;
V_152 -> V_167 . V_168 [ 2 ] = 2 ;
return 0 ;
}
static int F_153 ( struct V_149 * V_150 ,
struct V_157 * V_158 )
{
struct V_3 * V_4 ;
V_4 = F_101 ( V_150 ) ;
F_154 ( V_4 , V_158 -> V_154 . integer . V_154 ) ;
return 0 ;
}
static int F_155 ( struct V_149 * V_150 ,
struct V_151 * V_152 )
{
V_152 -> type = V_153 ;
V_152 -> V_63 = 6 ;
V_152 -> V_154 . integer . V_32 = 0 ;
V_152 -> V_154 . integer . V_37 = 1 << V_196 ;
return 0 ;
}
static int F_156 ( struct V_149 * V_150 ,
struct V_157 * V_158 )
{
struct V_3 * V_4 ;
int V_197 , V_198 , V_199 , V_200 ;
V_4 = F_101 ( V_150 ) ;
V_158 -> V_154 . integer . V_154 [ 0 ] = F_121 ( V_4 ) ;
V_158 -> V_154 . integer . V_154 [ 1 ] = F_36 ( V_4 ) ;
V_158 -> V_154 . integer . V_154 [ 2 ] = F_102 ( V_4 ) ;
V_158 -> V_154 . integer . V_154 [ 3 ] = F_42 ( V_4 ) ;
V_158 -> V_154 . integer . V_154 [ 4 ] = F_41 ( V_4 ) ;
V_197 = F_157 ( V_4 ) ;
V_198 = 0 ;
V_200 = V_4 -> V_186 - 1 ;
for ( V_199 = V_196 - 1 ; V_199 >= 0 ; V_199 -- )
if ( V_197 & ( 1 << V_199 ) )
for (; V_200 >= 0 ; V_200 -- )
if ( V_199 == V_4 -> V_188 [ V_200 ] ) {
V_198 |= 1 << V_200 ;
break;
}
V_158 -> V_154 . integer . V_154 [ 5 ] = V_198 ;
return 0 ;
}
static T_5 F_158 ( int V_201 , void * V_202 )
{
struct V_3 * V_4 = V_202 ;
struct V_49 * V_50 ;
int V_203 , V_135 , V_204 ;
F_85 ( & V_4 -> V_93 ) ;
V_204 = F_159 ( V_4 ) ;
if ( V_204 < 0 ) {
F_89 ( & V_4 -> V_93 ) ;
return V_205 ;
}
for ( V_135 = 0 ; V_135 < V_115 ; V_135 ++ ) {
V_50 = V_4 -> V_50 [ V_135 ] ;
if ( V_50 && ( (struct V_16 * ) V_50 -> V_15 ->
V_18 ) -> V_119 == V_123 ) {
V_203 = F_90 ( V_50 ) /
V_50 -> V_15 -> V_206 ;
if ( V_203 != V_4 -> V_95 [ V_135 ] ) {
V_4 -> V_95 [ V_135 ] = V_203 ;
F_89 ( & V_4 -> V_93 ) ;
F_160 ( V_50 ) ;
F_85 ( & V_4 -> V_93 ) ;
}
}
}
F_89 ( & V_4 -> V_93 ) ;
#ifdef F_161
if ( V_204 > 0 && V_4 -> V_207 ) {
F_162 ( V_4 -> V_207 , V_4 -> V_208 , V_204 ) ;
F_3 ( V_4 -> V_9 -> V_10 , L_40 , V_204 ) ;
}
#endif
return V_209 ;
}
static int F_163 ( struct V_3 * V_4 )
{
if ( V_4 -> V_210 )
F_164 ( V_4 ) ;
if ( V_4 -> V_201 >= 0 )
F_165 ( V_4 -> V_201 , V_4 ) ;
if ( V_4 -> V_210 )
F_11 ( & V_4 -> V_211 ) ;
if ( V_4 -> V_212 )
F_166 ( V_4 -> V_212 ) ;
F_167 ( V_4 -> V_213 ) ;
F_168 ( V_4 -> V_75 ) ;
F_9 ( V_4 ) ;
F_12 ( V_4 ) ;
return 0 ;
}
static int F_169 ( struct V_214 * V_134 )
{
struct V_3 * V_4 = V_134 -> V_215 ;
return F_163 ( V_4 ) ;
}
static int F_170 ( struct V_216 * V_9 ,
struct V_217 * V_75 ,
struct V_3 * * V_218 )
{
struct V_3 * V_4 ;
int V_6 ;
T_4 V_219 ;
static struct V_220 V_221 = {
. V_222 = F_169 ,
} ;
* V_218 = NULL ;
F_171 ( V_75 , V_223 , 0xC0 ) ;
if ( ( V_6 = F_172 ( V_75 ) ) < 0 )
return V_6 ;
F_173 ( V_75 ) ;
if ( ! * V_218 ) {
V_4 = F_27 ( sizeof( * V_4 ) , V_53 ) ;
if ( ! V_4 ) {
F_168 ( V_75 ) ;
return - V_54 ;
}
F_3 ( V_9 -> V_10 , L_41 , V_4 ) ;
F_174 ( & V_4 -> V_93 ) ;
V_4 -> V_9 = V_9 ;
V_4 -> V_75 = V_75 ;
V_4 -> V_201 = - 1 ;
F_175 ( & V_4 -> V_78 , 0 ) ;
F_176 ( & V_4 -> V_80 ) ;
V_4 -> V_47 = 1 ;
} else {
V_4 = * V_218 ;
}
V_4 -> V_224 = F_177 ( V_75 , 0 ) ;
V_219 = F_178 ( V_75 , 0 ) ;
if ( V_219 > V_76 )
V_219 = V_76 ;
if ( ( V_4 -> V_213 = F_179 ( V_4 -> V_224 , V_219 ,
V_225 ) ) == NULL ) {
F_6 ( V_4 -> V_9 -> V_10 , L_42 ) ;
F_163 ( V_4 ) ;
return - V_226 ;
}
V_4 -> V_212 = ( volatile V_42 V_227 * )
F_180 ( V_4 -> V_224 , V_219 ) ;
if ( F_181 ( V_75 -> V_201 , F_158 , V_228 ,
V_229 , V_4 ) ) {
F_6 ( V_4 -> V_9 -> V_10 , L_43 ) ;
F_163 ( V_4 ) ;
return - V_226 ;
}
V_4 -> V_201 = V_75 -> V_201 ;
F_3 ( V_9 -> V_10 , L_44 ,
V_4 -> V_75 , V_4 -> V_201 , V_4 -> V_75 -> V_230 ) ;
if ( F_33 ( V_74 , F_34 ( V_4 -> V_75 ) ,
sizeof( struct V_210 ) ,
& V_4 -> V_211 ) < 0 ) {
F_6 ( V_4 -> V_9 -> V_10 , L_45 ) ;
F_163 ( V_4 ) ;
return - V_54 ;
}
V_4 -> V_231 = V_4 -> V_211 . V_94 ;
V_4 -> V_210 = (struct V_210 * ) V_4 -> V_211 . V_20 ;
V_6 = F_182 ( V_4 , V_4 -> V_75 -> V_134 , V_4 -> V_75 -> V_230 ) ;
if ( V_6 >= 0 )
V_6 = F_183 ( V_4 ) ;
if ( V_6 < 0 ) {
F_6 ( V_9 -> V_10 , L_46 , V_6 ) ;
F_163 ( V_4 ) ;
return V_6 ;
}
if ( ( V_6 = F_184 ( V_9 , V_232 , V_4 , & V_221 ) ) < 0 ) {
F_163 ( V_4 ) ;
return V_6 ;
}
* V_218 = V_4 ;
return 0 ;
}
static int F_185 ( struct V_217 * V_75 ,
const struct V_233 * V_234 )
{
static int V_10 ;
struct V_216 * V_9 ;
struct V_3 * V_4 ;
char * V_235 ;
int V_13 , V_6 ;
if ( V_10 >= V_236 )
return - V_237 ;
if ( ! V_238 [ V_10 ] ) {
V_10 ++ ;
return - V_239 ;
}
V_13 = 0 ;
V_6 = F_186 ( & V_75 -> V_10 , V_55 [ V_10 ] , V_170 [ V_10 ] , V_240 ,
0 , & V_9 ) ;
if ( V_6 < 0 )
return V_6 ;
V_4 = NULL ;
if ( ( V_6 = F_170 ( V_9 , V_75 , & V_4 ) ) < 0 ) {
F_187 ( V_9 ) ;
return V_6 ;
}
strcpy ( V_9 -> V_241 , L_47 V_225 ) ;
strcpy ( V_9 -> V_141 , V_4 -> V_242 ) ;
V_235 = L_48 ;
if ( V_234 -> V_134 == 0x3410 )
V_235 = L_49 ;
sprintf ( V_9 -> V_243 , L_50 ,
V_9 -> V_141 , V_234 -> V_244 & 0x000f , V_235 ,
V_4 -> V_224 , V_4 -> V_201 ) ;
if ( ( V_6 = F_96 ( V_4 ) ) < 0 ) {
F_6 ( V_4 -> V_9 -> V_10 , L_51 , V_6 ) ;
F_187 ( V_9 ) ;
return V_6 ;
}
#ifdef F_161
if ( V_4 -> V_245 ) {
if ( ( V_6 = F_188 ( V_9 , V_4 ) ) < 0 ) {
F_6 ( V_4 -> V_9 -> V_10 , L_52 , V_6 ) ;
F_187 ( V_9 ) ;
return V_6 ;
}
}
#endif
#ifdef F_40
V_246 . V_63 = F_41 ( V_4 ) * F_102 ( V_4 ) ;
if ( ( V_6 = F_189 ( V_4 -> V_9 , F_190 ( & V_246 , V_4 ) ) ) < 0 )
goto V_247;
#ifdef F_191
V_6 = F_189 ( V_4 -> V_9 ,
F_190 ( & V_248 , V_4 ) ) ;
if ( V_6 < 0 )
goto V_247;
#endif
#else
V_6 = F_189 ( V_4 -> V_9 ,
F_190 ( & V_249 , V_4 ) ) ;
if ( V_6 < 0 )
goto V_247;
#endif
#ifdef F_192
if ( ( V_6 = F_189 ( V_4 -> V_9 , F_190 ( & V_250 , V_4 ) ) ) < 0 )
goto V_247;
#endif
#ifdef F_193
if ( ! V_4 -> V_251 )
if ( ( V_6 = F_189 ( V_4 -> V_9 , F_190 ( & V_252 , V_4 ) ) ) < 0 )
goto V_247;
#endif
#ifdef F_194
if ( ( V_6 = F_189 ( V_4 -> V_9 , F_190 ( & V_253 , V_4 ) ) ) < 0 )
goto V_247;
#endif
if ( ( V_6 = F_189 ( V_4 -> V_9 , F_190 ( & V_254 , V_4 ) ) ) < 0 )
goto V_247;
if ( ( V_6 = F_189 ( V_4 -> V_9 , F_190 ( & V_255 , V_4 ) ) ) < 0 )
goto V_247;
#ifdef F_195
V_256 . V_63 = F_121 ( V_4 ) * F_102 ( V_4 ) ;
if ( ( V_6 = F_189 ( V_4 -> V_9 , F_190 ( & V_256 , V_4 ) ) ) < 0 )
goto V_247;
#endif
#ifdef F_196
if ( ( V_6 = F_189 ( V_4 -> V_9 , F_190 ( & V_257 , V_4 ) ) ) < 0 )
goto V_247;
#endif
if ( ( V_6 = F_189 ( V_4 -> V_9 , F_190 ( & V_258 , V_4 ) ) ) < 0 )
goto V_247;
#ifdef F_197
V_4 -> V_176 = 0 ;
for ( V_13 = 0 ; V_13 < 6 ; V_13 ++ )
if ( V_4 -> V_259 & ( 1 << V_13 ) )
V_4 -> V_178 [ V_4 -> V_176 ++ ] = V_13 ;
if ( ( V_6 = F_189 ( V_4 -> V_9 , F_190 ( & V_260 , V_4 ) ) ) < 0 )
goto V_247;
#endif
#ifdef F_198
V_4 -> V_186 = 0 ;
for ( V_13 = 0 ; V_13 < 10 ; V_13 ++ )
if ( V_4 -> V_191 & ( 1 << V_13 ) )
V_4 -> V_188 [ V_4 -> V_186 ++ ] = V_13 ;
if ( V_4 -> V_186 > 1 ) {
V_4 -> V_183 = F_190 ( & V_261 , V_4 ) ;
if ( ( V_6 = F_189 ( V_4 -> V_9 , V_4 -> V_183 ) ) < 0 )
goto V_247;
}
#endif
#ifdef F_99
if ( ( V_6 = F_189 ( V_4 -> V_9 , F_190 ( & V_262 , V_4 ) ) ) < 0 )
goto V_247;
#endif
#ifdef F_199
if ( V_4 -> V_263 )
if ( ( V_6 = F_189 ( V_4 -> V_9 , F_190 ( & V_264 , V_4 ) ) ) < 0 )
goto V_247;
#endif
V_6 = F_200 ( V_9 ) ;
if ( V_6 < 0 )
goto V_247;
F_201 ( V_9 -> V_10 , L_53 , V_9 -> V_243 ) ;
F_202 ( V_75 , V_4 ) ;
V_10 ++ ;
return 0 ;
V_247:
F_6 ( V_9 -> V_10 , L_54 , V_6 ) ;
F_187 ( V_9 ) ;
return V_6 ;
}
static int F_203 ( struct V_134 * V_10 )
{
struct V_217 * V_75 = F_204 ( V_10 ) ;
struct V_3 * V_4 = F_205 ( V_10 ) ;
F_206 ( V_4 -> V_140 ) ;
F_206 ( V_4 -> V_146 ) ;
#ifdef F_161
if ( V_4 -> V_265 )
F_207 ( V_4 -> V_265 , 0 ) ;
#endif
F_52 ( & V_4 -> V_93 ) ;
if ( F_208 ( V_4 ) ) {
F_56 ( & V_4 -> V_93 ) ;
return - V_266 ;
}
F_209 ( V_4 ) ;
if ( F_210 ( V_4 , V_267 ) < 0 ) {
F_56 ( & V_4 -> V_93 ) ;
return - V_266 ;
}
F_56 ( & V_4 -> V_93 ) ;
V_4 -> V_268 = NULL ;
F_165 ( V_4 -> V_201 , V_4 ) ;
V_4 -> V_201 = - 1 ;
F_211 ( V_75 ) ;
F_168 ( V_75 ) ;
return 0 ;
}
static int F_212 ( struct V_134 * V_10 )
{
struct V_217 * V_75 = F_204 ( V_10 ) ;
struct V_3 * V_4 = F_205 ( V_10 ) ;
struct V_210 * V_269 , * V_270 ;
V_42 V_271 ;
int V_6 ;
F_213 ( V_75 ) ;
V_270 = F_214 ( sizeof( struct V_3 ) , V_53 ) ;
if ( V_270 == NULL )
return - V_54 ;
V_269 = V_4 -> V_210 ;
memcpy ( V_270 , V_269 , sizeof( struct V_210 ) ) ;
V_6 = F_182 ( V_4 , V_4 -> V_75 -> V_134 , V_4 -> V_75 -> V_230 ) ;
if ( V_6 < 0 ) {
F_12 ( V_270 ) ;
F_6 ( V_10 , L_55 , V_6 ) ;
F_163 ( V_4 ) ;
return V_6 ;
}
V_271 = V_4 -> V_271 ;
V_4 -> V_271 = 0 ;
V_6 = F_215 ( V_4 ) ;
V_4 -> V_271 = V_271 ;
if ( V_6 < 0 ) {
F_12 ( V_270 ) ;
return V_6 ;
}
memcpy ( & V_269 -> V_272 , & V_270 -> V_272 ,
sizeof( V_269 -> V_272 ) ) ;
memcpy ( & V_269 -> V_273 , & V_270 -> V_273 ,
sizeof( V_269 -> V_273 ) ) ;
memcpy ( & V_269 -> V_274 , & V_270 -> V_274 ,
sizeof( V_269 -> V_274 ) ) ;
F_12 ( V_270 ) ;
if ( F_181 ( V_75 -> V_201 , F_158 , V_228 ,
V_229 , V_4 ) ) {
F_6 ( V_4 -> V_9 -> V_10 , L_43 ) ;
F_163 ( V_4 ) ;
return - V_226 ;
}
V_4 -> V_201 = V_75 -> V_201 ;
F_3 ( V_10 , L_56 , V_4 -> V_201 ) ;
#ifdef F_161
if ( V_4 -> V_275 )
F_216 ( V_4 , TRUE ) ;
if ( V_4 -> V_265 )
F_207 ( V_4 -> V_265 , 1 ) ;
#endif
return 0 ;
}
static void F_217 ( struct V_217 * V_75 )
{
struct V_3 * V_4 ;
V_4 = F_218 ( V_75 ) ;
if ( V_4 )
F_187 ( V_4 -> V_9 ) ;
}
