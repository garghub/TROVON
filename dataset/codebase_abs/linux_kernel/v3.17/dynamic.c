struct V_1 * F_1 ( struct V_1 * V_2 )
{
if ( V_2 )
F_2 ( & V_2 -> V_3 ) ;
return V_2 ;
}
void F_3 ( struct V_1 * V_2 )
{
if ( V_2 )
F_4 ( & V_2 -> V_3 ) ;
}
void F_5 ( struct V_1 * V_4 )
{
struct V_5 * V_6 ;
if ( ! F_6 ( V_7 ) )
return;
F_7 ( ! F_8 ( V_4 ) ) ;
if ( ! V_8 )
return;
if ( F_9 ( V_4 ) ) {
F_10 (np, pp)
F_11 ( & V_4 -> V_3 , & V_6 -> V_9 ) ;
F_12 ( & V_4 -> V_3 ) ;
}
F_3 ( V_4 ) ;
}
int F_13 ( struct V_10 * V_11 )
{
return F_14 ( & V_12 , V_11 ) ;
}
int F_15 ( struct V_10 * V_11 )
{
return F_16 ( & V_12 , V_11 ) ;
}
int F_17 ( unsigned long V_13 , void * V_14 )
{
int V_15 ;
V_15 = F_18 ( & V_12 , V_13 , V_14 ) ;
return F_19 ( V_15 ) ;
}
int F_20 ( int V_13 , struct V_1 * V_4 ,
struct V_5 * V_16 , struct V_5 * V_17 )
{
struct V_18 V_19 ;
if ( ! F_9 ( V_4 ) )
return 0 ;
V_19 . V_20 = V_4 ;
V_19 . V_16 = V_16 ;
V_19 . V_21 = V_17 ;
return F_17 ( V_13 , & V_19 ) ;
}
void F_21 ( struct V_1 * V_4 )
{
const T_1 * V_22 ;
int V_23 ;
V_4 -> V_24 = F_22 ( V_4 , L_1 , NULL ) ? : L_2 ;
V_4 -> type = F_22 ( V_4 , L_3 , NULL ) ? : L_2 ;
V_22 = F_22 ( V_4 , L_4 , & V_23 ) ;
if ( ! V_22 )
V_22 = F_22 ( V_4 , L_5 , & V_23 ) ;
if ( F_6 ( V_25 ) && ! V_22 )
V_22 = F_22 ( V_4 , L_6 , & V_23 ) ;
V_4 -> V_22 = ( V_22 && ( V_23 >= 4 ) ) ? F_23 ( V_22 ) : 0 ;
V_4 -> V_26 = NULL ;
V_4 -> V_27 = V_4 -> V_28 -> V_26 ;
V_4 -> V_29 = V_4 -> V_28 -> V_29 ;
V_4 -> V_28 -> V_29 = V_4 ;
V_4 -> V_28 -> V_26 = V_4 ;
F_24 ( V_4 , V_30 ) ;
}
int F_25 ( struct V_1 * V_4 )
{
unsigned long V_31 ;
F_26 ( & V_32 ) ;
F_27 ( & V_33 , V_31 ) ;
F_21 ( V_4 ) ;
F_28 ( & V_33 , V_31 ) ;
F_29 ( V_4 ) ;
F_30 ( & V_32 ) ;
F_17 ( V_34 , V_4 ) ;
return 0 ;
}
void F_31 ( struct V_1 * V_4 )
{
struct V_1 * V_28 ;
if ( F_32 ( F_33 ( V_4 , V_30 ) ) )
return;
V_28 = V_4 -> V_28 ;
if ( F_32 ( ! V_28 ) )
return;
if ( V_35 == V_4 )
V_35 = V_4 -> V_29 ;
else {
struct V_1 * V_36 ;
for ( V_36 = V_35 ;
V_36 -> V_29 != V_4 ;
V_36 = V_36 -> V_29 )
;
V_36 -> V_29 = V_4 -> V_29 ;
}
if ( V_28 -> V_26 == V_4 )
V_28 -> V_26 = V_4 -> V_27 ;
else {
struct V_1 * V_37 ;
for ( V_37 = V_4 -> V_28 -> V_26 ;
V_37 -> V_27 != V_4 ;
V_37 = V_37 -> V_27 )
;
V_37 -> V_27 = V_4 -> V_27 ;
}
F_34 ( V_4 , V_30 ) ;
}
int F_35 ( struct V_1 * V_4 )
{
unsigned long V_31 ;
int V_15 = 0 ;
F_26 ( & V_32 ) ;
F_27 ( & V_33 , V_31 ) ;
F_31 ( V_4 ) ;
F_28 ( & V_33 , V_31 ) ;
F_5 ( V_4 ) ;
F_30 ( & V_32 ) ;
F_17 ( V_38 , V_4 ) ;
return V_15 ;
}
void F_36 ( struct V_39 * V_3 )
{
struct V_1 * V_2 = F_37 ( V_3 ) ;
struct V_5 * V_16 = V_2 -> V_40 ;
if ( ! F_33 ( V_2 , V_30 ) ) {
F_38 ( L_7 , V_2 -> V_41 ) ;
F_39 () ;
return;
}
if ( ! F_33 ( V_2 , V_42 ) )
return;
while ( V_16 ) {
struct V_5 * V_43 = V_16 -> V_43 ;
F_40 ( V_16 -> V_24 ) ;
F_40 ( V_16 -> V_44 ) ;
F_40 ( V_16 ) ;
V_16 = V_43 ;
if ( ! V_16 ) {
V_16 = V_2 -> V_45 ;
V_2 -> V_45 = NULL ;
}
}
F_40 ( V_2 -> V_41 ) ;
F_40 ( V_2 -> V_46 ) ;
F_40 ( V_2 ) ;
}
struct V_5 * F_41 ( const struct V_5 * V_16 , T_2 V_47 )
{
struct V_5 * V_48 ;
V_48 = F_42 ( sizeof( * V_48 ) , V_47 ) ;
if ( ! V_48 )
return NULL ;
V_48 -> V_24 = F_43 ( V_16 -> V_24 , V_47 ) ;
V_48 -> V_44 = F_44 ( V_16 -> V_44 , V_16 -> V_49 , V_47 ) ;
V_48 -> V_49 = V_16 -> V_49 ;
if ( ! V_48 -> V_24 || ! V_48 -> V_44 )
goto V_50;
F_45 ( V_48 , V_42 ) ;
return V_48 ;
V_50:
F_40 ( V_48 -> V_24 ) ;
F_40 ( V_48 -> V_44 ) ;
F_40 ( V_48 ) ;
return NULL ;
}
struct V_1 * F_46 ( const char * V_41 , T_2 V_47 )
{
struct V_1 * V_2 ;
V_2 = F_42 ( sizeof( * V_2 ) , V_47 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_41 = F_43 ( V_41 , V_47 ) ;
F_34 ( V_2 , V_42 ) ;
F_34 ( V_2 , V_30 ) ;
if ( ! V_2 -> V_41 )
goto V_50;
F_47 ( V_2 ) ;
return V_2 ;
V_50:
F_40 ( V_2 -> V_41 ) ;
F_40 ( V_2 ) ;
return NULL ;
}
static void F_48 ( struct V_51 * V_52 )
{
F_3 ( V_52 -> V_4 ) ;
F_49 ( & V_52 -> V_2 ) ;
F_40 ( V_52 ) ;
}
static void F_50 ( struct V_51 * V_52 )
{
switch ( V_52 -> V_13 ) {
case V_53 :
F_51 ( L_8 ,
V_52 , L_9 , V_52 -> V_4 -> V_41 ,
V_52 -> V_16 -> V_24 ) ;
break;
case V_54 :
F_51 ( L_8 ,
V_52 , L_10 , V_52 -> V_4 -> V_41 ,
V_52 -> V_16 -> V_24 ) ;
break;
case V_55 :
F_51 ( L_8 ,
V_52 , L_11 , V_52 -> V_4 -> V_41 ,
V_52 -> V_16 -> V_24 ) ;
break;
case V_34 :
F_51 ( L_12 ,
V_52 , L_13 , V_52 -> V_4 -> V_41 ) ;
break;
case V_38 :
F_51 ( L_12 ,
V_52 , L_14 , V_52 -> V_4 -> V_41 ) ;
break;
}
}
static inline void F_50 ( struct V_51 * V_52 )
{
}
static void F_52 ( struct V_51 * V_52 ,
struct V_51 * V_56 )
{
memcpy ( V_56 , V_52 , sizeof( * V_56 ) ) ;
switch ( V_52 -> V_13 ) {
case V_34 :
V_56 -> V_13 = V_38 ;
break;
case V_38 :
V_56 -> V_13 = V_34 ;
break;
case V_53 :
V_56 -> V_13 = V_54 ;
break;
case V_54 :
V_56 -> V_13 = V_53 ;
break;
case V_55 :
V_56 -> V_21 = V_52 -> V_16 ;
V_56 -> V_16 = V_52 -> V_21 ;
break;
}
}
static void F_53 ( struct V_51 * V_52 , bool V_57 )
{
struct V_51 V_58 ;
int V_59 ;
if ( V_57 ) {
F_52 ( V_52 , & V_58 ) ;
V_52 = & V_58 ;
}
switch ( V_52 -> V_13 ) {
case V_34 :
case V_38 :
V_59 = F_17 ( V_52 -> V_13 , V_52 -> V_4 ) ;
break;
case V_53 :
case V_54 :
case V_55 :
V_59 = F_20 ( V_52 -> V_13 , V_52 -> V_4 , V_52 -> V_16 , V_52 -> V_21 ) ;
break;
default:
F_38 ( L_15 , V_60 ,
( int ) V_52 -> V_13 ) ;
return;
}
if ( V_59 )
F_38 ( L_16 , V_60 , V_52 -> V_4 -> V_41 ) ;
}
static int F_54 ( struct V_51 * V_52 )
{
struct V_5 * V_21 , * * V_61 ;
unsigned long V_31 ;
int V_59 = 0 ;
F_50 ( V_52 ) ;
F_27 ( & V_33 , V_31 ) ;
switch ( V_52 -> V_13 ) {
case V_34 :
F_21 ( V_52 -> V_4 ) ;
break;
case V_38 :
F_31 ( V_52 -> V_4 ) ;
break;
case V_53 :
for ( V_61 = & V_52 -> V_4 -> V_45 ; * V_61 ; V_61 = & ( * V_61 ) -> V_43 ) {
if ( * V_61 == V_52 -> V_16 ) {
* V_61 = V_52 -> V_16 -> V_43 ;
V_52 -> V_16 -> V_43 = NULL ;
break;
}
}
V_59 = F_55 ( V_52 -> V_4 , V_52 -> V_16 ) ;
if ( V_59 ) {
F_38 ( L_17 ,
V_60 , V_52 -> V_4 -> V_41 ,
V_52 -> V_16 -> V_24 ) ;
break;
}
break;
case V_54 :
V_59 = F_56 ( V_52 -> V_4 , V_52 -> V_16 ) ;
if ( V_59 ) {
F_38 ( L_18 ,
V_60 , V_52 -> V_4 -> V_41 ,
V_52 -> V_16 -> V_24 ) ;
break;
}
break;
case V_55 :
for ( V_61 = & V_52 -> V_4 -> V_45 ; * V_61 ; V_61 = & ( * V_61 ) -> V_43 ) {
if ( * V_61 == V_52 -> V_16 ) {
* V_61 = V_52 -> V_16 -> V_43 ;
V_52 -> V_16 -> V_43 = NULL ;
break;
}
}
V_59 = F_57 ( V_52 -> V_4 , V_52 -> V_16 , & V_21 ) ;
if ( V_59 ) {
F_38 ( L_19 ,
V_60 , V_52 -> V_4 -> V_41 ,
V_52 -> V_16 -> V_24 ) ;
break;
}
break;
default:
V_59 = - V_62 ;
}
F_28 ( & V_33 , V_31 ) ;
if ( V_59 )
return V_59 ;
switch ( V_52 -> V_13 ) {
case V_34 :
F_29 ( V_52 -> V_4 ) ;
break;
case V_38 :
F_5 ( V_52 -> V_4 ) ;
break;
case V_53 :
F_58 ( V_52 -> V_4 , V_52 -> V_16 ) ;
break;
case V_54 :
F_59 ( V_52 -> V_4 , V_52 -> V_16 ) ;
break;
case V_55 :
F_60 ( V_52 -> V_4 , V_52 -> V_16 , V_52 -> V_21 ) ;
break;
}
return 0 ;
}
static inline int F_61 ( struct V_51 * V_52 )
{
struct V_51 V_58 ;
F_52 ( V_52 , & V_58 ) ;
return F_54 ( & V_58 ) ;
}
void F_62 ( struct V_63 * V_64 )
{
memset ( V_64 , 0 , sizeof( * V_64 ) ) ;
F_63 ( & V_64 -> V_65 ) ;
}
void F_64 ( struct V_63 * V_64 )
{
struct V_51 * V_52 , * V_66 ;
F_65 (ce, cen, &ocs->entries, node)
F_48 ( V_52 ) ;
}
int F_66 ( struct V_63 * V_64 )
{
struct V_51 * V_52 ;
int V_59 ;
F_51 ( L_20 ) ;
F_67 (ce, &ocs->entries, node) {
V_59 = F_54 ( V_52 ) ;
if ( V_59 ) {
F_38 ( L_21 , V_60 , V_59 ) ;
F_68 (ce, &ocs->entries, node)
F_61 ( V_52 ) ;
return V_59 ;
}
}
F_51 ( L_22 ) ;
F_30 ( & V_32 ) ;
F_67 (ce, &ocs->entries, node)
F_53 ( V_52 , 0 ) ;
F_26 ( & V_32 ) ;
F_51 ( L_23 ) ;
return 0 ;
}
int F_69 ( struct V_63 * V_64 )
{
struct V_51 * V_52 ;
int V_59 ;
F_51 ( L_24 ) ;
F_70 (ce, &ocs->entries, node) {
V_59 = F_61 ( V_52 ) ;
if ( V_59 ) {
F_38 ( L_25 , V_60 , V_59 ) ;
F_71 (ce, &ocs->entries, node)
F_54 ( V_52 ) ;
return V_59 ;
}
}
F_51 ( L_26 ) ;
F_30 ( & V_32 ) ;
F_70 (ce, &ocs->entries, node)
F_53 ( V_52 , 1 ) ;
F_26 ( & V_32 ) ;
F_51 ( L_23 ) ;
return 0 ;
}
int F_72 ( struct V_63 * V_64 , unsigned long V_13 ,
struct V_1 * V_4 , struct V_5 * V_16 )
{
struct V_51 * V_52 ;
V_52 = F_42 ( sizeof( * V_52 ) , V_67 ) ;
if ( ! V_52 ) {
F_38 ( L_27 , V_60 ) ;
return - V_68 ;
}
V_52 -> V_13 = V_13 ;
V_52 -> V_4 = F_1 ( V_4 ) ;
V_52 -> V_16 = V_16 ;
if ( V_13 == V_55 && V_16 )
V_52 -> V_21 = F_73 ( V_4 , V_16 -> V_24 , NULL ) ;
F_74 ( & V_52 -> V_2 , & V_64 -> V_65 ) ;
return 0 ;
}
