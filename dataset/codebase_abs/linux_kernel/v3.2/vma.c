static void T_1 F_1 ( void * V_1 , T_2 V_2 )
{
T_3 * V_3 = V_1 ;
T_4 * V_4 , * V_5 = 0 ;
char * V_6 ;
void * V_7 ;
int V_8 ;
F_2 ( V_2 < sizeof( T_3 ) ) ;
F_2 ( memcmp ( V_3 -> V_9 , V_10 , V_11 ) != 0 ) ;
V_4 = ( void * ) V_3 + V_3 -> V_12 ;
V_6 = ( void * ) V_3 + V_4 [ V_3 -> V_13 ] . V_14 ;
for ( V_8 = 1 ; V_8 < V_3 -> V_15 ; V_8 ++ ) {
T_4 * V_16 = & V_4 [ V_8 ] ;
if ( ! strcmp ( V_6 + V_16 -> V_17 , L_1 ) ) {
V_5 = V_16 ;
goto V_18;
}
}
F_3 ( L_2 ) ;
return;
V_18:
V_7 = ( void * ) V_3 + V_5 -> V_14 ;
F_4 ( V_7 , V_7 + V_5 -> V_19 ) ;
}
static int T_1 F_5 ( void )
{
int V_20 = ( V_21 - V_22 + V_23 - 1 ) / V_23 ;
int V_8 ;
F_1 ( V_22 , V_21 - V_22 ) ;
V_24 = V_20 << V_25 ;
for ( V_8 = 0 ; V_8 < V_20 ; V_8 ++ )
V_26 [ V_8 ] = F_6 ( V_22 + V_8 * V_23 ) ;
return 0 ;
}
static unsigned long F_7 ( unsigned long V_27 , unsigned V_2 )
{
unsigned long V_28 , V_29 ;
unsigned V_30 ;
V_29 = ( V_27 + V_31 - 1 ) & V_32 ;
if ( V_29 >= V_33 )
V_29 = V_33 ;
V_29 -= V_2 ;
V_30 = F_8 () & ( V_34 - 1 ) ;
V_28 = V_27 + ( V_30 << V_25 ) ;
if ( V_28 >= V_29 )
V_28 = V_29 ;
V_28 = F_9 ( V_28 ) ;
V_28 = F_10 ( V_28 , NULL , V_35 ) ;
return V_28 ;
}
int F_11 ( struct V_36 * V_37 , int V_38 )
{
struct V_39 * V_40 = V_41 -> V_40 ;
unsigned long V_28 ;
int V_42 ;
if ( ! V_43 )
return 0 ;
F_12 ( & V_40 -> V_44 ) ;
V_28 = F_7 ( V_40 -> V_45 , V_24 ) ;
V_28 = F_13 ( NULL , V_28 , V_24 , 0 , 0 ) ;
if ( F_14 ( V_28 ) ) {
V_42 = V_28 ;
goto V_46;
}
V_41 -> V_40 -> V_47 . V_1 = ( void * ) V_28 ;
V_42 = F_15 ( V_40 , V_28 , V_24 ,
V_48 | V_49 |
V_50 | V_51 | V_52 |
V_53 ,
V_26 ) ;
if ( V_42 ) {
V_41 -> V_40 -> V_47 . V_1 = NULL ;
goto V_46;
}
V_46:
F_16 ( & V_40 -> V_44 ) ;
return V_42 ;
}
static T_1 int F_17 ( char * V_54 )
{
V_43 = F_18 ( V_54 , NULL , 0 ) ;
return 0 ;
}
