struct V_1 * F_1 ( unsigned int V_2 )
{
struct V_1 * V_3 ;
F_2 (info, &registered_dmac_list, list) {
if ( ( V_2 < V_3 -> V_4 ) ||
( V_2 >= V_3 -> V_4 + V_3 -> V_5 ) )
continue;
return V_3 ;
}
return NULL ;
}
struct V_1 * F_3 ( const char * V_6 )
{
struct V_1 * V_3 ;
F_2 (info, &registered_dmac_list, list) {
if ( V_6 && ( strcmp ( V_6 , V_3 -> V_7 ) != 0 ) )
continue;
else
return V_3 ;
}
return NULL ;
}
static unsigned int F_4 ( void )
{
struct V_1 * V_3 ;
unsigned int V_8 = 0 ;
if ( F_5 ( F_6 ( & V_9 ) ) )
return V_8 ;
F_2 (info, &registered_dmac_list, list)
V_8 += V_3 -> V_5 ;
return V_8 ;
}
struct V_10 * F_7 ( unsigned int V_2 )
{
struct V_1 * V_3 = F_1 ( V_2 ) ;
struct V_10 * V_11 ;
int V_12 ;
if ( F_5 ( ! V_3 ) )
return F_8 ( - V_13 ) ;
for ( V_12 = 0 ; V_12 < V_3 -> V_5 ; V_12 ++ ) {
V_11 = & V_3 -> V_14 [ V_12 ] ;
if ( V_11 -> V_15 == V_2 )
return V_11 ;
}
return NULL ;
}
int F_9 ( unsigned int V_2 )
{
struct V_1 * V_3 = F_1 ( V_2 ) ;
struct V_10 * V_11 = F_7 ( V_2 ) ;
if ( V_3 -> V_16 -> V_17 )
return V_3 -> V_16 -> V_17 ( V_11 ) ;
return 0 ;
}
static int F_10 ( const char * * V_18 , const char * V_19 )
{
const char * * V_20 ;
for ( V_20 = V_18 ; * V_20 ; V_20 ++ )
if ( strcmp ( * V_20 , V_19 ) == 0 )
return 1 ;
return 0 ;
}
int F_11 ( const char * * V_21 , const char * * V_22 , const char * V_23 )
{
unsigned int V_24 = 0 ;
struct V_1 * V_3 ;
const char * * V_20 ;
int V_12 ;
F_12 ( ! V_21 || ! V_22 ) ;
F_2 (info, &registered_dmac_list, list)
if ( strcmp ( * V_21 , V_3 -> V_7 ) == 0 ) {
V_24 = 1 ;
break;
}
if ( ! V_24 )
return - V_25 ;
for ( V_12 = 0 ; V_12 < V_3 -> V_5 ; V_12 ++ ) {
struct V_10 * V_11 = & V_3 -> V_14 [ V_12 ] ;
if ( F_5 ( ! V_11 -> V_22 ) )
continue;
for ( V_20 = V_22 ; * V_20 ; V_20 ++ ) {
if ( ! F_10 ( V_11 -> V_22 , * V_20 ) )
break;
if ( F_13 ( V_11 -> V_2 , V_23 ) == 0 )
return V_11 -> V_2 ;
}
}
return - V_13 ;
}
int F_14 ( const char * V_23 )
{
struct V_10 * V_11 = { 0 } ;
struct V_1 * V_3 = F_1 ( 0 ) ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_3 -> V_5 ; V_12 ++ ) {
V_11 = & V_3 -> V_14 [ V_12 ] ;
if ( F_5 ( ! V_11 ) )
return - V_25 ;
if ( F_15 ( & V_11 -> V_26 ) == 0 )
break;
}
if ( V_3 -> V_16 -> V_27 ) {
int V_28 = V_3 -> V_16 -> V_27 ( V_11 ) ;
if ( V_28 )
return V_28 ;
F_16 ( & V_11 -> V_26 , 1 ) ;
return V_11 -> V_2 ;
}
return - V_29 ;
}
int F_13 ( unsigned int V_2 , const char * V_23 )
{
struct V_10 * V_11 = { 0 } ;
struct V_1 * V_3 = F_1 ( V_2 ) ;
int V_28 ;
V_11 = F_7 ( V_2 ) ;
if ( F_17 ( & V_11 -> V_26 , 1 ) )
return - V_30 ;
F_18 ( V_11 -> V_23 , V_23 , sizeof( V_11 -> V_23 ) ) ;
if ( V_3 -> V_16 -> V_27 ) {
V_28 = V_3 -> V_16 -> V_27 ( V_11 ) ;
if ( V_28 )
F_16 ( & V_11 -> V_26 , 0 ) ;
return V_28 ;
}
return 0 ;
}
void F_19 ( unsigned int V_2 )
{
struct V_1 * V_3 = F_1 ( V_2 ) ;
struct V_10 * V_11 = F_7 ( V_2 ) ;
if ( V_3 -> V_16 -> free )
V_3 -> V_16 -> free ( V_11 ) ;
F_16 ( & V_11 -> V_26 , 0 ) ;
}
void F_20 ( unsigned int V_2 )
{
struct V_1 * V_3 = F_1 ( V_2 ) ;
struct V_10 * V_11 = F_7 ( V_2 ) ;
if ( V_11 -> V_31 & V_32 ) {
F_21 ( V_11 -> V_33 ,
( V_3 -> V_16 -> V_17 ( V_11 ) == 0 ) ) ;
return;
}
while ( V_3 -> V_16 -> V_17 ( V_11 ) )
F_22 () ;
}
int F_23 ( const char * V_21 , struct V_34 * V_22 )
{
struct V_1 * V_3 ;
unsigned int V_24 = 0 ;
int V_12 ;
F_2 (info, &registered_dmac_list, list)
if ( strcmp ( V_21 , V_3 -> V_7 ) == 0 ) {
V_24 = 1 ;
break;
}
if ( F_5 ( ! V_24 ) )
return - V_25 ;
for ( V_12 = 0 ; V_12 < V_3 -> V_5 ; V_12 ++ , V_22 ++ ) {
struct V_10 * V_11 ;
if ( ( V_3 -> V_35 + V_12 ) != V_22 -> V_36 )
return - V_13 ;
V_11 = & V_3 -> V_14 [ V_12 ] ;
V_11 -> V_22 = V_22 -> V_37 ;
}
return 0 ;
}
void F_24 ( unsigned int V_2 , unsigned long V_31 )
{
struct V_1 * V_3 = F_1 ( V_2 ) ;
struct V_10 * V_11 = F_7 ( V_2 ) ;
if ( V_3 -> V_16 -> V_38 )
V_3 -> V_16 -> V_38 ( V_11 , V_31 ) ;
}
int F_25 ( unsigned int V_2 , unsigned long V_39 ,
unsigned long V_40 , T_1 V_41 , unsigned int V_42 )
{
struct V_1 * V_3 = F_1 ( V_2 ) ;
struct V_10 * V_11 = F_7 ( V_2 ) ;
V_11 -> V_43 = V_39 ;
V_11 -> V_44 = V_40 ;
V_11 -> V_45 = V_41 ;
V_11 -> V_42 = V_42 ;
return V_3 -> V_16 -> V_46 ( V_11 ) ;
}
int F_26 ( unsigned int V_2 , unsigned long V_47 , void * V_48 )
{
struct V_1 * V_3 = F_1 ( V_2 ) ;
struct V_10 * V_11 = F_7 ( V_2 ) ;
if ( V_3 -> V_16 -> V_49 )
return V_3 -> V_16 -> V_49 ( V_11 , V_47 , V_48 ) ;
return - V_29 ;
}
static int F_27 ( struct V_50 * V_51 , void * V_52 )
{
struct V_1 * V_3 = V_52 ;
if ( F_6 ( & V_9 ) )
return 0 ;
F_2 (info, &registered_dmac_list, list) {
int V_12 ;
for ( V_12 = 0 ; V_12 < V_3 -> V_5 ; V_12 ++ ) {
struct V_10 * V_11 = V_3 -> V_14 + V_12 ;
if ( ! ( V_11 -> V_31 & V_53 ) )
continue;
F_28 ( V_51 , L_1 , V_12 ,
V_3 -> V_7 , V_11 -> V_23 ) ;
}
}
return 0 ;
}
static int F_29 ( struct V_54 * V_54 , struct V_55 * V_55 )
{
return F_30 ( V_55 , F_27 , NULL ) ;
}
int F_31 ( struct V_1 * V_3 )
{
unsigned int V_56 , V_12 ;
F_32 ( & V_3 -> V_57 ) ;
F_33 ( V_58 L_2 ,
V_3 -> V_7 , V_3 -> V_5 , V_3 -> V_5 > 1 ? L_3 : L_4 ) ;
F_12 ( ( V_3 -> V_31 & V_59 ) && ! V_3 -> V_14 ) ;
V_3 -> V_60 = F_34 ( V_3 -> V_7 , - 1 ,
NULL , 0 ) ;
if ( F_35 ( V_3 -> V_60 ) )
return F_36 ( V_3 -> V_60 ) ;
if ( ! ( V_3 -> V_31 & V_59 ) ) {
unsigned int V_41 ;
V_41 = sizeof( struct V_10 ) * V_3 -> V_5 ;
V_3 -> V_14 = F_37 ( V_41 , V_61 ) ;
if ( ! V_3 -> V_14 )
return - V_62 ;
}
V_56 = F_4 () ;
V_3 -> V_4 = V_56 ;
for ( V_12 = 0 ; V_12 < V_3 -> V_5 ; V_12 ++ ) {
struct V_10 * V_2 = & V_3 -> V_14 [ V_12 ] ;
F_16 ( & V_2 -> V_26 , 0 ) ;
V_2 -> V_2 = V_3 -> V_35 + V_12 ;
V_2 -> V_15 = V_3 -> V_35 + V_12 + V_56 ;
memcpy ( V_2 -> V_23 , L_5 , 7 ) ;
if ( V_3 -> V_31 & V_63 )
V_2 -> V_31 |= V_32 ;
F_38 ( & V_2 -> V_33 ) ;
F_39 ( V_2 , V_3 ) ;
}
F_40 ( & V_3 -> V_57 , & V_9 ) ;
return 0 ;
}
void F_41 ( struct V_1 * V_3 )
{
unsigned int V_12 ;
for ( V_12 = 0 ; V_12 < V_3 -> V_5 ; V_12 ++ )
F_42 ( V_3 -> V_14 + V_12 , V_3 ) ;
if ( ! ( V_3 -> V_31 & V_59 ) )
F_43 ( V_3 -> V_14 ) ;
F_44 ( & V_3 -> V_57 ) ;
F_45 ( V_3 -> V_60 ) ;
}
static int T_2 F_46 ( void )
{
F_33 ( V_64 L_6 ) ;
return F_47 ( L_7 , 0 , NULL , & V_65 ) ? 0 : - V_62 ;
}
