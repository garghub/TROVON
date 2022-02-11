static struct V_1 * F_1 ( struct V_2 * V_3 , int V_4 )
{
struct V_1 * V_1 = F_2 ( V_3 ) ;
if ( V_1 ) {
V_1 -> V_5 = F_3 () ;
V_1 -> V_6 = V_4 ;
V_1 -> V_7 = V_1 -> V_8 = V_1 -> V_9 = F_4 ( V_1 ) ;
}
return V_1 ;
}
T_1 F_5 ( char const * V_10 , char T_2 * V_11 , T_3 V_12 , T_4 * V_13 )
{
return F_6 ( V_11 , V_12 , V_13 , V_10 , strlen ( V_10 ) ) ;
}
T_1 F_7 ( unsigned long V_14 , char T_2 * V_11 , T_3 V_12 , T_4 * V_13 )
{
char V_15 [ V_16 ] ;
T_3 V_17 = snprintf ( V_15 , V_16 , L_1 , V_14 ) ;
if ( V_17 > V_16 )
V_17 = V_16 ;
return F_6 ( V_11 , V_12 , V_13 , V_15 , V_17 ) ;
}
int F_8 ( unsigned long * V_14 , char const T_2 * V_11 , T_3 V_12 )
{
char V_15 [ V_16 ] ;
unsigned long V_18 ;
if ( ! V_12 )
return 0 ;
if ( V_12 > V_16 - 1 )
return - V_19 ;
memset ( V_15 , 0x0 , V_16 ) ;
if ( F_9 ( V_15 , V_11 , V_12 ) )
return - V_20 ;
F_10 ( & V_21 , V_18 ) ;
* V_14 = F_11 ( V_15 , NULL , 0 ) ;
F_12 ( & V_21 , V_18 ) ;
return V_12 ;
}
static T_1 F_13 ( struct V_22 * V_22 , char T_2 * V_11 , T_3 V_12 , T_4 * V_13 )
{
unsigned long * V_14 = V_22 -> V_23 ;
return F_7 ( * V_14 , V_11 , V_12 , V_13 ) ;
}
static T_1 F_14 ( struct V_22 * V_22 , char const T_2 * V_11 , T_3 V_12 , T_4 * V_13 )
{
unsigned long V_24 ;
int V_25 ;
if ( * V_13 )
return - V_19 ;
V_25 = F_8 ( & V_24 , V_11 , V_12 ) ;
if ( V_25 <= 0 )
return V_25 ;
V_25 = F_15 ( V_22 -> V_23 , V_24 ) ;
if ( V_25 )
return V_25 ;
return V_12 ;
}
static int F_16 ( struct V_26 * V_27 , char const * V_28 ,
const struct V_29 * V_30 , int V_31 , void * V_32 )
{
struct V_26 * V_26 ;
struct V_1 * V_1 ;
F_17 ( F_18 ( V_27 ) ) ;
V_26 = F_19 ( V_27 , V_28 ) ;
if ( ! V_26 ) {
F_20 ( F_18 ( V_27 ) ) ;
return - V_33 ;
}
V_1 = F_1 ( V_27 -> V_34 , V_35 | V_31 ) ;
if ( ! V_1 ) {
F_21 ( V_26 ) ;
F_20 ( F_18 ( V_27 ) ) ;
return - V_33 ;
}
V_1 -> V_36 = V_30 ;
V_1 -> V_37 = V_32 ;
F_22 ( V_26 , V_1 ) ;
F_20 ( F_18 ( V_27 ) ) ;
return 0 ;
}
int F_23 ( struct V_26 * V_27 ,
char const * V_28 , unsigned long * V_14 )
{
return F_16 ( V_27 , V_28 ,
& V_38 , 0644 , V_14 ) ;
}
int F_24 ( struct V_26 * V_27 ,
char const * V_28 , unsigned long * V_14 )
{
return F_16 ( V_27 , V_28 ,
& V_39 , 0444 , V_14 ) ;
}
static T_1 F_25 ( struct V_22 * V_22 , char T_2 * V_11 , T_3 V_12 , T_4 * V_13 )
{
T_5 * V_14 = V_22 -> V_23 ;
return F_7 ( F_26 ( V_14 ) , V_11 , V_12 , V_13 ) ;
}
int F_27 ( struct V_26 * V_27 ,
char const * V_28 , T_5 * V_14 )
{
return F_16 ( V_27 , V_28 ,
& V_40 , 0444 , V_14 ) ;
}
int F_28 ( struct V_26 * V_27 ,
char const * V_28 , const struct V_29 * V_30 )
{
return F_16 ( V_27 , V_28 , V_30 , 0644 , NULL ) ;
}
int F_29 ( struct V_26 * V_27 ,
char const * V_28 , const struct V_29 * V_30 , int V_31 )
{
return F_16 ( V_27 , V_28 , V_30 , V_31 , NULL ) ;
}
struct V_26 * F_30 ( struct V_26 * V_41 , char const * V_28 )
{
struct V_26 * V_26 ;
struct V_1 * V_1 ;
F_17 ( F_18 ( V_41 ) ) ;
V_26 = F_19 ( V_41 , V_28 ) ;
if ( ! V_26 ) {
F_20 ( F_18 ( V_41 ) ) ;
return NULL ;
}
V_1 = F_1 ( V_41 -> V_34 , V_42 | 0755 ) ;
if ( ! V_1 ) {
F_21 ( V_26 ) ;
F_20 ( F_18 ( V_41 ) ) ;
return NULL ;
}
V_1 -> V_43 = & V_44 ;
V_1 -> V_36 = & V_45 ;
F_22 ( V_26 , V_1 ) ;
F_20 ( F_18 ( V_41 ) ) ;
return V_26 ;
}
static int F_31 ( struct V_2 * V_3 , void * V_46 , int V_47 )
{
struct V_1 * V_48 ;
V_3 -> V_49 = V_50 ;
V_3 -> V_51 = V_52 ;
V_3 -> V_53 = V_54 ;
V_3 -> V_55 = & V_56 ;
V_3 -> V_57 = 1 ;
V_48 = F_1 ( V_3 , V_42 | 0755 ) ;
if ( ! V_48 )
return - V_33 ;
V_48 -> V_43 = & V_44 ;
V_48 -> V_36 = & V_45 ;
V_3 -> V_58 = F_32 ( V_48 ) ;
if ( ! V_3 -> V_58 )
return - V_33 ;
F_33 ( V_3 -> V_58 ) ;
return 0 ;
}
static struct V_26 * F_34 ( struct V_59 * V_60 ,
int V_18 , const char * V_61 , void * V_46 )
{
return F_35 ( V_60 , V_18 , V_46 , F_31 ) ;
}
int T_6 F_36 ( void )
{
return F_37 ( & V_62 ) ;
}
void T_7 F_38 ( void )
{
F_39 ( & V_62 ) ;
}
