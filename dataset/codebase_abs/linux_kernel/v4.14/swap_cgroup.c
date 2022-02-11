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
static struct V_13 * F_5 ( struct V_2 * V_3 ,
T_1 V_14 )
{
struct V_1 * V_15 ;
struct V_13 * V_16 ;
V_15 = V_3 -> V_10 [ V_14 / V_17 ] ;
V_16 = F_6 ( V_15 ) ;
return V_16 + V_14 % V_17 ;
}
static struct V_13 * F_7 ( T_2 V_18 ,
struct V_2 * * V_19 )
{
T_1 V_14 = F_8 ( V_18 ) ;
struct V_2 * V_3 ;
V_3 = & V_2 [ F_9 ( V_18 ) ] ;
if ( V_19 )
* V_19 = V_3 ;
return F_5 ( V_3 , V_14 ) ;
}
unsigned short F_10 ( T_2 V_18 ,
unsigned short V_20 , unsigned short V_21 )
{
struct V_2 * V_3 ;
struct V_13 * V_16 ;
unsigned long V_22 ;
unsigned short V_23 ;
V_16 = F_7 ( V_18 , & V_3 ) ;
F_11 ( & V_3 -> V_24 , V_22 ) ;
V_23 = V_16 -> V_25 ;
if ( V_23 == V_20 )
V_16 -> V_25 = V_21 ;
else
V_23 = 0 ;
F_12 ( & V_3 -> V_24 , V_22 ) ;
return V_23 ;
}
unsigned short F_13 ( T_2 V_18 , unsigned short V_25 ,
unsigned int V_26 )
{
struct V_2 * V_3 ;
struct V_13 * V_16 ;
unsigned short V_20 ;
unsigned long V_22 ;
T_1 V_14 = F_8 ( V_18 ) ;
T_1 V_27 = V_14 + V_26 ;
V_16 = F_7 ( V_18 , & V_3 ) ;
F_11 ( & V_3 -> V_24 , V_22 ) ;
V_20 = V_16 -> V_25 ;
for (; ; ) {
F_14 ( V_16 -> V_25 != V_20 ) ;
V_16 -> V_25 = V_25 ;
V_14 ++ ;
if ( V_14 == V_27 )
break;
if ( V_14 % V_17 )
V_16 ++ ;
else
V_16 = F_5 ( V_3 , V_14 ) ;
}
F_12 ( & V_3 -> V_24 , V_22 ) ;
return V_20 ;
}
unsigned short F_15 ( T_2 V_18 )
{
return F_7 ( V_18 , NULL ) -> V_25 ;
}
int F_16 ( int type , unsigned long V_28 )
{
void * V_29 ;
unsigned long V_30 ;
unsigned long V_6 ;
struct V_2 * V_3 ;
if ( ! V_31 )
return 0 ;
V_6 = F_17 ( V_28 , V_17 ) ;
V_30 = V_6 * sizeof( void * ) ;
V_29 = F_18 ( V_30 ) ;
if ( ! V_29 )
goto V_32;
V_3 = & V_2 [ type ] ;
F_19 ( & V_33 ) ;
V_3 -> V_6 = V_6 ;
V_3 -> V_10 = V_29 ;
F_20 ( & V_3 -> V_24 ) ;
if ( F_1 ( type ) ) {
V_3 -> V_10 = NULL ;
V_3 -> V_6 = 0 ;
F_21 ( & V_33 ) ;
F_22 ( V_29 ) ;
goto V_32;
}
F_21 ( & V_33 ) ;
return 0 ;
V_32:
F_23 ( L_1 ) ;
F_23 ( L_2 ) ;
return - V_12 ;
}
void F_24 ( int type )
{
struct V_1 * * V_10 ;
unsigned long V_34 , V_6 ;
struct V_2 * V_3 ;
if ( ! V_31 )
return;
F_19 ( & V_33 ) ;
V_3 = & V_2 [ type ] ;
V_10 = V_3 -> V_10 ;
V_6 = V_3 -> V_6 ;
V_3 -> V_10 = NULL ;
V_3 -> V_6 = 0 ;
F_21 ( & V_33 ) ;
if ( V_10 ) {
for ( V_34 = 0 ; V_34 < V_6 ; V_34 ++ ) {
struct V_1 * V_1 = V_10 [ V_34 ] ;
if ( V_1 )
F_4 ( V_1 ) ;
if ( ! ( V_34 % V_11 ) )
F_3 () ;
}
F_22 ( V_10 ) ;
}
}
