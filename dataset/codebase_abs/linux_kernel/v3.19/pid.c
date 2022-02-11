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
case 2 :
case 1 :
F_31 ( V_9 -> V_42 ) ;
break;
case V_43 :
F_32 ( V_9 -> V_42 ) ;
V_9 -> V_41 = 0 ;
case 0 :
F_33 ( & V_9 -> V_44 ) ;
break;
}
}
F_34 ( & V_28 , V_39 ) ;
for ( V_21 = 0 ; V_21 <= V_17 -> V_33 ; V_21 ++ )
F_2 ( V_17 -> V_32 + V_21 ) ;
F_35 ( & V_17 -> V_38 , F_26 ) ;
}
struct V_17 * F_36 ( struct V_1 * V_9 )
{
struct V_17 * V_17 ;
enum V_45 type ;
int V_21 , V_8 ;
struct V_1 * V_46 ;
struct V_7 * V_7 ;
V_17 = F_37 ( V_9 -> V_35 , V_27 ) ;
if ( ! V_17 )
goto V_47;
V_46 = V_9 ;
V_17 -> V_33 = V_9 -> V_33 ;
for ( V_21 = V_9 -> V_33 ; V_21 >= 0 ; V_21 -- ) {
V_8 = F_8 ( V_46 ) ;
if ( V_8 < 0 )
goto V_48;
V_17 -> V_32 [ V_21 ] . V_8 = V_8 ;
V_17 -> V_32 [ V_21 ] . V_9 = V_46 ;
V_46 = V_46 -> V_49 ;
}
if ( F_10 ( F_38 ( V_17 ) ) ) {
if ( F_39 ( V_9 ) )
goto V_48;
}
F_40 ( V_9 ) ;
F_41 ( & V_17 -> V_34 , 1 ) ;
for ( type = 0 ; type < V_50 ; ++ type )
F_42 ( & V_17 -> V_51 [ type ] ) ;
V_7 = V_17 -> V_32 + V_9 -> V_33 ;
F_12 ( & V_28 ) ;
if ( ! ( V_9 -> V_41 & V_43 ) )
goto V_52;
for ( ; V_7 >= V_17 -> V_32 ; -- V_7 ) {
F_43 ( & V_7 -> V_40 ,
& V_53 [ F_44 ( V_7 -> V_8 , V_7 -> V_9 ) ] ) ;
V_7 -> V_9 -> V_41 ++ ;
}
F_13 ( & V_28 ) ;
V_47:
return V_17 ;
V_52:
F_13 ( & V_28 ) ;
F_25 ( V_9 ) ;
V_48:
while ( ++ V_21 <= V_9 -> V_33 )
F_2 ( V_17 -> V_32 + V_21 ) ;
F_24 ( V_9 -> V_35 , V_17 ) ;
V_17 = NULL ;
goto V_47;
}
void F_45 ( struct V_1 * V_9 )
{
F_12 ( & V_28 ) ;
V_9 -> V_41 &= ~ V_43 ;
F_13 ( & V_28 ) ;
}
struct V_17 * F_46 ( int V_8 , struct V_1 * V_9 )
{
struct V_7 * V_54 ;
F_47 (pnr,
&pid_hash[pid_hashfn(nr, ns)], pid_chain)
if ( V_54 -> V_8 == V_8 && V_54 -> V_9 == V_9 )
return F_27 ( V_54 , struct V_17 ,
V_32 [ V_9 -> V_33 ] ) ;
return NULL ;
}
struct V_17 * F_48 ( int V_8 )
{
return F_46 ( V_8 , F_49 ( V_55 ) ) ;
}
void F_50 ( struct V_56 * V_57 , enum V_45 type )
{
struct V_58 * V_59 = & V_57 -> V_60 [ type ] ;
F_43 ( & V_59 -> V_61 , & V_59 -> V_17 -> V_51 [ type ] ) ;
}
static void F_51 ( struct V_56 * V_57 , enum V_45 type ,
struct V_17 * V_62 )
{
struct V_58 * V_59 ;
struct V_17 * V_17 ;
int V_46 ;
V_59 = & V_57 -> V_60 [ type ] ;
V_17 = V_59 -> V_17 ;
F_30 ( & V_59 -> V_61 ) ;
V_59 -> V_17 = V_62 ;
for ( V_46 = V_50 ; -- V_46 >= 0 ; )
if ( ! F_52 ( & V_17 -> V_51 [ V_46 ] ) )
return;
F_28 ( V_17 ) ;
}
void F_53 ( struct V_56 * V_57 , enum V_45 type )
{
F_51 ( V_57 , type , NULL ) ;
}
void F_54 ( struct V_56 * V_57 , enum V_45 type ,
struct V_17 * V_17 )
{
F_51 ( V_57 , type , V_17 ) ;
F_50 ( V_57 , type ) ;
}
void F_55 ( struct V_56 * V_63 , struct V_56 * V_62 ,
enum V_45 type )
{
V_62 -> V_60 [ type ] . V_17 = V_63 -> V_60 [ type ] . V_17 ;
F_56 ( & V_63 -> V_60 [ type ] . V_61 , & V_62 -> V_60 [ type ] . V_61 ) ;
}
struct V_56 * F_57 ( struct V_17 * V_17 , enum V_45 type )
{
struct V_56 * V_64 = NULL ;
if ( V_17 ) {
struct V_65 * V_66 ;
V_66 = F_58 ( F_59 ( & V_17 -> V_51 [ type ] ) ,
F_60 () ) ;
if ( V_66 )
V_64 = F_61 ( V_66 , struct V_56 , V_60 [ ( type ) ] . V_61 ) ;
}
return V_64 ;
}
struct V_56 * F_62 ( T_1 V_8 , struct V_1 * V_9 )
{
F_63 ( F_64 () ,
L_1
L_2 ) ;
return F_57 ( F_46 ( V_8 , V_9 ) , V_67 ) ;
}
struct V_56 * F_65 ( T_1 V_68 )
{
return F_62 ( V_68 , F_49 ( V_55 ) ) ;
}
struct V_17 * F_66 ( struct V_56 * V_57 , enum V_45 type )
{
struct V_17 * V_17 ;
F_67 () ;
if ( type != V_67 )
V_57 = V_57 -> V_69 ;
V_17 = F_68 ( V_57 -> V_60 [ type ] . V_17 ) ;
F_69 () ;
return V_17 ;
}
struct V_56 * F_70 ( struct V_17 * V_17 , enum V_45 type )
{
struct V_56 * V_64 ;
F_67 () ;
V_64 = F_57 ( V_17 , type ) ;
if ( V_64 )
F_71 ( V_64 ) ;
F_69 () ;
return V_64 ;
}
struct V_17 * F_72 ( T_1 V_8 )
{
struct V_17 * V_17 ;
F_67 () ;
V_17 = F_68 ( F_48 ( V_8 ) ) ;
F_69 () ;
return V_17 ;
}
T_1 F_73 ( struct V_17 * V_17 , struct V_1 * V_9 )
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
T_1 F_74 ( struct V_17 * V_17 )
{
return F_73 ( V_17 , F_49 ( V_55 ) ) ;
}
T_1 F_75 ( struct V_56 * V_57 , enum V_45 type ,
struct V_1 * V_9 )
{
T_1 V_8 = 0 ;
F_67 () ;
if ( ! V_9 )
V_9 = F_49 ( V_55 ) ;
if ( F_15 ( F_76 ( V_57 ) ) ) {
if ( type != V_67 )
V_57 = V_57 -> V_69 ;
V_8 = F_73 ( V_57 -> V_60 [ type ] . V_17 , V_9 ) ;
}
F_69 () ;
return V_8 ;
}
T_1 F_77 ( struct V_56 * V_70 , struct V_1 * V_9 )
{
return F_73 ( F_78 ( V_70 ) , V_9 ) ;
}
struct V_1 * F_49 ( struct V_56 * V_70 )
{
return F_79 ( F_80 ( V_70 ) ) ;
}
struct V_17 * F_81 ( int V_8 , struct V_1 * V_9 )
{
struct V_17 * V_17 ;
do {
V_17 = F_46 ( V_8 , V_9 ) ;
if ( V_17 )
break;
V_8 = F_20 ( V_9 , V_8 ) ;
} while ( V_8 > 0 );
return V_17 ;
}
void T_2 F_82 ( void )
{
unsigned int V_21 , V_71 ;
V_53 = F_83 ( L_3 , sizeof( * V_53 ) , 0 , 18 ,
V_72 | V_73 ,
& V_74 , NULL ,
0 , 4096 ) ;
V_71 = 1U << V_74 ;
for ( V_21 = 0 ; V_21 < V_71 ; V_21 ++ )
F_42 ( & V_53 [ V_21 ] ) ;
}
void T_2 F_84 ( void )
{
F_85 ( V_30 >= V_43 ) ;
V_24 = F_86 ( V_75 , F_87 ( int , V_24 ,
V_76 * F_88 () ) ) ;
V_77 = F_87 ( int , V_77 ,
V_78 * F_88 () ) ;
F_89 ( L_4 , V_24 , V_77 ) ;
V_79 . V_3 [ 0 ] . V_12 = F_11 ( V_26 , V_27 ) ;
F_90 ( 0 , V_79 . V_3 [ 0 ] . V_12 ) ;
F_18 ( & V_79 . V_3 [ 0 ] . V_13 ) ;
V_79 . V_35 = F_91 ( V_17 ,
V_80 | V_81 ) ;
}
