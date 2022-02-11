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
F_3 (cp->pri_active, idx) {
struct V_15 * V_16 = & V_8 -> V_17 [ V_13 ] ;
if ( V_13 >= V_14 )
break;
if ( F_4 ( & V_10 -> V_18 , V_16 -> V_19 ) >= V_20 )
continue;
if ( V_12 ) {
F_5 ( V_12 , & V_10 -> V_18 , V_16 -> V_19 ) ;
if ( F_6 ( V_12 ) >= V_20 )
continue;
}
return 1 ;
}
return 0 ;
}
void F_7 ( struct V_2 * V_8 , int V_21 , int V_22 )
{
int * V_23 = & V_8 -> V_24 [ V_21 ] ;
int V_25 = * V_23 ;
unsigned long V_26 ;
V_22 = F_1 ( V_22 ) ;
F_8 ( V_22 >= V_27 ) ;
if ( V_22 == V_25 )
return;
if ( F_9 ( V_22 != V_3 ) ) {
struct V_15 * V_16 = & V_8 -> V_17 [ V_22 ] ;
F_10 ( & V_16 -> V_28 , V_26 ) ;
F_11 ( V_21 , V_16 -> V_19 ) ;
V_16 -> V_29 ++ ;
if ( V_16 -> V_29 == 1 )
F_12 ( V_22 , V_8 -> V_30 ) ;
F_13 ( & V_16 -> V_28 , V_26 ) ;
}
if ( F_9 ( V_25 != V_3 ) ) {
struct V_15 * V_16 = & V_8 -> V_17 [ V_25 ] ;
F_10 ( & V_16 -> V_28 , V_26 ) ;
V_16 -> V_29 -- ;
if ( ! V_16 -> V_29 )
F_14 ( V_25 , V_8 -> V_30 ) ;
F_15 ( V_21 , V_16 -> V_19 ) ;
F_13 ( & V_16 -> V_28 , V_26 ) ;
}
* V_23 = V_22 ;
}
int F_16 ( struct V_2 * V_8 )
{
int V_31 ;
memset ( V_8 , 0 , sizeof( * V_8 ) ) ;
for ( V_31 = 0 ; V_31 < V_27 ; V_31 ++ ) {
struct V_15 * V_16 = & V_8 -> V_17 [ V_31 ] ;
F_17 ( & V_16 -> V_28 ) ;
V_16 -> V_29 = 0 ;
if ( ! F_18 ( & V_16 -> V_19 , V_32 ) )
goto V_33;
}
F_19 (i)
V_8 -> V_24 [ V_31 ] = V_3 ;
return 0 ;
V_33:
for ( V_31 -- ; V_31 >= 0 ; V_31 -- )
F_20 ( V_8 -> V_17 [ V_31 ] . V_19 ) ;
return - V_34 ;
}
void F_21 ( struct V_2 * V_8 )
{
int V_31 ;
for ( V_31 = 0 ; V_31 < V_27 ; V_31 ++ )
F_20 ( V_8 -> V_17 [ V_31 ] . V_19 ) ;
}
