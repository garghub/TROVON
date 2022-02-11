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
if ( V_14 -> V_20 > V_23 )
return F_6 ( - V_24 ) ;
V_8 = F_7 ( V_14 -> V_20 , 8 ) ;
V_18 = sizeof( * V_2 ) ;
if ( V_15 )
V_18 += ( T_2 ) V_14 -> V_5 * sizeof( void * ) ;
else
V_18 += ( T_2 ) V_14 -> V_5 * V_8 ;
if ( V_18 >= V_25 - V_26 )
return F_6 ( - V_11 ) ;
V_2 = F_8 ( V_18 ) ;
if ( ! V_2 )
return F_6 ( - V_11 ) ;
V_2 -> V_4 . V_16 = V_14 -> V_16 ;
V_2 -> V_4 . V_19 = V_14 -> V_19 ;
V_2 -> V_4 . V_20 = V_14 -> V_20 ;
V_2 -> V_4 . V_5 = V_14 -> V_5 ;
V_2 -> V_8 = V_8 ;
if ( ! V_15 )
goto V_27;
V_18 += ( T_2 ) V_14 -> V_5 * V_8 * F_9 () ;
if ( V_18 >= V_25 - V_26 ||
V_8 > V_28 || F_3 ( V_2 ) ) {
F_10 ( V_2 ) ;
return F_6 ( - V_11 ) ;
}
V_27:
V_2 -> V_4 . V_29 = F_7 ( V_18 , V_26 ) >> V_30 ;
return & V_2 -> V_4 ;
}
static void * F_11 ( struct V_12 * V_4 , void * V_31 )
{
struct V_1 * V_2 = F_12 ( V_4 , struct V_1 , V_4 ) ;
T_3 V_32 = * ( T_3 * ) V_31 ;
if ( F_13 ( V_32 >= V_2 -> V_4 . V_5 ) )
return NULL ;
return V_2 -> V_33 + V_2 -> V_8 * V_32 ;
}
static void * F_14 ( struct V_12 * V_4 , void * V_31 )
{
struct V_1 * V_2 = F_12 ( V_4 , struct V_1 , V_4 ) ;
T_3 V_32 = * ( T_3 * ) V_31 ;
if ( F_13 ( V_32 >= V_2 -> V_4 . V_5 ) )
return NULL ;
return F_15 ( V_2 -> V_6 [ V_32 ] ) ;
}
int F_16 ( struct V_12 * V_4 , void * V_31 , void * V_33 )
{
struct V_1 * V_2 = F_12 ( V_4 , struct V_1 , V_4 ) ;
T_3 V_32 = * ( T_3 * ) V_31 ;
void T_1 * V_34 ;
int V_35 , V_36 = 0 ;
T_3 V_37 ;
if ( F_13 ( V_32 >= V_2 -> V_4 . V_5 ) )
return - V_38 ;
V_37 = F_7 ( V_4 -> V_20 , 8 ) ;
F_17 () ;
V_34 = V_2 -> V_6 [ V_32 ] ;
F_18 (cpu) {
F_19 ( V_33 + V_36 , F_20 ( V_34 , V_35 ) , V_37 ) ;
V_36 += V_37 ;
}
F_21 () ;
return 0 ;
}
static int F_22 ( struct V_12 * V_4 , void * V_31 , void * V_39 )
{
struct V_1 * V_2 = F_12 ( V_4 , struct V_1 , V_4 ) ;
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
static int F_23 ( struct V_12 * V_4 , void * V_31 , void * V_33 ,
T_2 V_21 )
{
struct V_1 * V_2 = F_12 ( V_4 , struct V_1 , V_4 ) ;
T_3 V_32 = * ( T_3 * ) V_31 ;
if ( F_13 ( V_21 > V_41 ) )
return - V_22 ;
if ( F_13 ( V_32 >= V_2 -> V_4 . V_5 ) )
return - V_24 ;
if ( F_13 ( V_21 == V_42 ) )
return - V_43 ;
if ( V_2 -> V_4 . V_16 == V_17 )
memcpy ( F_15 ( V_2 -> V_6 [ V_32 ] ) ,
V_33 , V_4 -> V_20 ) ;
else
memcpy ( V_2 -> V_33 + V_2 -> V_8 * V_32 ,
V_33 , V_4 -> V_20 ) ;
return 0 ;
}
int F_24 ( struct V_12 * V_4 , void * V_31 , void * V_33 ,
T_2 V_21 )
{
struct V_1 * V_2 = F_12 ( V_4 , struct V_1 , V_4 ) ;
T_3 V_32 = * ( T_3 * ) V_31 ;
void T_1 * V_34 ;
int V_35 , V_36 = 0 ;
T_3 V_37 ;
if ( F_13 ( V_21 > V_41 ) )
return - V_22 ;
if ( F_13 ( V_32 >= V_2 -> V_4 . V_5 ) )
return - V_24 ;
if ( F_13 ( V_21 == V_42 ) )
return - V_43 ;
V_37 = F_7 ( V_4 -> V_20 , 8 ) ;
F_17 () ;
V_34 = V_2 -> V_6 [ V_32 ] ;
F_18 (cpu) {
F_19 ( F_20 ( V_34 , V_35 ) , V_33 + V_36 , V_37 ) ;
V_36 += V_37 ;
}
F_21 () ;
return 0 ;
}
static int F_25 ( struct V_12 * V_4 , void * V_31 )
{
return - V_22 ;
}
static void F_26 ( struct V_12 * V_4 )
{
struct V_1 * V_2 = F_12 ( V_4 , struct V_1 , V_4 ) ;
F_27 () ;
if ( V_2 -> V_4 . V_16 == V_17 )
F_1 ( V_2 ) ;
F_10 ( V_2 ) ;
}
static int T_4 F_28 ( void )
{
F_29 ( & V_44 ) ;
F_29 ( & V_45 ) ;
return 0 ;
}
static struct V_12 * F_30 ( union V_13 * V_14 )
{
if ( V_14 -> V_20 != sizeof( T_3 ) )
return F_6 ( - V_22 ) ;
return F_5 ( V_14 ) ;
}
static void F_31 ( struct V_12 * V_4 )
{
struct V_1 * V_2 = F_12 ( V_4 , struct V_1 , V_4 ) ;
int V_3 ;
F_27 () ;
for ( V_3 = 0 ; V_3 < V_2 -> V_4 . V_5 ; V_3 ++ )
F_32 ( V_2 -> V_46 [ V_3 ] != NULL ) ;
F_10 ( V_2 ) ;
}
static void * F_33 ( struct V_12 * V_4 , void * V_31 )
{
return NULL ;
}
int F_34 ( struct V_12 * V_4 , struct V_47 * V_48 ,
void * V_31 , void * V_33 , T_2 V_21 )
{
struct V_1 * V_2 = F_12 ( V_4 , struct V_1 , V_4 ) ;
void * V_49 , * V_50 ;
T_3 V_32 = * ( T_3 * ) V_31 , V_51 ;
if ( V_21 != V_52 )
return - V_22 ;
if ( V_32 >= V_2 -> V_4 . V_5 )
return - V_24 ;
V_51 = * ( T_3 * ) V_33 ;
V_49 = V_4 -> V_53 -> V_54 ( V_4 , V_48 , V_51 ) ;
if ( F_35 ( V_49 ) )
return F_36 ( V_49 ) ;
V_50 = F_37 ( V_2 -> V_46 + V_32 , V_49 ) ;
if ( V_50 )
V_4 -> V_53 -> V_55 ( V_50 ) ;
return 0 ;
}
static int F_38 ( struct V_12 * V_4 , void * V_31 )
{
struct V_1 * V_2 = F_12 ( V_4 , struct V_1 , V_4 ) ;
void * V_50 ;
T_3 V_32 = * ( T_3 * ) V_31 ;
if ( V_32 >= V_2 -> V_4 . V_5 )
return - V_24 ;
V_50 = F_37 ( V_2 -> V_46 + V_32 , NULL ) ;
if ( V_50 ) {
V_4 -> V_53 -> V_55 ( V_50 ) ;
return 0 ;
} else {
return - V_38 ;
}
}
static void * F_39 ( struct V_12 * V_4 ,
struct V_47 * V_48 , int V_56 )
{
struct V_1 * V_2 = F_12 ( V_4 , struct V_1 , V_4 ) ;
struct V_57 * V_58 = F_40 ( V_56 ) ;
if ( F_35 ( V_58 ) )
return V_58 ;
if ( ! F_41 ( V_2 , V_58 ) ) {
F_42 ( V_58 ) ;
return F_6 ( - V_22 ) ;
}
return V_58 ;
}
static void F_43 ( void * V_7 )
{
F_42 ( V_7 ) ;
}
void F_44 ( struct V_12 * V_4 )
{
struct V_1 * V_2 = F_12 ( V_4 , struct V_1 , V_4 ) ;
int V_3 ;
for ( V_3 = 0 ; V_3 < V_2 -> V_4 . V_5 ; V_3 ++ )
F_38 ( V_4 , & V_3 ) ;
}
static int T_4 F_45 ( void )
{
F_29 ( & V_59 ) ;
return 0 ;
}
static struct V_60 * F_46 ( struct V_47 * V_61 ,
struct V_47 * V_48 )
{
struct V_60 * V_62 ;
V_62 = F_47 ( sizeof( * V_62 ) , V_63 ) ;
if ( V_62 ) {
V_62 -> V_64 = V_61 -> V_65 ;
V_62 -> V_61 = V_61 ;
V_62 -> V_48 = V_48 ;
}
return V_62 ;
}
static void F_48 ( struct V_66 * V_67 )
{
struct V_60 * V_62 ;
V_62 = F_12 ( V_67 , struct V_60 , V_67 ) ;
F_49 ( V_62 -> V_61 ) ;
F_50 ( V_62 ) ;
}
static void F_51 ( struct V_60 * V_62 )
{
F_52 ( & V_62 -> V_67 , F_48 ) ;
}
static void * F_53 ( struct V_12 * V_4 ,
struct V_47 * V_48 , int V_56 )
{
const struct V_68 * V_14 ;
struct V_60 * V_62 ;
struct V_69 * V_64 ;
struct V_47 * V_61 ;
V_61 = F_54 ( V_56 ) ;
if ( F_35 ( V_61 ) )
return V_61 ;
V_64 = V_61 -> V_65 ;
V_62 = F_6 ( - V_22 ) ;
V_14 = F_55 ( V_64 ) ;
if ( F_35 ( V_14 ) || V_14 -> V_70 )
goto V_71;
switch ( V_14 -> type ) {
case V_72 :
if ( V_14 -> V_73 != V_74 )
goto V_71;
case V_75 :
case V_76 :
V_62 = F_46 ( V_61 , V_48 ) ;
if ( V_62 )
return V_62 ;
V_62 = F_6 ( - V_11 ) ;
default:
break;
}
V_71:
F_49 ( V_61 ) ;
return V_62 ;
}
static void F_56 ( void * V_7 )
{
F_51 ( V_7 ) ;
}
static void F_57 ( struct V_12 * V_4 ,
struct V_47 * V_48 )
{
struct V_1 * V_2 = F_12 ( V_4 , struct V_1 , V_4 ) ;
struct V_60 * V_62 ;
int V_3 ;
F_17 () ;
for ( V_3 = 0 ; V_3 < V_2 -> V_4 . V_5 ; V_3 ++ ) {
V_62 = F_58 ( V_2 -> V_46 [ V_3 ] ) ;
if ( V_62 && V_62 -> V_48 == V_48 )
F_38 ( V_4 , & V_3 ) ;
}
F_21 () ;
}
static int T_4 F_59 ( void )
{
F_29 ( & V_77 ) ;
return 0 ;
}
static void * F_60 ( struct V_12 * V_4 ,
struct V_47 * V_48 ,
int V_56 )
{
return F_61 ( V_56 ) ;
}
static void F_62 ( void * V_7 )
{
F_63 ( V_7 ) ;
}
static void F_64 ( struct V_12 * V_4 )
{
F_44 ( V_4 ) ;
F_31 ( V_4 ) ;
}
static int T_4 F_65 ( void )
{
F_29 ( & V_78 ) ;
return 0 ;
}
