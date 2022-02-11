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
V_7 -> V_27 = F_9 () & ~ 0x3f ;
if ( V_7 -> V_11 & V_24 ) {
V_7 -> V_27 |= V_7 -> V_22 ;
V_7 -> V_22 = V_39 -> V_22 ;
} else
V_7 -> V_27 |= 0xf ;
if ( V_7 -> V_11 & V_32 )
V_7 -> V_27 |= 1 << 4 ;
if ( V_7 -> V_11 & V_40 )
V_7 -> V_27 |= 1 << 5 ;
}
void F_10 ( struct V_6 * V_7 )
{
V_7 -> V_22 = V_7 -> V_28 & 0xf ;
if ( V_7 -> V_22 != 0xf )
V_7 -> V_11 |= V_24 ;
V_7 -> V_11 |= V_7 -> V_28 & ( 1 << 4 ) ? V_32 : 0 ;
V_7 -> V_11 |= V_7 -> V_28 & ( 1 << 5 ) ? V_40 : 0 ;
}
unsigned int F_11 ( struct V_1 * V_2 ,
unsigned int V_41 ,
struct V_4 * V_5 ,
struct V_42 * V_43 ,
enum V_44 V_45 ,
const struct V_46 * V_47 )
{
unsigned int V_48 , V_49 ;
T_2 * V_10 , V_50 ;
if ( V_47 -> V_51 == 0 )
return 1 ;
V_48 = V_41 + sizeof( struct V_4 ) ;
V_49 = V_41 + V_5 -> V_3 * 4 ;
if ( ! F_12 ( V_2 , V_49 ) )
return 0 ;
while ( V_48 < V_49 ) {
unsigned char * V_52 = V_2 -> V_53 + V_48 ;
switch ( V_52 [ 0 ] ) {
case V_14 :
return 1 ;
case V_15 :
V_48 ++ ;
continue;
default:
if ( V_48 + 1 == V_49 ||
V_48 + V_52 [ 1 ] > V_49 ||
V_52 [ 1 ] < 2 )
return 0 ;
if ( V_52 [ 0 ] == V_25 &&
V_52 [ 1 ] == V_26 ) {
if ( F_13 ( V_45 ) == V_54 ) {
V_10 = ( T_2 * ) & V_52 [ 2 ] ;
V_50 = * V_10 ;
* V_10 = F_7 ( F_14 ( * V_10 ) -
V_47 -> V_51 ) ;
} else {
V_10 = ( T_2 * ) & V_52 [ 6 ] ;
V_50 = * V_10 ;
* V_10 = F_7 ( F_14 ( * V_10 ) +
V_47 -> V_51 ) ;
}
F_15 ( & V_5 -> V_55 , V_2 ,
V_50 , * V_10 , false ) ;
return 1 ;
}
V_48 += V_52 [ 1 ] ;
}
}
return 1 ;
}
static void * F_16 ( struct V_56 * V_57 , T_3 * V_58 )
{
struct V_59 * V_60 = F_17 ( F_18 ( V_57 ) ) ;
int V_61 ;
if ( * V_58 == 0 )
return V_62 ;
for ( V_61 = * V_58 - 1 ; V_61 < V_63 ; V_61 ++ ) {
if ( ! F_19 ( V_61 ) )
continue;
* V_58 = V_61 + 1 ;
return F_20 ( V_60 -> V_64 , V_61 ) ;
}
return NULL ;
}
static void * F_21 ( struct V_56 * V_57 , void * V_65 , T_3 * V_58 )
{
struct V_59 * V_60 = F_17 ( F_18 ( V_57 ) ) ;
int V_61 ;
for ( V_61 = * V_58 ; V_61 < V_63 ; V_61 ++ ) {
if ( ! F_19 ( V_61 ) )
continue;
* V_58 = V_61 + 1 ;
return F_20 ( V_60 -> V_64 , V_61 ) ;
}
return NULL ;
}
static void F_22 ( struct V_56 * V_57 , void * V_65 )
{
return;
}
static int F_23 ( struct V_56 * V_57 , void * V_65 )
{
struct V_66 * V_64 = V_65 ;
if ( V_65 == V_62 ) {
F_24 ( V_57 , L_1
L_2
L_3 ) ;
return 0 ;
}
F_25 ( V_57 , L_4 , 0 ,
V_64 -> V_67 ,
V_64 -> V_68 ,
V_64 -> V_69 ,
V_64 -> V_70 ,
V_64 -> V_71 ) ;
return 0 ;
}
static int F_26 ( struct V_72 * V_72 , struct V_73 * V_73 )
{
return F_27 ( V_72 , V_73 , & V_74 ,
sizeof( struct V_75 ) ) ;
}
static int T_4 F_28 ( struct V_76 * V_76 )
{
if ( ! F_29 ( L_5 , V_77 , V_76 -> V_78 ,
& V_79 ) )
return - V_80 ;
return 0 ;
}
static void T_5 F_30 ( struct V_76 * V_76 )
{
F_31 ( L_5 , V_76 -> V_78 ) ;
}
static int T_4 F_28 ( struct V_76 * V_76 )
{
return 0 ;
}
static void T_5 F_30 ( struct V_76 * V_76 )
{
return;
}
static int T_4 F_32 ( struct V_76 * V_76 )
{
struct V_59 * V_60 = F_17 ( V_76 ) ;
struct V_42 * V_43 ;
int V_81 = - V_80 ;
V_43 = F_33 ( V_76 , & V_82 , V_83 ) ;
if ( ! V_43 )
goto V_84;
if ( ! F_34 ( V_43 ) )
goto V_85;
if ( ! F_35 ( V_43 ) )
goto V_85;
F_36 ( V_86 , & V_43 -> V_87 ) ;
F_37 ( & V_43 -> V_88 ) ;
V_60 -> V_89 = V_43 ;
V_60 -> V_64 = F_38 ( struct V_66 ) ;
if ( V_60 -> V_64 == NULL )
goto V_85;
V_81 = F_28 ( V_76 ) ;
if ( V_81 < 0 )
goto V_90;
return 0 ;
V_90:
F_39 ( V_60 -> V_64 ) ;
V_85:
F_40 ( V_43 ) ;
V_84:
return V_81 ;
}
static void T_5 F_41 ( struct V_76 * V_76 )
{
struct V_59 * V_60 = F_17 ( V_76 ) ;
F_42 ( V_60 -> V_89 ) ;
F_30 ( V_76 ) ;
F_39 ( V_60 -> V_64 ) ;
}
static int T_6 F_43 ( void )
{
int V_81 ;
V_81 = F_44 ( & V_91 ) ;
if ( V_81 < 0 )
goto V_84;
V_81 = F_45 ( & V_92 ) ;
if ( V_81 < 0 )
goto V_85;
return 0 ;
V_85:
F_46 ( & V_91 ) ;
V_84:
return V_81 ;
}
static void T_7 F_47 ( void )
{
F_48 ( & V_92 ) ;
F_46 ( & V_91 ) ;
}
