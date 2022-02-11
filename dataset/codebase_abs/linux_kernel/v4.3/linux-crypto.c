static int F_1 ( unsigned char V_1 ,
const struct V_2 * * type ,
struct V_3 * V_4 , unsigned char * V_5 ,
unsigned int V_6 )
{
int V_7 = 0 ;
* type = V_2 ( V_1 ) ;
if ( * type == NULL ) {
F_2 ( L_1 ,
V_1 , V_8 ) ;
return - V_9 ;
}
V_4 -> V_10 = F_3 ( ( * type ) -> V_11 , 0 , 0 ) ;
if ( V_4 -> V_10 == NULL )
return - V_9 ;
if ( F_4 ( V_4 -> V_10 ) ) {
F_5 ( V_12 , L_2 ,
( * type ) -> V_11 ) ;
return F_6 ( V_4 -> V_10 ) ;
}
V_4 -> V_13 = 0 ;
if ( V_5 != NULL ) {
V_7 = F_7 ( V_4 -> V_10 , V_5 , V_6 ) ;
} else if ( ( * type ) -> V_14 != 0 ) {
V_7 = F_7 ( V_4 -> V_10 ,
( unsigned char * ) & ( ( * type ) -> V_14 ) ,
( * type ) -> V_15 ) ;
}
if ( V_7 != 0 ) {
F_8 ( V_4 -> V_10 ) ;
return V_7 ;
}
F_5 ( V_12 , L_3 ,
( F_9 ( V_4 -> V_10 ) ) -> V_16 -> V_17 ,
( F_9 ( V_4 -> V_10 ) ) -> V_16 -> V_18 ,
V_19 [ V_1 ] ) ;
return F_10 ( V_4 ) ;
}
int F_11 ( unsigned char V_1 ,
const void * V_20 , unsigned int V_21 ,
unsigned char * V_5 , unsigned int V_6 ,
unsigned char * V_22 , unsigned int * V_23 )
{
struct V_24 V_25 ;
struct V_3 V_26 ;
int V_7 ;
const struct V_2 * type ;
if ( V_20 == NULL || V_21 == 0 || V_23 == NULL )
return - V_9 ;
V_7 = F_1 ( V_1 , & type , & V_26 , V_5 , V_6 ) ;
if ( V_7 != 0 )
return V_7 ;
if ( V_22 == NULL || * V_23 < type -> V_15 ) {
* V_23 = type -> V_15 ;
F_8 ( V_26 . V_10 ) ;
return - V_27 ;
}
F_12 ( & V_25 , V_20 , V_21 ) ;
V_26 . V_13 = 0 ;
V_7 = F_13 ( & V_26 , & V_25 , V_25 . V_28 , V_22 ) ;
F_8 ( V_26 . V_10 ) ;
return V_7 ;
}
struct V_29 *
F_14 ( unsigned char V_1 ,
unsigned char * V_5 , unsigned int V_6 )
{
struct V_3 * V_26 ;
int V_7 ;
const struct V_2 * type ;
V_26 = F_15 ( sizeof( * V_26 ) , 0 ) ;
if ( V_26 == NULL )
return F_16 ( - V_30 ) ;
V_7 = F_1 ( V_1 , & type , V_26 , V_5 , V_6 ) ;
if ( V_7 ) {
F_17 ( V_26 ) ;
return F_16 ( V_7 ) ;
}
return (struct V_29 * ) V_26 ;
}
int F_18 ( struct V_29 * V_26 ,
struct V_31 * V_31 , unsigned int V_32 ,
unsigned int V_33 )
{
struct V_24 V_25 ;
F_19 ( & V_25 , 1 ) ;
F_20 ( & V_25 , V_31 , V_33 , V_32 & ~ V_34 ) ;
return F_21 ( (struct V_3 * ) V_26 , & V_25 , V_25 . V_28 ) ;
}
int F_22 ( struct V_29 * V_26 ,
const void * V_20 , unsigned int V_21 )
{
struct V_24 V_25 ;
F_12 ( & V_25 , V_20 , V_21 ) ;
return F_21 ( (struct V_3 * ) V_26 , & V_25 , V_25 . V_28 ) ;
}
int F_23 ( struct V_29 * V_26 ,
unsigned char * V_22 , unsigned int * V_23 )
{
int V_7 ;
int V_35 = F_24 ( ( (struct V_3 * ) V_26 ) -> V_10 ) ;
if ( V_23 == NULL ) {
F_8 ( ( (struct V_3 * ) V_26 ) -> V_10 ) ;
F_17 ( V_26 ) ;
return 0 ;
}
if ( V_22 == NULL || * V_23 < V_35 ) {
* V_23 = V_35 ;
return - V_27 ;
}
V_7 = F_25 ( (struct V_3 * ) V_26 , V_22 ) ;
if ( V_7 < 0 ) {
return V_7 ;
}
F_8 ( ( (struct V_3 * ) V_26 ) -> V_10 ) ;
F_17 ( V_26 ) ;
return V_7 ;
}
static void F_26 ( unsigned char V_1 ,
const unsigned char * V_20 ,
unsigned int V_21 )
{
unsigned long V_36 , V_37 ;
int V_38 , V_7 = 0 ;
int V_39 = 1 ;
unsigned char V_22 [ 64 ] ;
unsigned int V_23 = 64 ;
for ( V_36 = V_40 , V_37 = V_36 + V_39 * V_41 , V_38 = 0 ;
F_27 ( V_40 , V_37 ) ; V_38 ++ ) {
V_7 = F_11 ( V_1 , V_20 , V_21 , NULL , 0 ,
V_22 , & V_23 ) ;
if ( V_7 )
break;
}
V_37 = V_40 ;
if ( V_7 ) {
V_19 [ V_1 ] = - 1 ;
F_5 ( V_12 , L_4 ,
F_28 ( V_1 ) , V_7 ) ;
} else {
unsigned long V_42 ;
V_42 = ( ( V_38 * V_21 / F_29 ( V_37 - V_36 ) ) *
1000 ) / ( 1024 * 1024 ) ;
V_19 [ V_1 ] = ( int ) V_42 ;
}
F_5 ( V_12 , L_5 ,
F_28 ( V_1 ) , V_19 [ V_1 ] ) ;
}
int F_30 ( unsigned char V_43 )
{
if ( V_43 < V_8 )
return V_19 [ V_43 ] ;
else
return - 1 ;
}
static int F_31 ( void )
{
unsigned char V_44 ;
unsigned char * V_45 ;
unsigned int V_46 ;
unsigned int V_47 = 1 * 128 * 1024 ;
V_45 = F_15 ( V_47 , 0 ) ;
if ( V_45 == NULL ) {
F_32 ( L_6 ) ;
return - V_30 ;
}
for ( V_46 = 0 ; V_46 < V_47 ; V_46 ++ )
V_45 [ V_46 ] = V_46 & 0xff ;
for ( V_44 = 0 ; V_44 < V_8 ; V_44 ++ )
F_26 ( V_44 , V_45 , V_47 ) ;
F_17 ( V_45 ) ;
return 0 ;
}
int F_33 ( void )
{
F_34 ( L_7 ) ;
V_48 = F_35 () ;
F_31 () ;
return 0 ;
}
void F_36 ( void )
{
if ( V_48 == 0 )
F_37 () ;
return;
}
