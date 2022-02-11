static void F_1 ( struct V_1 * V_2 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_2 -> V_4 ; V_3 ++ ) {
T_1 V_5 = F_2 ( V_2 -> V_6 [ V_3 ] ) ;
if ( ! V_5 )
continue;
V_5 -- ;
V_2 -> V_6 [ V_3 ] &= ~ ( V_7 << V_8 ) ;
V_2 -> V_6 [ V_3 ] |= ( V_5 << V_8 ) ;
}
V_2 -> V_9 = 0 ;
V_2 -> V_10 ++ ;
}
static void F_3 ( struct V_11 * V_12 , unsigned long V_13 )
{
unsigned long V_14 ;
V_14 = V_13 * V_15 + V_16 ;
F_4 ( V_12 , F_5 ( V_14 ) ) ;
}
static void F_6 ( unsigned long V_17 )
{
struct V_1 * V_2 = (struct V_1 * ) V_17 ;
F_1 ( V_2 ) ;
F_3 ( & V_18 , V_19 ) ;
}
static int F_7 ( struct V_1 * V_2 , T_2 V_20 , unsigned int * V_21 )
{
T_2 V_22 ;
int V_23 = 0 , V_24 = V_2 -> V_4 ;
while ( V_23 < V_24 ) {
int V_25 = ( V_24 + V_23 ) >> 1 ;
V_22 = F_8 ( V_2 -> V_6 [ V_25 ] ) ;
if ( V_22 < V_20 )
V_23 = V_25 + 1 ;
else if ( V_22 > V_20 )
V_24 = V_25 ;
else {
V_23 = V_25 ;
break;
}
}
if ( V_21 )
* V_21 = V_23 ;
V_22 = F_8 ( V_2 -> V_6 [ V_23 ] ) ;
if ( V_22 == V_20 )
return V_23 ;
return - V_26 ;
}
static int F_9 ( struct V_1 * V_2 , T_2 V_20 , unsigned int * V_21 )
{
F_10 ( ! V_21 ) ;
if ( ! V_2 -> V_4 ) {
* V_21 = 0 ;
return - V_26 ;
}
return F_7 ( V_2 , V_20 , V_21 ) ;
}
static void F_11 ( struct V_1 * V_2 , int V_27 )
{
if ( V_2 -> V_4 - ( V_27 + 1 ) )
memmove ( ( void * ) & V_2 -> V_6 [ V_27 ] ,
( void * ) & V_2 -> V_6 [ V_27 + 1 ] ,
( V_2 -> V_4 - ( V_27 + 1 ) ) * sizeof( T_2 ) ) ;
V_2 -> V_4 -- ;
}
static T_2 F_12 ( struct V_1 * V_2 )
{
unsigned int V_23 = V_28 ;
int V_3 , V_29 = 0 ;
for ( V_3 = 0 ; V_3 < V_2 -> V_4 ; V_3 ++ ) {
unsigned int V_30 = F_13 ( V_2 -> V_6 [ V_3 ] ) ;
if ( V_23 > V_30 ) {
V_23 = V_30 ;
V_29 = V_3 ;
}
}
F_11 ( V_2 , V_29 ) ;
return F_8 ( V_2 -> V_6 [ V_29 ] ) ;
}
static T_2 T_3 F_14 ( void )
{
struct V_1 * V_2 = & V_31 ;
T_2 V_20 ;
if ( ! V_2 -> V_4 )
return 0 ;
F_15 ( & V_32 ) ;
V_20 = F_12 ( V_2 ) ;
F_16 ( & V_32 ) ;
return V_20 ;
}
int F_17 ( T_2 V_20 )
{
struct V_1 * V_2 = & V_31 ;
unsigned int V_21 ;
int V_33 , V_34 = 0 ;
if ( ! V_31 . V_6 || V_31 . V_35 )
return - V_36 ;
V_2 -> V_37 ++ ;
F_15 ( & V_32 ) ;
if ( V_2 -> V_4 == V_38 )
F_10 ( ! F_12 ( V_2 ) ) ;
V_34 = F_9 ( V_2 , V_20 , & V_21 ) ;
if ( V_34 < 0 ) {
memmove ( ( void * ) & V_2 -> V_6 [ V_21 + 1 ] ,
( void * ) & V_2 -> V_6 [ V_21 ] ,
( V_2 -> V_4 - V_21 ) * sizeof( T_2 ) ) ;
V_2 -> V_6 [ V_21 ] = ( V_20 << V_39 ) |
( V_7 << V_8 ) | 1 ;
V_2 -> V_4 ++ ;
V_34 = 0 ;
goto V_5;
}
V_33 = F_18 ( V_2 -> V_6 [ V_21 ] ) ;
if ( V_33 < V_40 ) {
V_2 -> V_6 [ V_21 ] |= ( V_7 << V_8 ) ;
V_2 -> V_6 [ V_21 ] ++ ;
V_34 = 0 ;
} else {
T_2 V_20 = V_2 -> V_6 [ V_21 ] >> V_39 ;
if ( ! F_19 ( V_20 ) ) {
F_20 ( L_1 , V_20 ) ;
} else {
F_21 ( L_2 , V_20 ) ;
F_22 ( V_20 , 0 , V_41 ) ;
V_2 -> V_42 ++ ;
}
F_11 ( V_2 , V_21 ) ;
V_34 = 1 ;
goto V_43;
}
V_5:
V_2 -> V_9 ++ ;
if ( V_2 -> V_9 >= V_44 )
F_1 ( V_2 ) ;
V_43:
F_16 ( & V_32 ) ;
return V_34 ;
}
static int F_23 ( void * V_17 , T_2 * V_45 )
{
* V_45 = * ( T_2 * ) V_17 ;
return 0 ;
}
static int F_24 ( void * V_17 , T_2 V_45 )
{
* ( T_2 * ) V_17 = V_45 ;
return F_17 ( V_45 ) ;
}
static int F_25 ( void * V_17 , T_2 V_45 )
{
* ( T_2 * ) V_17 = V_45 ;
if ( V_45 < V_46 )
return - V_47 ;
if ( V_45 > V_48 )
return - V_47 ;
V_19 = V_45 ;
F_3 ( & V_18 , V_19 ) ;
return 0 ;
}
static int F_26 ( void * V_17 , T_2 V_45 )
{
* ( T_2 * ) V_17 = V_45 ;
if ( V_45 > V_49 )
V_45 = V_49 ;
V_40 = V_45 ;
return 0 ;
}
static int F_27 ( struct V_50 * V_51 , void * V_52 )
{
struct V_1 * V_2 = & V_31 ;
T_2 V_53 = 0 ;
int V_3 ;
F_15 ( & V_32 ) ;
F_28 ( V_51 , L_3 , V_2 -> V_4 ) ;
for ( V_3 = 0 ; V_3 < V_2 -> V_4 ; V_3 ++ ) {
T_2 V_30 = F_8 ( V_2 -> V_6 [ V_3 ] ) ;
F_28 ( V_51 , L_4 , V_3 , V_30 , F_13 ( V_2 -> V_6 [ V_3 ] ) ) ;
F_10 ( V_53 > V_30 ) ;
V_53 = V_30 ;
}
F_28 ( V_51 , L_5 ) ;
F_28 ( V_51 , L_6 ,
V_2 -> V_37 , V_2 -> V_42 ) ;
F_28 ( V_51 , L_7 , V_2 -> V_54 ) ;
F_28 ( V_51 , L_8 , V_19 ) ;
F_28 ( V_51 , L_9 , V_2 -> V_10 ) ;
F_28 ( V_51 , L_10 , V_40 ) ;
F_16 ( & V_32 ) ;
return 0 ;
}
static int F_29 ( struct V_55 * V_55 , struct V_56 * V_57 )
{
return F_30 ( V_57 , F_27 , NULL ) ;
}
static int T_4 F_31 ( void )
{
struct V_58 * V_59 , * V_20 , * V_5 , * V_33 , * V_6 ;
V_59 = F_32 ( L_11 , V_60 ) ;
if ( ! V_59 ) {
F_20 ( L_12 ) ;
return - 1 ;
}
V_20 = F_33 ( L_13 , V_61 | V_62 , V_59 , & V_63 , & V_64 ) ;
if ( ! V_20 ) {
F_20 ( L_14 ) ;
goto V_65;
}
V_6 = F_33 ( L_15 , V_61 , V_59 , NULL , & V_66 ) ;
if ( ! V_6 ) {
F_20 ( L_16 ) ;
goto V_65;
}
V_5 = F_33 ( L_17 , V_61 | V_62 , V_59 ,
& V_19 , & V_67 ) ;
if ( ! V_5 ) {
F_20 ( L_18 ) ;
goto V_65;
}
V_33 = F_33 ( L_19 , V_61 | V_62 , V_59 ,
& V_40 , & V_68 ) ;
if ( ! V_5 ) {
F_20 ( L_20 ) ;
goto V_65;
}
return 0 ;
V_65:
F_34 ( V_59 ) ;
return 1 ;
}
void T_4 F_35 ( void )
{
if ( V_31 . V_35 )
return;
V_31 . V_6 = ( void * ) F_36 ( V_69 ) ;
if ( ! V_31 . V_6 ) {
F_21 ( L_21 ) ;
return;
}
if ( F_31 () )
return;
F_37 ( & V_18 , F_6 , ( unsigned long ) & V_31 ) ;
F_3 ( & V_18 , V_70 ) ;
F_38 ( L_22 ) ;
}
int T_4 F_39 ( char * V_71 )
{
if ( ! V_71 )
return 0 ;
if ( * V_71 == '=' )
V_71 ++ ;
if ( ! strncmp ( V_71 , L_23 , 7 ) )
V_31 . V_35 = 1 ;
else
return 0 ;
return 1 ;
}
