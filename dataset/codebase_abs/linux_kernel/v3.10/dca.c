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
if ( V_15 -> V_9 != & V_24 )
return - V_25 ;
V_12 = F_11 ( V_15 ) ;
V_23 = F_2 ( V_12 ) ;
if ( V_21 -> V_26 == V_21 -> V_27 )
return - V_25 ;
for ( V_22 = 0 ; V_22 < V_21 -> V_27 ; V_22 ++ ) {
if ( V_21 -> V_28 [ V_22 ] . V_12 == NULL ) {
V_21 -> V_26 ++ ;
V_21 -> V_28 [ V_22 ] . V_12 = V_12 ;
V_21 -> V_28 [ V_22 ] . V_29 = V_23 ;
F_12 ( V_23 , V_21 -> V_30 + ( V_22 * 4 ) ) ;
F_13 ( 0 , V_21 -> V_30 + ( V_22 * 4 ) + 2 ) ;
return V_22 ;
}
}
return - V_31 ;
}
static int F_14 ( struct V_17 * V_18 ,
struct V_19 * V_15 )
{
struct V_20 * V_21 = F_10 ( V_18 ) ;
struct V_7 * V_12 ;
int V_22 ;
if ( V_15 -> V_9 != & V_24 )
return - V_25 ;
V_12 = F_11 ( V_15 ) ;
for ( V_22 = 0 ; V_22 < V_21 -> V_27 ; V_22 ++ ) {
if ( V_21 -> V_28 [ V_22 ] . V_12 == V_12 ) {
F_12 ( 0 , V_21 -> V_30 + ( V_22 * 4 ) ) ;
V_21 -> V_28 [ V_22 ] . V_12 = NULL ;
V_21 -> V_28 [ V_22 ] . V_29 = 0 ;
V_21 -> V_26 -- ;
return V_22 ;
}
}
return - V_25 ;
}
static T_1 F_15 ( struct V_17 * V_18 ,
struct V_19 * V_15 ,
int V_32 )
{
struct V_20 * V_21 = F_10 ( V_18 ) ;
int V_22 , V_33 , V_34 , V_35 ;
T_1 V_36 , V_37 ;
V_37 = 0 ;
V_33 = F_16 ( V_32 ) ;
for ( V_22 = 0 ; V_22 < V_38 ; V_22 ++ ) {
V_36 = V_21 -> V_1 [ V_22 ] ;
if ( V_36 & V_39 ) {
V_34 = V_36 & ~ V_39 ;
V_35 = ( V_33 & ( 1 << V_34 ) ) ? 1 : 0 ;
} else {
V_35 = V_36 ? 1 : 0 ;
}
V_37 |= ( V_35 << V_22 ) ;
}
return V_37 ;
}
static int F_17 ( struct V_17 * V_18 ,
struct V_19 * V_15 )
{
struct V_20 * V_21 = F_10 ( V_18 ) ;
struct V_7 * V_12 ;
int V_22 ;
V_12 = F_11 ( V_15 ) ;
for ( V_22 = 0 ; V_22 < V_21 -> V_27 ; V_22 ++ ) {
if ( V_21 -> V_28 [ V_22 ] . V_12 == V_12 )
return 1 ;
}
return 0 ;
}
struct V_17 * F_18 ( struct V_7 * V_12 , void T_3 * V_40 )
{
struct V_17 * V_18 ;
struct V_20 * V_21 ;
T_1 * V_1 = NULL ;
int V_22 ;
int V_41 ;
T_1 V_42 ;
T_1 V_27 ;
if ( ! F_7 ( V_12 ) )
return NULL ;
switch ( V_12 -> V_43 ) {
case V_44 :
switch ( V_12 -> V_19 ) {
case V_45 :
V_1 = V_46 ;
break;
case V_47 :
V_1 = V_48 ;
break;
case V_49 :
V_1 = V_50 ;
break;
}
break;
case V_51 :
switch ( V_12 -> V_19 ) {
case V_52 :
V_1 = V_53 ;
break;
}
break;
}
if ( V_1 == NULL )
return NULL ;
V_42 = F_19 ( V_40 + V_54 ) ;
if ( V_42 == V_55 )
V_27 = V_56 ;
else
V_27 = V_57 ;
V_18 = F_20 ( & V_58 ,
sizeof( * V_21 ) +
( sizeof( struct V_59 ) * V_27 ) ) ;
if ( ! V_18 )
return NULL ;
V_21 = F_10 ( V_18 ) ;
V_21 -> V_27 = V_27 ;
V_21 -> V_30 = V_40 + 0x54 ;
for ( V_22 = 0 ; V_22 < V_38 ; V_22 ++ )
V_21 -> V_1 [ V_22 ] = V_1 [ V_22 ] ;
V_41 = F_21 ( V_18 , & V_12 -> V_15 ) ;
if ( V_41 ) {
F_22 ( V_18 ) ;
return NULL ;
}
return V_18 ;
}
static int F_23 ( struct V_17 * V_18 , struct V_19 * V_15 )
{
struct V_20 * V_21 = F_10 ( V_18 ) ;
struct V_7 * V_12 ;
int V_22 ;
T_2 V_23 ;
T_2 V_60 ;
if ( V_15 -> V_9 != & V_24 )
return - V_25 ;
V_12 = F_11 ( V_15 ) ;
V_23 = F_2 ( V_12 ) ;
if ( V_21 -> V_26 == V_21 -> V_27 )
return - V_25 ;
for ( V_22 = 0 ; V_22 < V_21 -> V_27 ; V_22 ++ ) {
if ( V_21 -> V_28 [ V_22 ] . V_12 == NULL ) {
V_21 -> V_26 ++ ;
V_21 -> V_28 [ V_22 ] . V_12 = V_12 ;
V_21 -> V_28 [ V_22 ] . V_29 = V_23 ;
V_60 =
F_24 ( V_21 -> V_30 + V_61 ) ;
F_25 ( V_23 | V_62 ,
V_21 -> V_40 + V_60 + ( V_22 * 4 ) ) ;
return V_22 ;
}
}
return - V_31 ;
}
static int F_26 ( struct V_17 * V_18 ,
struct V_19 * V_15 )
{
struct V_20 * V_21 = F_10 ( V_18 ) ;
struct V_7 * V_12 ;
int V_22 ;
T_2 V_60 ;
if ( V_15 -> V_9 != & V_24 )
return - V_25 ;
V_12 = F_11 ( V_15 ) ;
for ( V_22 = 0 ; V_22 < V_21 -> V_27 ; V_22 ++ ) {
if ( V_21 -> V_28 [ V_22 ] . V_12 == V_12 ) {
V_60 =
F_24 ( V_21 -> V_30 + V_61 ) ;
F_25 ( 0 , V_21 -> V_40 + V_60 + ( V_22 * 4 ) ) ;
V_21 -> V_28 [ V_22 ] . V_12 = NULL ;
V_21 -> V_28 [ V_22 ] . V_29 = 0 ;
V_21 -> V_26 -- ;
return V_22 ;
}
}
return - V_25 ;
}
static T_1 F_27 ( struct V_17 * V_18 ,
struct V_19 * V_15 ,
int V_32 )
{
T_1 V_37 ;
V_37 = F_15 ( V_18 , V_15 , V_32 ) ;
V_37 = ( ~ V_37 ) & 0x1F ;
return V_37 ;
}
static int F_28 ( void T_3 * V_40 , T_2 V_63 )
{
int V_64 = 0 ;
T_4 V_65 ;
T_2 V_60 ;
V_60 = F_24 ( V_40 + V_63 + V_61 ) ;
if ( V_60 == 0 )
return 0 ;
do {
V_65 = F_29 ( V_40 + V_60 + ( V_64 * sizeof( T_4 ) ) ) ;
V_64 ++ ;
} while ( ( V_65 & V_66 ) == 0 );
return V_64 ;
}
struct V_17 * F_30 ( struct V_7 * V_12 , void T_3 * V_40 )
{
struct V_17 * V_18 ;
struct V_20 * V_21 ;
int V_64 ;
int V_22 ;
int V_41 ;
T_4 V_1 ;
T_2 V_63 ;
T_2 V_67 ;
T_2 V_68 ;
T_1 V_34 ;
if ( ! F_7 ( V_12 ) )
return NULL ;
V_63 = F_24 ( V_40 + V_69 ) ;
if ( V_63 == 0 )
return NULL ;
V_64 = F_28 ( V_40 , V_63 ) ;
if ( V_64 == 0 )
return NULL ;
V_18 = F_20 ( & V_70 ,
sizeof( * V_21 )
+ ( sizeof( struct V_59 ) * V_64 ) ) ;
if ( ! V_18 )
return NULL ;
V_21 = F_10 ( V_18 ) ;
V_21 -> V_40 = V_40 ;
V_21 -> V_30 = V_40 + V_63 ;
V_21 -> V_27 = V_64 ;
V_67 = F_24 ( V_21 -> V_30 + V_71 ) ;
if ( ( V_67 & V_72 ) == 0 ) {
V_67 |= V_72 ;
F_12 ( V_67 ,
V_21 -> V_30 + V_71 ) ;
}
V_68 = F_24 ( V_21 -> V_30 + V_73 ) ;
if ( ( V_68 & V_74 ) == 0 ) {
V_68 |= V_74 ;
F_12 ( V_68 ,
V_21 -> V_30 + V_73 ) ;
}
V_1 = F_29 ( V_21 -> V_30 + V_75 ) ;
for ( V_22 = 0 ; V_22 < 5 ; V_22 ++ ) {
V_34 = ( V_1 >> ( 4 * V_22 ) ) & 0x0f ;
if ( V_34 < 8 )
V_21 -> V_1 [ V_22 ] = V_34 | V_39 ;
else
V_21 -> V_1 [ V_22 ] = 0 ;
}
if ( ! F_1 ( V_21 -> V_1 ) ) {
F_31 ( 1 , V_76 ,
L_3 ,
F_32 ( & V_12 -> V_15 ) ,
F_33 ( & V_12 -> V_15 ) ) ;
F_22 ( V_18 ) ;
return NULL ;
}
V_41 = F_21 ( V_18 , & V_12 -> V_15 ) ;
if ( V_41 ) {
F_22 ( V_18 ) ;
return NULL ;
}
return V_18 ;
}
static int F_34 ( struct V_17 * V_18 , struct V_19 * V_15 )
{
struct V_20 * V_21 = F_10 ( V_18 ) ;
struct V_7 * V_12 ;
int V_22 ;
T_2 V_23 ;
T_2 V_60 ;
if ( V_15 -> V_9 != & V_24 )
return - V_25 ;
V_12 = F_11 ( V_15 ) ;
V_23 = F_2 ( V_12 ) ;
if ( V_21 -> V_26 == V_21 -> V_27 )
return - V_25 ;
for ( V_22 = 0 ; V_22 < V_21 -> V_27 ; V_22 ++ ) {
if ( V_21 -> V_28 [ V_22 ] . V_12 == NULL ) {
V_21 -> V_26 ++ ;
V_21 -> V_28 [ V_22 ] . V_12 = V_12 ;
V_21 -> V_28 [ V_22 ] . V_29 = V_23 ;
V_60 =
F_24 ( V_21 -> V_30 + V_77 ) ;
F_25 ( V_23 | V_62 ,
V_21 -> V_40 + V_60 + ( V_22 * 4 ) ) ;
return V_22 ;
}
}
return - V_31 ;
}
static int F_35 ( struct V_17 * V_18 ,
struct V_19 * V_15 )
{
struct V_20 * V_21 = F_10 ( V_18 ) ;
struct V_7 * V_12 ;
int V_22 ;
T_2 V_60 ;
if ( V_15 -> V_9 != & V_24 )
return - V_25 ;
V_12 = F_11 ( V_15 ) ;
for ( V_22 = 0 ; V_22 < V_21 -> V_27 ; V_22 ++ ) {
if ( V_21 -> V_28 [ V_22 ] . V_12 == V_12 ) {
V_60 =
F_24 ( V_21 -> V_30 + V_77 ) ;
F_25 ( 0 , V_21 -> V_40 + V_60 + ( V_22 * 4 ) ) ;
V_21 -> V_28 [ V_22 ] . V_12 = NULL ;
V_21 -> V_28 [ V_22 ] . V_29 = 0 ;
V_21 -> V_26 -- ;
return V_22 ;
}
}
return - V_25 ;
}
static T_1 F_36 ( struct V_17 * V_18 ,
struct V_19 * V_15 ,
int V_32 )
{
T_1 V_37 ;
struct V_20 * V_21 = F_10 ( V_18 ) ;
int V_22 , V_33 , V_34 , V_35 ;
T_1 V_36 ;
V_37 = 0 ;
V_33 = F_16 ( V_32 ) ;
for ( V_22 = 0 ; V_22 < V_38 ; V_22 ++ ) {
V_36 = V_21 -> V_1 [ V_22 ] ;
if ( V_36 & V_78 ) {
V_34 = V_36 &
~ ( V_78 | V_79 ) ;
V_35 = ( V_33 & ( 1 << V_34 ) ) ? 1 : 0 ;
} else if ( V_36 & V_79 ) {
V_34 = V_36 & ~ V_79 ;
V_35 = ( V_33 & ( 1 << V_34 ) ) ? 0 : 1 ;
} else {
V_35 = ( V_36 & V_80 ) ? 1 : 0 ;
}
V_37 |= ( V_35 << V_22 ) ;
}
return V_37 ;
}
static int F_37 ( void * V_40 , T_2 V_63 )
{
int V_64 = 0 ;
T_4 V_65 ;
T_2 V_60 ;
V_60 = F_24 ( V_40 + V_63 + V_77 ) ;
if ( V_60 == 0 )
return 0 ;
do {
V_65 = F_29 ( V_40 + V_60 + ( V_64 * sizeof( T_4 ) ) ) ;
V_64 ++ ;
} while ( ( V_65 & V_66 ) == 0 );
return V_64 ;
}
static inline int F_38 ( T_1 * V_1 )
{
return ( ( V_1 [ 0 ] == V_39 ) &&
( V_1 [ 1 ] == V_39 ) &&
( V_1 [ 2 ] == V_39 ) &&
( V_1 [ 3 ] == V_39 ) &&
( V_1 [ 4 ] == V_39 ) ) ;
}
struct V_17 * F_39 ( struct V_7 * V_12 , void T_3 * V_40 )
{
struct V_17 * V_18 ;
struct V_20 * V_21 ;
int V_64 ;
int V_22 ;
int V_41 ;
T_2 V_63 ;
T_2 V_67 ;
T_2 V_68 ;
T_1 V_34 ;
union {
T_5 V_81 ;
struct {
T_4 V_82 ;
T_4 V_83 ;
};
} V_1 ;
if ( ! F_7 ( V_12 ) )
return NULL ;
V_63 = F_24 ( V_40 + V_69 ) ;
if ( V_63 == 0 )
return NULL ;
V_64 = F_37 ( V_40 , V_63 ) ;
if ( V_64 == 0 )
return NULL ;
V_18 = F_20 ( & V_84 ,
sizeof( * V_21 )
+ ( sizeof( struct V_59 ) * V_64 ) ) ;
if ( ! V_18 )
return NULL ;
V_21 = F_10 ( V_18 ) ;
V_21 -> V_40 = V_40 ;
V_21 -> V_30 = V_40 + V_63 ;
V_21 -> V_27 = V_64 ;
V_67 = F_24 ( V_21 -> V_30 + V_85 ) ;
if ( ( V_67 & V_86 ) == 0 ) {
V_67 |= V_86 ;
F_12 ( V_67 ,
V_21 -> V_30 + V_85 ) ;
}
V_68 = F_24 ( V_21 -> V_30 + V_87 ) ;
if ( ( V_68 & V_88 ) == 0 ) {
V_68 |= V_88 ;
F_12 ( V_68 ,
V_21 -> V_30 + V_87 ) ;
}
V_1 . V_82 =
F_29 ( V_21 -> V_30 + V_89 ) ;
V_1 . V_83 =
F_29 ( V_21 -> V_30 + V_90 ) ;
for ( V_22 = 0 ; V_22 < 8 ; V_22 ++ ) {
V_34 = V_1 . V_81 >> ( 8 * V_22 ) ;
V_21 -> V_1 [ V_22 ] = V_34 & V_91 ;
}
if ( F_38 ( V_21 -> V_1 ) ) {
F_31 ( 1 , V_76 ,
L_3 ,
F_32 ( & V_12 -> V_15 ) ,
F_33 ( & V_12 -> V_15 ) ) ;
F_22 ( V_18 ) ;
return NULL ;
}
V_41 = F_21 ( V_18 , & V_12 -> V_15 ) ;
if ( V_41 ) {
F_22 ( V_18 ) ;
return NULL ;
}
return V_18 ;
}
