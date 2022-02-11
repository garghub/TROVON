unsigned long F_1 ( struct V_1 * V_2 , int V_3 )
{
return F_2 ( V_4 , V_3 ) ;
}
static void F_3 ( unsigned int V_3 , unsigned long V_5 )
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
int V_13 = V_3 -> V_7 . V_11 , V_14 ;
unsigned long V_15 ;
T_1 V_16 ;
if ( V_12 ) {
V_16 = F_7 ( V_10 , 0 , & V_15 ) ;
if ( V_16 )
return V_16 ;
if ( V_15 > V_17 )
return - V_18 ;
F_8 ( & V_19 ) ;
F_9 (i, &cpu_topology[this_cpu].core_sibling)
F_3 ( V_14 , V_15 ) ;
F_10 ( & V_19 ) ;
}
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
static int T_3 F_16 ( struct V_22 * V_23 , int V_3 )
{
int V_16 = 1 ;
T_4 V_24 ;
if ( V_25 )
return ! V_16 ;
V_16 = F_17 ( V_23 ,
L_3 ,
& V_24 ) ;
if ( ! V_16 ) {
if ( ! V_26 ) {
V_26 = F_18 ( F_19 () ,
sizeof( * V_26 ) ,
V_27 ) ;
if ( ! V_26 ) {
F_14 ( L_4 ) ;
V_25 = true ;
return ! V_16 ;
}
}
V_28 = F_20 ( V_24 , V_28 ) ;
V_26 [ V_3 ] = V_24 ;
F_21 ( L_5 ,
V_23 -> V_29 , V_26 [ V_3 ] ) ;
} else {
if ( V_26 ) {
F_14 ( L_6 ,
V_23 -> V_29 ) ;
F_14 ( L_7 ) ;
}
V_25 = true ;
F_22 ( V_26 ) ;
}
return ! V_16 ;
}
static void F_23 ( void )
{
T_5 V_5 ;
int V_3 ;
if ( ! V_26 || V_25 )
return;
F_21 ( L_8 , V_28 ) ;
F_8 ( & V_19 ) ;
F_12 (cpu) {
V_5 = ( V_26 [ V_3 ] << V_30 )
/ V_28 ;
F_3 ( V_3 , V_5 ) ;
F_21 ( L_9 ,
V_3 , F_1 ( NULL , V_3 ) ) ;
}
F_10 ( & V_19 ) ;
}
static int
F_24 ( struct V_31 * V_32 ,
unsigned long V_33 ,
void * V_34 )
{
struct V_35 * V_36 = V_34 ;
int V_3 ;
if ( V_25 || V_37 )
return 0 ;
switch ( V_33 ) {
case V_38 :
F_21 ( L_10 ,
F_25 ( V_36 -> V_39 ) ,
F_25 ( V_40 ) ) ;
F_26 ( V_40 ,
V_40 ,
V_36 -> V_39 ) ;
F_9 (cpu, policy->related_cpus) {
V_26 [ V_3 ] = F_1 ( NULL , V_3 ) *
V_36 -> V_41 . V_42 / 1000UL ;
V_28 = F_20 ( V_26 [ V_3 ] , V_28 ) ;
}
if ( F_27 ( V_40 ) ) {
F_23 () ;
F_22 ( V_26 ) ;
F_21 ( L_11 ) ;
V_37 = true ;
F_28 ( & V_43 ) ;
}
}
return 0 ;
}
static int T_3 F_29 ( void )
{
if ( V_25 )
return - V_18 ;
if ( ! F_30 ( & V_40 , V_27 ) ) {
F_14 ( L_12 ) ;
return - V_44 ;
}
F_31 ( V_40 , V_45 ) ;
return F_32 ( & V_46 ,
V_47 ) ;
}
static void F_33 ( struct V_48 * V_49 )
{
F_34 ( & V_46 ,
V_47 ) ;
}
static int T_3 F_35 ( void )
{
F_22 ( V_26 ) ;
return 0 ;
}
static void T_3 F_36 ( void )
{
const struct V_50 * V_51 ;
struct V_22 * V_52 = NULL ;
unsigned long V_53 = V_54 ;
unsigned long V_55 = 0 ;
unsigned long V_5 = 0 ;
int V_3 = 0 ;
V_56 = F_18 ( V_57 , sizeof( * V_56 ) ,
V_58 ) ;
V_52 = F_37 ( L_13 ) ;
if ( ! V_52 ) {
F_14 ( L_14 ) ;
return;
}
F_12 (cpu) {
const T_4 * V_59 ;
int V_60 ;
V_52 = F_38 ( V_3 , NULL ) ;
if ( ! V_52 ) {
F_14 ( L_15 , V_3 ) ;
continue;
}
if ( F_16 ( V_52 , V_3 ) ) {
F_39 ( V_52 ) ;
continue;
}
V_61 = false ;
for ( V_51 = V_62 ; V_51 -> V_63 ; V_51 ++ )
if ( F_40 ( V_52 , V_51 -> V_63 ) )
break;
if ( V_51 -> V_63 == NULL )
continue;
V_59 = F_41 ( V_52 , L_16 , & V_60 ) ;
if ( ! V_59 || V_60 != 4 ) {
F_14 ( L_17 ,
V_52 -> V_29 ) ;
continue;
}
V_5 = ( ( F_42 ( V_59 ) ) >> 20 ) * V_51 -> V_64 ;
if ( V_5 < V_53 )
V_53 = V_5 ;
if ( V_5 > V_55 )
V_55 = V_5 ;
V_24 ( V_3 ) = V_5 ;
}
if ( 4 * V_55 < ( 3 * ( V_55 + V_53 ) ) )
V_65 = ( V_53 + V_55 )
>> ( V_30 + 1 ) ;
else
V_65 = ( ( V_55 / 3 )
>> ( V_30 - 1 ) ) + 1 ;
if ( V_61 && ! V_25 )
F_23 () ;
}
static void F_43 ( unsigned int V_3 )
{
if ( ! V_24 ( V_3 ) || V_61 )
return;
F_3 ( V_3 , V_24 ( V_3 ) / V_65 ) ;
F_44 ( L_18 ,
V_3 , F_1 ( NULL , V_3 ) ) ;
}
static inline void F_36 ( void ) {}
static inline void F_43 ( unsigned int V_66 ) {}
const struct V_67 * F_45 ( int V_3 )
{
return & V_68 [ V_3 ] . V_69 ;
}
const struct V_67 * F_46 ( int V_3 )
{
return & V_68 [ V_3 ] . V_70 ;
}
static void F_47 ( unsigned int V_66 )
{
struct V_71 * V_72 , * V_73 = & V_68 [ V_66 ] ;
int V_3 ;
F_12 (cpu) {
V_72 = & V_68 [ V_3 ] ;
if ( V_73 -> V_74 != V_72 -> V_74 )
continue;
F_48 ( V_66 , & V_72 -> V_69 ) ;
if ( V_3 != V_66 )
F_48 ( V_3 , & V_73 -> V_69 ) ;
if ( V_73 -> V_75 != V_72 -> V_75 )
continue;
F_48 ( V_66 , & V_72 -> V_70 ) ;
if ( V_3 != V_66 )
F_48 ( V_3 , & V_73 -> V_70 ) ;
}
F_49 () ;
}
void F_50 ( unsigned int V_66 )
{
struct V_71 * V_73 = & V_68 [ V_66 ] ;
unsigned int V_76 ;
if ( V_73 -> V_75 != - 1 )
return;
V_76 = F_51 () ;
if ( ( V_76 & V_77 ) == V_78 ) {
if ( V_76 & V_79 ) {
V_73 -> V_80 = F_52 ( V_76 , 0 ) ;
V_73 -> V_75 = F_52 ( V_76 , 1 ) ;
V_73 -> V_74 = F_52 ( V_76 , 2 ) ;
} else {
V_73 -> V_80 = - 1 ;
V_73 -> V_75 = F_52 ( V_76 , 0 ) ;
V_73 -> V_74 = F_52 ( V_76 , 1 ) ;
}
} else {
V_73 -> V_80 = - 1 ;
V_73 -> V_75 = 0 ;
V_73 -> V_74 = - 1 ;
}
F_47 ( V_66 ) ;
F_43 ( V_66 ) ;
F_44 ( L_19 ,
V_66 , V_68 [ V_66 ] . V_80 ,
V_68 [ V_66 ] . V_75 ,
V_68 [ V_66 ] . V_74 , V_76 ) ;
}
static inline int F_53 ( void )
{
return V_81 | V_82 ;
}
void T_3 F_54 ( void )
{
unsigned int V_3 ;
F_12 (cpu) {
struct V_71 * V_72 = & ( V_68 [ V_3 ] ) ;
V_72 -> V_80 = - 1 ;
V_72 -> V_75 = - 1 ;
V_72 -> V_74 = - 1 ;
F_55 ( & V_72 -> V_69 ) ;
F_55 ( & V_72 -> V_70 ) ;
}
F_49 () ;
F_36 () ;
F_56 ( V_83 ) ;
}
