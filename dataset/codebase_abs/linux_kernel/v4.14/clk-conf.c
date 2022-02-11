static int F_1 ( struct V_1 * V_2 , bool V_3 )
{
struct V_4 V_5 ;
int V_6 , V_7 , V_8 ;
struct V_9 * V_9 , * V_10 ;
V_8 = F_2 ( V_2 , L_1 ,
L_2 ) ;
if ( V_8 == - V_11 )
F_3 ( L_3 ,
V_2 ) ;
for ( V_6 = 0 ; V_6 < V_8 ; V_6 ++ ) {
V_7 = F_4 ( V_2 , L_1 ,
L_2 , V_6 , & V_5 ) ;
if ( V_7 < 0 ) {
if ( V_7 == - V_12 )
continue;
else
return V_7 ;
}
if ( V_5 . V_13 == V_2 && ! V_3 )
return 0 ;
V_10 = F_5 ( & V_5 ) ;
if ( F_6 ( V_10 ) ) {
if ( F_7 ( V_10 ) != - V_14 )
F_8 ( L_4 ,
V_6 , V_2 ) ;
return F_7 ( V_10 ) ;
}
V_7 = F_4 ( V_2 , L_5 ,
L_2 , V_6 , & V_5 ) ;
if ( V_7 < 0 )
goto V_15;
if ( V_5 . V_13 == V_2 && ! V_3 ) {
V_7 = 0 ;
goto V_15;
}
V_9 = F_5 ( & V_5 ) ;
if ( F_6 ( V_9 ) ) {
if ( F_7 ( V_9 ) != - V_14 )
F_8 ( L_6 ,
V_6 , V_2 ) ;
V_7 = F_7 ( V_9 ) ;
goto V_15;
}
V_7 = F_9 ( V_9 , V_10 ) ;
if ( V_7 < 0 )
F_3 ( L_7 ,
F_10 ( V_9 ) , F_10 ( V_10 ) , V_7 ) ;
F_11 ( V_9 ) ;
F_11 ( V_10 ) ;
}
return 0 ;
V_15:
F_11 ( V_10 ) ;
return V_7 ;
}
static int F_12 ( struct V_1 * V_2 , bool V_3 )
{
struct V_4 V_5 ;
struct V_16 * V_17 ;
const T_1 * V_18 ;
int V_7 , V_6 = 0 ;
struct V_9 * V_9 ;
T_2 V_19 ;
F_13 (node, L_8 , prop, cur, rate) {
if ( V_19 ) {
V_7 = F_4 ( V_2 , L_5 ,
L_2 , V_6 , & V_5 ) ;
if ( V_7 < 0 ) {
if ( V_7 == - V_12 )
continue;
else
return V_7 ;
}
if ( V_5 . V_13 == V_2 && ! V_3 )
return 0 ;
V_9 = F_5 ( & V_5 ) ;
if ( F_6 ( V_9 ) ) {
if ( F_7 ( V_9 ) != - V_14 )
F_8 ( L_9 ,
V_6 , V_2 ) ;
return F_7 ( V_9 ) ;
}
V_7 = F_14 ( V_9 , V_19 ) ;
if ( V_7 < 0 )
F_3 ( L_10 ,
F_10 ( V_9 ) , V_19 , V_7 ,
F_15 ( V_9 ) ) ;
F_11 ( V_9 ) ;
}
V_6 ++ ;
}
return 0 ;
}
int F_16 ( struct V_1 * V_2 , bool V_3 )
{
int V_7 ;
if ( ! V_2 )
return 0 ;
V_7 = F_1 ( V_2 , V_3 ) ;
if ( V_7 < 0 )
return V_7 ;
return F_12 ( V_2 , V_3 ) ;
}
