static void F_1 ( struct V_1 * V_2 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_2 -> V_4 . V_5 ; V_3 ++ )
F_2 ( V_2 -> V_6 [ V_3 ] ) ;
}
static int F_3 ( struct V_1 * V_2 )
{
void T_1 * V_7 ;
int V_3 ;
for ( V_3 = 0 ; V_3 < V_2 -> V_4 . V_5 ; V_3 ++ ) {
V_7 = F_4 ( V_2 -> V_8 , 8 ,
V_9 | V_10 ) ;
if ( ! V_7 ) {
F_1 ( V_2 ) ;
return - V_11 ;
}
V_2 -> V_6 [ V_3 ] = V_7 ;
}
return 0 ;
}
static struct V_12 * F_5 ( union V_13 * V_14 )
{
bool V_15 = V_14 -> V_16 == V_17 ;
struct V_1 * V_2 ;
T_2 V_18 ;
T_3 V_8 ;
if ( V_14 -> V_5 == 0 || V_14 -> V_19 != 4 ||
V_14 -> V_20 == 0 || V_14 -> V_21 )
return F_6 ( - V_22 ) ;
if ( V_14 -> V_20 >= 1 << ( V_23 - 1 ) )
return F_6 ( - V_24 ) ;
V_8 = F_7 ( V_14 -> V_20 , 8 ) ;
V_18 = sizeof( * V_2 ) ;
if ( V_15 )
V_18 += ( T_2 ) V_14 -> V_5 * sizeof( void * ) ;
else
V_18 += ( T_2 ) V_14 -> V_5 * V_8 ;
if ( V_18 >= V_25 - V_26 )
return F_6 ( - V_11 ) ;
V_2 = F_8 ( V_18 , V_9 | V_10 ) ;
if ( ! V_2 ) {
V_2 = F_9 ( V_18 ) ;
if ( ! V_2 )
return F_6 ( - V_11 ) ;
}
V_2 -> V_4 . V_16 = V_14 -> V_16 ;
V_2 -> V_4 . V_19 = V_14 -> V_19 ;
V_2 -> V_4 . V_20 = V_14 -> V_20 ;
V_2 -> V_4 . V_5 = V_14 -> V_5 ;
V_2 -> V_8 = V_8 ;
if ( ! V_15 )
goto V_27;
V_18 += ( T_2 ) V_14 -> V_5 * V_8 * F_10 () ;
if ( V_18 >= V_25 - V_26 ||
V_8 > V_28 || F_3 ( V_2 ) ) {
F_11 ( V_2 ) ;
return F_6 ( - V_11 ) ;
}
V_27:
V_2 -> V_4 . V_29 = F_7 ( V_18 , V_26 ) >> V_30 ;
return & V_2 -> V_4 ;
}
static void * F_12 ( struct V_12 * V_4 , void * V_31 )
{
struct V_1 * V_2 = F_13 ( V_4 , struct V_1 , V_4 ) ;
T_3 V_32 = * ( T_3 * ) V_31 ;
if ( F_14 ( V_32 >= V_2 -> V_4 . V_5 ) )
return NULL ;
return V_2 -> V_33 + V_2 -> V_8 * V_32 ;
}
static void * F_15 ( struct V_12 * V_4 , void * V_31 )
{
struct V_1 * V_2 = F_13 ( V_4 , struct V_1 , V_4 ) ;
T_3 V_32 = * ( T_3 * ) V_31 ;
if ( F_14 ( V_32 >= V_2 -> V_4 . V_5 ) )
return NULL ;
return F_16 ( V_2 -> V_6 [ V_32 ] ) ;
}
int F_17 ( struct V_12 * V_4 , void * V_31 , void * V_33 )
{
struct V_1 * V_2 = F_13 ( V_4 , struct V_1 , V_4 ) ;
T_3 V_32 = * ( T_3 * ) V_31 ;
void T_1 * V_34 ;
int V_35 , V_36 = 0 ;
T_3 V_37 ;
if ( F_14 ( V_32 >= V_2 -> V_4 . V_5 ) )
return - V_38 ;
V_37 = F_7 ( V_4 -> V_20 , 8 ) ;
F_18 () ;
V_34 = V_2 -> V_6 [ V_32 ] ;
F_19 (cpu) {
F_20 ( V_33 + V_36 , F_21 ( V_34 , V_35 ) , V_37 ) ;
V_36 += V_37 ;
}
F_22 () ;
return 0 ;
}
static int F_23 ( struct V_12 * V_4 , void * V_31 , void * V_39 )
{
struct V_1 * V_2 = F_13 ( V_4 , struct V_1 , V_4 ) ;
T_3 V_32 = * ( T_3 * ) V_31 ;
T_3 * V_40 = ( T_3 * ) V_39 ;
if ( V_32 >= V_2 -> V_4 . V_5 ) {
* V_40 = 0 ;
return 0 ;
}
if ( V_32 == V_2 -> V_4 . V_5 - 1 )
return - V_38 ;
* V_40 = V_32 + 1 ;
return 0 ;
}
static int F_24 ( struct V_12 * V_4 , void * V_31 , void * V_33 ,
T_2 V_21 )
{
struct V_1 * V_2 = F_13 ( V_4 , struct V_1 , V_4 ) ;
T_3 V_32 = * ( T_3 * ) V_31 ;
if ( F_14 ( V_21 > V_41 ) )
return - V_22 ;
if ( F_14 ( V_32 >= V_2 -> V_4 . V_5 ) )
return - V_24 ;
if ( F_14 ( V_21 == V_42 ) )
return - V_43 ;
if ( V_2 -> V_4 . V_16 == V_17 )
memcpy ( F_16 ( V_2 -> V_6 [ V_32 ] ) ,
V_33 , V_4 -> V_20 ) ;
else
memcpy ( V_2 -> V_33 + V_2 -> V_8 * V_32 ,
V_33 , V_4 -> V_20 ) ;
return 0 ;
}
int F_25 ( struct V_12 * V_4 , void * V_31 , void * V_33 ,
T_2 V_21 )
{
struct V_1 * V_2 = F_13 ( V_4 , struct V_1 , V_4 ) ;
T_3 V_32 = * ( T_3 * ) V_31 ;
void T_1 * V_34 ;
int V_35 , V_36 = 0 ;
T_3 V_37 ;
if ( F_14 ( V_21 > V_41 ) )
return - V_22 ;
if ( F_14 ( V_32 >= V_2 -> V_4 . V_5 ) )
return - V_24 ;
if ( F_14 ( V_21 == V_42 ) )
return - V_43 ;
V_37 = F_7 ( V_4 -> V_20 , 8 ) ;
F_18 () ;
V_34 = V_2 -> V_6 [ V_32 ] ;
F_19 (cpu) {
F_20 ( F_21 ( V_34 , V_35 ) , V_33 + V_36 , V_37 ) ;
V_36 += V_37 ;
}
F_22 () ;
return 0 ;
}
static int F_26 ( struct V_12 * V_4 , void * V_31 )
{
return - V_22 ;
}
static void F_27 ( struct V_12 * V_4 )
{
struct V_1 * V_2 = F_13 ( V_4 , struct V_1 , V_4 ) ;
F_28 () ;
if ( V_2 -> V_4 . V_16 == V_17 )
F_1 ( V_2 ) ;
F_11 ( V_2 ) ;
}
static int T_4 F_29 ( void )
{
F_30 ( & V_44 ) ;
F_30 ( & V_45 ) ;
return 0 ;
}
static struct V_12 * F_31 ( union V_13 * V_14 )
{
if ( V_14 -> V_20 != sizeof( T_3 ) )
return F_6 ( - V_22 ) ;
return F_5 ( V_14 ) ;
}
static void F_32 ( struct V_12 * V_4 )
{
struct V_1 * V_2 = F_13 ( V_4 , struct V_1 , V_4 ) ;
int V_3 ;
F_28 () ;
for ( V_3 = 0 ; V_3 < V_2 -> V_4 . V_5 ; V_3 ++ )
F_33 ( V_2 -> V_46 [ V_3 ] != NULL ) ;
F_11 ( V_2 ) ;
}
static void * F_34 ( struct V_12 * V_4 , void * V_31 )
{
return NULL ;
}
static int F_35 ( struct V_12 * V_4 , void * V_31 ,
void * V_33 , T_2 V_21 )
{
struct V_1 * V_2 = F_13 ( V_4 , struct V_1 , V_4 ) ;
void * V_47 , * V_48 ;
T_3 V_32 = * ( T_3 * ) V_31 , V_49 ;
if ( V_21 != V_50 )
return - V_22 ;
if ( V_32 >= V_2 -> V_4 . V_5 )
return - V_24 ;
V_49 = * ( T_3 * ) V_33 ;
V_47 = V_4 -> V_51 -> V_52 ( V_4 , V_49 ) ;
if ( F_36 ( V_47 ) )
return F_37 ( V_47 ) ;
V_48 = F_38 ( V_2 -> V_46 + V_32 , V_47 ) ;
if ( V_48 )
V_4 -> V_51 -> V_53 ( V_48 ) ;
return 0 ;
}
static int F_39 ( struct V_12 * V_4 , void * V_31 )
{
struct V_1 * V_2 = F_13 ( V_4 , struct V_1 , V_4 ) ;
void * V_48 ;
T_3 V_32 = * ( T_3 * ) V_31 ;
if ( V_32 >= V_2 -> V_4 . V_5 )
return - V_24 ;
V_48 = F_38 ( V_2 -> V_46 + V_32 , NULL ) ;
if ( V_48 ) {
V_4 -> V_51 -> V_53 ( V_48 ) ;
return 0 ;
} else {
return - V_38 ;
}
}
static void * F_40 ( struct V_12 * V_4 , int V_54 )
{
struct V_1 * V_2 = F_13 ( V_4 , struct V_1 , V_4 ) ;
struct V_55 * V_56 = F_41 ( V_54 ) ;
if ( F_36 ( V_56 ) )
return V_56 ;
if ( ! F_42 ( V_2 , V_56 ) ) {
F_43 ( V_56 ) ;
return F_6 ( - V_22 ) ;
}
return V_56 ;
}
static void F_44 ( void * V_7 )
{
struct V_55 * V_56 = V_7 ;
F_45 ( V_56 ) ;
}
void F_46 ( struct V_12 * V_4 )
{
struct V_1 * V_2 = F_13 ( V_4 , struct V_1 , V_4 ) ;
int V_3 ;
for ( V_3 = 0 ; V_3 < V_2 -> V_4 . V_5 ; V_3 ++ )
F_39 ( V_4 , & V_3 ) ;
}
static int T_4 F_47 ( void )
{
F_30 ( & V_57 ) ;
return 0 ;
}
static void F_48 ( struct V_12 * V_4 )
{
F_46 ( V_4 ) ;
F_32 ( V_4 ) ;
}
static void * F_49 ( struct V_12 * V_4 , int V_54 )
{
struct V_58 * V_59 ;
const struct V_60 * V_14 ;
struct V_61 * V_61 ;
V_61 = F_50 ( V_54 ) ;
if ( F_36 ( V_61 ) )
return V_61 ;
V_59 = V_61 -> V_62 ;
V_14 = F_51 ( V_59 ) ;
if ( F_36 ( V_14 ) )
goto V_63;
if ( V_14 -> V_64 )
goto V_63;
if ( V_14 -> type == V_65 )
return V_61 ;
if ( V_14 -> type == V_66 )
return V_61 ;
if ( V_14 -> type == V_67 &&
V_14 -> V_68 == V_69 )
return V_61 ;
V_63:
F_52 ( V_61 ) ;
return F_6 ( - V_22 ) ;
}
static void F_53 ( void * V_7 )
{
F_52 ( (struct V_61 * ) V_7 ) ;
}
static int T_4 F_54 ( void )
{
F_30 ( & V_70 ) ;
return 0 ;
}
