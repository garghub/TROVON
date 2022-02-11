int F_1 ( struct V_1 * V_2 , int V_3 , const struct V_4 * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = NULL ;
struct V_10 * V_11 ;
struct V_12 * V_13 ;
struct V_14 * V_14 = F_3 ( V_2 ) ;
int V_15 = ! V_14 -> V_16 . V_17 -> V_18 ;
int V_19 = 0 ;
F_4 () ;
if ( ! F_5 ( V_14 -> V_20 , V_21 ) )
return - V_22 ;
if ( F_6 ( V_5 ) )
return - V_23 ;
if ( F_7 ( V_14 , V_5 , NULL , 0 ) )
return - V_23 ;
V_13 = F_8 ( V_2 , sizeof( struct V_12 ) , V_24 ) ;
if ( ! V_13 )
return - V_25 ;
V_13 -> V_26 = NULL ;
V_13 -> V_27 = * V_5 ;
if ( V_3 == 0 ) {
struct V_28 * V_29 ;
V_29 = F_9 ( V_14 , V_5 , NULL , 0 , 0 ) ;
if ( V_29 ) {
V_9 = V_29 -> V_30 . V_9 ;
F_10 ( V_29 ) ;
} else if ( V_15 ) {
V_19 = - V_31 ;
goto error;
} else {
V_9 = F_11 ( V_14 , V_32 ,
V_32 | V_33 ) ;
}
} else
V_9 = F_12 ( V_14 , V_3 ) ;
if ( ! V_9 ) {
V_19 = - V_34 ;
goto error;
}
V_11 = F_13 ( V_9 ) ;
if ( ! V_11 ) {
if ( V_3 )
V_19 = - V_34 ;
else
V_19 = - V_31 ;
goto error;
}
V_15 = ! V_11 -> V_35 . V_18 ;
V_13 -> V_36 = V_9 -> V_3 ;
if ( ! F_14 ( V_5 , V_9 ) ) {
if ( V_15 )
V_19 = - V_31 ;
if ( V_19 )
goto error;
}
V_19 = F_15 ( V_11 , V_5 ) ;
if ( ! V_19 ) {
V_13 -> V_26 = V_7 -> V_37 ;
V_7 -> V_37 = V_13 ;
V_13 = NULL ;
}
error:
if ( V_13 )
F_16 ( V_2 , V_13 , sizeof( * V_13 ) ) ;
return V_19 ;
}
int F_17 ( struct V_1 * V_2 , int V_3 , const struct V_4 * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 ;
struct V_12 * V_13 , * V_38 ;
struct V_14 * V_14 = F_3 ( V_2 ) ;
F_4 () ;
V_38 = NULL ;
for ( V_13 = V_7 -> V_37 ; V_13 ; V_13 = V_13 -> V_26 ) {
if ( ( V_3 == 0 || V_13 -> V_36 == V_3 ) &&
F_18 ( & V_13 -> V_27 , V_5 ) )
break;
V_38 = V_13 ;
}
if ( ! V_13 )
return - V_39 ;
if ( V_38 )
V_38 -> V_26 = V_13 -> V_26 ;
else
V_7 -> V_37 = V_13 -> V_26 ;
V_9 = F_12 ( V_14 , V_13 -> V_36 ) ;
if ( V_9 )
F_19 ( V_9 , & V_13 -> V_27 ) ;
F_16 ( V_2 , V_13 , sizeof( * V_13 ) ) ;
return 0 ;
}
void F_20 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = NULL ;
struct V_12 * V_13 ;
struct V_14 * V_14 = F_3 ( V_2 ) ;
int V_40 ;
if ( ! V_7 -> V_37 )
return;
F_21 () ;
V_13 = V_7 -> V_37 ;
V_7 -> V_37 = NULL ;
V_40 = 0 ;
while ( V_13 ) {
struct V_12 * V_41 = V_13 -> V_26 ;
if ( V_13 -> V_36 != V_40 ) {
V_9 = F_12 ( V_14 , V_13 -> V_36 ) ;
V_40 = V_13 -> V_36 ;
}
if ( V_9 )
F_19 ( V_9 , & V_13 -> V_27 ) ;
F_16 ( V_2 , V_13 , sizeof( * V_13 ) ) ;
V_13 = V_41 ;
}
F_22 () ;
}
static void F_23 ( struct V_42 * V_43 )
{
F_24 ( & V_43 -> V_44 ) ;
}
static void F_25 ( struct V_42 * V_45 )
{
if ( F_26 ( & V_45 -> V_44 ) ) {
F_27 ( V_45 -> V_46 ) ;
F_28 ( & V_45 -> V_47 -> V_30 ) ;
F_29 ( V_45 ) ;
}
}
static struct V_42 * F_30 ( struct V_28 * V_29 ,
const struct V_4 * V_5 )
{
struct V_10 * V_11 = V_29 -> V_48 ;
struct V_42 * V_43 ;
V_43 = F_31 ( sizeof( * V_43 ) , V_49 ) ;
if ( ! V_43 )
return NULL ;
V_43 -> V_50 = * V_5 ;
F_32 ( V_11 ) ;
V_43 -> V_46 = V_11 ;
V_43 -> V_47 = V_29 ;
V_43 -> V_51 = 1 ;
V_43 -> V_52 = V_43 -> V_53 = V_54 ;
F_33 ( & V_43 -> V_44 , 1 ) ;
return V_43 ;
}
int F_15 ( struct V_10 * V_11 , const struct V_4 * V_5 )
{
struct V_42 * V_43 ;
struct V_28 * V_29 ;
int V_19 ;
F_4 () ;
F_34 ( & V_11 -> V_55 ) ;
if ( V_11 -> V_56 ) {
V_19 = - V_34 ;
goto V_57;
}
for ( V_43 = V_11 -> V_58 ; V_43 ; V_43 = V_43 -> V_59 ) {
if ( F_18 ( & V_43 -> V_50 , V_5 ) ) {
V_43 -> V_51 ++ ;
V_19 = 0 ;
goto V_57;
}
}
V_29 = F_35 ( V_11 , V_5 , true ) ;
if ( F_36 ( V_29 ) ) {
V_19 = F_37 ( V_29 ) ;
goto V_57;
}
V_43 = F_30 ( V_29 , V_5 ) ;
if ( ! V_43 ) {
F_10 ( V_29 ) ;
V_19 = - V_25 ;
goto V_57;
}
V_43 -> V_59 = V_11 -> V_58 ;
V_11 -> V_58 = V_43 ;
F_23 ( V_43 ) ;
F_38 ( & V_11 -> V_55 ) ;
F_39 ( V_29 ) ;
F_40 ( V_11 -> V_9 , & V_43 -> V_50 ) ;
F_25 ( V_43 ) ;
return 0 ;
V_57:
F_38 ( & V_11 -> V_55 ) ;
return V_19 ;
}
int F_41 ( struct V_10 * V_11 , const struct V_4 * V_5 )
{
struct V_42 * V_43 , * V_60 ;
F_4 () ;
F_34 ( & V_11 -> V_55 ) ;
V_60 = NULL ;
for ( V_43 = V_11 -> V_58 ; V_43 ; V_43 = V_43 -> V_59 ) {
if ( F_18 ( & V_43 -> V_50 , V_5 ) )
break;
V_60 = V_43 ;
}
if ( ! V_43 ) {
F_38 ( & V_11 -> V_55 ) ;
return - V_39 ;
}
if ( -- V_43 -> V_51 > 0 ) {
F_38 ( & V_11 -> V_55 ) ;
return 0 ;
}
if ( V_60 )
V_60 -> V_59 = V_43 -> V_59 ;
else
V_11 -> V_58 = V_43 -> V_59 ;
F_38 ( & V_11 -> V_55 ) ;
F_42 ( V_11 , & V_43 -> V_50 ) ;
F_43 ( & V_43 -> V_47 -> V_30 ) ;
F_44 ( V_43 -> V_47 ) ;
F_25 ( V_43 ) ;
return 0 ;
}
static int F_19 ( struct V_8 * V_9 , const struct V_4 * V_5 )
{
struct V_10 * V_11 = F_13 ( V_9 ) ;
if ( ! V_11 )
return - V_34 ;
return F_41 ( V_11 , V_5 ) ;
}
void F_45 ( struct V_10 * V_11 )
{
struct V_42 * V_43 ;
F_34 ( & V_11 -> V_55 ) ;
while ( ( V_43 = V_11 -> V_58 ) != NULL ) {
V_11 -> V_58 = V_43 -> V_59 ;
F_38 ( & V_11 -> V_55 ) ;
F_42 ( V_11 , & V_43 -> V_50 ) ;
F_43 ( & V_43 -> V_47 -> V_30 ) ;
F_44 ( V_43 -> V_47 ) ;
F_25 ( V_43 ) ;
F_34 ( & V_11 -> V_55 ) ;
}
F_38 ( & V_11 -> V_55 ) ;
}
static bool F_46 ( struct V_8 * V_9 , const struct V_4 * V_5 )
{
struct V_10 * V_11 ;
struct V_42 * V_43 ;
V_11 = F_13 ( V_9 ) ;
if ( V_11 ) {
F_47 ( & V_11 -> V_55 ) ;
for ( V_43 = V_11 -> V_58 ; V_43 ; V_43 = V_43 -> V_59 )
if ( F_18 ( & V_43 -> V_50 , V_5 ) )
break;
F_48 ( & V_11 -> V_55 ) ;
return V_43 != NULL ;
}
return false ;
}
bool F_49 ( struct V_14 * V_14 , struct V_8 * V_9 ,
const struct V_4 * V_5 )
{
bool V_61 = false ;
F_50 () ;
if ( V_9 )
V_61 = F_46 ( V_9 , V_5 ) ;
else
F_51 (net, dev)
if ( F_46 ( V_9 , V_5 ) ) {
V_61 = true ;
break;
}
F_52 () ;
return V_61 ;
}
bool F_53 ( struct V_14 * V_14 , struct V_8 * V_9 ,
const struct V_4 * V_5 )
{
return F_49 ( V_14 ,
( F_54 ( V_5 ) & V_62 ?
V_9 : NULL ) ,
V_5 ) ;
}
static inline struct V_42 * F_55 ( struct V_63 * V_64 )
{
struct V_42 * V_65 = NULL ;
struct V_66 * V_67 = F_56 ( V_64 ) ;
struct V_14 * V_14 = F_57 ( V_64 ) ;
V_67 -> V_11 = NULL ;
F_51 (net, state->dev) {
struct V_10 * V_11 ;
V_11 = F_13 ( V_67 -> V_9 ) ;
if ( ! V_11 )
continue;
F_47 ( & V_11 -> V_55 ) ;
V_65 = V_11 -> V_58 ;
if ( V_65 ) {
V_67 -> V_11 = V_11 ;
break;
}
F_48 ( & V_11 -> V_55 ) ;
}
return V_65 ;
}
static struct V_42 * F_58 ( struct V_63 * V_64 , struct V_42 * V_65 )
{
struct V_66 * V_67 = F_56 ( V_64 ) ;
V_65 = V_65 -> V_59 ;
while ( ! V_65 ) {
if ( F_59 ( V_67 -> V_11 != NULL ) )
F_48 ( & V_67 -> V_11 -> V_55 ) ;
V_67 -> V_9 = F_60 ( V_67 -> V_9 ) ;
if ( ! V_67 -> V_9 ) {
V_67 -> V_11 = NULL ;
break;
}
V_67 -> V_11 = F_13 ( V_67 -> V_9 ) ;
if ( ! V_67 -> V_11 )
continue;
F_47 ( & V_67 -> V_11 -> V_55 ) ;
V_65 = V_67 -> V_11 -> V_58 ;
}
return V_65 ;
}
static struct V_42 * F_61 ( struct V_63 * V_64 , T_1 V_68 )
{
struct V_42 * V_65 = F_55 ( V_64 ) ;
if ( V_65 )
while ( V_68 && ( V_65 = F_58 ( V_64 , V_65 ) ) != NULL )
-- V_68 ;
return V_68 ? NULL : V_65 ;
}
static void * F_62 ( struct V_63 * V_64 , T_1 * V_68 )
__acquires( T_2 )
{
F_50 () ;
return F_61 ( V_64 , * V_68 ) ;
}
static void * F_63 ( struct V_63 * V_64 , void * V_69 , T_1 * V_68 )
{
struct V_42 * V_65 = F_58 ( V_64 , V_69 ) ;
++ * V_68 ;
return V_65 ;
}
static void F_64 ( struct V_63 * V_64 , void * V_69 )
__releases( T_2 )
{
struct V_66 * V_67 = F_56 ( V_64 ) ;
if ( F_59 ( V_67 -> V_11 != NULL ) ) {
F_48 ( & V_67 -> V_11 -> V_55 ) ;
V_67 -> V_11 = NULL ;
}
F_52 () ;
}
static int F_65 ( struct V_63 * V_64 , void * V_69 )
{
struct V_42 * V_65 = (struct V_42 * ) V_69 ;
struct V_66 * V_67 = F_56 ( V_64 ) ;
F_66 ( V_64 , L_1 ,
V_67 -> V_9 -> V_3 , V_67 -> V_9 -> V_70 ,
& V_65 -> V_50 , V_65 -> V_51 ) ;
return 0 ;
}
static int F_67 ( struct V_71 * V_71 , struct V_72 * V_72 )
{
return F_68 ( V_71 , V_72 , & V_73 ,
sizeof( struct V_66 ) ) ;
}
int T_3 F_69 ( struct V_14 * V_14 )
{
if ( ! F_70 ( L_2 , V_74 , V_14 -> V_75 , & V_76 ) )
return - V_25 ;
return 0 ;
}
void F_71 ( struct V_14 * V_14 )
{
F_72 ( L_2 , V_14 -> V_75 ) ;
}
