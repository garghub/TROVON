static int F_1 ( const char * V_1 , const char * V_2 )
{
int V_3 = strlen ( V_1 ) ;
if ( V_3 > strlen ( V_2 ) )
return - 1 ;
return memcmp ( V_2 , V_1 , V_3 ) ;
}
static void F_2 ( const T_1 * V_4 , T_2 V_3 )
{
int V_5 ;
F_3 ( L_1 , 0 ) ;
for ( V_5 = 0 ; V_5 < V_3 ; V_5 ++ ) {
if ( V_5 && ! ( V_5 % 16 ) )
F_3 ( L_2 , V_5 ) ;
F_3 ( L_3 , V_4 [ V_5 ] ) ;
}
F_3 ( L_4 ) ;
}
static bool F_4 ( void )
{
if ( V_6 == 0 )
F_3 ( L_5 ) ;
return V_6 > 0 ;
}
static void F_5 ( const struct V_7 V_8 , unsigned int V_5 )
{
const char * V_9 , * V_10 ;
int V_11 = V_8 . V_12 ;
char V_4 [ 256 ] ;
switch ( V_8 . V_13 ) {
case V_14 | V_15 :
V_9 = V_16 [ V_14 ] ;
V_10 = L_6 ;
break;
case V_14 | V_17 :
V_9 = V_16 [ V_14 ] ;
V_10 = L_7 ;
break;
case V_14 | V_18 :
V_9 = V_16 [ V_14 ] ;
V_10 = L_8 ;
break;
case V_19 :
V_9 = V_16 [ V_19 ] ;
V_10 = L_9 ;
break;
case V_20 :
V_9 = V_16 [ V_20 ] ;
V_10 = L_9 ;
break;
case V_21 :
V_9 = V_16 [ V_21 ] ;
V_10 = L_10 ;
break;
case V_22 :
V_9 = V_16 [ V_22 ] ;
V_10 = L_10 ;
break;
case V_23 | V_24 :
V_9 = V_16 [ V_23 ] ;
V_10 = L_11 ;
break;
case V_25 | V_24 :
V_9 = V_16 [ V_25 ] ;
V_10 = L_11 ;
break;
case V_26 | V_24 :
V_9 = V_16 [ V_26 ] ;
V_10 = L_11 ;
break;
case V_23 | V_27 :
V_9 = V_16 [ V_23 ] ;
V_10 = L_12 ;
break;
case V_23 | V_28 :
V_9 = V_16 [ V_23 ] ;
V_10 = L_13 ;
break;
case V_25 | V_28 :
V_9 = V_16 [ V_25 ] ;
V_10 = L_13 ;
break;
case V_26 | V_28 :
V_9 = V_16 [ V_26 ] ;
V_10 = L_13 ;
break;
case V_29 | V_30 :
V_9 = V_16 [ V_23 ] ;
V_10 = L_6 ;
break;
case V_31 | V_30 :
V_9 = V_16 [ V_31 ] ;
V_10 = L_6 ;
break;
case V_32 | V_33 :
V_9 = V_16 [ V_32 ] ;
V_10 = L_14 ;
break;
case V_29 | V_34 :
V_9 = V_16 [ V_23 ] ;
V_10 = L_10 ;
break;
case V_31 | V_34 :
V_9 = V_16 [ V_31 ] ;
V_10 = L_10 ;
break;
case V_35 :
V_9 = V_16 [ V_35 ] ;
V_10 = L_15 ;
V_11 = V_5 + 1 + V_8 . V_12 ;
break;
case V_36 | V_18 :
V_9 = V_16 [ V_36 ] ;
V_10 = L_8 ;
break;
case V_36 | V_15 :
V_9 = V_16 [ V_36 ] ;
V_10 = L_6 ;
break;
case V_37 | V_18 :
V_9 = V_16 [ V_37 ] ;
V_10 = L_8 ;
break;
case V_37 | V_15 :
V_9 = V_16 [ V_37 ] ;
V_10 = L_6 ;
break;
case V_38 | V_18 :
V_9 = V_16 [ V_38 ] ;
V_10 = L_8 ;
break;
case V_38 | V_15 :
V_9 = V_16 [ V_38 ] ;
V_10 = L_6 ;
break;
case V_39 | V_18 :
V_9 = V_16 [ V_39 ] ;
V_10 = L_8 ;
break;
case V_39 | V_15 :
V_9 = V_16 [ V_39 ] ;
V_10 = L_6 ;
break;
case V_40 :
V_9 = V_16 [ V_40 ] ;
V_10 = L_9 ;
break;
case V_41 | V_18 :
V_9 = V_16 [ V_41 ] ;
V_10 = L_8 ;
break;
case V_41 | V_15 :
V_9 = V_16 [ V_41 ] ;
V_10 = L_16 ;
break;
case V_42 | V_18 :
V_9 = V_16 [ V_42 ] ;
V_10 = L_8 ;
break;
case V_42 | V_15 :
V_9 = V_16 [ V_42 ] ;
V_10 = L_16 ;
break;
case V_43 | V_18 :
V_9 = V_16 [ V_43 ] ;
V_10 = L_8 ;
break;
case V_43 | V_15 :
V_9 = V_16 [ V_43 ] ;
V_10 = L_16 ;
break;
case V_44 | V_18 :
V_9 = V_16 [ V_44 ] ;
V_10 = L_8 ;
break;
case V_44 | V_15 :
V_9 = V_16 [ V_44 ] ;
V_10 = L_16 ;
break;
case V_45 | V_18 :
V_9 = V_16 [ V_45 ] ;
V_10 = L_8 ;
break;
case V_45 | V_15 :
V_9 = V_16 [ V_45 ] ;
V_10 = L_16 ;
break;
case V_46 | V_18 :
V_9 = V_16 [ V_46 ] ;
V_10 = L_8 ;
break;
case V_46 | V_15 :
V_9 = V_16 [ V_46 ] ;
V_10 = L_16 ;
break;
case V_47 | V_18 :
V_9 = V_16 [ V_47 ] ;
V_10 = L_8 ;
break;
case V_47 | V_15 :
V_9 = V_16 [ V_47 ] ;
V_10 = L_16 ;
break;
case V_48 | V_18 :
V_9 = V_16 [ V_48 ] ;
V_10 = L_8 ;
break;
case V_48 | V_15 :
V_9 = V_16 [ V_48 ] ;
V_10 = L_6 ;
break;
case V_49 | V_18 :
V_9 = V_16 [ V_49 ] ;
V_10 = L_8 ;
break;
case V_49 | V_15 :
V_9 = V_16 [ V_49 ] ;
V_10 = L_6 ;
break;
case V_50 | V_18 :
V_9 = V_16 [ V_50 ] ;
V_10 = L_8 ;
break;
case V_50 | V_15 :
V_9 = V_16 [ V_50 ] ;
V_10 = L_6 ;
break;
default:
V_9 = L_17 ;
V_10 = L_18 ;
V_11 = V_8 . V_13 ;
break;
}
memset ( V_4 , 0 , sizeof( V_4 ) ) ;
snprintf ( V_4 , sizeof( V_4 ) , V_10 , V_11 ) ;
V_4 [ sizeof( V_4 ) - 1 ] = 0 ;
if ( ( F_6 ( V_8 . V_13 ) == V_51 && F_7 ( V_8 . V_13 ) != V_52 ) )
F_3 ( L_19 , V_5 , V_9 , V_4 ,
V_5 + 1 + V_8 . V_53 , V_5 + 1 + V_8 . V_54 ) ;
else
F_3 ( L_20 , V_5 , V_9 , V_4 ) ;
}
static void F_8 ( struct V_55 * V_56 , struct V_7 * V_8 )
{
int V_5 , V_57 = 0 ;
F_3 ( L_21 , V_56 -> V_58 ) ;
F_3 ( L_22 ,
V_8 -> V_13 , V_8 -> V_53 , V_8 -> V_54 , V_8 -> V_12 ) ;
F_3 ( L_23 ) ;
F_5 ( * V_8 , V_56 -> V_58 ) ;
if ( V_8 -> V_53 || V_8 -> V_54 ) {
F_3 ( L_24 ) ;
F_5 ( * ( V_8 + V_8 -> V_53 + 1 ) , V_56 -> V_58 + V_8 -> V_53 + 1 ) ;
F_3 ( L_25 ) ;
F_5 ( * ( V_8 + V_8 -> V_54 + 1 ) , V_56 -> V_58 + V_8 -> V_54 + 1 ) ;
}
F_3 ( L_26 , V_56 -> V_59 , V_56 -> V_59 ) ;
F_3 ( L_27 , V_56 -> V_60 , V_56 -> V_60 ) ;
if ( V_56 -> V_61 )
F_3 ( L_28 , V_56 -> V_62 , V_56 -> V_62 ) ;
for ( V_5 = 0 ; V_5 < V_63 ; V_5 ++ ) {
if ( V_56 -> V_64 [ V_5 ] ) {
V_57 ++ ;
F_3 ( L_29 , V_5 , V_56 -> V_64 [ V_5 ] , V_56 -> V_64 [ V_5 ] ) ;
}
}
if ( V_57 == 0 )
F_3 ( L_30 , V_63 - 1 , 0 , 0 ) ;
}
static void F_9 ( T_1 * V_65 , T_3 V_66 , T_3 V_67 )
{
if ( V_66 != V_67 )
F_3 ( L_31 , V_66 , V_67 ) ;
else
F_3 ( L_32 , V_67 ) ;
F_2 ( V_65 , V_66 ) ;
}
static void F_10 ( const struct V_7 * V_8 , unsigned int V_3 )
{
unsigned int V_5 ;
for ( V_5 = 0 ; V_5 < V_3 ; V_5 ++ )
F_5 ( V_8 [ V_5 ] , V_5 ) ;
}
static void F_11 ( const struct V_7 * V_8 , unsigned int V_3 )
{
unsigned int V_5 ;
F_3 ( L_33 ) ;
for ( V_5 = 0 ; V_5 < V_3 ; V_5 ++ )
F_3 ( L_34 ,
V_8 [ V_5 ] . V_13 , V_8 [ V_5 ] . V_53 , V_8 [ V_5 ] . V_54 , V_8 [ V_5 ] . V_12 ) ;
}
static bool F_12 ( struct V_7 * V_8 , unsigned int V_3 )
{
int V_68 , V_69 , V_5 ;
struct V_70 V_71 = {
. V_72 = V_8 ,
. V_3 = V_3 ,
} ;
V_68 = F_13 ( V_73 , V_74 , 0 ) ;
if ( V_68 < 0 ) {
F_3 ( L_35 ) ;
return false ;
}
V_69 = F_14 ( V_68 , V_75 , V_76 , & V_71 , sizeof( V_71 ) ) ;
F_15 ( V_68 ) ;
if ( V_69 < 0 ) {
F_3 ( L_36 ) ;
return false ;
}
for ( V_5 = 0 ; V_5 < V_3 ; V_5 ++ ) {
if ( F_6 ( V_8 [ V_5 ] . V_13 ) == V_29 &&
V_8 [ V_5 ] . V_12 > V_77 ) {
F_3 ( L_37 ) ;
return false ;
}
}
return true ;
}
static void F_16 ( void )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < F_17 ( V_78 ) ; V_5 ++ )
V_78 [ V_5 ] = - 1 ;
}
static void F_18 ( unsigned int V_79 )
{
int V_5 ;
bool V_80 = false ;
for ( V_5 = 0 ; V_5 < F_17 ( V_78 ) ; V_5 ++ ) {
if ( V_78 [ V_5 ] == ( int ) V_79 ) {
F_3 ( L_38 ) ;
V_80 = true ;
break;
}
if ( V_78 [ V_5 ] == - 1 && V_80 == false ) {
V_78 [ V_5 ] = V_79 ;
V_80 = true ;
}
}
if ( ! V_80 )
F_3 ( L_39 ) ;
}
static void F_19 ( void )
{
int V_5 ;
F_3 ( L_40 ) ;
for ( V_5 = 0 ; V_5 < F_17 ( V_78 ) ; V_5 ++ ) {
if ( V_78 [ V_5 ] < 0 )
continue;
F_3 ( L_41 , V_78 [ V_5 ] ) ;
}
F_3 ( L_4 ) ;
}
static void F_20 ( void )
{
V_81 = 0 ;
memset ( V_55 , 0 , sizeof( V_55 ) ) ;
memset ( & V_82 , 0 , sizeof( V_82 ) ) ;
}
static void F_21 ( void )
{
memcpy ( & V_55 [ V_81 ++ ] , & V_82 , sizeof( V_82 ) ) ;
}
static bool F_22 ( int V_83 )
{
unsigned int V_84 = V_81 - 1 + V_83 ;
if ( V_84 == 0 ) {
F_20 () ;
return true ;
} else if ( V_84 < V_81 ) {
memcpy ( & V_82 , & V_55 [ V_84 ] , sizeof( V_82 ) ) ;
V_81 = V_84 ;
return true ;
} else {
F_3 ( L_42 ) ;
return false ;
}
}
static T_3 F_23 ( T_1 * V_65 , T_3 V_83 )
{
T_3 V_56 ;
memcpy ( & V_56 , & V_65 [ V_83 ] , sizeof( V_56 ) ) ;
return F_24 ( V_56 ) ;
}
static T_4 F_25 ( T_1 * V_65 , T_3 V_83 )
{
T_4 V_56 ;
memcpy ( & V_56 , & V_65 [ V_83 ] , sizeof( V_56 ) ) ;
return F_26 ( V_56 ) ;
}
static T_1 F_27 ( T_1 * V_65 , T_3 V_83 )
{
return V_65 [ V_83 ] ;
}
static void F_28 ( struct V_55 * V_56 )
{
V_56 -> V_62 = 0 ;
V_56 -> V_61 = true ;
}
static void F_29 ( struct V_55 * V_56 , struct V_7 * V_8 ,
T_1 * V_65 , T_3 V_66 ,
T_3 V_67 )
{
T_3 V_85 = V_8 -> V_12 ;
int V_86 ;
switch ( V_8 -> V_13 ) {
case V_14 | V_15 :
V_56 -> V_62 = V_85 ;
V_56 -> V_61 = true ;
break;
case V_14 | V_17 :
V_56 -> V_62 = V_56 -> V_59 ;
V_56 -> V_61 = true ;
break;
case V_14 | V_18 :
V_56 -> V_62 = V_56 -> V_60 ;
V_56 -> V_61 = true ;
break;
case V_19 :
V_56 -> V_60 = V_56 -> V_59 ;
break;
case V_20 :
V_56 -> V_59 = V_56 -> V_60 ;
break;
case V_21 :
V_56 -> V_64 [ V_85 ] = V_56 -> V_59 ;
break;
case V_22 :
V_56 -> V_64 [ V_85 ] = V_56 -> V_60 ;
break;
case V_23 | V_24 :
V_86 = V_66 - V_85 ;
if ( V_86 >= sizeof( T_3 ) )
V_56 -> V_59 = F_23 ( V_65 , V_85 ) ;
else
F_28 ( V_56 ) ;
break;
case V_25 | V_24 :
V_86 = V_66 - V_85 ;
if ( V_86 >= sizeof( T_4 ) )
V_56 -> V_59 = F_25 ( V_65 , V_85 ) ;
else
F_28 ( V_56 ) ;
break;
case V_26 | V_24 :
V_86 = V_66 - V_85 ;
if ( V_86 >= sizeof( T_1 ) )
V_56 -> V_59 = F_27 ( V_65 , V_85 ) ;
else
F_28 ( V_56 ) ;
break;
case V_23 | V_28 :
V_86 = V_66 - ( V_56 -> V_60 + V_85 ) ;
if ( V_86 >= sizeof( T_3 ) )
V_56 -> V_59 = F_23 ( V_65 , V_56 -> V_60 + V_85 ) ;
break;
case V_25 | V_28 :
V_86 = V_66 - ( V_56 -> V_60 + V_85 ) ;
if ( V_86 >= sizeof( T_4 ) )
V_56 -> V_59 = F_25 ( V_65 , V_56 -> V_60 + V_85 ) ;
else
F_28 ( V_56 ) ;
break;
case V_26 | V_28 :
V_86 = V_66 - ( V_56 -> V_60 + V_85 ) ;
if ( V_86 >= sizeof( T_1 ) )
V_56 -> V_59 = F_27 ( V_65 , V_56 -> V_60 + V_85 ) ;
else
F_28 ( V_56 ) ;
break;
case V_32 | V_33 :
V_86 = V_66 - V_85 ;
if ( V_86 >= sizeof( T_1 ) ) {
V_56 -> V_60 = F_27 ( V_65 , V_85 ) ;
V_56 -> V_60 = ( V_56 -> V_60 & 0xf ) << 2 ;
} else
F_28 ( V_56 ) ;
break;
case V_23 | V_27 :
V_56 -> V_59 = V_67 ;
break;
case V_87 | V_27 :
V_56 -> V_59 = V_67 ;
break;
case V_29 | V_30 :
V_56 -> V_59 = V_85 ;
break;
case V_31 | V_30 :
V_56 -> V_60 = V_85 ;
break;
case V_29 | V_34 :
V_56 -> V_59 = V_56 -> V_64 [ V_85 ] ;
break;
case V_31 | V_34 :
V_56 -> V_60 = V_56 -> V_64 [ V_85 ] ;
break;
case V_35 :
V_56 -> V_58 += V_85 ;
break;
case V_36 | V_18 :
V_56 -> V_58 += V_56 -> V_59 > V_56 -> V_60 ? V_8 -> V_53 : V_8 -> V_54 ;
break;
case V_36 | V_15 :
V_56 -> V_58 += V_56 -> V_59 > V_85 ? V_8 -> V_53 : V_8 -> V_54 ;
break;
case V_37 | V_18 :
V_56 -> V_58 += V_56 -> V_59 >= V_56 -> V_60 ? V_8 -> V_53 : V_8 -> V_54 ;
break;
case V_37 | V_15 :
V_56 -> V_58 += V_56 -> V_59 >= V_85 ? V_8 -> V_53 : V_8 -> V_54 ;
break;
case V_38 | V_18 :
V_56 -> V_58 += V_56 -> V_59 == V_56 -> V_60 ? V_8 -> V_53 : V_8 -> V_54 ;
break;
case V_38 | V_15 :
V_56 -> V_58 += V_56 -> V_59 == V_85 ? V_8 -> V_53 : V_8 -> V_54 ;
break;
case V_39 | V_18 :
V_56 -> V_58 += V_56 -> V_59 & V_56 -> V_60 ? V_8 -> V_53 : V_8 -> V_54 ;
break;
case V_39 | V_15 :
V_56 -> V_58 += V_56 -> V_59 & V_85 ? V_8 -> V_53 : V_8 -> V_54 ;
break;
case V_40 :
V_56 -> V_59 = - V_56 -> V_59 ;
break;
case V_41 | V_18 :
V_56 -> V_59 <<= V_56 -> V_60 ;
break;
case V_41 | V_15 :
V_56 -> V_59 <<= V_85 ;
break;
case V_42 | V_18 :
V_56 -> V_59 >>= V_56 -> V_60 ;
break;
case V_42 | V_15 :
V_56 -> V_59 >>= V_85 ;
break;
case V_43 | V_18 :
V_56 -> V_59 += V_56 -> V_60 ;
break;
case V_43 | V_15 :
V_56 -> V_59 += V_85 ;
break;
case V_44 | V_18 :
V_56 -> V_59 -= V_56 -> V_60 ;
break;
case V_44 | V_15 :
V_56 -> V_59 -= V_85 ;
break;
case V_45 | V_18 :
V_56 -> V_59 *= V_56 -> V_60 ;
break;
case V_45 | V_15 :
V_56 -> V_59 *= V_85 ;
break;
case V_46 | V_18 :
case V_47 | V_18 :
if ( V_56 -> V_60 == 0 ) {
F_28 ( V_56 ) ;
break;
}
goto V_88;
case V_46 | V_15 :
case V_47 | V_15 :
if ( V_85 == 0 ) {
F_28 ( V_56 ) ;
break;
}
V_88:
switch ( V_8 -> V_13 ) {
case V_46 | V_18 :
V_56 -> V_59 /= V_56 -> V_60 ;
break;
case V_46 | V_15 :
V_56 -> V_59 /= V_85 ;
break;
case V_47 | V_18 :
V_56 -> V_59 %= V_56 -> V_60 ;
break;
case V_47 | V_15 :
V_56 -> V_59 %= V_85 ;
break;
}
break;
case V_48 | V_18 :
V_56 -> V_59 &= V_56 -> V_60 ;
break;
case V_48 | V_15 :
V_56 -> V_59 &= V_85 ;
break;
case V_49 | V_18 :
V_56 -> V_59 |= V_56 -> V_60 ;
break;
case V_49 | V_15 :
V_56 -> V_59 |= V_85 ;
break;
case V_50 | V_18 :
V_56 -> V_59 ^= V_56 -> V_60 ;
break;
case V_50 | V_15 :
V_56 -> V_59 ^= V_85 ;
break;
}
}
static bool F_30 ( T_4 V_89 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < F_17 ( V_78 ) ; V_5 ++ ) {
if ( V_78 [ V_5 ] < 0 )
continue;
if ( V_78 [ V_5 ] == V_89 )
return true ;
}
return false ;
}
static bool F_31 ( struct V_55 * V_56 , struct V_7 * V_8 ,
T_1 * V_65 , T_3 V_66 ,
T_3 V_67 )
{
F_3 ( L_43 ) ;
F_8 ( V_56 , & V_8 [ V_56 -> V_58 ] ) ;
F_3 ( L_44 ) ;
F_9 ( V_65 , V_66 , V_67 ) ;
F_3 ( L_45 ) ;
return true ;
}
static int F_32 ( struct V_7 * V_8 , T_4 V_90 , T_1 * V_65 ,
T_3 V_66 , T_3 V_67 )
{
bool V_91 = false ;
while ( V_82 . V_61 == false && V_91 == false ) {
F_21 () ;
if ( F_30 ( V_82 . V_58 ) )
V_91 = F_31 ( & V_82 , V_8 , V_65 ,
V_66 , V_67 ) ;
F_29 ( & V_82 , & V_8 [ V_82 . V_58 ] , V_65 , V_66 ,
V_67 ) ;
V_82 . V_58 ++ ;
}
return V_91 ? - 1 : V_82 . V_62 ;
}
static int F_33 ( struct V_7 * V_8 , T_4 V_90 ,
T_1 * V_65 , T_3 V_66 ,
T_3 V_67 , int V_92 )
{
bool V_91 = false ;
int V_5 = 1 ;
while ( V_82 . V_61 == false && V_91 == false ) {
F_21 () ;
if ( V_5 ++ == V_92 )
V_91 = F_31 ( & V_82 , V_8 , V_65 ,
V_66 , V_67 ) ;
F_29 ( & V_82 , & V_8 [ V_82 . V_58 ] , V_65 , V_66 ,
V_67 ) ;
V_82 . V_58 ++ ;
}
return V_91 ? - 1 : V_82 . V_62 ;
}
static bool F_34 ( void )
{
if ( V_93 < 0 )
F_3 ( L_46 ) ;
return V_93 >= 0 ;
}
static struct V_94 * F_35 ( void )
{
return ( void * ) V_95 ;
}
static bool F_36 ( void )
{
struct V_94 * V_96 = F_35 () ;
if ( V_95 + sizeof( * V_96 ) -
V_97 >= V_98 )
return false ;
if ( V_96 -> V_99 == 0 || V_96 -> V_3 == 0 || V_96 -> V_99 > V_96 -> V_3 )
return false ;
if ( V_95 + sizeof( * V_96 ) + V_96 -> V_99 -
V_97 >= V_98 )
return false ;
V_95 += ( sizeof( * V_96 ) + V_96 -> V_99 ) ;
return true ;
}
static void F_37 ( void )
{
V_95 = V_97 + sizeof( struct V_100 ) ;
}
static int F_38 ( const char * V_101 )
{
struct V_100 * V_96 ;
struct V_102 V_103 ;
int V_69 ;
V_93 = F_39 ( V_101 , V_104 ) ;
if ( V_93 < 0 ) {
F_3 ( L_47 , strerror ( V_105 ) ) ;
return V_106 ;
}
V_69 = F_40 ( V_93 , & V_103 ) ;
if ( V_69 < 0 ) {
F_3 ( L_48 ) ;
return V_106 ;
}
if ( ! F_41 ( V_103 . V_107 ) ) {
F_3 ( L_49 ) ;
return V_106 ;
}
V_98 = V_103 . V_108 ;
if ( V_98 <= sizeof( struct V_100 ) ) {
F_3 ( L_50 ) ;
return V_106 ;
}
V_97 = F_42 ( NULL , V_98 , V_109 ,
V_110 | V_111 , V_93 , 0 ) ;
if ( V_97 == V_112 ) {
F_3 ( L_51 ) ;
return V_106 ;
}
V_96 = ( void * ) V_97 ;
if ( V_96 -> V_113 != V_114 ) {
F_3 ( L_52 ) ;
return V_106 ;
}
F_37 () ;
return V_115 ;
}
static void F_43 ( void )
{
if ( V_93 >= 0 ) {
F_44 ( V_97 , V_98 ) ;
F_15 ( V_93 ) ;
V_97 = V_95 = NULL ;
V_98 = 0 ;
V_116 = 0 ;
V_93 = - 1 ;
}
}
static int F_45 ( char * V_117 )
{
char V_118 , * V_119 , V_120 = ',' ;
unsigned short V_90 , V_5 = 0 ;
struct V_7 V_121 ;
V_6 = 0 ;
memset ( V_122 , 0 , sizeof( V_122 ) ) ;
if ( sscanf ( V_117 , L_53 , & V_90 , & V_118 ) != 2 ||
V_118 != V_120 || V_90 > V_123 || V_90 == 0 ) {
F_3 ( L_54 ) ;
return V_106 ;
}
V_119 = V_117 ;
while ( ( V_119 = strchr ( V_119 , V_120 ) ) && ( ++ V_119 ) [ 0 ] ) {
if ( V_5 >= V_90 ) {
F_3 ( L_55 ) ;
return V_106 ;
}
if ( sscanf ( V_119 , L_56 ,
& V_121 . V_13 , & V_121 . V_53 , & V_121 . V_54 , & V_121 . V_12 ) != 4 ) {
F_3 ( L_57 , V_5 ) ;
return V_106 ;
}
V_122 [ V_5 ] . V_13 = V_121 . V_13 ;
V_122 [ V_5 ] . V_53 = V_121 . V_53 ;
V_122 [ V_5 ] . V_54 = V_121 . V_54 ;
V_122 [ V_5 ] . V_12 = V_121 . V_12 ;
V_5 ++ ;
}
if ( V_5 != V_90 ) {
F_3 ( L_58 ) ;
return V_106 ;
} else
V_6 = V_90 ;
if ( ! F_12 ( V_122 , V_6 ) )
V_6 = 0 ;
return V_115 ;
}
static int F_46 ( char * V_101 )
{
char * V_124 , * V_121 ;
V_124 = strtok_r ( V_101 , L_59 , & V_121 ) ;
if ( V_124 == NULL )
return V_106 ;
F_43 () ;
return F_38 ( V_124 ) ;
}
static int F_47 ( char * V_125 )
{
char * V_126 , * V_127 , * V_121 = F_48 ( V_125 ) ;
int V_69 = V_115 ;
V_126 = strtok_r ( V_121 , L_59 , & V_127 ) ;
if ( V_126 == NULL )
goto V_128;
if ( F_1 ( V_126 , L_60 ) == 0 ) {
F_20 () ;
F_16 () ;
V_69 = F_45 ( V_127 ) ;
} else if ( F_1 ( V_126 , L_61 ) == 0 ) {
V_69 = F_46 ( V_127 ) ;
} else {
V_128:
F_3 ( L_62 ) ;
F_3 ( L_63 ) ;
V_69 = V_106 ;
}
free ( V_121 ) ;
return V_69 ;
}
static int F_49 ( char * V_129 )
{
struct V_94 * V_96 ;
int V_130 , V_69 ;
if ( ! F_4 () || ! F_34 () )
return V_106 ;
V_130 = strtol ( V_129 , NULL , 10 ) ;
if ( V_130 == 0 || strlen ( V_129 ) == 0 )
V_130 = 1 ;
if ( V_130 < 0 ) {
if ( ! F_22 ( V_130 ) )
return V_106 ;
V_130 = 1 ;
}
V_96 = F_35 () ;
V_69 = F_33 ( V_122 , V_6 ,
( T_1 * ) V_96 + sizeof( * V_96 ) ,
V_96 -> V_99 , V_96 -> V_3 , V_130 ) ;
if ( V_69 >= 0 || V_82 . V_61 ) {
F_20 () ;
if ( ! F_36 () ) {
F_3 ( L_64 ) ;
F_37 () ;
} else {
F_3 ( L_65 ) ;
}
}
return V_115 ;
}
static int F_50 ( char * V_129 )
{
unsigned int V_131 , V_5 ;
bool V_132 = true ;
if ( ! F_34 () || strlen ( V_129 ) == 0 )
return V_106 ;
V_131 = strtoul ( V_129 , NULL , 10 ) ;
if ( V_131 == 0 ) {
F_3 ( L_66 ) ;
V_131 = 1 ;
}
F_37 () ;
F_20 () ;
for ( V_5 = 0 ; V_5 < V_131 && ( V_132 = F_36 () ) ; V_5 ++ )
;
if ( ! V_132 || F_35 () == NULL ) {
F_3 ( L_67 , V_131 ) ;
F_37 () ;
return V_106 ;
}
return V_115 ;
}
static int F_51 ( char * V_126 )
{
if ( ! F_4 () )
return V_106 ;
if ( strlen ( V_126 ) == 0 )
F_19 () ;
else if ( F_1 ( V_126 , L_68 ) == 0 )
F_16 () ;
else {
unsigned int V_79 = strtoul ( V_126 , NULL , 10 ) ;
if ( V_79 < V_6 ) {
F_18 ( V_79 ) ;
F_3 ( L_69 ) ;
F_5 ( V_122 [ V_79 ] , V_79 ) ;
}
}
return V_115 ;
}
static int F_52 ( char * V_129 )
{
static T_3 V_133 = 0 , V_134 = 0 ;
bool V_135 = true ;
int V_136 = 0 , V_5 = 0 ;
if ( ! F_4 () || ! F_34 () )
return V_106 ;
V_136 = strtol ( V_129 , NULL , 10 ) ;
if ( V_136 == 0 || strlen ( V_129 ) == 0 )
V_135 = false ;
do {
struct V_94 * V_96 = F_35 () ;
int V_69 = F_32 ( V_122 , V_6 ,
( T_1 * ) V_96 + sizeof( * V_96 ) ,
V_96 -> V_99 , V_96 -> V_3 ) ;
if ( V_69 > 0 )
V_133 ++ ;
else if ( V_69 == 0 )
V_134 ++ ;
else
return V_115 ;
F_20 () ;
} while ( F_36 () && ( ! V_135 || ( V_135 && ++ V_5 < V_136 ) ) );
F_3 ( L_70 , V_133 , V_134 ) ;
F_37 () ;
F_20 () ;
V_133 = V_134 = 0 ;
return V_115 ;
}
static int F_53 ( char * V_137 )
{
bool V_138 = false ;
unsigned long line ;
if ( ! F_4 () )
return V_106 ;
if ( strlen ( V_137 ) > 0 &&
( line = strtoul ( V_137 , NULL , 10 ) ) < V_6 )
V_138 = true ;
if ( V_138 )
F_5 ( V_122 [ line ] , line ) ;
else
F_10 ( V_122 , V_6 ) ;
return V_115 ;
}
static int F_54 ( char * V_139 )
{
if ( ! F_4 () )
return V_106 ;
F_11 ( V_122 , V_6 ) ;
return V_115 ;
}
static int F_55 ( char * V_139 )
{
return V_140 ;
}
static int F_56 ( char * V_125 )
{
char * V_1 , * V_127 , * V_121 = F_48 ( V_125 ) ;
int V_5 , V_69 = 0 , V_3 ;
V_1 = strtok_r ( V_121 , L_59 , & V_127 ) ;
if ( V_1 == NULL )
goto V_128;
V_3 = strlen ( V_1 ) ;
for ( V_5 = 0 ; V_5 < F_17 ( V_141 ) ; V_5 ++ ) {
if ( V_3 != strlen ( V_141 [ V_5 ] . V_142 ) )
continue;
if ( strncmp ( V_141 [ V_5 ] . V_142 , V_1 , V_3 ) == 0 ) {
V_69 = V_141 [ V_5 ] . F_57 ( V_127 ) ;
break;
}
}
V_128:
free ( V_121 ) ;
return V_69 ;
}
static char * F_58 ( const char * V_4 , int V_143 )
{
static int V_144 , V_3 ;
if ( ! V_143 ) {
V_144 = 0 ;
V_3 = strlen ( V_4 ) ;
}
for (; V_144 < F_17 ( V_141 ) ; ) {
const char * V_142 = V_141 [ V_144 ] . V_142 ;
V_144 ++ ;
if ( strncmp ( V_142 , V_4 , V_3 ) == 0 )
return F_48 ( V_142 ) ;
}
return NULL ;
}
static char * * F_59 ( const char * V_4 , int V_145 , int V_146 )
{
char * * F_1 = NULL ;
if ( V_145 == 0 )
F_1 = F_60 ( V_4 , F_58 ) ;
return F_1 ;
}
static void F_61 ( int V_147 )
{
if ( V_148 )
F_62 ( - 1 , 0 ) ;
F_63 () ;
F_64 ( 0 , 0 ) ;
F_65 () ;
}
static void F_66 ( T_5 * V_149 , T_5 * V_150 )
{
char V_101 [ 128 ] ;
snprintf ( V_101 , sizeof( V_101 ) , L_71 , getenv ( L_72 ) ) ;
F_67 ( V_101 ) ;
V_151 = V_149 ;
V_152 = V_150 ;
V_153 = L_73 ;
V_154 = getenv ( L_74 ) ;
V_155 = 0 ;
V_156 = 1 ;
V_157 = F_59 ;
F_68 ( '\t' , V_158 ) ;
F_69 ( '\t' , V_158 , V_159 ) ;
F_69 ( '\033' , V_158 , V_159 ) ;
snprintf ( V_101 , sizeof( V_101 ) , L_75 , getenv ( L_72 ) ) ;
F_70 ( V_101 ) ;
F_71 ( 0 ) ;
F_72 () ;
signal ( V_160 , F_61 ) ;
}
static void F_73 ( T_5 * V_149 , T_5 * V_150 )
{
char V_101 [ 128 ] ;
snprintf ( V_101 , sizeof( V_101 ) , L_71 , getenv ( L_72 ) ) ;
F_74 ( V_101 ) ;
F_75 () ;
F_76 () ;
F_43 () ;
if ( V_149 != V_161 )
fclose ( V_149 ) ;
if ( V_150 != stdout )
fclose ( V_150 ) ;
}
static int F_77 ( T_5 * V_149 , T_5 * V_150 )
{
char * V_4 ;
F_66 ( V_149 , V_150 ) ;
while ( ( V_4 = F_78 ( L_76 ) ) != NULL ) {
int V_69 = F_56 ( V_4 ) ;
if ( V_69 == V_140 )
break;
if ( V_69 == V_115 && strlen ( V_4 ) > 0 )
F_79 ( V_4 ) ;
free ( V_4 ) ;
}
F_73 ( V_149 , V_150 ) ;
return 0 ;
}
int main ( int V_162 , char * * V_163 )
{
T_5 * V_149 = NULL , * V_150 = NULL ;
if ( V_162 >= 2 )
V_149 = fopen ( V_163 [ 1 ] , L_77 ) ;
if ( V_162 >= 3 )
V_150 = fopen ( V_163 [ 2 ] , L_78 ) ;
return F_77 ( V_149 ? : V_161 , V_150 ? : stdout ) ;
}
