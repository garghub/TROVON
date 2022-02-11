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
static int F_24 ( struct V_1 * V_12 )
{
struct V_1 * V_29 ;
int type ;
if ( F_22 ( V_12 ) )
return 0 ;
if ( ! F_25 ( V_30 -> V_31 , V_12 -> V_7 . V_14 ) )
return 0 ;
if ( V_12 -> V_17 == V_32 -> V_17 ) {
type = V_33 ;
} else {
struct V_1 * V_34 , * V_2 ;
for ( V_34 = V_12 ; ; V_34 = V_2 ) {
V_2 = V_34 -> V_15 ;
if ( V_2 == V_35 || F_26 ( V_2 ) ) {
while ( V_32 -> V_15 != V_2 ) {
V_36 = V_36 -> V_15 ;
V_32 = V_36 -> V_37 ;
}
if ( V_34 -> V_17 != V_32 -> V_17 ) {
V_36 = V_36 -> V_15 ;
V_32 = V_36 -> V_37 ;
}
break;
}
}
type = V_38 ;
if ( F_9 ( V_12 ) )
type |= V_33 ;
}
if ( V_12 -> V_13 -> V_39 != V_39 )
type |= V_40 ;
V_29 = F_27 ( V_36 , V_36 -> V_7 . V_14 , type ) ;
if ( F_28 ( V_29 ) )
return F_29 ( V_29 ) ;
F_30 ( V_12 , V_30 , V_29 ) ;
V_32 = V_12 ;
V_36 = V_29 ;
if ( V_12 -> V_15 != V_35 ) {
F_31 ( & V_41 ) ;
F_32 ( V_12 -> V_15 ) ;
F_33 ( & V_41 ) ;
}
F_34 ( & V_29 -> V_42 , V_43 ) ;
return 0 ;
}
int F_35 ( struct V_1 * V_44 , struct V_45 * V_46 ,
struct V_1 * V_47 , struct V_48 * V_49 )
{
struct V_1 * V_12 , * V_34 ;
int V_50 = 0 ;
V_39 = V_51 -> V_52 -> V_13 -> V_39 ;
V_32 = V_44 ;
V_36 = V_47 ;
V_30 = V_46 ;
V_43 = V_49 ;
V_35 = V_44 -> V_15 ;
for ( V_34 = F_1 ( V_44 ) ; V_34 != V_44 ; V_34 = F_1 ( V_34 ) ) {
V_50 = F_24 ( V_34 ) ;
if ( V_50 )
goto V_53;
}
for ( V_12 = F_23 ( V_44 , V_44 ) ; V_12 ;
V_12 = F_23 ( V_12 , V_44 ) ) {
V_34 = V_12 ;
do {
V_50 = F_24 ( V_34 ) ;
if ( V_50 )
goto V_53;
V_34 = F_1 ( V_34 ) ;
} while ( V_34 != V_12 );
}
V_53:
F_31 ( & V_41 ) ;
F_36 (n, tree_list, mnt_hash) {
V_12 = V_34 -> V_37 ;
if ( V_12 -> V_15 != V_44 -> V_15 )
F_37 ( V_12 -> V_15 ) ;
}
F_33 ( & V_41 ) ;
return V_50 ;
}
static inline int F_38 ( struct V_1 * V_7 , int V_54 )
{
return F_39 ( V_7 ) > V_54 ;
}
int F_40 ( struct V_1 * V_7 , int V_55 )
{
struct V_1 * V_12 , * V_29 ;
struct V_1 * V_56 = V_7 -> V_37 ;
int V_50 = 0 ;
if ( V_7 == V_56 )
return F_38 ( V_7 , V_55 ) ;
if ( ! F_10 ( & V_7 -> V_57 ) || F_38 ( V_7 , V_55 ) )
return 1 ;
for ( V_12 = F_21 ( V_56 , V_56 ) ; V_12 ;
V_12 = F_21 ( V_12 , V_56 ) ) {
V_29 = F_41 ( & V_12 -> V_7 , V_7 -> V_58 ) ;
if ( V_29 && F_10 ( & V_29 -> V_57 ) &&
( V_50 = F_38 ( V_29 , 1 ) ) )
break;
}
return V_50 ;
}
static void F_42 ( struct V_1 * V_7 )
{
struct V_1 * V_56 = V_7 -> V_37 ;
struct V_1 * V_12 ;
F_43 ( V_56 == V_7 ) ;
for ( V_12 = F_21 ( V_56 , V_56 ) ; V_12 ;
V_12 = F_21 ( V_12 , V_56 ) ) {
struct V_1 * V_29 = F_41 ( & V_12 -> V_7 ,
V_7 -> V_58 ) ;
if ( V_29 && F_10 ( & V_29 -> V_57 ) ) {
F_12 ( & V_29 -> V_59 ) ;
F_44 ( & V_29 -> V_42 ) ;
F_45 ( & V_29 -> V_42 , & V_7 -> V_42 ) ;
}
}
}
int F_46 ( struct V_48 * V_43 )
{
struct V_1 * V_7 ;
F_36 (mnt, list, mnt_hash)
F_42 ( V_7 ) ;
return 0 ;
}
