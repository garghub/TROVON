static int T_1 F_1 ( char * V_1 )
{
V_2 = 1 ;
return 0 ;
}
static unsigned long T_1 F_2 ( unsigned long V_3 )
{
unsigned long V_4 = F_3 ( V_3 , V_5 ) ;
return F_4 ( V_4 , sizeof( long ) ) ;
}
unsigned long T_1 F_5 ( unsigned long V_3 )
{
unsigned long V_4 = F_2 ( V_3 ) ;
return F_6 ( V_4 ) >> V_6 ;
}
static void T_1 F_7 ( T_2 * V_7 )
{
T_2 * V_8 ;
F_8 (ent, &bdata_list, list) {
if ( V_7 -> V_9 < V_8 -> V_9 ) {
F_9 ( & V_7 -> V_10 , & V_8 -> V_10 ) ;
return;
}
}
F_9 ( & V_7 -> V_10 , & V_11 ) ;
}
static unsigned long T_1 F_10 ( T_2 * V_7 ,
unsigned long V_12 , unsigned long V_13 , unsigned long V_14 )
{
unsigned long V_15 ;
F_11 ( & V_13 , & V_14 ) ;
V_7 -> V_16 = F_12 ( F_13 ( V_12 ) ) ;
V_7 -> V_9 = V_13 ;
V_7 -> V_17 = V_14 ;
F_7 ( V_7 ) ;
V_15 = F_2 ( V_14 - V_13 ) ;
memset ( V_7 -> V_16 , 0xff , V_15 ) ;
F_14 ( L_1 ,
V_7 - V_18 , V_13 , V_12 , V_14 , V_15 ) ;
return V_15 ;
}
unsigned long T_1 F_15 ( T_3 * V_19 , unsigned long V_20 ,
unsigned long V_21 , unsigned long V_22 )
{
return F_10 ( V_19 -> V_7 , V_20 , V_21 , V_22 ) ;
}
unsigned long T_1 F_16 ( unsigned long V_13 , unsigned long V_3 )
{
V_23 = V_3 ;
V_24 = V_13 ;
return F_10 ( F_17 ( 0 ) -> V_7 , V_13 , 0 , V_3 ) ;
}
void T_1 F_18 ( unsigned long V_25 , unsigned long V_26 )
{
unsigned long V_27 , V_14 ;
F_19 ( V_25 , V_26 ) ;
V_27 = F_20 ( V_25 ) ;
V_14 = F_21 ( V_25 + V_26 ) ;
for (; V_27 < V_14 ; V_27 ++ ) {
F_22 ( F_23 ( V_27 ) , V_27 , 0 ) ;
V_28 ++ ;
}
}
static unsigned long T_1 F_24 ( T_2 * V_7 )
{
struct V_29 * V_29 ;
unsigned long * V_30 , V_13 , V_14 , V_3 , V_31 , V_32 = 0 ;
if ( ! V_7 -> V_16 )
return 0 ;
V_30 = V_7 -> V_16 ;
V_13 = V_7 -> V_9 ;
V_14 = V_7 -> V_17 ;
F_14 ( L_2 ,
V_7 - V_18 , V_13 , V_14 ) ;
while ( V_13 < V_14 ) {
unsigned long V_33 , V_34 ;
unsigned V_35 ;
V_33 = V_13 - V_7 -> V_9 ;
V_35 = V_33 & ( V_36 - 1 ) ;
V_34 = ~ V_30 [ V_33 / V_36 ] ;
if ( V_35 ) {
V_34 >>= V_35 ;
if ( V_14 - V_13 >= V_36 )
V_34 |= ~ V_30 [ V_33 / V_36 + 1 ] <<
( V_36 - V_35 ) ;
}
if ( F_25 ( V_13 , V_36 ) && V_34 == ~ 0UL ) {
int V_37 = F_26 ( V_36 ) ;
F_22 ( F_23 ( V_13 ) , V_13 , V_37 ) ;
V_32 += V_36 ;
V_13 += V_36 ;
} else {
V_31 = V_13 ;
V_13 = F_4 ( V_13 + 1 , V_36 ) ;
while ( V_34 && V_31 != V_13 ) {
if ( V_34 & 1 ) {
V_29 = F_23 ( V_31 ) ;
F_22 ( V_29 , V_31 , 0 ) ;
V_32 ++ ;
}
V_34 >>= 1 ;
++ V_31 ;
}
}
}
V_31 = V_7 -> V_9 ;
V_29 = F_27 ( V_7 -> V_16 ) ;
V_3 = V_7 -> V_17 - V_7 -> V_9 ;
V_3 = F_5 ( V_3 ) ;
V_32 += V_3 ;
while ( V_3 -- )
F_22 ( V_29 ++ , V_31 ++ , 0 ) ;
V_7 -> V_16 = NULL ;
F_14 ( L_3 , V_7 - V_18 , V_32 ) ;
return V_32 ;
}
void F_28 ( T_3 * V_19 )
{
struct V_38 * V_39 ;
for ( V_39 = V_19 -> V_40 ; V_39 < V_19 -> V_40 + V_41 ; V_39 ++ )
V_39 -> V_42 = 0 ;
}
void T_1 F_29 ( void )
{
struct V_43 * V_19 ;
if ( V_44 )
return;
F_30 (pgdat)
F_28 ( V_19 ) ;
V_44 = 1 ;
}
unsigned long T_1 F_31 ( void )
{
unsigned long V_45 = 0 ;
T_2 * V_7 ;
F_29 () ;
F_8 (bdata, &bdata_list, list)
V_45 += F_24 ( V_7 ) ;
V_28 += V_45 ;
return V_45 ;
}
static void T_1 F_32 ( T_2 * V_7 ,
unsigned long V_46 , unsigned long V_47 )
{
unsigned long V_33 ;
F_14 ( L_2 , V_7 - V_18 ,
V_46 + V_7 -> V_9 ,
V_47 + V_7 -> V_9 ) ;
if ( F_33 ( V_7 -> V_16 == NULL ) )
return;
if ( V_7 -> V_48 > V_46 )
V_7 -> V_48 = V_46 ;
for ( V_33 = V_46 ; V_33 < V_47 ; V_33 ++ )
if ( ! F_34 ( V_33 , V_7 -> V_16 ) )
F_35 () ;
}
static int T_1 F_36 ( T_2 * V_7 , unsigned long V_46 ,
unsigned long V_47 , int V_49 )
{
unsigned long V_33 ;
int V_50 = V_49 & V_51 ;
F_14 ( L_4 ,
V_7 - V_18 ,
V_46 + V_7 -> V_9 ,
V_47 + V_7 -> V_9 ,
V_49 ) ;
if ( F_33 ( V_7 -> V_16 == NULL ) )
return 0 ;
for ( V_33 = V_46 ; V_33 < V_47 ; V_33 ++ )
if ( F_37 ( V_33 , V_7 -> V_16 ) ) {
if ( V_50 ) {
F_32 ( V_7 , V_46 , V_33 ) ;
return - V_52 ;
}
F_14 ( L_5 ,
V_33 + V_7 -> V_9 ) ;
}
return 0 ;
}
static int T_1 F_38 ( T_2 * V_7 ,
unsigned long V_13 , unsigned long V_14 ,
int V_53 , int V_49 )
{
unsigned long V_46 , V_47 ;
F_14 ( L_6 ,
V_7 - V_18 , V_13 , V_14 , V_53 , V_49 ) ;
F_39 ( V_13 < V_7 -> V_9 ) ;
F_39 ( V_14 > V_7 -> V_17 ) ;
V_46 = V_13 - V_7 -> V_9 ;
V_47 = V_14 - V_7 -> V_9 ;
if ( V_53 )
return F_36 ( V_7 , V_46 , V_47 , V_49 ) ;
else
F_32 ( V_7 , V_46 , V_47 ) ;
return 0 ;
}
static int T_1 F_40 ( unsigned long V_13 , unsigned long V_14 ,
int V_53 , int V_49 )
{
unsigned long V_54 ;
T_2 * V_7 ;
V_54 = V_13 ;
F_8 (bdata, &bdata_list, list) {
int V_55 ;
unsigned long V_56 ;
if ( V_54 < V_7 -> V_9 ||
V_54 >= V_7 -> V_17 ) {
F_39 ( V_54 != V_13 ) ;
continue;
}
V_56 = F_41 ( V_7 -> V_17 , V_14 ) ;
V_55 = F_38 ( V_7 , V_54 , V_56 , V_53 , V_49 ) ;
if ( V_53 && V_55 ) {
F_40 ( V_13 , V_54 , 0 , 0 ) ;
return V_55 ;
}
if ( V_56 == V_14 )
return 0 ;
V_54 = V_7 -> V_17 ;
}
F_35 () ;
}
void T_1 F_42 ( T_3 * V_19 , unsigned long V_25 ,
unsigned long V_26 )
{
unsigned long V_13 , V_14 ;
F_19 ( V_25 , V_26 ) ;
V_13 = F_20 ( V_25 ) ;
V_14 = F_21 ( V_25 + V_26 ) ;
F_38 ( V_19 -> V_7 , V_13 , V_14 , 0 , 0 ) ;
}
void T_1 F_43 ( unsigned long V_25 , unsigned long V_26 )
{
unsigned long V_13 , V_14 ;
F_19 ( V_25 , V_26 ) ;
V_13 = F_20 ( V_25 ) ;
V_14 = F_21 ( V_25 + V_26 ) ;
F_40 ( V_13 , V_14 , 0 , 0 ) ;
}
int T_1 F_44 ( T_3 * V_19 , unsigned long V_25 ,
unsigned long V_26 , int V_49 )
{
unsigned long V_13 , V_14 ;
V_13 = F_21 ( V_25 ) ;
V_14 = F_20 ( V_25 + V_26 ) ;
return F_38 ( V_19 -> V_7 , V_13 , V_14 , 1 , V_49 ) ;
}
int T_1 F_45 ( unsigned long V_57 , unsigned long V_26 ,
int V_49 )
{
unsigned long V_13 , V_14 ;
V_13 = F_21 ( V_57 ) ;
V_14 = F_20 ( V_57 + V_26 ) ;
return F_40 ( V_13 , V_14 , 1 , V_49 ) ;
}
static unsigned long T_1 F_46 ( struct V_58 * V_7 ,
unsigned long V_33 , unsigned long V_59 )
{
unsigned long V_60 = V_7 -> V_9 ;
return F_4 ( V_60 + V_33 , V_59 ) - V_60 ;
}
static unsigned long T_1 F_47 ( struct V_58 * V_7 ,
unsigned long V_61 , unsigned long V_62 )
{
unsigned long V_60 = F_13 ( V_7 -> V_9 ) ;
return F_4 ( V_60 + V_61 , V_62 ) - V_60 ;
}
static void * T_1 F_48 ( struct V_58 * V_7 ,
unsigned long V_26 , unsigned long V_62 ,
unsigned long V_63 , unsigned long V_64 )
{
unsigned long V_65 = 0 ;
unsigned long F_41 , V_56 , V_13 , V_46 , V_66 , V_59 ;
F_14 ( L_7 ,
V_7 - V_18 , V_26 , F_6 ( V_26 ) >> V_6 ,
V_62 , V_63 , V_64 ) ;
F_39 ( ! V_26 ) ;
F_39 ( V_62 & ( V_62 - 1 ) ) ;
F_39 ( V_64 && V_63 + V_26 > V_64 ) ;
if ( ! V_7 -> V_16 )
return NULL ;
F_41 = V_7 -> V_9 ;
V_56 = V_7 -> V_17 ;
V_63 >>= V_6 ;
V_64 >>= V_6 ;
if ( V_64 && V_56 > V_64 )
V_56 = V_64 ;
if ( V_56 <= F_41 )
return NULL ;
V_59 = V_56 ( V_62 >> V_6 , 1UL ) ;
if ( V_63 && F_41 < V_63 && V_63 < V_56 )
V_13 = F_4 ( V_63 , V_59 ) ;
else
V_13 = F_4 ( F_41 , V_59 ) ;
V_46 = V_13 - V_7 -> V_9 ;
V_66 = V_56 - V_7 -> V_9 ;
if ( V_7 -> V_48 > V_46 ) {
V_65 = V_46 + 1 ;
V_46 = F_46 ( V_7 , V_7 -> V_48 , V_59 ) ;
}
while ( 1 ) {
int V_67 ;
void * V_68 ;
unsigned long V_47 , V_69 , V_70 , V_71 ;
V_72:
V_46 = F_49 ( V_7 -> V_16 , V_66 , V_46 ) ;
V_46 = F_46 ( V_7 , V_46 , V_59 ) ;
V_47 = V_46 + F_20 ( V_26 ) ;
if ( V_46 >= V_66 || V_47 > V_66 )
break;
for ( V_69 = V_46 ; V_69 < V_47 ; V_69 ++ )
if ( F_50 ( V_69 , V_7 -> V_16 ) ) {
V_46 = F_46 ( V_7 , V_69 , V_59 ) ;
if ( V_46 == V_69 )
V_46 += V_59 ;
goto V_72;
}
if ( V_7 -> V_73 & ( V_74 - 1 ) &&
F_21 ( V_7 -> V_73 ) + 1 == V_46 )
V_70 = F_47 ( V_7 , V_7 -> V_73 , V_62 ) ;
else
V_70 = F_13 ( V_46 ) ;
V_67 = F_21 ( V_70 ) < V_46 ;
V_71 = V_70 + V_26 ;
V_7 -> V_73 = V_71 ;
V_7 -> V_48 = F_20 ( V_71 ) ;
if ( F_36 ( V_7 , F_21 ( V_70 ) + V_67 ,
F_20 ( V_71 ) , V_51 ) )
F_35 () ;
V_68 = F_12 ( F_13 ( V_7 -> V_9 ) +
V_70 ) ;
memset ( V_68 , 0 , V_26 ) ;
F_51 ( V_68 , V_26 , 0 , 0 ) ;
return V_68 ;
}
if ( V_65 ) {
V_46 = F_46 ( V_7 , V_65 - 1 , V_59 ) ;
V_65 = 0 ;
goto V_72;
}
return NULL ;
}
static void * T_1 F_52 ( unsigned long V_26 ,
unsigned long V_62 ,
unsigned long V_63 ,
unsigned long V_64 )
{
T_2 * V_7 ;
void * V_68 ;
if ( F_53 ( F_54 () ) )
return F_55 ( V_26 , V_75 ) ;
F_8 (bdata, &bdata_list, list) {
if ( V_63 && V_7 -> V_17 <= F_21 ( V_63 ) )
continue;
if ( V_64 && V_7 -> V_9 >= F_21 ( V_64 ) )
break;
V_68 = F_48 ( V_7 , V_26 , V_62 , V_63 , V_64 ) ;
if ( V_68 )
return V_68 ;
}
return NULL ;
}
static void * T_1 F_56 ( unsigned long V_26 ,
unsigned long V_62 ,
unsigned long V_63 ,
unsigned long V_64 )
{
void * V_76 ;
V_77:
V_76 = F_52 ( V_26 , V_62 , V_63 , V_64 ) ;
if ( V_76 )
return V_76 ;
if ( V_63 ) {
V_63 = 0 ;
goto V_77;
}
return NULL ;
}
void * T_1 F_57 ( unsigned long V_26 , unsigned long V_62 ,
unsigned long V_63 )
{
unsigned long V_64 = 0 ;
return F_56 ( V_26 , V_62 , V_63 , V_64 ) ;
}
static void * T_1 F_58 ( unsigned long V_26 , unsigned long V_62 ,
unsigned long V_63 , unsigned long V_64 )
{
void * V_78 = F_56 ( V_26 , V_62 , V_63 , V_64 ) ;
if ( V_78 )
return V_78 ;
F_59 ( L_8 , V_26 ) ;
F_60 ( L_9 ) ;
return NULL ;
}
void * T_1 F_61 ( unsigned long V_26 , unsigned long V_62 ,
unsigned long V_63 )
{
unsigned long V_64 = 0 ;
return F_58 ( V_26 , V_62 , V_63 , V_64 ) ;
}
void * T_1 F_62 ( T_3 * V_19 ,
unsigned long V_26 , unsigned long V_62 ,
unsigned long V_63 , unsigned long V_64 )
{
void * V_76 ;
if ( F_53 ( F_54 () ) )
return F_63 ( V_26 , V_75 , V_19 -> V_79 ) ;
V_80:
if ( V_64 && V_63 + V_26 > V_64 )
V_64 = 0 ;
V_76 = F_48 ( V_19 -> V_7 , V_26 , V_62 , V_63 , V_64 ) ;
if ( V_76 )
return V_76 ;
V_76 = F_52 ( V_26 , V_62 , V_63 , V_64 ) ;
if ( V_76 )
return V_76 ;
if ( V_63 ) {
V_63 = 0 ;
goto V_80;
}
return NULL ;
}
void * T_1 F_64 ( T_3 * V_19 , unsigned long V_26 ,
unsigned long V_62 , unsigned long V_63 )
{
return F_62 ( V_19 , V_26 , V_62 , V_63 , 0 ) ;
}
void * T_1 F_65 ( T_3 * V_19 , unsigned long V_26 ,
unsigned long V_62 , unsigned long V_63 ,
unsigned long V_64 )
{
void * V_76 ;
V_76 = F_62 ( V_19 , V_26 , V_62 , V_63 , 0 ) ;
if ( V_76 )
return V_76 ;
F_59 ( L_8 , V_26 ) ;
F_60 ( L_9 ) ;
return NULL ;
}
void * T_1 F_66 ( T_3 * V_19 , unsigned long V_26 ,
unsigned long V_62 , unsigned long V_63 )
{
if ( F_53 ( F_54 () ) )
return F_63 ( V_26 , V_75 , V_19 -> V_79 ) ;
return F_65 ( V_19 , V_26 , V_62 , V_63 , 0 ) ;
}
void * T_1 F_67 ( T_3 * V_19 , unsigned long V_26 ,
unsigned long V_62 , unsigned long V_63 )
{
#ifdef F_68
unsigned long V_81 ;
if ( F_53 ( F_54 () ) )
return F_63 ( V_26 , V_75 , V_19 -> V_79 ) ;
V_81 = F_69 ( V_19 ) ;
if ( V_81 > F_68 + ( 128 >> ( 20 - V_6 ) ) &&
( V_63 >> V_6 ) < F_68 ) {
void * V_76 ;
unsigned long V_82 ;
V_82 = F_68 << V_6 ;
V_76 = F_48 ( V_19 -> V_7 , V_26 , V_62 ,
V_82 , 0 ) ;
if ( V_76 )
return V_76 ;
}
#endif
return F_66 ( V_19 , V_26 , V_62 , V_63 ) ;
}
void * T_1 F_70 ( unsigned long V_26 , unsigned long V_62 ,
unsigned long V_63 )
{
return F_58 ( V_26 , V_62 , V_63 , V_83 ) ;
}
void * T_1 F_71 ( unsigned long V_26 ,
unsigned long V_62 ,
unsigned long V_63 )
{
return F_56 ( V_26 , V_62 , V_63 ,
V_83 ) ;
}
void * T_1 F_72 ( T_3 * V_19 , unsigned long V_26 ,
unsigned long V_62 , unsigned long V_63 )
{
if ( F_53 ( F_54 () ) )
return F_63 ( V_26 , V_75 , V_19 -> V_79 ) ;
return F_65 ( V_19 , V_26 , V_62 ,
V_63 , V_83 ) ;
}
