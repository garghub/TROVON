static void F_1 ( struct V_1 * V_2 , T_1 V_3 ,
T_2 * V_4 , bool * V_5 )
{
T_2 V_6 ;
if ( ! F_2 ( V_7 ) ) {
* V_4 = 0 ;
* V_5 = true ;
return;
}
for ( V_6 = 0 ; V_6 < V_8 ; V_6 ++ ) {
if ( F_3 ( V_9 . V_10 [ V_6 ] . V_11 ) !=
V_2 -> V_12 . V_11 )
continue;
* V_4 = V_6 ;
* V_5 = ( F_3 ( V_9 . V_10 [ V_6 ] . V_13 ) <
V_3 ) ;
return;
}
* V_4 = F_4 ( V_9 . V_14 , 1 ) - 1 ;
if ( * V_4 >= V_8 ) {
* V_4 = 0 ;
F_5 ( V_9 . V_14 , 1 ) ;
}
* V_5 = true ;
}
void F_6 ( int V_15 )
{
struct V_1 * V_16 = F_3 ( V_9 . V_16 ) ;
if ( V_16 == & V_17 )
return;
F_7 ( ! F_3 ( V_9 . V_18 ) ) ;
F_8 ( NULL , & V_17 , NULL ) ;
}
void F_8 ( struct V_1 * V_19 , struct V_1 * V_2 ,
struct V_20 * V_21 )
{
unsigned long V_22 ;
F_9 ( V_22 ) ;
F_10 ( V_19 , V_2 , V_21 ) ;
F_11 ( V_22 ) ;
}
void F_10 ( struct V_1 * V_19 , struct V_1 * V_2 ,
struct V_20 * V_21 )
{
struct V_1 * V_23 = F_3 ( V_9 . V_16 ) ;
T_2 V_24 = F_3 ( V_9 . V_25 ) ;
unsigned V_15 = F_12 () ;
T_1 V_3 ;
if ( F_13 ( V_26 ) )
F_14 ( ! F_15 () ) ;
#ifdef F_16
if ( F_14 ( F_17 () != F_18 ( V_23 , V_24 ) ) ) {
F_19 () ;
}
#endif
F_5 ( V_9 . V_18 , false ) ;
if ( V_23 == V_2 ) {
F_20 ( F_3 ( V_9 . V_10 [ V_24 ] . V_11 ) !=
V_2 -> V_12 . V_11 ) ;
if ( F_14 ( V_23 != & V_17 &&
! F_21 ( V_15 , F_22 ( V_2 ) ) ) )
F_23 ( V_15 , F_22 ( V_2 ) ) ;
return;
} else {
T_2 V_4 ;
bool V_5 ;
if ( F_13 ( V_27 ) ) {
unsigned int V_28 = F_24 ( V_29 ) ;
T_3 * V_30 = V_2 -> V_30 + V_28 ;
if ( F_25 ( F_26 ( * V_30 ) ) )
F_27 ( V_30 , V_17 . V_30 [ V_28 ] ) ;
}
F_28 ( ! F_21 ( V_15 , F_22 ( V_23 ) ) &&
V_23 != & V_17 ) ;
F_29 ( V_15 , F_22 ( V_23 ) ) ;
F_23 ( V_15 , F_22 ( V_2 ) ) ;
V_3 = F_30 ( & V_2 -> V_12 . V_13 ) ;
F_1 ( V_2 , V_3 , & V_4 , & V_5 ) ;
if ( V_5 ) {
F_5 ( V_9 . V_10 [ V_4 ] . V_11 , V_2 -> V_12 . V_11 ) ;
F_5 ( V_9 . V_10 [ V_4 ] . V_13 , V_3 ) ;
F_31 ( F_18 ( V_2 , V_4 ) ) ;
F_32 ( V_31 , V_32 ) ;
} else {
F_31 ( F_33 ( V_2 , V_4 ) ) ;
F_32 ( V_31 , 0 ) ;
}
F_5 ( V_9 . V_16 , V_2 ) ;
F_5 ( V_9 . V_25 , V_4 ) ;
}
F_34 ( V_2 ) ;
F_35 ( V_23 , V_2 ) ;
}
void F_36 ( struct V_1 * V_33 , struct V_20 * V_21 )
{
if ( F_3 ( V_9 . V_16 ) == & V_17 )
return;
if ( F_37 () ) {
F_5 ( V_9 . V_18 , true ) ;
} else {
F_8 ( NULL , & V_17 , NULL ) ;
}
}
void F_38 ( void )
{
int V_34 ;
struct V_1 * V_33 = F_3 ( V_9 . V_16 ) ;
T_1 V_13 = F_30 ( & V_17 . V_12 . V_13 ) ;
unsigned long V_35 = F_17 () ;
F_7 ( ( V_35 & V_36 ) != F_39 ( V_33 -> V_30 ) ) ;
F_7 ( F_40 ( V_7 ) &&
! ( F_41 () & V_37 ) ) ;
F_31 ( F_18 ( V_33 , 0 ) ) ;
F_5 ( V_9 . V_25 , 0 ) ;
F_5 ( V_9 . V_14 , 1 ) ;
F_5 ( V_9 . V_10 [ 0 ] . V_11 , V_33 -> V_12 . V_11 ) ;
F_5 ( V_9 . V_10 [ 0 ] . V_13 , V_13 ) ;
for ( V_34 = 1 ; V_34 < V_8 ; V_34 ++ )
F_5 ( V_9 . V_10 [ V_34 ] . V_11 , 0 ) ;
}
static void F_42 ( const struct V_38 * V_39 ,
bool V_40 , enum V_41 V_42 )
{
struct V_1 * V_16 = F_3 ( V_9 . V_16 ) ;
T_4 V_25 = F_3 ( V_9 . V_25 ) ;
T_1 V_43 = F_30 ( & V_16 -> V_12 . V_13 ) ;
T_1 V_44 = F_3 ( V_9 . V_10 [ V_25 ] . V_13 ) ;
F_20 ( ! F_15 () ) ;
if ( F_25 ( V_16 == & V_17 ) )
return;
F_20 ( F_3 ( V_9 . V_10 [ V_25 ] . V_11 ) !=
V_16 -> V_12 . V_11 ) ;
if ( F_3 ( V_9 . V_18 ) ) {
F_10 ( NULL , & V_17 , NULL ) ;
return;
}
if ( F_25 ( V_44 == V_43 ) ) {
F_43 ( V_42 , 0 ) ;
return;
}
F_14 ( V_44 > V_43 ) ;
F_14 ( V_39 -> V_45 > V_43 ) ;
if ( V_39 -> V_46 != V_32 &&
V_39 -> V_45 == V_44 + 1 &&
V_39 -> V_45 == V_43 ) {
unsigned long V_47 ;
unsigned long V_48 = ( V_39 -> V_46 - V_39 -> V_49 ) >> V_50 ;
V_47 = V_39 -> V_49 ;
while ( V_47 < V_39 -> V_46 ) {
F_44 ( V_47 ) ;
V_47 += V_51 ;
}
if ( V_40 )
F_45 ( V_52 , V_48 ) ;
F_43 ( V_42 , V_48 ) ;
} else {
F_46 () ;
if ( V_40 )
F_47 ( V_53 ) ;
F_43 ( V_42 , V_32 ) ;
}
F_5 ( V_9 . V_10 [ V_25 ] . V_13 , V_43 ) ;
}
static void F_48 ( void * V_54 , enum V_41 V_42 )
{
const struct V_38 * V_39 = V_54 ;
F_42 ( V_39 , true , V_42 ) ;
}
static void F_49 ( void * V_54 )
{
const struct V_38 * V_39 = V_54 ;
F_50 ( V_55 ) ;
if ( V_39 -> V_33 && V_39 -> V_33 != F_3 ( V_9 . V_16 ) )
return;
F_47 ( V_56 ) ;
F_42 ( V_39 , false , V_57 ) ;
}
void F_51 ( const struct V_58 * V_58 ,
const struct V_38 * V_54 )
{
F_47 ( V_59 ) ;
if ( V_54 -> V_46 == V_32 )
F_43 ( V_60 , V_32 ) ;
else
F_43 ( V_60 ,
( V_54 -> V_46 - V_54 -> V_49 ) >> V_50 ) ;
if ( F_52 () ) {
unsigned int V_15 ;
V_15 = F_12 () ;
V_58 = F_53 ( V_58 , V_54 ) ;
if ( V_58 )
F_54 ( V_58 , F_49 ,
( void * ) V_54 , 1 ) ;
return;
}
F_54 ( V_58 , F_49 ,
( void * ) V_54 , 1 ) ;
}
void F_55 ( struct V_1 * V_33 , unsigned long V_49 ,
unsigned long V_46 , unsigned long V_61 )
{
int V_15 ;
struct V_38 V_54 = {
. V_33 = V_33 ,
} ;
V_15 = F_56 () ;
V_54 . V_45 = F_57 ( V_33 ) ;
if ( ( V_46 != V_32 ) &&
! ( V_61 & V_62 ) &&
( ( V_46 - V_49 ) >> V_50 ) <= V_63 ) {
V_54 . V_49 = V_49 ;
V_54 . V_46 = V_46 ;
} else {
V_54 . V_49 = 0UL ;
V_54 . V_46 = V_32 ;
}
if ( V_33 == F_3 ( V_9 . V_16 ) ) {
F_20 ( F_15 () ) ;
F_58 () ;
F_48 ( & V_54 , V_64 ) ;
F_59 () ;
}
if ( F_60 ( F_22 ( V_33 ) , V_15 ) < V_65 )
F_61 ( F_22 ( V_33 ) , & V_54 ) ;
F_62 () ;
}
static void F_63 ( void * V_54 )
{
F_47 ( V_56 ) ;
F_19 () ;
}
void F_64 ( void )
{
F_47 ( V_59 ) ;
F_65 ( F_63 , NULL , 1 ) ;
}
static void F_66 ( void * V_54 )
{
struct V_38 * V_39 = V_54 ;
unsigned long V_47 ;
for ( V_47 = V_39 -> V_49 ; V_47 < V_39 -> V_46 ; V_47 += V_51 )
F_44 ( V_47 ) ;
}
void F_67 ( unsigned long V_49 , unsigned long V_46 )
{
if ( V_46 == V_32 ||
( V_46 - V_49 ) > V_63 << V_50 ) {
F_65 ( F_63 , NULL , 1 ) ;
} else {
struct V_38 V_54 ;
V_54 . V_49 = V_49 ;
V_54 . V_46 = V_46 ;
F_65 ( F_66 , & V_54 , 1 ) ;
}
}
void F_68 ( struct V_66 * V_67 )
{
struct V_38 V_54 = {
. V_33 = NULL ,
. V_49 = 0UL ,
. V_46 = V_32 ,
} ;
int V_15 = F_56 () ;
if ( F_21 ( V_15 , & V_67 -> V_58 ) ) {
F_20 ( F_15 () ) ;
F_58 () ;
F_48 ( & V_54 , V_68 ) ;
F_59 () ;
}
if ( F_60 ( & V_67 -> V_58 , V_15 ) < V_65 )
F_61 ( & V_67 -> V_58 , & V_54 ) ;
F_69 ( & V_67 -> V_58 ) ;
F_62 () ;
}
static T_5 F_70 ( struct V_69 * V_69 , char T_6 * V_70 ,
T_7 V_71 , T_8 * V_72 )
{
char V_73 [ 32 ] ;
unsigned int V_74 ;
V_74 = sprintf ( V_73 , L_1 , V_63 ) ;
return F_71 ( V_70 , V_71 , V_72 , V_73 , V_74 ) ;
}
static T_5 F_72 ( struct V_69 * V_69 ,
const char T_6 * V_70 , T_7 V_71 , T_8 * V_72 )
{
char V_73 [ 32 ] ;
T_5 V_74 ;
int V_75 ;
V_74 = F_73 ( V_71 , sizeof( V_73 ) - 1 ) ;
if ( F_74 ( V_73 , V_70 , V_74 ) )
return - V_76 ;
V_73 [ V_74 ] = '\0' ;
if ( F_75 ( V_73 , 0 , & V_75 ) )
return - V_77 ;
if ( V_75 < 0 )
return - V_77 ;
V_63 = V_75 ;
return V_71 ;
}
static int T_9 F_76 ( void )
{
F_77 ( L_2 , V_78 | V_79 ,
V_80 , NULL , & V_81 ) ;
return 0 ;
}
