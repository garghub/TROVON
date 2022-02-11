int F_1 ( struct V_1 * V_2 , int V_3 , const struct V_4 * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = NULL ;
struct V_10 * V_11 ;
struct V_12 * V_13 ;
struct V_14 * V_14 = F_3 ( V_2 ) ;
int V_15 = ! V_14 -> V_16 . V_17 -> V_18 ;
int V_19 = 0 ;
if ( ! F_4 ( V_14 -> V_20 , V_21 ) )
return - V_22 ;
if ( F_5 ( V_5 ) )
return - V_23 ;
if ( F_6 ( V_14 , V_5 , NULL , 0 ) )
return - V_23 ;
V_13 = F_7 ( V_2 , sizeof( struct V_12 ) , V_24 ) ;
if ( V_13 == NULL )
return - V_25 ;
V_13 -> V_26 = NULL ;
V_13 -> V_27 = * V_5 ;
F_8 () ;
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
if ( V_9 == NULL ) {
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
V_19 = F_15 ( V_9 , V_5 ) ;
if ( ! V_19 ) {
F_16 ( & V_37 ) ;
V_13 -> V_26 = V_7 -> V_38 ;
V_7 -> V_38 = V_13 ;
F_17 ( & V_37 ) ;
V_13 = NULL ;
}
error:
F_18 () ;
if ( V_13 )
F_19 ( V_2 , V_13 , sizeof( * V_13 ) ) ;
return V_19 ;
}
int F_20 ( struct V_1 * V_2 , int V_3 , const struct V_4 * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 ;
struct V_12 * V_13 , * V_39 ;
struct V_14 * V_14 = F_3 ( V_2 ) ;
F_16 ( & V_37 ) ;
V_39 = NULL ;
for ( V_13 = V_7 -> V_38 ; V_13 ; V_13 = V_13 -> V_26 ) {
if ( ( V_3 == 0 || V_13 -> V_36 == V_3 ) &&
F_21 ( & V_13 -> V_27 , V_5 ) )
break;
V_39 = V_13 ;
}
if ( ! V_13 ) {
F_17 ( & V_37 ) ;
return - V_40 ;
}
if ( V_39 )
V_39 -> V_26 = V_13 -> V_26 ;
else
V_7 -> V_38 = V_13 -> V_26 ;
F_17 ( & V_37 ) ;
F_8 () ;
V_9 = F_12 ( V_14 , V_13 -> V_36 ) ;
if ( V_9 )
F_22 ( V_9 , & V_13 -> V_27 ) ;
F_18 () ;
F_19 ( V_2 , V_13 , sizeof( * V_13 ) ) ;
return 0 ;
}
void F_23 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = NULL ;
struct V_12 * V_13 ;
struct V_14 * V_14 = F_3 ( V_2 ) ;
int V_41 ;
if ( ! V_7 -> V_38 )
return;
F_16 ( & V_37 ) ;
V_13 = V_7 -> V_38 ;
V_7 -> V_38 = NULL ;
F_17 ( & V_37 ) ;
V_41 = 0 ;
F_8 () ;
while ( V_13 ) {
struct V_12 * V_42 = V_13 -> V_26 ;
if ( V_13 -> V_36 != V_41 ) {
V_9 = F_12 ( V_14 , V_13 -> V_36 ) ;
V_41 = V_13 -> V_36 ;
}
if ( V_9 )
F_22 ( V_9 , & V_13 -> V_27 ) ;
F_19 ( V_2 , V_13 , sizeof( * V_13 ) ) ;
V_13 = V_42 ;
}
F_18 () ;
}
static void F_24 ( struct V_43 * V_44 )
{
if ( F_25 ( & V_44 -> V_45 ) ) {
F_26 ( V_44 -> V_46 ) ;
F_27 ( & V_44 -> V_47 -> V_30 ) ;
F_28 ( V_44 ) ;
}
}
int F_15 ( struct V_8 * V_9 , const struct V_4 * V_5 )
{
struct V_43 * V_48 ;
struct V_10 * V_11 ;
struct V_28 * V_29 ;
int V_19 ;
V_11 = F_29 ( V_9 ) ;
if ( V_11 == NULL )
return - V_23 ;
F_30 ( & V_11 -> V_49 ) ;
if ( V_11 -> V_50 ) {
V_19 = - V_34 ;
goto V_51;
}
for ( V_48 = V_11 -> V_52 ; V_48 ; V_48 = V_48 -> V_53 ) {
if ( F_21 ( & V_48 -> V_54 , V_5 ) ) {
V_48 -> V_55 ++ ;
V_19 = 0 ;
goto V_51;
}
}
V_48 = F_31 ( sizeof( struct V_43 ) , V_56 ) ;
if ( V_48 == NULL ) {
V_19 = - V_25 ;
goto V_51;
}
V_29 = F_32 ( V_11 , V_5 , true ) ;
if ( F_33 ( V_29 ) ) {
F_28 ( V_48 ) ;
V_19 = F_34 ( V_29 ) ;
goto V_51;
}
V_48 -> V_54 = * V_5 ;
V_48 -> V_46 = V_11 ;
V_48 -> V_47 = V_29 ;
V_48 -> V_55 = 1 ;
V_48 -> V_57 = V_48 -> V_58 = V_59 ;
F_35 ( & V_48 -> V_45 , 2 ) ;
F_36 ( & V_48 -> V_60 ) ;
V_48 -> V_53 = V_11 -> V_52 ;
V_11 -> V_52 = V_48 ;
F_37 ( & V_11 -> V_49 ) ;
F_38 ( V_29 ) ;
F_39 ( V_9 , & V_48 -> V_54 ) ;
F_24 ( V_48 ) ;
return 0 ;
V_51:
F_37 ( & V_11 -> V_49 ) ;
F_26 ( V_11 ) ;
return V_19 ;
}
int F_40 ( struct V_10 * V_11 , const struct V_4 * V_5 )
{
struct V_43 * V_48 , * V_61 ;
F_30 ( & V_11 -> V_49 ) ;
V_61 = NULL ;
for ( V_48 = V_11 -> V_52 ; V_48 ; V_48 = V_48 -> V_53 ) {
if ( F_21 ( & V_48 -> V_54 , V_5 ) )
break;
V_61 = V_48 ;
}
if ( ! V_48 ) {
F_37 ( & V_11 -> V_49 ) ;
return - V_40 ;
}
if ( -- V_48 -> V_55 > 0 ) {
F_37 ( & V_11 -> V_49 ) ;
return 0 ;
}
if ( V_61 )
V_61 -> V_53 = V_48 -> V_53 ;
else
V_11 -> V_52 = V_48 -> V_53 ;
F_37 ( & V_11 -> V_49 ) ;
F_41 ( V_11 , & V_48 -> V_54 ) ;
F_42 ( & V_48 -> V_47 -> V_30 ) ;
F_43 ( V_48 -> V_47 ) ;
F_24 ( V_48 ) ;
return 0 ;
}
static int F_22 ( struct V_8 * V_9 , const struct V_4 * V_5 )
{
struct V_10 * V_11 = F_13 ( V_9 ) ;
if ( V_11 == NULL )
return - V_34 ;
return F_40 ( V_11 , V_5 ) ;
}
static bool F_44 ( struct V_8 * V_9 , const struct V_4 * V_5 )
{
struct V_10 * V_11 ;
struct V_43 * V_48 ;
V_11 = F_13 ( V_9 ) ;
if ( V_11 ) {
F_45 ( & V_11 -> V_49 ) ;
for ( V_48 = V_11 -> V_52 ; V_48 ; V_48 = V_48 -> V_53 )
if ( F_21 ( & V_48 -> V_54 , V_5 ) )
break;
F_46 ( & V_11 -> V_49 ) ;
return V_48 != NULL ;
}
return false ;
}
bool F_47 ( struct V_14 * V_14 , struct V_8 * V_9 ,
const struct V_4 * V_5 )
{
bool V_62 = false ;
F_8 () ;
if ( V_9 )
V_62 = F_44 ( V_9 , V_5 ) ;
else
F_48 (net, dev)
if ( F_44 ( V_9 , V_5 ) ) {
V_62 = true ;
break;
}
F_18 () ;
return V_62 ;
}
bool F_49 ( struct V_14 * V_14 , struct V_8 * V_9 ,
const struct V_4 * V_5 )
{
return F_47 ( V_14 ,
( F_50 ( V_5 ) & V_63 ?
V_9 : NULL ) ,
V_5 ) ;
}
static inline struct V_43 * F_51 ( struct V_64 * V_65 )
{
struct V_43 * V_66 = NULL ;
struct V_67 * V_68 = F_52 ( V_65 ) ;
struct V_14 * V_14 = F_53 ( V_65 ) ;
V_68 -> V_11 = NULL ;
F_48 (net, state->dev) {
struct V_10 * V_11 ;
V_11 = F_13 ( V_68 -> V_9 ) ;
if ( ! V_11 )
continue;
F_45 ( & V_11 -> V_49 ) ;
V_66 = V_11 -> V_52 ;
if ( V_66 ) {
V_68 -> V_11 = V_11 ;
break;
}
F_46 ( & V_11 -> V_49 ) ;
}
return V_66 ;
}
static struct V_43 * F_54 ( struct V_64 * V_65 , struct V_43 * V_66 )
{
struct V_67 * V_68 = F_52 ( V_65 ) ;
V_66 = V_66 -> V_53 ;
while ( ! V_66 ) {
if ( F_55 ( V_68 -> V_11 != NULL ) )
F_46 ( & V_68 -> V_11 -> V_49 ) ;
V_68 -> V_9 = F_56 ( V_68 -> V_9 ) ;
if ( ! V_68 -> V_9 ) {
V_68 -> V_11 = NULL ;
break;
}
V_68 -> V_11 = F_13 ( V_68 -> V_9 ) ;
if ( ! V_68 -> V_11 )
continue;
F_45 ( & V_68 -> V_11 -> V_49 ) ;
V_66 = V_68 -> V_11 -> V_52 ;
}
return V_66 ;
}
static struct V_43 * F_57 ( struct V_64 * V_65 , T_1 V_69 )
{
struct V_43 * V_66 = F_51 ( V_65 ) ;
if ( V_66 )
while ( V_69 && ( V_66 = F_54 ( V_65 , V_66 ) ) != NULL )
-- V_69 ;
return V_69 ? NULL : V_66 ;
}
static void * F_58 ( struct V_64 * V_65 , T_1 * V_69 )
__acquires( T_2 )
{
F_8 () ;
return F_57 ( V_65 , * V_69 ) ;
}
static void * F_59 ( struct V_64 * V_65 , void * V_70 , T_1 * V_69 )
{
struct V_43 * V_66 = F_54 ( V_65 , V_70 ) ;
++ * V_69 ;
return V_66 ;
}
static void F_60 ( struct V_64 * V_65 , void * V_70 )
__releases( T_2 )
{
struct V_67 * V_68 = F_52 ( V_65 ) ;
if ( F_55 ( V_68 -> V_11 != NULL ) ) {
F_46 ( & V_68 -> V_11 -> V_49 ) ;
V_68 -> V_11 = NULL ;
}
F_18 () ;
}
static int F_61 ( struct V_64 * V_65 , void * V_70 )
{
struct V_43 * V_66 = (struct V_43 * ) V_70 ;
struct V_67 * V_68 = F_52 ( V_65 ) ;
F_62 ( V_65 , L_1 ,
V_68 -> V_9 -> V_3 , V_68 -> V_9 -> V_71 ,
& V_66 -> V_54 , V_66 -> V_55 ) ;
return 0 ;
}
static int F_63 ( struct V_72 * V_72 , struct V_73 * V_73 )
{
return F_64 ( V_72 , V_73 , & V_74 ,
sizeof( struct V_67 ) ) ;
}
int T_3 F_65 ( struct V_14 * V_14 )
{
if ( ! F_66 ( L_2 , V_75 , V_14 -> V_76 , & V_77 ) )
return - V_25 ;
return 0 ;
}
void F_67 ( struct V_14 * V_14 )
{
F_68 ( L_2 , V_14 -> V_76 ) ;
}
