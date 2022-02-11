static inline struct V_1 * F_1 ( void )
{
return V_2 ;
}
static inline void F_2 ( struct V_1 * V_3 )
{
V_2 = V_3 ;
}
static inline void F_3 ( struct V_1 * V_3 )
{
V_2 = NULL ;
}
int F_4 ( void )
{
if ( F_1 () )
return 0 ;
return - V_4 ;
}
int F_5 ( struct V_5 * V_6 )
{
struct V_1 * V_3 = F_1 () ;
unsigned long V_7 ;
unsigned int V_8 ;
int V_9 ;
if ( ! V_3 )
return - V_4 ;
if ( ! V_6 -> V_10 )
return - V_11 ;
V_6 -> V_3 = V_3 ;
F_6 ( & V_3 -> V_12 , V_7 ) ;
V_8 = V_3 -> V_13 ;
if ( V_3 -> V_14 >= V_15 ) {
V_9 = - V_16 ;
if ( V_6 -> V_7 & V_17 )
F_7 ( & V_6 -> V_18 , & V_3 -> V_19 ) ;
} else {
V_9 = - V_20 ;
V_3 -> V_14 ++ ;
F_7 ( & V_6 -> V_18 , & V_3 -> V_6 ) ;
if ( ! V_3 -> V_21 ) {
for ( V_8 = 0 ; V_8 < V_3 -> V_13 ; V_8 ++ ) {
if ( V_3 -> V_22 [ V_8 ] . V_23 )
continue;
break;
}
}
}
F_8 ( & V_3 -> V_12 , V_7 ) ;
if ( V_8 < V_3 -> V_13 )
F_9 ( V_3 -> V_22 [ V_8 ] . V_24 ) ;
return V_9 ;
}
static void F_10 ( struct V_25 * V_26 )
{
struct V_5 * V_6 = F_11 ( V_26 , struct V_5 , V_26 ) ;
struct V_1 * V_3 = V_6 -> V_3 ;
unsigned long V_7 ;
unsigned int V_8 ;
V_6 -> V_10 ( V_6 -> V_27 , - V_20 ) ;
F_6 ( & V_3 -> V_12 , V_7 ) ;
V_3 -> V_14 ++ ;
F_7 ( & V_6 -> V_18 , & V_3 -> V_6 ) ;
for ( V_8 = 0 ; V_8 < V_3 -> V_13 ; V_8 ++ ) {
if ( V_3 -> V_22 [ V_8 ] . V_23 )
continue;
break;
}
F_8 ( & V_3 -> V_12 , V_7 ) ;
if ( V_8 < V_3 -> V_13 )
F_9 ( V_3 -> V_22 [ V_8 ] . V_24 ) ;
}
static struct V_5 * F_12 ( struct V_28 * V_22 )
{
struct V_1 * V_3 = V_22 -> V_3 ;
struct V_5 * V_6 = NULL ;
struct V_5 * V_19 = NULL ;
unsigned long V_7 ;
F_6 ( & V_3 -> V_12 , V_7 ) ;
V_22 -> V_23 = 0 ;
if ( V_3 -> V_21 ) {
V_22 -> V_29 = 1 ;
F_8 ( & V_3 -> V_12 , V_7 ) ;
F_13 ( & V_3 -> V_30 ) ;
return NULL ;
}
if ( V_3 -> V_14 ) {
V_22 -> V_23 = 1 ;
V_6 = F_14 ( & V_3 -> V_6 , struct V_5 , V_18 ) ;
F_15 ( & V_6 -> V_18 ) ;
V_3 -> V_14 -- ;
}
if ( ! F_16 ( & V_3 -> V_19 ) ) {
V_19 = F_14 ( & V_3 -> V_19 , struct V_5 ,
V_18 ) ;
F_15 ( & V_19 -> V_18 ) ;
}
F_8 ( & V_3 -> V_12 , V_7 ) ;
if ( V_19 ) {
F_17 ( & V_19 -> V_26 , F_10 ) ;
F_18 ( & V_19 -> V_26 ) ;
}
return V_6 ;
}
static void F_19 ( unsigned long V_27 )
{
struct V_31 * V_32 = (struct V_31 * ) V_27 ;
struct V_5 * V_6 = V_32 -> V_6 ;
V_6 -> V_10 ( V_6 -> V_27 , V_6 -> V_9 ) ;
F_20 ( & V_32 -> V_33 ) ;
}
static int F_21 ( void * V_27 )
{
struct V_28 * V_22 = (struct V_28 * ) V_27 ;
struct V_5 * V_6 ;
struct V_31 V_32 ;
struct V_34 V_35 ;
F_22 ( & V_35 , F_19 , ( unsigned long ) & V_32 ) ;
F_23 ( V_36 ) ;
while ( ! F_24 () ) {
F_25 () ;
F_23 ( V_36 ) ;
V_6 = F_12 ( V_22 ) ;
if ( ! V_6 )
continue;
F_26 ( V_37 ) ;
V_6 -> V_9 = F_27 ( V_22 , V_6 ) ;
V_32 . V_6 = V_6 ;
F_28 ( & V_32 . V_33 ) ;
F_29 ( & V_35 ) ;
F_30 ( & V_32 . V_33 ) ;
}
F_26 ( V_37 ) ;
return 0 ;
}
static int F_31 ( struct V_38 * V_39 , void * V_27 , T_1 V_40 , bool V_41 )
{
struct V_1 * V_3 = F_11 ( V_39 , struct V_1 , V_38 ) ;
T_2 V_42 ;
int V_43 = F_32 ( int , sizeof( V_42 ) , V_40 ) ;
V_42 = F_33 ( V_3 -> V_44 + V_45 ) ;
if ( ! V_42 ) {
if ( V_3 -> V_46 ++ > V_47 )
return - V_48 ;
return 0 ;
}
V_3 -> V_46 = 0 ;
memcpy ( V_27 , & V_42 , V_43 ) ;
return V_43 ;
}
struct V_1 * F_34 ( struct V_49 * V_50 )
{
struct V_1 * V_3 ;
V_3 = F_35 ( sizeof( * V_3 ) , V_51 ) ;
if ( V_3 == NULL ) {
F_36 ( V_50 , L_1 ) ;
return NULL ;
}
V_3 -> V_50 = V_50 ;
F_37 ( & V_3 -> V_6 ) ;
F_37 ( & V_3 -> V_19 ) ;
F_38 ( & V_3 -> V_12 ) ;
F_39 ( & V_3 -> V_52 ) ;
F_39 ( & V_3 -> V_53 ) ;
V_3 -> V_54 = V_55 ;
V_3 -> V_56 = 0 ;
return V_3 ;
}
int F_40 ( struct V_1 * V_3 )
{
struct V_49 * V_50 = V_3 -> V_50 ;
struct V_28 * V_22 ;
struct V_57 * V_57 ;
char V_58 [ V_59 ] ;
unsigned int V_60 , V_61 , V_8 ;
int V_9 ;
V_61 = 0 ;
V_60 = F_33 ( V_3 -> V_44 + V_62 ) ;
for ( V_8 = 0 ; V_8 < V_63 ; V_8 ++ ) {
if ( ! ( V_60 & ( 1 << V_8 ) ) )
continue;
snprintf ( V_58 , sizeof( V_58 ) , L_2 , V_8 ) ;
V_57 = F_41 ( V_58 , V_50 ,
V_64 ,
V_65 , 0 ) ;
if ( ! V_57 ) {
F_36 ( V_50 , L_3 ) ;
V_9 = - V_66 ;
goto V_67;
}
V_22 = & V_3 -> V_22 [ V_3 -> V_13 ] ;
V_3 -> V_13 ++ ;
V_22 -> V_3 = V_3 ;
V_22 -> V_68 = V_8 ;
V_22 -> V_57 = V_57 ;
V_22 -> V_69 = V_70 + V_3 -> V_56 ++ ;
V_22 -> V_71 = V_70 + V_3 -> V_56 ++ ;
V_3 -> V_54 -= 2 ;
V_22 -> V_72 = V_3 -> V_44 + V_73 +
( V_74 * V_8 ) ;
V_22 -> V_75 = V_3 -> V_44 + V_76 +
( V_74 * V_8 ) ;
V_22 -> V_77 = 1 << ( V_8 * 2 ) ;
V_22 -> V_78 = 1 << ( ( V_8 * 2 ) + 1 ) ;
V_22 -> V_79 = F_42 ( F_33 ( V_22 -> V_72 ) ) ;
F_43 ( & V_22 -> V_80 ) ;
V_61 |= V_22 -> V_77 | V_22 -> V_78 ;
#ifdef F_44
F_45 ( V_3 -> V_81 , V_3 -> V_44 + V_82 +
( V_83 * V_8 ) ) ;
#endif
F_46 ( V_50 , L_4 , V_8 ) ;
}
if ( V_3 -> V_13 == 0 ) {
F_47 ( V_50 , L_5 ) ;
V_9 = - V_48 ;
goto V_67;
}
F_47 ( V_50 , L_6 , V_3 -> V_13 ) ;
F_45 ( 0x00 , V_3 -> V_44 + V_84 ) ;
for ( V_8 = 0 ; V_8 < V_3 -> V_13 ; V_8 ++ ) {
V_22 = & V_3 -> V_22 [ V_8 ] ;
F_33 ( V_22 -> V_75 ) ;
F_33 ( V_22 -> V_72 ) ;
}
F_45 ( V_61 , V_3 -> V_44 + V_85 ) ;
V_9 = V_3 -> V_86 ( V_3 ) ;
if ( V_9 ) {
F_36 ( V_50 , L_7 ) ;
goto V_67;
}
F_43 ( & V_3 -> V_87 ) ;
F_43 ( & V_3 -> V_30 ) ;
for ( V_8 = 0 ; V_8 < V_3 -> V_13 ; V_8 ++ ) {
struct V_88 * V_24 ;
V_22 = & V_3 -> V_22 [ V_8 ] ;
V_24 = F_48 ( F_21 , V_22 ,
L_8 , V_22 -> V_68 ) ;
if ( F_49 ( V_24 ) ) {
F_36 ( V_50 , L_9 ,
F_50 ( V_24 ) ) ;
V_9 = F_50 ( V_24 ) ;
goto V_89;
}
V_22 -> V_24 = V_24 ;
F_9 ( V_24 ) ;
}
V_3 -> V_38 . V_90 = L_10 ;
V_3 -> V_38 . V_91 = F_31 ;
V_9 = F_51 ( & V_3 -> V_38 ) ;
if ( V_9 ) {
F_36 ( V_50 , L_11 , V_9 ) ;
goto V_89;
}
F_2 ( V_3 ) ;
F_45 ( V_61 , V_3 -> V_44 + V_84 ) ;
return 0 ;
V_89:
for ( V_8 = 0 ; V_8 < V_3 -> V_13 ; V_8 ++ )
if ( V_3 -> V_22 [ V_8 ] . V_24 )
F_52 ( V_3 -> V_22 [ V_8 ] . V_24 ) ;
V_3 -> V_92 ( V_3 ) ;
V_67:
for ( V_8 = 0 ; V_8 < V_3 -> V_13 ; V_8 ++ )
F_53 ( V_3 -> V_22 [ V_8 ] . V_57 ) ;
return V_9 ;
}
void F_54 ( struct V_1 * V_3 )
{
struct V_28 * V_22 ;
struct V_5 * V_6 ;
unsigned int V_61 , V_8 ;
F_3 ( V_3 ) ;
F_55 ( & V_3 -> V_38 ) ;
for ( V_8 = 0 ; V_8 < V_3 -> V_13 ; V_8 ++ )
if ( V_3 -> V_22 [ V_8 ] . V_24 )
F_52 ( V_3 -> V_22 [ V_8 ] . V_24 ) ;
V_61 = 0 ;
for ( V_8 = 0 ; V_8 < V_3 -> V_13 ; V_8 ++ ) {
V_22 = & V_3 -> V_22 [ V_8 ] ;
V_61 |= V_22 -> V_77 | V_22 -> V_78 ;
}
F_45 ( 0x00 , V_3 -> V_44 + V_84 ) ;
for ( V_8 = 0 ; V_8 < V_3 -> V_13 ; V_8 ++ ) {
V_22 = & V_3 -> V_22 [ V_8 ] ;
F_33 ( V_22 -> V_75 ) ;
F_33 ( V_22 -> V_72 ) ;
}
F_45 ( V_61 , V_3 -> V_44 + V_85 ) ;
V_3 -> V_92 ( V_3 ) ;
for ( V_8 = 0 ; V_8 < V_3 -> V_13 ; V_8 ++ )
F_53 ( V_3 -> V_22 [ V_8 ] . V_57 ) ;
while ( ! F_16 ( & V_3 -> V_6 ) ) {
V_6 = F_14 ( & V_3 -> V_6 , struct V_5 , V_18 ) ;
F_15 ( & V_6 -> V_18 ) ;
V_6 -> V_10 ( V_6 -> V_27 , - V_4 ) ;
}
while ( ! F_16 ( & V_3 -> V_19 ) ) {
V_6 = F_14 ( & V_3 -> V_19 , struct V_5 , V_18 ) ;
F_15 ( & V_6 -> V_18 ) ;
V_6 -> V_10 ( V_6 -> V_27 , - V_4 ) ;
}
}
T_3 F_56 ( int V_93 , void * V_27 )
{
struct V_49 * V_50 = V_27 ;
struct V_1 * V_3 = F_57 ( V_50 ) ;
struct V_28 * V_22 ;
T_2 V_94 , V_95 ;
unsigned int V_8 ;
V_95 = F_33 ( V_3 -> V_44 + V_85 ) ;
for ( V_8 = 0 ; V_8 < V_3 -> V_13 ; V_8 ++ ) {
V_22 = & V_3 -> V_22 [ V_8 ] ;
V_94 = V_95 & ( V_22 -> V_77 | V_22 -> V_78 ) ;
if ( V_94 ) {
V_22 -> V_96 = V_95 ;
V_22 -> V_97 = F_33 ( V_22 -> V_72 ) ;
V_22 -> V_98 = F_33 ( V_22 -> V_75 ) ;
if ( ( V_94 & V_22 -> V_78 ) && ! V_22 -> V_99 )
V_22 -> V_99 = F_58 ( V_22 -> V_97 ) ;
V_22 -> V_100 = 1 ;
F_45 ( V_94 , V_3 -> V_44 + V_85 ) ;
F_13 ( & V_22 -> V_80 ) ;
}
}
return V_101 ;
}
bool F_59 ( struct V_1 * V_3 )
{
unsigned int V_29 = 0 ;
unsigned long V_7 ;
unsigned int V_8 ;
F_6 ( & V_3 -> V_12 , V_7 ) ;
for ( V_8 = 0 ; V_8 < V_3 -> V_13 ; V_8 ++ )
if ( V_3 -> V_22 [ V_8 ] . V_29 )
V_29 ++ ;
F_8 ( & V_3 -> V_12 , V_7 ) ;
return V_3 -> V_13 == V_29 ;
}
static int T_4 F_60 ( void )
{
#ifdef F_61
struct V_102 * V_103 = & V_104 ;
int V_9 ;
if ( ! F_62 ( V_105 ) )
return - V_4 ;
switch ( V_103 -> V_106 ) {
case 22 :
if ( ( V_103 -> V_107 < 48 ) || ( V_103 -> V_107 > 63 ) )
return - V_4 ;
V_9 = F_63 () ;
if ( V_9 )
return V_9 ;
if ( ! F_1 () ) {
F_64 () ;
return - V_4 ;
}
return 0 ;
break;
}
#endif
#ifdef F_44
int V_9 ;
V_9 = F_65 () ;
if ( V_9 )
return V_9 ;
if ( ! F_1 () ) {
F_66 () ;
return - V_4 ;
}
return 0 ;
#endif
return - V_4 ;
}
static void T_5 F_67 ( void )
{
#ifdef F_61
struct V_102 * V_103 = & V_104 ;
switch ( V_103 -> V_106 ) {
case 22 :
F_64 () ;
break;
}
#endif
#ifdef F_44
F_66 () ;
#endif
}
