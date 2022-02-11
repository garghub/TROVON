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
struct V_19 * * V_20 , * V_21 ;
struct V_22 * V_23 = F_11 ( V_1 ) ;
V_20 = (struct V_19 * * ) & V_23 -> V_24 ;
F_12 (entry, data->handler_data) {
if ( V_21 -> V_1 == V_18 )
return 0 ;
V_20 = & V_21 -> V_25 ;
}
V_21 = F_13 ( sizeof( struct V_19 ) , V_26 ) ;
if ( ! V_21 ) {
F_14 ( L_1 , V_18 ) ;
return - V_27 ;
}
V_21 -> V_1 = V_18 ;
* V_20 = V_21 ;
return 0 ;
}
static void F_15 ( unsigned int V_1 , struct V_28 * V_9 )
{
struct V_22 * V_23 = F_11 ( V_1 ) ;
struct V_29 * V_14 = F_16 ( V_23 ) ;
struct V_19 * V_21 , * V_30 = F_17 ( V_23 ) ;
struct V_3 * V_4 = F_18 ( V_1 ) ;
V_14 -> V_31 ( V_23 ) ;
F_12 (entry, vlist) {
unsigned long V_32 , V_33 ;
V_33 = ( unsigned long ) F_19 ( V_21 -> V_1 ) ;
V_32 = F_20 ( V_4 , F_21 ( V_33 ) , 0 ) ;
if ( V_34 [ F_22 ( V_33 ) ] ( V_32 , V_33 , 0 ) )
F_23 ( V_21 -> V_1 ) ;
}
V_14 -> V_35 ( V_23 ) ;
}
static unsigned long T_2 F_24 ( struct V_36 * V_37 ,
struct V_3 * V_4 ,
unsigned int V_38 )
{
unsigned int V_39 = V_40 + ( V_37 -> V_41 >> 3 ) - 1 ;
return F_25 ( V_39 , V_42 , F_26 ( V_4 , V_37 -> V_43 ) ,
0 , 1 , ( V_37 -> V_41 - 1 ) - V_38 ) ;
}
static void T_2 F_27 ( struct V_44 * V_9 ,
struct V_3 * V_4 ,
struct V_36 * V_37 )
{
struct V_10 * V_45 ;
unsigned int V_46 ;
unsigned long V_5 ;
int V_47 ;
V_45 = F_9 ( & V_4 -> V_16 , V_37 -> V_48 ) ;
if ( ! V_45 ) {
F_28 ( 1 ) ;
return;
}
V_46 = V_45 - V_7 ;
F_2 ( & V_4 -> V_49 , V_5 ) ;
for ( V_47 = 0 ; V_47 < F_29 ( V_37 -> V_50 ) ; V_47 ++ ) {
struct V_51 * V_21 ;
int V_52 ;
if ( ! V_37 -> V_50 [ V_47 ] )
continue;
V_21 = F_30 ( sizeof( * V_21 ) , V_53 ) ;
if ( ! V_21 )
break;
V_21 -> V_46 = V_46 ;
V_21 -> V_8 = V_37 -> V_50 [ V_47 ] ;
V_21 -> V_33 = F_24 ( V_37 , V_4 , V_47 ) ;
V_52 = F_31 ( & V_4 -> V_16 , V_21 -> V_8 , V_21 ) ;
if ( F_8 ( V_52 < 0 ) )
break;
F_32 ( & V_4 -> V_16 , V_21 -> V_8 ,
V_17 ) ;
}
F_3 ( & V_4 -> V_49 , V_5 ) ;
}
void T_2 F_33 ( struct V_44 * V_9 , struct V_3 * V_4 )
{
int V_47 ;
if ( ! V_9 -> V_54 . V_55 )
return;
for ( V_47 = 0 ; V_47 < V_9 -> V_54 . V_56 ; V_47 ++ )
F_27 ( V_9 , V_4 , V_9 -> V_54 . V_55 + V_47 ) ;
}
static void T_2 F_34 ( struct V_3 * V_4 )
{
struct V_51 * V_57 [ 32 ] ;
unsigned long V_5 ;
unsigned int V_58 ;
int V_47 ;
F_2 ( & V_4 -> V_49 , V_5 ) ;
V_59:
V_58 = F_35 ( & V_4 -> V_16 ,
( void * * * ) V_57 , 0 , F_29 ( V_57 ) ,
V_17 ) ;
for ( V_47 = 0 ; V_47 < V_58 ; V_47 ++ ) {
struct V_51 * V_21 ;
int V_1 ;
V_21 = F_36 ( ( void * * ) V_57 [ V_47 ] ) ;
if ( F_8 ( ! V_21 ) )
continue;
if ( F_37 ( V_21 ) )
goto V_59;
V_1 = F_38 () ;
if ( F_8 ( V_1 < 0 ) ) {
F_14 ( L_2 ) ;
break;
}
F_39 ( L_3 ,
V_1 , V_21 -> V_46 ) ;
F_1 ( V_1 , V_21 -> V_8 , V_4 ) ;
F_40 ( V_1 , F_41 ( V_21 -> V_46 ) ,
V_60 , L_4 ) ;
F_42 ( V_1 , F_43 ( V_21 -> V_46 ) ) ;
F_44 ( V_1 , ( void * ) V_21 -> V_33 ) ;
F_45 ( V_1 ) ;
F_46 ( V_21 -> V_46 , F_15 ) ;
F_10 ( V_21 -> V_46 , V_1 ) ;
F_47 ( & V_4 -> V_16 , V_21 -> V_8 ,
V_17 ) ;
F_48 ( ( void * * ) V_57 [ V_47 ] ,
& V_7 [ V_1 ] ) ;
}
F_3 ( & V_4 -> V_49 , V_5 ) ;
}
void T_2 F_49 ( void )
{
struct V_3 * V_4 ;
F_6 (d, &intc_list, list)
if ( F_50 ( & V_4 -> V_16 , V_17 ) )
F_34 ( V_4 ) ;
}
