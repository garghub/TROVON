static inline struct V_1 * F_1 ( const struct V_2 * V_3 )
{
return V_3 ? V_4 [ V_3 -> V_5 / V_6 ] : NULL ;
}
static inline struct V_7 * F_2 ( const struct V_2 * V_3 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
return V_8 ? & V_8 -> V_7 [ V_3 -> V_5 % V_6 ] : NULL ;
}
static void F_3 ( T_1 * V_9 , const void T_2 * V_10 ,
T_1 V_11 )
{
T_1 V_12 = 0 ;
const T_1 T_2 * V_13 = V_10 ;
T_3 * V_14 ;
if ( F_4 ( ! V_13 || ! V_9 ) )
goto V_15;
switch ( V_11 ) {
case 2 :
V_14 = ( T_3 * ) V_9 ;
* V_14 = F_5 ( F_6 ( V_13 ) ) ;
goto V_15;
break;
case 4 :
* ( V_9 ) = F_7 ( F_8 ( V_13 ) ) ;
goto V_15;
break;
}
while ( V_12 < V_11 ) {
if ( V_11 - V_12 == 2 ) {
V_14 = ( T_3 * ) V_9 ;
* ( V_14 ) = F_5 ( F_6 ( V_13 ) ) ;
V_12 += 2 ;
} else {
* ( V_9 ) = F_7 ( F_8 ( V_13 ) ) ;
V_12 += 4 ;
}
V_9 ++ ;
V_13 ++ ;
}
V_15:
return;
}
static T_1 F_9 ( void T_2 * V_10 , const T_1 * V_9 ,
T_1 V_11 )
{
T_1 V_12 = 0 ;
T_1 T_2 * V_13 = V_10 ;
const T_3 * V_14 ;
if ( F_4 ( ! V_13 || ! V_9 ) )
return 0 ;
switch ( V_11 ) {
case 2 :
V_14 = ( const T_3 * ) V_9 ;
F_10 ( F_11 ( * V_14 ) , V_13 ) ;
return 2 ;
break;
case 1 :
case 4 :
F_12 ( F_13 ( * V_9 ) , V_13 ) ;
return 4 ;
break;
}
while ( V_12 < V_11 ) {
if ( V_11 - V_12 == 2 ) {
V_14 = ( const T_3 * ) V_9 ;
F_10 ( F_11 ( * V_14 ) , V_13 ) ;
V_12 += 2 ;
} else {
F_12 ( F_13 ( * V_9 ) , V_13 ) ;
V_12 += 4 ;
}
V_9 ++ ;
V_13 ++ ;
}
return V_12 ;
}
static void F_14 ( struct V_1 * V_16 )
{
void T_2 * V_17 = V_16 -> V_18 + V_16 -> V_19 . V_20 ;
const T_3 V_21 = 4 ;
V_16 -> V_7 [ V_22 ] . V_23 [ V_24 ] = V_17 ;
V_16 -> V_7 [ V_22 ] . V_23 [ V_25 ] =
( V_17 += V_16 -> V_19 . V_26 ) ;
V_16 -> V_7 [ V_22 ] . V_27 [ V_24 ] =
V_16 -> V_19 . V_26 - V_21 ;
V_16 -> V_7 [ V_22 ] . V_27 [ V_25 ] =
V_16 -> V_19 . V_28 - V_21 ;
V_16 -> V_7 [ V_29 ] . V_23 [ V_24 ] =
( V_17 += V_16 -> V_19 . V_28 ) ;
V_16 -> V_7 [ V_29 ] . V_27 [ V_24 ] =
V_16 -> V_19 . V_30 - V_21 ;
V_16 -> V_7 [ V_29 ] . V_23 [ V_25 ] =
( V_17 += V_16 -> V_19 . V_30 ) ;
V_16 -> V_7 [ V_29 ] . V_27 [ V_25 ] =
V_16 -> V_19 . V_31 - V_21 ;
V_16 -> V_7 [ V_32 ] . V_23 [ V_24 ] =
( V_17 += V_16 -> V_19 . V_31 ) ;
V_16 -> V_7 [ V_32 ] . V_27 [ V_24 ] =
V_16 -> V_19 . V_33 - V_21 ;
V_16 -> V_7 [ V_34 ] . V_23 [ V_24 ] =
( V_17 += V_16 -> V_19 . V_33 ) ;
V_16 -> V_7 [ V_34 ] . V_27 [ V_24 ] =
V_16 -> V_19 . V_35 - V_21 ;
V_16 -> V_7 [ V_36 ] . V_23 [ V_24 ] =
( V_17 += V_16 -> V_19 . V_35 ) ;
V_16 -> V_7 [ V_36 ] . V_27 [ V_24 ] =
V_16 -> V_19 . V_37 - V_21 ;
V_17 = V_16 -> V_18 + V_16 -> V_19 . V_38 ;
V_16 -> V_7 [ V_22 ] . V_39 [ V_24 ] = V_17 ;
V_16 -> V_7 [ V_22 ] . V_40 [ V_24 ] =
V_16 -> V_19 . V_41 - V_21 ;
V_16 -> V_7 [ V_22 ] . V_39 [ V_25 ] =
( V_17 += V_16 -> V_19 . V_41 ) ;
V_16 -> V_7 [ V_22 ] . V_40 [ V_25 ] =
V_16 -> V_19 . V_42 - V_21 ;
V_16 -> V_7 [ V_29 ] . V_39 [ V_24 ] =
( V_17 += V_16 -> V_19 . V_42 ) ;
V_16 -> V_7 [ V_29 ] . V_40 [ V_24 ] =
V_16 -> V_19 . V_43 - V_21 ;
V_16 -> V_7 [ V_32 ] . V_39 [ V_24 ] =
( V_17 += V_16 -> V_19 . V_43 ) ;
V_16 -> V_7 [ V_32 ] . V_40 [ V_24 ] =
V_16 -> V_19 . V_44 - V_21 ;
V_16 -> V_7 [ V_34 ] . V_39 [ V_24 ] =
( V_17 += V_16 -> V_19 . V_44 ) ;
V_16 -> V_7 [ V_34 ] . V_40 [ V_24 ] =
V_16 -> V_19 . V_45 - V_21 ;
V_16 -> V_7 [ V_36 ] . V_39 [ V_24 ] =
( V_17 += V_16 -> V_19 . V_45 ) ;
V_16 -> V_7 [ V_36 ] . V_40 [ V_24 ] =
V_16 -> V_19 . V_46 - V_21 ;
}
static void F_15 ( const struct V_1 * V_16 )
{
F_16 ( L_1 , V_16 -> V_19 . V_47 ) ;
F_16 ( L_2 , V_16 -> V_19 . V_48 ) ;
F_16 ( L_3 , \
V_16 -> V_19 . V_49 ) ;
F_16 ( L_4 , V_16 -> V_19 . V_50 . V_51 ) ;
F_16 ( L_5 , V_16 -> V_19 . V_50 . V_52 ) ;
F_16 ( L_6 , V_16 -> V_19 . V_50 . V_53 ) ;
F_16 ( L_7 , V_16 -> V_19 . V_50 . V_54 ) ;
F_16 ( L_8 , V_16 -> V_19 . V_20 ) ;
F_16 ( L_9 , V_16 -> V_19 . V_26 ,
V_16 -> V_19 . V_26 ) ;
F_16 ( L_10 , V_16 -> V_19 . V_28 ,
V_16 -> V_19 . V_28 ) ;
F_16 ( L_11 , V_16 -> V_19 . V_30 ,
V_16 -> V_19 . V_30 ) ;
F_16 ( L_12 , V_16 -> V_19 . V_31 ,
V_16 -> V_19 . V_31 ) ;
F_16 ( L_13 , V_16 -> V_19 . V_33 ,
V_16 -> V_19 . V_33 ) ;
F_16 ( L_14 , V_16 -> V_19 . V_35 ,
V_16 -> V_19 . V_35 ) ;
F_16 ( L_15 , V_16 -> V_19 . V_37 ,
V_16 -> V_19 . V_37 ) ;
F_16 ( L_16 , V_16 -> V_19 . V_38 ,
V_16 -> V_19 . V_38 ) ;
F_16 ( L_17 , V_16 -> V_19 . V_41 ,
V_16 -> V_19 . V_41 ) ;
F_16 ( L_18 , V_16 -> V_19 . V_42 ,
V_16 -> V_19 . V_42 ) ;
F_16 ( L_19 , V_16 -> V_19 . V_43 ,
V_16 -> V_19 . V_43 ) ;
F_16 ( L_20 , V_16 -> V_19 . V_44 ,
V_16 -> V_19 . V_44 ) ;
F_16 ( L_21 , V_16 -> V_19 . V_45 ,
V_16 -> V_19 . V_45 ) ;
F_16 ( L_22 , V_16 -> V_19 . V_46 ,
V_16 -> V_19 . V_46 ) ;
}
static inline void F_15 ( const struct V_1 * V_16 ) { }
static int F_17 ( struct V_1 * V_16 )
{
F_3 ( ( T_1 * ) & V_16 -> V_19 , V_16 -> V_18 + 0 ,
sizeof( struct V_19 ) ) ;
if ( V_16 -> V_19 . V_47 != V_55 ) {
F_18 ( & V_16 -> V_56 -> V_57 , L_23 ,
V_16 -> V_19 . V_47 , V_55 ) ;
return 0 ;
}
if ( ( V_16 -> V_19 . V_48 == 0 )
|| ( V_16 -> V_19 . V_50 . V_51 == V_58 ) ) {
int V_12 ;
F_19 ( L_24 ) ;
F_14 ( V_16 ) ;
V_16 -> V_7 [ V_22 ] . V_59 = V_16 -> V_19 . V_50 . V_52 ;
V_16 -> V_7 [ V_22 ] . V_60 = V_16 -> V_19 . V_50 . V_53 ;
V_16 -> V_7 [ V_29 ] . V_60 = V_16 -> V_19 . V_50 . V_54 ;
F_19 ( L_25 ,
V_16 -> V_7 [ V_22 ] . V_59 ,
V_16 -> V_7 [ V_22 ] . V_60 , V_16 -> V_7 [ V_29 ] . V_60 ) ;
F_15 ( V_16 ) ;
for ( V_12 = V_22 ; V_12 < V_6 ; V_12 ++ ) {
memset ( & V_16 -> V_7 [ V_12 ] . V_61 , 0 , sizeof( struct V_61 ) ) ;
memset ( & V_16 -> V_7 [ V_12 ] . V_62 , 0 , sizeof( struct V_62 ) ) ;
}
V_16 -> V_63 = V_16 -> V_63 | V_64 ;
F_10 ( V_16 -> V_63 , V_16 -> V_65 ) ;
V_16 -> V_66 = V_67 ;
F_20 ( & V_16 -> V_56 -> V_57 , L_26 ) ;
return 1 ;
}
if ( ( V_16 -> V_19 . V_48 > 0 )
&& ( V_16 -> V_19 . V_50 . V_51 != V_58 ) ) {
T_1 V_17 = 0 ;
F_19 ( L_27 ) ;
F_20 ( & V_16 -> V_56 -> V_57 , L_28 ,
V_16 -> V_19 . V_48 ) ;
F_14 ( V_16 ) ;
F_9 ( V_16 -> V_7 [ V_22 ] . V_39 [ V_24 ] ,
( T_1 * ) & V_17 , 4 ) ;
F_9 ( V_16 -> V_7 [ V_22 ] . V_39 [ V_25 ] ,
( T_1 * ) & V_17 , 4 ) ;
F_10 ( V_68 | V_69 | V_70 , V_16 -> V_71 ) ;
F_19 ( L_29 ) ;
}
return 1 ;
}
static void F_21 ( enum V_72 V_7 , struct V_1 * V_16 )
{
static const T_3 V_73 [] = { V_68 , V_74 , V_75 , V_76 , V_77 } ;
if ( V_7 < V_78 ) {
V_16 -> V_63 |= V_73 [ V_7 ] ;
F_10 ( V_16 -> V_63 , V_16 -> V_65 ) ;
} else {
F_18 ( & V_16 -> V_56 -> V_57 , L_30 ) ;
}
}
static void F_22 ( enum V_72 V_7 , struct V_1 * V_16 )
{
static const T_3 V_73 [] =
{ ~ V_68 , ~ V_74 , ~ V_75 , ~ V_76 , ~ V_77 } ;
if ( V_7 < V_78 ) {
V_16 -> V_63 &= V_73 [ V_7 ] ;
F_10 ( V_16 -> V_63 , V_16 -> V_65 ) ;
} else {
F_18 ( & V_16 -> V_56 -> V_57 , L_30 ) ;
}
}
static void F_23 ( enum V_72 V_7 , struct V_1 * V_16 )
{
static const T_3 V_73 [] = { V_70 , V_69 , V_79 , V_80 , V_64 } ;
if ( V_7 < V_78 ) {
V_16 -> V_63 |= V_73 [ V_7 ] ;
F_10 ( V_16 -> V_63 , V_16 -> V_65 ) ;
} else {
F_18 ( & V_16 -> V_56 -> V_57 , L_30 ) ;
}
}
static void F_24 ( enum V_72 V_7 , struct V_1 * V_16 )
{
static const T_3 V_73 [] =
{ ~ V_70 , ~ V_69 , ~ V_79 , ~ V_80 , ~ V_64 } ;
if ( V_7 < V_78 ) {
V_16 -> V_63 &= V_73 [ V_7 ] ;
F_10 ( V_16 -> V_63 , V_16 -> V_65 ) ;
} else {
F_18 ( & V_16 -> V_56 -> V_57 , L_30 ) ;
}
}
static int F_25 ( enum V_72 V_5 , struct V_1 * V_16 )
{
T_1 V_81 = 0 ;
struct V_7 * V_7 = & V_16 -> V_7 [ V_5 ] ;
const T_4 V_50 = V_7 -> V_59 ;
void T_2 * V_82 = V_7 -> V_39 [ V_50 ] ;
const T_1 V_40 = V_7 -> V_40 [ V_50 ] ;
V_81 = F_26 ( & V_7 -> V_83 , V_16 -> V_84 ,
V_40 < V_85 ? V_40 : V_85 ) ;
if ( V_81 == 0 ) {
F_27 ( L_31 ) ;
return 0 ;
}
F_9 ( V_82 , ( T_1 * ) & V_81 , 4 ) ;
F_9 ( V_82 + 4 , ( T_1 * ) V_16 -> V_84 , V_81 ) ;
F_28 ( & V_7 -> V_7 ) ;
return 1 ;
}
static int F_29 ( enum V_72 V_5 , struct V_1 * V_16 )
{
T_4 V_9 [ V_86 ] = { 0 } ;
int V_81 ;
T_1 V_17 = 4 ;
struct V_7 * V_7 = & V_16 -> V_7 [ V_5 ] ;
void T_2 * V_82 = V_7 -> V_23 [ V_7 -> V_60 ] ;
struct V_2 * V_3 = F_30 ( & V_7 -> V_7 ) ;
int V_12 , V_87 ;
V_81 = F_7 ( F_8 ( V_82 ) ) ;
if ( V_3 && F_31 ( V_3 ) ) {
F_19 ( L_32
L_33 ) ;
F_24 ( V_5 , V_16 ) ;
V_87 = 0 ;
goto V_88;
}
if ( F_4 ( V_81 == 0 ) ) {
F_18 ( & V_16 -> V_56 -> V_57 , L_34 ) ;
V_87 = 1 ;
goto V_88;
}
while ( V_81 > 0 ) {
F_3 ( ( T_1 * ) V_9 , V_82 + V_17 , V_86 ) ;
if ( V_81 == 1 ) {
F_32 ( & V_7 -> V_7 , V_9 [ 0 ] , V_89 ) ;
V_81 = 0 ;
} else if ( V_81 < V_86 ) {
V_81 -= F_33 ( & V_7 -> V_7 ,
( char * ) V_9 , V_81 ) ;
} else {
V_12 = F_33 ( & V_7 -> V_7 ,
( char * ) V_9 , V_86 ) ;
V_81 -= V_12 ;
V_17 += V_12 ;
}
}
F_34 ( V_5 , & V_16 -> V_90 ) ;
V_87 = 1 ;
V_88:
F_35 ( V_3 ) ;
return V_87 ;
}
static char * F_36 ( T_3 V_91 )
{
static char V_9 [ V_92 ] ;
char * V_93 = V_9 ;
V_91 & V_94 ? V_93 += snprintf ( V_93 , V_92 , L_35 ) : NULL ;
V_91 & V_95 ? V_93 += snprintf ( V_93 , V_92 - ( V_93 - V_9 ) ,
L_36 ) : NULL ;
V_91 & V_96 ? V_93 += snprintf ( V_93 , V_92 - ( V_93 - V_9 ) ,
L_37 ) : NULL ;
V_91 & V_97 ? V_93 += snprintf ( V_93 , V_92 - ( V_93 - V_9 ) ,
L_38 ) : NULL ;
V_91 & V_98 ? V_93 += snprintf ( V_93 , V_92 - ( V_93 - V_9 ) ,
L_39 ) : NULL ;
V_91 & V_99 ? V_93 += snprintf ( V_93 , V_92 - ( V_93 - V_9 ) ,
L_40 ) : NULL ;
V_91 & V_74 ? V_93 += snprintf ( V_93 , V_92 - ( V_93 - V_9 ) ,
L_41 ) : NULL ;
V_91 & V_79 ? V_93 += snprintf ( V_93 , V_92 - ( V_93 - V_9 ) ,
L_42 ) : NULL ;
V_91 & V_80 ? V_93 += snprintf ( V_93 , V_92 - ( V_93 - V_9 ) ,
L_43 ) : NULL ;
V_91 & V_75 ? V_93 += snprintf ( V_93 , V_92 - ( V_93 - V_9 ) ,
L_44 ) : NULL ;
V_91 & V_76 ? V_93 += snprintf ( V_93 , V_92 - ( V_93 - V_9 ) ,
L_45 ) : NULL ;
V_91 & V_64 ? V_93 += snprintf ( V_93 , V_92 - ( V_93 - V_9 ) ,
L_46 ) : NULL ;
V_91 & V_77 ? V_93 += snprintf ( V_93 , V_92 - ( V_93 - V_9 ) ,
L_47 ) : NULL ;
V_91 & V_100 ? V_93 += snprintf ( V_93 , V_92 - ( V_93 - V_9 ) ,
L_48 ) : NULL ;
return V_9 ;
}
static int F_37 ( struct V_1 * V_16 )
{
enum V_72 V_7 = V_22 ;
struct V_61 V_61 ;
struct V_61 V_101 ;
T_3 V_102 = 0 ;
F_3 ( ( T_1 * ) & V_61 , V_16 -> V_7 [ V_36 ] . V_23 [ V_24 ] , 2 ) ;
switch ( V_61 . V_7 ) {
case V_103 :
F_19 ( L_49
L_50
L_51 ) ;
break;
case V_104 :
V_7 = V_22 ;
V_102 = V_70 ;
break;
case V_105 :
V_7 = V_29 ;
V_102 = V_69 ;
break;
case V_106 :
V_7 = V_32 ;
V_102 = V_79 ;
break;
case V_107 :
V_7 = V_34 ;
V_102 = V_80 ;
if ( V_16 -> V_66 == V_67 ) {
V_16 -> V_66 = V_108 ;
F_20 ( & V_16 -> V_56 -> V_57 , L_52 ) ;
}
break;
default:
F_18 ( & V_16 -> V_56 -> V_57 ,
L_53 ) ;
return 0 ;
}
F_19 ( L_54 , * ( ( T_3 * ) & V_16 -> V_7 [ V_7 ] . V_61 ) ,
* ( ( T_3 * ) & V_61 ) ) ;
V_101 = V_16 -> V_7 [ V_7 ] . V_61 ;
V_16 -> V_7 [ V_7 ] . V_61 = V_61 ;
if ( V_101 . V_109 == 1 && V_61 . V_109 == 0 ) {
F_19 ( L_55 ,
V_102 , V_7 ) ;
F_22 ( V_7 , V_16 ) ;
} else if ( V_101 . V_109 == 0 && V_61 . V_109 == 1 ) {
if ( F_38 ( & V_16 -> V_7 [ V_7 ] . V_83 ) ) {
F_19 ( L_56 ,
V_102 , V_7 ) ;
F_19 ( L_57 ,
F_38 ( & V_16 -> V_7 [ V_7 ] . V_83 ) ) ;
F_21 ( V_7 , V_16 ) ;
} else {
F_19 ( L_58 ) ;
}
}
if ( * ( T_3 * ) & V_101 == * ( T_3 * ) & V_61 ) {
F_19 ( L_59 ) ;
return 1 ;
}
if ( V_101 . V_109 != V_61 . V_109 )
V_16 -> V_7 [ V_7 ] . V_110 . V_111 ++ ;
if ( V_101 . V_112 != V_61 . V_112 )
V_16 -> V_7 [ V_7 ] . V_110 . V_113 ++ ;
if ( V_101 . V_114 != V_61 . V_114 )
V_16 -> V_7 [ V_7 ] . V_110 . V_115 ++ ;
if ( V_101 . V_116 != V_61 . V_116 )
V_16 -> V_7 [ V_7 ] . V_110 . V_117 ++ ;
F_39 ( & V_16 -> V_7 [ V_7 ] . V_118 ) ;
F_19 ( L_60 ,
V_7 ,
V_16 -> V_7 [ V_7 ] . V_110 . V_117 , V_16 -> V_7 [ V_7 ] . V_110 . V_111 ,
V_16 -> V_7 [ V_7 ] . V_110 . V_115 , V_16 -> V_7 [ V_7 ] . V_110 . V_113 ) ;
return 1 ;
}
static enum V_119 F_40 ( enum V_72 V_7 ,
const struct V_1 * V_16 )
{
switch ( V_7 ) {
case V_22 :
return V_104 ;
case V_29 :
return V_105 ;
case V_32 :
return V_106 ;
case V_34 :
return V_107 ;
default:
F_18 ( & V_16 -> V_56 -> V_57 ,
L_61 \
L_62 ) ;
}
return V_120 ;
}
static int F_41 ( struct V_1 * V_16 )
{
T_1 V_12 , V_121 = 0 ;
T_3 * V_122 ;
for ( V_12 = V_22 ; V_12 < V_6 ; V_12 ++ ) {
if ( V_16 -> V_7 [ V_12 ] . V_123 ) {
if ( V_121 ) {
return 1 ;
}
V_16 -> V_7 [ V_12 ] . V_62 . V_7 = F_40 ( V_12 , V_16 ) ;
V_122 = ( T_3 * ) & V_16 -> V_7 [ V_12 ] . V_62 ;
F_9 ( V_16 -> V_7 [ V_36 ] . V_39 [ 0 ] , \
( T_1 * ) V_122 , 2 ) ;
V_16 -> V_7 [ V_12 ] . V_123 = 0 ;
V_121 = 1 ;
}
}
return 0 ;
}
static int F_42 ( struct V_1 * V_16 , enum V_72 V_7 , T_4 * V_50 ,
T_3 V_124 , T_3 V_125 , T_3 V_126 )
{
if ( * V_50 == 0 && V_124 & V_125 ) {
if ( F_29 ( V_7 , V_16 ) ) {
F_10 ( V_125 , V_16 -> V_71 ) ;
* V_50 = ! ( * V_50 ) ;
}
if ( V_124 & V_126 ) {
if ( F_29 ( V_7 , V_16 ) ) {
F_10 ( V_126 , V_16 -> V_71 ) ;
* V_50 = ! ( * V_50 ) ;
}
}
} else if ( * V_50 == 1 && V_124 & V_126 ) {
if ( F_29 ( V_7 , V_16 ) ) {
F_10 ( V_126 , V_16 -> V_71 ) ;
* V_50 = ! ( * V_50 ) ;
}
if ( V_124 & V_125 ) {
if ( F_29 ( V_7 , V_16 ) ) {
F_10 ( V_125 , V_16 -> V_71 ) ;
* V_50 = ! ( * V_50 ) ;
}
}
} else {
F_18 ( & V_16 -> V_56 -> V_57 , L_63 ,
* V_50 ) ;
return 0 ;
}
return 1 ;
}
static int F_43 ( struct V_1 * V_16 , enum V_72 V_7 , T_3 V_124 )
{
T_4 * V_50 = & ( V_16 -> V_7 [ V_7 ] . V_59 ) ;
if ( * V_50 == 0 && V_124 & V_96 ) {
V_16 -> V_63 &= ~ V_68 ;
F_10 ( V_16 -> V_63 , V_16 -> V_65 ) ;
if ( F_25 ( V_7 , V_16 ) ) {
F_10 ( V_96 , V_16 -> V_71 ) ;
V_16 -> V_63 = V_16 -> V_63 | V_68 ;
F_10 ( V_16 -> V_63 , V_16 -> V_65 ) ;
* V_50 = ! * V_50 ;
}
if ( V_124 & V_97 ) {
V_16 -> V_63 &= ~ V_68 ;
F_10 ( V_16 -> V_63 , V_16 -> V_65 ) ;
if ( F_25 ( V_7 , V_16 ) ) {
F_10 ( V_97 , V_16 -> V_71 ) ;
V_16 -> V_63 = V_16 -> V_63 | V_68 ;
F_10 ( V_16 -> V_63 , V_16 -> V_65 ) ;
* V_50 = ! * V_50 ;
}
}
} else if ( * V_50 == 1 && V_124 & V_97 ) {
V_16 -> V_63 &= ~ V_68 ;
F_10 ( V_16 -> V_63 , V_16 -> V_65 ) ;
if ( F_25 ( V_7 , V_16 ) ) {
F_10 ( V_97 , V_16 -> V_71 ) ;
V_16 -> V_63 = V_16 -> V_63 | V_68 ;
F_10 ( V_16 -> V_63 , V_16 -> V_65 ) ;
* V_50 = ! * V_50 ;
}
if ( V_124 & V_96 ) {
V_16 -> V_63 &= ~ V_68 ;
F_10 ( V_16 -> V_63 , V_16 -> V_65 ) ;
if ( F_25 ( V_7 , V_16 ) ) {
F_10 ( V_96 , V_16 -> V_71 ) ;
V_16 -> V_63 = V_16 -> V_63 | V_68 ;
F_10 ( V_16 -> V_63 , V_16 -> V_65 ) ;
* V_50 = ! * V_50 ;
}
}
} else {
F_10 ( V_124 & V_68 , V_16 -> V_71 ) ;
F_18 ( & V_16 -> V_56 -> V_57 , L_64 ) ;
return 0 ;
}
return 1 ;
}
static T_5 F_44 ( int V_127 , void * V_128 )
{
struct V_1 * V_16 = V_128 ;
unsigned int V_129 ;
T_3 V_124 ;
if ( ! V_16 )
return V_130 ;
F_45 ( & V_16 -> V_131 ) ;
V_124 = F_6 ( V_16 -> V_132 ) ;
if ( V_124 == ( T_3 ) - 1 )
goto V_133;
V_124 &= V_16 -> V_63 ;
if ( V_124 == 0 )
goto V_133;
F_27 ( L_65 , F_36 ( V_124 ) , V_124 ,
V_16 -> V_63 ) ;
if ( V_124 & V_100 ) {
if ( F_4 ( ! F_17 ( V_16 ) ) ) {
V_16 -> V_63 = 0x0 ;
F_10 ( V_16 -> V_63 , V_16 -> V_65 ) ;
F_18 ( & V_16 -> V_56 -> V_57 , L_66
L_67 ) ;
} else {
F_10 ( V_100 , V_16 -> V_71 ) ;
}
goto V_134;
}
if ( V_124 & V_77 ) {
F_19 ( L_68 ) ;
V_16 -> V_63 &= ~ V_77 ;
F_10 ( V_16 -> V_63 , V_16 -> V_65 ) ;
if ( F_41 ( V_16 ) ) {
F_10 ( V_77 , V_16 -> V_71 ) ;
V_16 -> V_63 = V_16 -> V_63 | V_77 ;
F_10 ( V_16 -> V_63 , V_16 -> V_65 ) ;
}
}
if ( V_124 & V_64 ) {
F_37 ( V_16 ) ;
F_10 ( V_64 , V_16 -> V_71 ) ;
}
if ( V_124 & V_70 ) {
if ( ! F_42 ( V_16 , V_22 ,
& ( V_16 -> V_7 [ V_22 ] . V_60 ) , V_124 ,
V_94 , V_95 ) ) {
F_18 ( & V_16 -> V_56 -> V_57 , L_69 ) ;
goto V_134;
}
}
if ( V_124 & V_68 ) {
if ( ! F_43 ( V_16 , V_22 , V_124 ) ) {
F_18 ( & V_16 -> V_56 -> V_57 , L_70 ) ;
goto V_134;
}
}
if ( V_124 & V_69 ) {
if ( ! F_42 ( V_16 , V_29 ,
& ( V_16 -> V_7 [ V_29 ] . V_60 ) , V_124 ,
V_98 , V_99 ) ) {
F_18 ( & V_16 -> V_56 -> V_57 , L_71 ) ;
goto V_134;
}
}
if ( V_124 & V_74 ) {
V_16 -> V_63 &= ~ V_74 ;
F_10 ( V_16 -> V_63 , V_16 -> V_65 ) ;
if ( F_25 ( V_29 , V_16 ) ) {
F_10 ( V_74 , V_16 -> V_71 ) ;
V_16 -> V_63 = V_16 -> V_63 | V_74 ;
F_10 ( V_16 -> V_63 , V_16 -> V_65 ) ;
}
}
if ( V_124 & V_79 ) {
if ( F_29 ( V_32 , V_16 ) )
F_10 ( V_79 , V_16 -> V_71 ) ;
}
if ( V_124 & V_75 ) {
V_16 -> V_63 &= ~ V_75 ;
F_10 ( V_16 -> V_63 , V_16 -> V_65 ) ;
if ( F_25 ( V_32 , V_16 ) ) {
F_10 ( V_75 , V_16 -> V_71 ) ;
V_16 -> V_63 = V_16 -> V_63 | V_75 ;
F_10 ( V_16 -> V_63 , V_16 -> V_65 ) ;
}
}
if ( V_124 & V_80 ) {
if ( F_29 ( V_34 , V_16 ) )
F_10 ( V_80 , V_16 -> V_71 ) ;
}
if ( V_124 & V_76 ) {
V_16 -> V_63 &= ~ V_76 ;
F_10 ( V_16 -> V_63 , V_16 -> V_65 ) ;
if ( F_25 ( V_34 , V_16 ) ) {
F_10 ( V_76 , V_16 -> V_71 ) ;
V_16 -> V_63 = V_16 -> V_63 | V_76 ;
F_10 ( V_16 -> V_63 , V_16 -> V_65 ) ;
}
}
V_134:
F_46 ( & V_16 -> V_131 ) ;
for ( V_129 = 0 ; V_129 < V_78 ; V_129 ++ )
if ( F_47 ( V_129 , & V_16 -> V_90 ) )
F_48 ( & V_16 -> V_7 [ V_129 ] . V_7 ) ;
return V_135 ;
V_133:
F_46 ( & V_16 -> V_131 ) ;
return V_130 ;
}
static void F_49 ( struct V_1 * V_16 )
{
int V_12 ;
T_1 V_81 = 0 ;
for ( V_12 = 0 ; V_12 < 6 ; V_12 ++ )
V_81 += F_50 ( V_16 -> V_56 , V_12 ) ;
V_16 -> V_136 = V_81 == 2048 ? V_137 : V_138 ;
F_20 ( & V_16 -> V_56 -> V_57 , L_72 , V_16 -> V_136 ) ;
}
static void F_51 ( struct V_1 * V_16 )
{
void T_2 * V_17 = V_16 -> V_18 + V_16 -> V_136 / 2 ;
unsigned int V_12 ;
V_16 -> V_71 = ( void T_2 * ) ( V_17 + V_139 ) ;
V_16 -> V_132 = ( void T_2 * ) ( V_17 + V_140 ) ;
V_16 -> V_65 = ( void T_2 * ) ( V_17 + V_141 ) ;
V_16 -> V_63 = 0 ;
V_16 -> V_90 = 0 ;
V_16 -> V_7 [ V_22 ] . V_142 = V_70 ;
V_16 -> V_7 [ V_29 ] . V_142 = V_69 ;
V_16 -> V_7 [ V_32 ] . V_142 = V_79 ;
V_16 -> V_7 [ V_34 ] . V_142 = V_80 ;
for ( V_12 = 0 ; V_12 < V_6 ; V_12 ++ )
F_52 ( & V_16 -> V_7 [ V_12 ] . V_118 ) ;
}
static T_6 F_53 ( struct V_143 * V_57 , struct V_144 * V_145 ,
char * V_9 )
{
const struct V_1 * V_16 = F_54 ( F_55 ( V_57 ) ) ;
return sprintf ( V_9 , L_73 , V_16 -> V_136 ) ;
}
static T_6 F_56 ( struct V_143 * V_57 , struct V_144 * V_145 ,
char * V_9 )
{
const struct V_1 * V_16 = F_54 ( F_55 ( V_57 ) ) ;
return sprintf ( V_9 , L_74 , V_16 -> V_146 ) ;
}
static void F_57 ( struct V_1 * V_16 )
{
if ( F_58 ( & V_16 -> V_56 -> V_57 , & V_147 ) )
F_18 ( & V_16 -> V_56 -> V_57 ,
L_75 ) ;
if ( F_58 ( & V_16 -> V_56 -> V_57 , & V_148 ) )
F_18 ( & V_16 -> V_56 -> V_57 ,
L_76 ) ;
}
static void F_59 ( struct V_1 * V_16 )
{
F_60 ( & V_16 -> V_56 -> V_57 , & V_147 ) ;
F_60 ( & V_16 -> V_56 -> V_57 , & V_148 ) ;
}
static int F_61 ( struct V_149 * V_56 ,
const struct V_150 * V_151 )
{
T_7 V_152 ;
int V_87 ;
struct V_1 * V_16 = NULL ;
int V_153 ;
int V_12 ;
F_62 ( & V_56 -> V_57 , L_77 ) ;
for ( V_153 = 0 ; V_153 < F_63 ( V_4 ) ; V_153 ++ )
if ( ! V_4 [ V_153 ] )
break;
if ( V_153 >= F_63 ( V_4 ) ) {
F_18 ( & V_56 -> V_57 , L_78 ) ;
V_87 = - V_154 ;
goto V_155;
}
V_16 = F_64 ( sizeof( struct V_1 ) , V_156 ) ;
if ( F_4 ( ! V_16 ) ) {
F_18 ( & V_56 -> V_57 , L_79 ) ;
V_87 = - V_157 ;
goto V_158;
}
V_16 -> V_56 = V_56 ;
V_87 = F_65 ( V_16 -> V_56 ) ;
if ( V_87 ) {
F_18 ( & V_56 -> V_57 , L_80 ) ;
goto V_158;
}
V_87 = F_66 ( V_16 -> V_56 , V_159 ) ;
if ( V_87 ) {
F_18 ( & V_56 -> V_57 , L_81 ,
( int ) 0 ) ;
goto V_160;
}
V_152 = F_67 ( V_16 -> V_56 , 0 ) ;
if ( V_152 == 0 ) {
F_18 ( & V_56 -> V_57 , L_82 ) ;
V_87 = - V_161 ;
goto V_162;
}
F_49 ( V_16 ) ;
V_16 -> V_18 = F_68 ( V_152 , V_16 -> V_136 ) ;
if ( ! V_16 -> V_18 ) {
F_18 ( & V_56 -> V_57 , L_83 ) ;
V_87 = - V_161 ;
goto V_162;
}
V_16 -> V_84 = F_69 ( V_85 , V_156 ) ;
if ( ! V_16 -> V_84 ) {
F_18 ( & V_56 -> V_57 , L_84 ) ;
V_87 = - V_157 ;
goto V_163;
}
for ( V_12 = V_22 ; V_12 < V_6 ; V_12 ++ ) {
if ( F_70 ( & V_16 -> V_7 [ V_12 ] . V_83 , V_164 ,
V_156 ) ) {
F_18 ( & V_56 -> V_57 ,
L_85 ) ;
V_87 = - V_157 ;
goto V_165;
}
}
F_71 ( & V_16 -> V_131 ) ;
F_51 ( V_16 ) ;
V_16 -> V_63 = 0 ;
F_10 ( V_16 -> V_63 , V_16 -> V_65 ) ;
V_87 = F_72 ( V_56 -> V_127 , & F_44 , V_166 ,
V_159 , V_16 ) ;
if ( F_4 ( V_87 ) ) {
F_18 ( & V_56 -> V_57 , L_86 , V_56 -> V_127 ) ;
goto V_165;
}
F_19 ( L_87 , V_16 -> V_18 ) ;
F_57 ( V_16 ) ;
V_16 -> V_167 = V_153 * V_6 ;
V_4 [ V_153 ] = V_16 ;
F_73 ( V_56 , V_16 ) ;
V_16 -> V_63 = V_100 ;
F_74 ( V_16 -> V_63 , V_16 -> V_65 ) ;
V_16 -> V_66 = V_168 ;
for ( V_12 = 0 ; V_12 < V_6 ; V_12 ++ ) {
struct V_143 * V_169 ;
struct V_7 * V_7 = & V_16 -> V_7 [ V_12 ] ;
V_7 -> V_16 = V_16 ;
F_75 ( & V_7 -> V_7 ) ;
V_7 -> V_7 . V_170 = & V_171 ;
V_169 = F_76 ( & V_7 -> V_7 , V_172 ,
V_16 -> V_167 + V_12 , & V_56 -> V_57 ) ;
if ( F_77 ( V_169 ) ) {
V_87 = F_78 ( V_169 ) ;
F_18 ( & V_56 -> V_57 , L_88 ) ;
F_79 ( & V_7 -> V_7 ) ;
goto V_173;
}
}
return 0 ;
V_173:
for ( V_12 = 0 ; V_12 < V_6 ; ++ V_12 ) {
F_80 ( V_172 , V_16 -> V_167 + V_12 ) ;
F_79 ( & V_16 -> V_7 [ V_12 ] . V_7 ) ;
}
V_165:
for ( V_12 = 0 ; V_12 < V_6 ; V_12 ++ )
F_81 ( & V_16 -> V_7 [ V_12 ] . V_83 ) ;
V_163:
F_82 ( V_16 -> V_84 ) ;
F_83 ( V_16 -> V_18 ) ;
V_162:
F_84 ( V_56 ) ;
V_160:
F_85 ( V_56 ) ;
V_158:
F_82 ( V_16 ) ;
V_155:
return V_87 ;
}
static void F_86 ( struct V_1 * V_16 )
{
unsigned int V_12 ;
F_19 ( L_89 ) ;
for ( V_12 = 0 ; V_12 < V_6 ; ++ V_12 )
F_87 ( & V_16 -> V_7 [ V_12 ] . V_7 , false ) ;
while ( V_16 -> V_146 )
F_88 ( 1 ) ;
for ( V_12 = 0 ; V_12 < V_6 ; ++ V_12 ) {
F_80 ( V_172 , V_16 -> V_167 + V_12 ) ;
F_79 ( & V_16 -> V_7 [ V_12 ] . V_7 ) ;
}
}
static void F_89 ( struct V_149 * V_56 )
{
int V_12 ;
struct V_62 V_122 ;
struct V_1 * V_16 = F_54 ( V_56 ) ;
V_16 -> V_63 = 0 ;
F_10 ( V_16 -> V_63 , V_16 -> V_65 ) ;
F_86 ( V_16 ) ;
V_122 . V_7 = 0x00 ;
V_122 . V_174 = 0 ;
V_122 . V_175 = 0 ;
V_122 . V_176 = 1 ;
F_19 ( L_90 , * ( ( T_3 * ) & V_122 ) ) ;
F_9 ( V_16 -> V_7 [ V_36 ] . V_39 [ 0 ] , ( T_1 * ) & V_122 , 2 ) ;
F_10 ( V_77 , V_16 -> V_71 ) ;
F_59 ( V_16 ) ;
F_90 ( V_56 -> V_127 , V_16 ) ;
for ( V_12 = 0 ; V_12 < V_6 ; V_12 ++ )
F_81 ( & V_16 -> V_7 [ V_12 ] . V_83 ) ;
F_82 ( V_16 -> V_84 ) ;
F_83 ( V_16 -> V_18 ) ;
F_84 ( V_56 ) ;
F_85 ( V_56 ) ;
V_4 [ V_16 -> V_167 / V_6 ] = NULL ;
F_82 ( V_16 ) ;
}
static void F_91 ( const struct V_2 * V_3 , int V_177 )
{
struct V_7 * V_7 = F_2 ( V_3 ) ;
V_7 -> V_62 . V_175 = V_177 ;
V_7 -> V_123 = 1 ;
F_21 ( V_36 , F_1 ( V_3 ) ) ;
}
static void F_92 ( const struct V_2 * V_3 , int V_178 )
{
struct V_7 * V_7 = F_2 ( V_3 ) ;
F_19 ( L_91 , V_3 -> V_5 , V_178 ) ;
V_7 -> V_62 . V_176 = V_178 ;
V_7 -> V_123 = 1 ;
F_21 ( V_36 , F_1 ( V_3 ) ) ;
}
static int F_93 ( struct V_179 * V_180 , struct V_2 * V_3 )
{
struct V_7 * V_7 = F_2 ( V_3 ) ;
struct V_1 * V_16 = F_1 ( V_3 ) ;
int V_87 ;
if ( ! V_7 || ! V_16 || V_16 -> V_66 != V_108 )
return - V_161 ;
V_87 = F_94 ( V_180 , V_3 ) ;
if ( V_87 == 0 )
V_3 -> V_181 = V_7 ;
return V_87 ;
}
static void F_95 ( struct V_2 * V_3 )
{
V_3 -> V_181 = NULL ;
}
static int F_96 ( struct V_182 * V_183 , struct V_2 * V_3 )
{
struct V_7 * V_7 = F_97 ( V_183 , struct V_7 , V_7 ) ;
struct V_1 * V_16 = V_7 -> V_16 ;
unsigned long V_184 ;
F_19 ( L_92 , V_7 -> V_142 ) ;
F_98 ( & V_16 -> V_131 , V_184 ) ;
V_16 -> V_63 = V_16 -> V_63 | V_7 -> V_142 ;
F_10 ( V_16 -> V_63 , V_16 -> V_65 ) ;
V_16 -> V_146 ++ ;
F_99 ( & V_16 -> V_131 , V_184 ) ;
F_100 ( L_93 , V_3 -> V_5 , V_183 ) ;
return 0 ;
}
static int F_101 ( struct V_2 * V_3 , struct V_185 * V_186 )
{
struct V_7 * V_7 = V_3 -> V_181 ;
return F_102 ( & V_7 -> V_7 , V_3 , V_186 ) ;
}
static void F_103 ( struct V_182 * V_183 )
{
struct V_7 * V_7 = F_97 ( V_183 , struct V_7 , V_7 ) ;
struct V_1 * V_16 = V_7 -> V_16 ;
unsigned long V_184 ;
F_19 ( L_94 , V_7 -> V_142 ) ;
F_98 ( & V_16 -> V_131 , V_184 ) ;
V_16 -> V_63 &= ~ ( V_7 -> V_142 ) ;
F_10 ( V_16 -> V_63 , V_16 -> V_65 ) ;
V_16 -> V_146 -- ;
F_99 ( & V_16 -> V_131 , V_184 ) ;
F_100 ( L_95 , V_183 ) ;
}
static void F_104 ( struct V_2 * V_3 , struct V_185 * V_186 )
{
struct V_7 * V_7 = V_3 -> V_181 ;
if ( V_7 )
F_105 ( & V_7 -> V_7 , V_3 , V_186 ) ;
}
static void F_106 ( struct V_2 * V_3 )
{
struct V_7 * V_7 = V_3 -> V_181 ;
F_107 ( & V_7 -> V_7 ) ;
}
static int F_108 ( struct V_2 * V_3 , const unsigned char * V_187 ,
int V_188 )
{
int V_189 = - V_190 ;
struct V_1 * V_16 = F_1 ( V_3 ) ;
struct V_7 * V_7 = V_3 -> V_181 ;
unsigned long V_184 ;
if ( ! V_16 || ! V_7 )
return - V_161 ;
V_189 = F_109 ( & V_7 -> V_83 , ( unsigned char * ) V_187 , V_188 ) ;
F_98 ( & V_16 -> V_131 , V_184 ) ;
if ( V_7 == & ( V_16 -> V_7 [ V_22 ] ) ) {
if ( V_7 -> V_61 . V_109 ) {
F_27 ( L_96 ) ;
F_21 ( V_3 -> V_5 % V_6 , V_16 ) ;
} else {
F_18 ( & V_16 -> V_56 -> V_57 ,
L_97 ) ;
}
} else {
F_21 ( V_3 -> V_5 % V_6 , V_16 ) ;
}
F_99 ( & V_16 -> V_131 , V_184 ) ;
return V_189 ;
}
static int F_110 ( struct V_2 * V_3 )
{
struct V_7 * V_7 = V_3 -> V_181 ;
int V_191 = 4096 ;
const struct V_1 * V_16 = F_1 ( V_3 ) ;
if ( V_16 )
V_191 = F_111 ( & V_7 -> V_83 ) ;
return V_191 ;
}
static int F_112 ( struct V_2 * V_3 )
{
const struct V_7 * V_7 = V_3 -> V_181 ;
const struct V_61 * V_61 = & V_7 -> V_61 ;
const struct V_62 * V_62 = & V_7 -> V_62 ;
return ( V_62 -> V_175 ? V_192 : 0 ) |
( V_62 -> V_176 ? V_193 : 0 ) |
( V_61 -> V_116 ? V_194 : 0 ) |
( V_61 -> V_114 ? V_195 : 0 ) |
( V_61 -> V_112 ? V_196 : 0 ) |
( V_61 -> V_109 ? V_197 : 0 ) ;
}
static int F_113 ( struct V_2 * V_3 ,
unsigned int V_198 , unsigned int V_199 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
unsigned long V_184 ;
F_98 ( & V_16 -> V_131 , V_184 ) ;
if ( V_198 & V_192 )
F_91 ( V_3 , 1 ) ;
else if ( V_199 & V_192 )
F_91 ( V_3 , 0 ) ;
if ( V_198 & V_193 )
F_92 ( V_3 , 1 ) ;
else if ( V_199 & V_193 )
F_92 ( V_3 , 0 ) ;
F_99 ( & V_16 -> V_131 , V_184 ) ;
return 0 ;
}
static int F_114 ( struct V_7 * V_7 , unsigned long V_184 ,
struct V_200 * V_201 )
{
const struct V_200 V_202 = V_7 -> V_110 ;
int V_87 ;
V_87 = ( ( V_184 & V_195 ) && ( V_202 . V_115 != V_201 -> V_115 ) ) ||
( ( V_184 & V_196 ) && ( V_202 . V_113 != V_201 -> V_113 ) ) ||
( ( V_184 & V_203 ) && ( V_202 . V_117 != V_201 -> V_117 ) ) ||
( ( V_184 & V_197 ) && ( V_202 . V_111 != V_201 -> V_111 ) ) ;
* V_201 = V_202 ;
return V_87 ;
}
static int F_115 ( struct V_2 * V_3 ,
struct V_204 * V_205 )
{
struct V_7 * V_7 = V_3 -> V_181 ;
const struct V_200 V_202 = V_7 -> V_110 ;
V_205 -> V_111 = V_202 . V_111 ;
V_205 -> V_113 = V_202 . V_113 ;
V_205 -> V_115 = V_202 . V_115 ;
V_205 -> V_117 = V_202 . V_117 ;
V_205 -> V_206 = V_202 . V_206 ;
V_205 -> V_207 = V_202 . V_207 ;
V_205 -> V_208 = V_202 . V_208 ;
V_205 -> V_209 = V_202 . V_209 ;
V_205 -> V_210 = V_202 . V_210 ;
V_205 -> V_211 = V_202 . V_211 ;
V_205 -> V_212 = V_202 . V_212 ;
return 0 ;
}
static int F_116 ( struct V_2 * V_3 ,
unsigned int V_213 , unsigned long V_214 )
{
struct V_7 * V_7 = V_3 -> V_181 ;
int V_189 = - V_215 ;
F_19 ( L_98 , V_213 ) ;
switch ( V_213 ) {
case V_216 : {
struct V_200 V_201 = V_7 -> V_110 ;
V_189 = F_117 ( V_7 -> V_118 ,
F_114 ( V_7 , V_214 , & V_201 ) ) ;
break;
}
default:
F_19 ( L_99 , V_213 , V_213 ) ;
break;
}
return V_189 ;
}
static void F_118 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
unsigned long V_184 ;
F_19 ( L_100 ) ;
F_98 ( & V_16 -> V_131 , V_184 ) ;
F_23 ( V_3 -> V_5 % V_6 , V_16 ) ;
F_91 ( V_3 , 1 ) ;
F_99 ( & V_16 -> V_131 , V_184 ) ;
}
static void F_119 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
unsigned long V_184 ;
F_19 ( L_101 ) ;
F_98 ( & V_16 -> V_131 , V_184 ) ;
F_91 ( V_3 , 0 ) ;
F_99 ( & V_16 -> V_131 , V_184 ) ;
}
static T_8 F_120 ( struct V_2 * V_3 )
{
struct V_7 * V_7 = V_3 -> V_181 ;
struct V_1 * V_16 = F_1 ( V_3 ) ;
T_8 V_189 = 0 ;
if ( F_4 ( ! V_16 || ! V_7 ) ) {
goto V_217;
}
V_189 = F_38 ( & V_7 -> V_83 ) ;
V_217:
return V_189 ;
}
static T_9 int F_121 ( void )
{
int V_87 ;
F_100 ( V_218 L_102 , V_219 ) ;
V_172 = F_122 ( V_220 ) ;
if ( ! V_172 )
return - V_157 ;
V_172 -> V_221 = V_222 ;
V_172 -> V_223 = L_103 ;
V_172 -> V_224 = 0 ;
V_172 -> type = V_225 ;
V_172 -> V_226 = V_227 ;
V_172 -> V_184 = V_228 | V_229 ;
V_172 -> V_230 = V_231 ;
V_172 -> V_230 . V_232 = V_233 | V_234 | V_235 | \
V_236 | V_237 ;
V_172 -> V_230 . V_238 = 115200 ;
V_172 -> V_230 . V_239 = 115200 ;
F_123 ( V_172 , & V_240 ) ;
V_87 = F_124 ( V_172 ) ;
if ( V_87 ) {
F_100 ( V_241 L_104 ) ;
goto V_242;
}
V_87 = F_125 ( & V_243 ) ;
if ( V_87 ) {
F_100 ( V_241 L_105 ) ;
goto V_244;
}
return 0 ;
V_244:
F_126 ( V_172 ) ;
V_242:
F_127 ( V_172 ) ;
return V_87 ;
}
static T_10 void F_128 ( void )
{
F_100 ( V_218 L_106 , V_245 ) ;
F_129 ( & V_243 ) ;
F_126 ( V_172 ) ;
F_127 ( V_172 ) ;
}
