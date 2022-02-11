static struct V_1 *
F_1 ( struct V_2 * V_3 , struct V_2 * * V_4 , unsigned char * V_5 ,
T_1 V_6 , struct V_7 * V_8 )
{
struct V_9 * V_10 = F_2 ( V_8 , V_11 ,
& V_3 , 1 , V_4 , 2 , V_6 ) ;
struct V_12 * V_13 = V_10 ? V_10 -> V_14 : NULL ;
const T_2 * V_15 , * V_16 ;
T_2 V_17 , V_18 ;
T_2 * V_19 , * V_20 , * V_21 ;
if ( V_13 ) {
T_3 V_22 [ 2 ] ;
T_3 V_23 [ 2 ] ;
struct V_14 * V_24 = V_13 -> V_24 ;
struct V_1 * V_25 ;
enum V_26 V_27 = V_28 ;
if ( V_8 -> V_29 & V_30 )
V_27 |= V_31 ;
V_22 [ 1 ] = F_3 ( V_24 , V_3 , 0 , V_6 , V_32 ) ;
V_23 [ 0 ] = F_3 ( V_24 , V_4 [ 0 ] , 0 , V_6 , V_33 ) ;
V_23 [ 1 ] = F_3 ( V_24 , V_4 [ 1 ] , 0 , V_6 , V_33 ) ;
V_25 = V_13 -> V_34 ( V_10 , V_22 , V_23 , 2 , V_5 ,
V_6 , V_27 ) ;
if ( V_25 ) {
F_4 ( V_10 , V_25 , V_8 ) ;
return V_25 ;
}
F_5 ( V_24 , V_22 [ 1 ] , V_6 , V_32 ) ;
F_5 ( V_24 , V_23 [ 0 ] , V_6 , V_33 ) ;
F_5 ( V_24 , V_23 [ 1 ] , V_6 , V_33 ) ;
}
F_6 ( & V_8 -> V_35 ) ;
V_15 = V_36 [ V_5 [ 0 ] ] ;
V_16 = V_36 [ V_5 [ 1 ] ] ;
V_19 = F_7 ( V_4 [ 0 ] ) ;
V_20 = F_7 ( V_4 [ 1 ] ) ;
V_21 = F_7 ( V_3 ) ;
while ( V_6 -- ) {
V_17 = V_15 [ * V_19 ++ ] ;
V_18 = V_16 [ * V_20 ++ ] ;
* V_21 ++ = V_17 ^ V_18 ;
}
return NULL ;
}
static struct V_1 *
F_8 ( struct V_2 * V_3 , struct V_2 * V_37 , T_2 V_5 , T_1 V_6 ,
struct V_7 * V_8 )
{
struct V_9 * V_10 = F_2 ( V_8 , V_11 ,
& V_3 , 1 , & V_37 , 1 , V_6 ) ;
struct V_12 * V_13 = V_10 ? V_10 -> V_14 : NULL ;
const T_2 * V_38 ;
T_2 * V_39 , * V_40 ;
if ( V_13 ) {
T_3 V_22 [ 2 ] ;
T_3 V_23 [ 1 ] ;
struct V_14 * V_24 = V_13 -> V_24 ;
struct V_1 * V_25 ;
enum V_26 V_27 = V_28 ;
if ( V_8 -> V_29 & V_30 )
V_27 |= V_31 ;
V_22 [ 1 ] = F_3 ( V_24 , V_3 , 0 , V_6 , V_32 ) ;
V_23 [ 0 ] = F_3 ( V_24 , V_37 , 0 , V_6 , V_33 ) ;
V_25 = V_13 -> V_34 ( V_10 , V_22 , V_23 , 1 , & V_5 ,
V_6 , V_27 ) ;
if ( V_25 ) {
F_4 ( V_10 , V_25 , V_8 ) ;
return V_25 ;
}
F_5 ( V_24 , V_22 [ 1 ] , V_6 , V_32 ) ;
F_5 ( V_24 , V_23 [ 0 ] , V_6 , V_33 ) ;
}
F_6 ( & V_8 -> V_35 ) ;
V_38 = V_36 [ V_5 ] ;
V_39 = F_7 ( V_3 ) ;
V_40 = F_7 ( V_37 ) ;
while ( V_6 -- )
* V_39 ++ = V_38 [ * V_40 ++ ] ;
return NULL ;
}
static struct V_1 *
F_9 ( int V_41 , T_1 V_42 , int V_43 , int V_44 ,
struct V_2 * * V_45 , struct V_7 * V_8 )
{
struct V_1 * V_25 = NULL ;
struct V_2 * V_46 , * V_47 , * V_19 , * V_20 ;
struct V_2 * V_4 [ 2 ] ;
unsigned char V_5 [ 2 ] ;
enum V_48 V_29 = V_8 -> V_29 ;
T_4 V_49 = V_8 -> V_49 ;
void * V_50 = V_8 -> V_50 ;
void * V_51 = V_8 -> V_51 ;
V_46 = V_45 [ V_41 - 2 ] ;
V_47 = V_45 [ V_41 - 1 ] ;
V_19 = V_45 [ V_43 ] ;
V_20 = V_45 [ V_44 ] ;
V_4 [ 0 ] = V_46 ;
V_4 [ 1 ] = V_47 ;
V_5 [ 0 ] = V_52 [ V_44 - V_43 ] ;
V_5 [ 1 ] = V_53 [ V_54 [ V_43 ] ^ V_54 [ V_44 ] ] ;
F_10 ( V_8 , V_30 , V_25 , NULL , NULL , V_51 ) ;
V_25 = F_1 ( V_20 , V_4 , V_5 , V_42 , V_8 ) ;
V_4 [ 0 ] = V_46 ;
V_4 [ 1 ] = V_20 ;
F_10 ( V_8 , V_29 | V_55 , V_25 , V_49 ,
V_50 , V_51 ) ;
V_25 = F_11 ( V_19 , V_4 , 0 , 2 , V_42 , V_8 ) ;
return V_25 ;
}
static struct V_1 *
F_12 ( int V_41 , T_1 V_42 , int V_43 , int V_44 ,
struct V_2 * * V_45 , struct V_7 * V_8 )
{
struct V_1 * V_25 = NULL ;
struct V_2 * V_46 , * V_47 , * V_56 , * V_57 , * V_58 ;
struct V_2 * V_4 [ 2 ] ;
unsigned char V_5 [ 2 ] ;
enum V_48 V_29 = V_8 -> V_29 ;
T_4 V_49 = V_8 -> V_49 ;
void * V_50 = V_8 -> V_50 ;
void * V_51 = V_8 -> V_51 ;
int V_59 , V_60 , V_61 ;
V_59 = 0 ;
V_60 = - 1 ;
for ( V_61 = 0 ; V_61 < V_41 - 2 ; V_61 ++ ) {
if ( V_45 [ V_61 ] == NULL )
continue;
if ( V_61 == V_43 || V_61 == V_44 )
continue;
V_60 = V_61 ;
V_59 ++ ;
}
F_13 ( V_59 > 1 ) ;
V_46 = V_45 [ V_41 - 2 ] ;
V_47 = V_45 [ V_41 - 1 ] ;
V_56 = V_45 [ V_60 ] ;
V_57 = V_45 [ V_43 ] ;
V_58 = V_45 [ V_44 ] ;
F_10 ( V_8 , V_30 , V_25 , NULL , NULL , V_51 ) ;
V_25 = F_14 ( V_57 , V_56 , 0 , 0 , V_42 , V_8 ) ;
F_10 ( V_8 , V_30 , V_25 , NULL , NULL , V_51 ) ;
V_25 = F_8 ( V_58 , V_56 , V_54 [ V_60 ] , V_42 , V_8 ) ;
V_4 [ 0 ] = V_57 ;
V_4 [ 1 ] = V_46 ;
F_10 ( V_8 , V_30 | V_62 , V_25 ,
NULL , NULL , V_51 ) ;
V_25 = F_11 ( V_57 , V_4 , 0 , 2 , V_42 , V_8 ) ;
V_4 [ 0 ] = V_58 ;
V_4 [ 1 ] = V_47 ;
F_10 ( V_8 , V_30 | V_62 , V_25 ,
NULL , NULL , V_51 ) ;
V_25 = F_11 ( V_58 , V_4 , 0 , 2 , V_42 , V_8 ) ;
V_4 [ 0 ] = V_57 ;
V_4 [ 1 ] = V_58 ;
V_5 [ 0 ] = V_52 [ V_44 - V_43 ] ;
V_5 [ 1 ] = V_53 [ V_54 [ V_43 ] ^ V_54 [ V_44 ] ] ;
F_10 ( V_8 , V_30 , V_25 , NULL , NULL , V_51 ) ;
V_25 = F_1 ( V_58 , V_4 , V_5 , V_42 , V_8 ) ;
V_4 [ 0 ] = V_57 ;
V_4 [ 1 ] = V_58 ;
F_10 ( V_8 , V_29 | V_62 , V_25 , V_49 ,
V_50 , V_51 ) ;
V_25 = F_11 ( V_57 , V_4 , 0 , 2 , V_42 , V_8 ) ;
return V_25 ;
}
static struct V_1 *
F_15 ( int V_41 , T_1 V_42 , int V_43 , int V_44 ,
struct V_2 * * V_45 , struct V_7 * V_8 )
{
struct V_1 * V_25 = NULL ;
struct V_2 * V_46 , * V_47 , * V_57 , * V_58 ;
struct V_2 * V_4 [ 2 ] ;
unsigned char V_5 [ 2 ] ;
enum V_48 V_29 = V_8 -> V_29 ;
T_4 V_49 = V_8 -> V_49 ;
void * V_50 = V_8 -> V_50 ;
void * V_51 = V_8 -> V_51 ;
V_46 = V_45 [ V_41 - 2 ] ;
V_47 = V_45 [ V_41 - 1 ] ;
V_57 = V_45 [ V_43 ] ;
V_45 [ V_43 ] = NULL ;
V_45 [ V_41 - 2 ] = V_57 ;
V_58 = V_45 [ V_44 ] ;
V_45 [ V_44 ] = NULL ;
V_45 [ V_41 - 1 ] = V_58 ;
F_10 ( V_8 , V_30 , V_25 , NULL , NULL , V_51 ) ;
V_25 = F_16 ( V_45 , 0 , V_41 , V_42 , V_8 ) ;
V_45 [ V_43 ] = V_57 ;
V_45 [ V_44 ] = V_58 ;
V_45 [ V_41 - 2 ] = V_46 ;
V_45 [ V_41 - 1 ] = V_47 ;
V_4 [ 0 ] = V_57 ;
V_4 [ 1 ] = V_46 ;
F_10 ( V_8 , V_30 | V_62 , V_25 ,
NULL , NULL , V_51 ) ;
V_25 = F_11 ( V_57 , V_4 , 0 , 2 , V_42 , V_8 ) ;
V_4 [ 0 ] = V_58 ;
V_4 [ 1 ] = V_47 ;
F_10 ( V_8 , V_30 | V_62 , V_25 ,
NULL , NULL , V_51 ) ;
V_25 = F_11 ( V_58 , V_4 , 0 , 2 , V_42 , V_8 ) ;
V_4 [ 0 ] = V_57 ;
V_4 [ 1 ] = V_58 ;
V_5 [ 0 ] = V_52 [ V_44 - V_43 ] ;
V_5 [ 1 ] = V_53 [ V_54 [ V_43 ] ^ V_54 [ V_44 ] ] ;
F_10 ( V_8 , V_30 , V_25 , NULL , NULL , V_51 ) ;
V_25 = F_1 ( V_58 , V_4 , V_5 , V_42 , V_8 ) ;
V_4 [ 0 ] = V_57 ;
V_4 [ 1 ] = V_58 ;
F_10 ( V_8 , V_29 | V_62 , V_25 , V_49 ,
V_50 , V_51 ) ;
V_25 = F_11 ( V_57 , V_4 , 0 , 2 , V_42 , V_8 ) ;
return V_25 ;
}
struct V_1 *
F_17 ( int V_41 , T_1 V_42 , int V_43 , int V_44 ,
struct V_2 * * V_45 , struct V_7 * V_8 )
{
void * V_51 = V_8 -> V_51 ;
int V_63 , V_61 ;
F_13 ( V_43 == V_44 ) ;
if ( V_44 < V_43 )
F_18 ( V_43 , V_44 ) ;
F_19 ( L_1 , V_64 , V_41 , V_42 ) ;
if ( ! F_20 ( V_11 ) || ! V_51 ) {
void * * V_65 = V_51 ? V_51 : ( void * * ) V_45 ;
F_6 ( & V_8 -> V_35 ) ;
for ( V_61 = 0 ; V_61 < V_41 ; V_61 ++ )
if ( V_45 [ V_61 ] == NULL )
V_65 [ V_61 ] = ( void * ) V_66 ;
else
V_65 [ V_61 ] = F_7 ( V_45 [ V_61 ] ) ;
F_21 ( V_41 , V_42 , V_43 , V_44 , V_65 ) ;
F_22 ( V_8 ) ;
return NULL ;
}
V_63 = 0 ;
for ( V_61 = 0 ; V_61 < V_41 - 2 && V_63 < 4 ; V_61 ++ )
if ( V_45 [ V_61 ] )
V_63 ++ ;
switch ( V_63 ) {
case 0 :
case 1 :
F_23 () ;
case 2 :
return F_9 ( V_41 , V_42 , V_43 , V_44 , V_45 , V_8 ) ;
case 3 :
return F_12 ( V_41 , V_42 , V_43 , V_44 , V_45 , V_8 ) ;
default:
return F_15 ( V_41 , V_42 , V_43 , V_44 , V_45 , V_8 ) ;
}
}
struct V_1 *
F_24 ( int V_41 , T_1 V_42 , int V_43 ,
struct V_2 * * V_45 , struct V_7 * V_8 )
{
struct V_1 * V_25 = NULL ;
struct V_2 * V_46 , * V_47 , * V_58 ;
T_2 V_5 ;
enum V_48 V_29 = V_8 -> V_29 ;
T_4 V_49 = V_8 -> V_49 ;
void * V_50 = V_8 -> V_50 ;
void * V_51 = V_8 -> V_51 ;
int V_59 , V_60 , V_61 ;
struct V_2 * V_4 [ 2 ] ;
F_19 ( L_1 , V_64 , V_41 , V_42 ) ;
if ( ! F_20 ( V_11 ) || ! V_51 ) {
void * * V_65 = V_51 ? V_51 : ( void * * ) V_45 ;
F_6 ( & V_8 -> V_35 ) ;
for ( V_61 = 0 ; V_61 < V_41 ; V_61 ++ )
if ( V_45 [ V_61 ] == NULL )
V_65 [ V_61 ] = ( void * ) V_66 ;
else
V_65 [ V_61 ] = F_7 ( V_45 [ V_61 ] ) ;
F_25 ( V_41 , V_42 , V_43 , V_65 ) ;
F_22 ( V_8 ) ;
return NULL ;
}
V_59 = 0 ;
V_60 = - 1 ;
for ( V_61 = 0 ; V_61 < V_41 - 2 ; V_61 ++ ) {
if ( V_61 == V_43 )
continue;
if ( V_45 [ V_61 ] ) {
V_60 = V_61 ;
V_59 ++ ;
if ( V_59 > 1 )
break;
}
}
F_13 ( V_59 == 0 ) ;
V_46 = V_45 [ V_41 - 2 ] ;
V_47 = V_45 [ V_41 - 1 ] ;
V_58 = V_45 [ V_43 ] ;
V_45 [ V_43 ] = NULL ;
V_45 [ V_41 - 1 ] = V_58 ;
if ( V_59 == 1 ) {
struct V_2 * V_56 = V_45 [ V_60 ] ;
F_10 ( V_8 , V_30 , V_25 , NULL , NULL ,
V_51 ) ;
V_25 = F_14 ( V_46 , V_56 , 0 , 0 , V_42 , V_8 ) ;
F_10 ( V_8 , V_30 , V_25 , NULL , NULL ,
V_51 ) ;
V_25 = F_8 ( V_58 , V_56 , V_54 [ V_60 ] , V_42 , V_8 ) ;
} else {
F_10 ( V_8 , V_30 , V_25 , NULL , NULL ,
V_51 ) ;
V_25 = F_16 ( V_45 , 0 , V_41 , V_42 , V_8 ) ;
}
V_45 [ V_43 ] = V_58 ;
V_45 [ V_41 - 1 ] = V_47 ;
V_5 = V_53 [ V_54 [ V_43 ] ] ;
V_4 [ 0 ] = V_58 ;
V_4 [ 1 ] = V_47 ;
F_10 ( V_8 , V_30 | V_62 , V_25 ,
NULL , NULL , V_51 ) ;
V_25 = F_11 ( V_58 , V_4 , 0 , 2 , V_42 , V_8 ) ;
F_10 ( V_8 , V_30 , V_25 , NULL , NULL , V_51 ) ;
V_25 = F_8 ( V_58 , V_58 , V_5 , V_42 , V_8 ) ;
V_4 [ 0 ] = V_46 ;
V_4 [ 1 ] = V_58 ;
F_10 ( V_8 , V_29 | V_62 , V_25 , V_49 ,
V_50 , V_51 ) ;
V_25 = F_11 ( V_46 , V_4 , 0 , 2 , V_42 , V_8 ) ;
return V_25 ;
}
