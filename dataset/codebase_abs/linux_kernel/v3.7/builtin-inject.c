static int F_1 ( struct V_1 * T_1 V_2 ,
union V_3 * V_4 ,
struct V_5 * V_5 V_2 )
{
T_2 V_6 ;
void * V_7 = V_4 ;
V_6 = V_4 -> V_8 . V_6 ;
while ( V_6 ) {
int V_9 = F_2 ( V_10 , V_7 , V_6 ) ;
if ( V_9 < 0 )
return - V_11 ;
V_6 -= V_9 ;
V_7 += V_9 ;
}
return 0 ;
}
static int F_3 ( struct V_1 * T_1 ,
union V_3 * V_4 ,
struct V_12 * T_3
V_2 )
{
return F_1 ( T_1 , V_4 , NULL ) ;
}
static int F_4 ( struct V_1 * T_1 ,
union V_3 * V_4 )
{
return F_1 ( T_1 , V_4 , NULL ) ;
}
static int F_5 ( union V_3 * V_4 ,
struct V_12 * T_3
V_2 )
{
return F_1 ( NULL , V_4 , NULL ) ;
}
static int F_6 ( union V_3 * V_4 ,
struct V_13 * * T_4 V_2 )
{
int V_9 ;
V_9 = F_7 ( V_4 , T_4 ) ;
if ( V_9 )
return V_9 ;
return F_1 ( NULL , V_4 , NULL ) ;
}
static int F_8 ( struct V_1 * T_1 ,
union V_3 * V_4 ,
struct V_14 * T_5 V_2 ,
struct V_5 * V_5 )
{
return F_1 ( T_1 , V_4 , V_5 ) ;
}
static int F_9 ( struct V_1 * T_1 ,
union V_3 * V_4 ,
struct V_14 * T_5 V_2 ,
struct V_15 * T_6 V_2 ,
struct V_5 * V_5 )
{
return F_1 ( T_1 , V_4 , V_5 ) ;
}
static int F_10 ( struct V_1 * T_1 ,
union V_3 * V_4 ,
struct V_14 * T_5 ,
struct V_5 * V_5 )
{
int V_16 ;
V_16 = F_11 ( T_1 , V_4 , T_5 , V_5 ) ;
F_8 ( T_1 , V_4 , T_5 , V_5 ) ;
return V_16 ;
}
static int F_12 ( struct V_1 * T_1 ,
union V_3 * V_4 ,
struct V_14 * T_5 ,
struct V_5 * V_5 )
{
int V_16 ;
V_16 = F_13 ( T_1 , V_4 , T_5 , V_5 ) ;
F_8 ( T_1 , V_4 , T_5 , V_5 ) ;
return V_16 ;
}
static int F_14 ( union V_3 * V_4 ,
struct V_12 * T_3 )
{
int V_16 ;
F_1 ( NULL , V_4 , NULL ) ;
V_16 = F_15 ( V_4 , T_3 ) ;
return V_16 ;
}
static int F_16 ( struct V_17 * V_18 )
{
if ( V_18 -> V_19 )
return 0 ;
if ( F_17 ( V_18 -> V_20 , V_18 -> V_21 ,
sizeof( V_18 -> V_21 ) ) > 0 ) {
V_18 -> V_19 = true ;
return 0 ;
}
return - 1 ;
}
static int F_18 ( struct V_17 * V_18 , struct V_1 * T_1 ,
struct V_5 * V_5 )
{
T_7 V_22 = V_23 ;
int V_16 ;
if ( F_16 ( V_18 ) < 0 ) {
F_19 ( L_1 , V_18 -> V_20 ) ;
return - 1 ;
}
if ( V_18 -> V_24 )
V_22 = V_25 ;
V_16 = F_20 ( T_1 , V_18 , V_22 , F_8 ,
V_5 ) ;
if ( V_16 ) {
F_21 ( L_2 , V_18 -> V_20 ) ;
return - 1 ;
}
return 0 ;
}
static int F_22 ( struct V_1 * T_1 ,
union V_3 * V_4 ,
struct V_14 * T_5 ,
struct V_15 * T_6 V_2 ,
struct V_5 * V_5 )
{
struct V_26 V_27 ;
struct V_28 * V_28 ;
T_8 V_29 ;
V_29 = V_4 -> V_8 . V_22 & V_30 ;
V_28 = F_23 ( V_5 , V_4 -> V_31 . V_32 ) ;
if ( V_28 == NULL ) {
F_21 ( L_3 ,
V_4 -> V_8 . type ) ;
goto V_33;
}
F_24 ( V_28 , V_5 , V_29 , V_34 ,
V_4 -> V_31 . V_31 , & V_27 ) ;
if ( V_27 . V_35 != NULL ) {
if ( ! V_27 . V_35 -> V_17 -> V_36 ) {
V_27 . V_35 -> V_17 -> V_36 = 1 ;
if ( F_25 ( V_27 . V_35 , NULL ) >= 0 ) {
F_18 ( V_27 . V_35 -> V_17 , T_1 , V_5 ) ;
} else {
#ifdef F_26
F_27 ( L_4
L_5 ,
V_27 . V_35 -> V_17 -> V_20 ) ;
#endif
}
}
}
V_33:
F_8 ( T_1 , V_4 , T_5 , V_5 ) ;
return 0 ;
}
static void F_28 ( int T_9 V_2 )
{
V_37 = 1 ;
}
static int F_29 ( struct V_38 * V_39 )
{
struct V_12 * T_3 ;
int V_9 = - V_40 ;
signal ( V_41 , F_28 ) ;
if ( V_39 -> V_42 ) {
V_39 -> T_1 . T_5 = F_22 ;
V_39 -> T_1 . V_43 = F_10 ;
V_39 -> T_1 . V_44 = F_12 ;
V_39 -> T_1 . V_45 = F_14 ;
}
T_3 = F_30 ( L_6 , V_46 , false , true , & V_39 -> T_1 ) ;
if ( T_3 == NULL )
return - V_47 ;
V_9 = F_31 ( T_3 , & V_39 -> T_1 ) ;
F_32 ( T_3 ) ;
return V_9 ;
}
int F_33 ( int V_48 , const char * * V_49 , const char * T_10 V_2 )
{
struct V_38 V_39 = {
. T_1 = {
. T_5 = F_9 ,
. V_43 = F_8 ,
. V_50 = F_8 ,
. V_44 = F_8 ,
. exit = F_8 ,
. V_51 = F_8 ,
. V_52 = F_9 ,
. V_53 = F_8 ,
. V_54 = F_8 ,
. V_55 = F_6 ,
. V_56 = F_4 ,
. V_45 = F_5 ,
. V_21 = F_3 ,
} ,
} ;
const struct V_57 V_58 [] = {
F_34 ( 'b' , L_7 , & V_39 . V_42 ,
L_8 ) ,
F_35 ( 'v' , L_9 , & V_59 ,
L_10 ) ,
F_36 ()
} ;
const char * const V_60 [] = {
L_11 ,
NULL
} ;
V_48 = F_37 ( V_48 , V_49 , V_58 , V_60 , 0 ) ;
if ( V_48 )
F_38 ( V_60 , V_58 ) ;
if ( F_39 () < 0 )
return - 1 ;
return F_29 ( & V_39 ) ;
}
