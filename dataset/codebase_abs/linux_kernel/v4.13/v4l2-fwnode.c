static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = & V_4 -> V_6 . V_7 ;
bool V_8 = false ;
unsigned int V_9 = 0 , V_10 = 0 ;
unsigned int V_11 ;
T_1 V_12 ;
int V_13 ;
V_13 = F_2 ( V_2 , L_1 , NULL , 0 ) ;
if ( V_13 > 0 ) {
T_1 V_14 [ F_3 ( V_6 -> V_15 ) ] ;
V_6 -> V_16 =
F_4 ( int , F_3 ( V_6 -> V_15 ) , V_13 ) ;
F_2 ( V_2 , L_1 , V_14 ,
V_6 -> V_16 ) ;
for ( V_11 = 0 ; V_11 < V_6 -> V_16 ; V_11 ++ ) {
if ( V_10 & F_5 ( V_14 [ V_11 ] ) )
F_6 ( L_2 ,
V_14 [ V_11 ] ) ;
V_10 |= F_5 ( V_14 [ V_11 ] ) ;
V_6 -> V_15 [ V_11 ] = V_14 [ V_11 ] ;
}
}
V_13 = F_2 ( V_2 , L_3 , NULL ,
0 ) ;
if ( V_13 > 0 ) {
T_1 V_14 [ F_3 ( V_6 -> V_17 ) ] ;
if ( V_13 < 1 + V_6 -> V_16 ) {
F_6 ( L_4 ,
1 + V_6 -> V_16 , V_13 ) ;
return - V_18 ;
}
F_2 ( V_2 , L_3 , V_14 ,
1 + V_6 -> V_16 ) ;
for ( V_11 = 0 ; V_11 < 1 + V_6 -> V_16 ; V_11 ++ )
V_6 -> V_17 [ V_11 ] = V_14 [ V_11 ] ;
}
if ( ! F_7 ( V_2 , L_5 , & V_12 ) ) {
if ( V_10 & F_5 ( V_12 ) )
F_6 ( L_6 , V_12 ) ;
V_10 |= F_5 ( V_12 ) ;
V_6 -> V_19 = V_12 ;
V_8 = true ;
}
if ( F_8 ( V_2 , L_7 ) )
V_9 |= V_20 ;
else if ( V_8 || V_6 -> V_16 > 0 )
V_9 |= V_21 ;
V_6 -> V_9 = V_9 ;
V_4 -> V_22 = V_23 ;
return 0 ;
}
static void F_9 (
struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_24 * V_6 = & V_4 -> V_6 . V_25 ;
unsigned int V_9 = 0 ;
T_1 V_12 ;
if ( ! F_7 ( V_2 , L_8 , & V_12 ) )
V_9 |= V_12 ? V_26 :
V_27 ;
if ( ! F_7 ( V_2 , L_9 , & V_12 ) )
V_9 |= V_12 ? V_28 :
V_29 ;
if ( ! F_7 ( V_2 , L_10 , & V_12 ) )
V_9 |= V_12 ? V_30 :
V_31 ;
if ( V_9 )
V_4 -> V_22 = V_32 ;
else
V_4 -> V_22 = V_33 ;
if ( ! F_7 ( V_2 , L_11 , & V_12 ) )
V_9 |= V_12 ? V_34 :
V_35 ;
if ( ! F_7 ( V_2 , L_12 , & V_12 ) )
V_9 |= V_12 ? V_36 :
V_37 ;
if ( F_8 ( V_2 , L_13 ) )
V_9 |= V_38 ;
else
V_9 |= V_39 ;
if ( ! F_7 ( V_2 , L_14 , & V_12 ) )
V_6 -> V_40 = V_12 ;
if ( ! F_7 ( V_2 , L_15 , & V_12 ) )
V_6 -> V_41 = V_12 ;
if ( ! F_7 ( V_2 , L_16 , & V_12 ) )
V_9 |= V_12 ? V_42 :
V_43 ;
V_6 -> V_9 = V_9 ;
}
int F_10 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_13 ;
F_11 ( V_2 , & V_4 -> V_44 ) ;
memset ( & V_4 -> V_22 , 0 , sizeof( * V_4 ) -
F_12 ( F_13 ( * V_4 ) , V_22 ) ) ;
V_13 = F_1 ( V_2 , V_4 ) ;
if ( V_13 )
return V_13 ;
if ( V_4 -> V_6 . V_7 . V_9 == 0 )
F_9 ( V_2 , V_4 ) ;
return 0 ;
}
void F_14 ( struct V_3 * V_4 )
{
if ( F_15 ( V_4 ) )
return;
F_16 ( V_4 -> V_45 ) ;
F_16 ( V_4 ) ;
}
struct V_3 * F_17 (
struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_13 ;
V_4 = F_18 ( sizeof( * V_4 ) , V_46 ) ;
if ( ! V_4 )
return F_19 ( - V_47 ) ;
V_13 = F_10 ( V_2 , V_4 ) ;
if ( V_13 < 0 )
goto V_48;
V_13 = F_20 ( V_2 , L_17 ,
NULL , 0 ) ;
if ( V_13 < 0 )
goto V_48;
V_4 -> V_45 =
F_21 ( V_13 , sizeof( * V_4 -> V_45 ) , V_46 ) ;
if ( ! V_4 -> V_45 ) {
V_13 = - V_47 ;
goto V_48;
}
V_4 -> V_49 = V_13 ;
V_13 = F_20 ( V_2 , L_17 ,
V_4 -> V_45 ,
V_4 -> V_49 ) ;
if ( V_13 < 0 )
goto V_48;
return V_4 ;
V_48:
F_14 ( V_4 ) ;
return F_19 ( V_13 ) ;
}
int F_22 ( struct V_1 * V_50 ,
struct V_51 * V_52 )
{
const char * V_53 = F_23 ( V_50 ) ? L_18 : L_19 ;
struct V_1 * V_2 ;
memset ( V_52 , 0 , sizeof( * V_52 ) ) ;
V_2 = F_24 ( V_50 ) ;
F_7 ( V_2 , V_53 , & V_52 -> V_54 ) ;
V_2 = F_25 ( V_2 ) ;
if ( F_23 ( V_2 ) &&
F_26 ( F_27 ( V_2 ) -> V_55 , L_20 ) == 0 )
V_2 = F_25 ( V_2 ) ;
V_52 -> V_56 = V_2 ;
V_2 = F_28 ( V_50 ) ;
if ( ! V_2 ) {
F_29 ( V_2 ) ;
return - V_57 ;
}
V_2 = F_24 ( V_2 ) ;
F_7 ( V_2 , V_53 , & V_52 -> V_58 ) ;
V_2 = F_25 ( V_2 ) ;
if ( F_23 ( V_2 ) &&
F_26 ( F_27 ( V_2 ) -> V_55 , L_20 ) == 0 )
V_2 = F_25 ( V_2 ) ;
V_52 -> V_59 = V_2 ;
return 0 ;
}
void F_30 ( struct V_51 * V_52 )
{
F_29 ( V_52 -> V_56 ) ;
F_29 ( V_52 -> V_59 ) ;
}
