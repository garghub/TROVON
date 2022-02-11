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
unsigned V_25 , unsigned long V_13 )
{
struct V_2 * V_3 = F_12 ( V_34 ) ;
struct V_1 * V_12 = & V_3 -> V_7 [ V_25 ] ;
if ( ! V_12 -> V_35 )
return - V_36 ;
if ( V_12 -> V_35 -> V_38 )
return V_12 -> V_35 -> V_38 ( V_12 -> V_35 , V_13 ) ;
return F_9 ( V_3 , V_12 , V_13 ) ;
}
static void F_14 ( struct V_33 * V_34 ,
struct V_39 * V_40 , unsigned V_25 )
{
struct V_2 * V_3 = F_12 ( V_34 ) ;
struct V_1 * V_12 = & V_3 -> V_7 [ V_25 ] ;
struct V_11 * V_41 ;
unsigned long V_13 ;
unsigned V_5 ;
if ( F_11 ( V_34 , V_25 , & V_13 ) )
return;
V_41 = F_3 ( V_3 , V_12 , V_13 ) ;
if ( V_41 ) {
F_15 ( V_40 , L_1 , V_41 -> V_10 ) ;
if ( V_41 -> V_42 )
F_15 ( V_40 , L_2 , V_41 -> V_42 ) ;
if ( V_41 -> V_18 & ( V_19 | V_20 ) ) {
F_15 ( V_40 , L_3 ) ;
if ( V_41 -> V_18 & V_20 )
F_15 ( V_40 , L_4 ) ;
if ( V_41 -> V_18 & V_19 )
F_15 ( V_40 , L_5 ) ;
F_15 ( V_40 , L_6 ) ;
}
} else
F_15 ( V_40 , L_7 ) ;
if ( V_12 -> V_14 > 1 ) {
F_15 ( V_40 , L_8 ) ;
for ( V_5 = 0 ; V_5 < V_12 -> V_14 ; V_5 ++ ) {
if ( V_41 == & V_12 -> V_15 [ V_5 ] )
continue;
if ( V_3 -> V_17 &&
! ( V_3 -> V_17 & V_12 -> V_15 [ V_5 ] . V_17 ) )
continue;
F_15 ( V_40 , L_9 , V_12 -> V_15 [ V_5 ] . V_10 ) ;
if ( V_12 -> V_15 [ V_5 ] . V_42 )
F_15 ( V_40 , L_2 , V_12 -> V_15 [ V_5 ] . V_42 ) ;
if ( V_12 -> V_15 [ V_5 ] . V_18 &
( V_19 | V_20 ) ) {
F_15 ( V_40 , L_3 ) ;
if ( V_12 -> V_15 [ V_5 ] . V_18 & V_20 )
F_15 ( V_40 , L_4 ) ;
if ( V_12 -> V_15 [ V_5 ] . V_18 & V_19 )
F_15 ( V_40 , L_5 ) ;
F_15 ( V_40 , L_6 ) ;
}
}
F_15 ( V_40 , L_10 ) ;
}
return;
}
static int F_16 ( struct V_33 * V_34 )
{
struct V_2 * V_3 = F_12 ( V_34 ) ;
return V_3 -> V_22 ;
}
static const char * F_17 ( struct V_33 * V_34 ,
unsigned V_43 )
{
struct V_2 * V_3 = F_12 ( V_34 ) ;
return V_3 -> V_23 [ V_43 ] . V_10 ;
}
static int F_18 ( struct V_33 * V_34 , unsigned V_43 ,
const char * const * * V_7 ,
unsigned * const V_6 )
{
struct V_2 * V_3 = F_12 ( V_34 ) ;
* V_7 = V_3 -> V_23 [ V_43 ] . V_7 ;
* V_6 = V_3 -> V_23 [ V_43 ] . V_6 ;
return 0 ;
}
static int F_19 ( struct V_33 * V_34 , unsigned V_43 ,
unsigned V_25 )
{
struct V_2 * V_3 = F_12 ( V_34 ) ;
struct V_21 * V_44 = & V_3 -> V_23 [ V_43 ] ;
struct V_1 * V_12 = & V_3 -> V_7 [ V_25 ] ;
struct V_11 * V_45 ;
int V_46 ;
V_45 = F_4 ( V_3 , V_12 ,
V_44 -> V_10 ) ;
if ( ! V_45 ) {
F_20 ( V_3 -> V_47 ,
L_11 ,
V_44 -> V_10 , V_44 -> V_7 [ V_25 ] ) ;
return - V_36 ;
}
V_46 = F_13 ( V_34 , V_12 -> V_25 , V_45 -> V_16 ) ;
if ( V_46 ) {
F_20 ( V_3 -> V_47 , L_12 ,
V_44 -> V_7 [ V_25 ] , V_44 -> V_10 ) ;
return V_46 ;
}
return 0 ;
}
static int F_21 ( struct V_33 * V_34 ,
struct V_48 * V_49 , unsigned V_50 )
{
struct V_2 * V_3 = F_12 ( V_34 ) ;
struct V_1 * V_12 ;
struct V_11 * V_45 ;
V_12 = F_1 ( V_3 , V_50 ) ;
if ( ! V_12 )
return - V_36 ;
if ( V_12 -> V_35 -> V_51 )
return V_12 -> V_35 -> V_51 ( V_12 -> V_35 , V_50 ) ;
V_45 = F_5 ( V_3 , V_12 ) ;
if ( ! V_45 )
return - V_52 ;
return F_13 ( V_34 , V_12 -> V_25 , V_45 -> V_16 ) ;
}
static int F_22 ( struct V_33 * V_34 ,
struct V_48 * V_49 , unsigned V_50 , bool V_53 )
{
struct V_2 * V_3 = F_12 ( V_34 ) ;
struct V_1 * V_12 ;
struct V_11 * V_45 ;
V_12 = F_1 ( V_3 , V_50 ) ;
if ( ! V_12 )
return - V_36 ;
if ( V_12 -> V_35 -> V_54 )
return V_12 -> V_35 -> V_54 ( V_12 -> V_35 , V_50 , V_53 ) ;
V_45 = F_5 ( V_3 , V_12 ) ;
if ( ! V_45 )
return - V_52 ;
if ( ( V_53 && ( V_45 -> V_18 & V_20 ) ) ||
( ! V_53 && ( V_45 -> V_18 & V_19 ) ) )
return 0 ;
return - V_52 ;
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
unsigned * V_55 )
{
struct V_2 * V_3 = F_12 ( V_34 ) ;
* V_8 = V_3 -> V_7 [ V_25 ] . V_8 ;
* V_55 = V_3 -> V_7 [ V_25 ] . V_9 ;
return 0 ;
}
static int F_26 ( struct V_33 * V_34 ,
struct V_56 * V_57 ,
struct V_58 * * V_59 ,
unsigned * V_60 )
{
struct V_2 * V_3 = F_12 ( V_34 ) ;
struct V_61 * V_62 ;
const char * V_63 ;
const char * V_64 ;
int V_46 , V_65 , V_5 ;
* V_59 = NULL ;
* V_60 = 0 ;
V_46 = F_27 ( V_57 , L_13 , & V_63 ) ;
if ( V_46 ) {
F_20 ( V_3 -> V_47 ,
L_14 , V_57 -> V_10 ) ;
return 0 ;
}
V_65 = F_28 ( V_57 , L_15 ) ;
if ( V_65 < 0 ) {
F_20 ( V_3 -> V_47 ,
L_16 , V_57 -> V_10 ) ;
return 0 ;
}
* V_59 = F_29 ( V_65 * sizeof( struct V_58 ) , V_66 ) ;
if ( V_59 == NULL ) {
F_20 ( V_3 -> V_47 ,
L_17 ,
V_57 -> V_10 ) ;
return - V_67 ;
}
V_5 = 0 ;
F_30 (np, L_15 , prop, group) {
struct V_1 * V_12 =
F_2 ( V_3 , V_64 ) ;
if ( ! V_12 ) {
F_20 ( V_3 -> V_47 , L_18 , V_64 ) ;
continue;
}
if ( ! F_4 ( V_3 , V_12 , V_63 ) ) {
F_20 ( V_3 -> V_47 , L_19 ,
V_63 , V_64 ) ;
continue;
}
( * V_59 ) [ V_5 ] . type = V_68 ;
( * V_59 ) [ V_5 ] . V_69 . V_70 . V_64 = V_64 ;
( * V_59 ) [ V_5 ] . V_69 . V_70 . V_63 = V_63 ;
V_5 ++ ;
}
* V_60 = V_65 ;
return 0 ;
}
static void F_31 ( struct V_33 * V_34 ,
struct V_58 * V_59 , unsigned V_60 )
{
F_32 ( V_59 ) ;
}
static int F_33 ( struct V_21 * V_71 , const char * V_10 )
{
while ( V_71 -> V_6 ) {
if ( strcmp ( V_71 -> V_10 , V_10 ) == 0 ) {
V_71 -> V_6 ++ ;
return - V_72 ;
}
V_71 ++ ;
}
V_71 -> V_10 = V_10 ;
V_71 -> V_6 = 1 ;
return 0 ;
}
static int F_34 ( struct V_73 * V_74 ,
struct V_2 * V_3 )
{
struct V_21 * V_71 ;
int V_75 = 0 ;
int V_5 , V_40 ;
V_71 = F_35 ( & V_74 -> V_47 , V_3 -> V_76 . V_9 *
sizeof( struct V_21 ) , V_66 ) ;
if ( ! V_71 )
return - V_67 ;
for ( V_5 = 0 ; V_5 < V_3 -> V_6 ; V_5 ++ ) {
struct V_1 * V_12 = & V_3 -> V_7 [ V_5 ] ;
for ( V_40 = 0 ; V_40 < V_12 -> V_14 ; V_40 ++ ) {
if ( V_3 -> V_17 &&
! ( V_3 -> V_17 & V_12 -> V_15 [ V_40 ] . V_17 ) )
continue;
if ( F_33 ( V_71 , V_12 -> V_15 [ V_40 ] . V_10 ) )
continue;
V_75 ++ ;
}
}
V_71 = F_36 ( V_71 , V_75 * sizeof( struct V_21 ) ,
V_66 ) ;
if ( ! V_71 )
return - V_67 ;
V_3 -> V_22 = V_75 ;
V_3 -> V_23 = V_71 ;
for ( V_5 = 0 ; V_5 < V_3 -> V_6 ; V_5 ++ ) {
struct V_1 * V_12 = & V_3 -> V_7 [ V_5 ] ;
for ( V_40 = 0 ; V_40 < V_12 -> V_14 ; V_40 ++ ) {
struct V_21 * V_77 ;
const char * * V_7 ;
if ( V_3 -> V_17 &&
! ( V_3 -> V_17 & V_12 -> V_15 [ V_40 ] . V_17 ) )
continue;
V_77 = F_6 ( V_3 ,
V_12 -> V_15 [ V_40 ] . V_10 ) ;
if ( ! V_77 -> V_7 ) {
V_77 -> V_7 = F_35 ( & V_74 -> V_47 ,
V_77 -> V_6 * sizeof( char * ) ,
V_66 ) ;
if ( ! V_77 -> V_7 )
return - V_67 ;
}
V_7 = V_77 -> V_7 ;
while ( * V_7 )
V_7 ++ ;
* V_7 = V_12 -> V_10 ;
}
}
return 0 ;
}
int F_37 ( struct V_73 * V_74 )
{
struct V_78 * V_79 = F_38 ( & V_74 -> V_47 ) ;
struct V_56 * V_57 = V_74 -> V_47 . V_80 ;
struct V_2 * V_3 ;
void T_1 * V_30 ;
struct V_81 * V_82 ;
unsigned V_25 , V_5 , V_83 ;
int V_46 ;
if ( ! V_79 || ! V_79 -> V_84 || ! V_79 -> V_85 ) {
F_20 ( & V_74 -> V_47 , L_20 ) ;
return - V_36 ;
}
V_30 = F_39 ( V_57 , 0 ) ;
if ( ! V_30 ) {
F_20 ( & V_74 -> V_47 , L_21 ) ;
return - V_86 ;
}
V_3 = F_35 ( & V_74 -> V_47 , sizeof( struct V_2 ) ,
V_66 ) ;
if ( ! V_3 ) {
F_20 ( & V_74 -> V_47 , L_22 ) ;
return - V_67 ;
}
V_3 -> V_76 . V_10 = F_40 ( & V_74 -> V_47 ) ;
V_3 -> V_76 . V_87 = V_88 ;
V_3 -> V_76 . V_89 = & V_90 ;
V_3 -> V_76 . V_91 = & V_92 ;
V_3 -> V_76 . V_93 = & V_94 ;
V_3 -> V_17 = V_79 -> V_17 ;
V_3 -> V_30 = V_30 ;
V_3 -> V_47 = & V_74 -> V_47 ;
F_41 ( V_74 , V_3 ) ;
V_3 -> V_6 = 0 ;
V_3 -> V_76 . V_9 = 0 ;
for ( V_5 = 0 ; V_5 < V_79 -> V_95 ; V_5 ++ ) {
struct V_96 * V_35 = & V_79 -> V_84 [ V_5 ] ;
char * V_97 ;
V_3 -> V_76 . V_9 += V_35 -> V_9 ;
for ( V_83 = 0 ; V_83 < V_35 -> V_9 ; V_83 ++ )
V_35 -> V_8 [ V_83 ] = V_35 -> V_4 + V_83 ;
if ( V_35 -> V_37 || V_35 -> V_38 ) {
if ( ! V_35 -> V_10 || ! V_35 -> V_38 || ! V_35 -> V_38 ) {
F_20 ( & V_74 -> V_47 , L_23 ) ;
return - V_36 ;
}
V_3 -> V_6 += 1 ;
continue;
}
V_97 = F_35 ( & V_74 -> V_47 , V_35 -> V_9 * 8 , V_66 ) ;
if ( ! V_97 ) {
F_20 ( & V_74 -> V_47 , L_24 ) ;
return - V_67 ;
}
for ( V_83 = 0 ; V_83 < V_35 -> V_9 ; V_83 ++ )
sprintf ( V_97 + 8 * V_83 , L_25 , V_35 -> V_4 + V_83 ) ;
V_35 -> V_10 = V_97 ;
V_3 -> V_6 += V_35 -> V_9 ;
}
V_82 = F_35 ( & V_74 -> V_47 , V_3 -> V_76 . V_9 *
sizeof( struct V_81 ) , V_66 ) ;
if ( ! V_82 ) {
F_20 ( & V_74 -> V_47 , L_26 ) ;
return - V_67 ;
}
for ( V_5 = 0 ; V_5 < V_3 -> V_76 . V_9 ; V_5 ++ )
V_82 [ V_5 ] . V_98 = V_5 ;
V_3 -> V_76 . V_8 = V_82 ;
V_3 -> V_7 = F_35 ( & V_74 -> V_47 , V_3 -> V_6 *
sizeof( struct V_1 ) , V_66 ) ;
if ( ! V_3 -> V_7 ) {
F_20 ( & V_74 -> V_47 , L_27 ) ;
return - V_67 ;
}
V_25 = 0 ;
for ( V_5 = 0 ; V_5 < V_79 -> V_95 ; V_5 ++ ) {
struct V_96 * V_35 = & V_79 -> V_84 [ V_5 ] ;
V_3 -> V_7 [ V_25 ] . V_25 = V_25 ;
V_3 -> V_7 [ V_25 ] . V_35 = V_35 ;
V_3 -> V_7 [ V_25 ] . V_10 = V_35 -> V_10 ;
V_3 -> V_7 [ V_25 ] . V_8 = V_35 -> V_8 ;
V_3 -> V_7 [ V_25 ] . V_9 = V_35 -> V_9 ;
if ( ! V_35 -> V_37 && ! V_35 -> V_38 ) {
V_3 -> V_7 [ V_25 ] . V_9 = 1 ;
for ( V_83 = 1 ; V_83 < V_35 -> V_9 ; V_83 ++ ) {
V_25 ++ ;
V_3 -> V_7 [ V_25 ] . V_25 = V_25 ;
V_3 -> V_7 [ V_25 ] . V_35 = V_35 ;
V_3 -> V_7 [ V_25 ] . V_10 = & V_35 -> V_10 [ 8 * V_83 ] ;
V_3 -> V_7 [ V_25 ] . V_8 = & V_35 -> V_8 [ V_83 ] ;
V_3 -> V_7 [ V_25 ] . V_9 = 1 ;
}
}
V_25 ++ ;
}
for ( V_5 = 0 ; V_5 < V_79 -> V_99 ; V_5 ++ ) {
struct V_100 * V_101 = & V_79 -> V_85 [ V_5 ] ;
struct V_1 * V_12 =
F_1 ( V_3 , V_101 -> V_4 ) ;
unsigned V_14 ;
if ( ! V_12 ) {
F_42 ( & V_74 -> V_47 , L_28 ,
V_101 -> V_4 ) ;
continue;
}
for ( V_14 = 0 ; ; ) {
struct V_11 * V_102 =
& V_101 -> V_15 [ V_14 ] ;
if ( ! V_102 -> V_10 )
break;
V_14 ++ ;
if ( V_3 -> V_17 && ! ( V_3 -> V_17 & V_102 -> V_17 ) )
continue;
if ( strcmp ( V_102 -> V_10 , L_29 ) == 0 )
V_102 -> V_18 = V_20 |
V_19 ;
else if ( strcmp ( V_102 -> V_10 , L_30 ) == 0 )
V_102 -> V_18 = V_19 ;
else if ( strcmp ( V_102 -> V_10 , L_31 ) == 0 )
V_102 -> V_18 = V_20 ;
}
V_12 -> V_15 = V_101 -> V_15 ;
V_12 -> V_14 = V_14 ;
}
V_46 = F_34 ( V_74 , V_3 ) ;
if ( V_46 ) {
F_20 ( & V_74 -> V_47 , L_32 ) ;
return V_46 ;
}
V_3 -> V_34 = F_43 ( & V_3 -> V_76 , & V_74 -> V_47 , V_3 ) ;
if ( ! V_3 -> V_34 ) {
F_20 ( & V_74 -> V_47 , L_33 ) ;
return - V_36 ;
}
F_44 ( & V_74 -> V_47 , L_34 ) ;
for ( V_5 = 0 ; V_5 < V_79 -> V_103 ; V_5 ++ )
F_45 ( V_3 -> V_34 , & V_79 -> V_104 [ V_5 ] ) ;
return 0 ;
}
int F_46 ( struct V_73 * V_74 )
{
struct V_2 * V_3 = F_47 ( V_74 ) ;
F_48 ( V_3 -> V_34 ) ;
return 0 ;
}
