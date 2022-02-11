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
F_4 ( V_15 , L_1 ,
V_7 ) ;
return V_7 ;
}
if ( V_7 != V_4 ) {
F_4 ( V_15 , L_2 ,
V_7 , V_4 ) ;
return - 1 ;
}
}
if ( V_5 != NULL ) {
#ifdef F_5
F_4 ( V_15 , L_3 , V_6 ) ;
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
F_4 ( V_15 , L_4 ,
V_7 ) ;
return V_7 ;
}
#ifdef F_5
F_4 ( V_15 , L_5 , V_6 ) ;
#endif
}
return V_7 ;
}
static int F_7 ( struct V_1 * V_2 ,
unsigned char * V_3 ,
int V_4 ,
int V_19 )
{
int V_7 = 0 , V_20 ;
V_7 = F_8 ( V_2 -> V_8 ,
F_9 ( V_2 -> V_8 , 1 ) ,
V_3 , V_4 , & V_20 , 200 ) ;
if ( V_7 ) {
F_4 ( V_15 , L_6 , V_7 ) ;
return V_7 ;
}
if ( V_20 != V_4 ) {
F_4 ( V_15 , L_2 ,
V_20 , V_4 ) ;
return - 1 ;
}
return V_7 ? V_7 : V_20 ;
}
static int F_10 ( struct V_1 * V_2 ,
unsigned char * V_5 , int V_6 )
{
int V_7 = 0 , V_20 ;
if ( V_5 == NULL )
return - V_21 ;
V_7 = F_8 ( V_2 -> V_8 ,
F_11 ( V_2 -> V_8 , 2 ) ,
V_5 , V_6 , & V_20 , 200 ) ;
if ( V_7 ) {
F_4 ( V_15 , L_7 , V_7 ) ;
return V_7 ;
}
if ( V_20 != V_6 ) {
F_4 ( V_15 , L_8 ,
V_20 , V_6 ) ;
return - 1 ;
}
return V_7 ? V_7 : V_20 ;
}
static int F_12 ( struct V_22 * V_23 , struct V_24 * V_24 )
{
int V_25 ;
F_13 ( V_24 ,
V_23 -> V_2 . V_8 ,
F_11 ( V_23 -> V_2 . V_8 , 0x2 ) ,
V_24 -> V_26 ,
V_27 ,
V_28 ,
V_23 ) ;
V_25 = F_14 ( V_24 , V_29 ) ;
if ( V_25 )
F_4 ( V_15 , L_9 , V_30 ) ;
return V_25 ;
}
void V_28 ( struct V_24 * V_24 )
{
struct V_22 * V_31 = V_24 -> V_32 ;
if ( V_24 -> V_33 > 0 ) {
F_15 ( & V_31 -> V_34 ,
V_24 -> V_26 ,
V_24 -> V_33 ) ;
} else {
if ( V_24 -> V_33 == 0 )
memset ( V_24 -> V_26 , 0 , V_27 ) ;
}
if ( V_31 -> V_35 )
F_12 ( V_31 , V_24 ) ;
}
static void F_16 ( struct V_22 * V_23 )
{
int V_36 ;
for ( V_36 = 0 ; V_36 < V_37 ; V_36 ++ )
F_17 ( V_23 -> V_38 [ V_36 ] ) ;
F_18 ( V_23 -> V_2 . V_8 ,
V_37 * V_27 ,
V_23 -> V_39 ,
V_23 -> V_40 ) ;
}
static int F_19 ( struct V_22 * V_23 )
{
int V_36 , V_7 = 0 ;
V_23 -> V_39 = F_20 ( V_23 -> V_2 . V_8 ,
V_37 * V_27 ,
V_41 ,
& V_23 -> V_40 ) ;
if ( ! V_23 -> V_39 ) {
F_4 ( V_15 , L_10 , V_30 ) ;
return - V_42 ;
}
memset ( V_23 -> V_39 , 0 , V_37 * V_27 ) ;
for ( V_36 = 0 ; V_36 < V_37 ; V_36 ++ ) {
struct V_24 * V_24 ;
V_24 = F_21 ( 0 , V_29 ) ;
if ( V_24 == NULL ) {
F_4 ( V_15 , L_11 , V_30 ) ;
F_16 ( V_23 ) ;
return - V_42 ;
}
V_24 -> V_26 = V_23 -> V_39 + ( V_36 * V_27 ) ;
V_24 -> V_43 = V_23 -> V_40 + ( V_36 * V_27 ) ;
V_24 -> V_44 = V_45 ;
V_24 -> V_46 = V_27 ;
V_23 -> V_38 [ V_36 ] = V_24 ;
}
return V_7 ;
}
static void F_22 ( struct V_22 * V_23 )
{
int V_36 ;
for ( V_36 = 0 ; V_36 < V_37 ; V_36 ++ )
F_23 ( V_23 -> V_38 [ V_36 ] ) ;
}
static int F_24 ( struct V_22 * V_23 )
{
int V_36 , V_7 = 0 ;
for ( V_36 = 0 ; V_36 < V_37 ; V_36 ++ ) {
V_7 = F_12 ( V_23 , V_23 -> V_38 [ V_36 ] ) ;
if ( V_7 ) {
F_22 ( V_23 ) ;
return V_7 ;
}
}
return 0 ;
}
static void F_25 ( struct V_47 * V_47 )
{
struct V_22 * V_31 ;
V_31 = F_26 ( V_47 , struct V_22 , V_47 ) ;
if ( V_31 != NULL ) {
F_27 ( V_31 -> V_2 . V_8 ) ;
F_28 ( V_31 ) ;
}
}
static void F_29 ( struct V_48 * V_49 )
{
struct V_22 * V_31 ;
V_31 = F_30 ( V_49 ) ;
F_31 ( V_31 ) ;
F_16 ( V_31 ) ;
F_32 ( V_49 , NULL ) ;
F_33 ( V_49 , & V_50 ) ;
F_34 ( & V_31 -> V_47 , F_25 ) ;
F_35 ( L_12 , V_51 ) ;
}
static int F_36 ( struct V_48 * V_49 ,
const struct V_52 * V_53 )
{
int V_7 ;
struct V_22 * V_31 ;
int V_36 ;
if ( F_37 ( V_54 ) !=
( sizeof( V_55 ) / sizeof( const char * ) ) ) {
F_38 ( L_13 ) ;
return - V_21 ;
}
V_31 = F_39 ( sizeof( struct V_22 ) , V_41 ) ;
if ( V_31 == NULL )
return - V_42 ;
for ( V_36 = 0 ; V_36 < F_37 ( V_54 ) ; V_36 ++ ) {
if ( V_53 == & V_54 [ V_36 ] ) {
V_31 -> V_56 = V_55 [ V_36 ] ;
V_31 -> V_57 = V_58 [ V_36 ] ;
}
}
if ( V_31 -> V_56 == NULL )
V_31 -> V_56 = L_14 ;
V_31 -> V_2 . V_59 = & V_60 ;
V_31 -> V_2 . V_61 = & V_31 -> V_2 . V_62 . V_63 . V_64 ;
V_31 -> V_2 . V_65 = & V_31 -> V_2 . V_62 . V_63 . V_66 ;
F_40 ( & V_31 -> V_47 ) ;
F_32 ( V_49 , ( void * ) V_31 ) ;
V_31 -> V_2 . V_8 = F_41 ( F_42 ( V_49 ) ) ;
V_7 = F_43 ( V_49 , & V_50 ) ;
if ( V_7 < 0 ) {
F_44 ( & V_49 -> V_23 ,
L_15 ,
V_30 , V_7 ) ;
goto V_67;
}
F_35 ( L_16 , V_51 ) ;
V_7 = F_19 ( V_31 ) ;
if ( V_7 != 0 )
goto V_68;
V_7 = F_45 ( V_31 ) ;
if ( V_7 != 0 )
goto V_69;
return V_7 ;
V_69:
F_16 ( V_31 ) ;
V_68:
F_33 ( V_49 , & V_50 ) ;
V_67:
F_27 ( V_31 -> V_2 . V_8 ) ;
F_32 ( V_49 , NULL ) ;
F_28 ( V_31 ) ;
return V_7 ;
}
static int F_46 ( struct V_70 * V_70 , struct V_71 * V_71 )
{
int V_7 = 0 , V_72 = 0 ;
struct V_48 * V_49 = NULL ;
struct V_22 * V_23 = NULL ;
V_72 = F_47 ( V_70 ) ;
V_49 = F_48 ( & V_73 , V_72 ) ;
if ( V_49 == NULL ) {
F_38 ( L_17 ,
V_30 , V_72 ) ;
V_7 = - V_74 ;
goto exit;
}
V_23 = F_30 ( V_49 ) ;
if ( V_23 == NULL ) {
V_7 = - V_75 ;
goto exit;
}
V_71 -> V_76 = V_23 ;
F_49 ( & V_23 -> V_47 ) ;
exit:
return V_7 ;
}
static int F_50 ( struct V_70 * V_70 , struct V_71 * V_71 )
{
int V_7 = 0 ;
struct V_22 * V_23 = NULL ;
V_23 = V_71 -> V_76 ;
if ( V_23 != NULL ) {
F_34 ( & V_23 -> V_47 , F_25 ) ;
}
return V_7 ;
}
