static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
V_4 = F_2 ( V_2 ) ;
if ( ! V_4 )
return 0 ;
if ( V_4 -> V_5 ) {
struct V_6 * V_7 = F_3 ( & V_2 -> V_2 ) ;
F_4 ( V_4 -> V_5 ) ;
F_5 ( V_4 -> V_5 ) ;
}
return 0 ;
}
static int F_6 ( struct V_1 * V_2 )
{
struct V_6 * V_7 ;
struct V_3 * V_4 ;
struct V_8 * V_9 ;
const char * const * V_10 ;
int V_11 = 0 ;
unsigned long V_12 ;
V_7 = F_3 ( & V_2 -> V_2 ) ;
if ( ! V_7 )
return - V_13 ;
V_9 = F_7 ( V_2 , V_14 , 0 ) ;
if ( ! V_9 )
return - V_13 ;
V_4 = F_8 ( & V_2 -> V_2 , sizeof( struct V_3 ) ,
V_15 ) ;
if ( ! V_4 )
return - V_16 ;
F_9 ( V_2 , V_4 ) ;
V_12 = F_10 ( V_9 ) ;
F_11 ( L_1 , V_9 ) ;
if ( ! F_12 ( & V_2 -> V_2 , V_9 -> V_17 , V_12 ,
F_13 ( & V_2 -> V_2 ) ) )
return - V_18 ;
V_4 -> V_19 . V_20 = F_13 ( & V_2 -> V_2 ) ;
V_4 -> V_19 . V_21 = V_9 -> V_17 ;
V_4 -> V_19 . V_12 = V_12 ;
V_4 -> V_19 . V_22 = V_7 -> V_23 ;
V_4 -> V_19 . V_24 = F_14 ( & V_2 -> V_2 , V_4 -> V_19 . V_21 , V_12 ) ;
if ( ! V_4 -> V_19 . V_24 )
return - V_18 ;
if ( V_7 -> V_25 )
(* V_7 -> V_25 )( & V_4 -> V_19 ) ;
else
F_15 ( & V_4 -> V_19 ) ;
V_10 = V_26 ;
for (; ! V_4 -> V_5 && * V_10 ; V_10 ++ )
V_4 -> V_5 = F_16 ( * V_10 , & V_4 -> V_19 ) ;
if ( ! V_4 -> V_5 ) {
F_17 ( & V_2 -> V_2 , L_2 ) ;
V_11 = - V_27 ;
goto V_28;
}
V_4 -> V_5 -> V_29 = V_30 ;
V_11 = F_18 ( V_4 -> V_5 , NULL , NULL , V_7 -> V_31 ,
V_7 -> V_32 ) ;
if ( V_11 )
goto V_28;
return 0 ;
V_28:
F_1 ( V_2 ) ;
return V_11 ;
}
static void F_19 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( F_20 ( V_4 -> V_5 ) == 0 )
F_21 ( V_4 -> V_5 ) ;
}
