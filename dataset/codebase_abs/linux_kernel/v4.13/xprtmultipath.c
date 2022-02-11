static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
if ( F_2 ( F_3 ( V_4 ) == NULL ) )
return;
F_4 ( & V_4 -> V_5 , & V_2 -> V_6 ) ;
F_5 () ;
if ( V_2 -> V_7 == 0 )
V_2 -> V_8 = V_4 -> V_9 ;
V_2 -> V_7 ++ ;
}
void F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
if ( V_4 == NULL )
return;
F_7 ( & V_2 -> V_10 ) ;
if ( ( V_2 -> V_8 == V_4 -> V_9 || V_2 -> V_8 == NULL ) &&
! F_8 ( V_2 , (struct V_11 * ) & V_4 -> V_12 ) )
F_1 ( V_2 , V_4 ) ;
F_9 ( & V_2 -> V_10 ) ;
}
static void F_10 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
if ( F_2 ( V_4 == NULL ) )
return;
V_2 -> V_7 -- ;
if ( V_2 -> V_7 == 0 )
V_2 -> V_8 = NULL ;
F_5 () ;
F_11 ( & V_4 -> V_5 ) ;
}
void F_12 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_7 ( & V_2 -> V_10 ) ;
F_10 ( V_2 , V_4 ) ;
F_9 ( & V_2 -> V_10 ) ;
F_13 ( V_4 ) ;
}
struct V_1 * F_14 ( struct V_3 * V_4 ,
T_1 V_13 )
{
struct V_1 * V_2 ;
V_2 = F_15 ( sizeof( * V_2 ) , V_13 ) ;
if ( V_2 != NULL ) {
F_16 ( & V_2 -> V_10 ) ;
F_17 ( & V_2 -> V_14 ) ;
V_2 -> V_7 = 0 ;
F_18 ( & V_2 -> V_6 ) ;
V_2 -> V_15 = & V_16 ;
F_1 ( V_2 , V_4 ) ;
}
return V_2 ;
}
static void F_19 ( struct V_1 * V_2 )
{
F_7 ( & V_2 -> V_10 ) ;
while ( ! F_20 ( & V_2 -> V_6 ) ) {
struct V_3 * V_4 ;
V_4 = F_21 ( & V_2 -> V_6 ,
struct V_3 , V_5 ) ;
F_10 ( V_2 , V_4 ) ;
F_9 ( & V_2 -> V_10 ) ;
F_13 ( V_4 ) ;
F_7 ( & V_2 -> V_10 ) ;
}
F_9 ( & V_2 -> V_10 ) ;
}
static void F_22 ( struct V_17 * V_17 )
{
struct V_1 * V_2 = F_23 ( V_17 ,
struct V_1 , V_14 ) ;
F_19 ( V_2 ) ;
F_24 ( V_2 , V_18 ) ;
}
struct V_1 * F_25 ( struct V_1 * V_2 )
{
if ( V_2 != NULL && F_26 ( & V_2 -> V_14 ) )
return V_2 ;
return NULL ;
}
void F_27 ( struct V_1 * V_2 )
{
if ( V_2 != NULL )
F_28 ( & V_2 -> V_14 , F_22 ) ;
}
void F_29 ( struct V_1 * V_2 )
{
if ( F_30 ( V_2 -> V_15 ) != & V_19 )
F_31 ( V_2 -> V_15 , & V_19 ) ;
}
static
const struct V_20 * F_32 ( const struct V_21 * V_22 )
{
if ( V_22 -> V_23 != NULL )
return V_22 -> V_23 ;
return F_33 ( V_22 -> V_24 ) -> V_15 ;
}
static
void F_34 ( struct V_21 * V_22 )
{
}
static
void F_35 ( struct V_21 * V_22 )
{
F_31 ( V_22 -> V_25 , NULL ) ;
}
static
struct V_3 * F_36 ( struct V_26 * V_27 )
{
return F_37 ( V_27 , struct V_3 , V_5 ) ;
}
static
struct V_3 * F_38 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_33 ( V_22 -> V_24 ) ;
if ( V_2 == NULL )
return NULL ;
return F_36 ( & V_2 -> V_6 ) ;
}
static
struct V_3 * F_39 ( struct V_26 * V_27 ,
const struct V_3 * V_28 )
{
struct V_3 * V_29 ;
F_40 (pos, head, xprt_switch) {
if ( V_28 == V_29 )
return V_29 ;
}
return NULL ;
}
static
struct V_3 * F_41 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_33 ( V_22 -> V_24 ) ;
struct V_26 * V_27 ;
if ( V_2 == NULL )
return NULL ;
V_27 = & V_2 -> V_6 ;
if ( V_22 -> V_25 == NULL || V_2 -> V_7 < 2 )
return F_36 ( V_27 ) ;
return F_39 ( V_27 , V_22 -> V_25 ) ;
}
bool F_8 ( struct V_1 * V_2 ,
const struct V_11 * V_30 )
{
struct V_26 * V_27 ;
struct V_3 * V_29 ;
if ( V_2 == NULL || V_30 == NULL )
return false ;
V_27 = & V_2 -> V_6 ;
F_40 (pos, head, xprt_switch) {
if ( F_42 ( V_30 , (struct V_11 * ) & V_29 -> V_12 ) ) {
F_43 ( L_1 ,
V_29 -> V_31 [ V_32 ] ) ;
return true ;
}
}
return false ;
}
static
struct V_3 * F_44 ( struct V_26 * V_27 ,
const struct V_3 * V_28 )
{
struct V_3 * V_29 , * V_33 = NULL ;
F_40 (pos, head, xprt_switch) {
if ( V_28 == V_33 )
return V_29 ;
V_33 = V_29 ;
}
return NULL ;
}
static
struct V_3 * F_45 ( struct V_26 * V_27 ,
struct V_3 * * V_34 ,
T_2 V_35 )
{
struct V_3 * V_28 , * V_29 , * V_36 ;
V_28 = F_30 ( * V_34 ) ;
for (; ; ) {
V_36 = V_28 ;
V_29 = V_35 ( V_27 , V_36 ) ;
if ( V_29 == NULL )
break;
V_28 = F_46 ( V_34 , V_36 , V_29 ) ;
if ( V_28 == V_36 )
break;
}
return V_29 ;
}
static
struct V_3 * F_47 ( struct V_21 * V_22 ,
T_2 V_35 )
{
struct V_1 * V_2 = F_33 ( V_22 -> V_24 ) ;
if ( V_2 == NULL )
return NULL ;
return F_45 ( & V_2 -> V_6 ,
& V_22 -> V_25 ,
V_35 ) ;
}
static
struct V_3 * F_48 ( struct V_26 * V_27 ,
const struct V_3 * V_28 )
{
struct V_3 * V_37 ;
V_37 = F_44 ( V_27 , V_28 ) ;
if ( V_37 != NULL )
return V_37 ;
return F_36 ( V_27 ) ;
}
static
struct V_3 * F_49 ( struct V_21 * V_22 )
{
return F_47 ( V_22 ,
F_48 ) ;
}
static
struct V_3 * F_50 ( struct V_21 * V_22 )
{
return F_47 ( V_22 , F_44 ) ;
}
static
void F_51 ( struct V_21 * V_22 )
{
F_52 () ;
F_32 ( V_22 ) -> F_53 ( V_22 ) ;
F_54 () ;
}
static void F_55 ( struct V_21 * V_22 ,
struct V_1 * V_2 ,
const struct V_20 * V_38 )
{
F_56 ( V_22 -> V_24 , F_25 ( V_2 ) ) ;
V_22 -> V_25 = NULL ;
V_22 -> V_23 = V_38 ;
}
void F_57 ( struct V_21 * V_22 ,
struct V_1 * V_2 )
{
F_55 ( V_22 , V_2 , NULL ) ;
}
void F_58 ( struct V_21 * V_22 ,
struct V_1 * V_2 )
{
F_55 ( V_22 , V_2 , & V_39 ) ;
}
struct V_1 * F_59 ( struct V_21 * V_22 ,
struct V_1 * V_40 )
{
struct V_1 T_3 * V_41 ;
V_41 = F_60 ( & V_22 -> V_24 , F_61 ( V_40 ) ) ;
if ( V_40 != NULL )
F_51 ( V_22 ) ;
return F_62 ( V_41 , true ) ;
}
void F_63 ( struct V_21 * V_22 )
{
F_27 ( F_59 ( V_22 , NULL ) ) ;
}
struct V_3 * F_64 ( struct V_21 * V_22 )
{
F_65 ( ! F_66 () ) ;
return F_32 ( V_22 ) -> F_67 ( V_22 ) ;
}
struct V_3 * F_68 ( struct V_21 * V_22 )
{
struct V_3 * V_4 ;
F_52 () ;
V_4 = F_69 ( V_22 , F_32 ( V_22 ) -> F_67 ) ;
F_54 () ;
return V_4 ;
}
struct V_3 * F_70 ( struct V_21 * V_22 )
{
struct V_3 * V_4 ;
F_52 () ;
V_4 = F_69 ( V_22 , F_32 ( V_22 ) -> V_42 ) ;
F_54 () ;
return V_4 ;
}
