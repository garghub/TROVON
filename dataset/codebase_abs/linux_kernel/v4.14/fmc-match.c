void * F_1 ( T_1 V_1 )
{
return F_2 ( V_1 , V_2 ) ;
}
int F_3 ( struct V_3 * V_4 , struct V_5 * V_6 )
{
struct V_7 * V_8 = F_4 ( V_6 ) ;
struct V_9 * V_10 = F_5 ( V_4 ) ;
struct V_11 * V_12 ;
int V_13 , V_14 = 0 ;
V_12 = V_8 -> V_15 . V_16 ;
if ( ! V_12 ) {
F_6 ( & V_10 -> V_4 , L_1 ) ;
V_14 = 1 ;
} else {
if ( ! V_10 -> V_17 . V_18 || ! V_10 -> V_17 . V_19 )
return 0 ;
for ( V_13 = 0 ; V_13 < V_8 -> V_15 . V_20 ; V_13 ++ , V_12 ++ ) {
if ( V_12 -> V_18 &&
strcmp ( V_12 -> V_18 , V_10 -> V_17 . V_18 ) )
continue;
if ( V_12 -> V_19 &&
strcmp ( V_12 -> V_19 , V_10 -> V_17 . V_19 ) )
continue;
V_14 = 1 ;
break;
}
}
return V_14 ;
}
int F_7 ( struct V_9 * V_21 )
{
struct V_22 * V_23 ;
struct V_24 * V_25 ;
int V_26 , V_27 = 0 ;
if ( V_21 -> V_28 && ! V_21 -> V_29 ) {
V_21 -> V_29 = F_2 ( V_21 -> V_28 , V_2 ) ;
if ( ! V_21 -> V_29 )
return - V_30 ;
V_27 = 1 ;
V_26 = F_8 ( V_21 , 0 , V_21 -> V_29 , V_21 -> V_28 ) ;
if ( V_26 < 0 )
goto V_31;
}
if ( ! V_21 -> V_29 )
return 0 ;
F_9 ( V_21 -> V_32 , L_2 , V_21 -> V_33 ) ;
V_23 = ( void * ) V_21 -> V_29 ;
if ( V_23 -> V_34 != 1 ) {
F_10 ( L_3 ) ;
goto V_31;
}
if ( ! F_11 ( V_23 ) ) {
F_10 ( L_4 ) ;
goto V_31;
}
V_25 = F_12 ( V_23 ) ;
if ( ! F_13 ( V_25 ) ) {
F_10 ( L_5 ) ;
goto V_31;
}
V_21 -> V_17 . V_18 = F_14 ( V_23 ) ;
V_21 -> V_17 . V_19 = F_15 ( V_23 ) ;
F_10 ( L_6 , V_21 -> V_17 . V_18 ) ;
F_10 ( L_7 , V_21 -> V_17 . V_19 ) ;
V_21 -> V_35 = F_16 ( V_21 -> V_17 . V_19 , V_2 ) ;
V_31:
if ( V_27 ) {
F_17 ( V_21 -> V_29 ) ;
V_21 -> V_29 = NULL ;
}
return 0 ;
}
void F_18 ( struct V_9 * V_21 )
{
F_17 ( V_21 -> V_35 ) ;
F_17 ( V_21 -> V_17 . V_18 ) ;
F_17 ( V_21 -> V_17 . V_19 ) ;
}
