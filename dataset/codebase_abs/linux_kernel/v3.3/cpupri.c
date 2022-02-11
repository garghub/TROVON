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
if ( V_14 >= V_6 )
return 0 ;
for ( V_13 = 0 ; V_13 < V_14 ; V_13 ++ ) {
struct V_15 * V_16 = & V_8 -> V_17 [ V_13 ] ;
int V_18 = 0 ;
if ( ! F_3 ( & ( V_16 ) -> V_19 ) )
V_18 = 1 ;
F_4 () ;
if ( V_18 )
continue;
if ( F_5 ( & V_10 -> V_20 , V_16 -> V_21 ) >= V_22 )
continue;
if ( V_12 ) {
F_6 ( V_12 , & V_10 -> V_20 , V_16 -> V_21 ) ;
if ( F_7 ( V_12 ) >= V_22 )
continue;
}
return 1 ;
}
return 0 ;
}
void F_8 ( struct V_2 * V_8 , int V_23 , int V_24 )
{
int * V_25 = & V_8 -> V_26 [ V_23 ] ;
int V_27 = * V_25 ;
int V_28 = 0 ;
V_24 = F_1 ( V_24 ) ;
F_9 ( V_24 >= V_29 ) ;
if ( V_24 == V_27 )
return;
if ( F_10 ( V_24 != V_3 ) ) {
struct V_15 * V_16 = & V_8 -> V_17 [ V_24 ] ;
F_11 ( V_23 , V_16 -> V_21 ) ;
F_12 () ;
F_13 ( & ( V_16 ) -> V_19 ) ;
V_28 = 1 ;
}
if ( F_10 ( V_27 != V_3 ) ) {
struct V_15 * V_16 = & V_8 -> V_17 [ V_27 ] ;
if ( V_28 )
F_14 () ;
F_15 ( & ( V_16 ) -> V_19 ) ;
F_14 () ;
F_16 ( V_23 , V_16 -> V_21 ) ;
}
* V_25 = V_24 ;
}
int F_17 ( struct V_2 * V_8 )
{
int V_30 ;
memset ( V_8 , 0 , sizeof( * V_8 ) ) ;
for ( V_30 = 0 ; V_30 < V_29 ; V_30 ++ ) {
struct V_15 * V_16 = & V_8 -> V_17 [ V_30 ] ;
F_18 ( & V_16 -> V_19 , 0 ) ;
if ( ! F_19 ( & V_16 -> V_21 , V_31 ) )
goto V_32;
}
F_20 (i)
V_8 -> V_26 [ V_30 ] = V_3 ;
return 0 ;
V_32:
for ( V_30 -- ; V_30 >= 0 ; V_30 -- )
F_21 ( V_8 -> V_17 [ V_30 ] . V_21 ) ;
return - V_33 ;
}
void F_22 ( struct V_2 * V_8 )
{
int V_30 ;
for ( V_30 = 0 ; V_30 < V_29 ; V_30 ++ )
F_21 ( V_8 -> V_17 [ V_30 ] . V_21 ) ;
}
