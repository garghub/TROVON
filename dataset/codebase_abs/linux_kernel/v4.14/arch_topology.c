unsigned long F_1 ( struct V_1 * V_2 , int V_3 )
{
return F_2 ( V_4 , V_3 ) ;
}
void F_3 ( unsigned int V_3 , unsigned long V_5 )
{
F_2 ( V_4 , V_3 ) = V_5 ;
}
static T_1 F_4 ( struct V_6 * V_7 ,
struct V_8 * V_9 ,
char * V_10 )
{
struct V_3 * V_3 = F_5 ( V_7 , struct V_3 , V_7 ) ;
return sprintf ( V_10 , L_1 , F_1 ( NULL , V_3 -> V_7 . V_11 ) ) ;
}
static T_1 F_6 ( struct V_6 * V_7 ,
struct V_8 * V_9 ,
const char * V_10 ,
T_2 V_12 )
{
struct V_3 * V_3 = F_5 ( V_7 , struct V_3 , V_7 ) ;
int V_13 = V_3 -> V_7 . V_11 ;
int V_14 ;
unsigned long V_15 ;
T_1 V_16 ;
if ( ! V_12 )
return 0 ;
V_16 = F_7 ( V_10 , 0 , & V_15 ) ;
if ( V_16 )
return V_16 ;
if ( V_15 > V_17 )
return - V_18 ;
F_8 ( & V_19 ) ;
F_9 (i, &cpu_topology[this_cpu].core_sibling)
F_3 ( V_14 , V_15 ) ;
F_10 ( & V_19 ) ;
return V_12 ;
}
static int F_11 ( void )
{
int V_14 ;
struct V_6 * V_3 ;
F_12 (i) {
V_3 = F_13 ( V_14 ) ;
if ( ! V_3 ) {
F_14 ( L_2 ,
V_20 , V_14 ) ;
continue;
}
F_15 ( V_3 , & V_21 ) ;
}
return 0 ;
}
static int T_3 F_16 ( void )
{
F_17 ( V_22 ) ;
V_22 = NULL ;
return 0 ;
}
void F_18 ( void )
{
T_4 V_5 ;
int V_3 ;
if ( ! V_22 )
return;
F_19 ( L_3 , V_23 ) ;
F_8 ( & V_19 ) ;
F_12 (cpu) {
F_19 ( L_4 ,
V_3 , V_22 [ V_3 ] ) ;
V_5 = ( V_22 [ V_3 ] << V_24 )
/ V_23 ;
F_3 ( V_3 , V_5 ) ;
F_19 ( L_5 ,
V_3 , F_1 ( NULL , V_3 ) ) ;
}
F_10 ( & V_19 ) ;
}
bool T_3 F_20 ( struct V_25 * V_26 , int V_3 )
{
static bool V_27 ;
int V_16 ;
T_5 V_28 ;
if ( V_27 )
return false ;
V_16 = F_21 ( V_26 , L_6 ,
& V_28 ) ;
if ( ! V_16 ) {
if ( ! V_22 ) {
V_22 = F_22 ( F_23 () ,
sizeof( * V_22 ) ,
V_29 ) ;
if ( ! V_22 ) {
F_14 ( L_7 ) ;
V_27 = true ;
return false ;
}
}
V_23 = F_24 ( V_28 , V_23 ) ;
V_22 [ V_3 ] = V_28 ;
F_19 ( L_8 ,
V_26 , V_22 [ V_3 ] ) ;
} else {
if ( V_22 ) {
F_14 ( L_9 ,
V_26 ) ;
F_14 ( L_10 ) ;
}
V_27 = true ;
F_16 () ;
}
return ! V_16 ;
}
static int T_3
F_25 ( struct V_30 * V_31 ,
unsigned long V_32 ,
void * V_33 )
{
struct V_34 * V_35 = V_33 ;
int V_3 ;
if ( ! V_22 )
return 0 ;
if ( V_32 != V_36 )
return 0 ;
F_19 ( L_11 ,
F_26 ( V_35 -> V_37 ) ,
F_26 ( V_38 ) ) ;
F_27 ( V_38 , V_38 , V_35 -> V_37 ) ;
F_9 (cpu, policy->related_cpus) {
V_22 [ V_3 ] = F_1 ( NULL , V_3 ) *
V_35 -> V_39 . V_40 / 1000UL ;
V_23 = F_24 ( V_22 [ V_3 ] , V_23 ) ;
}
if ( F_28 ( V_38 ) ) {
F_18 () ;
F_16 () ;
F_19 ( L_12 ) ;
F_29 ( & V_41 ) ;
}
return 0 ;
}
static int T_3 F_30 ( void )
{
if ( ! V_42 || ! V_22 )
return - V_18 ;
if ( ! F_31 ( & V_38 , V_29 ) ) {
F_14 ( L_13 ) ;
return - V_43 ;
}
F_32 ( V_38 , V_44 ) ;
return F_33 ( & V_45 ,
V_46 ) ;
}
static void T_3 F_34 ( struct V_47 * V_48 )
{
F_35 ( & V_45 ,
V_46 ) ;
}
