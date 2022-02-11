static void F_1 ( struct V_1 * V_2 , T_1 * V_3 )
{
T_2 V_4 ;
V_4 = F_2 ( V_2 , V_5 ) ;
* V_3 = ( T_1 ) ( V_4 & V_6 >>
V_7 ) ;
}
static int F_3 ( struct V_8 * V_9 ,
struct V_10 * V_11 )
{
struct V_12 * V_13 = F_4 ( V_9 ) ;
struct V_14 * V_15 ;
struct V_1 * V_2 = & V_13 -> V_2 ;
if ( ! ( V_13 -> V_16 & V_17 ) )
return - V_18 ;
V_15 = & V_2 -> V_19 ;
V_11 -> V_20 = V_15 -> V_21 . V_20 ;
V_11 -> V_22 = V_15 -> V_21 . V_23 ;
V_11 -> V_24 = V_15 -> V_21 . V_24 ;
memcpy ( V_11 -> V_25 , V_15 -> V_21 . V_26 ,
sizeof( V_11 -> V_25 ) ) ;
memcpy ( V_11 -> V_27 , V_15 -> V_21 . V_26 ,
sizeof( V_11 -> V_27 ) ) ;
memcpy ( V_11 -> V_28 , V_15 -> V_21 . V_29 ,
sizeof( V_11 -> V_28 ) ) ;
memcpy ( V_11 -> V_30 , V_15 -> V_21 . V_31 ,
sizeof( V_11 -> V_30 ) ) ;
memcpy ( V_11 -> V_32 , V_15 -> V_33 . V_26 ,
sizeof( V_11 -> V_32 ) ) ;
memcpy ( V_11 -> V_34 , V_15 -> V_33 . V_29 ,
sizeof( V_11 -> V_34 ) ) ;
memcpy ( V_11 -> V_35 , V_15 -> V_21 . V_31 ,
sizeof( V_11 -> V_35 ) ) ;
return 0 ;
}
static int F_5 ( struct V_8 * V_9 ,
struct V_36 * V_37 )
{
struct V_12 * V_13 = F_4 ( V_9 ) ;
struct V_14 * V_15 ;
struct V_1 * V_2 = & V_13 -> V_2 ;
int V_38 ;
if ( ! ( V_13 -> V_16 & V_17 ) )
return - V_18 ;
V_15 = & V_2 -> V_19 ;
V_37 -> V_39 = V_15 -> V_37 . V_40 ;
V_37 -> V_41 = V_15 -> V_37 . V_42 ;
V_37 -> V_43 = V_15 -> V_37 . V_43 ;
F_1 ( V_2 , & V_37 -> V_3 ) ;
for ( V_38 = 0 ; V_38 < V_44 ; V_38 ++ ) {
V_37 -> V_45 [ V_38 ] = V_13 -> V_46 . V_47 [ V_38 ] ;
V_37 -> V_48 [ V_38 ] = V_13 -> V_46 . V_49 [ V_38 ] ;
}
return 0 ;
}
static T_3 F_6 ( struct V_8 * V_9 )
{
struct V_12 * V_13 = F_4 ( V_9 ) ;
return V_13 -> V_16 ;
}
static void F_7 ( struct V_8 * V_9 ,
T_3 * V_50 )
{
struct V_12 * V_13 = F_4 ( V_9 ) ;
int V_38 , V_51 ;
memset ( V_50 , 0xff , V_52 ) ;
for ( V_38 = 0 ; V_38 < V_9 -> V_53 ; V_38 ++ )
V_50 [ V_38 ] = V_13 -> V_2 . V_54 . V_50 [ V_38 ] ;
for ( V_51 = 0 ; V_51 < V_9 -> V_53 ; V_51 ++ , V_38 ++ )
V_50 [ V_38 ] = V_13 -> V_2 . V_54 . V_55 [ V_51 ] ;
}
void F_8 ( struct V_56 * V_57 )
{
struct V_8 * V_9 = V_57 -> V_58 ;
struct V_12 * V_13 = F_4 ( V_9 ) ;
struct V_14 * V_15 ;
struct V_1 * V_2 = & V_13 -> V_2 ;
struct V_59 V_60 ;
T_3 V_61 , V_62 ;
int V_38 ;
if ( ! ( V_13 -> V_63 & V_64 ) )
return;
V_15 = & V_2 -> V_19 ;
for ( V_38 = 0 ; V_38 < V_15 -> V_65 ; V_38 ++ ) {
V_61 = V_15 -> V_66 [ V_38 ] . V_67 ;
V_62 = ( 1 << V_15 -> V_21 . V_31 [ V_61 ] ) ;
if ( V_62 & V_57 -> V_68 . V_69 ) {
V_60 . V_70 = V_15 -> V_66 [ V_38 ] . V_70 ;
V_60 . V_71 = V_15 -> V_66 [ V_38 ] . V_72 ;
V_60 . V_67 = V_61 ;
F_9 ( V_9 , & V_60 ) ;
}
}
F_10 ( V_9 , V_73 , V_74 , 0 , 0 ) ;
}
static int F_11 ( struct V_56 * V_57 ,
struct V_75 * V_66 )
{
struct V_8 * V_9 = V_57 -> V_58 ;
struct V_59 V_60 ;
if ( ! V_9 )
return - V_18 ;
V_60 . V_70 = V_66 -> V_70 ;
V_60 . V_71 = V_66 -> V_72 ;
V_60 . V_67 = V_66 -> V_67 ;
return F_12 ( V_9 , & V_60 ) ;
}
static void F_13 ( struct V_12 * V_13 ,
struct V_75 * V_66 )
{
int V_76 , V_77 ;
for ( V_76 = 0 ; V_76 < V_13 -> V_78 ; V_76 ++ ) {
if ( V_13 -> V_57 [ V_76 ] && V_13 -> V_57 [ V_76 ] -> V_58 ) {
V_77 = F_11 ( V_13 -> V_57 [ V_76 ] , V_66 ) ;
if ( V_77 )
F_14 ( & V_13 -> V_79 -> V_9 , L_1 ,
V_80 , V_13 -> V_57 [ V_76 ] -> V_81 ,
V_77 , V_66 -> V_70 ,
V_66 -> V_72 , V_66 -> V_67 ) ;
}
}
}
static bool F_15 ( struct V_14 * V_82 ,
struct V_75 * V_66 )
{
int V_38 ;
for ( V_38 = 0 ; V_38 < V_82 -> V_65 ; V_38 ++ ) {
if ( V_66 -> V_70 == V_82 -> V_66 [ V_38 ] . V_70 &&
V_66 -> V_72 == V_82 -> V_66 [ V_38 ] . V_72 &&
V_66 -> V_67 == V_82 -> V_66 [ V_38 ] . V_67 )
return true ;
}
return false ;
}
void F_16 ( struct V_12 * V_13 ,
struct V_14 * V_83 )
{
struct V_75 V_66 ;
struct V_14 * V_15 ;
struct V_1 * V_2 = & V_13 -> V_2 ;
int V_38 ;
V_15 = & V_2 -> V_19 ;
for ( V_38 = 0 ; V_38 < V_15 -> V_65 ; V_38 ++ ) {
V_66 = V_15 -> V_66 [ V_38 ] ;
if ( ! F_15 ( V_83 , & V_66 ) )
F_13 ( V_13 , & V_66 ) ;
}
}
void F_17 ( struct V_56 * V_57 )
{
struct V_8 * V_9 = V_57 -> V_58 ;
struct V_12 * V_13 = F_4 ( V_9 ) ;
if ( ! ( V_13 -> V_63 & V_84 ) )
return;
if ( ! ( V_13 -> V_63 & V_85 ) )
V_9 -> V_86 = & V_86 ;
F_8 ( V_57 ) ;
}
