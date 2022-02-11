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
int F_4 ( struct V_4 * V_5 )
{
struct V_1 * V_3 = F_1 () ;
unsigned long V_6 ;
unsigned int V_7 ;
int V_8 ;
if ( ! V_3 )
return - V_9 ;
if ( ! V_5 -> V_10 )
return - V_11 ;
V_5 -> V_3 = V_3 ;
F_5 ( & V_3 -> V_12 , V_6 ) ;
V_7 = V_3 -> V_13 ;
if ( V_3 -> V_14 >= V_15 ) {
V_8 = - V_16 ;
if ( V_5 -> V_6 & V_17 )
F_6 ( & V_5 -> V_18 , & V_3 -> V_19 ) ;
} else {
V_8 = - V_20 ;
V_3 -> V_14 ++ ;
F_6 ( & V_5 -> V_18 , & V_3 -> V_5 ) ;
if ( ! V_3 -> V_21 ) {
for ( V_7 = 0 ; V_7 < V_3 -> V_13 ; V_7 ++ ) {
if ( V_3 -> V_22 [ V_7 ] . V_23 )
continue;
break;
}
}
}
F_7 ( & V_3 -> V_12 , V_6 ) ;
if ( V_7 < V_3 -> V_13 )
F_8 ( V_3 -> V_22 [ V_7 ] . V_24 ) ;
return V_8 ;
}
static void F_9 ( struct V_25 * V_26 )
{
struct V_4 * V_5 = F_10 ( V_26 , struct V_4 , V_26 ) ;
struct V_1 * V_3 = V_5 -> V_3 ;
unsigned long V_6 ;
unsigned int V_7 ;
V_5 -> V_10 ( V_5 -> V_27 , - V_20 ) ;
F_5 ( & V_3 -> V_12 , V_6 ) ;
V_3 -> V_14 ++ ;
F_6 ( & V_5 -> V_18 , & V_3 -> V_5 ) ;
for ( V_7 = 0 ; V_7 < V_3 -> V_13 ; V_7 ++ ) {
if ( V_3 -> V_22 [ V_7 ] . V_23 )
continue;
break;
}
F_7 ( & V_3 -> V_12 , V_6 ) ;
if ( V_7 < V_3 -> V_13 )
F_8 ( V_3 -> V_22 [ V_7 ] . V_24 ) ;
}
static struct V_4 * F_11 ( struct V_28 * V_22 )
{
struct V_1 * V_3 = V_22 -> V_3 ;
struct V_4 * V_5 = NULL ;
struct V_4 * V_19 = NULL ;
unsigned long V_6 ;
F_5 ( & V_3 -> V_12 , V_6 ) ;
V_22 -> V_23 = 0 ;
if ( V_3 -> V_21 ) {
V_22 -> V_29 = 1 ;
F_7 ( & V_3 -> V_12 , V_6 ) ;
F_12 ( & V_3 -> V_30 ) ;
return NULL ;
}
if ( V_3 -> V_14 ) {
V_22 -> V_23 = 1 ;
V_5 = F_13 ( & V_3 -> V_5 , struct V_4 , V_18 ) ;
F_14 ( & V_5 -> V_18 ) ;
V_3 -> V_14 -- ;
}
if ( ! F_15 ( & V_3 -> V_19 ) ) {
V_19 = F_13 ( & V_3 -> V_19 , struct V_4 ,
V_18 ) ;
F_14 ( & V_19 -> V_18 ) ;
}
F_7 ( & V_3 -> V_12 , V_6 ) ;
if ( V_19 ) {
F_16 ( & V_19 -> V_26 , F_9 ) ;
F_17 ( & V_19 -> V_26 ) ;
}
return V_5 ;
}
static void F_18 ( unsigned long V_27 )
{
struct V_31 * V_32 = (struct V_31 * ) V_27 ;
struct V_4 * V_5 = V_32 -> V_5 ;
V_5 -> V_10 ( V_5 -> V_27 , V_5 -> V_8 ) ;
F_19 ( & V_32 -> V_33 ) ;
}
static int F_20 ( void * V_27 )
{
struct V_28 * V_22 = (struct V_28 * ) V_27 ;
struct V_4 * V_5 ;
struct V_31 V_32 ;
struct V_34 V_35 ;
F_21 ( & V_35 , F_18 , ( unsigned long ) & V_32 ) ;
F_22 ( V_36 ) ;
while ( ! F_23 () ) {
F_24 () ;
F_22 ( V_36 ) ;
V_5 = F_11 ( V_22 ) ;
if ( ! V_5 )
continue;
F_25 ( V_37 ) ;
V_5 -> V_8 = F_26 ( V_22 , V_5 ) ;
V_32 . V_5 = V_5 ;
F_27 ( & V_32 . V_33 ) ;
F_28 ( & V_35 ) ;
F_29 ( & V_32 . V_33 ) ;
}
F_25 ( V_37 ) ;
return 0 ;
}
static int F_30 ( struct V_38 * V_39 , void * V_27 , T_1 V_40 , bool V_41 )
{
struct V_1 * V_3 = F_10 ( V_39 , struct V_1 , V_38 ) ;
T_2 V_42 ;
int V_43 = F_31 ( int , sizeof( V_42 ) , V_40 ) ;
V_42 = F_32 ( V_3 -> V_44 + V_45 ) ;
if ( ! V_42 ) {
if ( V_3 -> V_46 ++ > V_47 )
return - V_48 ;
return 0 ;
}
V_3 -> V_46 = 0 ;
memcpy ( V_27 , & V_42 , V_43 ) ;
return V_43 ;
}
struct V_1 * F_33 ( struct V_49 * V_50 )
{
struct V_1 * V_3 ;
V_3 = F_34 ( sizeof( * V_3 ) , V_51 ) ;
if ( V_3 == NULL ) {
F_35 ( V_50 , L_1 ) ;
return NULL ;
}
V_3 -> V_50 = V_50 ;
F_36 ( & V_3 -> V_5 ) ;
F_36 ( & V_3 -> V_19 ) ;
F_37 ( & V_3 -> V_12 ) ;
F_38 ( & V_3 -> V_52 ) ;
F_38 ( & V_3 -> V_53 ) ;
V_3 -> V_54 = V_55 ;
V_3 -> V_56 = 0 ;
return V_3 ;
}
int F_39 ( struct V_1 * V_3 )
{
struct V_49 * V_50 = V_3 -> V_50 ;
struct V_28 * V_22 ;
struct V_57 * V_57 ;
char V_58 [ V_59 ] ;
unsigned int V_60 , V_61 , V_7 ;
int V_8 ;
V_61 = 0 ;
V_60 = F_32 ( V_3 -> V_44 + V_62 ) ;
for ( V_7 = 0 ; V_7 < V_63 ; V_7 ++ ) {
if ( ! ( V_60 & ( 1 << V_7 ) ) )
continue;
snprintf ( V_58 , sizeof( V_58 ) , L_2 , V_7 ) ;
V_57 = F_40 ( V_58 , V_50 ,
V_64 ,
V_65 , 0 ) ;
if ( ! V_57 ) {
F_35 ( V_50 , L_3 ) ;
V_8 = - V_66 ;
goto V_67;
}
V_22 = & V_3 -> V_22 [ V_3 -> V_13 ] ;
V_3 -> V_13 ++ ;
V_22 -> V_3 = V_3 ;
V_22 -> V_68 = V_7 ;
V_22 -> V_57 = V_57 ;
V_22 -> V_69 = V_70 + V_3 -> V_56 ++ ;
V_22 -> V_71 = V_70 + V_3 -> V_56 ++ ;
V_3 -> V_54 -= 2 ;
V_22 -> V_72 = V_3 -> V_44 + V_73 +
( V_74 * V_7 ) ;
V_22 -> V_75 = V_3 -> V_44 + V_76 +
( V_74 * V_7 ) ;
V_22 -> V_77 = 1 << ( V_7 * 2 ) ;
V_22 -> V_78 = 1 << ( ( V_7 * 2 ) + 1 ) ;
V_22 -> V_79 = F_41 ( F_32 ( V_22 -> V_72 ) ) ;
F_42 ( & V_22 -> V_80 ) ;
V_61 |= V_22 -> V_77 | V_22 -> V_78 ;
F_43 ( V_50 , L_4 , V_7 ) ;
}
if ( V_3 -> V_13 == 0 ) {
F_44 ( V_50 , L_5 ) ;
V_8 = - V_48 ;
goto V_67;
}
F_44 ( V_50 , L_6 , V_3 -> V_13 ) ;
F_45 ( 0x00 , V_3 -> V_44 + V_81 ) ;
for ( V_7 = 0 ; V_7 < V_3 -> V_13 ; V_7 ++ ) {
V_22 = & V_3 -> V_22 [ V_7 ] ;
F_32 ( V_22 -> V_75 ) ;
F_32 ( V_22 -> V_72 ) ;
}
F_45 ( V_61 , V_3 -> V_44 + V_82 ) ;
V_8 = V_3 -> V_83 ( V_3 ) ;
if ( V_8 ) {
F_35 ( V_50 , L_7 ) ;
goto V_67;
}
F_42 ( & V_3 -> V_84 ) ;
F_42 ( & V_3 -> V_30 ) ;
for ( V_7 = 0 ; V_7 < V_3 -> V_13 ; V_7 ++ ) {
struct V_85 * V_24 ;
V_22 = & V_3 -> V_22 [ V_7 ] ;
V_24 = F_46 ( F_20 , V_22 ,
L_8 , V_22 -> V_68 ) ;
if ( F_47 ( V_24 ) ) {
F_35 ( V_50 , L_9 ,
F_48 ( V_24 ) ) ;
V_8 = F_48 ( V_24 ) ;
goto V_86;
}
V_22 -> V_24 = V_24 ;
F_8 ( V_24 ) ;
}
V_3 -> V_38 . V_87 = L_10 ;
V_3 -> V_38 . V_88 = F_30 ;
V_8 = F_49 ( & V_3 -> V_38 ) ;
if ( V_8 ) {
F_35 ( V_50 , L_11 , V_8 ) ;
goto V_86;
}
F_2 ( V_3 ) ;
F_45 ( V_61 , V_3 -> V_44 + V_81 ) ;
return 0 ;
V_86:
for ( V_7 = 0 ; V_7 < V_3 -> V_13 ; V_7 ++ )
if ( V_3 -> V_22 [ V_7 ] . V_24 )
F_50 ( V_3 -> V_22 [ V_7 ] . V_24 ) ;
V_3 -> V_89 ( V_3 ) ;
V_67:
for ( V_7 = 0 ; V_7 < V_3 -> V_13 ; V_7 ++ )
F_51 ( V_3 -> V_22 [ V_7 ] . V_57 ) ;
return V_8 ;
}
void F_52 ( struct V_1 * V_3 )
{
struct V_28 * V_22 ;
struct V_4 * V_5 ;
unsigned int V_61 , V_7 ;
F_3 ( V_3 ) ;
F_53 ( & V_3 -> V_38 ) ;
for ( V_7 = 0 ; V_7 < V_3 -> V_13 ; V_7 ++ )
if ( V_3 -> V_22 [ V_7 ] . V_24 )
F_50 ( V_3 -> V_22 [ V_7 ] . V_24 ) ;
V_61 = 0 ;
for ( V_7 = 0 ; V_7 < V_3 -> V_13 ; V_7 ++ ) {
V_22 = & V_3 -> V_22 [ V_7 ] ;
V_61 |= V_22 -> V_77 | V_22 -> V_78 ;
}
F_45 ( 0x00 , V_3 -> V_44 + V_81 ) ;
for ( V_7 = 0 ; V_7 < V_3 -> V_13 ; V_7 ++ ) {
V_22 = & V_3 -> V_22 [ V_7 ] ;
F_32 ( V_22 -> V_75 ) ;
F_32 ( V_22 -> V_72 ) ;
}
F_45 ( V_61 , V_3 -> V_44 + V_82 ) ;
V_3 -> V_89 ( V_3 ) ;
for ( V_7 = 0 ; V_7 < V_3 -> V_13 ; V_7 ++ )
F_51 ( V_3 -> V_22 [ V_7 ] . V_57 ) ;
while ( ! F_15 ( & V_3 -> V_5 ) ) {
V_5 = F_13 ( & V_3 -> V_5 , struct V_4 , V_18 ) ;
F_14 ( & V_5 -> V_18 ) ;
V_5 -> V_10 ( V_5 -> V_27 , - V_9 ) ;
}
while ( ! F_15 ( & V_3 -> V_19 ) ) {
V_5 = F_13 ( & V_3 -> V_19 , struct V_4 , V_18 ) ;
F_14 ( & V_5 -> V_18 ) ;
V_5 -> V_10 ( V_5 -> V_27 , - V_9 ) ;
}
}
T_3 F_54 ( int V_90 , void * V_27 )
{
struct V_49 * V_50 = V_27 ;
struct V_1 * V_3 = F_55 ( V_50 ) ;
struct V_28 * V_22 ;
T_2 V_91 , V_92 ;
unsigned int V_7 ;
V_92 = F_32 ( V_3 -> V_44 + V_82 ) ;
for ( V_7 = 0 ; V_7 < V_3 -> V_13 ; V_7 ++ ) {
V_22 = & V_3 -> V_22 [ V_7 ] ;
V_91 = V_92 & ( V_22 -> V_77 | V_22 -> V_78 ) ;
if ( V_91 ) {
V_22 -> V_93 = V_92 ;
V_22 -> V_94 = F_32 ( V_22 -> V_72 ) ;
V_22 -> V_95 = F_32 ( V_22 -> V_75 ) ;
if ( ( V_91 & V_22 -> V_78 ) && ! V_22 -> V_96 )
V_22 -> V_96 = F_56 ( V_22 -> V_94 ) ;
V_22 -> V_97 = 1 ;
F_45 ( V_91 , V_3 -> V_44 + V_82 ) ;
F_12 ( & V_22 -> V_80 ) ;
}
}
return V_98 ;
}
bool F_57 ( struct V_1 * V_3 )
{
unsigned int V_29 = 0 ;
unsigned long V_6 ;
unsigned int V_7 ;
F_5 ( & V_3 -> V_12 , V_6 ) ;
for ( V_7 = 0 ; V_7 < V_3 -> V_13 ; V_7 ++ )
if ( V_3 -> V_22 [ V_7 ] . V_29 )
V_29 ++ ;
F_7 ( & V_3 -> V_12 , V_6 ) ;
return V_3 -> V_13 == V_29 ;
}
static int T_4 F_58 ( void )
{
struct V_99 * V_100 = & V_101 ;
int V_8 ;
if ( ! F_59 ( V_102 ) )
return - V_9 ;
switch ( V_100 -> V_103 ) {
case 22 :
if ( ( V_100 -> V_104 < 48 ) || ( V_100 -> V_104 > 63 ) )
return - V_9 ;
V_8 = F_60 () ;
if ( V_8 )
return V_8 ;
if ( ! F_1 () ) {
F_61 () ;
return - V_9 ;
}
return 0 ;
break;
}
return - V_9 ;
}
static void T_5 F_62 ( void )
{
struct V_99 * V_100 = & V_101 ;
switch ( V_100 -> V_103 ) {
case 22 :
F_61 () ;
break;
}
}
