static inline int F_1 ( T_1 * V_1 )
{
return ( ( V_1 [ 0 ] == V_2 ) &&
( V_1 [ 1 ] == V_3 ) &&
( V_1 [ 2 ] == V_4 ) &&
( V_1 [ 3 ] == V_5 ) &&
( V_1 [ 4 ] == V_6 ) ) ;
}
static inline T_2 F_2 ( struct V_7 * V_8 )
{
return ( V_8 -> V_9 -> V_10 << 8 ) | V_8 -> V_11 ;
}
static int F_3 ( struct V_7 * V_12 )
{
unsigned long V_13 ;
int V_14 ;
V_13 = F_4 ( 9 ) ;
V_14 = F_5 ( 0 , & V_13 ) ;
if ( ! V_14 )
F_6 ( & V_12 -> V_15 , L_1 ) ;
return V_14 ;
}
int F_7 ( struct V_7 * V_12 )
{
if ( F_8 ( V_16 ) )
return F_3 ( V_12 ) ;
F_6 ( & V_12 -> V_15 , L_2 ) ;
return 0 ;
}
static int F_9 ( struct V_17 * V_18 , struct V_19 * V_15 )
{
struct V_20 * V_21 = F_10 ( V_18 ) ;
struct V_7 * V_12 ;
int V_22 ;
T_2 V_23 ;
if ( ! F_11 ( V_15 ) )
return - V_24 ;
V_12 = F_12 ( V_15 ) ;
V_23 = F_2 ( V_12 ) ;
if ( V_21 -> V_25 == V_21 -> V_26 )
return - V_24 ;
for ( V_22 = 0 ; V_22 < V_21 -> V_26 ; V_22 ++ ) {
if ( V_21 -> V_27 [ V_22 ] . V_12 == NULL ) {
V_21 -> V_25 ++ ;
V_21 -> V_27 [ V_22 ] . V_12 = V_12 ;
V_21 -> V_27 [ V_22 ] . V_28 = V_23 ;
F_13 ( V_23 , V_21 -> V_29 + ( V_22 * 4 ) ) ;
F_14 ( 0 , V_21 -> V_29 + ( V_22 * 4 ) + 2 ) ;
return V_22 ;
}
}
return - V_30 ;
}
static int F_15 ( struct V_17 * V_18 ,
struct V_19 * V_15 )
{
struct V_20 * V_21 = F_10 ( V_18 ) ;
struct V_7 * V_12 ;
int V_22 ;
if ( ! F_11 ( V_15 ) )
return - V_24 ;
V_12 = F_12 ( V_15 ) ;
for ( V_22 = 0 ; V_22 < V_21 -> V_26 ; V_22 ++ ) {
if ( V_21 -> V_27 [ V_22 ] . V_12 == V_12 ) {
F_13 ( 0 , V_21 -> V_29 + ( V_22 * 4 ) ) ;
V_21 -> V_27 [ V_22 ] . V_12 = NULL ;
V_21 -> V_27 [ V_22 ] . V_28 = 0 ;
V_21 -> V_25 -- ;
return V_22 ;
}
}
return - V_24 ;
}
static T_1 F_16 ( struct V_17 * V_18 ,
struct V_19 * V_15 ,
int V_31 )
{
struct V_20 * V_21 = F_10 ( V_18 ) ;
int V_22 , V_32 , V_33 , V_34 ;
T_1 V_35 , V_36 ;
V_36 = 0 ;
V_32 = F_17 ( V_31 ) ;
for ( V_22 = 0 ; V_22 < V_37 ; V_22 ++ ) {
V_35 = V_21 -> V_1 [ V_22 ] ;
if ( V_35 & V_38 ) {
V_33 = V_35 & ~ V_38 ;
V_34 = ( V_32 & ( 1 << V_33 ) ) ? 1 : 0 ;
} else {
V_34 = V_35 ? 1 : 0 ;
}
V_36 |= ( V_34 << V_22 ) ;
}
return V_36 ;
}
static int F_18 ( struct V_17 * V_18 ,
struct V_19 * V_15 )
{
struct V_20 * V_21 = F_10 ( V_18 ) ;
struct V_7 * V_12 ;
int V_22 ;
V_12 = F_12 ( V_15 ) ;
for ( V_22 = 0 ; V_22 < V_21 -> V_26 ; V_22 ++ ) {
if ( V_21 -> V_27 [ V_22 ] . V_12 == V_12 )
return 1 ;
}
return 0 ;
}
struct V_17 * F_19 ( struct V_7 * V_12 , void T_3 * V_39 )
{
struct V_17 * V_18 ;
struct V_20 * V_21 ;
T_1 * V_1 = NULL ;
int V_22 ;
int V_40 ;
T_1 V_41 ;
T_1 V_26 ;
if ( ! F_7 ( V_12 ) )
return NULL ;
switch ( V_12 -> V_42 ) {
case V_43 :
switch ( V_12 -> V_19 ) {
case V_44 :
V_1 = V_45 ;
break;
case V_46 :
V_1 = V_47 ;
break;
case V_48 :
V_1 = V_49 ;
break;
}
break;
case V_50 :
switch ( V_12 -> V_19 ) {
case V_51 :
V_1 = V_52 ;
break;
}
break;
}
if ( V_1 == NULL )
return NULL ;
V_41 = F_20 ( V_39 + V_53 ) ;
if ( V_41 == V_54 )
V_26 = V_55 ;
else
V_26 = V_56 ;
V_18 = F_21 ( & V_57 ,
sizeof( * V_21 ) +
( sizeof( struct V_58 ) * V_26 ) ) ;
if ( ! V_18 )
return NULL ;
V_21 = F_10 ( V_18 ) ;
V_21 -> V_26 = V_26 ;
V_21 -> V_29 = V_39 + 0x54 ;
for ( V_22 = 0 ; V_22 < V_37 ; V_22 ++ )
V_21 -> V_1 [ V_22 ] = V_1 [ V_22 ] ;
V_40 = F_22 ( V_18 , & V_12 -> V_15 ) ;
if ( V_40 ) {
F_23 ( V_18 ) ;
return NULL ;
}
return V_18 ;
}
static int F_24 ( struct V_17 * V_18 , struct V_19 * V_15 )
{
struct V_20 * V_21 = F_10 ( V_18 ) ;
struct V_7 * V_12 ;
int V_22 ;
T_2 V_23 ;
T_2 V_59 ;
if ( ! F_11 ( V_15 ) )
return - V_24 ;
V_12 = F_12 ( V_15 ) ;
V_23 = F_2 ( V_12 ) ;
if ( V_21 -> V_25 == V_21 -> V_26 )
return - V_24 ;
for ( V_22 = 0 ; V_22 < V_21 -> V_26 ; V_22 ++ ) {
if ( V_21 -> V_27 [ V_22 ] . V_12 == NULL ) {
V_21 -> V_25 ++ ;
V_21 -> V_27 [ V_22 ] . V_12 = V_12 ;
V_21 -> V_27 [ V_22 ] . V_28 = V_23 ;
V_59 =
F_25 ( V_21 -> V_29 + V_60 ) ;
F_26 ( V_23 | V_61 ,
V_21 -> V_39 + V_59 + ( V_22 * 4 ) ) ;
return V_22 ;
}
}
return - V_30 ;
}
static int F_27 ( struct V_17 * V_18 ,
struct V_19 * V_15 )
{
struct V_20 * V_21 = F_10 ( V_18 ) ;
struct V_7 * V_12 ;
int V_22 ;
T_2 V_59 ;
if ( ! F_11 ( V_15 ) )
return - V_24 ;
V_12 = F_12 ( V_15 ) ;
for ( V_22 = 0 ; V_22 < V_21 -> V_26 ; V_22 ++ ) {
if ( V_21 -> V_27 [ V_22 ] . V_12 == V_12 ) {
V_59 =
F_25 ( V_21 -> V_29 + V_60 ) ;
F_26 ( 0 , V_21 -> V_39 + V_59 + ( V_22 * 4 ) ) ;
V_21 -> V_27 [ V_22 ] . V_12 = NULL ;
V_21 -> V_27 [ V_22 ] . V_28 = 0 ;
V_21 -> V_25 -- ;
return V_22 ;
}
}
return - V_24 ;
}
static T_1 F_28 ( struct V_17 * V_18 ,
struct V_19 * V_15 ,
int V_31 )
{
T_1 V_36 ;
V_36 = F_16 ( V_18 , V_15 , V_31 ) ;
V_36 = ( ~ V_36 ) & 0x1F ;
return V_36 ;
}
static int F_29 ( void T_3 * V_39 , T_2 V_62 )
{
int V_63 = 0 ;
T_4 V_64 ;
T_2 V_59 ;
V_59 = F_25 ( V_39 + V_62 + V_60 ) ;
if ( V_59 == 0 )
return 0 ;
do {
V_64 = F_30 ( V_39 + V_59 + ( V_63 * sizeof( T_4 ) ) ) ;
V_63 ++ ;
} while ( ( V_64 & V_65 ) == 0 );
return V_63 ;
}
struct V_17 * F_31 ( struct V_7 * V_12 , void T_3 * V_39 )
{
struct V_17 * V_18 ;
struct V_20 * V_21 ;
int V_63 ;
int V_22 ;
int V_40 ;
T_4 V_1 ;
T_2 V_62 ;
T_2 V_66 ;
T_2 V_67 ;
T_1 V_33 ;
if ( ! F_7 ( V_12 ) )
return NULL ;
V_62 = F_25 ( V_39 + V_68 ) ;
if ( V_62 == 0 )
return NULL ;
V_63 = F_29 ( V_39 , V_62 ) ;
if ( V_63 == 0 )
return NULL ;
V_18 = F_21 ( & V_69 ,
sizeof( * V_21 )
+ ( sizeof( struct V_58 ) * V_63 ) ) ;
if ( ! V_18 )
return NULL ;
V_21 = F_10 ( V_18 ) ;
V_21 -> V_39 = V_39 ;
V_21 -> V_29 = V_39 + V_62 ;
V_21 -> V_26 = V_63 ;
V_66 = F_25 ( V_21 -> V_29 + V_70 ) ;
if ( ( V_66 & V_71 ) == 0 ) {
V_66 |= V_71 ;
F_13 ( V_66 ,
V_21 -> V_29 + V_70 ) ;
}
V_67 = F_25 ( V_21 -> V_29 + V_72 ) ;
if ( ( V_67 & V_73 ) == 0 ) {
V_67 |= V_73 ;
F_13 ( V_67 ,
V_21 -> V_29 + V_72 ) ;
}
V_1 = F_30 ( V_21 -> V_29 + V_74 ) ;
for ( V_22 = 0 ; V_22 < 5 ; V_22 ++ ) {
V_33 = ( V_1 >> ( 4 * V_22 ) ) & 0x0f ;
if ( V_33 < 8 )
V_21 -> V_1 [ V_22 ] = V_33 | V_38 ;
else
V_21 -> V_1 [ V_22 ] = 0 ;
}
if ( ! F_1 ( V_21 -> V_1 ) ) {
F_32 ( 1 , V_75 ,
L_3 ,
F_33 ( & V_12 -> V_15 ) ,
F_34 ( & V_12 -> V_15 ) ) ;
F_23 ( V_18 ) ;
return NULL ;
}
V_40 = F_22 ( V_18 , & V_12 -> V_15 ) ;
if ( V_40 ) {
F_23 ( V_18 ) ;
return NULL ;
}
return V_18 ;
}
static int F_35 ( struct V_17 * V_18 , struct V_19 * V_15 )
{
struct V_20 * V_21 = F_10 ( V_18 ) ;
struct V_7 * V_12 ;
int V_22 ;
T_2 V_23 ;
T_2 V_59 ;
if ( ! F_11 ( V_15 ) )
return - V_24 ;
V_12 = F_12 ( V_15 ) ;
V_23 = F_2 ( V_12 ) ;
if ( V_21 -> V_25 == V_21 -> V_26 )
return - V_24 ;
for ( V_22 = 0 ; V_22 < V_21 -> V_26 ; V_22 ++ ) {
if ( V_21 -> V_27 [ V_22 ] . V_12 == NULL ) {
V_21 -> V_25 ++ ;
V_21 -> V_27 [ V_22 ] . V_12 = V_12 ;
V_21 -> V_27 [ V_22 ] . V_28 = V_23 ;
V_59 =
F_25 ( V_21 -> V_29 + V_76 ) ;
F_26 ( V_23 | V_61 ,
V_21 -> V_39 + V_59 + ( V_22 * 4 ) ) ;
return V_22 ;
}
}
return - V_30 ;
}
static int F_36 ( struct V_17 * V_18 ,
struct V_19 * V_15 )
{
struct V_20 * V_21 = F_10 ( V_18 ) ;
struct V_7 * V_12 ;
int V_22 ;
T_2 V_59 ;
if ( ! F_11 ( V_15 ) )
return - V_24 ;
V_12 = F_12 ( V_15 ) ;
for ( V_22 = 0 ; V_22 < V_21 -> V_26 ; V_22 ++ ) {
if ( V_21 -> V_27 [ V_22 ] . V_12 == V_12 ) {
V_59 =
F_25 ( V_21 -> V_29 + V_76 ) ;
F_26 ( 0 , V_21 -> V_39 + V_59 + ( V_22 * 4 ) ) ;
V_21 -> V_27 [ V_22 ] . V_12 = NULL ;
V_21 -> V_27 [ V_22 ] . V_28 = 0 ;
V_21 -> V_25 -- ;
return V_22 ;
}
}
return - V_24 ;
}
static T_1 F_37 ( struct V_17 * V_18 ,
struct V_19 * V_15 ,
int V_31 )
{
T_1 V_36 ;
struct V_20 * V_21 = F_10 ( V_18 ) ;
int V_22 , V_32 , V_33 , V_34 ;
T_1 V_35 ;
V_36 = 0 ;
V_32 = F_17 ( V_31 ) ;
for ( V_22 = 0 ; V_22 < V_37 ; V_22 ++ ) {
V_35 = V_21 -> V_1 [ V_22 ] ;
if ( V_35 & V_77 ) {
V_33 = V_35 &
~ ( V_77 | V_78 ) ;
V_34 = ( V_32 & ( 1 << V_33 ) ) ? 1 : 0 ;
} else if ( V_35 & V_78 ) {
V_33 = V_35 & ~ V_78 ;
V_34 = ( V_32 & ( 1 << V_33 ) ) ? 0 : 1 ;
} else {
V_34 = ( V_35 & V_79 ) ? 1 : 0 ;
}
V_36 |= ( V_34 << V_22 ) ;
}
return V_36 ;
}
static int F_38 ( void * V_39 , T_2 V_62 )
{
int V_63 = 0 ;
T_4 V_64 ;
T_2 V_59 ;
V_59 = F_25 ( V_39 + V_62 + V_76 ) ;
if ( V_59 == 0 )
return 0 ;
do {
V_64 = F_30 ( V_39 + V_59 + ( V_63 * sizeof( T_4 ) ) ) ;
V_63 ++ ;
} while ( ( V_64 & V_65 ) == 0 );
return V_63 ;
}
static inline int F_39 ( T_1 * V_1 )
{
return ( ( V_1 [ 0 ] == V_38 ) &&
( V_1 [ 1 ] == V_38 ) &&
( V_1 [ 2 ] == V_38 ) &&
( V_1 [ 3 ] == V_38 ) &&
( V_1 [ 4 ] == V_38 ) ) ;
}
struct V_17 * F_40 ( struct V_7 * V_12 , void T_3 * V_39 )
{
struct V_17 * V_18 ;
struct V_20 * V_21 ;
int V_63 ;
int V_22 ;
int V_40 ;
T_2 V_62 ;
T_2 V_66 ;
T_2 V_67 ;
T_1 V_33 ;
union {
T_5 V_80 ;
struct {
T_4 V_81 ;
T_4 V_82 ;
};
} V_1 ;
if ( ! F_7 ( V_12 ) )
return NULL ;
V_62 = F_25 ( V_39 + V_68 ) ;
if ( V_62 == 0 )
return NULL ;
V_63 = F_38 ( V_39 , V_62 ) ;
if ( V_63 == 0 )
return NULL ;
V_18 = F_21 ( & V_83 ,
sizeof( * V_21 )
+ ( sizeof( struct V_58 ) * V_63 ) ) ;
if ( ! V_18 )
return NULL ;
V_21 = F_10 ( V_18 ) ;
V_21 -> V_39 = V_39 ;
V_21 -> V_29 = V_39 + V_62 ;
V_21 -> V_26 = V_63 ;
V_66 = F_25 ( V_21 -> V_29 + V_84 ) ;
if ( ( V_66 & V_85 ) == 0 ) {
V_66 |= V_85 ;
F_13 ( V_66 ,
V_21 -> V_29 + V_84 ) ;
}
V_67 = F_25 ( V_21 -> V_29 + V_86 ) ;
if ( ( V_67 & V_87 ) == 0 ) {
V_67 |= V_87 ;
F_13 ( V_67 ,
V_21 -> V_29 + V_86 ) ;
}
V_1 . V_81 =
F_30 ( V_21 -> V_29 + V_88 ) ;
V_1 . V_82 =
F_30 ( V_21 -> V_29 + V_89 ) ;
for ( V_22 = 0 ; V_22 < 8 ; V_22 ++ ) {
V_33 = V_1 . V_80 >> ( 8 * V_22 ) ;
V_21 -> V_1 [ V_22 ] = V_33 & V_90 ;
}
if ( F_39 ( V_21 -> V_1 ) ) {
F_32 ( 1 , V_75 ,
L_3 ,
F_33 ( & V_12 -> V_15 ) ,
F_34 ( & V_12 -> V_15 ) ) ;
F_23 ( V_18 ) ;
return NULL ;
}
V_40 = F_22 ( V_18 , & V_12 -> V_15 ) ;
if ( V_40 ) {
F_23 ( V_18 ) ;
return NULL ;
}
return V_18 ;
}
