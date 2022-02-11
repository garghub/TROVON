static int F_1 ( void * V_1 )
{
long V_2 = ( long ) V_1 ;
static unsigned V_3 ;
static const unsigned V_4 = 100 ;
V_5 -> V_6 |= V_7 ;
while ( ! F_2 () ) {
int V_8 ;
int V_9 ;
T_1 V_10 ;
F_3 ( & V_11 ) ;
V_8 = F_4 ( V_12 , & V_10 ,
V_13 ) ;
if ( V_8 ) {
F_5 ( L_1 ,
V_8 ) ;
if ( ++ V_3 >= V_4 ) {
F_6 ( V_14 L_2
L_3 ,
V_15 ) ;
break;
}
F_7 ( & V_11 ) ;
continue;
}
F_8 () ;
for ( V_9 = V_16 ;
V_10 ;
V_10 >>= 1 , V_9 ++ ) {
if ( V_10 & 0x1 )
F_9 ( V_9 ) ;
}
F_10 () ;
F_11 ( V_2 ) ;
}
return 0 ;
}
static T_2 F_12 ( int V_2 , void * V_17 )
{
F_13 ( V_2 ) ;
F_7 ( V_17 ) ;
return V_18 ;
}
static int F_14 ( unsigned line )
{
const struct V_19 * V_19 ;
T_1 V_20 [ 4 ] ;
int V_21 ;
int V_22 ;
if ( line > 1 )
return - V_23 ;
V_24 = line ;
memset ( V_20 , 0xff , sizeof V_20 ) ;
V_19 = V_25 ;
for ( V_21 = 0 ; V_21 < V_26 ; V_21 ++ , V_19 ++ ) {
if ( ! V_19 -> V_27 )
continue;
if ( V_19 -> V_28 <= line )
continue;
V_22 = F_15 ( V_19 -> V_29 , V_20 ,
V_19 -> V_30 [ line ] . V_31 , V_19 -> V_27 ) ;
if ( V_22 < 0 )
F_16 ( L_4 ,
V_22 , V_19 -> V_32 , L_5 ) ;
if ( V_19 -> V_33 ) {
V_22 = F_17 ( V_19 -> V_29 ,
V_34 ,
V_19 -> V_35 ) ;
if ( V_22 < 0 )
F_16 ( L_4 ,
V_22 , V_19 -> V_32 , L_6 ) ;
}
}
V_19 = V_25 ;
for ( V_21 = 0 ; V_21 < V_26 ; V_21 ++ , V_19 ++ ) {
T_1 V_36 [ 4 ] ;
int V_37 ;
if ( ! V_19 -> V_27 )
continue;
if ( V_19 -> V_28 <= line )
continue;
for ( V_37 = 0 ; V_37 < 2 ; V_37 ++ ) {
V_22 = F_18 ( V_19 -> V_29 , V_36 ,
V_19 -> V_30 [ line ] . V_38 , V_19 -> V_27 ) ;
if ( V_22 < 0 )
F_16 ( L_4 ,
V_22 , V_19 -> V_32 , L_7 ) ;
if ( ! V_19 -> V_33 )
V_22 = F_15 ( V_19 -> V_29 , V_20 ,
V_19 -> V_30 [ line ] . V_38 ,
V_19 -> V_27 ) ;
}
}
return 0 ;
}
static inline void F_19 ( int V_2 )
{
#ifdef F_20
F_21 ( V_2 , V_39 ) ;
#else
F_22 ( V_2 ) ;
#endif
}
static void F_23 ( struct V_40 * V_41 )
{
struct V_42 * V_43 ;
const struct V_19 * V_19 ;
union {
T_1 V_44 [ 4 ] ;
T_3 V_45 ;
} V_46 ;
int V_22 ;
V_43 = F_24 ( V_41 , struct V_42 , V_47 ) ;
F_25 ( & V_48 ) ;
if ( V_43 -> V_49 ) {
V_19 = V_43 -> V_19 ;
V_46 . V_45 = F_26 ( V_43 -> V_46 << 8 ) ;
V_43 -> V_49 = false ;
} else
V_19 = NULL ;
F_27 ( & V_48 ) ;
if ( ! V_19 )
return;
V_22 = F_15 ( V_19 -> V_29 , V_46 . V_44 ,
V_19 -> V_30 [ V_24 ] . V_31 , V_19 -> V_27 ) ;
if ( V_22 )
F_16 ( L_8 , V_15 ,
L_9 , V_22 ) ;
}
static void F_28 ( struct V_40 * V_41 )
{
struct V_42 * V_43 ;
const struct V_19 * V_19 ;
T_1 V_44 [ 6 ] ;
T_3 V_50 ;
int V_22 ;
V_43 = F_24 ( V_41 , struct V_42 , V_51 ) ;
F_25 ( & V_48 ) ;
V_50 = V_43 -> V_50 ;
V_43 -> V_50 = 0 ;
V_19 = V_50 ? V_43 -> V_19 : NULL ;
F_27 ( & V_48 ) ;
if ( ! V_19 )
return;
V_22 = F_18 ( V_19 -> V_29 , V_44 + 1 ,
V_19 -> V_52 , V_19 -> V_53 ) ;
if ( V_22 ) {
F_16 ( L_8 , V_15 ,
L_10 , V_22 ) ;
return;
}
while ( V_50 ) {
int V_21 = F_29 ( V_50 ) - 1 ;
struct V_54 * V_55 = F_30 ( V_21 + V_43 -> V_56 ) ;
int V_57 = 1 + ( V_21 >> 2 ) ;
int V_58 = ( V_21 & 0x3 ) * 2 ;
unsigned int type ;
V_44 [ V_57 ] &= ~ ( 0x03 << V_58 ) ;
type = F_31 ( V_55 ) ;
if ( type & V_59 )
V_44 [ V_57 ] |= F_32 ( V_58 + 1 ) ;
if ( type & V_60 )
V_44 [ V_57 ] |= F_32 ( V_58 + 0 ) ;
V_50 &= ~ F_32 ( V_21 ) ;
}
V_22 = F_15 ( V_19 -> V_29 , V_44 ,
V_19 -> V_52 , V_19 -> V_53 ) ;
if ( V_22 )
F_16 ( L_8 , V_15 ,
L_9 , V_22 ) ;
}
static void F_33 ( struct V_54 * V_1 )
{
struct V_42 * V_19 = F_34 ( V_1 ) ;
unsigned long V_6 ;
F_35 ( & V_48 , V_6 ) ;
V_19 -> V_46 |= F_32 ( V_1 -> V_2 - V_19 -> V_56 ) ;
V_19 -> V_49 = true ;
F_36 ( V_61 , & V_19 -> V_47 ) ;
F_37 ( & V_48 , V_6 ) ;
}
static void F_38 ( struct V_54 * V_1 )
{
struct V_42 * V_19 = F_34 ( V_1 ) ;
unsigned long V_6 ;
F_35 ( & V_48 , V_6 ) ;
V_19 -> V_46 &= ~ F_32 ( V_1 -> V_2 - V_19 -> V_56 ) ;
V_19 -> V_49 = true ;
F_36 ( V_61 , & V_19 -> V_47 ) ;
F_37 ( & V_48 , V_6 ) ;
}
static int F_39 ( struct V_54 * V_1 , unsigned V_62 )
{
struct V_42 * V_19 = F_34 ( V_1 ) ;
unsigned long V_6 ;
if ( V_62 & ~ ( V_60 | V_59 ) )
return - V_23 ;
F_35 ( & V_48 , V_6 ) ;
if ( F_31 ( V_1 ) != V_62 ) {
V_19 -> V_50 |= F_32 ( V_1 -> V_2 - V_19 -> V_56 ) ;
F_36 ( V_61 , & V_19 -> V_51 ) ;
}
F_37 ( & V_48 , V_6 ) ;
return 0 ;
}
static inline int F_40 ( const struct V_19 * V_19 )
{
int V_22 ;
union {
T_1 V_44 [ 4 ] ;
T_3 V_45 ;
} V_63 ;
V_63 . V_45 = 0 ;
V_22 = F_18 ( V_19 -> V_29 , V_63 . V_44 ,
V_19 -> V_30 [ V_24 ] . V_38 , V_19 -> V_27 ) ;
return ( V_22 < 0 ) ? V_22 : F_41 ( V_63 . V_45 ) ;
}
static void F_42 ( unsigned V_2 , struct V_64 * V_65 )
{
struct V_42 * V_43 = F_43 ( V_2 ) ;
const struct V_19 * V_19 = V_43 -> V_19 ;
int V_63 ;
F_10 () ;
V_63 = F_40 ( V_19 ) ;
F_8 () ;
if ( V_63 < 0 ) {
F_16 ( L_11 ,
V_19 -> V_32 , V_63 ) ;
return;
}
while ( V_63 ) {
V_2 = F_29 ( V_63 ) ;
V_2 -- ;
V_63 &= ~ F_32 ( V_2 ) ;
if ( V_2 < V_19 -> V_66 )
F_9 ( V_43 -> V_56 + V_2 ) ;
else
F_16 ( L_12 ,
V_19 -> V_32 , V_2 ) ;
}
}
int F_44 ( int V_29 )
{
int V_67 ;
const struct V_19 * V_19 = NULL ;
struct V_42 * V_43 ;
int V_21 , V_2 ;
int V_22 = - V_23 ;
unsigned V_56 = V_68 ;
for ( V_67 = 0 , V_19 = V_25 ;
V_67 < V_26 ;
V_67 ++ , V_19 ++ ) {
if ( V_19 -> V_29 == V_29 && V_19 -> V_33 ) {
if ( ! F_45 ( ( V_56 + V_19 -> V_66 ) > V_69 ,
L_13 ,
V_56 + V_19 -> V_66 ,
V_19 -> V_32 ) )
V_22 = 0 ;
break;
}
}
if ( V_22 < 0 )
return V_22 ;
V_43 = F_46 ( sizeof *V_43 , V_70 ) ;
if ( ! V_43 )
return - V_71 ;
V_22 = 0 ;
V_43 -> V_56 = V_56 ;
V_43 -> V_19 = V_19 ;
V_43 -> V_46 = ~ 0 ;
F_47 ( & V_43 -> V_47 , F_23 ) ;
F_47 ( & V_43 -> V_51 , F_28 ) ;
for ( V_21 = 0 ; V_21 < V_19 -> V_66 ; V_21 ++ ) {
V_2 = V_56 + V_21 ;
F_48 ( V_2 , & V_72 ,
V_73 ) ;
F_49 ( V_2 , V_43 ) ;
F_19 ( V_2 ) ;
}
V_22 = V_56 ;
V_68 += V_21 ;
V_2 = V_67 + V_16 ;
F_50 ( V_2 , V_43 ) ;
F_51 ( V_2 , F_42 ) ;
F_52 ( L_14 , V_19 -> V_32 ,
V_2 , V_56 , V_68 - 1 ) ;
return V_22 ;
}
int F_53 ( int V_74 , unsigned V_56 , unsigned V_75 )
{
static struct V_76 V_77 ;
int V_22 ;
int V_21 ;
struct V_78 * V_79 ;
V_22 = F_14 ( V_80 ) ;
if ( V_22 < 0 )
return V_22 ;
V_61 = F_54 ( L_15 ) ;
if ( ! V_61 ) {
F_16 ( L_16 ) ;
return - V_81 ;
}
V_16 = V_56 ;
V_77 = V_82 ;
V_77 . V_32 = L_17 ;
V_72 . V_83 = V_82 . V_83 ;
for ( V_21 = V_56 ; V_21 < V_75 ; V_21 ++ ) {
F_48 ( V_21 , & V_77 ,
V_84 ) ;
F_19 ( V_21 ) ;
}
V_68 = V_21 ;
F_52 ( L_14 , L_18 ,
V_74 , V_56 , V_68 - 1 ) ;
V_22 = F_44 ( V_85 ) ;
if ( V_22 < 0 ) {
F_16 ( L_19 , V_22 ) ;
goto V_86;
}
F_55 ( & V_11 ) ;
V_22 = F_56 ( V_74 , F_12 , V_87 ,
L_20 , & V_11 ) ;
if ( V_22 < 0 ) {
F_16 ( L_21 , V_74 , V_22 ) ;
goto V_88;
}
V_79 = F_57 ( F_1 , ( void * ) ( long ) V_74 ,
L_22 ) ;
if ( F_58 ( V_79 ) ) {
F_16 ( L_23 , V_74 ) ;
V_22 = F_59 ( V_79 ) ;
goto V_89;
}
return V_22 ;
V_89:
F_60 ( V_74 , & V_11 ) ;
V_88:
V_86:
for ( V_21 = V_56 ; V_21 < V_75 ; V_21 ++ )
F_48 ( V_21 , NULL , NULL ) ;
F_61 ( V_61 ) ;
V_61 = NULL ;
return V_22 ;
}
int F_62 ( void )
{
if ( V_16 ) {
F_16 ( L_24 ) ;
return - V_90 ;
}
return 0 ;
}
int F_63 ( const char * V_91 )
{
if ( ! strcmp ( V_91 , L_25 ) ) {
V_25 = V_92 ;
V_26 = F_64 ( V_92 ) ;
} else {
V_25 = V_93 ;
V_26 = F_64 ( V_93 ) ;
}
return 0 ;
}
