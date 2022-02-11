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
F_8 ( V_6 ) ;
if ( V_4 -> V_10 != V_15 ) {
F_4 ( V_2 , L_3 ) ;
goto error;
}
F_2 ( V_2 , L_4 , V_8 ) ;
return V_16 ;
error:
F_2 ( V_2 , L_5 , V_8 ) ;
return V_17 ;
}
static int
F_9 ( struct V_1 * V_2 , const T_1 * V_3 ,
struct V_18 * V_19 , T_4 V_20 )
{
T_5 V_21 = 0 ;
F_2 ( V_2 , L_1 , V_8 ) ;
if ( V_19 -> V_6 )
F_8 ( V_19 -> V_6 ) ;
V_19 -> V_6 = F_3 ( V_2 , V_3 , V_20 , & V_21 ) ;
if ( ! V_19 -> V_6 ) {
F_4 ( V_2 , L_6
L_7 , V_8 , V_20 ) ;
F_2 ( V_2 , L_5 , V_8 ) ;
return V_17 ;
}
V_19 -> V_22 =
( V_23 * ) ( ( void * ) V_19 -> V_6 -> V_9 + V_21 ) ;
F_10 ( V_2 , V_19 -> V_22 ) ;
V_19 -> V_24 . V_25 = F_7 ( V_2 , V_19 -> V_22 -> V_25 ) ;
V_19 -> V_24 . V_26 = F_7 ( V_2 , V_19 -> V_22 -> V_26 ) ;
V_19 -> V_24 . V_27 = F_7 ( V_2 , V_19 -> V_22 -> V_27 ) ;
V_19 -> V_24 . V_28 =
F_11 ( V_2 , V_19 -> V_22 -> V_28 ) ;
V_19 -> V_24 . V_29 =
F_11 ( V_2 , V_19 -> V_22 -> V_29 ) ;
F_2 ( V_2 , L_4 , V_8 ) ;
return V_16 ;
}
int
F_12 ( struct V_1 * V_2 , const T_1 * V_3 ,
const char * V_30 , T_4 * V_31 )
{
struct V_18 * V_32 ;
T_2 V_33 ;
T_4 V_20 ;
int V_34 ;
F_2 ( V_2 , L_8 , V_8 , V_30 ) ;
if ( F_1 ( V_2 , V_3 , & V_33 ) != V_16 ) {
F_4 ( V_2 ,
L_9 ) ;
goto error;
}
V_32 = F_13 ( sizeof( struct V_18 ) ,
V_35 ) ;
if ( ! V_32 ) {
F_4 ( V_2 , L_10
L_11 , sizeof( struct V_18 ) ) ;
goto error;
}
V_32 -> V_6 = NULL ;
V_20 = V_33 . V_14 ;
if ( F_9 ( V_2 , V_3 , V_32 , V_20 ) != V_16 ) {
F_4 ( V_2 , L_12
L_7 , V_20 ) ;
goto V_36;
}
while ( ! F_14 ( V_32 ) ) {
V_34 = F_15 ( V_2 , V_32 , V_30 , & V_20 ) ;
if ( V_34 == V_37 )
V_20 = V_32 -> V_24 . V_27 ;
if ( F_9 ( V_2 , V_3 , V_32 , V_20 ) != V_16 ) {
F_4 ( V_2 , L_12
L_7 , V_20 ) ;
goto V_36;
}
}
V_34 = F_15 ( V_2 , V_32 , V_30 , V_31 ) ;
F_8 ( V_32 -> V_6 ) ;
F_16 ( V_32 ) ;
if ( V_34 != V_38 ) {
F_4 ( V_2 , L_13 , V_8 , V_30 ) ;
F_2 ( V_2 , L_5 , V_8 ) ;
* V_31 = 0 ;
return V_39 ;
}
F_2 ( V_2 , L_14 , V_8 ,
V_30 , * V_31 ) ;
return V_16 ;
V_36:
F_16 ( V_32 ) ;
error:
* V_31 = 0 ;
F_2 ( V_2 , L_5 , V_8 ) ;
return V_17 ;
}
static int
F_15 ( struct V_1 * V_2 , struct V_18 * V_19 ,
const char * V_40 , T_4 * V_31 )
{
int V_41 , V_42 , V_43 ;
int V_44 ;
T_6 V_45 ;
int V_46 ;
char * V_47 ;
T_7 * V_48 ;
F_2 ( V_2 , L_15 , V_8 , V_40 ) ;
V_46 = strlen ( V_40 ) ;
V_42 = V_19 -> V_24 . V_28 - 1 ;
V_47 = F_17 ( V_2 , V_19 , V_42 , & V_45 ) ;
V_44 = F_18 ( V_47 , V_45 , V_40 , V_46 ) ;
if ( V_44 < 0 ) {
F_2 ( V_2 , L_16 , V_40 ) ;
return V_37 ;
}
V_48 = F_19 ( V_19 ) ;
V_41 = 0 ;
V_43 = 0 ;
while ( V_42 >= V_41 ) {
V_43 = ( V_42 + V_41 ) / 2 ;
F_2 ( V_2 , L_17 , V_41 , V_42 ,
V_43 ) ;
V_47 = F_17 ( V_2 , V_19 , V_43 , & V_45 ) ;
V_44 = F_18 ( V_47 , V_45 , V_40 ,
V_46 ) ;
if ( V_44 == 0 ) {
F_2 ( V_2 , L_18 ,
V_8 , V_47 , V_43 ) ;
* V_31 = F_7 ( V_2 , V_48 [ V_43 ] ) ;
return V_38 ;
}
if ( V_44 > 0 )
V_42 = V_43 - 1 ;
else
V_41 = V_43 + 1 ;
}
if ( V_44 < 0 )
* V_31 = F_7 ( V_2 , V_48 [ V_43 + 1 ] ) ;
else
* V_31 = F_7 ( V_2 , V_48 [ V_43 ] ) ;
F_4 ( V_2 , L_19 , V_8 , V_40 ) ;
F_2 ( V_2 , L_5 , V_8 ) ;
return V_39 ;
}
int
F_20 ( struct V_1 * V_2 , const T_1 * V_3 ,
T_8 V_49 , T_9 V_50 , char * V_51 , T_9 * V_52 ,
T_4 * V_31 )
{
struct V_18 * V_32 ;
T_2 V_33 ;
T_4 V_20 ;
int V_53 ;
T_7 * V_48 ;
char * V_54 ;
T_6 V_45 ;
int V_34 ;
T_5 V_55 = 0 ;
F_2 ( V_2 , L_1 , V_8 ) ;
if ( F_1 ( V_2 , V_3 , & V_33 ) != V_16 ) {
F_4 ( V_2 ,
L_20 ) ;
goto error;
}
V_32 = F_13 ( sizeof( struct V_18 ) , V_35 ) ;
if ( V_32 == NULL ) {
F_4 ( V_2 , L_21
L_11 , sizeof( struct V_18 ) ) ;
goto error;
}
V_20 = V_33 . V_14 ;
V_32 -> V_6 = NULL ;
V_34 = F_21 ( V_2 , V_3 , & V_33 , V_32 , & V_20 ) ;
if ( V_34 == V_56 ) {
F_8 ( V_32 -> V_6 ) ;
F_16 ( V_32 ) ;
* V_31 = 0 ;
* V_52 = 0 ;
F_2 ( V_2 , L_22 , V_8 ) ;
return V_56 ;
} else if ( V_34 == V_17 ) {
goto V_36;
}
while ( V_55 + V_32 -> V_24 . V_28 <= V_49 ) {
if ( V_32 -> V_24 . V_26 == V_57 ) {
* V_52 = 0 ;
* V_31 = 0 ;
F_2 ( V_2 ,
L_23 , V_8 ,
( unsigned long long )
V_55 + V_32 -> V_24 . V_28 ) ;
F_8 ( V_32 -> V_6 ) ;
F_16 ( V_32 ) ;
return V_58 ;
}
V_55 += V_32 -> V_24 . V_28 ;
V_20 = V_32 -> V_24 . V_26 ;
if ( F_9 ( V_2 , V_3 , V_32 , V_20 ) != V_16 ) {
F_4 ( V_2 , L_24 ,
V_8 , ( unsigned long long ) V_20 ) ;
goto V_36;
}
}
V_53 = V_49 - V_55 ;
V_48 = F_19 ( V_32 ) ;
V_54 = F_17 ( V_2 , V_32 , V_53 , & V_45 ) ;
F_2 ( V_2 , L_25 ,
( long long unsigned int ) V_20 , ( int ) V_53 ,
( int ) V_45 ) ;
if ( V_50 < V_45 + 1 ) {
F_4 ( V_2 , L_26
L_27 , V_8 , V_50 , V_45 ) ;
F_8 ( V_32 -> V_6 ) ;
goto V_36;
}
F_22 ( V_51 , V_54 , V_45 + 1 ) ;
* V_31 = F_7 ( V_2 , V_48 [ V_53 ] ) ;
* V_52 = V_45 ;
F_2 ( V_2 , L_28 , V_20 ,
V_53 , V_45 , V_51 , * V_31 ) ;
F_8 ( V_32 -> V_6 ) ;
F_16 ( V_32 ) ;
F_2 ( V_2 , L_4 , V_8 ) ;
return V_16 ;
V_36:
F_16 ( V_32 ) ;
error:
* V_52 = 0 ;
* V_31 = 0 ;
F_2 ( V_2 , L_5 , V_8 ) ;
return V_17 ;
}
static int
F_21 ( struct V_1 * V_2 , const T_1 * V_3 ,
T_2 * V_33 ,
struct V_18 * V_32 ,
T_4 * V_20 )
{
F_2 ( V_2 , L_1 , V_8 ) ;
if ( F_9 ( V_2 , V_3 , V_32 , * V_20 ) != V_16 ) {
F_4 ( V_2 , L_6
L_7 , V_8 , * V_20 ) ;
goto error;
}
F_2 ( V_2 , L_29 , * V_20 ) ;
if ( V_32 -> V_24 . V_28 == 0 && F_14 ( V_32 ) ) {
F_2 ( V_2 , L_22 , V_8 ) ;
return V_56 ;
}
while ( ! F_14 ( V_32 ) ) {
if ( V_32 -> V_24 . V_28 == 0 ) {
F_2 ( V_2 , L_30
L_31
L_32 , V_8 , * V_20 ,
V_32 -> V_24 . V_27 ) ;
* V_20 = V_32 -> V_24 . V_27 ;
} else {
T_7 * V_48 = F_19 ( V_32 ) ;
* V_20 = F_7 ( V_2 , V_48 [ 0 ] ) ;
}
if ( F_9 ( V_2 , V_3 , V_32 , * V_20 ) != V_16 ) {
F_4 ( V_2 , L_6
L_7 , V_8 , * V_20 ) ;
goto error;
}
F_2 ( V_2 , L_33 , * V_20 ) ;
}
F_2 ( V_2 , L_34 , * V_20 ) ;
return V_16 ;
error:
F_2 ( V_2 , L_5 , V_8 ) ;
return V_17 ;
}
static int
F_14 ( struct V_18 * V_19 )
{
if ( V_19 -> V_24 . V_27 == V_57 )
return 1 ;
else
return 0 ;
}
static T_10 *
F_23 ( struct V_18 * V_19 )
{
const int V_59 = 8 ;
unsigned long int V_21 =
( sizeof ( V_23 ) + V_19 -> V_24 . V_29 ) ;
T_11 V_60 = V_21 % V_59 ;
if ( V_60 )
V_21 += V_59 - V_60 ;
return ( T_10 * ) ( ( void * ) V_19 -> V_22 + V_21 ) ;
}
static T_7 *
F_19 ( struct V_18 * V_19 )
{
void * V_61 = ( void * ) F_23 ( V_19 ) ;
T_9 V_62 = V_19 -> V_24 . V_28 * sizeof ( T_10 ) ;
return ( T_7 * ) ( V_61 + V_62 ) ;
}
static char *
F_24 ( struct V_18 * V_19 )
{
return ( char * ) ( ( void * ) V_19 -> V_22 + sizeof ( V_23 ) ) ;
}
static char *
F_17 ( struct V_1 * V_2 , struct V_18 * V_19 ,
int V_63 , T_6 * V_45 )
{
int V_64 ;
char * V_54 ;
T_10 * V_65 ;
if ( V_63 < 0 || V_63 > V_19 -> V_24 . V_28 ) {
* V_45 = 0 ;
return NULL ;
}
V_54 = F_24 ( V_19 ) ;
V_65 = F_23 ( V_19 ) ;
if ( V_63 == 0 )
V_64 = 0 ;
else
V_64 = F_11 ( V_2 , V_65 [ V_63 - 1 ] ) ;
* V_45 = F_11 ( V_2 , V_65 [ V_63 ] ) - V_64 ;
return V_54 + V_64 ;
}
static int
F_18 ( const void * V_66 , int V_67 ,
const void * V_68 , int V_69 )
{
int V_70 = F_25 ( int , V_67 , V_69 ) ;
int V_71 = strncmp ( V_66 , V_68 , V_70 ) ;
if ( V_71 == 0 )
V_71 = V_67 - V_69 ;
return V_71 ;
}
