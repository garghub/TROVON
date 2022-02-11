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
if ( V_2 -> V_12 == V_7 -> V_12 )
goto V_11;
if ( V_2 -> V_12 < V_7 -> V_12 )
V_4 = & ( * V_4 ) -> V_13 ;
else
V_4 = & ( * V_4 ) -> V_14 ;
}
F_3 ( & V_2 -> V_9 , V_6 , V_4 ) ;
F_4 ( & V_2 -> V_9 , & V_5 ) ;
goto V_15;
V_11:
V_8 = - V_16 ;
F_5 ( L_1 ,
V_17 , & V_2 -> V_12 , & V_2 -> V_10 , & V_7 -> V_12 , & V_7 -> V_10 ) ;
V_15:
return V_8 ;
}
unsigned long F_6 ( unsigned long V_12 )
{
struct V_3 * V_18 = V_5 . V_3 ;
struct V_1 * V_7 ;
unsigned long V_19 ;
F_7 ( & V_20 , V_19 ) ;
while ( V_18 ) {
V_7 = F_2 ( V_18 , struct V_1 , V_9 ) ;
if ( V_7 -> V_12 <= V_12 &&
V_7 -> V_12 + V_7 -> V_21 > V_12 ) {
F_8 ( & V_20 , V_19 ) ;
return V_7 -> V_10 + ( V_12 - V_7 -> V_12 ) ;
}
if ( V_12 < V_7 -> V_12 )
V_18 = V_18 -> V_13 ;
else
V_18 = V_18 -> V_14 ;
}
F_8 ( & V_20 , V_19 ) ;
return V_22 ;
}
static int F_9 ( struct V_1 * V_2 )
{
struct V_3 * * V_4 = & V_23 . V_3 ;
struct V_3 * V_6 = NULL ;
struct V_1 * V_7 ;
int V_8 = 0 ;
while ( * V_4 ) {
V_6 = * V_4 ;
V_7 = F_2 ( V_6 , struct V_1 , V_24 ) ;
if ( V_2 -> V_10 == V_7 -> V_10 )
goto V_11;
if ( V_2 -> V_12 == V_7 -> V_12 )
goto V_11;
if ( V_2 -> V_10 < V_7 -> V_10 )
V_4 = & ( * V_4 ) -> V_13 ;
else
V_4 = & ( * V_4 ) -> V_14 ;
}
F_3 ( & V_2 -> V_24 , V_6 , V_4 ) ;
F_4 ( & V_2 -> V_24 , & V_23 ) ;
goto V_15;
V_11:
V_8 = - V_16 ;
F_5 ( L_1 ,
V_17 , & V_2 -> V_12 , & V_2 -> V_10 , & V_7 -> V_12 , & V_7 -> V_10 ) ;
V_15:
return V_8 ;
}
unsigned long F_10 ( unsigned long V_10 )
{
struct V_3 * V_18 = V_23 . V_3 ;
struct V_1 * V_7 ;
unsigned long V_19 ;
F_7 ( & V_20 , V_19 ) ;
while ( V_18 ) {
V_7 = F_2 ( V_18 , struct V_1 , V_24 ) ;
if ( V_7 -> V_10 <= V_10 &&
V_7 -> V_10 + V_7 -> V_21 > V_10 ) {
F_8 ( & V_20 , V_19 ) ;
return V_7 -> V_12 + ( V_10 - V_7 -> V_10 ) ;
}
if ( V_10 < V_7 -> V_10 )
V_18 = V_18 -> V_13 ;
else
V_18 = V_18 -> V_14 ;
}
F_8 ( & V_20 , V_19 ) ;
return V_22 ;
}
bool F_11 ( unsigned long V_12 ,
unsigned long V_10 , unsigned long V_21 )
{
int V_8 ;
unsigned long V_19 ;
struct V_1 * V_25 ;
struct V_3 * V_18 = V_5 . V_3 ;
if ( V_10 == V_22 ) {
F_12 ( & V_20 , V_19 ) ;
while ( V_18 ) {
V_25 = F_2 ( V_18 , struct V_1 , V_9 ) ;
if ( V_25 -> V_12 <= V_12 &&
V_25 -> V_12 + V_25 -> V_21 > V_12 ) {
F_13 ( & V_25 -> V_24 , & V_23 ) ;
F_13 ( & V_25 -> V_9 , & V_5 ) ;
F_14 ( & V_20 , V_19 ) ;
F_15 ( V_25 ) ;
return true ;
}
if ( V_12 < V_25 -> V_12 )
V_18 = V_18 -> V_13 ;
else
V_18 = V_18 -> V_14 ;
}
F_14 ( & V_20 , V_19 ) ;
return true ;
}
V_25 = F_16 ( sizeof( struct V_1 ) , V_26 ) ;
if ( ! V_25 ) {
F_5 ( L_2 ) ;
return false ;
}
V_25 -> V_12 = V_12 ;
V_25 -> V_21 = V_21 ;
V_25 -> V_10 = V_10 ;
F_12 ( & V_20 , V_19 ) ;
if ( ( V_8 = F_1 ( V_25 ) < 0 ) ||
( V_8 = F_9 ( V_25 ) < 0 ) ) {
F_14 ( & V_20 , V_19 ) ;
return false ;
}
F_14 ( & V_20 , V_19 ) ;
return true ;
}
bool F_17 ( unsigned long V_12 , unsigned long V_10 )
{
return F_11 ( V_12 , V_10 , 1 ) ;
}
static int F_18 ( void )
{
F_19 ( & V_20 ) ;
return 0 ;
}
