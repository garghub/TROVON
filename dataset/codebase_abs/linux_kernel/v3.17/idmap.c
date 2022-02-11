static int F_1 ( const struct V_1 * V_1 , T_1 V_2 )
{
int V_3 , V_4 ;
if ( ! V_1 )
return 0 ;
V_3 = 0 ;
V_4 = V_1 -> V_5 ;
while ( V_3 < V_4 ) {
int V_6 = ( V_3 + V_4 ) / 2 ;
int V_7 = V_2 -
F_2 ( & V_8 , F_3 ( V_1 , V_6 ) ) ;
if ( V_7 > 0 )
V_3 = V_6 + 1 ;
else if ( V_7 < 0 )
V_4 = V_6 ;
else
return 1 ;
}
return 0 ;
}
void F_4 ( struct V_1 * V_9 , T_1 * V_10 )
{
int V_11 ;
int V_12 = V_9 -> V_5 ;
for ( V_11 = 0 ; V_11 < V_9 -> V_13 && V_12 > 0 ; V_11 ++ ) {
int V_14 = F_5 ( V_15 , V_12 ) ;
int V_16 = V_11 * V_15 ;
int V_17 = V_14 * sizeof( * V_10 ) ;
memcpy ( V_9 -> V_18 [ V_11 ] , V_10 + V_16 , V_17 ) ;
V_12 -= V_14 ;
}
}
void F_6 ( struct V_1 * V_1 )
{
int V_19 , V_20 , V_21 ;
int V_22 = V_1 -> V_5 ;
for ( V_21 = 1 ; V_21 < V_22 ; V_21 = 3 * V_21 + 1 )
;
V_21 /= 3 ;
while ( V_21 ) {
V_20 = V_22 - V_21 ;
for ( V_19 = 0 ; V_19 < V_20 ; V_19 ++ ) {
int V_3 = V_19 ;
int V_4 = V_3 + V_21 ;
T_1 V_23 = F_2 ( & V_8 ,
F_3 ( V_1 , V_4 ) ) ;
while ( V_3 >= 0 &&
V_23 < F_2 ( & V_8 ,
F_3 ( V_1 , V_3 ) ) ) {
F_3 ( V_1 , V_4 ) =
F_3 ( V_1 , V_3 ) ;
V_4 = V_3 ;
V_3 -= V_21 ;
}
F_3 ( V_1 , V_4 ) =
F_7 ( & V_8 , V_23 ) ;
}
V_21 /= 3 ;
}
}
int F_8 ( struct V_24 * V_25 , T_1 V_2 )
{
int V_26 = 1 ;
if ( V_2 != V_25 -> V_27 ) {
struct V_1 * V_1 = NULL ;
if ( V_25 -> V_28 || ! V_25 -> V_29 ||
V_25 -> V_30 == V_31 )
if ( V_2 == V_25 -> V_32 [ 0 ] ||
V_2 == V_25 -> V_32 [ 1 ] )
return 1 ;
if ( V_25 -> V_28 )
V_1 = V_25 -> V_28 ;
else if ( V_25 -> V_29 )
V_1 = V_25 -> V_29 -> V_33 ;
if ( ! V_1 )
return 0 ;
F_9 ( V_1 ) ;
V_26 = F_1 ( V_1 , V_2 ) ;
F_10 ( V_1 ) ;
}
return V_26 ;
}
static inline T_2 F_11 ( T_2 V_34 )
{
return V_34 & ( V_35 - 1 ) ;
}
static
struct V_36 * F_12 ( T_3 V_37 , T_3 V_38 ,
T_1 V_39 , T_1 V_40 )
{
struct V_36 * V_41 ;
F_13 ( V_41 ) ;
if ( V_41 == NULL )
return NULL ;
F_14 ( & V_41 -> V_42 ) ;
F_14 ( & V_41 -> V_43 ) ;
F_14 ( & V_41 -> V_44 ) ;
F_14 ( & V_41 -> V_45 ) ;
V_41 -> V_46 = V_37 ;
V_41 -> V_47 = V_38 ;
V_41 -> V_48 = V_39 ;
V_41 -> V_49 = V_40 ;
return V_41 ;
}
static void F_15 ( struct V_36 * V_41 )
{
if ( ! F_16 ( & V_41 -> V_42 ) )
F_17 ( & V_41 -> V_42 ) ;
if ( ! F_16 ( & V_41 -> V_43 ) )
F_17 ( & V_41 -> V_43 ) ;
if ( ! F_16 ( & V_41 -> V_44 ) )
F_17 ( & V_41 -> V_44 ) ;
if ( ! F_16 ( & V_41 -> V_45 ) )
F_17 ( & V_41 -> V_45 ) ;
F_18 ( V_41 ) ;
}
static
struct V_36 * F_19 ( struct V_50 * V_51 ,
T_3 V_37 , T_3 V_38 ,
T_1 V_39 , T_1 V_40 )
{
struct V_52 * V_53 ;
struct V_36 * V_41 ;
V_53 = & V_51 -> V_54 [ V_55 ] [ F_11 ( V_37 ) ] ;
F_20 (e, head, lie_rmt_uid_hash)
if ( V_41 -> V_46 == V_37 ) {
if ( V_41 -> V_47 == V_38 ) {
if ( V_41 -> V_48 == V_39 &&
V_41 -> V_49 == V_40 )
return V_41 ;
} else {
F_21 ( L_1
L_2 , V_41 -> V_46 ,
V_41 -> V_47 , V_38 ) ;
return F_22 ( - V_56 ) ;
}
}
V_53 = & V_51 -> V_54 [ V_57 ] [ F_11 ( V_39 ) ] ;
F_20 (e, head, lie_rmt_gid_hash)
if ( V_41 -> V_48 == V_39 ) {
if ( V_41 -> V_49 == V_40 ) {
if ( F_23 ( V_41 -> V_46 == V_37 &&
V_41 -> V_47 == V_38 ) )
F_24 () ;
} else {
F_21 ( L_3
L_2 , V_41 -> V_48 ,
V_41 -> V_49 , V_40 ) ;
return F_22 ( - V_56 ) ;
}
}
return NULL ;
}
static T_2 F_25 ( struct V_52 * V_58 , int V_59 ,
T_2 V_60 )
{
struct V_52 * V_53 = & V_58 [ F_11 ( V_60 ) ] ;
struct V_36 * V_41 ;
if ( ! V_59 ) {
F_20 (e, head, lie_rmt_uid_hash)
if ( V_41 -> V_46 == V_60 )
return V_41 -> V_47 ;
} else {
F_20 (e, head, lie_lcl_uid_hash)
if ( V_41 -> V_47 == V_60 )
return V_41 -> V_46 ;
}
return V_61 ;
}
static T_2 F_26 ( struct V_52 * V_58 , int V_59 , T_2 V_62 )
{
struct V_52 * V_53 = & V_58 [ F_11 ( V_62 ) ] ;
struct V_36 * V_41 ;
if ( ! V_59 ) {
F_20 (e, head, lie_rmt_gid_hash)
if ( V_41 -> V_48 == V_62 )
return V_41 -> V_49 ;
} else {
F_20 (e, head, lie_lcl_gid_hash)
if ( V_41 -> V_49 == V_62 )
return V_41 -> V_48 ;
}
return V_61 ;
}
int F_27 ( struct V_50 * V_51 ,
T_3 V_63 , T_3 V_64 ,
T_1 V_65 , T_1 V_66 )
{
struct V_36 * V_67 , * V_68 ;
F_28 ( V_51 ) ;
F_29 ( & V_51 -> V_69 ) ;
V_67 = F_19 ( V_51 , V_63 , V_64 , V_65 , V_66 ) ;
F_30 ( & V_51 -> V_69 ) ;
if ( ! V_67 ) {
V_67 = F_12 ( V_63 , V_64 , V_65 , V_66 ) ;
if ( ! V_67 )
return - V_70 ;
F_29 ( & V_51 -> V_69 ) ;
V_68 = F_19 ( V_51 , V_63 , V_64 , V_65 , V_66 ) ;
if ( V_68 == NULL ) {
F_31 ( & V_67 -> V_42 ,
& V_51 -> V_54 [ V_55 ]
[ F_11 ( V_63 ) ] ) ;
F_31 ( & V_67 -> V_43 ,
& V_51 -> V_54 [ V_71 ]
[ F_11 ( V_64 ) ] ) ;
F_31 ( & V_67 -> V_44 ,
& V_51 -> V_54 [ V_57 ]
[ F_11 ( V_65 ) ] ) ;
F_31 ( & V_67 -> V_45 ,
& V_51 -> V_54 [ V_72 ]
[ F_11 ( V_66 ) ] ) ;
}
F_30 ( & V_51 -> V_69 ) ;
if ( V_68 != NULL ) {
F_15 ( V_67 ) ;
if ( F_32 ( V_68 ) )
return F_33 ( V_68 ) ;
}
} else if ( F_32 ( V_67 ) ) {
return F_33 ( V_67 ) ;
}
return 0 ;
}
int F_34 ( struct V_50 * V_51 ,
T_3 V_63 , T_3 V_64 ,
T_1 V_65 , T_1 V_66 )
{
struct V_36 * V_41 ;
int V_26 = 0 ;
F_28 ( V_51 ) ;
F_29 ( & V_51 -> V_69 ) ;
V_41 = F_19 ( V_51 , V_63 , V_64 , V_65 , V_66 ) ;
if ( F_32 ( V_41 ) )
V_26 = F_33 ( V_41 ) ;
else if ( V_41 )
F_15 ( V_41 ) ;
F_30 ( & V_51 -> V_69 ) ;
return V_26 ;
}
int F_35 ( struct V_24 * V_25 ,
struct V_50 * V_51 ,
int V_59 , T_3 V_60 )
{
struct V_52 * V_58 ;
if ( V_25 && ( V_25 -> V_30 == V_31 || V_25 -> V_30 == V_73 ) ) {
if ( ! V_59 ) {
if ( V_60 == V_25 -> V_74 )
return V_25 -> V_75 ;
else if ( V_60 == V_25 -> V_76 )
return V_25 -> V_77 ;
} else {
if ( V_60 == V_25 -> V_75 )
return V_25 -> V_74 ;
else if ( V_60 == V_25 -> V_77 )
return V_25 -> V_76 ;
}
}
if ( V_51 == NULL )
return V_61 ;
V_58 = V_51 -> V_54 [ V_59 ? V_71 : V_55 ] ;
F_29 ( & V_51 -> V_69 ) ;
V_60 = F_25 ( V_58 , V_59 , V_60 ) ;
F_30 ( & V_51 -> V_69 ) ;
return V_60 ;
}
int F_36 ( struct V_24 * V_25 , struct V_50 * V_51 ,
int V_59 , T_1 V_62 )
{
struct V_52 * V_58 ;
if ( V_25 && ( V_25 -> V_30 == V_31 || V_25 -> V_30 == V_73 ) ) {
if ( ! V_59 ) {
if ( V_62 == V_25 -> V_78 )
return V_25 -> V_79 ;
else if ( V_62 == V_25 -> V_80 )
return V_25 -> V_27 ;
} else {
if ( V_62 == V_25 -> V_79 )
return V_25 -> V_78 ;
else if ( V_62 == V_25 -> V_27 )
return V_25 -> V_80 ;
}
}
if ( V_51 == NULL )
return V_61 ;
V_58 = V_51 -> V_54 [ V_59 ? V_72 : V_57 ] ;
F_29 ( & V_51 -> V_69 ) ;
V_62 = F_26 ( V_58 , V_59 , V_62 ) ;
F_30 ( & V_51 -> V_69 ) ;
return V_62 ;
}
struct V_50 * F_37 ( void )
{
struct V_50 * V_51 ;
int V_11 , V_81 ;
F_13 ( V_51 ) ;
if( F_23 ( V_51 == NULL ) )
return ( F_22 ( - V_70 ) ) ;
F_38 ( & V_51 -> V_69 ) ;
for ( V_11 = 0 ; V_11 < F_39 ( V_51 -> V_54 ) ; V_11 ++ )
for ( V_81 = 0 ; V_81 < F_39 ( V_51 -> V_54 [ V_11 ] ) ; V_81 ++ )
F_14 ( & V_51 -> V_54 [ V_11 ] [ V_81 ] ) ;
return V_51 ;
}
void F_40 ( struct V_50 * V_51 )
{
struct V_52 * V_82 ;
struct V_36 * V_41 ;
int V_11 ;
F_28 ( V_51 ) ;
V_82 = V_51 -> V_54 [ V_55 ] ;
F_29 ( & V_51 -> V_69 ) ;
for ( V_11 = 0 ; V_11 < V_35 ; V_11 ++ )
while ( ! F_16 ( & V_82 [ V_11 ] ) ) {
V_41 = F_41 ( V_82 [ V_11 ] . V_83 ,
struct V_36 ,
V_42 ) ;
F_15 ( V_41 ) ;
}
F_30 ( & V_51 -> V_69 ) ;
F_18 ( V_51 ) ;
}
