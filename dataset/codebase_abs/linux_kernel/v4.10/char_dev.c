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
if ( V_16 < V_19 )
F_10 ( L_2 ,
V_11 , V_16 ) ;
if ( V_16 == 0 ) {
V_15 = - V_20 ;
goto V_21;
}
V_1 = V_16 ;
}
V_7 -> V_1 = V_1 ;
V_7 -> V_12 = V_12 ;
V_7 -> V_13 = V_13 ;
F_11 ( V_7 -> V_11 , V_11 , sizeof( V_7 -> V_11 ) ) ;
V_16 = F_1 ( V_1 ) ;
for ( V_14 = & V_9 [ V_16 ] ; * V_14 ; V_14 = & ( * V_14 ) -> V_10 )
if ( ( * V_14 ) -> V_1 > V_1 ||
( ( * V_14 ) -> V_1 == V_1 &&
( ( ( * V_14 ) -> V_12 >= V_12 ) ||
( ( * V_14 ) -> V_12 + ( * V_14 ) -> V_13 > V_12 ) ) ) )
break;
if ( * V_14 && ( * V_14 ) -> V_1 == V_1 ) {
int V_22 = ( * V_14 ) -> V_12 ;
int V_23 = ( * V_14 ) -> V_12 + ( * V_14 ) -> V_13 - 1 ;
int V_24 = V_12 ;
int V_25 = V_12 + V_13 - 1 ;
if ( V_25 >= V_22 && V_25 <= V_23 ) {
V_15 = - V_20 ;
goto V_21;
}
if ( V_24 <= V_23 && V_24 >= V_22 ) {
V_15 = - V_20 ;
goto V_21;
}
}
V_7 -> V_10 = * V_14 ;
* V_14 = V_7 ;
F_5 ( & V_8 ) ;
return V_7 ;
V_21:
F_5 ( & V_8 ) ;
F_12 ( V_7 ) ;
return F_8 ( V_15 ) ;
}
static struct V_6 *
F_13 ( unsigned V_1 , unsigned V_12 , int V_13 )
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
int F_14 ( T_2 V_26 , unsigned V_27 , const char * V_11 )
{
struct V_6 * V_7 ;
T_2 V_28 = V_26 + V_27 ;
T_2 V_29 , V_10 ;
for ( V_29 = V_26 ; V_29 < V_28 ; V_29 = V_10 ) {
V_10 = F_15 ( F_16 ( V_29 ) + 1 , 0 ) ;
if ( V_10 > V_28 )
V_10 = V_28 ;
V_7 = F_6 ( F_16 ( V_29 ) , F_17 ( V_29 ) ,
V_10 - V_29 , V_11 ) ;
if ( F_18 ( V_7 ) )
goto V_30;
}
return 0 ;
V_30:
V_28 = V_29 ;
for ( V_29 = V_26 ; V_29 < V_28 ; V_29 = V_10 ) {
V_10 = F_15 ( F_16 ( V_29 ) + 1 , 0 ) ;
F_12 ( F_13 ( F_16 ( V_29 ) , F_17 ( V_29 ) , V_10 - V_29 ) ) ;
}
return F_19 ( V_7 ) ;
}
int F_20 ( T_2 * V_31 , unsigned V_12 , unsigned V_27 ,
const char * V_11 )
{
struct V_6 * V_7 ;
V_7 = F_6 ( 0 , V_12 , V_27 , V_11 ) ;
if ( F_18 ( V_7 ) )
return F_19 ( V_7 ) ;
* V_31 = F_15 ( V_7 -> V_1 , V_7 -> V_12 ) ;
return 0 ;
}
int F_21 ( unsigned int V_1 , unsigned int V_12 ,
unsigned int V_27 , const char * V_11 ,
const struct V_32 * V_33 )
{
struct V_6 * V_7 ;
struct V_34 * V_34 ;
int V_35 = - V_18 ;
V_7 = F_6 ( V_1 , V_12 , V_27 , V_11 ) ;
if ( F_18 ( V_7 ) )
return F_19 ( V_7 ) ;
V_34 = F_22 () ;
if ( ! V_34 )
goto V_36;
V_34 -> V_37 = V_33 -> V_37 ;
V_34 -> V_38 = V_33 ;
F_23 ( & V_34 -> V_39 , L_3 , V_11 ) ;
V_35 = F_24 ( V_34 , F_15 ( V_7 -> V_1 , V_12 ) , V_27 ) ;
if ( V_35 )
goto V_21;
V_7 -> V_34 = V_34 ;
return V_1 ? 0 : V_7 -> V_1 ;
V_21:
F_25 ( & V_34 -> V_39 ) ;
V_36:
F_12 ( F_13 ( V_7 -> V_1 , V_12 , V_27 ) ) ;
return V_35 ;
}
void F_26 ( T_2 V_26 , unsigned V_27 )
{
T_2 V_28 = V_26 + V_27 ;
T_2 V_29 , V_10 ;
for ( V_29 = V_26 ; V_29 < V_28 ; V_29 = V_10 ) {
V_10 = F_15 ( F_16 ( V_29 ) + 1 , 0 ) ;
if ( V_10 > V_28 )
V_10 = V_28 ;
F_12 ( F_13 ( F_16 ( V_29 ) , F_17 ( V_29 ) , V_10 - V_29 ) ) ;
}
}
void F_27 ( unsigned int V_1 , unsigned int V_12 ,
unsigned int V_27 , const char * V_11 )
{
struct V_6 * V_7 ;
V_7 = F_13 ( V_1 , V_12 , V_27 ) ;
if ( V_7 && V_7 -> V_34 )
F_28 ( V_7 -> V_34 ) ;
F_12 ( V_7 ) ;
}
static struct V_40 * F_29 ( struct V_34 * V_41 )
{
struct V_42 * V_37 = V_41 -> V_37 ;
struct V_40 * V_39 ;
if ( V_37 && ! F_30 ( V_37 ) )
return NULL ;
V_39 = F_31 ( & V_41 -> V_39 ) ;
if ( ! V_39 )
F_32 ( V_37 ) ;
return V_39 ;
}
void F_33 ( struct V_34 * V_41 )
{
if ( V_41 ) {
struct V_42 * V_37 = V_41 -> V_37 ;
F_25 ( & V_41 -> V_39 ) ;
F_32 ( V_37 ) ;
}
}
static int F_34 ( struct V_43 * V_43 , struct V_44 * V_45 )
{
const struct V_32 * V_33 ;
struct V_34 * V_41 ;
struct V_34 * V_46 = NULL ;
int V_15 = 0 ;
F_35 ( & V_47 ) ;
V_41 = V_43 -> V_48 ;
if ( ! V_41 ) {
struct V_40 * V_39 ;
int V_49 ;
F_36 ( & V_47 ) ;
V_39 = F_37 ( V_50 , V_43 -> V_51 , & V_49 ) ;
if ( ! V_39 )
return - V_52 ;
V_46 = F_38 ( V_39 , struct V_34 , V_39 ) ;
F_35 ( & V_47 ) ;
V_41 = V_43 -> V_48 ;
if ( ! V_41 ) {
V_43 -> V_48 = V_41 = V_46 ;
F_39 ( & V_43 -> V_53 , & V_41 -> V_54 ) ;
V_46 = NULL ;
} else if ( ! F_29 ( V_41 ) )
V_15 = - V_52 ;
} else if ( ! F_29 ( V_41 ) )
V_15 = - V_52 ;
F_36 ( & V_47 ) ;
F_33 ( V_46 ) ;
if ( V_15 )
return V_15 ;
V_15 = - V_52 ;
V_33 = F_40 ( V_41 -> V_38 ) ;
if ( ! V_33 )
goto V_55;
F_41 ( V_45 , V_33 ) ;
if ( V_45 -> V_56 -> V_57 ) {
V_15 = V_45 -> V_56 -> V_57 ( V_43 , V_45 ) ;
if ( V_15 )
goto V_55;
}
return 0 ;
V_55:
F_33 ( V_41 ) ;
return V_15 ;
}
void F_42 ( struct V_43 * V_43 )
{
F_35 ( & V_47 ) ;
F_43 ( & V_43 -> V_53 ) ;
V_43 -> V_48 = NULL ;
V_43 -> V_58 = & V_43 -> V_59 ;
F_36 ( & V_47 ) ;
}
static void F_44 ( struct V_34 * V_34 )
{
F_35 ( & V_47 ) ;
while ( ! F_45 ( & V_34 -> V_54 ) ) {
struct V_43 * V_43 ;
V_43 = F_38 ( V_34 -> V_54 . V_10 , struct V_43 , V_53 ) ;
F_43 ( & V_43 -> V_53 ) ;
V_43 -> V_48 = NULL ;
}
F_36 ( & V_47 ) ;
}
static struct V_40 * F_46 ( T_2 V_31 , int * V_60 , void * V_61 )
{
struct V_34 * V_41 = V_61 ;
return & V_41 -> V_39 ;
}
static int F_47 ( T_2 V_31 , void * V_61 )
{
struct V_34 * V_41 = V_61 ;
return F_29 ( V_41 ) ? 0 : - 1 ;
}
int F_24 ( struct V_34 * V_41 , T_2 V_31 , unsigned V_27 )
{
int error ;
V_41 -> V_31 = V_31 ;
V_41 -> V_27 = V_27 ;
error = F_48 ( V_50 , V_31 , V_27 , NULL ,
F_46 , F_47 , V_41 ) ;
if ( error )
return error ;
F_31 ( V_41 -> V_39 . V_62 ) ;
return 0 ;
}
static void F_49 ( T_2 V_31 , unsigned V_27 )
{
F_50 ( V_50 , V_31 , V_27 ) ;
}
void F_28 ( struct V_34 * V_41 )
{
F_49 ( V_41 -> V_31 , V_41 -> V_27 ) ;
F_25 ( & V_41 -> V_39 ) ;
}
static void F_51 ( struct V_40 * V_39 )
{
struct V_34 * V_41 = F_38 ( V_39 , struct V_34 , V_39 ) ;
struct V_40 * V_62 = V_39 -> V_62 ;
F_44 ( V_41 ) ;
F_25 ( V_62 ) ;
}
static void F_52 ( struct V_40 * V_39 )
{
struct V_34 * V_41 = F_38 ( V_39 , struct V_34 , V_39 ) ;
struct V_40 * V_62 = V_39 -> V_62 ;
F_44 ( V_41 ) ;
F_12 ( V_41 ) ;
F_25 ( V_62 ) ;
}
struct V_34 * F_22 ( void )
{
struct V_34 * V_41 = F_7 ( sizeof( struct V_34 ) , V_17 ) ;
if ( V_41 ) {
F_53 ( & V_41 -> V_54 ) ;
F_54 ( & V_41 -> V_39 , & V_63 ) ;
}
return V_41 ;
}
void F_55 ( struct V_34 * V_34 , const struct V_32 * V_33 )
{
memset ( V_34 , 0 , sizeof *V_34 ) ;
F_53 ( & V_34 -> V_54 ) ;
F_54 ( & V_34 -> V_39 , & V_64 ) ;
V_34 -> V_38 = V_33 ;
}
static struct V_40 * F_56 ( T_2 V_31 , int * V_60 , void * V_61 )
{
if ( F_57 ( L_4 , F_16 ( V_31 ) , F_17 ( V_31 ) ) > 0 )
F_57 ( L_5 , F_16 ( V_31 ) ) ;
return NULL ;
}
void T_3 F_58 ( void )
{
V_50 = F_59 ( F_56 , & V_8 ) ;
}
