struct V_1 * F_1 ( const struct V_2 * V_3 )
{
struct V_1 * V_4 ;
F_2 ( & V_5 ) ;
F_3 (fcp, &fcp_devices, list) {
if ( V_4 -> V_6 -> V_7 != V_3 )
continue;
if ( ! F_4 ( V_4 -> V_6 -> V_8 -> V_9 ) )
V_4 = NULL ;
goto V_10;
}
V_4 = F_5 ( - V_11 ) ;
V_10:
F_6 ( & V_5 ) ;
return V_4 ;
}
void F_7 ( struct V_1 * V_4 )
{
if ( V_4 )
F_8 ( V_4 -> V_6 -> V_8 -> V_9 ) ;
}
int F_9 ( struct V_1 * V_4 )
{
int error ;
if ( ! V_4 )
return 0 ;
error = F_10 ( V_4 -> V_6 ) ;
if ( error < 0 )
return error ;
return 0 ;
}
void F_11 ( struct V_1 * V_4 )
{
if ( V_4 )
F_12 ( V_4 -> V_6 ) ;
}
static int F_13 ( struct V_12 * V_13 )
{
struct V_1 * V_4 ;
V_4 = F_14 ( & V_13 -> V_6 , sizeof( * V_4 ) , V_14 ) ;
if ( V_4 == NULL )
return - V_15 ;
V_4 -> V_6 = & V_13 -> V_6 ;
F_15 ( & V_13 -> V_6 ) ;
F_2 ( & V_5 ) ;
F_16 ( & V_4 -> V_16 , & V_17 ) ;
F_6 ( & V_5 ) ;
F_17 ( V_13 , V_4 ) ;
return 0 ;
}
static int F_18 ( struct V_12 * V_13 )
{
struct V_1 * V_4 = F_19 ( V_13 ) ;
F_2 ( & V_5 ) ;
F_20 ( & V_4 -> V_16 ) ;
F_6 ( & V_5 ) ;
F_21 ( & V_13 -> V_6 ) ;
return 0 ;
}
