static T_1 F_1 ( T_1 V_1 , T_1 V_2 )
{
return V_1 / V_2 ;
}
static T_1 F_2 ( T_1 V_1 , T_1 V_2 )
{
return V_1 % V_2 ;
}
static inline void F_3 ( int V_3 , T_1 V_4 , struct V_5 * V_6 )
{
V_4 |= ( V_3 << 28 ) ;
V_4 = F_4 ( V_4 ) ;
if ( V_6 -> V_7 != NULL )
V_6 -> V_7 [ V_6 -> V_8 ] = V_4 ;
V_6 -> V_8 ++ ;
}
static inline void F_5 ( T_1 V_4 , struct V_5 * V_6 )
{
F_3 ( V_9 , V_4 , V_6 ) ;
}
static T_2 F_6 ( T_1 V_10 )
{
T_1 V_11 ;
for ( V_11 = 0 ; V_11 < 16 ; V_11 ++ )
if ( ( V_10 & ~ F_7 ( 0xff , 2 * V_11 ) ) == 0 )
return F_8 ( V_10 , 2 * V_11 ) | ( V_11 << 8 ) ;
return - 1 ;
}
static void F_9 ( void * V_12 , unsigned int V_13 )
{
T_1 * V_14 ;
for ( V_14 = V_12 ; V_13 >= sizeof( T_1 ) ; V_13 -= sizeof( T_1 ) )
* V_14 ++ = F_4 ( V_15 ) ;
}
static T_3 F_10 ( T_1 V_16 , struct V_5 * V_6 )
{
unsigned int V_17 = 0 , V_18 ;
T_3 V_19 ;
if ( V_6 -> V_7 == NULL ) {
V_6 -> V_20 ++ ;
return 0 ;
}
while ( ( V_17 < V_6 -> V_20 ) && V_6 -> V_21 [ V_17 ] ) {
if ( V_6 -> V_21 [ V_17 ] == V_16 )
break;
V_17 ++ ;
}
if ( V_6 -> V_21 [ V_17 ] == 0 )
V_6 -> V_21 [ V_17 ] = V_16 ;
V_18 = V_6 -> V_22 [ V_6 -> V_23 -> V_24 - 1 ] * 4 ;
V_18 += V_6 -> V_25 ;
V_18 += V_6 -> V_26 ;
V_18 += V_17 * 4 ;
V_6 -> V_7 [ V_18 / 4 ] = V_16 ;
V_19 = V_18 - ( 8 + V_6 -> V_8 * 4 ) ;
if ( V_19 & ~ 0xfff ) {
V_6 -> V_27 |= V_28 ;
return 0 ;
}
return V_19 ;
}
static inline int F_11 ( int V_29 , int V_30 ,
const struct V_5 * V_6 ) {
int V_31 , V_32 ;
if ( V_6 -> V_7 == NULL )
return 0 ;
V_31 = V_6 -> V_22 [ V_29 ] ;
V_32 = V_6 -> V_22 [ V_30 ] ;
return V_31 - V_32 - 1 ;
}
static inline void F_12 ( const T_4 V_33 , T_1 V_34 , struct V_5 * V_6 )
{
#if V_35 < 7
F_5 ( F_13 ( V_33 , V_36 , F_10 ( V_34 , V_6 ) ) , V_6 ) ;
#else
F_5 ( F_14 ( V_33 , V_34 & 0xffff ) , V_6 ) ;
if ( V_34 > 0xffff )
F_5 ( F_15 ( V_33 , V_34 >> 16 ) , V_6 ) ;
#endif
}
static inline void F_16 ( const T_4 V_33 , T_1 V_34 , struct V_5 * V_6 )
{
int V_37 = F_6 ( V_34 ) ;
if ( V_37 >= 0 )
F_5 ( F_17 ( V_33 , V_37 ) , V_6 ) ;
else
F_12 ( V_33 , V_34 , V_6 ) ;
}
static inline void F_18 ( T_4 V_38 , struct V_5 * V_6 )
{
V_6 -> V_39 |= V_40 ;
#if V_35 < 5
F_5 ( F_19 ( V_41 , V_36 ) , V_6 ) ;
if ( V_42 & V_43 )
F_5 ( F_20 ( V_38 ) , V_6 ) ;
else
F_5 ( F_19 ( V_36 , V_38 ) , V_6 ) ;
#else
F_5 ( F_21 ( V_38 ) , V_6 ) ;
#endif
}
static inline int F_22 ( const struct V_5 * V_6 )
{
int V_31 , V_32 ;
if ( V_6 -> V_7 == NULL )
return 0 ;
V_31 = V_6 -> F_22 ;
V_32 = V_6 -> V_8 ;
return V_31 - V_32 - 2 ;
}
static inline void F_23 ( T_4 V_33 , T_4 V_44 , T_4 V_45 , struct V_5 * V_6 , T_4 V_46 )
{
const T_4 * V_47 = V_48 [ V_49 ] ;
T_5 V_50 ;
F_5 ( F_24 ( V_45 , 0 ) , V_6 ) ;
F_3 ( V_51 , F_17 ( V_52 , 0 ) , V_6 ) ;
V_50 = F_22 ( V_6 ) ;
F_3 ( V_51 , F_25 ( V_50 ) , V_6 ) ;
#if V_35 == 7
if ( V_42 & V_53 ) {
if ( V_46 == V_54 )
F_5 ( F_26 ( V_33 , V_44 , V_45 ) , V_6 ) ;
else {
F_5 ( F_26 ( V_55 , V_44 , V_45 ) , V_6 ) ;
F_5 ( F_27 ( V_33 , V_45 , V_55 , V_44 ) , V_6 ) ;
}
return;
}
#endif
if ( V_45 != V_56 ) {
F_5 ( F_19 ( V_47 [ 0 ] , V_56 ) , V_6 ) ;
F_5 ( F_19 ( V_56 , V_45 ) , V_6 ) ;
}
if ( V_44 != V_52 ) {
F_5 ( F_19 ( V_47 [ 1 ] , V_52 ) , V_6 ) ;
F_5 ( F_19 ( V_52 , V_44 ) , V_6 ) ;
}
V_6 -> V_39 |= V_40 ;
F_16 ( V_55 , V_46 == V_54 ?
( T_1 ) F_1 : ( T_1 ) F_2 , V_6 ) ;
F_18 ( V_55 , V_6 ) ;
if ( V_33 != V_52 )
F_5 ( F_19 ( V_33 , V_52 ) , V_6 ) ;
if ( V_45 != V_56 )
F_5 ( F_19 ( V_56 , V_47 [ 0 ] ) , V_6 ) ;
if ( V_44 != V_52 )
F_5 ( F_19 ( V_52 , V_47 [ 1 ] ) , V_6 ) ;
}
static inline bool F_28 ( T_4 V_57 )
{
static T_4 V_58 [] = { V_59 , V_60 , V_61 , V_62 ,
V_63 , V_64 , V_65 , V_66 ,
V_67 , V_68 } ;
int V_17 , V_69 = sizeof( V_58 ) ;
for ( V_17 = 0 ; V_17 < V_69 ; V_17 ++ ) {
if ( V_57 == V_58 [ V_17 ] )
return true ;
}
return false ;
}
static inline void F_29 ( const T_4 V_70 , const T_1 V_34 ,
bool V_71 , struct V_5 * V_6 )
{
const T_4 * V_47 = V_48 [ V_49 ] ;
if ( V_71 ) {
F_16 ( V_47 [ 1 ] , V_34 , V_6 ) ;
F_5 ( F_30 ( V_47 [ 1 ] , V_72 , F_31 ( V_70 ) ) , V_6 ) ;
} else {
F_16 ( V_70 , V_34 , V_6 ) ;
}
}
static inline void F_32 ( const bool V_73 , const T_4 V_70 [] ,
const T_1 V_34 , bool V_71 ,
struct V_5 * V_6 ) {
T_1 V_74 = 0 ;
if ( V_73 && ( V_34 & ( 1 << 31 ) ) )
V_74 = ( T_1 ) ~ 0 ;
F_29 ( V_75 , V_34 , V_71 , V_6 ) ;
F_29 ( V_76 , V_74 , V_71 , V_6 ) ;
}
static inline void F_33 ( const T_4 V_70 , const T_4 V_77 ,
const bool V_73 , const bool V_74 ,
struct V_5 * V_6 ) {
if ( ! V_74 && V_73 )
F_5 ( F_34 ( V_70 , V_70 , V_77 ) , V_6 ) ;
else if ( V_74 && V_73 )
F_5 ( F_35 ( V_70 , V_70 , V_77 ) , V_6 ) ;
else
F_5 ( F_36 ( V_70 , V_70 , V_77 ) , V_6 ) ;
}
static inline void F_37 ( const T_4 V_70 , const T_4 V_77 ,
const bool V_73 , const bool V_74 ,
struct V_5 * V_6 ) {
if ( ! V_74 && V_73 )
F_5 ( F_38 ( V_70 , V_70 , V_77 ) , V_6 ) ;
else if ( V_74 && V_73 )
F_5 ( F_39 ( V_70 , V_70 , V_77 ) , V_6 ) ;
else
F_5 ( F_40 ( V_70 , V_70 , V_77 ) , V_6 ) ;
}
static inline void F_41 ( const T_4 V_70 , const T_4 V_77 , const bool V_73 ,
const bool V_74 , const T_4 V_46 , struct V_5 * V_6 ) {
switch ( F_42 ( V_46 ) ) {
case V_78 :
F_33 ( V_70 , V_77 , V_73 , V_74 , V_6 ) ;
break;
case V_79 :
F_37 ( V_70 , V_77 , V_73 , V_74 , V_6 ) ;
break;
case V_80 :
F_5 ( F_43 ( V_70 , V_70 , V_77 ) , V_6 ) ;
break;
case V_81 :
F_5 ( F_44 ( V_70 , V_70 , V_77 ) , V_6 ) ;
break;
case V_82 :
F_5 ( F_45 ( V_70 , V_70 , V_77 ) , V_6 ) ;
break;
case V_83 :
F_5 ( F_46 ( V_70 , V_70 , V_77 ) , V_6 ) ;
break;
case V_84 :
F_5 ( F_47 ( V_70 , V_70 , V_77 ) , V_6 ) ;
break;
case V_85 :
F_5 ( F_48 ( V_70 , V_70 , V_77 ) , V_6 ) ;
break;
case V_86 :
F_5 ( F_49 ( V_70 , V_70 , V_87 , V_77 ) , V_6 ) ;
break;
}
}
static inline void F_50 ( const T_4 V_70 , const T_4 V_77 ,
bool V_71 , bool V_88 ,
struct V_5 * V_6 , const bool V_73 ,
const bool V_74 , const T_4 V_46 ) {
const T_4 * V_47 = V_48 [ V_49 ] ;
T_4 V_45 = V_88 ? V_47 [ 1 ] : V_77 ;
if ( V_88 )
F_5 ( F_13 ( V_45 , V_72 , F_31 ( V_77 ) ) , V_6 ) ;
if ( V_71 ) {
F_5 ( F_13 ( V_47 [ 0 ] , V_72 , F_31 ( V_70 ) ) , V_6 ) ;
F_41 ( V_47 [ 0 ] , V_45 , V_73 , V_74 , V_46 , V_6 ) ;
F_5 ( F_30 ( V_47 [ 0 ] , V_72 , F_31 ( V_70 ) ) , V_6 ) ;
} else {
F_41 ( V_70 , V_45 , V_73 , V_74 , V_46 , V_6 ) ;
}
}
static inline void F_51 ( const bool V_73 , const T_4 V_70 [] ,
const T_4 V_77 [] , bool V_71 ,
bool V_88 , struct V_5 * V_6 ,
const T_4 V_46 ) {
F_50 ( V_75 , V_89 , V_71 , V_88 , V_6 , V_73 , false , V_46 ) ;
if ( V_73 )
F_50 ( V_76 , V_90 , V_71 , V_88 , V_6 , V_73 , true , V_46 ) ;
else
F_29 ( V_76 , 0 , V_71 , V_6 ) ;
}
static inline void F_52 ( const T_4 V_70 , const T_4 V_77 ,
bool V_71 , bool V_88 ,
struct V_5 * V_6 ) {
const T_4 * V_47 = V_48 [ V_49 ] ;
T_4 V_91 = V_88 ? V_47 [ 0 ] : V_77 ;
if ( V_88 )
F_5 ( F_13 ( V_47 [ 0 ] , V_72 , F_31 ( V_77 ) ) , V_6 ) ;
if ( V_71 )
F_5 ( F_30 ( V_91 , V_72 , F_31 ( V_70 ) ) , V_6 ) ;
else
F_5 ( F_19 ( V_70 , V_91 ) , V_6 ) ;
}
static inline void F_53 ( const bool V_73 , const T_4 V_70 [] ,
const T_4 V_77 [] , bool V_71 ,
bool V_88 , struct V_5 * V_6 ) {
F_52 ( V_75 , V_89 , V_71 , V_88 , V_6 ) ;
if ( V_73 ) {
F_52 ( V_76 , V_90 , V_71 , V_88 , V_6 ) ;
} else {
F_29 ( V_76 , 0 , V_71 , V_6 ) ;
}
}
static inline void F_54 ( const T_4 V_70 , const T_1 V_34 , bool V_71 ,
struct V_5 * V_6 , const T_4 V_46 ) {
const T_4 * V_47 = V_48 [ V_49 ] ;
T_4 V_33 = V_71 ? V_47 [ 0 ] : V_70 ;
if ( V_71 )
F_5 ( F_13 ( V_33 , V_72 , F_31 ( V_70 ) ) , V_6 ) ;
switch ( V_46 ) {
case V_84 :
F_5 ( F_55 ( V_33 , V_33 , V_34 ) , V_6 ) ;
break;
case V_85 :
F_5 ( F_56 ( V_33 , V_33 , V_34 ) , V_6 ) ;
break;
case V_92 :
F_5 ( F_57 ( V_33 , V_33 , V_34 ) , V_6 ) ;
break;
}
if ( V_71 )
F_5 ( F_30 ( V_33 , V_72 , F_31 ( V_70 ) ) , V_6 ) ;
}
static inline void F_58 ( const T_4 V_70 [] , bool V_71 ,
struct V_5 * V_6 ) {
const T_4 * V_47 = V_48 [ V_49 ] ;
T_4 V_33 = V_71 ? V_47 [ 1 ] : V_70 [ 1 ] ;
T_4 V_44 = V_71 ? V_47 [ 0 ] : V_70 [ 0 ] ;
if ( V_71 ) {
F_5 ( F_13 ( V_33 , V_72 , F_31 ( V_75 ) ) , V_6 ) ;
F_5 ( F_13 ( V_44 , V_72 , F_31 ( V_76 ) ) , V_6 ) ;
}
F_5 ( F_59 ( V_33 , V_33 , 0 ) , V_6 ) ;
F_5 ( F_60 ( V_44 , V_44 , 0 ) , V_6 ) ;
if ( V_71 ) {
F_5 ( F_30 ( V_33 , V_72 , F_31 ( V_75 ) ) , V_6 ) ;
F_5 ( F_30 ( V_44 , V_72 , F_31 ( V_76 ) ) , V_6 ) ;
}
}
static inline void F_61 ( const T_4 V_70 [] , const T_4 V_77 [] , bool V_71 ,
bool V_88 , struct V_5 * V_6 ) {
const T_4 * V_47 = V_48 [ V_49 ] ;
const T_4 * V_93 = V_48 [ V_94 ] ;
T_4 V_91 = V_88 ? V_93 [ 1 ] : V_89 ;
T_4 V_33 = V_71 ? V_47 [ 1 ] : V_75 ;
T_4 V_44 = V_71 ? V_47 [ 0 ] : V_76 ;
if ( V_88 )
F_5 ( F_13 ( V_91 , V_72 , F_31 ( V_89 ) ) , V_6 ) ;
if ( V_71 ) {
F_5 ( F_13 ( V_33 , V_72 , F_31 ( V_75 ) ) , V_6 ) ;
F_5 ( F_13 ( V_44 , V_72 , F_31 ( V_76 ) ) , V_6 ) ;
}
F_5 ( F_62 ( V_55 , V_91 , 32 ) , V_6 ) ;
F_5 ( F_57 ( V_93 [ 0 ] , V_91 , 32 ) , V_6 ) ;
V_6 -> V_39 |= V_40 ;
F_5 ( F_49 ( V_41 , V_44 , V_95 , V_91 ) , V_6 ) ;
F_5 ( F_63 ( V_41 , V_41 , V_33 , V_95 , V_55 ) , V_6 ) ;
F_5 ( F_63 ( V_55 , V_41 , V_33 , V_96 , V_93 [ 0 ] ) , V_6 ) ;
F_5 ( F_49 ( V_41 , V_33 , V_95 , V_91 ) , V_6 ) ;
if ( V_71 ) {
F_5 ( F_30 ( V_41 , V_72 , F_31 ( V_75 ) ) , V_6 ) ;
F_5 ( F_30 ( V_55 , V_72 , F_31 ( V_76 ) ) , V_6 ) ;
} else {
F_5 ( F_19 ( V_33 , V_41 ) , V_6 ) ;
F_5 ( F_19 ( V_44 , V_55 ) , V_6 ) ;
}
}
static inline void F_64 ( const T_4 V_70 [] , const T_4 V_77 [] , bool V_71 ,
bool V_88 , struct V_5 * V_6 ) {
const T_4 * V_47 = V_48 [ V_49 ] ;
const T_4 * V_93 = V_48 [ V_94 ] ;
T_4 V_91 = V_88 ? V_93 [ 1 ] : V_89 ;
T_4 V_33 = V_71 ? V_47 [ 1 ] : V_75 ;
T_4 V_44 = V_71 ? V_47 [ 0 ] : V_76 ;
if ( V_88 )
F_5 ( F_13 ( V_91 , V_72 , F_31 ( V_89 ) ) , V_6 ) ;
if ( V_71 ) {
F_5 ( F_13 ( V_33 , V_72 , F_31 ( V_75 ) ) , V_6 ) ;
F_5 ( F_13 ( V_44 , V_72 , F_31 ( V_76 ) ) , V_6 ) ;
}
F_5 ( F_57 ( V_55 , V_91 , 32 ) , V_6 ) ;
F_5 ( F_65 ( V_93 [ 0 ] , V_91 , 32 ) , V_6 ) ;
V_6 -> V_39 |= V_40 ;
F_5 ( F_49 ( V_41 , V_33 , V_96 , V_91 ) , V_6 ) ;
F_5 ( F_63 ( V_41 , V_41 , V_44 , V_95 , V_55 ) , V_6 ) ;
F_3 ( V_97 , F_25 ( 0 ) , V_6 ) ;
F_5 ( F_63 ( V_41 , V_41 , V_44 , V_87 , V_93 [ 0 ] ) , V_6 ) ;
F_5 ( F_49 ( V_55 , V_44 , V_87 , V_91 ) , V_6 ) ;
if ( V_71 ) {
F_5 ( F_30 ( V_41 , V_72 , F_31 ( V_75 ) ) , V_6 ) ;
F_5 ( F_30 ( V_55 , V_72 , F_31 ( V_76 ) ) , V_6 ) ;
} else {
F_5 ( F_19 ( V_33 , V_41 ) , V_6 ) ;
F_5 ( F_19 ( V_44 , V_55 ) , V_6 ) ;
}
}
static inline void F_66 ( const T_4 V_70 [] , const T_4 V_77 [] , bool V_71 ,
bool V_88 , struct V_5 * V_6 ) {
const T_4 * V_47 = V_48 [ V_49 ] ;
const T_4 * V_93 = V_48 [ V_94 ] ;
T_4 V_91 = V_88 ? V_93 [ 1 ] : V_89 ;
T_4 V_33 = V_71 ? V_47 [ 1 ] : V_75 ;
T_4 V_44 = V_71 ? V_47 [ 0 ] : V_76 ;
if ( V_88 )
F_5 ( F_13 ( V_91 , V_72 , F_31 ( V_89 ) ) , V_6 ) ;
if ( V_71 ) {
F_5 ( F_13 ( V_33 , V_72 , F_31 ( V_75 ) ) , V_6 ) ;
F_5 ( F_13 ( V_44 , V_72 , F_31 ( V_76 ) ) , V_6 ) ;
}
F_5 ( F_57 ( V_55 , V_91 , 32 ) , V_6 ) ;
F_5 ( F_65 ( V_93 [ 0 ] , V_91 , 32 ) , V_6 ) ;
V_6 -> V_39 |= V_40 ;
F_5 ( F_49 ( V_41 , V_33 , V_96 , V_91 ) , V_6 ) ;
F_5 ( F_63 ( V_41 , V_41 , V_44 , V_95 , V_55 ) , V_6 ) ;
F_5 ( F_63 ( V_41 , V_41 , V_44 , V_96 , V_93 [ 0 ] ) , V_6 ) ;
F_5 ( F_49 ( V_55 , V_44 , V_96 , V_91 ) , V_6 ) ;
if ( V_71 ) {
F_5 ( F_30 ( V_41 , V_72 , F_31 ( V_75 ) ) , V_6 ) ;
F_5 ( F_30 ( V_55 , V_72 , F_31 ( V_76 ) ) , V_6 ) ;
} else {
F_5 ( F_19 ( V_33 , V_41 ) , V_6 ) ;
F_5 ( F_19 ( V_44 , V_55 ) , V_6 ) ;
}
}
static inline void F_67 ( const T_4 V_70 [] , bool V_71 ,
const T_1 V_34 , struct V_5 * V_6 ) {
const T_4 * V_47 = V_48 [ V_49 ] ;
const T_4 * V_93 = V_48 [ V_94 ] ;
T_4 V_33 = V_71 ? V_47 [ 1 ] : V_75 ;
T_4 V_44 = V_71 ? V_47 [ 0 ] : V_76 ;
if ( V_71 ) {
F_5 ( F_13 ( V_33 , V_72 , F_31 ( V_75 ) ) , V_6 ) ;
F_5 ( F_13 ( V_44 , V_72 , F_31 ( V_76 ) ) , V_6 ) ;
}
if ( V_34 < 32 ) {
F_5 ( F_68 ( V_93 [ 0 ] , V_44 , V_95 , V_34 ) , V_6 ) ;
F_5 ( F_69 ( V_44 , V_93 [ 0 ] , V_33 , V_96 , 32 - V_34 ) , V_6 ) ;
F_5 ( F_68 ( V_33 , V_33 , V_95 , V_34 ) , V_6 ) ;
} else {
if ( V_34 == 32 )
F_5 ( F_19 ( V_44 , V_33 ) , V_6 ) ;
else
F_5 ( F_68 ( V_44 , V_33 , V_95 , V_34 - 32 ) , V_6 ) ;
F_5 ( F_45 ( V_33 , V_33 , V_33 ) , V_6 ) ;
}
if ( V_71 ) {
F_5 ( F_30 ( V_33 , V_72 , F_31 ( V_75 ) ) , V_6 ) ;
F_5 ( F_30 ( V_44 , V_72 , F_31 ( V_76 ) ) , V_6 ) ;
}
}
static inline void F_70 ( const T_4 V_70 [] , bool V_71 ,
const T_1 V_34 , struct V_5 * V_6 ) {
const T_4 * V_47 = V_48 [ V_49 ] ;
const T_4 * V_93 = V_48 [ V_94 ] ;
T_4 V_33 = V_71 ? V_47 [ 1 ] : V_75 ;
T_4 V_44 = V_71 ? V_47 [ 0 ] : V_76 ;
if ( V_71 ) {
F_5 ( F_13 ( V_33 , V_72 , F_31 ( V_75 ) ) , V_6 ) ;
F_5 ( F_13 ( V_44 , V_72 , F_31 ( V_76 ) ) , V_6 ) ;
}
if ( V_34 < 32 ) {
F_5 ( F_68 ( V_93 [ 1 ] , V_33 , V_96 , V_34 ) , V_6 ) ;
F_5 ( F_69 ( V_33 , V_93 [ 1 ] , V_44 , V_95 , 32 - V_34 ) , V_6 ) ;
F_5 ( F_68 ( V_44 , V_44 , V_96 , V_34 ) , V_6 ) ;
} else if ( V_34 == 32 ) {
F_5 ( F_19 ( V_33 , V_44 ) , V_6 ) ;
F_5 ( F_17 ( V_44 , 0 ) , V_6 ) ;
} else {
F_5 ( F_68 ( V_33 , V_44 , V_96 , V_34 - 32 ) , V_6 ) ;
F_5 ( F_17 ( V_44 , 0 ) , V_6 ) ;
}
if ( V_71 ) {
F_5 ( F_30 ( V_33 , V_72 , F_31 ( V_75 ) ) , V_6 ) ;
F_5 ( F_30 ( V_44 , V_72 , F_31 ( V_76 ) ) , V_6 ) ;
}
}
static inline void F_71 ( const T_4 V_70 [] , bool V_71 ,
const T_1 V_34 , struct V_5 * V_6 ) {
const T_4 * V_47 = V_48 [ V_49 ] ;
const T_4 * V_93 = V_48 [ V_94 ] ;
T_4 V_33 = V_71 ? V_47 [ 1 ] : V_75 ;
T_4 V_44 = V_71 ? V_47 [ 0 ] : V_76 ;
if ( V_71 ) {
F_5 ( F_13 ( V_33 , V_72 , F_31 ( V_75 ) ) , V_6 ) ;
F_5 ( F_13 ( V_44 , V_72 , F_31 ( V_76 ) ) , V_6 ) ;
}
if ( V_34 < 32 ) {
F_5 ( F_68 ( V_93 [ 1 ] , V_33 , V_96 , V_34 ) , V_6 ) ;
F_5 ( F_69 ( V_33 , V_93 [ 1 ] , V_44 , V_95 , 32 - V_34 ) , V_6 ) ;
F_5 ( F_68 ( V_44 , V_44 , V_87 , V_34 ) , V_6 ) ;
} else if ( V_34 == 32 ) {
F_5 ( F_19 ( V_33 , V_44 ) , V_6 ) ;
F_5 ( F_68 ( V_44 , V_44 , V_87 , 31 ) , V_6 ) ;
} else {
F_5 ( F_68 ( V_33 , V_44 , V_87 , V_34 - 32 ) , V_6 ) ;
F_5 ( F_68 ( V_44 , V_44 , V_87 , 31 ) , V_6 ) ;
}
if ( V_71 ) {
F_5 ( F_30 ( V_33 , V_72 , F_31 ( V_75 ) ) , V_6 ) ;
F_5 ( F_30 ( V_44 , V_72 , F_31 ( V_76 ) ) , V_6 ) ;
}
}
static inline void F_72 ( const T_4 V_70 [] , const T_4 V_77 [] , bool V_71 ,
bool V_88 , struct V_5 * V_6 ) {
const T_4 * V_47 = V_48 [ V_49 ] ;
const T_4 * V_93 = V_48 [ V_94 ] ;
T_4 V_33 = V_71 ? V_47 [ 1 ] : V_75 ;
T_4 V_44 = V_71 ? V_47 [ 0 ] : V_76 ;
T_4 V_91 = V_88 ? V_93 [ 1 ] : V_89 ;
T_4 V_45 = V_88 ? V_93 [ 0 ] : V_90 ;
if ( V_71 ) {
F_5 ( F_13 ( V_33 , V_72 , F_31 ( V_75 ) ) , V_6 ) ;
F_5 ( F_13 ( V_44 , V_72 , F_31 ( V_76 ) ) , V_6 ) ;
}
if ( V_88 ) {
F_5 ( F_13 ( V_91 , V_72 , F_31 ( V_89 ) ) , V_6 ) ;
F_5 ( F_13 ( V_45 , V_72 , F_31 ( V_90 ) ) , V_6 ) ;
}
F_5 ( F_46 ( V_55 , V_33 , V_45 ) , V_6 ) ;
F_5 ( F_46 ( V_41 , V_44 , V_91 ) , V_6 ) ;
V_6 -> V_39 |= V_40 ;
F_5 ( F_36 ( V_41 , V_55 , V_41 ) , V_6 ) ;
F_5 ( F_73 ( V_55 , V_44 , V_33 , V_91 ) , V_6 ) ;
F_5 ( F_36 ( V_44 , V_41 , V_44 ) , V_6 ) ;
if ( V_71 ) {
F_5 ( F_30 ( V_55 , V_72 , F_31 ( V_75 ) ) , V_6 ) ;
F_5 ( F_30 ( V_44 , V_72 , F_31 ( V_76 ) ) , V_6 ) ;
} else {
F_5 ( F_19 ( V_33 , V_55 ) , V_6 ) ;
}
}
static inline void F_74 ( const T_4 V_70 , const T_4 V_77 , bool V_71 ,
const T_5 V_98 , struct V_5 * V_6 , const T_4 V_99 ) {
const T_4 * V_47 = V_48 [ V_49 ] ;
T_4 V_33 = V_71 ? V_47 [ 1 ] : V_70 ;
if ( V_71 )
F_5 ( F_13 ( V_33 , V_72 , F_31 ( V_70 ) ) , V_6 ) ;
if ( V_98 ) {
F_29 ( V_47 [ 0 ] , V_98 , false , V_6 ) ;
F_5 ( F_36 ( V_47 [ 0 ] , V_33 , V_47 [ 0 ] ) , V_6 ) ;
V_33 = V_47 [ 0 ] ;
}
switch ( V_99 ) {
case V_100 :
F_5 ( F_30 ( V_77 , V_33 , 0 ) , V_6 ) ;
break;
case V_101 :
F_5 ( F_75 ( V_77 , V_33 , 0 ) , V_6 ) ;
break;
case V_102 :
F_5 ( F_76 ( V_77 , V_33 , 0 ) , V_6 ) ;
break;
}
}
static inline void F_77 ( const T_4 V_70 , const T_4 V_77 , bool V_71 ,
const T_5 V_98 , struct V_5 * V_6 , const T_4 V_99 ) {
const T_4 * V_47 = V_48 [ V_49 ] ;
T_4 V_33 = V_71 ? V_47 [ 1 ] : V_70 ;
T_4 V_44 = V_77 ;
if ( V_98 ) {
F_29 ( V_47 [ 0 ] , V_98 , false , V_6 ) ;
F_5 ( F_36 ( V_47 [ 0 ] , V_47 [ 0 ] , V_77 ) , V_6 ) ;
V_44 = V_47 [ 0 ] ;
}
switch ( V_99 ) {
case V_100 :
F_5 ( F_13 ( V_33 , V_44 , 0 ) , V_6 ) ;
break;
case V_101 :
F_5 ( F_78 ( V_33 , V_44 , 0 ) , V_6 ) ;
break;
case V_102 :
F_5 ( F_79 ( V_33 , V_44 , 0 ) , V_6 ) ;
break;
}
if ( V_71 )
F_5 ( F_30 ( V_33 , V_72 , F_31 ( V_70 ) ) , V_6 ) ;
}
static inline void F_80 ( const T_4 V_33 , const T_4 V_91 , const T_4 V_44 ,
const T_4 V_45 , struct V_5 * V_6 , T_4 V_46 ) {
switch ( V_46 ) {
case V_103 :
V_6 -> V_39 |= V_40 ;
F_5 ( F_44 ( V_55 , V_91 , V_45 ) , V_6 ) ;
F_5 ( F_44 ( V_41 , V_33 , V_44 ) , V_6 ) ;
F_5 ( F_81 ( V_55 , V_41 , V_55 ) , V_6 ) ;
break;
case V_104 :
case V_105 :
case V_106 :
case V_107 :
case V_108 :
case V_109 :
F_5 ( F_82 ( V_33 , V_44 ) , V_6 ) ;
F_3 ( V_51 , F_82 ( V_91 , V_45 ) , V_6 ) ;
break;
case V_110 :
case V_111 :
F_5 ( F_82 ( V_45 , V_91 ) , V_6 ) ;
F_5 ( F_83 ( V_55 , V_44 , V_33 ) , V_6 ) ;
break;
case V_112 :
case V_113 :
F_5 ( F_82 ( V_91 , V_45 ) , V_6 ) ;
F_5 ( F_83 ( V_55 , V_33 , V_44 ) , V_6 ) ;
break;
}
}
static int F_84 ( struct V_5 * V_6 )
{
const T_4 * V_114 = V_48 [ V_67 ] ;
const T_4 * V_115 = V_48 [ V_60 ] ;
const T_4 * V_47 = V_48 [ V_49 ] ;
const T_4 * V_93 = V_48 [ V_94 ] ;
const T_4 * V_116 = V_48 [ V_66 ] ;
const int V_117 = V_6 -> V_8 ;
#define F_85 (ctx->idx - idx0)
#define V_50 (out_offset - (cur_offset))
T_1 V_98 , V_118 , V_74 ;
V_98 = F_86 ( struct V_119 , V_120 . V_121 ) ;
F_29 ( V_47 [ 1 ] , V_98 , false , V_6 ) ;
F_5 ( F_13 ( V_93 [ 1 ] , V_72 , F_31 ( V_114 [ 1 ] ) ) , V_6 ) ;
F_5 ( F_87 ( V_47 [ 1 ] , V_93 [ 1 ] , V_47 [ 1 ] ) , V_6 ) ;
F_5 ( F_13 ( V_93 [ 1 ] , V_72 , F_31 ( V_115 [ 1 ] ) ) , V_6 ) ;
F_5 ( F_82 ( V_93 [ 1 ] , V_47 [ 1 ] ) , V_6 ) ;
F_3 ( V_122 , F_25 ( V_50 ) , V_6 ) ;
V_118 = ( T_1 ) V_123 ;
V_74 = ( T_1 ) ( ( V_124 ) V_123 >> 32 ) ;
F_5 ( F_13 ( V_47 [ 1 ] , V_72 , F_31 ( V_116 [ 1 ] ) ) , V_6 ) ;
F_5 ( F_13 ( V_47 [ 0 ] , V_72 , F_31 ( V_116 [ 0 ] ) ) , V_6 ) ;
F_5 ( F_24 ( V_47 [ 0 ] , V_74 ) , V_6 ) ;
F_3 ( V_51 , F_24 ( V_47 [ 1 ] , V_118 ) , V_6 ) ;
F_3 ( V_125 , F_25 ( V_50 ) , V_6 ) ;
F_5 ( F_88 ( V_47 [ 1 ] , V_47 [ 1 ] , 1 ) , V_6 ) ;
F_5 ( F_89 ( V_47 [ 0 ] , V_47 [ 0 ] , 0 ) , V_6 ) ;
F_5 ( F_30 ( V_47 [ 1 ] , V_72 , F_31 ( V_116 [ 1 ] ) ) , V_6 ) ;
F_5 ( F_30 ( V_47 [ 0 ] , V_72 , F_31 ( V_116 [ 0 ] ) ) , V_6 ) ;
V_98 = F_86 ( struct V_119 , V_126 ) ;
F_29 ( V_47 [ 1 ] , V_98 , false , V_6 ) ;
F_5 ( F_13 ( V_93 [ 1 ] , V_72 , F_31 ( V_114 [ 1 ] ) ) , V_6 ) ;
F_5 ( F_36 ( V_47 [ 1 ] , V_93 [ 1 ] , V_47 [ 1 ] ) , V_6 ) ;
F_5 ( F_13 ( V_93 [ 1 ] , V_72 , F_31 ( V_115 [ 1 ] ) ) , V_6 ) ;
F_5 ( F_68 ( V_47 [ 0 ] , V_93 [ 1 ] , V_95 , 2 ) , V_6 ) ;
F_5 ( F_87 ( V_47 [ 1 ] , V_47 [ 1 ] , V_47 [ 0 ] ) , V_6 ) ;
F_5 ( F_24 ( V_47 [ 1 ] , 0 ) , V_6 ) ;
F_3 ( V_51 , F_25 ( V_50 ) , V_6 ) ;
V_98 = F_86 ( struct V_127 , V_128 ) ;
F_29 ( V_93 [ 1 ] , V_98 , false , V_6 ) ;
F_5 ( F_87 ( V_47 [ 1 ] , V_47 [ 1 ] , V_93 [ 1 ] ) , V_6 ) ;
F_5 ( F_90 ( V_47 [ 1 ] , V_47 [ 1 ] , V_6 -> V_25 ) , V_6 ) ;
F_5 ( F_20 ( V_47 [ 1 ] ) , V_6 ) ;
if ( V_129 == - 1 )
V_129 = F_85 ;
if ( F_85 != V_129 ) {
F_91 ( L_1 ,
F_85 , V_129 ) ;
return - 1 ;
}
return 0 ;
#undef F_85
#undef V_50
}
static inline void F_92 ( const T_4 V_33 , const T_4 V_45 , struct V_5 * V_6 )
{
#if V_35 < 6
const T_4 * V_93 = V_48 [ V_94 ] ;
F_5 ( F_93 ( V_93 [ 1 ] , V_45 , 0xff ) , V_6 ) ;
F_5 ( F_68 ( V_93 [ 0 ] , V_45 , V_96 , 8 ) , V_6 ) ;
F_5 ( F_93 ( V_93 [ 0 ] , V_93 [ 0 ] , 0xff ) , V_6 ) ;
F_5 ( F_69 ( V_33 , V_93 [ 0 ] , V_93 [ 1 ] , V_130 , 8 ) , V_6 ) ;
#else
F_5 ( F_94 ( V_33 , V_45 ) , V_6 ) ;
#endif
}
static inline void F_95 ( const T_4 V_33 , const T_4 V_45 , struct V_5 * V_6 )
{
#if V_35 < 6
const T_4 * V_93 = V_48 [ V_94 ] ;
F_5 ( F_93 ( V_93 [ 1 ] , V_45 , 0xff ) , V_6 ) ;
F_5 ( F_68 ( V_93 [ 0 ] , V_45 , V_96 , 24 ) , V_6 ) ;
F_5 ( F_69 ( V_55 , V_93 [ 0 ] , V_93 [ 1 ] , V_130 , 24 ) , V_6 ) ;
F_5 ( F_68 ( V_93 [ 1 ] , V_45 , V_96 , 8 ) , V_6 ) ;
F_5 ( F_93 ( V_93 [ 1 ] , V_93 [ 1 ] , 0xff ) , V_6 ) ;
F_5 ( F_68 ( V_93 [ 0 ] , V_45 , V_96 , 16 ) , V_6 ) ;
F_5 ( F_93 ( V_93 [ 0 ] , V_93 [ 0 ] , 0xff ) , V_6 ) ;
F_5 ( F_68 ( V_93 [ 0 ] , V_93 [ 0 ] , V_130 , 8 ) , V_6 ) ;
F_5 ( F_69 ( V_93 [ 0 ] , V_93 [ 0 ] , V_93 [ 1 ] , V_130 , 16 ) , V_6 ) ;
F_5 ( F_43 ( V_33 , V_55 , V_93 [ 0 ] ) , V_6 ) ;
#else
F_5 ( F_96 ( V_33 , V_45 ) , V_6 ) ;
#endif
}
static inline void F_97 ( const T_4 V_77 [] , const T_4 V_131 ,
struct V_5 * V_6 )
{
const T_4 * V_93 = V_48 [ V_94 ] ;
T_3 V_132 = 0 ;
F_5 ( F_13 ( V_93 [ 1 ] , V_72 , F_31 ( V_77 [ 1 ] + V_131 ) ) , V_6 ) ;
F_5 ( F_13 ( V_93 [ 0 ] , V_72 , F_31 ( V_77 [ 0 ] + V_131 ) ) , V_6 ) ;
V_132 = ( 1 << V_93 [ 1 ] ) | ( 1 << V_93 [ 0 ] ) ;
F_5 ( F_98 ( V_132 ) , V_6 ) ;
}
static void F_99 ( struct V_5 * V_6 )
{
const T_4 V_133 = V_48 [ V_134 ] [ 1 ] ;
const T_4 V_114 = V_48 [ V_135 ] [ 1 ] ;
const T_4 V_115 = V_48 [ V_135 ] [ 0 ] ;
const T_4 V_136 = V_48 [ V_137 ] [ 1 ] ;
const T_4 V_138 = V_48 [ V_137 ] [ 0 ] ;
const T_4 V_139 = V_48 [ V_49 ] [ 1 ] ;
const T_4 V_140 = V_48 [ V_49 ] [ 0 ] ;
const T_4 V_141 = V_48 [ V_94 ] [ 1 ] ;
const T_4 V_142 = V_48 [ V_94 ] [ 0 ] ;
const T_4 V_143 = V_48 [ V_68 ] [ 1 ] ;
const T_4 V_144 = V_48 [ V_68 ] [ 0 ] ;
const T_4 V_145 = V_72 ;
const T_4 * V_116 = V_48 [ V_66 ] ;
T_3 V_132 = 0 ;
V_132 |= ( 1 << V_136 ) | ( 1 << V_138 ) | ( 1 << V_139 ) | ( 1 << V_140 ) | ( 1 << V_141 ) | ( 1 << V_142 ) ;
#ifdef F_100
V_132 |= ( 1 << V_146 ) | ( 1 << V_55 ) | ( 1 << V_41 ) | ( 1 << V_36 ) ;
F_5 ( F_19 ( V_55 , V_145 ) , V_6 ) ;
F_5 ( F_98 ( V_132 ) , V_6 ) ;
F_5 ( F_62 ( V_146 , V_55 , 4 ) , V_6 ) ;
#else
if ( V_6 -> V_39 & V_40 )
V_132 |= ( 1 << V_41 ) ;
F_5 ( F_98 ( V_132 ) , V_6 ) ;
#endif
F_5 ( F_62 ( V_55 , V_145 , V_147 ) , V_6 ) ;
V_6 -> V_148 = F_6 ( V_149 ) ;
F_5 ( F_62 ( V_72 , V_72 , V_6 -> V_148 ) , V_6 ) ;
F_52 ( V_143 , V_55 , true , false , V_6 ) ;
F_29 ( V_144 , 0 , true , V_6 ) ;
F_5 ( F_17 ( V_136 , 0 ) , V_6 ) ;
F_5 ( F_19 ( V_115 , V_136 ) , V_6 ) ;
F_5 ( F_19 ( V_114 , V_133 ) , V_6 ) ;
F_5 ( F_30 ( V_136 , V_72 , F_31 ( V_116 [ 0 ] ) ) , V_6 ) ;
F_5 ( F_30 ( V_136 , V_72 , F_31 ( V_116 [ 1 ] ) ) , V_6 ) ;
}
static void F_101 ( struct V_5 * V_6 )
{
const T_4 V_136 = V_48 [ V_137 ] [ 1 ] ;
const T_4 V_138 = V_48 [ V_137 ] [ 0 ] ;
const T_4 V_139 = V_48 [ V_49 ] [ 1 ] ;
const T_4 V_140 = V_48 [ V_49 ] [ 0 ] ;
const T_4 V_141 = V_48 [ V_94 ] [ 1 ] ;
const T_4 V_142 = V_48 [ V_94 ] [ 0 ] ;
T_3 V_132 = 0 ;
F_5 ( F_90 ( V_72 , V_72 , V_6 -> V_148 ) , V_6 ) ;
V_132 |= ( 1 << V_136 ) | ( 1 << V_138 ) | ( 1 << V_139 ) | ( 1 << V_140 ) | ( 1 << V_141 ) | ( 1 << V_142 ) ;
#ifdef F_100
V_132 |= ( 1 << V_146 ) | ( 1 << V_72 ) | ( 1 << V_36 ) ;
F_5 ( F_102 ( V_72 , V_132 ) , V_6 ) ;
#else
if ( V_6 -> V_39 & V_40 )
V_132 |= ( 1 << V_36 ) ;
F_5 ( F_103 ( V_132 ) , V_6 ) ;
if ( ! ( V_6 -> V_39 & V_40 ) )
F_5 ( F_20 ( V_41 ) , V_6 ) ;
#endif
}
static int F_104 ( const struct V_150 * V_151 , struct V_5 * V_6 )
{
const T_4 V_152 = V_151 -> V_152 ;
const T_4 * V_70 = V_48 [ V_151 -> V_153 ] ;
const T_4 * V_77 = V_48 [ V_151 -> V_154 ] ;
const T_4 * V_47 = V_48 [ V_49 ] ;
const T_4 * V_93 = V_48 [ V_94 ] ;
const T_6 V_98 = V_151 -> V_98 ;
const T_5 V_19 = V_151 -> V_19 ;
const int V_17 = V_151 - V_6 -> V_23 -> V_155 ;
const bool V_73 = F_105 ( V_152 ) == V_156 ;
const bool V_71 = F_28 ( V_151 -> V_153 ) ;
const bool V_88 = F_28 ( V_151 -> V_154 ) ;
T_4 V_33 , V_91 , V_44 , V_45 ;
T_5 V_50 ;
#define F_106 ( T_7 , V_19 ) do { \
if ((((imm) > 0) && ((imm) >> (bits))) || \
(((imm) < 0) && (~(imm) >> (bits)))) { \
pr_info("[%2d] imm=%d(0x%x) out of range\n", \
i, imm, imm); \
return -EINVAL; \
} \
} while (0)
#define F_107 ( V_19 ) check_imm(24, imm)
switch ( V_152 ) {
case V_157 | V_158 | V_159 :
case V_157 | V_158 | V_160 :
case V_156 | V_158 | V_159 :
case V_156 | V_158 | V_160 :
switch ( F_108 ( V_152 ) ) {
case V_160 :
F_53 ( V_73 , V_70 , V_77 , V_71 , V_88 , V_6 ) ;
break;
case V_159 :
F_32 ( V_73 , V_70 , V_19 , V_71 , V_6 ) ;
break;
}
break;
case V_157 | V_78 | V_159 :
case V_157 | V_78 | V_160 :
case V_157 | V_79 | V_159 :
case V_157 | V_79 | V_160 :
case V_157 | V_80 | V_159 :
case V_157 | V_80 | V_160 :
case V_157 | V_81 | V_159 :
case V_157 | V_81 | V_160 :
case V_157 | V_82 | V_159 :
case V_157 | V_82 | V_160 :
case V_157 | V_83 | V_159 :
case V_157 | V_83 | V_160 :
case V_157 | V_84 | V_160 :
case V_157 | V_85 | V_160 :
case V_157 | V_86 | V_159 :
case V_157 | V_86 | V_160 :
case V_156 | V_78 | V_159 :
case V_156 | V_78 | V_160 :
case V_156 | V_79 | V_159 :
case V_156 | V_79 | V_160 :
case V_156 | V_80 | V_159 :
case V_156 | V_80 | V_160 :
case V_156 | V_81 | V_159 :
case V_156 | V_81 | V_160 :
case V_156 | V_82 | V_159 :
case V_156 | V_82 | V_160 :
switch ( F_108 ( V_152 ) ) {
case V_160 :
F_51 ( V_73 , V_70 , V_77 , V_71 , V_88 ,
V_6 , F_42 ( V_152 ) ) ;
break;
case V_159 :
F_32 ( V_73 , V_93 , V_19 , false , V_6 ) ;
F_51 ( V_73 , V_70 , V_93 , V_71 , false ,
V_6 , F_42 ( V_152 ) ) ;
break;
}
break;
case V_157 | V_54 | V_159 :
case V_157 | V_54 | V_160 :
case V_157 | V_161 | V_159 :
case V_157 | V_161 | V_160 :
V_91 = V_89 ;
V_33 = V_71 ? V_93 [ 1 ] : V_75 ;
if ( V_71 )
F_5 ( F_13 ( V_33 , V_72 , F_31 ( V_75 ) ) , V_6 ) ;
switch ( F_108 ( V_152 ) ) {
case V_160 :
V_91 = V_88 ? V_93 [ 0 ] : V_91 ;
if ( V_88 )
F_5 ( F_13 ( V_91 , V_72 , F_31 ( V_89 ) ) ,
V_6 ) ;
break;
case V_159 :
V_91 = V_93 [ 0 ] ;
F_29 ( V_91 , V_19 , false , V_6 ) ;
break;
}
F_23 ( V_33 , V_33 , V_91 , V_6 , F_42 ( V_152 ) ) ;
if ( V_71 )
F_5 ( F_30 ( V_33 , V_72 , F_31 ( V_75 ) ) , V_6 ) ;
F_29 ( V_76 , 0 , V_71 , V_6 ) ;
break;
case V_156 | V_54 | V_159 :
case V_156 | V_54 | V_160 :
case V_156 | V_161 | V_159 :
case V_156 | V_161 | V_160 :
goto V_162;
case V_157 | V_85 | V_159 :
case V_157 | V_84 | V_159 :
if ( F_109 ( V_19 > 31 ) )
return - V_163 ;
if ( V_19 )
F_54 ( V_75 , V_19 , V_71 , V_6 , F_42 ( V_152 ) ) ;
F_29 ( V_76 , 0 , V_71 , V_6 ) ;
break;
case V_156 | V_84 | V_159 :
if ( F_109 ( V_19 > 63 ) )
return - V_163 ;
F_67 ( V_70 , V_71 , V_19 , V_6 ) ;
break;
case V_156 | V_85 | V_159 :
if ( F_109 ( V_19 > 63 ) )
return - V_163 ;
F_70 ( V_70 , V_71 , V_19 , V_6 ) ;
break;
case V_156 | V_84 | V_160 :
F_61 ( V_70 , V_77 , V_71 , V_88 , V_6 ) ;
break;
case V_156 | V_85 | V_160 :
F_66 ( V_70 , V_77 , V_71 , V_88 , V_6 ) ;
break;
case V_156 | V_86 | V_160 :
F_64 ( V_70 , V_77 , V_71 , V_88 , V_6 ) ;
break;
case V_156 | V_86 | V_159 :
if ( F_109 ( V_19 > 63 ) )
return - V_163 ;
F_71 ( V_70 , V_71 , V_19 , V_6 ) ;
break;
case V_157 | V_92 :
F_54 ( V_75 , 0 , V_71 , V_6 , F_42 ( V_152 ) ) ;
F_29 ( V_76 , 0 , V_71 , V_6 ) ;
break;
case V_156 | V_92 :
F_58 ( V_70 , V_71 , V_6 ) ;
break;
case V_156 | V_83 | V_160 :
case V_156 | V_83 | V_159 :
switch ( F_108 ( V_152 ) ) {
case V_160 :
F_72 ( V_70 , V_77 , V_71 , V_88 , V_6 ) ;
break;
case V_159 :
F_32 ( V_73 , V_93 , V_19 , false , V_6 ) ;
F_72 ( V_70 , V_93 , V_71 , false , V_6 ) ;
break;
}
break;
case V_157 | V_164 | V_165 :
case V_157 | V_164 | V_166 :
V_33 = V_71 ? V_47 [ 0 ] : V_76 ;
V_91 = V_71 ? V_47 [ 1 ] : V_75 ;
if ( V_71 ) {
F_5 ( F_13 ( V_91 , V_72 , F_31 ( V_75 ) ) , V_6 ) ;
F_5 ( F_13 ( V_33 , V_72 , F_31 ( V_76 ) ) , V_6 ) ;
}
if ( F_108 ( V_152 ) == V_165 )
goto V_167;
switch ( V_19 ) {
case 16 :
F_92 ( V_91 , V_91 , V_6 ) ;
goto V_167;
case 32 :
F_95 ( V_91 , V_91 , V_6 ) ;
goto V_167;
case 64 :
V_6 -> V_39 |= V_40 ;
F_95 ( V_41 , V_91 , V_6 ) ;
F_95 ( V_91 , V_33 , V_6 ) ;
F_5 ( F_19 ( V_33 , V_41 ) , V_6 ) ;
break;
}
goto exit;
V_167:
switch ( V_19 ) {
case 16 :
#if V_35 < 6
F_29 ( V_93 [ 1 ] , 0xffff , false , V_6 ) ;
F_5 ( F_44 ( V_91 , V_91 , V_93 [ 1 ] ) , V_6 ) ;
#else
F_5 ( F_110 ( V_91 , V_91 ) , V_6 ) ;
#endif
F_5 ( F_45 ( V_33 , V_33 , V_33 ) , V_6 ) ;
break;
case 32 :
F_5 ( F_45 ( V_33 , V_33 , V_33 ) , V_6 ) ;
break;
case 64 :
break;
}
exit:
if ( V_71 ) {
F_5 ( F_30 ( V_91 , V_72 , F_31 ( V_75 ) ) , V_6 ) ;
F_5 ( F_30 ( V_33 , V_72 , F_31 ( V_76 ) ) , V_6 ) ;
}
break;
case V_168 | V_169 | V_170 :
{
const struct V_150 V_171 = V_151 [ 1 ] ;
T_1 V_74 , V_118 = V_19 ;
V_74 = V_171 . V_19 ;
F_29 ( V_75 , V_118 , V_71 , V_6 ) ;
F_29 ( V_76 , V_74 , V_71 , V_6 ) ;
return 1 ;
}
case V_172 | V_173 | V_100 :
case V_172 | V_173 | V_101 :
case V_172 | V_173 | V_102 :
case V_172 | V_173 | V_170 :
V_45 = V_88 ? V_93 [ 1 ] : V_89 ;
if ( V_88 )
F_5 ( F_13 ( V_45 , V_72 , F_31 ( V_89 ) ) , V_6 ) ;
switch ( F_111 ( V_152 ) ) {
case V_100 :
case V_101 :
case V_102 :
F_77 ( V_75 , V_45 , V_71 , V_98 , V_6 , F_111 ( V_152 ) ) ;
F_29 ( V_76 , 0 , V_71 , V_6 ) ;
break;
case V_170 :
F_77 ( V_75 , V_45 , V_71 , V_98 , V_6 , V_100 ) ;
F_77 ( V_76 , V_45 , V_71 , V_98 + 4 , V_6 , V_100 ) ;
break;
}
break;
case V_168 | V_174 | V_100 :
case V_168 | V_174 | V_101 :
case V_168 | V_174 | V_102 :
case V_168 | V_175 | V_100 :
case V_168 | V_175 | V_101 :
case V_168 | V_175 | V_102 :
{
const T_4 V_136 = V_48 [ V_137 ] [ 1 ] ;
const T_4 V_133 = V_48 [ V_134 ] [ 1 ] ;
const T_4 V_176 = V_48 [ V_134 ] [ 0 ] ;
const T_4 V_114 = V_48 [ V_135 ] [ 1 ] ;
const T_4 V_115 = V_48 [ V_135 ] [ 0 ] ;
const T_4 V_139 = V_48 [ V_49 ] [ 1 ] ;
int V_13 ;
F_5 ( F_19 ( V_133 , V_136 ) , V_6 ) ;
F_29 ( V_176 , V_19 , false , V_6 ) ;
if ( F_112 ( V_152 ) == V_175 )
F_50 ( V_176 , V_89 , false , V_88 , V_6 ,
false , false , V_78 ) ;
switch ( F_111 ( V_152 ) ) {
case V_100 :
V_13 = 4 ;
break;
case V_101 :
V_13 = 2 ;
break;
case V_102 :
V_13 = 1 ;
break;
default:
return - V_163 ;
}
F_29 ( V_114 , V_13 , false , V_6 ) ;
F_5 ( F_90 ( V_115 , V_72 , F_6 ( V_177 ) ) , V_6 ) ;
F_29 ( V_139 , ( unsigned int ) V_178 , false , V_6 ) ;
F_18 ( V_139 , V_6 ) ;
F_5 ( F_45 ( V_176 , V_176 , V_176 ) , V_6 ) ;
F_5 ( F_24 ( V_133 , 0 ) , V_6 ) ;
V_50 = F_22 ( V_6 ) ;
F_107 ( V_50 ) ;
F_3 ( V_51 , F_25 ( V_50 ) , V_6 ) ;
switch ( F_111 ( V_152 ) ) {
case V_100 :
F_5 ( F_13 ( V_133 , V_133 , 0 ) , V_6 ) ;
F_95 ( V_133 , V_133 , V_6 ) ;
break;
case V_101 :
F_5 ( F_78 ( V_133 , V_133 , 0 ) , V_6 ) ;
F_92 ( V_133 , V_133 , V_6 ) ;
break;
case V_102 :
F_5 ( F_79 ( V_133 , V_133 , 0 ) , V_6 ) ;
break;
}
break;
}
case V_179 | V_173 | V_100 :
case V_179 | V_173 | V_101 :
case V_179 | V_173 | V_102 :
case V_179 | V_173 | V_170 :
switch ( F_111 ( V_152 ) ) {
case V_170 :
F_32 ( true , V_93 , V_19 , false , V_6 ) ;
F_74 ( V_75 , V_93 [ 1 ] , V_71 , V_98 , V_6 , V_100 ) ;
F_74 ( V_75 , V_93 [ 0 ] , V_71 , V_98 + 4 , V_6 , V_100 ) ;
break;
case V_100 :
case V_101 :
case V_102 :
F_29 ( V_93 [ 1 ] , V_19 , false , V_6 ) ;
F_74 ( V_75 , V_93 [ 1 ] , V_71 , V_98 , V_6 ,
F_111 ( V_152 ) ) ;
break;
}
break;
case V_180 | V_181 | V_100 :
case V_180 | V_181 | V_170 :
goto V_162;
case V_180 | V_173 | V_100 :
case V_180 | V_173 | V_101 :
case V_180 | V_173 | V_102 :
case V_180 | V_173 | V_170 :
{
T_4 V_99 = F_111 ( V_152 ) ;
V_45 = V_88 ? V_93 [ 1 ] : V_89 ;
V_44 = V_88 ? V_93 [ 0 ] : V_90 ;
if ( V_88 ) {
F_5 ( F_13 ( V_45 , V_72 , F_31 ( V_89 ) ) , V_6 ) ;
F_5 ( F_13 ( V_44 , V_72 , F_31 ( V_90 ) ) , V_6 ) ;
}
if ( F_111 ( V_152 ) == V_170 ) {
F_74 ( V_75 , V_45 , V_71 , V_98 , V_6 , V_100 ) ;
F_74 ( V_75 , V_44 , V_71 , V_98 + 4 , V_6 , V_100 ) ;
} else {
F_74 ( V_75 , V_45 , V_71 , V_98 , V_6 , V_99 ) ;
}
break;
}
case V_182 | V_104 | V_160 :
case V_182 | V_106 | V_160 :
case V_182 | V_107 | V_160 :
case V_182 | V_105 | V_160 :
case V_182 | V_111 | V_160 :
case V_182 | V_113 | V_160 :
case V_182 | V_103 | V_160 :
case V_182 | V_108 | V_160 :
case V_182 | V_109 | V_160 :
case V_182 | V_112 | V_160 :
case V_182 | V_110 | V_160 :
V_44 = V_88 ? V_93 [ 0 ] : V_90 ;
V_45 = V_88 ? V_93 [ 1 ] : V_89 ;
if ( V_88 ) {
F_5 ( F_13 ( V_45 , V_72 , F_31 ( V_89 ) ) , V_6 ) ;
F_5 ( F_13 ( V_44 , V_72 , F_31 ( V_90 ) ) , V_6 ) ;
}
goto V_183;
case V_182 | V_104 | V_159 :
case V_182 | V_106 | V_159 :
case V_182 | V_107 | V_159 :
case V_182 | V_105 | V_159 :
case V_182 | V_111 | V_159 :
case V_182 | V_113 | V_159 :
case V_182 | V_103 | V_159 :
case V_182 | V_109 | V_159 :
case V_182 | V_108 | V_159 :
case V_182 | V_112 | V_159 :
case V_182 | V_110 | V_159 :
if ( V_98 == 0 )
break;
V_44 = V_93 [ 0 ] ;
V_45 = V_93 [ 1 ] ;
F_32 ( true , V_93 , V_19 , false , V_6 ) ;
V_183:
V_33 = V_71 ? V_47 [ 0 ] : V_76 ;
V_91 = V_71 ? V_47 [ 1 ] : V_75 ;
if ( V_71 ) {
F_5 ( F_13 ( V_91 , V_72 , F_31 ( V_75 ) ) , V_6 ) ;
F_5 ( F_13 ( V_33 , V_72 , F_31 ( V_76 ) ) , V_6 ) ;
}
F_80 ( V_33 , V_91 , V_44 , V_45 , V_6 , F_42 ( V_152 ) ) ;
V_50 = F_11 ( V_17 + V_98 , V_17 , V_6 ) ;
switch ( F_42 ( V_152 ) ) {
case V_105 :
case V_103 :
F_3 ( V_184 , F_25 ( V_50 ) , V_6 ) ;
break;
case V_104 :
F_3 ( V_51 , F_25 ( V_50 ) , V_6 ) ;
break;
case V_106 :
F_3 ( V_125 , F_25 ( V_50 ) , V_6 ) ;
break;
case V_107 :
F_3 ( V_122 , F_25 ( V_50 ) , V_6 ) ;
break;
case V_111 :
F_3 ( V_185 , F_25 ( V_50 ) , V_6 ) ;
break;
case V_113 :
F_3 ( V_186 , F_25 ( V_50 ) , V_6 ) ;
break;
case V_108 :
F_3 ( V_187 , F_25 ( V_50 ) , V_6 ) ;
break;
case V_109 :
F_3 ( V_188 , F_25 ( V_50 ) , V_6 ) ;
break;
case V_112 :
F_3 ( V_185 , F_25 ( V_50 ) , V_6 ) ;
break;
case V_110 :
F_3 ( V_186 , F_25 ( V_50 ) , V_6 ) ;
break;
}
break;
case V_182 | V_189 :
{
if ( V_98 == 0 )
break;
V_50 = F_11 ( V_17 + V_98 , V_17 , V_6 ) ;
F_107 ( V_50 ) ;
F_5 ( F_25 ( V_50 ) , V_6 ) ;
break;
}
case V_182 | V_190 :
if ( F_84 ( V_6 ) )
return - V_191 ;
break;
case V_182 | V_192 :
{
const T_4 * V_133 = V_48 [ V_134 ] ;
const T_4 * V_176 = V_48 [ V_135 ] ;
const T_4 * V_114 = V_48 [ V_67 ] ;
const T_4 * V_115 = V_48 [ V_60 ] ;
const T_4 * V_136 = V_48 [ V_61 ] ;
const T_4 * V_138 = V_48 [ V_62 ] ;
const T_1 V_193 = ( T_1 ) V_194 + ( T_1 ) V_19 ;
F_53 ( true , V_133 , V_176 , false , false , V_6 ) ;
F_53 ( true , V_176 , V_114 , false , true , V_6 ) ;
F_97 ( V_138 , 0 , V_6 ) ;
F_97 ( V_136 , 8 , V_6 ) ;
F_97 ( V_115 , 16 , V_6 ) ;
F_29 ( V_47 [ 1 ] , V_193 , false , V_6 ) ;
F_18 ( V_47 [ 1 ] , V_6 ) ;
F_5 ( F_90 ( V_72 , V_72 , F_6 ( 24 ) ) , V_6 ) ;
break;
}
case V_182 | V_195 :
if ( V_17 == V_6 -> V_23 -> V_24 - 1 )
break;
V_50 = F_22 ( V_6 ) ;
F_107 ( V_50 ) ;
F_5 ( F_25 ( V_50 ) , V_6 ) ;
break;
V_162:
F_113 ( L_2 , V_152 ) ;
return - V_191 ;
default:
F_91 ( L_3 , V_152 ) ;
return - V_163 ;
}
if ( V_6 -> V_27 & V_28 )
return - 1 ;
return 0 ;
}
static int F_114 ( struct V_5 * V_6 )
{
const struct V_127 * V_23 = V_6 -> V_23 ;
unsigned int V_17 ;
for ( V_17 = 0 ; V_17 < V_23 -> V_24 ; V_17 ++ ) {
const struct V_150 * V_151 = & ( V_23 -> V_155 [ V_17 ] ) ;
int V_196 ;
V_196 = F_104 ( V_151 , V_6 ) ;
if ( V_196 > 0 ) {
V_17 ++ ;
if ( V_6 -> V_7 == NULL )
V_6 -> V_22 [ V_17 ] = V_6 -> V_8 ;
continue;
}
if ( V_6 -> V_7 == NULL )
V_6 -> V_22 [ V_17 ] = V_6 -> V_8 ;
if ( V_196 )
return V_196 ;
}
return 0 ;
}
static int F_115 ( struct V_5 * V_6 )
{
int V_17 ;
for ( V_17 = 0 ; V_17 < V_6 -> V_8 ; V_17 ++ ) {
if ( V_6 -> V_7 [ V_17 ] == F_4 ( V_15 ) )
return - 1 ;
}
return 0 ;
}
void F_116 ( struct V_127 * V_23 )
{
}
struct V_127 * F_117 ( struct V_127 * V_23 )
{
struct V_127 * V_47 , * V_197 = V_23 ;
struct V_198 * V_199 ;
bool V_200 = false ;
struct V_5 V_6 ;
unsigned int V_201 ;
unsigned int V_202 ;
T_4 * V_203 ;
if ( ! V_204 )
return V_197 ;
V_47 = F_118 ( V_23 ) ;
if ( F_119 ( V_47 ) )
return V_197 ;
if ( V_47 != V_23 ) {
V_200 = true ;
V_23 = V_47 ;
}
memset ( & V_6 , 0 , sizeof( V_6 ) ) ;
V_6 . V_23 = V_23 ;
V_6 . V_22 = F_120 ( V_23 -> V_24 , sizeof( int ) , V_205 ) ;
if ( V_6 . V_22 == NULL ) {
V_23 = V_197 ;
goto V_206;
}
if ( F_114 ( & V_6 ) ) {
V_23 = V_197 ;
goto V_207;
}
V_201 = V_6 . V_8 ;
F_99 ( & V_6 ) ;
V_6 . V_25 = ( V_6 . V_8 - V_201 ) * 4 ;
V_6 . F_22 = V_6 . V_8 ;
#if V_35 < 7
V_201 = V_6 . V_8 ;
F_101 ( & V_6 ) ;
V_6 . V_26 = ( V_6 . V_8 - V_201 ) * 4 ;
V_6 . V_8 += V_6 . V_20 ;
if ( V_6 . V_20 ) {
V_6 . V_21 = F_120 ( V_6 . V_20 , sizeof( T_1 ) , V_205 ) ;
if ( V_6 . V_21 == NULL ) {
V_23 = V_197 ;
goto V_207;
}
}
#else
F_101 ( & V_6 ) ;
#endif
V_202 = sizeof( T_1 ) * V_6 . V_8 ;
V_199 = F_121 ( V_202 , & V_203 ,
sizeof( T_1 ) , F_9 ) ;
if ( V_199 == NULL ) {
V_23 = V_197 ;
goto V_208;
}
V_6 . V_7 = ( T_1 * ) V_203 ;
V_6 . V_8 = 0 ;
F_99 ( & V_6 ) ;
if ( F_114 ( & V_6 ) < 0 ) {
V_203 = NULL ;
F_122 ( V_199 ) ;
V_23 = V_197 ;
goto V_208;
}
F_101 ( & V_6 ) ;
if ( F_115 ( & V_6 ) ) {
V_203 = NULL ;
F_122 ( V_199 ) ;
V_23 = V_197 ;
goto V_208;
}
F_123 ( ( T_1 ) V_199 , ( T_1 ) ( V_6 . V_7 + V_6 . V_8 ) ) ;
if ( V_204 > 1 )
F_124 ( V_23 -> V_24 , V_202 , 2 , V_6 . V_7 ) ;
F_125 ( ( unsigned long ) V_199 , V_199 -> V_209 ) ;
V_23 -> V_128 = ( void * ) V_6 . V_7 ;
V_23 -> V_210 = 1 ;
V_23 -> V_211 = V_202 ;
V_208:
#if V_35 < 7
if ( V_6 . V_20 )
F_126 ( V_6 . V_21 ) ;
#endif
V_207:
F_126 ( V_6 . V_22 ) ;
V_206:
if ( V_200 )
F_127 ( V_23 , V_23 == V_197 ?
V_47 : V_197 ) ;
return V_23 ;
}
