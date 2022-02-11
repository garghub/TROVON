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
F_11 ( V_4 , V_6 ) ;
F_12 ( & V_4 -> V_3 ) ;
}
F_3 ( V_4 ) ;
}
int F_13 ( struct V_9 * V_10 )
{
return F_14 ( & V_11 , V_10 ) ;
}
int F_15 ( struct V_9 * V_10 )
{
return F_16 ( & V_11 , V_10 ) ;
}
int F_17 ( unsigned long V_12 , struct V_13 * V_14 )
{
int V_15 ;
#ifdef F_18
struct V_13 * V_16 = V_14 ;
switch ( V_12 ) {
case V_17 :
case V_18 :
F_19 ( L_1 , V_19 [ V_12 ] ,
V_16 -> V_20 -> V_21 ) ;
break;
case V_22 :
case V_23 :
case V_24 :
F_19 ( L_2 , V_19 [ V_12 ] ,
V_16 -> V_20 -> V_21 , V_16 -> V_25 -> V_26 ) ;
break;
}
#endif
V_15 = F_20 ( & V_11 , V_12 , V_14 ) ;
return F_21 ( V_15 ) ;
}
int F_22 ( unsigned long V_12 , struct V_13 * V_16 )
{
struct V_5 * V_25 , * V_27 = NULL ;
int V_28 , V_29 , V_30 , V_31 , V_32 ;
switch ( V_12 ) {
case V_17 :
case V_18 :
V_25 = F_23 ( V_16 -> V_20 , L_3 , NULL ) ;
break;
case V_22 :
case V_23 :
V_25 = V_16 -> V_25 ;
break;
case V_24 :
V_25 = V_16 -> V_25 ;
V_27 = V_16 -> V_27 ;
break;
default:
return V_33 ;
}
V_28 = 0 ;
V_29 = - 1 ;
V_30 = - 1 ;
V_31 = - 1 ;
V_32 = - 1 ;
if ( V_25 && ! strcmp ( V_25 -> V_26 , L_3 ) ) {
V_28 = 1 ;
V_29 = ! strcmp ( V_25 -> V_34 , L_4 ) ||
! strcmp ( V_25 -> V_34 , L_5 ) ;
if ( V_27 )
V_30 = ! strcmp ( V_27 -> V_34 , L_4 ) ||
! strcmp ( V_27 -> V_34 , L_5 ) ;
}
switch ( V_12 ) {
case V_17 :
V_31 = 0 ;
V_32 = V_29 != 0 ;
break;
case V_18 :
V_31 = V_29 != 0 ;
V_32 = 0 ;
break;
case V_22 :
if ( V_28 ) {
V_31 = 1 ;
V_32 = V_29 ;
}
break;
case V_23 :
if ( V_28 ) {
V_31 = V_29 ;
V_32 = 1 ;
}
break;
case V_24 :
if ( V_28 ) {
V_31 = V_30 != 0 ;
V_32 = V_29 != 0 ;
}
break;
}
if ( V_31 == V_32 )
return V_33 ;
return V_32 ? V_35 : V_36 ;
}
int F_24 ( int V_12 , struct V_1 * V_4 ,
struct V_5 * V_25 , struct V_5 * V_37 )
{
struct V_13 V_16 ;
if ( ! F_9 ( V_4 ) )
return 0 ;
V_16 . V_20 = V_4 ;
V_16 . V_25 = V_25 ;
V_16 . V_27 = V_37 ;
return F_17 ( V_12 , & V_16 ) ;
}
void F_25 ( struct V_1 * V_4 )
{
const T_1 * V_38 ;
int V_39 ;
V_4 -> V_26 = F_26 ( V_4 , L_6 , NULL ) ? : L_7 ;
V_4 -> type = F_26 ( V_4 , L_8 , NULL ) ? : L_7 ;
V_38 = F_26 ( V_4 , L_9 , & V_39 ) ;
if ( ! V_38 )
V_38 = F_26 ( V_4 , L_10 , & V_39 ) ;
if ( F_6 ( V_40 ) && ! V_38 )
V_38 = F_26 ( V_4 , L_11 , & V_39 ) ;
V_4 -> V_38 = ( V_38 && ( V_39 >= 4 ) ) ? F_27 ( V_38 ) : 0 ;
V_4 -> V_41 = NULL ;
V_4 -> V_42 = V_4 -> V_43 -> V_41 ;
V_4 -> V_43 -> V_41 = V_4 ;
F_28 ( V_4 , V_44 ) ;
}
int F_29 ( struct V_1 * V_4 )
{
struct V_13 V_45 ;
unsigned long V_46 ;
memset ( & V_45 , 0 , sizeof( V_45 ) ) ;
V_45 . V_20 = V_4 ;
F_30 ( & V_47 ) ;
F_31 ( & V_48 , V_46 ) ;
F_25 ( V_4 ) ;
F_32 ( & V_48 , V_46 ) ;
F_33 ( V_4 ) ;
F_34 ( & V_47 ) ;
F_17 ( V_17 , & V_45 ) ;
return 0 ;
}
void F_35 ( struct V_1 * V_4 )
{
struct V_1 * V_43 ;
if ( F_36 ( F_37 ( V_4 , V_44 ) ) )
return;
V_43 = V_4 -> V_43 ;
if ( F_36 ( ! V_43 ) )
return;
if ( V_43 -> V_41 == V_4 )
V_43 -> V_41 = V_4 -> V_42 ;
else {
struct V_1 * V_49 ;
for ( V_49 = V_4 -> V_43 -> V_41 ;
V_49 -> V_42 != V_4 ;
V_49 = V_49 -> V_42 )
;
V_49 -> V_42 = V_4 -> V_42 ;
}
F_38 ( V_4 , V_44 ) ;
}
int F_39 ( struct V_1 * V_4 )
{
struct V_13 V_45 ;
unsigned long V_46 ;
int V_15 = 0 ;
memset ( & V_45 , 0 , sizeof( V_45 ) ) ;
V_45 . V_20 = V_4 ;
F_30 ( & V_47 ) ;
F_31 ( & V_48 , V_46 ) ;
F_35 ( V_4 ) ;
F_32 ( & V_48 , V_46 ) ;
F_5 ( V_4 ) ;
F_34 ( & V_47 ) ;
F_17 ( V_18 , & V_45 ) ;
return V_15 ;
}
void F_40 ( struct V_50 * V_3 )
{
struct V_1 * V_2 = F_41 ( V_3 ) ;
struct V_5 * V_25 = V_2 -> V_51 ;
if ( ! F_37 ( V_2 , V_44 ) ) {
F_42 ( L_12 , V_2 -> V_21 ) ;
F_43 () ;
return;
}
if ( ! F_37 ( V_2 , V_52 ) )
return;
while ( V_25 ) {
struct V_5 * V_53 = V_25 -> V_53 ;
F_44 ( V_25 -> V_26 ) ;
F_44 ( V_25 -> V_34 ) ;
F_44 ( V_25 ) ;
V_25 = V_53 ;
if ( ! V_25 ) {
V_25 = V_2 -> V_54 ;
V_2 -> V_54 = NULL ;
}
}
F_44 ( V_2 -> V_21 ) ;
F_44 ( V_2 -> V_55 ) ;
F_44 ( V_2 ) ;
}
struct V_5 * F_45 ( const struct V_5 * V_25 , T_2 V_56 )
{
struct V_5 * V_57 ;
V_57 = F_46 ( sizeof( * V_57 ) , V_56 ) ;
if ( ! V_57 )
return NULL ;
V_57 -> V_26 = F_47 ( V_25 -> V_26 , V_56 ) ;
V_57 -> V_34 = F_48 ( V_25 -> V_34 , V_25 -> V_58 , V_56 ) ;
V_57 -> V_58 = V_25 -> V_58 ;
if ( ! V_57 -> V_26 || ! V_57 -> V_34 )
goto V_59;
F_49 ( V_57 , V_52 ) ;
return V_57 ;
V_59:
F_44 ( V_57 -> V_26 ) ;
F_44 ( V_57 -> V_34 ) ;
F_44 ( V_57 ) ;
return NULL ;
}
struct V_1 * F_50 ( const struct V_1 * V_4 , const char * V_60 , ... )
{
T_3 V_61 ;
struct V_1 * V_2 ;
V_2 = F_46 ( sizeof( * V_2 ) , V_62 ) ;
if ( ! V_2 )
return NULL ;
va_start ( V_61 , V_60 ) ;
V_2 -> V_21 = F_51 ( V_62 , V_60 , V_61 ) ;
va_end ( V_61 ) ;
if ( ! V_2 -> V_21 ) {
F_44 ( V_2 ) ;
return NULL ;
}
F_38 ( V_2 , V_52 ) ;
F_38 ( V_2 , V_44 ) ;
F_52 ( V_2 ) ;
if ( V_4 ) {
struct V_5 * V_6 , * V_63 ;
F_10 (np, pp) {
V_63 = F_45 ( V_6 , V_62 ) ;
if ( ! V_63 )
goto V_64;
if ( F_53 ( V_2 , V_63 ) ) {
F_44 ( V_63 -> V_26 ) ;
F_44 ( V_63 -> V_34 ) ;
F_44 ( V_63 ) ;
goto V_64;
}
}
}
return V_2 ;
V_64:
F_3 ( V_2 ) ;
return NULL ;
}
static void F_54 ( struct V_65 * V_66 )
{
F_3 ( V_66 -> V_4 ) ;
F_55 ( & V_66 -> V_2 ) ;
F_44 ( V_66 ) ;
}
static void F_56 ( struct V_65 * V_66 )
{
switch ( V_66 -> V_12 ) {
case V_22 :
case V_23 :
case V_24 :
F_19 ( L_13 , V_66 , V_19 [ V_66 -> V_12 ] ,
V_66 -> V_4 -> V_21 , V_66 -> V_25 -> V_26 ) ;
break;
case V_17 :
case V_18 :
F_19 ( L_14 , V_66 , V_19 [ V_66 -> V_12 ] ,
V_66 -> V_4 -> V_21 ) ;
break;
}
}
static inline void F_56 ( struct V_65 * V_66 )
{
}
static void F_57 ( struct V_65 * V_66 ,
struct V_65 * V_67 )
{
memcpy ( V_67 , V_66 , sizeof( * V_67 ) ) ;
switch ( V_66 -> V_12 ) {
case V_17 :
V_67 -> V_12 = V_18 ;
break;
case V_18 :
V_67 -> V_12 = V_17 ;
break;
case V_22 :
V_67 -> V_12 = V_23 ;
break;
case V_23 :
V_67 -> V_12 = V_22 ;
break;
case V_24 :
V_67 -> V_27 = V_66 -> V_25 ;
V_67 -> V_25 = V_66 -> V_27 ;
if ( ! V_67 -> V_25 ) {
V_67 -> V_12 = V_23 ;
V_67 -> V_25 = V_66 -> V_25 ;
}
break;
}
}
static void F_58 ( struct V_65 * V_66 , bool V_68 )
{
struct V_13 V_45 ;
struct V_65 V_69 ;
int V_70 ;
if ( V_68 ) {
F_57 ( V_66 , & V_69 ) ;
V_66 = & V_69 ;
}
switch ( V_66 -> V_12 ) {
case V_17 :
case V_18 :
memset ( & V_45 , 0 , sizeof( V_45 ) ) ;
V_45 . V_20 = V_66 -> V_4 ;
V_70 = F_17 ( V_66 -> V_12 , & V_45 ) ;
break;
case V_22 :
case V_23 :
case V_24 :
V_70 = F_24 ( V_66 -> V_12 , V_66 -> V_4 , V_66 -> V_25 , V_66 -> V_27 ) ;
break;
default:
F_42 ( L_15 ,
( int ) V_66 -> V_12 ) ;
return;
}
if ( V_70 )
F_42 ( L_16 , V_66 -> V_4 -> V_21 ) ;
}
static int F_59 ( struct V_65 * V_66 )
{
struct V_5 * V_27 , * * V_71 ;
unsigned long V_46 ;
int V_70 = 0 ;
F_56 ( V_66 ) ;
F_31 ( & V_48 , V_46 ) ;
switch ( V_66 -> V_12 ) {
case V_17 :
F_25 ( V_66 -> V_4 ) ;
break;
case V_18 :
F_35 ( V_66 -> V_4 ) ;
break;
case V_22 :
for ( V_71 = & V_66 -> V_4 -> V_54 ; * V_71 ; V_71 = & ( * V_71 ) -> V_53 ) {
if ( * V_71 == V_66 -> V_25 ) {
* V_71 = V_66 -> V_25 -> V_53 ;
V_66 -> V_25 -> V_53 = NULL ;
break;
}
}
V_70 = F_53 ( V_66 -> V_4 , V_66 -> V_25 ) ;
if ( V_70 ) {
F_42 ( L_17 ,
V_66 -> V_4 -> V_21 ,
V_66 -> V_25 -> V_26 ) ;
break;
}
break;
case V_23 :
V_70 = F_60 ( V_66 -> V_4 , V_66 -> V_25 ) ;
if ( V_70 ) {
F_42 ( L_18 ,
V_66 -> V_4 -> V_21 ,
V_66 -> V_25 -> V_26 ) ;
break;
}
break;
case V_24 :
for ( V_71 = & V_66 -> V_4 -> V_54 ; * V_71 ; V_71 = & ( * V_71 ) -> V_53 ) {
if ( * V_71 == V_66 -> V_25 ) {
* V_71 = V_66 -> V_25 -> V_53 ;
V_66 -> V_25 -> V_53 = NULL ;
break;
}
}
V_70 = F_61 ( V_66 -> V_4 , V_66 -> V_25 , & V_27 ) ;
if ( V_70 ) {
F_42 ( L_19 ,
V_66 -> V_4 -> V_21 ,
V_66 -> V_25 -> V_26 ) ;
break;
}
break;
default:
V_70 = - V_72 ;
}
F_32 ( & V_48 , V_46 ) ;
if ( V_70 )
return V_70 ;
switch ( V_66 -> V_12 ) {
case V_17 :
F_33 ( V_66 -> V_4 ) ;
break;
case V_18 :
F_5 ( V_66 -> V_4 ) ;
break;
case V_22 :
F_62 ( V_66 -> V_4 , V_66 -> V_25 ) ;
break;
case V_23 :
F_63 ( V_66 -> V_4 , V_66 -> V_25 ) ;
break;
case V_24 :
F_64 ( V_66 -> V_4 , V_66 -> V_25 , V_66 -> V_27 ) ;
break;
}
return 0 ;
}
static inline int F_65 ( struct V_65 * V_66 )
{
struct V_65 V_69 ;
F_57 ( V_66 , & V_69 ) ;
return F_59 ( & V_69 ) ;
}
void F_66 ( struct V_73 * V_74 )
{
memset ( V_74 , 0 , sizeof( * V_74 ) ) ;
F_67 ( & V_74 -> V_75 ) ;
}
void F_68 ( struct V_73 * V_74 )
{
struct V_65 * V_66 , * V_76 ;
F_69 (ce, cen, &ocs->entries, node)
F_54 ( V_66 ) ;
}
int F_70 ( struct V_73 * V_74 )
{
struct V_65 * V_66 ;
int V_70 ;
F_19 ( L_20 ) ;
F_71 (ce, &ocs->entries, node) {
V_70 = F_59 ( V_66 ) ;
if ( V_70 ) {
F_42 ( L_21 , V_70 ) ;
F_72 (ce, &ocs->entries, node)
F_65 ( V_66 ) ;
return V_70 ;
}
}
F_19 ( L_22 ) ;
F_34 ( & V_47 ) ;
F_71 (ce, &ocs->entries, node)
F_58 ( V_66 , 0 ) ;
F_30 ( & V_47 ) ;
F_19 ( L_23 ) ;
return 0 ;
}
int F_73 ( struct V_73 * V_74 )
{
int V_70 ;
F_30 ( & V_47 ) ;
V_70 = F_70 ( V_74 ) ;
F_34 ( & V_47 ) ;
return V_70 ;
}
int F_74 ( struct V_73 * V_74 )
{
struct V_65 * V_66 ;
int V_70 ;
F_19 ( L_24 ) ;
F_75 (ce, &ocs->entries, node) {
V_70 = F_65 ( V_66 ) ;
if ( V_70 ) {
F_42 ( L_25 , V_70 ) ;
F_76 (ce, &ocs->entries, node)
F_59 ( V_66 ) ;
return V_70 ;
}
}
F_19 ( L_26 ) ;
F_34 ( & V_47 ) ;
F_75 (ce, &ocs->entries, node)
F_58 ( V_66 , 1 ) ;
F_30 ( & V_47 ) ;
F_19 ( L_23 ) ;
return 0 ;
}
int F_77 ( struct V_73 * V_74 )
{
int V_70 ;
F_30 ( & V_47 ) ;
V_70 = F_74 ( V_74 ) ;
F_34 ( & V_47 ) ;
return V_70 ;
}
int F_78 ( struct V_73 * V_74 , unsigned long V_12 ,
struct V_1 * V_4 , struct V_5 * V_25 )
{
struct V_65 * V_66 ;
V_66 = F_46 ( sizeof( * V_66 ) , V_62 ) ;
if ( ! V_66 )
return - V_77 ;
V_66 -> V_12 = V_12 ;
V_66 -> V_4 = F_1 ( V_4 ) ;
V_66 -> V_25 = V_25 ;
if ( V_12 == V_24 && V_25 )
V_66 -> V_27 = F_23 ( V_4 , V_25 -> V_26 , NULL ) ;
F_79 ( & V_66 -> V_2 , & V_74 -> V_75 ) ;
return 0 ;
}
