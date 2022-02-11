static int F_1 ( const struct V_1 * * V_2 ,
struct V_3 * V_4 , const short V_5 )
{
int V_6 ;
char V_7 [ 30 ] ;
#ifdef F_2
if ( V_4 -> V_8 [ V_5 ] ) {
F_3 ( ( L_1 , V_9 [ V_5 ] . V_10 ) ) ;
* V_2 = V_4 -> V_8 [ V_5 ] ;
return 0 ;
}
#endif
F_3 ( ( L_2 , V_9 [ V_5 ] . V_10 ) ) ;
snprintf ( V_7 , sizeof( V_7 ) , L_3 , V_9 [ V_5 ] . V_10 ) ;
V_6 = F_4 ( V_2 , V_7 , F_5 ( V_4 ) ) ;
if ( V_6 < 0 )
F_6 ( V_11 L_4 , V_6 ) ;
#ifdef F_2
else
V_4 -> V_8 [ V_5 ] = * V_2 ;
#endif
return V_6 ;
}
static void F_7 ( const struct V_1 * V_2 )
{
#ifdef F_2
F_3 ( ( L_5 ) ) ;
#else
F_8 ( V_2 ) ;
F_3 ( ( L_6 ) ) ;
#endif
}
static void F_9 ( struct V_3 * V_4 )
{
#ifdef F_2
int V_12 ;
for ( V_12 = 0 ; V_12 < 8 ; V_12 ++ )
if ( V_4 -> V_8 [ V_12 ] ) {
F_8 ( V_4 -> V_8 [ V_12 ] ) ;
F_3 ( ( L_7 , V_12 ) ) ;
}
F_3 ( ( L_8 ) ) ;
#endif
}
static void F_10 ( struct V_13 * V_14 )
{
struct V_15 * V_16 = V_14 -> V_17 ;
if ( V_16 -> V_18 . V_19 )
F_11 ( & V_16 -> V_18 ) ;
F_12 ( V_16 ) ;
}
static int F_13 ( struct V_20 * V_21 ,
struct V_22 * V_23 )
{
struct V_24 * V_25 = F_14 ( V_21 ,
V_26 ) ;
struct V_27 * V_28 = F_15 ( V_21 , V_29 ) ;
struct V_27 V_30 ;
F_16 ( & V_30 ) ;
#ifndef F_17
if ( V_25 -> V_31 == 2 ) {
V_30 . V_32 [ 0 ] &= ~ V_33 ;
return F_18 ( V_28 , & V_30 ) ;
}
#endif
if ( V_25 -> V_31 > 2 ) {
V_30 . V_32 [ 0 ] &= ~ ( V_34 | V_33 ) ;
return F_18 ( V_28 , & V_30 ) ;
}
return 0 ;
}
static int F_19 ( struct V_20 * V_21 ,
struct V_22 * V_23 )
{
struct V_24 * V_25 = F_14 ( V_21 ,
V_26 ) ;
struct V_27 * V_28 = F_15 ( V_21 , V_29 ) ;
struct V_24 V_35 ;
F_20 ( & V_35 ) ;
if ( V_28 -> V_32 [ 0 ] == V_33 ) {
V_35 . V_31 = 1 ;
#ifdef F_17
V_35 . V_36 = 2 ;
#else
V_35 . V_36 = 1 ;
#endif
V_35 . integer = 1 ;
return F_21 ( V_25 , & V_35 ) ;
}
if ( V_28 -> V_32 [ 0 ] == V_34 ) {
V_35 . V_31 = 1 ;
V_35 . V_36 = 2 ;
V_35 . integer = 1 ;
return F_21 ( V_25 , & V_35 ) ;
}
return 0 ;
}
static int F_22 ( struct V_20 * V_21 ,
struct V_22 * V_23 )
{
struct V_24 * V_25 = F_14 ( V_21 ,
V_26 ) ;
struct V_27 * V_28 = F_15 ( V_21 , V_29 ) ;
struct V_27 V_30 ;
T_1 V_37 ;
F_16 ( & V_30 ) ;
V_37 = V_30 . V_32 [ 0 ] + ( ( T_1 ) V_30 . V_32 [ 1 ] << 32 ) ;
if ( V_25 -> V_31 > 2 ) {
V_37 &= V_38 |
V_39 |
V_40 ;
} else if ( V_25 -> V_36 == 1 )
V_37 &= V_40 | V_33 ;
#ifndef F_17
else if ( V_25 -> V_31 == 2 && V_25 -> V_36 == 2 )
V_37 &= ~ V_33 ;
#endif
else
return 0 ;
V_30 . V_32 [ 0 ] &= ( V_41 ) V_37 ;
V_30 . V_32 [ 1 ] &= ( V_41 ) ( V_37 >> 32 ) ;
return F_18 ( V_28 , & V_30 ) ;
}
static int F_23 ( struct V_20 * V_21 ,
struct V_22 * V_23 )
{
struct V_24 * V_25 = F_14 ( V_21 ,
V_26 ) ;
struct V_27 * V_28 = F_15 ( V_21 , V_29 ) ;
struct V_24 V_35 ;
T_1 V_37 ;
F_20 ( & V_35 ) ;
V_35 . integer = 1 ;
V_37 = V_28 -> V_32 [ 0 ] + ( ( T_1 ) V_28 -> V_32 [ 1 ] << 32 ) ;
if ( V_37 == V_33 ) {
V_35 . V_31 = 1 ;
#ifdef F_17
V_35 . V_36 = 2 ;
#else
V_35 . V_36 = 1 ;
#endif
} else if ( V_37 == V_34 )
V_35 . V_31 = V_35 . V_36 = 2 ;
else if ( ! ( V_37 & ~ ( V_38 |
V_39 ) ) )
V_35 . V_31 = 2 ;
else
return 0 ;
return F_21 ( V_25 , & V_35 ) ;
}
static int F_24 ( struct V_20 * V_21 ,
struct V_22 * V_23 )
{
struct V_24 * V_42 = F_14 ( V_21 ,
V_43 ) ;
struct V_3 * V_4 = V_23 -> V_44 ;
struct V_24 V_45 ;
if ( ! V_4 -> V_46 ) {
F_20 ( & V_45 ) ;
V_45 . V_31 = V_45 . V_36 = V_4 -> V_47 ;
return F_21 ( V_42 , & V_45 ) ;
}
return 0 ;
}
static int F_25 ( struct V_48 * V_49 ,
signed char V_50 )
{
struct V_3 * V_4 ;
struct V_13 * V_14 ;
struct V_15 * V_16 ;
int V_6 , V_12 ;
if ( V_50 <= 0 )
return - V_51 ;
V_4 = F_26 ( V_49 ) ;
V_14 = V_49 -> V_14 ;
V_16 = F_27 ( sizeof( struct V_15 ) , V_52 ) ;
if ( ! V_16 )
return - V_53 ;
V_16 -> V_54 = - 1 ;
memcpy ( & V_16 -> V_55 , & V_56 , sizeof( struct V_57 ) ) ;
F_28 ( ( L_9 , V_50 ) ) ;
V_16 -> V_58 . V_59 = V_60 ;
V_16 -> V_58 . V_61 = 0 ;
for ( V_12 = 0 ; V_60 [ V_12 ] <= V_50 ; V_12 ++ ) ;
V_16 -> V_58 . V_62 = V_12 ;
if ( V_16 -> V_55 . V_63 > V_50 )
V_16 -> V_55 . V_63 = V_50 ;
if ( V_4 -> V_64 == V_65 ) {
V_16 -> V_55 . V_66 = 48000 ;
V_16 -> V_55 . V_67 &= V_68 ;
}
V_14 -> V_55 = V_16 -> V_55 ;
V_14 -> V_17 = V_16 ;
V_14 -> V_69 = F_10 ;
F_29 ( V_49 ) ;
if ( ( V_6 = F_30 ( V_14 , 0 ,
V_26 ,
& V_16 -> V_58 ) ) < 0 )
return V_6 ;
if ( ( V_6 = F_31 ( V_14 ,
V_70 ) ) < 0 )
return V_6 ;
if ( ( V_6 = F_32 ( V_14 , 0 ,
V_71 ,
32 ) ) < 0 )
return V_6 ;
if ( ( V_6 = F_32 ( V_14 , 0 ,
V_72 ,
32 ) ) < 0 )
return V_6 ;
if ( ( V_6 = F_33 ( V_49 -> V_14 , 0 ,
V_43 ,
F_24 , V_4 ,
V_43 , - 1 ) ) < 0 )
return V_6 ;
if ( ( V_6 = F_34 ( V_73 ,
F_35 ( V_4 -> V_74 ) ,
V_75 , & V_16 -> V_18 ) ) < 0 ) {
F_28 ( ( L_10 ) ) ;
return V_6 ;
}
return 0 ;
}
static int F_36 ( struct V_48 * V_49 )
{
struct V_3 * V_4 = F_26 ( V_49 ) ;
int V_6 ;
F_3 ( ( L_11 ) ) ;
if ( ( V_6 = F_25 ( V_49 , F_37 ( V_4 ) -
V_49 -> V_76 ) ) < 0 )
return V_6 ;
if ( ( V_6 = F_33 ( V_49 -> V_14 , 0 ,
V_26 ,
F_19 , NULL ,
V_29 , - 1 ) ) < 0 )
return V_6 ;
if ( ( V_6 = F_33 ( V_49 -> V_14 , 0 ,
V_29 ,
F_13 , NULL ,
V_26 , - 1 ) ) < 0 )
return V_6 ;
F_38 ( & V_4 -> V_77 ) ;
if ( F_39 ( & V_4 -> V_77 ) > 1 && V_4 -> V_78 )
V_4 -> V_46 = 0 ;
F_28 ( ( L_12 ,
V_4 -> V_46 , F_39 ( & V_4 -> V_77 ) ,
V_4 -> V_47 ) ) ;
return 0 ;
}
static int F_40 ( struct V_48 * V_49 )
{
struct V_3 * V_4 = F_26 ( V_49 ) ;
int V_50 , V_6 ;
#ifdef F_41
V_50 = F_42 ( V_4 ) ;
#else
V_50 = F_43 ( V_4 ) ;
#endif
F_3 ( ( L_13 ) ) ;
if ( ( V_6 = F_25 ( V_49 , V_50 - V_49 -> V_76 ) ) < 0 )
return V_6 ;
if ( ( V_6 = F_33 ( V_49 -> V_14 , 0 ,
V_26 ,
F_23 ,
NULL ,
V_29 , - 1 ) ) < 0 )
return V_6 ;
if ( ( V_6 = F_33 ( V_49 -> V_14 , 0 ,
V_29 ,
F_22 ,
NULL ,
V_26 , - 1 ) ) < 0 )
return V_6 ;
F_38 ( & V_4 -> V_77 ) ;
if ( F_39 ( & V_4 -> V_77 ) > 1 && V_4 -> V_78 )
V_4 -> V_46 = 0 ;
F_28 ( ( L_14 ,
V_4 -> V_46 , F_39 ( & V_4 -> V_77 ) ,
V_4 -> V_47 ) ) ;
return 0 ;
}
static int F_44 ( struct V_48 * V_49 )
{
struct V_3 * V_4 = F_26 ( V_49 ) ;
int V_6 , V_50 ;
F_3 ( ( L_15 ) ) ;
V_50 = F_45 ( V_4 ) - V_49 -> V_76 ;
F_46 ( & V_4 -> V_79 ) ;
if ( V_4 -> V_64 == V_65 )
V_6 = F_25 ( V_49 , V_50 ) ;
else
V_6 = F_25 ( V_49 , V_50 - V_80 ) ;
if ( V_6 < 0 )
goto V_81;
if ( ( V_6 = F_33 ( V_49 -> V_14 , 0 ,
V_26 ,
F_19 , NULL ,
V_29 , - 1 ) ) < 0 )
goto V_81;
if ( ( V_6 = F_33 ( V_49 -> V_14 , 0 ,
V_29 ,
F_13 , NULL ,
V_26 , - 1 ) ) < 0 )
goto V_81;
F_38 ( & V_4 -> V_77 ) ;
if ( F_39 ( & V_4 -> V_77 ) > 1 && V_4 -> V_78 )
V_4 -> V_46 = 0 ;
V_81:
F_47 ( & V_4 -> V_79 ) ;
return V_6 ;
}
static int F_48 ( struct V_48 * V_49 )
{
struct V_3 * V_4 = F_26 ( V_49 ) ;
int V_6 , V_50 ;
F_3 ( ( L_16 ) ) ;
V_50 = F_49 ( V_4 ) - V_49 -> V_76 ;
F_46 ( & V_4 -> V_79 ) ;
if ( V_4 -> V_64 == V_65 )
V_6 = F_25 ( V_49 , V_50 ) ;
else
V_6 = F_25 ( V_49 , V_50 - V_80 ) ;
if ( V_6 < 0 )
goto V_82;
if ( ( V_6 = F_33 ( V_49 -> V_14 , 0 ,
V_26 ,
F_23 ,
NULL , V_29 ,
- 1 ) ) < 0 )
goto V_82;
if ( ( V_6 = F_33 ( V_49 -> V_14 , 0 ,
V_29 ,
F_22 ,
NULL , V_26 ,
- 1 ) ) < 0 )
goto V_82;
F_38 ( & V_4 -> V_77 ) ;
if ( F_39 ( & V_4 -> V_77 ) > 1 && V_4 -> V_78 )
V_4 -> V_46 = 0 ;
V_82:
F_47 ( & V_4 -> V_79 ) ;
return V_6 ;
}
static int F_50 ( struct V_48 * V_49 )
{
struct V_3 * V_4 = F_26 ( V_49 ) ;
int V_83 ;
F_3 ( ( L_17 ) ) ;
F_51 ( & V_4 -> V_77 ) ;
V_83 = F_39 ( & V_4 -> V_77 ) ;
F_3 ( ( L_18 , V_83 ,
V_4 -> V_46 , V_4 -> V_78 ) ) ;
if ( V_83 < 2 )
V_4 -> V_46 = 1 ;
if ( V_83 == 0 )
V_4 -> V_78 = 0 ;
F_3 ( ( L_19 , V_83 ,
V_4 -> V_46 , V_4 -> V_78 ) ) ;
return 0 ;
}
static int F_52 ( struct V_48 * V_49 ,
struct V_20 * V_84 ,
int V_85 , int V_86 )
{
struct V_3 * V_4 ;
int V_6 , V_87 , V_88 , V_89 , V_90 , V_91 ;
struct V_15 * V_16 ;
V_4 = F_26 ( V_49 ) ;
V_16 = (struct V_15 * ) V_49 -> V_14 -> V_17 ;
F_53 ( & V_4 -> V_92 ) ;
if ( V_16 -> V_54 >= 0 ) {
F_28 ( ( L_20 , V_16 -> V_54 ) ) ;
V_6 = F_54 ( V_4 , V_16 ) ;
F_55 ( V_6 ) ;
V_4 -> V_49 [ V_16 -> V_54 ] = NULL ;
}
V_6 = F_56 ( V_4 , V_16 , V_85 , V_86 ) ;
if ( V_6 < 0 ) {
F_57 ( & V_4 -> V_92 ) ;
F_3 ( ( V_93 L_21 ,
V_85 , V_6 ) ) ;
return V_6 ;
}
F_57 ( & V_4 -> V_92 ) ;
F_3 ( ( V_93 L_22 , V_85 ) ) ;
F_28 ( ( L_23 ,
F_58 ( V_84 ) , F_59 ( V_84 ) ,
F_60 ( V_84 ) ) ) ;
V_6 = F_61 ( V_49 ,
F_58 ( V_84 ) ) ;
if ( V_6 < 0 ) {
F_6 ( V_11 L_24 , V_6 ) ;
F_53 ( & V_4 -> V_92 ) ;
F_54 ( V_4 , V_16 ) ;
F_57 ( & V_4 -> V_92 ) ;
V_16 -> V_54 = - 1 ;
return V_6 ;
}
F_62 ( V_4 , V_16 ) ;
V_90 = V_75 ;
for ( V_91 = V_89 = V_87 = 0 ; V_91 < F_58 ( V_84 ) ;
V_87 ++ ) {
V_88 = F_60 ( V_84 ) ;
if ( V_91 + V_88 > F_58 ( V_84 ) )
V_88 = F_58 ( V_84 ) - V_91 ;
while ( V_88 ) {
T_2 V_94 ;
V_94 = F_63 ( V_49 , V_91 ) ;
if ( V_88 <= V_90 - V_91 ) {
F_64 ( V_4 , V_16 , V_94 , V_88 ) ;
F_65 ( V_4 , V_16 ) ;
V_91 += V_88 ;
V_88 = 0 ;
} else {
F_64 ( V_4 , V_16 , V_94 ,
V_90 - V_91 ) ;
V_88 -= V_90 - V_91 ;
V_91 = V_90 ;
}
if ( V_91 == V_90 ) {
V_90 += V_75 ;
V_89 ++ ;
}
}
}
F_66 ( V_4 , V_16 ) ;
V_4 -> V_95 [ V_85 ] = 0 ;
V_16 -> V_96 = 0 ;
V_16 -> V_97 = 0 ;
F_67 () ;
V_4 -> V_49 [ V_85 ] = V_49 ;
V_4 -> V_78 = 1 ;
F_53 ( & V_4 -> V_92 ) ;
F_68 ( V_4 , V_84 -> V_98 / V_84 -> V_99 ) ;
F_57 ( & V_4 -> V_92 ) ;
F_28 ( ( L_25 ) ) ;
return 0 ;
}
static int F_69 ( struct V_48 * V_49 ,
struct V_20 * V_84 )
{
struct V_3 * V_4 = F_26 ( V_49 ) ;
return F_52 ( V_49 , V_84 , F_70 ( V_4 ) +
V_49 -> V_76 , F_71 ( V_84 ) ) ;
}
static int F_72 ( struct V_48 * V_49 ,
struct V_20 * V_84 )
{
return F_52 ( V_49 , V_84 , V_49 -> V_76 ,
F_71 ( V_84 ) ) ;
}
static int F_73 ( struct V_48 * V_49 ,
struct V_20 * V_84 )
{
struct V_3 * V_4 = F_26 ( V_49 ) ;
return F_52 ( V_49 , V_84 , F_74 ( V_4 ) +
V_49 -> V_76 , F_71 ( V_84 ) ) ;
}
static int F_75 ( struct V_48 * V_49 ,
struct V_20 * V_84 )
{
struct V_3 * V_4 = F_26 ( V_49 ) ;
return F_52 ( V_49 , V_84 , F_76 ( V_4 ) +
V_49 -> V_76 , F_71 ( V_84 ) ) ;
}
static int F_77 ( struct V_48 * V_49 )
{
struct V_3 * V_4 ;
struct V_15 * V_16 ;
V_4 = F_26 ( V_49 ) ;
V_16 = (struct V_15 * ) V_49 -> V_14 -> V_17 ;
F_53 ( & V_4 -> V_92 ) ;
if ( V_16 -> V_54 >= 0 ) {
F_28 ( ( L_26 , V_16 -> V_54 ) ) ;
F_54 ( V_4 , V_16 ) ;
V_4 -> V_49 [ V_16 -> V_54 ] = NULL ;
V_16 -> V_54 = - 1 ;
}
F_57 ( & V_4 -> V_92 ) ;
F_28 ( ( L_27 ) ) ;
F_78 ( V_49 ) ;
return 0 ;
}
static int F_79 ( struct V_48 * V_49 )
{
struct V_3 * V_4 = F_26 ( V_49 ) ;
struct V_13 * V_14 = V_49 -> V_14 ;
struct V_100 V_101 ;
int V_85 = ( (struct V_15 * ) V_14 -> V_17 ) -> V_54 ;
F_28 ( ( L_28 ,
V_14 -> V_42 , V_14 -> V_101 , V_14 -> V_102 ) ) ;
V_101 . V_86 = V_14 -> V_102 ;
V_101 . V_103 = 0 ;
V_101 . V_104 = 0 ;
switch ( V_14 -> V_101 ) {
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
F_28 ( ( L_29 ,
V_14 -> V_101 ) ) ;
return - V_111 ;
}
if ( F_55 ( V_85 >= F_80 ( V_4 ) ) )
return - V_111 ;
if ( F_55 ( ! F_81 ( V_4 , V_85 ) ) )
return - V_111 ;
F_82 ( V_4 , V_85 , & V_101 ) ;
return 0 ;
}
static int F_83 ( struct V_48 * V_49 , int V_112 )
{
struct V_3 * V_4 = F_26 ( V_49 ) ;
struct V_13 * V_14 = V_49 -> V_14 ;
struct V_15 * V_16 = V_14 -> V_17 ;
int V_12 , V_6 ;
V_41 V_113 = 0 ;
struct V_48 * V_114 ;
F_84 (s, substream) {
for ( V_12 = 0 ; V_12 < V_115 ; V_12 ++ ) {
if ( V_114 == V_4 -> V_49 [ V_12 ] ) {
V_113 |= 1 << V_12 ;
F_85 ( V_114 , V_49 ) ;
}
}
}
F_86 ( & V_4 -> V_92 ) ;
switch ( V_112 ) {
case V_116 :
F_3 ( ( L_30 ) ) ;
case V_117 :
case V_118 :
F_3 ( ( L_31 ) ) ;
for ( V_12 = 0 ; V_12 < V_115 ; V_12 ++ ) {
if ( V_113 & ( 1 << V_12 ) ) {
V_16 = V_4 -> V_49 [ V_12 ] -> V_14 -> V_17 ;
switch ( V_16 -> V_119 ) {
case V_120 :
V_4 -> V_95 [ V_12 ] = 0 ;
V_16 -> V_96 = 0 ;
V_16 -> V_97 = 0 ;
* V_16 -> V_121 = 0 ;
case V_122 :
V_16 -> V_119 = V_123 ;
break;
case V_123 :
break;
}
}
}
V_6 = F_87 ( V_4 , V_113 ,
V_4 -> V_124 ) ;
break;
case V_125 :
F_3 ( ( L_32 ) ) ;
case V_126 :
F_3 ( ( L_33 ) ) ;
for ( V_12 = 0 ; V_12 < V_115 ; V_12 ++ ) {
if ( V_113 & ( 1 << V_12 ) ) {
V_16 = V_4 -> V_49 [ V_12 ] -> V_14 -> V_17 ;
V_16 -> V_119 = V_120 ;
}
}
V_6 = F_88 ( V_4 , V_113 ) ;
break;
case V_127 :
F_3 ( ( L_34 ) ) ;
for ( V_12 = 0 ; V_12 < V_115 ; V_12 ++ ) {
if ( V_113 & ( 1 << V_12 ) ) {
V_16 = V_4 -> V_49 [ V_12 ] -> V_14 -> V_17 ;
V_16 -> V_119 = V_122 ;
}
}
V_6 = F_89 ( V_4 , V_113 ) ;
break;
default:
V_6 = - V_111 ;
}
F_90 ( & V_4 -> V_92 ) ;
return V_6 ;
}
static T_3 F_91 ( struct V_48 * V_49 )
{
struct V_13 * V_14 = V_49 -> V_14 ;
struct V_15 * V_16 = V_14 -> V_17 ;
T_4 V_128 , V_129 , V_130 ;
V_128 = F_92 ( * V_16 -> V_121 ) ;
V_16 -> V_97 += V_128 - V_16 -> V_96 ;
V_16 -> V_96 = V_128 ;
V_129 = V_49 -> V_14 -> V_131 ;
V_130 = F_93 ( V_49 -> V_14 , V_16 -> V_97 ) ;
while ( V_130 >= V_129 ) {
V_16 -> V_97 -= F_94 ( V_49 -> V_14 , V_129 ) ;
V_130 -= V_129 ;
}
return V_130 ;
}
static int F_95 ( struct V_132 * V_133 , struct V_134 * V_135 )
{
struct V_48 * V_136 ;
int V_137 , V_6 ;
for ( V_137 = 0 ; V_137 < 2 ; V_137 ++ )
for ( V_136 = V_133 -> V_138 [ V_137 ] . V_49 ; V_136 ; V_136 = V_136 -> V_139 ) {
V_6 = F_96 ( V_136 , V_140 ,
V_135 ,
V_136 -> V_76 ? 0 : 128 << 10 ,
256 << 10 ) ;
if ( V_6 < 0 )
return V_6 ;
}
return 0 ;
}
static int F_97 ( struct V_3 * V_4 )
{
struct V_132 * V_133 ;
int V_6 ;
#ifdef F_41
if ( ( V_6 = F_98 ( V_4 -> V_141 , L_35 , 0 , F_42 ( V_4 ) ,
F_37 ( V_4 ) , & V_133 ) ) < 0 )
return V_6 ;
V_133 -> V_17 = V_4 ;
V_4 -> V_142 = V_133 ;
strcpy ( V_133 -> V_7 , V_4 -> V_141 -> V_143 ) ;
F_99 ( V_133 , V_144 , & V_145 ) ;
F_99 ( V_133 , V_146 , & V_147 ) ;
if ( ( V_6 = F_95 ( V_133 , F_35 ( V_4 -> V_74 ) ) ) < 0 )
return V_6 ;
F_100 ( ( L_36 ) ) ;
#ifdef F_101
if ( ( V_6 = F_98 ( V_4 -> V_141 , L_37 , 1 , 0 ,
F_45 ( V_4 ) , & V_133 ) ) < 0 )
return V_6 ;
V_133 -> V_17 = V_4 ;
V_4 -> V_148 = V_133 ;
strcpy ( V_133 -> V_7 , V_4 -> V_141 -> V_143 ) ;
F_99 ( V_133 , V_146 , & V_149 ) ;
if ( ( V_6 = F_95 ( V_133 , F_35 ( V_4 -> V_74 ) ) ) < 0 )
return V_6 ;
F_100 ( ( L_38 ) ) ;
#endif
#else
if ( ( V_6 = F_98 ( V_4 -> V_141 , L_39 , 0 ,
F_43 ( V_4 ) ,
F_37 ( V_4 ) , & V_133 ) ) < 0 )
return V_6 ;
V_133 -> V_17 = V_4 ;
V_4 -> V_142 = V_133 ;
strcpy ( V_133 -> V_7 , V_4 -> V_141 -> V_143 ) ;
F_99 ( V_133 , V_144 , & V_145 ) ;
F_99 ( V_133 , V_146 , & V_147 ) ;
if ( ( V_6 = F_95 ( V_133 , F_35 ( V_4 -> V_74 ) ) ) < 0 )
return V_6 ;
F_100 ( ( L_36 ) ) ;
#ifdef F_101
if ( ( V_6 = F_98 ( V_4 -> V_141 , L_37 , 1 ,
F_49 ( V_4 ) ,
F_45 ( V_4 ) , & V_133 ) ) < 0 )
return V_6 ;
V_133 -> V_17 = V_4 ;
V_4 -> V_148 = V_133 ;
strcpy ( V_133 -> V_7 , V_4 -> V_141 -> V_143 ) ;
F_99 ( V_133 , V_144 , & V_150 ) ;
F_99 ( V_133 , V_146 , & V_149 ) ;
if ( ( V_6 = F_95 ( V_133 , F_35 ( V_4 -> V_74 ) ) ) < 0 )
return V_6 ;
F_100 ( ( L_38 ) ) ;
#endif
#endif
return 0 ;
}
static int F_102 ( struct V_151 * V_152 ,
struct V_153 * V_154 )
{
struct V_3 * V_4 ;
V_4 = F_103 ( V_152 ) ;
V_154 -> type = V_155 ;
V_154 -> V_62 = F_104 ( V_4 ) ;
V_154 -> V_156 . integer . V_31 = V_157 ;
V_154 -> V_156 . integer . V_36 = V_158 ;
return 0 ;
}
static int F_105 ( struct V_151 * V_152 ,
struct V_159 * V_160 )
{
struct V_3 * V_4 ;
int V_25 ;
V_4 = F_103 ( V_152 ) ;
for ( V_25 = 0 ; V_25 < F_104 ( V_4 ) ; V_25 ++ )
V_160 -> V_156 . integer . V_156 [ V_25 ] = V_4 -> V_161 [ V_25 ] ;
return 0 ;
}
static int F_106 ( struct V_151 * V_152 ,
struct V_159 * V_160 )
{
struct V_3 * V_4 ;
int V_25 , V_162 , V_163 ;
V_162 = 0 ;
V_4 = F_103 ( V_152 ) ;
F_53 ( & V_4 -> V_92 ) ;
for ( V_25 = 0 ; V_25 < F_104 ( V_4 ) ; V_25 ++ ) {
V_163 = V_160 -> V_156 . integer . V_156 [ V_25 ] ;
if ( V_163 < V_157 || V_163 > V_158 )
continue;
if ( V_4 -> V_161 [ V_25 ] != V_163 ) {
F_107 ( V_4 , V_25 , V_163 ) ;
V_162 = 1 ;
}
}
if ( V_162 )
F_108 ( V_4 ) ;
F_57 ( & V_4 -> V_92 ) ;
return V_162 ;
}
static int F_109 ( struct V_151 * V_152 ,
struct V_153 * V_154 )
{
struct V_3 * V_4 ;
V_4 = F_103 ( V_152 ) ;
V_154 -> type = V_155 ;
V_154 -> V_62 = F_37 ( V_4 ) ;
V_154 -> V_156 . integer . V_31 = V_164 ;
V_154 -> V_156 . integer . V_36 = V_165 ;
return 0 ;
}
static int F_110 ( struct V_151 * V_152 ,
struct V_159 * V_160 )
{
struct V_3 * V_4 ;
int V_25 ;
V_4 = F_103 ( V_152 ) ;
for ( V_25 = 0 ; V_25 < F_37 ( V_4 ) ; V_25 ++ )
V_160 -> V_156 . integer . V_156 [ V_25 ] = V_4 -> V_166 [ V_25 ] ;
return 0 ;
}
static int F_111 ( struct V_151 * V_152 ,
struct V_159 * V_160 )
{
struct V_3 * V_4 ;
int V_25 , V_163 , V_162 ;
V_162 = 0 ;
V_4 = F_103 ( V_152 ) ;
F_53 ( & V_4 -> V_92 ) ;
for ( V_25 = 0 ; V_25 < F_37 ( V_4 ) ; V_25 ++ ) {
V_163 = V_160 -> V_156 . integer . V_156 [ V_25 ] ;
if ( V_163 < V_164 || V_163 > V_165 )
continue;
if ( V_4 -> V_166 [ V_25 ] != V_163 ) {
F_112 ( V_4 , V_25 , V_163 ) ;
V_162 = 1 ;
}
}
if ( V_162 )
F_113 ( V_4 ) ;
F_57 ( & V_4 -> V_92 ) ;
return V_162 ;
}
static int F_114 ( struct V_151 * V_152 ,
struct V_153 * V_154 )
{
struct V_3 * V_4 ;
V_4 = F_103 ( V_152 ) ;
V_154 -> type = V_167 ;
V_154 -> V_62 = F_43 ( V_4 ) ;
V_154 -> V_156 . integer . V_31 = 0 ;
V_154 -> V_156 . integer . V_36 = 1 ;
return 0 ;
}
static int F_115 ( struct V_151 * V_152 ,
struct V_159 * V_160 )
{
struct V_3 * V_4 ;
int V_25 ;
V_4 = F_103 ( V_152 ) ;
for ( V_25 = 0 ; V_25 < F_43 ( V_4 ) ; V_25 ++ )
V_160 -> V_156 . integer . V_156 [ V_25 ] = V_4 -> V_168 [ V_25 ] ;
return 0 ;
}
static int F_116 ( struct V_151 * V_152 ,
struct V_159 * V_160 )
{
struct V_3 * V_4 ;
int V_25 , V_162 ;
V_162 = 0 ;
V_4 = F_103 ( V_152 ) ;
F_53 ( & V_4 -> V_92 ) ;
for ( V_25 = 0 ; V_25 < F_43 ( V_4 ) ; V_25 ++ ) {
if ( V_4 -> V_168 [ V_25 ] != V_160 -> V_156 . integer . V_156 [ V_25 ] ) {
F_117 ( V_4 , V_25 ,
V_160 -> V_156 . integer . V_156 [ V_25 ] ) ;
V_162 = 1 ;
}
}
if ( V_162 )
F_108 ( V_4 ) ;
F_57 ( & V_4 -> V_92 ) ;
return V_162 ;
}
static int F_118 ( struct V_151 * V_152 ,
struct V_153 * V_154 )
{
struct V_3 * V_4 ;
V_4 = F_103 ( V_152 ) ;
V_154 -> type = V_167 ;
V_154 -> V_62 = F_37 ( V_4 ) ;
V_154 -> V_156 . integer . V_31 = 0 ;
V_154 -> V_156 . integer . V_36 = 1 ;
return 0 ;
}
static int F_119 ( struct V_151 * V_152 ,
struct V_159 * V_160 )
{
struct V_3 * V_4 ;
int V_25 ;
V_4 = F_103 ( V_152 ) ;
for ( V_25 = 0 ; V_25 < F_37 ( V_4 ) ; V_25 ++ )
V_160 -> V_156 . integer . V_156 [ V_25 ] =
V_4 -> V_168 [ F_120 ( V_4 ) + V_25 ] ;
return 0 ;
}
static int F_121 ( struct V_151 * V_152 ,
struct V_159 * V_160 )
{
struct V_3 * V_4 ;
int V_25 , V_162 ;
V_162 = 0 ;
V_4 = F_103 ( V_152 ) ;
F_53 ( & V_4 -> V_92 ) ;
for ( V_25 = 0 ; V_25 < F_37 ( V_4 ) ; V_25 ++ ) {
if ( V_4 -> V_168 [ F_120 ( V_4 ) + V_25 ] !=
V_160 -> V_156 . integer . V_156 [ V_25 ] ) {
F_117 ( V_4 , F_120 ( V_4 ) + V_25 ,
V_160 -> V_156 . integer . V_156 [ V_25 ] ) ;
V_162 = 1 ;
}
}
if ( V_162 )
F_108 ( V_4 ) ;
F_57 ( & V_4 -> V_92 ) ;
return V_162 ;
}
static int F_122 ( struct V_151 * V_152 ,
struct V_153 * V_154 )
{
struct V_3 * V_4 ;
V_4 = F_103 ( V_152 ) ;
V_154 -> type = V_155 ;
V_154 -> V_62 = 1 ;
V_154 -> V_156 . integer . V_31 = V_157 ;
V_154 -> V_156 . integer . V_36 = V_158 ;
V_154 -> V_169 . V_170 [ 0 ] = F_104 ( V_4 ) ;
V_154 -> V_169 . V_170 [ 1 ] = F_123 ( V_4 ) ;
return 0 ;
}
static int F_124 ( struct V_151 * V_152 ,
struct V_159 * V_160 )
{
struct V_3 * V_4 ;
V_4 = F_103 ( V_152 ) ;
V_160 -> V_156 . integer . V_156 [ 0 ] =
V_4 -> V_171 [ V_160 -> V_172 . V_54 / F_123 ( V_4 ) ]
[ V_160 -> V_172 . V_54 % F_123 ( V_4 ) ] ;
return 0 ;
}
static int F_125 ( struct V_151 * V_152 ,
struct V_159 * V_160 )
{
struct V_3 * V_4 ;
int V_162 , V_163 ;
short V_173 , V_174 ;
V_162 = 0 ;
V_4 = F_103 ( V_152 ) ;
V_173 = V_160 -> V_172 . V_54 / F_123 ( V_4 ) ;
V_174 = V_160 -> V_172 . V_54 % F_123 ( V_4 ) ;
V_163 = V_160 -> V_156 . integer . V_156 [ 0 ] ;
if ( V_163 < V_157 || V_163 > V_158 )
return - V_111 ;
if ( V_4 -> V_171 [ V_173 ] [ V_174 ] != V_163 ) {
F_53 ( & V_4 -> V_92 ) ;
F_126 ( V_4 , V_173 , V_174 , V_163 ) ;
F_108 ( V_4 ) ;
F_57 ( & V_4 -> V_92 ) ;
V_162 = 1 ;
}
return V_162 ;
}
static int F_127 ( struct V_151 * V_152 ,
struct V_153 * V_154 )
{
struct V_3 * V_4 ;
V_4 = F_103 ( V_152 ) ;
V_154 -> type = V_155 ;
V_154 -> V_62 = 1 ;
V_154 -> V_156 . integer . V_31 = V_157 ;
V_154 -> V_156 . integer . V_36 = V_158 ;
V_154 -> V_169 . V_170 [ 0 ] = F_104 ( V_4 ) ;
V_154 -> V_169 . V_170 [ 1 ] = F_42 ( V_4 ) ;
return 0 ;
}
static int F_128 ( struct V_151 * V_152 ,
struct V_159 * V_160 )
{
struct V_3 * V_4 ;
V_4 = F_103 ( V_152 ) ;
V_160 -> V_156 . integer . V_156 [ 0 ] =
V_4 -> V_175 [ V_160 -> V_172 . V_54 / F_42 ( V_4 ) ]
[ V_160 -> V_172 . V_54 % F_42 ( V_4 ) ] ;
return 0 ;
}
static int F_129 ( struct V_151 * V_152 ,
struct V_159 * V_160 )
{
struct V_3 * V_4 ;
int V_163 , V_162 ;
short V_176 , V_173 ;
V_162 = 0 ;
V_4 = F_103 ( V_152 ) ;
V_173 = V_160 -> V_172 . V_54 / F_42 ( V_4 ) ;
V_176 = V_160 -> V_172 . V_54 % F_42 ( V_4 ) ;
V_163 = V_160 -> V_156 . integer . V_156 [ 0 ] ;
if ( V_163 < V_157 || V_163 > V_158 )
return - V_111 ;
if ( V_4 -> V_175 [ V_173 ] [ V_176 ] != V_160 -> V_156 . integer . V_156 [ 0 ] ) {
F_53 ( & V_4 -> V_92 ) ;
F_130 ( V_4 , V_173 , V_176 , V_160 -> V_156 . integer . V_156 [ 0 ] ) ;
F_131 ( V_4 ) ;
F_57 ( & V_4 -> V_92 ) ;
V_162 = 1 ;
}
return V_162 ;
}
static int F_132 ( struct V_151 * V_152 ,
struct V_153 * V_154 )
{
static char * V_177 [ 4 ] = {
L_40 , L_41 , L_42 ,
L_43
} ;
struct V_3 * V_4 ;
V_4 = F_103 ( V_152 ) ;
V_154 -> type = V_178 ;
V_154 -> V_156 . V_179 . V_180 = V_4 -> V_181 ;
V_154 -> V_62 = 1 ;
if ( V_154 -> V_156 . V_179 . V_182 >= V_4 -> V_181 )
V_154 -> V_156 . V_179 . V_182 = V_4 -> V_181 - 1 ;
strcpy ( V_154 -> V_156 . V_179 . V_7 , V_177 [
V_4 -> V_183 [ V_154 -> V_156 . V_179 . V_182 ] ] ) ;
return 0 ;
}
static int F_133 ( struct V_151 * V_152 ,
struct V_159 * V_160 )
{
struct V_3 * V_4 ;
int V_12 , V_184 ;
V_4 = F_103 ( V_152 ) ;
V_184 = V_4 -> V_64 ;
for ( V_12 = V_4 -> V_181 - 1 ; V_12 >= 0 ; V_12 -- )
if ( V_184 == V_4 -> V_183 [ V_12 ] ) {
V_160 -> V_156 . V_179 . V_182 [ 0 ] = V_12 ;
break;
}
return 0 ;
}
static int F_134 ( struct V_151 * V_152 ,
struct V_159 * V_160 )
{
struct V_3 * V_4 ;
int V_162 ;
unsigned short V_185 , V_186 ;
V_162 = 0 ;
V_4 = F_103 ( V_152 ) ;
V_185 = V_160 -> V_156 . V_179 . V_182 [ 0 ] ;
if ( V_185 >= V_4 -> V_181 )
return - V_111 ;
V_186 = V_4 -> V_183 [ V_185 ] ;
if ( V_186 != V_4 -> V_64 ) {
F_46 ( & V_4 -> V_79 ) ;
if ( F_39 ( & V_4 -> V_77 ) ) {
V_162 = - V_51 ;
} else {
V_162 = F_135 ( V_4 , V_186 ) ;
if ( V_162 > 0 && V_4 -> V_187 ) {
F_136 ( V_4 -> V_141 ,
V_188 ,
& V_4 -> V_187 -> V_172 ) ;
F_3 ( ( L_44 , V_162 ) ) ;
}
if ( V_162 >= 0 )
V_162 = 1 ;
}
F_47 ( & V_4 -> V_79 ) ;
}
return V_162 ;
}
static int F_137 ( struct V_151 * V_152 ,
struct V_153 * V_154 )
{
static char * V_177 [ 2 ] = { L_45 , L_46 } ;
V_154 -> type = V_178 ;
V_154 -> V_156 . V_179 . V_180 = 2 ;
V_154 -> V_62 = 1 ;
if ( V_154 -> V_156 . V_179 . V_182 )
V_154 -> V_156 . V_179 . V_182 = 1 ;
strcpy ( V_154 -> V_156 . V_179 . V_7 ,
V_177 [ V_154 -> V_156 . V_179 . V_182 ] ) ;
return 0 ;
}
static int F_138 ( struct V_151 * V_152 ,
struct V_159 * V_160 )
{
struct V_3 * V_4 ;
V_4 = F_103 ( V_152 ) ;
V_160 -> V_156 . V_179 . V_182 [ 0 ] = ! ! V_4 -> V_189 ;
return 0 ;
}
static int F_139 ( struct V_151 * V_152 ,
struct V_159 * V_160 )
{
struct V_3 * V_4 ;
int V_184 ;
V_4 = F_103 ( V_152 ) ;
V_184 = ! ! V_160 -> V_156 . V_179 . V_182 [ 0 ] ;
if ( V_184 != V_4 -> V_189 ) {
F_53 ( & V_4 -> V_92 ) ;
F_140 ( V_4 , V_184 ) ;
F_57 ( & V_4 -> V_92 ) ;
return 1 ;
}
return 0 ;
}
static int F_141 ( struct V_151 * V_152 ,
struct V_153 * V_154 )
{
static char * V_177 [ 8 ] = {
L_47 , L_48 , L_49 , L_50 , L_51 , L_52 ,
L_53 , L_54
} ;
struct V_3 * V_4 ;
V_4 = F_103 ( V_152 ) ;
V_154 -> type = V_178 ;
V_154 -> V_156 . V_179 . V_180 = V_4 -> V_190 ;
V_154 -> V_62 = 1 ;
if ( V_154 -> V_156 . V_179 . V_182 >= V_4 -> V_190 )
V_154 -> V_156 . V_179 . V_182 = V_4 -> V_190 - 1 ;
strcpy ( V_154 -> V_156 . V_179 . V_7 , V_177 [
V_4 -> V_191 [ V_154 -> V_156 . V_179 . V_182 ] ] ) ;
return 0 ;
}
static int F_142 ( struct V_151 * V_152 ,
struct V_159 * V_160 )
{
struct V_3 * V_4 ;
int V_12 , clock ;
V_4 = F_103 ( V_152 ) ;
clock = V_4 -> V_192 ;
for ( V_12 = 0 ; V_12 < V_4 -> V_190 ; V_12 ++ )
if ( clock == V_4 -> V_191 [ V_12 ] )
V_160 -> V_156 . V_179 . V_182 [ 0 ] = V_12 ;
return 0 ;
}
static int F_143 ( struct V_151 * V_152 ,
struct V_159 * V_160 )
{
struct V_3 * V_4 ;
int V_162 ;
unsigned int V_193 , V_194 ;
V_162 = 0 ;
V_4 = F_103 ( V_152 ) ;
V_193 = V_160 -> V_156 . V_179 . V_182 [ 0 ] ;
if ( V_193 >= V_4 -> V_195 )
return - V_111 ;
V_194 = V_4 -> V_191 [ V_193 ] ;
if ( V_4 -> V_192 != V_194 ) {
F_46 ( & V_4 -> V_79 ) ;
F_53 ( & V_4 -> V_92 ) ;
if ( ( V_162 = F_144 ( V_4 , V_194 ) ) == 0 )
V_162 = 1 ;
F_57 ( & V_4 -> V_92 ) ;
F_47 ( & V_4 -> V_79 ) ;
}
if ( V_162 < 0 )
F_3 ( ( L_55 , V_194 , V_162 ) ) ;
return V_162 ;
}
static int F_145 ( struct V_151 * V_152 ,
struct V_159 * V_160 )
{
struct V_3 * V_4 = F_103 ( V_152 ) ;
V_160 -> V_156 . integer . V_156 [ 0 ] = V_4 -> V_196 ;
return 0 ;
}
static int F_146 ( struct V_151 * V_152 ,
struct V_159 * V_160 )
{
struct V_3 * V_4 = F_103 ( V_152 ) ;
int V_197 , V_162 = 0 ;
V_197 = ! ! V_160 -> V_156 . integer . V_156 [ 0 ] ;
if ( V_4 -> V_196 != V_197 ) {
F_53 ( & V_4 -> V_92 ) ;
V_162 = F_147 ( V_4 , V_197 ) ;
F_57 ( & V_4 -> V_92 ) ;
if ( V_162 == 0 )
V_162 = 1 ;
}
return V_162 ;
}
static int F_148 ( struct V_151 * V_152 ,
struct V_159 * V_160 )
{
struct V_3 * V_4 = F_103 ( V_152 ) ;
V_160 -> V_156 . integer . V_156 [ 0 ] = V_4 -> V_198 ;
return 0 ;
}
static int F_149 ( struct V_151 * V_152 ,
struct V_159 * V_160 )
{
struct V_3 * V_4 = F_103 ( V_152 ) ;
int V_199 , V_162 = 0 ;
V_199 = ! ! V_160 -> V_156 . integer . V_156 [ 0 ] ;
if ( V_4 -> V_198 != V_199 ) {
F_53 ( & V_4 -> V_92 ) ;
V_162 = F_150 ( V_4 , V_199 ) ;
F_57 ( & V_4 -> V_92 ) ;
if ( V_162 == 0 )
V_162 = 1 ;
}
return V_162 ;
}
static int F_151 ( struct V_151 * V_152 ,
struct V_159 * V_160 )
{
struct V_3 * V_4 ;
V_4 = F_103 ( V_152 ) ;
F_53 ( & V_4 -> V_92 ) ;
F_152 ( V_4 , V_160 -> V_156 . integer . V_156 [ 0 ] ) ;
F_57 ( & V_4 -> V_92 ) ;
return 1 ;
}
static int F_153 ( struct V_151 * V_152 ,
struct V_153 * V_154 )
{
struct V_3 * V_4 ;
V_4 = F_103 ( V_152 ) ;
V_154 -> type = V_155 ;
V_154 -> V_62 = 96 ;
V_154 -> V_156 . integer . V_31 = V_157 ;
V_154 -> V_156 . integer . V_36 = 0 ;
#ifdef F_41
V_154 -> V_169 . V_170 [ 0 ] = 3 ;
#else
V_154 -> V_169 . V_170 [ 0 ] = 2 ;
#endif
V_154 -> V_169 . V_170 [ 1 ] = 16 ;
V_154 -> V_169 . V_170 [ 2 ] = 2 ;
return 0 ;
}
static int F_154 ( struct V_151 * V_152 ,
struct V_159 * V_160 )
{
struct V_3 * V_4 ;
V_4 = F_103 ( V_152 ) ;
F_155 ( V_4 , V_160 -> V_156 . integer . V_156 ) ;
return 0 ;
}
static int F_156 ( struct V_151 * V_152 ,
struct V_153 * V_154 )
{
struct V_3 * V_4 ;
V_4 = F_103 ( V_152 ) ;
V_154 -> type = V_155 ;
V_154 -> V_62 = 6 ;
V_154 -> V_156 . integer . V_31 = 0 ;
V_154 -> V_156 . integer . V_36 = 1 << V_200 ;
return 0 ;
}
static int F_157 ( struct V_151 * V_152 ,
struct V_159 * V_160 )
{
struct V_3 * V_4 ;
int V_201 , V_202 , V_203 , V_204 ;
V_4 = F_103 ( V_152 ) ;
V_160 -> V_156 . integer . V_156 [ 0 ] = F_123 ( V_4 ) ;
V_160 -> V_156 . integer . V_156 [ 1 ] = F_37 ( V_4 ) ;
V_160 -> V_156 . integer . V_156 [ 2 ] = F_104 ( V_4 ) ;
V_160 -> V_156 . integer . V_156 [ 3 ] = F_43 ( V_4 ) ;
V_160 -> V_156 . integer . V_156 [ 4 ] = F_42 ( V_4 ) ;
V_201 = F_158 ( V_4 ) ;
V_202 = 0 ;
V_204 = V_4 -> V_190 - 1 ;
for ( V_203 = V_200 - 1 ; V_203 >= 0 ; V_203 -- )
if ( V_201 & ( 1 << V_203 ) )
for (; V_204 >= 0 ; V_204 -- )
if ( V_203 == V_4 -> V_191 [ V_204 ] ) {
V_202 |= 1 << V_204 ;
break;
}
V_160 -> V_156 . integer . V_156 [ 5 ] = V_202 ;
return 0 ;
}
static T_5 F_159 ( int V_205 , void * V_206 )
{
struct V_3 * V_4 = V_206 ;
struct V_48 * V_49 ;
int V_207 , V_136 , V_208 ;
F_86 ( & V_4 -> V_92 ) ;
V_208 = F_160 ( V_4 ) ;
if ( V_208 < 0 ) {
F_90 ( & V_4 -> V_92 ) ;
return V_209 ;
}
for ( V_136 = 0 ; V_136 < V_115 ; V_136 ++ ) {
V_49 = V_4 -> V_49 [ V_136 ] ;
if ( V_49 && ( (struct V_15 * ) V_49 -> V_14 ->
V_17 ) -> V_119 == V_123 ) {
V_207 = F_91 ( V_49 ) /
V_49 -> V_14 -> V_210 ;
if ( V_207 != V_4 -> V_95 [ V_136 ] ) {
V_4 -> V_95 [ V_136 ] = V_207 ;
F_90 ( & V_4 -> V_92 ) ;
F_161 ( V_49 ) ;
F_86 ( & V_4 -> V_92 ) ;
}
}
}
F_90 ( & V_4 -> V_92 ) ;
#ifdef F_162
if ( V_208 > 0 && V_4 -> V_211 ) {
F_163 ( V_4 -> V_211 , V_4 -> V_212 , V_208 ) ;
F_164 ( ( L_56 , V_208 ) ) ;
}
#endif
return V_213 ;
}
static int F_165 ( struct V_3 * V_4 )
{
F_100 ( ( L_57 ) ) ;
if ( V_4 -> V_214 )
F_166 ( V_4 ) ;
F_100 ( ( L_58 ) ) ;
if ( V_4 -> V_205 >= 0 )
F_167 ( V_4 -> V_205 , V_4 ) ;
if ( V_4 -> V_214 )
F_11 ( & V_4 -> V_215 ) ;
if ( V_4 -> V_216 )
F_168 ( V_4 -> V_216 ) ;
if ( V_4 -> V_217 )
F_169 ( V_4 -> V_217 ) ;
F_100 ( ( L_59 ) ) ;
F_170 ( V_4 -> V_74 ) ;
F_9 ( V_4 ) ;
F_12 ( V_4 ) ;
F_100 ( ( L_60 ) ) ;
return 0 ;
}
static int F_171 ( struct V_218 * V_134 )
{
struct V_3 * V_4 = V_134 -> V_219 ;
F_100 ( ( L_61 ) ) ;
return F_165 ( V_4 ) ;
}
static int F_172 ( struct V_220 * V_141 ,
struct V_221 * V_74 ,
struct V_3 * * V_222 )
{
struct V_3 * V_4 ;
int V_6 ;
T_4 V_223 ;
static struct V_224 V_225 = {
. V_226 = F_171 ,
} ;
* V_222 = NULL ;
F_173 ( V_74 , V_227 , 0xC0 ) ;
if ( ( V_6 = F_174 ( V_74 ) ) < 0 )
return V_6 ;
F_175 ( V_74 ) ;
if ( ! * V_222 ) {
V_4 = F_27 ( sizeof( * V_4 ) , V_52 ) ;
if ( ! V_4 ) {
F_170 ( V_74 ) ;
return - V_53 ;
}
F_100 ( ( L_62 , V_4 ) ) ;
F_176 ( & V_4 -> V_92 ) ;
V_4 -> V_141 = V_141 ;
V_4 -> V_74 = V_74 ;
V_4 -> V_205 = - 1 ;
F_177 ( & V_4 -> V_77 , 0 ) ;
F_178 ( & V_4 -> V_79 ) ;
V_4 -> V_46 = 1 ;
} else {
V_4 = * V_222 ;
}
V_4 -> V_228 = F_179 ( V_74 , 0 ) ;
V_223 = F_180 ( V_74 , 0 ) ;
if ( V_223 > V_75 )
V_223 = V_75 ;
if ( ( V_4 -> V_217 = F_181 ( V_4 -> V_228 , V_223 ,
V_229 ) ) == NULL ) {
F_165 ( V_4 ) ;
F_6 ( V_11 L_63 ) ;
return - V_230 ;
}
V_4 -> V_216 = ( volatile V_41 V_231 * )
F_182 ( V_4 -> V_228 , V_223 ) ;
if ( F_183 ( V_74 -> V_205 , F_159 , V_232 ,
V_233 , V_4 ) ) {
F_165 ( V_4 ) ;
F_6 ( V_11 L_64 ) ;
return - V_230 ;
}
V_4 -> V_205 = V_74 -> V_205 ;
F_100 ( ( L_65 ,
V_4 -> V_74 , V_4 -> V_205 , V_4 -> V_74 -> V_234 ) ) ;
if ( F_34 ( V_73 , F_35 ( V_4 -> V_74 ) ,
sizeof( struct V_214 ) ,
& V_4 -> V_215 ) < 0 ) {
F_165 ( V_4 ) ;
F_6 ( V_11 L_66 ) ;
return - V_53 ;
}
V_4 -> V_235 = V_4 -> V_215 . V_94 ;
V_4 -> V_214 = (struct V_214 * ) V_4 -> V_215 . V_19 ;
V_6 = F_184 ( V_4 , V_4 -> V_74 -> V_134 , V_4 -> V_74 -> V_234 ) ;
if ( V_6 >= 0 )
V_6 = F_185 ( V_4 ) ;
if ( V_6 < 0 ) {
F_100 ( ( L_67 , V_6 ) ) ;
F_165 ( V_4 ) ;
return V_6 ;
}
F_100 ( ( L_68 ) ) ;
if ( ( V_6 = F_186 ( V_141 , V_236 , V_4 , & V_225 ) ) < 0 ) {
F_165 ( V_4 ) ;
return V_6 ;
}
* V_222 = V_4 ;
return 0 ;
}
static int F_187 ( struct V_221 * V_74 ,
const struct V_237 * V_238 )
{
static int V_135 ;
struct V_220 * V_141 ;
struct V_3 * V_4 ;
char * V_239 ;
int V_12 , V_6 ;
if ( V_135 >= V_240 )
return - V_241 ;
if ( ! V_242 [ V_135 ] ) {
V_135 ++ ;
return - V_243 ;
}
F_100 ( ( L_69 ) ) ;
V_12 = 0 ;
V_6 = F_188 ( V_54 [ V_135 ] , V_172 [ V_135 ] , V_244 , 0 , & V_141 ) ;
if ( V_6 < 0 )
return V_6 ;
F_189 ( V_141 , & V_74 -> V_135 ) ;
V_4 = NULL ;
if ( ( V_6 = F_172 ( V_141 , V_74 , & V_4 ) ) < 0 ) {
F_190 ( V_141 ) ;
return V_6 ;
}
strcpy ( V_141 -> V_245 , L_70 V_229 ) ;
strcpy ( V_141 -> V_143 , V_4 -> V_246 ) ;
V_239 = L_71 ;
if ( V_238 -> V_134 == 0x3410 )
V_239 = L_72 ;
sprintf ( V_141 -> V_247 , L_73 ,
V_141 -> V_143 , V_238 -> V_248 & 0x000f , V_239 ,
V_4 -> V_228 , V_4 -> V_205 ) ;
if ( ( V_6 = F_97 ( V_4 ) ) < 0 ) {
F_6 ( V_11 L_74 , V_6 ) ;
F_190 ( V_141 ) ;
return V_6 ;
}
#ifdef F_162
if ( V_4 -> V_249 ) {
if ( ( V_6 = F_191 ( V_141 , V_4 ) ) < 0 ) {
F_6 ( V_11 L_75 , V_6 ) ;
F_190 ( V_141 ) ;
return V_6 ;
}
}
#endif
#ifdef F_41
V_250 . V_62 = F_42 ( V_4 ) * F_104 ( V_4 ) ;
if ( ( V_6 = F_192 ( V_4 -> V_141 , F_193 ( & V_250 , V_4 ) ) ) < 0 )
goto V_251;
#ifdef F_194
V_6 = F_192 ( V_4 -> V_141 ,
F_193 ( & V_252 , V_4 ) ) ;
if ( V_6 < 0 )
goto V_251;
#endif
#else
V_6 = F_192 ( V_4 -> V_141 ,
F_193 ( & V_253 , V_4 ) ) ;
if ( V_6 < 0 )
goto V_251;
#endif
#ifdef F_195
if ( ( V_6 = F_192 ( V_4 -> V_141 , F_193 ( & V_254 , V_4 ) ) ) < 0 )
goto V_251;
#endif
#ifdef F_196
if ( ! V_4 -> V_255 )
if ( ( V_6 = F_192 ( V_4 -> V_141 , F_193 ( & V_256 , V_4 ) ) ) < 0 )
goto V_251;
#endif
#ifdef F_197
if ( ( V_6 = F_192 ( V_4 -> V_141 , F_193 ( & V_257 , V_4 ) ) ) < 0 )
goto V_251;
#endif
if ( ( V_6 = F_192 ( V_4 -> V_141 , F_193 ( & V_258 , V_4 ) ) ) < 0 )
goto V_251;
if ( ( V_6 = F_192 ( V_4 -> V_141 , F_193 ( & V_259 , V_4 ) ) ) < 0 )
goto V_251;
#ifdef F_198
V_260 . V_62 = F_123 ( V_4 ) * F_104 ( V_4 ) ;
if ( ( V_6 = F_192 ( V_4 -> V_141 , F_193 ( & V_260 , V_4 ) ) ) < 0 )
goto V_251;
#endif
#ifdef F_199
if ( ( V_6 = F_192 ( V_4 -> V_141 , F_193 ( & V_261 , V_4 ) ) ) < 0 )
goto V_251;
#endif
if ( ( V_6 = F_192 ( V_4 -> V_141 , F_193 ( & V_262 , V_4 ) ) ) < 0 )
goto V_251;
#ifdef F_200
V_4 -> V_181 = 0 ;
for ( V_12 = 0 ; V_12 < 6 ; V_12 ++ )
if ( V_4 -> V_263 & ( 1 << V_12 ) )
V_4 -> V_183 [ V_4 -> V_181 ++ ] = V_12 ;
if ( ( V_6 = F_192 ( V_4 -> V_141 , F_193 ( & V_264 , V_4 ) ) ) < 0 )
goto V_251;
#endif
#ifdef F_201
V_4 -> V_190 = 0 ;
for ( V_12 = 0 ; V_12 < 10 ; V_12 ++ )
if ( V_4 -> V_195 & ( 1 << V_12 ) )
V_4 -> V_191 [ V_4 -> V_190 ++ ] = V_12 ;
if ( V_4 -> V_190 > 1 ) {
V_4 -> V_187 = F_193 ( & V_265 , V_4 ) ;
if ( ( V_6 = F_192 ( V_4 -> V_141 , V_4 -> V_187 ) ) < 0 )
goto V_251;
}
#endif
#ifdef F_101
if ( ( V_6 = F_192 ( V_4 -> V_141 , F_193 ( & V_266 , V_4 ) ) ) < 0 )
goto V_251;
#endif
#ifdef F_202
if ( V_4 -> V_267 )
if ( ( V_6 = F_192 ( V_4 -> V_141 , F_193 ( & V_268 , V_4 ) ) ) < 0 )
goto V_251;
#endif
V_6 = F_203 ( V_141 ) ;
if ( V_6 < 0 )
goto V_251;
F_6 ( V_269 L_76 , V_141 -> V_247 ) ;
F_204 ( V_74 , V_4 ) ;
V_135 ++ ;
return 0 ;
V_251:
F_6 ( V_11 L_77 , V_6 ) ;
F_190 ( V_141 ) ;
return V_6 ;
}
static int F_205 ( struct V_134 * V_135 )
{
struct V_221 * V_74 = F_206 ( V_135 ) ;
struct V_3 * V_4 = F_207 ( V_135 ) ;
F_100 ( ( L_78 ) ) ;
F_208 ( V_4 -> V_142 ) ;
F_208 ( V_4 -> V_148 ) ;
#ifdef F_162
if ( V_4 -> V_270 )
F_209 ( V_4 -> V_270 , 0 ) ;
#endif
F_53 ( & V_4 -> V_92 ) ;
if ( F_210 ( V_4 ) ) {
F_57 ( & V_4 -> V_92 ) ;
return - V_271 ;
}
F_211 ( V_4 ) ;
if ( F_212 ( V_4 , V_272 ) < 0 ) {
F_57 ( & V_4 -> V_92 ) ;
return - V_271 ;
}
F_57 ( & V_4 -> V_92 ) ;
V_4 -> V_273 = NULL ;
F_167 ( V_4 -> V_205 , V_4 ) ;
V_4 -> V_205 = - 1 ;
F_213 ( V_74 ) ;
F_170 ( V_74 ) ;
F_100 ( ( L_79 ) ) ;
return 0 ;
}
static int F_214 ( struct V_134 * V_135 )
{
struct V_221 * V_74 = F_206 ( V_135 ) ;
struct V_3 * V_4 = F_207 ( V_135 ) ;
struct V_214 * V_274 , * V_275 ;
V_41 V_276 ;
int V_6 ;
F_100 ( ( L_80 ) ) ;
F_215 ( V_74 ) ;
V_275 = F_216 ( sizeof( struct V_3 ) , V_52 ) ;
if ( V_275 == NULL )
return - V_53 ;
V_274 = V_4 -> V_214 ;
memcpy ( V_275 , V_274 , sizeof( struct V_214 ) ) ;
V_6 = F_184 ( V_4 , V_4 -> V_74 -> V_134 , V_4 -> V_74 -> V_234 ) ;
if ( V_6 < 0 ) {
F_12 ( V_275 ) ;
F_100 ( ( L_81 , V_6 ) ) ;
F_165 ( V_4 ) ;
return V_6 ;
}
F_100 ( ( L_82 ) ) ;
V_276 = V_4 -> V_276 ;
V_4 -> V_276 = 0 ;
V_6 = F_217 ( V_4 ) ;
V_4 -> V_276 = V_276 ;
if ( V_6 < 0 ) {
F_12 ( V_275 ) ;
return V_6 ;
}
F_100 ( ( L_83 ) ) ;
memcpy ( & V_274 -> V_277 , & V_275 -> V_277 ,
sizeof( V_274 -> V_277 ) ) ;
memcpy ( & V_274 -> V_278 , & V_275 -> V_278 ,
sizeof( V_274 -> V_278 ) ) ;
memcpy ( & V_274 -> V_279 , & V_275 -> V_279 ,
sizeof( V_274 -> V_279 ) ) ;
F_12 ( V_275 ) ;
if ( F_183 ( V_74 -> V_205 , F_159 , V_232 ,
V_233 , V_4 ) ) {
F_165 ( V_4 ) ;
F_6 ( V_11 L_64 ) ;
return - V_230 ;
}
V_4 -> V_205 = V_74 -> V_205 ;
F_100 ( ( L_84 , V_4 -> V_205 ) ) ;
#ifdef F_162
if ( V_4 -> V_280 )
F_218 ( V_4 , TRUE ) ;
if ( V_4 -> V_270 )
F_209 ( V_4 -> V_270 , 1 ) ;
#endif
F_100 ( ( L_85 ) ) ;
return 0 ;
}
static void F_219 ( struct V_221 * V_74 )
{
struct V_3 * V_4 ;
V_4 = F_220 ( V_74 ) ;
if ( V_4 )
F_190 ( V_4 -> V_141 ) ;
F_204 ( V_74 , NULL ) ;
}
