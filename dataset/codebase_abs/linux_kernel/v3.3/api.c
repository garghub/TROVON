static inline struct V_1 * F_1 ( struct V_1 * V_2 )
{
F_2 ( & V_2 -> V_3 ) ;
return V_2 ;
}
struct V_1 * F_3 ( struct V_1 * V_2 )
{
return F_4 ( V_2 -> V_4 ) ? F_1 ( V_2 ) : NULL ;
}
void F_5 ( struct V_1 * V_2 )
{
struct V_5 * V_5 = V_2 -> V_4 ;
F_6 ( V_2 ) ;
F_7 ( V_5 ) ;
}
static inline int F_8 ( struct V_6 * V_7 )
{
return V_7 -> V_2 . V_8 [ 0 ] ;
}
static struct V_1 * F_9 ( const char * V_9 , T_1 type ,
T_1 V_10 )
{
struct V_1 * V_11 , * V_2 = NULL ;
int V_12 = - 2 ;
F_10 (q, &crypto_alg_list, cra_list) {
int V_13 , V_14 ;
if ( F_11 ( V_11 ) )
continue;
if ( ( V_11 -> V_15 ^ type ) & V_10 )
continue;
if ( F_12 ( V_11 ) &&
! F_8 ( (struct V_6 * ) V_11 ) &&
( (struct V_6 * ) V_11 ) -> V_10 != V_10 )
continue;
V_13 = ! strcmp ( V_11 -> V_8 , V_9 ) ;
V_14 = ! strcmp ( V_11 -> V_16 , V_9 ) ;
if ( ! V_13 && ! ( V_14 && V_11 -> V_17 > V_12 ) )
continue;
if ( F_13 ( ! F_3 ( V_11 ) ) )
continue;
V_12 = V_11 -> V_17 ;
if ( V_2 )
F_5 ( V_2 ) ;
V_2 = V_11 ;
if ( V_13 )
break;
}
return V_2 ;
}
static void F_14 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = ( void * ) V_2 ;
F_15 ( ! F_12 ( V_2 ) ) ;
if ( V_7 -> V_18 )
F_5 ( V_7 -> V_18 ) ;
F_16 ( V_7 ) ;
}
struct V_6 * F_17 ( const char * V_9 , T_1 type , T_1 V_10 )
{
struct V_6 * V_7 ;
V_7 = F_18 ( sizeof( * V_7 ) , V_19 ) ;
if ( ! V_7 )
return F_19 ( - V_20 ) ;
V_7 -> V_10 = V_10 ;
V_7 -> V_2 . V_15 = V_21 | type ;
V_7 -> V_2 . V_17 = - 1 ;
V_7 -> V_2 . V_22 = F_14 ;
F_20 ( V_7 -> V_2 . V_16 , V_9 , V_23 ) ;
F_21 ( & V_7 -> V_24 ) ;
return V_7 ;
}
static struct V_1 * F_22 ( const char * V_9 , T_1 type ,
T_1 V_10 )
{
struct V_1 * V_2 ;
struct V_6 * V_7 ;
V_7 = F_17 ( V_9 , type , V_10 ) ;
if ( F_23 ( V_7 ) )
return F_24 ( V_7 ) ;
F_25 ( & V_7 -> V_2 . V_3 , 2 ) ;
F_26 ( & V_25 ) ;
V_2 = F_9 ( V_9 , type , V_10 ) ;
if ( ! V_2 ) {
V_2 = & V_7 -> V_2 ;
F_27 ( & V_2 -> V_26 , & V_27 ) ;
}
F_28 ( & V_25 ) ;
if ( V_2 != & V_7 -> V_2 )
F_16 ( V_7 ) ;
return V_2 ;
}
void F_29 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = ( void * ) V_2 ;
F_26 ( & V_25 ) ;
F_30 ( & V_2 -> V_26 ) ;
F_28 ( & V_25 ) ;
F_31 ( & V_7 -> V_24 ) ;
F_6 ( V_2 ) ;
}
static struct V_1 * F_32 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = ( void * ) V_2 ;
long V_28 ;
V_28 = F_33 (
& V_7 -> V_24 , 60 * V_29 ) ;
V_2 = V_7 -> V_18 ;
if ( V_28 < 0 )
V_2 = F_19 ( - V_30 ) ;
else if ( ! V_28 )
V_2 = F_19 ( - V_31 ) ;
else if ( ! V_2 )
V_2 = F_19 ( - V_32 ) ;
else if ( F_8 ( V_7 ) &&
! ( V_2 -> V_15 & V_33 ) )
V_2 = F_19 ( - V_34 ) ;
else if ( ! F_3 ( V_2 ) )
V_2 = F_19 ( - V_34 ) ;
F_5 ( & V_7 -> V_2 ) ;
return V_2 ;
}
struct V_1 * F_34 ( const char * V_9 , T_1 type , T_1 V_10 )
{
struct V_1 * V_2 ;
F_35 ( & V_25 ) ;
V_2 = F_9 ( V_9 , type , V_10 ) ;
F_36 ( & V_25 ) ;
return V_2 ;
}
struct V_1 * F_37 ( const char * V_9 , T_1 type , T_1 V_10 )
{
struct V_1 * V_2 ;
if ( ! V_9 )
return F_19 ( - V_32 ) ;
V_10 &= ~ ( V_21 | V_35 ) ;
type &= V_10 ;
V_2 = F_34 ( V_9 , type , V_10 ) ;
if ( ! V_2 ) {
F_38 ( L_1 , V_9 ) ;
if ( ! ( ( type ^ V_36 ) & V_10 &
V_36 ) )
F_38 ( L_2 , V_9 ) ;
V_2 = F_34 ( V_9 , type , V_10 ) ;
}
if ( V_2 )
return F_12 ( V_2 ) ? F_32 ( V_2 ) : V_2 ;
return F_22 ( V_9 , type , V_10 ) ;
}
int F_39 ( unsigned long V_37 , void * V_38 )
{
int V_39 ;
V_39 = F_40 ( & V_40 , V_37 , V_38 ) ;
if ( V_39 == V_41 ) {
F_38 ( L_3 ) ;
V_39 = F_40 ( & V_40 , V_37 , V_38 ) ;
}
return V_39 ;
}
struct V_1 * F_41 ( const char * V_9 , T_1 type , T_1 V_10 )
{
struct V_1 * V_2 ;
struct V_1 * V_7 ;
int V_39 ;
if ( ! ( ( type | V_10 ) & V_33 ) ) {
type |= V_33 ;
V_10 |= V_33 ;
}
V_7 = F_37 ( V_9 , type , V_10 ) ;
if ( F_23 ( V_7 ) || ! F_12 ( V_7 ) )
return V_7 ;
V_39 = F_39 ( V_42 , V_7 ) ;
if ( V_39 == V_43 )
V_2 = F_32 ( V_7 ) ;
else {
F_5 ( V_7 ) ;
V_2 = F_19 ( - V_32 ) ;
}
F_29 ( V_7 ) ;
return V_2 ;
}
static int F_42 ( struct V_44 * V_45 , T_1 type , T_1 V_10 )
{
const struct V_46 * V_47 = V_45 -> V_48 -> V_49 ;
if ( V_47 )
return V_47 -> V_50 ( V_45 , type , V_10 ) ;
switch ( F_43 ( V_45 ) ) {
case V_51 :
return F_44 ( V_45 ) ;
case V_52 :
return F_45 ( V_45 ) ;
default:
break;
}
F_46 () ;
return - V_53 ;
}
static void F_47 ( struct V_44 * V_45 )
{
const struct V_46 * type = V_45 -> V_48 -> V_49 ;
if ( type ) {
if ( V_45 -> exit )
V_45 -> exit ( V_45 ) ;
return;
}
switch ( F_43 ( V_45 ) ) {
case V_51 :
F_48 ( V_45 ) ;
break;
case V_52 :
F_49 ( V_45 ) ;
break;
default:
F_46 () ;
}
}
static unsigned int F_50 ( struct V_1 * V_2 , T_1 type , T_1 V_10 )
{
const struct V_46 * V_47 = V_2 -> V_49 ;
unsigned int V_54 ;
V_54 = V_2 -> V_55 & ~ ( F_51 () - 1 ) ;
if ( V_47 )
return V_54 + V_47 -> V_56 ( V_2 , type , V_10 ) ;
switch ( V_2 -> V_15 & V_57 ) {
default:
F_46 () ;
case V_51 :
V_54 += F_52 ( V_2 ) ;
break;
case V_52 :
V_54 += F_53 ( V_2 ) ;
break;
}
return V_54 ;
}
void F_54 ( struct V_1 * V_2 )
{
F_26 ( & V_25 ) ;
V_2 -> V_15 |= V_58 ;
F_28 ( & V_25 ) ;
}
struct V_44 * F_55 ( struct V_1 * V_2 , T_1 type ,
T_1 V_10 )
{
struct V_44 * V_45 = NULL ;
unsigned int V_59 ;
int V_60 = - V_20 ;
V_59 = sizeof( * V_45 ) + F_50 ( V_2 , type , V_10 ) ;
V_45 = F_18 ( V_59 , V_19 ) ;
if ( V_45 == NULL )
goto V_61;
V_45 -> V_48 = V_2 ;
V_60 = F_42 ( V_45 , type , V_10 ) ;
if ( V_60 )
goto V_62;
if ( ! V_45 -> exit && V_2 -> V_63 && ( V_60 = V_2 -> V_63 ( V_45 ) ) )
goto V_64;
goto V_65;
V_64:
F_47 ( V_45 ) ;
V_62:
if ( V_60 == - V_34 )
F_54 ( V_2 ) ;
F_16 ( V_45 ) ;
V_61:
V_45 = F_19 ( V_60 ) ;
V_65:
return V_45 ;
}
struct V_44 * F_56 ( const char * V_66 , T_1 type , T_1 V_10 )
{
struct V_44 * V_45 ;
int V_60 ;
for (; ; ) {
struct V_1 * V_2 ;
V_2 = F_41 ( V_66 , type , V_10 ) ;
if ( F_23 ( V_2 ) ) {
V_60 = F_57 ( V_2 ) ;
goto V_60;
}
V_45 = F_55 ( V_2 , type , V_10 ) ;
if ( ! F_23 ( V_45 ) )
return V_45 ;
F_5 ( V_2 ) ;
V_60 = F_57 ( V_45 ) ;
V_60:
if ( V_60 != - V_34 )
break;
if ( F_58 ( V_67 ) ) {
V_60 = - V_30 ;
break;
}
}
return F_19 ( V_60 ) ;
}
void * F_59 ( struct V_1 * V_2 ,
const struct V_46 * V_68 )
{
char * V_69 ;
struct V_44 * V_45 = NULL ;
unsigned int V_70 ;
unsigned int V_71 ;
int V_60 = - V_20 ;
V_70 = V_68 -> V_70 ;
V_71 = V_70 + sizeof( * V_45 ) + V_68 -> V_72 ( V_2 ) ;
V_69 = F_18 ( V_71 , V_19 ) ;
if ( V_69 == NULL )
goto V_61;
V_45 = (struct V_44 * ) ( V_69 + V_70 ) ;
V_45 -> V_48 = V_2 ;
V_60 = V_68 -> V_73 ( V_45 ) ;
if ( V_60 )
goto V_62;
if ( ! V_45 -> exit && V_2 -> V_63 && ( V_60 = V_2 -> V_63 ( V_45 ) ) )
goto V_64;
goto V_65;
V_64:
F_47 ( V_45 ) ;
V_62:
if ( V_60 == - V_34 )
F_54 ( V_2 ) ;
F_16 ( V_69 ) ;
V_61:
V_69 = F_19 ( V_60 ) ;
V_65:
return V_69 ;
}
struct V_1 * F_60 ( const char * V_66 ,
const struct V_46 * V_68 ,
T_1 type , T_1 V_10 )
{
struct V_1 * (* F_61)( const char * V_9 , T_1 type , T_1 V_10 ) =
F_41 ;
if ( V_68 ) {
type &= V_68 -> V_74 ;
V_10 &= V_68 -> V_74 ;
type |= V_68 -> type ;
V_10 |= V_68 -> V_75 ;
if ( V_68 -> F_61 )
F_61 = V_68 -> F_61 ;
}
return F_61 ( V_66 , type , V_10 ) ;
}
void * F_62 ( const char * V_66 ,
const struct V_46 * V_68 , T_1 type , T_1 V_10 )
{
void * V_45 ;
int V_60 ;
for (; ; ) {
struct V_1 * V_2 ;
V_2 = F_60 ( V_66 , V_68 , type , V_10 ) ;
if ( F_23 ( V_2 ) ) {
V_60 = F_57 ( V_2 ) ;
goto V_60;
}
V_45 = F_59 ( V_2 , V_68 ) ;
if ( ! F_23 ( V_45 ) )
return V_45 ;
F_5 ( V_2 ) ;
V_60 = F_57 ( V_45 ) ;
V_60:
if ( V_60 != - V_34 )
break;
if ( F_58 ( V_67 ) ) {
V_60 = - V_30 ;
break;
}
}
return F_19 ( V_60 ) ;
}
void F_63 ( void * V_69 , struct V_44 * V_45 )
{
struct V_1 * V_2 ;
if ( F_13 ( ! V_69 ) )
return;
V_2 = V_45 -> V_48 ;
if ( ! V_45 -> exit && V_2 -> V_76 )
V_2 -> V_76 ( V_45 ) ;
F_47 ( V_45 ) ;
F_5 ( V_2 ) ;
F_64 ( V_69 ) ;
}
int F_65 ( const char * V_9 , T_1 type , T_1 V_10 )
{
int V_77 = 0 ;
struct V_1 * V_2 = F_41 ( V_9 , type , V_10 ) ;
if ( ! F_23 ( V_2 ) ) {
F_5 ( V_2 ) ;
V_77 = 1 ;
}
return V_77 ;
}
