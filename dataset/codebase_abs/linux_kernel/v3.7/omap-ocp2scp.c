static unsigned F_1 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
while ( V_2 -> V_4 != V_2 -> V_5 ) {
V_3 ++ ;
V_2 ++ ;
}
return V_3 ;
}
static int F_2 ( struct V_6 * V_7 , void * V_8 )
{
struct V_9 * V_10 = F_3 ( V_7 ) ;
F_4 ( V_10 ) ;
return 0 ;
}
static int T_1 F_5 ( struct V_9 * V_10 )
{
int V_11 ;
unsigned V_12 , V_13 ;
struct V_14 * V_15 = V_10 -> V_7 . V_16 ;
struct V_9 * V_17 ;
struct V_18 * V_19 = V_10 -> V_7 . V_20 ;
struct V_21 * V_7 ;
if ( V_15 ) {
V_11 = F_6 ( V_15 , NULL , NULL , & V_10 -> V_7 ) ;
if ( V_11 ) {
F_7 ( & V_10 -> V_7 ,
L_1 ) ;
goto V_22;
}
} else if ( V_19 ) {
for ( V_13 = 0 , V_7 = * V_19 -> V_23 ; V_13 < V_19 -> V_24 ; V_13 ++ ,
V_7 ++ ) {
V_12 = F_1 ( V_7 -> V_2 ) ;
V_17 = F_8 ( V_7 -> V_25 ,
V_26 ) ;
if ( ! V_17 ) {
F_7 ( & V_10 -> V_7 ,
L_2 ) ;
goto V_22;
}
V_11 = F_9 ( V_17 ,
V_7 -> V_2 , V_12 ) ;
if ( V_11 ) {
F_7 ( & V_10 -> V_7 ,
L_1 ) ;
goto V_27;
}
V_17 -> V_7 . V_28 = & V_10 -> V_7 ;
V_11 = F_10 ( V_17 ) ;
if ( V_11 ) {
F_7 ( & V_10 -> V_7 ,
L_3 ) ;
goto V_27;
}
}
} else {
F_7 ( & V_10 -> V_7 , L_4 ) ;
return - V_29 ;
}
F_11 ( & V_10 -> V_7 ) ;
return 0 ;
V_27:
F_12 ( V_17 ) ;
V_22:
F_13 ( & V_10 -> V_7 , NULL , F_2 ) ;
return V_11 ;
}
static int T_2 F_14 ( struct V_9 * V_10 )
{
F_15 ( & V_10 -> V_7 ) ;
F_13 ( & V_10 -> V_7 , NULL , F_2 ) ;
return 0 ;
}
