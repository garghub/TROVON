static int F_1 ( void )
{
struct V_1 * V_2 ;
int V_3 , V_4 , V_5 , V_6 , V_7 = 0 ;
const T_1 * V_8 , * V_9 ;
T_2 V_10 , V_11 ;
V_2 = F_2 ( L_1 ) ;
if ( ! V_2 ) {
F_3 ( L_2 ) ;
return - V_12 ;
}
if ( F_4 ( V_2 , L_3 , & V_4 ) ) {
F_3 ( L_4 ) ;
return - V_12 ;
}
if ( F_4 ( V_2 , L_5 , & V_5 ) ) {
F_3 ( L_6 ) ;
return - V_12 ;
}
if ( F_4 ( V_2 , L_7 ,
& V_6 ) ) {
F_3 ( L_8 ) ;
return - V_12 ;
}
F_5 ( L_9 , V_4 ,
V_6 , V_5 ) ;
V_8 = F_6 ( V_2 , L_10 , & V_10 ) ;
if ( ! V_8 ) {
F_3 ( L_11 ) ;
return - V_12 ;
}
V_9 = F_6 ( V_2 , L_12 ,
& V_11 ) ;
if ( ! V_9 ) {
F_3 ( L_13 ) ;
return - V_12 ;
}
if ( V_10 != V_11 ) {
F_3 ( L_14
L_15 ) ;
}
V_7 = F_7 ( V_10 , V_11 ) / sizeof( T_2 ) ;
if ( ! V_7 ) {
F_3 ( L_16 ) ;
return - V_12 ;
}
F_8 ( L_17 , V_7 ) ;
for ( V_3 = 0 ; V_3 < V_7 ; V_3 ++ ) {
T_2 V_13 = F_9 ( V_8 [ V_3 ] ) ;
T_2 V_14 = F_9 ( V_9 [ V_3 ] ) ;
F_8 ( L_18 , V_13 , V_14 ) ;
V_15 [ V_3 ] . V_16 = V_14 * 1000 ;
V_15 [ V_3 ] . V_17 = V_13 ;
}
V_15 [ V_3 ] . V_16 = V_18 ;
V_19 . F_7 = V_4 ;
V_19 . V_20 = V_5 ;
V_19 . V_21 = V_6 ;
V_19 . V_7 = V_7 ;
return 0 ;
}
static unsigned int F_10 ( int V_22 )
{
int V_3 ;
V_3 = V_19 . V_20 - V_22 ;
if ( V_3 >= V_19 . V_7 || V_3 < 0 ) {
F_3 ( L_19
L_20 ,
V_22 , V_19 . V_21 ) ;
V_3 = V_19 . V_20 - V_19 . V_21 ;
}
return V_15 [ V_3 ] . V_16 ;
}
static T_3 F_11 ( struct V_23 * V_24 ,
char * V_25 )
{
return sprintf ( V_25 , L_21 ,
F_10 ( V_19 . V_21 ) ) ;
}
static inline unsigned long F_12 ( unsigned long V_26 )
{
switch ( V_26 ) {
case V_27 :
return F_13 ( V_27 ) ;
case V_28 :
return F_13 ( V_28 ) ;
case V_29 :
return F_13 ( V_29 ) ;
}
F_14 () ;
}
static inline void F_15 ( unsigned long V_26 , unsigned long V_30 )
{
switch ( V_26 ) {
case V_27 :
F_16 ( V_27 , V_30 ) ;
return;
case V_28 :
F_16 ( V_28 , V_30 ) ;
return;
}
F_14 () ;
}
static void F_17 ( void * V_31 )
{
unsigned long V_32 ;
T_4 V_33 ;
struct V_34 * V_35 = V_31 ;
V_32 = F_12 ( V_29 ) ;
V_33 = ( V_32 >> 48 ) & 0xFF ;
V_35 -> V_22 = V_33 ;
V_35 -> V_14 = F_10 ( V_35 -> V_22 ) ;
F_8 ( L_22 ,
F_18 () , V_32 , V_35 -> V_22 ,
V_35 -> V_14 ) ;
}
static unsigned int F_19 ( unsigned int V_36 )
{
struct V_34 V_35 ;
F_20 ( F_21 ( V_36 ) , F_17 ,
& V_35 , 1 ) ;
return V_35 . V_14 ;
}
static void F_22 ( void * V_35 )
{
unsigned long V_30 ;
unsigned long V_37 =
( (struct V_34 * ) V_35 ) -> V_22 ;
V_30 = F_12 ( V_27 ) ;
V_30 = V_30 & 0x0000FFFFFFFFFFFFULL ;
V_37 = V_37 & 0xFF ;
V_30 = V_30 | ( V_37 << 56 ) | ( V_37 << 48 ) ;
F_8 ( L_23 ,
F_18 () , V_30 ) ;
F_15 ( V_27 , V_30 ) ;
}
static inline unsigned int F_23 ( void )
{
return V_19 . V_20 - V_19 . V_21 ;
}
static void F_24 ( void * V_38 )
{
struct V_39 * V_39 ;
unsigned int V_36 = F_25 () ;
unsigned long V_40 ;
int V_41 ;
V_40 = F_12 ( V_29 ) ;
V_39 = F_26 ( V_42 ) ;
V_41 = ( T_4 ) F_27 ( V_40 ) ;
if ( V_41 != V_19 . V_20 ) {
if ( V_39 -> V_43 )
goto V_44;
V_39 -> V_43 = true ;
if ( V_41 < V_19 . V_21 ) {
F_28 ( L_24 ,
V_36 , V_39 -> V_13 , V_41 ,
V_19 . V_21 ) ;
V_39 -> V_45 ++ ;
} else {
V_39 -> V_46 ++ ;
}
F_29 ( V_39 -> V_13 ,
V_47 [ V_39 -> V_47 ] ,
V_41 ) ;
} else if ( V_39 -> V_43 ) {
V_39 -> V_43 = false ;
F_29 ( V_39 -> V_13 ,
V_47 [ V_39 -> V_47 ] ,
V_41 ) ;
}
V_44:
if ( V_40 & V_48 ) {
V_43 = true ;
F_5 ( L_25 ) ;
}
if ( V_40 & V_49 ) {
V_43 = true ;
F_5 ( L_26 ) ;
}
if ( V_43 ) {
F_5 ( L_27 , V_40 ) ;
F_3 ( L_28 ) ;
}
}
static int F_30 ( struct V_23 * V_24 ,
unsigned int V_50 )
{
struct V_34 V_35 ;
if ( F_31 ( V_51 ) && V_50 != F_23 () )
return 0 ;
if ( ! V_43 )
F_24 ( NULL ) ;
V_35 . V_22 = V_15 [ V_50 ] . V_17 ;
F_20 ( V_24 -> V_52 , F_22 , & V_35 , 1 ) ;
return 0 ;
}
static int F_32 ( struct V_23 * V_24 )
{
int V_53 , V_3 ;
V_53 = F_33 ( V_24 -> V_36 ) ;
for ( V_3 = 0 ; V_3 < V_54 ; V_3 ++ )
F_34 ( V_53 + V_3 , V_24 -> V_52 ) ;
if ( ! V_24 -> V_17 ) {
int V_55 ;
V_55 = F_35 ( & V_24 -> V_56 , & V_57 ) ;
if ( V_55 ) {
F_5 ( L_29 ,
V_24 -> V_36 ) ;
return V_55 ;
}
V_24 -> V_17 = V_24 ;
}
return F_36 ( V_24 , V_15 ) ;
}
static int F_37 ( struct V_58 * V_59 ,
unsigned long V_60 , void * V_61 )
{
int V_36 ;
struct V_23 V_62 ;
V_51 = true ;
F_38 (cpu) {
F_39 ( & V_62 , V_36 ) ;
F_30 ( & V_62 , F_23 () ) ;
}
return V_63 ;
}
void F_40 ( struct V_64 * V_65 )
{
struct V_39 * V_39 = F_41 ( V_65 , struct V_39 , V_66 ) ;
unsigned int V_36 ;
T_5 V_67 ;
F_42 () ;
F_43 ( & V_67 , & V_39 -> V_67 , V_68 ) ;
F_20 ( & V_67 ,
F_24 , NULL , 0 ) ;
if ( ! V_39 -> V_69 )
goto V_70;
V_39 -> V_69 = false ;
F_44 (cpu, &mask) {
int V_71 ;
struct V_23 V_24 ;
F_39 ( & V_24 , V_36 ) ;
F_45 ( & V_24 , V_24 . V_72 ,
V_24 . V_73 ,
V_74 , & V_71 ) ;
F_30 ( & V_24 , V_71 ) ;
F_46 ( & V_67 , & V_67 , V_24 . V_52 ) ;
}
V_70:
F_47 () ;
}
static int F_48 ( struct V_58 * V_59 ,
unsigned long V_75 , void * V_76 )
{
struct V_77 * V_78 = V_76 ;
struct V_79 V_80 ;
int V_3 ;
if ( V_75 != V_81 )
return 0 ;
V_80 . type = F_49 ( V_78 -> V_82 [ 0 ] ) ;
switch ( V_80 . type ) {
case V_83 :
V_84 = true ;
F_5 ( L_30 ) ;
if ( ! V_43 ) {
V_43 = true ;
F_3 ( L_31 ) ;
}
break;
case V_85 :
F_5 ( L_32 ) ;
break;
case V_86 :
V_80 . V_39 = F_49 ( V_78 -> V_82 [ 1 ] ) ;
V_80 . V_87 = F_49 ( V_78 -> V_82 [ 2 ] ) ;
if ( V_84 ) {
V_84 = false ;
V_43 = false ;
F_5 ( L_33 ) ;
for ( V_3 = 0 ; V_3 < V_88 ; V_3 ++ ) {
V_89 [ V_3 ] . V_69 = true ;
F_50 ( & V_89 [ V_3 ] . V_66 ) ;
}
return 0 ;
}
for ( V_3 = 0 ; V_3 < V_88 ; V_3 ++ )
if ( V_89 [ V_3 ] . V_13 == V_80 . V_39 )
break;
if ( V_80 . V_87 >= 0 &&
V_80 . V_87 <= V_90 ) {
V_89 [ V_3 ] . V_47 = V_80 . V_87 ;
V_89 [ V_3 ] . V_91 [ V_80 . V_87 ] ++ ;
}
if ( ! V_80 . V_87 )
V_89 [ V_3 ] . V_69 = true ;
F_50 ( & V_89 [ V_3 ] . V_66 ) ;
}
return 0 ;
}
static void F_51 ( struct V_23 * V_24 )
{
struct V_34 V_35 ;
V_35 . V_22 = V_19 . F_7 ;
F_52 ( V_24 -> V_36 , F_22 , & V_35 , 1 ) ;
}
static int F_53 ( void )
{
unsigned int V_39 [ 256 ] ;
unsigned int V_36 , V_3 ;
unsigned int V_92 = V_93 ;
F_54 (cpu) {
unsigned int V_13 = F_55 ( V_36 ) ;
if ( V_92 != V_13 ) {
V_92 = V_13 ;
V_39 [ V_88 ++ ] = V_13 ;
}
}
V_89 = F_56 ( V_88 , sizeof( struct V_39 ) , V_94 ) ;
if ( ! V_89 )
return - V_95 ;
for ( V_3 = 0 ; V_3 < V_88 ; V_3 ++ ) {
V_89 [ V_3 ] . V_13 = V_39 [ V_3 ] ;
F_57 ( & V_89 [ V_3 ] . V_67 , F_58 ( V_39 [ V_3 ] ) ) ;
F_59 ( & V_89 [ V_3 ] . V_66 , F_40 ) ;
F_44 (cpu, &chips[i].mask)
F_60 ( V_42 , V_36 ) = & V_89 [ V_3 ] ;
}
return 0 ;
}
static inline void F_61 ( void )
{
F_62 ( V_89 ) ;
}
static inline void F_63 ( void )
{
F_64 ( V_81 ,
& V_96 ) ;
F_65 ( & V_97 ) ;
}
static int T_6 F_66 ( void )
{
int V_98 = 0 ;
if ( ! F_67 ( V_99 ) )
return - V_12 ;
V_98 = F_1 () ;
if ( V_98 )
goto V_70;
V_98 = F_53 () ;
if ( V_98 )
goto V_70;
F_68 ( & V_97 ) ;
F_69 ( V_81 , & V_96 ) ;
V_98 = F_70 ( & V_100 ) ;
if ( ! V_98 )
return 0 ;
F_5 ( L_34 , V_98 ) ;
F_63 () ;
F_61 () ;
V_70:
F_5 ( L_35 ) ;
return V_98 ;
}
static void T_7 F_71 ( void )
{
F_72 ( & V_100 ) ;
F_63 () ;
F_61 () ;
}
