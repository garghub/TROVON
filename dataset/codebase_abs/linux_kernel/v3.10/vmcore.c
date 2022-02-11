int F_1 ( int (* F_2)( unsigned long V_1 ) )
{
if ( V_2 )
return - V_3 ;
V_2 = F_2 ;
return 0 ;
}
void F_3 ( void )
{
V_2 = NULL ;
F_4 () ;
}
static int F_5 ( unsigned long V_1 )
{
int (* F_2)( unsigned long V_1 );
int V_4 = 1 ;
F_2 = V_2 ;
if ( F_2 )
V_4 = F_2 ( V_1 ) ;
return V_4 ;
}
static T_1 F_6 ( char * V_5 , T_2 V_6 ,
T_3 * V_7 , int V_8 )
{
unsigned long V_1 , V_9 ;
T_2 V_10 ;
T_1 V_11 = 0 , V_12 ;
if ( ! V_6 )
return 0 ;
V_9 = ( unsigned long ) ( * V_7 % V_13 ) ;
V_1 = ( unsigned long ) ( * V_7 / V_13 ) ;
do {
if ( V_6 > ( V_13 - V_9 ) )
V_10 = V_13 - V_9 ;
else
V_10 = V_6 ;
if ( F_5 ( V_1 ) == 0 )
memset ( V_5 , 0 , V_10 ) ;
else {
V_12 = F_7 ( V_1 , V_5 , V_10 ,
V_9 , V_8 ) ;
if ( V_12 < 0 )
return V_12 ;
}
* V_7 += V_10 ;
V_6 -= V_10 ;
V_5 += V_10 ;
V_11 += V_10 ;
++ V_1 ;
V_9 = 0 ;
} while ( V_6 );
return V_11 ;
}
static T_3 F_8 ( T_4 V_9 , struct V_14 * V_15 ,
struct V_16 * * V_17 )
{
struct V_16 * V_18 ;
T_3 V_19 ;
F_9 (m, vc_list, list) {
T_3 V_20 , V_21 ;
V_20 = V_18 -> V_9 ;
V_21 = V_18 -> V_9 + V_18 -> V_22 - 1 ;
if ( V_9 >= V_20 && V_9 <= V_21 ) {
V_19 = V_18 -> V_19 + V_9 - V_20 ;
* V_17 = V_18 ;
return V_19 ;
}
}
* V_17 = NULL ;
return 0 ;
}
static T_1 F_10 ( struct V_23 * V_23 , char T_5 * V_24 ,
T_2 V_25 , T_4 * V_26 )
{
T_1 V_27 = 0 , V_12 ;
T_2 V_28 ;
T_3 V_20 , V_10 ;
struct V_16 * V_29 = NULL ;
if ( V_25 == 0 || * V_26 >= V_30 )
return 0 ;
if ( V_25 > V_30 - * V_26 )
V_25 = V_30 - * V_26 ;
if ( * V_26 < V_31 ) {
V_28 = V_31 - * V_26 ;
if ( V_25 < V_28 )
V_28 = V_25 ;
if ( F_11 ( V_24 , V_32 + * V_26 , V_28 ) )
return - V_33 ;
V_25 -= V_28 ;
* V_26 += V_28 ;
V_24 += V_28 ;
V_27 += V_28 ;
if ( V_25 == 0 )
return V_27 ;
}
V_20 = F_8 ( * V_26 , & V_34 , & V_29 ) ;
if ( ! V_29 )
return - V_35 ;
while ( V_25 ) {
V_28 = F_12 ( T_2 , V_25 , V_13 - ( V_20 & ~ V_36 ) ) ;
V_10 = ( V_29 -> V_22 - ( V_20 - V_29 -> V_19 ) ) ;
if ( V_28 > V_10 )
V_28 = V_10 ;
V_12 = F_6 ( V_24 , V_28 , & V_20 , 1 ) ;
if ( V_12 < 0 )
return V_12 ;
V_25 -= V_28 ;
* V_26 += V_28 ;
V_24 += V_28 ;
V_27 += V_28 ;
if ( V_20 >= ( V_29 -> V_19 + V_29 -> V_22 ) ) {
if ( V_29 -> V_37 . V_38 == & V_34 )
return V_27 ;
V_29 = F_13 ( V_29 -> V_37 . V_38 ,
struct V_16 , V_37 ) ;
V_20 = V_29 -> V_19 ;
}
}
return V_27 ;
}
static struct V_16 * T_6 F_14 ( void )
{
return F_15 ( sizeof( struct V_16 ) , V_39 ) ;
}
static T_3 T_6 F_16 ( char * V_40 )
{
int V_41 ;
T_3 V_22 ;
T_7 * V_42 ;
T_8 * V_43 ;
V_42 = ( T_7 * ) V_40 ;
V_43 = ( T_8 * ) ( V_40 + sizeof( T_7 ) ) ;
V_22 = sizeof( T_7 ) + ( ( V_42 -> V_44 ) * sizeof( T_8 ) ) ;
for ( V_41 = 0 ; V_41 < V_42 -> V_44 ; V_41 ++ ) {
V_22 += V_43 -> V_45 ;
V_43 ++ ;
}
return V_22 ;
}
static T_3 T_6 F_17 ( char * V_40 )
{
int V_41 ;
T_3 V_22 ;
T_9 * V_42 ;
T_10 * V_43 ;
V_42 = ( T_9 * ) V_40 ;
V_43 = ( T_10 * ) ( V_40 + sizeof( T_9 ) ) ;
V_22 = sizeof( T_9 ) + ( ( V_42 -> V_44 ) * sizeof( T_10 ) ) ;
for ( V_41 = 0 ; V_41 < V_42 -> V_44 ; V_41 ++ ) {
V_22 += V_43 -> V_45 ;
V_43 ++ ;
}
return V_22 ;
}
static int T_6 F_18 ( char * V_40 , T_2 * V_46 ,
struct V_14 * V_15 )
{
int V_41 , V_47 = 0 , V_48 = 0 ;
char * V_12 ;
T_7 * V_42 ;
T_8 V_49 , * V_43 ;
T_11 * V_50 ;
T_3 V_51 = 0 , V_52 ;
V_42 = ( T_7 * ) V_40 ;
V_43 = ( T_8 * ) ( V_40 + sizeof( T_7 ) ) ;
for ( V_41 = 0 ; V_41 < V_42 -> V_44 ; V_41 ++ , V_43 ++ ) {
int V_53 ;
void * V_54 ;
struct V_16 * V_55 ;
T_3 V_9 , V_56 , V_57 , V_58 = 0 ;
if ( V_43 -> V_59 != V_60 )
continue;
V_47 ++ ;
V_56 = V_43 -> V_45 ;
V_9 = V_43 -> V_61 ;
V_54 = F_19 ( V_56 , V_39 ) ;
if ( ! V_54 )
return - V_62 ;
V_48 = F_6 ( V_54 , V_56 , & V_9 , 0 ) ;
if ( V_48 < 0 ) {
F_20 ( V_54 ) ;
return V_48 ;
}
V_50 = V_54 ;
for ( V_53 = 0 ; V_53 < V_56 ; V_53 += V_57 ) {
if ( V_50 -> V_63 == 0 )
break;
V_57 = sizeof( T_11 ) +
( ( V_50 -> V_63 + 3 ) & ~ 3 ) +
( ( V_50 -> V_64 + 3 ) & ~ 3 ) ;
V_58 += V_57 ;
V_50 = ( T_11 * ) ( ( char * ) V_50 + V_57 ) ;
}
V_55 = F_14 () ;
if ( ! V_55 ) {
F_20 ( V_54 ) ;
return - V_62 ;
}
V_55 -> V_19 = V_43 -> V_61 ;
V_55 -> V_22 = V_58 ;
F_21 ( & V_55 -> V_37 , V_15 ) ;
V_51 += V_58 ;
F_20 ( V_54 ) ;
}
V_49 . V_59 = V_60 ;
V_49 . V_65 = 0 ;
V_52 = sizeof( T_7 ) +
( V_42 -> V_44 - V_47 + 1 ) * sizeof( T_8 ) ;
V_49 . V_61 = V_52 ;
V_49 . V_66 = V_49 . V_67 = 0 ;
V_49 . V_68 = V_49 . V_45 = V_51 ;
V_49 . V_69 = 0 ;
V_12 = V_40 + sizeof( T_7 ) ;
memcpy ( V_12 , & V_49 , sizeof( V_49 ) ) ;
V_12 += sizeof( V_49 ) ;
V_41 = ( V_47 - 1 ) * sizeof( T_8 ) ;
* V_46 = * V_46 - V_41 ;
memmove ( V_12 , V_12 + V_41 , ( ( * V_46 ) - sizeof( T_7 ) - sizeof( T_8 ) ) ) ;
V_42 -> V_44 = V_42 -> V_44 - V_47 + 1 ;
return 0 ;
}
static int T_6 F_22 ( char * V_40 , T_2 * V_46 ,
struct V_14 * V_15 )
{
int V_41 , V_47 = 0 , V_48 = 0 ;
char * V_12 ;
T_9 * V_42 ;
T_10 V_49 , * V_43 ;
T_12 * V_50 ;
T_3 V_51 = 0 , V_52 ;
V_42 = ( T_9 * ) V_40 ;
V_43 = ( T_10 * ) ( V_40 + sizeof( T_9 ) ) ;
for ( V_41 = 0 ; V_41 < V_42 -> V_44 ; V_41 ++ , V_43 ++ ) {
int V_53 ;
void * V_54 ;
struct V_16 * V_55 ;
T_3 V_9 , V_56 , V_57 , V_58 = 0 ;
if ( V_43 -> V_59 != V_60 )
continue;
V_47 ++ ;
V_56 = V_43 -> V_45 ;
V_9 = V_43 -> V_61 ;
V_54 = F_19 ( V_56 , V_39 ) ;
if ( ! V_54 )
return - V_62 ;
V_48 = F_6 ( V_54 , V_56 , & V_9 , 0 ) ;
if ( V_48 < 0 ) {
F_20 ( V_54 ) ;
return V_48 ;
}
V_50 = V_54 ;
for ( V_53 = 0 ; V_53 < V_56 ; V_53 += V_57 ) {
if ( V_50 -> V_63 == 0 )
break;
V_57 = sizeof( T_12 ) +
( ( V_50 -> V_63 + 3 ) & ~ 3 ) +
( ( V_50 -> V_64 + 3 ) & ~ 3 ) ;
V_58 += V_57 ;
V_50 = ( T_12 * ) ( ( char * ) V_50 + V_57 ) ;
}
V_55 = F_14 () ;
if ( ! V_55 ) {
F_20 ( V_54 ) ;
return - V_62 ;
}
V_55 -> V_19 = V_43 -> V_61 ;
V_55 -> V_22 = V_58 ;
F_21 ( & V_55 -> V_37 , V_15 ) ;
V_51 += V_58 ;
F_20 ( V_54 ) ;
}
V_49 . V_59 = V_60 ;
V_49 . V_65 = 0 ;
V_52 = sizeof( T_9 ) +
( V_42 -> V_44 - V_47 + 1 ) * sizeof( T_10 ) ;
V_49 . V_61 = V_52 ;
V_49 . V_66 = V_49 . V_67 = 0 ;
V_49 . V_68 = V_49 . V_45 = V_51 ;
V_49 . V_69 = 0 ;
V_12 = V_40 + sizeof( T_9 ) ;
memcpy ( V_12 , & V_49 , sizeof( V_49 ) ) ;
V_12 += sizeof( V_49 ) ;
V_41 = ( V_47 - 1 ) * sizeof( T_10 ) ;
* V_46 = * V_46 - V_41 ;
memmove ( V_12 , V_12 + V_41 , ( ( * V_46 ) - sizeof( T_9 ) - sizeof( T_10 ) ) ) ;
V_42 -> V_44 = V_42 -> V_44 - V_47 + 1 ;
return 0 ;
}
static int T_6 F_23 ( char * V_40 ,
T_2 V_46 ,
struct V_14 * V_15 )
{
int V_41 ;
T_7 * V_42 ;
T_8 * V_43 ;
T_4 V_70 ;
struct V_16 * V_55 ;
V_42 = ( T_7 * ) V_40 ;
V_43 = ( T_8 * ) ( V_40 + sizeof( T_7 ) ) ;
V_70 = sizeof( T_7 ) +
( V_42 -> V_44 ) * sizeof( T_8 ) +
V_43 -> V_45 ;
for ( V_41 = 0 ; V_41 < V_42 -> V_44 ; V_41 ++ , V_43 ++ ) {
if ( V_43 -> V_59 != V_71 )
continue;
V_55 = F_14 () ;
if ( ! V_55 )
return - V_62 ;
V_55 -> V_19 = V_43 -> V_61 ;
V_55 -> V_22 = V_43 -> V_45 ;
F_21 ( & V_55 -> V_37 , V_15 ) ;
V_43 -> V_61 = V_70 ;
V_70 = V_70 + V_43 -> V_45 ;
}
return 0 ;
}
static int T_6 F_24 ( char * V_40 ,
T_2 V_46 ,
struct V_14 * V_15 )
{
int V_41 ;
T_9 * V_42 ;
T_10 * V_43 ;
T_4 V_70 ;
struct V_16 * V_55 ;
V_42 = ( T_9 * ) V_40 ;
V_43 = ( T_10 * ) ( V_40 + sizeof( T_9 ) ) ;
V_70 = sizeof( T_9 ) +
( V_42 -> V_44 ) * sizeof( T_10 ) +
V_43 -> V_45 ;
for ( V_41 = 0 ; V_41 < V_42 -> V_44 ; V_41 ++ , V_43 ++ ) {
if ( V_43 -> V_59 != V_71 )
continue;
V_55 = F_14 () ;
if ( ! V_55 )
return - V_62 ;
V_55 -> V_19 = V_43 -> V_61 ;
V_55 -> V_22 = V_43 -> V_45 ;
F_21 ( & V_55 -> V_37 , V_15 ) ;
V_43 -> V_61 = V_70 ;
V_70 = V_70 + V_43 -> V_45 ;
}
return 0 ;
}
static void T_6 F_25 ( char * V_40 ,
struct V_14 * V_15 )
{
T_4 V_70 ;
T_7 * V_42 ;
struct V_16 * V_18 ;
V_42 = ( T_7 * ) V_40 ;
V_70 = sizeof( T_7 ) +
( V_42 -> V_44 ) * sizeof( T_8 ) ;
F_9 (m, vc_list, list) {
V_18 -> V_9 = V_70 ;
V_70 += V_18 -> V_22 ;
}
}
static void T_6 F_26 ( char * V_40 ,
struct V_14 * V_15 )
{
T_4 V_70 ;
T_9 * V_42 ;
struct V_16 * V_18 ;
V_42 = ( T_9 * ) V_40 ;
V_70 = sizeof( T_9 ) +
( V_42 -> V_44 ) * sizeof( T_10 ) ;
F_9 (m, vc_list, list) {
V_18 -> V_9 = V_70 ;
V_70 += V_18 -> V_22 ;
}
}
static int T_6 F_27 ( void )
{
int V_48 = 0 ;
T_7 V_72 ;
T_3 V_73 ;
V_73 = V_74 ;
V_48 = F_6 ( ( char * ) & V_72 , sizeof( T_7 ) , & V_73 , 0 ) ;
if ( V_48 < 0 )
return V_48 ;
if ( memcmp ( V_72 . V_75 , V_76 , V_77 ) != 0 ||
( V_72 . V_78 != V_79 ) ||
! F_28 ( & V_72 ) ||
V_72 . V_75 [ V_80 ] != V_81 ||
V_72 . V_75 [ V_82 ] != V_83 ||
V_72 . V_84 != V_83 ||
V_72 . V_85 != sizeof( T_7 ) ||
V_72 . V_86 != sizeof( T_8 ) ||
V_72 . V_44 == 0 ) {
F_29 ( L_1 ) ;
return - V_35 ;
}
V_31 = sizeof( T_7 ) + V_72 . V_44 * sizeof( T_8 ) ;
V_32 = F_19 ( V_31 , V_39 ) ;
if ( ! V_32 )
return - V_62 ;
V_73 = V_74 ;
V_48 = F_6 ( V_32 , V_31 , & V_73 , 0 ) ;
if ( V_48 < 0 ) {
F_20 ( V_32 ) ;
return V_48 ;
}
V_48 = F_18 ( V_32 , & V_31 , & V_34 ) ;
if ( V_48 ) {
F_20 ( V_32 ) ;
return V_48 ;
}
V_48 = F_23 ( V_32 , V_31 ,
& V_34 ) ;
if ( V_48 ) {
F_20 ( V_32 ) ;
return V_48 ;
}
F_25 ( V_32 , & V_34 ) ;
return 0 ;
}
static int T_6 F_30 ( void )
{
int V_48 = 0 ;
T_9 V_72 ;
T_3 V_73 ;
V_73 = V_74 ;
V_48 = F_6 ( ( char * ) & V_72 , sizeof( T_9 ) , & V_73 , 0 ) ;
if ( V_48 < 0 )
return V_48 ;
if ( memcmp ( V_72 . V_75 , V_76 , V_77 ) != 0 ||
( V_72 . V_78 != V_79 ) ||
! F_31 ( & V_72 ) ||
V_72 . V_75 [ V_80 ] != V_87 ||
V_72 . V_75 [ V_82 ] != V_83 ||
V_72 . V_84 != V_83 ||
V_72 . V_85 != sizeof( T_9 ) ||
V_72 . V_86 != sizeof( T_10 ) ||
V_72 . V_44 == 0 ) {
F_29 ( L_1 ) ;
return - V_35 ;
}
V_31 = sizeof( T_9 ) + V_72 . V_44 * sizeof( T_10 ) ;
V_32 = F_19 ( V_31 , V_39 ) ;
if ( ! V_32 )
return - V_62 ;
V_73 = V_74 ;
V_48 = F_6 ( V_32 , V_31 , & V_73 , 0 ) ;
if ( V_48 < 0 ) {
F_20 ( V_32 ) ;
return V_48 ;
}
V_48 = F_22 ( V_32 , & V_31 , & V_34 ) ;
if ( V_48 ) {
F_20 ( V_32 ) ;
return V_48 ;
}
V_48 = F_24 ( V_32 , V_31 ,
& V_34 ) ;
if ( V_48 ) {
F_20 ( V_32 ) ;
return V_48 ;
}
F_26 ( V_32 , & V_34 ) ;
return 0 ;
}
static int T_6 F_32 ( void )
{
unsigned char V_75 [ V_88 ] ;
T_3 V_73 ;
int V_48 = 0 ;
V_73 = V_74 ;
V_48 = F_6 ( V_75 , V_88 , & V_73 , 0 ) ;
if ( V_48 < 0 )
return V_48 ;
if ( memcmp ( V_75 , V_76 , V_77 ) != 0 ) {
F_29 ( L_2 ) ;
return - V_35 ;
}
if ( V_75 [ V_80 ] == V_81 ) {
V_48 = F_27 () ;
if ( V_48 )
return V_48 ;
V_30 = F_16 ( V_32 ) ;
} else if ( V_75 [ V_80 ] == V_87 ) {
V_48 = F_30 () ;
if ( V_48 )
return V_48 ;
V_30 = F_17 ( V_32 ) ;
} else {
F_29 ( L_1 ) ;
return - V_35 ;
}
return 0 ;
}
static int T_6 F_33 ( void )
{
int V_48 = 0 ;
if ( ! ( F_34 () ) )
return V_48 ;
V_48 = F_32 () ;
if ( V_48 ) {
F_29 ( L_3 ) ;
return V_48 ;
}
V_89 = F_35 ( L_4 , V_90 , NULL , & V_91 ) ;
if ( V_89 )
V_89 -> V_22 = V_30 ;
return 0 ;
}
void F_36 ( void )
{
struct V_14 * V_92 , * V_38 ;
if ( V_89 ) {
F_37 ( V_89 ) ;
V_89 = NULL ;
}
F_38 (pos, next, &vmcore_list) {
struct V_16 * V_18 ;
V_18 = F_13 ( V_92 , struct V_16 , V_37 ) ;
F_39 ( & V_18 -> V_37 ) ;
F_20 ( V_18 ) ;
}
F_20 ( V_32 ) ;
V_32 = NULL ;
}
