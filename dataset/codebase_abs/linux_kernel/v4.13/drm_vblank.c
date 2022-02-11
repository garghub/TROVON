static void F_1 ( struct V_1 * V_2 , unsigned int V_3 ,
T_1 V_4 ,
struct V_5 * V_6 , T_1 V_7 )
{
struct V_8 * V_9 = & V_2 -> V_9 [ V_3 ] ;
F_2 ( & V_2 -> V_10 ) ;
V_9 -> V_7 = V_7 ;
F_3 ( & V_9 -> V_11 ) ;
V_9 -> time = * V_6 ;
V_9 -> V_12 += V_4 ;
F_4 ( & V_9 -> V_11 ) ;
}
static T_1 F_5 ( struct V_1 * V_2 , unsigned int V_3 )
{
F_6 ( V_2 -> V_13 != 0 ) ;
return 0 ;
}
static T_1 F_7 ( struct V_1 * V_2 , unsigned int V_3 )
{
if ( F_8 ( V_2 , V_14 ) ) {
struct V_15 * V_16 = F_9 ( V_2 , V_3 ) ;
if ( V_16 -> V_17 -> V_18 )
return V_16 -> V_17 -> V_18 ( V_16 ) ;
}
if ( V_2 -> V_19 -> V_18 )
return V_2 -> V_19 -> V_18 ( V_2 , V_3 ) ;
return F_5 ( V_2 , V_3 ) ;
}
static void F_10 ( struct V_1 * V_2 , unsigned int V_3 )
{
T_1 V_20 ;
bool V_21 ;
struct V_5 V_6 ;
int V_12 = V_22 ;
F_11 ( & V_2 -> V_10 ) ;
do {
V_20 = F_7 ( V_2 , V_3 ) ;
V_21 = F_12 ( V_2 , V_3 , & V_6 , false ) ;
} while ( V_20 != F_7 ( V_2 , V_3 ) && -- V_12 > 0 );
if ( ! V_21 )
V_6 = (struct V_5 ) { 0 , 0 } ;
F_1 ( V_2 , V_3 , 1 , & V_6 , V_20 ) ;
F_13 ( & V_2 -> V_10 ) ;
}
static void F_14 ( struct V_1 * V_2 , unsigned int V_3 ,
bool V_23 )
{
struct V_8 * V_9 = & V_2 -> V_9 [ V_3 ] ;
T_1 V_20 , V_24 ;
bool V_21 ;
struct V_5 V_6 ;
int V_12 = V_22 ;
int V_25 = V_9 -> V_25 ;
do {
V_20 = F_7 ( V_2 , V_3 ) ;
V_21 = F_12 ( V_2 , V_3 , & V_6 , V_23 ) ;
} while ( V_20 != F_7 ( V_2 , V_3 ) && -- V_12 > 0 );
if ( V_2 -> V_13 != 0 ) {
V_24 = ( V_20 - V_9 -> V_7 ) & V_2 -> V_13 ;
} else if ( V_21 && V_25 ) {
const struct V_5 * V_26 ;
T_2 V_27 ;
V_26 = & V_9 -> time ;
V_27 = F_15 ( & V_6 ) - F_15 ( V_26 ) ;
V_24 = F_16 ( V_27 , V_25 ) ;
if ( V_24 == 0 && V_23 )
F_17 ( L_1
L_2 ,
V_3 , ( long long ) V_27 , V_25 ) ;
} else {
V_24 = V_23 ? 1 : 0 ;
}
if ( V_24 > 1 && ( V_9 -> V_28 & 0x2 ) ) {
F_17 ( L_3
L_4 , V_3 , V_24 ) ;
V_24 = 1 ;
}
F_17 ( L_5
L_6 ,
V_3 , V_9 -> V_12 , V_24 , V_20 , V_9 -> V_7 ) ;
if ( V_24 == 0 ) {
F_6 ( V_20 != V_9 -> V_7 ) ;
return;
}
if ( ! V_21 && ! V_23 )
V_6 = (struct V_5 ) { 0 , 0 } ;
F_1 ( V_2 , V_3 , V_24 , & V_6 , V_20 ) ;
}
static T_1 F_18 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_8 * V_9 = & V_2 -> V_9 [ V_3 ] ;
if ( F_19 ( V_3 >= V_2 -> V_29 ) )
return 0 ;
return V_9 -> V_12 ;
}
T_1 F_20 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = V_16 -> V_2 ;
unsigned int V_3 = F_21 ( V_16 ) ;
T_1 V_9 ;
unsigned long V_30 ;
F_22 ( ! V_2 -> V_19 -> V_31 ,
L_7 ) ;
F_23 ( & V_2 -> V_10 , V_30 ) ;
F_14 ( V_2 , V_3 , false ) ;
V_9 = F_18 ( V_2 , V_3 ) ;
F_24 ( & V_2 -> V_10 , V_30 ) ;
return V_9 ;
}
static void F_25 ( struct V_1 * V_2 , unsigned int V_3 )
{
if ( F_8 ( V_2 , V_14 ) ) {
struct V_15 * V_16 = F_9 ( V_2 , V_3 ) ;
if ( V_16 -> V_17 -> V_32 ) {
V_16 -> V_17 -> V_32 ( V_16 ) ;
return;
}
}
V_2 -> V_19 -> V_32 ( V_2 , V_3 ) ;
}
void F_26 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_8 * V_9 = & V_2 -> V_9 [ V_3 ] ;
unsigned long V_33 ;
F_2 ( & V_2 -> V_34 ) ;
F_23 ( & V_2 -> V_10 , V_33 ) ;
if ( V_9 -> V_35 ) {
F_25 ( V_2 , V_3 ) ;
V_9 -> V_35 = false ;
}
F_14 ( V_2 , V_3 , false ) ;
F_24 ( & V_2 -> V_10 , V_33 ) ;
}
static void F_27 ( unsigned long V_36 )
{
struct V_8 * V_9 = ( void * ) V_36 ;
struct V_1 * V_2 = V_9 -> V_2 ;
unsigned int V_3 = V_9 -> V_3 ;
unsigned long V_33 ;
F_23 ( & V_2 -> V_34 , V_33 ) ;
if ( F_28 ( & V_9 -> V_37 ) == 0 && V_9 -> V_35 ) {
F_29 ( L_8 , V_3 ) ;
F_26 ( V_2 , V_3 ) ;
}
F_24 ( & V_2 -> V_34 , V_33 ) ;
}
void F_30 ( struct V_1 * V_2 )
{
unsigned int V_3 ;
if ( V_2 -> V_29 == 0 )
return;
for ( V_3 = 0 ; V_3 < V_2 -> V_29 ; V_3 ++ ) {
struct V_8 * V_9 = & V_2 -> V_9 [ V_3 ] ;
F_19 ( F_31 ( V_9 -> V_35 ) &&
F_8 ( V_2 , V_14 ) ) ;
F_32 ( & V_9 -> V_38 ) ;
}
F_33 ( V_2 -> V_9 ) ;
V_2 -> V_29 = 0 ;
}
int F_34 ( struct V_1 * V_2 , unsigned int V_29 )
{
int V_39 = - V_40 ;
unsigned int V_41 ;
F_35 ( & V_2 -> V_34 ) ;
F_35 ( & V_2 -> V_10 ) ;
V_2 -> V_29 = V_29 ;
V_2 -> V_9 = F_36 ( V_29 , sizeof( * V_2 -> V_9 ) , V_42 ) ;
if ( ! V_2 -> V_9 )
goto V_43;
for ( V_41 = 0 ; V_41 < V_29 ; V_41 ++ ) {
struct V_8 * V_9 = & V_2 -> V_9 [ V_41 ] ;
V_9 -> V_2 = V_2 ;
V_9 -> V_3 = V_41 ;
F_37 ( & V_9 -> V_44 ) ;
F_38 ( & V_9 -> V_38 , F_27 ,
( unsigned long ) V_9 ) ;
F_39 ( & V_9 -> V_11 ) ;
}
F_40 ( L_9 ) ;
if ( V_2 -> V_19 -> V_31 )
F_40 ( L_10 ) ;
else
F_40 ( L_11 ) ;
if ( V_2 -> V_45 && ! V_2 -> V_19 -> V_31 ) {
V_2 -> V_45 = false ;
F_40 ( L_12
L_13 ) ;
}
return 0 ;
V_43:
V_2 -> V_29 = 0 ;
return V_39 ;
}
T_3 * F_41 ( struct V_15 * V_16 )
{
return & V_16 -> V_2 -> V_9 [ F_21 ( V_16 ) ] . V_44 ;
}
void F_42 ( struct V_15 * V_16 ,
const struct V_46 * V_47 )
{
struct V_1 * V_2 = V_16 -> V_2 ;
unsigned int V_3 = F_21 ( V_16 ) ;
struct V_8 * V_9 = & V_2 -> V_9 [ V_3 ] ;
int V_48 = 0 , V_25 = 0 ;
int V_49 = V_47 -> V_50 ;
if ( ! V_2 -> V_29 )
return;
if ( F_19 ( V_3 >= V_2 -> V_29 ) )
return;
if ( V_49 > 0 ) {
int V_51 = V_47 -> V_52 * V_47 -> V_53 ;
V_48 = F_43 ( ( T_2 ) V_47 -> V_52 * 1000000 , V_49 ) ;
V_25 = F_43 ( ( T_2 ) V_51 * 1000000 , V_49 ) ;
if ( V_47 -> V_30 & V_54 )
V_25 /= 2 ;
} else
F_44 ( L_14 ,
V_16 -> V_55 . V_56 ) ;
V_9 -> V_48 = V_48 ;
V_9 -> V_25 = V_25 ;
V_9 -> V_57 = * V_47 ;
F_29 ( L_15 ,
V_16 -> V_55 . V_56 , V_47 -> V_52 ,
V_47 -> V_53 , V_47 -> V_58 ) ;
F_29 ( L_16 ,
V_16 -> V_55 . V_56 , V_49 , V_25 , V_48 ) ;
}
bool F_45 ( struct V_1 * V_2 ,
unsigned int V_3 ,
int * V_59 ,
struct V_5 * V_60 ,
bool V_23 )
{
struct V_5 V_61 ;
T_4 V_62 , V_63 ;
bool V_64 ;
struct V_15 * V_16 ;
const struct V_46 * V_47 ;
struct V_8 * V_9 = & V_2 -> V_9 [ V_3 ] ;
int V_65 , V_66 , V_41 ;
int V_67 , V_68 ;
if ( ! F_8 ( V_2 , V_14 ) )
return false ;
V_16 = F_9 ( V_2 , V_3 ) ;
if ( V_3 >= V_2 -> V_29 || ! V_16 ) {
F_44 ( L_17 , V_3 ) ;
return false ;
}
if ( ! V_2 -> V_19 -> V_69 ) {
F_44 ( L_18 ) ;
return false ;
}
if ( F_46 ( V_2 ) )
V_47 = & V_9 -> V_57 ;
else
V_47 = & V_16 -> V_57 ;
if ( V_47 -> V_50 == 0 ) {
F_29 ( L_19 , V_3 ) ;
F_6 ( F_46 ( V_2 ) ) ;
return false ;
}
for ( V_41 = 0 ; V_41 < V_22 ; V_41 ++ ) {
V_64 = V_2 -> V_19 -> V_69 ( V_2 , V_3 ,
V_23 ,
& V_65 , & V_66 ,
& V_62 , & V_63 ,
V_47 ) ;
if ( ! V_64 ) {
F_29 ( L_20 ,
V_3 ) ;
return false ;
}
V_68 = F_47 ( V_63 ) - F_47 ( V_62 ) ;
if ( V_68 <= * V_59 )
break;
}
if ( V_41 == V_22 ) {
F_29 ( L_21 ,
V_3 , V_68 / 1000 , * V_59 / 1000 , V_41 ) ;
}
* V_59 = V_68 ;
V_67 = F_48 ( 1000000LL * ( V_65 * V_47 -> V_52 + V_66 ) ,
V_47 -> V_50 ) ;
if ( ! V_70 )
V_63 = F_49 ( V_63 ) ;
V_61 = F_50 ( V_63 ) ;
V_63 = F_51 ( V_63 , V_67 ) ;
* V_60 = F_50 ( V_63 ) ;
F_17 ( L_22 ,
V_3 , V_66 , V_65 ,
( long ) V_61 . V_71 , ( long ) V_61 . V_72 ,
( long ) V_60 -> V_71 , ( long ) V_60 -> V_72 ,
V_68 / 1000 , V_41 ) ;
return true ;
}
static struct V_5 F_52 ( void )
{
T_4 V_73 ;
V_73 = V_70 ? F_53 () : F_54 () ;
return F_50 ( V_73 ) ;
}
static bool
F_12 ( struct V_1 * V_2 , unsigned int V_3 ,
struct V_5 * V_74 , bool V_23 )
{
bool V_39 = false ;
int V_59 = ( int ) V_75 * 1000 ;
if ( V_2 -> V_19 -> V_31 && ( V_59 > 0 ) )
V_39 = V_2 -> V_19 -> V_31 ( V_2 , V_3 , & V_59 ,
V_74 , V_23 ) ;
if ( ! V_39 )
* V_74 = F_52 () ;
return V_39 ;
}
T_1 F_55 ( struct V_15 * V_16 )
{
return F_18 ( V_16 -> V_2 , F_21 ( V_16 ) ) ;
}
static T_1 F_56 ( struct V_1 * V_2 , unsigned int V_3 ,
struct V_5 * V_76 )
{
struct V_8 * V_9 = & V_2 -> V_9 [ V_3 ] ;
T_1 V_77 ;
unsigned int V_78 ;
if ( F_19 ( V_3 >= V_2 -> V_29 ) ) {
* V_76 = (struct V_5 ) { 0 } ;
return 0 ;
}
do {
V_78 = F_57 ( & V_9 -> V_11 ) ;
V_77 = V_9 -> V_12 ;
* V_76 = V_9 -> time ;
} while ( F_58 ( & V_9 -> V_11 , V_78 ) );
return V_77 ;
}
T_1 F_59 ( struct V_15 * V_16 ,
struct V_5 * V_76 )
{
return F_56 ( V_16 -> V_2 , F_21 ( V_16 ) ,
V_76 ) ;
}
static void F_60 ( struct V_1 * V_2 ,
struct V_79 * V_80 ,
unsigned long V_78 , struct V_5 * V_73 )
{
V_80 -> V_81 . V_82 = V_78 ;
V_80 -> V_81 . V_71 = V_73 -> V_71 ;
V_80 -> V_81 . V_72 = V_73 -> V_72 ;
F_61 ( V_80 -> V_55 . V_83 , V_80 -> V_3 ,
V_80 -> V_81 . V_82 ) ;
F_62 ( V_2 , & V_80 -> V_55 ) ;
}
void F_63 ( struct V_15 * V_16 ,
struct V_79 * V_80 )
{
struct V_1 * V_2 = V_16 -> V_2 ;
unsigned int V_3 = F_21 ( V_16 ) ;
F_2 ( & V_2 -> V_84 ) ;
V_80 -> V_3 = V_3 ;
V_80 -> V_81 . V_82 = F_18 ( V_2 , V_3 ) ;
V_80 -> V_81 . V_85 = V_16 -> V_55 . V_56 ;
F_64 ( & V_80 -> V_55 . V_86 , & V_2 -> V_87 ) ;
}
void F_65 ( struct V_15 * V_16 ,
struct V_79 * V_80 )
{
struct V_1 * V_2 = V_16 -> V_2 ;
unsigned int V_78 , V_3 = F_21 ( V_16 ) ;
struct V_5 V_73 ;
if ( V_2 -> V_29 > 0 ) {
V_78 = F_56 ( V_2 , V_3 , & V_73 ) ;
} else {
V_78 = 0 ;
V_73 = F_52 () ;
}
V_80 -> V_3 = V_3 ;
V_80 -> V_81 . V_85 = V_16 -> V_55 . V_56 ;
F_60 ( V_2 , V_80 , V_78 , & V_73 ) ;
}
static int F_66 ( struct V_1 * V_2 , unsigned int V_3 )
{
if ( F_8 ( V_2 , V_14 ) ) {
struct V_15 * V_16 = F_9 ( V_2 , V_3 ) ;
if ( V_16 -> V_17 -> V_88 )
return V_16 -> V_17 -> V_88 ( V_16 ) ;
}
return V_2 -> V_19 -> V_88 ( V_2 , V_3 ) ;
}
static int F_67 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_8 * V_9 = & V_2 -> V_9 [ V_3 ] ;
int V_39 = 0 ;
F_2 ( & V_2 -> V_34 ) ;
F_11 ( & V_2 -> V_10 ) ;
if ( ! V_9 -> V_35 ) {
V_39 = F_66 ( V_2 , V_3 ) ;
F_29 ( L_23 , V_3 , V_39 ) ;
if ( V_39 ) {
F_68 ( & V_9 -> V_37 ) ;
} else {
F_14 ( V_2 , V_3 , 0 ) ;
F_69 ( V_9 -> V_35 , true ) ;
}
}
F_13 ( & V_2 -> V_10 ) ;
return V_39 ;
}
static int F_70 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_8 * V_9 = & V_2 -> V_9 [ V_3 ] ;
unsigned long V_33 ;
int V_39 = 0 ;
if ( ! V_2 -> V_29 )
return - V_89 ;
if ( F_19 ( V_3 >= V_2 -> V_29 ) )
return - V_89 ;
F_23 ( & V_2 -> V_34 , V_33 ) ;
if ( F_71 ( 1 , & V_9 -> V_37 ) == 1 ) {
V_39 = F_67 ( V_2 , V_3 ) ;
} else {
if ( ! V_9 -> V_35 ) {
F_68 ( & V_9 -> V_37 ) ;
V_39 = - V_89 ;
}
}
F_24 ( & V_2 -> V_34 , V_33 ) ;
return V_39 ;
}
int F_72 ( struct V_15 * V_16 )
{
return F_70 ( V_16 -> V_2 , F_21 ( V_16 ) ) ;
}
static void F_73 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_8 * V_9 = & V_2 -> V_9 [ V_3 ] ;
if ( F_19 ( V_3 >= V_2 -> V_29 ) )
return;
if ( F_19 ( F_28 ( & V_9 -> V_37 ) == 0 ) )
return;
if ( F_74 ( & V_9 -> V_37 ) ) {
if ( V_90 == 0 )
return;
else if ( V_90 < 0 )
F_27 ( ( unsigned long ) V_9 ) ;
else if ( ! V_2 -> V_45 )
F_75 ( & V_9 -> V_38 ,
V_91 + ( ( V_90 * V_92 ) / 1000 ) ) ;
}
}
void F_76 ( struct V_15 * V_16 )
{
F_73 ( V_16 -> V_2 , F_21 ( V_16 ) ) ;
}
void F_77 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_8 * V_9 = & V_2 -> V_9 [ V_3 ] ;
int V_39 ;
T_1 V_7 ;
if ( F_19 ( V_3 >= V_2 -> V_29 ) )
return;
V_39 = F_70 ( V_2 , V_3 ) ;
if ( F_22 ( V_39 , L_24 , V_3 , V_39 ) )
return;
V_7 = F_18 ( V_2 , V_3 ) ;
V_39 = F_78 ( V_9 -> V_44 ,
V_7 != F_18 ( V_2 , V_3 ) ,
F_79 ( 100 ) ) ;
F_22 ( V_39 == 0 , L_25 , V_3 ) ;
F_73 ( V_2 , V_3 ) ;
}
void F_80 ( struct V_15 * V_16 )
{
F_77 ( V_16 -> V_2 , F_21 ( V_16 ) ) ;
}
void F_81 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = V_16 -> V_2 ;
unsigned int V_3 = F_21 ( V_16 ) ;
struct V_8 * V_9 = & V_2 -> V_9 [ V_3 ] ;
struct V_79 * V_80 , * V_93 ;
struct V_5 V_73 ;
unsigned long V_33 ;
unsigned int V_78 ;
if ( F_19 ( V_3 >= V_2 -> V_29 ) )
return;
F_23 ( & V_2 -> V_84 , V_33 ) ;
F_11 ( & V_2 -> V_34 ) ;
F_17 ( L_26 ,
V_3 , V_9 -> V_35 , V_9 -> V_28 ) ;
if ( F_8 ( V_2 , V_94 ) || ! V_9 -> V_28 )
F_26 ( V_2 , V_3 ) ;
F_82 ( & V_9 -> V_44 ) ;
if ( ! V_9 -> V_28 ) {
F_83 ( & V_9 -> V_37 ) ;
V_9 -> V_28 = 1 ;
}
F_13 ( & V_2 -> V_34 ) ;
V_78 = F_56 ( V_2 , V_3 , & V_73 ) ;
F_84 (e, t, &dev->vblank_event_list, base.link) {
if ( V_80 -> V_3 != V_3 )
continue;
F_29 ( L_27
L_28 ,
V_80 -> V_81 . V_82 , V_78 ) ;
F_85 ( & V_80 -> V_55 . V_86 ) ;
F_73 ( V_2 , V_3 ) ;
F_60 ( V_2 , V_80 , V_78 , & V_73 ) ;
}
F_24 ( & V_2 -> V_84 , V_33 ) ;
V_9 -> V_57 . V_50 = 0 ;
}
void F_86 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = V_16 -> V_2 ;
unsigned long V_33 ;
unsigned int V_3 = F_21 ( V_16 ) ;
struct V_8 * V_9 = & V_2 -> V_9 [ V_3 ] ;
F_23 ( & V_2 -> V_34 , V_33 ) ;
if ( ! V_9 -> V_28 ) {
F_83 ( & V_9 -> V_37 ) ;
V_9 -> V_28 = 1 ;
}
F_24 ( & V_2 -> V_34 , V_33 ) ;
F_19 ( ! F_87 ( & V_2 -> V_87 ) ) ;
}
void F_88 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = V_16 -> V_2 ;
unsigned int V_3 = F_21 ( V_16 ) ;
struct V_8 * V_9 = & V_2 -> V_9 [ V_3 ] ;
unsigned long V_33 ;
if ( F_19 ( V_3 >= V_2 -> V_29 ) )
return;
F_23 ( & V_2 -> V_34 , V_33 ) ;
F_17 ( L_26 ,
V_3 , V_9 -> V_35 , V_9 -> V_28 ) ;
if ( V_9 -> V_28 ) {
F_68 ( & V_9 -> V_37 ) ;
V_9 -> V_28 = 0 ;
}
F_10 ( V_2 , V_3 ) ;
if ( F_28 ( & V_9 -> V_37 ) != 0 || V_90 == 0 )
F_19 ( F_67 ( V_2 , V_3 ) ) ;
F_24 ( & V_2 -> V_34 , V_33 ) ;
}
static void F_89 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
struct V_8 * V_9 = & V_2 -> V_9 [ V_3 ] ;
if ( ! V_2 -> V_29 )
return;
if ( F_19 ( V_3 >= V_2 -> V_29 ) )
return;
if ( ! V_9 -> V_28 ) {
V_9 -> V_28 = 0x1 ;
if ( F_70 ( V_2 , V_3 ) == 0 )
V_9 -> V_28 |= 0x2 ;
}
}
static void F_90 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
struct V_8 * V_9 = & V_2 -> V_9 [ V_3 ] ;
unsigned long V_33 ;
if ( ! V_2 -> V_29 )
return;
if ( F_19 ( V_3 >= V_2 -> V_29 ) )
return;
if ( V_9 -> V_28 ) {
F_23 ( & V_2 -> V_34 , V_33 ) ;
F_10 ( V_2 , V_3 ) ;
F_24 ( & V_2 -> V_34 , V_33 ) ;
if ( V_9 -> V_28 & 0x2 )
F_73 ( V_2 , V_3 ) ;
V_9 -> V_28 = 0 ;
}
}
int F_91 ( struct V_1 * V_2 , void * V_95 ,
struct V_96 * V_83 )
{
struct V_97 * V_98 = V_95 ;
unsigned int V_3 ;
if ( ! V_2 -> V_29 )
return 0 ;
if ( ! F_8 ( V_2 , V_99 ) )
return 0 ;
V_3 = V_98 -> V_16 ;
if ( V_3 >= V_2 -> V_29 )
return - V_89 ;
switch ( V_98 -> V_100 ) {
case V_101 :
F_89 ( V_2 , V_3 ) ;
break;
case V_102 :
F_90 ( V_2 , V_3 ) ;
break;
default:
return - V_89 ;
}
return 0 ;
}
static inline bool F_92 ( T_1 V_78 , T_1 V_103 )
{
return ( V_78 - V_103 ) <= ( 1 << 23 ) ;
}
static int F_93 ( struct V_1 * V_2 , unsigned int V_3 ,
union V_104 * V_105 ,
struct V_96 * V_83 )
{
struct V_8 * V_9 = & V_2 -> V_9 [ V_3 ] ;
struct V_79 * V_80 ;
struct V_5 V_73 ;
unsigned long V_30 ;
unsigned int V_78 ;
int V_39 ;
V_80 = F_94 ( sizeof( * V_80 ) , V_42 ) ;
if ( V_80 == NULL ) {
V_39 = - V_40 ;
goto V_106;
}
V_80 -> V_3 = V_3 ;
V_80 -> V_81 . V_55 . type = V_107 ;
V_80 -> V_81 . V_55 . V_108 = sizeof( V_80 -> V_81 ) ;
V_80 -> V_81 . V_109 = V_105 -> V_110 . signal ;
F_23 ( & V_2 -> V_84 , V_30 ) ;
if ( ! F_31 ( V_9 -> V_35 ) ) {
V_39 = - V_89 ;
goto V_111;
}
V_39 = F_95 ( V_2 , V_83 , & V_80 -> V_55 ,
& V_80 -> V_81 . V_55 ) ;
if ( V_39 )
goto V_111;
V_78 = F_56 ( V_2 , V_3 , & V_73 ) ;
F_29 ( L_29 ,
V_105 -> V_110 . V_82 , V_78 , V_3 ) ;
F_96 ( V_83 , V_3 ,
V_105 -> V_110 . V_82 ) ;
V_80 -> V_81 . V_82 = V_105 -> V_110 . V_82 ;
if ( F_92 ( V_78 , V_105 -> V_110 . V_82 ) ) {
F_73 ( V_2 , V_3 ) ;
F_60 ( V_2 , V_80 , V_78 , & V_73 ) ;
V_105 -> V_112 . V_82 = V_78 ;
} else {
F_64 ( & V_80 -> V_55 . V_86 , & V_2 -> V_87 ) ;
V_105 -> V_112 . V_82 = V_105 -> V_110 . V_82 ;
}
F_24 ( & V_2 -> V_84 , V_30 ) ;
return 0 ;
V_111:
F_24 ( & V_2 -> V_84 , V_30 ) ;
F_33 ( V_80 ) ;
V_106:
F_73 ( V_2 , V_3 ) ;
return V_39 ;
}
static bool F_97 ( union V_104 * V_105 )
{
if ( V_105 -> V_110 . V_82 )
return false ;
return V_113 ==
( V_105 -> V_110 . type & ( V_114 |
V_115 |
V_116 ) ) ;
}
int V_104 ( struct V_1 * V_2 , void * V_95 ,
struct V_96 * V_83 )
{
struct V_8 * V_9 ;
union V_104 * V_105 = V_95 ;
int V_39 ;
unsigned int V_30 , V_78 , V_3 , V_117 ;
if ( ! V_2 -> V_118 )
return - V_89 ;
if ( V_105 -> V_110 . type & V_119 )
return - V_89 ;
if ( V_105 -> V_110 . type &
~ ( V_114 | V_120 |
V_121 ) ) {
F_44 ( L_30 ,
V_105 -> V_110 . type ,
( V_114 | V_120 |
V_121 ) ) ;
return - V_89 ;
}
V_30 = V_105 -> V_110 . type & V_120 ;
V_117 = ( V_105 -> V_110 . type & V_121 ) ;
if ( V_117 )
V_3 = V_117 >> V_122 ;
else
V_3 = V_30 & V_123 ? 1 : 0 ;
if ( V_3 >= V_2 -> V_29 )
return - V_89 ;
V_9 = & V_2 -> V_9 [ V_3 ] ;
if ( V_2 -> V_45 &&
F_97 ( V_105 ) &&
F_31 ( V_9 -> V_35 ) ) {
struct V_5 V_73 ;
V_105 -> V_112 . V_82 =
F_56 ( V_2 , V_3 , & V_73 ) ;
V_105 -> V_112 . V_124 = V_73 . V_71 ;
V_105 -> V_112 . V_125 = V_73 . V_72 ;
return 0 ;
}
V_39 = F_70 ( V_2 , V_3 ) ;
if ( V_39 ) {
F_29 ( L_31 , V_3 , V_39 ) ;
return V_39 ;
}
V_78 = F_18 ( V_2 , V_3 ) ;
switch ( V_105 -> V_110 . type & V_114 ) {
case V_113 :
V_105 -> V_110 . V_82 += V_78 ;
V_105 -> V_110 . type &= ~ V_113 ;
case V_126 :
break;
default:
V_39 = - V_89 ;
goto V_127;
}
if ( ( V_30 & V_116 ) &&
F_92 ( V_78 , V_105 -> V_110 . V_82 ) )
V_105 -> V_110 . V_82 = V_78 + 1 ;
if ( V_30 & V_115 ) {
return F_93 ( V_2 , V_3 , V_105 , V_83 ) ;
}
if ( V_105 -> V_110 . V_82 != V_78 ) {
F_29 ( L_32 ,
V_105 -> V_110 . V_82 , V_3 ) ;
F_98 ( V_39 , V_9 -> V_44 , 3 * V_92 ,
F_92 ( F_18 ( V_2 , V_3 ) ,
V_105 -> V_110 . V_82 ) ||
! F_31 ( V_9 -> V_35 ) ) ;
}
if ( V_39 != - V_128 ) {
struct V_5 V_73 ;
V_105 -> V_112 . V_82 = F_56 ( V_2 , V_3 , & V_73 ) ;
V_105 -> V_112 . V_124 = V_73 . V_71 ;
V_105 -> V_112 . V_125 = V_73 . V_72 ;
F_29 ( L_33 ,
V_3 , V_105 -> V_112 . V_82 ) ;
} else {
F_29 ( L_34 , V_3 ) ;
}
V_127:
F_73 ( V_2 , V_3 ) ;
return V_39 ;
}
static void F_99 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_79 * V_80 , * V_93 ;
struct V_5 V_73 ;
unsigned int V_78 ;
F_2 ( & V_2 -> V_84 ) ;
V_78 = F_56 ( V_2 , V_3 , & V_73 ) ;
F_84 (e, t, &dev->vblank_event_list, base.link) {
if ( V_80 -> V_3 != V_3 )
continue;
if ( ! F_92 ( V_78 , V_80 -> V_81 . V_82 ) )
continue;
F_29 ( L_35 ,
V_80 -> V_81 . V_82 , V_78 ) ;
F_85 ( & V_80 -> V_55 . V_86 ) ;
F_73 ( V_2 , V_3 ) ;
F_60 ( V_2 , V_80 , V_78 , & V_73 ) ;
}
F_100 ( V_3 , V_78 ) ;
}
bool F_101 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_8 * V_9 = & V_2 -> V_9 [ V_3 ] ;
unsigned long V_33 ;
bool V_129 ;
if ( F_6 ( ! V_2 -> V_29 ) )
return false ;
if ( F_19 ( V_3 >= V_2 -> V_29 ) )
return false ;
F_23 ( & V_2 -> V_84 , V_33 ) ;
F_11 ( & V_2 -> V_10 ) ;
if ( ! V_9 -> V_35 ) {
F_13 ( & V_2 -> V_10 ) ;
F_24 ( & V_2 -> V_84 , V_33 ) ;
return false ;
}
F_14 ( V_2 , V_3 , true ) ;
F_13 ( & V_2 -> V_10 ) ;
F_82 ( & V_9 -> V_44 ) ;
V_129 = ( V_2 -> V_45 &&
V_90 > 0 &&
! F_28 ( & V_9 -> V_37 ) ) ;
F_99 ( V_2 , V_3 ) ;
F_24 ( & V_2 -> V_84 , V_33 ) ;
if ( V_129 )
F_27 ( ( unsigned long ) V_9 ) ;
return true ;
}
bool F_102 ( struct V_15 * V_16 )
{
return F_101 ( V_16 -> V_2 , F_21 ( V_16 ) ) ;
}
