static inline void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 =
F_2 ( V_2 , struct V_3 , V_2 ) ;
V_4 -> V_5 ( V_4 , V_4 -> V_6 ) ;
}
static inline void F_3 ( struct V_7 * V_8 ,
enum V_9 V_10 )
{
struct V_3 * V_4 = F_2 ( V_8 ,
struct V_3 , V_7 ) ;
V_4 -> V_6 = V_10 ;
F_4 ( & V_4 -> V_2 ) ;
}
static int F_5 ( struct V_11 * V_12 )
{
struct V_13 * V_14 = V_12 -> V_15 ;
if ( F_6 ( V_14 -> V_16 , V_17 ,
NULL , NULL ) != V_18 )
return - V_19 ;
return 0 ;
}
static int F_7 ( struct V_11 * V_12 , int V_20 , T_1 * V_21 )
{
struct V_13 * V_14 = V_12 -> V_15 ;
union V_22 V_23 = { V_24 } ;
struct V_25 args = { 1 , & V_23 } ;
unsigned long long V_26 ;
T_2 V_27 ;
V_23 . integer . V_28 = V_20 ;
V_27 = F_8 ( V_14 -> V_16 , L_1 , & args , & V_26 ) ;
if ( F_9 ( V_27 ) )
return - V_19 ;
* V_21 = V_26 ;
return 0 ;
}
static int F_10 ( struct V_11 * V_12 , int V_20 , T_1 V_29 )
{
struct V_13 * V_14 = V_12 -> V_15 ;
unsigned long long V_21 ;
union V_22 V_30 [ 2 ] ;
struct V_25 args = { 2 , V_30 } ;
V_30 [ 0 ] . type = V_24 ;
V_30 [ 0 ] . integer . V_28 = V_20 ;
V_30 [ 1 ] . type = V_24 ;
V_30 [ 1 ] . integer . V_28 = V_29 ;
if ( F_8 ( V_14 -> V_16 , L_2 , & args , & V_21 ) != V_18 )
return - V_19 ;
return 0 ;
}
static int F_11 ( const struct V_31 * V_32 )
{
V_33 . V_34 = * ( (union V_35 * ) V_32 -> V_36 ) ;
F_12 ( L_3 , V_32 -> V_37 ) ;
return 1 ;
}
static void F_13 ( struct V_3 * V_8 , enum V_9 V_28 )
{
struct V_13 * V_14 = V_33 . V_15 ;
unsigned long long V_21 ;
union V_22 V_30 [ 1 ] ;
struct V_25 args = { 1 , V_30 } ;
V_30 [ 0 ] . type = V_24 ;
V_30 [ 0 ] . integer . V_28 = ! ! V_28 ;
F_8 ( V_14 -> V_16 , L_4 , & args , & V_21 ) ;
}
static T_2
F_14 ( struct V_38 * V_39 , void * V_40 )
{
if ( V_39 -> type == V_41 ) {
struct V_42 * V_43 ;
T_3 * V_44 = V_40 ;
V_43 = & V_39 -> V_4 . V_45 ;
* V_44 = V_43 -> V_46 [ 0 ] ;
}
return V_18 ;
}
static void F_15 ( struct V_13 * V_47 )
{
T_2 V_27 ;
V_27 = F_16 ( V_47 -> V_16 , V_48 ,
F_14 , & V_33 . V_43 ) ;
if ( F_9 ( V_27 ) )
F_17 (KERN_DEBUG DRIVER_NAME L_5 ) ;
}
static bool F_18 ( unsigned char V_4 , unsigned char V_49 ,
struct V_50 * V_51 )
{
static bool V_52 ;
if ( V_49 & V_53 )
return false ;
if ( V_4 == 0xe0 ) {
V_52 = true ;
return true ;
} else if ( F_19 ( V_52 ) ) {
V_52 = false ;
switch ( V_4 ) {
case V_54 :
case V_55 :
case V_56 :
case V_57 :
return true ;
default:
F_20 ( V_51 , 0xe0 , 0 ) ;
return false ;
}
}
return false ;
}
static int F_21 ( struct V_13 * V_47 )
{
int V_21 ;
if ( ! V_47 )
return - V_19 ;
V_33 . V_15 = V_47 ;
V_33 . V_58 = F_5 ;
V_33 . V_59 = F_7 ;
V_33 . V_60 = F_10 ;
strcpy ( F_22 ( V_47 ) , V_61 ) ;
strcpy ( F_23 ( V_47 ) , V_62 ) ;
V_47 -> V_36 = & V_33 ;
F_15 ( V_47 ) ;
if ( V_33 . V_34 . V_63 && V_33 . V_34 . V_64 && V_33 . V_34 . V_65 ) {
F_12 ( L_6 ,
V_33 . V_34 . V_63 , V_33 . V_34 . V_64 , V_33 . V_34 . V_65 ) ;
} else if ( F_24 ( V_66 ) == 0 ) {
F_12 ( L_7 ) ;
V_33 . V_34 = V_67 ;
}
V_21 = F_25 ( & V_33 ) ;
if ( V_21 )
return V_21 ;
if ( strstr ( F_26 ( & V_47 -> V_14 ) , L_8 ) )
F_27 ( F_18 ) ;
F_28 ( & V_68 . V_2 , F_1 ) ;
V_21 = F_29 ( NULL , & V_68 . V_7 ) ;
if ( V_21 ) {
F_30 ( & V_33 ) ;
F_31 ( & V_33 ) ;
F_32 ( & V_68 . V_2 ) ;
return V_21 ;
}
return V_21 ;
}
static int F_33 ( struct V_13 * V_47 )
{
if ( ! V_47 )
return - V_19 ;
F_34 ( F_18 ) ;
F_30 ( & V_33 ) ;
F_31 ( & V_33 ) ;
F_35 ( & V_68 . V_7 ) ;
F_32 ( & V_68 . V_2 ) ;
return F_36 ( & V_33 ) ;
}
static int F_37 ( struct V_47 * V_14 )
{
F_31 ( & V_33 ) ;
return 0 ;
}
static int F_38 ( struct V_47 * V_14 )
{
F_39 ( & V_33 ) ;
return 0 ;
}
