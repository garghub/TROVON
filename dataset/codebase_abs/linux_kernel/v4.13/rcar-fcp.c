struct V_1 * F_1 ( const struct V_2 * V_3 )
{
struct V_1 * V_4 ;
F_2 ( & V_5 ) ;
F_3 (fcp, &fcp_devices, list) {
if ( V_4 -> V_6 -> V_7 != V_3 )
continue;
F_4 ( V_4 -> V_6 ) ;
goto V_8;
}
V_4 = F_5 ( - V_9 ) ;
V_8:
F_6 ( & V_5 ) ;
return V_4 ;
}
void F_7 ( struct V_1 * V_4 )
{
if ( V_4 )
F_8 ( V_4 -> V_6 ) ;
}
struct V_10 * F_9 ( struct V_1 * V_4 )
{
return V_4 -> V_6 ;
}
int F_10 ( struct V_1 * V_4 )
{
int V_11 ;
if ( ! V_4 )
return 0 ;
V_11 = F_11 ( V_4 -> V_6 ) ;
if ( V_11 < 0 )
return V_11 ;
return 0 ;
}
void F_12 ( struct V_1 * V_4 )
{
if ( V_4 )
F_13 ( V_4 -> V_6 ) ;
}
static int F_14 ( struct V_12 * V_13 )
{
struct V_1 * V_4 ;
V_4 = F_15 ( & V_13 -> V_6 , sizeof( * V_4 ) , V_14 ) ;
if ( V_4 == NULL )
return - V_15 ;
V_4 -> V_6 = & V_13 -> V_6 ;
F_16 ( & V_13 -> V_6 ) ;
F_2 ( & V_5 ) ;
F_17 ( & V_4 -> V_16 , & V_17 ) ;
F_6 ( & V_5 ) ;
F_18 ( V_13 , V_4 ) ;
return 0 ;
}
static int F_19 ( struct V_12 * V_13 )
{
struct V_1 * V_4 = F_20 ( V_13 ) ;
F_2 ( & V_5 ) ;
F_21 ( & V_4 -> V_16 ) ;
F_6 ( & V_5 ) ;
F_22 ( & V_13 -> V_6 ) ;
return 0 ;
}
