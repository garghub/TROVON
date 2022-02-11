static struct V_1 * F_1 (
struct V_2 * V_3 , unsigned V_4 )
{
unsigned V_5 ;
for ( V_5 = 0 ; V_5 < V_3 -> V_6 ; V_5 ++ ) {
if ( V_4 >= V_3 -> V_7 [ V_5 ] . V_8 [ 0 ] &&
V_4 < V_3 -> V_7 [ V_5 ] . V_8 [ 0 ] +
V_3 -> V_7 [ V_5 ] . V_9 )
return & V_3 -> V_7 [ V_5 ] ;
}
return NULL ;
}
static struct V_1 * F_2 (
struct V_2 * V_3 , const char * V_10 )
{
unsigned V_5 ;
for ( V_5 = 0 ; V_5 < V_3 -> V_6 ; V_5 ++ ) {
if ( strcmp ( V_10 , V_3 -> V_7 [ V_5 ] . V_10 ) == 0 )
return & V_3 -> V_7 [ V_5 ] ;
}
return NULL ;
}
static struct V_11 * F_3 (
struct V_2 * V_3 , struct V_1 * V_12 ,
unsigned long V_13 )
{
unsigned V_5 ;
for ( V_5 = 0 ; V_5 < V_12 -> V_14 ; V_5 ++ ) {
if ( V_13 == V_12 -> V_15 [ V_5 ] . V_16 ) {
if ( ! V_3 -> V_17 || ( V_3 -> V_17 &
V_12 -> V_15 [ V_5 ] . V_17 ) )
return & V_12 -> V_15 [ V_5 ] ;
}
}
return NULL ;
}
static struct V_11 * F_4 (
struct V_2 * V_3 , struct V_1 * V_12 ,
const char * V_10 )
{
unsigned V_5 ;
for ( V_5 = 0 ; V_5 < V_12 -> V_14 ; V_5 ++ ) {
if ( strcmp ( V_10 , V_12 -> V_15 [ V_5 ] . V_10 ) == 0 ) {
if ( ! V_3 -> V_17 || ( V_3 -> V_17 &
V_12 -> V_15 [ V_5 ] . V_17 ) )
return & V_12 -> V_15 [ V_5 ] ;
}
}
return NULL ;
}
static struct V_11 * F_5 (
struct V_2 * V_3 , struct V_1 * V_12 )
{
unsigned V_5 ;
for ( V_5 = 0 ; V_5 < V_12 -> V_14 ; V_5 ++ ) {
if ( V_12 -> V_15 [ V_5 ] . V_18 &
( V_19 | V_20 ) ) {
if ( ! V_3 -> V_17 || ( V_3 -> V_17 &
V_12 -> V_15 [ V_5 ] . V_17 ) )
return & V_12 -> V_15 [ V_5 ] ;
}
}
return NULL ;
}
static struct V_21 * F_6 (
struct V_2 * V_3 , const char * V_10 )
{
unsigned V_5 ;
for ( V_5 = 0 ; V_5 < V_3 -> V_22 ; V_5 ++ ) {
if ( strcmp ( V_10 , V_3 -> V_23 [ V_5 ] . V_10 ) == 0 )
return & V_3 -> V_23 [ V_5 ] ;
}
return NULL ;
}
static int F_7 ( struct V_2 * V_3 ,
struct V_1 * V_12 ,
unsigned long * V_13 )
{
unsigned V_24 = V_12 -> V_25 ;
unsigned V_26 = ( V_24 / V_27 ) * V_28 ;
unsigned V_29 = ( V_24 % V_27 ) * V_28 ;
* V_13 = F_8 ( V_3 -> V_30 + V_26 ) ;
* V_13 >>= V_29 ;
* V_13 &= V_31 ;
return 0 ;
}
static int F_9 ( struct V_2 * V_3 ,
struct V_1 * V_12 ,
unsigned long V_13 )
{
unsigned V_24 = V_12 -> V_25 ;
unsigned V_26 = ( V_24 / V_27 ) * V_28 ;
unsigned V_29 = ( V_24 % V_27 ) * V_28 ;
unsigned long V_32 ;
V_32 = F_8 ( V_3 -> V_30 + V_26 ) ;
V_32 &= ~ ( V_31 << V_29 ) ;
V_32 |= ( V_13 << V_29 ) ;
F_10 ( V_32 , V_3 -> V_30 + V_26 ) ;
return 0 ;
}
static int F_11 ( struct V_33 * V_34 ,
unsigned V_25 , unsigned long * V_13 )
{
struct V_2 * V_3 = F_12 ( V_34 ) ;
struct V_1 * V_12 = & V_3 -> V_7 [ V_25 ] ;
if ( ! V_12 -> V_35 )
return - V_36 ;
if ( V_12 -> V_35 -> V_37 )
return V_12 -> V_35 -> V_37 ( V_12 -> V_35 , V_13 ) ;
return F_7 ( V_3 , V_12 , V_13 ) ;
}
static int F_13 ( struct V_33 * V_34 ,
unsigned V_25 , unsigned long * V_38 ,
unsigned V_39 )
{
struct V_2 * V_3 = F_12 ( V_34 ) ;
struct V_1 * V_12 = & V_3 -> V_7 [ V_25 ] ;
int V_40 , V_41 ;
if ( ! V_12 -> V_35 )
return - V_36 ;
for ( V_40 = 0 ; V_40 < V_39 ; V_40 ++ ) {
if ( V_12 -> V_35 -> V_42 )
V_41 = V_12 -> V_35 -> V_42 ( V_12 -> V_35 , V_38 [ V_40 ] ) ;
else
V_41 = F_9 ( V_3 , V_12 , V_38 [ V_40 ] ) ;
if ( V_41 )
return V_41 ;
}
return 0 ;
}
static void F_14 ( struct V_33 * V_34 ,
struct V_43 * V_44 , unsigned V_25 )
{
struct V_2 * V_3 = F_12 ( V_34 ) ;
struct V_1 * V_12 = & V_3 -> V_7 [ V_25 ] ;
struct V_11 * V_45 ;
unsigned long V_13 ;
unsigned V_5 ;
if ( F_11 ( V_34 , V_25 , & V_13 ) )
return;
V_45 = F_3 ( V_3 , V_12 , V_13 ) ;
if ( V_45 ) {
F_15 ( V_44 , L_1 , V_45 -> V_10 ) ;
if ( V_45 -> V_46 )
F_15 ( V_44 , L_2 , V_45 -> V_46 ) ;
if ( V_45 -> V_18 & ( V_19 | V_20 ) ) {
F_15 ( V_44 , L_3 ) ;
if ( V_45 -> V_18 & V_20 )
F_15 ( V_44 , L_4 ) ;
if ( V_45 -> V_18 & V_19 )
F_15 ( V_44 , L_5 ) ;
F_15 ( V_44 , L_6 ) ;
}
} else
F_15 ( V_44 , L_7 ) ;
if ( V_12 -> V_14 > 1 ) {
F_15 ( V_44 , L_8 ) ;
for ( V_5 = 0 ; V_5 < V_12 -> V_14 ; V_5 ++ ) {
if ( V_45 == & V_12 -> V_15 [ V_5 ] )
continue;
if ( V_3 -> V_17 &&
! ( V_3 -> V_17 & V_12 -> V_15 [ V_5 ] . V_17 ) )
continue;
F_15 ( V_44 , L_9 , V_12 -> V_15 [ V_5 ] . V_10 ) ;
if ( V_12 -> V_15 [ V_5 ] . V_46 )
F_15 ( V_44 , L_2 , V_12 -> V_15 [ V_5 ] . V_46 ) ;
if ( V_12 -> V_15 [ V_5 ] . V_18 &
( V_19 | V_20 ) ) {
F_15 ( V_44 , L_3 ) ;
if ( V_12 -> V_15 [ V_5 ] . V_18 & V_20 )
F_15 ( V_44 , L_4 ) ;
if ( V_12 -> V_15 [ V_5 ] . V_18 & V_19 )
F_15 ( V_44 , L_5 ) ;
F_15 ( V_44 , L_6 ) ;
}
}
F_15 ( V_44 , L_10 ) ;
}
return;
}
static int F_16 ( struct V_33 * V_34 )
{
struct V_2 * V_3 = F_12 ( V_34 ) ;
return V_3 -> V_22 ;
}
static const char * F_17 ( struct V_33 * V_34 ,
unsigned V_47 )
{
struct V_2 * V_3 = F_12 ( V_34 ) ;
return V_3 -> V_23 [ V_47 ] . V_10 ;
}
static int F_18 ( struct V_33 * V_34 , unsigned V_47 ,
const char * const * * V_7 ,
unsigned * const V_6 )
{
struct V_2 * V_3 = F_12 ( V_34 ) ;
* V_7 = V_3 -> V_23 [ V_47 ] . V_7 ;
* V_6 = V_3 -> V_23 [ V_47 ] . V_6 ;
return 0 ;
}
static int F_19 ( struct V_33 * V_34 , unsigned V_47 ,
unsigned V_25 )
{
struct V_2 * V_3 = F_12 ( V_34 ) ;
struct V_21 * V_48 = & V_3 -> V_23 [ V_47 ] ;
struct V_1 * V_12 = & V_3 -> V_7 [ V_25 ] ;
struct V_11 * V_49 ;
int V_41 ;
unsigned long V_13 ;
V_49 = F_4 ( V_3 , V_12 ,
V_48 -> V_10 ) ;
if ( ! V_49 ) {
F_20 ( V_3 -> V_50 ,
L_11 ,
V_48 -> V_10 , V_48 -> V_7 [ V_25 ] ) ;
return - V_36 ;
}
V_13 = V_49 -> V_16 ;
V_41 = F_13 ( V_34 , V_12 -> V_25 , & V_13 , 1 ) ;
if ( V_41 ) {
F_20 ( V_3 -> V_50 , L_12 ,
V_48 -> V_7 [ V_25 ] , V_48 -> V_10 ) ;
return V_41 ;
}
return 0 ;
}
static int F_21 ( struct V_33 * V_34 ,
struct V_51 * V_52 , unsigned V_53 )
{
struct V_2 * V_3 = F_12 ( V_34 ) ;
struct V_1 * V_12 ;
struct V_11 * V_49 ;
unsigned long V_13 ;
V_12 = F_1 ( V_3 , V_53 ) ;
if ( ! V_12 )
return - V_36 ;
if ( V_12 -> V_35 -> V_54 )
return V_12 -> V_35 -> V_54 ( V_12 -> V_35 , V_53 ) ;
V_49 = F_5 ( V_3 , V_12 ) ;
if ( ! V_49 )
return - V_55 ;
V_13 = V_49 -> V_16 ;
return F_13 ( V_34 , V_12 -> V_25 , & V_13 , 1 ) ;
}
static int F_22 ( struct V_33 * V_34 ,
struct V_51 * V_52 , unsigned V_53 , bool V_56 )
{
struct V_2 * V_3 = F_12 ( V_34 ) ;
struct V_1 * V_12 ;
struct V_11 * V_49 ;
V_12 = F_1 ( V_3 , V_53 ) ;
if ( ! V_12 )
return - V_36 ;
if ( V_12 -> V_35 -> V_57 )
return V_12 -> V_35 -> V_57 ( V_12 -> V_35 , V_53 , V_56 ) ;
V_49 = F_5 ( V_3 , V_12 ) ;
if ( ! V_49 )
return - V_55 ;
if ( ( V_56 && ( V_49 -> V_18 & V_20 ) ) ||
( ! V_56 && ( V_49 -> V_18 & V_19 ) ) )
return 0 ;
return - V_55 ;
}
static int F_23 ( struct V_33 * V_34 )
{
struct V_2 * V_3 = F_12 ( V_34 ) ;
return V_3 -> V_6 ;
}
static const char * F_24 ( struct V_33 * V_34 ,
unsigned V_25 )
{
struct V_2 * V_3 = F_12 ( V_34 ) ;
return V_3 -> V_7 [ V_25 ] . V_10 ;
}
static int F_25 ( struct V_33 * V_34 ,
unsigned V_25 , const unsigned * * V_8 ,
unsigned * V_58 )
{
struct V_2 * V_3 = F_12 ( V_34 ) ;
* V_8 = V_3 -> V_7 [ V_25 ] . V_8 ;
* V_58 = V_3 -> V_7 [ V_25 ] . V_9 ;
return 0 ;
}
static int F_26 ( struct V_33 * V_34 ,
struct V_59 * V_60 ,
struct V_61 * * V_62 ,
unsigned * V_63 )
{
struct V_2 * V_3 = F_12 ( V_34 ) ;
struct V_64 * V_65 ;
const char * V_66 ;
const char * V_67 ;
int V_41 , V_68 , V_5 ;
* V_62 = NULL ;
* V_63 = 0 ;
V_41 = F_27 ( V_60 , L_13 , & V_66 ) ;
if ( V_41 ) {
F_20 ( V_3 -> V_50 ,
L_14 , V_60 -> V_10 ) ;
return 0 ;
}
V_68 = F_28 ( V_60 , L_15 ) ;
if ( V_68 < 0 ) {
F_20 ( V_3 -> V_50 ,
L_16 , V_60 -> V_10 ) ;
return 0 ;
}
* V_62 = F_29 ( V_68 * sizeof( struct V_61 ) , V_69 ) ;
if ( * V_62 == NULL ) {
F_20 ( V_3 -> V_50 ,
L_17 ,
V_60 -> V_10 ) ;
return - V_70 ;
}
V_5 = 0 ;
F_30 (np, L_15 , prop, group) {
struct V_1 * V_12 =
F_2 ( V_3 , V_67 ) ;
if ( ! V_12 ) {
F_20 ( V_3 -> V_50 , L_18 , V_67 ) ;
continue;
}
if ( ! F_4 ( V_3 , V_12 , V_66 ) ) {
F_20 ( V_3 -> V_50 , L_19 ,
V_66 , V_67 ) ;
continue;
}
( * V_62 ) [ V_5 ] . type = V_71 ;
( * V_62 ) [ V_5 ] . V_72 . V_73 . V_67 = V_67 ;
( * V_62 ) [ V_5 ] . V_72 . V_73 . V_66 = V_66 ;
V_5 ++ ;
}
* V_63 = V_68 ;
return 0 ;
}
static void F_31 ( struct V_33 * V_34 ,
struct V_61 * V_62 , unsigned V_63 )
{
F_32 ( V_62 ) ;
}
static int F_33 ( struct V_21 * V_74 , int * V_75 ,
const char * V_10 )
{
if ( * V_75 <= 0 )
return - V_76 ;
while ( V_74 -> V_6 ) {
if ( strcmp ( V_74 -> V_10 , V_10 ) == 0 ) {
V_74 -> V_6 ++ ;
return - V_77 ;
}
V_74 ++ ;
}
V_74 -> V_10 = V_10 ;
V_74 -> V_6 = 1 ;
( * V_75 ) -- ;
return 0 ;
}
static int F_34 ( struct V_78 * V_79 ,
struct V_2 * V_3 )
{
struct V_21 * V_74 ;
int V_80 = 0 , V_75 = V_3 -> V_81 . V_9 ;
int V_5 , V_44 ;
V_74 = F_35 ( & V_79 -> V_50 , V_75 *
sizeof( struct V_21 ) , V_69 ) ;
if ( ! V_74 )
return - V_70 ;
for ( V_5 = 0 ; V_5 < V_3 -> V_6 ; V_5 ++ ) {
struct V_1 * V_12 = & V_3 -> V_7 [ V_5 ] ;
for ( V_44 = 0 ; V_44 < V_12 -> V_14 ; V_44 ++ ) {
int V_41 ;
if ( V_3 -> V_17 &&
! ( V_3 -> V_17 & V_12 -> V_15 [ V_44 ] . V_17 ) )
continue;
V_41 = F_33 ( V_74 , & V_75 ,
V_12 -> V_15 [ V_44 ] . V_10 ) ;
if ( V_41 == - V_76 )
F_20 ( & V_79 -> V_50 ,
L_20 ,
V_3 -> V_81 . V_9 ) ;
if ( V_41 < 0 )
continue;
V_80 ++ ;
}
}
V_3 -> V_22 = V_80 ;
V_3 -> V_23 = V_74 ;
for ( V_5 = 0 ; V_5 < V_3 -> V_6 ; V_5 ++ ) {
struct V_1 * V_12 = & V_3 -> V_7 [ V_5 ] ;
for ( V_44 = 0 ; V_44 < V_12 -> V_14 ; V_44 ++ ) {
struct V_21 * V_82 ;
const char * * V_7 ;
if ( V_3 -> V_17 &&
! ( V_3 -> V_17 & V_12 -> V_15 [ V_44 ] . V_17 ) )
continue;
V_82 = F_6 ( V_3 ,
V_12 -> V_15 [ V_44 ] . V_10 ) ;
if ( ! V_82 -> V_7 ) {
V_82 -> V_7 = F_35 ( & V_79 -> V_50 ,
V_82 -> V_6 * sizeof( char * ) ,
V_69 ) ;
if ( ! V_82 -> V_7 )
return - V_70 ;
}
V_7 = V_82 -> V_7 ;
while ( * V_7 )
V_7 ++ ;
* V_7 = V_12 -> V_10 ;
}
}
return 0 ;
}
int F_36 ( struct V_78 * V_79 )
{
struct V_83 * V_84 = F_37 ( & V_79 -> V_50 ) ;
struct V_85 * V_86 ;
struct V_2 * V_3 ;
void T_1 * V_30 ;
struct V_87 * V_88 ;
unsigned V_25 , V_5 , V_89 ;
int V_41 ;
if ( ! V_84 || ! V_84 -> V_90 || ! V_84 -> V_91 ) {
F_20 ( & V_79 -> V_50 , L_21 ) ;
return - V_36 ;
}
V_86 = F_38 ( V_79 , V_92 , 0 ) ;
V_30 = F_39 ( & V_79 -> V_50 , V_86 ) ;
if ( F_40 ( V_30 ) )
return F_41 ( V_30 ) ;
V_3 = F_35 ( & V_79 -> V_50 , sizeof( struct V_2 ) ,
V_69 ) ;
if ( ! V_3 ) {
F_20 ( & V_79 -> V_50 , L_22 ) ;
return - V_70 ;
}
V_3 -> V_81 . V_10 = F_42 ( & V_79 -> V_50 ) ;
V_3 -> V_81 . V_93 = V_94 ;
V_3 -> V_81 . V_95 = & V_96 ;
V_3 -> V_81 . V_97 = & V_98 ;
V_3 -> V_81 . V_99 = & V_100 ;
V_3 -> V_17 = V_84 -> V_17 ;
V_3 -> V_30 = V_30 ;
V_3 -> V_50 = & V_79 -> V_50 ;
F_43 ( V_79 , V_3 ) ;
V_3 -> V_6 = 0 ;
V_3 -> V_81 . V_9 = 0 ;
for ( V_5 = 0 ; V_5 < V_84 -> V_101 ; V_5 ++ ) {
struct V_102 * V_35 = & V_84 -> V_90 [ V_5 ] ;
char * V_103 ;
V_3 -> V_81 . V_9 += V_35 -> V_9 ;
for ( V_89 = 0 ; V_89 < V_35 -> V_9 ; V_89 ++ )
V_35 -> V_8 [ V_89 ] = V_35 -> V_4 + V_89 ;
if ( V_35 -> V_37 || V_35 -> V_42 ) {
if ( ! V_35 -> V_10 || ! V_35 -> V_37 || ! V_35 -> V_42 ) {
F_20 ( & V_79 -> V_50 , L_23 ) ;
return - V_36 ;
}
V_3 -> V_6 += 1 ;
continue;
}
V_103 = F_35 ( & V_79 -> V_50 , V_35 -> V_9 * 8 , V_69 ) ;
if ( ! V_103 ) {
F_20 ( & V_79 -> V_50 , L_24 ) ;
return - V_70 ;
}
for ( V_89 = 0 ; V_89 < V_35 -> V_9 ; V_89 ++ )
sprintf ( V_103 + 8 * V_89 , L_25 , V_35 -> V_4 + V_89 ) ;
V_35 -> V_10 = V_103 ;
V_3 -> V_6 += V_35 -> V_9 ;
}
V_88 = F_35 ( & V_79 -> V_50 , V_3 -> V_81 . V_9 *
sizeof( struct V_87 ) , V_69 ) ;
if ( ! V_88 ) {
F_20 ( & V_79 -> V_50 , L_26 ) ;
return - V_70 ;
}
for ( V_5 = 0 ; V_5 < V_3 -> V_81 . V_9 ; V_5 ++ )
V_88 [ V_5 ] . V_104 = V_5 ;
V_3 -> V_81 . V_8 = V_88 ;
V_3 -> V_7 = F_35 ( & V_79 -> V_50 , V_3 -> V_6 *
sizeof( struct V_1 ) , V_69 ) ;
if ( ! V_3 -> V_7 ) {
F_20 ( & V_79 -> V_50 , L_27 ) ;
return - V_70 ;
}
V_25 = 0 ;
for ( V_5 = 0 ; V_5 < V_84 -> V_101 ; V_5 ++ ) {
struct V_102 * V_35 = & V_84 -> V_90 [ V_5 ] ;
V_3 -> V_7 [ V_25 ] . V_25 = V_25 ;
V_3 -> V_7 [ V_25 ] . V_35 = V_35 ;
V_3 -> V_7 [ V_25 ] . V_10 = V_35 -> V_10 ;
V_3 -> V_7 [ V_25 ] . V_8 = V_35 -> V_8 ;
V_3 -> V_7 [ V_25 ] . V_9 = V_35 -> V_9 ;
if ( ! V_35 -> V_37 && ! V_35 -> V_42 ) {
V_3 -> V_7 [ V_25 ] . V_9 = 1 ;
for ( V_89 = 1 ; V_89 < V_35 -> V_9 ; V_89 ++ ) {
V_25 ++ ;
V_3 -> V_7 [ V_25 ] . V_25 = V_25 ;
V_3 -> V_7 [ V_25 ] . V_35 = V_35 ;
V_3 -> V_7 [ V_25 ] . V_10 = & V_35 -> V_10 [ 8 * V_89 ] ;
V_3 -> V_7 [ V_25 ] . V_8 = & V_35 -> V_8 [ V_89 ] ;
V_3 -> V_7 [ V_25 ] . V_9 = 1 ;
}
}
V_25 ++ ;
}
for ( V_5 = 0 ; V_5 < V_84 -> V_105 ; V_5 ++ ) {
struct V_106 * V_107 = & V_84 -> V_91 [ V_5 ] ;
struct V_1 * V_12 =
F_1 ( V_3 , V_107 -> V_4 ) ;
unsigned V_14 ;
if ( ! V_12 ) {
F_44 ( & V_79 -> V_50 , L_28 ,
V_107 -> V_4 ) ;
continue;
}
for ( V_14 = 0 ; ; ) {
struct V_11 * V_108 =
& V_107 -> V_15 [ V_14 ] ;
if ( ! V_108 -> V_10 )
break;
V_14 ++ ;
if ( V_3 -> V_17 && ! ( V_3 -> V_17 & V_108 -> V_17 ) )
continue;
if ( strcmp ( V_108 -> V_10 , L_29 ) == 0 )
V_108 -> V_18 = V_20 |
V_19 ;
else if ( strcmp ( V_108 -> V_10 , L_30 ) == 0 )
V_108 -> V_18 = V_19 ;
else if ( strcmp ( V_108 -> V_10 , L_31 ) == 0 )
V_108 -> V_18 = V_20 ;
}
V_12 -> V_15 = V_107 -> V_15 ;
V_12 -> V_14 = V_14 ;
}
V_41 = F_34 ( V_79 , V_3 ) ;
if ( V_41 ) {
F_20 ( & V_79 -> V_50 , L_32 ) ;
return V_41 ;
}
V_3 -> V_34 = F_45 ( & V_3 -> V_81 , & V_79 -> V_50 , V_3 ) ;
if ( ! V_3 -> V_34 ) {
F_20 ( & V_79 -> V_50 , L_33 ) ;
return - V_36 ;
}
F_46 ( & V_79 -> V_50 , L_34 ) ;
for ( V_5 = 0 ; V_5 < V_84 -> V_109 ; V_5 ++ )
F_47 ( V_3 -> V_34 , & V_84 -> V_110 [ V_5 ] ) ;
return 0 ;
}
int F_48 ( struct V_78 * V_79 )
{
struct V_2 * V_3 = F_49 ( V_79 ) ;
F_50 ( V_3 -> V_34 ) ;
return 0 ;
}
