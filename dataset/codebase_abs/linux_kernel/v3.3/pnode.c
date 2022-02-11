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
if ( F_9 ( V_7 ) && F_10 ( & V_7 -> V_3 ) )
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
static struct V_1 * F_23 ( struct V_1 * V_29 ,
struct V_1 * V_30 ,
struct V_1 * V_31 ,
int * type )
{
struct V_1 * V_32 = NULL ;
struct V_1 * V_33 = NULL ;
while ( V_30 != V_29 -> V_15 ) {
V_33 = V_30 ;
V_32 = V_31 ;
V_30 = V_30 -> V_15 ;
V_31 = V_31 -> V_15 ;
}
if ( V_33 ) {
do {
V_33 = F_1 ( V_33 ) ;
} while ( F_22 ( V_33 ) );
if ( V_29 == V_33 ) {
* type = V_34 ;
return V_32 ;
}
}
* type = V_35 ;
if ( F_9 ( V_29 ) )
* type |= V_34 ;
return V_31 ;
}
int F_24 ( struct V_1 * V_36 , struct V_37 * V_38 ,
struct V_1 * V_39 , struct V_22 * V_40 )
{
struct V_1 * V_12 , * V_41 ;
int V_42 = 0 ;
struct V_1 * V_43 = V_36 ;
struct V_1 * V_44 = V_39 ;
F_25 ( V_45 ) ;
F_25 ( V_46 ) ;
for ( V_12 = F_21 ( V_36 , V_36 ) ; V_12 ;
V_12 = F_21 ( V_12 , V_36 ) ) {
int type ;
struct V_1 * V_47 ;
if ( F_22 ( V_12 ) )
continue;
V_47 = F_23 ( V_12 , V_43 , V_44 , & type ) ;
if ( ! ( V_41 = F_26 ( V_47 , V_47 -> V_7 . V_14 , type ) ) ) {
V_42 = - V_48 ;
F_15 ( V_40 , V_45 . V_21 ) ;
goto V_49;
}
if ( F_27 ( V_38 , V_12 -> V_7 . V_14 ) ) {
F_28 ( V_12 , V_38 , V_41 ) ;
F_29 ( & V_41 -> V_50 , V_40 ) ;
} else {
F_29 ( & V_41 -> V_50 , & V_45 ) ;
}
V_43 = V_12 ;
V_44 = V_41 ;
}
V_49:
F_30 ( V_51 ) ;
while ( ! F_10 ( & V_45 ) ) {
V_41 = F_17 ( & V_45 , struct V_1 , V_50 ) ;
F_31 ( V_41 , 0 , & V_46 ) ;
}
F_32 ( V_51 ) ;
F_33 ( & V_46 ) ;
return V_42 ;
}
static inline int F_34 ( struct V_1 * V_7 , int V_52 )
{
int V_53 = F_35 ( V_7 ) - V_7 -> V_54 ;
return ( V_53 > V_52 ) ;
}
int F_36 ( struct V_1 * V_7 , int V_55 )
{
struct V_1 * V_12 , * V_41 ;
struct V_1 * V_56 = V_7 -> V_57 ;
int V_42 = 0 ;
if ( V_7 == V_56 )
return F_34 ( V_7 , V_55 ) ;
if ( ! F_10 ( & V_7 -> V_58 ) || F_34 ( V_7 , V_55 ) )
return 1 ;
for ( V_12 = F_21 ( V_56 , V_56 ) ; V_12 ;
V_12 = F_21 ( V_12 , V_56 ) ) {
V_41 = F_37 ( & V_12 -> V_7 , V_7 -> V_59 , 0 ) ;
if ( V_41 && F_10 ( & V_41 -> V_58 ) &&
( V_42 = F_34 ( V_41 , 1 ) ) )
break;
}
return V_42 ;
}
static void F_38 ( struct V_1 * V_7 )
{
struct V_1 * V_56 = V_7 -> V_57 ;
struct V_1 * V_12 ;
F_39 ( V_56 == V_7 ) ;
for ( V_12 = F_21 ( V_56 , V_56 ) ; V_12 ;
V_12 = F_21 ( V_12 , V_56 ) ) {
struct V_1 * V_41 = F_37 ( & V_12 -> V_7 ,
V_7 -> V_59 , 0 ) ;
if ( V_41 && F_10 ( & V_41 -> V_58 ) )
F_40 ( & V_41 -> V_50 , & V_7 -> V_50 ) ;
}
}
int F_41 ( struct V_22 * V_60 )
{
struct V_1 * V_7 ;
F_13 (mnt, list, mnt_hash)
F_38 ( V_7 ) ;
return 0 ;
}
