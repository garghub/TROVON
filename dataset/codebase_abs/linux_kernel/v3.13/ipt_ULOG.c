static struct V_1 * F_1 ( struct V_2 * V_2 )
{
return F_2 ( V_2 , V_3 ) ;
}
static void F_3 ( struct V_1 * V_4 , unsigned int V_5 )
{
T_1 * V_6 = & V_4 -> V_7 [ V_5 ] ;
F_4 ( L_1 ) ;
F_5 ( & V_6 -> V_8 ) ;
if ( ! V_6 -> V_9 ) {
F_4 ( L_2 ) ;
return;
}
if ( V_6 -> V_10 > 1 )
V_6 -> V_11 -> V_12 = V_13 ;
F_6 ( V_6 -> V_9 ) . V_14 = V_5 + 1 ;
F_4 ( L_3 ,
V_6 -> V_10 , V_5 + 1 ) ;
F_7 ( V_4 -> V_15 , V_6 -> V_9 , 0 , V_5 + 1 ,
V_16 ) ;
V_6 -> V_10 = 0 ;
V_6 -> V_9 = NULL ;
V_6 -> V_11 = NULL ;
}
static void F_8 ( unsigned long V_17 )
{
unsigned int V_18 = * ( ( unsigned int * ) V_17 ) ;
struct V_1 * V_4 = F_9 ( ( void * ) V_17 ,
struct V_1 ,
V_19 [ V_18 ] ) ;
F_4 ( L_4 ) ;
F_10 ( & V_4 -> V_20 ) ;
F_3 ( V_4 , V_18 ) ;
F_11 ( & V_4 -> V_20 ) ;
}
static struct V_21 * F_12 ( unsigned int V_22 )
{
struct V_21 * V_9 ;
unsigned int V_23 ;
V_23 = F_13 ( V_22 , V_24 ) ;
V_9 = F_14 ( V_23 , V_16 | V_25 ) ;
if ( ! V_9 ) {
if ( V_23 > V_22 ) {
V_9 = F_14 ( V_22 , V_16 ) ;
if ( ! V_9 )
F_4 ( L_5 , V_22 ) ;
}
}
return V_9 ;
}
static void F_15 ( struct V_2 * V_2 ,
unsigned int V_26 ,
const struct V_21 * V_9 ,
const struct V_27 * V_28 ,
const struct V_27 * V_29 ,
const struct V_30 * V_31 ,
const char * V_32 )
{
T_1 * V_6 ;
T_2 * V_33 ;
T_3 V_22 , V_34 ;
struct V_35 * V_36 ;
struct V_37 V_38 ;
struct V_1 * V_4 = F_1 ( V_2 ) ;
unsigned int V_18 = F_16 ( V_31 -> V_39 ) - 1 ;
if ( V_31 -> V_40 == 0 || V_31 -> V_40 > V_9 -> V_41 )
V_34 = V_9 -> V_41 ;
else
V_34 = V_31 -> V_40 ;
V_22 = F_17 ( sizeof( * V_33 ) + V_34 ) ;
V_6 = & V_4 -> V_7 [ V_18 ] ;
F_10 ( & V_4 -> V_20 ) ;
if ( ! V_6 -> V_9 ) {
if ( ! ( V_6 -> V_9 = F_12 ( V_22 ) ) )
goto V_42;
} else if ( V_6 -> V_10 >= V_31 -> V_43 ||
V_22 > F_18 ( V_6 -> V_9 ) ) {
F_3 ( V_4 , V_18 ) ;
if ( ! ( V_6 -> V_9 = F_12 ( V_22 ) ) )
goto V_42;
}
F_4 ( L_6 , V_6 -> V_10 , V_31 -> V_43 ) ;
V_36 = F_19 ( V_6 -> V_9 , 0 , V_6 -> V_10 , V_44 ,
sizeof( * V_33 ) + V_34 , 0 ) ;
if ( ! V_36 ) {
F_4 ( L_7 ) ;
goto V_45;
}
V_6 -> V_10 ++ ;
V_33 = F_20 ( V_36 ) ;
memset ( V_33 , 0 , sizeof( * V_33 ) ) ;
if ( V_9 -> V_46 . V_47 == 0 )
F_21 ( (struct V_21 * ) V_9 ) ;
V_33 -> V_48 = V_34 ;
V_38 = F_22 ( V_9 -> V_46 ) ;
F_23 ( V_38 . V_49 , & V_33 -> V_50 ) ;
F_23 ( V_38 . V_51 , & V_33 -> V_52 ) ;
F_23 ( V_9 -> V_53 , & V_33 -> V_53 ) ;
V_33 -> V_54 = V_26 ;
if ( V_32 != NULL ) {
strncpy ( V_33 -> V_32 , V_32 , sizeof( V_33 -> V_32 ) - 1 ) ;
V_33 -> V_32 [ sizeof( V_33 -> V_32 ) - 1 ] = '\0' ;
}
else if ( V_31 -> V_32 [ 0 ] != '\0' )
strncpy ( V_33 -> V_32 , V_31 -> V_32 , sizeof( V_33 -> V_32 ) ) ;
if ( V_28 && V_28 -> V_55 > 0 &&
V_9 -> V_56 != V_9 -> V_57 &&
V_28 -> V_55 <= V_58 ) {
memcpy ( V_33 -> V_59 , F_24 ( V_9 ) , V_28 -> V_55 ) ;
V_33 -> V_60 = V_28 -> V_55 ;
} else
V_33 -> V_60 = 0 ;
if ( V_28 )
strncpy ( V_33 -> V_61 , V_28 -> V_62 , sizeof( V_33 -> V_61 ) ) ;
if ( V_29 )
strncpy ( V_33 -> V_63 , V_29 -> V_62 , sizeof( V_33 -> V_63 ) ) ;
if ( F_25 ( V_9 , 0 , V_33 -> V_64 , V_34 ) < 0 )
F_26 () ;
if ( V_6 -> V_10 > 1 )
V_6 -> V_11 -> V_65 |= V_66 ;
V_6 -> V_11 = V_36 ;
if ( ! F_27 ( & V_6 -> V_8 ) ) {
V_6 -> V_8 . V_67 = V_68 + V_69 * V_70 / 100 ;
F_28 ( & V_6 -> V_8 ) ;
}
if ( V_6 -> V_10 >= V_31 -> V_43 ) {
if ( V_31 -> V_43 > 1 )
V_36 -> V_12 = V_13 ;
F_3 ( V_4 , V_18 ) ;
}
V_45:
F_11 ( & V_4 -> V_20 ) ;
return;
V_42:
F_4 ( L_8 ) ;
F_11 ( & V_4 -> V_20 ) ;
}
static unsigned int
F_29 ( struct V_21 * V_9 , const struct V_71 * V_72 )
{
struct V_2 * V_2 = F_30 ( V_72 -> V_28 ? V_72 -> V_28 : V_72 -> V_29 ) ;
F_15 ( V_2 , V_72 -> V_26 , V_9 , V_72 -> V_28 , V_72 -> V_29 ,
V_72 -> V_73 , NULL ) ;
return V_74 ;
}
static void F_31 ( struct V_2 * V_2 ,
T_4 V_75 ,
unsigned int V_26 ,
const struct V_21 * V_9 ,
const struct V_27 * V_28 ,
const struct V_27 * V_29 ,
const struct V_76 * V_77 ,
const char * V_32 )
{
struct V_30 V_31 ;
if ( ! V_77 || V_77 -> type != V_78 ) {
V_31 . V_39 = V_79 ;
V_31 . V_40 = 0 ;
V_31 . V_43 = V_80 ;
V_31 . V_32 [ 0 ] = '\0' ;
} else {
V_31 . V_39 = V_77 -> V_81 . V_4 . V_82 ;
V_31 . V_40 = V_77 -> V_81 . V_4 . V_34 ;
V_31 . V_43 = V_77 -> V_81 . V_4 . V_43 ;
F_32 ( V_31 . V_32 , V_32 , sizeof( V_31 . V_32 ) ) ;
}
F_15 ( V_2 , V_26 , V_9 , V_28 , V_29 , & V_31 , V_32 ) ;
}
static int F_33 ( const struct V_83 * V_72 )
{
const struct V_30 * V_31 = V_72 -> V_73 ;
if ( ! V_72 -> V_2 -> V_84 . V_85 ) {
F_34 ( L_9
L_10 ) ;
V_72 -> V_2 -> V_84 . V_85 = true ;
}
if ( V_31 -> V_32 [ sizeof( V_31 -> V_32 ) - 1 ] != '\0' ) {
F_4 ( L_11 ) ;
return - V_86 ;
}
if ( V_31 -> V_43 > V_87 ) {
F_4 ( L_12 ,
V_31 -> V_43 ) ;
return - V_86 ;
}
return 0 ;
}
static void F_35 ( void * V_88 , const void * V_89 )
{
const struct V_90 * V_91 = V_89 ;
struct V_30 V_92 = {
. V_39 = V_91 -> V_39 ,
. V_40 = V_91 -> V_40 ,
. V_43 = V_91 -> V_43 ,
} ;
memcpy ( V_92 . V_32 , V_91 -> V_32 , sizeof( V_92 . V_32 ) ) ;
memcpy ( V_88 , & V_92 , sizeof( V_92 ) ) ;
}
static int F_36 ( void T_5 * V_88 , const void * V_89 )
{
const struct V_30 * V_92 = V_89 ;
struct V_90 V_91 = {
. V_39 = V_92 -> V_39 ,
. V_40 = V_92 -> V_40 ,
. V_43 = V_92 -> V_43 ,
} ;
memcpy ( V_91 . V_32 , V_92 -> V_32 , sizeof( V_91 . V_32 ) ) ;
return F_37 ( V_88 , & V_91 , sizeof( V_91 ) ) ? - V_93 : 0 ;
}
static int T_6 F_38 ( struct V_2 * V_2 )
{
int V_94 ;
struct V_1 * V_4 = F_1 ( V_2 ) ;
struct V_95 V_96 = {
. V_97 = V_98 ,
} ;
F_39 ( & V_4 -> V_20 ) ;
for ( V_94 = 0 ; V_94 < V_98 ; V_94 ++ ) {
V_4 -> V_19 [ V_94 ] = V_94 ;
F_40 ( & V_4 -> V_7 [ V_94 ] . V_8 , F_8 ,
( unsigned long ) & V_4 -> V_19 [ V_94 ] ) ;
}
V_4 -> V_15 = F_41 ( V_2 , V_99 , & V_96 ) ;
if ( ! V_4 -> V_15 )
return - V_100 ;
if ( V_101 )
F_42 ( V_2 , V_102 , & V_103 ) ;
return 0 ;
}
static void T_7 F_43 ( struct V_2 * V_2 )
{
T_1 * V_6 ;
int V_94 ;
struct V_1 * V_4 = F_1 ( V_2 ) ;
if ( V_101 )
F_44 ( V_2 , & V_103 ) ;
F_45 ( V_4 -> V_15 ) ;
for ( V_94 = 0 ; V_94 < V_98 ; V_94 ++ ) {
V_6 = & V_4 -> V_7 [ V_94 ] ;
F_4 ( L_13 ) ;
F_5 ( & V_6 -> V_8 ) ;
if ( V_6 -> V_9 ) {
F_46 ( V_6 -> V_9 ) ;
V_6 -> V_9 = NULL ;
}
}
}
static int T_8 F_47 ( void )
{
int V_104 ;
F_4 ( L_14 ) ;
if ( V_24 > 128 * 1024 ) {
F_48 ( L_15 ) ;
return - V_86 ;
}
V_104 = F_49 ( & V_105 ) ;
if ( V_104 )
goto V_106;
V_104 = F_50 ( & V_107 ) ;
if ( V_104 < 0 )
goto V_108;
if ( V_101 )
F_51 ( V_102 , & V_103 ) ;
return 0 ;
V_108:
F_52 ( & V_105 ) ;
V_106:
return V_104 ;
}
static void T_9 F_53 ( void )
{
F_4 ( L_16 ) ;
if ( V_101 )
F_54 ( & V_103 ) ;
F_55 ( & V_107 ) ;
F_52 ( & V_105 ) ;
}
