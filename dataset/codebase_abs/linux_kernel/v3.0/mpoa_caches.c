static T_1 * F_1 ( T_2 V_1 ,
struct V_2 * V_3 )
{
T_1 * V_4 ;
F_2 ( & V_3 -> V_5 ) ;
V_4 = V_3 -> V_6 ;
while ( V_4 != NULL ) {
if ( V_4 -> V_7 . V_8 == V_1 ) {
F_3 ( & V_4 -> V_9 ) ;
F_4 ( & V_3 -> V_5 ) ;
return V_4 ;
}
V_4 = V_4 -> V_10 ;
}
F_4 ( & V_3 -> V_5 ) ;
return NULL ;
}
static T_1 * F_5 ( T_2 V_1 ,
struct V_2 * V_3 ,
T_2 V_11 )
{
T_1 * V_4 ;
F_2 ( & V_3 -> V_5 ) ;
V_4 = V_3 -> V_6 ;
while ( V_4 != NULL ) {
if ( ( V_4 -> V_7 . V_8 & V_11 ) == ( V_1 & V_11 ) ) {
F_3 ( & V_4 -> V_9 ) ;
F_4 ( & V_3 -> V_5 ) ;
return V_4 ;
}
V_4 = V_4 -> V_10 ;
}
F_4 ( & V_3 -> V_5 ) ;
return NULL ;
}
static T_1 * F_6 ( struct V_12 * V_13 ,
struct V_2 * V_3 )
{
T_1 * V_4 ;
F_2 ( & V_3 -> V_5 ) ;
V_4 = V_3 -> V_6 ;
while ( V_4 != NULL ) {
if ( V_4 -> V_14 == V_13 ) {
F_3 ( & V_4 -> V_9 ) ;
F_4 ( & V_3 -> V_5 ) ;
return V_4 ;
}
V_4 = V_4 -> V_10 ;
}
F_4 ( & V_3 -> V_5 ) ;
return NULL ;
}
static T_1 * F_7 ( T_2 V_1 ,
struct V_2 * V_3 )
{
T_1 * V_4 = F_8 ( sizeof( T_1 ) , V_15 ) ;
if ( V_4 == NULL ) {
F_9 ( L_1 ) ;
return NULL ;
}
F_10 ( L_2 , & V_1 ) ;
F_11 ( & V_4 -> V_9 , 1 ) ;
F_10 ( L_3 ) ;
F_12 ( & V_3 -> V_5 ) ;
V_4 -> V_10 = V_3 -> V_6 ;
V_4 -> V_16 = NULL ;
if ( V_3 -> V_6 != NULL )
V_3 -> V_6 -> V_16 = V_4 ;
V_3 -> V_6 = V_4 ;
memcpy ( V_4 -> V_17 , V_3 -> V_18 , V_19 ) ;
V_4 -> V_7 . V_8 = V_1 ;
F_13 ( & ( V_4 -> V_20 ) ) ;
V_4 -> V_21 = V_3 -> V_22 . V_23 ;
V_4 -> V_24 = 1 ;
V_4 -> V_25 = V_26 ;
V_4 -> V_7 . V_27 = V_28 ;
F_3 ( & V_4 -> V_9 ) ;
F_14 ( & V_3 -> V_5 ) ;
F_10 ( L_4 ) ;
return V_4 ;
}
static int F_15 ( T_1 * V_4 , struct V_2 * V_29 )
{
struct V_30 * V_31 ;
struct V_32 V_33 ;
V_4 -> V_24 ++ ;
if ( V_4 -> V_25 == V_34 && V_4 -> V_14 != NULL )
return V_35 ;
if ( V_4 -> V_25 == V_36 ) {
if ( V_4 -> V_24 > V_29 -> V_22 . V_37 ) {
V_33 . type = V_38 ;
V_33 . V_39 . V_40 = V_4 -> V_7 ;
memcpy ( V_33 . V_41 , V_29 -> V_18 , V_19 ) ;
V_31 = F_16 ( V_4 -> V_7 . V_8 ) ;
if ( V_31 != NULL )
V_33 . V_31 = V_31 -> V_31 ;
F_17 ( & V_33 , V_29 ) ;
F_13 ( & ( V_4 -> V_42 ) ) ;
V_4 -> V_25 = V_43 ;
}
if ( V_4 -> V_14 != NULL )
return V_35 ;
return V_44 ;
}
if ( V_4 -> V_25 == V_43 && V_4 -> V_14 != NULL )
return V_35 ;
if ( V_4 -> V_24 > V_29 -> V_22 . V_37 &&
V_4 -> V_25 == V_26 ) {
F_10 ( L_5 ,
V_29 -> V_45 -> V_46 , & V_4 -> V_7 . V_8 ) ;
V_4 -> V_25 = V_43 ;
V_33 . type = V_38 ;
memcpy ( V_33 . V_41 , V_29 -> V_18 , V_19 ) ;
V_33 . V_39 . V_40 = V_4 -> V_7 ;
V_31 = F_16 ( V_4 -> V_7 . V_8 ) ;
if ( V_31 != NULL )
V_33 . V_31 = V_31 -> V_31 ;
F_17 ( & V_33 , V_29 ) ;
F_13 ( & ( V_4 -> V_42 ) ) ;
}
return V_44 ;
}
static void F_18 ( T_1 * V_4 )
{
if ( F_19 ( & V_4 -> V_9 ) ) {
memset ( V_4 , 0 , sizeof( T_1 ) ) ;
F_20 ( V_4 ) ;
}
}
static void F_21 ( T_1 * V_4 ,
struct V_2 * V_3 )
{
struct V_12 * V_13 ;
struct V_32 V_33 ;
V_13 = V_4 -> V_14 ;
F_10 ( L_6 ,
& V_4 -> V_7 . V_8 ) ;
if ( V_4 -> V_16 != NULL )
V_4 -> V_16 -> V_10 = V_4 -> V_10 ;
else
V_3 -> V_6 = V_4 -> V_10 ;
if ( V_4 -> V_10 != NULL )
V_4 -> V_10 -> V_16 = V_4 -> V_16 ;
V_3 -> V_47 -> V_48 ( V_4 ) ;
if ( V_3 -> V_6 == NULL && V_3 -> V_49 == NULL ) {
V_33 . type = V_50 ;
F_17 ( & V_33 , V_3 ) ;
}
if ( V_13 != NULL ) {
T_3 * V_51 = V_3 -> V_52 -> V_53 ( V_13 ,
V_3 ) ;
if ( V_51 != NULL ) {
V_3 -> V_52 -> V_48 ( V_51 ) ;
return;
}
F_22 ( V_13 , - V_54 ) ;
}
}
static void F_23 ( struct V_2 * V_3 )
{
T_1 * V_4 , * V_55 ;
struct V_56 V_57 ;
F_13 ( & V_57 ) ;
F_12 ( & V_3 -> V_5 ) ;
V_4 = V_3 -> V_6 ;
while ( V_4 != NULL ) {
V_4 -> V_24 = 0 ;
V_55 = V_4 -> V_10 ;
if ( ( V_57 . V_58 - V_4 -> V_20 . V_58 )
> V_4 -> V_7 . V_27 ) {
F_10 ( L_7 ,
& V_4 -> V_7 . V_8 ) ;
V_3 -> V_47 -> V_59 ( V_4 , V_3 ) ;
}
V_4 = V_55 ;
}
F_14 ( & V_3 -> V_5 ) ;
}
static void F_24 ( struct V_2 * V_3 )
{
struct V_30 * V_31 ;
T_1 * V_4 ;
struct V_56 V_57 ;
struct V_32 V_33 ;
F_13 ( & V_57 ) ;
F_2 ( & V_3 -> V_5 ) ;
V_4 = V_3 -> V_6 ;
while ( V_4 != NULL ) {
if ( V_4 -> V_25 == V_43 ) {
if ( ( V_57 . V_58 - V_4 -> V_60 . V_58 ) <
V_3 -> V_22 . V_61 ) {
V_4 = V_4 -> V_10 ;
continue;
}
if ( ( V_57 . V_58 - V_4 -> V_42 . V_58 ) >
V_4 -> V_21 ) {
V_4 -> V_21 = V_62 * ( V_4 -> V_21 ) ;
if ( V_4 -> V_21 > V_3 -> V_22 . V_63 ) {
F_13 ( & ( V_4 -> V_60 ) ) ;
V_4 -> V_21 = V_3 -> V_22 . V_23 ;
V_4 = V_4 -> V_10 ;
continue;
}
memset ( & ( V_4 -> V_60 ) , 0 , sizeof( struct V_56 ) ) ;
V_33 . type = V_64 ;
memcpy ( V_33 . V_41 , V_3 -> V_18 , V_19 ) ;
V_33 . V_39 . V_40 = V_4 -> V_7 ;
V_31 = F_16 ( V_4 -> V_7 . V_8 ) ;
if ( V_31 != NULL )
V_33 . V_31 = V_31 -> V_31 ;
F_17 ( & V_33 , V_3 ) ;
F_13 ( & ( V_4 -> V_42 ) ) ;
}
}
V_4 = V_4 -> V_10 ;
}
F_4 ( & V_3 -> V_5 ) ;
}
static void F_25 ( struct V_2 * V_3 )
{
struct V_56 V_57 ;
struct T_1 * V_4 = V_3 -> V_6 ;
F_26 ( L_8 ) ;
F_13 ( & V_57 ) ;
F_2 ( & V_3 -> V_5 ) ;
while ( V_4 != NULL ) {
if ( V_4 -> V_25 == V_34 ) {
if ( ! ( V_4 -> V_65 ) )
V_4 -> V_65 = ( 2 * ( V_4 -> V_7 . V_27 ) ) / 3 ;
if ( ( V_57 . V_58 - V_4 -> V_42 . V_58 ) >
V_4 -> V_65 ) {
F_10 ( L_9 ) ;
V_4 -> V_25 = V_36 ;
}
}
V_4 = V_4 -> V_10 ;
}
F_4 ( & V_3 -> V_5 ) ;
}
static void F_27 ( struct V_2 * V_29 )
{
F_28 ( & V_29 -> V_5 ) ;
while ( V_29 -> V_6 != NULL )
V_29 -> V_47 -> V_59 ( V_29 -> V_6 , V_29 ) ;
F_29 ( & V_29 -> V_5 ) ;
}
static T_3 * F_30 ( T_2 V_66 ,
struct V_2 * V_29 )
{
T_3 * V_4 ;
F_31 ( & V_29 -> V_67 ) ;
V_4 = V_29 -> V_49 ;
while ( V_4 != NULL ) {
if ( V_4 -> V_7 . V_66 == V_66 ) {
F_3 ( & V_4 -> V_9 ) ;
F_32 ( & V_29 -> V_67 ) ;
return V_4 ;
}
V_4 = V_4 -> V_10 ;
}
F_32 ( & V_29 -> V_67 ) ;
return NULL ;
}
static T_3 * F_33 ( T_2 V_68 , struct V_2 * V_29 )
{
unsigned long V_69 ;
T_3 * V_4 ;
F_34 ( & V_29 -> V_67 , V_69 ) ;
V_4 = V_29 -> V_49 ;
while ( V_4 != NULL ) {
if ( V_4 -> V_7 . V_68 == V_68 ) {
F_3 ( & V_4 -> V_9 ) ;
F_35 ( & V_29 -> V_67 , V_69 ) ;
return V_4 ;
}
V_4 = V_4 -> V_10 ;
}
F_35 ( & V_29 -> V_67 , V_69 ) ;
return NULL ;
}
static T_3 * F_36 ( struct V_12 * V_13 ,
struct V_2 * V_29 )
{
unsigned long V_69 ;
T_3 * V_4 ;
F_34 ( & V_29 -> V_67 , V_69 ) ;
V_4 = V_29 -> V_49 ;
while ( V_4 != NULL ) {
if ( V_4 -> V_14 == V_13 ) {
F_3 ( & V_4 -> V_9 ) ;
F_35 ( & V_29 -> V_67 , V_69 ) ;
return V_4 ;
}
V_4 = V_4 -> V_10 ;
}
F_35 ( & V_29 -> V_67 , V_69 ) ;
return NULL ;
}
static T_3 * F_37 ( T_2 V_70 ,
struct V_2 * V_29 )
{
T_3 * V_4 ;
F_31 ( & V_29 -> V_67 ) ;
V_4 = V_29 -> V_49 ;
while ( V_4 != NULL ) {
if ( V_4 -> V_71 == V_70 ) {
F_3 ( & V_4 -> V_9 ) ;
F_32 ( & V_29 -> V_67 ) ;
return V_4 ;
}
V_4 = V_4 -> V_10 ;
}
F_32 ( & V_29 -> V_67 ) ;
return NULL ;
}
static void F_38 ( T_3 * V_4 )
{
if ( F_19 ( & V_4 -> V_9 ) ) {
memset ( V_4 , 0 , sizeof( T_3 ) ) ;
F_20 ( V_4 ) ;
}
}
static void F_39 ( T_3 * V_4 ,
struct V_2 * V_3 )
{
struct V_12 * V_13 ;
struct V_32 V_33 ;
V_13 = V_4 -> V_14 ;
F_10 ( L_10 ) ;
if ( V_4 -> V_16 != NULL )
V_4 -> V_16 -> V_10 = V_4 -> V_10 ;
else
V_3 -> V_49 = V_4 -> V_10 ;
if ( V_4 -> V_10 != NULL )
V_4 -> V_10 -> V_16 = V_4 -> V_16 ;
V_3 -> V_52 -> V_48 ( V_4 ) ;
if ( V_3 -> V_6 == NULL && V_3 -> V_49 == NULL ) {
V_33 . type = V_50 ;
F_17 ( & V_33 , V_3 ) ;
}
if ( V_13 != NULL ) {
T_1 * V_72 = V_3 -> V_47 -> V_53 ( V_13 , V_3 ) ;
if ( V_72 != NULL ) {
V_3 -> V_47 -> V_48 ( V_72 ) ;
return;
}
F_22 ( V_13 , - V_54 ) ;
}
}
static T_3 * F_40 ( struct V_32 * V_33 ,
struct V_2 * V_3 )
{
T_3 * V_4 = F_8 ( sizeof( T_3 ) , V_15 ) ;
if ( V_4 == NULL ) {
F_9 ( L_11 ) ;
return NULL ;
}
F_10 ( L_12 ,
& V_33 -> V_39 . V_73 . V_74 ) ;
F_11 ( & V_4 -> V_9 , 1 ) ;
F_10 ( L_13 ) ;
F_28 ( & V_3 -> V_67 ) ;
V_4 -> V_10 = V_3 -> V_49 ;
V_4 -> V_16 = NULL ;
if ( V_3 -> V_49 != NULL )
V_3 -> V_49 -> V_16 = V_4 ;
V_3 -> V_49 = V_4 ;
memcpy ( V_4 -> V_17 , V_3 -> V_18 , V_19 ) ;
V_4 -> V_7 = V_33 -> V_39 . V_73 ;
F_13 ( & ( V_4 -> V_20 ) ) ;
V_4 -> V_25 = V_75 ;
F_10 ( L_14 ,
F_41 ( V_4 -> V_7 . V_66 ) ) ;
F_10 ( L_15 , & V_4 -> V_7 . V_76 ) ;
F_3 ( & V_4 -> V_9 ) ;
F_29 ( & V_3 -> V_67 ) ;
F_10 ( L_16 ) ;
return V_4 ;
}
static void F_42 ( T_3 * V_4 , T_4 V_27 )
{
F_13 ( & ( V_4 -> V_20 ) ) ;
V_4 -> V_25 = V_75 ;
V_4 -> V_7 . V_27 = V_27 ;
}
static void F_43 ( struct V_2 * V_3 )
{
T_3 * V_4 , * V_55 ;
struct V_56 V_57 ;
struct V_32 V_33 ;
F_13 ( & V_57 ) ;
F_28 ( & V_3 -> V_67 ) ;
V_4 = V_3 -> V_49 ;
while ( V_4 != NULL ) {
V_55 = V_4 -> V_10 ;
if ( ( V_57 . V_58 - V_4 -> V_20 . V_58 )
> V_4 -> V_7 . V_27 ) {
V_33 . type = V_77 ;
V_33 . V_39 . V_73 = V_4 -> V_7 ;
F_10 ( L_17 ,
F_41 ( V_4 -> V_7 . V_66 ) ) ;
F_17 ( & V_33 , V_3 ) ;
V_3 -> V_52 -> V_59 ( V_4 , V_3 ) ;
}
V_4 = V_55 ;
}
F_29 ( & V_3 -> V_67 ) ;
}
static void F_44 ( struct V_2 * V_29 )
{
F_28 ( & V_29 -> V_67 ) ;
while ( V_29 -> V_49 != NULL )
V_29 -> V_52 -> V_59 ( V_29 -> V_49 , V_29 ) ;
F_29 ( & V_29 -> V_67 ) ;
}
void F_45 ( struct V_2 * V_29 )
{
V_29 -> V_47 = & V_78 ;
V_29 -> V_52 = & V_79 ;
}
