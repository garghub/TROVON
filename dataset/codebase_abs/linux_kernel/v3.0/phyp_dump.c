static unsigned long F_1 ( struct V_1 * V_2 )
{
unsigned long V_3 = 0 ;
V_2 -> V_4 = V_5 ;
V_2 -> V_6 = V_7 ;
V_2 -> V_8 = 0 ;
V_2 -> V_9 =
( V_10 ) F_2 ( struct V_1 , V_11 ) ;
V_2 -> V_12 = 0 ;
V_2 -> V_13 = 0 ;
V_2 -> V_14 = 0 ;
V_2 -> V_15 = 0 ;
V_2 -> V_16 = 0 ;
V_2 -> V_11 . V_17 = V_18 ;
V_2 -> V_11 . V_19 = V_20 ;
V_2 -> V_11 . V_21 = 0 ;
V_2 -> V_11 . V_22 = V_23 -> V_24 ;
V_2 -> V_11 . V_25 = V_3 ;
V_3 += V_23 -> V_24 ;
V_2 -> V_26 . V_17 = V_18 ;
V_2 -> V_26 . V_19 = V_27 ;
V_2 -> V_26 . V_21 = 0 ;
V_2 -> V_26 . V_22 = V_23 -> V_28 ;
V_2 -> V_26 . V_25 = V_3 ;
V_3 += V_23 -> V_28 ;
V_2 -> V_29 . V_17 = V_18 ;
V_2 -> V_29 . V_19 = V_30 ;
V_2 -> V_29 . V_21 = V_31 ;
V_2 -> V_29 . V_22 = V_32 ;
V_2 -> V_29 . V_25 = V_3 ;
V_3 += V_2 -> V_29 . V_22 ;
return V_3 ;
}
static void F_3 ( const struct V_1 * V_2 )
{
#ifdef F_4
if ( V_2 == NULL )
return;
F_5 ( V_33 L_1 ) ;
F_5 ( V_33 L_2 , V_2 -> V_4 ) ;
F_5 ( V_33 L_3 , V_2 -> V_6 ) ;
F_5 ( V_33 L_4 , V_2 -> V_8 ) ;
F_5 ( V_33 L_5 ,
V_2 -> V_9 ) ;
F_5 ( V_33 L_6 ) ;
F_5 ( V_33 L_7 , V_2 -> V_12 ) ;
F_5 ( V_33 L_8 , V_2 -> V_13 ) ;
F_5 ( V_33 L_9 , V_2 -> V_14 ) ;
F_5 ( V_33 L_10 , V_2 -> V_15 ) ;
F_5 ( V_33 L_11 , V_2 -> V_16 ) ;
F_5 ( V_33 L_12 ) ;
F_5 ( V_33 L_13 , V_2 -> V_11 . V_17 ) ;
F_5 ( V_33 L_14 , V_2 -> V_11 . V_19 ) ;
F_5 ( V_33 L_15 , V_2 -> V_11 . V_34 ) ;
F_5 ( V_33 L_16 ,
V_2 -> V_11 . V_21 ) ;
F_5 ( V_33 L_17 ,
V_2 -> V_11 . V_22 ) ;
F_5 ( V_33 L_18 ,
V_2 -> V_11 . V_35 ) ;
F_5 ( V_33 L_19 ) ;
F_5 ( V_33 L_20 , V_2 -> V_26 . V_17 ) ;
F_5 ( V_33 L_21 , V_2 -> V_26 . V_19 ) ;
F_5 ( V_33 L_22 , V_2 -> V_26 . V_34 ) ;
F_5 ( V_33 L_23 ,
V_2 -> V_26 . V_21 ) ;
F_5 ( V_33 L_24 ,
V_2 -> V_26 . V_22 ) ;
F_5 ( V_33 L_25 ,
V_2 -> V_26 . V_35 ) ;
F_5 ( V_33 L_26 ) ;
F_5 ( V_33 L_27 , V_2 -> V_29 . V_17 ) ;
F_5 ( V_33 L_28 , V_2 -> V_29 . V_19 ) ;
F_5 ( V_33 L_29 , V_2 -> V_29 . V_34 ) ;
F_5 ( V_33 L_30 ,
V_2 -> V_29 . V_21 ) ;
F_5 ( V_33 L_31 ,
V_2 -> V_29 . V_22 ) ;
F_5 ( V_33 L_32 ,
V_2 -> V_29 . V_35 ) ;
#endif
}
static T_1 F_6 ( struct V_36 * V_37 ,
struct V_38 * V_39 , char * V_40 )
{
return sprintf ( V_40 , L_33 , V_23 -> V_41 ) ;
}
static void F_7 ( struct V_1 * V_2 , unsigned long V_42 )
{
int V_43 ;
if ( V_2 -> V_11 . V_25 == 0 ) {
V_2 -> V_11 . V_25 += V_42 ;
V_2 -> V_26 . V_25 += V_42 ;
V_2 -> V_29 . V_25 += V_42 ;
}
do {
V_43 = F_8 ( V_44 , 3 , 1 , NULL ,
1 , V_2 , sizeof( struct V_1 ) ) ;
} while ( F_9 ( V_43 ) );
if ( V_43 ) {
F_5 ( V_45 L_34
L_35 , V_43 ) ;
F_3 ( V_2 ) ;
return;
}
V_43 = F_10 ( V_46 , & V_47 . V_39 ) ;
if ( V_43 )
F_5 ( V_45 L_36
L_37 , V_43 ) ;
}
static
void F_11 ( struct V_1 * V_2 , unsigned long V_42 )
{
int V_43 ;
if ( V_2 -> V_11 . V_25 == 0 ) {
V_2 -> V_11 . V_25 += V_42 ;
V_2 -> V_26 . V_25 += V_42 ;
V_2 -> V_29 . V_25 += V_42 ;
}
do {
V_43 = F_8 ( V_44 , 3 , 1 , NULL ,
2 , V_2 , sizeof( struct V_1 ) ) ;
} while ( F_9 ( V_43 ) );
if ( V_43 ) {
F_5 ( V_45 L_38
L_39 , V_43 ) ;
F_3 ( V_2 ) ;
}
}
static void F_12 ( unsigned long V_48 ,
unsigned long V_49 )
{
struct V_50 * V_51 ;
unsigned long V_52 ;
long V_53 ;
V_52 = V_48 + V_49 ;
for ( V_53 = V_48 ; V_53 <= V_52 ; V_53 ++ ) {
V_51 = F_13 ( V_53 ) ;
if ( F_14 ( V_51 ) ) {
F_15 ( V_51 ) ;
F_16 ( V_51 ) ;
F_17 ( V_51 ) ;
V_54 ++ ;
}
}
}
static void
F_18 ( unsigned long V_42 , unsigned long V_55 )
{
static unsigned long V_56 , V_57 ;
if ( V_42 < V_23 -> V_58 )
return;
if ( ( V_42 >= V_23 -> V_58 ) &&
( V_42 <= V_23 -> V_58 +
V_23 -> V_59 ) )
V_57 += V_55 ;
if ( ( V_42 >= V_23 -> V_60 ) &&
( V_42 <= V_23 -> V_60 +
V_23 -> V_61 ) )
V_56 += V_55 ;
if ( ( V_57 == V_23 -> V_59 ) &&
( V_56 == V_23 -> V_61 ) ) {
F_11 ( & V_62 ,
V_23 -> V_60 ) ;
F_7 ( & V_62 ,
V_23 -> V_60 ) ;
}
}
static T_1 F_19 ( struct V_36 * V_37 ,
struct V_38 * V_39 ,
const char * V_40 , T_2 V_63 )
{
unsigned long V_64 , V_55 , V_65 ;
unsigned long V_48 , V_49 ;
T_1 V_66 ;
V_66 = sscanf ( V_40 , L_40 , & V_64 , & V_55 ) ;
if ( V_66 != 2 )
return - V_67 ;
F_18 ( V_64 , V_55 ) ;
if ( V_64 < V_23 -> V_58 )
V_64 = V_23 -> V_58 ;
V_65 = V_23 -> V_58 +
V_23 -> V_59 ;
if ( V_64 + V_55 > V_65 )
V_55 = V_65 - V_64 ;
V_48 = F_20 ( V_64 ) ;
V_49 = F_20 ( V_55 ) ;
F_12 ( V_48 , V_49 ) ;
return V_63 ;
}
static T_1 F_21 ( struct V_36 * V_37 ,
struct V_38 * V_39 , char * V_40 )
{
T_3 V_68 ;
V_68 = V_23 -> V_59 -
V_23 -> V_61 ;
return sprintf ( V_40 , L_41
L_42 ,
V_62 . V_11 . V_25 ,
V_62 . V_11 . V_35 ,
V_62 . V_26 . V_25 ,
V_62 . V_26 . V_35 ,
V_62 . V_29 . V_25 ,
V_62 . V_29 . V_35 ,
V_23 -> V_58 ,
V_68 ) ;
}
static int T_4 F_22 ( void )
{
struct V_69 * V_70 ;
const struct V_1 * V_71 = NULL ;
unsigned long V_72 ;
unsigned long V_73 ;
int V_74 = 0 ;
int V_43 ;
if ( V_23 -> V_59 == 0 )
return 0 ;
if ( ! V_23 -> V_75 )
return - V_76 ;
V_70 = F_23 ( L_43 ) ;
if ( V_70 ) {
V_71 = F_24 ( V_70 , L_44 ,
& V_74 ) ;
F_25 ( V_70 ) ;
}
V_44 = F_26 ( L_45 ) ;
F_3 ( V_71 ) ;
V_73 = F_1 ( & V_62 ) ;
V_72 = V_23 -> V_58 & V_77 ;
if ( V_71 == NULL ) {
F_7 ( & V_62 , V_72 ) ;
return 0 ;
}
if ( ( V_71 ) && ( V_71 -> V_8 & V_78 ) ) {
F_11 ( & V_62 , V_72 ) ;
F_7 ( & V_62 , V_72 ) ;
return 0 ;
}
if ( V_71 ) {
V_23 -> V_60 =
V_71 -> V_11 . V_25 ;
V_23 -> V_61 =
V_71 -> V_11 . V_22 +
V_71 -> V_26 . V_22 +
V_71 -> V_29 . V_22 ;
}
V_43 = F_10 ( V_46 , & V_79 . V_39 ) ;
if ( V_43 )
F_5 ( V_45 L_46 ,
V_43 ) ;
return 0 ;
}
int T_4 F_27 ( unsigned long V_80 ,
const char * V_81 , int V_82 , void * V_83 )
{
const unsigned int * V_84 ;
V_23 -> V_75 = 0 ;
V_23 -> V_85 = 0 ;
if ( V_82 != 1 || strcmp ( V_81 , L_47 ) != 0 )
return 0 ;
if ( F_28 ( V_80 , L_45 , NULL ) )
V_23 -> V_75 ++ ;
if ( F_28 ( V_80 , L_48 , NULL ) )
V_23 -> V_85 ++ ;
V_84 = F_28 ( V_80 , L_49 ,
NULL ) ;
if ( ! V_84 )
return 0 ;
if ( V_84 [ 0 ] == 1 )
V_23 -> V_24 = * ( ( unsigned long * ) & V_84 [ 1 ] ) ;
if ( V_84 [ 3 ] == 2 )
V_23 -> V_28 =
* ( ( unsigned long * ) & V_84 [ 4 ] ) ;
return 1 ;
}
static int T_4 F_29 ( char * V_86 )
{
V_23 -> V_41 = 1 ;
if ( ! V_86 )
return 0 ;
if ( strncmp ( V_86 , L_50 , 1 ) == 0 )
V_23 -> V_41 = 1 ;
else if ( strncmp ( V_86 , L_51 , 1 ) == 0 )
V_23 -> V_41 = 0 ;
return 0 ;
}
static int T_4 F_30 ( char * V_86 )
{
if ( V_86 )
V_23 -> V_87 = F_31 ( V_86 , & V_86 ) ;
return 0 ;
}
