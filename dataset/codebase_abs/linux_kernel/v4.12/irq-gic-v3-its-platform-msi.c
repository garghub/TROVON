static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
T_1 * V_5 )
{
int V_6 , V_7 = 0 ;
do {
struct V_8 args ;
V_6 = F_2 ( V_4 -> V_9 ,
L_1 , L_2 ,
V_7 , & args ) ;
if ( args . V_10 == F_3 ( V_2 ) ) {
if ( F_4 ( args . V_11 != 1 ) )
return - V_12 ;
* V_5 = args . args [ 0 ] ;
break;
}
} while ( ! V_6 );
return V_6 ;
}
int __weak F_5 ( struct V_3 * V_4 , T_1 * V_5 )
{
return - 1 ;
}
static int F_6 ( struct V_1 * V_2 , struct V_3 * V_4 ,
int V_13 , T_2 * V_14 )
{
struct V_15 * V_16 ;
T_1 V_5 ;
int V_6 ;
V_16 = F_7 ( V_2 -> V_17 ) ;
if ( V_4 -> V_9 )
V_6 = F_1 ( V_2 , V_4 , & V_5 ) ;
else
V_6 = F_5 ( V_4 , & V_5 ) ;
if ( V_6 )
return V_6 ;
V_14 -> V_18 [ 0 ] . V_19 = V_5 ;
return V_16 -> V_20 -> V_21 ( V_2 -> V_17 ,
V_4 , V_13 , V_14 ) ;
}
static int T_3 F_8 ( struct V_22 * V_23 ,
const char * V_24 )
{
struct V_1 * V_17 ;
V_17 = F_9 ( V_23 , V_25 ) ;
if ( ! V_17 || ! F_7 ( V_17 ) ) {
F_10 ( L_3 , V_24 ) ;
return - V_26 ;
}
if ( ! F_11 ( V_23 , & V_27 ,
V_17 ) ) {
F_10 ( L_4 , V_24 ) ;
return - V_26 ;
}
F_12 ( L_5 , V_24 ) ;
return 0 ;
}
static int T_3
F_13 ( struct V_28 * V_29 ,
const unsigned long V_30 )
{
struct V_31 * V_32 ;
struct V_22 * V_33 ;
const char * V_34 ;
int V_35 = - V_26 ;
V_32 = (struct V_31 * ) V_29 ;
V_34 = F_14 ( V_36 , L_6 ,
( long ) V_32 -> V_37 ) ;
V_33 = F_15 ( V_32 -> V_38 ) ;
if ( ! V_33 ) {
F_10 ( L_7 , V_34 ) ;
goto V_39;
}
V_35 = F_8 ( V_33 , V_34 ) ;
V_39:
F_16 ( V_34 ) ;
return V_35 ;
}
static void T_3 F_17 ( void )
{
F_18 ( V_40 ,
F_13 , 0 ) ;
}
static inline void F_17 ( void ) { }
static void T_3 F_19 ( void )
{
struct V_41 * V_10 ;
for ( V_10 = F_20 ( NULL , V_42 ) ; V_10 ;
V_10 = F_20 ( V_10 , V_42 ) ) {
if ( ! F_21 ( V_10 , L_8 ) )
continue;
F_8 ( F_22 ( V_10 ) , V_10 -> V_43 ) ;
}
}
static int T_3 F_23 ( void )
{
F_19 () ;
F_17 () ;
return 0 ;
}
