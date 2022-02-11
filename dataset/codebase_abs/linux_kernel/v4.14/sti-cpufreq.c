static int F_1 ( void ) {
struct V_1 * V_2 = V_3 . V_4 -> V_5 ;
struct V_6 * V_7 = V_3 . V_4 ;
unsigned int V_8 ;
unsigned int V_9 ;
int V_10 ;
V_10 = F_2 ( V_2 , L_1 ,
V_11 , & V_8 ) ;
if ( V_10 ) {
F_3 ( V_7 , L_2 ,
V_2 , V_10 ) ;
return V_10 ;
}
V_10 = F_4 ( V_3 . V_12 , V_8 , & V_9 ) ;
if ( V_10 ) {
F_3 ( V_7 , L_3 ,
V_10 ) ;
return V_10 ;
}
return ( ( V_9 >> V_13 ) & 0xf ) + 1 ;
}
static int F_5 ( void )
{
struct V_6 * V_7 = V_3 . V_4 ;
struct V_1 * V_2 = V_7 -> V_5 ;
unsigned int V_14 ;
unsigned int V_15 ;
int V_10 ;
V_10 = F_2 ( V_2 , L_4 ,
V_16 , & V_14 ) ;
if ( V_10 ) {
F_3 ( V_7 ,
L_5 ,
V_2 , V_10 ) ;
return V_10 ;
}
V_10 = F_4 ( V_3 . V_17 , V_14 , & V_15 ) ;
if ( V_10 ) {
F_3 ( V_7 ,
L_6 ,
V_10 ) ;
return V_10 ;
}
return V_15 & 0xf ;
}
static int F_6 ( const struct V_18 * V_19 ,
int V_20 , int V_21 )
{
struct V_22 * V_22 ;
struct V_18 V_18 = V_19 [ V_21 ] ;
struct V_6 * V_7 = V_3 . V_4 ;
unsigned int V_23 ;
int V_10 ;
V_18 . V_24 = V_20 ;
V_22 = F_7 ( V_7 ,
V_3 . V_17 ,
V_18 ) ;
if ( F_8 ( V_22 ) ) {
F_3 ( V_7 , L_7 ) ;
return F_9 ( V_22 ) ;
}
V_10 = F_10 ( V_22 , & V_23 ) ;
if ( V_10 ) {
F_3 ( V_7 , L_8 ,
V_21 ? L_9 : L_10 ) ;
return V_10 ;
}
return V_23 ;
}
static const struct V_18 * F_11 ( void )
{
if ( F_12 ( L_11 ) ||
F_12 ( L_12 ) )
return V_25 ;
return NULL ;
}
static int F_13 ( void )
{
struct V_6 * V_7 = V_3 . V_4 ;
struct V_1 * V_2 = V_7 -> V_5 ;
const struct V_18 * V_19 ;
unsigned int V_20 ;
unsigned int V_26 [ V_27 ] ;
int V_28 , V_29 , V_30 , V_31 ;
int V_10 ;
char V_32 [ V_33 ] ;
struct V_34 * V_34 ;
V_19 = F_11 () ;
if ( ! V_19 ) {
F_3 ( V_7 , L_13 ) ;
return - V_35 ;
}
V_10 = F_2 ( V_2 , L_4 ,
V_36 , & V_20 ) ;
if ( V_10 ) {
F_14 ( V_7 , L_14 ) ;
V_29 = V_37 ;
V_28 = 0 ;
goto V_38;
}
V_28 = F_6 ( V_19 ,
V_20 ,
V_39 ) ;
if ( V_28 < 0 ) {
F_14 ( V_7 , L_15 ) ;
V_28 = 0 ;
}
V_29 = F_6 ( V_19 ,
V_20 ,
V_40 ) ;
if ( V_29 ) {
F_14 ( V_7 , L_16 ) ;
V_29 = V_37 ;
}
V_38:
V_30 = F_1 () ;
if ( V_30 < 0 ) {
F_3 ( V_7 , L_17 ) ;
V_30 = V_37 ;
}
V_31 = F_5 () ;
if ( V_31 < 0 ) {
F_3 ( V_7 , L_18 ) ;
V_31 = V_37 ;
}
snprintf ( V_32 , V_33 , L_19 , V_28 ) ;
V_34 = F_15 ( V_7 , V_32 ) ;
if ( F_8 ( V_34 ) ) {
F_3 ( V_7 , L_20 ) ;
return F_9 ( V_34 ) ;
}
V_26 [ 0 ] = F_16 ( V_30 ) ;
V_26 [ 1 ] = F_16 ( V_31 ) ;
V_26 [ 2 ] = F_16 ( V_29 ) ;
V_34 = F_17 ( V_7 , V_26 , V_27 ) ;
if ( F_8 ( V_34 ) ) {
F_3 ( V_7 , L_21 ) ;
return F_9 ( V_34 ) ;
}
F_18 ( V_7 , L_22 ,
V_28 , V_30 , V_31 , V_29 ) ;
F_18 ( V_7 , L_23 ,
V_26 [ 0 ] , V_26 [ 1 ] , V_26 [ 2 ] ) ;
return 0 ;
}
static int F_19 ( void )
{
struct V_6 * V_7 = V_3 . V_4 ;
struct V_1 * V_2 = V_7 -> V_5 ;
V_3 . V_12 = F_20 ( V_2 , L_1 ) ;
if ( F_8 ( V_3 . V_12 ) ) {
F_3 ( V_7 , L_24 ) ;
return F_9 ( V_3 . V_12 ) ;
}
V_3 . V_17 = F_20 ( V_2 , L_4 ) ;
if ( F_8 ( V_3 . V_17 ) ) {
F_3 ( V_7 , L_25 ) ;
return F_9 ( V_3 . V_17 ) ;
}
return 0 ;
}
static int F_21 ( void )
{
int V_10 ;
if ( ( ! F_12 ( L_11 ) ) &&
( ! F_12 ( L_12 ) ) )
return - V_35 ;
V_3 . V_4 = F_22 ( 0 ) ;
if ( ! V_3 . V_4 ) {
F_3 ( V_3 . V_4 , L_26 ) ;
goto V_41;
}
if ( ! F_23 ( V_3 . V_4 -> V_5 , L_27 , NULL ) ) {
F_3 ( V_3 . V_4 , L_28 ) ;
goto V_41;
}
V_10 = F_19 () ;
if ( V_10 )
goto V_41;
V_10 = F_13 () ;
if ( ! V_10 )
goto V_42;
V_41:
F_3 ( V_3 . V_4 , L_29 ) ;
V_42:
F_24 ( L_30 , - 1 , NULL , 0 ) ;
return 0 ;
}
