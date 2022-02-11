static unsigned int F_1 ( struct V_1 * V_2 , int V_3 )
{
unsigned int V_4 ;
V_3 = V_3 << V_2 -> V_5 ;
if ( V_3 == V_6 ) {
V_4 = F_2 ( V_2 -> V_7 + ( V_6 & ~ 3 ) ) ;
return ( V_4 >> 16 ) & 0xff ;
} else
return F_3 ( V_2 -> V_7 + V_3 ) ;
}
static void F_4 ( struct V_1 * V_2 , int V_3 , int V_8 )
{
V_3 = V_3 << V_2 -> V_5 ;
if ( ! ( ( V_3 == V_9 ) && ( V_8 & V_10 ) ) )
F_5 ( V_8 , V_2 -> V_7 + V_3 ) ;
}
static int T_1 F_6 ( struct V_11 * V_12 , int V_13 ,
int V_14 , T_2 V_15 ,
T_2 V_16 , unsigned long V_17 ,
T_3 V_18 , int V_19 )
{
const T_4 * V_20 , * V_21 , * V_22 ;
T_5 clock = V_23 * 16 ;
T_5 V_24 = 0 ;
int V_25 ;
V_20 = F_7 ( V_12 , L_1 , NULL ) ;
if ( V_20 && * V_20 )
clock = F_8 ( V_20 ) ;
V_21 = F_7 ( V_12 , L_2 , NULL ) ;
V_22 = F_7 ( V_12 , L_3 , NULL ) ;
if ( V_22 && * V_22 )
V_24 = F_8 ( V_22 ) ;
if ( V_13 >= 0 && V_13 < V_26 )
V_25 = V_13 ;
else
V_25 = V_27 ;
if ( V_25 >= V_26 )
return - 1 ;
if ( V_25 >= V_27 )
V_27 = V_25 + 1 ;
if ( V_28 [ V_25 ] . V_12 != NULL ) {
if ( V_27 < V_26 ) {
F_9 ( V_29 L_4 ,
V_25 , V_27 ) ;
V_30 [ V_27 ] =
V_30 [ V_25 ] ;
V_28 [ V_27 ] =
V_28 [ V_25 ] ;
V_27 ++ ;
} else {
F_9 ( V_29 L_5 , V_25 ) ;
}
}
memset ( & V_30 [ V_25 ] , 0 ,
sizeof( struct V_31 ) ) ;
if ( V_14 == V_32 )
V_30 [ V_25 ] . V_33 = V_15 ;
else
V_30 [ V_25 ] . V_34 = V_15 ;
V_30 [ V_25 ] . V_14 = V_14 ;
V_30 [ V_25 ] . V_35 = clock ;
V_30 [ V_25 ] . V_17 = V_17 ;
V_30 [ V_25 ] . V_18 = V_18 ;
V_30 [ V_25 ] . V_5 = V_24 ;
V_28 [ V_25 ] . V_16 = V_16 ;
V_28 [ V_25 ] . V_12 = F_10 ( V_12 ) ;
V_28 [ V_25 ] . clock = clock ;
V_28 [ V_25 ] . V_36 = V_21 ? F_8 ( V_21 ) : 0 ;
V_28 [ V_25 ] . V_19 = V_19 ;
if ( V_14 == V_37 ) {
V_30 [ V_25 ] . V_38 = F_1 ;
V_30 [ V_25 ] . V_39 = F_4 ;
}
F_9 ( V_29 L_6 ,
V_25 , V_12 -> V_40 ) ;
F_9 ( V_29 L_7 ,
( V_14 == V_32 ) ? L_8 : L_9 ,
( unsigned long long ) V_15 , ( unsigned long long ) V_16 , V_17 ,
V_30 [ V_25 ] . V_35 ,
V_28 [ V_25 ] . V_36 ) ;
return V_25 ;
}
static int T_1 F_11 ( struct V_11 * V_12 ,
struct V_11 * V_41 )
{
T_6 V_42 ;
const T_4 * V_43 ;
struct V_11 * V_44 = F_12 ( V_12 ) ;
if ( F_7 ( V_12 , L_1 , NULL ) == NULL )
return - 1 ;
if ( ( F_7 ( V_12 , L_10 , NULL ) != NULL ) )
return - 1 ;
if ( F_7 ( V_12 , L_11 , NULL ) != NULL )
return - 1 ;
V_43 = F_13 ( V_41 , 0 , NULL , NULL ) ;
if ( V_43 == NULL )
return - 1 ;
V_42 = F_14 ( V_41 , V_43 ) ;
if ( V_42 == V_45 )
return - 1 ;
if ( V_44 && ! strcmp ( V_44 -> type , L_12 ) )
return F_6 ( V_12 , - 1 , V_37 , V_42 , V_42 ,
0 , V_46 , 0 ) ;
else
return F_6 ( V_12 , - 1 , V_47 , V_42 , V_42 ,
0 , V_46 , 0 ) ;
}
static int T_1 F_15 ( struct V_11 * V_12 ,
struct V_11 * V_48 )
{
const T_4 * V_49 ;
const char * V_50 ;
int V_25 = - 1 ;
T_6 V_16 ;
F_16 ( L_13 , V_12 -> V_40 ) ;
V_49 = F_7 ( V_12 , L_14 , NULL ) ;
if ( V_49 == NULL )
return - 1 ;
if ( ! ( F_17 ( V_49 [ 0 ] ) & 0x00000001 ) )
return - 1 ;
V_50 = F_7 ( V_12 , L_15 , NULL ) ;
if ( V_50 && * V_50 == 'S' )
V_25 = F_18 ( V_50 + 1 , NULL , 0 ) - 1 ;
if ( ! F_19 ( V_48 , L_16 ) ||
F_7 ( V_48 , L_17 , NULL ) ) {
V_16 = F_14 ( V_12 , V_49 ) ;
if ( V_16 == V_45 )
V_16 = 0 ;
} else
V_16 = 0 ;
return F_6 ( V_12 , V_25 , V_32 , F_17 ( V_49 [ 1 ] ) ,
V_16 , 0 , V_46 , 0 ) ;
}
static int T_1 F_20 ( struct V_11 * V_12 ,
struct V_11 * V_51 )
{
T_6 V_42 , V_15 ;
const T_4 * V_43 ;
unsigned int V_18 ;
int V_14 , V_25 = - 1 , V_52 = 0 ;
F_16 ( L_18 , V_12 -> V_40 ) ;
if ( F_7 ( V_12 , L_1 , NULL ) == NULL )
return - 1 ;
V_43 = F_21 ( V_51 , 0 , NULL , & V_18 ) ;
if ( V_43 == NULL )
return - 1 ;
V_14 = ( V_18 & V_53 ) ? V_47 : V_32 ;
V_42 = F_14 ( V_51 , V_43 ) ;
if ( V_42 == V_45 )
return - 1 ;
if ( V_14 == V_47 )
V_15 = V_42 ;
else
V_15 = F_22 ( & V_43 [ 2 ] , 1 ) ;
if ( V_12 != V_51 ) {
const T_4 * V_49 = F_7 ( V_12 , L_14 , NULL ) ;
if ( V_49 && ( F_8 ( V_49 ) < 4 ) )
V_25 = V_52 = F_8 ( V_49 ) ;
}
if ( F_19 ( V_51 , L_19 ) ||
F_19 ( V_51 , L_20 ) ||
F_19 ( V_51 , L_21 ) ) {
V_42 += 0x200 * V_52 ;
V_15 += 0x200 * V_52 ;
} else {
V_42 += 8 * V_52 ;
V_15 += 8 * V_52 ;
}
return F_6 ( V_12 , V_25 , V_14 , V_15 , V_42 , 0 ,
V_46 , V_12 != V_51 ) ;
}
static void T_1 F_23 ( int V_54 )
{
struct V_55 * V_56 = & V_28 [ V_54 ] ;
struct V_31 * V_57 = & V_30 [ V_54 ] ;
void T_7 * V_42 ;
unsigned int V_58 ;
V_58 = 1 << V_57 -> V_5 ;
if ( V_56 -> V_16 ) {
V_42 = F_24 ( V_56 -> V_16 , 0x1000 ) ;
if ( V_42 == NULL )
return;
F_25 ( V_42 , V_58 ) ;
} else {
if ( V_57 -> V_14 == V_32 && V_59 )
F_26 ( V_57 -> V_33 , V_58 ) ;
else
return;
}
if ( V_56 -> V_36 == 0 )
V_56 -> V_36 = F_27 ( V_56 -> clock ) ;
F_16 ( L_22 , V_56 -> V_36 ) ;
F_28 ( V_56 -> V_36 , V_56 -> clock ) ;
}
void T_1 F_29 ( void )
{
struct V_11 * V_12 , * stdout = NULL ;
const char * V_60 ;
int V_25 ;
F_16 ( L_23 ) ;
V_60 = F_7 ( V_61 , L_24 , NULL ) ;
if ( V_60 != NULL ) {
stdout = F_30 ( V_60 ) ;
if ( stdout )
F_16 ( L_25 , stdout -> V_40 ) ;
} else {
F_16 ( L_26 ) ;
}
F_31 (np, L_27 , L_28 ) {
struct V_11 * V_62 = F_12 ( V_12 ) ;
if ( ! V_62 )
continue;
if ( F_32 ( V_63 , V_62 ) != NULL ) {
if ( F_33 ( V_12 ) ) {
V_25 = F_11 ( V_12 , V_12 ) ;
if ( V_25 >= 0 && V_12 == stdout )
V_64 = V_25 ;
}
}
F_34 ( V_62 ) ;
}
F_35 (np, L_27 ) {
struct V_11 * V_65 = F_12 ( V_12 ) ;
if ( V_65 && ( ! strcmp ( V_65 -> V_66 , L_29 ) ||
! strcmp ( V_65 -> V_66 , L_30 ) ) ) {
if ( F_33 ( V_12 ) ) {
V_25 = F_15 ( V_12 , V_65 ) ;
if ( V_25 >= 0 && V_12 == stdout )
V_64 = V_25 ;
}
}
F_34 ( V_65 ) ;
}
#ifdef F_36
for ( V_12 = NULL ; ( V_12 = F_37 ( V_12 ) ) ; ) {
struct V_11 * V_67 , * V_62 = F_12 ( V_12 ) ;
if ( V_62 && ! strcmp ( V_62 -> V_66 , L_29 ) ) {
F_34 ( V_62 ) ;
continue;
}
if ( strcmp ( V_12 -> V_66 , L_27 ) && strcmp ( V_12 -> type , L_27 ) ) {
F_34 ( V_62 ) ;
continue;
}
if ( F_19 ( V_12 , L_31 ) ||
F_19 ( V_12 , L_32 ) )
V_67 = V_12 ;
else if ( F_19 ( V_62 , L_31 ) ||
F_19 ( V_62 , L_32 ) )
V_67 = V_62 ;
else {
F_34 ( V_62 ) ;
continue;
}
V_25 = F_20 ( V_12 , V_67 ) ;
if ( V_25 >= 0 && V_12 == stdout )
V_64 = V_25 ;
F_34 ( V_62 ) ;
}
#endif
F_16 ( L_33 , V_64 ) ;
if ( V_64 >= 0 )
F_23 ( V_64 ) ;
F_16 ( L_34 ) ;
}
static void T_1 F_38 ( int V_25 ,
struct V_11 * V_12 ,
struct V_31 * V_57 )
{
unsigned int V_68 ;
F_16 ( L_35 , V_25 ) ;
V_68 = F_39 ( V_12 , 0 ) ;
if ( ! V_68 && V_28 [ V_25 ] . V_19 ) {
V_12 = F_12 ( V_12 ) ;
if ( V_12 == NULL )
return;
V_68 = F_39 ( V_12 , 0 ) ;
F_34 ( V_12 ) ;
}
if ( ! V_68 )
return;
V_57 -> V_17 = V_68 ;
#ifdef F_40
if ( F_19 ( V_12 , L_36 ) )
V_57 -> V_69 = V_70 ;
#endif
}
static void T_1 F_41 ( int V_25 ,
struct V_11 * V_12 ,
struct V_31 * V_57 )
{
#ifdef F_36
struct V_71 * V_72 ;
F_16 ( L_37 , V_25 ) ;
V_72 = F_42 ( V_12 ) ;
if ( V_72 ) {
unsigned long V_3 = ( unsigned long ) V_72 -> V_73 -
#ifdef F_43
V_74 ;
#else
V_75 ;
#endif
F_16 ( L_38 ,
V_25 , V_57 -> V_33 , V_57 -> V_33 + V_3 ) ;
V_57 -> V_33 += V_3 ;
}
#endif
}
static void T_1 F_44 ( int V_25 ,
struct V_11 * V_12 ,
struct V_31 * V_57 )
{
F_16 ( L_39 , V_25 ) ;
V_57 -> V_7 = F_24 ( V_57 -> V_34 , 0x100 ) ;
}
static int T_1 F_45 ( void )
{
int V_76 ;
if ( V_27 == 0 )
return - V_77 ;
F_16 ( L_40 ) ;
for ( V_76 = 0 ; V_76 < V_27 ; V_76 ++ ) {
struct V_31 * V_57 = & V_30 [ V_76 ] ;
struct V_11 * V_12 = V_28 [ V_76 ] . V_12 ;
if ( ! V_57 -> V_17 )
F_38 ( V_76 , V_12 , V_57 ) ;
if ( V_57 -> V_14 == V_32 )
F_41 ( V_76 , V_12 , V_57 ) ;
if ( ( V_57 -> V_14 == V_47 ) || ( V_57 -> V_14 == V_37 ) )
F_44 ( V_76 , V_12 , V_57 ) ;
}
F_16 ( L_41 ) ;
return F_46 ( & V_78 ) ;
}
static int T_1 F_47 ( void )
{
struct V_11 * V_79 = NULL ;
int V_76 , V_36 = 0 , V_3 = 0 ;
const char * V_66 ;
const T_4 * V_21 ;
F_16 ( L_42 ) ;
if ( strstr ( V_80 , L_43 ) ) {
F_16 ( L_44 ) ;
return - V_81 ;
}
if ( ! V_61 ) {
F_16 ( L_45 ) ;
return - V_77 ;
}
if ( V_64 < 0 ) {
F_16 ( L_46 ) ;
return - V_77 ;
}
V_66 = F_7 ( V_61 , L_24 , NULL ) ;
if ( V_66 == NULL ) {
F_16 ( L_26 ) ;
return - V_77 ;
}
V_79 = F_30 ( V_66 ) ;
if ( ! V_79 ) {
F_16 ( L_47 , V_66 ) ;
return - V_77 ;
}
F_16 ( L_25 , V_79 -> V_40 ) ;
V_66 = F_7 ( V_79 , L_48 , NULL ) ;
if ( ! V_66 ) {
F_16 ( L_49 ) ;
goto V_82;
}
V_21 = F_7 ( V_79 , L_2 , NULL ) ;
if ( V_21 )
V_36 = F_8 ( V_21 ) ;
if ( strcmp ( V_66 , L_27 ) != 0 )
goto V_82;
for ( V_76 = 0 ; V_76 < V_27 ; V_76 ++ ) {
if ( V_79 != V_28 [ V_76 ] . V_12 )
continue;
V_3 = V_76 ;
V_36 = V_28 [ V_76 ] . V_36 ;
break;
}
if ( V_76 >= V_27 )
goto V_82;
F_34 ( V_79 ) ;
F_16 ( L_50 , V_3 ) ;
if ( V_36 ) {
static char T_8 V_83 [ 16 ] ;
sprintf ( V_83 , L_51 , V_36 ) ;
return F_48 ( L_52 , V_3 , V_83 ) ;
} else
return F_48 ( L_52 , V_3 , NULL ) ;
V_82:
F_16 ( L_53 ) ;
F_34 ( V_79 ) ;
return - V_77 ;
}
