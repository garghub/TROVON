static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return V_3 ? F_2 ( F_3 ( F_4 ( V_3 ) ) ,
struct V_1 , V_4 ) : NULL ;
}
static T_1 F_5 ( struct V_2 * V_3 , char * V_5 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
T_1 V_6 ;
V_6 = sprintf ( V_5 , L_1 , V_1 -> V_7 ) ;
V_1 -> V_7 ++ ;
return V_6 ;
}
static T_1 F_6 ( struct V_2 * V_3 , char * V_5 )
{
return sprintf ( V_5 , L_1 , F_1 ( V_3 ) -> V_8 ) ;
}
static T_1 F_7 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_9 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
unsigned long V_10 ;
char * V_11 = ( char * ) V_5 ;
V_10 = F_8 ( V_11 , & V_11 , 10 ) ;
if ( ! V_11 || ( * V_11 && ( * V_11 != '\n' ) ) )
return - V_12 ;
if ( V_10 > V_13 )
return - V_14 ;
V_1 -> V_8 = V_10 ;
return V_9 ;
}
static T_1 F_9 ( struct V_2 * V_3 , char * V_5 )
{
return sprintf ( V_5 ,
L_2
L_3
L_4
L_5
L_6
L_7 ) ;
}
static inline struct V_15 * F_10 ( struct V_2 * V_3 )
{
return V_3 ? F_2 ( V_3 , struct V_15 , V_3 ) : NULL ;
}
static T_1 F_11 ( struct V_2 * V_3 , char * V_5 )
{
return sprintf ( V_5 , L_1 , F_10 ( V_3 ) -> V_8 ) ;
}
static T_1 F_12 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_9 )
{
struct V_15 * V_15 = F_10 ( V_3 ) ;
unsigned long V_10 ;
char * V_11 = ( char * ) V_5 ;
V_10 = F_8 ( V_11 , & V_11 , 10 ) ;
if ( ! V_11 || ( * V_11 && ( * V_11 != '\n' ) ) )
return - V_12 ;
if ( V_10 > V_13 )
return - V_14 ;
V_15 -> V_8 = V_10 ;
return V_9 ;
}
static void F_13 ( struct V_2 * V_3 )
{
F_14 ( F_10 ( V_3 ) ) ;
}
static inline struct V_16 * F_15 ( struct V_2 * V_3 )
{
return V_3 ? F_2 ( F_4 ( V_3 ) ,
struct V_16 , V_17 ) : NULL ;
}
static struct V_2 * F_16 ( struct V_18 * V_17 ,
const char * V_19 )
{
struct V_15 * V_15 ;
V_15 = F_17 ( sizeof( struct V_15 ) , V_20 ) ;
if ( ! V_15 )
return F_18 ( - V_21 ) ;
F_19 ( & V_15 -> V_3 , V_19 ,
& V_22 ) ;
V_15 -> V_8 = 0 ;
return & V_15 -> V_3 ;
}
static T_1 F_20 ( struct V_2 * V_3 ,
char * V_5 )
{
return sprintf ( V_5 ,
L_8
L_3
L_9
L_10 ) ;
}
static void F_21 ( struct V_2 * V_3 )
{
F_14 ( F_15 ( V_3 ) ) ;
}
static struct V_18 * F_22 (
struct V_18 * V_17 , const char * V_19 )
{
struct V_16 * V_16 ;
V_16 = F_17 ( sizeof( struct V_16 ) ,
V_20 ) ;
if ( ! V_16 )
return F_18 ( - V_21 ) ;
F_23 ( & V_16 -> V_17 , V_19 ,
& V_23 ) ;
return & V_16 -> V_17 ;
}
static T_1 F_24 ( struct V_2 * V_3 ,
char * V_5 )
{
return sprintf ( V_5 ,
L_11
L_3
L_12
L_13 ) ;
}
static int T_3 F_25 ( void )
{
int V_24 ;
int V_25 ;
struct V_26 * V_4 ;
for ( V_25 = 0 ; V_27 [ V_25 ] ; V_25 ++ ) {
V_4 = V_27 [ V_25 ] ;
F_26 ( & V_4 -> V_28 ) ;
F_27 ( & V_4 -> V_29 ) ;
V_24 = F_28 ( V_4 ) ;
if ( V_24 ) {
F_29 ( V_30 L_14 ,
V_24 ,
V_4 -> V_28 . V_31 . V_32 ) ;
goto V_33;
}
}
return 0 ;
V_33:
for ( V_25 -- ; V_25 >= 0 ; V_25 -- )
F_30 ( V_27 [ V_25 ] ) ;
return V_24 ;
}
static void T_4 F_31 ( void )
{
int V_25 ;
for ( V_25 = 0 ; V_27 [ V_25 ] ; V_25 ++ )
F_30 ( V_27 [ V_25 ] ) ;
}
