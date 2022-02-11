static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_8 ;
V_8 = V_6 -> type -> V_9 ( V_2 , V_4 -> V_10 , V_4 -> V_11 ) ;
if ( V_8 == 0 ) {
V_4 -> V_12 = V_13 ;
} else {
V_4 -> V_12 = V_14 ;
V_4 -> V_15 = V_16 ;
}
F_2 ( V_4 ) ;
return V_8 ;
}
static void F_3 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = F_4 ( V_2 ) ;
struct V_5 * V_6 = V_2 -> V_7 ;
int V_8 ;
V_8 = V_6 -> type -> V_19 ( V_2 ) ;
if ( V_8 )
F_5 ( L_1 ,
V_18 -> V_20 , V_18 -> V_21 , V_8 ) ;
}
static void F_6 ( struct V_17 * V_18 )
{
int V_8 ;
for (; ; ) {
V_8 = F_7 ( & V_18 -> V_2 ) ;
if ( V_8 != - V_22 )
break;
F_8 ( 1 ) ;
}
F_9 ( V_8 ) ;
F_10 ( & V_18 -> V_23 ) ;
}
int F_11 ( struct V_5 * V_6 , struct V_17 * V_24 ,
T_1 V_25 , T_1 V_26 )
{
struct V_17 * V_18 ;
T_1 V_27 ;
for ( V_27 = 0 ; V_27 < V_25 ; V_27 ++ ) {
V_18 = (struct V_17 * ) ( ( char * ) V_24 +
V_27 * V_26 ) ;
V_18 -> V_2 . V_28 = 1 ;
V_18 -> V_2 . V_29 = V_30 ;
V_18 -> V_2 . V_7 = V_6 ;
V_18 -> V_2 . V_20 = V_18 -> V_20 ;
V_18 -> V_2 . V_31 = F_1 ;
V_18 -> V_2 . V_32 = V_6 -> type -> V_33 ;
V_18 -> V_2 . V_34 = V_6 -> type -> V_35 ;
V_18 -> V_2 . V_36 = F_3 ;
V_6 -> type -> V_37 ( V_18 ) ;
if ( F_12 ( & V_18 -> V_2 , NULL , 0 ) )
goto V_38;
F_13 ( & V_18 -> V_23 , & V_6 -> V_39 ) ;
}
return 0 ;
V_38:
while ( V_27 -- ) {
V_18 = (struct V_17 * ) ( ( char * ) V_24 +
V_27 * V_26 ) ;
F_6 ( V_18 ) ;
}
return - V_40 ;
}
void F_14 ( struct V_5 * V_6 )
{
struct V_17 * V_24 , * V_18 , * V_41 ;
F_9 ( F_15 ( V_6 ) ) ;
if ( F_16 ( & V_6 -> V_39 ) )
return;
V_24 = F_17 ( & V_6 -> V_39 , struct V_17 ,
V_23 ) ;
F_18 (part, next, &efx->mtd_list, node)
F_6 ( V_18 ) ;
F_19 ( V_24 ) ;
}
void F_20 ( struct V_5 * V_6 )
{
struct V_17 * V_18 ;
F_21 () ;
F_22 (part, &efx->mtd_list, node)
V_6 -> type -> V_37 ( V_18 ) ;
}
