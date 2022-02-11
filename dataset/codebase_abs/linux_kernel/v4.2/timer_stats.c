static void F_1 ( void )
{
V_1 = 0 ;
memset ( V_2 , 0 , sizeof( V_2 ) ) ;
memset ( V_3 , 0 , sizeof( V_3 ) ) ;
F_2 ( & V_4 , 0 ) ;
}
static struct V_5 * F_3 ( void )
{
if ( V_1 >= V_6 )
return NULL ;
return V_2 + V_1 ++ ;
}
static int F_4 ( struct V_5 * V_7 , struct V_5 * V_8 )
{
return V_7 -> V_9 == V_8 -> V_9 &&
V_7 -> V_10 == V_8 -> V_10 &&
V_7 -> V_11 == V_8 -> V_11 &&
V_7 -> V_12 == V_8 -> V_12 ;
}
static struct V_5 * F_5 ( struct V_5 * V_5 , char * V_13 )
{
struct V_5 * * V_14 , * V_15 , * V_16 ;
V_14 = F_6 ( V_5 ) ;
V_15 = * V_14 ;
while ( V_15 ) {
if ( F_4 ( V_15 , V_5 ) )
return V_15 ;
V_15 = V_15 -> V_17 ;
}
V_16 = NULL ;
V_15 = * V_14 ;
F_7 ( & V_18 ) ;
while ( V_15 ) {
if ( F_4 ( V_15 , V_5 ) )
goto V_19;
V_16 = V_15 ;
V_15 = V_15 -> V_17 ;
}
V_15 = F_3 () ;
if ( V_15 ) {
* V_15 = * V_5 ;
V_15 -> V_20 = 0 ;
V_15 -> V_17 = NULL ;
memcpy ( V_15 -> V_13 , V_13 , V_21 ) ;
F_8 () ;
if ( V_16 )
V_16 -> V_17 = V_15 ;
else
* V_14 = V_15 ;
}
V_19:
F_9 ( & V_18 ) ;
return V_15 ;
}
void F_10 ( void * V_9 , T_1 V_12 , void * V_22 ,
void * V_23 , char * V_13 , T_2 V_24 )
{
T_3 * V_25 ;
struct V_5 * V_5 , V_26 ;
unsigned long V_27 ;
if ( F_11 ( ! V_28 ) )
return;
V_25 = & F_12 ( V_29 , F_13 () ) ;
V_26 . V_9 = V_9 ;
V_26 . V_10 = V_22 ;
V_26 . V_11 = V_23 ;
V_26 . V_12 = V_12 ;
V_26 . V_27 = V_24 ;
F_14 ( V_25 , V_27 ) ;
if ( ! V_28 )
goto V_19;
V_5 = F_5 ( & V_26 , V_13 ) ;
if ( F_11 ( V_5 ) )
V_5 -> V_20 ++ ;
else
F_15 ( & V_4 ) ;
V_19:
F_16 ( V_25 , V_27 ) ;
}
static void F_17 ( struct V_30 * V_31 , unsigned long V_32 )
{
char V_33 [ V_34 ] ;
if ( F_18 ( V_32 , V_33 ) < 0 )
F_19 ( V_31 , L_1 , ( void * ) V_32 ) ;
else
F_19 ( V_31 , L_2 , V_33 ) ;
}
static int F_20 ( struct V_30 * V_31 , void * V_35 )
{
struct V_36 V_37 ;
struct V_5 * V_5 ;
unsigned long V_38 ;
long V_39 = 0 ;
T_4 time ;
int V_40 ;
F_21 ( & V_41 ) ;
if ( V_28 )
V_42 = F_22 () ;
time = F_23 ( V_42 , V_43 ) ;
V_37 = F_24 ( time ) ;
V_38 = V_37 . V_44 / 1000000 ;
F_25 ( V_31 , L_3 ) ;
F_19 ( V_31 , L_4 , V_37 . V_45 , V_38 ) ;
if ( F_26 ( & V_4 ) )
F_19 ( V_31 , L_5 , F_26 ( & V_4 ) ) ;
F_19 ( V_31 , L_6 , V_28 ? L_7 : L_8 ) ;
for ( V_40 = 0 ; V_40 < V_1 ; V_40 ++ ) {
V_5 = V_2 + V_40 ;
if ( V_5 -> V_27 & V_46 ) {
F_19 ( V_31 , L_9 ,
V_5 -> V_20 , V_5 -> V_12 , V_5 -> V_13 ) ;
} else {
F_19 ( V_31 , L_10 ,
V_5 -> V_20 , V_5 -> V_12 , V_5 -> V_13 ) ;
}
F_17 ( V_31 , ( unsigned long ) V_5 -> V_10 ) ;
F_25 ( V_31 , L_11 ) ;
F_17 ( V_31 , ( unsigned long ) V_5 -> V_11 ) ;
F_25 ( V_31 , L_12 ) ;
V_39 += V_5 -> V_20 ;
}
V_38 += V_37 . V_45 * 1000 ;
if ( ! V_38 )
V_38 = 1 ;
if ( V_39 && V_37 . V_45 )
F_19 ( V_31 , L_13 ,
V_39 , V_39 * 1000 / V_38 ,
( V_39 * 1000000 / V_38 ) % 1000 ) ;
else
F_19 ( V_31 , L_14 , V_39 ) ;
F_27 ( & V_41 ) ;
return 0 ;
}
static void F_28 ( void )
{
unsigned long V_27 ;
int V_47 ;
F_29 (cpu) {
T_3 * V_25 = & F_12 ( V_29 , V_47 ) ;
F_14 ( V_25 , V_27 ) ;
F_16 ( V_25 , V_27 ) ;
}
}
static T_5 F_30 ( struct V_48 * V_48 , const char T_6 * V_49 ,
T_7 V_20 , T_8 * V_50 )
{
char V_51 [ 2 ] ;
if ( V_20 != 2 || * V_50 )
return - V_52 ;
if ( F_31 ( V_51 , V_49 , V_20 ) )
return - V_53 ;
F_21 ( & V_41 ) ;
switch ( V_51 [ 0 ] ) {
case '0' :
if ( V_28 ) {
V_28 = 0 ;
V_42 = F_22 () ;
F_28 () ;
}
break;
case '1' :
if ( ! V_28 ) {
F_1 () ;
V_43 = F_22 () ;
F_8 () ;
V_28 = 1 ;
}
break;
default:
V_20 = - V_52 ;
}
F_27 ( & V_41 ) ;
return V_20 ;
}
static int F_32 ( struct V_54 * V_54 , struct V_48 * V_55 )
{
return F_33 ( V_55 , F_20 , NULL ) ;
}
void T_9 F_34 ( void )
{
int V_47 ;
F_35 (cpu)
F_36 ( & F_12 ( V_29 , V_47 ) ) ;
}
static int T_9 F_37 ( void )
{
struct V_56 * V_57 ;
V_57 = F_38 ( L_15 , 0644 , NULL , & V_58 ) ;
if ( ! V_57 )
return - V_59 ;
return 0 ;
}
