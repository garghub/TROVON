static inline int F_1 ( unsigned V_1 )
{
return V_1 % V_2 ;
}
void F_2 ( struct V_3 * V_4 , T_1 V_5 )
{
struct V_6 * V_7 ;
F_3 ( & V_8 ) ;
for ( V_7 = V_9 [ F_1 ( V_5 ) ] ; V_7 ; V_7 = V_7 -> V_10 ) {
if ( V_7 -> V_1 == V_5 )
F_4 ( V_4 , L_1 , V_7 -> V_1 , V_7 -> V_11 ) ;
}
F_5 ( & V_8 ) ;
}
static int F_6 ( void )
{
int V_12 ;
struct V_6 * V_7 ;
for ( V_12 = F_7 ( V_9 ) - 1 ; V_12 > V_13 ; V_12 -- ) {
if ( V_9 [ V_12 ] == NULL )
return V_12 ;
}
for ( V_12 = V_14 ;
V_12 > V_15 ; V_12 -- ) {
for ( V_7 = V_9 [ F_1 ( V_12 ) ] ; V_7 ; V_7 = V_7 -> V_10 )
if ( V_7 -> V_1 == V_12 )
break;
if ( V_7 == NULL || V_7 -> V_1 != V_12 )
return V_12 ;
}
return - V_16 ;
}
static struct V_6 *
F_8 ( unsigned int V_1 , unsigned int V_17 ,
int V_18 , const char * V_11 )
{
struct V_6 * V_7 , * * V_19 ;
int V_20 = 0 ;
int V_12 ;
V_7 = F_9 ( sizeof( struct V_6 ) , V_21 ) ;
if ( V_7 == NULL )
return F_10 ( - V_22 ) ;
F_3 ( & V_8 ) ;
if ( V_1 == 0 ) {
V_20 = F_6 () ;
if ( V_20 < 0 ) {
F_11 ( L_2 ,
V_11 ) ;
goto V_23;
}
V_1 = V_20 ;
}
if ( V_1 >= V_24 ) {
F_11 ( L_3 ,
V_11 , V_1 , V_24 ) ;
V_20 = - V_25 ;
goto V_23;
}
V_7 -> V_1 = V_1 ;
V_7 -> V_17 = V_17 ;
V_7 -> V_18 = V_18 ;
F_12 ( V_7 -> V_11 , V_11 , sizeof( V_7 -> V_11 ) ) ;
V_12 = F_1 ( V_1 ) ;
for ( V_19 = & V_9 [ V_12 ] ; * V_19 ; V_19 = & ( * V_19 ) -> V_10 )
if ( ( * V_19 ) -> V_1 > V_1 ||
( ( * V_19 ) -> V_1 == V_1 &&
( ( ( * V_19 ) -> V_17 >= V_17 ) ||
( ( * V_19 ) -> V_17 + ( * V_19 ) -> V_18 > V_17 ) ) ) )
break;
if ( * V_19 && ( * V_19 ) -> V_1 == V_1 ) {
int V_26 = ( * V_19 ) -> V_17 ;
int V_27 = ( * V_19 ) -> V_17 + ( * V_19 ) -> V_18 - 1 ;
int V_28 = V_17 ;
int V_29 = V_17 + V_18 - 1 ;
if ( V_29 >= V_26 && V_29 <= V_27 ) {
V_20 = - V_16 ;
goto V_23;
}
if ( V_28 <= V_27 && V_28 >= V_26 ) {
V_20 = - V_16 ;
goto V_23;
}
}
V_7 -> V_10 = * V_19 ;
* V_19 = V_7 ;
F_5 ( & V_8 ) ;
return V_7 ;
V_23:
F_5 ( & V_8 ) ;
F_13 ( V_7 ) ;
return F_10 ( V_20 ) ;
}
static struct V_6 *
F_14 ( unsigned V_1 , unsigned V_17 , int V_18 )
{
struct V_6 * V_7 = NULL , * * V_19 ;
int V_12 = F_1 ( V_1 ) ;
F_3 ( & V_8 ) ;
for ( V_19 = & V_9 [ V_12 ] ; * V_19 ; V_19 = & ( * V_19 ) -> V_10 )
if ( ( * V_19 ) -> V_1 == V_1 &&
( * V_19 ) -> V_17 == V_17 &&
( * V_19 ) -> V_18 == V_18 )
break;
if ( * V_19 ) {
V_7 = * V_19 ;
* V_19 = V_7 -> V_10 ;
}
F_5 ( & V_8 ) ;
return V_7 ;
}
int F_15 ( T_2 V_30 , unsigned V_31 , const char * V_11 )
{
struct V_6 * V_7 ;
T_2 V_32 = V_30 + V_31 ;
T_2 V_33 , V_10 ;
for ( V_33 = V_30 ; V_33 < V_32 ; V_33 = V_10 ) {
V_10 = F_16 ( F_17 ( V_33 ) + 1 , 0 ) ;
if ( V_10 > V_32 )
V_10 = V_32 ;
V_7 = F_8 ( F_17 ( V_33 ) , F_18 ( V_33 ) ,
V_10 - V_33 , V_11 ) ;
if ( F_19 ( V_7 ) )
goto V_34;
}
return 0 ;
V_34:
V_32 = V_33 ;
for ( V_33 = V_30 ; V_33 < V_32 ; V_33 = V_10 ) {
V_10 = F_16 ( F_17 ( V_33 ) + 1 , 0 ) ;
F_13 ( F_14 ( F_17 ( V_33 ) , F_18 ( V_33 ) , V_10 - V_33 ) ) ;
}
return F_20 ( V_7 ) ;
}
int F_21 ( T_2 * V_35 , unsigned V_17 , unsigned V_31 ,
const char * V_11 )
{
struct V_6 * V_7 ;
V_7 = F_8 ( 0 , V_17 , V_31 , V_11 ) ;
if ( F_19 ( V_7 ) )
return F_20 ( V_7 ) ;
* V_35 = F_16 ( V_7 -> V_1 , V_7 -> V_17 ) ;
return 0 ;
}
int F_22 ( unsigned int V_1 , unsigned int V_17 ,
unsigned int V_31 , const char * V_11 ,
const struct V_36 * V_37 )
{
struct V_6 * V_7 ;
struct V_38 * V_38 ;
int V_39 = - V_22 ;
V_7 = F_8 ( V_1 , V_17 , V_31 , V_11 ) ;
if ( F_19 ( V_7 ) )
return F_20 ( V_7 ) ;
V_38 = F_23 () ;
if ( ! V_38 )
goto V_40;
V_38 -> V_41 = V_37 -> V_41 ;
V_38 -> V_42 = V_37 ;
F_24 ( & V_38 -> V_43 , L_4 , V_11 ) ;
V_39 = F_25 ( V_38 , F_16 ( V_7 -> V_1 , V_17 ) , V_31 ) ;
if ( V_39 )
goto V_23;
V_7 -> V_38 = V_38 ;
return V_1 ? 0 : V_7 -> V_1 ;
V_23:
F_26 ( & V_38 -> V_43 ) ;
V_40:
F_13 ( F_14 ( V_7 -> V_1 , V_17 , V_31 ) ) ;
return V_39 ;
}
void F_27 ( T_2 V_30 , unsigned V_31 )
{
T_2 V_32 = V_30 + V_31 ;
T_2 V_33 , V_10 ;
for ( V_33 = V_30 ; V_33 < V_32 ; V_33 = V_10 ) {
V_10 = F_16 ( F_17 ( V_33 ) + 1 , 0 ) ;
if ( V_10 > V_32 )
V_10 = V_32 ;
F_13 ( F_14 ( F_17 ( V_33 ) , F_18 ( V_33 ) , V_10 - V_33 ) ) ;
}
}
void F_28 ( unsigned int V_1 , unsigned int V_17 ,
unsigned int V_31 , const char * V_11 )
{
struct V_6 * V_7 ;
V_7 = F_14 ( V_1 , V_17 , V_31 ) ;
if ( V_7 && V_7 -> V_38 )
F_29 ( V_7 -> V_38 ) ;
F_13 ( V_7 ) ;
}
static struct V_44 * F_30 ( struct V_38 * V_45 )
{
struct V_46 * V_41 = V_45 -> V_41 ;
struct V_44 * V_43 ;
if ( V_41 && ! F_31 ( V_41 ) )
return NULL ;
V_43 = F_32 ( & V_45 -> V_43 ) ;
if ( ! V_43 )
F_33 ( V_41 ) ;
return V_43 ;
}
void F_34 ( struct V_38 * V_45 )
{
if ( V_45 ) {
struct V_46 * V_41 = V_45 -> V_41 ;
F_26 ( & V_45 -> V_43 ) ;
F_33 ( V_41 ) ;
}
}
static int F_35 ( struct V_47 * V_47 , struct V_48 * V_49 )
{
const struct V_36 * V_37 ;
struct V_38 * V_45 ;
struct V_38 * V_50 = NULL ;
int V_20 = 0 ;
F_36 ( & V_51 ) ;
V_45 = V_47 -> V_52 ;
if ( ! V_45 ) {
struct V_44 * V_43 ;
int V_53 ;
F_37 ( & V_51 ) ;
V_43 = F_38 ( V_54 , V_47 -> V_55 , & V_53 ) ;
if ( ! V_43 )
return - V_56 ;
V_50 = F_39 ( V_43 , struct V_38 , V_43 ) ;
F_36 ( & V_51 ) ;
V_45 = V_47 -> V_52 ;
if ( ! V_45 ) {
V_47 -> V_52 = V_45 = V_50 ;
F_40 ( & V_47 -> V_57 , & V_45 -> V_58 ) ;
V_50 = NULL ;
} else if ( ! F_30 ( V_45 ) )
V_20 = - V_56 ;
} else if ( ! F_30 ( V_45 ) )
V_20 = - V_56 ;
F_37 ( & V_51 ) ;
F_34 ( V_50 ) ;
if ( V_20 )
return V_20 ;
V_20 = - V_56 ;
V_37 = F_41 ( V_45 -> V_42 ) ;
if ( ! V_37 )
goto V_59;
F_42 ( V_49 , V_37 ) ;
if ( V_49 -> V_60 -> V_61 ) {
V_20 = V_49 -> V_60 -> V_61 ( V_47 , V_49 ) ;
if ( V_20 )
goto V_59;
}
return 0 ;
V_59:
F_34 ( V_45 ) ;
return V_20 ;
}
void F_43 ( struct V_47 * V_47 )
{
F_36 ( & V_51 ) ;
F_44 ( & V_47 -> V_57 ) ;
V_47 -> V_52 = NULL ;
V_47 -> V_62 = & V_47 -> V_63 ;
F_37 ( & V_51 ) ;
}
static void F_45 ( struct V_38 * V_38 )
{
F_36 ( & V_51 ) ;
while ( ! F_46 ( & V_38 -> V_58 ) ) {
struct V_47 * V_47 ;
V_47 = F_39 ( V_38 -> V_58 . V_10 , struct V_47 , V_57 ) ;
F_44 ( & V_47 -> V_57 ) ;
V_47 -> V_52 = NULL ;
}
F_37 ( & V_51 ) ;
}
static struct V_44 * F_47 ( T_2 V_35 , int * V_64 , void * V_65 )
{
struct V_38 * V_45 = V_65 ;
return & V_45 -> V_43 ;
}
static int F_48 ( T_2 V_35 , void * V_65 )
{
struct V_38 * V_45 = V_65 ;
return F_30 ( V_45 ) ? 0 : - 1 ;
}
int F_25 ( struct V_38 * V_45 , T_2 V_35 , unsigned V_31 )
{
int error ;
V_45 -> V_35 = V_35 ;
V_45 -> V_31 = V_31 ;
error = F_49 ( V_54 , V_35 , V_31 , NULL ,
F_47 , F_48 , V_45 ) ;
if ( error )
return error ;
F_32 ( V_45 -> V_43 . V_66 ) ;
return 0 ;
}
void F_50 ( struct V_38 * V_45 , struct V_44 * V_43 )
{
F_51 ( ! V_43 -> V_67 ) ;
V_45 -> V_43 . V_66 = V_43 ;
}
int F_52 ( struct V_38 * V_38 , struct V_68 * V_35 )
{
int V_69 = 0 ;
if ( V_35 -> V_70 ) {
F_50 ( V_38 , & V_35 -> V_43 ) ;
V_69 = F_25 ( V_38 , V_35 -> V_70 , 1 ) ;
if ( V_69 )
return V_69 ;
}
V_69 = F_53 ( V_35 ) ;
if ( V_69 )
F_29 ( V_38 ) ;
return V_69 ;
}
void F_54 ( struct V_38 * V_38 , struct V_68 * V_35 )
{
F_55 ( V_35 ) ;
if ( V_35 -> V_70 )
F_29 ( V_38 ) ;
}
static void F_56 ( T_2 V_35 , unsigned V_31 )
{
F_57 ( V_54 , V_35 , V_31 ) ;
}
void F_29 ( struct V_38 * V_45 )
{
F_56 ( V_45 -> V_35 , V_45 -> V_31 ) ;
F_26 ( & V_45 -> V_43 ) ;
}
static void F_58 ( struct V_44 * V_43 )
{
struct V_38 * V_45 = F_39 ( V_43 , struct V_38 , V_43 ) ;
struct V_44 * V_66 = V_43 -> V_66 ;
F_45 ( V_45 ) ;
F_26 ( V_66 ) ;
}
static void F_59 ( struct V_44 * V_43 )
{
struct V_38 * V_45 = F_39 ( V_43 , struct V_38 , V_43 ) ;
struct V_44 * V_66 = V_43 -> V_66 ;
F_45 ( V_45 ) ;
F_13 ( V_45 ) ;
F_26 ( V_66 ) ;
}
struct V_38 * F_23 ( void )
{
struct V_38 * V_45 = F_9 ( sizeof( struct V_38 ) , V_21 ) ;
if ( V_45 ) {
F_60 ( & V_45 -> V_58 ) ;
F_61 ( & V_45 -> V_43 , & V_71 ) ;
}
return V_45 ;
}
void F_62 ( struct V_38 * V_38 , const struct V_36 * V_37 )
{
memset ( V_38 , 0 , sizeof *V_38 ) ;
F_60 ( & V_38 -> V_58 ) ;
F_61 ( & V_38 -> V_43 , & V_72 ) ;
V_38 -> V_42 = V_37 ;
}
static struct V_44 * F_63 ( T_2 V_35 , int * V_64 , void * V_65 )
{
if ( F_64 ( L_5 , F_17 ( V_35 ) , F_18 ( V_35 ) ) > 0 )
F_64 ( L_6 , F_17 ( V_35 ) ) ;
return NULL ;
}
void T_3 F_65 ( void )
{
V_54 = F_66 ( F_63 , & V_8 ) ;
}
