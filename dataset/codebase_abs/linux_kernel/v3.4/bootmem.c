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
struct V_7 * V_8 ;
F_8 (iter, &bdata_list) {
T_2 * V_9 ;
V_9 = F_9 ( V_8 , T_2 , V_10 ) ;
if ( V_6 -> V_11 < V_9 -> V_11 )
break;
}
F_10 ( & V_6 -> V_10 , V_8 ) ;
}
static unsigned long T_1 F_11 ( T_2 * V_6 ,
unsigned long V_12 , unsigned long V_13 , unsigned long V_14 )
{
unsigned long V_15 ;
F_12 ( & V_13 , & V_14 ) ;
V_6 -> V_16 = F_13 ( F_14 ( V_12 ) ) ;
V_6 -> V_11 = V_13 ;
V_6 -> V_17 = V_14 ;
F_7 ( V_6 ) ;
V_15 = F_2 ( V_14 - V_13 ) ;
memset ( V_6 -> V_16 , 0xff , V_15 ) ;
F_15 ( L_1 ,
V_6 - V_18 , V_13 , V_12 , V_14 , V_15 ) ;
return V_15 ;
}
unsigned long T_1 F_16 ( T_3 * V_19 , unsigned long V_20 ,
unsigned long V_21 , unsigned long V_22 )
{
return F_11 ( V_19 -> V_6 , V_20 , V_21 , V_22 ) ;
}
unsigned long T_1 F_17 ( unsigned long V_13 , unsigned long V_3 )
{
V_23 = V_3 ;
V_24 = V_13 ;
return F_11 ( F_18 ( 0 ) -> V_6 , V_13 , 0 , V_3 ) ;
}
void T_1 F_19 ( unsigned long V_25 , unsigned long V_26 )
{
unsigned long V_27 , V_14 ;
F_20 ( F_21 ( V_25 ) , V_26 ) ;
V_27 = F_22 ( V_25 ) ;
V_14 = F_23 ( V_25 + V_26 ) ;
for (; V_27 < V_14 ; V_27 ++ ) {
F_24 ( F_25 ( V_27 ) , 0 ) ;
V_28 ++ ;
}
}
static unsigned long T_1 F_26 ( T_2 * V_6 )
{
struct V_29 * V_29 ;
unsigned long V_13 , V_14 , V_3 , V_30 = 0 ;
if ( ! V_6 -> V_16 )
return 0 ;
V_13 = V_6 -> V_11 ;
V_14 = V_6 -> V_17 ;
F_15 ( L_2 ,
V_6 - V_18 , V_13 , V_14 ) ;
while ( V_13 < V_14 ) {
unsigned long * V_31 , V_32 , V_33 ;
V_31 = V_6 -> V_16 ;
V_32 = V_13 - V_6 -> V_11 ;
V_33 = ~ V_31 [ V_32 / V_34 ] ;
if ( F_27 ( V_13 , V_34 ) && V_33 == ~ 0UL ) {
int V_35 = F_28 ( V_34 ) ;
F_24 ( F_25 ( V_13 ) , V_35 ) ;
V_30 += V_34 ;
V_13 += V_34 ;
} else {
unsigned long V_36 = 0 ;
while ( V_33 && V_36 < V_34 ) {
if ( V_33 & 1 ) {
V_29 = F_25 ( V_13 + V_36 ) ;
F_24 ( V_29 , 0 ) ;
V_30 ++ ;
}
V_33 >>= 1 ;
V_36 ++ ;
}
V_13 = F_4 ( V_13 + 1 , V_34 ) ;
}
}
V_29 = F_29 ( V_6 -> V_16 ) ;
V_3 = V_6 -> V_17 - V_6 -> V_11 ;
V_3 = F_5 ( V_3 ) ;
V_30 += V_3 ;
while ( V_3 -- )
F_24 ( V_29 ++ , 0 ) ;
F_15 ( L_3 , V_6 - V_18 , V_30 ) ;
return V_30 ;
}
unsigned long T_1 F_30 ( T_3 * V_19 )
{
F_31 ( V_19 ) ;
return F_26 ( V_19 -> V_6 ) ;
}
unsigned long T_1 F_32 ( void )
{
unsigned long V_37 = 0 ;
T_2 * V_6 ;
F_33 (bdata, &bdata_list, list)
V_37 += F_26 ( V_6 ) ;
return V_37 ;
}
static void T_1 F_34 ( T_2 * V_6 ,
unsigned long V_38 , unsigned long V_39 )
{
unsigned long V_32 ;
F_15 ( L_2 , V_6 - V_18 ,
V_38 + V_6 -> V_11 ,
V_39 + V_6 -> V_11 ) ;
if ( V_6 -> V_40 > V_38 )
V_6 -> V_40 = V_38 ;
for ( V_32 = V_38 ; V_32 < V_39 ; V_32 ++ )
if ( ! F_35 ( V_32 , V_6 -> V_16 ) )
F_36 () ;
}
static int T_1 F_37 ( T_2 * V_6 , unsigned long V_38 ,
unsigned long V_39 , int V_41 )
{
unsigned long V_32 ;
int V_42 = V_41 & V_43 ;
F_15 ( L_4 ,
V_6 - V_18 ,
V_38 + V_6 -> V_11 ,
V_39 + V_6 -> V_11 ,
V_41 ) ;
for ( V_32 = V_38 ; V_32 < V_39 ; V_32 ++ )
if ( F_38 ( V_32 , V_6 -> V_16 ) ) {
if ( V_42 ) {
F_34 ( V_6 , V_38 , V_32 ) ;
return - V_44 ;
}
F_15 ( L_5 ,
V_32 + V_6 -> V_11 ) ;
}
return 0 ;
}
static int T_1 F_39 ( T_2 * V_6 ,
unsigned long V_13 , unsigned long V_14 ,
int V_45 , int V_41 )
{
unsigned long V_38 , V_39 ;
F_15 ( L_6 ,
V_6 - V_18 , V_13 , V_14 , V_45 , V_41 ) ;
F_40 ( V_13 < V_6 -> V_11 ) ;
F_40 ( V_14 > V_6 -> V_17 ) ;
V_38 = V_13 - V_6 -> V_11 ;
V_39 = V_14 - V_6 -> V_11 ;
if ( V_45 )
return F_37 ( V_6 , V_38 , V_39 , V_41 ) ;
else
F_34 ( V_6 , V_38 , V_39 ) ;
return 0 ;
}
static int T_1 F_41 ( unsigned long V_13 , unsigned long V_14 ,
int V_45 , int V_41 )
{
unsigned long V_46 ;
T_2 * V_6 ;
V_46 = V_13 ;
F_33 (bdata, &bdata_list, list) {
int V_47 ;
unsigned long V_48 ;
if ( V_46 < V_6 -> V_11 ||
V_46 >= V_6 -> V_17 ) {
F_40 ( V_46 != V_13 ) ;
continue;
}
V_48 = F_42 ( V_6 -> V_17 , V_14 ) ;
V_47 = F_39 ( V_6 , V_46 , V_48 , V_45 , V_41 ) ;
if ( V_45 && V_47 ) {
F_41 ( V_13 , V_46 , 0 , 0 ) ;
return V_47 ;
}
if ( V_48 == V_14 )
return 0 ;
V_46 = V_6 -> V_17 ;
}
F_36 () ;
}
void T_1 F_43 ( T_3 * V_19 , unsigned long V_49 ,
unsigned long V_26 )
{
unsigned long V_13 , V_14 ;
F_20 ( F_21 ( V_49 ) , V_26 ) ;
V_13 = F_22 ( V_49 ) ;
V_14 = F_23 ( V_49 + V_26 ) ;
F_39 ( V_19 -> V_6 , V_13 , V_14 , 0 , 0 ) ;
}
void T_1 F_44 ( unsigned long V_25 , unsigned long V_26 )
{
unsigned long V_13 , V_14 ;
F_20 ( F_21 ( V_25 ) , V_26 ) ;
V_13 = F_22 ( V_25 ) ;
V_14 = F_23 ( V_25 + V_26 ) ;
F_41 ( V_13 , V_14 , 0 , 0 ) ;
}
int T_1 F_45 ( T_3 * V_19 , unsigned long V_49 ,
unsigned long V_26 , int V_41 )
{
unsigned long V_13 , V_14 ;
V_13 = F_23 ( V_49 ) ;
V_14 = F_22 ( V_49 + V_26 ) ;
return F_39 ( V_19 -> V_6 , V_13 , V_14 , 1 , V_41 ) ;
}
int T_1 F_46 ( unsigned long V_25 , unsigned long V_26 ,
int V_41 )
{
unsigned long V_13 , V_14 ;
V_13 = F_23 ( V_25 ) ;
V_14 = F_22 ( V_25 + V_26 ) ;
return F_41 ( V_13 , V_14 , 1 , V_41 ) ;
}
int __weak T_1 F_47 ( unsigned long V_50 , unsigned long V_51 ,
int V_41 )
{
return F_46 ( V_50 , V_51 , V_41 ) ;
}
static unsigned long T_1 F_48 ( struct V_52 * V_6 ,
unsigned long V_32 , unsigned long V_53 )
{
unsigned long V_54 = V_6 -> V_11 ;
return F_4 ( V_54 + V_32 , V_53 ) - V_54 ;
}
static unsigned long T_1 F_49 ( struct V_52 * V_6 ,
unsigned long V_36 , unsigned long V_55 )
{
unsigned long V_54 = F_14 ( V_6 -> V_11 ) ;
return F_4 ( V_54 + V_36 , V_55 ) - V_54 ;
}
static void * T_1 F_50 ( struct V_52 * V_6 ,
unsigned long V_26 , unsigned long V_55 ,
unsigned long V_56 , unsigned long V_57 )
{
unsigned long V_58 = 0 ;
unsigned long F_42 , V_48 , V_13 , V_38 , V_59 , V_53 ;
F_15 ( L_7 ,
V_6 - V_18 , V_26 , F_6 ( V_26 ) >> V_5 ,
V_55 , V_56 , V_57 ) ;
F_40 ( ! V_26 ) ;
F_40 ( V_55 & ( V_55 - 1 ) ) ;
F_40 ( V_57 && V_56 + V_26 > V_57 ) ;
if ( ! V_6 -> V_16 )
return NULL ;
F_42 = V_6 -> V_11 ;
V_48 = V_6 -> V_17 ;
V_56 >>= V_5 ;
V_57 >>= V_5 ;
if ( V_57 && V_48 > V_57 )
V_48 = V_57 ;
if ( V_48 <= F_42 )
return NULL ;
V_53 = V_48 ( V_55 >> V_5 , 1UL ) ;
if ( V_56 && F_42 < V_56 && V_56 < V_48 )
V_13 = F_4 ( V_56 , V_53 ) ;
else
V_13 = F_4 ( F_42 , V_53 ) ;
V_38 = V_13 - V_6 -> V_11 ;
V_59 = V_48 - V_6 -> V_11 ;
if ( V_6 -> V_40 > V_38 ) {
V_58 = V_38 + 1 ;
V_38 = F_48 ( V_6 , V_6 -> V_40 , V_53 ) ;
}
while ( 1 ) {
int V_60 ;
void * V_61 ;
unsigned long V_39 , V_62 , V_63 , V_64 ;
V_65:
V_38 = F_51 ( V_6 -> V_16 , V_59 , V_38 ) ;
V_38 = F_48 ( V_6 , V_38 , V_53 ) ;
V_39 = V_38 + F_22 ( V_26 ) ;
if ( V_38 >= V_59 || V_39 > V_59 )
break;
for ( V_62 = V_38 ; V_62 < V_39 ; V_62 ++ )
if ( F_52 ( V_62 , V_6 -> V_16 ) ) {
V_38 = F_48 ( V_6 , V_62 , V_53 ) ;
if ( V_38 == V_62 )
V_38 += V_53 ;
goto V_65;
}
if ( V_6 -> V_66 & ( V_67 - 1 ) &&
F_23 ( V_6 -> V_66 ) + 1 == V_38 )
V_63 = F_49 ( V_6 , V_6 -> V_66 , V_55 ) ;
else
V_63 = F_14 ( V_38 ) ;
V_60 = F_23 ( V_63 ) < V_38 ;
V_64 = V_63 + V_26 ;
V_6 -> V_66 = V_64 ;
V_6 -> V_40 = F_22 ( V_64 ) ;
if ( F_37 ( V_6 , F_23 ( V_63 ) + V_60 ,
F_22 ( V_64 ) , V_43 ) )
F_36 () ;
V_61 = F_13 ( F_14 ( V_6 -> V_11 ) +
V_63 ) ;
memset ( V_61 , 0 , V_26 ) ;
F_53 ( V_61 , V_26 , 0 , 0 ) ;
return V_61 ;
}
if ( V_58 ) {
V_38 = F_48 ( V_6 , V_58 - 1 , V_53 ) ;
V_58 = 0 ;
goto V_65;
}
return NULL ;
}
static void * T_1 F_54 ( T_2 * V_6 ,
unsigned long V_26 , unsigned long V_55 ,
unsigned long V_56 , unsigned long V_57 )
{
if ( F_55 ( F_56 () ) )
return F_57 ( V_26 , V_68 ) ;
#ifdef F_58
{
T_2 * V_69 ;
V_69 = F_59 ( V_6 , V_26 , V_55 ,
V_56 , V_57 ) ;
if ( V_69 )
return F_50 ( V_69 , V_26 , V_55 ,
V_56 , V_57 ) ;
}
#endif
return NULL ;
}
static void * T_1 F_60 ( unsigned long V_26 ,
unsigned long V_55 ,
unsigned long V_56 ,
unsigned long V_57 )
{
T_2 * V_6 ;
void * V_61 ;
V_70:
V_61 = F_54 ( NULL , V_26 , V_55 , V_56 , V_57 ) ;
if ( V_61 )
return V_61 ;
F_33 (bdata, &bdata_list, list) {
if ( V_56 && V_6 -> V_17 <= F_23 ( V_56 ) )
continue;
if ( V_57 && V_6 -> V_11 >= F_23 ( V_57 ) )
break;
V_61 = F_50 ( V_6 , V_26 , V_55 , V_56 , V_57 ) ;
if ( V_61 )
return V_61 ;
}
if ( V_56 ) {
V_56 = 0 ;
goto V_70;
}
return NULL ;
}
void * T_1 F_61 ( unsigned long V_26 , unsigned long V_55 ,
unsigned long V_56 )
{
unsigned long V_57 = 0 ;
return F_60 ( V_26 , V_55 , V_56 , V_57 ) ;
}
static void * T_1 F_62 ( unsigned long V_26 , unsigned long V_55 ,
unsigned long V_56 , unsigned long V_57 )
{
void * V_71 = F_60 ( V_26 , V_55 , V_56 , V_57 ) ;
if ( V_71 )
return V_71 ;
F_63 ( V_72 L_8 , V_26 ) ;
F_64 ( L_9 ) ;
return NULL ;
}
void * T_1 F_65 ( unsigned long V_26 , unsigned long V_55 ,
unsigned long V_56 )
{
unsigned long V_57 = 0 ;
return F_62 ( V_26 , V_55 , V_56 , V_57 ) ;
}
static void * T_1 F_66 ( T_2 * V_6 ,
unsigned long V_26 , unsigned long V_55 ,
unsigned long V_56 , unsigned long V_57 )
{
void * V_73 ;
V_73 = F_54 ( V_6 , V_26 , V_55 , V_56 , V_57 ) ;
if ( V_73 )
return V_73 ;
V_73 = F_50 ( V_6 , V_26 , V_55 , V_56 , V_57 ) ;
if ( V_73 )
return V_73 ;
return F_62 ( V_26 , V_55 , V_56 , V_57 ) ;
}
void * T_1 F_67 ( T_3 * V_19 , unsigned long V_26 ,
unsigned long V_55 , unsigned long V_56 )
{
if ( F_55 ( F_56 () ) )
return F_68 ( V_26 , V_68 , V_19 -> V_74 ) ;
return F_66 ( V_19 -> V_6 , V_26 , V_55 , V_56 , 0 ) ;
}
void * T_1 F_69 ( T_3 * V_19 , unsigned long V_26 ,
unsigned long V_55 , unsigned long V_56 )
{
#ifdef F_70
unsigned long V_75 ;
if ( F_55 ( F_56 () ) )
return F_68 ( V_26 , V_68 , V_19 -> V_74 ) ;
V_75 = V_19 -> V_76 + V_19 -> V_77 ;
if ( V_75 > F_70 + ( 128 >> ( 20 - V_5 ) ) &&
( V_56 >> V_5 ) < F_70 ) {
void * V_73 ;
unsigned long V_78 ;
V_78 = F_70 << V_5 ;
V_73 = F_50 ( V_19 -> V_6 , V_26 , V_55 ,
V_78 , 0 ) ;
if ( V_73 )
return V_73 ;
}
#endif
return F_67 ( V_19 , V_26 , V_55 , V_56 ) ;
}
void * T_1 F_71 ( unsigned long V_26 ,
unsigned long V_79 )
{
T_2 * V_6 ;
unsigned long V_80 , V_56 ;
V_80 = F_72 ( V_79 ) ;
V_56 = V_80 << V_5 ;
V_6 = & V_18 [ F_73 ( V_80 ) ] ;
return F_50 ( V_6 , V_26 , V_81 , V_56 , 0 ) ;
}
void * T_1 F_74 ( T_3 * V_19 , unsigned long V_26 ,
unsigned long V_55 , unsigned long V_56 )
{
void * V_73 ;
if ( F_55 ( F_56 () ) )
return F_68 ( V_26 , V_68 , V_19 -> V_74 ) ;
V_73 = F_54 ( V_19 -> V_6 , V_26 , V_55 , V_56 , 0 ) ;
if ( V_73 )
return V_73 ;
V_73 = F_50 ( V_19 -> V_6 , V_26 , V_55 , V_56 , 0 ) ;
if ( V_73 )
return V_73 ;
return F_61 ( V_26 , V_55 , V_56 ) ;
}
void * T_1 F_75 ( unsigned long V_26 , unsigned long V_55 ,
unsigned long V_56 )
{
return F_62 ( V_26 , V_55 , V_56 , V_82 ) ;
}
void * T_1 F_76 ( T_3 * V_19 , unsigned long V_26 ,
unsigned long V_55 , unsigned long V_56 )
{
if ( F_55 ( F_56 () ) )
return F_68 ( V_26 , V_68 , V_19 -> V_74 ) ;
return F_66 ( V_19 -> V_6 , V_26 , V_55 ,
V_56 , V_82 ) ;
}
