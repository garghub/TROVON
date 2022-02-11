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
0 , 2 , V_10 , NULL ) ;
if ( F_6 ( V_1 ) )
return V_1 ;
V_8 = F_7 ( V_3 , V_11 , V_1 ) ;
if ( V_8 )
goto V_12;
return V_1 ;
V_12:
F_8 ( V_1 ) ;
return F_3 ( V_8 ) ;
}
static void F_9 ( struct V_2 * V_3 )
{
void T_1 * V_4 ;
struct V_13 V_14 ;
struct V_1 * V_1 ;
V_4 = F_10 ( V_3 , 0 , F_11 ( V_3 ) ) ;
if ( F_6 ( V_4 ) ) {
if ( F_12 ( V_4 ) != - V_9 )
F_13 ( L_2 ) ;
return;
}
V_1 = F_1 ( V_3 , V_4 ) ;
if ( F_6 ( V_1 ) )
goto V_15;
return;
V_15:
F_14 ( V_4 ) ;
F_15 ( V_3 , 0 , & V_14 ) ;
F_16 ( V_14 . V_16 , F_17 ( & V_14 ) ) ;
}
static int F_18 ( struct V_17 * V_18 )
{
struct V_2 * V_19 = V_18 -> V_20 . V_21 ;
struct V_13 * V_22 ;
void T_1 * V_4 ;
struct V_1 * V_1 ;
V_22 = F_19 ( V_18 , V_23 , 0 ) ;
V_4 = F_20 ( & V_18 -> V_20 , V_22 ) ;
if ( F_6 ( V_4 ) )
return F_12 ( V_4 ) ;
V_1 = F_1 ( V_19 , V_4 ) ;
if ( F_6 ( V_1 ) )
return F_12 ( V_1 ) ;
return 0 ;
}
