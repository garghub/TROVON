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
if ( F_6 ( & V_10 -> V_21 , V_17 -> V_22 ) >= V_23 )
continue;
if ( V_12 ) {
F_7 ( V_12 , & V_10 -> V_21 , V_17 -> V_22 ) ;
if ( F_8 ( V_12 ) >= V_23 )
continue;
}
return 1 ;
}
return 0 ;
}
void F_9 ( struct V_2 * V_8 , int V_24 , int V_25 )
{
int * V_26 = & V_8 -> V_27 [ V_24 ] ;
int V_28 = * V_26 ;
int V_29 = 0 ;
V_25 = F_1 ( V_25 ) ;
F_3 ( V_25 >= V_15 ) ;
if ( V_25 == V_28 )
return;
if ( F_10 ( V_25 != V_3 ) ) {
struct V_16 * V_17 = & V_8 -> V_18 [ V_25 ] ;
F_11 ( V_24 , V_17 -> V_22 ) ;
F_12 () ;
F_13 ( & ( V_17 ) -> V_20 ) ;
V_29 = 1 ;
}
if ( F_10 ( V_28 != V_3 ) ) {
struct V_16 * V_17 = & V_8 -> V_18 [ V_28 ] ;
if ( V_29 )
F_14 () ;
F_15 ( & ( V_17 ) -> V_20 ) ;
F_14 () ;
F_16 ( V_24 , V_17 -> V_22 ) ;
}
* V_26 = V_25 ;
}
int F_17 ( struct V_2 * V_8 )
{
int V_30 ;
memset ( V_8 , 0 , sizeof( * V_8 ) ) ;
for ( V_30 = 0 ; V_30 < V_15 ; V_30 ++ ) {
struct V_16 * V_17 = & V_8 -> V_18 [ V_30 ] ;
F_18 ( & V_17 -> V_20 , 0 ) ;
if ( ! F_19 ( & V_17 -> V_22 , V_31 ) )
goto V_32;
}
V_8 -> V_27 = F_20 ( V_23 , sizeof( int ) , V_31 ) ;
if ( ! V_8 -> V_27 )
goto V_32;
F_21 (i)
V_8 -> V_27 [ V_30 ] = V_3 ;
return 0 ;
V_32:
for ( V_30 -- ; V_30 >= 0 ; V_30 -- )
F_22 ( V_8 -> V_18 [ V_30 ] . V_22 ) ;
return - V_33 ;
}
void F_23 ( struct V_2 * V_8 )
{
int V_30 ;
F_24 ( V_8 -> V_27 ) ;
for ( V_30 = 0 ; V_30 < V_15 ; V_30 ++ )
F_22 ( V_8 -> V_18 [ V_30 ] . V_22 ) ;
}
