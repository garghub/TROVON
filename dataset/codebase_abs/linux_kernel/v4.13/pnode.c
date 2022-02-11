static inline struct V_1 * F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_2 -> V_3 . V_4 , struct V_1 , V_3 ) ;
}
static inline struct V_1 * F_3 ( struct V_1 * V_2 )
{
return F_2 ( V_2 -> V_5 . V_4 , struct V_1 , V_6 ) ;
}
static inline struct V_1 * F_4 ( struct V_1 * V_2 )
{
return F_2 ( V_2 -> V_5 . V_7 , struct V_1 , V_6 ) ;
}
static inline struct V_1 * F_5 ( struct V_1 * V_2 )
{
return F_2 ( V_2 -> V_6 . V_4 , struct V_1 , V_6 ) ;
}
static struct V_1 * F_6 ( struct V_1 * V_8 ,
struct V_9 * V_10 ,
const struct V_11 * V_12 )
{
struct V_1 * V_13 = V_8 ;
do {
if ( V_13 -> V_14 == V_10 && F_7 ( V_13 , V_13 -> V_8 . V_15 , V_12 ) )
return V_13 ;
V_13 = F_1 ( V_13 ) ;
} while ( V_13 != V_8 );
return NULL ;
}
int F_8 ( struct V_1 * V_8 , const struct V_11 * V_12 )
{
struct V_1 * V_13 ;
for ( V_13 = V_8 -> V_16 ; V_13 != NULL ; V_13 = V_13 -> V_16 ) {
struct V_1 * V_17 = F_6 ( V_13 , V_8 -> V_14 , V_12 ) ;
if ( V_17 )
return V_17 -> V_18 ;
}
return 0 ;
}
static int F_9 ( struct V_1 * V_8 )
{
struct V_1 * V_19 , * V_20 ;
if ( F_10 ( & V_8 -> V_3 ) ) {
if ( F_11 ( V_8 ) ) {
F_12 ( V_8 ) ;
F_13 ( V_8 ) ;
}
V_19 = V_8 -> V_16 ;
if ( ! V_19 ) {
struct V_21 * V_2 = & V_8 -> V_5 ;
while ( ! F_10 ( V_2 ) ) {
V_20 = F_14 ( V_2 ,
struct V_1 , V_6 ) ;
F_15 ( & V_20 -> V_6 ) ;
V_20 -> V_16 = NULL ;
}
return 0 ;
}
} else {
struct V_1 * V_13 ;
for ( V_13 = V_19 = F_1 ( V_8 ) ; V_13 != V_8 ; V_13 = F_1 ( V_13 ) ) {
if ( V_13 -> V_8 . V_15 == V_8 -> V_8 . V_15 ) {
V_19 = V_13 ;
break;
}
}
F_15 ( & V_8 -> V_3 ) ;
V_8 -> V_18 = 0 ;
F_13 ( V_8 ) ;
}
F_16 (slave_mnt, &mnt->mnt_slave_list, mnt_slave)
V_20 -> V_16 = V_19 ;
F_17 ( & V_8 -> V_6 , & V_19 -> V_5 ) ;
F_18 ( & V_8 -> V_5 , V_19 -> V_5 . V_7 ) ;
F_19 ( & V_8 -> V_5 ) ;
V_8 -> V_16 = V_19 ;
return 0 ;
}
void F_20 ( struct V_1 * V_8 , int type )
{
if ( type == V_22 ) {
F_21 ( V_8 ) ;
return;
}
F_9 ( V_8 ) ;
if ( type != V_23 ) {
F_15 ( & V_8 -> V_6 ) ;
V_8 -> V_16 = NULL ;
if ( type == V_24 )
V_8 -> V_8 . V_25 |= V_26 ;
else
V_8 -> V_8 . V_25 &= ~ V_26 ;
}
}
static struct V_1 * F_22 ( struct V_1 * V_13 ,
struct V_1 * V_27 )
{
if ( ! F_23 ( V_13 ) && ! F_10 ( & V_13 -> V_5 ) )
return F_3 ( V_13 ) ;
while ( 1 ) {
struct V_1 * V_19 = V_13 -> V_16 ;
if ( V_19 == V_27 -> V_16 ) {
struct V_1 * V_4 = F_1 ( V_13 ) ;
return ( V_4 == V_27 ) ? NULL : V_4 ;
} else if ( V_13 -> V_6 . V_4 != & V_19 -> V_5 )
return F_5 ( V_13 ) ;
V_13 = V_19 ;
}
}
static struct V_1 * F_24 ( struct V_1 * V_13 ,
struct V_1 * V_27 )
{
if ( ! F_23 ( V_13 ) && ! F_10 ( & V_13 -> V_5 ) )
V_13 = F_4 ( V_13 ) ;
return V_13 ;
}
static struct V_1 * F_25 ( struct V_1 * V_13 , struct V_1 * V_27 )
{
while ( 1 ) {
while ( 1 ) {
struct V_1 * V_4 ;
if ( ! F_23 ( V_13 ) && ! F_10 ( & V_13 -> V_5 ) )
return F_3 ( V_13 ) ;
V_4 = F_1 ( V_13 ) ;
if ( V_13 -> V_18 == V_27 -> V_18 ) {
if ( V_4 == V_27 )
return NULL ;
} else if ( V_13 -> V_6 . V_4 != & V_4 -> V_6 )
break;
V_13 = V_4 ;
}
while ( 1 ) {
struct V_1 * V_19 = V_13 -> V_16 ;
if ( V_13 -> V_6 . V_4 != & V_19 -> V_5 )
return F_5 ( V_13 ) ;
V_13 = F_1 ( V_19 ) ;
if ( V_19 -> V_18 == V_27 -> V_18 )
break;
if ( V_19 -> V_6 . V_4 == & V_13 -> V_6 )
break;
V_13 = V_19 ;
}
if ( V_13 == V_27 )
return NULL ;
}
}
static inline bool F_26 ( struct V_1 * V_28 , struct V_1 * V_29 )
{
return V_28 -> V_18 == V_29 -> V_18 && V_28 -> V_18 ;
}
static int F_27 ( struct V_1 * V_13 )
{
struct V_1 * V_30 ;
int type ;
if ( F_23 ( V_13 ) )
return 0 ;
if ( ! F_28 ( V_31 -> V_32 , V_13 -> V_8 . V_15 ) )
return 0 ;
if ( F_26 ( V_13 , V_33 ) ) {
type = V_34 ;
} else {
struct V_1 * V_35 , * V_2 ;
bool V_36 ;
for ( V_35 = V_13 ; ; V_35 = V_2 ) {
V_2 = V_35 -> V_16 ;
if ( V_2 == V_37 || F_29 ( V_2 ) )
break;
}
do {
struct V_1 * V_38 = V_39 -> V_40 ;
if ( V_39 == V_41 )
break;
V_36 = V_38 -> V_16 == V_2 ;
if ( V_36 && F_26 ( V_35 , V_38 ) )
break;
V_39 = V_39 -> V_16 ;
} while ( ! V_36 );
type = V_42 ;
if ( F_11 ( V_13 ) )
type |= V_34 ;
}
if ( V_13 -> V_14 -> V_43 != V_43 )
type |= V_44 ;
V_30 = F_30 ( V_39 , V_39 -> V_8 . V_15 , type ) ;
if ( F_31 ( V_30 ) )
return F_32 ( V_30 ) ;
V_30 -> V_8 . V_25 &= ~ V_45 ;
F_33 ( V_13 , V_31 , V_30 ) ;
V_33 = V_13 ;
V_39 = V_30 ;
if ( V_13 -> V_16 != V_37 ) {
F_34 ( & V_46 ) ;
F_35 ( V_13 -> V_16 ) ;
F_36 ( & V_46 ) ;
}
F_37 ( & V_30 -> V_47 , V_48 ) ;
return F_38 ( V_13 -> V_14 , V_30 ) ;
}
int F_39 ( struct V_1 * V_49 , struct V_50 * V_51 ,
struct V_1 * V_52 , struct V_53 * V_54 )
{
struct V_1 * V_13 , * V_35 ;
int V_55 = 0 ;
V_43 = V_56 -> V_57 -> V_14 -> V_43 ;
V_33 = V_49 ;
V_41 = V_52 ;
V_39 = V_52 ;
V_31 = V_51 ;
V_48 = V_54 ;
V_37 = V_49 -> V_16 ;
for ( V_35 = F_1 ( V_49 ) ; V_35 != V_49 ; V_35 = F_1 ( V_35 ) ) {
V_55 = F_27 ( V_35 ) ;
if ( V_55 )
goto V_58;
}
for ( V_13 = F_25 ( V_49 , V_49 ) ; V_13 ;
V_13 = F_25 ( V_13 , V_49 ) ) {
V_35 = V_13 ;
do {
V_55 = F_27 ( V_35 ) ;
if ( V_55 )
goto V_58;
V_35 = F_1 ( V_35 ) ;
} while ( V_35 != V_13 );
}
V_58:
F_34 ( & V_46 ) ;
F_40 (n, tree_list, mnt_hash) {
V_13 = V_35 -> V_40 ;
if ( V_13 -> V_16 != V_49 -> V_16 )
F_41 ( V_13 -> V_16 ) ;
}
F_36 ( & V_46 ) ;
return V_55 ;
}
static struct V_1 * F_42 ( struct V_1 * V_8 )
{
struct V_1 * V_30 ;
if ( ! F_43 ( & V_8 -> V_59 ) )
return NULL ;
V_30 = F_14 ( & V_8 -> V_59 , struct V_1 , V_60 ) ;
if ( V_30 -> V_61 != V_8 -> V_8 . V_15 )
return NULL ;
return V_30 ;
}
static inline int F_44 ( struct V_1 * V_8 , int V_62 )
{
return F_45 ( V_8 ) > V_62 ;
}
int F_46 ( struct V_1 * V_8 , int V_63 )
{
struct V_1 * V_13 , * V_30 , * V_64 ;
struct V_1 * V_38 = V_8 -> V_40 ;
if ( V_8 == V_38 )
return F_44 ( V_8 , V_63 ) ;
if ( ! F_10 ( & V_8 -> V_59 ) || F_44 ( V_8 , V_63 ) )
return 1 ;
for ( V_13 = F_22 ( V_38 , V_38 ) ; V_13 ;
V_13 = F_22 ( V_13 , V_38 ) ) {
int V_62 = 1 ;
V_30 = F_47 ( & V_13 -> V_8 , V_8 -> V_61 ) ;
if ( ! V_30 )
continue;
V_64 = F_42 ( V_30 ) ;
if ( V_64 )
V_62 += 1 ;
else if ( ! F_10 ( & V_30 -> V_59 ) )
continue;
if ( F_44 ( V_30 , V_62 ) )
return 1 ;
}
return 0 ;
}
void F_48 ( struct V_1 * V_8 )
{
struct V_1 * V_38 = V_8 -> V_40 ;
struct V_1 * V_13 , * V_30 ;
F_49 ( V_38 == V_8 ) ;
for ( V_13 = F_22 ( V_38 , V_38 ) ; V_13 ;
V_13 = F_22 ( V_13 , V_38 ) ) {
V_30 = F_47 ( & V_13 -> V_8 , V_8 -> V_61 ) ;
if ( V_30 )
V_30 -> V_8 . V_25 &= ~ V_45 ;
}
}
static void F_50 ( struct V_1 * V_8 , struct V_21 * V_65 )
{
F_41 ( V_8 ) ;
V_8 -> V_8 . V_25 |= V_66 ;
F_15 ( & V_8 -> V_60 ) ;
F_15 ( & V_8 -> V_67 ) ;
F_51 ( & V_8 -> V_68 , V_65 ) ;
}
static bool F_52 ( struct V_1 * V_8 ,
struct V_21 * V_65 ,
struct V_21 * V_69 )
{
bool V_70 = false ;
struct V_1 * V_30 ;
if ( V_8 -> V_8 . V_25 & ( V_66 | V_71 ) )
goto V_58;
F_16 (child, &mnt->mnt_mounts, mnt_child) {
if ( V_30 -> V_61 == V_8 -> V_8 . V_15 )
continue;
if ( ! F_10 ( & V_30 -> V_67 ) && F_29 ( V_30 ) )
continue;
goto V_72;
}
F_35 ( V_8 ) ;
V_70 = true ;
if ( ! F_53 ( V_8 ) ) {
F_50 ( V_8 , V_65 ) ;
} else {
V_72:
F_51 ( & V_8 -> V_67 , V_69 ) ;
}
V_58:
return V_70 ;
}
static void F_54 ( struct V_21 * V_65 ,
struct V_21 * V_69 )
{
struct V_1 * V_8 , * V_30 , * V_73 ;
F_16 (mnt, to_umount, mnt_list) {
F_55 (child, tmp, &mnt->mnt_mounts, mnt_child) {
if ( V_30 -> V_61 == V_8 -> V_8 . V_15 )
F_51 ( & V_30 -> V_67 , V_69 ) ;
else
F_50 ( V_30 , V_65 ) ;
}
}
}
static void F_56 ( struct V_21 * V_69 )
{
while ( ! F_10 ( V_69 ) ) {
struct V_1 * V_8 , * V_38 ;
struct V_50 * V_31 ;
V_8 = F_14 ( V_69 , struct V_1 , V_67 ) ;
F_41 ( V_8 ) ;
F_15 ( & V_8 -> V_67 ) ;
V_31 = V_8 -> V_74 ;
V_38 = V_8 -> V_40 ;
while ( V_38 -> V_8 . V_25 & V_66 ) {
V_31 = V_38 -> V_74 ;
V_38 = V_38 -> V_40 ;
}
if ( V_38 != V_8 -> V_40 )
F_57 ( V_38 , V_31 , V_8 ) ;
}
}
static void F_58 ( struct V_21 * V_75 )
{
while ( ! F_10 ( V_75 ) ) {
struct V_1 * V_8 =
F_14 ( V_75 , struct V_1 , V_67 ) ;
F_15 ( & V_8 -> V_67 ) ;
}
}
int F_59 ( struct V_21 * V_48 )
{
struct V_1 * V_8 ;
F_60 ( V_69 ) ;
F_60 ( V_65 ) ;
F_60 ( V_75 ) ;
F_61 (mnt, list, mnt_list) {
struct V_1 * V_38 = V_8 -> V_40 ;
struct V_1 * V_13 ;
if ( ! F_10 ( & V_8 -> V_67 ) )
continue;
F_62 ( & V_8 -> V_67 , & V_75 ) ;
for ( V_13 = F_22 ( V_38 , V_38 ) ; V_13 ;
V_13 = F_22 ( V_13 , V_38 ) ) {
struct V_1 * V_30 = F_47 ( & V_13 -> V_8 ,
V_8 -> V_61 ) ;
if ( ! V_30 )
continue;
if ( ! F_10 ( & V_30 -> V_67 ) ) {
V_13 = F_24 ( V_13 , V_38 ) ;
continue;
} else if ( V_30 -> V_8 . V_25 & V_66 ) {
F_62 ( & V_30 -> V_67 , & V_75 ) ;
continue;
}
while ( F_52 ( V_30 ,
& V_65 , & V_69 ) ) {
V_30 = V_30 -> V_40 ;
if ( F_10 ( & V_30 -> V_67 ) )
break;
}
}
}
F_54 ( & V_65 , & V_69 ) ;
F_56 ( & V_69 ) ;
F_58 ( & V_75 ) ;
F_63 ( & V_65 , V_48 ) ;
return 0 ;
}
