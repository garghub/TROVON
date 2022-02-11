static struct V_1 T_1 * F_1 (
const char * V_2 ,
int V_3 ,
struct V_4 * V_5 ,
const unsigned short * V_6 )
{
const struct V_7 * V_8 ;
const struct V_9 * V_10 ;
struct V_11 * V_12 ;
struct V_1 * V_13 ;
if ( V_3 < 0 )
return NULL ;
if ( V_2 ) {
V_8 = F_2 ( V_14 , V_2 , NULL ) ;
if ( ! V_8 ) {
F_3 ( L_1 ,
V_15 ,
V_2 ) ;
return NULL ;
}
V_10 = (struct V_9 * ) V_8 -> V_16 ;
if ( ! V_10 ) {
F_3 ( L_2 ,
V_15 , V_2 ) ;
return NULL ;
}
V_5 -> V_17 = V_10 -> V_18 ;
}
V_12 = F_4 ( V_3 ) ;
if ( ! V_12 ) {
F_3 ( L_3 , V_15 , V_3 ) ;
return NULL ;
}
V_13 = F_5 ( V_12 , V_5 , V_6 , NULL ) ;
if ( ! V_13 )
F_3 ( L_4 ,
V_15 , V_3 , V_5 -> V_19 ) ;
else
F_6 ( L_5 ,
V_15 , V_3 , V_5 -> V_19 ) ;
F_7 ( V_12 ) ;
return V_13 ;
}
static int T_1 F_8 ( struct V_20 * V_21 , void * V_22 )
{
const char * V_2 = V_22 ;
static const char * V_23 = L_6 ;
struct V_11 * V_12 ;
if ( strncmp ( F_9 ( V_21 ) , V_23 , strlen ( V_23 ) ) != 0 )
return 0 ;
V_12 = F_10 ( V_21 ) ;
return ( strncmp ( V_12 -> V_2 , V_2 , strlen ( V_2 ) ) == 0 ) ;
}
static int T_1 F_11 ( enum V_24 type )
{
struct V_20 * V_21 = NULL ;
struct V_11 * V_12 ;
const char * V_2 = V_25 [ type ] ;
V_21 = F_12 ( & V_26 , NULL , ( void * ) V_2 ,
F_8 ) ;
if ( ! V_21 ) {
F_3 ( L_7 , V_15 ,
V_2 ) ;
return - V_27 ;
}
V_12 = F_10 ( V_21 ) ;
return V_12 -> V_28 ;
}
static struct V_1 T_1 * F_13 ( const char * V_2 ,
struct V_4 * V_5 )
{
return F_14 ( V_2 , V_29 , V_5 ) ;
}
static int T_1 F_15 ( const struct V_30 * V_31 )
{
V_32 = F_13 ( L_8 , & V_33 ) ;
return 0 ;
}
static int T_1 F_16 ( const struct V_30 * V_31 )
{
const unsigned short V_34 [] = { V_35 ,
V_36 ,
V_37 } ;
V_32 = F_17 ( L_8 , V_38 ,
& V_39 , V_34 ) ;
return 0 ;
}
static int T_1 F_18 ( const struct V_30 * V_31 )
{
const unsigned short V_34 [] = { V_40 ,
V_41 ,
V_37 } ;
V_42 = F_17 ( L_9 , V_43 ,
& V_44 , V_34 ) ;
return 0 ;
}
static int T_1 F_19 ( const struct V_30 * V_31 )
{
V_45 = F_13 ( L_10 , & V_46 ) ;
return 0 ;
}
static int T_1 F_20 ( const struct V_30 * V_31 )
{
V_45 = F_14 ( L_10 , V_43 ,
& V_46 ) ;
return 0 ;
}
static int T_1 F_21 ( const struct V_30 * V_31 )
{
V_45 = F_13 ( NULL , & V_47 ) ;
return 0 ;
}
static int T_1 F_22 ( const struct V_30 * V_31 )
{
V_45 = F_13 ( NULL , & V_48 ) ;
return 0 ;
}
static int T_1 F_23 ( void )
{
if ( ! F_24 ( V_49 ) ) {
F_6 ( L_11 , V_15 ) ;
return - V_27 ;
}
return 0 ;
}
static void T_2 F_25 ( void )
{
if ( V_45 )
F_26 ( V_45 ) ;
if ( V_32 )
F_26 ( V_32 ) ;
if ( V_42 )
F_26 ( V_42 ) ;
}
