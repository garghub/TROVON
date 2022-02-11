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
F_19 ( V_39 ) ;
if ( V_31 )
F_20 ( V_40 , & V_39 ) ;
if ( ! F_21 () )
return - V_41 ;
F_22 ( V_18 ) ;
V_32 = (struct V_23 * * ) F_23 ( V_42 ) ;
if ( ! V_32 )
return - V_43 ;
V_36 = F_24 ( V_29 + ( V_28 & ~ V_44 ) ) >> V_45 ;
F_3 ( & V_46 -> V_5 -> V_6 ) ;
V_33 = V_36 + V_46 -> V_5 -> V_7 ;
V_34 = F_25 ( V_47 ) >> V_45 ;
if ( ( V_33 > V_34 ) && ! F_26 ( V_48 ) ) {
V_37 = - V_43 ;
goto V_49;
}
V_14 = V_50 | V_51 ;
V_14 |= ( V_30 ) ? V_52 : 0 ;
V_35 = V_28 & V_44 ;
V_37 = 0 ;
while ( V_36 ) {
V_37 = F_27 ( V_35 ,
F_28 (unsigned long, npages,
PAGE_SIZE / sizeof(struct page *)) ,
1 , ! V_30 , V_32 , NULL ) ;
if ( V_37 < 0 )
goto V_49;
V_36 -= V_37 ;
V_38 = 0 ;
while ( V_37 ) {
V_21 = F_29 ( sizeof( * V_21 ) +
sizeof( struct V_24 ) *
F_28 ( int , V_37 , V_53 ) ,
V_42 ) ;
if ( ! V_21 ) {
V_37 = - V_43 ;
goto V_49;
}
V_21 -> V_54 = F_28 ( int , V_37 , V_53 ) ;
F_30 ( V_21 -> V_32 , V_21 -> V_54 ) ;
F_12 (chunk->page_list, sg, chunk->nents, i) {
F_31 ( V_25 , V_32 [ V_26 + V_38 ] ,
V_55 , 0 ) ;
V_27 = F_14 ( V_25 ) ;
F_17 ( L_3 ,
V_35 + V_26 * V_55 , & V_27 ) ;
}
V_35 += V_21 -> V_54 * V_55 ;
V_37 -= V_21 -> V_54 ;
V_38 += V_21 -> V_54 ;
F_32 ( & V_21 -> V_56 , V_18 ) ;
}
V_37 = 0 ;
}
V_49:
if ( V_37 < 0 )
F_10 ( V_18 , 0 ) ;
else
V_46 -> V_5 -> V_7 = V_33 ;
F_4 ( & V_46 -> V_5 -> V_6 ) ;
F_33 ( ( unsigned long ) V_32 ) ;
return V_37 ;
}
static void F_34 ( struct V_17 * V_57 ,
struct V_58 * V_59 )
{
struct V_60 * V_61 , * V_22 ;
long unsigned V_62 , V_29 ;
F_11 (interval, tmp, intervals, link) {
V_62 = V_61 -> V_63 << V_45 ;
V_29 = ( ( V_61 -> V_64 - V_61 -> V_63 ) + 1 ) << V_45 ;
while ( V_29 > 0 ) {
F_17 ( L_4 , V_62 , V_55 ) ;
F_35 ( V_59 -> V_10 , V_62 , V_55 ) ;
V_62 += V_55 ;
V_29 -= V_55 ;
}
}
}
static void F_36 ( struct V_58 * V_59 ,
struct V_3 * V_65 ,
int V_19 )
{
int V_36 ;
unsigned long V_66 , V_67 ;
struct V_60 * V_61 , * V_22 ;
int V_30 = 0 ;
F_37 ( V_68 ) ;
V_36 = F_24 ( V_65 -> V_69 + V_65 -> V_70 ) >> V_45 ;
V_66 = ( V_65 -> V_62 & V_44 ) >> V_45 ;
V_67 = V_66 + V_36 - 1 ;
F_38 ( & V_59 -> V_71 ) ;
F_39 ( & V_59 -> V_72 , V_66 ,
V_67 , & V_68 ) ;
F_34 ( & V_68 , V_59 ) ;
F_11 (interval, tmp, &rm_intervals, link) {
if ( V_61 -> V_14 & V_52 )
V_30 = 1 ;
F_40 ( & V_61 -> V_73 ) ;
F_6 ( V_61 ) ;
}
F_10 ( & V_65 -> V_18 , V_19 & V_30 ) ;
F_41 ( & V_59 -> V_71 ) ;
}
static int F_42 ( struct V_17 * V_57 ,
struct V_3 * V_65 )
{
int V_26 , V_74 ;
T_2 V_29 ;
struct V_20 * V_21 ;
struct V_60 * V_75 ;
T_1 V_27 ;
T_1 V_76 = 0 ;
T_1 V_77 = 0 ;
long int va_start = - V_78 ;
struct V_58 * V_59 = V_65 -> V_59 ;
long int V_62 = V_65 -> V_62 & V_44 ;
int V_14 = V_50 | V_51 ;
V_14 |= ( V_65 -> V_30 ) ? V_52 : 0 ;
V_21 = F_43 ( & V_65 -> V_18 , struct V_20 ,
V_56 ) ;
F_44 (interval_node, intervals, link) {
V_79:
for ( V_26 = 0 ; V_26 < V_21 -> V_54 ; V_26 ++ , V_62 += V_55 ) {
V_27 = F_14 ( & V_21 -> V_32 [ V_26 ] ) ;
if ( ( V_62 >> V_45 ) < V_75 -> V_63 )
continue;
if ( ( V_62 >> V_45 ) == V_75 -> V_63 ) {
va_start = V_62 ;
V_76 = V_27 ;
V_77 = V_27 ;
}
F_45 ( va_start == - V_78 ) ;
if ( ( V_77 + V_55 != V_27 ) &&
( V_27 != V_76 ) ) {
V_29 = V_77 - V_76 + V_55 ;
F_17 ( L_5 ,
va_start , & V_76 , V_29 , V_14 ) ;
V_74 = F_46 ( V_59 -> V_10 , va_start , V_76 ,
V_29 , V_14 ) ;
if ( V_74 ) {
F_8 ( L_6 ,
va_start , & V_76 , V_29 , V_74 ) ;
goto V_80;
}
va_start = V_62 ;
V_76 = V_27 ;
V_77 = V_27 ;
}
if ( ( V_62 >> V_45 ) == V_75 -> V_64 ) {
V_29 = V_27 - V_76 + V_55 ;
F_17 ( L_7 ,
va_start , & V_76 , V_29 , V_14 ) ;
V_74 = F_46 ( V_59 -> V_10 , va_start , V_76 ,
V_29 , V_14 ) ;
if ( V_74 ) {
F_8 ( L_6 ,
va_start , & V_76 , V_29 , V_74 ) ;
goto V_80;
}
break;
}
if ( V_27 != V_76 )
V_77 += V_55 ;
}
if ( V_26 == V_21 -> V_54 ) {
V_21 = F_43 ( & V_21 -> V_56 ,
struct V_20 ,
V_56 ) ;
goto V_79;
}
}
return 0 ;
V_80:
F_34 ( V_57 , V_59 ) ;
return V_74 ;
}
struct V_3 * F_47 ( struct V_58 * V_59 ,
unsigned long V_28 , T_2 V_29 ,
int V_30 , int V_31 )
{
struct V_3 * V_65 ;
unsigned long V_81 , V_66 , V_67 ;
unsigned long V_36 ;
int V_70 , V_74 ;
F_37 ( V_82 ) ;
V_30 = 1 ;
V_81 = V_28 & V_44 ;
V_70 = V_28 & ~ V_44 ;
V_36 = F_24 ( V_29 + V_70 ) >> V_45 ;
V_66 = ( V_28 & V_44 ) >> V_45 ;
V_67 = V_66 + V_36 - 1 ;
V_65 = F_29 ( sizeof( * V_65 ) , V_42 ) ;
if ( ! V_65 )
return F_48 ( - V_43 ) ;
V_65 -> V_62 = V_81 ;
V_65 -> V_70 = V_70 ;
V_65 -> V_69 = V_29 ;
V_65 -> V_30 = V_30 ;
V_65 -> V_59 = V_59 ;
V_74 = F_18 ( V_28 , V_29 , V_30 , V_31 ,
& V_65 -> V_18 ) ;
if ( V_74 ) {
F_8 ( L_8 ,
V_66 , V_67 , V_74 ) ;
goto V_83;
}
F_38 ( & V_59 -> V_71 ) ;
V_74 = F_49 ( V_66 , V_67 ,
( V_30 ) ? V_52 : 0 ,
V_52 ,
& V_59 -> V_72 ,
& V_82 ) ;
if ( V_74 ) {
F_8 ( L_9 ,
V_66 , V_67 , V_74 ) ;
goto V_84;
}
V_74 = F_42 ( & V_82 , V_65 ) ;
if ( V_74 ) {
F_8 ( L_10 ,
V_66 , V_67 , V_74 ) ;
goto V_85;
}
V_74 = F_50 ( & V_59 -> V_72 , V_66 , V_67 ,
( V_30 ) ? V_52 : 0 ) ;
if ( V_74 ) {
F_8 ( L_11 ,
V_66 , V_67 , V_74 ) ;
goto V_86;
}
F_51 ( & V_82 ) ;
F_41 ( & V_59 -> V_71 ) ;
return V_65 ;
V_86:
F_34 ( & V_82 , V_59 ) ;
V_85:
F_51 ( & V_82 ) ;
V_84:
F_10 ( & V_65 -> V_18 , 0 ) ;
F_41 ( & V_59 -> V_71 ) ;
V_83:
F_6 ( V_65 ) ;
return F_48 ( V_74 ) ;
}
void F_52 ( struct V_3 * V_65 , int V_87 )
{
struct V_88 * V_5 ;
unsigned long V_8 ;
F_36 ( V_65 -> V_59 , V_65 , 1 ) ;
V_5 = F_53 ( V_46 ) ;
if ( ! V_5 ) {
F_6 ( V_65 ) ;
return;
}
V_8 = F_24 ( V_65 -> V_69 + V_65 -> V_70 ) >> V_45 ;
if ( V_87 ) {
if ( ! F_54 ( & V_5 -> V_6 ) ) {
F_55 ( & V_65 -> V_2 , F_1 ) ;
V_65 -> V_5 = V_5 ;
V_65 -> V_8 = V_8 ;
F_56 ( V_89 , & V_65 -> V_2 ) ;
return;
}
} else
F_3 ( & V_5 -> V_6 ) ;
V_46 -> V_5 -> V_7 -= V_8 ;
F_4 ( & V_5 -> V_6 ) ;
F_5 ( V_5 ) ;
F_6 ( V_65 ) ;
}
struct V_58 * F_57 ( void )
{
struct V_58 * V_59 ;
void * V_10 ;
V_59 = F_58 ( sizeof( * V_59 ) , V_42 ) ;
if ( ! V_59 )
return F_48 ( - V_43 ) ;
V_59 -> V_10 = V_10 = F_59 ( & V_90 ) ;
if ( ! V_10 ) {
F_8 ( L_12 ) ;
F_6 ( V_59 ) ;
return F_48 ( - V_43 ) ;
}
F_60 ( V_59 -> V_10 , F_7 , NULL ) ;
F_61 ( & V_59 -> V_71 ) ;
F_22 ( & V_59 -> V_91 ) ;
return V_59 ;
}
void F_62 ( struct V_58 * V_59 )
{
F_63 ( V_59 -> V_10 ) ;
F_6 ( V_59 ) ;
}
int F_64 ( struct V_58 * V_59 , struct V_11 * V_12 )
{
struct V_92 * V_93 ;
int V_74 ;
V_93 = F_58 ( sizeof( * V_93 ) , V_94 ) ;
if ( ! V_93 )
return - V_43 ;
V_93 -> V_12 = V_12 ;
V_74 = F_65 ( V_59 -> V_10 , V_12 ) ;
if ( V_74 )
goto V_95;
if ( ! F_66 ( V_12 -> V_96 , V_97 ) ) {
F_8 ( L_13 ,
F_9 ( V_12 ) ) ;
V_74 = - V_78 ;
goto V_98;
}
F_38 ( & V_59 -> V_71 ) ;
F_32 ( & V_93 -> V_73 , & V_59 -> V_91 ) ;
V_59 -> V_99 ++ ;
F_41 ( & V_59 -> V_71 ) ;
return 0 ;
V_98:
F_67 ( V_59 -> V_10 , V_12 ) ;
V_95:
F_6 ( V_93 ) ;
return V_74 ;
}
void F_68 ( struct V_58 * V_59 , struct V_11 * V_12 )
{
struct V_92 * V_93 ;
int V_100 = 0 ;
F_38 ( & V_59 -> V_71 ) ;
F_44 (uiom_dev, &pd->devs, link) {
if ( V_93 -> V_12 == V_12 ) {
V_100 = 1 ;
break;
}
}
if ( ! V_100 ) {
F_8 ( L_14 ,
F_9 ( V_12 ) ) ;
F_41 ( & V_59 -> V_71 ) ;
return;
}
F_40 ( & V_93 -> V_73 ) ;
V_59 -> V_99 -- ;
F_41 ( & V_59 -> V_71 ) ;
return F_67 ( V_59 -> V_10 , V_12 ) ;
}
struct V_11 * * F_69 ( struct V_58 * V_59 )
{
struct V_92 * V_93 ;
struct V_11 * * V_91 ;
int V_26 = 0 ;
F_38 ( & V_59 -> V_71 ) ;
V_91 = F_70 ( V_59 -> V_99 + 1 , sizeof( * V_91 ) , V_94 ) ;
if ( ! V_91 ) {
V_91 = F_48 ( - V_43 ) ;
goto V_49;
}
F_44 (uiom_dev, &pd->devs, link) {
V_91 [ V_26 ++ ] = V_93 -> V_12 ;
}
V_49:
F_41 ( & V_59 -> V_71 ) ;
return V_91 ;
}
void F_71 ( struct V_11 * * V_91 )
{
F_6 ( V_91 ) ;
}
int F_72 ( char * V_101 )
{
if ( ! F_73 ( & V_90 ) ) {
F_8 ( L_15 ) ;
return - V_41 ;
}
V_89 = F_74 ( V_101 ) ;
if ( ! V_89 ) {
F_8 ( L_16 , V_101 ) ;
return - V_43 ;
}
return 0 ;
}
void F_75 ( void )
{
F_76 ( V_89 ) ;
F_77 ( V_89 ) ;
}
