static int T_1 F_1 ( char * V_1 )
{
V_2 = 1 ;
return 0 ;
}
static unsigned long T_1 F_2 ( unsigned long V_3 )
{
unsigned long V_4 = F_3 ( V_3 , 8 ) ;
return F_4 ( V_4 , sizeof( long ) ) ;
}
unsigned long T_1 F_5 ( unsigned long V_3 )
{
unsigned long V_4 = F_2 ( V_3 ) ;
return F_6 ( V_4 ) >> V_5 ;
}
static void T_1 F_7 ( T_2 * V_6 )
{
T_2 * V_7 ;
F_8 (ent, &bdata_list, list) {
if ( V_6 -> V_8 < V_7 -> V_8 ) {
F_9 ( & V_6 -> V_9 , & V_7 -> V_9 ) ;
return;
}
}
F_9 ( & V_6 -> V_9 , & V_10 ) ;
}
static unsigned long T_1 F_10 ( T_2 * V_6 ,
unsigned long V_11 , unsigned long V_12 , unsigned long V_13 )
{
unsigned long V_14 ;
F_11 ( & V_12 , & V_13 ) ;
V_6 -> V_15 = F_12 ( F_13 ( V_11 ) ) ;
V_6 -> V_8 = V_12 ;
V_6 -> V_16 = V_13 ;
F_7 ( V_6 ) ;
V_14 = F_2 ( V_13 - V_12 ) ;
memset ( V_6 -> V_15 , 0xff , V_14 ) ;
F_14 ( L_1 ,
V_6 - V_17 , V_12 , V_11 , V_13 , V_14 ) ;
return V_14 ;
}
unsigned long T_1 F_15 ( T_3 * V_18 , unsigned long V_19 ,
unsigned long V_20 , unsigned long V_21 )
{
return F_10 ( V_18 -> V_6 , V_19 , V_20 , V_21 ) ;
}
unsigned long T_1 F_16 ( unsigned long V_12 , unsigned long V_3 )
{
V_22 = V_3 ;
V_23 = V_12 ;
return F_10 ( F_17 ( 0 ) -> V_6 , V_12 , 0 , V_3 ) ;
}
void T_1 F_18 ( unsigned long V_24 , unsigned long V_25 )
{
unsigned long V_26 , V_13 ;
F_19 ( F_20 ( V_24 ) , V_25 ) ;
V_26 = F_21 ( V_24 ) ;
V_13 = F_22 ( V_24 + V_25 ) ;
for (; V_26 < V_13 ; V_26 ++ ) {
F_23 ( F_24 ( V_26 ) , V_26 , 0 ) ;
V_27 ++ ;
}
}
static unsigned long T_1 F_25 ( T_2 * V_6 )
{
struct V_28 * V_28 ;
unsigned long * V_29 , V_12 , V_13 , V_3 , V_30 , V_31 = 0 ;
if ( ! V_6 -> V_15 )
return 0 ;
V_29 = V_6 -> V_15 ;
V_12 = V_6 -> V_8 ;
V_13 = V_6 -> V_16 ;
F_14 ( L_2 ,
V_6 - V_17 , V_12 , V_13 ) ;
while ( V_12 < V_13 ) {
unsigned long V_32 , V_33 ;
unsigned V_34 ;
V_32 = V_12 - V_6 -> V_8 ;
V_34 = V_32 & ( V_35 - 1 ) ;
V_33 = ~ V_29 [ V_32 / V_35 ] ;
if ( V_34 ) {
V_33 >>= V_34 ;
if ( V_13 - V_12 >= V_35 )
V_33 |= ~ V_29 [ V_32 / V_35 + 1 ] <<
( V_35 - V_34 ) ;
}
if ( F_26 ( V_12 , V_35 ) && V_33 == ~ 0UL ) {
int V_36 = F_27 ( V_35 ) ;
F_23 ( F_24 ( V_12 ) , V_12 , V_36 ) ;
V_31 += V_35 ;
V_12 += V_35 ;
} else {
V_30 = V_12 ;
V_12 = F_4 ( V_12 + 1 , V_35 ) ;
while ( V_33 && V_30 != V_12 ) {
if ( V_33 & 1 ) {
V_28 = F_24 ( V_30 ) ;
F_23 ( V_28 , V_30 , 0 ) ;
V_31 ++ ;
}
V_33 >>= 1 ;
++ V_30 ;
}
}
}
V_30 = V_6 -> V_8 ;
V_28 = F_28 ( V_6 -> V_15 ) ;
V_3 = V_6 -> V_16 - V_6 -> V_8 ;
V_3 = F_5 ( V_3 ) ;
V_31 += V_3 ;
while ( V_3 -- )
F_23 ( V_28 ++ , V_30 ++ , 0 ) ;
V_6 -> V_15 = NULL ;
F_14 ( L_3 , V_6 - V_17 , V_31 ) ;
return V_31 ;
}
void F_29 ( T_3 * V_18 )
{
struct V_37 * V_38 ;
for ( V_38 = V_18 -> V_39 ; V_38 < V_18 -> V_39 + V_40 ; V_38 ++ )
V_38 -> V_41 = 0 ;
}
void T_1 F_30 ( void )
{
struct V_42 * V_18 ;
if ( V_43 )
return;
F_31 (pgdat)
F_29 ( V_18 ) ;
V_43 = 1 ;
}
unsigned long T_1 F_32 ( void )
{
unsigned long V_44 = 0 ;
T_2 * V_6 ;
F_30 () ;
F_8 (bdata, &bdata_list, list)
V_44 += F_25 ( V_6 ) ;
V_27 += V_44 ;
return V_44 ;
}
static void T_1 F_33 ( T_2 * V_6 ,
unsigned long V_45 , unsigned long V_46 )
{
unsigned long V_32 ;
F_14 ( L_2 , V_6 - V_17 ,
V_45 + V_6 -> V_8 ,
V_46 + V_6 -> V_8 ) ;
if ( F_34 ( V_6 -> V_15 == NULL ) )
return;
if ( V_6 -> V_47 > V_45 )
V_6 -> V_47 = V_45 ;
for ( V_32 = V_45 ; V_32 < V_46 ; V_32 ++ )
if ( ! F_35 ( V_32 , V_6 -> V_15 ) )
F_36 () ;
}
static int T_1 F_37 ( T_2 * V_6 , unsigned long V_45 ,
unsigned long V_46 , int V_48 )
{
unsigned long V_32 ;
int V_49 = V_48 & V_50 ;
F_14 ( L_4 ,
V_6 - V_17 ,
V_45 + V_6 -> V_8 ,
V_46 + V_6 -> V_8 ,
V_48 ) ;
if ( F_34 ( V_6 -> V_15 == NULL ) )
return 0 ;
for ( V_32 = V_45 ; V_32 < V_46 ; V_32 ++ )
if ( F_38 ( V_32 , V_6 -> V_15 ) ) {
if ( V_49 ) {
F_33 ( V_6 , V_45 , V_32 ) ;
return - V_51 ;
}
F_14 ( L_5 ,
V_32 + V_6 -> V_8 ) ;
}
return 0 ;
}
static int T_1 F_39 ( T_2 * V_6 ,
unsigned long V_12 , unsigned long V_13 ,
int V_52 , int V_48 )
{
unsigned long V_45 , V_46 ;
F_14 ( L_6 ,
V_6 - V_17 , V_12 , V_13 , V_52 , V_48 ) ;
F_40 ( V_12 < V_6 -> V_8 ) ;
F_40 ( V_13 > V_6 -> V_16 ) ;
V_45 = V_12 - V_6 -> V_8 ;
V_46 = V_13 - V_6 -> V_8 ;
if ( V_52 )
return F_37 ( V_6 , V_45 , V_46 , V_48 ) ;
else
F_33 ( V_6 , V_45 , V_46 ) ;
return 0 ;
}
static int T_1 F_41 ( unsigned long V_12 , unsigned long V_13 ,
int V_52 , int V_48 )
{
unsigned long V_53 ;
T_2 * V_6 ;
V_53 = V_12 ;
F_8 (bdata, &bdata_list, list) {
int V_54 ;
unsigned long V_55 ;
if ( V_53 < V_6 -> V_8 ||
V_53 >= V_6 -> V_16 ) {
F_40 ( V_53 != V_12 ) ;
continue;
}
V_55 = F_42 ( V_6 -> V_16 , V_13 ) ;
V_54 = F_39 ( V_6 , V_53 , V_55 , V_52 , V_48 ) ;
if ( V_52 && V_54 ) {
F_41 ( V_12 , V_53 , 0 , 0 ) ;
return V_54 ;
}
if ( V_55 == V_13 )
return 0 ;
V_53 = V_6 -> V_16 ;
}
F_36 () ;
}
void T_1 F_43 ( T_3 * V_18 , unsigned long V_24 ,
unsigned long V_25 )
{
unsigned long V_12 , V_13 ;
F_19 ( F_20 ( V_24 ) , V_25 ) ;
V_12 = F_21 ( V_24 ) ;
V_13 = F_22 ( V_24 + V_25 ) ;
F_39 ( V_18 -> V_6 , V_12 , V_13 , 0 , 0 ) ;
}
void T_1 F_44 ( unsigned long V_24 , unsigned long V_25 )
{
unsigned long V_12 , V_13 ;
F_19 ( F_20 ( V_24 ) , V_25 ) ;
V_12 = F_21 ( V_24 ) ;
V_13 = F_22 ( V_24 + V_25 ) ;
F_41 ( V_12 , V_13 , 0 , 0 ) ;
}
int T_1 F_45 ( T_3 * V_18 , unsigned long V_24 ,
unsigned long V_25 , int V_48 )
{
unsigned long V_12 , V_13 ;
V_12 = F_22 ( V_24 ) ;
V_13 = F_21 ( V_24 + V_25 ) ;
return F_39 ( V_18 -> V_6 , V_12 , V_13 , 1 , V_48 ) ;
}
int T_1 F_46 ( unsigned long V_56 , unsigned long V_25 ,
int V_48 )
{
unsigned long V_12 , V_13 ;
V_12 = F_22 ( V_56 ) ;
V_13 = F_21 ( V_56 + V_25 ) ;
return F_41 ( V_12 , V_13 , 1 , V_48 ) ;
}
static unsigned long T_1 F_47 ( struct V_57 * V_6 ,
unsigned long V_32 , unsigned long V_58 )
{
unsigned long V_59 = V_6 -> V_8 ;
return F_4 ( V_59 + V_32 , V_58 ) - V_59 ;
}
static unsigned long T_1 F_48 ( struct V_57 * V_6 ,
unsigned long V_60 , unsigned long V_61 )
{
unsigned long V_59 = F_13 ( V_6 -> V_8 ) ;
return F_4 ( V_59 + V_60 , V_61 ) - V_59 ;
}
static void * T_1 F_49 ( struct V_57 * V_6 ,
unsigned long V_25 , unsigned long V_61 ,
unsigned long V_62 , unsigned long V_63 )
{
unsigned long V_64 = 0 ;
unsigned long F_42 , V_55 , V_12 , V_45 , V_65 , V_58 ;
F_14 ( L_7 ,
V_6 - V_17 , V_25 , F_6 ( V_25 ) >> V_5 ,
V_61 , V_62 , V_63 ) ;
F_40 ( ! V_25 ) ;
F_40 ( V_61 & ( V_61 - 1 ) ) ;
F_40 ( V_63 && V_62 + V_25 > V_63 ) ;
if ( ! V_6 -> V_15 )
return NULL ;
F_42 = V_6 -> V_8 ;
V_55 = V_6 -> V_16 ;
V_62 >>= V_5 ;
V_63 >>= V_5 ;
if ( V_63 && V_55 > V_63 )
V_55 = V_63 ;
if ( V_55 <= F_42 )
return NULL ;
V_58 = V_55 ( V_61 >> V_5 , 1UL ) ;
if ( V_62 && F_42 < V_62 && V_62 < V_55 )
V_12 = F_4 ( V_62 , V_58 ) ;
else
V_12 = F_4 ( F_42 , V_58 ) ;
V_45 = V_12 - V_6 -> V_8 ;
V_65 = V_55 - V_6 -> V_8 ;
if ( V_6 -> V_47 > V_45 ) {
V_64 = V_45 + 1 ;
V_45 = F_47 ( V_6 , V_6 -> V_47 , V_58 ) ;
}
while ( 1 ) {
int V_66 ;
void * V_67 ;
unsigned long V_46 , V_68 , V_69 , V_70 ;
V_71:
V_45 = F_50 ( V_6 -> V_15 , V_65 , V_45 ) ;
V_45 = F_47 ( V_6 , V_45 , V_58 ) ;
V_46 = V_45 + F_21 ( V_25 ) ;
if ( V_45 >= V_65 || V_46 > V_65 )
break;
for ( V_68 = V_45 ; V_68 < V_46 ; V_68 ++ )
if ( F_51 ( V_68 , V_6 -> V_15 ) ) {
V_45 = F_47 ( V_6 , V_68 , V_58 ) ;
if ( V_45 == V_68 )
V_45 += V_58 ;
goto V_71;
}
if ( V_6 -> V_72 & ( V_73 - 1 ) &&
F_22 ( V_6 -> V_72 ) + 1 == V_45 )
V_69 = F_48 ( V_6 , V_6 -> V_72 , V_61 ) ;
else
V_69 = F_13 ( V_45 ) ;
V_66 = F_22 ( V_69 ) < V_45 ;
V_70 = V_69 + V_25 ;
V_6 -> V_72 = V_70 ;
V_6 -> V_47 = F_21 ( V_70 ) ;
if ( F_37 ( V_6 , F_22 ( V_69 ) + V_66 ,
F_21 ( V_70 ) , V_50 ) )
F_36 () ;
V_67 = F_12 ( F_13 ( V_6 -> V_8 ) +
V_69 ) ;
memset ( V_67 , 0 , V_25 ) ;
F_52 ( V_67 , V_25 , 0 , 0 ) ;
return V_67 ;
}
if ( V_64 ) {
V_45 = F_47 ( V_6 , V_64 - 1 , V_58 ) ;
V_64 = 0 ;
goto V_71;
}
return NULL ;
}
static void * T_1 F_53 ( unsigned long V_25 ,
unsigned long V_61 ,
unsigned long V_62 ,
unsigned long V_63 )
{
T_2 * V_6 ;
void * V_67 ;
if ( F_54 ( F_55 () ) )
return F_56 ( V_25 , V_74 ) ;
F_8 (bdata, &bdata_list, list) {
if ( V_62 && V_6 -> V_16 <= F_22 ( V_62 ) )
continue;
if ( V_63 && V_6 -> V_8 >= F_22 ( V_63 ) )
break;
V_67 = F_49 ( V_6 , V_25 , V_61 , V_62 , V_63 ) ;
if ( V_67 )
return V_67 ;
}
return NULL ;
}
static void * T_1 F_57 ( unsigned long V_25 ,
unsigned long V_61 ,
unsigned long V_62 ,
unsigned long V_63 )
{
void * V_75 ;
V_76:
V_75 = F_53 ( V_25 , V_61 , V_62 , V_63 ) ;
if ( V_75 )
return V_75 ;
if ( V_62 ) {
V_62 = 0 ;
goto V_76;
}
return NULL ;
}
void * T_1 F_58 ( unsigned long V_25 , unsigned long V_61 ,
unsigned long V_62 )
{
unsigned long V_63 = 0 ;
return F_57 ( V_25 , V_61 , V_62 , V_63 ) ;
}
static void * T_1 F_59 ( unsigned long V_25 , unsigned long V_61 ,
unsigned long V_62 , unsigned long V_63 )
{
void * V_77 = F_57 ( V_25 , V_61 , V_62 , V_63 ) ;
if ( V_77 )
return V_77 ;
F_60 ( L_8 , V_25 ) ;
F_61 ( L_9 ) ;
return NULL ;
}
void * T_1 F_62 ( unsigned long V_25 , unsigned long V_61 ,
unsigned long V_62 )
{
unsigned long V_63 = 0 ;
return F_59 ( V_25 , V_61 , V_62 , V_63 ) ;
}
void * T_1 F_63 ( T_3 * V_18 ,
unsigned long V_25 , unsigned long V_61 ,
unsigned long V_62 , unsigned long V_63 )
{
void * V_75 ;
if ( F_54 ( F_55 () ) )
return F_56 ( V_25 , V_74 ) ;
V_78:
if ( V_63 && V_62 + V_25 > V_63 )
V_63 = 0 ;
V_75 = F_49 ( V_18 -> V_6 , V_25 , V_61 , V_62 , V_63 ) ;
if ( V_75 )
return V_75 ;
V_75 = F_53 ( V_25 , V_61 , V_62 , V_63 ) ;
if ( V_75 )
return V_75 ;
if ( V_62 ) {
V_62 = 0 ;
goto V_78;
}
return NULL ;
}
void * T_1 F_64 ( T_3 * V_18 , unsigned long V_25 ,
unsigned long V_61 , unsigned long V_62 )
{
if ( F_54 ( F_55 () ) )
return F_65 ( V_25 , V_74 , V_18 -> V_79 ) ;
return F_63 ( V_18 , V_25 , V_61 , V_62 , 0 ) ;
}
void * T_1 F_66 ( T_3 * V_18 , unsigned long V_25 ,
unsigned long V_61 , unsigned long V_62 ,
unsigned long V_63 )
{
void * V_75 ;
V_75 = F_63 ( V_18 , V_25 , V_61 , V_62 , 0 ) ;
if ( V_75 )
return V_75 ;
F_60 ( L_8 , V_25 ) ;
F_61 ( L_9 ) ;
return NULL ;
}
void * T_1 F_67 ( T_3 * V_18 , unsigned long V_25 ,
unsigned long V_61 , unsigned long V_62 )
{
if ( F_54 ( F_55 () ) )
return F_65 ( V_25 , V_74 , V_18 -> V_79 ) ;
return F_66 ( V_18 , V_25 , V_61 , V_62 , 0 ) ;
}
void * T_1 F_68 ( T_3 * V_18 , unsigned long V_25 ,
unsigned long V_61 , unsigned long V_62 )
{
#ifdef F_69
unsigned long V_80 ;
if ( F_54 ( F_55 () ) )
return F_65 ( V_25 , V_74 , V_18 -> V_79 ) ;
V_80 = F_70 ( V_18 ) ;
if ( V_80 > F_69 + ( 128 >> ( 20 - V_5 ) ) &&
( V_62 >> V_5 ) < F_69 ) {
void * V_75 ;
unsigned long V_81 ;
V_81 = F_69 << V_5 ;
V_75 = F_49 ( V_18 -> V_6 , V_25 , V_61 ,
V_81 , 0 ) ;
if ( V_75 )
return V_75 ;
}
#endif
return F_67 ( V_18 , V_25 , V_61 , V_62 ) ;
}
void * T_1 F_71 ( unsigned long V_25 , unsigned long V_61 ,
unsigned long V_62 )
{
return F_59 ( V_25 , V_61 , V_62 , V_82 ) ;
}
void * T_1 F_72 ( unsigned long V_25 ,
unsigned long V_61 ,
unsigned long V_62 )
{
return F_57 ( V_25 , V_61 , V_62 ,
V_82 ) ;
}
void * T_1 F_73 ( T_3 * V_18 , unsigned long V_25 ,
unsigned long V_61 , unsigned long V_62 )
{
if ( F_54 ( F_55 () ) )
return F_65 ( V_25 , V_74 , V_18 -> V_79 ) ;
return F_66 ( V_18 , V_25 , V_61 ,
V_62 , V_82 ) ;
}
