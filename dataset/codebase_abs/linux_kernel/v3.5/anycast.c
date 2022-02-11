int F_1 ( struct V_1 * V_2 , int V_3 , const struct V_4 * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = NULL ;
struct V_10 * V_11 ;
struct V_12 * V_13 ;
struct V_14 * V_14 = F_3 ( V_2 ) ;
int V_15 = ! V_14 -> V_16 . V_17 -> V_18 ;
int V_19 = 0 ;
if ( ! F_4 ( V_20 ) )
return - V_21 ;
if ( F_5 ( V_5 ) )
return - V_22 ;
if ( F_6 ( V_14 , V_5 , NULL , 0 ) )
return - V_22 ;
V_13 = F_7 ( V_2 , sizeof( struct V_12 ) , V_23 ) ;
if ( V_13 == NULL )
return - V_24 ;
V_13 -> V_25 = NULL ;
V_13 -> V_26 = * V_5 ;
F_8 () ;
if ( V_3 == 0 ) {
struct V_27 * V_28 ;
V_28 = F_9 ( V_14 , V_5 , NULL , 0 , 0 ) ;
if ( V_28 ) {
V_9 = V_28 -> V_29 . V_9 ;
F_10 ( & V_28 -> V_29 ) ;
} else if ( V_15 ) {
V_19 = - V_30 ;
goto error;
} else {
V_9 = F_11 ( V_14 , V_31 ,
V_31 | V_32 ) ;
}
} else
V_9 = F_12 ( V_14 , V_3 ) ;
if ( V_9 == NULL ) {
V_19 = - V_33 ;
goto error;
}
V_11 = F_13 ( V_9 ) ;
if ( ! V_11 ) {
if ( V_3 )
V_19 = - V_33 ;
else
V_19 = - V_30 ;
goto error;
}
V_15 = ! V_11 -> V_34 . V_18 ;
V_13 -> V_35 = V_9 -> V_3 ;
if ( ! F_14 ( V_5 , V_9 ) ) {
if ( V_15 )
V_19 = - V_30 ;
if ( V_19 )
goto error;
}
V_19 = F_15 ( V_9 , V_5 ) ;
if ( ! V_19 ) {
F_16 ( & V_36 ) ;
V_13 -> V_25 = V_7 -> V_37 ;
V_7 -> V_37 = V_13 ;
F_17 ( & V_36 ) ;
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
struct V_12 * V_13 , * V_38 ;
struct V_14 * V_14 = F_3 ( V_2 ) ;
F_16 ( & V_36 ) ;
V_38 = NULL ;
for ( V_13 = V_7 -> V_37 ; V_13 ; V_13 = V_13 -> V_25 ) {
if ( ( V_3 == 0 || V_13 -> V_35 == V_3 ) &&
F_21 ( & V_13 -> V_26 , V_5 ) )
break;
V_38 = V_13 ;
}
if ( ! V_13 ) {
F_17 ( & V_36 ) ;
return - V_39 ;
}
if ( V_38 )
V_38 -> V_25 = V_13 -> V_25 ;
else
V_7 -> V_37 = V_13 -> V_25 ;
F_17 ( & V_36 ) ;
F_8 () ;
V_9 = F_12 ( V_14 , V_13 -> V_35 ) ;
if ( V_9 )
F_22 ( V_9 , & V_13 -> V_26 ) ;
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
int V_40 ;
F_16 ( & V_36 ) ;
V_13 = V_7 -> V_37 ;
V_7 -> V_37 = NULL ;
F_17 ( & V_36 ) ;
V_40 = 0 ;
F_8 () ;
while ( V_13 ) {
struct V_12 * V_41 = V_13 -> V_25 ;
if ( V_13 -> V_35 != V_40 ) {
V_9 = F_12 ( V_14 , V_13 -> V_35 ) ;
V_40 = V_13 -> V_35 ;
}
if ( V_9 )
F_22 ( V_9 , & V_13 -> V_26 ) ;
F_19 ( V_2 , V_13 , sizeof( * V_13 ) ) ;
V_13 = V_41 ;
}
F_18 () ;
}
static void F_24 ( struct V_42 * V_43 )
{
if ( F_25 ( & V_43 -> V_44 ) ) {
F_26 ( V_43 -> V_45 ) ;
F_10 ( & V_43 -> V_46 -> V_29 ) ;
F_27 ( V_43 ) ;
}
}
int F_15 ( struct V_8 * V_9 , const struct V_4 * V_5 )
{
struct V_42 * V_47 ;
struct V_10 * V_11 ;
struct V_27 * V_28 ;
int V_19 ;
V_11 = F_28 ( V_9 ) ;
if ( V_11 == NULL )
return - V_22 ;
F_16 ( & V_11 -> V_48 ) ;
if ( V_11 -> V_49 ) {
V_19 = - V_33 ;
goto V_50;
}
for ( V_47 = V_11 -> V_51 ; V_47 ; V_47 = V_47 -> V_52 ) {
if ( F_21 ( & V_47 -> V_53 , V_5 ) ) {
V_47 -> V_54 ++ ;
V_19 = 0 ;
goto V_50;
}
}
V_47 = F_29 ( sizeof( struct V_42 ) , V_55 ) ;
if ( V_47 == NULL ) {
V_19 = - V_24 ;
goto V_50;
}
V_28 = F_30 ( V_11 , V_5 , true ) ;
if ( F_31 ( V_28 ) ) {
F_27 ( V_47 ) ;
V_19 = F_32 ( V_28 ) ;
goto V_50;
}
V_47 -> V_53 = * V_5 ;
V_47 -> V_45 = V_11 ;
V_47 -> V_46 = V_28 ;
V_47 -> V_54 = 1 ;
V_47 -> V_56 = V_47 -> V_57 = V_58 ;
F_33 ( & V_47 -> V_44 , 2 ) ;
F_34 ( & V_47 -> V_59 ) ;
V_47 -> V_52 = V_11 -> V_51 ;
V_11 -> V_51 = V_47 ;
F_17 ( & V_11 -> V_48 ) ;
F_35 ( V_28 ) ;
F_36 ( V_9 , & V_47 -> V_53 ) ;
F_24 ( V_47 ) ;
return 0 ;
V_50:
F_17 ( & V_11 -> V_48 ) ;
F_26 ( V_11 ) ;
return V_19 ;
}
int F_37 ( struct V_10 * V_11 , const struct V_4 * V_5 )
{
struct V_42 * V_47 , * V_60 ;
F_16 ( & V_11 -> V_48 ) ;
V_60 = NULL ;
for ( V_47 = V_11 -> V_51 ; V_47 ; V_47 = V_47 -> V_52 ) {
if ( F_21 ( & V_47 -> V_53 , V_5 ) )
break;
V_60 = V_47 ;
}
if ( ! V_47 ) {
F_17 ( & V_11 -> V_48 ) ;
return - V_39 ;
}
if ( -- V_47 -> V_54 > 0 ) {
F_17 ( & V_11 -> V_48 ) ;
return 0 ;
}
if ( V_60 )
V_60 -> V_52 = V_47 -> V_52 ;
else
V_11 -> V_51 = V_47 -> V_52 ;
F_17 ( & V_11 -> V_48 ) ;
F_38 ( V_11 , & V_47 -> V_53 ) ;
F_39 ( & V_47 -> V_46 -> V_29 ) ;
F_40 ( V_47 -> V_46 ) ;
F_24 ( V_47 ) ;
return 0 ;
}
static int F_22 ( struct V_8 * V_9 , const struct V_4 * V_5 )
{
struct V_10 * V_11 = F_13 ( V_9 ) ;
if ( V_11 == NULL )
return - V_33 ;
return F_37 ( V_11 , V_5 ) ;
}
static bool F_41 ( struct V_8 * V_9 , const struct V_4 * V_5 )
{
struct V_10 * V_11 ;
struct V_42 * V_47 ;
V_11 = F_13 ( V_9 ) ;
if ( V_11 ) {
F_42 ( & V_11 -> V_48 ) ;
for ( V_47 = V_11 -> V_51 ; V_47 ; V_47 = V_47 -> V_52 )
if ( F_21 ( & V_47 -> V_53 , V_5 ) )
break;
F_43 ( & V_11 -> V_48 ) ;
return V_47 != NULL ;
}
return false ;
}
bool F_44 ( struct V_14 * V_14 , struct V_8 * V_9 ,
const struct V_4 * V_5 )
{
bool V_61 = false ;
F_8 () ;
if ( V_9 )
V_61 = F_41 ( V_9 , V_5 ) ;
else
F_45 (net, dev)
if ( F_41 ( V_9 , V_5 ) ) {
V_61 = true ;
break;
}
F_18 () ;
return V_61 ;
}
static inline struct V_42 * F_46 ( struct V_62 * V_63 )
{
struct V_42 * V_64 = NULL ;
struct V_65 * V_66 = F_47 ( V_63 ) ;
struct V_14 * V_14 = F_48 ( V_63 ) ;
V_66 -> V_11 = NULL ;
F_45 (net, state->dev) {
struct V_10 * V_11 ;
V_11 = F_13 ( V_66 -> V_9 ) ;
if ( ! V_11 )
continue;
F_42 ( & V_11 -> V_48 ) ;
V_64 = V_11 -> V_51 ;
if ( V_64 ) {
V_66 -> V_11 = V_11 ;
break;
}
F_43 ( & V_11 -> V_48 ) ;
}
return V_64 ;
}
static struct V_42 * F_49 ( struct V_62 * V_63 , struct V_42 * V_64 )
{
struct V_65 * V_66 = F_47 ( V_63 ) ;
V_64 = V_64 -> V_52 ;
while ( ! V_64 ) {
if ( F_50 ( V_66 -> V_11 != NULL ) )
F_43 ( & V_66 -> V_11 -> V_48 ) ;
V_66 -> V_9 = F_51 ( V_66 -> V_9 ) ;
if ( ! V_66 -> V_9 ) {
V_66 -> V_11 = NULL ;
break;
}
V_66 -> V_11 = F_13 ( V_66 -> V_9 ) ;
if ( ! V_66 -> V_11 )
continue;
F_42 ( & V_66 -> V_11 -> V_48 ) ;
V_64 = V_66 -> V_11 -> V_51 ;
}
return V_64 ;
}
static struct V_42 * F_52 ( struct V_62 * V_63 , T_1 V_67 )
{
struct V_42 * V_64 = F_46 ( V_63 ) ;
if ( V_64 )
while ( V_67 && ( V_64 = F_49 ( V_63 , V_64 ) ) != NULL )
-- V_67 ;
return V_67 ? NULL : V_64 ;
}
static void * F_53 ( struct V_62 * V_63 , T_1 * V_67 )
__acquires( T_2 )
{
F_8 () ;
return F_52 ( V_63 , * V_67 ) ;
}
static void * F_54 ( struct V_62 * V_63 , void * V_68 , T_1 * V_67 )
{
struct V_42 * V_64 = F_49 ( V_63 , V_68 ) ;
++ * V_67 ;
return V_64 ;
}
static void F_55 ( struct V_62 * V_63 , void * V_68 )
__releases( T_2 )
{
struct V_65 * V_66 = F_47 ( V_63 ) ;
if ( F_50 ( V_66 -> V_11 != NULL ) ) {
F_43 ( & V_66 -> V_11 -> V_48 ) ;
V_66 -> V_11 = NULL ;
}
F_18 () ;
}
static int F_56 ( struct V_62 * V_63 , void * V_68 )
{
struct V_42 * V_64 = (struct V_42 * ) V_68 ;
struct V_65 * V_66 = F_47 ( V_63 ) ;
F_57 ( V_63 , L_1 ,
V_66 -> V_9 -> V_3 , V_66 -> V_9 -> V_69 ,
& V_64 -> V_53 , V_64 -> V_54 ) ;
return 0 ;
}
static int F_58 ( struct V_70 * V_70 , struct V_71 * V_71 )
{
return F_59 ( V_70 , V_71 , & V_72 ,
sizeof( struct V_65 ) ) ;
}
int T_3 F_60 ( struct V_14 * V_14 )
{
if ( ! F_61 ( V_14 , L_2 , V_73 , & V_74 ) )
return - V_24 ;
return 0 ;
}
void F_62 ( struct V_14 * V_14 )
{
F_63 ( V_14 , L_2 ) ;
}
