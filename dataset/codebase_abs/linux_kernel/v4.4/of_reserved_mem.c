int T_1 __weak F_1 ( T_2 V_1 ,
T_2 V_2 , T_2 V_3 , T_2 V_4 , bool V_5 ,
T_2 * V_6 )
{
T_2 V_7 = F_2 ( V_1 , V_2 , V_4 ) ;
if ( ! V_7 )
return - V_8 ;
if ( V_7 < V_3 ) {
F_3 ( V_7 , V_1 ) ;
return - V_8 ;
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
return - V_9 ;
}
void T_1 F_6 ( unsigned long V_10 , const char * V_11 ,
T_2 V_7 , T_2 V_1 )
{
struct V_12 * V_13 = & V_12 [ V_14 ] ;
if ( V_14 == F_7 ( V_12 ) ) {
F_5 ( L_4 ) ;
return;
}
V_13 -> V_15 = V_10 ;
V_13 -> V_16 = V_11 ;
V_13 -> V_7 = V_7 ;
V_13 -> V_1 = V_1 ;
V_14 ++ ;
return;
}
static int T_1 F_8 ( unsigned long V_10 ,
const char * V_11 , T_2 * V_6 , T_2 * V_17 )
{
int V_18 = ( V_19 + V_20 ) * sizeof( V_21 ) ;
T_2 V_3 = 0 , V_4 = 0 ;
T_2 V_7 = 0 , V_2 = 0 , V_1 ;
int V_22 ;
const V_21 * V_23 ;
int V_5 ;
int V_24 ;
V_23 = F_9 ( V_10 , L_5 , & V_22 ) ;
if ( ! V_23 )
return - V_25 ;
if ( V_22 != V_20 * sizeof( V_21 ) ) {
F_5 ( L_6 ,
V_11 ) ;
return - V_25 ;
}
V_1 = F_10 ( V_20 , & V_23 ) ;
V_5 = F_9 ( V_10 , L_7 , NULL ) != NULL ;
V_23 = F_9 ( V_10 , L_8 , & V_22 ) ;
if ( V_23 ) {
if ( V_22 != V_19 * sizeof( V_21 ) ) {
F_5 ( L_9 ,
V_11 ) ;
return - V_25 ;
}
V_2 = F_10 ( V_19 , & V_23 ) ;
}
if ( F_11 ( V_26 ) && F_12 ( V_10 , L_10 ) )
V_2 = F_13 ( V_2 , ( T_2 ) V_27 << F_13 ( V_28 - 1 , V_29 ) ) ;
V_23 = F_9 ( V_10 , L_11 , & V_22 ) ;
if ( V_23 ) {
if ( V_22 % V_18 != 0 ) {
F_5 ( L_12 ,
V_11 ) ;
return - V_25 ;
}
V_7 = 0 ;
while ( V_22 > 0 ) {
V_3 = F_10 ( V_19 , & V_23 ) ;
V_4 = V_3 + F_10 ( V_20 ,
& V_23 ) ;
V_24 = F_1 ( V_1 ,
V_2 , V_3 , V_4 , V_5 , & V_7 ) ;
if ( V_24 == 0 ) {
F_14 ( L_13 ,
V_11 , & V_7 ,
( unsigned long ) V_1 / V_30 ) ;
break;
}
V_22 -= V_18 ;
}
} else {
V_24 = F_1 ( V_1 , V_2 ,
0 , 0 , V_5 , & V_7 ) ;
if ( V_24 == 0 )
F_14 ( L_13 ,
V_11 , & V_7 , ( unsigned long ) V_1 / V_30 ) ;
}
if ( V_7 == 0 ) {
F_15 ( L_14 ,
V_11 ) ;
return - V_8 ;
}
* V_6 = V_7 ;
* V_17 = V_1 ;
return 0 ;
}
static int T_1 F_16 ( struct V_12 * V_13 )
{
extern const struct V_31 V_32 [] ;
const struct V_31 * V_33 ;
for ( V_33 = V_32 ; V_33 < & V_34 ; V_33 ++ ) {
T_3 V_35 = V_33 -> V_36 ;
const char * V_37 = V_33 -> V_38 ;
if ( ! F_12 ( V_13 -> V_15 , V_37 ) )
continue;
if ( V_35 ( V_13 ) == 0 ) {
F_15 ( L_15 ,
V_13 -> V_16 , V_37 ) ;
return 0 ;
}
}
return - V_39 ;
}
static int T_1 F_17 ( const void * V_40 , const void * V_41 )
{
const struct V_12 * V_42 = V_40 , * V_43 = V_41 ;
if ( V_42 -> V_7 < V_43 -> V_7 )
return - 1 ;
if ( V_42 -> V_7 > V_43 -> V_7 )
return 1 ;
return 0 ;
}
static void T_1 F_18 ( void )
{
int V_33 ;
if ( V_14 < 2 )
return;
F_19 ( V_12 , V_14 , sizeof( V_12 [ 0 ] ) ,
F_17 , NULL ) ;
for ( V_33 = 0 ; V_33 < V_14 - 1 ; V_33 ++ ) {
struct V_12 * V_44 , * V_45 ;
V_44 = & V_12 [ V_33 ] ;
V_45 = & V_12 [ V_33 + 1 ] ;
if ( ! ( V_44 -> V_7 && V_45 -> V_7 ) )
continue;
if ( V_44 -> V_7 + V_44 -> V_1 > V_45 -> V_7 ) {
T_2 V_46 , V_47 ;
V_46 = V_44 -> V_7 + V_44 -> V_1 ;
V_47 = V_45 -> V_7 + V_45 -> V_1 ;
F_5 ( L_16 ,
V_44 -> V_16 , & V_44 -> V_7 , & V_46 ,
V_45 -> V_16 , & V_45 -> V_7 , & V_47 ) ;
}
}
}
void T_1 F_20 ( void )
{
int V_33 ;
F_18 () ;
for ( V_33 = 0 ; V_33 < V_14 ; V_33 ++ ) {
struct V_12 * V_13 = & V_12 [ V_33 ] ;
unsigned long V_10 = V_13 -> V_15 ;
int V_22 ;
const V_21 * V_23 ;
int V_48 = 0 ;
V_23 = F_9 ( V_10 , L_17 , & V_22 ) ;
if ( ! V_23 )
V_23 = F_9 ( V_10 , L_18 , & V_22 ) ;
if ( V_23 )
V_13 -> V_49 = F_21 ( V_23 , V_22 / 4 ) ;
if ( V_13 -> V_1 == 0 )
V_48 = F_8 ( V_10 , V_13 -> V_16 ,
& V_13 -> V_7 , & V_13 -> V_1 ) ;
if ( V_48 == 0 )
F_16 ( V_13 ) ;
}
}
static inline struct V_12 * F_22 ( struct V_50 * V_10 )
{
unsigned int V_33 ;
if ( ! V_10 -> V_49 )
return NULL ;
for ( V_33 = 0 ; V_33 < V_14 ; V_33 ++ )
if ( V_12 [ V_33 ] . V_49 == V_10 -> V_49 )
return & V_12 [ V_33 ] ;
return NULL ;
}
int F_23 ( struct V_51 * V_52 )
{
struct V_12 * V_13 ;
struct V_50 * V_53 ;
int V_24 ;
V_53 = F_24 ( V_52 -> V_54 , L_19 , 0 ) ;
if ( ! V_53 )
return - V_55 ;
V_13 = F_22 ( V_53 ) ;
F_25 ( V_53 ) ;
if ( ! V_13 || ! V_13 -> V_56 || ! V_13 -> V_56 -> V_57 )
return - V_25 ;
V_24 = V_13 -> V_56 -> V_57 ( V_13 , V_52 ) ;
if ( V_24 == 0 )
F_26 ( V_52 , L_20 , V_13 -> V_16 ) ;
return V_24 ;
}
void F_27 ( struct V_51 * V_52 )
{
struct V_12 * V_13 ;
struct V_50 * V_53 ;
V_53 = F_24 ( V_52 -> V_54 , L_19 , 0 ) ;
if ( ! V_53 )
return;
V_13 = F_22 ( V_53 ) ;
F_25 ( V_53 ) ;
if ( ! V_13 || ! V_13 -> V_56 || ! V_13 -> V_56 -> V_58 )
return;
V_13 -> V_56 -> V_58 ( V_13 , V_52 ) ;
}
