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
if ( V_2 -> V_8 == V_4 -> V_9 || V_2 -> V_8 == NULL )
F_1 ( V_2 , V_4 ) ;
F_8 ( & V_2 -> V_10 ) ;
}
static void F_9 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
if ( F_2 ( V_4 == NULL ) )
return;
V_2 -> V_7 -- ;
if ( V_2 -> V_7 == 0 )
V_2 -> V_8 = NULL ;
F_5 () ;
F_10 ( & V_4 -> V_5 ) ;
}
void F_11 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_7 ( & V_2 -> V_10 ) ;
F_9 ( V_2 , V_4 ) ;
F_8 ( & V_2 -> V_10 ) ;
F_12 ( V_4 ) ;
}
struct V_1 * F_13 ( struct V_3 * V_4 ,
T_1 V_11 )
{
struct V_1 * V_2 ;
V_2 = F_14 ( sizeof( * V_2 ) , V_11 ) ;
if ( V_2 != NULL ) {
F_15 ( & V_2 -> V_10 ) ;
F_16 ( & V_2 -> V_12 ) ;
V_2 -> V_7 = 0 ;
F_17 ( & V_2 -> V_6 ) ;
V_2 -> V_13 = & V_14 ;
F_1 ( V_2 , V_4 ) ;
}
return V_2 ;
}
static void F_18 ( struct V_1 * V_2 )
{
F_7 ( & V_2 -> V_10 ) ;
while ( ! F_19 ( & V_2 -> V_6 ) ) {
struct V_3 * V_4 ;
V_4 = F_20 ( & V_2 -> V_6 ,
struct V_3 , V_5 ) ;
F_9 ( V_2 , V_4 ) ;
F_8 ( & V_2 -> V_10 ) ;
F_12 ( V_4 ) ;
F_7 ( & V_2 -> V_10 ) ;
}
F_8 ( & V_2 -> V_10 ) ;
}
static void F_21 ( struct V_15 * V_15 )
{
struct V_1 * V_2 = F_22 ( V_15 ,
struct V_1 , V_12 ) ;
F_18 ( V_2 ) ;
F_23 ( V_2 , V_16 ) ;
}
struct V_1 * F_24 ( struct V_1 * V_2 )
{
if ( V_2 != NULL && F_25 ( & V_2 -> V_12 ) )
return V_2 ;
return NULL ;
}
void F_26 ( struct V_1 * V_2 )
{
if ( V_2 != NULL )
F_27 ( & V_2 -> V_12 , F_21 ) ;
}
void F_28 ( struct V_1 * V_2 )
{
if ( F_29 ( V_2 -> V_13 ) != & V_17 )
F_30 ( V_2 -> V_13 , & V_17 ) ;
}
static
const struct V_18 * F_31 ( const struct V_19 * V_20 )
{
if ( V_20 -> V_21 != NULL )
return V_20 -> V_21 ;
return F_32 ( V_20 -> V_22 ) -> V_13 ;
}
static
void F_33 ( struct V_19 * V_20 )
{
}
static
void F_34 ( struct V_19 * V_20 )
{
F_30 ( V_20 -> V_23 , NULL ) ;
}
static
struct V_3 * F_35 ( struct V_24 * V_25 )
{
return F_36 ( V_25 , struct V_3 , V_5 ) ;
}
static
struct V_3 * F_37 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = F_32 ( V_20 -> V_22 ) ;
if ( V_2 == NULL )
return NULL ;
return F_35 ( & V_2 -> V_6 ) ;
}
static
struct V_3 * F_38 ( struct V_24 * V_25 ,
const struct V_3 * V_26 )
{
struct V_3 * V_27 ;
F_39 (pos, head, xprt_switch) {
if ( V_26 == V_27 )
return V_27 ;
}
return NULL ;
}
static
struct V_3 * F_40 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = F_32 ( V_20 -> V_22 ) ;
struct V_24 * V_25 ;
if ( V_2 == NULL )
return NULL ;
V_25 = & V_2 -> V_6 ;
if ( V_20 -> V_23 == NULL || V_2 -> V_7 < 2 )
return F_35 ( V_25 ) ;
return F_38 ( V_25 , V_20 -> V_23 ) ;
}
static
struct V_3 * F_41 ( struct V_24 * V_25 ,
const struct V_3 * V_26 )
{
struct V_3 * V_27 , * V_28 = NULL ;
F_39 (pos, head, xprt_switch) {
if ( V_26 == V_28 )
return V_27 ;
V_28 = V_27 ;
}
return NULL ;
}
static
struct V_3 * F_42 ( struct V_24 * V_25 ,
struct V_3 * * V_29 ,
T_2 V_30 )
{
struct V_3 * V_26 , * V_27 , * V_31 ;
V_26 = F_29 ( * V_29 ) ;
for (; ; ) {
V_31 = V_26 ;
V_27 = V_30 ( V_25 , V_31 ) ;
if ( V_27 == NULL )
break;
V_26 = F_43 ( V_29 , V_31 , V_27 ) ;
if ( V_26 == V_31 )
break;
}
return V_27 ;
}
static
struct V_3 * F_44 ( struct V_19 * V_20 ,
T_2 V_30 )
{
struct V_1 * V_2 = F_32 ( V_20 -> V_22 ) ;
struct V_24 * V_25 ;
if ( V_2 == NULL )
return NULL ;
V_25 = & V_2 -> V_6 ;
if ( V_2 -> V_7 < 2 )
return F_35 ( V_25 ) ;
return F_42 ( V_25 , & V_20 -> V_23 , V_30 ) ;
}
static
struct V_3 * F_45 ( struct V_24 * V_25 ,
const struct V_3 * V_26 )
{
struct V_3 * V_32 ;
V_32 = F_41 ( V_25 , V_26 ) ;
if ( V_32 != NULL )
return V_32 ;
return F_35 ( V_25 ) ;
}
static
struct V_3 * F_46 ( struct V_19 * V_20 )
{
return F_44 ( V_20 ,
F_45 ) ;
}
static
struct V_3 * F_47 ( struct V_19 * V_20 )
{
return F_44 ( V_20 , F_41 ) ;
}
static
void F_48 ( struct V_19 * V_20 )
{
F_49 () ;
F_31 ( V_20 ) -> F_50 ( V_20 ) ;
F_51 () ;
}
static void F_52 ( struct V_19 * V_20 ,
struct V_1 * V_2 ,
const struct V_18 * V_33 )
{
F_53 ( V_20 -> V_22 , F_24 ( V_2 ) ) ;
V_20 -> V_23 = NULL ;
V_20 -> V_21 = V_33 ;
}
void F_54 ( struct V_19 * V_20 ,
struct V_1 * V_2 )
{
F_52 ( V_20 , V_2 , NULL ) ;
}
void F_55 ( struct V_19 * V_20 ,
struct V_1 * V_2 )
{
F_52 ( V_20 , V_2 , & V_34 ) ;
}
struct V_1 * F_56 ( struct V_19 * V_20 ,
struct V_1 * V_35 )
{
struct V_1 T_3 * V_36 ;
V_36 = F_57 ( & V_20 -> V_22 , F_58 ( V_35 ) ) ;
if ( V_35 != NULL )
F_48 ( V_20 ) ;
return F_59 ( V_36 , true ) ;
}
void F_60 ( struct V_19 * V_20 )
{
F_26 ( F_56 ( V_20 , NULL ) ) ;
}
struct V_3 * F_61 ( struct V_19 * V_20 )
{
F_62 ( ! F_63 () ) ;
return F_31 ( V_20 ) -> F_64 ( V_20 ) ;
}
struct V_3 * F_65 ( struct V_19 * V_20 )
{
struct V_3 * V_4 ;
F_49 () ;
V_4 = F_66 ( V_20 , F_31 ( V_20 ) -> F_64 ) ;
F_51 () ;
return V_4 ;
}
struct V_3 * F_67 ( struct V_19 * V_20 )
{
struct V_3 * V_4 ;
F_49 () ;
V_4 = F_66 ( V_20 , F_31 ( V_20 ) -> V_37 ) ;
F_51 () ;
return V_4 ;
}
