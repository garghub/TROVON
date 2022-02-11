int F_1 ( int V_1 )
{
if ( V_2 [ V_1 ] == V_3 )
return 1 ;
return - 1 ;
}
static inline int F_2 ( void )
{
int V_1 ;
for ( V_1 = V_4 ; V_1 < V_5 ; V_1 ++ )
if ( V_2 [ V_1 ] == V_6 )
return V_1 ;
return - V_7 ;
}
static inline int F_3 ( T_1 V_8 )
{
T_1 V_9 ;
int V_10 , V_11 ;
F_4 ( V_9 , V_8 , V_12 ) ;
if ( F_5 ( V_9 ) )
return - V_13 ;
for ( V_10 = 0 ; V_10 < V_14 ; V_10 ++ ) {
V_11 = V_4 + V_10 ;
F_4 ( V_9 , V_8 , V_15 [ V_11 ] ) ;
if ( ! F_5 ( V_9 ) )
continue;
return V_11 ;
}
return - V_7 ;
}
static int F_6 ( int V_1 , int V_11 , T_1 V_8 )
{
T_1 V_9 ;
int V_16 ;
struct V_17 * V_18 = & V_17 [ V_1 ] ;
F_7 ( ( unsigned ) V_1 >= V_5 ) ;
F_7 ( ( unsigned ) V_11 >= V_19 ) ;
F_4 ( V_9 , V_8 , V_12 ) ;
if ( F_5 ( V_9 ) )
return - V_13 ;
if ( ( V_18 -> V_11 == V_11 ) && F_8 ( V_18 -> V_8 , V_8 ) )
return 0 ;
if ( V_18 -> V_11 != V_20 )
return - V_21 ;
F_9 (cpu, mask)
F_10 ( V_22 , V_16 ) [ V_11 ] = V_1 ;
V_18 -> V_11 = V_11 ;
V_18 -> V_8 = V_8 ;
V_2 [ V_1 ] = V_3 ;
F_11 ( V_15 [ V_11 ] , V_15 [ V_11 ] , V_8 ) ;
return 0 ;
}
int F_12 ( int V_1 , int V_11 , T_1 V_8 )
{
unsigned long V_23 ;
int V_24 ;
F_13 ( & V_25 , V_23 ) ;
V_24 = F_6 ( V_1 , V_11 , V_8 ) ;
F_14 ( & V_25 , V_23 ) ;
return V_24 ;
}
static void F_15 ( int V_1 )
{
int V_11 , V_16 ;
T_1 V_9 ;
T_1 V_8 ;
struct V_17 * V_18 = & V_17 [ V_1 ] ;
F_7 ( ( unsigned ) V_1 >= V_5 ) ;
F_7 ( V_18 -> V_11 == V_20 ) ;
V_11 = V_18 -> V_11 ;
V_8 = V_18 -> V_8 ;
F_4 ( V_9 , V_18 -> V_8 , V_12 ) ;
F_9 (cpu, mask)
F_10 ( V_22 , V_16 ) [ V_11 ] = - 1 ;
V_18 -> V_11 = V_20 ;
V_18 -> V_8 = V_26 ;
V_2 [ V_1 ] = V_6 ;
F_16 ( V_15 [ V_11 ] , V_15 [ V_11 ] , V_8 ) ;
}
static void F_17 ( int V_1 )
{
unsigned long V_23 ;
F_13 ( & V_25 , V_23 ) ;
F_15 ( V_1 ) ;
F_14 ( & V_25 , V_23 ) ;
}
int
F_18 ( int V_1 )
{
unsigned long V_23 ;
int V_11 , V_16 ;
T_1 V_8 = V_26 ;
V_11 = - V_7 ;
F_13 ( & V_25 , V_23 ) ;
F_19 (cpu) {
V_8 = F_20 ( V_16 ) ;
V_11 = F_3 ( V_8 ) ;
if ( V_11 >= 0 )
break;
}
if ( V_11 < 0 )
goto V_27;
if ( V_1 == V_28 )
V_1 = V_11 ;
F_7 ( F_6 ( V_1 , V_11 , V_8 ) ) ;
V_27:
F_14 ( & V_25 , V_23 ) ;
return V_11 ;
}
void
F_21 ( int V_11 )
{
if ( V_11 < V_4 ||
V_11 > V_29 )
return;
F_17 ( V_11 ) ;
}
int
F_22 ( int V_11 )
{
if ( V_11 < V_4 ||
V_11 > V_29 )
return - V_13 ;
return ! ! F_12 ( V_11 , V_11 , V_30 ) ;
}
void F_23 ( int V_16 )
{
int V_1 , V_11 ;
for ( V_11 = 0 ; V_11 < V_19 ; ++ V_11 )
F_10 ( V_22 , V_16 ) [ V_11 ] = - 1 ;
for ( V_1 = 0 ; V_1 < V_5 ; ++ V_1 ) {
if ( ! F_24 ( V_16 , V_17 [ V_1 ] . V_8 ) )
continue;
V_11 = F_25 ( V_1 ) ;
F_10 ( V_22 , V_16 ) [ V_11 ] = V_1 ;
}
}
static T_1 F_20 ( int V_16 )
{
if ( V_31 == V_32 )
return F_26 ( V_16 ) ;
return V_30 ;
}
static int F_27 ( int V_1 , int V_16 )
{
struct V_17 * V_18 = & V_17 [ V_1 ] ;
int V_11 ;
T_1 V_8 ;
if ( V_18 -> V_33 || V_18 -> V_34 )
return - V_21 ;
if ( V_18 -> V_11 == V_20 || ! F_28 ( V_16 ) )
return - V_13 ;
if ( F_24 ( V_16 , V_18 -> V_8 ) )
return 0 ;
V_8 = F_20 ( V_16 ) ;
V_11 = F_3 ( V_8 ) ;
if ( V_11 < 0 )
return - V_7 ;
V_18 -> V_33 = 1 ;
V_18 -> V_35 = V_18 -> V_8 ;
V_18 -> V_11 = V_20 ;
V_18 -> V_8 = V_26 ;
F_7 ( F_6 ( V_1 , V_11 , V_8 ) ) ;
return 0 ;
}
int F_29 ( int V_1 , int V_16 )
{
unsigned long V_23 ;
int V_24 ;
F_13 ( & V_25 , V_23 ) ;
V_24 = F_27 ( V_1 , V_16 ) ;
F_14 ( & V_25 , V_23 ) ;
return V_24 ;
}
void F_30 ( unsigned V_1 )
{
struct V_17 * V_18 = & V_17 [ V_1 ] ;
T_1 V_36 ;
int V_37 ;
if ( F_31 ( ! V_18 -> V_33 ) )
return;
if ( F_32 ( F_24 ( F_33 () , V_18 -> V_35 ) ) )
return;
F_4 ( V_36 , V_18 -> V_35 , V_12 ) ;
V_18 -> V_34 = F_34 ( V_36 ) ;
F_9 (i, cleanup_mask)
F_35 ( V_37 , V_38 , V_39 , 0 ) ;
V_18 -> V_33 = 0 ;
}
static T_2 F_36 ( int V_1 , void * V_40 )
{
int V_41 = F_33 () ;
T_3 V_11 ;
unsigned long V_23 ;
for ( V_11 = V_4 ;
V_11 < V_29 ; V_11 ++ ) {
int V_1 ;
struct V_42 * V_43 ;
struct V_17 * V_18 ;
V_1 = F_37 ( V_22 ) [ V_11 ] ;
if ( V_1 < 0 )
continue;
V_43 = F_38 ( V_1 ) ;
V_18 = V_17 + V_1 ;
F_39 ( & V_43 -> V_44 ) ;
if ( ! V_18 -> V_34 )
goto V_45;
if ( ! F_24 ( V_41 , V_18 -> V_35 ) )
goto V_45;
F_13 ( & V_25 , V_23 ) ;
F_37 ( V_22 ) [ V_11 ] = - 1 ;
F_40 ( V_41 , V_15 [ V_11 ] ) ;
F_14 ( & V_25 , V_23 ) ;
V_18 -> V_34 -- ;
V_45:
F_41 ( & V_43 -> V_44 ) ;
}
return V_46 ;
}
static int T_4 F_42 ( char * V_47 )
{
if ( ! V_47 )
return - V_13 ;
if ( ! strcmp ( V_47 , L_1 ) ) {
V_31 = V_32 ;
V_48 = 1 ;
}
return 0 ;
}
static T_1 F_20 ( int V_16 )
{
return V_30 ;
}
void F_43 ( unsigned int V_1 )
{
unsigned long V_23 ;
F_44 ( V_1 ) ;
F_13 ( & V_25 , V_23 ) ;
F_15 ( V_1 ) ;
V_2 [ V_1 ] = V_49 ;
F_14 ( & V_25 , V_23 ) ;
}
int F_45 ( void )
{
unsigned long V_23 ;
int V_1 , V_11 , V_16 ;
T_1 V_8 = V_26 ;
V_1 = V_11 = - V_7 ;
F_13 ( & V_25 , V_23 ) ;
F_19 (cpu) {
V_8 = F_20 ( V_16 ) ;
V_11 = F_3 ( V_8 ) ;
if ( V_11 >= 0 )
break;
}
if ( V_11 < 0 )
goto V_27;
V_1 = F_2 () ;
if ( V_1 < 0 )
goto V_27;
F_7 ( F_6 ( V_1 , V_11 , V_8 ) ) ;
V_27:
F_14 ( & V_25 , V_23 ) ;
if ( V_1 >= 0 )
F_46 ( V_1 ) ;
return V_1 ;
}
void F_47 ( unsigned int V_1 )
{
F_44 ( V_1 ) ;
F_17 ( V_1 ) ;
}
void
F_48 ( T_3 V_11 , struct V_50 * V_51 )
{
struct V_50 * V_52 = F_49 ( V_51 ) ;
unsigned long V_53 ;
#if V_54
{
unsigned long V_55 , V_56 ;
V_55 = F_50 ( V_57 ) ;
V_56 = F_50 ( V_58 ) ;
if ( ( V_56 - V_55 ) < 1024 ) {
static F_51 ( V_59 , 5 * V_60 , 5 ) ;
if ( F_52 ( & V_59 ) ) {
F_53 ( L_2
L_3
L_4 , V_55 , V_56 ) ;
}
}
}
#endif
F_54 () ;
V_53 = F_50 ( V_61 ) ;
F_55 () ;
while ( V_11 != V_62 ) {
int V_1 = F_56 ( V_11 ) ;
struct V_42 * V_43 = F_38 ( V_1 ) ;
if ( F_32 ( F_57 ( V_11 ) ) ) {
F_58 () ;
F_59 ( V_1 , V_43 ) ;
} else if ( F_32 ( F_60 ( V_11 ) ) ) {
F_61 () ;
F_59 ( V_1 , V_43 ) ;
} else {
F_62 ( V_61 , V_11 ) ;
F_55 () ;
if ( F_32 ( V_1 < 0 ) ) {
F_53 ( V_63 L_5
L_6
L_7 , V_64 , V_11 ,
F_33 () ) ;
} else
F_63 ( V_1 ) ;
F_64 () ;
F_62 ( V_61 , V_53 ) ;
}
F_65 () ;
V_11 = F_66 () ;
}
F_67 () ;
F_49 ( V_52 ) ;
}
void F_68 ( void )
{
T_3 V_11 ;
unsigned long V_53 ;
extern unsigned int V_65 [ V_5 ] ;
V_11 = F_66 () ;
F_54 () ;
V_53 = F_50 ( V_61 ) ;
F_55 () ;
while ( V_11 != V_62 ) {
int V_1 = F_56 ( V_11 ) ;
struct V_42 * V_43 = F_38 ( V_1 ) ;
if ( F_32 ( F_57 ( V_11 ) ) ) {
F_58 () ;
F_59 ( V_1 , V_43 ) ;
} else if ( F_32 ( F_60 ( V_11 ) ) ) {
F_59 ( V_1 , V_43 ) ;
} else {
struct V_50 * V_52 = F_49 ( NULL ) ;
F_62 ( V_61 , V_11 ) ;
F_55 () ;
if ( F_32 ( V_1 < 0 ) ) {
F_53 ( V_63 L_5
L_8
L_9 , V_64 , V_11 ,
F_33 () ) ;
} else {
V_65 [ V_1 ] = 0 ;
F_63 ( V_1 ) ;
}
F_49 ( V_52 ) ;
F_64 () ;
F_62 ( V_61 , V_53 ) ;
}
F_65 () ;
V_11 = F_66 () ;
}
F_67 () ;
}
static T_2 F_69 ( int V_1 , void * V_40 )
{
F_70 () ;
}
void
F_71 ( T_3 V_66 , struct V_67 * V_68 )
{
unsigned int V_1 ;
V_1 = V_66 ;
F_7 ( F_12 ( V_1 , V_66 , V_30 ) ) ;
F_72 ( V_1 , V_69 ) ;
F_73 ( V_1 , & V_70 ) ;
if ( V_68 )
F_74 ( V_1 , V_68 ) ;
F_75 ( V_1 , V_71 ) ;
}
void T_4
F_76 ( void )
{
#ifdef F_77
F_78 ( V_72 , & V_73 ) ;
F_78 ( V_74 , & V_75 ) ;
F_78 ( V_76 , & V_77 ) ;
#endif
}
void T_4
F_79 ( void )
{
#ifdef F_80
F_81 () ;
#endif
F_82 () ;
F_78 ( V_62 , NULL ) ;
#ifdef F_77
#if F_83 ( V_78 ) || F_83 ( V_79 )
if ( V_31 != V_80 )
F_78 ( V_38 , & V_81 ) ;
#endif
#endif
#ifdef F_84
F_85 () ;
#endif
F_86 () ;
}
void
F_87 ( int V_16 , int V_11 , int V_82 , int V_83 )
{
void T_5 * V_84 ;
unsigned long V_85 ;
unsigned long V_86 ;
V_86 = F_88 ( V_16 ) ;
V_85 = ( V_82 << 8 ) | ( V_11 & 0xff ) ;
V_84 = V_87 + ( ( V_86 << 4 ) | ( ( V_83 & 1 ) << 3 ) ) ;
F_89 ( V_85 , V_84 ) ;
}
