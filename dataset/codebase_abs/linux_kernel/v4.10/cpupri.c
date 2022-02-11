static int F_1 ( int V_1 )
{
int V_2 ;
if ( V_1 == V_3 )
V_2 = V_3 ;
else if ( V_1 == V_4 )
V_2 = V_5 ;
else if ( V_1 >= V_6 )
V_2 = V_7 ;
else
V_2 = V_6 - V_1 + 1 ;
return V_2 ;
}
int F_2 ( struct V_2 * V_8 , struct V_9 * V_10 ,
struct V_11 * V_12 )
{
int V_13 = 0 ;
int V_14 = F_1 ( V_10 -> V_1 ) ;
F_3 ( V_14 >= V_15 ) ;
for ( V_13 = 0 ; V_13 < V_14 ; V_13 ++ ) {
struct V_16 * V_17 = & V_8 -> V_18 [ V_13 ] ;
int V_19 = 0 ;
if ( ! F_4 ( & ( V_17 ) -> V_20 ) )
V_19 = 1 ;
F_5 () ;
if ( V_19 )
continue;
if ( F_6 ( F_7 ( V_10 ) , V_17 -> V_21 ) >= V_22 )
continue;
if ( V_12 ) {
F_8 ( V_12 , F_7 ( V_10 ) , V_17 -> V_21 ) ;
if ( F_9 ( V_12 ) >= V_22 )
continue;
}
return 1 ;
}
return 0 ;
}
void F_10 ( struct V_2 * V_8 , int V_23 , int V_24 )
{
int * V_25 = & V_8 -> V_26 [ V_23 ] ;
int V_27 = * V_25 ;
int V_28 = 0 ;
V_24 = F_1 ( V_24 ) ;
F_3 ( V_24 >= V_15 ) ;
if ( V_24 == V_27 )
return;
if ( F_11 ( V_24 != V_3 ) ) {
struct V_16 * V_17 = & V_8 -> V_18 [ V_24 ] ;
F_12 ( V_23 , V_17 -> V_21 ) ;
F_13 () ;
F_14 ( & ( V_17 ) -> V_20 ) ;
V_28 = 1 ;
}
if ( F_11 ( V_27 != V_3 ) ) {
struct V_16 * V_17 = & V_8 -> V_18 [ V_27 ] ;
if ( V_28 )
F_15 () ;
F_16 ( & ( V_17 ) -> V_20 ) ;
F_15 () ;
F_17 ( V_23 , V_17 -> V_21 ) ;
}
* V_25 = V_24 ;
}
int F_18 ( struct V_2 * V_8 )
{
int V_29 ;
memset ( V_8 , 0 , sizeof( * V_8 ) ) ;
for ( V_29 = 0 ; V_29 < V_15 ; V_29 ++ ) {
struct V_16 * V_17 = & V_8 -> V_18 [ V_29 ] ;
F_19 ( & V_17 -> V_20 , 0 ) ;
if ( ! F_20 ( & V_17 -> V_21 , V_30 ) )
goto V_31;
}
V_8 -> V_26 = F_21 ( V_22 , sizeof( int ) , V_30 ) ;
if ( ! V_8 -> V_26 )
goto V_31;
F_22 (i)
V_8 -> V_26 [ V_29 ] = V_3 ;
return 0 ;
V_31:
for ( V_29 -- ; V_29 >= 0 ; V_29 -- )
F_23 ( V_8 -> V_18 [ V_29 ] . V_21 ) ;
return - V_32 ;
}
void F_24 ( struct V_2 * V_8 )
{
int V_29 ;
F_25 ( V_8 -> V_26 ) ;
for ( V_29 = 0 ; V_29 < V_15 ; V_29 ++ )
F_23 ( V_8 -> V_18 [ V_29 ] . V_21 ) ;
}
