static int F_1 ( unsigned short V_1 )
{
switch ( V_1 ) {
case V_2 :
case V_3 :
return sizeof( struct V_4 ) ;
#if F_2 ( V_5 ) || F_2 ( V_6 )
case V_7 :
return sizeof( struct V_8 ) ;
#endif
}
return 0 ;
}
struct V_9 * F_3 ( struct V_10 * V_11 , struct V_12 * V_13 ,
T_1 type , T_2 V_14 )
{
int V_15 = type == V_16 ? 3 : 4 ;
struct V_9 * V_17 ;
V_15 += F_1 ( V_13 -> type ) ;
V_17 = F_4 ( V_15 + V_14 , V_18 ) ;
if ( V_17 ) {
F_5 ( V_17 ) ;
F_6 ( V_17 , V_15 ) ;
F_7 ( V_17 ) ;
F_8 ( V_17 ) ;
V_17 -> V_19 = F_9 ( V_20 ) ;
V_17 -> V_13 = V_13 ;
if ( V_11 != NULL )
F_10 ( V_17 , V_11 ) ;
}
return V_17 ;
}
void F_11 ( struct V_10 * V_11 , struct V_9 * V_17 , T_1 V_21 )
{
struct V_22 * V_23 ;
V_23 = F_12 ( V_17 ) ;
memset ( V_23 , 0 , sizeof( * V_23 ) ) ;
V_23 -> V_24 = V_11 -> V_25 ;
V_23 -> V_26 = V_17 -> V_13 -> type ;
V_23 -> V_27 = V_21 == V_28 ;
V_23 -> V_29 = V_21 == V_30 ;
V_23 -> V_31 = V_21 == V_32 ;
F_13 ( V_17 , V_23 -> V_33 ) ;
F_14 ( V_17 , & V_23 -> V_34 ) ;
}
void F_15 ( struct V_35 * V_36 , struct V_9 * V_17 )
{
struct V_37 * V_38 = F_16 ( V_17 ) ;
struct V_39 * V_40 = F_17 ( V_17 ) ;
switch ( F_18 ( V_40 ) ) {
case V_41 :
V_38 -> V_21 = V_28 ; break;
case V_42 :
V_38 -> V_21 = V_30 ; break;
case V_43 :
V_38 -> V_21 = V_32 ; break;
}
V_38 -> V_44 = V_45 ;
}
static struct V_46 * F_19 ( struct V_35 * V_36 ,
struct V_9 * V_17 )
{
int V_47 = 0 ;
struct V_46 * V_48 = NULL ;
struct V_46 * * V_49 ;
struct V_50 * V_51 = & V_52 [ V_36 -> V_53 - 1 ] ;
for ( V_49 = V_51 -> V_54 ; V_49 [ V_47 ] -> V_38 ; V_47 ++ )
if ( ! V_49 [ V_47 ] -> V_38 ( V_36 , V_17 ) ) {
V_48 = V_49 [ V_47 ] ;
break;
}
return V_48 ;
}
static int F_20 ( struct V_35 * V_36 ,
struct V_46 * V_55 ,
struct V_9 * V_17 )
{
int V_48 = 0 ;
T_3 * V_56 = V_55 -> V_57 ;
for (; V_56 && * V_56 ; V_56 ++ )
if ( (* V_56)( V_36 , V_17 ) )
V_48 = 1 ;
return V_48 ;
}
static int F_21 ( struct V_35 * V_36 , struct V_9 * V_17 )
{
int V_48 = 1 ;
struct V_46 * V_55 ;
if ( V_36 -> V_53 > V_58 )
goto V_59;
V_55 = F_19 ( V_36 , V_17 ) ;
if ( ! V_55 )
goto V_59;
V_48 = F_20 ( V_36 , V_55 , V_17 ) ;
if ( V_48 )
goto V_59;
V_36 -> V_53 = V_55 -> V_60 ;
V_59:
return V_48 ;
}
static void F_22 ( struct V_35 * V_36 , struct V_9 * V_17 )
{
struct V_37 * V_38 = F_16 ( V_17 ) ;
F_23 ( V_17 ) ;
V_38 -> V_44 = 0 ;
F_21 ( V_36 , V_17 ) ;
if ( V_38 -> V_44 == V_45 ) {
if ( V_17 -> V_11 -> V_61 == V_62 )
F_24 ( V_17 ) ;
else {
F_11 ( V_17 -> V_11 , V_17 , V_38 -> V_21 ) ;
if ( F_25 ( V_17 -> V_11 , V_17 ) )
F_24 ( V_17 ) ;
}
}
F_24 ( V_17 ) ;
}
void F_26 ( struct V_35 * V_36 ,
struct V_9 * V_17 , T_1 * V_63 , T_1 V_64 )
{
struct V_37 * V_38 = F_16 ( V_17 ) ;
V_38 -> V_65 . V_66 = V_36 -> V_67 . V_66 ;
V_38 -> V_68 . V_66 = V_64 ;
memcpy ( V_38 -> V_65 . V_69 , V_17 -> V_13 -> V_70 , V_71 ) ;
memcpy ( V_38 -> V_68 . V_69 , V_63 , V_71 ) ;
V_38 -> type = V_72 ;
V_38 -> V_21 = V_28 ;
V_38 -> V_73 = V_74 ;
F_22 ( V_36 , V_17 ) ;
}
void F_27 ( struct V_35 * V_36 , struct V_9 * V_17 ,
T_1 * V_63 , T_1 V_64 )
{
struct V_37 * V_38 = F_16 ( V_17 ) ;
V_38 -> V_65 . V_66 = V_36 -> V_67 . V_66 ;
V_38 -> V_68 . V_66 = V_64 ;
memcpy ( V_38 -> V_65 . V_69 , V_17 -> V_13 -> V_70 , V_71 ) ;
memcpy ( V_38 -> V_68 . V_69 , V_63 , V_71 ) ;
V_38 -> type = V_72 ;
V_38 -> V_21 = V_30 ;
V_38 -> V_73 = V_74 ;
F_22 ( V_36 , V_17 ) ;
}
static void F_28 ( struct V_35 * V_36 , struct V_9 * V_17 ,
struct V_10 * V_11 )
{
struct V_37 * V_38 = F_16 ( V_17 ) ;
V_38 -> type = V_75 ;
V_38 -> V_76 = 0 ;
V_17 -> V_11 = V_11 ;
F_22 ( V_36 , V_17 ) ;
}
static inline bool F_29 ( const struct V_35 * V_36 ,
const struct V_77 * V_67 ,
const struct V_10 * V_11 )
{
struct V_78 * V_79 = F_30 ( V_11 ) ;
return V_11 -> V_80 == V_81 &&
V_79 -> V_67 . V_66 == V_67 -> V_66 &&
F_31 ( V_79 -> V_67 . V_69 , V_67 -> V_69 ) ;
}
static struct V_10 * F_32 ( struct V_35 * V_36 ,
const struct V_77 * V_67 )
{
struct V_10 * V_48 ;
struct V_82 * V_83 ;
int V_84 = F_33 ( V_36 , V_67 ) ;
struct V_85 * V_86 = & V_36 -> V_87 [ V_84 ] ;
F_34 () ;
V_88:
F_35 (rc, node, laddr_hb) {
if ( F_29 ( V_36 , V_67 , V_48 ) ) {
if ( F_36 ( ! F_37 ( & V_48 -> V_89 ) ) )
goto V_88;
if ( F_36 ( F_30 ( V_48 ) -> V_36 != V_36 ||
! F_29 ( V_36 , V_67 , V_48 ) ) ) {
F_38 ( V_48 ) ;
continue;
}
goto V_90;
}
}
V_48 = NULL ;
if ( F_36 ( F_39 ( V_83 ) != V_84 ) )
goto V_88;
V_90:
F_40 () ;
return V_48 ;
}
static inline bool F_41 ( const struct V_35 * V_36 ,
const struct V_77 * V_67 ,
const struct V_9 * V_17 ,
const struct V_10 * V_11 )
{
struct V_78 * V_79 = F_30 ( V_11 ) ;
return V_11 -> V_80 == V_81 &&
V_79 -> V_67 . V_66 == V_67 -> V_66 &&
V_79 -> V_13 == V_17 -> V_13 ;
}
static void F_42 ( struct V_35 * V_36 , struct V_9 * V_17 ,
struct V_10 * * V_91 , int V_92 )
{
struct V_9 * V_93 ;
int V_47 ;
for ( V_47 = 0 ; V_47 < V_92 ; V_47 ++ ) {
V_93 = F_43 ( V_17 , V_18 ) ;
if ( ! V_93 ) {
F_38 ( V_91 [ V_47 ] ) ;
continue;
}
F_28 ( V_36 , V_93 , V_91 [ V_47 ] ) ;
F_38 ( V_91 [ V_47 ] ) ;
}
}
static void F_44 ( struct V_35 * V_36 ,
const struct V_77 * V_67 ,
struct V_9 * V_17 )
{
int V_47 = 0 , V_92 = 256 / sizeof( struct V_10 * ) ;
struct V_10 * V_11 , * V_91 [ V_92 ] ;
struct V_94 * V_83 ;
struct V_78 * V_79 ;
struct V_95 * V_96 = F_45 ( V_36 , V_17 -> V_13 -> V_97 ) ;
F_46 ( & V_36 -> V_98 ) ;
F_47 (llc, node, dev_hb, dev_hash_node) {
V_11 = & V_79 -> V_11 ;
if ( ! F_41 ( V_36 , V_67 , V_17 , V_11 ) )
continue;
F_48 ( V_11 ) ;
if ( V_47 < V_92 )
V_91 [ V_47 ++ ] = V_11 ;
else {
F_42 ( V_36 , V_17 , V_91 , V_47 ) ;
V_47 = 0 ;
}
}
F_49 ( & V_36 -> V_98 ) ;
F_42 ( V_36 , V_17 , V_91 , V_47 ) ;
}
void F_50 ( struct V_35 * V_36 , struct V_9 * V_17 )
{
struct V_77 V_67 ;
F_51 ( V_17 , V_67 . V_69 ) ;
F_52 ( V_17 , & V_67 . V_66 ) ;
if ( F_53 ( V_67 . V_69 ) ) {
F_44 ( V_36 , & V_67 , V_17 ) ;
F_24 ( V_17 ) ;
} else {
struct V_10 * V_11 = F_32 ( V_36 , & V_67 ) ;
if ( V_11 ) {
F_28 ( V_36 , V_17 , V_11 ) ;
F_38 ( V_11 ) ;
} else
F_24 ( V_17 ) ;
}
}
