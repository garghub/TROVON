static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( V_4 ) ;
}
static int F_4 ( struct V_1 * V_2 , void * V_5 )
{
return ! strncmp ( F_5 ( V_2 ) , L_1 , 6 ) ;
}
void F_6 ( struct V_3 * V_4 )
{
struct V_6 * V_7 = V_4 -> V_7 ;
F_7 ( L_2 , V_4 ) ;
V_4 -> V_2 . type = & V_8 ;
V_4 -> V_2 . V_9 = V_10 ;
V_4 -> V_2 . V_11 = & V_7 -> V_2 ;
F_8 ( & V_4 -> V_2 ) ;
}
void F_9 ( struct V_3 * V_4 )
{
struct V_6 * V_7 = V_4 -> V_7 ;
F_7 ( L_2 , V_4 ) ;
F_10 ( & V_4 -> V_2 , L_3 , V_7 -> V_12 , V_4 -> V_13 ) ;
if ( F_11 ( & V_4 -> V_2 ) < 0 ) {
F_12 ( L_4 ) ;
return;
}
F_13 ( V_7 ) ;
}
void F_14 ( struct V_3 * V_4 )
{
struct V_6 * V_7 = V_4 -> V_7 ;
if ( ! F_15 ( & V_4 -> V_2 ) )
return;
while ( 1 ) {
struct V_1 * V_2 ;
V_2 = F_16 ( & V_4 -> V_2 , NULL , F_4 ) ;
if ( ! V_2 )
break;
F_17 ( V_2 , NULL , V_14 ) ;
F_18 ( V_2 ) ;
}
F_19 ( & V_4 -> V_2 ) ;
F_20 ( V_7 ) ;
}
static void F_21 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_22 ( V_2 ) ;
F_3 ( V_7 ) ;
F_23 ( V_15 ) ;
}
void F_24 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = & V_7 -> V_2 ;
V_2 -> type = & V_16 ;
V_2 -> V_9 = V_10 ;
F_25 ( V_15 ) ;
F_8 ( V_2 ) ;
}
int T_1 F_26 ( void )
{
V_10 = F_27 ( V_15 , L_5 ) ;
return F_28 ( V_10 ) ;
}
void F_29 ( void )
{
F_30 ( V_10 ) ;
}
