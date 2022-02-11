static struct V_1 * F_1 ( unsigned long V_2 )
{
struct V_1 * V_3 ;
int V_4 ;
const char * V_5 [] = {
L_1 ,
L_2 ,
L_3 ,
L_4 ,
} ;
if ( V_2 <= 300000000 )
V_4 = 0 ;
else if ( V_2 > 300000000 && V_2 <= 500000000 )
V_4 = 3 ;
else if ( V_2 == 600000000 )
V_4 = 1 ;
else
return F_2 ( - V_6 ) ;
V_3 = F_3 ( NULL , V_5 [ V_4 ] ) ;
if ( F_4 ( V_3 ) )
F_5 ( L_5 , V_5 [ V_4 ] ) ;
return V_3 ;
}
static int F_6 ( struct V_1 * V_3 , unsigned long V_2 )
{
struct V_1 * V_7 ;
int V_8 = 0 ;
V_7 = F_7 ( V_9 . V_1 ) ;
if ( F_4 ( V_7 ) ) {
F_5 ( L_6 ) ;
return F_8 ( V_7 ) ;
}
V_8 = F_9 ( V_3 , V_2 ) ;
if ( V_8 ) {
F_5 ( L_7 , V_2 ) ;
return V_8 ;
}
V_8 = F_10 ( V_7 , V_3 ) ;
if ( V_8 ) {
F_5 ( L_8 ) ;
return V_8 ;
}
return 0 ;
}
static int F_11 ( struct V_10 * V_11 ,
unsigned int V_12 )
{
long V_2 ;
struct V_1 * V_13 ;
int V_8 , V_14 = 1 ;
V_2 = V_9 . V_15 [ V_12 ] . V_16 * 1000 ;
if ( F_12 ( L_9 ) ) {
V_13 = F_1 ( V_2 ) ;
if ( F_4 ( V_13 ) ) {
F_5 ( L_10 ) ;
return F_8 ( V_13 ) ;
}
V_14 = 2 ;
} else {
V_13 = V_9 . V_1 ;
}
V_2 = F_13 ( V_13 , V_2 * V_14 ) ;
if ( V_2 <= 0 ) {
F_5 ( L_11 ) ;
return V_2 ;
}
if ( V_14 == 2 )
V_8 = F_6 ( V_13 , V_2 ) ;
else
V_8 = F_9 ( V_9 . V_1 , V_2 ) ;
if ( V_8 )
F_5 ( L_12 , V_8 ) ;
return V_8 ;
}
static int F_14 ( struct V_10 * V_11 )
{
V_11 -> V_1 = V_9 . V_1 ;
return F_15 ( V_11 , V_9 . V_15 ,
V_9 . V_17 ) ;
}
static int F_16 ( void )
{
struct V_18 * V_19 ;
const struct V_20 * V_21 ;
struct V_22 * V_15 ;
const T_1 * V_23 ;
int V_24 , V_25 , V_8 ;
V_19 = F_17 ( 0 ) ;
if ( ! V_19 ) {
F_5 ( L_13 ) ;
return - V_26 ;
}
if ( F_18 ( V_19 , L_14 ,
& V_9 . V_17 ) )
V_9 . V_17 = V_27 ;
V_21 = F_19 ( V_19 , L_15 , NULL ) ;
if ( ! V_21 || ! V_21 -> V_28 ) {
F_5 ( L_16 ) ;
V_8 = - V_26 ;
goto V_29;
}
V_24 = V_21 -> V_30 / sizeof( V_31 ) ;
V_23 = V_21 -> V_28 ;
V_15 = F_20 ( sizeof( * V_15 ) * ( V_24 + 1 ) , V_32 ) ;
if ( ! V_15 ) {
V_8 = - V_33 ;
goto V_29;
}
for ( V_25 = 0 ; V_25 < V_24 ; V_25 ++ ) {
V_15 [ V_25 ] . V_34 = V_25 ;
V_15 [ V_25 ] . V_16 = F_21 ( V_23 ++ ) ;
}
V_15 [ V_25 ] . V_34 = V_25 ;
V_15 [ V_25 ] . V_16 = V_35 ;
V_9 . V_15 = V_15 ;
F_22 ( V_19 ) ;
V_9 . V_1 = F_3 ( NULL , L_17 ) ;
if ( F_4 ( V_9 . V_1 ) ) {
F_5 ( L_18 ) ;
V_8 = F_8 ( V_9 . V_1 ) ;
goto V_36;
}
V_8 = F_23 ( & V_37 ) ;
if ( ! V_8 )
return 0 ;
F_5 ( L_19 , V_8 ) ;
F_24 ( V_9 . V_1 ) ;
V_36:
F_25 ( V_15 ) ;
return V_8 ;
V_29:
F_22 ( V_19 ) ;
return V_8 ;
}
