static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return V_3 ? F_2 ( F_3 ( F_4 ( V_3 ) ) , struct V_1 , V_4 ) : NULL ;
}
static T_1 F_5 ( struct V_1 * V_1 ,
char * V_5 )
{
T_1 V_6 ;
V_6 = sprintf ( V_5 , L_1 , V_1 -> V_7 ) ;
V_1 -> V_7 ++ ;
return V_6 ;
}
static T_1 F_6 ( struct V_1 * V_1 ,
char * V_5 )
{
return sprintf ( V_5 , L_1 , V_1 -> V_8 ) ;
}
static T_1 F_7 ( struct V_1 * V_1 ,
const char * V_5 ,
T_2 V_9 )
{
unsigned long V_10 ;
char * V_11 = ( char * ) V_5 ;
V_10 = F_8 ( V_11 , & V_11 , 10 ) ;
if ( ( * V_11 != '\0' ) && ( * V_11 != '\n' ) )
return - V_12 ;
if ( V_10 > V_13 )
return - V_14 ;
V_1 -> V_8 = V_10 ;
return V_9 ;
}
static T_1 F_9 ( struct V_1 * V_1 ,
char * V_5 )
{
return sprintf ( V_5 ,
L_2
L_3
L_4
L_5
L_6
L_7 ) ;
}
static T_1 F_10 ( struct V_2 * V_3 ,
struct V_15 * V_16 ,
char * V_5 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_17 * V_18 =
F_2 ( V_16 , struct V_17 , V_16 ) ;
T_1 V_19 = 0 ;
if ( V_18 -> V_20 )
V_19 = V_18 -> V_20 ( V_1 , V_5 ) ;
return V_19 ;
}
static T_1 F_11 ( struct V_2 * V_3 ,
struct V_15 * V_16 ,
const char * V_5 , T_2 V_9 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_17 * V_18 =
F_2 ( V_16 , struct V_17 , V_16 ) ;
T_1 V_19 = - V_12 ;
if ( V_18 -> V_21 )
V_19 = V_18 -> V_21 ( V_1 , V_5 , V_9 ) ;
return V_19 ;
}
static inline struct V_22 * F_12 ( struct V_2 * V_3 )
{
return V_3 ? F_2 ( V_3 , struct V_22 , V_3 ) : NULL ;
}
static T_1 F_13 ( struct V_2 * V_3 ,
struct V_15 * V_16 ,
char * V_5 )
{
T_1 V_9 ;
struct V_22 * V_22 = F_12 ( V_3 ) ;
V_9 = sprintf ( V_5 , L_1 , V_22 -> V_8 ) ;
return V_9 ;
}
static T_1 F_14 ( struct V_2 * V_3 ,
struct V_15 * V_16 ,
const char * V_5 , T_2 V_9 )
{
struct V_22 * V_22 = F_12 ( V_3 ) ;
unsigned long V_10 ;
char * V_11 = ( char * ) V_5 ;
V_10 = F_8 ( V_11 , & V_11 , 10 ) ;
if ( ! V_11 || ( * V_11 && ( * V_11 != '\n' ) ) )
return - V_12 ;
if ( V_10 > V_13 )
return - V_14 ;
V_22 -> V_8 = V_10 ;
return V_9 ;
}
static void F_15 ( struct V_2 * V_3 )
{
F_16 ( F_12 ( V_3 ) ) ;
}
static inline struct V_23 * F_17 ( struct V_2 * V_3 )
{
return V_3 ? F_2 ( F_4 ( V_3 ) , struct V_23 , V_24 ) : NULL ;
}
static struct V_2 * F_18 ( struct V_25 * V_24 , const char * V_26 )
{
struct V_22 * V_22 ;
V_22 = F_19 ( sizeof( struct V_22 ) , V_27 ) ;
if ( ! V_22 )
return F_20 ( - V_28 ) ;
F_21 ( & V_22 -> V_3 , V_26 ,
& V_29 ) ;
V_22 -> V_8 = 0 ;
return & V_22 -> V_3 ;
}
static T_1 F_22 ( struct V_2 * V_3 ,
struct V_15 * V_16 ,
char * V_5 )
{
return sprintf ( V_5 ,
L_8
L_3
L_9
L_10 ) ;
}
static void F_23 ( struct V_2 * V_3 )
{
F_16 ( F_17 ( V_3 ) ) ;
}
static struct V_25 * F_24 ( struct V_25 * V_24 , const char * V_26 )
{
struct V_23 * V_23 ;
V_23 = F_19 ( sizeof( struct V_23 ) ,
V_27 ) ;
if ( ! V_23 )
return F_20 ( - V_28 ) ;
F_25 ( & V_23 -> V_24 , V_26 ,
& V_30 ) ;
return & V_23 -> V_24 ;
}
static T_1 F_26 ( struct V_2 * V_3 ,
struct V_15 * V_16 ,
char * V_5 )
{
return sprintf ( V_5 ,
L_11
L_3
L_12
L_13 ) ;
}
static int T_3 F_27 ( void )
{
int V_19 ;
int V_31 ;
struct V_32 * V_4 ;
for ( V_31 = 0 ; V_33 [ V_31 ] ; V_31 ++ ) {
V_4 = V_33 [ V_31 ] ;
F_28 ( & V_4 -> V_34 ) ;
F_29 ( & V_4 -> V_35 ) ;
V_19 = F_30 ( V_4 ) ;
if ( V_19 ) {
F_31 ( V_36 L_14 ,
V_19 ,
V_4 -> V_34 . V_37 . V_38 ) ;
goto V_39;
}
}
return 0 ;
V_39:
for ( V_31 -- ; V_31 >= 0 ; V_31 -- )
F_32 ( V_33 [ V_31 ] ) ;
return V_19 ;
}
static void T_4 F_33 ( void )
{
int V_31 ;
for ( V_31 = 0 ; V_33 [ V_31 ] ; V_31 ++ )
F_32 ( V_33 [ V_31 ] ) ;
}
