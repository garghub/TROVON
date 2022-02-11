static struct V_1 *
F_1 ( struct V_2 * V_3 , struct V_2 * * V_4 , unsigned char * V_5 ,
T_1 V_6 , struct V_7 * V_8 )
{
struct V_9 * V_10 = F_2 ( V_8 , V_11 ,
& V_3 , 1 , V_4 , 2 , V_6 ) ;
struct V_12 * V_13 = V_10 ? V_10 -> V_14 : NULL ;
struct V_15 * V_16 = NULL ;
const T_2 * V_17 , * V_18 ;
T_2 V_19 , V_20 ;
T_2 * V_21 , * V_22 , * V_23 ;
if ( V_13 )
V_16 = F_3 ( V_13 -> V_24 , 3 , V_25 ) ;
if ( V_16 ) {
struct V_14 * V_24 = V_13 -> V_24 ;
T_3 V_26 [ 2 ] ;
struct V_1 * V_27 ;
enum V_28 V_29 = V_30 ;
if ( V_8 -> V_31 & V_32 )
V_29 |= V_33 ;
V_16 -> V_34 [ 0 ] = F_4 ( V_24 , V_4 [ 0 ] , 0 , V_6 , V_35 ) ;
V_16 -> V_34 [ 1 ] = F_4 ( V_24 , V_4 [ 1 ] , 0 , V_6 , V_35 ) ;
V_16 -> V_36 = 2 ;
V_16 -> V_34 [ 2 ] = F_4 ( V_24 , V_3 , 0 , V_6 , V_37 ) ;
V_16 -> V_38 = 1 ;
V_26 [ 1 ] = V_16 -> V_34 [ 2 ] ;
V_16 -> V_6 = V_6 ;
V_27 = V_13 -> V_39 ( V_10 , V_26 , V_16 -> V_34 , 2 , V_5 ,
V_6 , V_29 ) ;
if ( V_27 ) {
F_5 ( V_27 , V_16 ) ;
F_6 ( V_10 , V_27 , V_8 ) ;
F_7 ( V_16 ) ;
return V_27 ;
}
F_7 ( V_16 ) ;
}
F_8 ( & V_8 -> V_40 ) ;
V_17 = V_41 [ V_5 [ 0 ] ] ;
V_18 = V_41 [ V_5 [ 1 ] ] ;
V_21 = F_9 ( V_4 [ 0 ] ) ;
V_22 = F_9 ( V_4 [ 1 ] ) ;
V_23 = F_9 ( V_3 ) ;
while ( V_6 -- ) {
V_19 = V_17 [ * V_21 ++ ] ;
V_20 = V_18 [ * V_22 ++ ] ;
* V_23 ++ = V_19 ^ V_20 ;
}
return NULL ;
}
static struct V_1 *
F_10 ( struct V_2 * V_3 , struct V_2 * V_42 , T_2 V_5 , T_1 V_6 ,
struct V_7 * V_8 )
{
struct V_9 * V_10 = F_2 ( V_8 , V_11 ,
& V_3 , 1 , & V_42 , 1 , V_6 ) ;
struct V_12 * V_13 = V_10 ? V_10 -> V_14 : NULL ;
struct V_15 * V_16 = NULL ;
const T_2 * V_43 ;
T_2 * V_44 , * V_45 ;
if ( V_13 )
V_16 = F_3 ( V_13 -> V_24 , 3 , V_25 ) ;
if ( V_16 ) {
T_3 V_46 [ 2 ] ;
struct V_14 * V_24 = V_13 -> V_24 ;
struct V_1 * V_27 ;
enum V_28 V_29 = V_30 ;
if ( V_8 -> V_31 & V_32 )
V_29 |= V_33 ;
V_16 -> V_34 [ 0 ] = F_4 ( V_24 , V_42 , 0 , V_6 , V_35 ) ;
V_16 -> V_36 ++ ;
V_16 -> V_34 [ 1 ] = F_4 ( V_24 , V_3 , 0 , V_6 , V_37 ) ;
V_46 [ 1 ] = V_16 -> V_34 [ 1 ] ;
V_16 -> V_38 ++ ;
V_16 -> V_6 = V_6 ;
V_27 = V_13 -> V_39 ( V_10 , V_46 , V_16 -> V_34 ,
1 , & V_5 , V_6 , V_29 ) ;
if ( V_27 ) {
F_5 ( V_27 , V_16 ) ;
F_7 ( V_16 ) ;
F_6 ( V_10 , V_27 , V_8 ) ;
return V_27 ;
}
F_7 ( V_16 ) ;
}
F_8 ( & V_8 -> V_40 ) ;
V_43 = V_41 [ V_5 ] ;
V_44 = F_9 ( V_3 ) ;
V_45 = F_9 ( V_42 ) ;
while ( V_6 -- )
* V_44 ++ = V_43 [ * V_45 ++ ] ;
return NULL ;
}
static struct V_1 *
F_11 ( int V_47 , T_1 V_48 , int V_49 , int V_50 ,
struct V_2 * * V_51 , struct V_7 * V_8 )
{
struct V_1 * V_27 = NULL ;
struct V_2 * V_52 , * V_53 , * V_21 , * V_22 ;
struct V_2 * V_4 [ 2 ] ;
unsigned char V_5 [ 2 ] ;
enum V_54 V_31 = V_8 -> V_31 ;
T_4 V_55 = V_8 -> V_55 ;
void * V_56 = V_8 -> V_56 ;
void * V_57 = V_8 -> V_57 ;
V_52 = V_51 [ V_47 - 2 ] ;
V_53 = V_51 [ V_47 - 1 ] ;
V_21 = V_51 [ V_49 ] ;
V_22 = V_51 [ V_50 ] ;
V_4 [ 0 ] = V_52 ;
V_4 [ 1 ] = V_53 ;
V_5 [ 0 ] = V_58 [ V_50 - V_49 ] ;
V_5 [ 1 ] = V_59 [ V_60 [ V_49 ] ^ V_60 [ V_50 ] ] ;
F_12 ( V_8 , V_32 , V_27 , NULL , NULL , V_57 ) ;
V_27 = F_1 ( V_22 , V_4 , V_5 , V_48 , V_8 ) ;
V_4 [ 0 ] = V_52 ;
V_4 [ 1 ] = V_22 ;
F_12 ( V_8 , V_31 | V_61 , V_27 , V_55 ,
V_56 , V_57 ) ;
V_27 = F_13 ( V_21 , V_4 , 0 , 2 , V_48 , V_8 ) ;
return V_27 ;
}
static struct V_1 *
F_14 ( int V_47 , T_1 V_48 , int V_49 , int V_50 ,
struct V_2 * * V_51 , struct V_7 * V_8 )
{
struct V_1 * V_27 = NULL ;
struct V_2 * V_52 , * V_53 , * V_62 , * V_63 , * V_64 ;
struct V_2 * V_4 [ 2 ] ;
unsigned char V_5 [ 2 ] ;
enum V_54 V_31 = V_8 -> V_31 ;
T_4 V_55 = V_8 -> V_55 ;
void * V_56 = V_8 -> V_56 ;
void * V_57 = V_8 -> V_57 ;
int V_65 , V_66 , V_67 ;
V_65 = 0 ;
V_66 = - 1 ;
for ( V_67 = 0 ; V_67 < V_47 - 2 ; V_67 ++ ) {
if ( V_51 [ V_67 ] == NULL )
continue;
if ( V_67 == V_49 || V_67 == V_50 )
continue;
V_66 = V_67 ;
V_65 ++ ;
}
F_15 ( V_65 > 1 ) ;
V_52 = V_51 [ V_47 - 2 ] ;
V_53 = V_51 [ V_47 - 1 ] ;
V_62 = V_51 [ V_66 ] ;
V_63 = V_51 [ V_49 ] ;
V_64 = V_51 [ V_50 ] ;
F_12 ( V_8 , V_32 , V_27 , NULL , NULL , V_57 ) ;
V_27 = F_16 ( V_63 , V_62 , 0 , 0 , V_48 , V_8 ) ;
F_12 ( V_8 , V_32 , V_27 , NULL , NULL , V_57 ) ;
V_27 = F_10 ( V_64 , V_62 , V_60 [ V_66 ] , V_48 , V_8 ) ;
V_4 [ 0 ] = V_63 ;
V_4 [ 1 ] = V_52 ;
F_12 ( V_8 , V_32 | V_68 , V_27 ,
NULL , NULL , V_57 ) ;
V_27 = F_13 ( V_63 , V_4 , 0 , 2 , V_48 , V_8 ) ;
V_4 [ 0 ] = V_64 ;
V_4 [ 1 ] = V_53 ;
F_12 ( V_8 , V_32 | V_68 , V_27 ,
NULL , NULL , V_57 ) ;
V_27 = F_13 ( V_64 , V_4 , 0 , 2 , V_48 , V_8 ) ;
V_4 [ 0 ] = V_63 ;
V_4 [ 1 ] = V_64 ;
V_5 [ 0 ] = V_58 [ V_50 - V_49 ] ;
V_5 [ 1 ] = V_59 [ V_60 [ V_49 ] ^ V_60 [ V_50 ] ] ;
F_12 ( V_8 , V_32 , V_27 , NULL , NULL , V_57 ) ;
V_27 = F_1 ( V_64 , V_4 , V_5 , V_48 , V_8 ) ;
V_4 [ 0 ] = V_63 ;
V_4 [ 1 ] = V_64 ;
F_12 ( V_8 , V_31 | V_68 , V_27 , V_55 ,
V_56 , V_57 ) ;
V_27 = F_13 ( V_63 , V_4 , 0 , 2 , V_48 , V_8 ) ;
return V_27 ;
}
static struct V_1 *
F_17 ( int V_47 , T_1 V_48 , int V_49 , int V_50 ,
struct V_2 * * V_51 , struct V_7 * V_8 )
{
struct V_1 * V_27 = NULL ;
struct V_2 * V_52 , * V_53 , * V_63 , * V_64 ;
struct V_2 * V_4 [ 2 ] ;
unsigned char V_5 [ 2 ] ;
enum V_54 V_31 = V_8 -> V_31 ;
T_4 V_55 = V_8 -> V_55 ;
void * V_56 = V_8 -> V_56 ;
void * V_57 = V_8 -> V_57 ;
V_52 = V_51 [ V_47 - 2 ] ;
V_53 = V_51 [ V_47 - 1 ] ;
V_63 = V_51 [ V_49 ] ;
V_51 [ V_49 ] = NULL ;
V_51 [ V_47 - 2 ] = V_63 ;
V_64 = V_51 [ V_50 ] ;
V_51 [ V_50 ] = NULL ;
V_51 [ V_47 - 1 ] = V_64 ;
F_12 ( V_8 , V_32 , V_27 , NULL , NULL , V_57 ) ;
V_27 = F_18 ( V_51 , 0 , V_47 , V_48 , V_8 ) ;
V_51 [ V_49 ] = V_63 ;
V_51 [ V_50 ] = V_64 ;
V_51 [ V_47 - 2 ] = V_52 ;
V_51 [ V_47 - 1 ] = V_53 ;
V_4 [ 0 ] = V_63 ;
V_4 [ 1 ] = V_52 ;
F_12 ( V_8 , V_32 | V_68 , V_27 ,
NULL , NULL , V_57 ) ;
V_27 = F_13 ( V_63 , V_4 , 0 , 2 , V_48 , V_8 ) ;
V_4 [ 0 ] = V_64 ;
V_4 [ 1 ] = V_53 ;
F_12 ( V_8 , V_32 | V_68 , V_27 ,
NULL , NULL , V_57 ) ;
V_27 = F_13 ( V_64 , V_4 , 0 , 2 , V_48 , V_8 ) ;
V_4 [ 0 ] = V_63 ;
V_4 [ 1 ] = V_64 ;
V_5 [ 0 ] = V_58 [ V_50 - V_49 ] ;
V_5 [ 1 ] = V_59 [ V_60 [ V_49 ] ^ V_60 [ V_50 ] ] ;
F_12 ( V_8 , V_32 , V_27 , NULL , NULL , V_57 ) ;
V_27 = F_1 ( V_64 , V_4 , V_5 , V_48 , V_8 ) ;
V_4 [ 0 ] = V_63 ;
V_4 [ 1 ] = V_64 ;
F_12 ( V_8 , V_31 | V_68 , V_27 , V_55 ,
V_56 , V_57 ) ;
V_27 = F_13 ( V_63 , V_4 , 0 , 2 , V_48 , V_8 ) ;
return V_27 ;
}
struct V_1 *
F_19 ( int V_47 , T_1 V_48 , int V_49 , int V_50 ,
struct V_2 * * V_51 , struct V_7 * V_8 )
{
void * V_57 = V_8 -> V_57 ;
int V_69 , V_67 ;
F_15 ( V_49 == V_50 ) ;
if ( V_50 < V_49 )
F_20 ( V_49 , V_50 ) ;
F_21 ( L_1 , V_70 , V_47 , V_48 ) ;
if ( ! F_22 ( V_11 ) || ! V_57 ) {
void * * V_71 = V_57 ? V_57 : ( void * * ) V_51 ;
F_8 ( & V_8 -> V_40 ) ;
for ( V_67 = 0 ; V_67 < V_47 ; V_67 ++ )
if ( V_51 [ V_67 ] == NULL )
V_71 [ V_67 ] = ( void * ) V_72 ;
else
V_71 [ V_67 ] = F_9 ( V_51 [ V_67 ] ) ;
F_23 ( V_47 , V_48 , V_49 , V_50 , V_71 ) ;
F_24 ( V_8 ) ;
return NULL ;
}
V_69 = 0 ;
for ( V_67 = 0 ; V_67 < V_47 - 2 && V_69 < 4 ; V_67 ++ )
if ( V_51 [ V_67 ] )
V_69 ++ ;
switch ( V_69 ) {
case 0 :
case 1 :
F_25 () ;
case 2 :
return F_11 ( V_47 , V_48 , V_49 , V_50 , V_51 , V_8 ) ;
case 3 :
return F_14 ( V_47 , V_48 , V_49 , V_50 , V_51 , V_8 ) ;
default:
return F_17 ( V_47 , V_48 , V_49 , V_50 , V_51 , V_8 ) ;
}
}
struct V_1 *
F_26 ( int V_47 , T_1 V_48 , int V_49 ,
struct V_2 * * V_51 , struct V_7 * V_8 )
{
struct V_1 * V_27 = NULL ;
struct V_2 * V_52 , * V_53 , * V_64 ;
T_2 V_5 ;
enum V_54 V_31 = V_8 -> V_31 ;
T_4 V_55 = V_8 -> V_55 ;
void * V_56 = V_8 -> V_56 ;
void * V_57 = V_8 -> V_57 ;
int V_65 , V_66 , V_67 ;
struct V_2 * V_4 [ 2 ] ;
F_21 ( L_1 , V_70 , V_47 , V_48 ) ;
if ( ! F_22 ( V_11 ) || ! V_57 ) {
void * * V_71 = V_57 ? V_57 : ( void * * ) V_51 ;
F_8 ( & V_8 -> V_40 ) ;
for ( V_67 = 0 ; V_67 < V_47 ; V_67 ++ )
if ( V_51 [ V_67 ] == NULL )
V_71 [ V_67 ] = ( void * ) V_72 ;
else
V_71 [ V_67 ] = F_9 ( V_51 [ V_67 ] ) ;
F_27 ( V_47 , V_48 , V_49 , V_71 ) ;
F_24 ( V_8 ) ;
return NULL ;
}
V_65 = 0 ;
V_66 = - 1 ;
for ( V_67 = 0 ; V_67 < V_47 - 2 ; V_67 ++ ) {
if ( V_67 == V_49 )
continue;
if ( V_51 [ V_67 ] ) {
V_66 = V_67 ;
V_65 ++ ;
if ( V_65 > 1 )
break;
}
}
F_15 ( V_65 == 0 ) ;
V_52 = V_51 [ V_47 - 2 ] ;
V_53 = V_51 [ V_47 - 1 ] ;
V_64 = V_51 [ V_49 ] ;
V_51 [ V_49 ] = NULL ;
V_51 [ V_47 - 1 ] = V_64 ;
if ( V_65 == 1 ) {
struct V_2 * V_62 = V_51 [ V_66 ] ;
F_12 ( V_8 , V_32 , V_27 , NULL , NULL ,
V_57 ) ;
V_27 = F_16 ( V_52 , V_62 , 0 , 0 , V_48 , V_8 ) ;
F_12 ( V_8 , V_32 , V_27 , NULL , NULL ,
V_57 ) ;
V_27 = F_10 ( V_64 , V_62 , V_60 [ V_66 ] , V_48 , V_8 ) ;
} else {
F_12 ( V_8 , V_32 , V_27 , NULL , NULL ,
V_57 ) ;
V_27 = F_18 ( V_51 , 0 , V_47 , V_48 , V_8 ) ;
}
V_51 [ V_49 ] = V_64 ;
V_51 [ V_47 - 1 ] = V_53 ;
V_5 = V_59 [ V_60 [ V_49 ] ] ;
V_4 [ 0 ] = V_64 ;
V_4 [ 1 ] = V_53 ;
F_12 ( V_8 , V_32 | V_68 , V_27 ,
NULL , NULL , V_57 ) ;
V_27 = F_13 ( V_64 , V_4 , 0 , 2 , V_48 , V_8 ) ;
F_12 ( V_8 , V_32 , V_27 , NULL , NULL , V_57 ) ;
V_27 = F_10 ( V_64 , V_64 , V_5 , V_48 , V_8 ) ;
V_4 [ 0 ] = V_52 ;
V_4 [ 1 ] = V_64 ;
F_12 ( V_8 , V_31 | V_68 , V_27 , V_55 ,
V_56 , V_57 ) ;
V_27 = F_13 ( V_52 , V_4 , 0 , 2 , V_48 , V_8 ) ;
return V_27 ;
}
