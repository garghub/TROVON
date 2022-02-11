void F_1 ( T_1 * V_1 , int V_2 , int V_3 , int V_4 )
{
V_1 -> V_5 -> V_6 ( V_1 , V_2 , V_3 , V_4 ) ;
}
int F_2 ( T_1 * V_1 , int V_2 , int V_3 )
{
return V_1 -> V_5 -> V_7 ( V_1 , V_2 , V_3 ) ;
}
void F_3 ( T_1 * V_1 , char * V_8 , int V_9 )
{
V_1 -> V_5 -> V_10 ( V_1 , V_8 , V_9 ) ;
}
void F_4 ( T_1 * V_1 , char * V_8 , int V_9 )
{
V_1 -> V_5 -> V_11 ( V_1 , V_8 , V_9 ) ;
}
static void F_5 ( void * V_12 )
{
T_1 * V_1 = ( T_1 * ) V_12 ;
unsigned long V_13 ;
void (* V_2) ( void ) = NULL ;
F_6 ( & V_14 , V_13 ) ;
if ( V_1 -> V_15 && ! F_7 ( V_1 -> V_16 ) ) {
V_2 = V_1 -> V_15 ;
V_1 -> V_15 = NULL ;
V_1 -> V_17 = 1 ;
}
F_8 ( & V_14 , V_13 ) ;
F_9 ( & ( V_1 -> V_18 ) ) ;
if ( V_2 )
V_2 () ;
}
int F_10 ( T_1 * V_1 , void (* V_2) ( void ) )
{
unsigned long V_13 ;
F_6 ( & V_14 , V_13 ) ;
if ( V_1 -> V_16 && F_7 ( V_1 -> V_16 ) ) {
V_1 -> V_15 = V_2 ;
F_8 ( & V_14 , V_13 ) ;
return 0 ;
}
V_1 -> V_17 = 1 ;
F_8 ( & V_14 , V_13 ) ;
return 1 ;
}
void F_11 ( T_1 * V_1 , void (* V_2) ( void ) )
{
if ( F_10 ( V_1 , V_2 ) )
V_2 () ;
}
static void F_12 ( T_1 * V_1 )
{
if ( V_1 -> V_17 )
return;
V_1 -> V_17 = 1 ;
if ( V_1 -> V_16 )
F_13 ( V_1 -> V_18 ,
! F_7 ( (struct V_19 * ) V_1 -> V_16 ) ) ;
}
static void F_14 ( T_1 * V_1 )
{
V_1 -> V_17 = 0 ;
if ( V_1 -> V_16 )
F_15 ( (struct V_19 * ) ( V_1 -> V_16 ) ) ;
}
void F_16 ( T_1 * V_1 )
{
F_12 ( V_1 ) ;
V_1 -> V_5 -> V_20 ( V_1 ) ;
}
void F_17 ( T_1 * V_1 )
{
V_1 -> V_5 -> V_21 ( V_1 ) ;
F_14 ( V_1 ) ;
}
static void F_18 ( T_1 * V_1 )
{
if ( V_1 -> V_16 ) {
F_19 ( (struct V_19 * ) ( V_1 -> V_16 ) ) ;
V_1 -> V_16 = NULL ;
}
}
void F_20 ( T_1 * V_1 )
{
F_18 ( V_1 ) ;
if ( V_1 -> V_5 -> V_22 )
V_1 -> V_5 -> V_22 ( V_1 ) ;
F_21 ( V_1 -> V_5 -> V_23 ) ;
}
static int F_22 ( T_1 * V_1 , char * V_24 , int V_25 )
{
int V_26 , V_27 ;
int V_28 [ 2 ] = { 0 , 0 } ;
V_1 -> V_5 -> V_20 ( V_1 ) ;
for ( V_26 = 0 ; V_26 < 2 ; V_26 ++ ) {
F_1 ( V_1 , 0 , 6 , 0xa0 + V_26 * 0x10 ) ;
for ( V_27 = 0 ; V_27 < 256 ; V_27 ++ ) {
F_1 ( V_1 , 0 , 2 , V_27 ^ 0xaa ) ;
F_1 ( V_1 , 0 , 3 , V_27 ^ 0x55 ) ;
if ( F_2 ( V_1 , 0 , 2 ) != ( V_27 ^ 0xaa ) )
V_28 [ V_26 ] ++ ;
}
}
V_1 -> V_5 -> V_21 ( V_1 ) ;
if ( V_25 )
F_23 ( L_1 ,
V_1 -> V_29 , V_1 -> V_5 -> V_30 , V_1 -> V_31 ,
V_1 -> V_32 , V_28 [ 0 ] , V_28 [ 1 ] ) ;
return ( V_28 [ 0 ] && V_28 [ 1 ] ) ;
}
static int F_24 ( T_1 * V_1 , char * V_24 , int V_25 )
{
int V_33 ;
F_12 ( V_1 ) ;
if ( V_1 -> V_5 -> V_34 )
V_33 = V_1 -> V_5 -> V_34 ( V_1 , V_24 , V_25 ) ;
else
V_33 = F_22 ( V_1 , V_24 , V_25 ) ;
F_14 ( V_1 ) ;
return V_33 ;
}
int F_25 ( T_2 * V_35 )
{
int V_27 ;
for ( V_27 = 0 ; V_27 < V_36 ; V_27 ++ )
if ( V_37 [ V_27 ] && ! strcmp ( V_35 -> V_30 , V_37 [ V_27 ] -> V_30 ) ) {
F_23 ( L_2 ,
V_35 -> V_30 ) ;
return - 1 ;
}
V_27 = 0 ;
while ( ( V_27 < V_36 ) && ( V_37 [ V_27 ] ) )
V_27 ++ ;
if ( V_27 == V_36 ) {
F_23 ( L_3 ) ;
return - 1 ;
}
V_37 [ V_27 ] = V_35 ;
V_35 -> V_38 = V_27 ;
F_23 ( L_4 , V_35 -> V_30 , V_27 ) ;
return 0 ;
}
void F_26 ( T_2 * V_35 )
{
if ( ! V_35 )
return;
if ( V_37 [ V_35 -> V_38 ] != V_35 ) {
F_23 ( L_5 , V_35 -> V_30 ) ;
return;
}
V_37 [ V_35 -> V_38 ] = NULL ;
}
static int F_27 ( T_1 * V_1 , int V_25 )
{
struct V_39 * V_31 ;
V_31 = F_28 ( V_1 -> V_31 ) ;
if ( ! V_31 )
return 0 ;
V_1 -> V_16 = F_29 ( V_31 ,
V_1 -> V_29 , NULL ,
F_5 , NULL , 0 , ( void * ) V_1 ) ;
F_30 ( V_31 ) ;
if ( ! V_1 -> V_16 )
return 0 ;
F_31 ( & V_1 -> V_18 ) ;
if ( V_25 )
F_23 ( L_6 , V_1 -> V_29 , V_1 -> V_31 , V_31 -> V_30 ) ;
V_1 -> V_40 = ( char * ) V_31 -> V_30 ;
return 1 ;
}
static int F_32 ( T_1 * V_1 , int V_41 , char * V_24 , int V_25 )
{
int V_42 , V_43 ;
if ( V_1 -> V_32 != - 1 ) {
if ( V_1 -> V_32 >= V_41 )
return 0 ;
V_43 = 3 ;
if ( V_1 -> V_32 >= V_1 -> V_5 -> V_44 )
V_43 = 8 ;
if ( ( V_43 == 8 ) && ( V_1 -> V_31 % 8 ) )
return 0 ;
V_1 -> V_45 = V_43 ;
return ( ! F_24 ( V_1 , V_24 , V_25 ) ) ;
}
V_42 = - 1 ;
for ( V_1 -> V_32 = 0 ; V_1 -> V_32 < V_41 ; V_1 -> V_32 ++ ) {
V_43 = 3 ;
if ( V_1 -> V_32 >= V_1 -> V_5 -> V_44 )
V_43 = 8 ;
if ( ( V_43 == 8 ) && ( V_1 -> V_31 % 8 ) )
break;
V_1 -> V_45 = V_43 ;
if ( ! F_24 ( V_1 , V_24 , V_25 ) )
V_42 = V_1 -> V_32 ;
}
V_1 -> V_32 = V_42 ;
return ( V_42 > - 1 ) ;
}
static int F_33 ( T_1 * V_1 , int V_46 , char * V_24 , int V_25 )
{
int V_41 , V_47 , V_28 ;
V_47 = V_46 ;
V_28 = V_47 + 1 ;
if ( V_47 == - 1 ) {
V_47 = 0 ;
V_28 = V_1 -> V_5 -> V_48 ;
}
if ( ! F_27 ( V_1 , V_25 ) )
return 0 ;
if ( V_1 -> V_5 -> V_49 ) {
F_12 ( V_1 ) ;
V_41 = V_1 -> V_5 -> V_49 ( V_1 ) ;
F_14 ( V_1 ) ;
} else
V_41 = V_1 -> V_5 -> V_50 ;
if ( V_1 -> V_5 -> V_51 ) {
F_12 ( V_1 ) ;
for ( V_1 -> V_46 = V_47 ; V_1 -> V_46 < V_28 ; V_1 -> V_46 ++ )
if ( V_1 -> V_5 -> V_51 ( V_1 ) ) {
F_14 ( V_1 ) ;
if ( F_32 ( V_1 , V_41 , V_24 , V_25 ) )
return 1 ;
F_18 ( V_1 ) ;
return 0 ;
}
F_14 ( V_1 ) ;
F_18 ( V_1 ) ;
return 0 ;
}
if ( ! F_32 ( V_1 , V_41 , V_24 , V_25 ) ) {
F_18 ( V_1 ) ;
return 0 ;
}
return 1 ;
}
int F_34 ( T_1 * V_1 , int V_52 , int V_31 , int V_32 ,
int V_46 , int V_53 , int V_54 , char * V_24 ,
int V_55 , int V_25 , char * V_29 )
{
int V_12 , V_27 , V_47 , V_28 ;
int V_56 [ 7 ] = { 0x3bc , 0x378 , 0x278 , 0x268 , 0x27c , 0x26c , 0 } ;
V_47 = V_53 ;
V_28 = V_47 + 1 ;
if ( ! V_37 [ 0 ] )
F_35 ( L_7 ) ;
if ( V_52 ) {
V_47 = 0 ;
V_28 = V_36 ;
} else if ( ( V_47 < 0 ) || ( V_47 >= V_36 ) || ( V_31 <= 0 ) ||
( ! V_37 [ V_47 ] ) || ( V_46 < 0 ) ||
( V_46 >= V_37 [ V_47 ] -> V_48 ) ) {
F_23 ( L_8 , V_29 ) ;
return 0 ;
}
for ( V_12 = V_47 ; V_12 < V_28 ; V_12 ++ ) {
struct V_57 * V_5 = V_37 [ V_12 ] ;
if ( ! V_5 )
continue;
if ( ! F_36 ( V_5 -> V_23 ) )
continue;
V_1 -> V_5 = V_5 ;
V_1 -> V_58 = 0 ;
if ( V_5 -> V_59 && V_5 -> V_59 ( V_1 ) < 0 ) {
V_1 -> V_5 = NULL ;
F_21 ( V_5 -> V_23 ) ;
continue;
}
if ( V_54 == - 1 )
V_1 -> V_54 = V_1 -> V_5 -> V_60 ;
else
V_1 -> V_54 = V_54 ;
V_1 -> V_55 = V_55 ;
V_1 -> V_29 = V_29 ;
V_1 -> V_40 = NULL ;
V_1 -> V_16 = NULL ;
F_31 ( & V_1 -> V_18 ) ;
V_1 -> V_17 = 0 ;
V_1 -> V_15 = NULL ;
V_1 -> V_32 = V_32 ;
if ( V_31 != - 1 ) {
V_1 -> V_31 = V_31 ;
if ( F_33 ( V_1 , V_46 , V_24 , V_25 ) )
break;
V_1 -> V_31 = 0 ;
} else {
V_27 = 0 ;
while ( ( V_1 -> V_31 = V_56 [ V_27 ++ ] ) )
if ( F_33
( V_1 , V_46 , V_24 , V_25 ) )
break;
if ( V_1 -> V_31 )
break;
}
if ( V_1 -> V_5 -> V_22 )
V_1 -> V_5 -> V_22 ( V_1 ) ;
F_21 ( V_5 -> V_23 ) ;
}
if ( ! V_1 -> V_31 ) {
if ( V_52 )
F_23 ( L_9 , V_29 ) ;
else
F_23 ( L_10 , V_29 ) ;
return 0 ;
}
if ( V_1 -> V_40 )
F_23 ( L_11 , V_1 -> V_29 ,
V_1 -> V_40 , V_1 -> V_31 ) ;
V_1 -> V_5 -> V_61 ( V_1 , V_24 , V_25 ) ;
return 1 ;
}
