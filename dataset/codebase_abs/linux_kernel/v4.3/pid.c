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
return - V_29 ;
}
if ( F_15 ( F_16 ( & V_4 -> V_13 ) ) ) {
for ( ; ; ) {
if ( ! F_17 ( V_10 , V_4 -> V_12 ) ) {
F_18 ( & V_4 -> V_13 ) ;
F_6 ( V_2 , V_23 , V_17 ) ;
return V_17 ;
}
V_10 = F_19 ( V_4 , V_10 ) ;
if ( V_10 >= V_6 )
break;
V_17 = F_1 ( V_2 , V_4 , V_10 ) ;
if ( V_17 >= V_24 )
break;
}
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
return - V_30 ;
}
int F_20 ( struct V_1 * V_2 , unsigned int V_23 )
{
int V_10 ;
struct V_3 * V_4 , * V_31 ;
if ( V_23 >= V_32 )
return - 1 ;
V_10 = ( V_23 + 1 ) & V_11 ;
V_4 = & V_2 -> V_3 [ ( V_23 + 1 ) / V_6 ] ;
V_31 = & V_2 -> V_3 [ V_33 ] ;
for (; V_4 < V_31 ; V_4 ++ , V_10 = 0 ) {
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
V_9 = V_17 -> V_34 [ V_17 -> V_35 ] . V_9 ;
if ( ( F_16 ( & V_17 -> V_36 ) == 1 ) ||
F_23 ( & V_17 -> V_36 ) ) {
F_24 ( V_9 -> V_37 , V_17 ) ;
F_25 ( V_9 ) ;
}
}
static void F_26 ( struct V_38 * V_39 )
{
struct V_17 * V_17 = F_27 ( V_39 , struct V_17 , V_40 ) ;
F_22 ( V_17 ) ;
}
void F_28 ( struct V_17 * V_17 )
{
int V_21 ;
unsigned long V_41 ;
F_29 ( & V_28 , V_41 ) ;
for ( V_21 = 0 ; V_21 <= V_17 -> V_35 ; V_21 ++ ) {
struct V_7 * V_7 = V_17 -> V_34 + V_21 ;
struct V_1 * V_9 = V_7 -> V_9 ;
F_30 ( & V_7 -> V_42 ) ;
switch( -- V_9 -> V_43 ) {
case 2 :
case 1 :
F_31 ( V_9 -> V_44 ) ;
break;
case V_45 :
F_32 ( V_9 -> V_44 ) ;
V_9 -> V_43 = 0 ;
case 0 :
F_33 ( & V_9 -> V_46 ) ;
break;
}
}
F_34 ( & V_28 , V_41 ) ;
for ( V_21 = 0 ; V_21 <= V_17 -> V_35 ; V_21 ++ )
F_2 ( V_17 -> V_34 + V_21 ) ;
F_35 ( & V_17 -> V_40 , F_26 ) ;
}
struct V_17 * F_36 ( struct V_1 * V_9 )
{
struct V_17 * V_17 ;
enum V_47 type ;
int V_21 , V_8 ;
struct V_1 * V_48 ;
struct V_7 * V_7 ;
int V_49 = - V_29 ;
V_17 = F_37 ( V_9 -> V_37 , V_27 ) ;
if ( ! V_17 )
return F_38 ( V_49 ) ;
V_48 = V_9 ;
V_17 -> V_35 = V_9 -> V_35 ;
for ( V_21 = V_9 -> V_35 ; V_21 >= 0 ; V_21 -- ) {
V_8 = F_8 ( V_48 ) ;
if ( F_39 ( V_8 ) ) {
V_49 = V_8 ;
goto V_50;
}
V_17 -> V_34 [ V_21 ] . V_8 = V_8 ;
V_17 -> V_34 [ V_21 ] . V_9 = V_48 ;
V_48 = V_48 -> V_51 ;
}
if ( F_10 ( F_40 ( V_17 ) ) ) {
if ( F_41 ( V_9 ) )
goto V_50;
}
F_42 ( V_9 ) ;
F_43 ( & V_17 -> V_36 , 1 ) ;
for ( type = 0 ; type < V_52 ; ++ type )
F_44 ( & V_17 -> V_53 [ type ] ) ;
V_7 = V_17 -> V_34 + V_9 -> V_35 ;
F_12 ( & V_28 ) ;
if ( ! ( V_9 -> V_43 & V_45 ) )
goto V_54;
for ( ; V_7 >= V_17 -> V_34 ; -- V_7 ) {
F_45 ( & V_7 -> V_42 ,
& V_55 [ F_46 ( V_7 -> V_8 , V_7 -> V_9 ) ] ) ;
V_7 -> V_9 -> V_43 ++ ;
}
F_13 ( & V_28 ) ;
return V_17 ;
V_54:
F_13 ( & V_28 ) ;
F_25 ( V_9 ) ;
V_50:
while ( ++ V_21 <= V_9 -> V_35 )
F_2 ( V_17 -> V_34 + V_21 ) ;
F_24 ( V_9 -> V_37 , V_17 ) ;
return F_38 ( V_49 ) ;
}
void F_47 ( struct V_1 * V_9 )
{
F_12 ( & V_28 ) ;
V_9 -> V_43 &= ~ V_45 ;
F_13 ( & V_28 ) ;
}
struct V_17 * F_48 ( int V_8 , struct V_1 * V_9 )
{
struct V_7 * V_56 ;
F_49 (pnr,
&pid_hash[pid_hashfn(nr, ns)], pid_chain)
if ( V_56 -> V_8 == V_8 && V_56 -> V_9 == V_9 )
return F_27 ( V_56 , struct V_17 ,
V_34 [ V_9 -> V_35 ] ) ;
return NULL ;
}
struct V_17 * F_50 ( int V_8 )
{
return F_48 ( V_8 , F_51 ( V_57 ) ) ;
}
void F_52 ( struct V_58 * V_59 , enum V_47 type )
{
struct V_60 * V_61 = & V_59 -> V_62 [ type ] ;
F_45 ( & V_61 -> V_63 , & V_61 -> V_17 -> V_53 [ type ] ) ;
}
static void F_53 ( struct V_58 * V_59 , enum V_47 type ,
struct V_17 * V_64 )
{
struct V_60 * V_61 ;
struct V_17 * V_17 ;
int V_48 ;
V_61 = & V_59 -> V_62 [ type ] ;
V_17 = V_61 -> V_17 ;
F_30 ( & V_61 -> V_63 ) ;
V_61 -> V_17 = V_64 ;
for ( V_48 = V_52 ; -- V_48 >= 0 ; )
if ( ! F_54 ( & V_17 -> V_53 [ V_48 ] ) )
return;
F_28 ( V_17 ) ;
}
void F_55 ( struct V_58 * V_59 , enum V_47 type )
{
F_53 ( V_59 , type , NULL ) ;
}
void F_56 ( struct V_58 * V_59 , enum V_47 type ,
struct V_17 * V_17 )
{
F_53 ( V_59 , type , V_17 ) ;
F_52 ( V_59 , type ) ;
}
void F_57 ( struct V_58 * V_65 , struct V_58 * V_64 ,
enum V_47 type )
{
V_64 -> V_62 [ type ] . V_17 = V_65 -> V_62 [ type ] . V_17 ;
F_58 ( & V_65 -> V_62 [ type ] . V_63 , & V_64 -> V_62 [ type ] . V_63 ) ;
}
struct V_58 * F_59 ( struct V_17 * V_17 , enum V_47 type )
{
struct V_58 * V_66 = NULL ;
if ( V_17 ) {
struct V_67 * V_68 ;
V_68 = F_60 ( F_61 ( & V_17 -> V_53 [ type ] ) ,
F_62 () ) ;
if ( V_68 )
V_66 = F_63 ( V_68 , struct V_58 , V_62 [ ( type ) ] . V_63 ) ;
}
return V_66 ;
}
struct V_58 * F_64 ( T_1 V_8 , struct V_1 * V_9 )
{
F_65 ( ! F_66 () ,
L_1 ) ;
return F_59 ( F_48 ( V_8 , V_9 ) , V_69 ) ;
}
struct V_58 * F_67 ( T_1 V_70 )
{
return F_64 ( V_70 , F_51 ( V_57 ) ) ;
}
struct V_17 * F_68 ( struct V_58 * V_59 , enum V_47 type )
{
struct V_17 * V_17 ;
F_69 () ;
if ( type != V_69 )
V_59 = V_59 -> V_71 ;
V_17 = F_70 ( V_59 -> V_62 [ type ] . V_17 ) ;
F_71 () ;
return V_17 ;
}
struct V_58 * F_72 ( struct V_17 * V_17 , enum V_47 type )
{
struct V_58 * V_66 ;
F_69 () ;
V_66 = F_59 ( V_17 , type ) ;
if ( V_66 )
F_73 ( V_66 ) ;
F_71 () ;
return V_66 ;
}
struct V_17 * F_74 ( T_1 V_8 )
{
struct V_17 * V_17 ;
F_69 () ;
V_17 = F_70 ( F_50 ( V_8 ) ) ;
F_71 () ;
return V_17 ;
}
T_1 F_75 ( struct V_17 * V_17 , struct V_1 * V_9 )
{
struct V_7 * V_7 ;
T_1 V_8 = 0 ;
if ( V_17 && V_9 -> V_35 <= V_17 -> V_35 ) {
V_7 = & V_17 -> V_34 [ V_9 -> V_35 ] ;
if ( V_7 -> V_9 == V_9 )
V_8 = V_7 -> V_8 ;
}
return V_8 ;
}
T_1 F_76 ( struct V_17 * V_17 )
{
return F_75 ( V_17 , F_51 ( V_57 ) ) ;
}
T_1 F_77 ( struct V_58 * V_59 , enum V_47 type ,
struct V_1 * V_9 )
{
T_1 V_8 = 0 ;
F_69 () ;
if ( ! V_9 )
V_9 = F_51 ( V_57 ) ;
if ( F_15 ( F_78 ( V_59 ) ) ) {
if ( type != V_69 )
V_59 = V_59 -> V_71 ;
V_8 = F_75 ( V_59 -> V_62 [ type ] . V_17 , V_9 ) ;
}
F_71 () ;
return V_8 ;
}
T_1 F_79 ( struct V_58 * V_72 , struct V_1 * V_9 )
{
return F_75 ( F_80 ( V_72 ) , V_9 ) ;
}
struct V_1 * F_51 ( struct V_58 * V_72 )
{
return F_81 ( F_82 ( V_72 ) ) ;
}
struct V_17 * F_83 ( int V_8 , struct V_1 * V_9 )
{
struct V_17 * V_17 ;
do {
V_17 = F_48 ( V_8 , V_9 ) ;
if ( V_17 )
break;
V_8 = F_20 ( V_9 , V_8 ) ;
} while ( V_8 > 0 );
return V_17 ;
}
void T_2 F_84 ( void )
{
unsigned int V_21 , V_73 ;
V_55 = F_85 ( L_2 , sizeof( * V_55 ) , 0 , 18 ,
V_74 | V_75 ,
& V_76 , NULL ,
0 , 4096 ) ;
V_73 = 1U << V_76 ;
for ( V_21 = 0 ; V_21 < V_73 ; V_21 ++ )
F_44 ( & V_55 [ V_21 ] ) ;
}
void T_2 F_86 ( void )
{
F_87 ( V_32 >= V_45 ) ;
V_24 = F_88 ( V_77 , F_89 ( int , V_24 ,
V_78 * F_90 () ) ) ;
V_79 = F_89 ( int , V_79 ,
V_80 * F_90 () ) ;
F_91 ( L_3 , V_24 , V_79 ) ;
V_81 . V_3 [ 0 ] . V_12 = F_11 ( V_26 , V_27 ) ;
F_92 ( 0 , V_81 . V_3 [ 0 ] . V_12 ) ;
F_18 ( & V_81 . V_3 [ 0 ] . V_13 ) ;
V_81 . V_37 = F_93 ( V_17 ,
V_82 | V_83 ) ;
}
