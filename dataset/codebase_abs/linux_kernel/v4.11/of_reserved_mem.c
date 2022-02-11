int T_1 __weak F_1 ( T_2 V_1 ,
T_2 V_2 , T_2 V_3 , T_2 V_4 , bool V_5 ,
T_2 * V_6 )
{
T_2 V_7 ;
V_4 = ! V_4 ? V_8 : V_4 ;
V_7 = F_2 ( V_1 , V_2 , V_4 ) ;
if ( ! V_7 )
return - V_9 ;
if ( V_7 < V_3 ) {
F_3 ( V_7 , V_1 ) ;
return - V_9 ;
}
* V_6 = V_7 ;
if ( V_5 )
return F_4 ( V_7 , V_1 ) ;
return 0 ;
}
int T_1 __weak F_1 ( T_2 V_1 ,
T_2 V_2 , T_2 V_3 , T_2 V_4 , bool V_5 ,
T_2 * V_6 )
{
F_5 ( L_1 ,
V_1 , V_5 ? L_2 : L_3 ) ;
return - V_10 ;
}
void T_1 F_6 ( unsigned long V_11 , const char * V_12 ,
T_2 V_7 , T_2 V_1 )
{
struct V_13 * V_14 = & V_13 [ V_15 ] ;
if ( V_15 == F_7 ( V_13 ) ) {
F_5 ( L_4 ) ;
return;
}
V_14 -> V_16 = V_11 ;
V_14 -> V_17 = V_12 ;
V_14 -> V_7 = V_7 ;
V_14 -> V_1 = V_1 ;
V_15 ++ ;
return;
}
static int T_1 F_8 ( unsigned long V_11 ,
const char * V_12 , T_2 * V_6 , T_2 * V_18 )
{
int V_19 = ( V_20 + V_21 ) * sizeof( V_22 ) ;
T_2 V_3 = 0 , V_4 = 0 ;
T_2 V_7 = 0 , V_2 = 0 , V_1 ;
int V_23 ;
const V_22 * V_24 ;
int V_5 ;
int V_25 ;
V_24 = F_9 ( V_11 , L_5 , & V_23 ) ;
if ( ! V_24 )
return - V_26 ;
if ( V_23 != V_21 * sizeof( V_22 ) ) {
F_5 ( L_6 , V_12 ) ;
return - V_26 ;
}
V_1 = F_10 ( V_21 , & V_24 ) ;
V_5 = F_9 ( V_11 , L_7 , NULL ) != NULL ;
V_24 = F_9 ( V_11 , L_8 , & V_23 ) ;
if ( V_24 ) {
if ( V_23 != V_20 * sizeof( V_22 ) ) {
F_5 ( L_9 ,
V_12 ) ;
return - V_26 ;
}
V_2 = F_10 ( V_20 , & V_24 ) ;
}
if ( F_11 ( V_27 )
&& F_12 ( V_11 , L_10 )
&& F_9 ( V_11 , L_11 , NULL )
&& ! F_9 ( V_11 , L_7 , NULL ) ) {
unsigned long V_28 =
F_13 (unsigned long, MAX_ORDER - 1 , pageblock_order) ;
V_2 = F_14 ( V_2 , ( T_2 ) V_29 << V_28 ) ;
}
V_24 = F_9 ( V_11 , L_12 , & V_23 ) ;
if ( V_24 ) {
if ( V_23 % V_19 != 0 ) {
F_5 ( L_13 ,
V_12 ) ;
return - V_26 ;
}
V_7 = 0 ;
while ( V_23 > 0 ) {
V_3 = F_10 ( V_20 , & V_24 ) ;
V_4 = V_3 + F_10 ( V_21 ,
& V_24 ) ;
V_25 = F_1 ( V_1 ,
V_2 , V_3 , V_4 , V_5 , & V_7 ) ;
if ( V_25 == 0 ) {
F_15 ( L_14 ,
V_12 , & V_7 ,
( unsigned long ) V_1 / V_30 ) ;
break;
}
V_23 -= V_19 ;
}
} else {
V_25 = F_1 ( V_1 , V_2 ,
0 , 0 , V_5 , & V_7 ) ;
if ( V_25 == 0 )
F_15 ( L_14 ,
V_12 , & V_7 , ( unsigned long ) V_1 / V_30 ) ;
}
if ( V_7 == 0 ) {
F_16 ( L_15 , V_12 ) ;
return - V_9 ;
}
* V_6 = V_7 ;
* V_18 = V_1 ;
return 0 ;
}
static int T_1 F_17 ( struct V_13 * V_14 )
{
extern const struct V_31 V_32 [] ;
const struct V_31 * V_33 ;
for ( V_33 = V_32 ; V_33 < & V_34 ; V_33 ++ ) {
T_3 V_35 = V_33 -> V_36 ;
const char * V_37 = V_33 -> V_38 ;
if ( ! F_12 ( V_14 -> V_16 , V_37 ) )
continue;
if ( V_35 ( V_14 ) == 0 ) {
F_16 ( L_16 ,
V_14 -> V_17 , V_37 ) ;
return 0 ;
}
}
return - V_39 ;
}
static int T_1 F_18 ( const void * V_40 , const void * V_41 )
{
const struct V_13 * V_42 = V_40 , * V_43 = V_41 ;
if ( V_42 -> V_7 < V_43 -> V_7 )
return - 1 ;
if ( V_42 -> V_7 > V_43 -> V_7 )
return 1 ;
return 0 ;
}
static void T_1 F_19 ( void )
{
int V_33 ;
if ( V_15 < 2 )
return;
F_20 ( V_13 , V_15 , sizeof( V_13 [ 0 ] ) ,
F_18 , NULL ) ;
for ( V_33 = 0 ; V_33 < V_15 - 1 ; V_33 ++ ) {
struct V_13 * V_44 , * V_45 ;
V_44 = & V_13 [ V_33 ] ;
V_45 = & V_13 [ V_33 + 1 ] ;
if ( ! ( V_44 -> V_7 && V_45 -> V_7 ) )
continue;
if ( V_44 -> V_7 + V_44 -> V_1 > V_45 -> V_7 ) {
T_2 V_46 , V_47 ;
V_46 = V_44 -> V_7 + V_44 -> V_1 ;
V_47 = V_45 -> V_7 + V_45 -> V_1 ;
F_5 ( L_17 ,
V_44 -> V_17 , & V_44 -> V_7 , & V_46 ,
V_45 -> V_17 , & V_45 -> V_7 , & V_47 ) ;
}
}
}
void T_1 F_21 ( void )
{
int V_33 ;
F_19 () ;
for ( V_33 = 0 ; V_33 < V_15 ; V_33 ++ ) {
struct V_13 * V_14 = & V_13 [ V_33 ] ;
unsigned long V_11 = V_14 -> V_16 ;
int V_23 ;
const V_22 * V_24 ;
int V_48 = 0 ;
V_24 = F_9 ( V_11 , L_18 , & V_23 ) ;
if ( ! V_24 )
V_24 = F_9 ( V_11 , L_19 , & V_23 ) ;
if ( V_24 )
V_14 -> V_49 = F_22 ( V_24 , V_23 / 4 ) ;
if ( V_14 -> V_1 == 0 )
V_48 = F_8 ( V_11 , V_14 -> V_17 ,
& V_14 -> V_7 , & V_14 -> V_1 ) ;
if ( V_48 == 0 )
F_17 ( V_14 ) ;
}
}
static inline struct V_13 * F_23 ( struct V_50 * V_11 )
{
unsigned int V_33 ;
if ( ! V_11 -> V_49 )
return NULL ;
for ( V_33 = 0 ; V_33 < V_15 ; V_33 ++ )
if ( V_13 [ V_33 ] . V_49 == V_11 -> V_49 )
return & V_13 [ V_33 ] ;
return NULL ;
}
int F_24 ( struct V_51 * V_52 ,
struct V_50 * V_53 , int V_54 )
{
struct V_55 * V_56 ;
struct V_50 * V_57 ;
struct V_13 * V_14 ;
int V_25 ;
if ( ! V_53 || ! V_52 )
return - V_26 ;
V_57 = F_25 ( V_53 , L_20 , V_54 ) ;
if ( ! V_57 )
return - V_58 ;
V_14 = F_23 ( V_57 ) ;
F_26 ( V_57 ) ;
if ( ! V_14 || ! V_14 -> V_59 || ! V_14 -> V_59 -> V_60 )
return - V_26 ;
V_56 = F_27 ( sizeof( struct V_55 ) , V_61 ) ;
if ( ! V_56 )
return - V_9 ;
V_25 = V_14 -> V_59 -> V_60 ( V_14 , V_52 ) ;
if ( V_25 == 0 ) {
V_56 -> V_52 = V_52 ;
V_56 -> V_14 = V_14 ;
F_28 ( & V_62 ) ;
F_29 ( & V_56 -> V_63 , & V_64 ) ;
F_30 ( & V_62 ) ;
F_31 ( V_52 , V_53 ) ;
F_32 ( V_52 , L_21 , V_14 -> V_17 ) ;
} else {
F_33 ( V_56 ) ;
}
return V_25 ;
}
void F_34 ( struct V_51 * V_52 )
{
struct V_55 * V_56 ;
struct V_13 * V_14 = NULL ;
F_28 ( & V_62 ) ;
F_35 (rd, &of_rmem_assigned_device_list, list) {
if ( V_56 -> V_52 == V_52 ) {
V_14 = V_56 -> V_14 ;
F_36 ( & V_56 -> V_63 ) ;
F_33 ( V_56 ) ;
break;
}
}
F_30 ( & V_62 ) ;
if ( ! V_14 || ! V_14 -> V_59 || ! V_14 -> V_59 -> V_65 )
return;
V_14 -> V_59 -> V_65 ( V_14 , V_52 ) ;
}
