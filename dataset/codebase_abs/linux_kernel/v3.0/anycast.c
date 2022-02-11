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
F_8 ( & V_13 -> V_26 , V_5 ) ;
F_9 () ;
if ( V_3 == 0 ) {
struct V_27 * V_28 ;
V_28 = F_10 ( V_14 , V_5 , NULL , 0 , 0 ) ;
if ( V_28 ) {
V_9 = V_28 -> V_29 ;
F_11 ( & V_28 -> V_30 ) ;
} else if ( V_15 ) {
V_19 = - V_31 ;
goto error;
} else {
V_9 = F_12 ( V_14 , V_32 ,
V_32 | V_33 ) ;
}
} else
V_9 = F_13 ( V_14 , V_3 ) ;
if ( V_9 == NULL ) {
V_19 = - V_34 ;
goto error;
}
V_11 = F_14 ( V_9 ) ;
if ( ! V_11 ) {
if ( V_3 )
V_19 = - V_34 ;
else
V_19 = - V_31 ;
goto error;
}
V_15 = ! V_11 -> V_35 . V_18 ;
V_13 -> V_36 = V_9 -> V_3 ;
if ( ! F_15 ( V_5 , V_9 ) ) {
if ( V_15 )
V_19 = - V_31 ;
if ( V_19 )
goto error;
}
V_19 = F_16 ( V_9 , V_5 ) ;
if ( ! V_19 ) {
F_17 ( & V_37 ) ;
V_13 -> V_25 = V_7 -> V_38 ;
V_7 -> V_38 = V_13 ;
F_18 ( & V_37 ) ;
V_13 = NULL ;
}
error:
F_19 () ;
if ( V_13 )
F_20 ( V_2 , V_13 , sizeof( * V_13 ) ) ;
return V_19 ;
}
int F_21 ( struct V_1 * V_2 , int V_3 , const struct V_4 * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 ;
struct V_12 * V_13 , * V_39 ;
struct V_14 * V_14 = F_3 ( V_2 ) ;
F_17 ( & V_37 ) ;
V_39 = NULL ;
for ( V_13 = V_7 -> V_38 ; V_13 ; V_13 = V_13 -> V_25 ) {
if ( ( V_3 == 0 || V_13 -> V_36 == V_3 ) &&
F_22 ( & V_13 -> V_26 , V_5 ) )
break;
V_39 = V_13 ;
}
if ( ! V_13 ) {
F_18 ( & V_37 ) ;
return - V_40 ;
}
if ( V_39 )
V_39 -> V_25 = V_13 -> V_25 ;
else
V_7 -> V_38 = V_13 -> V_25 ;
F_18 ( & V_37 ) ;
F_9 () ;
V_9 = F_13 ( V_14 , V_13 -> V_36 ) ;
if ( V_9 )
F_23 ( V_9 , & V_13 -> V_26 ) ;
F_19 () ;
F_20 ( V_2 , V_13 , sizeof( * V_13 ) ) ;
return 0 ;
}
void F_24 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = NULL ;
struct V_12 * V_13 ;
struct V_14 * V_14 = F_3 ( V_2 ) ;
int V_41 ;
F_17 ( & V_37 ) ;
V_13 = V_7 -> V_38 ;
V_7 -> V_38 = NULL ;
F_18 ( & V_37 ) ;
V_41 = 0 ;
F_9 () ;
while ( V_13 ) {
struct V_12 * V_42 = V_13 -> V_25 ;
if ( V_13 -> V_36 != V_41 ) {
V_9 = F_13 ( V_14 , V_13 -> V_36 ) ;
V_41 = V_13 -> V_36 ;
}
if ( V_9 )
F_23 ( V_9 , & V_13 -> V_26 ) ;
F_20 ( V_2 , V_13 , sizeof( * V_13 ) ) ;
V_13 = V_42 ;
}
F_19 () ;
}
static void F_25 ( struct V_43 * V_44 )
{
if ( F_26 ( & V_44 -> V_45 ) ) {
F_27 ( V_44 -> V_46 ) ;
F_11 ( & V_44 -> V_47 -> V_30 ) ;
F_28 ( V_44 ) ;
}
}
int F_16 ( struct V_8 * V_9 , const struct V_4 * V_5 )
{
struct V_43 * V_48 ;
struct V_10 * V_11 ;
struct V_27 * V_28 ;
int V_19 ;
V_11 = F_29 ( V_9 ) ;
if ( V_11 == NULL )
return - V_22 ;
F_17 ( & V_11 -> V_49 ) ;
if ( V_11 -> V_50 ) {
V_19 = - V_34 ;
goto V_51;
}
for ( V_48 = V_11 -> V_52 ; V_48 ; V_48 = V_48 -> V_53 ) {
if ( F_22 ( & V_48 -> V_54 , V_5 ) ) {
V_48 -> V_55 ++ ;
V_19 = 0 ;
goto V_51;
}
}
V_48 = F_30 ( sizeof( struct V_43 ) , V_56 ) ;
if ( V_48 == NULL ) {
V_19 = - V_24 ;
goto V_51;
}
V_28 = F_31 ( V_11 , V_5 , 1 ) ;
if ( F_32 ( V_28 ) ) {
F_28 ( V_48 ) ;
V_19 = F_33 ( V_28 ) ;
goto V_51;
}
F_8 ( & V_48 -> V_54 , V_5 ) ;
V_48 -> V_46 = V_11 ;
V_48 -> V_47 = V_28 ;
V_48 -> V_55 = 1 ;
V_48 -> V_57 = V_48 -> V_58 = V_59 ;
F_34 ( & V_48 -> V_45 , 2 ) ;
F_35 ( & V_48 -> V_60 ) ;
V_48 -> V_53 = V_11 -> V_52 ;
V_11 -> V_52 = V_48 ;
F_18 ( & V_11 -> V_49 ) ;
F_36 ( V_28 ) ;
F_37 ( V_9 , & V_48 -> V_54 ) ;
F_25 ( V_48 ) ;
return 0 ;
V_51:
F_18 ( & V_11 -> V_49 ) ;
F_27 ( V_11 ) ;
return V_19 ;
}
int F_38 ( struct V_10 * V_11 , const struct V_4 * V_5 )
{
struct V_43 * V_48 , * V_61 ;
F_17 ( & V_11 -> V_49 ) ;
V_61 = NULL ;
for ( V_48 = V_11 -> V_52 ; V_48 ; V_48 = V_48 -> V_53 ) {
if ( F_22 ( & V_48 -> V_54 , V_5 ) )
break;
V_61 = V_48 ;
}
if ( ! V_48 ) {
F_18 ( & V_11 -> V_49 ) ;
return - V_40 ;
}
if ( -- V_48 -> V_55 > 0 ) {
F_18 ( & V_11 -> V_49 ) ;
return 0 ;
}
if ( V_61 )
V_61 -> V_53 = V_48 -> V_53 ;
else
V_11 -> V_52 = V_48 -> V_53 ;
F_18 ( & V_11 -> V_49 ) ;
F_39 ( V_11 , & V_48 -> V_54 ) ;
F_40 ( & V_48 -> V_47 -> V_30 ) ;
F_41 ( V_48 -> V_47 ) ;
F_25 ( V_48 ) ;
return 0 ;
}
static int F_23 ( struct V_8 * V_9 , const struct V_4 * V_5 )
{
struct V_10 * V_11 = F_14 ( V_9 ) ;
if ( V_11 == NULL )
return - V_34 ;
return F_38 ( V_11 , V_5 ) ;
}
static int F_42 ( struct V_8 * V_9 , const struct V_4 * V_5 )
{
struct V_10 * V_11 ;
struct V_43 * V_48 ;
V_11 = F_14 ( V_9 ) ;
if ( V_11 ) {
F_43 ( & V_11 -> V_49 ) ;
for ( V_48 = V_11 -> V_52 ; V_48 ; V_48 = V_48 -> V_53 )
if ( F_22 ( & V_48 -> V_54 , V_5 ) )
break;
F_44 ( & V_11 -> V_49 ) ;
return V_48 != NULL ;
}
return 0 ;
}
int F_45 ( struct V_14 * V_14 , struct V_8 * V_9 ,
const struct V_4 * V_5 )
{
int V_62 = 0 ;
F_9 () ;
if ( V_9 )
V_62 = F_42 ( V_9 , V_5 ) ;
else
F_46 (net, dev)
if ( F_42 ( V_9 , V_5 ) ) {
V_62 = 1 ;
break;
}
F_19 () ;
return V_62 ;
}
static inline struct V_43 * F_47 ( struct V_63 * V_64 )
{
struct V_43 * V_65 = NULL ;
struct V_66 * V_67 = F_48 ( V_64 ) ;
struct V_14 * V_14 = F_49 ( V_64 ) ;
V_67 -> V_11 = NULL ;
F_46 (net, state->dev) {
struct V_10 * V_11 ;
V_11 = F_14 ( V_67 -> V_9 ) ;
if ( ! V_11 )
continue;
F_43 ( & V_11 -> V_49 ) ;
V_65 = V_11 -> V_52 ;
if ( V_65 ) {
V_67 -> V_11 = V_11 ;
break;
}
F_44 ( & V_11 -> V_49 ) ;
}
return V_65 ;
}
static struct V_43 * F_50 ( struct V_63 * V_64 , struct V_43 * V_65 )
{
struct V_66 * V_67 = F_48 ( V_64 ) ;
V_65 = V_65 -> V_53 ;
while ( ! V_65 ) {
if ( F_51 ( V_67 -> V_11 != NULL ) )
F_44 ( & V_67 -> V_11 -> V_49 ) ;
V_67 -> V_9 = F_52 ( V_67 -> V_9 ) ;
if ( ! V_67 -> V_9 ) {
V_67 -> V_11 = NULL ;
break;
}
V_67 -> V_11 = F_14 ( V_67 -> V_9 ) ;
if ( ! V_67 -> V_11 )
continue;
F_43 ( & V_67 -> V_11 -> V_49 ) ;
V_65 = V_67 -> V_11 -> V_52 ;
}
return V_65 ;
}
static struct V_43 * F_53 ( struct V_63 * V_64 , T_1 V_68 )
{
struct V_43 * V_65 = F_47 ( V_64 ) ;
if ( V_65 )
while ( V_68 && ( V_65 = F_50 ( V_64 , V_65 ) ) != NULL )
-- V_68 ;
return V_68 ? NULL : V_65 ;
}
static void * F_54 ( struct V_63 * V_64 , T_1 * V_68 )
__acquires( T_2 )
{
F_9 () ;
return F_53 ( V_64 , * V_68 ) ;
}
static void * F_55 ( struct V_63 * V_64 , void * V_69 , T_1 * V_68 )
{
struct V_43 * V_65 = F_50 ( V_64 , V_69 ) ;
++ * V_68 ;
return V_65 ;
}
static void F_56 ( struct V_63 * V_64 , void * V_69 )
__releases( T_2 )
{
struct V_66 * V_67 = F_48 ( V_64 ) ;
if ( F_51 ( V_67 -> V_11 != NULL ) ) {
F_44 ( & V_67 -> V_11 -> V_49 ) ;
V_67 -> V_11 = NULL ;
}
F_19 () ;
}
static int F_57 ( struct V_63 * V_64 , void * V_69 )
{
struct V_43 * V_65 = (struct V_43 * ) V_69 ;
struct V_66 * V_67 = F_48 ( V_64 ) ;
F_58 ( V_64 , L_1 ,
V_67 -> V_9 -> V_3 , V_67 -> V_9 -> V_70 ,
& V_65 -> V_54 , V_65 -> V_55 ) ;
return 0 ;
}
static int F_59 ( struct V_71 * V_71 , struct V_72 * V_72 )
{
return F_60 ( V_71 , V_72 , & V_73 ,
sizeof( struct V_66 ) ) ;
}
int T_3 F_61 ( struct V_14 * V_14 )
{
if ( ! F_62 ( V_14 , L_2 , V_74 , & V_75 ) )
return - V_24 ;
return 0 ;
}
void F_63 ( struct V_14 * V_14 )
{
F_64 ( V_14 , L_2 ) ;
}
