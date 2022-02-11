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
& V_2 -> V_6 . V_23 . V_24 ,
V_16 -> V_25 + V_2 -> V_20 ,
( * V_14 ) -> V_3 ) ;
F_12 ( V_2 , V_2 -> V_6 . V_26 ,
( * V_14 ) -> V_3 ,
V_27 ) ;
F_13 ( V_2 -> V_16 -> V_28 , V_2 -> V_20 , ( * V_14 ) -> V_3 ) ;
return 0 ;
}
static int F_14 ( T_2 * V_29 , unsigned V_30 , int V_31 , void * V_32 )
{
struct V_13 * V_14 ;
struct V_15 * V_16 ;
T_3 V_3 ;
int V_33 ;
V_14 = F_15 ( V_29 , struct V_13 , V_34 ) ;
V_16 = V_14 -> V_2 -> V_16 ;
V_3 = F_6 ( & V_14 -> V_2 -> V_6 . V_8 ) ;
if ( V_3 >= V_14 -> V_3 ) {
V_33 = F_16 ( & V_14 -> V_21 ) ;
if ( ! V_33 )
F_17 ( & V_14 -> V_21 , L_1 ) ;
else
F_17 ( & V_14 -> V_21 , L_2 ) ;
F_18 ( & V_14 -> V_2 -> V_6 . V_23 , & V_14 -> V_34 ) ;
F_19 ( & V_14 -> V_21 ) ;
} else
F_17 ( & V_14 -> V_21 , L_3 ) ;
return 0 ;
}
static bool F_20 ( struct V_1 * V_2 )
{
T_4 V_3 , V_8 , V_35 ;
unsigned V_36 = 0 ;
bool V_37 = false ;
V_8 = F_6 ( & V_2 -> V_6 . V_8 ) ;
do {
V_35 = V_2 -> V_6 . V_19 [ V_2 -> V_20 ] ;
V_3 = F_3 ( V_2 ) ;
V_3 |= V_8 & 0xffffffff00000000LL ;
if ( V_3 < V_8 ) {
V_3 &= 0xffffffff ;
V_3 |= V_35 & 0xffffffff00000000LL ;
}
if ( V_3 <= V_8 || V_3 > V_35 ) {
break;
}
V_37 = true ;
V_8 = V_3 ;
if ( ( V_36 ++ ) > 10 ) {
break;
}
} while ( F_21 ( & V_2 -> V_6 . V_8 , V_3 ) > V_3 );
if ( V_3 < V_35 )
F_7 ( V_2 ) ;
return V_37 ;
}
static void F_22 ( struct V_38 * V_39 )
{
struct V_4 * V_6 ;
struct V_1 * V_2 ;
V_6 = F_15 ( V_39 , struct V_4 ,
V_10 . V_39 ) ;
V_2 = V_6 -> V_2 ;
if ( ! F_23 ( & V_2 -> V_16 -> V_40 ) ) {
F_7 ( V_2 ) ;
return;
}
if ( F_20 ( V_2 ) ) {
F_24 ( & V_2 -> V_6 . V_23 ) ;
}
else if ( F_25 ( V_2 ) ) {
F_26 ( V_2 -> V_16 -> V_41 , L_4
L_5 ,
( T_4 ) F_6 ( & V_6 -> V_8 ) ,
V_6 -> V_19 [ V_2 -> V_20 ] , V_2 -> V_20 ) ;
V_2 -> V_16 -> V_42 = true ;
F_24 ( & V_2 -> V_6 . V_23 ) ;
}
F_27 ( & V_2 -> V_16 -> V_40 ) ;
}
void F_28 ( struct V_1 * V_2 )
{
if ( F_20 ( V_2 ) )
F_24 ( & V_2 -> V_6 . V_23 ) ;
}
static bool F_29 ( struct V_1 * V_2 , T_3 V_3 )
{
if ( F_6 ( & V_2 -> V_6 . V_8 ) >= V_3 )
return true ;
F_28 ( V_2 ) ;
if ( F_6 ( & V_2 -> V_6 . V_8 ) >= V_3 )
return true ;
return false ;
}
static bool F_30 ( struct V_14 * V_43 )
{
struct V_13 * V_14 = F_31 ( V_43 ) ;
struct V_1 * V_2 = V_14 -> V_2 ;
struct V_15 * V_16 = V_2 -> V_16 ;
if ( F_6 ( & V_2 -> V_6 . V_8 ) >= V_14 -> V_3 )
return true ;
if ( F_23 ( & V_16 -> V_40 ) ) {
F_28 ( V_2 ) ;
F_27 ( & V_16 -> V_40 ) ;
if ( F_6 ( & V_2 -> V_6 . V_8 ) >= V_14 -> V_3 )
return true ;
}
return false ;
}
static bool F_32 ( struct V_14 * V_43 )
{
struct V_13 * V_14 = F_31 ( V_43 ) ;
struct V_1 * V_2 = V_14 -> V_2 ;
if ( F_6 ( & V_2 -> V_6 . V_8 ) >= V_14 -> V_3 )
return false ;
V_14 -> V_34 . V_31 = 0 ;
V_14 -> V_34 . V_44 = NULL ;
V_14 -> V_34 . V_45 = F_14 ;
F_33 ( & V_2 -> V_6 . V_23 , & V_14 -> V_34 ) ;
F_34 ( V_43 ) ;
F_17 ( & V_14 -> V_21 , L_6 , V_2 -> V_20 ) ;
return true ;
}
static int F_35 ( struct V_1 * V_2 , T_4 V_3 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
bool V_46 = false ;
F_36 ( ! V_2 ) ;
if ( V_3 > V_2 -> V_6 . V_19 [ V_2 -> V_20 ] )
return - V_47 ;
if ( F_6 ( & V_2 -> V_6 . V_8 ) >= V_3 )
return 0 ;
F_37 ( V_2 -> V_6 . V_23 , (
( V_46 = F_29 ( V_2 , V_3 ) )
|| V_16 -> V_42 ) ) ;
if ( V_46 )
return 0 ;
else
return - V_48 ;
}
int F_38 ( struct V_1 * V_2 )
{
T_4 V_3 = F_6 ( & V_2 -> V_6 . V_8 ) + 1ULL ;
if ( V_3 >= V_2 -> V_6 . V_19 [ V_2 -> V_20 ] )
return - V_49 ;
return F_35 ( V_2 , V_3 ) ;
}
int F_39 ( struct V_1 * V_2 )
{
T_4 V_3 = V_2 -> V_6 . V_19 [ V_2 -> V_20 ] ;
if ( ! V_3 )
return 0 ;
return F_35 ( V_2 , V_3 ) ;
}
struct V_13 * F_40 ( struct V_13 * V_14 )
{
F_34 ( & V_14 -> V_21 ) ;
return V_14 ;
}
void F_41 ( struct V_13 * * V_14 )
{
struct V_13 * V_50 = * V_14 ;
* V_14 = NULL ;
if ( V_50 )
F_19 ( & V_50 -> V_21 ) ;
}
unsigned F_42 ( struct V_1 * V_2 )
{
T_4 V_51 ;
F_28 ( V_2 ) ;
V_51 = V_2 -> V_6 . V_19 [ V_2 -> V_20 ]
- F_6 ( & V_2 -> V_6 . V_8 ) ;
if ( V_51 > 0x10000000 )
V_51 = 0x10000000 ;
return ( unsigned ) V_51 ;
}
bool F_43 ( struct V_13 * V_14 ,
struct V_1 * V_52 )
{
struct V_4 * V_53 ;
if ( ! V_14 )
return false ;
if ( V_14 -> V_2 == V_52 )
return false ;
V_53 = & V_52 -> V_6 ;
if ( V_14 -> V_3 <= V_53 -> V_19 [ V_14 -> V_2 -> V_20 ] )
return false ;
return true ;
}
void F_44 ( struct V_13 * V_14 ,
struct V_1 * V_52 )
{
struct V_4 * V_54 , * V_55 ;
unsigned V_56 ;
if ( ! V_14 )
return;
if ( V_14 -> V_2 == V_52 )
return;
V_55 = & V_14 -> V_2 -> V_6 ;
V_54 = & V_52 -> V_6 ;
for ( V_56 = 0 ; V_56 < V_57 ; ++ V_56 ) {
if ( V_56 == V_52 -> V_20 )
continue;
V_54 -> V_19 [ V_56 ] = F_45 ( V_54 -> V_19 [ V_56 ] , V_55 -> V_19 [ V_56 ] ) ;
}
}
int F_46 ( struct V_1 * V_2 ,
struct V_58 * V_59 ,
unsigned V_60 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
T_4 V_61 ;
if ( V_2 != & V_16 -> V_62 . V_2 ) {
V_2 -> V_6 . V_7 = & V_16 -> V_63 . V_63 [ V_2 -> V_64 ] ;
V_2 -> V_6 . V_26 = V_16 -> V_63 . V_26 + ( V_2 -> V_64 * 4 ) ;
} else {
V_61 = F_47 ( V_16 -> V_62 . V_65 -> V_66 , 8 ) ;
V_2 -> V_6 . V_7 = V_16 -> V_62 . V_7 + V_61 ;
V_2 -> V_6 . V_26 = V_16 -> V_62 . V_26 + V_61 ;
}
F_1 ( V_2 , F_6 ( & V_2 -> V_6 . V_8 ) ) ;
F_48 ( V_16 , V_59 , V_60 ) ;
V_2 -> V_6 . V_59 = V_59 ;
V_2 -> V_6 . V_60 = V_60 ;
V_2 -> V_6 . V_67 = true ;
F_49 ( V_16 -> V_41 , L_7
L_8 , V_2 -> V_20 ,
V_2 -> V_6 . V_26 , V_2 -> V_6 . V_7 ) ;
return 0 ;
}
int F_50 ( struct V_1 * V_2 )
{
int V_56 , V_68 ;
V_2 -> V_6 . V_7 = NULL ;
V_2 -> V_6 . V_26 = 0 ;
for ( V_56 = 0 ; V_56 < V_57 ; ++ V_56 )
V_2 -> V_6 . V_19 [ V_56 ] = 0 ;
F_51 ( & V_2 -> V_6 . V_8 , 0 ) ;
V_2 -> V_6 . V_67 = false ;
F_52 ( & V_2 -> V_6 . V_10 ,
F_22 ) ;
V_2 -> V_6 . V_2 = V_2 ;
F_53 ( & V_2 -> V_6 . V_23 ) ;
if ( V_69 ) {
V_68 = F_54 ( & V_2 -> V_70 , & V_71 ,
V_72 , V_2 -> V_73 ) ;
if ( V_68 ) {
F_55 ( L_9 ,
V_2 -> V_73 ) ;
return V_68 ;
}
}
return 0 ;
}
int F_56 ( struct V_15 * V_16 )
{
if ( F_57 ( V_16 ) )
F_58 ( V_16 -> V_41 , L_10 ) ;
return 0 ;
}
void F_59 ( struct V_15 * V_16 )
{
int V_56 , V_68 ;
F_60 ( & V_16 -> V_74 ) ;
for ( V_56 = 0 ; V_56 < V_57 ; V_56 ++ ) {
struct V_1 * V_2 = V_16 -> V_75 [ V_56 ] ;
if ( ! V_2 || ! V_2 -> V_6 . V_67 )
continue;
V_68 = F_39 ( V_2 ) ;
if ( V_68 ) {
F_61 ( V_16 ) ;
}
F_24 ( & V_2 -> V_6 . V_23 ) ;
F_62 ( V_16 , V_2 -> V_6 . V_59 ,
V_2 -> V_6 . V_60 ) ;
F_63 ( & V_2 -> V_70 ) ;
V_2 -> V_6 . V_67 = false ;
}
F_64 ( & V_16 -> V_74 ) ;
}
void F_65 ( struct V_15 * V_16 )
{
int V_56 , V_68 ;
F_60 ( & V_16 -> V_74 ) ;
for ( V_56 = 0 ; V_56 < V_57 ; V_56 ++ ) {
struct V_1 * V_2 = V_16 -> V_75 [ V_56 ] ;
if ( ! V_2 || ! V_2 -> V_6 . V_67 )
continue;
V_68 = F_39 ( V_2 ) ;
if ( V_68 ) {
F_61 ( V_16 ) ;
}
F_62 ( V_16 , V_2 -> V_6 . V_59 ,
V_2 -> V_6 . V_60 ) ;
}
F_64 ( & V_16 -> V_74 ) ;
}
void F_66 ( struct V_15 * V_16 )
{
int V_56 ;
F_60 ( & V_16 -> V_74 ) ;
for ( V_56 = 0 ; V_56 < V_57 ; V_56 ++ ) {
struct V_1 * V_2 = V_16 -> V_75 [ V_56 ] ;
if ( ! V_2 || ! V_2 -> V_6 . V_67 )
continue;
F_48 ( V_16 , V_2 -> V_6 . V_59 ,
V_2 -> V_6 . V_60 ) ;
}
F_64 ( & V_16 -> V_74 ) ;
}
void F_61 ( struct V_15 * V_16 )
{
int V_56 ;
for ( V_56 = 0 ; V_56 < V_57 ; V_56 ++ ) {
struct V_1 * V_2 = V_16 -> V_75 [ V_56 ] ;
if ( ! V_2 || ! V_2 -> V_6 . V_67 )
continue;
F_1 ( V_2 , V_2 -> V_6 . V_19 [ V_56 ] ) ;
}
}
static int F_67 ( struct V_76 * V_77 , void * V_78 )
{
struct V_79 * V_80 = (struct V_79 * ) V_77 -> V_44 ;
struct V_81 * V_41 = V_80 -> V_82 -> V_41 ;
struct V_15 * V_16 = V_41 -> V_83 ;
int V_56 , V_84 ;
for ( V_56 = 0 ; V_56 < V_57 ; ++ V_56 ) {
struct V_1 * V_2 = V_16 -> V_75 [ V_56 ] ;
if ( ! V_2 || ! V_2 -> V_6 . V_67 )
continue;
F_28 ( V_2 ) ;
F_68 ( V_77 , L_11 , V_56 , V_2 -> V_73 ) ;
F_68 ( V_77 , L_12 ,
( unsigned long long ) F_6 ( & V_2 -> V_6 . V_8 ) ) ;
F_68 ( V_77 , L_13 ,
V_2 -> V_6 . V_19 [ V_56 ] ) ;
for ( V_84 = 0 ; V_84 < V_57 ; ++ V_84 ) {
struct V_1 * V_85 = V_16 -> V_75 [ V_84 ] ;
if ( V_56 != V_84 && V_85 && V_85 -> V_6 . V_67 &&
V_2 -> V_6 . V_19 [ V_84 ] )
F_68 ( V_77 , L_14 ,
V_84 , V_2 -> V_6 . V_19 [ V_84 ] ) ;
}
}
return 0 ;
}
int F_57 ( struct V_15 * V_16 )
{
#if F_69 ( V_86 )
return F_70 ( V_16 , V_87 , 1 ) ;
#else
return 0 ;
#endif
}
static const char * F_71 ( struct V_14 * V_14 )
{
return L_15 ;
}
static const char * F_72 ( struct V_14 * V_43 )
{
struct V_13 * V_14 = F_31 ( V_43 ) ;
return ( const char * ) V_14 -> V_2 -> V_73 ;
}
static inline bool F_73 ( struct V_13 * V_14 )
{
return F_74 ( V_88 , & V_14 -> V_21 . V_31 ) ;
}
static bool F_75 ( struct V_14 * * V_89 , T_5 V_90 )
{
int V_20 ;
struct V_14 * V_14 ;
for ( V_20 = 0 ; V_20 < V_90 ; ++ V_20 ) {
V_14 = V_89 [ V_20 ] ;
if ( V_14 ) {
if ( F_74 ( V_88 , & V_14 -> V_31 ) )
return true ;
}
}
return false ;
}
static void F_76 ( struct V_14 * V_14 , struct V_91 * V_92 )
{
struct V_93 * V_29 =
F_15 ( V_92 , struct V_93 , V_21 ) ;
F_77 ( V_29 -> V_94 ) ;
}
static signed long F_78 ( struct V_14 * V_43 , bool V_95 ,
signed long V_96 )
{
struct V_13 * V_14 = F_31 ( V_43 ) ;
struct V_15 * V_16 = V_14 -> V_2 -> V_16 ;
return F_79 ( V_16 , & V_43 , 1 , V_95 , V_96 ) ;
}
signed long F_79 ( struct V_15 * V_16 ,
struct V_14 * * V_97 , T_5 V_90 ,
bool V_95 , signed long V_96 )
{
struct V_93 * V_92 ;
struct V_14 * V_14 ;
unsigned V_20 ;
F_36 ( ! V_97 ) ;
V_92 = F_80 ( V_90 , sizeof( struct V_93 ) , V_17 ) ;
if ( V_92 == NULL ) {
V_96 = - V_18 ;
goto V_98;
}
for ( V_20 = 0 ; V_20 < V_90 ; ++ V_20 ) {
V_14 = V_97 [ V_20 ] ;
if ( V_14 ) {
V_92 [ V_20 ] . V_94 = V_99 ;
if ( F_81 ( V_14 ,
& V_92 [ V_20 ] . V_21 , F_76 ) ) {
goto V_100;
}
}
}
while ( V_96 > 0 ) {
if ( V_95 )
F_82 ( V_101 ) ;
else
F_82 ( V_102 ) ;
if ( F_75 ( V_97 , V_90 ) )
break;
if ( V_16 -> V_42 ) {
V_96 = - V_48 ;
break;
}
V_96 = F_83 ( V_96 ) ;
if ( V_96 > 0 && V_95 && F_84 ( V_99 ) )
V_96 = - V_103 ;
}
F_85 ( V_104 ) ;
V_100:
for ( V_20 = 0 ; V_20 < V_90 ; ++ V_20 ) {
V_14 = V_97 [ V_20 ] ;
if ( V_14 && V_92 [ V_20 ] . V_21 . V_45 )
F_86 ( V_14 , & V_92 [ V_20 ] . V_21 ) ;
}
V_98:
F_87 ( V_92 ) ;
return V_96 ;
}
