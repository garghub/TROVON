static struct V_1 * F_1 ( const char * V_2 )
{
struct V_3 * V_4 ;
struct V_1 * V_5 ;
V_5 = F_2 ( - V_6 ) ;
F_3 ( & V_7 ) ;
F_4 (fd, &func_list, list) {
if ( strcmp ( V_2 , V_4 -> V_2 ) )
continue;
if ( ! F_5 ( V_4 -> V_8 ) ) {
V_5 = F_2 ( - V_9 ) ;
break;
}
V_5 = V_4 -> V_10 () ;
if ( F_6 ( V_5 ) )
F_7 ( V_4 -> V_8 ) ;
else
V_5 -> V_4 = V_4 ;
break;
}
F_8 ( & V_7 ) ;
return V_5 ;
}
struct V_1 * F_9 ( const char * V_2 )
{
struct V_1 * V_5 ;
int V_11 ;
V_5 = F_1 ( V_2 ) ;
if ( ! F_6 ( V_5 ) )
return V_5 ;
V_11 = F_10 ( V_5 ) ;
if ( V_11 != - V_6 )
return V_5 ;
V_11 = F_11 ( L_1 , V_2 ) ;
if ( V_11 < 0 )
return F_2 ( V_11 ) ;
return F_1 ( V_2 ) ;
}
struct V_12 * F_12 ( struct V_1 * V_5 )
{
struct V_12 * V_13 ;
V_13 = V_5 -> V_4 -> V_14 ( V_5 ) ;
if ( F_6 ( V_13 ) )
return V_13 ;
V_13 -> V_5 = V_5 ;
return V_13 ;
}
void F_13 ( struct V_1 * V_5 )
{
struct V_15 * V_8 ;
if ( ! V_5 )
return;
V_8 = V_5 -> V_4 -> V_8 ;
V_5 -> V_16 ( V_5 ) ;
F_7 ( V_8 ) ;
}
void F_14 ( struct V_12 * V_13 )
{
if ( ! V_13 )
return;
V_13 -> V_17 ( V_13 ) ;
}
int F_15 ( struct V_3 * V_18 )
{
struct V_3 * V_4 ;
int V_11 ;
V_11 = - V_19 ;
F_3 ( & V_7 ) ;
F_4 (fd, &func_list, list) {
if ( ! strcmp ( V_4 -> V_2 , V_18 -> V_2 ) )
goto V_20;
}
V_11 = 0 ;
F_16 ( & V_18 -> V_21 , & V_22 ) ;
V_20:
F_8 ( & V_7 ) ;
return V_11 ;
}
void F_17 ( struct V_3 * V_4 )
{
F_3 ( & V_7 ) ;
F_18 ( & V_4 -> V_21 ) ;
F_8 ( & V_7 ) ;
}
