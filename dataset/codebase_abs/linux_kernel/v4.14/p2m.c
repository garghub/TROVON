static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * * V_4 = & V_5 . V_3 ;
struct V_3 * V_6 = NULL ;
struct V_1 * V_7 ;
int V_8 = 0 ;
while ( * V_4 ) {
V_6 = * V_4 ;
V_7 = F_2 ( V_6 , struct V_1 , V_9 ) ;
if ( V_2 -> V_10 == V_7 -> V_10 )
goto V_11;
if ( V_2 -> V_10 < V_7 -> V_10 )
V_4 = & ( * V_4 ) -> V_12 ;
else
V_4 = & ( * V_4 ) -> V_13 ;
}
F_3 ( & V_2 -> V_9 , V_6 , V_4 ) ;
F_4 ( & V_2 -> V_9 , & V_5 ) ;
goto V_14;
V_11:
V_8 = - V_15 ;
F_5 ( L_1 ,
V_16 , & V_2 -> V_10 , & V_2 -> V_17 , & V_7 -> V_10 , & V_7 -> V_17 ) ;
V_14:
return V_8 ;
}
unsigned long F_6 ( unsigned long V_10 )
{
struct V_3 * V_18 = V_5 . V_3 ;
struct V_1 * V_7 ;
unsigned long V_19 ;
F_7 ( & V_20 , V_19 ) ;
while ( V_18 ) {
V_7 = F_2 ( V_18 , struct V_1 , V_9 ) ;
if ( V_7 -> V_10 <= V_10 &&
V_7 -> V_10 + V_7 -> V_21 > V_10 ) {
F_8 ( & V_20 , V_19 ) ;
return V_7 -> V_17 + ( V_10 - V_7 -> V_10 ) ;
}
if ( V_10 < V_7 -> V_10 )
V_18 = V_18 -> V_12 ;
else
V_18 = V_18 -> V_13 ;
}
F_8 ( & V_20 , V_19 ) ;
return V_22 ;
}
int F_9 ( struct V_23 * V_24 ,
struct V_23 * V_25 ,
struct V_26 * * V_27 , unsigned int V_28 )
{
int V_29 ;
for ( V_29 = 0 ; V_29 < V_28 ; V_29 ++ ) {
if ( V_24 [ V_29 ] . V_30 )
continue;
F_10 ( V_24 [ V_29 ] . V_31 >> V_32 ,
V_24 [ V_29 ] . V_33 >> V_32 ) ;
}
return 0 ;
}
int F_11 ( struct V_34 * V_35 ,
struct V_34 * V_36 ,
struct V_26 * * V_27 , unsigned int V_28 )
{
int V_29 ;
for ( V_29 = 0 ; V_29 < V_28 ; V_29 ++ ) {
F_10 ( V_35 [ V_29 ] . V_31 >> V_32 ,
V_22 ) ;
}
return 0 ;
}
bool F_12 ( unsigned long V_10 ,
unsigned long V_17 , unsigned long V_21 )
{
int V_8 ;
unsigned long V_19 ;
struct V_1 * V_37 ;
struct V_3 * V_18 = V_5 . V_3 ;
if ( V_17 == V_22 ) {
F_13 ( & V_20 , V_19 ) ;
while ( V_18 ) {
V_37 = F_2 ( V_18 , struct V_1 , V_9 ) ;
if ( V_37 -> V_10 <= V_10 &&
V_37 -> V_10 + V_37 -> V_21 > V_10 ) {
F_14 ( & V_37 -> V_9 , & V_5 ) ;
F_15 ( & V_20 , V_19 ) ;
F_16 ( V_37 ) ;
return true ;
}
if ( V_10 < V_37 -> V_10 )
V_18 = V_18 -> V_12 ;
else
V_18 = V_18 -> V_13 ;
}
F_15 ( & V_20 , V_19 ) ;
return true ;
}
V_37 = F_17 ( sizeof( * V_37 ) , V_38 ) ;
if ( ! V_37 )
return false ;
V_37 -> V_10 = V_10 ;
V_37 -> V_21 = V_21 ;
V_37 -> V_17 = V_17 ;
F_13 ( & V_20 , V_19 ) ;
V_8 = F_1 ( V_37 ) ;
if ( V_8 < 0 ) {
F_15 ( & V_20 , V_19 ) ;
return false ;
}
F_15 ( & V_20 , V_19 ) ;
return true ;
}
bool F_18 ( unsigned long V_10 , unsigned long V_17 )
{
return F_12 ( V_10 , V_17 , 1 ) ;
}
static int F_19 ( void )
{
F_20 ( & V_20 ) ;
return 0 ;
}
