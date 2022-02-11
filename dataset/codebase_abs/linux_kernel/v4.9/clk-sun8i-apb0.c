static struct V_1 * F_1 ( struct V_2 * V_3 ,
void T_1 * V_4 )
{
const char * V_5 = V_3 -> V_6 ;
const char * V_7 ;
struct V_1 * V_1 ;
int V_8 ;
V_7 = F_2 ( V_3 , 0 ) ;
if ( ! V_7 )
return F_3 ( - V_9 ) ;
F_4 ( V_3 , L_1 , & V_5 ) ;
V_1 = F_5 ( NULL , V_5 , V_7 , 0 , V_4 ,
0 , 2 , 0 , NULL ) ;
if ( F_6 ( V_1 ) )
return V_1 ;
V_8 = F_7 ( V_3 , V_10 , V_1 ) ;
if ( V_8 )
goto V_11;
return V_1 ;
V_11:
F_8 ( V_1 ) ;
return F_3 ( V_8 ) ;
}
static void F_9 ( struct V_2 * V_3 )
{
void T_1 * V_4 ;
struct V_12 V_13 ;
struct V_1 * V_1 ;
V_4 = F_10 ( V_3 , 0 , F_11 ( V_3 ) ) ;
if ( F_6 ( V_4 ) ) {
if ( F_12 ( V_4 ) != - V_9 )
F_13 ( L_2 ) ;
return;
}
V_1 = F_1 ( V_3 , V_4 ) ;
if ( F_6 ( V_1 ) )
goto V_14;
return;
V_14:
F_14 ( V_4 ) ;
F_15 ( V_3 , 0 , & V_13 ) ;
F_16 ( V_13 . V_15 , F_17 ( & V_13 ) ) ;
}
static int F_18 ( struct V_16 * V_17 )
{
struct V_2 * V_18 = V_17 -> V_19 . V_20 ;
struct V_12 * V_21 ;
void T_1 * V_4 ;
struct V_1 * V_1 ;
V_21 = F_19 ( V_17 , V_22 , 0 ) ;
V_4 = F_20 ( & V_17 -> V_19 , V_21 ) ;
if ( F_6 ( V_4 ) )
return F_12 ( V_4 ) ;
V_1 = F_1 ( V_18 , V_4 ) ;
if ( F_6 ( V_1 ) )
return F_12 ( V_1 ) ;
return 0 ;
}
