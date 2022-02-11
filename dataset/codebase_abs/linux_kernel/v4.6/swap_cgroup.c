static int F_1 ( int type )
{
struct V_1 * V_1 ;
struct V_2 * V_3 ;
unsigned long V_4 , V_5 ;
V_3 = & V_2 [ type ] ;
for ( V_4 = 0 ; V_4 < V_3 -> V_6 ; V_4 ++ ) {
V_1 = F_2 ( V_7 | V_8 ) ;
if ( ! V_1 )
goto V_9;
V_3 -> V_10 [ V_4 ] = V_1 ;
}
return 0 ;
V_9:
V_5 = V_4 ;
for ( V_4 = 0 ; V_4 < V_5 ; V_4 ++ )
F_3 ( V_3 -> V_10 [ V_4 ] ) ;
return - V_11 ;
}
static struct V_12 * F_4 ( T_1 V_13 ,
struct V_2 * * V_14 )
{
T_2 V_15 = F_5 ( V_13 ) ;
struct V_2 * V_3 ;
struct V_1 * V_16 ;
struct V_12 * V_17 ;
V_3 = & V_2 [ F_6 ( V_13 ) ] ;
if ( V_14 )
* V_14 = V_3 ;
V_16 = V_3 -> V_10 [ V_15 / V_18 ] ;
V_17 = F_7 ( V_16 ) ;
return V_17 + V_15 % V_18 ;
}
unsigned short F_8 ( T_1 V_13 ,
unsigned short V_19 , unsigned short V_20 )
{
struct V_2 * V_3 ;
struct V_12 * V_17 ;
unsigned long V_21 ;
unsigned short V_22 ;
V_17 = F_4 ( V_13 , & V_3 ) ;
F_9 ( & V_3 -> V_23 , V_21 ) ;
V_22 = V_17 -> V_24 ;
if ( V_22 == V_19 )
V_17 -> V_24 = V_20 ;
else
V_22 = 0 ;
F_10 ( & V_3 -> V_23 , V_21 ) ;
return V_22 ;
}
unsigned short F_11 ( T_1 V_13 , unsigned short V_24 )
{
struct V_2 * V_3 ;
struct V_12 * V_17 ;
unsigned short V_19 ;
unsigned long V_21 ;
V_17 = F_4 ( V_13 , & V_3 ) ;
F_9 ( & V_3 -> V_23 , V_21 ) ;
V_19 = V_17 -> V_24 ;
V_17 -> V_24 = V_24 ;
F_10 ( & V_3 -> V_23 , V_21 ) ;
return V_19 ;
}
unsigned short F_12 ( T_1 V_13 )
{
return F_4 ( V_13 , NULL ) -> V_24 ;
}
int F_13 ( int type , unsigned long V_25 )
{
void * V_26 ;
unsigned long V_27 ;
unsigned long V_6 ;
struct V_2 * V_3 ;
if ( ! V_28 )
return 0 ;
V_6 = F_14 ( V_25 , V_18 ) ;
V_27 = V_6 * sizeof( void * ) ;
V_26 = F_15 ( V_27 ) ;
if ( ! V_26 )
goto V_29;
V_3 = & V_2 [ type ] ;
F_16 ( & V_30 ) ;
V_3 -> V_6 = V_6 ;
V_3 -> V_10 = V_26 ;
F_17 ( & V_3 -> V_23 ) ;
if ( F_1 ( type ) ) {
V_3 -> V_10 = NULL ;
V_3 -> V_6 = 0 ;
F_18 ( & V_30 ) ;
F_19 ( V_26 ) ;
goto V_29;
}
F_18 ( & V_30 ) ;
return 0 ;
V_29:
F_20 ( L_1 ) ;
F_20 ( L_2 ) ;
return - V_11 ;
}
void F_21 ( int type )
{
struct V_1 * * V_10 ;
unsigned long V_31 , V_6 ;
struct V_2 * V_3 ;
if ( ! V_28 )
return;
F_16 ( & V_30 ) ;
V_3 = & V_2 [ type ] ;
V_10 = V_3 -> V_10 ;
V_6 = V_3 -> V_6 ;
V_3 -> V_10 = NULL ;
V_3 -> V_6 = 0 ;
F_18 ( & V_30 ) ;
if ( V_10 ) {
for ( V_31 = 0 ; V_31 < V_6 ; V_31 ++ ) {
struct V_1 * V_1 = V_10 [ V_31 ] ;
if ( V_1 )
F_3 ( V_1 ) ;
}
F_19 ( V_10 ) ;
}
}
