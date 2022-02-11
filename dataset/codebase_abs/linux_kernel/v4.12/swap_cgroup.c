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
if ( ! ( V_4 % V_11 ) )
F_3 () ;
}
return 0 ;
V_9:
V_5 = V_4 ;
for ( V_4 = 0 ; V_4 < V_5 ; V_4 ++ )
F_4 ( V_3 -> V_10 [ V_4 ] ) ;
return - V_12 ;
}
static struct V_13 * F_5 ( T_1 V_14 ,
struct V_2 * * V_15 )
{
T_2 V_16 = F_6 ( V_14 ) ;
struct V_2 * V_3 ;
struct V_1 * V_17 ;
struct V_13 * V_18 ;
V_3 = & V_2 [ F_7 ( V_14 ) ] ;
if ( V_15 )
* V_15 = V_3 ;
V_17 = V_3 -> V_10 [ V_16 / V_19 ] ;
V_18 = F_8 ( V_17 ) ;
return V_18 + V_16 % V_19 ;
}
unsigned short F_9 ( T_1 V_14 ,
unsigned short V_20 , unsigned short V_21 )
{
struct V_2 * V_3 ;
struct V_13 * V_18 ;
unsigned long V_22 ;
unsigned short V_23 ;
V_18 = F_5 ( V_14 , & V_3 ) ;
F_10 ( & V_3 -> V_24 , V_22 ) ;
V_23 = V_18 -> V_25 ;
if ( V_23 == V_20 )
V_18 -> V_25 = V_21 ;
else
V_23 = 0 ;
F_11 ( & V_3 -> V_24 , V_22 ) ;
return V_23 ;
}
unsigned short F_12 ( T_1 V_14 , unsigned short V_25 )
{
struct V_2 * V_3 ;
struct V_13 * V_18 ;
unsigned short V_20 ;
unsigned long V_22 ;
V_18 = F_5 ( V_14 , & V_3 ) ;
F_10 ( & V_3 -> V_24 , V_22 ) ;
V_20 = V_18 -> V_25 ;
V_18 -> V_25 = V_25 ;
F_11 ( & V_3 -> V_24 , V_22 ) ;
return V_20 ;
}
unsigned short F_13 ( T_1 V_14 )
{
return F_5 ( V_14 , NULL ) -> V_25 ;
}
int F_14 ( int type , unsigned long V_26 )
{
void * V_27 ;
unsigned long V_28 ;
unsigned long V_6 ;
struct V_2 * V_3 ;
if ( ! V_29 )
return 0 ;
V_6 = F_15 ( V_26 , V_19 ) ;
V_28 = V_6 * sizeof( void * ) ;
V_27 = F_16 ( V_28 ) ;
if ( ! V_27 )
goto V_30;
V_3 = & V_2 [ type ] ;
F_17 ( & V_31 ) ;
V_3 -> V_6 = V_6 ;
V_3 -> V_10 = V_27 ;
F_18 ( & V_3 -> V_24 ) ;
if ( F_1 ( type ) ) {
V_3 -> V_10 = NULL ;
V_3 -> V_6 = 0 ;
F_19 ( & V_31 ) ;
F_20 ( V_27 ) ;
goto V_30;
}
F_19 ( & V_31 ) ;
return 0 ;
V_30:
F_21 ( L_1 ) ;
F_21 ( L_2 ) ;
return - V_12 ;
}
void F_22 ( int type )
{
struct V_1 * * V_10 ;
unsigned long V_32 , V_6 ;
struct V_2 * V_3 ;
if ( ! V_29 )
return;
F_17 ( & V_31 ) ;
V_3 = & V_2 [ type ] ;
V_10 = V_3 -> V_10 ;
V_6 = V_3 -> V_6 ;
V_3 -> V_10 = NULL ;
V_3 -> V_6 = 0 ;
F_19 ( & V_31 ) ;
if ( V_10 ) {
for ( V_32 = 0 ; V_32 < V_6 ; V_32 ++ ) {
struct V_1 * V_1 = V_10 [ V_32 ] ;
if ( V_1 )
F_4 ( V_1 ) ;
if ( ! ( V_32 % V_11 ) )
F_3 () ;
}
F_20 ( V_10 ) ;
}
}
