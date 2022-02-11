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
void F_2 ( struct V_6 * V_7 ,
struct V_8 * V_9 , int V_10 )
{
V_7 -> V_10 = V_10 ;
V_7 -> V_9 = * V_9 ;
F_3 ( & V_7 -> V_11 ) ;
}
struct V_6 * F_4 ( struct V_8 * V_9 , int V_10 )
{
struct V_6 * V_7 = F_5 ( sizeof( * V_7 ) ) ;
if ( V_7 != NULL )
F_2 ( V_7 , V_9 , V_10 ) ;
return V_7 ;
}
int F_6 ( struct V_6 * V_7 , int V_12 , int V_13 )
{
int V_14 , V_15 ;
V_7 -> V_16 = F_7 ( V_12 , V_13 , sizeof( int ) ) ;
if ( V_7 -> V_16 ) {
for ( V_14 = 0 ; V_14 < V_12 ; V_14 ++ ) {
for ( V_15 = 0 ; V_15 < V_13 ; V_15 ++ ) {
F_8 ( V_7 , V_14 , V_15 ) = - 1 ;
}
}
}
return V_7 -> V_16 != NULL ? 0 : - V_17 ;
}
int F_9 ( struct V_6 * V_7 , int V_12 , int V_13 )
{
V_7 -> V_18 = F_7 ( V_12 , V_13 , sizeof( struct V_19 ) ) ;
if ( V_7 -> V_18 == NULL )
return - V_17 ;
V_7 -> V_20 = F_5 ( V_12 * V_13 * sizeof( T_1 ) ) ;
if ( V_7 -> V_20 == NULL ) {
F_10 ( V_7 -> V_18 ) ;
V_7 -> V_18 = NULL ;
return - V_17 ;
}
return 0 ;
}
int F_11 ( struct V_6 * V_7 , int V_12 )
{
V_7 -> V_21 = F_5 ( ( sizeof( * V_7 -> V_21 ) +
( V_12 * sizeof( struct V_22 ) ) ) ) ;
return V_7 -> V_21 != NULL ? 0 : - V_17 ;
}
void F_12 ( struct V_6 * V_7 )
{
F_10 ( V_7 -> V_16 ) ;
V_7 -> V_16 = NULL ;
}
void F_13 ( struct V_6 * V_7 )
{
F_10 ( V_7 -> V_18 ) ;
V_7 -> V_18 = NULL ;
free ( V_7 -> V_20 ) ;
V_7 -> V_20 = NULL ;
}
void F_14 ( struct V_6 * V_7 , int V_12 , int V_13 )
{
int V_14 , V_15 ;
for ( V_14 = 0 ; V_14 < V_12 ; V_14 ++ )
for ( V_15 = 0 ; V_15 < V_13 ; ++ V_15 ) {
F_15 ( F_8 ( V_7 , V_14 , V_15 ) ) ;
F_8 ( V_7 , V_14 , V_15 ) = - 1 ;
}
}
void F_16 ( struct V_6 * V_7 )
{
assert ( F_17 ( & V_7 -> V_11 ) ) ;
F_10 ( V_7 -> V_16 ) ;
F_10 ( V_7 -> V_18 ) ;
free ( V_7 -> V_20 ) ;
}
void F_18 ( struct V_6 * V_7 )
{
F_16 ( V_7 ) ;
F_19 ( V_7 -> V_23 ) ;
free ( V_7 -> V_24 ) ;
free ( V_7 ) ;
}
int F_20 ( struct V_6 * V_7 ,
int V_14 , int V_15 , bool V_25 )
{
struct V_22 V_26 ;
T_2 V_27 = V_25 ? 3 : 1 ;
if ( F_8 ( V_7 , V_14 , V_15 ) < 0 )
return - V_28 ;
if ( V_7 -> V_21 == NULL && F_11 ( V_7 , V_14 + 1 ) < 0 )
return - V_17 ;
if ( F_21 ( F_8 ( V_7 , V_14 , V_15 ) , & V_26 , V_27 * sizeof( T_1 ) ) < 0 )
return - V_29 ;
if ( V_25 ) {
if ( V_26 . V_30 == 0 )
V_26 . V_31 = 0 ;
else if ( V_26 . V_30 < V_26 . V_32 )
V_26 . V_31 = ( T_1 ) ( ( double ) V_26 . V_31 * V_26 . V_32 / V_26 . V_30 + 0.5 ) ;
} else
V_26 . V_32 = V_26 . V_30 = 0 ;
V_7 -> V_21 -> V_14 [ V_14 ] = V_26 ;
return 0 ;
}
int F_22 ( struct V_6 * V_7 ,
int V_12 , int V_13 , bool V_25 )
{
T_2 V_27 = V_25 ? 3 : 1 ;
int V_14 , V_15 ;
struct V_22 * V_33 = & V_7 -> V_21 -> V_33 , V_26 ;
V_33 -> V_31 = V_33 -> V_32 = V_33 -> V_30 = 0 ;
for ( V_14 = 0 ; V_14 < V_12 ; V_14 ++ ) {
for ( V_15 = 0 ; V_15 < V_13 ; V_15 ++ ) {
if ( F_8 ( V_7 , V_14 , V_15 ) < 0 )
continue;
if ( F_21 ( F_8 ( V_7 , V_14 , V_15 ) ,
& V_26 , V_27 * sizeof( T_1 ) ) < 0 )
return - V_29 ;
V_33 -> V_31 += V_26 . V_31 ;
if ( V_25 ) {
V_33 -> V_32 += V_26 . V_32 ;
V_33 -> V_30 += V_26 . V_30 ;
}
}
}
V_7 -> V_21 -> V_34 = 0 ;
if ( V_25 ) {
if ( V_33 -> V_30 == 0 ) {
V_7 -> V_21 -> V_34 = - 1 ;
V_33 -> V_31 = 0 ;
return 0 ;
}
if ( V_33 -> V_30 < V_33 -> V_32 ) {
V_7 -> V_21 -> V_34 = 1 ;
V_33 -> V_31 = ( T_1 ) ( ( double ) V_33 -> V_31 * V_33 -> V_32 / V_33 -> V_30 + 0.5 ) ;
}
} else
V_33 -> V_32 = V_33 -> V_30 = 0 ;
return 0 ;
}
static int F_23 ( struct V_6 * V_7 , struct V_35 * V_36 ,
struct V_37 * V_38 , bool V_39 )
{
int V_14 , V_15 ;
unsigned long V_40 = 0 ;
int V_41 = - 1 ;
if ( V_7 -> V_16 == NULL &&
F_6 ( V_7 , V_36 -> V_42 , V_38 -> V_42 ) < 0 )
return - 1 ;
if ( V_7 -> V_23 ) {
V_40 = V_43 ;
V_41 = V_7 -> V_23 -> V_16 ;
}
for ( V_14 = 0 ; V_14 < V_36 -> V_42 ; V_14 ++ ) {
int V_44 = - 1 ;
for ( V_15 = 0 ; V_15 < V_38 -> V_42 ; V_15 ++ ) {
if ( ! V_7 -> V_23 )
V_41 = V_38 -> V_45 [ V_15 ] ;
F_8 ( V_7 , V_14 , V_15 ) = F_24 ( & V_7 -> V_9 ,
V_41 ,
V_36 -> V_45 [ V_14 ] ,
V_44 , V_40 ) ;
if ( F_8 ( V_7 , V_14 , V_15 ) < 0 )
goto V_46;
if ( V_39 && V_44 == - 1 )
V_44 = F_8 ( V_7 , V_14 , V_15 ) ;
}
}
return 0 ;
V_46:
do {
while ( -- V_15 >= 0 ) {
F_15 ( F_8 ( V_7 , V_14 , V_15 ) ) ;
F_8 ( V_7 , V_14 , V_15 ) = - 1 ;
}
V_15 = V_38 -> V_42 ;
} while ( -- V_14 >= 0 );
return - 1 ;
}
int F_25 ( struct V_6 * V_7 , struct V_35 * V_36 ,
struct V_37 * V_38 , bool V_39 )
{
if ( V_36 == NULL ) {
V_36 = & V_47 . V_45 ;
}
if ( V_38 == NULL )
V_38 = & V_48 . V_45 ;
return F_23 ( V_7 , V_36 , V_38 , V_39 ) ;
}
int F_26 ( struct V_6 * V_7 ,
struct V_35 * V_36 , bool V_39 )
{
return F_23 ( V_7 , V_36 , & V_48 . V_45 , V_39 ) ;
}
int F_27 ( struct V_6 * V_7 ,
struct V_37 * V_38 , bool V_39 )
{
return F_23 ( V_7 , & V_47 . V_45 , V_38 , V_39 ) ;
}
static int F_28 ( const union V_49 * V_50 , T_1 type ,
struct V_51 * V_52 )
{
const T_1 * V_53 = V_50 -> V_52 . V_53 ;
V_53 += ( ( V_50 -> V_54 . V_4 -
sizeof( V_50 -> V_54 ) ) / sizeof( T_1 ) ) - 1 ;
if ( type & V_55 ) {
T_3 * V_56 = ( T_3 * ) V_53 ;
V_52 -> V_14 = * V_56 ;
V_53 -- ;
}
if ( type & V_57 ) {
V_52 -> V_58 = * V_53 ;
V_53 -- ;
}
if ( type & V_59 ) {
V_52 -> V_20 = * V_53 ;
V_53 -- ;
}
if ( type & V_60 ) {
V_52 -> time = * V_53 ;
V_53 -- ;
}
if ( type & V_61 ) {
T_3 * V_56 = ( T_3 * ) V_53 ;
V_52 -> V_41 = V_56 [ 0 ] ;
V_52 -> V_62 = V_56 [ 1 ] ;
}
return 0 ;
}
static bool F_29 ( const union V_49 * V_50 ,
const void * V_63 , T_1 V_4 )
{
const void * V_64 = V_50 ;
if ( V_63 + V_4 > V_64 + V_50 -> V_54 . V_4 )
return true ;
return false ;
}
int F_30 ( const union V_49 * V_50 , T_1 type ,
int V_65 , bool V_66 ,
struct V_51 * V_67 , bool V_68 )
{
const T_1 * V_53 ;
union {
T_1 V_69 ;
T_3 V_70 [ 2 ] ;
} V_71 ;
V_67 -> V_14 = V_67 -> V_41 = V_67 -> V_62 = - 1 ;
V_67 -> V_58 = V_67 -> V_20 = V_67 -> time = - 1ULL ;
if ( V_50 -> V_54 . type != V_72 ) {
if ( ! V_66 )
return 0 ;
return F_28 ( V_50 , type , V_67 ) ;
}
V_53 = V_50 -> V_52 . V_53 ;
if ( V_65 + sizeof( V_50 -> V_54 ) > V_50 -> V_54 . V_4 )
return - V_73 ;
if ( type & V_74 ) {
V_67 -> V_75 = V_50 -> V_75 . V_75 ;
V_53 ++ ;
}
if ( type & V_61 ) {
V_71 . V_69 = * V_53 ;
if ( V_68 ) {
V_71 . V_69 = F_31 ( V_71 . V_69 ) ;
V_71 . V_70 [ 0 ] = F_32 ( V_71 . V_70 [ 0 ] ) ;
V_71 . V_70 [ 1 ] = F_32 ( V_71 . V_70 [ 1 ] ) ;
}
V_67 -> V_41 = V_71 . V_70 [ 0 ] ;
V_67 -> V_62 = V_71 . V_70 [ 1 ] ;
V_53 ++ ;
}
if ( type & V_60 ) {
V_67 -> time = * V_53 ;
V_53 ++ ;
}
V_67 -> V_76 = 0 ;
if ( type & V_77 ) {
V_67 -> V_76 = * V_53 ;
V_53 ++ ;
}
V_67 -> V_20 = - 1ULL ;
if ( type & V_59 ) {
V_67 -> V_20 = * V_53 ;
V_53 ++ ;
}
if ( type & V_57 ) {
V_67 -> V_58 = * V_53 ;
V_53 ++ ;
}
if ( type & V_55 ) {
V_71 . V_69 = * V_53 ;
if ( V_68 ) {
V_71 . V_69 = F_31 ( V_71 . V_69 ) ;
V_71 . V_70 [ 0 ] = F_32 ( V_71 . V_70 [ 0 ] ) ;
}
V_67 -> V_14 = V_71 . V_70 [ 0 ] ;
V_53 ++ ;
}
if ( type & V_78 ) {
V_67 -> V_79 = * V_53 ;
V_53 ++ ;
}
if ( type & V_80 ) {
fprintf ( V_81 , L_1 ) ;
return - 1 ;
}
if ( type & V_82 ) {
if ( F_29 ( V_50 , V_53 , sizeof( V_67 -> V_83 -> V_42 ) ) )
return - V_73 ;
V_67 -> V_83 = (struct V_84 * ) V_53 ;
if ( F_29 ( V_50 , V_53 , V_67 -> V_83 -> V_42 ) )
return - V_73 ;
V_53 += 1 + V_67 -> V_83 -> V_42 ;
}
if ( type & V_85 ) {
const T_1 * V_86 ;
V_71 . V_69 = * V_53 ;
if ( F_33 ( V_68 ,
L_2 ) ) {
V_71 . V_69 = F_31 ( V_71 . V_69 ) ;
V_71 . V_70 [ 0 ] = F_32 ( V_71 . V_70 [ 0 ] ) ;
V_71 . V_70 [ 1 ] = F_32 ( V_71 . V_70 [ 1 ] ) ;
}
if ( F_29 ( V_50 , V_53 , sizeof( T_3 ) ) )
return - V_73 ;
V_67 -> V_87 = V_71 . V_70 [ 0 ] ;
V_86 = ( void * ) V_53 + sizeof( T_3 ) ;
if ( F_29 ( V_50 , V_86 , V_67 -> V_87 ) )
return - V_73 ;
V_67 -> V_88 = ( void * ) V_86 ;
}
return 0 ;
}
