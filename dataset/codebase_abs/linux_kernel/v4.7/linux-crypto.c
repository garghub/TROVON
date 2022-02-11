static int F_1 ( enum V_1 V_2 ,
const struct V_3 * * type ,
struct V_4 * * V_5 ,
unsigned char * V_6 ,
unsigned int V_7 )
{
struct V_8 * V_9 ;
int V_10 = 0 ;
* type = V_3 ( V_2 ) ;
if ( ! * type ) {
F_2 ( L_1 ,
V_2 , V_11 ) ;
return - V_12 ;
}
V_9 = F_3 ( ( * type ) -> V_13 , 0 , V_14 ) ;
if ( F_4 ( V_9 ) ) {
F_5 ( V_15 , L_2 ,
( * type ) -> V_13 ) ;
return F_6 ( V_9 ) ;
}
* V_5 = F_7 ( V_9 , V_16 ) ;
if ( ! * V_5 ) {
F_5 ( V_15 , L_3 ,
( * type ) -> V_13 ) ;
F_8 ( V_9 ) ;
return - V_17 ;
}
F_9 ( * V_5 , 0 , NULL , NULL ) ;
if ( V_6 )
V_10 = F_10 ( V_9 , V_6 , V_7 ) ;
else if ( ( * type ) -> V_18 != 0 )
V_10 = F_10 ( V_9 ,
( unsigned char * ) & ( ( * type ) -> V_18 ) ,
( * type ) -> V_19 ) ;
if ( V_10 != 0 ) {
F_8 ( V_9 ) ;
return V_10 ;
}
F_5 ( V_15 , L_4 ,
F_11 ( V_9 ) , F_12 ( V_9 ) ,
V_20 [ V_2 ] ) ;
V_10 = F_13 ( * V_5 ) ;
if ( V_10 ) {
F_14 ( * V_5 ) ;
F_8 ( V_9 ) ;
}
return V_10 ;
}
int F_15 ( enum V_1 V_2 ,
const void * V_21 , unsigned int V_22 ,
unsigned char * V_6 , unsigned int V_7 ,
unsigned char * V_23 , unsigned int * V_24 )
{
struct V_25 V_26 ;
struct V_4 * V_5 ;
int V_10 ;
const struct V_3 * type ;
if ( ! V_21 || V_22 == 0 || ! V_24 )
return - V_12 ;
V_10 = F_1 ( V_2 , & type , & V_5 , V_6 , V_7 ) ;
if ( V_10 != 0 )
return V_10 ;
if ( ! V_23 || * V_24 < type -> V_19 ) {
* V_24 = type -> V_19 ;
F_8 ( F_16 ( V_5 ) ) ;
F_14 ( V_5 ) ;
return - V_27 ;
}
F_17 ( & V_26 , V_21 , V_22 ) ;
F_18 ( V_5 , & V_26 , V_23 , V_26 . V_28 ) ;
V_10 = F_19 ( V_5 ) ;
F_8 ( F_16 ( V_5 ) ) ;
F_14 ( V_5 ) ;
return V_10 ;
}
struct V_29 *
F_20 ( enum V_1 V_2 ,
unsigned char * V_6 , unsigned int V_7 )
{
struct V_4 * V_5 ;
int V_10 ;
const struct V_3 * type ;
V_10 = F_1 ( V_2 , & type , & V_5 , V_6 , V_7 ) ;
if ( V_10 )
return F_21 ( V_10 ) ;
return (struct V_29 * ) V_5 ;
}
int F_22 ( struct V_29 * V_30 ,
struct V_31 * V_31 , unsigned int V_32 ,
unsigned int V_33 )
{
struct V_4 * V_5 = ( void * ) V_30 ;
struct V_25 V_26 ;
F_23 ( & V_26 , 1 ) ;
F_24 ( & V_26 , V_31 , V_33 , V_32 & ~ V_34 ) ;
F_18 ( V_5 , & V_26 , NULL , V_26 . V_28 ) ;
return F_25 ( V_5 ) ;
}
int F_26 ( struct V_29 * V_30 ,
const void * V_21 , unsigned int V_22 )
{
struct V_4 * V_5 = ( void * ) V_30 ;
struct V_25 V_26 ;
F_17 ( & V_26 , V_21 , V_22 ) ;
F_18 ( V_5 , & V_26 , NULL , V_26 . V_28 ) ;
return F_25 ( V_5 ) ;
}
int F_27 ( struct V_29 * V_30 ,
unsigned char * V_23 , unsigned int * V_24 )
{
int V_10 ;
struct V_4 * V_5 = ( void * ) V_30 ;
int V_35 = F_28 ( F_16 ( V_5 ) ) ;
if ( ! V_23 || ! V_24 ) {
V_10 = 0 ;
goto V_36;
}
if ( * V_24 < V_35 ) {
V_10 = - V_37 ;
goto V_36;
}
F_18 ( V_5 , NULL , V_23 , 0 ) ;
V_10 = F_29 ( V_5 ) ;
if ( ! V_10 )
* V_24 = V_35 ;
V_36:
F_8 ( F_16 ( V_5 ) ) ;
F_14 ( V_5 ) ;
return V_10 ;
}
static void F_30 ( enum V_1 V_2 )
{
int V_22 = F_31 ( V_38 , 1048576UL ) ;
void * V_21 ;
unsigned long V_39 , V_40 ;
int V_41 , V_10 = 0 ;
struct V_31 * V_31 ;
unsigned char V_23 [ V_42 ] ;
unsigned int V_24 = sizeof( V_23 ) ;
V_31 = F_32 ( V_16 ) ;
if ( ! V_31 ) {
V_10 = - V_17 ;
goto V_43;
}
V_21 = F_33 ( V_31 ) ;
memset ( V_21 , 0xAD , V_38 ) ;
F_34 ( V_31 ) ;
for ( V_39 = V_44 , V_40 = V_39 + F_35 ( V_45 ) ,
V_41 = 0 ; F_36 ( V_44 , V_40 ) ; V_41 ++ ) {
struct V_29 * V_30 ;
int V_46 ;
V_30 = F_20 ( V_2 , NULL , 0 ) ;
if ( F_4 ( V_30 ) ) {
V_10 = F_6 ( V_30 ) ;
break;
}
for ( V_46 = 0 ; V_46 < V_22 / V_38 ; V_46 ++ ) {
V_10 = F_22 ( V_30 , V_31 , 0 ,
V_38 ) ;
if ( V_10 )
break;
}
V_10 = F_27 ( V_30 , V_23 , & V_24 ) ;
if ( V_10 )
break;
}
V_40 = V_44 ;
F_37 ( V_31 ) ;
V_43:
if ( V_10 ) {
V_20 [ V_2 ] = V_10 ;
F_5 ( V_15 , L_5 ,
F_38 ( V_2 ) , V_10 ) ;
} else {
unsigned long V_47 ;
V_47 = ( ( V_41 * V_22 / F_39 ( V_40 - V_39 ) ) *
1000 ) / ( 1024 * 1024 ) ;
V_20 [ V_2 ] = ( int ) V_47 ;
F_5 ( V_48 , L_6 ,
F_38 ( V_2 ) ,
V_20 [ V_2 ] ) ;
}
}
int F_40 ( enum V_1 V_2 )
{
if ( V_2 < V_11 )
return V_20 [ V_2 ] ;
return - V_49 ;
}
static int F_41 ( void )
{
enum V_1 V_2 ;
for ( V_2 = 0 ; V_2 < V_11 ; V_2 ++ )
F_30 ( V_2 ) ;
return 0 ;
}
int F_42 ( void )
{
F_43 ( L_7 ) ;
V_50 = F_44 () ;
F_41 () ;
return 0 ;
}
void F_45 ( void )
{
if ( V_50 == 0 )
F_46 () ;
}
