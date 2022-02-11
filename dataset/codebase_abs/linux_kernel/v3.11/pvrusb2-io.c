static const char * F_1 ( enum V_1 V_2 )
{
switch ( V_2 ) {
case V_3 : return L_1 ;
case V_4 : return L_2 ;
case V_5 : return L_3 ;
case V_6 : return L_4 ;
}
return L_5 ;
}
static void F_2 ( struct V_7 * V_8 , const char * V_9 )
{
F_3 ( V_10 ,
L_6
L_7 ,
( V_9 ? L_8 : L_9 ) ,
( V_9 ? V_9 : L_9 ) ,
V_8 ,
( V_8 ? F_1 ( V_8 -> V_11 ) : L_10 ) ,
( V_8 ? V_8 -> V_12 : 0 ) ,
( V_8 ? V_8 -> V_13 : 0 ) ,
( V_8 ? V_8 -> V_14 : NULL ) ,
( V_8 ? V_8 -> V_15 : NULL ) ,
( V_8 ? V_8 -> V_16 : 0 ) ) ;
}
static void F_4 ( struct V_7 * V_8 )
{
unsigned int * V_17 ;
unsigned int * V_18 ;
unsigned int V_19 ;
struct V_20 * V_21 = V_8 -> V_14 ;
switch ( V_8 -> V_11 ) {
case V_4 :
V_17 = & V_21 -> V_22 ;
V_18 = & V_21 -> V_23 ;
V_19 = V_8 -> V_24 ;
break;
case V_5 :
V_17 = & V_21 -> V_25 ;
V_18 = & V_21 -> V_26 ;
V_19 = V_8 -> V_24 ;
break;
case V_6 :
V_17 = & V_21 -> V_27 ;
V_18 = & V_21 -> V_28 ;
V_19 = V_8 -> V_29 ;
break;
default:
return;
}
F_5 ( & V_8 -> V_30 ) ;
( * V_17 ) -- ;
( * V_18 ) -= V_19 ;
F_3 ( V_31 ,
L_11
L_12 ,
F_1 ( V_8 -> V_11 ) , * V_18 , * V_17 ) ;
V_8 -> V_11 = V_3 ;
}
static void F_6 ( struct V_7 * V_8 )
{
unsigned long V_32 ;
struct V_20 * V_21 ;
F_7 ( V_8 ) ;
V_21 = V_8 -> V_14 ;
F_3 ( V_31 ,
L_13 ,
V_8 ,
F_1 ( V_8 -> V_11 ) ,
F_1 ( V_3 ) ) ;
F_8 ( & V_21 -> V_33 , V_32 ) ;
F_4 ( V_8 ) ;
F_9 ( & V_21 -> V_33 , V_32 ) ;
}
static int F_10 ( struct V_7 * V_8 )
{
int V_34 ;
unsigned long V_32 ;
struct V_20 * V_21 ;
F_7 ( V_8 ) ;
V_21 = V_8 -> V_14 ;
F_3 ( V_31 ,
L_13 ,
V_8 ,
F_1 ( V_8 -> V_11 ) ,
F_1 ( V_6 ) ) ;
F_8 ( & V_21 -> V_33 , V_32 ) ;
V_34 = ( V_21 -> V_27 == 0 ) ;
F_4 ( V_8 ) ;
F_11 ( & V_8 -> V_30 , & V_21 -> V_35 ) ;
V_8 -> V_11 = V_6 ;
( V_21 -> V_27 ) ++ ;
V_21 -> V_28 += V_8 -> V_29 ;
F_3 ( V_31 ,
L_11
L_14 ,
F_1 ( V_8 -> V_11 ) ,
V_21 -> V_28 , V_21 -> V_27 ) ;
F_9 ( & V_21 -> V_33 , V_32 ) ;
return V_34 ;
}
static void F_12 ( struct V_7 * V_8 )
{
unsigned long V_32 ;
struct V_20 * V_21 ;
F_7 ( V_8 ) ;
V_21 = V_8 -> V_14 ;
F_3 ( V_31 ,
L_13 ,
V_8 ,
F_1 ( V_8 -> V_11 ) ,
F_1 ( V_4 ) ) ;
F_8 ( & V_21 -> V_33 , V_32 ) ;
F_4 ( V_8 ) ;
F_11 ( & V_8 -> V_30 , & V_21 -> V_36 ) ;
V_8 -> V_11 = V_4 ;
( V_21 -> V_22 ) ++ ;
V_21 -> V_23 += V_8 -> V_24 ;
F_3 ( V_31 ,
L_11
L_14 ,
F_1 ( V_8 -> V_11 ) ,
V_21 -> V_23 , V_21 -> V_22 ) ;
F_9 ( & V_21 -> V_33 , V_32 ) ;
}
static void F_13 ( struct V_7 * V_8 )
{
unsigned long V_32 ;
struct V_20 * V_21 ;
F_7 ( V_8 ) ;
V_21 = V_8 -> V_14 ;
F_3 ( V_31 ,
L_13 ,
V_8 ,
F_1 ( V_8 -> V_11 ) ,
F_1 ( V_5 ) ) ;
F_8 ( & V_21 -> V_33 , V_32 ) ;
F_4 ( V_8 ) ;
F_11 ( & V_8 -> V_30 , & V_21 -> V_37 ) ;
V_8 -> V_11 = V_5 ;
( V_21 -> V_25 ) ++ ;
V_21 -> V_26 += V_8 -> V_24 ;
F_3 ( V_31 ,
L_11
L_14 ,
F_1 ( V_8 -> V_11 ) ,
V_21 -> V_26 , V_21 -> V_25 ) ;
F_9 ( & V_21 -> V_33 , V_32 ) ;
}
static void F_14 ( struct V_7 * V_8 )
{
if ( V_8 -> V_11 == V_5 ) {
F_15 ( V_8 -> V_15 ) ;
}
}
static int F_16 ( struct V_7 * V_8 ,
struct V_20 * V_21 ,
unsigned int V_12 )
{
memset ( V_8 , 0 , sizeof( * V_8 ) ) ;
V_8 -> V_16 = V_38 ;
V_8 -> V_12 = V_12 ;
F_3 ( V_39 ,
L_15 , V_8 , V_21 ) ;
V_8 -> V_14 = V_21 ;
V_8 -> V_11 = V_3 ;
F_17 ( & V_8 -> V_30 ) ;
V_8 -> V_15 = F_18 ( 0 , V_40 ) ;
if ( ! V_8 -> V_15 ) return - V_41 ;
#ifdef F_19
F_2 ( V_8 , L_16 ) ;
#endif
return 0 ;
}
static void F_20 ( struct V_7 * V_8 )
{
#ifdef F_19
F_2 ( V_8 , L_17 ) ;
#endif
F_14 ( V_8 ) ;
F_6 ( V_8 ) ;
V_8 -> V_16 = 0 ;
V_8 -> V_14 = NULL ;
F_21 ( V_8 -> V_15 ) ;
F_3 ( V_39 , L_11
L_18 , V_8 ) ;
}
static int F_22 ( struct V_20 * V_21 , unsigned int V_17 )
{
int V_42 ;
unsigned int V_43 ;
if ( V_17 == V_21 -> V_44 ) return 0 ;
F_3 ( V_39 ,
L_19
L_20 ,
V_21 ,
V_21 -> V_44 ,
V_17 - V_21 -> V_44 ) ;
V_43 = V_17 & ~ 0x1f ;
if ( V_17 > V_43 ) V_43 += 0x20 ;
if ( V_17 > V_21 -> V_44 ) {
if ( V_43 > V_21 -> V_45 ) {
struct V_7 * * V_46 ;
V_46 = F_23 ( V_43 * sizeof( * V_46 ) , V_40 ) ;
if ( ! V_46 ) return - V_41 ;
if ( V_21 -> V_45 ) {
memcpy ( V_46 , V_21 -> V_47 ,
V_21 -> V_45 * sizeof( * V_46 ) ) ;
F_24 ( V_21 -> V_47 ) ;
}
V_21 -> V_47 = V_46 ;
V_21 -> V_45 = V_43 ;
}
while ( V_21 -> V_44 < V_17 ) {
struct V_7 * V_8 ;
V_8 = F_23 ( sizeof( * V_8 ) , V_40 ) ;
if ( ! V_8 ) return - V_41 ;
V_42 = F_16 ( V_8 , V_21 , V_21 -> V_44 ) ;
if ( V_42 ) {
F_24 ( V_8 ) ;
return - V_41 ;
}
V_21 -> V_47 [ V_21 -> V_44 ] = V_8 ;
( V_21 -> V_44 ) ++ ;
F_12 ( V_8 ) ;
}
} else {
while ( V_21 -> V_44 > V_17 ) {
struct V_7 * V_8 ;
V_8 = V_21 -> V_47 [ V_21 -> V_44 - 1 ] ;
V_21 -> V_47 [ V_21 -> V_44 - 1 ] = NULL ;
( V_21 -> V_44 ) -- ;
F_20 ( V_8 ) ;
F_24 ( V_8 ) ;
}
if ( V_43 < V_21 -> V_45 ) {
struct V_7 * * V_46 = NULL ;
if ( V_43 ) {
V_46 = F_25 ( V_21 -> V_47 , V_43 * sizeof( * V_46 ) ,
V_40 ) ;
if ( ! V_46 ) return - V_41 ;
}
F_24 ( V_21 -> V_47 ) ;
V_21 -> V_47 = V_46 ;
V_21 -> V_45 = V_43 ;
}
}
return 0 ;
}
static int F_26 ( struct V_20 * V_21 )
{
struct V_7 * V_8 ;
unsigned int V_17 ;
if ( V_21 -> V_44 == V_21 -> V_48 ) return 0 ;
F_3 ( V_39 ,
L_11
L_21 ,
V_21 , V_21 -> V_44 , V_21 -> V_48 ) ;
if ( V_21 -> V_44 < V_21 -> V_48 ) {
return F_22 ( V_21 , V_21 -> V_48 ) ;
}
V_17 = 0 ;
while ( ( V_21 -> V_44 - V_17 ) > V_21 -> V_48 ) {
V_8 = V_21 -> V_47 [ V_21 -> V_44 - ( V_17 + 1 ) ] ;
if ( V_8 -> V_11 != V_4 ) break;
V_17 ++ ;
}
if ( V_17 ) {
F_22 ( V_21 , V_21 -> V_44 - V_17 ) ;
}
return 0 ;
}
static void F_27 ( struct V_20 * V_21 )
{
struct V_49 * V_50 ;
struct V_7 * V_51 ;
while ( ( V_50 = V_21 -> V_37 . V_52 ) != & V_21 -> V_37 ) {
V_51 = F_28 ( V_50 , struct V_7 , V_30 ) ;
F_14 ( V_51 ) ;
if ( V_51 -> V_11 != V_5 ) continue;
F_12 ( V_51 ) ;
}
if ( V_21 -> V_44 != V_21 -> V_48 ) {
F_26 ( V_21 ) ;
}
}
static void F_29 ( struct V_20 * V_21 )
{
F_30 ( & V_21 -> V_33 ) ;
F_31 ( & V_21 -> V_53 ) ;
F_17 ( & V_21 -> V_37 ) ;
F_17 ( & V_21 -> V_35 ) ;
F_17 ( & V_21 -> V_36 ) ;
}
static void F_32 ( struct V_20 * V_21 )
{
F_33 ( & V_21 -> V_53 ) ; do {
F_27 ( V_21 ) ;
F_22 ( V_21 , 0 ) ;
} while ( 0 ); F_34 ( & V_21 -> V_53 ) ;
}
static void F_35 ( struct V_54 * V_54 )
{
struct V_7 * V_8 = V_54 -> V_55 ;
struct V_20 * V_21 ;
unsigned long V_32 ;
F_7 ( V_8 ) ;
V_21 = V_8 -> V_14 ;
V_8 -> V_29 = 0 ;
V_8 -> V_13 = 0 ;
F_3 ( V_31 ,
L_22 ,
V_8 , V_54 -> V_13 , V_54 -> V_56 ) ;
F_8 ( & V_21 -> V_33 , V_32 ) ;
if ( ( ! ( V_54 -> V_13 ) ) ||
( V_54 -> V_13 == - V_57 ) ||
( V_54 -> V_13 == - V_58 ) ||
( V_54 -> V_13 == - V_59 ) ) {
( V_21 -> V_60 ) ++ ;
V_21 -> V_61 += V_54 -> V_56 ;
V_8 -> V_29 = V_54 -> V_56 ;
if ( V_21 -> V_62 ) {
F_3 ( V_63 ,
L_23
L_24 , V_21 ) ;
V_21 -> V_62 = 0 ;
}
} else if ( V_21 -> V_62 < V_21 -> V_64 ) {
( V_21 -> V_62 ) ++ ;
( V_21 -> V_65 ) ++ ;
F_3 ( V_63 ,
L_25
L_26 ,
V_21 , V_54 -> V_13 , V_21 -> V_62 ) ;
} else {
( V_21 -> V_65 ) ++ ;
V_8 -> V_13 = V_54 -> V_13 ;
}
F_9 ( & V_21 -> V_33 , V_32 ) ;
F_10 ( V_8 ) ;
if ( V_21 && V_21 -> V_66 ) {
V_21 -> V_66 ( V_21 -> V_67 ) ;
}
}
struct V_20 * F_36 ( void )
{
struct V_20 * V_21 ;
V_21 = F_37 ( sizeof( * V_21 ) , V_40 ) ;
if ( ! V_21 ) return V_21 ;
F_3 ( V_68 , L_27 , V_21 ) ;
F_29 ( V_21 ) ;
return V_21 ;
}
void F_38 ( struct V_20 * V_21 )
{
if ( ! V_21 ) return;
F_3 ( V_68 , L_28 , V_21 ) ;
F_32 ( V_21 ) ;
F_24 ( V_21 ) ;
}
void F_39 ( struct V_20 * V_21 ,
struct V_69 * V_70 ,
int V_71 ,
unsigned int V_72 )
{
F_33 ( & V_21 -> V_53 ) ; do {
F_27 ( V_21 ) ;
V_21 -> V_70 = V_70 ;
V_21 -> V_71 = V_71 ;
V_21 -> V_64 = V_72 ;
} while( 0 ); F_34 ( & V_21 -> V_53 ) ;
}
void F_40 ( struct V_20 * V_21 ,
T_1 V_73 ,
void * V_74 )
{
unsigned long V_32 ;
F_33 ( & V_21 -> V_53 ) ; do {
F_8 ( & V_21 -> V_33 , V_32 ) ;
V_21 -> V_67 = V_74 ;
V_21 -> V_66 = V_73 ;
F_9 ( & V_21 -> V_33 , V_32 ) ;
} while( 0 ); F_34 ( & V_21 -> V_53 ) ;
}
void F_41 ( struct V_20 * V_21 ,
struct V_75 * V_76 ,
int V_77 )
{
unsigned long V_32 ;
F_8 ( & V_21 -> V_33 , V_32 ) ;
if ( V_76 ) {
V_76 -> V_78 = V_21 -> V_25 ;
V_76 -> V_79 = V_21 -> V_22 ;
V_76 -> V_80 = V_21 -> V_27 ;
V_76 -> V_60 = V_21 -> V_60 ;
V_76 -> V_65 = V_21 -> V_65 ;
V_76 -> V_61 = V_21 -> V_61 ;
}
if ( V_77 ) {
V_21 -> V_60 = 0 ;
V_21 -> V_65 = 0 ;
V_21 -> V_61 = 0 ;
}
F_9 ( & V_21 -> V_33 , V_32 ) ;
}
int F_42 ( struct V_20 * V_21 )
{
return V_21 -> V_48 ;
}
int F_43 ( struct V_20 * V_21 , unsigned int V_17 )
{
int V_42 ;
if ( V_21 -> V_48 == V_17 ) return 0 ;
F_33 ( & V_21 -> V_53 ) ; do {
V_21 -> V_48 = V_17 ;
V_42 = F_26 ( V_21 ) ;
} while( 0 ); F_34 ( & V_21 -> V_53 ) ;
return V_42 ;
}
struct V_7 * F_44 ( struct V_20 * V_21 )
{
struct V_49 * V_50 = V_21 -> V_36 . V_52 ;
if ( V_50 == & V_21 -> V_36 ) return NULL ;
return F_28 ( V_50 , struct V_7 , V_30 ) ;
}
struct V_7 * F_45 ( struct V_20 * V_21 )
{
struct V_49 * V_50 = V_21 -> V_35 . V_52 ;
if ( V_50 == & V_21 -> V_35 ) return NULL ;
return F_28 ( V_50 , struct V_7 , V_30 ) ;
}
struct V_7 * F_46 ( struct V_20 * V_21 , int V_12 )
{
if ( V_12 < 0 ) return NULL ;
if ( V_12 >= V_21 -> V_44 ) return NULL ;
return V_21 -> V_47 [ V_12 ] ;
}
int F_47 ( struct V_20 * V_21 )
{
return V_21 -> V_27 ;
}
void F_48 ( struct V_20 * V_21 )
{
struct V_7 * V_8 ;
F_33 ( & V_21 -> V_53 ) ; do {
F_27 ( V_21 ) ;
while ( ( V_8 = F_45 ( V_21 ) ) != NULL ) {
F_12 ( V_8 ) ;
}
if ( V_21 -> V_44 != V_21 -> V_48 ) {
F_26 ( V_21 ) ;
}
} while( 0 ); F_34 ( & V_21 -> V_53 ) ;
}
int F_49 ( struct V_7 * V_8 )
{
#undef V_81
#ifdef V_81
unsigned int V_82 ;
unsigned int V_83 ;
#endif
int V_42 = 0 ;
struct V_20 * V_21 ;
if ( ! V_8 ) return - V_84 ;
V_21 = V_8 -> V_14 ;
F_33 ( & V_21 -> V_53 ) ; do {
F_14 ( V_8 ) ;
if ( ! V_21 -> V_70 ) {
V_42 = - V_85 ;
break;
}
F_13 ( V_8 ) ;
#ifdef V_81
for ( V_82 = 0 ; V_82 < ( V_8 -> V_24 ) / 4 ; V_82 ++ ) {
V_83 = V_8 -> V_12 << 24 ;
V_83 |= V_82 ;
( ( unsigned int * ) ( V_8 -> V_86 ) ) [ V_82 ] = V_83 ;
}
#endif
V_8 -> V_13 = - V_87 ;
F_50 ( V_8 -> V_15 ,
V_21 -> V_70 ,
F_51 ( V_21 -> V_70 , V_21 -> V_71 ) ,
V_8 -> V_86 ,
V_8 -> V_24 ,
F_35 ,
V_8 ) ;
F_52 ( V_8 -> V_15 , V_40 ) ;
} while( 0 ); F_34 ( & V_21 -> V_53 ) ;
return V_42 ;
}
int F_53 ( struct V_7 * V_8 , void * V_86 , unsigned int V_17 )
{
int V_42 = 0 ;
unsigned long V_32 ;
struct V_20 * V_21 ;
if ( ! V_8 ) return - V_84 ;
V_21 = V_8 -> V_14 ;
F_33 ( & V_21 -> V_53 ) ; do {
F_8 ( & V_21 -> V_33 , V_32 ) ;
if ( V_8 -> V_11 != V_4 ) {
V_42 = - V_88 ;
} else {
V_8 -> V_86 = V_86 ;
V_8 -> V_14 -> V_23 -= V_8 -> V_24 ;
V_8 -> V_24 = V_17 ;
V_8 -> V_14 -> V_23 += V_8 -> V_24 ;
F_3 ( V_31 ,
L_29
L_30 ,
F_1 (
V_4 ) ,
V_8 -> V_14 -> V_23 , V_8 -> V_14 -> V_22 ) ;
}
F_9 ( & V_21 -> V_33 , V_32 ) ;
} while( 0 ); F_34 ( & V_21 -> V_53 ) ;
return V_42 ;
}
unsigned int F_54 ( struct V_7 * V_8 )
{
return V_8 -> V_29 ;
}
int F_55 ( struct V_7 * V_8 )
{
return V_8 -> V_13 ;
}
int F_56 ( struct V_7 * V_8 )
{
return V_8 -> V_12 ;
}
