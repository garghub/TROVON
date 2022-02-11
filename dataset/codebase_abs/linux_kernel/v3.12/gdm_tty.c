static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 , struct V_3 , V_2 ) ;
F_3 ( & V_4 ) ;
V_5 [ V_3 -> V_6 ] [ V_3 -> V_7 ] = NULL ;
F_4 ( & V_4 ) ;
F_5 ( V_3 ) ;
}
static int F_6 ( struct V_8 * V_9 , struct V_10 * V_11 )
{
struct V_3 * V_3 = NULL ;
int V_12 ;
int V_13 ;
int V_14 ;
V_14 = V_15 ;
for ( V_13 = 0 ; V_13 < V_16 ; V_13 ++ ) {
if ( ! strcmp ( V_11 -> V_9 -> V_17 , V_18 [ V_13 ] ) ) {
V_14 = V_11 -> V_6 ;
break;
}
}
if ( V_14 == V_15 )
return - V_19 ;
F_3 ( & V_4 ) ;
V_3 = V_5 [ V_13 ] [ V_14 ] ;
if ( V_3 == NULL ) {
F_4 ( & V_4 ) ;
return - V_19 ;
}
F_7 ( & V_3 -> V_2 ) ;
V_12 = F_8 ( V_9 , V_11 ) ;
if ( V_12 ) {
F_9 ( & V_3 -> V_2 ) ;
F_4 ( & V_4 ) ;
return V_12 ;
}
V_11 -> V_20 = V_3 ;
F_4 ( & V_4 ) ;
return 0 ;
}
static int F_10 ( struct V_10 * V_11 , struct V_21 * V_22 )
{
struct V_3 * V_3 = V_11 -> V_20 ;
return F_11 ( & V_3 -> V_2 , V_11 , V_22 ) ;
}
static void F_12 ( struct V_10 * V_11 )
{
struct V_3 * V_3 = V_11 -> V_20 ;
F_9 ( & V_3 -> V_2 ) ;
}
static void F_13 ( struct V_10 * V_11 )
{
struct V_3 * V_3 = V_11 -> V_20 ;
F_14 ( & V_3 -> V_2 ) ;
}
static void F_15 ( struct V_10 * V_11 , struct V_21 * V_22 )
{
struct V_3 * V_3 = V_11 -> V_20 ;
F_16 ( & V_3 -> V_2 , V_11 , V_22 ) ;
}
static int F_17 ( void * V_23 ,
int V_24 ,
int V_6 ,
struct V_25 * V_25 ,
int V_26 )
{
struct V_3 * V_3 = V_25 -> V_3 [ V_6 ] ;
if ( ! F_18 ( V_3 ) ) {
if ( V_26 == V_27 )
F_19 ( V_3 , F_17 ) ;
return V_28 ;
}
if ( V_23 && V_24 ) {
if ( F_20 ( & V_3 -> V_2 , V_24 ) == V_24 ) {
F_21 ( & V_3 -> V_2 , V_23 , V_24 ) ;
F_22 ( & V_3 -> V_2 ) ;
} else {
return V_29 ;
}
}
if ( V_26 == V_27 )
F_19 ( V_3 , F_17 ) ;
return 0 ;
}
static void F_23 ( void * V_30 )
{
struct V_3 * V_3 = (struct V_3 * ) V_30 ;
if ( ! F_18 ( V_3 ) )
return;
F_24 ( & V_3 -> V_2 ) ;
}
static int F_25 ( struct V_10 * V_11 , const unsigned char * V_31 , int V_24 )
{
struct V_3 * V_3 = V_11 -> V_20 ;
int V_32 = V_24 ;
int V_33 = 0 ;
int V_34 = 0 ;
if ( ! F_18 ( V_3 ) )
return - V_19 ;
if ( ! V_24 )
return 0 ;
while ( 1 ) {
V_34 = V_32 > V_35 ? V_35 : V_32 ;
F_26 ( V_3 ,
( void * ) ( V_31 + V_33 ) ,
V_34 ,
V_3 -> V_6 ,
F_23 ,
V_3
) ;
V_33 += V_34 ;
V_32 -= V_34 ;
if ( V_32 <= 0 )
break;
}
return V_24 ;
}
static int F_27 ( struct V_10 * V_11 )
{
struct V_3 * V_3 = V_11 -> V_20 ;
if ( ! F_18 ( V_3 ) )
return - V_19 ;
return V_36 ;
}
int F_28 ( struct V_25 * V_25 , struct V_37 * V_37 )
{
struct V_3 * V_3 ;
int V_13 ;
int V_14 ;
for ( V_13 = 0 ; V_13 < V_16 ; V_13 ++ ) {
V_3 = F_29 ( sizeof( struct V_3 ) , V_38 ) ;
if ( ! V_3 )
return - V_39 ;
F_3 ( & V_4 ) ;
for ( V_14 = 0 ; V_14 < V_15 ; V_14 ++ ) {
if ( ! V_5 [ V_13 ] [ V_14 ] )
break;
}
if ( V_14 == V_15 ) {
F_5 ( V_3 ) ;
F_4 ( & V_4 ) ;
return - V_40 ;
}
V_5 [ V_13 ] [ V_14 ] = V_3 ;
F_4 ( & V_4 ) ;
V_25 -> V_3 [ V_13 ] = V_3 ;
F_30 ( & V_3 -> V_2 ) ;
V_3 -> V_2 . V_41 = & V_42 ;
V_3 -> V_6 = V_13 ;
V_3 -> V_7 = V_14 ;
V_3 -> V_25 = V_25 ;
F_31 ( & V_3 -> V_2 , V_43 [ V_13 ] , V_3 -> V_7 , V_37 ) ;
}
for ( V_13 = 0 ; V_13 < V_44 ; V_13 ++ )
F_19 ( V_3 , F_17 ) ;
return 0 ;
}
void F_32 ( struct V_25 * V_25 )
{
struct V_3 * V_3 ;
struct V_10 * V_11 ;
int V_13 ;
for ( V_13 = 0 ; V_13 < V_16 ; V_13 ++ ) {
V_3 = V_25 -> V_3 [ V_13 ] ;
if ( ! V_3 )
continue;
F_3 ( & V_4 ) ;
V_5 [ V_3 -> V_6 ] [ V_3 -> V_7 ] = NULL ;
F_4 ( & V_4 ) ;
V_11 = F_33 ( & V_3 -> V_2 ) ;
if ( V_11 ) {
F_34 ( V_11 ) ;
F_35 ( V_11 ) ;
}
F_36 ( V_43 [ V_13 ] , V_3 -> V_7 ) ;
F_9 ( & V_3 -> V_2 ) ;
}
}
int F_37 ( void )
{
struct V_8 * V_8 ;
int V_13 ;
int V_12 ;
for ( V_13 = 0 ; V_13 < V_16 ; V_13 ++ ) {
V_8 = F_38 ( V_15 ) ;
if ( ! V_8 )
return - V_39 ;
V_8 -> V_45 = V_46 ;
V_8 -> V_17 = V_18 [ V_13 ] ;
V_8 -> V_47 = V_48 [ V_13 ] ;
V_8 -> V_49 = V_50 ;
V_8 -> type = V_51 ;
V_8 -> V_52 = V_53 ;
V_8 -> V_54 = V_55 | V_56 ;
V_8 -> V_57 = V_58 ;
V_8 -> V_57 . V_59 = V_60 | V_61 | V_62 | V_63 ;
V_8 -> V_57 . V_64 = V_65 | V_66 | V_67 ;
F_39 ( V_8 , & V_68 ) ;
V_12 = F_40 ( V_8 ) ;
if ( V_12 ) {
F_41 ( V_8 ) ;
return V_12 ;
}
V_43 [ V_13 ] = V_8 ;
}
return V_12 ;
}
void F_42 ( void )
{
struct V_8 * V_8 ;
int V_13 ;
for ( V_13 = 0 ; V_13 < V_16 ; V_13 ++ ) {
V_8 = V_43 [ V_13 ] ;
if ( V_8 ) {
F_43 ( V_8 ) ;
F_41 ( V_8 ) ;
}
}
}
