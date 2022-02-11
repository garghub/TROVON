static int F_1 ( unsigned char V_1 ,
const struct V_2 * * type ,
struct V_3 * * V_4 ,
unsigned char * V_5 ,
unsigned int V_6 )
{
struct V_7 * V_8 ;
int V_9 = 0 ;
* type = V_2 ( V_1 ) ;
if ( ! * type ) {
F_2 ( L_1 ,
V_1 , V_10 ) ;
return - V_11 ;
}
V_8 = F_3 ( ( * type ) -> V_12 , 0 , V_13 ) ;
if ( F_4 ( V_8 ) ) {
F_5 ( V_14 , L_2 ,
( * type ) -> V_12 ) ;
return F_6 ( V_8 ) ;
}
* V_4 = F_7 ( V_8 , V_15 ) ;
if ( ! * V_4 ) {
F_5 ( V_14 , L_3 ,
( * type ) -> V_12 ) ;
F_8 ( V_8 ) ;
return - V_16 ;
}
F_9 ( * V_4 , 0 , NULL , NULL ) ;
if ( V_5 )
V_9 = F_10 ( V_8 , V_5 , V_6 ) ;
else if ( ( * type ) -> V_17 != 0 )
V_9 = F_10 ( V_8 ,
( unsigned char * ) & ( ( * type ) -> V_17 ) ,
( * type ) -> V_18 ) ;
if ( V_9 != 0 ) {
F_8 ( V_8 ) ;
return V_9 ;
}
F_5 ( V_14 , L_4 ,
F_11 ( V_8 ) , F_12 ( V_8 ) ,
V_19 [ V_1 ] ) ;
V_9 = F_13 ( * V_4 ) ;
if ( V_9 ) {
F_14 ( * V_4 ) ;
F_8 ( V_8 ) ;
}
return V_9 ;
}
int F_15 ( unsigned char V_1 ,
const void * V_20 , unsigned int V_21 ,
unsigned char * V_5 , unsigned int V_6 ,
unsigned char * V_22 , unsigned int * V_23 )
{
struct V_24 V_25 ;
struct V_3 * V_4 ;
int V_9 ;
const struct V_2 * type ;
if ( ! V_20 || V_21 == 0 || ! V_23 )
return - V_11 ;
V_9 = F_1 ( V_1 , & type , & V_4 , V_5 , V_6 ) ;
if ( V_9 != 0 )
return V_9 ;
if ( ! V_22 || * V_23 < type -> V_18 ) {
* V_23 = type -> V_18 ;
F_8 ( F_16 ( V_4 ) ) ;
F_14 ( V_4 ) ;
return - V_26 ;
}
F_17 ( & V_25 , V_20 , V_21 ) ;
F_18 ( V_4 , & V_25 , V_22 , V_25 . V_27 ) ;
V_9 = F_19 ( V_4 ) ;
F_8 ( F_16 ( V_4 ) ) ;
F_14 ( V_4 ) ;
return V_9 ;
}
struct V_28 *
F_20 ( unsigned char V_1 ,
unsigned char * V_5 , unsigned int V_6 )
{
struct V_3 * V_4 ;
int V_9 ;
const struct V_2 * type ;
V_9 = F_1 ( V_1 , & type , & V_4 , V_5 , V_6 ) ;
if ( V_9 )
return F_21 ( V_9 ) ;
return (struct V_28 * ) V_4 ;
}
int F_22 ( struct V_28 * V_29 ,
struct V_30 * V_30 , unsigned int V_31 ,
unsigned int V_32 )
{
struct V_3 * V_4 = ( void * ) V_29 ;
struct V_24 V_25 ;
F_23 ( & V_25 , 1 ) ;
F_24 ( & V_25 , V_30 , V_32 , V_31 & ~ V_33 ) ;
F_18 ( V_4 , & V_25 , NULL , V_25 . V_27 ) ;
return F_25 ( V_4 ) ;
}
int F_26 ( struct V_28 * V_29 ,
const void * V_20 , unsigned int V_21 )
{
struct V_3 * V_4 = ( void * ) V_29 ;
struct V_24 V_25 ;
F_17 ( & V_25 , V_20 , V_21 ) ;
F_18 ( V_4 , & V_25 , NULL , V_25 . V_27 ) ;
return F_25 ( V_4 ) ;
}
int F_27 ( struct V_28 * V_29 ,
unsigned char * V_22 , unsigned int * V_23 )
{
int V_9 ;
struct V_3 * V_4 = ( void * ) V_29 ;
int V_34 = F_28 ( F_16 ( V_4 ) ) ;
if ( ! V_23 ) {
F_8 ( F_16 ( V_4 ) ) ;
F_14 ( V_4 ) ;
return 0 ;
}
if ( ! V_22 || * V_23 < V_34 ) {
* V_23 = V_34 ;
return - V_26 ;
}
F_18 ( V_4 , NULL , V_22 , 0 ) ;
V_9 = F_29 ( V_4 ) ;
if ( V_9 < 0 ) {
return V_9 ;
}
F_8 ( F_16 ( V_4 ) ) ;
F_14 ( V_4 ) ;
return V_9 ;
}
static void F_30 ( unsigned char V_1 ,
const unsigned char * V_20 ,
unsigned int V_21 )
{
unsigned long V_35 , V_36 ;
int V_37 , V_9 = 0 ;
int V_38 = 1 ;
unsigned char V_22 [ 64 ] ;
unsigned int V_23 = 64 ;
for ( V_35 = V_39 , V_36 = V_35 + V_38 * V_40 , V_37 = 0 ;
F_31 ( V_39 , V_36 ) ; V_37 ++ ) {
V_9 = F_15 ( V_1 , V_20 , V_21 , NULL , 0 ,
V_22 , & V_23 ) ;
if ( V_9 )
break;
}
V_36 = V_39 ;
if ( V_9 ) {
V_19 [ V_1 ] = - 1 ;
F_5 ( V_14 , L_5 ,
F_32 ( V_1 ) , V_9 ) ;
} else {
unsigned long V_41 ;
V_41 = ( ( V_37 * V_21 / F_33 ( V_36 - V_35 ) ) *
1000 ) / ( 1024 * 1024 ) ;
V_19 [ V_1 ] = ( int ) V_41 ;
}
F_5 ( V_14 , L_6 ,
F_32 ( V_1 ) , V_19 [ V_1 ] ) ;
}
int F_34 ( unsigned char V_42 )
{
if ( V_42 < V_10 )
return V_19 [ V_42 ] ;
return - 1 ;
}
static int F_35 ( void )
{
unsigned char V_43 ;
unsigned char * V_44 ;
unsigned int V_45 ;
unsigned int V_46 = 1 * 128 * 1024 ;
V_44 = F_36 ( V_46 , 0 ) ;
if ( ! V_44 )
return - V_16 ;
for ( V_45 = 0 ; V_45 < V_46 ; V_45 ++ )
V_44 [ V_45 ] = V_45 & 0xff ;
for ( V_43 = 0 ; V_43 < V_10 ; V_43 ++ )
F_30 ( V_43 , V_44 , V_46 ) ;
F_37 ( V_44 ) ;
return 0 ;
}
int F_38 ( void )
{
F_39 ( L_7 ) ;
V_47 = F_40 () ;
F_35 () ;
return 0 ;
}
void F_41 ( void )
{
if ( V_47 == 0 )
F_42 () ;
}
