static int F_1 ( struct V_1 * V_2 ,
unsigned char * V_3 , int V_4 ,
unsigned char * V_5 , int V_6 )
{
int V_7 = 0 ;
F_2 () ;
if ( V_3 != NULL ) {
V_7 = F_3 ( V_2 -> V_8 ,
F_4 ( V_2 -> V_8 , 0 ) ,
V_9 ,
V_10 | V_11 |
V_12 ,
V_2 -> V_13 ,
0 ,
V_3 , V_4 ,
V_14 ) ;
if ( V_7 < 0 ) {
F_5 ( V_15 , L_1 ,
V_7 ) ;
return V_7 ;
}
if ( V_7 != V_4 ) {
F_5 ( V_15 , L_2 ,
V_7 , V_4 ) ;
return - 1 ;
}
}
if ( V_5 != NULL ) {
#ifdef F_6
F_5 ( V_15 , L_3 , V_6 ) ;
#endif
V_7 = F_3 ( V_2 -> V_8 ,
F_7 ( V_2 -> V_8 , 0 ) ,
V_16 ,
V_17 | V_11 |
V_12 ,
V_2 -> V_13 ,
0 ,
V_5 , V_6 ,
V_18 ) ;
if ( V_7 < 0 ) {
F_5 ( V_15 , L_4 ,
V_7 ) ;
return V_7 ;
}
#ifdef F_6
F_5 ( V_15 , L_5 , V_6 ) ;
#endif
}
F_8 () ;
return V_7 ;
}
static int F_9 ( struct V_1 * V_2 ,
unsigned char * V_3 ,
int V_4 ,
int V_19 )
{
int V_7 = 0 , V_20 ;
V_7 = F_10 ( V_2 -> V_8 ,
F_11 ( V_2 -> V_8 , 1 ) ,
V_3 , V_4 , & V_20 , 200 ) ;
if ( V_7 ) {
F_5 ( V_15 , L_6 , V_7 ) ;
return V_7 ;
}
if ( V_20 != V_4 ) {
F_5 ( V_15 , L_2 ,
V_20 , V_4 ) ;
return - 1 ;
}
return V_7 ? V_7 : V_20 ;
}
static int F_12 ( struct V_1 * V_2 ,
unsigned char * V_5 , int V_6 )
{
int V_7 = 0 , V_20 ;
if ( V_5 == NULL )
return - V_21 ;
V_7 = F_10 ( V_2 -> V_8 ,
F_13 ( V_2 -> V_8 , 2 ) ,
V_5 , V_6 , & V_20 , 200 ) ;
if ( V_7 ) {
F_5 ( V_15 , L_7 , V_7 ) ;
return V_7 ;
}
if ( V_20 != V_6 ) {
F_5 ( V_15 , L_8 ,
V_20 , V_6 ) ;
return - 1 ;
}
return V_7 ? V_7 : V_20 ;
}
static int F_14 ( struct V_22 * V_23 , struct V_24 * V_24 )
{
int V_25 ;
F_15 ( V_24 ,
V_23 -> V_2 . V_8 ,
F_13 ( V_23 -> V_2 . V_8 , 0x2 ) ,
V_24 -> V_26 ,
V_27 ,
V_28 ,
V_23 ) ;
V_25 = F_16 ( V_24 , V_29 ) ;
if ( V_25 )
F_5 ( V_15 , L_9 , V_30 ) ;
return V_25 ;
}
void V_28 ( struct V_24 * V_24 )
{
struct V_22 * V_31 = V_24 -> V_32 ;
if ( V_24 -> V_33 > 0 ) {
F_17 ( & V_31 -> V_34 ,
V_24 -> V_26 ,
V_24 -> V_33 ) ;
} else {
if ( V_24 -> V_33 == 0 )
memset ( V_24 -> V_26 , 0 , V_27 ) ;
}
if ( V_31 -> V_35 )
F_14 ( V_31 , V_24 ) ;
}
static void F_18 ( struct V_22 * V_23 )
{
int V_36 ;
F_2 () ;
for ( V_36 = 0 ; V_36 < V_37 ; V_36 ++ )
F_19 ( V_23 -> V_38 [ V_36 ] ) ;
F_20 ( V_23 -> V_2 . V_8 ,
V_37 * V_27 ,
V_23 -> V_39 ,
V_23 -> V_40 ) ;
F_8 () ;
}
static int F_21 ( struct V_22 * V_23 )
{
int V_36 , V_7 = 0 ;
F_2 () ;
V_23 -> V_39 = F_22 ( V_23 -> V_2 . V_8 ,
V_37 * V_27 ,
V_41 ,
& V_23 -> V_40 ) ;
if ( ! V_23 -> V_39 ) {
F_5 ( V_15 , L_10 , V_30 ) ;
return - V_42 ;
}
memset ( V_23 -> V_39 , 0 , V_37 * V_27 ) ;
for ( V_36 = 0 ; V_36 < V_37 ; V_36 ++ ) {
struct V_24 * V_24 ;
V_24 = F_23 ( 0 , V_29 ) ;
if ( V_24 == NULL ) {
F_5 ( V_15 , L_11 , V_30 ) ;
F_18 ( V_23 ) ;
return - V_42 ;
}
V_24 -> V_26 = V_23 -> V_39 + ( V_36 * V_27 ) ;
V_24 -> V_43 = V_27 ;
V_23 -> V_38 [ V_36 ] = V_24 ;
}
F_8 () ;
return V_7 ;
}
static void F_24 ( struct V_22 * V_23 )
{
int V_36 ;
for ( V_36 = 0 ; V_36 < V_37 ; V_36 ++ )
F_25 ( V_23 -> V_38 [ V_36 ] ) ;
}
static int F_26 ( struct V_22 * V_23 )
{
int V_36 , V_7 = 0 ;
for ( V_36 = 0 ; V_36 < V_37 ; V_36 ++ ) {
V_7 = F_14 ( V_23 , V_23 -> V_38 [ V_36 ] ) ;
if ( V_7 ) {
F_24 ( V_23 ) ;
return V_7 ;
}
}
return 0 ;
}
static void F_27 ( struct V_44 * V_44 )
{
struct V_22 * V_31 ;
F_2 () ;
V_31 = F_28 ( V_44 , struct V_22 , V_44 ) ;
if ( V_31 != NULL ) {
F_29 ( V_31 -> V_2 . V_8 ) ;
F_30 ( V_31 ) ;
}
F_8 () ;
}
static void F_31 ( struct V_45 * V_46 )
{
struct V_22 * V_31 ;
F_2 () ;
V_31 = F_32 ( V_46 ) ;
F_33 ( V_31 ) ;
F_18 ( V_31 ) ;
F_34 ( V_46 , NULL ) ;
F_35 ( V_46 , & V_47 ) ;
F_36 ( & V_31 -> V_44 , F_27 ) ;
F_37 ( V_48 L_12 , V_49 ) ;
F_8 () ;
}
static int F_38 ( struct V_45 * V_46 ,
const struct V_50 * V_51 )
{
int V_7 ;
struct V_22 * V_31 ;
int V_36 ;
F_2 () ;
V_31 = F_39 ( sizeof( struct V_22 ) , V_41 ) ;
if ( V_31 == NULL ) {
V_25 ( L_13 , V_30 ) ;
return - V_42 ;
}
if ( ( sizeof( V_52 ) / sizeof( struct V_50 ) ) !=
( sizeof( V_53 ) / sizeof( const char * ) ) ) {
F_37 ( V_54 L_14 ) ;
return - V_21 ;
}
for ( V_36 = 0 ; V_36 < ( sizeof( V_52 ) /
sizeof( struct V_50 ) ) ; V_36 ++ ) {
if ( V_51 == & V_52 [ V_36 ] )
V_31 -> V_55 = V_53 [ V_36 ] ;
}
if ( V_31 -> V_55 == NULL )
V_31 -> V_55 = L_15 ;
V_31 -> V_2 . V_56 = & V_57 ;
V_31 -> V_2 . V_58 = & V_31 -> V_2 . V_59 . V_60 . V_61 ;
V_31 -> V_2 . V_62 = & V_31 -> V_2 . V_59 . V_60 . V_63 ;
F_40 ( & V_31 -> V_44 ) ;
F_34 ( V_46 , ( void * ) V_31 ) ;
V_31 -> V_2 . V_8 = F_41 ( F_42 ( V_46 ) ) ;
V_7 = F_43 ( V_46 , & V_47 ) ;
if ( V_7 < 0 ) {
V_25 ( L_16 ,
V_30 , V_7 ) ;
goto V_64;
}
F_37 ( V_48 L_17 , V_49 ) ;
V_7 = F_21 ( V_31 ) ;
if ( V_7 != 0 )
goto V_64;
V_7 = F_44 ( V_31 ) ;
F_8 () ;
return V_7 ;
V_64:
F_34 ( V_46 , NULL ) ;
F_30 ( V_31 ) ;
return V_7 ;
}
static int F_45 ( struct V_65 * V_65 , struct V_66 * V_66 )
{
int V_7 = 0 , V_67 = 0 ;
struct V_45 * V_46 = NULL ;
struct V_22 * V_23 = NULL ;
F_2 () ;
V_67 = F_46 ( V_65 ) ;
V_46 = F_47 ( & V_68 , V_67 ) ;
if ( V_46 == NULL ) {
F_37 ( V_54 L_18 ,
V_30 , V_67 ) ;
V_7 = - V_69 ;
goto exit;
}
V_23 = F_32 ( V_46 ) ;
if ( V_23 == NULL ) {
V_7 = - V_70 ;
goto exit;
}
V_66 -> V_71 = V_23 ;
F_48 ( & V_23 -> V_44 ) ;
exit:
F_8 () ;
return V_7 ;
}
static int F_49 ( struct V_65 * V_65 , struct V_66 * V_66 )
{
int V_7 = 0 ;
struct V_22 * V_23 = NULL ;
F_2 () ;
V_23 = V_66 -> V_71 ;
if ( V_23 != NULL ) {
F_36 ( & V_23 -> V_44 , F_27 ) ;
}
F_8 () ;
return V_7 ;
}
