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
static void T_1 F_5 ( void * V_1 , T_2 V_2 )
{
T_5 * V_3 = V_1 ;
T_6 * V_4 , * V_5 = 0 ;
char * V_6 ;
void * V_7 ;
int V_8 ;
F_2 ( V_2 < sizeof( T_5 ) ) ;
F_2 ( memcmp ( V_3 -> V_9 , V_10 , V_11 ) != 0 ) ;
V_4 = ( void * ) V_3 + V_3 -> V_12 ;
V_6 = ( void * ) V_3 + V_4 [ V_3 -> V_13 ] . V_14 ;
for ( V_8 = 1 ; V_8 < V_3 -> V_15 ; V_8 ++ ) {
T_6 * V_16 = & V_4 [ V_8 ] ;
if ( ! strcmp ( V_6 + V_16 -> V_17 , L_1 ) ) {
V_5 = V_16 ;
goto V_18;
}
}
F_3 ( L_3 ) ;
return;
V_18:
V_7 = ( void * ) V_3 + V_5 -> V_14 ;
F_4 ( V_7 , V_7 + V_5 -> V_19 ) ;
}
static int T_1 F_6 ( void )
{
int V_20 = ( V_21 - V_22 + V_23 - 1 ) / V_23 ;
int V_8 ;
F_5 ( V_22 , V_21 - V_22 ) ;
V_24 = V_20 << V_25 ;
for ( V_8 = 0 ; V_8 < V_20 ; V_8 ++ )
V_26 [ V_8 ] = F_7 ( V_22 + V_8 * V_23 ) ;
#ifdef F_8
F_1 ( V_27 , V_28 - V_27 ) ;
V_20 = ( V_28 - V_27 + V_23 - 1 ) / V_23 ;
V_29 = V_20 << V_25 ;
for ( V_8 = 0 ; V_8 < V_20 ; V_8 ++ )
V_30 [ V_8 ] = F_7 ( V_27 + V_8 * V_23 ) ;
#endif
return 0 ;
}
static unsigned long F_9 ( unsigned long V_31 , unsigned V_2 )
{
unsigned long V_32 , V_33 ;
unsigned V_34 ;
V_33 = ( V_31 + V_35 - 1 ) & V_36 ;
if ( V_33 >= V_37 )
V_33 = V_37 ;
V_33 -= V_2 ;
V_34 = F_10 () & ( V_38 - 1 ) ;
V_32 = V_31 + ( V_34 << V_25 ) ;
if ( V_32 >= V_33 )
V_32 = V_33 ;
V_32 = F_11 ( V_32 ) ;
V_32 = F_12 ( V_32 , NULL , V_39 ) ;
return V_32 ;
}
static int F_13 ( struct V_40 * V_41 ,
int V_42 ,
struct V_43 * * V_44 ,
unsigned V_45 )
{
struct V_46 * V_47 = V_48 -> V_47 ;
unsigned long V_32 ;
int V_49 ;
if ( ! V_50 )
return 0 ;
F_14 ( & V_47 -> V_51 ) ;
V_32 = F_9 ( V_47 -> V_52 , V_45 ) ;
V_32 = F_15 ( NULL , V_32 , V_45 , 0 , 0 ) ;
if ( F_16 ( V_32 ) ) {
V_49 = V_32 ;
goto V_53;
}
V_48 -> V_47 -> V_54 . V_1 = ( void * ) V_32 ;
V_49 = F_17 ( V_47 , V_32 , V_45 ,
V_55 | V_56 |
V_57 | V_58 | V_59 ,
V_44 ) ;
if ( V_49 ) {
V_48 -> V_47 -> V_54 . V_1 = NULL ;
goto V_53;
}
V_53:
F_18 ( & V_47 -> V_51 ) ;
return V_49 ;
}
int F_19 ( struct V_40 * V_41 , int V_42 )
{
return F_13 ( V_41 , V_42 , V_26 ,
V_24 ) ;
}
int F_20 ( struct V_40 * V_41 , int V_42 )
{
return F_13 ( V_41 , V_42 , V_30 ,
V_29 ) ;
}
static T_1 int F_21 ( char * V_60 )
{
V_50 = F_22 ( V_60 , NULL , 0 ) ;
return 0 ;
}
