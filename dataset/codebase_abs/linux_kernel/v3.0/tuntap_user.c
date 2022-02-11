static int F_1 ( void * V_1 , void * V_2 )
{
struct V_3 * V_4 = V_1 ;
V_4 -> V_2 = V_2 ;
return 0 ;
}
static void F_2 ( unsigned char * V_5 , unsigned char * V_6 ,
void * V_1 )
{
struct V_3 * V_4 = V_1 ;
F_3 ( V_4 -> V_7 , V_5 ) ;
if ( ( V_4 -> V_8 == - 1 ) || V_4 -> V_9 )
return;
F_4 ( V_5 , V_6 , V_4 -> V_10 ) ;
}
static void F_5 ( unsigned char * V_5 , unsigned char * V_6 ,
void * V_1 )
{
struct V_3 * V_4 = V_1 ;
if ( ( V_4 -> V_8 == - 1 ) || V_4 -> V_9 )
return;
F_6 ( V_5 , V_6 , V_4 -> V_10 ) ;
}
static void F_7 ( void * V_11 )
{
struct V_12 * V_1 = V_11 ;
F_8 ( V_1 -> stdout , 1 ) ;
F_9 ( V_1 -> V_13 ) ;
}
static int F_10 ( char * V_14 , int * V_15 , int V_16 , int V_17 ,
char * V_18 , int V_19 , int * V_20 )
{
struct V_12 V_1 ;
char V_21 [ sizeof( L_1 ) ] ;
char * V_22 [] = { L_2 , V_21 , L_3 , L_4 , V_14 ,
NULL } ;
char V_23 [ F_11 ( sizeof( * V_15 ) ) ] ;
struct V_24 V_25 ;
struct V_26 * V_27 ;
struct V_28 V_29 ;
int V_30 , V_31 , V_32 ;
sprintf ( V_21 , L_5 , V_33 ) ;
V_1 . stdout = V_17 ;
V_1 . V_13 = V_16 ;
V_30 = F_12 ( F_7 , & V_1 , V_22 ) ;
if ( V_30 < 0 )
return - V_30 ;
F_9 ( V_17 ) ;
V_25 . V_34 = NULL ;
V_25 . V_35 = 0 ;
if ( V_18 != NULL ) {
V_29 = ( (struct V_28 ) { V_18 , V_19 } ) ;
V_25 . V_36 = & V_29 ;
V_25 . V_37 = 1 ;
}
else {
V_25 . V_36 = NULL ;
V_25 . V_37 = 0 ;
}
V_25 . V_38 = V_23 ;
V_25 . V_39 = sizeof( V_23 ) ;
V_25 . V_40 = 0 ;
V_31 = F_13 ( V_16 , & V_25 , 0 ) ;
* V_20 = V_31 ;
if ( V_31 < 0 ) {
V_32 = - V_41 ;
F_14 ( V_42 L_6
L_7 , V_41 ) ;
return V_32 ;
}
F_15 ( V_30 ) ;
V_27 = F_16 ( & V_25 ) ;
if ( V_27 == NULL ) {
F_14 ( V_42 L_8
L_9 ) ;
return - V_43 ;
}
if ( ( V_27 -> V_44 != V_45 ) ||
( V_27 -> V_46 != V_47 ) ) {
F_14 ( V_42 L_8
L_10 ) ;
return - V_43 ;
}
* V_15 = ( ( int * ) F_17 ( V_27 ) ) [ 0 ] ;
F_18 ( * V_15 ) ;
return 0 ;
}
static int F_19 ( void * V_1 )
{
struct V_48 V_49 ;
struct V_3 * V_4 = V_1 ;
char * V_50 , * V_18 ;
int V_32 , V_51 [ 2 ] , V_52 , V_53 ;
V_32 = F_20 ( V_4 -> V_2 , V_4 -> V_7 ) ;
if ( V_32 < 0 )
return V_32 ;
if ( V_4 -> V_9 ) {
V_4 -> V_8 = F_21 ( L_11 ,
F_22 ( F_23 ( F_24 () ) ) , 0 ) ;
if ( V_4 -> V_8 < 0 ) {
F_14 ( V_42 L_12
L_13 , - V_4 -> V_8 ) ;
return V_4 -> V_8 ;
}
memset ( & V_49 , 0 , sizeof( V_49 ) ) ;
V_49 . V_54 = V_55 | V_56 ;
F_25 ( V_49 . V_57 , V_4 -> V_10 , sizeof( V_49 . V_57 ) ) ;
if ( F_26 ( V_4 -> V_8 , V_58 , & V_49 ) < 0 ) {
V_32 = - V_41 ;
F_14 ( V_42 L_14 ,
V_41 ) ;
F_9 ( V_4 -> V_8 ) ;
return V_32 ;
}
}
else {
V_32 = F_27 ( V_59 , V_60 , 0 , V_51 ) ;
if ( V_32 ) {
V_32 = - V_41 ;
F_14 ( V_42 L_15
L_7 , V_41 ) ;
return V_32 ;
}
V_18 = F_28 ( & V_52 ) ;
if ( V_18 != NULL )
V_52 -- ;
V_53 = 0 ;
V_32 = F_10 ( V_4 -> V_7 , & V_4 -> V_8 , V_51 [ 0 ] ,
V_51 [ 1 ] , V_18 , V_52 , & V_53 ) ;
V_50 = V_18 ;
if ( V_32 < 0 ) {
F_14 ( L_16 , V_50 ) ;
F_29 ( V_18 ) ;
F_14 ( V_42 L_17
L_13 , - V_32 ) ;
return V_32 ;
}
V_4 -> V_10 = F_30 ( V_18 ) ;
V_50 += V_61 ;
F_14 ( L_16 , V_50 ) ;
F_29 ( V_18 ) ;
F_9 ( V_51 [ 0 ] ) ;
F_31 ( V_4 -> V_2 , F_4 , V_4 -> V_10 ) ;
}
return V_4 -> V_8 ;
}
static void F_32 ( int V_8 , void * V_1 )
{
struct V_3 * V_4 = V_1 ;
if ( ! V_4 -> V_9 )
F_31 ( V_4 -> V_2 , F_6 , V_4 -> V_10 ) ;
F_9 ( V_8 ) ;
V_4 -> V_8 = - 1 ;
}
