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
T_2 V_3 ;
* V_17 = F_13 ( sizeof( struct V_16 ) , V_18 ) ;
if ( ( * V_17 ) == NULL ) {
return - V_19 ;
}
( * V_17 ) -> V_2 = V_2 ;
( * V_17 ) -> V_3 = V_3 = ++ V_2 -> V_7 [ V_4 ] . V_20 [ V_4 ] ;
( * V_17 ) -> V_4 = V_4 ;
( * V_17 ) -> V_21 = false ;
F_14 ( & ( * V_17 ) -> V_22 , & V_23 ,
& V_2 -> V_24 . V_25 , V_2 -> V_26 + V_4 , V_3 ) ;
F_15 ( V_2 , V_4 , * V_17 ) ;
F_16 ( V_2 -> V_27 , V_4 , ( * V_17 ) -> V_3 ) ;
F_10 ( V_2 , V_4 ) ;
return 0 ;
}
static int F_17 ( T_3 * V_28 , unsigned V_29 , int V_30 , void * V_31 )
{
struct V_16 * V_17 ;
T_2 V_3 ;
V_17 = F_18 ( V_28 , struct V_16 , V_32 ) ;
V_3 = F_8 ( & V_17 -> V_2 -> V_7 [ V_17 -> V_4 ] . V_12 ) ;
if ( V_3 >= V_17 -> V_3 ) {
int V_33 = F_19 ( & V_17 -> V_22 ) ;
if ( ! V_33 )
F_20 ( & V_17 -> V_22 , L_1 ) ;
else
F_20 ( & V_17 -> V_22 , L_2 ) ;
F_21 ( V_17 -> V_2 , V_17 -> V_4 ) ;
F_22 ( & V_17 -> V_2 -> V_24 , & V_17 -> V_32 ) ;
F_23 ( & V_17 -> V_22 ) ;
} else
F_20 ( & V_17 -> V_22 , L_3 ) ;
return 0 ;
}
static bool F_24 ( struct V_1 * V_2 , int V_4 )
{
T_4 V_3 , V_12 , V_34 ;
unsigned V_35 = 0 ;
bool V_36 = false ;
V_12 = F_8 ( & V_2 -> V_7 [ V_4 ] . V_12 ) ;
do {
V_34 = V_2 -> V_7 [ V_4 ] . V_20 [ V_4 ] ;
V_3 = F_5 ( V_2 , V_4 ) ;
V_3 |= V_12 & 0xffffffff00000000LL ;
if ( V_3 < V_12 ) {
V_3 &= 0xffffffff ;
V_3 |= V_34 & 0xffffffff00000000LL ;
}
if ( V_3 <= V_12 || V_3 > V_34 ) {
break;
}
V_36 = true ;
V_12 = V_3 ;
if ( ( V_35 ++ ) > 10 ) {
break;
}
} while ( F_25 ( & V_2 -> V_7 [ V_4 ] . V_12 , V_3 ) > V_3 );
if ( V_3 < V_34 )
F_10 ( V_2 , V_4 ) ;
return V_36 ;
}
static void F_26 ( struct V_37 * V_38 )
{
struct V_5 * V_7 ;
struct V_1 * V_2 ;
int V_4 ;
V_7 = F_18 ( V_38 , struct V_5 ,
V_14 . V_38 ) ;
V_2 = V_7 -> V_2 ;
V_4 = V_7 - & V_2 -> V_7 [ 0 ] ;
if ( ! F_27 ( & V_2 -> V_39 ) ) {
F_10 ( V_2 , V_4 ) ;
return;
}
if ( V_7 -> V_40 && V_2 -> V_27 -> V_41 ) {
unsigned long V_42 ;
V_7 -> V_40 = false ;
F_28 ( & V_2 -> V_43 . V_25 , V_42 ) ;
F_29 ( V_2 ) ;
F_30 ( & V_2 -> V_43 . V_25 , V_42 ) ;
}
if ( F_24 ( V_2 , V_4 ) )
F_31 ( & V_2 -> V_24 ) ;
else if ( F_32 ( V_2 , V_4 , & V_2 -> V_4 [ V_4 ] ) ) {
F_33 ( V_2 -> V_44 , L_4
L_5 ,
( T_4 ) F_8 ( & V_7 -> V_12 ) ,
V_7 -> V_20 [ V_4 ] , V_4 ) ;
V_2 -> V_45 = true ;
F_31 ( & V_2 -> V_24 ) ;
}
F_34 ( & V_2 -> V_39 ) ;
}
void F_35 ( struct V_1 * V_2 , int V_4 )
{
if ( F_24 ( V_2 , V_4 ) )
F_31 ( & V_2 -> V_24 ) ;
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
static bool F_37 ( struct V_17 * V_46 )
{
struct V_16 * V_17 = F_38 ( V_46 ) ;
struct V_1 * V_2 = V_17 -> V_2 ;
unsigned V_4 = V_17 -> V_4 ;
T_2 V_3 = V_17 -> V_3 ;
if ( F_8 ( & V_2 -> V_7 [ V_4 ] . V_12 ) >= V_3 ) {
return true ;
}
if ( F_27 ( & V_2 -> V_39 ) ) {
F_35 ( V_2 , V_4 ) ;
F_34 ( & V_2 -> V_39 ) ;
if ( F_8 ( & V_2 -> V_7 [ V_4 ] . V_12 ) >= V_3 ) {
return true ;
}
}
return false ;
}
static bool F_39 ( struct V_17 * V_46 )
{
struct V_16 * V_17 = F_38 ( V_46 ) ;
struct V_1 * V_2 = V_17 -> V_2 ;
if ( F_8 ( & V_2 -> V_7 [ V_17 -> V_4 ] . V_12 ) >= V_17 -> V_3 )
return false ;
if ( F_27 ( & V_2 -> V_39 ) ) {
F_40 ( V_2 , V_17 -> V_4 ) ;
if ( F_24 ( V_2 , V_17 -> V_4 ) )
F_41 ( & V_2 -> V_24 ) ;
if ( F_8 ( & V_2 -> V_7 [ V_17 -> V_4 ] . V_12 ) >= V_17 -> V_3 ) {
F_21 ( V_2 , V_17 -> V_4 ) ;
F_34 ( & V_2 -> V_39 ) ;
return false ;
}
F_34 ( & V_2 -> V_39 ) ;
} else {
if ( F_42 ( V_2 , V_17 -> V_4 ) )
V_2 -> V_7 [ V_17 -> V_4 ] . V_40 = true ;
F_10 ( V_2 , V_17 -> V_4 ) ;
}
V_17 -> V_32 . V_30 = 0 ;
V_17 -> V_32 . V_47 = NULL ;
V_17 -> V_32 . V_48 = F_17 ;
F_43 ( & V_2 -> V_24 , & V_17 -> V_32 ) ;
F_44 ( V_46 ) ;
F_20 ( & V_17 -> V_22 , L_6 , V_17 -> V_4 ) ;
return true ;
}
bool F_45 ( struct V_16 * V_17 )
{
if ( ! V_17 )
return true ;
if ( F_36 ( V_17 -> V_2 , V_17 -> V_3 , V_17 -> V_4 ) ) {
int V_33 ;
V_33 = F_46 ( & V_17 -> V_22 ) ;
if ( ! V_33 )
F_20 ( & V_17 -> V_22 , L_7 ) ;
return true ;
}
return false ;
}
static bool F_47 ( struct V_1 * V_2 , T_2 * V_3 )
{
unsigned V_49 ;
for ( V_49 = 0 ; V_49 < V_50 ; ++ V_49 ) {
if ( V_3 [ V_49 ] && F_36 ( V_2 , V_3 [ V_49 ] , V_49 ) )
return true ;
}
return false ;
}
static long F_48 ( struct V_1 * V_2 ,
T_2 * V_51 , bool V_52 ,
long V_53 )
{
long V_54 ;
int V_49 ;
if ( F_47 ( V_2 , V_51 ) )
return V_53 ;
for ( V_49 = 0 ; V_49 < V_50 ; ++ V_49 ) {
if ( ! V_51 [ V_49 ] )
continue;
F_49 ( V_2 -> V_27 , V_49 , V_51 [ V_49 ] ) ;
F_40 ( V_2 , V_49 ) ;
}
if ( V_52 ) {
V_54 = F_50 ( V_2 -> V_24 , (
F_47 ( V_2 , V_51 )
|| V_2 -> V_45 ) , V_53 ) ;
} else {
V_54 = F_51 ( V_2 -> V_24 , (
F_47 ( V_2 , V_51 )
|| V_2 -> V_45 ) , V_53 ) ;
}
if ( V_2 -> V_45 )
V_54 = - V_55 ;
for ( V_49 = 0 ; V_49 < V_50 ; ++ V_49 ) {
if ( ! V_51 [ V_49 ] )
continue;
F_21 ( V_2 , V_49 ) ;
F_52 ( V_2 -> V_27 , V_49 , V_51 [ V_49 ] ) ;
}
return V_54 ;
}
long F_53 ( struct V_16 * V_17 , bool V_52 , long V_53 )
{
T_4 V_3 [ V_50 ] = {} ;
long V_54 ;
int V_56 ;
if ( F_54 ( ! F_38 ( & V_17 -> V_22 ) ) )
return F_55 ( & V_17 -> V_22 , V_52 ) ;
V_3 [ V_17 -> V_4 ] = V_17 -> V_3 ;
V_54 = F_48 ( V_17 -> V_2 , V_3 , V_52 , V_53 ) ;
if ( V_54 <= 0 ) {
return V_54 ;
}
V_56 = F_46 ( & V_17 -> V_22 ) ;
if ( ! V_56 )
F_20 ( & V_17 -> V_22 , L_8 ) ;
return V_54 ;
}
int F_56 ( struct V_16 * V_17 , bool V_52 )
{
long V_54 = F_53 ( V_17 , V_52 , V_57 ) ;
if ( V_54 > 0 ) {
return 0 ;
} else {
return V_54 ;
}
}
int F_57 ( struct V_1 * V_2 ,
struct V_16 * * V_58 ,
bool V_52 )
{
T_4 V_3 [ V_50 ] ;
unsigned V_49 , V_59 = 0 ;
long V_54 ;
for ( V_49 = 0 ; V_49 < V_50 ; ++ V_49 ) {
V_3 [ V_49 ] = 0 ;
if ( ! V_58 [ V_49 ] ) {
continue;
}
V_3 [ V_49 ] = V_58 [ V_49 ] -> V_3 ;
++ V_59 ;
}
if ( V_59 == 0 )
return - V_60 ;
V_54 = F_48 ( V_2 , V_3 , V_52 , V_57 ) ;
if ( V_54 < 0 ) {
return V_54 ;
}
return 0 ;
}
int F_58 ( struct V_1 * V_2 , int V_4 )
{
T_4 V_3 [ V_50 ] = {} ;
long V_54 ;
V_3 [ V_4 ] = F_8 ( & V_2 -> V_7 [ V_4 ] . V_12 ) + 1ULL ;
if ( V_3 [ V_4 ] >= V_2 -> V_7 [ V_4 ] . V_20 [ V_4 ] ) {
return - V_60 ;
}
V_54 = F_48 ( V_2 , V_3 , false , V_57 ) ;
if ( V_54 < 0 )
return V_54 ;
return 0 ;
}
int F_59 ( struct V_1 * V_2 , int V_4 )
{
T_4 V_3 [ V_50 ] = {} ;
long V_54 ;
V_3 [ V_4 ] = V_2 -> V_7 [ V_4 ] . V_20 [ V_4 ] ;
if ( ! V_3 [ V_4 ] )
return 0 ;
V_54 = F_48 ( V_2 , V_3 , false , V_57 ) ;
if ( V_54 < 0 ) {
if ( V_54 == - V_55 )
return - V_55 ;
F_60 ( V_2 -> V_44 , L_9 ,
V_4 , V_54 ) ;
}
return 0 ;
}
struct V_16 * F_61 ( struct V_16 * V_17 )
{
F_44 ( & V_17 -> V_22 ) ;
return V_17 ;
}
void F_62 ( struct V_16 * * V_17 )
{
struct V_16 * V_61 = * V_17 ;
* V_17 = NULL ;
if ( V_61 ) {
F_23 ( & V_61 -> V_22 ) ;
}
}
unsigned F_63 ( struct V_1 * V_2 , int V_4 )
{
T_4 V_62 ;
F_35 ( V_2 , V_4 ) ;
V_62 = V_2 -> V_7 [ V_4 ] . V_20 [ V_4 ]
- F_8 ( & V_2 -> V_7 [ V_4 ] . V_12 ) ;
if ( V_62 > 0x10000000 ) {
V_62 = 0x10000000 ;
}
return ( unsigned ) V_62 ;
}
bool F_64 ( struct V_16 * V_17 , int V_63 )
{
struct V_5 * V_64 ;
if ( ! V_17 ) {
return false ;
}
if ( V_17 -> V_4 == V_63 ) {
return false ;
}
V_64 = & V_17 -> V_2 -> V_7 [ V_63 ] ;
if ( V_17 -> V_3 <= V_64 -> V_20 [ V_17 -> V_4 ] ) {
return false ;
}
return true ;
}
void F_65 ( struct V_16 * V_17 , int V_63 )
{
struct V_5 * V_65 , * V_66 ;
unsigned V_49 ;
if ( ! V_17 ) {
return;
}
if ( V_17 -> V_4 == V_63 ) {
return;
}
V_66 = & V_17 -> V_2 -> V_7 [ V_17 -> V_4 ] ;
V_65 = & V_17 -> V_2 -> V_7 [ V_63 ] ;
for ( V_49 = 0 ; V_49 < V_50 ; ++ V_49 ) {
if ( V_49 == V_63 ) {
continue;
}
V_65 -> V_20 [ V_49 ] = F_66 ( V_65 -> V_20 [ V_49 ] , V_66 -> V_20 [ V_49 ] ) ;
}
}
int F_67 ( struct V_1 * V_2 , int V_4 )
{
T_4 V_67 ;
int V_54 ;
F_68 ( V_2 , V_2 -> V_7 [ V_4 ] . V_10 ) ;
if ( V_2 -> V_8 . V_68 || ! F_69 ( V_2 , & V_2 -> V_4 [ V_4 ] ) ) {
V_2 -> V_7 [ V_4 ] . V_10 = 0 ;
if ( V_4 != V_69 ) {
V_67 = V_70 + V_4 * 4 ;
V_2 -> V_7 [ V_4 ] . V_11 = & V_2 -> V_8 . V_8 [ V_67 / 4 ] ;
V_2 -> V_7 [ V_4 ] . V_71 = V_2 -> V_8 . V_71 +
V_67 ;
} else {
V_67 = F_70 ( V_2 -> V_72 -> V_73 , 8 ) ;
V_2 -> V_7 [ V_4 ] . V_11 = V_2 -> V_74 . V_11 + V_67 ;
V_2 -> V_7 [ V_4 ] . V_71 = V_2 -> V_74 . V_71 + V_67 ;
}
} else {
V_54 = F_71 ( V_2 , & V_2 -> V_7 [ V_4 ] . V_10 ) ;
if ( V_54 ) {
F_60 ( V_2 -> V_44 , L_10 ) ;
return V_54 ;
}
V_67 = V_75 +
V_2 -> V_7 [ V_4 ] . V_10 -
V_2 -> V_76 . V_77 ;
V_2 -> V_7 [ V_4 ] . V_11 = & V_2 -> V_8 . V_8 [ V_67 / 4 ] ;
V_2 -> V_7 [ V_4 ] . V_71 = V_2 -> V_8 . V_71 + V_67 ;
}
F_1 ( V_2 , F_8 ( & V_2 -> V_7 [ V_4 ] . V_12 ) , V_4 ) ;
V_2 -> V_7 [ V_4 ] . V_78 = true ;
F_72 ( V_2 -> V_44 , L_11 ,
V_4 , V_2 -> V_7 [ V_4 ] . V_71 , V_2 -> V_7 [ V_4 ] . V_11 ) ;
return 0 ;
}
static void F_73 ( struct V_1 * V_2 , int V_4 )
{
int V_49 ;
V_2 -> V_7 [ V_4 ] . V_10 = - 1 ;
V_2 -> V_7 [ V_4 ] . V_11 = NULL ;
V_2 -> V_7 [ V_4 ] . V_71 = 0 ;
for ( V_49 = 0 ; V_49 < V_50 ; ++ V_49 )
V_2 -> V_7 [ V_4 ] . V_20 [ V_49 ] = 0 ;
F_74 ( & V_2 -> V_7 [ V_4 ] . V_12 , 0 ) ;
V_2 -> V_7 [ V_4 ] . V_78 = false ;
F_75 ( & V_2 -> V_7 [ V_4 ] . V_14 ,
F_26 ) ;
V_2 -> V_7 [ V_4 ] . V_2 = V_2 ;
}
int F_76 ( struct V_1 * V_2 )
{
int V_4 ;
F_77 ( & V_2 -> V_24 ) ;
for ( V_4 = 0 ; V_4 < V_50 ; V_4 ++ ) {
F_73 ( V_2 , V_4 ) ;
}
if ( F_78 ( V_2 ) ) {
F_60 ( V_2 -> V_44 , L_12 ) ;
}
return 0 ;
}
void F_79 ( struct V_1 * V_2 )
{
int V_4 , V_54 ;
F_80 ( & V_2 -> V_79 ) ;
for ( V_4 = 0 ; V_4 < V_50 ; V_4 ++ ) {
if ( ! V_2 -> V_7 [ V_4 ] . V_78 )
continue;
V_54 = F_59 ( V_2 , V_4 ) ;
if ( V_54 ) {
F_81 ( V_2 , V_4 ) ;
}
F_82 ( & V_2 -> V_7 [ V_4 ] . V_14 ) ;
F_31 ( & V_2 -> V_24 ) ;
F_68 ( V_2 , V_2 -> V_7 [ V_4 ] . V_10 ) ;
V_2 -> V_7 [ V_4 ] . V_78 = false ;
}
F_83 ( & V_2 -> V_79 ) ;
}
void F_81 ( struct V_1 * V_2 , int V_4 )
{
if ( V_2 -> V_7 [ V_4 ] . V_78 ) {
F_1 ( V_2 , V_2 -> V_7 [ V_4 ] . V_20 [ V_4 ] , V_4 ) ;
F_82 ( & V_2 -> V_7 [ V_4 ] . V_14 ) ;
}
}
static int F_84 ( struct V_80 * V_81 , void * V_82 )
{
struct V_83 * V_84 = (struct V_83 * ) V_81 -> V_47 ;
struct V_85 * V_44 = V_84 -> V_86 -> V_44 ;
struct V_1 * V_2 = V_44 -> V_87 ;
int V_49 , V_88 ;
for ( V_49 = 0 ; V_49 < V_50 ; ++ V_49 ) {
if ( ! V_2 -> V_7 [ V_49 ] . V_78 )
continue;
F_35 ( V_2 , V_49 ) ;
F_85 ( V_81 , L_13 , V_49 ) ;
F_85 ( V_81 , L_14 ,
( unsigned long long ) F_8 ( & V_2 -> V_7 [ V_49 ] . V_12 ) ) ;
F_85 ( V_81 , L_15 ,
V_2 -> V_7 [ V_49 ] . V_20 [ V_49 ] ) ;
for ( V_88 = 0 ; V_88 < V_50 ; ++ V_88 ) {
if ( V_49 != V_88 && V_2 -> V_7 [ V_88 ] . V_78 )
F_85 ( V_81 , L_16 ,
V_88 , V_2 -> V_7 [ V_49 ] . V_20 [ V_88 ] ) ;
}
}
return 0 ;
}
static int F_86 ( struct V_80 * V_81 , void * V_82 )
{
struct V_83 * V_84 = (struct V_83 * ) V_81 -> V_47 ;
struct V_85 * V_44 = V_84 -> V_86 -> V_44 ;
struct V_1 * V_2 = V_44 -> V_87 ;
F_87 ( & V_2 -> V_39 ) ;
F_85 ( V_81 , L_17 , V_2 -> V_45 ) ;
V_2 -> V_45 = true ;
F_31 ( & V_2 -> V_24 ) ;
F_34 ( & V_2 -> V_39 ) ;
return 0 ;
}
int F_78 ( struct V_1 * V_2 )
{
#if F_88 ( V_89 )
return F_89 ( V_2 , V_90 , 2 ) ;
#else
return 0 ;
#endif
}
static const char * F_90 ( struct V_17 * V_17 )
{
return L_18 ;
}
static const char * F_91 ( struct V_17 * V_46 )
{
struct V_16 * V_17 = F_38 ( V_46 ) ;
switch ( V_17 -> V_4 ) {
case V_91 : return L_19 ;
case V_92 : return L_20 ;
case V_93 : return L_21 ;
case V_94 : return L_22 ;
case V_95 : return L_23 ;
case V_69 : return L_24 ;
case V_96 : return L_25 ;
case V_97 : return L_26 ;
default: F_54 ( 1 ) ; return L_27 ;
}
}
static inline bool F_92 ( struct V_16 * V_17 )
{
return F_93 ( V_98 , & V_17 -> V_22 . V_30 ) ;
}
static void
F_94 ( struct V_17 * V_17 , struct V_99 * V_100 )
{
struct V_101 * V_28 =
F_18 ( V_100 , struct V_101 , V_22 ) ;
F_95 ( V_28 -> V_102 ) ;
}
static signed long F_96 ( struct V_17 * V_46 , bool V_52 ,
signed long V_103 )
{
struct V_16 * V_17 = F_38 ( V_46 ) ;
struct V_1 * V_2 = V_17 -> V_2 ;
struct V_101 V_100 ;
V_100 . V_102 = V_104 ;
if ( F_97 ( V_46 , & V_100 . V_22 , F_94 ) )
return V_103 ;
while ( V_103 > 0 ) {
if ( V_52 )
F_98 ( V_105 ) ;
else
F_98 ( V_106 ) ;
if ( F_92 ( V_17 ) )
break;
if ( V_2 -> V_45 ) {
V_103 = - V_55 ;
break;
}
V_103 = F_99 ( V_103 ) ;
if ( V_103 > 0 && V_52 && F_100 ( V_104 ) )
V_103 = - V_107 ;
}
F_101 ( V_108 ) ;
F_102 ( V_46 , & V_100 . V_22 ) ;
return V_103 ;
}
