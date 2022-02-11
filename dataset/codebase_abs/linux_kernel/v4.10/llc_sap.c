static int F_1 ( unsigned short V_1 )
{
switch ( V_1 ) {
case V_2 :
case V_3 :
return sizeof( struct V_4 ) ;
}
return 0 ;
}
struct V_5 * F_2 ( struct V_6 * V_7 , struct V_8 * V_9 ,
T_1 type , T_2 V_10 )
{
int V_11 = type == V_12 ? 3 : 4 ;
struct V_5 * V_13 ;
V_11 += F_1 ( V_9 -> type ) ;
V_13 = F_3 ( V_11 + V_10 , V_14 ) ;
if ( V_13 ) {
F_4 ( V_13 ) ;
F_5 ( V_13 , V_11 ) ;
F_6 ( V_13 ) ;
F_7 ( V_13 ) ;
V_13 -> V_15 = F_8 ( V_16 ) ;
V_13 -> V_9 = V_9 ;
if ( V_7 != NULL )
F_9 ( V_13 , V_7 ) ;
}
return V_13 ;
}
void F_10 ( struct V_6 * V_7 , struct V_5 * V_13 , T_1 V_17 )
{
struct V_18 * V_19 ;
V_19 = F_11 ( V_13 ) ;
memset ( V_19 , 0 , sizeof( * V_19 ) ) ;
V_19 -> V_20 = V_7 -> V_21 ;
V_19 -> V_22 = V_13 -> V_9 -> type ;
V_19 -> V_23 = V_17 == V_24 ;
V_19 -> V_25 = V_17 == V_26 ;
V_19 -> V_27 = V_17 == V_28 ;
F_12 ( V_13 , V_19 -> V_29 ) ;
F_13 ( V_13 , & V_19 -> V_30 ) ;
}
void F_14 ( struct V_31 * V_32 , struct V_5 * V_13 )
{
struct V_33 * V_34 = F_15 ( V_13 ) ;
struct V_35 * V_36 = F_16 ( V_13 ) ;
switch ( F_17 ( V_36 ) ) {
case V_37 :
V_34 -> V_17 = V_24 ; break;
case V_38 :
V_34 -> V_17 = V_26 ; break;
case V_39 :
V_34 -> V_17 = V_28 ; break;
}
V_34 -> V_40 = V_41 ;
}
static struct V_42 * F_18 ( struct V_31 * V_32 ,
struct V_5 * V_13 )
{
int V_43 = 0 ;
struct V_42 * V_44 = NULL ;
struct V_42 * * V_45 ;
struct V_46 * V_47 = & V_48 [ V_32 -> V_49 - 1 ] ;
for ( V_45 = V_47 -> V_50 ; V_45 [ V_43 ] -> V_34 ; V_43 ++ )
if ( ! V_45 [ V_43 ] -> V_34 ( V_32 , V_13 ) ) {
V_44 = V_45 [ V_43 ] ;
break;
}
return V_44 ;
}
static int F_19 ( struct V_31 * V_32 ,
struct V_42 * V_51 ,
struct V_5 * V_13 )
{
int V_44 = 0 ;
const T_3 * V_52 = V_51 -> V_53 ;
for (; V_52 && * V_52 ; V_52 ++ )
if ( (* V_52)( V_32 , V_13 ) )
V_44 = 1 ;
return V_44 ;
}
static int F_20 ( struct V_31 * V_32 , struct V_5 * V_13 )
{
int V_44 = 1 ;
struct V_42 * V_51 ;
if ( V_32 -> V_49 > V_54 )
goto V_55;
V_51 = F_18 ( V_32 , V_13 ) ;
if ( ! V_51 )
goto V_55;
V_44 = F_19 ( V_32 , V_51 , V_13 ) ;
if ( V_44 )
goto V_55;
V_32 -> V_49 = V_51 -> V_56 ;
V_55:
return V_44 ;
}
static void F_21 ( struct V_31 * V_32 , struct V_5 * V_13 )
{
struct V_33 * V_34 = F_15 ( V_13 ) ;
F_22 ( V_13 ) ;
V_34 -> V_40 = 0 ;
F_20 ( V_32 , V_13 ) ;
if ( V_34 -> V_40 == V_41 ) {
if ( V_13 -> V_7 -> V_57 == V_58 )
F_23 ( V_13 ) ;
else {
F_10 ( V_13 -> V_7 , V_13 , V_34 -> V_17 ) ;
if ( F_24 ( V_13 -> V_7 , V_13 ) )
F_23 ( V_13 ) ;
}
}
F_23 ( V_13 ) ;
}
void F_25 ( struct V_31 * V_32 ,
struct V_5 * V_13 , T_1 * V_59 , T_1 V_60 )
{
struct V_33 * V_34 = F_15 ( V_13 ) ;
V_34 -> V_61 . V_62 = V_32 -> V_63 . V_62 ;
V_34 -> V_64 . V_62 = V_60 ;
memcpy ( V_34 -> V_61 . V_65 , V_13 -> V_9 -> V_66 , V_67 ) ;
memcpy ( V_34 -> V_64 . V_65 , V_59 , V_67 ) ;
V_34 -> type = V_68 ;
V_34 -> V_17 = V_24 ;
V_34 -> V_69 = V_70 ;
F_21 ( V_32 , V_13 ) ;
}
void F_26 ( struct V_31 * V_32 , struct V_5 * V_13 ,
T_1 * V_59 , T_1 V_60 )
{
struct V_33 * V_34 = F_15 ( V_13 ) ;
V_34 -> V_61 . V_62 = V_32 -> V_63 . V_62 ;
V_34 -> V_64 . V_62 = V_60 ;
memcpy ( V_34 -> V_61 . V_65 , V_13 -> V_9 -> V_66 , V_67 ) ;
memcpy ( V_34 -> V_64 . V_65 , V_59 , V_67 ) ;
V_34 -> type = V_68 ;
V_34 -> V_17 = V_26 ;
V_34 -> V_69 = V_70 ;
F_21 ( V_32 , V_13 ) ;
}
static void F_27 ( struct V_31 * V_32 , struct V_5 * V_13 ,
struct V_6 * V_7 )
{
struct V_33 * V_34 = F_15 ( V_13 ) ;
V_34 -> type = V_71 ;
V_34 -> V_72 = 0 ;
F_28 ( V_13 ) ;
F_29 ( V_7 ) ;
V_13 -> V_7 = V_7 ;
V_13 -> V_73 = V_74 ;
F_21 ( V_32 , V_13 ) ;
}
static inline bool F_30 ( const struct V_31 * V_32 ,
const struct V_75 * V_63 ,
const struct V_6 * V_7 )
{
struct V_76 * V_77 = F_31 ( V_7 ) ;
return V_7 -> V_78 == V_79 &&
V_77 -> V_63 . V_62 == V_63 -> V_62 &&
F_32 ( V_77 -> V_63 . V_65 , V_63 -> V_65 ) ;
}
static struct V_6 * F_33 ( struct V_31 * V_32 ,
const struct V_75 * V_63 )
{
struct V_6 * V_44 ;
struct V_80 * V_81 ;
int V_82 = F_34 ( V_32 , V_63 ) ;
struct V_83 * V_84 = & V_32 -> V_85 [ V_82 ] ;
F_35 () ;
V_86:
F_36 (rc, node, laddr_hb) {
if ( F_30 ( V_32 , V_63 , V_44 ) ) {
if ( F_37 ( ! F_38 ( & V_44 -> V_87 ) ) )
goto V_86;
if ( F_37 ( F_31 ( V_44 ) -> V_32 != V_32 ||
! F_30 ( V_32 , V_63 , V_44 ) ) ) {
F_39 ( V_44 ) ;
continue;
}
goto V_88;
}
}
V_44 = NULL ;
if ( F_37 ( F_40 ( V_81 ) != V_82 ) )
goto V_86;
V_88:
F_41 () ;
return V_44 ;
}
static inline bool F_42 ( const struct V_31 * V_32 ,
const struct V_75 * V_63 ,
const struct V_5 * V_13 ,
const struct V_6 * V_7 )
{
struct V_76 * V_77 = F_31 ( V_7 ) ;
return V_7 -> V_78 == V_79 &&
V_77 -> V_63 . V_62 == V_63 -> V_62 &&
V_77 -> V_9 == V_13 -> V_9 ;
}
static void F_43 ( struct V_31 * V_32 , struct V_5 * V_13 ,
struct V_6 * * V_89 , int V_90 )
{
struct V_5 * V_91 ;
int V_43 ;
for ( V_43 = 0 ; V_43 < V_90 ; V_43 ++ ) {
V_91 = F_44 ( V_13 , V_14 ) ;
if ( ! V_91 ) {
F_39 ( V_89 [ V_43 ] ) ;
continue;
}
F_27 ( V_32 , V_91 , V_89 [ V_43 ] ) ;
F_39 ( V_89 [ V_43 ] ) ;
}
}
static void F_45 ( struct V_31 * V_32 ,
const struct V_75 * V_63 ,
struct V_5 * V_13 )
{
int V_43 = 0 , V_90 = 256 / sizeof( struct V_6 * ) ;
struct V_6 * V_7 , * V_89 [ V_90 ] ;
struct V_76 * V_77 ;
struct V_92 * V_93 = F_46 ( V_32 , V_13 -> V_9 -> V_94 ) ;
F_47 ( & V_32 -> V_95 ) ;
F_48 (llc, dev_hb, dev_hash_node) {
V_7 = & V_77 -> V_7 ;
if ( ! F_42 ( V_32 , V_63 , V_13 , V_7 ) )
continue;
F_29 ( V_7 ) ;
if ( V_43 < V_90 )
V_89 [ V_43 ++ ] = V_7 ;
else {
F_43 ( V_32 , V_13 , V_89 , V_43 ) ;
V_43 = 0 ;
}
}
F_49 ( & V_32 -> V_95 ) ;
F_43 ( V_32 , V_13 , V_89 , V_43 ) ;
}
void F_50 ( struct V_31 * V_32 , struct V_5 * V_13 )
{
struct V_75 V_63 ;
F_51 ( V_13 , V_63 . V_65 ) ;
F_52 ( V_13 , & V_63 . V_62 ) ;
if ( F_53 ( V_63 . V_65 ) ) {
F_45 ( V_32 , & V_63 , V_13 ) ;
F_23 ( V_13 ) ;
} else {
struct V_6 * V_7 = F_33 ( V_32 , & V_63 ) ;
if ( V_7 ) {
F_27 ( V_32 , V_13 , V_7 ) ;
F_39 ( V_7 ) ;
} else
F_23 ( V_13 ) ;
}
}
