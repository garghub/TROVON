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
} else if ( strcmp ( V_30 , L_7 ) == 0 ) {
if ( V_32 . type == V_33 ) {
V_27 = 0 ;
V_2 = V_32 . V_34 . V_35 . V_36 . V_19 ;
V_4 = V_32 . V_34 . V_35 . V_36 . V_20 ;
} else if ( V_32 . type == V_37 ||
V_32 . type == V_38 ) {
V_27 = 0 ;
V_2 = V_32 . V_34 . V_39 . V_36 . V_19 ;
V_4 = V_32 . V_34 . V_39 . V_36 . V_20 ;
} else {
continue;
}
V_28 = V_27 ;
V_3 = V_2 ;
V_5 = V_4 ;
} else if ( strcmp ( V_30 , L_8 ) == 0 ) {
if ( V_40 == - 1 )
continue;
V_27 = V_28 = 0 ;
V_2 = V_3 = 0 ;
V_4 = V_5 = V_40 ;
} else {
V_22 = F_7 ( F_10 ( & V_30 , L_9 ) , & V_27 ,
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
V_29 = - V_41 ;
} else
V_29 = - V_41 ;
}
return V_29 ;
}
static int T_2
F_11 ( char * V_17 )
{
F_12 ( 6 , L_10 ) ;
if ( F_9 ( V_17 , V_7 , 1 ) )
return 0 ;
return 1 ;
}
int
F_13 ( int V_19 , int V_20 )
{
return F_14 ( V_20 , V_8 [ V_19 ] ) ;
}
static int F_15 ( char * V_42 )
{
int V_22 ;
char * V_30 ;
V_30 = F_10 ( & V_42 , L_11 ) ;
if ( strcmp ( L_12 , V_30 ) == 0 ) {
V_22 = F_9 ( V_42 , free , 0 ) ;
F_16 ( 0 ) ;
} else if ( strcmp ( L_13 , V_30 ) == 0 )
V_22 = F_9 ( V_42 , V_7 , 0 ) ;
else if ( strcmp ( L_14 , V_30 ) == 0 )
return F_17 () ;
else
return - V_41 ;
return V_22 ;
}
static void *
F_18 ( struct V_43 * V_44 , T_3 * V_45 )
{
struct V_46 * V_47 = V_44 -> V_48 ;
if ( * V_45 >= ( V_9 + 1 ) * ( V_26 + 1 ) )
return NULL ;
memset ( V_47 , 0 , sizeof( * V_47 ) ) ;
V_47 -> V_19 = * V_45 / ( V_9 + 1 ) ;
V_47 -> V_20 = * V_45 % ( V_9 + 1 ) ;
return V_47 ;
}
static void
F_19 ( struct V_43 * V_44 , void * V_49 )
{
}
static void *
F_20 ( struct V_43 * V_44 , void * V_49 , T_3 * V_45 )
{
struct V_46 * V_47 ;
if ( * V_45 >= ( V_9 + 1 ) * ( V_26 + 1 ) )
return NULL ;
V_47 = V_49 ;
if ( V_47 -> V_20 == V_9 ) {
V_47 -> V_20 = 0 ;
V_47 -> V_19 ++ ;
if ( V_47 -> V_19 > V_26 )
return NULL ;
} else
V_47 -> V_20 ++ ;
( * V_45 ) ++ ;
return V_47 ;
}
static int
F_21 ( struct V_43 * V_44 , void * V_49 )
{
struct V_46 * V_47 ;
V_47 = V_49 ;
if ( ! F_13 ( V_47 -> V_19 , V_47 -> V_20 ) )
return 0 ;
if ( ! V_47 -> V_50 ) {
if ( ( V_47 -> V_20 == V_9 ) ||
! F_13 ( V_47 -> V_19 , V_47 -> V_20 + 1 ) )
return F_22 ( V_44 , L_15 ,
V_47 -> V_19 , V_47 -> V_20 ) ;
V_47 -> V_50 = 1 ;
return F_22 ( V_44 , L_16 , V_47 -> V_19 , V_47 -> V_20 ) ;
}
if ( ( V_47 -> V_20 == V_9 ) ||
! F_13 ( V_47 -> V_19 , V_47 -> V_20 + 1 ) ) {
V_47 -> V_50 = 0 ;
return F_22 ( V_44 , L_15 , V_47 -> V_19 , V_47 -> V_20 ) ;
}
return 0 ;
}
static T_4
F_23 ( struct V_51 * V_51 , const char T_5 * V_52 ,
T_6 V_53 , T_3 * V_45 )
{
char * V_42 ;
T_4 V_22 , V_23 , V_54 ;
if ( * V_45 )
return - V_41 ;
if ( V_53 > 65536 )
V_53 = 65536 ;
V_42 = F_24 ( V_53 + 1 ) ;
if ( V_42 == NULL )
return - V_55 ;
if ( F_25 ( V_42 , V_52 , V_53 ) < 0 ) {
V_22 = - V_56 ;
goto V_57;
}
V_54 = V_53 - 1 ;
while ( ( V_54 >= 0 ) && ( isspace ( V_42 [ V_54 ] ) || ( V_42 [ V_54 ] == 0 ) ) ) {
V_42 [ V_54 ] = '\0' ;
V_54 -- ;
}
V_23 = F_15 ( V_42 ) ;
if ( V_23 )
V_22 = V_23 ;
else
V_22 = V_53 ;
V_57:
F_26 ( V_42 ) ;
return V_22 ;
}
static int
F_27 ( struct V_58 * V_58 , struct V_51 * V_51 )
{
return F_28 ( V_51 , & V_59 ,
sizeof( struct V_46 ) ) ;
}
static int
F_29 ( void )
{
struct V_60 * V_61 ;
V_61 = F_30 ( L_17 , V_62 | V_63 | V_64 , NULL ,
& V_65 ) ;
if ( ! V_61 )
return - V_66 ;
return 0 ;
}
