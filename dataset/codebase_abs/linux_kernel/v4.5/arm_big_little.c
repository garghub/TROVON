static inline int F_1 ( int V_1 )
{
return F_2 ( V_1 ) ;
}
static inline int F_3 ( int V_1 )
{
return F_4 () ?
V_2 : F_1 ( V_1 ) ;
}
static unsigned int F_5 ( int V_3 )
{
int V_4 ;
T_1 V_5 = 0 , V_6 ;
F_6 (j) {
V_6 = F_7 ( V_7 , V_4 ) ;
if ( ( V_3 == F_7 ( V_8 , V_4 ) ) &&
( V_5 < V_6 ) )
V_5 = V_6 ;
}
F_8 ( L_1 , V_9 , V_3 ,
V_5 ) ;
return V_5 ;
}
static unsigned int F_9 ( unsigned int V_1 )
{
T_1 V_10 = F_7 ( V_8 , V_1 ) ;
T_1 V_11 = F_10 ( V_12 [ V_10 ] ) / 1000 ;
if ( F_4 () )
V_11 = F_11 ( V_10 , V_11 ) ;
F_8 ( L_2 , V_9 , V_1 ,
V_10 , V_11 ) ;
return V_11 ;
}
static unsigned int F_12 ( unsigned int V_1 )
{
if ( F_4 () ) {
F_8 ( L_3 , V_9 , F_7 ( V_7 ,
V_1 ) ) ;
return F_7 ( V_7 , V_1 ) ;
} else {
return F_9 ( V_1 ) ;
}
}
static unsigned int
F_13 ( T_1 V_1 , T_1 V_13 , T_1 V_14 , T_1 V_11 )
{
T_1 V_15 , V_16 ;
int V_17 ;
bool V_18 = F_4 () ;
F_14 ( & V_19 [ V_14 ] ) ;
if ( V_18 ) {
V_16 = F_7 ( V_7 , V_1 ) ;
F_7 ( V_7 , V_1 ) = V_11 ;
F_7 ( V_8 , V_1 ) = V_14 ;
V_15 = F_5 ( V_14 ) ;
V_15 = F_15 ( V_14 , V_15 ) ;
} else {
V_15 = V_11 ;
}
F_8 ( L_4 ,
V_9 , V_1 , V_13 , V_14 , V_15 ) ;
V_17 = F_16 ( V_12 [ V_14 ] , V_15 * 1000 ) ;
if ( ! V_17 ) {
if ( F_10 ( V_12 [ V_14 ] ) != V_15 * 1000 )
V_17 = - V_20 ;
}
if ( F_17 ( V_17 ) ) {
F_18 ( L_5 , V_17 ,
V_14 ) ;
if ( V_18 ) {
F_7 ( V_7 , V_1 ) = V_16 ;
F_7 ( V_8 , V_1 ) = V_13 ;
}
F_19 ( & V_19 [ V_14 ] ) ;
return V_17 ;
}
F_19 ( & V_19 [ V_14 ] ) ;
if ( V_13 != V_14 ) {
F_8 ( L_6 ,
V_9 , V_1 , V_13 , V_14 ) ;
F_20 ( V_1 , V_14 ) ;
F_14 ( & V_19 [ V_13 ] ) ;
V_15 = F_5 ( V_13 ) ;
V_15 = F_15 ( V_13 , V_15 ) ;
if ( V_15 ) {
F_8 ( L_7 ,
V_9 , V_13 , V_15 ) ;
if ( F_16 ( V_12 [ V_13 ] , V_15 * 1000 ) )
F_18 ( L_8 ,
V_9 , V_17 , V_13 ) ;
}
F_19 ( & V_19 [ V_13 ] ) ;
}
return 0 ;
}
static int F_21 ( struct V_21 * V_22 ,
unsigned int V_23 )
{
T_1 V_1 = V_22 -> V_1 , V_10 , V_14 , V_24 ;
unsigned int V_25 ;
V_10 = F_3 ( V_1 ) ;
V_14 = V_24 = F_7 ( V_8 , V_1 ) ;
V_25 = V_26 [ V_10 ] [ V_23 ] . V_27 ;
if ( F_4 () ) {
if ( ( V_24 == V_28 ) &&
( V_25 < V_29 ) ) {
V_14 = V_30 ;
} else if ( ( V_24 == V_30 ) &&
( V_25 > V_31 ) ) {
V_14 = V_28 ;
}
}
return F_13 ( V_1 , V_24 , V_14 , V_25 ) ;
}
static inline T_1 F_22 ( struct V_32 * V_33 )
{
int V_34 ;
for ( V_34 = 0 ; V_33 [ V_34 ] . V_27 != V_35 ; V_34 ++ )
;
return V_34 ;
}
static inline T_1 F_23 ( struct V_32 * V_33 )
{
struct V_32 * V_36 ;
T_2 V_37 = ~ 0 ;
F_24 (pos, table)
if ( V_36 -> V_27 < V_37 )
V_37 = V_36 -> V_27 ;
return V_37 ;
}
static inline T_1 F_25 ( struct V_32 * V_33 )
{
struct V_32 * V_36 ;
T_2 V_5 = 0 ;
F_24 (pos, table)
if ( V_36 -> V_27 > V_5 )
V_5 = V_36 -> V_27 ;
return V_5 ;
}
static int F_26 ( void )
{
int V_38 , V_4 , V_39 = 0 , V_34 = 1 ;
struct V_32 * V_33 ;
for ( V_38 = 0 ; V_38 < V_2 ; V_38 ++ )
V_34 += F_22 ( V_26 [ V_38 ] ) ;
V_33 = F_27 ( sizeof( * V_33 ) * V_34 , V_40 ) ;
if ( ! V_33 )
return - V_41 ;
V_26 [ V_2 ] = V_33 ;
for ( V_38 = V_2 - 1 ; V_38 >= 0 ; V_38 -- ) {
for ( V_4 = 0 ; V_26 [ V_38 ] [ V_4 ] . V_27 != V_35 ;
V_4 ++ ) {
V_33 [ V_39 ] . V_27 = F_11 ( V_38 ,
V_26 [ V_38 ] [ V_4 ] . V_27 ) ;
F_8 ( L_9 , V_9 , V_39 ,
V_33 [ V_39 ] . V_27 ) ;
V_39 ++ ;
}
}
V_33 [ V_39 ] . V_42 = V_39 ;
V_33 [ V_39 ] . V_27 = V_35 ;
F_8 ( L_10 , V_9 , V_33 , V_39 ) ;
return 0 ;
}
static void F_28 ( struct V_43 * V_44 )
{
T_1 V_3 = F_1 ( V_44 -> V_45 ) ;
if ( ! V_26 [ V_3 ] )
return;
F_29 ( V_12 [ V_3 ] ) ;
F_30 ( V_44 , & V_26 [ V_3 ] ) ;
if ( V_46 -> V_47 )
V_46 -> V_47 ( V_44 ) ;
F_31 ( V_44 , L_11 , V_9 , V_3 ) ;
}
static void F_32 ( struct V_43 * V_44 )
{
T_1 V_3 = F_3 ( V_44 -> V_45 ) ;
int V_38 ;
if ( F_33 ( & V_48 [ V_3 ] ) )
return;
if ( V_3 < V_2 )
return F_28 ( V_44 ) ;
F_34 (i) {
struct V_43 * V_49 = F_35 ( V_38 ) ;
if ( ! V_49 ) {
F_18 ( L_12 , V_9 , V_38 ) ;
return;
}
F_28 ( V_49 ) ;
}
F_36 ( V_26 [ V_3 ] ) ;
}
static int F_37 ( struct V_43 * V_44 )
{
T_1 V_3 = F_1 ( V_44 -> V_45 ) ;
int V_17 ;
if ( V_26 [ V_3 ] )
return 0 ;
V_17 = V_46 -> V_50 ( V_44 ) ;
if ( V_17 ) {
F_38 ( V_44 , L_13 ,
V_9 , V_44 -> V_45 , V_17 ) ;
goto V_51;
}
V_17 = F_39 ( V_44 , & V_26 [ V_3 ] ) ;
if ( V_17 ) {
F_38 ( V_44 , L_14 ,
V_9 , V_44 -> V_45 , V_17 ) ;
goto V_47;
}
V_12 [ V_3 ] = F_40 ( V_44 , NULL ) ;
if ( ! F_41 ( V_12 [ V_3 ] ) ) {
F_31 ( V_44 , L_15 ,
V_9 , V_12 [ V_3 ] , V_26 [ V_3 ] ,
V_3 ) ;
return 0 ;
}
F_38 ( V_44 , L_16 ,
V_9 , V_44 -> V_45 , V_3 ) ;
V_17 = F_42 ( V_12 [ V_3 ] ) ;
F_30 ( V_44 , & V_26 [ V_3 ] ) ;
V_47:
if ( V_46 -> V_47 )
V_46 -> V_47 ( V_44 ) ;
V_51:
F_38 ( V_44 , L_17 , V_9 ,
V_3 ) ;
return V_17 ;
}
static int F_43 ( struct V_43 * V_44 )
{
T_1 V_3 = F_3 ( V_44 -> V_45 ) ;
int V_38 , V_17 ;
if ( F_44 ( & V_48 [ V_3 ] ) != 1 )
return 0 ;
if ( V_3 < V_2 ) {
V_17 = F_37 ( V_44 ) ;
if ( V_17 )
F_45 ( & V_48 [ V_3 ] ) ;
return V_17 ;
}
F_34 (i) {
struct V_43 * V_49 = F_35 ( V_38 ) ;
if ( ! V_49 ) {
F_18 ( L_12 , V_9 , V_38 ) ;
return - V_52 ;
}
V_17 = F_37 ( V_49 ) ;
if ( V_17 )
goto V_53;
}
V_17 = F_26 () ;
if ( V_17 )
goto V_53;
V_29 = F_23 ( V_26 [ 0 ] ) ;
V_31 = F_11 ( 1 , F_25 ( V_26 [ 1 ] ) ) ;
F_8 ( L_18 ,
V_9 , V_3 , V_29 , V_31 ) ;
return 0 ;
V_53:
F_34 (i) {
struct V_43 * V_49 = F_35 ( V_38 ) ;
if ( ! V_49 ) {
F_18 ( L_12 , V_9 , V_38 ) ;
return - V_52 ;
}
F_28 ( V_49 ) ;
}
F_45 ( & V_48 [ V_3 ] ) ;
return V_17 ;
}
static int F_46 ( struct V_21 * V_22 )
{
T_1 V_10 = F_3 ( V_22 -> V_1 ) ;
struct V_43 * V_44 ;
int V_17 ;
V_44 = F_35 ( V_22 -> V_1 ) ;
if ( ! V_44 ) {
F_18 ( L_12 , V_9 ,
V_22 -> V_1 ) ;
return - V_52 ;
}
V_17 = F_43 ( V_44 ) ;
if ( V_17 )
return V_17 ;
V_17 = F_47 ( V_22 , V_26 [ V_10 ] ) ;
if ( V_17 ) {
F_38 ( V_44 , L_19 ,
V_22 -> V_1 , V_10 ) ;
F_32 ( V_44 ) ;
return V_17 ;
}
if ( V_10 < V_2 ) {
int V_1 ;
F_48 ( V_22 -> V_54 , F_49 ( V_22 -> V_1 ) ) ;
F_50 (cpu, policy->cpus)
F_7 ( V_8 , V_1 ) = V_10 ;
} else {
F_7 ( V_8 , V_22 -> V_1 ) = V_28 ;
}
if ( V_46 -> V_55 )
V_22 -> V_56 . V_57 =
V_46 -> V_55 ( V_44 ) ;
else
V_22 -> V_56 . V_57 = V_58 ;
if ( F_4 () )
F_7 ( V_7 , V_22 -> V_1 ) = F_9 ( V_22 -> V_1 ) ;
F_51 ( V_44 , L_20 , V_9 , V_22 -> V_1 ) ;
return 0 ;
}
static int F_52 ( struct V_21 * V_22 )
{
struct V_43 * V_44 ;
int V_10 = F_3 ( V_22 -> V_1 ) ;
if ( V_10 < V_2 ) {
F_53 ( V_49 [ V_10 ] ) ;
V_49 [ V_10 ] = NULL ;
}
V_44 = F_35 ( V_22 -> V_1 ) ;
if ( ! V_44 ) {
F_18 ( L_12 , V_9 ,
V_22 -> V_1 ) ;
return - V_52 ;
}
F_32 ( V_44 ) ;
F_31 ( V_44 , L_21 , V_9 , V_22 -> V_1 ) ;
return 0 ;
}
static void F_54 ( struct V_21 * V_22 )
{
struct V_43 * V_44 = F_35 ( V_22 -> V_1 ) ;
int V_10 = F_3 ( V_22 -> V_1 ) ;
struct V_59 * V_60 ;
if ( V_10 >= V_2 )
return;
V_60 = F_55 ( V_44 -> V_61 ) ;
if ( F_17 ( ! V_60 ) )
return;
if ( F_56 ( V_60 , L_22 , NULL ) ) {
T_1 V_62 = 0 ;
F_57 ( V_60 , L_23 ,
& V_62 ) ;
V_49 [ V_10 ] = F_58 ( V_60 ,
V_22 -> V_63 , V_62 , NULL ) ;
if ( F_41 ( V_49 [ V_10 ] ) ) {
F_38 ( V_44 ,
L_24 ,
F_42 ( V_49 [ V_10 ] ) ) ;
V_49 [ V_10 ] = NULL ;
}
}
F_59 ( V_60 ) ;
}
static int F_60 ( struct V_64 * V_65 ,
unsigned long V_66 , void * V_67 )
{
F_8 ( L_25 , V_9 , V_66 ) ;
switch ( V_66 ) {
case V_68 :
case V_69 :
F_61 ( & V_70 ) ;
break;
case V_71 :
F_62 ( true ) ;
F_63 ( & V_70 ) ;
break;
case V_72 :
F_62 ( false ) ;
F_63 ( & V_70 ) ;
break;
default:
return V_73 ;
}
return V_74 ;
}
static int F_64 ( void )
{
return F_65 ( & V_75 ) ;
}
static int F_66 ( void )
{
return F_67 ( & V_75 ) ;
}
static int F_64 ( void ) { return 0 ; }
static int F_66 ( void ) { return 0 ; }
int F_68 ( struct V_76 * V_77 )
{
int V_17 , V_38 ;
if ( V_46 ) {
F_8 ( L_26 , V_9 ,
V_46 -> V_78 ) ;
return - V_79 ;
}
if ( ! V_77 || ! strlen ( V_77 -> V_78 ) || ! V_77 -> V_50 ) {
F_18 ( L_27 , V_9 ) ;
return - V_52 ;
}
V_46 = V_77 ;
F_62 ( F_69 () ) ;
for ( V_38 = 0 ; V_38 < V_2 ; V_38 ++ )
F_70 ( & V_19 [ V_38 ] ) ;
V_17 = F_63 ( & V_70 ) ;
if ( V_17 ) {
F_71 ( L_28 ,
V_9 , V_77 -> V_78 , V_17 ) ;
V_46 = NULL ;
} else {
V_17 = F_64 () ;
if ( V_17 ) {
F_61 ( & V_70 ) ;
V_46 = NULL ;
} else {
F_71 ( L_29 ,
V_9 , V_77 -> V_78 ) ;
}
}
F_72 () ;
return V_17 ;
}
void F_73 ( struct V_76 * V_77 )
{
if ( V_46 != V_77 ) {
F_18 ( L_30 ,
V_9 , V_46 -> V_78 ) ;
return;
}
F_69 () ;
F_66 () ;
F_61 ( & V_70 ) ;
F_72 () ;
F_71 ( L_31 , V_9 ,
V_46 -> V_78 ) ;
V_46 = NULL ;
}
