void
F_1 ( struct V_1 * V_2 , T_1 V_3 , struct V_4 * V_5 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_9 ;
struct V_10 * V_11 ;
int V_12 = V_2 -> V_5 -> type != V_9 -> V_13 ;
T_2 V_14 = V_2 -> V_5 -> V_14 + ( V_3 >> 12 ) ;
T_2 V_15 = V_2 -> V_5 -> type - 12 ;
T_2 V_16 = ( V_14 >> V_9 -> V_17 ) - V_7 -> V_18 ;
T_2 V_19 = ( V_14 & ( ( 1 << V_9 -> V_17 ) - 1 ) ) >> V_15 ;
T_2 V_20 = 1 << ( V_9 -> V_17 - V_15 ) ;
T_2 V_21 , V_22 ;
V_3 = 0 ;
F_2 (r, &node->regions, rl_entry) {
T_1 V_23 = ( T_1 ) V_11 -> V_14 << 12 ;
T_2 V_24 = V_11 -> V_25 >> V_15 ;
while ( V_24 ) {
struct V_26 * V_27 = V_7 -> V_27 [ V_16 ] . V_28 [ V_12 ] ;
V_21 = ( V_19 + V_24 ) ;
if ( F_3 ( V_21 >= V_20 ) )
V_21 = V_20 ;
V_22 = V_21 - V_19 ;
V_9 -> V_29 ( V_2 , V_27 , V_5 , V_19 , V_22 , V_23 , V_3 ) ;
V_24 -= V_22 ;
V_19 += V_22 ;
if ( F_3 ( V_21 >= V_20 ) ) {
V_23 += V_22 << ( V_15 + 12 ) ;
V_16 ++ ;
V_19 = 0 ;
}
V_3 += ( T_1 ) V_22 << V_2 -> V_5 -> type ;
}
}
V_9 -> V_30 ( V_7 ) ;
}
static void
F_4 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_25 ,
struct V_4 * V_31 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_9 ;
int V_12 = V_2 -> V_5 -> type != V_9 -> V_13 ;
T_2 V_14 = V_2 -> V_5 -> V_14 + ( V_3 >> 12 ) ;
T_2 V_15 = V_2 -> V_5 -> type - 12 ;
T_2 V_24 = V_25 >> V_2 -> V_5 -> type ;
T_2 V_16 = ( V_14 >> V_9 -> V_17 ) - V_7 -> V_18 ;
T_2 V_19 = ( V_14 & ( ( 1 << V_9 -> V_17 ) - 1 ) ) >> V_15 ;
T_2 V_20 = 1 << ( V_9 -> V_17 - V_15 ) ;
unsigned V_32 , V_33 ;
T_2 V_21 , V_22 ;
int V_34 ;
struct V_35 * V_36 ;
F_5 (mem->sg->sgl, sg, mem->sg->nents, i) {
struct V_26 * V_27 = V_7 -> V_27 [ V_16 ] . V_28 [ V_12 ] ;
V_33 = F_6 ( V_36 ) >> V_37 ;
V_21 = V_19 + V_33 ;
if ( F_3 ( V_21 >= V_20 ) )
V_21 = V_20 ;
V_22 = V_21 - V_19 ;
for ( V_32 = 0 ; V_32 < V_22 ; V_32 ++ ) {
T_3 V_38 = F_7 ( V_36 ) + ( V_32 << V_37 ) ;
V_9 -> V_39 ( V_2 , V_27 , V_31 , V_19 , 1 , & V_38 ) ;
V_24 -- ;
V_19 ++ ;
if ( V_24 == 0 )
goto V_40;
}
if ( F_3 ( V_21 >= V_20 ) ) {
V_16 ++ ;
V_19 = 0 ;
}
if ( V_32 < V_33 ) {
for (; V_32 < V_33 ; V_32 ++ ) {
T_3 V_38 = F_7 ( V_36 ) + ( V_32 << V_37 ) ;
V_9 -> V_39 ( V_2 , V_27 , V_31 , V_19 , 1 , & V_38 ) ;
V_24 -- ;
V_19 ++ ;
if ( V_24 == 0 )
goto V_40;
}
}
}
V_40:
V_9 -> V_30 ( V_7 ) ;
}
static void
F_8 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_25 ,
struct V_4 * V_31 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_9 ;
T_3 * V_41 = V_31 -> V_42 ;
int V_12 = V_2 -> V_5 -> type != V_9 -> V_13 ;
T_2 V_14 = V_2 -> V_5 -> V_14 + ( V_3 >> 12 ) ;
T_2 V_15 = V_2 -> V_5 -> type - 12 ;
T_2 V_24 = V_25 >> V_2 -> V_5 -> type ;
T_2 V_16 = ( V_14 >> V_9 -> V_17 ) - V_7 -> V_18 ;
T_2 V_19 = ( V_14 & ( ( 1 << V_9 -> V_17 ) - 1 ) ) >> V_15 ;
T_2 V_20 = 1 << ( V_9 -> V_17 - V_15 ) ;
T_2 V_21 , V_22 ;
while ( V_24 ) {
struct V_26 * V_27 = V_7 -> V_27 [ V_16 ] . V_28 [ V_12 ] ;
V_21 = ( V_19 + V_24 ) ;
if ( F_3 ( V_21 >= V_20 ) )
V_21 = V_20 ;
V_22 = V_21 - V_19 ;
V_9 -> V_39 ( V_2 , V_27 , V_31 , V_19 , V_22 , V_41 ) ;
V_24 -= V_22 ;
V_19 += V_22 ;
V_41 += V_22 ;
if ( F_3 ( V_21 >= V_20 ) ) {
V_16 ++ ;
V_19 = 0 ;
}
}
V_9 -> V_30 ( V_7 ) ;
}
void
F_9 ( struct V_1 * V_2 , struct V_4 * V_5 )
{
if ( V_5 -> V_36 )
F_4 ( V_2 , 0 , V_5 -> V_43 << 12 , V_5 ) ;
else
if ( V_5 -> V_42 )
F_8 ( V_2 , 0 , V_5 -> V_43 << 12 , V_5 ) ;
else
F_1 ( V_2 , 0 , V_5 ) ;
}
void
F_10 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_25 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_9 ;
int V_12 = V_2 -> V_5 -> type != V_9 -> V_13 ;
T_2 V_14 = V_2 -> V_5 -> V_14 + ( V_3 >> 12 ) ;
T_2 V_15 = V_2 -> V_5 -> type - 12 ;
T_2 V_24 = V_25 >> V_2 -> V_5 -> type ;
T_2 V_16 = ( V_14 >> V_9 -> V_17 ) - V_7 -> V_18 ;
T_2 V_19 = ( V_14 & ( ( 1 << V_9 -> V_17 ) - 1 ) ) >> V_15 ;
T_2 V_20 = 1 << ( V_9 -> V_17 - V_15 ) ;
T_2 V_21 , V_22 ;
while ( V_24 ) {
struct V_26 * V_27 = V_7 -> V_27 [ V_16 ] . V_28 [ V_12 ] ;
V_21 = ( V_19 + V_24 ) ;
if ( F_3 ( V_21 >= V_20 ) )
V_21 = V_20 ;
V_22 = V_21 - V_19 ;
V_9 -> V_44 ( V_27 , V_19 , V_22 ) ;
V_24 -= V_22 ;
V_19 += V_22 ;
if ( F_3 ( V_21 >= V_20 ) ) {
V_16 ++ ;
V_19 = 0 ;
}
}
V_9 -> V_30 ( V_7 ) ;
}
void
F_11 ( struct V_1 * V_2 )
{
F_10 ( V_2 , 0 , ( T_1 ) V_2 -> V_5 -> V_25 << 12 ) ;
}
static void
F_12 ( struct V_6 * V_7 , int V_12 , T_2 V_18 , T_2 V_45 )
{
struct V_8 * V_9 = V_7 -> V_9 ;
struct V_46 * V_47 ;
struct V_48 * V_49 ;
struct V_26 * V_27 ;
T_2 V_16 ;
for ( V_16 = V_18 ; V_16 <= V_45 ; V_16 ++ ) {
V_49 = & V_7 -> V_27 [ V_16 - V_7 -> V_18 ] ;
if ( -- V_49 -> V_50 [ V_12 ] )
continue;
V_27 = V_49 -> V_28 [ V_12 ] ;
V_49 -> V_28 [ V_12 ] = NULL ;
F_2 (vpgd, &vm->pgd_list, head) {
V_9 -> V_51 ( V_47 -> V_28 , V_16 , V_49 -> V_28 ) ;
}
F_13 ( & F_14 ( V_9 ) -> V_52 ) ;
F_15 ( NULL , & V_27 ) ;
F_16 ( & F_14 ( V_9 ) -> V_52 ) ;
}
}
static int
F_17 ( struct V_6 * V_7 , T_2 V_16 , T_2 type )
{
struct V_8 * V_9 = V_7 -> V_9 ;
struct V_48 * V_49 = & V_7 -> V_27 [ V_16 - V_7 -> V_18 ] ;
struct V_46 * V_47 ;
struct V_26 * V_27 ;
int V_12 = ( type != V_9 -> V_13 ) ;
T_2 V_53 ;
int V_54 ;
V_53 = ( 1 << ( V_9 -> V_17 + 12 ) ) >> type ;
V_53 *= 8 ;
F_13 ( & F_14 ( V_9 ) -> V_52 ) ;
V_54 = F_18 ( F_19 ( V_7 -> V_9 ) , NULL , V_53 , 0x1000 ,
V_55 , & V_27 ) ;
F_16 ( & F_14 ( V_9 ) -> V_52 ) ;
if ( F_3 ( V_54 ) )
return V_54 ;
if ( F_3 ( V_49 -> V_50 [ V_12 ] ++ ) ) {
F_13 ( & F_14 ( V_9 ) -> V_52 ) ;
F_15 ( NULL , & V_27 ) ;
F_16 ( & F_14 ( V_9 ) -> V_52 ) ;
return 0 ;
}
V_49 -> V_28 [ V_12 ] = V_27 ;
F_2 (vpgd, &vm->pgd_list, head) {
V_9 -> V_51 ( V_47 -> V_28 , V_16 , V_49 -> V_28 ) ;
}
return 0 ;
}
int
F_20 ( struct V_6 * V_7 , T_1 V_43 , T_2 V_56 ,
T_2 V_57 , struct V_1 * V_2 )
{
struct V_8 * V_9 = V_7 -> V_9 ;
T_2 V_58 = ( 1 << V_56 ) >> 12 ;
T_2 V_59 = V_43 >> 12 ;
T_2 V_18 , V_45 , V_16 ;
int V_54 ;
F_16 ( & F_14 ( V_9 ) -> V_52 ) ;
V_54 = F_21 ( & V_7 -> V_60 , 0 , V_56 , V_59 , V_59 , V_58 ,
& V_2 -> V_5 ) ;
if ( F_3 ( V_54 != 0 ) ) {
F_13 ( & F_14 ( V_9 ) -> V_52 ) ;
return V_54 ;
}
V_18 = ( V_2 -> V_5 -> V_14 >> V_9 -> V_17 ) ;
V_45 = ( V_2 -> V_5 -> V_14 + V_2 -> V_5 -> V_25 - 1 ) >> V_9 -> V_17 ;
for ( V_16 = V_18 ; V_16 <= V_45 ; V_16 ++ ) {
struct V_48 * V_49 = & V_7 -> V_27 [ V_16 - V_7 -> V_18 ] ;
int V_12 = ( V_2 -> V_5 -> type != V_9 -> V_13 ) ;
if ( F_22 ( V_49 -> V_50 [ V_12 ] ) ) {
V_49 -> V_50 [ V_12 ] ++ ;
continue;
}
V_54 = F_17 ( V_7 , V_16 , V_2 -> V_5 -> type ) ;
if ( V_54 ) {
if ( V_16 != V_18 )
F_12 ( V_7 , V_12 , V_18 , V_16 - 1 ) ;
F_23 ( & V_7 -> V_60 , & V_2 -> V_5 ) ;
F_13 ( & F_14 ( V_9 ) -> V_52 ) ;
return V_54 ;
}
}
F_13 ( & F_14 ( V_9 ) -> V_52 ) ;
V_2 -> V_7 = NULL ;
F_24 ( V_7 , & V_2 -> V_7 , NULL ) ;
V_2 -> V_14 = ( T_1 ) V_2 -> V_5 -> V_14 << 12 ;
V_2 -> V_57 = V_57 ;
return 0 ;
}
void
F_25 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_9 ;
T_2 V_18 , V_45 ;
if ( F_3 ( V_2 -> V_5 == NULL ) )
return;
V_18 = ( V_2 -> V_5 -> V_14 >> V_9 -> V_17 ) ;
V_45 = ( V_2 -> V_5 -> V_14 + V_2 -> V_5 -> V_25 - 1 ) >> V_9 -> V_17 ;
F_16 ( & F_14 ( V_9 ) -> V_52 ) ;
F_12 ( V_7 , V_2 -> V_5 -> type != V_9 -> V_13 , V_18 , V_45 ) ;
F_23 ( & V_7 -> V_60 , & V_2 -> V_5 ) ;
F_13 ( & F_14 ( V_9 ) -> V_52 ) ;
F_24 ( NULL , & V_2 -> V_7 , NULL ) ;
}
int
F_26 ( struct V_8 * V_9 , T_1 V_14 , T_1 V_25 ,
T_1 V_61 , T_2 V_62 , struct V_6 * * V_63 )
{
struct V_6 * V_7 ;
T_1 V_64 = ( V_14 + V_25 ) - V_61 ;
int V_54 ;
V_7 = F_27 ( sizeof( * V_7 ) , V_65 ) ;
if ( ! V_7 )
return - V_66 ;
F_28 ( & V_7 -> V_67 ) ;
V_7 -> V_9 = V_9 ;
F_29 ( & V_7 -> V_50 ) ;
V_7 -> V_18 = V_14 >> ( V_9 -> V_17 + 12 ) ;
V_7 -> V_45 = ( V_14 + V_25 - 1 ) >> ( V_9 -> V_17 + 12 ) ;
V_7 -> V_27 = F_30 ( ( V_7 -> V_45 - V_7 -> V_18 + 1 ) * sizeof( * V_7 -> V_27 ) ) ;
if ( ! V_7 -> V_27 ) {
F_31 ( V_7 ) ;
return - V_66 ;
}
V_54 = F_32 ( & V_7 -> V_60 , V_61 >> 12 , V_64 >> 12 ,
V_62 >> 12 ) ;
if ( V_54 ) {
F_33 ( V_7 -> V_27 ) ;
F_31 ( V_7 ) ;
return V_54 ;
}
* V_63 = V_7 ;
return 0 ;
}
int
F_34 ( struct V_68 * V_69 , T_1 V_14 , T_1 V_25 ,
T_1 V_61 , struct V_6 * * V_63 )
{
struct V_8 * V_9 = V_8 ( V_69 ) ;
return V_9 -> V_70 ( V_9 , V_14 , V_25 , V_61 , V_63 ) ;
}
static int
F_35 ( struct V_6 * V_7 , struct V_26 * V_71 )
{
struct V_8 * V_9 = V_7 -> V_9 ;
struct V_46 * V_47 ;
int V_34 ;
if ( ! V_71 )
return 0 ;
V_47 = F_27 ( sizeof( * V_47 ) , V_65 ) ;
if ( ! V_47 )
return - V_66 ;
F_15 ( V_71 , & V_47 -> V_28 ) ;
F_16 ( & F_14 ( V_9 ) -> V_52 ) ;
for ( V_34 = V_7 -> V_18 ; V_34 <= V_7 -> V_45 ; V_34 ++ )
V_9 -> V_51 ( V_71 , V_34 , V_7 -> V_27 [ V_34 - V_7 -> V_18 ] . V_28 ) ;
F_36 ( & V_47 -> V_72 , & V_7 -> V_67 ) ;
F_13 ( & F_14 ( V_9 ) -> V_52 ) ;
return 0 ;
}
static void
F_37 ( struct V_6 * V_7 , struct V_26 * V_73 )
{
struct V_8 * V_9 = V_7 -> V_9 ;
struct V_46 * V_47 , * V_74 ;
struct V_26 * V_71 = NULL ;
if ( ! V_73 )
return;
F_16 ( & F_14 ( V_9 ) -> V_52 ) ;
F_38 (vpgd, tmp, &vm->pgd_list, head) {
if ( V_47 -> V_28 == V_73 ) {
V_71 = V_47 -> V_28 ;
F_39 ( & V_47 -> V_72 ) ;
F_31 ( V_47 ) ;
break;
}
}
F_13 ( & F_14 ( V_9 ) -> V_52 ) ;
F_15 ( NULL , & V_71 ) ;
}
static void
F_40 ( struct V_75 * V_75 )
{
struct V_6 * V_7 = F_41 ( V_75 , F_42 ( * V_7 ) , V_50 ) ;
struct V_46 * V_47 , * V_74 ;
F_38 (vpgd, tmp, &vm->pgd_list, head) {
F_37 ( V_7 , V_47 -> V_28 ) ;
}
F_43 ( & V_7 -> V_60 ) ;
F_33 ( V_7 -> V_27 ) ;
F_31 ( V_7 ) ;
}
int
F_24 ( struct V_6 * V_76 , struct V_6 * * V_77 ,
struct V_26 * V_71 )
{
if ( V_76 ) {
int V_54 = F_35 ( V_76 , V_71 ) ;
if ( V_54 )
return V_54 ;
F_44 ( & V_76 -> V_50 ) ;
}
if ( * V_77 ) {
F_37 ( * V_77 , V_71 ) ;
F_45 ( & ( * V_77 ) -> V_50 , F_40 ) ;
}
* V_77 = V_76 ;
return 0 ;
}
