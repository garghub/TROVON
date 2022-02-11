void F_1 ( int V_1 )
{
struct V_2 * V_3 = F_2 ( V_4 . V_3 ) ;
if ( V_3 == & V_5 )
return;
if ( F_2 ( V_4 . V_6 ) == V_7 )
F_3 () ;
F_4 ( NULL , & V_5 , NULL ) ;
}
void F_4 ( struct V_2 * V_8 , struct V_2 * V_9 ,
struct V_10 * V_11 )
{
unsigned long V_12 ;
F_5 ( V_12 ) ;
F_6 ( V_8 , V_9 , V_11 ) ;
F_7 ( V_12 ) ;
}
void F_6 ( struct V_2 * V_8 , struct V_2 * V_9 ,
struct V_10 * V_11 )
{
unsigned V_1 = F_8 () ;
struct V_2 * V_13 = F_2 ( V_4 . V_3 ) ;
F_9 ( V_4 . V_6 , V_7 ) ;
if ( V_13 == V_9 ) {
if ( F_10 ( ! F_11 ( V_1 , F_12 ( V_9 ) ) ) )
F_13 ( V_1 , F_12 ( V_9 ) ) ;
return;
}
if ( F_14 ( V_14 ) ) {
unsigned int V_15 = F_15 ( F_16 () ) ;
T_1 * V_16 = V_9 -> V_16 + V_15 ;
if ( F_17 ( F_18 ( * V_16 ) ) )
F_19 ( V_16 , V_5 . V_16 [ V_15 ] ) ;
}
F_9 ( V_4 . V_3 , V_9 ) ;
F_10 ( F_11 ( V_1 , F_12 ( V_9 ) ) ) ;
F_13 ( V_1 , F_12 ( V_9 ) ) ;
F_20 ( V_9 -> V_16 ) ;
F_21 ( V_17 , V_18 ) ;
F_10 ( ! F_11 ( V_1 , F_12 ( V_13 ) ) &&
V_13 != & V_5 ) ;
F_22 ( V_1 , F_12 ( V_13 ) ) ;
F_23 ( V_9 ) ;
F_24 ( V_13 , V_9 ) ;
}
static void F_25 ( const struct V_19 * V_20 ,
bool V_21 , enum V_22 V_23 )
{
F_26 ( ! F_27 () ) ;
if ( F_2 ( V_4 . V_6 ) != V_7 ) {
F_1 ( F_8 () ) ;
return;
}
if ( V_20 -> V_24 == V_18 ) {
F_28 () ;
if ( V_21 )
F_29 ( V_25 ) ;
F_30 ( V_23 , V_18 ) ;
} else {
unsigned long V_26 ;
unsigned long V_27 = ( V_20 -> V_24 - V_20 -> V_28 ) >> V_29 ;
V_26 = V_20 -> V_28 ;
while ( V_26 < V_20 -> V_24 ) {
F_31 ( V_26 ) ;
V_26 += V_30 ;
}
if ( V_21 )
F_32 ( V_31 , V_27 ) ;
F_30 ( V_23 , V_27 ) ;
}
}
static void F_33 ( void * V_32 , enum V_22 V_23 )
{
const struct V_19 * V_20 = V_32 ;
F_25 ( V_20 , true , V_23 ) ;
}
static void F_34 ( void * V_32 )
{
const struct V_19 * V_20 = V_32 ;
F_35 ( V_33 ) ;
if ( V_20 -> V_34 && V_20 -> V_34 != F_2 ( V_4 . V_3 ) )
return;
F_29 ( V_35 ) ;
F_25 ( V_20 , false , V_36 ) ;
}
void F_36 ( const struct V_37 * V_37 ,
const struct V_19 * V_32 )
{
F_29 ( V_38 ) ;
if ( V_32 -> V_24 == V_18 )
F_30 ( V_39 , V_18 ) ;
else
F_30 ( V_39 ,
( V_32 -> V_24 - V_32 -> V_28 ) >> V_29 ) ;
if ( F_37 () ) {
unsigned int V_1 ;
V_1 = F_8 () ;
V_37 = F_38 ( V_37 , V_32 ) ;
if ( V_37 )
F_39 ( V_37 , F_34 ,
( void * ) V_32 , 1 ) ;
return;
}
F_39 ( V_37 , F_34 ,
( void * ) V_32 , 1 ) ;
}
void F_40 ( struct V_2 * V_34 , unsigned long V_28 ,
unsigned long V_24 , unsigned long V_40 )
{
int V_1 ;
struct V_19 V_32 = {
. V_34 = V_34 ,
} ;
V_1 = F_41 () ;
F_42 () ;
if ( ( V_24 != V_18 ) &&
! ( V_40 & V_41 ) &&
( ( V_24 - V_28 ) >> V_29 ) <= V_42 ) {
V_32 . V_28 = V_28 ;
V_32 . V_24 = V_24 ;
} else {
V_32 . V_28 = 0UL ;
V_32 . V_24 = V_18 ;
}
if ( V_34 == F_2 ( V_4 . V_3 ) ) {
F_26 ( F_27 () ) ;
F_43 () ;
F_33 ( & V_32 , V_43 ) ;
F_44 () ;
}
if ( F_45 ( F_12 ( V_34 ) , V_1 ) < V_44 )
F_46 ( F_12 ( V_34 ) , & V_32 ) ;
F_47 () ;
}
static void F_48 ( void * V_32 )
{
F_29 ( V_35 ) ;
F_49 () ;
if ( F_2 ( V_4 . V_6 ) == V_45 )
F_1 ( F_8 () ) ;
}
void F_50 ( void )
{
F_29 ( V_38 ) ;
F_51 ( F_48 , NULL , 1 ) ;
}
static void F_52 ( void * V_32 )
{
struct V_19 * V_20 = V_32 ;
unsigned long V_26 ;
for ( V_26 = V_20 -> V_28 ; V_26 < V_20 -> V_24 ; V_26 += V_30 )
F_31 ( V_26 ) ;
}
void F_53 ( unsigned long V_28 , unsigned long V_24 )
{
if ( V_24 == V_18 ||
( V_24 - V_28 ) > V_42 << V_29 ) {
F_51 ( F_48 , NULL , 1 ) ;
} else {
struct V_19 V_32 ;
V_32 . V_28 = V_28 ;
V_32 . V_24 = V_24 ;
F_51 ( F_52 , & V_32 , 1 ) ;
}
}
void F_54 ( struct V_46 * V_47 )
{
struct V_19 V_32 = {
. V_34 = NULL ,
. V_28 = 0UL ,
. V_24 = V_18 ,
} ;
int V_1 = F_41 () ;
if ( F_11 ( V_1 , & V_47 -> V_37 ) ) {
F_26 ( F_27 () ) ;
F_43 () ;
F_33 ( & V_32 , V_48 ) ;
F_44 () ;
}
if ( F_45 ( & V_47 -> V_37 , V_1 ) < V_44 )
F_46 ( & V_47 -> V_37 , & V_32 ) ;
F_55 ( & V_47 -> V_37 ) ;
F_47 () ;
}
static T_2 F_56 ( struct V_49 * V_49 , char T_3 * V_50 ,
T_4 V_51 , T_5 * V_52 )
{
char V_53 [ 32 ] ;
unsigned int V_54 ;
V_54 = sprintf ( V_53 , L_1 , V_42 ) ;
return F_57 ( V_50 , V_51 , V_52 , V_53 , V_54 ) ;
}
static T_2 F_58 ( struct V_49 * V_49 ,
const char T_3 * V_50 , T_4 V_51 , T_5 * V_52 )
{
char V_53 [ 32 ] ;
T_2 V_54 ;
int V_55 ;
V_54 = F_59 ( V_51 , sizeof( V_53 ) - 1 ) ;
if ( F_60 ( V_53 , V_50 , V_54 ) )
return - V_56 ;
V_53 [ V_54 ] = '\0' ;
if ( F_61 ( V_53 , 0 , & V_55 ) )
return - V_57 ;
if ( V_55 < 0 )
return - V_57 ;
V_42 = V_55 ;
return V_51 ;
}
static int T_6 F_62 ( void )
{
F_63 ( L_2 , V_58 | V_59 ,
V_60 , NULL , & V_61 ) ;
return 0 ;
}
