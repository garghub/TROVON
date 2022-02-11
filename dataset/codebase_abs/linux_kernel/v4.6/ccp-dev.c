unsigned int F_1 ( void )
{
return F_2 ( & V_1 ) ;
}
void F_3 ( struct V_2 * V_3 )
{
unsigned long V_4 ;
F_4 ( & V_5 , V_4 ) ;
F_5 ( & V_3 -> V_6 , & V_7 ) ;
if ( ! V_8 )
V_8 = V_3 ;
F_6 ( & V_5 , V_4 ) ;
}
void F_7 ( struct V_2 * V_3 )
{
unsigned long V_4 ;
F_4 ( & V_5 , V_4 ) ;
if ( V_8 == V_3 ) {
if ( F_8 ( & V_8 -> V_6 , & V_7 ) )
V_8 = F_9 ( & V_7 , struct V_2 ,
V_6 ) ;
else
V_8 = F_10 ( V_8 , V_6 ) ;
}
F_11 ( & V_3 -> V_6 ) ;
if ( F_12 ( & V_7 ) )
V_8 = NULL ;
F_6 ( & V_5 , V_4 ) ;
}
static struct V_2 * F_13 ( void )
{
unsigned long V_4 ;
struct V_2 * V_9 = NULL ;
F_14 ( & V_5 , V_4 ) ;
if ( ! F_12 ( & V_7 ) ) {
F_15 ( & V_10 ) ;
V_9 = V_8 ;
if ( F_8 ( & V_8 -> V_6 , & V_7 ) )
V_8 = F_9 ( & V_7 , struct V_2 ,
V_6 ) ;
else
V_8 = F_10 ( V_8 , V_6 ) ;
F_16 ( & V_10 ) ;
}
F_17 ( & V_5 , V_4 ) ;
return V_9 ;
}
int F_18 ( void )
{
unsigned long V_4 ;
int V_11 ;
F_14 ( & V_5 , V_4 ) ;
V_11 = F_12 ( & V_7 ) ;
F_17 ( & V_5 , V_4 ) ;
return V_11 ? - V_12 : 0 ;
}
unsigned int F_19 ( void )
{
struct V_2 * V_9 ;
unsigned long V_4 ;
int V_11 = 0 ;
F_14 ( & V_5 , V_4 ) ;
if ( ! F_12 ( & V_7 ) ) {
V_9 = F_9 ( & V_7 , struct V_2 , V_6 ) ;
V_11 = V_9 -> V_13 -> V_14 ;
}
F_17 ( & V_5 , V_4 ) ;
return V_11 ;
}
int F_20 ( struct V_15 * V_16 )
{
struct V_2 * V_3 = F_13 () ;
unsigned long V_4 ;
unsigned int V_17 ;
int V_11 ;
if ( ! V_3 )
return - V_12 ;
if ( ! V_16 -> V_18 )
return - V_19 ;
V_16 -> V_3 = V_3 ;
F_21 ( & V_3 -> V_20 , V_4 ) ;
V_17 = V_3 -> V_21 ;
if ( V_3 -> V_22 >= V_23 ) {
V_11 = - V_24 ;
if ( V_16 -> V_4 & V_25 )
F_5 ( & V_16 -> V_6 , & V_3 -> V_26 ) ;
} else {
V_11 = - V_27 ;
V_3 -> V_22 ++ ;
F_5 ( & V_16 -> V_6 , & V_3 -> V_16 ) ;
if ( ! V_3 -> V_28 ) {
for ( V_17 = 0 ; V_17 < V_3 -> V_21 ; V_17 ++ ) {
if ( V_3 -> V_29 [ V_17 ] . V_30 )
continue;
break;
}
}
}
F_22 ( & V_3 -> V_20 , V_4 ) ;
if ( V_17 < V_3 -> V_21 )
F_23 ( V_3 -> V_29 [ V_17 ] . V_31 ) ;
return V_11 ;
}
static void F_24 ( struct V_32 * V_33 )
{
struct V_15 * V_16 = F_25 ( V_33 , struct V_15 , V_33 ) ;
struct V_2 * V_3 = V_16 -> V_3 ;
unsigned long V_4 ;
unsigned int V_17 ;
V_16 -> V_18 ( V_16 -> V_34 , - V_27 ) ;
F_21 ( & V_3 -> V_20 , V_4 ) ;
V_3 -> V_22 ++ ;
F_5 ( & V_16 -> V_6 , & V_3 -> V_16 ) ;
for ( V_17 = 0 ; V_17 < V_3 -> V_21 ; V_17 ++ ) {
if ( V_3 -> V_29 [ V_17 ] . V_30 )
continue;
break;
}
F_22 ( & V_3 -> V_20 , V_4 ) ;
if ( V_17 < V_3 -> V_21 )
F_23 ( V_3 -> V_29 [ V_17 ] . V_31 ) ;
}
static struct V_15 * F_26 ( struct V_35 * V_29 )
{
struct V_2 * V_3 = V_29 -> V_3 ;
struct V_15 * V_16 = NULL ;
struct V_15 * V_26 = NULL ;
unsigned long V_4 ;
F_21 ( & V_3 -> V_20 , V_4 ) ;
V_29 -> V_30 = 0 ;
if ( V_3 -> V_28 ) {
V_29 -> V_36 = 1 ;
F_22 ( & V_3 -> V_20 , V_4 ) ;
F_27 ( & V_3 -> V_37 ) ;
return NULL ;
}
if ( V_3 -> V_22 ) {
V_29 -> V_30 = 1 ;
V_16 = F_9 ( & V_3 -> V_16 , struct V_15 , V_6 ) ;
F_11 ( & V_16 -> V_6 ) ;
V_3 -> V_22 -- ;
}
if ( ! F_12 ( & V_3 -> V_26 ) ) {
V_26 = F_9 ( & V_3 -> V_26 , struct V_15 ,
V_6 ) ;
F_11 ( & V_26 -> V_6 ) ;
}
F_22 ( & V_3 -> V_20 , V_4 ) ;
if ( V_26 ) {
F_28 ( & V_26 -> V_33 , F_24 ) ;
F_29 ( & V_26 -> V_33 ) ;
}
return V_16 ;
}
static void F_30 ( unsigned long V_34 )
{
struct V_38 * V_39 = (struct V_38 * ) V_34 ;
struct V_15 * V_16 = V_39 -> V_16 ;
V_16 -> V_18 ( V_16 -> V_34 , V_16 -> V_11 ) ;
F_31 ( & V_39 -> V_40 ) ;
}
int F_32 ( void * V_34 )
{
struct V_35 * V_29 = (struct V_35 * ) V_34 ;
struct V_15 * V_16 ;
struct V_38 V_39 ;
struct V_41 V_42 ;
F_33 ( & V_42 , F_30 , ( unsigned long ) & V_39 ) ;
F_34 ( V_43 ) ;
while ( ! F_35 () ) {
F_36 () ;
F_34 ( V_43 ) ;
V_16 = F_26 ( V_29 ) ;
if ( ! V_16 )
continue;
F_37 ( V_44 ) ;
V_16 -> V_11 = F_38 ( V_29 , V_16 ) ;
V_39 . V_16 = V_16 ;
F_39 ( & V_39 . V_40 ) ;
F_40 ( & V_42 ) ;
F_41 ( & V_39 . V_40 ) ;
}
F_37 ( V_44 ) ;
return 0 ;
}
struct V_2 * F_42 ( struct V_45 * V_46 )
{
struct V_2 * V_3 ;
V_3 = F_43 ( V_46 , sizeof( * V_3 ) , V_47 ) ;
if ( ! V_3 )
return NULL ;
V_3 -> V_46 = V_46 ;
F_44 ( & V_3 -> V_16 ) ;
F_44 ( & V_3 -> V_26 ) ;
F_45 ( & V_3 -> V_20 ) ;
F_46 ( & V_3 -> V_48 ) ;
F_46 ( & V_3 -> V_49 ) ;
V_3 -> V_50 = V_51 ;
V_3 -> V_52 = 0 ;
V_3 -> V_53 = F_1 () ;
snprintf ( V_3 -> V_54 , V_55 , L_1 , V_3 -> V_53 ) ;
snprintf ( V_3 -> V_56 , V_55 , L_2 , V_3 -> V_53 ) ;
return V_3 ;
}
bool F_47 ( struct V_2 * V_3 )
{
unsigned int V_36 = 0 ;
unsigned long V_4 ;
unsigned int V_17 ;
F_21 ( & V_3 -> V_20 , V_4 ) ;
for ( V_17 = 0 ; V_17 < V_3 -> V_21 ; V_17 ++ )
if ( V_3 -> V_29 [ V_17 ] . V_36 )
V_36 ++ ;
F_22 ( & V_3 -> V_20 , V_4 ) ;
return V_3 -> V_21 == V_36 ;
}
static int T_1 F_48 ( void )
{
#ifdef F_49
int V_11 ;
V_11 = F_50 () ;
if ( V_11 )
return V_11 ;
if ( F_18 () != 0 ) {
F_51 () ;
return - V_12 ;
}
return 0 ;
#endif
#ifdef F_52
int V_11 ;
V_11 = F_53 () ;
if ( V_11 )
return V_11 ;
if ( F_18 () != 0 ) {
F_54 () ;
return - V_12 ;
}
return 0 ;
#endif
return - V_12 ;
}
static void T_2 F_55 ( void )
{
#ifdef F_49
F_51 () ;
#endif
#ifdef F_52
F_54 () ;
#endif
}
