static int T_1 F_1 ( char * V_1 )
{
V_2 = 1 ;
return 0 ;
}
static unsigned long T_1 F_2 ( unsigned long V_3 )
{
unsigned long V_4 = ( V_3 + 7 ) / 8 ;
return F_3 ( V_4 , sizeof( long ) ) ;
}
unsigned long T_1 F_4 ( unsigned long V_3 )
{
unsigned long V_4 = F_2 ( V_3 ) ;
return F_5 ( V_4 ) >> V_5 ;
}
static void T_1 F_6 ( T_2 * V_6 )
{
struct V_7 * V_8 ;
F_7 (iter, &bdata_list) {
T_2 * V_9 ;
V_9 = F_8 ( V_8 , T_2 , V_10 ) ;
if ( V_6 -> V_11 < V_9 -> V_11 )
break;
}
F_9 ( & V_6 -> V_10 , V_8 ) ;
}
static unsigned long T_1 F_10 ( T_2 * V_6 ,
unsigned long V_12 , unsigned long V_13 , unsigned long V_14 )
{
unsigned long V_15 ;
F_11 ( & V_13 , & V_14 ) ;
V_6 -> V_16 = F_12 ( F_13 ( V_12 ) ) ;
V_6 -> V_11 = V_13 ;
V_6 -> V_17 = V_14 ;
F_6 ( V_6 ) ;
V_15 = F_2 ( V_14 - V_13 ) ;
memset ( V_6 -> V_16 , 0xff , V_15 ) ;
F_14 ( L_1 ,
V_6 - V_18 , V_13 , V_12 , V_14 , V_15 ) ;
return V_15 ;
}
unsigned long T_1 F_15 ( T_3 * V_19 , unsigned long V_20 ,
unsigned long V_21 , unsigned long V_22 )
{
return F_10 ( V_19 -> V_6 , V_20 , V_21 , V_22 ) ;
}
unsigned long T_1 F_16 ( unsigned long V_13 , unsigned long V_3 )
{
V_23 = V_3 ;
V_24 = V_13 ;
return F_10 ( F_17 ( 0 ) -> V_6 , V_13 , 0 , V_3 ) ;
}
void T_1 F_18 ( unsigned long V_25 , unsigned long V_26 )
{
unsigned long V_27 , V_14 ;
F_19 ( F_20 ( V_25 ) , V_26 ) ;
V_27 = F_21 ( V_25 ) ;
V_14 = F_22 ( V_25 + V_26 ) ;
for (; V_27 < V_14 ; V_27 ++ ) {
F_23 ( F_24 ( V_27 ) , 0 ) ;
V_28 ++ ;
}
}
static unsigned long T_1 F_25 ( T_2 * V_6 )
{
int V_29 ;
struct V_30 * V_30 ;
unsigned long V_13 , V_14 , V_3 , V_31 = 0 ;
if ( ! V_6 -> V_16 )
return 0 ;
V_13 = V_6 -> V_11 ;
V_14 = V_6 -> V_17 ;
V_29 = ! ( V_13 & ( V_32 - 1 ) ) ;
F_14 ( L_2 ,
V_6 - V_18 , V_13 , V_14 , V_29 ) ;
while ( V_13 < V_14 ) {
unsigned long * V_33 , V_34 , V_35 ;
V_33 = V_6 -> V_16 ;
V_34 = V_13 - V_6 -> V_11 ;
V_35 = ~ V_33 [ V_34 / V_32 ] ;
if ( V_29 && V_35 == ~ 0UL && V_13 + V_32 < V_14 ) {
int V_36 = F_26 ( V_32 ) ;
F_23 ( F_24 ( V_13 ) , V_36 ) ;
V_31 += V_32 ;
} else {
unsigned long V_37 = 0 ;
while ( V_35 && V_37 < V_32 ) {
if ( V_35 & 1 ) {
V_30 = F_24 ( V_13 + V_37 ) ;
F_23 ( V_30 , 0 ) ;
V_31 ++ ;
}
V_35 >>= 1 ;
V_37 ++ ;
}
}
V_13 += V_32 ;
}
V_30 = F_27 ( V_6 -> V_16 ) ;
V_3 = V_6 -> V_17 - V_6 -> V_11 ;
V_3 = F_4 ( V_3 ) ;
V_31 += V_3 ;
while ( V_3 -- )
F_23 ( V_30 ++ , 0 ) ;
F_14 ( L_3 , V_6 - V_18 , V_31 ) ;
return V_31 ;
}
unsigned long T_1 F_28 ( T_3 * V_19 )
{
F_29 ( V_19 ) ;
return F_25 ( V_19 -> V_6 ) ;
}
unsigned long T_1 F_30 ( void )
{
unsigned long V_38 = 0 ;
T_2 * V_6 ;
F_31 (bdata, &bdata_list, list)
V_38 += F_25 ( V_6 ) ;
return V_38 ;
}
static void T_1 F_32 ( T_2 * V_6 ,
unsigned long V_39 , unsigned long V_40 )
{
unsigned long V_34 ;
F_14 ( L_4 , V_6 - V_18 ,
V_39 + V_6 -> V_11 ,
V_40 + V_6 -> V_11 ) ;
if ( V_6 -> V_41 > V_39 )
V_6 -> V_41 = V_39 ;
for ( V_34 = V_39 ; V_34 < V_40 ; V_34 ++ )
if ( ! F_33 ( V_34 , V_6 -> V_16 ) )
F_34 () ;
}
static int T_1 F_35 ( T_2 * V_6 , unsigned long V_39 ,
unsigned long V_40 , int V_42 )
{
unsigned long V_34 ;
int V_43 = V_42 & V_44 ;
F_14 ( L_5 ,
V_6 - V_18 ,
V_39 + V_6 -> V_11 ,
V_40 + V_6 -> V_11 ,
V_42 ) ;
for ( V_34 = V_39 ; V_34 < V_40 ; V_34 ++ )
if ( F_36 ( V_34 , V_6 -> V_16 ) ) {
if ( V_43 ) {
F_32 ( V_6 , V_39 , V_34 ) ;
return - V_45 ;
}
F_14 ( L_6 ,
V_34 + V_6 -> V_11 ) ;
}
return 0 ;
}
static int T_1 F_37 ( T_2 * V_6 ,
unsigned long V_13 , unsigned long V_14 ,
int V_46 , int V_42 )
{
unsigned long V_39 , V_40 ;
F_14 ( L_7 ,
V_6 - V_18 , V_13 , V_14 , V_46 , V_42 ) ;
F_38 ( V_13 < V_6 -> V_11 ) ;
F_38 ( V_14 > V_6 -> V_17 ) ;
V_39 = V_13 - V_6 -> V_11 ;
V_40 = V_14 - V_6 -> V_11 ;
if ( V_46 )
return F_35 ( V_6 , V_39 , V_40 , V_42 ) ;
else
F_32 ( V_6 , V_39 , V_40 ) ;
return 0 ;
}
static int T_1 F_39 ( unsigned long V_13 , unsigned long V_14 ,
int V_46 , int V_42 )
{
unsigned long V_47 ;
T_2 * V_6 ;
V_47 = V_13 ;
F_31 (bdata, &bdata_list, list) {
int V_48 ;
unsigned long V_49 ;
if ( V_47 < V_6 -> V_11 ||
V_47 >= V_6 -> V_17 ) {
F_38 ( V_47 != V_13 ) ;
continue;
}
V_49 = F_40 ( V_6 -> V_17 , V_14 ) ;
V_48 = F_37 ( V_6 , V_47 , V_49 , V_46 , V_42 ) ;
if ( V_46 && V_48 ) {
F_39 ( V_13 , V_47 , 0 , 0 ) ;
return V_48 ;
}
if ( V_49 == V_14 )
return 0 ;
V_47 = V_6 -> V_17 ;
}
F_34 () ;
}
void T_1 F_41 ( T_3 * V_19 , unsigned long V_50 ,
unsigned long V_26 )
{
unsigned long V_13 , V_14 ;
F_19 ( F_20 ( V_50 ) , V_26 ) ;
V_13 = F_21 ( V_50 ) ;
V_14 = F_22 ( V_50 + V_26 ) ;
F_37 ( V_19 -> V_6 , V_13 , V_14 , 0 , 0 ) ;
}
void T_1 F_42 ( unsigned long V_25 , unsigned long V_26 )
{
unsigned long V_13 , V_14 ;
F_19 ( F_20 ( V_25 ) , V_26 ) ;
V_13 = F_21 ( V_25 ) ;
V_14 = F_22 ( V_25 + V_26 ) ;
F_39 ( V_13 , V_14 , 0 , 0 ) ;
}
int T_1 F_43 ( T_3 * V_19 , unsigned long V_50 ,
unsigned long V_26 , int V_42 )
{
unsigned long V_13 , V_14 ;
V_13 = F_22 ( V_50 ) ;
V_14 = F_21 ( V_50 + V_26 ) ;
return F_37 ( V_19 -> V_6 , V_13 , V_14 , 1 , V_42 ) ;
}
int T_1 F_44 ( unsigned long V_25 , unsigned long V_26 ,
int V_42 )
{
unsigned long V_13 , V_14 ;
V_13 = F_22 ( V_25 ) ;
V_14 = F_21 ( V_25 + V_26 ) ;
return F_39 ( V_13 , V_14 , 1 , V_42 ) ;
}
int __weak T_1 F_45 ( unsigned long V_51 , unsigned long V_52 ,
int V_42 )
{
return F_44 ( V_51 , V_52 , V_42 ) ;
}
static unsigned long T_1 F_46 ( struct V_53 * V_6 ,
unsigned long V_34 , unsigned long V_54 )
{
unsigned long V_55 = V_6 -> V_11 ;
return F_3 ( V_55 + V_34 , V_54 ) - V_55 ;
}
static unsigned long T_1 F_47 ( struct V_53 * V_6 ,
unsigned long V_37 , unsigned long V_56 )
{
unsigned long V_55 = F_13 ( V_6 -> V_11 ) ;
return F_3 ( V_55 + V_37 , V_56 ) - V_55 ;
}
static void * T_1 F_48 ( struct V_53 * V_6 ,
unsigned long V_26 , unsigned long V_56 ,
unsigned long V_57 , unsigned long V_58 )
{
unsigned long V_59 = 0 ;
unsigned long F_40 , V_49 , V_13 , V_39 , V_60 , V_54 ;
F_14 ( L_8 ,
V_6 - V_18 , V_26 , F_5 ( V_26 ) >> V_5 ,
V_56 , V_57 , V_58 ) ;
F_38 ( ! V_26 ) ;
F_38 ( V_56 & ( V_56 - 1 ) ) ;
F_38 ( V_58 && V_57 + V_26 > V_58 ) ;
if ( ! V_6 -> V_16 )
return NULL ;
F_40 = V_6 -> V_11 ;
V_49 = V_6 -> V_17 ;
V_57 >>= V_5 ;
V_58 >>= V_5 ;
if ( V_58 && V_49 > V_58 )
V_49 = V_58 ;
if ( V_49 <= F_40 )
return NULL ;
V_54 = V_49 ( V_56 >> V_5 , 1UL ) ;
if ( V_57 && F_40 < V_57 && V_57 < V_49 )
V_13 = F_3 ( V_57 , V_54 ) ;
else
V_13 = F_3 ( F_40 , V_54 ) ;
V_39 = V_13 - V_6 -> V_11 ;
V_60 = V_49 - V_6 -> V_11 ;
if ( V_6 -> V_41 > V_39 ) {
V_59 = V_39 + 1 ;
V_39 = F_46 ( V_6 , V_6 -> V_41 , V_54 ) ;
}
while ( 1 ) {
int V_61 ;
void * V_62 ;
unsigned long V_40 , V_63 , V_64 , V_65 ;
V_66:
V_39 = F_49 ( V_6 -> V_16 , V_60 , V_39 ) ;
V_39 = F_46 ( V_6 , V_39 , V_54 ) ;
V_40 = V_39 + F_21 ( V_26 ) ;
if ( V_39 >= V_60 || V_40 > V_60 )
break;
for ( V_63 = V_39 ; V_63 < V_40 ; V_63 ++ )
if ( F_50 ( V_63 , V_6 -> V_16 ) ) {
V_39 = F_46 ( V_6 , V_63 , V_54 ) ;
if ( V_39 == V_63 )
V_39 += V_54 ;
goto V_66;
}
if ( V_6 -> V_67 & ( V_68 - 1 ) &&
F_22 ( V_6 -> V_67 ) + 1 == V_39 )
V_64 = F_47 ( V_6 , V_6 -> V_67 , V_56 ) ;
else
V_64 = F_13 ( V_39 ) ;
V_61 = F_22 ( V_64 ) < V_39 ;
V_65 = V_64 + V_26 ;
V_6 -> V_67 = V_65 ;
V_6 -> V_41 = F_21 ( V_65 ) ;
if ( F_35 ( V_6 , F_22 ( V_64 ) + V_61 ,
F_21 ( V_65 ) , V_44 ) )
F_34 () ;
V_62 = F_12 ( F_13 ( V_6 -> V_11 ) +
V_64 ) ;
memset ( V_62 , 0 , V_26 ) ;
F_51 ( V_62 , V_26 , 0 , 0 ) ;
return V_62 ;
}
if ( V_59 ) {
V_39 = F_46 ( V_6 , V_59 - 1 , V_54 ) ;
V_59 = 0 ;
goto V_66;
}
return NULL ;
}
static void * T_1 F_52 ( T_2 * V_6 ,
unsigned long V_26 , unsigned long V_56 ,
unsigned long V_57 , unsigned long V_58 )
{
if ( F_53 ( F_54 () ) )
return F_55 ( V_26 , V_69 ) ;
#ifdef F_56
{
T_2 * V_70 ;
V_70 = F_57 ( V_6 , V_26 , V_56 ,
V_57 , V_58 ) ;
if ( V_70 )
return F_48 ( V_70 , V_26 , V_56 ,
V_57 , V_58 ) ;
}
#endif
return NULL ;
}
static void * T_1 F_58 ( unsigned long V_26 ,
unsigned long V_56 ,
unsigned long V_57 ,
unsigned long V_58 )
{
T_2 * V_6 ;
void * V_62 ;
V_71:
V_62 = F_52 ( NULL , V_26 , V_56 , V_57 , V_58 ) ;
if ( V_62 )
return V_62 ;
F_31 (bdata, &bdata_list, list) {
if ( V_57 && V_6 -> V_17 <= F_22 ( V_57 ) )
continue;
if ( V_58 && V_6 -> V_11 >= F_22 ( V_58 ) )
break;
V_62 = F_48 ( V_6 , V_26 , V_56 , V_57 , V_58 ) ;
if ( V_62 )
return V_62 ;
}
if ( V_57 ) {
V_57 = 0 ;
goto V_71;
}
return NULL ;
}
void * T_1 F_59 ( unsigned long V_26 , unsigned long V_56 ,
unsigned long V_57 )
{
unsigned long V_58 = 0 ;
return F_58 ( V_26 , V_56 , V_57 , V_58 ) ;
}
static void * T_1 F_60 ( unsigned long V_26 , unsigned long V_56 ,
unsigned long V_57 , unsigned long V_58 )
{
void * V_72 = F_58 ( V_26 , V_56 , V_57 , V_58 ) ;
if ( V_72 )
return V_72 ;
F_61 ( V_73 L_9 , V_26 ) ;
F_62 ( L_10 ) ;
return NULL ;
}
void * T_1 F_63 ( unsigned long V_26 , unsigned long V_56 ,
unsigned long V_57 )
{
unsigned long V_58 = 0 ;
return F_60 ( V_26 , V_56 , V_57 , V_58 ) ;
}
static void * T_1 F_64 ( T_2 * V_6 ,
unsigned long V_26 , unsigned long V_56 ,
unsigned long V_57 , unsigned long V_58 )
{
void * V_74 ;
V_74 = F_52 ( V_6 , V_26 , V_56 , V_57 , V_58 ) ;
if ( V_74 )
return V_74 ;
V_74 = F_48 ( V_6 , V_26 , V_56 , V_57 , V_58 ) ;
if ( V_74 )
return V_74 ;
return F_60 ( V_26 , V_56 , V_57 , V_58 ) ;
}
void * T_1 F_65 ( T_3 * V_19 , unsigned long V_26 ,
unsigned long V_56 , unsigned long V_57 )
{
if ( F_53 ( F_54 () ) )
return F_66 ( V_26 , V_69 , V_19 -> V_75 ) ;
return F_64 ( V_19 -> V_6 , V_26 , V_56 , V_57 , 0 ) ;
}
void * T_1 F_67 ( T_3 * V_19 , unsigned long V_26 ,
unsigned long V_56 , unsigned long V_57 )
{
#ifdef F_68
unsigned long V_76 ;
if ( F_53 ( F_54 () ) )
return F_66 ( V_26 , V_69 , V_19 -> V_75 ) ;
V_76 = V_19 -> V_77 + V_19 -> V_78 ;
if ( V_76 > F_68 + ( 128 >> ( 20 - V_5 ) ) &&
( V_57 >> V_5 ) < F_68 ) {
void * V_74 ;
unsigned long V_79 ;
V_79 = F_68 << V_5 ;
V_74 = F_48 ( V_19 -> V_6 , V_26 , V_56 ,
V_79 , 0 ) ;
if ( V_74 )
return V_74 ;
}
#endif
return F_65 ( V_19 , V_26 , V_56 , V_57 ) ;
}
void * T_1 F_69 ( unsigned long V_26 ,
unsigned long V_80 )
{
T_2 * V_6 ;
unsigned long V_81 , V_57 , V_58 ;
V_81 = F_70 ( V_80 ) ;
V_57 = V_81 << V_5 ;
V_58 = F_70 ( V_80 + 1 ) << V_5 ;
V_6 = & V_18 [ F_71 ( V_81 ) ] ;
return F_48 ( V_6 , V_26 , V_82 , V_57 , V_58 ) ;
}
void * T_1 F_72 ( T_3 * V_19 , unsigned long V_26 ,
unsigned long V_56 , unsigned long V_57 )
{
void * V_74 ;
if ( F_53 ( F_54 () ) )
return F_66 ( V_26 , V_69 , V_19 -> V_75 ) ;
V_74 = F_52 ( V_19 -> V_6 , V_26 , V_56 , V_57 , 0 ) ;
if ( V_74 )
return V_74 ;
V_74 = F_48 ( V_19 -> V_6 , V_26 , V_56 , V_57 , 0 ) ;
if ( V_74 )
return V_74 ;
return F_59 ( V_26 , V_56 , V_57 ) ;
}
void * T_1 F_73 ( unsigned long V_26 , unsigned long V_56 ,
unsigned long V_57 )
{
return F_60 ( V_26 , V_56 , V_57 , V_83 ) ;
}
void * T_1 F_74 ( T_3 * V_19 , unsigned long V_26 ,
unsigned long V_56 , unsigned long V_57 )
{
if ( F_53 ( F_54 () ) )
return F_66 ( V_26 , V_69 , V_19 -> V_75 ) ;
return F_64 ( V_19 -> V_6 , V_26 , V_56 ,
V_57 , V_83 ) ;
}
