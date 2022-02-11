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
struct V_24 * V_25 ;
V_23 = F_4 ( V_26 , V_27 ) ;
if ( V_23 == NULL )
return NULL ;
V_23 -> V_20 = * V_20 ;
if ( V_20 -> V_28 & V_29 ) {
V_25 = F_4 ( V_30 , V_27 ) ;
if ( V_25 == NULL ) {
F_5 ( V_26 , V_23 ) ;
return NULL ;
}
* V_25 = * ( V_22 -> V_31 . V_25 ) ;
V_23 -> V_22 . V_31 . V_25 = V_25 ;
} else {
V_23 -> V_22 . V_31 . V_32 = V_22 -> V_31 . V_32 ;
}
if ( V_18 ) {
V_23 -> V_33 = V_18 -> V_33 ;
V_18 -> V_33 = V_23 ;
} else {
V_23 -> V_33 = F_6 ( V_16 -> V_34 , V_17 ) ;
if ( F_7 ( V_16 -> V_34 , V_17 , V_23 ,
V_27 | V_35 ) ) {
F_5 ( V_26 , V_23 ) ;
return NULL ;
}
}
V_16 -> V_36 ++ ;
return V_23 ;
}
static int F_8 ( struct V_15 * V_16 , struct V_1 * V_20 , struct V_21 * V_22 )
{
int V_17 ;
struct V_14 * V_18 , * V_19 , * V_23 ;
T_3 V_28 = V_20 -> V_28 & ~ ( V_37 | V_38 ) ;
if ( ! V_16 || ! V_16 -> V_34 )
return - V_39 ;
V_17 = F_1 ( V_20 , V_16 -> V_3 ) ;
for ( V_18 = NULL , V_19 = F_6 ( V_16 -> V_34 , V_17 ) ;
V_19 ;
V_18 = V_19 , V_19 = V_19 -> V_33 ) {
if ( V_20 -> V_13 == V_19 -> V_20 . V_13 &&
V_20 -> V_12 == V_19 -> V_20 . V_12 &&
V_20 -> V_11 == V_19 -> V_20 . V_11 &&
( V_28 & V_19 -> V_20 . V_28 ) ) {
if ( V_28 & V_29 )
break;
return - V_40 ;
}
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
return - V_41 ;
return 0 ;
}
struct V_14 *
F_9 ( struct V_15 * V_16 , struct V_1 * V_20 , struct V_21 * V_22 )
{
int V_17 ;
struct V_14 * V_18 , * V_19 ;
T_3 V_28 = V_20 -> V_28 & ~ ( V_37 | V_38 ) ;
if ( ! V_16 || ! V_16 -> V_34 )
return NULL ;
V_17 = F_1 ( V_20 , V_16 -> V_3 ) ;
for ( V_18 = NULL , V_19 = F_6 ( V_16 -> V_34 , V_17 ) ;
V_19 ;
V_18 = V_19 , V_19 = V_19 -> V_33 ) {
if ( V_20 -> V_13 == V_19 -> V_20 . V_13 &&
V_20 -> V_12 == V_19 -> V_20 . V_12 &&
V_20 -> V_11 == V_19 -> V_20 . V_11 &&
( V_28 & V_19 -> V_20 . V_28 ) )
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
T_3 V_28 = V_20 -> V_28 & ~ ( V_37 | V_38 ) ;
if ( ! V_16 || ! V_16 -> V_34 )
return NULL ;
V_17 = F_1 ( V_20 , V_16 -> V_3 ) ;
for ( V_19 = F_6 ( V_16 -> V_34 , V_17 ) ; V_19 ;
V_19 = V_19 -> V_33 ) {
if ( V_20 -> V_13 == V_19 -> V_20 . V_13 &&
V_20 -> V_12 == V_19 -> V_20 . V_12 &&
V_20 -> V_11 == V_19 -> V_20 . V_11 &&
( V_28 & V_19 -> V_20 . V_28 ) )
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
T_3 V_28 = V_20 -> V_28 & ~ ( V_37 | V_38 ) ;
if ( ! V_16 || ! V_16 -> V_34 )
return NULL ;
V_17 = F_1 ( V_20 , V_16 -> V_3 ) ;
for ( V_19 = F_6 ( V_16 -> V_34 , V_17 ) ; V_19 ;
V_19 = V_19 -> V_33 ) {
if ( V_20 -> V_13 == V_19 -> V_20 . V_13 &&
V_20 -> V_12 == V_19 -> V_20 . V_12 &&
V_20 -> V_11 == V_19 -> V_20 . V_11 &&
( V_28 & V_19 -> V_20 . V_28 ) )
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
F_12 ( struct V_14 * V_42 , int V_28 )
{
struct V_14 * V_19 ;
if ( ! V_42 )
return NULL ;
V_28 &= ~ ( V_37 | V_38 ) ;
for ( V_19 = V_42 -> V_33 ; V_19 ; V_19 = V_19 -> V_33 ) {
if ( V_42 -> V_20 . V_13 == V_19 -> V_20 . V_13 &&
V_42 -> V_20 . V_12 == V_19 -> V_20 . V_12 &&
V_42 -> V_20 . V_11 == V_19 -> V_20 . V_11 &&
( V_28 & V_19 -> V_20 . V_28 ) )
return V_19 ;
if ( V_42 -> V_20 . V_13 < V_19 -> V_20 . V_13 )
break;
if ( V_42 -> V_20 . V_13 == V_19 -> V_20 . V_13 &&
V_42 -> V_20 . V_12 < V_19 -> V_20 . V_12 )
break;
if ( V_42 -> V_20 . V_13 == V_19 -> V_20 . V_13 &&
V_42 -> V_20 . V_12 == V_19 -> V_20 . V_12 &&
V_42 -> V_20 . V_11 < V_19 -> V_20 . V_11 )
break;
}
return NULL ;
}
void F_13 ( struct V_15 * V_16 )
{
int V_43 ;
struct V_14 * V_19 , * V_44 ;
if ( ! V_16 || ! V_16 -> V_34 )
return;
for ( V_43 = 0 ; V_43 < V_16 -> V_45 ; V_43 ++ ) {
V_19 = F_6 ( V_16 -> V_34 , V_43 ) ;
while ( V_19 ) {
V_44 = V_19 ;
V_19 = V_19 -> V_33 ;
if ( V_44 -> V_20 . V_28 & V_29 )
F_5 ( V_30 ,
V_44 -> V_22 . V_31 . V_25 ) ;
F_5 ( V_26 , V_44 ) ;
}
}
F_14 ( V_16 -> V_34 ) ;
V_16 -> V_34 = NULL ;
V_16 -> V_45 = 0 ;
V_16 -> V_3 = 0 ;
}
int F_15 ( struct V_15 * V_16 )
{
V_16 -> V_34 = NULL ;
V_16 -> V_36 = 0 ;
return 0 ;
}
int F_16 ( struct V_15 * V_16 , T_1 V_46 )
{
T_1 V_3 = 0 ;
T_1 V_47 = 0 ;
T_1 V_48 = V_46 ;
T_1 V_45 = 0 ;
if ( V_46 == 0 )
goto V_49;
while ( V_48 ) {
V_48 = V_48 >> 1 ;
V_47 ++ ;
}
if ( V_47 > 2 )
V_47 = V_47 - 2 ;
V_45 = 1 << V_47 ;
if ( V_45 > V_50 )
V_45 = V_50 ;
V_3 = V_45 - 1 ;
V_16 -> V_34 = F_17 ( sizeof( struct V_14 * ) , V_45 ,
V_27 | V_35 ) ;
if ( ! V_16 -> V_34 )
return - V_41 ;
V_49:
V_16 -> V_36 = 0 ;
V_16 -> V_45 = V_45 ;
V_16 -> V_3 = V_3 ;
F_18 ( V_51 L_1 ,
V_16 -> V_45 , V_46 ) ;
return 0 ;
}
void F_19 ( struct V_15 * V_16 , char * V_52 )
{
int V_43 , V_53 , V_54 , V_55 ;
unsigned long long V_56 ;
struct V_14 * V_19 ;
V_54 = 0 ;
V_55 = 0 ;
V_56 = 0 ;
for ( V_43 = 0 ; V_43 < V_16 -> V_45 ; V_43 ++ ) {
V_19 = F_6 ( V_16 -> V_34 , V_43 ) ;
if ( V_19 ) {
V_54 ++ ;
V_53 = 0 ;
while ( V_19 ) {
V_53 ++ ;
V_19 = V_19 -> V_33 ;
}
if ( V_53 > V_55 )
V_55 = V_53 ;
V_56 += V_53 * V_53 ;
}
}
F_18 ( V_51 L_2
L_3 ,
V_52 , V_16 -> V_36 , V_54 , V_16 -> V_45 , V_55 ,
V_56 ) ;
}
int F_20 ( struct V_15 * V_57 , void * V_58 , struct V_59 * V_60 ,
int (* F_21)( struct V_15 * V_57 , struct V_1 * V_61 ,
struct V_21 * V_62 , void * V_63 ) ,
void * V_63 )
{
T_4 V_64 [ 4 ] ;
T_3 V_65 ;
T_1 V_66 , V_67 , V_68 , V_69 = V_60 -> V_70 ;
struct V_1 V_20 ;
struct V_21 V_22 ;
struct V_24 V_25 ;
T_5 V_71 [ F_22 ( V_25 . V_72 . V_63 ) ] ;
int V_43 , V_73 ;
unsigned V_74 ;
memset ( & V_20 , 0 , sizeof( struct V_1 ) ) ;
memset ( & V_22 , 0 , sizeof( struct V_21 ) ) ;
if ( V_69 < V_75 ) {
V_73 = F_23 ( V_71 , V_58 , sizeof( T_1 ) ) ;
if ( V_73 ) {
F_18 ( V_76 L_4 ) ;
return V_73 ;
}
V_67 = F_24 ( V_71 [ 0 ] ) ;
if ( V_67 > F_22 ( V_71 ) ) {
F_18 ( V_76 L_5 ) ;
return - V_39 ;
}
V_73 = F_23 ( V_71 , V_58 , sizeof( T_1 ) * V_67 ) ;
if ( V_73 ) {
F_18 ( V_76 L_4 ) ;
return V_73 ;
}
V_66 = 0 ;
V_68 = F_24 ( V_71 [ V_66 ++ ] ) ;
V_20 . V_13 = ( T_3 ) V_68 ;
if ( V_20 . V_13 != V_68 ) {
F_18 ( V_76 L_6 ) ;
return - V_39 ;
}
V_68 = F_24 ( V_71 [ V_66 ++ ] ) ;
V_20 . V_12 = ( T_3 ) V_68 ;
if ( V_20 . V_12 != V_68 ) {
F_18 ( V_76 L_7 ) ;
return - V_39 ;
}
V_68 = F_24 ( V_71 [ V_66 ++ ] ) ;
V_20 . V_11 = ( T_3 ) V_68 ;
if ( V_20 . V_11 != V_68 ) {
F_18 ( V_76 L_8 ) ;
return - V_39 ;
}
V_68 = F_24 ( V_71 [ V_66 ++ ] ) ;
V_65 = ( V_68 & V_38 ) ? V_37 : 0 ;
if ( ! ( V_68 & ( V_77 | V_78 ) ) ) {
F_18 ( V_76 L_9 ) ;
return - V_39 ;
}
if ( ( V_68 & V_77 ) &&
( V_68 & V_78 ) ) {
F_18 ( V_76 L_10 ) ;
return - V_39 ;
}
if ( V_68 & V_29 ) {
F_18 ( V_76 L_11 ) ;
return - V_39 ;
}
for ( V_43 = 0 ; V_43 < F_22 ( V_79 ) ; V_43 ++ ) {
if ( V_68 & V_79 [ V_43 ] ) {
V_20 . V_28 = V_79 [ V_43 ] | V_65 ;
V_22 . V_31 . V_32 = F_24 ( V_71 [ V_66 ++ ] ) ;
V_73 = F_21 ( V_57 , & V_20 , & V_22 , V_63 ) ;
if ( V_73 )
return V_73 ;
}
}
if ( V_66 != V_67 ) {
F_18 ( V_76 L_12 , V_67 , V_66 ) ;
return - V_39 ;
}
return 0 ;
}
V_73 = F_23 ( V_64 , V_58 , sizeof( T_3 ) * 4 ) ;
if ( V_73 ) {
F_18 ( V_76 L_4 ) ;
return V_73 ;
}
V_66 = 0 ;
V_20 . V_13 = F_25 ( V_64 [ V_66 ++ ] ) ;
V_20 . V_12 = F_25 ( V_64 [ V_66 ++ ] ) ;
V_20 . V_11 = F_25 ( V_64 [ V_66 ++ ] ) ;
V_20 . V_28 = F_25 ( V_64 [ V_66 ++ ] ) ;
if ( ! F_26 ( V_60 , V_20 . V_13 ) ||
! F_26 ( V_60 , V_20 . V_12 ) ||
! F_27 ( V_60 , V_20 . V_11 ) ) {
F_18 ( V_76 L_13 ) ;
return - V_39 ;
}
V_74 = 0 ;
for ( V_43 = 0 ; V_43 < F_22 ( V_79 ) ; V_43 ++ ) {
if ( V_20 . V_28 & V_79 [ V_43 ] )
V_74 ++ ;
}
if ( ! V_74 || V_74 > 1 ) {
F_18 ( V_76 L_14 ) ;
return - V_39 ;
}
if ( ( V_69 < V_80 ) &&
( V_20 . V_28 & V_29 ) ) {
F_18 ( V_76 L_15
L_16
L_17 , V_69 ) ;
return - V_39 ;
} else if ( V_20 . V_28 & V_29 ) {
memset ( & V_25 , 0 , sizeof( struct V_24 ) ) ;
V_73 = F_23 ( & V_25 . V_28 , V_58 , sizeof( V_81 ) ) ;
if ( V_73 ) {
F_18 ( V_76 L_4 ) ;
return V_73 ;
}
V_73 = F_23 ( & V_25 . V_82 , V_58 , sizeof( V_81 ) ) ;
if ( V_73 ) {
F_18 ( V_76 L_4 ) ;
return V_73 ;
}
V_73 = F_23 ( V_71 , V_58 , sizeof( T_1 ) * F_22 ( V_25 . V_72 . V_63 ) ) ;
if ( V_73 ) {
F_18 ( V_76 L_4 ) ;
return V_73 ;
}
for ( V_43 = 0 ; V_43 < F_22 ( V_25 . V_72 . V_63 ) ; V_43 ++ )
V_25 . V_72 . V_63 [ V_43 ] = F_24 ( V_71 [ V_43 ] ) ;
V_22 . V_31 . V_25 = & V_25 ;
} else {
V_73 = F_23 ( V_71 , V_58 , sizeof( T_1 ) ) ;
if ( V_73 ) {
F_18 ( V_76 L_4 ) ;
return V_73 ;
}
V_22 . V_31 . V_32 = F_24 ( * V_71 ) ;
}
if ( ( V_20 . V_28 & V_78 ) &&
! F_26 ( V_60 , V_22 . V_31 . V_32 ) ) {
F_18 ( V_76 L_18 ) ;
return - V_39 ;
}
return F_21 ( V_57 , & V_20 , & V_22 , V_63 ) ;
}
static int F_28 ( struct V_15 * V_57 , struct V_1 * V_61 ,
struct V_21 * V_62 , void * V_63 )
{
return F_8 ( V_57 , V_61 , V_62 ) ;
}
int F_29 ( struct V_15 * V_57 , void * V_58 , struct V_59 * V_60 )
{
int V_73 ;
T_5 V_83 [ 1 ] ;
T_1 V_36 , V_43 ;
V_73 = F_23 ( V_83 , V_58 , sizeof( T_1 ) ) ;
if ( V_73 < 0 ) {
F_18 ( V_76 L_19 ) ;
goto V_84;
}
V_36 = F_24 ( V_83 [ 0 ] ) ;
if ( ! V_36 ) {
F_18 ( V_76 L_20 ) ;
V_73 = - V_39 ;
goto V_84;
}
V_73 = F_16 ( V_57 , V_36 ) ;
if ( V_73 )
goto V_84;
for ( V_43 = 0 ; V_43 < V_36 ; V_43 ++ ) {
V_73 = F_20 ( V_57 , V_58 , V_60 , F_28 , NULL ) ;
if ( V_73 ) {
if ( V_73 == - V_41 )
F_18 ( V_76 L_21 ) ;
else if ( V_73 == - V_40 )
F_18 ( V_76 L_22 ) ;
goto V_84;
}
}
V_73 = 0 ;
V_85:
return V_73 ;
V_84:
F_13 ( V_57 ) ;
goto V_85;
}
int F_30 ( struct V_59 * V_63 , struct V_14 * V_19 , void * V_58 )
{
T_4 V_64 [ 4 ] ;
T_5 V_71 [ F_22 ( V_19 -> V_22 . V_31 . V_25 -> V_72 . V_63 ) ] ;
int V_73 ;
unsigned int V_43 ;
V_64 [ 0 ] = F_31 ( V_19 -> V_20 . V_13 ) ;
V_64 [ 1 ] = F_31 ( V_19 -> V_20 . V_12 ) ;
V_64 [ 2 ] = F_31 ( V_19 -> V_20 . V_11 ) ;
V_64 [ 3 ] = F_31 ( V_19 -> V_20 . V_28 ) ;
V_73 = F_32 ( V_64 , sizeof( T_3 ) , 4 , V_58 ) ;
if ( V_73 )
return V_73 ;
if ( V_19 -> V_20 . V_28 & V_29 ) {
V_73 = F_32 ( & V_19 -> V_22 . V_31 . V_25 -> V_28 , sizeof( V_81 ) , 1 , V_58 ) ;
if ( V_73 )
return V_73 ;
V_73 = F_32 ( & V_19 -> V_22 . V_31 . V_25 -> V_82 , sizeof( V_81 ) , 1 , V_58 ) ;
if ( V_73 )
return V_73 ;
for ( V_43 = 0 ; V_43 < F_22 ( V_19 -> V_22 . V_31 . V_25 -> V_72 . V_63 ) ; V_43 ++ )
V_71 [ V_43 ] = F_33 ( V_19 -> V_22 . V_31 . V_25 -> V_72 . V_63 [ V_43 ] ) ;
V_73 = F_32 ( V_71 , sizeof( T_1 ) ,
F_22 ( V_19 -> V_22 . V_31 . V_25 -> V_72 . V_63 ) , V_58 ) ;
} else {
V_71 [ 0 ] = F_33 ( V_19 -> V_22 . V_31 . V_32 ) ;
V_73 = F_32 ( V_71 , sizeof( T_1 ) , 1 , V_58 ) ;
}
if ( V_73 )
return V_73 ;
return 0 ;
}
int F_34 ( struct V_59 * V_63 , struct V_15 * V_57 , void * V_58 )
{
unsigned int V_43 ;
int V_73 = 0 ;
struct V_14 * V_19 ;
T_5 V_83 [ 1 ] ;
V_83 [ 0 ] = F_33 ( V_57 -> V_36 ) ;
V_73 = F_32 ( V_83 , sizeof( T_1 ) , 1 , V_58 ) ;
if ( V_73 )
return V_73 ;
for ( V_43 = 0 ; V_43 < V_57 -> V_45 ; V_43 ++ ) {
for ( V_19 = F_6 ( V_57 -> V_34 , V_43 ) ; V_19 ;
V_19 = V_19 -> V_33 ) {
V_73 = F_30 ( V_63 , V_19 , V_58 ) ;
if ( V_73 )
return V_73 ;
}
}
return V_73 ;
}
void F_35 ( void )
{
V_26 = F_36 ( L_23 ,
sizeof( struct V_14 ) ,
0 , V_86 , NULL ) ;
V_30 = F_36 ( L_24 ,
sizeof( struct V_24 ) ,
0 , V_86 , NULL ) ;
}
void F_37 ( void )
{
F_38 ( V_26 ) ;
F_38 ( V_30 ) ;
}
