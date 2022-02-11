static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( V_4 -> V_5 , 1 ) ;
return 0 ;
}
static void F_4 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( V_4 -> V_5 , 0 ) ;
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return F_6 ( V_4 -> V_5 ) ;
}
static T_1 F_7 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return F_6 ( V_4 -> V_5 ) ;
}
static int F_8 ( struct V_1 * V_2 , T_1 V_6 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( V_4 -> V_5 , V_6 ) ;
return 0 ;
}
static struct V_4 * F_9 ( struct V_7 * V_8 , const char * V_9 ,
const char * const * V_10 , T_1 V_11 , unsigned V_12 ,
bool V_13 , unsigned long V_14 ,
const struct V_15 * V_16 )
{
struct V_3 * V_3 ;
struct V_4 * V_4 ;
struct V_17 V_18 = {} ;
unsigned long V_19 ;
int V_20 ;
if ( V_8 )
V_3 = F_10 ( V_8 , sizeof( * V_3 ) , V_21 ) ;
else
V_3 = F_11 ( sizeof( * V_3 ) , V_21 ) ;
if ( ! V_3 )
return F_12 ( - V_22 ) ;
if ( V_13 )
V_19 = V_23 | V_24 ;
else
V_19 = V_25 ;
if ( V_8 )
V_20 = F_13 ( V_8 , V_12 , V_19 , V_9 ) ;
else
V_20 = F_14 ( V_12 , V_19 , V_9 ) ;
if ( V_20 ) {
if ( V_20 != - V_26 )
F_15 ( L_1 ,
V_27 , V_9 , V_12 ) ;
if ( ! V_8 )
F_16 ( V_3 ) ;
return F_12 ( V_20 ) ;
}
V_18 . V_9 = V_9 ;
V_18 . V_28 = V_16 ;
V_18 . V_14 = V_14 | V_29 ;
V_18 . V_10 = V_10 ;
V_18 . V_11 = V_11 ;
V_3 -> V_5 = F_17 ( V_12 ) ;
V_3 -> V_2 . V_18 = & V_18 ;
if ( V_8 )
V_4 = F_18 ( V_8 , & V_3 -> V_2 ) ;
else
V_4 = F_19 ( NULL , & V_3 -> V_2 ) ;
if ( ! F_20 ( V_4 ) )
return V_4 ;
if ( ! V_8 ) {
F_21 ( V_3 -> V_5 ) ;
F_16 ( V_3 ) ;
}
return V_4 ;
}
struct V_4 * F_22 ( struct V_7 * V_8 , const char * V_9 ,
const char * V_30 , unsigned V_12 , bool V_13 ,
unsigned long V_14 )
{
return F_9 ( V_8 , V_9 ,
( V_30 ? & V_30 : NULL ) ,
( V_30 ? 1 : 0 ) , V_12 , V_13 , V_14 ,
& V_31 ) ;
}
struct V_4 * F_23 ( struct V_7 * V_8 , const char * V_9 ,
const char * const * V_10 , T_1 V_11 , unsigned V_12 ,
bool V_13 , unsigned long V_14 )
{
if ( V_11 != 2 ) {
F_15 ( L_2 , V_9 ) ;
return F_12 ( - V_32 ) ;
}
return F_9 ( V_8 , V_9 , V_10 , V_11 ,
V_12 , V_13 , V_14 , & V_33 ) ;
}
static struct V_4 * F_24 (
struct V_34 * V_35 , void * V_36 )
{
struct V_37 * V_38 = V_36 ;
struct V_4 * V_4 ;
const char * * V_10 ;
int V_39 , V_11 ;
int V_12 ;
enum V_40 V_41 ;
F_25 ( & V_38 -> V_42 ) ;
if ( V_38 -> V_4 ) {
F_26 ( & V_38 -> V_42 ) ;
return V_38 -> V_4 ;
}
V_12 = F_27 ( V_38 -> V_43 , V_38 -> V_44 , 0 ,
& V_41 ) ;
if ( V_12 < 0 ) {
F_26 ( & V_38 -> V_42 ) ;
if ( V_12 == - V_26 )
F_28 ( L_3 ,
V_38 -> V_43 -> V_9 , V_27 ) ;
else
F_15 ( L_4 ,
V_38 -> V_43 -> V_9 , V_27 ,
V_38 -> V_44 ) ;
return F_12 ( V_12 ) ;
}
V_11 = F_29 ( V_38 -> V_43 ) ;
V_10 = F_30 ( V_11 , sizeof( char * ) , V_21 ) ;
if ( ! V_10 ) {
V_4 = F_12 ( - V_22 ) ;
goto V_45;
}
for ( V_39 = 0 ; V_39 < V_11 ; V_39 ++ )
V_10 [ V_39 ] = F_31 ( V_38 -> V_43 , V_39 ) ;
V_4 = V_38 -> V_46 ( V_38 -> V_43 -> V_9 , V_10 ,
V_11 , V_12 , V_41 & V_47 ) ;
if ( F_20 ( V_4 ) )
goto V_45;
V_38 -> V_4 = V_4 ;
V_45:
F_26 ( & V_38 -> V_42 ) ;
F_16 ( V_10 ) ;
return V_4 ;
}
static struct V_4 * F_32 ( const char * V_9 ,
const char * const * V_10 , T_1 V_11 ,
unsigned V_12 , bool V_13 )
{
return F_22 ( NULL , V_9 , V_10 [ 0 ] ,
V_12 , V_13 , 0 ) ;
}
static struct V_4 * F_33 ( const char * V_9 ,
const char * const * V_10 , T_1 V_11 , unsigned V_12 ,
bool V_13 )
{
return F_23 ( NULL , V_9 , V_10 , V_11 ,
V_12 , V_13 , 0 ) ;
}
static void T_2 F_34 ( struct V_48 * V_43 )
{
F_35 ( V_43 , L_5 ,
F_32 ) ;
}
void T_2 F_36 ( struct V_48 * V_43 )
{
F_35 ( V_43 , L_6 ,
F_33 ) ;
}
