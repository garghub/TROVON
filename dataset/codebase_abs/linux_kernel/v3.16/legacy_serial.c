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
V_46 , V_47 , 0 ) ;
else
return F_6 ( V_12 , - 1 , V_48 , V_42 , V_42 ,
V_46 , V_47 , 0 ) ;
}
static int T_1 F_15 ( struct V_11 * V_12 ,
struct V_11 * V_49 )
{
const T_4 * V_50 ;
const char * V_51 ;
int V_25 = - 1 ;
T_6 V_16 ;
F_16 ( L_13 , V_12 -> V_40 ) ;
V_50 = F_7 ( V_12 , L_14 , NULL ) ;
if ( V_50 == NULL )
return - 1 ;
if ( ! ( F_17 ( V_50 [ 0 ] ) & 0x00000001 ) )
return - 1 ;
V_51 = F_7 ( V_12 , L_15 , NULL ) ;
if ( V_51 && * V_51 == 'S' )
V_25 = F_18 ( V_51 + 1 , NULL , 0 ) - 1 ;
if ( ! F_19 ( V_49 , L_16 ) ) {
V_16 = F_14 ( V_12 , V_50 ) ;
if ( V_16 == V_45 )
V_16 = 0 ;
} else
V_16 = 0 ;
return F_6 ( V_12 , V_25 , V_32 , F_17 ( V_50 [ 1 ] ) ,
V_16 , V_46 , V_47 , 0 ) ;
}
static int T_1 F_20 ( struct V_11 * V_12 ,
struct V_11 * V_52 )
{
T_6 V_42 , V_15 ;
const T_4 * V_43 ;
unsigned int V_18 ;
int V_14 , V_25 = - 1 , V_53 = 0 ;
F_16 ( L_17 , V_12 -> V_40 ) ;
if ( F_7 ( V_12 , L_1 , NULL ) == NULL )
return - 1 ;
V_43 = F_21 ( V_52 , 0 , NULL , & V_18 ) ;
if ( V_43 == NULL )
return - 1 ;
V_14 = ( V_18 & V_54 ) ? V_48 : V_32 ;
V_42 = F_14 ( V_52 , V_43 ) ;
if ( V_42 == V_45 )
return - 1 ;
if ( V_14 == V_48 )
V_15 = V_42 ;
else
V_15 = F_22 ( & V_43 [ 2 ] , 1 ) ;
if ( V_12 != V_52 ) {
const T_4 * V_50 = F_7 ( V_12 , L_14 , NULL ) ;
if ( V_50 && ( F_8 ( V_50 ) < 4 ) )
V_25 = V_53 = F_8 ( V_50 ) ;
}
if ( F_19 ( V_52 , L_18 ) ||
F_19 ( V_52 , L_19 ) ||
F_19 ( V_52 , L_20 ) ) {
V_42 += 0x200 * V_53 ;
V_15 += 0x200 * V_53 ;
} else {
V_42 += 8 * V_53 ;
V_15 += 8 * V_53 ;
}
return F_6 ( V_12 , V_25 , V_14 , V_15 , V_42 , V_46 ,
V_47 , V_12 != V_52 ) ;
}
static void T_1 F_23 ( int V_55 )
{
struct V_56 * V_57 = & V_28 [ V_55 ] ;
struct V_31 * V_58 = & V_30 [ V_55 ] ;
void T_7 * V_42 ;
unsigned int V_59 ;
V_59 = 1 << V_58 -> V_5 ;
if ( V_57 -> V_16 ) {
V_42 = F_24 ( V_57 -> V_16 , 0x1000 ) ;
if ( V_42 == NULL )
return;
F_25 ( V_42 , V_59 ) ;
} else {
if ( V_58 -> V_14 == V_32 && V_60 )
F_26 ( V_58 -> V_33 , V_59 ) ;
else
return;
}
if ( V_57 -> V_36 == 0 )
V_57 -> V_36 = F_27 ( V_57 -> clock ) ;
F_16 ( L_21 , V_57 -> V_36 ) ;
F_28 ( V_57 -> V_36 , V_57 -> clock ) ;
}
void T_1 F_29 ( void )
{
struct V_11 * V_12 , * stdout = NULL ;
const char * V_61 ;
int V_25 ;
F_16 ( L_22 ) ;
V_61 = F_7 ( V_62 , L_23 , NULL ) ;
if ( V_61 != NULL ) {
stdout = F_30 ( V_61 ) ;
if ( stdout )
F_16 ( L_24 , stdout -> V_40 ) ;
} else {
F_16 ( L_25 ) ;
}
F_31 (np, L_26 , L_27 ) {
struct V_11 * V_63 = F_12 ( V_12 ) ;
if ( ! V_63 )
continue;
if ( F_32 ( V_64 , V_63 ) != NULL ) {
if ( F_33 ( V_12 ) ) {
V_25 = F_11 ( V_12 , V_12 ) ;
if ( V_25 >= 0 && V_12 == stdout )
V_65 = V_25 ;
}
}
F_34 ( V_63 ) ;
}
F_35 (np, L_26 ) {
struct V_11 * V_66 = F_12 ( V_12 ) ;
if ( V_66 && ( ! strcmp ( V_66 -> V_67 , L_28 ) ||
! strcmp ( V_66 -> V_67 , L_29 ) ) ) {
if ( F_33 ( V_12 ) ) {
V_25 = F_15 ( V_12 , V_66 ) ;
if ( V_25 >= 0 && V_12 == stdout )
V_65 = V_25 ;
}
}
F_34 ( V_66 ) ;
}
#ifdef F_36
for ( V_12 = NULL ; ( V_12 = F_37 ( V_12 ) ) ; ) {
struct V_11 * V_68 , * V_63 = F_12 ( V_12 ) ;
if ( V_63 && ! strcmp ( V_63 -> V_67 , L_28 ) ) {
F_34 ( V_63 ) ;
continue;
}
if ( strcmp ( V_12 -> V_67 , L_26 ) && strcmp ( V_12 -> type , L_26 ) ) {
F_34 ( V_63 ) ;
continue;
}
if ( F_19 ( V_12 , L_30 ) ||
F_19 ( V_12 , L_31 ) )
V_68 = V_12 ;
else if ( F_19 ( V_63 , L_30 ) ||
F_19 ( V_63 , L_31 ) )
V_68 = V_63 ;
else {
F_34 ( V_63 ) ;
continue;
}
V_25 = F_20 ( V_12 , V_68 ) ;
if ( V_25 >= 0 && V_12 == stdout )
V_65 = V_25 ;
F_34 ( V_63 ) ;
}
#endif
F_16 ( L_32 , V_65 ) ;
if ( V_65 >= 0 )
F_23 ( V_65 ) ;
F_16 ( L_33 ) ;
}
static void T_1 F_38 ( int V_25 ,
struct V_11 * V_12 ,
struct V_31 * V_58 )
{
unsigned int V_69 ;
F_16 ( L_34 , V_25 ) ;
V_69 = F_39 ( V_12 , 0 ) ;
if ( V_69 == V_46 && V_28 [ V_25 ] . V_19 ) {
V_12 = F_12 ( V_12 ) ;
if ( V_12 == NULL )
return;
V_69 = F_39 ( V_12 , 0 ) ;
F_34 ( V_12 ) ;
}
if ( V_69 == V_46 )
return;
V_58 -> V_17 = V_69 ;
#ifdef F_40
if ( F_19 ( V_12 , L_35 ) )
V_58 -> V_70 = V_71 ;
#endif
}
static void T_1 F_41 ( int V_25 ,
struct V_11 * V_12 ,
struct V_31 * V_58 )
{
#ifdef F_36
struct V_72 * V_73 ;
F_16 ( L_36 , V_25 ) ;
V_73 = F_42 ( V_12 ) ;
if ( V_73 ) {
unsigned long V_3 = ( unsigned long ) V_73 -> V_74 -
#ifdef F_43
V_75 ;
#else
V_76 ;
#endif
F_16 ( L_37 ,
V_25 , V_58 -> V_33 , V_58 -> V_33 + V_3 ) ;
V_58 -> V_33 += V_3 ;
}
#endif
}
static void T_1 F_44 ( int V_25 ,
struct V_11 * V_12 ,
struct V_31 * V_58 )
{
F_16 ( L_38 , V_25 ) ;
V_58 -> V_7 = F_24 ( V_58 -> V_34 , 0x100 ) ;
}
static int T_1 F_45 ( void )
{
int V_77 ;
if ( V_27 == 0 )
return - V_78 ;
F_16 ( L_39 ) ;
for ( V_77 = 0 ; V_77 < V_27 ; V_77 ++ ) {
struct V_31 * V_58 = & V_30 [ V_77 ] ;
struct V_11 * V_12 = V_28 [ V_77 ] . V_12 ;
if ( V_58 -> V_17 == V_46 )
F_38 ( V_77 , V_12 , V_58 ) ;
if ( V_58 -> V_14 == V_32 )
F_41 ( V_77 , V_12 , V_58 ) ;
if ( ( V_58 -> V_14 == V_48 ) || ( V_58 -> V_14 == V_37 ) )
F_44 ( V_77 , V_12 , V_58 ) ;
}
F_16 ( L_40 ) ;
return F_46 ( & V_79 ) ;
}
static int T_1 F_47 ( void )
{
struct V_11 * V_80 = NULL ;
int V_77 , V_36 = 0 , V_3 = 0 ;
const char * V_67 ;
const T_4 * V_21 ;
F_16 ( L_41 ) ;
if ( strstr ( V_81 , L_42 ) ) {
F_16 ( L_43 ) ;
return - V_82 ;
}
if ( ! V_62 ) {
F_16 ( L_44 ) ;
return - V_78 ;
}
if ( V_65 < 0 ) {
F_16 ( L_45 ) ;
return - V_78 ;
}
V_67 = F_7 ( V_62 , L_23 , NULL ) ;
if ( V_67 == NULL ) {
F_16 ( L_25 ) ;
return - V_78 ;
}
V_80 = F_30 ( V_67 ) ;
if ( ! V_80 ) {
F_16 ( L_46 , V_67 ) ;
return - V_78 ;
}
F_16 ( L_24 , V_80 -> V_40 ) ;
V_67 = F_7 ( V_80 , L_47 , NULL ) ;
if ( ! V_67 ) {
F_16 ( L_48 ) ;
goto V_83;
}
V_21 = F_7 ( V_80 , L_2 , NULL ) ;
if ( V_21 )
V_36 = F_8 ( V_21 ) ;
if ( strcmp ( V_67 , L_26 ) != 0 )
goto V_83;
for ( V_77 = 0 ; V_77 < V_27 ; V_77 ++ ) {
if ( V_80 != V_28 [ V_77 ] . V_12 )
continue;
V_3 = V_77 ;
V_36 = V_28 [ V_77 ] . V_36 ;
break;
}
if ( V_77 >= V_27 )
goto V_83;
F_34 ( V_80 ) ;
F_16 ( L_49 , V_3 ) ;
if ( V_36 ) {
static char T_8 V_84 [ 16 ] ;
sprintf ( V_84 , L_50 , V_36 ) ;
return F_48 ( L_51 , V_3 , V_84 ) ;
} else
return F_48 ( L_51 , V_3 , NULL ) ;
V_83:
F_16 ( L_52 ) ;
F_34 ( V_80 ) ;
return - V_78 ;
}
