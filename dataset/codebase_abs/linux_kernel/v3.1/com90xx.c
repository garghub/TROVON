static void T_1 F_1 ( void )
{
int V_1 , V_2 , V_3 , V_4 , V_5 , V_6 = 0 ;
unsigned long V_7 ;
int V_8 [ ( 0x3f0 - 0x200 ) / 16 + 1 ] =
{ 0 } ;
unsigned long * V_9 ;
void T_2 * * V_10 ;
int V_11 , V_12 , * V_13 ;
T_3 * V_14 ;
int V_15 ;
if ( ! V_16 && ! V_17 && ! V_18 && ! * V_19 && V_20 )
return;
V_9 = F_2 ( ( ( 0x100000 - 0xa0000 ) / 0x800 ) * sizeof( unsigned long ) ,
V_21 ) ;
if ( ! V_9 )
return;
V_10 = F_2 ( ( ( 0x100000 - 0xa0000 ) / 0x800 ) * sizeof( void T_2 * ) ,
V_21 ) ;
if ( ! V_10 ) {
F_3 ( V_9 ) ;
return;
}
F_4 (D_NORMAL) F_5 ( V_22 ) ;
V_11 = V_12 = 0 ;
if ( V_16 )
V_8 [ V_11 ++ ] = V_16 ;
else
for ( V_1 = 0x200 ; V_1 <= 0x3f0 ; V_1 += 16 )
V_8 [ V_11 ++ ] = V_1 ;
if ( V_18 )
V_9 [ V_12 ++ ] = V_18 ;
else
for ( V_1 = 0xA0000 ; V_1 <= 0xFF800 ; V_1 += 2048 )
V_9 [ V_12 ++ ] = V_1 ;
V_4 = - 1 ;
for ( V_13 = & V_8 [ 0 ] ; V_13 - V_8 < V_11 ; V_13 ++ ) {
V_4 ++ ;
V_4 %= 8 ;
if ( ! V_4 ) {
F_6 ( V_23 , L_1 ) ;
F_6 ( V_23 , L_2 ) ;
}
F_6 ( V_23 , L_3 , * V_13 ) ;
V_3 = * V_13 ;
if ( ! F_7 ( * V_13 , V_24 , L_4 ) ) {
F_6 ( V_25 , L_5 ) ;
F_6 ( V_25 , L_2 ) ;
F_4 (D_INIT_REASONS) V_4 = 0 ;
* V_13 -- = V_8 [ -- V_11 ] ;
continue;
}
if ( F_8 () == 0xFF ) {
F_6 ( V_25 , L_6 ) ;
F_6 ( V_25 , L_2 ) ;
F_4 (D_INIT_REASONS) V_4 = 0 ;
F_9 ( * V_13 , V_24 ) ;
* V_13 -- = V_8 [ -- V_11 ] ;
continue;
}
F_10 ( V_26 ) ;
F_6 ( V_25 , L_1 ) ;
F_6 ( V_25 , L_2 ) ;
F_4 (D_INIT_REASONS) V_4 = 0 ;
}
F_6 ( V_23 , L_1 ) ;
if ( ! V_11 ) {
F_6 ( V_27 , L_7 ) ;
F_3 ( V_9 ) ;
F_3 ( V_10 ) ;
return;
}
V_4 = - 1 ;
for ( V_13 = & V_8 [ 0 ] ; V_13 < V_8 + V_11 ; V_13 ++ ) {
V_4 ++ ;
V_4 %= 8 ;
if ( ! V_4 ) {
F_6 ( V_23 , L_1 ) ;
F_6 ( V_23 , L_8 ) ;
}
F_6 ( V_23 , L_3 , * V_13 ) ;
}
F_6 ( V_23 , L_1 ) ;
F_11 ( V_28 ) ;
V_4 = - 1 ;
for ( V_15 = 0 , V_14 = & V_9 [ 0 ] ; V_15 < V_12 ; V_14 ++ , V_15 ++ ) {
void T_2 * V_29 ;
V_4 ++ ;
V_4 %= 8 ;
if ( ! V_4 ) {
F_6 ( V_23 , L_1 ) ;
F_6 ( V_23 , L_9 ) ;
}
F_6 ( V_23 , L_10 , * V_14 ) ;
if ( ! F_12 ( * V_14 , V_30 , L_4 ) ) {
F_6 ( V_25 , L_11 ) ;
F_6 ( V_25 , L_12 ) ;
F_4 (D_INIT_REASONS) V_4 = 0 ;
goto V_31;
}
V_29 = F_13 ( * V_14 , V_30 ) ;
if ( ! V_29 ) {
F_6 ( V_25 , L_13 ) ;
F_6 ( V_25 , L_12 ) ;
F_4 (D_INIT_REASONS) V_4 = 0 ;
goto V_32;
}
if ( F_14 ( V_29 ) != V_33 ) {
F_6 ( V_25 , L_14 ,
F_14 ( V_29 ) , V_33 ) ;
F_6 ( V_25 , L_9 ) ;
F_4 (D_INIT_REASONS) V_4 = 0 ;
goto V_34;
}
F_15 ( 0x42 , V_29 ) ;
if ( F_14 ( V_29 ) != 0x42 ) {
F_6 ( V_25 , L_15 ) ;
F_6 ( V_25 , L_9 ) ;
goto V_34;
}
F_6 ( V_25 , L_1 ) ;
F_6 ( V_25 , L_9 ) ;
F_4 (D_INIT_REASONS) V_4 = 0 ;
V_10 [ V_15 ] = V_29 ;
continue;
V_34:
F_16 ( V_29 ) ;
V_32:
F_17 ( * V_14 , V_30 ) ;
V_31:
* V_14 -- = V_9 [ -- V_12 ] ;
V_15 -- ;
}
F_6 ( V_23 , L_1 ) ;
if ( ! V_12 ) {
F_6 ( V_27 , L_16 ) ;
for ( V_13 = & V_8 [ 0 ] ; V_13 < V_8 + V_11 ; V_13 ++ )
F_9 ( * V_13 , V_24 ) ;
F_3 ( V_9 ) ;
F_3 ( V_10 ) ;
return;
}
V_4 = - 1 ;
for ( V_14 = & V_9 [ 0 ] ; V_14 < V_9 + V_12 ; V_14 ++ ) {
V_4 ++ ;
V_4 %= 8 ;
if ( ! V_4 ) {
F_6 ( V_23 , L_1 ) ;
F_6 ( V_23 , L_17 ) ;
}
F_6 ( V_23 , L_10 , * V_14 ) ;
}
F_6 ( V_23 , L_1 ) ;
V_4 = - 1 ;
for ( V_13 = & V_8 [ 0 ] ; V_13 < V_8 + V_11 ; V_13 ++ ) {
int V_35 = 0 ;
V_4 ++ ;
V_4 %= 8 ;
if ( ! V_4 ) {
F_6 ( V_23 , L_1 ) ;
F_6 ( V_23 , L_18 ) ;
}
F_6 ( V_23 , L_3 , * V_13 ) ;
V_3 = * V_13 ;
V_2 = F_8 () ;
if ( ( V_2 & 0x9D )
!= ( V_36 | V_37 | V_38 | V_39 ) ) {
F_6 ( V_25 , L_19 , V_2 ) ;
F_6 ( V_25 , L_18 ) ;
F_4 (D_INIT_REASONS) V_4 = 0 ;
F_9 ( * V_13 , V_24 ) ;
* V_13 -- = V_8 [ -- V_11 ] ;
continue;
}
F_18 ( V_40 | V_41 | V_42 ) ;
V_2 = F_8 () ;
if ( V_2 & V_39 ) {
F_6 ( V_25 , L_20 ,
V_2 ) ;
F_6 ( V_25 , L_18 ) ;
F_4 (D_INIT_REASONS) V_4 = 0 ;
F_9 ( * V_13 , V_24 ) ;
* V_13 -- = V_8 [ -- V_11 ] ;
continue;
}
if ( ! V_17 ) {
V_7 = F_19 () ;
F_20 ( V_36 ) ;
F_21 ( 1 ) ;
F_20 ( 0 ) ;
V_5 = F_22 ( V_7 ) ;
if ( V_5 <= 0 ) {
F_6 ( V_25 , L_21 , V_5 ) ;
F_6 ( V_25 , L_18 ) ;
F_4 (D_INIT_REASONS) V_4 = 0 ;
F_9 ( * V_13 , V_24 ) ;
* V_13 -- = V_8 [ -- V_11 ] ;
continue;
}
} else {
V_5 = V_17 ;
}
F_6 ( V_23 , L_22 , V_5 ) ;
V_6 = 1 ;
#ifdef F_23
if ( V_11 > 1 || V_12 > 1 ) {
F_10 ( V_26 ) ;
F_11 ( V_28 ) ;
} else {
F_15 ( V_33 , V_10 [ 0 ] ) ;
}
#else
F_10 ( V_26 ) ;
F_11 ( V_28 ) ;
#endif
for ( V_15 = 0 ; V_15 < V_12 ; V_15 ++ ) {
T_3 V_43 = V_9 [ V_15 ] ;
void T_2 * V_29 = V_10 [ V_15 ] ;
if ( F_14 ( V_29 ) == V_33 ) {
F_6 ( V_23 , L_23 , * V_14 ) ;
V_6 = 0 ;
if ( F_24 ( * V_13 , V_5 , V_43 , V_29 ) == 0 )
V_35 = 1 ;
V_4 = - 1 ;
V_9 [ V_15 ] = V_9 [ -- V_12 ] ;
V_10 [ V_15 ] = V_10 [ V_12 ] ;
break;
} else {
F_6 ( V_25 , L_24 , F_14 ( V_29 ) ) ;
}
}
if ( V_6 ) {
F_4 (D_INIT) F_5 ( L_25 ) ;
F_4 (D_INIT_REASONS) F_5 ( L_18 ) ;
F_4 (D_INIT_REASONS) V_4 = 0 ;
}
if ( ! V_35 )
F_9 ( * V_13 , V_24 ) ;
* V_13 -- = V_8 [ -- V_11 ] ;
}
F_4 (D_INIT_REASONS) F_5 ( L_1 ) ;
for ( V_15 = 0 ; V_15 < V_12 ; V_15 ++ ) {
F_15 ( V_33 , V_10 [ V_15 ] ) ;
F_16 ( V_10 [ V_15 ] ) ;
F_17 ( V_9 [ V_15 ] , V_30 ) ;
}
F_3 ( V_9 ) ;
F_3 ( V_10 ) ;
}
static int F_25 ( unsigned long V_44 , T_4 V_45 )
{
void T_2 * V_14 ;
int V_46 = - 1 ;
if ( ! F_12 ( V_44 , V_45 , L_4 ) )
return - 1 ;
V_14 = F_13 ( V_44 , V_45 ) ;
if ( V_14 ) {
if ( F_14 ( V_14 ) == V_33 )
V_46 = 1 ;
else
V_46 = 0 ;
F_16 ( V_14 ) ;
}
F_17 ( V_44 , V_45 ) ;
return V_46 ;
}
static int T_1 F_24 ( int V_3 , int V_5 , T_3 V_18 , void T_2 * V_14 )
{
struct V_47 * V_48 = NULL ;
struct V_49 * V_50 ;
T_3 V_51 , V_52 ;
int V_53 ;
V_48 = F_26 ( V_19 ) ;
if ( ! V_48 ) {
F_6 ( V_27 , L_26 ) ;
F_16 ( V_14 ) ;
F_17 ( V_18 , V_30 ) ;
return - V_54 ;
}
V_50 = F_27 ( V_48 ) ;
V_53 = V_30 ;
if ( F_14 ( V_14 ) == V_33 &&
F_25 ( V_18 - V_30 , V_30 ) == 0 &&
F_25 ( V_18 - 2 * V_30 , V_30 ) == 1 )
V_53 = 2 * V_30 ;
V_51 = V_18 - V_53 ;
while ( F_25 ( V_51 , V_53 ) == 1 )
V_51 -= V_53 ;
V_51 += V_53 ;
V_52 = V_18 + V_53 ;
while ( F_25 ( V_52 , V_53 ) == 1 )
V_52 += V_53 ;
V_52 -= V_53 ;
V_48 -> V_55 = V_51 ;
V_48 -> V_56 = V_52 + V_30 - 1 ;
F_16 ( V_14 ) ;
F_17 ( V_18 , V_30 ) ;
if ( ! F_12 ( V_48 -> V_55 , V_48 -> V_56 - V_48 -> V_55 + 1 , L_4 ) )
goto V_57;
if ( F_28 ( V_5 , V_58 , 0 , L_4 , V_48 ) ) {
F_29 ( V_27 , L_27 , V_5 ) ;
goto V_59;
}
V_48 -> V_17 = V_5 ;
V_50 -> V_60 = L_28 ;
V_50 -> V_61 . V_62 = V_63 ;
V_50 -> V_61 . V_2 = V_64 ;
V_50 -> V_61 . V_65 = V_66 ;
V_50 -> V_61 . V_67 = V_68 ;
V_50 -> V_61 . V_69 = V_70 ;
V_50 -> V_61 . V_71 = V_72 ;
V_50 -> V_61 . V_73 = V_74 ;
V_50 -> V_55 = F_13 ( V_48 -> V_55 , V_48 -> V_56 - V_48 -> V_55 + 1 ) ;
if ( ! V_50 -> V_55 ) {
F_29 ( V_27 , L_29 ) ;
goto V_75;
}
V_48 -> V_76 [ 0 ] = F_14 ( V_50 -> V_55 + 1 ) ;
V_48 -> V_77 = V_3 ;
F_29 ( V_27 , L_30
L_31 ,
V_48 -> V_76 [ 0 ] ,
V_48 -> V_77 , V_48 -> V_17 , V_48 -> V_55 ,
( V_48 -> V_56 - V_48 -> V_55 + 1 ) / V_53 , V_53 ) ;
if ( F_30 ( V_48 ) )
goto V_78;
V_79 [ V_80 ++ ] = V_48 ;
return 0 ;
V_78:
F_16 ( V_50 -> V_55 ) ;
V_75:
F_31 ( V_48 -> V_17 , V_48 ) ;
V_59:
F_17 ( V_48 -> V_55 , V_48 -> V_56 - V_48 -> V_55 + 1 ) ;
V_57:
F_32 ( V_48 ) ;
return - V_81 ;
}
static void V_63 ( struct V_47 * V_48 , int V_82 )
{
short V_3 = V_48 -> V_77 ;
F_18 ( V_82 ) ;
}
static int V_64 ( struct V_47 * V_48 )
{
short V_3 = V_48 -> V_77 ;
return F_8 () ;
}
static void V_66 ( struct V_47 * V_48 , int V_83 )
{
short V_3 = V_48 -> V_77 ;
F_20 ( V_83 ) ;
}
static int V_68 ( struct V_47 * V_48 , int V_84 )
{
struct V_49 * V_50 = F_27 ( V_48 ) ;
short V_3 = V_48 -> V_77 ;
F_29 ( V_23 , L_32 , F_8 () ) ;
if ( V_84 ) {
F_10 ( V_26 ) ;
F_11 ( V_28 ) ;
}
F_18 ( V_40 | V_41 ) ;
F_18 ( V_40 | V_42 ) ;
if ( F_14 ( V_50 -> V_55 ) != V_33 ) {
if ( V_84 )
F_29 ( V_27 , L_33 ) ;
return 1 ;
}
F_18 ( V_85 | V_86 ) ;
F_4 (D_DURING)
F_33 ( V_50 -> V_55 , 0x42 , 2048 ) ;
return 0 ;
}
static void V_72 ( struct V_47 * V_48 , int V_87 , int V_88 ,
void * V_89 , int V_1 )
{
struct V_49 * V_50 = F_27 ( V_48 ) ;
void T_2 * V_90 = V_50 -> V_55 + V_87 * 512 + V_88 ;
TIME ( L_34 , V_1 , F_34 ( V_90 , V_89 , V_1 ) ) ;
}
static void V_74 ( struct V_47 * V_48 , int V_87 , int V_88 ,
void * V_89 , int V_1 )
{
struct V_49 * V_50 = F_27 ( V_48 ) ;
void T_2 * V_90 = V_50 -> V_55 + V_87 * 512 + V_88 ;
TIME ( L_35 , V_1 , F_35 ( V_89 , V_90 , V_1 ) ) ;
}
static int T_1 F_36 ( void )
{
if ( V_17 == 2 )
V_17 = 9 ;
F_1 () ;
if ( ! V_80 )
return - V_81 ;
return 0 ;
}
static void T_5 F_37 ( void )
{
struct V_47 * V_48 ;
struct V_49 * V_50 ;
int V_1 ;
for ( V_1 = 0 ; V_1 < V_80 ; V_1 ++ ) {
V_48 = V_79 [ V_1 ] ;
V_50 = F_27 ( V_48 ) ;
F_38 ( V_48 ) ;
F_31 ( V_48 -> V_17 , V_48 ) ;
F_16 ( V_50 -> V_55 ) ;
F_9 ( V_48 -> V_77 , V_24 ) ;
F_17 ( V_48 -> V_55 , V_48 -> V_56 - V_48 -> V_55 + 1 ) ;
F_32 ( V_48 ) ;
}
}
static int T_1 F_39 ( char * V_91 )
{
int V_92 [ 8 ] ;
V_91 = F_40 ( V_91 , 8 , V_92 ) ;
if ( ! V_92 [ 0 ] && ! * V_91 ) {
F_5 ( L_36 ) ;
return 1 ;
}
switch ( V_92 [ 0 ] ) {
default:
F_5 ( L_37 ) ;
case 3 :
V_18 = V_92 [ 3 ] ;
case 2 :
V_17 = V_92 [ 2 ] ;
case 1 :
V_16 = V_92 [ 1 ] ;
}
if ( * V_91 )
snprintf ( V_19 , sizeof( V_19 ) , L_38 , V_91 ) ;
return 1 ;
}
