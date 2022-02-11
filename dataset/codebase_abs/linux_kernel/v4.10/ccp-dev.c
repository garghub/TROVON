void F_1 ( struct V_1 * V_2 , int V_3 )
{
F_2 ( V_2 -> V_4 , L_1 , V_5 [ V_3 ] , V_3 ) ;
}
static unsigned int F_3 ( void )
{
return F_4 ( & V_6 ) ;
}
void F_5 ( struct V_1 * V_7 )
{
unsigned long V_8 ;
F_6 ( & V_9 , V_8 ) ;
F_7 ( & V_7 -> V_10 , & V_11 ) ;
if ( ! V_12 )
V_12 = V_7 ;
F_8 ( & V_9 , V_8 ) ;
}
void F_9 ( struct V_1 * V_7 )
{
unsigned long V_8 ;
F_6 ( & V_9 , V_8 ) ;
if ( V_12 == V_7 ) {
if ( F_10 ( & V_12 -> V_10 , & V_11 ) )
V_12 = F_11 ( & V_11 , struct V_1 ,
V_10 ) ;
else
V_12 = F_12 ( V_12 , V_10 ) ;
}
F_13 ( & V_7 -> V_10 ) ;
if ( F_14 ( & V_11 ) )
V_12 = NULL ;
F_8 ( & V_9 , V_8 ) ;
}
int F_15 ( struct V_1 * V_7 )
{
int V_13 = 0 ;
F_16 ( V_7 -> V_4 , L_2 ) ;
V_7 -> V_14 . V_15 = V_7 -> V_16 ;
V_7 -> V_14 . V_17 = V_18 ;
V_13 = F_17 ( & V_7 -> V_14 ) ;
if ( V_13 )
F_2 ( V_7 -> V_4 , L_3 , V_13 ) ;
return V_13 ;
}
void F_18 ( struct V_1 * V_7 )
{
if ( V_7 -> V_14 . V_15 )
F_19 ( & V_7 -> V_14 ) ;
}
static struct V_1 * F_20 ( void )
{
unsigned long V_8 ;
struct V_1 * V_19 = NULL ;
F_21 ( & V_9 , V_8 ) ;
if ( ! F_14 ( & V_11 ) ) {
F_22 ( & V_20 ) ;
V_19 = V_12 ;
if ( F_10 ( & V_12 -> V_10 , & V_11 ) )
V_12 = F_11 ( & V_11 , struct V_1 ,
V_10 ) ;
else
V_12 = F_12 ( V_12 , V_10 ) ;
F_23 ( & V_20 ) ;
}
F_24 ( & V_9 , V_8 ) ;
return V_19 ;
}
int F_25 ( void )
{
unsigned long V_8 ;
int V_13 ;
F_21 ( & V_9 , V_8 ) ;
V_13 = F_14 ( & V_11 ) ;
F_24 ( & V_9 , V_8 ) ;
return V_13 ? - V_21 : 0 ;
}
unsigned int F_26 ( void )
{
struct V_1 * V_19 ;
unsigned long V_8 ;
int V_13 = 0 ;
F_21 ( & V_9 , V_8 ) ;
if ( ! F_14 ( & V_11 ) ) {
V_19 = F_11 ( & V_11 , struct V_1 , V_10 ) ;
V_13 = V_19 -> V_22 -> V_23 ;
}
F_24 ( & V_9 , V_8 ) ;
return V_13 ;
}
int F_27 ( struct V_24 * V_25 )
{
struct V_1 * V_7 = F_20 () ;
unsigned long V_8 ;
unsigned int V_26 ;
int V_13 ;
if ( ! V_7 )
return - V_21 ;
if ( ! V_25 -> V_27 )
return - V_28 ;
V_25 -> V_7 = V_7 ;
F_28 ( & V_7 -> V_29 , V_8 ) ;
V_26 = V_7 -> V_30 ;
if ( V_7 -> V_31 >= V_32 ) {
V_13 = - V_33 ;
if ( V_25 -> V_8 & V_34 )
F_7 ( & V_25 -> V_10 , & V_7 -> V_35 ) ;
} else {
V_13 = - V_36 ;
V_7 -> V_31 ++ ;
F_7 ( & V_25 -> V_10 , & V_7 -> V_25 ) ;
if ( ! V_7 -> V_37 ) {
for ( V_26 = 0 ; V_26 < V_7 -> V_30 ; V_26 ++ ) {
if ( V_7 -> V_38 [ V_26 ] . V_39 )
continue;
break;
}
}
}
F_29 ( & V_7 -> V_29 , V_8 ) ;
if ( V_26 < V_7 -> V_30 )
F_30 ( V_7 -> V_38 [ V_26 ] . V_40 ) ;
return V_13 ;
}
static void F_31 ( struct V_41 * V_42 )
{
struct V_24 * V_25 = F_32 ( V_42 , struct V_24 , V_42 ) ;
struct V_1 * V_7 = V_25 -> V_7 ;
unsigned long V_8 ;
unsigned int V_26 ;
V_25 -> V_27 ( V_25 -> V_43 , - V_36 ) ;
F_28 ( & V_7 -> V_29 , V_8 ) ;
V_7 -> V_31 ++ ;
F_7 ( & V_25 -> V_10 , & V_7 -> V_25 ) ;
for ( V_26 = 0 ; V_26 < V_7 -> V_30 ; V_26 ++ ) {
if ( V_7 -> V_38 [ V_26 ] . V_39 )
continue;
break;
}
F_29 ( & V_7 -> V_29 , V_8 ) ;
if ( V_26 < V_7 -> V_30 )
F_30 ( V_7 -> V_38 [ V_26 ] . V_40 ) ;
}
static struct V_24 * F_33 ( struct V_44 * V_38 )
{
struct V_1 * V_7 = V_38 -> V_7 ;
struct V_24 * V_25 = NULL ;
struct V_24 * V_35 = NULL ;
unsigned long V_8 ;
F_28 ( & V_7 -> V_29 , V_8 ) ;
V_38 -> V_39 = 0 ;
if ( V_7 -> V_37 ) {
V_38 -> V_45 = 1 ;
F_29 ( & V_7 -> V_29 , V_8 ) ;
F_34 ( & V_7 -> V_46 ) ;
return NULL ;
}
if ( V_7 -> V_31 ) {
V_38 -> V_39 = 1 ;
V_25 = F_11 ( & V_7 -> V_25 , struct V_24 , V_10 ) ;
F_13 ( & V_25 -> V_10 ) ;
V_7 -> V_31 -- ;
}
if ( ! F_14 ( & V_7 -> V_35 ) ) {
V_35 = F_11 ( & V_7 -> V_35 , struct V_24 ,
V_10 ) ;
F_13 ( & V_35 -> V_10 ) ;
}
F_29 ( & V_7 -> V_29 , V_8 ) ;
if ( V_35 ) {
F_35 ( & V_35 -> V_42 , F_31 ) ;
F_36 ( & V_35 -> V_42 ) ;
}
return V_25 ;
}
static void F_37 ( unsigned long V_43 )
{
struct V_47 * V_48 = (struct V_47 * ) V_43 ;
struct V_24 * V_25 = V_48 -> V_25 ;
V_25 -> V_27 ( V_25 -> V_43 , V_25 -> V_13 ) ;
F_38 ( & V_48 -> V_49 ) ;
}
int F_39 ( void * V_43 )
{
struct V_44 * V_38 = (struct V_44 * ) V_43 ;
struct V_24 * V_25 ;
struct V_47 V_48 ;
struct V_50 V_51 ;
F_40 ( & V_51 , F_37 , ( unsigned long ) & V_48 ) ;
F_41 ( V_52 ) ;
while ( ! F_42 () ) {
F_43 () ;
F_41 ( V_52 ) ;
V_25 = F_33 ( V_38 ) ;
if ( ! V_25 )
continue;
F_44 ( V_53 ) ;
V_25 -> V_13 = F_45 ( V_38 , V_25 ) ;
V_48 . V_25 = V_25 ;
F_46 ( & V_48 . V_49 ) ;
F_47 ( & V_51 ) ;
F_48 ( & V_48 . V_49 ) ;
}
F_44 ( V_53 ) ;
return 0 ;
}
struct V_1 * F_49 ( struct V_54 * V_4 )
{
struct V_1 * V_7 ;
V_7 = F_50 ( V_4 , sizeof( * V_7 ) , V_55 ) ;
if ( ! V_7 )
return NULL ;
V_7 -> V_4 = V_4 ;
F_51 ( & V_7 -> V_25 ) ;
F_51 ( & V_7 -> V_35 ) ;
F_52 ( & V_7 -> V_29 ) ;
F_53 ( & V_7 -> V_56 ) ;
F_53 ( & V_7 -> V_57 ) ;
V_7 -> V_58 = V_59 ;
V_7 -> V_60 = 0 ;
F_54 ( & V_7 -> V_61 ) ;
F_54 ( & V_7 -> V_46 ) ;
V_7 -> V_62 = F_3 () ;
snprintf ( V_7 -> V_15 , V_63 , L_4 , V_7 -> V_62 ) ;
snprintf ( V_7 -> V_16 , V_63 , L_5 , V_7 -> V_62 ) ;
return V_7 ;
}
int V_18 ( struct V_14 * V_64 , void * V_43 , T_1 V_65 , bool V_66 )
{
struct V_1 * V_7 = F_32 ( V_64 , struct V_1 , V_14 ) ;
T_2 V_67 ;
int V_68 = F_55 ( int , sizeof( V_67 ) , V_65 ) ;
V_67 = F_56 ( V_7 -> V_69 + V_70 ) ;
if ( ! V_67 ) {
if ( V_7 -> V_71 ++ > V_72 )
return - V_73 ;
return 0 ;
}
V_7 -> V_71 = 0 ;
memcpy ( V_43 , & V_67 , V_68 ) ;
return V_68 ;
}
bool F_57 ( struct V_1 * V_7 )
{
unsigned int V_45 = 0 ;
unsigned long V_8 ;
unsigned int V_26 ;
F_28 ( & V_7 -> V_29 , V_8 ) ;
for ( V_26 = 0 ; V_26 < V_7 -> V_30 ; V_26 ++ )
if ( V_7 -> V_38 [ V_26 ] . V_45 )
V_45 ++ ;
F_29 ( & V_7 -> V_29 , V_8 ) ;
return V_7 -> V_30 == V_45 ;
}
static int T_3 F_58 ( void )
{
#ifdef F_59
int V_13 ;
V_13 = F_60 () ;
if ( V_13 )
return V_13 ;
if ( F_25 () != 0 ) {
F_61 () ;
return - V_21 ;
}
return 0 ;
#endif
#ifdef F_62
int V_13 ;
V_13 = F_63 () ;
if ( V_13 )
return V_13 ;
if ( F_25 () != 0 ) {
F_64 () ;
return - V_21 ;
}
return 0 ;
#endif
return - V_21 ;
}
static void T_4 F_65 ( void )
{
#ifdef F_59
F_61 () ;
#endif
#ifdef F_62
F_64 () ;
#endif
}
