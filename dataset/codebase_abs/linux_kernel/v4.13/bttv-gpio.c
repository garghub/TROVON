static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
int V_7 = strlen ( V_6 -> V_8 ) ;
if ( 0 == strncmp ( F_3 ( V_2 ) , V_6 -> V_8 , V_7 ) )
return 1 ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_5 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 -> V_11 ) ;
return V_6 -> V_12 ? V_6 -> V_12 ( V_10 ) : - V_13 ;
}
static int F_6 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_5 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 -> V_11 ) ;
if ( V_6 -> remove )
V_6 -> remove ( V_10 ) ;
return 0 ;
}
static void F_7 ( struct V_1 * V_2 )
{
struct V_9 * V_6 = F_5 ( V_2 ) ;
F_8 ( V_6 ) ;
}
int F_9 ( struct V_14 * V_15 , char * V_16 )
{
struct V_9 * V_6 ;
int V_17 ;
V_6 = F_10 ( sizeof( * V_6 ) , V_18 ) ;
if ( NULL == V_6 )
return - V_19 ;
V_6 -> V_15 = V_15 ;
V_6 -> V_2 . V_20 = & V_15 -> V_21 -> V_2 ;
V_6 -> V_2 . V_22 = & V_23 ;
V_6 -> V_2 . V_24 = F_7 ;
F_11 ( & V_6 -> V_2 , L_1 , V_16 , V_15 -> V_25 ) ;
V_17 = F_12 ( & V_6 -> V_2 ) ;
if ( 0 != V_17 ) {
F_13 ( & V_6 -> V_2 ) ;
return V_17 ;
}
F_14 ( L_2 , V_15 -> V_25 , F_3 ( & V_6 -> V_2 ) ) ;
F_15 ( & V_6 -> V_26 , & V_15 -> V_27 ) ;
return 0 ;
}
int F_16 ( struct V_14 * V_15 )
{
struct V_9 * V_6 , * V_28 ;
F_17 (sub, save, &core->subs, list) {
F_18 ( & V_6 -> V_26 ) ;
F_19 ( & V_6 -> V_2 ) ;
}
return 0 ;
}
int F_20 ( struct V_5 * V_6 , char * V_8 )
{
V_6 -> V_4 . V_22 = & V_23 ;
snprintf ( V_6 -> V_8 , sizeof( V_6 -> V_8 ) , L_3 , V_8 ) ;
return F_21 ( & V_6 -> V_4 ) ;
}
int F_22 ( struct V_5 * V_6 )
{
F_23 ( & V_6 -> V_4 ) ;
return 0 ;
}
void F_24 ( struct V_14 * V_15 , T_1 V_29 , T_1 V_30 )
{
struct V_31 * V_32 = F_25 ( V_15 , struct V_31 , V_33 ) ;
unsigned long V_34 ;
T_1 V_35 ;
F_26 ( & V_32 -> V_36 , V_34 ) ;
V_35 = F_27 ( V_37 ) ;
V_35 = V_35 & ~ V_29 ;
V_35 = V_35 | ( V_29 & V_30 ) ;
F_28 ( V_35 , V_37 ) ;
F_29 ( & V_32 -> V_36 , V_34 ) ;
}
T_1 F_30 ( struct V_14 * V_15 )
{
struct V_31 * V_32 = F_25 ( V_15 , struct V_31 , V_33 ) ;
T_1 V_38 ;
V_38 = F_27 ( V_39 ) ;
return V_38 ;
}
void F_31 ( struct V_14 * V_15 , T_1 V_38 )
{
struct V_31 * V_32 = F_25 ( V_15 , struct V_31 , V_33 ) ;
F_28 ( V_38 , V_39 ) ;
}
void F_32 ( struct V_14 * V_15 , T_1 V_29 , T_1 V_40 )
{
struct V_31 * V_32 = F_25 ( V_15 , struct V_31 , V_33 ) ;
unsigned long V_34 ;
T_1 V_35 ;
F_26 ( & V_32 -> V_36 , V_34 ) ;
V_35 = F_27 ( V_39 ) ;
V_35 = V_35 & ~ V_29 ;
V_35 = V_35 | ( V_29 & V_40 ) ;
F_28 ( V_35 , V_39 ) ;
F_29 ( & V_32 -> V_36 , V_34 ) ;
}
