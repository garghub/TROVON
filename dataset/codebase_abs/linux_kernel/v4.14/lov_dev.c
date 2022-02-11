static void * F_1 ( const struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 ;
V_6 = F_2 ( V_7 , V_8 ) ;
if ( ! V_6 )
V_6 = F_3 ( - V_9 ) ;
return V_6 ;
}
static void F_4 ( const struct V_1 * V_2 ,
struct V_3 * V_4 , void * V_10 )
{
struct V_5 * V_6 = V_10 ;
F_5 ( V_7 , V_6 ) ;
}
static void * F_6 ( const struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_11 * V_6 ;
V_6 = F_2 ( V_12 , V_8 ) ;
if ( ! V_6 )
V_6 = F_3 ( - V_9 ) ;
return V_6 ;
}
static void F_7 ( const struct V_1 * V_2 ,
struct V_3 * V_4 , void * V_10 )
{
struct V_11 * V_6 = V_10 ;
F_5 ( V_12 , V_6 ) ;
}
static struct V_13 * F_8 ( const struct V_14 * V_15 ,
struct V_13 * V_16 )
{
int V_17 ;
struct V_18 * V_19 = F_9 ( V_16 ) ;
F_10 ( V_19 -> V_20 ) ;
if ( ! V_19 -> V_21 )
return NULL ;
F_11 (ld, i) {
struct V_22 * V_23 ;
V_23 = V_19 -> V_21 [ V_17 ] ;
if ( V_23 ) {
F_12 ( V_15 , F_13 ( V_23 ) ) ;
V_19 -> V_21 [ V_17 ] = NULL ;
}
}
return NULL ;
}
static int F_14 ( const struct V_14 * V_15 , struct V_13 * V_16 ,
const char * V_24 , struct V_13 * V_25 )
{
struct V_18 * V_19 = F_9 ( V_16 ) ;
int V_17 ;
int V_26 = 0 ;
F_10 ( V_16 -> V_27 ) ;
if ( ! V_19 -> V_21 )
return V_26 ;
F_11 (ld, i) {
struct V_22 * V_23 ;
struct V_28 * V_29 ;
struct V_30 * V_31 ;
V_31 = V_19 -> V_20 -> V_32 [ V_17 ] ;
if ( ! V_31 )
continue;
V_29 = F_15 ( V_15 , V_16 -> V_27 , & V_33 ,
V_31 -> V_34 -> V_35 ) ;
if ( F_16 ( V_29 ) ) {
V_26 = F_17 ( V_29 ) ;
break;
}
V_23 = F_18 ( V_29 ) ;
V_19 -> V_21 [ V_17 ] = V_23 ;
}
if ( V_26 )
F_8 ( V_15 , V_16 ) ;
else
V_19 -> V_36 |= V_37 ;
return V_26 ;
}
static struct V_13 * F_19 ( const struct V_14 * V_15 ,
struct V_13 * V_16 )
{
struct V_18 * V_19 = F_9 ( V_16 ) ;
F_20 ( F_21 ( V_16 ) ) ;
F_22 ( V_19 -> V_21 ) ;
F_22 ( V_19 ) ;
return NULL ;
}
static void F_23 ( const struct V_14 * V_15 , struct V_13 * V_38 ,
T_1 V_39 )
{
struct V_18 * V_19 = F_9 ( V_38 ) ;
if ( V_19 -> V_21 [ V_39 ] ) {
F_12 ( V_15 , F_13 ( V_19 -> V_21 [ V_39 ] ) ) ;
V_19 -> V_21 [ V_39 ] = NULL ;
}
}
static int F_24 ( const struct V_14 * V_15 , struct V_18 * V_38 )
{
int V_40 ;
T_1 V_41 ;
T_1 V_42 ;
V_40 = 0 ;
V_41 = V_38 -> V_20 -> V_43 ;
V_42 = V_38 -> V_44 ;
if ( V_42 < V_41 ) {
struct V_22 * * V_45 ;
const T_2 V_46 = sizeof( V_45 [ 0 ] ) ;
V_45 = F_25 ( V_41 , V_46 , V_8 ) ;
if ( V_45 ) {
if ( V_42 > 0 ) {
memcpy ( V_45 , V_38 -> V_21 , V_42 * V_46 ) ;
F_22 ( V_38 -> V_21 ) ;
}
V_38 -> V_21 = V_45 ;
V_38 -> V_44 = V_41 ;
} else {
V_40 = - V_9 ;
}
}
return V_40 ;
}
static int F_26 ( const struct V_14 * V_15 , struct V_13 * V_38 ,
T_1 V_39 )
{
struct V_47 * V_48 = V_38 -> V_49 ;
struct V_18 * V_19 = F_9 ( V_38 ) ;
struct V_30 * V_50 ;
struct V_22 * V_23 ;
struct V_28 * V_29 ;
int V_26 ;
F_27 ( V_48 ) ;
V_50 = V_48 -> V_51 . V_52 . V_32 [ V_39 ] ;
if ( ! V_50 -> V_34 -> V_53 ) {
F_28 ( L_1 , F_29 ( & V_50 -> V_54 ) ) ;
return - V_55 ;
}
V_26 = F_24 ( V_15 , V_19 ) ;
if ( V_26 == 0 && V_19 -> V_36 & V_37 ) {
F_10 ( V_38 -> V_27 ) ;
V_29 = F_15 ( V_15 , V_38 -> V_27 , & V_33 ,
V_50 -> V_34 -> V_35 ) ;
if ( ! F_16 ( V_29 ) ) {
V_23 = F_18 ( V_29 ) ;
V_19 -> V_21 [ V_39 ] = V_23 ;
} else {
F_28 ( L_2 , V_26 ,
F_29 ( & V_50 -> V_54 ) ) ;
F_23 ( V_15 , V_38 , V_39 ) ;
V_26 = F_17 ( V_29 ) ;
}
}
F_30 ( V_48 ) ;
return V_26 ;
}
static int F_31 ( const struct V_14 * V_15 ,
struct V_13 * V_16 , struct V_56 * V_57 )
{
struct V_47 * V_48 = V_16 -> V_49 ;
int V_58 ;
int V_26 ;
int V_59 ;
T_1 V_39 ;
F_27 ( V_48 ) ;
V_58 = V_57 -> V_60 ;
V_26 = F_32 ( V_16 -> V_49 , V_57 , & V_39 , & V_59 ) ;
if ( V_26 == 0 ) {
switch ( V_58 ) {
case V_61 :
case V_62 :
V_26 = F_26 ( V_15 , V_16 , V_39 ) ;
if ( V_26 != 0 )
F_33 ( V_16 -> V_49 , V_39 , NULL , 0 ) ;
break;
case V_63 :
F_23 ( V_15 , V_16 , V_39 ) ;
break;
}
}
F_30 ( V_48 ) ;
return V_26 ;
}
static struct V_13 * F_34 ( const struct V_14 * V_15 ,
struct V_64 * V_65 ,
struct V_56 * V_57 )
{
struct V_13 * V_16 ;
struct V_18 * V_19 ;
struct V_47 * V_48 ;
int V_26 ;
V_19 = F_35 ( sizeof( * V_19 ) , V_8 ) ;
if ( ! V_19 )
return F_3 ( - V_9 ) ;
F_36 ( & V_19 -> V_66 , V_65 ) ;
V_16 = F_37 ( V_19 ) ;
V_16 -> V_67 = & V_68 ;
V_48 = F_38 ( F_39 ( V_57 , 0 ) ) ;
F_10 ( V_48 ) ;
V_26 = F_40 ( V_48 , V_57 ) ;
if ( V_26 ) {
F_19 ( V_15 , V_16 ) ;
return F_3 ( V_26 ) ;
}
V_19 -> V_20 = & V_48 -> V_51 . V_52 ;
return V_16 ;
}
