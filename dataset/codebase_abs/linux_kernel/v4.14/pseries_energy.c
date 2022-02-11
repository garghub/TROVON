static T_1 F_1 ( int V_1 )
{
struct V_2 * V_3 = NULL ;
const int * V_4 ;
int V_5 ;
int V_6 = 1 ;
T_1 V_7 = 0 ;
V_3 = F_2 ( L_1 ) ;
if ( V_3 == NULL )
goto V_8;
V_4 = F_3 ( V_3 , L_2 , NULL ) ;
if ( V_4 == NULL )
goto V_9;
V_5 = F_4 ( V_1 ) ;
F_5 ( V_5 > V_4 [ 0 ] ) ;
V_7 = V_4 [ V_5 + 1 ] ;
V_6 = 0 ;
V_9:
F_6 ( V_3 ) ;
V_8:
if ( V_6 )
F_7 ( V_10 L_3 , V_1 ) ;
return V_7 ;
}
static int F_8 ( T_1 V_11 )
{
struct V_2 * V_3 = NULL ;
const int * V_4 ;
int V_5 , V_1 = 0 ;
int V_6 = 1 ;
V_3 = F_2 ( L_1 ) ;
if ( V_3 == NULL )
goto V_8;
V_4 = F_3 ( V_3 , L_2 , NULL ) ;
if ( V_4 == NULL )
goto V_9;
for ( V_5 = 0 ; V_5 < V_4 [ 0 ] ; V_5 ++ ) {
if ( V_4 [ V_5 + 1 ] == V_11 )
break;
}
V_1 = F_9 ( V_5 ) ;
V_6 = 0 ;
V_9:
F_6 ( V_3 ) ;
V_8:
if ( V_6 )
F_7 ( V_10 L_4 , V_11 ) ;
return V_1 ;
}
static T_2 F_10 ( char * V_12 , int V_13 )
{
int V_6 , V_14 , V_5 , V_1 ;
unsigned long V_15 [ V_16 ] ;
unsigned long V_17 = 0 ;
T_1 * V_18 ;
char * V_19 = V_12 ;
V_18 = ( T_1 * ) F_11 ( V_20 ) ;
if ( ! V_18 )
return - V_21 ;
V_17 = V_22 ;
if ( V_13 )
V_17 |= V_23 ;
V_6 = F_12 ( V_24 , V_15 , V_17 , 0 , F_13 ( V_18 ) ,
0 , 0 , 0 , 0 , 0 , 0 ) ;
if ( V_6 != V_25 ) {
F_14 ( ( unsigned long ) V_18 ) ;
return - V_26 ;
}
V_14 = V_15 [ 0 ] ;
for ( V_5 = 0 ; V_5 < V_14 ; V_5 ++ ) {
V_1 = F_8 ( V_18 [ 2 * V_5 + 1 ] ) ;
if ( ( F_15 ( V_1 ) && ! V_13 ) ||
( ! F_15 ( V_1 ) && V_13 ) )
V_19 += sprintf ( V_19 , L_5 , V_1 ) ;
}
if ( V_19 > V_12 ) {
V_19 -- ;
V_19 += sprintf ( V_19 , L_6 ) ;
}
F_14 ( ( unsigned long ) V_18 ) ;
return V_19 - V_12 ;
}
static T_2 F_16 ( struct V_27 * V_28 ,
char * V_12 , int V_13 )
{
int V_6 ;
unsigned long V_15 [ V_16 ] ;
unsigned long V_17 = 0 ;
V_17 = V_29 ;
if ( V_13 )
V_17 |= V_23 ;
V_6 = F_12 ( V_24 , V_15 , V_17 ,
F_1 ( V_28 -> V_30 ) ,
0 , 0 , 0 , 0 , 0 , 0 , 0 ) ;
if ( V_6 != V_25 )
return - V_26 ;
return sprintf ( V_12 , L_7 , V_15 [ 1 ] >> 32 ) ;
}
static T_2 F_17 ( struct V_27 * V_28 ,
struct V_31 * V_32 , char * V_12 )
{
return F_10 ( V_12 , 1 ) ;
}
static T_2 F_18 ( struct V_27 * V_28 ,
struct V_31 * V_32 , char * V_12 )
{
return F_10 ( V_12 , 0 ) ;
}
static T_2 F_19 ( struct V_27 * V_28 ,
struct V_31 * V_32 , char * V_12 )
{
return F_16 ( V_28 , V_12 , 1 ) ;
}
static T_2 F_20 ( struct V_27 * V_28 ,
struct V_31 * V_32 , char * V_12 )
{
return F_16 ( V_28 , V_12 , 0 ) ;
}
static int T_3 F_21 ( void )
{
int V_1 , V_8 ;
struct V_27 * V_33 ;
if ( ! F_22 ( V_34 ) )
return 0 ;
V_8 = F_23 ( V_35 . V_36 ,
& V_37 ) ;
if ( ! V_8 )
V_8 = F_23 ( V_35 . V_36 ,
& V_38 ) ;
if ( V_8 )
return V_8 ;
F_24 (cpu) {
V_33 = F_25 ( V_1 ) ;
V_8 = F_23 ( V_33 ,
& V_39 ) ;
if ( V_8 )
break;
V_8 = F_23 ( V_33 ,
& V_40 ) ;
if ( V_8 )
break;
}
if ( V_8 )
return V_8 ;
V_41 = 1 ;
return 0 ;
}
static void T_4 F_26 ( void )
{
int V_1 ;
struct V_27 * V_33 ;
if ( ! V_41 )
return;
F_27 ( V_35 . V_36 , & V_37 ) ;
F_27 ( V_35 . V_36 , & V_38 ) ;
F_24 (cpu) {
V_33 = F_25 ( V_1 ) ;
F_28 ( & V_33 -> V_42 ,
& V_39 . V_32 ) ;
F_28 ( & V_33 -> V_42 ,
& V_40 . V_32 ) ;
}
}
