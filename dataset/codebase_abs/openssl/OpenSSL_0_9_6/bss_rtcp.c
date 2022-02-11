T_1 * F_1 ( void )
{
return ( & V_1 ) ;
}
static int F_2 ( T_2 V_2 , char * V_3 , int V_4 , int * V_5 )
{
int V_6 ;
struct V_7 V_8 ;
V_6 = F_3 ( 0 , V_2 , V_9 , & V_8 , 0 , 0 ,
V_3 , V_4 , 0 , 0 , 0 , 0 ) ;
if ( ( V_6 & 1 ) == 1 ) V_6 = V_8 . V_6 ;
if ( ( V_6 & 1 ) == 1 ) * V_5 = V_8 . V_10 ;
return V_6 ;
}
static int F_4 ( T_2 V_2 , char * V_3 , int V_5 )
{
int V_6 ;
struct V_7 V_8 ;
V_6 = F_3 ( 0 , V_2 , V_11 , & V_8 , 0 , 0 ,
V_3 , V_5 , 0 , 0 , 0 , 0 ) ;
if ( ( V_6 & 1 ) == 1 ) V_6 = V_8 . V_6 ;
return V_6 ;
}
static int F_5 ( T_3 * V_12 )
{
struct V_13 * V_14 ;
V_12 -> V_15 = 1 ;
V_12 -> V_16 = 0 ;
V_12 -> V_17 = 0 ;
V_12 -> V_18 = F_6 ( sizeof( struct V_13 ) ) ;
V_14 = (struct V_13 * ) V_12 -> V_18 ;
V_14 -> V_19 = 0 ;
V_14 -> V_20 = 0 ;
return ( 1 ) ;
}
static int F_7 ( T_3 * V_21 )
{
if ( V_21 == NULL ) return ( 0 ) ;
if ( V_21 -> V_18 ) F_8 ( V_21 -> V_18 ) ;
V_21 -> V_18 = NULL ;
return ( 1 ) ;
}
static int F_9 ( T_3 * V_22 , char * V_23 , int V_24 )
{
int V_6 , V_5 ;
struct V_13 * V_14 ;
V_14 = (struct V_13 * ) V_22 -> V_18 ;
if ( V_14 -> V_20 < V_14 -> V_19 ) {
V_5 = V_14 -> V_19 - V_14 -> V_20 ;
if ( V_5 > V_24 ) V_5 = V_24 ;
memmove ( V_23 , & V_14 -> V_25 . V_26 [ V_14 -> V_20 ] , V_5 ) ;
V_14 -> V_20 += V_5 ;
return V_5 ;
}
V_14 -> V_25 . V_27 = 'R' ;
V_14 -> V_25 . V_28 = 'G' ;
V_14 -> V_25 . V_5 = sizeof( V_14 -> V_25 . V_26 ) ;
V_6 = F_4 ( V_22 -> V_16 , ( char * ) & V_14 -> V_25 , V_29 ) ;
if ( ( V_6 & 1 ) == 0 ) {
return - 1 ;
}
V_14 -> V_20 = V_14 -> V_19 = 0 ;
V_6 = F_2 ( V_22 -> V_16 , ( char * ) & V_14 -> V_25 , sizeof( V_14 -> V_25 ) , & V_5 ) ;
if ( ( V_6 & 1 ) == 0 ) V_5 = - 1 ;
if ( V_14 -> V_25 . V_27 != 'R' || V_14 -> V_25 . V_28 != 'C' ) {
V_5 = - 1 ;
}
V_14 -> V_19 = V_5 - V_29 ;
if ( V_14 -> V_20 < V_14 -> V_19 ) {
V_5 = V_14 -> V_19 - V_14 -> V_20 ;
if ( V_5 > V_24 ) V_5 = V_24 ;
memmove ( V_23 , V_14 -> V_25 . V_26 , V_5 ) ;
V_14 -> V_20 += V_5 ;
return V_5 ;
}
return V_5 ;
}
static int F_10 ( T_3 * V_22 , const char * V_30 , int V_31 )
{
int V_6 , V_32 , V_33 , V_5 ;
struct V_13 * V_14 ;
V_14 = (struct V_13 * ) V_22 -> V_18 ;
for ( V_32 = 0 ; V_32 < V_31 ; V_32 += V_33 ) {
V_33 = V_31 - V_32 ;
if ( V_33 > sizeof( V_14 -> V_25 . V_26 ) ) V_33 = sizeof( V_14 -> V_25 . V_26 ) ;
V_14 -> V_25 . V_27 = 'R' ;
V_14 -> V_25 . V_28 = 'P' ;
V_14 -> V_25 . V_5 = V_33 ;
memmove ( V_14 -> V_25 . V_26 , & V_30 [ V_32 ] , V_33 ) ;
V_6 = F_4 ( V_22 -> V_16 , ( char * ) & V_14 -> V_25 , V_33 + V_29 ) ;
if ( ( V_6 & 1 ) == 0 ) { V_32 = - 1 ; break; }
V_6 = F_2 ( V_22 -> V_16 , ( char * ) & V_14 -> V_25 , sizeof( V_14 -> V_25 ) , & V_5 ) ;
if ( ( ( V_6 & 1 ) == 0 ) || ( V_5 < V_29 ) ) { V_32 = - 1 ; break; }
if ( ( V_14 -> V_25 . V_27 != 'R' ) || ( V_14 -> V_25 . V_28 != 'C' ) ) {
printf ( L_1 ,
V_14 -> V_25 . V_27 , V_14 -> V_25 . V_28 ) ;
}
}
return ( V_32 ) ;
}
static long F_11 ( T_3 * V_22 , int V_34 , long V_16 , void * V_18 )
{
long V_35 = 1 ;
switch ( V_34 )
{
case V_36 :
case V_37 :
V_35 = 1 ;
break;
case V_38 :
V_22 -> V_16 = V_16 ;
V_35 = 1 ;
break;
case V_39 :
case V_40 :
case V_41 :
V_35 = 1 ;
break;
case V_42 :
case V_43 :
case V_44 :
case V_45 :
case V_46 :
default:
V_35 = 0 ;
break;
}
return ( V_35 ) ;
}
static int F_12 ( T_3 * V_47 , char * V_48 , int V_49 )
{
return ( 0 ) ;
}
static int F_13 ( T_3 * V_47 , const char * V_50 )
{
int V_5 ;
if ( V_50 == NULL ) return ( 0 ) ;
V_5 = strlen ( V_50 ) ;
if ( V_5 == 0 ) return ( 0 ) ;
return F_10 ( V_47 , V_50 , V_5 ) ;
}
