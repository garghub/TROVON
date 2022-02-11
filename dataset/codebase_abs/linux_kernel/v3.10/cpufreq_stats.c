static int F_1 ( unsigned int V_1 )
{
struct V_2 * V_3 ;
unsigned long long V_4 ;
V_4 = F_2 () ;
F_3 ( & V_5 ) ;
V_3 = F_4 ( V_6 , V_1 ) ;
if ( V_3 -> V_7 )
V_3 -> V_7 [ V_3 -> V_8 ] +=
V_4 - V_3 -> V_9 ;
V_3 -> V_9 = V_4 ;
F_5 ( & V_5 ) ;
return 0 ;
}
static T_1 F_6 ( struct V_10 * V_11 , char * V_12 )
{
struct V_2 * V_3 = F_4 ( V_6 , V_11 -> V_1 ) ;
if ( ! V_3 )
return 0 ;
return sprintf ( V_12 , L_1 ,
F_4 ( V_6 , V_3 -> V_1 ) -> V_13 ) ;
}
static T_1 F_7 ( struct V_10 * V_11 , char * V_12 )
{
T_1 V_14 = 0 ;
int V_15 ;
struct V_2 * V_3 = F_4 ( V_6 , V_11 -> V_1 ) ;
if ( ! V_3 )
return 0 ;
F_1 ( V_3 -> V_1 ) ;
for ( V_15 = 0 ; V_15 < V_3 -> V_16 ; V_15 ++ ) {
V_14 += sprintf ( V_12 + V_14 , L_2 , V_3 -> V_17 [ V_15 ] ,
( unsigned long long )
F_8 ( V_3 -> V_7 [ V_15 ] ) ) ;
}
return V_14 ;
}
static T_1 F_9 ( struct V_10 * V_11 , char * V_12 )
{
T_1 V_14 = 0 ;
int V_15 , V_18 ;
struct V_2 * V_3 = F_4 ( V_6 , V_11 -> V_1 ) ;
if ( ! V_3 )
return 0 ;
F_1 ( V_3 -> V_1 ) ;
V_14 += snprintf ( V_12 + V_14 , V_19 - V_14 , L_3 ) ;
V_14 += snprintf ( V_12 + V_14 , V_19 - V_14 , L_4 ) ;
for ( V_15 = 0 ; V_15 < V_3 -> V_16 ; V_15 ++ ) {
if ( V_14 >= V_19 )
break;
V_14 += snprintf ( V_12 + V_14 , V_19 - V_14 , L_5 ,
V_3 -> V_17 [ V_15 ] ) ;
}
if ( V_14 >= V_19 )
return V_19 ;
V_14 += snprintf ( V_12 + V_14 , V_19 - V_14 , L_6 ) ;
for ( V_15 = 0 ; V_15 < V_3 -> V_16 ; V_15 ++ ) {
if ( V_14 >= V_19 )
break;
V_14 += snprintf ( V_12 + V_14 , V_19 - V_14 , L_7 ,
V_3 -> V_17 [ V_15 ] ) ;
for ( V_18 = 0 ; V_18 < V_3 -> V_16 ; V_18 ++ ) {
if ( V_14 >= V_19 )
break;
V_14 += snprintf ( V_12 + V_14 , V_19 - V_14 , L_5 ,
V_3 -> V_20 [ V_15 * V_3 -> V_21 + V_18 ] ) ;
}
if ( V_14 >= V_19 )
break;
V_14 += snprintf ( V_12 + V_14 , V_19 - V_14 , L_6 ) ;
}
if ( V_14 >= V_19 )
return V_19 ;
return V_14 ;
}
static int F_10 ( struct V_2 * V_3 , unsigned int V_22 )
{
int V_23 ;
for ( V_23 = 0 ; V_23 < V_3 -> V_21 ; V_23 ++ )
if ( V_3 -> V_17 [ V_23 ] == V_22 )
return V_23 ;
return - 1 ;
}
static void F_11 ( unsigned int V_1 )
{
struct V_2 * V_3 = F_4 ( V_6 , V_1 ) ;
if ( V_3 ) {
F_12 ( L_8 , V_24 ) ;
F_13 ( V_3 -> V_7 ) ;
F_13 ( V_3 ) ;
F_4 ( V_6 , V_1 ) = NULL ;
}
}
static void F_14 ( unsigned int V_1 )
{
struct V_10 * V_11 = F_15 ( V_1 ) ;
if ( ! V_11 )
return;
if ( ! F_16 ( V_1 ) )
goto V_25;
if ( ! F_17 ( V_11 ) ) {
F_12 ( L_9 , V_24 ) ;
F_18 ( & V_11 -> V_26 , & V_27 ) ;
}
V_25:
F_19 ( V_11 ) ;
}
static int F_20 ( struct V_10 * V_11 ,
struct V_28 * V_29 )
{
unsigned int V_15 , V_18 , V_30 = 0 , V_31 = 0 ;
struct V_2 * V_3 ;
struct V_10 * V_32 ;
unsigned int V_33 ;
unsigned int V_1 = V_11 -> V_1 ;
if ( F_4 ( V_6 , V_1 ) )
return - V_34 ;
V_3 = F_21 ( sizeof( struct V_2 ) , V_35 ) ;
if ( ( V_3 ) == NULL )
return - V_36 ;
V_32 = F_15 ( V_1 ) ;
if ( V_32 == NULL ) {
V_31 = - V_37 ;
goto V_38;
}
V_31 = F_22 ( & V_32 -> V_26 , & V_27 ) ;
if ( V_31 )
goto V_39;
V_3 -> V_1 = V_1 ;
F_4 ( V_6 , V_1 ) = V_3 ;
for ( V_15 = 0 ; V_29 [ V_15 ] . V_40 != V_41 ; V_15 ++ ) {
unsigned int V_22 = V_29 [ V_15 ] . V_40 ;
if ( V_22 == V_42 )
continue;
V_30 ++ ;
}
V_33 = V_30 * sizeof( int ) + V_30 * sizeof( V_43 ) ;
#ifdef F_23
V_33 += V_30 * V_30 * sizeof( int ) ;
#endif
V_3 -> V_21 = V_30 ;
V_3 -> V_7 = F_21 ( V_33 , V_35 ) ;
if ( ! V_3 -> V_7 ) {
V_31 = - V_36 ;
goto V_39;
}
V_3 -> V_17 = ( unsigned int * ) ( V_3 -> V_7 + V_30 ) ;
#ifdef F_23
V_3 -> V_20 = V_3 -> V_17 + V_30 ;
#endif
V_18 = 0 ;
for ( V_15 = 0 ; V_29 [ V_15 ] . V_40 != V_41 ; V_15 ++ ) {
unsigned int V_22 = V_29 [ V_15 ] . V_40 ;
if ( V_22 == V_42 )
continue;
if ( F_10 ( V_3 , V_22 ) == - 1 )
V_3 -> V_17 [ V_18 ++ ] = V_22 ;
}
V_3 -> V_16 = V_18 ;
F_3 ( & V_5 ) ;
V_3 -> V_9 = F_2 () ;
V_3 -> V_8 = F_10 ( V_3 , V_11 -> V_44 ) ;
F_5 ( & V_5 ) ;
F_19 ( V_32 ) ;
return 0 ;
V_39:
F_19 ( V_32 ) ;
V_38:
F_13 ( V_3 ) ;
F_4 ( V_6 , V_1 ) = NULL ;
return V_31 ;
}
static void F_24 ( struct V_10 * V_11 )
{
struct V_2 * V_3 = F_4 ( V_6 ,
V_11 -> V_45 ) ;
F_12 ( L_10 ,
V_11 -> V_1 , V_11 -> V_45 ) ;
F_4 ( V_6 , V_11 -> V_1 ) = F_4 ( V_6 ,
V_11 -> V_45 ) ;
F_4 ( V_6 , V_11 -> V_45 ) = NULL ;
V_3 -> V_1 = V_11 -> V_1 ;
}
static int F_25 ( struct V_46 * V_47 ,
unsigned long V_48 , void * V_32 )
{
int V_31 ;
struct V_10 * V_11 = V_32 ;
struct V_28 * V_29 ;
unsigned int V_1 = V_11 -> V_1 ;
if ( V_48 == V_49 ) {
F_24 ( V_11 ) ;
return 0 ;
}
if ( V_48 != V_50 )
return 0 ;
V_29 = F_16 ( V_1 ) ;
if ( ! V_29 )
return 0 ;
V_31 = F_20 ( V_11 , V_29 ) ;
if ( V_31 )
return V_31 ;
return 0 ;
}
static int F_26 ( struct V_46 * V_47 ,
unsigned long V_48 , void * V_32 )
{
struct V_51 * V_22 = V_32 ;
struct V_2 * V_3 ;
int V_52 , V_53 ;
if ( V_48 != V_54 )
return 0 ;
V_3 = F_4 ( V_6 , V_22 -> V_1 ) ;
if ( ! V_3 )
return 0 ;
V_52 = V_3 -> V_8 ;
V_53 = F_10 ( V_3 , V_22 -> V_55 ) ;
if ( V_52 == - 1 || V_53 == - 1 )
return 0 ;
F_1 ( V_22 -> V_1 ) ;
if ( V_52 == V_53 )
return 0 ;
F_3 ( & V_5 ) ;
V_3 -> V_8 = V_53 ;
#ifdef F_23
V_3 -> V_20 [ V_52 * V_3 -> V_21 + V_53 ] ++ ;
#endif
V_3 -> V_13 ++ ;
F_5 ( & V_5 ) ;
return 0 ;
}
static int T_2 F_27 ( struct V_46 * V_56 ,
unsigned long V_57 ,
void * V_58 )
{
unsigned int V_1 = ( unsigned long ) V_58 ;
switch ( V_57 ) {
case V_59 :
F_28 ( V_1 ) ;
break;
case V_60 :
F_14 ( V_1 ) ;
break;
case V_61 :
F_11 ( V_1 ) ;
break;
case V_62 :
F_14 ( V_1 ) ;
F_11 ( V_1 ) ;
break;
}
return V_63 ;
}
static int T_3 F_29 ( void )
{
int V_31 ;
unsigned int V_1 ;
F_30 ( & V_5 ) ;
V_31 = F_31 ( & V_64 ,
V_65 ) ;
if ( V_31 )
return V_31 ;
F_32 ( & V_66 ) ;
F_33 (cpu)
F_28 ( V_1 ) ;
V_31 = F_31 ( & V_67 ,
V_68 ) ;
if ( V_31 ) {
F_34 ( & V_64 ,
V_65 ) ;
F_35 ( & V_66 ) ;
F_33 (cpu)
F_11 ( V_1 ) ;
return V_31 ;
}
return 0 ;
}
static void T_4 F_36 ( void )
{
unsigned int V_1 ;
F_34 ( & V_64 ,
V_65 ) ;
F_34 ( & V_67 ,
V_68 ) ;
F_35 ( & V_66 ) ;
F_33 (cpu) {
F_11 ( V_1 ) ;
F_14 ( V_1 ) ;
}
}
