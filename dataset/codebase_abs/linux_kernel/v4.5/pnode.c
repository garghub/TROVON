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
struct V_1 * V_18 = V_7 , * V_19 = V_7 -> V_15 ;
struct V_1 * V_20 ;
while ( ( V_18 = F_1 ( V_18 ) ) != V_7 &&
V_18 -> V_7 . V_14 != V_7 -> V_7 . V_14 ) ;
if ( V_18 == V_7 ) {
V_18 = F_1 ( V_7 ) ;
if ( V_18 == V_7 )
V_18 = NULL ;
}
if ( V_7 -> V_17 && F_9 ( V_7 ) &&
F_10 ( & V_7 -> V_3 ) )
F_11 ( V_7 ) ;
F_12 ( & V_7 -> V_3 ) ;
V_7 -> V_17 = 0 ;
if ( V_18 )
V_19 = V_18 ;
if ( V_19 ) {
F_13 (slave_mnt, &mnt->mnt_slave_list, mnt_slave)
V_20 -> V_15 = V_19 ;
F_14 ( & V_7 -> V_6 , & V_19 -> V_5 ) ;
F_15 ( & V_7 -> V_5 , V_19 -> V_5 . V_21 ) ;
F_16 ( & V_7 -> V_5 ) ;
} else {
struct V_22 * V_2 = & V_7 -> V_5 ;
while ( ! F_10 ( V_2 ) ) {
V_20 = F_17 ( V_2 ,
struct V_1 , V_6 ) ;
F_12 ( & V_20 -> V_6 ) ;
V_20 -> V_15 = NULL ;
}
}
V_7 -> V_15 = V_19 ;
F_18 ( V_7 ) ;
return 0 ;
}
void F_19 ( struct V_1 * V_7 , int type )
{
if ( type == V_23 ) {
F_20 ( V_7 ) ;
return;
}
F_8 ( V_7 ) ;
if ( type != V_24 ) {
F_12 ( & V_7 -> V_6 ) ;
V_7 -> V_15 = NULL ;
if ( type == V_25 )
V_7 -> V_7 . V_26 |= V_27 ;
else
V_7 -> V_7 . V_26 &= ~ V_27 ;
}
}
static struct V_1 * F_21 ( struct V_1 * V_12 ,
struct V_1 * V_28 )
{
if ( ! F_22 ( V_12 ) && ! F_10 ( & V_12 -> V_5 ) )
return F_3 ( V_12 ) ;
while ( 1 ) {
struct V_1 * V_19 = V_12 -> V_15 ;
if ( V_19 == V_28 -> V_15 ) {
struct V_1 * V_4 = F_1 ( V_12 ) ;
return ( V_4 == V_28 ) ? NULL : V_4 ;
} else if ( V_12 -> V_6 . V_4 != & V_19 -> V_5 )
return F_4 ( V_12 ) ;
V_12 = V_19 ;
}
}
static struct V_1 * F_23 ( struct V_1 * V_12 , struct V_1 * V_28 )
{
while ( 1 ) {
while ( 1 ) {
struct V_1 * V_4 ;
if ( ! F_22 ( V_12 ) && ! F_10 ( & V_12 -> V_5 ) )
return F_3 ( V_12 ) ;
V_4 = F_1 ( V_12 ) ;
if ( V_12 -> V_17 == V_28 -> V_17 ) {
if ( V_4 == V_28 )
return NULL ;
} else if ( V_12 -> V_6 . V_4 != & V_4 -> V_6 )
break;
V_12 = V_4 ;
}
while ( 1 ) {
struct V_1 * V_19 = V_12 -> V_15 ;
if ( V_12 -> V_6 . V_4 != & V_19 -> V_5 )
return F_4 ( V_12 ) ;
V_12 = F_1 ( V_19 ) ;
if ( V_19 -> V_17 == V_28 -> V_17 )
break;
if ( V_19 -> V_6 . V_4 == & V_12 -> V_6 )
break;
V_12 = V_19 ;
}
if ( V_12 == V_28 )
return NULL ;
}
}
static inline bool F_24 ( struct V_1 * V_29 , struct V_1 * V_30 )
{
return V_29 -> V_17 == V_30 -> V_17 && V_29 -> V_17 ;
}
static int F_25 ( struct V_1 * V_12 )
{
struct V_1 * V_31 ;
int type ;
if ( F_22 ( V_12 ) )
return 0 ;
if ( ! F_26 ( V_32 -> V_33 , V_12 -> V_7 . V_14 ) )
return 0 ;
if ( F_24 ( V_12 , V_34 ) ) {
type = V_35 ;
} else {
struct V_1 * V_36 , * V_2 ;
for ( V_36 = V_12 ; ; V_36 = V_2 ) {
V_2 = V_36 -> V_15 ;
if ( V_2 == V_37 || F_27 ( V_2 ) ) {
while ( V_34 -> V_15 != V_2 ) {
V_38 = V_38 -> V_15 ;
V_34 = V_38 -> V_39 ;
}
if ( ! F_24 ( V_36 , V_34 ) ) {
V_38 = V_38 -> V_15 ;
V_34 = V_38 -> V_39 ;
}
break;
}
}
type = V_40 ;
if ( F_9 ( V_12 ) )
type |= V_35 ;
}
if ( V_12 -> V_13 -> V_41 != V_41 )
type |= V_42 ;
V_31 = F_28 ( V_38 , V_38 -> V_7 . V_14 , type ) ;
if ( F_29 ( V_31 ) )
return F_30 ( V_31 ) ;
V_31 -> V_7 . V_26 &= ~ V_43 ;
F_31 ( V_12 , V_32 , V_31 ) ;
V_34 = V_12 ;
V_38 = V_31 ;
if ( V_12 -> V_15 != V_37 ) {
F_32 ( & V_44 ) ;
F_33 ( V_12 -> V_15 ) ;
F_34 ( & V_44 ) ;
}
F_35 ( & V_31 -> V_45 , V_46 ) ;
return 0 ;
}
int F_36 ( struct V_1 * V_47 , struct V_48 * V_49 ,
struct V_1 * V_50 , struct V_51 * V_52 )
{
struct V_1 * V_12 , * V_36 ;
int V_53 = 0 ;
V_41 = V_54 -> V_55 -> V_13 -> V_41 ;
V_34 = V_47 ;
V_38 = V_50 ;
V_32 = V_49 ;
V_46 = V_52 ;
V_37 = V_47 -> V_15 ;
for ( V_36 = F_1 ( V_47 ) ; V_36 != V_47 ; V_36 = F_1 ( V_36 ) ) {
V_53 = F_25 ( V_36 ) ;
if ( V_53 )
goto V_56;
}
for ( V_12 = F_23 ( V_47 , V_47 ) ; V_12 ;
V_12 = F_23 ( V_12 , V_47 ) ) {
V_36 = V_12 ;
do {
V_53 = F_25 ( V_36 ) ;
if ( V_53 )
goto V_56;
V_36 = F_1 ( V_36 ) ;
} while ( V_36 != V_12 );
}
V_56:
F_32 ( & V_44 ) ;
F_37 (n, tree_list, mnt_hash) {
V_12 = V_36 -> V_39 ;
if ( V_12 -> V_15 != V_47 -> V_15 )
F_38 ( V_12 -> V_15 ) ;
}
F_34 ( & V_44 ) ;
return V_53 ;
}
static inline int F_39 ( struct V_1 * V_7 , int V_57 )
{
return F_40 ( V_7 ) > V_57 ;
}
int F_41 ( struct V_1 * V_7 , int V_58 )
{
struct V_1 * V_12 , * V_31 ;
struct V_1 * V_59 = V_7 -> V_39 ;
int V_53 = 0 ;
if ( V_7 == V_59 )
return F_39 ( V_7 , V_58 ) ;
if ( ! F_10 ( & V_7 -> V_60 ) || F_39 ( V_7 , V_58 ) )
return 1 ;
for ( V_12 = F_21 ( V_59 , V_59 ) ; V_12 ;
V_12 = F_21 ( V_12 , V_59 ) ) {
V_31 = F_42 ( & V_12 -> V_7 , V_7 -> V_61 ) ;
if ( V_31 && F_10 ( & V_31 -> V_60 ) &&
( V_53 = F_39 ( V_31 , 1 ) ) )
break;
}
return V_53 ;
}
void F_43 ( struct V_1 * V_7 )
{
struct V_1 * V_59 = V_7 -> V_39 ;
struct V_1 * V_12 , * V_31 ;
F_44 ( V_59 == V_7 ) ;
for ( V_12 = F_21 ( V_59 , V_59 ) ; V_12 ;
V_12 = F_21 ( V_12 , V_59 ) ) {
V_31 = F_42 ( & V_12 -> V_7 , V_7 -> V_61 ) ;
if ( V_31 )
V_31 -> V_7 . V_26 &= ~ V_43 ;
}
}
static void F_45 ( struct V_1 * V_7 )
{
struct V_1 * V_59 = V_7 -> V_39 ;
struct V_1 * V_12 ;
F_44 ( V_59 == V_7 ) ;
for ( V_12 = F_21 ( V_59 , V_59 ) ; V_12 ;
V_12 = F_21 ( V_12 , V_59 ) ) {
struct V_1 * V_31 = F_42 ( & V_12 -> V_7 ,
V_7 -> V_61 ) ;
if ( V_31 && ( ! F_46 ( V_31 ) || F_27 ( V_12 ) ) ) {
F_33 ( V_31 ) ;
}
}
}
static void F_47 ( struct V_1 * V_7 )
{
struct V_1 * V_59 = V_7 -> V_39 ;
struct V_1 * V_12 ;
F_44 ( V_59 == V_7 ) ;
for ( V_12 = F_21 ( V_59 , V_59 ) ; V_12 ;
V_12 = F_21 ( V_12 , V_59 ) ) {
struct V_1 * V_31 = F_42 ( & V_12 -> V_7 ,
V_7 -> V_61 ) ;
if ( ! V_31 || ! F_27 ( V_31 ) )
continue;
F_38 ( V_31 ) ;
if ( F_10 ( & V_31 -> V_60 ) ) {
F_12 ( & V_31 -> V_62 ) ;
V_31 -> V_7 . V_26 |= V_63 ;
F_48 ( & V_31 -> V_64 , & V_7 -> V_64 ) ;
}
}
}
int F_49 ( struct V_22 * V_46 )
{
struct V_1 * V_7 ;
F_50 (mnt, list, mnt_list)
F_45 ( V_7 ) ;
F_13 (mnt, list, mnt_list)
F_47 ( V_7 ) ;
return 0 ;
}
