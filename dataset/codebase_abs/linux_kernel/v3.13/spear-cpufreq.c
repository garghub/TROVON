static unsigned int F_1 ( unsigned int V_1 )
{
return F_2 ( V_2 . V_3 ) / 1000 ;
}
static struct V_3 * F_3 ( unsigned long V_4 )
{
struct V_3 * V_5 ;
int V_6 ;
const char * V_7 [] = {
L_1 ,
L_2 ,
L_3 ,
L_4 ,
} ;
if ( V_4 <= 300000000 )
V_6 = 0 ;
else if ( V_4 > 300000000 && V_4 <= 500000000 )
V_6 = 3 ;
else if ( V_4 == 600000000 )
V_6 = 1 ;
else
return F_4 ( - V_8 ) ;
V_5 = F_5 ( NULL , V_7 [ V_6 ] ) ;
if ( F_6 ( V_5 ) )
F_7 ( L_5 , V_7 [ V_6 ] ) ;
return V_5 ;
}
static int F_8 ( struct V_3 * V_5 , unsigned long V_4 )
{
struct V_3 * V_9 ;
int V_10 = 0 ;
V_9 = F_9 ( V_2 . V_3 ) ;
if ( F_6 ( V_9 ) ) {
F_7 ( L_6 ) ;
return F_10 ( V_9 ) ;
}
V_10 = F_11 ( V_5 , V_4 ) ;
if ( V_10 ) {
F_7 ( L_7 , V_4 ) ;
return V_10 ;
}
V_10 = F_12 ( V_9 , V_5 ) ;
if ( V_10 ) {
F_7 ( L_8 ) ;
return V_10 ;
}
return 0 ;
}
static int F_13 ( struct V_11 * V_12 ,
unsigned int V_13 )
{
long V_4 ;
struct V_3 * V_14 ;
int V_10 , V_15 = 1 ;
V_4 = V_2 . V_16 [ V_13 ] . V_17 * 1000 ;
if ( F_14 ( L_9 ) ) {
V_14 = F_3 ( V_4 ) ;
if ( F_6 ( V_14 ) ) {
F_7 ( L_10 ) ;
return F_10 ( V_14 ) ;
}
V_15 = 2 ;
} else {
V_14 = V_2 . V_3 ;
}
V_4 = F_15 ( V_14 , V_4 * V_15 ) ;
if ( V_4 < 0 ) {
F_7 ( L_11 ) ;
return V_4 ;
}
if ( V_15 == 2 )
V_10 = F_8 ( V_14 , V_4 ) ;
else
V_10 = F_11 ( V_2 . V_3 , V_4 ) ;
if ( V_10 )
F_7 ( L_12 , V_10 ) ;
return V_10 ;
}
static int F_16 ( struct V_11 * V_12 )
{
return F_17 ( V_12 , V_2 . V_16 ,
V_2 . V_18 ) ;
}
static int F_18 ( void )
{
struct V_19 * V_20 ;
const struct V_21 * V_22 ;
struct V_23 * V_16 ;
const T_1 * V_24 ;
int V_25 , V_26 , V_10 ;
V_20 = F_19 ( 0 ) ;
if ( ! V_20 ) {
F_7 ( L_13 ) ;
return - V_27 ;
}
if ( F_20 ( V_20 , L_14 ,
& V_2 . V_18 ) )
V_2 . V_18 = V_28 ;
V_22 = F_21 ( V_20 , L_15 , NULL ) ;
if ( ! V_22 || ! V_22 -> V_29 ) {
F_7 ( L_16 ) ;
V_10 = - V_27 ;
goto V_30;
}
V_25 = V_22 -> V_31 / sizeof( V_32 ) ;
V_24 = V_22 -> V_29 ;
V_16 = F_22 ( sizeof( * V_16 ) * ( V_25 + 1 ) , V_33 ) ;
if ( ! V_16 ) {
V_10 = - V_34 ;
goto V_30;
}
for ( V_26 = 0 ; V_26 < V_25 ; V_26 ++ ) {
V_16 [ V_26 ] . V_35 = V_26 ;
V_16 [ V_26 ] . V_17 = F_23 ( V_24 ++ ) ;
}
V_16 [ V_26 ] . V_35 = V_26 ;
V_16 [ V_26 ] . V_17 = V_36 ;
V_2 . V_16 = V_16 ;
F_24 ( V_20 ) ;
V_2 . V_3 = F_5 ( NULL , L_17 ) ;
if ( F_6 ( V_2 . V_3 ) ) {
F_7 ( L_18 ) ;
V_10 = F_10 ( V_2 . V_3 ) ;
goto V_37;
}
V_10 = F_25 ( & V_38 ) ;
if ( ! V_10 )
return 0 ;
F_7 ( L_19 , V_10 ) ;
F_26 ( V_2 . V_3 ) ;
V_37:
F_27 ( V_16 ) ;
return V_10 ;
V_30:
F_24 ( V_20 ) ;
return V_10 ;
}
