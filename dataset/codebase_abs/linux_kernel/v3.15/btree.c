static int
F_1 ( struct V_1 * V_2 , T_1 * V_3 ,
T_2 * V_4 )
{
struct V_5 * V_6 = NULL ;
T_3 * V_7 = NULL ;
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
F_9 ( struct V_1 * V_2 , T_1 * V_3 ,
T_4 * V_20 , T_5 V_21 )
{
T_6 V_22 = 0 ;
F_2 ( V_2 , L_1 , V_8 ) ;
if ( V_20 -> V_6 )
F_8 ( V_20 -> V_6 ) ;
V_20 -> V_6 = F_3 ( V_2 , V_3 , V_21 , & V_22 ) ;
if ( ! V_20 -> V_6 ) {
F_4 ( V_2 , L_6
L_7 , V_8 , V_21 ) ;
F_2 ( V_2 , L_5 , V_8 ) ;
return V_19 ;
}
V_20 -> V_23 =
( V_24 * ) ( ( void * ) V_20 -> V_6 -> V_9 + V_22 ) ;
F_10 ( V_2 , V_20 -> V_23 ) ;
V_20 -> V_25 . V_26 = F_7 ( V_2 , V_20 -> V_23 -> V_26 ) ;
V_20 -> V_25 . V_27 = F_7 ( V_2 , V_20 -> V_23 -> V_27 ) ;
V_20 -> V_25 . V_28 = F_7 ( V_2 , V_20 -> V_23 -> V_28 ) ;
V_20 -> V_25 . V_29 =
F_11 ( V_2 , V_20 -> V_23 -> V_29 ) ;
V_20 -> V_25 . V_30 =
F_11 ( V_2 , V_20 -> V_23 -> V_30 ) ;
F_2 ( V_2 , L_4 , V_8 ) ;
return V_18 ;
}
int
F_12 ( struct V_1 * V_2 , T_1 * V_3 ,
const char * V_31 , T_5 * V_32 )
{
T_4 * V_33 = NULL ;
T_2 V_34 ;
T_5 V_21 ;
int V_35 ;
F_2 ( V_2 , L_8 , V_8 , V_31 ) ;
if ( F_1 ( V_2 , V_3 , & V_34 ) != V_18 ) {
F_4 ( V_2 ,
L_9 ) ;
goto error;
}
V_33 = F_13 ( sizeof ( T_4 ) ,
V_36 ) ;
if ( ! V_33 ) {
F_4 ( V_2 , L_10
L_11 , sizeof ( T_4 ) ) ;
goto error;
}
V_33 -> V_6 = NULL ;
V_21 = V_34 . V_14 ;
if ( F_9 ( V_2 , V_3 , V_33 , V_21 ) != V_18 ) {
F_4 ( V_2 , L_12
L_7 , V_21 ) ;
goto V_37;
}
while ( ! F_14 ( V_33 ) ) {
V_35 = F_15 ( V_2 , V_33 , V_31 , & V_21 ) ;
if ( V_35 == V_38 )
V_21 = V_33 -> V_25 . V_28 ;
if ( F_9 ( V_2 , V_3 , V_33 , V_21 ) != V_18 ) {
F_4 ( V_2 , L_12
L_7 , V_21 ) ;
goto V_37;
}
}
V_35 = F_15 ( V_2 , V_33 , V_31 , V_32 ) ;
F_8 ( V_33 -> V_6 ) ;
F_16 ( V_33 ) ;
if ( V_35 != V_39 ) {
F_2 ( V_2 , L_13 , V_8 , V_31 ) ;
* V_32 = 0 ;
return V_38 ;
}
F_2 ( V_2 , L_14 , V_8 ,
V_31 , * V_32 ) ;
return V_18 ;
V_37:
F_16 ( V_33 ) ;
error:
* V_32 = 0 ;
F_2 ( V_2 , L_5 , V_8 ) ;
return V_19 ;
}
static int
F_15 ( struct V_1 * V_2 , T_4 * V_20 ,
const char * V_40 , T_5 * V_32 )
{
int V_41 , V_42 , V_43 ;
int V_44 ;
T_7 V_45 ;
int V_46 ;
char * V_47 ;
T_8 * V_48 ;
F_2 ( V_2 , L_15 , V_8 , V_40 ) ;
* V_32 = 0 ;
V_46 = strlen ( V_40 ) ;
V_42 = V_20 -> V_25 . V_29 - 1 ;
V_47 = F_17 ( V_2 , V_20 , V_42 , & V_45 ) ;
V_44 = F_18 ( V_47 , V_45 , V_40 , V_46 ) ;
if ( V_44 < 0 ) {
F_2 ( V_2 , L_16 , V_8 , V_40 ) ;
return V_38 ;
}
V_48 = F_19 ( V_20 ) ;
V_41 = 0 ;
V_43 = 0 ;
while ( V_42 >= V_41 ) {
V_43 = ( V_42 + V_41 ) / 2 ;
F_2 ( V_2 , L_17 , V_41 , V_42 ,
V_43 ) ;
V_47 = F_17 ( V_2 , V_20 , V_43 , & V_45 ) ;
V_44 = F_18 ( V_47 , V_45 , V_40 ,
V_46 ) ;
if ( V_44 == 0 ) {
F_2 ( V_2 , L_18 ,
V_8 , V_47 , V_43 ) ;
* V_32 = F_7 ( V_2 , V_48 [ V_43 ] ) ;
return V_39 ;
}
if ( V_44 > 0 )
V_42 = V_43 - 1 ;
else
V_41 = V_43 + 1 ;
}
if ( V_44 < 0 )
* V_32 = F_7 ( V_2 , V_48 [ V_43 + 1 ] ) ;
else
* V_32 = F_7 ( V_2 , V_48 [ V_43 ] ) ;
F_2 ( V_2 , L_18 , V_8 , V_47 , V_43 ) ;
return V_49 ;
}
int
F_20 ( struct V_1 * V_2 , T_1 * V_3 ,
T_9 V_50 , T_10 V_51 , char * V_52 , T_10 * V_53 ,
T_5 * V_32 )
{
T_4 * V_33 ;
T_2 V_34 ;
T_5 V_21 = 0 ;
int V_54 ;
T_8 * V_48 ;
char * V_55 ;
T_7 V_45 ;
int V_35 ;
T_6 V_56 = 0 ;
F_2 ( V_2 , L_1 , V_8 ) ;
if ( F_1 ( V_2 , V_3 , & V_34 ) != V_18 ) {
F_4 ( V_2 ,
L_19 ) ;
goto error;
}
if ( ( V_33 = F_13 ( sizeof ( T_4 ) , V_36 ) ) == NULL ) {
F_4 ( V_2 , L_20
L_11 , sizeof ( T_4 ) ) ;
goto error;
}
V_21 = V_34 . V_14 ;
V_33 -> V_6 = NULL ;
V_35 = F_21 ( V_2 , V_3 , & V_34 , V_33 , & V_21 ) ;
if ( V_35 == V_57 ) {
F_8 ( V_33 -> V_6 ) ;
F_16 ( V_33 ) ;
* V_32 = 0 ;
* V_53 = 0 ;
F_2 ( V_2 , L_21 , V_8 ) ;
return V_57 ;
} else if ( V_35 == V_19 ) {
goto V_37;
}
while ( V_56 + V_33 -> V_25 . V_29 <= V_50 ) {
if ( V_33 -> V_25 . V_27 == V_58 ) {
* V_53 = 0 ;
* V_32 = 0 ;
F_2 ( V_2 ,
L_22 , V_8 ,
( unsigned long long )
V_56 + V_33 -> V_25 . V_29 ) ;
F_8 ( V_33 -> V_6 ) ;
F_16 ( V_33 ) ;
return V_59 ;
}
V_56 += V_33 -> V_25 . V_29 ;
V_21 = V_33 -> V_25 . V_27 ;
if ( F_9 ( V_2 , V_3 , V_33 , V_21 ) != V_18 ) {
F_4 ( V_2 , L_23 ,
V_8 , ( unsigned long long ) V_21 ) ;
goto V_37;
}
}
V_54 = V_50 - V_56 ;
V_48 = F_19 ( V_33 ) ;
V_55 = F_17 ( V_2 , V_33 , V_54 , & V_45 ) ;
F_2 ( V_2 , L_24 ,
( long long unsigned int ) V_21 , ( int ) V_54 ,
( int ) V_45 ) ;
if ( V_51 < V_45 + 1 ) {
F_4 ( V_2 , L_25
L_26 , V_8 , V_51 , V_45 ) ;
F_8 ( V_33 -> V_6 ) ;
goto V_37;
} ;
strncpy ( V_52 , V_55 , V_45 ) ;
* V_32 = F_7 ( V_2 , V_48 [ V_54 ] ) ;
* V_53 = V_45 ;
V_52 [ V_45 ] = '\0' ;
F_2 ( V_2 , L_27 , V_21 ,
V_54 , V_45 , V_52 , * V_32 ) ;
F_8 ( V_33 -> V_6 ) ;
F_16 ( V_33 ) ;
F_2 ( V_2 , L_4 , V_8 ) ;
return V_18 ;
V_37:
F_16 ( V_33 ) ;
error:
* V_53 = 0 ;
* V_32 = 0 ;
F_2 ( V_2 , L_5 , V_8 ) ;
return V_19 ;
}
static int
F_21 ( struct V_1 * V_2 , T_1 * V_3 ,
T_2 * V_34 , T_4 * V_33 ,
T_5 * V_21 )
{
F_2 ( V_2 , L_1 , V_8 ) ;
if ( F_9 ( V_2 , V_3 , V_33 , * V_21 ) != V_18 ) {
F_4 ( V_2 , L_6
L_7 , V_8 , * V_21 ) ;
goto error;
}
F_2 ( V_2 , L_28 , * V_21 ) ;
if ( V_33 -> V_25 . V_29 == 0 && F_14 ( V_33 ) ) {
F_2 ( V_2 , L_21 , V_8 ) ;
return V_57 ;
}
while ( ! F_14 ( V_33 ) ) {
if ( V_33 -> V_25 . V_29 == 0 ) {
F_2 ( V_2 , L_29
L_30
L_31 , V_8 , * V_21 ,
V_33 -> V_25 . V_28 ) ;
* V_21 = V_33 -> V_25 . V_28 ;
} else {
T_8 * V_48 = F_19 ( V_33 ) ;
* V_21 = F_7 ( V_2 , V_48 [ 0 ] ) ;
}
if ( F_9 ( V_2 , V_3 , V_33 , * V_21 ) != V_18 ) {
F_4 ( V_2 , L_6
L_7 , V_8 , * V_21 ) ;
goto error;
}
F_2 ( V_2 , L_32 , * V_21 ) ;
}
F_2 ( V_2 , L_33 , * V_21 ) ;
return V_18 ;
error:
F_2 ( V_2 , L_5 , V_8 ) ;
return V_19 ;
}
static int
F_14 ( T_4 * V_20 )
{
if ( V_20 -> V_25 . V_28 == V_58 )
return 1 ;
else
return 0 ;
}
static T_11 *
F_22 ( T_4 * V_20 )
{
const int V_60 = 8 ;
unsigned long int V_22 =
( sizeof ( V_24 ) + V_20 -> V_25 . V_30 ) ;
T_12 V_61 = V_22 % V_60 ;
if ( V_61 )
V_22 += V_60 - V_61 ;
return ( T_11 * ) ( ( void * ) V_20 -> V_23 + V_22 ) ;
}
static T_8 *
F_19 ( T_4 * V_20 )
{
void * V_62 = ( void * ) F_22 ( V_20 ) ;
T_10 V_63 = V_20 -> V_25 . V_29 * sizeof ( T_11 ) ;
return ( T_8 * ) ( V_62 + V_63 ) ;
}
static char *
F_23 ( T_4 * V_20 )
{
return ( char * ) ( ( void * ) V_20 -> V_23 + sizeof ( V_24 ) ) ;
}
static char *
F_17 ( struct V_1 * V_2 , T_4 * V_20 ,
int V_64 , T_7 * V_45 )
{
int V_65 ;
char * V_55 ;
T_11 * V_66 ;
if ( V_64 < 0 || V_64 > V_20 -> V_25 . V_29 ) {
* V_45 = 0 ;
return NULL ;
}
V_55 = F_23 ( V_20 ) ;
V_66 = F_22 ( V_20 ) ;
if ( V_64 == 0 )
V_65 = 0 ;
else
V_65 = F_11 ( V_2 , V_66 [ V_64 - 1 ] ) ;
* V_45 = F_11 ( V_2 , V_66 [ V_64 ] ) - V_65 ;
return V_55 + V_65 ;
}
static int
F_18 ( const void * V_67 , int V_68 ,
const void * V_69 , int V_70 )
{
int V_71 = F_24 ( int , V_68 , V_70 ) ;
int V_72 = strncmp ( V_67 , V_69 , V_71 ) ;
if ( V_72 == 0 )
V_72 = V_68 - V_70 ;
return V_72 ;
}
