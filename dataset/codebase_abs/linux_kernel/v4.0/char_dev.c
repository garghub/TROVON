static inline int F_1 ( unsigned V_1 )
{
return V_1 % V_2 ;
}
void F_2 ( struct V_3 * V_4 , T_1 V_5 )
{
struct V_6 * V_7 ;
if ( V_5 < V_2 ) {
F_3 ( & V_8 ) ;
for ( V_7 = V_9 [ V_5 ] ; V_7 ; V_7 = V_7 -> V_10 )
F_4 ( V_4 , L_1 , V_7 -> V_1 , V_7 -> V_11 ) ;
F_5 ( & V_8 ) ;
}
}
static struct V_6 *
F_6 ( unsigned int V_1 , unsigned int V_12 ,
int V_13 , const char * V_11 )
{
struct V_6 * V_7 , * * V_14 ;
int V_15 = 0 ;
int V_16 ;
V_7 = F_7 ( sizeof( struct V_6 ) , V_17 ) ;
if ( V_7 == NULL )
return F_8 ( - V_18 ) ;
F_3 ( & V_8 ) ;
if ( V_1 == 0 ) {
for ( V_16 = F_9 ( V_9 ) - 1 ; V_16 > 0 ; V_16 -- ) {
if ( V_9 [ V_16 ] == NULL )
break;
}
if ( V_16 == 0 ) {
V_15 = - V_19 ;
goto V_20;
}
V_1 = V_16 ;
}
V_7 -> V_1 = V_1 ;
V_7 -> V_12 = V_12 ;
V_7 -> V_13 = V_13 ;
F_10 ( V_7 -> V_11 , V_11 , sizeof( V_7 -> V_11 ) ) ;
V_16 = F_1 ( V_1 ) ;
for ( V_14 = & V_9 [ V_16 ] ; * V_14 ; V_14 = & ( * V_14 ) -> V_10 )
if ( ( * V_14 ) -> V_1 > V_1 ||
( ( * V_14 ) -> V_1 == V_1 &&
( ( ( * V_14 ) -> V_12 >= V_12 ) ||
( ( * V_14 ) -> V_12 + ( * V_14 ) -> V_13 > V_12 ) ) ) )
break;
if ( * V_14 && ( * V_14 ) -> V_1 == V_1 ) {
int V_21 = ( * V_14 ) -> V_12 ;
int V_22 = ( * V_14 ) -> V_12 + ( * V_14 ) -> V_13 - 1 ;
int V_23 = V_12 ;
int V_24 = V_12 + V_13 - 1 ;
if ( V_24 >= V_21 && V_24 <= V_22 ) {
V_15 = - V_19 ;
goto V_20;
}
if ( V_23 <= V_22 && V_23 >= V_21 ) {
V_15 = - V_19 ;
goto V_20;
}
}
V_7 -> V_10 = * V_14 ;
* V_14 = V_7 ;
F_5 ( & V_8 ) ;
return V_7 ;
V_20:
F_5 ( & V_8 ) ;
F_11 ( V_7 ) ;
return F_8 ( V_15 ) ;
}
static struct V_6 *
F_12 ( unsigned V_1 , unsigned V_12 , int V_13 )
{
struct V_6 * V_7 = NULL , * * V_14 ;
int V_16 = F_1 ( V_1 ) ;
F_3 ( & V_8 ) ;
for ( V_14 = & V_9 [ V_16 ] ; * V_14 ; V_14 = & ( * V_14 ) -> V_10 )
if ( ( * V_14 ) -> V_1 == V_1 &&
( * V_14 ) -> V_12 == V_12 &&
( * V_14 ) -> V_13 == V_13 )
break;
if ( * V_14 ) {
V_7 = * V_14 ;
* V_14 = V_7 -> V_10 ;
}
F_5 ( & V_8 ) ;
return V_7 ;
}
int F_13 ( T_2 V_25 , unsigned V_26 , const char * V_11 )
{
struct V_6 * V_7 ;
T_2 V_27 = V_25 + V_26 ;
T_2 V_28 , V_10 ;
for ( V_28 = V_25 ; V_28 < V_27 ; V_28 = V_10 ) {
V_10 = F_14 ( F_15 ( V_28 ) + 1 , 0 ) ;
if ( V_10 > V_27 )
V_10 = V_27 ;
V_7 = F_6 ( F_15 ( V_28 ) , F_16 ( V_28 ) ,
V_10 - V_28 , V_11 ) ;
if ( F_17 ( V_7 ) )
goto V_29;
}
return 0 ;
V_29:
V_27 = V_28 ;
for ( V_28 = V_25 ; V_28 < V_27 ; V_28 = V_10 ) {
V_10 = F_14 ( F_15 ( V_28 ) + 1 , 0 ) ;
F_11 ( F_12 ( F_15 ( V_28 ) , F_16 ( V_28 ) , V_10 - V_28 ) ) ;
}
return F_18 ( V_7 ) ;
}
int F_19 ( T_2 * V_30 , unsigned V_12 , unsigned V_26 ,
const char * V_11 )
{
struct V_6 * V_7 ;
V_7 = F_6 ( 0 , V_12 , V_26 , V_11 ) ;
if ( F_17 ( V_7 ) )
return F_18 ( V_7 ) ;
* V_30 = F_14 ( V_7 -> V_1 , V_7 -> V_12 ) ;
return 0 ;
}
int F_20 ( unsigned int V_1 , unsigned int V_12 ,
unsigned int V_26 , const char * V_11 ,
const struct V_31 * V_32 )
{
struct V_6 * V_7 ;
struct V_33 * V_33 ;
int V_34 = - V_18 ;
V_7 = F_6 ( V_1 , V_12 , V_26 , V_11 ) ;
if ( F_17 ( V_7 ) )
return F_18 ( V_7 ) ;
V_33 = F_21 () ;
if ( ! V_33 )
goto V_35;
V_33 -> V_36 = V_32 -> V_36 ;
V_33 -> V_37 = V_32 ;
F_22 ( & V_33 -> V_38 , L_2 , V_11 ) ;
V_34 = F_23 ( V_33 , F_14 ( V_7 -> V_1 , V_12 ) , V_26 ) ;
if ( V_34 )
goto V_20;
V_7 -> V_33 = V_33 ;
return V_1 ? 0 : V_7 -> V_1 ;
V_20:
F_24 ( & V_33 -> V_38 ) ;
V_35:
F_11 ( F_12 ( V_7 -> V_1 , V_12 , V_26 ) ) ;
return V_34 ;
}
void F_25 ( T_2 V_25 , unsigned V_26 )
{
T_2 V_27 = V_25 + V_26 ;
T_2 V_28 , V_10 ;
for ( V_28 = V_25 ; V_28 < V_27 ; V_28 = V_10 ) {
V_10 = F_14 ( F_15 ( V_28 ) + 1 , 0 ) ;
if ( V_10 > V_27 )
V_10 = V_27 ;
F_11 ( F_12 ( F_15 ( V_28 ) , F_16 ( V_28 ) , V_10 - V_28 ) ) ;
}
}
void F_26 ( unsigned int V_1 , unsigned int V_12 ,
unsigned int V_26 , const char * V_11 )
{
struct V_6 * V_7 ;
V_7 = F_12 ( V_1 , V_12 , V_26 ) ;
if ( V_7 && V_7 -> V_33 )
F_27 ( V_7 -> V_33 ) ;
F_11 ( V_7 ) ;
}
static struct V_39 * F_28 ( struct V_33 * V_40 )
{
struct V_41 * V_36 = V_40 -> V_36 ;
struct V_39 * V_38 ;
if ( V_36 && ! F_29 ( V_36 ) )
return NULL ;
V_38 = F_30 ( & V_40 -> V_38 ) ;
if ( ! V_38 )
F_31 ( V_36 ) ;
return V_38 ;
}
void F_32 ( struct V_33 * V_40 )
{
if ( V_40 ) {
struct V_41 * V_36 = V_40 -> V_36 ;
F_24 ( & V_40 -> V_38 ) ;
F_31 ( V_36 ) ;
}
}
static int F_33 ( struct V_42 * V_42 , struct V_43 * V_44 )
{
const struct V_31 * V_32 ;
struct V_33 * V_40 ;
struct V_33 * V_45 = NULL ;
int V_15 = 0 ;
F_34 ( & V_46 ) ;
V_40 = V_42 -> V_47 ;
if ( ! V_40 ) {
struct V_39 * V_38 ;
int V_48 ;
F_35 ( & V_46 ) ;
V_38 = F_36 ( V_49 , V_42 -> V_50 , & V_48 ) ;
if ( ! V_38 )
return - V_51 ;
V_45 = F_37 ( V_38 , struct V_33 , V_38 ) ;
F_34 ( & V_46 ) ;
V_40 = V_42 -> V_47 ;
if ( ! V_40 ) {
V_42 -> V_47 = V_40 = V_45 ;
F_38 ( & V_42 -> V_52 , & V_40 -> V_53 ) ;
V_45 = NULL ;
} else if ( ! F_28 ( V_40 ) )
V_15 = - V_51 ;
} else if ( ! F_28 ( V_40 ) )
V_15 = - V_51 ;
F_35 ( & V_46 ) ;
F_32 ( V_45 ) ;
if ( V_15 )
return V_15 ;
V_15 = - V_51 ;
V_32 = F_39 ( V_40 -> V_37 ) ;
if ( ! V_32 )
goto V_54;
F_40 ( V_44 , V_32 ) ;
if ( V_44 -> V_55 -> V_56 ) {
V_15 = V_44 -> V_55 -> V_56 ( V_42 , V_44 ) ;
if ( V_15 )
goto V_54;
}
return 0 ;
V_54:
F_32 ( V_40 ) ;
return V_15 ;
}
void F_41 ( struct V_42 * V_42 )
{
F_34 ( & V_46 ) ;
F_42 ( & V_42 -> V_52 ) ;
V_42 -> V_47 = NULL ;
F_35 ( & V_46 ) ;
}
static void F_43 ( struct V_33 * V_33 )
{
F_34 ( & V_46 ) ;
while ( ! F_44 ( & V_33 -> V_53 ) ) {
struct V_42 * V_42 ;
V_42 = F_37 ( V_33 -> V_53 . V_10 , struct V_42 , V_52 ) ;
F_42 ( & V_42 -> V_52 ) ;
V_42 -> V_47 = NULL ;
}
F_35 ( & V_46 ) ;
}
static struct V_39 * F_45 ( T_2 V_30 , int * V_57 , void * V_58 )
{
struct V_33 * V_40 = V_58 ;
return & V_40 -> V_38 ;
}
static int F_46 ( T_2 V_30 , void * V_58 )
{
struct V_33 * V_40 = V_58 ;
return F_28 ( V_40 ) ? 0 : - 1 ;
}
int F_23 ( struct V_33 * V_40 , T_2 V_30 , unsigned V_26 )
{
int error ;
V_40 -> V_30 = V_30 ;
V_40 -> V_26 = V_26 ;
error = F_47 ( V_49 , V_30 , V_26 , NULL ,
F_45 , F_46 , V_40 ) ;
if ( error )
return error ;
F_30 ( V_40 -> V_38 . V_59 ) ;
return 0 ;
}
static void F_48 ( T_2 V_30 , unsigned V_26 )
{
F_49 ( V_49 , V_30 , V_26 ) ;
}
void F_27 ( struct V_33 * V_40 )
{
F_48 ( V_40 -> V_30 , V_40 -> V_26 ) ;
F_24 ( & V_40 -> V_38 ) ;
}
static void F_50 ( struct V_39 * V_38 )
{
struct V_33 * V_40 = F_37 ( V_38 , struct V_33 , V_38 ) ;
struct V_39 * V_59 = V_38 -> V_59 ;
F_43 ( V_40 ) ;
F_24 ( V_59 ) ;
}
static void F_51 ( struct V_39 * V_38 )
{
struct V_33 * V_40 = F_37 ( V_38 , struct V_33 , V_38 ) ;
struct V_39 * V_59 = V_38 -> V_59 ;
F_43 ( V_40 ) ;
F_11 ( V_40 ) ;
F_24 ( V_59 ) ;
}
struct V_33 * F_21 ( void )
{
struct V_33 * V_40 = F_7 ( sizeof( struct V_33 ) , V_17 ) ;
if ( V_40 ) {
F_52 ( & V_40 -> V_53 ) ;
F_53 ( & V_40 -> V_38 , & V_60 ) ;
}
return V_40 ;
}
void F_54 ( struct V_33 * V_33 , const struct V_31 * V_32 )
{
memset ( V_33 , 0 , sizeof *V_33 ) ;
F_52 ( & V_33 -> V_53 ) ;
F_53 ( & V_33 -> V_38 , & V_61 ) ;
V_33 -> V_37 = V_32 ;
}
static struct V_39 * F_55 ( T_2 V_30 , int * V_57 , void * V_58 )
{
if ( F_56 ( L_3 , F_15 ( V_30 ) , F_16 ( V_30 ) ) > 0 )
F_56 ( L_4 , F_15 ( V_30 ) ) ;
return NULL ;
}
void T_3 F_57 ( void )
{
V_49 = F_58 ( F_55 , & V_8 ) ;
}
