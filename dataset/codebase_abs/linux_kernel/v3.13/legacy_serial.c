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
const T_4 * V_20 , * V_21 ;
T_5 clock = V_22 * 16 ;
int V_23 ;
V_20 = F_7 ( V_12 , L_1 , NULL ) ;
if ( V_20 && * V_20 )
clock = F_8 ( V_20 ) ;
V_21 = F_7 ( V_12 , L_2 , NULL ) ;
if ( V_13 >= 0 && V_13 < V_24 )
V_23 = V_13 ;
else
V_23 = V_25 ;
if ( V_23 >= V_24 )
return - 1 ;
if ( V_23 >= V_25 )
V_25 = V_23 + 1 ;
if ( V_26 [ V_23 ] . V_12 != NULL ) {
if ( V_25 < V_24 ) {
F_9 ( V_27 L_3 ,
V_23 , V_25 ) ;
V_28 [ V_25 ] =
V_28 [ V_23 ] ;
V_26 [ V_25 ] =
V_26 [ V_23 ] ;
V_25 ++ ;
} else {
F_9 ( V_27 L_4 , V_23 ) ;
}
}
memset ( & V_28 [ V_23 ] , 0 ,
sizeof( struct V_29 ) ) ;
if ( V_14 == V_30 )
V_28 [ V_23 ] . V_31 = V_15 ;
else
V_28 [ V_23 ] . V_32 = V_15 ;
V_28 [ V_23 ] . V_14 = V_14 ;
V_28 [ V_23 ] . V_33 = clock ;
V_28 [ V_23 ] . V_17 = V_17 ;
V_28 [ V_23 ] . V_18 = V_18 ;
V_26 [ V_23 ] . V_16 = V_16 ;
V_26 [ V_23 ] . V_12 = F_10 ( V_12 ) ;
V_26 [ V_23 ] . clock = clock ;
V_26 [ V_23 ] . V_34 = V_21 ? F_8 ( V_21 ) : 0 ;
V_26 [ V_23 ] . V_19 = V_19 ;
if ( V_14 == V_35 ) {
V_28 [ V_23 ] . V_36 = F_1 ;
V_28 [ V_23 ] . V_37 = F_4 ;
}
F_9 ( V_27 L_5 ,
V_23 , V_12 -> V_38 ) ;
F_9 ( V_27 L_6 ,
( V_14 == V_30 ) ? L_7 : L_8 ,
( unsigned long long ) V_15 , ( unsigned long long ) V_16 , V_17 ,
V_28 [ V_23 ] . V_33 ,
V_26 [ V_23 ] . V_34 ) ;
return V_23 ;
}
static int T_1 F_11 ( struct V_11 * V_12 ,
struct V_11 * V_39 )
{
T_6 V_40 ;
const T_4 * V_41 ;
T_3 V_18 = V_42 | V_43 | V_44
| V_45 ;
struct V_11 * V_46 = F_12 ( V_12 ) ;
if ( F_7 ( V_12 , L_1 , NULL ) == NULL )
return - 1 ;
if ( ( F_7 ( V_12 , L_9 , NULL ) != NULL ) ||
( F_7 ( V_12 , L_10 , NULL ) != NULL ) )
return - 1 ;
if ( F_7 ( V_12 , L_11 , NULL ) != NULL )
return - 1 ;
V_41 = F_13 ( V_39 , 0 , NULL , NULL ) ;
if ( V_41 == NULL )
return - 1 ;
V_40 = F_14 ( V_39 , V_41 ) ;
if ( V_40 == V_47 )
return - 1 ;
if ( V_46 && ! strcmp ( V_46 -> type , L_12 ) )
return F_6 ( V_12 , - 1 , V_35 , V_40 , V_40 , V_48 , V_18 , 0 ) ;
else
return F_6 ( V_12 , - 1 , V_49 , V_40 , V_40 , V_48 , V_18 , 0 ) ;
}
static int T_1 F_15 ( struct V_11 * V_12 ,
struct V_11 * V_50 )
{
const T_4 * V_51 ;
const char * V_52 ;
int V_23 = - 1 ;
T_6 V_16 ;
F_16 ( L_13 , V_12 -> V_38 ) ;
V_51 = F_7 ( V_12 , L_14 , NULL ) ;
if ( V_51 == NULL )
return - 1 ;
if ( ! ( F_17 ( V_51 [ 0 ] ) & 0x00000001 ) )
return - 1 ;
V_52 = F_7 ( V_12 , L_15 , NULL ) ;
if ( V_52 && * V_52 == 'S' )
V_23 = F_18 ( V_52 + 1 , NULL , 0 ) - 1 ;
if ( ! F_19 ( V_50 , L_16 ) ) {
V_16 = F_14 ( V_12 , V_51 ) ;
if ( V_16 == V_47 )
V_16 = 0 ;
} else
V_16 = 0 ;
return F_6 ( V_12 , V_23 , V_30 , F_17 ( V_51 [ 1 ] ) ,
V_16 , V_48 , V_42 , 0 ) ;
}
static int T_1 F_20 ( struct V_11 * V_12 ,
struct V_11 * V_53 )
{
T_6 V_40 , V_15 ;
const T_4 * V_41 ;
unsigned int V_18 ;
int V_14 , V_23 = - 1 , V_54 = 0 ;
F_16 ( L_17 , V_12 -> V_38 ) ;
if ( F_7 ( V_12 , L_1 , NULL ) == NULL )
return - 1 ;
V_41 = F_21 ( V_53 , 0 , NULL , & V_18 ) ;
if ( V_41 == NULL )
return - 1 ;
V_14 = ( V_18 & V_55 ) ? V_49 : V_30 ;
V_40 = F_14 ( V_53 , V_41 ) ;
if ( V_40 == V_47 )
return - 1 ;
if ( V_14 == V_49 )
V_15 = V_40 ;
else
V_15 = F_22 ( & V_41 [ 2 ] , 1 ) ;
if ( V_12 != V_53 ) {
const T_4 * V_51 = F_7 ( V_12 , L_14 , NULL ) ;
if ( V_51 && ( F_8 ( V_51 ) < 4 ) )
V_23 = V_54 = F_8 ( V_51 ) ;
}
if ( F_19 ( V_53 , L_18 ) ||
F_19 ( V_53 , L_19 ) ||
F_19 ( V_53 , L_20 ) ) {
V_40 += 0x200 * V_54 ;
V_15 += 0x200 * V_54 ;
} else {
V_40 += 8 * V_54 ;
V_15 += 8 * V_54 ;
}
return F_6 ( V_12 , V_23 , V_14 , V_15 , V_40 , V_48 ,
V_42 , V_12 != V_53 ) ;
}
static void T_1 F_23 ( int V_56 )
{
struct V_57 * V_58 = & V_26 [ V_56 ] ;
struct V_29 * V_59 = & V_28 [ V_56 ] ;
void T_7 * V_40 ;
if ( V_58 -> V_16 ) {
V_40 = F_24 ( V_58 -> V_16 , 0x1000 ) ;
if ( V_40 == NULL )
return;
F_25 ( V_40 , 1 ) ;
} else {
if ( V_59 -> V_14 == V_30 && V_60 )
F_26 ( V_59 -> V_31 , 1 ) ;
else
return;
}
if ( V_58 -> V_34 == 0 )
V_58 -> V_34 = F_27 ( V_58 -> clock ) ;
F_16 ( L_21 , V_58 -> V_34 ) ;
F_28 ( V_58 -> V_34 , V_58 -> clock ) ;
}
void T_1 F_29 ( void )
{
struct V_11 * V_12 , * stdout = NULL ;
const char * V_61 ;
int V_23 ;
F_16 ( L_22 ) ;
V_61 = F_7 ( V_62 , L_23 , NULL ) ;
if ( V_61 != NULL ) {
stdout = F_30 ( V_61 ) ;
if ( stdout )
F_16 ( L_24 , stdout -> V_38 ) ;
} else {
F_16 ( L_25 ) ;
}
F_31 (np, L_26 , L_27 ) {
struct V_11 * V_63 = F_12 ( V_12 ) ;
if ( ! V_63 )
continue;
if ( F_32 ( V_64 , V_63 ) != NULL ) {
if ( F_33 ( V_12 ) ) {
V_23 = F_11 ( V_12 , V_12 ) ;
if ( V_23 >= 0 && V_12 == stdout )
V_65 = V_23 ;
}
}
F_34 ( V_63 ) ;
}
F_35 (np, L_26 ) {
struct V_11 * V_66 = F_12 ( V_12 ) ;
if ( V_66 && ( ! strcmp ( V_66 -> V_67 , L_28 ) ||
! strcmp ( V_66 -> V_67 , L_29 ) ) ) {
if ( F_33 ( V_12 ) ) {
V_23 = F_15 ( V_12 , V_66 ) ;
if ( V_23 >= 0 && V_12 == stdout )
V_65 = V_23 ;
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
V_23 = F_20 ( V_12 , V_68 ) ;
if ( V_23 >= 0 && V_12 == stdout )
V_65 = V_23 ;
F_34 ( V_63 ) ;
}
#endif
F_16 ( L_32 , V_65 ) ;
if ( V_65 >= 0 )
F_23 ( V_65 ) ;
F_16 ( L_33 ) ;
}
static void T_1 F_38 ( int V_23 ,
struct V_11 * V_12 ,
struct V_29 * V_59 )
{
unsigned int V_69 ;
F_16 ( L_34 , V_23 ) ;
V_69 = F_39 ( V_12 , 0 ) ;
if ( V_69 == V_48 && V_26 [ V_23 ] . V_19 ) {
V_12 = F_12 ( V_12 ) ;
if ( V_12 == NULL )
return;
V_69 = F_39 ( V_12 , 0 ) ;
F_34 ( V_12 ) ;
}
if ( V_69 == V_48 )
return;
V_59 -> V_17 = V_69 ;
#ifdef F_40
if ( F_19 ( V_12 , L_35 ) )
V_59 -> V_70 = V_71 ;
#endif
}
static void T_1 F_41 ( int V_23 ,
struct V_11 * V_12 ,
struct V_29 * V_59 )
{
#ifdef F_36
struct V_72 * V_73 ;
F_16 ( L_36 , V_23 ) ;
V_73 = F_42 ( V_12 ) ;
if ( V_73 ) {
unsigned long V_3 = ( unsigned long ) V_73 -> V_74 -
#ifdef F_43
V_75 ;
#else
V_76 ;
#endif
F_16 ( L_37 ,
V_23 , V_59 -> V_31 , V_59 -> V_31 + V_3 ) ;
V_59 -> V_31 += V_3 ;
}
#endif
}
static void T_1 F_44 ( int V_23 ,
struct V_11 * V_12 ,
struct V_29 * V_59 )
{
F_16 ( L_38 , V_23 ) ;
V_59 -> V_7 = F_24 ( V_59 -> V_32 , 0x100 ) ;
}
static int T_1 F_45 ( void )
{
int V_77 ;
if ( V_25 == 0 )
return - V_78 ;
F_16 ( L_39 ) ;
for ( V_77 = 0 ; V_77 < V_25 ; V_77 ++ ) {
struct V_29 * V_59 = & V_28 [ V_77 ] ;
struct V_11 * V_12 = V_26 [ V_77 ] . V_12 ;
if ( V_59 -> V_17 == V_48 )
F_38 ( V_77 , V_12 , V_59 ) ;
if ( V_59 -> V_14 == V_30 )
F_41 ( V_77 , V_12 , V_59 ) ;
if ( ( V_59 -> V_14 == V_49 ) || ( V_59 -> V_14 == V_35 ) )
F_44 ( V_77 , V_12 , V_59 ) ;
}
F_16 ( L_40 ) ;
return F_46 ( & V_79 ) ;
}
static int T_1 F_47 ( void )
{
struct V_11 * V_80 = NULL ;
int V_77 , V_34 = 0 , V_3 = 0 ;
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
F_16 ( L_24 , V_80 -> V_38 ) ;
V_67 = F_7 ( V_80 , L_47 , NULL ) ;
if ( ! V_67 ) {
F_16 ( L_48 ) ;
goto V_83;
}
V_21 = F_7 ( V_80 , L_2 , NULL ) ;
if ( V_21 )
V_34 = F_8 ( V_21 ) ;
if ( strcmp ( V_67 , L_26 ) != 0 )
goto V_83;
for ( V_77 = 0 ; V_77 < V_25 ; V_77 ++ ) {
if ( V_80 != V_26 [ V_77 ] . V_12 )
continue;
V_3 = V_77 ;
V_34 = V_26 [ V_77 ] . V_34 ;
break;
}
if ( V_77 >= V_25 )
goto V_83;
F_34 ( V_80 ) ;
F_16 ( L_49 , V_3 ) ;
if ( V_34 ) {
static char T_8 V_84 [ 16 ] ;
sprintf ( V_84 , L_50 , V_34 ) ;
return F_48 ( L_51 , V_3 , V_84 ) ;
} else
return F_48 ( L_51 , V_3 , NULL ) ;
V_83:
F_16 ( L_52 ) ;
F_34 ( V_80 ) ;
return - V_78 ;
}
