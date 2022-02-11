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
int V_22 ;
unsigned long V_30 ;
V_30 = F_22 () ;
if ( V_30 )
V_31 = V_30 ;
else {
V_31 = ( 64 * 1024 * 1024 >> V_25 ) ;
V_31 = F_23 ( V_31 , V_24 ) ;
}
V_29 = V_31 << V_25 ;
V_18 = F_24 ( V_29 ) ;
if ( ! V_18 )
F_25 ( L_1 ) ;
V_19 = V_18 + V_29 ;
V_22 = F_17 ( V_18 ,
V_29 ,
V_31 ) ;
if ( V_22 )
goto error;
V_32 = F_7 ( V_18 ) ;
F_26 ( V_18 , V_31 , V_28 ) ;
return;
error:
F_25 ( L_2\
L_3\
L_4 , V_22 ) ;
}
void *
F_27 ( struct V_33 * V_34 , T_3 V_14 ,
T_1 * V_35 , T_5 V_36 )
{
void * V_37 ;
int V_38 = F_18 ( V_14 ) ;
T_6 V_39 = F_28 ( 32 ) ;
unsigned long V_40 ;
V_36 &= ~ ( V_41 | V_42 ) ;
if ( F_29 ( V_34 , V_14 , V_35 , & V_37 ) )
return V_37 ;
V_40 = F_30 ( V_36 , V_38 ) ;
V_37 = ( void * ) V_40 ;
if ( V_34 && V_34 -> V_43 )
V_39 = F_31 ( V_34 , V_36 ) ;
if ( V_37 ) {
if ( F_20 ( V_40 , V_38 ,
F_32 ( V_39 ) ) != 0 ) {
F_33 ( V_40 , V_38 ) ;
return NULL ;
}
memset ( V_37 , 0 , V_14 ) ;
* V_35 = F_34 ( V_37 ) . V_2 ;
}
return V_37 ;
}
void
F_35 ( struct V_33 * V_34 , T_3 V_14 , void * V_44 ,
T_1 V_45 )
{
int V_38 = F_18 ( V_14 ) ;
if ( F_36 ( V_34 , V_38 , V_44 ) )
return;
F_37 ( ( unsigned long ) V_44 , V_38 ) ;
F_33 ( ( unsigned long ) V_44 , V_38 ) ;
}
T_1 F_38 ( struct V_33 * V_46 , struct V_47 * V_47 ,
unsigned long V_6 , T_3 V_14 ,
enum V_48 V_49 ,
struct V_50 * V_51 )
{
T_2 V_52 = F_39 ( V_47 ) + V_6 ;
T_1 V_45 = F_1 ( V_52 ) ;
void * V_53 ;
F_40 ( V_49 == V_54 ) ;
if ( F_41 ( V_46 , V_45 , V_14 ) &&
! F_11 ( V_52 , V_14 ) && ! V_55 )
return V_45 ;
V_53 = F_42 ( V_46 , V_32 , V_52 , V_14 , V_49 ) ;
if ( ! V_53 )
return V_56 ;
V_45 = F_7 ( V_53 ) ;
if ( ! F_41 ( V_46 , V_45 , V_14 ) )
F_25 ( L_5 ) ;
return V_45 ;
}
static void F_43 ( struct V_33 * V_34 , T_1 V_45 ,
T_3 V_14 , enum V_48 V_49 )
{
T_2 V_1 = F_4 ( V_45 ) ;
F_40 ( V_49 == V_54 ) ;
if ( F_13 ( V_45 ) ) {
F_44 ( V_34 , F_45 ( V_1 ) , V_14 , V_49 ) ;
return;
}
if ( V_49 != V_57 )
return;
F_46 ( F_45 ( V_1 ) , V_14 ) ;
}
void F_47 ( struct V_33 * V_34 , T_1 V_45 ,
T_3 V_14 , enum V_48 V_49 ,
struct V_50 * V_51 )
{
F_43 ( V_34 , V_45 , V_14 , V_49 ) ;
}
static void
F_48 ( struct V_33 * V_34 , T_1 V_45 ,
T_3 V_14 , enum V_48 V_49 ,
enum V_58 V_59 )
{
T_2 V_1 = F_4 ( V_45 ) ;
F_40 ( V_49 == V_54 ) ;
if ( F_13 ( V_45 ) ) {
F_49 ( V_34 , F_45 ( V_1 ) , V_14 , V_49 ,
V_59 ) ;
return;
}
if ( V_49 != V_57 )
return;
F_46 ( F_45 ( V_1 ) , V_14 ) ;
}
void
F_50 ( struct V_33 * V_34 , T_1 V_45 ,
T_3 V_14 , enum V_48 V_49 )
{
F_48 ( V_34 , V_45 , V_14 , V_49 , V_60 ) ;
}
void
F_51 ( struct V_33 * V_34 , T_1 V_45 ,
T_3 V_14 , enum V_48 V_49 )
{
F_48 ( V_34 , V_45 , V_14 , V_49 , V_61 ) ;
}
int
F_52 ( struct V_33 * V_34 , struct V_62 * V_63 ,
int V_64 , enum V_48 V_49 ,
struct V_50 * V_51 )
{
struct V_62 * V_65 ;
int V_9 ;
F_40 ( V_49 == V_54 ) ;
F_53 (sgl, sg, nelems, i) {
T_2 V_1 = F_54 ( V_65 ) ;
T_1 V_45 = F_1 ( V_1 ) ;
if ( V_55 ||
! F_41 ( V_34 , V_45 , V_65 -> V_7 ) ||
F_11 ( V_1 , V_65 -> V_7 ) ) {
void * V_53 = F_42 ( V_34 ,
V_32 ,
F_54 ( V_65 ) ,
V_65 -> V_7 , V_49 ) ;
if ( ! V_53 ) {
F_55 ( V_34 , V_63 , V_9 , V_49 ,
V_51 ) ;
V_63 [ 0 ] . V_66 = 0 ;
return V_56 ;
}
V_65 -> V_67 = F_7 ( V_53 ) ;
} else
V_65 -> V_67 = V_45 ;
V_65 -> V_66 = V_65 -> V_7 ;
}
return V_64 ;
}
int
F_56 ( struct V_33 * V_34 , struct V_62 * V_63 , int V_64 ,
enum V_48 V_49 )
{
return F_52 ( V_34 , V_63 , V_64 , V_49 , NULL ) ;
}
void
F_55 ( struct V_33 * V_34 , struct V_62 * V_63 ,
int V_64 , enum V_48 V_49 ,
struct V_50 * V_51 )
{
struct V_62 * V_65 ;
int V_9 ;
F_40 ( V_49 == V_54 ) ;
F_53 (sgl, sg, nelems, i)
F_43 ( V_34 , V_65 -> V_67 , V_65 -> V_66 , V_49 ) ;
}
void
F_57 ( struct V_33 * V_34 , struct V_62 * V_63 , int V_64 ,
enum V_48 V_49 )
{
return F_55 ( V_34 , V_63 , V_64 , V_49 , NULL ) ;
}
static void
F_58 ( struct V_33 * V_34 , struct V_62 * V_63 ,
int V_64 , enum V_48 V_49 ,
enum V_58 V_59 )
{
struct V_62 * V_65 ;
int V_9 ;
F_53 (sgl, sg, nelems, i)
F_48 ( V_34 , V_65 -> V_67 ,
V_65 -> V_66 , V_49 , V_59 ) ;
}
void
F_59 ( struct V_33 * V_34 , struct V_62 * V_65 ,
int V_64 , enum V_48 V_49 )
{
F_58 ( V_34 , V_65 , V_64 , V_49 , V_60 ) ;
}
void
F_60 ( struct V_33 * V_34 , struct V_62 * V_65 ,
int V_64 , enum V_48 V_49 )
{
F_58 ( V_34 , V_65 , V_64 , V_49 , V_61 ) ;
}
int
F_61 ( struct V_33 * V_34 , T_1 V_16 )
{
return ! V_16 ;
}
int
F_62 ( struct V_33 * V_34 , T_6 V_68 )
{
return F_7 ( V_19 - 1 ) <= V_68 ;
}
