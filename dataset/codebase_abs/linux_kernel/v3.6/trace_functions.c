static int F_1 ( struct V_1 * V_2 )
{
V_3 = V_2 ;
V_2 -> V_4 = F_2 () ;
F_3 () ;
F_4 () ;
F_5 () ;
return 0 ;
}
static void F_6 ( struct V_1 * V_2 )
{
F_7 () ;
F_8 () ;
}
static void F_9 ( struct V_1 * V_2 )
{
F_10 ( V_2 ) ;
}
static void
F_11 ( unsigned long V_5 , unsigned long V_6 )
{
struct V_1 * V_2 = V_3 ;
struct V_7 * V_8 ;
unsigned long V_9 ;
long V_10 ;
int V_4 ;
int V_11 ;
if ( F_12 ( ! V_12 ) )
return;
V_11 = F_13 () ;
F_14 () ;
F_15 ( V_9 ) ;
V_4 = F_16 () ;
V_8 = V_2 -> V_8 [ V_4 ] ;
V_10 = F_17 ( & V_8 -> V_10 ) ;
if ( F_18 ( V_10 == 1 ) )
F_19 ( V_2 , V_5 , V_6 , V_9 , V_11 ) ;
F_20 ( & V_8 -> V_10 ) ;
F_21 () ;
}
static void
F_22 ( unsigned long V_5 , unsigned long V_6 )
{
struct V_1 * V_2 = V_3 ;
struct V_7 * V_8 ;
unsigned long V_9 ;
long V_10 ;
int V_4 ;
int V_11 ;
if ( F_12 ( ! V_12 ) )
return;
F_23 ( V_9 ) ;
V_4 = F_16 () ;
V_8 = V_2 -> V_8 [ V_4 ] ;
V_10 = F_17 ( & V_8 -> V_10 ) ;
if ( F_18 ( V_10 == 1 ) ) {
if ( F_12 ( V_13 . V_14 & V_15 ) )
F_24 ( V_5 , V_6 ) ;
V_11 = F_13 () ;
F_19 ( V_2 , V_5 , V_6 , V_9 , V_11 ) ;
}
F_20 ( & V_8 -> V_10 ) ;
F_25 ( V_9 ) ;
}
static void
F_26 ( unsigned long V_5 , unsigned long V_6 )
{
struct V_1 * V_2 = V_3 ;
struct V_7 * V_8 ;
unsigned long V_9 ;
long V_10 ;
int V_4 ;
int V_11 ;
if ( F_12 ( ! V_12 ) )
return;
F_23 ( V_9 ) ;
V_4 = F_16 () ;
V_8 = V_2 -> V_8 [ V_4 ] ;
V_10 = F_17 ( & V_8 -> V_10 ) ;
if ( F_18 ( V_10 == 1 ) ) {
V_11 = F_13 () ;
F_19 ( V_2 , V_5 , V_6 , V_9 , V_11 ) ;
F_27 ( V_2 , V_9 , 5 , V_11 ) ;
}
F_20 ( & V_8 -> V_10 ) ;
F_25 ( V_9 ) ;
}
static void F_5 ( void )
{
V_12 = 0 ;
if ( V_16 & V_17 )
V_18 . V_19 = F_11 ;
else
V_18 . V_19 = F_22 ;
if ( V_13 . V_14 & V_20 )
F_28 ( & V_21 ) ;
else
F_28 ( & V_18 ) ;
V_12 = 1 ;
}
static void F_7 ( void )
{
V_12 = 0 ;
if ( V_13 . V_14 & V_20 )
F_29 ( & V_21 ) ;
else
F_29 ( & V_18 ) ;
}
static int F_30 ( T_1 V_22 , T_1 V_23 , int V_24 )
{
switch ( V_23 ) {
case V_20 :
if ( ! ! V_24 == ! ! ( V_13 . V_14 & V_20 ) )
break;
if ( V_24 ) {
F_29 ( & V_18 ) ;
F_28 ( & V_21 ) ;
} else {
F_29 ( & V_21 ) ;
F_28 ( & V_18 ) ;
}
break;
case V_15 :
break;
default:
return - V_25 ;
}
return 0 ;
}
static void
F_31 ( unsigned long V_5 , unsigned long V_6 , void * * V_8 )
{
long * V_26 = ( long * ) V_8 ;
if ( F_32 () )
return;
if ( ! * V_26 )
return;
if ( * V_26 != - 1 )
( * V_26 ) -- ;
F_33 () ;
}
static void
F_34 ( unsigned long V_5 , unsigned long V_6 , void * * V_8 )
{
long * V_26 = ( long * ) V_8 ;
if ( ! F_32 () )
return;
if ( ! * V_26 )
return;
if ( * V_26 != - 1 )
( * V_26 ) -- ;
F_35 () ;
}
static int
F_36 ( struct V_27 * V_28 , unsigned long V_5 ,
struct V_29 * V_30 , void * V_8 )
{
long V_26 = ( long ) V_8 ;
F_37 ( V_28 , L_1 , ( void * ) V_5 ) ;
if ( V_30 == & V_31 )
F_37 ( V_28 , L_2 ) ;
else
F_37 ( V_28 , L_3 ) ;
if ( V_26 == - 1 )
F_37 ( V_28 , L_4 ) ;
else
F_37 ( V_28 , L_5 , V_26 ) ;
return 0 ;
}
static int
F_38 ( char * V_32 , char * V_33 , char * V_34 )
{
struct V_29 * V_30 ;
if ( strcmp ( V_33 , L_2 ) == 0 )
V_30 = & V_31 ;
else
V_30 = & V_35 ;
F_39 ( V_32 , V_30 ) ;
return 0 ;
}
static int
F_40 ( struct V_36 * V_37 ,
char * V_32 , char * V_33 , char * V_34 , int V_38 )
{
struct V_29 * V_30 ;
void * V_26 = ( void * ) - 1 ;
char * V_39 ;
int V_40 ;
if ( ! V_38 )
return - V_25 ;
if ( V_32 [ 0 ] == '!' )
return F_38 ( V_32 + 1 , V_33 , V_34 ) ;
if ( strcmp ( V_33 , L_2 ) == 0 )
V_30 = & V_31 ;
else
V_30 = & V_35 ;
if ( ! V_34 )
goto V_41;
V_39 = F_41 ( & V_34 , L_6 ) ;
if ( ! strlen ( V_39 ) )
goto V_41;
V_40 = F_42 ( V_39 , 0 , ( unsigned long * ) & V_26 ) ;
if ( V_40 )
return V_40 ;
V_41:
V_40 = F_43 ( V_32 , V_30 , V_26 ) ;
return V_40 < 0 ? V_40 : 0 ;
}
static int T_2 F_44 ( void )
{
int V_40 ;
V_40 = F_45 ( & V_42 ) ;
if ( V_40 )
return V_40 ;
V_40 = F_45 ( & V_43 ) ;
if ( V_40 )
F_46 ( & V_42 ) ;
return V_40 ;
}
static inline int F_44 ( void )
{
return 0 ;
}
static T_2 int F_47 ( void )
{
F_44 () ;
return F_48 ( & V_44 ) ;
}
