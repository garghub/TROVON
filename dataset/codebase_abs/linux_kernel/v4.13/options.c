T_1 F_1 ( const T_2 * V_1 , const T_2 V_2 )
{
T_1 V_3 = 0 ;
if ( V_2 >= V_4 )
V_3 += ( ( T_1 ) * V_1 ++ ) << 40 ;
if ( V_2 > 4 )
V_3 += ( ( T_1 ) * V_1 ++ ) << 32 ;
if ( V_2 > 3 )
V_3 += ( ( T_1 ) * V_1 ++ ) << 24 ;
if ( V_2 > 2 )
V_3 += ( ( T_1 ) * V_1 ++ ) << 16 ;
if ( V_2 > 1 )
V_3 += ( ( T_1 ) * V_1 ++ ) << 8 ;
if ( V_2 > 0 )
V_3 += * V_1 ;
return V_3 ;
}
int F_2 ( struct V_5 * V_6 , struct V_7 * V_8 ,
struct V_9 * V_10 )
{
struct V_11 * V_12 = F_3 ( V_6 ) ;
const struct V_13 * V_14 = V_13 ( V_10 ) ;
const T_2 V_15 = F_4 ( V_10 ) -> V_16 ;
unsigned char * V_17 = ( unsigned char * ) V_14 + F_5 ( V_10 ) ;
unsigned char * V_18 = V_17 ;
const unsigned char * V_19 = ( unsigned char * ) V_14 +
( V_14 -> V_20 * 4 ) ;
struct V_21 * V_22 = & V_12 -> V_23 ;
unsigned char V_24 , V_2 ;
unsigned char * V_25 ( V_3 ) ;
T_3 V_26 ;
T_4 V_27 ;
int V_28 ;
int V_29 = 0 ;
memset ( V_22 , 0 , sizeof( * V_22 ) ) ;
V_24 = V_2 = 0 ;
while ( V_18 != V_19 ) {
V_24 = * V_18 ++ ;
V_2 = 0 ;
V_3 = NULL ;
if ( V_24 > V_30 ) {
if ( V_18 == V_19 )
goto V_31;
V_2 = * V_18 ++ ;
if ( V_2 < 2 )
goto V_31;
V_2 -= 2 ;
V_3 = V_18 ;
V_18 += V_2 ;
if ( V_18 > V_19 )
goto V_31;
}
if ( V_8 != NULL && ( V_24 >= V_32 ||
V_24 == V_33 || V_24 == V_34 ) )
goto V_35;
switch ( V_24 ) {
case V_36 :
break;
case V_37 :
if ( V_29 )
goto V_38;
if ( V_15 != V_39 )
V_29 = 1 ;
break;
case V_40 :
if ( V_2 > 6 )
goto V_38;
V_22 -> V_41 = F_1 ( V_3 , V_2 ) ;
F_6 ( L_1 , F_7 ( V_6 ) ,
( unsigned long long ) V_22 -> V_41 ) ;
break;
case V_42 ... V_43 :
if ( V_15 == V_39 )
break;
if ( V_2 == 0 )
goto V_38;
V_28 = F_8 ( V_6 , V_8 , V_29 , V_24 ,
* V_3 , V_3 + 1 , V_2 - 1 ) ;
if ( V_28 )
goto V_44;
break;
case V_45 :
if ( V_2 != 4 )
goto V_38;
V_27 = F_9 ( ( T_4 * ) V_3 ) ;
if ( F_10 ( V_27 == 0 ) ) {
F_11 ( L_2 ) ;
break;
}
if ( V_8 != NULL ) {
V_8 -> V_46 = F_12 ( V_27 ) ;
V_8 -> V_47 = F_13 () ;
} else {
V_22 -> V_48 =
V_12 -> V_49 = F_12 ( V_27 ) ;
V_12 -> V_50 = F_13 () ;
}
F_6 ( L_3 ,
F_7 ( V_6 ) , F_12 ( V_27 ) ,
( unsigned long long )
F_4 ( V_10 ) -> V_51 ) ;
F_14 ( V_6 ) ;
break;
case V_52 :
if ( V_2 != 4 && V_2 != 6 && V_2 != 8 )
goto V_38;
V_27 = F_9 ( ( T_4 * ) V_3 ) ;
V_22 -> V_53 = F_12 ( V_27 ) ;
F_6 ( L_4
L_5 , F_7 ( V_6 ) ,
V_22 -> V_53 ,
V_2 + 2 ,
( unsigned long long )
F_4 ( V_10 ) -> V_51 ) ;
V_3 += 4 ;
if ( V_2 == 4 ) {
F_15 ( L_6 ) ;
break;
}
if ( V_2 == 6 ) {
T_5 V_54 = F_9 ( ( T_5 * ) V_3 ) ;
V_26 = F_16 ( V_54 ) ;
} else {
V_27 = F_9 ( ( T_4 * ) V_3 ) ;
V_26 = F_12 ( V_27 ) ;
}
F_15 ( L_7 , V_26 ) ;
if ( V_26 > V_22 -> V_55 )
V_22 -> V_55 = V_26 ;
break;
case V_56 :
if ( F_17 ( V_10 ) )
break;
if ( V_2 == 2 ) {
T_5 V_54 = F_9 ( ( T_5 * ) V_3 ) ;
V_26 = F_16 ( V_54 ) ;
} else if ( V_2 == 4 ) {
V_27 = F_9 ( ( T_4 * ) V_3 ) ;
V_26 = F_12 ( V_27 ) ;
} else {
goto V_38;
}
if ( V_26 > V_22 -> V_55 )
V_22 -> V_55 = V_26 ;
F_6 ( L_8 ,
F_7 ( V_6 ) , V_26 ) ;
break;
case V_32 ... V_57 :
if ( F_18 ( V_12 -> V_58 , V_6 ,
V_15 , V_24 , V_3 , V_2 ) )
goto V_38;
break;
case V_33 :
case V_34 :
if ( F_17 ( V_10 ) )
break;
case V_59 ... V_60 :
if ( F_19 ( V_12 -> V_61 , V_6 ,
V_15 , V_24 , V_3 , V_2 ) )
goto V_38;
break;
default:
F_20 ( L_9
L_10 , V_6 , V_24 , V_2 ) ;
break;
}
V_35:
if ( V_24 != V_37 )
V_29 = 0 ;
}
if ( V_29 )
goto V_38;
V_31:
return 0 ;
V_38:
F_21 ( V_62 ) ;
V_28 = V_63 ;
V_44:
F_11 ( L_11 , V_6 , V_24 , V_2 , V_28 ) ;
F_4 ( V_10 ) -> V_64 = V_28 ;
F_4 ( V_10 ) -> V_65 [ 0 ] = V_24 ;
F_4 ( V_10 ) -> V_65 [ 1 ] = V_2 > 0 ? V_3 [ 0 ] : 0 ;
F_4 ( V_10 ) -> V_65 [ 2 ] = V_2 > 1 ? V_3 [ 1 ] : 0 ;
return - 1 ;
}
void F_22 ( const T_1 V_3 , T_2 * V_66 , const T_2 V_2 )
{
if ( V_2 >= V_4 )
* V_66 ++ = ( V_3 & 0xFF0000000000ull ) >> 40 ;
if ( V_2 > 4 )
* V_66 ++ = ( V_3 & 0xFF00000000ull ) >> 32 ;
if ( V_2 > 3 )
* V_66 ++ = ( V_3 & 0xFF000000 ) >> 24 ;
if ( V_2 > 2 )
* V_66 ++ = ( V_3 & 0xFF0000 ) >> 16 ;
if ( V_2 > 1 )
* V_66 ++ = ( V_3 & 0xFF00 ) >> 8 ;
if ( V_2 > 0 )
* V_66 ++ = ( V_3 & 0xFF ) ;
}
static inline T_2 F_23 ( const T_1 V_67 )
{
if ( F_24 ( V_67 <= 0xFF ) )
return 1 ;
return F_24 ( V_67 <= V_68 ) ? 2 : ( V_67 <= V_69 ? 4 : 6 ) ;
}
int F_25 ( struct V_9 * V_10 , const unsigned char V_70 ,
const void * V_3 , const unsigned char V_2 )
{
unsigned char * V_66 ;
if ( F_4 ( V_10 ) -> V_71 + V_2 + 2 > V_72 )
return - 1 ;
F_4 ( V_10 ) -> V_71 += V_2 + 2 ;
V_66 = F_26 ( V_10 , V_2 + 2 ) ;
* V_66 ++ = V_70 ;
* V_66 ++ = V_2 + 2 ;
memcpy ( V_66 , V_3 , V_2 ) ;
return 0 ;
}
static int F_27 ( struct V_5 * V_6 , struct V_9 * V_10 )
{
struct V_11 * V_12 = F_3 ( V_6 ) ;
T_1 V_67 = V_12 -> V_73 ;
if ( F_28 ( V_10 ) )
++ V_12 -> V_73 ;
else
V_12 -> V_73 = 0 ;
if ( V_67 > 0 ) {
unsigned char * V_74 ;
const int V_75 = F_23 ( V_67 ) ;
const int V_2 = V_75 + 2 ;
if ( F_4 ( V_10 ) -> V_71 + V_2 > V_72 )
return - 1 ;
F_4 ( V_10 ) -> V_71 += V_2 ;
V_74 = F_26 ( V_10 , V_2 ) ;
* V_74 ++ = V_40 ;
* V_74 ++ = V_2 ;
F_22 ( V_67 , V_74 , V_75 ) ;
}
return 0 ;
}
static inline int F_29 ( const T_3 V_26 )
{
return V_26 == 0 ? 0 : V_26 <= 0xFFFF ? 2 : 4 ;
}
static int F_30 ( struct V_9 * V_10 )
{
T_4 V_76 = F_31 ( F_13 () ) ;
return F_25 ( V_10 , V_45 , & V_76 , sizeof( V_76 ) ) ;
}
static int F_32 ( struct V_11 * V_12 ,
struct V_7 * V_8 ,
struct V_9 * V_10 )
{
T_4 V_77 ;
unsigned char * V_66 ;
T_3 V_26 , V_78 , V_2 ;
if ( V_8 != NULL ) {
V_26 = F_13 () - V_8 -> V_47 ;
V_77 = F_31 ( V_8 -> V_46 ) ;
V_8 -> V_46 = 0 ;
} else {
V_26 = F_13 () - V_12 -> V_50 ;
V_77 = F_31 ( V_12 -> V_49 ) ;
V_12 -> V_49 = 0 ;
}
V_78 = F_29 ( V_26 ) ;
V_2 = 6 + V_78 ;
if ( F_4 ( V_10 ) -> V_71 + V_2 > V_72 )
return - 1 ;
F_4 ( V_10 ) -> V_71 += V_2 ;
V_66 = F_26 ( V_10 , V_2 ) ;
* V_66 ++ = V_52 ;
* V_66 ++ = V_2 ;
memcpy ( V_66 , & V_77 , 4 ) ;
V_66 += 4 ;
if ( V_78 == 2 ) {
const T_5 V_79 = F_33 ( ( V_80 ) V_26 ) ;
memcpy ( V_66 , & V_79 , 2 ) ;
} else if ( V_78 == 4 ) {
const T_4 V_81 = F_31 ( V_26 ) ;
memcpy ( V_66 , & V_81 , 4 ) ;
}
return 0 ;
}
static int F_34 ( struct V_5 * V_6 , struct V_9 * V_10 )
{
struct V_11 * V_12 = F_3 ( V_6 ) ;
struct V_82 * V_83 = V_12 -> V_84 ;
struct V_85 * V_86 = F_4 ( V_10 ) ;
const V_80 V_87 = F_35 ( V_83 ) ;
const T_2 V_88 = F_36 ( V_87 , V_89 ) ;
V_80 V_2 = V_87 + 2 * V_88 ;
T_2 V_90 , V_91 = 0 ;
const unsigned char * V_92 , * V_93 ;
unsigned char * V_66 ;
if ( V_86 -> V_71 + V_2 > V_72 ) {
F_11 ( L_12 , V_2 ,
F_37 ( V_86 -> V_16 ) ) ;
return - 1 ;
}
if ( V_2 > V_94 &&
V_2 + V_86 -> V_71 + V_10 -> V_2 > V_12 -> V_95 ) {
F_11 ( L_13
L_14 , V_2 , V_10 -> V_2 ,
V_86 -> V_71 , V_12 -> V_95 ) ;
V_12 -> V_96 = 1 ;
return 0 ;
}
V_86 -> V_71 += V_2 ;
V_66 = F_26 ( V_10 , V_2 ) ;
V_2 = V_87 ;
V_93 = V_83 -> V_97 + V_83 -> V_98 ;
V_92 = V_83 -> V_97 + V_99 ;
for ( V_90 = 0 ; V_90 < V_88 ; ++ V_90 ) {
int V_100 = V_2 ;
if ( V_2 > V_89 )
V_100 = V_89 ;
V_91 ^= V_83 -> V_101 [ V_90 ] ;
* V_66 ++ = V_33 + V_83 -> V_101 [ V_90 ] ;
* V_66 ++ = V_100 + 2 ;
if ( V_93 + V_100 > V_92 ) {
const V_80 V_102 = V_92 - V_93 ;
memcpy ( V_66 , V_93 , V_102 ) ;
V_66 += V_102 ;
V_2 -= V_102 ;
V_100 -= V_102 ;
V_93 = V_83 -> V_97 ;
}
memcpy ( V_66 , V_93 , V_100 ) ;
V_93 += V_100 ;
V_66 += V_100 ;
V_2 -= V_100 ;
}
if ( F_38 ( V_83 , V_86 -> V_103 , V_91 ) )
return - V_104 ;
return 0 ;
}
int F_39 ( struct V_9 * V_10 )
{
if ( F_4 ( V_10 ) -> V_71 >= V_72 )
return - 1 ;
F_4 ( V_10 ) -> V_71 ++ ;
* ( T_2 * ) F_26 ( V_10 , 1 ) = V_37 ;
return 0 ;
}
int F_40 ( struct V_9 * V_10 , T_2 type , T_2 V_105 ,
T_2 * V_106 , T_2 V_2 , bool V_107 )
{
T_2 V_108 , * V_66 ;
if ( V_2 > ( V_89 - 2 ) ) {
F_11 ( L_15 , V_2 , V_105 ) ;
return - 1 ;
}
if ( F_10 ( V_106 == NULL || V_2 == 0 ) )
V_2 = V_107 = false ;
V_108 = 3 + V_107 + V_2 ;
if ( F_4 ( V_10 ) -> V_71 + V_108 > V_72 ) {
F_11 ( L_16 , V_105 ) ;
return - 1 ;
}
F_4 ( V_10 ) -> V_71 += V_108 ;
V_66 = F_26 ( V_10 , V_108 ) ;
* V_66 ++ = type ;
* V_66 ++ = V_108 ;
* V_66 ++ = V_105 ;
if ( V_107 )
* V_66 ++ = * V_106 ;
if ( V_2 )
memcpy ( V_66 , V_106 , V_2 ) ;
return 0 ;
}
static void F_41 ( struct V_9 * V_10 )
{
int V_109 = F_4 ( V_10 ) -> V_71 % 4 ;
if ( V_109 != 0 ) {
V_109 = 4 - V_109 ;
memset ( F_26 ( V_10 , V_109 ) , 0 , V_109 ) ;
F_4 ( V_10 ) -> V_71 += V_109 ;
}
}
int F_42 ( struct V_5 * V_6 , struct V_9 * V_10 )
{
struct V_11 * V_12 = F_3 ( V_6 ) ;
F_4 ( V_10 ) -> V_71 = 0 ;
if ( V_12 -> V_110 && F_27 ( V_6 , V_10 ) )
return - 1 ;
if ( F_4 ( V_10 ) -> V_16 != V_39 ) {
if ( F_43 ( V_12 , NULL , V_10 ) )
return - 1 ;
if ( F_4 ( V_10 ) -> V_16 == V_111 ) {
if ( F_30 ( V_10 ) )
return - 1 ;
} else if ( F_44 ( V_6 ) &&
F_34 ( V_6 , V_10 ) ) {
return - 1 ;
}
}
if ( V_12 -> V_112 ) {
if ( F_45 ( V_12 -> V_58 , V_6 , V_10 ) )
return - 1 ;
V_12 -> V_112 = 0 ;
}
if ( V_12 -> V_49 != 0 &&
F_32 ( V_12 , NULL , V_10 ) )
return - 1 ;
F_41 ( V_10 ) ;
return 0 ;
}
int F_46 ( struct V_7 * V_8 , struct V_9 * V_10 )
{
F_4 ( V_10 ) -> V_71 = 0 ;
if ( F_43 ( NULL , V_8 , V_10 ) )
return - 1 ;
if ( F_30 ( V_10 ) )
return - 1 ;
if ( V_8 -> V_46 != 0 &&
F_32 ( NULL , V_8 , V_10 ) )
return - 1 ;
F_41 ( V_10 ) ;
return 0 ;
}
