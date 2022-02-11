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
F_5 ( V_17 , V_19 ) ;
if ( F_6 ( V_17 > 0xFFFFFFFF ) ) {
F_7 ( V_20 L_1
L_2 ,
V_21 , V_17 , type ,
V_2 -> V_4 . V_8 [ type ] ) ;
return;
}
F_2 ( & V_2 -> V_4 . V_5 ) ;
V_2 -> V_4 . V_8 [ type ] ++ ;
V_18 = V_2 -> V_4 . V_11 [ type ] ;
V_2 -> V_4 . V_11 [ type ] += V_17 ;
if ( F_6 ( V_18 > V_2 -> V_4 . V_11 [ type ] ) ) {
F_7 ( V_20 L_3
L_4 ,
V_21 , V_18 , V_2 -> V_4 . V_11 [ type ] ,
type , V_2 -> V_4 . V_8 [ type ] ) ;
}
V_18 = V_2 -> V_4 . V_12 [ type ] ;
V_2 -> V_4 . V_12 [ type ] += ( V_17 * V_17 ) ;
if ( F_6 ( V_18 > V_2 -> V_4 . V_12 [ type ] ) ) {
F_7 ( V_20 L_5
L_4 ,
V_21 , V_18 ,
V_2 -> V_4 . V_12 [ type ] ,
type , V_2 -> V_4 . V_8 [ type ] ) ;
}
if ( F_6 ( V_17 < V_2 -> V_4 . V_10 [ type ] ) )
V_2 -> V_4 . V_10 [ type ] = V_17 ;
if ( F_6 ( V_17 > V_2 -> V_4 . V_9 [ type ] ) )
V_2 -> V_4 . V_9 [ type ] = V_17 ;
F_3 ( & V_2 -> V_4 . V_5 ) ;
}
void F_8 ( struct V_1 * V_2 )
{
T_1 exit = V_2 -> V_4 . V_13 ;
T_1 V_22 = V_2 -> V_4 . V_16 . V_15 ;
V_2 -> V_4 . V_13 = V_2 -> V_4 . V_14 . V_15 ;
if ( F_6 ( V_2 -> V_4 . V_6 == 0xDEAD || exit == 0 ) )
return;
F_4 ( V_2 , ( V_22 - exit ) , V_2 -> V_4 . V_6 ) ;
F_4 ( V_2 , ( V_2 -> V_4 . V_13 - V_22 ) ,
V_23 ) ;
}
static int F_9 ( struct V_24 * V_25 , void * V_26 )
{
struct V_1 * V_2 = V_25 -> V_26 ;
int V_3 ;
T_1 V_27 , V_28 , V_29 , V_30 ;
F_10 ( V_25 , L_6 , L_7 ) ;
for ( V_3 = 0 ; V_3 < V_7 ; V_3 ++ ) {
V_27 = V_2 -> V_4 . V_10 [ V_3 ] ;
F_5 ( V_27 , V_19 ) ;
V_28 = V_2 -> V_4 . V_9 [ V_3 ] ;
F_5 ( V_28 , V_19 ) ;
V_29 = V_2 -> V_4 . V_11 [ V_3 ] ;
F_5 ( V_29 , V_19 ) ;
V_30 = V_2 -> V_4 . V_12 [ V_3 ] ;
F_5 ( V_30 , V_19 ) ;
F_10 ( V_25 , L_8 ,
V_31 [ V_3 ] ,
V_2 -> V_4 . V_8 [ V_3 ] ,
V_27 ,
V_28 ,
V_29 ,
V_30 ) ;
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
struct V_24 * V_41 = V_32 -> V_42 ;
struct V_1 * V_2 = V_41 -> V_26 ;
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
return F_14 ( V_32 , F_9 , V_44 -> V_45 ) ;
}
void F_15 ( struct V_1 * V_2 , unsigned int V_46 )
{
static char V_47 [ 50 ] ;
struct V_48 * V_49 ;
snprintf ( V_47 , sizeof( V_47 ) , L_9 ,
V_50 -> V_51 , V_46 ) ;
V_49 = F_16 ( V_47 , 0666 ,
V_52 , V_2 ,
& V_53 ) ;
if ( ! V_49 ) {
F_7 ( V_20 L_10 ,
V_21 , V_47 ) ;
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
