static int T_1
F_1 ( int V_1 , T_2 * V_2 , struct V_3 * V_4 ,
const struct V_5 * V_6 )
{
struct V_7 * V_8 ;
int V_9 ;
V_2 -> V_10 = F_2 ( V_4 , V_6 -> V_11 [ 0 ] . V_6 , NULL ) ;
if ( V_2 -> V_10 == NULL )
return - V_12 ;
if ( V_13 [ V_1 ] ) {
V_2 -> V_14 = F_2 ( V_4 , V_6 -> V_11 [ 2 ] . V_6 , NULL ) ;
if ( V_2 -> V_14 == NULL )
return - V_12 ;
}
V_2 -> V_15 = F_2 ( V_4 , V_6 -> V_11 [ 3 ] . V_6 , NULL ) ;
if ( V_2 -> V_15 == NULL )
return - V_12 ;
V_8 = V_2 -> V_10 ;
V_9 = F_3 ( V_8 ) ;
if ( V_9 < 0 ) {
F_4 ( V_16 L_1 ) ;
return V_9 ;
}
V_17 [ V_1 ] = F_5 ( V_8 , 0 ) ;
V_18 [ V_1 ] = F_5 ( V_8 , 1 ) ;
V_19 [ V_1 ] = F_6 ( V_8 , 0 ) ;
V_20 [ V_1 ] = F_6 ( V_8 , 1 ) ;
V_21 [ V_1 ] = F_7 ( V_8 , 0 ) ;
V_8 = V_2 -> V_15 ;
V_9 = F_3 ( V_8 ) ;
if ( V_9 < 0 ) {
F_4 ( V_16 L_2 ) ;
return V_9 ;
}
V_22 [ V_1 ] = F_5 ( V_8 , 0 ) ;
V_23 [ V_1 ] = F_7 ( V_8 , 0 ) ;
if ( V_13 [ V_1 ] ) {
V_8 = V_2 -> V_14 ;
V_9 = F_3 ( V_8 ) ;
if ( V_9 < 0 ) {
F_4 ( V_16 L_3 ) ;
V_24 [ V_1 ] = V_25 ;
} else {
V_24 [ V_1 ] = F_5 ( V_8 , 0 ) ;
V_26 [ V_1 ] = F_7 ( V_8 , 0 ) ;
}
F_4 ( V_27 L_4 ,
V_24 [ V_1 ] ,
V_26 [ V_1 ] ) ;
}
F_8 ( L_5 ,
V_17 [ V_1 ] ,
V_18 [ V_1 ] ,
V_19 [ V_1 ] ,
V_20 [ V_1 ] ,
V_21 [ V_1 ] ,
V_22 [ V_1 ] ,
V_23 [ V_1 ] ) ;
return 0 ;
}
static T_3 F_9 ( int V_28 , void * V_29 )
{
T_2 * V_2 ;
V_2 = ( T_2 * ) V_29 ;
if ( V_2 == NULL )
return V_30 ;
if ( V_2 -> V_31 . V_32 ) {
F_10 ( V_2 ) ;
} else {
F_11 ( V_2 ) ;
}
return V_33 ;
}
static struct V_34 * T_1
F_12 ( struct V_35 * V_4 ,
int V_36 ,
T_2 * V_2 )
{
struct V_34 * V_37 ;
if ( F_13 ( V_2 ) < 0 ) {
return NULL ;
}
if ( F_14 ( & V_2 -> V_31 ) < 0 ) {
return NULL ;
}
if ( F_15 ( V_4 , L_6 , V_36 , & V_37 ) < 0 )
return NULL ;
strcpy ( V_37 -> V_38 ,
L_7 ) ;
V_37 -> V_39 . V_40 = V_41 ;
V_37 -> V_39 . V_42 = V_43 ;
V_37 -> V_39 . V_44 = V_45 ;
return V_37 ;
}
static struct V_34 * T_1
F_16 ( struct V_35 * V_4 ,
int V_36 ,
T_2 * V_2 ,
unsigned long V_46 )
{
struct V_34 * V_47 ;
if ( F_17 ( & V_2 -> V_31 ) ) {
F_4 ( V_16 L_8 ) ;
return NULL ;
}
if ( F_15 ( V_4 , L_9 , V_36 , & V_47 ) < 0 )
return NULL ;
sprintf ( V_47 -> V_38 , L_10 , V_46 ) ;
V_47 -> V_39 . V_40 = V_48 ;
V_47 -> V_39 . V_42 = V_49 ;
V_47 -> V_39 . V_44 = V_50 ;
return V_47 ;
}
static struct V_51 * T_1
F_18 ( struct V_35 * V_4 ,
int V_52 ,
T_2 * V_2 ,
unsigned long V_46 ,
T_4 V_14 )
{
struct V_51 * V_53 ;
static int V_54 = 1 ;
if ( V_54 ) {
V_54 = 0 ;
V_2 -> V_31 . V_55 . V_56 = V_46 ;
if ( F_19 ( V_2 ) ) {
F_4 ( V_16 L_11 ) ;
return NULL ;
}
}
if ( F_20 ( V_4 , L_12 , V_52 , 1 , 1 , & V_53 ) < 0 )
return NULL ;
if ( V_14 == V_57 ) {
strcpy ( V_53 -> V_38 , L_13 ) ;
V_53 -> V_58 = & V_59 ;
} else {
strcpy ( V_53 -> V_38 , L_14 ) ;
V_53 -> V_58 = & V_60 ;
}
F_21 ( V_53 , V_61 , & V_62 ) ;
F_21 ( V_53 , V_63 , & V_64 ) ;
V_53 -> V_65 |= V_66 |
V_67 |
V_68 ;
return V_53 ;
}
static void
F_22 ( struct V_35 * V_4 )
{
T_2 * V_2 = ( T_2 * ) V_4 -> V_58 ;
if ( V_2 ) {
F_23 ( V_2 -> V_31 . V_69 ) ;
if ( V_2 -> V_31 . V_28 > 0 )
F_24 ( V_2 -> V_31 . V_28 , ( void * ) V_2 ) ;
}
}
static int F_25 ( int V_1 , struct V_35 * * V_70 )
{
struct V_35 * V_4 ;
T_2 * V_2 ;
int V_9 ;
V_9 = F_26 ( V_71 [ V_1 ] , V_6 [ V_1 ] , V_72 ,
sizeof( T_2 ) , & V_4 ) ;
if ( V_9 < 0 )
return V_9 ;
V_2 = V_4 -> V_58 ;
V_2 -> V_31 . V_28 = - 1 ;
F_27 ( & V_2 -> V_31 . V_73 ) ;
F_28 ( & V_2 -> V_31 . V_74 ) ;
F_27 ( & V_2 -> V_31 . V_55 . V_40 ) ;
F_27 ( & V_2 -> V_31 . V_55 . V_75 ) ;
V_2 -> V_31 . V_4 = V_4 ;
V_4 -> V_76 = F_22 ;
* V_70 = V_4 ;
return 0 ;
}
static int T_1
F_29 ( struct V_35 * V_4 , int V_1 )
{
T_2 * V_2 = V_4 -> V_58 ;
struct V_77 * V_78 ;
struct V_34 * V_37 ;
struct V_51 * V_79 = NULL ;
struct V_51 * V_80 = NULL ;
struct V_34 * V_47 ;
int V_36 = 0 , V_52 = 0 , V_9 ;
V_9 = F_30 ( V_4 , V_17 [ V_1 ] , - 1 ,
V_21 [ V_1 ] , V_19 [ V_1 ] , V_20 [ V_1 ] ,
V_81 , 0 , & V_78 ) ;
if ( V_9 < 0 ) {
F_4 ( V_16 L_15 ) ;
return V_9 ;
}
V_9 = F_31 ( V_78 , 0 , NULL ) ;
if ( V_9 < 0 )
return V_9 ;
V_9 = F_32 ( V_78 , 0 , NULL ) ;
if ( V_9 < 0 )
return V_9 ;
if ( V_18 [ V_1 ] > 0 && V_18 [ V_1 ] != V_25 ) {
struct V_82 * V_83 ;
V_9 = F_33 ( V_4 , V_18 [ V_1 ] , V_18 [ V_1 ] + 2 ,
V_84 , 0 , & V_83 ) ;
if ( V_9 < 0 ) {
F_4 ( V_16 L_16 ) ;
return V_9 ;
}
V_9 = F_34 ( V_83 , V_36 , 1 , NULL ) ;
if ( V_9 < 0 )
return V_9 ;
V_36 ++ ;
}
V_2 -> V_31 . V_69 = F_35 ( V_22 [ V_1 ] , 16 ,
L_17 ) ;
if ( V_2 -> V_31 . V_69 == NULL ) {
F_4 ( V_16 L_18 ,
V_22 [ V_1 ] , V_22 [ V_1 ] + 16 - 1 ) ;
return - V_12 ;
}
if ( F_36 ( V_23 [ V_1 ] , F_9 ,
0 , L_17 , V_2 ) ) {
F_4 ( V_16 L_19 , V_23 [ V_1 ] ) ;
return - V_12 ;
}
V_2 -> V_31 . V_28 = V_23 [ V_1 ] ;
V_2 -> V_31 . V_56 = V_22 [ V_1 ] ;
V_37 = F_12 ( V_4 , V_36 , V_2 ) ;
if ( V_37 == NULL ) {
F_4 ( V_16 L_20 ) ;
return - V_85 ;
}
strcpy ( V_37 -> V_38 , L_21 ) ;
V_37 -> V_86 = V_87 ;
V_36 ++ ;
V_9 = F_37 ( V_78 ) ;
if ( V_9 < 0 ) {
F_4 ( V_16 L_22 ) ;
return V_9 ;
}
if ( V_24 [ V_1 ] > 0 && V_24 [ V_1 ] != V_25 ) {
V_9 = F_38 ( V_4 , V_52 , V_88 ,
V_24 [ V_1 ] , 0 ,
V_26 [ V_1 ] , NULL ) ;
if ( V_9 < 0 ) {
F_4 ( V_16 L_23 ) ;
return V_9 ;
}
V_52 ++ ;
}
if ( V_22 [ V_1 ] > 0 && V_22 [ V_1 ] != V_25 ) {
V_79 =
F_18 ( V_4 ,
V_52 ,
V_2 ,
V_22 [ V_1 ] ,
V_57 ) ;
if ( V_79 == NULL ) {
F_4 ( V_16 L_24 ) ;
return - V_85 ;
}
V_52 ++ ;
}
if ( V_22 [ V_1 ] > 0 && V_22 [ V_1 ] != V_25 ) {
V_80 =
F_18 ( V_4 ,
V_52 ,
V_2 ,
V_22 [ V_1 ] ,
V_89 ) ;
if ( V_80 == NULL ) {
F_4 ( V_16 L_25 ) ;
return - V_85 ;
}
V_52 ++ ;
}
if ( V_2 -> V_31 . V_90 ) {
V_47 = F_16 ( V_4 ,
V_36 ,
V_2 ,
V_22 [ V_1 ] ) ;
if ( V_47 == NULL ) {
F_4 ( V_16 L_26 ) ;
return - V_85 ;
}
V_36 ++ ;
strcpy ( V_4 -> V_91 , L_27 ) ;
strcpy ( V_4 -> V_92 , L_28 ) ;
} else {
strcpy ( V_4 -> V_91 , L_6 ) ;
strcpy ( V_4 -> V_92 , L_29 ) ;
}
sprintf ( V_4 -> V_93 , L_30 ,
V_4 -> V_91 ,
V_78 -> V_46 ,
V_21 [ V_1 ] ,
V_19 [ V_1 ] ) ;
if ( V_20 [ V_1 ] >= 0 && V_20 [ V_1 ] < 8 )
sprintf ( V_4 -> V_93 + strlen ( V_4 -> V_93 ) , L_31 , V_20 [ V_1 ] ) ;
if ( V_24 [ V_1 ] > 0 && V_24 [ V_1 ] != V_25 ) {
sprintf ( V_4 -> V_93 + strlen ( V_4 -> V_93 ) ,
L_32 ,
V_24 [ V_1 ] ,
V_26 [ V_1 ] ) ;
}
sprintf ( V_4 -> V_93 + strlen ( V_4 -> V_93 ) ,
L_33 ,
V_22 [ V_1 ] ,
V_23 [ V_1 ] ) ;
return F_39 ( V_4 ) ;
}
static int T_1 F_40 ( struct V_94 * V_8 ,
unsigned int V_1 )
{
if ( ! V_95 [ V_1 ] )
return 0 ;
#ifdef F_41
if ( V_96 [ V_1 ] )
return 0 ;
#endif
if ( V_17 [ V_1 ] == V_25 ) {
F_4 ( V_16 L_34 ) ;
return 0 ;
}
if ( V_22 [ V_1 ] == V_25 ) {
F_4 ( V_16 L_35 ) ;
return 0 ;
}
return 1 ;
}
static int T_1 F_42 ( struct V_94 * V_8 ,
unsigned int V_1 )
{
struct V_35 * V_4 ;
int V_9 ;
V_9 = F_25 ( V_1 , & V_4 ) ;
if ( V_9 < 0 )
return V_9 ;
F_43 ( V_4 , V_8 ) ;
if ( ( V_9 = F_29 ( V_4 , V_1 ) ) < 0 ) {
F_44 ( V_4 ) ;
return V_9 ;
}
F_45 ( V_8 , V_4 ) ;
return 0 ;
}
static int T_5 F_46 ( struct V_94 * V_97 ,
unsigned int V_1 )
{
F_44 ( F_47 ( V_97 ) ) ;
F_45 ( V_97 , NULL ) ;
return 0 ;
}
static int T_1 F_48 ( struct V_3 * V_98 ,
const struct V_5 * V_99 )
{
static int V_1 ;
struct V_35 * V_4 ;
int V_100 ;
for ( ; V_1 < V_101 ; V_1 ++ ) {
if ( V_95 [ V_1 ] && V_96 [ V_1 ] )
break;
}
if ( V_1 >= V_101 )
return - V_102 ;
V_100 = F_25 ( V_1 , & V_4 ) ;
if ( V_100 < 0 )
return V_100 ;
if ( F_1 ( V_1 , V_4 -> V_58 , V_98 , V_99 ) < 0 ) {
if ( V_17 [ V_1 ] == V_25 ) {
F_4 ( V_16 L_36 ) ;
F_44 ( V_4 ) ;
return - V_102 ;
}
}
F_43 ( V_4 , & V_98 -> V_4 -> V_1 ) ;
if ( ( V_100 = F_29 ( V_4 , V_1 ) ) < 0 )
return V_100 ;
F_49 ( V_98 , V_4 ) ;
V_1 ++ ;
return 0 ;
}
static void T_5 F_50 ( struct V_3 * V_98 )
{
F_44 ( F_51 ( V_98 ) ) ;
F_49 ( V_98 , NULL ) ;
}
static int T_6 F_52 ( void )
{
int V_9 ;
V_9 = F_53 ( & V_103 , V_101 ) ;
#ifdef F_41
if ( ! V_9 )
V_104 = 1 ;
V_9 = F_54 ( & V_105 ) ;
if ( ! V_9 )
V_106 = 1 ;
if ( V_104 )
V_9 = 0 ;
#endif
return V_9 ;
}
static void T_7 F_55 ( void )
{
#ifdef F_41
if ( V_106 )
F_56 ( & V_105 ) ;
if ( V_104 )
#endif
F_57 ( & V_103 ) ;
}
