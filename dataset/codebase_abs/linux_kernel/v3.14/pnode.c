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
struct V_1 * V_39 , struct V_40 * V_41 )
{
struct V_42 * V_43 = V_44 -> V_45 -> V_13 -> V_43 ;
struct V_1 * V_12 , * V_46 ;
int V_47 = 0 ;
struct V_1 * V_48 = V_36 ;
struct V_1 * V_49 = V_39 ;
F_25 ( V_50 ) ;
for ( V_12 = F_21 ( V_36 , V_36 ) ; V_12 ;
V_12 = F_21 ( V_12 , V_36 ) ) {
int type ;
struct V_1 * V_51 ;
if ( F_22 ( V_12 ) )
continue;
V_51 = F_23 ( V_12 , V_48 , V_49 , & type ) ;
if ( V_12 -> V_13 -> V_43 != V_43 )
type |= V_52 ;
V_46 = F_26 ( V_51 , V_51 -> V_7 . V_14 , type ) ;
if ( F_27 ( V_46 ) ) {
V_47 = F_28 ( V_46 ) ;
V_50 = * V_41 ;
V_50 . V_53 -> V_54 = & V_50 . V_53 ;
F_29 ( V_41 ) ;
goto V_55;
}
if ( F_30 ( V_38 -> V_56 , V_12 -> V_7 . V_14 ) ) {
F_31 ( V_12 , V_38 , V_46 ) ;
F_32 ( & V_46 -> V_57 , V_41 ) ;
} else {
F_32 ( & V_46 -> V_57 , & V_50 ) ;
}
V_48 = V_12 ;
V_49 = V_46 ;
}
V_55:
F_33 () ;
while ( ! F_34 ( & V_50 ) ) {
V_46 = F_35 ( V_50 . V_53 , struct V_1 , V_57 ) ;
F_36 ( V_46 , 0 ) ;
}
F_37 () ;
return V_47 ;
}
static inline int F_38 ( struct V_1 * V_7 , int V_58 )
{
return F_39 ( V_7 ) > V_58 ;
}
int F_40 ( struct V_1 * V_7 , int V_59 )
{
struct V_1 * V_12 , * V_46 ;
struct V_1 * V_60 = V_7 -> V_61 ;
int V_47 = 0 ;
if ( V_7 == V_60 )
return F_38 ( V_7 , V_59 ) ;
if ( ! F_10 ( & V_7 -> V_62 ) || F_38 ( V_7 , V_59 ) )
return 1 ;
for ( V_12 = F_21 ( V_60 , V_60 ) ; V_12 ;
V_12 = F_21 ( V_12 , V_60 ) ) {
V_46 = F_41 ( & V_12 -> V_7 , V_7 -> V_63 ) ;
if ( V_46 && F_10 ( & V_46 -> V_62 ) &&
( V_47 = F_38 ( V_46 , 1 ) ) )
break;
}
return V_47 ;
}
static void F_42 ( struct V_1 * V_7 )
{
struct V_1 * V_60 = V_7 -> V_61 ;
struct V_1 * V_12 ;
F_43 ( V_60 == V_7 ) ;
for ( V_12 = F_21 ( V_60 , V_60 ) ; V_12 ;
V_12 = F_21 ( V_12 , V_60 ) ) {
struct V_1 * V_46 = F_41 ( & V_12 -> V_7 ,
V_7 -> V_63 ) ;
if ( V_46 && F_10 ( & V_46 -> V_62 ) ) {
F_44 ( & V_46 -> V_57 ) ;
F_45 ( & V_46 -> V_57 , & V_7 -> V_57 ) ;
}
}
}
int F_46 ( struct V_40 * V_64 )
{
struct V_1 * V_7 ;
F_47 (mnt, list, mnt_hash)
F_42 ( V_7 ) ;
return 0 ;
}
