static int F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_2 , V_3 . V_4 ) ;
}
static unsigned int F_3 ( unsigned int V_5 )
{
return F_4 ( V_3 . V_6 ) / 1000 ;
}
static struct V_6 * F_5 ( unsigned long V_7 )
{
struct V_6 * V_8 ;
int V_9 ;
const char * V_10 [] = {
L_1 ,
L_2 ,
L_3 ,
L_4 ,
} ;
if ( V_7 <= 300000000 )
V_9 = 0 ;
else if ( V_7 > 300000000 && V_7 <= 500000000 )
V_9 = 3 ;
else if ( V_7 == 600000000 )
V_9 = 1 ;
else
return F_6 ( - V_11 ) ;
V_8 = F_7 ( NULL , V_10 [ V_9 ] ) ;
if ( F_8 ( V_8 ) )
F_9 ( L_5 , V_10 [ V_9 ] ) ;
return V_8 ;
}
static int F_10 ( struct V_6 * V_8 , unsigned long V_7 )
{
struct V_6 * V_12 ;
int V_13 = 0 ;
V_12 = F_11 ( V_3 . V_6 ) ;
if ( F_8 ( V_12 ) ) {
F_9 ( L_6 ) ;
return F_12 ( V_12 ) ;
}
V_13 = F_13 ( V_8 , V_7 ) ;
if ( V_13 ) {
F_9 ( L_7 , V_7 ) ;
return V_13 ;
}
V_13 = F_14 ( V_12 , V_8 ) ;
if ( V_13 ) {
F_9 ( L_8 ) ;
return V_13 ;
}
return 0 ;
}
static int F_15 ( struct V_1 * V_2 ,
unsigned int V_14 , unsigned int V_15 )
{
struct V_16 V_17 ;
long V_7 ;
struct V_6 * V_18 ;
int V_19 , V_13 , V_20 = 1 ;
if ( F_16 ( V_2 , V_3 . V_4 ,
V_14 , V_15 , & V_19 ) )
return - V_11 ;
V_17 . V_21 = F_3 ( 0 ) ;
V_7 = V_3 . V_4 [ V_19 ] . V_22 * 1000 ;
if ( F_17 ( L_9 ) ) {
V_18 = F_5 ( V_7 ) ;
if ( F_8 ( V_18 ) ) {
F_9 ( L_10 ) ;
return F_12 ( V_18 ) ;
}
V_20 = 2 ;
} else {
V_18 = V_3 . V_6 ;
}
V_7 = F_18 ( V_18 , V_7 * V_20 ) ;
if ( V_7 < 0 ) {
F_9 ( L_11 ) ;
return V_7 ;
}
V_17 . V_23 = V_7 / 1000 ;
V_17 . V_23 /= V_20 ;
F_19 ( V_2 , & V_17 , V_24 ) ;
if ( V_20 == 2 )
V_13 = F_10 ( V_18 , V_7 ) ;
else
V_13 = F_13 ( V_3 . V_6 , V_7 ) ;
if ( V_13 ) {
F_9 ( L_12 , V_13 ) ;
V_17 . V_23 = F_4 ( V_3 . V_6 ) / 1000 ;
}
F_19 ( V_2 , & V_17 , V_25 ) ;
return V_13 ;
}
static int F_20 ( struct V_1 * V_2 )
{
int V_13 ;
V_13 = F_21 ( V_2 , V_3 . V_4 ) ;
if ( V_13 ) {
F_9 ( L_13 ) ;
return V_13 ;
}
F_22 ( V_3 . V_4 , V_2 -> V_5 ) ;
V_2 -> V_26 . V_27 = V_3 . V_27 ;
V_2 -> V_28 = F_3 ( 0 ) ;
F_23 ( V_2 -> V_29 ) ;
return 0 ;
}
static int F_24 ( struct V_1 * V_2 )
{
F_25 ( V_2 -> V_5 ) ;
return 0 ;
}
static int F_26 ( void )
{
struct V_30 * V_31 ;
const struct V_32 * V_33 ;
struct V_34 * V_4 ;
const T_1 * V_35 ;
int V_36 , V_37 , V_13 ;
V_31 = F_27 ( 0 ) ;
if ( ! V_31 ) {
F_9 ( L_14 ) ;
return - V_38 ;
}
if ( F_28 ( V_31 , L_15 ,
& V_3 . V_27 ) )
V_3 . V_27 = V_39 ;
V_33 = F_29 ( V_31 , L_16 , NULL ) ;
if ( ! V_33 || ! V_33 -> V_40 ) {
F_9 ( L_17 ) ;
V_13 = - V_38 ;
goto V_41;
}
V_36 = V_33 -> V_42 / sizeof( V_43 ) ;
V_35 = V_33 -> V_40 ;
V_4 = F_30 ( sizeof( * V_4 ) * ( V_36 + 1 ) , V_44 ) ;
if ( ! V_4 ) {
V_13 = - V_45 ;
goto V_41;
}
for ( V_37 = 0 ; V_37 < V_36 ; V_37 ++ ) {
V_4 [ V_37 ] . V_46 = V_37 ;
V_4 [ V_37 ] . V_22 = F_31 ( V_35 ++ ) ;
}
V_4 [ V_37 ] . V_46 = V_37 ;
V_4 [ V_37 ] . V_22 = V_47 ;
V_3 . V_4 = V_4 ;
F_32 ( V_31 ) ;
V_3 . V_6 = F_7 ( NULL , L_18 ) ;
if ( F_8 ( V_3 . V_6 ) ) {
F_9 ( L_19 ) ;
V_13 = F_12 ( V_3 . V_6 ) ;
goto V_48;
}
V_13 = F_33 ( & V_49 ) ;
if ( ! V_13 )
return 0 ;
F_9 ( L_20 , V_13 ) ;
F_34 ( V_3 . V_6 ) ;
V_48:
F_35 ( V_4 ) ;
return V_13 ;
V_41:
F_32 ( V_31 ) ;
return V_13 ;
}
