static void * F_1 ( struct V_1 * V_2 , T_1 * V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
return ( * V_3 < V_5 -> V_7 ) ? V_3 : NULL ;
}
static void * F_2 ( struct V_1 * V_2 , void * V_8 , T_1 * V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
return ( ++ ( * V_3 ) < V_5 -> V_7 ) ? V_3 : NULL ;
}
static void F_3 ( struct V_1 * V_2 , void * V_8 )
{
}
static void F_4 ( struct V_1 * V_2 , int V_9 )
{
while ( V_9 -- )
F_5 ( V_2 , L_1 ) ;
F_5 ( V_2 , L_2 ) ;
}
static int F_6 ( struct V_1 * V_2 , void * V_8 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
int V_9 = * ( T_1 * ) V_8 ;
static const char V_10 [] =
L_3 ;
if ( ! V_9 ) {
F_7 ( V_2 , V_10 ) ;
F_4 ( V_2 , sizeof( V_10 ) - 1 ) ;
}
if ( ! V_5 -> V_11 ) {
F_7 ( V_2 , L_4 , V_9 ) ;
} else {
struct V_12 * V_13 = F_8 ( V_5 , V_9 ) ;
F_7 ( V_2 , L_5 ,
V_9 , V_13 -> V_14 , V_13 -> V_15 , V_13 -> V_16 ,
V_13 -> V_17 , V_13 -> V_18 , V_13 -> V_19 ) ;
}
return 0 ;
}
static int F_9 ( struct V_1 * V_2 , void * V_8 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
int V_9 = * ( T_1 * ) V_8 ;
static const char V_20 [] =
L_6 ;
if ( ! V_9 ) {
F_7 ( V_2 , V_20 ) ;
F_4 ( V_2 , sizeof( V_20 ) - 1 ) ;
}
if ( ! V_5 -> V_11 ) {
F_7 ( V_2 , L_4 , V_9 ) ;
} else {
union V_21 * V_22 = F_10 ( V_5 , V_9 ) ;
F_7 ( V_2 ,
L_7 ,
V_9 , V_22 -> V_23 . V_24 , V_22 -> V_23 . V_25 , V_22 -> V_23 . V_26 ,
V_22 -> V_27 . V_28 , V_22 -> V_27 . V_16 , V_22 -> V_27 . V_29 ,
V_22 -> V_27 . V_30 , V_22 -> V_31 . V_32 ) ;
}
return 0 ;
}
static int F_11 ( struct V_33 * V_33 , struct V_34 * V_35 )
{
struct V_4 * V_5 = V_33 -> V_36 ;
struct V_37 * V_38 = V_5 -> V_38 ;
const struct V_39 * V_40 ;
int V_41 ;
if ( V_5 < V_38 -> V_42 . V_5 )
V_40 = & V_43 ;
else
V_40 = & V_44 ;
V_41 = F_12 ( V_35 , V_40 ) ;
if ( V_41 )
return V_41 ;
( (struct V_1 * ) V_35 -> V_45 ) -> V_6 = V_5 ;
return 0 ;
}
void F_13 ( struct V_37 * V_38 )
{
struct V_46 * V_47 = V_38 -> V_47 ;
char V_48 [ 16 ] ;
int V_9 ;
if ( ! V_47 -> V_49 )
return;
sprintf ( V_48 , L_8 , V_38 -> V_50 ) ;
V_38 -> V_51 = F_14 ( V_48 , V_47 -> V_49 ) ;
if ( ! V_38 -> V_51 )
return;
for ( V_9 = 0 ; V_9 < V_38 -> V_52 . V_7 ; V_9 ++ ) {
struct V_4 * V_5 = & V_38 -> V_52 . V_5 [ V_9 ] ;
sprintf ( V_48 , L_9 , V_5 -> V_53 ) ;
F_15 ( V_48 , 0600 ,
V_38 -> V_51 , V_5 ,
& V_54 ) ;
}
for ( V_9 = 0 ; V_9 < V_38 -> V_42 . V_7 ; V_9 ++ ) {
struct V_4 * V_5 = & V_38 -> V_42 . V_5 [ V_9 ] ;
sprintf ( V_48 , L_10 , V_5 -> V_53 ) ;
F_15 ( V_48 , 0600 ,
V_38 -> V_51 , V_5 ,
& V_54 ) ;
}
}
void F_16 ( struct V_37 * V_38 )
{
struct V_46 * V_47 = V_38 -> V_47 ;
if ( V_47 -> V_49 )
F_17 ( V_38 -> V_51 ) ;
V_38 -> V_51 = NULL ;
}
void F_18 ( struct V_46 * V_47 )
{
const char * V_48 = F_19 ( V_47 -> V_55 ) ;
if ( V_56 )
V_47 -> V_49 = F_14 ( V_48 , V_56 ) ;
}
void F_20 ( struct V_46 * V_47 )
{
if ( V_56 )
F_17 ( V_47 -> V_49 ) ;
V_47 -> V_49 = NULL ;
}
void F_21 ( void )
{
V_56 = F_14 ( V_57 , NULL ) ;
}
void F_22 ( void )
{
F_17 ( V_56 ) ;
V_56 = NULL ;
}
