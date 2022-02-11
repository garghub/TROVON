static inline int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
static const T_1 V_4 = 0xcc9e2d51 ;
static const T_1 V_5 = 0x1b873593 ;
static const T_1 V_6 = 15 ;
static const T_1 V_7 = 13 ;
static const T_1 V_8 = 5 ;
static const T_1 V_9 = 0xe6546b64 ;
T_1 V_10 = 0 ;
#define F_2 ( T_2 ) { \
u32 v = input; \
v *= c1; \
v = (v << r1) | (v >> (32 - r1)); \
v *= c2; \
hash ^= v; \
hash = (hash << r2) | (hash >> (32 - r2)); \
hash = hash * m + n; \
}
F_2 ( V_2 -> V_11 ) ;
F_2 ( V_2 -> V_12 ) ;
F_2 ( V_2 -> V_13 ) ;
#undef F_2
V_10 ^= V_10 >> 16 ;
V_10 *= 0x85ebca6b ;
V_10 ^= V_10 >> 13 ;
V_10 *= 0xc2b2ae35 ;
V_10 ^= V_10 >> 16 ;
return V_10 & V_3 ;
}
static struct V_14 *
F_3 ( struct V_15 * V_16 , int V_17 ,
struct V_14 * V_18 , struct V_14 * V_19 ,
struct V_1 * V_20 , struct V_21 * V_22 )
{
struct V_14 * V_23 ;
V_23 = F_4 ( V_24 , V_25 ) ;
if ( V_23 == NULL )
return NULL ;
V_23 -> V_20 = * V_20 ;
V_23 -> V_22 = * V_22 ;
if ( V_18 ) {
V_23 -> V_26 = V_18 -> V_26 ;
V_18 -> V_26 = V_23 ;
} else {
V_23 -> V_26 = F_5 ( V_16 -> V_27 , V_17 ) ;
if ( F_6 ( V_16 -> V_27 , V_17 , V_23 ,
V_25 | V_28 ) ) {
F_7 ( V_24 , V_23 ) ;
return NULL ;
}
}
V_16 -> V_29 ++ ;
return V_23 ;
}
static int F_8 ( struct V_15 * V_16 , struct V_1 * V_20 , struct V_21 * V_22 )
{
int V_17 ;
struct V_14 * V_18 , * V_19 , * V_23 ;
T_3 V_30 = V_20 -> V_30 & ~ ( V_31 | V_32 ) ;
if ( ! V_16 || ! V_16 -> V_27 )
return - V_33 ;
V_17 = F_1 ( V_20 , V_16 -> V_3 ) ;
for ( V_18 = NULL , V_19 = F_5 ( V_16 -> V_27 , V_17 ) ;
V_19 ;
V_18 = V_19 , V_19 = V_19 -> V_26 ) {
if ( V_20 -> V_13 == V_19 -> V_20 . V_13 &&
V_20 -> V_12 == V_19 -> V_20 . V_12 &&
V_20 -> V_11 == V_19 -> V_20 . V_11 &&
( V_30 & V_19 -> V_20 . V_30 ) )
return - V_34 ;
if ( V_20 -> V_13 < V_19 -> V_20 . V_13 )
break;
if ( V_20 -> V_13 == V_19 -> V_20 . V_13 &&
V_20 -> V_12 < V_19 -> V_20 . V_12 )
break;
if ( V_20 -> V_13 == V_19 -> V_20 . V_13 &&
V_20 -> V_12 == V_19 -> V_20 . V_12 &&
V_20 -> V_11 < V_19 -> V_20 . V_11 )
break;
}
V_23 = F_3 ( V_16 , V_17 , V_18 , V_19 , V_20 , V_22 ) ;
if ( ! V_23 )
return - V_35 ;
return 0 ;
}
struct V_14 *
F_9 ( struct V_15 * V_16 , struct V_1 * V_20 , struct V_21 * V_22 )
{
int V_17 ;
struct V_14 * V_18 , * V_19 ;
T_3 V_30 = V_20 -> V_30 & ~ ( V_31 | V_32 ) ;
if ( ! V_16 || ! V_16 -> V_27 )
return NULL ;
V_17 = F_1 ( V_20 , V_16 -> V_3 ) ;
for ( V_18 = NULL , V_19 = F_5 ( V_16 -> V_27 , V_17 ) ;
V_19 ;
V_18 = V_19 , V_19 = V_19 -> V_26 ) {
if ( V_20 -> V_13 == V_19 -> V_20 . V_13 &&
V_20 -> V_12 == V_19 -> V_20 . V_12 &&
V_20 -> V_11 == V_19 -> V_20 . V_11 &&
( V_30 & V_19 -> V_20 . V_30 ) )
break;
if ( V_20 -> V_13 < V_19 -> V_20 . V_13 )
break;
if ( V_20 -> V_13 == V_19 -> V_20 . V_13 &&
V_20 -> V_12 < V_19 -> V_20 . V_12 )
break;
if ( V_20 -> V_13 == V_19 -> V_20 . V_13 &&
V_20 -> V_12 == V_19 -> V_20 . V_12 &&
V_20 -> V_11 < V_19 -> V_20 . V_11 )
break;
}
return F_3 ( V_16 , V_17 , V_18 , V_19 , V_20 , V_22 ) ;
}
struct V_21 * F_10 ( struct V_15 * V_16 , struct V_1 * V_20 )
{
int V_17 ;
struct V_14 * V_19 ;
T_3 V_30 = V_20 -> V_30 & ~ ( V_31 | V_32 ) ;
if ( ! V_16 || ! V_16 -> V_27 )
return NULL ;
V_17 = F_1 ( V_20 , V_16 -> V_3 ) ;
for ( V_19 = F_5 ( V_16 -> V_27 , V_17 ) ; V_19 ;
V_19 = V_19 -> V_26 ) {
if ( V_20 -> V_13 == V_19 -> V_20 . V_13 &&
V_20 -> V_12 == V_19 -> V_20 . V_12 &&
V_20 -> V_11 == V_19 -> V_20 . V_11 &&
( V_30 & V_19 -> V_20 . V_30 ) )
return & V_19 -> V_22 ;
if ( V_20 -> V_13 < V_19 -> V_20 . V_13 )
break;
if ( V_20 -> V_13 == V_19 -> V_20 . V_13 &&
V_20 -> V_12 < V_19 -> V_20 . V_12 )
break;
if ( V_20 -> V_13 == V_19 -> V_20 . V_13 &&
V_20 -> V_12 == V_19 -> V_20 . V_12 &&
V_20 -> V_11 < V_19 -> V_20 . V_11 )
break;
}
return NULL ;
}
struct V_14 *
F_11 ( struct V_15 * V_16 , struct V_1 * V_20 )
{
int V_17 ;
struct V_14 * V_19 ;
T_3 V_30 = V_20 -> V_30 & ~ ( V_31 | V_32 ) ;
if ( ! V_16 || ! V_16 -> V_27 )
return NULL ;
V_17 = F_1 ( V_20 , V_16 -> V_3 ) ;
for ( V_19 = F_5 ( V_16 -> V_27 , V_17 ) ; V_19 ;
V_19 = V_19 -> V_26 ) {
if ( V_20 -> V_13 == V_19 -> V_20 . V_13 &&
V_20 -> V_12 == V_19 -> V_20 . V_12 &&
V_20 -> V_11 == V_19 -> V_20 . V_11 &&
( V_30 & V_19 -> V_20 . V_30 ) )
return V_19 ;
if ( V_20 -> V_13 < V_19 -> V_20 . V_13 )
break;
if ( V_20 -> V_13 == V_19 -> V_20 . V_13 &&
V_20 -> V_12 < V_19 -> V_20 . V_12 )
break;
if ( V_20 -> V_13 == V_19 -> V_20 . V_13 &&
V_20 -> V_12 == V_19 -> V_20 . V_12 &&
V_20 -> V_11 < V_19 -> V_20 . V_11 )
break;
}
return NULL ;
}
struct V_14 *
F_12 ( struct V_14 * V_36 , int V_30 )
{
struct V_14 * V_19 ;
if ( ! V_36 )
return NULL ;
V_30 &= ~ ( V_31 | V_32 ) ;
for ( V_19 = V_36 -> V_26 ; V_19 ; V_19 = V_19 -> V_26 ) {
if ( V_36 -> V_20 . V_13 == V_19 -> V_20 . V_13 &&
V_36 -> V_20 . V_12 == V_19 -> V_20 . V_12 &&
V_36 -> V_20 . V_11 == V_19 -> V_20 . V_11 &&
( V_30 & V_19 -> V_20 . V_30 ) )
return V_19 ;
if ( V_36 -> V_20 . V_13 < V_19 -> V_20 . V_13 )
break;
if ( V_36 -> V_20 . V_13 == V_19 -> V_20 . V_13 &&
V_36 -> V_20 . V_12 < V_19 -> V_20 . V_12 )
break;
if ( V_36 -> V_20 . V_13 == V_19 -> V_20 . V_13 &&
V_36 -> V_20 . V_12 == V_19 -> V_20 . V_12 &&
V_36 -> V_20 . V_11 < V_19 -> V_20 . V_11 )
break;
}
return NULL ;
}
void F_13 ( struct V_15 * V_16 )
{
int V_37 ;
struct V_14 * V_19 , * V_38 ;
if ( ! V_16 || ! V_16 -> V_27 )
return;
for ( V_37 = 0 ; V_37 < V_16 -> V_39 ; V_37 ++ ) {
V_19 = F_5 ( V_16 -> V_27 , V_37 ) ;
while ( V_19 ) {
V_38 = V_19 ;
V_19 = V_19 -> V_26 ;
F_7 ( V_24 , V_38 ) ;
}
}
F_14 ( V_16 -> V_27 ) ;
V_16 -> V_27 = NULL ;
V_16 -> V_39 = 0 ;
V_16 -> V_3 = 0 ;
}
int F_15 ( struct V_15 * V_16 )
{
V_16 -> V_27 = NULL ;
V_16 -> V_29 = 0 ;
return 0 ;
}
int F_16 ( struct V_15 * V_16 , T_1 V_40 )
{
T_1 V_3 = 0 ;
T_1 V_41 = 0 ;
T_1 V_42 = V_40 ;
T_1 V_39 = 0 ;
if ( V_40 == 0 )
goto V_43;
while ( V_42 ) {
V_42 = V_42 >> 1 ;
V_41 ++ ;
}
if ( V_41 > 2 )
V_41 = V_41 - 2 ;
V_39 = 1 << V_41 ;
if ( V_39 > V_44 )
V_39 = V_44 ;
V_3 = V_39 - 1 ;
V_16 -> V_27 = F_17 ( sizeof( struct V_14 * ) , V_39 ,
V_25 | V_28 ) ;
if ( ! V_16 -> V_27 )
return - V_35 ;
V_43:
V_16 -> V_29 = 0 ;
V_16 -> V_39 = V_39 ;
V_16 -> V_3 = V_3 ;
F_18 ( V_45 L_1 ,
V_16 -> V_39 , V_40 ) ;
return 0 ;
}
void F_19 ( struct V_15 * V_16 , char * V_46 )
{
int V_37 , V_47 , V_48 , V_49 ;
unsigned long long V_50 ;
struct V_14 * V_19 ;
V_48 = 0 ;
V_49 = 0 ;
V_50 = 0 ;
for ( V_37 = 0 ; V_37 < V_16 -> V_39 ; V_37 ++ ) {
V_19 = F_5 ( V_16 -> V_27 , V_37 ) ;
if ( V_19 ) {
V_48 ++ ;
V_47 = 0 ;
while ( V_19 ) {
V_47 ++ ;
V_19 = V_19 -> V_26 ;
}
if ( V_47 > V_49 )
V_49 = V_47 ;
V_50 += V_47 * V_47 ;
}
}
F_18 ( V_45 L_2
L_3 ,
V_46 , V_16 -> V_29 , V_48 , V_16 -> V_39 , V_49 ,
V_50 ) ;
}
int F_20 ( struct V_15 * V_51 , void * V_52 , struct V_53 * V_54 ,
int (* F_21)( struct V_15 * V_51 , struct V_1 * V_55 ,
struct V_21 * V_56 , void * V_57 ) ,
void * V_57 )
{
T_4 V_58 [ 4 ] ;
T_3 V_59 ;
T_5 V_60 [ 7 ] ;
T_1 V_61 , V_62 , V_63 , V_64 = V_54 -> V_65 ;
struct V_1 V_20 ;
struct V_21 V_22 ;
int V_37 , V_66 ;
unsigned V_67 ;
memset ( & V_20 , 0 , sizeof( struct V_1 ) ) ;
memset ( & V_22 , 0 , sizeof( struct V_21 ) ) ;
if ( V_64 < V_68 ) {
V_66 = F_22 ( V_60 , V_52 , sizeof( T_1 ) ) ;
if ( V_66 ) {
F_18 ( V_69 L_4 ) ;
return V_66 ;
}
V_62 = F_23 ( V_60 [ 0 ] ) ;
if ( V_62 > F_24 ( V_60 ) ) {
F_18 ( V_69 L_5 ) ;
return - V_33 ;
}
V_66 = F_22 ( V_60 , V_52 , sizeof( T_1 ) * V_62 ) ;
if ( V_66 ) {
F_18 ( V_69 L_4 ) ;
return V_66 ;
}
V_61 = 0 ;
V_63 = F_23 ( V_60 [ V_61 ++ ] ) ;
V_20 . V_13 = ( T_3 ) V_63 ;
if ( V_20 . V_13 != V_63 ) {
F_18 ( V_69 L_6 ) ;
return - V_33 ;
}
V_63 = F_23 ( V_60 [ V_61 ++ ] ) ;
V_20 . V_12 = ( T_3 ) V_63 ;
if ( V_20 . V_12 != V_63 ) {
F_18 ( V_69 L_7 ) ;
return - V_33 ;
}
V_63 = F_23 ( V_60 [ V_61 ++ ] ) ;
V_20 . V_11 = ( T_3 ) V_63 ;
if ( V_20 . V_11 != V_63 ) {
F_18 ( V_69 L_8 ) ;
return - V_33 ;
}
V_63 = F_23 ( V_60 [ V_61 ++ ] ) ;
V_59 = ( V_63 & V_32 ) ? V_31 : 0 ;
if ( ! ( V_63 & ( V_70 | V_71 ) ) ) {
F_18 ( V_69 L_9 ) ;
return - V_33 ;
}
if ( ( V_63 & V_70 ) &&
( V_63 & V_71 ) ) {
F_18 ( V_69 L_10 ) ;
return - V_33 ;
}
for ( V_37 = 0 ; V_37 < F_24 ( V_72 ) ; V_37 ++ ) {
if ( V_63 & V_72 [ V_37 ] ) {
V_20 . V_30 = V_72 [ V_37 ] | V_59 ;
V_22 . V_73 = F_23 ( V_60 [ V_61 ++ ] ) ;
V_66 = F_21 ( V_51 , & V_20 , & V_22 , V_57 ) ;
if ( V_66 )
return V_66 ;
}
}
if ( V_61 != V_62 ) {
F_18 ( V_69 L_11 , V_62 , V_61 ) ;
return - V_33 ;
}
return 0 ;
}
V_66 = F_22 ( V_58 , V_52 , sizeof( T_3 ) * 4 ) ;
if ( V_66 ) {
F_18 ( V_69 L_4 ) ;
return V_66 ;
}
V_61 = 0 ;
V_20 . V_13 = F_25 ( V_58 [ V_61 ++ ] ) ;
V_20 . V_12 = F_25 ( V_58 [ V_61 ++ ] ) ;
V_20 . V_11 = F_25 ( V_58 [ V_61 ++ ] ) ;
V_20 . V_30 = F_25 ( V_58 [ V_61 ++ ] ) ;
if ( ! F_26 ( V_54 , V_20 . V_13 ) ||
! F_26 ( V_54 , V_20 . V_12 ) ||
! F_27 ( V_54 , V_20 . V_11 ) ) {
F_18 ( V_69 L_12 ) ;
return - V_33 ;
}
V_67 = 0 ;
for ( V_37 = 0 ; V_37 < F_24 ( V_72 ) ; V_37 ++ ) {
if ( V_20 . V_30 & V_72 [ V_37 ] )
V_67 ++ ;
}
if ( ! V_67 || V_67 > 1 ) {
F_18 ( V_69 L_13 ) ;
return - V_33 ;
}
V_66 = F_22 ( V_60 , V_52 , sizeof( T_1 ) ) ;
if ( V_66 ) {
F_18 ( V_69 L_4 ) ;
return V_66 ;
}
V_22 . V_73 = F_23 ( * V_60 ) ;
if ( ( V_20 . V_30 & V_71 ) &&
! F_26 ( V_54 , V_22 . V_73 ) ) {
F_18 ( V_69 L_14 ) ;
return - V_33 ;
}
return F_21 ( V_51 , & V_20 , & V_22 , V_57 ) ;
}
static int F_28 ( struct V_15 * V_51 , struct V_1 * V_55 ,
struct V_21 * V_56 , void * V_57 )
{
return F_8 ( V_51 , V_55 , V_56 ) ;
}
int F_29 ( struct V_15 * V_51 , void * V_52 , struct V_53 * V_54 )
{
int V_66 ;
T_5 V_74 [ 1 ] ;
T_1 V_29 , V_37 ;
V_66 = F_22 ( V_74 , V_52 , sizeof( T_1 ) ) ;
if ( V_66 < 0 ) {
F_18 ( V_69 L_15 ) ;
goto V_75;
}
V_29 = F_23 ( V_74 [ 0 ] ) ;
if ( ! V_29 ) {
F_18 ( V_69 L_16 ) ;
V_66 = - V_33 ;
goto V_75;
}
V_66 = F_16 ( V_51 , V_29 ) ;
if ( V_66 )
goto V_75;
for ( V_37 = 0 ; V_37 < V_29 ; V_37 ++ ) {
V_66 = F_20 ( V_51 , V_52 , V_54 , F_28 , NULL ) ;
if ( V_66 ) {
if ( V_66 == - V_35 )
F_18 ( V_69 L_17 ) ;
else if ( V_66 == - V_34 )
F_18 ( V_69 L_18 ) ;
goto V_75;
}
}
V_66 = 0 ;
V_76:
return V_66 ;
V_75:
F_13 ( V_51 ) ;
goto V_76;
}
int F_30 ( struct V_53 * V_57 , struct V_14 * V_19 , void * V_52 )
{
T_4 V_58 [ 4 ] ;
T_5 V_60 [ 1 ] ;
int V_66 ;
V_58 [ 0 ] = F_31 ( V_19 -> V_20 . V_13 ) ;
V_58 [ 1 ] = F_31 ( V_19 -> V_20 . V_12 ) ;
V_58 [ 2 ] = F_31 ( V_19 -> V_20 . V_11 ) ;
V_58 [ 3 ] = F_31 ( V_19 -> V_20 . V_30 ) ;
V_66 = F_32 ( V_58 , sizeof( T_3 ) , 4 , V_52 ) ;
if ( V_66 )
return V_66 ;
V_60 [ 0 ] = F_33 ( V_19 -> V_22 . V_73 ) ;
V_66 = F_32 ( V_60 , sizeof( T_1 ) , 1 , V_52 ) ;
if ( V_66 )
return V_66 ;
return 0 ;
}
int F_34 ( struct V_53 * V_57 , struct V_15 * V_51 , void * V_52 )
{
unsigned int V_37 ;
int V_66 = 0 ;
struct V_14 * V_19 ;
T_5 V_74 [ 1 ] ;
V_74 [ 0 ] = F_33 ( V_51 -> V_29 ) ;
V_66 = F_32 ( V_74 , sizeof( T_1 ) , 1 , V_52 ) ;
if ( V_66 )
return V_66 ;
for ( V_37 = 0 ; V_37 < V_51 -> V_39 ; V_37 ++ ) {
for ( V_19 = F_5 ( V_51 -> V_27 , V_37 ) ; V_19 ;
V_19 = V_19 -> V_26 ) {
V_66 = F_30 ( V_57 , V_19 , V_52 ) ;
if ( V_66 )
return V_66 ;
}
}
return V_66 ;
}
void F_35 ( void )
{
V_24 = F_36 ( L_19 ,
sizeof( struct V_14 ) ,
0 , V_77 , NULL ) ;
}
void F_37 ( void )
{
F_38 ( V_24 ) ;
}
