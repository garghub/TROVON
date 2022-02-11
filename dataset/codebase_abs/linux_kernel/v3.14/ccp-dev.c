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
static void F_18 ( struct V_25 * V_26 )
{
struct V_4 * V_5 = F_10 ( V_26 , struct V_4 , V_26 ) ;
V_5 -> V_10 ( V_5 -> V_27 , V_5 -> V_8 ) ;
}
static int F_19 ( void * V_27 )
{
struct V_28 * V_22 = (struct V_28 * ) V_27 ;
struct V_4 * V_5 ;
F_20 ( V_31 ) ;
while ( ! F_21 () ) {
F_22 () ;
F_20 ( V_31 ) ;
V_5 = F_11 ( V_22 ) ;
if ( ! V_5 )
continue;
F_23 ( V_32 ) ;
V_5 -> V_8 = F_24 ( V_22 , V_5 ) ;
F_16 ( & V_5 -> V_26 , F_18 ) ;
F_17 ( & V_5 -> V_26 ) ;
}
F_23 ( V_32 ) ;
return 0 ;
}
static int F_25 ( struct V_33 * V_34 , void * V_27 , T_1 V_35 , bool V_36 )
{
struct V_1 * V_3 = F_10 ( V_34 , struct V_1 , V_33 ) ;
T_2 V_37 ;
int V_38 = F_26 ( int , sizeof( V_37 ) , V_35 ) ;
V_37 = F_27 ( V_3 -> V_39 + V_40 ) ;
if ( ! V_37 ) {
if ( V_3 -> V_41 ++ > V_42 )
return - V_43 ;
return 0 ;
}
V_3 -> V_41 = 0 ;
memcpy ( V_27 , & V_37 , V_38 ) ;
return V_38 ;
}
struct V_1 * F_28 ( struct V_44 * V_45 )
{
struct V_1 * V_3 ;
V_3 = F_29 ( sizeof( * V_3 ) , V_46 ) ;
if ( V_3 == NULL ) {
F_30 ( V_45 , L_1 ) ;
return NULL ;
}
V_3 -> V_45 = V_45 ;
F_31 ( & V_3 -> V_5 ) ;
F_31 ( & V_3 -> V_19 ) ;
F_32 ( & V_3 -> V_12 ) ;
F_33 ( & V_3 -> V_47 ) ;
F_33 ( & V_3 -> V_48 ) ;
V_3 -> V_49 = V_50 ;
V_3 -> V_51 = 0 ;
return V_3 ;
}
int F_34 ( struct V_1 * V_3 )
{
struct V_44 * V_45 = V_3 -> V_45 ;
struct V_28 * V_22 ;
struct V_52 * V_52 ;
char V_53 [ V_54 ] ;
unsigned int V_55 , V_56 , V_7 ;
int V_8 ;
V_56 = 0 ;
V_55 = F_27 ( V_3 -> V_39 + V_57 ) ;
for ( V_7 = 0 ; V_7 < V_58 ; V_7 ++ ) {
if ( ! ( V_55 & ( 1 << V_7 ) ) )
continue;
snprintf ( V_53 , sizeof( V_53 ) , L_2 , V_7 ) ;
V_52 = F_35 ( V_53 , V_45 ,
V_59 ,
V_60 , 0 ) ;
if ( ! V_52 ) {
F_30 ( V_45 , L_3 ) ;
V_8 = - V_61 ;
goto V_62;
}
V_22 = & V_3 -> V_22 [ V_3 -> V_13 ] ;
V_3 -> V_13 ++ ;
V_22 -> V_3 = V_3 ;
V_22 -> V_63 = V_7 ;
V_22 -> V_52 = V_52 ;
V_22 -> V_64 = V_65 + V_3 -> V_51 ++ ;
V_22 -> V_66 = V_65 + V_3 -> V_51 ++ ;
V_3 -> V_49 -= 2 ;
V_22 -> V_67 = V_3 -> V_39 + V_68 +
( V_69 * V_7 ) ;
V_22 -> V_70 = V_3 -> V_39 + V_71 +
( V_69 * V_7 ) ;
V_22 -> V_72 = 1 << ( V_7 * 2 ) ;
V_22 -> V_73 = 1 << ( ( V_7 * 2 ) + 1 ) ;
V_22 -> V_74 = F_36 ( F_27 ( V_22 -> V_67 ) ) ;
F_37 ( & V_22 -> V_75 ) ;
V_56 |= V_22 -> V_72 | V_22 -> V_73 ;
F_38 ( V_45 , L_4 , V_7 ) ;
}
if ( V_3 -> V_13 == 0 ) {
F_39 ( V_45 , L_5 ) ;
V_8 = - V_43 ;
goto V_62;
}
F_39 ( V_45 , L_6 , V_3 -> V_13 ) ;
F_40 ( 0x00 , V_3 -> V_39 + V_76 ) ;
for ( V_7 = 0 ; V_7 < V_3 -> V_13 ; V_7 ++ ) {
V_22 = & V_3 -> V_22 [ V_7 ] ;
F_27 ( V_22 -> V_70 ) ;
F_27 ( V_22 -> V_67 ) ;
}
F_40 ( V_56 , V_3 -> V_39 + V_77 ) ;
V_8 = V_3 -> V_78 ( V_3 ) ;
if ( V_8 ) {
F_30 ( V_45 , L_7 ) ;
goto V_62;
}
F_37 ( & V_3 -> V_79 ) ;
F_37 ( & V_3 -> V_30 ) ;
for ( V_7 = 0 ; V_7 < V_3 -> V_13 ; V_7 ++ ) {
struct V_80 * V_24 ;
V_22 = & V_3 -> V_22 [ V_7 ] ;
V_24 = F_41 ( F_19 , V_22 ,
L_8 , V_22 -> V_63 ) ;
if ( F_42 ( V_24 ) ) {
F_30 ( V_45 , L_9 ,
F_43 ( V_24 ) ) ;
V_8 = F_43 ( V_24 ) ;
goto V_81;
}
V_22 -> V_24 = V_24 ;
F_8 ( V_24 ) ;
}
V_3 -> V_33 . V_82 = L_10 ;
V_3 -> V_33 . V_83 = F_25 ;
V_8 = F_44 ( & V_3 -> V_33 ) ;
if ( V_8 ) {
F_30 ( V_45 , L_11 , V_8 ) ;
goto V_81;
}
F_2 ( V_3 ) ;
F_40 ( V_56 , V_3 -> V_39 + V_76 ) ;
return 0 ;
V_81:
for ( V_7 = 0 ; V_7 < V_3 -> V_13 ; V_7 ++ )
if ( V_3 -> V_22 [ V_7 ] . V_24 )
F_45 ( V_3 -> V_22 [ V_7 ] . V_24 ) ;
V_3 -> V_84 ( V_3 ) ;
V_62:
for ( V_7 = 0 ; V_7 < V_3 -> V_13 ; V_7 ++ )
F_46 ( V_3 -> V_22 [ V_7 ] . V_52 ) ;
return V_8 ;
}
void F_47 ( struct V_1 * V_3 )
{
struct V_28 * V_22 ;
struct V_4 * V_5 ;
unsigned int V_56 , V_7 ;
F_3 ( V_3 ) ;
F_48 ( & V_3 -> V_33 ) ;
for ( V_7 = 0 ; V_7 < V_3 -> V_13 ; V_7 ++ )
if ( V_3 -> V_22 [ V_7 ] . V_24 )
F_45 ( V_3 -> V_22 [ V_7 ] . V_24 ) ;
V_56 = 0 ;
for ( V_7 = 0 ; V_7 < V_3 -> V_13 ; V_7 ++ ) {
V_22 = & V_3 -> V_22 [ V_7 ] ;
V_56 |= V_22 -> V_72 | V_22 -> V_73 ;
}
F_40 ( 0x00 , V_3 -> V_39 + V_76 ) ;
for ( V_7 = 0 ; V_7 < V_3 -> V_13 ; V_7 ++ ) {
V_22 = & V_3 -> V_22 [ V_7 ] ;
F_27 ( V_22 -> V_70 ) ;
F_27 ( V_22 -> V_67 ) ;
}
F_40 ( V_56 , V_3 -> V_39 + V_77 ) ;
V_3 -> V_84 ( V_3 ) ;
for ( V_7 = 0 ; V_7 < V_3 -> V_13 ; V_7 ++ )
F_46 ( V_3 -> V_22 [ V_7 ] . V_52 ) ;
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
T_3 F_49 ( int V_85 , void * V_27 )
{
struct V_44 * V_45 = V_27 ;
struct V_1 * V_3 = F_50 ( V_45 ) ;
struct V_28 * V_22 ;
T_2 V_86 , V_87 ;
unsigned int V_7 ;
V_87 = F_27 ( V_3 -> V_39 + V_77 ) ;
for ( V_7 = 0 ; V_7 < V_3 -> V_13 ; V_7 ++ ) {
V_22 = & V_3 -> V_22 [ V_7 ] ;
V_86 = V_87 & ( V_22 -> V_72 | V_22 -> V_73 ) ;
if ( V_86 ) {
V_22 -> V_88 = V_87 ;
V_22 -> V_89 = F_27 ( V_22 -> V_67 ) ;
V_22 -> V_90 = F_27 ( V_22 -> V_70 ) ;
if ( ( V_86 & V_22 -> V_73 ) && ! V_22 -> V_91 )
V_22 -> V_91 = F_51 ( V_22 -> V_89 ) ;
V_22 -> V_92 = 1 ;
F_40 ( V_86 , V_3 -> V_39 + V_77 ) ;
F_12 ( & V_22 -> V_75 ) ;
}
}
return V_93 ;
}
bool F_52 ( struct V_1 * V_3 )
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
static int T_4 F_53 ( void )
{
struct V_94 * V_95 = & V_96 ;
int V_8 ;
if ( ! F_54 ( V_97 ) )
return - V_9 ;
switch ( V_95 -> V_98 ) {
case 22 :
if ( ( V_95 -> V_99 < 48 ) || ( V_95 -> V_99 > 63 ) )
return - V_9 ;
V_8 = F_55 () ;
if ( V_8 )
return V_8 ;
if ( ! F_1 () ) {
F_56 () ;
return - V_9 ;
}
return 0 ;
break;
}
return - V_9 ;
}
static void T_5 F_57 ( void )
{
struct V_94 * V_95 = & V_96 ;
switch ( V_95 -> V_98 ) {
case 22 :
F_56 () ;
break;
}
}
