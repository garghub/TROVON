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
int F_17 ( unsigned long V_13 , struct V_14 * V_15 )
{
int V_16 ;
#ifdef F_18
struct V_14 * V_17 = V_15 ;
switch ( V_13 ) {
case V_18 :
case V_19 :
F_19 ( L_1 , V_20 [ V_13 ] ,
V_17 -> V_21 -> V_22 ) ;
break;
case V_23 :
case V_24 :
case V_25 :
F_19 ( L_2 , V_20 [ V_13 ] ,
V_17 -> V_21 -> V_22 , V_17 -> V_26 -> V_27 ) ;
break;
}
#endif
V_16 = F_20 ( & V_12 , V_13 , V_15 ) ;
return F_21 ( V_16 ) ;
}
int F_22 ( unsigned long V_13 , struct V_14 * V_17 )
{
struct V_5 * V_26 , * V_28 = NULL ;
int V_29 , V_30 , V_31 , V_32 , V_33 ;
switch ( V_13 ) {
case V_18 :
case V_19 :
V_26 = F_23 ( V_17 -> V_21 , L_3 , NULL ) ;
break;
case V_23 :
case V_24 :
V_26 = V_17 -> V_26 ;
break;
case V_25 :
V_26 = V_17 -> V_26 ;
V_28 = V_17 -> V_28 ;
break;
default:
return V_34 ;
}
V_29 = 0 ;
V_30 = - 1 ;
V_31 = - 1 ;
V_32 = - 1 ;
V_33 = - 1 ;
if ( V_26 && ! strcmp ( V_26 -> V_27 , L_3 ) ) {
V_29 = 1 ;
V_30 = ! strcmp ( V_26 -> V_35 , L_4 ) ||
! strcmp ( V_26 -> V_35 , L_5 ) ;
if ( V_28 )
V_31 = ! strcmp ( V_28 -> V_35 , L_4 ) ||
! strcmp ( V_28 -> V_35 , L_5 ) ;
}
switch ( V_13 ) {
case V_18 :
V_32 = 0 ;
V_33 = V_30 != 0 ;
break;
case V_19 :
V_32 = V_30 != 0 ;
V_33 = 0 ;
break;
case V_23 :
if ( V_29 ) {
V_32 = 1 ;
V_33 = V_30 ;
}
break;
case V_24 :
if ( V_29 ) {
V_32 = V_30 ;
V_33 = 1 ;
}
break;
case V_25 :
if ( V_29 ) {
V_32 = V_31 != 0 ;
V_33 = V_30 != 0 ;
}
break;
}
if ( V_32 == V_33 )
return V_34 ;
return V_33 ? V_36 : V_37 ;
}
int F_24 ( int V_13 , struct V_1 * V_4 ,
struct V_5 * V_26 , struct V_5 * V_38 )
{
struct V_14 V_17 ;
if ( ! F_9 ( V_4 ) )
return 0 ;
V_17 . V_21 = V_4 ;
V_17 . V_26 = V_26 ;
V_17 . V_28 = V_38 ;
return F_17 ( V_13 , & V_17 ) ;
}
void F_25 ( struct V_1 * V_4 )
{
const T_1 * V_39 ;
int V_40 ;
V_4 -> V_27 = F_26 ( V_4 , L_6 , NULL ) ? : L_7 ;
V_4 -> type = F_26 ( V_4 , L_8 , NULL ) ? : L_7 ;
V_39 = F_26 ( V_4 , L_9 , & V_40 ) ;
if ( ! V_39 )
V_39 = F_26 ( V_4 , L_10 , & V_40 ) ;
if ( F_6 ( V_41 ) && ! V_39 )
V_39 = F_26 ( V_4 , L_11 , & V_40 ) ;
V_4 -> V_39 = ( V_39 && ( V_40 >= 4 ) ) ? F_27 ( V_39 ) : 0 ;
V_4 -> V_42 = NULL ;
V_4 -> V_43 = V_4 -> V_44 -> V_42 ;
V_4 -> V_44 -> V_42 = V_4 ;
F_28 ( V_4 , V_45 ) ;
}
int F_29 ( struct V_1 * V_4 )
{
struct V_14 V_46 ;
unsigned long V_47 ;
memset ( & V_46 , 0 , sizeof( V_46 ) ) ;
V_46 . V_21 = V_4 ;
F_30 ( & V_48 ) ;
F_31 ( & V_49 , V_47 ) ;
F_25 ( V_4 ) ;
F_32 ( & V_49 , V_47 ) ;
F_33 ( V_4 ) ;
F_34 ( & V_48 ) ;
F_17 ( V_18 , & V_46 ) ;
return 0 ;
}
void F_35 ( struct V_1 * V_4 )
{
struct V_1 * V_44 ;
if ( F_36 ( F_37 ( V_4 , V_45 ) ) )
return;
V_44 = V_4 -> V_44 ;
if ( F_36 ( ! V_44 ) )
return;
if ( V_44 -> V_42 == V_4 )
V_44 -> V_42 = V_4 -> V_43 ;
else {
struct V_1 * V_50 ;
for ( V_50 = V_4 -> V_44 -> V_42 ;
V_50 -> V_43 != V_4 ;
V_50 = V_50 -> V_43 )
;
V_50 -> V_43 = V_4 -> V_43 ;
}
F_38 ( V_4 , V_45 ) ;
}
int F_39 ( struct V_1 * V_4 )
{
struct V_14 V_46 ;
unsigned long V_47 ;
int V_16 = 0 ;
memset ( & V_46 , 0 , sizeof( V_46 ) ) ;
V_46 . V_21 = V_4 ;
F_30 ( & V_48 ) ;
F_31 ( & V_49 , V_47 ) ;
F_35 ( V_4 ) ;
F_32 ( & V_49 , V_47 ) ;
F_5 ( V_4 ) ;
F_34 ( & V_48 ) ;
F_17 ( V_19 , & V_46 ) ;
return V_16 ;
}
void F_40 ( struct V_51 * V_3 )
{
struct V_1 * V_2 = F_41 ( V_3 ) ;
struct V_5 * V_26 = V_2 -> V_52 ;
if ( ! F_37 ( V_2 , V_45 ) ) {
F_42 ( L_12 , V_2 -> V_22 ) ;
F_43 () ;
return;
}
if ( ! F_37 ( V_2 , V_53 ) )
return;
while ( V_26 ) {
struct V_5 * V_54 = V_26 -> V_54 ;
F_44 ( V_26 -> V_27 ) ;
F_44 ( V_26 -> V_35 ) ;
F_44 ( V_26 ) ;
V_26 = V_54 ;
if ( ! V_26 ) {
V_26 = V_2 -> V_55 ;
V_2 -> V_55 = NULL ;
}
}
F_44 ( V_2 -> V_22 ) ;
F_44 ( V_2 -> V_56 ) ;
F_44 ( V_2 ) ;
}
struct V_5 * F_45 ( const struct V_5 * V_26 , T_2 V_57 )
{
struct V_5 * V_58 ;
V_58 = F_46 ( sizeof( * V_58 ) , V_57 ) ;
if ( ! V_58 )
return NULL ;
V_58 -> V_27 = F_47 ( V_26 -> V_27 , V_57 ) ;
V_58 -> V_35 = F_48 ( V_26 -> V_35 , V_26 -> V_59 , V_57 ) ;
V_58 -> V_59 = V_26 -> V_59 ;
if ( ! V_58 -> V_27 || ! V_58 -> V_35 )
goto V_60;
F_49 ( V_58 , V_53 ) ;
return V_58 ;
V_60:
F_44 ( V_58 -> V_27 ) ;
F_44 ( V_58 -> V_35 ) ;
F_44 ( V_58 ) ;
return NULL ;
}
struct V_1 * F_50 ( const struct V_1 * V_4 , const char * V_61 , ... )
{
T_3 V_62 ;
struct V_1 * V_2 ;
V_2 = F_46 ( sizeof( * V_2 ) , V_63 ) ;
if ( ! V_2 )
return NULL ;
va_start ( V_62 , V_61 ) ;
V_2 -> V_22 = F_51 ( V_63 , V_61 , V_62 ) ;
va_end ( V_62 ) ;
if ( ! V_2 -> V_22 ) {
F_44 ( V_2 ) ;
return NULL ;
}
F_38 ( V_2 , V_53 ) ;
F_38 ( V_2 , V_45 ) ;
F_52 ( V_2 ) ;
if ( V_4 ) {
struct V_5 * V_6 , * V_64 ;
F_10 (np, pp) {
V_64 = F_45 ( V_6 , V_63 ) ;
if ( ! V_64 )
goto V_65;
if ( F_53 ( V_2 , V_64 ) ) {
F_44 ( V_64 -> V_27 ) ;
F_44 ( V_64 -> V_35 ) ;
F_44 ( V_64 ) ;
goto V_65;
}
}
}
return V_2 ;
V_65:
F_3 ( V_2 ) ;
return NULL ;
}
static void F_54 ( struct V_66 * V_67 )
{
F_3 ( V_67 -> V_4 ) ;
F_55 ( & V_67 -> V_2 ) ;
F_44 ( V_67 ) ;
}
static void F_56 ( struct V_66 * V_67 )
{
switch ( V_67 -> V_13 ) {
case V_23 :
case V_24 :
case V_25 :
F_19 ( L_13 , V_67 , V_20 [ V_67 -> V_13 ] ,
V_67 -> V_4 -> V_22 , V_67 -> V_26 -> V_27 ) ;
break;
case V_18 :
case V_19 :
F_19 ( L_14 , V_67 , V_20 [ V_67 -> V_13 ] ,
V_67 -> V_4 -> V_22 ) ;
break;
}
}
static inline void F_56 ( struct V_66 * V_67 )
{
}
static void F_57 ( struct V_66 * V_67 ,
struct V_66 * V_68 )
{
memcpy ( V_68 , V_67 , sizeof( * V_68 ) ) ;
switch ( V_67 -> V_13 ) {
case V_18 :
V_68 -> V_13 = V_19 ;
break;
case V_19 :
V_68 -> V_13 = V_18 ;
break;
case V_23 :
V_68 -> V_13 = V_24 ;
break;
case V_24 :
V_68 -> V_13 = V_23 ;
break;
case V_25 :
V_68 -> V_28 = V_67 -> V_26 ;
V_68 -> V_26 = V_67 -> V_28 ;
break;
}
}
static void F_58 ( struct V_66 * V_67 , bool V_69 )
{
struct V_14 V_46 ;
struct V_66 V_70 ;
int V_71 ;
if ( V_69 ) {
F_57 ( V_67 , & V_70 ) ;
V_67 = & V_70 ;
}
switch ( V_67 -> V_13 ) {
case V_18 :
case V_19 :
memset ( & V_46 , 0 , sizeof( V_46 ) ) ;
V_46 . V_21 = V_67 -> V_4 ;
V_71 = F_17 ( V_67 -> V_13 , & V_46 ) ;
break;
case V_23 :
case V_24 :
case V_25 :
V_71 = F_24 ( V_67 -> V_13 , V_67 -> V_4 , V_67 -> V_26 , V_67 -> V_28 ) ;
break;
default:
F_42 ( L_15 , V_72 ,
( int ) V_67 -> V_13 ) ;
return;
}
if ( V_71 )
F_42 ( L_16 , V_72 , V_67 -> V_4 -> V_22 ) ;
}
static int F_59 ( struct V_66 * V_67 )
{
struct V_5 * V_28 , * * V_73 ;
unsigned long V_47 ;
int V_71 = 0 ;
F_56 ( V_67 ) ;
F_31 ( & V_49 , V_47 ) ;
switch ( V_67 -> V_13 ) {
case V_18 :
F_25 ( V_67 -> V_4 ) ;
break;
case V_19 :
F_35 ( V_67 -> V_4 ) ;
break;
case V_23 :
for ( V_73 = & V_67 -> V_4 -> V_55 ; * V_73 ; V_73 = & ( * V_73 ) -> V_54 ) {
if ( * V_73 == V_67 -> V_26 ) {
* V_73 = V_67 -> V_26 -> V_54 ;
V_67 -> V_26 -> V_54 = NULL ;
break;
}
}
V_71 = F_53 ( V_67 -> V_4 , V_67 -> V_26 ) ;
if ( V_71 ) {
F_42 ( L_17 ,
V_72 , V_67 -> V_4 -> V_22 ,
V_67 -> V_26 -> V_27 ) ;
break;
}
break;
case V_24 :
V_71 = F_60 ( V_67 -> V_4 , V_67 -> V_26 ) ;
if ( V_71 ) {
F_42 ( L_18 ,
V_72 , V_67 -> V_4 -> V_22 ,
V_67 -> V_26 -> V_27 ) ;
break;
}
break;
case V_25 :
for ( V_73 = & V_67 -> V_4 -> V_55 ; * V_73 ; V_73 = & ( * V_73 ) -> V_54 ) {
if ( * V_73 == V_67 -> V_26 ) {
* V_73 = V_67 -> V_26 -> V_54 ;
V_67 -> V_26 -> V_54 = NULL ;
break;
}
}
V_71 = F_61 ( V_67 -> V_4 , V_67 -> V_26 , & V_28 ) ;
if ( V_71 ) {
F_42 ( L_19 ,
V_72 , V_67 -> V_4 -> V_22 ,
V_67 -> V_26 -> V_27 ) ;
break;
}
break;
default:
V_71 = - V_74 ;
}
F_32 ( & V_49 , V_47 ) ;
if ( V_71 )
return V_71 ;
switch ( V_67 -> V_13 ) {
case V_18 :
F_33 ( V_67 -> V_4 ) ;
break;
case V_19 :
F_5 ( V_67 -> V_4 ) ;
break;
case V_23 :
F_62 ( V_67 -> V_4 , V_67 -> V_26 ) ;
break;
case V_24 :
F_63 ( V_67 -> V_4 , V_67 -> V_26 ) ;
break;
case V_25 :
F_64 ( V_67 -> V_4 , V_67 -> V_26 , V_67 -> V_28 ) ;
break;
}
return 0 ;
}
static inline int F_65 ( struct V_66 * V_67 )
{
struct V_66 V_70 ;
F_57 ( V_67 , & V_70 ) ;
return F_59 ( & V_70 ) ;
}
void F_66 ( struct V_75 * V_76 )
{
memset ( V_76 , 0 , sizeof( * V_76 ) ) ;
F_67 ( & V_76 -> V_77 ) ;
}
void F_68 ( struct V_75 * V_76 )
{
struct V_66 * V_67 , * V_78 ;
F_69 (ce, cen, &ocs->entries, node)
F_54 ( V_67 ) ;
}
int F_70 ( struct V_75 * V_76 )
{
struct V_66 * V_67 ;
int V_71 ;
F_19 ( L_20 ) ;
F_71 (ce, &ocs->entries, node) {
V_71 = F_59 ( V_67 ) ;
if ( V_71 ) {
F_42 ( L_21 , V_72 , V_71 ) ;
F_72 (ce, &ocs->entries, node)
F_65 ( V_67 ) ;
return V_71 ;
}
}
F_19 ( L_22 ) ;
F_34 ( & V_48 ) ;
F_71 (ce, &ocs->entries, node)
F_58 ( V_67 , 0 ) ;
F_30 ( & V_48 ) ;
F_19 ( L_23 ) ;
return 0 ;
}
int F_73 ( struct V_75 * V_76 )
{
struct V_66 * V_67 ;
int V_71 ;
F_19 ( L_24 ) ;
F_74 (ce, &ocs->entries, node) {
V_71 = F_65 ( V_67 ) ;
if ( V_71 ) {
F_42 ( L_25 , V_72 , V_71 ) ;
F_75 (ce, &ocs->entries, node)
F_59 ( V_67 ) ;
return V_71 ;
}
}
F_19 ( L_26 ) ;
F_34 ( & V_48 ) ;
F_74 (ce, &ocs->entries, node)
F_58 ( V_67 , 1 ) ;
F_30 ( & V_48 ) ;
F_19 ( L_23 ) ;
return 0 ;
}
int F_76 ( struct V_75 * V_76 , unsigned long V_13 ,
struct V_1 * V_4 , struct V_5 * V_26 )
{
struct V_66 * V_67 ;
V_67 = F_46 ( sizeof( * V_67 ) , V_63 ) ;
if ( ! V_67 ) {
F_42 ( L_27 , V_72 ) ;
return - V_79 ;
}
V_67 -> V_13 = V_13 ;
V_67 -> V_4 = F_1 ( V_4 ) ;
V_67 -> V_26 = V_26 ;
if ( V_13 == V_25 && V_26 )
V_67 -> V_28 = F_23 ( V_4 , V_26 -> V_27 , NULL ) ;
F_77 ( & V_67 -> V_2 , & V_76 -> V_77 ) ;
return 0 ;
}
