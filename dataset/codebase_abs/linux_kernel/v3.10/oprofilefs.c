static struct V_1 * F_1 ( struct V_2 * V_3 , int V_4 )
{
struct V_1 * V_1 = F_2 ( V_3 ) ;
if ( V_1 ) {
V_1 -> V_5 = F_3 () ;
V_1 -> V_6 = V_4 ;
V_1 -> V_7 = V_1 -> V_8 = V_1 -> V_9 = V_10 ;
}
return V_1 ;
}
T_1 F_4 ( char const * V_11 , char T_2 * V_12 , T_3 V_13 , T_4 * V_14 )
{
return F_5 ( V_12 , V_13 , V_14 , V_11 , strlen ( V_11 ) ) ;
}
T_1 F_6 ( unsigned long V_15 , char T_2 * V_12 , T_3 V_13 , T_4 * V_14 )
{
char V_16 [ V_17 ] ;
T_3 V_18 = snprintf ( V_16 , V_17 , L_1 , V_15 ) ;
if ( V_18 > V_17 )
V_18 = V_17 ;
return F_5 ( V_12 , V_13 , V_14 , V_16 , V_18 ) ;
}
int F_7 ( unsigned long * V_15 , char const T_2 * V_12 , T_3 V_13 )
{
char V_16 [ V_17 ] ;
unsigned long V_19 ;
if ( ! V_13 )
return 0 ;
if ( V_13 > V_17 - 1 )
return - V_20 ;
memset ( V_16 , 0x0 , V_17 ) ;
if ( F_8 ( V_16 , V_12 , V_13 ) )
return - V_21 ;
F_9 ( & V_22 , V_19 ) ;
* V_15 = F_10 ( V_16 , NULL , 0 ) ;
F_11 ( & V_22 , V_19 ) ;
return V_13 ;
}
static T_1 F_12 ( struct V_23 * V_23 , char T_2 * V_12 , T_3 V_13 , T_4 * V_14 )
{
unsigned long * V_15 = V_23 -> V_24 ;
return F_6 ( * V_15 , V_12 , V_13 , V_14 ) ;
}
static T_1 F_13 ( struct V_23 * V_23 , char const T_2 * V_12 , T_3 V_13 , T_4 * V_14 )
{
unsigned long V_25 ;
int V_26 ;
if ( * V_14 )
return - V_20 ;
V_26 = F_7 ( & V_25 , V_12 , V_13 ) ;
if ( V_26 <= 0 )
return V_26 ;
V_26 = F_14 ( V_23 -> V_24 , V_25 ) ;
if ( V_26 )
return V_26 ;
return V_13 ;
}
static int F_15 ( struct V_2 * V_3 ,
struct V_27 * V_28 , char const * V_29 , const struct V_30 * V_31 ,
int V_32 , void * V_33 )
{
struct V_27 * V_27 ;
struct V_1 * V_1 ;
F_16 ( & V_28 -> V_34 -> V_35 ) ;
V_27 = F_17 ( V_28 , V_29 ) ;
if ( ! V_27 ) {
F_18 ( & V_28 -> V_34 -> V_35 ) ;
return - V_36 ;
}
V_1 = F_1 ( V_3 , V_37 | V_32 ) ;
if ( ! V_1 ) {
F_19 ( V_27 ) ;
F_18 ( & V_28 -> V_34 -> V_35 ) ;
return - V_36 ;
}
V_1 -> V_38 = V_31 ;
V_1 -> V_39 = V_33 ;
F_20 ( V_27 , V_1 ) ;
F_18 ( & V_28 -> V_34 -> V_35 ) ;
return 0 ;
}
int F_21 ( struct V_2 * V_3 , struct V_27 * V_28 ,
char const * V_29 , unsigned long * V_15 )
{
return F_15 ( V_3 , V_28 , V_29 ,
& V_40 , 0644 , V_15 ) ;
}
int F_22 ( struct V_2 * V_3 , struct V_27 * V_28 ,
char const * V_29 , unsigned long * V_15 )
{
return F_15 ( V_3 , V_28 , V_29 ,
& V_41 , 0444 , V_15 ) ;
}
static T_1 F_23 ( struct V_23 * V_23 , char T_2 * V_12 , T_3 V_13 , T_4 * V_14 )
{
T_5 * V_15 = V_23 -> V_24 ;
return F_6 ( F_24 ( V_15 ) , V_12 , V_13 , V_14 ) ;
}
int F_25 ( struct V_2 * V_3 , struct V_27 * V_28 ,
char const * V_29 , T_5 * V_15 )
{
return F_15 ( V_3 , V_28 , V_29 ,
& V_42 , 0444 , V_15 ) ;
}
int F_26 ( struct V_2 * V_3 , struct V_27 * V_28 ,
char const * V_29 , const struct V_30 * V_31 )
{
return F_15 ( V_3 , V_28 , V_29 , V_31 , 0644 , NULL ) ;
}
int F_27 ( struct V_2 * V_3 , struct V_27 * V_28 ,
char const * V_29 , const struct V_30 * V_31 , int V_32 )
{
return F_15 ( V_3 , V_28 , V_29 , V_31 , V_32 , NULL ) ;
}
struct V_27 * F_28 ( struct V_2 * V_3 ,
struct V_27 * V_28 , char const * V_29 )
{
struct V_27 * V_27 ;
struct V_1 * V_1 ;
F_16 ( & V_28 -> V_34 -> V_35 ) ;
V_27 = F_17 ( V_28 , V_29 ) ;
if ( ! V_27 ) {
F_18 ( & V_28 -> V_34 -> V_35 ) ;
return NULL ;
}
V_1 = F_1 ( V_3 , V_43 | 0755 ) ;
if ( ! V_1 ) {
F_19 ( V_27 ) ;
F_18 ( & V_28 -> V_34 -> V_35 ) ;
return NULL ;
}
V_1 -> V_44 = & V_45 ;
V_1 -> V_38 = & V_46 ;
F_20 ( V_27 , V_1 ) ;
F_18 ( & V_28 -> V_34 -> V_35 ) ;
return V_27 ;
}
static int F_29 ( struct V_2 * V_3 , void * V_47 , int V_48 )
{
struct V_1 * V_49 ;
V_3 -> V_50 = V_51 ;
V_3 -> V_52 = V_53 ;
V_3 -> V_54 = V_55 ;
V_3 -> V_56 = & V_57 ;
V_3 -> V_58 = 1 ;
V_49 = F_1 ( V_3 , V_43 | 0755 ) ;
if ( ! V_49 )
return - V_36 ;
V_49 -> V_44 = & V_45 ;
V_49 -> V_38 = & V_46 ;
V_3 -> V_59 = F_30 ( V_49 ) ;
if ( ! V_3 -> V_59 )
return - V_36 ;
F_31 ( V_3 , V_3 -> V_59 ) ;
return 0 ;
}
static struct V_27 * F_32 ( struct V_60 * V_61 ,
int V_19 , const char * V_62 , void * V_47 )
{
return F_33 ( V_61 , V_19 , V_47 , F_29 ) ;
}
int T_6 F_34 ( void )
{
return F_35 ( & V_63 ) ;
}
void T_7 F_36 ( void )
{
F_37 ( & V_63 ) ;
}
