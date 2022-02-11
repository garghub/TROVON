const char * F_1 ( struct V_1 * V_2 )
{
return V_2 -> V_3 ;
}
unsigned int F_2 ( struct V_1 * V_2 )
{
return V_2 -> V_4 ;
}
struct V_1 * F_3 ( struct V_1 * V_2 )
{
if ( ! V_2 )
return V_5 ;
return V_2 -> V_6 ;
}
void F_4 ( struct V_1 * V_2 )
{
V_2 -> V_6 = V_5 ;
V_5 = V_2 ;
}
void F_5 ( struct V_1 * V_7 , struct V_1 * V_2 )
{
if ( V_7 )
V_7 -> V_6 = V_2 -> V_6 ;
else
V_5 = V_2 -> V_6 ;
}
static int F_6 ( struct V_1 * V_2 , unsigned int type )
{
return V_2 -> V_8 [ type ] ? 1 : 0 ;
}
static unsigned int F_7 ( struct V_1 * V_2 )
{
unsigned int V_9 ;
unsigned int V_10 = 0 ;
for ( V_9 = 0 ; V_9 < V_11 ; V_9 ++ ) {
if ( F_6 ( V_2 , V_9 ) )
V_10 ++ ;
}
return V_10 ;
}
void F_8 ( struct V_1 * V_2 )
{
struct V_12 * V_13 ;
unsigned int V_14 ;
unsigned int V_15 ;
for ( V_14 = 0 ; V_14 < V_2 -> V_16 ; V_14 ++ ) {
V_13 = V_2 -> V_17 [ V_14 ] -> V_18 ;
for ( V_15 = 0 ; V_15 < V_11 ; V_15 ++ ) {
if ( ! F_6 ( V_2 , V_15 ) )
continue;
memset ( V_13 -> V_19 , 0 ,
sizeof( V_20 ) * V_13 -> V_21 ) ;
V_13 ++ ;
}
}
}
int F_9 ( struct V_1 * V_22 , struct V_1 * V_23 )
{
return ( V_22 -> V_24 == V_23 -> V_24 ) ;
}
void F_10 ( struct V_1 * V_25 , struct V_1 * V_26 )
{
struct V_12 * V_27 ;
struct V_12 * V_28 ;
unsigned int V_14 ;
unsigned int V_15 ;
unsigned int V_29 ;
for ( V_14 = 0 ; V_14 < V_26 -> V_16 ; V_14 ++ ) {
V_27 = V_25 -> V_17 [ V_14 ] -> V_18 ;
V_28 = V_26 -> V_17 [ V_14 ] -> V_18 ;
for ( V_15 = 0 ; V_15 < V_11 ; V_15 ++ ) {
if ( ! F_6 ( V_26 , V_15 ) )
continue;
for ( V_29 = 0 ; V_29 < V_28 -> V_21 ; V_29 ++ )
V_27 -> V_19 [ V_29 ] +=
V_28 -> V_19 [ V_29 ] ;
V_27 ++ ;
V_28 ++ ;
}
}
}
struct V_1 * F_11 ( struct V_1 * V_2 )
{
struct V_1 * V_30 ;
struct V_12 * V_27 ;
struct V_12 * V_28 ;
unsigned int V_31 ;
unsigned int V_14 ;
unsigned int V_15 ;
T_1 V_32 ;
T_1 V_33 ;
V_30 = F_12 ( V_2 , sizeof( * V_30 ) , V_34 ) ;
if ( ! V_30 )
return NULL ;
V_30 -> V_6 = NULL ;
V_30 -> V_3 = NULL ;
V_30 -> V_17 = NULL ;
V_30 -> V_3 = F_13 ( V_2 -> V_3 , V_34 ) ;
if ( ! V_30 -> V_3 )
goto V_35;
V_30 -> V_17 = F_14 ( V_2 -> V_16 ,
sizeof( struct V_36 * ) , V_34 ) ;
if ( ! V_30 -> V_17 )
goto V_35;
V_31 = F_7 ( V_2 ) ;
V_32 = sizeof( struct V_36 ) ;
V_32 += sizeof( struct V_12 ) * V_31 ;
for ( V_14 = 0 ; V_14 < V_2 -> V_16 ; V_14 ++ ) {
V_30 -> V_17 [ V_14 ] = F_15 ( V_32 , V_34 ) ;
if ( ! V_30 -> V_17 [ V_14 ] )
goto V_35;
* ( V_30 -> V_17 [ V_14 ] ) = * ( V_2 -> V_17 [ V_14 ] ) ;
V_28 = V_2 -> V_17 [ V_14 ] -> V_18 ;
V_27 = V_30 -> V_17 [ V_14 ] -> V_18 ;
for ( V_15 = 0 ; V_15 < V_31 ; V_15 ++ ) {
V_33 = sizeof( V_20 ) * V_28 -> V_21 ;
V_27 -> V_19 = F_16 ( V_33 ) ;
if ( ! V_27 -> V_19 )
goto V_35;
V_27 -> V_21 = V_28 -> V_21 ;
memcpy ( V_27 -> V_19 , V_28 -> V_19 , V_33 ) ;
V_28 ++ ;
V_27 ++ ;
}
}
return V_30 ;
V_35:
F_17 ( V_30 ) ;
return NULL ;
}
void F_17 ( struct V_1 * V_2 )
{
unsigned int V_31 ;
unsigned int V_14 ;
unsigned int V_15 ;
struct V_12 * V_13 ;
if ( ! V_2 -> V_17 )
goto V_37;
V_31 = F_7 ( V_2 ) ;
for ( V_14 = 0 ; V_14 < V_2 -> V_16 ; V_14 ++ ) {
if ( ! V_2 -> V_17 [ V_14 ] )
continue;
V_13 = V_2 -> V_17 [ V_14 ] -> V_18 ;
for ( V_15 = 0 ; V_15 < V_31 ; V_15 ++ , V_13 ++ )
F_18 ( V_13 -> V_19 ) ;
F_19 ( V_2 -> V_17 [ V_14 ] ) ;
}
V_37:
F_19 ( V_2 -> V_17 ) ;
F_19 ( V_2 -> V_3 ) ;
F_19 ( V_2 ) ;
}
static T_1 F_20 ( void * V_38 , T_1 V_39 , T_2 V_40 )
{
T_2 * V_41 ;
if ( V_38 ) {
V_41 = V_38 + V_39 ;
* V_41 = V_40 ;
}
return sizeof( * V_41 ) ;
}
static T_1 F_21 ( void * V_38 , T_1 V_39 , T_3 V_40 )
{
T_2 * V_41 ;
if ( V_38 ) {
V_41 = V_38 + V_39 ;
V_41 [ 0 ] = ( V_40 & 0xffffffffUL ) ;
V_41 [ 1 ] = ( V_40 >> 32 ) ;
}
return sizeof( * V_41 ) * 2 ;
}
static T_1 F_22 ( char * V_38 , struct V_1 * V_2 )
{
struct V_36 * V_42 ;
struct V_12 * V_13 ;
unsigned int V_14 ;
unsigned int V_15 ;
unsigned int V_43 ;
T_1 V_44 = 0 ;
V_44 += F_20 ( V_38 , V_44 , V_45 ) ;
V_44 += F_20 ( V_38 , V_44 , V_2 -> V_4 ) ;
V_44 += F_20 ( V_38 , V_44 , V_2 -> V_24 ) ;
for ( V_14 = 0 ; V_14 < V_2 -> V_16 ; V_14 ++ ) {
V_42 = V_2 -> V_17 [ V_14 ] ;
V_44 += F_20 ( V_38 , V_44 , V_46 ) ;
V_44 += F_20 ( V_38 , V_44 , V_47 ) ;
V_44 += F_20 ( V_38 , V_44 , V_42 -> V_48 ) ;
V_44 += F_20 ( V_38 , V_44 , V_42 -> V_49 ) ;
V_44 += F_20 ( V_38 , V_44 , V_42 -> V_50 ) ;
V_13 = V_42 -> V_18 ;
for ( V_15 = 0 ; V_15 < V_11 ; V_15 ++ ) {
if ( ! F_6 ( V_2 , V_15 ) )
continue;
V_44 += F_20 ( V_38 , V_44 ,
F_23 ( V_15 ) ) ;
V_44 += F_20 ( V_38 , V_44 , V_13 -> V_21 * 2 ) ;
for ( V_43 = 0 ; V_43 < V_13 -> V_21 ; V_43 ++ ) {
V_44 += F_21 ( V_38 , V_44 ,
V_13 -> V_19 [ V_43 ] ) ;
}
V_13 ++ ;
}
}
return V_44 ;
}
struct V_51 * F_24 ( struct V_1 * V_2 )
{
struct V_51 * V_52 ;
V_52 = F_15 ( sizeof( struct V_51 ) , V_34 ) ;
if ( ! V_52 )
goto V_35;
V_52 -> V_2 = V_2 ;
V_52 -> V_53 = F_22 ( NULL , V_2 ) ;
V_52 -> V_38 = F_16 ( V_52 -> V_53 ) ;
if ( ! V_52 -> V_38 )
goto V_35;
F_22 ( V_52 -> V_38 , V_2 ) ;
return V_52 ;
V_35:
F_19 ( V_52 ) ;
return NULL ;
}
void F_25 ( struct V_51 * V_52 )
{
F_18 ( V_52 -> V_38 ) ;
F_19 ( V_52 ) ;
}
struct V_1 * F_26 ( struct V_51 * V_52 )
{
return V_52 -> V_2 ;
}
void F_27 ( struct V_51 * V_52 )
{
V_52 -> V_44 = 0 ;
}
int F_28 ( struct V_51 * V_52 )
{
if ( V_52 -> V_44 < V_52 -> V_53 )
V_52 -> V_44 += V_54 ;
if ( V_52 -> V_44 >= V_52 -> V_53 )
return - V_55 ;
return 0 ;
}
int F_29 ( struct V_51 * V_52 , struct V_56 * V_57 )
{
T_1 V_58 ;
if ( V_52 -> V_44 >= V_52 -> V_53 )
return - V_55 ;
V_58 = V_54 ;
if ( V_52 -> V_44 + V_58 > V_52 -> V_53 )
V_58 = V_52 -> V_53 - V_52 -> V_44 ;
F_30 ( V_57 , V_52 -> V_38 + V_52 -> V_44 , V_58 ) ;
return 0 ;
}
