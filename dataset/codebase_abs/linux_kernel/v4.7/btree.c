static int
F_1 ( struct V_1 * V_2 , const T_1 * V_3 ,
T_2 * V_4 )
{
struct V_5 * V_6 ;
T_3 * V_7 ;
F_2 ( V_2 , L_1 , V_8 ) ;
V_6 = F_3 ( V_2 , V_3 , 0 , NULL ) ;
if ( ! V_6 ) {
F_4 ( V_2 , L_2 ) ;
goto error;
}
V_7 = ( T_3 * ) V_6 -> V_9 ;
F_5 ( V_2 , V_7 ) ;
V_4 -> V_10 = F_6 ( V_2 , V_7 -> V_10 ) ;
V_4 -> V_11 = F_6 ( V_2 , V_7 -> V_11 ) ;
V_4 -> V_12 = F_6 ( V_2 , V_7 -> V_12 ) ;
V_4 -> V_13 = F_6 ( V_2 , V_7 -> V_13 ) ;
V_4 -> V_14 = F_7 ( V_2 , V_7 -> V_14 ) ;
V_4 -> V_15 = F_7 ( V_2 , V_7 -> V_15 ) ;
V_4 -> V_16 = F_7 ( V_2 , V_7 -> V_16 ) ;
F_8 ( V_6 ) ;
if ( V_4 -> V_10 != V_17 ) {
F_4 ( V_2 , L_3 ) ;
goto error;
}
F_2 ( V_2 , L_4 , V_8 ) ;
return V_18 ;
error:
F_2 ( V_2 , L_5 , V_8 ) ;
return V_19 ;
}
static int
F_9 ( struct V_1 * V_2 , const T_1 * V_3 ,
struct V_20 * V_21 , T_4 V_22 )
{
T_5 V_23 = 0 ;
F_2 ( V_2 , L_1 , V_8 ) ;
if ( V_21 -> V_6 )
F_8 ( V_21 -> V_6 ) ;
V_21 -> V_6 = F_3 ( V_2 , V_3 , V_22 , & V_23 ) ;
if ( ! V_21 -> V_6 ) {
F_4 ( V_2 , L_6
L_7 , V_8 , V_22 ) ;
F_2 ( V_2 , L_5 , V_8 ) ;
return V_19 ;
}
V_21 -> V_24 =
( V_25 * ) ( ( void * ) V_21 -> V_6 -> V_9 + V_23 ) ;
F_10 ( V_2 , V_21 -> V_24 ) ;
V_21 -> V_26 . V_27 = F_7 ( V_2 , V_21 -> V_24 -> V_27 ) ;
V_21 -> V_26 . V_28 = F_7 ( V_2 , V_21 -> V_24 -> V_28 ) ;
V_21 -> V_26 . V_29 = F_7 ( V_2 , V_21 -> V_24 -> V_29 ) ;
V_21 -> V_26 . V_30 =
F_11 ( V_2 , V_21 -> V_24 -> V_30 ) ;
V_21 -> V_26 . V_31 =
F_11 ( V_2 , V_21 -> V_24 -> V_31 ) ;
F_2 ( V_2 , L_4 , V_8 ) ;
return V_18 ;
}
int
F_12 ( struct V_1 * V_2 , const T_1 * V_3 ,
const char * V_32 , T_4 * V_33 )
{
struct V_20 * V_34 ;
T_2 V_35 ;
T_4 V_22 ;
int V_36 ;
F_2 ( V_2 , L_8 , V_8 , V_32 ) ;
if ( F_1 ( V_2 , V_3 , & V_35 ) != V_18 ) {
F_4 ( V_2 ,
L_9 ) ;
goto error;
}
V_34 = F_13 ( sizeof( struct V_20 ) ,
V_37 ) ;
if ( ! V_34 ) {
F_4 ( V_2 , L_10
L_11 , sizeof( struct V_20 ) ) ;
goto error;
}
V_34 -> V_6 = NULL ;
V_22 = V_35 . V_14 ;
if ( F_9 ( V_2 , V_3 , V_34 , V_22 ) != V_18 ) {
F_4 ( V_2 , L_12
L_7 , V_22 ) ;
goto V_38;
}
while ( ! F_14 ( V_34 ) ) {
V_36 = F_15 ( V_2 , V_34 , V_32 , & V_22 ) ;
if ( V_36 == V_39 )
V_22 = V_34 -> V_26 . V_29 ;
if ( F_9 ( V_2 , V_3 , V_34 , V_22 ) != V_18 ) {
F_4 ( V_2 , L_12
L_7 , V_22 ) ;
goto V_38;
}
}
V_36 = F_15 ( V_2 , V_34 , V_32 , V_33 ) ;
F_8 ( V_34 -> V_6 ) ;
F_16 ( V_34 ) ;
if ( V_36 != V_40 ) {
F_2 ( V_2 , L_13 , V_8 , V_32 ) ;
* V_33 = 0 ;
return V_39 ;
}
F_2 ( V_2 , L_14 , V_8 ,
V_32 , * V_33 ) ;
return V_18 ;
V_38:
F_16 ( V_34 ) ;
error:
* V_33 = 0 ;
F_2 ( V_2 , L_5 , V_8 ) ;
return V_19 ;
}
static int
F_15 ( struct V_1 * V_2 , struct V_20 * V_21 ,
const char * V_41 , T_4 * V_33 )
{
int V_42 , V_43 , V_44 ;
int V_45 ;
T_6 V_46 ;
int V_47 ;
char * V_48 ;
T_7 * V_49 ;
F_2 ( V_2 , L_15 , V_8 , V_41 ) ;
* V_33 = 0 ;
V_47 = strlen ( V_41 ) ;
V_43 = V_21 -> V_26 . V_30 - 1 ;
V_48 = F_17 ( V_2 , V_21 , V_43 , & V_46 ) ;
V_45 = F_18 ( V_48 , V_46 , V_41 , V_47 ) ;
if ( V_45 < 0 ) {
F_2 ( V_2 , L_16 , V_8 , V_41 ) ;
return V_39 ;
}
V_49 = F_19 ( V_21 ) ;
V_42 = 0 ;
V_44 = 0 ;
while ( V_43 >= V_42 ) {
V_44 = ( V_43 + V_42 ) / 2 ;
F_2 ( V_2 , L_17 , V_42 , V_43 ,
V_44 ) ;
V_48 = F_17 ( V_2 , V_21 , V_44 , & V_46 ) ;
V_45 = F_18 ( V_48 , V_46 , V_41 ,
V_47 ) ;
if ( V_45 == 0 ) {
F_2 ( V_2 , L_18 ,
V_8 , V_48 , V_44 ) ;
* V_33 = F_7 ( V_2 , V_49 [ V_44 ] ) ;
return V_40 ;
}
if ( V_45 > 0 )
V_43 = V_44 - 1 ;
else
V_42 = V_44 + 1 ;
}
if ( V_45 < 0 )
* V_33 = F_7 ( V_2 , V_49 [ V_44 + 1 ] ) ;
else
* V_33 = F_7 ( V_2 , V_49 [ V_44 ] ) ;
F_2 ( V_2 , L_18 , V_8 , V_48 , V_44 ) ;
return V_50 ;
}
int
F_20 ( struct V_1 * V_2 , const T_1 * V_3 ,
T_8 V_51 , T_9 V_52 , char * V_53 , T_9 * V_54 ,
T_4 * V_33 )
{
struct V_20 * V_34 ;
T_2 V_35 ;
T_4 V_22 = 0 ;
int V_55 ;
T_7 * V_49 ;
char * V_56 ;
T_6 V_46 ;
int V_36 ;
T_5 V_57 = 0 ;
F_2 ( V_2 , L_1 , V_8 ) ;
if ( F_1 ( V_2 , V_3 , & V_35 ) != V_18 ) {
F_4 ( V_2 ,
L_19 ) ;
goto error;
}
V_34 = F_13 ( sizeof( struct V_20 ) , V_37 ) ;
if ( V_34 == NULL ) {
F_4 ( V_2 , L_20
L_11 , sizeof( struct V_20 ) ) ;
goto error;
}
V_22 = V_35 . V_14 ;
V_34 -> V_6 = NULL ;
V_36 = F_21 ( V_2 , V_3 , & V_35 , V_34 , & V_22 ) ;
if ( V_36 == V_58 ) {
F_8 ( V_34 -> V_6 ) ;
F_16 ( V_34 ) ;
* V_33 = 0 ;
* V_54 = 0 ;
F_2 ( V_2 , L_21 , V_8 ) ;
return V_58 ;
} else if ( V_36 == V_19 ) {
goto V_38;
}
while ( V_57 + V_34 -> V_26 . V_30 <= V_51 ) {
if ( V_34 -> V_26 . V_28 == V_59 ) {
* V_54 = 0 ;
* V_33 = 0 ;
F_2 ( V_2 ,
L_22 , V_8 ,
( unsigned long long )
V_57 + V_34 -> V_26 . V_30 ) ;
F_8 ( V_34 -> V_6 ) ;
F_16 ( V_34 ) ;
return V_60 ;
}
V_57 += V_34 -> V_26 . V_30 ;
V_22 = V_34 -> V_26 . V_28 ;
if ( F_9 ( V_2 , V_3 , V_34 , V_22 ) != V_18 ) {
F_4 ( V_2 , L_23 ,
V_8 , ( unsigned long long ) V_22 ) ;
goto V_38;
}
}
V_55 = V_51 - V_57 ;
V_49 = F_19 ( V_34 ) ;
V_56 = F_17 ( V_2 , V_34 , V_55 , & V_46 ) ;
F_2 ( V_2 , L_24 ,
( long long unsigned int ) V_22 , ( int ) V_55 ,
( int ) V_46 ) ;
if ( V_52 < V_46 + 1 ) {
F_4 ( V_2 , L_25
L_26 , V_8 , V_52 , V_46 ) ;
F_8 ( V_34 -> V_6 ) ;
goto V_38;
}
F_22 ( V_53 , V_56 , V_46 + 1 ) ;
* V_33 = F_7 ( V_2 , V_49 [ V_55 ] ) ;
* V_54 = V_46 ;
F_2 ( V_2 , L_27 , V_22 ,
V_55 , V_46 , V_53 , * V_33 ) ;
F_8 ( V_34 -> V_6 ) ;
F_16 ( V_34 ) ;
F_2 ( V_2 , L_4 , V_8 ) ;
return V_18 ;
V_38:
F_16 ( V_34 ) ;
error:
* V_54 = 0 ;
* V_33 = 0 ;
F_2 ( V_2 , L_5 , V_8 ) ;
return V_19 ;
}
static int
F_21 ( struct V_1 * V_2 , const T_1 * V_3 ,
T_2 * V_35 ,
struct V_20 * V_34 ,
T_4 * V_22 )
{
F_2 ( V_2 , L_1 , V_8 ) ;
if ( F_9 ( V_2 , V_3 , V_34 , * V_22 ) != V_18 ) {
F_4 ( V_2 , L_6
L_7 , V_8 , * V_22 ) ;
goto error;
}
F_2 ( V_2 , L_28 , * V_22 ) ;
if ( V_34 -> V_26 . V_30 == 0 && F_14 ( V_34 ) ) {
F_2 ( V_2 , L_21 , V_8 ) ;
return V_58 ;
}
while ( ! F_14 ( V_34 ) ) {
if ( V_34 -> V_26 . V_30 == 0 ) {
F_2 ( V_2 , L_29
L_30
L_31 , V_8 , * V_22 ,
V_34 -> V_26 . V_29 ) ;
* V_22 = V_34 -> V_26 . V_29 ;
} else {
T_7 * V_49 = F_19 ( V_34 ) ;
* V_22 = F_7 ( V_2 , V_49 [ 0 ] ) ;
}
if ( F_9 ( V_2 , V_3 , V_34 , * V_22 ) != V_18 ) {
F_4 ( V_2 , L_6
L_7 , V_8 , * V_22 ) ;
goto error;
}
F_2 ( V_2 , L_32 , * V_22 ) ;
}
F_2 ( V_2 , L_33 , * V_22 ) ;
return V_18 ;
error:
F_2 ( V_2 , L_5 , V_8 ) ;
return V_19 ;
}
static int
F_14 ( struct V_20 * V_21 )
{
if ( V_21 -> V_26 . V_29 == V_59 )
return 1 ;
else
return 0 ;
}
static T_10 *
F_23 ( struct V_20 * V_21 )
{
const int V_61 = 8 ;
unsigned long int V_23 =
( sizeof ( V_25 ) + V_21 -> V_26 . V_31 ) ;
T_11 V_62 = V_23 % V_61 ;
if ( V_62 )
V_23 += V_61 - V_62 ;
return ( T_10 * ) ( ( void * ) V_21 -> V_24 + V_23 ) ;
}
static T_7 *
F_19 ( struct V_20 * V_21 )
{
void * V_63 = ( void * ) F_23 ( V_21 ) ;
T_9 V_64 = V_21 -> V_26 . V_30 * sizeof ( T_10 ) ;
return ( T_7 * ) ( V_63 + V_64 ) ;
}
static char *
F_24 ( struct V_20 * V_21 )
{
return ( char * ) ( ( void * ) V_21 -> V_24 + sizeof ( V_25 ) ) ;
}
static char *
F_17 ( struct V_1 * V_2 , struct V_20 * V_21 ,
int V_65 , T_6 * V_46 )
{
int V_66 ;
char * V_56 ;
T_10 * V_67 ;
if ( V_65 < 0 || V_65 > V_21 -> V_26 . V_30 ) {
* V_46 = 0 ;
return NULL ;
}
V_56 = F_24 ( V_21 ) ;
V_67 = F_23 ( V_21 ) ;
if ( V_65 == 0 )
V_66 = 0 ;
else
V_66 = F_11 ( V_2 , V_67 [ V_65 - 1 ] ) ;
* V_46 = F_11 ( V_2 , V_67 [ V_65 ] ) - V_66 ;
return V_56 + V_66 ;
}
static int
F_18 ( const void * V_68 , int V_69 ,
const void * V_70 , int V_71 )
{
int V_72 = F_25 ( int , V_69 , V_71 ) ;
int V_73 = strncmp ( V_68 , V_70 , V_72 ) ;
if ( V_73 == 0 )
V_73 = V_69 - V_71 ;
return V_73 ;
}
