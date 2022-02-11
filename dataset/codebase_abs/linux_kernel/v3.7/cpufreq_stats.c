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
F_12 ( V_3 -> V_7 ) ;
F_12 ( V_3 ) ;
}
F_4 ( V_6 , V_1 ) = NULL ;
}
static void F_13 ( unsigned int V_1 )
{
struct V_10 * V_11 = F_14 ( V_1 ) ;
if ( V_11 && V_11 -> V_1 == V_1 )
F_15 ( & V_11 -> V_24 , & V_25 ) ;
if ( V_11 )
F_16 ( V_11 ) ;
}
static int F_17 ( struct V_10 * V_11 ,
struct V_26 * V_27 )
{
unsigned int V_15 , V_18 , V_28 = 0 , V_29 = 0 ;
struct V_2 * V_3 ;
struct V_10 * V_30 ;
unsigned int V_31 ;
unsigned int V_1 = V_11 -> V_1 ;
if ( F_4 ( V_6 , V_1 ) )
return - V_32 ;
V_3 = F_18 ( sizeof( struct V_2 ) , V_33 ) ;
if ( ( V_3 ) == NULL )
return - V_34 ;
V_30 = F_14 ( V_1 ) ;
if ( V_30 == NULL ) {
V_29 = - V_35 ;
goto V_36;
}
V_29 = F_19 ( & V_30 -> V_24 , & V_25 ) ;
if ( V_29 )
goto V_37;
V_3 -> V_1 = V_1 ;
F_4 ( V_6 , V_1 ) = V_3 ;
for ( V_15 = 0 ; V_27 [ V_15 ] . V_38 != V_39 ; V_15 ++ ) {
unsigned int V_22 = V_27 [ V_15 ] . V_38 ;
if ( V_22 == V_40 )
continue;
V_28 ++ ;
}
V_31 = V_28 * sizeof( int ) + V_28 * sizeof( V_41 ) ;
#ifdef F_20
V_31 += V_28 * V_28 * sizeof( int ) ;
#endif
V_3 -> V_21 = V_28 ;
V_3 -> V_7 = F_18 ( V_31 , V_33 ) ;
if ( ! V_3 -> V_7 ) {
V_29 = - V_34 ;
goto V_37;
}
V_3 -> V_17 = ( unsigned int * ) ( V_3 -> V_7 + V_28 ) ;
#ifdef F_20
V_3 -> V_20 = V_3 -> V_17 + V_28 ;
#endif
V_18 = 0 ;
for ( V_15 = 0 ; V_27 [ V_15 ] . V_38 != V_39 ; V_15 ++ ) {
unsigned int V_22 = V_27 [ V_15 ] . V_38 ;
if ( V_22 == V_40 )
continue;
if ( F_10 ( V_3 , V_22 ) == - 1 )
V_3 -> V_17 [ V_18 ++ ] = V_22 ;
}
V_3 -> V_16 = V_18 ;
F_3 ( & V_5 ) ;
V_3 -> V_9 = F_2 () ;
V_3 -> V_8 = F_10 ( V_3 , V_11 -> V_42 ) ;
F_5 ( & V_5 ) ;
F_16 ( V_30 ) ;
return 0 ;
V_37:
F_16 ( V_30 ) ;
V_36:
F_12 ( V_3 ) ;
F_4 ( V_6 , V_1 ) = NULL ;
return V_29 ;
}
static int F_21 ( struct V_43 * V_44 ,
unsigned long V_45 , void * V_30 )
{
int V_29 ;
struct V_10 * V_11 = V_30 ;
struct V_26 * V_27 ;
unsigned int V_1 = V_11 -> V_1 ;
if ( V_45 != V_46 )
return 0 ;
V_27 = F_22 ( V_1 ) ;
if ( ! V_27 )
return 0 ;
V_29 = F_17 ( V_11 , V_27 ) ;
if ( V_29 )
return V_29 ;
return 0 ;
}
static int F_23 ( struct V_43 * V_44 ,
unsigned long V_45 , void * V_30 )
{
struct V_47 * V_22 = V_30 ;
struct V_2 * V_3 ;
int V_48 , V_49 ;
if ( V_45 != V_50 )
return 0 ;
V_3 = F_4 ( V_6 , V_22 -> V_1 ) ;
if ( ! V_3 )
return 0 ;
V_48 = V_3 -> V_8 ;
V_49 = F_10 ( V_3 , V_22 -> V_51 ) ;
if ( V_48 == - 1 || V_49 == - 1 )
return 0 ;
F_1 ( V_22 -> V_1 ) ;
if ( V_48 == V_49 )
return 0 ;
F_3 ( & V_5 ) ;
V_3 -> V_8 = V_49 ;
#ifdef F_20
V_3 -> V_20 [ V_48 * V_3 -> V_21 + V_49 ] ++ ;
#endif
V_3 -> V_13 ++ ;
F_5 ( & V_5 ) ;
return 0 ;
}
static int T_2 F_24 ( struct V_43 * V_52 ,
unsigned long V_53 ,
void * V_54 )
{
unsigned int V_1 = ( unsigned long ) V_54 ;
switch ( V_53 ) {
case V_55 :
case V_56 :
F_25 ( V_1 ) ;
break;
case V_57 :
case V_58 :
F_13 ( V_1 ) ;
break;
case V_59 :
case V_60 :
F_11 ( V_1 ) ;
break;
}
return V_61 ;
}
static int T_3 F_26 ( void )
{
int V_29 ;
unsigned int V_1 ;
F_27 ( & V_5 ) ;
V_29 = F_28 ( & V_62 ,
V_63 ) ;
if ( V_29 )
return V_29 ;
V_29 = F_28 ( & V_64 ,
V_65 ) ;
if ( V_29 ) {
F_29 ( & V_62 ,
V_63 ) ;
return V_29 ;
}
F_30 ( & V_66 ) ;
F_31 (cpu) {
F_25 ( V_1 ) ;
}
return 0 ;
}
static void T_4 F_32 ( void )
{
unsigned int V_1 ;
F_29 ( & V_62 ,
V_63 ) ;
F_29 ( & V_64 ,
V_65 ) ;
F_33 ( & V_66 ) ;
F_31 (cpu) {
F_11 ( V_1 ) ;
F_13 ( V_1 ) ;
}
}
