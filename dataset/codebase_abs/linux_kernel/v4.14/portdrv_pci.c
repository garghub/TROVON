static int T_1 F_1 ( char * V_1 )
{
if ( ! strncmp ( V_1 , L_1 , 6 ) ) {
V_2 = true ;
} else if ( ! strncmp ( V_1 , L_2 , 6 ) ) {
V_2 = false ;
V_3 = false ;
} else if ( ! strncmp ( V_1 , L_3 , 4 ) ) {
V_2 = false ;
V_3 = true ;
}
return 1 ;
}
void F_2 ( struct V_4 * V_5 )
{
F_3 ( V_5 , V_6 , V_7 ) ;
}
static int F_4 ( struct V_4 * V_5 )
{
int V_8 ;
V_8 = F_5 ( V_5 ) ;
if ( V_8 )
return V_8 ;
F_6 ( V_5 ) ;
return 0 ;
}
static int F_7 ( struct V_9 * V_5 )
{
struct V_4 * V_10 = F_8 ( V_5 ) ;
if ( F_9 ( V_10 ) == V_11 )
F_2 ( V_10 ) ;
return 0 ;
}
static int F_10 ( struct V_9 * V_5 )
{
return F_8 ( V_5 ) -> V_12 ? 0 : - V_13 ;
}
static int F_11 ( struct V_9 * V_5 )
{
return 0 ;
}
static int F_12 ( struct V_9 * V_5 )
{
return F_8 ( V_5 ) -> V_12 ? 0 : - V_13 ;
}
static int F_13 ( struct V_4 * V_5 ,
const struct V_14 * V_15 )
{
int V_16 ;
if ( ! F_14 ( V_5 ) ||
( ( F_9 ( V_5 ) != V_11 ) &&
( F_9 ( V_5 ) != V_17 ) &&
( F_9 ( V_5 ) != V_18 ) ) )
return - V_19 ;
V_16 = F_15 ( V_5 ) ;
if ( V_16 )
return V_16 ;
F_16 ( V_5 ) ;
if ( F_17 ( V_5 ) ) {
F_18 ( & V_5 -> V_5 , 100 ) ;
F_19 ( & V_5 -> V_5 ) ;
F_20 ( & V_5 -> V_5 ) ;
F_21 ( & V_5 -> V_5 ) ;
F_22 ( & V_5 -> V_5 ) ;
}
return 0 ;
}
static void F_23 ( struct V_4 * V_5 )
{
if ( F_17 ( V_5 ) ) {
F_24 ( & V_5 -> V_5 ) ;
F_25 ( & V_5 -> V_5 ) ;
F_26 ( & V_5 -> V_5 ) ;
}
F_27 ( V_5 ) ;
}
static T_2 F_28 ( struct V_4 * V_5 ,
enum V_20 error )
{
return V_21 ;
}
static T_2 F_29 ( struct V_4 * V_5 )
{
return V_22 ;
}
static T_2 F_30 ( struct V_4 * V_5 )
{
if ( V_5 -> V_23 == V_24 ) {
V_5 -> V_25 = true ;
F_31 ( V_5 ) ;
F_4 ( V_5 ) ;
F_32 ( V_5 ) ;
}
return V_22 ;
}
static int F_33 ( struct V_9 * V_9 , void * V_26 )
{
struct V_27 * V_27 ;
struct V_28 * V_29 ;
if ( V_9 -> V_30 == & V_31 && V_9 -> V_29 ) {
V_29 = F_34 ( V_9 -> V_29 ) ;
if ( V_29 && V_29 -> V_32 ) {
V_27 = F_35 ( V_9 ) ;
V_29 -> V_32 ( V_27 -> V_33 ) ;
}
}
return 0 ;
}
static void F_36 ( struct V_4 * V_5 )
{
F_37 ( & V_5 -> V_5 , NULL , F_33 ) ;
}
static int T_1 F_38 ( const struct V_34 * V_35 )
{
F_39 ( L_4 ,
V_35 -> V_36 ) ;
F_40 () ;
return 0 ;
}
static int T_1 F_41 ( void )
{
int V_8 ;
if ( V_2 )
return F_42 ( & V_37 ) ;
F_43 ( V_38 ) ;
V_8 = F_44 () ;
if ( V_8 ) {
F_45 ( V_39 L_5 , V_8 ) ;
goto V_40;
}
V_8 = F_42 ( & V_37 ) ;
if ( V_8 )
F_46 () ;
V_40:
return V_8 ;
}
