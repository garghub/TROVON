static inline int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_5 )
{
return ( V_4 - V_2 -> V_3 ) * V_6 + V_5 ;
}
int F_2 ( struct V_7 * V_8 )
{
int V_9 = 0 ;
struct V_10 * V_10 ;
F_3 () ;
V_10 = F_4 ( V_8 ) ;
if ( V_10 != NULL && V_10 -> V_11 [ V_10 -> V_12 ] . V_13 == 1 )
V_9 = 1 ;
F_5 () ;
return V_9 ;
}
static void F_6 ( struct V_14 * V_14 )
{
int V_13 = V_14 -> V_13 ;
struct V_3 * V_4 = V_14 -> V_15 -> V_3 + V_13 / V_6 ;
int V_16 = V_13 & V_17 ;
F_7 ( V_16 , V_4 -> V_18 ) ;
F_8 ( & V_4 -> V_19 ) ;
}
static int F_9 ( int V_20 , int V_21 , int V_22 )
{
return ( unsigned ) ( V_21 - V_20 ) < ( unsigned ) ( V_22 - V_20 ) ;
}
static void F_10 ( struct V_1 * V_2 , int V_20 , int V_10 )
{
int V_23 ;
int V_24 = V_20 ;
do {
V_23 = V_24 ;
V_24 = F_11 ( & V_2 -> V_25 , V_23 , V_10 ) ;
} while ( ( V_23 != V_24 ) && ( F_9 ( V_20 , V_24 , V_10 ) ) );
}
static int F_12 ( struct V_1 * V_2 )
{
int V_26 , V_16 , V_27 , V_10 , V_28 = V_2 -> V_25 ;
struct V_3 * V_4 ;
V_10 = V_28 + 1 ;
if ( V_10 >= V_29 )
V_10 = V_30 ;
V_16 = V_10 & V_17 ;
V_4 = & V_2 -> V_3 [ V_10 / V_6 ] ;
V_27 = F_13 ( V_29 , V_6 ) - ! V_16 ;
for ( V_26 = 0 ; V_26 <= V_27 ; ++ V_26 ) {
if ( F_14 ( ! V_4 -> V_18 ) ) {
void * V_18 = F_15 ( V_31 , V_32 ) ;
F_16 ( & V_33 ) ;
if ( ! V_4 -> V_18 ) {
V_4 -> V_18 = V_18 ;
V_18 = NULL ;
}
F_17 ( & V_33 ) ;
F_18 ( V_18 ) ;
if ( F_14 ( ! V_4 -> V_18 ) )
break;
}
if ( F_19 ( F_20 ( & V_4 -> V_19 ) ) ) {
do {
if ( ! F_21 ( V_16 , V_4 -> V_18 ) ) {
F_22 ( & V_4 -> V_19 ) ;
F_10 ( V_2 , V_28 , V_10 ) ;
return V_10 ;
}
V_16 = F_23 ( V_4 , V_16 ) ;
V_10 = F_1 ( V_2 , V_4 , V_16 ) ;
} while ( V_16 < V_6 && V_10 < V_29 );
}
if ( V_4 < & V_2 -> V_3 [ ( V_29 - 1 ) / V_6 ] ) {
++ V_4 ;
V_16 = 0 ;
} else {
V_4 = & V_2 -> V_3 [ 0 ] ;
V_16 = V_30 ;
if ( F_14 ( V_28 == V_16 ) )
break;
}
V_10 = F_1 ( V_2 , V_4 , V_16 ) ;
}
return - 1 ;
}
int F_24 ( struct V_1 * V_2 , unsigned int V_28 )
{
int V_16 ;
struct V_3 * V_4 , * V_34 ;
if ( V_28 >= V_35 )
return - 1 ;
V_16 = ( V_28 + 1 ) & V_17 ;
V_4 = & V_2 -> V_3 [ ( V_28 + 1 ) / V_6 ] ;
V_34 = & V_2 -> V_3 [ V_36 ] ;
for (; V_4 < V_34 ; V_4 ++ , V_16 = 0 ) {
if ( F_14 ( ! V_4 -> V_18 ) )
continue;
V_16 = F_25 ( ( V_4 ) -> V_18 , V_6 , V_16 ) ;
if ( V_16 < V_6 )
return F_1 ( V_2 , V_4 , V_16 ) ;
}
return - 1 ;
}
void F_26 ( struct V_10 * V_10 )
{
struct V_1 * V_15 ;
if ( ! V_10 )
return;
V_15 = V_10 -> V_11 [ V_10 -> V_12 ] . V_15 ;
if ( ( F_20 ( & V_10 -> V_37 ) == 1 ) ||
F_27 ( & V_10 -> V_37 ) ) {
F_28 ( V_15 -> V_38 , V_10 ) ;
F_29 ( V_15 ) ;
}
}
static void F_30 ( struct V_39 * V_40 )
{
struct V_10 * V_10 = F_31 ( V_40 , struct V_10 , V_41 ) ;
F_26 ( V_10 ) ;
}
void F_32 ( struct V_10 * V_10 )
{
int V_26 ;
unsigned long V_42 ;
F_33 ( & V_33 , V_42 ) ;
for ( V_26 = 0 ; V_26 <= V_10 -> V_12 ; V_26 ++ )
F_34 ( & V_10 -> V_11 [ V_26 ] . V_43 ) ;
F_35 ( & V_33 , V_42 ) ;
for ( V_26 = 0 ; V_26 <= V_10 -> V_12 ; V_26 ++ )
F_6 ( V_10 -> V_11 + V_26 ) ;
F_36 ( & V_10 -> V_41 , F_30 ) ;
}
struct V_10 * F_37 ( struct V_1 * V_15 )
{
struct V_10 * V_10 ;
enum V_44 type ;
int V_26 , V_13 ;
struct V_1 * V_45 ;
struct V_14 * V_14 ;
V_10 = F_38 ( V_15 -> V_38 , V_32 ) ;
if ( ! V_10 )
goto V_46;
V_45 = V_15 ;
for ( V_26 = V_15 -> V_12 ; V_26 >= 0 ; V_26 -- ) {
V_13 = F_12 ( V_45 ) ;
if ( V_13 < 0 )
goto V_47;
V_10 -> V_11 [ V_26 ] . V_13 = V_13 ;
V_10 -> V_11 [ V_26 ] . V_15 = V_45 ;
V_45 = V_45 -> V_48 ;
}
F_39 ( V_15 ) ;
V_10 -> V_12 = V_15 -> V_12 ;
F_40 ( & V_10 -> V_37 , 1 ) ;
for ( type = 0 ; type < V_49 ; ++ type )
F_41 ( & V_10 -> V_50 [ type ] ) ;
V_14 = V_10 -> V_11 + V_15 -> V_12 ;
F_16 ( & V_33 ) ;
for ( ; V_14 >= V_10 -> V_11 ; -- V_14 )
F_42 ( & V_14 -> V_43 ,
& V_51 [ F_43 ( V_14 -> V_13 , V_14 -> V_15 ) ] ) ;
F_17 ( & V_33 ) ;
V_46:
return V_10 ;
V_47:
while ( ++ V_26 <= V_15 -> V_12 )
F_6 ( V_10 -> V_11 + V_26 ) ;
F_28 ( V_15 -> V_38 , V_10 ) ;
V_10 = NULL ;
goto V_46;
}
struct V_10 * F_44 ( int V_13 , struct V_1 * V_15 )
{
struct V_52 * V_53 ;
struct V_14 * V_54 ;
F_45 (pnr, elem,
&pid_hash[pid_hashfn(nr, ns)], pid_chain)
if ( V_54 -> V_13 == V_13 && V_54 -> V_15 == V_15 )
return F_31 ( V_54 , struct V_10 ,
V_11 [ V_15 -> V_12 ] ) ;
return NULL ;
}
struct V_10 * F_46 ( int V_13 )
{
return F_44 ( V_13 , V_55 -> V_56 -> V_2 ) ;
}
void F_47 ( struct V_7 * V_57 , enum V_44 type ,
struct V_10 * V_10 )
{
struct V_58 * V_59 ;
V_59 = & V_57 -> V_60 [ type ] ;
V_59 -> V_10 = V_10 ;
F_42 ( & V_59 -> V_61 , & V_10 -> V_50 [ type ] ) ;
}
static void F_48 ( struct V_7 * V_57 , enum V_44 type ,
struct V_10 * V_62 )
{
struct V_58 * V_59 ;
struct V_10 * V_10 ;
int V_45 ;
V_59 = & V_57 -> V_60 [ type ] ;
V_10 = V_59 -> V_10 ;
F_34 ( & V_59 -> V_61 ) ;
V_59 -> V_10 = V_62 ;
for ( V_45 = V_49 ; -- V_45 >= 0 ; )
if ( ! F_49 ( & V_10 -> V_50 [ V_45 ] ) )
return;
F_32 ( V_10 ) ;
}
void F_50 ( struct V_7 * V_57 , enum V_44 type )
{
F_48 ( V_57 , type , NULL ) ;
}
void F_51 ( struct V_7 * V_57 , enum V_44 type ,
struct V_10 * V_10 )
{
F_48 ( V_57 , type , V_10 ) ;
F_47 ( V_57 , type , V_10 ) ;
}
void F_52 ( struct V_7 * V_63 , struct V_7 * V_62 ,
enum V_44 type )
{
V_62 -> V_60 [ type ] . V_10 = V_63 -> V_60 [ type ] . V_10 ;
F_53 ( & V_63 -> V_60 [ type ] . V_61 , & V_62 -> V_60 [ type ] . V_61 ) ;
}
struct V_7 * F_54 ( struct V_10 * V_10 , enum V_44 type )
{
struct V_7 * V_64 = NULL ;
if ( V_10 ) {
struct V_52 * V_65 ;
V_65 = F_55 ( F_56 ( & V_10 -> V_50 [ type ] ) ,
F_57 () ) ;
if ( V_65 )
V_64 = F_58 ( V_65 , struct V_7 , V_60 [ ( type ) ] . V_61 ) ;
}
return V_64 ;
}
struct V_7 * F_59 ( T_1 V_13 , struct V_1 * V_15 )
{
F_60 ( F_61 () ,
L_1
L_2 ) ;
return F_54 ( F_44 ( V_13 , V_15 ) , V_66 ) ;
}
struct V_7 * F_62 ( T_1 V_67 )
{
return F_59 ( V_67 , V_55 -> V_56 -> V_2 ) ;
}
struct V_10 * F_63 ( struct V_7 * V_57 , enum V_44 type )
{
struct V_10 * V_10 ;
F_3 () ;
if ( type != V_66 )
V_57 = V_57 -> V_68 ;
V_10 = F_64 ( V_57 -> V_60 [ type ] . V_10 ) ;
F_5 () ;
return V_10 ;
}
struct V_7 * F_65 ( struct V_10 * V_10 , enum V_44 type )
{
struct V_7 * V_64 ;
F_3 () ;
V_64 = F_54 ( V_10 , type ) ;
if ( V_64 )
F_66 ( V_64 ) ;
F_5 () ;
return V_64 ;
}
struct V_10 * F_67 ( T_1 V_13 )
{
struct V_10 * V_10 ;
F_3 () ;
V_10 = F_64 ( F_46 ( V_13 ) ) ;
F_5 () ;
return V_10 ;
}
T_1 F_68 ( struct V_10 * V_10 , struct V_1 * V_15 )
{
struct V_14 * V_14 ;
T_1 V_13 = 0 ;
if ( V_10 && V_15 -> V_12 <= V_10 -> V_12 ) {
V_14 = & V_10 -> V_11 [ V_15 -> V_12 ] ;
if ( V_14 -> V_15 == V_15 )
V_13 = V_14 -> V_13 ;
}
return V_13 ;
}
T_1 F_69 ( struct V_10 * V_10 )
{
return F_68 ( V_10 , V_55 -> V_56 -> V_2 ) ;
}
T_1 F_70 ( struct V_7 * V_57 , enum V_44 type ,
struct V_1 * V_15 )
{
T_1 V_13 = 0 ;
F_3 () ;
if ( ! V_15 )
V_15 = V_55 -> V_56 -> V_2 ;
if ( F_19 ( F_71 ( V_57 ) ) ) {
if ( type != V_66 )
V_57 = V_57 -> V_68 ;
V_13 = F_68 ( V_57 -> V_60 [ type ] . V_10 , V_15 ) ;
}
F_5 () ;
return V_13 ;
}
T_1 F_72 ( struct V_7 * V_8 , struct V_1 * V_15 )
{
return F_68 ( F_73 ( V_8 ) , V_15 ) ;
}
struct V_1 * F_74 ( struct V_7 * V_8 )
{
return F_75 ( F_4 ( V_8 ) ) ;
}
struct V_10 * F_76 ( int V_13 , struct V_1 * V_15 )
{
struct V_10 * V_10 ;
do {
V_10 = F_44 ( V_13 , V_15 ) ;
if ( V_10 )
break;
V_13 = F_24 ( V_15 , V_13 ) ;
} while ( V_13 > 0 );
return V_10 ;
}
void T_2 F_77 ( void )
{
int V_26 , V_69 ;
V_51 = F_78 ( L_3 , sizeof( * V_51 ) , 0 , 18 ,
V_70 | V_71 ,
& V_72 , NULL , 4096 ) ;
V_69 = 1 << V_72 ;
for ( V_26 = 0 ; V_26 < V_69 ; V_26 ++ )
F_41 ( & V_51 [ V_26 ] ) ;
}
void T_2 F_79 ( void )
{
V_29 = F_80 ( V_73 , F_81 ( int , V_29 ,
V_74 * F_82 () ) ) ;
V_75 = F_81 ( int , V_75 ,
V_76 * F_82 () ) ;
F_83 ( L_4 , V_29 , V_75 ) ;
V_77 . V_3 [ 0 ] . V_18 = F_15 ( V_31 , V_32 ) ;
F_84 ( 0 , V_77 . V_3 [ 0 ] . V_18 ) ;
F_22 ( & V_77 . V_3 [ 0 ] . V_19 ) ;
V_77 . V_38 = F_85 ( V_10 ,
V_78 | V_79 ) ;
}
