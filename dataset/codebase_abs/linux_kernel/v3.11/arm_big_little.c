static unsigned int F_1 ( unsigned int V_1 )
{
T_1 V_2 = F_2 ( V_1 ) ;
return F_3 ( V_3 [ V_2 ] ) / 1000 ;
}
static int F_4 ( struct V_4 * V_5 )
{
T_1 V_2 = F_2 ( V_5 -> V_1 ) ;
return F_5 ( V_5 , V_6 [ V_2 ] ) ;
}
static int F_6 ( struct V_4 * V_5 ,
unsigned int V_7 , unsigned int V_8 )
{
struct V_9 V_10 ;
T_1 V_1 = V_5 -> V_1 , V_11 , V_2 ;
int V_12 = 0 ;
V_2 = F_2 ( V_5 -> V_1 ) ;
V_10 . V_13 = F_1 ( V_5 -> V_1 ) ;
F_7 ( V_5 , V_6 [ V_2 ] ,
V_7 , V_8 , & V_11 ) ;
V_10 . V_14 = V_6 [ V_2 ] [ V_11 ] . V_15 ;
F_8 ( L_1 ,
V_16 , V_1 , V_2 , V_10 . V_13 , V_7 ,
V_10 . V_14 ) ;
if ( V_10 . V_13 == V_10 . V_14 )
return 0 ;
F_9 ( V_5 , & V_10 , V_17 ) ;
V_12 = F_10 ( V_3 [ V_2 ] , V_10 . V_14 * 1000 ) ;
if ( V_12 ) {
F_11 ( L_2 , V_12 ) ;
V_10 . V_14 = V_10 . V_13 ;
}
F_9 ( V_5 , & V_10 , V_18 ) ;
return V_12 ;
}
static void F_12 ( struct V_19 * V_20 )
{
T_1 V_21 = F_2 ( V_20 -> V_22 ) ;
if ( ! F_13 ( & V_23 [ V_21 ] ) ) {
F_14 ( V_3 [ V_21 ] ) ;
F_15 ( V_20 , & V_6 [ V_21 ] ) ;
F_16 ( V_20 , L_3 , V_16 , V_21 ) ;
}
}
static int F_17 ( struct V_19 * V_20 )
{
T_1 V_21 = F_2 ( V_20 -> V_22 ) ;
char V_24 [ 14 ] = L_4 ;
int V_12 ;
if ( F_18 ( & V_23 [ V_21 ] ) != 1 )
return 0 ;
V_12 = V_25 -> V_26 ( V_20 ) ;
if ( V_12 ) {
F_19 ( V_20 , L_5 ,
V_16 , V_20 -> V_22 , V_12 ) ;
goto V_27;
}
V_12 = F_20 ( V_20 , & V_6 [ V_21 ] ) ;
if ( V_12 ) {
F_19 ( V_20 , L_6 ,
V_16 , V_20 -> V_22 , V_12 ) ;
goto V_27;
}
V_24 [ 12 ] = V_21 + '0' ;
V_3 [ V_21 ] = F_21 ( V_24 , NULL ) ;
if ( ! F_22 ( V_3 [ V_21 ] ) ) {
F_16 ( V_20 , L_7 ,
V_16 , V_3 [ V_21 ] , V_6 [ V_21 ] ,
V_21 ) ;
return 0 ;
}
F_19 ( V_20 , L_8 ,
V_16 , V_20 -> V_22 , V_21 ) ;
V_12 = F_23 ( V_3 [ V_21 ] ) ;
F_15 ( V_20 , & V_6 [ V_21 ] ) ;
V_27:
V_27 ( & V_23 [ V_21 ] ) ;
F_19 ( V_20 , L_9 , V_16 ,
V_21 ) ;
return V_12 ;
}
static int F_24 ( struct V_4 * V_5 )
{
T_1 V_2 = F_2 ( V_5 -> V_1 ) ;
struct V_19 * V_20 ;
int V_12 ;
V_20 = F_25 ( V_5 -> V_1 ) ;
if ( ! V_20 ) {
F_11 ( L_10 , V_16 ,
V_5 -> V_1 ) ;
return - V_28 ;
}
V_12 = F_17 ( V_20 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_26 ( V_5 , V_6 [ V_2 ] ) ;
if ( V_12 ) {
F_19 ( V_20 , L_11 ,
V_5 -> V_1 , V_2 ) ;
F_12 ( V_20 ) ;
return V_12 ;
}
F_27 ( V_6 [ V_2 ] , V_5 -> V_1 ) ;
if ( V_25 -> V_29 )
V_5 -> V_30 . V_31 =
V_25 -> V_29 ( V_20 ) ;
else
V_5 -> V_30 . V_31 = V_32 ;
V_5 -> V_33 = F_1 ( V_5 -> V_1 ) ;
F_28 ( V_5 -> V_34 , F_29 ( V_5 -> V_1 ) ) ;
F_30 ( V_20 , L_12 , V_16 , V_5 -> V_1 ) ;
return 0 ;
}
static int F_31 ( struct V_4 * V_5 )
{
struct V_19 * V_20 ;
V_20 = F_25 ( V_5 -> V_1 ) ;
if ( ! V_20 ) {
F_11 ( L_10 , V_16 ,
V_5 -> V_1 ) ;
return - V_28 ;
}
F_12 ( V_20 ) ;
F_16 ( V_20 , L_13 , V_16 , V_5 -> V_1 ) ;
return 0 ;
}
int F_32 ( struct V_35 * V_36 )
{
int V_12 ;
if ( V_25 ) {
F_8 ( L_14 , V_16 ,
V_25 -> V_24 ) ;
return - V_37 ;
}
if ( ! V_36 || ! strlen ( V_36 -> V_24 ) || ! V_36 -> V_26 ) {
F_11 ( L_15 , V_16 ) ;
return - V_28 ;
}
V_25 = V_36 ;
V_12 = F_33 ( & V_38 ) ;
if ( V_12 ) {
F_34 ( L_16 ,
V_16 , V_36 -> V_24 , V_12 ) ;
V_25 = NULL ;
} else {
F_34 ( L_17 , V_16 ,
V_36 -> V_24 ) ;
}
return V_12 ;
}
void F_35 ( struct V_35 * V_36 )
{
if ( V_25 != V_36 ) {
F_11 ( L_18 ,
V_16 , V_25 -> V_24 ) ;
return;
}
F_36 ( & V_38 ) ;
F_34 ( L_19 , V_16 ,
V_25 -> V_24 ) ;
V_25 = NULL ;
}
