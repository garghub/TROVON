static int F_1 ( T_1 V_1 , unsigned int V_2 ,
unsigned int V_3 , unsigned int V_4 ,
unsigned int V_5 , int V_6 )
{
if ( ( V_2 > V_3 ) || ( ( V_2 == V_3 ) && ( V_4 > V_5 ) ) ) {
if ( V_6 )
F_2 ( L_1
L_2 , V_2 , V_4 ,
V_3 , V_5 ) ;
return 1 ;
}
while ( ( V_2 < V_3 ) || ( ( V_2 == V_3 ) &&
( V_4 <= V_5 ) ) ) {
if ( V_1 == V_7 )
F_3 ( V_4 , V_8 [ V_2 ] ) ;
else
F_4 ( V_4 , V_8 [ V_2 ] ) ;
V_4 ++ ;
if ( V_4 > V_9 ) {
V_2 ++ ;
V_4 = 0 ;
}
}
return 0 ;
}
static int F_5 ( char * * V_10 , unsigned int * V_11 , int V_12 ,
int V_13 , int V_14 )
{
int V_15 ;
V_15 = 0 ;
* V_11 = 0 ;
while ( V_15 <= V_13 ) {
int V_16 = F_6 ( * * V_10 ) ;
if ( V_16 < 0 )
break;
* V_11 = * V_11 * 16 + V_16 ;
( * V_10 ) ++ ;
V_15 ++ ;
}
if ( ( V_15 < V_12 ) || ( V_15 > V_13 ) || ( * V_11 > V_14 ) )
return 1 ;
return 0 ;
}
static int F_7 ( char * V_17 , unsigned int * V_18 , unsigned int * V_19 ,
unsigned int * V_20 , int V_6 )
{
char * V_21 ;
int V_11 , V_22 , V_23 ;
V_22 = 1 ;
if ( * V_17 == '\0' )
goto V_24;
V_21 = V_17 ;
V_11 = F_8 ( V_17 , & V_21 , 16 ) ;
if ( * V_21 == '\0' ) {
if ( V_11 <= V_9 ) {
* V_20 = V_11 ;
* V_19 = 0 ;
* V_18 = 0 ;
V_22 = 0 ;
}
goto V_24;
}
V_21 = V_17 ;
V_23 = F_5 ( & V_21 , V_18 , 1 , 2 , V_25 ) ;
if ( V_23 || ( V_21 [ 0 ] != '.' ) )
goto V_24;
V_21 ++ ;
V_23 = F_5 ( & V_21 , V_19 , 1 , 1 , V_26 ) ;
if ( V_23 || ( V_21 [ 0 ] != '.' ) )
goto V_24;
V_21 ++ ;
V_23 = F_5 ( & V_21 , V_20 , 4 , 4 , V_9 ) ;
if ( V_23 || ( V_21 [ 0 ] != '\0' ) )
goto V_24;
V_22 = 0 ;
V_24:
if ( V_22 && V_6 )
F_2 ( L_3
L_4 , V_17 ) ;
return V_22 ;
}
static int F_9 ( char * V_17 , T_1 V_1 ,
int V_6 )
{
unsigned int V_27 , V_28 , V_2 , V_3 , V_4 , V_5 ;
int V_22 , V_29 ;
char * V_30 ;
T_1 V_31 ;
V_29 = 0 ;
while ( ( V_30 = F_10 ( & V_17 , L_5 ) ) ) {
V_22 = 0 ;
V_31 = V_1 ;
if ( * V_30 == '!' ) {
if ( V_31 == V_7 )
V_31 = free ;
else
V_31 = V_7 ;
V_30 ++ ;
}
if ( strcmp ( V_30 , L_6 ) == 0 ) {
V_27 = 0 ;
V_2 = 0 ;
V_4 = 0 ;
V_28 = V_25 ;
V_3 = V_26 ;
V_5 = V_9 ;
} else {
V_22 = F_7 ( F_10 ( & V_30 , L_7 ) , & V_27 ,
& V_2 , & V_4 , V_6 ) ;
if ( ! V_22 ) {
if ( V_30 != NULL )
V_22 = F_7 ( V_30 , & V_28 ,
& V_3 , & V_5 ,
V_6 ) ;
else {
V_28 = V_27 ;
V_3 = V_2 ;
V_5 = V_4 ;
}
}
}
if ( ! V_22 ) {
V_22 = F_1 ( V_31 , V_2 , V_3 , V_4 , V_5 ,
V_6 ) ;
if ( V_22 )
V_29 = - V_32 ;
} else
V_29 = - V_32 ;
}
return V_29 ;
}
static int T_2
F_11 ( char * V_17 )
{
F_12 ( 6 , L_8 ) ;
if ( F_9 ( V_17 , V_7 , 1 ) )
return 0 ;
return 1 ;
}
int
F_13 ( int V_19 , int V_20 )
{
return F_14 ( V_20 , V_8 [ V_19 ] ) ;
}
static int F_15 ( char * V_33 )
{
int V_22 ;
char * V_30 ;
V_30 = F_10 ( & V_33 , L_9 ) ;
if ( strcmp ( L_10 , V_30 ) == 0 )
V_22 = F_9 ( V_33 , free , 0 ) ;
else if ( strcmp ( L_11 , V_30 ) == 0 )
V_22 = F_9 ( V_33 , V_7 , 0 ) ;
else if ( strcmp ( L_12 , V_30 ) == 0 )
return F_16 () ;
else
return - V_32 ;
F_17 () ;
return V_22 ;
}
static void *
F_18 ( struct V_34 * V_35 , T_3 * V_36 )
{
struct V_37 * V_38 = V_35 -> V_39 ;
if ( * V_36 >= ( V_9 + 1 ) * ( V_26 + 1 ) )
return NULL ;
memset ( V_38 , 0 , sizeof( * V_38 ) ) ;
V_38 -> V_19 = * V_36 / ( V_9 + 1 ) ;
V_38 -> V_20 = * V_36 % ( V_9 + 1 ) ;
return V_38 ;
}
static void
F_19 ( struct V_34 * V_35 , void * V_40 )
{
}
static void *
F_20 ( struct V_34 * V_35 , void * V_40 , T_3 * V_36 )
{
struct V_37 * V_38 ;
if ( * V_36 >= ( V_9 + 1 ) * ( V_26 + 1 ) )
return NULL ;
V_38 = V_40 ;
if ( V_38 -> V_20 == V_9 ) {
V_38 -> V_20 = 0 ;
V_38 -> V_19 ++ ;
if ( V_38 -> V_19 > V_26 )
return NULL ;
} else
V_38 -> V_20 ++ ;
( * V_36 ) ++ ;
return V_38 ;
}
static int
F_21 ( struct V_34 * V_35 , void * V_40 )
{
struct V_37 * V_38 ;
V_38 = V_40 ;
if ( ! F_13 ( V_38 -> V_19 , V_38 -> V_20 ) )
return 0 ;
if ( ! V_38 -> V_41 ) {
if ( ( V_38 -> V_20 == V_9 ) ||
! F_13 ( V_38 -> V_19 , V_38 -> V_20 + 1 ) )
return F_22 ( V_35 , L_13 ,
V_38 -> V_19 , V_38 -> V_20 ) ;
V_38 -> V_41 = 1 ;
return F_22 ( V_35 , L_14 , V_38 -> V_19 , V_38 -> V_20 ) ;
}
if ( ( V_38 -> V_20 == V_9 ) ||
! F_13 ( V_38 -> V_19 , V_38 -> V_20 + 1 ) ) {
V_38 -> V_41 = 0 ;
return F_22 ( V_35 , L_13 , V_38 -> V_19 , V_38 -> V_20 ) ;
}
return 0 ;
}
static T_4
F_23 ( struct V_42 * V_42 , const char T_5 * V_43 ,
T_6 V_44 , T_3 * V_36 )
{
char * V_33 ;
T_4 V_22 , V_23 , V_45 ;
if ( * V_36 )
return - V_32 ;
if ( V_44 > 65536 )
V_44 = 65536 ;
V_33 = F_24 ( V_44 + 1 ) ;
if ( V_33 == NULL )
return - V_46 ;
memset ( V_33 , 0 , V_44 + 1 ) ;
if ( F_25 ( V_33 , V_43 , V_44 ) < 0 ) {
V_22 = - V_47 ;
goto V_48;
}
V_45 = V_44 - 1 ;
while ( ( V_45 >= 0 ) && ( isspace ( V_33 [ V_45 ] ) || ( V_33 [ V_45 ] == 0 ) ) ) {
V_33 [ V_45 ] = '\0' ;
V_45 -- ;
}
V_23 = F_15 ( V_33 ) ;
if ( V_23 )
V_22 = V_23 ;
else
V_22 = V_44 ;
V_48:
F_26 ( V_33 ) ;
return V_22 ;
}
static int
F_27 ( struct V_49 * V_49 , struct V_42 * V_42 )
{
return F_28 ( V_42 , & V_50 ,
sizeof( struct V_37 ) ) ;
}
static int
F_29 ( void )
{
struct V_51 * V_52 ;
V_52 = F_30 ( L_15 , V_53 | V_54 | V_55 , NULL ,
& V_56 ) ;
if ( ! V_52 )
return - V_57 ;
return 0 ;
}
