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
F_6 ( V_4 -> V_11 -> V_12 ,
L_4 , V_6 ) ;
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
int V_13 ;
for ( V_13 = 0 ; V_13 < 8 ; V_13 ++ )
if ( V_4 -> V_8 [ V_13 ] ) {
F_8 ( V_4 -> V_8 [ V_13 ] ) ;
F_3 ( ( L_7 , V_13 ) ) ;
}
F_3 ( ( L_8 ) ) ;
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
F_28 ( ( L_9 , V_51 ) ) ;
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
F_29 ( V_50 ) ;
if ( ( V_6 = F_30 ( V_15 , 0 ,
V_27 ,
& V_17 -> V_59 ) ) < 0 )
return V_6 ;
if ( ( V_6 = F_31 ( V_15 ,
V_71 ) ) < 0 )
return V_6 ;
if ( ( V_6 = F_32 ( V_15 , 0 ,
V_72 ,
32 ) ) < 0 )
return V_6 ;
if ( ( V_6 = F_32 ( V_15 , 0 ,
V_73 ,
32 ) ) < 0 )
return V_6 ;
if ( ( V_6 = F_33 ( V_50 -> V_15 , 0 ,
V_44 ,
F_24 , V_4 ,
V_44 , - 1 ) ) < 0 )
return V_6 ;
if ( ( V_6 = F_34 ( V_74 ,
F_35 ( V_4 -> V_75 ) ,
V_76 , & V_17 -> V_19 ) ) < 0 ) {
F_28 ( ( L_10 ) ) ;
return V_6 ;
}
return 0 ;
}
static int F_36 ( struct V_49 * V_50 )
{
struct V_3 * V_4 = F_26 ( V_50 ) ;
int V_6 ;
F_3 ( ( L_11 ) ) ;
if ( ( V_6 = F_25 ( V_50 , F_37 ( V_4 ) -
V_50 -> V_77 ) ) < 0 )
return V_6 ;
if ( ( V_6 = F_33 ( V_50 -> V_15 , 0 ,
V_27 ,
F_19 , NULL ,
V_30 , - 1 ) ) < 0 )
return V_6 ;
if ( ( V_6 = F_33 ( V_50 -> V_15 , 0 ,
V_30 ,
F_13 , NULL ,
V_27 , - 1 ) ) < 0 )
return V_6 ;
F_38 ( & V_4 -> V_78 ) ;
if ( F_39 ( & V_4 -> V_78 ) > 1 && V_4 -> V_79 )
V_4 -> V_47 = 0 ;
F_28 ( ( L_12 ,
V_4 -> V_47 , F_39 ( & V_4 -> V_78 ) ,
V_4 -> V_48 ) ) ;
return 0 ;
}
static int F_40 ( struct V_49 * V_50 )
{
struct V_3 * V_4 = F_26 ( V_50 ) ;
int V_51 , V_6 ;
#ifdef F_41
V_51 = F_42 ( V_4 ) ;
#else
V_51 = F_43 ( V_4 ) ;
#endif
F_3 ( ( L_13 ) ) ;
if ( ( V_6 = F_25 ( V_50 , V_51 - V_50 -> V_77 ) ) < 0 )
return V_6 ;
if ( ( V_6 = F_33 ( V_50 -> V_15 , 0 ,
V_27 ,
F_23 ,
NULL ,
V_30 , - 1 ) ) < 0 )
return V_6 ;
if ( ( V_6 = F_33 ( V_50 -> V_15 , 0 ,
V_30 ,
F_22 ,
NULL ,
V_27 , - 1 ) ) < 0 )
return V_6 ;
F_38 ( & V_4 -> V_78 ) ;
if ( F_39 ( & V_4 -> V_78 ) > 1 && V_4 -> V_79 )
V_4 -> V_47 = 0 ;
F_28 ( ( L_14 ,
V_4 -> V_47 , F_39 ( & V_4 -> V_78 ) ,
V_4 -> V_48 ) ) ;
return 0 ;
}
static int F_44 ( struct V_49 * V_50 )
{
struct V_3 * V_4 = F_26 ( V_50 ) ;
int V_6 , V_51 ;
F_3 ( ( L_15 ) ) ;
V_51 = F_45 ( V_4 ) - V_50 -> V_77 ;
F_46 ( & V_4 -> V_80 ) ;
if ( V_4 -> V_65 == V_66 )
V_6 = F_25 ( V_50 , V_51 ) ;
else
V_6 = F_25 ( V_50 , V_51 - V_81 ) ;
if ( V_6 < 0 )
goto V_82;
if ( ( V_6 = F_33 ( V_50 -> V_15 , 0 ,
V_27 ,
F_19 , NULL ,
V_30 , - 1 ) ) < 0 )
goto V_82;
if ( ( V_6 = F_33 ( V_50 -> V_15 , 0 ,
V_30 ,
F_13 , NULL ,
V_27 , - 1 ) ) < 0 )
goto V_82;
F_38 ( & V_4 -> V_78 ) ;
if ( F_39 ( & V_4 -> V_78 ) > 1 && V_4 -> V_79 )
V_4 -> V_47 = 0 ;
V_82:
F_47 ( & V_4 -> V_80 ) ;
return V_6 ;
}
static int F_48 ( struct V_49 * V_50 )
{
struct V_3 * V_4 = F_26 ( V_50 ) ;
int V_6 , V_51 ;
F_3 ( ( L_16 ) ) ;
V_51 = F_49 ( V_4 ) - V_50 -> V_77 ;
F_46 ( & V_4 -> V_80 ) ;
if ( V_4 -> V_65 == V_66 )
V_6 = F_25 ( V_50 , V_51 ) ;
else
V_6 = F_25 ( V_50 , V_51 - V_81 ) ;
if ( V_6 < 0 )
goto V_83;
if ( ( V_6 = F_33 ( V_50 -> V_15 , 0 ,
V_27 ,
F_23 ,
NULL , V_30 ,
- 1 ) ) < 0 )
goto V_83;
if ( ( V_6 = F_33 ( V_50 -> V_15 , 0 ,
V_30 ,
F_22 ,
NULL , V_27 ,
- 1 ) ) < 0 )
goto V_83;
F_38 ( & V_4 -> V_78 ) ;
if ( F_39 ( & V_4 -> V_78 ) > 1 && V_4 -> V_79 )
V_4 -> V_47 = 0 ;
V_83:
F_47 ( & V_4 -> V_80 ) ;
return V_6 ;
}
static int F_50 ( struct V_49 * V_50 )
{
struct V_3 * V_4 = F_26 ( V_50 ) ;
int V_84 ;
F_3 ( ( L_17 ) ) ;
F_51 ( & V_4 -> V_78 ) ;
V_84 = F_39 ( & V_4 -> V_78 ) ;
F_3 ( ( L_18 , V_84 ,
V_4 -> V_47 , V_4 -> V_79 ) ) ;
if ( V_84 < 2 )
V_4 -> V_47 = 1 ;
if ( V_84 == 0 )
V_4 -> V_79 = 0 ;
F_3 ( ( L_19 , V_84 ,
V_4 -> V_47 , V_4 -> V_79 ) ) ;
return 0 ;
}
static int F_52 ( struct V_49 * V_50 ,
struct V_21 * V_85 ,
int V_86 , int V_87 )
{
struct V_3 * V_4 ;
int V_6 , V_88 , V_89 , V_90 , V_91 , V_92 ;
struct V_16 * V_17 ;
V_4 = F_26 ( V_50 ) ;
V_17 = (struct V_16 * ) V_50 -> V_15 -> V_18 ;
F_53 ( & V_4 -> V_93 ) ;
if ( V_17 -> V_55 >= 0 ) {
F_28 ( ( L_20 , V_17 -> V_55 ) ) ;
V_6 = F_54 ( V_4 , V_17 ) ;
F_55 ( V_6 ) ;
V_4 -> V_50 [ V_17 -> V_55 ] = NULL ;
}
V_6 = F_56 ( V_4 , V_17 , V_86 , V_87 ) ;
if ( V_6 < 0 ) {
F_57 ( & V_4 -> V_93 ) ;
F_3 ( ( V_94 L_21 ,
V_86 , V_6 ) ) ;
return V_6 ;
}
F_57 ( & V_4 -> V_93 ) ;
F_3 ( ( V_94 L_22 , V_86 ) ) ;
F_28 ( ( L_23 ,
F_58 ( V_85 ) , F_59 ( V_85 ) ,
F_60 ( V_85 ) ) ) ;
V_6 = F_61 ( V_50 ,
F_58 ( V_85 ) ) ;
if ( V_6 < 0 ) {
F_6 ( V_4 -> V_11 -> V_12 , L_24 , V_6 ) ;
F_53 ( & V_4 -> V_93 ) ;
F_54 ( V_4 , V_17 ) ;
F_57 ( & V_4 -> V_93 ) ;
V_17 -> V_55 = - 1 ;
return V_6 ;
}
F_62 ( V_4 , V_17 ) ;
V_91 = V_76 ;
for ( V_92 = V_90 = V_88 = 0 ; V_92 < F_58 ( V_85 ) ;
V_88 ++ ) {
V_89 = F_60 ( V_85 ) ;
if ( V_92 + V_89 > F_58 ( V_85 ) )
V_89 = F_58 ( V_85 ) - V_92 ;
while ( V_89 ) {
T_2 V_95 ;
V_95 = F_63 ( V_50 , V_92 ) ;
if ( V_89 <= V_91 - V_92 ) {
F_64 ( V_4 , V_17 , V_95 , V_89 ) ;
F_65 ( V_4 , V_17 ) ;
V_92 += V_89 ;
V_89 = 0 ;
} else {
F_64 ( V_4 , V_17 , V_95 ,
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
F_66 ( V_4 , V_17 ) ;
V_4 -> V_96 [ V_86 ] = 0 ;
V_17 -> V_97 = 0 ;
V_17 -> V_98 = 0 ;
F_67 () ;
V_4 -> V_50 [ V_86 ] = V_50 ;
V_4 -> V_79 = 1 ;
F_53 ( & V_4 -> V_93 ) ;
F_68 ( V_4 , V_85 -> V_99 / V_85 -> V_100 ) ;
F_57 ( & V_4 -> V_93 ) ;
F_28 ( ( L_25 ) ) ;
return 0 ;
}
static int F_69 ( struct V_49 * V_50 ,
struct V_21 * V_85 )
{
struct V_3 * V_4 = F_26 ( V_50 ) ;
return F_52 ( V_50 , V_85 , F_70 ( V_4 ) +
V_50 -> V_77 , F_71 ( V_85 ) ) ;
}
static int F_72 ( struct V_49 * V_50 ,
struct V_21 * V_85 )
{
return F_52 ( V_50 , V_85 , V_50 -> V_77 ,
F_71 ( V_85 ) ) ;
}
static int F_73 ( struct V_49 * V_50 ,
struct V_21 * V_85 )
{
struct V_3 * V_4 = F_26 ( V_50 ) ;
return F_52 ( V_50 , V_85 , F_74 ( V_4 ) +
V_50 -> V_77 , F_71 ( V_85 ) ) ;
}
static int F_75 ( struct V_49 * V_50 ,
struct V_21 * V_85 )
{
struct V_3 * V_4 = F_26 ( V_50 ) ;
return F_52 ( V_50 , V_85 , F_76 ( V_4 ) +
V_50 -> V_77 , F_71 ( V_85 ) ) ;
}
static int F_77 ( struct V_49 * V_50 )
{
struct V_3 * V_4 ;
struct V_16 * V_17 ;
V_4 = F_26 ( V_50 ) ;
V_17 = (struct V_16 * ) V_50 -> V_15 -> V_18 ;
F_53 ( & V_4 -> V_93 ) ;
if ( V_17 -> V_55 >= 0 ) {
F_28 ( ( L_26 , V_17 -> V_55 ) ) ;
F_54 ( V_4 , V_17 ) ;
V_4 -> V_50 [ V_17 -> V_55 ] = NULL ;
V_17 -> V_55 = - 1 ;
}
F_57 ( & V_4 -> V_93 ) ;
F_28 ( ( L_27 ) ) ;
F_78 ( V_50 ) ;
return 0 ;
}
static int F_79 ( struct V_49 * V_50 )
{
struct V_3 * V_4 = F_26 ( V_50 ) ;
struct V_14 * V_15 = V_50 -> V_15 ;
struct V_101 V_102 ;
int V_86 = ( (struct V_16 * ) V_15 -> V_18 ) -> V_55 ;
F_28 ( ( L_28 ,
V_15 -> V_43 , V_15 -> V_102 , V_15 -> V_103 ) ) ;
V_102 . V_87 = V_15 -> V_103 ;
V_102 . V_104 = 0 ;
V_102 . V_105 = 0 ;
switch ( V_15 -> V_102 ) {
case V_106 :
V_102 . V_107 = 8 ;
break;
case V_108 :
V_102 . V_107 = 16 ;
break;
case V_109 :
V_102 . V_107 = 24 ;
break;
case V_110 :
V_102 . V_104 = 1 ;
case V_111 :
V_102 . V_107 = 32 ;
break;
default:
F_28 ( ( L_29 ,
V_15 -> V_102 ) ) ;
return - V_112 ;
}
if ( F_55 ( V_86 >= F_80 ( V_4 ) ) )
return - V_112 ;
if ( F_55 ( ! F_81 ( V_4 , V_86 ) ) )
return - V_112 ;
F_82 ( V_4 , V_86 , & V_102 ) ;
return 0 ;
}
static int F_83 ( struct V_49 * V_50 , int V_113 )
{
struct V_3 * V_4 = F_26 ( V_50 ) ;
struct V_14 * V_15 = V_50 -> V_15 ;
struct V_16 * V_17 = V_15 -> V_18 ;
int V_13 , V_6 ;
V_42 V_114 = 0 ;
struct V_49 * V_115 ;
F_84 (s, substream) {
for ( V_13 = 0 ; V_13 < V_116 ; V_13 ++ ) {
if ( V_115 == V_4 -> V_50 [ V_13 ] ) {
V_114 |= 1 << V_13 ;
F_85 ( V_115 , V_50 ) ;
}
}
}
F_86 ( & V_4 -> V_93 ) ;
switch ( V_113 ) {
case V_117 :
F_3 ( ( L_30 ) ) ;
case V_118 :
case V_119 :
F_3 ( ( L_31 ) ) ;
for ( V_13 = 0 ; V_13 < V_116 ; V_13 ++ ) {
if ( V_114 & ( 1 << V_13 ) ) {
V_17 = V_4 -> V_50 [ V_13 ] -> V_15 -> V_18 ;
switch ( V_17 -> V_120 ) {
case V_121 :
V_4 -> V_96 [ V_13 ] = 0 ;
V_17 -> V_97 = 0 ;
V_17 -> V_98 = 0 ;
* V_17 -> V_122 = 0 ;
case V_123 :
V_17 -> V_120 = V_124 ;
break;
case V_124 :
break;
}
}
}
V_6 = F_87 ( V_4 , V_114 ,
V_4 -> V_125 ) ;
break;
case V_126 :
F_3 ( ( L_32 ) ) ;
case V_127 :
F_3 ( ( L_33 ) ) ;
for ( V_13 = 0 ; V_13 < V_116 ; V_13 ++ ) {
if ( V_114 & ( 1 << V_13 ) ) {
V_17 = V_4 -> V_50 [ V_13 ] -> V_15 -> V_18 ;
V_17 -> V_120 = V_121 ;
}
}
V_6 = F_88 ( V_4 , V_114 ) ;
break;
case V_128 :
F_3 ( ( L_34 ) ) ;
for ( V_13 = 0 ; V_13 < V_116 ; V_13 ++ ) {
if ( V_114 & ( 1 << V_13 ) ) {
V_17 = V_4 -> V_50 [ V_13 ] -> V_15 -> V_18 ;
V_17 -> V_120 = V_123 ;
}
}
V_6 = F_89 ( V_4 , V_114 ) ;
break;
default:
V_6 = - V_112 ;
}
F_90 ( & V_4 -> V_93 ) ;
return V_6 ;
}
static T_3 F_91 ( struct V_49 * V_50 )
{
struct V_14 * V_15 = V_50 -> V_15 ;
struct V_16 * V_17 = V_15 -> V_18 ;
T_4 V_129 , V_130 , V_131 ;
V_129 = F_92 ( * V_17 -> V_122 ) ;
V_17 -> V_98 += V_129 - V_17 -> V_97 ;
V_17 -> V_97 = V_129 ;
V_130 = V_50 -> V_15 -> V_132 ;
V_131 = F_93 ( V_50 -> V_15 , V_17 -> V_98 ) ;
while ( V_131 >= V_130 ) {
V_17 -> V_98 -= F_94 ( V_50 -> V_15 , V_130 ) ;
V_131 -= V_130 ;
}
return V_131 ;
}
static int F_95 ( struct V_133 * V_134 , struct V_135 * V_12 )
{
struct V_49 * V_136 ;
int V_137 , V_6 ;
for ( V_137 = 0 ; V_137 < 2 ; V_137 ++ )
for ( V_136 = V_134 -> V_138 [ V_137 ] . V_50 ; V_136 ; V_136 = V_136 -> V_139 ) {
V_6 = F_96 ( V_136 , V_140 ,
V_12 ,
V_136 -> V_77 ? 0 : 128 << 10 ,
256 << 10 ) ;
if ( V_6 < 0 )
return V_6 ;
}
return 0 ;
}
static int F_97 ( struct V_3 * V_4 )
{
struct V_133 * V_134 ;
int V_6 ;
#ifdef F_41
if ( ( V_6 = F_98 ( V_4 -> V_11 , L_35 , 0 , F_42 ( V_4 ) ,
F_37 ( V_4 ) , & V_134 ) ) < 0 )
return V_6 ;
V_134 -> V_18 = V_4 ;
V_4 -> V_141 = V_134 ;
strcpy ( V_134 -> V_7 , V_4 -> V_11 -> V_142 ) ;
F_99 ( V_134 , V_143 , & V_144 ) ;
F_99 ( V_134 , V_145 , & V_146 ) ;
if ( ( V_6 = F_95 ( V_134 , F_35 ( V_4 -> V_75 ) ) ) < 0 )
return V_6 ;
F_100 ( ( L_36 ) ) ;
#ifdef F_101
if ( ( V_6 = F_98 ( V_4 -> V_11 , L_37 , 1 , 0 ,
F_45 ( V_4 ) , & V_134 ) ) < 0 )
return V_6 ;
V_134 -> V_18 = V_4 ;
V_4 -> V_147 = V_134 ;
strcpy ( V_134 -> V_7 , V_4 -> V_11 -> V_142 ) ;
F_99 ( V_134 , V_145 , & V_148 ) ;
if ( ( V_6 = F_95 ( V_134 , F_35 ( V_4 -> V_75 ) ) ) < 0 )
return V_6 ;
F_100 ( ( L_38 ) ) ;
#endif
#else
if ( ( V_6 = F_98 ( V_4 -> V_11 , L_39 , 0 ,
F_43 ( V_4 ) ,
F_37 ( V_4 ) , & V_134 ) ) < 0 )
return V_6 ;
V_134 -> V_18 = V_4 ;
V_4 -> V_141 = V_134 ;
strcpy ( V_134 -> V_7 , V_4 -> V_11 -> V_142 ) ;
F_99 ( V_134 , V_143 , & V_144 ) ;
F_99 ( V_134 , V_145 , & V_146 ) ;
if ( ( V_6 = F_95 ( V_134 , F_35 ( V_4 -> V_75 ) ) ) < 0 )
return V_6 ;
F_100 ( ( L_36 ) ) ;
#ifdef F_101
if ( ( V_6 = F_98 ( V_4 -> V_11 , L_37 , 1 ,
F_49 ( V_4 ) ,
F_45 ( V_4 ) , & V_134 ) ) < 0 )
return V_6 ;
V_134 -> V_18 = V_4 ;
V_4 -> V_147 = V_134 ;
strcpy ( V_134 -> V_7 , V_4 -> V_11 -> V_142 ) ;
F_99 ( V_134 , V_143 , & V_149 ) ;
F_99 ( V_134 , V_145 , & V_148 ) ;
if ( ( V_6 = F_95 ( V_134 , F_35 ( V_4 -> V_75 ) ) ) < 0 )
return V_6 ;
F_100 ( ( L_38 ) ) ;
#endif
#endif
return 0 ;
}
static int F_102 ( struct V_150 * V_151 ,
struct V_152 * V_153 )
{
struct V_3 * V_4 ;
V_4 = F_103 ( V_151 ) ;
V_153 -> type = V_154 ;
V_153 -> V_63 = F_104 ( V_4 ) ;
V_153 -> V_155 . integer . V_32 = V_156 ;
V_153 -> V_155 . integer . V_37 = V_157 ;
return 0 ;
}
static int F_105 ( struct V_150 * V_151 ,
struct V_158 * V_159 )
{
struct V_3 * V_4 ;
int V_26 ;
V_4 = F_103 ( V_151 ) ;
for ( V_26 = 0 ; V_26 < F_104 ( V_4 ) ; V_26 ++ )
V_159 -> V_155 . integer . V_155 [ V_26 ] = V_4 -> V_160 [ V_26 ] ;
return 0 ;
}
static int F_106 ( struct V_150 * V_151 ,
struct V_158 * V_159 )
{
struct V_3 * V_4 ;
int V_26 , V_161 , V_162 ;
V_161 = 0 ;
V_4 = F_103 ( V_151 ) ;
F_53 ( & V_4 -> V_93 ) ;
for ( V_26 = 0 ; V_26 < F_104 ( V_4 ) ; V_26 ++ ) {
V_162 = V_159 -> V_155 . integer . V_155 [ V_26 ] ;
if ( V_162 < V_156 || V_162 > V_157 )
continue;
if ( V_4 -> V_160 [ V_26 ] != V_162 ) {
F_107 ( V_4 , V_26 , V_162 ) ;
V_161 = 1 ;
}
}
if ( V_161 )
F_108 ( V_4 ) ;
F_57 ( & V_4 -> V_93 ) ;
return V_161 ;
}
static int F_109 ( struct V_150 * V_151 ,
struct V_152 * V_153 )
{
struct V_3 * V_4 ;
V_4 = F_103 ( V_151 ) ;
V_153 -> type = V_154 ;
V_153 -> V_63 = F_37 ( V_4 ) ;
V_153 -> V_155 . integer . V_32 = V_163 ;
V_153 -> V_155 . integer . V_37 = V_164 ;
return 0 ;
}
static int F_110 ( struct V_150 * V_151 ,
struct V_158 * V_159 )
{
struct V_3 * V_4 ;
int V_26 ;
V_4 = F_103 ( V_151 ) ;
for ( V_26 = 0 ; V_26 < F_37 ( V_4 ) ; V_26 ++ )
V_159 -> V_155 . integer . V_155 [ V_26 ] = V_4 -> V_165 [ V_26 ] ;
return 0 ;
}
static int F_111 ( struct V_150 * V_151 ,
struct V_158 * V_159 )
{
struct V_3 * V_4 ;
int V_26 , V_162 , V_161 ;
V_161 = 0 ;
V_4 = F_103 ( V_151 ) ;
F_53 ( & V_4 -> V_93 ) ;
for ( V_26 = 0 ; V_26 < F_37 ( V_4 ) ; V_26 ++ ) {
V_162 = V_159 -> V_155 . integer . V_155 [ V_26 ] ;
if ( V_162 < V_163 || V_162 > V_164 )
continue;
if ( V_4 -> V_165 [ V_26 ] != V_162 ) {
F_112 ( V_4 , V_26 , V_162 ) ;
V_161 = 1 ;
}
}
if ( V_161 )
F_113 ( V_4 ) ;
F_57 ( & V_4 -> V_93 ) ;
return V_161 ;
}
static int F_114 ( struct V_150 * V_151 ,
struct V_152 * V_153 )
{
struct V_3 * V_4 ;
V_4 = F_103 ( V_151 ) ;
V_153 -> type = V_166 ;
V_153 -> V_63 = F_43 ( V_4 ) ;
V_153 -> V_155 . integer . V_32 = 0 ;
V_153 -> V_155 . integer . V_37 = 1 ;
return 0 ;
}
static int F_115 ( struct V_150 * V_151 ,
struct V_158 * V_159 )
{
struct V_3 * V_4 ;
int V_26 ;
V_4 = F_103 ( V_151 ) ;
for ( V_26 = 0 ; V_26 < F_43 ( V_4 ) ; V_26 ++ )
V_159 -> V_155 . integer . V_155 [ V_26 ] = V_4 -> V_167 [ V_26 ] ;
return 0 ;
}
static int F_116 ( struct V_150 * V_151 ,
struct V_158 * V_159 )
{
struct V_3 * V_4 ;
int V_26 , V_161 ;
V_161 = 0 ;
V_4 = F_103 ( V_151 ) ;
F_53 ( & V_4 -> V_93 ) ;
for ( V_26 = 0 ; V_26 < F_43 ( V_4 ) ; V_26 ++ ) {
if ( V_4 -> V_167 [ V_26 ] != V_159 -> V_155 . integer . V_155 [ V_26 ] ) {
F_117 ( V_4 , V_26 ,
V_159 -> V_155 . integer . V_155 [ V_26 ] ) ;
V_161 = 1 ;
}
}
if ( V_161 )
F_108 ( V_4 ) ;
F_57 ( & V_4 -> V_93 ) ;
return V_161 ;
}
static int F_118 ( struct V_150 * V_151 ,
struct V_152 * V_153 )
{
struct V_3 * V_4 ;
V_4 = F_103 ( V_151 ) ;
V_153 -> type = V_166 ;
V_153 -> V_63 = F_37 ( V_4 ) ;
V_153 -> V_155 . integer . V_32 = 0 ;
V_153 -> V_155 . integer . V_37 = 1 ;
return 0 ;
}
static int F_119 ( struct V_150 * V_151 ,
struct V_158 * V_159 )
{
struct V_3 * V_4 ;
int V_26 ;
V_4 = F_103 ( V_151 ) ;
for ( V_26 = 0 ; V_26 < F_37 ( V_4 ) ; V_26 ++ )
V_159 -> V_155 . integer . V_155 [ V_26 ] =
V_4 -> V_167 [ F_120 ( V_4 ) + V_26 ] ;
return 0 ;
}
static int F_121 ( struct V_150 * V_151 ,
struct V_158 * V_159 )
{
struct V_3 * V_4 ;
int V_26 , V_161 ;
V_161 = 0 ;
V_4 = F_103 ( V_151 ) ;
F_53 ( & V_4 -> V_93 ) ;
for ( V_26 = 0 ; V_26 < F_37 ( V_4 ) ; V_26 ++ ) {
if ( V_4 -> V_167 [ F_120 ( V_4 ) + V_26 ] !=
V_159 -> V_155 . integer . V_155 [ V_26 ] ) {
F_117 ( V_4 , F_120 ( V_4 ) + V_26 ,
V_159 -> V_155 . integer . V_155 [ V_26 ] ) ;
V_161 = 1 ;
}
}
if ( V_161 )
F_108 ( V_4 ) ;
F_57 ( & V_4 -> V_93 ) ;
return V_161 ;
}
static int F_122 ( struct V_150 * V_151 ,
struct V_152 * V_153 )
{
struct V_3 * V_4 ;
V_4 = F_103 ( V_151 ) ;
V_153 -> type = V_154 ;
V_153 -> V_63 = 1 ;
V_153 -> V_155 . integer . V_32 = V_156 ;
V_153 -> V_155 . integer . V_37 = V_157 ;
V_153 -> V_168 . V_169 [ 0 ] = F_104 ( V_4 ) ;
V_153 -> V_168 . V_169 [ 1 ] = F_123 ( V_4 ) ;
return 0 ;
}
static int F_124 ( struct V_150 * V_151 ,
struct V_158 * V_159 )
{
struct V_3 * V_4 ;
V_4 = F_103 ( V_151 ) ;
V_159 -> V_155 . integer . V_155 [ 0 ] =
V_4 -> V_170 [ V_159 -> V_171 . V_55 / F_123 ( V_4 ) ]
[ V_159 -> V_171 . V_55 % F_123 ( V_4 ) ] ;
return 0 ;
}
static int F_125 ( struct V_150 * V_151 ,
struct V_158 * V_159 )
{
struct V_3 * V_4 ;
int V_161 , V_162 ;
short V_172 , V_173 ;
V_161 = 0 ;
V_4 = F_103 ( V_151 ) ;
V_172 = V_159 -> V_171 . V_55 / F_123 ( V_4 ) ;
V_173 = V_159 -> V_171 . V_55 % F_123 ( V_4 ) ;
V_162 = V_159 -> V_155 . integer . V_155 [ 0 ] ;
if ( V_162 < V_156 || V_162 > V_157 )
return - V_112 ;
if ( V_4 -> V_170 [ V_172 ] [ V_173 ] != V_162 ) {
F_53 ( & V_4 -> V_93 ) ;
F_126 ( V_4 , V_172 , V_173 , V_162 ) ;
F_108 ( V_4 ) ;
F_57 ( & V_4 -> V_93 ) ;
V_161 = 1 ;
}
return V_161 ;
}
static int F_127 ( struct V_150 * V_151 ,
struct V_152 * V_153 )
{
struct V_3 * V_4 ;
V_4 = F_103 ( V_151 ) ;
V_153 -> type = V_154 ;
V_153 -> V_63 = 1 ;
V_153 -> V_155 . integer . V_32 = V_156 ;
V_153 -> V_155 . integer . V_37 = V_157 ;
V_153 -> V_168 . V_169 [ 0 ] = F_104 ( V_4 ) ;
V_153 -> V_168 . V_169 [ 1 ] = F_42 ( V_4 ) ;
return 0 ;
}
static int F_128 ( struct V_150 * V_151 ,
struct V_158 * V_159 )
{
struct V_3 * V_4 ;
V_4 = F_103 ( V_151 ) ;
V_159 -> V_155 . integer . V_155 [ 0 ] =
V_4 -> V_174 [ V_159 -> V_171 . V_55 / F_42 ( V_4 ) ]
[ V_159 -> V_171 . V_55 % F_42 ( V_4 ) ] ;
return 0 ;
}
static int F_129 ( struct V_150 * V_151 ,
struct V_158 * V_159 )
{
struct V_3 * V_4 ;
int V_162 , V_161 ;
short V_175 , V_172 ;
V_161 = 0 ;
V_4 = F_103 ( V_151 ) ;
V_172 = V_159 -> V_171 . V_55 / F_42 ( V_4 ) ;
V_175 = V_159 -> V_171 . V_55 % F_42 ( V_4 ) ;
V_162 = V_159 -> V_155 . integer . V_155 [ 0 ] ;
if ( V_162 < V_156 || V_162 > V_157 )
return - V_112 ;
if ( V_4 -> V_174 [ V_172 ] [ V_175 ] != V_159 -> V_155 . integer . V_155 [ 0 ] ) {
F_53 ( & V_4 -> V_93 ) ;
F_130 ( V_4 , V_172 , V_175 , V_159 -> V_155 . integer . V_155 [ 0 ] ) ;
F_131 ( V_4 ) ;
F_57 ( & V_4 -> V_93 ) ;
V_161 = 1 ;
}
return V_161 ;
}
static int F_132 ( struct V_150 * V_151 ,
struct V_152 * V_153 )
{
static char * V_176 [ 4 ] = {
L_40 , L_41 , L_42 ,
L_43
} ;
struct V_3 * V_4 ;
V_4 = F_103 ( V_151 ) ;
V_153 -> type = V_177 ;
V_153 -> V_155 . V_178 . V_179 = V_4 -> V_180 ;
V_153 -> V_63 = 1 ;
if ( V_153 -> V_155 . V_178 . V_181 >= V_4 -> V_180 )
V_153 -> V_155 . V_178 . V_181 = V_4 -> V_180 - 1 ;
strcpy ( V_153 -> V_155 . V_178 . V_7 , V_176 [
V_4 -> V_182 [ V_153 -> V_155 . V_178 . V_181 ] ] ) ;
return 0 ;
}
static int F_133 ( struct V_150 * V_151 ,
struct V_158 * V_159 )
{
struct V_3 * V_4 ;
int V_13 , V_183 ;
V_4 = F_103 ( V_151 ) ;
V_183 = V_4 -> V_65 ;
for ( V_13 = V_4 -> V_180 - 1 ; V_13 >= 0 ; V_13 -- )
if ( V_183 == V_4 -> V_182 [ V_13 ] ) {
V_159 -> V_155 . V_178 . V_181 [ 0 ] = V_13 ;
break;
}
return 0 ;
}
static int F_134 ( struct V_150 * V_151 ,
struct V_158 * V_159 )
{
struct V_3 * V_4 ;
int V_161 ;
unsigned short V_184 , V_185 ;
V_161 = 0 ;
V_4 = F_103 ( V_151 ) ;
V_184 = V_159 -> V_155 . V_178 . V_181 [ 0 ] ;
if ( V_184 >= V_4 -> V_180 )
return - V_112 ;
V_185 = V_4 -> V_182 [ V_184 ] ;
if ( V_185 != V_4 -> V_65 ) {
F_46 ( & V_4 -> V_80 ) ;
if ( F_39 ( & V_4 -> V_78 ) ) {
V_161 = - V_52 ;
} else {
V_161 = F_135 ( V_4 , V_185 ) ;
if ( V_161 > 0 && V_4 -> V_186 ) {
F_136 ( V_4 -> V_11 ,
V_187 ,
& V_4 -> V_186 -> V_171 ) ;
F_3 ( ( L_44 , V_161 ) ) ;
}
if ( V_161 >= 0 )
V_161 = 1 ;
}
F_47 ( & V_4 -> V_80 ) ;
}
return V_161 ;
}
static int F_137 ( struct V_150 * V_151 ,
struct V_152 * V_153 )
{
static char * V_176 [ 2 ] = { L_45 , L_46 } ;
V_153 -> type = V_177 ;
V_153 -> V_155 . V_178 . V_179 = 2 ;
V_153 -> V_63 = 1 ;
if ( V_153 -> V_155 . V_178 . V_181 )
V_153 -> V_155 . V_178 . V_181 = 1 ;
strcpy ( V_153 -> V_155 . V_178 . V_7 ,
V_176 [ V_153 -> V_155 . V_178 . V_181 ] ) ;
return 0 ;
}
static int F_138 ( struct V_150 * V_151 ,
struct V_158 * V_159 )
{
struct V_3 * V_4 ;
V_4 = F_103 ( V_151 ) ;
V_159 -> V_155 . V_178 . V_181 [ 0 ] = ! ! V_4 -> V_188 ;
return 0 ;
}
static int F_139 ( struct V_150 * V_151 ,
struct V_158 * V_159 )
{
struct V_3 * V_4 ;
int V_183 ;
V_4 = F_103 ( V_151 ) ;
V_183 = ! ! V_159 -> V_155 . V_178 . V_181 [ 0 ] ;
if ( V_183 != V_4 -> V_188 ) {
F_53 ( & V_4 -> V_93 ) ;
F_140 ( V_4 , V_183 ) ;
F_57 ( & V_4 -> V_93 ) ;
return 1 ;
}
return 0 ;
}
static int F_141 ( struct V_150 * V_151 ,
struct V_152 * V_153 )
{
static char * V_176 [ 8 ] = {
L_47 , L_48 , L_49 , L_50 , L_51 , L_52 ,
L_53 , L_54
} ;
struct V_3 * V_4 ;
V_4 = F_103 ( V_151 ) ;
V_153 -> type = V_177 ;
V_153 -> V_155 . V_178 . V_179 = V_4 -> V_189 ;
V_153 -> V_63 = 1 ;
if ( V_153 -> V_155 . V_178 . V_181 >= V_4 -> V_189 )
V_153 -> V_155 . V_178 . V_181 = V_4 -> V_189 - 1 ;
strcpy ( V_153 -> V_155 . V_178 . V_7 , V_176 [
V_4 -> V_190 [ V_153 -> V_155 . V_178 . V_181 ] ] ) ;
return 0 ;
}
static int F_142 ( struct V_150 * V_151 ,
struct V_158 * V_159 )
{
struct V_3 * V_4 ;
int V_13 , clock ;
V_4 = F_103 ( V_151 ) ;
clock = V_4 -> V_191 ;
for ( V_13 = 0 ; V_13 < V_4 -> V_189 ; V_13 ++ )
if ( clock == V_4 -> V_190 [ V_13 ] )
V_159 -> V_155 . V_178 . V_181 [ 0 ] = V_13 ;
return 0 ;
}
static int F_143 ( struct V_150 * V_151 ,
struct V_158 * V_159 )
{
struct V_3 * V_4 ;
int V_161 ;
unsigned int V_192 , V_193 ;
V_161 = 0 ;
V_4 = F_103 ( V_151 ) ;
V_192 = V_159 -> V_155 . V_178 . V_181 [ 0 ] ;
if ( V_192 >= V_4 -> V_194 )
return - V_112 ;
V_193 = V_4 -> V_190 [ V_192 ] ;
if ( V_4 -> V_191 != V_193 ) {
F_46 ( & V_4 -> V_80 ) ;
F_53 ( & V_4 -> V_93 ) ;
if ( ( V_161 = F_144 ( V_4 , V_193 ) ) == 0 )
V_161 = 1 ;
F_57 ( & V_4 -> V_93 ) ;
F_47 ( & V_4 -> V_80 ) ;
}
if ( V_161 < 0 )
F_3 ( ( L_55 , V_193 , V_161 ) ) ;
return V_161 ;
}
static int F_145 ( struct V_150 * V_151 ,
struct V_158 * V_159 )
{
struct V_3 * V_4 = F_103 ( V_151 ) ;
V_159 -> V_155 . integer . V_155 [ 0 ] = V_4 -> V_195 ;
return 0 ;
}
static int F_146 ( struct V_150 * V_151 ,
struct V_158 * V_159 )
{
struct V_3 * V_4 = F_103 ( V_151 ) ;
int V_196 , V_161 = 0 ;
V_196 = ! ! V_159 -> V_155 . integer . V_155 [ 0 ] ;
if ( V_4 -> V_195 != V_196 ) {
F_53 ( & V_4 -> V_93 ) ;
V_161 = F_147 ( V_4 , V_196 ) ;
F_57 ( & V_4 -> V_93 ) ;
if ( V_161 == 0 )
V_161 = 1 ;
}
return V_161 ;
}
static int F_148 ( struct V_150 * V_151 ,
struct V_158 * V_159 )
{
struct V_3 * V_4 = F_103 ( V_151 ) ;
V_159 -> V_155 . integer . V_155 [ 0 ] = V_4 -> V_197 ;
return 0 ;
}
static int F_149 ( struct V_150 * V_151 ,
struct V_158 * V_159 )
{
struct V_3 * V_4 = F_103 ( V_151 ) ;
int V_198 , V_161 = 0 ;
V_198 = ! ! V_159 -> V_155 . integer . V_155 [ 0 ] ;
if ( V_4 -> V_197 != V_198 ) {
F_53 ( & V_4 -> V_93 ) ;
V_161 = F_150 ( V_4 , V_198 ) ;
F_57 ( & V_4 -> V_93 ) ;
if ( V_161 == 0 )
V_161 = 1 ;
}
return V_161 ;
}
static int F_151 ( struct V_150 * V_151 ,
struct V_158 * V_159 )
{
struct V_3 * V_4 ;
V_4 = F_103 ( V_151 ) ;
F_53 ( & V_4 -> V_93 ) ;
F_152 ( V_4 , V_159 -> V_155 . integer . V_155 [ 0 ] ) ;
F_57 ( & V_4 -> V_93 ) ;
return 1 ;
}
static int F_153 ( struct V_150 * V_151 ,
struct V_152 * V_153 )
{
struct V_3 * V_4 ;
V_4 = F_103 ( V_151 ) ;
V_153 -> type = V_154 ;
V_153 -> V_63 = 96 ;
V_153 -> V_155 . integer . V_32 = V_156 ;
V_153 -> V_155 . integer . V_37 = 0 ;
#ifdef F_41
V_153 -> V_168 . V_169 [ 0 ] = 3 ;
#else
V_153 -> V_168 . V_169 [ 0 ] = 2 ;
#endif
V_153 -> V_168 . V_169 [ 1 ] = 16 ;
V_153 -> V_168 . V_169 [ 2 ] = 2 ;
return 0 ;
}
static int F_154 ( struct V_150 * V_151 ,
struct V_158 * V_159 )
{
struct V_3 * V_4 ;
V_4 = F_103 ( V_151 ) ;
F_155 ( V_4 , V_159 -> V_155 . integer . V_155 ) ;
return 0 ;
}
static int F_156 ( struct V_150 * V_151 ,
struct V_152 * V_153 )
{
struct V_3 * V_4 ;
V_4 = F_103 ( V_151 ) ;
V_153 -> type = V_154 ;
V_153 -> V_63 = 6 ;
V_153 -> V_155 . integer . V_32 = 0 ;
V_153 -> V_155 . integer . V_37 = 1 << V_199 ;
return 0 ;
}
static int F_157 ( struct V_150 * V_151 ,
struct V_158 * V_159 )
{
struct V_3 * V_4 ;
int V_200 , V_201 , V_202 , V_203 ;
V_4 = F_103 ( V_151 ) ;
V_159 -> V_155 . integer . V_155 [ 0 ] = F_123 ( V_4 ) ;
V_159 -> V_155 . integer . V_155 [ 1 ] = F_37 ( V_4 ) ;
V_159 -> V_155 . integer . V_155 [ 2 ] = F_104 ( V_4 ) ;
V_159 -> V_155 . integer . V_155 [ 3 ] = F_43 ( V_4 ) ;
V_159 -> V_155 . integer . V_155 [ 4 ] = F_42 ( V_4 ) ;
V_200 = F_158 ( V_4 ) ;
V_201 = 0 ;
V_203 = V_4 -> V_189 - 1 ;
for ( V_202 = V_199 - 1 ; V_202 >= 0 ; V_202 -- )
if ( V_200 & ( 1 << V_202 ) )
for (; V_203 >= 0 ; V_203 -- )
if ( V_202 == V_4 -> V_190 [ V_203 ] ) {
V_201 |= 1 << V_203 ;
break;
}
V_159 -> V_155 . integer . V_155 [ 5 ] = V_201 ;
return 0 ;
}
static T_5 F_159 ( int V_204 , void * V_205 )
{
struct V_3 * V_4 = V_205 ;
struct V_49 * V_50 ;
int V_206 , V_136 , V_207 ;
F_86 ( & V_4 -> V_93 ) ;
V_207 = F_160 ( V_4 ) ;
if ( V_207 < 0 ) {
F_90 ( & V_4 -> V_93 ) ;
return V_208 ;
}
for ( V_136 = 0 ; V_136 < V_116 ; V_136 ++ ) {
V_50 = V_4 -> V_50 [ V_136 ] ;
if ( V_50 && ( (struct V_16 * ) V_50 -> V_15 ->
V_18 ) -> V_120 == V_124 ) {
V_206 = F_91 ( V_50 ) /
V_50 -> V_15 -> V_209 ;
if ( V_206 != V_4 -> V_96 [ V_136 ] ) {
V_4 -> V_96 [ V_136 ] = V_206 ;
F_90 ( & V_4 -> V_93 ) ;
F_161 ( V_50 ) ;
F_86 ( & V_4 -> V_93 ) ;
}
}
}
F_90 ( & V_4 -> V_93 ) ;
#ifdef F_162
if ( V_207 > 0 && V_4 -> V_210 ) {
F_163 ( V_4 -> V_210 , V_4 -> V_211 , V_207 ) ;
F_164 ( ( L_56 , V_207 ) ) ;
}
#endif
return V_212 ;
}
static int F_165 ( struct V_3 * V_4 )
{
F_100 ( ( L_57 ) ) ;
if ( V_4 -> V_213 )
F_166 ( V_4 ) ;
F_100 ( ( L_58 ) ) ;
if ( V_4 -> V_204 >= 0 )
F_167 ( V_4 -> V_204 , V_4 ) ;
if ( V_4 -> V_213 )
F_11 ( & V_4 -> V_214 ) ;
if ( V_4 -> V_215 )
F_168 ( V_4 -> V_215 ) ;
if ( V_4 -> V_216 )
F_169 ( V_4 -> V_216 ) ;
F_100 ( ( L_59 ) ) ;
F_170 ( V_4 -> V_75 ) ;
F_9 ( V_4 ) ;
F_12 ( V_4 ) ;
F_100 ( ( L_60 ) ) ;
return 0 ;
}
static int F_171 ( struct V_217 * V_135 )
{
struct V_3 * V_4 = V_135 -> V_218 ;
F_100 ( ( L_61 ) ) ;
return F_165 ( V_4 ) ;
}
static int F_172 ( struct V_219 * V_11 ,
struct V_220 * V_75 ,
struct V_3 * * V_221 )
{
struct V_3 * V_4 ;
int V_6 ;
T_4 V_222 ;
static struct V_223 V_224 = {
. V_225 = F_171 ,
} ;
* V_221 = NULL ;
F_173 ( V_75 , V_226 , 0xC0 ) ;
if ( ( V_6 = F_174 ( V_75 ) ) < 0 )
return V_6 ;
F_175 ( V_75 ) ;
if ( ! * V_221 ) {
V_4 = F_27 ( sizeof( * V_4 ) , V_53 ) ;
if ( ! V_4 ) {
F_170 ( V_75 ) ;
return - V_54 ;
}
F_100 ( ( L_62 , V_4 ) ) ;
F_176 ( & V_4 -> V_93 ) ;
V_4 -> V_11 = V_11 ;
V_4 -> V_75 = V_75 ;
V_4 -> V_204 = - 1 ;
F_177 ( & V_4 -> V_78 , 0 ) ;
F_178 ( & V_4 -> V_80 ) ;
V_4 -> V_47 = 1 ;
} else {
V_4 = * V_221 ;
}
V_4 -> V_227 = F_179 ( V_75 , 0 ) ;
V_222 = F_180 ( V_75 , 0 ) ;
if ( V_222 > V_76 )
V_222 = V_76 ;
if ( ( V_4 -> V_216 = F_181 ( V_4 -> V_227 , V_222 ,
V_228 ) ) == NULL ) {
F_6 ( V_4 -> V_11 -> V_12 , L_63 ) ;
F_165 ( V_4 ) ;
return - V_229 ;
}
V_4 -> V_215 = ( volatile V_42 V_230 * )
F_182 ( V_4 -> V_227 , V_222 ) ;
if ( F_183 ( V_75 -> V_204 , F_159 , V_231 ,
V_232 , V_4 ) ) {
F_6 ( V_4 -> V_11 -> V_12 , L_64 ) ;
F_165 ( V_4 ) ;
return - V_229 ;
}
V_4 -> V_204 = V_75 -> V_204 ;
F_100 ( ( L_65 ,
V_4 -> V_75 , V_4 -> V_204 , V_4 -> V_75 -> V_233 ) ) ;
if ( F_34 ( V_74 , F_35 ( V_4 -> V_75 ) ,
sizeof( struct V_213 ) ,
& V_4 -> V_214 ) < 0 ) {
F_6 ( V_4 -> V_11 -> V_12 , L_66 ) ;
F_165 ( V_4 ) ;
return - V_54 ;
}
V_4 -> V_234 = V_4 -> V_214 . V_95 ;
V_4 -> V_213 = (struct V_213 * ) V_4 -> V_214 . V_20 ;
V_6 = F_184 ( V_4 , V_4 -> V_75 -> V_135 , V_4 -> V_75 -> V_233 ) ;
if ( V_6 >= 0 )
V_6 = F_185 ( V_4 ) ;
if ( V_6 < 0 ) {
F_100 ( ( L_67 , V_6 ) ) ;
F_165 ( V_4 ) ;
return V_6 ;
}
F_100 ( ( L_68 ) ) ;
if ( ( V_6 = F_186 ( V_11 , V_235 , V_4 , & V_224 ) ) < 0 ) {
F_165 ( V_4 ) ;
return V_6 ;
}
* V_221 = V_4 ;
return 0 ;
}
static int F_187 ( struct V_220 * V_75 ,
const struct V_236 * V_237 )
{
static int V_12 ;
struct V_219 * V_11 ;
struct V_3 * V_4 ;
char * V_238 ;
int V_13 , V_6 ;
if ( V_12 >= V_239 )
return - V_240 ;
if ( ! V_241 [ V_12 ] ) {
V_12 ++ ;
return - V_242 ;
}
F_100 ( ( L_69 ) ) ;
V_13 = 0 ;
V_6 = F_188 ( & V_75 -> V_12 , V_55 [ V_12 ] , V_171 [ V_12 ] , V_243 ,
0 , & V_11 ) ;
if ( V_6 < 0 )
return V_6 ;
V_4 = NULL ;
if ( ( V_6 = F_172 ( V_11 , V_75 , & V_4 ) ) < 0 ) {
F_189 ( V_11 ) ;
return V_6 ;
}
strcpy ( V_11 -> V_244 , L_70 V_228 ) ;
strcpy ( V_11 -> V_142 , V_4 -> V_245 ) ;
V_238 = L_71 ;
if ( V_237 -> V_135 == 0x3410 )
V_238 = L_72 ;
sprintf ( V_11 -> V_246 , L_73 ,
V_11 -> V_142 , V_237 -> V_247 & 0x000f , V_238 ,
V_4 -> V_227 , V_4 -> V_204 ) ;
if ( ( V_6 = F_97 ( V_4 ) ) < 0 ) {
F_6 ( V_4 -> V_11 -> V_12 , L_74 , V_6 ) ;
F_189 ( V_11 ) ;
return V_6 ;
}
#ifdef F_162
if ( V_4 -> V_248 ) {
if ( ( V_6 = F_190 ( V_11 , V_4 ) ) < 0 ) {
F_6 ( V_4 -> V_11 -> V_12 , L_75 , V_6 ) ;
F_189 ( V_11 ) ;
return V_6 ;
}
}
#endif
#ifdef F_41
V_249 . V_63 = F_42 ( V_4 ) * F_104 ( V_4 ) ;
if ( ( V_6 = F_191 ( V_4 -> V_11 , F_192 ( & V_249 , V_4 ) ) ) < 0 )
goto V_250;
#ifdef F_193
V_6 = F_191 ( V_4 -> V_11 ,
F_192 ( & V_251 , V_4 ) ) ;
if ( V_6 < 0 )
goto V_250;
#endif
#else
V_6 = F_191 ( V_4 -> V_11 ,
F_192 ( & V_252 , V_4 ) ) ;
if ( V_6 < 0 )
goto V_250;
#endif
#ifdef F_194
if ( ( V_6 = F_191 ( V_4 -> V_11 , F_192 ( & V_253 , V_4 ) ) ) < 0 )
goto V_250;
#endif
#ifdef F_195
if ( ! V_4 -> V_254 )
if ( ( V_6 = F_191 ( V_4 -> V_11 , F_192 ( & V_255 , V_4 ) ) ) < 0 )
goto V_250;
#endif
#ifdef F_196
if ( ( V_6 = F_191 ( V_4 -> V_11 , F_192 ( & V_256 , V_4 ) ) ) < 0 )
goto V_250;
#endif
if ( ( V_6 = F_191 ( V_4 -> V_11 , F_192 ( & V_257 , V_4 ) ) ) < 0 )
goto V_250;
if ( ( V_6 = F_191 ( V_4 -> V_11 , F_192 ( & V_258 , V_4 ) ) ) < 0 )
goto V_250;
#ifdef F_197
V_259 . V_63 = F_123 ( V_4 ) * F_104 ( V_4 ) ;
if ( ( V_6 = F_191 ( V_4 -> V_11 , F_192 ( & V_259 , V_4 ) ) ) < 0 )
goto V_250;
#endif
#ifdef F_198
if ( ( V_6 = F_191 ( V_4 -> V_11 , F_192 ( & V_260 , V_4 ) ) ) < 0 )
goto V_250;
#endif
if ( ( V_6 = F_191 ( V_4 -> V_11 , F_192 ( & V_261 , V_4 ) ) ) < 0 )
goto V_250;
#ifdef F_199
V_4 -> V_180 = 0 ;
for ( V_13 = 0 ; V_13 < 6 ; V_13 ++ )
if ( V_4 -> V_262 & ( 1 << V_13 ) )
V_4 -> V_182 [ V_4 -> V_180 ++ ] = V_13 ;
if ( ( V_6 = F_191 ( V_4 -> V_11 , F_192 ( & V_263 , V_4 ) ) ) < 0 )
goto V_250;
#endif
#ifdef F_200
V_4 -> V_189 = 0 ;
for ( V_13 = 0 ; V_13 < 10 ; V_13 ++ )
if ( V_4 -> V_194 & ( 1 << V_13 ) )
V_4 -> V_190 [ V_4 -> V_189 ++ ] = V_13 ;
if ( V_4 -> V_189 > 1 ) {
V_4 -> V_186 = F_192 ( & V_264 , V_4 ) ;
if ( ( V_6 = F_191 ( V_4 -> V_11 , V_4 -> V_186 ) ) < 0 )
goto V_250;
}
#endif
#ifdef F_101
if ( ( V_6 = F_191 ( V_4 -> V_11 , F_192 ( & V_265 , V_4 ) ) ) < 0 )
goto V_250;
#endif
#ifdef F_201
if ( V_4 -> V_266 )
if ( ( V_6 = F_191 ( V_4 -> V_11 , F_192 ( & V_267 , V_4 ) ) ) < 0 )
goto V_250;
#endif
V_6 = F_202 ( V_11 ) ;
if ( V_6 < 0 )
goto V_250;
F_203 ( V_11 -> V_12 , L_76 , V_11 -> V_246 ) ;
F_204 ( V_75 , V_4 ) ;
V_12 ++ ;
return 0 ;
V_250:
F_6 ( V_11 -> V_12 , L_77 , V_6 ) ;
F_189 ( V_11 ) ;
return V_6 ;
}
static int F_205 ( struct V_135 * V_12 )
{
struct V_220 * V_75 = F_206 ( V_12 ) ;
struct V_3 * V_4 = F_207 ( V_12 ) ;
F_100 ( ( L_78 ) ) ;
F_208 ( V_4 -> V_141 ) ;
F_208 ( V_4 -> V_147 ) ;
#ifdef F_162
if ( V_4 -> V_268 )
F_209 ( V_4 -> V_268 , 0 ) ;
#endif
F_53 ( & V_4 -> V_93 ) ;
if ( F_210 ( V_4 ) ) {
F_57 ( & V_4 -> V_93 ) ;
return - V_269 ;
}
F_211 ( V_4 ) ;
if ( F_212 ( V_4 , V_270 ) < 0 ) {
F_57 ( & V_4 -> V_93 ) ;
return - V_269 ;
}
F_57 ( & V_4 -> V_93 ) ;
V_4 -> V_271 = NULL ;
F_167 ( V_4 -> V_204 , V_4 ) ;
V_4 -> V_204 = - 1 ;
F_213 ( V_75 ) ;
F_170 ( V_75 ) ;
F_100 ( ( L_79 ) ) ;
return 0 ;
}
static int F_214 ( struct V_135 * V_12 )
{
struct V_220 * V_75 = F_206 ( V_12 ) ;
struct V_3 * V_4 = F_207 ( V_12 ) ;
struct V_213 * V_272 , * V_273 ;
V_42 V_274 ;
int V_6 ;
F_100 ( ( L_80 ) ) ;
F_215 ( V_75 ) ;
V_273 = F_216 ( sizeof( struct V_3 ) , V_53 ) ;
if ( V_273 == NULL )
return - V_54 ;
V_272 = V_4 -> V_213 ;
memcpy ( V_273 , V_272 , sizeof( struct V_213 ) ) ;
V_6 = F_184 ( V_4 , V_4 -> V_75 -> V_135 , V_4 -> V_75 -> V_233 ) ;
if ( V_6 < 0 ) {
F_12 ( V_273 ) ;
F_100 ( ( L_81 , V_6 ) ) ;
F_165 ( V_4 ) ;
return V_6 ;
}
F_100 ( ( L_82 ) ) ;
V_274 = V_4 -> V_274 ;
V_4 -> V_274 = 0 ;
V_6 = F_217 ( V_4 ) ;
V_4 -> V_274 = V_274 ;
if ( V_6 < 0 ) {
F_12 ( V_273 ) ;
return V_6 ;
}
F_100 ( ( L_83 ) ) ;
memcpy ( & V_272 -> V_275 , & V_273 -> V_275 ,
sizeof( V_272 -> V_275 ) ) ;
memcpy ( & V_272 -> V_276 , & V_273 -> V_276 ,
sizeof( V_272 -> V_276 ) ) ;
memcpy ( & V_272 -> V_277 , & V_273 -> V_277 ,
sizeof( V_272 -> V_277 ) ) ;
F_12 ( V_273 ) ;
if ( F_183 ( V_75 -> V_204 , F_159 , V_231 ,
V_232 , V_4 ) ) {
F_6 ( V_4 -> V_11 -> V_12 , L_64 ) ;
F_165 ( V_4 ) ;
return - V_229 ;
}
V_4 -> V_204 = V_75 -> V_204 ;
F_100 ( ( L_84 , V_4 -> V_204 ) ) ;
#ifdef F_162
if ( V_4 -> V_278 )
F_218 ( V_4 , TRUE ) ;
if ( V_4 -> V_268 )
F_209 ( V_4 -> V_268 , 1 ) ;
#endif
F_100 ( ( L_85 ) ) ;
return 0 ;
}
static void F_219 ( struct V_220 * V_75 )
{
struct V_3 * V_4 ;
V_4 = F_220 ( V_75 ) ;
if ( V_4 )
F_189 ( V_4 -> V_11 ) ;
}
