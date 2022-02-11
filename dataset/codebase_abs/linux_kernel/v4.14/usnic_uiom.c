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
unsigned int V_39 ;
if ( ! F_19 () )
return - V_40 ;
F_20 ( V_18 ) ;
V_32 = (struct V_23 * * ) F_21 ( V_41 ) ;
if ( ! V_32 )
return - V_42 ;
V_36 = F_22 ( V_29 + ( V_28 & ~ V_43 ) ) >> V_44 ;
F_3 ( & V_45 -> V_5 -> V_6 ) ;
V_33 = V_36 + V_45 -> V_5 -> V_7 ;
V_34 = F_23 ( V_46 ) >> V_44 ;
if ( ( V_33 > V_34 ) && ! F_24 ( V_47 ) ) {
V_37 = - V_42 ;
goto V_48;
}
V_14 = V_49 | V_50 ;
V_14 |= ( V_30 ) ? V_51 : 0 ;
V_39 = V_52 ;
V_39 |= ( V_30 ) ? 0 : V_53 ;
V_35 = V_28 & V_43 ;
V_37 = 0 ;
while ( V_36 ) {
V_37 = F_25 ( V_35 ,
F_26 (unsigned long, npages,
PAGE_SIZE / sizeof(struct page *)) ,
V_39 , V_32 , NULL ) ;
if ( V_37 < 0 )
goto V_48;
V_36 -= V_37 ;
V_38 = 0 ;
while ( V_37 ) {
V_21 = F_27 ( sizeof( * V_21 ) +
sizeof( struct V_24 ) *
F_26 ( int , V_37 , V_54 ) ,
V_41 ) ;
if ( ! V_21 ) {
V_37 = - V_42 ;
goto V_48;
}
V_21 -> V_55 = F_26 ( int , V_37 , V_54 ) ;
F_28 ( V_21 -> V_32 , V_21 -> V_55 ) ;
F_12 (chunk->page_list, sg, chunk->nents, i) {
F_29 ( V_25 , V_32 [ V_26 + V_38 ] ,
V_56 , 0 ) ;
V_27 = F_14 ( V_25 ) ;
F_17 ( L_3 ,
V_35 + V_26 * V_56 , & V_27 ) ;
}
V_35 += V_21 -> V_55 * V_56 ;
V_37 -= V_21 -> V_55 ;
V_38 += V_21 -> V_55 ;
F_30 ( & V_21 -> V_57 , V_18 ) ;
}
V_37 = 0 ;
}
V_48:
if ( V_37 < 0 )
F_10 ( V_18 , 0 ) ;
else
V_45 -> V_5 -> V_7 = V_33 ;
F_4 ( & V_45 -> V_5 -> V_6 ) ;
F_31 ( ( unsigned long ) V_32 ) ;
return V_37 ;
}
static void F_32 ( struct V_17 * V_58 ,
struct V_59 * V_60 )
{
struct V_61 * V_62 , * V_22 ;
long unsigned V_63 , V_29 ;
F_11 (interval, tmp, intervals, link) {
V_63 = V_62 -> V_64 << V_44 ;
V_29 = ( ( V_62 -> V_65 - V_62 -> V_64 ) + 1 ) << V_44 ;
while ( V_29 > 0 ) {
F_17 ( L_4 , V_63 , V_56 ) ;
F_33 ( V_60 -> V_10 , V_63 , V_56 ) ;
V_63 += V_56 ;
V_29 -= V_56 ;
}
}
}
static void F_34 ( struct V_59 * V_60 ,
struct V_3 * V_66 ,
int V_19 )
{
int V_36 ;
unsigned long V_67 , V_68 ;
struct V_61 * V_62 , * V_22 ;
int V_30 = 0 ;
F_35 ( V_69 ) ;
V_36 = F_22 ( V_66 -> V_70 + V_66 -> V_71 ) >> V_44 ;
V_67 = ( V_66 -> V_63 & V_43 ) >> V_44 ;
V_68 = V_67 + V_36 - 1 ;
F_36 ( & V_60 -> V_72 ) ;
F_37 ( & V_60 -> V_73 , V_67 ,
V_68 , & V_69 ) ;
F_32 ( & V_69 , V_60 ) ;
F_11 (interval, tmp, &rm_intervals, link) {
if ( V_62 -> V_14 & V_51 )
V_30 = 1 ;
F_38 ( & V_62 -> V_74 ) ;
F_6 ( V_62 ) ;
}
F_10 ( & V_66 -> V_18 , V_19 & V_30 ) ;
F_39 ( & V_60 -> V_72 ) ;
}
static int F_40 ( struct V_17 * V_58 ,
struct V_3 * V_66 )
{
int V_26 , V_75 ;
T_2 V_29 ;
struct V_20 * V_21 ;
struct V_61 * V_76 ;
T_1 V_27 ;
T_1 V_77 = 0 ;
T_1 V_78 = 0 ;
long int va_start = - V_79 ;
struct V_59 * V_60 = V_66 -> V_60 ;
long int V_63 = V_66 -> V_63 & V_43 ;
int V_14 = V_49 | V_50 ;
V_14 |= ( V_66 -> V_30 ) ? V_51 : 0 ;
V_21 = F_41 ( & V_66 -> V_18 , struct V_20 ,
V_57 ) ;
F_42 (interval_node, intervals, link) {
V_80:
for ( V_26 = 0 ; V_26 < V_21 -> V_55 ; V_26 ++ , V_63 += V_56 ) {
V_27 = F_14 ( & V_21 -> V_32 [ V_26 ] ) ;
if ( ( V_63 >> V_44 ) < V_76 -> V_64 )
continue;
if ( ( V_63 >> V_44 ) == V_76 -> V_64 ) {
va_start = V_63 ;
V_77 = V_27 ;
V_78 = V_27 ;
}
F_43 ( va_start == - V_79 ) ;
if ( ( V_78 + V_56 != V_27 ) &&
( V_27 != V_77 ) ) {
V_29 = V_78 - V_77 + V_56 ;
F_17 ( L_5 ,
va_start , & V_77 , V_29 , V_14 ) ;
V_75 = F_44 ( V_60 -> V_10 , va_start , V_77 ,
V_29 , V_14 ) ;
if ( V_75 ) {
F_8 ( L_6 ,
va_start , & V_77 , V_29 , V_75 ) ;
goto V_81;
}
va_start = V_63 ;
V_77 = V_27 ;
V_78 = V_27 ;
}
if ( ( V_63 >> V_44 ) == V_76 -> V_65 ) {
V_29 = V_27 - V_77 + V_56 ;
F_17 ( L_7 ,
va_start , & V_77 , V_29 , V_14 ) ;
V_75 = F_44 ( V_60 -> V_10 , va_start , V_77 ,
V_29 , V_14 ) ;
if ( V_75 ) {
F_8 ( L_6 ,
va_start , & V_77 , V_29 , V_75 ) ;
goto V_81;
}
break;
}
if ( V_27 != V_77 )
V_78 += V_56 ;
}
if ( V_26 == V_21 -> V_55 ) {
V_21 = F_41 ( & V_21 -> V_57 ,
struct V_20 ,
V_57 ) ;
goto V_80;
}
}
return 0 ;
V_81:
F_32 ( V_58 , V_60 ) ;
return V_75 ;
}
struct V_3 * F_45 ( struct V_59 * V_60 ,
unsigned long V_28 , T_2 V_29 ,
int V_30 , int V_31 )
{
struct V_3 * V_66 ;
unsigned long V_82 , V_67 , V_68 ;
unsigned long V_36 ;
int V_71 , V_75 ;
F_35 ( V_83 ) ;
V_30 = 1 ;
V_82 = V_28 & V_43 ;
V_71 = V_28 & ~ V_43 ;
V_36 = F_22 ( V_29 + V_71 ) >> V_44 ;
V_67 = ( V_28 & V_43 ) >> V_44 ;
V_68 = V_67 + V_36 - 1 ;
V_66 = F_27 ( sizeof( * V_66 ) , V_41 ) ;
if ( ! V_66 )
return F_46 ( - V_42 ) ;
V_66 -> V_63 = V_82 ;
V_66 -> V_71 = V_71 ;
V_66 -> V_70 = V_29 ;
V_66 -> V_30 = V_30 ;
V_66 -> V_60 = V_60 ;
V_75 = F_18 ( V_28 , V_29 , V_30 , V_31 ,
& V_66 -> V_18 ) ;
if ( V_75 ) {
F_8 ( L_8 ,
V_67 , V_68 , V_75 ) ;
goto V_84;
}
F_36 ( & V_60 -> V_72 ) ;
V_75 = F_47 ( V_67 , V_68 ,
( V_30 ) ? V_51 : 0 ,
V_51 ,
& V_60 -> V_73 ,
& V_83 ) ;
if ( V_75 ) {
F_8 ( L_9 ,
V_67 , V_68 , V_75 ) ;
goto V_85;
}
V_75 = F_40 ( & V_83 , V_66 ) ;
if ( V_75 ) {
F_8 ( L_10 ,
V_67 , V_68 , V_75 ) ;
goto V_86;
}
V_75 = F_48 ( & V_60 -> V_73 , V_67 , V_68 ,
( V_30 ) ? V_51 : 0 ) ;
if ( V_75 ) {
F_8 ( L_11 ,
V_67 , V_68 , V_75 ) ;
goto V_87;
}
F_49 ( & V_83 ) ;
F_39 ( & V_60 -> V_72 ) ;
return V_66 ;
V_87:
F_32 ( & V_83 , V_60 ) ;
V_86:
F_49 ( & V_83 ) ;
V_85:
F_10 ( & V_66 -> V_18 , 0 ) ;
F_39 ( & V_60 -> V_72 ) ;
V_84:
F_6 ( V_66 ) ;
return F_46 ( V_75 ) ;
}
void F_50 ( struct V_3 * V_66 , int V_88 )
{
struct V_89 * V_5 ;
unsigned long V_8 ;
F_34 ( V_66 -> V_60 , V_66 , 1 ) ;
V_5 = F_51 ( V_45 ) ;
if ( ! V_5 ) {
F_6 ( V_66 ) ;
return;
}
V_8 = F_22 ( V_66 -> V_70 + V_66 -> V_71 ) >> V_44 ;
if ( V_88 ) {
if ( ! F_52 ( & V_5 -> V_6 ) ) {
F_53 ( & V_66 -> V_2 , F_1 ) ;
V_66 -> V_5 = V_5 ;
V_66 -> V_8 = V_8 ;
F_54 ( V_90 , & V_66 -> V_2 ) ;
return;
}
} else
F_3 ( & V_5 -> V_6 ) ;
V_45 -> V_5 -> V_7 -= V_8 ;
F_4 ( & V_5 -> V_6 ) ;
F_5 ( V_5 ) ;
F_6 ( V_66 ) ;
}
struct V_59 * F_55 ( void )
{
struct V_59 * V_60 ;
void * V_10 ;
V_60 = F_56 ( sizeof( * V_60 ) , V_41 ) ;
if ( ! V_60 )
return F_46 ( - V_42 ) ;
V_60 -> V_10 = V_10 = F_57 ( & V_91 ) ;
if ( ! V_10 ) {
F_8 ( L_12 ) ;
F_6 ( V_60 ) ;
return F_46 ( - V_42 ) ;
}
F_58 ( V_60 -> V_10 , F_7 , NULL ) ;
F_59 ( & V_60 -> V_72 ) ;
F_20 ( & V_60 -> V_92 ) ;
return V_60 ;
}
void F_60 ( struct V_59 * V_60 )
{
F_61 ( V_60 -> V_10 ) ;
F_6 ( V_60 ) ;
}
int F_62 ( struct V_59 * V_60 , struct V_11 * V_12 )
{
struct V_93 * V_94 ;
int V_75 ;
V_94 = F_56 ( sizeof( * V_94 ) , V_95 ) ;
if ( ! V_94 )
return - V_42 ;
V_94 -> V_12 = V_12 ;
V_75 = F_63 ( V_60 -> V_10 , V_12 ) ;
if ( V_75 )
goto V_96;
if ( ! F_64 ( V_12 -> V_97 , V_98 ) ) {
F_8 ( L_13 ,
F_9 ( V_12 ) ) ;
V_75 = - V_79 ;
goto V_99;
}
F_36 ( & V_60 -> V_72 ) ;
F_30 ( & V_94 -> V_74 , & V_60 -> V_92 ) ;
V_60 -> V_100 ++ ;
F_39 ( & V_60 -> V_72 ) ;
return 0 ;
V_99:
F_65 ( V_60 -> V_10 , V_12 ) ;
V_96:
F_6 ( V_94 ) ;
return V_75 ;
}
void F_66 ( struct V_59 * V_60 , struct V_11 * V_12 )
{
struct V_93 * V_94 ;
int V_101 = 0 ;
F_36 ( & V_60 -> V_72 ) ;
F_42 (uiom_dev, &pd->devs, link) {
if ( V_94 -> V_12 == V_12 ) {
V_101 = 1 ;
break;
}
}
if ( ! V_101 ) {
F_8 ( L_14 ,
F_9 ( V_12 ) ) ;
F_39 ( & V_60 -> V_72 ) ;
return;
}
F_38 ( & V_94 -> V_74 ) ;
V_60 -> V_100 -- ;
F_39 ( & V_60 -> V_72 ) ;
return F_65 ( V_60 -> V_10 , V_12 ) ;
}
struct V_11 * * F_67 ( struct V_59 * V_60 )
{
struct V_93 * V_94 ;
struct V_11 * * V_92 ;
int V_26 = 0 ;
F_36 ( & V_60 -> V_72 ) ;
V_92 = F_68 ( V_60 -> V_100 + 1 , sizeof( * V_92 ) , V_95 ) ;
if ( ! V_92 ) {
V_92 = F_46 ( - V_42 ) ;
goto V_48;
}
F_42 (uiom_dev, &pd->devs, link) {
V_92 [ V_26 ++ ] = V_94 -> V_12 ;
}
V_48:
F_39 ( & V_60 -> V_72 ) ;
return V_92 ;
}
void F_69 ( struct V_11 * * V_92 )
{
F_6 ( V_92 ) ;
}
int F_70 ( char * V_102 )
{
if ( ! F_71 ( & V_91 ) ) {
F_8 ( L_15 ) ;
return - V_40 ;
}
V_90 = F_72 ( V_102 ) ;
if ( ! V_90 ) {
F_8 ( L_16 , V_102 ) ;
return - V_42 ;
}
return 0 ;
}
void F_73 ( void )
{
F_74 ( V_90 ) ;
F_75 ( V_90 ) ;
}
