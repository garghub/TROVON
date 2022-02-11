void F_1 ( struct V_1 * V_2 ,
unsigned int * V_3 , unsigned int * V_4 ,
unsigned int * V_5 , unsigned int * V_6 )
{
* V_3 = V_2 -> V_7 ;
* V_4 = V_2 -> V_8 ;
* V_5 = V_2 -> V_9 ;
* V_6 = V_2 -> V_10 ;
}
static inline char * F_2 ( struct V_1 * V_2 )
{
return V_2 -> V_11 . V_12 . V_13 ? : L_1 ;
}
static inline struct V_14 * F_3 ( struct V_15 * V_16 )
{
return V_16 ?
F_4 ( F_5 ( V_16 ) , struct V_14 , V_11 ) :
NULL ;
}
static inline struct V_1 *
F_6 ( struct V_15 * V_16 )
{
return V_16 ?
F_4 ( F_5 ( V_16 ) , struct V_1 ,
V_11 ) :
NULL ;
}
static T_1
F_7 ( struct V_15 * V_16 , char * V_17 )
{
struct V_1 * V_2 = F_6 ( V_16 ) ;
T_1 V_18 ;
V_18 = sprintf ( V_17 , L_2 , V_2 -> V_7 ,
V_2 -> V_8 ) ;
return V_18 ;
}
static T_1
F_8 ( struct V_15 * V_16 , const char * V_17 ,
T_2 V_18 )
{
struct V_1 * V_2 = F_6 ( V_16 ) ;
unsigned int V_19 , V_20 ;
struct V_21 * V_22 ;
char * V_23 = ( char * ) V_17 ;
T_1 V_24 = - V_25 ;
if ( sscanf ( V_23 , L_3 , & V_19 , & V_20 ) != 2 )
return - V_26 ;
F_9 ( & V_27 . V_28 ) ;
V_22 = V_2 -> V_29 -> V_22 ;
if ( ! V_22 )
goto V_30;
if ( V_19 > V_31 || V_20 > V_31 || V_19 > V_20 ||
V_19 < V_22 -> V_32 -> V_33 ||
V_20 > V_22 -> V_32 -> V_34 ) {
V_24 = - V_35 ;
goto V_30;
}
V_24 = V_18 ;
V_2 -> V_7 = V_19 ;
V_2 -> V_8 = V_20 ;
V_30:
F_10 ( & V_27 . V_28 ) ;
return V_24 ;
}
static T_1
F_11 ( struct V_15 * V_16 , char * V_17 )
{
struct V_1 * V_2 = F_6 ( V_16 ) ;
T_1 V_18 ;
V_18 = sprintf ( V_17 , L_2 , V_2 -> V_9 ,
V_2 -> V_10 ) ;
return V_18 ;
}
static T_1
F_12 ( struct V_15 * V_16 , const char * V_17 ,
T_2 V_18 )
{
struct V_1 * V_2 = F_6 ( V_16 ) ;
unsigned int V_19 , V_20 ;
struct V_21 * V_22 ;
char * V_23 = ( char * ) V_17 ;
T_1 V_24 = - V_25 ;
if ( sscanf ( V_23 , L_3 , & V_19 , & V_20 ) != 2 )
return - V_26 ;
F_9 ( & V_27 . V_28 ) ;
V_22 = V_2 -> V_29 -> V_22 ;
if ( ! V_22 )
goto V_30;
if ( V_19 > V_31 || V_20 > V_31 || V_19 > V_20 ||
V_20 >= V_22 -> V_32 -> V_36 ) {
V_24 = - V_35 ;
goto V_30;
}
V_24 = V_18 ;
V_2 -> V_9 = V_19 ;
V_2 -> V_10 = V_20 ;
V_30:
F_10 ( & V_27 . V_28 ) ;
return V_24 ;
}
static void F_13 ( struct V_15 * V_16 )
{
F_14 ( F_6 ( V_16 ) ) ;
}
static struct V_37 *
F_15 ( struct V_37 * V_11 , const char * V_38 )
{
struct V_1 * V_2 , * V_39 ;
struct V_14 * V_29 ;
if ( V_11 -> V_12 . V_40 == & V_41 ) {
V_29 = F_4 ( V_11 , struct V_14 , V_11 ) ;
} else {
V_39 = F_4 ( V_11 , struct V_1 ,
V_11 ) ;
V_29 = V_39 -> V_29 ;
}
if ( ! V_29 -> V_22 )
return F_16 ( - V_25 ) ;
V_2 = F_17 ( sizeof( struct V_1 ) , V_42 ) ;
if ( ! V_2 )
return F_16 ( - V_43 ) ;
F_18 ( & V_2 -> V_11 , V_38 ,
& V_44 ) ;
V_2 -> V_29 = V_29 ;
V_2 -> V_7 = V_29 -> V_22 -> V_32 -> V_33 ;
V_2 -> V_8 = V_29 -> V_22 -> V_32 -> V_34 ;
V_2 -> V_9 = 0 ;
V_2 -> V_10 = V_29 -> V_22 -> V_32 -> V_36 - 1 ;
return & V_2 -> V_11 ;
}
static void
F_19 ( struct V_37 * V_11 , struct V_15 * V_16 )
{
F_20 ( V_16 ) ;
}
static T_1 F_21 ( struct V_15 * V_16 ,
char * V_17 )
{
struct V_14 * V_29 = F_3 ( V_16 ) ;
T_1 V_18 ;
V_18 = sprintf ( V_17 , L_4 ,
( V_29 && V_29 -> V_22 ) ?
V_29 -> V_22 -> V_32 -> V_38 :
L_1 ) ;
return V_18 ;
}
void F_22 ( struct V_14 * V_29 )
{
struct V_21 * V_22 = V_29 -> V_22 ;
if ( F_23 ( ! V_29 -> V_22 ) )
return;
F_9 ( & V_22 -> V_45 ) ;
V_22 -> V_29 = NULL ;
F_10 ( & V_22 -> V_45 ) ;
V_29 -> V_22 = NULL ;
F_24 ( V_22 ) ;
}
static void F_25 ( struct V_15 * V_16 )
{
struct V_14 * V_29 = F_3 ( V_16 ) ;
F_22 ( V_29 ) ;
F_14 ( V_29 ) ;
}
static struct V_37 *
F_26 ( struct V_37 * V_11 , const char * V_38 )
{
struct V_37 * V_24 ;
struct V_21 * V_22 ;
char * V_46 , * V_23 ;
V_46 = F_27 ( V_42 , L_5 , V_38 ) ;
if ( ! V_46 )
return F_16 ( - V_43 ) ;
V_23 = strchr ( V_46 , '.' ) ;
if ( ! V_23 ) {
F_14 ( V_46 ) ;
return F_16 ( - V_26 ) ;
}
* V_23 ++ = '\0' ;
V_22 = F_28 ( V_46 ) ;
F_14 ( V_46 ) ;
if ( ! V_22 )
return F_16 ( - V_25 ) ;
F_9 ( & V_22 -> V_45 ) ;
if ( V_22 -> V_29 ) {
V_24 = F_16 ( - V_47 ) ;
goto V_48;
}
V_22 -> V_29 = F_17 ( sizeof( * V_22 -> V_29 ) , V_42 ) ;
if ( ! V_22 -> V_29 ) {
V_24 = F_16 ( - V_43 ) ;
goto V_48;
}
F_18 ( & V_22 -> V_29 -> V_11 , V_38 ,
& V_41 ) ;
V_22 -> V_29 -> V_22 = V_22 ;
V_24 = & V_22 -> V_29 -> V_11 ;
V_48:
F_10 ( & V_22 -> V_45 ) ;
if ( F_29 ( V_24 ) )
F_24 ( V_22 ) ;
return V_24 ;
}
static struct V_1 *
F_30 ( struct V_14 * V_29 , char * V_49 )
{
struct V_1 * V_2 , * V_24 ;
struct V_50 * V_51 = & V_29 -> V_11 . V_52 ;
struct V_15 * V_16 ;
char * V_53 , * V_54 = V_49 ;
if ( F_31 ( V_51 ) )
return NULL ;
V_16 = F_32 ( V_51 -> V_55 , struct V_15 , V_56 ) ;
V_24 = F_6 ( V_16 ) ;
V_55:
for (; ; ) {
V_53 = F_33 ( & V_54 , L_6 ) ;
if ( ! V_53 )
break;
if ( ! * V_53 )
continue;
F_34 (item, head, ci_entry) {
V_2 = F_6 ( V_16 ) ;
if ( ! strcmp ( V_53 ,
V_2 -> V_11 . V_12 . V_13 ) ) {
V_24 = V_2 ;
if ( ! V_54 )
goto V_57;
V_51 = & V_2 -> V_11 . V_52 ;
goto V_55;
}
}
break;
}
V_57:
return V_24 ;
}
struct V_1 *
F_35 ( struct V_21 * V_22 , char * V_49 )
{
struct V_1 * V_2 = NULL ;
F_9 ( & V_27 . V_28 ) ;
F_9 ( & V_22 -> V_45 ) ;
if ( V_22 -> V_29 )
V_2 = F_30 ( V_22 -> V_29 , V_49 ) ;
F_10 ( & V_22 -> V_45 ) ;
if ( V_2 )
F_36 ( & V_2 -> V_11 . V_12 ) ;
F_10 ( & V_27 . V_28 ) ;
return V_2 ;
}
void F_37 ( struct V_1 * V_2 )
{
F_20 ( & V_2 -> V_11 . V_12 ) ;
}
int T_3 F_38 ( void )
{
int V_58 ;
F_39 ( & V_27 . V_59 ) ;
F_40 ( & V_27 . V_28 ) ;
V_58 = F_41 ( & V_27 ) ;
return V_58 ;
}
void T_4 F_42 ( void )
{
F_43 ( & V_27 ) ;
}
