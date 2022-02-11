static void F_1 ( struct V_1 * V_2 ,
enum V_3 V_3 )
{
F_2 ( V_3 ) ;
}
struct V_4 *
F_3 ( void * V_5 , unsigned short V_6 , unsigned short V_7 )
{
struct V_4 * V_8 ;
struct V_9 * V_10 ;
V_10 = (struct V_9 * ) V_5 ;
V_8 = ( (struct V_4 * ) ( ( V_11 ) V_10 + V_12 ) ) - 1 ;
V_8 -> V_10 = V_10 ;
V_8 -> V_13 = 0 ;
V_8 -> V_14 = 0 ;
V_8 -> V_15 = 0 ;
V_8 -> V_16 = NULL ;
V_8 -> V_17 = 0 ;
V_8 -> V_6 = V_6 ;
V_8 -> V_7 = V_7 ;
memset ( V_10 , 0 , sizeof( struct V_9 ) ) ;
V_10 -> V_18 = sizeof( struct V_9 ) ;
return V_8 ;
}
void *
F_4 ( struct V_4 * V_8 )
{
return V_8 -> V_10 ;
}
static int
F_5 ( struct V_4 * V_8 , int V_19 )
{
struct V_9 * V_10 ;
struct V_20 * V_21 ;
struct V_22 * V_22 ;
struct V_23 * V_23 ;
struct V_24 * V_24 ;
int V_25 ;
V_25 = sizeof( struct V_20 ) + V_19 ;
V_10 = V_8 -> V_10 ;
if ( ( V_26 - V_10 -> V_18 ) < V_25 )
return - V_27 ;
V_21 = (struct V_20 * ) ( ( V_11 ) V_10 + V_10 -> V_18 ) ;
memset ( V_21 , 0 , sizeof( struct V_20 ) ) ;
V_21 -> V_28 . V_18 = sizeof( struct V_20 ) ;
V_21 -> V_28 . type = V_29 ;
V_22 = & V_21 -> V_22 ;
V_22 -> V_28 . V_18 = sizeof( struct V_22 ) ;
V_22 -> V_28 . type = 1 ;
V_22 -> V_28 . V_30 = 0xD4C4C240 ;
V_22 -> V_28 . V_31 = 1 ;
V_23 = & V_22 -> V_23 ;
V_23 -> V_18 = sizeof( struct V_23 ) ;
V_23 -> type = 1 ;
V_24 = & V_22 -> V_24 ;
V_24 -> V_18 = sizeof( struct V_24 ) ;
V_24 -> type = 4 ;
V_24 -> V_32 = V_33 ;
V_8 -> V_34 = V_21 ;
V_8 -> V_16 = ( char * ) ( V_24 + 1 ) ;
V_8 -> V_17 = 0 ;
return 0 ;
}
static void
F_6 ( struct V_4 * V_8 )
{
struct V_9 * V_10 ;
struct V_20 * V_21 ;
V_10 = V_8 -> V_10 ;
V_21 = V_8 -> V_34 ;
V_21 -> V_28 . V_18 += V_8 -> V_17 ;
V_21 -> V_22 . V_28 . V_18 += V_8 -> V_17 ;
V_21 -> V_22 . V_24 . V_18 += V_8 -> V_17 ;
V_10 -> V_18 += V_21 -> V_28 . V_18 ;
V_8 -> V_14 ++ ;
V_8 -> V_15 += V_8 -> V_17 ;
V_8 -> V_16 = NULL ;
V_8 -> V_17 = 0 ;
V_8 -> V_34 = NULL ;
}
int
F_7 ( struct V_4 * V_8 , const unsigned char * V_21 , int V_35 )
{
int V_36 , V_37 ;
int V_38 ;
for ( V_37 = 0 ; V_37 < V_35 ; V_37 ++ ) {
switch ( V_21 [ V_37 ] ) {
case '\n' :
if ( V_8 -> V_16 == NULL ) {
V_38 = F_5 ( V_8 , 0 ) ;
if ( V_38 )
return V_37 ;
}
F_6 ( V_8 ) ;
break;
case '\a' :
if ( V_8 -> V_16 == NULL ) {
V_38 = F_5 ( V_8 ,
V_8 -> V_6 ) ;
if ( V_38 )
return V_37 ;
}
V_8 -> V_34 -> V_22 . V_23 . V_39 |=
V_40 ;
break;
case '\t' :
if ( V_8 -> V_16 == NULL ) {
V_38 = F_5 ( V_8 ,
V_8 -> V_6 ) ;
if ( V_38 )
return V_37 ;
}
do {
if ( V_8 -> V_17 >= V_8 -> V_6 )
break;
* V_8 -> V_16 ++ = 0x40 ;
V_8 -> V_17 ++ ;
} while ( V_8 -> V_17 % V_8 -> V_7 );
break;
case '\f' :
case '\v' :
if ( V_8 -> V_16 != NULL ) {
V_36 = V_8 -> V_17 ;
F_6 ( V_8 ) ;
V_38 = F_5 ( V_8 ,
V_8 -> V_6 ) ;
if ( V_38 )
return V_37 ;
memset ( V_8 -> V_16 , 0x40 , V_36 ) ;
V_8 -> V_16 += V_36 ;
V_8 -> V_17 = V_36 ;
} else {
V_38 = F_5 ( V_8 ,
V_8 -> V_6 ) ;
if ( V_38 )
return V_37 ;
F_6 ( V_8 ) ;
}
break;
case '\b' :
if ( V_8 -> V_16 != NULL &&
V_8 -> V_17 > 0 ) {
V_8 -> V_17 -- ;
V_8 -> V_16 -- ;
}
break;
case 0x00 :
if ( V_8 -> V_16 != NULL )
F_6 ( V_8 ) ;
V_37 = V_35 - 1 ;
break;
default:
if ( ! isprint ( V_21 [ V_37 ] ) )
break;
if ( V_8 -> V_16 == NULL ) {
V_38 = F_5 ( V_8 ,
V_8 -> V_6 ) ;
if ( V_38 )
return V_37 ;
}
* V_8 -> V_16 ++ = F_8 ( V_21 [ V_37 ] ) ;
V_8 -> V_17 ++ ;
break;
}
if ( V_8 -> V_16 != NULL &&
V_8 -> V_17 >= V_8 -> V_6 )
F_6 ( V_8 ) ;
}
return V_37 ;
}
int
F_9 ( struct V_4 * V_8 )
{
struct V_9 * V_10 ;
int V_35 ;
V_10 = V_8 -> V_10 ;
V_35 = V_26 - V_10 -> V_18 ;
if ( V_8 -> V_16 != NULL )
V_35 -= sizeof( struct V_20 ) + V_8 -> V_17 ;
return V_35 ;
}
int
F_10 ( struct V_4 * V_8 )
{
int V_35 ;
V_35 = V_8 -> V_15 ;
if ( V_8 -> V_16 != NULL )
V_35 += V_8 -> V_17 ;
return V_35 ;
}
void
F_11 ( struct V_4 * V_8 , unsigned short V_6 )
{
V_8 -> V_6 = V_6 ;
if ( V_8 -> V_16 != NULL &&
V_8 -> V_17 > V_8 -> V_6 )
F_6 ( V_8 ) ;
}
void
F_12 ( struct V_4 * V_8 , unsigned short V_7 )
{
V_8 -> V_7 = V_7 ;
}
int
F_13 ( void )
{
static int V_41 = 0 ;
int V_38 ;
if ( V_41 )
return 0 ;
V_38 = V_1 ( & V_42 ) ;
if ( V_38 == 0 )
V_41 = 1 ;
return V_38 ;
}
static void
F_14 ( struct V_43 * V_44 , void * V_45 )
{
int V_38 ;
struct V_4 * V_8 ;
struct V_9 * V_10 ;
V_8 = (struct V_4 * ) V_45 ;
V_10 = V_8 -> V_10 ;
if ( V_44 -> V_46 == V_47 ) {
if ( V_8 -> V_48 != NULL )
V_8 -> V_48 ( V_8 , - V_49 ) ;
return;
}
switch ( V_10 -> V_50 ) {
case 0x0020 :
V_38 = 0 ;
break;
case 0x0340 :
if ( ++ V_8 -> V_13 > V_51 ) {
V_38 = - V_49 ;
break;
}
if ( F_15 ( (struct V_9 * ) V_10 ) > 0 ) {
V_10 -> V_50 = 0x0000 ;
V_8 -> V_44 . V_46 = V_52 ;
V_38 = F_16 ( V_44 ) ;
if ( V_38 == 0 )
return;
} else
V_38 = 0 ;
break;
case 0x0040 :
case 0x05f0 :
if ( ++ V_8 -> V_13 > V_51 ) {
V_38 = - V_49 ;
break;
}
V_10 -> V_50 = 0x0000 ;
V_8 -> V_44 . V_46 = V_52 ;
V_38 = F_16 ( V_44 ) ;
if ( V_38 == 0 )
return;
break;
default:
if ( V_10 -> V_50 == 0x71f0 )
V_38 = - V_27 ;
else
V_38 = - V_53 ;
break;
}
if ( V_8 -> V_48 != NULL )
V_8 -> V_48 ( V_8 , V_38 ) ;
}
int
F_17 ( struct V_4 * V_8 ,
void (* V_48)( struct V_4 * , int ) )
{
if ( V_8 -> V_16 != NULL )
F_6 ( V_8 ) ;
if ( V_8 -> V_14 == 0 )
return - V_49 ;
V_8 -> V_44 . V_54 = V_55 ;
V_8 -> V_44 . V_46 = V_52 ;
V_8 -> V_44 . V_48 = F_14 ;
V_8 -> V_44 . V_56 = V_8 ;
V_8 -> V_44 . V_10 = V_8 -> V_10 ;
V_8 -> V_48 = V_48 ;
return F_16 ( & V_8 -> V_44 ) ;
}
