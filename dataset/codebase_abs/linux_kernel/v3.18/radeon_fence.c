static void F_1 ( struct V_1 * V_2 , T_1 V_3 , int V_4 )
{
struct V_5 * V_6 = & V_2 -> V_7 [ V_4 ] ;
if ( F_2 ( V_2 -> V_8 . V_9 || ! V_6 -> V_10 ) ) {
if ( V_6 -> V_11 ) {
* V_6 -> V_11 = F_3 ( V_3 ) ;
}
} else {
F_4 ( V_6 -> V_10 , V_3 ) ;
}
}
static T_1 F_5 ( struct V_1 * V_2 , int V_4 )
{
struct V_5 * V_6 = & V_2 -> V_7 [ V_4 ] ;
T_1 V_3 = 0 ;
if ( F_2 ( V_2 -> V_8 . V_9 || ! V_6 -> V_10 ) ) {
if ( V_6 -> V_11 ) {
V_3 = F_6 ( * V_6 -> V_11 ) ;
} else {
V_3 = F_7 ( F_8 ( & V_6 -> V_12 ) ) ;
}
} else {
V_3 = F_9 ( V_6 -> V_10 ) ;
}
return V_3 ;
}
static void F_10 ( struct V_1 * V_2 , int V_4 )
{
F_11 ( V_13 ,
& V_2 -> V_7 [ V_4 ] . V_14 ,
V_15 ) ;
}
int F_12 ( struct V_1 * V_2 ,
struct V_16 * * V_17 ,
int V_4 )
{
T_2 V_3 = ++ V_2 -> V_7 [ V_4 ] . V_18 [ V_4 ] ;
* V_17 = F_13 ( sizeof( struct V_16 ) , V_19 ) ;
if ( ( * V_17 ) == NULL ) {
return - V_20 ;
}
( * V_17 ) -> V_2 = V_2 ;
( * V_17 ) -> V_3 = V_3 ;
( * V_17 ) -> V_4 = V_4 ;
F_14 ( & ( * V_17 ) -> V_21 , & V_22 ,
& V_2 -> V_23 . V_24 , V_2 -> V_25 + V_4 , V_3 ) ;
F_15 ( V_2 , V_4 , * V_17 ) ;
F_16 ( V_2 -> V_26 , V_4 , ( * V_17 ) -> V_3 ) ;
F_10 ( V_2 , V_4 ) ;
return 0 ;
}
static int F_17 ( T_3 * V_27 , unsigned V_28 , int V_29 , void * V_30 )
{
struct V_16 * V_17 ;
T_2 V_3 ;
V_17 = F_18 ( V_27 , struct V_16 , V_31 ) ;
V_3 = F_8 ( & V_17 -> V_2 -> V_7 [ V_17 -> V_4 ] . V_12 ) ;
if ( V_3 >= V_17 -> V_3 ) {
int V_32 = F_19 ( & V_17 -> V_21 ) ;
if ( ! V_32 )
F_20 ( & V_17 -> V_21 , L_1 ) ;
else
F_20 ( & V_17 -> V_21 , L_2 ) ;
F_21 ( V_17 -> V_2 , V_17 -> V_4 ) ;
F_22 ( & V_17 -> V_2 -> V_23 , & V_17 -> V_31 ) ;
F_23 ( & V_17 -> V_21 ) ;
} else
F_20 ( & V_17 -> V_21 , L_3 ) ;
return 0 ;
}
static bool F_24 ( struct V_1 * V_2 , int V_4 )
{
T_4 V_3 , V_12 , V_33 ;
unsigned V_34 = 0 ;
bool V_35 = false ;
V_12 = F_8 ( & V_2 -> V_7 [ V_4 ] . V_12 ) ;
do {
V_33 = V_2 -> V_7 [ V_4 ] . V_18 [ V_4 ] ;
V_3 = F_5 ( V_2 , V_4 ) ;
V_3 |= V_12 & 0xffffffff00000000LL ;
if ( V_3 < V_12 ) {
V_3 &= 0xffffffff ;
V_3 |= V_33 & 0xffffffff00000000LL ;
}
if ( V_3 <= V_12 || V_3 > V_33 ) {
break;
}
V_35 = true ;
V_12 = V_3 ;
if ( ( V_34 ++ ) > 10 ) {
break;
}
} while ( F_25 ( & V_2 -> V_7 [ V_4 ] . V_12 , V_3 ) > V_3 );
if ( V_3 < V_33 )
F_10 ( V_2 , V_4 ) ;
return V_35 ;
}
static void F_26 ( struct V_36 * V_37 )
{
struct V_5 * V_7 ;
struct V_1 * V_2 ;
int V_4 ;
V_7 = F_18 ( V_37 , struct V_5 ,
V_14 . V_37 ) ;
V_2 = V_7 -> V_2 ;
V_4 = V_7 - & V_2 -> V_7 [ 0 ] ;
if ( ! F_27 ( & V_2 -> V_38 ) ) {
F_10 ( V_2 , V_4 ) ;
return;
}
if ( V_7 -> V_39 && V_2 -> V_26 -> V_40 ) {
unsigned long V_41 ;
V_7 -> V_39 = false ;
F_28 ( & V_2 -> V_42 . V_24 , V_41 ) ;
F_29 ( V_2 ) ;
F_30 ( & V_2 -> V_42 . V_24 , V_41 ) ;
}
if ( F_24 ( V_2 , V_4 ) )
F_31 ( & V_2 -> V_23 ) ;
else if ( F_32 ( V_2 , V_4 , & V_2 -> V_4 [ V_4 ] ) ) {
F_33 ( V_2 -> V_43 , L_4
L_5 ,
( T_4 ) F_8 ( & V_7 -> V_12 ) ,
V_7 -> V_18 [ V_4 ] , V_4 ) ;
V_2 -> V_44 = true ;
F_31 ( & V_2 -> V_23 ) ;
}
F_34 ( & V_2 -> V_38 ) ;
}
void F_35 ( struct V_1 * V_2 , int V_4 )
{
if ( F_24 ( V_2 , V_4 ) )
F_31 ( & V_2 -> V_23 ) ;
}
static bool F_36 ( struct V_1 * V_2 ,
T_2 V_3 , unsigned V_4 )
{
if ( F_8 ( & V_2 -> V_7 [ V_4 ] . V_12 ) >= V_3 ) {
return true ;
}
F_35 ( V_2 , V_4 ) ;
if ( F_8 ( & V_2 -> V_7 [ V_4 ] . V_12 ) >= V_3 ) {
return true ;
}
return false ;
}
static bool F_37 ( struct V_17 * V_45 )
{
struct V_16 * V_17 = F_38 ( V_45 ) ;
struct V_1 * V_2 = V_17 -> V_2 ;
unsigned V_4 = V_17 -> V_4 ;
T_2 V_3 = V_17 -> V_3 ;
if ( F_8 ( & V_2 -> V_7 [ V_4 ] . V_12 ) >= V_3 ) {
return true ;
}
if ( F_27 ( & V_2 -> V_38 ) ) {
F_35 ( V_2 , V_4 ) ;
F_34 ( & V_2 -> V_38 ) ;
if ( F_8 ( & V_2 -> V_7 [ V_4 ] . V_12 ) >= V_3 ) {
return true ;
}
}
return false ;
}
static bool F_39 ( struct V_17 * V_45 )
{
struct V_16 * V_17 = F_38 ( V_45 ) ;
struct V_1 * V_2 = V_17 -> V_2 ;
if ( F_8 ( & V_2 -> V_7 [ V_17 -> V_4 ] . V_12 ) >= V_17 -> V_3 )
return false ;
if ( F_27 ( & V_2 -> V_38 ) ) {
F_40 ( V_2 , V_17 -> V_4 ) ;
if ( F_24 ( V_2 , V_17 -> V_4 ) )
F_41 ( & V_2 -> V_23 ) ;
if ( F_8 ( & V_2 -> V_7 [ V_17 -> V_4 ] . V_12 ) >= V_17 -> V_3 ) {
F_21 ( V_2 , V_17 -> V_4 ) ;
F_34 ( & V_2 -> V_38 ) ;
return false ;
}
F_34 ( & V_2 -> V_38 ) ;
} else {
if ( F_42 ( V_2 , V_17 -> V_4 ) )
V_2 -> V_7 [ V_17 -> V_4 ] . V_39 = true ;
F_10 ( V_2 , V_17 -> V_4 ) ;
}
V_17 -> V_31 . V_29 = 0 ;
V_17 -> V_31 . V_46 = NULL ;
V_17 -> V_31 . V_47 = F_17 ;
F_43 ( & V_2 -> V_23 , & V_17 -> V_31 ) ;
F_44 ( V_45 ) ;
F_20 ( & V_17 -> V_21 , L_6 , V_17 -> V_4 ) ;
return true ;
}
bool F_45 ( struct V_16 * V_17 )
{
if ( ! V_17 )
return true ;
if ( F_36 ( V_17 -> V_2 , V_17 -> V_3 , V_17 -> V_4 ) ) {
int V_32 ;
V_32 = F_46 ( & V_17 -> V_21 ) ;
if ( ! V_32 )
F_20 ( & V_17 -> V_21 , L_7 ) ;
return true ;
}
return false ;
}
static bool F_47 ( struct V_1 * V_2 , T_2 * V_3 )
{
unsigned V_48 ;
for ( V_48 = 0 ; V_48 < V_49 ; ++ V_48 ) {
if ( V_3 [ V_48 ] && F_36 ( V_2 , V_3 [ V_48 ] , V_48 ) )
return true ;
}
return false ;
}
static long F_48 ( struct V_1 * V_2 ,
T_2 * V_50 , bool V_51 ,
long V_52 )
{
long V_53 ;
int V_48 ;
if ( F_47 ( V_2 , V_50 ) )
return V_52 ;
for ( V_48 = 0 ; V_48 < V_49 ; ++ V_48 ) {
if ( ! V_50 [ V_48 ] )
continue;
F_49 ( V_2 -> V_26 , V_48 , V_50 [ V_48 ] ) ;
F_40 ( V_2 , V_48 ) ;
}
if ( V_51 ) {
V_53 = F_50 ( V_2 -> V_23 , (
F_47 ( V_2 , V_50 )
|| V_2 -> V_44 ) , V_52 ) ;
} else {
V_53 = F_51 ( V_2 -> V_23 , (
F_47 ( V_2 , V_50 )
|| V_2 -> V_44 ) , V_52 ) ;
}
if ( V_2 -> V_44 )
V_53 = - V_54 ;
for ( V_48 = 0 ; V_48 < V_49 ; ++ V_48 ) {
if ( ! V_50 [ V_48 ] )
continue;
F_21 ( V_2 , V_48 ) ;
F_52 ( V_2 -> V_26 , V_48 , V_50 [ V_48 ] ) ;
}
return V_53 ;
}
int F_53 ( struct V_16 * V_17 , bool V_51 )
{
T_4 V_3 [ V_49 ] = {} ;
long V_53 ;
if ( F_54 ( ! F_38 ( & V_17 -> V_21 ) ) )
return F_55 ( & V_17 -> V_21 , V_51 ) ;
V_3 [ V_17 -> V_4 ] = V_17 -> V_3 ;
V_53 = F_48 ( V_17 -> V_2 , V_3 , V_51 , V_55 ) ;
if ( V_53 < 0 ) {
return V_53 ;
}
V_53 = F_46 ( & V_17 -> V_21 ) ;
if ( ! V_53 )
F_20 ( & V_17 -> V_21 , L_8 ) ;
return 0 ;
}
int F_56 ( struct V_1 * V_2 ,
struct V_16 * * V_56 ,
bool V_51 )
{
T_4 V_3 [ V_49 ] ;
unsigned V_48 , V_57 = 0 ;
long V_53 ;
for ( V_48 = 0 ; V_48 < V_49 ; ++ V_48 ) {
V_3 [ V_48 ] = 0 ;
if ( ! V_56 [ V_48 ] ) {
continue;
}
V_3 [ V_48 ] = V_56 [ V_48 ] -> V_3 ;
++ V_57 ;
}
if ( V_57 == 0 )
return - V_58 ;
V_53 = F_48 ( V_2 , V_3 , V_51 , V_55 ) ;
if ( V_53 < 0 ) {
return V_53 ;
}
return 0 ;
}
int F_57 ( struct V_1 * V_2 , int V_4 )
{
T_4 V_3 [ V_49 ] = {} ;
long V_53 ;
V_3 [ V_4 ] = F_8 ( & V_2 -> V_7 [ V_4 ] . V_12 ) + 1ULL ;
if ( V_3 [ V_4 ] >= V_2 -> V_7 [ V_4 ] . V_18 [ V_4 ] ) {
return - V_58 ;
}
V_53 = F_48 ( V_2 , V_3 , false , V_55 ) ;
if ( V_53 < 0 )
return V_53 ;
return 0 ;
}
int F_58 ( struct V_1 * V_2 , int V_4 )
{
T_4 V_3 [ V_49 ] = {} ;
long V_53 ;
V_3 [ V_4 ] = V_2 -> V_7 [ V_4 ] . V_18 [ V_4 ] ;
if ( ! V_3 [ V_4 ] )
return 0 ;
V_53 = F_48 ( V_2 , V_3 , false , V_55 ) ;
if ( V_53 < 0 ) {
if ( V_53 == - V_54 )
return - V_54 ;
F_59 ( V_2 -> V_43 , L_9 ,
V_4 , V_53 ) ;
}
return 0 ;
}
struct V_16 * F_60 ( struct V_16 * V_17 )
{
F_44 ( & V_17 -> V_21 ) ;
return V_17 ;
}
void F_61 ( struct V_16 * * V_17 )
{
struct V_16 * V_59 = * V_17 ;
* V_17 = NULL ;
if ( V_59 ) {
F_23 ( & V_59 -> V_21 ) ;
}
}
unsigned F_62 ( struct V_1 * V_2 , int V_4 )
{
T_4 V_60 ;
F_35 ( V_2 , V_4 ) ;
V_60 = V_2 -> V_7 [ V_4 ] . V_18 [ V_4 ]
- F_8 ( & V_2 -> V_7 [ V_4 ] . V_12 ) ;
if ( V_60 > 0x10000000 ) {
V_60 = 0x10000000 ;
}
return ( unsigned ) V_60 ;
}
bool F_63 ( struct V_16 * V_17 , int V_61 )
{
struct V_5 * V_62 ;
if ( ! V_17 ) {
return false ;
}
if ( V_17 -> V_4 == V_61 ) {
return false ;
}
V_62 = & V_17 -> V_2 -> V_7 [ V_61 ] ;
if ( V_17 -> V_3 <= V_62 -> V_18 [ V_17 -> V_4 ] ) {
return false ;
}
return true ;
}
void F_64 ( struct V_16 * V_17 , int V_61 )
{
struct V_5 * V_63 , * V_64 ;
unsigned V_48 ;
if ( ! V_17 ) {
return;
}
if ( V_17 -> V_4 == V_61 ) {
return;
}
V_64 = & V_17 -> V_2 -> V_7 [ V_17 -> V_4 ] ;
V_63 = & V_17 -> V_2 -> V_7 [ V_61 ] ;
for ( V_48 = 0 ; V_48 < V_49 ; ++ V_48 ) {
if ( V_48 == V_61 ) {
continue;
}
V_63 -> V_18 [ V_48 ] = F_65 ( V_63 -> V_18 [ V_48 ] , V_64 -> V_18 [ V_48 ] ) ;
}
}
int F_66 ( struct V_1 * V_2 , int V_4 )
{
T_4 V_65 ;
int V_53 ;
F_67 ( V_2 , V_2 -> V_7 [ V_4 ] . V_10 ) ;
if ( V_2 -> V_8 . V_66 || ! F_68 ( V_2 , & V_2 -> V_4 [ V_4 ] ) ) {
V_2 -> V_7 [ V_4 ] . V_10 = 0 ;
if ( V_4 != V_67 ) {
V_65 = V_68 + V_4 * 4 ;
V_2 -> V_7 [ V_4 ] . V_11 = & V_2 -> V_8 . V_8 [ V_65 / 4 ] ;
V_2 -> V_7 [ V_4 ] . V_69 = V_2 -> V_8 . V_69 +
V_65 ;
} else {
V_65 = F_69 ( V_2 -> V_70 -> V_71 , 8 ) ;
V_2 -> V_7 [ V_4 ] . V_11 = V_2 -> V_72 . V_11 + V_65 ;
V_2 -> V_7 [ V_4 ] . V_69 = V_2 -> V_72 . V_69 + V_65 ;
}
} else {
V_53 = F_70 ( V_2 , & V_2 -> V_7 [ V_4 ] . V_10 ) ;
if ( V_53 ) {
F_59 ( V_2 -> V_43 , L_10 ) ;
return V_53 ;
}
V_65 = V_73 +
V_2 -> V_7 [ V_4 ] . V_10 -
V_2 -> V_74 . V_75 ;
V_2 -> V_7 [ V_4 ] . V_11 = & V_2 -> V_8 . V_8 [ V_65 / 4 ] ;
V_2 -> V_7 [ V_4 ] . V_69 = V_2 -> V_8 . V_69 + V_65 ;
}
F_1 ( V_2 , F_8 ( & V_2 -> V_7 [ V_4 ] . V_12 ) , V_4 ) ;
V_2 -> V_7 [ V_4 ] . V_76 = true ;
F_71 ( V_2 -> V_43 , L_11 ,
V_4 , V_2 -> V_7 [ V_4 ] . V_69 , V_2 -> V_7 [ V_4 ] . V_11 ) ;
return 0 ;
}
static void F_72 ( struct V_1 * V_2 , int V_4 )
{
int V_48 ;
V_2 -> V_7 [ V_4 ] . V_10 = - 1 ;
V_2 -> V_7 [ V_4 ] . V_11 = NULL ;
V_2 -> V_7 [ V_4 ] . V_69 = 0 ;
for ( V_48 = 0 ; V_48 < V_49 ; ++ V_48 )
V_2 -> V_7 [ V_4 ] . V_18 [ V_48 ] = 0 ;
F_73 ( & V_2 -> V_7 [ V_4 ] . V_12 , 0 ) ;
V_2 -> V_7 [ V_4 ] . V_76 = false ;
F_74 ( & V_2 -> V_7 [ V_4 ] . V_14 ,
F_26 ) ;
V_2 -> V_7 [ V_4 ] . V_2 = V_2 ;
}
int F_75 ( struct V_1 * V_2 )
{
int V_4 ;
F_76 ( & V_2 -> V_23 ) ;
for ( V_4 = 0 ; V_4 < V_49 ; V_4 ++ ) {
F_72 ( V_2 , V_4 ) ;
}
if ( F_77 ( V_2 ) ) {
F_59 ( V_2 -> V_43 , L_12 ) ;
}
return 0 ;
}
void F_78 ( struct V_1 * V_2 )
{
int V_4 , V_53 ;
F_79 ( & V_2 -> V_77 ) ;
for ( V_4 = 0 ; V_4 < V_49 ; V_4 ++ ) {
if ( ! V_2 -> V_7 [ V_4 ] . V_76 )
continue;
V_53 = F_58 ( V_2 , V_4 ) ;
if ( V_53 ) {
F_80 ( V_2 , V_4 ) ;
}
F_81 ( & V_2 -> V_7 [ V_4 ] . V_14 ) ;
F_31 ( & V_2 -> V_23 ) ;
F_67 ( V_2 , V_2 -> V_7 [ V_4 ] . V_10 ) ;
V_2 -> V_7 [ V_4 ] . V_76 = false ;
}
F_82 ( & V_2 -> V_77 ) ;
}
void F_80 ( struct V_1 * V_2 , int V_4 )
{
if ( V_2 -> V_7 [ V_4 ] . V_76 ) {
F_1 ( V_2 , V_2 -> V_7 [ V_4 ] . V_18 [ V_4 ] , V_4 ) ;
F_81 ( & V_2 -> V_7 [ V_4 ] . V_14 ) ;
}
}
static int F_83 ( struct V_78 * V_79 , void * V_80 )
{
struct V_81 * V_82 = (struct V_81 * ) V_79 -> V_46 ;
struct V_83 * V_43 = V_82 -> V_84 -> V_43 ;
struct V_1 * V_2 = V_43 -> V_85 ;
int V_48 , V_86 ;
for ( V_48 = 0 ; V_48 < V_49 ; ++ V_48 ) {
if ( ! V_2 -> V_7 [ V_48 ] . V_76 )
continue;
F_35 ( V_2 , V_48 ) ;
F_84 ( V_79 , L_13 , V_48 ) ;
F_84 ( V_79 , L_14 ,
( unsigned long long ) F_8 ( & V_2 -> V_7 [ V_48 ] . V_12 ) ) ;
F_84 ( V_79 , L_15 ,
V_2 -> V_7 [ V_48 ] . V_18 [ V_48 ] ) ;
for ( V_86 = 0 ; V_86 < V_49 ; ++ V_86 ) {
if ( V_48 != V_86 && V_2 -> V_7 [ V_86 ] . V_76 )
F_84 ( V_79 , L_16 ,
V_86 , V_2 -> V_7 [ V_48 ] . V_18 [ V_86 ] ) ;
}
}
return 0 ;
}
static int F_85 ( struct V_78 * V_79 , void * V_80 )
{
struct V_81 * V_82 = (struct V_81 * ) V_79 -> V_46 ;
struct V_83 * V_43 = V_82 -> V_84 -> V_43 ;
struct V_1 * V_2 = V_43 -> V_85 ;
F_86 ( & V_2 -> V_38 ) ;
F_84 ( V_79 , L_17 , V_2 -> V_44 ) ;
V_2 -> V_44 = true ;
F_31 ( & V_2 -> V_23 ) ;
F_34 ( & V_2 -> V_38 ) ;
return 0 ;
}
int F_77 ( struct V_1 * V_2 )
{
#if F_87 ( V_87 )
return F_88 ( V_2 , V_88 , 2 ) ;
#else
return 0 ;
#endif
}
static const char * F_89 ( struct V_17 * V_17 )
{
return L_18 ;
}
static const char * F_90 ( struct V_17 * V_45 )
{
struct V_16 * V_17 = F_38 ( V_45 ) ;
switch ( V_17 -> V_4 ) {
case V_89 : return L_19 ;
case V_90 : return L_20 ;
case V_91 : return L_21 ;
case V_92 : return L_22 ;
case V_93 : return L_23 ;
case V_67 : return L_24 ;
case V_94 : return L_25 ;
case V_95 : return L_26 ;
default: F_54 ( 1 ) ; return L_27 ;
}
}
static inline bool F_91 ( struct V_16 * V_17 )
{
return F_92 ( V_96 , & V_17 -> V_21 . V_29 ) ;
}
static signed long F_93 ( struct V_17 * V_45 , bool V_51 ,
signed long V_97 )
{
struct V_16 * V_17 = F_38 ( V_45 ) ;
struct V_1 * V_2 = V_17 -> V_2 ;
bool V_98 ;
F_94 ( & V_17 -> V_21 ) ;
if ( V_51 )
V_97 = F_50 ( V_2 -> V_23 ,
( ( V_98 = F_91 ( V_17 ) ) ||
V_2 -> V_44 ) , V_97 ) ;
else
V_97 = F_51 ( V_2 -> V_23 ,
( ( V_98 = F_91 ( V_17 ) ) ||
V_2 -> V_44 ) , V_97 ) ;
if ( V_97 > 0 && ! V_98 )
return - V_54 ;
return V_97 ;
}
