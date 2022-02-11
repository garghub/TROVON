bool
F_1 ( const struct V_1 * V_2 , unsigned int V_3 ,
const struct V_4 * V_5 , struct V_6 * V_7 )
{
int V_8 = ( V_5 -> V_3 * 4 ) - sizeof( * V_5 ) ;
T_1 V_9 [ 40 ] , * V_10 ;
V_10 = F_2 ( V_2 , V_3 + sizeof( * V_5 ) , V_8 , V_9 ) ;
if ( V_10 == NULL )
return false ;
V_7 -> V_11 = 0 ;
while ( V_8 > 0 ) {
int V_12 = * V_10 ++ ;
int V_13 ;
switch ( V_12 ) {
case V_14 :
return true ;
case V_15 :
V_8 -- ;
continue;
default:
V_13 = * V_10 ++ ;
if ( V_13 < 2 )
return true ;
if ( V_13 > V_8 )
return true ;
switch ( V_12 ) {
case V_16 :
if ( V_13 == V_17 ) {
V_7 -> V_18 = F_3 ( V_10 ) ;
V_7 -> V_11 |= V_19 ;
}
break;
case V_20 :
if ( V_13 == V_21 ) {
V_7 -> V_22 = * V_10 ;
if ( V_7 -> V_22 > V_23 )
V_7 -> V_22 = V_23 ;
V_7 -> V_11 |= V_24 ;
}
break;
case V_25 :
if ( V_13 == V_26 ) {
V_7 -> V_27 = F_4 ( V_10 ) ;
V_7 -> V_28 = F_4 ( V_10 + 4 ) ;
V_7 -> V_11 |= V_29 ;
}
break;
case V_30 :
if ( V_13 == V_31 )
V_7 -> V_11 |= V_32 ;
break;
}
V_10 += V_13 - 2 ;
V_8 -= V_13 ;
}
}
return true ;
}
unsigned int F_5 ( const struct V_6 * V_7 )
{
unsigned int V_33 = 0 ;
if ( V_7 -> V_11 & V_19 )
V_33 += V_34 ;
if ( V_7 -> V_11 & V_29 )
V_33 += V_35 ;
else if ( V_7 -> V_11 & V_32 )
V_33 += V_36 ;
if ( V_7 -> V_11 & V_24 )
V_33 += V_37 ;
return V_33 ;
}
void
F_6 ( struct V_4 * V_5 , const struct V_6 * V_7 )
{
T_2 * V_10 = ( T_2 * ) ( V_5 + 1 ) ;
T_1 V_11 = V_7 -> V_11 ;
if ( V_11 & V_19 )
* V_10 ++ = F_7 ( ( V_16 << 24 ) |
( V_17 << 16 ) |
V_7 -> V_18 ) ;
if ( V_11 & V_29 ) {
if ( V_11 & V_32 )
* V_10 ++ = F_7 ( ( V_30 << 24 ) |
( V_31 << 16 ) |
( V_25 << 8 ) |
V_26 ) ;
else
* V_10 ++ = F_7 ( ( V_15 << 24 ) |
( V_15 << 16 ) |
( V_25 << 8 ) |
V_26 ) ;
* V_10 ++ = F_7 ( V_7 -> V_27 ) ;
* V_10 ++ = F_7 ( V_7 -> V_28 ) ;
} else if ( V_11 & V_32 )
* V_10 ++ = F_7 ( ( V_15 << 24 ) |
( V_15 << 16 ) |
( V_30 << 8 ) |
V_31 ) ;
if ( V_11 & V_24 )
* V_10 ++ = F_7 ( ( V_15 << 24 ) |
( V_20 << 16 ) |
( V_21 << 8 ) |
V_7 -> V_22 ) ;
}
void F_8 ( const struct V_38 * V_39 ,
struct V_6 * V_7 )
{
V_7 -> V_28 = V_7 -> V_27 ;
V_7 -> V_27 = V_40 & ~ 0x3f ;
if ( V_7 -> V_11 & V_24 ) {
V_7 -> V_27 |= V_7 -> V_22 ;
V_7 -> V_22 = V_39 -> V_22 ;
} else
V_7 -> V_27 |= 0xf ;
if ( V_7 -> V_11 & V_32 )
V_7 -> V_27 |= 1 << 4 ;
if ( V_7 -> V_11 & V_41 )
V_7 -> V_27 |= 1 << 5 ;
}
void F_9 ( struct V_6 * V_7 )
{
V_7 -> V_22 = V_7 -> V_28 & 0xf ;
if ( V_7 -> V_22 != 0xf )
V_7 -> V_11 |= V_24 ;
V_7 -> V_11 |= V_7 -> V_28 & ( 1 << 4 ) ? V_32 : 0 ;
V_7 -> V_11 |= V_7 -> V_28 & ( 1 << 5 ) ? V_41 : 0 ;
}
unsigned int F_10 ( struct V_1 * V_2 ,
unsigned int V_42 ,
struct V_4 * V_5 ,
struct V_43 * V_44 ,
enum V_45 V_46 ,
const struct V_47 * V_48 )
{
unsigned int V_49 , V_50 ;
T_2 * V_10 , V_51 ;
if ( V_48 -> V_52 == 0 )
return 1 ;
V_49 = V_42 + sizeof( struct V_4 ) ;
V_50 = V_42 + V_5 -> V_3 * 4 ;
if ( ! F_11 ( V_2 , V_50 ) )
return 0 ;
while ( V_49 < V_50 ) {
unsigned char * V_53 = V_2 -> V_54 + V_49 ;
switch ( V_53 [ 0 ] ) {
case V_14 :
return 1 ;
case V_15 :
V_49 ++ ;
continue;
default:
if ( V_49 + 1 == V_50 ||
V_49 + V_53 [ 1 ] > V_50 ||
V_53 [ 1 ] < 2 )
return 0 ;
if ( V_53 [ 0 ] == V_25 &&
V_53 [ 1 ] == V_26 ) {
if ( F_12 ( V_46 ) == V_55 ) {
V_10 = ( T_2 * ) & V_53 [ 2 ] ;
V_51 = * V_10 ;
* V_10 = F_7 ( F_13 ( * V_10 ) -
V_48 -> V_52 ) ;
} else {
V_10 = ( T_2 * ) & V_53 [ 6 ] ;
V_51 = * V_10 ;
* V_10 = F_7 ( F_13 ( * V_10 ) +
V_48 -> V_52 ) ;
}
F_14 ( & V_5 -> V_56 , V_2 ,
V_51 , * V_10 , false ) ;
return 1 ;
}
V_49 += V_53 [ 1 ] ;
}
}
return 1 ;
}
static void * F_15 ( struct V_57 * V_58 , T_3 * V_59 )
{
struct V_60 * V_61 = F_16 ( F_17 ( V_58 ) ) ;
int V_62 ;
if ( * V_59 == 0 )
return V_63 ;
for ( V_62 = * V_59 - 1 ; V_62 < V_64 ; V_62 ++ ) {
if ( ! F_18 ( V_62 ) )
continue;
* V_59 = V_62 + 1 ;
return F_19 ( V_61 -> V_65 , V_62 ) ;
}
return NULL ;
}
static void * F_20 ( struct V_57 * V_58 , void * V_66 , T_3 * V_59 )
{
struct V_60 * V_61 = F_16 ( F_17 ( V_58 ) ) ;
int V_62 ;
for ( V_62 = * V_59 ; V_62 < V_64 ; V_62 ++ ) {
if ( ! F_18 ( V_62 ) )
continue;
* V_59 = V_62 + 1 ;
return F_19 ( V_61 -> V_65 , V_62 ) ;
}
return NULL ;
}
static void F_21 ( struct V_57 * V_58 , void * V_66 )
{
return;
}
static int F_22 ( struct V_57 * V_58 , void * V_66 )
{
struct V_67 * V_65 = V_66 ;
if ( V_66 == V_63 ) {
F_23 ( V_58 , L_1
L_2
L_3 ) ;
return 0 ;
}
F_24 ( V_58 , L_4 , 0 ,
V_65 -> V_68 ,
V_65 -> V_69 ,
V_65 -> V_70 ,
V_65 -> V_71 ,
V_65 -> V_72 ) ;
return 0 ;
}
static int F_25 ( struct V_73 * V_73 , struct V_74 * V_74 )
{
return F_26 ( V_73 , V_74 , & V_75 ,
sizeof( struct V_76 ) ) ;
}
static int T_4 F_27 ( struct V_77 * V_77 )
{
if ( ! F_28 ( L_5 , V_78 , V_77 -> V_79 ,
& V_80 ) )
return - V_81 ;
return 0 ;
}
static void T_5 F_29 ( struct V_77 * V_77 )
{
F_30 ( L_5 , V_77 -> V_79 ) ;
}
static int T_4 F_27 ( struct V_77 * V_77 )
{
return 0 ;
}
static void T_5 F_29 ( struct V_77 * V_77 )
{
return;
}
static int T_4 F_31 ( struct V_77 * V_77 )
{
struct V_60 * V_61 = F_16 ( V_77 ) ;
struct V_43 * V_44 ;
int V_82 = - V_81 ;
V_44 = F_32 ( V_77 , & V_83 , V_84 ) ;
if ( ! V_44 )
goto V_85;
if ( ! F_33 ( V_44 ) )
goto V_86;
if ( ! F_34 ( V_44 ) )
goto V_86;
F_35 ( V_87 , & V_44 -> V_88 ) ;
F_36 ( & V_44 -> V_89 ) ;
V_61 -> V_90 = V_44 ;
V_61 -> V_65 = F_37 ( struct V_67 ) ;
if ( V_61 -> V_65 == NULL )
goto V_86;
V_82 = F_27 ( V_77 ) ;
if ( V_82 < 0 )
goto V_91;
return 0 ;
V_91:
F_38 ( V_61 -> V_65 ) ;
V_86:
F_39 ( V_44 ) ;
V_85:
return V_82 ;
}
static void T_5 F_40 ( struct V_77 * V_77 )
{
struct V_60 * V_61 = F_16 ( V_77 ) ;
F_41 ( V_61 -> V_90 ) ;
F_29 ( V_77 ) ;
F_38 ( V_61 -> V_65 ) ;
}
static int T_6 F_42 ( void )
{
int V_82 ;
V_82 = F_43 ( & V_92 ) ;
if ( V_82 < 0 )
goto V_85;
V_82 = F_44 ( & V_93 ) ;
if ( V_82 < 0 )
goto V_86;
return 0 ;
V_86:
F_45 ( & V_92 ) ;
V_85:
return V_82 ;
}
static void T_7 F_46 ( void )
{
F_47 ( & V_93 ) ;
F_45 ( & V_92 ) ;
}
