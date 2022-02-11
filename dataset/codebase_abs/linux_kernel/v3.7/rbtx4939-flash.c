static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
V_4 = F_2 ( V_2 ) ;
if ( ! V_4 )
return 0 ;
F_3 ( V_2 , NULL ) ;
if ( V_4 -> V_5 ) {
struct V_6 * V_7 = V_2 -> V_2 . V_8 ;
F_4 ( V_4 -> V_5 ) ;
F_5 ( V_4 -> V_5 ) ;
}
return 0 ;
}
static int F_6 ( struct V_1 * V_2 )
{
struct V_6 * V_7 ;
struct V_3 * V_4 ;
struct V_9 * V_10 ;
const char * * V_11 ;
int V_12 = 0 ;
unsigned long V_13 ;
V_7 = V_2 -> V_2 . V_8 ;
if ( ! V_7 )
return - V_14 ;
V_10 = F_7 ( V_2 , V_15 , 0 ) ;
if ( ! V_10 )
return - V_14 ;
V_4 = F_8 ( & V_2 -> V_2 , sizeof( struct V_3 ) ,
V_16 ) ;
if ( ! V_4 )
return - V_17 ;
F_3 ( V_2 , V_4 ) ;
V_13 = F_9 ( V_10 ) ;
F_10 ( L_1 , V_10 ) ;
if ( ! F_11 ( & V_2 -> V_2 , V_10 -> V_18 , V_13 ,
F_12 ( & V_2 -> V_2 ) ) )
return - V_19 ;
V_4 -> V_20 . V_21 = F_12 ( & V_2 -> V_2 ) ;
V_4 -> V_20 . V_22 = V_10 -> V_18 ;
V_4 -> V_20 . V_13 = V_13 ;
V_4 -> V_20 . V_23 = V_7 -> V_24 ;
V_4 -> V_20 . V_25 = F_13 ( & V_2 -> V_2 , V_4 -> V_20 . V_22 , V_13 ) ;
if ( ! V_4 -> V_20 . V_25 )
return - V_19 ;
if ( V_7 -> V_26 )
(* V_7 -> V_26 )( & V_4 -> V_20 ) ;
else
F_14 ( & V_4 -> V_20 ) ;
V_11 = V_27 ;
for (; ! V_4 -> V_5 && * V_11 ; V_11 ++ )
V_4 -> V_5 = F_15 ( * V_11 , & V_4 -> V_20 ) ;
if ( ! V_4 -> V_5 ) {
F_16 ( & V_2 -> V_2 , L_2 ) ;
V_12 = - V_28 ;
goto V_29;
}
V_4 -> V_5 -> V_30 = V_31 ;
V_12 = F_17 ( V_4 -> V_5 , NULL , NULL , V_7 -> V_32 ,
V_7 -> V_33 ) ;
if ( V_12 )
goto V_29;
return 0 ;
V_29:
F_1 ( V_2 ) ;
return V_12 ;
}
static void F_18 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( F_19 ( V_4 -> V_5 ) == 0 )
F_20 ( V_4 -> V_5 ) ;
}
