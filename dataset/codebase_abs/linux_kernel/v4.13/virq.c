void F_1 ( unsigned int V_1 , T_1 V_2 , struct V_3 * V_4 )
{
unsigned long V_5 ;
F_2 ( & V_6 , V_5 ) ;
V_7 [ V_1 ] . V_8 = V_2 ;
V_7 [ V_1 ] . V_9 = V_4 ;
F_3 ( & V_6 , V_5 ) ;
}
struct V_10 * F_4 ( unsigned int V_1 )
{
return V_7 + V_1 ;
}
int F_5 ( const char * V_11 , T_1 V_8 )
{
struct V_10 * V_12 ;
struct V_3 * V_4 ;
int V_1 = - 1 ;
F_6 (d, &intc_list, list) {
int V_13 ;
if ( strcmp ( V_4 -> V_14 . V_15 , V_11 ) != 0 )
continue;
V_13 = F_7 ( & V_4 -> V_16 , V_8 ,
V_17 ) ;
if ( F_8 ( V_13 ) )
break;
V_12 = F_9 ( & V_4 -> V_16 , V_8 ) ;
if ( V_12 ) {
V_1 = V_12 - V_7 ;
break;
}
}
return V_1 ;
}
static int F_10 ( unsigned int V_1 , unsigned int V_18 )
{
struct V_19 * V_20 ;
struct V_19 * * V_21 = NULL ;
F_11 (entry, irq_get_handler_data(irq)) {
if ( V_20 -> V_1 == V_18 )
return 0 ;
V_21 = & V_20 -> V_22 ;
}
V_20 = F_12 ( sizeof( struct V_19 ) , V_23 ) ;
if ( ! V_20 )
return - V_24 ;
V_20 -> V_1 = V_18 ;
if ( V_21 )
* V_21 = V_20 ;
else
F_13 ( V_1 , V_20 ) ;
return 0 ;
}
static void F_14 ( struct V_25 * V_9 )
{
unsigned int V_1 = F_15 ( V_9 ) ;
struct V_26 * V_27 = F_16 ( V_9 ) ;
struct V_28 * V_14 = F_17 ( V_27 ) ;
struct V_19 * V_20 , * V_29 = F_18 ( V_27 ) ;
struct V_3 * V_4 = F_19 ( V_1 ) ;
V_14 -> V_30 ( V_27 ) ;
F_11 (entry, vlist) {
unsigned long V_31 , V_32 ;
struct V_25 * V_33 = F_20 ( V_20 -> V_1 ) ;
if ( V_33 ) {
V_32 = ( unsigned long ) F_21 ( V_33 ) ;
V_31 = F_22 ( V_4 , F_23 ( V_32 ) , 0 ) ;
if ( V_34 [ F_24 ( V_32 ) ] ( V_31 , V_32 , 0 ) )
F_25 ( V_33 ) ;
}
}
V_14 -> V_35 ( V_27 ) ;
}
static unsigned long T_2 F_26 ( struct V_36 * V_37 ,
struct V_3 * V_4 ,
unsigned int V_38 )
{
unsigned int V_39 = V_40 + ( V_37 -> V_41 >> 3 ) - 1 ;
return F_27 ( V_39 , V_42 , F_28 ( V_4 , V_37 -> V_43 ) ,
0 , 1 , ( V_37 -> V_41 - 1 ) - V_38 ) ;
}
static void T_2 F_29 ( struct V_44 * V_9 ,
struct V_3 * V_4 ,
struct V_36 * V_37 )
{
struct V_10 * V_45 ;
unsigned int V_46 ;
unsigned long V_5 ;
int V_47 ;
V_45 = F_9 ( & V_4 -> V_16 , V_37 -> V_48 ) ;
if ( ! V_45 ) {
F_30 ( 1 ) ;
return;
}
V_46 = V_45 - V_7 ;
F_2 ( & V_4 -> V_49 , V_5 ) ;
for ( V_47 = 0 ; V_47 < F_31 ( V_37 -> V_50 ) ; V_47 ++ ) {
struct V_51 * V_20 ;
int V_52 ;
if ( ! V_37 -> V_50 [ V_47 ] )
continue;
V_20 = F_32 ( sizeof( * V_20 ) , V_53 ) ;
if ( ! V_20 )
break;
V_20 -> V_46 = V_46 ;
V_20 -> V_8 = V_37 -> V_50 [ V_47 ] ;
V_20 -> V_32 = F_26 ( V_37 , V_4 , V_47 ) ;
V_52 = F_33 ( & V_4 -> V_16 , V_20 -> V_8 , V_20 ) ;
if ( F_8 ( V_52 < 0 ) )
break;
F_34 ( & V_4 -> V_16 , V_20 -> V_8 ,
V_17 ) ;
}
F_3 ( & V_4 -> V_49 , V_5 ) ;
}
void T_2 F_35 ( struct V_44 * V_9 , struct V_3 * V_4 )
{
int V_47 ;
if ( ! V_9 -> V_54 . V_55 )
return;
for ( V_47 = 0 ; V_47 < V_9 -> V_54 . V_56 ; V_47 ++ )
F_29 ( V_9 , V_4 , V_9 -> V_54 . V_55 + V_47 ) ;
}
static void T_2 F_36 ( struct V_3 * V_4 )
{
struct V_51 * V_57 [ 32 ] ;
unsigned long V_5 ;
unsigned int V_58 ;
int V_47 ;
F_2 ( & V_4 -> V_49 , V_5 ) ;
V_59:
V_58 = F_37 ( & V_4 -> V_16 ,
( void * * * ) V_57 , 0 , F_31 ( V_57 ) ,
V_17 ) ;
for ( V_47 = 0 ; V_47 < V_58 ; V_47 ++ ) {
struct V_51 * V_20 ;
int V_1 ;
V_20 = F_38 ( ( void * * ) V_57 [ V_47 ] ) ;
if ( F_8 ( ! V_20 ) )
continue;
if ( F_39 ( V_20 ) )
goto V_59;
V_1 = F_40 ( F_41 () ) ;
if ( F_8 ( V_1 < 0 ) ) {
F_42 ( L_1 ) ;
break;
}
F_43 ( V_1 ) ;
F_44 ( L_2 ,
V_1 , V_20 -> V_46 ) ;
F_1 ( V_1 , V_20 -> V_8 , V_4 ) ;
F_45 ( V_1 , F_46 ( V_20 -> V_46 ) ,
V_60 , L_3 ) ;
F_47 ( V_1 , F_48 ( V_20 -> V_46 ) ) ;
F_13 ( V_1 , ( void * ) V_20 -> V_32 ) ;
F_49 ( V_1 ) ;
F_10 ( V_20 -> V_46 , V_1 ) ;
F_50 ( V_20 -> V_46 , F_14 ) ;
F_51 ( & V_4 -> V_16 , V_20 -> V_8 ,
V_17 ) ;
F_52 ( & V_4 -> V_16 , ( void * * ) V_57 [ V_47 ] ,
& V_7 [ V_1 ] ) ;
}
F_3 ( & V_4 -> V_49 , V_5 ) ;
}
void T_2 F_53 ( void )
{
struct V_3 * V_4 ;
F_6 (d, &intc_list, list)
if ( F_54 ( & V_4 -> V_16 , V_17 ) )
F_36 ( V_4 ) ;
}
