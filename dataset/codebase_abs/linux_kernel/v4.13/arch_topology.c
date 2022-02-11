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
return sprintf ( V_10 , L_1 ,
F_1 ( NULL , V_3 -> V_7 . V_11 ) ) ;
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
void F_16 ( void )
{
T_3 V_5 ;
int V_3 ;
if ( ! V_22 || V_23 )
return;
F_17 ( L_3 , V_24 ) ;
F_8 ( & V_19 ) ;
F_12 (cpu) {
F_17 ( L_4 ,
V_3 , V_22 [ V_3 ] ) ;
V_5 = ( V_22 [ V_3 ] << V_25 )
/ V_24 ;
F_3 ( V_3 , V_5 ) ;
F_17 ( L_5 ,
V_3 , F_1 ( NULL , V_3 ) ) ;
}
F_10 ( & V_19 ) ;
}
int T_4 F_18 ( struct V_26 * V_27 , int V_3 )
{
int V_16 = 1 ;
T_5 V_28 ;
if ( V_23 )
return ! V_16 ;
V_16 = F_19 ( V_27 ,
L_6 ,
& V_28 ) ;
if ( ! V_16 ) {
if ( ! V_22 ) {
V_22 = F_20 ( F_21 () ,
sizeof( * V_22 ) ,
V_29 ) ;
if ( ! V_22 ) {
F_14 ( L_7 ) ;
V_23 = true ;
return 0 ;
}
}
V_24 = F_22 ( V_28 , V_24 ) ;
V_22 [ V_3 ] = V_28 ;
F_17 ( L_8 ,
V_27 -> V_30 , V_22 [ V_3 ] ) ;
} else {
if ( V_22 ) {
F_14 ( L_9 ,
V_27 -> V_30 ) ;
F_14 ( L_10 ) ;
}
V_23 = true ;
F_23 ( V_22 ) ;
}
return ! V_16 ;
}
static int
F_24 ( struct V_31 * V_32 ,
unsigned long V_33 ,
void * V_34 )
{
struct V_35 * V_36 = V_34 ;
int V_3 ;
if ( V_23 || V_37 )
return 0 ;
switch ( V_33 ) {
case V_38 :
F_17 ( L_11 ,
F_25 ( V_36 -> V_39 ) ,
F_25 ( V_40 ) ) ;
F_26 ( V_40 ,
V_40 ,
V_36 -> V_39 ) ;
F_9 (cpu, policy->related_cpus) {
V_22 [ V_3 ] = F_1 ( NULL , V_3 ) *
V_36 -> V_41 . V_42 / 1000UL ;
V_24 = F_22 ( V_22 [ V_3 ] , V_24 ) ;
}
if ( F_27 ( V_40 ) ) {
F_16 () ;
F_23 ( V_22 ) ;
F_17 ( L_12 ) ;
V_37 = true ;
F_28 ( & V_43 ) ;
}
}
return 0 ;
}
static int T_4 F_29 ( void )
{
if ( ! V_44 || ! V_22 )
return - V_18 ;
if ( ! F_30 ( & V_40 , V_29 ) ) {
F_14 ( L_13 ) ;
return - V_45 ;
}
F_31 ( V_40 , V_46 ) ;
return F_32 ( & V_47 ,
V_48 ) ;
}
static void F_33 ( struct V_49 * V_50 )
{
F_34 ( & V_47 ,
V_48 ) ;
}
static int T_4 F_35 ( void )
{
F_23 ( V_22 ) ;
return 0 ;
}
