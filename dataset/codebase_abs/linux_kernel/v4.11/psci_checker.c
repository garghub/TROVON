static int F_1 ( void )
{
int V_1 = - 1 ;
int V_2 ;
if ( ! ( V_3 . V_4 && V_3 . V_5 && V_3 . V_6 ) ) {
F_2 ( L_1 ) ;
return - V_7 ;
}
if ( V_3 . V_8 )
V_1 = V_3 . V_8 () ;
if ( V_1 == V_9 ||
V_1 == V_10 ) {
F_3 (cpu)
if ( F_4 ( V_2 ) ) {
V_11 = V_2 ;
break;
}
if ( V_11 == - 1 )
F_2 ( L_2 ) ;
}
return 0 ;
}
static int F_5 ( const struct V_12 * V_13 ,
const struct V_12 * * V_14 )
{
unsigned int V_15 = 0 ;
T_1 V_16 ;
if ( ! F_6 ( & V_16 , V_17 ) )
return - V_18 ;
F_7 ( V_16 , V_13 ) ;
while ( ! F_8 ( V_16 ) ) {
const struct V_12 * V_19 =
F_9 ( F_10 ( V_16 ) ) ;
V_14 [ V_15 ++ ] = V_19 ;
F_11 ( V_16 , V_16 , V_19 ) ;
}
F_12 ( V_16 ) ;
return V_15 ;
}
static unsigned int F_13 ( const struct V_12 * V_13 ,
struct V_12 * V_20 )
{
int V_2 ;
int V_21 = 0 ;
F_14 ( V_20 ) ;
F_15 (cpu, cpus) {
int V_22 = F_16 ( V_2 ) ;
if ( F_17 ( V_20 ) + 1 == V_23 ) {
if ( V_22 != - V_24 ) {
F_18 ( L_3
L_4 ,
V_22 , V_2 ) ;
++ V_21 ;
}
} else if ( V_2 == V_11 ) {
if ( V_22 != - V_25 ) {
F_18 ( L_3
L_5 ,
V_22 , V_2 ) ;
++ V_21 ;
}
} else if ( V_22 != 0 ) {
F_18 ( L_6
L_7 , V_22 , V_2 ) ;
++ V_21 ;
}
if ( V_22 == 0 )
F_19 ( V_2 , V_20 ) ;
}
F_15 (cpu, offlined_cpus) {
int V_22 = F_20 ( V_2 ) ;
if ( V_22 != 0 ) {
F_18 ( L_6
L_8 , V_22 , V_2 ) ;
++ V_21 ;
} else {
F_21 ( V_2 , V_20 ) ;
}
}
F_22 ( ! F_8 ( V_20 ) ||
F_23 () != V_23 ) ;
return V_21 ;
}
static int F_24 ( void )
{
int V_21 ;
T_1 V_20 ;
int V_26 , V_27 ;
const struct V_12 * * V_14 ;
char * V_28 ;
V_21 = - V_18 ;
if ( ! F_6 ( & V_20 , V_17 ) )
return V_21 ;
V_14 = F_25 ( V_23 , sizeof( * V_14 ) ,
V_17 ) ;
if ( ! V_14 )
goto V_29;
V_28 = ( char * ) F_26 ( V_17 ) ;
if ( ! V_28 )
goto V_30;
V_21 = 0 ;
V_27 = F_5 ( V_31 , V_14 ) ;
F_27 ( L_9 ) ;
V_21 += F_13 ( V_31 , V_20 ) ;
for ( V_26 = 0 ; V_26 < V_27 ; ++ V_26 ) {
int V_32 =
F_28 ( F_10 ( V_14 [ V_26 ] ) ) ;
T_2 V_33 = F_29 ( true , V_28 ,
V_14 [ V_26 ] ) ;
V_28 [ V_33 - 1 ] = '\0' ;
F_27 ( L_10
L_11 , V_32 , V_28 ) ;
V_21 += F_13 ( V_14 [ V_26 ] , V_20 ) ;
}
F_30 ( ( unsigned long ) V_28 ) ;
V_30:
F_31 ( V_14 ) ;
V_29:
F_12 ( V_20 ) ;
return V_21 ;
}
static void F_32 ( unsigned long V_34 ) {}
static int F_33 ( int V_35 , bool V_36 )
{
int V_22 ;
F_34 () ;
if ( V_36 ) {
V_22 = F_35 () ;
if ( V_22 ) {
F_36 () ;
V_22 = 0 ;
goto V_37;
}
}
V_22 = F_37 ( V_38 , V_35 ) ;
if ( V_36 )
F_38 () ;
V_37:
F_39 () ;
return V_22 ;
}
static int F_40 ( void * V_39 )
{
int V_2 = ( long ) V_39 ;
int V_26 , V_40 = 0 , V_41 = 0 , V_42 = 0 ;
struct V_43 V_44 = { . V_44 = V_45 - 1 } ;
struct V_46 * V_47 ;
struct V_48 * V_49 ;
struct V_50 V_51 ;
F_41 ( & V_52 ) ;
if ( F_42 ( V_53 , V_54 , & V_44 ) )
F_2 ( L_12 ,
V_2 ) ;
V_47 = F_43 ( V_55 ) ;
V_49 = F_44 ( V_47 ) ;
F_27 ( L_13 ,
V_2 , V_49 -> V_56 - 1 ) ;
F_45 ( & V_51 , F_32 , 0 ) ;
for ( V_26 = 0 ; V_26 < V_57 ; ++ V_26 ) {
int V_35 ;
for ( V_35 = 1 ; V_35 < V_49 -> V_56 ; ++ V_35 ) {
struct V_58 * V_59 = & V_49 -> V_60 [ V_35 ] ;
bool V_36 = V_59 -> V_61 & V_62 ;
int V_22 ;
F_46 ( & V_51 , V_63 +
F_47 ( V_59 -> V_64 ) ) ;
F_48 () ;
V_22 = F_33 ( V_35 , V_36 ) ;
F_49 () ;
if ( V_22 == V_35 ) {
++ V_40 ;
} else if ( V_22 >= 0 ) {
++ V_41 ;
} else {
F_18 ( L_14
L_15 ,
V_2 , V_22 , V_35 , V_26 ) ;
++ V_42 ;
}
}
}
F_50 ( & V_51 ) ;
if ( F_51 ( & V_65 ) == 0 )
F_52 ( & V_66 ) ;
V_44 . V_44 = 0 ;
if ( F_42 ( V_53 , V_67 , & V_44 ) )
F_2 ( L_12 ,
V_2 ) ;
for (; ; ) {
F_53 ( V_68 ) ;
if ( F_54 () ) {
F_55 ( V_69 ) ;
break;
}
F_56 () ;
}
F_27 ( L_16 ,
V_2 , V_40 , V_41 , V_42 ) ;
return V_42 ;
}
static int F_57 ( void )
{
int V_26 , V_2 , V_21 = 0 ;
struct V_70 * * V_71 ;
int V_72 = 0 ;
V_71 = F_25 ( V_23 , sizeof( * V_71 ) ,
V_17 ) ;
if ( ! V_71 )
return - V_18 ;
F_58 () ;
F_3 (cpu) {
struct V_70 * V_73 ;
struct V_46 * V_47 = F_59 ( V_55 , V_2 ) ;
struct V_48 * V_49 = F_44 ( V_47 ) ;
if ( ! V_47 || ! V_49 ) {
F_2 ( L_17 ,
V_2 ) ;
continue;
}
V_73 = F_60 ( F_40 ,
( void * ) ( long ) V_2 , V_2 ,
L_18 ) ;
if ( F_61 ( V_73 ) )
F_18 ( L_19 , V_2 ) ;
else
V_71 [ V_72 ++ ] = V_73 ;
}
if ( V_72 < 1 ) {
V_21 = - V_74 ;
goto V_75;
}
F_62 ( & V_65 , V_72 ) ;
for ( V_26 = 0 ; V_26 < V_72 ; ++ V_26 )
F_63 ( V_71 [ V_26 ] ) ;
F_64 ( & V_52 ) ;
F_41 ( & V_66 ) ;
for ( V_26 = 0 ; V_26 < V_72 ; ++ V_26 )
V_21 += F_65 ( V_71 [ V_26 ] ) ;
V_75:
F_66 () ;
F_31 ( V_71 ) ;
return V_21 ;
}
static int T_3 F_67 ( void )
{
int V_22 ;
V_23 = F_23 () ;
V_22 = F_1 () ;
if ( V_22 )
return V_22 ;
F_27 ( L_20 , V_23 ) ;
F_27 ( L_21 ) ;
V_22 = F_24 () ;
if ( V_22 == 0 )
F_27 ( L_22 ) ;
else if ( V_22 > 0 )
F_18 ( L_23 , V_22 ) ;
else {
F_18 ( L_24 ) ;
return V_22 ;
}
F_27 ( L_25 ,
V_57 ) ;
V_22 = F_57 () ;
if ( V_22 == 0 )
F_27 ( L_26 ) ;
else if ( V_22 > 0 )
F_18 ( L_27 , V_22 ) ;
else {
switch ( V_22 ) {
case - V_18 :
F_18 ( L_24 ) ;
break;
case - V_74 :
F_2 ( L_28 ) ;
break;
}
}
F_27 ( L_29 ) ;
return V_22 < 0 ? V_22 : 0 ;
}
