static int F_1 ( void )
{
struct V_1 * V_2 = NULL ;
const char * V_3 , * V_4 ;
int V_5 ;
int V_6 = 0 ;
V_2 = F_2 ( L_1 ) ;
if ( ! V_2 )
return 0 ;
V_3 = F_3 ( V_2 , L_2 , & V_5 ) ;
if ( ! V_3 ) {
F_4 ( V_2 ) ;
return 0 ;
}
for ( V_4 = V_3 ; V_4 < V_3 + V_5 ; V_4 += strlen ( V_4 ) + 1 ) {
if ( ! strncmp ( L_3 , V_4 , 19 ) ) {
V_6 = 1 ;
break;
}
}
F_4 ( V_2 ) ;
return V_6 ;
}
static T_1 F_5 ( int V_7 )
{
struct V_1 * V_8 = NULL ;
const int * V_9 ;
int V_10 ;
int V_6 = 1 ;
T_1 V_11 = 0 ;
V_8 = F_2 ( L_4 ) ;
if ( V_8 == NULL )
goto V_12;
V_9 = F_3 ( V_8 , L_5 , NULL ) ;
if ( V_9 == NULL )
goto V_13;
V_10 = F_6 ( V_7 ) ;
F_7 ( V_10 > V_9 [ 0 ] ) ;
V_11 = V_9 [ V_10 + 1 ] ;
V_6 = 0 ;
V_13:
F_4 ( V_8 ) ;
V_12:
if ( V_6 )
F_8 ( V_14 L_6 , V_7 ) ;
return V_11 ;
}
static int F_9 ( T_1 V_15 )
{
struct V_1 * V_8 = NULL ;
const int * V_9 ;
int V_10 , V_7 = 0 ;
int V_6 = 1 ;
V_8 = F_2 ( L_4 ) ;
if ( V_8 == NULL )
goto V_12;
V_9 = F_3 ( V_8 , L_5 , NULL ) ;
if ( V_9 == NULL )
goto V_13;
for ( V_10 = 0 ; V_10 < V_9 [ 0 ] ; V_10 ++ ) {
if ( V_9 [ V_10 + 1 ] == V_15 )
break;
}
V_7 = F_10 ( V_10 ) ;
V_6 = 0 ;
V_13:
F_4 ( V_8 ) ;
V_12:
if ( V_6 )
F_8 ( V_14 L_7 , V_15 ) ;
return V_7 ;
}
static T_2 F_11 ( char * V_16 , int V_17 )
{
int V_6 , V_18 , V_10 , V_7 ;
unsigned long V_19 [ V_20 ] ;
unsigned long V_21 = 0 ;
T_1 * V_22 ;
char * V_4 = V_16 ;
V_22 = ( T_1 * ) F_12 ( V_23 ) ;
if ( ! V_22 )
return - V_24 ;
V_21 = V_25 ;
if ( V_17 )
V_21 |= V_26 ;
V_6 = F_13 ( V_27 , V_19 , V_21 , 0 , F_14 ( V_22 ) ,
0 , 0 , 0 , 0 , 0 , 0 ) ;
if ( V_6 != V_28 ) {
F_15 ( ( unsigned long ) V_22 ) ;
return - V_29 ;
}
V_18 = V_19 [ 0 ] ;
for ( V_10 = 0 ; V_10 < V_18 ; V_10 ++ ) {
V_7 = F_9 ( V_22 [ 2 * V_10 + 1 ] ) ;
if ( ( F_16 ( V_7 ) && ! V_17 ) ||
( ! F_16 ( V_7 ) && V_17 ) )
V_4 += sprintf ( V_4 , L_8 , V_7 ) ;
}
if ( V_4 > V_16 ) {
V_4 -- ;
V_4 += sprintf ( V_4 , L_9 ) ;
}
F_15 ( ( unsigned long ) V_22 ) ;
return V_4 - V_16 ;
}
static T_2 F_17 ( struct V_30 * V_31 ,
char * V_16 , int V_17 )
{
int V_6 ;
unsigned long V_19 [ V_20 ] ;
unsigned long V_21 = 0 ;
V_21 = V_32 ;
if ( V_17 )
V_21 |= V_26 ;
V_6 = F_13 ( V_27 , V_19 , V_21 ,
F_5 ( V_31 -> V_33 ) ,
0 , 0 , 0 , 0 , 0 , 0 , 0 ) ;
if ( V_6 != V_28 )
return - V_29 ;
return sprintf ( V_16 , L_10 , V_19 [ 1 ] >> 32 ) ;
}
static T_2 F_18 ( struct V_34 * V_35 ,
struct V_36 * V_37 , char * V_16 )
{
return F_11 ( V_16 , 1 ) ;
}
static T_2 F_19 ( struct V_34 * V_35 ,
struct V_36 * V_37 , char * V_16 )
{
return F_11 ( V_16 , 0 ) ;
}
static T_2 F_20 ( struct V_30 * V_31 ,
struct V_38 * V_37 , char * V_16 )
{
return F_17 ( V_31 , V_16 , 1 ) ;
}
static T_2 F_21 ( struct V_30 * V_31 ,
struct V_38 * V_37 , char * V_16 )
{
return F_17 ( V_31 , V_16 , 0 ) ;
}
static int T_3 F_22 ( void )
{
int V_7 , V_12 ;
struct V_30 * V_39 ;
if ( ! F_1 () ) {
F_8 ( V_40 L_11 ) ;
return 0 ;
}
V_12 = F_23 ( & V_41 . V_42 . V_43 ,
& V_44 . V_37 ) ;
if ( ! V_12 )
V_12 = F_23 ( & V_41 . V_42 . V_43 ,
& V_45 . V_37 ) ;
if ( V_12 )
return V_12 ;
F_24 (cpu) {
V_39 = F_25 ( V_7 ) ;
V_12 = F_23 ( & V_39 -> V_43 ,
& V_46 . V_37 ) ;
if ( V_12 )
break;
V_12 = F_23 ( & V_39 -> V_43 ,
& V_47 . V_37 ) ;
if ( V_12 )
break;
}
if ( V_12 )
return V_12 ;
V_48 = 1 ;
return 0 ;
}
static void T_4 F_26 ( void )
{
int V_7 ;
struct V_30 * V_39 ;
if ( ! V_48 )
return;
F_27 ( & V_41 . V_42 . V_43 ,
& V_44 . V_37 ) ;
F_27 ( & V_41 . V_42 . V_43 ,
& V_45 . V_37 ) ;
F_24 (cpu) {
V_39 = F_25 ( V_7 ) ;
F_27 ( & V_39 -> V_43 ,
& V_46 . V_37 ) ;
F_27 ( & V_39 -> V_43 ,
& V_47 . V_37 ) ;
}
}
