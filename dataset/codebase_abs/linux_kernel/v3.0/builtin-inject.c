static int F_1 ( union V_1 * V_2 ,
struct V_3 * T_1 V_4 )
{
T_2 V_5 ;
void * V_6 = V_2 ;
V_5 = V_2 -> V_7 . V_5 ;
while ( V_5 ) {
int V_8 = F_2 ( V_9 , V_6 , V_5 ) ;
if ( V_8 < 0 )
return - V_10 ;
V_5 -= V_8 ;
V_6 += V_8 ;
}
return 0 ;
}
static int F_3 ( union V_1 * V_2 ,
struct V_11 * T_3 V_4 ,
struct V_3 * T_1 )
{
return F_1 ( V_2 , T_1 ) ;
}
static int F_4 ( union V_1 * V_2 ,
struct V_11 * T_3 V_4 ,
struct V_12 * T_4 V_4 ,
struct V_3 * T_1 )
{
return F_1 ( V_2 , T_1 ) ;
}
static int F_5 ( union V_1 * V_2 ,
struct V_11 * T_3 ,
struct V_3 * T_1 )
{
int V_13 ;
V_13 = F_6 ( V_2 , T_3 , T_1 ) ;
F_3 ( V_2 , T_3 , T_1 ) ;
return V_13 ;
}
static int F_7 ( union V_1 * V_2 ,
struct V_11 * T_3 ,
struct V_3 * T_1 )
{
int V_13 ;
V_13 = F_8 ( V_2 , T_3 , T_1 ) ;
F_3 ( V_2 , T_3 , T_1 ) ;
return V_13 ;
}
static int F_9 ( union V_1 * V_2 ,
struct V_3 * T_1 )
{
int V_13 ;
F_1 ( V_2 , T_1 ) ;
V_13 = F_10 ( V_2 , T_1 ) ;
return V_13 ;
}
static int F_11 ( struct V_14 * V_15 )
{
if ( V_15 -> V_16 )
return 0 ;
if ( F_12 ( V_15 -> V_17 , V_15 -> V_18 ,
sizeof( V_15 -> V_18 ) ) > 0 ) {
V_15 -> V_16 = true ;
return 0 ;
}
return - 1 ;
}
static int F_13 ( struct V_14 * V_15 , struct V_3 * T_1 )
{
T_5 V_19 = V_20 ;
struct V_21 * V_21 ;
int V_13 ;
if ( F_11 ( V_15 ) < 0 ) {
F_14 ( L_1 , V_15 -> V_17 ) ;
return - 1 ;
}
V_21 = F_15 ( T_1 ) ;
if ( V_21 == NULL ) {
F_16 ( L_2 ) ;
return - 1 ;
}
if ( V_15 -> V_22 )
V_19 = V_23 ;
V_13 = F_17 ( V_15 , V_19 , F_3 ,
V_21 , T_1 ) ;
if ( V_13 ) {
F_16 ( L_3 , V_15 -> V_17 ) ;
return - 1 ;
}
return 0 ;
}
static int F_18 ( union V_1 * V_2 ,
struct V_11 * T_3 ,
struct V_12 * T_4 V_4 ,
struct V_3 * T_1 )
{
struct V_24 V_25 ;
struct V_26 * V_26 ;
T_6 V_27 ;
V_27 = V_2 -> V_7 . V_19 & V_28 ;
V_26 = F_19 ( T_1 , V_2 -> V_29 . V_30 ) ;
if ( V_26 == NULL ) {
F_16 ( L_4 ,
V_2 -> V_7 . type ) ;
goto V_31;
}
F_20 ( V_26 , T_1 , V_27 , V_32 ,
V_2 -> V_29 . V_30 , V_2 -> V_29 . V_29 , & V_25 ) ;
if ( V_25 . V_33 != NULL ) {
if ( ! V_25 . V_33 -> V_14 -> V_34 ) {
V_25 . V_33 -> V_14 -> V_34 = 1 ;
if ( F_21 ( V_25 . V_33 , NULL ) >= 0 ) {
F_13 ( V_25 . V_33 -> V_14 , T_1 ) ;
} else
F_22 ( L_5
L_6 ,
V_25 . V_33 -> V_14 -> V_17 ) ;
}
}
V_31:
F_3 ( V_2 , T_3 , T_1 ) ;
return 0 ;
}
static int F_23 ( void )
{
struct V_3 * T_1 ;
int V_8 = - V_35 ;
signal ( V_36 , V_37 ) ;
if ( V_38 ) {
V_39 . T_3 = F_18 ;
V_39 . V_40 = F_5 ;
V_39 . V_41 = F_7 ;
V_39 . V_42 = F_9 ;
}
T_1 = F_24 ( V_43 , V_44 , false , true , & V_39 ) ;
if ( T_1 == NULL )
return - V_45 ;
V_8 = F_25 ( T_1 , & V_39 ) ;
F_26 ( T_1 ) ;
return V_8 ;
}
int F_27 ( int V_46 , const char * * V_47 , const char * T_7 V_4 )
{
V_46 = F_28 ( V_46 , V_47 , V_48 , V_49 , 0 ) ;
if ( V_46 )
F_29 ( V_49 , V_48 ) ;
if ( F_30 () < 0 )
return - 1 ;
return F_23 () ;
}
