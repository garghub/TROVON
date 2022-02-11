static int F_1 ( struct V_1 * V_2 ,
unsigned long V_3 ,
struct V_4 T_1 * V_5 )
{
int V_6 ;
T_2 V_7 ;
V_2 -> V_3 = V_3 ;
V_7 = V_3 * sizeof( * V_5 ) ;
V_6 = F_2 ( V_2 -> V_8 , V_5 , V_7 ) ;
if ( V_6 )
V_6 = - V_9 ;
return V_6 ;
}
static int F_3 ( struct V_1 * * V_10 , unsigned long V_11 ,
unsigned long V_3 ,
struct V_4 T_1 * V_5 ,
unsigned long V_12 )
{
int V_6 ;
struct V_1 * V_2 ;
bool V_13 = V_12 & V_14 ;
if ( V_13 ) {
if ( ( V_11 < F_4 ( V_15 . V_16 ) ) ||
( V_11 > F_4 ( V_15 . V_17 ) ) )
return - V_18 ;
}
V_2 = F_5 () ;
if ( ! V_2 )
return - V_19 ;
V_2 -> V_16 = V_11 ;
V_6 = F_1 ( V_2 , V_3 , V_5 ) ;
if ( V_6 )
goto V_20;
if ( V_13 ) {
V_2 -> V_21 = V_15 . V_16 ;
V_2 -> type = V_22 ;
}
V_6 = F_6 ( V_2 ) ;
if ( V_6 )
goto V_20;
V_6 = - V_19 ;
V_2 -> V_23 = F_7 ( V_2 ,
F_8 ( V_24 ) ) ;
if ( ! V_2 -> V_23 ) {
F_9 ( L_1 ) ;
goto V_20;
}
if ( ! V_13 ) {
V_2 -> V_25 = F_7 ( V_2 , 0 ) ;
if ( ! V_2 -> V_25 ) {
F_9 ( L_2 ) ;
goto V_26;
}
}
* V_10 = V_2 ;
return 0 ;
V_26:
F_10 ( & V_2 -> V_27 ) ;
V_20:
F_11 ( V_2 ) ;
return V_6 ;
}
static int F_12 ( unsigned long V_11 , unsigned long V_3 ,
struct V_4 T_1 * V_5 , unsigned long V_12 )
{
struct V_1 * * V_28 , * V_2 ;
unsigned long V_29 ;
int V_6 ;
if ( V_12 & V_14 ) {
V_28 = & V_30 ;
if ( V_30 )
F_13 () ;
} else {
V_28 = & V_31 ;
}
if ( V_3 == 0 ) {
F_14 ( F_15 ( V_28 , NULL ) ) ;
return 0 ;
}
if ( V_12 & V_14 ) {
F_14 ( F_15 ( & V_30 , NULL ) ) ;
}
V_6 = F_3 ( & V_2 , V_11 , V_3 , V_5 , V_12 ) ;
if ( V_6 )
return V_6 ;
if ( V_12 & V_32 )
V_2 -> V_33 = 1 ;
V_6 = F_16 ( V_2 ) ;
if ( V_6 )
goto V_34;
V_6 = F_17 ( V_2 ) ;
if ( V_6 )
goto V_34;
for ( V_29 = 0 ; V_29 < V_3 ; V_29 ++ ) {
V_6 = F_18 ( V_2 , & V_2 -> V_8 [ V_29 ] ) ;
if ( V_6 )
goto V_34;
}
F_19 ( V_2 ) ;
V_2 = F_15 ( V_28 , V_2 ) ;
V_34:
if ( ( V_12 & V_14 ) && V_30 )
F_20 () ;
F_14 ( V_2 ) ;
return V_6 ;
}
