static void F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = & V_2 -> V_6 ;
if ( V_5 -> V_7 )
* V_5 -> V_7 = F_2 ( V_3 ) ;
}
static T_1 F_3 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = & V_2 -> V_6 ;
T_1 V_3 = 0 ;
if ( V_5 -> V_7 )
V_3 = F_4 ( * V_5 -> V_7 ) ;
else
V_3 = F_5 ( F_6 ( & V_5 -> V_8 ) ) ;
return V_3 ;
}
static void F_7 ( struct V_1 * V_2 )
{
F_8 ( V_9 ,
& V_2 -> V_6 . V_10 ,
V_11 ) ;
}
int F_9 ( struct V_1 * V_2 , void * V_12 ,
struct V_13 * * V_14 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
* V_14 = F_10 ( sizeof( struct V_13 ) , V_17 ) ;
if ( ( * V_14 ) == NULL ) {
return - V_18 ;
}
( * V_14 ) -> V_3 = ++ V_2 -> V_6 . V_19 [ V_2 -> V_20 ] ;
( * V_14 ) -> V_2 = V_2 ;
( * V_14 ) -> V_12 = V_12 ;
F_11 ( & ( * V_14 ) -> V_21 , & V_22 ,
& V_16 -> V_23 . V_24 , V_16 -> V_25 + V_2 -> V_20 ,
( * V_14 ) -> V_3 ) ;
F_12 ( V_2 , V_2 -> V_6 . V_26 ,
( * V_14 ) -> V_3 ,
V_27 ) ;
F_13 ( V_2 -> V_16 -> V_28 , V_2 -> V_20 , ( * V_14 ) -> V_3 ) ;
return 0 ;
}
int F_14 ( struct V_1 * V_2 , void * V_12 ,
T_2 V_3 , struct V_13 * * V_14 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
if ( V_3 > V_2 -> V_6 . V_19 [ V_2 -> V_20 ] )
return - V_29 ;
* V_14 = F_10 ( sizeof( struct V_13 ) , V_17 ) ;
if ( ( * V_14 ) == NULL )
return - V_18 ;
( * V_14 ) -> V_3 = V_3 ;
( * V_14 ) -> V_2 = V_2 ;
( * V_14 ) -> V_12 = V_12 ;
F_11 ( & ( * V_14 ) -> V_21 , & V_22 ,
& V_16 -> V_23 . V_24 , V_16 -> V_25 + V_2 -> V_20 ,
( * V_14 ) -> V_3 ) ;
return 0 ;
}
static int F_15 ( T_3 * V_30 , unsigned V_31 , int V_32 , void * V_33 )
{
struct V_13 * V_14 ;
struct V_15 * V_16 ;
T_4 V_3 ;
int V_34 ;
V_14 = F_16 ( V_30 , struct V_13 , V_35 ) ;
V_16 = V_14 -> V_2 -> V_16 ;
V_3 = F_6 ( & V_14 -> V_2 -> V_6 . V_8 ) ;
if ( V_3 >= V_14 -> V_3 ) {
V_34 = F_17 ( & V_14 -> V_21 ) ;
if ( ! V_34 )
F_18 ( & V_14 -> V_21 , L_1 ) ;
else
F_18 ( & V_14 -> V_21 , L_2 ) ;
F_19 ( V_16 , V_14 -> V_2 -> V_6 . V_36 ,
V_14 -> V_2 -> V_6 . V_37 ) ;
F_20 ( & V_16 -> V_23 , & V_14 -> V_35 ) ;
F_21 ( & V_14 -> V_21 ) ;
} else
F_18 ( & V_14 -> V_21 , L_3 ) ;
return 0 ;
}
static bool F_22 ( struct V_1 * V_2 )
{
T_2 V_3 , V_8 , V_38 ;
unsigned V_39 = 0 ;
bool V_40 = false ;
V_8 = F_6 ( & V_2 -> V_6 . V_8 ) ;
do {
V_38 = V_2 -> V_6 . V_19 [ V_2 -> V_20 ] ;
V_3 = F_3 ( V_2 ) ;
V_3 |= V_8 & 0xffffffff00000000LL ;
if ( V_3 < V_8 ) {
V_3 &= 0xffffffff ;
V_3 |= V_38 & 0xffffffff00000000LL ;
}
if ( V_3 <= V_8 || V_3 > V_38 ) {
break;
}
V_40 = true ;
V_8 = V_3 ;
if ( ( V_39 ++ ) > 10 ) {
break;
}
} while ( F_23 ( & V_2 -> V_6 . V_8 , V_3 ) > V_3 );
if ( V_3 < V_38 )
F_7 ( V_2 ) ;
return V_40 ;
}
static void F_24 ( struct V_41 * V_42 )
{
struct V_4 * V_6 ;
struct V_1 * V_2 ;
V_6 = F_16 ( V_42 , struct V_4 ,
V_10 . V_42 ) ;
V_2 = V_6 -> V_2 ;
if ( ! F_25 ( & V_2 -> V_16 -> V_43 ) ) {
F_7 ( V_2 ) ;
return;
}
if ( V_6 -> V_44 && V_2 -> V_16 -> V_28 -> V_45 ) {
V_6 -> V_44 = false ;
F_26 ( V_2 -> V_16 , V_6 -> V_36 ,
V_6 -> V_37 ) ;
}
if ( F_22 ( V_2 ) )
F_27 ( & V_2 -> V_16 -> V_23 ) ;
else if ( F_28 ( V_2 ) ) {
F_29 ( V_2 -> V_16 -> V_46 , L_4
L_5 ,
( T_2 ) F_6 ( & V_6 -> V_8 ) ,
V_6 -> V_19 [ V_2 -> V_20 ] , V_2 -> V_20 ) ;
V_2 -> V_16 -> V_47 = true ;
F_27 ( & V_2 -> V_16 -> V_23 ) ;
}
F_30 ( & V_2 -> V_16 -> V_43 ) ;
}
void F_31 ( struct V_1 * V_2 )
{
T_2 V_3 , V_8 , V_38 ;
unsigned V_39 = 0 ;
bool V_40 = false ;
V_8 = F_6 ( & V_2 -> V_6 . V_8 ) ;
do {
V_38 = V_2 -> V_6 . V_19 [ V_2 -> V_20 ] ;
V_3 = F_3 ( V_2 ) ;
V_3 |= V_8 & 0xffffffff00000000LL ;
if ( V_3 < V_8 ) {
V_3 &= 0xffffffff ;
V_3 |= V_38 & 0xffffffff00000000LL ;
}
if ( V_3 <= V_8 || V_3 > V_38 ) {
break;
}
V_40 = true ;
V_8 = V_3 ;
if ( ( V_39 ++ ) > 10 ) {
break;
}
} while ( F_23 ( & V_2 -> V_6 . V_8 , V_3 ) > V_3 );
if ( V_40 )
F_27 ( & V_2 -> V_16 -> V_23 ) ;
}
static bool F_32 ( struct V_1 * V_2 , T_4 V_3 )
{
if ( F_6 ( & V_2 -> V_6 . V_8 ) >= V_3 )
return true ;
F_31 ( V_2 ) ;
if ( F_6 ( & V_2 -> V_6 . V_8 ) >= V_3 )
return true ;
return false ;
}
static bool F_33 ( struct V_14 * V_48 )
{
struct V_13 * V_14 = F_34 ( V_48 ) ;
struct V_1 * V_2 = V_14 -> V_2 ;
struct V_15 * V_16 = V_2 -> V_16 ;
if ( F_6 ( & V_2 -> V_6 . V_8 ) >= V_14 -> V_3 )
return true ;
if ( F_25 ( & V_16 -> V_43 ) ) {
F_31 ( V_2 ) ;
F_30 ( & V_16 -> V_43 ) ;
if ( F_6 ( & V_2 -> V_6 . V_8 ) >= V_14 -> V_3 )
return true ;
}
return false ;
}
static bool F_35 ( struct V_14 * V_48 )
{
struct V_13 * V_14 = F_34 ( V_48 ) ;
struct V_1 * V_2 = V_14 -> V_2 ;
struct V_15 * V_16 = V_2 -> V_16 ;
if ( F_6 ( & V_2 -> V_6 . V_8 ) >= V_14 -> V_3 )
return false ;
if ( F_25 ( & V_16 -> V_43 ) ) {
F_36 ( V_16 , V_2 -> V_6 . V_36 ,
V_2 -> V_6 . V_37 ) ;
if ( F_22 ( V_2 ) )
F_37 ( & V_16 -> V_23 ) ;
if ( F_6 ( & V_2 -> V_6 . V_8 ) >= V_14 -> V_3 ) {
F_19 ( V_16 , V_2 -> V_6 . V_36 ,
V_2 -> V_6 . V_37 ) ;
F_30 ( & V_16 -> V_43 ) ;
return false ;
}
F_30 ( & V_16 -> V_43 ) ;
} else {
if ( F_38 ( V_16 , V_2 -> V_6 . V_36 ,
V_2 -> V_6 . V_37 ) )
V_2 -> V_6 . V_44 = true ;
F_7 ( V_2 ) ;
}
V_14 -> V_35 . V_32 = 0 ;
V_14 -> V_35 . V_49 = NULL ;
V_14 -> V_35 . V_50 = F_15 ;
F_39 ( & V_16 -> V_23 , & V_14 -> V_35 ) ;
F_40 ( V_48 ) ;
F_18 ( & V_14 -> V_21 , L_6 , V_2 -> V_20 ) ;
return true ;
}
bool F_41 ( struct V_13 * V_14 )
{
if ( ! V_14 )
return true ;
if ( F_32 ( V_14 -> V_2 , V_14 -> V_3 ) ) {
if ( ! F_42 ( & V_14 -> V_21 ) )
F_18 ( & V_14 -> V_21 , L_7 ) ;
return true ;
}
return false ;
}
static bool F_43 ( struct V_15 * V_16 , T_4 * V_3 )
{
unsigned V_51 ;
for ( V_51 = 0 ; V_51 < V_52 ; ++ V_51 ) {
if ( ! V_16 -> V_53 [ V_51 ] || ! V_3 [ V_51 ] )
continue;
if ( F_32 ( V_16 -> V_53 [ V_51 ] , V_3 [ V_51 ] ) )
return true ;
}
return false ;
}
static long F_44 ( struct V_15 * V_16 ,
T_4 * V_54 , bool V_55 ,
long V_56 )
{
T_2 V_8 [ V_52 ] ;
bool V_57 ;
int V_51 ;
long V_58 ;
if ( V_56 == 0 ) {
return F_43 ( V_16 , V_54 ) ;
}
while ( ! F_43 ( V_16 , V_54 ) ) {
for ( V_51 = 0 ; V_51 < V_52 ; ++ V_51 ) {
struct V_1 * V_2 = V_16 -> V_53 [ V_51 ] ;
if ( ! V_2 || ! V_54 [ V_51 ] )
continue;
V_8 [ V_51 ] = F_6 ( & V_2 -> V_6 . V_8 ) ;
F_45 ( V_16 -> V_28 , V_51 , V_54 [ V_51 ] ) ;
F_36 ( V_16 , V_2 -> V_6 . V_36 ,
V_2 -> V_6 . V_37 ) ;
}
if ( V_55 ) {
V_58 = F_46 ( V_16 -> V_23 , (
( V_57 = F_43 ( V_16 , V_54 ) )
|| V_16 -> V_47 ) , V_11 ) ;
} else {
V_58 = F_47 ( V_16 -> V_23 , (
( V_57 = F_43 ( V_16 , V_54 ) )
|| V_16 -> V_47 ) , V_11 ) ;
}
for ( V_51 = 0 ; V_51 < V_52 ; ++ V_51 ) {
struct V_1 * V_2 = V_16 -> V_53 [ V_51 ] ;
if ( ! V_2 || ! V_54 [ V_51 ] )
continue;
F_19 ( V_16 , V_2 -> V_6 . V_36 ,
V_2 -> V_6 . V_37 ) ;
F_48 ( V_16 -> V_28 , V_51 , V_54 [ V_51 ] ) ;
}
if ( F_49 ( V_58 < 0 ) )
return V_58 ;
if ( F_49 ( ! V_57 ) ) {
if ( V_16 -> V_47 )
return - V_59 ;
if ( V_58 )
continue;
for ( V_51 = 0 ; V_51 < V_52 ; ++ V_51 ) {
struct V_1 * V_2 = V_16 -> V_53 [ V_51 ] ;
if ( ! V_2 || ! V_54 [ V_51 ] )
continue;
if ( V_8 [ V_51 ] != F_6 ( & V_2 -> V_6 . V_8 ) )
break;
}
if ( V_51 != V_52 )
continue;
for ( V_51 = 0 ; V_51 < V_52 ; ++ V_51 ) {
if ( ! V_16 -> V_53 [ V_51 ] || ! V_54 [ V_51 ] )
continue;
if ( F_28 ( V_16 -> V_53 [ V_51 ] ) )
break;
}
if ( V_51 < V_52 ) {
F_29 ( V_16 -> V_46 , L_8
L_9
L_10 ,
V_54 [ V_51 ] , V_8 [ V_51 ] , V_51 ) ;
V_16 -> V_47 = true ;
F_27 ( & V_16 -> V_23 ) ;
return - V_59 ;
}
if ( V_56 < V_60 ) {
V_56 -= V_11 ;
if ( V_56 <= 0 ) {
return 0 ;
}
}
}
}
return V_56 ;
}
int F_50 ( struct V_13 * V_14 , bool V_55 )
{
T_2 V_3 [ V_52 ] = {} ;
long V_58 ;
V_3 [ V_14 -> V_2 -> V_20 ] = V_14 -> V_3 ;
V_58 = F_44 ( V_14 -> V_2 -> V_16 , V_3 , V_55 , V_60 ) ;
if ( V_58 < 0 ) {
return V_58 ;
}
V_58 = F_42 ( & V_14 -> V_21 ) ;
if ( ! V_58 )
F_18 ( & V_14 -> V_21 , L_11 ) ;
return 0 ;
}
int F_51 ( struct V_15 * V_16 ,
struct V_13 * * V_61 ,
bool V_55 )
{
T_2 V_3 [ V_52 ] ;
unsigned V_51 , V_62 = 0 ;
long V_58 ;
for ( V_51 = 0 ; V_51 < V_52 ; ++ V_51 ) {
V_3 [ V_51 ] = 0 ;
if ( ! V_61 [ V_51 ] ) {
continue;
}
V_3 [ V_51 ] = V_61 [ V_51 ] -> V_3 ;
++ V_62 ;
}
if ( V_62 == 0 )
return - V_63 ;
V_58 = F_44 ( V_16 , V_3 , V_55 , V_60 ) ;
if ( V_58 < 0 ) {
return V_58 ;
}
return 0 ;
}
int F_52 ( struct V_1 * V_2 )
{
T_2 V_3 [ V_52 ] = {} ;
long V_58 ;
V_3 [ V_2 -> V_20 ] = F_6 ( & V_2 -> V_6 . V_8 ) + 1ULL ;
if ( V_3 [ V_2 -> V_20 ] >= V_2 -> V_6 . V_19 [ V_2 -> V_20 ] ) {
return - V_63 ;
}
V_58 = F_44 ( V_2 -> V_16 , V_3 , false , V_60 ) ;
if ( V_58 < 0 )
return V_58 ;
return 0 ;
}
int F_53 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
T_2 V_3 [ V_52 ] = {} ;
long V_58 ;
V_3 [ V_2 -> V_20 ] = V_2 -> V_6 . V_19 [ V_2 -> V_20 ] ;
if ( ! V_3 [ V_2 -> V_20 ] )
return 0 ;
V_58 = F_44 ( V_16 , V_3 , false , V_60 ) ;
if ( V_58 < 0 ) {
if ( V_58 == - V_59 )
return - V_59 ;
F_54 ( V_16 -> V_46 , L_12 ,
V_2 -> V_20 , V_58 ) ;
}
return 0 ;
}
struct V_13 * F_55 ( struct V_13 * V_14 )
{
F_40 ( & V_14 -> V_21 ) ;
return V_14 ;
}
void F_56 ( struct V_13 * * V_14 )
{
struct V_13 * V_64 = * V_14 ;
* V_14 = NULL ;
if ( V_64 )
F_21 ( & V_64 -> V_21 ) ;
}
unsigned F_57 ( struct V_1 * V_2 )
{
T_2 V_65 ;
F_31 ( V_2 ) ;
V_65 = V_2 -> V_6 . V_19 [ V_2 -> V_20 ]
- F_6 ( & V_2 -> V_6 . V_8 ) ;
if ( V_65 > 0x10000000 )
V_65 = 0x10000000 ;
return ( unsigned ) V_65 ;
}
bool F_58 ( struct V_13 * V_14 ,
struct V_1 * V_66 )
{
struct V_4 * V_67 ;
if ( ! V_14 )
return false ;
if ( V_14 -> V_2 == V_66 )
return false ;
V_67 = & V_66 -> V_6 ;
if ( V_14 -> V_3 <= V_67 -> V_19 [ V_14 -> V_2 -> V_20 ] )
return false ;
return true ;
}
void F_59 ( struct V_13 * V_14 ,
struct V_1 * V_66 )
{
struct V_4 * V_68 , * V_69 ;
unsigned V_51 ;
if ( ! V_14 )
return;
if ( V_14 -> V_2 == V_66 )
return;
V_69 = & V_14 -> V_2 -> V_6 ;
V_68 = & V_66 -> V_6 ;
for ( V_51 = 0 ; V_51 < V_52 ; ++ V_51 ) {
if ( V_51 == V_66 -> V_20 )
continue;
V_68 -> V_19 [ V_51 ] = F_60 ( V_68 -> V_19 [ V_51 ] , V_69 -> V_19 [ V_51 ] ) ;
}
}
int F_61 ( struct V_1 * V_2 ,
struct V_70 * V_36 ,
unsigned V_37 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
T_2 V_71 ;
if ( V_2 != & V_16 -> V_72 . V_2 ) {
V_2 -> V_6 . V_7 = & V_16 -> V_73 . V_73 [ V_2 -> V_74 ] ;
V_2 -> V_6 . V_26 = V_16 -> V_73 . V_26 + ( V_2 -> V_74 * 4 ) ;
} else {
V_71 = F_62 ( V_16 -> V_72 . V_75 -> V_76 , 8 ) ;
V_2 -> V_6 . V_7 = V_16 -> V_72 . V_7 + V_71 ;
V_2 -> V_6 . V_26 = V_16 -> V_72 . V_26 + V_71 ;
}
F_1 ( V_2 , F_6 ( & V_2 -> V_6 . V_8 ) ) ;
V_2 -> V_6 . V_77 = true ;
V_2 -> V_6 . V_36 = V_36 ;
V_2 -> V_6 . V_37 = V_37 ;
F_63 ( V_16 -> V_46 , L_13
L_14 , V_2 -> V_20 ,
V_2 -> V_6 . V_26 , V_2 -> V_6 . V_7 ) ;
return 0 ;
}
void F_64 ( struct V_1 * V_2 )
{
int V_51 ;
V_2 -> V_6 . V_7 = NULL ;
V_2 -> V_6 . V_26 = 0 ;
for ( V_51 = 0 ; V_51 < V_52 ; ++ V_51 )
V_2 -> V_6 . V_19 [ V_51 ] = 0 ;
F_65 ( & V_2 -> V_6 . V_8 , 0 ) ;
V_2 -> V_6 . V_77 = false ;
F_66 ( & V_2 -> V_6 . V_10 ,
F_24 ) ;
V_2 -> V_6 . V_2 = V_2 ;
}
int F_67 ( struct V_15 * V_16 )
{
F_68 ( & V_16 -> V_23 ) ;
if ( F_69 ( V_16 ) )
F_54 ( V_16 -> V_46 , L_15 ) ;
return 0 ;
}
void F_70 ( struct V_15 * V_16 )
{
int V_51 , V_58 ;
F_71 ( & V_16 -> V_78 ) ;
for ( V_51 = 0 ; V_51 < V_52 ; V_51 ++ ) {
struct V_1 * V_2 = V_16 -> V_53 [ V_51 ] ;
if ( ! V_2 || ! V_2 -> V_6 . V_77 )
continue;
V_58 = F_53 ( V_2 ) ;
if ( V_58 ) {
F_72 ( V_16 ) ;
}
F_27 ( & V_16 -> V_23 ) ;
V_2 -> V_6 . V_77 = false ;
}
F_73 ( & V_16 -> V_78 ) ;
}
void F_72 ( struct V_15 * V_16 )
{
int V_51 ;
for ( V_51 = 0 ; V_51 < V_52 ; V_51 ++ ) {
struct V_1 * V_2 = V_16 -> V_53 [ V_51 ] ;
if ( ! V_2 || ! V_2 -> V_6 . V_77 )
continue;
F_1 ( V_2 , V_2 -> V_6 . V_19 [ V_51 ] ) ;
}
}
static int F_74 ( struct V_79 * V_80 , void * V_81 )
{
struct V_82 * V_83 = (struct V_82 * ) V_80 -> V_49 ;
struct V_84 * V_46 = V_83 -> V_85 -> V_46 ;
struct V_15 * V_16 = V_46 -> V_86 ;
int V_51 , V_87 ;
for ( V_51 = 0 ; V_51 < V_52 ; ++ V_51 ) {
struct V_1 * V_2 = V_16 -> V_53 [ V_51 ] ;
if ( ! V_2 || ! V_2 -> V_6 . V_77 )
continue;
F_31 ( V_2 ) ;
F_75 ( V_80 , L_16 , V_51 , V_2 -> V_88 ) ;
F_75 ( V_80 , L_17 ,
( unsigned long long ) F_6 ( & V_2 -> V_6 . V_8 ) ) ;
F_75 ( V_80 , L_18 ,
V_2 -> V_6 . V_19 [ V_51 ] ) ;
for ( V_87 = 0 ; V_87 < V_52 ; ++ V_87 ) {
struct V_1 * V_89 = V_16 -> V_53 [ V_87 ] ;
if ( V_51 != V_87 && V_89 && V_89 -> V_6 . V_77 &&
V_2 -> V_6 . V_19 [ V_87 ] )
F_75 ( V_80 , L_19 ,
V_87 , V_2 -> V_6 . V_19 [ V_87 ] ) ;
}
}
return 0 ;
}
int F_69 ( struct V_15 * V_16 )
{
#if F_76 ( V_90 )
return F_77 ( V_16 , V_91 , 1 ) ;
#else
return 0 ;
#endif
}
static const char * F_78 ( struct V_14 * V_14 )
{
return L_20 ;
}
static const char * F_79 ( struct V_14 * V_48 )
{
struct V_13 * V_14 = F_34 ( V_48 ) ;
return ( const char * ) V_14 -> V_2 -> V_88 ;
}
static inline bool F_80 ( struct V_13 * V_14 )
{
return F_81 ( V_92 , & V_14 -> V_21 . V_32 ) ;
}
static void F_82 ( struct V_14 * V_14 , struct V_93 * V_94 )
{
struct V_95 * V_30 =
F_16 ( V_94 , struct V_95 , V_21 ) ;
F_83 ( V_30 -> V_96 ) ;
}
static signed long F_84 ( struct V_14 * V_48 , bool V_55 ,
signed long V_97 )
{
struct V_13 * V_14 = F_34 ( V_48 ) ;
struct V_15 * V_16 = V_14 -> V_2 -> V_16 ;
struct V_95 V_94 ;
V_94 . V_96 = V_98 ;
if ( F_85 ( V_48 , & V_94 . V_21 , F_82 ) )
return V_97 ;
while ( V_97 > 0 ) {
if ( V_55 )
F_86 ( V_99 ) ;
else
F_86 ( V_100 ) ;
if ( F_80 ( V_14 ) )
break;
if ( V_16 -> V_47 ) {
V_97 = - V_59 ;
break;
}
V_97 = F_87 ( V_97 ) ;
if ( V_97 > 0 && V_55 && F_88 ( V_98 ) )
V_97 = - V_101 ;
}
F_89 ( V_102 ) ;
F_90 ( V_48 , & V_94 . V_21 ) ;
return V_97 ;
}
