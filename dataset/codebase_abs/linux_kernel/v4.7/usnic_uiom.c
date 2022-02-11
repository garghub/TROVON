static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ,
struct V_3 , V_2 ) ;
F_3 ( & V_4 -> V_5 -> V_6 ) ;
V_4 -> V_5 -> V_7 -= V_4 -> V_8 ;
F_4 ( & V_4 -> V_5 -> V_6 ) ;
F_5 ( V_4 -> V_5 ) ;
F_6 ( V_4 ) ;
}
static int F_7 ( struct V_9 * V_10 ,
struct V_11 * V_12 ,
unsigned long V_13 , int V_14 ,
void * V_15 )
{
F_8 ( L_1 ,
F_9 ( V_12 ) ,
V_10 , V_13 , V_14 ) ;
return - V_16 ;
}
static void F_10 ( struct V_17 * V_18 , int V_19 )
{
struct V_20 * V_21 , * V_22 ;
struct V_23 * V_23 ;
struct V_24 * V_25 ;
int V_26 ;
T_1 V_27 ;
F_11 (chunk, tmp, chunk_list, list) {
F_12 (chunk->page_list, sg, chunk->nents, i) {
V_23 = F_13 ( V_25 ) ;
V_27 = F_14 ( V_25 ) ;
if ( V_19 )
F_15 ( V_23 ) ;
F_16 ( V_23 ) ;
F_17 ( L_2 , & V_27 ) ;
}
F_6 ( V_21 ) ;
}
}
static int F_18 ( unsigned long V_28 , T_2 V_29 , int V_30 ,
int V_31 , struct V_17 * V_18 )
{
struct V_23 * * V_32 ;
struct V_24 * V_25 ;
struct V_20 * V_21 ;
unsigned long V_33 ;
unsigned long V_34 ;
unsigned long V_35 ;
unsigned long V_36 ;
int V_37 ;
int V_38 ;
int V_26 ;
int V_14 ;
T_1 V_27 ;
if ( ! F_19 () )
return - V_39 ;
F_20 ( V_18 ) ;
V_32 = (struct V_23 * * ) F_21 ( V_40 ) ;
if ( ! V_32 )
return - V_41 ;
V_36 = F_22 ( V_29 + ( V_28 & ~ V_42 ) ) >> V_43 ;
F_3 ( & V_44 -> V_5 -> V_6 ) ;
V_33 = V_36 + V_44 -> V_5 -> V_7 ;
V_34 = F_23 ( V_45 ) >> V_43 ;
if ( ( V_33 > V_34 ) && ! F_24 ( V_46 ) ) {
V_37 = - V_41 ;
goto V_47;
}
V_14 = V_48 | V_49 ;
V_14 |= ( V_30 ) ? V_50 : 0 ;
V_35 = V_28 & V_42 ;
V_37 = 0 ;
while ( V_36 ) {
V_37 = F_25 ( V_35 ,
F_26 (unsigned long, npages,
PAGE_SIZE / sizeof(struct page *)) ,
1 , ! V_30 , V_32 , NULL ) ;
if ( V_37 < 0 )
goto V_47;
V_36 -= V_37 ;
V_38 = 0 ;
while ( V_37 ) {
V_21 = F_27 ( sizeof( * V_21 ) +
sizeof( struct V_24 ) *
F_26 ( int , V_37 , V_51 ) ,
V_40 ) ;
if ( ! V_21 ) {
V_37 = - V_41 ;
goto V_47;
}
V_21 -> V_52 = F_26 ( int , V_37 , V_51 ) ;
F_28 ( V_21 -> V_32 , V_21 -> V_52 ) ;
F_12 (chunk->page_list, sg, chunk->nents, i) {
F_29 ( V_25 , V_32 [ V_26 + V_38 ] ,
V_53 , 0 ) ;
V_27 = F_14 ( V_25 ) ;
F_17 ( L_3 ,
V_35 + V_26 * V_53 , & V_27 ) ;
}
V_35 += V_21 -> V_52 * V_53 ;
V_37 -= V_21 -> V_52 ;
V_38 += V_21 -> V_52 ;
F_30 ( & V_21 -> V_54 , V_18 ) ;
}
V_37 = 0 ;
}
V_47:
if ( V_37 < 0 )
F_10 ( V_18 , 0 ) ;
else
V_44 -> V_5 -> V_7 = V_33 ;
F_4 ( & V_44 -> V_5 -> V_6 ) ;
F_31 ( ( unsigned long ) V_32 ) ;
return V_37 ;
}
static void F_32 ( struct V_17 * V_55 ,
struct V_56 * V_57 )
{
struct V_58 * V_59 , * V_22 ;
long unsigned V_60 , V_29 ;
F_11 (interval, tmp, intervals, link) {
V_60 = V_59 -> V_61 << V_43 ;
V_29 = ( ( V_59 -> V_62 - V_59 -> V_61 ) + 1 ) << V_43 ;
while ( V_29 > 0 ) {
F_17 ( L_4 , V_60 , V_53 ) ;
F_33 ( V_57 -> V_10 , V_60 , V_53 ) ;
V_60 += V_53 ;
V_29 -= V_53 ;
}
}
}
static void F_34 ( struct V_56 * V_57 ,
struct V_3 * V_63 ,
int V_19 )
{
int V_36 ;
unsigned long V_64 , V_65 ;
struct V_58 * V_59 , * V_22 ;
int V_30 = 0 ;
F_35 ( V_66 ) ;
V_36 = F_22 ( V_63 -> V_67 + V_63 -> V_68 ) >> V_43 ;
V_64 = ( V_63 -> V_60 & V_42 ) >> V_43 ;
V_65 = V_64 + V_36 - 1 ;
F_36 ( & V_57 -> V_69 ) ;
F_37 ( & V_57 -> V_70 , V_64 ,
V_65 , & V_66 ) ;
F_32 ( & V_66 , V_57 ) ;
F_11 (interval, tmp, &rm_intervals, link) {
if ( V_59 -> V_14 & V_50 )
V_30 = 1 ;
F_38 ( & V_59 -> V_71 ) ;
F_6 ( V_59 ) ;
}
F_10 ( & V_63 -> V_18 , V_19 & V_30 ) ;
F_39 ( & V_57 -> V_69 ) ;
}
static int F_40 ( struct V_17 * V_55 ,
struct V_3 * V_63 )
{
int V_26 , V_72 ;
T_2 V_29 ;
struct V_20 * V_21 ;
struct V_58 * V_73 ;
T_1 V_27 ;
T_1 V_74 = 0 ;
T_1 V_75 = 0 ;
long int va_start = - V_76 ;
struct V_56 * V_57 = V_63 -> V_57 ;
long int V_60 = V_63 -> V_60 & V_42 ;
int V_14 = V_48 | V_49 ;
V_14 |= ( V_63 -> V_30 ) ? V_50 : 0 ;
V_21 = F_41 ( & V_63 -> V_18 , struct V_20 ,
V_54 ) ;
F_42 (interval_node, intervals, link) {
V_77:
for ( V_26 = 0 ; V_26 < V_21 -> V_52 ; V_26 ++ , V_60 += V_53 ) {
V_27 = F_14 ( & V_21 -> V_32 [ V_26 ] ) ;
if ( ( V_60 >> V_43 ) < V_73 -> V_61 )
continue;
if ( ( V_60 >> V_43 ) == V_73 -> V_61 ) {
va_start = V_60 ;
V_74 = V_27 ;
V_75 = V_27 ;
}
F_43 ( va_start == - V_76 ) ;
if ( ( V_75 + V_53 != V_27 ) &&
( V_27 != V_74 ) ) {
V_29 = V_75 - V_74 + V_53 ;
F_17 ( L_5 ,
va_start , & V_74 , V_29 , V_14 ) ;
V_72 = F_44 ( V_57 -> V_10 , va_start , V_74 ,
V_29 , V_14 ) ;
if ( V_72 ) {
F_8 ( L_6 ,
va_start , & V_74 , V_29 , V_72 ) ;
goto V_78;
}
va_start = V_60 ;
V_74 = V_27 ;
V_75 = V_27 ;
}
if ( ( V_60 >> V_43 ) == V_73 -> V_62 ) {
V_29 = V_27 - V_74 + V_53 ;
F_17 ( L_7 ,
va_start , & V_74 , V_29 , V_14 ) ;
V_72 = F_44 ( V_57 -> V_10 , va_start , V_74 ,
V_29 , V_14 ) ;
if ( V_72 ) {
F_8 ( L_6 ,
va_start , & V_74 , V_29 , V_72 ) ;
goto V_78;
}
break;
}
if ( V_27 != V_74 )
V_75 += V_53 ;
}
if ( V_26 == V_21 -> V_52 ) {
V_21 = F_41 ( & V_21 -> V_54 ,
struct V_20 ,
V_54 ) ;
goto V_77;
}
}
return 0 ;
V_78:
F_32 ( V_55 , V_57 ) ;
return V_72 ;
}
struct V_3 * F_45 ( struct V_56 * V_57 ,
unsigned long V_28 , T_2 V_29 ,
int V_30 , int V_31 )
{
struct V_3 * V_63 ;
unsigned long V_79 , V_64 , V_65 ;
unsigned long V_36 ;
int V_68 , V_72 ;
F_35 ( V_80 ) ;
V_30 = 1 ;
V_79 = V_28 & V_42 ;
V_68 = V_28 & ~ V_42 ;
V_36 = F_22 ( V_29 + V_68 ) >> V_43 ;
V_64 = ( V_28 & V_42 ) >> V_43 ;
V_65 = V_64 + V_36 - 1 ;
V_63 = F_27 ( sizeof( * V_63 ) , V_40 ) ;
if ( ! V_63 )
return F_46 ( - V_41 ) ;
V_63 -> V_60 = V_79 ;
V_63 -> V_68 = V_68 ;
V_63 -> V_67 = V_29 ;
V_63 -> V_30 = V_30 ;
V_63 -> V_57 = V_57 ;
V_72 = F_18 ( V_28 , V_29 , V_30 , V_31 ,
& V_63 -> V_18 ) ;
if ( V_72 ) {
F_8 ( L_8 ,
V_64 , V_65 , V_72 ) ;
goto V_81;
}
F_36 ( & V_57 -> V_69 ) ;
V_72 = F_47 ( V_64 , V_65 ,
( V_30 ) ? V_50 : 0 ,
V_50 ,
& V_57 -> V_70 ,
& V_80 ) ;
if ( V_72 ) {
F_8 ( L_9 ,
V_64 , V_65 , V_72 ) ;
goto V_82;
}
V_72 = F_40 ( & V_80 , V_63 ) ;
if ( V_72 ) {
F_8 ( L_10 ,
V_64 , V_65 , V_72 ) ;
goto V_83;
}
V_72 = F_48 ( & V_57 -> V_70 , V_64 , V_65 ,
( V_30 ) ? V_50 : 0 ) ;
if ( V_72 ) {
F_8 ( L_11 ,
V_64 , V_65 , V_72 ) ;
goto V_84;
}
F_49 ( & V_80 ) ;
F_39 ( & V_57 -> V_69 ) ;
return V_63 ;
V_84:
F_32 ( & V_80 , V_57 ) ;
V_83:
F_49 ( & V_80 ) ;
V_82:
F_10 ( & V_63 -> V_18 , 0 ) ;
F_39 ( & V_57 -> V_69 ) ;
V_81:
F_6 ( V_63 ) ;
return F_46 ( V_72 ) ;
}
void F_50 ( struct V_3 * V_63 , int V_85 )
{
struct V_86 * V_5 ;
unsigned long V_8 ;
F_34 ( V_63 -> V_57 , V_63 , 1 ) ;
V_5 = F_51 ( V_44 ) ;
if ( ! V_5 ) {
F_6 ( V_63 ) ;
return;
}
V_8 = F_22 ( V_63 -> V_67 + V_63 -> V_68 ) >> V_43 ;
if ( V_85 ) {
if ( ! F_52 ( & V_5 -> V_6 ) ) {
F_53 ( & V_63 -> V_2 , F_1 ) ;
V_63 -> V_5 = V_5 ;
V_63 -> V_8 = V_8 ;
F_54 ( V_87 , & V_63 -> V_2 ) ;
return;
}
} else
F_3 ( & V_5 -> V_6 ) ;
V_44 -> V_5 -> V_7 -= V_8 ;
F_4 ( & V_5 -> V_6 ) ;
F_5 ( V_5 ) ;
F_6 ( V_63 ) ;
}
struct V_56 * F_55 ( void )
{
struct V_56 * V_57 ;
void * V_10 ;
V_57 = F_56 ( sizeof( * V_57 ) , V_40 ) ;
if ( ! V_57 )
return F_46 ( - V_41 ) ;
V_57 -> V_10 = V_10 = F_57 ( & V_88 ) ;
if ( ! V_10 ) {
F_8 ( L_12 ) ;
F_6 ( V_57 ) ;
return F_46 ( - V_41 ) ;
}
F_58 ( V_57 -> V_10 , F_7 , NULL ) ;
F_59 ( & V_57 -> V_69 ) ;
F_20 ( & V_57 -> V_89 ) ;
return V_57 ;
}
void F_60 ( struct V_56 * V_57 )
{
F_61 ( V_57 -> V_10 ) ;
F_6 ( V_57 ) ;
}
int F_62 ( struct V_56 * V_57 , struct V_11 * V_12 )
{
struct V_90 * V_91 ;
int V_72 ;
V_91 = F_56 ( sizeof( * V_91 ) , V_92 ) ;
if ( ! V_91 )
return - V_41 ;
V_91 -> V_12 = V_12 ;
V_72 = F_63 ( V_57 -> V_10 , V_12 ) ;
if ( V_72 )
goto V_93;
if ( ! F_64 ( V_12 -> V_94 , V_95 ) ) {
F_8 ( L_13 ,
F_9 ( V_12 ) ) ;
V_72 = - V_76 ;
goto V_96;
}
F_36 ( & V_57 -> V_69 ) ;
F_30 ( & V_91 -> V_71 , & V_57 -> V_89 ) ;
V_57 -> V_97 ++ ;
F_39 ( & V_57 -> V_69 ) ;
return 0 ;
V_96:
F_65 ( V_57 -> V_10 , V_12 ) ;
V_93:
F_6 ( V_91 ) ;
return V_72 ;
}
void F_66 ( struct V_56 * V_57 , struct V_11 * V_12 )
{
struct V_90 * V_91 ;
int V_98 = 0 ;
F_36 ( & V_57 -> V_69 ) ;
F_42 (uiom_dev, &pd->devs, link) {
if ( V_91 -> V_12 == V_12 ) {
V_98 = 1 ;
break;
}
}
if ( ! V_98 ) {
F_8 ( L_14 ,
F_9 ( V_12 ) ) ;
F_39 ( & V_57 -> V_69 ) ;
return;
}
F_38 ( & V_91 -> V_71 ) ;
V_57 -> V_97 -- ;
F_39 ( & V_57 -> V_69 ) ;
return F_65 ( V_57 -> V_10 , V_12 ) ;
}
struct V_11 * * F_67 ( struct V_56 * V_57 )
{
struct V_90 * V_91 ;
struct V_11 * * V_89 ;
int V_26 = 0 ;
F_36 ( & V_57 -> V_69 ) ;
V_89 = F_68 ( V_57 -> V_97 + 1 , sizeof( * V_89 ) , V_92 ) ;
if ( ! V_89 ) {
V_89 = F_46 ( - V_41 ) ;
goto V_47;
}
F_42 (uiom_dev, &pd->devs, link) {
V_89 [ V_26 ++ ] = V_91 -> V_12 ;
}
V_47:
F_39 ( & V_57 -> V_69 ) ;
return V_89 ;
}
void F_69 ( struct V_11 * * V_89 )
{
F_6 ( V_89 ) ;
}
int F_70 ( char * V_99 )
{
if ( ! F_71 ( & V_88 ) ) {
F_8 ( L_15 ) ;
return - V_39 ;
}
V_87 = F_72 ( V_99 ) ;
if ( ! V_87 ) {
F_8 ( L_16 , V_99 ) ;
return - V_41 ;
}
return 0 ;
}
void F_73 ( void )
{
F_74 ( V_87 ) ;
F_75 ( V_87 ) ;
}
