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
int F_7 ( struct V_1 * V_2 , void * V_9 ,
struct V_10 * * V_11 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
* V_11 = F_8 ( V_14 , V_15 ) ;
if ( ( * V_11 ) == NULL ) {
return - V_16 ;
}
( * V_11 ) -> V_3 = ++ V_2 -> V_6 . V_17 [ V_2 -> V_18 ] ;
( * V_11 ) -> V_2 = V_2 ;
( * V_11 ) -> V_9 = V_9 ;
F_9 ( & ( * V_11 ) -> V_19 , & V_20 ,
& V_2 -> V_6 . V_21 . V_22 ,
V_13 -> V_23 + V_2 -> V_18 ,
( * V_11 ) -> V_3 ) ;
F_10 ( V_2 , V_2 -> V_6 . V_24 ,
( * V_11 ) -> V_3 ,
V_25 ) ;
return 0 ;
}
static void F_11 ( struct V_1 * V_2 )
{
F_12 ( & V_2 -> V_6 . V_26 ,
V_27 + V_28 ) ;
}
static bool F_13 ( struct V_1 * V_2 )
{
T_2 V_3 , V_8 , V_29 ;
unsigned V_30 = 0 ;
bool V_31 = false ;
V_8 = F_6 ( & V_2 -> V_6 . V_8 ) ;
do {
V_29 = V_2 -> V_6 . V_17 [ V_2 -> V_18 ] ;
V_3 = F_3 ( V_2 ) ;
V_3 |= V_8 & 0xffffffff00000000LL ;
if ( V_3 < V_8 ) {
V_3 &= 0xffffffff ;
V_3 |= V_29 & 0xffffffff00000000LL ;
}
if ( V_3 <= V_8 || V_3 > V_29 ) {
break;
}
V_31 = true ;
V_8 = V_3 ;
if ( ( V_30 ++ ) > 10 ) {
break;
}
} while ( F_14 ( & V_2 -> V_6 . V_8 , V_3 ) > V_3 );
if ( V_3 < V_29 )
F_11 ( V_2 ) ;
return V_31 ;
}
void F_15 ( struct V_1 * V_2 )
{
if ( F_13 ( V_2 ) )
F_16 ( & V_2 -> V_6 . V_21 ) ;
}
static void F_17 ( unsigned long V_32 )
{
struct V_1 * V_2 = ( void * ) V_32 ;
F_15 ( V_2 ) ;
}
static bool F_18 ( struct V_1 * V_2 , T_3 V_3 )
{
if ( F_6 ( & V_2 -> V_6 . V_8 ) >= V_3 )
return true ;
F_15 ( V_2 ) ;
if ( F_6 ( & V_2 -> V_6 . V_8 ) >= V_3 )
return true ;
return false ;
}
static int F_19 ( struct V_1 * V_2 , T_2 V_3 )
{
bool V_33 = false ;
F_20 ( ! V_2 ) ;
if ( V_3 > V_2 -> V_6 . V_17 [ V_2 -> V_18 ] )
return - V_34 ;
if ( F_6 ( & V_2 -> V_6 . V_8 ) >= V_3 )
return 0 ;
F_11 ( V_2 ) ;
F_21 ( V_2 -> V_6 . V_21 , (
( V_33 = F_18 ( V_2 , V_3 ) ) ) ) ;
if ( V_33 )
return 0 ;
else
return - V_35 ;
}
int F_22 ( struct V_1 * V_2 )
{
T_2 V_3 = F_6 ( & V_2 -> V_6 . V_8 ) + 1ULL ;
if ( V_3 >= V_2 -> V_6 . V_17 [ V_2 -> V_18 ] )
return - V_36 ;
return F_19 ( V_2 , V_3 ) ;
}
int F_23 ( struct V_1 * V_2 )
{
T_2 V_3 = V_2 -> V_6 . V_17 [ V_2 -> V_18 ] ;
if ( ! V_3 )
return 0 ;
return F_19 ( V_2 , V_3 ) ;
}
unsigned F_24 ( struct V_1 * V_2 )
{
T_2 V_37 ;
F_15 ( V_2 ) ;
V_37 = V_2 -> V_6 . V_17 [ V_2 -> V_18 ]
- F_6 ( & V_2 -> V_6 . V_8 ) ;
if ( V_37 > 0x10000000 )
V_37 = 0x10000000 ;
return ( unsigned ) V_37 ;
}
bool F_25 ( struct V_10 * V_11 ,
struct V_1 * V_38 )
{
struct V_4 * V_39 ;
if ( ! V_11 )
return false ;
if ( V_11 -> V_2 == V_38 )
return false ;
V_39 = & V_38 -> V_6 ;
if ( V_11 -> V_3 <= V_39 -> V_17 [ V_11 -> V_2 -> V_18 ] )
return false ;
return true ;
}
void F_26 ( struct V_10 * V_11 ,
struct V_1 * V_38 )
{
struct V_4 * V_40 , * V_41 ;
unsigned V_42 ;
if ( ! V_11 )
return;
if ( V_11 -> V_2 == V_38 )
return;
V_41 = & V_11 -> V_2 -> V_6 ;
V_40 = & V_38 -> V_6 ;
for ( V_42 = 0 ; V_42 < V_43 ; ++ V_42 ) {
if ( V_42 == V_38 -> V_18 )
continue;
V_40 -> V_17 [ V_42 ] = F_27 ( V_40 -> V_17 [ V_42 ] , V_41 -> V_17 [ V_42 ] ) ;
}
}
int F_28 ( struct V_1 * V_2 ,
struct V_44 * V_45 ,
unsigned V_46 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
T_2 V_47 ;
if ( V_2 != & V_13 -> V_48 . V_2 ) {
V_2 -> V_6 . V_7 = & V_13 -> V_49 . V_49 [ V_2 -> V_50 ] ;
V_2 -> V_6 . V_24 = V_13 -> V_49 . V_24 + ( V_2 -> V_50 * 4 ) ;
} else {
V_47 = F_29 ( V_13 -> V_48 . V_51 -> V_52 , 8 ) ;
V_2 -> V_6 . V_7 = V_13 -> V_48 . V_7 + V_47 ;
V_2 -> V_6 . V_24 = V_13 -> V_48 . V_24 + V_47 ;
}
F_1 ( V_2 , F_6 ( & V_2 -> V_6 . V_8 ) ) ;
F_30 ( V_13 , V_45 , V_46 ) ;
V_2 -> V_6 . V_45 = V_45 ;
V_2 -> V_6 . V_46 = V_46 ;
V_2 -> V_6 . V_53 = true ;
F_31 ( V_13 -> V_54 , L_1
L_2 , V_2 -> V_18 ,
V_2 -> V_6 . V_24 , V_2 -> V_6 . V_7 ) ;
return 0 ;
}
int F_32 ( struct V_1 * V_2 )
{
int V_42 , V_55 ;
V_2 -> V_6 . V_7 = NULL ;
V_2 -> V_6 . V_24 = 0 ;
for ( V_42 = 0 ; V_42 < V_43 ; ++ V_42 )
V_2 -> V_6 . V_17 [ V_42 ] = 0 ;
F_33 ( & V_2 -> V_6 . V_8 , 0 ) ;
V_2 -> V_6 . V_53 = false ;
F_34 ( & V_2 -> V_6 . V_26 , F_17 ,
( unsigned long ) V_2 ) ;
F_35 ( & V_2 -> V_6 . V_21 ) ;
if ( V_56 ) {
long V_57 = F_36 ( V_58 ) ;
if ( V_57 == 0 ) {
V_57 = V_59 ;
}
V_55 = F_37 ( & V_2 -> V_60 , & V_61 ,
V_62 ,
V_57 , V_2 -> V_63 ) ;
if ( V_55 ) {
F_38 ( L_3 ,
V_2 -> V_63 ) ;
return V_55 ;
}
}
return 0 ;
}
int F_39 ( struct V_12 * V_13 )
{
if ( F_40 ( & V_64 ) == 1 ) {
V_14 = F_41 (
L_4 , sizeof( struct V_10 ) , 0 ,
V_65 , NULL ) ;
if ( ! V_14 )
return - V_16 ;
}
if ( F_42 ( V_13 ) )
F_43 ( V_13 -> V_54 , L_5 ) ;
return 0 ;
}
void F_44 ( struct V_12 * V_13 )
{
int V_42 , V_55 ;
if ( F_45 ( & V_64 ) )
F_46 ( V_14 ) ;
F_47 ( & V_13 -> V_66 ) ;
for ( V_42 = 0 ; V_42 < V_43 ; V_42 ++ ) {
struct V_1 * V_2 = V_13 -> V_67 [ V_42 ] ;
if ( ! V_2 || ! V_2 -> V_6 . V_53 )
continue;
V_55 = F_23 ( V_2 ) ;
if ( V_55 ) {
F_48 ( V_13 ) ;
}
F_16 ( & V_2 -> V_6 . V_21 ) ;
F_49 ( V_13 , V_2 -> V_6 . V_45 ,
V_2 -> V_6 . V_46 ) ;
F_50 ( & V_2 -> V_60 ) ;
F_51 ( & V_2 -> V_6 . V_26 ) ;
V_2 -> V_6 . V_53 = false ;
}
F_52 ( & V_13 -> V_66 ) ;
}
void F_53 ( struct V_12 * V_13 )
{
int V_42 , V_55 ;
F_47 ( & V_13 -> V_66 ) ;
for ( V_42 = 0 ; V_42 < V_43 ; V_42 ++ ) {
struct V_1 * V_2 = V_13 -> V_67 [ V_42 ] ;
if ( ! V_2 || ! V_2 -> V_6 . V_53 )
continue;
V_55 = F_23 ( V_2 ) ;
if ( V_55 ) {
F_48 ( V_13 ) ;
}
F_49 ( V_13 , V_2 -> V_6 . V_45 ,
V_2 -> V_6 . V_46 ) ;
}
F_52 ( & V_13 -> V_66 ) ;
}
void F_54 ( struct V_12 * V_13 )
{
int V_42 ;
F_47 ( & V_13 -> V_66 ) ;
for ( V_42 = 0 ; V_42 < V_43 ; V_42 ++ ) {
struct V_1 * V_2 = V_13 -> V_67 [ V_42 ] ;
if ( ! V_2 || ! V_2 -> V_6 . V_53 )
continue;
F_30 ( V_13 , V_2 -> V_6 . V_45 ,
V_2 -> V_6 . V_46 ) ;
}
F_52 ( & V_13 -> V_66 ) ;
}
void F_48 ( struct V_12 * V_13 )
{
int V_42 ;
for ( V_42 = 0 ; V_42 < V_43 ; V_42 ++ ) {
struct V_1 * V_2 = V_13 -> V_67 [ V_42 ] ;
if ( ! V_2 || ! V_2 -> V_6 . V_53 )
continue;
F_1 ( V_2 , V_2 -> V_6 . V_17 [ V_42 ] ) ;
}
}
static const char * F_55 ( struct V_11 * V_11 )
{
return L_6 ;
}
static const char * F_56 ( struct V_11 * V_68 )
{
struct V_10 * V_11 = F_57 ( V_68 ) ;
return ( const char * ) V_11 -> V_2 -> V_63 ;
}
static bool F_58 ( struct V_11 * V_68 )
{
struct V_10 * V_11 = F_57 ( V_68 ) ;
struct V_1 * V_2 = V_11 -> V_2 ;
if ( F_6 ( & V_2 -> V_6 . V_8 ) >= V_11 -> V_3 )
return true ;
F_15 ( V_2 ) ;
if ( F_6 ( & V_2 -> V_6 . V_8 ) >= V_11 -> V_3 )
return true ;
return false ;
}
static int F_59 ( T_4 * V_69 , unsigned V_70 , int V_71 , void * V_72 )
{
struct V_10 * V_11 ;
struct V_12 * V_13 ;
T_3 V_3 ;
int V_73 ;
V_11 = F_60 ( V_69 , struct V_10 , V_74 ) ;
V_13 = V_11 -> V_2 -> V_13 ;
V_3 = F_6 ( & V_11 -> V_2 -> V_6 . V_8 ) ;
if ( V_3 >= V_11 -> V_3 ) {
V_73 = F_61 ( & V_11 -> V_19 ) ;
if ( ! V_73 )
F_62 ( & V_11 -> V_19 , L_7 ) ;
else
F_62 ( & V_11 -> V_19 , L_8 ) ;
F_63 ( & V_11 -> V_2 -> V_6 . V_21 , & V_11 -> V_74 ) ;
F_64 ( & V_11 -> V_19 ) ;
} else
F_62 ( & V_11 -> V_19 , L_9 ) ;
return 0 ;
}
static bool F_65 ( struct V_11 * V_68 )
{
struct V_10 * V_11 = F_57 ( V_68 ) ;
struct V_1 * V_2 = V_11 -> V_2 ;
if ( F_6 ( & V_2 -> V_6 . V_8 ) >= V_11 -> V_3 )
return false ;
V_11 -> V_74 . V_71 = 0 ;
V_11 -> V_74 . V_75 = NULL ;
V_11 -> V_74 . V_76 = F_59 ;
F_66 ( & V_2 -> V_6 . V_21 , & V_11 -> V_74 ) ;
F_67 ( V_68 ) ;
if ( ! F_68 ( & V_2 -> V_6 . V_26 ) )
F_11 ( V_2 ) ;
F_62 ( & V_11 -> V_19 , L_10 , V_2 -> V_18 ) ;
return true ;
}
static void F_69 ( struct V_11 * V_68 )
{
struct V_10 * V_11 = F_57 ( V_68 ) ;
F_70 ( V_14 , V_11 ) ;
}
static int F_71 ( struct V_77 * V_78 , void * V_79 )
{
struct V_80 * V_81 = (struct V_80 * ) V_78 -> V_75 ;
struct V_82 * V_54 = V_81 -> V_83 -> V_54 ;
struct V_12 * V_13 = V_54 -> V_84 ;
int V_42 , V_85 ;
for ( V_42 = 0 ; V_42 < V_43 ; ++ V_42 ) {
struct V_1 * V_2 = V_13 -> V_67 [ V_42 ] ;
if ( ! V_2 || ! V_2 -> V_6 . V_53 )
continue;
F_15 ( V_2 ) ;
F_72 ( V_78 , L_11 , V_42 , V_2 -> V_63 ) ;
F_72 ( V_78 , L_12 ,
( unsigned long long ) F_6 ( & V_2 -> V_6 . V_8 ) ) ;
F_72 ( V_78 , L_13 ,
V_2 -> V_6 . V_17 [ V_42 ] ) ;
for ( V_85 = 0 ; V_85 < V_43 ; ++ V_85 ) {
struct V_1 * V_86 = V_13 -> V_67 [ V_85 ] ;
if ( V_42 != V_85 && V_86 && V_86 -> V_6 . V_53 &&
V_2 -> V_6 . V_17 [ V_85 ] )
F_72 ( V_78 , L_14 ,
V_85 , V_2 -> V_6 . V_17 [ V_85 ] ) ;
}
}
return 0 ;
}
int F_42 ( struct V_12 * V_13 )
{
#if F_73 ( V_87 )
return F_74 ( V_13 , V_88 , 1 ) ;
#else
return 0 ;
#endif
}
