struct V_1 * F_1 ( int V_2 )
{
struct V_1 * V_3 , * V_4 = NULL ;
F_2 () ;
F_3 (pos, &tpm_chip_list, list) {
if ( V_2 != V_5 && V_2 != V_3 -> V_6 )
continue;
if ( F_4 ( V_3 -> V_7 -> V_8 -> V_9 ) ) {
V_4 = V_3 ;
break;
}
}
F_5 () ;
return V_4 ;
}
static void F_6 ( struct V_10 * V_11 )
{
struct V_1 * V_4 = F_7 ( V_11 , struct V_1 , V_11 ) ;
F_8 ( & V_12 ) ;
F_9 ( V_4 -> V_6 , V_13 ) ;
F_10 ( & V_12 ) ;
F_11 ( V_4 ) ;
}
struct V_1 * F_12 ( struct V_10 * V_11 ,
const struct V_14 * V_15 )
{
struct V_1 * V_4 ;
V_4 = F_13 ( sizeof( * V_4 ) , V_16 ) ;
if ( V_4 == NULL )
return F_14 ( - V_17 ) ;
F_15 ( & V_4 -> V_18 ) ;
F_16 ( & V_4 -> V_19 ) ;
V_4 -> V_15 = V_15 ;
F_8 ( & V_12 ) ;
V_4 -> V_6 = F_17 ( V_13 , V_20 ) ;
F_10 ( & V_12 ) ;
if ( V_4 -> V_6 >= V_20 ) {
F_18 ( V_11 , L_1 ) ;
F_11 ( V_4 ) ;
return F_14 ( - V_17 ) ;
}
F_19 ( V_4 -> V_6 , V_13 ) ;
F_20 ( V_4 -> V_21 , sizeof( V_4 -> V_21 ) , L_2 , V_4 -> V_6 ) ;
V_4 -> V_7 = V_11 ;
F_21 ( V_11 , V_4 ) ;
V_4 -> V_11 . V_22 = V_23 ;
V_4 -> V_11 . V_24 = F_6 ;
V_4 -> V_11 . V_25 = V_4 -> V_7 ;
if ( V_4 -> V_6 == 0 )
V_4 -> V_11 . V_26 = F_22 ( V_27 , V_28 ) ;
else
V_4 -> V_11 . V_26 = F_22 ( F_23 ( V_29 ) , V_4 -> V_6 ) ;
F_24 ( & V_4 -> V_11 , L_3 , V_4 -> V_21 ) ;
F_25 ( & V_4 -> V_11 ) ;
V_4 -> V_30 . V_9 = V_4 -> V_7 -> V_8 -> V_9 ;
F_26 ( & V_4 -> V_30 , & V_31 ) ;
return V_4 ;
}
static int F_27 ( struct V_1 * V_4 )
{
int V_32 ;
V_32 = F_28 ( & V_4 -> V_30 , V_4 -> V_11 . V_26 , 1 ) ;
if ( V_32 ) {
F_18 ( & V_4 -> V_11 ,
L_4 ,
V_4 -> V_21 , F_23 ( V_4 -> V_11 . V_26 ) ,
F_29 ( V_4 -> V_11 . V_26 ) , V_32 ) ;
F_30 ( & V_4 -> V_11 ) ;
return V_32 ;
}
V_32 = F_31 ( & V_4 -> V_11 ) ;
if ( V_32 ) {
F_18 ( & V_4 -> V_11 ,
L_5 ,
V_4 -> V_21 , F_23 ( V_4 -> V_11 . V_26 ) ,
F_29 ( V_4 -> V_11 . V_26 ) , V_32 ) ;
return V_32 ;
}
return V_32 ;
}
static void F_32 ( struct V_1 * V_4 )
{
F_33 ( & V_4 -> V_30 ) ;
F_30 ( & V_4 -> V_11 ) ;
}
int F_34 ( struct V_1 * V_4 )
{
int V_32 ;
if ( ! ( V_4 -> V_33 & V_34 ) ) {
V_32 = F_35 ( V_4 ) ;
if ( V_32 )
goto V_35;
V_32 = F_36 ( V_4 ) ;
if ( V_32 )
goto V_36;
V_4 -> V_37 = F_37 ( V_4 -> V_21 ) ;
}
V_32 = F_27 ( V_4 ) ;
if ( V_32 )
return V_32 ;
F_8 ( & V_12 ) ;
F_38 ( & V_4 -> V_19 , & V_38 ) ;
F_10 ( & V_12 ) ;
V_4 -> V_33 |= V_39 ;
return 0 ;
V_36:
F_39 ( V_4 ) ;
V_35:
F_32 ( V_4 ) ;
return V_32 ;
}
void F_40 ( struct V_1 * V_4 )
{
if ( ! ( V_4 -> V_33 & V_39 ) )
return;
F_8 ( & V_12 ) ;
F_41 ( & V_4 -> V_19 ) ;
F_10 ( & V_12 ) ;
F_42 () ;
if ( ! ( V_4 -> V_33 & V_34 ) ) {
if ( V_4 -> V_37 )
F_43 ( V_4 -> V_37 ) ;
F_44 ( V_4 ) ;
F_39 ( V_4 ) ;
}
F_32 ( V_4 ) ;
}
