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
return F_2 ( V_2 -> V_6 . V_4 , struct V_1 , V_6 ) ;
}
static struct V_1 * F_5 ( struct V_1 * V_7 ,
struct V_8 * V_9 ,
const struct V_10 * V_11 )
{
struct V_1 * V_12 = V_7 ;
do {
if ( V_12 -> V_13 == V_9 && F_6 ( V_12 , V_12 -> V_7 . V_14 , V_11 ) )
return V_12 ;
V_12 = F_1 ( V_12 ) ;
} while ( V_12 != V_7 );
return NULL ;
}
int F_7 ( struct V_1 * V_7 , const struct V_10 * V_11 )
{
struct V_1 * V_12 ;
for ( V_12 = V_7 -> V_15 ; V_12 != NULL ; V_12 = V_12 -> V_15 ) {
struct V_1 * V_16 = F_5 ( V_12 , V_7 -> V_13 , V_11 ) ;
if ( V_16 )
return V_16 -> V_17 ;
}
return 0 ;
}
static int F_8 ( struct V_1 * V_7 )
{
struct V_1 * V_18 , * V_19 ;
if ( F_9 ( & V_7 -> V_3 ) ) {
if ( F_10 ( V_7 ) ) {
F_11 ( V_7 ) ;
F_12 ( V_7 ) ;
}
V_18 = V_7 -> V_15 ;
if ( ! V_18 ) {
struct V_20 * V_2 = & V_7 -> V_5 ;
while ( ! F_9 ( V_2 ) ) {
V_19 = F_13 ( V_2 ,
struct V_1 , V_6 ) ;
F_14 ( & V_19 -> V_6 ) ;
V_19 -> V_15 = NULL ;
}
return 0 ;
}
} else {
struct V_1 * V_12 ;
for ( V_12 = V_18 = F_1 ( V_7 ) ; V_12 != V_7 ; V_12 = F_1 ( V_12 ) ) {
if ( V_12 -> V_7 . V_14 == V_7 -> V_7 . V_14 ) {
V_18 = V_12 ;
break;
}
}
F_14 ( & V_7 -> V_3 ) ;
V_7 -> V_17 = 0 ;
F_12 ( V_7 ) ;
}
F_15 (slave_mnt, &mnt->mnt_slave_list, mnt_slave)
V_19 -> V_15 = V_18 ;
F_16 ( & V_7 -> V_6 , & V_18 -> V_5 ) ;
F_17 ( & V_7 -> V_5 , V_18 -> V_5 . V_21 ) ;
F_18 ( & V_7 -> V_5 ) ;
V_7 -> V_15 = V_18 ;
return 0 ;
}
void F_19 ( struct V_1 * V_7 , int type )
{
if ( type == V_22 ) {
F_20 ( V_7 ) ;
return;
}
F_8 ( V_7 ) ;
if ( type != V_23 ) {
F_14 ( & V_7 -> V_6 ) ;
V_7 -> V_15 = NULL ;
if ( type == V_24 )
V_7 -> V_7 . V_25 |= V_26 ;
else
V_7 -> V_7 . V_25 &= ~ V_26 ;
}
}
static struct V_1 * F_21 ( struct V_1 * V_12 ,
struct V_1 * V_27 )
{
if ( ! F_22 ( V_12 ) && ! F_9 ( & V_12 -> V_5 ) )
return F_3 ( V_12 ) ;
while ( 1 ) {
struct V_1 * V_18 = V_12 -> V_15 ;
if ( V_18 == V_27 -> V_15 ) {
struct V_1 * V_4 = F_1 ( V_12 ) ;
return ( V_4 == V_27 ) ? NULL : V_4 ;
} else if ( V_12 -> V_6 . V_4 != & V_18 -> V_5 )
return F_4 ( V_12 ) ;
V_12 = V_18 ;
}
}
static struct V_1 * F_23 ( struct V_1 * V_12 , struct V_1 * V_27 )
{
while ( 1 ) {
while ( 1 ) {
struct V_1 * V_4 ;
if ( ! F_22 ( V_12 ) && ! F_9 ( & V_12 -> V_5 ) )
return F_3 ( V_12 ) ;
V_4 = F_1 ( V_12 ) ;
if ( V_12 -> V_17 == V_27 -> V_17 ) {
if ( V_4 == V_27 )
return NULL ;
} else if ( V_12 -> V_6 . V_4 != & V_4 -> V_6 )
break;
V_12 = V_4 ;
}
while ( 1 ) {
struct V_1 * V_18 = V_12 -> V_15 ;
if ( V_12 -> V_6 . V_4 != & V_18 -> V_5 )
return F_4 ( V_12 ) ;
V_12 = F_1 ( V_18 ) ;
if ( V_18 -> V_17 == V_27 -> V_17 )
break;
if ( V_18 -> V_6 . V_4 == & V_12 -> V_6 )
break;
V_12 = V_18 ;
}
if ( V_12 == V_27 )
return NULL ;
}
}
static inline bool F_24 ( struct V_1 * V_28 , struct V_1 * V_29 )
{
return V_28 -> V_17 == V_29 -> V_17 && V_28 -> V_17 ;
}
static int F_25 ( struct V_1 * V_12 )
{
struct V_1 * V_30 ;
int type ;
if ( F_22 ( V_12 ) )
return 0 ;
if ( ! F_26 ( V_31 -> V_32 , V_12 -> V_7 . V_14 ) )
return 0 ;
if ( F_24 ( V_12 , V_33 ) ) {
type = V_34 ;
} else {
struct V_1 * V_35 , * V_2 ;
bool V_36 ;
for ( V_35 = V_12 ; ; V_35 = V_2 ) {
V_2 = V_35 -> V_15 ;
if ( V_2 == V_37 || F_27 ( V_2 ) )
break;
}
do {
struct V_1 * V_38 = V_39 -> V_40 ;
if ( V_39 == V_41 )
break;
V_36 = V_38 -> V_15 == V_2 ;
if ( V_36 && F_24 ( V_35 , V_38 ) )
break;
V_39 = V_39 -> V_15 ;
} while ( ! V_36 );
type = V_42 ;
if ( F_10 ( V_12 ) )
type |= V_34 ;
}
if ( V_12 -> V_13 -> V_43 != V_43 )
type |= V_44 ;
V_30 = F_28 ( V_39 , V_39 -> V_7 . V_14 , type ) ;
if ( F_29 ( V_30 ) )
return F_30 ( V_30 ) ;
V_30 -> V_7 . V_25 &= ~ V_45 ;
F_31 ( V_12 , V_31 , V_30 ) ;
V_33 = V_12 ;
V_39 = V_30 ;
if ( V_12 -> V_15 != V_37 ) {
F_32 ( & V_46 ) ;
F_33 ( V_12 -> V_15 ) ;
F_34 ( & V_46 ) ;
}
F_35 ( & V_30 -> V_47 , V_48 ) ;
return F_36 ( V_12 -> V_13 , V_30 ) ;
}
int F_37 ( struct V_1 * V_49 , struct V_50 * V_51 ,
struct V_1 * V_52 , struct V_53 * V_54 )
{
struct V_1 * V_12 , * V_35 ;
int V_55 = 0 ;
V_43 = V_56 -> V_57 -> V_13 -> V_43 ;
V_33 = V_49 ;
V_41 = V_52 ;
V_39 = V_52 ;
V_31 = V_51 ;
V_48 = V_54 ;
V_37 = V_49 -> V_15 ;
for ( V_35 = F_1 ( V_49 ) ; V_35 != V_49 ; V_35 = F_1 ( V_35 ) ) {
V_55 = F_25 ( V_35 ) ;
if ( V_55 )
goto V_58;
}
for ( V_12 = F_23 ( V_49 , V_49 ) ; V_12 ;
V_12 = F_23 ( V_12 , V_49 ) ) {
V_35 = V_12 ;
do {
V_55 = F_25 ( V_35 ) ;
if ( V_55 )
goto V_58;
V_35 = F_1 ( V_35 ) ;
} while ( V_35 != V_12 );
}
V_58:
F_32 ( & V_46 ) ;
F_38 (n, tree_list, mnt_hash) {
V_12 = V_35 -> V_40 ;
if ( V_12 -> V_15 != V_49 -> V_15 )
F_39 ( V_12 -> V_15 ) ;
}
F_34 ( & V_46 ) ;
return V_55 ;
}
static struct V_1 * F_40 ( struct V_1 * V_7 )
{
struct V_1 * V_30 ;
if ( ! F_41 ( & V_7 -> V_59 ) )
return NULL ;
V_30 = F_13 ( & V_7 -> V_59 , struct V_1 , V_60 ) ;
if ( V_30 -> V_61 != V_7 -> V_7 . V_14 )
return NULL ;
return V_30 ;
}
static inline int F_42 ( struct V_1 * V_7 , int V_62 )
{
return F_43 ( V_7 ) > V_62 ;
}
int F_44 ( struct V_1 * V_7 , int V_63 )
{
struct V_1 * V_12 , * V_30 , * V_64 ;
struct V_1 * V_38 = V_7 -> V_40 ;
if ( V_7 == V_38 )
return F_42 ( V_7 , V_63 ) ;
if ( ! F_9 ( & V_7 -> V_59 ) || F_42 ( V_7 , V_63 ) )
return 1 ;
for ( V_12 = F_21 ( V_38 , V_38 ) ; V_12 ;
V_12 = F_21 ( V_12 , V_38 ) ) {
int V_62 = 1 ;
V_30 = F_45 ( & V_12 -> V_7 , V_7 -> V_61 ) ;
if ( ! V_30 )
continue;
V_64 = F_40 ( V_30 ) ;
if ( V_64 )
V_62 += 1 ;
else if ( ! F_9 ( & V_30 -> V_59 ) )
continue;
if ( F_42 ( V_30 , V_62 ) )
return 1 ;
}
return 0 ;
}
void F_46 ( struct V_1 * V_7 )
{
struct V_1 * V_38 = V_7 -> V_40 ;
struct V_1 * V_12 , * V_30 ;
F_47 ( V_38 == V_7 ) ;
for ( V_12 = F_21 ( V_38 , V_38 ) ; V_12 ;
V_12 = F_21 ( V_12 , V_38 ) ) {
V_30 = F_45 ( & V_12 -> V_7 , V_7 -> V_61 ) ;
if ( V_30 )
V_30 -> V_7 . V_25 &= ~ V_45 ;
}
}
static void F_48 ( struct V_1 * V_7 )
{
struct V_1 * V_38 = V_7 -> V_40 ;
struct V_1 * V_12 ;
F_47 ( V_38 == V_7 ) ;
for ( V_12 = F_21 ( V_38 , V_38 ) ; V_12 ;
V_12 = F_21 ( V_12 , V_38 ) ) {
struct V_1 * V_30 = F_45 ( & V_12 -> V_7 ,
V_7 -> V_61 ) ;
if ( ! V_30 || ( V_30 -> V_7 . V_25 & V_65 ) )
continue;
if ( ! F_49 ( V_30 ) || F_27 ( V_12 ) ) {
F_33 ( V_30 ) ;
}
}
}
static void F_50 ( struct V_1 * V_7 )
{
struct V_1 * V_38 = V_7 -> V_40 ;
struct V_1 * V_12 ;
F_47 ( V_38 == V_7 ) ;
for ( V_12 = F_21 ( V_38 , V_38 ) ; V_12 ;
V_12 = F_21 ( V_12 , V_38 ) ) {
struct V_1 * V_64 ;
struct V_1 * V_30 = F_45 ( & V_12 -> V_7 ,
V_7 -> V_61 ) ;
if ( ! V_30 || ! F_27 ( V_30 ) )
continue;
F_39 ( V_30 ) ;
V_64 = F_40 ( V_30 ) ;
if ( V_64 )
F_51 ( V_30 -> V_40 , V_30 -> V_66 ,
V_64 ) ;
if ( F_9 ( & V_30 -> V_59 ) ) {
F_14 ( & V_30 -> V_60 ) ;
V_30 -> V_7 . V_25 |= V_65 ;
F_52 ( & V_30 -> V_67 , & V_7 -> V_67 ) ;
}
}
}
int F_53 ( struct V_20 * V_48 )
{
struct V_1 * V_7 ;
F_54 (mnt, list, mnt_list)
F_48 ( V_7 ) ;
F_15 (mnt, list, mnt_list)
F_50 ( V_7 ) ;
return 0 ;
}
