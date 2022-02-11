static int F_1 ( T_1 V_1 ,
T_1 V_2 ,
T_1 V_3 ,
T_2 V_4 ,
void * V_5 , struct V_6 * V_7 )
{
int V_8 ;
T_1 V_9 ;
struct V_6 V_10 ;
struct V_11 * V_12 ;
if ( ( V_2 & V_13 ) != 0 )
return V_14 ;
if ( ( V_2 & V_15 ) != 0 ) {
V_9 = V_16 ;
} else {
V_9 = F_2 () ;
if ( V_9 == V_16 )
return V_17 ;
}
V_10 = F_3 ( V_9 , V_1 ) ;
V_12 = F_4 ( sizeof( * V_12 ) , V_18 ) ;
if ( ! V_12 ) {
F_5 ( L_1 ) ;
return V_19 ;
}
V_12 -> V_20 = ( V_2 & V_21 ) ? true : false ;
V_12 -> V_2 = V_2 ;
V_12 -> V_4 = V_4 ;
V_12 -> V_5 = V_5 ;
V_12 -> V_3 = V_3 ;
V_8 = F_6 ( & V_12 -> V_22 ,
V_23 ,
V_10 ) ;
if ( V_8 != V_24 ) {
F_5 ( L_2 ,
V_10 . V_25 , V_10 . V_22 , V_8 ) ;
F_7 ( V_12 ) ;
return V_8 ;
}
* V_7 = F_8 ( & V_12 -> V_22 ) ;
return V_24 ;
}
static int F_9 ( T_1 V_9 ,
struct V_6 V_10 ,
T_1 * V_3 )
{
if ( V_9 == V_16 )
return V_14 ;
if ( V_9 == V_26 ) {
struct V_11 * V_27 ;
struct V_28 * V_22 ;
V_22 = F_10 ( V_10 ,
V_23 ) ;
if ( ! V_22 )
return V_14 ;
V_27 = F_11 ( V_22 , struct V_11 ,
V_22 ) ;
* V_3 = V_27 -> V_3 ;
F_12 ( V_22 ) ;
} else if ( V_9 == V_29 )
* V_3 = V_30 ;
else
* V_3 = F_13 ( V_9 ) ;
return V_24 ;
}
static void F_14 ( struct V_31 * V_32 )
{
struct V_33 * V_34 =
F_11 ( V_32 , struct V_33 , V_32 ) ;
V_34 -> V_12 -> V_4 ( V_34 -> V_12 -> V_5 , & V_34 -> V_35 ) ;
F_12 ( & V_34 -> V_12 -> V_22 ) ;
if ( V_34 -> V_36 )
F_15 ( & V_37 ) ;
F_7 ( V_34 ) ;
}
static int F_16 ( T_1 V_9 , struct V_38 * V_39 )
{
int V_40 ;
T_3 V_41 ;
T_1 V_42 ;
V_41 = F_17 ( V_39 ) ;
if ( V_39 -> V_43 . V_25 == V_29 )
return V_44 ;
if ( V_39 -> V_45 . V_25 != V_9 ) {
F_18 ( L_3 ,
V_9 , V_39 -> V_45 . V_25 , V_39 -> V_45 . V_22 ) ;
return V_46 ;
}
V_40 = F_9 ( V_9 , V_39 -> V_45 ,
& V_42 ) ;
if ( V_40 != V_24 ) {
F_5 ( L_4 ,
V_39 -> V_45 . V_25 , V_39 -> V_45 . V_22 ) ;
return V_40 ;
}
if ( V_39 -> V_43 . V_25 == V_26 ) {
struct V_11 * V_47 ;
struct V_28 * V_22 ;
if ( V_39 -> V_45 . V_25 == V_29 &&
V_39 -> V_43 . V_22 == V_48 ) {
return F_19 ( V_39 ) ;
}
V_22 = F_10 ( V_39 -> V_43 ,
V_23 ) ;
if ( ! V_22 ) {
F_18 ( L_5 ,
V_39 -> V_43 . V_25 , V_39 -> V_43 . V_22 ) ;
return V_49 ;
}
V_47 = F_11 ( V_22 , struct V_11 ,
V_22 ) ;
if ( F_20 ( V_42 ,
V_47 -> V_3 ) ) {
F_12 ( V_22 ) ;
return V_46 ;
}
if ( V_47 -> V_20 ||
V_39 -> V_45 . V_25 == V_26 ) {
struct V_33 * V_34 ;
if ( F_21 ( 1 , & V_37 )
== V_50 ) {
F_15 ( & V_37 ) ;
F_12 ( V_22 ) ;
return V_19 ;
}
V_34 = F_4 ( sizeof( * V_34 ) +
( T_3 ) V_39 -> V_51 , V_52 ) ;
if ( ! V_34 ) {
F_15 ( & V_37 ) ;
F_12 ( V_22 ) ;
return V_19 ;
}
V_34 -> V_36 = true ;
V_34 -> V_12 = V_47 ;
memcpy ( & V_34 -> V_35 , V_39 , V_41 ) ;
F_22 ( & V_34 -> V_32 , F_14 ) ;
F_23 ( & V_34 -> V_32 ) ;
V_40 = V_24 ;
} else {
V_40 = V_47 -> V_4 ( V_47 -> V_5 , V_39 ) ;
F_12 ( V_22 ) ;
if ( V_40 < V_24 )
return V_40 ;
}
} else {
struct V_38 * V_53 ;
if ( V_9 != V_39 -> V_43 . V_25 ) {
if ( F_20 ( V_42 ,
F_13
( V_39 -> V_43 . V_25 ) ) ) {
return V_46 ;
} else if ( F_24 ( V_9 ) ) {
F_18 ( L_6 ,
V_9 , V_39 -> V_43 . V_25 ) ;
return V_44 ;
}
}
V_53 = F_4 ( V_41 , V_18 ) ;
if ( V_53 == NULL )
return V_19 ;
memcpy ( V_53 , V_39 , V_41 ) ;
V_40 = F_25 ( V_39 -> V_43 . V_25 , V_53 ) ;
if ( V_40 < V_24 ) {
F_7 ( V_53 ) ;
return V_40 ;
}
}
return ( int ) V_41 ;
}
static int F_26 ( struct V_38 * V_39 )
{
int V_40 ;
struct V_28 * V_22 ;
V_22 = F_10 ( V_39 -> V_45 ,
V_23 ) ;
if ( ! V_22 )
return V_54 ;
V_40 = F_27 ( V_39 ) ;
F_12 ( V_22 ) ;
return V_40 ;
}
int F_28 ( T_1 V_9 ,
struct V_38 * V_39 , bool V_55 )
{
int V_40 ;
enum V_56 V_57 ;
F_29 ( sizeof( struct V_38 ) != 24 ) ;
if ( F_17 ( V_39 ) > V_58 ) {
F_18 ( L_7 ,
( unsigned long long ) V_39 -> V_51 ) ;
return V_14 ;
}
V_40 = V_56 ( & V_39 -> V_45 , & V_39 -> V_43 , V_55 , & V_57 ) ;
if ( V_40 < V_24 ) {
F_18 ( L_8 ,
V_39 -> V_45 . V_25 , V_39 -> V_43 . V_25 , V_40 ) ;
return V_40 ;
}
if ( V_59 == V_57 ) {
if ( V_16 == V_9 )
V_9 = V_26 ;
return F_16 ( V_9 , V_39 ) ;
}
if ( V_60 == V_57 )
return F_26 ( V_39 ) ;
F_5 ( L_9 , V_57 ) ;
return V_44 ;
}
int F_30 ( struct V_38 * V_39 )
{
struct V_28 * V_22 ;
struct V_11 * V_47 ;
V_22 = F_10 ( V_39 -> V_43 ,
V_23 ) ;
if ( ! V_22 ) {
F_18 ( L_10 ,
V_39 -> V_43 . V_25 , V_39 -> V_43 . V_22 ) ;
return V_54 ;
}
V_47 = F_11 ( V_22 , struct V_11 , V_22 ) ;
if ( V_47 -> V_20 ) {
struct V_33 * V_34 ;
V_34 = F_4 ( sizeof( * V_34 ) + ( T_3 ) V_39 -> V_51 ,
V_52 ) ;
if ( ! V_34 ) {
F_12 ( V_22 ) ;
return V_19 ;
}
V_34 -> V_36 = false ;
V_34 -> V_12 = V_47 ;
memcpy ( & V_34 -> V_35 , V_39 , F_17 ( V_39 ) ) ;
F_22 ( & V_34 -> V_32 , F_14 ) ;
F_23 ( & V_34 -> V_32 ) ;
} else {
V_47 -> V_4 ( V_47 -> V_5 , V_39 ) ;
F_12 ( V_22 ) ;
}
return V_24 ;
}
int F_31 ( T_1 V_1 ,
T_1 V_2 ,
T_1 V_3 ,
T_2 V_4 ,
void * V_5 ,
struct V_6 * V_7 )
{
if ( V_7 == NULL )
return V_14 ;
if ( V_4 == NULL ) {
F_18 ( L_11 ) ;
return V_14 ;
}
if ( V_3 & ~ V_61 )
return V_14 ;
return F_1 ( V_1 , V_2 , V_3 , V_4 ,
V_5 , V_7 ) ;
}
int F_32 ( T_1 V_1 ,
T_1 V_2 ,
T_2 V_4 ,
void * V_5 ,
struct V_6 * V_7 )
{
return F_31 (
V_1 , V_2 ,
V_62 ,
V_4 , V_5 ,
V_7 ) ;
}
int F_33 ( struct V_6 V_10 )
{
struct V_11 * V_12 ;
struct V_28 * V_22 ;
V_22 = F_10 ( V_10 , V_23 ) ;
if ( ! V_22 ) {
F_18 ( L_12 ,
V_10 . V_25 , V_10 . V_22 ) ;
return V_63 ;
}
V_12 = F_11 ( V_22 , struct V_11 , V_22 ) ;
F_12 ( & V_12 -> V_22 ) ;
F_34 ( & V_12 -> V_22 ) ;
F_7 ( V_12 ) ;
return V_24 ;
}
int F_35 ( struct V_38 * V_35 )
{
if ( V_35 == NULL )
return V_14 ;
return F_28 ( V_16 , V_35 , false ) ;
}
