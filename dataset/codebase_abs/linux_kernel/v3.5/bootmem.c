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
F_23 ( F_24 ( V_26 ) , 0 ) ;
V_27 ++ ;
}
}
static unsigned long T_1 F_25 ( T_2 * V_6 )
{
struct V_28 * V_28 ;
unsigned long V_12 , V_13 , V_3 , V_29 = 0 ;
if ( ! V_6 -> V_15 )
return 0 ;
V_12 = V_6 -> V_8 ;
V_13 = V_6 -> V_16 ;
F_14 ( L_2 ,
V_6 - V_17 , V_12 , V_13 ) ;
while ( V_12 < V_13 ) {
unsigned long * V_30 , V_31 , V_32 ;
V_30 = V_6 -> V_15 ;
V_31 = V_12 - V_6 -> V_8 ;
V_32 = ~ V_30 [ V_31 / V_33 ] ;
if ( F_26 ( V_12 , V_33 ) && V_32 == ~ 0UL ) {
int V_34 = F_27 ( V_33 ) ;
F_23 ( F_24 ( V_12 ) , V_34 ) ;
V_29 += V_33 ;
V_12 += V_33 ;
} else {
unsigned long V_35 = 0 ;
V_32 >>= V_12 & ( V_33 - 1 ) ;
while ( V_32 ) {
if ( V_32 & 1 ) {
V_28 = F_24 ( V_12 + V_35 ) ;
F_23 ( V_28 , 0 ) ;
V_29 ++ ;
}
V_32 >>= 1 ;
V_35 ++ ;
}
V_12 = F_4 ( V_12 + 1 , V_33 ) ;
}
}
V_28 = F_28 ( V_6 -> V_15 ) ;
V_3 = V_6 -> V_16 - V_6 -> V_8 ;
V_3 = F_5 ( V_3 ) ;
V_29 += V_3 ;
while ( V_3 -- )
F_23 ( V_28 ++ , 0 ) ;
F_14 ( L_3 , V_6 - V_17 , V_29 ) ;
return V_29 ;
}
unsigned long T_1 F_29 ( T_3 * V_18 )
{
F_30 ( V_18 ) ;
return F_25 ( V_18 -> V_6 ) ;
}
unsigned long T_1 F_31 ( void )
{
unsigned long V_36 = 0 ;
T_2 * V_6 ;
F_8 (bdata, &bdata_list, list)
V_36 += F_25 ( V_6 ) ;
return V_36 ;
}
static void T_1 F_32 ( T_2 * V_6 ,
unsigned long V_37 , unsigned long V_38 )
{
unsigned long V_31 ;
F_14 ( L_2 , V_6 - V_17 ,
V_37 + V_6 -> V_8 ,
V_38 + V_6 -> V_8 ) ;
if ( V_6 -> V_39 > V_37 )
V_6 -> V_39 = V_37 ;
for ( V_31 = V_37 ; V_31 < V_38 ; V_31 ++ )
if ( ! F_33 ( V_31 , V_6 -> V_15 ) )
F_34 () ;
}
static int T_1 F_35 ( T_2 * V_6 , unsigned long V_37 ,
unsigned long V_38 , int V_40 )
{
unsigned long V_31 ;
int V_41 = V_40 & V_42 ;
F_14 ( L_4 ,
V_6 - V_17 ,
V_37 + V_6 -> V_8 ,
V_38 + V_6 -> V_8 ,
V_40 ) ;
for ( V_31 = V_37 ; V_31 < V_38 ; V_31 ++ )
if ( F_36 ( V_31 , V_6 -> V_15 ) ) {
if ( V_41 ) {
F_32 ( V_6 , V_37 , V_31 ) ;
return - V_43 ;
}
F_14 ( L_5 ,
V_31 + V_6 -> V_8 ) ;
}
return 0 ;
}
static int T_1 F_37 ( T_2 * V_6 ,
unsigned long V_12 , unsigned long V_13 ,
int V_44 , int V_40 )
{
unsigned long V_37 , V_38 ;
F_14 ( L_6 ,
V_6 - V_17 , V_12 , V_13 , V_44 , V_40 ) ;
F_38 ( V_12 < V_6 -> V_8 ) ;
F_38 ( V_13 > V_6 -> V_16 ) ;
V_37 = V_12 - V_6 -> V_8 ;
V_38 = V_13 - V_6 -> V_8 ;
if ( V_44 )
return F_35 ( V_6 , V_37 , V_38 , V_40 ) ;
else
F_32 ( V_6 , V_37 , V_38 ) ;
return 0 ;
}
static int T_1 F_39 ( unsigned long V_12 , unsigned long V_13 ,
int V_44 , int V_40 )
{
unsigned long V_45 ;
T_2 * V_6 ;
V_45 = V_12 ;
F_8 (bdata, &bdata_list, list) {
int V_46 ;
unsigned long V_47 ;
if ( V_45 < V_6 -> V_8 ||
V_45 >= V_6 -> V_16 ) {
F_38 ( V_45 != V_12 ) ;
continue;
}
V_47 = F_40 ( V_6 -> V_16 , V_13 ) ;
V_46 = F_37 ( V_6 , V_45 , V_47 , V_44 , V_40 ) ;
if ( V_44 && V_46 ) {
F_39 ( V_12 , V_45 , 0 , 0 ) ;
return V_46 ;
}
if ( V_47 == V_13 )
return 0 ;
V_45 = V_6 -> V_16 ;
}
F_34 () ;
}
void T_1 F_41 ( T_3 * V_18 , unsigned long V_48 ,
unsigned long V_25 )
{
unsigned long V_12 , V_13 ;
F_19 ( F_20 ( V_48 ) , V_25 ) ;
V_12 = F_21 ( V_48 ) ;
V_13 = F_22 ( V_48 + V_25 ) ;
F_37 ( V_18 -> V_6 , V_12 , V_13 , 0 , 0 ) ;
}
void T_1 F_42 ( unsigned long V_24 , unsigned long V_25 )
{
unsigned long V_12 , V_13 ;
F_19 ( F_20 ( V_24 ) , V_25 ) ;
V_12 = F_21 ( V_24 ) ;
V_13 = F_22 ( V_24 + V_25 ) ;
F_39 ( V_12 , V_13 , 0 , 0 ) ;
}
int T_1 F_43 ( T_3 * V_18 , unsigned long V_48 ,
unsigned long V_25 , int V_40 )
{
unsigned long V_12 , V_13 ;
V_12 = F_22 ( V_48 ) ;
V_13 = F_21 ( V_48 + V_25 ) ;
return F_37 ( V_18 -> V_6 , V_12 , V_13 , 1 , V_40 ) ;
}
int T_1 F_44 ( unsigned long V_24 , unsigned long V_25 ,
int V_40 )
{
unsigned long V_12 , V_13 ;
V_12 = F_22 ( V_24 ) ;
V_13 = F_21 ( V_24 + V_25 ) ;
return F_39 ( V_12 , V_13 , 1 , V_40 ) ;
}
int __weak T_1 F_45 ( unsigned long V_49 , unsigned long V_50 ,
int V_40 )
{
return F_44 ( V_49 , V_50 , V_40 ) ;
}
static unsigned long T_1 F_46 ( struct V_51 * V_6 ,
unsigned long V_31 , unsigned long V_52 )
{
unsigned long V_53 = V_6 -> V_8 ;
return F_4 ( V_53 + V_31 , V_52 ) - V_53 ;
}
static unsigned long T_1 F_47 ( struct V_51 * V_6 ,
unsigned long V_35 , unsigned long V_54 )
{
unsigned long V_53 = F_13 ( V_6 -> V_8 ) ;
return F_4 ( V_53 + V_35 , V_54 ) - V_53 ;
}
static void * T_1 F_48 ( struct V_51 * V_6 ,
unsigned long V_25 , unsigned long V_54 ,
unsigned long V_55 , unsigned long V_56 )
{
unsigned long V_57 = 0 ;
unsigned long F_40 , V_47 , V_12 , V_37 , V_58 , V_52 ;
F_14 ( L_7 ,
V_6 - V_17 , V_25 , F_6 ( V_25 ) >> V_5 ,
V_54 , V_55 , V_56 ) ;
F_38 ( ! V_25 ) ;
F_38 ( V_54 & ( V_54 - 1 ) ) ;
F_38 ( V_56 && V_55 + V_25 > V_56 ) ;
if ( ! V_6 -> V_15 )
return NULL ;
F_40 = V_6 -> V_8 ;
V_47 = V_6 -> V_16 ;
V_55 >>= V_5 ;
V_56 >>= V_5 ;
if ( V_56 && V_47 > V_56 )
V_47 = V_56 ;
if ( V_47 <= F_40 )
return NULL ;
V_52 = V_47 ( V_54 >> V_5 , 1UL ) ;
if ( V_55 && F_40 < V_55 && V_55 < V_47 )
V_12 = F_4 ( V_55 , V_52 ) ;
else
V_12 = F_4 ( F_40 , V_52 ) ;
V_37 = V_12 - V_6 -> V_8 ;
V_58 = V_47 - V_6 -> V_8 ;
if ( V_6 -> V_39 > V_37 ) {
V_57 = V_37 + 1 ;
V_37 = F_46 ( V_6 , V_6 -> V_39 , V_52 ) ;
}
while ( 1 ) {
int V_59 ;
void * V_60 ;
unsigned long V_38 , V_61 , V_62 , V_63 ;
V_64:
V_37 = F_49 ( V_6 -> V_15 , V_58 , V_37 ) ;
V_37 = F_46 ( V_6 , V_37 , V_52 ) ;
V_38 = V_37 + F_21 ( V_25 ) ;
if ( V_37 >= V_58 || V_38 > V_58 )
break;
for ( V_61 = V_37 ; V_61 < V_38 ; V_61 ++ )
if ( F_50 ( V_61 , V_6 -> V_15 ) ) {
V_37 = F_46 ( V_6 , V_61 , V_52 ) ;
if ( V_37 == V_61 )
V_37 += V_52 ;
goto V_64;
}
if ( V_6 -> V_65 & ( V_66 - 1 ) &&
F_22 ( V_6 -> V_65 ) + 1 == V_37 )
V_62 = F_47 ( V_6 , V_6 -> V_65 , V_54 ) ;
else
V_62 = F_13 ( V_37 ) ;
V_59 = F_22 ( V_62 ) < V_37 ;
V_63 = V_62 + V_25 ;
V_6 -> V_65 = V_63 ;
V_6 -> V_39 = F_21 ( V_63 ) ;
if ( F_35 ( V_6 , F_22 ( V_62 ) + V_59 ,
F_21 ( V_63 ) , V_42 ) )
F_34 () ;
V_60 = F_12 ( F_13 ( V_6 -> V_8 ) +
V_62 ) ;
memset ( V_60 , 0 , V_25 ) ;
F_51 ( V_60 , V_25 , 0 , 0 ) ;
return V_60 ;
}
if ( V_57 ) {
V_37 = F_46 ( V_6 , V_57 - 1 , V_52 ) ;
V_57 = 0 ;
goto V_64;
}
return NULL ;
}
static void * T_1 F_52 ( T_2 * V_6 ,
unsigned long V_25 , unsigned long V_54 ,
unsigned long V_55 , unsigned long V_56 )
{
if ( F_53 ( F_54 () ) )
return F_55 ( V_25 , V_67 ) ;
#ifdef F_56
{
T_2 * V_68 ;
V_68 = F_57 ( V_6 , V_25 , V_54 ,
V_55 , V_56 ) ;
if ( V_68 )
return F_48 ( V_68 , V_25 , V_54 ,
V_55 , V_56 ) ;
}
#endif
return NULL ;
}
static void * T_1 F_58 ( unsigned long V_25 ,
unsigned long V_54 ,
unsigned long V_55 ,
unsigned long V_56 )
{
T_2 * V_6 ;
void * V_60 ;
V_60 = F_52 ( NULL , V_25 , V_54 , V_55 , V_56 ) ;
if ( V_60 )
return V_60 ;
F_8 (bdata, &bdata_list, list) {
if ( V_55 && V_6 -> V_16 <= F_22 ( V_55 ) )
continue;
if ( V_56 && V_6 -> V_8 >= F_22 ( V_56 ) )
break;
V_60 = F_48 ( V_6 , V_25 , V_54 , V_55 , V_56 ) ;
if ( V_60 )
return V_60 ;
}
return NULL ;
}
static void * T_1 F_59 ( unsigned long V_25 ,
unsigned long V_54 ,
unsigned long V_55 ,
unsigned long V_56 )
{
void * V_69 ;
V_70:
V_69 = F_58 ( V_25 , V_54 , V_55 , V_56 ) ;
if ( V_69 )
return V_69 ;
if ( V_55 ) {
V_55 = 0 ;
goto V_70;
}
return NULL ;
}
void * T_1 F_60 ( unsigned long V_25 , unsigned long V_54 ,
unsigned long V_55 )
{
unsigned long V_56 = 0 ;
return F_59 ( V_25 , V_54 , V_55 , V_56 ) ;
}
static void * T_1 F_61 ( unsigned long V_25 , unsigned long V_54 ,
unsigned long V_55 , unsigned long V_56 )
{
void * V_71 = F_59 ( V_25 , V_54 , V_55 , V_56 ) ;
if ( V_71 )
return V_71 ;
F_62 ( V_72 L_8 , V_25 ) ;
F_63 ( L_9 ) ;
return NULL ;
}
void * T_1 F_64 ( unsigned long V_25 , unsigned long V_54 ,
unsigned long V_55 )
{
unsigned long V_56 = 0 ;
return F_61 ( V_25 , V_54 , V_55 , V_56 ) ;
}
void * T_1 F_65 ( T_3 * V_18 ,
unsigned long V_25 , unsigned long V_54 ,
unsigned long V_55 , unsigned long V_56 )
{
void * V_69 ;
V_73:
V_69 = F_52 ( V_18 -> V_6 , V_25 ,
V_54 , V_55 , V_56 ) ;
if ( V_69 )
return V_69 ;
if ( V_56 && V_55 + V_25 > V_56 )
V_56 = 0 ;
V_69 = F_48 ( V_18 -> V_6 , V_25 , V_54 , V_55 , V_56 ) ;
if ( V_69 )
return V_69 ;
V_69 = F_58 ( V_25 , V_54 , V_55 , V_56 ) ;
if ( V_69 )
return V_69 ;
if ( V_55 ) {
V_55 = 0 ;
goto V_73;
}
return NULL ;
}
void * T_1 F_66 ( T_3 * V_18 , unsigned long V_25 ,
unsigned long V_54 , unsigned long V_55 )
{
if ( F_53 ( F_54 () ) )
return F_67 ( V_25 , V_67 , V_18 -> V_74 ) ;
return F_65 ( V_18 , V_25 , V_54 , V_55 , 0 ) ;
}
void * T_1 F_68 ( T_3 * V_18 , unsigned long V_25 ,
unsigned long V_54 , unsigned long V_55 ,
unsigned long V_56 )
{
void * V_69 ;
V_69 = F_65 ( V_18 , V_25 , V_54 , V_55 , 0 ) ;
if ( V_69 )
return V_69 ;
F_62 ( V_72 L_8 , V_25 ) ;
F_63 ( L_9 ) ;
return NULL ;
}
void * T_1 F_69 ( T_3 * V_18 , unsigned long V_25 ,
unsigned long V_54 , unsigned long V_55 )
{
if ( F_53 ( F_54 () ) )
return F_67 ( V_25 , V_67 , V_18 -> V_74 ) ;
return F_68 ( V_18 , V_25 , V_54 , V_55 , 0 ) ;
}
void * T_1 F_70 ( T_3 * V_18 , unsigned long V_25 ,
unsigned long V_54 , unsigned long V_55 )
{
#ifdef F_71
unsigned long V_75 ;
if ( F_53 ( F_54 () ) )
return F_67 ( V_25 , V_67 , V_18 -> V_74 ) ;
V_75 = V_18 -> V_76 + V_18 -> V_77 ;
if ( V_75 > F_71 + ( 128 >> ( 20 - V_5 ) ) &&
( V_55 >> V_5 ) < F_71 ) {
void * V_69 ;
unsigned long V_78 ;
V_78 = F_71 << V_5 ;
V_69 = F_48 ( V_18 -> V_6 , V_25 , V_54 ,
V_78 , 0 ) ;
if ( V_69 )
return V_69 ;
}
#endif
return F_69 ( V_18 , V_25 , V_54 , V_55 ) ;
}
void * T_1 F_72 ( unsigned long V_25 , unsigned long V_54 ,
unsigned long V_55 )
{
return F_61 ( V_25 , V_54 , V_55 , V_79 ) ;
}
void * T_1 F_73 ( T_3 * V_18 , unsigned long V_25 ,
unsigned long V_54 , unsigned long V_55 )
{
if ( F_53 ( F_54 () ) )
return F_67 ( V_25 , V_67 , V_18 -> V_74 ) ;
return F_68 ( V_18 , V_25 , V_54 ,
V_55 , V_79 ) ;
}
