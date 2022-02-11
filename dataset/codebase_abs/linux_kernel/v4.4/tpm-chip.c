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
#ifdef F_22
V_4 -> V_11 . V_26 = V_4 -> V_26 ;
#endif
if ( V_4 -> V_6 == 0 )
V_4 -> V_11 . V_27 = F_23 ( V_28 , V_29 ) ;
else
V_4 -> V_11 . V_27 = F_23 ( F_24 ( V_30 ) , V_4 -> V_6 ) ;
F_25 ( & V_4 -> V_11 , L_3 , V_4 -> V_21 ) ;
F_26 ( & V_4 -> V_11 ) ;
F_27 ( & V_4 -> V_31 , & V_32 ) ;
V_4 -> V_31 . V_9 = V_4 -> V_7 -> V_8 -> V_9 ;
V_4 -> V_31 . V_33 . V_25 = & V_4 -> V_11 . V_33 ;
return V_4 ;
}
static int F_28 ( struct V_1 * V_4 )
{
int V_34 ;
V_34 = F_29 ( & V_4 -> V_31 , V_4 -> V_11 . V_27 , 1 ) ;
if ( V_34 ) {
F_18 ( & V_4 -> V_11 ,
L_4 ,
V_4 -> V_21 , F_24 ( V_4 -> V_11 . V_27 ) ,
F_30 ( V_4 -> V_11 . V_27 ) , V_34 ) ;
F_31 ( & V_4 -> V_11 ) ;
return V_34 ;
}
V_34 = F_32 ( & V_4 -> V_11 ) ;
if ( V_34 ) {
F_18 ( & V_4 -> V_11 ,
L_5 ,
V_4 -> V_21 , F_24 ( V_4 -> V_11 . V_27 ) ,
F_30 ( V_4 -> V_11 . V_27 ) , V_34 ) ;
return V_34 ;
}
return V_34 ;
}
static void F_33 ( struct V_1 * V_4 )
{
F_34 ( & V_4 -> V_31 ) ;
F_31 ( & V_4 -> V_11 ) ;
}
static int F_35 ( struct V_1 * V_4 )
{
int V_34 ;
if ( V_4 -> V_35 & V_36 )
return 0 ;
V_34 = F_36 ( V_4 ) ;
if ( V_34 )
return V_34 ;
V_4 -> V_37 = F_37 ( V_4 -> V_21 ) ;
return 0 ;
}
static void F_38 ( struct V_1 * V_4 )
{
if ( V_4 -> V_35 & V_36 )
return;
if ( V_4 -> V_37 )
F_39 ( V_4 -> V_37 ) ;
F_40 ( V_4 ) ;
}
int F_41 ( struct V_1 * V_4 )
{
int V_34 ;
V_34 = F_35 ( V_4 ) ;
if ( V_34 )
return V_34 ;
F_42 ( V_4 ) ;
V_34 = F_28 ( V_4 ) ;
if ( V_34 )
goto V_38;
F_8 ( & V_12 ) ;
F_43 ( & V_4 -> V_19 , & V_39 ) ;
F_10 ( & V_12 ) ;
V_4 -> V_35 |= V_40 ;
if ( ! ( V_4 -> V_35 & V_36 ) ) {
V_34 = F_44 ( & V_4 -> V_7 -> V_33 ,
& V_4 -> V_11 . V_33 ,
L_6 ) ;
if ( V_34 && V_34 != - V_41 ) {
F_45 ( V_4 ) ;
return V_34 ;
}
}
return 0 ;
V_38:
F_38 ( V_4 ) ;
return V_34 ;
}
void F_45 ( struct V_1 * V_4 )
{
if ( ! ( V_4 -> V_35 & V_40 ) )
return;
F_8 ( & V_12 ) ;
F_46 ( & V_4 -> V_19 ) ;
F_10 ( & V_12 ) ;
F_47 () ;
if ( ! ( V_4 -> V_35 & V_36 ) )
F_48 ( & V_4 -> V_7 -> V_33 , L_6 ) ;
F_38 ( V_4 ) ;
F_33 ( V_4 ) ;
}
