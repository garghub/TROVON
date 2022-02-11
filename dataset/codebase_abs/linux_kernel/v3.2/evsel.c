int F_1 ( T_1 V_1 )
{
T_1 V_2 = V_1 & V_3 ;
int V_4 = 0 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < 64 ; V_5 ++ ) {
if ( V_2 & ( 1ULL << V_5 ) )
V_4 ++ ;
}
V_4 *= sizeof( T_1 ) ;
return V_4 ;
}
static void F_2 ( struct V_6 * V_6 )
{
memset ( V_6 , 0 , sizeof( * V_6 ) ) ;
V_6 -> V_7 [ 0 ] = V_6 -> V_7 [ 1 ] = V_8 ;
V_6 -> V_9 = & V_6 -> V_7 [ 0 ] ;
V_6 -> V_10 = V_8 ;
V_6 -> V_11 = V_8 ;
F_3 ( & V_6 -> V_12 , NULL ) ;
}
void F_4 ( struct V_13 * V_14 ,
struct V_15 * V_16 , int V_17 )
{
V_14 -> V_17 = V_17 ;
V_14 -> V_16 = * V_16 ;
F_5 ( & V_14 -> V_18 ) ;
F_2 ( & V_14 -> V_6 ) ;
}
struct V_13 * F_6 ( struct V_15 * V_16 , int V_17 )
{
struct V_13 * V_14 = F_7 ( sizeof( * V_14 ) ) ;
if ( V_14 != NULL )
F_4 ( V_14 , V_16 , V_17 ) ;
return V_14 ;
}
int F_8 ( struct V_13 * V_14 , int V_19 , int V_20 )
{
int V_21 , V_22 ;
V_14 -> V_23 = F_9 ( V_19 , V_20 , sizeof( int ) ) ;
if ( V_14 -> V_23 ) {
for ( V_21 = 0 ; V_21 < V_19 ; V_21 ++ ) {
for ( V_22 = 0 ; V_22 < V_20 ; V_22 ++ ) {
F_10 ( V_14 , V_21 , V_22 ) = - 1 ;
}
}
}
return V_14 -> V_23 != NULL ? 0 : - V_24 ;
}
int F_11 ( struct V_13 * V_14 , int V_19 , int V_20 )
{
V_14 -> V_25 = F_9 ( V_19 , V_20 , sizeof( struct V_26 ) ) ;
if ( V_14 -> V_25 == NULL )
return - V_24 ;
V_14 -> V_27 = F_7 ( V_19 * V_20 * sizeof( T_1 ) ) ;
if ( V_14 -> V_27 == NULL ) {
F_12 ( V_14 -> V_25 ) ;
V_14 -> V_25 = NULL ;
return - V_24 ;
}
return 0 ;
}
int F_13 ( struct V_13 * V_14 , int V_19 )
{
V_14 -> V_28 = F_7 ( ( sizeof( * V_14 -> V_28 ) +
( V_19 * sizeof( struct V_29 ) ) ) ) ;
return V_14 -> V_28 != NULL ? 0 : - V_24 ;
}
void F_14 ( struct V_13 * V_14 )
{
F_12 ( V_14 -> V_23 ) ;
V_14 -> V_23 = NULL ;
}
void F_15 ( struct V_13 * V_14 )
{
F_12 ( V_14 -> V_25 ) ;
V_14 -> V_25 = NULL ;
free ( V_14 -> V_27 ) ;
V_14 -> V_27 = NULL ;
}
void F_16 ( struct V_13 * V_14 , int V_19 , int V_20 )
{
int V_21 , V_22 ;
for ( V_21 = 0 ; V_21 < V_19 ; V_21 ++ )
for ( V_22 = 0 ; V_22 < V_20 ; ++ V_22 ) {
F_17 ( F_10 ( V_14 , V_21 , V_22 ) ) ;
F_10 ( V_14 , V_21 , V_22 ) = - 1 ;
}
}
void F_18 ( struct V_13 * V_14 )
{
assert ( F_19 ( & V_14 -> V_18 ) ) ;
F_12 ( V_14 -> V_23 ) ;
F_12 ( V_14 -> V_25 ) ;
free ( V_14 -> V_27 ) ;
}
void F_20 ( struct V_13 * V_14 )
{
F_18 ( V_14 ) ;
F_21 ( V_14 -> V_30 ) ;
free ( V_14 -> V_31 ) ;
free ( V_14 ) ;
}
int F_22 ( struct V_13 * V_14 ,
int V_21 , int V_22 , bool V_32 )
{
struct V_29 V_33 ;
T_2 V_34 = V_32 ? 3 : 1 ;
if ( F_10 ( V_14 , V_21 , V_22 ) < 0 )
return - V_35 ;
if ( V_14 -> V_28 == NULL && F_13 ( V_14 , V_21 + 1 ) < 0 )
return - V_24 ;
if ( F_23 ( F_10 ( V_14 , V_21 , V_22 ) , & V_33 , V_34 * sizeof( T_1 ) ) < 0 )
return - V_36 ;
if ( V_32 ) {
if ( V_33 . V_37 == 0 )
V_33 . V_38 = 0 ;
else if ( V_33 . V_37 < V_33 . V_39 )
V_33 . V_38 = ( T_1 ) ( ( double ) V_33 . V_38 * V_33 . V_39 / V_33 . V_37 + 0.5 ) ;
} else
V_33 . V_39 = V_33 . V_37 = 0 ;
V_14 -> V_28 -> V_21 [ V_21 ] = V_33 ;
return 0 ;
}
int F_24 ( struct V_13 * V_14 ,
int V_19 , int V_20 , bool V_32 )
{
T_2 V_34 = V_32 ? 3 : 1 ;
int V_21 , V_22 ;
struct V_29 * V_40 = & V_14 -> V_28 -> V_40 , V_33 ;
V_40 -> V_38 = V_40 -> V_39 = V_40 -> V_37 = 0 ;
for ( V_21 = 0 ; V_21 < V_19 ; V_21 ++ ) {
for ( V_22 = 0 ; V_22 < V_20 ; V_22 ++ ) {
if ( F_10 ( V_14 , V_21 , V_22 ) < 0 )
continue;
if ( F_23 ( F_10 ( V_14 , V_21 , V_22 ) ,
& V_33 , V_34 * sizeof( T_1 ) ) < 0 )
return - V_36 ;
V_40 -> V_38 += V_33 . V_38 ;
if ( V_32 ) {
V_40 -> V_39 += V_33 . V_39 ;
V_40 -> V_37 += V_33 . V_37 ;
}
}
}
V_14 -> V_28 -> V_41 = 0 ;
if ( V_32 ) {
if ( V_40 -> V_37 == 0 ) {
V_14 -> V_28 -> V_41 = - 1 ;
V_40 -> V_38 = 0 ;
return 0 ;
}
if ( V_40 -> V_37 < V_40 -> V_39 ) {
V_14 -> V_28 -> V_41 = 1 ;
V_40 -> V_38 = ( T_1 ) ( ( double ) V_40 -> V_38 * V_40 -> V_39 / V_40 -> V_37 + 0.5 ) ;
}
} else
V_40 -> V_39 = V_40 -> V_37 = 0 ;
return 0 ;
}
static int F_25 ( struct V_13 * V_14 , struct V_42 * V_43 ,
struct V_44 * V_45 , bool V_46 ,
struct V_47 * V_48 )
{
int V_21 , V_22 ;
unsigned long V_49 = 0 ;
int V_50 = - 1 , V_51 ;
if ( V_14 -> V_23 == NULL &&
F_8 ( V_14 , V_43 -> V_52 , V_45 -> V_52 ) < 0 )
return - V_24 ;
if ( V_14 -> V_30 ) {
V_49 = V_53 ;
V_50 = V_14 -> V_30 -> V_23 ;
}
for ( V_21 = 0 ; V_21 < V_43 -> V_52 ; V_21 ++ ) {
int V_54 = V_48 ? F_26 ( V_48 , V_21 ) : - 1 ;
for ( V_22 = 0 ; V_22 < V_45 -> V_52 ; V_22 ++ ) {
if ( ! V_14 -> V_30 )
V_50 = V_45 -> V_55 [ V_22 ] ;
F_10 ( V_14 , V_21 , V_22 ) = F_27 ( & V_14 -> V_16 ,
V_50 ,
V_43 -> V_55 [ V_21 ] ,
V_54 , V_49 ) ;
if ( F_10 ( V_14 , V_21 , V_22 ) < 0 ) {
V_51 = - V_36 ;
goto V_56;
}
if ( V_46 && V_54 == - 1 )
V_54 = F_10 ( V_14 , V_21 , V_22 ) ;
}
}
return 0 ;
V_56:
do {
while ( -- V_22 >= 0 ) {
F_17 ( F_10 ( V_14 , V_21 , V_22 ) ) ;
F_10 ( V_14 , V_21 , V_22 ) = - 1 ;
}
V_22 = V_45 -> V_52 ;
} while ( -- V_21 >= 0 );
return V_51 ;
}
void F_28 ( struct V_13 * V_14 , int V_19 , int V_20 )
{
if ( V_14 -> V_23 == NULL )
return;
F_16 ( V_14 , V_19 , V_20 ) ;
F_14 ( V_14 ) ;
V_14 -> V_23 = NULL ;
}
int F_29 ( struct V_13 * V_14 , struct V_42 * V_43 ,
struct V_44 * V_45 , bool V_46 ,
struct V_47 * V_54 )
{
if ( V_43 == NULL ) {
V_43 = & V_57 . V_55 ;
}
if ( V_45 == NULL )
V_45 = & V_58 . V_55 ;
return F_25 ( V_14 , V_43 , V_45 , V_46 , V_54 ) ;
}
int F_30 ( struct V_13 * V_14 ,
struct V_42 * V_43 , bool V_46 ,
struct V_47 * V_54 )
{
return F_25 ( V_14 , V_43 , & V_58 . V_55 , V_46 ,
V_54 ) ;
}
int F_31 ( struct V_13 * V_14 ,
struct V_44 * V_45 , bool V_46 ,
struct V_47 * V_54 )
{
return F_25 ( V_14 , & V_57 . V_55 , V_45 , V_46 ,
V_54 ) ;
}
static int F_32 ( const union V_59 * V_60 , T_1 type ,
struct V_61 * V_62 )
{
const T_1 * V_63 = V_60 -> V_62 . V_63 ;
V_63 += ( ( V_60 -> V_64 . V_4 -
sizeof( V_60 -> V_64 ) ) / sizeof( T_1 ) ) - 1 ;
if ( type & V_65 ) {
T_3 * V_66 = ( T_3 * ) V_63 ;
V_62 -> V_21 = * V_66 ;
V_63 -- ;
}
if ( type & V_67 ) {
V_62 -> V_68 = * V_63 ;
V_63 -- ;
}
if ( type & V_69 ) {
V_62 -> V_27 = * V_63 ;
V_63 -- ;
}
if ( type & V_70 ) {
V_62 -> time = * V_63 ;
V_63 -- ;
}
if ( type & V_71 ) {
T_3 * V_66 = ( T_3 * ) V_63 ;
V_62 -> V_50 = V_66 [ 0 ] ;
V_62 -> V_72 = V_66 [ 1 ] ;
}
return 0 ;
}
static bool F_33 ( const union V_59 * V_60 ,
const void * V_73 , T_1 V_4 )
{
const void * V_74 = V_60 ;
if ( V_73 + V_4 > V_74 + V_60 -> V_64 . V_4 )
return true ;
return false ;
}
int F_34 ( const union V_59 * V_60 , T_1 type ,
int V_75 , bool V_76 ,
struct V_61 * V_77 , bool V_78 )
{
const T_1 * V_63 ;
union {
T_1 V_79 ;
T_3 V_80 [ 2 ] ;
} V_81 ;
V_77 -> V_21 = V_77 -> V_50 = V_77 -> V_72 = - 1 ;
V_77 -> V_68 = V_77 -> V_27 = V_77 -> time = - 1ULL ;
if ( V_60 -> V_64 . type != V_82 ) {
if ( ! V_76 )
return 0 ;
return F_32 ( V_60 , type , V_77 ) ;
}
V_63 = V_60 -> V_62 . V_63 ;
if ( V_75 + sizeof( V_60 -> V_64 ) > V_60 -> V_64 . V_4 )
return - V_83 ;
if ( type & V_84 ) {
V_77 -> V_85 = V_60 -> V_85 . V_85 ;
V_63 ++ ;
}
if ( type & V_71 ) {
V_81 . V_79 = * V_63 ;
if ( V_78 ) {
V_81 . V_79 = F_35 ( V_81 . V_79 ) ;
V_81 . V_80 [ 0 ] = F_36 ( V_81 . V_80 [ 0 ] ) ;
V_81 . V_80 [ 1 ] = F_36 ( V_81 . V_80 [ 1 ] ) ;
}
V_77 -> V_50 = V_81 . V_80 [ 0 ] ;
V_77 -> V_72 = V_81 . V_80 [ 1 ] ;
V_63 ++ ;
}
if ( type & V_70 ) {
V_77 -> time = * V_63 ;
V_63 ++ ;
}
V_77 -> V_86 = 0 ;
if ( type & V_87 ) {
V_77 -> V_86 = * V_63 ;
V_63 ++ ;
}
V_77 -> V_27 = - 1ULL ;
if ( type & V_69 ) {
V_77 -> V_27 = * V_63 ;
V_63 ++ ;
}
if ( type & V_67 ) {
V_77 -> V_68 = * V_63 ;
V_63 ++ ;
}
if ( type & V_65 ) {
V_81 . V_79 = * V_63 ;
if ( V_78 ) {
V_81 . V_79 = F_35 ( V_81 . V_79 ) ;
V_81 . V_80 [ 0 ] = F_36 ( V_81 . V_80 [ 0 ] ) ;
}
V_77 -> V_21 = V_81 . V_80 [ 0 ] ;
V_63 ++ ;
}
if ( type & V_88 ) {
V_77 -> V_89 = * V_63 ;
V_63 ++ ;
}
if ( type & V_90 ) {
fprintf ( V_91 , L_1 ) ;
return - 1 ;
}
if ( type & V_92 ) {
if ( F_33 ( V_60 , V_63 , sizeof( V_77 -> V_93 -> V_52 ) ) )
return - V_83 ;
V_77 -> V_93 = (struct V_94 * ) V_63 ;
if ( F_33 ( V_60 , V_63 , V_77 -> V_93 -> V_52 ) )
return - V_83 ;
V_63 += 1 + V_77 -> V_93 -> V_52 ;
}
if ( type & V_95 ) {
const T_1 * V_96 ;
V_81 . V_79 = * V_63 ;
if ( F_37 ( V_78 ,
L_2 ) ) {
V_81 . V_79 = F_35 ( V_81 . V_79 ) ;
V_81 . V_80 [ 0 ] = F_36 ( V_81 . V_80 [ 0 ] ) ;
V_81 . V_80 [ 1 ] = F_36 ( V_81 . V_80 [ 1 ] ) ;
}
if ( F_33 ( V_60 , V_63 , sizeof( T_3 ) ) )
return - V_83 ;
V_77 -> V_97 = V_81 . V_80 [ 0 ] ;
V_96 = ( void * ) V_63 + sizeof( T_3 ) ;
if ( F_33 ( V_60 , V_96 , V_77 -> V_97 ) )
return - V_83 ;
V_77 -> V_98 = ( void * ) V_96 ;
}
return 0 ;
}
