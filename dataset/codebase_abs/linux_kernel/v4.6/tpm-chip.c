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
int V_16 ;
V_4 = F_13 ( sizeof( * V_4 ) , V_17 ) ;
if ( V_4 == NULL )
return F_14 ( - V_18 ) ;
F_15 ( & V_4 -> V_19 ) ;
F_16 ( & V_4 -> V_20 ) ;
V_4 -> V_15 = V_15 ;
F_8 ( & V_12 ) ;
V_4 -> V_6 = F_17 ( V_13 , V_21 ) ;
F_10 ( & V_12 ) ;
if ( V_4 -> V_6 >= V_21 ) {
F_18 ( V_11 , L_1 ) ;
F_11 ( V_4 ) ;
return F_14 ( - V_18 ) ;
}
F_19 ( V_4 -> V_6 , V_13 ) ;
F_20 ( V_4 -> V_22 , sizeof( V_4 -> V_22 ) , L_2 , V_4 -> V_6 ) ;
V_4 -> V_7 = V_11 ;
F_21 ( V_11 , V_4 ) ;
V_4 -> V_11 . V_23 = V_24 ;
V_4 -> V_11 . V_25 = F_6 ;
V_4 -> V_11 . V_26 = V_4 -> V_7 ;
#ifdef F_22
V_4 -> V_11 . V_27 = V_4 -> V_27 ;
#endif
if ( V_4 -> V_6 == 0 )
V_4 -> V_11 . V_28 = F_23 ( V_29 , V_30 ) ;
else
V_4 -> V_11 . V_28 = F_23 ( F_24 ( V_31 ) , V_4 -> V_6 ) ;
F_25 ( & V_4 -> V_11 , L_3 , V_4 -> V_22 ) ;
F_26 ( & V_4 -> V_11 ) ;
F_27 ( & V_4 -> V_32 , & V_33 ) ;
V_4 -> V_32 . V_9 = V_4 -> V_7 -> V_8 -> V_9 ;
V_4 -> V_32 . V_34 . V_26 = & V_4 -> V_11 . V_34 ;
V_16 = F_28 ( V_11 , ( void ( * ) ( void * ) ) V_35 , & V_4 -> V_11 ) ;
if ( V_16 ) {
V_35 ( & V_4 -> V_11 ) ;
return F_14 ( V_16 ) ;
}
return V_4 ;
}
static int F_29 ( struct V_1 * V_4 )
{
int V_16 ;
V_16 = F_30 ( & V_4 -> V_32 , V_4 -> V_11 . V_28 , 1 ) ;
if ( V_16 ) {
F_18 ( & V_4 -> V_11 ,
L_4 ,
V_4 -> V_22 , F_24 ( V_4 -> V_11 . V_28 ) ,
F_31 ( V_4 -> V_11 . V_28 ) , V_16 ) ;
return V_16 ;
}
V_16 = F_32 ( & V_4 -> V_11 ) ;
if ( V_16 ) {
F_18 ( & V_4 -> V_11 ,
L_5 ,
V_4 -> V_22 , F_24 ( V_4 -> V_11 . V_28 ) ,
F_31 ( V_4 -> V_11 . V_28 ) , V_16 ) ;
F_33 ( & V_4 -> V_32 ) ;
return V_16 ;
}
return V_16 ;
}
static void F_34 ( struct V_1 * V_4 )
{
F_33 ( & V_4 -> V_32 ) ;
F_35 ( & V_4 -> V_11 ) ;
}
static int F_36 ( struct V_1 * V_4 )
{
int V_16 ;
if ( V_4 -> V_36 & V_37 )
return 0 ;
V_16 = F_37 ( V_4 ) ;
if ( V_16 )
return V_16 ;
V_4 -> V_38 = F_38 ( V_4 -> V_22 ) ;
return 0 ;
}
static void F_39 ( struct V_1 * V_4 )
{
if ( V_4 -> V_36 & V_37 )
return;
if ( V_4 -> V_38 )
F_40 ( V_4 -> V_38 ) ;
F_41 ( V_4 ) ;
}
int F_42 ( struct V_1 * V_4 )
{
int V_16 ;
V_16 = F_36 ( V_4 ) ;
if ( V_16 )
return V_16 ;
F_43 ( V_4 ) ;
V_16 = F_29 ( V_4 ) ;
if ( V_16 )
goto V_39;
F_8 ( & V_12 ) ;
F_44 ( & V_4 -> V_20 , & V_40 ) ;
F_10 ( & V_12 ) ;
V_4 -> V_36 |= V_41 ;
if ( ! ( V_4 -> V_36 & V_37 ) ) {
V_16 = F_45 ( & V_4 -> V_7 -> V_34 ,
& V_4 -> V_11 . V_34 ,
L_6 ) ;
if ( V_16 && V_16 != - V_42 ) {
F_46 ( V_4 ) ;
return V_16 ;
}
}
return 0 ;
V_39:
F_39 ( V_4 ) ;
return V_16 ;
}
void F_46 ( struct V_1 * V_4 )
{
if ( ! ( V_4 -> V_36 & V_41 ) )
return;
F_8 ( & V_12 ) ;
F_47 ( & V_4 -> V_20 ) ;
F_10 ( & V_12 ) ;
F_48 () ;
if ( ! ( V_4 -> V_36 & V_37 ) )
F_49 ( & V_4 -> V_7 -> V_34 , L_6 ) ;
F_39 ( V_4 ) ;
F_34 ( V_4 ) ;
}
