static struct V_1 * F_1 ( struct V_2 * V_3 ,
unsigned int V_4 )
{
unsigned int V_5 ;
for ( V_5 = 0 ; V_5 < V_3 -> V_6 ; V_5 ++ ) {
if ( V_3 -> V_7 [ V_5 ] . V_4 == V_4 )
return & V_3 -> V_7 [ V_5 ] ;
}
return NULL ;
}
void F_2 ( struct V_2 * V_3 )
{
struct V_1 * V_8 ;
if ( ! V_3 -> V_9 )
goto V_10;
if ( V_3 -> V_4 == 0 )
return;
V_8 = F_1 ( V_3 , V_3 -> V_4 ) ;
if ( ! V_8 ) {
F_3 ( V_3 -> V_11 ,
L_1 ,
V_3 -> V_4 ) ;
goto V_10;
}
if ( V_8 != V_3 -> V_12 ) {
F_4 ( & V_3 -> V_12 -> V_13 , V_14 ) ;
F_4 ( & V_8 -> V_13 , V_15 ) ;
V_3 -> V_12 = V_8 ;
}
return;
V_10:
if ( V_3 -> V_12 ) {
F_4 ( & V_3 -> V_12 -> V_13 ,
V_14 ) ;
V_3 -> V_12 = NULL ;
}
}
static int F_5 ( struct V_2 * V_3 ,
struct V_1 * V_8 ,
unsigned int V_4 )
{
char V_16 [ V_17 ] ;
V_8 -> V_4 = V_4 ;
if ( V_4 < V_18 )
snprintf ( V_16 , sizeof( V_16 ) , L_2 , V_4 ) ;
else if ( V_4 == V_19 )
snprintf ( V_16 , sizeof( V_16 ) , L_3 ) ;
else
snprintf ( V_16 , sizeof( V_16 ) , L_4 ,
F_6 ( V_4 , 1000 ) ) ;
snprintf ( V_8 -> V_20 , sizeof( V_8 -> V_20 ) , V_21 L_5 ,
V_3 -> V_22 . V_23 -> V_24 , V_3 -> V_22 . V_25 , V_16 ) ;
V_8 -> V_13 . V_20 = V_8 -> V_20 ;
return F_7 ( & V_8 -> V_13 ) ;
}
static void F_8 ( struct V_1 * V_8 )
{
F_9 ( & V_8 -> V_13 ) ;
}
int F_10 ( struct V_2 * V_3 )
{
int V_5 , V_26 ;
unsigned int V_27 [ 50 ] ;
V_3 -> V_6 = F_11 ( V_3 , V_27 ,
F_12 ( V_27 ) ) ;
if ( ! V_3 -> V_6 )
return 0 ;
V_3 -> V_7 = F_13 ( & V_3 -> V_22 . V_28 ,
sizeof( struct V_1 ) *
V_3 -> V_6 ,
V_29 ) ;
if ( ! V_3 -> V_7 ) {
V_26 = - V_30 ;
goto V_31;
}
for ( V_5 = 0 ; V_5 < V_3 -> V_6 ; V_5 ++ ) {
V_26 = F_5 ( V_3 , & V_3 -> V_7 [ V_5 ] ,
V_27 [ V_5 ] ) ;
if ( V_26 )
goto V_32;
}
V_3 -> V_12 = NULL ;
F_2 ( V_3 ) ;
return 0 ;
V_32:
while ( V_5 -- )
F_8 ( & V_3 -> V_7 [ V_5 ] ) ;
F_14 ( & V_3 -> V_22 . V_28 , V_3 -> V_7 ) ;
V_31:
V_3 -> V_6 = 0 ;
return V_26 ;
}
void F_15 ( struct V_2 * V_3 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < V_3 -> V_6 ; V_5 ++ )
F_8 ( & V_3 -> V_7 [ V_5 ] ) ;
}
