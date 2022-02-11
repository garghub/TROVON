static inline int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_5 )
{
return ( V_4 - V_2 -> V_3 ) * V_6 + V_5 ;
}
static void F_2 ( struct V_7 * V_7 )
{
int V_8 = V_7 -> V_8 ;
struct V_3 * V_4 = V_7 -> V_9 -> V_3 + V_8 / V_6 ;
int V_10 = V_8 & V_11 ;
F_3 ( V_10 , V_4 -> V_12 ) ;
F_4 ( & V_4 -> V_13 ) ;
}
static int F_5 ( int V_14 , int V_15 , int V_16 )
{
return ( unsigned ) ( V_15 - V_14 ) < ( unsigned ) ( V_16 - V_14 ) ;
}
static void F_6 ( struct V_1 * V_2 , int V_14 , int V_17 )
{
int V_18 ;
int V_19 = V_14 ;
do {
V_18 = V_19 ;
V_19 = F_7 ( & V_2 -> V_20 , V_18 , V_17 ) ;
} while ( ( V_18 != V_19 ) && ( F_5 ( V_14 , V_19 , V_17 ) ) );
}
static int F_8 ( struct V_1 * V_2 )
{
int V_21 , V_10 , V_22 , V_17 , V_23 = V_2 -> V_20 ;
struct V_3 * V_4 ;
V_17 = V_23 + 1 ;
if ( V_17 >= V_24 )
V_17 = V_25 ;
V_10 = V_17 & V_11 ;
V_4 = & V_2 -> V_3 [ V_17 / V_6 ] ;
V_22 = F_9 ( V_24 , V_6 ) - ! V_10 ;
for ( V_21 = 0 ; V_21 <= V_22 ; ++ V_21 ) {
if ( F_10 ( ! V_4 -> V_12 ) ) {
void * V_12 = F_11 ( V_26 , V_27 ) ;
F_12 ( & V_28 ) ;
if ( ! V_4 -> V_12 ) {
V_4 -> V_12 = V_12 ;
V_12 = NULL ;
}
F_13 ( & V_28 ) ;
F_14 ( V_12 ) ;
if ( F_10 ( ! V_4 -> V_12 ) )
break;
}
if ( F_15 ( F_16 ( & V_4 -> V_13 ) ) ) {
do {
if ( ! F_17 ( V_10 , V_4 -> V_12 ) ) {
F_18 ( & V_4 -> V_13 ) ;
F_6 ( V_2 , V_23 , V_17 ) ;
return V_17 ;
}
V_10 = F_19 ( V_4 , V_10 ) ;
V_17 = F_1 ( V_2 , V_4 , V_10 ) ;
} while ( V_10 < V_6 && V_17 < V_24 );
}
if ( V_4 < & V_2 -> V_3 [ ( V_24 - 1 ) / V_6 ] ) {
++ V_4 ;
V_10 = 0 ;
} else {
V_4 = & V_2 -> V_3 [ 0 ] ;
V_10 = V_25 ;
if ( F_10 ( V_23 == V_10 ) )
break;
}
V_17 = F_1 ( V_2 , V_4 , V_10 ) ;
}
return - 1 ;
}
int F_20 ( struct V_1 * V_2 , unsigned int V_23 )
{
int V_10 ;
struct V_3 * V_4 , * V_29 ;
if ( V_23 >= V_30 )
return - 1 ;
V_10 = ( V_23 + 1 ) & V_11 ;
V_4 = & V_2 -> V_3 [ ( V_23 + 1 ) / V_6 ] ;
V_29 = & V_2 -> V_3 [ V_31 ] ;
for (; V_4 < V_29 ; V_4 ++ , V_10 = 0 ) {
if ( F_10 ( ! V_4 -> V_12 ) )
continue;
V_10 = F_21 ( ( V_4 ) -> V_12 , V_6 , V_10 ) ;
if ( V_10 < V_6 )
return F_1 ( V_2 , V_4 , V_10 ) ;
}
return - 1 ;
}
void F_22 ( struct V_17 * V_17 )
{
struct V_1 * V_9 ;
if ( ! V_17 )
return;
V_9 = V_17 -> V_32 [ V_17 -> V_33 ] . V_9 ;
if ( ( F_16 ( & V_17 -> V_34 ) == 1 ) ||
F_23 ( & V_17 -> V_34 ) ) {
F_24 ( V_9 -> V_35 , V_17 ) ;
F_25 ( V_9 ) ;
}
}
static void F_26 ( struct V_36 * V_37 )
{
struct V_17 * V_17 = F_27 ( V_37 , struct V_17 , V_38 ) ;
F_22 ( V_17 ) ;
}
void F_28 ( struct V_17 * V_17 )
{
int V_21 ;
unsigned long V_39 ;
F_29 ( & V_28 , V_39 ) ;
for ( V_21 = 0 ; V_21 <= V_17 -> V_33 ; V_21 ++ ) {
struct V_7 * V_7 = V_17 -> V_32 + V_21 ;
struct V_1 * V_9 = V_7 -> V_9 ;
F_30 ( & V_7 -> V_40 ) ;
switch( -- V_9 -> V_41 ) {
case 1 :
F_31 ( V_9 -> V_42 ) ;
break;
case 0 :
F_32 ( & V_9 -> V_43 ) ;
break;
}
}
F_33 ( & V_28 , V_39 ) ;
for ( V_21 = 0 ; V_21 <= V_17 -> V_33 ; V_21 ++ )
F_2 ( V_17 -> V_32 + V_21 ) ;
F_34 ( & V_17 -> V_38 , F_26 ) ;
}
struct V_17 * F_35 ( struct V_1 * V_9 )
{
struct V_17 * V_17 ;
enum V_44 type ;
int V_21 , V_8 ;
struct V_1 * V_45 ;
struct V_7 * V_7 ;
V_17 = F_36 ( V_9 -> V_35 , V_27 ) ;
if ( ! V_17 )
goto V_46;
V_45 = V_9 ;
V_17 -> V_33 = V_9 -> V_33 ;
for ( V_21 = V_9 -> V_33 ; V_21 >= 0 ; V_21 -- ) {
V_8 = F_8 ( V_45 ) ;
if ( V_8 < 0 )
goto V_47;
V_17 -> V_32 [ V_21 ] . V_8 = V_8 ;
V_17 -> V_32 [ V_21 ] . V_9 = V_45 ;
V_45 = V_45 -> V_48 ;
}
if ( F_10 ( F_37 ( V_17 ) ) ) {
if ( F_38 ( V_9 ) )
goto V_47;
}
F_39 ( V_9 ) ;
F_40 ( & V_17 -> V_34 , 1 ) ;
for ( type = 0 ; type < V_49 ; ++ type )
F_41 ( & V_17 -> V_50 [ type ] ) ;
V_7 = V_17 -> V_32 + V_9 -> V_33 ;
F_12 ( & V_28 ) ;
if ( ! ( V_9 -> V_41 & V_51 ) )
goto V_52;
for ( ; V_7 >= V_17 -> V_32 ; -- V_7 ) {
F_42 ( & V_7 -> V_40 ,
& V_53 [ F_43 ( V_7 -> V_8 , V_7 -> V_9 ) ] ) ;
V_7 -> V_9 -> V_41 ++ ;
}
F_13 ( & V_28 ) ;
V_46:
return V_17 ;
V_52:
F_13 ( & V_28 ) ;
V_47:
while ( ++ V_21 <= V_9 -> V_33 )
F_2 ( V_17 -> V_32 + V_21 ) ;
F_24 ( V_9 -> V_35 , V_17 ) ;
V_17 = NULL ;
goto V_46;
}
void F_44 ( struct V_1 * V_9 )
{
F_12 ( & V_28 ) ;
V_9 -> V_41 &= ~ V_51 ;
F_13 ( & V_28 ) ;
}
struct V_17 * F_45 ( int V_8 , struct V_1 * V_9 )
{
struct V_7 * V_54 ;
F_46 (pnr,
&pid_hash[pid_hashfn(nr, ns)], pid_chain)
if ( V_54 -> V_8 == V_8 && V_54 -> V_9 == V_9 )
return F_27 ( V_54 , struct V_17 ,
V_32 [ V_9 -> V_33 ] ) ;
return NULL ;
}
struct V_17 * F_47 ( int V_8 )
{
return F_45 ( V_8 , F_48 ( V_55 ) ) ;
}
void F_49 ( struct V_56 * V_57 , enum V_44 type ,
struct V_17 * V_17 )
{
struct V_58 * V_59 ;
V_59 = & V_57 -> V_60 [ type ] ;
V_59 -> V_17 = V_17 ;
F_42 ( & V_59 -> V_61 , & V_17 -> V_50 [ type ] ) ;
}
static void F_50 ( struct V_56 * V_57 , enum V_44 type ,
struct V_17 * V_62 )
{
struct V_58 * V_59 ;
struct V_17 * V_17 ;
int V_45 ;
V_59 = & V_57 -> V_60 [ type ] ;
V_17 = V_59 -> V_17 ;
F_30 ( & V_59 -> V_61 ) ;
V_59 -> V_17 = V_62 ;
for ( V_45 = V_49 ; -- V_45 >= 0 ; )
if ( ! F_51 ( & V_17 -> V_50 [ V_45 ] ) )
return;
F_28 ( V_17 ) ;
}
void F_52 ( struct V_56 * V_57 , enum V_44 type )
{
F_50 ( V_57 , type , NULL ) ;
}
void F_53 ( struct V_56 * V_57 , enum V_44 type ,
struct V_17 * V_17 )
{
F_50 ( V_57 , type , V_17 ) ;
F_49 ( V_57 , type , V_17 ) ;
}
void F_54 ( struct V_56 * V_63 , struct V_56 * V_62 ,
enum V_44 type )
{
V_62 -> V_60 [ type ] . V_17 = V_63 -> V_60 [ type ] . V_17 ;
F_55 ( & V_63 -> V_60 [ type ] . V_61 , & V_62 -> V_60 [ type ] . V_61 ) ;
}
struct V_56 * F_56 ( struct V_17 * V_17 , enum V_44 type )
{
struct V_56 * V_64 = NULL ;
if ( V_17 ) {
struct V_65 * V_66 ;
V_66 = F_57 ( F_58 ( & V_17 -> V_50 [ type ] ) ,
F_59 () ) ;
if ( V_66 )
V_64 = F_60 ( V_66 , struct V_56 , V_60 [ ( type ) ] . V_61 ) ;
}
return V_64 ;
}
struct V_56 * F_61 ( T_1 V_8 , struct V_1 * V_9 )
{
F_62 ( F_63 () ,
L_1
L_2 ) ;
return F_56 ( F_45 ( V_8 , V_9 ) , V_67 ) ;
}
struct V_56 * F_64 ( T_1 V_68 )
{
return F_61 ( V_68 , F_48 ( V_55 ) ) ;
}
struct V_17 * F_65 ( struct V_56 * V_57 , enum V_44 type )
{
struct V_17 * V_17 ;
F_66 () ;
if ( type != V_67 )
V_57 = V_57 -> V_69 ;
V_17 = F_67 ( V_57 -> V_60 [ type ] . V_17 ) ;
F_68 () ;
return V_17 ;
}
struct V_56 * F_69 ( struct V_17 * V_17 , enum V_44 type )
{
struct V_56 * V_64 ;
F_66 () ;
V_64 = F_56 ( V_17 , type ) ;
if ( V_64 )
F_70 ( V_64 ) ;
F_68 () ;
return V_64 ;
}
struct V_17 * F_71 ( T_1 V_8 )
{
struct V_17 * V_17 ;
F_66 () ;
V_17 = F_67 ( F_47 ( V_8 ) ) ;
F_68 () ;
return V_17 ;
}
T_1 F_72 ( struct V_17 * V_17 , struct V_1 * V_9 )
{
struct V_7 * V_7 ;
T_1 V_8 = 0 ;
if ( V_17 && V_9 -> V_33 <= V_17 -> V_33 ) {
V_7 = & V_17 -> V_32 [ V_9 -> V_33 ] ;
if ( V_7 -> V_9 == V_9 )
V_8 = V_7 -> V_8 ;
}
return V_8 ;
}
T_1 F_73 ( struct V_17 * V_17 )
{
return F_72 ( V_17 , F_48 ( V_55 ) ) ;
}
T_1 F_74 ( struct V_56 * V_57 , enum V_44 type ,
struct V_1 * V_9 )
{
T_1 V_8 = 0 ;
F_66 () ;
if ( ! V_9 )
V_9 = F_48 ( V_55 ) ;
if ( F_15 ( F_75 ( V_57 ) ) ) {
if ( type != V_67 )
V_57 = V_57 -> V_69 ;
V_8 = F_72 ( V_57 -> V_60 [ type ] . V_17 , V_9 ) ;
}
F_68 () ;
return V_8 ;
}
T_1 F_76 ( struct V_56 * V_70 , struct V_1 * V_9 )
{
return F_72 ( F_77 ( V_70 ) , V_9 ) ;
}
struct V_1 * F_48 ( struct V_56 * V_70 )
{
return F_78 ( F_79 ( V_70 ) ) ;
}
struct V_17 * F_80 ( int V_8 , struct V_1 * V_9 )
{
struct V_17 * V_17 ;
do {
V_17 = F_45 ( V_8 , V_9 ) ;
if ( V_17 )
break;
V_8 = F_20 ( V_9 , V_8 ) ;
} while ( V_8 > 0 );
return V_17 ;
}
void T_2 F_81 ( void )
{
unsigned int V_21 , V_71 ;
V_53 = F_82 ( L_3 , sizeof( * V_53 ) , 0 , 18 ,
V_72 | V_73 ,
& V_74 , NULL ,
0 , 4096 ) ;
V_71 = 1U << V_74 ;
for ( V_21 = 0 ; V_21 < V_71 ; V_21 ++ )
F_41 ( & V_53 [ V_21 ] ) ;
}
void T_2 F_83 ( void )
{
F_84 ( V_30 >= V_51 ) ;
V_24 = F_85 ( V_75 , F_86 ( int , V_24 ,
V_76 * F_87 () ) ) ;
V_77 = F_86 ( int , V_77 ,
V_78 * F_87 () ) ;
F_88 ( L_4 , V_24 , V_77 ) ;
V_79 . V_3 [ 0 ] . V_12 = F_11 ( V_26 , V_27 ) ;
F_89 ( 0 , V_79 . V_3 [ 0 ] . V_12 ) ;
F_18 ( & V_79 . V_3 [ 0 ] . V_13 ) ;
V_79 . V_41 = V_51 ;
V_79 . V_35 = F_90 ( V_17 ,
V_80 | V_81 ) ;
}
