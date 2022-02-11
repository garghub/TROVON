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
F_8 ( V_1 -> V_13 , 1 ) ;
F_9 ( V_1 -> V_14 ) ;
}
static int F_10 ( char * V_15 , int * V_16 , int V_17 , int V_18 ,
char * V_19 , int V_20 , int * V_21 )
{
struct V_12 V_1 ;
char V_22 [ sizeof( L_1 ) ] ;
char * V_23 [] = { L_2 , V_22 , L_3 , L_4 , V_15 ,
NULL } ;
char V_24 [ F_11 ( sizeof( * V_16 ) ) ] ;
struct V_25 V_26 ;
struct V_27 * V_28 ;
struct V_29 V_30 ;
int V_31 , V_32 , V_33 ;
sprintf ( V_22 , L_5 , V_34 ) ;
V_1 . V_13 = V_18 ;
V_1 . V_14 = V_17 ;
V_31 = F_12 ( F_7 , & V_1 , V_23 ) ;
if ( V_31 < 0 )
return V_31 ;
F_9 ( V_18 ) ;
V_26 . V_35 = NULL ;
V_26 . V_36 = 0 ;
if ( V_19 != NULL ) {
V_30 = ( (struct V_29 ) { V_19 , V_20 } ) ;
V_26 . V_37 = & V_30 ;
V_26 . V_38 = 1 ;
}
else {
V_26 . V_37 = NULL ;
V_26 . V_38 = 0 ;
}
V_26 . V_39 = V_24 ;
V_26 . V_40 = sizeof( V_24 ) ;
V_26 . V_41 = 0 ;
V_32 = F_13 ( V_17 , & V_26 , 0 ) ;
* V_21 = V_32 ;
if ( V_32 < 0 ) {
V_33 = - V_42 ;
F_14 ( V_43 L_6
L_7 , V_42 ) ;
return V_33 ;
}
F_15 ( V_31 ) ;
V_28 = F_16 ( & V_26 ) ;
if ( V_28 == NULL ) {
F_14 ( V_43 L_8
L_9 ) ;
return - V_44 ;
}
if ( ( V_28 -> V_45 != V_46 ) ||
( V_28 -> V_47 != V_48 ) ) {
F_14 ( V_43 L_8
L_10 ) ;
return - V_44 ;
}
* V_16 = ( ( int * ) F_17 ( V_28 ) ) [ 0 ] ;
F_18 ( * V_16 ) ;
return 0 ;
}
static int F_19 ( void * V_1 )
{
struct V_49 V_50 ;
struct V_3 * V_4 = V_1 ;
char * V_51 , * V_19 ;
int V_33 , V_52 [ 2 ] , V_53 , V_54 ;
V_33 = F_20 ( V_4 -> V_2 , V_4 -> V_7 ) ;
if ( V_33 < 0 )
return V_33 ;
if ( V_4 -> V_9 ) {
V_4 -> V_8 = F_21 ( L_11 ,
F_22 ( F_23 ( F_24 () ) ) , 0 ) ;
if ( V_4 -> V_8 < 0 ) {
F_14 ( V_43 L_12
L_13 , - V_4 -> V_8 ) ;
return V_4 -> V_8 ;
}
memset ( & V_50 , 0 , sizeof( V_50 ) ) ;
V_50 . V_55 = V_56 | V_57 ;
F_25 ( V_50 . V_58 , V_4 -> V_10 , sizeof( V_50 . V_58 ) ) ;
if ( F_26 ( V_4 -> V_8 , V_59 , & V_50 ) < 0 ) {
V_33 = - V_42 ;
F_14 ( V_43 L_14 ,
V_42 ) ;
F_9 ( V_4 -> V_8 ) ;
return V_33 ;
}
}
else {
V_33 = F_27 ( V_60 , V_61 , 0 , V_52 ) ;
if ( V_33 ) {
V_33 = - V_42 ;
F_14 ( V_43 L_15
L_7 , V_42 ) ;
return V_33 ;
}
V_19 = F_28 ( & V_53 ) ;
if ( V_19 != NULL )
V_53 -- ;
V_54 = 0 ;
V_33 = F_10 ( V_4 -> V_7 , & V_4 -> V_8 , V_52 [ 0 ] ,
V_52 [ 1 ] , V_19 , V_53 , & V_54 ) ;
V_51 = V_19 ;
if ( V_33 < 0 ) {
F_14 ( L_16 , V_51 ) ;
F_29 ( V_19 ) ;
F_14 ( V_43 L_17
L_13 , - V_33 ) ;
return V_33 ;
}
V_4 -> V_10 = F_30 ( V_19 ) ;
V_51 += V_62 ;
F_14 ( L_16 , V_51 ) ;
F_29 ( V_19 ) ;
F_9 ( V_52 [ 0 ] ) ;
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
