static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( & V_3 -> V_4 ) ;
}
static T_1 F_3 ( struct V_5 * V_4 , struct V_6 * V_7 , char * V_8 )
{
struct V_2 * V_3 = F_4 ( V_4 ) ;
struct V_1 * V_9 = F_1 ( V_3 ) ;
unsigned long V_10 ;
int V_11 ;
F_5 ( & V_9 -> V_12 , V_10 ) ;
V_11 = sprintf ( V_8 , L_1 , V_9 -> V_13 ) ;
F_6 ( & V_9 -> V_12 , V_10 ) ;
return V_11 ;
}
static T_1 F_7 ( struct V_5 * V_4 , struct V_6 * V_7 , char * V_8 )
{
struct V_2 * V_3 = F_4 ( V_4 ) ;
struct V_1 * V_9 = F_1 ( V_3 ) ;
unsigned long V_10 ;
int V_11 ;
F_5 ( & V_9 -> V_12 , V_10 ) ;
V_11 = sprintf ( V_8 , L_2 , & V_9 -> V_14 [ 0 ] ) ;
F_6 ( & V_9 -> V_12 , V_10 ) ;
return V_11 ;
}
static T_1 F_8 ( struct V_5 * V_4 , struct V_6 * V_7 , const char * V_8 ,
T_2 V_15 )
{
F_9 ( V_16 L_3 ) ;
return - V_17 ;
}
static T_1 F_10 ( struct V_5 * V_4 , struct V_6 * V_7 , char * V_8 )
{
struct V_2 * V_3 = F_4 ( V_4 ) ;
struct V_1 * V_9 = F_1 ( V_3 ) ;
unsigned long V_10 ;
int V_11 ;
F_5 ( & V_9 -> V_12 , V_10 ) ;
V_11 = sprintf ( V_8 , L_2 , & V_9 -> V_14 [ 0 ] ) ;
F_6 ( & V_9 -> V_12 , V_10 ) ;
return V_11 ;
}
static T_1 F_11 ( struct V_5 * V_4 , struct V_6 * V_7 , const char * V_8 ,
T_2 V_15 )
{
struct V_2 * V_3 = F_4 ( V_4 ) ;
struct V_1 * V_9 = F_1 ( V_3 ) ;
unsigned long V_10 ;
if ( F_12 ( V_8 , NULL , 0 ) != 0 )
return - V_18 ;
F_5 ( & V_9 -> V_12 , V_10 ) ;
if ( V_9 -> V_19 . V_15 > 0 ) {
F_6 ( & V_9 -> V_12 , V_10 ) ;
F_9 ( V_16 L_4
L_5 ) ;
return - V_17 ;
}
if ( V_9 -> V_20 == 0 ) {
F_6 ( & V_9 -> V_12 , V_10 ) ;
F_9 ( V_16 L_6
L_7 ) ;
return - V_17 ;
}
F_13 ( V_9 ) ;
F_9 ( V_16 L_8
L_9 ,
V_9 -> V_21 -> V_22 ,
V_9 -> V_13 ,
( V_23 ) V_9 -> V_24 ) ;
F_6 ( & V_9 -> V_12 , V_10 ) ;
return V_15 ;
}
static T_1 F_14 ( struct V_5 * V_4 , struct V_6 * V_7 , char * V_8 )
{
struct V_2 * V_3 = F_4 ( V_4 ) ;
struct V_1 * V_9 = F_1 ( V_3 ) ;
unsigned long V_10 ;
int V_11 ;
F_5 ( & V_9 -> V_12 , V_10 ) ;
V_11 = sprintf ( V_8 , L_10 , V_9 -> V_20 ) ;
F_6 ( & V_9 -> V_12 , V_10 ) ;
return V_11 ;
}
static T_1 F_15 ( struct V_5 * V_4 , struct V_6 * V_7 , char * V_8 )
{
struct V_2 * V_3 = F_4 ( V_4 ) ;
struct V_1 * V_9 = F_1 ( V_3 ) ;
unsigned long V_10 ;
int V_11 ;
F_5 ( & V_9 -> V_12 , V_10 ) ;
V_11 = sprintf ( V_8 , L_10 , V_9 -> V_25 ) ;
F_6 ( & V_9 -> V_12 , V_10 ) ;
return V_11 ;
}
static T_1 F_16 ( struct V_26 * V_27 , char * V_8 )
{
return snprintf ( V_8 , V_28 , L_10 , V_29 ) ;
}
static T_1 F_17 ( struct V_26 * V_27 , const char * V_8 ,
T_2 V_15 )
{
if ( ( F_12 ( V_8 , NULL , 0 ) != 1 )
&& ( V_29 != 0 ) )
return - V_18 ;
V_29 = 1 ;
F_9 ( V_16 L_11
L_12 ) ;
F_18 () ;
V_29 = 0 ;
return V_15 ;
}
static void F_19 ( void )
{
V_30 = 1 ;
F_20 () ;
F_21 ( V_31 ) ;
}
static void F_22 ( struct V_32 * V_33 )
{
struct V_1 * V_9 = V_33 -> V_34 ;
unsigned long V_10 ;
F_5 ( & V_9 -> V_12 , V_10 ) ;
V_9 -> V_35 |= V_36 ;
F_6 ( & V_9 -> V_12 , V_10 ) ;
F_19 () ;
}
static void F_23 ( struct V_32 * V_33 )
{
struct V_1 * V_9 = V_33 -> V_34 ;
unsigned long V_10 ;
F_5 ( & V_9 -> V_12 , V_10 ) ;
F_24 ( V_9 -> V_21 ) ;
F_6 ( & V_9 -> V_12 , V_10 ) ;
}
static T_3 F_25 ( int V_37 , void * V_38 )
{
struct V_1 * V_9 = V_38 ;
F_26 ( & V_9 -> V_12 ) ;
F_24 ( V_9 -> V_21 ) ;
V_9 -> V_35 |= V_36 ;
F_27 ( & V_9 -> V_12 ) ;
F_19 () ;
return V_39 ;
}
static void F_28 ( struct V_1 * V_9 )
{
V_23 V_22 = V_9 -> V_21 -> V_22 ;
struct V_32 * V_33 = V_9 -> V_19 . V_33 ;
int V_40 ;
if ( V_9 -> V_35 & V_41 ) {
V_40 = F_29 ( V_22 ,
& V_9 -> V_42 [ 0 ] ,
V_9 -> V_43 ) ;
if ( V_40 > 0 ) {
V_9 -> V_43 = 0 ;
V_9 -> V_35 &= ~ ( V_41 ) ;
if ( V_33 ) {
F_30 ( V_33 ) ;
}
}
}
}
static int F_31 ( struct V_1 * V_9 )
{
V_23 V_22 ;
struct V_32 * V_33 ;
char V_8 [ V_44 ] V_45 ;
unsigned long V_10 ;
int V_46 = 0 ;
F_5 ( & V_9 -> V_12 , V_10 ) ;
V_22 = V_9 -> V_21 -> V_22 ;
V_33 = V_9 -> V_19 . V_33 ;
F_28 ( V_9 ) ;
if ( ! V_33 || F_32 ( V_47 , & V_33 -> V_10 ) ) {
V_9 -> V_35 &= ~ ( V_48 ) ;
goto V_49;
} else if ( ! ( V_9 -> V_35 & ( V_48 ) ) )
goto V_49;
V_9 -> V_35 &= ~ ( V_48 ) ;
if ( F_33 ( & V_9 -> V_19 , V_44 ) >= V_44 ) {
V_46 = F_34 ( V_22 ,
& V_8 [ 0 ] ,
V_44 ) ;
F_35 ( & V_9 -> V_19 , V_8 , V_46 ) ;
}
if ( V_46 )
V_9 -> V_35 |= V_50 ;
F_6 ( & V_9 -> V_12 , V_10 ) ;
if( V_46 )
F_36 ( & V_9 -> V_19 ) ;
if ( ! V_46 ) {
F_5 ( & V_9 -> V_12 , V_10 ) ;
F_37 ( V_9 -> V_21 ) ;
F_6 ( & V_9 -> V_12 , V_10 ) ;
}
return V_9 -> V_35 ;
V_49:
F_6 ( & V_9 -> V_12 , V_10 ) ;
return V_9 -> V_35 ;
}
static int F_38 ( void * V_51 )
{
struct V_1 * V_9 ;
int V_52 ;
F_39 ( V_53 ) ;
do {
V_52 = 0 ;
V_30 = 0 ;
F_20 () ;
F_26 ( & V_54 ) ;
F_40 (hvcsd, &hvcs_structs, next) {
V_52 |= F_31 ( V_9 ) ;
}
F_27 ( & V_54 ) ;
if ( V_52 & ( V_41 | V_50 ) ) {
F_41 () ;
continue;
}
F_42 ( V_55 ) ;
if ( ! V_30 )
F_43 () ;
F_39 ( V_53 ) ;
} while ( ! F_44 () );
return 0 ;
}
static void F_45 ( int V_25 )
{
if ( ! V_56 )
return;
if ( V_25 < 0 || V_25 >= V_57 )
return;
if ( V_56 [ V_25 ] == - 1 )
return;
else
V_56 [ V_25 ] = - 1 ;
}
static void F_46 ( struct V_58 * V_59 )
{
struct V_1 * V_9 = F_47 ( V_59 , struct V_1 , V_19 ) ;
struct V_2 * V_21 ;
unsigned long V_10 ;
F_26 ( & V_54 ) ;
F_5 ( & V_9 -> V_12 , V_10 ) ;
F_48 ( & ( V_9 -> V_60 ) ) ;
if ( V_9 -> V_20 == 1 ) {
F_13 ( V_9 ) ;
F_9 ( V_16 L_8
L_9 ,
V_9 -> V_21 -> V_22 ,
V_9 -> V_13 ,
( V_23 ) V_9 -> V_24 ) ;
}
F_9 ( V_16 L_13 ,
V_9 -> V_21 -> V_22 ) ;
V_21 = V_9 -> V_21 ;
V_9 -> V_21 = NULL ;
V_9 -> V_13 = 0 ;
V_9 -> V_24 = 0 ;
F_45 ( V_9 -> V_25 ) ;
memset ( & V_9 -> V_14 [ 0 ] , 0x00 , V_61 + 1 ) ;
F_6 ( & V_9 -> V_12 , V_10 ) ;
F_27 ( & V_54 ) ;
F_49 ( & V_21 -> V_4 . V_62 , & V_63 ) ;
F_50 ( V_9 ) ;
}
static int F_51 ( void )
{
int V_64 ;
if ( ! V_56 ) {
F_9 ( V_65 L_14 ) ;
return - V_66 ;
}
for( V_64 = 0 ; V_64 < V_57 ; V_64 ++ ) {
if ( V_56 [ V_64 ] == - 1 ) {
V_56 [ V_64 ] = 0 ;
return V_64 ;
}
}
return - 1 ;
}
static int F_52 (
struct V_2 * V_4 ,
const struct V_67 * V_68 )
{
struct V_1 * V_9 ;
int V_25 , V_69 ;
int V_11 ;
if ( ! V_4 || ! V_68 ) {
F_9 ( V_65 L_15 ) ;
return - V_17 ;
}
V_69 = F_53 () ;
if ( V_69 ) {
F_54 ( L_16 ) ;
return V_69 ;
}
V_25 = F_51 () ;
if ( V_25 < 0 ) {
return - V_66 ;
}
V_9 = F_55 ( sizeof( * V_9 ) , V_70 ) ;
if ( ! V_9 )
return - V_71 ;
F_56 ( & V_9 -> V_19 ) ;
V_9 -> V_19 . V_72 = & V_73 ;
F_57 ( & V_9 -> V_12 ) ;
V_9 -> V_21 = V_4 ;
F_58 ( & V_4 -> V_4 , V_9 ) ;
V_9 -> V_25 = V_25 ;
V_9 -> V_43 = 0 ;
V_9 -> V_35 = 0 ;
V_9 -> V_20 = 0 ;
if ( F_59 ( V_9 ) ) {
F_9 ( V_65 L_17
L_18 ,
V_9 -> V_21 -> V_22 ) ;
}
F_26 ( & V_54 ) ;
F_60 ( & ( V_9 -> V_60 ) , & V_74 ) ;
F_27 ( & V_54 ) ;
V_11 = F_61 ( & V_4 -> V_4 . V_62 , & V_63 ) ;
if ( V_11 ) {
F_9 ( V_65 L_19 ,
V_9 -> V_21 -> V_22 ) ;
return V_11 ;
}
F_9 ( V_16 L_20 , V_4 -> V_22 ) ;
return 0 ;
}
static int F_62 ( struct V_2 * V_4 )
{
struct V_1 * V_9 = F_2 ( & V_4 -> V_4 ) ;
unsigned long V_10 ;
struct V_32 * V_33 ;
if ( ! V_9 )
return - V_71 ;
F_5 ( & V_9 -> V_12 , V_10 ) ;
V_33 = V_9 -> V_19 . V_33 ;
F_6 ( & V_9 -> V_12 , V_10 ) ;
F_63 ( & V_9 -> V_19 ) ;
if ( V_33 )
F_64 ( V_33 ) ;
F_9 ( V_16 L_21
L_22 , V_4 -> V_22 ) ;
return 0 ;
}
static void F_65 ( struct V_75 * V_76 , struct V_1 * V_9 )
{
V_9 -> V_13 = V_76 -> V_22 ;
V_9 -> V_24 = V_76 -> V_77 ;
F_66 ( & V_9 -> V_14 [ 0 ] ,
& V_76 -> V_78 [ 0 ] , sizeof( V_9 -> V_14 ) ) ;
}
static int F_59 ( struct V_1 * V_9 )
{
struct V_75 * V_76 ;
V_23 V_22 = V_9 -> V_21 -> V_22 ;
struct V_79 V_80 ;
int V_11 ;
F_26 ( & V_81 ) ;
if ( ! V_82 ) {
F_27 ( & V_81 ) ;
return - V_66 ;
}
V_11 = F_67 ( V_22 , & V_80 , V_82 ) ;
F_27 ( & V_81 ) ;
if ( V_11 ) {
F_9 ( V_65 L_17
L_23 , V_22 ) ;
return V_11 ;
}
V_9 -> V_13 = 0 ;
V_9 -> V_24 = 0 ;
F_40 (pi, &head, node)
F_65 ( V_76 , V_9 ) ;
F_68 ( & V_80 ) ;
return 0 ;
}
static int F_18 ( void )
{
struct V_1 * V_9 ;
unsigned long V_10 ;
F_26 ( & V_54 ) ;
F_40 (hvcsd, &hvcs_structs, next) {
F_5 ( & V_9 -> V_12 , V_10 ) ;
F_59 ( V_9 ) ;
F_6 ( & V_9 -> V_12 , V_10 ) ;
}
F_27 ( & V_54 ) ;
return 0 ;
}
static int F_69 ( struct V_1 * V_9 )
{
if ( ( ! V_9 -> V_13 ) || ( ! V_9 -> V_24 ) )
return 0 ;
return 1 ;
}
static int F_70 ( struct V_1 * V_9 )
{
int V_11 ;
unsigned int V_22 = V_9 -> V_21 -> V_22 ;
V_11 = F_71 ( V_22 ,
V_9 -> V_24 ,
V_9 -> V_13 ) ;
if ( ! V_11 ) {
V_9 -> V_20 = 1 ;
return 0 ;
} else if ( V_11 != - V_18 )
return V_11 ;
if ( F_59 ( V_9 ) )
return - V_83 ;
if ( ! F_69 ( V_9 ) )
return - V_71 ;
V_11 = F_71 ( V_22 ,
V_9 -> V_24 ,
V_9 -> V_13 ) ;
if ( V_11 != - V_18 ) {
V_9 -> V_20 = 1 ;
return V_11 ;
}
F_9 ( V_16 L_24
L_25 ) ;
return - V_84 ;
}
static void F_13 ( struct V_1 * V_9 )
{
int V_11 ;
do {
V_11 = F_72 ( V_9 -> V_21 -> V_22 ) ;
} while ( V_11 == - V_84 );
V_9 -> V_20 = 0 ;
}
static int F_73 ( struct V_1 * V_9 , V_23 V_22 ,
unsigned int V_37 , struct V_2 * V_21 )
{
unsigned long V_10 ;
int V_69 ;
if ( ! ( V_69 = F_74 ( V_37 , & F_25 ,
0 , L_26 , V_9 ) ) ) {
if ( F_37 ( V_21 ) == V_85 )
return 0 ;
else {
F_9 ( V_65 L_27
L_28 , V_22 ) ;
F_75 ( V_37 , V_9 ) ;
}
} else
F_9 ( V_65 L_29
L_28 , V_22 ) ;
F_5 ( & V_9 -> V_12 , V_10 ) ;
F_13 ( V_9 ) ;
F_6 ( & V_9 -> V_12 , V_10 ) ;
return V_69 ;
}
static struct V_1 * F_76 ( int V_25 )
{
struct V_1 * V_9 ;
unsigned long V_10 ;
F_26 ( & V_54 ) ;
F_40 (hvcsd, &hvcs_structs, next) {
F_5 ( & V_9 -> V_12 , V_10 ) ;
if ( V_9 -> V_25 == V_25 ) {
F_77 ( & V_9 -> V_19 ) ;
F_6 ( & V_9 -> V_12 , V_10 ) ;
F_27 ( & V_54 ) ;
return V_9 ;
}
F_6 ( & V_9 -> V_12 , V_10 ) ;
}
F_27 ( & V_54 ) ;
return NULL ;
}
static int F_78 ( struct V_86 * V_87 , struct V_32 * V_33 )
{
struct V_1 * V_9 ;
struct V_2 * V_21 ;
unsigned long V_22 , V_10 ;
unsigned int V_37 ;
int V_11 ;
V_9 = F_76 ( V_33 -> V_25 ) ;
if ( ! V_9 ) {
F_9 ( V_88 L_30
L_31 , V_33 -> V_25 ) ;
return - V_71 ;
}
F_5 ( & V_9 -> V_12 , V_10 ) ;
if ( V_9 -> V_20 == 0 ) {
V_11 = F_70 ( V_9 ) ;
if ( V_11 ) {
F_6 ( & V_9 -> V_12 , V_10 ) ;
F_9 ( V_88 L_32 ) ;
goto V_89;
}
}
V_9 -> V_19 . V_15 = 0 ;
V_9 -> V_19 . V_33 = V_33 ;
V_33 -> V_34 = V_9 ;
memset ( & V_9 -> V_42 [ 0 ] , 0x00 , V_44 ) ;
V_37 = V_9 -> V_21 -> V_37 ;
V_21 = V_9 -> V_21 ;
V_22 = V_9 -> V_21 -> V_22 ;
V_9 -> V_35 |= V_36 ;
F_6 ( & V_9 -> V_12 , V_10 ) ;
V_11 = F_73 ( V_9 , V_22 , V_37 , V_21 ) ;
if ( V_11 ) {
F_9 ( V_88 L_33 ) ;
goto V_89;
}
V_11 = F_79 ( & V_9 -> V_19 , V_87 , V_33 ) ;
if ( V_11 )
goto V_90;
return 0 ;
V_90:
F_5 ( & V_9 -> V_12 , V_10 ) ;
F_24 ( V_9 -> V_21 ) ;
F_6 ( & V_9 -> V_12 , V_10 ) ;
F_75 ( V_37 , V_9 ) ;
V_89:
F_63 ( & V_9 -> V_19 ) ;
return V_11 ;
}
static int F_80 ( struct V_32 * V_33 , struct V_91 * V_92 )
{
struct V_1 * V_9 = V_33 -> V_34 ;
unsigned long V_10 ;
F_5 ( & V_9 -> V_12 , V_10 ) ;
V_9 -> V_19 . V_15 ++ ;
V_9 -> V_35 |= V_36 ;
F_6 ( & V_9 -> V_12 , V_10 ) ;
F_19 () ;
F_9 ( V_16 L_34 ,
V_9 -> V_21 -> V_22 ) ;
return 0 ;
}
static void F_81 ( struct V_32 * V_33 , struct V_91 * V_92 )
{
struct V_1 * V_9 ;
unsigned long V_10 ;
int V_37 ;
if ( F_82 ( V_92 ) )
return;
if ( ! V_33 -> V_34 )
return;
V_9 = V_33 -> V_34 ;
F_5 ( & V_9 -> V_12 , V_10 ) ;
if ( -- V_9 -> V_19 . V_15 == 0 ) {
F_24 ( V_9 -> V_21 ) ;
V_9 -> V_19 . V_33 = NULL ;
V_37 = V_9 -> V_21 -> V_37 ;
F_6 ( & V_9 -> V_12 , V_10 ) ;
F_83 ( V_33 , V_93 ) ;
V_33 -> V_34 = NULL ;
F_75 ( V_37 , V_9 ) ;
return;
} else if ( V_9 -> V_19 . V_15 < 0 ) {
F_9 ( V_65 L_35
L_36 ,
V_9 -> V_21 -> V_22 , V_9 -> V_19 . V_15 ) ;
}
F_6 ( & V_9 -> V_12 , V_10 ) ;
}
static void F_84 ( struct V_32 * V_33 )
{
struct V_1 * V_9 = V_33 -> V_34 ;
F_63 ( & V_9 -> V_19 ) ;
}
static void F_85 ( struct V_32 * V_33 )
{
struct V_1 * V_9 = V_33 -> V_34 ;
unsigned long V_10 ;
int V_94 ;
int V_37 ;
F_5 ( & V_9 -> V_12 , V_10 ) ;
V_94 = V_9 -> V_19 . V_15 ;
F_24 ( V_9 -> V_21 ) ;
V_9 -> V_35 = 0 ;
V_33 -> V_34 = NULL ;
V_9 -> V_19 . V_33 = NULL ;
V_9 -> V_19 . V_15 = 0 ;
memset ( & V_9 -> V_42 [ 0 ] , 0x00 , V_44 ) ;
V_9 -> V_43 = 0 ;
V_37 = V_9 -> V_21 -> V_37 ;
F_6 ( & V_9 -> V_12 , V_10 ) ;
F_75 ( V_37 , V_9 ) ;
while( V_94 ) {
-- V_94 ;
F_63 ( & V_9 -> V_19 ) ;
}
}
static int F_86 ( struct V_32 * V_33 ,
const unsigned char * V_8 , int V_15 )
{
struct V_1 * V_9 = V_33 -> V_34 ;
unsigned int V_22 ;
const unsigned char * V_95 ;
unsigned long V_10 ;
int V_96 = 0 ;
int V_97 = 0 ;
int V_98 = 0 ;
if ( ! V_9 )
return - V_71 ;
if ( V_15 > V_99 ) {
F_9 ( V_88 L_37
L_38 ) ;
V_15 = V_99 ;
}
V_95 = V_8 ;
F_5 ( & V_9 -> V_12 , V_10 ) ;
if ( V_9 -> V_19 . V_15 <= 0 ) {
F_6 ( & V_9 -> V_12 , V_10 ) ;
return - V_71 ;
}
V_22 = V_9 -> V_21 -> V_22 ;
while ( V_15 > 0 ) {
V_97 = F_87 ( V_15 , ( V_44 - V_9 -> V_43 ) ) ;
if ( ! V_97 )
break;
memcpy ( & V_9 -> V_42 [ V_9 -> V_43 ] ,
& V_95 [ V_96 ] ,
V_97 ) ;
V_9 -> V_43 += V_97 ;
V_98 = 0 ;
if ( ! ( V_9 -> V_35 & V_41 ) )
V_98 = F_29 ( V_22 ,
& V_9 -> V_42 [ 0 ] ,
V_9 -> V_43 ) ;
V_96 += V_97 ;
V_15 -= V_97 ;
if ( V_98 == 0 ) {
V_9 -> V_35 |= V_41 ;
F_19 () ;
break;
}
V_9 -> V_43 = 0 ;
if ( V_98 < 0 )
break;
}
F_6 ( & V_9 -> V_12 , V_10 ) ;
if ( V_98 == - 1 )
return - V_100 ;
else
return V_96 ;
}
static int F_88 ( struct V_32 * V_33 )
{
struct V_1 * V_9 = V_33 -> V_34 ;
if ( ! V_9 || V_9 -> V_19 . V_15 <= 0 )
return 0 ;
return V_44 - V_9 -> V_43 ;
}
static int F_89 ( struct V_32 * V_33 )
{
struct V_1 * V_9 = V_33 -> V_34 ;
return V_9 -> V_43 ;
}
static int F_90 ( int V_101 )
{
int V_64 ;
V_56 = F_91 ( V_101 * sizeof( V_57 ) , V_70 ) ;
if ( ! V_56 )
return - V_83 ;
V_57 = V_101 ;
for ( V_64 = 0 ; V_64 < V_57 ; V_64 ++ )
V_56 [ V_64 ] = - 1 ;
return 0 ;
}
static void F_92 ( void )
{
F_50 ( V_56 ) ;
V_56 = NULL ;
V_57 = 0 ;
}
static int F_53 ( void )
{
int V_69 , V_102 ;
F_93 ( & V_103 ) ;
if ( V_31 ) {
F_94 ( & V_103 ) ;
return 0 ;
}
if ( V_104 <= 0 ||
( V_104 > V_105 ) ) {
V_102 = V_106 ;
} else
V_102 = V_104 ;
V_107 = F_95 ( V_102 ) ;
if ( ! V_107 ) {
F_94 ( & V_103 ) ;
return - V_83 ;
}
if ( F_90 ( V_102 ) ) {
V_69 = - V_83 ;
goto V_108;
}
V_107 -> V_109 = V_110 ;
V_107 -> V_111 = V_112 ;
V_107 -> V_113 = V_114 ;
V_107 -> type = V_115 ;
V_107 -> V_116 = V_117 ;
V_107 -> V_10 = V_118 ;
F_96 ( V_107 , & V_119 ) ;
if ( F_97 ( V_107 ) ) {
F_9 ( V_65 L_39 ) ;
V_69 = - V_100 ;
goto V_120;
}
V_82 = ( unsigned long * ) F_98 ( V_70 ) ;
if ( ! V_82 ) {
V_69 = - V_83 ;
goto V_121;
}
V_31 = F_99 ( F_38 , NULL , L_40 ) ;
if ( F_100 ( V_31 ) ) {
F_9 ( V_65 L_41 ) ;
V_69 = - V_100 ;
goto V_122;
}
F_94 ( & V_103 ) ;
return 0 ;
V_122:
F_101 ( ( unsigned long ) V_82 ) ;
V_121:
F_102 ( V_107 ) ;
V_120:
F_92 () ;
V_108:
F_103 ( V_107 ) ;
V_107 = NULL ;
F_94 ( & V_103 ) ;
return V_69 ;
}
static int T_4 F_104 ( void )
{
int V_69 = F_105 ( & V_123 ) ;
if ( V_69 ) {
F_9 ( V_65 L_42 ) ;
return V_69 ;
}
F_106 ( L_43 ) ;
V_69 = F_107 ( & ( V_123 . V_87 ) , & V_124 ) ;
if ( V_69 )
F_108 ( L_44 , V_69 ) ;
return 0 ;
}
static void T_5 F_109 ( void )
{
F_110 ( & V_123 ) ;
if ( ! V_31 )
return;
F_111 ( V_31 ) ;
F_26 ( & V_81 ) ;
F_101 ( ( unsigned long ) V_82 ) ;
V_82 = NULL ;
F_27 ( & V_81 ) ;
F_112 ( & V_123 . V_87 , & V_124 ) ;
F_102 ( V_107 ) ;
F_92 () ;
F_103 ( V_107 ) ;
F_9 ( V_16 L_45 ) ;
}
