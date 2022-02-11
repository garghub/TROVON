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
static bool F_5 ( struct V_1 * V_7 , struct V_8 * V_8 ,
const struct V_9 * V_10 )
{
while ( V_7 != V_10 -> V_7 && V_7 -> V_11 != V_7 ) {
V_8 = V_7 -> V_12 ;
V_7 = V_7 -> V_11 ;
}
return V_7 == V_10 -> V_7 && F_6 ( V_8 , V_10 -> V_8 ) ;
}
static struct V_1 * F_7 ( struct V_1 * V_7 ,
struct V_13 * V_14 ,
const struct V_9 * V_10 )
{
struct V_1 * V_15 = V_7 ;
do {
if ( V_15 -> V_16 == V_14 && F_5 ( V_15 , V_15 -> V_17 , V_10 ) )
return V_15 ;
V_15 = F_1 ( V_15 ) ;
} while ( V_15 != V_7 );
return NULL ;
}
int F_8 ( struct V_1 * V_7 , const struct V_9 * V_10 )
{
struct V_1 * V_15 ;
for ( V_15 = V_7 -> V_18 ; V_15 != NULL ; V_15 = V_15 -> V_18 ) {
struct V_1 * V_19 = F_7 ( V_15 , V_7 -> V_16 , V_10 ) ;
if ( V_19 )
return V_19 -> V_20 ;
}
return 0 ;
}
static int F_9 ( struct V_1 * V_7 )
{
struct V_1 * V_21 = V_7 , * V_22 = V_7 -> V_18 ;
struct V_1 * V_23 ;
while ( ( V_21 = F_1 ( V_21 ) ) != V_7 &&
V_21 -> V_17 != V_7 -> V_17 ) ;
if ( V_21 == V_7 ) {
V_21 = F_1 ( V_7 ) ;
if ( V_21 == V_7 )
V_21 = NULL ;
}
if ( F_10 ( V_7 ) && F_11 ( & V_7 -> V_3 ) )
F_12 ( V_7 ) ;
F_13 ( & V_7 -> V_3 ) ;
V_7 -> V_20 = 0 ;
if ( V_21 )
V_22 = V_21 ;
if ( V_22 ) {
F_14 (slave_mnt, &mnt->mnt_slave_list, mnt_slave)
V_23 -> V_18 = V_22 ;
F_15 ( & V_7 -> V_6 , & V_22 -> V_5 ) ;
F_16 ( & V_7 -> V_5 , V_22 -> V_5 . V_24 ) ;
F_17 ( & V_7 -> V_5 ) ;
} else {
struct V_25 * V_2 = & V_7 -> V_5 ;
while ( ! F_11 ( V_2 ) ) {
V_23 = F_18 ( V_2 ,
struct V_1 , V_6 ) ;
F_13 ( & V_23 -> V_6 ) ;
V_23 -> V_18 = NULL ;
}
}
V_7 -> V_18 = V_22 ;
F_19 ( V_7 ) ;
return 0 ;
}
void F_20 ( struct V_1 * V_7 , int type )
{
if ( type == V_26 ) {
F_21 ( V_7 ) ;
return;
}
F_9 ( V_7 ) ;
if ( type != V_27 ) {
F_13 ( & V_7 -> V_6 ) ;
V_7 -> V_18 = NULL ;
if ( type == V_28 )
V_7 -> V_29 |= V_30 ;
else
V_7 -> V_29 &= ~ V_30 ;
}
}
static struct V_1 * F_22 ( struct V_1 * V_15 ,
struct V_1 * V_31 )
{
if ( ! F_23 ( V_15 ) && ! F_11 ( & V_15 -> V_5 ) )
return F_3 ( V_15 ) ;
while ( 1 ) {
struct V_1 * V_4 ;
struct V_1 * V_22 = V_15 -> V_18 ;
if ( V_22 == V_31 -> V_18 ) {
V_4 = F_1 ( V_15 ) ;
return ( ( V_4 == V_31 ) ? NULL : V_4 ) ;
} else if ( V_15 -> V_6 . V_4 != & V_22 -> V_5 )
return F_4 ( V_15 ) ;
V_15 = V_22 ;
}
}
static struct V_1 * F_24 ( struct V_1 * V_32 ,
struct V_1 * V_33 ,
struct V_1 * V_34 ,
int * type )
{
struct V_1 * V_35 = NULL ;
struct V_1 * V_36 = NULL ;
while ( V_33 != V_32 -> V_18 ) {
V_36 = V_33 ;
V_35 = V_34 ;
V_33 = V_33 -> V_18 ;
V_34 = V_34 -> V_18 ;
}
if ( V_36 ) {
do {
V_36 = F_1 ( V_36 ) ;
} while ( F_23 ( V_36 ) );
if ( V_32 == V_36 ) {
* type = V_37 ;
return V_35 ;
}
}
* type = V_38 ;
if ( F_10 ( V_32 ) )
* type |= V_37 ;
return V_34 ;
}
int F_25 ( struct V_1 * V_39 , struct V_8 * V_40 ,
struct V_1 * V_41 , struct V_25 * V_42 )
{
struct V_1 * V_15 , * V_43 ;
int V_44 = 0 ;
struct V_1 * V_45 = V_39 ;
struct V_1 * V_46 = V_41 ;
F_26 ( V_47 ) ;
F_26 ( V_48 ) ;
for ( V_15 = F_22 ( V_39 , V_39 ) ; V_15 ;
V_15 = F_22 ( V_15 , V_39 ) ) {
int type ;
struct V_1 * V_49 ;
if ( F_23 ( V_15 ) )
continue;
V_49 = F_24 ( V_15 , V_45 , V_46 , & type ) ;
if ( ! ( V_43 = F_27 ( V_49 , V_49 -> V_17 , type ) ) ) {
V_44 = - V_50 ;
F_16 ( V_42 , V_47 . V_24 ) ;
goto V_51;
}
if ( F_6 ( V_40 , V_15 -> V_17 ) ) {
F_28 ( V_15 , V_40 , V_43 ) ;
F_29 ( & V_43 -> V_52 , V_42 ) ;
} else {
F_29 ( & V_43 -> V_52 , & V_47 ) ;
}
V_45 = V_15 ;
V_46 = V_43 ;
}
V_51:
F_30 ( V_53 ) ;
while ( ! F_11 ( & V_47 ) ) {
V_43 = F_18 ( & V_47 , struct V_1 , V_52 ) ;
F_31 ( V_43 , 0 , & V_48 ) ;
}
F_32 ( V_53 ) ;
F_33 ( & V_48 ) ;
return V_44 ;
}
static inline int F_34 ( struct V_1 * V_7 , int V_54 )
{
int V_55 = F_35 ( V_7 ) - V_7 -> V_56 ;
return ( V_55 > V_54 ) ;
}
int F_36 ( struct V_1 * V_7 , int V_57 )
{
struct V_1 * V_15 , * V_43 ;
struct V_1 * V_58 = V_7 -> V_11 ;
int V_44 = 0 ;
if ( V_7 == V_58 )
return F_34 ( V_7 , V_57 ) ;
if ( ! F_11 ( & V_7 -> V_59 ) || F_34 ( V_7 , V_57 ) )
return 1 ;
for ( V_15 = F_22 ( V_58 , V_58 ) ; V_15 ;
V_15 = F_22 ( V_15 , V_58 ) ) {
V_43 = F_37 ( V_15 , V_7 -> V_12 , 0 ) ;
if ( V_43 && F_11 ( & V_43 -> V_59 ) &&
( V_44 = F_34 ( V_43 , 1 ) ) )
break;
}
return V_44 ;
}
static void F_38 ( struct V_1 * V_7 )
{
struct V_1 * V_58 = V_7 -> V_11 ;
struct V_1 * V_15 ;
F_39 ( V_58 == V_7 ) ;
for ( V_15 = F_22 ( V_58 , V_58 ) ; V_15 ;
V_15 = F_22 ( V_15 , V_58 ) ) {
struct V_1 * V_43 = F_37 ( V_15 ,
V_7 -> V_12 , 0 ) ;
if ( V_43 && F_11 ( & V_43 -> V_59 ) )
F_40 ( & V_43 -> V_52 , & V_7 -> V_52 ) ;
}
}
int F_41 ( struct V_25 * V_60 )
{
struct V_1 * V_7 ;
F_14 (mnt, list, mnt_hash)
F_38 ( V_7 ) ;
return 0 ;
}
