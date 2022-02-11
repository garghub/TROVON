void F_1 ( struct V_1 * V_2 )
{
int V_3 ;
F_2 ( & V_2 -> V_4 . V_5 ) ;
V_2 -> V_4 . V_6 = 0xDEAD ;
for ( V_3 = 0 ; V_3 < V_7 ; V_3 ++ ) {
V_2 -> V_4 . V_8 [ V_3 ] = 0 ;
V_2 -> V_4 . V_9 [ V_3 ] = 0 ;
V_2 -> V_4 . V_10 [ V_3 ] = 0xFFFFFFFF ;
V_2 -> V_4 . V_11 [ V_3 ] = 0 ;
V_2 -> V_4 . V_12 [ V_3 ] = 0 ;
}
V_2 -> V_4 . V_13 = 0 ;
V_2 -> V_4 . V_14 . V_15 = 0 ;
V_2 -> V_4 . V_16 . V_15 = 0 ;
F_3 ( & V_2 -> V_4 . V_5 ) ;
}
static void F_4 ( struct V_1 * V_2 , T_1 V_17 , int type )
{
T_1 V_18 ;
F_2 ( & V_2 -> V_4 . V_5 ) ;
V_2 -> V_4 . V_8 [ type ] ++ ;
V_18 = V_2 -> V_4 . V_11 [ type ] ;
V_2 -> V_4 . V_11 [ type ] += V_17 ;
if ( F_5 ( V_18 > V_2 -> V_4 . V_11 [ type ] ) ) {
F_6 ( V_19 L_1
L_2 ,
V_20 , V_18 , V_2 -> V_4 . V_11 [ type ] ,
type , V_2 -> V_4 . V_8 [ type ] ) ;
}
V_18 = V_2 -> V_4 . V_12 [ type ] ;
V_2 -> V_4 . V_12 [ type ] += ( V_17 * V_17 ) ;
if ( F_5 ( V_18 > V_2 -> V_4 . V_12 [ type ] ) ) {
F_6 ( V_19 L_3
L_2 ,
V_20 , V_18 ,
V_2 -> V_4 . V_12 [ type ] ,
type , V_2 -> V_4 . V_8 [ type ] ) ;
}
if ( F_5 ( V_17 < V_2 -> V_4 . V_10 [ type ] ) )
V_2 -> V_4 . V_10 [ type ] = V_17 ;
if ( F_5 ( V_17 > V_2 -> V_4 . V_9 [ type ] ) )
V_2 -> V_4 . V_9 [ type ] = V_17 ;
F_3 ( & V_2 -> V_4 . V_5 ) ;
}
void F_7 ( struct V_1 * V_2 )
{
T_1 exit = V_2 -> V_4 . V_13 ;
T_1 V_21 = V_2 -> V_4 . V_16 . V_15 ;
V_2 -> V_4 . V_13 = V_2 -> V_4 . V_14 . V_15 ;
if ( F_5 ( V_2 -> V_4 . V_6 == 0xDEAD || exit == 0 ) )
return;
F_4 ( V_2 , ( V_21 - exit ) , V_2 -> V_4 . V_6 ) ;
F_4 ( V_2 , ( V_2 -> V_4 . V_13 - V_21 ) ,
V_22 ) ;
}
static int F_8 ( struct V_23 * V_24 , void * V_25 )
{
struct V_1 * V_2 = V_24 -> V_25 ;
int V_3 ;
T_1 V_26 , V_27 , V_28 , V_29 ;
F_9 ( V_24 , L_4 , L_5 ) ;
for ( V_3 = 0 ; V_3 < V_7 ; V_3 ++ ) {
V_26 = V_2 -> V_4 . V_10 [ V_3 ] ;
F_10 ( V_26 , V_30 ) ;
V_27 = V_2 -> V_4 . V_9 [ V_3 ] ;
F_10 ( V_27 , V_30 ) ;
V_28 = V_2 -> V_4 . V_11 [ V_3 ] ;
F_10 ( V_28 , V_30 ) ;
V_29 = V_2 -> V_4 . V_12 [ V_3 ] ;
F_10 ( V_29 , V_30 ) ;
F_9 ( V_24 , L_6 ,
V_31 [ V_3 ] ,
V_2 -> V_4 . V_8 [ V_3 ] ,
V_26 ,
V_27 ,
V_28 ,
V_29 ) ;
}
return 0 ;
}
static T_2 F_11 ( struct V_32 * V_32 ,
const char T_3 * V_33 ,
T_4 V_34 , T_5 * V_35 )
{
int V_36 = - V_37 ;
char V_38 ;
if ( V_34 > 1 ) {
goto V_39;
}
if ( F_12 ( V_38 , V_33 ) ) {
V_36 = - V_40 ;
goto V_39;
}
if ( V_38 == 'c' ) {
struct V_23 * V_41 = V_32 -> V_42 ;
struct V_1 * V_2 = V_41 -> V_25 ;
F_2 ( & V_41 -> V_43 ) ;
F_1 ( V_2 ) ;
F_3 ( & V_41 -> V_43 ) ;
V_36 = V_34 ;
}
V_39:
return V_36 ;
}
static int F_13 ( struct V_44 * V_44 , struct V_32 * V_32 )
{
return F_14 ( V_32 , F_8 , V_44 -> V_45 ) ;
}
void F_15 ( struct V_1 * V_2 , unsigned int V_46 )
{
static char V_47 [ 50 ] ;
struct V_48 * V_49 ;
snprintf ( V_47 , sizeof( V_47 ) , L_7 ,
V_50 -> V_51 , V_46 ) ;
V_49 = F_16 ( V_47 , 0666 ,
V_52 , V_2 ,
& V_53 ) ;
if ( ! V_49 ) {
F_6 ( V_19 L_8 ,
V_20 , V_47 ) ;
return;
}
V_2 -> V_4 . V_54 = V_49 ;
}
void F_17 ( struct V_1 * V_2 )
{
if ( V_2 -> V_4 . V_54 ) {
F_18 ( V_2 -> V_4 . V_54 ) ;
V_2 -> V_4 . V_54 = NULL ;
}
}
