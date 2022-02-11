static struct V_1 * F_1 ( struct V_2 * V_2 )
{
return F_2 ( V_2 , V_3 ) ;
}
static void F_3 ( struct V_1 * V_4 , unsigned int V_5 )
{
T_1 * V_6 = & V_4 -> V_7 [ V_5 ] ;
F_4 ( & V_6 -> V_8 ) ;
if ( ! V_6 -> V_9 )
return;
if ( V_6 -> V_10 > 1 )
V_6 -> V_11 -> V_12 = V_13 ;
F_5 ( V_6 -> V_9 ) . V_14 = V_5 + 1 ;
F_6 ( V_4 -> V_15 , V_6 -> V_9 , 0 , V_5 + 1 , V_16 ) ;
V_6 -> V_10 = 0 ;
V_6 -> V_9 = NULL ;
}
static void F_7 ( unsigned long V_17 )
{
struct V_1 * V_4 = F_8 ( ( void * ) V_17 ,
struct V_1 ,
V_5 [ * ( unsigned int * ) V_17 ] ) ;
T_1 * V_6 = & V_4 -> V_7 [ * ( unsigned int * ) V_17 ] ;
F_9 ( & V_6 -> V_18 ) ;
if ( V_6 -> V_9 )
F_3 ( V_4 , * ( unsigned int * ) V_17 ) ;
F_10 ( & V_6 -> V_18 ) ;
}
static struct V_19 * F_11 ( unsigned int V_20 )
{
struct V_19 * V_9 ;
unsigned int V_21 ;
V_21 = F_12 ( V_20 , V_22 ) ;
V_9 = F_13 ( V_21 , V_16 | V_23 ) ;
if ( ! V_9 ) {
if ( V_21 > V_20 ) {
V_9 = F_13 ( V_20 , V_16 ) ;
if ( ! V_9 )
F_14 ( L_1 ,
V_20 ) ;
}
}
return V_9 ;
}
static void F_15 ( struct V_2 * V_2 , unsigned int V_24 ,
const struct V_19 * V_9 ,
const struct V_25 * V_26 ,
const struct V_25 * V_27 ,
const struct V_28 * V_29 ,
const char * V_30 )
{
T_2 * V_31 ;
T_3 V_20 , V_32 ;
struct V_33 * V_34 ;
struct V_1 * V_4 = F_1 ( V_2 ) ;
unsigned int V_35 = V_29 -> V_5 ;
T_1 * V_6 = & V_4 -> V_7 [ V_35 ] ;
T_4 * V_18 = & V_6 -> V_18 ;
T_5 V_36 ;
if ( ( V_29 -> V_37 == 0 ) ||
( V_29 -> V_37 > V_9 -> V_38 + V_39 ) )
V_32 = V_9 -> V_38 + V_39 ;
else
V_32 = V_29 -> V_37 ;
V_20 = F_16 ( sizeof( * V_31 ) + V_32 ) ;
if ( V_20 > V_22 ) {
F_14 ( L_2 , V_20 , V_22 ) ;
return;
}
F_9 ( V_18 ) ;
if ( ! V_6 -> V_9 ) {
if ( ! ( V_6 -> V_9 = F_11 ( V_20 ) ) )
goto V_40;
} else if ( V_20 > F_17 ( V_6 -> V_9 ) ) {
F_3 ( V_4 , V_35 ) ;
if ( ! ( V_6 -> V_9 = F_11 ( V_20 ) ) )
goto V_40;
}
V_34 = F_18 ( V_6 -> V_9 , 0 , V_6 -> V_10 , 0 ,
V_20 - F_19 ( sizeof( * V_34 ) ) , 0 ) ;
if ( ! V_34 ) {
F_20 ( V_6 -> V_9 ) ;
V_6 -> V_9 = NULL ;
goto V_40;
}
V_6 -> V_10 ++ ;
V_31 = F_21 ( V_34 ) ;
memset ( V_31 , 0 , sizeof( * V_31 ) ) ;
V_31 -> V_41 = V_42 ;
V_36 = F_22 () ;
V_31 -> V_43 = F_23 ( V_36 ) ;
if ( V_6 -> V_10 == 1 )
V_6 -> V_9 -> V_44 = V_36 ;
V_31 -> V_45 = V_32 ;
V_31 -> V_46 = V_9 -> V_46 ;
V_31 -> V_47 = V_24 ;
if ( V_29 -> V_30 != NULL )
strcpy ( V_31 -> V_30 , V_29 -> V_30 ) ;
if ( V_26 ) {
strcpy ( V_31 -> V_48 , V_26 -> V_49 ) ;
if ( F_24 ( V_26 ) )
strcpy ( V_31 -> V_50 , F_25 ( V_26 ) -> V_51 -> V_52 -> V_49 ) ;
else
strcpy ( V_31 -> V_50 , V_26 -> V_49 ) ;
}
if ( V_27 ) {
strcpy ( V_31 -> V_53 , V_27 -> V_49 ) ;
strcpy ( V_31 -> V_54 , F_25 ( V_27 ) -> V_51 -> V_52 -> V_49 ) ;
}
if ( F_26 ( V_9 , - V_39 , V_31 -> V_17 , V_32 ) < 0 )
F_27 () ;
if ( V_6 -> V_10 > 1 )
V_6 -> V_11 -> V_55 |= V_56 ;
V_6 -> V_11 = V_34 ;
if ( V_6 -> V_10 >= V_29 -> V_57 )
F_3 ( V_4 , V_35 ) ;
else if ( ! F_28 ( & V_6 -> V_8 ) ) {
V_6 -> V_8 . V_58 = V_59 + V_60 * V_61 / 100 ;
F_29 ( & V_6 -> V_8 ) ;
}
V_40:
F_10 ( V_18 ) ;
}
static void F_30 ( struct V_2 * V_2 , T_6 V_62 , unsigned int V_63 ,
const struct V_19 * V_9 , const struct V_25 * V_26 ,
const struct V_25 * V_27 , const struct V_64 * V_65 ,
const char * V_30 )
{
struct V_28 V_66 ;
if ( ! V_65 || V_65 -> type != V_67 ) {
V_66 . V_5 = V_68 ;
V_66 . V_37 = 0 ;
V_66 . V_57 = V_69 ;
V_66 . V_30 [ 0 ] = '\0' ;
} else {
V_66 . V_5 = V_65 -> V_70 . V_71 . V_35 ;
V_66 . V_37 = V_65 -> V_70 . V_71 . V_32 ;
V_66 . V_57 = V_65 -> V_70 . V_71 . V_57 ;
F_31 ( V_66 . V_30 , V_30 , sizeof( V_66 . V_30 ) ) ;
}
F_15 ( V_2 , V_63 , V_9 , V_26 , V_27 , & V_66 , V_30 ) ;
}
static unsigned int
F_32 ( struct V_19 * V_9 , const struct V_72 * V_73 )
{
struct V_2 * V_2 = F_33 ( V_73 -> V_26 ? V_73 -> V_26 : V_73 -> V_27 ) ;
F_15 ( V_2 , V_73 -> V_63 , V_9 , V_73 -> V_26 , V_73 -> V_27 ,
V_73 -> V_74 , NULL ) ;
return V_75 ;
}
static int F_34 ( const struct V_76 * V_73 )
{
struct V_28 * V_29 = V_73 -> V_74 ;
if ( ! V_73 -> V_2 -> V_77 . V_78 ) {
F_35 ( L_3
L_4 ) ;
V_73 -> V_2 -> V_77 . V_78 = true ;
}
if ( V_29 -> V_5 > 31 )
return - V_79 ;
V_29 -> V_30 [ V_80 - 1 ] = '\0' ;
if ( V_29 -> V_57 > V_81 )
V_29 -> V_57 = V_81 ;
return 0 ;
}
static int T_7 F_36 ( struct V_2 * V_2 )
{
int V_82 ;
struct V_1 * V_4 = F_1 ( V_2 ) ;
struct V_83 V_84 = {
. V_85 = V_86 ,
} ;
for ( V_82 = 0 ; V_82 < V_86 ; V_82 ++ ) {
V_4 -> V_5 [ V_82 ] = V_82 ;
F_37 ( & V_4 -> V_7 [ V_82 ] . V_8 , F_7 ,
( unsigned long ) & V_4 -> V_5 [ V_82 ] ) ;
F_38 ( & V_4 -> V_7 [ V_82 ] . V_18 ) ;
}
V_4 -> V_15 = F_39 ( V_2 , V_87 , & V_84 ) ;
if ( ! V_4 -> V_15 )
return - V_88 ;
F_40 ( V_2 , V_89 , & V_90 ) ;
return 0 ;
}
static void T_8 F_41 ( struct V_2 * V_2 )
{
int V_82 ;
struct V_1 * V_4 = F_1 ( V_2 ) ;
F_42 ( V_2 , & V_90 ) ;
for ( V_82 = 0 ; V_82 < V_86 ; V_82 ++ ) {
T_1 * V_6 = & V_4 -> V_7 [ V_82 ] ;
F_4 ( & V_6 -> V_8 ) ;
if ( V_6 -> V_9 ) {
F_20 ( V_6 -> V_9 ) ;
V_6 -> V_9 = NULL ;
}
}
F_43 ( V_4 -> V_15 ) ;
}
static int T_9 F_44 ( void )
{
int V_91 ;
if ( V_22 >= 128 * 1024 ) {
F_45 ( L_5
L_6 ) ;
return - V_79 ;
}
V_91 = F_46 ( & V_92 ) ;
if ( V_91 )
goto V_93;
V_91 = F_47 ( & V_94 ) ;
if ( V_91 )
goto V_95;
F_48 ( V_89 , & V_90 ) ;
return 0 ;
V_95:
F_49 ( & V_92 ) ;
V_93:
return V_91 ;
}
static void T_10 F_50 ( void )
{
F_51 ( & V_90 ) ;
F_52 ( & V_94 ) ;
F_49 ( & V_92 ) ;
}
