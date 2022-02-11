static int F_1 ( struct V_1 * V_2 , char * V_3 )
{
struct V_4 * V_5 = & V_4 ;
int V_6 = 9600 ;
int V_7 = 8 ;
int V_8 = 'n' ;
int V_9 = 0 ;
int V_10 = V_11 | V_12 | V_13 ;
char * V_14 ;
struct V_15 * V_16 ;
struct V_17 * V_18 ;
int V_19 ;
struct V_20 * V_21 = NULL ;
struct V_22 V_23 ;
if ( V_3 ) {
V_6 = F_2 ( V_3 , NULL , 10 ) ;
V_14 = V_3 ;
while ( * V_14 >= '0' && * V_14 <= '9' )
V_14 ++ ;
if ( * V_14 )
V_8 = * V_14 ++ ;
if ( * V_14 )
V_7 = * V_14 ++ - '0' ;
if ( * V_14 )
V_9 = ( * V_14 ++ == 'r' ) ;
}
if ( V_6 == 0 )
V_6 = 9600 ;
switch ( V_7 ) {
case 7 :
V_10 |= V_24 ;
break;
default:
case 8 :
V_10 |= V_25 ;
break;
}
switch ( V_8 ) {
case 'o' : case 'O' :
V_10 |= V_26 ;
break;
case 'e' : case 'E' :
V_10 |= V_27 ;
break;
}
V_2 -> V_10 = V_10 ;
V_18 = F_3 ( V_2 -> V_28 ) ;
if ( V_18 == NULL ) {
F_4 ( L_1 , V_2 -> V_28 ) ;
return - V_29 ;
}
V_16 = V_18 -> V_16 ;
V_19 = F_5 ( V_16 -> V_30 ) ;
if ( V_19 )
goto V_31;
F_6 ( & V_18 -> V_18 , NULL ) ;
V_5 -> V_18 = V_18 ;
++ V_18 -> V_18 . V_32 ;
if ( ! F_7 ( & V_18 -> V_18 ) ) {
if ( V_16 -> type -> V_33 ) {
V_21 = F_8 ( sizeof( * V_21 ) , V_34 ) ;
if ( ! V_21 ) {
V_19 = - V_35 ;
goto V_36;
}
F_9 ( & V_21 -> V_37 ) ;
V_21 -> V_38 = V_39 ;
V_21 -> V_28 = V_2 -> V_28 ;
F_10 ( & V_21 -> V_40 ) ;
F_11 ( & V_21 -> V_41 ) ;
F_12 ( & V_21 -> V_42 ) ;
F_13 ( & V_21 -> V_38 -> V_37 ) ;
F_14 ( V_21 -> V_38 -> V_43 ) ;
V_21 -> V_44 = & V_45 ;
F_15 ( V_21 ) ;
F_6 ( & V_18 -> V_18 , V_21 ) ;
}
V_19 = V_16 -> type -> V_46 ( NULL , V_18 ) ;
if ( V_19 ) {
F_16 ( & V_18 -> V_47 , L_2 ) ;
goto V_48;
}
if ( V_16 -> type -> V_33 ) {
V_21 -> V_49 . V_50 = V_10 ;
F_17 ( & V_21 -> V_49 , V_6 , V_6 ) ;
memset ( & V_23 , 0 , sizeof( struct V_22 ) ) ;
V_16 -> type -> V_33 ( V_21 , V_18 , & V_23 ) ;
F_6 ( & V_18 -> V_18 , NULL ) ;
F_18 ( V_21 ) ;
}
F_19 ( & V_18 -> V_18 , 1 ) ;
}
-- V_18 -> V_18 . V_32 ;
V_18 -> V_18 . V_1 = 1 ;
F_20 ( & V_16 -> V_51 ) ;
return V_19 ;
V_48:
F_6 ( & V_18 -> V_18 , NULL ) ;
F_18 ( V_21 ) ;
V_36:
V_18 -> V_18 . V_32 = 0 ;
F_21 ( V_16 -> V_30 ) ;
V_31:
F_22 ( V_16 ) ;
F_20 ( & V_16 -> V_51 ) ;
return V_19 ;
}
static void F_23 ( struct V_1 * V_2 ,
const char * V_52 , unsigned V_32 )
{
static struct V_4 * V_5 = & V_4 ;
struct V_17 * V_18 = V_5 -> V_18 ;
struct V_15 * V_16 ;
int V_19 = - V_29 ;
if ( ! V_18 || V_18 -> V_16 -> V_47 -> V_53 == V_54 )
return;
V_16 = V_18 -> V_16 ;
if ( V_32 == 0 )
return;
F_24 ( & V_18 -> V_47 , L_3 , V_55 , V_32 ) ;
if ( ! V_18 -> V_18 . V_1 ) {
F_24 ( & V_18 -> V_47 , L_4 , V_55 ) ;
return;
}
while ( V_32 ) {
unsigned int V_56 ;
unsigned int V_57 ;
for ( V_56 = 0 , V_57 = 0 ; V_56 < V_32 ; V_56 ++ ) {
if ( * ( V_52 + V_56 ) == 10 ) {
V_57 = 1 ;
V_56 ++ ;
break;
}
}
V_19 = V_16 -> type -> V_58 ( NULL , V_18 , V_52 , V_56 ) ;
F_24 ( & V_18 -> V_47 , L_5 , V_55 , V_19 ) ;
if ( V_57 ) {
unsigned char V_59 = 13 ;
V_19 = V_16 -> type -> V_58 ( NULL , V_18 , & V_59 , 1 ) ;
F_24 ( & V_18 -> V_47 , L_6 ,
V_55 , V_19 ) ;
}
V_52 += V_56 ;
V_32 -= V_56 ;
}
}
static struct V_60 * F_25 ( struct V_1 * V_2 , int * V_28 )
{
struct V_60 * * V_61 = (struct V_60 * * ) V_2 -> V_62 ;
if ( ! * V_61 )
return NULL ;
* V_28 = V_2 -> V_28 ;
return * V_61 ;
}
void F_26 ( struct V_15 * V_16 )
{
if ( V_16 -> V_18 [ 0 ] == V_4 . V_18 ) {
F_27 () ;
F_22 ( V_16 ) ;
}
}
void F_28 ( int V_63 )
{
if ( V_63 == 0 ) {
F_29 ( L_7 ) ;
F_30 ( & V_64 ) ;
}
}
void F_27 ( void )
{
if ( V_4 . V_18 ) {
F_31 ( & V_64 ) ;
V_4 . V_18 -> V_18 . V_1 = 0 ;
V_4 . V_18 = NULL ;
}
}
