int T_1 F_1 ( unsigned long V_1 ,
const char * V_2 , int V_3 , void * V_4 )
{
const void * V_5 , * V_6 ;
unsigned long V_7 , V_8 ;
if ( V_3 != 1 || strcmp ( V_2 , L_1 ) != 0 )
return 0 ;
V_5 = F_2 ( V_1 , L_2 , & V_7 ) ;
V_6 = F_2 ( V_1 , L_3 , & V_8 ) ;
if ( ! V_5 || ! V_6 )
return 1 ;
V_9 . V_10 = F_3 ( V_5 , V_7 / 4 ) ;
V_9 . V_11 = F_3 ( V_6 , V_8 / 4 ) ;
F_4 ( L_4 ,
V_9 . V_10 , V_5 , V_7 ) ;
F_4 ( L_5 ,
V_9 . V_11 , V_6 , V_8 ) ;
V_12 |= V_13 ;
if ( F_5 ( V_1 , L_6 ) ) {
V_12 |= V_14 ;
V_12 |= V_15 ;
F_6 ( L_7 ) ;
} else if ( F_5 ( V_1 , L_8 ) ) {
V_12 |= V_14 ;
F_6 ( L_9 ) ;
} else {
F_6 ( L_10 ) ;
}
return 1 ;
}
static int T_1 F_7 ( void )
{
#ifdef F_8
T_2 V_16 ;
if ( ! ( V_12 & V_13 ) )
return - V_17 ;
V_16 = 0x7000 ;
F_9 ( V_18 ,
0 , V_16 ) ;
V_16 += 128 ;
F_9 ( V_19 , 0 , V_16 ) ;
#endif
return 0 ;
}
int F_10 ( struct V_20 * V_21 )
{
if ( ! V_21 ) {
F_11 ( L_11 ,
V_22 , V_21 ) ;
return - V_23 ;
}
F_12 ( & V_24 , V_21 ) ;
return 0 ;
}
static void F_13 ( T_3 V_25 )
{
unsigned long V_26 ;
T_3 V_27 ;
if ( F_14 ( & V_28 ) )
return;
F_15 ( & V_29 , V_26 ) ;
V_27 = V_30 ^ V_25 ;
V_30 = V_25 ;
F_16 ( & V_29 , V_26 ) ;
F_17 ( & V_24 ,
V_25 , ( void * ) V_27 ) ;
}
void F_18 ( T_3 V_31 ,
T_3 V_32 )
{
unsigned long V_26 ;
F_15 ( & V_29 , V_26 ) ;
V_30 &= ~ V_31 ;
V_30 |= V_32 ;
F_16 ( & V_29 , V_26 ) ;
}
void F_19 ( void )
{
T_4 V_33 ;
T_3 V_34 = 0 ;
F_20 ( & V_28 , 0 ) ;
V_33 = F_21 ( & V_34 ) ;
if ( V_33 == V_35 && V_34 )
F_13 ( V_34 ) ;
}
void F_22 ( void )
{
F_20 ( & V_28 , 1 ) ;
}
int F_23 ( enum V_36 V_37 ,
struct V_20 * V_21 )
{
if ( ! V_21 ) {
F_11 ( L_11 ,
V_22 , V_21 ) ;
return - V_23 ;
}
if ( V_37 > V_38 ) {
F_11 ( L_12 ,
V_22 , V_37 ) ;
return - V_23 ;
}
return F_12 (
& V_39 [ V_37 ] , V_21 ) ;
}
static void F_24 ( T_5 V_37 , void * V_40 )
{
F_17 ( & V_39 [ V_37 ] ,
V_37 , V_40 ) ;
}
static void F_25 ( void )
{
T_6 V_41 ;
static struct V_42 V_40 ;
V_41 = F_26 ( F_27 ( & V_40 ) , sizeof( V_40 ) ) ;
if ( V_41 == V_43 )
return;
if ( V_41 ) {
F_11 ( L_13 ,
V_22 , V_41 ) ;
return;
}
if ( V_40 . V_37 > V_38 ) {
F_11 ( L_14 ,
V_22 , V_40 . V_37 ) ;
return;
}
F_24 ( V_40 . V_37 , ( void * ) & V_40 ) ;
}
static int F_28 ( struct V_20 * V_21 ,
unsigned long V_25 , void * V_44 )
{
if ( V_25 & V_45 )
F_25 () ;
return 0 ;
}
static int T_1 F_29 ( void )
{
int V_41 , V_46 ;
for ( V_46 = 0 ; V_46 < V_38 ; V_46 ++ )
F_30 ( & V_39 [ V_46 ] ) ;
V_41 = F_10 ( & V_47 ) ;
if ( V_41 ) {
F_31 ( L_15 ,
V_22 , V_41 ) ;
return V_41 ;
}
return 0 ;
}
int F_32 ( T_5 V_48 , char * V_49 , int V_50 )
{
T_6 V_33 ;
T_7 V_34 , V_51 ;
if ( ! V_9 . V_11 )
return - V_17 ;
F_21 ( & V_34 ) ;
if ( ( F_33 ( V_34 ) & V_52 ) == 0 )
return 0 ;
V_51 = F_34 ( V_50 ) ;
V_33 = F_35 ( V_48 , & V_51 , V_49 ) ;
if ( V_33 == V_35 )
return F_33 ( V_51 ) ;
return 0 ;
}
int F_36 ( T_5 V_48 , const char * V_4 , int V_53 )
{
int V_54 = 0 ;
T_7 V_55 ;
T_6 V_51 , V_33 ;
unsigned long V_26 ;
T_7 V_34 ;
if ( ! V_9 . V_11 )
return - V_17 ;
F_15 ( & V_56 , V_26 ) ;
if ( F_37 ( V_14 ) ) {
V_33 = F_38 ( V_48 , & V_55 ) ;
V_51 = F_33 ( V_55 ) ;
if ( V_33 || V_51 < V_53 ) {
F_16 ( & V_56 , V_26 ) ;
if ( V_33 )
return V_53 ;
F_21 ( NULL ) ;
return - V_57 ;
}
}
V_33 = V_58 ;
while( V_53 > 0 && ( V_33 == V_58 ||
V_33 == V_59 || V_33 == V_35 ) ) {
V_55 = F_34 ( V_53 ) ;
V_33 = F_39 ( V_48 , & V_55 , V_4 ) ;
V_51 = F_33 ( V_55 ) ;
if ( V_33 != V_35 && V_33 != V_58 &&
V_33 != V_59 ) {
V_54 = V_53 ;
break;
}
if ( V_33 == V_35 ) {
V_53 -= V_51 ;
V_4 += V_51 ;
V_54 += V_51 ;
}
do
F_21 ( & V_34 ) ;
while( V_33 == V_35 &&
( F_33 ( V_34 ) & V_60 ) );
}
F_16 ( & V_56 , V_26 ) ;
return V_54 ;
}
static int F_40 ( struct V_61 * V_62 ,
struct V_63 * V_34 )
{
int V_64 = 0 ;
T_3 V_65 = F_41 ( V_34 ) ;
if ( ! ( V_62 -> V_66 & V_67 ) ) {
V_64 = 0 ;
} else if ( V_34 -> V_68 == V_69 ) {
V_64 = 1 ;
} else if ( V_65 && ! F_42 ( V_65 ) ) {
if ( F_43 ( V_62 ) && ! F_44 ( V_70 ) ) {
F_45 ( V_71 , V_62 , V_72 , V_62 -> V_73 ) ;
V_64 = 1 ;
} else
V_64 = 0 ;
} else if ( F_43 ( V_62 ) && ! F_44 ( V_70 ) &&
V_34 -> V_74 == V_75 ) {
F_45 ( V_71 , V_62 , V_72 , V_62 -> V_73 ) ;
V_64 = 1 ;
}
return V_64 ;
}
int F_46 ( struct V_61 * V_62 )
{
struct V_63 V_34 ;
if ( ! F_47 ( & V_34 , V_76 ) )
return 0 ;
if ( V_34 . V_77 != V_78 ) {
F_31 ( L_16 ,
V_34 . V_77 ) ;
return 0 ;
}
F_48 ( & V_34 ) ;
if ( F_40 ( V_62 , & V_34 ) )
return 1 ;
return 0 ;
}
static T_8 F_49 ( int V_79 , void * V_4 )
{
T_7 V_25 ;
F_50 ( F_51 ( V_79 ) , & V_25 ) ;
F_13 ( V_25 ) ;
return V_80 ;
}
static int F_52 ( void )
{
V_81 = F_53 ( L_17 , V_82 ) ;
if ( ! V_81 ) {
F_54 ( L_18 ) ;
return - V_83 ;
}
return 0 ;
}
static int T_1 F_55 ( void )
{
struct V_84 * V_85 , * V_86 ;
const T_9 * V_87 ;
int V_33 , V_46 , V_88 ;
V_89 = F_56 ( L_19 ) ;
if ( ! V_89 ) {
F_54 ( L_20 ) ;
return - V_17 ;
}
if ( F_37 ( V_14 ) )
V_86 = F_56 ( L_21 ) ;
else
V_86 = F_57 ( V_89 ) ;
if ( V_86 ) {
F_58 (consoles, np) {
if ( strcmp ( V_85 -> V_90 , L_22 ) )
continue;
F_59 ( V_85 , NULL , NULL ) ;
}
F_60 ( V_86 ) ;
}
V_87 = F_61 ( V_89 , L_23 , & V_88 ) ;
F_4 ( L_24 ,
V_87 ? ( V_88 / 4 ) : 0 ) ;
V_91 = V_88 / 4 ;
V_92 = F_62 ( V_91 * sizeof( unsigned int ) , V_93 ) ;
for ( V_46 = 0 ; V_87 && V_46 < ( V_88 / 4 ) ; V_46 ++ , V_87 ++ ) {
unsigned int V_94 = F_63 ( V_87 ) ;
unsigned int V_79 = F_64 ( NULL , V_94 ) ;
if ( V_79 == V_95 ) {
F_11 ( L_25 , V_94 ) ;
continue;
}
V_33 = F_65 ( V_79 , F_49 , 0 , L_17 , NULL ) ;
if ( V_33 )
F_11 ( L_26
L_27 , V_33 , V_79 , V_94 ) ;
V_92 [ V_46 ] = V_79 ;
}
V_33 = F_52 () ;
if ( V_33 == 0 ) {
F_66 () ;
}
return 0 ;
}
void F_67 ( void )
{
unsigned int V_46 ;
long V_33 = V_58 ;
for ( V_46 = 0 ; V_46 < V_91 ; V_46 ++ ) {
if ( V_92 [ V_46 ] )
F_68 ( V_92 [ V_46 ] , NULL ) ;
V_92 [ V_46 ] = 0 ;
}
while ( V_33 == V_58 || V_33 == V_59 ) {
V_33 = F_69 () ;
if ( V_33 == V_58 )
F_21 ( NULL ) ;
else
F_70 ( 10 ) ;
}
}
