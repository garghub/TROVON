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
return V_12 ;
}
V_5 -> V_18 = V_10 . V_14 ;
F_9 ( V_5 , & V_10 , V_19 ) ;
return V_12 ;
}
static void F_12 ( struct V_20 * V_21 )
{
T_1 V_22 = F_2 ( V_21 -> V_23 ) ;
if ( ! F_13 ( & V_24 [ V_22 ] ) ) {
F_14 ( V_3 [ V_22 ] ) ;
F_15 ( V_21 , & V_6 [ V_22 ] ) ;
F_16 ( V_21 , L_3 , V_16 , V_22 ) ;
}
}
static int F_17 ( struct V_20 * V_21 )
{
T_1 V_22 = F_2 ( V_21 -> V_23 ) ;
char V_25 [ 14 ] = L_4 ;
int V_12 ;
if ( F_18 ( & V_24 [ V_22 ] ) != 1 )
return 0 ;
V_12 = V_26 -> V_27 ( V_21 ) ;
if ( V_12 ) {
F_19 ( V_21 , L_5 ,
V_16 , V_21 -> V_23 , V_12 ) ;
goto V_28;
}
V_12 = F_20 ( V_21 , & V_6 [ V_22 ] ) ;
if ( V_12 ) {
F_19 ( V_21 , L_6 ,
V_16 , V_21 -> V_23 , V_12 ) ;
goto V_28;
}
V_25 [ 12 ] = V_22 + '0' ;
V_3 [ V_22 ] = F_21 ( V_25 , NULL ) ;
if ( ! F_22 ( V_3 [ V_22 ] ) ) {
F_16 ( V_21 , L_7 ,
V_16 , V_3 [ V_22 ] , V_6 [ V_22 ] ,
V_22 ) ;
return 0 ;
}
F_19 ( V_21 , L_8 ,
V_16 , V_21 -> V_23 , V_22 ) ;
V_12 = F_23 ( V_3 [ V_22 ] ) ;
F_15 ( V_21 , & V_6 [ V_22 ] ) ;
V_28:
V_28 ( & V_24 [ V_22 ] ) ;
F_19 ( V_21 , L_9 , V_16 ,
V_22 ) ;
return V_12 ;
}
static int F_24 ( struct V_4 * V_5 )
{
T_1 V_2 = F_2 ( V_5 -> V_1 ) ;
struct V_20 * V_21 ;
int V_12 ;
V_21 = F_25 ( V_5 -> V_1 ) ;
if ( ! V_21 ) {
F_11 ( L_10 , V_16 ,
V_5 -> V_1 ) ;
return - V_29 ;
}
V_12 = F_17 ( V_21 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_26 ( V_5 , V_6 [ V_2 ] ) ;
if ( V_12 ) {
F_19 ( V_21 , L_11 ,
V_5 -> V_1 , V_2 ) ;
F_12 ( V_21 ) ;
return V_12 ;
}
F_27 ( V_6 [ V_2 ] , V_5 -> V_1 ) ;
if ( V_26 -> V_30 )
V_5 -> V_31 . V_32 =
V_26 -> V_30 ( V_21 ) ;
else
V_5 -> V_31 . V_32 = V_33 ;
V_5 -> V_18 = F_1 ( V_5 -> V_1 ) ;
F_28 ( V_5 -> V_34 , F_29 ( V_5 -> V_1 ) ) ;
F_30 ( V_21 , L_12 , V_16 , V_5 -> V_1 ) ;
return 0 ;
}
static int F_31 ( struct V_4 * V_5 )
{
struct V_20 * V_21 ;
V_21 = F_25 ( V_5 -> V_1 ) ;
if ( ! V_21 ) {
F_11 ( L_10 , V_16 ,
V_5 -> V_1 ) ;
return - V_29 ;
}
F_12 ( V_21 ) ;
F_16 ( V_21 , L_13 , V_16 , V_5 -> V_1 ) ;
return 0 ;
}
int F_32 ( struct V_35 * V_36 )
{
int V_12 ;
if ( V_26 ) {
F_8 ( L_14 , V_16 ,
V_26 -> V_25 ) ;
return - V_37 ;
}
if ( ! V_36 || ! strlen ( V_36 -> V_25 ) || ! V_36 -> V_27 ) {
F_11 ( L_15 , V_16 ) ;
return - V_29 ;
}
V_26 = V_36 ;
V_12 = F_33 ( & V_38 ) ;
if ( V_12 ) {
F_34 ( L_16 ,
V_16 , V_36 -> V_25 , V_12 ) ;
V_26 = NULL ;
} else {
F_34 ( L_17 , V_16 ,
V_36 -> V_25 ) ;
}
return V_12 ;
}
void F_35 ( struct V_35 * V_36 )
{
if ( V_26 != V_36 ) {
F_11 ( L_18 ,
V_16 , V_26 -> V_25 ) ;
return;
}
F_36 ( & V_38 ) ;
F_34 ( L_19 , V_16 ,
V_26 -> V_25 ) ;
V_26 = NULL ;
}
