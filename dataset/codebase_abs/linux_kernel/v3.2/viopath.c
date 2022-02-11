static int F_1 ( struct V_1 * V_2 , void * V_3 )
{
char * V_4 ;
T_1 V_5 ;
T_2 V_6 ;
T_3 V_7 ;
F_2 ( V_8 ) ;
struct V_9 * V_10 ;
const char * V_11 ;
V_4 = F_3 ( V_12 , V_13 ) ;
if ( ! V_4 )
return 0 ;
V_6 = F_4 ( V_4 , V_12 , V_14 ) ;
V_7 = F_5 ( V_15 ,
V_16 ,
V_17 | V_18 ,
V_19 , V_20 ,
F_6 ( V_15 ) ,
F_7 ( V_15 ) ,
( V_21 ) ( unsigned long ) & V_8 , V_22 << 16 ,
( ( V_21 ) V_6 ) << 32 , V_12 , 0 , 0 ) ;
if ( V_7 != V_23 )
F_8 ( V_24 L_1 , ( int ) V_7 ) ;
F_9 ( & V_8 ) ;
V_5 = F_10 () ;
V_4 [ V_12 - 1 ] = '\0' ;
F_11 ( V_2 , L_2 , V_4 ) ;
F_12 ( V_6 , V_12 , V_14 ) ;
F_13 ( V_4 ) ;
F_11 ( V_2 , L_3 , V_5 ) ;
V_10 = F_14 ( L_4 ) ;
V_11 = NULL ;
if ( V_10 != NULL )
V_11 = F_15 ( V_10 , L_5 , NULL ) ;
if ( V_11 == NULL )
F_11 ( V_2 , L_6 ) ;
else
F_11 ( V_2 , L_7 , V_11 + 4 ) ;
F_16 ( V_10 ) ;
return 0 ;
}
static int F_17 ( struct V_25 * V_25 , struct V_26 * V_26 )
{
return F_18 ( V_26 , F_1 , NULL ) ;
}
static int T_4 F_19 ( void )
{
if ( ! F_20 ( V_27 ) )
return 0 ;
F_21 ( L_8 , 0 , NULL , & V_28 ) ;
return 0 ;
}
int F_22 ( T_5 V_29 )
{
if ( V_29 == V_30 )
return 0 ;
if ( V_29 < V_31 )
return V_32 [ V_29 ] . V_33 ;
else
return 0 ;
}
T_6 F_6 ( T_5 V_29 )
{
return V_32 [ V_29 ] . V_34 ;
}
T_6 F_7 ( T_5 V_29 )
{
return V_32 [ V_29 ] . V_35 ;
}
static void F_23 ( T_5 V_36 )
{
T_3 V_7 ;
V_32 [ V_36 ] . V_34 =
F_24 ( V_36 ,
V_16 ) ;
V_32 [ V_36 ] . V_35 =
F_25 ( V_36 ,
V_16 ) ;
F_26 ( V_37 , V_38 ) ;
V_7 = F_5 ( V_36 , V_16 ,
V_37 , V_19 ,
V_39 ,
V_32 [ V_36 ] . V_34 ,
V_32 [ V_36 ] . V_35 ,
V_40 ++ , 0 , 0 , 0 , 0 , 0 ) ;
if ( V_7 == V_23 )
V_32 [ V_36 ] . V_33 = 1 ;
else {
F_8 ( V_24 L_9 ,
V_36 ) ;
V_32 [ V_36 ] . V_33 = 0 ;
}
}
static void V_38 ( struct V_41 * V_42 )
{
T_5 V_36 ;
int V_43 ;
if ( ! V_42 )
return;
if ( F_27 ( V_42 ) ) {
V_36 = V_42 -> V_44 ;
if ( ! V_32 [ V_36 ] . V_33 )
F_23 ( V_36 ) ;
return;
}
V_36 = V_42 -> V_45 ;
if ( ( V_42 -> V_46 != V_32 [ V_36 ] . V_34 ) ||
( V_42 -> V_47 != V_32 [ V_36 ] . V_35 ) ) {
F_8 ( V_24 L_10 ) ;
return;
}
F_8 ( V_24 L_11 , V_36 ) ;
V_32 [ V_36 ] . V_33 = 0 ;
for ( V_43 = 0 ; V_43 < V_48 ; V_43 ++ ) {
if ( V_49 [ V_43 ] != NULL )
(* V_49 [ V_43 ])( NULL ) ;
}
}
int F_26 ( int V_50 , T_7 * V_51 )
{
V_50 = V_50 >> V_52 ;
if ( ( V_50 < 0 ) || ( V_50 >= V_48 ) )
return - V_53 ;
if ( V_49 [ V_50 ] != NULL )
return - V_54 ;
V_49 [ V_50 ] = V_51 ;
return 0 ;
}
int F_28 ( int V_50 )
{
V_50 = V_50 >> V_52 ;
if ( ( V_50 < 0 ) || ( V_50 >= V_48 ) )
return - V_53 ;
if ( V_49 [ V_50 ] == NULL )
return - V_55 ;
V_49 [ V_50 ] = NULL ;
return 0 ;
}
static void F_29 ( struct V_41 * V_42 )
{
if ( ! V_42 )
return;
if ( F_27 ( V_42 ) ) {
F_8 ( V_24
L_12 ,
V_42 -> V_44 ) ;
if ( F_30 ( V_42 ) ) {
V_42 -> V_56 = V_57 ;
F_31 ( V_42 ) ;
}
return;
}
F_32 ( (struct V_58 * ) V_42 -> V_59 ) ;
}
void F_33 ( void )
{
if ( V_15 != V_30 )
return;
V_60 = F_34 () ;
V_15 = F_35 ( V_60 ) ;
if ( V_15 != V_30 )
F_26 ( V_17 , F_29 ) ;
}
static void F_36 ( struct V_41 * V_42 )
{
T_5 V_36 ;
int V_50 = ( V_42 -> V_61 & V_62 )
>> V_52 ;
if ( F_27 ( V_42 ) ) {
V_36 = V_42 -> V_44 ;
if ( V_32 [ V_36 ] . V_33
&& ( V_42 -> V_46 !=
V_32 [ V_36 ] . V_35 ) ) {
F_8 ( V_24
L_13
L_14 ,
V_32 [ V_36 ] . V_35 ,
V_42 -> V_46 ) ;
return;
}
if ( V_32 [ V_36 ] . V_33
&& ( V_42 -> V_47 !=
V_32 [ V_36 ] . V_34 ) ) {
F_8 ( V_24
L_13
L_15 ,
V_32 [ V_36 ] . V_34 ,
V_42 -> V_47 ) ;
return;
}
} else {
V_36 = V_42 -> V_45 ;
if ( V_42 -> V_46 !=
V_32 [ V_36 ] . V_34 ) {
F_8 ( V_24
L_13
L_16 ,
V_32 [ V_36 ] . V_34 ,
V_42 -> V_46 ) ;
return;
}
if ( V_42 -> V_47 !=
V_32 [ V_36 ] . V_35 ) {
F_8 ( V_24
L_13
L_17 ,
V_32 [ V_36 ] . V_35 ,
V_42 -> V_47 ) ;
return;
}
}
if ( V_49 [ V_50 ] == NULL ) {
F_8 ( V_24
L_18 ,
V_42 -> V_61 , V_36 ) ;
if ( F_27 ( V_42 ) && F_30 ( V_42 ) ) {
V_42 -> V_56 = V_57 ;
F_31 ( V_42 ) ;
}
return;
}
(* V_49 [ V_50 ])( V_42 ) ;
}
static void F_37 ( void * V_63 , int V_64 )
{
struct V_65 * V_66 = V_63 ;
V_66 -> V_64 = V_64 ;
if ( V_66 -> V_67 )
F_38 ( & V_66 -> V_68 , 0 ) ;
else
F_32 ( & V_66 -> V_8 ) ;
}
static int F_39 ( T_5 V_36 , int V_69 )
{
struct V_65 V_70 ;
if ( V_71 != V_72 ) {
V_70 . V_67 = 1 ;
F_38 ( & V_70 . V_68 , 1 ) ;
} else {
V_70 . V_67 = 0 ;
F_40 ( & V_70 . V_8 ) ;
}
F_41 ( V_36 , V_16 , 250 ,
V_69 , & F_37 , & V_70 ) ;
if ( V_71 != V_72 ) {
while ( F_42 ( & V_70 . V_68 ) )
F_43 () ;
} else
F_9 ( & V_70 . V_8 ) ;
return V_70 . V_64 ;
}
int F_44 ( T_5 V_36 , int V_50 , int V_73 )
{
int V_43 ;
unsigned long V_74 ;
int V_75 ;
if ( ( V_36 >= V_31 ) || ( V_36 == V_30 ) )
return - V_53 ;
V_50 = V_50 >> V_52 ;
if ( ( V_50 < 0 ) || ( V_50 >= V_48 ) )
return - V_53 ;
F_45 ( & V_76 , V_74 ) ;
if ( ! V_77 ) {
for ( V_43 = 0 ; V_43 < V_48 ; V_43 ++ )
F_38 ( & V_78 [ V_43 ] , 1 ) ;
V_77 = 1 ;
}
V_32 [ V_36 ] . V_79 [ V_50 ] ++ ;
if ( ! V_32 [ V_36 ] . V_80 ) {
V_32 [ V_36 ] . V_80 = 1 ;
F_46 ( V_36 , V_16 ) ;
F_47 ( & V_76 , V_74 ) ;
V_75 = F_39 ( V_36 , 1 ) ;
F_45 ( & V_76 , V_74 ) ;
V_32 [ V_36 ] . V_81 += V_75 ;
if ( V_32 [ V_36 ] . V_81 == 0 ) {
F_48 ( V_36 ,
V_16 ) ;
F_47 ( & V_76 , V_74 ) ;
return - V_82 ;
}
V_32 [ V_36 ] . V_34 =
F_24 ( V_36 ,
V_16 ) ;
V_32 [ V_36 ] . V_35 =
F_25 ( V_36 ,
V_16 ) ;
F_49 ( V_16 ,
& F_36 ) ;
F_23 ( V_36 ) ;
F_8 ( V_83 L_19
L_20 ,
V_36 , V_32 [ V_36 ] . V_34 ,
V_32 [ V_36 ] . V_35 ) ;
}
F_47 ( & V_76 , V_74 ) ;
V_75 = F_39 ( V_36 , V_73 ) ;
F_45 ( & V_76 , V_74 ) ;
V_32 [ V_36 ] . V_81 += V_75 ;
F_47 ( & V_76 , V_74 ) ;
return 0 ;
}
int F_50 ( T_5 V_36 , int V_50 , int V_73 )
{
unsigned long V_74 ;
int V_43 ;
int V_84 ;
struct V_65 V_70 ;
if ( ( V_36 >= V_31 ) || ( V_36 == V_30 ) )
return - V_53 ;
V_50 = V_50 >> V_52 ;
if ( ( V_50 < 0 ) || ( V_50 >= V_48 ) )
return - V_53 ;
F_45 ( & V_76 , V_74 ) ;
if ( V_32 [ V_36 ] . V_79 [ V_50 ] > 0 )
V_32 [ V_36 ] . V_79 [ V_50 ] -- ;
F_47 ( & V_76 , V_74 ) ;
V_70 . V_67 = 0 ;
F_40 ( & V_70 . V_8 ) ;
F_51 ( V_36 , V_16 ,
V_73 , & F_37 , & V_70 ) ;
F_9 ( & V_70 . V_8 ) ;
F_45 ( & V_76 , V_74 ) ;
for ( V_43 = 0 , V_84 = 0 ; V_43 < V_48 ; V_43 ++ )
V_84 += V_32 [ V_36 ] . V_79 [ V_43 ] ;
if ( ( V_32 [ V_36 ] . V_80 ) && ( V_84 == 0 ) ) {
F_8 ( V_83 L_21 ,
V_36 ) ;
F_48 ( V_36 ,
V_16 ) ;
V_32 [ V_36 ] . V_80 = 0 ;
V_32 [ V_36 ] . V_33 = 0 ;
for ( V_43 = 0 ; V_43 < V_48 ; V_43 ++ )
F_38 ( & V_78 [ V_43 ] , 0 ) ;
V_77 = 0 ;
}
F_47 ( & V_76 , V_74 ) ;
return 0 ;
}
void * F_52 ( int V_50 )
{
V_50 = V_50 >> V_52 ;
if ( ( V_50 < 0 ) || ( V_50 >= V_48 ) )
return NULL ;
if ( F_53 ( & V_78 [ V_50 ] ) == 0 )
return & V_85 [ V_50 * 256 ] ;
else
return NULL ;
}
void F_54 ( int V_50 , void * V_86 )
{
V_50 = V_50 >> V_52 ;
if ( ( V_50 < 0 ) || ( V_50 >= V_48 ) ) {
F_8 ( V_24
L_22 , V_50 ) ;
return;
}
if ( F_42 ( & V_78 [ V_50 ] ) != 0 ) {
F_8 ( V_24
L_23 ,
V_50 ) ;
return;
}
if ( V_86 != & V_85 [ V_50 * 256 ] ) {
F_8 ( V_24
L_24 , V_50 ) ;
}
F_38 ( & V_78 [ V_50 ] , 1 ) ;
}
const struct V_87 * F_55 (
const struct V_87 * V_88 , T_1 V_89 )
{
const struct V_87 * V_90 ;
if ( ! V_89 )
return & V_91 ;
if ( V_88 )
for ( V_90 = V_88 ; V_90 -> V_89 ; ++ V_90 )
if ( V_90 -> V_89 == V_89 )
return V_90 ;
for ( V_90 = V_92 ; V_90 -> V_89 ; ++ V_90 )
if ( V_90 -> V_89 == V_89 )
return V_90 ;
return & V_93 ;
}
