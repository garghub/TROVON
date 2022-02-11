static int F_1 ( struct V_1 * V_2 ,
unsigned char * V_3 , int V_4 ,
unsigned char * V_5 , int V_6 )
{
int V_7 = 0 ;
if ( V_3 != NULL ) {
V_7 = F_2 ( V_2 -> V_8 ,
F_3 ( V_2 -> V_8 , 0 ) ,
V_9 ,
V_10 | V_11 |
V_12 ,
V_2 -> V_13 ,
0 ,
V_3 , V_4 ,
V_14 ) ;
if ( V_7 < 0 ) {
F_4 ( & V_2 -> V_8 -> V_15 ,
L_1 , V_7 ) ;
return V_7 ;
}
if ( V_7 != V_4 ) {
F_4 ( & V_2 -> V_8 -> V_15 ,
L_2 , V_7 , V_4 ) ;
return - 1 ;
}
}
if ( V_5 != NULL ) {
#ifdef F_5
F_4 ( V_2 -> V_8 -> V_15 ,
L_3 , V_6 ) ;
#endif
V_7 = F_2 ( V_2 -> V_8 ,
F_6 ( V_2 -> V_8 , 0 ) ,
V_16 ,
V_17 | V_11 |
V_12 ,
V_2 -> V_13 ,
0 ,
V_5 , V_6 ,
V_18 ) ;
if ( V_7 < 0 ) {
F_4 ( & V_2 -> V_8 -> V_15 ,
L_4 , V_7 ) ;
return V_7 ;
}
#ifdef F_5
F_4 ( V_2 -> V_8 -> V_15 ,
L_5 , V_6 ) ;
#endif
}
return V_7 ;
}
static int F_7 ( struct V_1 * V_2 ,
unsigned char * V_3 ,
int V_4 ,
int V_19 )
{
int V_7 , V_20 ;
V_7 = F_8 ( V_2 -> V_8 ,
F_9 ( V_2 -> V_8 , 1 ) ,
V_3 , V_4 , & V_20 , 200 ) ;
if ( V_7 ) {
F_4 ( & V_2 -> V_8 -> V_15 ,
L_6 , V_7 ) ;
return V_7 ;
}
if ( V_20 != V_4 ) {
F_4 ( & V_2 -> V_8 -> V_15 , L_2 ,
V_20 , V_4 ) ;
return - 1 ;
}
return V_20 ;
}
static int F_10 ( struct V_1 * V_2 ,
unsigned char * V_5 , int V_6 )
{
int V_7 , V_20 ;
if ( V_5 == NULL )
return - V_21 ;
V_7 = F_8 ( V_2 -> V_8 ,
F_11 ( V_2 -> V_8 , 2 ) ,
V_5 , V_6 , & V_20 , 200 ) ;
if ( V_7 ) {
F_4 ( & V_2 -> V_8 -> V_15 ,
L_7 , V_7 ) ;
return V_7 ;
}
if ( V_20 != V_6 ) {
F_4 ( & V_2 -> V_8 -> V_15 , L_8 ,
V_20 , V_6 ) ;
return - 1 ;
}
return V_20 ;
}
static int F_12 ( struct V_22 * V_15 , struct V_23 * V_23 )
{
int V_24 ;
F_13 ( V_23 ,
V_15 -> V_2 . V_8 ,
F_11 ( V_15 -> V_2 . V_8 , 0x2 ) ,
V_23 -> V_25 ,
V_26 ,
V_27 ,
V_15 ) ;
V_24 = F_14 ( V_23 , V_28 ) ;
if ( V_24 )
F_4 ( & V_23 -> V_15 -> V_15 ,
L_9 , V_29 ) ;
return V_24 ;
}
void V_27 ( struct V_23 * V_23 )
{
struct V_22 * V_30 = V_23 -> V_31 ;
if ( V_23 -> V_32 > 0 ) {
F_15 ( & V_30 -> V_33 ,
V_23 -> V_25 ,
V_23 -> V_32 ) ;
} else {
if ( V_23 -> V_32 == 0 )
memset ( V_23 -> V_25 , 0 , V_26 ) ;
}
if ( V_30 -> V_34 )
F_12 ( V_30 , V_23 ) ;
}
static void F_16 ( struct V_22 * V_15 )
{
int V_35 ;
for ( V_35 = 0 ; V_35 < V_36 ; V_35 ++ )
F_17 ( V_15 -> V_37 [ V_35 ] ) ;
F_18 ( V_15 -> V_2 . V_8 ,
V_36 * V_26 ,
V_15 -> V_38 ,
V_15 -> V_39 ) ;
}
static int F_19 ( struct V_22 * V_15 )
{
int V_35 ;
V_15 -> V_38 = F_20 ( V_15 -> V_2 . V_8 ,
V_36 * V_26 ,
V_40 ,
& V_15 -> V_39 ) ;
if ( ! V_15 -> V_38 ) {
F_4 ( & V_15 -> V_2 . V_8 -> V_15 ,
L_10 , V_29 ) ;
return - V_41 ;
}
memset ( V_15 -> V_38 , 0 , V_36 * V_26 ) ;
for ( V_35 = 0 ; V_35 < V_36 ; V_35 ++ ) {
struct V_23 * V_23 ;
V_23 = F_21 ( 0 , V_28 ) ;
if ( V_23 == NULL ) {
F_4 ( & V_15 -> V_2 . V_8 -> V_15 ,
L_11 , V_29 ) ;
F_16 ( V_15 ) ;
return - V_41 ;
}
V_23 -> V_25 = V_15 -> V_38 + ( V_35 * V_26 ) ;
V_23 -> V_42 = V_15 -> V_39 + ( V_35 * V_26 ) ;
V_23 -> V_43 = V_44 ;
V_23 -> V_45 = V_26 ;
V_15 -> V_37 [ V_35 ] = V_23 ;
}
return 0 ;
}
static void F_22 ( struct V_22 * V_15 )
{
int V_35 ;
for ( V_35 = 0 ; V_35 < V_36 ; V_35 ++ )
F_23 ( V_15 -> V_37 [ V_35 ] ) ;
}
static int F_24 ( struct V_22 * V_15 )
{
int V_35 , V_7 = 0 ;
for ( V_35 = 0 ; V_35 < V_36 ; V_35 ++ ) {
V_7 = F_12 ( V_15 , V_15 -> V_37 [ V_35 ] ) ;
if ( V_7 ) {
F_22 ( V_15 ) ;
return V_7 ;
}
}
return 0 ;
}
static void F_25 ( struct V_46 * V_46 )
{
struct V_22 * V_30 ;
V_30 = F_26 ( V_46 , struct V_22 , V_46 ) ;
if ( V_30 != NULL ) {
F_27 ( V_30 -> V_2 . V_8 ) ;
F_28 ( V_30 ) ;
}
}
static void F_29 ( struct V_47 * V_48 )
{
struct V_22 * V_30 ;
V_30 = F_30 ( V_48 ) ;
F_31 ( V_30 ) ;
F_16 ( V_30 ) ;
F_32 ( V_48 , NULL ) ;
F_33 ( V_48 , & V_49 ) ;
F_34 ( & V_30 -> V_46 , F_25 ) ;
F_35 ( L_12 , V_50 ) ;
}
static int F_36 ( struct V_47 * V_48 ,
const struct V_51 * V_52 )
{
int V_7 ;
struct V_22 * V_30 ;
int V_35 ;
if ( F_37 ( V_53 ) !=
( sizeof( V_54 ) / sizeof( const char * ) ) ) {
F_38 ( L_13 ) ;
return - V_21 ;
}
V_30 = F_39 ( sizeof( struct V_22 ) , V_40 ) ;
if ( V_30 == NULL )
return - V_41 ;
for ( V_35 = 0 ; V_35 < F_37 ( V_53 ) ; V_35 ++ ) {
if ( V_52 == & V_53 [ V_35 ] ) {
V_30 -> V_55 = V_54 [ V_35 ] ;
V_30 -> V_56 = V_57 [ V_35 ] ;
}
}
if ( V_30 -> V_55 == NULL )
V_30 -> V_55 = L_14 ;
V_30 -> V_2 . V_58 = & V_59 ;
V_30 -> V_2 . V_60 = & V_30 -> V_2 . V_61 . V_62 . V_63 ;
V_30 -> V_2 . V_64 = & V_30 -> V_2 . V_61 . V_62 . V_65 ;
F_40 ( & V_30 -> V_46 ) ;
F_32 ( V_48 , ( void * ) V_30 ) ;
V_30 -> V_2 . V_8 = F_41 ( F_42 ( V_48 ) ) ;
V_7 = F_43 ( V_48 , & V_49 ) ;
if ( V_7 < 0 ) {
F_44 ( & V_48 -> V_15 ,
L_15 ,
V_29 , V_7 ) ;
goto V_66;
}
F_35 ( L_16 , V_50 ) ;
V_7 = F_19 ( V_30 ) ;
if ( V_7 != 0 )
goto V_67;
V_7 = F_45 ( V_30 ) ;
if ( V_7 != 0 )
goto V_68;
return V_7 ;
V_68:
F_16 ( V_30 ) ;
V_67:
F_33 ( V_48 , & V_49 ) ;
V_66:
F_27 ( V_30 -> V_2 . V_8 ) ;
F_32 ( V_48 , NULL ) ;
F_28 ( V_30 ) ;
return V_7 ;
}
static int F_46 ( struct V_69 * V_69 , struct V_70 * V_70 )
{
int V_7 = 0 , V_71 = 0 ;
struct V_47 * V_48 = NULL ;
struct V_22 * V_15 = NULL ;
V_71 = F_47 ( V_69 ) ;
V_48 = F_48 ( & V_72 , V_71 ) ;
if ( V_48 == NULL ) {
F_38 ( L_17 ,
V_29 , V_71 ) ;
V_7 = - V_73 ;
goto exit;
}
V_15 = F_30 ( V_48 ) ;
if ( V_15 == NULL ) {
V_7 = - V_74 ;
goto exit;
}
V_70 -> V_75 = V_15 ;
F_49 ( & V_15 -> V_46 ) ;
exit:
return V_7 ;
}
static int F_50 ( struct V_69 * V_69 , struct V_70 * V_70 )
{
struct V_22 * V_15 = NULL ;
V_15 = V_70 -> V_75 ;
if ( V_15 != NULL ) {
F_34 ( & V_15 -> V_46 , F_25 ) ;
}
return 0 ;
}
