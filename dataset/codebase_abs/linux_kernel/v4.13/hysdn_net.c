static int
F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
T_1 * V_5 = V_2 -> V_6 ;
int V_7 ;
F_2 ( V_2 ) ;
if ( ! V_5 -> V_8 [ 0 ] ) {
for ( V_7 = 0 ; V_7 < V_9 ; V_7 ++ )
V_2 -> V_10 [ V_7 ] = 0xfc ;
if ( ( V_4 = V_2 -> V_11 ) != NULL ) {
struct V_12 * V_13 = V_4 -> V_14 ;
if ( V_13 != NULL )
memcpy ( V_2 -> V_10 + ( V_9 - sizeof( V_13 -> V_15 ) ) , & V_13 -> V_15 , sizeof( V_13 -> V_15 ) ) ;
}
} else
memcpy ( V_2 -> V_10 , V_5 -> V_8 , V_9 ) ;
return ( 0 ) ;
}
static void
F_3 ( struct V_16 * V_17 )
{
while ( V_17 -> V_18 ) {
F_4 ( V_17 -> V_19 [ V_17 -> V_20 ++ ] ) ;
if ( V_17 -> V_20 >= V_21 )
V_17 -> V_20 = 0 ;
V_17 -> V_18 -- ;
}
}
static int
F_5 ( struct V_1 * V_2 )
{
F_6 ( V_2 ) ;
F_3 ( (struct V_16 * ) V_2 ) ;
return ( 0 ) ;
}
static T_2
F_7 ( struct V_22 * V_23 , struct V_1 * V_2 )
{
struct V_16 * V_24 = (struct V_16 * ) V_2 ;
F_8 ( & V_24 -> V_25 ) ;
V_24 -> V_19 [ V_24 -> V_26 ++ ] = V_23 ;
if ( V_24 -> V_26 >= V_21 )
V_24 -> V_26 = 0 ;
V_24 -> V_18 ++ ;
F_9 ( V_2 ) ;
if ( V_24 -> V_18 >= V_21 )
F_6 ( V_2 ) ;
F_10 ( & V_24 -> V_25 ) ;
if ( V_24 -> V_18 <= 3 ) {
F_11 ( & ( ( T_1 * ) V_2 -> V_6 ) -> V_27 ) ;
}
return V_28 ;
}
void
F_12 ( T_1 * V_5 )
{
struct V_16 * V_24 = V_5 -> V_29 ;
if ( ! V_24 )
return;
if ( ! V_24 -> V_18 )
return;
V_24 -> V_2 -> V_30 . V_31 ++ ;
V_24 -> V_2 -> V_30 . V_32 += V_24 -> V_19 [ V_24 -> V_20 ] -> V_33 ;
F_4 ( V_24 -> V_19 [ V_24 -> V_20 ++ ] ) ;
if ( V_24 -> V_20 >= V_21 )
V_24 -> V_20 = 0 ;
if ( V_24 -> V_18 -- == V_21 )
F_2 ( (struct V_1 * ) V_24 ) ;
}
void
F_13 ( T_1 * V_5 , unsigned char * V_34 , unsigned short V_33 )
{
struct V_16 * V_24 = V_5 -> V_29 ;
struct V_1 * V_2 ;
struct V_22 * V_23 ;
if ( ! V_24 )
return;
V_2 = V_24 -> V_2 ;
V_2 -> V_30 . V_35 += V_33 ;
V_23 = F_14 ( V_33 ) ;
if ( V_23 == NULL ) {
F_15 ( V_36 L_1 ,
V_2 -> V_37 ) ;
V_2 -> V_30 . V_38 ++ ;
return;
}
F_16 ( V_23 , V_34 , V_33 ) ;
V_23 -> V_39 = F_17 ( V_23 , V_2 ) ;
V_2 -> V_30 . V_40 ++ ;
F_18 ( V_23 ) ;
}
struct V_22 *
F_19 ( T_1 * V_5 )
{
struct V_16 * V_24 = V_5 -> V_29 ;
if ( ! V_24 )
return ( NULL ) ;
if ( ! V_24 -> V_18 )
return ( NULL ) ;
return ( V_24 -> V_19 [ V_24 -> V_20 ] ) ;
}
int
F_20 ( T_1 * V_5 )
{
struct V_1 * V_2 ;
int V_7 ;
struct V_16 * V_24 ;
if ( ! V_5 ) {
F_15 ( V_41 L_2 ) ;
return ( - V_42 ) ;
}
F_21 ( V_5 ) ;
V_2 = F_22 ( sizeof( struct V_16 ) ) ;
if ( ! V_2 ) {
F_15 ( V_41 L_3 ) ;
return ( - V_42 ) ;
}
V_24 = F_23 ( V_2 ) ;
V_24 -> V_2 = V_2 ;
V_2 -> V_43 = & V_44 ;
F_24 ( & ( (struct V_16 * ) V_2 ) -> V_25 ) ;
V_2 -> V_45 = V_5 -> V_46 ;
V_2 -> V_47 = V_5 -> V_47 ;
V_2 -> V_43 = & V_44 ;
if ( ( V_7 = F_25 ( V_2 ) ) ) {
F_15 ( V_41 L_4 ) ;
F_26 ( V_2 ) ;
return ( V_7 ) ;
}
V_2 -> V_6 = V_5 ;
V_5 -> V_29 = V_2 ;
if ( V_5 -> V_48 & V_49 )
F_27 ( V_5 , L_5 ) ;
return ( 0 ) ;
}
int
F_21 ( T_1 * V_5 )
{
struct V_1 * V_2 = V_5 -> V_29 ;
if ( ! V_2 )
return ( 0 ) ;
V_5 -> V_29 = NULL ;
F_5 ( V_2 ) ;
F_3 ( (struct V_16 * ) V_2 ) ;
F_28 ( V_2 ) ;
F_26 ( V_2 ) ;
if ( V_5 -> V_48 & V_49 )
F_27 ( V_5 , L_6 ) ;
return ( 0 ) ;
}
char *
F_29 ( T_1 * V_5 )
{
struct V_1 * V_2 = V_5 -> V_29 ;
if ( ! V_2 )
return ( L_7 ) ;
return ( V_2 -> V_37 ) ;
}
