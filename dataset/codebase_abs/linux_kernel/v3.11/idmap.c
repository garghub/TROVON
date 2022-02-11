static int F_1 ( T_1 * V_1 ,
T_2 V_2 )
{
int V_3 , V_4 ;
if ( ! V_1 )
return 0 ;
V_3 = 0 ;
V_4 = V_1 -> V_5 ;
while ( V_3 < V_4 ) {
int V_6 = ( V_3 + V_4 ) / 2 ;
int V_7 = V_2 - F_2 ( V_1 , V_6 ) ;
if ( V_7 > 0 )
V_3 = V_6 + 1 ;
else if ( V_7 < 0 )
V_4 = V_6 ;
else
return 1 ;
}
return 0 ;
}
void F_3 ( T_1 * V_8 , T_2 * V_9 )
{
int V_10 ;
int V_11 = V_8 -> V_5 ;
for ( V_10 = 0 ; V_10 < V_8 -> V_12 && V_11 > 0 ; V_10 ++ ) {
int V_13 = F_4 ( V_14 , V_11 ) ;
int V_15 = V_10 * V_14 ;
int V_16 = V_13 * sizeof( * V_9 ) ;
memcpy ( V_8 -> V_17 [ V_10 ] , V_9 + V_15 , V_16 ) ;
V_11 -= V_13 ;
}
}
void F_5 ( T_1 * V_1 )
{
int V_18 , V_19 , V_20 ;
int V_21 = V_1 -> V_5 ;
for ( V_20 = 1 ; V_20 < V_21 ; V_20 = 3 * V_20 + 1 )
;
V_20 /= 3 ;
while ( V_20 ) {
V_19 = V_21 - V_20 ;
for ( V_18 = 0 ; V_18 < V_19 ; V_18 ++ ) {
int V_3 = V_18 ;
int V_4 = V_3 + V_20 ;
T_2 V_22 = F_2 ( V_1 , V_4 ) ;
while ( V_3 >= 0 &&
F_2 ( V_1 , V_3 ) > V_22 ) {
F_2 ( V_1 , V_4 ) =
F_2 ( V_1 , V_3 ) ;
V_4 = V_3 ;
V_3 -= V_20 ;
}
F_2 ( V_1 , V_4 ) = V_22 ;
}
V_20 /= 3 ;
}
}
int F_6 ( struct V_23 * V_24 , T_2 V_2 )
{
int V_25 = 1 ;
if ( V_2 != V_24 -> V_26 ) {
T_1 * V_1 = NULL ;
if ( V_24 -> V_27 || ! V_24 -> V_28 ||
V_24 -> V_29 == V_30 )
if ( V_2 == V_24 -> V_31 [ 0 ] ||
V_2 == V_24 -> V_31 [ 1 ] )
return 1 ;
if ( V_24 -> V_27 )
V_1 = V_24 -> V_27 ;
else if ( V_24 -> V_28 )
V_1 = V_24 -> V_28 -> V_32 ;
if ( ! V_1 )
return 0 ;
F_7 ( V_1 ) ;
V_25 = F_1 ( V_1 , V_2 ) ;
F_8 ( V_1 ) ;
}
return V_25 ;
}
static inline T_3 F_9 ( T_3 V_33 )
{
return V_33 & ( V_34 - 1 ) ;
}
static
struct V_35 * F_10 ( T_4 V_36 , T_4 V_37 ,
T_2 V_38 , T_2 V_39 )
{
struct V_35 * V_40 ;
F_11 ( V_40 ) ;
if ( V_40 == NULL )
return NULL ;
F_12 ( & V_40 -> V_41 ) ;
F_12 ( & V_40 -> V_42 ) ;
F_12 ( & V_40 -> V_43 ) ;
F_12 ( & V_40 -> V_44 ) ;
V_40 -> V_45 = V_36 ;
V_40 -> V_46 = V_37 ;
V_40 -> V_47 = V_38 ;
V_40 -> V_48 = V_39 ;
return V_40 ;
}
static void F_13 ( struct V_35 * V_40 )
{
if ( ! F_14 ( & V_40 -> V_41 ) )
F_15 ( & V_40 -> V_41 ) ;
if ( ! F_14 ( & V_40 -> V_42 ) )
F_15 ( & V_40 -> V_42 ) ;
if ( ! F_14 ( & V_40 -> V_43 ) )
F_15 ( & V_40 -> V_43 ) ;
if ( ! F_14 ( & V_40 -> V_44 ) )
F_15 ( & V_40 -> V_44 ) ;
F_16 ( V_40 ) ;
}
static
struct V_35 * F_17 ( struct V_49 * V_50 ,
T_4 V_36 , T_4 V_37 ,
T_2 V_38 , T_2 V_39 )
{
struct V_51 * V_52 ;
struct V_35 * V_40 ;
V_52 = & V_50 -> V_53 [ V_54 ] [ F_9 ( V_36 ) ] ;
F_18 (e, head, lie_rmt_uid_hash)
if ( V_40 -> V_45 == V_36 ) {
if ( V_40 -> V_46 == V_37 ) {
if ( V_40 -> V_47 == V_38 &&
V_40 -> V_48 == V_39 )
return V_40 ;
} else {
F_19 ( L_1
L_2 , V_40 -> V_45 ,
V_40 -> V_46 , V_37 ) ;
return F_20 ( - V_55 ) ;
}
}
V_52 = & V_50 -> V_53 [ V_56 ] [ F_9 ( V_38 ) ] ;
F_18 (e, head, lie_rmt_gid_hash)
if ( V_40 -> V_47 == V_38 ) {
if ( V_40 -> V_48 == V_39 ) {
if ( F_21 ( V_40 -> V_45 == V_36 &&
V_40 -> V_46 == V_37 ) )
F_22 () ;
} else {
F_19 ( L_3
L_2 , V_40 -> V_47 ,
V_40 -> V_48 , V_39 ) ;
return F_20 ( - V_55 ) ;
}
}
return NULL ;
}
static T_3 F_23 ( struct V_51 * V_57 , int V_58 ,
T_3 V_59 )
{
struct V_51 * V_52 = & V_57 [ F_9 ( V_59 ) ] ;
struct V_35 * V_40 ;
if ( ! V_58 ) {
F_18 (e, head, lie_rmt_uid_hash)
if ( V_40 -> V_45 == V_59 )
return V_40 -> V_46 ;
} else {
F_18 (e, head, lie_lcl_uid_hash)
if ( V_40 -> V_46 == V_59 )
return V_40 -> V_45 ;
}
return V_60 ;
}
static T_3 F_24 ( struct V_51 * V_57 , int V_58 , T_3 V_61 )
{
struct V_51 * V_52 = & V_57 [ F_9 ( V_61 ) ] ;
struct V_35 * V_40 ;
if ( ! V_58 ) {
F_18 (e, head, lie_rmt_gid_hash)
if ( V_40 -> V_47 == V_61 )
return V_40 -> V_48 ;
} else {
F_18 (e, head, lie_lcl_gid_hash)
if ( V_40 -> V_48 == V_61 )
return V_40 -> V_47 ;
}
return V_60 ;
}
int F_25 ( struct V_49 * V_50 ,
T_4 V_62 , T_4 V_63 ,
T_2 V_64 , T_2 V_65 )
{
struct V_35 * V_66 , * V_67 ;
F_26 ( V_50 ) ;
F_27 ( & V_50 -> V_68 ) ;
V_66 = F_17 ( V_50 , V_62 , V_63 , V_64 , V_65 ) ;
F_28 ( & V_50 -> V_68 ) ;
if ( ! V_66 ) {
V_66 = F_10 ( V_62 , V_63 , V_64 , V_65 ) ;
if ( ! V_66 )
return - V_69 ;
F_27 ( & V_50 -> V_68 ) ;
V_67 = F_17 ( V_50 , V_62 , V_63 , V_64 , V_65 ) ;
if ( V_67 == NULL ) {
F_29 ( & V_66 -> V_41 ,
& V_50 -> V_53 [ V_54 ]
[ F_9 ( V_62 ) ] ) ;
F_29 ( & V_66 -> V_42 ,
& V_50 -> V_53 [ V_70 ]
[ F_9 ( V_63 ) ] ) ;
F_29 ( & V_66 -> V_43 ,
& V_50 -> V_53 [ V_56 ]
[ F_9 ( V_64 ) ] ) ;
F_29 ( & V_66 -> V_44 ,
& V_50 -> V_53 [ V_71 ]
[ F_9 ( V_65 ) ] ) ;
}
F_28 ( & V_50 -> V_68 ) ;
if ( V_67 != NULL ) {
F_13 ( V_66 ) ;
if ( F_30 ( V_67 ) )
return F_31 ( V_67 ) ;
}
} else if ( F_30 ( V_66 ) ) {
return F_31 ( V_66 ) ;
}
return 0 ;
}
int F_32 ( struct V_49 * V_50 ,
T_4 V_62 , T_4 V_63 ,
T_2 V_64 , T_2 V_65 )
{
struct V_35 * V_40 ;
int V_25 = 0 ;
F_26 ( V_50 ) ;
F_27 ( & V_50 -> V_68 ) ;
V_40 = F_17 ( V_50 , V_62 , V_63 , V_64 , V_65 ) ;
if ( F_30 ( V_40 ) )
V_25 = F_31 ( V_40 ) ;
else if ( V_40 )
F_13 ( V_40 ) ;
F_28 ( & V_50 -> V_68 ) ;
return V_25 ;
}
int F_33 ( struct V_23 * V_24 ,
struct V_49 * V_50 ,
int V_58 , T_4 V_59 )
{
struct V_51 * V_57 ;
if ( V_24 && ( V_24 -> V_29 == V_30 || V_24 -> V_29 == V_72 ) ) {
if ( ! V_58 ) {
if ( V_59 == V_24 -> V_73 )
return V_24 -> V_74 ;
else if ( V_59 == V_24 -> V_75 )
return V_24 -> V_76 ;
} else {
if ( V_59 == V_24 -> V_74 )
return V_24 -> V_73 ;
else if ( V_59 == V_24 -> V_76 )
return V_24 -> V_75 ;
}
}
if ( V_50 == NULL )
return V_60 ;
V_57 = V_50 -> V_53 [ V_58 ? V_70 : V_54 ] ;
F_27 ( & V_50 -> V_68 ) ;
V_59 = F_23 ( V_57 , V_58 , V_59 ) ;
F_28 ( & V_50 -> V_68 ) ;
return V_59 ;
}
int F_34 ( struct V_23 * V_24 , struct V_49 * V_50 ,
int V_58 , T_2 V_61 )
{
struct V_51 * V_57 ;
if ( V_24 && ( V_24 -> V_29 == V_30 || V_24 -> V_29 == V_72 ) ) {
if ( ! V_58 ) {
if ( V_61 == V_24 -> V_77 )
return V_24 -> V_78 ;
else if ( V_61 == V_24 -> V_79 )
return V_24 -> V_26 ;
} else {
if ( V_61 == V_24 -> V_78 )
return V_24 -> V_77 ;
else if ( V_61 == V_24 -> V_26 )
return V_24 -> V_79 ;
}
}
if ( V_50 == NULL )
return V_60 ;
V_57 = V_50 -> V_53 [ V_58 ? V_71 : V_56 ] ;
F_27 ( & V_50 -> V_68 ) ;
V_61 = F_24 ( V_57 , V_58 , V_61 ) ;
F_28 ( & V_50 -> V_68 ) ;
return V_61 ;
}
struct V_49 * F_35 ( void )
{
struct V_49 * V_50 ;
int V_10 , V_80 ;
F_11 ( V_50 ) ;
if( F_21 ( V_50 == NULL ) )
return ( F_20 ( - V_69 ) ) ;
F_36 ( & V_50 -> V_68 ) ;
for ( V_10 = 0 ; V_10 < F_37 ( V_50 -> V_53 ) ; V_10 ++ )
for ( V_80 = 0 ; V_80 < F_37 ( V_50 -> V_53 [ V_10 ] ) ; V_80 ++ )
F_12 ( & V_50 -> V_53 [ V_10 ] [ V_80 ] ) ;
return V_50 ;
}
void F_38 ( struct V_49 * V_50 )
{
struct V_51 * V_81 ;
struct V_35 * V_40 ;
int V_10 ;
F_26 ( V_50 ) ;
V_81 = V_50 -> V_53 [ V_54 ] ;
F_27 ( & V_50 -> V_68 ) ;
for ( V_10 = 0 ; V_10 < V_34 ; V_10 ++ )
while ( ! F_14 ( & V_81 [ V_10 ] ) ) {
V_40 = F_39 ( V_81 [ V_10 ] . V_82 ,
struct V_35 ,
V_41 ) ;
F_13 ( V_40 ) ;
}
F_28 ( & V_50 -> V_68 ) ;
F_16 ( V_50 ) ;
}
