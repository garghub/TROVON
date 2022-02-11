static void F_1 ( const char * V_1 , struct V_2 * V_2 , char * V_3 )
{
char * V_4 , * V_5 ;
V_5 = F_2 ( V_2 , V_6 ) ;
V_4 = F_3 ( V_7 , V_6 ) ;
F_4 ( L_1 ,
V_1 , V_3 ,
( V_5 && V_5 [ 0 ] != '<' ) ? L_2 : L_3 ,
V_5 ,
( V_5 && V_5 [ 0 ] != '<' ) ? L_2 : L_3 ,
F_5 ( V_7 ) ,
V_4 ? L_2 : L_3 , V_4 , V_4 ? L_2 : L_3 ) ;
F_6 ( V_4 ) ;
F_6 ( V_5 ) ;
}
static void F_7 ( struct V_8 * V_9 )
{
bool V_10 = false ;
if ( V_9 -> V_11 ) {
V_10 = F_8 ( V_9 -> V_11 ) ;
F_9 ( L_4 ,
F_10 ( V_9 -> V_11 -> V_12 ) ,
F_11 ( V_9 -> V_11 -> V_12 ) ,
V_10 ? L_5 : L_6 ) ;
} else
F_9 ( L_7 ) ;
if ( ! V_10 ) {
if ( ! F_12 ( V_13 ,
V_14 ) )
F_4 ( L_8 ) ;
else
F_9 ( L_9 ) ;
} else
F_9 ( L_10 ) ;
}
static void F_7 ( struct V_8 * V_9 )
{
F_9 ( L_10 ) ;
}
static void F_13 ( struct V_8 * V_9 )
{
if ( ! F_14 ( V_15 ) && V_9 == V_15 ) {
V_15 = F_15 ( - V_16 ) ;
F_9 ( L_11 ) ;
}
}
static int F_16 ( struct V_2 * V_2 , enum V_17 V_18 )
{
struct V_8 * V_19 ;
const char * V_1 = F_17 ( V_18 ) ;
if ( ! V_2 ) {
if ( ! V_20 ) {
F_1 ( V_1 , NULL , L_12 ) ;
return 0 ;
}
F_1 ( V_1 , NULL , L_13 ) ;
return - V_21 ;
}
V_19 = V_2 -> V_22 . V_23 -> V_9 ;
F_18 ( & V_24 ) ;
if ( ! V_15 ) {
V_15 = V_19 ;
F_19 ( & V_24 ) ;
F_7 ( V_15 ) ;
F_1 ( V_1 , V_2 , L_14 ) ;
} else {
F_19 ( & V_24 ) ;
}
if ( F_14 ( V_15 ) || V_19 != V_15 ) {
if ( F_20 ( ! V_20 ) ) {
F_1 ( V_1 , V_2 , L_15 ) ;
return 0 ;
}
F_1 ( V_1 , V_2 , L_16 ) ;
return - V_21 ;
}
return 0 ;
}
void T_1 F_21 ( void )
{
F_9 ( L_17 , V_20 ? L_18 : L_19 ) ;
F_22 ( V_25 , F_23 ( V_25 ) ) ;
}
