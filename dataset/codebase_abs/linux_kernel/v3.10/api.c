struct V_1 * F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_2 -> V_3 ) ? F_3 ( V_2 ) : NULL ;
}
void F_4 ( struct V_1 * V_2 )
{
struct V_4 * V_4 = V_2 -> V_3 ;
F_5 ( V_2 ) ;
F_6 ( V_4 ) ;
}
static inline int F_7 ( struct V_5 * V_6 )
{
return V_6 -> V_2 . V_7 [ 0 ] ;
}
static struct V_1 * F_8 ( const char * V_8 , T_1 type ,
T_1 V_9 )
{
struct V_1 * V_10 , * V_2 = NULL ;
int V_11 = - 2 ;
F_9 (q, &crypto_alg_list, cra_list) {
int V_12 , V_13 ;
if ( F_10 ( V_10 ) )
continue;
if ( ( V_10 -> V_14 ^ type ) & V_9 )
continue;
if ( F_11 ( V_10 ) &&
! F_7 ( (struct V_5 * ) V_10 ) &&
( (struct V_5 * ) V_10 ) -> V_9 != V_9 )
continue;
V_12 = ! strcmp ( V_10 -> V_7 , V_8 ) ;
V_13 = ! strcmp ( V_10 -> V_15 , V_8 ) ;
if ( ! V_12 && ! ( V_13 && V_10 -> V_16 > V_11 ) )
continue;
if ( F_12 ( ! F_1 ( V_10 ) ) )
continue;
V_11 = V_10 -> V_16 ;
if ( V_2 )
F_4 ( V_2 ) ;
V_2 = V_10 ;
if ( V_12 )
break;
}
return V_2 ;
}
static void F_13 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = ( void * ) V_2 ;
F_14 ( ! F_11 ( V_2 ) ) ;
if ( V_6 -> V_17 )
F_4 ( V_6 -> V_17 ) ;
F_15 ( V_6 ) ;
}
struct V_5 * F_16 ( const char * V_8 , T_1 type , T_1 V_9 )
{
struct V_5 * V_6 ;
V_6 = F_17 ( sizeof( * V_6 ) , V_18 ) ;
if ( ! V_6 )
return F_18 ( - V_19 ) ;
V_6 -> V_9 = V_9 ;
V_6 -> V_2 . V_14 = V_20 | type ;
V_6 -> V_2 . V_16 = - 1 ;
V_6 -> V_2 . V_21 = F_13 ;
F_19 ( V_6 -> V_2 . V_15 , V_8 , V_22 ) ;
F_20 ( & V_6 -> V_23 ) ;
return V_6 ;
}
static struct V_1 * F_21 ( const char * V_8 , T_1 type ,
T_1 V_9 )
{
struct V_1 * V_2 ;
struct V_5 * V_6 ;
V_6 = F_16 ( V_8 , type , V_9 ) ;
if ( F_22 ( V_6 ) )
return F_23 ( V_6 ) ;
F_24 ( & V_6 -> V_2 . V_24 , 2 ) ;
F_25 ( & V_25 ) ;
V_2 = F_8 ( V_8 , type , V_9 ) ;
if ( ! V_2 ) {
V_2 = & V_6 -> V_2 ;
F_26 ( & V_2 -> V_26 , & V_27 ) ;
}
F_27 ( & V_25 ) ;
if ( V_2 != & V_6 -> V_2 )
F_15 ( V_6 ) ;
return V_2 ;
}
void F_28 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = ( void * ) V_2 ;
F_25 ( & V_25 ) ;
F_29 ( & V_2 -> V_26 ) ;
F_27 ( & V_25 ) ;
F_30 ( & V_6 -> V_23 ) ;
F_5 ( V_2 ) ;
}
static struct V_1 * F_31 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = ( void * ) V_2 ;
long V_28 ;
V_28 = F_32 (
& V_6 -> V_23 , 60 * V_29 ) ;
V_2 = V_6 -> V_17 ;
if ( V_28 < 0 )
V_2 = F_18 ( - V_30 ) ;
else if ( ! V_28 )
V_2 = F_18 ( - V_31 ) ;
else if ( ! V_2 )
V_2 = F_18 ( - V_32 ) ;
else if ( F_7 ( V_6 ) &&
! ( V_2 -> V_14 & V_33 ) )
V_2 = F_18 ( - V_34 ) ;
else if ( ! F_1 ( V_2 ) )
V_2 = F_18 ( - V_34 ) ;
F_4 ( & V_6 -> V_2 ) ;
return V_2 ;
}
struct V_1 * F_33 ( const char * V_8 , T_1 type , T_1 V_9 )
{
struct V_1 * V_2 ;
F_34 ( & V_25 ) ;
V_2 = F_8 ( V_8 , type , V_9 ) ;
F_35 ( & V_25 ) ;
return V_2 ;
}
struct V_1 * F_36 ( const char * V_8 , T_1 type , T_1 V_9 )
{
struct V_1 * V_2 ;
if ( ! V_8 )
return F_18 ( - V_32 ) ;
V_9 &= ~ ( V_20 | V_35 ) ;
type &= V_9 ;
V_2 = F_33 ( V_8 , type , V_9 ) ;
if ( ! V_2 ) {
F_37 ( L_1 , V_8 ) ;
if ( ! ( ( type ^ V_36 ) & V_9 &
V_36 ) )
F_37 ( L_2 , V_8 ) ;
V_2 = F_33 ( V_8 , type , V_9 ) ;
}
if ( V_2 )
return F_11 ( V_2 ) ? F_31 ( V_2 ) : V_2 ;
return F_21 ( V_8 , type , V_9 ) ;
}
int F_38 ( unsigned long V_37 , void * V_38 )
{
int V_39 ;
V_39 = F_39 ( & V_40 , V_37 , V_38 ) ;
if ( V_39 == V_41 ) {
F_37 ( L_3 ) ;
V_39 = F_39 ( & V_40 , V_37 , V_38 ) ;
}
return V_39 ;
}
struct V_1 * F_40 ( const char * V_8 , T_1 type , T_1 V_9 )
{
struct V_1 * V_2 ;
struct V_1 * V_6 ;
int V_39 ;
if ( ! ( ( type | V_9 ) & V_33 ) ) {
type |= V_33 ;
V_9 |= V_33 ;
}
V_6 = F_36 ( V_8 , type , V_9 ) ;
if ( F_22 ( V_6 ) || ! F_11 ( V_6 ) )
return V_6 ;
V_39 = F_38 ( V_42 , V_6 ) ;
if ( V_39 == V_43 )
V_2 = F_31 ( V_6 ) ;
else {
F_4 ( V_6 ) ;
V_2 = F_18 ( - V_32 ) ;
}
F_28 ( V_6 ) ;
return V_2 ;
}
static int F_41 ( struct V_44 * V_45 , T_1 type , T_1 V_9 )
{
const struct V_46 * V_47 = V_45 -> V_48 -> V_49 ;
if ( V_47 )
return V_47 -> V_50 ( V_45 , type , V_9 ) ;
switch ( F_42 ( V_45 ) ) {
case V_51 :
return F_43 ( V_45 ) ;
case V_52 :
return F_44 ( V_45 ) ;
default:
break;
}
F_45 () ;
return - V_53 ;
}
static void F_46 ( struct V_44 * V_45 )
{
const struct V_46 * type = V_45 -> V_48 -> V_49 ;
if ( type ) {
if ( V_45 -> exit )
V_45 -> exit ( V_45 ) ;
return;
}
switch ( F_42 ( V_45 ) ) {
case V_51 :
F_47 ( V_45 ) ;
break;
case V_52 :
F_48 ( V_45 ) ;
break;
default:
F_45 () ;
}
}
static unsigned int F_49 ( struct V_1 * V_2 , T_1 type , T_1 V_9 )
{
const struct V_46 * V_47 = V_2 -> V_49 ;
unsigned int V_54 ;
V_54 = V_2 -> V_55 & ~ ( F_50 () - 1 ) ;
if ( V_47 )
return V_54 + V_47 -> V_56 ( V_2 , type , V_9 ) ;
switch ( V_2 -> V_14 & V_57 ) {
default:
F_45 () ;
case V_51 :
V_54 += F_51 ( V_2 ) ;
break;
case V_52 :
V_54 += F_52 ( V_2 ) ;
break;
}
return V_54 ;
}
void F_53 ( struct V_1 * V_2 )
{
F_25 ( & V_25 ) ;
V_2 -> V_14 |= V_58 ;
F_27 ( & V_25 ) ;
}
struct V_44 * F_54 ( struct V_1 * V_2 , T_1 type ,
T_1 V_9 )
{
struct V_44 * V_45 = NULL ;
unsigned int V_59 ;
int V_60 = - V_19 ;
V_59 = sizeof( * V_45 ) + F_49 ( V_2 , type , V_9 ) ;
V_45 = F_17 ( V_59 , V_18 ) ;
if ( V_45 == NULL )
goto V_61;
V_45 -> V_48 = V_2 ;
V_60 = F_41 ( V_45 , type , V_9 ) ;
if ( V_60 )
goto V_62;
if ( ! V_45 -> exit && V_2 -> V_63 && ( V_60 = V_2 -> V_63 ( V_45 ) ) )
goto V_64;
goto V_65;
V_64:
F_46 ( V_45 ) ;
V_62:
if ( V_60 == - V_34 )
F_53 ( V_2 ) ;
F_15 ( V_45 ) ;
V_61:
V_45 = F_18 ( V_60 ) ;
V_65:
return V_45 ;
}
struct V_44 * F_55 ( const char * V_66 , T_1 type , T_1 V_9 )
{
struct V_44 * V_45 ;
int V_60 ;
for (; ; ) {
struct V_1 * V_2 ;
V_2 = F_40 ( V_66 , type , V_9 ) ;
if ( F_22 ( V_2 ) ) {
V_60 = F_56 ( V_2 ) ;
goto V_60;
}
V_45 = F_54 ( V_2 , type , V_9 ) ;
if ( ! F_22 ( V_45 ) )
return V_45 ;
F_4 ( V_2 ) ;
V_60 = F_56 ( V_45 ) ;
V_60:
if ( V_60 != - V_34 )
break;
if ( F_57 ( V_67 ) ) {
V_60 = - V_30 ;
break;
}
}
return F_18 ( V_60 ) ;
}
void * F_58 ( struct V_1 * V_2 ,
const struct V_46 * V_68 )
{
char * V_69 ;
struct V_44 * V_45 = NULL ;
unsigned int V_70 ;
unsigned int V_71 ;
int V_60 = - V_19 ;
V_70 = V_68 -> V_70 ;
V_71 = V_70 + sizeof( * V_45 ) + V_68 -> V_72 ( V_2 ) ;
V_69 = F_17 ( V_71 , V_18 ) ;
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
F_46 ( V_45 ) ;
V_62:
if ( V_60 == - V_34 )
F_53 ( V_2 ) ;
F_15 ( V_69 ) ;
V_61:
V_69 = F_18 ( V_60 ) ;
V_65:
return V_69 ;
}
struct V_1 * F_59 ( const char * V_66 ,
const struct V_46 * V_68 ,
T_1 type , T_1 V_9 )
{
struct V_1 * (* F_60)( const char * V_8 , T_1 type , T_1 V_9 ) =
F_40 ;
if ( V_68 ) {
type &= V_68 -> V_74 ;
V_9 &= V_68 -> V_74 ;
type |= V_68 -> type ;
V_9 |= V_68 -> V_75 ;
if ( V_68 -> F_60 )
F_60 = V_68 -> F_60 ;
}
return F_60 ( V_66 , type , V_9 ) ;
}
void * F_61 ( const char * V_66 ,
const struct V_46 * V_68 , T_1 type , T_1 V_9 )
{
void * V_45 ;
int V_60 ;
for (; ; ) {
struct V_1 * V_2 ;
V_2 = F_59 ( V_66 , V_68 , type , V_9 ) ;
if ( F_22 ( V_2 ) ) {
V_60 = F_56 ( V_2 ) ;
goto V_60;
}
V_45 = F_58 ( V_2 , V_68 ) ;
if ( ! F_22 ( V_45 ) )
return V_45 ;
F_4 ( V_2 ) ;
V_60 = F_56 ( V_45 ) ;
V_60:
if ( V_60 != - V_34 )
break;
if ( F_57 ( V_67 ) ) {
V_60 = - V_30 ;
break;
}
}
return F_18 ( V_60 ) ;
}
void F_62 ( void * V_69 , struct V_44 * V_45 )
{
struct V_1 * V_2 ;
if ( F_12 ( ! V_69 ) )
return;
V_2 = V_45 -> V_48 ;
if ( ! V_45 -> exit && V_2 -> V_76 )
V_2 -> V_76 ( V_45 ) ;
F_46 ( V_45 ) ;
F_4 ( V_2 ) ;
F_63 ( V_69 ) ;
}
int F_64 ( const char * V_8 , T_1 type , T_1 V_9 )
{
int V_77 = 0 ;
struct V_1 * V_2 = F_40 ( V_8 , type , V_9 ) ;
if ( ! F_22 ( V_2 ) ) {
F_4 ( V_2 ) ;
V_77 = 1 ;
}
return V_77 ;
}
