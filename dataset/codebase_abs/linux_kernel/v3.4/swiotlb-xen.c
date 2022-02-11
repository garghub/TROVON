static T_1 F_1 ( T_2 V_1 )
{
return F_2 ( F_3 ( V_1 ) ) . V_2 ;
}
static T_2 F_4 ( T_1 V_3 )
{
return F_5 ( F_6 ( V_3 ) ) . V_1 ;
}
static T_1 F_7 ( void * V_4 )
{
return F_1 ( F_8 ( V_4 ) ) ;
}
static int F_9 ( unsigned long V_5 ,
unsigned int V_6 ,
T_3 V_7 )
{
unsigned long V_8 ;
int V_9 ;
int V_10 ;
V_8 = F_10 ( V_5 ) ;
V_10 = ( V_6 + V_7 + V_11 - 1 ) >> V_12 ;
for ( V_9 = 1 ; V_9 < V_10 ; V_9 ++ ) {
if ( F_10 ( ++ V_5 ) != ++ V_8 )
return 0 ;
}
return 1 ;
}
static int F_11 ( T_2 V_13 , T_3 V_14 )
{
unsigned long V_5 = F_12 ( V_13 ) ;
unsigned int V_6 = V_13 & ~ V_15 ;
if ( V_6 + V_14 <= V_11 )
return 0 ;
if ( F_9 ( V_5 , V_6 , V_14 ) )
return 0 ;
return 1 ;
}
static int F_13 ( T_1 V_16 )
{
unsigned long V_17 = F_12 ( V_16 ) ;
unsigned long V_5 = F_14 ( V_17 ) ;
T_2 V_1 ;
if ( F_15 ( V_5 ) ) {
V_1 = F_16 ( V_5 ) ;
return V_1 >= F_8 ( V_18 ) &&
V_1 < F_8 ( V_19 ) ;
}
return 0 ;
}
static int
F_17 ( void * V_20 , T_3 V_14 , unsigned long V_21 )
{
int V_9 , V_22 ;
int V_23 ;
V_23 = F_18 ( V_24 << V_25 ) + V_12 ;
V_9 = 0 ;
do {
int V_26 = F_19 ( V_21 - V_9 , ( unsigned long ) V_24 ) ;
do {
V_22 = F_20 (
( unsigned long ) V_20 + ( V_9 << V_25 ) ,
F_18 ( V_26 << V_25 ) ,
V_23 ) ;
} while ( V_22 && V_23 ++ < V_27 );
if ( V_22 )
return V_22 ;
V_9 += V_26 ;
} while ( V_9 < V_21 );
return 0 ;
}
void T_4 F_21 ( int V_28 )
{
unsigned long V_29 ;
int V_22 = - V_30 ;
unsigned long V_31 ;
char * V_32 = NULL ;
unsigned int V_33 = 3 ;
V_31 = F_22 () ;
if ( V_31 )
V_34 = V_31 ;
else {
V_34 = ( 64 * 1024 * 1024 >> V_25 ) ;
V_34 = F_23 ( V_34 , V_24 ) ;
}
V_35:
V_29 = V_34 << V_25 ;
V_18 = F_24 ( F_25 ( V_29 ) ) ;
if ( ! V_18 ) {
V_32 = L_1 ;
goto error;
}
V_19 = V_18 + V_29 ;
V_22 = F_17 ( V_18 ,
V_29 ,
V_34 ) ;
if ( V_22 ) {
F_26 ( F_27 ( V_18 ) , F_25 ( V_29 ) ) ;
V_32 = L_2\
L_3\
L_4\
L_5 ;
goto error;
}
V_36 = F_7 ( V_18 ) ;
F_28 ( V_18 , V_34 , V_28 ) ;
return;
error:
if ( V_33 -- ) {
V_34 = F_29 ( 1024UL ,
( V_34 >> 1 ) ) ;
F_30 ( V_37 L_6 ,
( V_34 << V_25 ) >> 20 ) ;
goto V_35;
}
F_31 ( L_7 , V_32 , V_22 ) ;
F_32 ( L_7 , V_32 , V_22 ) ;
}
void *
F_33 ( struct V_38 * V_39 , T_3 V_14 ,
T_1 * V_40 , T_5 V_41 ,
struct V_42 * V_43 )
{
void * V_44 ;
int V_45 = F_18 ( V_14 ) ;
T_6 V_46 = F_34 ( 32 ) ;
unsigned long V_47 ;
T_2 V_48 ;
T_1 V_49 ;
V_41 &= ~ ( V_50 | V_51 ) ;
if ( F_35 ( V_39 , V_14 , V_40 , & V_44 ) )
return V_44 ;
V_47 = F_36 ( V_41 , V_45 ) ;
V_44 = ( void * ) V_47 ;
if ( ! V_44 )
return V_44 ;
if ( V_39 && V_39 -> V_52 )
V_46 = V_39 -> V_52 ;
V_48 = F_8 ( V_44 ) ;
V_49 = F_1 ( V_48 ) ;
if ( ( ( V_49 + V_14 - 1 <= V_46 ) ) &&
! F_11 ( V_48 , V_14 ) )
* V_40 = V_49 ;
else {
if ( F_20 ( V_47 , V_45 ,
F_37 ( V_46 ) ) != 0 ) {
F_38 ( V_47 , V_45 ) ;
return NULL ;
}
* V_40 = F_39 ( V_44 ) . V_2 ;
}
memset ( V_44 , 0 , V_14 ) ;
return V_44 ;
}
void
F_40 ( struct V_38 * V_39 , T_3 V_14 , void * V_53 ,
T_1 V_49 , struct V_42 * V_43 )
{
int V_45 = F_18 ( V_14 ) ;
T_2 V_48 ;
T_6 V_46 = F_34 ( 32 ) ;
if ( F_41 ( V_39 , V_45 , V_53 ) )
return;
if ( V_39 && V_39 -> V_52 )
V_46 = V_39 -> V_52 ;
V_48 = F_8 ( V_53 ) ;
if ( ( ( V_49 + V_14 - 1 > V_46 ) ) ||
F_11 ( V_48 , V_14 ) )
F_42 ( ( unsigned long ) V_53 , V_45 ) ;
F_38 ( ( unsigned long ) V_53 , V_45 ) ;
}
T_1 F_43 ( struct V_38 * V_54 , struct V_55 * V_55 ,
unsigned long V_6 , T_3 V_14 ,
enum V_56 V_57 ,
struct V_42 * V_43 )
{
T_2 V_48 = F_44 ( V_55 ) + V_6 ;
T_1 V_49 = F_1 ( V_48 ) ;
void * V_58 ;
F_45 ( V_57 == V_59 ) ;
if ( F_46 ( V_54 , V_49 , V_14 ) &&
! F_11 ( V_48 , V_14 ) && ! V_60 )
return V_49 ;
V_58 = F_47 ( V_54 , V_36 , V_48 , V_14 , V_57 ) ;
if ( ! V_58 )
return V_61 ;
V_49 = F_7 ( V_58 ) ;
if ( ! F_46 ( V_54 , V_49 , V_14 ) ) {
F_48 ( V_54 , V_58 , V_14 , V_57 ) ;
V_49 = 0 ;
}
return V_49 ;
}
static void F_49 ( struct V_38 * V_39 , T_1 V_49 ,
T_3 V_14 , enum V_56 V_57 )
{
T_2 V_1 = F_4 ( V_49 ) ;
F_45 ( V_57 == V_59 ) ;
if ( F_13 ( V_49 ) ) {
F_48 ( V_39 , F_50 ( V_1 ) , V_14 , V_57 ) ;
return;
}
if ( V_57 != V_62 )
return;
F_51 ( F_50 ( V_1 ) , V_14 ) ;
}
void F_52 ( struct V_38 * V_39 , T_1 V_49 ,
T_3 V_14 , enum V_56 V_57 ,
struct V_42 * V_43 )
{
F_49 ( V_39 , V_49 , V_14 , V_57 ) ;
}
static void
F_53 ( struct V_38 * V_39 , T_1 V_49 ,
T_3 V_14 , enum V_56 V_57 ,
enum V_63 V_64 )
{
T_2 V_1 = F_4 ( V_49 ) ;
F_45 ( V_57 == V_59 ) ;
if ( F_13 ( V_49 ) ) {
F_54 ( V_39 , F_50 ( V_1 ) , V_14 , V_57 ,
V_64 ) ;
return;
}
if ( V_57 != V_62 )
return;
F_51 ( F_50 ( V_1 ) , V_14 ) ;
}
void
F_55 ( struct V_38 * V_39 , T_1 V_49 ,
T_3 V_14 , enum V_56 V_57 )
{
F_53 ( V_39 , V_49 , V_14 , V_57 , V_65 ) ;
}
void
F_56 ( struct V_38 * V_39 , T_1 V_49 ,
T_3 V_14 , enum V_56 V_57 )
{
F_53 ( V_39 , V_49 , V_14 , V_57 , V_66 ) ;
}
int
F_57 ( struct V_38 * V_39 , struct V_67 * V_68 ,
int V_69 , enum V_56 V_57 ,
struct V_42 * V_43 )
{
struct V_67 * V_70 ;
int V_9 ;
F_45 ( V_57 == V_59 ) ;
F_58 (sgl, sg, nelems, i) {
T_2 V_1 = F_59 ( V_70 ) ;
T_1 V_49 = F_1 ( V_1 ) ;
if ( V_60 ||
! F_46 ( V_39 , V_49 , V_70 -> V_7 ) ||
F_11 ( V_1 , V_70 -> V_7 ) ) {
void * V_58 = F_47 ( V_39 ,
V_36 ,
F_59 ( V_70 ) ,
V_70 -> V_7 , V_57 ) ;
if ( ! V_58 ) {
F_60 ( V_39 , V_68 , V_9 , V_57 ,
V_43 ) ;
V_68 [ 0 ] . V_71 = 0 ;
return V_61 ;
}
V_70 -> V_72 = F_7 ( V_58 ) ;
} else
V_70 -> V_72 = V_49 ;
V_70 -> V_71 = V_70 -> V_7 ;
}
return V_69 ;
}
int
F_61 ( struct V_38 * V_39 , struct V_67 * V_68 , int V_69 ,
enum V_56 V_57 )
{
return F_57 ( V_39 , V_68 , V_69 , V_57 , NULL ) ;
}
void
F_60 ( struct V_38 * V_39 , struct V_67 * V_68 ,
int V_69 , enum V_56 V_57 ,
struct V_42 * V_43 )
{
struct V_67 * V_70 ;
int V_9 ;
F_45 ( V_57 == V_59 ) ;
F_58 (sgl, sg, nelems, i)
F_49 ( V_39 , V_70 -> V_72 , V_70 -> V_71 , V_57 ) ;
}
void
F_62 ( struct V_38 * V_39 , struct V_67 * V_68 , int V_69 ,
enum V_56 V_57 )
{
return F_60 ( V_39 , V_68 , V_69 , V_57 , NULL ) ;
}
static void
F_63 ( struct V_38 * V_39 , struct V_67 * V_68 ,
int V_69 , enum V_56 V_57 ,
enum V_63 V_64 )
{
struct V_67 * V_70 ;
int V_9 ;
F_58 (sgl, sg, nelems, i)
F_53 ( V_39 , V_70 -> V_72 ,
V_70 -> V_71 , V_57 , V_64 ) ;
}
void
F_64 ( struct V_38 * V_39 , struct V_67 * V_70 ,
int V_69 , enum V_56 V_57 )
{
F_63 ( V_39 , V_70 , V_69 , V_57 , V_65 ) ;
}
void
F_65 ( struct V_38 * V_39 , struct V_67 * V_70 ,
int V_69 , enum V_56 V_57 )
{
F_63 ( V_39 , V_70 , V_69 , V_57 , V_66 ) ;
}
int
F_66 ( struct V_38 * V_39 , T_1 V_16 )
{
return ! V_16 ;
}
int
F_67 ( struct V_38 * V_39 , T_6 V_73 )
{
return F_7 ( V_19 - 1 ) <= V_73 ;
}
