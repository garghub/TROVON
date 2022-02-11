static struct V_1 * F_1 ( struct V_2 * V_3 , int V_4 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
struct V_7 * V_8 ;
struct V_9 * V_10 ;
struct V_1 * V_1 = NULL ;
V_8 = V_6 -> V_11 + F_3 ( V_4 ) ;
F_4 ( & V_6 -> V_12 ) ;
F_5 (i, head, i_dir_hash) {
F_6 ( V_10 -> V_13 . V_14 != V_3 ) ;
if ( V_10 -> V_4 != V_4 )
continue;
V_1 = F_7 ( & V_10 -> V_13 ) ;
if ( V_1 )
break;
}
F_8 ( & V_6 -> V_12 ) ;
return V_1 ;
}
static struct V_1 * F_9 ( struct V_2 * V_3 , T_1 V_15 , T_2 V_16 )
{
if ( F_2 ( V_3 ) -> V_17 . V_18 == V_19 )
return F_10 ( V_3 , V_16 ) ;
else {
if ( ( V_15 < V_20 ) || ( V_15 == V_21 ) )
return NULL ;
return F_11 ( V_3 , V_15 ) ;
}
}
static struct V_1 * F_12 ( struct V_2 * V_3 ,
T_1 V_15 , T_3 V_22 , T_2 V_16 )
{
struct V_1 * V_1 = F_9 ( V_3 , V_15 , V_16 ) ;
if ( V_1 && V_22 && ( V_1 -> V_23 != V_22 ) ) {
F_13 ( V_1 ) ;
V_1 = NULL ;
}
if ( V_1 == NULL && F_2 ( V_3 ) -> V_17 . V_18 == V_19 ) {
struct V_24 * V_25 = NULL ;
struct V_26 * V_27 ;
T_4 V_28 ;
int V_29 ;
F_14 ( F_2 ( V_3 ) , V_16 , & V_28 , & V_29 ) ;
V_25 = F_15 ( V_3 , V_28 ) ;
if ( ! V_25 ) {
F_16 ( V_3 , V_30 ,
L_1 ,
( V_31 ) V_28 ) ;
return V_1 ;
}
V_27 = (struct V_26 * ) V_25 -> V_32 ;
if ( F_17 ( V_27 [ V_29 ] . V_33 ) )
V_1 = NULL ;
else
V_1 = F_18 ( V_3 , & V_27 [ V_29 ] , V_16 ) ;
F_19 ( V_25 ) ;
}
return V_1 ;
}
static struct V_1 * F_20 ( struct V_2 * V_3 ,
T_1 V_15 , T_3 V_22 )
{
return F_12 ( V_3 , V_15 , V_22 , 0 ) ;
}
static int
F_21 ( struct V_1 * V_1 , T_5 * V_34 , int * V_35 ,
struct V_1 * V_36 )
{
int V_37 = * V_35 ;
struct V_5 * V_6 = F_2 ( V_1 -> V_14 ) ;
struct V_38 * V_39 = (struct V_38 * ) V_34 ;
T_2 V_16 ;
int type = V_40 ;
if ( V_36 ) {
if ( V_37 < V_41 ) {
* V_35 = V_41 ;
return V_42 ;
}
} else {
if ( V_37 < V_43 ) {
* V_35 = V_43 ;
return V_42 ;
}
}
V_16 = F_22 ( V_6 , V_1 ) ;
* V_35 = V_43 ;
V_39 -> V_44 = V_1 -> V_23 ;
V_39 -> V_45 = V_16 & 0xFFFFFFFF ;
V_39 -> V_46 = ( V_16 >> 32 ) & 0xFFFF ;
if ( V_36 ) {
V_16 = F_22 ( V_6 , V_36 ) ;
V_39 -> V_47 = ( V_16 >> 32 ) & 0xFFFF ;
V_39 -> V_48 = V_16 & 0xFFFFFFFF ;
V_39 -> V_49 = V_36 -> V_23 ;
type = V_50 ;
* V_35 = V_41 ;
}
return type ;
}
static struct V_51 * F_23 ( struct V_2 * V_3 , struct V_39 * V_39 ,
int V_52 , int V_53 )
{
return F_24 ( V_3 , V_39 , V_52 , V_53 ,
F_20 ) ;
}
static struct V_51 * F_25 ( struct V_2 * V_3 ,
struct V_39 * V_34 , int V_52 ,
int V_53 )
{
struct V_1 * V_1 = NULL ;
struct V_38 * V_39 = (struct V_38 * ) V_34 ;
T_2 V_16 ;
switch ( V_53 ) {
case V_40 :
if ( V_52 < V_43 )
return NULL ;
break;
case V_50 :
if ( V_52 < V_41 )
return NULL ;
break;
default:
return NULL ;
}
V_16 = V_39 -> V_46 ;
V_16 = ( V_16 << 32 ) | ( V_39 -> V_45 ) ;
V_1 = F_12 ( V_3 , 0 , V_39 -> V_44 , V_16 ) ;
return F_26 ( V_1 ) ;
}
static struct V_51 * F_27 ( struct V_2 * V_3 , struct V_39 * V_39 ,
int V_52 , int V_53 )
{
return F_28 ( V_3 , V_39 , V_52 , V_53 ,
F_20 ) ;
}
static struct V_51 * F_29 ( struct V_2 * V_3 ,
struct V_39 * V_34 , int V_52 ,
int V_53 )
{
struct V_1 * V_1 = NULL ;
struct V_38 * V_39 = (struct V_38 * ) V_34 ;
T_2 V_16 ;
if ( V_52 < V_41 )
return NULL ;
switch ( V_53 ) {
case V_50 :
V_16 = V_39 -> V_47 ;
V_16 = ( V_16 << 32 ) | ( V_39 -> V_48 ) ;
V_1 = F_12 ( V_3 , 0 , V_39 -> V_49 , V_16 ) ;
break;
}
return F_26 ( V_1 ) ;
}
static
struct V_1 * F_30 ( struct V_2 * V_3 , int V_54 )
{
int V_55 , V_56 ;
struct V_26 * V_27 ;
struct V_1 * V_36 = NULL ;
struct V_1 * V_57 = NULL ;
struct V_58 V_59 ;
struct V_5 * V_6 = F_2 ( V_3 ) ;
T_4 V_60 = F_31 ( V_6 , V_54 ) ;
struct V_24 * V_61 = F_15 ( V_3 , V_60 ) ;
if ( ! V_61 ) {
F_16 ( V_3 , V_30 ,
L_2 ) ;
return NULL ;
}
V_27 = (struct V_26 * ) V_61 -> V_32 ;
V_56 = F_32 ( V_6 , & V_27 [ 0 ] ) ;
V_55 = F_32 ( V_6 , & V_27 [ 1 ] ) ;
V_57 = F_1 ( V_3 , V_55 ) ;
if ( ! V_57 ) {
V_57 = F_33 ( V_3 ) ;
if ( ! V_57 ) {
F_19 ( V_61 ) ;
return V_36 ;
}
V_57 -> V_62 = F_34 ( V_3 , V_20 ) ;
F_35 ( V_57 , & V_27 [ 1 ] ) ;
F_36 ( V_57 ) -> V_16 = - 1 ;
}
if ( ! F_37 ( V_57 , V_56 , & V_59 ) )
V_36 = F_18 ( V_3 , V_59 . V_27 , V_59 . V_16 ) ;
F_19 ( V_61 ) ;
F_13 ( V_57 ) ;
return V_36 ;
}
static struct V_51 * F_38 ( struct V_51 * V_63 )
{
struct V_2 * V_3 = V_63 -> V_64 ;
struct V_24 * V_25 = NULL ;
struct V_26 * V_27 ;
struct V_1 * V_65 = NULL ;
struct V_5 * V_6 = F_2 ( V_3 ) ;
if ( ! F_39 ( V_63 -> V_66 , & V_25 , & V_27 ) ) {
int V_54 = F_32 ( V_6 , V_27 ) ;
V_65 = F_1 ( V_3 , V_54 ) ;
if ( ! V_65 && V_6 -> V_17 . V_18 == V_19 )
V_65 = F_30 ( V_3 , V_54 ) ;
}
F_19 ( V_25 ) ;
return F_26 ( V_65 ) ;
}
